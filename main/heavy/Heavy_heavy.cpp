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

float hTable_Kx30gaOT_data[128] = {0.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 5.0f, 7.0f, 9.0f, 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 15.0f, 15.0f, 17.0f, 17.0f, 19.0f, 21.0f, 22.0f, 22.0f, 24.0f, 26.0f, 26.0f, 27.0f, 27.0f, 29.0f, 29.0f, 31.0f, 33.0f, 34.0f, 34.0f, 36.0f, 38.0f, 38.0f, 39.0f, 39.0f, 41.0f, 41.0f, 43.0f, 45.0f, 46.0f, 46.0f, 48.0f, 50.0f, 50.0f, 51.0f, 51.0f, 53.0f, 53.0f, 55.0f, 57.0f, 58.0f, 58.0f, 60.0f, 62.0f, 62.0f, 63.0f, 63.0f, 65.0f, 65.0f, 67.0f, 69.0f, 70.0f, 70.0f, 72.0f, 74.0f, 74.0f, 75.0f, 75.0f, 77.0f, 77.0f, 79.0f, 81.0f, 82.0f, 82.0f, 84.0f, 86.0f, 86.0f, 87.0f, 87.0f, 89.0f, 89.0f, 91.0f, 93.0f, 94.0f, 94.0f, 96.0f, 98.0f, 98.0f, 99.0f, 99.0f, 101.0f, 101.0f, 103.0f, 105.0f, 106.0f, 106.0f, 108.0f, 110.0f, 110.0f, 111.0f, 111.0f, 113.0f, 113.0f, 115.0f, 117.0f, 118.0f, 118.0f, 120.0f, 122.0f, 122.0f, 123.0f, 123.0f, 125.0f, 125.0f, 127.0f, 129.0f, 130.0f, 130.0f, 132.0f, 134.0f, 134.0f, 135.0f, 135.0f, 137.0f, 0.0f};
float hTable_IFkUGZIz_data[128] = {0.0f, 2.0f, 2.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f, 11.0f, 11.0f, 12.0f, 14.0f, 14.0f, 16.0f, 16.0f, 17.0f, 17.0f, 19.0f, 21.0f, 23.0f, 23.0f, 24.0f, 26.0f, 26.0f, 28.0f, 28.0f, 29.0f, 29.0f, 31.0f, 33.0f, 35.0f, 35.0f, 36.0f, 38.0f, 38.0f, 40.0f, 40.0f, 41.0f, 41.0f, 43.0f, 45.0f, 47.0f, 47.0f, 48.0f, 50.0f, 50.0f, 52.0f, 52.0f, 53.0f, 53.0f, 55.0f, 57.0f, 59.0f, 59.0f, 60.0f, 62.0f, 62.0f, 64.0f, 64.0f, 65.0f, 65.0f, 67.0f, 69.0f, 71.0f, 71.0f, 72.0f, 74.0f, 74.0f, 76.0f, 76.0f, 77.0f, 77.0f, 79.0f, 81.0f, 83.0f, 83.0f, 84.0f, 86.0f, 86.0f, 88.0f, 88.0f, 89.0f, 89.0f, 91.0f, 93.0f, 95.0f, 95.0f, 96.0f, 98.0f, 98.0f, 100.0f, 100.0f, 101.0f, 101.0f, 103.0f, 105.0f, 107.0f, 107.0f, 108.0f, 110.0f, 110.0f, 112.0f, 112.0f, 113.0f, 113.0f, 115.0f, 117.0f, 119.0f, 119.0f, 120.0f, 122.0f, 122.0f, 124.0f, 124.0f, 125.0f, 125.0f, 127.0f, 129.0f, 131.0f, 131.0f, 132.0f, 134.0f, 134.0f, 136.0f, 136.0f, 137.0f, 0.0f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_b5nAZ8WN, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_2MelNO5m);
  numBytes += sPhasor_k_init(&sPhasor_Hbrrr06g, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_6JIITBP5);
  numBytes += sPhasor_init(&sPhasor_lYxH2dr9, sampleRate);
  numBytes += sDel1_init(&sDel1_CMdvMF5O);
  numBytes += sSamphold_init(&sSamphold_eGG8cBcf);
  numBytes += sRPole_init(&sRPole_N7cgAtMm);
  numBytes += sSample_init(&sSample_CB20OR4L);
  numBytes += sRPole_init(&sRPole_RR5GAOrc);
  numBytes += sLine_init(&sLine_ZwWY59RX);
  numBytes += sPhasor_init(&sPhasor_005CXTPC, sampleRate);
  numBytes += sLine_init(&sLine_b3PxFJhK);
  numBytes += sPhasor_init(&sPhasor_yX3wGsRV, sampleRate);
  numBytes += sLine_init(&sLine_CaGyMHbz);
  numBytes += sPhasor_init(&sPhasor_g3BETxNw, sampleRate);
  numBytes += sLine_init(&sLine_QZt9JBv5);
  numBytes += sLine_init(&sLine_9evs4JXh);
  numBytes += sTabhead_init(&sTabhead_c5UdDxWI, &hTable_9fSdilL2);
  numBytes += sTabread_init(&sTabread_hvxwJBQZ, &hTable_9fSdilL2, false);
  numBytes += sTabread_init(&sTabread_IRWJMgLq, &hTable_9fSdilL2, false);
  numBytes += sRPole_init(&sRPole_UbQqrgmW);
  numBytes += sTabwrite_init(&sTabwrite_EAiT1jOi, &hTable_Nm5tuKQC);
  numBytes += sTabhead_init(&sTabhead_zq8lQ4b2, &hTable_Nm5tuKQC);
  numBytes += sTabread_init(&sTabread_iQkWA8EO, &hTable_Nm5tuKQC, false);
  numBytes += sTabread_init(&sTabread_zzLJYd9x, &hTable_Nm5tuKQC, false);
  numBytes += sRPole_init(&sRPole_q6GgpS9j);
  numBytes += sTabwrite_init(&sTabwrite_AeCTFMoC, &hTable_9fSdilL2);
  numBytes += cBinop_init(&cBinop_UvnhZhr5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_QpWrxRlM, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_CxDYoDLd, 0.0f);
  numBytes += cVar_init_f(&cVar_9wE2wZD6, 1000.0f);
  numBytes += cVar_init_f(&cVar_oCui7N0u, 2000.0f);
  numBytes += cVar_init_f(&cVar_Q7nTJE4F, 1.0f);
  numBytes += cIf_init(&cIf_H6OsAmJt, false);
  numBytes += cVar_init_f(&cVar_H57aItZ3, 0.0f);
  numBytes += cVar_init_f(&cVar_aIhDdR0z, 0.0f);
  numBytes += cDelay_init(this, &cDelay_epv0PDgt, 20.0f);
  numBytes += cVar_init_f(&cVar_vtzKAjY4, 1.0f);
  numBytes += cVar_init_f(&cVar_0ErG23Py, 1.0f);
  numBytes += cBinop_init(&cBinop_yb0kscMs, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_9C5YwtJc, 0.0f);
  numBytes += cVar_init_f(&cVar_uV7dUTwu, 0.0f);
  numBytes += cVar_init_s(&cVar_tpVe4nph, "minor_scale");
  numBytes += cBinop_init(&cBinop_t7ZBk20V, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_uYFbygc6, 1, -1);
  numBytes += cTabread_init(&cTabread_D9mqQAwK, &hTable_Kx30gaOT); // minor_scale
  numBytes += cVar_init_f(&cVar_9Z9WXVkr, 0.0f);
  numBytes += cVar_init_f(&cVar_ToDfQcLB, 0.0f);
  numBytes += cBinop_init(&cBinop_a1dxAM2D, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_rEIuwRla, 0.0f);
  numBytes += cIf_init(&cIf_TzQTjj1v, false);
  numBytes += cIf_init(&cIf_AKxAGoxe, true);
  numBytes += cBinop_init(&cBinop_fdC6XLFu, -1.0f); // __add
  numBytes += cIf_init(&cIf_dFAOlpdX, false);
  numBytes += cIf_init(&cIf_OVso049F, true);
  numBytes += cBinop_init(&cBinop_ccS1Mbfg, 16.0f); // __add
  numBytes += cIf_init(&cIf_TfXLF4fC, true);
  numBytes += cBinop_init(&cBinop_MymwubhE, 8.0f); // __add
  numBytes += cIf_init(&cIf_jc0L3AxB, false);
  numBytes += cVar_init_f(&cVar_9UjSM6Be, 1.0f);
  numBytes += cVar_init_f(&cVar_6kYahgzU, 1.0f);
  numBytes += cVar_init_f(&cVar_ZmnFC8rZ, 0.0f);
  numBytes += cVar_init_f(&cVar_PytVnCCm, 0.0f);
  numBytes += cVar_init_f(&cVar_uhgTXZvq, 0.0f);
  numBytes += cVar_init_f(&cVar_JPZNNeOc, 1.0f);
  numBytes += cVar_init_f(&cVar_OlouO5Lc, 0.0f);
  numBytes += cVar_init_f(&cVar_73uG7yYL, 0.0f);
  numBytes += cSlice_init(&cSlice_zS0v2T4r, 3, 1);
  numBytes += cSlice_init(&cSlice_5TWd224x, 4, 1);
  numBytes += cSlice_init(&cSlice_VOd1WGkq, 1, 1);
  numBytes += cSlice_init(&cSlice_8CaWLNR7, 0, 1);
  numBytes += cSlice_init(&cSlice_KyYXLwwk, 2, 1);
  numBytes += cVar_init_f(&cVar_8jqFmQiO, 0.0f);
  numBytes += cVar_init_f(&cVar_WyJ5YzQF, 0.0f);
  numBytes += cVar_init_f(&cVar_fy5kWJDz, 0.0f);
  numBytes += cIf_init(&cIf_YWKMiRJT, false);
  numBytes += cVar_init_f(&cVar_0K6BmE5E, 0.0f);
  numBytes += cVar_init_f(&cVar_f9T5SeFW, 1.0f);
  numBytes += cIf_init(&cIf_iUoq4O6I, true);
  numBytes += cBinop_init(&cBinop_vnskNDyD, 2.0f); // __add
  numBytes += cIf_init(&cIf_nrezRk7Y, false);
  numBytes += cBinop_init(&cBinop_LKaYhJAu, 0.0f); // __add
  numBytes += cIf_init(&cIf_Xes5JctW, false);
  numBytes += cIf_init(&cIf_OFxnuEQE, true);
  numBytes += cVar_init_f(&cVar_kwPFitDv, 1.0f);
  numBytes += cDelay_init(this, &cDelay_aWNIkFKx, 0.0f);
  numBytes += cVar_init_f(&cVar_wyYGLHWG, 250.0f);
  numBytes += cVar_init_f(&cVar_6ojyzIuj, 0.0f);
  numBytes += cSlice_init(&cSlice_Fu5YDaIu, 1, -1);
  numBytes += cSlice_init(&cSlice_9VUwkgty, 1, -1);
  numBytes += cVar_init_f(&cVar_JtLhsKgu, 0.0f);
  numBytes += cSlice_init(&cSlice_pMgfBwkU, 0, 1);
  numBytes += cSlice_init(&cSlice_7UbNvHbq, 1, 1);
  numBytes += cVar_init_f(&cVar_MgoInE2v, 0.0f);
  numBytes += cBinop_init(&cBinop_bIbd0Di7, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_5JdSgS6Z, 0.0f);
  numBytes += cBinop_init(&cBinop_rbCDk5y7, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_AP33g7da, 20.0f);
  numBytes += cBinop_init(&cBinop_QQ355z2w, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ts9tGPZj, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_gqYegqiZ, 0.0f);
  numBytes += cBinop_init(&cBinop_HHAMbxAP, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_XEMjK39C, 0.0f);
  numBytes += cBinop_init(&cBinop_hibepSXI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_20lI73RY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ZpWOHPVK, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_ecTyxRx1, 20.0f);
  numBytes += cVar_init_f(&cVar_EnFAXZup, 0.0f);
  numBytes += cBinop_init(&cBinop_KfInBqND, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_D12MObID, 0.0f);
  numBytes += cBinop_init(&cBinop_FMUJYJha, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_I8oCRHcV, 550.0f);
  numBytes += cVar_init_f(&cVar_OCUsTFDw, 850.0f);
  numBytes += cVar_init_f(&cVar_TRfgtTpK, 0.0f);
  numBytes += cVar_init_f(&cVar_FtUGHxl2, 0.0f);
  numBytes += cVar_init_f(&cVar_ib38gYHQ, 0.0f);
  numBytes += hTable_initWithData(&hTable_Kx30gaOT, 128, hTable_Kx30gaOT_data);
  numBytes += cBinop_init(&cBinop_MYVnpbNJ, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_cQMiT4vd, 0.0f);
  numBytes += cBinop_init(&cBinop_lQJgs83p, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_eLsKFmMI, "minor_scale");
  numBytes += cSlice_init(&cSlice_U1kSmPfO, 1, -1);
  numBytes += cTabread_init(&cTabread_xzd7tRRu, &hTable_Kx30gaOT); // minor_scale
  numBytes += cVar_init_f(&cVar_odstSaQ0, 0.0f);
  numBytes += cVar_init_f(&cVar_lfRZ53F2, 0.0f);
  numBytes += cVar_init_f(&cVar_k8n1xzFk, 2.0f);
  numBytes += cVar_init_f(&cVar_T8j1Gu5I, 0.0f);
  numBytes += cVar_init_f(&cVar_GIpRWERu, 0.0f);
  numBytes += cVar_init_f(&cVar_oldCuK5v, 0.0f);
  numBytes += cIf_init(&cIf_IvAcKGgE, false);
  numBytes += cBinop_init(&cBinop_tSvpJtO6, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_vNbm2ESn, 0.0f);
  numBytes += cBinop_init(&cBinop_mBEVsQmD, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_16uWELcM, 0.0f);
  numBytes += cIf_init(&cIf_epO92W03, false);
  numBytes += cVar_init_f(&cVar_oRZHpVJn, 0.0f);
  numBytes += cBinop_init(&cBinop_6q64OxXZ, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_VPItLnu6, 1.0f);
  numBytes += cVar_init_f(&cVar_lRrJb5k1, 17.0f);
  numBytes += cBinop_init(&cBinop_hPxw7ZEP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ArroMVwM, 0.0f);
  numBytes += cIf_init(&cIf_b8lQwKJY, false);
  numBytes += cBinop_init(&cBinop_c4nift2Q, 0.0f); // __sub
  numBytes += cIf_init(&cIf_PSiTdS3h, false);
  numBytes += cBinop_init(&cBinop_QMbFgCcP, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_Ov19mrxz, 0.0f);
  numBytes += cSlice_init(&cSlice_u0hMb8VP, 1, -1);
  numBytes += cSlice_init(&cSlice_KwkJLZ4P, 1, -1);
  numBytes += cBinop_init(&cBinop_SyPKdhMj, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_j8k2iX2o, 0.0f);
  numBytes += cSlice_init(&cSlice_A8cw1GCv, 1, -1);
  numBytes += cSlice_init(&cSlice_2c5Gs4wt, 1, -1);
  numBytes += cIf_init(&cIf_ookXRWES, false);
  numBytes += cVar_init_f(&cVar_T3uoYdhv, 0.0f);
  numBytes += cIf_init(&cIf_ql5zoUJs, false);
  numBytes += cBinop_init(&cBinop_Sz2k48O4, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_xsyLbTUr, 2.0f);
  numBytes += cBinop_init(&cBinop_nRsb4HgB, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_hJsO51Ky, 1.0f); // __pow
  numBytes += cPack_init(&cPack_ApJXGuFs, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_QGRBx9Yz, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_llfHZ7NK, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_LPK4oyRS, 0.0f);
  numBytes += cVar_init_f(&cVar_frFVAgxX, 0.0f);
  numBytes += cVar_init_f(&cVar_5OOkhDAz, 0.0f);
  numBytes += cBinop_init(&cBinop_7Q0pyjyX, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_Sb3dGBF2, 0.0f);
  numBytes += cVar_init_s(&cVar_at4avcr4, "minor_scale");
  numBytes += cBinop_init(&cBinop_s8fKdPrg, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_0wpEGPsq, 1, -1);
  numBytes += cTabread_init(&cTabread_s31S13Tw, &hTable_Kx30gaOT); // minor_scale
  numBytes += cVar_init_f(&cVar_GsEUWUg7, 0.0f);
  numBytes += cVar_init_f(&cVar_he4yfEGv, 13.0f);
  numBytes += cVar_init_f(&cVar_4YWvcfXM, 0.0f);
  numBytes += cVar_init_f(&cVar_JZKmH7ho, 0.0f);
  numBytes += cVar_init_f(&cVar_kFqBWNJW, 0.0f);
  numBytes += cIf_init(&cIf_zh8VyaXb, false);
  numBytes += cBinop_init(&cBinop_Mn3463RK, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_mk4xhAOV, 0.0f);
  numBytes += cVar_init_f(&cVar_p5ODS2GF, 0.0f);
  numBytes += cVar_init_f(&cVar_q2k12Hfm, 1.0f);
  numBytes += cVar_init_f(&cVar_gO8PS5Bw, 0.0f);
  numBytes += cIf_init(&cIf_Lt7Qai4k, false);
  numBytes += cIf_init(&cIf_RndhL19m, false);
  numBytes += cVar_init_f(&cVar_HOvrXvyt, 0.0f);
  numBytes += cBinop_init(&cBinop_gszDvX9h, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_NBYnoFm6, 0.0f);
  numBytes += cBinop_init(&cBinop_rmOCWJJL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Yo1HcYsz, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_qz8wEnLF, 0.0f); // __sub
  numBytes += cIf_init(&cIf_Vg2d4iO6, false);
  numBytes += cVar_init_f(&cVar_b4K7GILE, 0.0f);
  numBytes += cVar_init_f(&cVar_lX3XIYvh, 0.0f);
  numBytes += cIf_init(&cIf_ykEdvjzq, false);
  numBytes += cIf_init(&cIf_6GVSYUYq, true);
  numBytes += cIf_init(&cIf_2pkhRHVx, false);
  numBytes += cBinop_init(&cBinop_kG4N5DPk, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_HYeMjZd8, 1.0f);
  numBytes += cVar_init_f(&cVar_TMkWmDws, 1.0f);
  numBytes += cVar_init_f(&cVar_IpChYN7D, 0.0f);
  numBytes += cVar_init_f(&cVar_2cUS36T4, 1.0f);
  numBytes += cVar_init_f(&cVar_M9Of9EAW, 1.0f);
  numBytes += cIf_init(&cIf_dSsWxOHC, true);
  numBytes += cIf_init(&cIf_K6X0f6b6, false);
  numBytes += cBinop_init(&cBinop_SmhPnxhY, -1.0f); // __add
  numBytes += cSlice_init(&cSlice_fgCH1UdV, 4, 1);
  numBytes += cSlice_init(&cSlice_cG5AAzRT, 0, 1);
  numBytes += cSlice_init(&cSlice_ISGFdj2b, 3, 1);
  numBytes += cSlice_init(&cSlice_Vx6FOShH, 2, 1);
  numBytes += cSlice_init(&cSlice_PYC0FgsI, 1, 1);
  numBytes += cVar_init_f(&cVar_5NZeynvC, 1.0f);
  numBytes += cVar_init_f(&cVar_wXFJEtJe, 0.0f);
  numBytes += cBinop_init(&cBinop_oEIw258s, 2.0f); // __add
  numBytes += cIf_init(&cIf_eHKqBdKj, true);
  numBytes += cIf_init(&cIf_Q3liAkPA, false);
  numBytes += cIf_init(&cIf_KMGOOZK4, true);
  numBytes += cBinop_init(&cBinop_o53Pwtpi, 0.0f); // __add
  numBytes += cIf_init(&cIf_Wmj5aNVI, false);
  numBytes += cVar_init_f(&cVar_pRuR6fsl, 0.0f);
  numBytes += cVar_init_f(&cVar_IKJ1Bdnn, 0.0f);
  numBytes += cVar_init_f(&cVar_3rkTJYsa, 0.0f);
  numBytes += cVar_init_f(&cVar_qOgva67c, 0.0f);
  numBytes += cBinop_init(&cBinop_9bSRtVXc, 8.0f); // __add
  numBytes += cIf_init(&cIf_yqComDUc, true);
  numBytes += cIf_init(&cIf_uz2pZYru, false);
  numBytes += cVar_init_f(&cVar_ZqTBs6pT, 0.0f);
  numBytes += cVar_init_f(&cVar_lKokN0Ja, 0.0f);
  numBytes += cIf_init(&cIf_f6AjtmMJ, false);
  numBytes += cVar_init_f(&cVar_hrwapjK6, 0.0f);
  numBytes += cVar_init_f(&cVar_ob4tbwh6, 0.0f);
  numBytes += cVar_init_f(&cVar_FnLtCae6, 9.0f);
  numBytes += cBinop_init(&cBinop_iu2rGNFj, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_Be3iKc2Q, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_aMGNgFRF, 0.0f);
  numBytes += cBinop_init(&cBinop_ImQYcCRJ, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_BJbmrtgi, 0.0f);
  numBytes += cIf_init(&cIf_stiDtEXI, false);
  numBytes += cVar_init_f(&cVar_tHl9F6rp, 0.0f);
  numBytes += cIf_init(&cIf_T5ocu9mQ, false);
  numBytes += cBinop_init(&cBinop_vZ2m050N, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_3Ug5YNfj, 1.0f);
  numBytes += cVar_init_f(&cVar_Yc7MY045, 0.0f);
  numBytes += cVar_init_f(&cVar_KCjG8Q90, 0.0f);
  numBytes += cIf_init(&cIf_wXldkRCF, false);
  numBytes += cVar_init_f(&cVar_EJLNZx31, 0.0f);
  numBytes += cVar_init_f(&cVar_Ew4pOSX5, 7.0f);
  numBytes += cVar_init_f(&cVar_i15KTGOB, 0.0f);
  numBytes += hTable_initWithData(&hTable_IFkUGZIz, 128, hTable_IFkUGZIz_data);
  numBytes += cVar_init_f(&cVar_Qrq4Thyr, 48.0f);
  numBytes += cVar_init_f(&cVar_MwbR8GQO, 1.0f);
  numBytes += cVar_init_f(&cVar_FrEJj85v, 0.0f);
  numBytes += cBinop_init(&cBinop_cbKx2hdh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HK71a1EG, 3.0f);
  numBytes += cBinop_init(&cBinop_ReWBbZSh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_e8lE01iH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lKLACoOb, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6DAWsIQR, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_n91cxqYp, 3.0f);
  numBytes += sVarf_init(&sVarf_5BwL9ba5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qfayAQdA, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_L8A3uBA9, 0.0f);
  numBytes += cBinop_init(&cBinop_LwJYRrsF, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_DWcyfi9A, 0.5f);
  numBytes += cRandom_init(&cRandom_963a7O1E, -331963286);
  numBytes += cSlice_init(&cSlice_dgWkOvDY, 1, 1);
  numBytes += sVari_init(&sVari_jUR1GvoN, 0, 0, false);
  numBytes += sVarf_init(&sVarf_e3PhZ4ls, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Fz579kUX, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8A1qjlAt, 0.0f);
  numBytes += cBinop_init(&cBinop_3T6vGJU0, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_67nXGw17, 1.0f);
  numBytes += cVar_init_f(&cVar_PuMwIldQ, 0.0f);
  numBytes += cIf_init(&cIf_y62lntw3, false);
  numBytes += cIf_init(&cIf_nHMJbPu1, true);
  numBytes += cBinop_init(&cBinop_YDfxkzNq, 8.0f); // __add
  numBytes += cVar_init_f(&cVar_yqFUzuKB, 1.0f);
  numBytes += cVar_init_f(&cVar_LdeElRER, 1.0f);
  numBytes += cVar_init_f(&cVar_EDimMCJ4, 0.0f);
  numBytes += cVar_init_f(&cVar_DiEMBY6Q, 1.0f);
  numBytes += cVar_init_f(&cVar_cxWVZPrp, 0.0f);
  numBytes += cVar_init_f(&cVar_BBIXkHSk, 0.0f);
  numBytes += cVar_init_f(&cVar_a2i4NR2L, 1.0f);
  numBytes += cVar_init_f(&cVar_iy9D7JUY, 0.0f);
  numBytes += cIf_init(&cIf_yVds3xTD, false);
  numBytes += cIf_init(&cIf_fdUeuIjI, true);
  numBytes += cBinop_init(&cBinop_fBquftPT, -1.0f); // __add
  numBytes += cVar_init_f(&cVar_wlP1Lmxs, 1.0f);
  numBytes += cIf_init(&cIf_HxNpiCyD, false);
  numBytes += cVar_init_f(&cVar_LJgh9dry, 0.0f);
  numBytes += cVar_init_f(&cVar_8nVgWv8O, 0.0f);
  numBytes += cBinop_init(&cBinop_K0GEhC2x, 16.0f); // __add
  numBytes += cIf_init(&cIf_NNWiRKWC, true);
  numBytes += cIf_init(&cIf_4vZthoJo, false);
  numBytes += cVar_init_f(&cVar_OqWSK5Wj, 0.0f);
  numBytes += cVar_init_f(&cVar_Inad4e1J, 0.0f);
  numBytes += cSlice_init(&cSlice_BqqX2wS0, 0, 1);
  numBytes += cSlice_init(&cSlice_d5yby8OR, 1, 1);
  numBytes += cSlice_init(&cSlice_a2J22b1K, 4, 1);
  numBytes += cSlice_init(&cSlice_IygRLXav, 3, 1);
  numBytes += cSlice_init(&cSlice_yDPP8C1z, 2, 1);
  numBytes += cIf_init(&cIf_8gXc5LUW, true);
  numBytes += cIf_init(&cIf_VYpsOxWb, false);
  numBytes += cBinop_init(&cBinop_ToXVT85F, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_L9sQvQh7, 2.0f); // __add
  numBytes += cIf_init(&cIf_1xUtlG5w, true);
  numBytes += cIf_init(&cIf_Niaam5rU, false);
  numBytes += cVar_init_f(&cVar_UIV2jv2G, 0.0f);
  numBytes += hTable_init(&hTable_Nm5tuKQC, 256);
  numBytes += cDelay_init(this, &cDelay_Oic9VEPY, 0.0f);
  numBytes += cDelay_init(this, &cDelay_p1i5r11A, 0.0f);
  numBytes += cVar_init_f(&cVar_pq1S9iz9, 3000.0f);
  numBytes += cBinop_init(&cBinop_6BgcXMlV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_S2wDnHtF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_09SR3nTF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jsEIJpnG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HPw6Hnma, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_BxxAcZUL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_XIxfofqt, 0.0f);
  numBytes += hTable_init(&hTable_9fSdilL2, 256);
  numBytes += cBinop_init(&cBinop_jTKnbOr4, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_IskvanSJ, 0.5f);
  numBytes += cVar_init_f(&cVar_Na4JOGbG, 0.0f);
  numBytes += cVar_init_f(&cVar_vYNvg5KP, 0.0f);
  numBytes += sVarf_init(&sVarf_VGFPE0yM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9VQK4PQn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_8VTAEOzP, "del-1337-ping");
  numBytes += sVarf_init(&sVarf_AD0D96xP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tVpRsUbn, 0.0f);
  numBytes += cVar_init_f(&cVar_b3dj1G9q, 3.0f);
  numBytes += sVarf_init(&sVarf_23cq5VE4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oZxFJCO6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_kR4uKky9, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_G772OHHV, 0.7f);
  numBytes += sVarf_init(&sVarf_Jt4G8bL7, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JXAwQowM, 0.0f);
  numBytes += cVar_init_s(&cVar_td4QjZ9z, "del-1337-pong");
  numBytes += sVarf_init(&sVarf_pKkMfB1O, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8JbSv2WV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_707VPVVE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_vn5P78p9, 0.5f);
  numBytes += sVarf_init(&sVarf_bm0dVxmh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_E10rZJw1, 3000.0f);
  numBytes += cBinop_init(&cBinop_BDk7TjQ4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ffN18mS0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D8ZCGh9N, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6HYGca0m, 0.0f); // __sub
  numBytes += cIf_init(&cIf_8ak0erjy, false);
  numBytes += cVar_init_f(&cVar_1drJNYNW, 0.0f);
  numBytes += cBinop_init(&cBinop_0drYSm8N, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_jmb8aaXv, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_99IEcudf, 11.0f);
  numBytes += cIf_init(&cIf_ZLaW9DYN, false);
  numBytes += cVar_init_f(&cVar_7RVbPwFx, 0.0f);
  numBytes += cVar_init_f(&cVar_fPHCu6a8, 1.0f);
  numBytes += cVar_init_f(&cVar_byMG7DSX, 0.0f);
  numBytes += cVar_init_f(&cVar_FabiYoBd, 0.0f);
  numBytes += cIf_init(&cIf_1GRGwoQJ, false);
  numBytes += cVar_init_f(&cVar_hnfya8fk, 0.0f);
  numBytes += cVar_init_f(&cVar_H9qcBYk9, 0.0f);
  numBytes += cVar_init_f(&cVar_R4efRek9, 5.0f);
  numBytes += cBinop_init(&cBinop_bmRHMQQe, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3itl0QaI, 0.0f);
  numBytes += cVar_init_f(&cVar_aLVHS86O, 0.0f);
  numBytes += cIf_init(&cIf_hUu2fQ5v, false);
  numBytes += cBinop_init(&cBinop_8VmyJxBs, 0.0f); // __lt
  numBytes += cSlice_init(&cSlice_hYixEqrA, 1, -1);
  numBytes += cSlice_init(&cSlice_TC0ilSVg, 1, -1);
  numBytes += cIf_init(&cIf_wF7Hx9ck, false);
  numBytes += cBinop_init(&cBinop_qY9yIxWN, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_dCgGYSuL, 0.0f);
  numBytes += cVar_init_f(&cVar_boGxRIh2, 0.0f);
  numBytes += cVar_init_f(&cVar_TkXcPm95, 0.0f);
  numBytes += cBinop_init(&cBinop_HaskwrCA, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_VVlyuvHt, 0.0f);
  numBytes += cIf_init(&cIf_atYfweyV, false);
  numBytes += cVar_init_f(&cVar_10rWvkrG, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_Kx30gaOT);
  cPack_free(&cPack_ApJXGuFs);
  cPack_free(&cPack_QGRBx9Yz);
  cPack_free(&cPack_llfHZ7NK);
  hTable_free(&hTable_IFkUGZIz);
  hTable_free(&hTable_Nm5tuKQC);
  hTable_free(&hTable_9fSdilL2);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x4F3833AF: return &hTable_Nm5tuKQC; // del-1337-pong
    case 0x4D17F050: return &hTable_Kx30gaOT; // minor_scale
    case 0x41D1A08F: return &hTable_9fSdilL2; // del-1337-ping
    case 0xBBA21A19: return &hTable_IFkUGZIz; // major_scale
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xC440C54F: { // Channel-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mEn228S2_sendMessage);
      break;
    }
    case 0xB762BB42: { // Channel-B
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WbD8dQRj_sendMessage);
      break;
    }
    case 0x27D89CD5: { // Channel-C
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ATsUAjQw_sendMessage);
      break;
    }
    case 0x8A3BA78B: { // 1001-hier
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tK2A1AyP_sendMessage);
      break;
    }
    case 0x17512476: { // 1001-intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_P0vKXfiI_sendMessage);
      break;
    }
    case 0xD52A3BF1: { // 1001-mastertempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wAE5F7pt_sendMessage);
      break;
    }
    case 0x8CF5567: { // 1001-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AjV2a2iV_sendMessage);
      break;
    }
    case 0x8CC8BA58: { // 1001-transpose
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NJmMgdzZ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6tYLiPHd_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
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
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cBinop_kdHyqIRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PytVnCCm, 0, m, &cVar_PytVnCCm_sendMessage);
}

