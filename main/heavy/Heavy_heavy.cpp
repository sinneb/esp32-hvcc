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

#include "Heavy_heavy.hpp"

#define Context(_c) reinterpret_cast<Heavy_heavy *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_heavy_new(double sampleRate) {
    return new Heavy_heavy(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_heavy_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_heavy(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_gTb2dZ1A, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_yReEsNB0);
  numBytes += sRPole_init(&sRPole_FanzNNhb);
  numBytes += sDel1_init(&sDel1_h0QHCRfA);
  numBytes += sPhasor_k_init(&sPhasor_TvwNUrHY, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_RKFyT8n6);
  numBytes += sTabhead_init(&sTabhead_T99tlsC6, &hTable_vRHrFU5Q);
  numBytes += sTabread_init(&sTabread_G5aI4OgP, &hTable_vRHrFU5Q, false);
  numBytes += sTabread_init(&sTabread_gDfj7nwD, &hTable_vRHrFU5Q, false);
  numBytes += sRPole_init(&sRPole_L6dy5FYM);
  numBytes += sDel1_init(&sDel1_plTtF99d);
  numBytes += sLine_init(&sLine_069oWWYu);
  numBytes += sTabwrite_init(&sTabwrite_OfWpnTjZ, &hTable_vRHrFU5Q);
  numBytes += cVar_init_f(&cVar_H52Tq4TS, 0.0f);
  numBytes += cVar_init_f(&cVar_bFNc1MMz, 0.0f);
  numBytes += cVar_init_f(&cVar_GUMP3idJ, 0.0f);
  numBytes += cVar_init_f(&cVar_1LjYCFSR, 0.0f);
  numBytes += cIf_init(&cIf_WokhNE4C, false);
  numBytes += cSlice_init(&cSlice_YOmHeFNM, 1, -1);
  numBytes += cSlice_init(&cSlice_zf51i22T, 1, -1);
  numBytes += cBinop_init(&cBinop_UQUuc1gK, 0.0f); // __neq
  numBytes += sVarf_init(&sVarf_JHolM1EC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_m6J9OFVA, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_IKhaM7hd, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_LNGC6SJH, 10.0f);
  numBytes += cDelay_init(this, &cDelay_PqlYxYoA, 0.0f);
  numBytes += hTable_init(&hTable_vRHrFU5Q, 256);
  numBytes += cDelay_init(this, &cDelay_PmWNSj0N, 0.0f);
  numBytes += cBinop_init(&cBinop_7Re0kUy5, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_X0okIWcK, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_CB8pISSz, 5.0f);
  numBytes += sVarf_init(&sVarf_MGbLUjXT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pGtnOkqG, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wECoytgD, 0.0f);
  numBytes += cSlice_init(&cSlice_0hAmoMd4, 1, -1);
  numBytes += cSlice_init(&cSlice_H6yMBgkv, 1, -1);
  numBytes += cIf_init(&cIf_LfWlkyT3, false);
  numBytes += cBinop_init(&cBinop_0jjTpGT5, 0.0f); // __neq
  numBytes += sVarf_init(&sVarf_hVWmYCOh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jS1GXMe6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dsMSmhAk, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ogFWk1YO, "del-G03-del");
  numBytes += cVar_init_f(&cVar_jdQHbsKY, 0.0f);
  numBytes += cPack_init(&cPack_CaAuxBGq, 2, 0.0f, 100.0f);
  numBytes += cVar_init_f(&cVar_AngU5rwl, 0.0f);
  numBytes += cVar_init_f(&cVar_eFTZHRHG, 0.0f);
  numBytes += cVar_init_f(&cVar_1MbzftDs, 0.0f);
  numBytes += cBinop_init(&cBinop_DAaIybJu, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_2Ex6fGYj, 1, -1);
  numBytes += cSlice_init(&cSlice_6dyRzZv3, 1, -1);
  numBytes += cIf_init(&cIf_tAzeUxyL, false);
  numBytes += cSlice_init(&cSlice_XWOgQky5, 1, -1);
  numBytes += cSlice_init(&cSlice_nJrfDBID, 1, -1);
  numBytes += cIf_init(&cIf_rPAF66b9, false);
  numBytes += cBinop_init(&cBinop_Sj2JdKQO, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_VQNlVVfE, 0.0f);
  numBytes += cPack_init(&cPack_wZHf0FIE, 2, 0.0f, 100.0f);
  numBytes += cPack_init(&cPack_vDpyVzVn, 2, 0.0f, 100.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_vRHrFU5Q);
  cPack_free(&cPack_CaAuxBGq);
  cPack_free(&cPack_wZHf0FIE);
  cPack_free(&cPack_vDpyVzVn);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x2FB8730C: return &hTable_vRHrFU5Q; // del-G03-del
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qahHqBfi_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6tpUKvur_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_r8LFz4cR_sendMessage);
      break;
    }
    case 0x125109EA: { // pot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GsCVZt7l_sendMessage);
      break;
    }
    case 0x73BEE661: { // pot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_49GDr3FR_sendMessage);
      break;
    }
    case 0xF2BC7D02: { // pot5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EZKBlcvz_sendMessage);
      break;
    }
    case 0x995F2576: { // thepot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QMeuhfKM_sendMessage);
      break;
    }
    case 0x9F988EB1: { // thepot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dAXs5f1x_sendMessage);
      break;
    }
    case 0x8D3FD8C7: { // thepot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_srKUNg7Y_sendMessage);
      break;
    }
    case 0xC4199C02: { // thepot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ReEbaOdC_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "pot5";
        info->hash = 0xF2BC7D02;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 4096.0f;
        info->defaultVal = 2048.0f;
        break;
      }
      case 1: {
        info->name = "pot4";
        info->hash = 0x73BEE661;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 4096.0f;
        info->defaultVal = 2048.0f;
        break;
      }
      case 2: {
        info->name = "pot3";
        info->hash = 0x125109EA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 4096.0f;
        info->defaultVal = 2048.0f;
        break;
      }
      case 3: {
        info->name = "pot2";
        info->hash = 0xDDC4EBDB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 4096.0f;
        info->defaultVal = 2048.0f;
        break;
      }
      case 4: {
        info->name = "pot1";
        info->hash = 0x3AE704A5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 4096.0f;
        info->defaultVal = 2048.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 5;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cMsg_fDP8dyRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bFNc1MMz, 0, m, &cVar_bFNc1MMz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H52Tq4TS, 0, m, &cVar_H52Tq4TS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eFTZHRHG, 0, m, &cVar_eFTZHRHG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jdQHbsKY, 0, m, &cVar_jdQHbsKY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AngU5rwl, 0, m, &cVar_AngU5rwl_sendMessage);
}

