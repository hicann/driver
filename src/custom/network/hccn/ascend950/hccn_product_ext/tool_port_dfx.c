/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "ds_data.h"
#include "tool_cmd_parse.h"
#include "tool_comm.h"
#include "ascend_hal.h"
#include "securec.h"
#include "tool_errcode.h"
#include "ds_net_interface.h"
#include "comm_product.h"
#include "tool_cmd_err.h"
#include "dsmi_common_interface.h"
#include "tool_lib.h"
#include "tool_table.h"

#include "tool_port_dfx.h"

// ======================  UB场景:  =======================
// level 0: ub和uboe的是相同的
#define UB_L0_MAC_LINK_STATUS_START         0
#define UB_L0_MAC_LINK_STATUS_SWITCH_SPEED  1
#define UB_L0_MAC_LINK_STATUS_LINK_PROC     2   // level 1 - 0
#define UB_L0_MAC_LINK_STATUS_LINK_UPDATE   3   // level 1 - 1

/* level 1 - 0: 采用顺时针命名 */

#define UB_L1_GEN_LINK_STATUS_START             0       // level 2 - 0
#define UB_L1_GEN_LINK_STATUS_WAIT_DETECT       1       // level 2 - 1
#define UB_L1_GEN_LINK_STATUS_WAIT_MAC_LINKUP   2
#define UB_L1_GEN_LINK_STATUS_CHECK_PCS_ERR     3
#define UB_L1_GEN_LINK_STATUS_PRE_DL_LINK       4
#define UB_L1_GEN_LINK_STATUS_WAIT_DL_LINKUP    5
#define UB_L1_GEN_LINK_STATUS_EXCHANGE          6       // level 2 - 2
#define UB_L1_GEN_LINK_STATUS_LINK_FAIL         7
#define UB_L1_GEN_LINK_STATUS_OFF               0xF

/* level 1 - 1: 采用顺时针命名 */

#define UB_L1_MONITOR_START                 0
#define UB_L1_MONITOR_LINK_DOWN_FILTER      1

/* level 2 - 0: 采用顺时针命名 */

#define UB_L2_0_SWITCH_SPEED_PROCESS  0
#define UB_L2_1_SDS_CALIB_PROCESS     1
#define UB_L2_GEN_LINK_LEVEL3_0     UB_L2_0_SWITCH_SPEED_PROCESS  // level 3 - 0
#define UB_L2_GEN_LINK_LEVEL3_1     UB_L2_1_SDS_CALIB_PROCESS     // level 3 - 1

/* level 2 - 1: 采用顺时针命名 */

#define UB_L2_1_LINKDOWN_PROCESS   0
#define UB_L2_1_SDS_ADAPT_PROCESS  1

/* level 2 - 2: 采用顺时针命名 */

#define UB_L2_WAIT_GUID         0
#define UB_L2_LINK_PARAM_EXCHG  1
#define UB_L2_PARAM_GET         2
#define UB_L2_ERROR             0xE
#define UB_L2_OFF               0xF

/* level 3 - 0: 采用顺时针命名 */

#define UB_L3_SWITCH_SPEED_CHECK_CONFIG     0
#define UB_L3_SWITCH_SPEED_FIRST_INIT       1
#define UB_L3_SWITCH_SPEED_NOT_FIRST_INIT   2
#define UB_L3_SWITCH_SPEED_WAIT_PORT_EN     3
#define UB_L3_SWITCH_SPEED_OFF              0xF

/* level 3 - 1: 采用顺时针命名 */

#define UB_L3_SDS_CALIB_PARAS_REINIT_AND_STOP_FW_TASK 0
#define UB_L3_SDS_CALIB_WAIT_STOP_FW_TASK_DONE        1
#define UB_L3_SDS_CALIB_DS_DIG_RESET                  2
#define UB_L3_SDS_CALIB_CS_POWER_UP                   3
#define UB_L3_SDS_CALIB_WAIT_CS_POWER_UP_DONE         4
#define UB_L3_SDS_CALIB_DS_POWER_UP                   5
#define UB_L3_SDS_CALIB_WAIT_DS_POWER_UP_DONE         6
#define UB_L3_SDS_CALIB_CS_CALIB_CONFIG               7
#define UB_L3_SDS_CALIB_WAIT_CS_CALIB_DONE            8
#define UB_L3_SDS_CALIB_DS_CALIB_CONFIG               9
#define UB_L3_SDS_CALIB_WAIT_DS_CALIB_DONE            10
#define UB_L3_SDS_CALIB_ERROR                         0xE
#define UB_L3_SDS_CALIB_END                           0xF

/* level 3 - 2: 采用顺时针命名 */

#define UB_L3_LINKDOWN_WAIT_UB_START_LINKDOWN   0x0
#define UB_L3_LINKDOWN_WAIT_SSU_PORT_CELL_CLEAR 0x1
#define UB_L3_LINKDOWN_WAIT_SSU_OQ_QUEUE_CLEAR  0x2
#define UB_L3_LINKDOWN_WAIT_LINKDOWN_SUCCESS    0x3
#define UB_L3_LINKDOWN_OFF                      0xF // 暂时定义为15，后续可能会改动

/* level 3 - 3: 采用顺时针命名 */

