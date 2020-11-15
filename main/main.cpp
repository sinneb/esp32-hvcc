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
#include "driver/ledc.h"

// // OLED display drivers & settings
#include <driver/spi_master.h>

#include "ad1939defs.cpp"
// #include "u8g2_esp32_hal.h"
// u8g2_t u8g2; // a structure which will contain all the data for one display

// #include "rotary_encoder.h"
// #define ROT_ENC_A_GPIO 14
// #define ROT_ENC_B_GPIO 27
// #define ENABLE_HALF_STEPS false  // Set to true to enable tracking of rotary encoder at half step resolution
// #define RESET_AT          0      // Set to a positive non-zero number to reset the position if this value is exceeded
// #define FLIP_DIRECTION    true  // Set to true to reverse the clockwise/counterclockwise sense

#define LEDC_IO_0    (5)

#define ESP_INTR_FLAG_DEFAULT 0

#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_HS_MODE           LEDC_HIGH_SPEED_MODE
#define LEDC_HS_CH0_GPIO       (12)
#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0

int fadelevel = 0;

#define MULT_S32 1826500000
#define MULT_S24 8388607
//#define MULT_S32 2147483647
//#define MULT_S32 1373741823
#define ADC_CS 15 // chip 10

static xQueueHandle gpio_evt_queue = NULL;
static xQueueHandle i2sDMA = NULL;

static const char* TAG = "EurorackEngine";

float *inBuffers;
float *outBuffers;
HeavyContextInterface *context;
int blockSize = 16;
uint8_t i2s_ready=1;
uint8_t calc_busy = 0;

int32_t calib[32];

uint16_t dmareqs = 0;

size_t free8start, free32start, free8, free32;

static intr_handle_t s_timer_handle;
static intr_handle_t s_timer_handle2;

static int io_state = 0;

uint32_t teller = 0;
uint32_t teller2 = 0;

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

uint16_t adcvalues[8][10];
uint8_t adccounter = 0;
uint8_t adcmax = 4;
uint8_t potentiometercounter=0;

// global spi handle
spi_device_handle_t spi;

// global spi_transaction_t
spi_transaction_ext_t t;
spi_transaction_ext_t *t_res;

static const char* tag = "heavy";

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