void Heavy_heavy::cReceive_AjV2a2iV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4000.0f, 0, m, &cBinop_bBB47PkD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_ckCXddNq_sendMessage);
}

void Heavy_heavy::cCast_YrPBe1fe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UvnhZhr5, HV_BINOP_DIVIDE, 1, m, &cBinop_UvnhZhr5_sendMessage);
}

void Heavy_heavy::cBinop_x3Zbxpdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_UvnhZhr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Hbrrr06g, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_b5nAZ8WN, 0, m);
}

void Heavy_heavy::cBinop_QpWrxRlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_JqlhzgaR_sendMessage);
}

void Heavy_heavy::cDelay_CxDYoDLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CxDYoDLd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CxDYoDLd, 0, m, &cDelay_CxDYoDLd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D58qizgX_sendMessage);
}

void Heavy_heavy::cVar_9wE2wZD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QpWrxRlM, HV_BINOP_MULTIPLY, 0, m, &cBinop_QpWrxRlM_sendMessage);
}

void Heavy_heavy::cMsg_el4hvMhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WwY5BSdk_sendMessage);
}

void Heavy_heavy::cSystem_WwY5BSdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A1KjQSzu_sendMessage);
}

void Heavy_heavy::cMsg_IUjT8YQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CxDYoDLd, 0, m, &cDelay_CxDYoDLd_sendMessage);
}

void Heavy_heavy::cBinop_A1KjQSzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QpWrxRlM, HV_BINOP_MULTIPLY, 1, m, &cBinop_QpWrxRlM_sendMessage);
}

void Heavy_heavy::cSwitchcase_afkeM7Lw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_IUjT8YQ9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_IUjT8YQ9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gC1CwXrv_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_gC1CwXrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IUjT8YQ9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CxDYoDLd, 0, m, &cDelay_CxDYoDLd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D58qizgX_sendMessage);
}

void Heavy_heavy::cBinop_JqlhzgaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CxDYoDLd, 2, m, &cDelay_CxDYoDLd_sendMessage);
}

void Heavy_heavy::cVar_oCui7N0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aIhDdR0z, 0, m, &cVar_aIhDdR0z_sendMessage);
}

void Heavy_heavy::cBinop_xu8roDO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_lSB499Il_sendMessage);
}

void Heavy_heavy::cCast_HFLKCtro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ltb1Iqs2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Ur1oCz8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_xu8roDO2_sendMessage);
}

