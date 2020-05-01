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
 * Table Data
 */

float hTable_4pORzTmm_data[8] = {0.0f, 0.5f, 1.0f, 0.5f, 0.0f, -0.5f, -1.0f, -0.5f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sSample_init(&sSample_1TDnHgJy);
  numBytes += sPhasor_k_init(&sPhasor_WiQNeTNT, 0.1f, sampleRate);
  numBytes += cVar_init_f(&cVar_KNIzVYsF, 0.0f);
  numBytes += sVarf_init(&sVarf_GZfsy7fk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HoOydShw, 0.0f);
  numBytes += cBinop_init(&cBinop_sCpjz4aw, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3pNYXuDq, 50.0f);
  numBytes += cDelay_init(this, &cDelay_Nj8ju9vW, 0.0f);
  numBytes += cSlice_init(&cSlice_epyP7Fpm, 1, 1);
  numBytes += cRandom_init(&cRandom_4XDblGHz, 495047363);
  numBytes += cVar_init_f(&cVar_FHU1cFWK, 0.0f);
  numBytes += cBinop_init(&cBinop_2imfZCuE, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_2MoydEYE, &hTable_pQBBMaTB); // p2
  numBytes += cSlice_init(&cSlice_JMbiAzfe, 1, -1);
  numBytes += cVar_init_s(&cVar_DSB3Jhht, "p2");
  numBytes += cIf_init(&cIf_K1prLupm, false);
  numBytes += cBinop_init(&cBinop_kujPbtD5, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_nN5i0Nto, 0.0f);
  numBytes += cSlice_init(&cSlice_fiaZQ7ag, 1, -1);
  numBytes += cSlice_init(&cSlice_RjDHZpbO, 1, -1);
  numBytes += cVar_init_f(&cVar_v4TVSyrT, 0.0f);
  numBytes += cVar_init_f(&cVar_tpdGnhon, 0.0f);
  numBytes += cVar_init_f(&cVar_OVYErndF, 0.0f);
  numBytes += hTable_init(&hTable_pQBBMaTB, 0);
  numBytes += cVar_init_f(&cVar_gYIlHD0j, 0.0f);
  numBytes += cVar_init_f(&cVar_wyxB5TIC, 0.0f);
  numBytes += cDelay_init(this, &cDelay_4nf7F1Bk, 0.0f);
  numBytes += cVar_init_f(&cVar_Rhk8bSXJ, 50.0f);
  numBytes += cBinop_init(&cBinop_8ZyVc9v2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0YAYHVyd, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_Fk42RMHe, &hTable_4pORzTmm); // 1001-array2
  numBytes += cVar_init_s(&cVar_vhirPLXA, "1001-array2");
  numBytes += cSlice_init(&cSlice_jDVIzQnu, 1, -1);
  numBytes += cDelay_init(this, &cDelay_JMpCGe0S, 0.0f);
  numBytes += cBinop_init(&cBinop_8PUwprvE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_z9vthNKh, 300.0f);
  numBytes += hTable_initWithData(&hTable_4pORzTmm, 8, hTable_4pORzTmm_data);
  numBytes += cSlice_init(&cSlice_Eln2PENt, 1, 1);
  numBytes += cRandom_init(&cRandom_PHjtYt8K, -1983147730);
  numBytes += cVar_init_f(&cVar_1IQw0wam, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_pQBBMaTB);
  hTable_free(&hTable_4pORzTmm);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xC7A73BB7: return &hTable_pQBBMaTB; // p2
    case 0x4F2DE9E8: return &hTable_4pORzTmm; // 1001-array2
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VzpX1Vvn_sendMessage);
      break;
    }
    case 0xBB2E5490: { // led2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_f4zkSt41_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8pEECm6L_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D877mNZD_sendMessage);
      break;
    }
    case 0x125109EA: { // pot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rEue0CWN_sendMessage);
      break;
    }
    case 0x73BEE661: { // pot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BHDL4UH3_sendMessage);
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


void Heavy_heavy::cBinop_sgEIhNXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KNIzVYsF, 1, m, &cVar_KNIzVYsF_sendMessage);
}

void Heavy_heavy::cReceive_VzpX1Vvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RMTzN0Nv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3pNYXuDq, 0, m, &cVar_3pNYXuDq_sendMessage);
  cMsg_6CYMAGSS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Rhk8bSXJ, 0, m, &cVar_Rhk8bSXJ_sendMessage);
  cMsg_YYJUeJ0X_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_z9vthNKh, 0, m, &cVar_z9vthNKh_sendMessage);
  cMsg_PhYbit30_sendMessage(_c, 0, m);
  cMsg_1fXarSaW_sendMessage(_c, 0, m);
  cSwitchcase_SixzFIvH_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_29Xh4yfC_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pGhPijhm_onMessage(_c, NULL, 0, m, NULL);
  cMsg_53dgMucR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_gUVS6kAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
  cReceive_f4zkSt41_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_f4zkSt41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tpdGnhon, 0, m, &cVar_tpdGnhon_sendMessage);
}

