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

float hTable_JTeuf71H_data[128] = {0.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 5.0f, 7.0f, 9.0f, 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 15.0f, 15.0f, 17.0f, 17.0f, 19.0f, 21.0f, 22.0f, 22.0f, 24.0f, 26.0f, 26.0f, 27.0f, 27.0f, 29.0f, 29.0f, 31.0f, 33.0f, 34.0f, 34.0f, 36.0f, 38.0f, 38.0f, 39.0f, 39.0f, 41.0f, 41.0f, 43.0f, 45.0f, 46.0f, 46.0f, 48.0f, 50.0f, 50.0f, 51.0f, 51.0f, 53.0f, 53.0f, 55.0f, 57.0f, 58.0f, 58.0f, 60.0f, 62.0f, 62.0f, 63.0f, 63.0f, 65.0f, 65.0f, 67.0f, 69.0f, 70.0f, 70.0f, 72.0f, 74.0f, 74.0f, 75.0f, 75.0f, 77.0f, 77.0f, 79.0f, 81.0f, 82.0f, 82.0f, 84.0f, 86.0f, 86.0f, 87.0f, 87.0f, 89.0f, 89.0f, 91.0f, 93.0f, 94.0f, 94.0f, 96.0f, 98.0f, 98.0f, 99.0f, 99.0f, 101.0f, 101.0f, 103.0f, 105.0f, 106.0f, 106.0f, 108.0f, 110.0f, 110.0f, 111.0f, 111.0f, 113.0f, 113.0f, 115.0f, 117.0f, 118.0f, 118.0f, 120.0f, 122.0f, 122.0f, 123.0f, 123.0f, 125.0f, 125.0f, 127.0f, 129.0f, 130.0f, 130.0f, 132.0f, 134.0f, 134.0f, 135.0f, 135.0f, 137.0f, 0.0f};
float hTable_U0QkO85v_data[128] = {0.0f, 2.0f, 2.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f, 11.0f, 11.0f, 12.0f, 14.0f, 14.0f, 16.0f, 16.0f, 17.0f, 17.0f, 19.0f, 21.0f, 23.0f, 23.0f, 24.0f, 26.0f, 26.0f, 28.0f, 28.0f, 29.0f, 29.0f, 31.0f, 33.0f, 35.0f, 35.0f, 36.0f, 38.0f, 38.0f, 40.0f, 40.0f, 41.0f, 41.0f, 43.0f, 45.0f, 47.0f, 47.0f, 48.0f, 50.0f, 50.0f, 52.0f, 52.0f, 53.0f, 53.0f, 55.0f, 57.0f, 59.0f, 59.0f, 60.0f, 62.0f, 62.0f, 64.0f, 64.0f, 65.0f, 65.0f, 67.0f, 69.0f, 71.0f, 71.0f, 72.0f, 74.0f, 74.0f, 76.0f, 76.0f, 77.0f, 77.0f, 79.0f, 81.0f, 83.0f, 83.0f, 84.0f, 86.0f, 86.0f, 88.0f, 88.0f, 89.0f, 89.0f, 91.0f, 93.0f, 95.0f, 95.0f, 96.0f, 98.0f, 98.0f, 100.0f, 100.0f, 101.0f, 101.0f, 103.0f, 105.0f, 107.0f, 107.0f, 108.0f, 110.0f, 110.0f, 112.0f, 112.0f, 113.0f, 113.0f, 115.0f, 117.0f, 119.0f, 119.0f, 120.0f, 122.0f, 122.0f, 124.0f, 124.0f, 125.0f, 125.0f, 127.0f, 129.0f, 131.0f, 131.0f, 132.0f, 134.0f, 134.0f, 136.0f, 136.0f, 137.0f, 0.0f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_wSSGD0Xd, 440.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_9f9VaZZz, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_edTKF4fo);
  numBytes += sPhasor_k_init(&sPhasor_2GqOF3Jf, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_qAl5spUM);
  numBytes += sRPole_init(&sRPole_yOTRCNyJ);
  numBytes += sPhasor_init(&sPhasor_rU4Cm8dJ, sampleRate);
  numBytes += sDel1_init(&sDel1_4TbZzwrI);
  numBytes += sSamphold_init(&sSamphold_4mOmGPho);
  numBytes += sRPole_init(&sRPole_K6zEJEjT);
  numBytes += sSample_init(&sSample_PDIAlkr7);
  numBytes += sLine_init(&sLine_BMXeaKXg);
  numBytes += sPhasor_init(&sPhasor_jSH94YTy, sampleRate);
  numBytes += sLine_init(&sLine_0hXKgL4Z);
  numBytes += sPhasor_init(&sPhasor_zIumMJN0, sampleRate);
  numBytes += sLine_init(&sLine_AT1wwnAQ);
  numBytes += sPhasor_init(&sPhasor_CQ8I2XVO, sampleRate);
  numBytes += sLine_init(&sLine_guMEvnBQ);
  numBytes += sLine_init(&sLine_65KpTKWm);
  numBytes += sTabhead_init(&sTabhead_tOV26FHG, &hTable_VwH15dD9);
  numBytes += sTabread_init(&sTabread_LMYQWsCA, &hTable_VwH15dD9, false);
  numBytes += sTabread_init(&sTabread_C9EutCgU, &hTable_VwH15dD9, false);
  numBytes += sRPole_init(&sRPole_nwRDX9SF);
  numBytes += sTabwrite_init(&sTabwrite_qW5cWS0w, &hTable_eObqPdzC);
  numBytes += sTabhead_init(&sTabhead_jxL5XbmA, &hTable_eObqPdzC);
  numBytes += sTabread_init(&sTabread_neMovKfS, &hTable_eObqPdzC, false);
  numBytes += sTabread_init(&sTabread_cMO9O1SX, &hTable_eObqPdzC, false);
  numBytes += sRPole_init(&sRPole_UJrbnYAz);
  numBytes += sTabwrite_init(&sTabwrite_xGINu7jN, &hTable_VwH15dD9);
  numBytes += cBinop_init(&cBinop_1o0STWZy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JSZiNAJR, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_6Jc3MUjM, 0.0f);
  numBytes += cIf_init(&cIf_Q64BpXvc, false);
  numBytes += cVar_init_f(&cVar_d0VicD0r, 0.0f);
  numBytes += cBinop_init(&cBinop_Yg6xq2Tz, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_lOoaVJYB, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_m9X9i1sU, 1.0f);
  numBytes += cVar_init_f(&cVar_5v5nRLK3, 0.0f);
  numBytes += cVar_init_f(&cVar_marjzifb, 0.0f);
  numBytes += cIf_init(&cIf_RqBbVgUr, false);
  numBytes += cIf_init(&cIf_C6p1AIlk, false);
  numBytes += cVar_init_f(&cVar_LqJ2BonC, 0.0f);
  numBytes += cVar_init_f(&cVar_3iuT6lVK, 0.0f);
  numBytes += cVar_init_f(&cVar_Y1aqJ4vd, 0.0f);
  numBytes += cVar_init_f(&cVar_zcxHUTlX, 5.0f);
  numBytes += cVar_init_f(&cVar_41CRETRr, 11.0f);
  numBytes += cVar_init_f(&cVar_147W3d3i, 0.0f);
  numBytes += cBinop_init(&cBinop_2hkYxXN6, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_qwUNhD6J, "minor_scale");
  numBytes += cTabread_init(&cTabread_e9sMYgay, &hTable_JTeuf71H); // minor_scale
  numBytes += cSlice_init(&cSlice_iaYCQ2bX, 1, -1);
  numBytes += cVar_init_f(&cVar_kxDzgTlV, 0.0f);
  numBytes += cVar_init_f(&cVar_Kg9Gdn7V, 0.0f);
  numBytes += cBinop_init(&cBinop_lHpsjCdo, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_bRLczDQ7, 0.0f);
  numBytes += cBinop_init(&cBinop_3ac9ajSm, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_YhF1nOA1, 0.0f);
  numBytes += cVar_init_f(&cVar_daZMHWLS, 0.0f);
  numBytes += cIf_init(&cIf_b3JUokXZ, false);
  numBytes += cBinop_init(&cBinop_Oo4gQ6wp, 0.0f); // __add
  numBytes += cIf_init(&cIf_aVDXoAlM, true);
  numBytes += cVar_init_f(&cVar_9YHBWDCD, 1.0f);
  numBytes += cSlice_init(&cSlice_HXz4RGLw, 1, 1);
  numBytes += cSlice_init(&cSlice_wnewENWH, 2, 1);
  numBytes += cSlice_init(&cSlice_F69fFKnY, 0, 1);
  numBytes += cSlice_init(&cSlice_I02O1hHh, 3, 1);
  numBytes += cSlice_init(&cSlice_CBW2BTzJ, 4, 1);
  numBytes += cVar_init_f(&cVar_xikT9ab4, 0.0f);
  numBytes += cBinop_init(&cBinop_g902mLOE, 16.0f); // __add
  numBytes += cIf_init(&cIf_eUhfYHmy, false);
  numBytes += cIf_init(&cIf_BS59nN2D, true);
  numBytes += cIf_init(&cIf_Jq5cN1Y6, false);
  numBytes += cBinop_init(&cBinop_WTw4DWp7, 2.0f); // __add
  numBytes += cIf_init(&cIf_bWAIOZQq, true);
  numBytes += cVar_init_f(&cVar_wyBEdDR5, 1.0f);
  numBytes += cVar_init_f(&cVar_6HLZskXs, 0.0f);
  numBytes += cVar_init_f(&cVar_UXuF5sah, 1.0f);
  numBytes += cVar_init_f(&cVar_V3UfwP9s, 0.0f);
  numBytes += cVar_init_f(&cVar_CJAsAVnx, 1.0f);
  numBytes += cVar_init_f(&cVar_T492mjB5, 0.0f);
  numBytes += cVar_init_f(&cVar_yeHBLlxW, 1.0f);
  numBytes += cVar_init_f(&cVar_FVhjcby5, 0.0f);
  numBytes += cVar_init_f(&cVar_GxGIW44R, 0.0f);
  numBytes += cIf_init(&cIf_XjbhgmBu, false);
  numBytes += cBinop_init(&cBinop_9aUcFtqx, 8.0f); // __add
  numBytes += cIf_init(&cIf_de0Y7saR, true);
  numBytes += cIf_init(&cIf_uyeXwhCO, false);
  numBytes += cIf_init(&cIf_b6xRkZwf, true);
  numBytes += cBinop_init(&cBinop_hkbS7EFp, -1.0f); // __add
  numBytes += cIf_init(&cIf_2FtGfMow, false);
  numBytes += cVar_init_f(&cVar_ECW9JI1V, 0.0f);
  numBytes += cPack_init(&cPack_cP8Eqdc8, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_aefk6a2h, 0.0f);
  numBytes += cBinop_init(&cBinop_tShivUZP, 1.0f); // __pow
  numBytes += cPack_init(&cPack_1OdInJXY, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_mClqTT1T, 1.0f); // __pow
  numBytes += cPack_init(&cPack_E10BehLN, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_y0eb8GVo, 2.0f);
  numBytes += cBinop_init(&cBinop_b6NJ9E7T, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_C2R1Dc6X, 0.0f);
  numBytes += cBinop_init(&cBinop_ebVjeECs, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_LAP8CRLN, 1, -1);
  numBytes += cSlice_init(&cSlice_UsmDKpPL, 1, -1);
  numBytes += cIf_init(&cIf_k6Z8Bf9w, false);
  numBytes += hTable_init(&hTable_eObqPdzC, 256);
  numBytes += cDelay_init(this, &cDelay_Pe0uVwrL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_tbDTXaQW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_hfqUZuoz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LJwh4eRB, 0.0f);
  numBytes += hTable_init(&hTable_VwH15dD9, 256);
  numBytes += sVarf_init(&sVarf_l3BVLLxT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dVoQ13Lm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_85Df0DyD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VpyJNL6E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xbwgOrp9, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_HNHTH8Ni, "del-1359-ping");
  numBytes += cBinop_init(&cBinop_Uu9iHQWc, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_gV74UEaB, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_UxnlGioP, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_VCC4uwbr, 0.0f);
  numBytes += cVar_init_f(&cVar_1F6IvLbK, 0.0f);
  numBytes += cVar_init_f(&cVar_lmt63RE2, 3.0f);
  numBytes += cVar_init_f(&cVar_CuJmenzw, 0.0f);
  numBytes += cVar_init_f(&cVar_VfQZKSqK, 0.8f);
  numBytes += cBinop_init(&cBinop_zou1CGUI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xY8JzL2h, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bu77gpF7, 0.0f);
  numBytes += cIf_init(&cIf_cgF8WG1A, false);
  numBytes += cVar_init_f(&cVar_Lf3bipoI, 0.0f);
  numBytes += sVarf_init(&sVarf_Lffvq5eY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TKvbnSRQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bVc45Nbv, 3000.0f);
  numBytes += cBinop_init(&cBinop_QlyJRBl4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zXuKHf3p, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nfGasZoY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_InqDOS26, 3000.0f);
  numBytes += sVarf_init(&sVarf_lPWjPcnk, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_273Ih2Hp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WkBZvjmm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ffTR99YA, 0.8f);
  numBytes += sVarf_init(&sVarf_F5C1ex7B, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7wyd5DQc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_K2PfNK9i, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_OMfFMOnN, "del-1359-pong");
  numBytes += cVar_init_f(&cVar_G8VrDPUk, 0.7f);
  numBytes += cIf_init(&cIf_zzJU6sdb, false);
  numBytes += cVar_init_f(&cVar_k4sHureO, 0.0f);
  numBytes += cVar_init_f(&cVar_5JGEoic1, 48.0f);
  numBytes += cVar_init_f(&cVar_WShRzQyW, 1.0f);
  numBytes += cVar_init_f(&cVar_rXkuP9YW, 0.0f);
  numBytes += cBinop_init(&cBinop_gid8o4EU, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sn9f3amk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SrbVdsrS, 0.0f);
  numBytes += cVar_init_f(&cVar_kKPrhRZJ, 0.0f);
  numBytes += cRandom_init(&cRandom_5yLJGJ6u, -1481590555);
  numBytes += cSlice_init(&cSlice_jAxxI9Er, 1, 1);
  numBytes += sVari_init(&sVari_bo0HZB9X, 0, 0, false);
  numBytes += cVar_init_f(&cVar_1MI3IqtT, 0.5f);
  numBytes += cVar_init_f(&cVar_wiBGRKAl, 3.0f);
  numBytes += cBinop_init(&cBinop_9oXsBKES, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_oerzrKYy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Pn3qQNEP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Tc15RKYj, 1.0f);
  numBytes += cDelay_init(this, &cDelay_7shc0YIT, 0.0f);
  numBytes += cBinop_init(&cBinop_aZvTglUa, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VPYhqf06, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_GnbBJHZa, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_nsLPoXlG, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_NxG0NuAb, 3.0f);
  numBytes += sVarf_init(&sVarf_sFhIrLR3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h0vI4JZ4, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_SZjNPmzS, 1.0f);
  numBytes += cVar_init_f(&cVar_tH7iKS62, 0.0f);
  numBytes += cIf_init(&cIf_HlRs69pI, false);
  numBytes += cIf_init(&cIf_Dmg9BDxm, true);
  numBytes += cBinop_init(&cBinop_TKsx8vgK, -1.0f); // __add
  numBytes += cIf_init(&cIf_UNJBnliS, false);
  numBytes += cBinop_init(&cBinop_bIlQLWIk, 0.0f); // __add
  numBytes += cIf_init(&cIf_JPbjIKxA, true);
  numBytes += cVar_init_f(&cVar_aO2ua2Hg, 1.0f);
  numBytes += cBinop_init(&cBinop_lDxmzN20, 2.0f); // __add
  numBytes += cIf_init(&cIf_nBDLrhJm, true);
  numBytes += cIf_init(&cIf_TgGyAmII, false);
  numBytes += cVar_init_f(&cVar_6dvZapxT, 0.0f);
  numBytes += cIf_init(&cIf_4sHalHpq, true);
  numBytes += cIf_init(&cIf_6QUMerPQ, false);
  numBytes += cBinop_init(&cBinop_jcJODHVB, 8.0f); // __add
  numBytes += cSlice_init(&cSlice_1q8DRYte, 2, 1);
  numBytes += cSlice_init(&cSlice_ONhOseWX, 4, 1);
  numBytes += cSlice_init(&cSlice_10NZsCBe, 0, 1);
  numBytes += cSlice_init(&cSlice_PUmnbZdW, 1, 1);
  numBytes += cSlice_init(&cSlice_yIVNSBBG, 3, 1);
  numBytes += cVar_init_f(&cVar_pjOlmmlY, 1.0f);
  numBytes += cIf_init(&cIf_EuUYHRo3, false);
  numBytes += cVar_init_f(&cVar_AAUKOtJg, 0.0f);
  numBytes += cVar_init_f(&cVar_TotUYRbN, 0.0f);
  numBytes += cVar_init_f(&cVar_knDXQp99, 1.0f);
  numBytes += cVar_init_f(&cVar_2ZLSifkc, 0.0f);
  numBytes += cVar_init_f(&cVar_eG0kOid8, 0.0f);
  numBytes += cIf_init(&cIf_R6rGvL8d, true);
  numBytes += cIf_init(&cIf_WhuRdAY5, false);
  numBytes += cBinop_init(&cBinop_KawC4KSw, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_nn1kvdOM, 0.0f);
  numBytes += cVar_init_f(&cVar_j415Uijs, 0.0f);
  numBytes += cVar_init_f(&cVar_BSZV6WPy, 0.0f);
  numBytes += cVar_init_f(&cVar_VmbH6zF0, 1.0f);
  numBytes += cBinop_init(&cBinop_Z51fcaiz, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_gbtG4nJQ, 0.0f);
  numBytes += cVar_init_f(&cVar_7ouTgYvS, 0.0f);
  numBytes += cVar_init_f(&cVar_uvgaYbJK, 7.0f);
  numBytes += cVar_init_f(&cVar_2Po7Y2of, 9.0f);
  numBytes += cIf_init(&cIf_YllZtKCZ, false);
  numBytes += cVar_init_f(&cVar_FBYpuo4s, 0.0f);
  numBytes += cVar_init_f(&cVar_RfVMVWZm, 0.0f);
  numBytes += cBinop_init(&cBinop_RgcAbrvN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zcHDhbW0, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_ayLo2PDp, 1.0f);
  numBytes += cIf_init(&cIf_yTQxpBNB, false);
  numBytes += cVar_init_f(&cVar_qQ3x8cIm, 0.0f);
  numBytes += cVar_init_f(&cVar_uEdAiHAD, 0.0f);
  numBytes += cBinop_init(&cBinop_wrfr2K1q, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_mSHeBHh5, 0.0f); // __mul
  numBytes += cIf_init(&cIf_WvBnkA7Y, false);
  numBytes += cVar_init_f(&cVar_qW6WcekT, 0.0f);
  numBytes += hTable_initWithData(&hTable_U0QkO85v, 128, hTable_U0QkO85v_data);
  numBytes += cDelay_init(this, &cDelay_ikjqZg0x, 0.0f);
  numBytes += cVar_init_f(&cVar_YCG6iO2g, 1000.0f);
  numBytes += cBinop_init(&cBinop_mMven3lr, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_L6T9nbHk, 1, -1);
  numBytes += cSlice_init(&cSlice_caIKr2nt, 1, -1);
  numBytes += cVar_init_f(&cVar_CmUw7Egz, 0.0f);
  numBytes += cIf_init(&cIf_1bXKxIuY, false);
  numBytes += cBinop_init(&cBinop_6hAZGc5k, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_hw51oO1H, 0.0f);
  numBytes += cIf_init(&cIf_4iFE98NT, false);
  numBytes += cVar_init_f(&cVar_qrM4f8Oy, 0.0f);
  numBytes += cVar_init_f(&cVar_eDaR5HPm, 0.0f);
  numBytes += cVar_init_f(&cVar_lcN8Sf8g, 0.2f);
  numBytes += cVar_init_f(&cVar_TSQ3UlVJ, 0.0f);
  numBytes += cIf_init(&cIf_p0yMqSOQ, false);
  numBytes += cVar_init_f(&cVar_jNEtJFVm, 0.0f);
  numBytes += cIf_init(&cIf_qeFY664F, false);
  numBytes += cVar_init_f(&cVar_NWeLi6IM, 0.0f);
  numBytes += cBinop_init(&cBinop_pPlptklM, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_B01sV4Jl, 13.0f);
  numBytes += cBinop_init(&cBinop_XdAahnpH, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_aj5qmvHJ, 1.0f);
  numBytes += cBinop_init(&cBinop_OVNAYOJ6, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_i9nuD5M4, 0.0f);
  numBytes += cIf_init(&cIf_F4sf3bHM, false);
  numBytes += cVar_init_f(&cVar_CLeeNgbD, 0.0f);
  numBytes += cVar_init_f(&cVar_0lV07AAC, 0.0f);
  numBytes += cBinop_init(&cBinop_c6XLbF46, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Bn4xjktz, 0.0f);
  numBytes += cVar_init_f(&cVar_RIcdKMSS, 0.0f);
  numBytes += cIf_init(&cIf_o9X5kPAZ, false);
  numBytes += cVar_init_f(&cVar_n14oa6kc, 0.0f);
  numBytes += cSlice_init(&cSlice_MmdnTktM, 1, -1);
  numBytes += cBinop_init(&cBinop_LEekCwEu, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_yvi7Troq, "minor_scale");
  numBytes += cTabread_init(&cTabread_EDlr2Eef, &hTable_JTeuf71H); // minor_scale
  numBytes += cBinop_init(&cBinop_vvcv1u03, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_TGQvta4C, 0.0f);
  numBytes += cVar_init_f(&cVar_pOCU3R8S, 0.0f);
  numBytes += cVar_init_f(&cVar_8J0ExYke, 0.0f);
  numBytes += cBinop_init(&cBinop_mvLiMq5Q, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_sE2IeSdC, 0.0f);
  numBytes += cBinop_init(&cBinop_p5aGBtbu, 0.0f); // __min
  numBytes += cVar_init_s(&cVar_BNEly66K, "minor_scale");
  numBytes += cSlice_init(&cSlice_IM6Sx14a, 1, -1);
  numBytes += cTabread_init(&cTabread_a88RUqOb, &hTable_JTeuf71H); // minor_scale
  numBytes += cVar_init_f(&cVar_RItaQfha, 0.0f);
  numBytes += cVar_init_f(&cVar_7qGJtJvL, 0.0f);
  numBytes += cVar_init_f(&cVar_Tv5KKtwU, 0.5f);
  numBytes += cVar_init_f(&cVar_LukbP4w5, 0.0f);
  numBytes += cVar_init_f(&cVar_zVC3OchR, 0.0f);
  numBytes += cVar_init_f(&cVar_k9ZHNgCv, 550.0f);
  numBytes += cDelay_init(this, &cDelay_bOMI37vI, 0.0f);
  numBytes += cVar_init_f(&cVar_xZVxXt9y, 0.0f);
  numBytes += cVar_init_f(&cVar_WlHB4Hjg, 250.0f);
  numBytes += cVar_init_f(&cVar_uE28QYNx, 0.0f);
  numBytes += cVar_init_f(&cVar_oQvNxFYw, 0.0f);
  numBytes += cBinop_init(&cBinop_PWx85PtL, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_Sef26veT, 0.0f);
  numBytes += cVar_init_f(&cVar_gtJOQ046, 850.0f);
  numBytes += cBinop_init(&cBinop_cb2Q6R8y, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xke1Tw8M, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xdUWyZ7m, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9Rxiod2W, 0.0f);
  numBytes += cSlice_init(&cSlice_FpIY8gVw, 1, -1);
  numBytes += cSlice_init(&cSlice_tHss6xCG, 1, -1);
  numBytes += cVar_init_f(&cVar_9dRIidrx, 20.0f);
  numBytes += cVar_init_f(&cVar_fh5yHqQI, 0.0f);
  numBytes += cBinop_init(&cBinop_0ZJmPlMF, 20.0f); // __div
  numBytes += cVar_init_f(&cVar_fxdS2O0E, 0.0f);
  numBytes += cVar_init_f(&cVar_4k4Z3EB7, 0.0f);
  numBytes += cBinop_init(&cBinop_LP7PuyYZ, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_XxS5D4Q3, 0.0f);
  numBytes += cBinop_init(&cBinop_OAY3noe4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jY6aDgAH, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XkQ9GVSR, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_Uv7s5ls9, 0, 1);
  numBytes += cSlice_init(&cSlice_lwLFKqNK, 1, 1);
  numBytes += cBinop_init(&cBinop_uBO1Zsqz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_cfdPjPeZ, 20.0f);
  numBytes += cDelay_init(this, &cDelay_8zyj4NXR, 0.0f);
  numBytes += cVar_init_f(&cVar_NQ9J1uqC, 0.0f);
  numBytes += cVar_init_f(&cVar_lD95jVbd, 0.0f);
  numBytes += cVar_init_f(&cVar_YON3gtbV, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_c4EAXaDo, 0.0f);
  numBytes += cBinop_init(&cBinop_0xEUmL7c, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ueUtxUWR, 1.0f);
  numBytes += cBinop_init(&cBinop_RTLZOsoO, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_86VXIZjU, 0.0f);
  numBytes += cVar_init_f(&cVar_agvT9Tmm, 1.0f);
  numBytes += cIf_init(&cIf_uFV16IwN, false);
  numBytes += cVar_init_f(&cVar_ztmqpwyc, 0.0f);
  numBytes += cVar_init_f(&cVar_AqHxkhYt, 2000.0f);
  numBytes += cVar_init_f(&cVar_xPRy3Lpy, 0.0f);
  numBytes += cVar_init_f(&cVar_TV8wuBl4, 1.0f);
  numBytes += cBinop_init(&cBinop_7ic7e0dC, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_hQkBF2WW, 20.0f);
  numBytes += cVar_init_f(&cVar_0QJ2aCi9, 0.0f);
  numBytes += cVar_init_f(&cVar_aNKDMw3F, 0.0f);
  numBytes += cBinop_init(&cBinop_GyG9FCZt, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_0RAifqMr, 0.0f);
  numBytes += cIf_init(&cIf_638AkvaS, false);
  numBytes += cSlice_init(&cSlice_YSvjarBJ, 1, -1);
  numBytes += cSlice_init(&cSlice_Zj8GDv9j, 1, -1);
  numBytes += cBinop_init(&cBinop_1EaqnUEF, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_sl9yd5dN, 0.0f);
  numBytes += cIf_init(&cIf_2GtGCKd7, false);
  numBytes += cIf_init(&cIf_O4uJT3Fn, false);
  numBytes += cVar_init_f(&cVar_WVl0AIgo, 0.0f);
  numBytes += cBinop_init(&cBinop_J9VQSDKC, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_RMSHrI0a, 1, -1);
  numBytes += cSlice_init(&cSlice_SYEwHO8k, 1, -1);
  numBytes += hTable_initWithData(&hTable_JTeuf71H, 128, hTable_JTeuf71H_data);
  numBytes += cVar_init_f(&cVar_lz6quDWx, 0.0f);
  numBytes += cIf_init(&cIf_b4ihePSs, false);
  numBytes += cVar_init_f(&cVar_3LTRHDad, 0.0f);
  numBytes += cIf_init(&cIf_EEbU73L0, false);
  numBytes += cVar_init_f(&cVar_peDzFdkM, 0.0f);
  numBytes += cBinop_init(&cBinop_7WMYNBhk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_otTeFKP7, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_FgFvW6sk, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_gTM1XzJ8, 17.0f);
  numBytes += cVar_init_f(&cVar_b8ODhJAw, 0.0f);
  numBytes += cBinop_init(&cBinop_Kj1QHhjZ, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_zrkQD840, 2.0f);
  numBytes += cVar_init_f(&cVar_NwJ5ff8s, 1.0f);
  numBytes += cVar_init_f(&cVar_H7bfD5Qv, 0.0f);
  numBytes += cVar_init_f(&cVar_JdXChY71, 0.0f);
  numBytes += cIf_init(&cIf_RGUfpXmY, false);
  numBytes += cVar_init_f(&cVar_pbc93Fjo, 0.0f);
  numBytes += cIf_init(&cIf_pfFYVig0, false);
  numBytes += cIf_init(&cIf_P0TQUvTn, true);
  numBytes += cBinop_init(&cBinop_gjx08Tt8, -1.0f); // __add
  numBytes += cVar_init_f(&cVar_YHIXfR7E, 1.0f);
  numBytes += cVar_init_f(&cVar_Vqy7sWFh, 0.0f);
  numBytes += cVar_init_f(&cVar_KQj7gkvH, 0.0f);
  numBytes += cIf_init(&cIf_m6nadAYg, false);
  numBytes += cBinop_init(&cBinop_gPzJXbci, 8.0f); // __add
  numBytes += cIf_init(&cIf_THyz76oG, true);
  numBytes += cIf_init(&cIf_fKzpBxOC, true);
  numBytes += cBinop_init(&cBinop_vkGW9UTI, 16.0f); // __add
  numBytes += cIf_init(&cIf_jcsCOvkn, false);
  numBytes += cVar_init_f(&cVar_k0MEwwFr, 0.0f);
  numBytes += cVar_init_f(&cVar_kH0Vmvao, 0.0f);
  numBytes += cVar_init_f(&cVar_xsLdMY1R, 0.0f);
  numBytes += cIf_init(&cIf_uTcd2IoC, true);
  numBytes += cIf_init(&cIf_K166pFsk, false);
  numBytes += cBinop_init(&cBinop_o57cKi3C, 2.0f); // __add
  numBytes += cVar_init_f(&cVar_Hk4dwMnA, 1.0f);
  numBytes += cVar_init_f(&cVar_UIv9RwWh, 1.0f);
  numBytes += cIf_init(&cIf_oBjKSRcf, true);
  numBytes += cBinop_init(&cBinop_3Um51HvY, 0.0f); // __add
  numBytes += cIf_init(&cIf_pg4JH6LD, false);
  numBytes += cVar_init_f(&cVar_UykwUekv, 1.0f);
  numBytes += cVar_init_f(&cVar_CYbKrDzS, 0.0f);
  numBytes += cVar_init_f(&cVar_SASkZ6xO, 1.0f);
  numBytes += cIf_init(&cIf_4VT2aL8Y, false);
  numBytes += cVar_init_f(&cVar_Rl7z6SIW, 0.0f);
  numBytes += cVar_init_f(&cVar_eRRLtrKB, 0.0f);
  numBytes += cVar_init_f(&cVar_PBjuHVKz, 0.0f);
  numBytes += cSlice_init(&cSlice_jvtIUQOd, 2, 1);
  numBytes += cSlice_init(&cSlice_VT2fAI8r, 1, 1);
  numBytes += cSlice_init(&cSlice_NQrGqvyT, 4, 1);
  numBytes += cSlice_init(&cSlice_FmWbMyMg, 0, 1);
  numBytes += cSlice_init(&cSlice_YBS5SZX3, 3, 1);
  numBytes += cIf_init(&cIf_lgULjGQx, false);
  numBytes += cBinop_init(&cBinop_D2dqV5kS, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_17yxP2IL, 1, -1);
  numBytes += cSlice_init(&cSlice_1SESET9R, 1, -1);
  numBytes += cVar_init_f(&cVar_fNSHAqM9, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  cPack_free(&cPack_cP8Eqdc8);
  cPack_free(&cPack_1OdInJXY);
  cPack_free(&cPack_E10BehLN);
  hTable_free(&hTable_eObqPdzC);
  hTable_free(&hTable_VwH15dD9);
  hTable_free(&hTable_U0QkO85v);
  hTable_free(&hTable_JTeuf71H);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x6E3F5F6B: return &hTable_eObqPdzC; // del-1359-pong
    case 0x4D17F050: return &hTable_JTeuf71H; // minor_scale
    case 0x3C2A08D7: return &hTable_VwH15dD9; // del-1359-ping
    case 0xBBA21A19: return &hTable_U0QkO85v; // major_scale
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xC440C54F: { // Channel-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dZs3N4md_sendMessage);
      break;
    }
    case 0xB762BB42: { // Channel-B
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YXbrjPyI_sendMessage);
      break;
    }
    case 0x27D89CD5: { // Channel-C
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IuRHTbjU_sendMessage);
      break;
    }
    case 0x17512476: { // 1001-intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bJ15F9bn_sendMessage);
      break;
    }
    case 0xD52A3BF1: { // 1001-mastertempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GRBkvXul_sendMessage);
      break;
    }
    case 0x8CF5567: { // 1001-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FetctBQT_sendMessage);
      break;
    }
    case 0x8CC8BA58: { // 1001-transpose
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UGkh87go_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_P5D8h8HU_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MMDz5aVN_sendMessage);
      break;
    }
    case 0xD1207465: { // pot1s
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WpWHxzo2_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cSqmjkP3_sendMessage);
      break;
    }
    case 0xE2E3FFA0: { // pot2s
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_793RaLKX_sendMessage);
      break;
    }
    case 0xF2BC7D02: { // pot5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CWJGmjz3_sendMessage);
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


void Heavy_heavy::cCast_0qMZO4pu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_1o0STWZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JSZiNAJR, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_JSZiNAJR_sendMessage);
}

