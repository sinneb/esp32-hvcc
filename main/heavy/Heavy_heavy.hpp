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
#include "HvSignalTabwrite.h"
#include "HvTable.h"
#include "HvControlIf.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvSignalRPole.h"
#include "HvMath.h"
#include "HvControlPack.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_heavy : public HeavyContext {

 public:
  Heavy_heavy(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_heavy();

  const char *getName() override { return "heavy"; }
  int getNumInputChannels() override { return 4; }
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
  static void cMsg_fDP8dyRl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ReEbaOdC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GVb0eHeW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_WiyT8auR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_ajBIs93T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_r8LFz4cR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_49GDr3FR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H52Tq4TS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_V7dmY6Ak_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bFNc1MMz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iMc7M3dr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GUMP3idJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_XO0cIPvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_pbc7ualj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_lzV1YRpx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0d6kUsmq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_srKUNg7Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6tpUKvur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IsvpieJy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1LjYCFSR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_WokhNE4C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YOmHeFNM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_D4tmyq6v_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_zf51i22T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5WxrNw8V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9LZuje4s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_joyJpDyr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UQUuc1gK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j6H8Yf1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dq5BcH2u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IKhaM7hd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UESU9lbv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vg4U11Nn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F89of5si_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_keJmLBCQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pVSYmC4W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XvGFehm3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LNGC6SJH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k98BXbjL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VczrM4Pp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CNioqRHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nyXG92Qc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PqlYxYoA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d25Y6hwu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OrGyZ527_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_I3nm0vet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_vRHrFU5Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BU4GH4ZJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BMjnp5wp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VQKQdaab_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hJOy5sum_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PmWNSj0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w1PUg8ej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EZKBlcvz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JzbeCube_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZxBSxwvV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7Re0kUy5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dHZEYTrI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XBNXOd3d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MROMrFYz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_34IqIBXn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mYSUQxxb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QXdNTVHi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X0okIWcK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sF1uCgci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fAJnJvmf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_17p1JjWZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XynIlP1B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CB8pISSz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3IX6edbW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_atNvLoHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VRSeZCsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4YAfxBqr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L8ORePpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_vBQkvAhd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_OhUFSQE8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dAXs5f1x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QMeuhfKM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K6ZSZDI6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wECoytgD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lmSWU9Bs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uUZC4NaA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0hAmoMd4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_paZF676h_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_H6yMBgkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ao7wlyDD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_LfWlkyT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0jjTpGT5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GsCVZt7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_vWUZY34O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_jsqTu3OP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ce7vsNTL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eq6fngdZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3lmPUzZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mBLq9gud_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ogFWk1YO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6WZJVf39_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jdQHbsKY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_CaAuxBGq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AngU5rwl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eFTZHRHG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ibgCIx2G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Va69F9ew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Gj28nA7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1MbzftDs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DwasCzZD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DAaIybJu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tZT1C9lp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2Ex6fGYj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6dyRzZv3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_VbslN1Ws_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_9IiQR3o7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_tAzeUxyL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6maw4c3B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qcEh3JSr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_elIBsHOV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XWOgQky5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_nJrfDBID_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_0jOKGPtA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cIf_rPAF66b9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_q46DlV8t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fMdKgXwv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AQZhbdBu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Sj2JdKQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8EyjwUPP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VQNlVVfE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2w4R9ypn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zQRlU8sN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_wZHf0FIE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yLEttjkg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_vDpyVzVn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_tpaZO3yW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qahHqBfi_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_gTb2dZ1A;
  SignalLine sLine_yReEsNB0;
  SignalRPole sRPole_FanzNNhb;
  SignalDel1 sDel1_h0QHCRfA;
  SignalPhasor sPhasor_TvwNUrHY;
  SignalLine sLine_RKFyT8n6;
  SignalTabhead sTabhead_T99tlsC6;
  SignalTabread sTabread_G5aI4OgP;
  SignalTabread sTabread_gDfj7nwD;
  SignalRPole sRPole_L6dy5FYM;
  SignalDel1 sDel1_plTtF99d;
  SignalLine sLine_069oWWYu;
  SignalTabwrite sTabwrite_OfWpnTjZ;
  ControlBinop cBinop_GVb0eHeW;
  ControlVar cVar_H52Tq4TS;
  ControlVar cVar_bFNc1MMz;
  ControlBinop cBinop_iMc7M3dr;
  ControlVar cVar_GUMP3idJ;
  ControlBinop cBinop_0d6kUsmq;
  ControlVar cVar_1LjYCFSR;
  ControlIf cIf_WokhNE4C;
  ControlSlice cSlice_YOmHeFNM;
  ControlSlice cSlice_zf51i22T;
  ControlBinop cBinop_UQUuc1gK;
  SignalVarf sVarf_JHolM1EC;
  SignalVarf sVarf_m6J9OFVA;
  ControlBinop cBinop_IKhaM7hd;
  ControlBinop cBinop_UESU9lbv;
  ControlBinop cBinop_Vg4U11Nn;
  ControlBinop cBinop_F89of5si;
  ControlBinop cBinop_XvGFehm3;
  ControlVar cVar_LNGC6SJH;
  ControlBinop cBinop_k98BXbjL;
  ControlBinop cBinop_VczrM4Pp;
  ControlBinop cBinop_CNioqRHY;
  ControlBinop cBinop_nyXG92Qc;
  ControlDelay cDelay_PqlYxYoA;
  HvTable hTable_vRHrFU5Q;
  ControlBinop cBinop_BU4GH4ZJ;
  ControlDelay cDelay_PmWNSj0N;
  ControlBinop cBinop_w1PUg8ej;
  ControlBinop cBinop_7Re0kUy5;
  ControlBinop cBinop_dHZEYTrI;
  ControlBinop cBinop_XBNXOd3d;
  ControlBinop cBinop_MROMrFYz;
  ControlBinop cBinop_mYSUQxxb;
  ControlBinop cBinop_QXdNTVHi;
  ControlBinop cBinop_X0okIWcK;
  ControlBinop cBinop_sF1uCgci;
  ControlBinop cBinop_17p1JjWZ;
  ControlBinop cBinop_XynIlP1B;
  ControlVar cVar_CB8pISSz;
  SignalVarf sVarf_MGbLUjXT;
  ControlBinop cBinop_VRSeZCsX;
  ControlBinop cBinop_4YAfxBqr;
  SignalVarf sVarf_pGtnOkqG;
  ControlBinop cBinop_L8ORePpG;
  ControlVar cVar_wECoytgD;
  ControlSlice cSlice_0hAmoMd4;
  ControlSlice cSlice_H6yMBgkv;
  ControlIf cIf_LfWlkyT3;
  ControlBinop cBinop_0jjTpGT5;
  SignalVarf sVarf_hVWmYCOh;
  SignalVarf sVarf_jS1GXMe6;
  ControlBinop cBinop_3lmPUzZC;
  SignalVarf sVarf_dsMSmhAk;
  ControlVar cVar_ogFWk1YO;
  ControlBinop cBinop_6WZJVf39;
  ControlVar cVar_jdQHbsKY;
  ControlPack cPack_CaAuxBGq;
  ControlVar cVar_AngU5rwl;
  ControlVar cVar_eFTZHRHG;
  ControlBinop cBinop_ibgCIx2G;
  ControlVar cVar_1MbzftDs;
  ControlBinop cBinop_DAaIybJu;
  ControlSlice cSlice_2Ex6fGYj;
  ControlSlice cSlice_6dyRzZv3;
  ControlIf cIf_tAzeUxyL;
  ControlBinop cBinop_6maw4c3B;
  ControlBinop cBinop_qcEh3JSr;
  ControlBinop cBinop_elIBsHOV;
  ControlSlice cSlice_XWOgQky5;
  ControlSlice cSlice_nJrfDBID;
  ControlIf cIf_rPAF66b9;
  ControlBinop cBinop_Sj2JdKQO;
  ControlVar cVar_VQNlVVfE;
  ControlBinop cBinop_2w4R9ypn;
  ControlBinop cBinop_zQRlU8sN;
  ControlPack cPack_wZHf0FIE;
  ControlBinop cBinop_yLEttjkg;
  ControlPack cPack_vDpyVzVn;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
