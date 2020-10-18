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

float hTable_sGgsBn21_data[128] = {0.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 5.0f, 7.0f, 9.0f, 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 15.0f, 15.0f, 17.0f, 17.0f, 19.0f, 21.0f, 22.0f, 22.0f, 24.0f, 26.0f, 26.0f, 27.0f, 27.0f, 29.0f, 29.0f, 31.0f, 33.0f, 34.0f, 34.0f, 36.0f, 38.0f, 38.0f, 39.0f, 39.0f, 41.0f, 41.0f, 43.0f, 45.0f, 46.0f, 46.0f, 48.0f, 50.0f, 50.0f, 51.0f, 51.0f, 53.0f, 53.0f, 55.0f, 57.0f, 58.0f, 58.0f, 60.0f, 62.0f, 62.0f, 63.0f, 63.0f, 65.0f, 65.0f, 67.0f, 69.0f, 70.0f, 70.0f, 72.0f, 74.0f, 74.0f, 75.0f, 75.0f, 77.0f, 77.0f, 79.0f, 81.0f, 82.0f, 82.0f, 84.0f, 86.0f, 86.0f, 87.0f, 87.0f, 89.0f, 89.0f, 91.0f, 93.0f, 94.0f, 94.0f, 96.0f, 98.0f, 98.0f, 99.0f, 99.0f, 101.0f, 101.0f, 103.0f, 105.0f, 106.0f, 106.0f, 108.0f, 110.0f, 110.0f, 111.0f, 111.0f, 113.0f, 113.0f, 115.0f, 117.0f, 118.0f, 118.0f, 120.0f, 122.0f, 122.0f, 123.0f, 123.0f, 125.0f, 125.0f, 127.0f, 129.0f, 130.0f, 130.0f, 132.0f, 134.0f, 134.0f, 135.0f, 135.0f, 137.0f, 0.0f};
float hTable_AH3vIPk6_data[128] = {0.0f, 2.0f, 2.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f, 11.0f, 11.0f, 12.0f, 14.0f, 14.0f, 16.0f, 16.0f, 17.0f, 17.0f, 19.0f, 21.0f, 23.0f, 23.0f, 24.0f, 26.0f, 26.0f, 28.0f, 28.0f, 29.0f, 29.0f, 31.0f, 33.0f, 35.0f, 35.0f, 36.0f, 38.0f, 38.0f, 40.0f, 40.0f, 41.0f, 41.0f, 43.0f, 45.0f, 47.0f, 47.0f, 48.0f, 50.0f, 50.0f, 52.0f, 52.0f, 53.0f, 53.0f, 55.0f, 57.0f, 59.0f, 59.0f, 60.0f, 62.0f, 62.0f, 64.0f, 64.0f, 65.0f, 65.0f, 67.0f, 69.0f, 71.0f, 71.0f, 72.0f, 74.0f, 74.0f, 76.0f, 76.0f, 77.0f, 77.0f, 79.0f, 81.0f, 83.0f, 83.0f, 84.0f, 86.0f, 86.0f, 88.0f, 88.0f, 89.0f, 89.0f, 91.0f, 93.0f, 95.0f, 95.0f, 96.0f, 98.0f, 98.0f, 100.0f, 100.0f, 101.0f, 101.0f, 103.0f, 105.0f, 107.0f, 107.0f, 108.0f, 110.0f, 110.0f, 112.0f, 112.0f, 113.0f, 113.0f, 115.0f, 117.0f, 119.0f, 119.0f, 120.0f, 122.0f, 122.0f, 124.0f, 124.0f, 125.0f, 125.0f, 127.0f, 129.0f, 131.0f, 131.0f, 132.0f, 134.0f, 134.0f, 136.0f, 136.0f, 137.0f, 0.0f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_VrA76h68, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_uy6OU6hg);
  numBytes += sPhasor_k_init(&sPhasor_qRx78syy, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_Zre1DATn);
  numBytes += sRPole_init(&sRPole_n4VKpJ9i);
  numBytes += sPhasor_init(&sPhasor_CmHxlib0, sampleRate);
  numBytes += sDel1_init(&sDel1_O6L1h1m4);
  numBytes += sSamphold_init(&sSamphold_hh1WZx6Y);
  numBytes += sRPole_init(&sRPole_rtvdm7AS);
  numBytes += sSample_init(&sSample_VHER76mY);
  numBytes += sLine_init(&sLine_w7DH4OJg);
  numBytes += sPhasor_init(&sPhasor_flABCkST, sampleRate);
  numBytes += sLine_init(&sLine_TBVKf7tP);
  numBytes += sPhasor_init(&sPhasor_IExBzSLg, sampleRate);
  numBytes += sLine_init(&sLine_yxsgbgza);
  numBytes += sPhasor_init(&sPhasor_acZ2UnXZ, sampleRate);
  numBytes += sLine_init(&sLine_3xV2kuZE);
  numBytes += sLine_init(&sLine_aglQGJpw);
  numBytes += sTabhead_init(&sTabhead_14u59m8b, &hTable_1BTQytxE);
  numBytes += sTabread_init(&sTabread_GpvA3OjB, &hTable_1BTQytxE, false);
  numBytes += sTabread_init(&sTabread_qEKoj9lc, &hTable_1BTQytxE, false);
  numBytes += sRPole_init(&sRPole_z3zPp50j);
  numBytes += sTabwrite_init(&sTabwrite_LDckccXt, &hTable_ZWZsxh48);
  numBytes += sTabhead_init(&sTabhead_91cKd0vl, &hTable_ZWZsxh48);
  numBytes += sTabread_init(&sTabread_y468XpXM, &hTable_ZWZsxh48, false);
  numBytes += sTabread_init(&sTabread_NLVtnFjn, &hTable_ZWZsxh48, false);
  numBytes += sRPole_init(&sRPole_L9aDDTP3);
  numBytes += sTabwrite_init(&sTabwrite_JakmLppA, &hTable_1BTQytxE);
  numBytes += sPhasor_k_init(&sPhasor_f1aBRPmz, 440.0f, sampleRate);
  numBytes += cIf_init(&cIf_Lprt8n9j, false);
  numBytes += cVar_init_f(&cVar_JvOT4p1N, 0.0f);
  numBytes += sVarf_init(&sVarf_Sjpq67JT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_B0T2IhGf, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_aH9J45cI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IXqZzo14, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HRyUCTZ9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_n9VSwYWz, 3000.0f);
  numBytes += sVarf_init(&sVarf_QZ5F20mC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_T32Qcl30, 0.5f);
  numBytes += hTable_init(&hTable_ZWZsxh48, 256);
  numBytes += cDelay_init(this, &cDelay_bDMy8yWH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_HGuc9jEv, 0.0f);
  numBytes += cVar_init_f(&cVar_Leb9V46Q, 3.0f);
  numBytes += sVarf_init(&sVarf_kgZb2NAc, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_f5OYp3lA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hhDlhBLw, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_EER3RzFd, 1.0f); // __pow
  numBytes += hTable_init(&hTable_1BTQytxE, 256);
  numBytes += cDelay_init(this, &cDelay_48INkRwD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_1XQkDJLl, 0.0f);
  numBytes += cVar_init_f(&cVar_1ggSOC58, 0.0f);
  numBytes += cVar_init_f(&cVar_8qwNpub1, 0.0f);
  numBytes += sVarf_init(&sVarf_1uQSHNZC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qEpQ6i7O, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_LDYgkgIK, "del-1339-pong");
  numBytes += sVarf_init(&sVarf_nVLkQmwY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3kuzYB9L, 0.0f);
  numBytes += cVar_init_f(&cVar_WUtE6xpp, 0.5f);
  numBytes += cVar_init_f(&cVar_M4PXpPM1, 0.7f);
  numBytes += sVarf_init(&sVarf_Zhz3bCq3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_CxFy3CqA, 0.0f);
  numBytes += cIf_init(&cIf_IOAhYlbh, false);
  numBytes += cVar_init_f(&cVar_BG4FgOIo, 0.0f);
  numBytes += sVarf_init(&sVarf_r8FwoLGq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_46F2R3tq, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_jp46spu8, "del-1339-ping");
  numBytes += sVarf_init(&sVarf_g1fw48zg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jbTsaDaB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_2quAnLmD, 3000.0f);
  numBytes += sVarf_init(&sVarf_GEaHrfin, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_YsNRBk6A, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1Iwp1KiL, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_cjQey5Wo, false);
  numBytes += cVar_init_f(&cVar_W0dvBX7G, 0.0f);
  numBytes += cVar_init_f(&cVar_SpBA86xz, 0.0f);
  numBytes += cVar_init_f(&cVar_ZADRKcNL, 0.0f);
  numBytes += cVar_init_f(&cVar_TGCvp5Rv, 0.0f);
  numBytes += cVar_init_f(&cVar_B71nrboF, 0.0f);
  numBytes += cTabread_init(&cTabread_qh0MuQEH, &hTable_sGgsBn21); // minor_scale
  numBytes += cSlice_init(&cSlice_oxqtp1jB, 1, -1);
  numBytes += cVar_init_s(&cVar_PssFDhkO, "minor_scale");
  numBytes += cBinop_init(&cBinop_tRCfvmfR, 0.0f); // __min
  numBytes += cBinop_init(&cBinop_9r5IAbMF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_l7G4SLzA, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_J1ai6ycL, 0.0f);
  numBytes += cVar_init_f(&cVar_dqnMcjex, 0.0f);
  numBytes += cVar_init_f(&cVar_NYYyJ4Cl, 1.0f);
  numBytes += cVar_init_f(&cVar_dQCdSeuS, 0.0f);
  numBytes += cBinop_init(&cBinop_ZxoUC43e, 0.0f); // __lt
  numBytes += cIf_init(&cIf_O7Lk0HVz, false);
  numBytes += cVar_init_f(&cVar_fmyRDTAj, 0.0f);
  numBytes += cVar_init_f(&cVar_oHtYajEi, 5.0f);
  numBytes += cIf_init(&cIf_W5EreUM2, false);
  numBytes += cVar_init_f(&cVar_2sSauajM, 0.0f);
  numBytes += cVar_init_f(&cVar_NMu7IGPR, 0.0f);
  numBytes += cBinop_init(&cBinop_qdvr97nw, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_7aHpkIyY, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_cHdRf4Il, 11.0f);
  numBytes += cVar_init_f(&cVar_dHbEopNs, 0.0f);
  numBytes += cIf_init(&cIf_c4O6BwEN, false);
  numBytes += cVar_init_f(&cVar_sVmRmZgM, 0.0f);
  numBytes += cIf_init(&cIf_3uQi5TzE, false);
  numBytes += cBinop_init(&cBinop_j7tnxJv8, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_PM03CEY1, 1, -1);
  numBytes += cSlice_init(&cSlice_VIkhQd62, 1, -1);
  numBytes += cVar_init_f(&cVar_xCKwQ5OQ, 0.0f);
  numBytes += cIf_init(&cIf_zUAweKoA, false);
  numBytes += cVar_init_f(&cVar_JrKmn8XN, 0.0f);
  numBytes += cBinop_init(&cBinop_17F3ZUaO, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_o13yxY9J, 0.0f);
  numBytes += cVar_init_f(&cVar_Y3JPfDWS, 0.0f);
  numBytes += cVar_init_f(&cVar_VxkS34l5, 13.0f);
  numBytes += cIf_init(&cIf_NwshF51P, false);
  numBytes += cVar_init_f(&cVar_hKktoyyZ, 0.0f);
  numBytes += cVar_init_f(&cVar_P8PkzrLL, 1.0f);
  numBytes += cBinop_init(&cBinop_oa9lfvkK, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_pZyM2ajm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ZVRBaq17, 0.0f);
  numBytes += cVar_init_f(&cVar_4jfftbP4, 0.0f);
  numBytes += cVar_init_f(&cVar_amxB5fy9, 0.0f);
  numBytes += cVar_init_f(&cVar_W51lrqp5, 0.0f);
  numBytes += cIf_init(&cIf_iYUNkVfU, false);
  numBytes += cBinop_init(&cBinop_JBfvRBIo, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_c0r2K5Gx, 0.0f);
  numBytes += cBinop_init(&cBinop_fFj51LgM, 0.0f); // __neq
  numBytes += cIf_init(&cIf_UWurcFWK, false);
  numBytes += cVar_init_f(&cVar_ACqme6WH, 0.0f);
  numBytes += cSlice_init(&cSlice_8rfeEBwJ, 1, -1);
  numBytes += cSlice_init(&cSlice_vlItzcU7, 1, -1);
  numBytes += cVar_init_f(&cVar_CEQjFqUN, 0.0f);
  numBytes += cVar_init_f(&cVar_n18uXsXT, 17.0f);
  numBytes += cBinop_init(&cBinop_8CHcdUcy, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nYQGY4h0, 2.0f);
  numBytes += cVar_init_f(&cVar_hoVIrVqr, 1.0f);
  numBytes += cVar_init_f(&cVar_Ou6tk0yc, 0.0f);
  numBytes += cBinop_init(&cBinop_pkvmIO3E, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_7uNFz4VF, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_WnpPvCmU, 0.0f);
  numBytes += cVar_init_f(&cVar_KsPTRZhf, 0.0f);
  numBytes += cIf_init(&cIf_X30VlWVJ, false);
  numBytes += cVar_init_f(&cVar_LNPnO8PO, 0.0f);
  numBytes += cIf_init(&cIf_8bAfR41W, false);
  numBytes += cVar_init_f(&cVar_GEdSyWd9, 0.0f);
  numBytes += cBinop_init(&cBinop_uFtegjly, 0.0f); // __lt
  numBytes += cIf_init(&cIf_jJI97OXA, false);
  numBytes += cVar_init_f(&cVar_QMZU2djc, 0.0f);
  numBytes += cVar_init_f(&cVar_ZkeyVBFM, 0.0f);
  numBytes += cIf_init(&cIf_Gy2lJH6D, false);
  numBytes += cVar_init_f(&cVar_didU4YgD, 0.0f);
  numBytes += cBinop_init(&cBinop_fedGXTW0, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_3jWAR7A0, 0.0f);
  numBytes += cVar_init_f(&cVar_bkBlAzOV, 1000.0f);
  numBytes += cBinop_init(&cBinop_ZqzbuQuh, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_niuIOKV7, 1, -1);
  numBytes += cBinop_init(&cBinop_85MK5Wv3, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_KM7L6oX9, "minor_scale");
  numBytes += cTabread_init(&cTabread_v8OkxrFn, &hTable_sGgsBn21); // minor_scale
  numBytes += cVar_init_f(&cVar_30rn3IfO, 0.0f);
  numBytes += cVar_init_f(&cVar_061B1Ihh, 0.0f);
  numBytes += cVar_init_f(&cVar_2CHmAZbk, 0.0f);
  numBytes += cBinop_init(&cBinop_xDe7kMvJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_PsBhoG5h, 0.0f); // __sub
  numBytes += cPack_init(&cPack_NJ0sy19t, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_byZEQt3J, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_7Q68ZuXM, 1.0f); // __pow
  numBytes += cPack_init(&cPack_29XHnAkg, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_vcGymGDY, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_OP5TKLiB, 0.0f);
  numBytes += cVar_init_f(&cVar_y5Ma4nfk, 2.0f);
  numBytes += cBinop_init(&cBinop_9fROUTkY, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_AsNMcfGw, 0.0f);
  numBytes += cVar_init_f(&cVar_Ddtqjlek, 0.0f);
  numBytes += cIf_init(&cIf_v0tQ0v9S, false);
  numBytes += cVar_init_f(&cVar_jfJa4sr4, 0.0f);
  numBytes += cVar_init_f(&cVar_zDRuJOQr, 0.0f);
  numBytes += cBinop_init(&cBinop_1gnjz8aC, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_vFeV0FXu, 1.0f);
  numBytes += cVar_init_f(&cVar_caYyEUsf, 9.0f);
  numBytes += cVar_init_f(&cVar_l4RtqX9t, 0.0f);
  numBytes += cIf_init(&cIf_KwWQhyUL, false);
  numBytes += cVar_init_f(&cVar_6wEtIwSY, 7.0f);
  numBytes += cBinop_init(&cBinop_qwChAOZy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BfdGDli9, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_A8buZwt0, 0.0f);
  numBytes += cIf_init(&cIf_SwVa52LZ, false);
  numBytes += cBinop_init(&cBinop_AKx8peis, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_vYVbAqqx, 0.0f);
  numBytes += cVar_init_f(&cVar_FQmH8qzn, 0.0f);
  numBytes += cIf_init(&cIf_j8R1kPtN, true);
  numBytes += cBinop_init(&cBinop_03zmzUyl, 2.0f); // __add
  numBytes += cIf_init(&cIf_wUcCm6JR, false);
  numBytes += cSlice_init(&cSlice_Cv5DG48A, 3, 1);
  numBytes += cSlice_init(&cSlice_EfIqMlBj, 1, 1);
  numBytes += cSlice_init(&cSlice_9yFwdI8s, 2, 1);
  numBytes += cSlice_init(&cSlice_8ylWRZ5Z, 4, 1);
  numBytes += cSlice_init(&cSlice_PcwxPqjD, 0, 1);
  numBytes += cVar_init_f(&cVar_Y24E8y7j, 0.0f);
  numBytes += cVar_init_f(&cVar_5Log8qDi, 0.0f);
  numBytes += cVar_init_f(&cVar_t4n2OEER, 1.0f);
  numBytes += cVar_init_f(&cVar_dCwtRYmh, 0.0f);
  numBytes += cIf_init(&cIf_FfGFVBfa, true);
  numBytes += cIf_init(&cIf_JUreMkOw, false);
  numBytes += cBinop_init(&cBinop_BKyrVABE, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_YJ0YSQcW, 0.0f);
  numBytes += cVar_init_f(&cVar_6m9tVKpr, 0.0f);
  numBytes += cIf_init(&cIf_HsvXWn9s, true);
  numBytes += cBinop_init(&cBinop_5Xay8MhQ, -1.0f); // __add
  numBytes += cIf_init(&cIf_gubxLBa0, false);
  numBytes += cIf_init(&cIf_jd7WFdlh, false);
  numBytes += cIf_init(&cIf_qdqNMDKx, true);
  numBytes += cBinop_init(&cBinop_AQLVydlI, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_isTEp57G, 0.0f);
  numBytes += cVar_init_f(&cVar_rR8zJ5wb, 1.0f);
  numBytes += cVar_init_f(&cVar_0SZXfkBm, 1.0f);
  numBytes += cVar_init_f(&cVar_qwjpIYJv, 1.0f);
  numBytes += cVar_init_f(&cVar_rOWRTHxz, 1.0f);
  numBytes += cBinop_init(&cBinop_RNh5SJ0f, 8.0f); // __add
  numBytes += cIf_init(&cIf_TCB8yNwr, true);
  numBytes += cIf_init(&cIf_IBqmK0ql, false);
  numBytes += cIf_init(&cIf_xk0wRNMA, false);
  numBytes += cVar_init_f(&cVar_4er5c1OB, 0.0f);
  numBytes += cVar_init_f(&cVar_cA3gATI7, 0.0f);
  numBytes += cVar_init_f(&cVar_DGEM3Efi, 250.0f);
  numBytes += cVar_init_f(&cVar_zaDY0v7c, 0.0f);
  numBytes += cVar_init_f(&cVar_HxVEGPju, 0.0f);
  numBytes += cSlice_init(&cSlice_hqRfnfDh, 1, -1);
  numBytes += cSlice_init(&cSlice_DVSpNeGN, 1, -1);
  numBytes += cBinop_init(&cBinop_ACDd7Log, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_o8zau1VN, 0, 1);
  numBytes += cSlice_init(&cSlice_AF3GgFGt, 1, 1);
  numBytes += cVar_init_f(&cVar_ihqcTtpc, 20.0f);
  numBytes += cBinop_init(&cBinop_KtqtnTol, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_GPtlFlAo, 0.0f);
  numBytes += cBinop_init(&cBinop_NI8DT43r, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_n0VJjOOL, 0.0f);
  numBytes += cBinop_init(&cBinop_DTYIqiCb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RN7YQEq8, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_n5h0LSNL, 20.0f);
  numBytes += cVar_init_f(&cVar_O1238Com, 0.0f);
  numBytes += cBinop_init(&cBinop_fOLGUiWY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8S1vMaoB, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_EsfVkSuE, 0.0f);
  numBytes += cBinop_init(&cBinop_0c4hkQjZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_OwBMmRzq, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_3X9wsLDX, 0.0f);
  numBytes += cVar_init_f(&cVar_DseOfTQE, 850.0f);
  numBytes += cDelay_init(this, &cDelay_68J8hXpZ, 0.0f);
  numBytes += cVar_init_f(&cVar_q22VdFZj, 0.0f);
  numBytes += cVar_init_f(&cVar_eTjRqvVn, 0.0f);
  numBytes += cBinop_init(&cBinop_MZPIYDFD, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_qvFGvrjV, 0.0f);
  numBytes += cVar_init_f(&cVar_M0EzhsMQ, 0.0f);
  numBytes += cVar_init_f(&cVar_pTCDDtZB, 550.0f);
  numBytes += cIf_init(&cIf_iZT0cRYM, false);
  numBytes += cVar_init_f(&cVar_R4ZyN6NI, 0.0f);
  numBytes += cBinop_init(&cBinop_khSE9Xx0, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_XnrrifRq, 1, -1);
  numBytes += cSlice_init(&cSlice_9qdYTh9b, 1, -1);
  numBytes += hTable_initWithData(&hTable_sGgsBn21, 128, hTable_sGgsBn21_data);
  numBytes += sVarf_init(&sVarf_G8kNxlBz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4X15vG97, 0.0f);
  numBytes += cBinop_init(&cBinop_KLTMngSX, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_opEZO5CK, 3.0f);
  numBytes += sVarf_init(&sVarf_cNjADvJM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XrNNeC8C, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4jojTPdL, 0.5f);
  numBytes += sVarf_init(&sVarf_zAKUWVYb, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NwwW5qDs, 3.0f);
  numBytes += cBinop_init(&cBinop_LcKoiK5a, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rMDmH6Qw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QjfJs5ZA, 0.0f);
  numBytes += cVar_init_f(&cVar_imsk0Ib1, 0.0f);
  numBytes += cVar_init_f(&cVar_gM6VXER7, 1.0f);
  numBytes += cBinop_init(&cBinop_dVLPSgdX, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_BsckdiEb, 0.0f);
  numBytes += cVar_init_f(&cVar_buuEYRMq, 48.0f);
  numBytes += sVari_init(&sVari_GPdGz24s, 0, 0, false);
  numBytes += cSlice_init(&cSlice_30TdiFfn, 1, 1);
  numBytes += cRandom_init(&cRandom_cZSztN9U, 1212729121);
  numBytes += cBinop_init(&cBinop_MYFdIUFG, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_rvFzwTAN, 1.0f);
  numBytes += sVarf_init(&sVarf_r5dVXJCc, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_imojacGj, 0.0f); // __mul
  numBytes += cIf_init(&cIf_eSVlkyYp, false);
  numBytes += cIf_init(&cIf_aPeiC1WT, true);
  numBytes += cBinop_init(&cBinop_oUcbGUV7, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_D39J7QuR, 0.0f);
  numBytes += cVar_init_f(&cVar_HsHZ6z9n, 0.0f);
  numBytes += cVar_init_f(&cVar_3hl1gBbw, 1.0f);
  numBytes += cIf_init(&cIf_HMdNMjkI, false);
  numBytes += cVar_init_f(&cVar_VdQD9BT1, 0.0f);
  numBytes += cVar_init_f(&cVar_UWe7uz3m, 0.0f);
  numBytes += cBinop_init(&cBinop_981TlHCZ, 2.0f); // __add
  numBytes += cIf_init(&cIf_iKfO2Xxt, true);
  numBytes += cIf_init(&cIf_va9jBzDd, false);
  numBytes += cVar_init_f(&cVar_Y92q5whO, 0.0f);
  numBytes += cIf_init(&cIf_yvCnPkpU, true);
  numBytes += cBinop_init(&cBinop_XVJa2lXO, -1.0f); // __add
  numBytes += cIf_init(&cIf_rPYReOQy, false);
  numBytes += cSlice_init(&cSlice_25Ii3NLi, 1, 1);
  numBytes += cSlice_init(&cSlice_86g30WIn, 0, 1);
  numBytes += cSlice_init(&cSlice_xlH4AqLK, 4, 1);
  numBytes += cSlice_init(&cSlice_VTQWvSBV, 3, 1);
  numBytes += cSlice_init(&cSlice_ZrufPV2m, 2, 1);
  numBytes += cVar_init_f(&cVar_wygWYgSD, 1.0f);
  numBytes += cVar_init_f(&cVar_6iWSHoQN, 0.0f);
  numBytes += cVar_init_f(&cVar_M5uftn2N, 0.0f);
  numBytes += cVar_init_f(&cVar_nz5jK9ET, 1.0f);
  numBytes += cBinop_init(&cBinop_Ym2UHCdJ, 0.0f); // __add
  numBytes += cIf_init(&cIf_q4aLsX71, true);
  numBytes += cIf_init(&cIf_MViG5grF, false);
  numBytes += cVar_init_f(&cVar_azTBjbvW, 0.0f);
  numBytes += cVar_init_f(&cVar_xVtVoSce, 1.0f);
  numBytes += cVar_init_f(&cVar_iSiPlo7U, 0.0f);
  numBytes += cVar_init_f(&cVar_BymQts4c, 1.0f);
  numBytes += cIf_init(&cIf_355qiIpz, true);
  numBytes += cBinop_init(&cBinop_NfCdTPvw, 8.0f); // __add
  numBytes += cIf_init(&cIf_xHSuPSbf, false);
  numBytes += cVar_init_f(&cVar_lB8ggTGW, 0.0f);
  numBytes += cVar_init_f(&cVar_PeytvIhF, 1.0f);
  numBytes += cIf_init(&cIf_NHTNOEce, true);
  numBytes += cBinop_init(&cBinop_oejbrcGZ, 8.0f); // __add
  numBytes += cIf_init(&cIf_PyBbhEHa, false);
  numBytes += cVar_init_f(&cVar_XJvGF9xq, 1.0f);
  numBytes += cIf_init(&cIf_t8TNuuZX, false);
  numBytes += cBinop_init(&cBinop_sQ0VmOLe, 0.0f); // __add
  numBytes += cIf_init(&cIf_xJWwcJLL, true);
  numBytes += cSlice_init(&cSlice_4d3eRchx, 4, 1);
  numBytes += cSlice_init(&cSlice_42TvLVMJ, 3, 1);
  numBytes += cSlice_init(&cSlice_v3Km82sg, 0, 1);
  numBytes += cSlice_init(&cSlice_3lfEw6Lr, 2, 1);
  numBytes += cSlice_init(&cSlice_KAxym3ZU, 1, 1);
  numBytes += cVar_init_f(&cVar_AIRXCTeO, 1.0f);
  numBytes += cBinop_init(&cBinop_eAnwFIzP, -1.0f); // __add
  numBytes += cIf_init(&cIf_OYqjWt2c, false);
  numBytes += cIf_init(&cIf_ec5kPkgU, true);
  numBytes += cVar_init_f(&cVar_sydmQFwq, 0.0f);
  numBytes += cVar_init_f(&cVar_kxDffcU5, 1.0f);
  numBytes += cVar_init_f(&cVar_vcZs95Hh, 0.0f);
  numBytes += cVar_init_f(&cVar_qtFChMkH, 0.0f);
  numBytes += cVar_init_f(&cVar_qM8aqwdK, 0.0f);
  numBytes += cIf_init(&cIf_KTnAHiu9, false);
  numBytes += cIf_init(&cIf_8OWMivPX, true);
  numBytes += cBinop_init(&cBinop_MmnmQ2bD, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_eZ4IRKZI, 1.0f);
  numBytes += cVar_init_f(&cVar_XBXx5Z3O, 0.0f);
  numBytes += cVar_init_f(&cVar_xMR2hgCU, 0.0f);
  numBytes += cBinop_init(&cBinop_cQxprVnN, 2.0f); // __add
  numBytes += cIf_init(&cIf_XhExc0Ya, false);
  numBytes += cIf_init(&cIf_9m97yfRz, true);
  numBytes += cVar_init_f(&cVar_MbgkdBWm, 0.0f);
  numBytes += cVar_init_f(&cVar_pkJmAMPq, 0.0f);
  numBytes += cVar_init_f(&cVar_lH4bDjFI, 0.0f);
  numBytes += cIf_init(&cIf_pgKblwcZ, false);
  numBytes += cBinop_init(&cBinop_jZ2C6GJ8, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_E2UdgdVk, 1, -1);
  numBytes += cBinop_init(&cBinop_B91rgiiw, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_wEho1RZn, "minor_scale");
  numBytes += cTabread_init(&cTabread_bcuFDFqd, &hTable_sGgsBn21); // minor_scale
  numBytes += cVar_init_f(&cVar_pqLeCSJ1, 0.0f);
  numBytes += cVar_init_f(&cVar_QliHqtcS, 0.0f);
  numBytes += cBinop_init(&cBinop_F0AiXunH, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_BPPHcuim, 0.0f);
  numBytes += cIf_init(&cIf_VvRyMq9R, false);
  numBytes += cVar_init_f(&cVar_Kxvd3ldJ, 0.0f);
  numBytes += cBinop_init(&cBinop_mx5gfwC5, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_26gwY9Gk, 1, -1);
  numBytes += cSlice_init(&cSlice_CaVCJvnA, 1, -1);
  numBytes += cVar_init_f(&cVar_Sbaxe4J1, 0.0f);
  numBytes += cIf_init(&cIf_riOZX07m, false);
  numBytes += hTable_initWithData(&hTable_AH3vIPk6, 128, hTable_AH3vIPk6_data);
  numBytes += cBinop_init(&cBinop_qqVOrR1L, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_3EyQ5oMB, 1, -1);
  numBytes += cSlice_init(&cSlice_Lgbm4VEW, 1, -1);
  numBytes += cIf_init(&cIf_NTVuliB5, false);
  numBytes += cVar_init_f(&cVar_KqgnZ8gz, 0.0f);
  numBytes += cVar_init_f(&cVar_kmZkNDQ5, 0.0f);
  numBytes += cVar_init_f(&cVar_yKQCVfDr, 1.0f);
  numBytes += cBinop_init(&cBinop_1msREMbo, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_NXwUSC2D, 0.0f);
  numBytes += cVar_init_f(&cVar_RBD49CQx, 1.0f);
  numBytes += cVar_init_f(&cVar_NbcYV9nZ, 1.0f);
  numBytes += cDelay_init(this, &cDelay_TwJXvv6f, 20.0f);
  numBytes += cVar_init_f(&cVar_EuWV65fU, 0.0f);
  numBytes += cBinop_init(&cBinop_EMZcd0J0, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_DnPEJdE1, 0.0f);
  numBytes += cVar_init_f(&cVar_aBN52BX8, 1000.0f);
  numBytes += cBinop_init(&cBinop_1fRBJGat, 0.0f); // __div
  numBytes += cIf_init(&cIf_BigoEGkn, false);
  numBytes += cVar_init_f(&cVar_O8JdUxyv, 0.0f);
  numBytes += cVar_init_f(&cVar_F4UNMXcU, 2000.0f);
  numBytes += cVar_init_f(&cVar_1Yb3t2Wd, 0.2f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_ZWZsxh48);
  hTable_free(&hTable_1BTQytxE);
  cPack_free(&cPack_NJ0sy19t);
  cPack_free(&cPack_29XHnAkg);
  cPack_free(&cPack_vcGymGDY);
  hTable_free(&hTable_sGgsBn21);
  hTable_free(&hTable_AH3vIPk6);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB069134D: return &hTable_ZWZsxh48; // del-1339-pong
    case 0x4D17F050: return &hTable_sGgsBn21; // minor_scale
    case 0xCA62B065: return &hTable_1BTQytxE; // del-1339-ping
    case 0xBBA21A19: return &hTable_AH3vIPk6; // major_scale
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xC440C54F: { // Channel-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pmiG6XHT_sendMessage);
      break;
    }
    case 0xB762BB42: { // Channel-B
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_miaT1VXA_sendMessage);
      break;
    }
    case 0x27D89CD5: { // Channel-C
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Y2E6OoHH_sendMessage);
      break;
    }
    case 0x17512476: { // 1001-intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t52bMKqt_sendMessage);
      break;
    }
    case 0xD52A3BF1: { // 1001-mastertempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ySmyPMpz_sendMessage);
      break;
    }
    case 0x8CF5567: { // 1001-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ujf0qv8n_sendMessage);
      break;
    }
    case 0x8CC8BA58: { // 1001-transpose
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FUJNmdzd_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dp3PzL7I_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_k9n6s6eJ_sendMessage);
      break;
    }
    case 0xD1207465: { // pot1s
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_84x3ogyJ_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o4XobnaS_sendMessage);
      break;
    }
    case 0xE2E3FFA0: { // pot2s
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rpNz7y5X_sendMessage);
      break;
    }
    case 0xF2BC7D02: { // pot5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WVMlJlXv_sendMessage);
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
        info->defaultVal = 2000.0f;
        break;
      }
      case 1: {
        info->name = "pot2";
        info->hash = 0xDDC4EBDB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 512.0f;
        info->defaultVal = 256.0f;
        break;
      }
      case 2: {
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
  return 3;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cSend_g0mIscYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ujf0qv8n_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_Lprt8n9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_PB3FMpi4_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HVDpCZ5Z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_JvOT4p1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_G9Dz2UhV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Lprt8n9j, 0, m, &cIf_Lprt8n9j_sendMessage);
}

