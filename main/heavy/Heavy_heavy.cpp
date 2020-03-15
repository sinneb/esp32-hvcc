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

float hTable_ZFqQS0Ye_data[128] = {0.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 5.0f, 7.0f, 9.0f, 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 15.0f, 15.0f, 17.0f, 17.0f, 19.0f, 21.0f, 22.0f, 22.0f, 24.0f, 26.0f, 26.0f, 27.0f, 27.0f, 29.0f, 29.0f, 31.0f, 33.0f, 34.0f, 34.0f, 36.0f, 38.0f, 38.0f, 39.0f, 39.0f, 41.0f, 41.0f, 43.0f, 45.0f, 46.0f, 46.0f, 48.0f, 50.0f, 50.0f, 51.0f, 51.0f, 53.0f, 53.0f, 55.0f, 57.0f, 58.0f, 58.0f, 60.0f, 62.0f, 62.0f, 63.0f, 63.0f, 65.0f, 65.0f, 67.0f, 69.0f, 70.0f, 70.0f, 72.0f, 74.0f, 74.0f, 75.0f, 75.0f, 77.0f, 77.0f, 79.0f, 81.0f, 82.0f, 82.0f, 84.0f, 86.0f, 86.0f, 87.0f, 87.0f, 89.0f, 89.0f, 91.0f, 93.0f, 94.0f, 94.0f, 96.0f, 98.0f, 98.0f, 99.0f, 99.0f, 101.0f, 101.0f, 103.0f, 105.0f, 106.0f, 106.0f, 108.0f, 110.0f, 110.0f, 111.0f, 111.0f, 113.0f, 113.0f, 115.0f, 117.0f, 118.0f, 118.0f, 120.0f, 122.0f, 122.0f, 123.0f, 123.0f, 125.0f, 125.0f, 127.0f, 129.0f, 130.0f, 130.0f, 132.0f, 134.0f, 134.0f, 135.0f, 135.0f, 137.0f, 0.0f};
float hTable_0e8IEloG_data[128] = {0.0f, 2.0f, 2.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f, 11.0f, 11.0f, 12.0f, 14.0f, 14.0f, 16.0f, 16.0f, 17.0f, 17.0f, 19.0f, 21.0f, 23.0f, 23.0f, 24.0f, 26.0f, 26.0f, 28.0f, 28.0f, 29.0f, 29.0f, 31.0f, 33.0f, 35.0f, 35.0f, 36.0f, 38.0f, 38.0f, 40.0f, 40.0f, 41.0f, 41.0f, 43.0f, 45.0f, 47.0f, 47.0f, 48.0f, 50.0f, 50.0f, 52.0f, 52.0f, 53.0f, 53.0f, 55.0f, 57.0f, 59.0f, 59.0f, 60.0f, 62.0f, 62.0f, 64.0f, 64.0f, 65.0f, 65.0f, 67.0f, 69.0f, 71.0f, 71.0f, 72.0f, 74.0f, 74.0f, 76.0f, 76.0f, 77.0f, 77.0f, 79.0f, 81.0f, 83.0f, 83.0f, 84.0f, 86.0f, 86.0f, 88.0f, 88.0f, 89.0f, 89.0f, 91.0f, 93.0f, 95.0f, 95.0f, 96.0f, 98.0f, 98.0f, 100.0f, 100.0f, 101.0f, 101.0f, 103.0f, 105.0f, 107.0f, 107.0f, 108.0f, 110.0f, 110.0f, 112.0f, 112.0f, 113.0f, 113.0f, 115.0f, 117.0f, 119.0f, 119.0f, 120.0f, 122.0f, 122.0f, 124.0f, 124.0f, 125.0f, 125.0f, 127.0f, 129.0f, 131.0f, 131.0f, 132.0f, 134.0f, 134.0f, 136.0f, 136.0f, 137.0f, 0.0f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_rZ9hfJTt, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_dsyvEXXD);
  numBytes += sPhasor_k_init(&sPhasor_8XyLMvqB, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_V4aWuIXy);
  numBytes += sPhasor_init(&sPhasor_8qjsesdt, sampleRate);
  numBytes += sDel1_init(&sDel1_vwYqPBdv);
  numBytes += sSamphold_init(&sSamphold_oxDfnMVJ);
  numBytes += sRPole_init(&sRPole_tYs3047f);
  numBytes += sSample_init(&sSample_Te1vfgJg);
  numBytes += sRPole_init(&sRPole_f4HOXh5a);
  numBytes += sLine_init(&sLine_yXi6rWqj);
  numBytes += sPhasor_init(&sPhasor_ciQlbSv3, sampleRate);
  numBytes += sLine_init(&sLine_7azZOOcP);
  numBytes += sPhasor_init(&sPhasor_t4DeW7YN, sampleRate);
  numBytes += sLine_init(&sLine_SC2hljFc);
  numBytes += sPhasor_init(&sPhasor_YLXhMM7P, sampleRate);
  numBytes += sLine_init(&sLine_fRBabuDa);
  numBytes += sLine_init(&sLine_DRF1CdF6);
  numBytes += sTabhead_init(&sTabhead_MqJpJtpp, &hTable_HkUzahtH);
  numBytes += sTabread_init(&sTabread_ldCzDTGF, &hTable_HkUzahtH, false);
  numBytes += sTabread_init(&sTabread_PnJdQKNq, &hTable_HkUzahtH, false);
  numBytes += sRPole_init(&sRPole_AqPx9AAy);
  numBytes += sTabwrite_init(&sTabwrite_YRTYe6G2, &hTable_QKuz4X29);
  numBytes += sTabhead_init(&sTabhead_tkRVC2PZ, &hTable_QKuz4X29);
  numBytes += sTabread_init(&sTabread_UQFDB0cf, &hTable_QKuz4X29, false);
  numBytes += sTabread_init(&sTabread_5UZlQdhd, &hTable_QKuz4X29, false);
  numBytes += sRPole_init(&sRPole_Et8wG6tU);
  numBytes += sTabwrite_init(&sTabwrite_l1XuuK90, &hTable_HkUzahtH);
  numBytes += hTable_initWithData(&hTable_ZFqQS0Ye, 128, hTable_ZFqQS0Ye_data);
  numBytes += cBinop_init(&cBinop_c7n9ZFtq, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_O0FFKHGH, 0.0f);
  numBytes += cSlice_init(&cSlice_9zrvzFBs, 1, -1);
  numBytes += cSlice_init(&cSlice_vO5ylbIo, 1, -1);
  numBytes += cIf_init(&cIf_Je8wTxig, false);
  numBytes += cPack_init(&cPack_tTxp0loT, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_tq5bCARR, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_agFpP1Yq, 2.0f);
  numBytes += cBinop_init(&cBinop_Ra6YWIB5, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_tDW7J5wT, 0.0f);
  numBytes += cPack_init(&cPack_UInkQpOT, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_rdZnQxCg, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_4GNmfphJ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_hcWWYbsB, 0.0f);
  numBytes += cVar_init_f(&cVar_sKAW1O7b, 0.0f);
  numBytes += cVar_init_f(&cVar_ptK9nge0, 0.0f);
  numBytes += cBinop_init(&cBinop_uZglU8UY, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_4YGiN1Sy, 13.0f);
  numBytes += cBinop_init(&cBinop_TBSVwCkj, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_B4oW138S, 1.0f);
  numBytes += cBinop_init(&cBinop_13O02OjZ, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_KapvQJQz, 0.0f);
  numBytes += cIf_init(&cIf_auqFaZum, false);
  numBytes += cVar_init_f(&cVar_VHUsxmcD, 0.0f);
  numBytes += cVar_init_f(&cVar_vFrvGzM2, 0.0f);
  numBytes += cIf_init(&cIf_thjuSyUq, false);
  numBytes += cVar_init_f(&cVar_2ZTL4OGD, 0.0f);
  numBytes += cBinop_init(&cBinop_K5xjvKTs, 0.0f); // __mul
  numBytes += cIf_init(&cIf_VIOpc2i8, false);
  numBytes += cVar_init_f(&cVar_lN86mWkh, 0.0f);
  numBytes += cBinop_init(&cBinop_0lRAJQcL, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_qfi57HlE, 0.0f);
  numBytes += sVarf_init(&sVarf_p8axsPO8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bpTvPBhe, 48.0f);
  numBytes += cBinop_init(&cBinop_WBtoDjUg, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ObXo4kIX, 3.0f);
  numBytes += sVarf_init(&sVarf_pkn9XHGB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NCEOAiWg, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_X39XwqoJ, 0.0f);
  numBytes += cVar_init_f(&cVar_J3TotSvJ, 1.0f);
  numBytes += sVari_init(&sVari_B1YpiFZN, 0, 0, false);
  numBytes += cRandom_init(&cRandom_IhacvEUq, 1913259347);
  numBytes += cSlice_init(&cSlice_6pCGeOSW, 1, 1);
  numBytes += cBinop_init(&cBinop_YLLno7pM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SVjFVwP4, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_32DH165b, 1.0f);
  numBytes += cDelay_init(this, &cDelay_9Ojduc4h, 0.0f);
  numBytes += cVar_init_f(&cVar_4dG7vwAw, 0.5f);
  numBytes += cVar_init_f(&cVar_BA7bmdYm, 0.0f);
  numBytes += sVarf_init(&sVarf_Kzi4LcH5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3E43c9JX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Y4xWnjC0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WLCV2hO9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VXAnUiwd, 3.0f);
  numBytes += cIf_init(&cIf_geN2Da2d, false);
  numBytes += cVar_init_f(&cVar_Xb0l53Ww, 0.0f);
  numBytes += cIf_init(&cIf_WG2esvHP, true);
  numBytes += cBinop_init(&cBinop_9MHkFG5s, 2.0f); // __add
  numBytes += cIf_init(&cIf_M7i1PjBK, false);
  numBytes += cVar_init_f(&cVar_aEFMY7aa, 0.0f);
  numBytes += cVar_init_f(&cVar_DKwNwPNr, 1.0f);
  numBytes += cVar_init_f(&cVar_jfnhLgPN, 1.0f);
  numBytes += cVar_init_f(&cVar_yWJNnKbz, 1.0f);
  numBytes += cVar_init_f(&cVar_L4at7Ym6, 0.0f);
  numBytes += cVar_init_f(&cVar_FQTjoxVK, 0.0f);
  numBytes += cBinop_init(&cBinop_3qbqfA3D, 8.0f); // __add
  numBytes += cIf_init(&cIf_X0Ph3w5D, true);
  numBytes += cIf_init(&cIf_Igb1M5um, false);
  numBytes += cVar_init_f(&cVar_L6Iedpw9, 1.0f);
  numBytes += cVar_init_f(&cVar_ZrDyhwH7, 0.0f);
  numBytes += cIf_init(&cIf_ZNzMm147, false);
  numBytes += cIf_init(&cIf_g6rmpJU6, true);
  numBytes += cBinop_init(&cBinop_PMrNwNvs, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_qpHAqH7q, 0.0f);
  numBytes += cVar_init_f(&cVar_DfPdsHid, 0.0f);
  numBytes += cIf_init(&cIf_a33d8Sp9, false);
  numBytes += cBinop_init(&cBinop_pQTfEm5L, -1.0f); // __add
  numBytes += cIf_init(&cIf_NfuSZzKG, true);
  numBytes += cSlice_init(&cSlice_DcOUjDyI, 1, 1);
  numBytes += cSlice_init(&cSlice_x24KTBd9, 4, 1);
  numBytes += cSlice_init(&cSlice_56NjVTbI, 3, 1);
  numBytes += cSlice_init(&cSlice_0XbJKEZn, 0, 1);
  numBytes += cSlice_init(&cSlice_0flqcDJG, 2, 1);
  numBytes += cIf_init(&cIf_wLifRQ3d, false);
  numBytes += cBinop_init(&cBinop_7iEyPd9l, 0.0f); // __add
  numBytes += cIf_init(&cIf_ReqMp5We, true);
  numBytes += cVar_init_f(&cVar_v2ARCwao, 0.0f);
  numBytes += cVar_init_f(&cVar_Cjh3B9Kw, 1.0f);
  numBytes += cVar_init_f(&cVar_gYfUn9NF, 0.0f);
  numBytes += cVar_init_f(&cVar_RWo9oYzY, 0.0f);
  numBytes += cIf_init(&cIf_IG3YnYtj, false);
  numBytes += cVar_init_f(&cVar_3giVpwCd, 0.0f);
  numBytes += cVar_init_f(&cVar_slLl5P4L, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ugL1WEX2, 0.0f);
  numBytes += cVar_init_f(&cVar_Ce1JwVyU, 0.0f);
  numBytes += cBinop_init(&cBinop_6r7Sjc0U, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_znXSrI5P, 0.0f);
  numBytes += cVar_init_f(&cVar_YY4EdWwD, 0.0f);
  numBytes += cVar_init_f(&cVar_3QJeDOon, 250.0f);
  numBytes += cSlice_init(&cSlice_8zWh0Nu7, 1, -1);
  numBytes += cSlice_init(&cSlice_BmEHfSuz, 1, -1);
  numBytes += cBinop_init(&cBinop_qFRZdWL9, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_MzYBtA74, 1, 1);
  numBytes += cSlice_init(&cSlice_thkiCIq2, 0, 1);
  numBytes += cBinop_init(&cBinop_fMKUnO9C, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_uwj9h1vF, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_g4MWqp8y, 20.0f);
  numBytes += cBinop_init(&cBinop_8dWgHZMB, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_XOlUMAuX, 0.0f);
  numBytes += cBinop_init(&cBinop_Ex9uIMKF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9vYTz0ZD, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_mX7ax9YV, 20.0f);
  numBytes += cBinop_init(&cBinop_IRJO8DFw, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_84IBLFXq, 0.0f);
  numBytes += cVar_init_f(&cVar_P51YIGXq, 0.0f);
  numBytes += cVar_init_f(&cVar_0naLdcVc, 0.0f);
  numBytes += cBinop_init(&cBinop_jBGMVWgt, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_d0XMJlJ2, 0.0f);
  numBytes += cBinop_init(&cBinop_jHMZw2NV, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_DE6Zz8Se, 0.0f);
  numBytes += cVar_init_f(&cVar_pnBtLuBY, 850.0f);
  numBytes += cVar_init_f(&cVar_y1HygRmI, 550.0f);
  numBytes += cVar_init_f(&cVar_9I9aEcZl, 0.0f);
  numBytes += cVar_init_f(&cVar_zv7FgbVZ, 0.0f);
  numBytes += cBinop_init(&cBinop_O25lSxq7, 0.0f); // __add
  numBytes += cIf_init(&cIf_Ov4uHqXs, false);
  numBytes += cIf_init(&cIf_pjjaKdE4, true);
  numBytes += cVar_init_f(&cVar_qckLs1dM, 1.0f);
  numBytes += cBinop_init(&cBinop_Vr0EucFF, 2.0f); // __add
  numBytes += cIf_init(&cIf_jV4mWyb7, false);
  numBytes += cIf_init(&cIf_y3TyaMch, true);
  numBytes += cVar_init_f(&cVar_AlGwqEbu, 0.0f);
  numBytes += cIf_init(&cIf_lHfwTI8Y, false);
  numBytes += cVar_init_f(&cVar_2ylSQA4Q, 0.0f);
  numBytes += cSlice_init(&cSlice_poZbF4CT, 0, 1);
  numBytes += cSlice_init(&cSlice_ms63WDtP, 3, 1);
  numBytes += cSlice_init(&cSlice_u1j7qqlP, 2, 1);
  numBytes += cSlice_init(&cSlice_8qgDCn8U, 4, 1);
  numBytes += cSlice_init(&cSlice_JzCNYX3V, 1, 1);
  numBytes += cVar_init_f(&cVar_URp0LRw4, 0.0f);
  numBytes += cIf_init(&cIf_iwpWQoUf, false);
  numBytes += cIf_init(&cIf_QHWBMH4N, true);
  numBytes += cBinop_init(&cBinop_4fn3UgnI, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_j5xePO9W, 1.0f);
  numBytes += cIf_init(&cIf_gIBYA9Vi, false);
  numBytes += cIf_init(&cIf_zAIgie2n, true);
  numBytes += cBinop_init(&cBinop_Luo4DNbj, -1.0f); // __add
  numBytes += cVar_init_f(&cVar_9s7ZODJ5, 1.0f);
  numBytes += cVar_init_f(&cVar_0lEe6iCJ, 0.0f);
  numBytes += cVar_init_f(&cVar_hPqVUX6k, 0.0f);
  numBytes += cVar_init_f(&cVar_y2TatLGC, 0.0f);
  numBytes += cVar_init_f(&cVar_JhJzOplK, 0.0f);
  numBytes += cVar_init_f(&cVar_Zf21cETL, 0.0f);
  numBytes += cVar_init_f(&cVar_tiVHQILs, 1.0f);
  numBytes += cVar_init_f(&cVar_mcGF2CQ0, 1.0f);
  numBytes += cIf_init(&cIf_gSxUNxP2, true);
  numBytes += cIf_init(&cIf_v6TqM15A, false);
  numBytes += cBinop_init(&cBinop_TEgUskHU, 8.0f); // __add
  numBytes += cIf_init(&cIf_Zyz4QrKK, false);
  numBytes += cVar_init_f(&cVar_hhmFmmkR, 0.0f);
  numBytes += cVar_init_f(&cVar_nxJps3eb, 0.0f);
  numBytes += cIf_init(&cIf_b48cWL7X, false);
  numBytes += cBinop_init(&cBinop_2ZYUyIKK, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_87J9BtnB, 0.0f);
  numBytes += cVar_init_f(&cVar_haDczaSF, 0.0f);
  numBytes += cIf_init(&cIf_EPuf5Wds, false);
  numBytes += cVar_init_f(&cVar_2VzcVne6, 5.0f);
  numBytes += cVar_init_f(&cVar_Z5U7luWV, 0.0f);
  numBytes += cVar_init_f(&cVar_jSDEvjGr, 0.0f);
  numBytes += cBinop_init(&cBinop_MPYlSnG5, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_lklQ4WuW, 0.0f);
  numBytes += cVar_init_f(&cVar_M50xoup2, 1.0f);
  numBytes += cVar_init_f(&cVar_XlbLbBRT, 11.0f);
  numBytes += cBinop_init(&cBinop_C5Q3MtKX, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_pFvpKkAb, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_fhFTtxdb, 0.0f);
  numBytes += cIf_init(&cIf_CJqK0bKZ, false);
  numBytes += cVar_init_f(&cVar_irEwjTXO, 0.0f);
  numBytes += hTable_initWithData(&hTable_0e8IEloG, 128, hTable_0e8IEloG_data);
  numBytes += cBinop_init(&cBinop_2zvC1nMQ, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_bCob2Buz, 0.0f);
  numBytes += cVar_init_f(&cVar_YnkJyax9, 0.0f);
  numBytes += cVar_init_f(&cVar_9c4gvwKl, 0.0f);
  numBytes += cIf_init(&cIf_rKJiU6oI, false);
  numBytes += cBinop_init(&cBinop_nWd73pAL, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_2u6CoMWM, 0.0f);
  numBytes += cBinop_init(&cBinop_yBvp9ptm, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_7zcAFrUo, 0.0f);
  numBytes += cIf_init(&cIf_Qk7tvjL6, false);
  numBytes += cVar_init_f(&cVar_1ek9dRMe, 0.0f);
  numBytes += cVar_init_f(&cVar_ykrJ9b6u, 17.0f);
  numBytes += cBinop_init(&cBinop_itGJ8SSc, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_bEPhmoI4, 0.0f);
  numBytes += cIf_init(&cIf_A41ARwKz, false);
  numBytes += cVar_init_f(&cVar_VdVyznpm, 2.0f);
  numBytes += cVar_init_f(&cVar_Z5TVikAR, 1.0f);
  numBytes += cVar_init_f(&cVar_vf7ENkBY, 0.0f);
  numBytes += cVar_init_f(&cVar_L3mQzZZk, 7.0f);
  numBytes += cBinop_init(&cBinop_5RBzp7GF, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_XC5wlGwZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_EaPUMS8W, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yVXsJRdM, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_JFflS1tQ, 9.0f);
  numBytes += cVar_init_f(&cVar_IFcDYXyU, 0.0f);
  numBytes += cVar_init_f(&cVar_Qd34HC3r, 0.0f);
  numBytes += cVar_init_f(&cVar_8PDLEOaT, 0.0f);
  numBytes += cIf_init(&cIf_J4j3YY1W, false);
  numBytes += cVar_init_f(&cVar_gqh1PB2D, 1.0f);
  numBytes += cVar_init_f(&cVar_18U4NBSj, 0.0f);
  numBytes += cIf_init(&cIf_E6y2Mn6q, false);
  numBytes += cVar_init_f(&cVar_M3U7coEX, 0.0f);
  numBytes += cVar_init_f(&cVar_oMylLNot, 0.0f);
  numBytes += cIf_init(&cIf_tnvOoxdZ, false);
  numBytes += cVar_init_f(&cVar_AFN3YNOI, 0.0f);
  numBytes += sVarf_init(&sVarf_g2fpaD8c, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ndea89W1, "del-1339-pong");
  numBytes += sVarf_init(&sVarf_xhJpgQT6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZfvEIDXQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_mSTxBLyj, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_Lf9qbP38, 0.5f);
  numBytes += cVar_init_f(&cVar_9Rt8TT9P, 3.0f);
  numBytes += cVar_init_f(&cVar_M3ak4vLQ, 0.0f);
  numBytes += cBinop_init(&cBinop_S12kC7dh, 0.0f); // __mul
  numBytes += hTable_init(&hTable_QKuz4X29, 256);
  numBytes += cDelay_init(this, &cDelay_wry86EPP, 0.0f);
  numBytes += cDelay_init(this, &cDelay_MWbNFHq0, 0.0f);
  numBytes += cVar_init_f(&cVar_Ns0Yrem9, 0.0f);
  numBytes += sVarf_init(&sVarf_rpNvROxU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gY76JK2a, 0.7f);
  numBytes += sVarf_init(&sVarf_WtHlQeQv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PbwaFKCN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KZWRv8U4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9kQARwGG, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_z0Hrrcz1, "del-1339-ping");
  numBytes += sVarf_init(&sVarf_mqF1LOL2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aZ7KMxy8, 0.5f);
  numBytes += sVarf_init(&sVarf_NFzRXMOM, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_oUPcelPX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rHmZR8NE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YVGTsPvm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_q8SXt3iK, 3000.0f);
  numBytes += sVarf_init(&sVarf_0GZhqeMB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jHORJlME, 3000.0f);
  numBytes += sVarf_init(&sVarf_5Ta8hJCX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_xwLXcgM7, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_eF92Mis9, 0.0f);
  numBytes += cBinop_init(&cBinop_2zyYLWcf, 1.0f); // __pow
  numBytes += hTable_init(&hTable_HkUzahtH, 256);
  numBytes += cDelay_init(this, &cDelay_ntzZeyFc, 0.0f);
  numBytes += cDelay_init(this, &cDelay_AVEs1Par, 0.0f);
  numBytes += sVarf_init(&sVarf_agVpjrxC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Hum7u1pp, 0.0f);
  numBytes += cIf_init(&cIf_aFgXVYeA, false);
  numBytes += sVarf_init(&sVarf_xTaLCdcf, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_ZGv2eRz3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ytloH9rg, 0.0f);
  numBytes += cIf_init(&cIf_CFd2AuUZ, false);
  numBytes += cVar_init_f(&cVar_Z2HUvkhM, 0.0f);
  numBytes += cSlice_init(&cSlice_6lhvnAop, 1, -1);
  numBytes += cVar_init_s(&cVar_T5sW7ZE2, "minor_scale");
  numBytes += cTabread_init(&cTabread_YMiPdg8Z, &hTable_ZFqQS0Ye); // minor_scale
  numBytes += cBinop_init(&cBinop_lArJybjA, 0.0f); // __min
  numBytes += cBinop_init(&cBinop_0dT4W8y4, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_oIfaaYrk, 0.0f);
  numBytes += cVar_init_f(&cVar_f2KjoGNJ, 0.0f);
  numBytes += cBinop_init(&cBinop_HUmrKiLo, 0.0f); // __sub
  numBytes += cIf_init(&cIf_RFLINFtS, false);
  numBytes += cSlice_init(&cSlice_XQb1QS4R, 1, -1);
  numBytes += cSlice_init(&cSlice_kHBVQGmz, 1, -1);
  numBytes += cVar_init_f(&cVar_27BBmrdb, 0.0f);
  numBytes += cBinop_init(&cBinop_EPALZRPp, 0.0f); // __neq
  numBytes += cBinop_init(&cBinop_3FZxheMK, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_bi7GJVPU, 0.0f);
  numBytes += cVar_init_s(&cVar_e5Z9Zkqw, "minor_scale");
  numBytes += cTabread_init(&cTabread_LVyouakr, &hTable_ZFqQS0Ye); // minor_scale
  numBytes += cBinop_init(&cBinop_vIyp314g, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_5iXPZPm2, 1, -1);
  numBytes += cVar_init_f(&cVar_DZIUGz48, 0.0f);
  numBytes += cVar_init_f(&cVar_If84eHLf, 0.0f);
  numBytes += cBinop_init(&cBinop_NP1ixxiI, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_JTuKRgzP, 1, -1);
  numBytes += cSlice_init(&cSlice_YnTtF8cq, 1, -1);
  numBytes += cBinop_init(&cBinop_MA73TW95, 0.0f); // __neq
  numBytes += cIf_init(&cIf_q64k6n1M, false);
  numBytes += cVar_init_f(&cVar_5d1G69Rp, 0.0f);
  numBytes += cVar_init_f(&cVar_vYw7AiSz, 1.0f);
  numBytes += cVar_init_f(&cVar_Miac6iea, 0.0f);
  numBytes += cIf_init(&cIf_dMPnEqJW, true);
  numBytes += cBinop_init(&cBinop_E4aucfg7, 8.0f); // __add
  numBytes += cIf_init(&cIf_APiCFsAX, false);
  numBytes += cVar_init_f(&cVar_Hg1YzM1C, 0.0f);
  numBytes += cIf_init(&cIf_lcK5bs2L, false);
  numBytes += cIf_init(&cIf_363pukBR, false);
  numBytes += cIf_init(&cIf_CjNDtL7p, true);
  numBytes += cBinop_init(&cBinop_ckuXZ8Ai, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_yP7DEtcM, 1.0f);
  numBytes += cVar_init_f(&cVar_tjyXAKNl, 0.0f);
  numBytes += cIf_init(&cIf_qpT7f6I4, true);
  numBytes += cIf_init(&cIf_JjBXm0yR, false);
  numBytes += cBinop_init(&cBinop_iJoCIsza, 16.0f); // __add
  numBytes += cIf_init(&cIf_PT4tGPlI, true);
  numBytes += cBinop_init(&cBinop_rPs1r5lw, 2.0f); // __add
  numBytes += cIf_init(&cIf_kmUgKCag, false);
  numBytes += cVar_init_f(&cVar_ah1Z7XO6, 0.0f);
  numBytes += cSlice_init(&cSlice_P1CdeTXE, 0, 1);
  numBytes += cSlice_init(&cSlice_2bYyw8rr, 3, 1);
  numBytes += cSlice_init(&cSlice_dDWji7AB, 1, 1);
  numBytes += cSlice_init(&cSlice_d7LxjlRU, 4, 1);
  numBytes += cSlice_init(&cSlice_OPfXiLXx, 2, 1);
  numBytes += cVar_init_f(&cVar_jbzuhYjB, 1.0f);
  numBytes += cVar_init_f(&cVar_GGAdABJh, 0.0f);
  numBytes += cIf_init(&cIf_VKLKTqPy, true);
  numBytes += cBinop_init(&cBinop_umBuGclw, -1.0f); // __add
  numBytes += cIf_init(&cIf_49eQUZ9o, false);
  numBytes += cVar_init_f(&cVar_WUjIqZK1, 1.0f);
  numBytes += cVar_init_f(&cVar_LFalCNlB, 0.0f);
  numBytes += cVar_init_f(&cVar_VGzudtNS, 0.0f);
  numBytes += cVar_init_f(&cVar_uZO8esYE, 0.0f);
  numBytes += cVar_init_f(&cVar_havNOXGy, 0.0f);
  numBytes += cVar_init_f(&cVar_vi7Gq1kH, 1.0f);
  numBytes += cVar_init_f(&cVar_lRKHRh21, 0.0f);
  numBytes += cBinop_init(&cBinop_Hz4MQRvk, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_byZ5Oue5, &hTable_ZFqQS0Ye); // minor_scale
  numBytes += cSlice_init(&cSlice_zZwTVWGj, 1, -1);
  numBytes += cVar_init_s(&cVar_cNZrUfCg, "minor_scale");
  numBytes += cVar_init_f(&cVar_5PcX9FRz, 0.0f);
  numBytes += cBinop_init(&cBinop_k4gJ8dxM, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_8wEioEGy, 0.0f);
  numBytes += cVar_init_f(&cVar_BZBtBDcA, 0.0f);
  numBytes += cVar_init_f(&cVar_Lax1QPiv, 0.0f);
  numBytes += cBinop_init(&cBinop_PkN1PTYJ, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_cm3aVWeV, 1.0f);
  numBytes += cVar_init_f(&cVar_MAxbVWO0, 0.0f);
  numBytes += cIf_init(&cIf_VUL6UJ3e, false);
  numBytes += cBinop_init(&cBinop_CCmmRHYB, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Z1mumEr1, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_6FZLz0ld, 0.0f);
  numBytes += cVar_init_f(&cVar_n3JVSHrr, 1.0f);
  numBytes += cVar_init_f(&cVar_8wqsPp24, 2000.0f);
  numBytes += cDelay_init(this, &cDelay_v25TaZVr, 0.0f);
  numBytes += cVar_init_f(&cVar_QQdkhqAS, 1.0f);
  numBytes += cBinop_init(&cBinop_gYVHrMzA, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_xSks1fHj, 20.0f);
  numBytes += cVar_init_f(&cVar_Csxr6obb, 0.0f);
  numBytes += cIf_init(&cIf_gwU6DVcz, false);
  numBytes += cVar_init_f(&cVar_iOMNU6H1, 0.0f);
  numBytes += cVar_init_f(&cVar_gfKkcVG1, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_ZFqQS0Ye);
  cPack_free(&cPack_tTxp0loT);
  cPack_free(&cPack_UInkQpOT);
  cPack_free(&cPack_rdZnQxCg);
  hTable_free(&hTable_0e8IEloG);
  hTable_free(&hTable_QKuz4X29);
  hTable_free(&hTable_HkUzahtH);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB069134D: return &hTable_QKuz4X29; // del-1339-pong
    case 0x4D17F050: return &hTable_ZFqQS0Ye; // minor_scale
    case 0xCA62B065: return &hTable_HkUzahtH; // del-1339-ping
    case 0xBBA21A19: return &hTable_0e8IEloG; // major_scale
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xC440C54F: { // Channel-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_It2U5qhP_sendMessage);
      break;
    }
    case 0xB762BB42: { // Channel-B
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QHvbNCZx_sendMessage);
      break;
    }
    case 0x27D89CD5: { // Channel-C
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rjL9kvlh_sendMessage);
      break;
    }
    case 0x17512476: { // 1001-intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eq8gYRHV_sendMessage);
      break;
    }
    case 0xD52A3BF1: { // 1001-mastertempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_llw9oRgm_sendMessage);
      break;
    }
    case 0x8CF5567: { // 1001-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TmCQMfDs_sendMessage);
      break;
    }
    case 0x8CC8BA58: { // 1001-transpose
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0kzmgiOq_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gVmUyYFS_sendMessage);
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