static void timer_tg0_isr(void* arg)
{
  teller++;
	//Reset irq and set for next time
  TIMERG0.int_clr_timers.t0 = 1;
  TIMERG0.hw_timer[0].config.alarm_en = 1;
  // get spi transaction result, dont wait
  spi_device_get_trans_result(spi, (spi_transaction_t**)&t_res, 0);
  // store result in adc array
  // adc[0] -> adc[3] : incoming CV values, no running average
  // adc[4] -> adc[7] : potentiometers, running averages (?)
  adcvalues[adccounter][0] = (rx_data[1] << 4) | (rx_data[2] >> 4);

  // set ADC port
  adccounter++;
  // reset ADC count
  // scan adc0 - adc3 (CV inputs) 10x more often,
  if(adccounter==adcmax) {
    adccounter = 0;
    potentiometercounter++;
    if(potentiometercounter==8) {
      adcmax=8;
    }
    if(potentiometercounter==9) {
      adcmax=4;
      potentiometercounter = 0;
    }
  }
  uint8_t pin = adccounter;
  tx_data[0] = 0b01100000 | ((pin & 0b111) << 2);

  if(adccounter==4) teller2++;

  // place next transaction in queue, dont wait
  spi_device_queue_trans(spi, (spi_transaction_t*)&t, 0);

    // ---- CALCULATE OSCILLOSCOPE
    // // display calculations are done here to distribute the calculation-load more evenly
    // if(displaybuffer1refresh==1) {
    //   if(displaybuffer1subcounter < displaybuffer1zoom) {
    //     displaybuffer1temp+=(rx_data[1] << 4) | (rx_data[2] >> 4);
    //     displaybuffer1subcounter++;
    //   } else {
    //     displaybuffer1[displaybuffer1counter]=displaybuffer1temp/displaybuffer1zoom;
    //     displaybuffer1temp=0;
    //     displaybuffer1subcounter=0;
    //     displaybuffer1counter++;
    //     if(displaybuffer1counter==128){displaybuffer1counter=0;displaybuffer1refresh=0;}
    //   }
    // }
    // /-- CALCULATE
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

uint8_t recvbuf=6;

uint32_t spiget(spi_device_handle_t spi, uint8_t reg)
{
  //
  unsigned char result = 0;
  unsigned char data[3];

  data[0] = ((0x04<<1)|1);
  data[1] = reg;      // reg
  data[2] = 0x0;
  //char sendbuf[16]="Hello World!"
  spi_transaction_t t;
  memset(&t, 0, sizeof(t));
  t.length=8*3;
  t.tx_buffer=&data;
  t.rx_buffer=&recvbuf;
  t.flags = SPI_TRANS_USE_RXDATA;
  t.user = (void*)1;

  esp_err_t ret=spi_device_polling_transmit(spi, &t);
  assert(ret==ESP_OK);

  return *(uint32_t*)t.rx_data;
}

void spi_write_reg(spi_device_handle_t spi, uint8_t reg, uint8_t val)
{
  //
  unsigned char result = 0;
  unsigned char data[3];

  data[0] = ((0x04<<1));
  data[1] = reg;      // reg
  data[2] = val;
  //char sendbuf[16]="Hello World!"
  spi_transaction_t t;
  memset(&t, 0, sizeof(t));
  t.length=8*3;
  t.tx_buffer=&data;
  //t.rx_buffer=&recvbuf;
  //t.flags = SPI_TRANS_USE_RXDATA;
  t.user = (void*)0;

  esp_err_t ret=spi_device_polling_transmit(spi, &t);
  assert(ret==ESP_OK);

  //return *(uint32_t*)t.rx_data;
}

void printram() {
  ESP_LOGI(TAG, "RAM left %d", esp_get_free_heap_size());

  free8start = heap_caps_get_free_size(MALLOC_CAP_8BIT);
free32start = heap_caps_get_free_size(MALLOC_CAP_32BIT);
printf("Free 8bit-capable memory (start): %dK, 32-bit capable memory %dK\n", free8start, free32start);
}

void displayHandler(void *pvParameter)
{
  uint8_t xpos = 10;

  while(true) {

    printf("teller: %d\n", teller);
    printf("teller2: %d\n", teller2);
    printf("ADC0: %d\n", adcvalues[0][0]);
    printf("ADC1: %d\n", adcvalues[1][0]);
    printf("ADC2: %d\n", adcvalues[2][0]);
    printf("ADC3: %d\n", adcvalues[3][0]);
    printf("ADC4: %d\n", adcvalues[4][0]);
    printf("ADC5: %d\n", adcvalues[5][0]);
    printf("ADC6: %d\n", adcvalues[6][0]);
    printf("ADC7: %d\n", adcvalues[7][0]);
    printf("\n");
    printram();

    // app main
    // I (1262) EurorackEngine: RAM left 299960
//     I (3502) EurorackEngine: RAM left 264300
// ADC7: 1094
//
// I (3502) EurorackEngine: RAM left 264300
// I (3512) EurorackEngine: heap 261888
// I (3512) EurorackEngine: heap 229444
// heavys # outputs: 4
// heavsy # inputs: 2
// [@ 0.000ms] print: seconds
// teller: 41283
// teller2: 1032
// ADC0: 11
// ADC1: 16
// ADC2: 15
// ADC3: 9
// ADC4: 1420
// ADC5: 720
// ADC6: 2557
// ADC7: 1095
//
// I (4512) EurorackEngine: RAM left 41928

    //
    // // ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, fadelevel);
    // // ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
    // // //
    // // ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, fadelevel);
    // // ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
    //
    // // ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, fadelevel);
    // // ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
    //
    // fadelevel+=100;
    // if(fadelevel>1000)fadelevel=0;
    //printf("-->");
    //uint32_t lcd_id = spiget(spi, 1);
    //printf("--> lock? \n");
    //ESP_LOGI(TAG, "RAM left %d", esp_get_free_heap_size());
    //lcd_id = spiget(spi, 3);
    //printf("--> 0: %08X\n", lcd_id);
    //printf("dma: %d\n",dmareqs);
    //dmareqs = 0;


    //printf("lock?: %d\n",recvbuf);

    vTaskDelay(10000 / portTICK_RATE_MS);
  }
}

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    //uint32_t gpio_num = (uint32_t) arg;
    //xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}


int ledstate = 0;
static void gpioHandler(void* arg)
{
  // uint32_t i2s_evt;
  // for(;;) {
  //   xQueueReceive(i2sDMA, &i2s_evt, portMAX_DELAY);
  //   //if (i2s_evt.type == I2S_EVENT_TX_DONE) {
  //   //printf("yo\n");
  //   dmareqs++;
  //   if(dmareqs==8) {
  //     if(ledstate==0) {
  //       gpio_set_level((gpio_num_t)13, 1);
  //       ledstate = 1;
  //     } else {
  //       gpio_set_level((gpio_num_t)13, 0);
  //       ledstate = 0;
  //     }
  //     dmareqs=0;
  //
  //   }
  //   //}
  // }
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("GPIO[%d] intr, val: %d\n", io_num, gpio_get_level((gpio_num_t)io_num));
            //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_BUT1, (float)gpio_get_level((gpio_num_t)io_num));
        }
    }
}