void Heavy_heavy::cBinop_Yt1cAX0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_x3Zbxpdl_sendMessage);
}

void Heavy_heavy::sSample_2MelNO5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ur1oCz8O_sendMessage);
}

void Heavy_heavy::cMsg_ltb1Iqs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UvnhZhr5, HV_BINOP_DIVIDE, 0, m, &cBinop_UvnhZhr5_sendMessage);
}

void Heavy_heavy::cBinop_aIddBAEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YrPBe1fe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HFLKCtro_sendMessage);
}

void Heavy_heavy::cVar_Q7nTJE4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jhO68yjT_sendMessage);
  cSwitchcase_RVFNONGi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_jhO68yjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Q7nTJE4F, 1, m, &cVar_Q7nTJE4F_sendMessage);
}

void Heavy_heavy::cIf_H6OsAmJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_SUkYR7yV_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YyPruBfo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_SUkYR7yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_H57aItZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_21etzleR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_H6OsAmJt, 0, m, &cIf_H6OsAmJt_sendMessage);
}

void Heavy_heavy::cUnop_YyPruBfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_21etzleR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_H6OsAmJt, 1, m, &cIf_H6OsAmJt_sendMessage);
}

void Heavy_heavy::cVar_aIhDdR0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aIddBAEI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9wE2wZD6, 0, m, &cVar_9wE2wZD6_sendMessage);
  cSwitchcase_hQC9eAph_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_H57aItZ3, 1, m, &cVar_H57aItZ3_sendMessage);
}

void Heavy_heavy::cCast_D58qizgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4YWvcfXM, 0, m, &cVar_4YWvcfXM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oRZHpVJn, 0, m, &cVar_oRZHpVJn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H9qcBYk9, 0, m, &cVar_H9qcBYk9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_i15KTGOB, 0, m, &cVar_i15KTGOB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0FEq0nbU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DJGgfsyY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b4K7GILE, 0, m, &cVar_b4K7GILE_sendMessage);
}

void Heavy_heavy::cSwitchcase_hQC9eAph_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_W9n3xfzG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_W9n3xfzG_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_epv0PDgt, 1, m, &cDelay_epv0PDgt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1S22nfBy_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_W9n3xfzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_epv0PDgt, 0, m, &cDelay_epv0PDgt_sendMessage);
}

void Heavy_heavy::cCast_1S22nfBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_epv0PDgt, 0, m, &cDelay_epv0PDgt_sendMessage);
}

void Heavy_heavy::cDelay_epv0PDgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_epv0PDgt, m);
  cVar_onMessage(_c, &Context(_c)->cVar_H57aItZ3, 0, m, &cVar_H57aItZ3_sendMessage);
}

void Heavy_heavy::cBinop_8D4nG32w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vtzKAjY4, 1, m, &cVar_vtzKAjY4_sendMessage);
}

void Heavy_heavy::cVar_vtzKAjY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8D4nG32w_sendMessage);
  cSwitchcase_afkeM7Lw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_9FTDqfl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9C5YwtJc, 2, m, &cDelay_9C5YwtJc_sendMessage);
}

void Heavy_heavy::cCast_IGYw5nGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rs1VKUCi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9C5YwtJc, 0, m, &cDelay_9C5YwtJc_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_2MelNO5m, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_6JIITBP5, 1, m);
}

void Heavy_heavy::cSystem_nEIecz2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lyDywCjM_sendMessage);
}

void Heavy_heavy::cMsg_VzY0vKuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nEIecz2p_sendMessage);
}

void Heavy_heavy::cSwitchcase_RVFNONGi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Rs1VKUCi_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Rs1VKUCi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IGYw5nGx_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_Rs1VKUCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9C5YwtJc, 0, m, &cDelay_9C5YwtJc_sendMessage);
}

void Heavy_heavy::cBinop_lyDywCjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yb0kscMs, HV_BINOP_MULTIPLY, 1, m, &cBinop_yb0kscMs_sendMessage);
}

void Heavy_heavy::cVar_0ErG23Py_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yb0kscMs, HV_BINOP_MULTIPLY, 0, m, &cBinop_yb0kscMs_sendMessage);
}

void Heavy_heavy::cBinop_yb0kscMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9FTDqfl9_sendMessage);
}

void Heavy_heavy::cDelay_9C5YwtJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9C5YwtJc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9C5YwtJc, 0, m, &cDelay_9C5YwtJc_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_2MelNO5m, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_6JIITBP5, 1, m);
}

void Heavy_heavy::sSample_6JIITBP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Yt1cAX0d_sendMessage);
}

void Heavy_heavy::cVar_uV7dUTwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HaskwrCA, HV_BINOP_MULTIPLY, 1, m, &cBinop_HaskwrCA_sendMessage);
}

void Heavy_heavy::cCast_tcgBU2R5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EaGdrKVO_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_HoF5Sw9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K6X0f6b6, 0, m, &cIf_K6X0f6b6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dSsWxOHC, 0, m, &cIf_dSsWxOHC_sendMessage);
}

void Heavy_heavy::cSend_QAgheVIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wAE5F7pt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_ZqpfFpHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frFVAgxX, 0, m, &cVar_frFVAgxX_sendMessage);
}

void Heavy_heavy::cSend_y15RF4hL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_P0vKXfiI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_M4ZX6olN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t7ZBk20V, HV_BINOP_MIN, 0, m, &cBinop_t7ZBk20V_sendMessage);
}

void Heavy_heavy::cMsg_yzxNI0Jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AgfkKJbk_sendMessage);
}

void Heavy_heavy::cVar_tpVe4nph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yzxNI0Jq_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_oTsfi7tJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_M4ZX6olN_sendMessage);
}

void Heavy_heavy::cCast_6EH6TvOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tpVe4nph, 0, m, &cVar_tpVe4nph_sendMessage);
}

void Heavy_heavy::cBinop_t7ZBk20V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_D9mqQAwK, 0, m, &cTabread_D9mqQAwK_sendMessage);
}

void Heavy_heavy::cSwitchcase_a7wYpfsY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uYFbygc6, 0, m, &cSlice_uYFbygc6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6EH6TvOC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oTsfi7tJ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_uYFbygc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_D9mqQAwK, 1, m, &cTabread_D9mqQAwK_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_D9mqQAwK, 1, m, &cTabread_D9mqQAwK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_EscWxHTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t7ZBk20V, HV_BINOP_MIN, 1, m, &cBinop_t7ZBk20V_sendMessage);
}

void Heavy_heavy::cSystem_AgfkKJbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_EscWxHTo_sendMessage);
}

void Heavy_heavy::cTabread_D9mqQAwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1dxAM2D, HV_BINOP_ADD, 0, m, &cBinop_a1dxAM2D_sendMessage);
}

void Heavy_heavy::cVar_9Z9WXVkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ToDfQcLB, 0, m, &cVar_ToDfQcLB_sendMessage);
}

void Heavy_heavy::cCast_FTKKMg9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ksP0d8vz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_ToDfQcLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1dxAM2D, HV_BINOP_ADD, 1, m, &cBinop_a1dxAM2D_sendMessage);
}

void Heavy_heavy::cBinop_a1dxAM2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_FpuExaoa_sendMessage);
}

void Heavy_heavy::cCast_fqbQHnH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wOXAhVwY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_wOXAhVwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_a7wYpfsY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_ksP0d8vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_a7wYpfsY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_rEIuwRla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a7wYpfsY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_P0vKXfiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tbrt7eAb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y1ZICV87_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.85f, 0, m, &cBinop_vnTzsLsa_sendMessage);
}

void Heavy_heavy::cIf_TzQTjj1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fdC6XLFu, HV_BINOP_ADD, 0, m, &cBinop_fdC6XLFu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_AKxAGoxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_nrezRk7Y, 0, m, &cIf_nrezRk7Y_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_iUoq4O6I, 0, m, &cIf_iUoq4O6I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_4ZIRvvfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AKxAGoxe, 1, m, &cIf_AKxAGoxe_sendMessage);
}

void Heavy_heavy::cBinop_fdC6XLFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nrezRk7Y, 0, m, &cIf_nrezRk7Y_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iUoq4O6I, 0, m, &cIf_iUoq4O6I_sendMessage);
}

void Heavy_heavy::cIf_dFAOlpdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ccS1Mbfg, HV_BINOP_ADD, 0, m, &cBinop_ccS1Mbfg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_OVso049F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Xes5JctW, 0, m, &cIf_Xes5JctW_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_OFxnuEQE, 0, m, &cIf_OFxnuEQE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ccS1Mbfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Xes5JctW, 0, m, &cIf_Xes5JctW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_OFxnuEQE, 0, m, &cIf_OFxnuEQE_sendMessage);
}

void Heavy_heavy::cBinop_qhUvC1nV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OVso049F, 1, m, &cIf_OVso049F_sendMessage);
}

void Heavy_heavy::cIf_TfXLF4fC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_dFAOlpdX, 0, m, &cIf_dFAOlpdX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_OVso049F, 0, m, &cIf_OVso049F_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_MymwubhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dFAOlpdX, 0, m, &cIf_dFAOlpdX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_OVso049F, 0, m, &cIf_OVso049F_sendMessage);
}

void Heavy_heavy::cBinop_EEj2tilP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TfXLF4fC, 1, m, &cIf_TfXLF4fC_sendMessage);
}

void Heavy_heavy::cIf_jc0L3AxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MymwubhE, HV_BINOP_ADD, 0, m, &cBinop_MymwubhE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_9UjSM6Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_M46beKnV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qhUvC1nV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dFAOlpdX, 1, m, &cIf_dFAOlpdX_sendMessage);
}

void Heavy_heavy::cBinop_M46beKnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9UjSM6Be, 1, m, &cVar_9UjSM6Be_sendMessage);
}

void Heavy_heavy::cVar_6kYahgzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YjBBLFK3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4ZIRvvfr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TzQTjj1v, 1, m, &cIf_TzQTjj1v_sendMessage);
}

void Heavy_heavy::cBinop_YjBBLFK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6kYahgzU, 1, m, &cVar_6kYahgzU_sendMessage);
}

void Heavy_heavy::cVar_ZmnFC8rZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6kYahgzU, 0, m, &cVar_6kYahgzU_sendMessage);
}

void Heavy_heavy::cVar_PytVnCCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fy5kWJDz, 0, m, &cVar_fy5kWJDz_sendMessage);
}

void Heavy_heavy::cVar_uhgTXZvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LKaYhJAu, HV_BINOP_ADD, 1, m, &cBinop_LKaYhJAu_sendMessage);
}

void Heavy_heavy::cBinop_rvMEYHHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JPZNNeOc, 1, m, &cVar_JPZNNeOc_sendMessage);
}

void Heavy_heavy::cVar_JPZNNeOc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_rvMEYHHN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_lRT4K6Se_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Xes5JctW, 1, m, &cIf_Xes5JctW_sendMessage);
}

void Heavy_heavy::cVar_OlouO5Lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kwPFitDv, 0, m, &cVar_kwPFitDv_sendMessage);
}

void Heavy_heavy::cVar_73uG7yYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9UjSM6Be, 0, m, &cVar_9UjSM6Be_sendMessage);
}

void Heavy_heavy::cSlice_zS0v2T4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ccS1Mbfg, HV_BINOP_ADD, 1, m, &cBinop_ccS1Mbfg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_5TWd224x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_PytVnCCm, 0, m, &cVar_PytVnCCm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_VOd1WGkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vnskNDyD, HV_BINOP_ADD, 1, m, &cBinop_vnskNDyD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_8CaWLNR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fdC6XLFu, HV_BINOP_ADD, 1, m, &cBinop_fdC6XLFu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_KyYXLwwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MymwubhE, HV_BINOP_ADD, 1, m, &cBinop_MymwubhE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_8jqFmQiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PytVnCCm, 0, m, &cVar_PytVnCCm_sendMessage);
}

void Heavy_heavy::cVar_WyJ5YzQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JPZNNeOc, 0, m, &cVar_JPZNNeOc_sendMessage);
}

void Heavy_heavy::cUnop_dOUraJMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uhgTXZvq, 0, m, &cVar_uhgTXZvq_sendMessage);
}

void Heavy_heavy::cBinop_tvyWOGVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YWKMiRJT, 1, m, &cIf_YWKMiRJT_sendMessage);
}

void Heavy_heavy::cVar_fy5kWJDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tvyWOGVh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YWKMiRJT, 0, m, &cIf_YWKMiRJT_sendMessage);
}

void Heavy_heavy::cUnop_pm2dzHei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uhgTXZvq, 0, m, &cVar_uhgTXZvq_sendMessage);
}

void Heavy_heavy::cIf_YWKMiRJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_dOUraJMB_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pm2dzHei_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_0K6BmE5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f9T5SeFW, 0, m, &cVar_f9T5SeFW_sendMessage);
}

void Heavy_heavy::cBinop_4UM735De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f9T5SeFW, 1, m, &cVar_f9T5SeFW_sendMessage);
}

void Heavy_heavy::cVar_f9T5SeFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4UM735De_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EEj2tilP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jc0L3AxB, 1, m, &cIf_jc0L3AxB_sendMessage);
}

void Heavy_heavy::cBinop_0nJWd8oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iUoq4O6I, 1, m, &cIf_iUoq4O6I_sendMessage);
}

void Heavy_heavy::cIf_iUoq4O6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_jc0L3AxB, 0, m, &cIf_jc0L3AxB_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_TfXLF4fC, 0, m, &cIf_TfXLF4fC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_vnskNDyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jc0L3AxB, 0, m, &cIf_jc0L3AxB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TfXLF4fC, 0, m, &cIf_TfXLF4fC_sendMessage);
}

void Heavy_heavy::cIf_nrezRk7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vnskNDyD, HV_BINOP_ADD, 0, m, &cBinop_vnskNDyD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_LKaYhJAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sb3dGBF2, 0, m, &cVar_Sb3dGBF2_sendMessage);
}

void Heavy_heavy::cBinop_lRT4K6Se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OFxnuEQE, 1, m, &cIf_OFxnuEQE_sendMessage);
}

void Heavy_heavy::cIf_Xes5JctW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LKaYhJAu, HV_BINOP_ADD, 0, m, &cBinop_LKaYhJAu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_OFxnuEQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Sb3dGBF2, 0, m, &cVar_Sb3dGBF2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_kwPFitDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_XrczkuBI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0nJWd8oi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nrezRk7Y, 1, m, &cIf_nrezRk7Y_sendMessage);
}

void Heavy_heavy::cBinop_XrczkuBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kwPFitDv, 1, m, &cVar_kwPFitDv_sendMessage);
}

void Heavy_heavy::cBinop_b1RPzlg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hrwapjK6, 0, m, &cVar_hrwapjK6_sendMessage);
}

void Heavy_heavy::cBinop_vCHx9L4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VVlyuvHt, 0, m, &cVar_VVlyuvHt_sendMessage);
}

void Heavy_heavy::cReceive_mEn228S2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_b1RPzlg7_sendMessage);
}

void Heavy_heavy::cBinop_UNBWV31d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yVds3xTD, 0, m, &cIf_yVds3xTD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fdUeuIjI, 0, m, &cIf_fdUeuIjI_sendMessage);
}

void Heavy_heavy::cSend_f0N0y3Qh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NJmMgdzZ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_JL3PJotQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_aWNIkFKx, 0, m, &cDelay_aWNIkFKx_sendMessage);
}

void Heavy_heavy::cDelay_aWNIkFKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aWNIkFKx, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FtUGHxl2, 0, m, &cVar_FtUGHxl2_sendMessage);
}

void Heavy_heavy::cCast_KgSRTczs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aWNIkFKx, 0, m, &cDelay_aWNIkFKx_sendMessage);
}

void Heavy_heavy::cSwitchcase_vaaeL7XW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JL3PJotQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JL3PJotQ_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_aWNIkFKx, 1, m, &cDelay_aWNIkFKx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KgSRTczs_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_wyYGLHWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ib38gYHQ, 0, m, &cVar_ib38gYHQ_sendMessage);
}

void Heavy_heavy::cCast_GjRDvgfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FMUJYJha, HV_BINOP_ADD, 1, m, &cBinop_FMUJYJha_sendMessage);
}

void Heavy_heavy::cVar_6ojyzIuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FtUGHxl2, 1, m, &cVar_FtUGHxl2_sendMessage);
}

void Heavy_heavy::cMsg_fqfA2f18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QZt9JBv5, 0, m, NULL);
  cSwitchcase_OAcdIF0W_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_QZt9JBv5, 0, m, NULL);
  cSwitchcase_OAcdIF0W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_mfnFspak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3pZOXJpi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KfInBqND, HV_BINOP_ADD, 0, m, &cBinop_KfInBqND_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XEMjK39C, 1, m, &cVar_XEMjK39C_sendMessage);
}