#define UB_L3_SDS_ADAPT_START                       0
#define UB_L3_SDS_ADAPT_CHECK_ALOS                  1
#define UB_L3_SDS_ADAPT_MACRO_DS_STOP_FW_TASK       2
#define UB_L3_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL  3
#define UB_L3_SDS_ADAPT_INITIAL_ADAPT               4
#define UB_L3_SDS_ADAPT_WAIT_DONE                   5
#define UB_L3_SDS_ADAPT_CONTINUOUS_ADAPT            6
#define UB_L3_SDS_ADAPT_CHECK_CLOS                  7
#define UB_L3_SDS_ADAPT_CHECK_SNR                   8
#define UB_L3_SDS_ADAPT_LPO_OPTIMIZE                9
#define UB_L3_SDS_ADAPT_ERROR                       0xE
#define UB_L3_SDS_ADAPT_END                         0xF

// ======================  UBOE场景:  =========================
// level 0: ub和uboe的是相同的
#define UBOE_L0_MAC_LINK_STATUS_START           0
#define UBOE_L0_MAC_LINK_STATUS_SWITCH_SPEED    1
#define UBOE_L0_MAC_LINK_STATUS_LINK_PROC       2   // level 1
#define UBOE_L0_MAC_LINK_STATUS_LINK_UPDATE     3

/* level 1: */

#define UBOE_L1_GEN_LINK_STATUS_START_ETH           0
#define UBOE_L1_GEN_LINK_STATUS_SERDES_ADAPT        1   // level 2
#define UBOE_L1_GEN_LINK_STATUS_HIMAC_LINK          2
#define UBOE_L1_GEN_LINK_STATUS_CHECK_PCS_ERR_ETH   3
#define UBOE_L1_GEN_LINK_STATUS_LINK_FAIL_ETH       4
#define UBOE_L1_GEN_LINK_STATUS_OFF_ETH             0xF

/* level 2: */

#define UBOE_L2_SDS_ADAPT_START                         0
#define UBOE_L2_SDS_ADAPT_CHECK_ALOS                    1
#define UBOE_L2_SDS_ADAPT_MACRO_DS_STOP_FW_TASK         2
#define UBOE_L2_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL    3
#define UBOE_L2_SDS_ADAPT_INITIAL_ADAPT                 4
#define UBOE_L2_SDS_ADAPT_WAIT_DONE                     5
#define UBOE_L2_SDS_ADAPT_CONTINUOUS_ADAPT              6
#define UBOE_L2_SDS_ADAPT_CHECK_CLOS                    7
#define UBOE_L2_SDS_ADAPT_CHECK_SNR                     8
#define UBOE_L2_SDS_ADAPT_LPO_OPTIMIZE                  9
#define UBOE_L2_SDS_ADAPT_ERROR                         0xE
#define UBOE_L2_SDS_ADAPT_END                           0xF

// ======================  升lane场景:  ========================
// level 0:
#define LANE_RL0_GEN_LINK_EXPAND_START                 0
#define LANE_RL0_GEN_LINK_EXPAND_DS_STOP_FW_TASK       1
#define LANE_RL0_GEN_LINK_EXPAND_DS_DIG_RESET          2
#define LANE_RL0_GEN_LINK_EXPAND_DS_CALIB_CONFIG       3
#define LANE_RL0_GEN_LINK_EXPAND_WAIT_DS_CALIB_DONE    4
#define LANE_RL0_GEN_LINK_EXPAND_WAIT_DP_READY         5
#define LANE_RL0_GEN_LINK_EXPAND_SDS_ADAPT             6    // level 1
#define LANE_RL0_GEN_LINK_EXPAND_RETRAIN               7

/* level 1: */

#define LANE_RL1_SDS_ADAPT_START                       0
#define LANE_RL1_SDS_ADAPT_CHECK_ALOS                  1
#define LANE_EL1_SDS_ADAPT_MACRO_DS_STOP_FW_TASK       2
#define LANE_RL1_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL  3
#define LANE_RL1_SDS_ADAPT_INITIAL_ADAPT               4
#define LANE_RL1_SDS_ADAPT_WAIT_DONE                   5
#define LANE_RL1_SDS_ADAPT_CONTINUOUS_ADAPT            6
#define LANE_RL1_SDS_ADAPT_CHECK_CLOS                  7
#define LANE_RL1_SDS_ADAPT_CHECK_SNR                   8
#define LANE_RL1_SDS_ADAPT_LPO_OPTIMIZE                9
#define LANE_RL1_SDS_ADAPT_ERROR                       0xE
#define LANE_RL1_SDS_ADAPT_END                         0xF

#define DISPLAY_ITERM_MAX               5
#define PORT_MODE_INFO_MACHINE_MAX      16
#define INFO_MACHINE_EMPTY_ITERM        1
#define UB_PORT_LINK_INFO_MACHINE_SIZE  PORT_MODE_INFO_MACHINE_MAX
#define UB_PORT_LINK_INFO_FLOW_SIZE     2

/**********************  link port 状态机 数据结构 **********************/
enum port_link_mode {
    LINK_UBOE_MODE,
    LINK_UB_MODE,
    LINK_LANE_MODE,
};

struct port_link_info_machine {
    struct timeval link_time;
    unsigned long long level0 : 8;
    unsigned long long level1 : 8;
    unsigned long long level2 : 8;
    unsigned long long level3 : 8;
    unsigned long long rvsd   : 32;
};

struct link_info_machine_data {
    unsigned int machine_num; // 状态个数
    struct port_link_info_machine history_machine[PORT_MODE_INFO_MACHINE_MAX];
};