void Heavy_heavy::cUnop_HVDpCZ5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gubxLBa0, 0, m, &cIf_gubxLBa0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HsvXWn9s, 0, m, &cIf_HsvXWn9s_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_m8ol3Wok_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_WmGchbox_sendMessage);
}

void Heavy_heavy::cUnop_PB3FMpi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gubxLBa0, 0, m, &cIf_gubxLBa0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HsvXWn9s, 0, m, &cIf_HsvXWn9s_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_m8ol3Wok_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_WmGchbox_sendMessage);
}

void Heavy_heavy::cBinop_G9Dz2UhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lprt8n9j, 1, m, &cIf_Lprt8n9j_sendMessage);
}

void Heavy_heavy::cCast_xE1FjEX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SpBA86xz, 1, m, &cVar_SpBA86xz_sendMessage);
}

void Heavy_heavy::cCast_zvSO5PWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c0r2K5Gx, 0, m, &cVar_c0r2K5Gx_sendMessage);
}

void Heavy_heavy::cUnop_gOMXXexk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Sjpq67JT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kgZb2NAc, m);
}

void Heavy_heavy::cBinop_4VG7rbjq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aH9J45cI, HV_BINOP_MULTIPLY, 1, m, &cBinop_aH9J45cI_sendMessage);
}

void Heavy_heavy::cMsg_RO0jCfBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4VG7rbjq_sendMessage);
}

void Heavy_heavy::cSystem_afz17cyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RO0jCfBF_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_cJlwwbMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_afz17cyl_sendMessage);
}

void Heavy_heavy::cBinop_aH9J45cI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_585MaRrk_sendMessage);
}

void Heavy_heavy::cBinop_585MaRrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lo54H8Pk_sendMessage);
}

void Heavy_heavy::cBinop_lo54H8Pk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6XCz6K6W_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IXqZzo14, m);
}

void Heavy_heavy::cBinop_6XCz6K6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HRyUCTZ9, m);
}

void Heavy_heavy::cVar_n9VSwYWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aH9J45cI, HV_BINOP_MULTIPLY, 0, m, &cBinop_aH9J45cI_sendMessage);
}

void Heavy_heavy::cVar_T32Qcl30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8qwNpub1, 0, m, &cVar_8qwNpub1_sendMessage);
}