void printHook(HeavyContextInterface *c, const char *printName, const char *str, const HvMessage *m) {
  double timestampMs = 1000.0 * ((double) hv_msg_getTimestamp(m)) / hv_getSampleRate(c);
  printf("[@ %.3fms] %s: %s\n", timestampMs, printName, str);
}

// define the send hook as a function with the following signature
static void sendHook(HeavyContextInterface *c,
    const char *sendName, unsigned int sendHash, const HvMessage *m) {

  // // only react to messages sent to receivers named "hello"
  // if (!strcmp(sendName, "hello")) {
  //   // do something with the message
  //   printf("> received message from send \"%s\".", sendName);
  // }

  // printf(sendName);
  // printf("\n");

  if (!strcmp(sendName, "led1")) {
      uint16_t x = hv_msg_getFloat(m, 0);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, x);
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
    }

  if (!strcmp(sendName, "led2")) {
      uint16_t x = hv_msg_getFloat(m, 0);
      //printf("led 2 val %d",x);
      ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, x);
      ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
    }

    if (!strcmp(sendName, "led3")) {
        uint16_t x = hv_msg_getFloat(m, 0);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, x);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
      }

    if (!strcmp(sendName, "led4")) {
        uint16_t x = hv_msg_getFloat(m, 0);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_3, x);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_3);
      }

  // // or alternatively...
  // printf("hash: %d\n", sendHash);
  //printf("hier");
  // printf("\n");
  // switch (sendHash) {
  //   case HV_HEAVY_PARAM_OUT_LED1: {
  //     printf("led1\n");
  //     uint16_t x = hv_msg_getFloat(m, 0);
  //     ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, x);
  //     ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
  //   }
  //   case HV_HEAVY_PARAM_OUT_LED2: {
  //     //printf("led2\n");
  //     uint16_t y = hv_msg_getNumElements(m);
  //     uint16_t x = hv_msg_getFloat(m, 0);
  //     printf("val %d\n",x);
  //     printf("numele: %d\n",y);
  //     ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, x);
  //     ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1);
  //   }
    // case HV_HEAVY_PARAM_OUT_LED3: {
    //   printf("led3\n");
    //   uint16_t x = hv_msg_getFloat(m, 0);
    //   ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, x);
    //   ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
    // }
    // case 0xFB81D83A: {
    //   // do something with the message
    //   printf("> message for you sir \"%s\".\n", sendName);
    //   uint16_t x = hv_msg_getFloat(m, 0);
    //   //printf("floatval: %d \n",x);
    //   ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2, x);
    //   ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_2);
    //   break;
    // }
    //default: return;
  //}
}