struct port_link_info_machine_queue {
    struct link_info_machine_data machine_data;
    struct port_link_info_machine machine_tmp;
    unsigned int head;
    unsigned int tail;
    unsigned int count;
};

struct uboe_link_speed {
    unsigned short tx_mac_speed;
    unsigned short rx_mac_speed;
};

union link_speed {
    unsigned int ub_speed;
    struct uboe_link_speed uboe_speed;
};

struct port_link_info_state_machine {
    unsigned int port_id;
    unsigned int mac_link;
    unsigned int pcs_link;
    union link_speed speed;
    unsigned int link_mode;
    struct timeval answer_time;
    struct link_info_machine_data link_up_info;
    struct link_info_machine_data lane_raise_info;
};

/**************************** MAC DFX ****************************/

#define MAKE_STRING(level, name) (level #name)

#define MAX_TIME_STR_LEN        40
#define MAX_STATUS_STR_LEN      120

#define LANE_LEVEL_1_H_STRING             "L0:sds_adapt"
#define UBOE_LEVEL_1_H_STRING             "L0:link_proc"

#define UBOE_LEVEL_2_H_STRING             UBOE_LEVEL_1_H_STRING "|L1:serdes_adapt"

#define UB_LEVEL_1_0_H_STRING             "L0:link_proc"
#define UB_LEVEL_1_1_H_STRING             "L0:link_update"

#define UB_LEVEL_2_0_H_STRING             UB_LEVEL_1_0_H_STRING "|L1:start"
#define UB_LEVEL_2_1_H_STRING             UB_LEVEL_1_0_H_STRING "|L1:wait_detect"
#define UB_LEVEL_2_2_H_STRING             UB_LEVEL_1_0_H_STRING "|L1:exchange"

#define UB_LEVEL_3_0_H_STRING             UB_LEVEL_2_0_H_STRING "|L2:switch_speed"
#define UB_LEVEL_3_1_H_STRING             UB_LEVEL_2_0_H_STRING "|L2:sds_calib"
#define UB_LEVEL_3_2_H_STRING             UB_LEVEL_2_1_H_STRING "|L2:linkdown"
#define UB_LEVEL_3_3_H_STRING             UB_LEVEL_2_1_H_STRING "|L2:sds_adapt"

#define TABLE_HEADER_STRING_UB_STATUS     "Adapt status: UB"
#define TABLE_HEADER_STRING_UBOE_STATUS   "Adapt status: UBOE"
#define TABLE_HEADER_STRING_LANE_STATUS   "Adapt status: LANE raise"
#define TABLE_IS_EMPTY_STRING             "N/A"
#define CHILD_STATUS_SUSPEND_VALUE        0xFF
#define TIME_START_YEAR                   1900

#define LINK_LEVEL_STAGE_0      0
#define LINK_LEVEL_STAGE_1      1
#define LINK_LEVEL_STAGE_2      2
#define LINK_LEVEL_STAGE_3      3

struct link_status_string_iterm {
    int status;
    const char *const string;
    const struct link_status_string_iterm *const child;
};

#define LINK_INVALID_INDEX          (-1)
#define LINK_STATUS_TABLE_END       {LINK_INVALID_INDEX, NULL, NULL}  // 哨兵节点

