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

float hTable_Mt9UjRaD_data[128] = {0.0f, 2.0f, 2.0f, 3.0f, 3.0f, 5.0f, 5.0f, 7.0f, 9.0f, 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 15.0f, 15.0f, 17.0f, 17.0f, 19.0f, 21.0f, 22.0f, 22.0f, 24.0f, 26.0f, 26.0f, 27.0f, 27.0f, 29.0f, 29.0f, 31.0f, 33.0f, 34.0f, 34.0f, 36.0f, 38.0f, 38.0f, 39.0f, 39.0f, 41.0f, 41.0f, 43.0f, 45.0f, 46.0f, 46.0f, 48.0f, 50.0f, 50.0f, 51.0f, 51.0f, 53.0f, 53.0f, 55.0f, 57.0f, 58.0f, 58.0f, 60.0f, 62.0f, 62.0f, 63.0f, 63.0f, 65.0f, 65.0f, 67.0f, 69.0f, 70.0f, 70.0f, 72.0f, 74.0f, 74.0f, 75.0f, 75.0f, 77.0f, 77.0f, 79.0f, 81.0f, 82.0f, 82.0f, 84.0f, 86.0f, 86.0f, 87.0f, 87.0f, 89.0f, 89.0f, 91.0f, 93.0f, 94.0f, 94.0f, 96.0f, 98.0f, 98.0f, 99.0f, 99.0f, 101.0f, 101.0f, 103.0f, 105.0f, 106.0f, 106.0f, 108.0f, 110.0f, 110.0f, 111.0f, 111.0f, 113.0f, 113.0f, 115.0f, 117.0f, 118.0f, 118.0f, 120.0f, 122.0f, 122.0f, 123.0f, 123.0f, 125.0f, 125.0f, 127.0f, 129.0f, 130.0f, 130.0f, 132.0f, 134.0f, 134.0f, 135.0f, 135.0f, 137.0f, 0.0f};
float hTable_rCm5VamY_data[128] = {0.0f, 2.0f, 2.0f, 4.0f, 4.0f, 5.0f, 5.0f, 7.0f, 9.0f, 11.0f, 11.0f, 12.0f, 14.0f, 14.0f, 16.0f, 16.0f, 17.0f, 17.0f, 19.0f, 21.0f, 23.0f, 23.0f, 24.0f, 26.0f, 26.0f, 28.0f, 28.0f, 29.0f, 29.0f, 31.0f, 33.0f, 35.0f, 35.0f, 36.0f, 38.0f, 38.0f, 40.0f, 40.0f, 41.0f, 41.0f, 43.0f, 45.0f, 47.0f, 47.0f, 48.0f, 50.0f, 50.0f, 52.0f, 52.0f, 53.0f, 53.0f, 55.0f, 57.0f, 59.0f, 59.0f, 60.0f, 62.0f, 62.0f, 64.0f, 64.0f, 65.0f, 65.0f, 67.0f, 69.0f, 71.0f, 71.0f, 72.0f, 74.0f, 74.0f, 76.0f, 76.0f, 77.0f, 77.0f, 79.0f, 81.0f, 83.0f, 83.0f, 84.0f, 86.0f, 86.0f, 88.0f, 88.0f, 89.0f, 89.0f, 91.0f, 93.0f, 95.0f, 95.0f, 96.0f, 98.0f, 98.0f, 100.0f, 100.0f, 101.0f, 101.0f, 103.0f, 105.0f, 107.0f, 107.0f, 108.0f, 110.0f, 110.0f, 112.0f, 112.0f, 113.0f, 113.0f, 115.0f, 117.0f, 119.0f, 119.0f, 120.0f, 122.0f, 122.0f, 124.0f, 124.0f, 125.0f, 125.0f, 127.0f, 129.0f, 131.0f, 131.0f, 132.0f, 134.0f, 134.0f, 136.0f, 136.0f, 137.0f, 0.0f};



