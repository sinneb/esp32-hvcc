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
#include "HvTable.h"
#include "HvSignalSample.h"
#include "HvControlIf.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvControlTabread.h"
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
  static void cBinop_hYAGX5ta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m0w44wfL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qhwLawzI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_39L0Frn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_SHXAxYYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bQ2PeKfD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pwa5gXFb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i0KPql4L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_yLEVFn9l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_EXjjhOUG_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_uKRhG7i8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eQ5Um9vt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_w5p9WiDP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_A6vXLkxJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sR8Mslas_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_YARphFsz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZWPijH8j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HpQiAO6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XKU1ICT9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_BE6zeSTY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WKY2M694_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XkwL4gTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wNSNYWjA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_er9z6dyw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vjRXWVeO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_BTqMoW5G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HXHWTrtW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JPZzpqTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G68vIWES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_a2VewrLU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_n0knTPCr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_huwKzNMD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BEhSUh5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tUJvsYfU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_u2pSCHyZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VCaWDLLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5E0wXPMr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_j2Lehmkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YPlmIaep_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qZ4jRhJ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aJ4a6c8P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cp4z6sFW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_2G9PEAyJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0gS9nyUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_jtLGNKQV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nDHRpk56_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_yFluBDy8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_bmTwezs5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bEEdaF0Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b7V81I9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yHLvGIoZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_3zulMTTy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_e4aLBZDI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_onkoZMuJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_BG4jHUFt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Kt1DdBYA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JIUZdoEw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZNLr6RRn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FjuvuaCn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_u9ks6H89_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TV5uaiSn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_30j7ybGF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qYNF4zpF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sSample_w9Z2vJeY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Dc5WqO3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JbgWad2t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_zEWmLLPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_lv9Wp9J3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GMdWvw1M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_De5dBBw8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b7KBHYiA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_njTFFfZm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_SfLOg7Vw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_j9SdnxxB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_NgWfTRYA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_oeo56Cd1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nlny4Wgo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mDF56h3p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TCvZ9Pfp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cynCizVw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_YC8wjkdl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LmRI8rSk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kr1GE1kF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lJ73CqWl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aEJLQngy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_GVsIB7R9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VNs9opFv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AAOMu1IP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jgtpVKz1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_JjczlcSk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mA9H9j9V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KzsvUQAf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_gST9XWpf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KmCDYq2O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Naa2ewIw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_HyupRMo9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0aJXUHPj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Qv6S3Een_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_buEKc6AO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ciKD05lf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RbrBJG8p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YlSKJIHB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UXv0S6UH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_EzeFC6Ms_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Rt5TPvWz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8qTmhtDQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fgQ0bdYP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KMzdqxmZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_2ggFVgNB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_QOIZkHm2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G6rRe6n4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GoYHUhJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vOcH8IzQ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_uympht4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qxpNzXZq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nzf8hHt2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_jg3ruYgh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_i8AALTRb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J4j8wzUB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5jDqlBe4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lUatANXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zE6MlffF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xPIc9MfH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_01eci0fv_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_lUCchBEk;
  SignalPhasor sPhasor_EQN3uYxY;
  SignalSample sSample_w9Z2vJeY;
  SignalPhasor sPhasor_qPyrN5PU;
  SignalPhasor sPhasor_26rS4I4Z;
  SignalPhasor sPhasor_ceL5jQIX;
  ControlBinop cBinop_hYAGX5ta;
  ControlVar cVar_qhwLawzI;
  ControlBinop cBinop_bQ2PeKfD;
  ControlBinop cBinop_Pwa5gXFb;
  ControlBinop cBinop_i0KPql4L;
  ControlDelay cDelay_yLEVFn9l;
  ControlVar cVar_w5p9WiDP;
  ControlVar cVar_A6vXLkxJ;
  ControlVar cVar_ZWPijH8j;
  HvTable hTable_BE6zeSTY;
  ControlVar cVar_wNSNYWjA;
  ControlVar cVar_vjRXWVeO;
  ControlTabread cTabread_BTqMoW5G;
  ControlBinop cBinop_HXHWTrtW;
  ControlBinop cBinop_G68vIWES;
  ControlSlice cSlice_a2VewrLU;
  ControlVar cVar_u2pSCHyZ;
  ControlBinop cBinop_VCaWDLLH;
  ControlVar cVar_j2Lehmkv;
  ControlBinop cBinop_YPlmIaep;
  SignalVarf sVarf_CLHUJnQA;
  SignalVarf sVarf_aokhutTT;
  ControlVar cVar_FjuvuaCn;
  ControlBinop cBinop_30j7ybGF;
  ControlVar cVar_qYNF4zpF;
  SignalVarf sVarf_L6N9DfTE;
  SignalVarf sVarf_Zx9qE7mS;
  ControlIf cIf_njTFFfZm;
  ControlVar cVar_nlny4Wgo;
  ControlBinop cBinop_mDF56h3p;
  ControlBinop cBinop_TCvZ9Pfp;
  ControlVar cVar_YC8wjkdl;
  ControlBinop cBinop_lJ73CqWl;
  ControlBinop cBinop_aEJLQngy;
  ControlDelay cDelay_GVsIB7R9;
  ControlIf cIf_JjczlcSk;
  ControlVar cVar_KzsvUQAf;
  ControlVar cVar_Naa2ewIw;
  ControlIf cIf_Qv6S3Een;
  ControlBinop cBinop_RbrBJG8p;
  SignalVarf sVarf_PlEreoAL;
  ControlBinop cBinop_YlSKJIHB;
  SignalVarf sVarf_C99Zxz2c;
  SignalVarf sVarf_fIVBka7d;
  ControlIf cIf_2ggFVgNB;
  ControlVar cVar_G6rRe6n4;
  ControlBinop cBinop_qxpNzXZq;
  ControlBinop cBinop_nzf8hHt2;
  ControlBinop cBinop_J4j8wzUB;
  ControlVar cVar_lUatANXJ;
  ControlDelay cDelay_zE6MlffF;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
