/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef UBASE_CMD_DATA_H
#define UBASE_CMD_DATA_H

#include <net/if.h>
#include "dev_info_data.h"

#define VL_NUM_PER_PORT 16

#define TC_BUFF_UNIT_SIZE 160

#define MAX_TC_NUM              16
#define REAL_USED_TC_NUM        8
#define INPUT_TC_CFG_LEN        100
#define MAX_TOTAL_RX_TC_SIZE    849600
#define MIN_RX_TC_SIZE          4480
#define TC_BUFF_UNIT_SIZE       160

#define UBASE_OPC_QUERY_TM_PRI_INFO    0x4207
#define QUERY_SET_TC_CFG_CMD           0xFB01
#define QUERY_CUR_TC_BUF_CMD           0xFB02
#define QUERY_NL_SSU_CREDIT_CMD        0xFB03

#define PK_BW_MIN_TIME_VAL      1
#define PK_BW_MAX_TIME_VAL      226
#define PK_BW_DEFAULT_TIME      200
#define BW_MIN_TIME_VAL         100
#define BW_MAX_TIME_VAL         10000
#define BW_DEFAULT_TIME         1000

#define PER_MB (1024*1024)
#define PER_MSECOND 1000

enum {
    WRITE_FLAG = 0,
    READ_FLAG = 1,
};

struct ubase_cmd_buf {
    unsigned short opcode;
    bool is_read;
    unsigned int data_size;
    void *data;
};

struct credit_info {
    unsigned short port_id;
    unsigned short resv;
    unsigned int link_alloc_port_share_credit;
    unsigned int link_cur_used_port_share_credit;
    unsigned int link_alloc_vl_pri_credit[VL_NUM_PER_PORT];
    unsigned int link_cur_used_pri_credit[VL_NUM_PER_PORT];
};

enum qos_op_type {
    OP_NONE = 0,
    OP_MAP,
    OP_UNMAP,
};

struct qos_dscp_args {
    enum qos_op_type op;
    int qos_idx;
    int dscp_idx;
};

#define QOS_OPT_BIT HCCN_BIT(2)
#define DSCP_OPT_BIT HCCN_BIT(3)
#define HCCL_QOS_LEVEL_CNT 8
#define HCCL_QOS_MAX_IDX (HCCL_QOS_LEVEL_CNT - 1)
#define DSCP_MAX_IDX 63
#define QOS_DSCP_CFG_LEN 50
#define QOS_MAP_STRING_LEN 6

struct qos_map_info {
    int dscp_idx;
    int sl_idx;
    int vl_idx; // tc
    bool save_cfg_flag;
    bool need_cfg_default_flag;
    int last_dscp_idx;
};

struct sl_vl_map_info {
    int sl_idx;
    int vl_idx;
};

struct cur_tc_buf_info {
    unsigned int tc_id;
    unsigned int max_tc_tx_buf;
    unsigned int max_tc_rx_buf;
};

struct cur_tc_buf_result {
    char slave_name[IFNAMSIZ];
    struct cur_tc_buf_info info;
};

struct tc_cfg_cmd_args {
    char tc_buff[INPUT_TC_CFG_LEN];
    char waterline[INPUT_TC_CFG_LEN];
};

struct tc_cfg_info {
    unsigned int tc_buffer_size[MAX_TC_NUM];
    unsigned int high_waterline[MAX_TC_NUM];
    unsigned int low_waterline[MAX_TC_NUM];
};

struct tc_cfg_result {
    char slave_name[IFNAMSIZ];
    struct tc_cfg_info info;
};

struct bandwidth_cmd_args {
    unsigned int time_interval;
};

struct bandwidth_t {
    double tx_bandwidth;
    double rx_bandwidth;
};

struct ubase_eth_mac_stats {
    unsigned long long tx_fragment_pkts;
    unsigned long long tx_undersize_pkts;
    unsigned long long tx_undermin_pkts;

    unsigned long long tx_64_octets_pkts;
    unsigned long long tx_65_127_octets_pkts;
    unsigned long long tx_128_255_octets_pkts;
    unsigned long long tx_256_511_octets_pkts;
    unsigned long long tx_512_1023_octets_pkts;
    unsigned long long tx_1024_1518_octets_pkts;
    unsigned long long tx_1519_2047_octets_pkts;
    unsigned long long tx_2048_4095_octets_pkts;
    unsigned long long tx_4096_8191_octets_pkts;
    unsigned long long tx_8192_9216_octets_pkts;
    unsigned long long tx_9217_12287_octets_pkts;
    unsigned long long tx_12288_16383_octets_pkts;
    unsigned long long tx_1519_max_octets_bad_pkts;
    unsigned long long tx_1519_max_octets_good_pkts;
    unsigned long long tx_oversize_pkts;
    unsigned long long tx_jabber_pkts;
    unsigned long long tx_bad_pkts;
    unsigned long long tx_bad_octets;
    unsigned long long tx_good_pkts;
    unsigned long long tx_good_octets;
    unsigned long long tx_total_pkts;
    unsigned long long tx_total_octets;
    unsigned long long tx_unicast_pkts;
    unsigned long long tx_multicast_pkts;
    unsigned long long tx_broadcast_pkts;