void Heavy_heavy::cReceive_ReEbaOdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AngU5rwl, 0, m, &cVar_AngU5rwl_sendMessage);
}

void Heavy_heavy::cBinop_GVb0eHeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CaAuxBGq, 0, m, &cPack_CaAuxBGq_sendMessage);
}

void Heavy_heavy::cSend_WiyT8auR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_ajBIs93T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cReceive_r8LFz4cR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_paZF676h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_49GDr3FR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0jOKGPtA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_H52Tq4TS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_GVb0eHeW_sendMessage);
}

void Heavy_heavy::cSend_V7dmY6Ak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cVar_bFNc1MMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_XBNXOd3d_sendMessage);
}

void Heavy_heavy::cBinop_iMc7M3dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WiyT8auR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_GUMP3idJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2048.0f, 0, m, &cBinop_0d6kUsmq_sendMessage);
}

void Heavy_heavy::cSend_XO0cIPvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dAXs5f1x_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_pbc7ualj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cSend_lzV1YRpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cBinop_0d6kUsmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iMc7M3dr_sendMessage);
}

void Heavy_heavy::cReceive_srKUNg7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eFTZHRHG, 0, m, &cVar_eFTZHRHG_sendMessage);
}

void Heavy_heavy::cReceive_6tpUKvur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VbslN1Ws_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_IsvpieJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 512.0f);
  cSend_V7dmY6Ak_sendMessage(_c, 0, m);
  cSend_lzV1YRpx_sendMessage(_c, 0, m);
  cSend_34IqIBXn_sendMessage(_c, 0, m);
  cSend_Va69F9ew_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_1LjYCFSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_yLEttjkg_sendMessage);
  cSend_tpaZO3yW_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_WokhNE4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5WxrNw8V_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j6H8Yf1I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_YOmHeFNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UQUuc1gK, HV_BINOP_NEQ, 1, m, &cBinop_UQUuc1gK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_1LjYCFSR, 1, m, &cVar_1LjYCFSR_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UQUuc1gK, HV_BINOP_NEQ, 1, m, &cBinop_UQUuc1gK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_1LjYCFSR, 1, m, &cVar_1LjYCFSR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_D4tmyq6v_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zf51i22T, 0, m, &cSlice_zf51i22T_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YOmHeFNM, 0, m, &cSlice_YOmHeFNM_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_joyJpDyr_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9LZuje4s_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_zf51i22T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_1LjYCFSR, 0, m, &cVar_1LjYCFSR_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_1LjYCFSR, 0, m, &cVar_1LjYCFSR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_5WxrNw8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQUuc1gK, HV_BINOP_NEQ, 1, m, &cBinop_UQUuc1gK_sendMessage);
}