void Heavy_heavy::cBinop_JSZiNAJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yg6xq2Tz, HV_BINOP_LESS_THAN, 0, m, &cBinop_Yg6xq2Tz_sendMessage);
}

void Heavy_heavy::cUnop_QMdiqvA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3iuT6lVK, 0, m, &cVar_3iuT6lVK_sendMessage);
}

void Heavy_heavy::cBinop_k3PQKcGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q64BpXvc, 1, m, &cIf_Q64BpXvc_sendMessage);
}

void Heavy_heavy::cUnop_xvEW2zP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3iuT6lVK, 0, m, &cVar_3iuT6lVK_sendMessage);
}

void Heavy_heavy::cVar_6Jc3MUjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_k3PQKcGx_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Q64BpXvc, 0, m, &cIf_Q64BpXvc_sendMessage);
}

void Heavy_heavy::cIf_Q64BpXvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_xvEW2zP0_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QMdiqvA0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_d0VicD0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JSZiNAJR, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_JSZiNAJR_sendMessage);
}

void Heavy_heavy::cBinop_Yg6xq2Tz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9orTbMdw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_j9zek02Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0qMZO4pu_sendMessage);
}

void Heavy_heavy::cSwitchcase_9orTbMdw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j9zek02Q_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eg6UrrDp_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_lOoaVJYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1o0STWZy, HV_BINOP_MULTIPLY, 0, m, &cBinop_1o0STWZy_sendMessage);
}

void Heavy_heavy::cVar_m9X9i1sU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6Jc3MUjM, 0, m, &cVar_6Jc3MUjM_sendMessage);
}

void Heavy_heavy::cVar_5v5nRLK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_t4Af8A3p_sendMessage);
}

void Heavy_heavy::cVar_marjzifb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JNPrtTal_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RqBbVgUr, 0, m, &cIf_RqBbVgUr_sendMessage);
}

void Heavy_heavy::cBinop_JNPrtTal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RqBbVgUr, 1, m, &cIf_RqBbVgUr_sendMessage);
}

void Heavy_heavy::cIf_RqBbVgUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_lOK8eSGr_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_A8cfByr5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_lOK8eSGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d0VicD0r, 0, m, &cVar_d0VicD0r_sendMessage);
}

void Heavy_heavy::cUnop_A8cfByr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d0VicD0r, 0, m, &cVar_d0VicD0r_sendMessage);
}

void Heavy_heavy::cCast_Eg6UrrDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UIv9RwWh, 0, m, &cVar_UIv9RwWh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yeHBLlxW, 0, m, &cVar_yeHBLlxW_sendMessage);
}

void Heavy_heavy::cUnop_ZGYvl8z1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1aqJ4vd, 0, m, &cVar_Y1aqJ4vd_sendMessage);
}

void Heavy_heavy::cIf_C6p1AIlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_30KVSx6A_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZGYvl8z1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_zBjueYoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_C6p1AIlk, 1, m, &cIf_C6p1AIlk_sendMessage);
}

