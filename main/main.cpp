#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
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
#define ROT_ENC_A_GPIO 14
#define ROT_ENC_B_GPIO 27
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    true  // Set to true to reverse the clockwise/counterclockwise sense

#define ESP_INTR_FLAG_DEFAULT 0

//#define MULT_S32 2147483647
#define MULT_S32 2147483647
#define ADC_CS 15 // chip 10

static xQueueHandle gpio_evt_queue = NULL;

float *inBuffers;
float *outBuffers;
HeavyContextInterface *context;
int blockSize = 16;
uint8_t i2s_ready=1;
uint8_t calc_busy = 0;
int32_t samples_data_out[32];
int32_t samples_data_out2[32];

static intr_handle_t s_timer_handle;
static intr_handle_t s_timer_handle2;

static int io_state = 0;

uint32_t teller = 0;

//RX TX Buffers
uint8_t tx_data[10];
uint8_t rx_data[10];

//uint16_t dmabuf[2500];
uint8_t displaybuffer1refresh = 1;
uint16_t displaybuffer1[128];
uint16_t displaybuffer1zoom = 8;
uint16_t displaybuffer1counter = 0;
uint16_t displaybuffer1subcounter = 0;
uint32_t displaybuffer1temp = 0;

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
	u8g2_esp32_hal.clk   = (gpio_num_t)12;  //d0
	u8g2_esp32_hal.mosi  = (gpio_num_t)2;  //d1
	u8g2_esp32_hal.cs    = (gpio_num_t)0; // not used
	u8g2_esp32_hal.dc    = (gpio_num_t)5; // *23
	u8g2_esp32_hal.reset = (gpio_num_t)13;
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
  u8g2_DrawStr(&u8g2, 0,15,"H4ello World!");
  u8g2_SendBuffer(&u8g2); // takes 30us @ 4Mhz
}

void encoderHandler (void *pvParameter) {
  // Start encoder reader

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
            //displaybuffer1counter = 0;
            //displaybuffer1subcounter = 0;
            // displaybuffer1zoom+=event.state.position;
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
    // set ADC port
    uint8_t pin = 0;
    tx_data[0] = 0b01100000 | ((pin & 0b111) << 2);
    //tx_data[0] = 19;
    // place next transaction in queue, dont wait
    spi_device_queue_trans(spi, (spi_transaction_t*)&t, 0);

    // for(int p=0;p<128;p++){
    //   for(int r=0;r<displaybuffer1zoom;r++) {
    //
    //   }
    // }

    // display calculations are done here to distribute the calculation-load more evenly
    if(displaybuffer1refresh==1) {
      if(displaybuffer1subcounter < displaybuffer1zoom) {
        displaybuffer1temp+=(rx_data[1] << 4) | (rx_data[2] >> 4);
        displaybuffer1subcounter++;
      } else {
        displaybuffer1[displaybuffer1counter]=displaybuffer1temp/displaybuffer1zoom;
        displaybuffer1temp=0;
        displaybuffer1subcounter=0;
        displaybuffer1counter++;
        if(displaybuffer1counter==128){displaybuffer1counter=0;displaybuffer1refresh=0;}
      }
    }

    // if(displaybuffer1counter==1024) {displaybuffer1counter=0;}
    // displaybuffer1[displaybuffer1counter]=(rx_data[1] << 4) | (rx_data[2] >> 4);

    // work with the DMA result
    // if(teller>=20000 && teller<22500) {
    //   dmabuf[teller-20000] = (rx_data[1] << 4) | (rx_data[2] >> 4);
    // }
    //if(displaybuffer1counter>=20000 && displaybuffer1counter<21024) {

      // displaybuffer1counter++;
      //
    //}

    //



    //----- HERE EVERY #uS -----

	//Toggle a pin so we can verify the timer is working using an oscilloscope
	// io_state ^= 1;									//Toggle the pins state
	// gpio_set_direction((gpio_num_t)4, GPIO_MODE_OUTPUT);
	// gpio_set_level((gpio_num_t)4, io_state);
}

