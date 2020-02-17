#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"
#include <sys/time.h>
#include "AC101.h"
#include "driver/i2s.h"
#include "Heavy_heavy.h"

typedef struct controlledPatchObjects {
   int id;
   int min;
   int max;
} controlledPatchObject;

// OLED display drivers & settings
#include <driver/spi_master.h>
#include "u8g2_esp32_hal.h"
// CLK - GPIO14§
#define PIN_CLK 14
// MOSI - GPIO 13
#define PIN_MOSI 13
// RESET - GPIO 26
#define PIN_RESET 12
// DC - GPIO 27
#define PIN_DC 23
// CS - GPIO 15
#define PIN_CS 15
u8g2_t u8g2; // a structure which will contain all the data for one display

#include "rotary_encoder.h"
#define ROT_ENC_A_GPIO 21
#define ROT_ENC_B_GPIO 22
#define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
#define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
#define FLIP_DIRECTION    true  // Set to true to reverse the clockwise/counterclockwise sense

#define MULT_S32 2147483647

float *inBuffers;
float *outBuffers;
HeavyContextInterface *context;
int blockSize = 256;

static const char* tag = "heavy";

static xQueueHandle signalsToPatchQueue = NULL;

extern "C" {
    void app_main(void);
}

void task_test_SSD1306() {
	u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
	u8g2_esp32_hal.clk   = (gpio_num_t)PIN_CLK;
	u8g2_esp32_hal.mosi  = (gpio_num_t)PIN_MOSI;
	u8g2_esp32_hal.cs    = (gpio_num_t)PIN_CS;
	u8g2_esp32_hal.dc    = (gpio_num_t)PIN_DC;
	u8g2_esp32_hal.reset = (gpio_num_t)PIN_RESET;
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

void printDemo(char *theText, int theValue) {
  u8g2_ClearBuffer(&u8g2);
  u8g2_SetFont(&u8g2, u8g2_font_t0_13_me);
  u8g2_DrawStr(&u8g2, 0,15,theText);

  char tmp_string[8];
  itoa(theValue, tmp_string, 10);
  u8g2_DrawStr(&u8g2, 0,45,tmp_string);
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
            printDemo("channel A",event.state.position);
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

void app_main()
{
    printf("app main\n");

    // setup queue
    signalsToPatchQueue = xQueueCreate(20, sizeof(float));

    task_test_SSD1306();
    printf("done display init\n");

    // setup and start heavy compiler
    double sampleRate = 48000.0;
    context = hv_heavy_new(sampleRate);
    int numOutputChannels = hv_getNumOutputChannels(context);
    float **outBuffers = (float **) hv_malloc(numOutputChannels * sizeof(float *));
    for (int i = 0; i < numOutputChannels; ++i) {
      outBuffers[i] = (float *) hv_malloc(blockSize * sizeof(float));
    }

    printf("heavy # outputs: %d \n",numOutputChannels);

    // measure load
    int numIterations = 100;
    struct timeval elapsed, start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < numIterations; ++i) {
      hv_process(context, NULL, outBuffers, blockSize);
    }
    printDemo("ola",500);

    gettimeofday(&end, NULL);
    timeval_subtract(&elapsed, &end, &start);
    uint64_t elapsedTimeUs = (elapsed.tv_sec * 1000000L) + elapsed.tv_usec;
    // return the us per block
    printf("us per block: %f \n", elapsedTimeUs/((double) numIterations));

    // start the ESP32-Audio-Kit AC101 codec
    AC101 ac101;
    ac101.begin();

    // start ESP32-Audio-Kit I2S
    i2s_pin_config_t pin_config;
    pin_config = {
        .bck_io_num = 27, //sck
        .ws_io_num = 26,
        .data_out_num = 25,
        .data_in_num = 35
    };
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 48000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_24BIT,
        .channel_format = I2S_CHANNEL_FMT_ALL_LEFT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_LSB),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // high interrupt priority
        .dma_buf_count = 3,
        .dma_buf_len = 1024,
        .use_apll = true,
    };
    i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
    i2s_set_pin((i2s_port_t)0, &pin_config);
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    REG_WRITE(PIN_CTRL, 0xFFFFFFF0);

    int32_t samples_data_out[blockSize*2];

    // I2S 1s warmup
    vTaskDelay(1000 / portTICK_PERIOD_MS);


    // start encoder service
    xTaskCreate(&encoderHandler, "encoderHandler", 2048, NULL, 5, NULL);

    //
    //xQueueSendToBack(signalsToPatchQueue, &((theSignal){SIGNAL_CLEANUP, arrMatrix[3].x+1, arrMatrix[3].y}), 0);

    while(1) {
      hv_process(context, NULL, outBuffers, blockSize);
      for (int i = 0; i < blockSize; i++) {
        samples_data_out[i*2] = (int32_t)(outBuffers[0][i] * MULT_S32);
        samples_data_out[i*2+1] = (int32_t)(outBuffers[1][i] * MULT_S32);
      }
      size_t bytes_written = 0;
      i2s_write((i2s_port_t)0, &samples_data_out, 256*2*sizeof(int32_t), &bytes_written, portMAX_DELAY);
    }
}