void Heavy_heavy::cCast_9LZuje4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WokhNE4C, 0, m, &cIf_WokhNE4C_sendMessage);
}

void Heavy_heavy::cCast_joyJpDyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQUuc1gK, HV_BINOP_NEQ, 0, m, &cBinop_UQUuc1gK_sendMessage);
}

void Heavy_heavy::cBinop_UQUuc1gK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WokhNE4C, 1, m, &cIf_WokhNE4C_sendMessage);
}

void Heavy_heavy::cCast_j6H8Yf1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1LjYCFSR, 0, m, &cVar_1LjYCFSR_sendMessage);
}

void Heavy_heavy::cMsg_Dq5BcH2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Vg4U11Nn_sendMessage);
}

void Heavy_heavy::cBinop_IKhaM7hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dq5BcH2u_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_UESU9lbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_F89of5si_sendMessage);
}

void Heavy_heavy::cBinop_Vg4U11Nn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nyXG92Qc_sendMessage);
}

void Heavy_heavy::cBinop_F89of5si_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_m6J9OFVA, m);
}

void Heavy_heavy::cSystem_keJmLBCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKhaM7hd, HV_BINOP_DIVIDE, 1, m, &cBinop_IKhaM7hd_sendMessage);
}

void Heavy_heavy::cMsg_pVSYmC4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_keJmLBCQ_sendMessage);
}

void Heavy_heavy::cBinop_XvGFehm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_VczrM4Pp_sendMessage);
}

void Heavy_heavy::cVar_LNGC6SJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XvGFehm3_sendMessage);
}

void Heavy_heavy::cBinop_k98BXbjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JHolM1EC, m);
}

void Heavy_heavy::cBinop_VczrM4Pp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IKhaM7hd, HV_BINOP_DIVIDE, 0, m, &cBinop_IKhaM7hd_sendMessage);
}

void Heavy_heavy::cBinop_CNioqRHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UESU9lbv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k98BXbjL_sendMessage);
}

void Heavy_heavy::cBinop_nyXG92Qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CNioqRHY_sendMessage);
}

void Heavy_heavy::cDelay_PqlYxYoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PqlYxYoA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PmWNSj0N, 0, m, &cDelay_PmWNSj0N_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqlYxYoA, 0, m, &cDelay_PqlYxYoA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_OfWpnTjZ, 1, m, NULL);
}

void Heavy_heavy::cMsg_d25Y6hwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_vRHrFU5Q, 0, m, &hTable_vRHrFU5Q_sendMessage);
}

void Heavy_heavy::cMsg_OrGyZ527_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_vRHrFU5Q, 0, m, &hTable_vRHrFU5Q_sendMessage);
}

void Heavy_heavy::cCast_I3nm0vet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqlYxYoA, 0, m, &cDelay_PqlYxYoA_sendMessage);
}

void Heavy_heavy::hTable_vRHrFU5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hJOy5sum_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqlYxYoA, 2, m, &cDelay_PqlYxYoA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I3nm0vet_sendMessage);
}

void Heavy_heavy::cBinop_BU4GH4ZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d25Y6hwu_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_BMjnp5wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_w1PUg8ej_sendMessage);
}

void Heavy_heavy::cMsg_VQKQdaab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BMjnp5wp_sendMessage);
}

void Heavy_heavy::cMsg_hJOy5sum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PmWNSj0N, 2, m, &cDelay_PmWNSj0N_sendMessage);
}

void Heavy_heavy::cDelay_PmWNSj0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PmWNSj0N, m);
  cMsg_OrGyZ527_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_w1PUg8ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_BU4GH4ZJ_sendMessage);
}