/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Kzrpzbbk, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_NAed3PxY);
  numBytes += sPhasor_k_init(&sPhasor_cGEDBl02, 0.0f, sampleRate);
  numBytes += sSample_init(&sSample_6FZ2hYwe);
  numBytes += sPhasor_init(&sPhasor_zozHet4J, sampleRate);
  numBytes += sDel1_init(&sDel1_Xqi3jv8l);
  numBytes += sSamphold_init(&sSamphold_iyuYtwL5);
  numBytes += sRPole_init(&sRPole_XBliX0PA);
  numBytes += sSample_init(&sSample_qAQHyiub);
  numBytes += sRPole_init(&sRPole_PKinAu5z);
  numBytes += sLine_init(&sLine_iOIr9slV);
  numBytes += sPhasor_init(&sPhasor_Lql8U7Wo, sampleRate);
  numBytes += sLine_init(&sLine_nfBQiNlR);
  numBytes += sPhasor_init(&sPhasor_22snlaDI, sampleRate);
  numBytes += sLine_init(&sLine_2z7YmJXc);
  numBytes += sPhasor_init(&sPhasor_PdhsKaRL, sampleRate);
  numBytes += sLine_init(&sLine_QmznSVBQ);
  numBytes += sLine_init(&sLine_T1axzyhg);
  numBytes += sTabhead_init(&sTabhead_DfPqYhu5, &hTable_XlagPEq3);
  numBytes += sTabread_init(&sTabread_OaLoBA1A, &hTable_XlagPEq3, false);
  numBytes += sTabread_init(&sTabread_9vrz1gk1, &hTable_XlagPEq3, false);
  numBytes += sRPole_init(&sRPole_Ws4Fhg1l);
  numBytes += sTabwrite_init(&sTabwrite_COmKKq3e, &hTable_t4UDgNYF);
  numBytes += sTabhead_init(&sTabhead_tcvu1KzT, &hTable_t4UDgNYF);
  numBytes += sTabread_init(&sTabread_9dRFK4Et, &hTable_t4UDgNYF, false);
  numBytes += sTabread_init(&sTabread_0fXI8pMs, &hTable_t4UDgNYF, false);
  numBytes += sRPole_init(&sRPole_wQEpmSvd);
  numBytes += sTabwrite_init(&sTabwrite_AZ5VSN3S, &hTable_XlagPEq3);
  numBytes += cVar_init_f(&cVar_womksIq9, 550.0f);
  numBytes += cVar_init_f(&cVar_XMnvHiMV, 0.0f);
  numBytes += cVar_init_f(&cVar_UYJuRsuk, 0.0f);
  numBytes += cBinop_init(&cBinop_pKKkG2p2, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_SdP85KdN, 0.0f);
  numBytes += cVar_init_f(&cVar_nHdwiAWZ, 0.0f);
  numBytes += cVar_init_f(&cVar_24OtEC1u, 250.0f);
  numBytes += cVar_init_f(&cVar_EiqraKYw, 0.0f);
  numBytes += cVar_init_f(&cVar_TY7JldFJ, 850.0f);
  numBytes += cVar_init_f(&cVar_hBLZGtQV, 0.0f);
  numBytes += cVar_init_f(&cVar_sjXkqhxP, 0.0f);
  numBytes += cSlice_init(&cSlice_DoCrtZK1, 0, 1);
  numBytes += cSlice_init(&cSlice_0jwVycUS, 1, 1);
  numBytes += cBinop_init(&cBinop_Z7yUvI0d, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_xc4Jq1Ga, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_u9AOgw5r, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GjxntXV1, 0.0f);
  numBytes += cVar_init_f(&cVar_aq5IPPx4, 0.0f);
  numBytes += cBinop_init(&cBinop_rLXHUaCg, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_T288V4M3, 20.0f);
  numBytes += cDelay_init(this, &cDelay_NH9Ziu6n, 0.0f);
  numBytes += cBinop_init(&cBinop_bRRzTMd5, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_BFDXUKE4, 20.0f);
  numBytes += cVar_init_f(&cVar_N7Pl4ior, 0.0f);
  numBytes += cBinop_init(&cBinop_NnbHdU7N, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_UBF9cBBk, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_gab98JBh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_sIw9foN6, 0.0f);
  numBytes += cBinop_init(&cBinop_SnmklFjt, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_EY5Ke5pD, 1, -1);
  numBytes += cSlice_init(&cSlice_vC5Icn22, 1, -1);
  numBytes += cVar_init_f(&cVar_xJa13LF8, 0.0f);
  numBytes += cBinop_init(&cBinop_bEd5lddf, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_rXP5nvlu, 0.0f);
  numBytes += cVar_init_f(&cVar_uKO9spZ9, 0.0f);
  numBytes += cVar_init_f(&cVar_3gbtKjst, 0.0f);
  numBytes += cTabread_init(&cTabread_cEJgQjtL, &hTable_Mt9UjRaD); // minor_scale
  numBytes += cVar_init_s(&cVar_l5V1HF96, "minor_scale");
  numBytes += cBinop_init(&cBinop_8bXHYstS, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_09HPZgqH, 1, -1);
  numBytes += cVar_init_f(&cVar_dEzfKEbx, 0.0f);
  numBytes += cVar_init_f(&cVar_0tF1mdMp, 0.0f);
  numBytes += cVar_init_f(&cVar_9wPF9xE3, 0.0f);
  numBytes += cVar_init_f(&cVar_VCSVXnSF, 1.0f);
  numBytes += cSlice_init(&cSlice_pJHoVX8P, 0, 1);
  numBytes += cSlice_init(&cSlice_iG9ZWVm7, 3, 1);
  numBytes += cSlice_init(&cSlice_h4STPBYU, 2, 1);
  numBytes += cSlice_init(&cSlice_3u8lOVwF, 4, 1);
  numBytes += cSlice_init(&cSlice_j3pJHCBI, 1, 1);
  numBytes += cVar_init_f(&cVar_2TNhCIDc, 0.0f);
  numBytes += cVar_init_f(&cVar_d2swh0fL, 1.0f);
  numBytes += cIf_init(&cIf_qm7t6sUD, false);
  numBytes += cBinop_init(&cBinop_2BNcRRK3, 16.0f); // __add
  numBytes += cIf_init(&cIf_hyWRrRzB, true);
  numBytes += cVar_init_f(&cVar_HnUKmVX2, 0.0f);
  numBytes += cVar_init_f(&cVar_bxJUoelq, 1.0f);
  numBytes += cVar_init_f(&cVar_OcmeB1Ma, 0.0f);
  numBytes += cIf_init(&cIf_lqkwlBcp, true);
  numBytes += cBinop_init(&cBinop_crY5zr3N, -1.0f); // __add
  numBytes += cIf_init(&cIf_TYuYtDQu, false);
  numBytes += cVar_init_f(&cVar_zdg9GVTU, 0.0f);
  numBytes += cVar_init_f(&cVar_Oag7bm4O, 1.0f);
  numBytes += cIf_init(&cIf_vSoKXUPs, true);
  numBytes += cIf_init(&cIf_6dvehMYE, false);
  numBytes += cBinop_init(&cBinop_rzAYarz3, 8.0f); // __add
  numBytes += cIf_init(&cIf_nuQAL7Ve, false);
  numBytes += cBinop_init(&cBinop_ZxG6fi77, 0.0f); // __add
  numBytes += cIf_init(&cIf_NqtjwDbe, true);
  numBytes += cVar_init_f(&cVar_ltxfcqdv, 1.0f);
  numBytes += cIf_init(&cIf_JXaHMsKL, false);
  numBytes += cBinop_init(&cBinop_aEbgyLsL, 2.0f); // __add
  numBytes += cIf_init(&cIf_15ZFazjw, true);
  numBytes += cIf_init(&cIf_rbtV9BCg, false);
  numBytes += cVar_init_f(&cVar_9Bit1r3J, 0.0f);
  numBytes += cVar_init_f(&cVar_CoqneQ2C, 0.0f);
  numBytes += cVar_init_f(&cVar_9p2GwApI, 0.5f);
  numBytes += cVar_init_f(&cVar_yjlFqvPL, 0.0f);
  numBytes += cVar_init_f(&cVar_T3R6yKib, 0.0f);
  numBytes += cRandom_init(&cRandom_7WgZ3hz7, 725713764);
  numBytes += cSlice_init(&cSlice_jYiAjdPm, 1, 1);
  numBytes += sVari_init(&sVari_8GlmbdPP, 0, 0, false);
  numBytes += cVar_init_f(&cVar_Ii7EDTMI, 0.0f);
  numBytes += cBinop_init(&cBinop_rb4B6vz2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_j5OsoXrr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_yp9WSGLz, 3.0f);
  numBytes += sVarf_init(&sVarf_C1f5KhGZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sU4Dnnqf, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8XhLWntm, 0.0f);
  numBytes += cBinop_init(&cBinop_1jVncyYT, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3J77N9X9, 1.0f);
  numBytes += cBinop_init(&cBinop_5rfndIlP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_509cKw2j, 3.0f);
  numBytes += sVarf_init(&sVarf_29jZT7BF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_owN6Jq8y, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6mwBuMzu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_M7YepMk9, 48.0f);
  numBytes += sVarf_init(&sVarf_YONAm2oA, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JYynSCky, 1.0f);
  numBytes += cBinop_init(&cBinop_7JevAcf4, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_yVRkPFwZ, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_DBrWqvas, 0.0f);
  numBytes += cVar_init_f(&cVar_xwwUsTnP, 1000.0f);
  numBytes += cBinop_init(&cBinop_AYFuz7tO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ftnCdwLh, 1.0f);
  numBytes += cDelay_init(this, &cDelay_hMm00IoS, 20.0f);
  numBytes += cVar_init_f(&cVar_eiCjQZhO, 0.0f);
  numBytes += cIf_init(&cIf_nSoxuo88, false);
  numBytes += cVar_init_f(&cVar_iV7UPGpx, 2000.0f);
  numBytes += cVar_init_f(&cVar_ipeGVXBn, 1.0f);
  numBytes += cBinop_init(&cBinop_VJ7jEO6y, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_M0Q8jNvk, 0.0f);
  numBytes += cVar_init_f(&cVar_Xzd3QCey, 0.0f);
  numBytes += cVar_init_f(&cVar_96Up93WQ, 1.0f);
  numBytes += cVar_init_f(&cVar_y7XZjBX1, 0.0f);
  numBytes += cVar_init_f(&cVar_eEdfw32S, 0.0f);
  numBytes += cTabread_init(&cTabread_iBRUsAUO, &hTable_Mt9UjRaD); // minor_scale
  numBytes += cBinop_init(&cBinop_Y93CznNo, 0.0f); // __min
  numBytes += cSlice_init(&cSlice_3rE74PdQ, 1, -1);
  numBytes += cVar_init_s(&cVar_YXrbQofi, "minor_scale");
  numBytes += cBinop_init(&cBinop_5ISncNhf, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_NQXnf83E, 0.0f);
  numBytes += cVar_init_f(&cVar_cXTwF7lV, 0.0f);
  numBytes += cBinop_init(&cBinop_XkvyTGqT, 0.0f); // __neq
  numBytes += cVar_init_f(&cVar_W1sqLmzP, 0.0f);
  numBytes += cIf_init(&cIf_ceOwm0S0, false);
  numBytes += cSlice_init(&cSlice_w7thGSOj, 1, -1);
  numBytes += cSlice_init(&cSlice_XBsJVuGh, 1, -1);
  numBytes += hTable_initWithData(&hTable_rCm5VamY, 128, hTable_rCm5VamY_data);
  numBytes += cVar_init_s(&cVar_jlGb6coA, "minor_scale");
  numBytes += cTabread_init(&cTabread_9qvYaNRW, &hTable_Mt9UjRaD); // minor_scale
  numBytes += cSlice_init(&cSlice_aCD1fiAk, 1, -1);
  numBytes += cBinop_init(&cBinop_nH91ZAbe, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_JicuGDQs, 0.0f);
  numBytes += cBinop_init(&cBinop_MFtkSTL7, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_jd7hSFpQ, 0.0f);
  numBytes += cVar_init_f(&cVar_CTysHU74, 0.0f);
  numBytes += cVar_init_f(&cVar_DU3Foeoz, 0.0f);
  numBytes += cBinop_init(&cBinop_PcQj8b80, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3fV8DYo7, 0.0f);
  numBytes += cVar_init_f(&cVar_Zf9d4DGR, 0.0f);
  numBytes += cVar_init_f(&cVar_p3ZDdJHn, 0.0f);
  numBytes += cIf_init(&cIf_G9vhqrRH, false);
  numBytes += cVar_init_f(&cVar_8ctndR28, 0.0f);
  numBytes += cBinop_init(&cBinop_ksDLoPB6, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tfUEcR6d, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_7qxiFe8Y, 0.0f);
  numBytes += cIf_init(&cIf_xGOQYi7G, false);
  numBytes += cBinop_init(&cBinop_l1NnATSi, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_MsaSy2JY, 0.0f);
  numBytes += cIf_init(&cIf_unQZl1CI, false);
  numBytes += cVar_init_f(&cVar_qFYN691w, 1.0f);
  numBytes += cVar_init_f(&cVar_WicG49wy, 9.0f);
  numBytes += cVar_init_f(&cVar_4DH6ySqX, 7.0f);
  numBytes += hTable_initWithData(&hTable_Mt9UjRaD, 128, hTable_Mt9UjRaD_data);
  numBytes += cBinop_init(&cBinop_SWMWB4Pf, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_k8oeYd0M, 1.0f);
  numBytes += cIf_init(&cIf_PLC61W4w, false);
  numBytes += cVar_init_f(&cVar_4SQJtis9, 0.0f);
  numBytes += cIf_init(&cIf_F71N2acF, true);
  numBytes += cIf_init(&cIf_NbTuzDPc, false);
  numBytes += cBinop_init(&cBinop_eWGtbgKO, 16.0f); // __add
  numBytes += cVar_init_f(&cVar_phpFgDNP, 0.0f);
  numBytes += cSlice_init(&cSlice_VlLI093L, 1, 1);
  numBytes += cSlice_init(&cSlice_5xTTi1VU, 2, 1);
  numBytes += cSlice_init(&cSlice_ptwWNLZ3, 0, 1);
  numBytes += cSlice_init(&cSlice_M2pNErhY, 4, 1);
  numBytes += cSlice_init(&cSlice_1RY1qx2l, 3, 1);
  numBytes += cVar_init_f(&cVar_srghvoyK, 1.0f);
  numBytes += cVar_init_f(&cVar_DH8E0hTk, 1.0f);
  numBytes += cIf_init(&cIf_eRBfVVVO, true);
  numBytes += cBinop_init(&cBinop_ly59XhgT, 0.0f); // __add
  numBytes += cIf_init(&cIf_H6yvkYV5, false);
  numBytes += cVar_init_f(&cVar_yyZEGycE, 0.0f);
  numBytes += cVar_init_f(&cVar_pDaHVYXa, 0.0f);
  numBytes += cVar_init_f(&cVar_iTv4078v, 0.0f);
  numBytes += cVar_init_f(&cVar_0J7y5UaU, 0.0f);
  numBytes += cIf_init(&cIf_xgP72M2O, false);
  numBytes += cBinop_init(&cBinop_HtokTgUc, 8.0f); // __add
  numBytes += cIf_init(&cIf_CGN7QOUf, true);
  numBytes += cVar_init_f(&cVar_Pu04dvRZ, 1.0f);
  numBytes += cBinop_init(&cBinop_csk0xgSn, -1.0f); // __add
  numBytes += cIf_init(&cIf_vjW77bD3, true);
  numBytes += cIf_init(&cIf_6zfyrPBY, false);
  numBytes += cVar_init_f(&cVar_fXt5lRf2, 1.0f);
  numBytes += cVar_init_f(&cVar_ecJB8UhS, 0.0f);
  numBytes += cBinop_init(&cBinop_SVKgX4xY, 2.0f); // __add
  numBytes += cIf_init(&cIf_2BDGeYq4, false);
  numBytes += cIf_init(&cIf_5iBXfrWr, true);
  numBytes += cVar_init_f(&cVar_jGv32XE1, 0.0f);
  numBytes += cVar_init_f(&cVar_5Szf4UcC, 0.0f);
  numBytes += cVar_init_f(&cVar_Oc9uv7pM, 0.0f);
  numBytes += cVar_init_f(&cVar_lJrEoy24, 1.0f);
  numBytes += cBinop_init(&cBinop_0Jk2L3IL, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_Sr0XDdFK, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_f4C4FAAC, 5.0f);
  numBytes += cBinop_init(&cBinop_IUH79Swa, 0.0f); // __add
  numBytes += cIf_init(&cIf_hwKAvrmp, false);
  numBytes += cVar_init_f(&cVar_V97p5PLM, 0.0f);
  numBytes += cVar_init_f(&cVar_e4cnTuIT, 0.0f);
  numBytes += cVar_init_f(&cVar_10QShX44, 0.0f);
  numBytes += cVar_init_f(&cVar_gc8ivMTL, 0.0f);
  numBytes += cBinop_init(&cBinop_gMbtG6mD, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_22NyCupc, 0.0f);
  numBytes += cIf_init(&cIf_Natmjv9h, false);
  numBytes += cIf_init(&cIf_iW85tzEl, false);
  numBytes += cVar_init_f(&cVar_UM6FQ5w2, 0.0f);
  numBytes += cVar_init_f(&cVar_FkrsnWLZ, 11.0f);
  numBytes += cIf_init(&cIf_DlKwv16p, false);
  numBytes += cVar_init_f(&cVar_J06HybW9, 0.0f);
  numBytes += cBinop_init(&cBinop_rxQ5nuEP, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_PcwPRJcQ, 1.0f); // __pow
  numBytes += cPack_init(&cPack_0yKPt9Ah, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_zeDTWVXS, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_SKqXkmId, 2.0f);
  numBytes += cBinop_init(&cBinop_Ch9zhjDb, 1.0f); // __pow
  numBytes += cPack_init(&cPack_8w1hN5Hb, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_KWMgpVDy, 0.0f);
  numBytes += cVar_init_f(&cVar_nmE2inuR, 0.0f);
  numBytes += cVar_init_f(&cVar_Gx1gSF1u, 0.0f);
  numBytes += cVar_init_f(&cVar_D2JhkqQY, 0.5f);
  numBytes += cVar_init_f(&cVar_czeDUCIf, 0.0f);
  numBytes += cVar_init_f(&cVar_JMExYTHw, 3.0f);
  numBytes += cBinop_init(&cBinop_Y98HKbgn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_T1iByYAv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_A3KreRrW, 3000.0f);
  numBytes += sVarf_init(&sVarf_zHKJ79b9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tuuHqt0e, 0.0f);
  numBytes += sVarf_init(&sVarf_NK18WIAf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Wn29EVHQ, 0.0f);
  numBytes += sVarf_init(&sVarf_xSajiZR9, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_0Zmhk0Av, "del-1339-ping");
  numBytes += sVarf_init(&sVarf_35UJXhL5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oI7okc9R, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gG29Dd3U, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qQoRCBU9, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_xtC51Tl0, 0.0f);
  numBytes += hTable_init(&hTable_t4UDgNYF, 256);
  numBytes += cDelay_init(this, &cDelay_g3bZWNGk, 0.0f);
  numBytes += cVar_init_f(&cVar_lOmHBysN, 0.0f);
  numBytes += cBinop_init(&cBinop_WmqXdaW8, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_TCCSr6Mm, 0.7f);
  numBytes += cVar_init_f(&cVar_Oi2cfEJy, 0.5f);
  numBytes += cDelay_init(this, &cDelay_y9krDOBO, 0.0f);
  numBytes += hTable_init(&hTable_XlagPEq3, 256);
  numBytes += cDelay_init(this, &cDelay_qb8h4TUp, 0.0f);
  numBytes += cBinop_init(&cBinop_Rew4Z5xy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_EKjLraGi, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Gt9NBsxE, 3000.0f);
  numBytes += sVarf_init(&sVarf_MW1sCAeW, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_cOnEbBEo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3BKjnCnH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nn3e1DEX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_hx5Iq7SI, 1.0f); // __pow
  numBytes += cIf_init(&cIf_KIdg8hxg, false);
  numBytes += cVar_init_f(&cVar_9d3khCX1, 0.0f);
  numBytes += sVarf_init(&sVarf_HB5pNCXh, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_nI69gyzQ, "del-1339-pong");
  numBytes += sVarf_init(&sVarf_wb2dlqJK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IoozRXwR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ILEJFr81, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_UF7ro4DQ, 1.0f);
  numBytes += cBinop_init(&cBinop_qOdC8TFK, 0.0f); // __mul
  numBytes += cIf_init(&cIf_SW7f5C6h, false);
  numBytes += cVar_init_f(&cVar_qQX3sGrl, 0.0f);
  numBytes += cVar_init_f(&cVar_lc9XiLbE, 0.0f);
  numBytes += cVar_init_f(&cVar_rfdALNVd, 0.0f);
  numBytes += cIf_init(&cIf_1klPmh6s, false);
  numBytes += cVar_init_f(&cVar_HMK7wZ0Q, 0.0f);
  numBytes += cVar_init_f(&cVar_aFvZ3LwN, 0.0f);
  numBytes += cBinop_init(&cBinop_NIpCcdmW, 0.0f); // __bimod
  numBytes += cBinop_init(&cBinop_ECQfy7I9, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_aJ70izQM, 0.0f);
  numBytes += cIf_init(&cIf_srw9af7J, false);
  numBytes += cBinop_init(&cBinop_gj3RE66N, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_PlmH5RuI, 0.0f);
  numBytes += cVar_init_f(&cVar_m4pt4h1D, 17.0f);
  numBytes += cVar_init_f(&cVar_1NU0nRw7, 2.0f);
  numBytes += cVar_init_f(&cVar_siGlhqcE, 13.0f);
  numBytes += cIf_init(&cIf_44aMhzMZ, false);
  numBytes += cVar_init_f(&cVar_m7kGdpKl, 0.0f);
  numBytes += cVar_init_f(&cVar_czetbuZu, 0.0f);
  numBytes += cVar_init_f(&cVar_wpSciaiB, 0.0f);
  numBytes += cBinop_init(&cBinop_p5Vzk9tK, 0.0f); // __bimod
  numBytes += cVar_init_f(&cVar_wNKH9wAw, 0.0f);
  numBytes += cIf_init(&cIf_hlllHi61, false);
  numBytes += cBinop_init(&cBinop_1WjO9OSZ, 0.0f); // __lt
  numBytes += cIf_init(&cIf_WZATE7In, false);
  numBytes += cVar_init_f(&cVar_qJQnxRQq, 0.0f);
  numBytes += cBinop_init(&cBinop_BJC3jbY0, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_lGtBKTpH, 1.0f);
  numBytes += cVar_init_f(&cVar_kGAQTZ07, 0.0f);
  numBytes += cBinop_init(&cBinop_QnuXkxc6, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YuQeecnE, 0.0f);
  numBytes += cVar_init_f(&cVar_FyE7awrB, 0.0f);
  numBytes += cBinop_init(&cBinop_b6dXp6nh, 0.0f); // __sub
  numBytes += cIf_init(&cIf_KXCPQii6, false);
  numBytes += cVar_init_f(&cVar_Wd5zzxdB, 0.0f);
  numBytes += cVar_init_f(&cVar_Ouv2eMVc, 0.0f);
  numBytes += cIf_init(&cIf_SzXmYaU0, false);
  numBytes += cVar_init_f(&cVar_8990YYy8, 1.0f);
  numBytes += cVar_init_f(&cVar_IIUtvmui, 0.0f);
  numBytes += cSlice_init(&cSlice_ch92QVHi, 4, 1);
  numBytes += cSlice_init(&cSlice_61a7tmZh, 0, 1);
  numBytes += cSlice_init(&cSlice_LqNRA3aC, 2, 1);
  numBytes += cSlice_init(&cSlice_Vhn7Sq4v, 1, 1);
  numBytes += cSlice_init(&cSlice_tlahTH2w, 3, 1);
  numBytes += cVar_init_f(&cVar_c3Fq9tyi, 1.0f);
  numBytes += cVar_init_f(&cVar_uCjNcF0P, 0.0f);
  numBytes += cBinop_init(&cBinop_J27VMlGC, 2.0f); // __add
  numBytes += cIf_init(&cIf_cNuXts6y, true);
  numBytes += cIf_init(&cIf_wPHXY64V, false);
  numBytes += cIf_init(&cIf_koNCIyIj, false);
  numBytes += cVar_init_f(&cVar_HBFuPN3z, 0.0f);
  numBytes += cVar_init_f(&cVar_hxVIShqe, 1.0f);
  numBytes += cVar_init_f(&cVar_liJaMpCw, 0.0f);
  numBytes += cVar_init_f(&cVar_Sz7LUj3n, 0.0f);
  numBytes += cIf_init(&cIf_3zHLhJqY, false);
  numBytes += cIf_init(&cIf_XLFoGQlr, true);
  numBytes += cBinop_init(&cBinop_pyrX2ViO, -1.0f); // __add
  numBytes += cBinop_init(&cBinop_IgDp83sR, 16.0f); // __add
  numBytes += cIf_init(&cIf_hGrYOBkY, false);
  numBytes += cIf_init(&cIf_NlFGGZeD, true);
  numBytes += cIf_init(&cIf_44LbNihN, false);
  numBytes += cBinop_init(&cBinop_GNq9Uais, 0.0f); // __add
  numBytes += cIf_init(&cIf_PE0arWMU, true);
  numBytes += cVar_init_f(&cVar_V3wfSgSd, 0.0f);
  numBytes += cBinop_init(&cBinop_chOrFQju, 8.0f); // __add
  numBytes += cIf_init(&cIf_gOV76KnO, false);
  numBytes += cIf_init(&cIf_M064bYid, true);
  numBytes += cVar_init_f(&cVar_HYpsbOCM, 1.0f);
  numBytes += cVar_init_f(&cVar_5B8bWGfJ, 0.0f);
  numBytes += cVar_init_f(&cVar_EUHklioh, 0.0f);
  numBytes += cVar_init_f(&cVar_rDA47Ugj, 1.0f);
  numBytes += cVar_init_f(&cVar_AMFXrXHx, 0.0f);
  numBytes += cVar_init_f(&cVar_YCwFaBt7, 0.0f);
  numBytes += cVar_init_f(&cVar_PIhdGW7l, 0.0f);
  numBytes += cIf_init(&cIf_fs72xCQX, false);
  numBytes += cBinop_init(&cBinop_vY7ltqjX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_dX68iHYx, 0.0f); // __neq
  numBytes += cSlice_init(&cSlice_3oqBXir1, 1, -1);
  numBytes += cSlice_init(&cSlice_a5uCBxFM, 1, -1);
  numBytes += cIf_init(&cIf_jxdarfE9, false);
  numBytes += cVar_init_f(&cVar_cYgupouL, 0.0f);
  numBytes += cVar_init_f(&cVar_3gdG0kcw, 0.0f);
  numBytes += cSlice_init(&cSlice_14bRYa1n, 1, -1);
  numBytes += cSlice_init(&cSlice_r4QvNXW3, 1, -1);
  numBytes += cBinop_init(&cBinop_Pg5t5FAY, 0.0f); // __neq
  numBytes += cIf_init(&cIf_d32pJKTv, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_rCm5VamY);
  hTable_free(&hTable_Mt9UjRaD);
  cPack_free(&cPack_0yKPt9Ah);
  cPack_free(&cPack_zeDTWVXS);
  cPack_free(&cPack_8w1hN5Hb);
  hTable_free(&hTable_t4UDgNYF);
  hTable_free(&hTable_XlagPEq3);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB069134D: return &hTable_t4UDgNYF; // del-1339-pong
    case 0x4D17F050: return &hTable_Mt9UjRaD; // minor_scale
    case 0xCA62B065: return &hTable_XlagPEq3; // del-1339-ping
    case 0xBBA21A19: return &hTable_rCm5VamY; // major_scale
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xC440C54F: { // Channel-A
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4g2vthrU_sendMessage);
      break;
    }
    case 0xB762BB42: { // Channel-B
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EasJdbrr_sendMessage);
      break;
    }
    case 0x27D89CD5: { // Channel-C
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NIYhqLT4_sendMessage);
      break;
    }
    case 0x17512476: { // 1001-intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uOz9jZvM_sendMessage);
      break;
    }
    case 0xD52A3BF1: { // 1001-mastertempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GJ7u5FID_sendMessage);
      break;
    }
    case 0x8CF5567: { // 1001-tempo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dzNhQpi6_sendMessage);
      break;
    }
    case 0x8CC8BA58: { // 1001-transpose
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x6DIiJPh_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xXiiKCiU_sendMessage);
      break;
    }
    case 0x3AE704A5: { // pot1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XBYGM5Rf_sendMessage);
      break;
    }
    case 0xDDC4EBDB: { // pot2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SL4vOQhh_sendMessage);
      break;
    }
    case 0x125109EA: { // pot3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M4XfIMHc_sendMessage);
      break;
    }
    case 0x73BEE661: { // pot4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YfvXSle8_sendMessage);
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


void Heavy_heavy::cCast_9TE3Vfq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YCwFaBt7, 0, m, &cVar_YCwFaBt7_sendMessage);
}

void Heavy_heavy::cBinop_dENu1Cux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ecJB8UhS, 0, m, &cVar_ecJB8UhS_sendMessage);
}

void Heavy_heavy::cSend_zbB2SPmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_uOz9jZvM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_R68qynew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tuuHqt0e, 0, m, &cVar_tuuHqt0e_sendMessage);
}

void Heavy_heavy::cBinop_0osWl12l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QyztcDi0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OugGsGZr_sendMessage);
}

void Heavy_heavy::cSend_sW3amLdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led1", 0xE817C68D, m);
}

void Heavy_heavy::cBinop_jiocF9pV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2TNhCIDc, 0, m, &cVar_2TNhCIDc_sendMessage);
}

void Heavy_heavy::cReceive_4g2vthrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_JFI2nHdE_sendMessage);
}

void Heavy_heavy::cVar_womksIq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nHdwiAWZ, 0, m, &cVar_nHdwiAWZ_sendMessage);
}

void Heavy_heavy::cVar_XMnvHiMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UYJuRsuk, 1, m, &cVar_UYJuRsuk_sendMessage);
}

void Heavy_heavy::cCast_VkpHexyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OZVvcUaz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_UYJuRsuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZVDcneXS_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_LhdfS35F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QmznSVBQ, 0, m, NULL);
  cSwitchcase_jn5Gas7b_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_QmznSVBQ, 0, m, NULL);
  cSwitchcase_jn5Gas7b_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_pKKkG2p2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SdP85KdN, 1, m, &cDelay_SdP85KdN_sendMessage);
}

void Heavy_heavy::cCast_tnDmDSj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKKkG2p2, HV_BINOP_ADD, 0, m, &cBinop_pKKkG2p2_sendMessage);
}

void Heavy_heavy::cCast_uQEPBeZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKKkG2p2, HV_BINOP_ADD, 1, m, &cBinop_pKKkG2p2_sendMessage);
}