static void timer_tg1_isr(void* arg)
{
	//Reset irq and set for next time
    TIMERG1.int_clr_timers.t0 = 1;
    TIMERG1.hw_timer[0].config.alarm_en = 1;
    teller++;
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

void timer_tg1_initialise (int timer_period_us)
{
    timer_config_t config = {
            .alarm_en = (timer_alarm_t)true,				  //Alarm Enable
            .counter_en = (timer_start_t)false,			  //If the counter is enabled it will start incrementing / decrementing immediately after calling timer_init()
            .intr_type = TIMER_INTR_LEVEL,	          //Is interrupt is triggered on timer’s alarm (timer_intr_mode_t)
            .counter_dir = TIMER_COUNT_UP,	          //Does counter increment or decrement (timer_count_dir_t)
            .auto_reload = (timer_autoreload_t)true,	//If counter should auto_reload a specific initial value on the timer’s alarm, or continue incrementing or decrementing.
            .divider = 80   				                  //Divisor of the incoming 80 MHz (12.5nS) APB_CLK clock. E.g. 80 = 1uS per timer tick
    };

    timer_init(TIMER_GROUP_1, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_1, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_1, TIMER_0, timer_period_us);
    timer_enable_intr(TIMER_GROUP_1, TIMER_0);
    timer_isr_register(TIMER_GROUP_1, TIMER_0, &timer_tg1_isr, NULL, 0, &s_timer_handle2);

    timer_start(TIMER_GROUP_1, TIMER_0);
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
  uint8_t xpos = 10;
  while(true) {
    // die println'ing when teller > 25000
    // if(teller>25000) {
    //   for(int i=0;i<2500;i++) {
    //     printf("%d, ",dmabuf[i]);
    //   }
    //   while(true) {};
    // }
    //printf("ticks: %d\n",teller);
    // ESP_LOG_BUFFER_HEX(tag,rx_data,20);
    // uint8_t msb = rx_data[1] & 0xf;
    // uint8_t lsb = rx_data[2];
    // uint16_t res = 256U*msb+lsb;
    // printf("val: %d\n",res);
    //printf("res2: %d\n",(rx_data[1] << 4) | (rx_data[2] >> 4));

    //printf("\n");
    //u8g2_DrawBox(&u8g2, 10,20, 20, 30);
    //u8g2_SetFont(&u8g2, u8g2_font_t0_13_me);
    //u8g2_DrawStr(&u8g2, 0,15,"H2ello World!");
    //u8g2_DrawBox(&u8g2, xpos, 10, 10, 10);
    // u8g2_ClearBuffer(&u8g2);
    // //u8g2_DrawBox(&u8g2, 10,20, 20, 30);
    // u8g2_SetFont(&u8g2, u8g2_font_t0_13_me);
    // u8g2_DrawStr(&u8g2, 0,15,"H3ello World!");
    // u8g2_SendBuffer(&u8g2); // takes 30us @ 4Mhz

    u8g2_ClearBuffer(&u8g2);
    for(int dis=0;dis<127;dis++) {
      u8g2_DrawPixel(&u8g2,dis,displaybuffer1[dis]/64);
      //printf("%d ",displaybuffer1[dis]/64);
    }

    u8g2_SendBuffer(&u8g2); // takes 30us @ 4Mhz
    displaybuffer1refresh=1;

    xpos+=10;
    if(xpos>100)xpos=10;

    vTaskDelay(100 / portTICK_RATE_MS);
  }
}

void i2s_task1(void *pvParameter)
{
  size_t bytes_written = 0;
  //printf("Hier3!\n");
  while(true) {
    //i2s_ready=0;
    if(calc_busy==0){
      i2s_write((i2s_port_t)0, &samples_data_out, blockSize*2*sizeof(int32_t), &bytes_written, portMAX_DELAY);
      i2s_ready=1;
    }
    //printf("Hier4!\n");
  }
}

void gpioCallback(void* arg) {
  printf("ola\n");
}

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}

