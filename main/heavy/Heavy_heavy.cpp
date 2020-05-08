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
  numBytes += sPhasor_init(&sPhasor_lWfUc4Vq, sampleRate);
  numBytes += sPhasor_init(&sPhasor_bmLpPQTa, sampleRate);
  numBytes += cVar_init_f(&cVar_cICHT37D, 0.0f);
  numBytes += sVarf_init(&sVarf_l87uahly, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AFqxhbzM, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_UQsXd5SD, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_94QcwWn8, 1, -1);
  numBytes += cSlice_init(&cSlice_qH9mj3GS, 1, -1);
  numBytes += cIf_init(&cIf_JB8turHL, false);
  numBytes += cVar_init_f(&cVar_vjh6g2HK, 0.0f);
  numBytes += sVarf_init(&sVarf_NgUIHt4N, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8z10xsLl, 0.0f);
  numBytes += sVarf_init(&sVarf_PKeLgOOV, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  // nothing to free
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6kt50oow_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EdHNLuGz_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JxqU3gsG_sendMessage);
      break;
    }
    case 0x125109EA: { // pot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kjg23WpT_sendMessage);
      break;
    }
    case 0x73BEE661: { // pot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CQLhBYug_sendMessage);
      break;
    }
    case 0xF2BC7D02: { // pot5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5BrW1o2Y_sendMessage);
      break;
    }
    case 0x995F2576: { // thepot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C9VB00Y8_sendMessage);
      break;
    }
    case 0xF5E48EA0: { // thepot5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_70qvyf4s_sendMessage);
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
        info->maxVal = 512.0f;
        info->defaultVal = 256.0f;
        break;
      }
      case 2: {
        info->name = "pot3";
        info->hash = 0x125109EA;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 512.0f;
        info->defaultVal = 256.0f;
        break;
      }
      case 3: {
        info->name = "pot2";
        info->hash = 0xDDC4EBDB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 512.0f;
        info->defaultVal = 256.0f;
        break;
      }
      case 4: {
        info->name = "pot1";
        info->hash = 0x3AE704A5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 512.0f;
        info->defaultVal = 256.0f;
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


void Heavy_heavy::cSend_gWoBBSUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_C9VB00Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sSSoDqbH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_RoREtCdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_5BrW1o2Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2048.0f, 0, m, &cBinop_FAwsN5bP_sendMessage);
}

void Heavy_heavy::cVar_cICHT37D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2048.0f, 0, m, &cBinop_FAwsN5bP_sendMessage);
}

void Heavy_heavy::cBinop_OcZbN29Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PKeLgOOV, m);
  cSend_DmpouRse_sendMessage(_c, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_l87uahly, m);
}

void Heavy_heavy::cSend_ncEFrRHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cBinop_7RH3FX10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8tgXHReM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_DmpouRse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cSend_i8YRvSRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_C9VB00Y8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_8tgXHReM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_70qvyf4s_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_EdHNLuGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_i8YRvSRR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_J9TC7mlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cReceive_JxqU3gsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_gWoBBSUo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_CQLhBYug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bNNEruvV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_mMFwzCBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 255.0f);
  cSend_suncw55e_sendMessage(_c, 0, m);
  cSend_J9TC7mlH_sendMessage(_c, 0, m);
  cSend_ncEFrRHL_sendMessage(_c, 0, m);
  cSend_m9r0ZEvu_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_UQsXd5SD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JB8turHL, 1, m, &cIf_JB8turHL_sendMessage);
}

void Heavy_heavy::cCast_Lj4gAYf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQsXd5SD, HV_BINOP_NEQ, 1, m, &cBinop_UQsXd5SD_sendMessage);
}

void Heavy_heavy::cSlice_94QcwWn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UQsXd5SD, HV_BINOP_NEQ, 1, m, &cBinop_UQsXd5SD_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_vjh6g2HK, 1, m, &cVar_vjh6g2HK_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_UQsXd5SD, HV_BINOP_NEQ, 1, m, &cBinop_UQsXd5SD_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_vjh6g2HK, 1, m, &cVar_vjh6g2HK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_qH9mj3GS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_vjh6g2HK, 0, m, &cVar_vjh6g2HK_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_vjh6g2HK, 0, m, &cVar_vjh6g2HK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_sSSoDqbH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qH9mj3GS, 0, m, &cSlice_qH9mj3GS_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_94QcwWn8, 0, m, &cSlice_94QcwWn8_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LBah4YZe_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5dE3ooGG_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_LBah4YZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQsXd5SD, HV_BINOP_NEQ, 0, m, &cBinop_UQsXd5SD_sendMessage);
}

void Heavy_heavy::cIf_JB8turHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Lj4gAYf5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CuZTBg8K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_vjh6g2HK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_OcZbN29Z_sendMessage);
}

void Heavy_heavy::cCast_5dE3ooGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JB8turHL, 0, m, &cIf_JB8turHL_sendMessage);
}

void Heavy_heavy::cCast_CuZTBg8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vjh6g2HK, 0, m, &cVar_vjh6g2HK_sendMessage);
}

void Heavy_heavy::cReceive_kjg23WpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RoREtCdB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_QQCdCIDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ys0R2jXo_sendMessage);
}

void Heavy_heavy::cMsg_ywLjc7Tz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lNGs7ZTm_sendMessage);
}

void Heavy_heavy::cSystem_lNGs7ZTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QQCdCIDR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_ys0R2jXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NgUIHt4N, m);
}

void Heavy_heavy::cSend_bNNEruvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_m9r0ZEvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cSend_suncw55e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cVar_8z10xsLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sSSoDqbH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_6kt50oow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ywLjc7Tz_sendMessage(_c, 0, m);
  cMsg_mMFwzCBG_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_FAwsN5bP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7RH3FX10_sendMessage);
}

void Heavy_heavy::cReceive_70qvyf4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AFqxhbzM, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7;

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
    __hv_varread_f(&sVarf_AFqxhbzM, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f);
    __hv_varread_f(&sVarf_l87uahly, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_lWfUc4Vq, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_PKeLgOOV, VOf(Bf1));
    __hv_phasor_f(&sPhasor_bmLpPQTa, VIf(Bf1), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_NgUIHt4N, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf5));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_lte_f(VIf(Bf3), VIf(Bf2), VOf(Bf7));
    __hv_and_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_gte_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

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