void audioHandler(void *pvParameter)
{
      // setup and start heavy compiler

    int numOutputChannels = 4;//hv_getNumOutputChannels(context);
    int numInputChannels = 2;//hv_getNumInputChannels(context);

    float **inBuffers = (float **) hv_malloc(numInputChannels * sizeof(float *));
    for (int i = 0; i < numInputChannels; ++i) {
      inBuffers[i] = (float *) hv_malloc(blockSize * sizeof(float));
    }

    float **outBuffers = (float **) hv_malloc(numOutputChannels * sizeof(float *));
    for (int i = 0; i < numOutputChannels; ++i) {
      outBuffers[i] = (float *) hv_malloc(blockSize * sizeof(float));
    }

    hv_setSendHook(context, sendHook);
    hv_setPrintHook(context, &printHook);

    int32_t samples_data_in[32];

    int32_t samples_data_out[32];
    int32_t samples_data_out2[32];

    //int32_t samples_data_in2[32];

    // int32_t **samples_data_in[32] = (int32_t **) malloc(32*sizeof(int32_t*));
    // for (int i = 0; i < 32; ++i) {
    //   samples_data_in[i] = (int32_t *) malloc(blockSize * sizeof(int32_t*));
    // }

    printf("heavys # outputs: %d \n",numOutputChannels);
    printf("heavsy # inputs: %d \n",numInputChannels);

  while(true) {
        size_t bytes_read = 0;
        i2s_read((i2s_port_t)0, &samples_data_in, blockSize*2*sizeof(int32_t), &bytes_read, portMAX_DELAY);

        for (int i = 0; i < blockSize; i++) {
         inBuffers[0][i] = (float)(samples_data_in[i*2] / 0.1f / MULT_S32);
         inBuffers[1][i] = (float)(samples_data_in[i*2+1] / 0.1f / MULT_S32);
        }

        //ESP_LOG_BUFFER_HEX(tag,samples_data_in,16);
        // send to context every blocksize (16 samples)
        // >>3 :: 4096 to 512
        uint32_t io_num;
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT1, (float)(adcvalues[4][0]>>3));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT2, (float)(adcvalues[5][0]>>3));
        // hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT2, (float)(adcvalues[6][0]>>3));
        // hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT4, (float)(adcvalues[7][0]>>3));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT5, (float)(adcvalues[0][0]));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT3, (float)(adcvalues[6][0]>>3));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT4, (float)(adcvalues[7][0]));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_CONTROLV1, (float)(adcvalues[7][0]));
        //hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_CV1, (float)0);
        // hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT2, 200.0f);
        // hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT3, 200.0f);
        // hv_sendFloatToReceiver(context, HV_HEAVY_PARAM_IN_POT4, 200.0f);
        hv_process(context, inBuffers, outBuffers, blockSize);
        for (int i = 0; i < blockSize; i++) {
          // samples_data_out[i*2] = (outBuffers[0][i]   * 1826500000) - 8000000;//((int)2000000000);//(int32_t)(outBuffers[0][i] * MULT_S32);
          // samples_data_out[i*2+1] = (outBuffers[1][i] * 1777000000) - 8000000;//((int)2000000000);//MULT_S32;//;//(int32_t)(outBuffers[1][i] * MULT_S32);
          // samples_data_out2[i*2] = (outBuffers[2][i] * 1821000000)  - 9000000;
          // samples_data_out2[i*2+1] = (outBuffers[3][i] * 1833000000)  - 9000000;
          samples_data_out[i*2] = (outBuffers[0][i]   * MULT_S32);// - 8000000;
          samples_data_out[i*2+1] = (outBuffers[1][i] * MULT_S32);
          samples_data_out2[i*2] = (outBuffers[2][i] * MULT_S32); // - 9000000;
          samples_data_out2[i*2+1] = (outBuffers[3][i] * MULT_S32);//  - 9000000;
        }
        //samples_data_out[31] = 0;
      size_t bytes_written = 0;
      size_t bytes_written2 = 0;

      //vTaskYield();
      //vTaskDelay(1 / portTICK_RATE_MS);

       // 128 bclk per frame = 32 bclk's per channel
       // 48000 sample rate
       // ((bits+8)/16)*16*4 = 40/16*16*4 = 200
       i2s_write((i2s_port_t)1, &samples_data_out2, blockSize*2*sizeof(int32_t), &bytes_written, portMAX_DELAY);
       //printf("write 1 done\n");
       i2s_write((i2s_port_t)0, &samples_data_out, blockSize*2*sizeof(int32_t), &bytes_written2, portMAX_DELAY);
       //printf("write 0 done\n");
  }
}

// void lcd_cmd(spi_device_handle_t spi, const uint8_t cmd)
// {
//     esp_err_t ret;
//     spi_transaction_t t;
//     memset(&t, 0, sizeof(t));       //Zero out the transaction
//     t.length=8;                     //Command is 8 bits
//     t.tx_buffer=&cmd;               //The data is the cmd itself
//     t.user=(void*)0;                //D/C needs to be set to 0
//     ret=spi_device_polling_transmit(spi, &t);  //Transmit!
//     assert(ret==ESP_OK);            //Should have had no issues.
// }
//
// uint32_t lcd_get_id(spi_device_handle_t spi)
// {
//     //get_id cmd
//     lcd_cmd(spi, 0x04);
//
//     spi_transaction_t t;
//     memset(&t, 0, sizeof(t));
//     t.length=8*3;
//
//     t.flags = SPI_TRANS_USE_RXDATA;
//     t.user = (void*)1;
//
//     esp_err_t ret = spi_device_polling_transmit(spi, &t);
//     assert( ret == ESP_OK );
//
//     return *(uint32_t*)t.rx_data;
// }



