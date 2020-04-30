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
  numBytes += sPhasor_k_init(&sPhasor_lUCchBEk, 55.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_EQN3uYxY, 0.1f, sampleRate);
  numBytes += sSample_init(&sSample_w9Z2vJeY);
  numBytes += sPhasor_k_init(&sPhasor_qPyrN5PU, 220.0f, sampleRate);
  numBytes += sPhasor_init(&sPhasor_26rS4I4Z, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_ceL5jQIX, 440.0f, sampleRate);
  numBytes += cVar_init_f(&cVar_qhwLawzI, 250.0f);
  numBytes += cBinop_init(&cBinop_i0KPql4L, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_yLEVFn9l, 0.0f);
  numBytes += cVar_init_f(&cVar_w5p9WiDP, 0.0f);
  numBytes += cVar_init_f(&cVar_A6vXLkxJ, 0.0f);
  numBytes += cVar_init_f(&cVar_ZWPijH8j, 0.0f);
  numBytes += hTable_init(&hTable_BE6zeSTY, 0);
  numBytes += cVar_init_f(&cVar_wNSNYWjA, 0.0f);
  numBytes += cVar_init_f(&cVar_vjRXWVeO, 0.0f);
  numBytes += cTabread_init(&cTabread_BTqMoW5G, &hTable_BE6zeSTY); // p2
  numBytes += cBinop_init(&cBinop_G68vIWES, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_a2VewrLU, 1, -1);
  numBytes += cVar_init_s(&cVar_u2pSCHyZ, "p2");
  numBytes += cVar_init_f(&cVar_j2Lehmkv, 1.0f);
  numBytes += sVarf_init(&sVarf_CLHUJnQA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aokhutTT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FjuvuaCn, 0.0f);
  numBytes += cVar_init_f(&cVar_qYNF4zpF, 0.0f);
  numBytes += sVarf_init(&sVarf_L6N9DfTE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Zx9qE7mS, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_njTFFfZm, false);
  numBytes += cVar_init_f(&cVar_nlny4Wgo, 0.0f);
  numBytes += cBinop_init(&cBinop_TCvZ9Pfp, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YC8wjkdl, 2000.0f);
  numBytes += cDelay_init(this, &cDelay_GVsIB7R9, 0.0f);
  numBytes += cIf_init(&cIf_JjczlcSk, false);
  numBytes += cVar_init_f(&cVar_KzsvUQAf, 0.0f);
  numBytes += cVar_init_f(&cVar_Naa2ewIw, 0.0f);
  numBytes += cIf_init(&cIf_Qv6S3Een, true);
  numBytes += sVarf_init(&sVarf_PlEreoAL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_C99Zxz2c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fIVBka7d, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_2ggFVgNB, false);
  numBytes += cVar_init_f(&cVar_G6rRe6n4, 0.0f);
  numBytes += cBinop_init(&cBinop_nzf8hHt2, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lUatANXJ, 50.0f);
  numBytes += cDelay_init(this, &cDelay_zE6MlffF, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_BE6zeSTY);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xC7A73BB7: return &hTable_BE6zeSTY; // p2
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HpQiAO6k_sendMessage);
      break;
    }
    case 0xA8BFDCCE: { // current
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yFluBDy8_sendMessage);
      break;
    }
    case 0xD020B8D1: { // metrospeed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lv9Wp9J3_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GMdWvw1M_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8qTmhtDQ_sendMessage);
      break;
    }
    case 0x125109EA: { // pot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_u9ks6H89_sendMessage);
      break;
    }
    case 0x73BEE661: { // pot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YARphFsz_sendMessage);
      break;
    }
    case 0xFDE4431F: { // slider1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bEEdaF0Q_sendMessage);
      break;
    }
    case 0x995F2576: { // thepot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mA9H9j9V_sendMessage);
      break;
    }
    case 0xD54A2BE1: { // v1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ciKD05lf_sendMessage);
      break;
    }
    case 0x8C1F50A3: { // v2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xPIc9MfH_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "pot4";
        info->hash = 0x73BEE661;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 410.0f;
        info->defaultVal = 200.0f;
        break;
      }
      case 1: {
        info->name = "pot3";
        info->hash = 0x125109EA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 410.0f;
        info->defaultVal = 200.0f;
        break;
      }
      case 2: {
        info->name = "pot2";
        info->hash = 0xDDC4EBDB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 410.0f;
        info->defaultVal = 200.0f;
        break;
      }
      case 3: {
        info->name = "pot1";
        info->hash = 0x3AE704A5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 410.0f;
        info->defaultVal = 200.0f;
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
  return 4;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cBinop_hYAGX5ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A6vXLkxJ, 1, m, &cVar_A6vXLkxJ_sendMessage);
}