void Heavy_heavy::hTable_ZWZsxh48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W8pjEB81_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDMy8yWH, 2, m, &cDelay_bDMy8yWH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dj2frT63_sendMessage);
}

void Heavy_heavy::cDelay_bDMy8yWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bDMy8yWH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HGuc9jEv, 0, m, &cDelay_HGuc9jEv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDMy8yWH, 0, m, &cDelay_bDMy8yWH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_LDckccXt, 1, m, NULL);
}

void Heavy_heavy::cMsg_W8pjEB81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_HGuc9jEv, 2, m, &cDelay_HGuc9jEv_sendMessage);
}

void Heavy_heavy::cCast_Dj2frT63_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDMy8yWH, 0, m, &cDelay_bDMy8yWH_sendMessage);
}

void Heavy_heavy::cDelay_HGuc9jEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HGuc9jEv, m);
  cMsg_GH3VRSqN_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_ANz6oYOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ZWZsxh48, 0, m, &hTable_ZWZsxh48_sendMessage);
}

void Heavy_heavy::cMsg_O3N2KnsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n34lWEIe_sendMessage);
}

void Heavy_heavy::cSystem_n34lWEIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ijPelnHg_sendMessage);
}

void Heavy_heavy::cBinop_zqqGToRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ANz6oYOK_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_ijPelnHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_zqqGToRH_sendMessage);
}

void Heavy_heavy::cMsg_GH3VRSqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ZWZsxh48, 0, m, &hTable_ZWZsxh48_sendMessage);
}

void Heavy_heavy::cBinop_b3hLn5f0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dxrwHEE9_sendMessage);
}

void Heavy_heavy::cBinop_dxrwHEE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1Iwp1KiL, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zhz3bCq3, m);
}

void Heavy_heavy::cVar_Leb9V46Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CxFy3CqA, 0, m, &cVar_CxFy3CqA_sendMessage);
}

void Heavy_heavy::cBinop_f5OYp3lA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6i0VFWWs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_hhDlhBLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_gOMXXexk_sendMessage);
}

void Heavy_heavy::cBinop_wNNpfXED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n9VSwYWz, 0, m, &cVar_n9VSwYWz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2quAnLmD, 0, m, &cVar_2quAnLmD_sendMessage);
}

void Heavy_heavy::cBinop_jExjN6XP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EER3RzFd, HV_BINOP_POW, 1, m, &cBinop_EER3RzFd_sendMessage);
  cMsg_EgcXIo1M_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_S5UITE1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_jExjN6XP_sendMessage);
}

void Heavy_heavy::cMsg_EgcXIo1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EER3RzFd, HV_BINOP_POW, 0, m, &cBinop_EER3RzFd_sendMessage);
}

void Heavy_heavy::cBinop_EER3RzFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_wNNpfXED_sendMessage);
}

void Heavy_heavy::cBinop_iT09yP5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LKlcXpND_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1nnZJx9V_sendMessage);
}

void Heavy_heavy::cCast_XyQhtvp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_48INkRwD, 0, m, &cDelay_48INkRwD_sendMessage);
}

void Heavy_heavy::hTable_1BTQytxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gsBR87gb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_48INkRwD, 2, m, &cDelay_48INkRwD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XyQhtvp4_sendMessage);
}

void Heavy_heavy::cMsg_fsKQyGyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KZ8bfgO4_sendMessage);
}

void Heavy_heavy::cSystem_KZ8bfgO4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tGXcfAz6_sendMessage);
}

void Heavy_heavy::cMsg_gsBR87gb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_1XQkDJLl, 2, m, &cDelay_1XQkDJLl_sendMessage);
}

void Heavy_heavy::cMsg_k3z3Wau7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1BTQytxE, 0, m, &hTable_1BTQytxE_sendMessage);
}

void Heavy_heavy::cBinop_941nYHAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k3z3Wau7_sendMessage(_c, 0, m);
}

void Heavy_heavy::cDelay_48INkRwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_48INkRwD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1XQkDJLl, 0, m, &cDelay_1XQkDJLl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_48INkRwD, 0, m, &cDelay_48INkRwD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JakmLppA, 1, m, NULL);
}

void Heavy_heavy::cMsg_YYMYrfNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1BTQytxE, 0, m, &hTable_1BTQytxE_sendMessage);
}

void Heavy_heavy::cBinop_tGXcfAz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_941nYHAZ_sendMessage);
}

void Heavy_heavy::cDelay_1XQkDJLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1XQkDJLl, m);
  cMsg_YYMYrfNs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_1nnZJx9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BG4FgOIo, 0, m, &cVar_BG4FgOIo_sendMessage);
}

void Heavy_heavy::cVar_1ggSOC58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_O66fElES_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sUhCf4GQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2rqYHKA2_sendMessage);
}

void Heavy_heavy::cVar_8qwNpub1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.99f, 0, m, &cBinop_b3hLn5f0_sendMessage);
}

void Heavy_heavy::cMsg_IrORkdhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hhDlhBLw, HV_BINOP_SUBTRACT, 0, m, &cBinop_hhDlhBLw_sendMessage);
}

void Heavy_heavy::cMsg_6i0VFWWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_aglQGJpw, 0, m, NULL);
}

void Heavy_heavy::cSystem_expGe7Zq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SDprugo6_sendMessage);
}

void Heavy_heavy::cMsg_COdvu5p8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_expGe7Zq_sendMessage);
}

void Heavy_heavy::cBinop_7WlhCzKk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nVLkQmwY, m);
}

void Heavy_heavy::cSystem_mxPBnndj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7WlhCzKk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1uQSHNZC, m);
}

void Heavy_heavy::cMsg_GpnVdY3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mxPBnndj_sendMessage);
}

void Heavy_heavy::cVar_LDYgkgIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GpnVdY3K_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_SDprugo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qEpQ6i7O, m);
}

void Heavy_heavy::cVar_3kuzYB9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_iNOMVdQu_sendMessage);
}

void Heavy_heavy::cVar_WUtE6xpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1ggSOC58, 0, m, &cVar_1ggSOC58_sendMessage);
}

void Heavy_heavy::cVar_M4PXpPM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3kuzYB9L, 0, m, &cVar_3kuzYB9L_sendMessage);
}

void Heavy_heavy::cVar_CxFy3CqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BG4FgOIo, 0, m, &cVar_BG4FgOIo_sendMessage);
}

void Heavy_heavy::cCast_sUhCf4GQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IrORkdhs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_IOAhYlbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_S6VsOS7C_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_w1LC3orc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_mqpH5qlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IOAhYlbh, 1, m, &cIf_IOAhYlbh_sendMessage);
}

void Heavy_heavy::cVar_BG4FgOIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mqpH5qlO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IOAhYlbh, 0, m, &cIf_IOAhYlbh_sendMessage);
}

void Heavy_heavy::cUnop_S6VsOS7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f5OYp3lA, HV_BINOP_MULTIPLY, 0, m, &cBinop_f5OYp3lA_sendMessage);
}

void Heavy_heavy::cUnop_w1LC3orc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f5OYp3lA, HV_BINOP_MULTIPLY, 0, m, &cBinop_f5OYp3lA_sendMessage);
}

void Heavy_heavy::cBinop_M5BEIEdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_46F2R3tq, m);
}

void Heavy_heavy::cVar_jp46spu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X9HgThbo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_VkPihJdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3HS8lIGu_sendMessage);
}

void Heavy_heavy::cSystem_3HS8lIGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M5BEIEdA_sendMessage);
}

void Heavy_heavy::cMsg_X9HgThbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ORwMeuo9_sendMessage);
}

void Heavy_heavy::cBinop_jsxloX5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g1fw48zg, m);
}

void Heavy_heavy::cSystem_ORwMeuo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jsxloX5W_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_r8FwoLGq, m);
}

void Heavy_heavy::cUnop_O66fElES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_B0T2IhGf, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QZ5F20mC, m);
}

void Heavy_heavy::cBinop_SsRRMYCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_sldEBhOV_sendMessage);
}

void Heavy_heavy::cBinop_sldEBhOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tikBkKFl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jbTsaDaB, m);
}

void Heavy_heavy::cVar_2quAnLmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YsNRBk6A, HV_BINOP_MULTIPLY, 0, m, &cBinop_YsNRBk6A_sendMessage);
}

void Heavy_heavy::cMsg_ZT5N1hoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_q8mrclmY_sendMessage);
}

void Heavy_heavy::cBinop_q8mrclmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YsNRBk6A, HV_BINOP_MULTIPLY, 1, m, &cBinop_YsNRBk6A_sendMessage);
}

void Heavy_heavy::cSystem_tFb7Y1Z0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZT5N1hoI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_uFwB13e0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tFb7Y1Z0_sendMessage);
}

void Heavy_heavy::cBinop_YsNRBk6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SsRRMYCq_sendMessage);
}

void Heavy_heavy::cBinop_tikBkKFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GEaHrfin, m);
}

void Heavy_heavy::cBinop_iNOMVdQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_S5UITE1R_sendMessage);
}

void Heavy_heavy::cCast_2rqYHKA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hhDlhBLw, HV_BINOP_SUBTRACT, 1, m, &cBinop_hhDlhBLw_sendMessage);
}

void Heavy_heavy::cCast_LKlcXpND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_f5OYp3lA, HV_BINOP_MULTIPLY, 1, m, &cBinop_f5OYp3lA_sendMessage);
}

void Heavy_heavy::cCast_ab26hXnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jZ2C6GJ8, HV_BINOP_SUBTRACT, 1, m, &cBinop_jZ2C6GJ8_sendMessage);
}

void Heavy_heavy::cBinop_4h1mAm5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cjQey5Wo, 1, m, &cIf_cjQey5Wo_sendMessage);
}

void Heavy_heavy::cIf_cjQey5Wo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_8lkab5KR_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_58gWpjRu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_W0dvBX7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4h1mAm5G_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_cjQey5Wo, 0, m, &cIf_cjQey5Wo_sendMessage);
}

void Heavy_heavy::cUnop_8lkab5KR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Vp6wR1xl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_58gWpjRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Vp6wR1xl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_kXy15UXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OP5TKLiB, 0, m, &cVar_OP5TKLiB_sendMessage);
}

void Heavy_heavy::cSend_KhfSuUug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FUJNmdzd_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_VpepTetF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KhfSuUug_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_JBPkpui1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SpBA86xz, 0, m, &cVar_SpBA86xz_sendMessage);
}

void Heavy_heavy::cBinop_WnCyu5GA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_imsk0Ib1, 0, m, &cVar_imsk0Ib1_sendMessage);
}

void Heavy_heavy::cBinop_qx5VCrOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_REhnmwUq_sendMessage);
}

void Heavy_heavy::cCast_vNp3xLMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2LGy3tNy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_rpNz7y5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 512.0f, 0, m, &cBinop_LeLUytdp_sendMessage);
}

void Heavy_heavy::cVar_SpBA86xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xDe7kMvJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_xDe7kMvJ_sendMessage);
}

void Heavy_heavy::cVar_ZADRKcNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B71nrboF, 0, m, &cVar_B71nrboF_sendMessage);
}

void Heavy_heavy::cVar_TGCvp5Rv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EaHBSrkc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_7UXPaWWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_EaHBSrkc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_BLhy5Ljz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_EaHBSrkc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_B71nrboF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9r5IAbMF, HV_BINOP_ADD, 1, m, &cBinop_9r5IAbMF_sendMessage);
}

void Heavy_heavy::cCast_HQkM76VL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7UXPaWWh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_U6FLFtpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BLhy5Ljz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_gzQhuLTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pYPo1p6h_sendMessage);
}

void Heavy_heavy::cTabread_qh0MuQEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9r5IAbMF, HV_BINOP_ADD, 0, m, &cBinop_9r5IAbMF_sendMessage);
}

void Heavy_heavy::cSwitchcase_EaHBSrkc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oxqtp1jB, 0, m, &cSlice_oxqtp1jB_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DfYMhBm9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BrEHTDSg_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_oxqtp1jB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_qh0MuQEH, 1, m, &cTabread_qh0MuQEH_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_qh0MuQEH, 1, m, &cTabread_qh0MuQEH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_PssFDhkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gzQhuLTS_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_DfYMhBm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PssFDhkO, 0, m, &cVar_PssFDhkO_sendMessage);
}

void Heavy_heavy::cBinop_ii8gsWRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tRCfvmfR, HV_BINOP_MIN, 0, m, &cBinop_tRCfvmfR_sendMessage);
}

void Heavy_heavy::cCast_BrEHTDSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ii8gsWRc_sendMessage);
}

void Heavy_heavy::cBinop_NCjbzxaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tRCfvmfR, HV_BINOP_MIN, 1, m, &cBinop_tRCfvmfR_sendMessage);
}

void Heavy_heavy::cBinop_tRCfvmfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_qh0MuQEH, 0, m, &cTabread_qh0MuQEH_sendMessage);
}

void Heavy_heavy::cSystem_pYPo1p6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NCjbzxaO_sendMessage);
}

void Heavy_heavy::cBinop_9r5IAbMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_CF7gKdth_sendMessage);
}

void Heavy_heavy::cCast_OPbzjknL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HMJ5GrrC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_jRwLbmS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_84x3ogyJ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_5nvrZYQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W0dvBX7G, 0, m, &cVar_W0dvBX7G_sendMessage);
}

void Heavy_heavy::cBinop_l7G4SLzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qdvr97nw, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_qdvr97nw_sendMessage);
}

void Heavy_heavy::cVar_J1ai6ycL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7aHpkIyY, HV_BINOP_ADD, 1, m, &cBinop_7aHpkIyY_sendMessage);
}

void Heavy_heavy::cVar_dqnMcjex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7G4SLzA, HV_BINOP_MULTIPLY, 1, m, &cBinop_l7G4SLzA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZxoUC43e, HV_BINOP_LESS_THAN, 1, m, &cBinop_ZxoUC43e_sendMessage);
}

void Heavy_heavy::cVar_NYYyJ4Cl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2sSauajM, 0, m, &cVar_2sSauajM_sendMessage);
}

void Heavy_heavy::cVar_dQCdSeuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qdvr97nw, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_qdvr97nw_sendMessage);
}

void Heavy_heavy::cBinop_ZxoUC43e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FyYdmgtX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_O7Lk0HVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_htaQLqeb_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1rh0bRf4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_htaQLqeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQCdSeuS, 0, m, &cVar_dQCdSeuS_sendMessage);
}

void Heavy_heavy::cUnop_1rh0bRf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQCdSeuS, 0, m, &cVar_dQCdSeuS_sendMessage);
}

void Heavy_heavy::cVar_fmyRDTAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_TMtumx6t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_O7Lk0HVz, 0, m, &cIf_O7Lk0HVz_sendMessage);
}

void Heavy_heavy::cBinop_TMtumx6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O7Lk0HVz, 1, m, &cIf_O7Lk0HVz_sendMessage);
}

void Heavy_heavy::cCast_WcaA6Yab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XJvGF9xq, 0, m, &cVar_XJvGF9xq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nz5jK9ET, 0, m, &cVar_nz5jK9ET_sendMessage);
}

void Heavy_heavy::cVar_oHtYajEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dHbEopNs, 0, m, &cVar_dHbEopNs_sendMessage);
}

void Heavy_heavy::cUnop_btf1T84j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dqnMcjex, 0, m, &cVar_dqnMcjex_sendMessage);
}

void Heavy_heavy::cIf_W5EreUM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_K18LO7zu_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_btf1T84j_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_QlkNl2Ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W5EreUM2, 1, m, &cIf_W5EreUM2_sendMessage);
}

void Heavy_heavy::cVar_2sSauajM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QlkNl2Ne_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_W5EreUM2, 0, m, &cIf_W5EreUM2_sendMessage);
}

void Heavy_heavy::cUnop_K18LO7zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dqnMcjex, 0, m, &cVar_dqnMcjex_sendMessage);
}

void Heavy_heavy::cCast_wjhbJV7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_NMu7IGPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LjZdLJ7X_sendMessage);
}

void Heavy_heavy::cBinop_qdvr97nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZxoUC43e, HV_BINOP_LESS_THAN, 0, m, &cBinop_ZxoUC43e_sendMessage);
}

void Heavy_heavy::cBinop_LjZdLJ7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NMu7IGPR, 1, m, &cVar_NMu7IGPR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7aHpkIyY, HV_BINOP_ADD, 0, m, &cBinop_7aHpkIyY_sendMessage);
}

void Heavy_heavy::cCast_YOkA8l4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wjhbJV7q_sendMessage);
}

void Heavy_heavy::cSwitchcase_FyYdmgtX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YOkA8l4G_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WcaA6Yab_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_7aHpkIyY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7G4SLzA, HV_BINOP_MULTIPLY, 0, m, &cBinop_l7G4SLzA_sendMessage);
}

void Heavy_heavy::cVar_cHdRf4Il_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fmyRDTAj, 0, m, &cVar_fmyRDTAj_sendMessage);
}

void Heavy_heavy::cVar_dHbEopNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DPbraWYu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_c4O6BwEN, 0, m, &cIf_c4O6BwEN_sendMessage);
}

void Heavy_heavy::cBinop_DPbraWYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_c4O6BwEN, 1, m, &cIf_c4O6BwEN_sendMessage);
}

void Heavy_heavy::cIf_c4O6BwEN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BbN0M5SW_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HGEM1GW4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_HGEM1GW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J1ai6ycL, 0, m, &cVar_J1ai6ycL_sendMessage);
}

void Heavy_heavy::cUnop_BbN0M5SW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J1ai6ycL, 0, m, &cVar_J1ai6ycL_sendMessage);
}

void Heavy_heavy::cCast_EyPRZlIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3uQi5TzE, 0, m, &cIf_3uQi5TzE_sendMessage);
}

void Heavy_heavy::cVar_sVmRmZgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KhfSuUug_sendMessage(_c, 0, m);
  cSend_RKlQqieV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_3uQi5TzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DWPEqlDs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YClWYLUv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_j7tnxJv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3uQi5TzE, 1, m, &cIf_3uQi5TzE_sendMessage);
}

