/**
 * Copyright (c) 2020 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_HEAVY_HPP_
#define _HEAVY_CONTEXT_HEAVY_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlIf.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_heavy : public HeavyContext {

 public:
  Heavy_heavy(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_heavy();

  const char *getName() override { return "heavy"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 4; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        POT1 = 0x3AE704A5, // pot1
        POT2 = 0xDDC4EBDB, // pot2
        POT3 = 0x125109EA, // pot3
        POT4 = 0x73BEE661, // pot4
        POT5 = 0xF2BC7D02, // pot5
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        LED1 = 0xE817C68D, // led1
        LED2 = 0xBB2E5490, // led2
        LED3 = 0xE14EE92B, // led3
        LED4 = 0x47FF8A5E, // led4
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cSend_gWoBBSUo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_C9VB00Y8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_RoREtCdB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_5BrW1o2Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cICHT37D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OcZbN29Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_ncEFrRHL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7RH3FX10_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_DmpouRse_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_i8YRvSRR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_8tgXHReM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EdHNLuGz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_J9TC7mlH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JxqU3gsG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CQLhBYug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mMFwzCBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UQsXd5SD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Lj4gAYf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_94QcwWn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_qH9mj3GS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sSSoDqbH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_LBah4YZe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_JB8turHL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vjh6g2HK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5dE3ooGG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CuZTBg8K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kjg23WpT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QQCdCIDR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ywLjc7Tz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lNGs7ZTm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ys0R2jXo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_bNNEruvV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_m9r0ZEvu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_suncw55e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8z10xsLl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6kt50oow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FAwsN5bP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_70qvyf4s_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_lWfUc4Vq;
  SignalPhasor sPhasor_bmLpPQTa;
  ControlVar cVar_cICHT37D;
  ControlBinop cBinop_OcZbN29Z;
  ControlBinop cBinop_7RH3FX10;
  SignalVarf sVarf_l87uahly;
  SignalVarf sVarf_AFqxhbzM;
  ControlBinop cBinop_UQsXd5SD;
  ControlSlice cSlice_94QcwWn8;
  ControlSlice cSlice_qH9mj3GS;
  ControlIf cIf_JB8turHL;
  ControlVar cVar_vjh6g2HK;
  ControlBinop cBinop_ys0R2jXo;
  SignalVarf sVarf_NgUIHt4N;
  ControlVar cVar_8z10xsLl;
  SignalVarf sVarf_PKeLgOOV;
  ControlBinop cBinop_FAwsN5bP;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
