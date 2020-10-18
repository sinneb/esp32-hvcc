/*The global address for the AD1938 is 0x04, shifted left one bit due to the R/W bit.*/
#define AD1938_GLOBAL_ADDRESS   0x04

#define AD1938_WRITE_ADDRESS    (AD1938_GLOBAL_ADDRESS<<1)
#define AD1938_READ_ADDRESS     ((AD1938_GLOBAL_ADDRESS<<1)|1)

#define AD1938_SPI_WRITE_BYTE_COUNT   3
#define AD1938_SPI_READ_BYTE_COUNT    2

/*------------------------------------------------------------------------------*/
/*PLL and Clock Control 0                                                       */
/*------------------------------------------------------------------------------*/
#define AD1938_PLL_CLK_CTRL0    0x00

/*
Bit Value Function Description
0 0 Normal operation PLL power-down
1 Power-down
2:1 00 INPUT 256 (× 44.1 kHz or 48 kHz) MCLKI/XI pin functionality (PLL active), master clock rate setting
    01 INPUT 384 (× 44.1 kHz or 48 kHz)
    10 INPUT 512 (× 44.1 kHz or 48 kHz)
    11 INPUT 768 (× 44.1 kHz or 48 kHz)
4:3 00 XTAL oscillator enabled MCLKO/XO pin, master clock rate setting
    01 256 × fS VCO output
    10 512 × fS VCO output
    11 Off
6:5 00 MCLKI/XI PLL input
    01 DLRCLK
    10 ALRCLK
    11 Reserved
7 0 Disable: ADC and DAC idle Internal master clock enable
  1 Enable: ADC and DAC active
*/

#define DIS_ADC_DAC         (0x00)
#define ENA_ADC_DAC         (0x80)

#define PLL_IN_MCLK         (0x00)
#define PLL_IN_DLRCLK       (0x20)
#define PLL_IN_ALRCLK       (0x40)

#define MCLK_OUT_XTAL       (0x00)
#define MCLK_OUT_256FS      (0x08)
#define MCLK_OUT_512FS      (0x10)
#define MCLK_OUT_OFF        (0x18)

#define INPUT256            (0x00)
#define INPUT384            (0x02)
#define INPUT512            (0x04)
#define INPUT768            (0x06)

#define PLL_PWR_UP          (0x00)
#define PLL_PWR_DWN         (0x01)

/*------------------------------------------------------------------------------*/
/*PLL and Clock Control 1                                                       */
/*------------------------------------------------------------------------------*/
#define AD1938_PLL_CLK_CTRL1     0x01
/*
Bit Value Function Description
0 0 PLL clock DAC clock source select
1 MCLK
1 0 PLL clock ADC clock source select
1 MCLK
2 0 Enabled On-chip voltage reference
1 Disabled
3 0 Not locked PLL lock indicator (read-only)
  1 Locked
7:4 0000 Reserved
*/
#define AD1938_PLL_LOCK     (0x08)

#define DIS_VREF            (0x04)
#define ENA_VREF            (0x00)

#define ADC_CLK_PLL         (0x00)
#define ADC_CLK_MCLK        (0x20)

#define DAC_CLK_PLL         (0x00)
#define DAC_CLK_MCLK        (0x01)

/*------------------------------------------------------------------------------*/
/*        DAC Control 0                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_CTRL0         0x02
/*
Bit Value Function Description
0 0 Normal Power-down
1 Power-down
2:1 00 32 kHz/44.1 kHz/48 kHz Sample rate
    01 64 kHz/88.2 kHz/96 kHz
    10 128 kHz/176.4 kHz/192 kHz
    11 Reserved
5:3 000 1 SDATA delay (BCLK periods)
    001 0
    010 8
    011 12
    100 16
    101 Reserved
    110 Reserved
    111 Reserved
7:6 00 Stereo (normal) Serial format
    01 TDM (daisy chain)
    10 DAC AUX mode (ADC-, DAC-, TDM-coupled)
    11 Dual-line TDM
*/
#define DAC_FMT_I2S         (0x00)
#define DAC_FMT_TDM         (0x40)
#define DAC_FMT_AUX         (0x80)
#define DAC_FMT_DUALTDM     (0xc0)


#define DAC_BCLK_DLY_1      (0x00)
#define DAC_BCLK_DLY_0      (0x08)
#define DAC_BCLK_DLY_8      (0x01)
#define DAC_BCLK_DLY_12     (0x18)
#define DAC_BCLK_DLY_16     (0x20)

#define DAC_SR_48K          (0x00)
#define DAC_SR_96K          (0x02)
#define DAC_SR_192K         (0x04)

