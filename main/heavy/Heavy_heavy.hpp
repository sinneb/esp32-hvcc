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
  static void cSend_wvy3ViaO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hdGINO35_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Kv2waxQh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gcW4SRhp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_juDwxlsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_QtLbKjQ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_FFp0nRVk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CxRQ3Rlv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mMMt7JVp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bvjyNWsL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_idnPgxj8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Ww3mnnWh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2g67miuU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_RkJfItTA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_X46VN6qF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NB2DmjkS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_u9SN3ZoH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qJMI17QN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mvlyuarM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Alx7dkZL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UwUCgFkj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OaIkVLHf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZqfFUxNx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_W2ctTK4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5z4RGJ75_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_qtQ5Gc0o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_OCQrl1gm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tJbDVXRI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSend_rLN2BF00_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KZrIxJtA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BL4SvWFg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0Yf3Ygp2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i9L3JheL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_XArkK61y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_pRorYrVx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_xcFWQSXX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zgXK3FQp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_W95rOWXQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_lT7D6f1t;
  SignalPhasor sPhasor_PBly4Euo;
  ControlBinop cBinop_Kv2waxQh;
  SignalVarf sVarf_Tl4rTviu;
  ControlBinop cBinop_CxRQ3Rlv;
  ControlVar cVar_NB2DmjkS;
  ControlVar cVar_Alx7dkZL;
  ControlIf cIf_W2ctTK4F;
  ControlBinop cBinop_5z4RGJ75;
  ControlSlice cSlice_qtQ5Gc0o;
  ControlSlice cSlice_OCQrl1gm;
  ControlBinop cBinop_KZrIxJtA;
  SignalVarf sVarf_ifj8kgec;
  SignalVarf sVarf_Twt6dcce;
  ControlVar cVar_BL4SvWFg;
  ControlBinop cBinop_i9L3JheL;
  SignalVarf sVarf_A54cQKoh;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