void Heavy_heavy::cVar_LqJ2BonC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zBjueYoi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_C6p1AIlk, 0, m, &cIf_C6p1AIlk_sendMessage);
}

void Heavy_heavy::cUnop_30KVSx6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1aqJ4vd, 0, m, &cVar_Y1aqJ4vd_sendMessage);
}

void Heavy_heavy::cBinop_t4Af8A3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5v5nRLK3, 1, m, &cVar_5v5nRLK3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lOoaVJYB, HV_BINOP_ADD, 0, m, &cBinop_lOoaVJYB_sendMessage);
}

void Heavy_heavy::cVar_3iuT6lVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1o0STWZy, HV_BINOP_MULTIPLY, 1, m, &cBinop_1o0STWZy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yg6xq2Tz, HV_BINOP_LESS_THAN, 1, m, &cBinop_Yg6xq2Tz_sendMessage);
}

void Heavy_heavy::cVar_Y1aqJ4vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lOoaVJYB, HV_BINOP_ADD, 1, m, &cBinop_lOoaVJYB_sendMessage);
}

void Heavy_heavy::cVar_zcxHUTlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LqJ2BonC, 0, m, &cVar_LqJ2BonC_sendMessage);
}

void Heavy_heavy::cVar_41CRETRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_marjzifb, 0, m, &cVar_marjzifb_sendMessage);
}

void Heavy_heavy::cSend_xJOc7484_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_FetctBQT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_YXbrjPyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_QsoSSGvi_sendMessage);
}

void Heavy_heavy::cBinop_G9BO8mSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sl9yd5dN, 0, m, &cVar_sl9yd5dN_sendMessage);
}

void Heavy_heavy::cBinop_pYKoIh14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KQj7gkvH, 0, m, &cVar_KQj7gkvH_sendMessage);
}

void Heavy_heavy::cSend_57Xf0ReC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UGkh87go_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_147W3d3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Wty24ssj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_TfyeQ5zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fYsQ9dsJ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_TKnbF3a9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwUNhD6J, 0, m, &cVar_qwUNhD6J_sendMessage);
}

void Heavy_heavy::cSystem_867WG0Nz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uIPzXNN0_sendMessage);
}

void Heavy_heavy::cBinop_2hkYxXN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_e9sMYgay, 0, m, &cTabread_e9sMYgay_sendMessage);
}

void Heavy_heavy::cMsg_l929iYfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_867WG0Nz_sendMessage);
}

void Heavy_heavy::cBinop_zpZJFlKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hkYxXN6, HV_BINOP_MIN, 0, m, &cBinop_2hkYxXN6_sendMessage);
}

void Heavy_heavy::cCast_Lg1uJGOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zpZJFlKO_sendMessage);
}

void Heavy_heavy::cVar_qwUNhD6J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l929iYfl_sendMessage(_c, 0, m);
}

void Heavy_heavy::cTabread_e9sMYgay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lHpsjCdo, HV_BINOP_ADD, 0, m, &cBinop_lHpsjCdo_sendMessage);
}

void Heavy_heavy::cSlice_iaYCQ2bX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_e9sMYgay, 1, m, &cTabread_e9sMYgay_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_e9sMYgay, 1, m, &cTabread_e9sMYgay_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Wty24ssj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iaYCQ2bX, 0, m, &cSlice_iaYCQ2bX_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TKnbF3a9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Lg1uJGOz_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_uIPzXNN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hkYxXN6, HV_BINOP_MIN, 1, m, &cBinop_2hkYxXN6_sendMessage);
}

void Heavy_heavy::cMsg_cX0mW0Ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_Wty24ssj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_kxDzgTlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lHpsjCdo, HV_BINOP_ADD, 1, m, &cBinop_lHpsjCdo_sendMessage);
}

void Heavy_heavy::cCast_G4kOGNnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cX0mW0Ka_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_Kg9Gdn7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kxDzgTlV, 0, m, &cVar_kxDzgTlV_sendMessage);
}

void Heavy_heavy::cMsg_fYsQ9dsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_Wty24ssj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_lHpsjCdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_WCOdhrCJ_sendMessage);
}

void Heavy_heavy::cMsg_bxwuJYCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z51fcaiz, HV_BINOP_SUBTRACT, 0, m, &cBinop_Z51fcaiz_sendMessage);
}

void Heavy_heavy::cSend_o6ZWoKc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_793RaLKX_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_bRLczDQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LukbP4w5, 0, m, &cVar_LukbP4w5_sendMessage);
}

void Heavy_heavy::cReceive_793RaLKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 512.0f, 0, m, &cBinop_Ohjkhzu9_sendMessage);
}

void Heavy_heavy::cBinop_3ac9ajSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AqHxkhYt, 0, m, &cVar_AqHxkhYt_sendMessage);
  cSend_vaiqL5QT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_6ojR7JHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_YQQkxmBc_sendMessage);
}

void Heavy_heavy::cVar_YhF1nOA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UXuF5sah, 0, m, &cVar_UXuF5sah_sendMessage);
}

void Heavy_heavy::cVar_daZMHWLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yeHBLlxW, 0, m, &cVar_yeHBLlxW_sendMessage);
}

void Heavy_heavy::cBinop_9hGYC0NW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aVDXoAlM, 1, m, &cIf_aVDXoAlM_sendMessage);
}

void Heavy_heavy::cIf_b3JUokXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Oo4gQ6wp, HV_BINOP_ADD, 0, m, &cBinop_Oo4gQ6wp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Oo4gQ6wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_147W3d3i, 0, m, &cVar_147W3d3i_sendMessage);
}

void Heavy_heavy::cIf_aVDXoAlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_147W3d3i, 0, m, &cVar_147W3d3i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_slBanMhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9YHBWDCD, 1, m, &cVar_9YHBWDCD_sendMessage);
}

void Heavy_heavy::cVar_9YHBWDCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_slBanMhl_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AcuudtaL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Jq5cN1Y6, 1, m, &cIf_Jq5cN1Y6_sendMessage);
}

void Heavy_heavy::cSlice_HXz4RGLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WTw4DWp7, HV_BINOP_ADD, 1, m, &cBinop_WTw4DWp7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_wnewENWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9aUcFtqx, HV_BINOP_ADD, 1, m, &cBinop_9aUcFtqx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_F69fFKnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hkbS7EFp, HV_BINOP_ADD, 1, m, &cBinop_hkbS7EFp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_I02O1hHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_g902mLOE, HV_BINOP_ADD, 1, m, &cBinop_g902mLOE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_CBW2BTzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_GxGIW44R, 0, m, &cVar_GxGIW44R_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_xikT9ab4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9YHBWDCD, 0, m, &cVar_9YHBWDCD_sendMessage);
}

void Heavy_heavy::cBinop_g902mLOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b3JUokXZ, 0, m, &cIf_b3JUokXZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_aVDXoAlM, 0, m, &cIf_aVDXoAlM_sendMessage);
}

void Heavy_heavy::cBinop_rGWP1nZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BS59nN2D, 1, m, &cIf_BS59nN2D_sendMessage);
}

void Heavy_heavy::cIf_eUhfYHmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_g902mLOE, HV_BINOP_ADD, 0, m, &cBinop_g902mLOE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_BS59nN2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_b3JUokXZ, 0, m, &cIf_b3JUokXZ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_aVDXoAlM, 0, m, &cIf_aVDXoAlM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_Jq5cN1Y6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_WTw4DWp7, HV_BINOP_ADD, 0, m, &cBinop_WTw4DWp7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_AcuudtaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bWAIOZQq, 1, m, &cIf_bWAIOZQq_sendMessage);
}

void Heavy_heavy::cBinop_WTw4DWp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XjbhgmBu, 0, m, &cIf_XjbhgmBu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_de0Y7saR, 0, m, &cIf_de0Y7saR_sendMessage);
}

void Heavy_heavy::cIf_bWAIOZQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_XjbhgmBu, 0, m, &cIf_XjbhgmBu_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_de0Y7saR, 0, m, &cIf_de0Y7saR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_wyBEdDR5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_rgPEAf9i_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_9hGYC0NW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b3JUokXZ, 1, m, &cIf_b3JUokXZ_sendMessage);
}

void Heavy_heavy::cBinop_rgPEAf9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wyBEdDR5, 1, m, &cVar_wyBEdDR5_sendMessage);
}

void Heavy_heavy::cVar_6HLZskXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GxGIW44R, 0, m, &cVar_GxGIW44R_sendMessage);
}

void Heavy_heavy::cVar_UXuF5sah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oaJVBrhT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EoWjPT33_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_uyeXwhCO, 1, m, &cIf_uyeXwhCO_sendMessage);
}

void Heavy_heavy::cBinop_oaJVBrhT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UXuF5sah, 1, m, &cVar_UXuF5sah_sendMessage);
}

void Heavy_heavy::cVar_V3UfwP9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wyBEdDR5, 0, m, &cVar_wyBEdDR5_sendMessage);
}

void Heavy_heavy::cVar_CJAsAVnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gAnF5IS9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_1O32HRRZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_XjbhgmBu, 1, m, &cIf_XjbhgmBu_sendMessage);
}

void Heavy_heavy::cBinop_gAnF5IS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CJAsAVnx, 1, m, &cVar_CJAsAVnx_sendMessage);
}

void Heavy_heavy::cVar_T492mjB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CJAsAVnx, 0, m, &cVar_CJAsAVnx_sendMessage);
}

void Heavy_heavy::cBinop_tJNsXiEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yeHBLlxW, 1, m, &cVar_yeHBLlxW_sendMessage);
}

void Heavy_heavy::cVar_yeHBLlxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_tJNsXiEm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_rGWP1nZ9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eUhfYHmy, 1, m, &cIf_eUhfYHmy_sendMessage);
}

void Heavy_heavy::cVar_FVhjcby5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oo4gQ6wp, HV_BINOP_ADD, 1, m, &cBinop_Oo4gQ6wp_sendMessage);
}

void Heavy_heavy::cVar_GxGIW44R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ECW9JI1V, 0, m, &cVar_ECW9JI1V_sendMessage);
}

void Heavy_heavy::cBinop_1O32HRRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_de0Y7saR, 1, m, &cIf_de0Y7saR_sendMessage);
}

void Heavy_heavy::cIf_XjbhgmBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_9aUcFtqx, HV_BINOP_ADD, 0, m, &cBinop_9aUcFtqx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_9aUcFtqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eUhfYHmy, 0, m, &cIf_eUhfYHmy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_BS59nN2D, 0, m, &cIf_BS59nN2D_sendMessage);
}

void Heavy_heavy::cIf_de0Y7saR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_eUhfYHmy, 0, m, &cIf_eUhfYHmy_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_BS59nN2D, 0, m, &cIf_BS59nN2D_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_uyeXwhCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hkbS7EFp, HV_BINOP_ADD, 0, m, &cBinop_hkbS7EFp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_EoWjPT33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b6xRkZwf, 1, m, &cIf_b6xRkZwf_sendMessage);
}

void Heavy_heavy::cIf_b6xRkZwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_Jq5cN1Y6, 0, m, &cIf_Jq5cN1Y6_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_bWAIOZQq, 0, m, &cIf_bWAIOZQq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_hkbS7EFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Jq5cN1Y6, 0, m, &cIf_Jq5cN1Y6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_bWAIOZQq, 0, m, &cIf_bWAIOZQq_sendMessage);
}

void Heavy_heavy::cUnop_aAev0Kqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FVhjcby5, 0, m, &cVar_FVhjcby5_sendMessage);
}

void Heavy_heavy::cBinop_6Je2RJh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2FtGfMow, 1, m, &cIf_2FtGfMow_sendMessage);
}

void Heavy_heavy::cUnop_BwLYNUOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FVhjcby5, 0, m, &cVar_FVhjcby5_sendMessage);
}

void Heavy_heavy::cIf_2FtGfMow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BwLYNUOV_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aAev0Kqe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_ECW9JI1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_6Je2RJh1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2FtGfMow, 0, m, &cIf_2FtGfMow_sendMessage);
}

void Heavy_heavy::cBinop_R21UDjEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uyeXwhCO, 0, m, &cIf_uyeXwhCO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b6xRkZwf, 0, m, &cIf_b6xRkZwf_sendMessage);
}

void Heavy_heavy::cPack_cP8Eqdc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_0hXKgL4Z, 0, m, NULL);
}

void Heavy_heavy::cVar_aefk6a2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1OdInJXY, 1, m, &cPack_1OdInJXY_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_cP8Eqdc8, 1, m, &cPack_cP8Eqdc8_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_E10BehLN, 1, m, &cPack_E10BehLN_sendMessage);
}

void Heavy_heavy::cBinop_WCOdhrCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_49FoUHcv_sendMessage);
}

void Heavy_heavy::cMsg_FpO2ZRpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tShivUZP, HV_BINOP_POW, 0, m, &cBinop_tShivUZP_sendMessage);
}

void Heavy_heavy::cBinop_tShivUZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_O1if7Ibe_sendMessage);
}

void Heavy_heavy::cBinop_O1if7Ibe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_E10BehLN, 0, m, &cPack_E10BehLN_sendMessage);
}

void Heavy_heavy::cBinop_49FoUHcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tShivUZP, HV_BINOP_POW, 1, m, &cBinop_tShivUZP_sendMessage);
  cMsg_FpO2ZRpe_sendMessage(_c, 0, m);
}

void Heavy_heavy::cPack_1OdInJXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BMXeaKXg, 0, m, NULL);
}

void Heavy_heavy::cBinop_lTW0ZaPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mClqTT1T, HV_BINOP_POW, 1, m, &cBinop_mClqTT1T_sendMessage);
  cMsg_kcjNhMvG_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Pc11PcoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lTW0ZaPy_sendMessage);
}

void Heavy_heavy::cBinop_mClqTT1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_wHWorFq6_sendMessage);
}

void Heavy_heavy::cBinop_wHWorFq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1OdInJXY, 0, m, &cPack_1OdInJXY_sendMessage);
}

void Heavy_heavy::cMsg_kcjNhMvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mClqTT1T, HV_BINOP_POW, 0, m, &cBinop_mClqTT1T_sendMessage);
}

void Heavy_heavy::cPack_E10BehLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_AT1wwnAQ, 0, m, NULL);
}

void Heavy_heavy::cVar_y0eb8GVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aefk6a2h, 0, m, &cVar_aefk6a2h_sendMessage);
}

void Heavy_heavy::cBinop_KypUBkh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_40bCHHsP_sendMessage);
}

void Heavy_heavy::cBinop_yVwgBvJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cP8Eqdc8, 0, m, &cPack_cP8Eqdc8_sendMessage);
}

void Heavy_heavy::cBinop_40bCHHsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6NJ9E7T, HV_BINOP_POW, 1, m, &cBinop_b6NJ9E7T_sendMessage);
  cMsg_IATgz1Qd_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_IATgz1Qd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6NJ9E7T, HV_BINOP_POW, 0, m, &cBinop_b6NJ9E7T_sendMessage);
}

void Heavy_heavy::cBinop_b6NJ9E7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_yVwgBvJ7_sendMessage);
}

void Heavy_heavy::cCast_JmJmAM8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eDaR5HPm, 0, m, &cVar_eDaR5HPm_sendMessage);
}

void Heavy_heavy::cBinop_YQQkxmBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k4sHureO, 1, m, &cVar_k4sHureO_sendMessage);
}

void Heavy_heavy::cReceive_P5D8h8HU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tXJ3NAqn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cfdPjPeZ, 0, m, &cVar_cfdPjPeZ_sendMessage);
  cMsg_IiYDcVqf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YON3gtbV, 0, m, &cVar_YON3gtbV_sendMessage);
  cMsg_8y7YoBLB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_agvT9Tmm, 0, m, &cVar_agvT9Tmm_sendMessage);
  cMsg_vrQ1IoTv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fh5yHqQI, 0, m, &cVar_fh5yHqQI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9dRIidrx, 0, m, &cVar_9dRIidrx_sendMessage);
  cMsg_nRYDud0t_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NxG0NuAb, 0, m, &cVar_NxG0NuAb_sendMessage);
  cSwitchcase_55pUUDdJ_onMessage(_c, NULL, 0, m, NULL);
  cMsg_J8H6Qs8y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wiBGRKAl, 0, m, &cVar_wiBGRKAl_sendMessage);
  cMsg_Cx0zzzp8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Tc15RKYj, 0, m, &cVar_Tc15RKYj_sendMessage);
  cMsg_Crkm96Ib_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bVc45Nbv, 0, m, &cVar_bVc45Nbv_sendMessage);
  cMsg_ebqFkoxi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_InqDOS26, 0, m, &cVar_InqDOS26_sendMessage);
  cMsg_kmCsSdEl_sendMessage(_c, 0, m);
  cMsg_dCbLQBTZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2ZLSifkc, 0, m, &cVar_2ZLSifkc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nn1kvdOM, 0, m, &cVar_nn1kvdOM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eG0kOid8, 0, m, &cVar_eG0kOid8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BSZV6WPy, 0, m, &cVar_BSZV6WPy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tH7iKS62, 0, m, &cVar_tH7iKS62_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j415Uijs, 0, m, &cVar_j415Uijs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eRRLtrKB, 0, m, &cVar_eRRLtrKB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PBjuHVKz, 0, m, &cVar_PBjuHVKz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Vqy7sWFh, 0, m, &cVar_Vqy7sWFh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xsLdMY1R, 0, m, &cVar_xsLdMY1R_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kH0Vmvao, 0, m, &cVar_kH0Vmvao_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k0MEwwFr, 0, m, &cVar_k0MEwwFr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YhF1nOA1, 0, m, &cVar_YhF1nOA1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xikT9ab4, 0, m, &cVar_xikT9ab4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T492mjB5, 0, m, &cVar_T492mjB5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_daZMHWLS, 0, m, &cVar_daZMHWLS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V3UfwP9s, 0, m, &cVar_V3UfwP9s_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6HLZskXs, 0, m, &cVar_6HLZskXs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ueUtxUWR, 0, m, &cVar_ueUtxUWR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AqHxkhYt, 0, m, &cVar_AqHxkhYt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B01sV4Jl, 0, m, &cVar_B01sV4Jl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aj5qmvHJ, 0, m, &cVar_aj5qmvHJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CLeeNgbD, 0, m, &cVar_CLeeNgbD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gTM1XzJ8, 0, m, &cVar_gTM1XzJ8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NwJ5ff8s, 0, m, &cVar_NwJ5ff8s_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zrkQD840, 0, m, &cVar_zrkQD840_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_41CRETRr, 0, m, &cVar_41CRETRr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_m9X9i1sU, 0, m, &cVar_m9X9i1sU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zcxHUTlX, 0, m, &cVar_zcxHUTlX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2Po7Y2of, 0, m, &cVar_2Po7Y2of_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ayLo2PDp, 0, m, &cVar_ayLo2PDp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uvgaYbJK, 0, m, &cVar_uvgaYbJK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WlHB4Hjg, 0, m, &cVar_WlHB4Hjg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k9ZHNgCv, 0, m, &cVar_k9ZHNgCv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gtJOQ046, 0, m, &cVar_gtJOQ046_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1MI3IqtT, 0, m, &cVar_1MI3IqtT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5JGEoic1, 0, m, &cVar_5JGEoic1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WShRzQyW, 0, m, &cVar_WShRzQyW_sendMessage);
  cMsg_aLf1xtdw_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yzzE2UPx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TGQvta4C, 0, m, &cVar_TGQvta4C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sPVqnCKE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7qGJtJvL, 0, m, &cVar_7qGJtJvL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TfyeQ5zf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Kg9Gdn7V, 0, m, &cVar_Kg9Gdn7V_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y0eb8GVo, 0, m, &cVar_y0eb8GVo_sendMessage);
  cMsg_6b26ud8f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YCG6iO2g, 0, m, &cVar_YCG6iO2g_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lmt63RE2, 0, m, &cVar_lmt63RE2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G8VrDPUk, 0, m, &cVar_G8VrDPUk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ffTR99YA, 0, m, &cVar_ffTR99YA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VfQZKSqK, 0, m, &cVar_VfQZKSqK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TV8wuBl4, 0, m, &cVar_TV8wuBl4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lcN8Sf8g, 0, m, &cVar_lcN8Sf8g_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Tv5KKtwU, 0, m, &cVar_Tv5KKtwU_sendMessage);
  cSwitchcase_doZMasVg_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_HNHTH8Ni, 0, m, &cVar_HNHTH8Ni_sendMessage);
  cMsg_fH2tWvg1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OMfFMOnN, 0, m, &cVar_OMfFMOnN_sendMessage);
  cMsg_yhWebc71_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_GRBkvXul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_2UnJrFMt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_7f5BBN13_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_NOsj5COX_sendMessage);
}