void Heavy_heavy::cCast_gYJw4e1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j7tnxJv8, HV_BINOP_NEQ, 0, m, &cBinop_j7tnxJv8_sendMessage);
}

void Heavy_heavy::cSlice_PM03CEY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_sVmRmZgM, 0, m, &cVar_sVmRmZgM_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_sVmRmZgM, 0, m, &cVar_sVmRmZgM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_VIkhQd62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_j7tnxJv8, HV_BINOP_NEQ, 1, m, &cBinop_j7tnxJv8_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_sVmRmZgM, 1, m, &cVar_sVmRmZgM_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_j7tnxJv8, HV_BINOP_NEQ, 1, m, &cBinop_j7tnxJv8_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_sVmRmZgM, 1, m, &cVar_sVmRmZgM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_auNYvEPf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PM03CEY1, 0, m, &cSlice_PM03CEY1_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VIkhQd62, 0, m, &cSlice_VIkhQd62_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gYJw4e1y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EyPRZlIW_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_DWPEqlDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j7tnxJv8, HV_BINOP_NEQ, 1, m, &cBinop_j7tnxJv8_sendMessage);
}

void Heavy_heavy::cCast_YClWYLUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sVmRmZgM, 0, m, &cVar_sVmRmZgM_sendMessage);
}

void Heavy_heavy::cSend_mmSjc85j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rpNz7y5X_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_afE9LxYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g0mIscYU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_hr0xFJKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iSiPlo7U, 0, m, &cVar_iSiPlo7U_sendMessage);
}

void Heavy_heavy::cBinop_kYfw89Cj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DseOfTQE, 0, m, &cVar_DseOfTQE_sendMessage);
}

void Heavy_heavy::cVar_xCKwQ5OQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lB8ggTGW, 0, m, &cVar_lB8ggTGW_sendMessage);
}

void Heavy_heavy::cIf_zUAweKoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_tP7CVXHp_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QzklQ53d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_tP7CVXHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZVRBaq17, 0, m, &cVar_ZVRBaq17_sendMessage);
}

void Heavy_heavy::cBinop_796nSCOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zUAweKoA, 1, m, &cIf_zUAweKoA_sendMessage);
}

void Heavy_heavy::cVar_JrKmn8XN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_796nSCOy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zUAweKoA, 0, m, &cIf_zUAweKoA_sendMessage);
}

void Heavy_heavy::cUnop_QzklQ53d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZVRBaq17, 0, m, &cVar_ZVRBaq17_sendMessage);
}

void Heavy_heavy::cCast_hzpoMGOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_17F3ZUaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oa9lfvkK, HV_BINOP_LESS_THAN, 0, m, &cBinop_oa9lfvkK_sendMessage);
}

void Heavy_heavy::cVar_o13yxY9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3IEwWT1F_sendMessage);
}

void Heavy_heavy::cVar_Y3JPfDWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hKktoyyZ, 0, m, &cVar_hKktoyyZ_sendMessage);
}

void Heavy_heavy::cVar_VxkS34l5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JrKmn8XN, 0, m, &cVar_JrKmn8XN_sendMessage);
}

void Heavy_heavy::cBinop_3IEwWT1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o13yxY9J, 1, m, &cVar_o13yxY9J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBfvRBIo, HV_BINOP_ADD, 0, m, &cBinop_JBfvRBIo_sendMessage);
}

void Heavy_heavy::cIf_NwshF51P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_fvJOyNno_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jxcQ8Zrz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_fvJOyNno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4jfftbP4, 0, m, &cVar_4jfftbP4_sendMessage);
}

void Heavy_heavy::cUnop_jxcQ8Zrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4jfftbP4, 0, m, &cVar_4jfftbP4_sendMessage);
}

void Heavy_heavy::cBinop_z5DLUeN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NwshF51P, 1, m, &cIf_NwshF51P_sendMessage);
}

void Heavy_heavy::cVar_hKktoyyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_z5DLUeN2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NwshF51P, 0, m, &cIf_NwshF51P_sendMessage);
}

void Heavy_heavy::cVar_P8PkzrLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W51lrqp5, 0, m, &cVar_W51lrqp5_sendMessage);
}

void Heavy_heavy::cBinop_oa9lfvkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_13LSW4El_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_tIdc0EFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hzpoMGOC_sendMessage);
}

void Heavy_heavy::cSwitchcase_13LSW4El_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tIdc0EFn_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tYyumMMl_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_pZyM2ajm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_17F3ZUaO, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_17F3ZUaO_sendMessage);
}

void Heavy_heavy::cCast_tYyumMMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0SZXfkBm, 0, m, &cVar_0SZXfkBm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eZ4IRKZI, 0, m, &cVar_eZ4IRKZI_sendMessage);
}

void Heavy_heavy::cVar_ZVRBaq17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_17F3ZUaO, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_17F3ZUaO_sendMessage);
}

void Heavy_heavy::cVar_4jfftbP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBfvRBIo, HV_BINOP_ADD, 1, m, &cBinop_JBfvRBIo_sendMessage);
}

void Heavy_heavy::cVar_amxB5fy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pZyM2ajm, HV_BINOP_MULTIPLY, 1, m, &cBinop_pZyM2ajm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oa9lfvkK, HV_BINOP_LESS_THAN, 1, m, &cBinop_oa9lfvkK_sendMessage);
}

void Heavy_heavy::cVar_W51lrqp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_M6Wn7Hu4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iYUNkVfU, 0, m, &cIf_iYUNkVfU_sendMessage);
}

void Heavy_heavy::cBinop_M6Wn7Hu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iYUNkVfU, 1, m, &cIf_iYUNkVfU_sendMessage);
}

void Heavy_heavy::cIf_iYUNkVfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_tjtvcSdH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eW0sMETa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_eW0sMETa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_amxB5fy9, 0, m, &cVar_amxB5fy9_sendMessage);
}

void Heavy_heavy::cUnop_tjtvcSdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_amxB5fy9, 0, m, &cVar_amxB5fy9_sendMessage);
}

void Heavy_heavy::cBinop_JBfvRBIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pZyM2ajm, HV_BINOP_MULTIPLY, 0, m, &cBinop_pZyM2ajm_sendMessage);
}

void Heavy_heavy::cBinop_LbDd4lPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8qwNpub1, 0, m, &cVar_8qwNpub1_sendMessage);
}

void Heavy_heavy::cVar_c0r2K5Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xDe7kMvJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_xDe7kMvJ_sendMessage);
}

void Heavy_heavy::cSend_RKlQqieV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_t52bMKqt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_fFj51LgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UWurcFWK, 1, m, &cIf_UWurcFWK_sendMessage);
}

void Heavy_heavy::cCast_pBw6oiKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFj51LgM, HV_BINOP_NEQ, 0, m, &cBinop_fFj51LgM_sendMessage);
}

void Heavy_heavy::cCast_mfHfN78W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ACqme6WH, 0, m, &cVar_ACqme6WH_sendMessage);
}

void Heavy_heavy::cIf_UWurcFWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xuqt2dnx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mfHfN78W_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_ACqme6WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_VpepTetF_sendMessage);
}

void Heavy_heavy::cCast_DFHyJQ9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UWurcFWK, 0, m, &cIf_UWurcFWK_sendMessage);
}

void Heavy_heavy::cCast_xuqt2dnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFj51LgM, HV_BINOP_NEQ, 1, m, &cBinop_fFj51LgM_sendMessage);
}

void Heavy_heavy::cSlice_8rfeEBwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_ACqme6WH, 0, m, &cVar_ACqme6WH_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_ACqme6WH, 0, m, &cVar_ACqme6WH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_vlItzcU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fFj51LgM, HV_BINOP_NEQ, 1, m, &cBinop_fFj51LgM_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ACqme6WH, 1, m, &cVar_ACqme6WH_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fFj51LgM, HV_BINOP_NEQ, 1, m, &cBinop_fFj51LgM_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ACqme6WH, 1, m, &cVar_ACqme6WH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_K2ClpjsU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8rfeEBwJ, 0, m, &cSlice_8rfeEBwJ_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vlItzcU7, 0, m, &cSlice_vlItzcU7_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pBw6oiKi_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DFHyJQ9w_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cReceive_dp3PzL7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XIja4t07_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ihqcTtpc, 0, m, &cVar_ihqcTtpc_sendMessage);
  cMsg_sJfEomRS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aBN52BX8, 0, m, &cVar_aBN52BX8_sendMessage);
  cMsg_LXJeBZRP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RBD49CQx, 0, m, &cVar_RBD49CQx_sendMessage);
  cMsg_qmp2bcR6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3X9wsLDX, 0, m, &cVar_3X9wsLDX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n5h0LSNL, 0, m, &cVar_n5h0LSNL_sendMessage);
  cMsg_3zHFyLZb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NwwW5qDs, 0, m, &cVar_NwwW5qDs_sendMessage);
  cSwitchcase_Ra831hmh_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Ui1P8NjA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_opEZO5CK, 0, m, &cVar_opEZO5CK_sendMessage);
  cMsg_UiRZ7JOE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gM6VXER7, 0, m, &cVar_gM6VXER7_sendMessage);
  cMsg_cJlwwbMi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n9VSwYWz, 0, m, &cVar_n9VSwYWz_sendMessage);
  cMsg_uFwB13e0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2quAnLmD, 0, m, &cVar_2quAnLmD_sendMessage);
  cMsg_fsKQyGyh_sendMessage(_c, 0, m);
  cMsg_O3N2KnsW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cA3gATI7, 0, m, &cVar_cA3gATI7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FQmH8qzn, 0, m, &cVar_FQmH8qzn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YJ0YSQcW, 0, m, &cVar_YJ0YSQcW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_isTEp57G, 0, m, &cVar_isTEp57G_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5Log8qDi, 0, m, &cVar_5Log8qDi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dCwtRYmh, 0, m, &cVar_dCwtRYmh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MbgkdBWm, 0, m, &cVar_MbgkdBWm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xMR2hgCU, 0, m, &cVar_xMR2hgCU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qtFChMkH, 0, m, &cVar_qtFChMkH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vcZs95Hh, 0, m, &cVar_vcZs95Hh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qM8aqwdK, 0, m, &cVar_qM8aqwdK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XBXx5Z3O, 0, m, &cVar_XBXx5Z3O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6iWSHoQN, 0, m, &cVar_6iWSHoQN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M5uftn2N, 0, m, &cVar_M5uftn2N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_D39J7QuR, 0, m, &cVar_D39J7QuR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UWe7uz3m, 0, m, &cVar_UWe7uz3m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y92q5whO, 0, m, &cVar_Y92q5whO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HsHZ6z9n, 0, m, &cVar_HsHZ6z9n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NbcYV9nZ, 0, m, &cVar_NbcYV9nZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_F4UNMXcU, 0, m, &cVar_F4UNMXcU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VxkS34l5, 0, m, &cVar_VxkS34l5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P8PkzrLL, 0, m, &cVar_P8PkzrLL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y3JPfDWS, 0, m, &cVar_Y3JPfDWS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n18uXsXT, 0, m, &cVar_n18uXsXT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hoVIrVqr, 0, m, &cVar_hoVIrVqr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nYQGY4h0, 0, m, &cVar_nYQGY4h0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cHdRf4Il, 0, m, &cVar_cHdRf4Il_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NYYyJ4Cl, 0, m, &cVar_NYYyJ4Cl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oHtYajEi, 0, m, &cVar_oHtYajEi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_caYyEUsf, 0, m, &cVar_caYyEUsf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vFeV0FXu, 0, m, &cVar_vFeV0FXu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6wEtIwSY, 0, m, &cVar_6wEtIwSY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DGEM3Efi, 0, m, &cVar_DGEM3Efi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pTCDDtZB, 0, m, &cVar_pTCDDtZB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DseOfTQE, 0, m, &cVar_DseOfTQE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4jojTPdL, 0, m, &cVar_4jojTPdL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_buuEYRMq, 0, m, &cVar_buuEYRMq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rvFzwTAN, 0, m, &cVar_rvFzwTAN_sendMessage);
  cMsg_DC6TO6kJ_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3R1jcqAM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QliHqtcS, 0, m, &cVar_QliHqtcS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5MURpL1v_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_061B1Ihh, 0, m, &cVar_061B1Ihh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U6FLFtpT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZADRKcNL, 0, m, &cVar_ZADRKcNL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y5Ma4nfk, 0, m, &cVar_y5Ma4nfk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Leb9V46Q, 0, m, &cVar_Leb9V46Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M4PXpPM1, 0, m, &cVar_M4PXpPM1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T32Qcl30, 0, m, &cVar_T32Qcl30_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WUtE6xpp, 0, m, &cVar_WUtE6xpp_sendMessage);
  cMsg_PyuhAh2W_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bkBlAzOV, 0, m, &cVar_bkBlAzOV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yKQCVfDr, 0, m, &cVar_yKQCVfDr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1Yb3t2Wd, 0, m, &cVar_1Yb3t2Wd_sendMessage);
  cSwitchcase_bA4xWimq_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_LDYgkgIK, 0, m, &cVar_LDYgkgIK_sendMessage);
  cMsg_COdvu5p8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jp46spu8, 0, m, &cVar_jp46spu8_sendMessage);
  cMsg_VkPihJdU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_CEQjFqUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1X56XHEB_sendMessage);
}

void Heavy_heavy::cVar_n18uXsXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KsPTRZhf, 0, m, &cVar_KsPTRZhf_sendMessage);
}

void Heavy_heavy::cBinop_8CHcdUcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkvmIO3E, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_pkvmIO3E_sendMessage);
}

void Heavy_heavy::cVar_nYQGY4h0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LNPnO8PO, 0, m, &cVar_LNPnO8PO_sendMessage);
}

void Heavy_heavy::cVar_hoVIrVqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QMZU2djc, 0, m, &cVar_QMZU2djc_sendMessage);
}

void Heavy_heavy::cVar_Ou6tk0yc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8CHcdUcy, HV_BINOP_MULTIPLY, 1, m, &cBinop_8CHcdUcy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uFtegjly, HV_BINOP_LESS_THAN, 1, m, &cBinop_uFtegjly_sendMessage);
}

void Heavy_heavy::cBinop_pkvmIO3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uFtegjly, HV_BINOP_LESS_THAN, 0, m, &cBinop_uFtegjly_sendMessage);
}

void Heavy_heavy::cBinop_7uNFz4VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8CHcdUcy, HV_BINOP_MULTIPLY, 0, m, &cBinop_8CHcdUcy_sendMessage);
}

void Heavy_heavy::cVar_WnpPvCmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7uNFz4VF, HV_BINOP_ADD, 1, m, &cBinop_7uNFz4VF_sendMessage);
}

void Heavy_heavy::cUnop_Av6xRsCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GEdSyWd9, 0, m, &cVar_GEdSyWd9_sendMessage);
}

void Heavy_heavy::cUnop_wLPebAvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GEdSyWd9, 0, m, &cVar_GEdSyWd9_sendMessage);
}

void Heavy_heavy::cVar_KsPTRZhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ODUPZOhl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_X30VlWVJ, 0, m, &cIf_X30VlWVJ_sendMessage);
}

void Heavy_heavy::cIf_X30VlWVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_wLPebAvH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Av6xRsCx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ODUPZOhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X30VlWVJ, 1, m, &cIf_X30VlWVJ_sendMessage);
}

void Heavy_heavy::cCast_V148piS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_LNPnO8PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NQwgo8iD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8bAfR41W, 0, m, &cIf_8bAfR41W_sendMessage);
}

void Heavy_heavy::cUnop_ZZNqoBdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WnpPvCmU, 0, m, &cVar_WnpPvCmU_sendMessage);
}

void Heavy_heavy::cIf_8bAfR41W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_FkyEVRnt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZZNqoBdf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_NQwgo8iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8bAfR41W, 1, m, &cIf_8bAfR41W_sendMessage);
}

void Heavy_heavy::cUnop_FkyEVRnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WnpPvCmU, 0, m, &cVar_WnpPvCmU_sendMessage);
}

void Heavy_heavy::cCast_kDvd7z17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V148piS8_sendMessage);
}

void Heavy_heavy::cSwitchcase_lFV3ythq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDvd7z17_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54nXpwn6_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_GEdSyWd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pkvmIO3E, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_pkvmIO3E_sendMessage);
}

void Heavy_heavy::cBinop_uFtegjly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lFV3ythq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_54nXpwn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t4n2OEER, 0, m, &cVar_t4n2OEER_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rR8zJ5wb, 0, m, &cVar_rR8zJ5wb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wygWYgSD, 0, m, &cVar_wygWYgSD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PeytvIhF, 0, m, &cVar_PeytvIhF_sendMessage);
}

void Heavy_heavy::cBinop_1X56XHEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CEQjFqUN, 1, m, &cVar_CEQjFqUN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7uNFz4VF, HV_BINOP_ADD, 0, m, &cBinop_7uNFz4VF_sendMessage);
}

void Heavy_heavy::cIf_jJI97OXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BixwMS25_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YHFB8IJy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_BixwMS25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ou6tk0yc, 0, m, &cVar_Ou6tk0yc_sendMessage);
}

void Heavy_heavy::cVar_QMZU2djc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_UUuNmkqn_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jJI97OXA, 0, m, &cIf_jJI97OXA_sendMessage);
}

void Heavy_heavy::cBinop_UUuNmkqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jJI97OXA, 1, m, &cIf_jJI97OXA_sendMessage);
}

void Heavy_heavy::cUnop_YHFB8IJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ou6tk0yc, 0, m, &cVar_Ou6tk0yc_sendMessage);
}

void Heavy_heavy::cBinop_REhnmwUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JvOT4p1N, 1, m, &cVar_JvOT4p1N_sendMessage);
}

void Heavy_heavy::cVar_ZkeyVBFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_i8bsNbXx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Gy2lJH6D, 0, m, &cIf_Gy2lJH6D_sendMessage);
}

void Heavy_heavy::cUnop_CPxoAOM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K2ClpjsU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_Gy2lJH6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_CPxoAOM9_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5BtMTcij_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_i8bsNbXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Gy2lJH6D, 1, m, &cIf_Gy2lJH6D_sendMessage);
}

