#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"
#include <sys/time.h>
#include "WM8978.h"
#include "driver/i2s.h"
#include "Heavy_heavy.h"
#include "esp32/rom/ets_sys.h"
#include "esp32/rom/gpio.h"
#include "esp_intr_alloc.h"
#include "esp_attr.h"
#include "driver/timer.h"
#include "driver/gpio.h"

// OLED display drivers & settings
#include <driver/spi_master.h>
#include "u8g2_esp32_hal.h"
u8g2_t u8g2; // a structure which will contain all the data for one display

#include "rotary_encoder.h"
#define ROT_ENC_A_GPIO 2
#define ROT_ENC_B_GPIO 4
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    true  // Set to true to reverse the clockwise/counterclockwise sense

#define MULT_S32 2147483647
#define ADC_CS 17 // chip 10

float *inBuffers;
float *outBuffers;
HeavyContextInterface *context;
int blockSize = 16;

static intr_handle_t s_timer_handle;

static int io_state = 0;

uint16_t teller = 0;

//RX TX Buffers
uint16_t tx_data[10];
uint16_t rx_data[10];

// global spi handle
spi_device_handle_t spi;

// global spi_transaction_t
spi_transaction_ext_t t;
spi_transaction_ext_t *t_res;

static const char* tag = "heavy";

extern "C" {
    void app_main(void);
}

void task_test_SSD1306() {
	u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
	u8g2_esp32_hal.clk   = (gpio_num_t)14;
	u8g2_esp32_hal.mosi  = (gpio_num_t)13;
	u8g2_esp32_hal.cs    = (gpio_num_t)5;
	u8g2_esp32_hal.dc    = (gpio_num_t)15; // *23
	u8g2_esp32_hal.reset = (gpio_num_t)12;
	u8g2_esp32_hal_init(u8g2_esp32_hal);

	u8g2_Setup_ssd1306_128x64_noname_f(
		&u8g2,
		U8G2_R0,
		u8g2_esp32_spi_byte_cb,
		u8g2_esp32_gpio_and_delay_cb);  // init u8g2 structure
	u8g2_InitDisplay(&u8g2); // send init sequence to the display, display is in sleep mode after this,
	u8g2_SetPowerSave(&u8g2, 0); // wake up display
	ESP_LOGI(tag, "All done!");
}

void printDemo() {
  u8g2_ClearBuffer(&u8g2);
  //u8g2_DrawBox(&u8g2, 10,20, 20, 30);
  u8g2_SetFont(&u8g2, u8g2_font_t0_13_me);
  u8g2_DrawStr(&u8g2, 0,15,"H2ello World!");
  u8g2_SendBuffer(&u8g2); // takes 30us @ 4Mhz
}

void encoderHandler (void *pvParameter) {
  // Start encoder reader
  ESP_ERROR_CHECK(gpio_install_isr_service(0));
  // Initialise the rotary encoder device with the GPIOs for A and B signals
  rotary_encoder_info_t info;
  ESP_ERROR_CHECK(rotary_encoder_init(&info, (gpio_num_t)ROT_ENC_A_GPIO, (gpio_num_t)ROT_ENC_B_GPIO));
  ESP_ERROR_CHECK(rotary_encoder_enable_half_steps(&info, ENABLE_HALF_STEPS));

  // button handler
  //gpio_isr_handler_add((gpio_num_t)5, isr_handler, void* args);

  #ifdef FLIP_DIRECTION
  ESP_ERROR_CHECK(rotary_encoder_flip_direction(&info));
  #endif

  // Create a queue for events from the rotary encoder driver.
  // Tasks can read from this queue to receive up to date position information.
  QueueHandle_t event_queue = rotary_encoder_create_queue();
  ESP_ERROR_CHECK(rotary_encoder_set_queue(&info, event_queue));
  printf("done ENC init\n");
  while(1) {
    // printf("ola\n");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);

    // Wait for incoming events on the event queue.
        rotary_encoder_event_t event = { 0 };
        if (xQueueReceive(event_queue, &event, portMAX_DELAY) == pdTRUE)
        {
            //ESP_LOGI(tag, "Event: position %d", event.state.position);
            //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_CHANNELA, event.state.position/100.0);
            //printDemo("channel A",event.state.position);
            printf("Channel A: %d\n",event.state.position);
        }
        // else
        // {
        //     // Poll current position and direction
        //     rotary_encoder_state_t state = { 0 };
        //     ESP_ERROR_CHECK(rotary_encoder_get_state(&info, &state));
        //     ESP_LOGI(tag, "Poll: position %d, direction %s", state.position,
        //              state.direction ? (state.direction == ROTARY_ENCODER_DIRECTION_CLOCKWISE ? "CW" : "CCW") : "NOT_SET");
        //
        //     // Reset the device
        //     if (RESET_AT && (state.position >= RESET_AT || state.position <= -RESET_AT))
        //     {
        //         ESP_LOGI(tag, "Reset");
        //         ESP_ERROR_CHECK(rotary_encoder_reset(&info));
        //     }
        // }
  }
}