void Heavy_heavy::cSlice_Fu5YDaIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mcR32Kdq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mfnFspak_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mcR32Kdq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mfnFspak_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_OAcdIF0W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9VUwkgty, 0, m, &cSlice_9VUwkgty_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Fu5YDaIu, 0, m, &cSlice_Fu5YDaIu_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xczDP01p_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7UbNvHbq, 0, m, &cSlice_7UbNvHbq_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_pMgfBwkU, 0, m, &cSlice_pMgfBwkU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gAEGAHoP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4LEUvZsD_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_9VUwkgty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_P40P1jsm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_P40P1jsm_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_XmvlH19b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZpWOHPVK, HV_BINOP_DIVIDE, 0, m, &cBinop_ZpWOHPVK_sendMessage);
}

void Heavy_heavy::cCast_NWRCDWhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hibepSXI, HV_BINOP_MULTIPLY, 0, m, &cBinop_hibepSXI_sendMessage);
}

void Heavy_heavy::cMsg_ENE1QeBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_KHpDoyqc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_AyBQPgJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ts9tGPZj, HV_BINOP_SUBTRACT, 1, m, &cBinop_ts9tGPZj_sendMessage);
}

void Heavy_heavy::cCast_9vSEtb9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MgoInE2v, 1, m, &cVar_MgoInE2v_sendMessage);
}

void Heavy_heavy::cMsg_vSTytgM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_KHpDoyqc_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KfInBqND, HV_BINOP_ADD, 1, m, &cBinop_KfInBqND_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HHAMbxAP, HV_BINOP_ADD, 1, m, &cBinop_HHAMbxAP_sendMessage);
}

void Heavy_heavy::cMsg_Dm0RqB6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_gqYegqiZ, 1, m, &cVar_gqYegqiZ_sendMessage);
}

void Heavy_heavy::cCast_6iBmwXjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j8Ovgaie_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0xPT2RyJ_sendMessage);
}

void Heavy_heavy::cCast_YaK1vAon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XEMjK39C, 0, m, &cVar_XEMjK39C_sendMessage);
}

void Heavy_heavy::cSwitchcase_vUiQkv7G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YaK1vAon_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6iBmwXjp_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cVar_JtLhsKgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ts9tGPZj, HV_BINOP_SUBTRACT, 0, m, &cBinop_ts9tGPZj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_IcMFt2w3_sendMessage);
}

void Heavy_heavy::cSlice_pMgfBwkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9vSEtb9M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KucHWefo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_7UbNvHbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NWRCDWhH_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XmvlH19b_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_MgoInE2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XEMjK39C, 0, m, &cVar_XEMjK39C_sendMessage);
}

void Heavy_heavy::cCast_xczDP01p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gqYegqiZ, 0, m, &cVar_gqYegqiZ_sendMessage);
}

void Heavy_heavy::cBinop_bIbd0Di7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AyBQPgJM_sendMessage);
}

void Heavy_heavy::cCast_KucHWefo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20lI73RY, HV_BINOP_SUBTRACT, 0, m, &cBinop_20lI73RY_sendMessage);
}

void Heavy_heavy::cMsg_IszQ9FTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5JdSgS6Z, 0, m, &cDelay_5JdSgS6Z_sendMessage);
}

void Heavy_heavy::cDelay_5JdSgS6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5JdSgS6Z, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5JdSgS6Z, 0, m, &cDelay_5JdSgS6Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JtLhsKgu, 0, m, &cVar_JtLhsKgu_sendMessage);
}

void Heavy_heavy::cBinop_SWCCWJlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rbCDk5y7, HV_BINOP_MULTIPLY, 1, m, &cBinop_rbCDk5y7_sendMessage);
}

void Heavy_heavy::cBinop_rbCDk5y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5l4MT2M7_sendMessage);
}

void Heavy_heavy::cMsg_rinfd456_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mFYTZiZe_sendMessage);
}

void Heavy_heavy::cSystem_mFYTZiZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SWCCWJlq_sendMessage);
}

void Heavy_heavy::cCast_pnQaF0xX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IszQ9FTw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5JdSgS6Z, 0, m, &cDelay_5JdSgS6Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JtLhsKgu, 0, m, &cVar_JtLhsKgu_sendMessage);
}

void Heavy_heavy::cBinop_5l4MT2M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5JdSgS6Z, 2, m, &cDelay_5JdSgS6Z_sendMessage);
}

void Heavy_heavy::cVar_AP33g7da_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rbCDk5y7, HV_BINOP_MULTIPLY, 0, m, &cBinop_rbCDk5y7_sendMessage);
}

void Heavy_heavy::cSwitchcase_KHpDoyqc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_IszQ9FTw_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_IszQ9FTw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pnQaF0xX_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_QQ355z2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KfInBqND, HV_BINOP_ADD, 1, m, &cBinop_KfInBqND_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HHAMbxAP, HV_BINOP_ADD, 1, m, &cBinop_HHAMbxAP_sendMessage);
}

void Heavy_heavy::cCast_0xPT2RyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MgoInE2v, 0, m, &cVar_MgoInE2v_sendMessage);
}

void Heavy_heavy::cCast_3pZOXJpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vSTytgM5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_ts9tGPZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JtLhsKgu, 1, m, &cVar_JtLhsKgu_sendMessage);
}

void Heavy_heavy::cVar_gqYegqiZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NWRCDWhH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XmvlH19b_sendMessage);
}

void Heavy_heavy::cBinop_HHAMbxAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XEMjK39C, 1, m, &cVar_XEMjK39C_sendMessage);
}

void Heavy_heavy::cVar_XEMjK39C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HHAMbxAP, HV_BINOP_ADD, 0, m, &cBinop_HHAMbxAP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KfInBqND, HV_BINOP_ADD, 0, m, &cBinop_KfInBqND_sendMessage);
}

void Heavy_heavy::cBinop_IcMFt2w3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vUiQkv7G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_hibepSXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QnEkb2xN_sendMessage);
}

void Heavy_heavy::cCast_gAEGAHoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ENE1QeBp_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_4CTbHOSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iuY93ofY_sendMessage);
}

void Heavy_heavy::cSystem_iuY93ofY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bIbd0Di7, HV_BINOP_MULTIPLY, 1, m, &cBinop_bIbd0Di7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hibepSXI, HV_BINOP_MULTIPLY, 1, m, &cBinop_hibepSXI_sendMessage);
}

void Heavy_heavy::cBinop_20lI73RY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QQ355z2w, HV_BINOP_DIVIDE, 0, m, &cBinop_QQ355z2w_sendMessage);
}

void Heavy_heavy::cBinop_ZpWOHPVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QQ355z2w, HV_BINOP_DIVIDE, 1, m, &cBinop_QQ355z2w_sendMessage);
}

void Heavy_heavy::cCast_mcR32Kdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P40P1jsm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_j8Ovgaie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vSTytgM5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_3VUnLS9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bIbd0Di7, HV_BINOP_MULTIPLY, 0, m, &cBinop_bIbd0Di7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZpWOHPVK, HV_BINOP_DIVIDE, 1, m, &cBinop_ZpWOHPVK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AP33g7da, 0, m, &cVar_AP33g7da_sendMessage);
}

void Heavy_heavy::cMsg_P40P1jsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_KHpDoyqc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_ecTyxRx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8YMYoHnj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_4LEUvZsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dm0RqB6h_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_O5CIYzuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3VUnLS9F_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_8YMYoHnj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O5CIYzuI_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bIbd0Di7, HV_BINOP_MULTIPLY, 0, m, &cBinop_bIbd0Di7_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZpWOHPVK, HV_BINOP_DIVIDE, 1, m, &cBinop_ZpWOHPVK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_AP33g7da, 0, m, &cVar_AP33g7da_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_EnFAXZup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20lI73RY, HV_BINOP_SUBTRACT, 1, m, &cBinop_20lI73RY_sendMessage);
}

void Heavy_heavy::cBinop_QnEkb2xN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JtLhsKgu, 1, m, &cVar_JtLhsKgu_sendMessage);
}

void Heavy_heavy::cBinop_KfInBqND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EnFAXZup, 0, m, &cVar_EnFAXZup_sendMessage);
}

void Heavy_heavy::cVar_D12MObID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1jBIA9Gg_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_FMUJYJha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aWNIkFKx, 1, m, &cDelay_aWNIkFKx_sendMessage);
}

void Heavy_heavy::cVar_I8oCRHcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TRfgtTpK, 0, m, &cVar_TRfgtTpK_sendMessage);
}

void Heavy_heavy::cCast_0FEq0nbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D12MObID, 0, m, &cVar_D12MObID_sendMessage);
}

void Heavy_heavy::cVar_OCUsTFDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6ojyzIuj, 0, m, &cVar_6ojyzIuj_sendMessage);
}

void Heavy_heavy::cMsg_1jBIA9Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QZt9JBv5, 0, m, NULL);
  cSwitchcase_OAcdIF0W_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_QZt9JBv5, 0, m, NULL);
  cSwitchcase_OAcdIF0W_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_TRfgtTpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D12MObID, 1, m, &cVar_D12MObID_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FMUJYJha, HV_BINOP_ADD, 0, m, &cBinop_FMUJYJha_sendMessage);
}

void Heavy_heavy::cVar_FtUGHxl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fqfA2f18_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_GazNMwUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FMUJYJha, HV_BINOP_ADD, 0, m, &cBinop_FMUJYJha_sendMessage);
}

void Heavy_heavy::cCast_DJGgfsyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vaaeL7XW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_ib38gYHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GjRDvgfQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GazNMwUm_sendMessage);
}

void Heavy_heavy::hTable_Kx30gaOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_NJmMgdzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_CKDKBOsl_sendMessage);
}

void Heavy_heavy::cBinop_MYVnpbNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_n3zd9Qzj_sendMessage);
}

void Heavy_heavy::cMsg_LcQqbYmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_RskrTZ1j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_cQMiT4vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_odstSaQ0, 0, m, &cVar_odstSaQ0_sendMessage);
}

void Heavy_heavy::cBinop_lQJgs83p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_xzd7tRRu, 0, m, &cTabread_xzd7tRRu_sendMessage);
}

void Heavy_heavy::cCast_BIrap6tu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eLsKFmMI, 0, m, &cVar_eLsKFmMI_sendMessage);
}

void Heavy_heavy::cBinop_MU45kQ2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQJgs83p, HV_BINOP_MIN, 1, m, &cBinop_lQJgs83p_sendMessage);
}

void Heavy_heavy::cVar_eLsKFmMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lKic23Lb_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_lKic23Lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xpsOSaZg_sendMessage);
}

void Heavy_heavy::cSwitchcase_RskrTZ1j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_U1kSmPfO, 0, m, &cSlice_U1kSmPfO_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BIrap6tu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eHqGemqk_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_U1kSmPfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xzd7tRRu, 1, m, &cTabread_xzd7tRRu_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_xzd7tRRu, 1, m, &cTabread_xzd7tRRu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_eHqGemqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VIvLdLv2_sendMessage);
}

void Heavy_heavy::cTabread_xzd7tRRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYVnpbNJ, HV_BINOP_ADD, 0, m, &cBinop_MYVnpbNJ_sendMessage);
}

void Heavy_heavy::cSystem_xpsOSaZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MU45kQ2s_sendMessage);
}

void Heavy_heavy::cBinop_VIvLdLv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQJgs83p, HV_BINOP_MIN, 0, m, &cBinop_lQJgs83p_sendMessage);
}

void Heavy_heavy::cCast_hHhQxt9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LcQqbYmv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_odstSaQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYVnpbNJ, HV_BINOP_ADD, 1, m, &cBinop_MYVnpbNJ_sendMessage);
}

void Heavy_heavy::cMsg_rlPYIoT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_RskrTZ1j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_lfRZ53F2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RskrTZ1j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_5yeMJVhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rlPYIoT5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_vnTzsLsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYNvg5KP, 0, m, &cVar_vYNvg5KP_sendMessage);
}

void Heavy_heavy::cBinop_Eu9Vn4lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BXlhF6gD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UapKLQal_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZqpfFpHP_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_VCXsBVvH_sendMessage);
}

void Heavy_heavy::cBinop_9hFcxtLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_FQEsU9bY_sendMessage);
}

void Heavy_heavy::cBinop_NlSN9Itb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_y15RF4hL_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_pZzAfZPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vgfm0RwX_sendMessage);
}

void Heavy_heavy::cSwitchcase_qfNS4o1G_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pZzAfZPD_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hVqwM6wX_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_k8n1xzFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ArroMVwM, 0, m, &cVar_ArroMVwM_sendMessage);
}

void Heavy_heavy::cVar_T8j1Gu5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tSvpJtO6, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_tSvpJtO6_sendMessage);
}

void Heavy_heavy::cVar_GIpRWERu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPxw7ZEP, HV_BINOP_MULTIPLY, 1, m, &cBinop_hPxw7ZEP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mBEVsQmD, HV_BINOP_LESS_THAN, 1, m, &cBinop_mBEVsQmD_sendMessage);
}

void Heavy_heavy::cUnop_byLg1T8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIpRWERu, 0, m, &cVar_GIpRWERu_sendMessage);
}

void Heavy_heavy::cUnop_w27fXKiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIpRWERu, 0, m, &cVar_GIpRWERu_sendMessage);
}

void Heavy_heavy::cVar_oldCuK5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tNInXE1t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IvAcKGgE, 0, m, &cIf_IvAcKGgE_sendMessage);
}

void Heavy_heavy::cIf_IvAcKGgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_byLg1T8o_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_w27fXKiP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_tNInXE1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IvAcKGgE, 1, m, &cIf_IvAcKGgE_sendMessage);
}

void Heavy_heavy::cBinop_tSvpJtO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mBEVsQmD, HV_BINOP_LESS_THAN, 0, m, &cBinop_mBEVsQmD_sendMessage);
}

void Heavy_heavy::cVar_vNbm2ESn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6q64OxXZ, HV_BINOP_ADD, 1, m, &cBinop_6q64OxXZ_sendMessage);
}

void Heavy_heavy::cBinop_mBEVsQmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qfNS4o1G_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_16uWELcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_U7fEGn32_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_epO92W03, 0, m, &cIf_epO92W03_sendMessage);
}

void Heavy_heavy::cBinop_U7fEGn32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_epO92W03, 1, m, &cIf_epO92W03_sendMessage);
}

void Heavy_heavy::cIf_epO92W03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_0u8fMY2n_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bG0uLcPV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_0u8fMY2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T8j1Gu5I, 0, m, &cVar_T8j1Gu5I_sendMessage);
}

void Heavy_heavy::cUnop_bG0uLcPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T8j1Gu5I, 0, m, &cVar_T8j1Gu5I_sendMessage);
}

void Heavy_heavy::cVar_oRZHpVJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_nVzvDgCC_sendMessage);
}

void Heavy_heavy::cBinop_6q64OxXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPxw7ZEP, HV_BINOP_MULTIPLY, 0, m, &cBinop_hPxw7ZEP_sendMessage);
}

void Heavy_heavy::cVar_VPItLnu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oldCuK5v, 0, m, &cVar_oldCuK5v_sendMessage);
}

void Heavy_heavy::cVar_lRrJb5k1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16uWELcM, 0, m, &cVar_16uWELcM_sendMessage);
}

void Heavy_heavy::cBinop_hPxw7ZEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tSvpJtO6, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_tSvpJtO6_sendMessage);
}

void Heavy_heavy::cBinop_nVzvDgCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oRZHpVJn, 1, m, &cVar_oRZHpVJn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6q64OxXZ, HV_BINOP_ADD, 0, m, &cBinop_6q64OxXZ_sendMessage);
}

void Heavy_heavy::cCast_hVqwM6wX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kwPFitDv, 0, m, &cVar_kwPFitDv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JPZNNeOc, 0, m, &cVar_JPZNNeOc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TMkWmDws, 0, m, &cVar_TMkWmDws_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wlP1Lmxs, 0, m, &cVar_wlP1Lmxs_sendMessage);
}

void Heavy_heavy::cBinop_hImUbjqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b8lQwKJY, 1, m, &cIf_b8lQwKJY_sendMessage);
}

void Heavy_heavy::cVar_ArroMVwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hImUbjqe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b8lQwKJY, 0, m, &cIf_b8lQwKJY_sendMessage);
}

void Heavy_heavy::cUnop_VXlgA6d0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vNbm2ESn, 0, m, &cVar_vNbm2ESn_sendMessage);
}

void Heavy_heavy::cUnop_7m6BHnAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vNbm2ESn, 0, m, &cVar_vNbm2ESn_sendMessage);
}

void Heavy_heavy::cIf_b8lQwKJY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_7m6BHnAH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_VXlgA6d0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_Vgfm0RwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_tK2A1AyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_10rWvkrG, 0, m, &cVar_10rWvkrG_sendMessage);
}

void Heavy_heavy::cCast_UapKLQal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frFVAgxX, 1, m, &cVar_frFVAgxX_sendMessage);
}

void Heavy_heavy::cCast_4fFdqRPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4nift2Q, HV_BINOP_SUBTRACT, 1, m, &cBinop_c4nift2Q_sendMessage);
}

void Heavy_heavy::cBinop_c4nift2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oCui7N0u, 0, m, &cVar_oCui7N0u_sendMessage);
  cSend_QAgheVIm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_ATsUAjQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_vCHx9L4Q_sendMessage);
}

void Heavy_heavy::cBinop_ufsd7lOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 3.0f, 0, m, &cBinop_kdHyqIRZ_sendMessage);
}