void Heavy_heavy::cBinop_UZ2XezfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tjyXAKNl, 0, m, &cVar_tjyXAKNl_sendMessage);
}

void Heavy_heavy::hTable_ZFqQS0Ye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_FBJus5TB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l0D3EU1r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZzRrIneh_sendMessage);
}

void Heavy_heavy::cBinop_NGv4ZaXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_IxutTyQh_sendMessage);
}

void Heavy_heavy::cBinop_hBWDjJXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pnBtLuBY, 0, m, &cVar_pnBtLuBY_sendMessage);
}

void Heavy_heavy::cSend_EOwrKIcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TmCQMfDs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_uw7qdnJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c7n9ZFtq, HV_BINOP_NEQ, 0, m, &cBinop_c7n9ZFtq_sendMessage);
}

void Heavy_heavy::cCast_OvFqEOER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Je8wTxig, 0, m, &cIf_Je8wTxig_sendMessage);
}

void Heavy_heavy::cBinop_c7n9ZFtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Je8wTxig, 1, m, &cIf_Je8wTxig_sendMessage);
}

void Heavy_heavy::cCast_FeTkXSI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c7n9ZFtq, HV_BINOP_NEQ, 1, m, &cBinop_c7n9ZFtq_sendMessage);
}

void Heavy_heavy::cVar_O0FFKHGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_wXlN1JPU_sendMessage);
}

void Heavy_heavy::cCast_wa5tw9Yl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O0FFKHGH, 0, m, &cVar_O0FFKHGH_sendMessage);
}

void Heavy_heavy::cSlice_9zrvzFBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_c7n9ZFtq, HV_BINOP_NEQ, 1, m, &cBinop_c7n9ZFtq_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_O0FFKHGH, 1, m, &cVar_O0FFKHGH_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_c7n9ZFtq, HV_BINOP_NEQ, 1, m, &cBinop_c7n9ZFtq_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_O0FFKHGH, 1, m, &cVar_O0FFKHGH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_vO5ylbIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_O0FFKHGH, 0, m, &cVar_O0FFKHGH_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_O0FFKHGH, 0, m, &cVar_O0FFKHGH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_OyLoYR3l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vO5ylbIo, 0, m, &cSlice_vO5ylbIo_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9zrvzFBs, 0, m, &cSlice_9zrvzFBs_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uw7qdnJ8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OvFqEOER_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cIf_Je8wTxig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FeTkXSI5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wa5tw9Yl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_Ym2eys3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3giVpwCd, 0, m, &cVar_3giVpwCd_sendMessage);
}