static void gpio_task_example(void* arg)
{
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("GPIO[%d] intr, val: %d\n", io_num, gpio_get_level((gpio_num_t)io_num));
        }
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
    // 24 = channel 0, single ended
    // 25 = channel 1
    // 26, 27 = channel 2, 3
    tx_data[0] = 24;
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

    // gpio_pad_select_gpio((gpio_num_t)27);
    // gpio_set_direction((gpio_num_t)27, GPIO_MODE_OUTPUT);
    //gpio_set_level((gpio_num_t)27, 0);
    //gpio_matrix_out(GPIO_NUM_27, SIG_GPIO_OUT_IDX, false, false);
    //gpio_reset_pin(GPIO_NUM_27);

    //gpio_reset_pin
    printf("setting pins\n");
    // gpio_pad_select_gpio((gpio_num_t)25);
    // gpio_set_direction((gpio_num_t)25, GPIO_MODE_INPUT);
    // gpio_set_level((gpio_num_t)25, 0);
    //
    // gpio_set_direction(GPIO_NUM_26, GPIO_MODE_INPUT);
    // gpio_set_level(GPIO_NUM_26, 0);
    // gpio_set_direction(GPIO_NUM_27, GPIO_MODE_INPUT);
    // gpio_set_level(GPIO_NUM_27, 0);
    // gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);
    // gpio_set_level(GPIO_NUM_0, 0);

    // gpio_config_t io_conf;
    // //disable interrupt
    // io_conf.intr_type = gpio_int_type_t(0);
    // //set as output mode
    // io_conf.mode = GPIO_MODE_INPUT;
    // //bit mask of the pins that you want to set,e.g.GPIO18/19
    // io_conf.pin_bit_mask = ((1ULL<<25) | (1ULL<<26) | (1ULL<<27));
    // //disable pull-down mode
    // io_conf.pull_down_en = (gpio_pulldown_t)0;
    // //disable pull-up mode
    // io_conf.pull_up_en = (gpio_pullup_t)1;
    // //configure GPIO with the given settings
    // gpio_config(&io_conf);
    //gpio_install_isr_service(3);

    //gpio_intr_enable(GPIO_NUM_32);
