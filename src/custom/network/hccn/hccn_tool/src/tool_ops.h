/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_TOOL_OPS_H
#define HCCN_TOOL_OPS_H

#include <stddef.h>
#include <tool_ext.h>
#define XSFP_IDENTIFIER_LEN     20
#define VENDOR_OUI_FIR     0
#define VENDOR_OUI_MID     1
#define VENDOR_OUI_END     2
#define CHANNEL_0_H        0
#define CHANNEL_0_L        1
#define CHANNEL_1_H        2
#define CHANNEL_1_L        3
#define CHANNEL_2_H        4
#define CHANNEL_2_L        5
#define CHANNEL_3_H        6
#define CHANNEL_3_L        7

#define TEMP_INVALID       0x7EFF
#define TEMP_FAULT         0x7FFF

#define MAX_IP_LEN         20
#define MAX_IPV6_LEN       48
#define MAX_PORT_COUNT     2u
#define LLDP_SET_MAC       0
#define LLDP_SET_INTF      1

#define RECOVER_RETRY_TIMES     3

struct xsfp_id_map {
    int id;
    char id_str[XSFP_IDENTIFIER_LEN];
};

#define OPTICAL_LOOPBACK_MODE_MIN 0
#define OPTICAL_LOOPBACK_MODE_MAX 4
#define OPTICAL_LOOPBACK_RETRY    10
#define OPTICAL_LOOPBACK_RUNNING  4
#define OPTICAL_LOOPBACK_OPT_FAIL_DUE_TO_DOWNGRADE  16
#define OPTICAL_LOOPBACK_UNSUPPORT 0xFF

#define OPTICAL_SET_MODE_UNSUPPORT 0xFF
#define OPTICAL_NOT_INIT           8
#define OPTICAL_I2C_BUSY           3
#define OPTICAL_ABSENT             11

#define BOARD_ID_MASK           0x7
#define PCIE_BOARD_ID           0x1
#define PCIE_BOARD_ID_EXTEND    0x2
#define A_K_OR_POD_BOARD_ID     0x3 // 特别的，A+K与POD共用一种BOARD ID，需要用main board id区分
#define A_K_BOARD_ID_EXTEND     0x4
#define A_K_MAIN_BOARD_ID       0b0011
#define A_X_BOARD_ID            0x5
#define A_X_BOARD_ID_EXTEND     0x6
#define POD_BUSINESS_MAIN_BOARD 4
#define CFG_RECOVERY_FAIL       1
#define CFG_RECOVERY_SUCCESS    0
#define IP_TYPE_SIZE            5

#define ESD_MAX_DISPLAY_LANE    8

#define VALID_ASCII_LOW  32
#define VALID_ASCII_HIGH 127

typedef struct recovery_cmd {
    const char* recovery_cmd_value;
    int (*recovery_cmd_execute)(struct tool_param *param);
} recovery_cmd_t;

struct tool_ip_character {
    char address[MAX_IP_LEN];
    char netmask[MAX_IP_LEN];
};

recovery_cmd_t *get_recovery_ipv4_cmd_list(int *size);
recovery_cmd_t *get_recovery_ipv6_cmd_list(int *size);
recovery_cmd_t *get_recovery_com_cmd_list(int *size);
recovery_cmd_t *get_recovery_cooperative_cmd_list(int *size);

int tool_para_overflow_check(const char *str, unsigned int max_val, int err_ret);
int tool_inet_pton_ipv4_address(const char *str, unsigned int *ip);
int is_ipaddr_conflict(int logic_id, const char *address, const char *netmask);
int check_str_is_num(char *str, size_t len);
int tool_mac_str2char(const char mac_str[], unsigned char mac_pieces[], int num);
int tool_cfg_shaping_recovery(struct tool_param *param);
int tool_set_roce_port(int logic_id, int phy_id, int argc, char **argv, struct tool_param *param);
int tool_get_netdetect(int argc, char **argv, const struct tool_param *param);
int tool_set_netdetect(int argc, char **argv, const struct tool_param *param);
int tool_is_pcie_card(int logic_id, bool *pcie_card);
int tool_cfg_ip_ipv6_recovery(struct tool_param *param);
int tool_cfg_netdetect_ipv6_recovery(struct tool_param *param);
int tool_cfg_route_ipv6_recovery(struct tool_param *param);
int tool_gateway_is_get_cmd_execute(struct tool_param *param, int *port, unsigned int *gw_addr, char *gw_str,
    unsigned int *default_phy_id);
int tool_is_pcie_card(int logic_id, bool *pcie_card);
int tool_inner_gateway_set_execute(int argc, char **argv, struct tool_param *param, bool is_gateway_on_eth);
int tool_ipv4_int_to_str(const unsigned int ip, char *str, int len);
int tool_cfg_gateway_recovery_ipv6(struct tool_param *param);
int tool_set_optical_loopback(int argc, char **argv, struct tool_param *param);
int tool_option_mode_check(int logic_id, hccn_cmd_mode option_mode, unsigned int *port_type);
int tool_cfg_ip_recovery_bond(struct tool_param *param);
int tool_get_device_ipaddr(struct tool_param *param);
int tool_ip_set_address(struct tool_param *param, const char *address, const char *netmask);
int tool_check_mtu(const char *mtu_str, unsigned int *mtu_size, unsigned int mac_type);
int tool_cfg_tls_enable_recovery(struct tool_param *param);
int tool_cfg_tls_ca_recovery(struct tool_param *param);
int tool_get_npu_serders_snr(struct tool_param *param);

int tool_cfg_ip_udhcpc_recovery(struct tool_param *param);
int tool_cfg_ip_ipv6_udhcpc_recovery(struct tool_param *param);
int tool_get_ipaddr_from_device(struct tool_param *param, char *ip_addr, char *netmask_addr, int ipv4_len);
int tool_check_route_net_segment(struct tool_param *param, const char *address, const char *netmask);
int tool_set_ipaddr_recovery(struct tool_param *param, const char *address, const char *netmask,
    char *gateway, unsigned int gateway_len);
int tool_dump_optical_info(int argc, char **argv, struct tool_param *param);
int tool_set_optical_mode(int argc, char **argv, struct tool_param *param);
char is_empty_ascii(unsigned char c);
void tool_show_vendor_rev(struct ds_optical_info *info);
void tool_show_optical_specification_compliance(struct ds_optical_info *info);
void tool_show_additional_optical_snr_info(struct ds_optical_info *info, const int sflag);
void tool_show_additional_optical_physical_code_info(struct ds_optical_info *info);
int recovery_process_cfg_cmd(struct tool_param *param);
int tool_cfg_roce_port_recovery(struct tool_param *param);
int tool_cfg_udp_port_mode_recovery(struct tool_param *param);
int tool_set_roce_ports_info(int logic_id, int phy_id, int argc, char **argv);
int tool_roce_ports_clear_conf(int phy_id);
int tool_dump_optical_info_ret_convert(int result);
#endif