void Heavy_heavy::cReceive_EZKBlcvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2048.0f, 0, m, &cBinop_0d6kUsmq_sendMessage);
}

void Heavy_heavy::cSend_JzbeCube_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_srKUNg7Y_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_ZxBSxwvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Re0kUy5, HV_BINOP_POW, 0, m, &cBinop_7Re0kUy5_sendMessage);
}

void Heavy_heavy::cBinop_7Re0kUy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_MROMrFYz_sendMessage);
}

void Heavy_heavy::cBinop_dHZEYTrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Re0kUy5, HV_BINOP_POW, 1, m, &cBinop_7Re0kUy5_sendMessage);
  cMsg_ZxBSxwvV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_XBNXOd3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_dHZEYTrI_sendMessage);
}

void Heavy_heavy::cBinop_MROMrFYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ibgCIx2G_sendMessage);
}

void Heavy_heavy::cSend_34IqIBXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cBinop_mYSUQxxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QXdNTVHi_sendMessage);
}

void Heavy_heavy::cBinop_QXdNTVHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_17p1JjWZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_L8ORePpG_sendMessage);
}

void Heavy_heavy::cBinop_X0okIWcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fAJnJvmf_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_sF1uCgci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_4YAfxBqr_sendMessage);
}

void Heavy_heavy::cMsg_fAJnJvmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_VRSeZCsX_sendMessage);
}

void Heavy_heavy::cBinop_17p1JjWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_XynIlP1B_sendMessage);
}

void Heavy_heavy::cBinop_XynIlP1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pGtnOkqG, m);
}

void Heavy_heavy::cVar_CB8pISSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_sF1uCgci_sendMessage);
}

void Heavy_heavy::cSystem_3IX6edbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X0okIWcK, HV_BINOP_DIVIDE, 1, m, &cBinop_X0okIWcK_sendMessage);
}

void Heavy_heavy::cMsg_atNvLoHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3IX6edbW_sendMessage);
}

void Heavy_heavy::cBinop_VRSeZCsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mYSUQxxb_sendMessage);
}

void Heavy_heavy::cBinop_4YAfxBqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X0okIWcK, HV_BINOP_DIVIDE, 0, m, &cBinop_X0okIWcK_sendMessage);
}

void Heavy_heavy::cBinop_L8ORePpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MGbLUjXT, m);
}

void Heavy_heavy::cSend_vBQkvAhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cSend_OhUFSQE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QMeuhfKM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_dAXs5f1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H52Tq4TS, 0, m, &cVar_H52Tq4TS_sendMessage);
}

void Heavy_heavy::cReceive_QMeuhfKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bFNc1MMz, 0, m, &cVar_bFNc1MMz_sendMessage);
}

void Heavy_heavy::cCast_K6ZSZDI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jjTpGT5, HV_BINOP_NEQ, 0, m, &cBinop_0jjTpGT5_sendMessage);
}

void Heavy_heavy::cVar_wECoytgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_2w4R9ypn_sendMessage);
  cSend_pbc7ualj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_lmSWU9Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0jjTpGT5, HV_BINOP_NEQ, 1, m, &cBinop_0jjTpGT5_sendMessage);
}

void Heavy_heavy::cCast_uUZC4NaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LfWlkyT3, 0, m, &cIf_LfWlkyT3_sendMessage);
}

void Heavy_heavy::cSlice_0hAmoMd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0jjTpGT5, HV_BINOP_NEQ, 1, m, &cBinop_0jjTpGT5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_wECoytgD, 1, m, &cVar_wECoytgD_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0jjTpGT5, HV_BINOP_NEQ, 1, m, &cBinop_0jjTpGT5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_wECoytgD, 1, m, &cVar_wECoytgD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_paZF676h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_H6yMBgkv, 0, m, &cSlice_H6yMBgkv_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0hAmoMd4, 0, m, &cSlice_0hAmoMd4_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K6ZSZDI6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uUZC4NaA_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_H6yMBgkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_wECoytgD, 0, m, &cVar_wECoytgD_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_wECoytgD, 0, m, &cVar_wECoytgD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_ao7wlyDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wECoytgD, 0, m, &cVar_wECoytgD_sendMessage);
}

void Heavy_heavy::cIf_LfWlkyT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lmSWU9Bs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ao7wlyDD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_0jjTpGT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LfWlkyT3, 1, m, &cIf_LfWlkyT3_sendMessage);
}