void Heavy_heavy::cReceive_wAE5F7pt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_1ytdfwrK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_H2dloyKZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_Lbuww5sY_sendMessage);
}

void Heavy_heavy::cBinop_VCXsBVvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LPK4oyRS, 0, m, &cVar_LPK4oyRS_sendMessage);
}

void Heavy_heavy::cCast_fY3E87lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QMbFgCcP, HV_BINOP_NEQ, 0, m, &cBinop_QMbFgCcP_sendMessage);
}

void Heavy_heavy::cIf_PSiTdS3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nYGC3IHm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0A4nHbpo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_0A4nHbpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ov19mrxz, 0, m, &cVar_Ov19mrxz_sendMessage);
}

void Heavy_heavy::cCast_YNzNGbMz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PSiTdS3h, 0, m, &cIf_PSiTdS3h_sendMessage);
}

void Heavy_heavy::cBinop_QMbFgCcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PSiTdS3h, 1, m, &cIf_PSiTdS3h_sendMessage);
}

void Heavy_heavy::cVar_Ov19mrxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_7bEumH6Y_sendMessage);
}

void Heavy_heavy::cCast_nYGC3IHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QMbFgCcP, HV_BINOP_NEQ, 1, m, &cBinop_QMbFgCcP_sendMessage);
}

void Heavy_heavy::cSlice_u0hMb8VP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QMbFgCcP, HV_BINOP_NEQ, 1, m, &cBinop_QMbFgCcP_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Ov19mrxz, 1, m, &cVar_Ov19mrxz_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_QMbFgCcP, HV_BINOP_NEQ, 1, m, &cBinop_QMbFgCcP_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Ov19mrxz, 1, m, &cVar_Ov19mrxz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_zJbgXjmZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KwkJLZ4P, 0, m, &cSlice_KwkJLZ4P_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u0hMb8VP, 0, m, &cSlice_u0hMb8VP_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fY3E87lx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YNzNGbMz_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_KwkJLZ4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_Ov19mrxz, 0, m, &cVar_Ov19mrxz_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Ov19mrxz, 0, m, &cVar_Ov19mrxz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cReceive_6tYLiPHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rinfd456_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AP33g7da, 0, m, &cVar_AP33g7da_sendMessage);
  cMsg_el4hvMhj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9wE2wZD6, 0, m, &cVar_9wE2wZD6_sendMessage);
  cMsg_VzY0vKuS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0ErG23Py, 0, m, &cVar_0ErG23Py_sendMessage);
  cMsg_4CTbHOSD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EnFAXZup, 0, m, &cVar_EnFAXZup_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ecTyxRx1, 0, m, &cVar_ecTyxRx1_sendMessage);
  cMsg_vD49KKen_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HK71a1EG, 0, m, &cVar_HK71a1EG_sendMessage);
  cSwitchcase_bemowd9j_onMessage(_c, NULL, 0, m, NULL);
  cMsg_yQg2N1EA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n91cxqYp, 0, m, &cVar_n91cxqYp_sendMessage);
  cMsg_bc02ru3C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_67nXGw17, 0, m, &cVar_67nXGw17_sendMessage);
  cMsg_jtmxTfma_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pq1S9iz9, 0, m, &cVar_pq1S9iz9_sendMessage);
  cMsg_ekQnuF86_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_E10rZJw1, 0, m, &cVar_E10rZJw1_sendMessage);
  cMsg_9YjIt5VX_sendMessage(_c, 0, m);
  cMsg_5N22whH3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZmnFC8rZ, 0, m, &cVar_ZmnFC8rZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OlouO5Lc, 0, m, &cVar_OlouO5Lc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0K6BmE5E, 0, m, &cVar_0K6BmE5E_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_73uG7yYL, 0, m, &cVar_73uG7yYL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WyJ5YzQF, 0, m, &cVar_WyJ5YzQF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8jqFmQiO, 0, m, &cVar_8jqFmQiO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Inad4e1J, 0, m, &cVar_Inad4e1J_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iy9D7JUY, 0, m, &cVar_iy9D7JUY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cxWVZPrp, 0, m, &cVar_cxWVZPrp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BBIXkHSk, 0, m, &cVar_BBIXkHSk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UIV2jv2G, 0, m, &cVar_UIV2jv2G_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EDimMCJ4, 0, m, &cVar_EDimMCJ4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lKokN0Ja, 0, m, &cVar_lKokN0Ja_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3rkTJYsa, 0, m, &cVar_3rkTJYsa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wXFJEtJe, 0, m, &cVar_wXFJEtJe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qOgva67c, 0, m, &cVar_qOgva67c_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pRuR6fsl, 0, m, &cVar_pRuR6fsl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZqTBs6pT, 0, m, &cVar_ZqTBs6pT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Q7nTJE4F, 0, m, &cVar_Q7nTJE4F_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oCui7N0u, 0, m, &cVar_oCui7N0u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_he4yfEGv, 0, m, &cVar_he4yfEGv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q2k12Hfm, 0, m, &cVar_q2k12Hfm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NBYnoFm6, 0, m, &cVar_NBYnoFm6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lRrJb5k1, 0, m, &cVar_lRrJb5k1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VPItLnu6, 0, m, &cVar_VPItLnu6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k8n1xzFk, 0, m, &cVar_k8n1xzFk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_99IEcudf, 0, m, &cVar_99IEcudf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fPHCu6a8, 0, m, &cVar_fPHCu6a8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R4efRek9, 0, m, &cVar_R4efRek9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FnLtCae6, 0, m, &cVar_FnLtCae6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3Ug5YNfj, 0, m, &cVar_3Ug5YNfj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ew4pOSX5, 0, m, &cVar_Ew4pOSX5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wyYGLHWG, 0, m, &cVar_wyYGLHWG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I8oCRHcV, 0, m, &cVar_I8oCRHcV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OCUsTFDw, 0, m, &cVar_OCUsTFDw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DWcyfi9A, 0, m, &cVar_DWcyfi9A_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qrq4Thyr, 0, m, &cVar_Qrq4Thyr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MwbR8GQO, 0, m, &cVar_MwbR8GQO_sendMessage);
  cMsg_dO31CMYw_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zbNPQsLE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5OOkhDAz, 0, m, &cVar_5OOkhDAz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hHhQxt9Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cQMiT4vd, 0, m, &cVar_cQMiT4vd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FTKKMg9J_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Z9WXVkr, 0, m, &cVar_9Z9WXVkr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xsyLbTUr, 0, m, &cVar_xsyLbTUr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b3dj1G9q, 0, m, &cVar_b3dj1G9q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G772OHHV, 0, m, &cVar_G772OHHV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IskvanSJ, 0, m, &cVar_IskvanSJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vn5P78p9, 0, m, &cVar_vn5P78p9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vtzKAjY4, 0, m, &cVar_vtzKAjY4_sendMessage);
  cSend_DqS8nzJu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8VTAEOzP, 0, m, &cVar_8VTAEOzP_sendMessage);
  cMsg_aH2w2ZbS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_td4QjZ9z, 0, m, &cVar_td4QjZ9z_sendMessage);
  cMsg_pNHHE7Oq_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_XoFUYg5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uV7dUTwu, 1, m, &cVar_uV7dUTwu_sendMessage);
}

void Heavy_heavy::cCast_BXlhF6gD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uV7dUTwu, 0, m, &cVar_uV7dUTwu_sendMessage);
}

void Heavy_heavy::cCast_1odSQwqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SyPKdhMj, HV_BINOP_NEQ, 0, m, &cBinop_SyPKdhMj_sendMessage);
}

void Heavy_heavy::cBinop_SyPKdhMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ookXRWES, 1, m, &cIf_ookXRWES_sendMessage);
}

void Heavy_heavy::cVar_j8k2iX2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_sRJzlNrQ_sendMessage);
}

void Heavy_heavy::cSlice_A8cw1GCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SyPKdhMj, HV_BINOP_NEQ, 1, m, &cBinop_SyPKdhMj_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_j8k2iX2o, 1, m, &cVar_j8k2iX2o_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SyPKdhMj, HV_BINOP_NEQ, 1, m, &cBinop_SyPKdhMj_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_j8k2iX2o, 1, m, &cVar_j8k2iX2o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_2c5Gs4wt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_j8k2iX2o, 0, m, &cVar_j8k2iX2o_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_j8k2iX2o, 0, m, &cVar_j8k2iX2o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_pAbm8QMd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2c5Gs4wt, 0, m, &cSlice_2c5Gs4wt_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_A8cw1GCv, 0, m, &cSlice_A8cw1GCv_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1odSQwqz_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fmT08iLh_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_Z5RqONdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j8k2iX2o, 0, m, &cVar_j8k2iX2o_sendMessage);
}

void Heavy_heavy::cCast_HTuGd9E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SyPKdhMj, HV_BINOP_NEQ, 1, m, &cBinop_SyPKdhMj_sendMessage);
}

void Heavy_heavy::cIf_ookXRWES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HTuGd9E2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z5RqONdG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_fmT08iLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ookXRWES, 0, m, &cIf_ookXRWES_sendMessage);
}

void Heavy_heavy::cSend_DqS8nzJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tK2A1AyP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_HIIPnrNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ql5zoUJs, 1, m, &cIf_ql5zoUJs_sendMessage);
}

void Heavy_heavy::cVar_T3uoYdhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_HIIPnrNB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ql5zoUJs, 0, m, &cIf_ql5zoUJs_sendMessage);
}

void Heavy_heavy::cUnop_mDIyZTAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zJbgXjmZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_3EO0YxJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zJbgXjmZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_ql5zoUJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_mDIyZTAz_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3EO0YxJh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_nqejnPsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_llfHZ7NK, 0, m, &cPack_llfHZ7NK_sendMessage);
}

void Heavy_heavy::cBinop_ujScaS4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sz2k48O4, HV_BINOP_POW, 1, m, &cBinop_Sz2k48O4_sendMessage);
  cMsg_LeRDdnxI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_FpuExaoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ujScaS4i_sendMessage);
}

void Heavy_heavy::cBinop_Sz2k48O4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_nqejnPsn_sendMessage);
}

void Heavy_heavy::cMsg_LeRDdnxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sz2k48O4, HV_BINOP_POW, 0, m, &cBinop_Sz2k48O4_sendMessage);
}

void Heavy_heavy::cVar_xsyLbTUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LPK4oyRS, 0, m, &cVar_LPK4oyRS_sendMessage);
}

void Heavy_heavy::cBinop_Zm5IJlUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nRsb4HgB, HV_BINOP_POW, 1, m, &cBinop_nRsb4HgB_sendMessage);
  cMsg_uFizvQfq_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_n3zd9Qzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Zm5IJlUE_sendMessage);
}

void Heavy_heavy::cMsg_uFizvQfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nRsb4HgB, HV_BINOP_POW, 0, m, &cBinop_nRsb4HgB_sendMessage);
}

void Heavy_heavy::cBinop_nRsb4HgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_LJxjjK4h_sendMessage);
}

void Heavy_heavy::cBinop_LJxjjK4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ApJXGuFs, 0, m, &cPack_ApJXGuFs_sendMessage);
}

void Heavy_heavy::cBinop_IJb31rp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_YHn5a4kr_sendMessage);
}

void Heavy_heavy::cMsg_8Rumdj2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJsO51Ky, HV_BINOP_POW, 0, m, &cBinop_hJsO51Ky_sendMessage);
}

void Heavy_heavy::cBinop_1c42lJXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QGRBx9Yz, 0, m, &cPack_QGRBx9Yz_sendMessage);
}

void Heavy_heavy::cBinop_YHn5a4kr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJsO51Ky, HV_BINOP_POW, 1, m, &cBinop_hJsO51Ky_sendMessage);
  cMsg_8Rumdj2y_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_hJsO51Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_1c42lJXE_sendMessage);
}

void Heavy_heavy::cPack_ApJXGuFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b3PxFJhK, 0, m, NULL);
}

void Heavy_heavy::cPack_QGRBx9Yz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZwWY59RX, 0, m, NULL);
}

void Heavy_heavy::cPack_llfHZ7NK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CaGyMHbz, 0, m, NULL);
}

void Heavy_heavy::cVar_LPK4oyRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QGRBx9Yz, 1, m, &cPack_QGRBx9Yz_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_ApJXGuFs, 1, m, &cPack_ApJXGuFs_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_llfHZ7NK, 1, m, &cPack_llfHZ7NK_sendMessage);
}

void Heavy_heavy::cVar_frFVAgxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HaskwrCA, HV_BINOP_MULTIPLY, 0, m, &cBinop_HaskwrCA_sendMessage);
}

void Heavy_heavy::cBinop_sksYXnOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OqWSK5Wj, 0, m, &cVar_OqWSK5Wj_sendMessage);
}

void Heavy_heavy::cMsg_Zxx1kF5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_NCmawWP5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_zbNPQsLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SksYuqPs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_5OOkhDAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GsEUWUg7, 0, m, &cVar_GsEUWUg7_sendMessage);
}

void Heavy_heavy::cBinop_7Q0pyjyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_IJb31rp0_sendMessage);
}

void Heavy_heavy::cVar_Sb3dGBF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NCmawWP5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_AWd02Po7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tKyq98lx_sendMessage);
}

void Heavy_heavy::cVar_at4avcr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AWd02Po7_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_berUDVAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rNhn9xBg_sendMessage);
}

void Heavy_heavy::cBinop_s8fKdPrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_s31S13Tw, 0, m, &cTabread_s31S13Tw_sendMessage);
}

void Heavy_heavy::cBinop_ny73T9jr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s8fKdPrg, HV_BINOP_MIN, 1, m, &cBinop_s8fKdPrg_sendMessage);
}

void Heavy_heavy::cBinop_rNhn9xBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s8fKdPrg, HV_BINOP_MIN, 0, m, &cBinop_s8fKdPrg_sendMessage);
}

void Heavy_heavy::cSwitchcase_NCmawWP5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0wpEGPsq, 0, m, &cSlice_0wpEGPsq_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ddhsgYWU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_berUDVAO_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_0wpEGPsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_s31S13Tw, 1, m, &cTabread_s31S13Tw_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_s31S13Tw, 1, m, &cTabread_s31S13Tw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cTabread_s31S13Tw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q0pyjyX, HV_BINOP_ADD, 0, m, &cBinop_7Q0pyjyX_sendMessage);
}

void Heavy_heavy::cCast_ddhsgYWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_at4avcr4, 0, m, &cVar_at4avcr4_sendMessage);
}

void Heavy_heavy::cSystem_tKyq98lx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ny73T9jr_sendMessage);
}

void Heavy_heavy::cMsg_SksYuqPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_NCmawWP5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_Om2svuR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zxx1kF5F_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_GsEUWUg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q0pyjyX, HV_BINOP_ADD, 1, m, &cBinop_7Q0pyjyX_sendMessage);
}

void Heavy_heavy::cVar_he4yfEGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HOvrXvyt, 0, m, &cVar_HOvrXvyt_sendMessage);
}

void Heavy_heavy::cVar_4YWvcfXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Z8AEvm8t_sendMessage);
}

void Heavy_heavy::cCast_snVUFSEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6kYahgzU, 0, m, &cVar_6kYahgzU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LdeElRER, 0, m, &cVar_LdeElRER_sendMessage);
}

void Heavy_heavy::cCast_cY1fViYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tYQ9aZ5r_sendMessage);
}

void Heavy_heavy::cSwitchcase_x2ryEvsK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cY1fViYK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_snVUFSEY_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_JZKmH7ho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmOCWJJL, HV_BINOP_MULTIPLY, 1, m, &cBinop_rmOCWJJL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gszDvX9h, HV_BINOP_LESS_THAN, 1, m, &cBinop_gszDvX9h_sendMessage);
}

void Heavy_heavy::cBinop_bcCA2yiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zh8VyaXb, 1, m, &cIf_zh8VyaXb_sendMessage);
}

void Heavy_heavy::cUnop_rto5t7gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mk4xhAOV, 0, m, &cVar_mk4xhAOV_sendMessage);
}

void Heavy_heavy::cVar_kFqBWNJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bcCA2yiB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zh8VyaXb, 0, m, &cIf_zh8VyaXb_sendMessage);
}

void Heavy_heavy::cIf_zh8VyaXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rto5t7gp_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_d5ub7Zwi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_d5ub7Zwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mk4xhAOV, 0, m, &cVar_mk4xhAOV_sendMessage);
}

void Heavy_heavy::cBinop_Mn3463RK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmOCWJJL, HV_BINOP_MULTIPLY, 0, m, &cBinop_rmOCWJJL_sendMessage);
}

void Heavy_heavy::cCast_tYQ9aZ5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_mk4xhAOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mn3463RK, HV_BINOP_ADD, 1, m, &cBinop_Mn3463RK_sendMessage);
}

void Heavy_heavy::cVar_p5ODS2GF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yo1HcYsz, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_Yo1HcYsz_sendMessage);
}

void Heavy_heavy::cVar_q2k12Hfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gO8PS5Bw, 0, m, &cVar_gO8PS5Bw_sendMessage);
}

void Heavy_heavy::cVar_gO8PS5Bw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hBI43MHj_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Lt7Qai4k, 0, m, &cIf_Lt7Qai4k_sendMessage);
}