void Heavy_heavy::cMsg_m0w44wfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cSend_NgWfTRYA_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_qhwLawzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i0KPql4L, HV_BINOP_MULTIPLY, 0, m, &cBinop_i0KPql4L_sendMessage);
}

void Heavy_heavy::cMsg_39L0Frn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SHXAxYYl_sendMessage);
}

void Heavy_heavy::cSystem_SHXAxYYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bQ2PeKfD_sendMessage);
}

void Heavy_heavy::cBinop_bQ2PeKfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i0KPql4L, HV_BINOP_MULTIPLY, 1, m, &cBinop_i0KPql4L_sendMessage);
}

void Heavy_heavy::cBinop_Pwa5gXFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLEVFn9l, 2, m, &cDelay_yLEVFn9l_sendMessage);
}

void Heavy_heavy::cBinop_i0KPql4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Pwa5gXFb_sendMessage);
}

void Heavy_heavy::cDelay_yLEVFn9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yLEVFn9l, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLEVFn9l, 0, m, &cDelay_yLEVFn9l_sendMessage);
}

void Heavy_heavy::cSwitchcase_EXjjhOUG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_uKRhG7i8_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_uKRhG7i8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eQ5Um9vt_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_uKRhG7i8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLEVFn9l, 0, m, &cDelay_yLEVFn9l_sendMessage);
}

void Heavy_heavy::cCast_eQ5Um9vt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uKRhG7i8_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yLEVFn9l, 0, m, &cDelay_yLEVFn9l_sendMessage);
}

void Heavy_heavy::cVar_w5p9WiDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_j9SdnxxB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_A6vXLkxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hYAGX5ta_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_UNIPOLAR, 8.0f, 0, m, &cBinop_b7KBHYiA_sendMessage);
}

void Heavy_heavy::cMsg_sR8Mslas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KzsvUQAf, 0, m, &cVar_KzsvUQAf_sendMessage);
}

void Heavy_heavy::cReceive_YARphFsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JIUZdoEw_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_ZWPijH8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_HpQiAO6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UXv0S6UH_sendMessage(_c, 0, m);
  cMsg_AAOMu1IP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YC8wjkdl, 0, m, &cVar_YC8wjkdl_sendMessage);
  cMsg_i8AALTRb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lUatANXJ, 0, m, &cVar_lUatANXJ_sendMessage);
  cMsg_39L0Frn1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qhwLawzI, 0, m, &cVar_qhwLawzI_sendMessage);
  cMsg_nDHRpk56_sendMessage(_c, 0, m);
  cSwitchcase_cynCizVw_onMessage(_c, NULL, 0, m, NULL);
  cMsg_sR8Mslas_sendMessage(_c, 0, m);
  cMsg_0aJXUHPj_sendMessage(_c, 0, m);
  cMsg_3zulMTTy_sendMessage(_c, 0, m);
  cMsg_ZNLr6RRn_sendMessage(_c, 0, m);
  cSwitchcase_vOcH8IzQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_XKU1ICT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XkwL4gTU_sendMessage(_c, 0, m);
}

void Heavy_heavy::hTable_BE6zeSTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cCast_WKY2M694_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A6vXLkxJ, 0, m, &cVar_A6vXLkxJ_sendMessage);
}

void Heavy_heavy::cMsg_XkwL4gTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_QOIZkHm2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_wNSNYWjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G6rRe6n4, 0, m, &cVar_G6rRe6n4_sendMessage);
}