#define DAC_PWR_UP          (0x00)
#define DAC_PWR_DWN         (0x01)
/*------------------------------------------------------------------------------*/
/*        DAC Control 1                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_CTRL1        0x03

/*
Bit Value Function Description
0   0 Latch in mid cycle (normal) BCLK active edge (TDM in)
1 Latch in at end of cycle (pipeline)
2:1 00 64 (2 channels) BCLKs per frame
    01 128 (4 channels)
    10 256 (8 channels)
    11 512 (16 channels)
3 0 Left low LRCLK polarity
  1 Left high
4 0 Slave LRCLK master/slave
  1 Master
5 0 Slave BCLK master/slave
  1 Master
6 0 DBCLK pin BCLK source
  1 Internally generated
7 0 Normal BCLK polarity
  1 Inverted
*/

#define DAC_BCLK_POL_NORM       (0x00)
#define DAC_BCLK_POL_INV        (0x80)

#define DAC_BCLK_SRC_PIN        (0x00)
#define DAC_BCLK_SRC_INTERNAL   (0x40)

#define DAC_BCLK_SLAVE          (0x00)
#define DAC_BCLK_MASTER         (0x20)

#define DAC_LRCLK_SLAVE         (0x00)
#define DAC_LRCLK_MASTER        (0x10)

#define DAC_LRCLK_POL_NORM      (0x00)
#define DAC_LRCLK_POL_INV       (0x08)

#define DAC_CHANNELS_2          (0x00)
#define DAC_CHANNELS_4          (0x02)
#define DAC_CHANNELS_8          (0x04)
#define DAC_CHANNELS_16         (0x06)

#define DAC_LATCH_MID           (0x00)
#define DAC_LATCH_END           (0x01)
/*------------------------------------------------------------------------------*/
/*       DAC Control 2                                                          */
/*------------------------------------------------------------------------------*/
/*
Bit Value Function Description
0   0 Unmute Master mute
1 Mute
2:1 00 Flat De-emphasis (32 kHz/44.1 kHz/48 kHz mode only)
    01 48 kHz curve
    10 44.1 kHz curve
    11 32 kHz curve
4:3 00 24 Word width
    01 20
    10 Reserved
    11 16
5 0 Noninverted DAC output polarity
  1 Inverted
7:6 00 Reserved
*/
#define AD1938_DAC_CTRL2        0x04
#define DAC_OUT_POL_NORM    (0x00)
#define DAC_OUT_POL_INV     (0x20)

#define DAC_WIDTH_24        (0x00)
#define DAC_WIDTH_20        (0x08)
#define DAC_WIDTH_16        (0x18)

#define DAC_DEEMPH_FLAT     (0x00)
#define DAC_DEEMPH_48K      (0x02)
#define DAC_DEEMPH_44_1K    (0x04)
#define DAC_DEEMPH_32K      (0x06)

#define DAC_UNMUTE_ALL      (0x00)
#define DAC_MUTE_ALL        (0x01)
/*------------------------------------------------------------------------------*/
/* DAC individual channel mutes                                                */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_CHNL_MUTE    0x05
/*
Bit Value Function Description
0 0 Unmute DAC 1 left mute
  1 Mute
1 0 Unmute DAC 1 right mute
  1 Mute
2 0 Unmute DAC 2 left mute
  1 Mute
3 0 Unmute DAC 2 right mute
  1 Mute
4 0 Unmute DAC 3 left mute
  1 Mute
5 0 Unmute DAC 3 right mute
  1 Mute
6 0 Unmute DAC 4 left mute
  1 Mute
7 0 Unmute DAC 4 right mute
  1 Mute
*/
#define DACMUTE_R4    (0x80)
#define DACMUTE_L4    (0x40)
#define DACMUTE_R3    (0x20)
#define DACMUTE_L3    (0x10)
#define DACMUTE_R2    (0x08)
#define DACMUTE_L2    (0x04)
#define DACMUTE_R1    (0x02)
#define DACMUTE_L1    (0x01)

/*
Bit Value Function Description
7:0        0        No attenuation DAC volume control
1 to 254  -3/8 dB per step
255       Full attenuation
*/
#define DACVOL_MIN      (0xFF)
#define DACVOL_LOW      (0xC0)
#define DACVOL_MED      (0x80)
#define DACVOL_HI       (0x40)
#define DACVOL_MAX      (0x00) // 0db Volume
#define DACVOL_MASK     (0xFF)
/*------------------------------------------------------------------------------*/
/*DAC L1 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_L1_VOL       0x06
/*------------------------------------------------------------------------------*/
/*DAC R1 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_R1_VOL       0x07
/*------------------------------------------------------------------------------*/
/*DAC L2 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_L2_VOL       0x08
/*------------------------------------------------------------------------------*/
/*DAC R2 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_R2_VOL       0x09
/*------------------------------------------------------------------------------*/
/*DAC L3 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_L3_VOL       0x0a

/*------------------------------------------------------------------------------*/
/*DAC R3 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_R3_VOL       0x0b

/*------------------------------------------------------------------------------*/
/*DAC L4 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_L4_VOL       0x0c
/*------------------------------------------------------------------------------*/
/*DAC R4 volume control                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_DAC_R4_VOL       0x0d

/*------------------------------------------------------------------------------*/
/*        ADC Control 0                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_ADC_CTRL0        0x0e
/*
Bit Value Function Description
0 0 Normal Power-down
  1 Power down
1 0 Off High-pass filter
  1 On
2 0 Unmute ADC L1 mute
  1 Mute
3 0 Unmute ADC R1 mute
  1 Mute
4 0 Unmute ADC L2 mute
  1 Mute
5 0 Unmute ADC R2 mute
  1 Mute
7:6 00 32 kHz/44.1 kHz/48 kHz Output sample rate
    01 64 kHz/88.2 kHz/96 kHz
    10 128 kHz/176.4 kHz/192 kHz
    11 Reserved
*/
#define ADC_SR_48K          (0x00)
#define ADC_SR_96K          (0x40)
#define ADC_SR_192K         (0x80)