void Heavy_heavy::cReceive_GsCVZt7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_D4tmyq6v_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_vWUZY34O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ReEbaOdC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_jsqTu3OP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6WZJVf39_sendMessage);
}

void Heavy_heavy::cMsg_Ce7vsNTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jsqTu3OP_sendMessage);
}

void Heavy_heavy::cSystem_eq6fngdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3lmPUzZC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dsMSmhAk, m);
}

void Heavy_heavy::cBinop_3lmPUzZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hVWmYCOh, m);
}

void Heavy_heavy::cMsg_mBLq9gud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eq6fngdZ_sendMessage);
}

void Heavy_heavy::cVar_ogFWk1YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mBLq9gud_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_6WZJVf39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jS1GXMe6, m);
}

void Heavy_heavy::cVar_jdQHbsKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vDpyVzVn, 0, m, &cPack_vDpyVzVn_sendMessage);
}

void Heavy_heavy::cPack_CaAuxBGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yReEsNB0, 0, m, NULL);
}

void Heavy_heavy::cVar_AngU5rwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.01f, 0, m, &cBinop_zQRlU8sN_sendMessage);
}

void Heavy_heavy::cVar_eFTZHRHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_6maw4c3B_sendMessage);
}

void Heavy_heavy::cBinop_ibgCIx2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_gTb2dZ1A, 0, m);
}

void Heavy_heavy::cSend_Va69F9ew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cCast_Gj28nA7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1MbzftDs, 0, m, &cVar_1MbzftDs_sendMessage);
}

void Heavy_heavy::cVar_1MbzftDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_elIBsHOV_sendMessage);
  cSend_vBQkvAhd_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_DwasCzZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAaIybJu, HV_BINOP_NEQ, 1, m, &cBinop_DAaIybJu_sendMessage);
}

void Heavy_heavy::cBinop_DAaIybJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tAzeUxyL, 1, m, &cIf_tAzeUxyL_sendMessage);
}

void Heavy_heavy::cCast_tZT1C9lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tAzeUxyL, 0, m, &cIf_tAzeUxyL_sendMessage);
}

void Heavy_heavy::cSlice_2Ex6fGYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DAaIybJu, HV_BINOP_NEQ, 1, m, &cBinop_DAaIybJu_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_1MbzftDs, 1, m, &cVar_1MbzftDs_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_DAaIybJu, HV_BINOP_NEQ, 1, m, &cBinop_DAaIybJu_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_1MbzftDs, 1, m, &cVar_1MbzftDs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_6dyRzZv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_1MbzftDs, 0, m, &cVar_1MbzftDs_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_1MbzftDs, 0, m, &cVar_1MbzftDs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_VbslN1Ws_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6dyRzZv3, 0, m, &cSlice_6dyRzZv3_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2Ex6fGYj, 0, m, &cSlice_2Ex6fGYj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9IiQR3o7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tZT1C9lp_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_9IiQR3o7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAaIybJu, HV_BINOP_NEQ, 0, m, &cBinop_DAaIybJu_sendMessage);
}

void Heavy_heavy::cIf_tAzeUxyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DwasCzZD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Gj28nA7l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_6maw4c3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TvwNUrHY, 0, m);
}

void Heavy_heavy::cBinop_qcEh3JSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vWUZY34O_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_elIBsHOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OhUFSQE8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSlice_XWOgQky5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Sj2JdKQO, HV_BINOP_NEQ, 1, m, &cBinop_Sj2JdKQO_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_VQNlVVfE, 1, m, &cVar_VQNlVVfE_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Sj2JdKQO, HV_BINOP_NEQ, 1, m, &cBinop_Sj2JdKQO_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_VQNlVVfE, 1, m, &cVar_VQNlVVfE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_nJrfDBID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_VQNlVVfE, 0, m, &cVar_VQNlVVfE_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_VQNlVVfE, 0, m, &cVar_VQNlVVfE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_0jOKGPtA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nJrfDBID, 0, m, &cSlice_nJrfDBID_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XWOgQky5, 0, m, &cSlice_XWOgQky5_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AQZhbdBu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q46DlV8t_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cIf_rPAF66b9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8EyjwUPP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fMdKgXwv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_q46DlV8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rPAF66b9, 0, m, &cIf_rPAF66b9_sendMessage);
}

void Heavy_heavy::cCast_fMdKgXwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VQNlVVfE, 0, m, &cVar_VQNlVVfE_sendMessage);
}

