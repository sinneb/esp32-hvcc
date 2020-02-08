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
#include "HvSignalSample.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_heavy : public HeavyContext {

 public:
  Heavy_heavy(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_heavy();

  const char *getName() override { return "heavy"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cMsg_3Ww0t2gT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dLEI7Sbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eElWBYUS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WpcT2Tc3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RbvPGFJD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sSample_moztMorH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_OUhTFsoy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_p0OGzheO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SOH0qkFO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rx5Ngyqr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VGFEivXU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kes0AwG8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_o86BsM7S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YxDG3UFj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4LertuLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aO3MXD9i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_osg1fn1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Vi5vkhtq;
  SignalPhasor sPhasor_sbmYKJhk;
  SignalPhasor sPhasor_JcOiZE8T;
  SignalPhasor sPhasor_3ivYEUkG;
  SignalPhasor sPhasor_XpDc28UB;
  SignalPhasor sPhasor_9FLH0HUN;
  SignalPhasor sPhasor_iuimobYp;
  SignalSample sSample_moztMorH;
  ControlBinop cBinop_dLEI7Sbo;
  ControlVar cVar_eElWBYUS;
  ControlVar cVar_RbvPGFJD;
  ControlDelay cDelay_p0OGzheO;
  ControlBinop cBinop_SOH0qkFO;
  ControlBinop cBinop_Rx5Ngyqr;
  ControlVar cVar_VGFEivXU;
  ControlBinop cBinop_aO3MXD9i;
  SignalVarf sVarf_p7OcXN67;
  SignalVarf sVarf_CfhVc5bZ;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
