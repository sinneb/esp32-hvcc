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

#define MULT_S32 2147483647

float *inBuffers;
float *outBuffers;
HeavyContextInterface *context;
int blockSize = 256;

static const char* TAG = "heavy";

extern "C" {
    void app_main(void);
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

    gettimeofday(&end, NULL);
    timeval_subtract(&elapsed, &end, &start);
    uint64_t elapsedTimeUs = (elapsed.tv_sec * 1000000L) + elapsed.tv_usec;
    // return the us per block
    printf("%f \n", elapsedTimeUs/((double) numIterations));

    // start the ESP32-Audio-Kit AC101 codec
    AC101 ac101;
    ac101.begin();

    // start ESP32-Audio-Kit I2S
    i2s_pin_config_t pin_config;
    pin_config = {
        .bck_io_num = 27,
        .ws_io_num = 26,
        .data_out_num = 25,
        .data_in_num = 35
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

    int32_t samples_data_out[blockSize*2];

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
