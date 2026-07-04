/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DSMI_NETWORK_H
#define DSMI_NETWORK_H

#include "comm_channel.h"
#include "dsmi_common_interface.h"

/** dsmi_network.so 启用 -fvisibility=hidden，不EXPORT_FUNCTION的函数默认不会被so暴露 */

#define EXPORT_FUNCTION __attribute__ ((visibility ("default")))

// 带宽单位是MB/s，对齐A2A3版本的实现，舍弃小数
struct ub_bandwidth_t {
    unsigned int tx_bandwidth;
    unsigned int rx_bandwidth;
};
struct ub_bottom_bandwidth_t {
    double tx_bandwidth;
    double rx_bandwidth;
};

#define UBOE_PKT_STAT_NUM 48

struct ds_port_pkt_stats_info {
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

#define VL_NUM_PER_PORT        16

struct dsmi_credit_info {
    unsigned short port_id;
    unsigned short resv;
    unsigned int link_alloc_port_share_credit;
    unsigned int link_cur_used_port_share_credit;
    unsigned int link_alloc_vl_pri_credit[VL_NUM_PER_PORT];
    unsigned int link_cur_used_pri_credit[VL_NUM_PER_PORT];
};

#define IFNAMSIZ    16
#define DEV_INFO_MAX_IP_NUM 64U
#define DEV_INFO_DEFAULT_BOND_SLAVE_NUM 2U
#define DEV_INFO_MAX_DEV_NUM 32U
#define NETDEV_MAX_NUM         8
#define NETDEV_NAME_MAX_LEN    16

union sockaddr_t {
    struct sockaddr sa;
    struct sockaddr_in sa_in;
    struct sockaddr_in6 sa_in6;
};

struct netdev_info {
    char ifname[IFNAMSIZ];
    union sockaddr_t addr_list[DEV_INFO_MAX_IP_NUM];
    union sockaddr_t mask_list[DEV_INFO_MAX_IP_NUM];
    uint8_t list_size;
    bool is_bond;
    struct {
        uint8_t bond_mode; // BOND_MODE_8023AD, refer to linux/if_bonding.h
        char slaves_ifname[DEV_INFO_DEFAULT_BOND_SLAVE_NUM][IFNAMSIZ];
    } bond_info;
};

struct dsmi_netdev_info_data {
    struct netdev_info data[DEV_INFO_MAX_DEV_NUM];
    unsigned int num;
};

struct dsmi_netdev_list_info {
    int netdev_nums;                                      // 有效netdev数量，暂只支持1个bond属性的网络设备
    char netdev_name[NETDEV_MAX_NUM][NETDEV_NAME_MAX_LEN];          // 网络设备的名称，暂主要服务于以太网口（uboe）场景  bond0、ethc0d0/eth1
};

enum dsmi_ip_addr_type {
    DSMI_IPADDR_TYPE_V4 = 0U,    /**< IPv4 */
    DSMI_IPADDR_TYPE_V6 = 1U,    /**< IPv6 */
    DSMI_IPADDR_TYPE_ANY = 2U
};

#define DSMI_NETDEV_IPV4_LEN 4
#define DSMI_NETDEV_IPV6_LEN 16

struct dsmi_ip_addr {
    union {
        unsigned char ip6[DSMI_NETDEV_IPV6_LEN];
        unsigned char ip4[DSMI_NETDEV_IPV4_LEN];
    } u_addr;
    enum dsmi_ip_addr_type ip_type;
};

struct dsmi_ip_val {
    unsigned int ip_addr;
    unsigned char ip6_addr[MAX_IPV6_NUM];
    char str_ip[MAX_IP_VAL_LEN];
};

struct dsmi_gateway_cmd_args {
    struct dsmi_ip_val gw_addr;
};

#define DSMI_MAC_ADDR_LEN        6
#define DSMI_MAC_STR_LEN         17

struct dsmi_mac_val {
    unsigned char mac_pieces[DSMI_MAC_ADDR_LEN];
};

#define DSMI_MAC_ADDR_ARGS(mac) \
    (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]

#define IP_BYTE_INDEX_1 0
#define IP_BYTE_INDEX_2 1
#define IP_BYTE_INDEX_3 2
#define IP_BYTE_INDEX_4 3
#define IP_SPLIT_BIT_0  0
#define IP_SPLIT_BIT_8  8
#define IP_SPLIT_BIT_16 16
#define IP_SPLIT_BIT_24 24
#define SPLIT_UIP(ip, number) (((ip) >> (number)) & 0xff)

#define MAX_IPV4_LEN 20
#define MAX_IPV6_NUM 16

struct ip_netmask_val {
    unsigned int ip;
    unsigned int netmask;
};

struct ip_val {
    unsigned int ip_addr;
    unsigned char ip6_addr[MAX_IPV6_NUM];
    char str_ip[MAX_IP_VAL_LEN];
};

struct ip_cmd_args {
    struct ip_val ip;
    struct ip_val netmask;
};

enum dcmi_ip_addr_type {
    DCMI_IPADDR_TYPE_V4 = 0, /** IPv4 */
    DCMI_IPADDR_TYPE_V6 = 1, /** IPv6 */
    DCMI_IPADDR_TYPE_ANY = 2 /** IPv4+IPv6 ("dual-stack") */
};

#define FREE_BUF(buf) do { \
    if ((buf) != NULL) {   \
        free((buf));       \
        (buf) = NULL;      \
    }                      \
} while (0)