void Heavy_heavy::cSend_er9z6dyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_vjRXWVeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BG4jHUFt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cTabread_BTqMoW5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZWPijH8j, 0, m, &cVar_ZWPijH8j_sendMessage);
}

void Heavy_heavy::cBinop_HXHWTrtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G68vIWES, HV_BINOP_MIN, 1, m, &cBinop_G68vIWES_sendMessage);
}

void Heavy_heavy::cMsg_JPZzpqTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_huwKzNMD_sendMessage);
}

void Heavy_heavy::cBinop_G68vIWES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_BTqMoW5G, 0, m, &cTabread_BTqMoW5G_sendMessage);
}

void Heavy_heavy::cSlice_a2VewrLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_BTqMoW5G, 1, m, &cTabread_BTqMoW5G_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_BTqMoW5G, 1, m, &cTabread_BTqMoW5G_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_n0knTPCr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a2VewrLU, 0, m, &cSlice_a2VewrLU_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tUJvsYfU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BEhSUh5T_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSystem_huwKzNMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HXHWTrtW_sendMessage);
}

void Heavy_heavy::cCast_BEhSUh5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VCaWDLLH_sendMessage);
}

void Heavy_heavy::cCast_tUJvsYfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u2pSCHyZ, 0, m, &cVar_u2pSCHyZ_sendMessage);
}

void Heavy_heavy::cVar_u2pSCHyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JPZzpqTd_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_VCaWDLLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G68vIWES, HV_BINOP_MIN, 0, m, &cBinop_G68vIWES_sendMessage);
}

void Heavy_heavy::cMsg_5E0wXPMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_De5dBBw8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_j2Lehmkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YPlmIaep_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_njTFFfZm, 1, m, &cIf_njTFFfZm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RbrBJG8p_sendMessage);
}

void Heavy_heavy::cBinop_YPlmIaep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j2Lehmkv, 1, m, &cVar_j2Lehmkv_sendMessage);
}

void Heavy_heavy::cMsg_qZ4jRhJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(6);
  msg_init(m, 6, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "p2");
  msg_setFloat(m, 1, 0.0f);
  msg_setFloat(m, 2, -1.0f);
  msg_setFloat(m, 3, 0.3f);
  msg_setFloat(m, 4, 0.5f);
  msg_setFloat(m, 5, 1.0f);
}

void Heavy_heavy::cCast_aJ4a6c8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jgtpVKz1_sendMessage);
  cMsg_m0w44wfL_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_cp4z6sFW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aJ4a6c8P_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KmCDYq2O_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_2G9PEAyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vOcH8IzQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_0gS9nyUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cSend_jtLGNKQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_nDHRpk56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zx9qE7mS, m);
}

void Heavy_heavy::cReceive_yFluBDy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cp4z6sFW_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_yHLvGIoZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_bmTwezs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cReceive_bEEdaF0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2ggFVgNB, 0, m, &cIf_2ggFVgNB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JjczlcSk, 0, m, &cIf_JjczlcSk_sendMessage);
}

void Heavy_heavy::cCast_b7V81I9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XKU1ICT9_sendMessage);
  cMsg_fgQ0bdYP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_yHLvGIoZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b7V81I9G_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KMzdqxmZ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_3zulMTTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_HyupRMo9_sendMessage(_c, 0, m);
  cSend_bmTwezs5_sendMessage(_c, 0, m);
  cSend_gST9XWpf_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_e4aLBZDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sSample_onMessage(_c, &Context(_c)->sSample_w9Z2vJeY, 1, m);
}

void Heavy_heavy::cSend_onkoZMuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mA9H9j9V_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_BG4jHUFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cCast_Kt1DdBYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qYNF4zpF, 0, m, &cVar_qYNF4zpF_sendMessage);
}

void Heavy_heavy::cSend_JIUZdoEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_ZNLr6RRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PlEreoAL, m);
}

void Heavy_heavy::cVar_FjuvuaCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Naa2ewIw, 0, m, &cVar_Naa2ewIw_sendMessage);
}