void Heavy_heavy::cCast_MwgUDzAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ebVjeECs, HV_BINOP_NEQ, 1, m, &cBinop_ebVjeECs_sendMessage);
}

void Heavy_heavy::cCast_j5rO2aFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ebVjeECs, HV_BINOP_NEQ, 0, m, &cBinop_ebVjeECs_sendMessage);
}

void Heavy_heavy::cVar_C2R1Dc6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_9I5MAlTv_sendMessage);
}

void Heavy_heavy::cBinop_ebVjeECs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_k6Z8Bf9w, 1, m, &cIf_k6Z8Bf9w_sendMessage);
}

void Heavy_heavy::cSlice_LAP8CRLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_C2R1Dc6X, 0, m, &cVar_C2R1Dc6X_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_C2R1Dc6X, 0, m, &cVar_C2R1Dc6X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_UsmDKpPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ebVjeECs, HV_BINOP_NEQ, 1, m, &cBinop_ebVjeECs_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_C2R1Dc6X, 1, m, &cVar_C2R1Dc6X_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ebVjeECs, HV_BINOP_NEQ, 1, m, &cBinop_ebVjeECs_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_C2R1Dc6X, 1, m, &cVar_C2R1Dc6X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_uehGQS6E_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LAP8CRLN, 0, m, &cSlice_LAP8CRLN_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UsmDKpPL, 0, m, &cSlice_UsmDKpPL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j5rO2aFt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BXe4QUFT_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cCast_qBIcIihA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C2R1Dc6X, 0, m, &cVar_C2R1Dc6X_sendMessage);
}

void Heavy_heavy::cIf_k6Z8Bf9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MwgUDzAs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qBIcIihA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_BXe4QUFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_k6Z8Bf9w, 0, m, &cIf_k6Z8Bf9w_sendMessage);
}

void Heavy_heavy::cCast_RvgiEEfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UxnlGioP, HV_BINOP_SUBTRACT, 1, m, &cBinop_UxnlGioP_sendMessage);
}

void Heavy_heavy::cCast_MjPoZtBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bu77gpF7, 0, m, &cVar_bu77gpF7_sendMessage);
}

void Heavy_heavy::cUnop_dFgeHW1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dVoQ13Lm, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gV74UEaB, m);
}

void Heavy_heavy::cMsg_6lrfYIP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UxnlGioP, HV_BINOP_SUBTRACT, 0, m, &cBinop_UxnlGioP_sendMessage);
}

void Heavy_heavy::cMsg_dCbLQBTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1qB7Sm7S_sendMessage);
}

void Heavy_heavy::cSystem_1qB7Sm7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9jqU6r5M_sendMessage);
}

void Heavy_heavy::hTable_eObqPdzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LgHEO49J_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pe0uVwrL, 2, m, &cDelay_Pe0uVwrL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_47Fxiw6F_sendMessage);
}

void Heavy_heavy::cCast_47Fxiw6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pe0uVwrL, 0, m, &cDelay_Pe0uVwrL_sendMessage);
}

void Heavy_heavy::cMsg_LgHEO49J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_tbDTXaQW, 2, m, &cDelay_tbDTXaQW_sendMessage);
}

void Heavy_heavy::cBinop_9jqU6r5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_UoCu3Agz_sendMessage);
}

void Heavy_heavy::cDelay_Pe0uVwrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Pe0uVwrL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tbDTXaQW, 0, m, &cDelay_tbDTXaQW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Pe0uVwrL, 0, m, &cDelay_Pe0uVwrL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qW5cWS0w, 1, m, NULL);
}

void Heavy_heavy::cMsg_063prve8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_eObqPdzC, 0, m, &hTable_eObqPdzC_sendMessage);
}

void Heavy_heavy::cBinop_UoCu3Agz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EGJ9V683_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_EGJ9V683_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_eObqPdzC, 0, m, &hTable_eObqPdzC_sendMessage);
}

void Heavy_heavy::cDelay_tbDTXaQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tbDTXaQW, m);
  cMsg_063prve8_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_qV34hy0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zou1CGUI, HV_BINOP_MULTIPLY, 1, m, &cBinop_zou1CGUI_sendMessage);
}

void Heavy_heavy::cBinop_RUZAMM8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WWQsJiz4_sendMessage);
}

void Heavy_heavy::cBinop_WWQsJiz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zXuKHf3p, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xY8JzL2h, m);
}

void Heavy_heavy::cBinop_tle54kw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_q2LLjciW_sendMessage);
}

void Heavy_heavy::cMsg_N5McwbQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_VwH15dD9, 0, m, &hTable_VwH15dD9_sendMessage);
}

void Heavy_heavy::cMsg_cRoK5Omw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_hfqUZuoz, 2, m, &cDelay_hfqUZuoz_sendMessage);
}

void Heavy_heavy::cBinop_q2LLjciW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bKvjgtsY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_dTkEdTn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LJwh4eRB, 0, m, &cDelay_LJwh4eRB_sendMessage);
}

void Heavy_heavy::cMsg_bKvjgtsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_VwH15dD9, 0, m, &hTable_VwH15dD9_sendMessage);
}

void Heavy_heavy::cDelay_hfqUZuoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hfqUZuoz, m);
  cMsg_N5McwbQP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_wUbLSCYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tle54kw0_sendMessage);
}

void Heavy_heavy::cMsg_kmCsSdEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wUbLSCYV_sendMessage);
}

void Heavy_heavy::cDelay_LJwh4eRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LJwh4eRB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_hfqUZuoz, 0, m, &cDelay_hfqUZuoz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LJwh4eRB, 0, m, &cDelay_LJwh4eRB_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_xGINu7jN, 1, m, NULL);
}

void Heavy_heavy::hTable_VwH15dD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cRoK5Omw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LJwh4eRB, 2, m, &cDelay_LJwh4eRB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dTkEdTn2_sendMessage);
}

void Heavy_heavy::cMsg_fH2tWvg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OehqdRjz_sendMessage);
}

void Heavy_heavy::cSystem_OehqdRjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Iv5XNy4b_sendMessage);
}

void Heavy_heavy::cSystem_TPiwyTws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RAlviDCi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VpyJNL6E, m);
}

void Heavy_heavy::cMsg_PvjfF37D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TPiwyTws_sendMessage);
}

void Heavy_heavy::cBinop_Iv5XNy4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_85Df0DyD, m);
}

void Heavy_heavy::cBinop_RAlviDCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xbwgOrp9, m);
}

void Heavy_heavy::cVar_HNHTH8Ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PvjfF37D_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_zZLPjrGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6lrfYIP9_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Uu9iHQWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rrtxpsld_sendMessage);
}

void Heavy_heavy::cBinop_rrtxpsld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bVc45Nbv, 0, m, &cVar_bVc45Nbv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_InqDOS26, 0, m, &cVar_InqDOS26_sendMessage);
}

void Heavy_heavy::cBinop_RiPeNHAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_YTz5RMK5_sendMessage);
}

void Heavy_heavy::cMsg_Z89LuTQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Uu9iHQWc, HV_BINOP_POW, 0, m, &cBinop_Uu9iHQWc_sendMessage);
}

void Heavy_heavy::cBinop_YTz5RMK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Uu9iHQWc, HV_BINOP_POW, 1, m, &cBinop_Uu9iHQWc_sendMessage);
  cMsg_Z89LuTQV_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_UxnlGioP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_dFgeHW1N_sendMessage);
}

void Heavy_heavy::cVar_VCC4uwbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bu77gpF7, 0, m, &cVar_bu77gpF7_sendMessage);
}

void Heavy_heavy::cVar_1F6IvLbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_nxbmbz8s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zZLPjrGb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RvgiEEfD_sendMessage);
}

void Heavy_heavy::cMsg_QvMRhtnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_65KpTKWm, 0, m, NULL);
}

void Heavy_heavy::cBinop_NOsj5COX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qV34hy0E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MjPoZtBt_sendMessage);
}

void Heavy_heavy::cVar_lmt63RE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VCC4uwbr, 0, m, &cVar_VCC4uwbr_sendMessage);
}

void Heavy_heavy::cUnop_nxbmbz8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l3BVLLxT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WkBZvjmm, m);
}

void Heavy_heavy::cVar_CuJmenzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.99f, 0, m, &cBinop_RUZAMM8d_sendMessage);
}

void Heavy_heavy::cVar_VfQZKSqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1F6IvLbK, 0, m, &cVar_1F6IvLbK_sendMessage);
}

void Heavy_heavy::cBinop_zou1CGUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QvMRhtnP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cUnop_BOj4L0pH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zou1CGUI, HV_BINOP_MULTIPLY, 0, m, &cBinop_zou1CGUI_sendMessage);
}

void Heavy_heavy::cVar_bu77gpF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gREQ0rnz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_cgF8WG1A, 0, m, &cIf_cgF8WG1A_sendMessage);
}

void Heavy_heavy::cIf_cgF8WG1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_0utA8Nr5_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BOj4L0pH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_0utA8Nr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zou1CGUI, HV_BINOP_MULTIPLY, 0, m, &cBinop_zou1CGUI_sendMessage);
}

void Heavy_heavy::cBinop_gREQ0rnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cgF8WG1A, 1, m, &cIf_cgF8WG1A_sendMessage);
}

void Heavy_heavy::cVar_Lf3bipoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_F7LY6bHB_sendMessage);
}

void Heavy_heavy::cBinop_etCDnmCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DoscQYUj_sendMessage);
}

void Heavy_heavy::cBinop_DoscQYUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wGTZAeET_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Lffvq5eY, m);
}

void Heavy_heavy::cBinop_wGTZAeET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TKvbnSRQ, m);
}

void Heavy_heavy::cVar_bVc45Nbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QlyJRBl4, HV_BINOP_MULTIPLY, 0, m, &cBinop_QlyJRBl4_sendMessage);
}

void Heavy_heavy::cBinop_QlyJRBl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_etCDnmCH_sendMessage);
}

void Heavy_heavy::cSystem_tamEpUKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o0Nd3vKY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_Crkm96Ib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tamEpUKv_sendMessage);
}

void Heavy_heavy::cBinop_cSmQZYuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QlyJRBl4, HV_BINOP_MULTIPLY, 1, m, &cBinop_QlyJRBl4_sendMessage);
}

void Heavy_heavy::cMsg_o0Nd3vKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cSmQZYuu_sendMessage);
}

void Heavy_heavy::cBinop_F7LY6bHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_RiPeNHAg_sendMessage);
}

void Heavy_heavy::cBinop_HfASz2eY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_U4YkSJ1c_sendMessage);
}

void Heavy_heavy::cBinop_U4YkSJ1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LZDmwPeX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lPWjPcnk, m);
}

void Heavy_heavy::cVar_InqDOS26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_273Ih2Hp, HV_BINOP_MULTIPLY, 0, m, &cBinop_273Ih2Hp_sendMessage);
}

void Heavy_heavy::cBinop_QCj5qMYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_273Ih2Hp, HV_BINOP_MULTIPLY, 1, m, &cBinop_273Ih2Hp_sendMessage);
}

void Heavy_heavy::cBinop_273Ih2Hp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HfASz2eY_sendMessage);
}

void Heavy_heavy::cMsg_ebqFkoxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D34dbVBP_sendMessage);
}

void Heavy_heavy::cSystem_D34dbVBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fdxjBi5A_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_fdxjBi5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QCj5qMYr_sendMessage);
}

void Heavy_heavy::cBinop_LZDmwPeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nfGasZoY, m);
}

void Heavy_heavy::cVar_ffTR99YA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuJmenzw, 0, m, &cVar_CuJmenzw_sendMessage);
}

void Heavy_heavy::cSystem_s9RZZ83E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Cg0B4QtA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7wyd5DQc, m);
}

void Heavy_heavy::cSystem_bg8JXBkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hq4Hu7dm_sendMessage);
}

void Heavy_heavy::cMsg_yhWebc71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bg8JXBkl_sendMessage);
}

void Heavy_heavy::cMsg_2e521fPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s9RZZ83E_sendMessage);
}

void Heavy_heavy::cBinop_hq4Hu7dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K2PfNK9i, m);
}

void Heavy_heavy::cVar_OMfFMOnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2e521fPH_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Cg0B4QtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_F5C1ex7B, m);
}

void Heavy_heavy::cVar_G8VrDPUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Lf3bipoI, 0, m, &cVar_Lf3bipoI_sendMessage);
}

void Heavy_heavy::cSend_vaiqL5QT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GRBkvXul_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_lapxelfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bxwuJYCB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_RtmIa7E7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_yvFsrB9b_sendMessage);
}

void Heavy_heavy::cUnop_Y07n5wB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HlRs69pI, 0, m, &cIf_HlRs69pI_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Dmg9BDxm, 0, m, &cIf_Dmg9BDxm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_sQb1vnIH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_R21UDjEy_sendMessage);
}

void Heavy_heavy::cIf_zzJU6sdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_K1oQS5LO_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Y07n5wB5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_k4sHureO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gk12uuOd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zzJU6sdb, 0, m, &cIf_zzJU6sdb_sendMessage);
}

void Heavy_heavy::cUnop_K1oQS5LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HlRs69pI, 0, m, &cIf_HlRs69pI_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Dmg9BDxm, 0, m, &cIf_Dmg9BDxm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_sQb1vnIH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_R21UDjEy_sendMessage);
}

void Heavy_heavy::cBinop_gk12uuOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zzJU6sdb, 1, m, &cIf_zzJU6sdb_sendMessage);
}

void Heavy_heavy::cReceive_UGkh87go_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_6ojR7JHB_sendMessage);
}

void Heavy_heavy::cVar_5JGEoic1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SrbVdsrS, 0, m, &cVar_SrbVdsrS_sendMessage);
}

void Heavy_heavy::cVar_WShRzQyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rXkuP9YW, 0, m, &cVar_rXkuP9YW_sendMessage);
}

void Heavy_heavy::cVar_rXkuP9YW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gid8o4EU, HV_BINOP_MULTIPLY, 1, m, &cBinop_gid8o4EU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VPYhqf06, m);
}

void Heavy_heavy::cBinop_gid8o4EU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RtmIa7E7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_UXw2W5jX_sendMessage);
}

void Heavy_heavy::cCast_fxVkKHme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnbBJHZa, HV_BINOP_SUBTRACT, 1, m, &cBinop_GnbBJHZa_sendMessage);
}

void Heavy_heavy::cVar_SrbVdsrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fxVkKHme_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9drru6Bh_sendMessage);
}

void Heavy_heavy::cVar_kKPrhRZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sn9f3amk, m);
}

void Heavy_heavy::cRandom_5yLJGJ6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_2TPyz80a_sendMessage);
}

void Heavy_heavy::cUnop_KB5xQeh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IbcamQ3Z_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_2TPyz80a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KB5xQeh6_sendMessage);
}

void Heavy_heavy::cSlice_jAxxI9Er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5yLJGJ6u, 1, m, &cRandom_5yLJGJ6u_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_55pUUDdJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jAxxI9Er, 0, m, &cSlice_jAxxI9Er_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5yLJGJ6u, 0, m, &cRandom_5yLJGJ6u_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_IbcamQ3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_bo0HZB9X, m);
}

void Heavy_heavy::cMsg_aLf1xtdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_35CbJBpZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_1MI3IqtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kKPrhRZJ, 0, m, &cVar_kKPrhRZJ_sendMessage);
}

void Heavy_heavy::sSample_PDIAlkr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gid8o4EU, HV_BINOP_MULTIPLY, 0, m, &cBinop_gid8o4EU_sendMessage);
}

void Heavy_heavy::cBinop_X2YuVVe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oerzrKYy, m);
}