void Heavy_heavy::cPack_tTxp0loT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SC2hljFc, 0, m, NULL);
}

void Heavy_heavy::cBinop_2iQFThlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tq5bCARR, HV_BINOP_POW, 1, m, &cBinop_tq5bCARR_sendMessage);
  cMsg_BQGcoI79_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_TioFQDBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_tTxp0loT, 0, m, &cPack_tTxp0loT_sendMessage);
}

void Heavy_heavy::cBinop_tq5bCARR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TioFQDBS_sendMessage);
}

void Heavy_heavy::cBinop_ooDkWyyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2iQFThlh_sendMessage);
}

void Heavy_heavy::cMsg_BQGcoI79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tq5bCARR, HV_BINOP_POW, 0, m, &cBinop_tq5bCARR_sendMessage);
}

void Heavy_heavy::cVar_agFpP1Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tDW7J5wT, 0, m, &cVar_tDW7J5wT_sendMessage);
}

void Heavy_heavy::cMsg_WNF6u3G8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ra6YWIB5, HV_BINOP_POW, 0, m, &cBinop_Ra6YWIB5_sendMessage);
}

void Heavy_heavy::cBinop_Ra6YWIB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_fiAei8eW_sendMessage);
}

void Heavy_heavy::cBinop_5RFEZkxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ra6YWIB5, HV_BINOP_POW, 1, m, &cBinop_Ra6YWIB5_sendMessage);
  cMsg_WNF6u3G8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_MSAdxeSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5RFEZkxd_sendMessage);
}

void Heavy_heavy::cBinop_fiAei8eW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rdZnQxCg, 0, m, &cPack_rdZnQxCg_sendMessage);
}

void Heavy_heavy::cVar_tDW7J5wT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_rdZnQxCg, 1, m, &cPack_rdZnQxCg_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_UInkQpOT, 1, m, &cPack_UInkQpOT_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_tTxp0loT, 1, m, &cPack_tTxp0loT_sendMessage);
}

void Heavy_heavy::cPack_UInkQpOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_7azZOOcP, 0, m, NULL);
}

void Heavy_heavy::cPack_rdZnQxCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yXi6rWqj, 0, m, NULL);
}

void Heavy_heavy::cBinop_iJvyaekm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UInkQpOT, 0, m, &cPack_UInkQpOT_sendMessage);
}

void Heavy_heavy::cBinop_4GNmfphJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_iJvyaekm_sendMessage);
}

void Heavy_heavy::cMsg_IEoW1yaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GNmfphJ, HV_BINOP_POW, 0, m, &cBinop_4GNmfphJ_sendMessage);
}

void Heavy_heavy::cBinop_cKyWrgSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GNmfphJ, HV_BINOP_POW, 1, m, &cBinop_4GNmfphJ_sendMessage);
  cMsg_IEoW1yaF_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_KXDjY9mL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_cKyWrgSz_sendMessage);
}

void Heavy_heavy::cVar_hcWWYbsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TBSVwCkj, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_TBSVwCkj_sendMessage);
}

void Heavy_heavy::cVar_sKAW1O7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vFrvGzM2, 0, m, &cVar_vFrvGzM2_sendMessage);
}

void Heavy_heavy::cVar_ptK9nge0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZglU8UY, HV_BINOP_ADD, 1, m, &cBinop_uZglU8UY_sendMessage);
}

void Heavy_heavy::cBinop_uZglU8UY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K5xjvKTs, HV_BINOP_MULTIPLY, 0, m, &cBinop_K5xjvKTs_sendMessage);
}

void Heavy_heavy::cCast_cB8a2tvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_4YGiN1Sy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lN86mWkh, 0, m, &cVar_lN86mWkh_sendMessage);
}

void Heavy_heavy::cCast_LMkQjSeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9s7ZODJ5, 0, m, &cVar_9s7ZODJ5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vYw7AiSz, 0, m, &cVar_vYw7AiSz_sendMessage);
}

void Heavy_heavy::cBinop_TBSVwCkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_13O02OjZ, HV_BINOP_LESS_THAN, 0, m, &cBinop_13O02OjZ_sendMessage);
}

void Heavy_heavy::cVar_B4oW138S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KapvQJQz, 0, m, &cVar_KapvQJQz_sendMessage);
}

void Heavy_heavy::cBinop_13O02OjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mNRce7rg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_BxyWpUgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VHUsxmcD, 0, m, &cVar_VHUsxmcD_sendMessage);
}

void Heavy_heavy::cVar_KapvQJQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_bzcYOXU8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_auqFaZum, 0, m, &cIf_auqFaZum_sendMessage);
}

void Heavy_heavy::cUnop_xj21K2E4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VHUsxmcD, 0, m, &cVar_VHUsxmcD_sendMessage);
}

void Heavy_heavy::cIf_auqFaZum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BxyWpUgI_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xj21K2E4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_bzcYOXU8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_auqFaZum, 1, m, &cIf_auqFaZum_sendMessage);
}

void Heavy_heavy::cVar_VHUsxmcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K5xjvKTs, HV_BINOP_MULTIPLY, 1, m, &cBinop_K5xjvKTs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_13O02OjZ, HV_BINOP_LESS_THAN, 1, m, &cBinop_13O02OjZ_sendMessage);
}

void Heavy_heavy::cBinop_IMy9AxIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ZTL4OGD, 1, m, &cVar_2ZTL4OGD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZglU8UY, HV_BINOP_ADD, 0, m, &cBinop_uZglU8UY_sendMessage);
}

void Heavy_heavy::cUnop_Gw0qEib0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ptK9nge0, 0, m, &cVar_ptK9nge0_sendMessage);
}

void Heavy_heavy::cVar_vFrvGzM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_SBKx4jvy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_thjuSyUq, 0, m, &cIf_thjuSyUq_sendMessage);
}

void Heavy_heavy::cUnop_mcYL3OVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ptK9nge0, 0, m, &cVar_ptK9nge0_sendMessage);
}

void Heavy_heavy::cIf_thjuSyUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_mcYL3OVt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Gw0qEib0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_SBKx4jvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_thjuSyUq, 1, m, &cIf_thjuSyUq_sendMessage);
}

void Heavy_heavy::cVar_2ZTL4OGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_IMy9AxIl_sendMessage);
}

void Heavy_heavy::cBinop_K5xjvKTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TBSVwCkj, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_TBSVwCkj_sendMessage);
}

void Heavy_heavy::cBinop_LWBBgpTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VIOpc2i8, 1, m, &cIf_VIOpc2i8_sendMessage);
}

void Heavy_heavy::cIf_VIOpc2i8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_l01ujX0o_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jjXJk3vv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_l01ujX0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hcWWYbsB, 0, m, &cVar_hcWWYbsB_sendMessage);
}

void Heavy_heavy::cVar_lN86mWkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LWBBgpTW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VIOpc2i8, 0, m, &cIf_VIOpc2i8_sendMessage);
}

void Heavy_heavy::cUnop_jjXJk3vv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hcWWYbsB, 0, m, &cVar_hcWWYbsB_sendMessage);
}

void Heavy_heavy::cCast_d71gFK3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cB8a2tvQ_sendMessage);
}

void Heavy_heavy::cSwitchcase_mNRce7rg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d71gFK3T_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LMkQjSeD_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_t6NFagX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ym2eys3O_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kfJiBe1r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i3UGYzK0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_EfN3T6OF_sendMessage);
}

void Heavy_heavy::cBinop_0lRAJQcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VXAnUiwd, 0, m, &cVar_VXAnUiwd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ObXo4kIX, 0, m, &cVar_ObXo4kIX_sendMessage);
}

void Heavy_heavy::cVar_qfi57HlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LXnEmb6W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EH0WR7QI_sendMessage);
}

void Heavy_heavy::cVar_bpTvPBhe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qfi57HlE, 0, m, &cVar_qfi57HlE_sendMessage);
}

void Heavy_heavy::cBinop_4Vjo6Tj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pkn9XHGB, m);
}

void Heavy_heavy::cSystem_0Hp7TVso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ta5eUjpk_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_cHPdhJgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0Hp7TVso_sendMessage);
}

void Heavy_heavy::cBinop_WBtoDjUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JbfS7GmM_sendMessage);
}

void Heavy_heavy::cBinop_7Pv3ynnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WBtoDjUg, HV_BINOP_MULTIPLY, 1, m, &cBinop_WBtoDjUg_sendMessage);
}

void Heavy_heavy::cMsg_Ta5eUjpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7Pv3ynnB_sendMessage);
}

void Heavy_heavy::cVar_ObXo4kIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WBtoDjUg, HV_BINOP_MULTIPLY, 0, m, &cBinop_WBtoDjUg_sendMessage);
}

void Heavy_heavy::cBinop_JbfS7GmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IT7VEOGI_sendMessage);
}

void Heavy_heavy::cBinop_IT7VEOGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4Vjo6Tj8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NCEOAiWg, m);
}

void Heavy_heavy::cVar_X39XwqoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLLno7pM, HV_BINOP_MULTIPLY, 1, m, &cBinop_YLLno7pM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Kzi4LcH5, m);
}

void Heavy_heavy::cVar_J3TotSvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X39XwqoJ, 0, m, &cVar_X39XwqoJ_sendMessage);
}

void Heavy_heavy::cMsg_5FuoalNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_B1YpiFZN, m);
}

void Heavy_heavy::cBinop_bt1cXyLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kHTG907y_sendMessage);
}

void Heavy_heavy::cRandom_IhacvEUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_bt1cXyLY_sendMessage);
}

void Heavy_heavy::cUnop_kHTG907y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5FuoalNl_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_FQhJ9wB5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6pCGeOSW, 0, m, &cSlice_6pCGeOSW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IhacvEUq, 0, m, &cRandom_IhacvEUq_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_6pCGeOSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_IhacvEUq, 1, m, &cRandom_IhacvEUq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_LXnEmb6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0lRAJQcL, HV_BINOP_SUBTRACT, 1, m, &cBinop_0lRAJQcL_sendMessage);
}

void Heavy_heavy::cMsg_AzdaYT5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_AX7OFaBx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_YLLno7pM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NGv4ZaXD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_bdlYadcp_sendMessage);
}

void Heavy_heavy::cBinop_NcWVSQVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ojduc4h, 2, m, &cDelay_9Ojduc4h_sendMessage);
}

void Heavy_heavy::cBinop_SVjFVwP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NcWVSQVl_sendMessage);
}

void Heavy_heavy::cMsg_HWW935p7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ojduc4h, 0, m, &cDelay_9Ojduc4h_sendMessage);
}

void Heavy_heavy::cSwitchcase_AX7OFaBx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HWW935p7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HWW935p7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v01QtM5j_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_KThS0Cie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVjFVwP4, HV_BINOP_MULTIPLY, 1, m, &cBinop_SVjFVwP4_sendMessage);
}

void Heavy_heavy::cCast_v01QtM5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HWW935p7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ojduc4h, 0, m, &cDelay_9Ojduc4h_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_Te1vfgJg, 1, m);
}

void Heavy_heavy::cSystem_Z5M36ddQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KThS0Cie_sendMessage);
}

void Heavy_heavy::cMsg_rsOZpBPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Z5M36ddQ_sendMessage);
}

void Heavy_heavy::cVar_32DH165b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVjFVwP4, HV_BINOP_MULTIPLY, 0, m, &cBinop_SVjFVwP4_sendMessage);
}

void Heavy_heavy::cDelay_9Ojduc4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9Ojduc4h, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Ojduc4h, 0, m, &cDelay_9Ojduc4h_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_Te1vfgJg, 1, m);
}

void Heavy_heavy::cVar_4dG7vwAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BA7bmdYm, 0, m, &cVar_BA7bmdYm_sendMessage);
}

void Heavy_heavy::cVar_BA7bmdYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p8axsPO8, m);
}

void Heavy_heavy::cCast_EH0WR7QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3tkVPJ7o_sendMessage(_c, 0, m);
}

void Heavy_heavy::sSample_Te1vfgJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YLLno7pM, HV_BINOP_MULTIPLY, 0, m, &cBinop_YLLno7pM_sendMessage);
}

void Heavy_heavy::cBinop_1f7tL5j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4xWnjC0, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y4xWnjC0_sendMessage);
}

void Heavy_heavy::cBinop_Y4xWnjC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_H0z671s7_sendMessage);
}

void Heavy_heavy::cMsg_PnHj48PB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MBN2imgT_sendMessage);
}

void Heavy_heavy::cSystem_MBN2imgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JVvVn0lu_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_JVvVn0lu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1f7tL5j3_sendMessage);
}

void Heavy_heavy::cBinop_H0z671s7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_d0SPMOuS_sendMessage);
}

void Heavy_heavy::cBinop_d0SPMOuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZvM0gSnZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WLCV2hO9, m);
}

void Heavy_heavy::cBinop_ZvM0gSnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3E43c9JX, m);
}

void Heavy_heavy::cVar_VXAnUiwd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4xWnjC0, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y4xWnjC0_sendMessage);
}

void Heavy_heavy::cMsg_3tkVPJ7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.01f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0lRAJQcL, HV_BINOP_SUBTRACT, 0, m, &cBinop_0lRAJQcL_sendMessage);
}

void Heavy_heavy::cBinop_zPGoQhtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.3f, 0, m, &cBinop_8fqwHswU_sendMessage);
}

void Heavy_heavy::cUnop_6KCwviXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aEFMY7aa, 0, m, &cVar_aEFMY7aa_sendMessage);
}

void Heavy_heavy::cBinop_cqy9iqLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_geN2Da2d, 1, m, &cIf_geN2Da2d_sendMessage);
}

void Heavy_heavy::cIf_geN2Da2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_fhwpiQ3K_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6KCwviXH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_Xb0l53Ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cqy9iqLP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_geN2Da2d, 0, m, &cIf_geN2Da2d_sendMessage);
}

void Heavy_heavy::cUnop_fhwpiQ3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aEFMY7aa, 0, m, &cVar_aEFMY7aa_sendMessage);
}

void Heavy_heavy::cIf_WG2esvHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Igb1M5um, 0, m, &cIf_Igb1M5um_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_X0Ph3w5D, 0, m, &cIf_X0Ph3w5D_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_43JY95nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WG2esvHP, 1, m, &cIf_WG2esvHP_sendMessage);
}

void Heavy_heavy::cBinop_9MHkFG5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Igb1M5um, 0, m, &cIf_Igb1M5um_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_X0Ph3w5D, 0, m, &cIf_X0Ph3w5D_sendMessage);
}

void Heavy_heavy::cIf_M7i1PjBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9MHkFG5s, HV_BINOP_ADD, 0, m, &cBinop_9MHkFG5s_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_aEFMY7aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7iEyPd9l, HV_BINOP_ADD, 1, m, &cBinop_7iEyPd9l_sendMessage);
}

void Heavy_heavy::cVar_DKwNwPNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3GZpEG5v_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mLasln04_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_a33d8Sp9, 1, m, &cIf_a33d8Sp9_sendMessage);
}

void Heavy_heavy::cBinop_3GZpEG5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DKwNwPNr, 1, m, &cVar_DKwNwPNr_sendMessage);
}

void Heavy_heavy::cBinop_MVwXbFxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jfnhLgPN, 1, m, &cVar_jfnhLgPN_sendMessage);
}

void Heavy_heavy::cVar_jfnhLgPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MVwXbFxL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_43JY95nd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_M7i1PjBK, 1, m, &cIf_M7i1PjBK_sendMessage);
}

void Heavy_heavy::cBinop_VKBh5f7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yWJNnKbz, 1, m, &cVar_yWJNnKbz_sendMessage);
}

void Heavy_heavy::cVar_yWJNnKbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VKBh5f7S_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_CFevUYu3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wLifRQ3d, 1, m, &cIf_wLifRQ3d_sendMessage);
}

void Heavy_heavy::cVar_L4at7Ym6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yWJNnKbz, 0, m, &cVar_yWJNnKbz_sendMessage);
}

void Heavy_heavy::cVar_FQTjoxVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xb0l53Ww, 0, m, &cVar_Xb0l53Ww_sendMessage);
}

void Heavy_heavy::cBinop_xXCuKT4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X0Ph3w5D, 1, m, &cIf_X0Ph3w5D_sendMessage);
}

void Heavy_heavy::cBinop_3qbqfA3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZNzMm147, 0, m, &cIf_ZNzMm147_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_g6rmpJU6, 0, m, &cIf_g6rmpJU6_sendMessage);
}

void Heavy_heavy::cIf_X0Ph3w5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_ZNzMm147, 0, m, &cIf_ZNzMm147_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_g6rmpJU6, 0, m, &cIf_g6rmpJU6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_Igb1M5um_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3qbqfA3D, HV_BINOP_ADD, 0, m, &cBinop_3qbqfA3D_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_u1iU7Sl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L6Iedpw9, 1, m, &cVar_L6Iedpw9_sendMessage);
}

void Heavy_heavy::cVar_L6Iedpw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_u1iU7Sl4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_xXCuKT4T_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Igb1M5um, 1, m, &cIf_Igb1M5um_sendMessage);
}

