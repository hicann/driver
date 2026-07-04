/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DS_DATA_H
#define DS_DATA_H

#include <sys/types.h>
#include <stdbool.h>

#ifndef CONFIG_LLT
#define STATIC static
#else
#define STATIC
#endif

#define HCCN_BIT(shift) (1U << (shift))
#define CHECK_HCCN_BIT(mask, hccn_bit) (((mask) & (hccn_bit)) != 0)
#define MIN(a, b)   (((a) > (b)) ? (b) : (a))
#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
#define ARRAY_SIZE_COMPUTE(_array) (sizeof((_array)) / sizeof((_array)[0]))

#define L1_CMD_MASK         0xF000

#define INVALID_VAL (-1)

#define PERCENTAGE_BASE 100
#define STR_NUM_BASE_10 10

// ------------------ 设备参数 bitmask ---------------
#define DEV_I               HCCN_BIT(0)
#define DEV_U               HCCN_BIT(1)
#define DEV_P               HCCN_BIT(2)
#define DEV_D               HCCN_BIT(3)
#define DEV_OPTICAL         HCCN_BIT(4)
#define DEV_ALL             HCCN_BIT(5)

#define DEV_PORT_TYPE       (DEV_I | DEV_U | DEV_P)
#define DEV_DEV_ATTR        (DEV_I | DEV_D)
#define DEV_NPU_ATTR        (DEV_I)
#define DEV_GLOBAL_ATTR     (DEV_ALL)
#define DEV_OPTICAL_ATTR    (DEV_I | DEV_OPTICAL)
#define DEV_COMBINATION_NUM 5

#define DEV_UDMA_DEV            HCCN_BIT(0)
#define DEV_NET_DEV             HCCN_BIT(1)
#define DEV_BOND_DEV            HCCN_BIT(2)

enum ds_cmd_opcode {
    // shell type
    DS_SHELL_EXE = 0x0000,
    DS_INSPECT_LINK_STATUS = 0x0001,
    DS_GET_PROCESS = 0x0002,
    DS_GET_BIT_ERR = 0x0003,
    DS_GET_RES_ATTR = 0x0004,
    DS_GET_RES_LIST = 0x0005,
    DS_GET_CONTEXT = 0x0006,
    DS_GET_FIRMWARE_VERSION = 0x0007,
    DS_GET_NETDEV_STATUS = 0x0008,
    DS_GET_PORT_INFO = 0x0009,
    DS_GET_ETH_TEST_INFO = 0x000A,
    DS_GET_UB_BANDWIDTH = 0x000B,
    DS_GET_PACKET_STATISTICS = 0x000C,
    DS_CLEAR_PACKET_STATISTICS = 0x000D,
    DS_GET_UBCTL_LS_INFO = 0x000E,
    DS_GET_SPEED_ABILITY = 0x000F,
    DS_GET_LLDP_NEIGHBOR_INFO = 0x0010,
    DS_GET_PEAK_BANDWIDTH = 0x0011,
    DS_GET_BOND_MODE = 0x0012,
    DS_GET_BOND_SLAVES = 0x0013,
    DS_SET_LINK_STATUS = 0x0014,
    DS_GET_MTU_SIZE = 0x0015,
    DS_SET_MTU_SIZE = 0x0016,
    DS_SET_DEFAULT_GATEWAY = 0x0017,
    DS_DEL_DEFAULT_GATEWAY = 0x0018,
    DS_GET_DEFAULT_GATEWAY = 0x0019,
    DS_GET_LOOPBACK_STATE = 0x001A,
    DS_SET_LOOPBACK_STATE = 0x001B,
    DS_GET_ARP_TABLE = 0x001C,
    DS_SET_ARP_TABLE = 0x001D,
    DS_SET_MAC_ADDR = 0x001E,
    DS_GET_BOND_ATTR = 0x001F,
    DS_SET_BOND_ATTR = 0x0020,
    DS_GET_IP = 0x0021,
    DS_SET_IP = 0x0022,
    DS_GET_PFC_CFG = 0x0023,
    DS_SET_PFC_CFG = 0x0024,
    DS_GET_PRIO_TC_INFO = 0x0025,
    DS_SET_PRIO_TC_INFO = 0x0026,
    DS_ACQUIRE_DHCP_IP = 0x0027,
    DS_RELEASE_DHCP_IP = 0x0028,
    DS_FIND_UDHCPC_PID = 0x0029,
    DS_GET_UDHCPC_PID = 0x002A,
    DS_START_UDHCPC_PROC = 0x002B,
    DS_START_TROUTE = 0x002C,
    DS_RESET_TROUTE = 0x002D,
    DS_GET_DSCP_MAP_INFO = 0x002E,
    DS_GET_VL_SL_MAP_INFO = 0x002F,
    DS_UDIS_GET_LINK = 0x0030,
    DS_GET_UDIE_AND_PORT = 0x0031,
    DS_GET_TC_PACKET_INFO = 0x0032,
    DS_ENABLE_TC_STAT = 0x0033,
    DS_CLEAR_TC_STAT = 0x0034,
    // tcp/ip type
    DS_LINUX_TCP_IP_EXE = 0x1000,
    DS_GET_VNIC_STATUS = 0x1001,
    DS_GET_PING_INFO = 0x1002,
    DS_GET_TLS_CFG = 0x1003,
    DS_SET_TLS_CFG = 0x1004,
    DS_GET_ENVELOPE_PUB = 0x1005,
    DS_SET_TLS_ALARM = 0x1006,
    DS_SET_TLS_ENABLE = 0x1007,
    DS_CLEAR_TLS_CFG = 0x1008,
    DS_GET_ALL_NETDEV_INFO = 0x1009,
    DS_GET_MAC_ADDR = 0x100A,
    DS_CLEAR_LOOPBACK_STATE = 0x100B,
    DS_GET_NET_DETECT = 0x100C,
    DS_SET_NET_DETECT = 0x100D,
    DS_GET_TRACEROUTE_STATUS = 0x100E,
    DS_GET_TRACEROUTE_INFO = 0x100F,
    DS_START_TRACEROUTE = 0x1010,
    DS_RESET_TRACEROUTE = 0x1011,
    DS_GET_INTERFACE_STATUS = 0x1012,
    DS_GET_TC_PACKET_STATISTICS = 0x1013,
    DS_SET_TC_PACKET_STATISTICS = 0x1014,
    // optical type
    DS_OPTICAL_EXE = 0x2000,
    // UBASE type
    DS_UBASE_EXE = 0x3000,
    DS_GET_CREDIT_INFO = 0x3001,
    DS_UPGRADE_LANE = 0x3002,
    DS_GET_CUR_TC_BUF = 0x3003,
    DS_GET_TC_CFG_INFO = 0x3004,
    DS_SET_TC_CFG_INFO = 0x3005,
    DS_GET_UBOE_BANDWIDTH = 0x3006,
    DS_GET_TM_SHAPING_PORT = 0x3007,
    DS_GET_QOS_DSCP_INFO = 0x3008,
    DS_SET_QOS_DSCP_INFO = 0x3009,
    // URMA type
    DS_URMA_EXE = 0x4000,
    DS_GET_ALL_UDEV_INFO = 0x4001,
    // cfg type
    DS_CFG_EXE = 0x5000,
    DS_SET_CFG_STATUS = 0x5001,
    DS_GET_CFG_STATUS = 0x5002,
    // product_type
    DS_PRODUCT_EXE = 0x8000,
};