void app_main()
{
    printf("app main\n");

    printram();

    // setup global spi_transaction_t
    t_res = &t;
    memset(&t, 0, sizeof(t));
    t.base.length = 24;
    t.base.tx_buffer = &tx_data;
    t.base.rxlength = 24;
    t.base.rx_buffer = &rx_data;
    tx_data[0] = 24;
    tx_data[1] = 0;

    esp_err_t ret;

    spi_bus_config_t buscfg={
        .mosi_io_num=22,      // chip 11
        .miso_io_num=23,      // chip 12 *19
        .sclk_io_num=25,      // chip 13 *18
        .quadwp_io_num=-1,
        .quadhd_io_num=-1
    };
    spi_device_interface_config_t devcfg={
        .mode=0,
        .clock_speed_hz=2000000,
        .spics_io_num=26,     // 10
        .queue_size=1,
    };





//     uint32_t lcd_id = spiget(spi, 3);
//     printf("LCD3  ID: %08X\n", lcd_id);
//     printf("LCD 3 ID: %d\n", lcd_id);
//     printf("res: %d\n",recvbuf);
//
//     vTaskDelay(1000 / portTICK_RATE_MS);
//
//      lcd_id = spiget(spi,12);
//     printf("LCD 12 ID: %08X\n", lcd_id);
//     printf("res: %d\n",recvbuf);
//
//     vTaskDelay(1000 / portTICK_RATE_MS);
//
//      lcd_id = spiget(spi,1);
//     printf("LCD 1 ID: %08X\n", lcd_id);
//     printf("LCD 1 ID: %d\n", lcd_id);
//     printf("res: %d\n",recvbuf);
//
// vTaskDelay(1000 / portTICK_RATE_MS);
//
//      lcd_id = spiget(spi,8);
//     printf("LCD8 ID: %08X\n", lcd_id);
//     printf("LCD8 ID: %d\n", lcd_id);
//     printf("res: %d\n",recvbuf);

//Initialize the SPI bus
ret=spi_bus_initialize(HSPI_HOST, &buscfg, 2);
ESP_ERROR_CHECK(ret);
//Attach the LCD to the SPI bus
ret=spi_bus_add_device(HSPI_HOST, &devcfg, &spi);
ESP_ERROR_CHECK(ret);

gpio_reset_pin((gpio_num_t)27);
gpio_set_direction((gpio_num_t)27, GPIO_MODE_OUTPUT);
gpio_set_level((gpio_num_t)27,0);

    WM8978 wm8978;
    wm8978.init(0);
    printf("starting wm8731.2\n");
printram();
    //rtc_clk_apll_enable(1, 0, 0, 4, 0);
    //WM8978 wm8978_2;
    //wm8978_2.init(1);

    // printf("starting display\n");
    // init_SSD1306();

    // start I2S
    i2s_pin_config_t pin_config;
    i2s_pin_config_t pin_config2;
    pin_config = {                  // 0 -> 25 MCLK
        .bck_io_num = 27,           // 3 SCK
        .ws_io_num = 12,            // 5 7 LRCLK
        .data_out_num = 13,         // 4 DACDAT
        .data_in_num = 34           // 6 ADCDAT
    };
    pin_config2 = {                  // 0 -> 25 MCLK
        .bck_io_num = 21,           // 3 SCK
        .ws_io_num = 19,            // 5 7 LRCLK
        .data_out_num = 5,         // 4 DACDAT
        //.data_in_num = 34          // 6 ADCDAT
    };
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),
        .sample_rate = 48000,
        .bits_per_sample = (i2s_bits_per_sample_t)24,
        //.channel_num = 4,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S |I2S_COMM_FORMAT_I2S_MSB),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL2, // high interrupt priority, level 2 because of HSPI conflict @ level 1
        .dma_buf_count = 6,
        .dma_buf_len = 60,
        //.use_apll = true,
        //.tx_desc_auto_clear   = false,
        //.fixed_mclk           = 0
        //.fixed_mclk = 40000000
    };
    // i2s_config_t i2s_config = {
    //     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    //     .sample_rate = 48000,
    //     .bits_per_sample = (i2s_bits_per_sample_t)32,
    //     //.channel_num = 4,
    //     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    //     .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S |I2S_COMM_FORMAT_I2S_MSB),
    //     .intr_alloc_flags = ESP_INTR_FLAG_LEVEL2, // high interrupt priority, level 2 because of HSPI conflict @ level 1
    //     .dma_buf_count = 6,
    //     .dma_buf_len = 60,
    //     .use_apll = true,
    //     //.tx_desc_auto_clear   = false,
    //     //.fixed_mclk           = 0
    //     //.fixed_mclk = 40000000
    // };
    //
    // i2s_config_t i2s_wm8731 = {
    //     .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    //     .sample_rate = 48000,
    //     .bits_per_sample = (i2s_bits_per_sample_t)32,
    //     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    //     .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S |I2S_COMM_FORMAT_I2S_MSB),
    //     .intr_alloc_flags = ESP_INTR_FLAG_LEVEL2, // high interrupt priority
    //     .dma_buf_count = 6,
    //     .dma_buf_len = 60,
    //     .use_apll = true,
    //     //.use_apll = true,
    //     //.fixed_mclk = 12288000
    // };

    // I2S0.conf_chan.tx_chan_mod = 0x1;
    // I2S0.fifo_conf.tx_fifo_mod = 0x1;
    // I2S0.sample_rate_conf.tx_bck_div_num = 2;
    // I2S0.int_ena.out_eof = 1;
    // I2S0.out_link.start = 1;
    // I2S0.conf.tx_start = 1;

    //i2sDMA = xQueueCreate(10, sizeof(uint32_t));

    esp_err_t err;
    printf("i2s port 0 \n");
    err = i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
    if (err != ESP_OK) {
      printf("Failed installing driver: %d\n", err);
      while (true);
    }
    err = i2s_set_pin((i2s_port_t)0, &pin_config);
    if (err != ESP_OK) {
      printf("Failed setting pin: %d\n", err);
      while (true);
    }

    printf("i2s port 1 \n");
    err = i2s_driver_install((i2s_port_t)1, &i2s_config, 0, NULL);
    if (err != ESP_OK) {
    printf("Failed installing driver: %d\n", err);
      while (true);
    }
    err = i2s_set_pin((i2s_port_t)1, &pin_config2);
    if (err != ESP_OK) {
      printf("Failed setting pin: %d\n", err);
      while (true);
    }