void Heavy_heavy::cVar_ZrDyhwH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DKwNwPNr, 0, m, &cVar_DKwNwPNr_sendMessage);
}

void Heavy_heavy::cBinop_cFNfbyJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_g6rmpJU6, 1, m, &cIf_g6rmpJU6_sendMessage);
}

void Heavy_heavy::cIf_ZNzMm147_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PMrNwNvs, HV_BINOP_ADD, 0, m, &cBinop_PMrNwNvs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_g6rmpJU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_wLifRQ3d, 0, m, &cIf_wLifRQ3d_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_ReqMp5We, 0, m, &cIf_ReqMp5We_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_PMrNwNvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wLifRQ3d, 0, m, &cIf_wLifRQ3d_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ReqMp5We, 0, m, &cIf_ReqMp5We_sendMessage);
}

void Heavy_heavy::cVar_qpHAqH7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Cjh3B9Kw, 0, m, &cVar_Cjh3B9Kw_sendMessage);
}

void Heavy_heavy::cVar_DfPdsHid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FQTjoxVK, 0, m, &cVar_FQTjoxVK_sendMessage);
}

void Heavy_heavy::cIf_a33d8Sp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pQTfEm5L, HV_BINOP_ADD, 0, m, &cBinop_pQTfEm5L_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_pQTfEm5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M7i1PjBK, 0, m, &cIf_M7i1PjBK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WG2esvHP, 0, m, &cIf_WG2esvHP_sendMessage);
}

void Heavy_heavy::cIf_NfuSZzKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_M7i1PjBK, 0, m, &cIf_M7i1PjBK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_WG2esvHP, 0, m, &cIf_WG2esvHP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_mLasln04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NfuSZzKG, 1, m, &cIf_NfuSZzKG_sendMessage);
}

void Heavy_heavy::cSlice_DcOUjDyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9MHkFG5s, HV_BINOP_ADD, 1, m, &cBinop_9MHkFG5s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_x24KTBd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_FQTjoxVK, 0, m, &cVar_FQTjoxVK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_56NjVTbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_PMrNwNvs, HV_BINOP_ADD, 1, m, &cBinop_PMrNwNvs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_0XbJKEZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pQTfEm5L, HV_BINOP_ADD, 1, m, &cBinop_pQTfEm5L_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_0flqcDJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3qbqfA3D, HV_BINOP_ADD, 1, m, &cBinop_3qbqfA3D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_wLifRQ3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7iEyPd9l, HV_BINOP_ADD, 0, m, &cBinop_7iEyPd9l_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_7iEyPd9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oIfaaYrk, 0, m, &cVar_oIfaaYrk_sendMessage);
}

void Heavy_heavy::cBinop_CFevUYu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ReqMp5We, 1, m, &cIf_ReqMp5We_sendMessage);
}

void Heavy_heavy::cIf_ReqMp5We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_oIfaaYrk, 0, m, &cVar_oIfaaYrk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_v2ARCwao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jfnhLgPN, 0, m, &cVar_jfnhLgPN_sendMessage);
}

void Heavy_heavy::cBinop_9NpPLqeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Cjh3B9Kw, 1, m, &cVar_Cjh3B9Kw_sendMessage);
}

void Heavy_heavy::cVar_Cjh3B9Kw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_9NpPLqeI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_cFNfbyJF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZNzMm147, 1, m, &cIf_ZNzMm147_sendMessage);
}

void Heavy_heavy::cVar_gYfUn9NF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L6Iedpw9, 0, m, &cVar_L6Iedpw9_sendMessage);
}

void Heavy_heavy::cBinop_jj0pOXGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IG3YnYtj, 1, m, &cIf_IG3YnYtj_sendMessage);
}

void Heavy_heavy::cUnop_3Y91ulI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Beez2N0B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_B1VpNMdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Beez2N0B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_RWo9oYzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jj0pOXGE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IG3YnYtj, 0, m, &cIf_IG3YnYtj_sendMessage);
}

void Heavy_heavy::cIf_IG3YnYtj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_3Y91ulI0_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_B1VpNMdU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_3giVpwCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGv2eRz3, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZGv2eRz3_sendMessage);
}

void Heavy_heavy::cCast_BQr5sIWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a72d1fER_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_QOuXL72j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EOwrKIcI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_xOKZjsq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_a33d8Sp9, 0, m, &cIf_a33d8Sp9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NfuSZzKG, 0, m, &cIf_NfuSZzKG_sendMessage);
}

void Heavy_heavy::cVar_slLl5P4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jfW7akz2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_1lKpQrNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6r7Sjc0U, HV_BINOP_ADD, 1, m, &cBinop_6r7Sjc0U_sendMessage);
}

void Heavy_heavy::cCast_nsIMkVCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_znXSrI5P, 0, m, &cVar_znXSrI5P_sendMessage);
}

void Heavy_heavy::cMsg_tiBxNwqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ugL1WEX2, 0, m, &cDelay_ugL1WEX2_sendMessage);
}

void Heavy_heavy::cDelay_ugL1WEX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ugL1WEX2, m);
  cVar_onMessage(_c, &Context(_c)->cVar_slLl5P4L, 0, m, &cVar_slLl5P4L_sendMessage);
}

void Heavy_heavy::cCast_gZxacMHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ugL1WEX2, 0, m, &cDelay_ugL1WEX2_sendMessage);
}

void Heavy_heavy::cSwitchcase_9BQqfRur_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_tiBxNwqe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_tiBxNwqe_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ugL1WEX2, 1, m, &cDelay_ugL1WEX2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gZxacMHK_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_Ic55eZr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fRBabuDa, 0, m, NULL);
  cSwitchcase_oDt4xBF6_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_fRBabuDa, 0, m, NULL);
  cSwitchcase_oDt4xBF6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_Ce1JwVyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1lKpQrNA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kNvucmwo_sendMessage);
}

void Heavy_heavy::cBinop_6r7Sjc0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ugL1WEX2, 1, m, &cDelay_ugL1WEX2_sendMessage);
}

void Heavy_heavy::cMsg_jfW7akz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fRBabuDa, 0, m, NULL);
  cSwitchcase_oDt4xBF6_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_fRBabuDa, 0, m, NULL);
  cSwitchcase_oDt4xBF6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_znXSrI5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ic55eZr5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_kNvucmwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6r7Sjc0U, HV_BINOP_ADD, 0, m, &cBinop_6r7Sjc0U_sendMessage);
}

void Heavy_heavy::cVar_YY4EdWwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_znXSrI5P, 1, m, &cVar_znXSrI5P_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6r7Sjc0U, HV_BINOP_ADD, 0, m, &cBinop_6r7Sjc0U_sendMessage);
}

void Heavy_heavy::cVar_3QJeDOon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ce1JwVyU, 0, m, &cVar_Ce1JwVyU_sendMessage);
}

void Heavy_heavy::cCast_3X3oymyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wKlnfbCe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMKUnO9C, HV_BINOP_ADD, 0, m, &cBinop_fMKUnO9C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DE6Zz8Se, 1, m, &cVar_DE6Zz8Se_sendMessage);
}

void Heavy_heavy::cSlice_8zWh0Nu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I2Be023Y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3X3oymyF_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I2Be023Y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3X3oymyF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_BmEHfSuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_YI3wN0zF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_YI3wN0zF_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_oDt4xBF6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BmEHfSuz, 0, m, &cSlice_BmEHfSuz_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8zWh0Nu7, 0, m, &cSlice_8zWh0Nu7_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UqvZELhb_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MzYBtA74, 0, m, &cSlice_MzYBtA74_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_thkiCIq2, 0, m, &cSlice_thkiCIq2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oYROqBET_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pE4wHMh7_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_2wOM4Mqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d0XMJlJ2, 1, m, &cVar_d0XMJlJ2_sendMessage);
}

void Heavy_heavy::cCast_I2Be023Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YI3wN0zF_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_A5kUwlfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_4HLhmWAz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_V5bDnm3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XOlUMAuX, 1, m, &cVar_XOlUMAuX_sendMessage);
}

void Heavy_heavy::cCast_4q0Pjv8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0naLdcVc, 1, m, &cVar_0naLdcVc_sendMessage);
}

void Heavy_heavy::cMsg_aiT2JdlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1EBA07N3_sendMessage);
}

void Heavy_heavy::cSystem_1EBA07N3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ex9uIMKF, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ex9uIMKF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHMZw2NV, HV_BINOP_MULTIPLY, 1, m, &cBinop_jHMZw2NV_sendMessage);
}

void Heavy_heavy::cBinop_qFRZdWL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8dWgHZMB, HV_BINOP_DIVIDE, 0, m, &cBinop_8dWgHZMB_sendMessage);
}

void Heavy_heavy::cMsg_ZiCnnDSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ex9uIMKF, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ex9uIMKF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uwj9h1vF, HV_BINOP_DIVIDE, 1, m, &cBinop_uwj9h1vF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mX7ax9YV, 0, m, &cVar_mX7ax9YV_sendMessage);
}

void Heavy_heavy::cSlice_MzYBtA74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7oI8UwM4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qlp6D1md_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_thkiCIq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4q0Pjv8M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8thmh1ht_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_qlp6D1md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uwj9h1vF, HV_BINOP_DIVIDE, 0, m, &cBinop_uwj9h1vF_sendMessage);
}

void Heavy_heavy::cCast_wKlnfbCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5r0Pf3dh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_oYROqBET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A5kUwlfg_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_fMKUnO9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_P51YIGXq, 0, m, &cVar_P51YIGXq_sendMessage);
}

void Heavy_heavy::cBinop_x6fN36G8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ND6Sq3uZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_uwj9h1vF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8dWgHZMB, HV_BINOP_DIVIDE, 1, m, &cBinop_8dWgHZMB_sendMessage);
}

void Heavy_heavy::cVar_g4MWqp8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1WJ48VNl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_8dWgHZMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMKUnO9C, HV_BINOP_ADD, 1, m, &cBinop_fMKUnO9C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBGMVWgt, HV_BINOP_ADD, 1, m, &cBinop_jBGMVWgt_sendMessage);
}

void Heavy_heavy::cCast_JZaR7Xbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5r0Pf3dh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_UqvZELhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XOlUMAuX, 0, m, &cVar_XOlUMAuX_sendMessage);
}

void Heavy_heavy::cVar_XOlUMAuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7oI8UwM4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qlp6D1md_sendMessage);
}

void Heavy_heavy::cCast_7oI8UwM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jHMZw2NV, HV_BINOP_MULTIPLY, 0, m, &cBinop_jHMZw2NV_sendMessage);
}

void Heavy_heavy::cCast_pE4wHMh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V5bDnm3L_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_OvhISId7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9vYTz0ZD, HV_BINOP_SUBTRACT, 1, m, &cBinop_9vYTz0ZD_sendMessage);
}

void Heavy_heavy::cBinop_Ex9uIMKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OvhISId7_sendMessage);
}

void Heavy_heavy::cBinop_9vYTz0ZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d0XMJlJ2, 1, m, &cVar_d0XMJlJ2_sendMessage);
}

void Heavy_heavy::cMsg_kt9aeMaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u984ycQG_sendMessage);
}

void Heavy_heavy::cSystem_u984ycQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3cf4nxGh_sendMessage);
}

void Heavy_heavy::cSwitchcase_4HLhmWAz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_CjB6tDhE_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_CjB6tDhE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GuvObHyn_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_mX7ax9YV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRJO8DFw, HV_BINOP_MULTIPLY, 0, m, &cBinop_IRJO8DFw_sendMessage);
}

void Heavy_heavy::cMsg_CjB6tDhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_84IBLFXq, 0, m, &cDelay_84IBLFXq_sendMessage);
}

void Heavy_heavy::cBinop_IRJO8DFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1Ec5fYIr_sendMessage);
}

void Heavy_heavy::cCast_GuvObHyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CjB6tDhE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_84IBLFXq, 0, m, &cDelay_84IBLFXq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_d0XMJlJ2, 0, m, &cVar_d0XMJlJ2_sendMessage);
}

void Heavy_heavy::cBinop_1Ec5fYIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_84IBLFXq, 2, m, &cDelay_84IBLFXq_sendMessage);
}

void Heavy_heavy::cDelay_84IBLFXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_84IBLFXq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_84IBLFXq, 0, m, &cDelay_84IBLFXq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_d0XMJlJ2, 0, m, &cVar_d0XMJlJ2_sendMessage);
}

void Heavy_heavy::cBinop_3cf4nxGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRJO8DFw, HV_BINOP_MULTIPLY, 1, m, &cBinop_IRJO8DFw_sendMessage);
}

void Heavy_heavy::cCast_a9CJYiPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JZaR7Xbg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y47vAGq6_sendMessage);
}

void Heavy_heavy::cCast_ehD8xk8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DE6Zz8Se, 0, m, &cVar_DE6Zz8Se_sendMessage);
}

void Heavy_heavy::cSwitchcase_ND6Sq3uZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ehD8xk8X_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a9CJYiPW_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cMsg_5r0Pf3dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4HLhmWAz_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMKUnO9C, HV_BINOP_ADD, 1, m, &cBinop_fMKUnO9C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBGMVWgt, HV_BINOP_ADD, 1, m, &cBinop_jBGMVWgt_sendMessage);
}

void Heavy_heavy::cCast_8thmh1ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qFRZdWL9, HV_BINOP_SUBTRACT, 0, m, &cBinop_qFRZdWL9_sendMessage);
}

void Heavy_heavy::cCast_Y47vAGq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0naLdcVc, 0, m, &cVar_0naLdcVc_sendMessage);
}

void Heavy_heavy::cVar_P51YIGXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qFRZdWL9, HV_BINOP_SUBTRACT, 1, m, &cBinop_qFRZdWL9_sendMessage);
}

void Heavy_heavy::cVar_0naLdcVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DE6Zz8Se, 0, m, &cVar_DE6Zz8Se_sendMessage);
}

void Heavy_heavy::cMsg_YI3wN0zF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4HLhmWAz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_bu5zGEHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZiCnnDSC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_1WJ48VNl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bu5zGEHF_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ex9uIMKF, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ex9uIMKF_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_uwj9h1vF, HV_BINOP_DIVIDE, 1, m, &cBinop_uwj9h1vF_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_mX7ax9YV, 0, m, &cVar_mX7ax9YV_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_jBGMVWgt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DE6Zz8Se, 1, m, &cVar_DE6Zz8Se_sendMessage);
}

void Heavy_heavy::cVar_d0XMJlJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9vYTz0ZD, HV_BINOP_SUBTRACT, 0, m, &cBinop_9vYTz0ZD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_x6fN36G8_sendMessage);
}

void Heavy_heavy::cBinop_jHMZw2NV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2wOM4Mqv_sendMessage);
}

void Heavy_heavy::cVar_DE6Zz8Se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBGMVWgt, HV_BINOP_ADD, 0, m, &cBinop_jBGMVWgt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fMKUnO9C, HV_BINOP_ADD, 0, m, &cBinop_fMKUnO9C_sendMessage);
}

void Heavy_heavy::cVar_pnBtLuBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9I9aEcZl, 0, m, &cVar_9I9aEcZl_sendMessage);
}

void Heavy_heavy::cVar_y1HygRmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YY4EdWwD, 0, m, &cVar_YY4EdWwD_sendMessage);
}

void Heavy_heavy::cVar_9I9aEcZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_slLl5P4L, 1, m, &cVar_slLl5P4L_sendMessage);
}

void Heavy_heavy::cCast_WNG0cRY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9BQqfRur_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_i3UGYzK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iOMNU6H1, 0, m, &cVar_iOMNU6H1_sendMessage);
}

void Heavy_heavy::cBinop_g69ohnbY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3QJeDOon, 0, m, &cVar_3QJeDOon_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8UrSrmUo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CzlbCFod_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dOiM3J7L_sendMessage);
}

void Heavy_heavy::cBinop_wXlN1JPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YtSyZdET_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_8fqwHswU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BA7bmdYm, 0, m, &cVar_BA7bmdYm_sendMessage);
}

void Heavy_heavy::cCast_kfJiBe1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iOMNU6H1, 1, m, &cVar_iOMNU6H1_sendMessage);
}

void Heavy_heavy::cCast_8UrSrmUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3giVpwCd, 1, m, &cVar_3giVpwCd_sendMessage);
}

void Heavy_heavy::cSend_oH9YTO57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_llw9oRgm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_zv7FgbVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y2TatLGC, 0, m, &cVar_y2TatLGC_sendMessage);
}

void Heavy_heavy::cBinop_bNjUIuGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pjjaKdE4, 1, m, &cIf_pjjaKdE4_sendMessage);
}

void Heavy_heavy::cBinop_O25lSxq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bi7GJVPU, 0, m, &cVar_bi7GJVPU_sendMessage);
}

void Heavy_heavy::cIf_Ov4uHqXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_O25lSxq7, HV_BINOP_ADD, 0, m, &cBinop_O25lSxq7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_pjjaKdE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_bi7GJVPU, 0, m, &cVar_bi7GJVPU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_CuMlmztf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qckLs1dM, 1, m, &cVar_qckLs1dM_sendMessage);
}

void Heavy_heavy::cVar_qckLs1dM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_CuMlmztf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8AnaRJS1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jV4mWyb7, 1, m, &cIf_jV4mWyb7_sendMessage);
}