enum ds_data_frag {
    DS_ONE_PKT,
    DS_FIRST_PKT,
    DS_MIDDLE_PKT,
    DS_LAST_PKT,
};

enum ds_send_recv_op {
    DS_SEND_OP,
    DS_RECV_OP,
};

struct ds_common_req_head {
    int logic_id;
    int port_id;
    enum ds_cmd_opcode cmd;
    enum ds_data_frag data_frag;
    enum ds_send_recv_op send_recv_op;
    unsigned int send_data_len;
    unsigned int recv_data_len;
    unsigned int one_piece_len;
    pid_t host_tid;
    pid_t pid;
    int rsvd;
};

#define MAX_CMD_PAYLOAD_LEN 2000
#define MAX_TRANS_DATA_LEN 386000

struct ds_common_req_param {
    struct ds_common_req_head req_head;
    char info[MAX_CMD_PAYLOAD_LEN];
};

struct ds_common_rsp_head {
    int logic_id;
    int result;
    enum ds_cmd_opcode cmd;
    enum ds_data_frag data_frag;
    unsigned int one_piece_len;
    pid_t pid;
    int rsvd;
};

struct ds_common_rsp_param {
    struct ds_common_rsp_head rsp_head;
    char info[MAX_CMD_PAYLOAD_LEN];
};

// ------------------ 顶层 context ------------------
#define MAX_DEV_NAME_LEN 64
struct command_context {
    unsigned int mode;
    int dev_id;                         // phy_id
    int slot_id;
    int udie_id;                        // -u
    int port_id;                        // -p
    int optical_id;                     // -optical_id
    char dev_name[MAX_DEV_NAME_LEN];    // -d
    bool global_flag;                   // -all or -global
    void *cmd_args;                     // 子命令专用结构体
    struct cmd_entry *match_cmd;        // 匹配上的命令字
    unsigned int sub_opt_mask;          // cmd sub option seen mask
    char *result;
    unsigned int dev_mask;              // 实际使用的目标模式

    struct env_info_struct {
        char usr_name[128];     // 用户名，用来校验用户操作权限
        char usr_ip[128];       // 用户ip信息，用来记录命令操作时用户的ip信息
        char env_flag;          // 物理、虚机、容器
        unsigned int pid;       // 通过pid锁定用户操作命令最后执行的结果
    } env_info;

    struct npu_info_struct {    // 单板信息
        int logic_id;                   // -i
        unsigned int mainboard_id;      // A+X/A+K
        unsigned int board_id;
    } npu_info;

    int help_level;
};

#endif // DS_DATA_H