void Heavy_heavy::cVar_wiBGRKAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9oXsBKES, HV_BINOP_MULTIPLY, 0, m, &cBinop_9oXsBKES_sendMessage);
}

void Heavy_heavy::cMsg_J8H6Qs8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6auYdMvd_sendMessage);
}

void Heavy_heavy::cSystem_6auYdMvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jHDFSelA_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_tGkl37B4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9oXsBKES, HV_BINOP_MULTIPLY, 1, m, &cBinop_9oXsBKES_sendMessage);
}

void Heavy_heavy::cMsg_jHDFSelA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tGkl37B4_sendMessage);
}

void Heavy_heavy::cBinop_9oXsBKES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LrgDmyGu_sendMessage);
}

void Heavy_heavy::cBinop_AQ3zwt8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_X2YuVVe0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pn3qQNEP, m);
}

void Heavy_heavy::cBinop_LrgDmyGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AQ3zwt8t_sendMessage);
}

void Heavy_heavy::cMsg_HoEaUHdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7shc0YIT, 0, m, &cDelay_7shc0YIT_sendMessage);
}

void Heavy_heavy::cBinop_wlMgjLJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aZvTglUa, HV_BINOP_MULTIPLY, 1, m, &cBinop_aZvTglUa_sendMessage);
}

void Heavy_heavy::cVar_Tc15RKYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aZvTglUa, HV_BINOP_MULTIPLY, 0, m, &cBinop_aZvTglUa_sendMessage);
}

void Heavy_heavy::cSwitchcase_35CbJBpZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HoEaUHdQ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HoEaUHdQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7UOfonMy_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_7shc0YIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7shc0YIT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7shc0YIT, 0, m, &cDelay_7shc0YIT_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_PDIAlkr7, 1, m);
}

void Heavy_heavy::cCast_7UOfonMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HoEaUHdQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7shc0YIT, 0, m, &cDelay_7shc0YIT_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_PDIAlkr7, 1, m);
}

void Heavy_heavy::cBinop_bwdmIX5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7shc0YIT, 2, m, &cDelay_7shc0YIT_sendMessage);
}

void Heavy_heavy::cMsg_Cx0zzzp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I5Vggjn5_sendMessage);
}

void Heavy_heavy::cSystem_I5Vggjn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wlMgjLJC_sendMessage);
}

void Heavy_heavy::cBinop_aZvTglUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bwdmIX5G_sendMessage);
}

void Heavy_heavy::cMsg_JcxWDs0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.01f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnbBJHZa, HV_BINOP_SUBTRACT, 0, m, &cBinop_GnbBJHZa_sendMessage);
}

void Heavy_heavy::cCast_9drru6Bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JcxWDs0k_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_GnbBJHZa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wiBGRKAl, 0, m, &cVar_wiBGRKAl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NxG0NuAb, 0, m, &cVar_NxG0NuAb_sendMessage);
}

void Heavy_heavy::cBinop_CwowRYIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nsLPoXlG, HV_BINOP_MULTIPLY, 1, m, &cBinop_nsLPoXlG_sendMessage);
}

void Heavy_heavy::cBinop_nsLPoXlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eLgJaDPP_sendMessage);
}

void Heavy_heavy::cSystem_dEnzIVLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TgOt3VdM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_nRYDud0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dEnzIVLM_sendMessage);
}

void Heavy_heavy::cMsg_TgOt3VdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CwowRYIy_sendMessage);
}

void Heavy_heavy::cVar_NxG0NuAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nsLPoXlG, HV_BINOP_MULTIPLY, 0, m, &cBinop_nsLPoXlG_sendMessage);
}

void Heavy_heavy::cBinop_eLgJaDPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GW4NDOkj_sendMessage);
}

void Heavy_heavy::cBinop_GW4NDOkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Orhr9To1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sFhIrLR3, m);
}

void Heavy_heavy::cBinop_Orhr9To1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h0vI4JZ4, m);
}

void Heavy_heavy::cBinop_IyGIKS2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aMSxSZ1d_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jOzrLrcx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FsiWjSjY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_Sgqstl7u_sendMessage);
}

void Heavy_heavy::cBinop_NJ363ZNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SZjNPmzS, 1, m, &cVar_SZjNPmzS_sendMessage);
}

void Heavy_heavy::cVar_SZjNPmzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NJ363ZNl_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NmYVpVBM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TgGyAmII, 1, m, &cIf_TgGyAmII_sendMessage);
}

void Heavy_heavy::cVar_tH7iKS62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VmbH6zF0, 0, m, &cVar_VmbH6zF0_sendMessage);
}

void Heavy_heavy::cIf_HlRs69pI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TKsx8vgK, HV_BINOP_ADD, 0, m, &cBinop_TKsx8vgK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_Dmg9BDxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_TgGyAmII, 0, m, &cIf_TgGyAmII_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_nBDLrhJm, 0, m, &cIf_nBDLrhJm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_TKsx8vgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TgGyAmII, 0, m, &cIf_TgGyAmII_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nBDLrhJm, 0, m, &cIf_nBDLrhJm_sendMessage);
}

void Heavy_heavy::cBinop_KuCoZ30A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Dmg9BDxm, 1, m, &cIf_Dmg9BDxm_sendMessage);
}

void Heavy_heavy::cIf_UNJBnliS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bIlQLWIk, HV_BINOP_ADD, 0, m, &cBinop_bIlQLWIk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_bIlQLWIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8J0ExYke, 0, m, &cVar_8J0ExYke_sendMessage);
}

void Heavy_heavy::cBinop_zWBkiyXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JPbjIKxA, 1, m, &cIf_JPbjIKxA_sendMessage);
}

void Heavy_heavy::cIf_JPbjIKxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_8J0ExYke, 0, m, &cVar_8J0ExYke_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_6W7sk1wa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aO2ua2Hg, 1, m, &cVar_aO2ua2Hg_sendMessage);
}

void Heavy_heavy::cVar_aO2ua2Hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6W7sk1wa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_fnO5SNzA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6QUMerPQ, 1, m, &cIf_6QUMerPQ_sendMessage);
}

void Heavy_heavy::cBinop_lDxmzN20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6QUMerPQ, 0, m, &cIf_6QUMerPQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4sHalHpq, 0, m, &cIf_4sHalHpq_sendMessage);
}

void Heavy_heavy::cBinop_NmYVpVBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nBDLrhJm, 1, m, &cIf_nBDLrhJm_sendMessage);
}

void Heavy_heavy::cIf_nBDLrhJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_6QUMerPQ, 0, m, &cIf_6QUMerPQ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_4sHalHpq, 0, m, &cIf_4sHalHpq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_TgGyAmII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_lDxmzN20, HV_BINOP_ADD, 0, m, &cBinop_lDxmzN20_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_6dvZapxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AAUKOtJg, 0, m, &cVar_AAUKOtJg_sendMessage);
}

void Heavy_heavy::cIf_4sHalHpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_WhuRdAY5, 0, m, &cIf_WhuRdAY5_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_R6rGvL8d, 0, m, &cIf_R6rGvL8d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_fnO5SNzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4sHalHpq, 1, m, &cIf_4sHalHpq_sendMessage);
}

void Heavy_heavy::cIf_6QUMerPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jcJODHVB, HV_BINOP_ADD, 0, m, &cBinop_jcJODHVB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_jcJODHVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WhuRdAY5, 0, m, &cIf_WhuRdAY5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_R6rGvL8d, 0, m, &cIf_R6rGvL8d_sendMessage);
}

void Heavy_heavy::cSlice_1q8DRYte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_jcJODHVB, HV_BINOP_ADD, 1, m, &cBinop_jcJODHVB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_ONhOseWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_6dvZapxT, 0, m, &cVar_6dvZapxT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_10NZsCBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_TKsx8vgK, HV_BINOP_ADD, 1, m, &cBinop_TKsx8vgK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_PUmnbZdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_lDxmzN20, HV_BINOP_ADD, 1, m, &cBinop_lDxmzN20_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_yIVNSBBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KawC4KSw, HV_BINOP_ADD, 1, m, &cBinop_KawC4KSw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_pjOlmmlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jr6LZwf7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_KuCoZ30A_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HlRs69pI, 1, m, &cIf_HlRs69pI_sendMessage);
}

void Heavy_heavy::cBinop_jr6LZwf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pjOlmmlY, 1, m, &cVar_pjOlmmlY_sendMessage);
}

void Heavy_heavy::cIf_EuUYHRo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_RdjiQVmz_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vIFE5wRg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_RdjiQVmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TotUYRbN, 0, m, &cVar_TotUYRbN_sendMessage);
}

void Heavy_heavy::cVar_AAUKOtJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4cZdLDGl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EuUYHRo3, 0, m, &cIf_EuUYHRo3_sendMessage);
}

void Heavy_heavy::cUnop_vIFE5wRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TotUYRbN, 0, m, &cVar_TotUYRbN_sendMessage);
}

void Heavy_heavy::cBinop_4cZdLDGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EuUYHRo3, 1, m, &cIf_EuUYHRo3_sendMessage);
}

void Heavy_heavy::cVar_TotUYRbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bIlQLWIk, HV_BINOP_ADD, 1, m, &cBinop_bIlQLWIk_sendMessage);
}

void Heavy_heavy::cBinop_SukPTooh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_knDXQp99, 1, m, &cVar_knDXQp99_sendMessage);
}

void Heavy_heavy::cVar_knDXQp99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_SukPTooh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zci9dTZl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WhuRdAY5, 1, m, &cIf_WhuRdAY5_sendMessage);
}

void Heavy_heavy::cVar_2ZLSifkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pjOlmmlY, 0, m, &cVar_pjOlmmlY_sendMessage);
}

void Heavy_heavy::cVar_eG0kOid8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aO2ua2Hg, 0, m, &cVar_aO2ua2Hg_sendMessage);
}

void Heavy_heavy::cIf_R6rGvL8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_UNJBnliS, 0, m, &cIf_UNJBnliS_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_JPbjIKxA, 0, m, &cIf_JPbjIKxA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_WhuRdAY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_KawC4KSw, HV_BINOP_ADD, 0, m, &cBinop_KawC4KSw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_KawC4KSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UNJBnliS, 0, m, &cIf_UNJBnliS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JPbjIKxA, 0, m, &cIf_JPbjIKxA_sendMessage);
}

void Heavy_heavy::cBinop_zci9dTZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_R6rGvL8d, 1, m, &cIf_R6rGvL8d_sendMessage);
}

void Heavy_heavy::cVar_nn1kvdOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SZjNPmzS, 0, m, &cVar_SZjNPmzS_sendMessage);
}

void Heavy_heavy::cVar_j415Uijs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6dvZapxT, 0, m, &cVar_6dvZapxT_sendMessage);
}

void Heavy_heavy::cVar_BSZV6WPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_knDXQp99, 0, m, &cVar_knDXQp99_sendMessage);
}

void Heavy_heavy::cVar_VmbH6zF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hYDQ1CMA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zWBkiyXR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UNJBnliS, 1, m, &cIf_UNJBnliS_sendMessage);
}

void Heavy_heavy::cBinop_hYDQ1CMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VmbH6zF0, 1, m, &cVar_VmbH6zF0_sendMessage);
}

void Heavy_heavy::cBinop_oFe3zwRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.3f, 0, m, &cBinop_Nm5FLDLQ_sendMessage);
}

void Heavy_heavy::cReceive_cSqmjkP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_o6ZWoKc3_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Z51fcaiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.01f, 0, m, &cBinop_IyGIKS2j_sendMessage);
}

void Heavy_heavy::cCast_Jpas7pQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_gbtG4nJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wrfr2K1q, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_wrfr2K1q_sendMessage);
}

void Heavy_heavy::cVar_7ouTgYvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_x3VMTlO9_sendMessage);
}

void Heavy_heavy::cCast_It0eCqWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jpas7pQT_sendMessage);
}

void Heavy_heavy::cSwitchcase_miRRGs2t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_It0eCqWy_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eJ9qAGmg_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_uvgaYbJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qW6WcekT, 0, m, &cVar_qW6WcekT_sendMessage);
}

void Heavy_heavy::cVar_2Po7Y2of_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FBYpuo4s, 0, m, &cVar_FBYpuo4s_sendMessage);
}

void Heavy_heavy::cUnop_vaPuuZKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gbtG4nJQ, 0, m, &cVar_gbtG4nJQ_sendMessage);
}

void Heavy_heavy::cUnop_tsNKeGq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gbtG4nJQ, 0, m, &cVar_gbtG4nJQ_sendMessage);
}

void Heavy_heavy::cBinop_CRp2HePq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YllZtKCZ, 1, m, &cIf_YllZtKCZ_sendMessage);
}

void Heavy_heavy::cIf_YllZtKCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_tsNKeGq8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vaPuuZKK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_FBYpuo4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_CRp2HePq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YllZtKCZ, 0, m, &cIf_YllZtKCZ_sendMessage);
}

void Heavy_heavy::cVar_RfVMVWZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RgcAbrvN, HV_BINOP_ADD, 1, m, &cBinop_RgcAbrvN_sendMessage);
}

void Heavy_heavy::cBinop_RgcAbrvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSHeBHh5, HV_BINOP_MULTIPLY, 0, m, &cBinop_mSHeBHh5_sendMessage);
}

void Heavy_heavy::cBinop_x3VMTlO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ouTgYvS, 1, m, &cVar_7ouTgYvS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RgcAbrvN, HV_BINOP_ADD, 0, m, &cBinop_RgcAbrvN_sendMessage);
}

void Heavy_heavy::cBinop_zcHDhbW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_miRRGs2t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_ayLo2PDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qQ3x8cIm, 0, m, &cVar_qQ3x8cIm_sendMessage);
}

void Heavy_heavy::cIf_yTQxpBNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_qQVAhyHM_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yLnrFdmk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_yLnrFdmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uEdAiHAD, 0, m, &cVar_uEdAiHAD_sendMessage);
}

void Heavy_heavy::cBinop_2146pkRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yTQxpBNB, 1, m, &cIf_yTQxpBNB_sendMessage);
}

void Heavy_heavy::cVar_qQ3x8cIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_2146pkRu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yTQxpBNB, 0, m, &cIf_yTQxpBNB_sendMessage);
}

void Heavy_heavy::cUnop_qQVAhyHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uEdAiHAD, 0, m, &cVar_uEdAiHAD_sendMessage);
}

void Heavy_heavy::cVar_uEdAiHAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSHeBHh5, HV_BINOP_MULTIPLY, 1, m, &cBinop_mSHeBHh5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcHDhbW0, HV_BINOP_LESS_THAN, 1, m, &cBinop_zcHDhbW0_sendMessage);
}

void Heavy_heavy::cBinop_wrfr2K1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zcHDhbW0, HV_BINOP_LESS_THAN, 0, m, &cBinop_zcHDhbW0_sendMessage);
}

void Heavy_heavy::cBinop_mSHeBHh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wrfr2K1q, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_wrfr2K1q_sendMessage);
}

void Heavy_heavy::cIf_WvBnkA7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_b8TgIIik_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_s2QjWb9M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_s2QjWb9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RfVMVWZm, 0, m, &cVar_RfVMVWZm_sendMessage);
}

void Heavy_heavy::cBinop_etXsIUsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WvBnkA7Y, 1, m, &cIf_WvBnkA7Y_sendMessage);
}

void Heavy_heavy::cUnop_b8TgIIik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RfVMVWZm, 0, m, &cVar_RfVMVWZm_sendMessage);
}

void Heavy_heavy::cVar_qW6WcekT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_etXsIUsD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WvBnkA7Y, 0, m, &cIf_WvBnkA7Y_sendMessage);
}

void Heavy_heavy::cCast_eJ9qAGmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_knDXQp99, 0, m, &cVar_knDXQp99_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wyBEdDR5, 0, m, &cVar_wyBEdDR5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UykwUekv, 0, m, &cVar_UykwUekv_sendMessage);
}

void Heavy_heavy::cMsg_a7uS5hXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "seconds");
  cPrint_onMessage(_c, m, "print");
}

void Heavy_heavy::hTable_U0QkO85v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_RW8SxBIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjqZg0x, 2, m, &cDelay_ikjqZg0x_sendMessage);
}

void Heavy_heavy::cBinop_jzswjova_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mMven3lr, HV_BINOP_MULTIPLY, 1, m, &cBinop_mMven3lr_sendMessage);
}

void Heavy_heavy::cMsg_gKfHor0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjqZg0x, 0, m, &cDelay_ikjqZg0x_sendMessage);
}

void Heavy_heavy::cDelay_ikjqZg0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ikjqZg0x, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjqZg0x, 0, m, &cDelay_ikjqZg0x_sendMessage);
  cMsg_a7uS5hXC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_WLCICao8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jzswjova_sendMessage);
}

void Heavy_heavy::cMsg_6b26ud8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WLCICao8_sendMessage);
}

void Heavy_heavy::cVar_YCG6iO2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mMven3lr, HV_BINOP_MULTIPLY, 0, m, &cBinop_mMven3lr_sendMessage);
}

void Heavy_heavy::cCast_WoUk5Tos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gKfHor0f_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjqZg0x, 0, m, &cDelay_ikjqZg0x_sendMessage);
  cMsg_a7uS5hXC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_mMven3lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RW8SxBIH_sendMessage);
}

void Heavy_heavy::cSwitchcase_doZMasVg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_gKfHor0f_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_gKfHor0f_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WoUk5Tos_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_dCc0KM59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cUpAbVHt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cReceive_IuRHTbjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_G9BO8mSK_sendMessage);
}

void Heavy_heavy::cBinop_2UnJrFMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UhZmUrDD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JmJmAM8T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WIeqpjiP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WlHB4Hjg, 0, m, &cVar_WlHB4Hjg_sendMessage);
}

void Heavy_heavy::cCast_I9BOTtxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6hAZGc5k, HV_BINOP_NEQ, 0, m, &cBinop_6hAZGc5k_sendMessage);
}

void Heavy_heavy::cCast_x58gyiwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6hAZGc5k, HV_BINOP_NEQ, 1, m, &cBinop_6hAZGc5k_sendMessage);
}