static void timeval_subtract(struct timeval *result, struct timeval *end, struct timeval *start) {
  if (end->tv_usec < start->tv_usec) {
    result->tv_sec = end->tv_sec - start->tv_sec - 1;
    result->tv_usec = 1000000L + end->tv_usec - start->tv_usec;
  } else {
    result->tv_sec = end->tv_sec - start->tv_sec;
    result->tv_usec = end->tv_usec - start->tv_usec;
  }
}

static void timer_tg0_isr(void* arg)
{
	//Reset irq and set for next time
    TIMERG0.int_clr_timers.t0 = 1;
    TIMERG0.hw_timer[0].config.alarm_en = 1;
    //t.base.rx_buffer = &rx_data;
    // get spi transaction result, dont wait
    spi_device_get_trans_result(spi, (spi_transaction_t**)&t_res, 0);
    // place next transaction in queue, dont wait
    spi_device_queue_trans(spi, (spi_transaction_t*)&t, 0);


    //----- HERE EVERY #uS -----
    teller++;
	//Toggle a pin so we can verify the timer is working using an oscilloscope
	// io_state ^= 1;									//Toggle the pins state
	// gpio_set_direction((gpio_num_t)4, GPIO_MODE_OUTPUT);
	// gpio_set_level((gpio_num_t)4, io_state);
}

void timer_tg0_initialise (int timer_period_us)
{
    timer_config_t config = {
            .alarm_en = (timer_alarm_t)true,				  //Alarm Enable
            .counter_en = (timer_start_t)false,			  //If the counter is enabled it will start incrementing / decrementing immediately after calling timer_init()
            .intr_type = TIMER_INTR_LEVEL,	          //Is interrupt is triggered on timer’s alarm (timer_intr_mode_t)
            .counter_dir = TIMER_COUNT_UP,	          //Does counter increment or decrement (timer_count_dir_t)
            .auto_reload = (timer_autoreload_t)true,	//If counter should auto_reload a specific initial value on the timer’s alarm, or continue incrementing or decrementing.
            .divider = 80   				                  //Divisor of the incoming 80 MHz (12.5nS) APB_CLK clock. E.g. 80 = 1uS per timer tick
    };

    timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, timer_period_us);
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_isr_register(TIMER_GROUP_0, TIMER_0, &timer_tg0_isr, NULL, 0, &s_timer_handle);

    timer_start(TIMER_GROUP_0, TIMER_0);
}

esp_err_t write_cmd(spi_device_handle_t spi, uint8_t cmd)
{
    esp_err_t err;
    err = spi_device_get_trans_result(spi, (spi_transaction_t**)&t_res, 100);
    err = spi_device_queue_trans(spi, (spi_transaction_t*)&t, 100);
    return err;
}

void hello_task(void *pvParameter)
{
  while(true) {
    printf("ticks: %d\n",teller);
    vTaskDelay(1000 / portTICK_RATE_MS);
  }
}