printram();
    // i2s_driver_install((i2s_port_t)1, &i2s_wm8731, 0, NULL);


    //vTaskDelay(3000 / portTICK_RATE_MS);





    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    WRITE_PERI_REG(PIN_CTRL, READ_PERI_REG(PIN_CTRL) & 0xFFFFFFF0);

    // gpio_set_direction((gpio_num_t)0, GPIO_MODE_OUTPUT);
    // PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    // REG_WRITE(PIN_CTRL,0);

    //vTaskDelay(3000 / portTICK_RATE_MS);


    // VSPI DMA Channel 2
    // ret=spi_bus_initialize(VSPI_HOST, &buscfg, 2);
    // assert(ret==ESP_OK);
    // ret=spi_bus_add_device(VSPI_HOST, &devcfg, &spi);
    // assert(ret==ESP_OK);
    //queue a single transaction to set things up
    spi_device_queue_trans(spi, (spi_transaction_t*)&t, 100);

    // Start ADC callback
    printf("start ADC callback \n");
    timer_tg0_initialise(50);
    printf("ADC callback started \n");
printram();
    // let the ADC flow
    vTaskDelay(1000 / portTICK_RATE_MS);

    // gpio_pad_select_gpio((gpio_num_t)0);
    // gpio_pad_select_gpio((gpio_num_t)2);
    // gpio_set_direction((gpio_num_t)0, GPIO_MODE_INPUT);
    // gpio_set_direction((gpio_num_t)2, GPIO_MODE_INPUT);
    //
    // Start button interrupts & queue
    gpio_config_t io_conf;
    io_conf.intr_type = (gpio_int_type_t)GPIO_PIN_INTR_DISABLE;
    io_conf.pin_bit_mask = ((1ULL<<14) | (1ULL<<16) | (1ULL<<17) | (1ULL<<18));
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_down_en = (gpio_pulldown_t)0;
    io_conf.pull_up_en = (gpio_pullup_t)1;
    gpio_config(&io_conf);
    gpio_set_intr_type((gpio_num_t)14, GPIO_INTR_ANYEDGE);
    gpio_set_intr_type((gpio_num_t)16, GPIO_INTR_ANYEDGE);
    gpio_set_intr_type((gpio_num_t)17, GPIO_INTR_ANYEDGE);
    gpio_set_intr_type((gpio_num_t)18, GPIO_INTR_ANYEDGE);
    ESP_ERROR_CHECK(gpio_install_isr_service(0));
    gpio_isr_handler_add(GPIO_NUM_14, gpio_isr_handler, (void*) GPIO_NUM_14);
    gpio_isr_handler_add(GPIO_NUM_16, gpio_isr_handler, (void*) GPIO_NUM_16);
    gpio_isr_handler_add(GPIO_NUM_17, gpio_isr_handler, (void*) GPIO_NUM_17);
    gpio_isr_handler_add(GPIO_NUM_18, gpio_isr_handler, (void*) GPIO_NUM_18);
    gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    //
    //
    gpio_config_t io_conf2;
    io_conf2.intr_type = GPIO_INTR_DISABLE;
    io_conf2.mode = GPIO_MODE_OUTPUT;
    io_conf2.pin_bit_mask = ((1ULL<<2) | (1ULL<<4) | (1ULL<<15)); //(1ULL<<0)
    io_conf2.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf2.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf2);
    //
    ledc_timer_config_t ledc_timer2 = {
      .speed_mode = LEDC_LOW_SPEED_MODE,           // timer mode
      .duty_resolution = LEDC_TIMER_8_BIT, // resolution of PWM duty
      .timer_num = LEDC_TIMER_2,            // timer index
      .freq_hz = 5000,                      // frequency of PWM signal
      .clk_cfg = LEDC_AUTO_CLK,              // Auto select the source clock
        };
    ledc_timer_config(&ledc_timer2);
    //
    static ledc_channel_config_t var_ledc_channel0 = {
    .gpio_num   = 4,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel    = LEDC_CHANNEL_0,
    .intr_type  = LEDC_INTR_DISABLE,
    .timer_sel  = LEDC_TIMER_2,
    .duty       = 100, // LEDC channel duty, the duty range is [0, (2**bit_num) - 1],
    .hpoint = 0,
    };
    ledc_channel_config(&var_ledc_channel0);
    //
    static ledc_channel_config_t var_ledc_channel1 = {
    .gpio_num   = 2,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel    = LEDC_CHANNEL_1,
    .intr_type  = LEDC_INTR_DISABLE,
    .timer_sel  = LEDC_TIMER_2,
    .duty       = 100, // LEDC channel duty, the duty range is [0, (2**bit_num) - 1],
    .hpoint = 0,
    };
    ledc_channel_config(&var_ledc_channel1);

    // static ledc_channel_config_t var_ledc_channel2 = {
    // .gpio_num   = 0,
    // .speed_mode = LEDC_LOW_SPEED_MODE,
    // .channel    = LEDC_CHANNEL_2,
    // .intr_type  = LEDC_INTR_DISABLE,
    // .timer_sel  = LEDC_TIMER_2,
    // .duty       = 100, // LEDC channel duty, the duty range is [0, (2**bit_num) - 1],
    // .hpoint = 0,
    // };
    //ledc_channel_config(&var_ledc_channel2);

    static ledc_channel_config_t var_ledc_channel3 = {
    .gpio_num   = 15,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel    = LEDC_CHANNEL_3,
    .intr_type  = LEDC_INTR_DISABLE,
    .timer_sel  = LEDC_TIMER_2,
    .duty       = 100, // LEDC channel duty, the duty range is [0, (2**bit_num) - 1],
    .hpoint = 0,
    };
    ledc_channel_config(&var_ledc_channel3);

    // printf("start i2s calibration \n");
    // size_t bytes_written = 0;
    // for(int i=0;i<32;i++) {
    //   calib[i] = MULT_S32 * 0;// / 1;
    // }
    // // mult_s32 * - 1 -> 2.522v 3.023v  == 1387
    // // * 0            -> 1.632v 1.636v
    // // * 1            -> 0.743v 0.244v  == 1392
    // //for(uint16_t ca=0;ca<100000;ca++) {
    //   i2s_write((i2s_port_t)0, &calib, 32*sizeof(int32_t), &bytes_written, portMAX_DELAY);
    //   i2s_write((i2s_port_t)1, &calib, 32*sizeof(int32_t), &bytes_written, portMAX_DELAY);
    // //}
    // printf("end i2s calibration \n");
    //
    // uint32_t readings = 0;
    // printf("collect readings\n");
    // for(int p=0;p<1000;p++) {
    //   readings += adcvalues[7][0];
    //   vTaskDelay(10 / portTICK_RATE_MS);
    // }
    // printf("readings: %zu \n", readings);

    // 2042703 1.627
    // 2044460 1.633
    // 2045320 1.634
    // 2080066 1.636