void Heavy_heavy::cSwitchcase_OZVvcUaz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4h8Teo1Z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4h8Teo1Z_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_SdP85KdN, 1, m, &cDelay_SdP85KdN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S8NQaW9Z_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_SdP85KdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SdP85KdN, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UYJuRsuk, 0, m, &cVar_UYJuRsuk_sendMessage);
}

void Heavy_heavy::cMsg_4h8Teo1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SdP85KdN, 0, m, &cDelay_SdP85KdN_sendMessage);
}

void Heavy_heavy::cCast_S8NQaW9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SdP85KdN, 0, m, &cDelay_SdP85KdN_sendMessage);
}

void Heavy_heavy::cVar_nHdwiAWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EiqraKYw, 1, m, &cVar_EiqraKYw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKKkG2p2, HV_BINOP_ADD, 0, m, &cBinop_pKKkG2p2_sendMessage);
}

void Heavy_heavy::cVar_24OtEC1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hBLZGtQV, 0, m, &cVar_hBLZGtQV_sendMessage);
}

void Heavy_heavy::cCast_Jv6uQbwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EiqraKYw, 0, m, &cVar_EiqraKYw_sendMessage);
}

void Heavy_heavy::cVar_EiqraKYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LhdfS35F_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_TY7JldFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XMnvHiMV, 0, m, &cVar_XMnvHiMV_sendMessage);
}

void Heavy_heavy::cVar_hBLZGtQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uQEPBeZB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tnDmDSj3_sendMessage);
}

void Heavy_heavy::cMsg_ZVDcneXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QmznSVBQ, 0, m, NULL);
  cSwitchcase_jn5Gas7b_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_QmznSVBQ, 0, m, NULL);
  cSwitchcase_jn5Gas7b_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_W1LlUyG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xc4Jq1Ga, HV_BINOP_SUBTRACT, 1, m, &cBinop_xc4Jq1Ga_sendMessage);
}

void Heavy_heavy::cVar_sjXkqhxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xc4Jq1Ga, HV_BINOP_SUBTRACT, 0, m, &cBinop_xc4Jq1Ga_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_YLkqEmfL_sendMessage);
}

void Heavy_heavy::cCast_Vv1ZKhX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N7Pl4ior, 1, m, &cVar_N7Pl4ior_sendMessage);
}

void Heavy_heavy::cSlice_DoCrtZK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Vv1ZKhX2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dDPAy5Lb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_0jwVycUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Buawfyk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mNj6XJJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Z7yUvI0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bRRzTMd5, HV_BINOP_DIVIDE, 0, m, &cBinop_bRRzTMd5_sendMessage);
}

void Heavy_heavy::cBinop_xc4Jq1Ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sjXkqhxP, 1, m, &cVar_sjXkqhxP_sendMessage);
}

void Heavy_heavy::cCast_YRkrs18A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JGc9geyM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_u9AOgw5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RBbK2ydx_sendMessage);
}

void Heavy_heavy::cBinop_RBbK2ydx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sjXkqhxP, 1, m, &cVar_sjXkqhxP_sendMessage);
}

void Heavy_heavy::cCast_MM3tmwc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5Q520pc7_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSwitchcase_syAI4ozS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MM3tmwc0_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gab98JBh, HV_BINOP_MULTIPLY, 0, m, &cBinop_gab98JBh_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_UBF9cBBk, HV_BINOP_DIVIDE, 1, m, &cBinop_UBF9cBBk_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_T288V4M3, 0, m, &cVar_T288V4M3_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_GjxntXV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NnbHdU7N, HV_BINOP_ADD, 0, m, &cBinop_NnbHdU7N_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnmklFjt, HV_BINOP_ADD, 0, m, &cBinop_SnmklFjt_sendMessage);
}

void Heavy_heavy::cCast_Y3usJRZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dn3lhBFy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_2PkoNkst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x7OTBwHQ_sendMessage);
}

void Heavy_heavy::cSystem_x7OTBwHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gab98JBh, HV_BINOP_MULTIPLY, 1, m, &cBinop_gab98JBh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u9AOgw5r, HV_BINOP_MULTIPLY, 1, m, &cBinop_u9AOgw5r_sendMessage);
}

void Heavy_heavy::cVar_aq5IPPx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z7yUvI0d, HV_BINOP_SUBTRACT, 1, m, &cBinop_Z7yUvI0d_sendMessage);
}

void Heavy_heavy::cCast_FTK1NHCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N7Pl4ior, 0, m, &cVar_N7Pl4ior_sendMessage);
}

void Heavy_heavy::cCast_zVvjPR0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5LkuoV4z_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnmklFjt, HV_BINOP_ADD, 0, m, &cBinop_SnmklFjt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GjxntXV1, 1, m, &cVar_GjxntXV1_sendMessage);
}

void Heavy_heavy::cMsg_bU6jnHA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NH9Ziu6n, 0, m, &cDelay_NH9Ziu6n_sendMessage);
}

void Heavy_heavy::cBinop_ciQOzXxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rLXHUaCg, HV_BINOP_MULTIPLY, 1, m, &cBinop_rLXHUaCg_sendMessage);
}

void Heavy_heavy::cBinop_eW1xojcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NH9Ziu6n, 2, m, &cDelay_NH9Ziu6n_sendMessage);
}

void Heavy_heavy::cMsg_Om2BUaJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R7tX66HY_sendMessage);
}

void Heavy_heavy::cSystem_R7tX66HY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ciQOzXxf_sendMessage);
}

void Heavy_heavy::cBinop_rLXHUaCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_eW1xojcP_sendMessage);
}

void Heavy_heavy::cVar_T288V4M3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rLXHUaCg, HV_BINOP_MULTIPLY, 0, m, &cBinop_rLXHUaCg_sendMessage);
}

void Heavy_heavy::cSwitchcase_Ng0pJjLG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_bU6jnHA5_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_bU6jnHA5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lA15pWKP_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_NH9Ziu6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NH9Ziu6n, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NH9Ziu6n, 0, m, &cDelay_NH9Ziu6n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sjXkqhxP, 0, m, &cVar_sjXkqhxP_sendMessage);
}

void Heavy_heavy::cCast_lA15pWKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bU6jnHA5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NH9Ziu6n, 0, m, &cDelay_NH9Ziu6n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sjXkqhxP, 0, m, &cVar_sjXkqhxP_sendMessage);
}

void Heavy_heavy::cCast_OoxmQ7tS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pg5SdQjs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_bRRzTMd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnmklFjt, HV_BINOP_ADD, 1, m, &cBinop_SnmklFjt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NnbHdU7N, HV_BINOP_ADD, 1, m, &cBinop_NnbHdU7N_sendMessage);
}

void Heavy_heavy::cBinop_YLkqEmfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Cm2vYYmP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_BFDXUKE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_syAI4ozS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_5LkuoV4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pg5SdQjs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_N7Pl4ior_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GjxntXV1, 0, m, &cVar_GjxntXV1_sendMessage);
}

void Heavy_heavy::cCast_lBNy1d0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OoxmQ7tS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FTK1NHCd_sendMessage);
}

void Heavy_heavy::cCast_uwnH5fWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GjxntXV1, 0, m, &cVar_GjxntXV1_sendMessage);
}

void Heavy_heavy::cSwitchcase_Cm2vYYmP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uwnH5fWM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lBNy1d0p_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_heavy::cMsg_JGc9geyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Ng0pJjLG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_P1tk2DPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sIw9foN6, 0, m, &cVar_sIw9foN6_sendMessage);
}

void Heavy_heavy::cMsg_S3lZKH1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Ng0pJjLG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_NnbHdU7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GjxntXV1, 1, m, &cVar_GjxntXV1_sendMessage);
}

void Heavy_heavy::cBinop_UBF9cBBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bRRzTMd5, HV_BINOP_DIVIDE, 1, m, &cBinop_bRRzTMd5_sendMessage);
}

void Heavy_heavy::cCast_XFkNfOkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S3lZKH1y_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_gab98JBh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_W1LlUyG3_sendMessage);
}

void Heavy_heavy::cMsg_5Q520pc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gab98JBh, HV_BINOP_MULTIPLY, 0, m, &cBinop_gab98JBh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UBF9cBBk, HV_BINOP_DIVIDE, 1, m, &cBinop_UBF9cBBk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T288V4M3, 0, m, &cVar_T288V4M3_sendMessage);
}

void Heavy_heavy::cCast_dDPAy5Lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z7yUvI0d, HV_BINOP_SUBTRACT, 0, m, &cBinop_Z7yUvI0d_sendMessage);
}

void Heavy_heavy::cVar_sIw9foN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Buawfyk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6mNj6XJJ_sendMessage);
}

void Heavy_heavy::cMsg_pg5SdQjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Ng0pJjLG_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnmklFjt, HV_BINOP_ADD, 1, m, &cBinop_SnmklFjt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NnbHdU7N, HV_BINOP_ADD, 1, m, &cBinop_NnbHdU7N_sendMessage);
}

void Heavy_heavy::cCast_6mNj6XJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UBF9cBBk, HV_BINOP_DIVIDE, 0, m, &cBinop_UBF9cBBk_sendMessage);
}

void Heavy_heavy::cMsg_dn3lhBFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_sIw9foN6, 1, m, &cVar_sIw9foN6_sendMessage);
}

void Heavy_heavy::cCast_1Buawfyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u9AOgw5r, HV_BINOP_MULTIPLY, 0, m, &cBinop_u9AOgw5r_sendMessage);
}

void Heavy_heavy::cBinop_SnmklFjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aq5IPPx4, 0, m, &cVar_aq5IPPx4_sendMessage);
}

void Heavy_heavy::cSlice_EY5Ke5pD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_S3lZKH1y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_S3lZKH1y_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_jn5Gas7b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EY5Ke5pD, 0, m, &cSlice_EY5Ke5pD_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vC5Icn22, 0, m, &cSlice_vC5Icn22_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P1tk2DPS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_0jwVycUS, 0, m, &cSlice_0jwVycUS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DoCrtZK1, 0, m, &cSlice_DoCrtZK1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YRkrs18A_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3usJRZs_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_vC5Icn22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFkNfOkE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zVvjPR0z_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFkNfOkE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zVvjPR0z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_xJa13LF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zbB2SPmD_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_JFI2nHdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PIhdGW7l, 0, m, &cVar_PIhdGW7l_sendMessage);
}

void Heavy_heavy::cBinop_bEd5lddf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tMerIVrP_sendMessage);
}

void Heavy_heavy::cVar_rXP5nvlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uKO9spZ9, 0, m, &cVar_uKO9spZ9_sendMessage);
}

void Heavy_heavy::cVar_uKO9spZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bEd5lddf, HV_BINOP_ADD, 1, m, &cBinop_bEd5lddf_sendMessage);
}

void Heavy_heavy::cVar_3gbtKjst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_weviA1I1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cMsg_OgLYUWBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_weviA1I1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_EAIhTNa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ItGZ6Uux_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_cW0PXKdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l5V1HF96, 0, m, &cVar_l5V1HF96_sendMessage);
}

void Heavy_heavy::cTabread_cEJgQjtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bEd5lddf, HV_BINOP_ADD, 0, m, &cBinop_bEd5lddf_sendMessage);
}

void Heavy_heavy::cCast_MbjITmLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IHdElqwZ_sendMessage);
}

void Heavy_heavy::cVar_l5V1HF96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mUmijhl5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_IHdElqwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8bXHYstS, HV_BINOP_MIN, 0, m, &cBinop_8bXHYstS_sendMessage);
}

void Heavy_heavy::cBinop_8bXHYstS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_cEJgQjtL, 0, m, &cTabread_cEJgQjtL_sendMessage);
}

void Heavy_heavy::cSystem_at9Xk3PS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FME1X51n_sendMessage);
}

void Heavy_heavy::cBinop_FME1X51n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8bXHYstS, HV_BINOP_MIN, 1, m, &cBinop_8bXHYstS_sendMessage);
}

void Heavy_heavy::cMsg_mUmijhl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_at9Xk3PS_sendMessage);
}

void Heavy_heavy::cSlice_09HPZgqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_cEJgQjtL, 1, m, &cTabread_cEJgQjtL_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_cEJgQjtL, 1, m, &cTabread_cEJgQjtL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_weviA1I1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_09HPZgqH, 0, m, &cSlice_09HPZgqH_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cW0PXKdt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MbjITmLD_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cMsg_ItGZ6Uux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_weviA1I1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_f8AQAaVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OgLYUWBI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_dEzfKEbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZxG6fi77, HV_BINOP_ADD, 1, m, &cBinop_ZxG6fi77_sendMessage);
}

void Heavy_heavy::cVar_0tF1mdMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ltxfcqdv, 0, m, &cVar_ltxfcqdv_sendMessage);
}

void Heavy_heavy::cVar_9wPF9xE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VCSVXnSF, 0, m, &cVar_VCSVXnSF_sendMessage);
}

void Heavy_heavy::cVar_VCSVXnSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_nBP4B2Sk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_UH0W4Ke1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qm7t6sUD, 1, m, &cIf_qm7t6sUD_sendMessage);
}

void Heavy_heavy::cBinop_nBP4B2Sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VCSVXnSF, 1, m, &cVar_VCSVXnSF_sendMessage);
}

void Heavy_heavy::cSlice_pJHoVX8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_crY5zr3N, HV_BINOP_ADD, 1, m, &cBinop_crY5zr3N_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_iG9ZWVm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2BNcRRK3, HV_BINOP_ADD, 1, m, &cBinop_2BNcRRK3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_h4STPBYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rzAYarz3, HV_BINOP_ADD, 1, m, &cBinop_rzAYarz3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_3u8lOVwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_2TNhCIDc, 0, m, &cVar_2TNhCIDc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_j3pJHCBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aEbgyLsL, HV_BINOP_ADD, 1, m, &cBinop_aEbgyLsL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_2TNhCIDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Bit1r3J, 0, m, &cVar_9Bit1r3J_sendMessage);
}

void Heavy_heavy::cBinop_UupTIMYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d2swh0fL, 1, m, &cVar_d2swh0fL_sendMessage);
}

void Heavy_heavy::cVar_d2swh0fL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_UupTIMYg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Ds5lEQdo_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nuQAL7Ve, 1, m, &cIf_nuQAL7Ve_sendMessage);
}

void Heavy_heavy::cIf_qm7t6sUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_2BNcRRK3, HV_BINOP_ADD, 0, m, &cBinop_2BNcRRK3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_UH0W4Ke1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hyWRrRzB, 1, m, &cIf_hyWRrRzB_sendMessage);
}

void Heavy_heavy::cBinop_2BNcRRK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nuQAL7Ve, 0, m, &cIf_nuQAL7Ve_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NqtjwDbe, 0, m, &cIf_NqtjwDbe_sendMessage);
}

void Heavy_heavy::cIf_hyWRrRzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_nuQAL7Ve, 0, m, &cIf_nuQAL7Ve_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NqtjwDbe, 0, m, &cIf_NqtjwDbe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_HnUKmVX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oag7bm4O, 0, m, &cVar_Oag7bm4O_sendMessage);
}

void Heavy_heavy::cVar_bxJUoelq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zoEcB6BJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ydIKxrFJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_JXaHMsKL, 1, m, &cIf_JXaHMsKL_sendMessage);
}

void Heavy_heavy::cBinop_zoEcB6BJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bxJUoelq, 1, m, &cVar_bxJUoelq_sendMessage);
}

void Heavy_heavy::cVar_OcmeB1Ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bxJUoelq, 0, m, &cVar_bxJUoelq_sendMessage);
}

void Heavy_heavy::cIf_lqkwlBcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_JXaHMsKL, 0, m, &cIf_JXaHMsKL_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_15ZFazjw, 0, m, &cIf_15ZFazjw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_crY5zr3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JXaHMsKL, 0, m, &cIf_JXaHMsKL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_15ZFazjw, 0, m, &cIf_15ZFazjw_sendMessage);
}

void Heavy_heavy::cBinop_UPJ4ekYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lqkwlBcp, 1, m, &cIf_lqkwlBcp_sendMessage);
}

void Heavy_heavy::cIf_TYuYtDQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_crY5zr3N, HV_BINOP_ADD, 0, m, &cBinop_crY5zr3N_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_zdg9GVTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d2swh0fL, 0, m, &cVar_d2swh0fL_sendMessage);
}

void Heavy_heavy::cBinop_ZiMt4UFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oag7bm4O, 1, m, &cVar_Oag7bm4O_sendMessage);
}

void Heavy_heavy::cVar_Oag7bm4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ZiMt4UFp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BMN7F8Z1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6dvehMYE, 1, m, &cIf_6dvehMYE_sendMessage);
}

void Heavy_heavy::cIf_vSoKXUPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_qm7t6sUD, 0, m, &cIf_qm7t6sUD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_hyWRrRzB, 0, m, &cIf_hyWRrRzB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_6dvehMYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rzAYarz3, HV_BINOP_ADD, 0, m, &cBinop_rzAYarz3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_BMN7F8Z1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vSoKXUPs, 1, m, &cIf_vSoKXUPs_sendMessage);
}

void Heavy_heavy::cBinop_rzAYarz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qm7t6sUD, 0, m, &cIf_qm7t6sUD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hyWRrRzB, 0, m, &cIf_hyWRrRzB_sendMessage);
}

void Heavy_heavy::cIf_nuQAL7Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZxG6fi77, HV_BINOP_ADD, 0, m, &cBinop_ZxG6fi77_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ZxG6fi77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eEdfw32S, 0, m, &cVar_eEdfw32S_sendMessage);
}