void Heavy_heavy::cUnop_NcTuqlFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JZKmH7ho, 0, m, &cVar_JZKmH7ho_sendMessage);
}

void Heavy_heavy::cUnop_0LBUlwnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JZKmH7ho, 0, m, &cVar_JZKmH7ho_sendMessage);
}

void Heavy_heavy::cIf_Lt7Qai4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_0LBUlwnA_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NcTuqlFB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_hBI43MHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lt7Qai4k, 1, m, &cIf_Lt7Qai4k_sendMessage);
}

void Heavy_heavy::cUnop_gXCWsB8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p5ODS2GF, 0, m, &cVar_p5ODS2GF_sendMessage);
}

void Heavy_heavy::cIf_RndhL19m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_gXCWsB8f_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IgWMVFpx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_0yIVi4vU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RndhL19m, 1, m, &cIf_RndhL19m_sendMessage);
}

void Heavy_heavy::cVar_HOvrXvyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0yIVi4vU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RndhL19m, 0, m, &cIf_RndhL19m_sendMessage);
}

void Heavy_heavy::cUnop_IgWMVFpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p5ODS2GF, 0, m, &cVar_p5ODS2GF_sendMessage);
}

void Heavy_heavy::cBinop_gszDvX9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_x2ryEvsK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_NBYnoFm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kFqBWNJW, 0, m, &cVar_kFqBWNJW_sendMessage);
}

void Heavy_heavy::cBinop_Z8AEvm8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4YWvcfXM, 1, m, &cVar_4YWvcfXM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mn3463RK, HV_BINOP_ADD, 0, m, &cBinop_Mn3463RK_sendMessage);
}

void Heavy_heavy::cBinop_rmOCWJJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yo1HcYsz, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_Yo1HcYsz_sendMessage);
}

void Heavy_heavy::cBinop_Yo1HcYsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gszDvX9h, HV_BINOP_LESS_THAN, 0, m, &cBinop_gszDvX9h_sendMessage);
}

void Heavy_heavy::cBinop_qz8wEnLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.01f, 0, m, &cBinop_Eu9Vn4lv_sendMessage);
}

void Heavy_heavy::cMsg_Sv5z2daR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qz8wEnLF, HV_BINOP_SUBTRACT, 0, m, &cBinop_qz8wEnLF_sendMessage);
}

void Heavy_heavy::cBinop_CKDKBOsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_Hmd49Y7W_sendMessage);
}

void Heavy_heavy::cBinop_cETMysZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PuMwIldQ, 0, m, &cVar_PuMwIldQ_sendMessage);
}

void Heavy_heavy::cBinop_GyT5YizT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Vg2d4iO6, 1, m, &cIf_Vg2d4iO6_sendMessage);
}

void Heavy_heavy::cIf_Vg2d4iO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rPq6BOWI_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_p9XYEhrk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_p9XYEhrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TzQTjj1v, 0, m, &cIf_TzQTjj1v_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AKxAGoxe, 0, m, &cIf_AKxAGoxe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_UNBWV31d_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_HoF5Sw9e_sendMessage);
}

void Heavy_heavy::cVar_b4K7GILE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GyT5YizT_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Vg2d4iO6, 0, m, &cIf_Vg2d4iO6_sendMessage);
}

void Heavy_heavy::cUnop_rPq6BOWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TzQTjj1v, 0, m, &cIf_TzQTjj1v_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AKxAGoxe, 0, m, &cIf_AKxAGoxe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_UNBWV31d_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_HoF5Sw9e_sendMessage);
}

void Heavy_heavy::cBinop_7bEumH6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_f0N0y3Qh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_nhJDQG6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uV7dUTwu, 0, m, &cVar_uV7dUTwu_sendMessage);
}

void Heavy_heavy::cBinop_MylH5tVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ykEdvjzq, 1, m, &cIf_ykEdvjzq_sendMessage);
}

void Heavy_heavy::cUnop_JCQOjPVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IKJ1Bdnn, 0, m, &cVar_IKJ1Bdnn_sendMessage);
}

void Heavy_heavy::cUnop_7YKt4rGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IKJ1Bdnn, 0, m, &cVar_IKJ1Bdnn_sendMessage);
}

void Heavy_heavy::cVar_lX3XIYvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MylH5tVr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ykEdvjzq, 0, m, &cIf_ykEdvjzq_sendMessage);
}

void Heavy_heavy::cIf_ykEdvjzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_JCQOjPVz_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7YKt4rGZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_6GVSYUYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Wmj5aNVI, 0, m, &cIf_Wmj5aNVI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_KMGOOZK4, 0, m, &cIf_KMGOOZK4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_2pkhRHVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kG4N5DPk, HV_BINOP_ADD, 0, m, &cBinop_kG4N5DPk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_kG4N5DPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wmj5aNVI, 0, m, &cIf_Wmj5aNVI_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KMGOOZK4, 0, m, &cIf_KMGOOZK4_sendMessage);
}

void Heavy_heavy::cBinop_OVMa6HIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6GVSYUYq, 1, m, &cIf_6GVSYUYq_sendMessage);
}

void Heavy_heavy::cVar_HYeMjZd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jQ6duoVK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OVMa6HIo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2pkhRHVx, 1, m, &cIf_2pkhRHVx_sendMessage);
}

void Heavy_heavy::cBinop_jQ6duoVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HYeMjZd8, 1, m, &cVar_HYeMjZd8_sendMessage);
}

void Heavy_heavy::cVar_TMkWmDws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_eLqAvkK7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ur0uZeEP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Q3liAkPA, 1, m, &cIf_Q3liAkPA_sendMessage);
}

void Heavy_heavy::cBinop_eLqAvkK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TMkWmDws, 1, m, &cVar_TMkWmDws_sendMessage);
}

void Heavy_heavy::cVar_IpChYN7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lX3XIYvh, 0, m, &cVar_lX3XIYvh_sendMessage);
}

void Heavy_heavy::cVar_2cUS36T4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6omgj2jm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_9cDHBwQe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Wmj5aNVI, 1, m, &cIf_Wmj5aNVI_sendMessage);
}

void Heavy_heavy::cBinop_6omgj2jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2cUS36T4, 1, m, &cVar_2cUS36T4_sendMessage);
}

void Heavy_heavy::cVar_M9Of9EAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_5siSnMJ8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BCBpMGKZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_K6X0f6b6, 1, m, &cIf_K6X0f6b6_sendMessage);
}

void Heavy_heavy::cBinop_5siSnMJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M9Of9EAW, 1, m, &cVar_M9Of9EAW_sendMessage);
}

void Heavy_heavy::cIf_dSsWxOHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Q3liAkPA, 0, m, &cIf_Q3liAkPA_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_eHKqBdKj, 0, m, &cIf_eHKqBdKj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_BCBpMGKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dSsWxOHC, 1, m, &cIf_dSsWxOHC_sendMessage);
}

void Heavy_heavy::cIf_K6X0f6b6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SmhPnxhY, HV_BINOP_ADD, 0, m, &cBinop_SmhPnxhY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_SmhPnxhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q3liAkPA, 0, m, &cIf_Q3liAkPA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eHKqBdKj, 0, m, &cIf_eHKqBdKj_sendMessage);
}

void Heavy_heavy::cSlice_fgCH1UdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_IpChYN7D, 0, m, &cVar_IpChYN7D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_cG5AAzRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SmhPnxhY, HV_BINOP_ADD, 1, m, &cBinop_SmhPnxhY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_ISGFdj2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kG4N5DPk, HV_BINOP_ADD, 1, m, &cBinop_kG4N5DPk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_Vx6FOShH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9bSRtVXc, HV_BINOP_ADD, 1, m, &cBinop_9bSRtVXc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_PYC0FgsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oEIw258s, HV_BINOP_ADD, 1, m, &cBinop_oEIw258s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_5NZeynvC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Xe3zPuzT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_PZqWJJ33_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_uz2pZYru, 1, m, &cIf_uz2pZYru_sendMessage);
}

void Heavy_heavy::cBinop_Xe3zPuzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5NZeynvC, 1, m, &cVar_5NZeynvC_sendMessage);
}

void Heavy_heavy::cVar_wXFJEtJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5NZeynvC, 0, m, &cVar_5NZeynvC_sendMessage);
}

void Heavy_heavy::cBinop_oEIw258s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uz2pZYru, 0, m, &cIf_uz2pZYru_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yqComDUc, 0, m, &cIf_yqComDUc_sendMessage);
}

void Heavy_heavy::cIf_eHKqBdKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_uz2pZYru, 0, m, &cIf_uz2pZYru_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_yqComDUc, 0, m, &cIf_yqComDUc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_Q3liAkPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oEIw258s, HV_BINOP_ADD, 0, m, &cBinop_oEIw258s_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ur0uZeEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eHKqBdKj, 1, m, &cIf_eHKqBdKj_sendMessage);
}

void Heavy_heavy::cBinop_9cDHBwQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KMGOOZK4, 1, m, &cIf_KMGOOZK4_sendMessage);
}

void Heavy_heavy::cIf_KMGOOZK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_rEIuwRla, 0, m, &cVar_rEIuwRla_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_o53Pwtpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rEIuwRla, 0, m, &cVar_rEIuwRla_sendMessage);
}

void Heavy_heavy::cIf_Wmj5aNVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_o53Pwtpi, HV_BINOP_ADD, 0, m, &cBinop_o53Pwtpi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_pRuR6fsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2cUS36T4, 0, m, &cVar_2cUS36T4_sendMessage);
}

void Heavy_heavy::cVar_IKJ1Bdnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o53Pwtpi, HV_BINOP_ADD, 1, m, &cBinop_o53Pwtpi_sendMessage);
}

void Heavy_heavy::cVar_3rkTJYsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TMkWmDws, 0, m, &cVar_TMkWmDws_sendMessage);
}

void Heavy_heavy::cVar_qOgva67c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HYeMjZd8, 0, m, &cVar_HYeMjZd8_sendMessage);
}

void Heavy_heavy::cBinop_9bSRtVXc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2pkhRHVx, 0, m, &cIf_2pkhRHVx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6GVSYUYq, 0, m, &cIf_6GVSYUYq_sendMessage);
}

void Heavy_heavy::cIf_yqComDUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_2pkhRHVx, 0, m, &cIf_2pkhRHVx_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_6GVSYUYq, 0, m, &cIf_6GVSYUYq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_uz2pZYru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9bSRtVXc, HV_BINOP_ADD, 0, m, &cBinop_9bSRtVXc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_PZqWJJ33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yqComDUc, 1, m, &cIf_yqComDUc_sendMessage);
}

void Heavy_heavy::cVar_ZqTBs6pT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IpChYN7D, 0, m, &cVar_IpChYN7D_sendMessage);
}

void Heavy_heavy::cVar_lKokN0Ja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M9Of9EAW, 0, m, &cVar_M9Of9EAW_sendMessage);
}

void Heavy_heavy::cUnop_AqkYcL4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pAbm8QMd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_f6AjtmMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_1NfCLwZc_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AqkYcL4M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_1NfCLwZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pAbm8QMd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_tYmZiSfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f6AjtmMJ, 1, m, &cIf_f6AjtmMJ_sendMessage);
}

void Heavy_heavy::cVar_hrwapjK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_tYmZiSfE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_f6AjtmMJ, 0, m, &cIf_f6AjtmMJ_sendMessage);
}

void Heavy_heavy::cVar_ob4tbwh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_FnLtCae6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KCjG8Q90, 0, m, &cVar_KCjG8Q90_sendMessage);
}

void Heavy_heavy::cBinop_iu2rGNFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_kHSq8e3k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_Be3iKc2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImQYcCRJ, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_ImQYcCRJ_sendMessage);
}

void Heavy_heavy::cVar_aMGNgFRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImQYcCRJ, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_ImQYcCRJ_sendMessage);
}

void Heavy_heavy::cBinop_weA6IsKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i15KTGOB, 1, m, &cVar_i15KTGOB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vZ2m050N, HV_BINOP_ADD, 0, m, &cBinop_vZ2m050N_sendMessage);
}

void Heavy_heavy::cBinop_ImQYcCRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iu2rGNFj, HV_BINOP_LESS_THAN, 0, m, &cBinop_iu2rGNFj_sendMessage);
}

void Heavy_heavy::cCast_knXH4QZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9UjSM6Be, 0, m, &cVar_9UjSM6Be_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2cUS36T4, 0, m, &cVar_2cUS36T4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yqFUzuKB, 0, m, &cVar_yqFUzuKB_sendMessage);
}

void Heavy_heavy::cUnop_KE1sKtzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yc7MY045, 0, m, &cVar_Yc7MY045_sendMessage);
}

void Heavy_heavy::cUnop_HUV1zJ9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yc7MY045, 0, m, &cVar_Yc7MY045_sendMessage);
}

void Heavy_heavy::cVar_BJbmrtgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_f71shfDb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_stiDtEXI, 0, m, &cIf_stiDtEXI_sendMessage);
}

void Heavy_heavy::cBinop_f71shfDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_stiDtEXI, 1, m, &cIf_stiDtEXI_sendMessage);
}

void Heavy_heavy::cIf_stiDtEXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_KE1sKtzi_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HUV1zJ9O_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_0YAfRRz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T5ocu9mQ, 1, m, &cIf_T5ocu9mQ_sendMessage);
}

void Heavy_heavy::cVar_tHl9F6rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_0YAfRRz5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_T5ocu9mQ, 0, m, &cIf_T5ocu9mQ_sendMessage);
}

void Heavy_heavy::cIf_T5ocu9mQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_EKhMAMxG_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_X9xtjqDi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_EKhMAMxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EJLNZx31, 0, m, &cVar_EJLNZx31_sendMessage);
}

void Heavy_heavy::cUnop_X9xtjqDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EJLNZx31, 0, m, &cVar_EJLNZx31_sendMessage);
}

void Heavy_heavy::cBinop_vZ2m050N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Be3iKc2Q, HV_BINOP_MULTIPLY, 0, m, &cBinop_Be3iKc2Q_sendMessage);
}

void Heavy_heavy::cVar_3Ug5YNfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tHl9F6rp, 0, m, &cVar_tHl9F6rp_sendMessage);
}

void Heavy_heavy::cCast_zGPbhQon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_Yc7MY045_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vZ2m050N, HV_BINOP_ADD, 1, m, &cBinop_vZ2m050N_sendMessage);
}

void Heavy_heavy::cUnop_V8o1eWTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aMGNgFRF, 0, m, &cVar_aMGNgFRF_sendMessage);
}

void Heavy_heavy::cUnop_NYLqc67k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aMGNgFRF, 0, m, &cVar_aMGNgFRF_sendMessage);
}

void Heavy_heavy::cBinop_Py4Z54PC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wXldkRCF, 1, m, &cIf_wXldkRCF_sendMessage);
}

void Heavy_heavy::cVar_KCjG8Q90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Py4Z54PC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wXldkRCF, 0, m, &cIf_wXldkRCF_sendMessage);
}

void Heavy_heavy::cIf_wXldkRCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_V8o1eWTD_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NYLqc67k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_EJLNZx31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Be3iKc2Q, HV_BINOP_MULTIPLY, 1, m, &cBinop_Be3iKc2Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iu2rGNFj, HV_BINOP_LESS_THAN, 1, m, &cBinop_iu2rGNFj_sendMessage);
}

void Heavy_heavy::cVar_Ew4pOSX5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BJbmrtgi, 0, m, &cVar_BJbmrtgi_sendMessage);
}

void Heavy_heavy::cCast_lkKgux4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zGPbhQon_sendMessage);
}

void Heavy_heavy::cSwitchcase_kHSq8e3k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lkKgux4N_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_knXH4QZf_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_i15KTGOB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_weA6IsKB_sendMessage);
}

void Heavy_heavy::hTable_IFkUGZIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_H2dloyKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OCUsTFDw, 0, m, &cVar_OCUsTFDw_sendMessage);
}

void Heavy_heavy::cVar_Qrq4Thyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8A3uBA9, 0, m, &cVar_L8A3uBA9_sendMessage);
}

void Heavy_heavy::cMsg_dO31CMYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_188IEyIZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_MwbR8GQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FrEJj85v, 0, m, &cVar_FrEJj85v_sendMessage);
}

void Heavy_heavy::cVar_FrEJj85v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbKx2hdh, HV_BINOP_MULTIPLY, 1, m, &cBinop_cbKx2hdh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e3PhZ4ls, m);
}

void Heavy_heavy::cBinop_cbKx2hdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MVHmL0lU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_ufsd7lOE_sendMessage);
}

void Heavy_heavy::cBinop_9JKWcYSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YEUe7qTv_sendMessage);
}

void Heavy_heavy::cBinop_YEUe7qTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zfGwRKjA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e8lE01iH, m);
}

void Heavy_heavy::cVar_HK71a1EG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ReWBbZSh, HV_BINOP_MULTIPLY, 0, m, &cBinop_ReWBbZSh_sendMessage);
}

void Heavy_heavy::cMsg_xYat4ILQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sd6LbXml_sendMessage);
}

void Heavy_heavy::cBinop_ReWBbZSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9JKWcYSP_sendMessage);
}