void app_main()
{
    printf("app main\n");

    // setup global spi_transaction_t
    t_res = &t;
    memset(&t, 0, sizeof(t));
    t.base.length = 24;
    t.base.tx_buffer = &tx_data;
    t.base.rxlength = 24;
    t.base.rx_buffer = &rx_data;
    tx_data[0] = 6;
    tx_data[1] = 0;

    esp_err_t ret;

    spi_bus_config_t buscfg={
        .mosi_io_num=23,      // chip 11
        .miso_io_num=19,      // chip 12 *19
        .sclk_io_num=18,      // chip 13 *18
        .quadwp_io_num=-1,
        .quadhd_io_num=-1
    };
    spi_device_interface_config_t devcfg={
        .mode=0,
        .clock_speed_hz=2000000,
        .spics_io_num=ADC_CS,
        .queue_size=1,
        //.flags = (SPI_DEVICE_HALFDUPLEX),
        //.cs_ena_pretrans = 2,
        //.cs_ena_posttrans = 2
    };
    // ret=spi_bus_initialize(VSPI_HOST, &buscfg, 1);
    // assert(ret==ESP_OK);
    //
    // ret=spi_bus_add_device(VSPI_HOST, &devcfg, &spi);
    // assert(ret==ESP_OK);


    WM8978 wm8978;
    wm8978.init();

    task_test_SSD1306();
    printDemo();
    printf("done display test\n");

    // setup and start heavy compiler
    double sampleRate = 48000.0;
    context = hv_heavy_new(sampleRate);
    int numOutputChannels = hv_getNumOutputChannels(context);
    float **outBuffers = (float **) hv_malloc(numOutputChannels * sizeof(float *));
    for (int i = 0; i < numOutputChannels; ++i) {
      outBuffers[i] = (float *) hv_malloc(blockSize * sizeof(float));
    }

    printf("heavy # outputs: %d \n",numOutputChannels);

    vTaskDelay(1000 / portTICK_RATE_MS);

    // measure load
    int numIterations = 5000;
    struct timeval elapsed, start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < numIterations; ++i) {
      hv_process(context, NULL, outBuffers, blockSize);
    }


    gettimeofday(&end, NULL);
    timeval_subtract(&elapsed, &end, &start);
    uint64_t elapsedTimeUs = (elapsed.tv_sec * 1000000L) + elapsed.tv_usec;
    // return the us per block
    printf("%f \n", elapsedTimeUs/((double) numIterations));

    // start the ESP32-Audio-Kit AC101 codec
    // AC101 ac101;
    // ac101.begin();

    // start ESP32-Audio-Kit I2S
    i2s_pin_config_t pin_config;
    pin_config = {                  // 0 -> 25 MCLK
        .bck_io_num = 27,           // 3 SCK
        .ws_io_num = 26,            // 5 7 LRCLK
        .data_out_num = 25,         // 4 DACDAT
        .data_in_num = 35           // 6 ADCDAT
    };
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 48000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // high interrupt priority
        .dma_buf_count = 3,
        .dma_buf_len = 1024,
        .use_apll = true
    };
    i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
    i2s_set_pin((i2s_port_t)0, &pin_config);
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    REG_WRITE(PIN_CTRL, 0xFFFFFFF0);

    // VSPI DMA Channel 2
    ret=spi_bus_initialize(VSPI_HOST, &buscfg, 2);
    assert(ret==ESP_OK);

    ret=spi_bus_add_device(VSPI_HOST, &devcfg, &spi);
    assert(ret==ESP_OK);

    // queue a single transaction to set things up
    spi_device_queue_trans(spi, (spi_transaction_t*)&t, 100);

    // Start ADC callback
    printf("start ADC callback \n");
    timer_tg0_initialise(80);
    printf("ADC callback started \n");

    // start encoder service
    xTaskCreate(&encoderHandler, "encoderHandler", 2048, NULL, 5, NULL);

    // start main task
    xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);

    int32_t samples_data_out[blockSize*2];

    while(1) {
      hv_process(context, NULL, outBuffers, blockSize);
      for (int i = 0; i < blockSize; i++) {
        samples_data_out[i*2] = (int32_t)(outBuffers[0][i] * MULT_S32);
        samples_data_out[i*2+1] = (int32_t)(outBuffers[1][i] * MULT_S32);
      }
      size_t bytes_written = 0;
      i2s_write((i2s_port_t)0, &samples_data_out, blockSize*2*sizeof(int32_t), &bytes_written, portMAX_DELAY);
    }
}