void Heavy_heavy::cUnop_5BtMTcij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K2ClpjsU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_didU4YgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RKlQqieV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_HMJ5GrrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jZ2C6GJ8, HV_BINOP_SUBTRACT, 0, m, &cBinop_jZ2C6GJ8_sendMessage);
}

void Heavy_heavy::cReceive_miaT1VXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_OTTp6YTW_sendMessage);
}

void Heavy_heavy::cBinop_WmGchbox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rPYReOQy, 0, m, &cIf_rPYReOQy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yvCnPkpU, 0, m, &cIf_yvCnPkpU_sendMessage);
}

void Heavy_heavy::cReceive_t52bMKqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ab26hXnJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OPbzjknL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.85f, 0, m, &cBinop_LbDd4lPH_sendMessage);
}

void Heavy_heavy::cBinop_OaCp9l7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EqXf8Pfj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vNp3xLMi_sendMessage);
}

void Heavy_heavy::cBinop_pPKPAuCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fedGXTW0, HV_BINOP_MULTIPLY, 1, m, &cBinop_fedGXTW0_sendMessage);
}

void Heavy_heavy::cSwitchcase_bA4xWimq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_icVCm7de_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_icVCm7de_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rEHyuv0N_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_icVCm7de_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jWAR7A0, 0, m, &cDelay_3jWAR7A0_sendMessage);
}

void Heavy_heavy::cBinop_fedGXTW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_fghjMbbX_sendMessage);
}

void Heavy_heavy::cDelay_3jWAR7A0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3jWAR7A0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jWAR7A0, 0, m, &cDelay_3jWAR7A0_sendMessage);
  cMsg_ghi9YjAB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_wGu9eQez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pPKPAuCR_sendMessage);
}

void Heavy_heavy::cMsg_PyuhAh2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wGu9eQez_sendMessage);
}

void Heavy_heavy::cCast_rEHyuv0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_icVCm7de_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jWAR7A0, 0, m, &cDelay_3jWAR7A0_sendMessage);
  cMsg_ghi9YjAB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_fghjMbbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jWAR7A0, 2, m, &cDelay_3jWAR7A0_sendMessage);
}

void Heavy_heavy::cVar_bkBlAzOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fedGXTW0, HV_BINOP_MULTIPLY, 0, m, &cBinop_fedGXTW0_sendMessage);
}

void Heavy_heavy::cMsg_2LGy3tNy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4300.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PsBhoG5h, HV_BINOP_SUBTRACT, 0, m, &cBinop_PsBhoG5h_sendMessage);
}

void Heavy_heavy::cBinop_ZqzbuQuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_i100uZ6U_sendMessage);
}

void Heavy_heavy::cMsg_Au0Hjnxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_s9NalwSZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_wIwDwWff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_s9NalwSZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_iMMZ0tDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wIwDwWff_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_ioXwEwjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PsrF0Iz1_sendMessage);
}

void Heavy_heavy::cSlice_niuIOKV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_v8OkxrFn, 1, m, &cTabread_v8OkxrFn_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_v8OkxrFn, 1, m, &cTabread_v8OkxrFn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_s9NalwSZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_niuIOKV7, 0, m, &cSlice_niuIOKV7_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Mwjrab7A_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ioXwEwjI_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_fWvOnB3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_85MK5Wv3, HV_BINOP_MIN, 1, m, &cBinop_85MK5Wv3_sendMessage);
}

void Heavy_heavy::cBinop_PsrF0Iz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_85MK5Wv3, HV_BINOP_MIN, 0, m, &cBinop_85MK5Wv3_sendMessage);
}

void Heavy_heavy::cCast_Mwjrab7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KM7L6oX9, 0, m, &cVar_KM7L6oX9_sendMessage);
}

void Heavy_heavy::cBinop_85MK5Wv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_v8OkxrFn, 0, m, &cTabread_v8OkxrFn_sendMessage);
}

void Heavy_heavy::cVar_KM7L6oX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qGbhXczE_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_qGbhXczE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GNiYroet_sendMessage);
}

void Heavy_heavy::cTabread_v8OkxrFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqzbuQuh, HV_BINOP_ADD, 0, m, &cBinop_ZqzbuQuh_sendMessage);
}

void Heavy_heavy::cSystem_GNiYroet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fWvOnB3s_sendMessage);
}

void Heavy_heavy::cVar_30rn3IfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqzbuQuh, HV_BINOP_ADD, 1, m, &cBinop_ZqzbuQuh_sendMessage);
}

void Heavy_heavy::cVar_061B1Ihh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_30rn3IfO, 0, m, &cVar_30rn3IfO_sendMessage);
}

void Heavy_heavy::cCast_5MURpL1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Au0Hjnxx_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_2CHmAZbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_s9NalwSZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_xDe7kMvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pTCDDtZB, 0, m, &cVar_pTCDDtZB_sendMessage);
}

void Heavy_heavy::cBinop_PsBhoG5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F4UNMXcU, 0, m, &cVar_F4UNMXcU_sendMessage);
  cSend_S0AdbwZo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cPack_NJ0sy19t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_w7DH4OJg, 0, m, NULL);
}

void Heavy_heavy::cBinop_byZEQt3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ovIe3RML_sendMessage);
}

void Heavy_heavy::cBinop_CF7gKdth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_AtY0g9FZ_sendMessage);
}

void Heavy_heavy::cMsg_YGU7P5jS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_byZEQt3J, HV_BINOP_POW, 0, m, &cBinop_byZEQt3J_sendMessage);
}

void Heavy_heavy::cBinop_ovIe3RML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vcGymGDY, 0, m, &cPack_vcGymGDY_sendMessage);
}

void Heavy_heavy::cBinop_AtY0g9FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_byZEQt3J, HV_BINOP_POW, 1, m, &cBinop_byZEQt3J_sendMessage);
  cMsg_YGU7P5jS_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_cOwaqrVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q68ZuXM, HV_BINOP_POW, 1, m, &cBinop_7Q68ZuXM_sendMessage);
  cMsg_Z8We27bv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_oiB65Xlt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NJ0sy19t, 0, m, &cPack_NJ0sy19t_sendMessage);
}

void Heavy_heavy::cBinop_7Q68ZuXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_oiB65Xlt_sendMessage);
}

void Heavy_heavy::cBinop_gWJeJ7Hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_cOwaqrVp_sendMessage);
}

void Heavy_heavy::cMsg_Z8We27bv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Q68ZuXM, HV_BINOP_POW, 0, m, &cBinop_7Q68ZuXM_sendMessage);
}

void Heavy_heavy::cPack_29XHnAkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TBVKf7tP, 0, m, NULL);
}

void Heavy_heavy::cPack_vcGymGDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yxsgbgza, 0, m, NULL);
}

void Heavy_heavy::cVar_OP5TKLiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_NJ0sy19t, 1, m, &cPack_NJ0sy19t_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_29XHnAkg, 1, m, &cPack_29XHnAkg_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_vcGymGDY, 1, m, &cPack_vcGymGDY_sendMessage);
}

void Heavy_heavy::cVar_y5Ma4nfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OP5TKLiB, 0, m, &cVar_OP5TKLiB_sendMessage);
}

void Heavy_heavy::cBinop_2SoHsYLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9fROUTkY, HV_BINOP_POW, 1, m, &cBinop_9fROUTkY_sendMessage);
  cMsg_YkYt3Xax_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_xib518ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_29XHnAkg, 0, m, &cPack_29XHnAkg_sendMessage);
}

void Heavy_heavy::cMsg_YkYt3Xax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9fROUTkY, HV_BINOP_POW, 0, m, &cBinop_9fROUTkY_sendMessage);
}

void Heavy_heavy::cBinop_i100uZ6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_2SoHsYLU_sendMessage);
}

void Heavy_heavy::cBinop_9fROUTkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_xib518ic_sendMessage);
}

void Heavy_heavy::cVar_AsNMcfGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwChAOZy, HV_BINOP_MULTIPLY, 1, m, &cBinop_qwChAOZy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AKx8peis, HV_BINOP_LESS_THAN, 1, m, &cBinop_AKx8peis_sendMessage);
}

void Heavy_heavy::cBinop_zyMEUTzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_v0tQ0v9S, 1, m, &cIf_v0tQ0v9S_sendMessage);
}

void Heavy_heavy::cUnop_hu2NUgCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AsNMcfGw, 0, m, &cVar_AsNMcfGw_sendMessage);
}

void Heavy_heavy::cUnop_CsDWXJs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AsNMcfGw, 0, m, &cVar_AsNMcfGw_sendMessage);
}

void Heavy_heavy::cVar_Ddtqjlek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zyMEUTzN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_v0tQ0v9S, 0, m, &cIf_v0tQ0v9S_sendMessage);
}

void Heavy_heavy::cIf_v0tQ0v9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_CsDWXJs8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hu2NUgCv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_J7FOaE7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_jfJa4sr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_l3ozmOyV_sendMessage);
}

void Heavy_heavy::cVar_zDRuJOQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1gnjz8aC, HV_BINOP_ADD, 1, m, &cBinop_1gnjz8aC_sendMessage);
}

void Heavy_heavy::cCast_2LlwROmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwjpIYJv, 0, m, &cVar_qwjpIYJv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3hl1gBbw, 0, m, &cVar_3hl1gBbw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kxDffcU5, 0, m, &cVar_kxDffcU5_sendMessage);
}

void Heavy_heavy::cBinop_1gnjz8aC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwChAOZy, HV_BINOP_MULTIPLY, 0, m, &cBinop_qwChAOZy_sendMessage);
}

void Heavy_heavy::cVar_vFeV0FXu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ddtqjlek, 0, m, &cVar_Ddtqjlek_sendMessage);
}

void Heavy_heavy::cVar_caYyEUsf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l4RtqX9t, 0, m, &cVar_l4RtqX9t_sendMessage);
}

void Heavy_heavy::cVar_l4RtqX9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9iorTo7t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KwWQhyUL, 0, m, &cIf_KwWQhyUL_sendMessage);
}

void Heavy_heavy::cBinop_9iorTo7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KwWQhyUL, 1, m, &cIf_KwWQhyUL_sendMessage);
}

void Heavy_heavy::cUnop_TWIrLyXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYVbAqqx, 0, m, &cVar_vYVbAqqx_sendMessage);
}

void Heavy_heavy::cUnop_2f15hwcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vYVbAqqx, 0, m, &cVar_vYVbAqqx_sendMessage);
}

void Heavy_heavy::cIf_KwWQhyUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_TWIrLyXf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2f15hwcC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_l3ozmOyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jfJa4sr4, 1, m, &cVar_jfJa4sr4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1gnjz8aC, HV_BINOP_ADD, 0, m, &cBinop_1gnjz8aC_sendMessage);
}

void Heavy_heavy::cVar_6wEtIwSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A8buZwt0, 0, m, &cVar_A8buZwt0_sendMessage);
}

void Heavy_heavy::cCast_Tdn9q27b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J7FOaE7M_sendMessage);
}

void Heavy_heavy::cSwitchcase_Pibiq1zu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tdn9q27b_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2LlwROmj_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_qwChAOZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BfdGDli9, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_BfdGDli9_sendMessage);
}

void Heavy_heavy::cBinop_BfdGDli9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AKx8peis, HV_BINOP_LESS_THAN, 0, m, &cBinop_AKx8peis_sendMessage);
}

void Heavy_heavy::cBinop_MKPuYXBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SwVa52LZ, 1, m, &cIf_SwVa52LZ_sendMessage);
}

void Heavy_heavy::cUnop_CpdSBihk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zDRuJOQr, 0, m, &cVar_zDRuJOQr_sendMessage);
}

void Heavy_heavy::cVar_A8buZwt0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MKPuYXBe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SwVa52LZ, 0, m, &cIf_SwVa52LZ_sendMessage);
}

void Heavy_heavy::cUnop_2v9DFdQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zDRuJOQr, 0, m, &cVar_zDRuJOQr_sendMessage);
}

void Heavy_heavy::cIf_SwVa52LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_CpdSBihk_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2v9DFdQS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_AKx8peis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Pibiq1zu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_vYVbAqqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BfdGDli9, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_BfdGDli9_sendMessage);
}

void Heavy_heavy::cVar_FQmH8qzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t4n2OEER, 0, m, &cVar_t4n2OEER_sendMessage);
}

void Heavy_heavy::cIf_j8R1kPtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_IBqmK0ql, 0, m, &cIf_IBqmK0ql_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_TCB8yNwr, 0, m, &cIf_TCB8yNwr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_03zmzUyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IBqmK0ql, 0, m, &cIf_IBqmK0ql_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TCB8yNwr, 0, m, &cIf_TCB8yNwr_sendMessage);
}

void Heavy_heavy::cIf_wUcCm6JR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_03zmzUyl, HV_BINOP_ADD, 0, m, &cBinop_03zmzUyl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_EszzCPHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j8R1kPtN, 1, m, &cIf_j8R1kPtN_sendMessage);
}

void Heavy_heavy::cSlice_Cv5DG48A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BKyrVABE, HV_BINOP_ADD, 1, m, &cBinop_BKyrVABE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_EfIqMlBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_03zmzUyl, HV_BINOP_ADD, 1, m, &cBinop_03zmzUyl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_9yFwdI8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RNh5SJ0f, HV_BINOP_ADD, 1, m, &cBinop_RNh5SJ0f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_8ylWRZ5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_Y24E8y7j, 0, m, &cVar_Y24E8y7j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_PcwxPqjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_5Xay8MhQ, HV_BINOP_ADD, 1, m, &cBinop_5Xay8MhQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_Y24E8y7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4er5c1OB, 0, m, &cVar_4er5c1OB_sendMessage);
}

void Heavy_heavy::cVar_5Log8qDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rR8zJ5wb, 0, m, &cVar_rR8zJ5wb_sendMessage);
}

void Heavy_heavy::cVar_t4n2OEER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qFRCbmmX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EszzCPHc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wUcCm6JR, 1, m, &cIf_wUcCm6JR_sendMessage);
}

void Heavy_heavy::cBinop_qFRCbmmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t4n2OEER, 1, m, &cVar_t4n2OEER_sendMessage);
}

void Heavy_heavy::cVar_dCwtRYmh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y24E8y7j, 0, m, &cVar_Y24E8y7j_sendMessage);
}

void Heavy_heavy::cIf_FfGFVBfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_jd7WFdlh, 0, m, &cIf_jd7WFdlh_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_qdqNMDKx, 0, m, &cIf_qdqNMDKx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_JUreMkOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_BKyrVABE, HV_BINOP_ADD, 0, m, &cBinop_BKyrVABE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_BKyrVABE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jd7WFdlh, 0, m, &cIf_jd7WFdlh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qdqNMDKx, 0, m, &cIf_qdqNMDKx_sendMessage);
}

void Heavy_heavy::cBinop_C8vv9OCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FfGFVBfa, 1, m, &cIf_FfGFVBfa_sendMessage);
}

void Heavy_heavy::cVar_YJ0YSQcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rOWRTHxz, 0, m, &cVar_rOWRTHxz_sendMessage);
}

void Heavy_heavy::cVar_6m9tVKpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AQLVydlI, HV_BINOP_ADD, 1, m, &cBinop_AQLVydlI_sendMessage);
}

void Heavy_heavy::cBinop_DsxxDIQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HsvXWn9s, 1, m, &cIf_HsvXWn9s_sendMessage);
}

void Heavy_heavy::cIf_HsvXWn9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_wUcCm6JR, 0, m, &cIf_wUcCm6JR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_j8R1kPtN, 0, m, &cIf_j8R1kPtN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_5Xay8MhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wUcCm6JR, 0, m, &cIf_wUcCm6JR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j8R1kPtN, 0, m, &cIf_j8R1kPtN_sendMessage);
}

void Heavy_heavy::cIf_gubxLBa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_5Xay8MhQ, HV_BINOP_ADD, 0, m, &cBinop_5Xay8MhQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_jd7WFdlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_AQLVydlI, HV_BINOP_ADD, 0, m, &cBinop_AQLVydlI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_qdqNMDKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_pqLeCSJ1, 0, m, &cVar_pqLeCSJ1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_HOf1feRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qdqNMDKx, 1, m, &cIf_qdqNMDKx_sendMessage);
}

void Heavy_heavy::cBinop_AQLVydlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pqLeCSJ1, 0, m, &cVar_pqLeCSJ1_sendMessage);
}

void Heavy_heavy::cVar_isTEp57G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwjpIYJv, 0, m, &cVar_qwjpIYJv_sendMessage);
}

void Heavy_heavy::cBinop_2Yap1Jmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rR8zJ5wb, 1, m, &cVar_rR8zJ5wb_sendMessage);
}

void Heavy_heavy::cVar_rR8zJ5wb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_2Yap1Jmf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_HOf1feRc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jd7WFdlh, 1, m, &cIf_jd7WFdlh_sendMessage);
}

void Heavy_heavy::cBinop_WWLjtHbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0SZXfkBm, 1, m, &cVar_0SZXfkBm_sendMessage);
}

void Heavy_heavy::cVar_0SZXfkBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_WWLjtHbT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DsxxDIQe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gubxLBa0, 1, m, &cIf_gubxLBa0_sendMessage);
}

void Heavy_heavy::cVar_qwjpIYJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jBW6ouUK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_C8vv9OCl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JUreMkOw, 1, m, &cIf_JUreMkOw_sendMessage);
}

void Heavy_heavy::cBinop_jBW6ouUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwjpIYJv, 1, m, &cVar_qwjpIYJv_sendMessage);
}

void Heavy_heavy::cBinop_jC3KB7bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rOWRTHxz, 1, m, &cVar_rOWRTHxz_sendMessage);
}

void Heavy_heavy::cVar_rOWRTHxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jC3KB7bu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YnwASYCB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IBqmK0ql, 1, m, &cIf_IBqmK0ql_sendMessage);
}

void Heavy_heavy::cBinop_RNh5SJ0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JUreMkOw, 0, m, &cIf_JUreMkOw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_FfGFVBfa, 0, m, &cIf_FfGFVBfa_sendMessage);
}