    unsigned long long tx_pause_pkts;
    unsigned long long tx_pfc_pkts;
    unsigned long long tx_pri0_pfc_pkts;
    unsigned long long tx_pri1_pfc_pkts;
    unsigned long long tx_pri2_pfc_pkts;
    unsigned long long tx_pri3_pfc_pkts;
    unsigned long long tx_pri4_pfc_pkts;
    unsigned long long tx_pri5_pfc_pkts;
    unsigned long long tx_pri6_pfc_pkts;
    unsigned long long tx_pri7_pfc_pkts;

    unsigned long long tx_mac_ctrl_pkts;
    unsigned long long tx_unfilter_pkts;
    unsigned long long tx_1588_pkts;
    unsigned long long tx_err_all_pkts;
    unsigned long long tx_from_app_good_pkts;
    unsigned long long tx_from_app_bad_pkts;

    unsigned long long rx_fragment_pkts;
    unsigned long long rx_undersize_pkts;
    unsigned long long rx_undermin_pkts;

    unsigned long long rx_64_octets_pkts;
    unsigned long long rx_65_127_octets_pkts;
    unsigned long long rx_128_255_octets_pkts;
    unsigned long long rx_256_511_octets_pkts;
    unsigned long long rx_512_1023_octets_pkts;
    unsigned long long rx_1024_1518_octets_pkts;
    unsigned long long rx_1519_2047_octets_pkts;
    unsigned long long rx_2048_4095_octets_pkts;
    unsigned long long rx_4096_8191_octets_pkts;
    unsigned long long rx_8192_9216_octets_pkts;
    unsigned long long rx_9217_12287_octets_pkts;
    unsigned long long rx_12288_16383_octets_pkts;
    unsigned long long rx_1519_max_octets_bad_pkts;
    unsigned long long rx_1519_max_octets_good_pkts;

    unsigned long long rx_oversize_pkts;
    unsigned long long rx_jabber_pkts;
    unsigned long long rx_bad_pkts;
    unsigned long long rx_bad_octets;
    unsigned long long rx_good_pkts;
    unsigned long long rx_good_octets;
    unsigned long long rx_total_pkts;
    unsigned long long rx_total_octets;
    unsigned long long rx_unicast_pkts;
    unsigned long long rx_multicast_pkts;
    unsigned long long rx_broadcast_pkts;

    unsigned long long rx_pause_pkts;
    unsigned long long rx_pfc_pkts;
    unsigned long long rx_pri0_pfc_pkts;
    unsigned long long rx_pri1_pfc_pkts;
    unsigned long long rx_pri2_pfc_pkts;
    unsigned long long rx_pri3_pfc_pkts;
    unsigned long long rx_pri4_pfc_pkts;
    unsigned long long rx_pri5_pfc_pkts;
    unsigned long long rx_pri6_pfc_pkts;
    unsigned long long rx_pri7_pfc_pkts;

    unsigned long long rx_mac_ctrl_pkts;
    unsigned long long rx_symbol_err_pkts;
    unsigned long long rx_fcs_err_pkts;
    unsigned long long rx_send_app_good_pkts;
    unsigned long long rx_send_app_bad_pkts;
    unsigned long long rx_unfilter_pkts;

    unsigned long long tx_merge_frame_ass_error_pkts;
    unsigned long long tx_merge_frame_ass_ok_pkts;
    unsigned long long tx_merge_frame_frag_count;
    unsigned long long rx_merge_frame_ass_error_pkts;
    unsigned long long rx_merge_frame_ass_ok_pkts;
    unsigned long long rx_merge_frame_frag_count;
    unsigned long long rx_merge_frame_smd_error_pkts;
};

struct ubase_query_tm_pri_cmd {
    unsigned short bus_ue_id;
    unsigned char pri_id;
    unsigned char pg_id;
    unsigned char pri_sch_mode;
    unsigned char pri_weight;
    unsigned char c_ir_b;
    unsigned char c_ir_u;
    unsigned char c_ir_s;
    unsigned char c_bs_b;
    unsigned char c_bs_s;
    unsigned char p_ir_b;
    unsigned char p_ir_u;
    unsigned char p_ir_s;
    unsigned char p_bs_b;
    unsigned char p_bs_s;
    unsigned int c_rate;
    unsigned int p_rate;
    unsigned char c_rate_limit_bypass;
    unsigned char p_rate_limit_bypass;
    unsigned char resv1[30U];
};

struct shaping_info {
    char slave_name[IFNAMSIZ];
    unsigned int bw_limit;
    unsigned int bw_max;
};

struct shaping_result {
    struct shaping_info info[DEV_INFO_DEFAULT_BOND_SLAVE_NUM];
};

static inline void ubase_fill_inout_buf(struct ubase_cmd_buf *buf, unsigned short opcode,
    bool is_read, unsigned int data_size, void *data)
{
    buf->opcode = opcode;
    buf->is_read = is_read;
    buf->data_size = data_size;
    buf->data = data;
}
#endif // UBASE_CMD_DATA_H