void Heavy_heavy::cBinop_sd6LbXml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ReWBbZSh, HV_BINOP_MULTIPLY, 1, m, &cBinop_ReWBbZSh_sendMessage);
}

void Heavy_heavy::cMsg_vD49KKen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6XcvHosy_sendMessage);
}

void Heavy_heavy::cSystem_6XcvHosy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xYat4ILQ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_zfGwRKjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lKLACoOb, m);
}

void Heavy_heavy::cCast_j2k7RZqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LwJYRrsF, HV_BINOP_SUBTRACT, 1, m, &cBinop_LwJYRrsF_sendMessage);
}

void Heavy_heavy::sSample_CB20OR4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cbKx2hdh, HV_BINOP_MULTIPLY, 0, m, &cBinop_cbKx2hdh_sendMessage);
}

void Heavy_heavy::cMsg_0mOYlPkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fDu8ULp7_sendMessage);
}

void Heavy_heavy::cMsg_yQg2N1EA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TIDwGnI7_sendMessage);
}

void Heavy_heavy::cSystem_TIDwGnI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0mOYlPkn_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_6DAWsIQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_13ZURL6g_sendMessage);
}

void Heavy_heavy::cBinop_fDu8ULp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6DAWsIQR, HV_BINOP_MULTIPLY, 1, m, &cBinop_6DAWsIQR_sendMessage);
}

void Heavy_heavy::cVar_n91cxqYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6DAWsIQR, HV_BINOP_MULTIPLY, 0, m, &cBinop_6DAWsIQR_sendMessage);
}

void Heavy_heavy::cBinop_13ZURL6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DLtznGvc_sendMessage);
}

void Heavy_heavy::cBinop_DLtznGvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4jgmlqtX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5BwL9ba5, m);
}

void Heavy_heavy::cBinop_4jgmlqtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qfayAQdA, m);
}

void Heavy_heavy::cVar_L8A3uBA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j2k7RZqN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PwPI2Ia6_sendMessage);
}

void Heavy_heavy::cCast_PwPI2Ia6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TYoq4eli_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_LwJYRrsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n91cxqYp, 0, m, &cVar_n91cxqYp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HK71a1EG, 0, m, &cVar_HK71a1EG_sendMessage);
}

void Heavy_heavy::cVar_DWcyfi9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PuMwIldQ, 0, m, &cVar_PuMwIldQ_sendMessage);
}

void Heavy_heavy::cMsg_bJYACTCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_jUR1GvoN, m);
}

void Heavy_heavy::cRandom_963a7O1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_SfsvZ7hz_sendMessage);
}

void Heavy_heavy::cBinop_SfsvZ7hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_U9zFhHaK_sendMessage);
}

void Heavy_heavy::cUnop_U9zFhHaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bJYACTCW_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_bemowd9j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dgWkOvDY, 0, m, &cSlice_dgWkOvDY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_963a7O1E, 0, m, &cRandom_963a7O1E_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_dgWkOvDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_963a7O1E, 1, m, &cRandom_963a7O1E_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cMsg_TYoq4eli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.01f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LwJYRrsF, HV_BINOP_SUBTRACT, 0, m, &cBinop_LwJYRrsF_sendMessage);
}

void Heavy_heavy::cMsg_5MNqAuzv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8A1qjlAt, 0, m, &cDelay_8A1qjlAt_sendMessage);
}

void Heavy_heavy::cBinop_y0W8Xg7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8A1qjlAt, 2, m, &cDelay_8A1qjlAt_sendMessage);
}

void Heavy_heavy::cDelay_8A1qjlAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8A1qjlAt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8A1qjlAt, 0, m, &cDelay_8A1qjlAt_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_CB20OR4L, 1, m);
}

void Heavy_heavy::cCast_ybh5q82c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5MNqAuzv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8A1qjlAt, 0, m, &cDelay_8A1qjlAt_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_CB20OR4L, 1, m);
}

void Heavy_heavy::cBinop_b8bHwBc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3T6vGJU0, HV_BINOP_MULTIPLY, 1, m, &cBinop_3T6vGJU0_sendMessage);
}

void Heavy_heavy::cBinop_3T6vGJU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_y0W8Xg7S_sendMessage);
}

void Heavy_heavy::cVar_67nXGw17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3T6vGJU0, HV_BINOP_MULTIPLY, 0, m, &cBinop_3T6vGJU0_sendMessage);
}

void Heavy_heavy::cSwitchcase_188IEyIZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_5MNqAuzv_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_5MNqAuzv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ybh5q82c_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSystem_AjzDkv3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_b8bHwBc7_sendMessage);
}

void Heavy_heavy::cMsg_bc02ru3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AjzDkv3L_sendMessage);
}

void Heavy_heavy::cVar_PuMwIldQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fz579kUX, m);
}

void Heavy_heavy::cBinop_lSB499Il_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_sksYXnOm_sendMessage);
}

void Heavy_heavy::cCast_Wdzey9AG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frFVAgxX, 0, m, &cVar_frFVAgxX_sendMessage);
}

void Heavy_heavy::cIf_y62lntw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YDfxkzNq, HV_BINOP_ADD, 0, m, &cBinop_YDfxkzNq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_nHMJbPu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_4vZthoJo, 0, m, &cIf_4vZthoJo_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NNWiRKWC, 0, m, &cIf_NNWiRKWC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_YDfxkzNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4vZthoJo, 0, m, &cIf_4vZthoJo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NNWiRKWC, 0, m, &cIf_NNWiRKWC_sendMessage);
}

void Heavy_heavy::cBinop_vf9S1kkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nHMJbPu1, 1, m, &cIf_nHMJbPu1_sendMessage);
}

void Heavy_heavy::cBinop_QoJtbe2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yqFUzuKB, 1, m, &cVar_yqFUzuKB_sendMessage);
}

void Heavy_heavy::cVar_yqFUzuKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QoJtbe2c_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Rxn4NEWU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yVds3xTD, 1, m, &cIf_yVds3xTD_sendMessage);
}

void Heavy_heavy::cVar_LdeElRER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8QYgpZFz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_vf9S1kkp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_y62lntw3, 1, m, &cIf_y62lntw3_sendMessage);
}

void Heavy_heavy::cBinop_8QYgpZFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LdeElRER, 1, m, &cVar_LdeElRER_sendMessage);
}

void Heavy_heavy::cVar_EDimMCJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OqWSK5Wj, 0, m, &cVar_OqWSK5Wj_sendMessage);
}

void Heavy_heavy::cVar_DiEMBY6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_PtwMJFgT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fehrvSnh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Niaam5rU, 1, m, &cIf_Niaam5rU_sendMessage);
}

void Heavy_heavy::cBinop_PtwMJFgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DiEMBY6Q, 1, m, &cVar_DiEMBY6Q_sendMessage);
}

void Heavy_heavy::cVar_cxWVZPrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LdeElRER, 0, m, &cVar_LdeElRER_sendMessage);
}

void Heavy_heavy::cVar_BBIXkHSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a2i4NR2L, 0, m, &cVar_a2i4NR2L_sendMessage);
}

void Heavy_heavy::cBinop_vrB3Ktd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a2i4NR2L, 1, m, &cVar_a2i4NR2L_sendMessage);
}

void Heavy_heavy::cVar_a2i4NR2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_vrB3Ktd3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qtsrKDsy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4vZthoJo, 1, m, &cIf_4vZthoJo_sendMessage);
}

void Heavy_heavy::cVar_iy9D7JUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DiEMBY6Q, 0, m, &cVar_DiEMBY6Q_sendMessage);
}

void Heavy_heavy::cIf_yVds3xTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fBquftPT, HV_BINOP_ADD, 0, m, &cBinop_fBquftPT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_fdUeuIjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Niaam5rU, 0, m, &cIf_Niaam5rU_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_1xUtlG5w, 0, m, &cIf_1xUtlG5w_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Rxn4NEWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fdUeuIjI, 1, m, &cIf_fdUeuIjI_sendMessage);
}

void Heavy_heavy::cBinop_fBquftPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Niaam5rU, 0, m, &cIf_Niaam5rU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1xUtlG5w, 0, m, &cIf_1xUtlG5w_sendMessage);
}

void Heavy_heavy::cBinop_fqL4pdf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wlP1Lmxs, 1, m, &cVar_wlP1Lmxs_sendMessage);
}

void Heavy_heavy::cVar_wlP1Lmxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fqL4pdf8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IkE6o1mH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VYpsOxWb, 1, m, &cIf_VYpsOxWb_sendMessage);
}

void Heavy_heavy::cUnop_XLcXssXi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8nVgWv8O, 0, m, &cVar_8nVgWv8O_sendMessage);
}

void Heavy_heavy::cUnop_WndSsNU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8nVgWv8O, 0, m, &cVar_8nVgWv8O_sendMessage);
}

void Heavy_heavy::cBinop_aaXcLi7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HxNpiCyD, 1, m, &cIf_HxNpiCyD_sendMessage);
}

void Heavy_heavy::cIf_HxNpiCyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_WndSsNU5_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XLcXssXi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_LJgh9dry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_aaXcLi7t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HxNpiCyD, 0, m, &cIf_HxNpiCyD_sendMessage);
}

void Heavy_heavy::cVar_8nVgWv8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ToXVT85F, HV_BINOP_ADD, 1, m, &cBinop_ToXVT85F_sendMessage);
}

void Heavy_heavy::cBinop_K0GEhC2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VYpsOxWb, 0, m, &cIf_VYpsOxWb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8gXc5LUW, 0, m, &cIf_8gXc5LUW_sendMessage);
}

void Heavy_heavy::cIf_NNWiRKWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_VYpsOxWb, 0, m, &cIf_VYpsOxWb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8gXc5LUW, 0, m, &cIf_8gXc5LUW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_4vZthoJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_K0GEhC2x, HV_BINOP_ADD, 0, m, &cBinop_K0GEhC2x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_qtsrKDsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NNWiRKWC, 1, m, &cIf_NNWiRKWC_sendMessage);
}

void Heavy_heavy::cVar_OqWSK5Wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LJgh9dry, 0, m, &cVar_LJgh9dry_sendMessage);
}

void Heavy_heavy::cVar_Inad4e1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yqFUzuKB, 0, m, &cVar_yqFUzuKB_sendMessage);
}

void Heavy_heavy::cSlice_BqqX2wS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fBquftPT, HV_BINOP_ADD, 1, m, &cBinop_fBquftPT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_d5yby8OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_L9sQvQh7, HV_BINOP_ADD, 1, m, &cBinop_L9sQvQh7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_a2J22b1K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_OqWSK5Wj, 0, m, &cVar_OqWSK5Wj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_IygRLXav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_K0GEhC2x, HV_BINOP_ADD, 1, m, &cBinop_K0GEhC2x_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_yDPP8C1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_YDfxkzNq, HV_BINOP_ADD, 1, m, &cBinop_YDfxkzNq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_8gXc5LUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_lfRZ53F2, 0, m, &cVar_lfRZ53F2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_VYpsOxWb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ToXVT85F, HV_BINOP_ADD, 0, m, &cBinop_ToXVT85F_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ToXVT85F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lfRZ53F2, 0, m, &cVar_lfRZ53F2_sendMessage);
}

void Heavy_heavy::cBinop_IkE6o1mH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8gXc5LUW, 1, m, &cIf_8gXc5LUW_sendMessage);
}

void Heavy_heavy::cBinop_fehrvSnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1xUtlG5w, 1, m, &cIf_1xUtlG5w_sendMessage);
}

void Heavy_heavy::cBinop_L9sQvQh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y62lntw3, 0, m, &cIf_y62lntw3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nHMJbPu1, 0, m, &cIf_nHMJbPu1_sendMessage);
}

void Heavy_heavy::cIf_1xUtlG5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_y62lntw3, 0, m, &cIf_y62lntw3_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_nHMJbPu1, 0, m, &cIf_nHMJbPu1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_Niaam5rU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_L9sQvQh7, HV_BINOP_ADD, 0, m, &cBinop_L9sQvQh7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_UIV2jv2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wlP1Lmxs, 0, m, &cVar_wlP1Lmxs_sendMessage);
}

void Heavy_heavy::cBinop_sRJzlNrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dwKlJvR8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_tbrt7eAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qz8wEnLF, HV_BINOP_SUBTRACT, 1, m, &cBinop_qz8wEnLF_sendMessage);
}

void Heavy_heavy::cBinop_7fbIbqMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_DEMeH9zr_sendMessage);
}

void Heavy_heavy::cSystem_j772XuVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7fbIbqMk_sendMessage);
}

void Heavy_heavy::cMsg_5N22whH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j772XuVq_sendMessage);
}

void Heavy_heavy::hTable_Nm5tuKQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fGVJZgZW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oic9VEPY, 2, m, &cDelay_Oic9VEPY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zobJotrt_sendMessage);
}

void Heavy_heavy::cMsg_xCpTknsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Nm5tuKQC, 0, m, &hTable_Nm5tuKQC_sendMessage);
}

void Heavy_heavy::cBinop_DEMeH9zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xCpTknsY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_zobJotrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oic9VEPY, 0, m, &cDelay_Oic9VEPY_sendMessage);
}

void Heavy_heavy::cMsg_fGVJZgZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1i5r11A, 2, m, &cDelay_p1i5r11A_sendMessage);
}

void Heavy_heavy::cDelay_Oic9VEPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Oic9VEPY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p1i5r11A, 0, m, &cDelay_p1i5r11A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Oic9VEPY, 0, m, &cDelay_Oic9VEPY_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_EAiT1jOi, 1, m, NULL);
}

void Heavy_heavy::cMsg_CRNhFlZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Nm5tuKQC, 0, m, &hTable_Nm5tuKQC_sendMessage);
}

void Heavy_heavy::cDelay_p1i5r11A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p1i5r11A, m);
  cMsg_CRNhFlZl_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_uRoy0Iqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9evs4JXh, 0, m, NULL);
}

void Heavy_heavy::cMsg_qOmGWdYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HYGca0m, HV_BINOP_SUBTRACT, 0, m, &cBinop_6HYGca0m_sendMessage);
}

void Heavy_heavy::cVar_pq1S9iz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6BgcXMlV, HV_BINOP_MULTIPLY, 0, m, &cBinop_6BgcXMlV_sendMessage);
}

void Heavy_heavy::cBinop_672awKbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_S2wDnHtF, m);
}

void Heavy_heavy::cBinop_VlK9MQWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6BgcXMlV, HV_BINOP_MULTIPLY, 1, m, &cBinop_6BgcXMlV_sendMessage);
}

void Heavy_heavy::cMsg_mNAOcDgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VlK9MQWt_sendMessage);
}

void Heavy_heavy::cBinop_6BgcXMlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LJPbf8Af_sendMessage);
}

void Heavy_heavy::cSystem_mZg9FwuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mNAOcDgJ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_jtmxTfma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mZg9FwuX_sendMessage);
}

void Heavy_heavy::cBinop_gTdGFlXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_672awKbA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_09SR3nTF, m);
}

void Heavy_heavy::cBinop_LJPbf8Af_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gTdGFlXs_sendMessage);
}

void Heavy_heavy::cDelay_BxxAcZUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BxxAcZUL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XIxfofqt, 0, m, &cDelay_XIxfofqt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BxxAcZUL, 0, m, &cDelay_BxxAcZUL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AeCTFMoC, 1, m, NULL);
}

void Heavy_heavy::cCast_Iv8IWR9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BxxAcZUL, 0, m, &cDelay_BxxAcZUL_sendMessage);
}

void Heavy_heavy::cBinop_4KJ4S5zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f4xJOMUI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_Dv7uomkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_9fSdilL2, 0, m, &hTable_9fSdilL2_sendMessage);
}

void Heavy_heavy::cDelay_XIxfofqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XIxfofqt, m);
  cMsg_Dv7uomkX_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_nUraFjN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_XIxfofqt, 2, m, &cDelay_XIxfofqt_sendMessage);
}

void Heavy_heavy::cBinop_eZnDBFkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_4KJ4S5zz_sendMessage);
}

void Heavy_heavy::hTable_9fSdilL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nUraFjN3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BxxAcZUL, 2, m, &cDelay_BxxAcZUL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iv8IWR9M_sendMessage);
}

void Heavy_heavy::cMsg_f4xJOMUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_9fSdilL2, 0, m, &hTable_9fSdilL2_sendMessage);
}

void Heavy_heavy::cSystem_a0MAthMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eZnDBFkF_sendMessage);
}

void Heavy_heavy::cMsg_9YjIt5VX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a0MAthMe_sendMessage);
}

void Heavy_heavy::cBinop_Lbuww5sY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yTEwVwMg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iJYUZe7C_sendMessage);
}

void Heavy_heavy::cBinop_Fc92ymUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jTKnbOr4, HV_BINOP_POW, 1, m, &cBinop_jTKnbOr4_sendMessage);
  cMsg_qaDUM7WV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_qaDUM7WV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jTKnbOr4, HV_BINOP_POW, 0, m, &cBinop_jTKnbOr4_sendMessage);
}

void Heavy_heavy::cBinop_jTKnbOr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ysmPLhU8_sendMessage);
}

void Heavy_heavy::cBinop_v3CGKHWb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_Fc92ymUz_sendMessage);
}