void Heavy_heavy::cIf_TCB8yNwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_JUreMkOw, 0, m, &cIf_JUreMkOw_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_FfGFVBfa, 0, m, &cIf_FfGFVBfa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_IBqmK0ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RNh5SJ0f, HV_BINOP_ADD, 0, m, &cBinop_RNh5SJ0f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_YnwASYCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TCB8yNwr, 1, m, &cIf_TCB8yNwr_sendMessage);
}

void Heavy_heavy::cUnop_YNg1T24w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6m9tVKpr, 0, m, &cVar_6m9tVKpr_sendMessage);
}

void Heavy_heavy::cIf_xk0wRNMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_YNg1T24w_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tLPaQkZP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_tLPaQkZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6m9tVKpr, 0, m, &cVar_6m9tVKpr_sendMessage);
}

void Heavy_heavy::cBinop_cBZjF0Pv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xk0wRNMA, 1, m, &cIf_xk0wRNMA_sendMessage);
}

void Heavy_heavy::cVar_4er5c1OB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cBZjF0Pv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xk0wRNMA, 0, m, &cIf_xk0wRNMA_sendMessage);
}

void Heavy_heavy::cVar_cA3gATI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0SZXfkBm, 0, m, &cVar_0SZXfkBm_sendMessage);
}

void Heavy_heavy::cBinop_LeLUytdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_auNYvEPf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_Y2E6OoHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_5nvrZYQX_sendMessage);
}

void Heavy_heavy::cReceive_FUJNmdzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_qx5VCrOS_sendMessage);
}

void Heavy_heavy::cVar_DGEM3Efi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qvFGvrjV, 0, m, &cVar_qvFGvrjV_sendMessage);
}

void Heavy_heavy::cCast_lYh7GIHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M0EzhsMQ, 0, m, &cVar_M0EzhsMQ_sendMessage);
}

void Heavy_heavy::cVar_zaDY0v7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M0EzhsMQ, 1, m, &cVar_M0EzhsMQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZPIYDFD, HV_BINOP_ADD, 0, m, &cBinop_MZPIYDFD_sendMessage);
}

void Heavy_heavy::cCast_5EFbRYOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DTYIqiCb, HV_BINOP_MULTIPLY, 0, m, &cBinop_DTYIqiCb_sendMessage);
}

void Heavy_heavy::cCast_KhSX4ObL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QX6WROVH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6B6vMpvb_sendMessage);
}

void Heavy_heavy::cCast_WGHROYBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EsfVkSuE, 0, m, &cVar_EsfVkSuE_sendMessage);
}

void Heavy_heavy::cSwitchcase_4OJ6vKUS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WGHROYBg_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KhSX4ObL_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cVar_HxVEGPju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5EFbRYOP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bk8Y4rP7_sendMessage);
}

void Heavy_heavy::cSlice_hqRfnfDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6w5skfQb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_6w5skfQb_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_DVSpNeGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDg1LsuX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bePvm7Ls_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kDg1LsuX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bePvm7Ls_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_t2EZ0s9o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hqRfnfDh, 0, m, &cSlice_hqRfnfDh_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DVSpNeGN, 0, m, &cSlice_DVSpNeGN_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mFFf8UhI_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AF3GgFGt, 0, m, &cSlice_AF3GgFGt_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_o8zau1VN, 0, m, &cSlice_o8zau1VN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AjClmAxc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BZmJIBsK_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_ACDd7Log_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3X9wsLDX, 0, m, &cVar_3X9wsLDX_sendMessage);
}

void Heavy_heavy::cCast_bePvm7Ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rmP1Ko1P_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACDd7Log, HV_BINOP_ADD, 0, m, &cBinop_ACDd7Log_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EsfVkSuE, 1, m, &cVar_EsfVkSuE_sendMessage);
}

void Heavy_heavy::cMsg_6w5skfQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_H8MT1GN0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSystem_rIqSrq24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fOLGUiWY, HV_BINOP_MULTIPLY, 1, m, &cBinop_fOLGUiWY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DTYIqiCb, HV_BINOP_MULTIPLY, 1, m, &cBinop_DTYIqiCb_sendMessage);
}

void Heavy_heavy::cMsg_qmp2bcR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rIqSrq24_sendMessage);
}

void Heavy_heavy::cBinop_yZP7We8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4OJ6vKUS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_6guThNfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0c4hkQjZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_0c4hkQjZ_sendMessage);
}

void Heavy_heavy::cSlice_o8zau1VN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u7eymT7M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OLrCzfLt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_AF3GgFGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5EFbRYOP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bk8Y4rP7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_OLrCzfLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwBMmRzq, HV_BINOP_SUBTRACT, 0, m, &cBinop_OwBMmRzq_sendMessage);
}

void Heavy_heavy::cVar_ihqcTtpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KtqtnTol, HV_BINOP_MULTIPLY, 0, m, &cBinop_KtqtnTol_sendMessage);
}

void Heavy_heavy::cBinop_KtqtnTol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_HuDqk7Av_sendMessage);
}

void Heavy_heavy::cMsg_DFHeoM45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_GPtlFlAo, 0, m, &cDelay_GPtlFlAo_sendMessage);
}

void Heavy_heavy::cMsg_XIja4t07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lZswei7e_sendMessage);
}

void Heavy_heavy::cSystem_lZswei7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8HtwHjFK_sendMessage);
}

void Heavy_heavy::cCast_gBLCcgDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DFHeoM45_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GPtlFlAo, 0, m, &cDelay_GPtlFlAo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_O1238Com, 0, m, &cVar_O1238Com_sendMessage);
}

void Heavy_heavy::cSwitchcase_H8MT1GN0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_DFHeoM45_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_DFHeoM45_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gBLCcgDg_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_8HtwHjFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KtqtnTol, HV_BINOP_MULTIPLY, 1, m, &cBinop_KtqtnTol_sendMessage);
}

void Heavy_heavy::cBinop_HuDqk7Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GPtlFlAo, 2, m, &cDelay_GPtlFlAo_sendMessage);
}

void Heavy_heavy::cDelay_GPtlFlAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GPtlFlAo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GPtlFlAo, 0, m, &cDelay_GPtlFlAo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_O1238Com, 0, m, &cVar_O1238Com_sendMessage);
}

void Heavy_heavy::cMsg_9WLbRN4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_H8MT1GN0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_NI8DT43r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EsfVkSuE, 1, m, &cVar_EsfVkSuE_sendMessage);
}

void Heavy_heavy::cCast_BZmJIBsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aFZozoqx_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_QX6WROVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GpyJBErZ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_n0VJjOOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EsfVkSuE, 0, m, &cVar_EsfVkSuE_sendMessage);
}

void Heavy_heavy::cCast_rmP1Ko1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GpyJBErZ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_mFFf8UhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HxVEGPju, 0, m, &cVar_HxVEGPju_sendMessage);
}

void Heavy_heavy::cBinop_DTYIqiCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_24u5ryz1_sendMessage);
}

void Heavy_heavy::cBinop_RN7YQEq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACDd7Log, HV_BINOP_ADD, 1, m, &cBinop_ACDd7Log_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NI8DT43r, HV_BINOP_ADD, 1, m, &cBinop_NI8DT43r_sendMessage);
}

void Heavy_heavy::cVar_n5h0LSNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2FygU0je_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_acEGyexl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fOLGUiWY, HV_BINOP_MULTIPLY, 0, m, &cBinop_fOLGUiWY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8S1vMaoB, HV_BINOP_DIVIDE, 1, m, &cBinop_8S1vMaoB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ihqcTtpc, 0, m, &cVar_ihqcTtpc_sendMessage);
}

void Heavy_heavy::cVar_O1238Com_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0c4hkQjZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_0c4hkQjZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_yZP7We8J_sendMessage);
}

void Heavy_heavy::cBinop_fOLGUiWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6guThNfZ_sendMessage);
}

void Heavy_heavy::cCast_u7eymT7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n0VJjOOL, 1, m, &cVar_n0VJjOOL_sendMessage);
}

void Heavy_heavy::cBinop_8S1vMaoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RN7YQEq8, HV_BINOP_DIVIDE, 1, m, &cBinop_RN7YQEq8_sendMessage);
}

void Heavy_heavy::cCast_6B6vMpvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n0VJjOOL, 0, m, &cVar_n0VJjOOL_sendMessage);
}

void Heavy_heavy::cBinop_24u5ryz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O1238Com, 1, m, &cVar_O1238Com_sendMessage);
}

void Heavy_heavy::cVar_EsfVkSuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NI8DT43r, HV_BINOP_ADD, 0, m, &cBinop_NI8DT43r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACDd7Log, HV_BINOP_ADD, 0, m, &cBinop_ACDd7Log_sendMessage);
}

void Heavy_heavy::cBinop_0c4hkQjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O1238Com, 1, m, &cVar_O1238Com_sendMessage);
}

void Heavy_heavy::cCast_bk8Y4rP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8S1vMaoB, HV_BINOP_DIVIDE, 0, m, &cBinop_8S1vMaoB_sendMessage);
}

void Heavy_heavy::cBinop_OwBMmRzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RN7YQEq8, HV_BINOP_DIVIDE, 0, m, &cBinop_RN7YQEq8_sendMessage);
}

void Heavy_heavy::cMsg_GpyJBErZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_H8MT1GN0_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ACDd7Log, HV_BINOP_ADD, 1, m, &cBinop_ACDd7Log_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NI8DT43r, HV_BINOP_ADD, 1, m, &cBinop_NI8DT43r_sendMessage);
}

void Heavy_heavy::cVar_3X9wsLDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwBMmRzq, HV_BINOP_SUBTRACT, 1, m, &cBinop_OwBMmRzq_sendMessage);
}

void Heavy_heavy::cCast_xgYhOM3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_acEGyexl_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_2FygU0je_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xgYhOM3I_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fOLGUiWY, HV_BINOP_MULTIPLY, 0, m, &cBinop_fOLGUiWY_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_8S1vMaoB, HV_BINOP_DIVIDE, 1, m, &cBinop_8S1vMaoB_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ihqcTtpc, 0, m, &cVar_ihqcTtpc_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_AjClmAxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9WLbRN4f_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_aFZozoqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HxVEGPju, 1, m, &cVar_HxVEGPju_sendMessage);
}

void Heavy_heavy::cCast_kDg1LsuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6w5skfQb_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_DseOfTQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q22VdFZj, 0, m, &cVar_q22VdFZj_sendMessage);
}

void Heavy_heavy::cMsg_EUKbg9sR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3xV2kuZE, 0, m, NULL);
  cSwitchcase_t2EZ0s9o_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_3xV2kuZE, 0, m, NULL);
  cSwitchcase_t2EZ0s9o_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_31xAIIDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZPIYDFD, HV_BINOP_ADD, 0, m, &cBinop_MZPIYDFD_sendMessage);
}

void Heavy_heavy::cSwitchcase_cFckvRuu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_J8EH2iiv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_J8EH2iiv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_68J8hXpZ, 1, m, &cDelay_68J8hXpZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H0pDVYax_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_H0pDVYax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_68J8hXpZ, 0, m, &cDelay_68J8hXpZ_sendMessage);
}

void Heavy_heavy::cDelay_68J8hXpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_68J8hXpZ, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eTjRqvVn, 0, m, &cVar_eTjRqvVn_sendMessage);
}

void Heavy_heavy::cMsg_J8EH2iiv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_68J8hXpZ, 0, m, &cDelay_68J8hXpZ_sendMessage);
}

void Heavy_heavy::cCast_YK7Ti2MH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MZPIYDFD, HV_BINOP_ADD, 1, m, &cBinop_MZPIYDFD_sendMessage);
}

void Heavy_heavy::cVar_q22VdFZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eTjRqvVn, 1, m, &cVar_eTjRqvVn_sendMessage);
}

void Heavy_heavy::cVar_eTjRqvVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tvadtIwV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_MZPIYDFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_68J8hXpZ, 1, m, &cDelay_68J8hXpZ_sendMessage);
}

void Heavy_heavy::cVar_qvFGvrjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YK7Ti2MH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_31xAIIDq_sendMessage);
}

void Heavy_heavy::cCast_lfP2s0Xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cFckvRuu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_M0EzhsMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EUKbg9sR_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_pTCDDtZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zaDY0v7c, 0, m, &cVar_zaDY0v7c_sendMessage);
}

void Heavy_heavy::cMsg_tvadtIwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3xV2kuZE, 0, m, NULL);
  cSwitchcase_t2EZ0s9o_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_3xV2kuZE, 0, m, NULL);
  cSwitchcase_t2EZ0s9o_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_NRAu60Mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iZT0cRYM, 0, m, &cIf_iZT0cRYM_sendMessage);
}

void Heavy_heavy::cIf_iZT0cRYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CWGoGk69_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vY2Sy9FV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_vY2Sy9FV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R4ZyN6NI, 0, m, &cVar_R4ZyN6NI_sendMessage);
}

void Heavy_heavy::cVar_R4ZyN6NI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_dww0vzA8_sendMessage);
}

void Heavy_heavy::cBinop_khSE9Xx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iZT0cRYM, 1, m, &cIf_iZT0cRYM_sendMessage);
}

void Heavy_heavy::cCast_ct7xpTQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khSE9Xx0, HV_BINOP_NEQ, 0, m, &cBinop_khSE9Xx0_sendMessage);
}

void Heavy_heavy::cSlice_XnrrifRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_R4ZyN6NI, 0, m, &cVar_R4ZyN6NI_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_R4ZyN6NI, 0, m, &cVar_R4ZyN6NI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_9qdYTh9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_khSE9Xx0, HV_BINOP_NEQ, 1, m, &cBinop_khSE9Xx0_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_R4ZyN6NI, 1, m, &cVar_R4ZyN6NI_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_khSE9Xx0, HV_BINOP_NEQ, 1, m, &cBinop_khSE9Xx0_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_R4ZyN6NI, 1, m, &cVar_R4ZyN6NI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Vp6wR1xl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XnrrifRq, 0, m, &cSlice_XnrrifRq_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9qdYTh9b, 0, m, &cSlice_9qdYTh9b_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ct7xpTQr_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NRAu60Mh_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_CWGoGk69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khSE9Xx0, HV_BINOP_NEQ, 1, m, &cBinop_khSE9Xx0_sendMessage);
}

void Heavy_heavy::hTable_sGgsBn21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_dww0vzA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RKlQqieV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_0SNf8Umc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.01f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYFdIUFG, HV_BINOP_SUBTRACT, 0, m, &cBinop_MYFdIUFG_sendMessage);
}

void Heavy_heavy::cCast_cmDRzGmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0SNf8Umc_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_4X15vG97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_imojacGj, HV_BINOP_MULTIPLY, 1, m, &cBinop_imojacGj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_r5dVXJCc, m);
}

void Heavy_heavy::cMsg_3hIVlwXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fYN1nWO5_sendMessage);
}

void Heavy_heavy::cSystem_zHQxZyvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3hIVlwXw_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_Ui1P8NjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zHQxZyvj_sendMessage);
}

void Heavy_heavy::cBinop_KLTMngSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_44rHBlo8_sendMessage);
}

void Heavy_heavy::cBinop_fYN1nWO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLTMngSX, HV_BINOP_MULTIPLY, 1, m, &cBinop_KLTMngSX_sendMessage);
}

void Heavy_heavy::cVar_opEZO5CK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLTMngSX, HV_BINOP_MULTIPLY, 0, m, &cBinop_KLTMngSX_sendMessage);
}

void Heavy_heavy::cBinop_44rHBlo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_V0bKpCxr_sendMessage);
}

void Heavy_heavy::cBinop_V0bKpCxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8WD1YKOy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XrNNeC8C, m);
}

void Heavy_heavy::cBinop_8WD1YKOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cNjADvJM, m);
}

void Heavy_heavy::cVar_4jojTPdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_imsk0Ib1, 0, m, &cVar_imsk0Ib1_sendMessage);
}

void Heavy_heavy::cVar_NwwW5qDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LcKoiK5a, HV_BINOP_MULTIPLY, 0, m, &cBinop_LcKoiK5a_sendMessage);
}

void Heavy_heavy::cBinop_YCSI9694_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LcKoiK5a, HV_BINOP_MULTIPLY, 1, m, &cBinop_LcKoiK5a_sendMessage);
}

void Heavy_heavy::cMsg_I5rCyHGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YCSI9694_sendMessage);
}

void Heavy_heavy::cBinop_LcKoiK5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jETgvwIG_sendMessage);
}

void Heavy_heavy::cSystem_MwNYkEFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I5rCyHGU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_3zHFyLZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MwNYkEFp_sendMessage);
}

void Heavy_heavy::cBinop_jETgvwIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oH4HntPW_sendMessage);
}

void Heavy_heavy::cBinop_oH4HntPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_emUgWvVY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zAKUWVYb, m);
}

void Heavy_heavy::cBinop_emUgWvVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rMDmH6Qw, m);
}

void Heavy_heavy::cVar_QjfJs5ZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2EPGOavO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cmDRzGmB_sendMessage);
}

void Heavy_heavy::sSample_VHER76mY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_imojacGj, HV_BINOP_MULTIPLY, 0, m, &cBinop_imojacGj_sendMessage);
}

void Heavy_heavy::cVar_imsk0Ib1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_G8kNxlBz, m);
}

void Heavy_heavy::cCast_qtkKw87d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4eAq7skB_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsckdiEb, 0, m, &cDelay_BsckdiEb_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_VHER76mY, 1, m);
}

void Heavy_heavy::cVar_gM6VXER7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dVLPSgdX, HV_BINOP_MULTIPLY, 0, m, &cBinop_dVLPSgdX_sendMessage);
}

void Heavy_heavy::cSwitchcase_GIFlefNC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_4eAq7skB_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_4eAq7skB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qtkKw87d_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_dVLPSgdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_M7rFT0Q3_sendMessage);
}

void Heavy_heavy::cBinop_M7rFT0Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsckdiEb, 2, m, &cDelay_BsckdiEb_sendMessage);
}

