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
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
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
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        METROBANG = 0xFB81D83A, // metrobang
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cMsg_iNnlqfUr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iwYxfyaC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_mRrTD102_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kwkPqMkq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_6SbOg8rf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_URhH3eGC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_PryA2evj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0E5vJFtX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8GufeVIO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RXWFEyRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_wNcy31Pd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VJldKZ0C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xAJxXvqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZeC1KTqx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PoFoGAFP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_5coFS8aq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LEUGDlid_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tx65gBlZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D0Ixmn7F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NCme0Dva_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_yTWyTEYR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zNEGQLFa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8n83OrqD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_UDJzioX1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bW407dBt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_mONf8MAY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FIb0fa4E_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_gpCOrvuc;
  SignalPhasor sPhasor_XbIzqV3L;
  SignalPhasor sPhasor_RfMpZOFm;
  SignalPhasor sPhasor_31DsCUo0;
  ControlDelay cDelay_mRrTD102;
  SignalVarf sVarf_rkcPcpN9;
  ControlBinop cBinop_xAJxXvqL;
  ControlBinop cBinop_ZeC1KTqx;
  ControlDelay cDelay_5coFS8aq;
  ControlBinop cBinop_D0Ixmn7F;
  ControlVar cVar_NCme0Dva;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
