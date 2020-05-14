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
  int getNumInputChannels() override { return 2; }
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
  static void cBinop_oTfBUYco_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DjV097jI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_u3fUKkd3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_20C7gq6G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Od8ftV6j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_wr9ZrKYu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_8ZcZ1Llz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EmBCarOi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R11widXg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_aIjWEAqV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Fj9t6CqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_23zTS2ch_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_u0Jy4x82_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0FNl1ZP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_WCeQMmEX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PJXmCD4r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_2LVCG0mK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PKDfZMQT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zYEte6kA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_tftXFBYJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vXHr5oFt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mXoYJdjv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QfmrWxqO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q4bBLNH2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_R1Vakmyo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_SGtuDlnH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_lVNNKbyw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A7zFxzNH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CGjDzVNd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Va79dK7L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QHUr7NjC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dbeVmS5I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nZIot3Kn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_IJgS5KFi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_mmnDA9DS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_39Q4i4c2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LpLo1WOw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_3fqLMmFG_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_6uFFIyR4;
  SignalPhasor sPhasor_lSQu3iTg;
  SignalPhasor sPhasor_nU4Dlfc4;
  SignalPhasor sPhasor_YYkhS2m8;
  SignalVarf sVarf_0lZfXd1R;
  ControlBinop cBinop_oTfBUYco;
  ControlVar cVar_EmBCarOi;
  SignalVarf sVarf_Xc5L0rxN;
  ControlBinop cBinop_R11widXg;
  SignalVarf sVarf_nUQVgg2q;
  SignalVarf sVarf_CE9lEChA;
  ControlIf cIf_2LVCG0mK;
  ControlSlice cSlice_tftXFBYJ;
  ControlSlice cSlice_vXHr5oFt;
  ControlBinop cBinop_mXoYJdjv;
  ControlVar cVar_R1Vakmyo;
  ControlBinop cBinop_A7zFxzNH;
  ControlBinop cBinop_Va79dK7L;
  ControlVar cVar_LpLo1WOw;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