void Heavy_heavy::cIf_NqtjwDbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_eEdfw32S, 0, m, &cVar_eEdfw32S_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Ds5lEQdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NqtjwDbe, 1, m, &cIf_NqtjwDbe_sendMessage);
}

void Heavy_heavy::cVar_ltxfcqdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_U5DPGqsG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_UPJ4ekYs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TYuYtDQu, 1, m, &cIf_TYuYtDQu_sendMessage);
}

void Heavy_heavy::cBinop_U5DPGqsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ltxfcqdv, 1, m, &cVar_ltxfcqdv_sendMessage);
}

void Heavy_heavy::cIf_JXaHMsKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_aEbgyLsL, HV_BINOP_ADD, 0, m, &cBinop_aEbgyLsL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_ydIKxrFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_15ZFazjw, 1, m, &cIf_15ZFazjw_sendMessage);
}

void Heavy_heavy::cBinop_aEbgyLsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6dvehMYE, 0, m, &cIf_6dvehMYE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vSoKXUPs, 0, m, &cIf_vSoKXUPs_sendMessage);
}

void Heavy_heavy::cIf_15ZFazjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_6dvehMYE, 0, m, &cIf_6dvehMYE_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_vSoKXUPs, 0, m, &cIf_vSoKXUPs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_IO2rAAwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dEzfKEbx, 0, m, &cVar_dEzfKEbx_sendMessage);
}

void Heavy_heavy::cBinop_cIIx42t3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rbtV9BCg, 1, m, &cIf_rbtV9BCg_sendMessage);
}

void Heavy_heavy::cUnop_PGdlDNNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dEzfKEbx, 0, m, &cVar_dEzfKEbx_sendMessage);
}

void Heavy_heavy::cIf_rbtV9BCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_IO2rAAwn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PGdlDNNI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_9Bit1r3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cIIx42t3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rbtV9BCg, 0, m, &cIf_rbtV9BCg_sendMessage);
}

void Heavy_heavy::cVar_CoqneQ2C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2TNhCIDc, 0, m, &cVar_2TNhCIDc_sendMessage);
}

void Heavy_heavy::cSend_fcrNMaha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::sSample_qAQHyiub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rfndIlP, HV_BINOP_MULTIPLY, 0, m, &cBinop_5rfndIlP_sendMessage);
}

void Heavy_heavy::cVar_9p2GwApI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yjlFqvPL, 0, m, &cVar_yjlFqvPL_sendMessage);
}

void Heavy_heavy::cVar_yjlFqvPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sU4Dnnqf, m);
}

void Heavy_heavy::cVar_T3R6yKib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rfndIlP, HV_BINOP_MULTIPLY, 1, m, &cBinop_5rfndIlP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YONAm2oA, m);
}

void Heavy_heavy::cMsg_DXHAPphh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.01f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7JevAcf4, HV_BINOP_SUBTRACT, 0, m, &cBinop_7JevAcf4_sendMessage);
}

void Heavy_heavy::cMsg_xCHWZHWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_8GlmbdPP, m);
}

void Heavy_heavy::cRandom_7WgZ3hz7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_jylH4vxl_sendMessage);
}

void Heavy_heavy::cSwitchcase_FcLpsfWl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jYiAjdPm, 0, m, &cSlice_jYiAjdPm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7WgZ3hz7, 0, m, &cRandom_7WgZ3hz7_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_jYiAjdPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7WgZ3hz7, 1, m, &cRandom_7WgZ3hz7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_imrfk0x6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xCHWZHWh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_jylH4vxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_imrfk0x6_sendMessage);
}

void Heavy_heavy::cVar_Ii7EDTMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JzKoOZU0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hdqWDPsq_sendMessage);
}

void Heavy_heavy::cBinop_KfKW9Sbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_C1f5KhGZ, m);
}

void Heavy_heavy::cMsg_m3OaAwz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J9Zn5pV0_sendMessage);
}

void Heavy_heavy::cSystem_J9Zn5pV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O5GKy1RX_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_O5GKy1RX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1WELBpFH_sendMessage);
}

void Heavy_heavy::cBinop_rb4B6vz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zOxNltIO_sendMessage);
}

void Heavy_heavy::cBinop_1WELBpFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rb4B6vz2, HV_BINOP_MULTIPLY, 1, m, &cBinop_rb4B6vz2_sendMessage);
}

void Heavy_heavy::cBinop_zOxNltIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Dn39Oh9P_sendMessage);
}

void Heavy_heavy::cBinop_Dn39Oh9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KfKW9Sbd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_j5OsoXrr, m);
}

void Heavy_heavy::cVar_yp9WSGLz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rb4B6vz2, HV_BINOP_MULTIPLY, 0, m, &cBinop_rb4B6vz2_sendMessage);
}

void Heavy_heavy::cSwitchcase_wKAkceQc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_RX4ZtGxy_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_RX4ZtGxy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oYo9Xruh_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_2Bbl3tKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1jVncyYT, HV_BINOP_MULTIPLY, 1, m, &cBinop_1jVncyYT_sendMessage);
}

void Heavy_heavy::cBinop_MmnnNDXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8XhLWntm, 2, m, &cDelay_8XhLWntm_sendMessage);
}

void Heavy_heavy::cDelay_8XhLWntm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8XhLWntm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8XhLWntm, 0, m, &cDelay_8XhLWntm_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_qAQHyiub, 1, m);
}

void Heavy_heavy::cCast_oYo9Xruh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RX4ZtGxy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8XhLWntm, 0, m, &cDelay_8XhLWntm_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_qAQHyiub, 1, m);
}

void Heavy_heavy::cBinop_1jVncyYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MmnnNDXR_sendMessage);
}

void Heavy_heavy::cMsg_YMtB25AC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8e73k1aC_sendMessage);
}

void Heavy_heavy::cSystem_8e73k1aC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2Bbl3tKR_sendMessage);
}

void Heavy_heavy::cVar_3J77N9X9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1jVncyYT, HV_BINOP_MULTIPLY, 0, m, &cBinop_1jVncyYT_sendMessage);
}

void Heavy_heavy::cMsg_RX4ZtGxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8XhLWntm, 0, m, &cDelay_8XhLWntm_sendMessage);
}

void Heavy_heavy::cCast_hdqWDPsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DXHAPphh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_gux1GOca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_wKAkceQc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_5rfndIlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Kb3rm5V3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 15.0f, 0, m, &cBinop_1wZq5Dnf_sendMessage);
}

void Heavy_heavy::cCast_JzKoOZU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7JevAcf4, HV_BINOP_SUBTRACT, 1, m, &cBinop_7JevAcf4_sendMessage);
}

void Heavy_heavy::cBinop_Joqw7DLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_29jZT7BF, m);
}

void Heavy_heavy::cVar_509cKw2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6mwBuMzu, HV_BINOP_MULTIPLY, 0, m, &cBinop_6mwBuMzu_sendMessage);
}

void Heavy_heavy::cBinop_1AwvmOz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uVGwxZrK_sendMessage);
}

void Heavy_heavy::cBinop_uVGwxZrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Joqw7DLv_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_owN6Jq8y, m);
}

void Heavy_heavy::cSystem_QfVMMB0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jM50uKWf_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_mDgSc7dL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QfVMMB0r_sendMessage);
}

void Heavy_heavy::cBinop_ehldyf9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6mwBuMzu, HV_BINOP_MULTIPLY, 1, m, &cBinop_6mwBuMzu_sendMessage);
}

void Heavy_heavy::cMsg_jM50uKWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ehldyf9Z_sendMessage);
}

void Heavy_heavy::cBinop_6mwBuMzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1AwvmOz4_sendMessage);
}

void Heavy_heavy::cVar_M7YepMk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ii7EDTMI, 0, m, &cVar_Ii7EDTMI_sendMessage);
}

void Heavy_heavy::cVar_JYynSCky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T3R6yKib, 0, m, &cVar_T3R6yKib_sendMessage);
}

void Heavy_heavy::cBinop_7JevAcf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_509cKw2j, 0, m, &cVar_509cKw2j_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yp9WSGLz, 0, m, &cVar_yp9WSGLz_sendMessage);
}

void Heavy_heavy::cReceive_EasJdbrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_DLcjK8g3_sendMessage);
}

void Heavy_heavy::cBinop_hTGxLfQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ESKje9DI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_q1QBTBDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QElJesAj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IU4F68MK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N5J0qnO8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_okY4g5uA_sendMessage);
}

void Heavy_heavy::cBinop_zeoatiM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_DaHGwuGN_sendMessage);
}

void Heavy_heavy::cCast_fZa5cPMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVRkPFwZ, HV_BINOP_DIVIDE, 1, m, &cBinop_yVRkPFwZ_sendMessage);
}

void Heavy_heavy::cBinop_yVRkPFwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_cGEDBl02, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Kzrpzbbk, 0, m);
}

void Heavy_heavy::cBinop_5dVfZ2Gh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cDelay_DBrWqvas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DBrWqvas, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DBrWqvas, 0, m, &cDelay_DBrWqvas_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jIhAtfjk_sendMessage);
}

void Heavy_heavy::cMsg_uJr8glBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DBrWqvas, 0, m, &cDelay_DBrWqvas_sendMessage);
}

void Heavy_heavy::cBinop_SVUYUhmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AYFuz7tO, HV_BINOP_MULTIPLY, 1, m, &cBinop_AYFuz7tO_sendMessage);
}

void Heavy_heavy::cSystem_L57BV3wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SVUYUhmD_sendMessage);
}

void Heavy_heavy::cMsg_VDeFibH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L57BV3wF_sendMessage);
}

void Heavy_heavy::cBinop_RcW1cUm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DBrWqvas, 2, m, &cDelay_DBrWqvas_sendMessage);
}

void Heavy_heavy::cCast_AmVFHcaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uJr8glBC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DBrWqvas, 0, m, &cDelay_DBrWqvas_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jIhAtfjk_sendMessage);
}

void Heavy_heavy::cSwitchcase_OXhJzimF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_uJr8glBC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_uJr8glBC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AmVFHcaS_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_xwwUsTnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AYFuz7tO, HV_BINOP_MULTIPLY, 0, m, &cBinop_AYFuz7tO_sendMessage);
}

void Heavy_heavy::cBinop_AYFuz7tO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RcW1cUm4_sendMessage);
}

void Heavy_heavy::sSample_6FZ2hYwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fdUao77p_sendMessage);
}

void Heavy_heavy::sSample_NAed3PxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zeoatiM6_sendMessage);
}

void Heavy_heavy::cVar_ftnCdwLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oQ7qxmHJ_sendMessage);
  cSwitchcase_cwpBcnLr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_oQ7qxmHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ftnCdwLh, 1, m, &cVar_ftnCdwLh_sendMessage);
}

void Heavy_heavy::cSwitchcase_yGP4eeJO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_pZkf94A3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_pZkf94A3_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hMm00IoS, 1, m, &cDelay_hMm00IoS_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oRc2vuwY_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cDelay_hMm00IoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hMm00IoS, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eiCjQZhO, 0, m, &cVar_eiCjQZhO_sendMessage);
}

void Heavy_heavy::cMsg_pZkf94A3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hMm00IoS, 0, m, &cDelay_hMm00IoS_sendMessage);
}

void Heavy_heavy::cCast_oRc2vuwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hMm00IoS, 0, m, &cDelay_hMm00IoS_sendMessage);
}

void Heavy_heavy::cBinop_eNLdgGBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fZa5cPMW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KmSX8E0J_sendMessage);
}

void Heavy_heavy::cUnop_760ONvtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_eiCjQZhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KFIjteJq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nSoxuo88, 0, m, &cIf_nSoxuo88_sendMessage);
}

void Heavy_heavy::cUnop_jGnCxWmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_KFIjteJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nSoxuo88, 1, m, &cIf_nSoxuo88_sendMessage);
}

void Heavy_heavy::cIf_nSoxuo88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_760ONvtJ_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jGnCxWmw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_iV7UPGpx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xzd3QCey, 0, m, &cVar_Xzd3QCey_sendMessage);
}

void Heavy_heavy::cBinop_1w6t7jhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0Q8jNvk, 2, m, &cDelay_M0Q8jNvk_sendMessage);
}

void Heavy_heavy::cMsg_cF03U0tU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3aOwoFHB_sendMessage);
}

void Heavy_heavy::cSystem_3aOwoFHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gVUjTfxr_sendMessage);
}

void Heavy_heavy::cSwitchcase_cwpBcnLr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_AEcWRrov_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_AEcWRrov_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kEmgchuj_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_ipeGVXBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VJ7jEO6y, HV_BINOP_MULTIPLY, 0, m, &cBinop_VJ7jEO6y_sendMessage);
}

void Heavy_heavy::cBinop_VJ7jEO6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1w6t7jhO_sendMessage);
}

void Heavy_heavy::cDelay_M0Q8jNvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_M0Q8jNvk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0Q8jNvk, 0, m, &cDelay_M0Q8jNvk_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_NAed3PxY, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_6FZ2hYwe, 1, m);
}

void Heavy_heavy::cMsg_AEcWRrov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0Q8jNvk, 0, m, &cDelay_M0Q8jNvk_sendMessage);
}

void Heavy_heavy::cCast_kEmgchuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AEcWRrov_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_M0Q8jNvk, 0, m, &cDelay_M0Q8jNvk_sendMessage);
  sSample_onMessage(_c, &Context(_c)->sSample_NAed3PxY, 1, m);
  sSample_onMessage(_c, &Context(_c)->sSample_6FZ2hYwe, 1, m);
}

void Heavy_heavy::cBinop_gVUjTfxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VJ7jEO6y, HV_BINOP_MULTIPLY, 1, m, &cBinop_VJ7jEO6y_sendMessage);
}

void Heavy_heavy::cMsg_Xh3NEsgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yVRkPFwZ, HV_BINOP_DIVIDE, 0, m, &cBinop_yVRkPFwZ_sendMessage);
}

void Heavy_heavy::cCast_jIhAtfjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YuQeecnE, 0, m, &cVar_YuQeecnE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PlmH5RuI, 0, m, &cVar_PlmH5RuI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e4cnTuIT, 0, m, &cVar_e4cnTuIT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3fV8DYo7, 0, m, &cVar_3fV8DYo7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jv6uQbwh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VkpHexyN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Wd5zzxdB, 0, m, &cVar_Wd5zzxdB_sendMessage);
}

void Heavy_heavy::cCast_KmSX8E0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xh3NEsgp_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_fdUao77p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_5dVfZ2Gh_sendMessage);
}

void Heavy_heavy::cBinop_DaHGwuGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_hnjRX3Ph_sendMessage);
}

void Heavy_heavy::cVar_Xzd3QCey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_eNLdgGBD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xwwUsTnP, 0, m, &cVar_xwwUsTnP_sendMessage);
  cSwitchcase_yGP4eeJO_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_eiCjQZhO, 1, m, &cVar_eiCjQZhO_sendMessage);
}

void Heavy_heavy::cBinop_HSnDXchq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_96Up93WQ, 1, m, &cVar_96Up93WQ_sendMessage);
}

void Heavy_heavy::cVar_96Up93WQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_HSnDXchq_sendMessage);
  cSwitchcase_OXhJzimF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_A60ikBQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led2", 0xBB2E5490, m);
}

void Heavy_heavy::cVar_y7XZjBX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWMWB4Pf, HV_BINOP_MULTIPLY, 0, m, &cBinop_SWMWB4Pf_sendMessage);
}

void Heavy_heavy::cMsg_9egjCen5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_Sjf9X17c_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_eEdfw32S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Sjf9X17c_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSystem_ilEppd5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bXuCeQxV_sendMessage);
}

void Heavy_heavy::cMsg_3E6QSo94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ilEppd5a_sendMessage);
}

void Heavy_heavy::cCast_T3nhZUXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YXrbQofi, 0, m, &cVar_YXrbQofi_sendMessage);
}

void Heavy_heavy::cCast_GQ4f17FZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hxZ78QZD_sendMessage);
}

void Heavy_heavy::cTabread_iBRUsAUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ISncNhf, HV_BINOP_ADD, 0, m, &cBinop_5ISncNhf_sendMessage);
}

void Heavy_heavy::cBinop_Y93CznNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_iBRUsAUO, 0, m, &cTabread_iBRUsAUO_sendMessage);
}

void Heavy_heavy::cSlice_3rE74PdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_iBRUsAUO, 1, m, &cTabread_iBRUsAUO_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_iBRUsAUO, 1, m, &cTabread_iBRUsAUO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Sjf9X17c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3rE74PdQ, 0, m, &cSlice_3rE74PdQ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T3nhZUXd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GQ4f17FZ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_YXrbQofi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3E6QSo94_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_bXuCeQxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y93CznNo, HV_BINOP_MIN, 1, m, &cBinop_Y93CznNo_sendMessage);
}

void Heavy_heavy::cBinop_hxZ78QZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y93CznNo, HV_BINOP_MIN, 0, m, &cBinop_Y93CznNo_sendMessage);
}

void Heavy_heavy::cMsg_u7Ak5BbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_Sjf9X17c_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_1SIOIIjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u7Ak5BbJ_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_5ISncNhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tbg0xtxI_sendMessage);
}

void Heavy_heavy::cVar_NQXnf83E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cXTwF7lV, 0, m, &cVar_cXTwF7lV_sendMessage);
}

void Heavy_heavy::cCast_mwRS145X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9egjCen5_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_cXTwF7lV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ISncNhf, HV_BINOP_ADD, 1, m, &cBinop_5ISncNhf_sendMessage);
}

void Heavy_heavy::cCast_kBlMTjO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XkvyTGqT, HV_BINOP_NEQ, 1, m, &cBinop_XkvyTGqT_sendMessage);
}