void Heavy_heavy::cBinop_Vr0EucFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_v6TqM15A, 0, m, &cIf_v6TqM15A_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gSxUNxP2, 0, m, &cIf_gSxUNxP2_sendMessage);
}

void Heavy_heavy::cBinop_8AnaRJS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y3TyaMch, 1, m, &cIf_y3TyaMch_sendMessage);
}

void Heavy_heavy::cIf_jV4mWyb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Vr0EucFF, HV_BINOP_ADD, 0, m, &cBinop_Vr0EucFF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_y3TyaMch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_v6TqM15A, 0, m, &cIf_v6TqM15A_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_gSxUNxP2, 0, m, &cIf_gSxUNxP2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_doXaXje2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lHfwTI8Y, 1, m, &cIf_lHfwTI8Y_sendMessage);
}

void Heavy_heavy::cVar_AlGwqEbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_doXaXje2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lHfwTI8Y, 0, m, &cIf_lHfwTI8Y_sendMessage);
}

void Heavy_heavy::cIf_lHfwTI8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_YWe7yuo8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AwIU7mhz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_AwIU7mhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zf21cETL, 0, m, &cVar_Zf21cETL_sendMessage);
}

void Heavy_heavy::cUnop_YWe7yuo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zf21cETL, 0, m, &cVar_Zf21cETL_sendMessage);
}

void Heavy_heavy::cVar_2ylSQA4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j5xePO9W, 0, m, &cVar_j5xePO9W_sendMessage);
}

void Heavy_heavy::cSlice_poZbF4CT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Luo4DNbj, HV_BINOP_ADD, 1, m, &cBinop_Luo4DNbj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_ms63WDtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4fn3UgnI, HV_BINOP_ADD, 1, m, &cBinop_4fn3UgnI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_u1j7qqlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TEgUskHU, HV_BINOP_ADD, 1, m, &cBinop_TEgUskHU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_8qgDCn8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_y2TatLGC, 0, m, &cVar_y2TatLGC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_JzCNYX3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Vr0EucFF, HV_BINOP_ADD, 1, m, &cBinop_Vr0EucFF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_URp0LRw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mcGF2CQ0, 0, m, &cVar_mcGF2CQ0_sendMessage);
}

void Heavy_heavy::cIf_iwpWQoUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_4fn3UgnI, HV_BINOP_ADD, 0, m, &cBinop_4fn3UgnI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_4EfY4yhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QHWBMH4N, 1, m, &cIf_QHWBMH4N_sendMessage);
}

void Heavy_heavy::cIf_QHWBMH4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Ov4uHqXs, 0, m, &cIf_Ov4uHqXs_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_pjjaKdE4, 0, m, &cIf_pjjaKdE4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_4fn3UgnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ov4uHqXs, 0, m, &cIf_Ov4uHqXs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pjjaKdE4, 0, m, &cIf_pjjaKdE4_sendMessage);
}

void Heavy_heavy::cBinop_XoCedS4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_j5xePO9W, 1, m, &cVar_j5xePO9W_sendMessage);
}

void Heavy_heavy::cVar_j5xePO9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_XoCedS4t_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_dsJNi0Pp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_v6TqM15A, 1, m, &cIf_v6TqM15A_sendMessage);
}

void Heavy_heavy::cIf_gIBYA9Vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Luo4DNbj, HV_BINOP_ADD, 0, m, &cBinop_Luo4DNbj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_zAIgie2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_jV4mWyb7, 0, m, &cIf_jV4mWyb7_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_y3TyaMch, 0, m, &cIf_y3TyaMch_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Luo4DNbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jV4mWyb7, 0, m, &cIf_jV4mWyb7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_y3TyaMch, 0, m, &cIf_y3TyaMch_sendMessage);
}

void Heavy_heavy::cBinop_g8BITmvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zAIgie2n, 1, m, &cIf_zAIgie2n_sendMessage);
}

void Heavy_heavy::cVar_9s7ZODJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DhyPcxZH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_g8BITmvS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gIBYA9Vi, 1, m, &cIf_gIBYA9Vi_sendMessage);
}

void Heavy_heavy::cBinop_DhyPcxZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9s7ZODJ5, 1, m, &cVar_9s7ZODJ5_sendMessage);
}

void Heavy_heavy::cVar_0lEe6iCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9s7ZODJ5, 0, m, &cVar_9s7ZODJ5_sendMessage);
}

void Heavy_heavy::cVar_hPqVUX6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tiVHQILs, 0, m, &cVar_tiVHQILs_sendMessage);
}

void Heavy_heavy::cVar_y2TatLGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AlGwqEbu, 0, m, &cVar_AlGwqEbu_sendMessage);
}

void Heavy_heavy::cVar_JhJzOplK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qckLs1dM, 0, m, &cVar_qckLs1dM_sendMessage);
}

void Heavy_heavy::cVar_Zf21cETL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O25lSxq7, HV_BINOP_ADD, 1, m, &cBinop_O25lSxq7_sendMessage);
}

void Heavy_heavy::cVar_tiVHQILs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_I6y4zWFn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bNjUIuGc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Ov4uHqXs, 1, m, &cIf_Ov4uHqXs_sendMessage);
}

void Heavy_heavy::cBinop_I6y4zWFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tiVHQILs, 1, m, &cVar_tiVHQILs_sendMessage);
}

void Heavy_heavy::cBinop_IKVpZNCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mcGF2CQ0, 1, m, &cVar_mcGF2CQ0_sendMessage);
}

void Heavy_heavy::cVar_mcGF2CQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IKVpZNCm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4EfY4yhl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iwpWQoUf, 1, m, &cIf_iwpWQoUf_sendMessage);
}

void Heavy_heavy::cBinop_dsJNi0Pp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gSxUNxP2, 1, m, &cIf_gSxUNxP2_sendMessage);
}

void Heavy_heavy::cIf_gSxUNxP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_iwpWQoUf, 0, m, &cIf_iwpWQoUf_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_QHWBMH4N, 0, m, &cIf_QHWBMH4N_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_v6TqM15A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TEgUskHU, HV_BINOP_ADD, 0, m, &cBinop_TEgUskHU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_TEgUskHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iwpWQoUf, 0, m, &cIf_iwpWQoUf_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_QHWBMH4N, 0, m, &cIf_QHWBMH4N_sendMessage);
}

void Heavy_heavy::cMsg_UXLBtpOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4300.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3FZxheMK, HV_BINOP_SUBTRACT, 0, m, &cBinop_3FZxheMK_sendMessage);
}

void Heavy_heavy::cReceive_llw9oRgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_g69ohnbY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_hBWDjJXd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_pit2GdfN_sendMessage);
}

void Heavy_heavy::cBinop_wyAG1vR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y2TatLGC, 0, m, &cVar_y2TatLGC_sendMessage);
}

void Heavy_heavy::cUnop_x9uZjC32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jSDEvjGr, 0, m, &cVar_jSDEvjGr_sendMessage);
}

void Heavy_heavy::cBinop_LN1yC3B5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Zyz4QrKK, 1, m, &cIf_Zyz4QrKK_sendMessage);
}

void Heavy_heavy::cIf_Zyz4QrKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Mw04LXHq_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_x9uZjC32_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_hhmFmmkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LN1yC3B5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Zyz4QrKK, 0, m, &cIf_Zyz4QrKK_sendMessage);
}

void Heavy_heavy::cUnop_Mw04LXHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jSDEvjGr, 0, m, &cVar_jSDEvjGr_sendMessage);
}

void Heavy_heavy::cVar_nxJps3eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_VL9MkOtD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b48cWL7X, 0, m, &cIf_b48cWL7X_sendMessage);
}

void Heavy_heavy::cBinop_VL9MkOtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b48cWL7X, 1, m, &cIf_b48cWL7X_sendMessage);
}

void Heavy_heavy::cUnop_8KnysbtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z5U7luWV, 0, m, &cVar_Z5U7luWV_sendMessage);
}

void Heavy_heavy::cIf_b48cWL7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_WaBCqHpG_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8KnysbtS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_WaBCqHpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z5U7luWV, 0, m, &cVar_Z5U7luWV_sendMessage);
}

void Heavy_heavy::cBinop_2ZYUyIKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFvpKkAb, HV_BINOP_MULTIPLY, 0, m, &cBinop_pFvpKkAb_sendMessage);
}

void Heavy_heavy::cVar_87J9BtnB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFvpKkAb, HV_BINOP_MULTIPLY, 1, m, &cBinop_pFvpKkAb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C5Q3MtKX, HV_BINOP_LESS_THAN, 1, m, &cBinop_C5Q3MtKX_sendMessage);
}

void Heavy_heavy::cBinop_JhSgJyu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lklQ4WuW, 1, m, &cVar_lklQ4WuW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ZYUyIKK, HV_BINOP_ADD, 0, m, &cBinop_2ZYUyIKK_sendMessage);
}

void Heavy_heavy::cBinop_jVV780WJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EPuf5Wds, 1, m, &cIf_EPuf5Wds_sendMessage);
}

void Heavy_heavy::cVar_haDczaSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_jVV780WJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EPuf5Wds, 0, m, &cIf_EPuf5Wds_sendMessage);
}

void Heavy_heavy::cUnop_UqmWwvsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_87J9BtnB, 0, m, &cVar_87J9BtnB_sendMessage);
}

void Heavy_heavy::cUnop_bRJ3q2vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_87J9BtnB, 0, m, &cVar_87J9BtnB_sendMessage);
}

void Heavy_heavy::cIf_EPuf5Wds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_UqmWwvsw_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bRJ3q2vi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_2VzcVne6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nxJps3eb, 0, m, &cVar_nxJps3eb_sendMessage);
}

void Heavy_heavy::cVar_Z5U7luWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2ZYUyIKK, HV_BINOP_ADD, 1, m, &cBinop_2ZYUyIKK_sendMessage);
}

void Heavy_heavy::cVar_jSDEvjGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MPYlSnG5, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_MPYlSnG5_sendMessage);
}

void Heavy_heavy::cBinop_MPYlSnG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C5Q3MtKX, HV_BINOP_LESS_THAN, 0, m, &cBinop_C5Q3MtKX_sendMessage);
}

void Heavy_heavy::cCast_sXIYfJQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_lklQ4WuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JhSgJyu7_sendMessage);
}

void Heavy_heavy::cVar_M50xoup2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_haDczaSF, 0, m, &cVar_haDczaSF_sendMessage);
}

void Heavy_heavy::cVar_XlbLbBRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hhmFmmkR, 0, m, &cVar_hhmFmmkR_sendMessage);
}

void Heavy_heavy::cCast_b3wsYb7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sXIYfJQ2_sendMessage);
}

void Heavy_heavy::cSwitchcase_Z6v8YPzk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b3wsYb7k_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F4ImiMuu_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_C5Q3MtKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Z6v8YPzk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_pFvpKkAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MPYlSnG5, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_MPYlSnG5_sendMessage);
}

void Heavy_heavy::cCast_F4ImiMuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jbzuhYjB, 0, m, &cVar_jbzuhYjB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Cjh3B9Kw, 0, m, &cVar_Cjh3B9Kw_sendMessage);
}

void Heavy_heavy::cVar_fhFTtxdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mOvYRsvv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_bdlYadcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 3.0f, 0, m, &cBinop_wyAG1vR2_sendMessage);
}

void Heavy_heavy::cBinop_y245RhNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eF92Mis9, 0, m, &cVar_eF92Mis9_sendMessage);
}

void Heavy_heavy::cBinop_vyefIjRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mOvYRsvv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_QHvbNCZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_b9EpYEl8_sendMessage);
}

void Heavy_heavy::cBinop_IxutTyQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_ZJQs4obA_sendMessage);
}

void Heavy_heavy::cIf_CJqK0bKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_9Urlb7I8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rCjQm539_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_9Urlb7I8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gIBYA9Vi, 0, m, &cIf_gIBYA9Vi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zAIgie2n, 0, m, &cIf_zAIgie2n_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_FldTJrzs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_xOKZjsq2_sendMessage);
}

void Heavy_heavy::cVar_irEwjTXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8qrymJ6M_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CJqK0bKZ, 0, m, &cIf_CJqK0bKZ_sendMessage);
}

void Heavy_heavy::cBinop_8qrymJ6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CJqK0bKZ, 1, m, &cIf_CJqK0bKZ_sendMessage);
}

void Heavy_heavy::cUnop_rCjQm539_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gIBYA9Vi, 0, m, &cIf_gIBYA9Vi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zAIgie2n, 0, m, &cIf_zAIgie2n_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_FldTJrzs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_xOKZjsq2_sendMessage);
}

void Heavy_heavy::hTable_0e8IEloG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_ZJQs4obA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FQTjoxVK, 0, m, &cVar_FQTjoxVK_sendMessage);
}

void Heavy_heavy::cCast_0Yua2BMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qckLs1dM, 0, m, &cVar_qckLs1dM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tiVHQILs, 0, m, &cVar_tiVHQILs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jfnhLgPN, 0, m, &cVar_jfnhLgPN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yP7DEtcM, 0, m, &cVar_yP7DEtcM_sendMessage);
}

void Heavy_heavy::cBinop_2zvC1nMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_itGJ8SSc, HV_BINOP_LESS_THAN, 0, m, &cBinop_itGJ8SSc_sendMessage);
}

void Heavy_heavy::cVar_bCob2Buz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_n9yNVZt6_sendMessage);
}

void Heavy_heavy::cBinop_n9yNVZt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bCob2Buz, 1, m, &cVar_bCob2Buz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBvp9ptm, HV_BINOP_ADD, 0, m, &cBinop_yBvp9ptm_sendMessage);
}

void Heavy_heavy::cVar_YnkJyax9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWd73pAL, HV_BINOP_MULTIPLY, 1, m, &cBinop_nWd73pAL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_itGJ8SSc, HV_BINOP_LESS_THAN, 1, m, &cBinop_itGJ8SSc_sendMessage);
}

void Heavy_heavy::cUnop_qK6dkXsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2u6CoMWM, 0, m, &cVar_2u6CoMWM_sendMessage);
}

void Heavy_heavy::cVar_9c4gvwKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_i9Qde8vY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rKJiU6oI, 0, m, &cIf_rKJiU6oI_sendMessage);
}

void Heavy_heavy::cUnop_cTUM4hdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2u6CoMWM, 0, m, &cVar_2u6CoMWM_sendMessage);
}

void Heavy_heavy::cBinop_i9Qde8vY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rKJiU6oI, 1, m, &cIf_rKJiU6oI_sendMessage);
}

void Heavy_heavy::cIf_rKJiU6oI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_qK6dkXsn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cTUM4hdQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_nWd73pAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zvC1nMQ, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_2zvC1nMQ_sendMessage);
}

void Heavy_heavy::cVar_2u6CoMWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBvp9ptm, HV_BINOP_ADD, 1, m, &cBinop_yBvp9ptm_sendMessage);
}

void Heavy_heavy::cBinop_yBvp9ptm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWd73pAL, HV_BINOP_MULTIPLY, 0, m, &cBinop_nWd73pAL_sendMessage);
}

void Heavy_heavy::cBinop_Q3Ke2aX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Qk7tvjL6, 1, m, &cIf_Qk7tvjL6_sendMessage);
}

void Heavy_heavy::cUnop_JCiinqrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1ek9dRMe, 0, m, &cVar_1ek9dRMe_sendMessage);
}

void Heavy_heavy::cVar_7zcAFrUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Q3Ke2aX7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Qk7tvjL6, 0, m, &cIf_Qk7tvjL6_sendMessage);
}

void Heavy_heavy::cIf_Qk7tvjL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_YYQMykYU_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_JCiinqrT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_YYQMykYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1ek9dRMe, 0, m, &cVar_1ek9dRMe_sendMessage);
}

void Heavy_heavy::cVar_1ek9dRMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zvC1nMQ, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_2zvC1nMQ_sendMessage);
}

void Heavy_heavy::cCast_oudRhRZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_ykrJ9b6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7zcAFrUo, 0, m, &cVar_7zcAFrUo_sendMessage);
}

void Heavy_heavy::cBinop_itGJ8SSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1aqj7Cm1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_kbcmMm7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oudRhRZZ_sendMessage);
}

void Heavy_heavy::cSwitchcase_1aqj7Cm1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kbcmMm7k_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Yua2BMO_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cUnop_ImgUxLRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnkJyax9, 0, m, &cVar_YnkJyax9_sendMessage);
}

void Heavy_heavy::cUnop_81NZ4HMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnkJyax9, 0, m, &cVar_YnkJyax9_sendMessage);
}

void Heavy_heavy::cBinop_rZGOcxcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_A41ARwKz, 1, m, &cIf_A41ARwKz_sendMessage);
}

void Heavy_heavy::cVar_bEPhmoI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_rZGOcxcb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_A41ARwKz, 0, m, &cIf_A41ARwKz_sendMessage);
}

void Heavy_heavy::cIf_A41ARwKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ImgUxLRO_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_81NZ4HMe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_VdVyznpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9c4gvwKl, 0, m, &cVar_9c4gvwKl_sendMessage);
}