void Heavy_heavy::cSlice_L6T9nbHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6hAZGc5k, HV_BINOP_NEQ, 1, m, &cBinop_6hAZGc5k_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_CmUw7Egz, 1, m, &cVar_CmUw7Egz_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6hAZGc5k, HV_BINOP_NEQ, 1, m, &cBinop_6hAZGc5k_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_CmUw7Egz, 1, m, &cVar_CmUw7Egz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_caIKr2nt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_CmUw7Egz, 0, m, &cVar_CmUw7Egz_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_CmUw7Egz, 0, m, &cVar_CmUw7Egz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Q7ofoU0n_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_caIKr2nt, 0, m, &cSlice_caIKr2nt_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L6T9nbHk, 0, m, &cSlice_L6T9nbHk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I9BOTtxX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cYy1pK4u_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_CmUw7Egz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_57Xf0ReC_sendMessage(_c, 0, m);
  cSend_OcAjESBi_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_1bXKxIuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x58gyiwE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6PHSWoZf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_cYy1pK4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1bXKxIuY, 0, m, &cIf_1bXKxIuY_sendMessage);
}

void Heavy_heavy::cBinop_6hAZGc5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1bXKxIuY, 1, m, &cIf_1bXKxIuY_sendMessage);
}

void Heavy_heavy::cCast_6PHSWoZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CmUw7Egz, 0, m, &cVar_CmUw7Egz_sendMessage);
}

void Heavy_heavy::cBinop_74HXDxuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_57Xf0ReC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_DWRy6qe6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_hw51oO1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cIf_4iFE98NT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ZpPk35zf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LwzT3Z7f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_ZpPk35zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uehGQS6E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_goSDW0cI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4iFE98NT, 1, m, &cIf_4iFE98NT_sendMessage);
}

void Heavy_heavy::cUnop_LwzT3Z7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uehGQS6E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_qrM4f8Oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_goSDW0cI_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4iFE98NT, 0, m, &cIf_4iFE98NT_sendMessage);
}

void Heavy_heavy::cBinop_sQb1vnIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pfFYVig0, 0, m, &cIf_pfFYVig0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_P0TQUvTn, 0, m, &cIf_P0TQUvTn_sendMessage);
}

void Heavy_heavy::cVar_eDaR5HPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GyG9FCZt, HV_BINOP_MULTIPLY, 1, m, &cBinop_GyG9FCZt_sendMessage);
}

void Heavy_heavy::cVar_lcN8Sf8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_57Xf0ReC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_WIeqpjiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lD95jVbd, 0, m, &cVar_lD95jVbd_sendMessage);
}

void Heavy_heavy::cSend_OcAjESBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bJ15F9bn_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_QsoSSGvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TSQ3UlVJ, 0, m, &cVar_TSQ3UlVJ_sendMessage);
}

void Heavy_heavy::cReceive_dZs3N4md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_kdYXPzPM_sendMessage);
}

void Heavy_heavy::cBinop_kI7y9gJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GxGIW44R, 0, m, &cVar_GxGIW44R_sendMessage);
}

void Heavy_heavy::cUnop_hWiiGyFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VLtjgZu7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_BcXDZxCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_p0yMqSOQ, 1, m, &cIf_p0yMqSOQ_sendMessage);
}

void Heavy_heavy::cUnop_wqToeZh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VLtjgZu7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_TSQ3UlVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BcXDZxCa_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_p0yMqSOQ, 0, m, &cIf_p0yMqSOQ_sendMessage);
}

void Heavy_heavy::cIf_p0yMqSOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_wqToeZh3_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hWiiGyFW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_jNEtJFVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c6XLbF46, HV_BINOP_MULTIPLY, 1, m, &cBinop_c6XLbF46_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XdAahnpH, HV_BINOP_LESS_THAN, 1, m, &cBinop_XdAahnpH_sendMessage);
}

void Heavy_heavy::cUnop_2tmEX0tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jNEtJFVm, 0, m, &cVar_jNEtJFVm_sendMessage);
}

void Heavy_heavy::cIf_qeFY664F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_2tmEX0tK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sypcOgAl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_cTesA9gE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qeFY664F, 1, m, &cIf_qeFY664F_sendMessage);
}

void Heavy_heavy::cVar_NWeLi6IM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cTesA9gE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qeFY664F, 0, m, &cIf_qeFY664F_sendMessage);
}

void Heavy_heavy::cUnop_sypcOgAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jNEtJFVm, 0, m, &cVar_jNEtJFVm_sendMessage);
}

void Heavy_heavy::cBinop_pPlptklM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c6XLbF46, HV_BINOP_MULTIPLY, 0, m, &cBinop_c6XLbF46_sendMessage);
}

void Heavy_heavy::cCast_DO0zgIDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pjOlmmlY, 0, m, &cVar_pjOlmmlY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SASkZ6xO, 0, m, &cVar_SASkZ6xO_sendMessage);
}

void Heavy_heavy::cVar_B01sV4Jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_i9nuD5M4, 0, m, &cVar_i9nuD5M4_sendMessage);
}

void Heavy_heavy::cBinop_XdAahnpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_83Ew7Y0x_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_0nBzd224_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MBsFA8IX_sendMessage);
}

void Heavy_heavy::cSwitchcase_83Ew7Y0x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0nBzd224_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DO0zgIDQ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_aj5qmvHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NWeLi6IM, 0, m, &cVar_NWeLi6IM_sendMessage);
}

void Heavy_heavy::cBinop_OVNAYOJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XdAahnpH, HV_BINOP_LESS_THAN, 0, m, &cBinop_XdAahnpH_sendMessage);
}

void Heavy_heavy::cCast_MBsFA8IX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cUnop_hGxyoBus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RIcdKMSS, 0, m, &cVar_RIcdKMSS_sendMessage);
}

void Heavy_heavy::cVar_i9nuD5M4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_fDBFxlVZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_F4sf3bHM, 0, m, &cIf_F4sf3bHM_sendMessage);
}

void Heavy_heavy::cUnop_JJbNoMoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RIcdKMSS, 0, m, &cVar_RIcdKMSS_sendMessage);
}

void Heavy_heavy::cBinop_fDBFxlVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F4sf3bHM, 1, m, &cIf_F4sf3bHM_sendMessage);
}

void Heavy_heavy::cIf_F4sf3bHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_JJbNoMoe_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hGxyoBus_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_CLeeNgbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n14oa6kc, 0, m, &cVar_n14oa6kc_sendMessage);
}

void Heavy_heavy::cVar_0lV07AAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPlptklM, HV_BINOP_ADD, 1, m, &cBinop_pPlptklM_sendMessage);
}

void Heavy_heavy::cBinop_c6XLbF46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OVNAYOJ6, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_OVNAYOJ6_sendMessage);
}

void Heavy_heavy::cBinop_PSrlcmxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bn4xjktz, 1, m, &cVar_Bn4xjktz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pPlptklM, HV_BINOP_ADD, 0, m, &cBinop_pPlptklM_sendMessage);
}

void Heavy_heavy::cVar_Bn4xjktz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PSrlcmxM_sendMessage);
}

void Heavy_heavy::cVar_RIcdKMSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OVNAYOJ6, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_OVNAYOJ6_sendMessage);
}

void Heavy_heavy::cIf_o9X5kPAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_3b4lhmND_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LwCNBHGT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_LwCNBHGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0lV07AAC, 0, m, &cVar_0lV07AAC_sendMessage);
}

void Heavy_heavy::cUnop_3b4lhmND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0lV07AAC, 0, m, &cVar_0lV07AAC_sendMessage);
}

void Heavy_heavy::cBinop_yDtuQ6vc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_o9X5kPAZ, 1, m, &cIf_o9X5kPAZ_sendMessage);
}

void Heavy_heavy::cVar_n14oa6kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yDtuQ6vc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_o9X5kPAZ, 0, m, &cIf_o9X5kPAZ_sendMessage);
}

void Heavy_heavy::cReceive_bJ15F9bn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_20CizADL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lapxelfS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.85f, 0, m, &cBinop_WsCbhFwM_sendMessage);
}

void Heavy_heavy::cCast_20CizADL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z51fcaiz, HV_BINOP_SUBTRACT, 1, m, &cBinop_Z51fcaiz_sendMessage);
}

void Heavy_heavy::cCast_jOzrLrcx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lD95jVbd, 1, m, &cVar_lD95jVbd_sendMessage);
}

void Heavy_heavy::cBinop_WsCbhFwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CuJmenzw, 0, m, &cVar_CuJmenzw_sendMessage);
}

void Heavy_heavy::cCast_f7h0VMyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ac9ajSm, HV_BINOP_SUBTRACT, 1, m, &cBinop_3ac9ajSm_sendMessage);
}

void Heavy_heavy::cBinop_rYavlpy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_f7h0VMyg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lG0jl6CN_sendMessage);
}

void Heavy_heavy::cMsg_qOFlMyAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_jbEW8diP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSlice_MmdnTktM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EDlr2Eef, 1, m, &cTabread_EDlr2Eef_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EDlr2Eef, 1, m, &cTabread_EDlr2Eef_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_jbEW8diP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MmdnTktM, 0, m, &cSlice_MmdnTktM_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bXVfTpG3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RVcNzpP6_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_bwqcwgHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEekCwEu, HV_BINOP_MIN, 0, m, &cBinop_LEekCwEu_sendMessage);
}

void Heavy_heavy::cCast_bXVfTpG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yvi7Troq, 0, m, &cVar_yvi7Troq_sendMessage);
}

void Heavy_heavy::cBinop_LEekCwEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_EDlr2Eef, 0, m, &cTabread_EDlr2Eef_sendMessage);
}

void Heavy_heavy::cVar_yvi7Troq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lL1IYbT4_sendMessage(_c, 0, m);
}

void Heavy_heavy::cTabread_EDlr2Eef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vvcv1u03, HV_BINOP_ADD, 0, m, &cBinop_vvcv1u03_sendMessage);
}

void Heavy_heavy::cCast_RVcNzpP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bwqcwgHd_sendMessage);
}

void Heavy_heavy::cBinop_2Lx3LZYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEekCwEu, HV_BINOP_MIN, 1, m, &cBinop_LEekCwEu_sendMessage);
}

void Heavy_heavy::cMsg_lL1IYbT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w4khJrpc_sendMessage);
}

void Heavy_heavy::cSystem_w4khJrpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2Lx3LZYW_sendMessage);
}

void Heavy_heavy::cBinop_vvcv1u03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Pc11PcoE_sendMessage);
}

void Heavy_heavy::cCast_cgwEsrWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eJhypDnt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_eJhypDnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_jbEW8diP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_TGQvta4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pOCU3R8S, 0, m, &cVar_pOCU3R8S_sendMessage);
}

void Heavy_heavy::cCast_yzzE2UPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qOFlMyAZ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_pOCU3R8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vvcv1u03, HV_BINOP_ADD, 1, m, &cBinop_vvcv1u03_sendMessage);
}

void Heavy_heavy::cVar_8J0ExYke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jbEW8diP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_mvLiMq5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_KypUBkh2_sendMessage);
}

void Heavy_heavy::cMsg_JeZmUV4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_NVGWvrdw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_5mr7Xlbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pd5F6mcp_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_sE2IeSdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mvLiMq5Q, HV_BINOP_ADD, 1, m, &cBinop_mvLiMq5Q_sendMessage);
}

void Heavy_heavy::cBinop_p5aGBtbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_a88RUqOb, 0, m, &cTabread_a88RUqOb_sendMessage);
}

void Heavy_heavy::cCast_IsLfhJOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CrvAC7lM_sendMessage);
}

void Heavy_heavy::cMsg_hwcIpgTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n43lAoS8_sendMessage);
}

void Heavy_heavy::cCast_9tobPPFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BNEly66K, 0, m, &cVar_BNEly66K_sendMessage);
}

void Heavy_heavy::cBinop_CrvAC7lM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5aGBtbu, HV_BINOP_MIN, 0, m, &cBinop_p5aGBtbu_sendMessage);
}

void Heavy_heavy::cBinop_05z7zIH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5aGBtbu, HV_BINOP_MIN, 1, m, &cBinop_p5aGBtbu_sendMessage);
}

void Heavy_heavy::cVar_BNEly66K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hwcIpgTT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSlice_IM6Sx14a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_a88RUqOb, 1, m, &cTabread_a88RUqOb_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_a88RUqOb, 1, m, &cTabread_a88RUqOb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_NVGWvrdw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IM6Sx14a, 0, m, &cSlice_IM6Sx14a_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9tobPPFW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IsLfhJOq_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSystem_n43lAoS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_05z7zIH1_sendMessage);
}

void Heavy_heavy::cTabread_a88RUqOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mvLiMq5Q, HV_BINOP_ADD, 0, m, &cBinop_mvLiMq5Q_sendMessage);
}

void Heavy_heavy::cVar_RItaQfha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NVGWvrdw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_pd5F6mcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_NVGWvrdw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_7qGJtJvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sE2IeSdC, 0, m, &cVar_sE2IeSdC_sendMessage);
}

void Heavy_heavy::cCast_sPVqnCKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JeZmUV4v_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_Tv5KKtwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bRLczDQ7, 0, m, &cVar_bRLczDQ7_sendMessage);
}

void Heavy_heavy::cMsg_oCVYxg7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4300.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3ac9ajSm, HV_BINOP_SUBTRACT, 0, m, &cBinop_3ac9ajSm_sendMessage);
}

void Heavy_heavy::cReceive_CWJGmjz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DWRy6qe6_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_LukbP4w5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xJOc7484_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_zVC3OchR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uE28QYNx, 1, m, &cVar_uE28QYNx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWx85PtL, HV_BINOP_ADD, 0, m, &cBinop_PWx85PtL_sendMessage);
}

void Heavy_heavy::cVar_k9ZHNgCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zVC3OchR, 0, m, &cVar_zVC3OchR_sendMessage);
}

void Heavy_heavy::cMsg_bo5Mt4dI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bOMI37vI, 0, m, &cDelay_bOMI37vI_sendMessage);
}

void Heavy_heavy::cCast_NlG6x5A9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bOMI37vI, 0, m, &cDelay_bOMI37vI_sendMessage);
}

void Heavy_heavy::cSwitchcase_p68JbJCA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_bo5Mt4dI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_bo5Mt4dI_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_bOMI37vI, 1, m, &cDelay_bOMI37vI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NlG6x5A9_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_bOMI37vI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bOMI37vI, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oQvNxFYw, 0, m, &cVar_oQvNxFYw_sendMessage);
}

void Heavy_heavy::cVar_xZVxXt9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Xsq517s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TjRNkgFK_sendMessage);
}

void Heavy_heavy::cVar_WlHB4Hjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xZVxXt9y, 0, m, &cVar_xZVxXt9y_sendMessage);
}

void Heavy_heavy::cVar_uE28QYNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A6KHe5Me_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_A6KHe5Me_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_guMEvnBQ, 0, m, NULL);
  cSwitchcase_qrG7j08m_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_guMEvnBQ, 0, m, NULL);
  cSwitchcase_qrG7j08m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_TjRNkgFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWx85PtL, HV_BINOP_ADD, 0, m, &cBinop_PWx85PtL_sendMessage);
}

void Heavy_heavy::cVar_oQvNxFYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HeSDOeXb_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_BqxkYEpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uE28QYNx, 0, m, &cVar_uE28QYNx_sendMessage);
}

void Heavy_heavy::cMsg_HeSDOeXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_guMEvnBQ, 0, m, NULL);
  cSwitchcase_qrG7j08m_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_guMEvnBQ, 0, m, NULL);
  cSwitchcase_qrG7j08m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_PWx85PtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bOMI37vI, 1, m, &cDelay_bOMI37vI_sendMessage);
}

void Heavy_heavy::cCast_I6zN5Ue6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_p68JbJCA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_Sef26veT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oQvNxFYw, 1, m, &cVar_oQvNxFYw_sendMessage);
}

void Heavy_heavy::cCast_9Xsq517s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWx85PtL, HV_BINOP_ADD, 1, m, &cBinop_PWx85PtL_sendMessage);
}

void Heavy_heavy::cVar_gtJOQ046_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sef26veT, 0, m, &cVar_Sef26veT_sendMessage);
}

void Heavy_heavy::cBinop_cb2Q6R8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4k4Z3EB7, 1, m, &cVar_4k4Z3EB7_sendMessage);
}

void Heavy_heavy::cBinop_xke1Tw8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_shFgFC92_sendMessage);
}

void Heavy_heavy::cCast_fqmr1M7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XkQ9GVSR, HV_BINOP_SUBTRACT, 0, m, &cBinop_XkQ9GVSR_sendMessage);
}

void Heavy_heavy::cMsg_NdnqvpVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_fxdS2O0E, 1, m, &cVar_fxdS2O0E_sendMessage);
}

void Heavy_heavy::cBinop_3lHInoAt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HKnuc32I_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_T2MAC6YL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xdUWyZ7m, HV_BINOP_MULTIPLY, 0, m, &cBinop_xdUWyZ7m_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ZJmPlMF, HV_BINOP_DIVIDE, 1, m, &cBinop_0ZJmPlMF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cfdPjPeZ, 0, m, &cVar_cfdPjPeZ_sendMessage);
}

void Heavy_heavy::cBinop_xdUWyZ7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TQAdRZoe_sendMessage);
}

void Heavy_heavy::cCast_dGpAsfqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YBFXWg8J_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_6ZEFERdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Zbxp5sZ1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_Lg05xyth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XxS5D4Q3, 0, m, &cVar_XxS5D4Q3_sendMessage);
}

void Heavy_heavy::cCast_8pptxEKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ZJmPlMF, HV_BINOP_DIVIDE, 0, m, &cBinop_0ZJmPlMF_sendMessage);
}

void Heavy_heavy::cMsg_7zLEj2GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Zbxp5sZ1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_gSHKfkdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xke1Tw8M, HV_BINOP_MULTIPLY, 0, m, &cBinop_xke1Tw8M_sendMessage);
}

void Heavy_heavy::cMsg_YBFXWg8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Zbxp5sZ1_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LP7PuyYZ, HV_BINOP_ADD, 1, m, &cBinop_LP7PuyYZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OAY3noe4, HV_BINOP_ADD, 1, m, &cBinop_OAY3noe4_sendMessage);
}

