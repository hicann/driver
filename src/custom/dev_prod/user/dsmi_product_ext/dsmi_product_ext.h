/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __DSMI_PRODUCT_EXT_H__
#define __DSMI_PRODUCT_EXT_H__

#include "dsmi_common.h"
#include "dev_mon_cmd_def.h"
#include "dsmi_dmp_command.h"
#include "dev_mon_iam_type.h"
#include "dev_mon_cmd.h"
#include "dsmi_inner_interface.h"
#include "dsmi_common_interface_custom.h"

#define __stringify_1(x...) #x
#define __stringify(x...)   __stringify_1(x)
#define CMD_LENGTH_INVALID      0XFFFF

#define COMMON_ERR      (-1)
#define NDIE_TYPE       4
#define NDIE_ID_OFFSET  16
#define COMPUTING_POWER_AICORE_INDEX    1
#undef DEVDRV_MAX_DAVINCI_NUM
#define DEVDRV_MAX_DAVINCI_NUM  64

// A5 标卡
#define DEV_950_1P_MAINBOARD_ID            0x68
#define DEV_950_2P_MAINBOARD_ID            0x6A
#define DEV_950_4P_MAINBOARD_ID            0x6C
#define DEV_UBOE_CARD_950_MAIN_BOARD_ID    0xD2

// A5 pod
#define DEV_950_pod_2D_MAINBOARD_ID          0x03
#define DEV_950_pod_2D_BackUp_MAINBOARD_ID   0x05
#define DEV_950_pod_1D_MAINBOARD_ID          0x07
#define DEV_950_pod_PCIE_MAINBOARD_ID        0xC0
#define DEV_950_pod_UBoE_MAINBOARD_ID        0xC2

// A5 server
#define DEV_950_Server_A_K_2_4_MAINBOARD_ID        0x21
#define DEV_950_Server_A_K_2_4_UBoE_MAINBOARD_ID   0x23
#define DEV_950_Server_A_K_2_6_MAINBOARD_ID        0x25
#define DEV_950_Server_A_K_2_6_UBoE_MAINBOARD_ID   0x27
#define DEV_950_Server_A_X_2_4_MAINBOARD_ID        0x40
#define DEV_950_Server_A_X_2_4_UBoE_MAINBOARD_ID   0x42
#define DEV_950_Server_A_X_PCIE_MAINBOARD_ID       0xC4
#define DEV_950_Server_A_X_UBoE_MAINBOARD_ID       0xC6

// A5 UBX
#define DEV_950_UBX_PCIE_MAINBOARD_ID    0x44
#define DEV_950_UBX_UBoE_MAINBOARD_ID    0xD4

#define BOARD_TYPE_EP            0
#define DEV_TYPE_MAX_LEN         8
#define DEV_PATH_MAX_LEN         64
#define SOFT_LINK_TYPE           10
#define PCI_DEVICE_BASE_PATH     "/sys/bus/pci/devices"
#define DEV_HISI_HDC_PATH        "/dev/hisi_hdc"
#define DEV_DAVINCI_MANAGER_PATH "/dev/davinci_manager"
#define DEV_DEVMMM_SVM_PATH      "/dev/devmm_svm"
#define DEV_SVM0_PATH            "/dev/svm0"

#define DSMI_MAX_VDEV_NUM 16 /**< max number a device can spilts */
#define DSMI_MAX_SPEC_RESERVE 8

#ifdef CFG_SOC_PLATFORM_CLOUD
#define HCCS_ON  1
#define HCCS_OFF 0
#endif

#ifdef CFG_FEATURE_HBM_MANUFACTURER_ID
#define CHECK_ONE_BYTE_BIT        8
#define CHECK_TWO_BYTE_BIT        (2 * CHECK_ONE_BYTE_BIT)
#define CHECK_THREE_BYTE_BIT      (3 * CHECK_ONE_BYTE_BIT)
#endif

#define DSMI_CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX        8192
#define DSMI_CUSTOM_OP_SECVERIFY_CERT_SHOW_INFO_SIZE_MAX    720