void Heavy_heavy::cCast_yF6fEYqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ceOwm0S0, 0, m, &cIf_ceOwm0S0_sendMessage);
}

void Heavy_heavy::cBinop_XkvyTGqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ceOwm0S0, 1, m, &cIf_ceOwm0S0_sendMessage);
}

void Heavy_heavy::cCast_jdhHxmjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W1sqLmzP, 0, m, &cVar_W1sqLmzP_sendMessage);
}

void Heavy_heavy::cCast_rL9ovqXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XkvyTGqT, HV_BINOP_NEQ, 0, m, &cBinop_XkvyTGqT_sendMessage);
}

void Heavy_heavy::cVar_W1sqLmzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_IehZzEIu_sendMessage);
}

void Heavy_heavy::cIf_ceOwm0S0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kBlMTjO9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jdhHxmjQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_3P5DJESP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XBsJVuGh, 0, m, &cSlice_XBsJVuGh_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_w7thGSOj, 0, m, &cSlice_w7thGSOj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rL9ovqXn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yF6fEYqP_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_w7thGSOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XkvyTGqT, HV_BINOP_NEQ, 1, m, &cBinop_XkvyTGqT_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_W1sqLmzP, 1, m, &cVar_W1sqLmzP_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XkvyTGqT, HV_BINOP_NEQ, 1, m, &cBinop_XkvyTGqT_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_W1sqLmzP, 1, m, &cVar_W1sqLmzP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_XBsJVuGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_W1sqLmzP, 0, m, &cVar_W1sqLmzP_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_W1sqLmzP, 0, m, &cVar_W1sqLmzP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::hTable_rCm5VamY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_xXiiKCiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Om2BUaJL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T288V4M3, 0, m, &cVar_T288V4M3_sendMessage);
  cMsg_VDeFibH1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xwwUsTnP, 0, m, &cVar_xwwUsTnP_sendMessage);
  cMsg_cF03U0tU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ipeGVXBn, 0, m, &cVar_ipeGVXBn_sendMessage);
  cMsg_2PkoNkst_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aq5IPPx4, 0, m, &cVar_aq5IPPx4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BFDXUKE4, 0, m, &cVar_BFDXUKE4_sendMessage);
  cMsg_m3OaAwz8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yp9WSGLz, 0, m, &cVar_yp9WSGLz_sendMessage);
  cSwitchcase_FcLpsfWl_onMessage(_c, NULL, 0, m, NULL);
  cMsg_mDgSc7dL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_509cKw2j, 0, m, &cVar_509cKw2j_sendMessage);
  cMsg_YMtB25AC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3J77N9X9, 0, m, &cVar_3J77N9X9_sendMessage);
  cMsg_3grV8mwv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Gt9NBsxE, 0, m, &cVar_Gt9NBsxE_sendMessage);
  cMsg_Osiq5BqY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A3KreRrW, 0, m, &cVar_A3KreRrW_sendMessage);
  cMsg_q5DfeqAf_sendMessage(_c, 0, m);
  cMsg_xPyrLCXp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0tF1mdMp, 0, m, &cVar_0tF1mdMp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OcmeB1Ma, 0, m, &cVar_OcmeB1Ma_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HnUKmVX2, 0, m, &cVar_HnUKmVX2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9wPF9xE3, 0, m, &cVar_9wPF9xE3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zdg9GVTU, 0, m, &cVar_zdg9GVTU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CoqneQ2C, 0, m, &cVar_CoqneQ2C_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EUHklioh, 0, m, &cVar_EUHklioh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IIUtvmui, 0, m, &cVar_IIUtvmui_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uCjNcF0P, 0, m, &cVar_uCjNcF0P_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_liJaMpCw, 0, m, &cVar_liJaMpCw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AMFXrXHx, 0, m, &cVar_AMFXrXHx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V3wfSgSd, 0, m, &cVar_V3wfSgSd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iTv4078v, 0, m, &cVar_iTv4078v_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pDaHVYXa, 0, m, &cVar_pDaHVYXa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_phpFgDNP, 0, m, &cVar_phpFgDNP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jGv32XE1, 0, m, &cVar_jGv32XE1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0J7y5UaU, 0, m, &cVar_0J7y5UaU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5Szf4UcC, 0, m, &cVar_5Szf4UcC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ftnCdwLh, 0, m, &cVar_ftnCdwLh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iV7UPGpx, 0, m, &cVar_iV7UPGpx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_siGlhqcE, 0, m, &cVar_siGlhqcE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lGtBKTpH, 0, m, &cVar_lGtBKTpH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kGAQTZ07, 0, m, &cVar_kGAQTZ07_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_m4pt4h1D, 0, m, &cVar_m4pt4h1D_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UF7ro4DQ, 0, m, &cVar_UF7ro4DQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1NU0nRw7, 0, m, &cVar_1NU0nRw7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FkrsnWLZ, 0, m, &cVar_FkrsnWLZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lJrEoy24, 0, m, &cVar_lJrEoy24_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f4C4FAAC, 0, m, &cVar_f4C4FAAC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WicG49wy, 0, m, &cVar_WicG49wy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qFYN691w, 0, m, &cVar_qFYN691w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4DH6ySqX, 0, m, &cVar_4DH6ySqX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_24OtEC1u, 0, m, &cVar_24OtEC1u_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_womksIq9, 0, m, &cVar_womksIq9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TY7JldFJ, 0, m, &cVar_TY7JldFJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9p2GwApI, 0, m, &cVar_9p2GwApI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M7YepMk9, 0, m, &cVar_M7YepMk9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JYynSCky, 0, m, &cVar_JYynSCky_sendMessage);
  cMsg_gux1GOca_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1SIOIIjR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NQXnf83E, 0, m, &cVar_NQXnf83E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f8AQAaVF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rXP5nvlu, 0, m, &cVar_rXP5nvlu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_17IWYmPR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CTysHU74, 0, m, &cVar_CTysHU74_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SKqXkmId, 0, m, &cVar_SKqXkmId_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JMExYTHw, 0, m, &cVar_JMExYTHw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TCCSr6Mm, 0, m, &cVar_TCCSr6Mm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Oi2cfEJy, 0, m, &cVar_Oi2cfEJy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_D2JhkqQY, 0, m, &cVar_D2JhkqQY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_96Up93WQ, 0, m, &cVar_96Up93WQ_sendMessage);
  cMsg_QoqxGQYf_sendMessage(_c, 0, m);
  cMsg_y4nY2Tsj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0Zmhk0Av, 0, m, &cVar_0Zmhk0Av_sendMessage);
  cMsg_aMeH2OCz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nI69gyzQ, 0, m, &cVar_nI69gyzQ_sendMessage);
  cMsg_Y2S6ChM9_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_A7V2BVoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24OtEC1u, 0, m, &cVar_24OtEC1u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XWHhuiGq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9TE3Vfq7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1XwIeljv_sendMessage);
}

void Heavy_heavy::cCast_OugGsGZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4lsxxNjK_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_NIYhqLT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_PlHcYQez_sendMessage);
}

void Heavy_heavy::cSystem_at742JMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Fj80RZ2d_sendMessage);
}

void Heavy_heavy::cMsg_Ph4qTyTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_at742JMb_sendMessage);
}

void Heavy_heavy::cCast_YhrV4y9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cAz5CY4V_sendMessage);
}

void Heavy_heavy::cBinop_cAz5CY4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nH91ZAbe, HV_BINOP_MIN, 0, m, &cBinop_nH91ZAbe_sendMessage);
}

void Heavy_heavy::cBinop_Fj80RZ2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nH91ZAbe, HV_BINOP_MIN, 1, m, &cBinop_nH91ZAbe_sendMessage);
}

void Heavy_heavy::cVar_jlGb6coA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ph4qTyTe_sendMessage(_c, 0, m);
}

void Heavy_heavy::cTabread_9qvYaNRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFtkSTL7, HV_BINOP_ADD, 0, m, &cBinop_MFtkSTL7_sendMessage);
}

void Heavy_heavy::cSlice_aCD1fiAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_9qvYaNRW, 1, m, &cTabread_9qvYaNRW_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_9qvYaNRW, 1, m, &cTabread_9qvYaNRW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_TGwps6zF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_aCD1fiAk, 0, m, &cSlice_aCD1fiAk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JxzeEwFb_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YhrV4y9F_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_nH91ZAbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_9qvYaNRW, 0, m, &cTabread_9qvYaNRW_sendMessage);
}

void Heavy_heavy::cCast_JxzeEwFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jlGb6coA, 0, m, &cVar_jlGb6coA_sendMessage);
}

void Heavy_heavy::cMsg_WeuDFg0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "major_scale");
  cSwitchcase_TGwps6zF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_JicuGDQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MFtkSTL7, HV_BINOP_ADD, 1, m, &cBinop_MFtkSTL7_sendMessage);
}

void Heavy_heavy::cBinop_MFtkSTL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_d4MvtaRL_sendMessage);
}

void Heavy_heavy::cCast_17IWYmPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ep1qIoMM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_jd7hSFpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TGwps6zF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_lZ76NgdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WeuDFg0o_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_CTysHU74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JicuGDQs, 0, m, &cVar_JicuGDQs_sendMessage);
}

void Heavy_heavy::cMsg_ep1qIoMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "set");
  msg_setSymbol(m, 1, "minor_scale");
  cSwitchcase_TGwps6zF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_rAKjNjoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VCSVXnSF, 0, m, &cVar_VCSVXnSF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_srghvoyK, 0, m, &cVar_srghvoyK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rDA47Ugj, 0, m, &cVar_rDA47Ugj_sendMessage);
}

void Heavy_heavy::cVar_DU3Foeoz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PcQj8b80, HV_BINOP_MULTIPLY, 1, m, &cBinop_PcQj8b80_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l1NnATSi, HV_BINOP_LESS_THAN, 1, m, &cBinop_l1NnATSi_sendMessage);
}

void Heavy_heavy::cBinop_PcQj8b80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tfUEcR6d, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_tfUEcR6d_sendMessage);
}

void Heavy_heavy::cVar_3fV8DYo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YCi7ge2I_sendMessage);
}

void Heavy_heavy::cCast_amV0N4eP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_Zf9d4DGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ksDLoPB6, HV_BINOP_ADD, 1, m, &cBinop_ksDLoPB6_sendMessage);
}

void Heavy_heavy::cVar_p3ZDdJHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tfUEcR6d, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_tfUEcR6d_sendMessage);
}

void Heavy_heavy::cIf_G9vhqrRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_xVLbB8LS_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5Twwru5Y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_8ctndR28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uAyGBvD2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_G9vhqrRH, 0, m, &cIf_G9vhqrRH_sendMessage);
}

void Heavy_heavy::cUnop_xVLbB8LS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zf9d4DGR, 0, m, &cVar_Zf9d4DGR_sendMessage);
}

void Heavy_heavy::cUnop_5Twwru5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zf9d4DGR, 0, m, &cVar_Zf9d4DGR_sendMessage);
}

void Heavy_heavy::cBinop_uAyGBvD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_G9vhqrRH, 1, m, &cIf_G9vhqrRH_sendMessage);
}

void Heavy_heavy::cBinop_ksDLoPB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PcQj8b80, HV_BINOP_MULTIPLY, 0, m, &cBinop_PcQj8b80_sendMessage);
}

void Heavy_heavy::cBinop_tfUEcR6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l1NnATSi, HV_BINOP_LESS_THAN, 0, m, &cBinop_l1NnATSi_sendMessage);
}

void Heavy_heavy::cVar_7qxiFe8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NSpMUogP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xGOQYi7G, 0, m, &cIf_xGOQYi7G_sendMessage);
}

void Heavy_heavy::cBinop_NSpMUogP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xGOQYi7G, 1, m, &cIf_xGOQYi7G_sendMessage);
}

void Heavy_heavy::cIf_xGOQYi7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_k1YmhZOr_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FcJScFD9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_k1YmhZOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DU3Foeoz, 0, m, &cVar_DU3Foeoz_sendMessage);
}

void Heavy_heavy::cUnop_FcJScFD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DU3Foeoz, 0, m, &cVar_DU3Foeoz_sendMessage);
}

void Heavy_heavy::cBinop_YCi7ge2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3fV8DYo7, 1, m, &cVar_3fV8DYo7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ksDLoPB6, HV_BINOP_ADD, 0, m, &cBinop_ksDLoPB6_sendMessage);
}

void Heavy_heavy::cBinop_l1NnATSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7xud3MT2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_BfrxIcaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p3ZDdJHn, 0, m, &cVar_p3ZDdJHn_sendMessage);
}

void Heavy_heavy::cVar_MsaSy2JY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_guk0V3oU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_unQZl1CI, 0, m, &cIf_unQZl1CI_sendMessage);
}

void Heavy_heavy::cUnop_tpoaF337_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p3ZDdJHn, 0, m, &cVar_p3ZDdJHn_sendMessage);
}

void Heavy_heavy::cIf_unQZl1CI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_tpoaF337_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BfrxIcaj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_guk0V3oU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_unQZl1CI, 1, m, &cIf_unQZl1CI_sendMessage);
}

void Heavy_heavy::cCast_rhVq6oTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_amV0N4eP_sendMessage);
}

void Heavy_heavy::cSwitchcase_7xud3MT2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rhVq6oTT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rAKjNjoO_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_qFYN691w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7qxiFe8Y, 0, m, &cVar_7qxiFe8Y_sendMessage);
}

void Heavy_heavy::cVar_WicG49wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MsaSy2JY, 0, m, &cVar_MsaSy2JY_sendMessage);
}

void Heavy_heavy::cVar_4DH6ySqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8ctndR28, 0, m, &cVar_8ctndR28_sendMessage);
}

void Heavy_heavy::cBinop_1wZq5Dnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 3.0f, 0, m, &cBinop_jiocF9pV_sendMessage);
}

void Heavy_heavy::cCast_IU4F68MK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y7XZjBX1, 1, m, &cVar_y7XZjBX1_sendMessage);
}

void Heavy_heavy::cMsg_iUr2qcHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vY7ltqjX, HV_BINOP_SUBTRACT, 0, m, &cBinop_vY7ltqjX_sendMessage);
}

void Heavy_heavy::cReceive_uOz9jZvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0WvpYErh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WFpRrfYQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.85f, 0, m, &cBinop_R68qynew_sendMessage);
}

void Heavy_heavy::cSend_ESKje9DI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dzNhQpi6_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_r3tL2oJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_dENu1Cux_sendMessage);
}

void Heavy_heavy::cSend_lZhucViH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GJ7u5FID_sendMessage(_c, 0, m);
}

void Heavy_heavy::hTable_Mt9UjRaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_NxCJhGRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led3", 0xE14EE92B, m);
}

void Heavy_heavy::cCast_1XwIeljv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y7XZjBX1, 0, m, &cVar_y7XZjBX1_sendMessage);
}

void Heavy_heavy::cBinop_IehZzEIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9AptJOqo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_SWMWB4Pf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_womksIq9, 0, m, &cVar_womksIq9_sendMessage);
}

void Heavy_heavy::cCast_0WvpYErh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vY7ltqjX, HV_BINOP_SUBTRACT, 1, m, &cBinop_vY7ltqjX_sendMessage);
}

void Heavy_heavy::cBinop_bM8WBF6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TY7JldFJ, 0, m, &cVar_TY7JldFJ_sendMessage);
}

void Heavy_heavy::cBinop_YTJ8tbu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k8oeYd0M, 1, m, &cVar_k8oeYd0M_sendMessage);
}

void Heavy_heavy::cVar_k8oeYd0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YTJ8tbu7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_w65tVDXK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NbTuzDPc, 1, m, &cIf_NbTuzDPc_sendMessage);
}

void Heavy_heavy::cUnop_xrHsMcTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yyZEGycE, 0, m, &cVar_yyZEGycE_sendMessage);
}

void Heavy_heavy::cBinop_y8xi5MQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PLC61W4w, 1, m, &cIf_PLC61W4w_sendMessage);
}

void Heavy_heavy::cUnop_VS3wTNWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yyZEGycE, 0, m, &cVar_yyZEGycE_sendMessage);
}

void Heavy_heavy::cIf_PLC61W4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_VS3wTNWe_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xrHsMcTK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_4SQJtis9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_y8xi5MQW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PLC61W4w, 0, m, &cIf_PLC61W4w_sendMessage);
}

void Heavy_heavy::cIf_F71N2acF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_H6yvkYV5, 0, m, &cIf_H6yvkYV5_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_eRBfVVVO, 0, m, &cIf_eRBfVVVO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_w65tVDXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F71N2acF, 1, m, &cIf_F71N2acF_sendMessage);
}

void Heavy_heavy::cIf_NbTuzDPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eWGtbgKO, HV_BINOP_ADD, 0, m, &cBinop_eWGtbgKO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_eWGtbgKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_H6yvkYV5, 0, m, &cIf_H6yvkYV5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eRBfVVVO, 0, m, &cIf_eRBfVVVO_sendMessage);
}

void Heavy_heavy::cVar_phpFgDNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Pu04dvRZ, 0, m, &cVar_Pu04dvRZ_sendMessage);
}

void Heavy_heavy::cSlice_VlLI093L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SVKgX4xY, HV_BINOP_ADD, 1, m, &cBinop_SVKgX4xY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_5xTTi1VU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HtokTgUc, HV_BINOP_ADD, 1, m, &cBinop_HtokTgUc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_ptwWNLZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_csk0xgSn, HV_BINOP_ADD, 1, m, &cBinop_csk0xgSn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_M2pNErhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_ecJB8UhS, 0, m, &cVar_ecJB8UhS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_1RY1qx2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_eWGtbgKO, HV_BINOP_ADD, 1, m, &cBinop_eWGtbgKO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_srghvoyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_iigr2mIG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GUPzQbWA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_H6yvkYV5, 1, m, &cIf_H6yvkYV5_sendMessage);
}