// ub Level 3.0
static const struct link_status_string_iterm ub_level_3_0_table[] = {
    { UB_L3_SWITCH_SPEED_CHECK_CONFIG,      (UB_LEVEL_3_0_H_STRING "|L3:check_config"),     NULL },
    { UB_L3_SWITCH_SPEED_FIRST_INIT,        (UB_LEVEL_3_0_H_STRING "|L3:first_init"),       NULL },
    { UB_L3_SWITCH_SPEED_NOT_FIRST_INIT,    (UB_LEVEL_3_0_H_STRING "|L3:not_first_init"),   NULL },
    { UB_L3_SWITCH_SPEED_WAIT_PORT_EN,      (UB_LEVEL_3_0_H_STRING "|L3:wait_port_en"),     NULL },
    { UB_L3_SWITCH_SPEED_OFF,               (UB_LEVEL_3_0_H_STRING "|L3:switch_speed_off"), NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 3.1
static const struct link_status_string_iterm ub_level_3_1_table[] = {
    {UB_L3_SDS_CALIB_PARAS_REINIT_AND_STOP_FW_TASK, (UB_LEVEL_3_1_H_STRING "|L3:paras_reinit_and_stop_fw_task"), NULL},
    {UB_L3_SDS_CALIB_WAIT_STOP_FW_TASK_DONE,        (UB_LEVEL_3_1_H_STRING "|L3:wait_stop_fw_task_done"),        NULL},
    {UB_L3_SDS_CALIB_DS_DIG_RESET,                  (UB_LEVEL_3_1_H_STRING "|L3:ds_dig_reset"),                  NULL},
    {UB_L3_SDS_CALIB_CS_POWER_UP,                   (UB_LEVEL_3_1_H_STRING "|L3:cs_power_up"),                   NULL},
    {UB_L3_SDS_CALIB_WAIT_CS_POWER_UP_DONE,         (UB_LEVEL_3_1_H_STRING "|L3:wait_cs_power_up_done"),         NULL},
    {UB_L3_SDS_CALIB_DS_POWER_UP,                   (UB_LEVEL_3_1_H_STRING "|L3:ds_power_up"),                   NULL},
    {UB_L3_SDS_CALIB_WAIT_DS_POWER_UP_DONE,         (UB_LEVEL_3_1_H_STRING "|L3:wait_ds_power_up_done"),         NULL},
    {UB_L3_SDS_CALIB_CS_CALIB_CONFIG,               (UB_LEVEL_3_1_H_STRING "|L3:cs_calib_config"),               NULL},
    {UB_L3_SDS_CALIB_WAIT_CS_CALIB_DONE,            (UB_LEVEL_3_1_H_STRING "|L3:wait_cs_calib_done"),            NULL},
    {UB_L3_SDS_CALIB_DS_CALIB_CONFIG,               (UB_LEVEL_3_1_H_STRING "|L3:ds_calib_config"),               NULL},
    {UB_L3_SDS_CALIB_WAIT_DS_CALIB_DONE,            (UB_LEVEL_3_1_H_STRING "|L3:wait_ds_calib_done"),            NULL},
    {UB_L3_SDS_CALIB_ERROR,                         (UB_LEVEL_3_1_H_STRING "|L3:calib_error"),                   NULL},
    {UB_L3_SDS_CALIB_END,                           (UB_LEVEL_3_1_H_STRING "|L3:calib_end"),                     NULL},
    LINK_STATUS_TABLE_END,
};

// ub Level 3.2
static const struct link_status_string_iterm ub_level_3_2_table[] = {
    { UB_L3_LINKDOWN_WAIT_UB_START_LINKDOWN,   (UB_LEVEL_3_2_H_STRING "|L3:wait_ub_start_linkdown"),     NULL },
    { UB_L3_LINKDOWN_WAIT_SSU_PORT_CELL_CLEAR, (UB_LEVEL_3_2_H_STRING "|L3:wait_ssu_port_cell_clear"),   NULL },
    { UB_L3_LINKDOWN_WAIT_SSU_OQ_QUEUE_CLEAR,  (UB_LEVEL_3_2_H_STRING "|L3:wait_ssu_oq_queue_clear"),    NULL },
    { UB_L3_LINKDOWN_WAIT_LINKDOWN_SUCCESS,    (UB_LEVEL_3_2_H_STRING "|L3:wait_linkdown_success"),      NULL },
    { UB_L3_LINKDOWN_OFF,                      (UB_LEVEL_3_2_H_STRING "|L3:linkdown_off"),               NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 3.3
static const struct link_status_string_iterm ub_level_3_3_table[] = {
    { UB_L3_SDS_ADAPT_START,                      (UB_LEVEL_3_3_H_STRING "|L3:adapt_start"),                NULL },
    { UB_L3_SDS_ADAPT_CHECK_ALOS,                 (UB_LEVEL_3_3_H_STRING "|L3:check_alos"),                 NULL },
    { UB_L3_SDS_ADAPT_MACRO_DS_STOP_FW_TASK,      (UB_LEVEL_3_3_H_STRING "|L3:macro_ds_stop_fw_task"),      NULL },
    { UB_L3_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL, (UB_LEVEL_3_3_H_STRING "|L3:ds_api_config_adapt_normal"), NULL },
    { UB_L3_SDS_ADAPT_INITIAL_ADAPT,              (UB_LEVEL_3_3_H_STRING "|L3:initial_adapt"),              NULL },
    { UB_L3_SDS_ADAPT_WAIT_DONE,                  (UB_LEVEL_3_3_H_STRING "|L3:wait_done"),                  NULL },
    { UB_L3_SDS_ADAPT_CONTINUOUS_ADAPT,           (UB_LEVEL_3_3_H_STRING "|L3:continuous_adapt"),           NULL },
    { UB_L3_SDS_ADAPT_CHECK_CLOS,                 (UB_LEVEL_3_3_H_STRING "|L3:check_clos"),                 NULL },
    { UB_L3_SDS_ADAPT_CHECK_SNR,                  (UB_LEVEL_3_3_H_STRING "|L3:check_snr"),                  NULL },
    { UB_L3_SDS_ADAPT_LPO_OPTIMIZE,               (UB_LEVEL_3_3_H_STRING "|L3:lpo_optimize"),               NULL },
    { UB_L3_SDS_ADAPT_ERROR,                      (UB_LEVEL_3_3_H_STRING "|L3:adapt_error"),                NULL },
    { UB_L3_SDS_ADAPT_END,                        (UB_LEVEL_3_3_H_STRING "|L3:adapt_end"),                  NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 2.0
static const struct link_status_string_iterm ub_level_2_0_table[] = {
    { UB_L2_0_SWITCH_SPEED_PROCESS,  (UB_LEVEL_3_0_H_STRING), ub_level_3_0_table },
    { UB_L2_1_SDS_CALIB_PROCESS,     (UB_LEVEL_3_1_H_STRING), ub_level_3_1_table },
    LINK_STATUS_TABLE_END,
};

// ub Level 2.1
static const struct link_status_string_iterm ub_level_2_1_table[] = {
    { UB_L2_1_LINKDOWN_PROCESS,  (UB_LEVEL_3_2_H_STRING), ub_level_3_2_table },
    { UB_L2_1_SDS_ADAPT_PROCESS, (UB_LEVEL_3_3_H_STRING), ub_level_3_3_table },
    LINK_STATUS_TABLE_END,
};

// ub Level 2.2
static const struct link_status_string_iterm ub_level_2_2_table[] = {
    { UB_L2_WAIT_GUID,          (UB_LEVEL_2_2_H_STRING "|L2:wait_guid"),        NULL },
    { UB_L2_LINK_PARAM_EXCHG,   (UB_LEVEL_2_2_H_STRING "|L2:link_param_exchg"), NULL },
    { UB_L2_PARAM_GET,          (UB_LEVEL_2_2_H_STRING "|L2:param_get"),        NULL },
    { UB_L2_ERROR,              (UB_LEVEL_2_2_H_STRING "|L2:link_error"),       NULL },
    { UB_L2_OFF,                (UB_LEVEL_2_2_H_STRING "|L2:link_off"),         NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 1.0
static const struct link_status_string_iterm ub_level_1_0_table[] = {
    { UB_L1_GEN_LINK_STATUS_START,           (UB_LEVEL_2_0_H_STRING),                       ub_level_2_0_table },
    { UB_L1_GEN_LINK_STATUS_WAIT_DETECT,     (UB_LEVEL_2_1_H_STRING),                       ub_level_2_1_table },
    { UB_L1_GEN_LINK_STATUS_WAIT_MAC_LINKUP, (UB_LEVEL_1_0_H_STRING "|L1:wait_mac_linkup"), NULL },
    { UB_L1_GEN_LINK_STATUS_CHECK_PCS_ERR,   (UB_LEVEL_1_0_H_STRING "|L1:check_pcs_err"),   NULL },
    { UB_L1_GEN_LINK_STATUS_PRE_DL_LINK,     (UB_LEVEL_1_0_H_STRING "|L1:pre_dl_link"),     NULL },
    { UB_L1_GEN_LINK_STATUS_WAIT_DL_LINKUP,  (UB_LEVEL_1_0_H_STRING "|L1:wait_dl_linkup"),  NULL },
    { UB_L1_GEN_LINK_STATUS_EXCHANGE,        (UB_LEVEL_2_2_H_STRING),                       ub_level_2_2_table },
    { UB_L1_GEN_LINK_STATUS_LINK_FAIL,       (UB_LEVEL_1_0_H_STRING "|L1:link_fail"),       NULL },
    { UB_L1_GEN_LINK_STATUS_OFF,             (UB_LEVEL_1_0_H_STRING "|L1:link_off"),        NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 1.1
static const struct link_status_string_iterm ub_level_1_1_table[] = {
    { UB_L1_MONITOR_START,            (UB_LEVEL_1_1_H_STRING "|L1:monitor_start"),            NULL },
    { UB_L1_MONITOR_LINK_DOWN_FILTER, (UB_LEVEL_1_1_H_STRING "|L1:monitor_link_down_filter"), NULL },
    LINK_STATUS_TABLE_END,
};

// ub Level 0
static const struct link_status_string_iterm ub_adapt_table[] = {
    { UB_L0_MAC_LINK_STATUS_START,        "L0:start",            NULL },
    { UB_L0_MAC_LINK_STATUS_SWITCH_SPEED, "L0:switch_speed",     NULL },
    { UB_L0_MAC_LINK_STATUS_LINK_PROC,    UB_LEVEL_1_0_H_STRING, ub_level_1_0_table },
    { UB_L0_MAC_LINK_STATUS_LINK_UPDATE,  UB_LEVEL_1_1_H_STRING, ub_level_1_1_table },
    LINK_STATUS_TABLE_END,
};

// uboe Level 2
static const struct link_status_string_iterm uboe_level_2_table[] = {
    { UBOE_L2_SDS_ADAPT_START,                      (UBOE_LEVEL_2_H_STRING "|L2:start"),                      NULL },
    { UBOE_L2_SDS_ADAPT_CHECK_ALOS,                 (UBOE_LEVEL_2_H_STRING "|L2:check_alos"),                 NULL },
    { UBOE_L2_SDS_ADAPT_MACRO_DS_STOP_FW_TASK,      (UBOE_LEVEL_2_H_STRING "|L2:macro_ds_stop_fw_task"),      NULL },
    { UBOE_L2_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL, (UBOE_LEVEL_2_H_STRING "|L2:ds_api_config_adapt_normal"), NULL },
    { UBOE_L2_SDS_ADAPT_INITIAL_ADAPT,              (UBOE_LEVEL_2_H_STRING "|L2:initial_adapt"),              NULL },
    { UBOE_L2_SDS_ADAPT_WAIT_DONE,                  (UBOE_LEVEL_2_H_STRING "|L2:wait_done"),                  NULL },
    { UBOE_L2_SDS_ADAPT_CONTINUOUS_ADAPT,           (UBOE_LEVEL_2_H_STRING "|L2:continuous_adapt"),           NULL },
    { UBOE_L2_SDS_ADAPT_CHECK_CLOS,                 (UBOE_LEVEL_2_H_STRING "|L2:check_clos"),                 NULL },
    { UBOE_L2_SDS_ADAPT_CHECK_SNR,                  (UBOE_LEVEL_2_H_STRING "|L2:check_snr"),                  NULL },
    { UBOE_L2_SDS_ADAPT_LPO_OPTIMIZE,               (UBOE_LEVEL_2_H_STRING "|L2:lpo_optimize"),               NULL },
    { UBOE_L2_SDS_ADAPT_ERROR,                      (UBOE_LEVEL_2_H_STRING "|L2:serdes_adapt_error"),         NULL },
    { UBOE_L2_SDS_ADAPT_END,                        (UBOE_LEVEL_2_H_STRING "|L2:serdes_adapt_end"),           NULL },
    LINK_STATUS_TABLE_END,
};

// uboe Level 1
static const struct link_status_string_iterm uboe_level_1_table[] = {
    { UBOE_L1_GEN_LINK_STATUS_START_ETH,         (UBOE_LEVEL_1_H_STRING "|L1:start_eth"),          NULL },
    { UBOE_L1_GEN_LINK_STATUS_SERDES_ADAPT,      (UBOE_LEVEL_2_H_STRING),                          uboe_level_2_table },
    { UBOE_L1_GEN_LINK_STATUS_HIMAC_LINK,        (UBOE_LEVEL_1_H_STRING "|L1:himac_link"),         NULL },
    { UBOE_L1_GEN_LINK_STATUS_CHECK_PCS_ERR_ETH, (UBOE_LEVEL_1_H_STRING "|L1:check_pcs_err_eth"),  NULL },
    { UBOE_L1_GEN_LINK_STATUS_LINK_FAIL_ETH,     (UBOE_LEVEL_1_H_STRING "|L1:link_fail_eth"),      NULL },
    { UBOE_L1_GEN_LINK_STATUS_OFF_ETH,           (UBOE_LEVEL_1_H_STRING "|L1:link_off_eth"),       NULL },
    LINK_STATUS_TABLE_END,
};

// uboe Level 0
static const struct link_status_string_iterm uboe_adapt_table[] = {
    { UBOE_L0_MAC_LINK_STATUS_START,        "L0:start",            NULL },
    { UBOE_L0_MAC_LINK_STATUS_SWITCH_SPEED, "L0:switch_speed",     NULL },
    { UBOE_L0_MAC_LINK_STATUS_LINK_PROC,    UBOE_LEVEL_1_H_STRING, uboe_level_1_table },
    { UBOE_L0_MAC_LINK_STATUS_LINK_UPDATE,  "L0:link_update",      NULL },
    LINK_STATUS_TABLE_END,
};

// lane Level 1
static const struct link_status_string_iterm lane_level_1_table[] = {
    { LANE_RL1_SDS_ADAPT_START,                      (LANE_LEVEL_1_H_STRING "|L1:start"),                      NULL },
    { LANE_RL1_SDS_ADAPT_CHECK_ALOS,                 (LANE_LEVEL_1_H_STRING "|L1:check_alos"),                 NULL },
    { LANE_EL1_SDS_ADAPT_MACRO_DS_STOP_FW_TASK,      (LANE_LEVEL_1_H_STRING "|L1:macro_ds_stop_fw_task"),      NULL },
    { LANE_RL1_SDS_ADAPT_DS_API_CONFIG_ADAPT_NORMAL, (LANE_LEVEL_1_H_STRING "|L1:ds_api_config_adapt_normal"), NULL },
    { LANE_RL1_SDS_ADAPT_INITIAL_ADAPT,              (LANE_LEVEL_1_H_STRING "|L1:initial_adapt"),              NULL },
    { LANE_RL1_SDS_ADAPT_WAIT_DONE,                  (LANE_LEVEL_1_H_STRING "|L1:wait_done"),                  NULL },
    { LANE_RL1_SDS_ADAPT_CONTINUOUS_ADAPT,           (LANE_LEVEL_1_H_STRING "|L1:continuous_adapt"),           NULL },
    { LANE_RL1_SDS_ADAPT_CHECK_CLOS,                 (LANE_LEVEL_1_H_STRING "|L1:check_clos"),                 NULL },
    { LANE_RL1_SDS_ADAPT_CHECK_SNR,                  (LANE_LEVEL_1_H_STRING "|L1:check_snr"),                  NULL },
    { LANE_RL1_SDS_ADAPT_LPO_OPTIMIZE,               (LANE_LEVEL_1_H_STRING "|L1:lpo_optimize"),               NULL },
    { LANE_RL1_SDS_ADAPT_ERROR,                      (LANE_LEVEL_1_H_STRING "|L1:sds_adapt_error"),            NULL },
    { LANE_RL1_SDS_ADAPT_END,                        (LANE_LEVEL_1_H_STRING "|L1:sds_adapt_end"),              NULL },
    LINK_STATUS_TABLE_END,
};

// lane Level 0
static const struct link_status_string_iterm lane_raise_table[] = {
    { LANE_RL0_GEN_LINK_EXPAND_START,              "L0:start",                NULL },
    { LANE_RL0_GEN_LINK_EXPAND_DS_STOP_FW_TASK,    "L0:ds_stop_fw_task",      NULL },
    { LANE_RL0_GEN_LINK_EXPAND_DS_DIG_RESET,       "L0:ds_dig_reset",         NULL },
    { LANE_RL0_GEN_LINK_EXPAND_DS_CALIB_CONFIG,    "L0:wait_ds_calib_config", NULL },
    { LANE_RL0_GEN_LINK_EXPAND_WAIT_DS_CALIB_DONE, "L0:wait_sds_adapt",       NULL },
    { LANE_RL0_GEN_LINK_EXPAND_WAIT_DP_READY,      "L0:wait_dp_ready",        NULL },
    { LANE_RL0_GEN_LINK_EXPAND_SDS_ADAPT,          LANE_LEVEL_1_H_STRING,     lane_level_1_table },
    { LANE_RL0_GEN_LINK_EXPAND_RETRAIN,            "L0:retrain",              NULL},
    LINK_STATUS_TABLE_END,
};

static const struct link_status_string_iterm *const link_status_string_table[] = {
    uboe_adapt_table,
    ub_adapt_table,
    lane_raise_table,
};

static int get_gmt_date_string(char *buffer, const int buffer_length, const struct timeval link_time)
{
    struct tm *timeinfo = NULL;
    
    timeinfo = gmtime(&link_time.tv_sec);
    if (timeinfo == NULL) {
        hccn_err("Failed to get GMT time");
        return -TOOL_EXCEPT_INVALID_ARGUMENT;
    }
    const char *weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return sprintf_s(buffer, buffer_length, "%s %s %d %02d:%02d:%02d %d",
                    weekdays[timeinfo->tm_wday],
                    months[timeinfo->tm_mon],
                    timeinfo->tm_mday,
                    timeinfo->tm_hour,
                    timeinfo->tm_min,
                    timeinfo->tm_sec,
                    timeinfo->tm_year + TIME_START_YEAR);
}

static int get_level_status(const struct port_link_info_machine *info, int level)
{
    switch (level) {
    case LINK_LEVEL_STAGE_0:
        return (int)info->level0;
    case LINK_LEVEL_STAGE_1:
        return (int)info->level1;
    case LINK_LEVEL_STAGE_2:
        return (int)info->level2;
    case LINK_LEVEL_STAGE_3:
        return (int)info->level3;
    default:
        return LINK_INVALID_INDEX;
    }
}

static const char* get_link_status(const struct link_status_string_iterm *table,
    const struct port_link_info_machine *info)
{
    int level = 0;
    int status = 0;
    const char *pre_string = NULL;
    
    for (const struct link_status_string_iterm *iter = table; iter->status != LINK_INVALID_INDEX; iter++) {
        status = get_level_status(info, level);
        if (iter->status == status) {
            level++;
            if (iter->child == NULL) {
                return iter->string;
            } else {
                pre_string = iter->string;
                iter = iter->child - 1; // 因为后面有++操作，所以这里要退一步出来；
            }
        }
    }
    if (pre_string != NULL) {
        if (status == CHILD_STATUS_SUSPEND_VALUE) {
            return pre_string;
        }
    }

    hccn_err("can't find the level status string. error level grade: %d, "
        "level 0: 0x%02X, level 1: 0x%02X, level 2: 0x%02X, level 3: 0x%02X\n",
        level,
        (unsigned int)info->level0,
        (unsigned int)info->level1,
        (unsigned int)info->level2,
        (unsigned int)info->level3);

    return "level status error";
}

static const struct link_info_machine_data* get_mode_info(const struct port_link_info_state_machine *info,
    const unsigned int mode)
{
    if (mode == LINK_UBOE_MODE || mode == LINK_UB_MODE) {
        return &info->link_up_info;
    } else if (mode == LINK_LANE_MODE) {
        return &info->lane_raise_info;
    } else {
        hccn_err("unknown mode %d", mode);
        return NULL;
    }
}

void free_two_dimension_charptr(char **table, int size)
{
    for (int i = 0; i < size; i++) {
        free(table[i]);
    }
    free(table);
}

static char** fill_timestamp(const struct port_link_info_machine *data, const int num, const int iterm_count)
{
    char **timestamp  = NULL;

    timestamp = (char **)calloc(iterm_count, sizeof(char*));
    if (timestamp == NULL) {
        hccn_err("timestamp malloc failed");
        return NULL;
    }

    if (num <= 0) {
        timestamp[0] = (char*)calloc(1, MAX_TIME_STR_LEN);
        if (timestamp[0] == NULL) {
            hccn_err("time string malloc failed");
            free(timestamp);
            return NULL;
        }
        sprintf_s(timestamp[0], MAX_TIME_STR_LEN, "%s", TABLE_IS_EMPTY_STRING);
        return timestamp;
    }

    for (int i = 0; i < iterm_count; i++) {
        timestamp[i] = (char *)calloc(1, MAX_TIME_STR_LEN);
        if (timestamp[i] == NULL) {
            hccn_err("timestamp[%d] malloc failed", i);
            free_two_dimension_charptr(timestamp, i);
            return NULL;
        }
        
        // 这里返回 sprintf_s 的字符数，如果返回值 <= 0，表示失败
        if (get_gmt_date_string(timestamp[i], MAX_TIME_STR_LEN, data[i].link_time) == 0) {
            hccn_err("get gmt date string failed");
            free_two_dimension_charptr(timestamp, i + 1);
            return NULL;
        }
    }
    return timestamp;
}

static const char** fill_status_string(const unsigned int mode, const struct port_link_info_machine *data,
    const int display_num, const int iterm_count)
{
    const char **adapt_status = NULL;

    adapt_status = (const char **)calloc(iterm_count, sizeof(const char *));
    if (adapt_status == NULL) {
        hccn_err("adapt_status malloc failed");
        return NULL;
    }

    if (display_num <= 0) {
        adapt_status[0] = TABLE_IS_EMPTY_STRING;
        return adapt_status;
    }

    for (int i = 0; i < iterm_count; i++) {
        adapt_status[i] = get_link_status(link_status_string_table[mode], data + i);
    }

    return adapt_status;
}

static const char* get_mode_string(const unsigned int mode)
{
    switch (mode) {
        case LINK_UBOE_MODE:
            return TABLE_HEADER_STRING_UBOE_STATUS;
        case LINK_UB_MODE:
            return TABLE_HEADER_STRING_UB_STATUS;
        case LINK_LANE_MODE:
            return TABLE_HEADER_STRING_LANE_STATUS;
        default:
            return "Adapt status: unknow";
    }
}

static int get_iterm_and_num(const int num, int *const display_num, int *const iterm_count)
{
    if (num > 0) {
        if (num > PORT_MODE_INFO_MACHINE_MAX) {
            hccn_err("num: %d, more than the max which %d", PORT_MODE_INFO_MACHINE_MAX, num);
            return -TOOL_EXCEPT_INVALID_RESULT_DATA;
        }
        *display_num = (num > DISPLAY_ITERM_MAX) ?  DISPLAY_ITERM_MAX : num;
        *iterm_count = *display_num;
    } else {
        *display_num = num;
        *iterm_count = INFO_MACHINE_EMPTY_ITERM;
    }
    return 0;
}

static int print_adapt_mode_table(const struct command_context *ctx,
    const struct port_link_info_state_machine *info, const unsigned int mode)
{
    int ret = 0;
    int display_num = 0;
    int iterm_count = 0;
    const char **timestamp = NULL;
    const char **adapt_status = NULL;
    const struct link_info_machine_data *link_info = NULL;
    struct table_header_t header[] = {
        {"Index", TYPE_INT},
        {"Time_Stamp", TYPE_STR},
        {get_mode_string(mode), TYPE_STR},
    };

    link_info = get_mode_info(info, mode); // 获取记录条数
    if (link_info == NULL) {
        hccn_err("get mode information data failed.");
        return -TOOL_EXCEPT_INVALID_RESULT_DATA;
    }
    ret = get_iterm_and_num((int)link_info->machine_num, &display_num, &iterm_count); // 获取表格数据部分行数
    if (ret != 0) {
        hccn_err("machine_num invalid.");
        return ret;
    }
    timestamp = (const char **)fill_timestamp(link_info->history_machine, display_num, iterm_count); // 获取整列时间戳
    if (timestamp == NULL) {
        hccn_err("time conversion failed");
        return -TOOL_EXCEPT_BAD_ALLOC;
    }
    adapt_status = fill_status_string(mode, link_info->history_machine, display_num, iterm_count); // 获取一整列适配状态
    if (adapt_status == NULL) {
        hccn_err("adapt status string conversion failed");
        ret = -TOOL_EXCEPT_BAD_ALLOC;
        goto adapt_status_failed;
    }
    if (malloc_table_prefix_t(DEV_PORT_TYPE, iterm_count, (sizeof(header) / sizeof(struct table_header_t)), header)) {
        hccn_err("malloc table failed.");
        ret = -TOOL_EXCEPT_BAD_ALLOC;
        goto print_table_failed;
    }
    for (int i = 0; i < iterm_count; i++) {
        SET_ENTIRE_ROW(i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, i, timestamp[i], adapt_status[i]);
    }
    print_table();
    clean_table();

print_table_failed:
    free(adapt_status);
adapt_status_failed:
    free_two_dimension_charptr((char**)timestamp, iterm_count);
    return ret;
}

static int print_adapt_status_table(const struct command_context *ctx, const struct port_link_info_state_machine *info)
{
    int ret = 0;
    TOOL_PRINT_INFO("print the adapt status table:");
    ret = print_adapt_mode_table(ctx, info, info->link_mode);
    if (ret != 0) {
        return ret;
    }
    TOOL_PRINT_INFO("print the lane raise table:");
    ret = print_adapt_mode_table(ctx, info, LINK_LANE_MODE);

    return ret;
}

// 为了保证原地排序的数据顺序安全性，不适用快排操作。
void sort_history_machine(struct link_info_machine_data *link_info)
{
    if (!link_info || link_info->machine_num <= 1) {
        return;
    }
    int n = link_info->machine_num;
    struct port_link_info_machine *data = link_info->history_machine;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (data[j].link_time.tv_sec < data[j + 1].link_time.tv_sec ||
                (data[j].link_time.tv_sec == data[j + 1].link_time.tv_sec &&
                data[j].link_time.tv_usec < data[j + 1].link_time.tv_usec)) {
                struct port_link_info_machine temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int tool_adapt_status_exec(struct command_context *ctx)
{
    int ret = 0;
    struct port_link_info_state_machine link_info_history = {0};
    struct product_channel_msg msg = {0};

    SET_PRODUCT_MSG(msg, NULL, 0, &link_info_history, sizeof(link_info_history));
    ret = product_host_device_channel(ctx, CMD_GET_ADAPT_STATUS, &msg);
    if (ret != 0) {
        hccn_err("-adapt_status command execute failed, ret: %d", ret);
        return ret;
    }
    sort_history_machine(&link_info_history.link_up_info);
    sort_history_machine(&link_info_history.lane_raise_info);
    return print_adapt_status_table(ctx, &link_info_history);
}

void tool_adapt_status_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_adapt_status_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-adapt_status", "get port link connection history status");
            tool_print_npu_info(DEV_PORT_TYPE); // 命令需要指定到端口 PORT
            break;
        default:
            break;
    }
}