void Heavy_heavy::cVar_Z5TVikAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bEPhmoI4, 0, m, &cVar_bEPhmoI4_sendMessage);
}

void Heavy_heavy::cVar_vf7ENkBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EaPUMS8W, HV_BINOP_MULTIPLY, 1, m, &cBinop_EaPUMS8W_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVXsJRdM, HV_BINOP_LESS_THAN, 1, m, &cBinop_yVXsJRdM_sendMessage);
}

void Heavy_heavy::cBinop_XeY4XqDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M3U7coEX, 1, m, &cVar_M3U7coEX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XC5wlGwZ, HV_BINOP_ADD, 0, m, &cBinop_XC5wlGwZ_sendMessage);
}

void Heavy_heavy::cCast_B7LgBFWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SNMTTyYW_sendMessage);
}

void Heavy_heavy::cSwitchcase_uJQJWpIQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B7LgBFWr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_badgvW0k_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_L3mQzZZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oMylLNot, 0, m, &cVar_oMylLNot_sendMessage);
}

void Heavy_heavy::cCast_SNMTTyYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_5RBzp7GF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVXsJRdM, HV_BINOP_LESS_THAN, 0, m, &cBinop_yVXsJRdM_sendMessage);
}

void Heavy_heavy::cBinop_XC5wlGwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EaPUMS8W, HV_BINOP_MULTIPLY, 0, m, &cBinop_EaPUMS8W_sendMessage);
}

void Heavy_heavy::cBinop_EaPUMS8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RBzp7GF, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_5RBzp7GF_sendMessage);
}

void Heavy_heavy::cBinop_yVXsJRdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uJQJWpIQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_JFflS1tQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_18U4NBSj, 0, m, &cVar_18U4NBSj_sendMessage);
}

void Heavy_heavy::cVar_IFcDYXyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5RBzp7GF, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_5RBzp7GF_sendMessage);
}

void Heavy_heavy::cCast_badgvW0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mcGF2CQ0, 0, m, &cVar_mcGF2CQ0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yWJNnKbz, 0, m, &cVar_yWJNnKbz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vi7Gq1kH, 0, m, &cVar_vi7Gq1kH_sendMessage);
}

void Heavy_heavy::cVar_Qd34HC3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XC5wlGwZ, HV_BINOP_ADD, 1, m, &cBinop_XC5wlGwZ_sendMessage);
}

void Heavy_heavy::cUnop_nunCdpCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vf7ENkBY, 0, m, &cVar_vf7ENkBY_sendMessage);
}

void Heavy_heavy::cUnop_YHAkgMJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vf7ENkBY, 0, m, &cVar_vf7ENkBY_sendMessage);
}

void Heavy_heavy::cBinop_LC5eNe65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_J4j3YY1W, 1, m, &cIf_J4j3YY1W_sendMessage);
}

void Heavy_heavy::cVar_8PDLEOaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LC5eNe65_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_J4j3YY1W, 0, m, &cIf_J4j3YY1W_sendMessage);
}

void Heavy_heavy::cIf_J4j3YY1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_YHAkgMJh_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nunCdpCX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_gqh1PB2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8PDLEOaT, 0, m, &cVar_8PDLEOaT_sendMessage);
}

void Heavy_heavy::cVar_18U4NBSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_D3UO61ny_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_E6y2Mn6q, 0, m, &cIf_E6y2Mn6q_sendMessage);
}

void Heavy_heavy::cUnop_Lv87szfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IFcDYXyU, 0, m, &cVar_IFcDYXyU_sendMessage);
}

void Heavy_heavy::cIf_E6y2Mn6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Lv87szfo_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RhQZ27Tw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_RhQZ27Tw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IFcDYXyU, 0, m, &cVar_IFcDYXyU_sendMessage);
}

void Heavy_heavy::cBinop_D3UO61ny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_E6y2Mn6q, 1, m, &cIf_E6y2Mn6q_sendMessage);
}

void Heavy_heavy::cVar_M3U7coEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XeY4XqDy_sendMessage);
}

void Heavy_heavy::cVar_oMylLNot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hfLz7S76_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tnvOoxdZ, 0, m, &cIf_tnvOoxdZ_sendMessage);
}

void Heavy_heavy::cUnop_VlX9bOtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qd34HC3r, 0, m, &cVar_Qd34HC3r_sendMessage);
}

void Heavy_heavy::cUnop_gwVDZS3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qd34HC3r, 0, m, &cVar_Qd34HC3r_sendMessage);
}

void Heavy_heavy::cBinop_hfLz7S76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tnvOoxdZ, 1, m, &cIf_tnvOoxdZ_sendMessage);
}

void Heavy_heavy::cIf_tnvOoxdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_VlX9bOtU_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_gwVDZS3b_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_AFN3YNOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hum7u1pp, 0, m, &cVar_Hum7u1pp_sendMessage);
}

void Heavy_heavy::cBinop_nB1Gu4kh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZfvEIDXQ, m);
}

void Heavy_heavy::cBinop_oU6r6iER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xhJpgQT6, m);
}

void Heavy_heavy::cVar_ndea89W1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eWnzkvzj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_D0W9PWPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oU6r6iER_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_g2fpaD8c, m);
}

void Heavy_heavy::cSystem_D3RibnyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nB1Gu4kh_sendMessage);
}

void Heavy_heavy::cMsg_64gxnb3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D3RibnyG_sendMessage);
}

void Heavy_heavy::cMsg_eWnzkvzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D0W9PWPA_sendMessage);
}

void Heavy_heavy::cCast_sQbr5aMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S12kC7dh, HV_BINOP_MULTIPLY, 1, m, &cBinop_S12kC7dh_sendMessage);
}

void Heavy_heavy::cBinop_mSTxBLyj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_o8wC4amS_sendMessage);
}

void Heavy_heavy::cBinop_L1QxhCaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_VdRVvNCF_sendMessage);
}

void Heavy_heavy::cCast_F6IM34bY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hum7u1pp, 0, m, &cVar_Hum7u1pp_sendMessage);
}

void Heavy_heavy::cCast_zTj4J0TZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSTxBLyj, HV_BINOP_SUBTRACT, 1, m, &cBinop_mSTxBLyj_sendMessage);
}

void Heavy_heavy::cVar_Lf9qbP38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eF92Mis9, 0, m, &cVar_eF92Mis9_sendMessage);
}

void Heavy_heavy::cVar_9Rt8TT9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AFN3YNOI, 0, m, &cVar_AFN3YNOI_sendMessage);
}

void Heavy_heavy::cBinop_7yC9vPHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UkQegLW5_sendMessage);
}

void Heavy_heavy::cBinop_UkQegLW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_agVpjrxC, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NFzRXMOM, m);
}

void Heavy_heavy::cVar_M3ak4vLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_srNKr8HQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r6RYhQ21_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zTj4J0TZ_sendMessage);
}

void Heavy_heavy::cBinop_S12kC7dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zBda0AO2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cUnop_srNKr8HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mqF1LOL2, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xTaLCdcf, m);
}

void Heavy_heavy::cUnop_o8wC4amS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rpNvROxU, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WtHlQeQv, m);
}

void Heavy_heavy::cBinop_9th3a8Ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_qDaUzm9x_sendMessage);
}

void Heavy_heavy::hTable_QKuz4X29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IpzGiksd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWbNFHq0, 2, m, &cDelay_MWbNFHq0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9ZKVN8Hp_sendMessage);
}

void Heavy_heavy::cMsg_IpzGiksd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wry86EPP, 2, m, &cDelay_wry86EPP_sendMessage);
}

void Heavy_heavy::cDelay_wry86EPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wry86EPP, m);
  cMsg_EhcR1dsw_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_HPNDxU0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_QKuz4X29, 0, m, &hTable_QKuz4X29_sendMessage);
}

void Heavy_heavy::cMsg_EhcR1dsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_QKuz4X29, 0, m, &hTable_QKuz4X29_sendMessage);
}

void Heavy_heavy::cCast_9ZKVN8Hp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWbNFHq0, 0, m, &cDelay_MWbNFHq0_sendMessage);
}

void Heavy_heavy::cBinop_qDaUzm9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HPNDxU0U_sendMessage(_c, 0, m);
}

void Heavy_heavy::cDelay_MWbNFHq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MWbNFHq0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wry86EPP, 0, m, &cDelay_wry86EPP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MWbNFHq0, 0, m, &cDelay_MWbNFHq0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YRTYe6G2, 1, m, NULL);
}

void Heavy_heavy::cSystem_Xz7S3Gan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9th3a8Ls_sendMessage);
}

void Heavy_heavy::cMsg_4W0IcQaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Xz7S3Gan_sendMessage);
}

void Heavy_heavy::cVar_Ns0Yrem9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_L1QxhCaO_sendMessage);
}

void Heavy_heavy::cVar_gY76JK2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ns0Yrem9, 0, m, &cVar_Ns0Yrem9_sendMessage);
}

void Heavy_heavy::cCast_r6RYhQ21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WZJ1PhI9_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_M6lxg99r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TGgUlOr8_sendMessage);
}

void Heavy_heavy::cMsg_xDsILz4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M6lxg99r_sendMessage);
}

void Heavy_heavy::cBinop_1KmFcCTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9kQARwGG, m);
}

void Heavy_heavy::cMsg_l0JQDWFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R7BQfiiS_sendMessage);
}

void Heavy_heavy::cSystem_R7BQfiiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1KmFcCTM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KZWRv8U4, m);
}

void Heavy_heavy::cVar_z0Hrrcz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l0JQDWFN_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_TGgUlOr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PbwaFKCN, m);
}

void Heavy_heavy::cVar_aZ7KMxy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M3ak4vLQ, 0, m, &cVar_M3ak4vLQ_sendMessage);
}

void Heavy_heavy::cBinop_pit2GdfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sQbr5aMh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F6IM34bY_sendMessage);
}

void Heavy_heavy::cBinop_oUPcelPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_X2KnpZmA_sendMessage);
}

void Heavy_heavy::cMsg_b3h0UMLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7PULC66x_sendMessage);
}

void Heavy_heavy::cMsg_OpWESe3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kd69w0BT_sendMessage);
}

void Heavy_heavy::cSystem_Kd69w0BT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b3h0UMLg_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_7PULC66x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oUPcelPX, HV_BINOP_MULTIPLY, 1, m, &cBinop_oUPcelPX_sendMessage);
}

void Heavy_heavy::cBinop_dGIKiRT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rHmZR8NE, m);
}

void Heavy_heavy::cBinop_b1NMU6C2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dGIKiRT3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YVGTsPvm, m);
}

void Heavy_heavy::cBinop_X2KnpZmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_b1NMU6C2_sendMessage);
}

void Heavy_heavy::cVar_q8SXt3iK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oUPcelPX, HV_BINOP_MULTIPLY, 0, m, &cBinop_oUPcelPX_sendMessage);
}

void Heavy_heavy::cVar_jHORJlME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwLXcgM7, HV_BINOP_MULTIPLY, 0, m, &cBinop_xwLXcgM7_sendMessage);
}

void Heavy_heavy::cSystem_Axjp0yzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jDpZgY3K_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_4EAFfofH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Axjp0yzh_sendMessage);
}

void Heavy_heavy::cMsg_jDpZgY3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mR4eFYBx_sendMessage);
}

void Heavy_heavy::cBinop_mR4eFYBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwLXcgM7, HV_BINOP_MULTIPLY, 1, m, &cBinop_xwLXcgM7_sendMessage);
}

void Heavy_heavy::cBinop_xwLXcgM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nz81IAZC_sendMessage);
}

void Heavy_heavy::cBinop_iS18kCPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5Ta8hJCX, m);
}

void Heavy_heavy::cBinop_nz81IAZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yRPM6yTj_sendMessage);
}

void Heavy_heavy::cBinop_yRPM6yTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iS18kCPM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0GZhqeMB, m);
}

void Heavy_heavy::cVar_eF92Mis9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.99f, 0, m, &cBinop_7yC9vPHj_sendMessage);
}

void Heavy_heavy::cBinop_uVo74rjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jHORJlME, 0, m, &cVar_jHORJlME_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q8SXt3iK, 0, m, &cVar_q8SXt3iK_sendMessage);
}

void Heavy_heavy::cBinop_2zyYLWcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_uVo74rjL_sendMessage);
}

void Heavy_heavy::cBinop_VdRVvNCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ngzBKdky_sendMessage);
}

void Heavy_heavy::cMsg_tQ6e9RFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zyYLWcf, HV_BINOP_POW, 0, m, &cBinop_2zyYLWcf_sendMessage);
}

void Heavy_heavy::cBinop_ngzBKdky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2zyYLWcf, HV_BINOP_POW, 1, m, &cBinop_2zyYLWcf_sendMessage);
  cMsg_tQ6e9RFR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_zBda0AO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DRF1CdF6, 0, m, NULL);
}

void Heavy_heavy::cBinop_pKbAU88a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_35PgJH4F_sendMessage(_c, 0, m);
}

void Heavy_heavy::hTable_HkUzahtH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uJxjNkk6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ntzZeyFc, 2, m, &cDelay_ntzZeyFc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JjnK2vgd_sendMessage);
}

void Heavy_heavy::cCast_JjnK2vgd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ntzZeyFc, 0, m, &cDelay_ntzZeyFc_sendMessage);
}

void Heavy_heavy::cMsg_uJxjNkk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_AVEs1Par, 2, m, &cDelay_AVEs1Par_sendMessage);
}

void Heavy_heavy::cMsg_eZf9EFlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tl9bvxBq_sendMessage);
}

void Heavy_heavy::cSystem_tl9bvxBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fCtAXcMm_sendMessage);
}

void Heavy_heavy::cMsg_usnI4oMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HkUzahtH, 0, m, &hTable_HkUzahtH_sendMessage);
}

void Heavy_heavy::cDelay_ntzZeyFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ntzZeyFc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_AVEs1Par, 0, m, &cDelay_AVEs1Par_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ntzZeyFc, 0, m, &cDelay_ntzZeyFc_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_l1XuuK90, 1, m, NULL);
}

void Heavy_heavy::cMsg_35PgJH4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HkUzahtH, 0, m, &hTable_HkUzahtH_sendMessage);
}

void Heavy_heavy::cDelay_AVEs1Par_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_AVEs1Par, m);
  cMsg_usnI4oMm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_fCtAXcMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_pKbAU88a_sendMessage);
}

void Heavy_heavy::cBinop_3uKK1jgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aFgXVYeA, 1, m, &cIf_aFgXVYeA_sendMessage);
}

void Heavy_heavy::cUnop_IhSmt6NK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S12kC7dh, HV_BINOP_MULTIPLY, 0, m, &cBinop_S12kC7dh_sendMessage);
}

void Heavy_heavy::cVar_Hum7u1pp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3uKK1jgc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aFgXVYeA, 0, m, &cIf_aFgXVYeA_sendMessage);
}

void Heavy_heavy::cIf_aFgXVYeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_IhSmt6NK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4KmbPfDR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_4KmbPfDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S12kC7dh, HV_BINOP_MULTIPLY, 0, m, &cBinop_S12kC7dh_sendMessage);
}

void Heavy_heavy::cMsg_WZJ1PhI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSTxBLyj, HV_BINOP_SUBTRACT, 0, m, &cBinop_mSTxBLyj_sendMessage);
}

void Heavy_heavy::cBinop_ZGv2eRz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y1HygRmI, 0, m, &cVar_y1HygRmI_sendMessage);
}

void Heavy_heavy::cVar_ytloH9rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_19177f1M_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CFd2AuUZ, 0, m, &cIf_CFd2AuUZ_sendMessage);
}

void Heavy_heavy::cBinop_19177f1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CFd2AuUZ, 1, m, &cIf_CFd2AuUZ_sendMessage);
}

