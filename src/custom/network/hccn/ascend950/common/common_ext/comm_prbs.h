/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef COMM_PRBS_H
#define COMM_PRBS_H

#include "comm_channel.h"
#define XSFP_MAX_LANE_NUM      8

typedef enum {
    XSFP_OPTICAL_PRBS_TX_RX_DISABLE_STATE = 0,
    XSFP_OPTICAL_PRBS_TX_ENABLE_STATE,
    XSFP_OPTICAL_PRBS_RX_ENABLE_STATE,
    XSFP_OPTICAL_PRBS_TX_RX_ENABLE_STATE
} XSFP_TX_RX_ENABLE_TYPE;                   // tx rx使能状态，从1开始

typedef enum {
    XSFP_PRBS_GET_STATE = 0,
    XSFP_PRBS_CONFIG,
    XSFP_PRBS_CLEAR_STATISTICS,
    XSFP_PRBS_GET_RESULT,
    XSFP_PRBS_CLOSE,
    XSFP_PRBS_OP_TYPE_MAX
} XSFP_OPTICAL_MODULE_PRBS_OP_TYPE;

// 查询状态/获取打流结果/清理/关闭打流动作 入参
struct xsfp_prbs_op_in {
    unsigned char optical_index;
    unsigned char operation_type;
    unsigned char optical_module_num;
    unsigned char optical_module_id[XSFP_MAX_OPTICAL_MODULE_NUM];
};

struct optical_module_config {
    unsigned char config_item;
    unsigned int test_time;
    unsigned char prbs_type;
    unsigned char optical_module_num;
    unsigned char optical_module_id[XSFP_MAX_OPTICAL_MODULE_NUM];
};

// 配置打流入参
struct xsfp_prbs_config_in {
    unsigned char operation_type;
    unsigned char optical_index;
    struct optical_module_config config;
};

#pragma pack(push, 1)

//  配置/清理/关闭 打流动作结构
struct optical_module_op_result {
    unsigned char optical_module_num;
    union {
        unsigned char optical_module_id[XSFP_MAX_OPTICAL_MODULE_NUM]; // 为了适配与A3带外公用代码保留
        unsigned char exe_result[XSFP_MAX_OPTICAL_MODULE_NUM];
    };
};

// 打流状态
struct prbs_state_result {
    unsigned char optical_module_num;
    unsigned char supported_test_type[XSFP_MAX_OPTICAL_MODULE_NUM];
    unsigned char test_state[XSFP_MAX_OPTICAL_MODULE_NUM];
};

// 打流结果
struct optical_module_prbs_result {
    unsigned char optical_module_num;
    unsigned char optical_module_id[XSFP_MAX_OPTICAL_MODULE_NUM];
    unsigned short error_bit_rate[XSFP_MAX_LANE_NUM];
    unsigned char rx_lost_of_lock;      // rx失锁统计
    unsigned char tx_lost_of_lock;      // tx失锁统计
};

struct prbs_result_out_band {
    unsigned char optical_module_num;
    unsigned char optical_module_id[XSFP_MAX_OPTICAL_MODULE_NUM];
    float error_bit_rate[XSFP_MAX_LANE_NUM];
    unsigned char rx_lost_of_lock;      // rx失锁统计
    unsigned char tx_lost_of_lock;      // tx失锁统计
};
#pragma pack(pop)

struct thread_para_stu {
    unsigned int flag;
    unsigned int time;
    unsigned int count;
    int dev_id;
    unsigned char module_num;
    unsigned char module_id[XSFP_MAX_OPTICAL_MODULE_NUM];
    unsigned char op_type;
};

#endif  // COMM_PRBS_H