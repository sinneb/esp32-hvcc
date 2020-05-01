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
#include "HvControlRandom.h"
#include "HvControlTabread.h"
#include "HvMath.h"
#include "HvControlUnop.h"
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
  static void cBinop_sgEIhNXB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VzpX1Vvn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_gUVS6kAj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_f4zkSt41_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_90OdYTK5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yOWIJGxU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_MiAnOBKS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7kX1Bh4E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JR1P8D8b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_E64E6Ixh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KNIzVYsF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_D877mNZD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_BHDL4UH3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HoOydShw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_5ydw6ptT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rrhq6K3X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VuRkv6Zt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RMTzN0Nv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UN6xebQC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sCpjz4aw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3pNYXuDq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KD5GFXcv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_67HQv9nG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_29Xh4yfC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Nj8ju9vW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cGg6Kphy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_IzlouvIe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_01CVVBN7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_epyP7Fpm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_4XDblGHz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kyr9z3Sw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_YDY2VoMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FHU1cFWK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2imfZCuE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_2MoydEYE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JMbiAzfe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_csy1VEUo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Z4jFO3r9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DSB3Jhht_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nCTvO5D4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0R4FhLcU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_o0dWVIPl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rJTrQ7FR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wpe57UUG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MfSQmmB0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q2dmXa7o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_K1prLupm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kujPbtD5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8jTj2oDK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TOk1h9QK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nN5i0Nto_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O1npxGN1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fiaZQ7ag_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_RjDHZpbO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dkzgfEuo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSend_mPFAwhmN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_qRsoLu3H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_v4TVSyrT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tpdGnhon_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sSample_1TDnHgJy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rEue0CWN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OVYErndF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8pEECm6L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_pQBBMaTB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gYIlHD0j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wyxB5TIC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_pGhPijhm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_4nf7F1Bk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_uE13QPBN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6CYMAGSS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Rhk8bSXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8ZyVc9v2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d6bfuMA2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GCgSjhK4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UmzCDqAK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z2lS5CER_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PhYbit30_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_53dgMucR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pXO0RcCE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7ysnh75l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JruIg8mx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ogVIK9eC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0YAYHVyd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8OUJzSIa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabread_Fk42RMHe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vhirPLXA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_izi9znzm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_jDVIzQnu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2Fd7Esq9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0nqsrGxs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SixzFIvH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_JMpCGe0S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NEzXlX4C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HTknxZIx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xYN23ALC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8PUwprvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_z9vthNKh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rZyqhtIY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eZbR5CcU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YYJUeJ0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_4pORzTmm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Eln2PENt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rRIpTQ5G_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_bnRYQaJ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_PHjtYt8K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_BJk2GNzr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1IQw0wam_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wAlRXpfo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_yMUoYWeP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1fXarSaW_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalSample sSample_1TDnHgJy;
  SignalPhasor sPhasor_WiQNeTNT;
  ControlBinop cBinop_sgEIhNXB;
  ControlBinop cBinop_yOWIJGxU;
  ControlVar cVar_KNIzVYsF;
  SignalVarf sVarf_GZfsy7fk;
  ControlVar cVar_HoOydShw;
  ControlBinop cBinop_VuRkv6Zt;
  ControlBinop cBinop_sCpjz4aw;
  ControlVar cVar_3pNYXuDq;
  ControlBinop cBinop_KD5GFXcv;
  ControlDelay cDelay_Nj8ju9vW;
  ControlSlice cSlice_epyP7Fpm;
  ControlRandom cRandom_4XDblGHz;
  ControlBinop cBinop_kyr9z3Sw;
  ControlVar cVar_FHU1cFWK;
  ControlBinop cBinop_2imfZCuE;
  ControlTabread cTabread_2MoydEYE;
  ControlSlice cSlice_JMbiAzfe;
  ControlBinop cBinop_Z4jFO3r9;
  ControlVar cVar_DSB3Jhht;
  ControlBinop cBinop_nCTvO5D4;
  ControlIf cIf_K1prLupm;
  ControlBinop cBinop_kujPbtD5;
  ControlVar cVar_nN5i0Nto;
  ControlSlice cSlice_fiaZQ7ag;
  ControlSlice cSlice_RjDHZpbO;
  ControlVar cVar_v4TVSyrT;
  ControlVar cVar_tpdGnhon;
  ControlVar cVar_OVYErndF;
  HvTable hTable_pQBBMaTB;
  ControlVar cVar_gYIlHD0j;
  ControlVar cVar_wyxB5TIC;
  ControlDelay cDelay_4nf7F1Bk;
  ControlVar cVar_Rhk8bSXJ;
  ControlBinop cBinop_8ZyVc9v2;
  ControlBinop cBinop_d6bfuMA2;
  ControlBinop cBinop_z2lS5CER;
  ControlBinop cBinop_7ysnh75l;
  ControlBinop cBinop_0YAYHVyd;
  ControlBinop cBinop_8OUJzSIa;
  ControlTabread cTabread_Fk42RMHe;
  ControlVar cVar_vhirPLXA;
  ControlSlice cSlice_jDVIzQnu;
  ControlDelay cDelay_JMpCGe0S;
  ControlBinop cBinop_NEzXlX4C;
  ControlBinop cBinop_xYN23ALC;
  ControlBinop cBinop_8PUwprvE;
  ControlVar cVar_z9vthNKh;
  HvTable hTable_4pORzTmm;
  ControlSlice cSlice_Eln2PENt;
  ControlBinop cBinop_bnRYQaJ9;
  ControlRandom cRandom_PHjtYt8K;
  ControlVar cVar_1IQw0wam;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