void Heavy_heavy::cUnop_yQ5VlZMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OyLoYR3l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_CFd2AuUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_yQ5VlZMn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_p1WxQQO4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_p1WxQQO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OyLoYR3l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_gVmUyYFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kt9aeMaY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mX7ax9YV, 0, m, &cVar_mX7ax9YV_sendMessage);
  cMsg_jIb1mQDh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Z1mumEr1, 0, m, &cVar_Z1mumEr1_sendMessage);
  cMsg_na9hOzzV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QQdkhqAS, 0, m, &cVar_QQdkhqAS_sendMessage);
  cMsg_aiT2JdlS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_P51YIGXq, 0, m, &cVar_P51YIGXq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g4MWqp8y, 0, m, &cVar_g4MWqp8y_sendMessage);
  cMsg_cHPdhJgG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ObXo4kIX, 0, m, &cVar_ObXo4kIX_sendMessage);
  cSwitchcase_FQhJ9wB5_onMessage(_c, NULL, 0, m, NULL);
  cMsg_PnHj48PB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VXAnUiwd, 0, m, &cVar_VXAnUiwd_sendMessage);
  cMsg_rsOZpBPf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_32DH165b, 0, m, &cVar_32DH165b_sendMessage);
  cMsg_4EAFfofH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jHORJlME, 0, m, &cVar_jHORJlME_sendMessage);
  cMsg_OpWESe3a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_q8SXt3iK, 0, m, &cVar_q8SXt3iK_sendMessage);
  cMsg_eZf9EFlO_sendMessage(_c, 0, m);
  cMsg_4W0IcQaF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0lEe6iCJ, 0, m, &cVar_0lEe6iCJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JhJzOplK, 0, m, &cVar_JhJzOplK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2ylSQA4Q, 0, m, &cVar_2ylSQA4Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_URp0LRw4, 0, m, &cVar_URp0LRw4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hPqVUX6k, 0, m, &cVar_hPqVUX6k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zv7FgbVZ, 0, m, &cVar_zv7FgbVZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GGAdABJh, 0, m, &cVar_GGAdABJh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uZO8esYE, 0, m, &cVar_uZO8esYE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LFalCNlB, 0, m, &cVar_LFalCNlB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Miac6iea, 0, m, &cVar_Miac6iea_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VGzudtNS, 0, m, &cVar_VGzudtNS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_havNOXGy, 0, m, &cVar_havNOXGy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZrDyhwH7, 0, m, &cVar_ZrDyhwH7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v2ARCwao, 0, m, &cVar_v2ARCwao_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gYfUn9NF, 0, m, &cVar_gYfUn9NF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qpHAqH7q, 0, m, &cVar_qpHAqH7q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L4at7Ym6, 0, m, &cVar_L4at7Ym6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DfPdsHid, 0, m, &cVar_DfPdsHid_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n3JVSHrr, 0, m, &cVar_n3JVSHrr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8wqsPp24, 0, m, &cVar_8wqsPp24_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4YGiN1Sy, 0, m, &cVar_4YGiN1Sy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B4oW138S, 0, m, &cVar_B4oW138S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sKAW1O7b, 0, m, &cVar_sKAW1O7b_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ykrJ9b6u, 0, m, &cVar_ykrJ9b6u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z5TVikAR, 0, m, &cVar_Z5TVikAR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VdVyznpm, 0, m, &cVar_VdVyznpm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XlbLbBRT, 0, m, &cVar_XlbLbBRT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M50xoup2, 0, m, &cVar_M50xoup2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2VzcVne6, 0, m, &cVar_2VzcVne6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JFflS1tQ, 0, m, &cVar_JFflS1tQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gqh1PB2D, 0, m, &cVar_gqh1PB2D_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L3mQzZZk, 0, m, &cVar_L3mQzZZk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3QJeDOon, 0, m, &cVar_3QJeDOon_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y1HygRmI, 0, m, &cVar_y1HygRmI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pnBtLuBY, 0, m, &cVar_pnBtLuBY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4dG7vwAw, 0, m, &cVar_4dG7vwAw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bpTvPBhe, 0, m, &cVar_bpTvPBhe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_J3TotSvJ, 0, m, &cVar_J3TotSvJ_sendMessage);
  cMsg_AzdaYT5i_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FwK6Ycsy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DZIUGz48, 0, m, &cVar_DZIUGz48_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2WogOoqL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BZBtBDcA, 0, m, &cVar_BZBtBDcA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RgjicCg2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2HUvkhM, 0, m, &cVar_Z2HUvkhM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_agFpP1Yq, 0, m, &cVar_agFpP1Yq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Rt8TT9P, 0, m, &cVar_9Rt8TT9P_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gY76JK2a, 0, m, &cVar_gY76JK2a_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Lf9qbP38, 0, m, &cVar_Lf9qbP38_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aZ7KMxy8, 0, m, &cVar_aZ7KMxy8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cm3aVWeV, 0, m, &cVar_cm3aVWeV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ndea89W1, 0, m, &cVar_ndea89W1_sendMessage);
  cMsg_64gxnb3S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_z0Hrrcz1, 0, m, &cVar_z0Hrrcz1_sendMessage);
  cMsg_xDsILz4e_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_rjL9kvlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_oW1UeVRI_sendMessage);
}

void Heavy_heavy::cVar_Z2HUvkhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f2KjoGNJ, 0, m, &cVar_f2KjoGNJ_sendMessage);
}

void Heavy_heavy::cCast_PQzh24BB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eY7R9YWO_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_BXoaL5I3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lArJybjA, HV_BINOP_MIN, 0, m, &cBinop_lArJybjA_sendMessage);
}

void Heavy_heavy::cCast_2SaK9TWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T5sW7ZE2, 0, m, &cVar_T5sW7ZE2_sendMessage);
}

void Heavy_heavy::cSlice_6lhvnAop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_YMiPdg8Z, 1, m, &cTabread_YMiPdg8Z_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_YMiPdg8Z, 1, m, &cTabread_YMiPdg8Z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_pi31CJDz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6lhvnAop, 0, m, &cSlice_6lhvnAop_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2SaK9TWA_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WAVjGKBy_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_WAVjGKBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BXoaL5I3_sendMessage);
}

void Heavy_heavy::cVar_T5sW7ZE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kCvjbJPt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_5QPoUwgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TTkIPIrB_sendMessage);
}

void Heavy_heavy::cBinop_TTkIPIrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lArJybjA, HV_BINOP_MIN, 1, m, &cBinop_lArJybjA_sendMessage);
}

void Heavy_heavy::cMsg_kCvjbJPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5QPoUwgJ_sendMessage);
}

void Heavy_heavy::cTabread_YMiPdg8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dT4W8y4, HV_BINOP_ADD, 0, m, &cBinop_0dT4W8y4_sendMessage);
}

void Heavy_heavy::cBinop_lArJybjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_YMiPdg8Z, 0, m, &cTabread_YMiPdg8Z_sendMessage);
}

void Heavy_heavy::cMsg_mm8NDRLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_pi31CJDz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_0dT4W8y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ooDkWyyj_sendMessage);
}

void Heavy_heavy::cVar_oIfaaYrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pi31CJDz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_f2KjoGNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dT4W8y4, HV_BINOP_ADD, 1, m, &cBinop_0dT4W8y4_sendMessage);
}

void Heavy_heavy::cCast_RgjicCg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mm8NDRLk_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_eY7R9YWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_pi31CJDz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_HUmrKiLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.01f, 0, m, &cBinop_t6NFagX0_sendMessage);
}

void Heavy_heavy::cReceive_0kzmgiOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_oSIo77ao_sendMessage);
}

void Heavy_heavy::cIf_RFLINFtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k3yOzxJl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nRCNEqLT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_XQb1QS4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_27BBmrdb, 0, m, &cVar_27BBmrdb_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_27BBmrdb, 0, m, &cVar_27BBmrdb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_kHBVQGmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EPALZRPp, HV_BINOP_NEQ, 1, m, &cBinop_EPALZRPp_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_27BBmrdb, 1, m, &cVar_27BBmrdb_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_EPALZRPp, HV_BINOP_NEQ, 1, m, &cBinop_EPALZRPp_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_27BBmrdb, 1, m, &cVar_27BBmrdb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Beez2N0B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XQb1QS4R, 0, m, &cSlice_XQb1QS4R_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kHBVQGmz, 0, m, &cSlice_kHBVQGmz_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EqRtqRlN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lJGABuB4_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_lJGABuB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RFLINFtS, 0, m, &cIf_RFLINFtS_sendMessage);
}

void Heavy_heavy::cCast_EqRtqRlN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EPALZRPp, HV_BINOP_NEQ, 0, m, &cBinop_EPALZRPp_sendMessage);
}

void Heavy_heavy::cVar_27BBmrdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_QOuXL72j_sendMessage);
}

void Heavy_heavy::cBinop_EPALZRPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RFLINFtS, 1, m, &cIf_RFLINFtS_sendMessage);
}

void Heavy_heavy::cCast_k3yOzxJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EPALZRPp, HV_BINOP_NEQ, 1, m, &cBinop_EPALZRPp_sendMessage);
}

void Heavy_heavy::cCast_nRCNEqLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_27BBmrdb, 0, m, &cVar_27BBmrdb_sendMessage);
}

void Heavy_heavy::cReceive_eq8gYRHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JyLGQuDC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BQr5sIWI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.85f, 0, m, &cBinop_y245RhNJ_sendMessage);
}

void Heavy_heavy::cCast_CzlbCFod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3giVpwCd, 0, m, &cVar_3giVpwCd_sendMessage);
}

void Heavy_heavy::cBinop_oW1UeVRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Csxr6obb, 0, m, &cVar_Csxr6obb_sendMessage);
}

void Heavy_heavy::cReceive_TmCQMfDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4000.0f, 0, m, &cBinop_FBJus5TB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_zPGoQhtk_sendMessage);
}

void Heavy_heavy::cBinop_3FZxheMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8wqsPp24, 0, m, &cVar_8wqsPp24_sendMessage);
  cSend_oH9YTO57_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_KXrnOsQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yr0pZQi0_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_FwK6Ycsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V2nG4ukd_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_bi7GJVPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TJshtEt8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_Yr0pZQi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_TJshtEt8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_V2nG4ukd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_TJshtEt8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_e5Z9Zkqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yw7z9GU3_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_ZFIKhSYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RBBfxLJN_sendMessage);
}

void Heavy_heavy::cTabread_LVyouakr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NP1ixxiI, HV_BINOP_ADD, 0, m, &cBinop_NP1ixxiI_sendMessage);
}

void Heavy_heavy::cSystem_eavSnB8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VzFzmIUy_sendMessage);
}

void Heavy_heavy::cBinop_vIyp314g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_LVyouakr, 0, m, &cTabread_LVyouakr_sendMessage);
}

void Heavy_heavy::cBinop_RBBfxLJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vIyp314g, HV_BINOP_MIN, 0, m, &cBinop_vIyp314g_sendMessage);
}

void Heavy_heavy::cSlice_5iXPZPm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_LVyouakr, 1, m, &cTabread_LVyouakr_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_LVyouakr, 1, m, &cTabread_LVyouakr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_TJshtEt8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5iXPZPm2, 0, m, &cSlice_5iXPZPm2_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z1XJLVDP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZFIKhSYI_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_Yw7z9GU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eavSnB8o_sendMessage);
}

void Heavy_heavy::cBinop_VzFzmIUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vIyp314g, HV_BINOP_MIN, 1, m, &cBinop_vIyp314g_sendMessage);
}

void Heavy_heavy::cCast_Z1XJLVDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e5Z9Zkqw, 0, m, &cVar_e5Z9Zkqw_sendMessage);
}

void Heavy_heavy::cVar_DZIUGz48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_If84eHLf, 0, m, &cVar_If84eHLf_sendMessage);
}

void Heavy_heavy::cVar_If84eHLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NP1ixxiI, HV_BINOP_ADD, 1, m, &cBinop_NP1ixxiI_sendMessage);
}

void Heavy_heavy::cBinop_NP1ixxiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MSAdxeSV_sendMessage);
}

void Heavy_heavy::cSlice_JTuKRgzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MA73TW95, HV_BINOP_NEQ, 1, m, &cBinop_MA73TW95_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_5d1G69Rp, 1, m, &cVar_5d1G69Rp_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MA73TW95, HV_BINOP_NEQ, 1, m, &cBinop_MA73TW95_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_5d1G69Rp, 1, m, &cVar_5d1G69Rp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_YnTtF8cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_5d1G69Rp, 0, m, &cVar_5d1G69Rp_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_5d1G69Rp, 0, m, &cVar_5d1G69Rp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_rwSGY2nP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YnTtF8cq, 0, m, &cSlice_YnTtF8cq_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JTuKRgzP, 0, m, &cSlice_JTuKRgzP_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Pnbp1FwF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_T4lGPuj8_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_2J4C1qpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5d1G69Rp, 0, m, &cVar_5d1G69Rp_sendMessage);
}

void Heavy_heavy::cCast_8OUQpEns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MA73TW95, HV_BINOP_NEQ, 1, m, &cBinop_MA73TW95_sendMessage);
}

void Heavy_heavy::cCast_T4lGPuj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_q64k6n1M, 0, m, &cIf_q64k6n1M_sendMessage);
}

void Heavy_heavy::cBinop_MA73TW95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_q64k6n1M, 1, m, &cIf_q64k6n1M_sendMessage);
}

void Heavy_heavy::cIf_q64k6n1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8OUQpEns_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2J4C1qpx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_5d1G69Rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_vyefIjRk_sendMessage);
}

void Heavy_heavy::cCast_Pnbp1FwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MA73TW95, HV_BINOP_NEQ, 0, m, &cBinop_MA73TW95_sendMessage);
}

void Heavy_heavy::cCast_dOiM3J7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iOMNU6H1, 0, m, &cVar_iOMNU6H1_sendMessage);
}

void Heavy_heavy::cVar_vYw7AiSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GOFtbWiV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qbUbejzP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_APiCFsAX, 1, m, &cIf_APiCFsAX_sendMessage);
}

void Heavy_heavy::cBinop_GOFtbWiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYw7AiSz, 1, m, &cVar_vYw7AiSz_sendMessage);
}

void Heavy_heavy::cVar_Miac6iea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jbzuhYjB, 0, m, &cVar_jbzuhYjB_sendMessage);
}

void Heavy_heavy::cIf_dMPnEqJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_JjBXm0yR, 0, m, &cIf_JjBXm0yR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_qpT7f6I4, 0, m, &cIf_qpT7f6I4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_qbUbejzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dMPnEqJW, 1, m, &cIf_dMPnEqJW_sendMessage);
}

void Heavy_heavy::cBinop_E4aucfg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JjBXm0yR, 0, m, &cIf_JjBXm0yR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qpT7f6I4, 0, m, &cIf_qpT7f6I4_sendMessage);
}

void Heavy_heavy::cIf_APiCFsAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_E4aucfg7, HV_BINOP_ADD, 0, m, &cBinop_E4aucfg7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Un4ouLvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lcK5bs2L, 1, m, &cIf_lcK5bs2L_sendMessage);
}

void Heavy_heavy::cUnop_H8f4lwKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ah1Z7XO6, 0, m, &cVar_ah1Z7XO6_sendMessage);
}

void Heavy_heavy::cVar_Hg1YzM1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Un4ouLvJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lcK5bs2L, 0, m, &cIf_lcK5bs2L_sendMessage);
}

void Heavy_heavy::cUnop_b6qiIA5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ah1Z7XO6, 0, m, &cVar_ah1Z7XO6_sendMessage);
}

void Heavy_heavy::cIf_lcK5bs2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_H8f4lwKz_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_b6qiIA5U_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_363pukBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ckuXZ8Ai, HV_BINOP_ADD, 0, m, &cBinop_ckuXZ8Ai_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_CjNDtL7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_5PcX9FRz, 0, m, &cVar_5PcX9FRz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ckuXZ8Ai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5PcX9FRz, 0, m, &cVar_5PcX9FRz_sendMessage);
}

void Heavy_heavy::cBinop_8By3uP8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CjNDtL7p, 1, m, &cIf_CjNDtL7p_sendMessage);
}

void Heavy_heavy::cVar_yP7DEtcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DUW7rmhS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8By3uP8V_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_363pukBR, 1, m, &cIf_363pukBR_sendMessage);
}

void Heavy_heavy::cBinop_DUW7rmhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yP7DEtcM, 1, m, &cVar_yP7DEtcM_sendMessage);
}

void Heavy_heavy::cVar_tjyXAKNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hg1YzM1C, 0, m, &cVar_Hg1YzM1C_sendMessage);
}

void Heavy_heavy::cIf_qpT7f6I4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_363pukBR, 0, m, &cIf_363pukBR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_CjNDtL7p, 0, m, &cIf_CjNDtL7p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_JjBXm0yR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iJoCIsza, HV_BINOP_ADD, 0, m, &cBinop_iJoCIsza_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_yQgwhb6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qpT7f6I4, 1, m, &cIf_qpT7f6I4_sendMessage);
}

void Heavy_heavy::cBinop_iJoCIsza_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_363pukBR, 0, m, &cIf_363pukBR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CjNDtL7p, 0, m, &cIf_CjNDtL7p_sendMessage);
}

void Heavy_heavy::cIf_PT4tGPlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_APiCFsAX, 0, m, &cIf_APiCFsAX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_dMPnEqJW, 0, m, &cIf_dMPnEqJW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_rPs1r5lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_APiCFsAX, 0, m, &cIf_APiCFsAX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dMPnEqJW, 0, m, &cIf_dMPnEqJW_sendMessage);
}

void Heavy_heavy::cIf_kmUgKCag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rPs1r5lw, HV_BINOP_ADD, 0, m, &cBinop_rPs1r5lw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_PB0j113K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PT4tGPlI, 1, m, &cIf_PT4tGPlI_sendMessage);
}

void Heavy_heavy::cVar_ah1Z7XO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ckuXZ8Ai, HV_BINOP_ADD, 1, m, &cBinop_ckuXZ8Ai_sendMessage);
}

void Heavy_heavy::cSlice_P1CdeTXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_umBuGclw, HV_BINOP_ADD, 1, m, &cBinop_umBuGclw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_2bYyw8rr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_iJoCIsza, HV_BINOP_ADD, 1, m, &cBinop_iJoCIsza_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_dDWji7AB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rPs1r5lw, HV_BINOP_ADD, 1, m, &cBinop_rPs1r5lw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_d7LxjlRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_tjyXAKNl, 0, m, &cVar_tjyXAKNl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_OPfXiLXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_E4aucfg7, HV_BINOP_ADD, 1, m, &cBinop_E4aucfg7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_jbzuhYjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_tXQc72tM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_yQgwhb6G_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JjBXm0yR, 1, m, &cIf_JjBXm0yR_sendMessage);
}

