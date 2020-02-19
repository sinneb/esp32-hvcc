#ifndef __WM8978_H
#define __WM8978_H

#include <stdio.h>
#include <stdint.h>
#include "esp_types.h"
#include "esp_err.h"

#define I2C_MASTER_NUM 1 /*!< I2C port number for master dev */
#define I2C_MASTER_SCL_IO 18
#define I2C_MASTER_SDA_IO 19
#define I2C_MASTER_FREQ_HZ 100000
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0

#define WM8978_ADDR 0X1A	//WM8978

#define WRITE_BIT I2C_MASTER_WRITE              /*!< I2C master write */
#define ACK_CHECK_EN 0x1

#define EQ1_80Hz 0X00
#define EQ1_105Hz 0X01
#define EQ1_135Hz 0X02
#define EQ1_175Hz	0X03

#define EQ2_230Hz	0X00
#define EQ2_300Hz	0X01
#define EQ2_385Hz	0X02
#define EQ2_500Hz	0X03

#define EQ3_650Hz	0X00
#define EQ3_850Hz	0X01
#define EQ3_1100Hz 0X02
#define EQ3_14000Hz 0X03

#define EQ4_1800Hz 0X00
#define EQ4_2400Hz 0X01
#define EQ4_3200Hz 0X02
#define EQ4_4100Hz 0X03

#define EQ5_5300Hz 0X00
#define EQ5_6900Hz 0X01
#define EQ5_9000Hz 0X02
#define EQ5_11700Hz 0X03

class WM8978
{
  public:
    uint8_t init(void);
    void initI2C(void);
    void addaCfg(uint8_t dacen,uint8_t adcen);
    void inputCfg(uint8_t micen,uint8_t lineinen,uint8_t auxen);
    void outputCfg(uint8_t dacen,uint8_t bpsen);
    void micGain(uint8_t gain);
    void lineinGain(uint8_t gain);
    void auxGain(uint8_t gain);
    uint8_t writeReg(uint8_t reg,uint16_t val);
    esp_err_t writeRegwithError(uint8_t reg,uint8_t val);
    uint16_t readReg(uint8_t reg);
    void hpVolSet(uint8_t voll,uint8_t volr);
    void spkVolSet(uint8_t volx);
    void i2sCfg(uint8_t fmt,uint8_t len);
    void threeDSet(uint8_t depth);
    void eq3DDir(uint8_t dir);
    void eq1Set(uint8_t cfreq,uint8_t gain);
    void eq2Set(uint8_t cfreq,uint8_t gain);
    void eq3Set(uint8_t cfreq,uint8_t gain);
    void eq4Set(uint8_t cfreq,uint8_t gain);
    void eq5Set(uint8_t cfreq,uint8_t gain);
    void noiseSet(uint8_t enable,uint8_t gain);
    void alcSet(uint8_t enable, uint8_t maxgain, uint8_t mingain);

    void setLeftLineIn(int32_t LRINBOTH, int32_t LINMUTE, float LINVOL);
    void setRightLineIn(int32_t RLINBOTH, int32_t RINMUTE, float RINVOL);
    void setLeftHeadphoneOut(int32_t LRHPBOTH, int32_t LZCEN, int32_t LHPVOL);
    void setRightHeadphoneOut(int32_t RLHPBOTH, int32_t RZCEN, int32_t RHPVOL);
    void setAnalogueAudioPathControl(int32_t SIDEATT, int32_t SIDETONE, int32_t DACSEL, int32_t BYPASS, int32_t INSEL, int32_t MUTEMIC, int32_t MICBOOST);
    void setDigitalAudioPathControl(int32_t HPOR, int32_t DACMU, int32_t DEEMP, int32_t ADCHPD);
    void setPowerDownControl(int32_t POWEROFF, int32_t CLKOUTPD, int32_t OSCPD, int32_t OUTPD, int32_t DACPD, int32_t ADCPD, int32_t MICPD, int32_t LINEINPD);
    void setDigitalAudioInterfaceFormat(int32_t BCLKINV, int32_t MS, int32_t LRSWAP, int32_t LRP, int32_t IWL, int32_t FORMAT);
    void setSamplingControl(int32_t CLKODIV2, int32_t CLKIDIV2, int32_t SR, int32_t BOSR, int32_t USBNORM);
    void setActiveControl(int32_t ACTIVE);
};

#endif