void Heavy_heavy::cBinop_iigr2mIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_srghvoyK, 1, m, &cVar_srghvoyK_sendMessage);
}

void Heavy_heavy::cBinop_17PCVuuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DH8E0hTk, 1, m, &cVar_DH8E0hTk_sendMessage);
}

void Heavy_heavy::cVar_DH8E0hTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_17PCVuuh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_t1nIcwXz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6zfyrPBY, 1, m, &cIf_6zfyrPBY_sendMessage);
}

void Heavy_heavy::cIf_eRBfVVVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_jd7hSFpQ, 0, m, &cVar_jd7hSFpQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_GUPzQbWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eRBfVVVO, 1, m, &cIf_eRBfVVVO_sendMessage);
}

void Heavy_heavy::cBinop_ly59XhgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jd7hSFpQ, 0, m, &cVar_jd7hSFpQ_sendMessage);
}

void Heavy_heavy::cIf_H6yvkYV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ly59XhgT, HV_BINOP_ADD, 0, m, &cBinop_ly59XhgT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_yyZEGycE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ly59XhgT, HV_BINOP_ADD, 1, m, &cBinop_ly59XhgT_sendMessage);
}

void Heavy_heavy::cVar_pDaHVYXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fXt5lRf2, 0, m, &cVar_fXt5lRf2_sendMessage);
}

void Heavy_heavy::cVar_iTv4078v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DH8E0hTk, 0, m, &cVar_DH8E0hTk_sendMessage);
}

void Heavy_heavy::cVar_0J7y5UaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_srghvoyK, 0, m, &cVar_srghvoyK_sendMessage);
}

void Heavy_heavy::cIf_xgP72M2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HtokTgUc, HV_BINOP_ADD, 0, m, &cBinop_HtokTgUc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_TOkhATHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CGN7QOUf, 1, m, &cIf_CGN7QOUf_sendMessage);
}

void Heavy_heavy::cBinop_HtokTgUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NbTuzDPc, 0, m, &cIf_NbTuzDPc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_F71N2acF, 0, m, &cIf_F71N2acF_sendMessage);
}

void Heavy_heavy::cIf_CGN7QOUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_NbTuzDPc, 0, m, &cIf_NbTuzDPc_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_F71N2acF, 0, m, &cIf_F71N2acF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_AyazTSg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Pu04dvRZ, 1, m, &cVar_Pu04dvRZ_sendMessage);
}

void Heavy_heavy::cVar_Pu04dvRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AyazTSg8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_TOkhATHH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xgP72M2O, 1, m, &cIf_xgP72M2O_sendMessage);
}

void Heavy_heavy::cBinop_csk0xgSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2BDGeYq4, 0, m, &cIf_2BDGeYq4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_5iBXfrWr, 0, m, &cIf_5iBXfrWr_sendMessage);
}

void Heavy_heavy::cIf_vjW77bD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_2BDGeYq4, 0, m, &cIf_2BDGeYq4_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5iBXfrWr, 0, m, &cIf_5iBXfrWr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_t1nIcwXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vjW77bD3, 1, m, &cIf_vjW77bD3_sendMessage);
}

void Heavy_heavy::cIf_6zfyrPBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_csk0xgSn, HV_BINOP_ADD, 0, m, &cBinop_csk0xgSn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_hFlUgt7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fXt5lRf2, 1, m, &cVar_fXt5lRf2_sendMessage);
}

void Heavy_heavy::cVar_fXt5lRf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hFlUgt7r_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ZK6bdnrD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2BDGeYq4, 1, m, &cIf_2BDGeYq4_sendMessage);
}

void Heavy_heavy::cVar_ecJB8UhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4SQJtis9, 0, m, &cVar_4SQJtis9_sendMessage);
}

void Heavy_heavy::cBinop_SVKgX4xY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xgP72M2O, 0, m, &cIf_xgP72M2O_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CGN7QOUf, 0, m, &cIf_CGN7QOUf_sendMessage);
}

void Heavy_heavy::cBinop_ZK6bdnrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5iBXfrWr, 1, m, &cIf_5iBXfrWr_sendMessage);
}

void Heavy_heavy::cIf_2BDGeYq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_SVKgX4xY, HV_BINOP_ADD, 0, m, &cBinop_SVKgX4xY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_5iBXfrWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_xgP72M2O, 0, m, &cIf_xgP72M2O_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_CGN7QOUf, 0, m, &cIf_CGN7QOUf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_jGv32XE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k8oeYd0M, 0, m, &cVar_k8oeYd0M_sendMessage);
}

void Heavy_heavy::cVar_5Szf4UcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ecJB8UhS, 0, m, &cVar_ecJB8UhS_sendMessage);
}

void Heavy_heavy::cVar_Oc9uv7pM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IUH79Swa, HV_BINOP_ADD, 1, m, &cBinop_IUH79Swa_sendMessage);
}

void Heavy_heavy::cVar_lJrEoy24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UM6FQ5w2, 0, m, &cVar_UM6FQ5w2_sendMessage);
}

void Heavy_heavy::cCast_UMifFPOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cBinop_0Jk2L3IL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sr0XDdFK, HV_BINOP_LESS_THAN, 0, m, &cBinop_Sr0XDdFK_sendMessage);
}

void Heavy_heavy::cBinop_Sr0XDdFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_emGgtkJm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_f4C4FAAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V97p5PLM, 0, m, &cVar_V97p5PLM_sendMessage);
}

void Heavy_heavy::cBinop_IUH79Swa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMbtG6mD, HV_BINOP_MULTIPLY, 0, m, &cBinop_gMbtG6mD_sendMessage);
}

void Heavy_heavy::cIf_hwKAvrmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_q7ihvQeH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3XqATg54_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_V97p5PLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_irD4UJKP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hwKAvrmp, 0, m, &cIf_hwKAvrmp_sendMessage);
}

void Heavy_heavy::cUnop_q7ihvQeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oc9uv7pM, 0, m, &cVar_Oc9uv7pM_sendMessage);
}

void Heavy_heavy::cBinop_irD4UJKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hwKAvrmp, 1, m, &cIf_hwKAvrmp_sendMessage);
}

void Heavy_heavy::cUnop_3XqATg54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oc9uv7pM, 0, m, &cVar_Oc9uv7pM_sendMessage);
}

void Heavy_heavy::cVar_e4cnTuIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_DeE5J0jz_sendMessage);
}

void Heavy_heavy::cCast_cU4AkRCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UMifFPOV_sendMessage);
}

void Heavy_heavy::cSwitchcase_emGgtkJm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cU4AkRCr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7pxd9YmL_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cVar_10QShX44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gMbtG6mD, HV_BINOP_MULTIPLY, 1, m, &cBinop_gMbtG6mD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sr0XDdFK, HV_BINOP_LESS_THAN, 1, m, &cBinop_Sr0XDdFK_sendMessage);
}

void Heavy_heavy::cVar_gc8ivMTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Jk2L3IL, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_0Jk2L3IL_sendMessage);
}

void Heavy_heavy::cBinop_DeE5J0jz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e4cnTuIT, 1, m, &cVar_e4cnTuIT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IUH79Swa, HV_BINOP_ADD, 0, m, &cBinop_IUH79Swa_sendMessage);
}

void Heavy_heavy::cBinop_gMbtG6mD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Jk2L3IL, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_0Jk2L3IL_sendMessage);
}

void Heavy_heavy::cBinop_uzfiJlSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Natmjv9h, 1, m, &cIf_Natmjv9h_sendMessage);
}

void Heavy_heavy::cUnop_rPaVQEaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gc8ivMTL, 0, m, &cVar_gc8ivMTL_sendMessage);
}

void Heavy_heavy::cVar_22NyCupc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uzfiJlSb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Natmjv9h, 0, m, &cIf_Natmjv9h_sendMessage);
}

void Heavy_heavy::cUnop_BXv8ZkpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gc8ivMTL, 0, m, &cVar_gc8ivMTL_sendMessage);
}

void Heavy_heavy::cIf_Natmjv9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_rPaVQEaV_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BXv8ZkpG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_7pxd9YmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c3Fq9tyi, 0, m, &cVar_c3Fq9tyi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_k8oeYd0M, 0, m, &cVar_k8oeYd0M_sendMessage);
}

void Heavy_heavy::cUnop_4Owxd5F0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_10QShX44, 0, m, &cVar_10QShX44_sendMessage);
}

void Heavy_heavy::cIf_iW85tzEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_xsK7RTAS_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4Owxd5F0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_xsK7RTAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_10QShX44, 0, m, &cVar_10QShX44_sendMessage);
}

void Heavy_heavy::cBinop_wb2GOfw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iW85tzEl, 1, m, &cIf_iW85tzEl_sendMessage);
}

void Heavy_heavy::cVar_UM6FQ5w2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_wb2GOfw4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iW85tzEl, 0, m, &cIf_iW85tzEl_sendMessage);
}

void Heavy_heavy::cVar_FkrsnWLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_22NyCupc, 0, m, &cVar_22NyCupc_sendMessage);
}

void Heavy_heavy::cReceive_M4XfIMHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VQHv5kv3_sendMessage(_c, 0, m);
}

void Heavy_heavy::cIf_DlKwv16p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Rk0OLIwr_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DFYfgnPU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_Rk0OLIwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KoyCQRGX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_J06HybW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hzRsUvgK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_DlKwv16p, 0, m, &cIf_DlKwv16p_sendMessage);
}

void Heavy_heavy::cBinop_hzRsUvgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DlKwv16p, 1, m, &cIf_DlKwv16p_sendMessage);
}

void Heavy_heavy::cUnop_DFYfgnPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KoyCQRGX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cCast_N5J0qnO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y7XZjBX1, 0, m, &cVar_y7XZjBX1_sendMessage);
}

void Heavy_heavy::cBinop_tbg0xtxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5IMVqESY_sendMessage);
}

void Heavy_heavy::cMsg_B3ZwQ9ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rxQ5nuEP, HV_BINOP_POW, 0, m, &cBinop_rxQ5nuEP_sendMessage);
}

void Heavy_heavy::cBinop_Q9kUBxmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zeDTWVXS, 0, m, &cPack_zeDTWVXS_sendMessage);
}

void Heavy_heavy::cBinop_rxQ5nuEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Q9kUBxmy_sendMessage);
}

void Heavy_heavy::cBinop_5IMVqESY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rxQ5nuEP, HV_BINOP_POW, 1, m, &cBinop_rxQ5nuEP_sendMessage);
  cMsg_B3ZwQ9ou_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_GX8xQaA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PcwPRJcQ, HV_BINOP_POW, 1, m, &cBinop_PcwPRJcQ_sendMessage);
  cMsg_jJ1NVVRg_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_jJ1NVVRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PcwPRJcQ, HV_BINOP_POW, 0, m, &cBinop_PcwPRJcQ_sendMessage);
}

void Heavy_heavy::cBinop_RBDxHKhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8w1hN5Hb, 0, m, &cPack_8w1hN5Hb_sendMessage);
}

void Heavy_heavy::cBinop_PcwPRJcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_RBDxHKhD_sendMessage);
}

void Heavy_heavy::cBinop_tMerIVrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_GX8xQaA2_sendMessage);
}

void Heavy_heavy::cPack_0yKPt9Ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_2z7YmJXc, 0, m, NULL);
}

void Heavy_heavy::cPack_zeDTWVXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_iOIr9slV, 0, m, NULL);
}

void Heavy_heavy::cVar_SKqXkmId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KWMgpVDy, 0, m, &cVar_KWMgpVDy_sendMessage);
}

void Heavy_heavy::cBinop_nZg6wboh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0yKPt9Ah, 0, m, &cPack_0yKPt9Ah_sendMessage);
}

void Heavy_heavy::cBinop_TyVqIIWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ch9zhjDb, HV_BINOP_POW, 1, m, &cBinop_Ch9zhjDb_sendMessage);
  cMsg_NN2yylVt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_d4MvtaRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_TyVqIIWi_sendMessage);
}

void Heavy_heavy::cBinop_Ch9zhjDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_nZg6wboh_sendMessage);
}

void Heavy_heavy::cMsg_NN2yylVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ch9zhjDb, HV_BINOP_POW, 0, m, &cBinop_Ch9zhjDb_sendMessage);
}

void Heavy_heavy::cPack_8w1hN5Hb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nfBQiNlR, 0, m, NULL);
}

void Heavy_heavy::cVar_KWMgpVDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_zeDTWVXS, 1, m, &cPack_zeDTWVXS_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_8w1hN5Hb, 1, m, &cPack_8w1hN5Hb_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_0yKPt9Ah, 1, m, &cPack_0yKPt9Ah_sendMessage);
}

void Heavy_heavy::cVar_nmE2inuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ESKje9DI_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_Gx1gSF1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9AptJOqo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_XBYGM5Rf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fcrNMaha_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_73fLIvo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.3f, 0, m, &cBinop_l1Ftlmxk_sendMessage);
}

void Heavy_heavy::cMsg_QoqxGQYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  cVar_onMessage(_c, &Context(_c)->cVar_nmE2inuR, 0, m, &cVar_nmE2inuR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xJa13LF8, 0, m, &cVar_xJa13LF8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Gx1gSF1u, 0, m, &cVar_Gx1gSF1u_sendMessage);
}

void Heavy_heavy::cVar_D2JhkqQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wn29EVHQ, 0, m, &cVar_Wn29EVHQ_sendMessage);
}

void Heavy_heavy::cVar_czeDUCIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9d3khCX1, 0, m, &cVar_9d3khCX1_sendMessage);
}

void Heavy_heavy::cBinop_Q2tcLwAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qQoRCBU9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NK18WIAf, m);
}

void Heavy_heavy::cBinop_meHpNlHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Q2tcLwAJ_sendMessage);
}

void Heavy_heavy::cVar_JMExYTHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_czeDUCIf, 0, m, &cVar_czeDUCIf_sendMessage);
}

void Heavy_heavy::cBinop_dKeVAo7R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y98HKbgn, HV_BINOP_MULTIPLY, 1, m, &cBinop_Y98HKbgn_sendMessage);
}

void Heavy_heavy::cMsg_p6aWwXD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dKeVAo7R_sendMessage);
}

void Heavy_heavy::cMsg_Osiq5BqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Aq6BDLYR_sendMessage);
}

void Heavy_heavy::cSystem_Aq6BDLYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p6aWwXD9_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Y98HKbgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AJMBoXqi_sendMessage);
}

void Heavy_heavy::cBinop_NqSe9li9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_T1iByYAv, m);
}

void Heavy_heavy::cVar_A3KreRrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y98HKbgn, HV_BINOP_MULTIPLY, 0, m, &cBinop_Y98HKbgn_sendMessage);
}

void Heavy_heavy::cBinop_AJMBoXqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_C0UeAIUy_sendMessage);
}

void Heavy_heavy::cBinop_C0UeAIUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NqSe9li9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zHKJ79b9, m);
}

void Heavy_heavy::cVar_tuuHqt0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.99f, 0, m, &cBinop_meHpNlHu_sendMessage);
}

void Heavy_heavy::cMsg_s0t6Awhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WmqXdaW8, HV_BINOP_SUBTRACT, 0, m, &cBinop_WmqXdaW8_sendMessage);
}

void Heavy_heavy::cVar_Wn29EVHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_l9pZtyY4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bZmh5i8V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QdEFc1gI_sendMessage);
}

void Heavy_heavy::cBinop_mIrutLzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gG29Dd3U, m);
}

void Heavy_heavy::cVar_0Zmhk0Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X4Siwlcv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_aMeH2OCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VwVjnwls_sendMessage);
}

void Heavy_heavy::cSystem_VwVjnwls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mIrutLzW_sendMessage);
}

void Heavy_heavy::cBinop_16QdjNwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_35UJXhL5, m);
}

void Heavy_heavy::cMsg_X4Siwlcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1FhulqmJ_sendMessage);
}

void Heavy_heavy::cSystem_1FhulqmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_16QdjNwP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oI7okc9R, m);
}

void Heavy_heavy::cDelay_xtC51Tl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xtC51Tl0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_g3bZWNGk, 0, m, &cDelay_g3bZWNGk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xtC51Tl0, 0, m, &cDelay_xtC51Tl0_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_COmKKq3e, 1, m, NULL);
}

void Heavy_heavy::cCast_t7kKcNem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xtC51Tl0, 0, m, &cDelay_xtC51Tl0_sendMessage);
}

void Heavy_heavy::hTable_t4UDgNYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hKxwBwAk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xtC51Tl0, 2, m, &cDelay_xtC51Tl0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t7kKcNem_sendMessage);
}

void Heavy_heavy::cBinop_gcwl8fG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_7qeshdYp_sendMessage);
}

void Heavy_heavy::cBinop_7qeshdYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qsi8Jv7M_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_qsi8Jv7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_t4UDgNYF, 0, m, &hTable_t4UDgNYF_sendMessage);
}

void Heavy_heavy::cSystem_R5g96Nrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gcwl8fG9_sendMessage);
}

void Heavy_heavy::cMsg_xPyrLCXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R5g96Nrx_sendMessage);
}

void Heavy_heavy::cMsg_hKxwBwAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_g3bZWNGk, 2, m, &cDelay_g3bZWNGk_sendMessage);
}

