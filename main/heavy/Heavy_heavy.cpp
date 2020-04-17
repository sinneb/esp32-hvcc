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
  numBytes += sPhasor_k_init(&sPhasor_gpCOrvuc, 110.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_XbIzqV3L, 220.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_RfMpZOFm, 440.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_31DsCUo0, 330.0f, sampleRate);
  numBytes += cDelay_init(this, &cDelay_mRrTD102, 100.0f);
  numBytes += sVarf_init(&sVarf_rkcPcpN9, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_5coFS8aq, 0.0f);
  numBytes += cBinop_init(&cBinop_D0Ixmn7F, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_NCme0Dva, 2000.0f);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0E5vJFtX_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_URhH3eGC_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RXWFEyRp_sendMessage);
      break;
    }
    case 0x995F2576: { // thepot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8n83OrqD_sendMessage);
      break;
    }
    case 0x9F988EB1: { // thepot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yTWyTEYR_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "pot2";
        info->hash = 0xDDC4EBDB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 410.0f;
        info->defaultVal = 200.0f;
        break;
      }
      case 1: {
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
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cMsg_iNnlqfUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rkcPcpN9, m);
}

void Heavy_heavy::cCast_iwYxfyaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mRrTD102, 0, m, &cDelay_mRrTD102_sendMessage);
}

void Heavy_heavy::cDelay_mRrTD102_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mRrTD102, m);
  cMsg_8GufeVIO_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_kwkPqMkq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_6SbOg8rf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_6SbOg8rf_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_mRrTD102, 1, m, &cDelay_mRrTD102_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iwYxfyaC_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_6SbOg8rf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mRrTD102, 0, m, &cDelay_mRrTD102_sendMessage);
}

void Heavy_heavy::cReceive_URhH3eGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mONf8MAY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_PryA2evj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_yTWyTEYR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_0E5vJFtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VJldKZ0C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NCme0Dva, 0, m, &cVar_NCme0Dva_sendMessage);
  cMsg_iNnlqfUr_sendMessage(_c, 0, m);
  cSwitchcase_PoFoGAFP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_8GufeVIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_UDJzioX1_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_RXWFEyRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PryA2evj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_wNcy31Pd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xAJxXvqL_sendMessage);
}

void Heavy_heavy::cMsg_VJldKZ0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wNcy31Pd_sendMessage);
}

void Heavy_heavy::cBinop_xAJxXvqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D0Ixmn7F, HV_BINOP_MULTIPLY, 1, m, &cBinop_D0Ixmn7F_sendMessage);
}

void Heavy_heavy::cBinop_ZeC1KTqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5coFS8aq, 2, m, &cDelay_5coFS8aq_sendMessage);
}

void Heavy_heavy::cSwitchcase_PoFoGAFP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_tx65gBlZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_tx65gBlZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEUGDlid_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_5coFS8aq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5coFS8aq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5coFS8aq, 0, m, &cDelay_5coFS8aq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bW407dBt_sendMessage);
}

void Heavy_heavy::cCast_LEUGDlid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tx65gBlZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5coFS8aq, 0, m, &cDelay_5coFS8aq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bW407dBt_sendMessage);
}

void Heavy_heavy::cMsg_tx65gBlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5coFS8aq, 0, m, &cDelay_5coFS8aq_sendMessage);
}

void Heavy_heavy::cBinop_D0Ixmn7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ZeC1KTqx_sendMessage);
}

void Heavy_heavy::cVar_NCme0Dva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D0Ixmn7F, HV_BINOP_MULTIPLY, 0, m, &cBinop_D0Ixmn7F_sendMessage);
}

void Heavy_heavy::cReceive_yTWyTEYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_XbIzqV3L, 0, m);
}

void Heavy_heavy::cMsg_zNEGQLFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1024.0f);
  cSend_UDJzioX1_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_8n83OrqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_31DsCUo0, 0, m);
}

void Heavy_heavy::cSend_UDJzioX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "metrobang", 0xFB81D83A, m);
}

void Heavy_heavy::cCast_bW407dBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zNEGQLFa_sendMessage(_c, 0, m);
  cSwitchcase_kwkPqMkq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_mONf8MAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_8n83OrqD_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_FIb0fa4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PoFoGAFP_onMessage(_c, NULL, 0, m, NULL);
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
    __hv_varread_f(&sVarf_rkcPcpN9, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_gpCOrvuc, VOf(Bf0));
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
    __hv_phasor_k_f(&sPhasor_XbIzqV3L, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O2), VOf(O2));
    __hv_phasor_k_f(&sPhasor_RfMpZOFm, VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));
    __hv_phasor_k_f(&sPhasor_31DsCUo0, VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf1), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));

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