void Heavy_heavy::cBinop_ysmPLhU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pq1S9iz9, 0, m, &cVar_pq1S9iz9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_E10rZJw1, 0, m, &cVar_E10rZJw1_sendMessage);
}

void Heavy_heavy::cCast_iJYUZe7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1drJNYNW, 0, m, &cVar_1drJNYNW_sendMessage);
}

void Heavy_heavy::cVar_IskvanSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYNvg5KP, 0, m, &cVar_vYNvg5KP_sendMessage);
}

void Heavy_heavy::cVar_Na4JOGbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_WrCoaAKG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ill08Q3Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qbEC8lA4_sendMessage);
}

void Heavy_heavy::cVar_vYNvg5KP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.99f, 0, m, &cBinop_tAaVoI91_sendMessage);
}

void Heavy_heavy::cSystem_xD8AJct4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jUnpIg0z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VGFPE0yM, m);
}

void Heavy_heavy::cVar_8VTAEOzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IUwV1GE5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_aH2w2ZbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bZEXVEM2_sendMessage);
}

void Heavy_heavy::cSystem_bZEXVEM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_09JfJUtc_sendMessage);
}

void Heavy_heavy::cBinop_09JfJUtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9VQK4PQn, m);
}

void Heavy_heavy::cBinop_jUnpIg0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AD0D96xP, m);
}

void Heavy_heavy::cMsg_IUwV1GE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xD8AJct4_sendMessage);
}

void Heavy_heavy::cUnop_Ei6aKfHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jsEIJpnG, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oZxFJCO6, m);
}

void Heavy_heavy::cVar_tVpRsUbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_EJCiTreW_sendMessage);
}

void Heavy_heavy::cVar_b3dj1G9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JXAwQowM, 0, m, &cVar_JXAwQowM_sendMessage);
}

void Heavy_heavy::cBinop_kR4uKky9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uRoy0Iqm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_EJCiTreW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_v3CGKHWb_sendMessage);
}

void Heavy_heavy::cVar_G772OHHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tVpRsUbn, 0, m, &cVar_tVpRsUbn_sendMessage);
}

void Heavy_heavy::cCast_qbEC8lA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HYGca0m, HV_BINOP_SUBTRACT, 1, m, &cBinop_6HYGca0m_sendMessage);
}

void Heavy_heavy::cCast_yTEwVwMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kR4uKky9, HV_BINOP_MULTIPLY, 1, m, &cBinop_kR4uKky9_sendMessage);
}

void Heavy_heavy::cCast_Ill08Q3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qOmGWdYC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_JXAwQowM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1drJNYNW, 0, m, &cVar_1drJNYNW_sendMessage);
}

void Heavy_heavy::cBinop_amnfmVon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_707VPVVE, m);
}

void Heavy_heavy::cMsg_ggXQOT7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SHgXuvoJ_sendMessage);
}

void Heavy_heavy::cVar_td4QjZ9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ggXQOT7X_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_pNHHE7Oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LZiS7tB6_sendMessage);
}

void Heavy_heavy::cSystem_LZiS7tB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_z7XHSLsa_sendMessage);
}

void Heavy_heavy::cSystem_SHgXuvoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_amnfmVon_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pKkMfB1O, m);
}

void Heavy_heavy::cBinop_z7XHSLsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8JbSv2WV, m);
}

void Heavy_heavy::cVar_vn5P78p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Na4JOGbG, 0, m, &cVar_Na4JOGbG_sendMessage);
}

void Heavy_heavy::cVar_E10rZJw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BDk7TjQ4, HV_BINOP_MULTIPLY, 0, m, &cBinop_BDk7TjQ4_sendMessage);
}

void Heavy_heavy::cMsg_ekQnuF86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xt2buRXx_sendMessage);
}

void Heavy_heavy::cSystem_Xt2buRXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iWPkPzMC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_iWPkPzMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LAJGeI4l_sendMessage);
}

void Heavy_heavy::cBinop_LAJGeI4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BDk7TjQ4, HV_BINOP_MULTIPLY, 1, m, &cBinop_BDk7TjQ4_sendMessage);
}

void Heavy_heavy::cBinop_BDk7TjQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cGetbAAa_sendMessage);
}

void Heavy_heavy::cBinop_cGetbAAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yVhKl11A_sendMessage);
}

void Heavy_heavy::cBinop_yVhKl11A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bn47eA9H_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bm0dVxmh, m);
}

void Heavy_heavy::cBinop_bn47eA9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ffN18mS0, m);
}

void Heavy_heavy::cUnop_WrCoaAKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HPw6Hnma, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Jt4G8bL7, m);
}

void Heavy_heavy::cBinop_6HYGca0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_Ei6aKfHc_sendMessage);
}

void Heavy_heavy::cBinop_9f0txf6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8ak0erjy, 1, m, &cIf_8ak0erjy_sendMessage);
}

void Heavy_heavy::cIf_8ak0erjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_QnEkyp8M_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jG8GhGEi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_jG8GhGEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kR4uKky9, HV_BINOP_MULTIPLY, 0, m, &cBinop_kR4uKky9_sendMessage);
}

void Heavy_heavy::cVar_1drJNYNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9f0txf6b_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8ak0erjy, 0, m, &cIf_8ak0erjy_sendMessage);
}

void Heavy_heavy::cUnop_QnEkyp8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kR4uKky9, HV_BINOP_MULTIPLY, 0, m, &cBinop_kR4uKky9_sendMessage);
}

void Heavy_heavy::cBinop_tAaVoI91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PuEVqOFC_sendMessage);
}

void Heavy_heavy::cBinop_PuEVqOFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D8ZCGh9N, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_23cq5VE4, m);
}

void Heavy_heavy::cBinop_MVHmL0lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_9hFcxtLA_sendMessage);
}

void Heavy_heavy::cReceive_WbD8dQRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_UebGa0FL_sendMessage);
}

void Heavy_heavy::cBinop_UebGa0FL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T3uoYdhv, 0, m, &cVar_T3uoYdhv_sendMessage);
}

void Heavy_heavy::cBinop_bBB47PkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4fFdqRPO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tcgBU2R5_sendMessage);
}

void Heavy_heavy::cBinop_ckCXddNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.3f, 0, m, &cBinop_cETMysZZ_sendMessage);
}

void Heavy_heavy::cCast_dwFl5ezR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_a2i4NR2L, 0, m, &cVar_a2i4NR2L_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HYeMjZd8, 0, m, &cVar_HYeMjZd8_sendMessage);
}

void Heavy_heavy::cBinop_0drYSm8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8VmyJxBs, HV_BINOP_LESS_THAN, 0, m, &cBinop_8VmyJxBs_sendMessage);
}

void Heavy_heavy::cBinop_jmb8aaXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bmRHMQQe, HV_BINOP_MULTIPLY, 0, m, &cBinop_bmRHMQQe_sendMessage);
}

void Heavy_heavy::cBinop_mqZqGgCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H9qcBYk9, 1, m, &cVar_H9qcBYk9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmb8aaXv, HV_BINOP_ADD, 0, m, &cBinop_jmb8aaXv_sendMessage);
}

void Heavy_heavy::cVar_99IEcudf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7RVbPwFx, 0, m, &cVar_7RVbPwFx_sendMessage);
}

void Heavy_heavy::cUnop_06zcp9el_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_byMG7DSX, 0, m, &cVar_byMG7DSX_sendMessage);
}

void Heavy_heavy::cUnop_3h07bsZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_byMG7DSX, 0, m, &cVar_byMG7DSX_sendMessage);
}

void Heavy_heavy::cBinop_WMicJl4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZLaW9DYN, 1, m, &cIf_ZLaW9DYN_sendMessage);
}

void Heavy_heavy::cIf_ZLaW9DYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_3h07bsZE_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_06zcp9el_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_7RVbPwFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WMicJl4s_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZLaW9DYN, 0, m, &cIf_ZLaW9DYN_sendMessage);
}

void Heavy_heavy::cVar_fPHCu6a8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aLVHS86O, 0, m, &cVar_aLVHS86O_sendMessage);
}

void Heavy_heavy::cVar_byMG7DSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0drYSm8N, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_0drYSm8N_sendMessage);
}

void Heavy_heavy::cVar_FabiYoBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bmRHMQQe, HV_BINOP_MULTIPLY, 1, m, &cBinop_bmRHMQQe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8VmyJxBs, HV_BINOP_LESS_THAN, 1, m, &cBinop_8VmyJxBs_sendMessage);
}

void Heavy_heavy::cIf_1GRGwoQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_OF3RL6Iu_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_e4ZjZ9Ec_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_e4ZjZ9Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3itl0QaI, 0, m, &cVar_3itl0QaI_sendMessage);
}

void Heavy_heavy::cBinop_CnQyv3Qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1GRGwoQJ, 1, m, &cIf_1GRGwoQJ_sendMessage);
}

void Heavy_heavy::cUnop_OF3RL6Iu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3itl0QaI, 0, m, &cVar_3itl0QaI_sendMessage);
}

void Heavy_heavy::cVar_hnfya8fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_CnQyv3Qt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1GRGwoQJ, 0, m, &cIf_1GRGwoQJ_sendMessage);
}

void Heavy_heavy::cVar_H9qcBYk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mqZqGgCt_sendMessage);
}

void Heavy_heavy::cVar_R4efRek9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hnfya8fk, 0, m, &cVar_hnfya8fk_sendMessage);
}

void Heavy_heavy::cBinop_bmRHMQQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0drYSm8N, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_0drYSm8N_sendMessage);
}

void Heavy_heavy::cVar_3itl0QaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmb8aaXv, HV_BINOP_ADD, 1, m, &cBinop_jmb8aaXv_sendMessage);
}

void Heavy_heavy::cUnop_hL1IL701_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FabiYoBd, 0, m, &cVar_FabiYoBd_sendMessage);
}

void Heavy_heavy::cVar_aLVHS86O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_e0dTaEai_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hUu2fQ5v, 0, m, &cIf_hUu2fQ5v_sendMessage);
}

void Heavy_heavy::cIf_hUu2fQ5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_hL1IL701_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dpYByVNE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_e0dTaEai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hUu2fQ5v, 1, m, &cIf_hUu2fQ5v_sendMessage);
}

void Heavy_heavy::cUnop_dpYByVNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FabiYoBd, 0, m, &cVar_FabiYoBd_sendMessage);
}

void Heavy_heavy::cCast_PjiK4iop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_8VmyJxBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TiwKgpC7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_OuAOoHv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PjiK4iop_sendMessage);
}

void Heavy_heavy::cSwitchcase_TiwKgpC7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OuAOoHv9_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dwFl5ezR_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_EaGdrKVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4300.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_c4nift2Q, HV_BINOP_SUBTRACT, 0, m, &cBinop_c4nift2Q_sendMessage);
}

void Heavy_heavy::cBinop_FQEsU9bY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IpChYN7D, 0, m, &cVar_IpChYN7D_sendMessage);
}

void Heavy_heavy::cSend_dwKlJvR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AjV2a2iV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSlice_hYixEqrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_dCgGYSuL, 0, m, &cVar_dCgGYSuL_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_dCgGYSuL, 0, m, &cVar_dCgGYSuL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_TC0ilSVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qY9yIxWN, HV_BINOP_NEQ, 1, m, &cBinop_qY9yIxWN_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_dCgGYSuL, 1, m, &cVar_dCgGYSuL_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qY9yIxWN, HV_BINOP_NEQ, 1, m, &cBinop_qY9yIxWN_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_dCgGYSuL, 1, m, &cVar_dCgGYSuL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_cQVa52Kr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hYixEqrA, 0, m, &cSlice_hYixEqrA_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TC0ilSVg, 0, m, &cSlice_TC0ilSVg_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hDaDF916_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DbAHQ3Do_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_cmZWTH2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dCgGYSuL, 0, m, &cVar_dCgGYSuL_sendMessage);
}

void Heavy_heavy::cIf_wF7Hx9ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dVAMeJX1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cmZWTH2U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_DbAHQ3Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wF7Hx9ck, 0, m, &cIf_wF7Hx9ck_sendMessage);
}

void Heavy_heavy::cCast_hDaDF916_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qY9yIxWN, HV_BINOP_NEQ, 0, m, &cBinop_qY9yIxWN_sendMessage);
}

void Heavy_heavy::cBinop_qY9yIxWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wF7Hx9ck, 1, m, &cIf_wF7Hx9ck_sendMessage);
}

void Heavy_heavy::cVar_dCgGYSuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_NlSN9Itb_sendMessage);
}

void Heavy_heavy::cCast_dVAMeJX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qY9yIxWN, HV_BINOP_NEQ, 1, m, &cBinop_qY9yIxWN_sendMessage);
}

void Heavy_heavy::cCast_y1ZICV87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sv5z2daR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_boGxRIh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_y15RF4hL_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_TkXcPm95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dwKlJvR8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ob4tbwh6, 0, m, &cVar_ob4tbwh6_sendMessage);
}

void Heavy_heavy::cBinop_Hmd49Y7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b4K7GILE, 1, m, &cVar_b4K7GILE_sendMessage);
}

void Heavy_heavy::cBinop_HaskwrCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I8oCRHcV, 0, m, &cVar_I8oCRHcV_sendMessage);
}

void Heavy_heavy::cBinop_vMtNi4t1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_atYfweyV, 1, m, &cIf_atYfweyV_sendMessage);
}

void Heavy_heavy::cVar_VVlyuvHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_vMtNi4t1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_atYfweyV, 0, m, &cIf_atYfweyV_sendMessage);
}

void Heavy_heavy::cUnop_X6L2fWIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cQVa52Kr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_FPxhfw5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cQVa52Kr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_atYfweyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_X6L2fWIq_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FPxhfw5F_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_ct1mIj3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DqS8nzJu_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_10rWvkrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_f0N0y3Qh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_1ytdfwrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wyYGLHWG, 0, m, &cVar_wyYGLHWG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XoFUYg5R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nhJDQG6Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wdzey9AG_sendMessage);
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
  hv_bufferf_t O0, O1;

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

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_b5nAZ8WN, VOf(Bf0));
    __hv_sample_f(this, &sSample_2MelNO5m, VIf(Bf0), &sSample_2MelNO5m_sendMessage);
    __hv_phasor_k_f(&sPhasor_Hbrrr06g, VOf(Bf0));
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
    __hv_sample_f(this, &sSample_6JIITBP5, VIf(Bf1), &sSample_6JIITBP5_sendMessage);
    __hv_varread_i(&sVari_jUR1GvoN, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_jUR1GvoN, VIi(Bi1));
    __hv_varread_f(&sVarf_Fz579kUX, VOf(Bf1));
    __hv_phasor_f(&sPhasor_lYxH2dr9, VIf(Bf1), VOf(Bf1));
    __hv_del1_f(&sDel1_CMdvMF5O, VIf(Bf1), VOf(Bf0));
    __hv_lt_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_samphold_f(&sSamphold_eGG8cBcf, VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_5BwL9ba5, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_qfayAQdA, VOf(Bf0));
    __hv_rpole_f(&sRPole_N7cgAtMm, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_CB20OR4L, VIf(Bf0), &sSample_CB20OR4L_sendMessage);
    __hv_varread_f(&sVarf_e8lE01iH, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_lKLACoOb, VOf(Bf1));
    __hv_rpole_f(&sRPole_RR5GAOrc, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_e3PhZ4ls, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_ZwWY59RX, VOf(Bf0));
    __hv_phasor_f(&sPhasor_005CXTPC, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_b3PxFJhK, VOf(Bf4));
    __hv_phasor_f(&sPhasor_yX3wGsRV, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_CaGyMHbz, VOf(Bf3));
    __hv_phasor_f(&sPhasor_g3BETxNw, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_QZt9JBv5, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_9evs4JXh, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_c5UdDxWI, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9VQK4PQn, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_AD0D96xP, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_varread_f(&sVarf_VGFPE0yM, VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_hvxwJBQZ, VIi(Bi0), VOf(Bf4));
    __hv_tabread_if(&sTabread_IRWJMgLq, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_09SR3nTF, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_S2wDnHtF, VOf(Bf2));
    __hv_rpole_f(&sRPole_UbQqrgmW, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_23cq5VE4, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_EAiT1jOi, VIf(Bf3));
    __hv_varread_f(&sVarf_HPw6Hnma, VOf(Bf3));
    __hv_varread_f(&sVarf_jsEIJpnG, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_zq8lQ4b2, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_8JbSv2WV, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_707VPVVE, VOf(Bf0));
    __hv_min_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_varread_f(&sVarf_pKkMfB1O, VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_iQkWA8EO, VIi(Bi0), VOf(Bf5));
    __hv_tabread_if(&sTabread_zzLJYd9x, VIi(Bi1), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_bm0dVxmh, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ffN18mS0, VOf(Bf0));
    __hv_rpole_f(&sRPole_q6GgpS9j, VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_D8ZCGh9N, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf1), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_AeCTFMoC, VIf(Bf2));
    __hv_varread_f(&sVarf_Jt4G8bL7, VOf(Bf2));
    __hv_varread_f(&sVarf_oZxFJCO6, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_min_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f);
    __hv_max_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_min_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f);
    __hv_max_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_heavy::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_heavy::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