void Heavy_heavy::cBinop_A6vbBvPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dVLPSgdX, HV_BINOP_MULTIPLY, 1, m, &cBinop_dVLPSgdX_sendMessage);
}

void Heavy_heavy::cDelay_BsckdiEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BsckdiEb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsckdiEb, 0, m, &cDelay_BsckdiEb_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_VHER76mY, 1, m);
}

void Heavy_heavy::cMsg_4eAq7skB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BsckdiEb, 0, m, &cDelay_BsckdiEb_sendMessage);
}

void Heavy_heavy::cSystem_unku2nmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A6vbBvPr_sendMessage);
}

void Heavy_heavy::cMsg_UiRZ7JOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_unku2nmk_sendMessage);
}

void Heavy_heavy::cCast_2EPGOavO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MYFdIUFG, HV_BINOP_SUBTRACT, 1, m, &cBinop_MYFdIUFG_sendMessage);
}

void Heavy_heavy::cVar_buuEYRMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QjfJs5ZA, 0, m, &cVar_QjfJs5ZA_sendMessage);
}

void Heavy_heavy::cMsg_DC6TO6kJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_GIFlefNC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSlice_30TdiFfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cZSztN9U, 1, m, &cRandom_cZSztN9U_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_8yreEi4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PZ5bOO2R_sendMessage);
}

void Heavy_heavy::cUnop_PZ5bOO2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_El8pqkLz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_Ra831hmh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_30TdiFfn, 0, m, &cSlice_30TdiFfn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cZSztN9U, 0, m, &cRandom_cZSztN9U_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cRandom_cZSztN9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_8yreEi4S_sendMessage);
}

void Heavy_heavy::cMsg_El8pqkLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_GPdGz24s, m);
}

void Heavy_heavy::cBinop_MYFdIUFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_opEZO5CK, 0, m, &cVar_opEZO5CK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NwwW5qDs, 0, m, &cVar_NwwW5qDs_sendMessage);
}

void Heavy_heavy::cVar_rvFzwTAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4X15vG97, 0, m, &cVar_4X15vG97_sendMessage);
}

void Heavy_heavy::cBinop_imojacGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wR3lSHDq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_tmhRUqSq_sendMessage);
}

void Heavy_heavy::cReceive_ujf0qv8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4000.0f, 0, m, &cBinop_OaCp9l7l_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_1y8RuHWc_sendMessage);
}

void Heavy_heavy::cBinop_nwjwBuko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aPeiC1WT, 1, m, &cIf_aPeiC1WT_sendMessage);
}

void Heavy_heavy::cIf_eSVlkyYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oUcbGUV7, HV_BINOP_ADD, 0, m, &cBinop_oUcbGUV7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_aPeiC1WT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_MViG5grF, 0, m, &cIf_MViG5grF_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_q4aLsX71, 0, m, &cIf_q4aLsX71_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_oUcbGUV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MViG5grF, 0, m, &cIf_MViG5grF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_q4aLsX71, 0, m, &cIf_q4aLsX71_sendMessage);
}

void Heavy_heavy::cVar_D39J7QuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BymQts4c, 0, m, &cVar_BymQts4c_sendMessage);
}

void Heavy_heavy::cVar_HsHZ6z9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iSiPlo7U, 0, m, &cVar_iSiPlo7U_sendMessage);
}

void Heavy_heavy::cVar_3hl1gBbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3oudfgcu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OOWhjwjt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_MViG5grF, 1, m, &cIf_MViG5grF_sendMessage);
}

void Heavy_heavy::cBinop_3oudfgcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3hl1gBbw, 1, m, &cVar_3hl1gBbw_sendMessage);
}

void Heavy_heavy::cUnop_GDmMdHK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_azTBjbvW, 0, m, &cVar_azTBjbvW_sendMessage);
}

void Heavy_heavy::cIf_HMdNMjkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_zMbqkQea_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GDmMdHK0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_VdQD9BT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_xD0HCQtf_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HMdNMjkI, 0, m, &cIf_HMdNMjkI_sendMessage);
}

void Heavy_heavy::cUnop_zMbqkQea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_azTBjbvW, 0, m, &cVar_azTBjbvW_sendMessage);
}

void Heavy_heavy::cBinop_xD0HCQtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HMdNMjkI, 1, m, &cIf_HMdNMjkI_sendMessage);
}

void Heavy_heavy::cVar_UWe7uz3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nz5jK9ET, 0, m, &cVar_nz5jK9ET_sendMessage);
}

void Heavy_heavy::cBinop_XdGN5ddq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iKfO2Xxt, 1, m, &cIf_iKfO2Xxt_sendMessage);
}

void Heavy_heavy::cBinop_981TlHCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xHSuPSbf, 0, m, &cIf_xHSuPSbf_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_355qiIpz, 0, m, &cIf_355qiIpz_sendMessage);
}

void Heavy_heavy::cIf_iKfO2Xxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_xHSuPSbf, 0, m, &cIf_xHSuPSbf_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_355qiIpz, 0, m, &cIf_355qiIpz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_va9jBzDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_981TlHCZ, HV_BINOP_ADD, 0, m, &cBinop_981TlHCZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_Y92q5whO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3hl1gBbw, 0, m, &cVar_3hl1gBbw_sendMessage);
}

void Heavy_heavy::cIf_yvCnPkpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_va9jBzDd, 0, m, &cIf_va9jBzDd_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_iKfO2Xxt, 0, m, &cIf_iKfO2Xxt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_XVJa2lXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_va9jBzDd, 0, m, &cIf_va9jBzDd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iKfO2Xxt, 0, m, &cIf_iKfO2Xxt_sendMessage);
}

void Heavy_heavy::cIf_rPYReOQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XVJa2lXO, HV_BINOP_ADD, 0, m, &cBinop_XVJa2lXO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_It6YT5cd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yvCnPkpU, 1, m, &cIf_yvCnPkpU_sendMessage);
}

void Heavy_heavy::cSlice_25Ii3NLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_981TlHCZ, HV_BINOP_ADD, 1, m, &cBinop_981TlHCZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_86g30WIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XVJa2lXO, HV_BINOP_ADD, 1, m, &cBinop_XVJa2lXO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_xlH4AqLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_iSiPlo7U, 0, m, &cVar_iSiPlo7U_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_VTQWvSBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oUcbGUV7, HV_BINOP_ADD, 1, m, &cBinop_oUcbGUV7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_ZrufPV2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NfCdTPvw, HV_BINOP_ADD, 1, m, &cBinop_NfCdTPvw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_wygWYgSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_rLScOCvI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_XdGN5ddq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_va9jBzDd, 1, m, &cIf_va9jBzDd_sendMessage);
}

void Heavy_heavy::cBinop_rLScOCvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wygWYgSD, 1, m, &cVar_wygWYgSD_sendMessage);
}

void Heavy_heavy::cVar_6iWSHoQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xVtVoSce, 0, m, &cVar_xVtVoSce_sendMessage);
}

void Heavy_heavy::cVar_M5uftn2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wygWYgSD, 0, m, &cVar_wygWYgSD_sendMessage);
}

void Heavy_heavy::cBinop_F0Yz9eDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nz5jK9ET, 1, m, &cVar_nz5jK9ET_sendMessage);
}

void Heavy_heavy::cVar_nz5jK9ET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_F0Yz9eDk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nwjwBuko_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eSVlkyYp, 1, m, &cIf_eSVlkyYp_sendMessage);
}

void Heavy_heavy::cBinop_Ym2UHCdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TGCvp5Rv, 0, m, &cVar_TGCvp5Rv_sendMessage);
}

void Heavy_heavy::cIf_q4aLsX71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_TGCvp5Rv, 0, m, &cVar_TGCvp5Rv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_OOWhjwjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_q4aLsX71, 1, m, &cIf_q4aLsX71_sendMessage);
}

void Heavy_heavy::cIf_MViG5grF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ym2UHCdJ, HV_BINOP_ADD, 0, m, &cBinop_Ym2UHCdJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_azTBjbvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ym2UHCdJ, HV_BINOP_ADD, 1, m, &cBinop_Ym2UHCdJ_sendMessage);
}

void Heavy_heavy::cBinop_VSlcEWEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xVtVoSce, 1, m, &cVar_xVtVoSce_sendMessage);
}

void Heavy_heavy::cVar_xVtVoSce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VSlcEWEy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_It6YT5cd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rPYReOQy, 1, m, &cIf_rPYReOQy_sendMessage);
}

void Heavy_heavy::cVar_iSiPlo7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VdQD9BT1, 0, m, &cVar_VdQD9BT1_sendMessage);
}

void Heavy_heavy::cBinop_BhH5hlDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BymQts4c, 1, m, &cVar_BymQts4c_sendMessage);
}

void Heavy_heavy::cVar_BymQts4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BhH5hlDz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_S363MfiH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xHSuPSbf, 1, m, &cIf_xHSuPSbf_sendMessage);
}

void Heavy_heavy::cIf_355qiIpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_eSVlkyYp, 0, m, &cIf_eSVlkyYp_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_aPeiC1WT, 0, m, &cIf_aPeiC1WT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_S363MfiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_355qiIpz, 1, m, &cIf_355qiIpz_sendMessage);
}

void Heavy_heavy::cBinop_NfCdTPvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eSVlkyYp, 0, m, &cIf_eSVlkyYp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aPeiC1WT, 0, m, &cIf_aPeiC1WT_sendMessage);
}

void Heavy_heavy::cIf_xHSuPSbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NfCdTPvw, HV_BINOP_ADD, 0, m, &cBinop_NfCdTPvw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cMsg_ghi9YjAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "seconds");
  cPrint_onMessage(_c, m, "print");
}

void Heavy_heavy::cBinop_vbcUnIBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sbaxe4J1, 0, m, &cVar_Sbaxe4J1_sendMessage);
}

void Heavy_heavy::cReceive_84x3ogyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 512.0f, 0, m, &cBinop_aYqa9k5y_sendMessage);
}

void Heavy_heavy::cCast_gRheW7zv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c0r2K5Gx, 0, m, &cVar_c0r2K5Gx_sendMessage);
}

void Heavy_heavy::cBinop_0RQvNVuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_jBxurwsx_sendMessage);
}

void Heavy_heavy::cVar_lB8ggTGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g0mIscYU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_1y8RuHWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.3f, 0, m, &cBinop_WnCyu5GA_sendMessage);
}

void Heavy_heavy::cSend_M3Y7QFuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_ySmyPMpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_ccUZdd0z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_kYfw89Cj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_iT09yP5R_sendMessage);
}

void Heavy_heavy::cBinop_m8ol3Wok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OYqjWt2c, 0, m, &cIf_OYqjWt2c_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ec5kPkgU, 0, m, &cIf_ec5kPkgU_sendMessage);
}

void Heavy_heavy::cBinop_QUyVbhJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PeytvIhF, 1, m, &cVar_PeytvIhF_sendMessage);
}

void Heavy_heavy::cVar_PeytvIhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QUyVbhJe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_k4T9z5aw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_t8TNuuZX, 1, m, &cIf_t8TNuuZX_sendMessage);
}

void Heavy_heavy::cBinop_hJvW4tuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NHTNOEce, 1, m, &cIf_NHTNOEce_sendMessage);
}

void Heavy_heavy::cIf_NHTNOEce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_KTnAHiu9, 0, m, &cIf_KTnAHiu9_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8OWMivPX, 0, m, &cIf_8OWMivPX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_oejbrcGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KTnAHiu9, 0, m, &cIf_KTnAHiu9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8OWMivPX, 0, m, &cIf_8OWMivPX_sendMessage);
}

void Heavy_heavy::cIf_PyBbhEHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oejbrcGZ, HV_BINOP_ADD, 0, m, &cBinop_oejbrcGZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_d9y8Ksr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XJvGF9xq, 1, m, &cVar_XJvGF9xq_sendMessage);
}

void Heavy_heavy::cVar_XJvGF9xq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_d9y8Ksr0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_FD1whIaQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KTnAHiu9, 1, m, &cIf_KTnAHiu9_sendMessage);
}

void Heavy_heavy::cIf_t8TNuuZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_sQ0VmOLe, HV_BINOP_ADD, 0, m, &cBinop_sQ0VmOLe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_k4T9z5aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xJWwcJLL, 1, m, &cIf_xJWwcJLL_sendMessage);
}

void Heavy_heavy::cBinop_sQ0VmOLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2CHmAZbk, 0, m, &cVar_2CHmAZbk_sendMessage);
}

void Heavy_heavy::cIf_xJWwcJLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_2CHmAZbk, 0, m, &cVar_2CHmAZbk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_4d3eRchx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_sydmQFwq, 0, m, &cVar_sydmQFwq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_42TvLVMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MmnmQ2bD, HV_BINOP_ADD, 1, m, &cBinop_MmnmQ2bD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_v3Km82sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eAnwFIzP, HV_BINOP_ADD, 1, m, &cBinop_eAnwFIzP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_3lfEw6Lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_oejbrcGZ, HV_BINOP_ADD, 1, m, &cBinop_oejbrcGZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_KAxym3ZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cQxprVnN, HV_BINOP_ADD, 1, m, &cBinop_cQxprVnN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_AIRXCTeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_KvjuexSJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_SvZTZrb1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_XhExc0Ya, 1, m, &cIf_XhExc0Ya_sendMessage);
}

void Heavy_heavy::cBinop_KvjuexSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AIRXCTeO, 1, m, &cVar_AIRXCTeO_sendMessage);
}

void Heavy_heavy::cBinop_eAnwFIzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XhExc0Ya, 0, m, &cIf_XhExc0Ya_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9m97yfRz, 0, m, &cIf_9m97yfRz_sendMessage);
}

void Heavy_heavy::cIf_OYqjWt2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eAnwFIzP, HV_BINOP_ADD, 0, m, &cBinop_eAnwFIzP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_ec5kPkgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_XhExc0Ya, 0, m, &cIf_XhExc0Ya_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_9m97yfRz, 0, m, &cIf_9m97yfRz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_N4XDFtR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ec5kPkgU, 1, m, &cIf_ec5kPkgU_sendMessage);
}

void Heavy_heavy::cVar_sydmQFwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lH4bDjFI, 0, m, &cVar_lH4bDjFI_sendMessage);
}

void Heavy_heavy::cBinop_Q8uscotR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kxDffcU5, 1, m, &cVar_kxDffcU5_sendMessage);
}

void Heavy_heavy::cVar_kxDffcU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Q8uscotR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_N4XDFtR7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_OYqjWt2c, 1, m, &cIf_OYqjWt2c_sendMessage);
}

void Heavy_heavy::cVar_vcZs95Hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XJvGF9xq, 0, m, &cVar_XJvGF9xq_sendMessage);
}

void Heavy_heavy::cVar_qtFChMkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eZ4IRKZI, 0, m, &cVar_eZ4IRKZI_sendMessage);
}

void Heavy_heavy::cVar_qM8aqwdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PeytvIhF, 0, m, &cVar_PeytvIhF_sendMessage);
}

void Heavy_heavy::cIf_KTnAHiu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_MmnmQ2bD, HV_BINOP_ADD, 0, m, &cBinop_MmnmQ2bD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_8OWMivPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_t8TNuuZX, 0, m, &cIf_t8TNuuZX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_xJWwcJLL, 0, m, &cIf_xJWwcJLL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_MmnmQ2bD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t8TNuuZX, 0, m, &cIf_t8TNuuZX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xJWwcJLL, 0, m, &cIf_xJWwcJLL_sendMessage);
}

void Heavy_heavy::cBinop_FD1whIaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8OWMivPX, 1, m, &cIf_8OWMivPX_sendMessage);
}

void Heavy_heavy::cVar_eZ4IRKZI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oFuUPdxT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hJvW4tuh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PyBbhEHa, 1, m, &cIf_PyBbhEHa_sendMessage);
}

void Heavy_heavy::cBinop_oFuUPdxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eZ4IRKZI, 1, m, &cVar_eZ4IRKZI_sendMessage);
}

void Heavy_heavy::cVar_XBXx5Z3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sydmQFwq, 0, m, &cVar_sydmQFwq_sendMessage);
}

void Heavy_heavy::cVar_xMR2hgCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AIRXCTeO, 0, m, &cVar_AIRXCTeO_sendMessage);
}

void Heavy_heavy::cBinop_cQxprVnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PyBbhEHa, 0, m, &cIf_PyBbhEHa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NHTNOEce, 0, m, &cIf_NHTNOEce_sendMessage);
}

void Heavy_heavy::cBinop_SvZTZrb1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9m97yfRz, 1, m, &cIf_9m97yfRz_sendMessage);
}

void Heavy_heavy::cIf_XhExc0Ya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cQxprVnN, HV_BINOP_ADD, 0, m, &cBinop_cQxprVnN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_9m97yfRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_PyBbhEHa, 0, m, &cIf_PyBbhEHa_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NHTNOEce, 0, m, &cIf_NHTNOEce_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_MbgkdBWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kxDffcU5, 0, m, &cVar_kxDffcU5_sendMessage);
}

void Heavy_heavy::cVar_pkJmAMPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sQ0VmOLe, HV_BINOP_ADD, 1, m, &cBinop_sQ0VmOLe_sendMessage);
}

void Heavy_heavy::cUnop_Mn55aQjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pkJmAMPq, 0, m, &cVar_pkJmAMPq_sendMessage);
}

void Heavy_heavy::cBinop_je8jk0xL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pgKblwcZ, 1, m, &cIf_pgKblwcZ_sendMessage);
}

void Heavy_heavy::cVar_lH4bDjFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_je8jk0xL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pgKblwcZ, 0, m, &cIf_pgKblwcZ_sendMessage);
}

void Heavy_heavy::cUnop_RB64mOmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pkJmAMPq, 0, m, &cVar_pkJmAMPq_sendMessage);
}

void Heavy_heavy::cIf_pgKblwcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_RB64mOmK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Mn55aQjw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_jZ2C6GJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.01f, 0, m, &cBinop_gmjcMlfI_sendMessage);
}

