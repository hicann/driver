/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __DCMI_NETWORK_INTF_H__
#define __DCMI_NETWORK_INTF_H__

#include "dcmi_interface_api.h"

#define MAX_PAYLOAD_TYPE 3
#define NETWORK_RDMA_BYTE_TO_MBYTE 100
#define NETWORK_PORT_COUNT_DEFAULT 1
#define Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1     0x1C
#define Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2     0x1D
#define MAX_PKT_SIZE    3000
#define MIN_PKT_SIZE    1792
#define MAX_SEND_NUM    1000
#define MAX_PKT_INTERVAL 1000
#define MAX_TASK_INTERVAL 60
#define MAX_PAYLOAD_LEN   3
#define MAX_TASK_ID       1
#define STR_NUM_BASE    10
#define NS_CONVERT_TO_US  1000
#define NS_CONVERT_TO_S   1000000000
#define SDID_LEN_MAX    10

// ip地址转换为sdid
// ip地址格式：[192].[server_id].[2+die_id].[199-device_id]
// sdid格式：[10位server_id][4位chip_id][2位die_id][16位device_id]
#define A3_SUPERPOD_MAX_NUMS 48
#define CHIP_DIE_CNT 2
#define VNIC_IP_HEADER 192

#define IP_GET_HEADER(A) ((A) & 0xFF)
#define IP_GET_SERVERID(A) (((A) >> 8) & 0xFF)
#define IP_GET_DIEID(A)    ((((A) >> 16) & 0xFF) - 2)
#define IP_GET_DEVICEID(A) (199 - (((A) >> 24) & 0xFF))
#define IP_CONVERT_SDID(A) ((IP_GET_SERVERID(A) << 22) | ((IP_GET_DEVICEID(A) / 2) << 18) | \
        (IP_GET_DIEID(A) << 16) | (IP_GET_DEVICEID(A)))
#define SDID_GET_SERVERID(A) (((A) >> 22) & 0xFF)
#define SDID_GET_CHIPID(A) (((A) >> 18) & 0xF)
#define SDID_GET_DIEID(A) (((A) >> 16) & 0x3)
#define SDID_GET_DEVICEID(A) ((A) & 0xFFFF)

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

#define VL_NUM_PER_PORT 16

struct dsmi_credit_info {
    unsigned short port_id;
    unsigned short resv;
    unsigned int link_alloc_port_share_credit;
    unsigned int link_cur_used_port_share_credit;
    unsigned int link_alloc_vl_pri_credit[VL_NUM_PER_PORT];
    unsigned int link_cur_used_pri_credit[VL_NUM_PER_PORT];
};

struct dsmi_netdev_list_info {
    int netdev_nums;
    char netdev_name[NETDEV_MAX_NUM][NETDEV_NAME_MAX_LEN];
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

#define IP_MAX_LEN                      48

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

struct dsmi_traceroute_result {
    unsigned int result_nums;
    struct traceroute_result *result_data;
};

int dcmi_set_traceroute_main(int logic_id, struct dcmi_traceroute_info param_in,
    struct dcmi_network_node_info *ret_info, unsigned int ret_info_size);
int dcmi_traceroute_reset(int logic_id);
int dsmi_get_port_pkt_stats_info(int dev_id, int udie_id, int port_id,
    struct ds_port_pkt_stats_info *port_pkt_stats_info);
int dsmi_get_port_avail_credit_info(int dev_id, int udie_id, int port_id,
    struct dsmi_credit_info *port_avail_credit_info);
int dsmi_get_device_netdev_list_info(int dev_id, struct dsmi_netdev_list_info *ds_netdev_list_info);
int dsmi_set_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway);
int dsmi_get_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway);
int dsmi_set_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    const char *mac_addr, unsigned int mac_addr_len);
int dsmi_get_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    char *mac_addr, unsigned int mac_addr_len);
int dsmi_get_device_bond_ip_address(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
                                    struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address);
int dsmi_set_device_bond_ip_address(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
                                    struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address);
int dsmi_exec_bond_traceroute(int device_id, const char *netdev_name,  unsigned int netdev_name_len,
    struct dsmi_traceroute_param *traceroute_info, struct dsmi_traceroute_result *result);
int dsmi_get_netdev_pfc_duration_info(int logic_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dcmi_bond_pfc_duration_info *pfc_duration_info);
int dsmi_clear_netdev_pfc_duration_info(int logic_id, const char *netdev_name, unsigned int netdev_name_len);
#endif /* __DCMI_NETWORK_INTF_H__ */