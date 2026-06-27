/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_OPTICAL_H
#define TOOL_OPTICAL_H

#include "comm_channel.h"
#include "tool_comm.h"

typedef enum {
    TX_FAULT_CMD = 0,
    TX_LOS_CMD,
    RX_LOS_CMD,
    TX_LOL_CMD,
    RX_LOL_CMD
} optical_status_type;

#define TEMP_BYTE_OFFSET    256
#define OPTICAL_SNR_OFFSET  256
#define XSFP_OUI_PRINT_LEN  10
#define THREE_NUM           3
#define FIVE_NUM            5
#define TOOL_FLAG_MAP_NUM   5
#define MACRO_LANE_NUM_UBOE 2
#define MACRO_LANE_NUM      4
#define OSFP_LANE_NUM       8
#define QSFP_LANE_NUM       4
#define CHIP_ID_0 0
#define CHIP_ID_1 1
#define CHIP_ID_2 2
#define CHIP_ID_3 3
#define DEV_NUM_PER_LEVEL               4 // 每一层抽屉4个NPU
#define PER_DEV_USE_OPTICAL_2_4         6 // A+K 2+4 机型每个NPU出6个port用于Y轴光模块
#define PER_DEV_CTL_OSFP_NUM_0_8        4 // A+K 0+8 机型每个NPU控制4个Y轴光模块
#define OPTICAL_ID_MAX                  4 // 光模块ID最大值 (0-3 for outlet, 4 for UBOE)
#define UDIE_PORT_NUM                   9
#define LANE_PER_NPU_PORT               4 // 每个NPU PORT 4条LANE
#define LANE_PER_NPU_PORT_UBOE          2 // 每个UBOE PORT 2条LANE
#define PER_NPU_PORT_UBOE               2 // UBOE PORT口分成2个PORT口
#define MW_TO_DBM_TEN              10
#define MW_TO_DBM(value)           (((value) < 0.0001) ? 0 : (10 * log10f(value)))
#define XSFP_MODULE_READY                 0x3
#define ASCII_MIN_NUM   32
#define ASCII_MAX_NUM   127

struct optical_status {
        int txfault;
        int txlos;
        int rxlos;
        int txlol;
        int rxlol;
};

struct optical_info {
    int optical_phy_id;
    int optical_logic_id;
    int optical_master_dev_id;
    int optical_lane_id;
};

struct optical_lane_map {
    int chip_id;
    int macro_id;
    int macro_lane_id;
};

struct macro_lane_map {
    int optical_phy_id;
    int optical_logic_id;
    int optical_master_chip_id;
    int optical_lane_id;
};

struct optical_id_macro_laneid_map {
    struct macro_lane_map macro_lane[LANE_PER_NPU_PORT];
};

struct port_id_optical_lane_id_map {
    struct optical_lane_map optical_lane[OSFP_LANE_NUM];
};

struct optical_id_macro_laneid_map_uboe {
    struct macro_lane_map macro_lane[LANE_PER_NPU_PORT_UBOE];
};

struct port_id_optical_lane_id_map_uboe {
    struct optical_lane_map optical_lane[QSFP_LANE_NUM];
};

#define WAVE_LEN_MULTI          256
#define WAVE_LEN_UNIT           20
#define XSFP_IDENTIFIER_LEN     20

struct xsfp_id_map {
    int id;
    char id_str[XSFP_IDENTIFIER_LEN];
};

struct optical_id_silk_screen_num_map {
    unsigned char screen_num[16];
    unsigned int optical_id;
    unsigned char speed[5];
    unsigned char used_mode[5];
};

#define TOOL_BIT0   0x1
#define TOOL_BIT1   0x2
#define TOOL_BIT2   0x4
#define TOOL_BIT3   0x8
#define TOOL_BIT4   0x10
#define TOOL_BIT5   0x20
#define TOOL_BIT6   0x40
#define TOOL_BIT7   0x80

#define OPTICAL_VCC_DEVISOR         10000
#define OPTICAL_BIAS_DEVISOR        500
#define OPTICAL_POWER_DEVISOR       10000
#define TOOL_USER_BY_STR_LEN        50

#define TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(value, high_threshold, low_threshold) \
    (((value) <= (high_threshold)) && ((value) >= (low_threshold)))

struct optical_id_lane_id_map {
    int optical_id;
    int optical_lane_id;
};

struct portid_optical_lane_id_map {
    int dev_id;  // 0~3
    int udie_id; // 0~1
    int port_id; // 47, 56
    struct optical_id_lane_id_map optical_lane_id[LANE_PER_NPU_PORT];
};

struct optical_id_map {
    int optical_phy_id; // 光模块物理id 0~11
    int phy_dev_id;
    int optical_logic_id; // 光模块逻辑id 0~3
};

#define TOOL_START_ROW_NUM0         0
#define TOOL_START_ROW_NUM1         1

typedef struct {
    void *data_ptr;
    size_t data_size;
    uint32_t cmd_id;
} optical_data_request;

/* tx signal 状态定义 */

#define TX_SIGNAL_ENABLE         0x00
#define TX_SIGNAL_DD_DISABLE     0x0F
#define TX_SIGNAL_DISABLE        0xFF

struct optical_param_t {
    struct optical_test_t info;
    int cfg_status_flag;
    char firmware_path[PATH_MAX];  // 使用Linux最大路径长度
};

int tool_optical_exec(struct command_context *ctx);
void tool_optical_help(struct command_context *ctx, unsigned int mode);
int optical_assign(void *args, struct sub_option_entry *opt, value_union *type_val);
void *alloc_optical_args_init(void);
void get_optical_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count);
int tool_optical_show_page_info(struct optical_test_t *info, unsigned char *reg_buf);
int optical_confirm_required(const struct optical_test_t *info);
int parse_dump_page(struct optical_test_t *info, const char *page_str);
int tool_test_optical_exec(struct command_context *ctx);
int optical_assign_test(struct optical_test_t *info, struct sub_option_entry *opt, value_union *type_val);

#endif