void Heavy_heavy::cCast_90OdYTK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_yOWIJGxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wyxB5TIC, 0, m, &cVar_wyxB5TIC_sendMessage);
}

void Heavy_heavy::cSend_MiAnOBKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cCast_7kX1Bh4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rRIpTQ5G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_JR1P8D8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_E64E6Ixh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_KNIzVYsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sgEIhNXB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_UNIPOLAR, 8.0f, 0, m, &cBinop_Rrhq6K3X_sendMessage);
}

void Heavy_heavy::cReceive_D877mNZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qRsoLu3H_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_BHDL4UH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_E64E6Ixh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_HoOydShw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_5ydw6ptT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cBinop_Rrhq6K3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OVYErndF, 0, m, &cVar_OVYErndF_sendMessage);
  cSwitchcase_csy1VEUo_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_izi9znzm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_VuRkv6Zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nj8ju9vW, 2, m, &cDelay_Nj8ju9vW_sendMessage);
}

void Heavy_heavy::cMsg_RMTzN0Nv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UN6xebQC_sendMessage);
}

void Heavy_heavy::cSystem_UN6xebQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KD5GFXcv_sendMessage);
}

void Heavy_heavy::cBinop_sCpjz4aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VuRkv6Zt_sendMessage);
}

void Heavy_heavy::cVar_3pNYXuDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sCpjz4aw, HV_BINOP_MULTIPLY, 0, m, &cBinop_sCpjz4aw_sendMessage);
}

void Heavy_heavy::cBinop_KD5GFXcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sCpjz4aw, HV_BINOP_MULTIPLY, 1, m, &cBinop_sCpjz4aw_sendMessage);
}

void Heavy_heavy::cMsg_67HQv9nG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nj8ju9vW, 0, m, &cDelay_Nj8ju9vW_sendMessage);
}

void Heavy_heavy::cSwitchcase_29Xh4yfC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_67HQv9nG_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_67HQv9nG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cGg6Kphy_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_Nj8ju9vW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Nj8ju9vW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nj8ju9vW, 0, m, &cDelay_Nj8ju9vW_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_1TDnHgJy, 1, m);
  cSwitchcase_01CVVBN7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_cGg6Kphy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_67HQv9nG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Nj8ju9vW, 0, m, &cDelay_Nj8ju9vW_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_1TDnHgJy, 1, m);
  cSwitchcase_01CVVBN7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_IzlouvIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FHU1cFWK, 0, m, &cVar_FHU1cFWK_sendMessage);
}

void Heavy_heavy::cSwitchcase_01CVVBN7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_epyP7Fpm, 0, m, &cSlice_epyP7Fpm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4XDblGHz, 0, m, &cRandom_4XDblGHz_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_epyP7Fpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4XDblGHz, 1, m, &cRandom_4XDblGHz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cRandom_4XDblGHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1024.0f, 0, m, &cBinop_kyr9z3Sw_sendMessage);
}

void Heavy_heavy::cBinop_kyr9z3Sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IzlouvIe_sendMessage);
}

void Heavy_heavy::cSend_YDY2VoMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_FHU1cFWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_2imfZCuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_2MoydEYE, 0, m, &cTabread_2MoydEYE_sendMessage);
}

void Heavy_heavy::cTabread_2MoydEYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1IQw0wam, 0, m, &cVar_1IQw0wam_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MfSQmmB0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_90OdYTK5_sendMessage);
}

void Heavy_heavy::cSlice_JMbiAzfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2MoydEYE, 1, m, &cTabread_2MoydEYE_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2MoydEYE, 1, m, &cTabread_2MoydEYE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_csy1VEUo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JMbiAzfe, 0, m, &cSlice_JMbiAzfe_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wpe57UUG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rJTrQ7FR_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_Z4jFO3r9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2imfZCuE, HV_BINOP_MIN, 0, m, &cBinop_2imfZCuE_sendMessage);
}

void Heavy_heavy::cVar_DSB3Jhht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0R4FhLcU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_nCTvO5D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2imfZCuE, HV_BINOP_MIN, 1, m, &cBinop_2imfZCuE_sendMessage);
}

void Heavy_heavy::cMsg_0R4FhLcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o0dWVIPl_sendMessage);
}

