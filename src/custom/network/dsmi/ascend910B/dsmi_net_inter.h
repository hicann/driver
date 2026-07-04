/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __DSMI_NET_INTER_H__
#define __DSMI_NET_INTER_H__

#include <stdbool.h>
#include "dsmi_network_interface.h"

/* the num of ds_port_stat_info pkt stat items */
#define ETH_PKT_STAT_NUM    28
#define NIC_PKT_STAT_NUM    4
#define ROCE_PKT_STAT_NUM   14

// supernodes ping reply
#define PING_PACKET_NUM_MAX 1000
#define TASK_WAIT_MAX_TIME 60
#define ARGC_NUM_10 10
#define STR_TO_INT_TEN 10

struct prbs_adapt_mode_info {
    unsigned int mode;
    unsigned int master_flag; /* 主从DIE标记 */
};

typedef struct {
    hccs_ping_reply_info info;
    bool completed;
} hccs_ping_reply_info_ext;

enum ds_net_opcode_type_ext {
    DS_MIN_CMD_EXT = 0x0080,
    DS_START_PERFTEST = 0x0081,
    DS_GET_PERFTEST_STATUS = 0x0082,
    DS_GET_PERFTEST_REPORT = 0x0083,
    DS_STOP_PERFTEST = 0x0084,
    DS_GET_ETH_SPEED = 0x0085,
    DS_GET_ETH_DUPLEX = 0x0086,
    DS_GET_ETH_SSU_REG = 0x0087,
    DS_GET_SERDES_CTLE_INFO = 0x0088,
    DS_GET_SERDES_DFE_INFO = 0x0089,
    DS_GET_SERDES_FFE_INFO = 0x0090,
    DS_GET_FEC_INFO = 0x0091,
    DS_GET_PCS_INFO = 0x0092,
    DS_IP_RULE_CFG = 0x0093,
    DS_IP_ROUTE_CFG = 0x0094,
    DS_TRIG_GET_CDR_INFO = 0x0095,
    DS_GET_MAC_LANE_INFO = 0x0096,
    DS_GET_CDR_REG_INFO = 0x0097,
    DS_GET_CDR_LOG = 0x0098,
    DS_GET_ADAPT_STATUS_INFO = 0x0099,
    DS_GET_PFC_CFG = 0x009A,
    DS_SET_PFC_CFG = 0x009B,
    DS_GET_TC_CFG = 0x009C,
    DS_SET_TC_CFG = 0x009D,
    DS_GET_CURR_TC_USED = 0x009E,
    DS_PING = 0x009F,
    DS_HCCS_PING = 0x00A0,
    DS_RESET_PERFTEST = 0x0100,
    DS_GET_PRIO_TC_INFO = 0x0101,
    DS_SET_PRIO_TC_INFO = 0x0102,
    DS_SET_FEC_INFO = 0x0103,
    DS_GET_GRATUIT_ARP_INFO = 0x0104,
    DS_SET_GRATUIT_ARP_INFO = 0x0105,
    DS_GET_ROUTE_TABLE_INET6 = 0x0106,
    DS_NEIGH_TABLE_CFG = 0x0107,
    DS_ADD_ROUTE_TABLE_INET6 = 0x0108,
    DS_DELETE_ROUTE_TABLE_INET6 = 0x0109,
    DS_SET_NEIGH_TABLE_CFG = 0x010A,
    DS_SET_CDR_MODE_CMD = 0x010B,
    DS_GET_LINK_DOWN_INFO_CMD = 0x010C,
    DS_GET_TRACEROUTE_INFO = 0x010D,
    DS_START_TRACEROUTE = 0x010E,
    DS_GET_TRACEROUTE_STATUS = 0x010F,
    DS_RESET_TRACEROUTE = 0x0110,
    DS_GET_XSFP_RESET_INFO = 0x0111,
    DS_SET_XSFP_RESET_INFO = 0x0112,
    DS_SET_HOST_INFO = 0x0113,
    DS_UPDATE_ROCE_PORT_IPPAIR = 0x0114,
    DS_CLEAR_ROCE_PORT_IPPAIR = 0x0115,
    DS_GET_ROCE_PORT_IPPAIR = 0x0116,
    DS_GET_EXTRA_STAT_INFO = 0x0117,
    DS_GET_CDR_SNR_CMD = 0x0118,
    DS_SET_NPU_PRBS_FLAG = 0x0119,
    DS_GET_CDR_VERSION_INFO_CMD = 0x011A,
    DS_CLEAR_EXTRA_STAT_INFO = 0x011B,
    DS_GET_DOWNGRADE_LANE_INFO = 0x011C,
    DS_SET_DOWNGRADE_LANE_INFO = 0x011D,
    DS_GET_FEC_ERROR_INFO = 0x011E,
    DS_GET_PFC_D_INFO = 0x011F,
    DS_CLEAR_PFC_DURATION = 0x0120,
    DS_GET_TC_STAT = 0x0121,
    DS_CLEAR_TC_PACKET_STATISTICS = 0x0122,
    DS_GET_SERDES_INFO_STEADY = 0x0123,
    DS_GET_SERDES_INFO_FLASH = 0x0124,
    DS_GET_QPN_LIST = 0x0125,
    DS_GET_QP_CONTEXT = 0x0126,
    DS_SET_ROCE_CW_BAD_CNT_THD = 0x0127,
    DS_GET_ROCE_CW_BAD_CNT_THD = 0x0128,
    DS_SET_PFC_STORM_WATCHDOG = 0x0129,
    DS_GET_PFC_STORM_WATCHDOG = 0x012A,
    DS_GET_PFC_STORM_INFO = 0x012B,
    DS_CLEAR_PFC_STORM = 0x012C,
    DS_DUMP_OPTICAL_INFO_CMD = 0x012D,
    DS_GET_PING_MESH_INFO = 0x012E,
    DS_GET_PING_MESH_STATE = 0x012F,
    DS_STOP_HCCS_PING_MESH = 0x0130,
    DS_START_PING_MESH_TASK = 0x0131,
    DS_HANDLE_CDR_REG = 0x0132,
    DS_SET_OPTICAL_MODE = 0x0133,
    DS_SET_DOWNDELAY = 0x0134,
    DS_GET_DOWNDELAY = 0x0135,
    DS_SET_PRBS_ADAPT_IN_ORDER = 0x0136,
    DS_GET_CDR_RESET_INFO = 0x0137,
    DS_SET_CDR_RESET_INFO = 0x0138,
    DS_SET_MULTI_ROCE_PORTS = 0x0139,
    DS_GET_MULTI_ROCE_PORTS = 0x013A,
    DS_GET_HUYANG_FMEA = 0x013B,
    DS_GET_SCDR_ESD_STATUS  = 0x013C,
    DS_SET_DIAGNOSTIC_MODE = 0x013D,
    DS_GET_DIAGNOSTIC_MODE = 0x013E,
    DS_SET_DIAGNOSTIC_I2C_ACCESS = 0x013F,
    DS_GET_DEFAULT_GATEWAY_IPV6 = 0x0140,
    DS_SET_DEFAULT_GATEWAY_IPV6 = 0x0141,
    DS_GET_TC_QOS_INFO = 0x0142,
    DS_SET_TC_QOS_INFO = 0x0143,
    DS_GET_XSFP_SNR_QUERY_INFO = 0x0144,
    DS_SET_XSFP_SNR_QUERY_INFO = 0x0145,
    DS_SET_DEVICE_OFFLINE_NET_DOWN = 0x0146,
    DS_SET_MEM_RESERVE = 0x0148,
    DS_GET_MEM_RESERVE = 0x0149,
    DS_DUMP_INFO = 0x014A,
    DS_MAX_CMD_EXT,
};

int dsmi_del_default_gateway_address(int logic_id, int port, unsigned int gateway, bool is_gateway_on_eth);
int dsmi_get_netdev_link(int logic_id, int port, int *link);
int dsmi_clear_netdev_stat(int logic_id, int port);
int dsmi_set_device_offline_nic_down_flag(int logic_id, int enable_flag);
#endif