void Heavy_heavy::cDelay_g3bZWNGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_g3bZWNGk, m);
  cMsg_RN0wolTa_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_RN0wolTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_t4UDgNYF, 0, m, &hTable_t4UDgNYF_sendMessage);
}

void Heavy_heavy::cCast_bZmh5i8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s0t6Awhy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_lOmHBysN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_RSHaewZ1_sendMessage);
}

void Heavy_heavy::cBinop_WmqXdaW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_wmRaHESH_sendMessage);
}

void Heavy_heavy::cCast_QdEFc1gI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WmqXdaW8, HV_BINOP_SUBTRACT, 1, m, &cBinop_WmqXdaW8_sendMessage);
}

void Heavy_heavy::cUnop_wmRaHESH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ILEJFr81, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nn3e1DEX, m);
}

void Heavy_heavy::cBinop_ICkaydqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DFmvc5vC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_53Ykap3e_sendMessage);
}

void Heavy_heavy::cMsg_ea6axT5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_T1axzyhg, 0, m, NULL);
}

void Heavy_heavy::cUnop_l9pZtyY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xSajiZR9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3BKjnCnH, m);
}

void Heavy_heavy::cCast_53Ykap3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9d3khCX1, 0, m, &cVar_9d3khCX1_sendMessage);
}

void Heavy_heavy::cVar_TCCSr6Mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lOmHBysN, 0, m, &cVar_lOmHBysN_sendMessage);
}

void Heavy_heavy::cVar_Oi2cfEJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tuuHqt0e, 0, m, &cVar_tuuHqt0e_sendMessage);
}

void Heavy_heavy::cMsg_sruA67Gs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_XlagPEq3, 0, m, &hTable_XlagPEq3_sendMessage);
}

void Heavy_heavy::cMsg_xt3d96iy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_XlagPEq3, 0, m, &hTable_XlagPEq3_sendMessage);
}

void Heavy_heavy::cBinop_EIpXbmQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sruA67Gs_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_zrvezbO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5PcJlx7w_sendMessage);
}

void Heavy_heavy::cMsg_q5DfeqAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zrvezbO2_sendMessage);
}

void Heavy_heavy::cDelay_y9krDOBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y9krDOBO, m);
  cMsg_xt3d96iy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_GSnAGLpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qb8h4TUp, 0, m, &cDelay_qb8h4TUp_sendMessage);
}

void Heavy_heavy::cMsg_gka4Kirr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_y9krDOBO, 2, m, &cDelay_y9krDOBO_sendMessage);
}

void Heavy_heavy::cBinop_5PcJlx7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_EIpXbmQp_sendMessage);
}

void Heavy_heavy::hTable_XlagPEq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gka4Kirr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qb8h4TUp, 2, m, &cDelay_qb8h4TUp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GSnAGLpr_sendMessage);
}

void Heavy_heavy::cDelay_qb8h4TUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qb8h4TUp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y9krDOBO, 0, m, &cDelay_y9krDOBO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qb8h4TUp, 0, m, &cDelay_qb8h4TUp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AZ5VSN3S, 1, m, NULL);
}

void Heavy_heavy::cBinop_AyQdyJcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GdZ0fN6K_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MW1sCAeW, m);
}

void Heavy_heavy::cBinop_tRWAig4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AyQdyJcL_sendMessage);
}

void Heavy_heavy::cBinop_Rew4Z5xy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tRWAig4q_sendMessage);
}

void Heavy_heavy::cSystem_vr5zUdjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dXTGAiEE_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_3grV8mwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vr5zUdjs_sendMessage);
}

void Heavy_heavy::cBinop_N10sZFdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rew4Z5xy, HV_BINOP_MULTIPLY, 1, m, &cBinop_Rew4Z5xy_sendMessage);
}

void Heavy_heavy::cMsg_dXTGAiEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_N10sZFdu_sendMessage);
}

void Heavy_heavy::cVar_Gt9NBsxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rew4Z5xy, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rew4Z5xy_sendMessage);
}

void Heavy_heavy::cBinop_GdZ0fN6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EKjLraGi, m);
}

void Heavy_heavy::cBinop_cOnEbBEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ea6axT5B_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_DFmvc5vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOnEbBEo, HV_BINOP_MULTIPLY, 1, m, &cBinop_cOnEbBEo_sendMessage);
}

void Heavy_heavy::cMsg_APLCBQf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hx5Iq7SI, HV_BINOP_POW, 0, m, &cBinop_hx5Iq7SI_sendMessage);
}

void Heavy_heavy::cBinop_hx5Iq7SI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_eZMGTido_sendMessage);
}

void Heavy_heavy::cBinop_ugUOl7X8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lb3KEh3Q_sendMessage);
}

void Heavy_heavy::cBinop_lb3KEh3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hx5Iq7SI, HV_BINOP_POW, 1, m, &cBinop_hx5Iq7SI_sendMessage);
  cMsg_APLCBQf6_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_eZMGTido_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Gt9NBsxE, 0, m, &cVar_Gt9NBsxE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_A3KreRrW, 0, m, &cVar_A3KreRrW_sendMessage);
}

void Heavy_heavy::cBinop_RSHaewZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ugUOl7X8_sendMessage);
}

void Heavy_heavy::cIf_KIdg8hxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Q96NxhJQ_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_t7e5QRr0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_9d3khCX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hR8jypoS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KIdg8hxg, 0, m, &cIf_KIdg8hxg_sendMessage);
}

void Heavy_heavy::cUnop_Q96NxhJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOnEbBEo, HV_BINOP_MULTIPLY, 0, m, &cBinop_cOnEbBEo_sendMessage);
}

void Heavy_heavy::cBinop_hR8jypoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KIdg8hxg, 1, m, &cIf_KIdg8hxg_sendMessage);
}

void Heavy_heavy::cUnop_t7e5QRr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cOnEbBEo, HV_BINOP_MULTIPLY, 0, m, &cBinop_cOnEbBEo_sendMessage);
}

void Heavy_heavy::cBinop_d4FMTthC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wb2dlqJK, m);
}

void Heavy_heavy::cMsg_WjXXZa24_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u4lojvei_sendMessage);
}

void Heavy_heavy::cSystem_nlXTBiQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QPCfzypN_sendMessage);
}

void Heavy_heavy::cMsg_Y2S6ChM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nlXTBiQ8_sendMessage);
}

void Heavy_heavy::cSystem_u4lojvei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_d4FMTthC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HB5pNCXh, m);
}

void Heavy_heavy::cVar_nI69gyzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WjXXZa24_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_QPCfzypN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IoozRXwR, m);
}

void Heavy_heavy::cBinop_D0skclgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3zHLhJqY, 0, m, &cIf_3zHLhJqY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_XLFoGQlr, 0, m, &cIf_XLFoGQlr_sendMessage);
}

void Heavy_heavy::cVar_UF7ro4DQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qQX3sGrl, 0, m, &cVar_qQX3sGrl_sendMessage);
}

void Heavy_heavy::cBinop_qOdC8TFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIpCcdmW, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_NIpCcdmW_sendMessage);
}

void Heavy_heavy::cUnop_kEXoTly9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aFvZ3LwN, 0, m, &cVar_aFvZ3LwN_sendMessage);
}

void Heavy_heavy::cIf_SW7f5C6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_kEXoTly9_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9Mi1TTtY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_MbAe97dz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SW7f5C6h, 1, m, &cIf_SW7f5C6h_sendMessage);
}

void Heavy_heavy::cVar_qQX3sGrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MbAe97dz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SW7f5C6h, 0, m, &cIf_SW7f5C6h_sendMessage);
}

void Heavy_heavy::cUnop_9Mi1TTtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aFvZ3LwN, 0, m, &cVar_aFvZ3LwN_sendMessage);
}

void Heavy_heavy::cVar_lc9XiLbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ECQfy7I9, HV_BINOP_ADD, 1, m, &cBinop_ECQfy7I9_sendMessage);
}

void Heavy_heavy::cVar_rfdALNVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NIpCcdmW, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_NIpCcdmW_sendMessage);
}

void Heavy_heavy::cIf_1klPmh6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_NsMVhQbl_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_U92QwTJH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_HMK7wZ0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_DXtwuptf_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1klPmh6s, 0, m, &cIf_1klPmh6s_sendMessage);
}

void Heavy_heavy::cUnop_NsMVhQbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rfdALNVd, 0, m, &cVar_rfdALNVd_sendMessage);
}

void Heavy_heavy::cUnop_U92QwTJH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rfdALNVd, 0, m, &cVar_rfdALNVd_sendMessage);
}

void Heavy_heavy::cBinop_DXtwuptf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1klPmh6s, 1, m, &cIf_1klPmh6s_sendMessage);
}

void Heavy_heavy::cVar_aFvZ3LwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qOdC8TFK, HV_BINOP_MULTIPLY, 1, m, &cBinop_qOdC8TFK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gj3RE66N, HV_BINOP_LESS_THAN, 1, m, &cBinop_gj3RE66N_sendMessage);
}

void Heavy_heavy::cBinop_NIpCcdmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gj3RE66N, HV_BINOP_LESS_THAN, 0, m, &cBinop_gj3RE66N_sendMessage);
}

void Heavy_heavy::cBinop_ECQfy7I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qOdC8TFK, HV_BINOP_MULTIPLY, 0, m, &cBinop_qOdC8TFK_sendMessage);
}

void Heavy_heavy::cCast_Qn7xirKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bxJUoelq, 0, m, &cVar_bxJUoelq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_d2swh0fL, 0, m, &cVar_d2swh0fL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fXt5lRf2, 0, m, &cVar_fXt5lRf2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8990YYy8, 0, m, &cVar_8990YYy8_sendMessage);
}

void Heavy_heavy::cCast_4jftkVTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6q8UtqXA_sendMessage);
}

void Heavy_heavy::cSwitchcase_a4aYcNNs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4jftkVTH_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qn7xirKU_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_hq01W2yl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_srw9af7J, 1, m, &cIf_srw9af7J_sendMessage);
}

void Heavy_heavy::cUnop_zWO9zp8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lc9XiLbE, 0, m, &cVar_lc9XiLbE_sendMessage);
}

void Heavy_heavy::cVar_aJ70izQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hq01W2yl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_srw9af7J, 0, m, &cIf_srw9af7J_sendMessage);
}

void Heavy_heavy::cUnop_RGtJ7TPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lc9XiLbE, 0, m, &cVar_lc9XiLbE_sendMessage);
}

void Heavy_heavy::cIf_srw9af7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_zWO9zp8L_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RGtJ7TPd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_gj3RE66N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a4aYcNNs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_PMTyqGyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PlmH5RuI, 1, m, &cVar_PlmH5RuI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ECQfy7I9, HV_BINOP_ADD, 0, m, &cBinop_ECQfy7I9_sendMessage);
}

void Heavy_heavy::cVar_PlmH5RuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PMTyqGyB_sendMessage);
}

void Heavy_heavy::cVar_m4pt4h1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HMK7wZ0Q, 0, m, &cVar_HMK7wZ0Q_sendMessage);
}

void Heavy_heavy::cCast_6q8UtqXA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_1NU0nRw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aJ70izQM, 0, m, &cVar_aJ70izQM_sendMessage);
}

void Heavy_heavy::cBinop_hnjRX3Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 6.0f, 0, m, &cBinop_UnpwSOVG_sendMessage);
}

void Heavy_heavy::cVar_siGlhqcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m7kGdpKl, 0, m, &cVar_m7kGdpKl_sendMessage);
}

void Heavy_heavy::cCast_lKqnBJPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ltxfcqdv, 0, m, &cVar_ltxfcqdv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hxVIShqe, 0, m, &cVar_hxVIShqe_sendMessage);
}

void Heavy_heavy::cUnop_sHAFXZEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wpSciaiB, 0, m, &cVar_wpSciaiB_sendMessage);
}

void Heavy_heavy::cIf_44aMhzMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_CTw8wBP4_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sHAFXZEv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_CTw8wBP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wpSciaiB, 0, m, &cVar_wpSciaiB_sendMessage);
}

void Heavy_heavy::cBinop_1USx26qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_44aMhzMZ, 1, m, &cIf_44aMhzMZ_sendMessage);
}

void Heavy_heavy::cVar_m7kGdpKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1USx26qF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_44aMhzMZ, 0, m, &cIf_44aMhzMZ_sendMessage);
}

void Heavy_heavy::cCast_LwVrE6Pb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_czetbuZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnuXkxc6, HV_BINOP_MULTIPLY, 1, m, &cBinop_QnuXkxc6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1WjO9OSZ, HV_BINOP_LESS_THAN, 1, m, &cBinop_1WjO9OSZ_sendMessage);
}

void Heavy_heavy::cVar_wpSciaiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5Vzk9tK, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_p5Vzk9tK_sendMessage);
}

void Heavy_heavy::cBinop_p5Vzk9tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1WjO9OSZ, HV_BINOP_LESS_THAN, 0, m, &cBinop_1WjO9OSZ_sendMessage);
}

void Heavy_heavy::cCast_0bQirnWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LwVrE6Pb_sendMessage);
}

void Heavy_heavy::cSwitchcase_73EpMsSi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0bQirnWB_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lKqnBJPN_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cBinop_M9rBLUbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YuQeecnE, 1, m, &cVar_YuQeecnE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BJC3jbY0, HV_BINOP_ADD, 0, m, &cBinop_BJC3jbY0_sendMessage);
}

void Heavy_heavy::cBinop_hMCLerLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hlllHi61, 1, m, &cIf_hlllHi61_sendMessage);
}

void Heavy_heavy::cUnop_KVhazlNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_czetbuZu, 0, m, &cVar_czetbuZu_sendMessage);
}

void Heavy_heavy::cVar_wNKH9wAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hMCLerLw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hlllHi61, 0, m, &cIf_hlllHi61_sendMessage);
}

void Heavy_heavy::cUnop_OCptVOsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_czetbuZu, 0, m, &cVar_czetbuZu_sendMessage);
}

void Heavy_heavy::cIf_hlllHi61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_OCptVOsV_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KVhazlNt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_1WjO9OSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_73EpMsSi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cIf_WZATE7In_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_LaIPRARG_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mbWqgtfS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_QxxRSsFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WZATE7In, 1, m, &cIf_WZATE7In_sendMessage);
}

void Heavy_heavy::cUnop_mbWqgtfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FyE7awrB, 0, m, &cVar_FyE7awrB_sendMessage);
}

void Heavy_heavy::cVar_qJQnxRQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_QxxRSsFg_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WZATE7In, 0, m, &cIf_WZATE7In_sendMessage);
}

void Heavy_heavy::cUnop_LaIPRARG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FyE7awrB, 0, m, &cVar_FyE7awrB_sendMessage);
}

void Heavy_heavy::cBinop_BJC3jbY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QnuXkxc6, HV_BINOP_MULTIPLY, 0, m, &cBinop_QnuXkxc6_sendMessage);
}

void Heavy_heavy::cVar_lGtBKTpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wNKH9wAw, 0, m, &cVar_wNKH9wAw_sendMessage);
}

void Heavy_heavy::cVar_kGAQTZ07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qJQnxRQq, 0, m, &cVar_qJQnxRQq_sendMessage);
}

void Heavy_heavy::cBinop_QnuXkxc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5Vzk9tK, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_p5Vzk9tK_sendMessage);
}

void Heavy_heavy::cVar_YuQeecnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_M9rBLUbZ_sendMessage);
}

void Heavy_heavy::cVar_FyE7awrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BJC3jbY0, HV_BINOP_ADD, 1, m, &cBinop_BJC3jbY0_sendMessage);
}

void Heavy_heavy::cBinop_b6dXp6nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iV7UPGpx, 0, m, &cVar_iV7UPGpx_sendMessage);
  cSend_lZhucViH_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_QElJesAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YCwFaBt7, 0, m, &cVar_YCwFaBt7_sendMessage);
}

void Heavy_heavy::cSend_9AptJOqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_x6DIiJPh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_PHAL4ifQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zbB2SPmD_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_QyztcDi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6dXp6nh, HV_BINOP_SUBTRACT, 1, m, &cBinop_b6dXp6nh_sendMessage);
}

void Heavy_heavy::cSend_cTrIAhBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led4", 0x47FF8A5E, m);
}

void Heavy_heavy::cIf_KXCPQii6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_FaDotKjB_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uR7x4qgV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_Wd5zzxdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ngADVw5H_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KXCPQii6, 0, m, &cIf_KXCPQii6_sendMessage);
}

void Heavy_heavy::cUnop_uR7x4qgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TYuYtDQu, 0, m, &cIf_TYuYtDQu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lqkwlBcp, 0, m, &cIf_lqkwlBcp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_D0skclgx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_GYjrkFUP_sendMessage);
}

void Heavy_heavy::cBinop_ngADVw5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KXCPQii6, 1, m, &cIf_KXCPQii6_sendMessage);
}

void Heavy_heavy::cUnop_FaDotKjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TYuYtDQu, 0, m, &cIf_TYuYtDQu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lqkwlBcp, 0, m, &cIf_lqkwlBcp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_D0skclgx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_GYjrkFUP_sendMessage);
}

void Heavy_heavy::cBinop_GYjrkFUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6zfyrPBY, 0, m, &cIf_6zfyrPBY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vjW77bD3, 0, m, &cIf_vjW77bD3_sendMessage);
}

void Heavy_heavy::cBinop_DLcjK8g3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ouv2eMVc, 0, m, &cVar_Ouv2eMVc_sendMessage);
}