#define ADC_R2_UNMUTE       (0x00)
#define ADC_R2_MUTE         (0x20)

#define ADC_L2_UNMUTE       (0x00)
#define ADC_L2_MUTE         (0x10)

#define ADC_R1_UNMUTE       (0x00)
#define ADC_R1_MUTE         (0x08)

#define ADC_L1_UNMUTE       (0x00)
#define ADC_L1_MUTE         (0x04)

#define ADC_HP_FILT_OFF     (0x00)
#define ADC_HP_FILT_ON      (0x02)

#define ADC_PWR_UP          (0x00)
#define ADC_PWR_DWN         (0x01)
/*------------------------------------------------------------------------------*/
/*        ADC Control 01                                                        */
/*------------------------------------------------------------------------------*/
#define AD1938_ADC_CTRL1        0x0f
/*
Bit Value Function Description
1:0 00 24 Word width
    01 20
    10 Reserved
    11 16
4:2 000 1 SDATA delay (BCLK periods)
    001 0
    010 8
    011 12
    100 16
    101 Reserved
    110 Reserved
    111 Reserved
6:5 00 Stereo Serial format
    01 TDM (daisy chain)
    10 ADC AUX mode (ADC-, DAC-, TDM-coupled)
    11 Reserved
7 0 Latch in mid cycle (normal) BCLK active edge (TDM in)
  1 Latch in at end of cycle (pipeline)
*/
#define ADC_LATCH_MID       (0x00)
#define ADC_LATCH_END       (0x80)

#define ADC_FMT_I2S         (0x00)
#define ADC_FMT_TDM         (0x20)
#define ADC_FMT_AUX         (0x40)

#define ADC_BCLK_DLY_1      (0x00)
#define ADC_BCLK_DLY_0      (0x04)
#define ADC_BCLK_DLY_8      (0x08)
#define ADC_BCLK_DLY_12     (0x0c)
#define ADC_BCLK_DLY_16     (0x10)

#define ADC_WIDTH_24        (0x00)
#define ADC_WIDTH_20        (0x01)
#define ADC_WIDTH_16        (0x03)
/*------------------------------------------------------------------------------*/
/*        ADC Control 2                                                         */
/*------------------------------------------------------------------------------*/
#define AD1938_ADC_CTRL2        0x10
/*
Bit Value Function Description
0 0 50/50 (allows 32, 24, 20, or 16 bit clocks (BCLKs) per channel) LRCLK format
  1 Pulse (32 BCLKs per channel)
1 0 Drive out on falling edge (DEF) BCLK polarity
  1 Drive out on rising edge
2 0 Left low LRCLK polarity
  1 Left high
3 0 Slave LRCLK master/slave
  1 Master
5:4 00 64 BCLKs per frame
    01 128
    10 256
    11 512
6 0 Slave BCLK master/slave
  1 Master
7 0 ABCLK pin BCLK source
  1 Internally generated
*/

#define ADC_BCLK_SRC_PIN        (0x00)
#define ADC_BCLK_SRC_INTERNAL   (0x80)

#define ADC_BCLK_SLAVE          (0x00)
#define ADC_BCLK_MASTER         (0x40)

#define ADC_CHANNELS_2          (0x00)
#define ADC_CHANNELS_4          (0x10)
#define ADC_CHANNELS_8          (0x20)
#define ADC_CHANNELS_16         (0x30)

#define ADC_LRCLK_SLAVE         (0x00)
#define ADC_LRCLK_MASTER        (0x08)

#define ADC_LRCLK_POL_NORM      (0x00)
#define ADC_LRCLK_POL_INV       (0x04)

#define ADC_BCLK_POL_NORM       (0x00)
#define ADC_BCLK_POL_INV        (0x02)

#define ADC_LRCLK_FMT_50_50     (0x00)
#define ADC_LRCLK_FMT_PULSE     (0x01)