//gpio_isr_handle_t s_int_handle;
// Intterrupt number see below
//gpio_isr_register(gpioCallback, NULL, ESP_INTR_FLAG_LEVEL1, &s_int_handle);
//gpio_isr_register(GPIO_NUM_32, gpioCallback, (void *)tag); // 17

    // PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[27], 1);
    // REG_WRITE(PIN_CTRL, 0xFFFFFFF0);
    //gpio_matrix_in(12, 224, 1);
    //gpio_matrix_out(27, 224, 1, 1);

    //gpio_set_pull_mode(GPIO_NUM_27, GPIO_FLOATING);

    //vTaskDelay(1000 / portTICK_PERIOD_MS);

    printf("starting wm8731.1\n");
    WM8978 wm8978;
    wm8978.init(0);

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    printf("starting wm8731.2\n");

    WM8978 wm8978_2;
    wm8978_2.init(1);
    //
    // printf("restarting wm8731.1\n");
    //
    // wm8978.init(2);

    //vTaskDelay(1000 / portTICK_PERIOD_MS);

    task_test_SSD1306();
    printDemo();
    printf("done display test\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

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
    i2s_pin_config_t pin_config2;
    pin_config = {                  // 0 -> 25 MCLK
        .bck_io_num = 36,           // 3 SCK
        .ws_io_num = 34,            // 5 7 LRCLK
        .data_out_num = 25,         // 4 DACDAT
        //.data_in_num = 35           // 6 ADCDAT
    };
    pin_config2 = {                  // 0 -> 25 MCLK
        .bck_io_num = 35,           // 3 SCK
        .ws_io_num = 39,            // 5 7 LRCLK
        .data_out_num = 4,         // 4 DACDAT
        //.data_in_num = 33          // 6 ADCDAT
    };
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_SLAVE | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 48000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL2, // high interrupt priority, level 2 because of HSPI conflict @ level 1
        .dma_buf_count = 8,
        .dma_buf_len = 128,
        .use_apll = true,
        //.tx_desc_auto_clear = true
    };

    i2s_config_t i2s_config2 = {
        .mode = (i2s_mode_t)(I2S_MODE_SLAVE | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 48000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // high interrupt priority
        .dma_buf_count = 8,
        .dma_buf_len = 128,
        .use_apll = true,
        //.tx_desc_auto_clear = true
    };
    i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
    i2s_set_pin((i2s_port_t)0, &pin_config);
    // PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    // REG_WRITE(PIN_CTRL, 0xFFFFFFF0);

    i2s_driver_install((i2s_port_t)1, &i2s_config2, 0, NULL);
    i2s_set_pin((i2s_port_t)1, &pin_config2);

    // VSPI DMA Channel 2
    ret=spi_bus_initialize(VSPI_HOST, &buscfg, 2);
    assert(ret==ESP_OK);

    ret=spi_bus_add_device(VSPI_HOST, &devcfg, &spi);
    assert(ret==ESP_OK);

    // queue a single transaction to set things up
    spi_device_queue_trans(spi, (spi_transaction_t*)&t, 100);

    // Start ADC callback
    printf("start ADC callback \n");
    timer_tg0_initialise(100);
        //timer_tg1_initialise(4000);
    printf("ADC callback started \n");


    gpio_config_t io_conf;
    //interrupt of rising edge
    io_conf.intr_type = (gpio_int_type_t)GPIO_PIN_INTR_DISABLE;

    //bit mask of the pins, use GPIO4/5 here
io_conf.pin_bit_mask = ((1ULL<<26)); //| (1ULL<<26) | (1ULL<<27));
//set as input mode
io_conf.mode = GPIO_MODE_INPUT;
//enable pull-up mode
io_conf.pull_down_en = (gpio_pulldown_t)0;
io_conf.pull_up_en = (gpio_pullup_t)1;
gpio_config(&io_conf);

gpio_set_intr_type((gpio_num_t)26, GPIO_INTR_ANYEDGE);


    ESP_ERROR_CHECK(gpio_install_isr_service(0));
    gpio_isr_handler_add(GPIO_NUM_26, gpio_isr_handler, (void*) GPIO_NUM_26);

gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));

    //start encoder service
    xTaskCreate(&encoderHandler, "encoderHandler", 2048, NULL, 5, NULL);

xTaskCreate(gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL);

    // start main task
    xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);

    // start i2s task 1
    //xTaskCreate(&i2s_task1, "i2s_task1", 2048, NULL, 5, NULL);

    while(1) {
      // runs @ 48000 / 16 = 3000hz
        hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_FREQ, (4095 - ((rx_data[1] << 4) | (rx_data[2] >> 4))));
        hv_process(context, NULL, outBuffers, blockSize);
        for (int i = 0; i < blockSize; i++) {
          samples_data_out[i*2] = (int32_t)(outBuffers[0][i] * MULT_S32);
          samples_data_out[i*2+1] = (int32_t)(outBuffers[1][i] * MULT_S32);
          samples_data_out2[i*2] = (int32_t)(outBuffers[2][i] * MULT_S32);
          samples_data_out2[i*2+1] = (int32_t)(outBuffers[3][i] * MULT_S32);
        }
      size_t bytes_written = 0;
      size_t bytes_written2 = 0;
      i2s_write((i2s_port_t)1, &samples_data_out2, blockSize*2*sizeof(int32_t), &bytes_written2, portMAX_DELAY);
      i2s_write((i2s_port_t)0, &samples_data_out, blockSize*2*sizeof(int32_t), &bytes_written, portMAX_DELAY);
    }
}
