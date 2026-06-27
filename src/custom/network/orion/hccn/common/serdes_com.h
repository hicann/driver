/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef SERDES_COM_H
#define SERDES_COM_H

#define PORT_LANE_CNT                   4

#define SERDES_RX_CTLE_FFE_BUFFER_SIZE  (26 * 1024)

struct snr_info_t {
    unsigned int udie_id;
    unsigned int port_id;
    unsigned int lane;
    unsigned int snr;
};

struct tx_fir_t {
    short fir_pre2;
    short fir_pre1;
    unsigned short fir_main;
    short fir_post1;
    short fir_post2;
    unsigned short rsv;             // 保留字节用于对齐
};
struct tx_fir_info_t {
    unsigned int udie_id;
    unsigned int port_id;
    unsigned int lane;
    struct tx_fir_t tx_fir;
};

// 这里暂时用 char*, 待海思交付接口后适配修改
struct rx_ctle_ffe_t {
    char *data;
    unsigned int len;
};
struct rx_ctle_ffe_info_t {
    unsigned int udie_id;
    unsigned int port_id;
    unsigned int lane;
    struct rx_ctle_ffe_t buffer;
};

struct serdes_info_t {
    union {
        struct snr_info_t snr_info[PORT_LANE_CNT];
        struct tx_fir_info_t tx_fir_info[PORT_LANE_CNT];
    } info;
    unsigned int lane_start;
    unsigned int lane_cnt;
};

enum serdes_info_type_e {
    SERDES_SNR_INFO = 0,
    SERDES_TX_FIR_INFO,
    SERDES_RX_CTLE_INFO,
    SERDES_RX_DFE_INFO,
};

#endif  // SERDES_COM_H