printram();




    // Start display task
    xTaskCreate(&displayHandler, "displayHandler", 2048, NULL, 5, NULL);

printf("after displayhandler\n");
printram();
vTaskDelay(1000 / portTICK_RATE_MS);
    // measure load
    // int numIterations = 5000;
    // struct timeval elapsed, start, end;
    // gettimeofday(&start, NULL);
    // for (int i = 0; i < numIterations; ++i) {
    //   hv_process(context, NULL, outBuffers, blockSize);
    // }
    // gettimeofday(&end, NULL);
    // timeval_subtract(&elapsed, &end, &start);
    // uint64_t elapsedTimeUs = (elapsed.tv_sec * 1000000L) + elapsed.tv_usec;
    // // return the us per block
    // printf("%f \n", elapsedTimeUs/((double) numIterations));

    // I2S loop -> runs @ 48000

    double sampleRate = 48000.0;
    context = hv_heavy_new(sampleRate);

    printf("after heavy\n");
    printram();
    vTaskDelay(1000 / portTICK_RATE_MS);

    // Start button queue handler
    xTaskCreate(gpioHandler, "gpioHandler", 2048, NULL, 10, NULL);

    printf("after gpio\n");
    printram();
    vTaskDelay(1000 / portTICK_RATE_MS);

    xTaskCreatePinnedToCore(&audioHandler, "audioHandler", 32000, NULL, 4, NULL,1);
    printf("after audiohandler\n");
    printram();
    vTaskDelay(1000 / portTICK_RATE_MS);
    //xTaskCreate(&audioHandler, "audioHandler", 640000, NULL, 4, NULL);

    //vTaskDelay(1000 / portTICK_RATE_MS);

    //ESP_LOGI(TAG, "xtask RAM left %d", esp_get_free_heap_size());

  //   //0 PLL and Clock Control 0
	// 	spi_write_reg(spi, AD1938_PLL_CLK_CTRL0, (DIS_ADC_DAC  | INPUT256 | PLL_IN_MCLK | MCLK_OUT_XTAL | PLL_PWR_UP));
  //
	// 	// //1 PLL and Clock Control 1
	// 	spi_write_reg(spi, AD1938_PLL_CLK_CTRL1, (DAC_CLK_PLL | ADC_CLK_PLL | ENA_VREF));
  //   //
	// 	// //2 DAC Control 0
	// 	spi_write_reg(spi, AD1938_DAC_CTRL0, (DAC_FMT_I2S | DAC_BCLK_DLY_0 | DAC_SR_48K | DAC_PWR_UP));
  //   //
	// 	//  //3 DAC Control 1
	// 	spi_write_reg(spi, AD1938_DAC_CTRL1, ( DAC_BCLK_SRC_INTERNAL|DAC_BCLK_MASTER| DAC_LRCLK_MASTER |DAC_LRCLK_POL_NORM| DAC_CHANNELS_2 | DAC_LATCH_MID));
  //   //
	// 	// //4 DAC Control 2
	// 	spi_write_reg(spi, AD1938_DAC_CTRL2, DAC_WIDTH_24);
  //   //
	// 	//5 DAC individual channel mutes
	// 	spi_write_reg(spi, AD1938_DAC_CHNL_MUTE, 0x00);/*unmute*/
  //
	// 	//6 DAC L1 volume control
	// 	spi_write_reg(spi, AD1938_DAC_L1_VOL, DACVOL_MAX);
  //
	// 	//7 DAC R1 volume control
	// 	spi_write_reg(spi, AD1938_DAC_R1_VOL, DACVOL_MAX);
  //
	// 	//8 DAC L2 volume control
	// 	spi_write_reg(spi, AD1938_DAC_L2_VOL, DACVOL_MAX);
  //
	// 	//9 DAC R2 volume control
	// 	spi_write_reg(spi, AD1938_DAC_R2_VOL, DACVOL_MAX);
  //
	// 	//10 DAC L3 volume control
	// 	spi_write_reg(spi, AD1938_DAC_L3_VOL, DACVOL_MAX);
  //
	// 	//11 DAC R3 volume control
	// 	spi_write_reg(spi, AD1938_DAC_R3_VOL, DACVOL_MAX);
  //
	// 	//12 DAC L4 volume control
	// 	spi_write_reg(spi, AD1938_DAC_L4_VOL, DACVOL_MAX);
  //
	// 	//13 DAC R4 volume control
	// 	spi_write_reg(spi, AD1938_DAC_R4_VOL, DACVOL_MAX);
  //
	// 	//14 ADC Control 0
	// 	spi_write_reg(spi, AD1938_ADC_CTRL0, ADC_SR_48K);
  //
	// 	//15 ADC Control 1
	// 	spi_write_reg(spi, AD1938_ADC_CTRL1, (ADC_LATCH_MID | ADC_FMT_I2S | ADC_BCLK_DLY_0 | ADC_WIDTH_24));
  //
	// 	//16 ADC Control 2
	// 	spi_write_reg(spi, AD1938_ADC_CTRL2, ( ADC_BCLK_SRC_INTERNAL|ADC_BCLK_MASTER | ADC_CHANNELS_4 | ADC_LRCLK_MASTER  | ADC_LRCLK_FMT_50_50|ADC_LRCLK_POL_NORM|ADC_BCLK_POL_NORM));
  //
  // //  spi_write_reg(spi, AD1938_PLL_CLK_CTRL0, (DIS_ADC_DAC  | INPUT256 | PLL_IN_DLRCLK | MCLK_OUT_OFF |PLL_PWR_UP));
  //   //spi_write_reg(spi, AD1938_PLL_CLK_CTRL0, (ENA_ADC_DAC  | INPUT256 | PLL_IN_DLRCLK | MCLK_OUT_OFF |PLL_PWR_UP));
  //
  //   //spiwrite(spi,3);
  //   uint32_t lcd_id = 0;
  //   for(int all=0;all<17;all++) {
  //     lcd_id = spiget(spi, all);
  //     printf("control %d\n", all);
  //     printf("LCD3  ID: %08X\n", lcd_id);
  //     printf("res: %d\n",recvbuf);
  //   }
    // while(1) {

    // }
}