void Heavy_heavy::cMsg_eTmb32ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_fLFDWUuR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_GHvf1tRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eTmb32ps_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_LSBEDv1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B91rgiiw, HV_BINOP_MIN, 1, m, &cBinop_B91rgiiw_sendMessage);
}

void Heavy_heavy::cSwitchcase_fLFDWUuR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_E2UdgdVk, 0, m, &cSlice_E2UdgdVk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xJcJivAY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5nWuBbfA_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_E2UdgdVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_bcuFDFqd, 1, m, &cTabread_bcuFDFqd_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_bcuFDFqd, 1, m, &cTabread_bcuFDFqd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_B91rgiiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_bcuFDFqd, 0, m, &cTabread_bcuFDFqd_sendMessage);
}

void Heavy_heavy::cCast_5nWuBbfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_twABUz4c_sendMessage);
}

void Heavy_heavy::cVar_wEho1RZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KuCNJLor_sendMessage(_c, 0, m);
}

void Heavy_heavy::cTabread_bcuFDFqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0AiXunH, HV_BINOP_ADD, 0, m, &cBinop_F0AiXunH_sendMessage);
}

void Heavy_heavy::cMsg_KuCNJLor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TEVyz1eD_sendMessage);
}

void Heavy_heavy::cCast_xJcJivAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wEho1RZn, 0, m, &cVar_wEho1RZn_sendMessage);
}

void Heavy_heavy::cBinop_twABUz4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B91rgiiw, HV_BINOP_MIN, 0, m, &cBinop_B91rgiiw_sendMessage);
}

void Heavy_heavy::cSystem_TEVyz1eD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LSBEDv1D_sendMessage);
}

void Heavy_heavy::cVar_pqLeCSJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fLFDWUuR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_QliHqtcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BPPHcuim, 0, m, &cVar_BPPHcuim_sendMessage);
}

void Heavy_heavy::cMsg_kENSvg6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_fLFDWUuR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_3R1jcqAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kENSvg6S_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_F0AiXunH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_gWJeJ7Hh_sendMessage);
}

void Heavy_heavy::cVar_BPPHcuim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0AiXunH, HV_BINOP_ADD, 1, m, &cBinop_F0AiXunH_sendMessage);
}

void Heavy_heavy::cSend_S0AdbwZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_ySmyPMpz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_aYqa9k5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DcDRLxXt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_mDCcv5IA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y24E8y7j, 0, m, &cVar_Y24E8y7j_sendMessage);
}

void Heavy_heavy::cBinop_ccUZdd0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DGEM3Efi, 0, m, &cVar_DGEM3Efi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XAaADjv8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvSO5PWX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3YIqcfsH_sendMessage);
}

void Heavy_heavy::cIf_VvRyMq9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1mRjjAge_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J29dzPEx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_1mRjjAge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mx5gfwC5, HV_BINOP_NEQ, 1, m, &cBinop_mx5gfwC5_sendMessage);
}

void Heavy_heavy::cVar_Kxvd3ldJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_afE9LxYu_sendMessage);
}

void Heavy_heavy::cBinop_mx5gfwC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VvRyMq9R, 1, m, &cIf_VvRyMq9R_sendMessage);
}

void Heavy_heavy::cCast_FjO94T2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VvRyMq9R, 0, m, &cIf_VvRyMq9R_sendMessage);
}

void Heavy_heavy::cCast_nlJf7EKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mx5gfwC5, HV_BINOP_NEQ, 0, m, &cBinop_mx5gfwC5_sendMessage);
}

void Heavy_heavy::cSlice_26gwY9Gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mx5gfwC5, HV_BINOP_NEQ, 1, m, &cBinop_mx5gfwC5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Kxvd3ldJ, 1, m, &cVar_Kxvd3ldJ_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_mx5gfwC5, HV_BINOP_NEQ, 1, m, &cBinop_mx5gfwC5_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Kxvd3ldJ, 1, m, &cVar_Kxvd3ldJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_eMrkpNim_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CaVCJvnA, 0, m, &cSlice_CaVCJvnA_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_26gwY9Gk, 0, m, &cSlice_26gwY9Gk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nlJf7EKn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FjO94T2b_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_CaVCJvnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_Kxvd3ldJ, 0, m, &cVar_Kxvd3ldJ_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Kxvd3ldJ, 0, m, &cVar_Kxvd3ldJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_J29dzPEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Kxvd3ldJ, 0, m, &cVar_Kxvd3ldJ_sendMessage);
}

void Heavy_heavy::cReceive_k9n6s6eJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_jRwLbmS0_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_Sbaxe4J1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iQPc4YLy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_riOZX07m, 0, m, &cIf_riOZX07m_sendMessage);
}

void Heavy_heavy::cUnop_rFePN74X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eMrkpNim_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_iQPc4YLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_riOZX07m, 1, m, &cIf_riOZX07m_sendMessage);
}

void Heavy_heavy::cUnop_DrLPV38N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eMrkpNim_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_riOZX07m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rFePN74X_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DrLPV38N_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cReceive_WVMlJlXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_M3Y7QFuZ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_3YIqcfsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SpBA86xz, 0, m, &cVar_SpBA86xz_sendMessage);
}

void Heavy_heavy::cBinop_OTTp6YTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZkeyVBFM, 0, m, &cVar_ZkeyVBFM_sendMessage);
}

void Heavy_heavy::cBinop_tmhRUqSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 3.0f, 0, m, &cBinop_mDCcv5IA_sendMessage);
}

void Heavy_heavy::hTable_AH3vIPk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_qqVOrR1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NTVuliB5, 1, m, &cIf_NTVuliB5_sendMessage);
}

void Heavy_heavy::cSlice_3EyQ5oMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_KqgnZ8gz, 0, m, &cVar_KqgnZ8gz_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_KqgnZ8gz, 0, m, &cVar_KqgnZ8gz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_DcDRLxXt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3EyQ5oMB, 0, m, &cSlice_3EyQ5oMB_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Lgbm4VEW, 0, m, &cSlice_Lgbm4VEW_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Cutdui2b_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SvziOAYj_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_Lgbm4VEW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qqVOrR1L, HV_BINOP_NEQ, 1, m, &cBinop_qqVOrR1L_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_KqgnZ8gz, 1, m, &cVar_KqgnZ8gz_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_qqVOrR1L, HV_BINOP_NEQ, 1, m, &cBinop_qqVOrR1L_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_KqgnZ8gz, 1, m, &cVar_KqgnZ8gz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_NTVuliB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DgE7i5Rk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aa5yV2us_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_DgE7i5Rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qqVOrR1L, HV_BINOP_NEQ, 1, m, &cBinop_qqVOrR1L_sendMessage);
}

void Heavy_heavy::cVar_KqgnZ8gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g0mIscYU_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_aa5yV2us_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KqgnZ8gz, 0, m, &cVar_KqgnZ8gz_sendMessage);
}

void Heavy_heavy::cCast_Cutdui2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qqVOrR1L, HV_BINOP_NEQ, 0, m, &cBinop_qqVOrR1L_sendMessage);
}

void Heavy_heavy::cCast_SvziOAYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NTVuliB5, 0, m, &cIf_NTVuliB5_sendMessage);
}

void Heavy_heavy::cBinop_wR3lSHDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_7o7U75IG_sendMessage);
}

void Heavy_heavy::cCast_XAaADjv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c0r2K5Gx, 1, m, &cVar_c0r2K5Gx_sendMessage);
}

void Heavy_heavy::cBinop_jBxurwsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sydmQFwq, 0, m, &cVar_sydmQFwq_sendMessage);
}

void Heavy_heavy::cVar_kmZkNDQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KhfSuUug_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_EqXf8Pfj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PsBhoG5h, HV_BINOP_SUBTRACT, 1, m, &cBinop_PsBhoG5h_sendMessage);
}

void Heavy_heavy::cBinop_gmjcMlfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gRheW7zv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xE1FjEX2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JBPkpui1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_kXy15UXd_sendMessage);
}

void Heavy_heavy::cBinop_5WgVOSr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yKQCVfDr, 1, m, &cVar_yKQCVfDr_sendMessage);
}

void Heavy_heavy::cVar_yKQCVfDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_5WgVOSr0_sendMessage);
  cSwitchcase_wzyYgJY4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_QJHimzPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qlgZh1yb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9p2xBoor_sendMessage);
}

void Heavy_heavy::cBinop_BZ4zBHey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::sSample_Zre1DATn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qzkLI8J6_sendMessage);
}

void Heavy_heavy::cMsg_LXJeBZRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uTmWubLf_sendMessage);
}

void Heavy_heavy::cSystem_uTmWubLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eDU2nAv9_sendMessage);
}

void Heavy_heavy::cBinop_eDU2nAv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1msREMbo, HV_BINOP_MULTIPLY, 1, m, &cBinop_1msREMbo_sendMessage);
}

void Heavy_heavy::cCast_MtI8JBzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d9DAPNQp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXwUSC2D, 0, m, &cDelay_NXwUSC2D_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_Zre1DATn, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_uy6OU6hg, 1, m);
}

void Heavy_heavy::cMsg_d9DAPNQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXwUSC2D, 0, m, &cDelay_NXwUSC2D_sendMessage);
}

void Heavy_heavy::cBinop_1msREMbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_fKBPJ6ZK_sendMessage);
}

void Heavy_heavy::cDelay_NXwUSC2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NXwUSC2D, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXwUSC2D, 0, m, &cDelay_NXwUSC2D_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_Zre1DATn, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_uy6OU6hg, 1, m);
}

void Heavy_heavy::cBinop_fKBPJ6ZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NXwUSC2D, 2, m, &cDelay_NXwUSC2D_sendMessage);
}

void Heavy_heavy::cVar_RBD49CQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1msREMbo, HV_BINOP_MULTIPLY, 0, m, &cBinop_1msREMbo_sendMessage);
}

void Heavy_heavy::cSwitchcase_DJJgtCWx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_d9DAPNQp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_d9DAPNQp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MtI8JBzY_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_qlgZh1yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1fRBJGat, HV_BINOP_DIVIDE, 1, m, &cBinop_1fRBJGat_sendMessage);
}

void Heavy_heavy::cCast_srCqh7Wi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o13yxY9J, 0, m, &cVar_o13yxY9J_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CEQjFqUN, 0, m, &cVar_CEQjFqUN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NMu7IGPR, 0, m, &cVar_NMu7IGPR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jfJa4sr4, 0, m, &cVar_jfJa4sr4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JvOT4p1N, 0, m, &cVar_JvOT4p1N_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lYh7GIHg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lfP2s0Xv_sendMessage);
}

void Heavy_heavy::cBinop_d4oYcTYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NbcYV9nZ, 1, m, &cVar_NbcYV9nZ_sendMessage);
}

void Heavy_heavy::cVar_NbcYV9nZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_d4oYcTYy_sendMessage);
  cSwitchcase_DJJgtCWx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cDelay_TwJXvv6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TwJXvv6f, m);
  cVar_onMessage(_c, &Context(_c)->cVar_O8JdUxyv, 0, m, &cVar_O8JdUxyv_sendMessage);
}

void Heavy_heavy::cMsg_CYRm2nlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_TwJXvv6f, 0, m, &cDelay_TwJXvv6f_sendMessage);
}

void Heavy_heavy::cCast_FsbKkkwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TwJXvv6f, 0, m, &cDelay_TwJXvv6f_sendMessage);
}

void Heavy_heavy::cSwitchcase_WeWWCZ8S_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CYRm2nlz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CYRm2nlz_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_TwJXvv6f, 1, m, &cDelay_TwJXvv6f_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FsbKkkwD_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_UU6kKvV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_BZ4zBHey_sendMessage);
}

void Heavy_heavy::cVar_EuWV65fU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QJHimzPl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aBN52BX8, 0, m, &cVar_aBN52BX8_sendMessage);
  cSwitchcase_WeWWCZ8S_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_O8JdUxyv, 1, m, &cVar_O8JdUxyv_sendMessage);
}

void Heavy_heavy::cSystem_rLZa0elX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LaqqqlLU_sendMessage);
}

void Heavy_heavy::cMsg_sJfEomRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rLZa0elX_sendMessage);
}

void Heavy_heavy::cBinop_EMZcd0J0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_sLWFeyoP_sendMessage);
}

void Heavy_heavy::cCast_GGqsJmfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XFUGE2nP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DnPEJdE1, 0, m, &cDelay_DnPEJdE1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_srCqh7Wi_sendMessage);
}

void Heavy_heavy::cBinop_sLWFeyoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DnPEJdE1, 2, m, &cDelay_DnPEJdE1_sendMessage);
}

void Heavy_heavy::cDelay_DnPEJdE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DnPEJdE1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DnPEJdE1, 0, m, &cDelay_DnPEJdE1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_srCqh7Wi_sendMessage);
}

void Heavy_heavy::cSwitchcase_wzyYgJY4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_XFUGE2nP_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_XFUGE2nP_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GGqsJmfi_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_aBN52BX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EMZcd0J0, HV_BINOP_MULTIPLY, 0, m, &cBinop_EMZcd0J0_sendMessage);
}

void Heavy_heavy::cMsg_XFUGE2nP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DnPEJdE1, 0, m, &cDelay_DnPEJdE1_sendMessage);
}

void Heavy_heavy::cBinop_LaqqqlLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EMZcd0J0, HV_BINOP_MULTIPLY, 1, m, &cBinop_EMZcd0J0_sendMessage);
}

void Heavy_heavy::cBinop_1fRBJGat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_VrA76h68, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_qRx78syy, 0, m);
}

void Heavy_heavy::sSample_uy6OU6hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UU6kKvV4_sendMessage);
}

void Heavy_heavy::cBinop_IMHUdkuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_0RQvNVuO_sendMessage);
}

void Heavy_heavy::cMsg_Jr4goePu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1fRBJGat, HV_BINOP_DIVIDE, 0, m, &cBinop_1fRBJGat_sendMessage);
}

void Heavy_heavy::cBinop_MITW36Vv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BigoEGkn, 1, m, &cIf_BigoEGkn_sendMessage);
}

void Heavy_heavy::cIf_BigoEGkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_vaABQ8LL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_l79Dx7rZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_l79Dx7rZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cUnop_vaABQ8LL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_O8JdUxyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MITW36Vv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_BigoEGkn, 0, m, &cIf_BigoEGkn_sendMessage);
}

void Heavy_heavy::cVar_F4UNMXcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EuWV65fU, 0, m, &cVar_EuWV65fU_sendMessage);
}

void Heavy_heavy::cCast_9p2xBoor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jr4goePu_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_qzkLI8J6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_IMHUdkuX_sendMessage);
}

void Heavy_heavy::cReceive_o4XobnaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mmSjc85j_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_7o7U75IG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_hr0xFJKs_sendMessage);
}

void Heavy_heavy::cVar_1Yb3t2Wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KhfSuUug_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_pmiG6XHT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_vbcUnIBy_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_VrA76h68, VOf(Bf0));
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
    __hv_sample_f(this, &sSample_uy6OU6hg, VIf(Bf1), &sSample_uy6OU6hg_sendMessage);
    __hv_phasor_k_f(&sPhasor_qRx78syy, VOf(Bf1));
    __hv_sample_f(this, &sSample_Zre1DATn, VIf(Bf1), &sSample_Zre1DATn_sendMessage);
    __hv_varread_i(&sVari_GPdGz24s, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_GPdGz24s, VIi(Bi1));
    __hv_varread_f(&sVarf_zAKUWVYb, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rMDmH6Qw, VOf(Bf0));
    __hv_rpole_f(&sRPole_n4VKpJ9i, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_r5dVXJCc, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_G8kNxlBz, VOf(Bf0));
    __hv_phasor_f(&sPhasor_CmHxlib0, VIf(Bf0), VOf(Bf0));
    __hv_del1_f(&sDel1_O6L1h1m4, VIf(Bf0), VOf(Bf4));
    __hv_lt_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_hh1WZx6Y, VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_XrNNeC8C, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_cNjADvJM, VOf(Bf4));
    __hv_rpole_f(&sRPole_rtvdm7AS, VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_sample_f(this, &sSample_VHER76mY, VIf(Bf4), &sSample_VHER76mY_sendMessage);
    __hv_line_f(&sLine_w7DH4OJg, VOf(Bf1));
    __hv_phasor_f(&sPhasor_flABCkST, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_TBVKf7tP, VOf(Bf0));
    __hv_phasor_f(&sPhasor_IExBzSLg, VIf(Bf0), VOf(Bf0));
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
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_yxsgbgza, VOf(Bf3));
    __hv_phasor_f(&sPhasor_acZ2UnXZ, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_3xV2kuZE, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_aglQGJpw, VOf(Bf1));
    __hv_tabhead_f(&sTabhead_14u59m8b, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_46F2R3tq, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_g1fw48zg, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_varread_f(&sVarf_r8FwoLGq, VOf(Bf2));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_GpvA3OjB, VIi(Bi0), VOf(Bf0));
    __hv_tabread_if(&sTabread_qEKoj9lc, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_IXqZzo14, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_HRyUCTZ9, VOf(Bf2));
    __hv_rpole_f(&sRPole_z3zPp50j, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Zhz3bCq3, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_LDckccXt, VIf(Bf3));
    __hv_tabhead_f(&sTabhead_91cKd0vl, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_qEpQ6i7O, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_nVLkQmwY, VOf(Bf1));
    __hv_min_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf0));
    __hv_varread_f(&sVarf_1uQSHNZC, VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_y468XpXM, VIi(Bi0), VOf(Bf5));
    __hv_tabread_if(&sTabread_NLVtnFjn, VIi(Bi1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_jbTsaDaB, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_GEaHrfin, VOf(Bf1));
    __hv_rpole_f(&sRPole_L9aDDTP3, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_1Iwp1KiL, VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf4), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_JakmLppA, VIf(Bf0));
    __hv_varread_f(&sVarf_Sjpq67JT, VOf(Bf0));
    __hv_varread_f(&sVarf_B0T2IhGf, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf4), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_kgZb2NAc, VOf(Bf0));
    __hv_varread_f(&sVarf_QZ5F20mC, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_f1aBRPmz, VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf1), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O2), VOf(O2));

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