void Heavy_heavy::cReceive_u9ks6H89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Dc5WqO3y_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_TV5uaiSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_De5dBBw8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_30j7ybGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ceL5jQIX, 0, m);
}

void Heavy_heavy::cVar_qYNF4zpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A6vXLkxJ, 0, m, &cVar_A6vXLkxJ_sendMessage);
}

void Heavy_heavy::sSample_w9Z2vJeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vjRXWVeO, 0, m, &cVar_vjRXWVeO_sendMessage);
}

void Heavy_heavy::cSend_Dc5WqO3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_JbgWad2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_L6N9DfTE, m);
}

void Heavy_heavy::cSend_zEWmLLPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lv9Wp9J3_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_lv9Wp9J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YC8wjkdl, 0, m, &cVar_YC8wjkdl_sendMessage);
}

void Heavy_heavy::cReceive_GMdWvw1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_onkoZMuJ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_De5dBBw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ciKD05lf_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_b7KBHYiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wNSNYWjA, 0, m, &cVar_wNSNYWjA_sendMessage);
  cSwitchcase_n0knTPCr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_njTFFfZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_nlny4Wgo, 0, m, &cVar_nlny4Wgo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSend_SfLOg7Vw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yFluBDy8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_j9SdnxxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bEEdaF0Q_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_NgWfTRYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lv9Wp9J3_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_oeo56Cd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bEEdaF0Q_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_nlny4Wgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_er9z6dyw_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_mDF56h3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L6N9DfTE, m);
}

void Heavy_heavy::cBinop_TCvZ9Pfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lJ73CqWl_sendMessage);
}

void Heavy_heavy::cSwitchcase_cynCizVw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_kr1GE1kF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_kr1GE1kF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LmRI8rSk_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_YC8wjkdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TCvZ9Pfp, HV_BINOP_MULTIPLY, 0, m, &cBinop_TCvZ9Pfp_sendMessage);
}

void Heavy_heavy::cCast_LmRI8rSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kr1GE1kF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVsIB7R9, 0, m, &cDelay_GVsIB7R9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GoYHUhJ1_sendMessage);
}

void Heavy_heavy::cMsg_kr1GE1kF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVsIB7R9, 0, m, &cDelay_GVsIB7R9_sendMessage);
}

void Heavy_heavy::cBinop_lJ73CqWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVsIB7R9, 2, m, &cDelay_GVsIB7R9_sendMessage);
}

void Heavy_heavy::cBinop_aEJLQngy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TCvZ9Pfp, HV_BINOP_MULTIPLY, 1, m, &cBinop_TCvZ9Pfp_sendMessage);
}

void Heavy_heavy::cDelay_GVsIB7R9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GVsIB7R9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GVsIB7R9, 0, m, &cDelay_GVsIB7R9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GoYHUhJ1_sendMessage);
}

void Heavy_heavy::cSystem_VNs9opFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aEJLQngy_sendMessage);
}

void Heavy_heavy::cMsg_AAOMu1IP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VNs9opFv_sendMessage);
}

void Heavy_heavy::cCast_jgtpVKz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TV5uaiSn_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_JjczlcSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_30j7ybGF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cReceive_mA9H9j9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CLHUJnQA, m);
}

void Heavy_heavy::cVar_KzsvUQAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_njTFFfZm, 0, m, &cIf_njTFFfZm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Qv6S3Een, 0, m, &cIf_Qv6S3Een_sendMessage);
}

void Heavy_heavy::cSend_gST9XWpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cCast_KmCDYq2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5E0wXPMr_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_Naa2ewIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oeo56Cd1_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_HyupRMo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cMsg_0aJXUHPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1024.0f);
  cSend_0gS9nyUH_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_Qv6S3Een_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_w5p9WiDP, 0, m, &cVar_w5p9WiDP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cMsg_buEKc6AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_QOIZkHm2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_ciKD05lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JjczlcSk, 1, m, &cIf_JjczlcSk_sendMessage);
}