void Heavy_heavy::cBinop_tXQc72tM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jbzuhYjB, 1, m, &cVar_jbzuhYjB_sendMessage);
}

void Heavy_heavy::cVar_GGAdABJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vi7Gq1kH, 0, m, &cVar_vi7Gq1kH_sendMessage);
}

void Heavy_heavy::cIf_VKLKTqPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_kmUgKCag, 0, m, &cIf_kmUgKCag_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_PT4tGPlI, 0, m, &cIf_PT4tGPlI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_umBuGclw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kmUgKCag, 0, m, &cIf_kmUgKCag_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PT4tGPlI, 0, m, &cIf_PT4tGPlI_sendMessage);
}

void Heavy_heavy::cBinop_bYEosc57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VKLKTqPy, 1, m, &cIf_VKLKTqPy_sendMessage);
}

void Heavy_heavy::cIf_49eQUZ9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_umBuGclw, HV_BINOP_ADD, 0, m, &cBinop_umBuGclw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_mT2wwdRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WUjIqZK1, 1, m, &cVar_WUjIqZK1_sendMessage);
}

void Heavy_heavy::cVar_WUjIqZK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mT2wwdRa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_PB0j113K_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kmUgKCag, 1, m, &cIf_kmUgKCag_sendMessage);
}

void Heavy_heavy::cVar_LFalCNlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYw7AiSz, 0, m, &cVar_vYw7AiSz_sendMessage);
}

void Heavy_heavy::cVar_VGzudtNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yP7DEtcM, 0, m, &cVar_yP7DEtcM_sendMessage);
}

void Heavy_heavy::cVar_uZO8esYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WUjIqZK1, 0, m, &cVar_WUjIqZK1_sendMessage);
}

void Heavy_heavy::cVar_havNOXGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tjyXAKNl, 0, m, &cVar_tjyXAKNl_sendMessage);
}

void Heavy_heavy::cBinop_aficbvL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vi7Gq1kH, 1, m, &cVar_vi7Gq1kH_sendMessage);
}

void Heavy_heavy::cVar_vi7Gq1kH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_aficbvL2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bYEosc57_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_49eQUZ9o, 1, m, &cIf_49eQUZ9o_sendMessage);
}

void Heavy_heavy::cBinop_EfN3T6OF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tDW7J5wT, 0, m, &cVar_tDW7J5wT_sendMessage);
}

void Heavy_heavy::cSend_YtSyZdET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0kzmgiOq_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_mOvYRsvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eq8gYRHV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_lRKHRh21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EOwrKIcI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_ZzRrIneh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UXLBtpOI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_5spZOHTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_Xa1ih2YM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_2WogOoqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JSNyMsF7_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_kToFhqUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5spZOHTQ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Hz4MQRvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_byZ5Oue5, 0, m, &cTabread_byZ5Oue5_sendMessage);
}

void Heavy_heavy::cBinop_f1DozMVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hz4MQRvk, HV_BINOP_MIN, 1, m, &cBinop_Hz4MQRvk_sendMessage);
}

void Heavy_heavy::cSystem_UZwSxuGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_f1DozMVi_sendMessage);
}

void Heavy_heavy::cBinop_GNTdL26H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hz4MQRvk, HV_BINOP_MIN, 0, m, &cBinop_Hz4MQRvk_sendMessage);
}

void Heavy_heavy::cCast_D5hpsLsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GNTdL26H_sendMessage);
}

void Heavy_heavy::cMsg_Nq5v3j35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UZwSxuGy_sendMessage);
}

void Heavy_heavy::cTabread_byZ5Oue5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k4gJ8dxM, HV_BINOP_ADD, 0, m, &cBinop_k4gJ8dxM_sendMessage);
}

void Heavy_heavy::cSlice_zZwTVWGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_byZ5Oue5, 1, m, &cTabread_byZ5Oue5_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_byZ5Oue5, 1, m, &cTabread_byZ5Oue5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Xa1ih2YM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zZwTVWGj, 0, m, &cSlice_zZwTVWGj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CAHGIVEl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_D5hpsLsH_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_cNZrUfCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Nq5v3j35_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_CAHGIVEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cNZrUfCg, 0, m, &cVar_cNZrUfCg_sendMessage);
}

void Heavy_heavy::cVar_5PcX9FRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Xa1ih2YM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_k4gJ8dxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_KXDjY9mL_sendMessage);
}

void Heavy_heavy::cVar_8wEioEGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k4gJ8dxM, HV_BINOP_ADD, 1, m, &cBinop_k4gJ8dxM_sendMessage);
}

void Heavy_heavy::cMsg_JSNyMsF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_Xa1ih2YM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_BZBtBDcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8wEioEGy, 0, m, &cVar_8wEioEGy_sendMessage);
}

void Heavy_heavy::cBinop_vns8w1Nr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_UZ2XezfM_sendMessage);
}

void Heavy_heavy::cCast_xmy2QFyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2ZTL4OGD, 0, m, &cVar_2ZTL4OGD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bCob2Buz, 0, m, &cVar_bCob2Buz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lklQ4WuW, 0, m, &cVar_lklQ4WuW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M3U7coEX, 0, m, &cVar_M3U7coEX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nsIMkVCc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WNG0cRY4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_irEwjTXO, 0, m, &cVar_irEwjTXO_sendMessage);
}

void Heavy_heavy::cVar_Lax1QPiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TqRivhNk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z1mumEr1, 0, m, &cVar_Z1mumEr1_sendMessage);
  cSwitchcase_0h2PbunH_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_MAxbVWO0, 1, m, &cVar_MAxbVWO0_sendMessage);
}

void Heavy_heavy::sSample_dsyvEXXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_nm6ETnAY_sendMessage);
}

void Heavy_heavy::cBinop_PkN1PTYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8XyLMvqB, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_rZ9hfJTt, 0, m);
}

void Heavy_heavy::cCast_UILS2VeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PkN1PTYJ, HV_BINOP_DIVIDE, 1, m, &cBinop_PkN1PTYJ_sendMessage);
}

void Heavy_heavy::cVar_cm3aVWeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8hfSkzwT_sendMessage);
  cSwitchcase_5OWf900C_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_8hfSkzwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cm3aVWeV, 1, m, &cVar_cm3aVWeV_sendMessage);
}

void Heavy_heavy::sSample_V4aWuIXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZYMLqOTn_sendMessage);
}

void Heavy_heavy::cBinop_TqRivhNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UILS2VeP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nQzm1a1t_sendMessage);
}

void Heavy_heavy::cVar_MAxbVWO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hQ4AJ2rp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VUL6UJ3e, 0, m, &cIf_VUL6UJ3e_sendMessage);
}

void Heavy_heavy::cUnop_iJVKlYox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cUnop_KWVapoa5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_hQ4AJ2rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VUL6UJ3e, 1, m, &cIf_VUL6UJ3e_sendMessage);
}

void Heavy_heavy::cIf_VUL6UJ3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_iJVKlYox_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KWVapoa5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_eLZ6pyek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_R6tTO4oE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_vns8w1Nr_sendMessage);
}

void Heavy_heavy::cCast_nQzm1a1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nVK0KBsb_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_CCmmRHYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4izl0eJW_sendMessage);
}

void Heavy_heavy::cCast_OUolqDh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1vtCa77t_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6FZLz0ld, 0, m, &cDelay_6FZLz0ld_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xmy2QFyA_sendMessage);
}

void Heavy_heavy::cVar_Z1mumEr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CCmmRHYB, HV_BINOP_MULTIPLY, 0, m, &cBinop_CCmmRHYB_sendMessage);
}

void Heavy_heavy::cDelay_6FZLz0ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6FZLz0ld, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6FZLz0ld, 0, m, &cDelay_6FZLz0ld_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xmy2QFyA_sendMessage);
}

void Heavy_heavy::cSwitchcase_5OWf900C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_1vtCa77t_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_1vtCa77t_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OUolqDh4_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSystem_AkVQ7Nvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vJGVBkwG_sendMessage);
}

void Heavy_heavy::cMsg_jIb1mQDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AkVQ7Nvm_sendMessage);
}

void Heavy_heavy::cBinop_4izl0eJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6FZLz0ld, 2, m, &cDelay_6FZLz0ld_sendMessage);
}

void Heavy_heavy::cBinop_vJGVBkwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CCmmRHYB, HV_BINOP_MULTIPLY, 1, m, &cBinop_CCmmRHYB_sendMessage);
}

void Heavy_heavy::cMsg_1vtCa77t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6FZLz0ld, 0, m, &cDelay_6FZLz0ld_sendMessage);
}

void Heavy_heavy::cBinop_nm6ETnAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_R6tTO4oE_sendMessage);
}

void Heavy_heavy::cBinop_ZYMLqOTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_eLZ6pyek_sendMessage);
}

void Heavy_heavy::cVar_n3JVSHrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qgEDRyJ1_sendMessage);
  cSwitchcase_mmknzsou_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_qgEDRyJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n3JVSHrr, 1, m, &cVar_n3JVSHrr_sendMessage);
}

void Heavy_heavy::cVar_8wqsPp24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Lax1QPiv, 0, m, &cVar_Lax1QPiv_sendMessage);
}

void Heavy_heavy::cMsg_nVK0KBsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PkN1PTYJ, HV_BINOP_DIVIDE, 0, m, &cBinop_PkN1PTYJ_sendMessage);
}

void Heavy_heavy::cDelay_v25TaZVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_v25TaZVr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_v25TaZVr, 0, m, &cDelay_v25TaZVr_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_dsyvEXXD, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_V4aWuIXy, 1, m);
}

void Heavy_heavy::cVar_QQdkhqAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYVHrMzA, HV_BINOP_MULTIPLY, 0, m, &cBinop_gYVHrMzA_sendMessage);
}

void Heavy_heavy::cBinop_gYVHrMzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5YWG3qZf_sendMessage);
}

void Heavy_heavy::cBinop_iP2oOGxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYVHrMzA, HV_BINOP_MULTIPLY, 1, m, &cBinop_gYVHrMzA_sendMessage);
}

void Heavy_heavy::cMsg_na9hOzzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jpIQ8rnk_sendMessage);
}

void Heavy_heavy::cSystem_jpIQ8rnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iP2oOGxI_sendMessage);
}

void Heavy_heavy::cMsg_6J1dDlyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_v25TaZVr, 0, m, &cDelay_v25TaZVr_sendMessage);
}

void Heavy_heavy::cBinop_5YWG3qZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_v25TaZVr, 2, m, &cDelay_v25TaZVr_sendMessage);
}

void Heavy_heavy::cSwitchcase_mmknzsou_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_6J1dDlyq_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_6J1dDlyq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BDnbAwFE_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_BDnbAwFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6J1dDlyq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_v25TaZVr, 0, m, &cDelay_v25TaZVr_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_dsyvEXXD, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_V4aWuIXy, 1, m);
}

void Heavy_heavy::cDelay_xSks1fHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xSks1fHj, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MAxbVWO0, 0, m, &cVar_MAxbVWO0_sendMessage);
}

void Heavy_heavy::cMsg_izQnSm3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xSks1fHj, 0, m, &cDelay_xSks1fHj_sendMessage);
}

void Heavy_heavy::cCast_ZhtIeBtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xSks1fHj, 0, m, &cDelay_xSks1fHj_sendMessage);
}

void Heavy_heavy::cSwitchcase_0h2PbunH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_izQnSm3D_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_izQnSm3D_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_xSks1fHj, 1, m, &cDelay_xSks1fHj_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZhtIeBtX_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_b9EpYEl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ytloH9rg, 0, m, &cVar_ytloH9rg_sendMessage);
}

void Heavy_heavy::cBinop_FldTJrzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_49eQUZ9o, 0, m, &cIf_49eQUZ9o_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_VKLKTqPy, 0, m, &cIf_VKLKTqPy_sendMessage);
}

void Heavy_heavy::cBinop_ClGE1hFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_irEwjTXO, 1, m, &cVar_irEwjTXO_sendMessage);
}

void Heavy_heavy::cCast_l0D3EU1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3FZxheMK, HV_BINOP_SUBTRACT, 1, m, &cBinop_3FZxheMK_sendMessage);
}

void Heavy_heavy::cCast_JyLGQuDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HUmrKiLo, HV_BINOP_SUBTRACT, 1, m, &cBinop_HUmrKiLo_sendMessage);
}

void Heavy_heavy::cUnop_QWCTdmVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rwSGY2nP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_9acvBRrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gwU6DVcz, 1, m, &cIf_gwU6DVcz_sendMessage);
}

void Heavy_heavy::cVar_Csxr6obb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9acvBRrr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gwU6DVcz, 0, m, &cIf_gwU6DVcz_sendMessage);
}

void Heavy_heavy::cUnop_W2joEVrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_rwSGY2nP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_gwU6DVcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_QWCTdmVs_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_W2joEVrt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_oSIo77ao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_ClGE1hFs_sendMessage);
}

void Heavy_heavy::cVar_iOMNU6H1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGv2eRz3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZGv2eRz3_sendMessage);
}

void Heavy_heavy::cReceive_It2U5qhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_Oa4rK5Gu_sendMessage);
}

void Heavy_heavy::cBinop_Oa4rK5Gu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RWo9oYzY, 0, m, &cVar_RWo9oYzY_sendMessage);
}

void Heavy_heavy::cVar_gfKkcVG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YtSyZdET_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_a72d1fER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HUmrKiLo, HV_BINOP_SUBTRACT, 0, m, &cBinop_HUmrKiLo_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6;
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
    __hv_phasor_k_f(&sPhasor_rZ9hfJTt, VOf(Bf0));
    __hv_sample_f(this, &sSample_dsyvEXXD, VIf(Bf0), &sSample_dsyvEXXD_sendMessage);
    __hv_phasor_k_f(&sPhasor_8XyLMvqB, VOf(Bf0));
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
    __hv_sample_f(this, &sSample_V4aWuIXy, VIf(Bf1), &sSample_V4aWuIXy_sendMessage);
    __hv_varread_i(&sVari_B1YpiFZN, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_B1YpiFZN, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_p8axsPO8, VOf(Bf1));
    __hv_phasor_f(&sPhasor_8qjsesdt, VIf(Bf1), VOf(Bf1));
    __hv_del1_f(&sDel1_vwYqPBdv, VIf(Bf1), VOf(Bf0));
    __hv_lt_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_samphold_f(&sSamphold_oxDfnMVJ, VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_WLCV2hO9, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_3E43c9JX, VOf(Bf0));
    __hv_rpole_f(&sRPole_tYs3047f, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_Te1vfgJg, VIf(Bf0), &sSample_Te1vfgJg_sendMessage);
    __hv_varread_f(&sVarf_NCEOAiWg, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_pkn9XHGB, VOf(Bf1));
    __hv_rpole_f(&sRPole_f4HOXh5a, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Kzi4LcH5, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_yXi6rWqj, VOf(Bf0));
    __hv_phasor_f(&sPhasor_ciQlbSv3, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_7azZOOcP, VOf(Bf4));
    __hv_phasor_f(&sPhasor_t4DeW7YN, VIf(Bf4), VOf(Bf4));
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
    __hv_line_f(&sLine_SC2hljFc, VOf(Bf3));
    __hv_phasor_f(&sPhasor_YLXhMM7P, VIf(Bf3), VOf(Bf3));
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
    __hv_line_f(&sLine_fRBabuDa, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rpNvROxU, VOf(Bf0));
    __hv_line_f(&sLine_DRF1CdF6, VOf(Bf5));
    __hv_tabhead_f(&sTabhead_MqJpJtpp, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_PbwaFKCN, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9kQARwGG, VOf(Bf4));
    __hv_min_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_varread_f(&sVarf_KZWRv8U4, VOf(Bf4));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_ldCzDTGF, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_PnJdQKNq, VIi(Bi1), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_0GZhqeMB, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_5Ta8hJCX, VOf(Bf4));
    __hv_rpole_f(&sRPole_AqPx9AAy, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_mqF1LOL2, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NFzRXMOM, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_YRTYe6G2, VIf(Bf0));
    __hv_tabhead_f(&sTabhead_tkRVC2PZ, VOf(Bf0));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_ZfvEIDXQ, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_xhJpgQT6, VOf(Bf5));
    __hv_min_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf4));
    __hv_varread_f(&sVarf_g2fpaD8c, VOf(Bf5));
    __hv_zero_f(VOf(Bf6));
    __hv_lt_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_UQFDB0cf, VIi(Bi0), VOf(Bf6));
    __hv_tabread_if(&sTabread_5UZlQdhd, VIi(Bi1), VOf(Bf5));
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf6), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_YVGTsPvm, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_rHmZR8NE, VOf(Bf5));
    __hv_rpole_f(&sRPole_Et8wG6tU, VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_agVpjrxC, VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_l1XuuK90, VIf(Bf4));
    __hv_varread_f(&sVarf_WtHlQeQv, VOf(Bf4));
    __hv_varread_f(&sVarf_xTaLCdcf, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));

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
