/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef SHELL_CMD_DATA_H
#define SHELL_CMD_DATA_H

#include "hccn_comm.h"
#include <stdbool.h>
#include <net/if.h>
#include "dev_info_data.h"

#define PROTOCOL_TYPR_UBOE 1

#define BW_FACTOR ((1000.0 * 1000.0) / (1024.0 * 1024.0))
#define TX_MAX_PORT_BW "tx_max_port_bw: "
#define RX_MAX_PORT_BW "rx_max_port_bw: "
#define TX_PORT_BW "real_time_bandwidth_tx: "
#define RX_PORT_BW "real_time_bandwidth_rx: "
#define BIT_TO_BYTE 8

#define TOOL_MAC_STR_LEN 6
#define MAC_STR_LEN 17

#define BOND_ATTR_VAL_STRING_LEN 1

#define MTU_VAL_STRING_LEN 6

#define IP_SPLIT_BIT_0 0
#define IP_SPLIT_BIT_8 8
#define IP_SPLIT_BIT_16 16
#define IP_SPLIT_BIT_24 24
#define SPLIT_UIP(ip, number) (((ip) >> (number)) & 0xff)

#define UDHCPC_TIMEOUT_DEFAULT 3
#define MAX_UDHCPC_TIMEOUT 300
#define MAX_UDHCPC_OUTBUFF_LEN 5000

#define MAX_LOOPBACK_MODE_NAME 16
#define RXMAC2TXMAC "rxmac2txmac"
#define TXMAC2RXMAC "txmac2rxmac"
#define TXPCS2RXPCS "txpcs2rxpcs"
#define LOOPBACK_EN "loopback_en: "

#define PRIORITY_NUM  8
#define PFC_CFG_STR_LEN 15 // 2 * PRIORITY_NUM - 1

#define UBOE_PKT_STAT_NUM 48
#define UB_PKT_STAT_NUM 40

#define PRIORITY_ARGS(args) (args)[0], (args)[1], (args)[2], (args)[3], (args)[4], (args)[5], (args)[6], (args)[7]
struct pfc_cmd_args {
    char pfc_enabled[PFC_CFG_STR_LEN + 1];
};

struct prio_tc_cmd_args {
    char map[PFC_CFG_STR_LEN + 1];
};

struct dscp_to_tc_args {
    bool get_all_flag;
    int dscp_val;
};

struct mtu_cmd_args {
    int mtu_size;
};

enum link_ops_type {
    SET_LINK_NONE = 0,
    SET_LINK_UP,
    SET_LINK_DOWN
};

struct set_link_args {
    enum link_ops_type type;
};

#define MAC_ADDR_ARGS(mac) (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]

struct mac_val {
    unsigned char mac_pieces[TOOL_MAC_STR_LEN];
};

struct show_res_cmd_args {
    int res_type;
    int key_id;
};

struct show_list_cmd_args {
    int res_type;
};

enum ds_net_context_type {
    DS_TYPE_NONE = 0,
    DS_TYPE_AEQC,
    DS_TYPE_CEQC,
    DS_TYPE_MAX
};

struct context_cmd_args {
    enum ds_net_context_type type;
    int index;
};

enum eth_test_mode {
    ETH_TEST_MODE_OFFLINE = 1,
    ETH_TEST_MODE_MAX
};

struct eth_test_cmd_args {
   enum eth_test_mode mode;
};

enum stat_set_mode {
    STAT_SET_MODE_CLEAR = 1,
    STAT_SET_MODE_MAX
};

struct stat_cmd_args {
   enum stat_set_mode mode;
};

struct bit_err_res {
    unsigned long long decoded_fail_block_num;
    unsigned long long fec_err;
};