void Heavy_heavy::cBinop_RbrBJG8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Qv6S3Een, 1, m, &cIf_Qv6S3Een_sendMessage);
}

void Heavy_heavy::cBinop_YlSKJIHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_C99Zxz2c, m);
}

void Heavy_heavy::cMsg_UXv0S6UH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EzeFC6Ms_sendMessage);
}

void Heavy_heavy::cSystem_EzeFC6Ms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rt5TPvWz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_Rt5TPvWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YlSKJIHB_sendMessage);
}

void Heavy_heavy::cReceive_8qTmhtDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_jtLGNKQV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_fgQ0bdYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 200.0f);
  cSend_zEWmLLPW_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_KMzdqxmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_buEKc6AO_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_2ggFVgNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_mDF56h3p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSend_QOIZkHm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xPIc9MfH_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_G6rRe6n4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SfLOg7Vw_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_GoYHUhJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSwitchcase_vOcH8IzQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_5jDqlBe4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_5jDqlBe4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uympht4x_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_uympht4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5jDqlBe4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zE6MlffF, 0, m, &cDelay_zE6MlffF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e4aLBZDI_sendMessage);
}

void Heavy_heavy::cBinop_qxpNzXZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zE6MlffF, 2, m, &cDelay_zE6MlffF_sendMessage);
}

void Heavy_heavy::cBinop_nzf8hHt2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_qxpNzXZq_sendMessage);
}

void Heavy_heavy::cSystem_jg3ruYgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_J4j8wzUB_sendMessage);
}

void Heavy_heavy::cMsg_i8AALTRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jg3ruYgh_sendMessage);
}

void Heavy_heavy::cBinop_J4j8wzUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzf8hHt2, HV_BINOP_MULTIPLY, 1, m, &cBinop_nzf8hHt2_sendMessage);
}

void Heavy_heavy::cMsg_5jDqlBe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zE6MlffF, 0, m, &cDelay_zE6MlffF_sendMessage);
}

void Heavy_heavy::cVar_lUatANXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzf8hHt2, HV_BINOP_MULTIPLY, 0, m, &cBinop_nzf8hHt2_sendMessage);
}

void Heavy_heavy::cDelay_zE6MlffF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zE6MlffF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zE6MlffF, 0, m, &cDelay_zE6MlffF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e4aLBZDI_sendMessage);
}

void Heavy_heavy::cReceive_xPIc9MfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2ggFVgNB, 1, m, &cIf_2ggFVgNB_sendMessage);
}

void Heavy_heavy::cCast_01eci0fv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cynCizVw_onMessage(_c, NULL, 0, m, NULL);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9;

  // input and output vars
  hv_bufferf_t O0, O1, O2, O3;

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

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));
    __hv_zero_f(VOf(O2));
    __hv_zero_f(VOf(O3));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_lUCchBEk, VOf(Bf0));
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
    __hv_add_f(VIf(Bf1), VIf(O3), VOf(O3));
    __hv_varread_f(&sVarf_CLHUJnQA, VOf(Bf1));
    __hv_varread_f(&sVarf_fIVBka7d, VOf(Bf1));
    __hv_varread_f(&sVarf_aokhutTT, VOf(Bf3));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_EQN3uYxY, VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sample_f(this, &sSample_w9Z2vJeY, VIf(Bf3), &sSample_w9Z2vJeY_sendMessage);
    __hv_phasor_k_f(&sPhasor_qPyrN5PU, VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O2), VOf(O2));
    __hv_varread_f(&sVarf_L6N9DfTE, VOf(Bf0));
    __hv_phasor_f(&sPhasor_26rS4I4Z, VIf(Bf0), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_C99Zxz2c, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf8));
    __hv_lte_f(VIf(Bf3), VIf(Bf5), VOf(Bf9));
    __hv_and_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_gte_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_fIVBka7d, VIf(Bf2));
    __hv_phasor_k_f(&sPhasor_ceL5jQIX, VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_aokhutTT, VIf(Bf6));
    __hv_varread_f(&sVarf_PlEreoAL, VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_Zx9qE7mS, VOf(Bf4));

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

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

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

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

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