#define IP_MAX_LEN                      48
#define TRACEROUTE_RESERVE_MAX_LEN      64
#define TRACEROUTE_PACKETS_SENT_NUM     3
#define TRACEROUTE_OUTPUT_MAX_TIME      100000
#define TRACEROUTE_DSET_UNREACHABLE     0x06
#define PERCENT_NUM                     100
#define TRACEROUTE_OUTPUT_ALL_EFFECTIVE 0xff
#define TRACEROUTE_OUTPUT_ALL_LOSS      0x07
#define TRACEROUTE_OUTPUT_INDEX_TWO     2
#define TRACEROUTE_TTL_MAX              255
#define MAX_TRACEROUTE_WAITING_TIMES    600
#define INVALID_TIME_RESULT             (-1)

enum traceroute_status {
    TRACEROUTE_STATUS_HALT    = 0,
    TRACEROUTE_STATUS_RUNNING = 1,
    TRACEROUTE_STATUS_ERROR   = 2
};

struct traceroute_info {
    int max_ttl;
    int tos;
    int waittime;
    int sport;
    int dport;
    struct ip_val src_ip;
    struct ip_val dst_ip;
    bool reset_flag;
};

struct dsmi_traceroute_param {
    int max_ttl;
    int tos;
    int waittime;
    int src_port;
    int dst_port;
    char src_ip[IP_MAX_LEN];
    char dst_ip[IP_MAX_LEN];
    bool reset_flag;
};

struct traceroute_result {
    int func_mask;
    char src_ip[IP_MAX_LEN];
    char dst_ip[IP_MAX_LEN];
    int snt;
    double loss;
    double last;
    double avg;
    double best;
    double wrst;
    double stdev;
    char reserve[TRACEROUTE_RESERVE_MAX_LEN];
};

struct dsmi_traceroute_result {
    unsigned int result_nums;
    struct traceroute_result *result_data;
};

struct dcmi_bond_pfc_duration_info {
    unsigned char slave0_name[NETDEV_NAME_MAX_LEN];
    unsigned long long slave0_tx[MAX_PRI_NUM];
    unsigned long long slave0_rx[MAX_PRI_NUM];
    unsigned char slave1_name[NETDEV_NAME_MAX_LEN];
    unsigned long long slave1_tx[MAX_PRI_NUM];
    unsigned long long slave1_rx[MAX_PRI_NUM];
};

EXPORT_FUNCTION int dsmi_get_ub_bandwidth(int device_id, int udie_id, int port_id,
                                          unsigned int time_interval, struct ub_bandwidth_t *bw);
EXPORT_FUNCTION int dsmi_get_device_ub_ping_info(int device_id, struct dcmi_ub_ping_operate *ping_args,
    struct ub_ping_result* ping_result);
EXPORT_FUNCTION int dsmi_get_port_pkt_stats_info(int device_id, int udie_id, int port_id,
    struct ds_port_pkt_stats_info *port_pkt_stats_info);
EXPORT_FUNCTION int dsmi_get_port_avail_credit_info(int device_id, int udie_id, int port_id,
    struct dsmi_credit_info *port_avail_credit_info);
EXPORT_FUNCTION int dsmi_get_device_netdev_list_info(int dev_id, struct dsmi_netdev_list_info *netdev_list_info);
EXPORT_FUNCTION int dsmi_get_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway_addr);
EXPORT_FUNCTION int dsmi_set_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway_addr);
EXPORT_FUNCTION int dsmi_get_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    char *mac_addr, unsigned int mac_addr_len);
EXPORT_FUNCTION int dsmi_set_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    const char *mac_addr, unsigned int mac_addr_len);
EXPORT_FUNCTION int dsmi_get_device_bond_ip_address(int device_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address);
EXPORT_FUNCTION int dsmi_set_device_bond_ip_address(int device_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address);
EXPORT_FUNCTION int dsmi_start_ubping_mesh_proc(int device_id, struct ubping_mesh_operate *operate);
EXPORT_FUNCTION int dsmi_stop_ubping_mesh_proc(int device_id);
EXPORT_FUNCTION int dsmi_get_ubping_mesh_info_proc(int device_id, struct ubping_mesh_info *result_info);
EXPORT_FUNCTION int dsmi_get_ubping_mesh_state_proc(int device_id, unsigned int *state);
EXPORT_FUNCTION int dsmi_exec_bond_traceroute(int device_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_traceroute_param *traceroute_info, struct dsmi_traceroute_result *result);
EXPORT_FUNCTION int dsmi_get_netdev_pfc_duration_info(int logic_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dcmi_bond_pfc_duration_info *pfc_duration_info);
EXPORT_FUNCTION int dsmi_clear_netdev_pfc_duration_info(int logic_id, const char *netdev_name,
    unsigned int netdev_name_len);
#endif