struct ds_port_stat_info {
    unsigned int port_id;
    unsigned int is_uboe_port;
    union {
        struct {
            unsigned long long ub_ipv4_pkt_cnt_rx;
            unsigned long long ub_ipv6_pkt_cnt_rx;
            unsigned long long unic_ipv4_pkt_cnt_rx;
            unsigned long long unic_ipv6_pkt_cnt_rx;
            unsigned long long ub_compact_pkt_cnt_rx;
            unsigned long long ub_umoc_ctph_cnt_rx;
            unsigned long long ub_umoc_ntph_cnt_rx;
            unsigned long long ub_mem_pkt_cnt_rx;
            unsigned long long unknown_pkt_cnt_rx;
            unsigned long long drop_ind_cnt_rx;
            unsigned long long err_ind_cnt_rx;
            unsigned long long to_host_pkt_cnt_rx;
            unsigned long long to_imp_pkt_cnt_rx;
            unsigned long long to_mar_pkt_cnt_rx;
            unsigned long long to_link_pkt_cnt_rx;
            unsigned long long to_noc_pkt_cnt_rx;
            unsigned long long route_err_cnt_rx;
            unsigned long long out_err_cnt_rx;
            unsigned long long length_err_cnt_rx;
            unsigned long long rx_busi_flit_num;
            unsigned long long rx_send_ack_flit;
            unsigned long long ub_ipv4_pkt_cnt_tx;
            unsigned long long ub_ipv6_pkt_cnt_tx;
            unsigned long long unic_ipv4_pkt_cnt_tx;
            unsigned long long unic_ipv6_pkt_cnt_tx;
            unsigned long long ub_compact_pkt_cnt_tx;
            unsigned long long ub_umoc_ctph_cnt_tx;
            unsigned long long ub_umoc_ntph_cnt_tx;
            unsigned long long ub_mem_pkt_cnt_tx;
            unsigned long long unknown_pkt_cnt_tx;
            unsigned long long drop_ind_cnt_tx;
            unsigned long long err_ind_cnt_tx;
            unsigned long long lpbk_ind_cnt_tx;
            unsigned long long out_err_cnt_tx;
            unsigned long long length_err_cnt_tx;
            unsigned long long tx_busi_flit_num;
            unsigned long long tx_recv_ack_flit;
            unsigned long long retry_req_sum;
            unsigned long long retry_ack_sum;
            unsigned long long crc_error_sum;
            union  {
                struct {
                    unsigned long long core_mib_rxpausepkts;
                    unsigned long long core_mib_txpausepkts;
                    unsigned long long core_mib_rxpfcpkts;
                    unsigned long long core_mib_txpfcpkts;
                    unsigned long long core_mib_rxbadpkts;
                    unsigned long long core_mib_txbadpkts;
                    unsigned long long core_mib_rxbadoctets;
                    unsigned long long core_mib_txbadoctets;
                } uboe;
            };
        };
        unsigned long long pkt_num[UBOE_PKT_STAT_NUM];
    };
};

struct peak_bandwidth_t {
    double tx_peak_bandwidth;
    double rx_peak_bandwidth;
};

struct ip_cmd_args {
    struct ip_val ip;
    struct ip_val netmask;
};

struct ip_netmask_val {
    unsigned int ip;
    unsigned int netmask;
};

struct gateway_cmd_args {
    struct ip_val gw_addr;
};

enum arp_set_mode {
    ARP_SET_MODE_NONE = 0,
    ARP_SET_MODE_ADD = 1,
    ARP_SET_MODE_DEL = 2,
    ARP_SET_MODE_MAX
};

struct arp_cmd_args {
    enum arp_set_mode mode;
    struct ip_val ip;
    struct mac_val mac;
};

enum lb_set_mode {
    LOOPBACK_SET_NONE = 0,
    LOOPBACK_SET_ENABLE,
    LOOPBACK_SET_CLEAR,
    LOOPBACK_SET_MODE_MAX
};

struct lb_cmd_args {
   enum lb_set_mode mode;
   char lb_mode_name[MAX_LOOPBACK_MODE_NAME];
};

struct lb_state {
    bool is_rxmac2txmac_en;
    bool is_txmac2rxmac_en;
    bool is_txpcs2rxpcs_en;
};

struct bond_attr_cmd_args {
    int lacp_rate;
};

enum udhcp_proc_type {
    UDHCP_PROC_TYPE_INIT = 0,
    UDHCP_PROC_RETAIN = 1,
    UDHCP_PROC_QUIT = 2,
};

struct udhcpc_cmd_args {
    int timeout;
    enum udhcp_proc_type proc_type;
};

enum tc_set_mode {
    TC_SET_NONE = 0,
    TC_SET_ENABLE,
    TC_SET_CLEAR,
    TC_SET_MODE_MAX
};

struct tc_stat_cmd_args {
    unsigned int tc_id;
    enum tc_set_mode mode;
};

struct tc_stat_info {
    unsigned int tc_id;
    unsigned int tx_num;
    unsigned int rx_num;
};

struct tc_packet_stat {
    unsigned int tc_id;
    struct {
        char dev_name[IFNAMSIZ];
        bool is_valid;
        unsigned int tx_num;
        unsigned int rx_num;
    } packet_stat[DEV_INFO_DEFAULT_BOND_SLAVE_NUM];
};

#endif // SHELL_CMD_DATA_H
