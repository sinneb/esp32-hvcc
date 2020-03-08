/*******************************************************************************
 I2C Configuration for a Wolfson WM8978 Audio Codec.
 This file was written based on the information provided in the Codec Specs
 and on the NuovotonDuino project: https://github.com/DFRobot/NuvotonDuino.
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "WM8978.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "math.h"

static const char* TAG = "driver";
uint8_t wm8731device = 27;

//WM8731 register addresses as defined in the datasheet
#define LEFT_LINE_INPUT_CHANNEL_VOLUME_CONTROL  (0x00 << 1)
#define RIGHT_LINE_INPUT_CHANNEL_VOLUME_CONTROL (0x01 << 1)
#define LEFT_CHANNEL_HEADPHONE_VOLUME_CONTROL   (0x02 << 1)
#define RIGHT_CHANNEL_HEADPHONE_VOLUME_CONTROL  (0x03 << 1)
#define ANALOG_AUDIO_PATH_CONTROL               (0x04 << 1)
#define DIGITAL_AUDIO_PATH_CONTROL              (0x05 << 1)
#define POWER_DOWN_CONTROL                      (0x06 << 1)
#define DIGITAL_AUDIO_INTERFACE_FORMAT          (0x07 << 1)
#define SAMPLE_RATE_CONTROL                     (0x08 << 1)
#define DIGITAL_INTERFACE_ACTIVATION            (0x09 << 1)
#define RESET_REGISTER                          (0x0F << 1)

static uint16_t WM8978_REGVAL_TBL[58]=
{
    0X0000,0X0000,0X0000,0X0000,0X0050,0X0000,0X0140,0X0000,
    0X0000,0X0000,0X0000,0X00FF,0X00FF,0X0000,0X0100,0X00FF,
    0X00FF,0X0000,0X012C,0X002C,0X002C,0X002C,0X002C,0X0000,
    0X0032,0X0000,0X0000,0X0000,0X0000,0X0000,0X0000,0X0000,
    0X0038,0X000B,0X0032,0X0000,0X0008,0X000C,0X0093,0X00E9,
    0X0000,0X0000,0X0000,0X0000,0X0003,0X0010,0X0010,0X0100,
    0X0100,0X0002,0X0001,0X0001,0X0039,0X0039,0X0039,0X0039,
    0X0001,0X0001
};

// WM8978 init
uint8_t WM8978::init(uint8_t id)
{
  if(id==0) {
    wm8731device = 26;
    initI2C();
    vTaskDelay(1000 / portTICK_RATE_MS);
  } else if(id==1) {
    wm8731device = 27;
  } else if(id==2) {
    wm8731device = 26;
  }

    //vTaskDelay(1000 / portTICK_RATE_MS);
    //uint8_t res;
    // RESET
    writeRegwithError(0,0);// WM8978

    //setLeftLineIn(int32_t LRINBOTH, int32_t LINMUTE, float LINVOL)
    // no simultaneous load, no mute, 0dB gain
    setLeftLineIn(1, 0, 0);//0dB
    setRightLineIn(1, 0, 0);//0dB

    // Headphone out (0dB)
    setLeftHeadphoneOut(1, 1, 0);//-24dB
    setRightHeadphoneOut(1, 1, 0);//-24dB

    //setAnalogueAudioPathControl(SIDEATT,SIDETONE,DACSEL,BYPASS,INSEL,MUTEMIC,MICBOOST);
    setAnalogueAudioPathControl(0,0,1,0,0,1,0);

    //setDigitalAudioPathControl(int32_t HPOR, int32_t DACMU, int32_t DEEMP, int32_t ADCHPD)
    //clear DC offset, not software mute, no de-emphasis,no adc HPF
    setDigitalAudioPathControl(0,0,0,1);

    //setPowerDownControl(int32_t POWEROFF, int32_t CLKOUTPD, int32_t OSCPD, int32_t OUTPD, int32_t DACPD, int32_t ADCPD, int32_t MICPD, int32_t LINEINPD)
    setPowerDownControl(0,0,0,0,0,0,0,0);

    //setDigitalAudioInterfaceFormat(int32_t BCLKINV, int32_t MS, int32_t LRSWAP, int32_t LRP, int32_t IWL, int32_t FORMAT)
    //no bit clocl invert, slave, no DAC Left Right Clock Swap, Right Channel DAC data when DACLRC low, 16bit, I2S Format MSB left justfied
    setDigitalAudioInterfaceFormat(0,1,0,0,1,0x2);

    //setSamplingControl(int32_t CLKODIV2, int32_t CLKIDIV2, int32_t SR, int32_t BOSR, int32_t USBNORM)
    setSamplingControl(0, 0, 0, 0, 0);//48kHz


    setActiveControl(1);

    // if(res) return 1;
    // writeReg(1,0X1B);   // R1, MICEN (MIC), BIASEN, VMIDSEL[1:0]
    // writeReg(2,0X1B0);  // R2, ROUT1, LOUT1, BOOSTENR, BOOSTENL
    // writeReg(3,0X6C);   // R3, LOUT2, ROUT2, RMIX, LMIX
    // writeReg(6,0);      // R6, MCLK
    // writeReg(43,1<<4);  // R43, INVROUT2
    // writeReg(47,1<<8);  // R47, PGABOOSTL, MIC
    // writeReg(48,1<<8);  // R48, PGABOOSTR, MIC
    // writeReg(49,1<<1);  // R49, TSDEN
    // writeReg(10,1<<3);  // R10, SOFTMUTE
    // writeReg(14,1<<3);  // R14, ADC
    return 0;
}

// Initialize i2c for the ESP32
void WM8978::initI2C(void)
{
    i2c_port_t i2c_master_port = (i2c_port_t) I2C_MASTER_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = (gpio_num_t) I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = (gpio_num_t) I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    i2c_param_config(i2c_master_port, &conf);
    ESP_ERROR_CHECK(
    i2c_driver_install(i2c_master_port, conf.mode,
                       I2C_MASTER_RX_BUF_DISABLE,
                       I2C_MASTER_TX_BUF_DISABLE, 0)
                     );
}

// WM8978 register write
// reg: Register Address
// val: Register value
uint8_t WM8978::writeReg(uint8_t reg,uint16_t val)
{
    unsigned char buf[2];
    buf[0] = (reg<<1)|((val>>8)&0X01);
    buf[1] = val&0XFF;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (wm8731device << 1) | WRITE_BIT, ACK_CHECK_EN);
    i2c_master_write(cmd, buf, 2, ACK_CHECK_EN);
    i2c_master_stop(cmd);
    i2c_master_cmd_begin((i2c_port_t) 1, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);

    WM8978_REGVAL_TBL[reg] = val;
    return 0;
}

// WM8978 register write
// reg: Register Address
// val: Register value
esp_err_t WM8978::writeRegwithError(uint8_t reg,uint8_t val)
{
    esp_err_t errret = ESP_OK;
    uint8_t buf[2];
    buf[0] = reg;//(reg<<1)|((val>>8)&0X01);
    buf[1] = val;//&0XFF;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    errret |= i2c_master_start(cmd);
    errret |= i2c_master_write_byte(cmd, (wm8731device << 1) | WRITE_BIT, ACK_CHECK_EN);
    errret |= i2c_master_write(cmd, buf, 2, ACK_CHECK_EN);
    errret |= i2c_master_stop(cmd);
    errret |= i2c_master_cmd_begin((i2c_port_t) 1, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);

    WM8978_REGVAL_TBL[reg] = val;

    if(errret!=ESP_OK) {
      ESP_LOGE(TAG, "i2c communication error");
    } else {
      ESP_LOGI(TAG, "i2c communication ok");
    }

    return errret;
}

// WM8978 read register
// Reads the value of the local register buffer zone
// reg: Register Address
// Return Value: Register value
uint16_t WM8978::readReg(uint8_t reg)
{
    return WM8978_REGVAL_TBL[reg];
}

// WM8978 DAC/ADC
// adcen: adc 1/0
// dacen: dac 1/0
void WM8978::addaCfg(uint8_t dacen,uint8_t adcen)
{
    uint16_t regval;
    regval = readReg(3);        // R3
    if(dacen)regval |= 3<<0;    // R3 DACR & DACL
    else regval &= ~(3<<0);     // R3 DACR & DACL
    writeReg(3,regval);         // R3
    regval=readReg(2);          // R2
    if(adcen)regval|=3<<0;      // R2 ADCR & ADCL
    else regval&=~(3<<0);       // R2 ADCR & ADCL
    writeReg(2,regval);         // R2
}

// WM8978 Input Config
// micen: MIC 1/0
// lineinen: Line In 1/0
// auxen: aux 1/0
void WM8978::inputCfg(uint8_t micen,uint8_t lineinen,uint8_t auxen)
{
    uint16_t regval;
    regval = readReg(2);            // R2
    if(micen) regval|=3<<2;         // INPPGAENR, INPPGAENL (MIC/PGA)
    else regval&=~(3<<2);
    writeReg(2,regval);             // R2

    regval=readReg(44);             // R44
    if(micen) regval|=3<<4|3<<0;    // LIN2INPPGA, LIP2INPGA, RIN2INPPGA, RIP2INPGA
    else regval&=~(3<<4|3<<0);
    writeReg(44,regval);            // R44

    if(lineinen) lineinGain(5);     // LINE IN 0dB
    else lineinGain(0);
    if(auxen) auxGain(7);           // AUX 6dB
    else auxGain(0);
}

// WM8978
// dacen: DAC 1/0
// bpsen: Bypass (MIC, LINE IN,AUX) 1/0
void WM8978::outputCfg(uint8_t dacen,uint8_t bpsen)
{
    uint16_t regval = 0;
    if(dacen) regval|=1<<0; // DAC
    if(bpsen)
    {
        regval|=1<<1;       // BYPASS
        regval|=5<<2;       // 0dB
    }
    writeReg(50,regval);    // R50
    writeReg(51,regval);    // R51
}

// WM8978 MIC (BOOST 20dB,MIC-->ADC)
// gain: 0~63, -12dB~35.25dB, 0.75dB/Step
void WM8978::micGain(uint8_t gain)
{
    gain &= 0X3F;
    writeReg(45,gain);      // R45,PGA
    writeReg(46,gain|1<<8);	// R46, PGA
}

// WM8978 L2/R2 (Line In) (L2/R2-->ADC)
// gain: 0~7, 0ֹ, 1~7, -12dB~6dB, 3dB/Step
void WM8978::lineinGain(uint8_t gain)
{
    uint16_t regval;
    gain &= 0X07;
    regval = readReg(47);           // R47
    regval&=~(7<<4);
    writeReg(47,regval|gain<<4);    // R47
    regval = readReg(48);           // R48
    regval&=~(7<<4);
    writeReg(48,regval|gain<<4);    // R48
}

// WM8978 AUXR, AUXL(PWM) (AUXR/L-->ADC)
// gain:0~7, 0ֹ, 1~7, -12dB~6dB, 3dB/Step
void WM8978::auxGain(uint8_t gain)
{
    uint16_t regval;
    gain &= 0X07;
    regval = readReg(47);           // R47
    regval&=~(7<<0);
    writeReg(47,regval|gain<<0);    // R47
    regval = readReg(48);           // R48
    regval&=~(7<<0);
    writeReg(48,regval|gain<<0);    // R48
}

// I2S
// fmt: 0, LSB; 1,MSB; 2, I2S; 3, PCM/DSP;
// len:0,16λ;1,20λ;2,24λ;3,32λ;
void WM8978::i2sCfg(uint8_t fmt,uint8_t len)
{
    fmt &= 0X03;
    len &= 0X03;
    writeReg(4,(fmt<<3)|(len<<5));	// R4, WM8978
}

// Headphone Output Volume
// voll: (0~63)
// volr: (0~63)
void WM8978::hpVolSet(uint8_t voll,uint8_t volr)
{
    voll &= 0X3F;
    volr &= 0X3F;
    if(voll==0) voll|=1<<6;
    if(volr==0) volr|=1<<6;
    writeReg(52,voll);          // R52
    writeReg(53,volr|(1<<8));   // R53 (HPVU=1)
}

// Speaker Volume
// voll: (0~63)
void WM8978::spkVolSet(uint8_t volx)
{
    volx &= 0X3F;
    if(volx==0) volx|=1<<6;
    writeReg(54,volx);          // R54
    writeReg(55,volx|(1<<8));   // R55 (SPKVU=1)
}

// 3D Setup
// depth: 0~15
void WM8978::threeDSet(uint8_t depth)
{
    depth &= 0XF;
    writeReg(41,depth);     // R41
}

// EQ/3D
// dir:0, ADC
// 1,DAC
void WM8978::eq3DDir(uint8_t dir)
{
    uint16_t regval;
    regval = readReg(0X12);
    if(dir) regval|=1<<8;
    else regval&=~(1<<8);
    writeReg(18,regval);    // R18
}

// EQ1
// cfreq: 0~3, 80/105/135/175Hz
// gain: 0~24, -12~+12dB
void WM8978::eq1Set(uint8_t cfreq,uint8_t gain)
{
    uint16_t regval;
    cfreq &= 0X3;
    if(gain>24) gain = 24;
    gain = 24-gain;
    regval = readReg(18);
    regval &= 0X100;
    regval |= cfreq<<5;
    regval |= gain;
    writeReg(18,regval);    // R18, EQ1
}

// EQ2
// cfreq: 0~3, 230/300/385/500Hz
// gain: 0~24, -12~+12dB
void WM8978::eq2Set(uint8_t cfreq,uint8_t gain)
{
    uint16_t regval = 0;
    cfreq &= 0X3;
    if(gain>24) gain = 24;
    gain = 24-gain;
    regval |= cfreq<<5;
    regval |= gain;
    writeReg(19,regval);
}

// EQ3
// cfreq: 0~3, 650/850/1100/1400Hz
// gain: 0~24, -12~+12dB
void WM8978::eq3Set(uint8_t cfreq,uint8_t gain)
{
    uint16_t regval = 0;
    cfreq &= 0X3;
    if(gain>24) gain = 24;
    gain = 24-gain;
    regval |= cfreq << 5;
    regval |= gain;
    writeReg(20,regval);    // R20, EQ3
}

// EQ4
// cfreq: 0~3, 1800/2400/3200/4100Hz
// gain: 0~24, -12~+12dB
void WM8978::eq4Set(uint8_t cfreq,uint8_t gain)
{
    uint16_t regval = 0;
    cfreq &= 0X3;
    if(gain>24) gain = 24;
    gain = 24-gain;
    regval |= cfreq << 5;
    regval |= gain;
    writeReg(21,regval);    // R21, EQ4
}

// EQ5
// cfreq: 0~3, 5300/6900/9000/11700Hz
// gain: 0~24, -12~+12dB
void WM8978::eq5Set(uint8_t cfreq,uint8_t gain)
{
    uint16_t regval = 0;
    cfreq &= 0X3;
    if(gain>24) gain = 24;
    gain = 24-gain;
    regval |= cfreq << 5;
    regval |= gain;
    writeReg(22,regval);    // R22, EQ5
}

void WM8978::alcSet(uint8_t enable, uint8_t maxgain, uint8_t mingain)
{
    uint16_t regval;

    if(maxgain>7) maxgain=7;
    if(mingain>7) mingain=7;

    regval=readReg(32);
    if(enable)
    regval |= (3<<7);
    regval |= (maxgain<<3)|(mingain<<0);
    writeReg(32,regval);
}

void WM8978::noiseSet(uint8_t enable,uint8_t gain)
{
    uint16_t regval;

    if(gain>7) gain=7;

    regval = readReg(35);
    regval = (enable<<3);
    regval |= gain;
    writeReg(35,regval);    // R18, EQ1
}

void WM8978::setLeftLineIn(int32_t LRINBOTH, int32_t LINMUTE,  float _LINVOL)
{
    // LINVOL is a 5 bit number to set volume from 0x00 = -34.5 dB to ox1F = +12dB, 1.5dB steps, 0x17 is 0dB
    // LINMUTE, LRINBOTH are single bit
    if(_LINVOL<-34.5)_LINVOL=-34.5;
    if(_LINVOL>12)_LINVOL=12;
    int32_t LINVOL=round((_LINVOL+34.5)/1.5);
    int32_t val = ((LRINBOTH & 0x01) << 8) | ((LINMUTE & 0x01) << 7) | (LINVOL & 0x1F);
    writeRegwithError(LEFT_LINE_INPUT_CHANNEL_VOLUME_CONTROL, val);
}

void WM8978::setRightLineIn(int32_t RLINBOTH, int32_t RINMUTE, float _RINVOL)
{
    // RINVOL is a 5 bit number to set volume from 0x00 = -34.5 dB to ox1F = +12dB, 1.5dB steps, 0x17 is 0dB
    // RINMUTE, RLINBOTH are single bit
    if(_RINVOL<-34.5)_RINVOL=-34.5;
    if(_RINVOL>12)_RINVOL=12;
    int32_t RINVOL=round((_RINVOL+34.5)/1.5);
    int32_t val = ((RLINBOTH & 0x01) << 8) | ((RINMUTE & 0x01) << 7) | (RINVOL & 0x1F);
    writeRegwithError(RIGHT_LINE_INPUT_CHANNEL_VOLUME_CONTROL, val);
}

void WM8978::setLeftHeadphoneOut(int32_t LRHPBOTH, int32_t LZCEN, int32_t LHPVOL)
{
    //LHPVOL=-73~+6
    if(LHPVOL<-73)LHPVOL=-73;
    if(LHPVOL>6)LHPVOL=6;
    LHPVOL+=48+73;//LHPVOL=0110000 to 11111111, 48(0110000) means -73dB, 127 means +6dB
    int32_t val = ((LRHPBOTH & 0x01) << 8) | ((LZCEN & 0x01) << 7) | (LHPVOL & 0x7F);
    writeRegwithError(LEFT_CHANNEL_HEADPHONE_VOLUME_CONTROL, val);
}

void WM8978::setRightHeadphoneOut(int32_t RLHPBOTH, int32_t RZCEN, int32_t RHPVOL)
{
    //RHPVOL=-73~+6
    if(RHPVOL<-73)RHPVOL=-73;
    if(RHPVOL>6)RHPVOL=6;
    RHPVOL+=48+73;//RHPVOL=0110000 to 11111111, 48(0110000) means -73dB, 127 means +6dB
    int32_t val = ((RLHPBOTH & 0x01) << 8) | ((RZCEN & 0x01) << 7) | (RHPVOL & 0x7F);
    writeRegwithError(RIGHT_CHANNEL_HEADPHONE_VOLUME_CONTROL, val);
}

void WM8978::setAnalogueAudioPathControl(int32_t SIDEATT, int32_t SIDETONE, int32_t DACSEL, int32_t BYPASS, int32_t INSEL, int32_t MUTEMIC, int32_t MICBOOST)
{
    // Insert description
    int32_t val = ((SIDEATT & 0x03) << 6) | ((SIDETONE & 0x01) << 5) | ((DACSEL & 0x01) << 4) | ((BYPASS & 0x01) << 3) | ((INSEL & 0x01) << 2) | ((MUTEMIC & 0x01) << 1) | ((MICBOOST & 0x01) << 0);
    writeRegwithError(ANALOG_AUDIO_PATH_CONTROL, val);
}

void WM8978::setDigitalAudioPathControl(int32_t HPOR, int32_t DACMU, int32_t DEEMP, int32_t ADCHPD)
{
    // Description
    int32_t val =  ((HPOR & 0x01) << 4)  | ((DACMU & 0x01) << 3) | ((DEEMP & 0x03) << 1) | ((ADCHPD & 0x01) << 0);
    writeRegwithError(DIGITAL_AUDIO_PATH_CONTROL, val);
}

void WM8978::setPowerDownControl(int32_t POWEROFF, int32_t CLKOUTPD, int32_t OSCPD, int32_t OUTPD, int32_t DACPD, int32_t ADCPD, int32_t MICPD, int32_t LINEINPD)
{

    int32_t val = ((POWEROFF & 0x01) << 7) | ((CLKOUTPD & 0x01) << 6) | ((OSCPD & 0x01) << 5) | ((OUTPD & 0x01) << 4) | ((DACPD & 0x01) << 3) | ((ADCPD & 0x01) << 2) | ((MICPD & 0x01) << 1) | (LINEINPD & 0x01);
    writeRegwithError(POWER_DOWN_CONTROL, val);
}

void WM8978::setDigitalAudioInterfaceFormat(int32_t BCLKINV, int32_t MS, int32_t LRSWAP, int32_t LRP, int32_t IWL, int32_t FORMAT)
{

    int32_t val = ((BCLKINV & 0x01) << 7) | ((MS & 0x01) << 6) | ((LRSWAP & 0x01) << 5) | ((LRP & 0x01) << 4) | ((IWL & 0x03) << 2) | (FORMAT & 0x03);
    writeRegwithError(DIGITAL_AUDIO_INTERFACE_FORMAT, val);
}

void WM8978::setSamplingControl(int32_t CLKODIV2, int32_t CLKIDIV2, int32_t SR, int32_t BOSR, int32_t USBNORM)
{

    int32_t val = ((CLKODIV2 & 0x01) << 7) | ((CLKIDIV2 & 0x01) << 6) | ((SR & 0x0F) << 2) | ((BOSR & 0x01) << 1) | (USBNORM & 0x01);
    writeRegwithError(SAMPLE_RATE_CONTROL, val);
}

void WM8978::setActiveControl(int32_t ACTIVE)
{

    int32_t val = (ACTIVE & 0x01);
    writeRegwithError(DIGITAL_INTERFACE_ACTIVATION, val);
}