void Heavy_heavy::cVar_9Rxiod2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OAY3noe4, HV_BINOP_ADD, 0, m, &cBinop_OAY3noe4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LP7PuyYZ, HV_BINOP_ADD, 0, m, &cBinop_LP7PuyYZ_sendMessage);
}

void Heavy_heavy::cCast_2iABFMdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fxdS2O0E, 0, m, &cVar_fxdS2O0E_sendMessage);
}

void Heavy_heavy::cSlice_FpIY8gVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iJqFD0mF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wNQyRkWE_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iJqFD0mF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wNQyRkWE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_qrG7j08m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tHss6xCG, 0, m, &cSlice_tHss6xCG_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FpIY8gVw, 0, m, &cSlice_FpIY8gVw_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2iABFMdi_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lwLFKqNK, 0, m, &cSlice_lwLFKqNK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Uv7s5ls9, 0, m, &cSlice_Uv7s5ls9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kyzr01IC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hY31T7ee_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_tHss6xCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6ZEFERdp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_6ZEFERdp_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_hY31T7ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NdnqvpVm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_9dRIidrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cVagDws8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_ZVN9zaYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XxS5D4Q3, 1, m, &cVar_XxS5D4Q3_sendMessage);
}

void Heavy_heavy::cBinop_TQAdRZoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cb2Q6R8y, HV_BINOP_SUBTRACT, 1, m, &cBinop_cb2Q6R8y_sendMessage);
}

void Heavy_heavy::cMsg_vrQ1IoTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k3AZTfii_sendMessage);
}

void Heavy_heavy::cSystem_k3AZTfii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xdUWyZ7m, HV_BINOP_MULTIPLY, 1, m, &cBinop_xdUWyZ7m_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xke1Tw8M, HV_BINOP_MULTIPLY, 1, m, &cBinop_xke1Tw8M_sendMessage);
}

void Heavy_heavy::cVar_fh5yHqQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XkQ9GVSR, HV_BINOP_SUBTRACT, 1, m, &cBinop_XkQ9GVSR_sendMessage);
}

void Heavy_heavy::cBinop_0ZJmPlMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jY6aDgAH, HV_BINOP_DIVIDE, 1, m, &cBinop_jY6aDgAH_sendMessage);
}

void Heavy_heavy::cCast_Tln2UayH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YBFXWg8J_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_fxdS2O0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gSHKfkdw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8pptxEKN_sendMessage);
}

void Heavy_heavy::cVar_4k4Z3EB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cb2Q6R8y, HV_BINOP_SUBTRACT, 0, m, &cBinop_cb2Q6R8y_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_3lHInoAt_sendMessage);
}

void Heavy_heavy::cCast_wNQyRkWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dGpAsfqD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LP7PuyYZ, HV_BINOP_ADD, 0, m, &cBinop_LP7PuyYZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Rxiod2W, 1, m, &cVar_9Rxiod2W_sendMessage);
}

void Heavy_heavy::cBinop_LP7PuyYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fh5yHqQI, 0, m, &cVar_fh5yHqQI_sendMessage);
}

void Heavy_heavy::cCast_iJqFD0mF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6ZEFERdp_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_EvsiR8AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tln2UayH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Lg05xyth_sendMessage);
}

void Heavy_heavy::cCast_53aLVlqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Rxiod2W, 0, m, &cVar_9Rxiod2W_sendMessage);
}

void Heavy_heavy::cSwitchcase_HKnuc32I_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_53aLVlqJ_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EvsiR8AO_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cVar_XxS5D4Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Rxiod2W, 0, m, &cVar_9Rxiod2W_sendMessage);
}

void Heavy_heavy::cCast_vIddeBMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T2MAC6YL_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_cVagDws8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vIddeBMa_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_xdUWyZ7m, HV_BINOP_MULTIPLY, 0, m, &cBinop_xdUWyZ7m_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_0ZJmPlMF, HV_BINOP_DIVIDE, 1, m, &cBinop_0ZJmPlMF_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_cfdPjPeZ, 0, m, &cVar_cfdPjPeZ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_OAY3noe4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Rxiod2W, 1, m, &cVar_9Rxiod2W_sendMessage);
}

void Heavy_heavy::cBinop_jY6aDgAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LP7PuyYZ, HV_BINOP_ADD, 1, m, &cBinop_LP7PuyYZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OAY3noe4, HV_BINOP_ADD, 1, m, &cBinop_OAY3noe4_sendMessage);
}

void Heavy_heavy::cBinop_XkQ9GVSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jY6aDgAH, HV_BINOP_DIVIDE, 0, m, &cBinop_jY6aDgAH_sendMessage);
}

void Heavy_heavy::cSlice_Uv7s5ls9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZVN9zaYO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fqmr1M7t_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_lwLFKqNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gSHKfkdw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8pptxEKN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_yel7qcJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QFvKg0ah_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zyj4NXR, 0, m, &cDelay_8zyj4NXR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4k4Z3EB7, 0, m, &cVar_4k4Z3EB7_sendMessage);
}

void Heavy_heavy::cSwitchcase_Zbxp5sZ1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_QFvKg0ah_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_QFvKg0ah_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yel7qcJu_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_cv5FsR6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uBO1Zsqz, HV_BINOP_MULTIPLY, 1, m, &cBinop_uBO1Zsqz_sendMessage);
}

void Heavy_heavy::cBinop_uBO1Zsqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AVSozIn0_sendMessage);
}

void Heavy_heavy::cBinop_AVSozIn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zyj4NXR, 2, m, &cDelay_8zyj4NXR_sendMessage);
}

void Heavy_heavy::cVar_cfdPjPeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uBO1Zsqz, HV_BINOP_MULTIPLY, 0, m, &cBinop_uBO1Zsqz_sendMessage);
}

void Heavy_heavy::cSystem_FmpP4Dcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cv5FsR6k_sendMessage);
}

void Heavy_heavy::cMsg_tXJ3NAqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FmpP4Dcq_sendMessage);
}

void Heavy_heavy::cMsg_QFvKg0ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zyj4NXR, 0, m, &cDelay_8zyj4NXR_sendMessage);
}

void Heavy_heavy::cDelay_8zyj4NXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8zyj4NXR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8zyj4NXR, 0, m, &cDelay_8zyj4NXR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4k4Z3EB7, 0, m, &cVar_4k4Z3EB7_sendMessage);
}

void Heavy_heavy::cCast_Kyzr01IC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7zLEj2GB_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_shFgFC92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4k4Z3EB7, 1, m, &cVar_4k4Z3EB7_sendMessage);
}

void Heavy_heavy::cCast_aMSxSZ1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eDaR5HPm, 0, m, &cVar_eDaR5HPm_sendMessage);
}

void Heavy_heavy::cVar_NQ9J1uqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OcAjESBi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hw51oO1H, 0, m, &cVar_hw51oO1H_sendMessage);
}

void Heavy_heavy::cVar_lD95jVbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GyG9FCZt, HV_BINOP_MULTIPLY, 0, m, &cBinop_GyG9FCZt_sendMessage);
}

void Heavy_heavy::cReceive_FetctBQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4000.0f, 0, m, &cBinop_rYavlpy1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_oFe3zwRv_sendMessage);
}

void Heavy_heavy::cBinop_K5qbb3Yu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6dvZapxT, 0, m, &cVar_6dvZapxT_sendMessage);
}

void Heavy_heavy::cBinop_7x02yqZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0xEUmL7c, HV_BINOP_MULTIPLY, 1, m, &cBinop_0xEUmL7c_sendMessage);
}

void Heavy_heavy::cSwitchcase_b2WH8g5x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_3idc3s1h_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3idc3s1h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pC4Vb8mW_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_YON3gtbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0xEUmL7c, HV_BINOP_MULTIPLY, 0, m, &cBinop_0xEUmL7c_sendMessage);
}

void Heavy_heavy::cDelay_c4EAXaDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c4EAXaDo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c4EAXaDo, 0, m, &cDelay_c4EAXaDo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kwNOPpYG_sendMessage);
}

void Heavy_heavy::cMsg_3idc3s1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_c4EAXaDo, 0, m, &cDelay_c4EAXaDo_sendMessage);
}

void Heavy_heavy::cMsg_IiYDcVqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j5DCGcwn_sendMessage);
}

void Heavy_heavy::cSystem_j5DCGcwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7x02yqZ1_sendMessage);
}

void Heavy_heavy::cBinop_EztVOAZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c4EAXaDo, 2, m, &cDelay_c4EAXaDo_sendMessage);
}

void Heavy_heavy::cBinop_0xEUmL7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_EztVOAZJ_sendMessage);
}

void Heavy_heavy::cCast_pC4Vb8mW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3idc3s1h_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c4EAXaDo, 0, m, &cDelay_c4EAXaDo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kwNOPpYG_sendMessage);
}

void Heavy_heavy::cVar_ueUtxUWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_C9S0GlO0_sendMessage);
  cSwitchcase_sMSIh8AS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_C9S0GlO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ueUtxUWR, 1, m, &cVar_ueUtxUWR_sendMessage);
}

void Heavy_heavy::cBinop_RTLZOsoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_V6IcHZyh_sendMessage);
}

void Heavy_heavy::cBinop_VblEj1sH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTLZOsoO, HV_BINOP_MULTIPLY, 1, m, &cBinop_RTLZOsoO_sendMessage);
}

void Heavy_heavy::cDelay_86VXIZjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_86VXIZjU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86VXIZjU, 0, m, &cDelay_86VXIZjU_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_edTKF4fo, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_qAl5spUM, 1, m);
}

void Heavy_heavy::cSwitchcase_sMSIh8AS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_KQRpww7x_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KQRpww7x_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XECkpWZq_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSystem_UYUomxm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VblEj1sH_sendMessage);
}

void Heavy_heavy::cMsg_8y7YoBLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UYUomxm3_sendMessage);
}

void Heavy_heavy::cCast_XECkpWZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQRpww7x_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_86VXIZjU, 0, m, &cDelay_86VXIZjU_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_edTKF4fo, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_qAl5spUM, 1, m);
}

void Heavy_heavy::cBinop_V6IcHZyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_86VXIZjU, 2, m, &cDelay_86VXIZjU_sendMessage);
}

void Heavy_heavy::cVar_agvT9Tmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTLZOsoO, HV_BINOP_MULTIPLY, 0, m, &cBinop_RTLZOsoO_sendMessage);
}

void Heavy_heavy::cMsg_KQRpww7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_86VXIZjU, 0, m, &cDelay_86VXIZjU_sendMessage);
}

void Heavy_heavy::cBinop_XQDm7ks3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uFV16IwN, 1, m, &cIf_uFV16IwN_sendMessage);
}

void Heavy_heavy::cUnop_eW7MbsGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cUnop_tXSCPodM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cIf_uFV16IwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_eW7MbsGg_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tXSCPodM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_ztmqpwyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_XQDm7ks3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_uFV16IwN, 0, m, &cIf_uFV16IwN_sendMessage);
}

void Heavy_heavy::cMsg_fjBmrswq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ic7e0dC, HV_BINOP_DIVIDE, 0, m, &cBinop_7ic7e0dC_sendMessage);
}

void Heavy_heavy::sSample_qAl5spUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_RXcurFFO_sendMessage);
}

void Heavy_heavy::cVar_AqHxkhYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xPRy3Lpy, 0, m, &cVar_xPRy3Lpy_sendMessage);
}

void Heavy_heavy::sSample_edTKF4fo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yo2enpsk_sendMessage);
}

void Heavy_heavy::cCast_4CXfkibN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fjBmrswq_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_RXcurFFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_v4KnXPkN_sendMessage);
}

void Heavy_heavy::cCast_AT83GqB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ic7e0dC, HV_BINOP_DIVIDE, 1, m, &cBinop_7ic7e0dC_sendMessage);
}

void Heavy_heavy::cBinop_EiMo6vOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_BHJuZSFb_sendMessage);
}

void Heavy_heavy::cVar_xPRy3Lpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XMZqnQ5Z_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YON3gtbV, 0, m, &cVar_YON3gtbV_sendMessage);
  cSwitchcase_ytM9jepY_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_ztmqpwyc, 1, m, &cVar_ztmqpwyc_sendMessage);
}

void Heavy_heavy::cVar_TV8wuBl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_WSBsvB3i_sendMessage);
  cSwitchcase_b2WH8g5x_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_WSBsvB3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TV8wuBl4, 1, m, &cVar_TV8wuBl4_sendMessage);
}

void Heavy_heavy::cBinop_7ic7e0dC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_2GqOF3Jf, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9f9VaZZz, 0, m);
}

void Heavy_heavy::cBinop_v4KnXPkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cDelay_hQkBF2WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hQkBF2WW, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ztmqpwyc, 0, m, &cVar_ztmqpwyc_sendMessage);
}

void Heavy_heavy::cMsg_YJLZKQYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQkBF2WW, 0, m, &cDelay_hQkBF2WW_sendMessage);
}

void Heavy_heavy::cCast_wk4M2PvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hQkBF2WW, 0, m, &cDelay_hQkBF2WW_sendMessage);
}

void Heavy_heavy::cSwitchcase_ytM9jepY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_YJLZKQYD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_YJLZKQYD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hQkBF2WW, 1, m, &cDelay_hQkBF2WW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wk4M2PvH_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_XMZqnQ5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AT83GqB4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4CXfkibN_sendMessage);
}

void Heavy_heavy::cBinop_yo2enpsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_EiMo6vOX_sendMessage);
}

void Heavy_heavy::cCast_kwNOPpYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bn4xjktz, 0, m, &cVar_Bn4xjktz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lz6quDWx, 0, m, &cVar_lz6quDWx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5v5nRLK3, 0, m, &cVar_5v5nRLK3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7ouTgYvS, 0, m, &cVar_7ouTgYvS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k4sHureO, 0, m, &cVar_k4sHureO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BqxkYEpV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I6zN5Ue6_sendMessage);
}

void Heavy_heavy::cBinop_Ohjkhzu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Q7ofoU0n_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_7f5BBN13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gtJOQ046, 0, m, &cVar_gtJOQ046_sendMessage);
}

void Heavy_heavy::cBinop_9I5MAlTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xJOc7484_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_UhZmUrDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eDaR5HPm, 1, m, &cVar_eDaR5HPm_sendMessage);
}

void Heavy_heavy::cVar_0QJ2aCi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_57Xf0ReC_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSend_xsDWGCEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_WpWHxzo2_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Nm5FLDLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kKPrhRZJ, 0, m, &cVar_kKPrhRZJ_sendMessage);
}

void Heavy_heavy::cReceive_WpWHxzo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 512.0f, 0, m, &cBinop_dCc0KM59_sendMessage);
}

void Heavy_heavy::cBinop_Wti1wrxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OcAjESBi_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_MMDz5aVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xsDWGCEl_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_aNKDMw3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_BHJuZSFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_pYKoIh14_sendMessage);
}

void Heavy_heavy::cBinop_Sgqstl7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aefk6a2h, 0, m, &cVar_aefk6a2h_sendMessage);
}

void Heavy_heavy::cBinop_GyG9FCZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k9ZHNgCv, 0, m, &cVar_k9ZHNgCv_sendMessage);
}

void Heavy_heavy::cCast_fe9Z07Jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1EaqnUEF, HV_BINOP_NEQ, 0, m, &cBinop_1EaqnUEF_sendMessage);
}

void Heavy_heavy::cCast_ariGUCn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1EaqnUEF, HV_BINOP_NEQ, 1, m, &cBinop_1EaqnUEF_sendMessage);
}

void Heavy_heavy::cVar_0RAifqMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xJOc7484_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_VGqUgLTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_638AkvaS, 0, m, &cIf_638AkvaS_sendMessage);
}

void Heavy_heavy::cIf_638AkvaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ariGUCn1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7b5Jug01_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_YSvjarBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_0RAifqMr, 0, m, &cVar_0RAifqMr_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_0RAifqMr, 0, m, &cVar_0RAifqMr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_Zj8GDv9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1EaqnUEF, HV_BINOP_NEQ, 1, m, &cBinop_1EaqnUEF_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_0RAifqMr, 1, m, &cVar_0RAifqMr_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1EaqnUEF, HV_BINOP_NEQ, 1, m, &cBinop_1EaqnUEF_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_0RAifqMr, 1, m, &cVar_0RAifqMr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_cUpAbVHt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YSvjarBJ, 0, m, &cSlice_YSvjarBJ_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Zj8GDv9j, 0, m, &cSlice_Zj8GDv9j_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fe9Z07Jl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VGqUgLTZ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_1EaqnUEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_638AkvaS, 1, m, &cIf_638AkvaS_sendMessage);
}

void Heavy_heavy::cCast_7b5Jug01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0RAifqMr, 0, m, &cVar_0RAifqMr_sendMessage);
}

void Heavy_heavy::cVar_sl9yd5dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_PaEeir23_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2GtGCKd7, 0, m, &cIf_2GtGCKd7_sendMessage);
}

void Heavy_heavy::cUnop_0dGG0j33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ek1p8TEJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_2GtGCKd7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Ku498MeJ_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0dGG0j33_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_PaEeir23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2GtGCKd7, 1, m, &cIf_2GtGCKd7_sendMessage);
}

void Heavy_heavy::cUnop_Ku498MeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Ek1p8TEJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_JJ7x5EZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J9VQSDKC, HV_BINOP_NEQ, 0, m, &cBinop_J9VQSDKC_sendMessage);
}

void Heavy_heavy::cCast_X5LXHu8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J9VQSDKC, HV_BINOP_NEQ, 1, m, &cBinop_J9VQSDKC_sendMessage);
}

void Heavy_heavy::cIf_O4uJT3Fn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X5LXHu8z_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yia02SRX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_WoOrIJ4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O4uJT3Fn, 0, m, &cIf_O4uJT3Fn_sendMessage);
}

void Heavy_heavy::cVar_WVl0AIgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_74HXDxuQ_sendMessage);
}

void Heavy_heavy::cBinop_J9VQSDKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O4uJT3Fn, 1, m, &cIf_O4uJT3Fn_sendMessage);
}