void Heavy_heavy::cBinop_okY4g5uA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KWMgpVDy, 0, m, &cVar_KWMgpVDy_sendMessage);
}

void Heavy_heavy::cUnop_vhD0wKmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3P5DJESP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cUnop_UpNcz4f5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3P5DJESP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cBinop_7jbwafAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SzXmYaU0, 1, m, &cIf_SzXmYaU0_sendMessage);
}

void Heavy_heavy::cVar_Ouv2eMVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7jbwafAZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SzXmYaU0, 0, m, &cIf_SzXmYaU0_sendMessage);
}

void Heavy_heavy::cIf_SzXmYaU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_UpNcz4f5_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vhD0wKmj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cReceive_GJ7u5FID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_A7V2BVoN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_bM8WBF6V_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.25f, 0, m, &cBinop_ICkaydqE_sendMessage);
}

void Heavy_heavy::cBinop_NwQckHgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_CB8mUFRv_sendMessage);
}

void Heavy_heavy::cMsg_y4nY2Tsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 98.0f);
  cSend_NxCJhGRm_sendMessage(_c, 0, m);
  cSend_cTrIAhBV_sendMessage(_c, 0, m);
  cSend_A60ikBQj_sendMessage(_c, 0, m);
  cSend_sW3amLdj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_P8CIzJ1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8990YYy8, 1, m, &cVar_8990YYy8_sendMessage);
}

void Heavy_heavy::cVar_8990YYy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_P8CIzJ1g_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_5tOWnpmj_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_44LbNihN, 1, m, &cIf_44LbNihN_sendMessage);
}

void Heavy_heavy::cVar_IIUtvmui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HYpsbOCM, 0, m, &cVar_HYpsbOCM_sendMessage);
}

void Heavy_heavy::cSlice_ch92QVHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_5B8bWGfJ, 0, m, &cVar_5B8bWGfJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_61a7tmZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pyrX2ViO, HV_BINOP_ADD, 1, m, &cBinop_pyrX2ViO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_LqNRA3aC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_chOrFQju, HV_BINOP_ADD, 1, m, &cBinop_chOrFQju_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_Vhn7Sq4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J27VMlGC, HV_BINOP_ADD, 1, m, &cBinop_J27VMlGC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSlice_tlahTH2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IgDp83sR, HV_BINOP_ADD, 1, m, &cBinop_IgDp83sR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_c3Fq9tyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BnCnq6ud_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BD9bBNSc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hGrYOBkY, 1, m, &cIf_hGrYOBkY_sendMessage);
}

void Heavy_heavy::cBinop_BnCnq6ud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c3Fq9tyi, 1, m, &cVar_c3Fq9tyi_sendMessage);
}

void Heavy_heavy::cVar_uCjNcF0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hxVIShqe, 0, m, &cVar_hxVIShqe_sendMessage);
}

void Heavy_heavy::cBinop_J27VMlGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gOV76KnO, 0, m, &cIf_gOV76KnO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_M064bYid, 0, m, &cIf_M064bYid_sendMessage);
}

void Heavy_heavy::cBinop_uwD0v8EQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cNuXts6y, 1, m, &cIf_cNuXts6y_sendMessage);
}

void Heavy_heavy::cIf_cNuXts6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_gOV76KnO, 0, m, &cIf_gOV76KnO_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_M064bYid, 0, m, &cIf_M064bYid_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_wPHXY64V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_J27VMlGC, HV_BINOP_ADD, 0, m, &cBinop_J27VMlGC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_koNCIyIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_IxulRnN3_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yHX5qsaa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_HBFuPN3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_r063baub_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_koNCIyIj, 0, m, &cIf_koNCIyIj_sendMessage);
}

void Heavy_heavy::cUnop_yHX5qsaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sz7LUj3n, 0, m, &cVar_Sz7LUj3n_sendMessage);
}

void Heavy_heavy::cUnop_IxulRnN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sz7LUj3n, 0, m, &cVar_Sz7LUj3n_sendMessage);
}

void Heavy_heavy::cBinop_r063baub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_koNCIyIj, 1, m, &cIf_koNCIyIj_sendMessage);
}

void Heavy_heavy::cVar_hxVIShqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YNDU0n3p_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_h7uz0Jik_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_gOV76KnO, 1, m, &cIf_gOV76KnO_sendMessage);
}

void Heavy_heavy::cBinop_YNDU0n3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hxVIShqe, 1, m, &cVar_hxVIShqe_sendMessage);
}

void Heavy_heavy::cVar_liJaMpCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c3Fq9tyi, 0, m, &cVar_c3Fq9tyi_sendMessage);
}

void Heavy_heavy::cVar_Sz7LUj3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GNq9Uais, HV_BINOP_ADD, 1, m, &cBinop_GNq9Uais_sendMessage);
}

void Heavy_heavy::cIf_3zHLhJqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_pyrX2ViO, HV_BINOP_ADD, 0, m, &cBinop_pyrX2ViO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_XLFoGQlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_wPHXY64V, 0, m, &cIf_wPHXY64V_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_cNuXts6y, 0, m, &cIf_cNuXts6y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_z4veauuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XLFoGQlr, 1, m, &cIf_XLFoGQlr_sendMessage);
}

void Heavy_heavy::cBinop_pyrX2ViO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wPHXY64V, 0, m, &cIf_wPHXY64V_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_cNuXts6y, 0, m, &cIf_cNuXts6y_sendMessage);
}

void Heavy_heavy::cBinop_IgDp83sR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_44LbNihN, 0, m, &cIf_44LbNihN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PE0arWMU, 0, m, &cIf_PE0arWMU_sendMessage);
}

void Heavy_heavy::cIf_hGrYOBkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_IgDp83sR, HV_BINOP_ADD, 0, m, &cBinop_IgDp83sR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_NlFGGZeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_44LbNihN, 0, m, &cIf_44LbNihN_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_PE0arWMU, 0, m, &cIf_PE0arWMU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_BD9bBNSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NlFGGZeD, 1, m, &cIf_NlFGGZeD_sendMessage);
}

void Heavy_heavy::cIf_44LbNihN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GNq9Uais, HV_BINOP_ADD, 0, m, &cBinop_GNq9Uais_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_GNq9Uais_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3gbtKjst, 0, m, &cVar_3gbtKjst_sendMessage);
}

void Heavy_heavy::cBinop_5tOWnpmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PE0arWMU, 1, m, &cIf_PE0arWMU_sendMessage);
}

void Heavy_heavy::cIf_PE0arWMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_3gbtKjst, 0, m, &cVar_3gbtKjst_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cVar_V3wfSgSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5B8bWGfJ, 0, m, &cVar_5B8bWGfJ_sendMessage);
}

void Heavy_heavy::cBinop_h7uz0Jik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_M064bYid, 1, m, &cIf_M064bYid_sendMessage);
}

void Heavy_heavy::cBinop_chOrFQju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hGrYOBkY, 0, m, &cIf_hGrYOBkY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NlFGGZeD, 0, m, &cIf_NlFGGZeD_sendMessage);
}

void Heavy_heavy::cIf_gOV76KnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_chOrFQju, HV_BINOP_ADD, 0, m, &cBinop_chOrFQju_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cIf_M064bYid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_hGrYOBkY, 0, m, &cIf_hGrYOBkY_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NlFGGZeD, 0, m, &cIf_NlFGGZeD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_AJpAJ8UV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HYpsbOCM, 1, m, &cVar_HYpsbOCM_sendMessage);
}

void Heavy_heavy::cVar_HYpsbOCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AJpAJ8UV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_uwD0v8EQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wPHXY64V, 1, m, &cIf_wPHXY64V_sendMessage);
}

void Heavy_heavy::cVar_5B8bWGfJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HBFuPN3z, 0, m, &cVar_HBFuPN3z_sendMessage);
}

void Heavy_heavy::cVar_EUHklioh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rDA47Ugj, 0, m, &cVar_rDA47Ugj_sendMessage);
}

void Heavy_heavy::cVar_rDA47Ugj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MjRTDPgx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_z4veauuG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_3zHLhJqY, 1, m, &cIf_3zHLhJqY_sendMessage);
}

void Heavy_heavy::cBinop_MjRTDPgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rDA47Ugj, 1, m, &cVar_rDA47Ugj_sendMessage);
}

void Heavy_heavy::cVar_AMFXrXHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8990YYy8, 0, m, &cVar_8990YYy8_sendMessage);
}

void Heavy_heavy::cBinop_l1Ftlmxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yjlFqvPL, 0, m, &cVar_yjlFqvPL_sendMessage);
}

void Heavy_heavy::cBinop_PlHcYQez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J06HybW9, 0, m, &cVar_J06HybW9_sendMessage);
}

void Heavy_heavy::cVar_YCwFaBt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWMWB4Pf, HV_BINOP_MULTIPLY, 1, m, &cBinop_SWMWB4Pf_sendMessage);
}

void Heavy_heavy::cReceive_dzNhQpi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4000.0f, 0, m, &cBinop_0osWl12l_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_73fLIvo9_sendMessage);
}

void Heavy_heavy::cCast_WFpRrfYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iUr2qcHy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_x6DIiJPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 25.0f, 0, m, &cBinop_NwQckHgf_sendMessage);
}

void Heavy_heavy::cBinop_CB8mUFRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Wd5zzxdB, 1, m, &cVar_Wd5zzxdB_sendMessage);
}

void Heavy_heavy::cSend_luPjDlmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSend_VQHv5kv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_4lsxxNjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4300.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6dXp6nh, HV_BINOP_SUBTRACT, 0, m, &cBinop_b6dXp6nh_sendMessage);
}

void Heavy_heavy::cBinop_Kb3rm5V3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_r3tL2oJF_sendMessage);
}

void Heavy_heavy::cUnop_eZY21ymA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LkmOzVij_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cVar_PIhdGW7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8V47HdFt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fs72xCQX, 0, m, &cIf_fs72xCQX_sendMessage);
}

void Heavy_heavy::cIf_fs72xCQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_P8Mt5lwp_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eZY21ymA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_8V47HdFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fs72xCQX, 1, m, &cIf_fs72xCQX_sendMessage);
}

void Heavy_heavy::cUnop_P8Mt5lwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LkmOzVij_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_heavy::cSend_bQAkp6wt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cReceive_SL4vOQhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_luPjDlmk_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_UnpwSOVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5B8bWGfJ, 0, m, &cVar_5B8bWGfJ_sendMessage);
}

void Heavy_heavy::cBinop_vY7ltqjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.01f, 0, m, &cBinop_q1QBTBDE_sendMessage);
}

void Heavy_heavy::cReceive_YfvXSle8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bQAkp6wt_sendMessage(_c, 0, m);
}

void Heavy_heavy::cCast_ZUKoPEBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cYgupouL, 0, m, &cVar_cYgupouL_sendMessage);
}

void Heavy_heavy::cBinop_dX68iHYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jxdarfE9, 1, m, &cIf_jxdarfE9_sendMessage);
}

void Heavy_heavy::cSlice_3oqBXir1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dX68iHYx, HV_BINOP_NEQ, 1, m, &cBinop_dX68iHYx_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_cYgupouL, 1, m, &cVar_cYgupouL_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_dX68iHYx, HV_BINOP_NEQ, 1, m, &cBinop_dX68iHYx_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_cYgupouL, 1, m, &cVar_cYgupouL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_KoyCQRGX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a5uCBxFM, 0, m, &cSlice_a5uCBxFM_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3oqBXir1, 0, m, &cSlice_3oqBXir1_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y35EGysq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SGNfcqQZ_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_a5uCBxFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_cYgupouL, 0, m, &cVar_cYgupouL_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_cYgupouL, 0, m, &cVar_cYgupouL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_SGNfcqQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jxdarfE9, 0, m, &cIf_jxdarfE9_sendMessage);
}

void Heavy_heavy::cCast_7Pw34zkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dX68iHYx, HV_BINOP_NEQ, 1, m, &cBinop_dX68iHYx_sendMessage);
}

void Heavy_heavy::cIf_jxdarfE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7Pw34zkh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZUKoPEBk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_Y35EGysq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dX68iHYx, HV_BINOP_NEQ, 0, m, &cBinop_dX68iHYx_sendMessage);
}

void Heavy_heavy::cVar_cYgupouL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_PHAL4ifQ_sendMessage);
}

void Heavy_heavy::cCast_WHxjS8tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3gdG0kcw, 0, m, &cVar_3gdG0kcw_sendMessage);
}

void Heavy_heavy::cVar_3gdG0kcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_hTGxLfQk_sendMessage);
}

void Heavy_heavy::cCast_tEE9n4MV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pg5t5FAY, HV_BINOP_NEQ, 0, m, &cBinop_Pg5t5FAY_sendMessage);
}

void Heavy_heavy::cCast_MpTZJf4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pg5t5FAY, HV_BINOP_NEQ, 1, m, &cBinop_Pg5t5FAY_sendMessage);
}

void Heavy_heavy::cSlice_14bRYa1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Pg5t5FAY, HV_BINOP_NEQ, 1, m, &cBinop_Pg5t5FAY_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_3gdG0kcw, 1, m, &cVar_3gdG0kcw_sendMessage);
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Pg5t5FAY, HV_BINOP_NEQ, 1, m, &cBinop_Pg5t5FAY_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_3gdG0kcw, 1, m, &cVar_3gdG0kcw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_LkmOzVij_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0xFFFFFFFF: { // "bang"
      cSlice_onMessage(_c, &Context(_c)->cSlice_r4QvNXW3, 0, m, &cSlice_r4QvNXW3_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_14bRYa1n, 0, m, &cSlice_14bRYa1n_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tEE9n4MV_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qDxgSUeC_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cSlice_r4QvNXW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_3gdG0kcw, 0, m, &cVar_3gdG0kcw_sendMessage);
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_3gdG0kcw, 0, m, &cVar_3gdG0kcw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_Pg5t5FAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d32pJKTv, 1, m, &cIf_d32pJKTv_sendMessage);
}

void Heavy_heavy::cCast_qDxgSUeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d32pJKTv, 0, m, &cIf_d32pJKTv_sendMessage);
}

void Heavy_heavy::cIf_d32pJKTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MpTZJf4L_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WHxjS8tg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cCast_XWHhuiGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YCwFaBt7, 1, m, &cVar_YCwFaBt7_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_Kzrpzbbk, VOf(Bf0));
    __hv_sample_f(this, &sSample_NAed3PxY, VIf(Bf0), &sSample_NAed3PxY_sendMessage);
    __hv_phasor_k_f(&sPhasor_cGEDBl02, VOf(Bf0));
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
    __hv_sample_f(this, &sSample_6FZ2hYwe, VIf(Bf1), &sSample_6FZ2hYwe_sendMessage);
    __hv_varread_i(&sVari_8GlmbdPP, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_8GlmbdPP, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_sU4Dnnqf, VOf(Bf1));
    __hv_phasor_f(&sPhasor_zozHet4J, VIf(Bf1), VOf(Bf1));
    __hv_del1_f(&sDel1_Xqi3jv8l, VIf(Bf1), VOf(Bf0));
    __hv_lt_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_samphold_f(&sSamphold_iyuYtwL5, VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_owN6Jq8y, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_29jZT7BF, VOf(Bf0));
    __hv_rpole_f(&sRPole_XBliX0PA, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sample_f(this, &sSample_qAQHyiub, VIf(Bf0), &sSample_qAQHyiub_sendMessage);
    __hv_varread_f(&sVarf_j5OsoXrr, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_C1f5KhGZ, VOf(Bf1));
    __hv_rpole_f(&sRPole_PKinAu5z, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_YONAm2oA, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_iOIr9slV, VOf(Bf0));
    __hv_phasor_f(&sPhasor_Lql8U7Wo, VIf(Bf0), VOf(Bf0));
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
    __hv_line_f(&sLine_nfBQiNlR, VOf(Bf4));
    __hv_phasor_f(&sPhasor_22snlaDI, VIf(Bf4), VOf(Bf4));
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
    __hv_line_f(&sLine_2z7YmJXc, VOf(Bf3));
    __hv_phasor_f(&sPhasor_PdhsKaRL, VIf(Bf3), VOf(Bf3));
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
    __hv_line_f(&sLine_QmznSVBQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_T1axzyhg, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_DfPqYhu5, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf3), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_gG29Dd3U, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_35UJXhL5, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_varread_f(&sVarf_oI7okc9R, VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_OaLoBA1A, VIi(Bi0), VOf(Bf4));
    __hv_tabread_if(&sTabread_9vrz1gk1, VIi(Bi1), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_MW1sCAeW, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_EKjLraGi, VOf(Bf2));
    __hv_rpole_f(&sRPole_Ws4Fhg1l, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NK18WIAf, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_tabwrite_f(&sTabwrite_COmKKq3e, VIf(Bf3));
    __hv_tabhead_f(&sTabhead_tcvu1KzT, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_IoozRXwR, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_wb2dlqJK, VOf(Bf0));
    __hv_min_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_HB5pNCXh, VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_9dRFK4Et, VIi(Bi0), VOf(Bf5));
    __hv_tabread_if(&sTabread_0fXI8pMs, VIi(Bi1), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zHKJ79b9, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_T1iByYAv, VOf(Bf0));
    __hv_rpole_f(&sRPole_wQEpmSvd, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_3BKjnCnH, VOf(Bf4));
    __hv_varread_f(&sVarf_nn3e1DEX, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_qQoRCBU9, VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_AZ5VSN3S, VIf(Bf4));
    __hv_varread_f(&sVarf_xSajiZR9, VOf(Bf4));
    __hv_varread_f(&sVarf_ILEJFr81, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f, -0.99f);
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));

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