void Heavy_heavy::cCast_AQZhbdBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sj2JdKQO, HV_BINOP_NEQ, 0, m, &cBinop_Sj2JdKQO_sendMessage);
}

void Heavy_heavy::cBinop_Sj2JdKQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rPAF66b9, 1, m, &cIf_rPAF66b9_sendMessage);
}

void Heavy_heavy::cCast_8EyjwUPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sj2JdKQO, HV_BINOP_NEQ, 1, m, &cBinop_Sj2JdKQO_sendMessage);
}

void Heavy_heavy::cVar_VQNlVVfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_qcEh3JSr_sendMessage);
  cSend_ajBIs93T_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_2w4R9ypn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XO0cIPvr_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_zQRlU8sN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wZHf0FIE, 0, m, &cPack_wZHf0FIE_sendMessage);
}

void Heavy_heavy::cPack_wZHf0FIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_069oWWYu, 0, m, NULL);
}

void Heavy_heavy::cBinop_yLEttjkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JzbeCube_sendMessage(_c, 0, m);
}

void Heavy_heavy::cPack_vDpyVzVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RKFyT8n6, 0, m, NULL);
}

void Heavy_heavy::cSend_tpaZO3yW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cReceive_qahHqBfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pVSYmC4W_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LNGC6SJH, 0, m, &cVar_LNGC6SJH_sendMessage);
  cMsg_atNvLoHZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CB8pISSz, 0, m, &cVar_CB8pISSz_sendMessage);
  cMsg_VQKQdaab_sendMessage(_c, 0, m);
  cMsg_IsvpieJy_sendMessage(_c, 0, m);
  cMsg_fDP8dyRl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ogFWk1YO, 0, m, &cVar_ogFWk1YO_sendMessage);
  cMsg_Ce7vsNTL_sendMessage(_c, 0, m);
}




/*
 * Context Process Implementation
 */

int Heavy_heavy::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1, O2, O3;
  hv_bufferf_t I0, I1, I2, I3;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));
    __hv_load_f(inputBuffers[2]+n, VOf(I2));
    __hv_load_f(inputBuffers[3]+n, VOf(I3));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));
    __hv_zero_f(VOf(O2));
    __hv_zero_f(VOf(O3));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_gTb2dZ1A, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_yReEsNB0, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_JHolM1EC, VOf(Bf4));
    __hv_rpole_f(&sRPole_FanzNNhb, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_h0QHCRfA, VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_m6J9OFVA, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), -0.2f, -0.2f, -0.2f, -0.2f, -0.2f, -0.2f, -0.2f, -0.2f);
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_TvwNUrHY, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_RKFyT8n6, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.46f, 1.46f, 1.46f, 1.46f, 1.46f, 1.46f, 1.46f, 1.46f);
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_tabhead_f(&sTabhead_T99tlsC6, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_jS1GXMe6, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_hVWmYCOh, VOf(Bf2));
    __hv_min_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf0));
    __hv_varread_f(&sVarf_dsMSmhAk, VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_G5aI4OgP, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_gDfj7nwD, VIi(Bi0), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_MGbLUjXT, VOf(Bf4));
    __hv_rpole_f(&sRPole_L6dy5FYM, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_plTtF99d, VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_pGtnOkqG, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_069oWWYu, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_OfWpnTjZ, VIf(Bf2));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
    __hv_store_f(outputBuffers[2]+n, VIf(O2));
    __hv_store_f(outputBuffers[3]+n, VIf(O3));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_heavy::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 4 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(4*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);
  bIn[2] = inputBuffers+(2*n4);
  bIn[3] = inputBuffers+(3*n4);

  // define the heavy output buffer for 4 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(4*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);
  bOut[2] = outputBuffers+(2*n4);
  bOut[3] = outputBuffers+(3*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_heavy::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 4 channel(s), uninterleave
  float *const bIn = (float *) hv_alloca(4*n4*sizeof(float));
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+4*j];
    bIn[1*n4+j] = inputBuffers[1+4*j];
    bIn[2*n4+j] = inputBuffers[2+4*j];
    bIn[3*n4+j] = inputBuffers[3+4*j];
  }

  // define the heavy output buffer for 4 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(4*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  
  // interleave the heavy output into the output buffer
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+4*j] = bOut[i*n4+j];
    }
  }

  return n;
}