struct dsmi_vdev_spec_info {
    unsigned char core_num; /**< aicore num for virtual device */
    unsigned char reservesd[DSMI_MAX_SPEC_RESERVE]; /**< reserved */
};

struct dsmi_sub_vdev_info {
    unsigned int status;       /**< whether the vdevice used by container */
    unsigned int vdevid;       /**< id number of vdevice */
    unsigned int vfid;
    unsigned long long cid;    /**< container id */
    struct dsmi_vdev_spec_info spec; /**< specification of vdevice */
};

// 带宽单位是MB/S，对齐A2A3版本的实现，舍弃小数
struct ub_bandwidth_t {
    unsigned int tx_bandwidth;
    unsigned int rx_bandwidth;
};

struct dsmi_vdev_info {
    unsigned int vdev_num;         /**< number of vdevice the devid had created */
    struct dsmi_vdev_spec_info spec_unused;  /**< resource the devid unallocated */
    struct dsmi_sub_vdev_info vdev[DSMI_MAX_VDEV_NUM];
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

#define VL_NUM_PER_PORT        16

struct dsmi_credit_info {
    unsigned short port_id;
    unsigned short resv;
    unsigned int link_alloc_port_share_credit;
    unsigned int link_cur_used_port_share_credit;
    unsigned int link_alloc_vl_pri_credit[VL_NUM_PER_PORT];
    unsigned int link_cur_used_pri_credit[VL_NUM_PER_PORT];
};

#define NETDEV_MAX_NUM        8
#define NETDEV_NAME_MAX_LEN   16

struct dsmi_netdev_list_info {
    int netdev_nums;
    char netdev_name[NETDEV_MAX_NUM][NETDEV_NAME_MAX_LEN];
};

#define IP_MAX_LEN                  48
#define TRACEROUTE_RESERVE_MAX_LEN  64

struct dsmi_traceroute_param {
    int max_ttl;
    int tos;
    int waittime;
    int source_port;
    int dest_port;
    char src_ip[IP_MAX_LEN];
    char dst_ip[IP_MAX_LEN];
    bool reset_flag;
};
 
struct traceroute_result {
    int mask;
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

#define DSMI_MAC_ADDR_LEN        6
#define DSMI_MAC_STR_LEN         17

struct dsmi_mac_val {
    unsigned char mac_pieces[DSMI_MAC_ADDR_LEN];
};

#define DSMI_MAC_ADDR_ARGS(mac) \
    (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]


#define MAX_PRI_NUM 8

struct dcmi_bond_pfc_duration_info {
    unsigned char slave0_name[NETDEV_NAME_MAX_LEN];
    unsigned long long slave0_tx[MAX_PRI_NUM];
    unsigned long long slave0_rx[MAX_PRI_NUM];
    unsigned char slave1_name[NETDEV_NAME_MAX_LEN];
    unsigned long long slave1_tx[MAX_PRI_NUM];
    unsigned long long slave1_rx[MAX_PRI_NUM];
};

#ifndef CFG_FEATURE_UB_INFO
#define MAX_IP_VAL_LEN              48
#define UB_PING_RESERVE_NUM        4

struct ubping_pair_info {
    char src_addr[MAX_IP_VAL_LEN];
    char dst_addr[MAX_IP_VAL_LEN];
};

struct dcmi_ub_ping_operate {
    struct ubping_pair_info ub_pair_info;  // 源/目的eid对
    int pkt_size;             // ping报文大小，取值范围：0~4046，默认值为4046，注这里需要看ip over urma的mtu值是多少
    int pkt_send_num;            // ping报文发送轮数, 默认为3轮；
    int pkt_interval;            // ping报文间隔，多久发送一次，默认值为1S；
    int timeout;             // ping超时时间，发送失败了后直接停止；
    unsigned int reserve[UB_PING_RESERVE_NUM];                // 预留字段
};

struct ub_ping_result {
    unsigned int suc_pkt_num;    // ping成功次数
    unsigned int fail_pkt_num;    // ping失败次数
    long max_time;                // ping最大时延
    long min_time;                // ping最小时延
    long avg_time;                // ping平均时延
    long tp95_time;               // ping时延TP95分位数
    unsigned int reserve[UB_PING_RESERVE_NUM];                 // 预留字段
};
#endif

#ifdef CONFIG_LLT
static inline void printf_stub(char *format, ...) {
}
#define DEV_MON_ERR          printf_stub
#define DEV_MON_WARNING      printf_stub
#define DEV_MON_INFO         printf_stub
#define DEV_MON_DEBUG        printf_stub
#define DEV_MON_EVENT        printf_stub
#define DEV_MON_PRINT        printf_stub
#endif

#if !defined CFG_SOC_PLATFORM_CLOUD && !defined CFG_FEATURE_ECC_DDR && !defined CFG_SOC_PLATFORM_CLOUD_V4
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_GET_CHIP_PCIE_ERR_RATE, 0, sizeof(PCIE_ERR_RATE_INFO_STU), STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_CLEAR_CHIP_PCIE_ERR_RATE, 0, 0, STATE_MANAGE_TYPE)
#else
#if defined CFG_FEATURE_ECC_DDR
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_GET_CHIP_PCIE_ERR_RATE, 0, sizeof(PCIE_ERR_RATE_INFO_STU), STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_CLEAR_CHIP_PCIE_ERR_RATE, 0, 0, STATE_MANAGE_TYPE)
#endif
DSMI_CMD_DEF_DAVINCI_INSTANCE(
    DEV_MON_CMD_GET_MULTI_ECC_TIME_INFO, 0, sizeof(struct dsmi_multi_ecc_time_data), STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(
    DEV_MON_CMD_GET_ECC_RECORD_INFO, sizeof(unsigned int) + sizeof(unsigned char) + sizeof(unsigned char),
    sizeof(struct dsmi_ecc_common_data), STATE_MANAGE_TYPE)
#endif
#ifdef CFG_ATTEST_EVIDENCE
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_ATTEST_EVIDENCE, CMD_LENGTH_INVALID,
    sizeof(ATTEST_OPERATE_RESPONSE), UNDEFINED_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_AKCERT, 0, BUF_MAX_LEN_HDC, UNDEFINED_TYPE)