void Heavy_heavy::cSystem_o0dWVIPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nCTvO5D4_sendMessage);
}

void Heavy_heavy::cCast_rJTrQ7FR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Z4jFO3r9_sendMessage);
}

void Heavy_heavy::cCast_wpe57UUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DSB3Jhht, 0, m, &cVar_DSB3Jhht_sendMessage);
}

void Heavy_heavy::cCast_MfSQmmB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cCast_Q2dmXa7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nN5i0Nto, 0, m, &cVar_nN5i0Nto_sendMessage);
}

void Heavy_heavy::cIf_K1prLupm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_O1npxGN1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Q2dmXa7o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_kujPbtD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K1prLupm, 1, m, &cIf_K1prLupm_sendMessage);
}

void Heavy_heavy::cCast_8jTj2oDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K1prLupm, 0, m, &cIf_K1prLupm_sendMessage);
}

void Heavy_heavy::cCast_TOk1h9QK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kujPbtD5, HV_BINOP_NEQ, 0, m, &cBinop_kujPbtD5_sendMessage);
}

void Heavy_heavy::cVar_nN5i0Nto_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v4TVSyrT, 0, m, &cVar_v4TVSyrT_sendMessage);
}

void Heavy_heavy::cCast_O1npxGN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kujPbtD5, HV_BINOP_NEQ, 1, m, &cBinop_kujPbtD5_sendMessage);
}

void Heavy_heavy::cSlice_fiaZQ7ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_nN5i0Nto, 0, m, &cVar_nN5i0Nto_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_nN5i0Nto, 0, m, &cVar_nN5i0Nto_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_RjDHZpbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kujPbtD5, HV_BINOP_NEQ, 1, m, &cBinop_kujPbtD5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_nN5i0Nto, 1, m, &cVar_nN5i0Nto_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kujPbtD5, HV_BINOP_NEQ, 1, m, &cBinop_kujPbtD5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_nN5i0Nto, 1, m, &cVar_nN5i0Nto_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_dkzgfEuo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fiaZQ7ag, 0, m, &cSlice_fiaZQ7ag_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RjDHZpbO, 0, m, &cSlice_RjDHZpbO_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TOk1h9QK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8jTj2oDK_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSend_mPFAwhmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cSend_qRsoLu3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_v4TVSyrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gUVS6kAj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_tpdGnhon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::sSample_1TDnHgJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dkzgfEuo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_rEue0CWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JR1P8D8b_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_OVYErndF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_8pEECm6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YDY2VoMH_sendMessage(_c, 0, m);
}

void Heavy_heavy::hTable_pQBBMaTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_gYIlHD0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GZfsy7fk, m);
}

void Heavy_heavy::cVar_wyxB5TIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSwitchcase_pGhPijhm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_UmzCDqAK_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_UmzCDqAK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GCgSjhK4_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_4nf7F1Bk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4nf7F1Bk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nf7F1Bk, 0, m, &cDelay_4nf7F1Bk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HoOydShw, 0, m, &cVar_HoOydShw_sendMessage);
}

void Heavy_heavy::cSystem_uE13QPBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z2lS5CER_sendMessage);
}

void Heavy_heavy::cMsg_6CYMAGSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uE13QPBN_sendMessage);
}

void Heavy_heavy::cVar_Rhk8bSXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ZyVc9v2, HV_BINOP_MULTIPLY, 0, m, &cBinop_8ZyVc9v2_sendMessage);
}

void Heavy_heavy::cBinop_8ZyVc9v2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_d6bfuMA2_sendMessage);
}

void Heavy_heavy::cBinop_d6bfuMA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nf7F1Bk, 2, m, &cDelay_4nf7F1Bk_sendMessage);
}

void Heavy_heavy::cCast_GCgSjhK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UmzCDqAK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nf7F1Bk, 0, m, &cDelay_4nf7F1Bk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HoOydShw, 0, m, &cVar_HoOydShw_sendMessage);
}

void Heavy_heavy::cMsg_UmzCDqAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4nf7F1Bk, 0, m, &cDelay_4nf7F1Bk_sendMessage);
}

void Heavy_heavy::cBinop_z2lS5CER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ZyVc9v2, HV_BINOP_MULTIPLY, 1, m, &cBinop_8ZyVc9v2_sendMessage);
}

void Heavy_heavy::cMsg_PhYbit30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 98.0f);
  cSend_5ydw6ptT_sendMessage(_c, 0, m);
  cSend_mPFAwhmN_sendMessage(_c, 0, m);
  cSend_yMUoYWeP_sendMessage(_c, 0, m);
  cSend_MiAnOBKS_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_53dgMucR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1024.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HoOydShw, 0, m, &cVar_HoOydShw_sendMessage);
}