void Heavy_heavy::cSlice_RMSHrI0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_WVl0AIgo, 0, m, &cVar_WVl0AIgo_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_WVl0AIgo, 0, m, &cVar_WVl0AIgo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_VLtjgZu7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RMSHrI0a, 0, m, &cSlice_RMSHrI0a_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SYEwHO8k, 0, m, &cSlice_SYEwHO8k_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JJ7x5EZ8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WoOrIJ4B_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_SYEwHO8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J9VQSDKC, HV_BINOP_NEQ, 1, m, &cBinop_J9VQSDKC_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_WVl0AIgo, 1, m, &cVar_WVl0AIgo_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J9VQSDKC, HV_BINOP_NEQ, 1, m, &cBinop_J9VQSDKC_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_WVl0AIgo, 1, m, &cVar_WVl0AIgo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_Yia02SRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WVl0AIgo, 0, m, &cVar_WVl0AIgo_sendMessage);
}

void Heavy_heavy::hTable_JTeuf71H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_yvFsrB9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_kI7y9gJr_sendMessage);
}

void Heavy_heavy::cCast_lG0jl6CN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oCVYxg7i_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_lz6quDWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sPm4NPIm_sendMessage);
}

void Heavy_heavy::cIf_b4ihePSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_chWZ5Bd8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ADLnUels_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_3LTRHDad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_psy8wH8d_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b4ihePSs, 0, m, &cIf_b4ihePSs_sendMessage);
}

void Heavy_heavy::cUnop_chWZ5Bd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pbc93Fjo, 0, m, &cVar_pbc93Fjo_sendMessage);
}

void Heavy_heavy::cBinop_psy8wH8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b4ihePSs, 1, m, &cIf_b4ihePSs_sendMessage);
}

void Heavy_heavy::cUnop_ADLnUels_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pbc93Fjo, 0, m, &cVar_pbc93Fjo_sendMessage);
}

void Heavy_heavy::cIf_EEbU73L0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_jlpdmXx6_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uWQxTego_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_uWQxTego_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b8ODhJAw, 0, m, &cVar_b8ODhJAw_sendMessage);
}

void Heavy_heavy::cVar_peDzFdkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_W0U9vUt3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EEbU73L0, 0, m, &cIf_EEbU73L0_sendMessage);
}

void Heavy_heavy::cUnop_jlpdmXx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b8ODhJAw, 0, m, &cVar_b8ODhJAw_sendMessage);
}

void Heavy_heavy::cBinop_W0U9vUt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EEbU73L0, 1, m, &cIf_EEbU73L0_sendMessage);
}

void Heavy_heavy::cCast_ogpPh5Zm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WFUjGhy9_sendMessage);
}

void Heavy_heavy::cSwitchcase_AwN44lmN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ogpPh5Zm_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ViAWNbu9_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_7WMYNBhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Kj1QHhjZ, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_Kj1QHhjZ_sendMessage);
}

void Heavy_heavy::cBinop_otTeFKP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AwN44lmN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_FgFvW6sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7WMYNBhk, HV_BINOP_MULTIPLY, 0, m, &cBinop_7WMYNBhk_sendMessage);
}

void Heavy_heavy::cVar_gTM1XzJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3LTRHDad, 0, m, &cVar_3LTRHDad_sendMessage);
}

void Heavy_heavy::cVar_b8ODhJAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7WMYNBhk, HV_BINOP_MULTIPLY, 1, m, &cBinop_7WMYNBhk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_otTeFKP7, HV_BINOP_LESS_THAN, 1, m, &cBinop_otTeFKP7_sendMessage);
}

void Heavy_heavy::cBinop_Kj1QHhjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_otTeFKP7, HV_BINOP_LESS_THAN, 0, m, &cBinop_otTeFKP7_sendMessage);
}

void Heavy_heavy::cVar_zrkQD840_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JdXChY71, 0, m, &cVar_JdXChY71_sendMessage);
}

void Heavy_heavy::cVar_NwJ5ff8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_peDzFdkM, 0, m, &cVar_peDzFdkM_sendMessage);
}

void Heavy_heavy::cCast_WFUjGhy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_sPm4NPIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lz6quDWx, 1, m, &cVar_lz6quDWx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgFvW6sk, HV_BINOP_ADD, 0, m, &cBinop_FgFvW6sk_sendMessage);
}

void Heavy_heavy::cCast_ViAWNbu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SZjNPmzS, 0, m, &cVar_SZjNPmzS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VmbH6zF0, 0, m, &cVar_VmbH6zF0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9YHBWDCD, 0, m, &cVar_9YHBWDCD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YHIXfR7E, 0, m, &cVar_YHIXfR7E_sendMessage);
}

void Heavy_heavy::cVar_H7bfD5Qv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FgFvW6sk, HV_BINOP_ADD, 1, m, &cBinop_FgFvW6sk_sendMessage);
}

void Heavy_heavy::cUnop_tzSIB4or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H7bfD5Qv, 0, m, &cVar_H7bfD5Qv_sendMessage);
}

void Heavy_heavy::cVar_JdXChY71_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_kfhpYtkc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RGUfpXmY, 0, m, &cIf_RGUfpXmY_sendMessage);
}

void Heavy_heavy::cBinop_kfhpYtkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RGUfpXmY, 1, m, &cIf_RGUfpXmY_sendMessage);
}

void Heavy_heavy::cUnop_Mz0QzVUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H7bfD5Qv, 0, m, &cVar_H7bfD5Qv_sendMessage);
}

void Heavy_heavy::cIf_RGUfpXmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_tzSIB4or_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Mz0QzVUj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_pbc93Fjo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Kj1QHhjZ, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_Kj1QHhjZ_sendMessage);
}

void Heavy_heavy::cIf_pfFYVig0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gjx08Tt8, HV_BINOP_ADD, 0, m, &cBinop_gjx08Tt8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_P0TQUvTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_K166pFsk, 0, m, &cIf_K166pFsk_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_uTcd2IoC, 0, m, &cIf_uTcd2IoC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_bZuXQVrR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P0TQUvTn, 1, m, &cIf_P0TQUvTn_sendMessage);
}

void Heavy_heavy::cBinop_gjx08Tt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K166pFsk, 0, m, &cIf_K166pFsk_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_uTcd2IoC, 0, m, &cIf_uTcd2IoC_sendMessage);
}

void Heavy_heavy::cBinop_ysNIM0h6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YHIXfR7E, 1, m, &cVar_YHIXfR7E_sendMessage);
}

void Heavy_heavy::cVar_YHIXfR7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ysNIM0h6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IFBYp79Q_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pg4JH6LD, 1, m, &cIf_pg4JH6LD_sendMessage);
}

void Heavy_heavy::cVar_Vqy7sWFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SASkZ6xO, 0, m, &cVar_SASkZ6xO_sendMessage);
}

void Heavy_heavy::cVar_KQj7gkvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rl7z6SIW, 0, m, &cVar_Rl7z6SIW_sendMessage);
}

void Heavy_heavy::cIf_m6nadAYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gPzJXbci, HV_BINOP_ADD, 0, m, &cBinop_gPzJXbci_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_gPzJXbci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jcsCOvkn, 0, m, &cIf_jcsCOvkn_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fKzpBxOC, 0, m, &cIf_fKzpBxOC_sendMessage);
}

void Heavy_heavy::cIf_THyz76oG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_jcsCOvkn, 0, m, &cIf_jcsCOvkn_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_fKzpBxOC, 0, m, &cIf_fKzpBxOC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_qE8PQxq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_THyz76oG, 1, m, &cIf_THyz76oG_sendMessage);
}

void Heavy_heavy::cBinop_unO1PR5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fKzpBxOC, 1, m, &cIf_fKzpBxOC_sendMessage);
}

void Heavy_heavy::cIf_fKzpBxOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_pg4JH6LD, 0, m, &cIf_pg4JH6LD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_oBjKSRcf, 0, m, &cIf_oBjKSRcf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_vkGW9UTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pg4JH6LD, 0, m, &cIf_pg4JH6LD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_oBjKSRcf, 0, m, &cIf_oBjKSRcf_sendMessage);
}

void Heavy_heavy::cIf_jcsCOvkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vkGW9UTI, HV_BINOP_ADD, 0, m, &cBinop_vkGW9UTI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_k0MEwwFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KQj7gkvH, 0, m, &cVar_KQj7gkvH_sendMessage);
}

void Heavy_heavy::cVar_kH0Vmvao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YHIXfR7E, 0, m, &cVar_YHIXfR7E_sendMessage);
}

void Heavy_heavy::cVar_xsLdMY1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UIv9RwWh, 0, m, &cVar_UIv9RwWh_sendMessage);
}

void Heavy_heavy::cIf_uTcd2IoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_m6nadAYg, 0, m, &cIf_m6nadAYg_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_THyz76oG, 0, m, &cIf_THyz76oG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_K166pFsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_o57cKi3C, HV_BINOP_ADD, 0, m, &cBinop_o57cKi3C_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Gb4GQ72T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uTcd2IoC, 1, m, &cIf_uTcd2IoC_sendMessage);
}

void Heavy_heavy::cBinop_o57cKi3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_m6nadAYg, 0, m, &cIf_m6nadAYg_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_THyz76oG, 0, m, &cIf_THyz76oG_sendMessage);
}

void Heavy_heavy::cBinop_Som3vwRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hk4dwMnA, 1, m, &cVar_Hk4dwMnA_sendMessage);
}

void Heavy_heavy::cVar_Hk4dwMnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Som3vwRC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Gb4GQ72T_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_K166pFsk, 1, m, &cIf_K166pFsk_sendMessage);
}

void Heavy_heavy::cBinop_dXgEgClO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UIv9RwWh, 1, m, &cVar_UIv9RwWh_sendMessage);
}

void Heavy_heavy::cVar_UIv9RwWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_dXgEgClO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_unO1PR5E_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_jcsCOvkn, 1, m, &cIf_jcsCOvkn_sendMessage);
}

void Heavy_heavy::cIf_oBjKSRcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_RItaQfha, 0, m, &cVar_RItaQfha_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_3Um51HvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RItaQfha, 0, m, &cVar_RItaQfha_sendMessage);
}

void Heavy_heavy::cBinop_IFBYp79Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oBjKSRcf, 1, m, &cIf_oBjKSRcf_sendMessage);
}

void Heavy_heavy::cIf_pg4JH6LD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_3Um51HvY, HV_BINOP_ADD, 0, m, &cBinop_3Um51HvY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_UykwUekv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_C70uDdNz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bZuXQVrR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pfFYVig0, 1, m, &cIf_pfFYVig0_sendMessage);
}

void Heavy_heavy::cBinop_C70uDdNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UykwUekv, 1, m, &cVar_UykwUekv_sendMessage);
}

void Heavy_heavy::cVar_CYbKrDzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Um51HvY, HV_BINOP_ADD, 1, m, &cBinop_3Um51HvY_sendMessage);
}

void Heavy_heavy::cVar_SASkZ6xO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mBJtYaoK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qE8PQxq8_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_m6nadAYg, 1, m, &cIf_m6nadAYg_sendMessage);
}

void Heavy_heavy::cBinop_mBJtYaoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SASkZ6xO, 1, m, &cVar_SASkZ6xO_sendMessage);
}

void Heavy_heavy::cIf_4VT2aL8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_DaQn7uPf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ART9zefq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_ART9zefq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CYbKrDzS, 0, m, &cVar_CYbKrDzS_sendMessage);
}

void Heavy_heavy::cUnop_DaQn7uPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CYbKrDzS, 0, m, &cVar_CYbKrDzS_sendMessage);
}

void Heavy_heavy::cBinop_WQhv4WH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4VT2aL8Y, 1, m, &cIf_4VT2aL8Y_sendMessage);
}

void Heavy_heavy::cVar_Rl7z6SIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WQhv4WH6_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4VT2aL8Y, 0, m, &cIf_4VT2aL8Y_sendMessage);
}

void Heavy_heavy::cVar_eRRLtrKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UykwUekv, 0, m, &cVar_UykwUekv_sendMessage);
}

void Heavy_heavy::cVar_PBjuHVKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Hk4dwMnA, 0, m, &cVar_Hk4dwMnA_sendMessage);
}

void Heavy_heavy::cSlice_jvtIUQOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gPzJXbci, HV_BINOP_ADD, 1, m, &cBinop_gPzJXbci_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_VT2fAI8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_o57cKi3C, HV_BINOP_ADD, 1, m, &cBinop_o57cKi3C_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_NQrGqvyT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_KQj7gkvH, 0, m, &cVar_KQj7gkvH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_FmWbMyMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gjx08Tt8, HV_BINOP_ADD, 1, m, &cBinop_gjx08Tt8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_YBS5SZX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_vkGW9UTI, HV_BINOP_ADD, 1, m, &cBinop_vkGW9UTI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_UXw2W5jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 3.0f, 0, m, &cBinop_K5qbb3Yu_sendMessage);
}

void Heavy_heavy::cCast_FsiWjSjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lD95jVbd, 0, m, &cVar_lD95jVbd_sendMessage);
}

void Heavy_heavy::cBinop_kdYXPzPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qrM4f8Oy, 0, m, &cVar_qrM4f8Oy_sendMessage);
}

void Heavy_heavy::cCast_9Yp7tVJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2dqV5kS, HV_BINOP_NEQ, 1, m, &cBinop_D2dqV5kS_sendMessage);
}

void Heavy_heavy::cCast_Qn4uD7xk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lgULjGQx, 0, m, &cIf_lgULjGQx_sendMessage);
}

void Heavy_heavy::cIf_lgULjGQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Yp7tVJt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X3Xs0n4K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_D2dqV5kS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lgULjGQx, 1, m, &cIf_lgULjGQx_sendMessage);
}

void Heavy_heavy::cSlice_17yxP2IL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_D2dqV5kS, HV_BINOP_NEQ, 1, m, &cBinop_D2dqV5kS_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_fNSHAqM9, 1, m, &cVar_fNSHAqM9_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_D2dqV5kS, HV_BINOP_NEQ, 1, m, &cBinop_D2dqV5kS_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_fNSHAqM9, 1, m, &cVar_fNSHAqM9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Ek1p8TEJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1SESET9R, 0, m, &cSlice_1SESET9R_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_17yxP2IL, 0, m, &cSlice_17yxP2IL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hL8T0QBI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qn4uD7xk_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_1SESET9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_fNSHAqM9, 0, m, &cVar_fNSHAqM9_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_fNSHAqM9, 0, m, &cVar_fNSHAqM9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_fNSHAqM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_Wti1wrxv_sendMessage);
}

void Heavy_heavy::cCast_X3Xs0n4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fNSHAqM9, 0, m, &cVar_fNSHAqM9_sendMessage);
}

void Heavy_heavy::cCast_hL8T0QBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D2dqV5kS, HV_BINOP_NEQ, 0, m, &cBinop_D2dqV5kS_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_wSSGD0Xd, VOf(Bf0));
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
    __hv_add_f(VIf(Bf1), VIf(O2), VOf(O2));
    __hv_phasor_k_f(&sPhasor_9f9VaZZz, VOf(Bf1));
    __hv_sample_f(this, &sSample_edTKF4fo, VIf(Bf1), &sSample_edTKF4fo_sendMessage);
    __hv_phasor_k_f(&sPhasor_2GqOF3Jf, VOf(Bf1));
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
    __hv_sample_f(this, &sSample_qAl5spUM, VIf(Bf3), &sSample_qAl5spUM_sendMessage);
    __hv_varread_i(&sVari_bo0HZB9X, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_i(&sVari_bo0HZB9X, VIi(Bi1));
    __hv_varread_f(&sVarf_sFhIrLR3, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_h0vI4JZ4, VOf(Bf1));
    __hv_rpole_f(&sRPole_yOTRCNyJ, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_VPYhqf06, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_sn9f3amk, VOf(Bf1));
    __hv_phasor_f(&sPhasor_rU4Cm8dJ, VIf(Bf1), VOf(Bf1));
    __hv_del1_f(&sDel1_4TbZzwrI, VIf(Bf1), VOf(Bf2));
    __hv_lt_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_4mOmGPho, VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Pn3qQNEP, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_oerzrKYy, VOf(Bf2));
    __hv_rpole_f(&sRPole_K6zEJEjT, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sample_f(this, &sSample_PDIAlkr7, VIf(Bf2), &sSample_PDIAlkr7_sendMessage);
    __hv_line_f(&sLine_BMXeaKXg, VOf(Bf3));
    __hv_phasor_f(&sPhasor_jSH94YTy, VIf(Bf3), VOf(Bf3));
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
    __hv_var_k_f(VOf(Bf1), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_0hXKgL4Z, VOf(Bf1));
    __hv_phasor_f(&sPhasor_zIumMJN0, VIf(Bf1), VOf(Bf1));
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
    __hv_var_k_f(VOf(Bf2), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_AT1wwnAQ, VOf(Bf4));
    __hv_phasor_f(&sPhasor_CQ8I2XVO, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f, 0.33f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_guMEvnBQ, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_65KpTKWm, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_tOV26FHG, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_85Df0DyD, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_xbwgOrp9, VOf(Bf0));
    __hv_min_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_VpyJNL6E, VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_LMYQWsCA, VIi(Bi0), VOf(Bf1));
    __hv_tabread_if(&sTabread_C9EutCgU, VIi(Bi1), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Lffvq5eY, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_TKvbnSRQ, VOf(Bf0));
    __hv_rpole_f(&sRPole_nwRDX9SF, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_l3BVLLxT, VOf(Bf4));
    __hv_varread_f(&sVarf_dVoQ13Lm, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xY8JzL2h, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_qW5cWS0w, VIf(Bf4));
    __hv_tabhead_f(&sTabhead_jxL5XbmA, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_K2PfNK9i, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_F5C1ex7B, VOf(Bf3));
    __hv_min_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_varread_f(&sVarf_7wyd5DQc, VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_neMovKfS, VIi(Bi0), VOf(Bf5));
    __hv_tabread_if(&sTabread_cMO9O1SX, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_lPWjPcnk, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_nfGasZoY, VOf(Bf3));
    __hv_rpole_f(&sRPole_UJrbnYAz, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_zXuKHf3p, VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_tabwrite_f(&sTabwrite_xGINu7jN, VIf(Bf0));
    __hv_varread_f(&sVarf_gV74UEaB, VOf(Bf0));
    __hv_varread_f(&sVarf_WkBZvjmm, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

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