#endif
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_SET_USER_CONFIG_PRODUCT, CMD_LENGTH_INVALID, 0, STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_GET_USER_CONFIG_PRODUCT, CMD_LENGTH_INVALID, 0, STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_CLEAR_USER_CONFIG_PRODUCT, CMD_LENGTH_INVALID, 0, STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_MEM_INFO, 0, sizeof(struct dsmi_get_memory_info_stru),
    STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_GET_CUSTOM_OP_SECVERIFY_CERT, CMD_LENGTH_INVALID,
                              CMD_LENGTH_INVALID, STATE_MANAGE_TYPE)
#ifdef CFG_FEATURE_HBM_MANUFACTURER_ID
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_HBM_MANUFACTURER_ID, 0, sizeof(unsigned int), STATE_MANAGE_TYPE)
#endif
#ifdef CFG_FEATURE_ROOTKEY_STATUS
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_ROOTKEY_STATUS, 0, sizeof(unsigned int), STATE_MANAGE_TYPE)
#endif
#if defined(CFG_FEATURE_SERDES_INFO) || defined(CFG_FEATURE_SERDES_INFO_A5)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_GET_SERDES_INFO, CMD_LENGTH_INVALID, CMD_LENGTH_INVALID, STATE_MANAGE_TYPE)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MON_CMD_D_SET_SERDES_INFO, CMD_LENGTH_INVALID, CMD_LENGTH_INVALID, CONFIG_MANAGE_TYPE)
#endif
#if defined(CFG_FEATURE_INIT_MCU_BOARD_ID)
DSMI_CMD_DEF_DAVINCI_INSTANCE(DEV_MOV_CMD_GET_MCU_BOARD_ID, 0, sizeof(unsigned int), STATE_MANAGE_TYPE)
#endif
#endif