void Heavy_heavy::cCast_pXO0RcCE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8OUJzSIa_sendMessage);
}

void Heavy_heavy::cBinop_7ysnh75l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YAYHVyd, HV_BINOP_MIN, 1, m, &cBinop_0YAYHVyd_sendMessage);
}

void Heavy_heavy::cSystem_JruIg8mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7ysnh75l_sendMessage);
}

void Heavy_heavy::cMsg_ogVIK9eC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JruIg8mx_sendMessage);
}

void Heavy_heavy::cBinop_0YAYHVyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_Fk42RMHe, 0, m, &cTabread_Fk42RMHe_sendMessage);
}

void Heavy_heavy::cBinop_8OUJzSIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0YAYHVyd, HV_BINOP_MIN, 0, m, &cBinop_0YAYHVyd_sendMessage);
}

void Heavy_heavy::cTabread_Fk42RMHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gYIlHD0j, 0, m, &cVar_gYIlHD0j_sendMessage);
}

void Heavy_heavy::cVar_vhirPLXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ogVIK9eC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_izi9znzm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jDVIzQnu, 0, m, &cSlice_jDVIzQnu_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2Fd7Esq9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pXO0RcCE_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_jDVIzQnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Fk42RMHe, 1, m, &cTabread_Fk42RMHe_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Fk42RMHe, 1, m, &cTabread_Fk42RMHe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_2Fd7Esq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vhirPLXA, 0, m, &cVar_vhirPLXA_sendMessage);
}

void Heavy_heavy::cCast_0nqsrGxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1fXarSaW_sendMessage(_c, 0, m);
  cSwitchcase_SixzFIvH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSwitchcase_SixzFIvH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_rZyqhtIY_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_rZyqhtIY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HTknxZIx_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_JMpCGe0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JMpCGe0S, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JMpCGe0S, 0, m, &cDelay_JMpCGe0S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KNIzVYsF, 0, m, &cVar_KNIzVYsF_sendMessage);
}

void Heavy_heavy::cBinop_NEzXlX4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JMpCGe0S, 2, m, &cDelay_JMpCGe0S_sendMessage);
}

void Heavy_heavy::cCast_HTknxZIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rZyqhtIY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JMpCGe0S, 0, m, &cDelay_JMpCGe0S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KNIzVYsF, 0, m, &cVar_KNIzVYsF_sendMessage);
}

void Heavy_heavy::cBinop_xYN23ALC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8PUwprvE, HV_BINOP_MULTIPLY, 1, m, &cBinop_8PUwprvE_sendMessage);
}

void Heavy_heavy::cBinop_8PUwprvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NEzXlX4C_sendMessage);
}

void Heavy_heavy::cVar_z9vthNKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8PUwprvE, HV_BINOP_MULTIPLY, 0, m, &cBinop_8PUwprvE_sendMessage);
}

void Heavy_heavy::cMsg_rZyqhtIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JMpCGe0S, 0, m, &cDelay_JMpCGe0S_sendMessage);
}

void Heavy_heavy::cSystem_eZbR5CcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xYN23ALC_sendMessage);
}

void Heavy_heavy::cMsg_YYJUeJ0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eZbR5CcU_sendMessage);
}

void Heavy_heavy::hTable_4pORzTmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSlice_Eln2PENt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PHjtYt8K, 1, m, &cRandom_PHjtYt8K_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_rRIpTQ5G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Eln2PENt, 0, m, &cSlice_Eln2PENt_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PHjtYt8K, 0, m, &cRandom_PHjtYt8K_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_bnRYQaJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BJk2GNzr_sendMessage);
}

void Heavy_heavy::cRandom_PHjtYt8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1024.0f, 0, m, &cBinop_bnRYQaJ9_sendMessage);
}

void Heavy_heavy::cUnop_BJk2GNzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_1IQw0wam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cCast_wAlRXpfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_29Xh4yfC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_yMUoYWeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
  cReceive_f4zkSt41_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_1fXarSaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(7);
  msg_init(m, 7, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "p2");
  msg_setFloat(m, 1, 0.0f);
  msg_setFloat(m, 2, 1.0f);
  msg_setFloat(m, 3, 1.0f);
  msg_setFloat(m, 4, 1.0f);
  msg_setFloat(m, 5, 1.0f);
  msg_setFloat(m, 6, 1.0f);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;

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
    __hv_varread_f(&sVarf_GZfsy7fk, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f, 512.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_1TDnHgJy, VIf(Bf0), &sSample_1TDnHgJy_sendMessage);
    __hv_phasor_k_f(&sPhasor_WiQNeTNT, VOf(Bf0));
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
