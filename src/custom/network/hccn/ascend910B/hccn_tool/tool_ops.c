/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <limits.h>
#include "dsmi_common_interface.h"
#include "tool.h"
#include "tool_recovery.h"
#include "tool_ext.h"
#include "cmd.h"
#include "cfg.h"
#include "log.h"
#include "ds_net_ext.h"
#include "tool_ops_ip.h"
#include "tool_ops.h"

static char *g_mac_filter_list[] = {
    "09:00:2B:00:00:04", "09:00:2B:00:00:05", "03:00:00:00:00:08",
    "03:00:00:00:00:10", "03:00:00:00:00:40", "03:00:00:00:01:00",
    "03:00:00:00:02:00", "03:00:00:00:04:00", "03:00:00:00:08:00",
    "03:00:00:00:10:00", "03:00:00:00:20:00", "03:00:00:00:40:00",
    "03:00:00:40:00:00", "00:00:00:00:00:00", "FF:FF:FF:FF:FF:FF",
    "ff:ff:ff:ff:ff:ff", "09:00:2b:00:00:04", "09:00:2b:00:00:05"
};

static struct net_health_status_map g_net_health_status[] = {
    { 0x0, "Success" },
    { 0x1, "Socket fail" },
    { 0x2, "Receive timeout" },
    { 0x3, "Unreachable" },
    { 0x4, "Time exceeded" },
    { 0x5, "Fault" },
    { 0x6, "Init" },
    { 0x7, "Thread error" },
    { 0x8, "Detect ip set" },
    { 0x9, "Unknown" }
};

int check_str_is_num(char *str, size_t len)
{
    size_t idx;
    for (idx = 0; idx < len; ++idx) {
        if (!isdigit(str[idx])) {
            return -EINVAL;
        }
    }
    return 0;
}

int tool_is_pcie_card(int logic_id, bool *pcie_card)
{
    int ret;
    unsigned int board_id;

    ret = dsmi_get_board_id(logic_id, &board_id);
    if (ret) {
        roce_err("get board id fail! ret=%d logic_id is [%d]", ret, logic_id);
        return ret;
    }

    if (tool_is_910_a3(logic_id)) {
        *pcie_card = false;
        return ret;
    }
    /* first four bits of board_id value are not used */
    board_id = board_id & 0xFFF0;
    if (((board_id & BOARDID_PCIE_CARD_MASK) == BOARDID_PCIE_CARD_MASK_VALUE) &&
        (board_id != BOARDID_AI_SERVER_MODULE) && (board_id != BOARDID_ARM_SERVER_AG)) {
        *pcie_card = true;
    } else {
        *pcie_card = false;
    }
    return ret;
}

int tool_para_overflow_check(const char *str, unsigned int max_val, int err_ret)
{
    int index = 0;
    long long res = 0;

    while ((index < TOOL_PARA_BITSWIDTH) && str[index] != '\0') {
        res = res * TOOL_PARA_BASE + (str[index] - '0');
        if (res > max_val) {
            roce_err("Input str val is out of range.");
            return err_ret;
        }
        index++;
    }

    return 0;
}

int tool_inet_pton_ipv4_address(const char *str, unsigned int *ip)
{
    struct in_addr addr;
    int ret;

    if (str == NULL || ip == NULL) {
        roce_err("Input param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    ret = inet_pton(AF_INET, str, &addr);
    if (ret <= 0) {
        roce_err("Invalid IPv4 address. (ret=%d; errno=%d)", ret, errno);
        return UDA_PARAM_IP_INVALID_ERR;
    }

    *ip = addr.s_addr;
    return 0;
}

int tool_ipv4_int_to_str(const unsigned int ip, char *str, int len)
{
    int ret;

    if (str == NULL) {
        roce_err("Input param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }
    unsigned int gw_fst = SPLIT_UIP(ip, IP_SPLIT_BIT_0);
    unsigned int gw_sed = SPLIT_UIP(ip, IP_SPLIT_BIT_8);
    unsigned int gw_thd = SPLIT_UIP(ip, IP_SPLIT_BIT_16);
    unsigned int gw_fth = SPLIT_UIP(ip, IP_SPLIT_BIT_24);

    ret = sprintf_s(str, len, "%u.%u.%u.%u", gw_fst, gw_sed, gw_thd, gw_fth);
    if (ret <= 0) {
        roce_err("sprintf fail %u.%u.%u.%u!, ret:%d", gw_fst, gw_sed, gw_thd, gw_fth, ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    return 0;
}

STATIC int tool_check_ip_net_segment(const char *sip, const char *dip, const char *netmask)
{
    int ret;
    unsigned int src_ip, dst_ip, mask;

    ret = tool_inet_pton_ipv4_address(sip, &src_ip);
    if (ret == UDA_PARAM_IP_INVALID_ERR) {
        return ret;
    } else if (ret) {
        roce_err("check and inet pton source ip fail, ret[%d]", ret);
        return ret;
    }

    ret = tool_inet_pton_ipv4_address(dip, &dst_ip);
    if (ret == UDA_PARAM_IP_INVALID_ERR) {
        return ret;
    } else if (ret) {
        roce_err("check and inet pton dest ip fail, ret[%d]", ret);
        return ret;
    }

    ret = tool_inet_pton_ipv4_address(netmask, &mask);
    if (ret == UDA_PARAM_IP_INVALID_ERR) {
        return ret;
    } else if (ret) {
        roce_err("check and inet pton netmask fail, ret[%d]", ret);
        return ret;
    }

    roce_info("check net segment! src_ip[0x%x] dst_ip[0x%x] mask[0x%x]", src_ip, dst_ip, mask);
    if ((src_ip & mask) != (dst_ip & mask)) {
        roce_err("src_ip[0x%x] and dst_ip[0x%x] are not the same net segment!", src_ip, dst_ip);
        return UDA_PARAM_DIFF_SEGMT_GTWY_ERR;
    } else {
        return 0;
    }
}

STATIC int tool_ip_get_ipaddr(int argc, char *argv[], char *address, char *netmask, int length)
{
    int i, ret, j = 0;
    char *msg = NULL;

    for (i = 1; i < argc && j < argc; i = i + ARGC_ID_2) {
        j = i + 1;
        msg = (char *)(argv[j]);
        if (!strncmp(argv[i], "address", strlen("address") + 1)) {
            ret = memcpy_s(address, length, msg, strlen(msg) + 1);
            if (ret) {
                roce_err("memcpy_s address fail[%d], dlen[%d], slen[%u]", ret, length, strlen(msg) + 1);
                return UDA_TOOL_NO_MEM_ERR;
            }
        } else if (!strncmp(argv[i], "netmask", strlen("netmask") + 1)) {
            ret = memcpy_s(netmask, length, msg, strlen(msg) + 1);
            if (ret) {
                roce_err("memcpy_s netmask fail[%d], dlen[%d], slen[%u]", ret, length, strlen(msg) + 1);
                return UDA_TOOL_NO_MEM_ERR;
            }
        } else {
            roce_err("Err input cmd.");
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    }

    return 0;
}

static int tool_check_net_segment_config(struct tool_param *param, const char *address, const char *netmask)
{
    int ret;

    ret = tool_check_route_net_segment(param, address, netmask);
    if (ret) {
        roce_err("tool_check_route_net_segment: route not in the same net segment del failed! ret is %d", ret);
        return ret;
    }

    ret = tool_check_ip_route_net_segment(param, address, netmask);
    if (ret) {
        roce_err("tool_check_ip_route_net_segment: ip route not in the same net segment del failed! ret is %d", ret);
        return ret;
    }

    return ret;
}

static int tool_prepare_device_ip_address(ip_addr_t *ip_address, ip_addr_t *ip_mask_address, unsigned int address_ip,
    unsigned int netmask_ip)
{
    int ret;

    ip_address->ip_type = IPADDR_TYPE_V4;
    ip_mask_address->ip_type = IPADDR_TYPE_V4;
    ret = memcpy_s(ip_address->u_addr.ip4, sizeof(ip_address->u_addr.ip4), &address_ip, sizeof(unsigned int));
    if (ret) {
        roce_err("memcpy_s ipv4 address fail[%d], dlen[%d], slen[%u]", ret, sizeof(ip_address->u_addr.ip4),
                 sizeof(unsigned int));
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = memcpy_s(ip_mask_address->u_addr.ip4, sizeof(ip_mask_address->u_addr.ip4), &netmask_ip, sizeof(unsigned int));
    if (ret) {
        roce_err("memcpy_s ipv4 mask fail[%d], dlen[%d], slen[%u]", ret, sizeof(ip_mask_address->u_addr.ip4),
                 sizeof(unsigned int));
        return UDA_TOOL_NO_MEM_ERR;
    }

    return ret;
}

int tool_ip_set_address(struct tool_param *param, const char *address, const char *netmask)
{
    int ret;
    ip_addr_t ip_address, ip_mask_address;
    int port_type = DSMI_ROCE_PORT;
    unsigned int address_ip = 0, netmask_ip = 0;

    ret = is_ipaddr_conflict(param->logic_id, address, netmask);
    if (ret == UDA_PARAM_CONFLICT_IP_ADDR_ERR) {
        roce_err("Ipaddr conflict.");
        return ret;
    } else if ((ret != 0) && (ret != UDA_DSMI_IPCONF_NOT_PRESET_ERR)) {
        roce_err("Ipaddr conflict failed.");
        return ret;
    }

    ret = tool_transfer_check_ipaddr((char *)address, &address_ip);
    if (ret) {
        roce_err("Tool set device ipaddr is invalid.");
        return ret;
    }
    ret = tool_transfer_check_netmask((char *)netmask, &netmask_ip);
    if (ret) {
        roce_err("Tool set device netmask is invalid.");
        return ret;
    }

    ret = tool_check_net_segment_config(param, address, netmask);
    if (ret != 0) {
        roce_err("Tool check net segment config failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_prepare_device_ip_address(&ip_address, &ip_mask_address, address_ip, netmask_ip);
    if (ret) {
        roce_err("Tool prepare device ip address failed. (ret=%d)", ret);
    }

    if (param->option_mode == UDA_OPT_BOND_CMD) {
        port_type = DSMI_BOND_PORT;
    } else if (param->option_mode == UDA_OPT_EMPTY_CMD) {
        port_type = DSMI_ROCE_PORT;
    }

    ret = dsmi_set_device_ip_address(param->logic_id, port_type, 0, ip_address, ip_mask_address);
    if (ret) {
        roce_err("dsmi set ip fail! ret[%d] logic_id[%d] address_ip[0x%x] netmask_ip[0x%x]",
                 ret, param->logic_id, address_ip, netmask_ip);
        return UDA_DSMI_EXE_ERR;
    }

    return 0;
}

STATIC int tool_ip_get_gateway(int argc, char *argv[], char *gateway)
{
    int i, ret, j = 0;
    char *msg = NULL;

    for (i = 1; i < argc && j < argc; i = i + ARGC_ID_2) {
        j = i + 1;
        msg = (char *)(argv[j]);
        if (!strncmp(argv[i], "gateway", strlen("gateway") + 1)) {
            ret = memcpy_s(gateway, MAX_IP_LEN, msg, strlen(msg) + 1);
            if (ret) {
                roce_err("memcpy_s gateway fail[%d], dlen[%d], slen[%u]", ret, MAX_IP_LEN, strlen(msg) + 1);
                return UDA_TOOL_NO_MEM_ERR;
            }
        } else {
            roce_err("Err input cmd.");
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    }

    return 0;
}

STATIC int tool_ip_read_gateway_conf(int logic_id, int phy_id, bool is_pcie_card,
                                     unsigned int *gateway, int *gateway_phy_id)
{
    int ret, max, min, loop;
    unsigned int gw_ip = 0;
    char gw[MAX_IP_LEN] = "";
    struct dev_list_info list_info = {0};

    min = (phy_id >= TOOL_DEVICE_CHIP_ID_MAX) ? TOOL_DEVICE_CHIP_ID_MAX : 0;
    max = (phy_id >= TOOL_DEVICE_CHIP_ID_MAX) ? TOOL_HOST_LOGIC_ID_MAX : TOOL_DEVICE_CHIP_ID_MAX;

    ret = tool_get_dev_list_info(&list_info);
    if (ret) {
        roce_err("tool_get_dev_list_info fail! ret=%d", ret);
        return ret;
    }

    for (loop = 0; loop < list_info.dev_num; loop++) {
        if (is_pcie_card) {
            if (logic_id != list_info.logic_list[loop]) {
                continue;
            }
        } else {
            if ((list_info.phy_list[loop] < min) || (list_info.phy_list[loop] >= max)) {
                continue;
            }
        }
        ret = cfg_read_conf(list_info.phy_list[loop], "gateway", gw, sizeof(gw));
        if (ret) {
            if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
                continue;
            }
            roce_err("cfg_read_conf fail! phy_id[%d] ret[%d] len[%d]", list_info.phy_list[loop], ret, sizeof(gw));
            return ret;
        }

        ret = tool_inet_pton_ipv4_address(gw, &gw_ip);
        if (ret) {
            roce_err("Tool inet pton ipv4 address fail. (ret=%d; logic_id=%d; gw_ip=0x%x)",
                     ret, list_info.logic_list[loop], gw_ip);
            return ret;
        }

        // found entry
        *gateway_phy_id = list_info.phy_list[loop];
        *gateway = gw_ip;
        return 0;
    }

    return UDA_TOOL_SYS_RD_FILE_NOT_FOUND;
}

STATIC int tool_ip_get_gateway_conf(int logic_id, int phy_id, unsigned int *gateway, int *gateway_phy_id)
{
    int ret;
    bool is_pcie_card = false;

    ret = tool_is_pcie_card(logic_id, &is_pcie_card);
    if (ret) {
        roce_err("tool_ip_get_gateway_conf check pcie card failed, ret[%d]", ret);
        return ret;
    }

#ifndef CFG_SOC_PLATFORM_CLOUD_V2
    return tool_ip_read_gateway_conf(logic_id, phy_id, is_pcie_card, gateway, gateway_phy_id);
#else
    // A2/A3 generations can find the corresponding gateway IP through their phy_id.
    return tool_ip_read_gateway_conf_v2(phy_id, is_pcie_card, gateway, gateway_phy_id);
#endif
}

STATIC int tool_ip_sync_handle_cfg_conf(int has_conf, int phy_id, unsigned int *gateway,
    int *port, unsigned int gw_conf)
{
    int ret = 0;

    if (has_conf) {
        /* if hw cfg and conf diff, del old and add hw cfg */
        roce_warn("hw gateway[0x%x] port[%d], diff conf gw[0x%x] phy_id[%d]", *gateway, *port, gw_conf, phy_id);
        ret = cfg_del_conf(phy_id, "gateway");
        if (ret) {
            roce_err("del cfg error! ret[%d] phy_id[%d]", ret, phy_id);
            return ret;
        }
    } else {
        /* hw has something, and conf nothing, LOG ERR and continue */
        roce_err("hw gateway[0x%x] port[%d], conf nothing", *gateway, *port);
    }

    return ret;
}

STATIC int tool_ip_sync_hw_gateway_to_conf(int logic_id, int phy_id, unsigned int *gateway,
    unsigned int *default_gateway_phy_id, bool is_gateway_on_eth)
{
    int ret, port, has_conf = 1, gateway_phy_id = 0;
    unsigned int gw_conf = 0, *tmp_phy_id = default_gateway_phy_id;
    char gw_str[MAX_IP_LEN] = "";
    struct tool_param param = {0};

    *gateway = INVALID_GW;
    *default_gateway_phy_id = INVALID_PORT;

    ret = tool_ip_get_gateway_conf(logic_id, phy_id, &gw_conf, &gateway_phy_id);
    if (ret) {
        roce_warn("tool ip get gateway conf not success %d", ret);
        if (ret != UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
            roce_err("tool get gw conf fail[%d] logic_id[%d]", ret, logic_id);
            return ret;
        }
        has_conf = 0;
    }

    /* first, sync conf and config. then check if need cfg new gateway */
    ret = dsmi_get_default_gateway_address(logic_id, &port, gateway, tmp_phy_id, is_gateway_on_eth);
    /* hardware without default gateway */
    if (ret) {
        /* if conf has gateway, delete it */
        if (has_conf) {
            ret = cfg_del_conf(gateway_phy_id, "gateway");
            if (ret) {
                roce_err("del cfg error! ret[%d] phy_id[%d]", ret, gateway_phy_id);
                return ret;
            }
        }
        /* return ok, because without hw gw entry */
        return 0;
    }

    ret = tool_ipv4_int_to_str(*gateway, gw_str, MAX_IP_LEN);
    if (ret) {
        roce_err("ipv4_int_to_str! ret[%d] gateway[%d]", ret, *gateway);
        return ret;
    }

    if (has_conf && (*default_gateway_phy_id == gateway_phy_id) && (*gateway == gw_conf)) {
        return 0;
    }

    ret = tool_ip_sync_handle_cfg_conf(has_conf, gateway_phy_id, gateway, default_gateway_phy_id, gw_conf);
    if (ret) {
        roce_err("handle cfg and conf fail!, ret[%d]", ret);
        return ret;
    }

    param.phy_id = *default_gateway_phy_id;

    if (!check_udhcpc_write_hccn_conf(&param, 0)) {
        ret = cfg_write_conf(param.phy_id, "gateway", gw_str);
        if (ret) {
            roce_err("write cfg error! ret[%d] phy_id[%d]", ret, *default_gateway_phy_id);
            return ret;
        }
    }

    return ret;
}

STATIC int tool_ip_del_gateway(int phy_id, int port, unsigned int gw_ip, bool is_gateway_on_eth)
{
    int ret;
    unsigned int logic_id;

    ret = dsmi_get_logicid_from_phyid(phy_id, &logic_id);
    if (ret) {
        roce_err("dsmi_get_logicid_from_phyid err! ret[%d], phy_id[%d]", ret, phy_id);
        return ret;
    }

    ret = dsmi_del_default_gateway_address(logic_id, port, gw_ip, is_gateway_on_eth);
    if (ret) {
        roce_err("dsmi del default gw fail! ret[%d] logic_id[%d] ip[0x%x]", ret, logic_id, gw_ip);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = cfg_del_conf(phy_id, "gateway");
    if (ret) {
        roce_err("del cfg error! ret[%d] phy_id[%d]", ret, phy_id);
        return ret;
    }

    return ret;
}

STATIC int tool_ip_set_gateway(int logic_id, const char *gateway, struct tool_param *param, bool is_gateway_on_eth)
{
    int ret;
    unsigned int gateway_ip = 0, gw_ip = 0;
    int default_gateway_phy_id = 0, hw_has_gw = 1;
    struct ds_gateway_addr gw_addr = {0};

    ret = tool_inet_pton_ipv4_address(gateway, &gateway_ip);
    if (ret) {
        roce_err("Tool inet pton ipv4 address fail. (ret=%d; gateway_ip=0x%x)", ret, gateway_ip);
        return ret;
    }

    roce_info("phy_id[0x%x] gateway_ip[0x%x]", param->phy_id, gateway_ip);

    ret = tool_ip_sync_hw_gateway_to_conf(logic_id, param->phy_id, &gw_ip,
                                          (unsigned int *)(void *)&default_gateway_phy_id, is_gateway_on_eth);
    if (ret) {
        roce_err("sync hw gateway to conf fail logic_id[%d] phy_id[%d] ret[%d]", logic_id, param->phy_id, ret);
        return ret;
    }

    if (default_gateway_phy_id == INVALID_PORT && gw_ip == INVALID_GW) {
        hw_has_gw = 0;
    }

    gw_addr.address = gateway_ip;
    gw_addr.is_gateway_on_eth = is_ATLAS_900_A3_SUPERPOD(param->mainboard_id);
    ret = dsmi_set_default_gateway_address(logic_id, 0, gw_addr);
    if (ret) {
        roce_err("dsmi set default gw fail! ret[%d] logic_id[%d] ip[0x%x]", ret, logic_id, gateway_ip);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (hw_has_gw && default_gateway_phy_id == param->phy_id && gw_ip == gateway_ip) {
        roce_info("cfg logic_id[%d] gw[0x%x] exist", logic_id, gateway_ip);
        return 0;
    }

    if (hw_has_gw == 1) {
        ret = tool_ip_del_gateway(default_gateway_phy_id, 0, gw_ip, is_gateway_on_eth);
        if (ret) {
            return ret;
        }
    }

    return ret;
}

int is_dev_ipaddr_conflict(int logic_id, int port_type, int port_id, unsigned int ipaddr, unsigned int mask)
{
    int ret;
    ip_addr_t ip_address, mask_address;
    unsigned int ip_addr;

    ip_address.ip_type = IPADDR_TYPE_V4;
    mask_address.ip_type = IPADDR_TYPE_V4;
    ret = dsmi_get_device_ip_address(logic_id, port_type, port_id, &ip_address, &mask_address);
    if (ret) {
        roce_err("dsmi_get_device_ip_address fail. (ret=%d, logic_id=%d)", ret, logic_id);
        ret = (ret == DRV_ERROR_NO_DEVICE) ? UDA_DSMI_IPCONF_NOT_PRESET_ERR : UDA_DSMI_EXE_ERR;
        return ret;
    }

    ip_addr = *(unsigned int *)(void *)&ip_address.u_addr;
    if (ip_addr == ipaddr) {
        return UDA_PARAM_CONFLICT_IP_ADDR_ERR;
    }

    return 0;
}

static bool is_total_dev_ipaddr_conflict(int logic_id, int device_start, int device_end,
                                         unsigned int ipaddr, unsigned int mask)
{
    int node_id, ret, port_id = 0;
    for (node_id = device_start; node_id < device_end; node_id++) {
        ret = is_dev_ipaddr_conflict(node_id, DSMI_VNIC_PORT, port_id, ipaddr, mask);
        if (ret == UDA_PARAM_CONFLICT_IP_ADDR_ERR) {
            roce_err("IPv4 ipaddr ip conflict.");
            return true;
        }

        if (node_id == logic_id) {
            continue;
        }

        ret = is_dev_ipaddr_conflict(node_id, DSMI_ROCE_PORT, port_id, ipaddr, mask);
        if (ret == UDA_PARAM_CONFLICT_IP_ADDR_ERR) {
            roce_err("IPv4 ipaddr ip conflict.");
            return true;
        }
    }
    return false;
}

int is_ipaddr_conflict(int logic_id, const char *address, const char *netmask)
{
    int ret, end, start = 0;
    unsigned int phy_id;
    const char* vnic_host_addr = "192.168.1.199";
    const char* vnic_host_mask = "255.255.255.0";
    unsigned int ipaddr = inet_addr(address), mask = inet_addr(netmask);
    unsigned int vnic_h_ipaddr = inet_addr(vnic_host_addr), vnic_h_mask = inet_addr(vnic_host_mask);
    bool is_pcie_card = false;

    ret = dsmi_get_device_count(&end);
    if (ret) {
        roce_err("dsmi_get_device_count failed. ret=%d", ret);
        return ret;
    }

    ret = dsmi_get_phyid_from_logicid(logic_id, &phy_id);
    if (ret) {
        roce_err("dsmi_get_phyid_from_logicid failed. ret=%d", ret);
        return ret;
    }

    // 910_a3里，同一个NPU下属的两个DIE不能配置相同的IP
    if (tool_is_910_a3(logic_id)) {
        ret = is_910_a3_ip_conflict(logic_id, address, netmask, 1);
        if (ret == 0 || ret == UDA_DSMI_IPCONF_NOT_PRESET_ERR) {
            goto CHECK_IP;
        }
        return ret;
    }

    if (tool_is_pcie_card(logic_id, &is_pcie_card)) {
        roce_err("tool_is_pcie_card ipv4 is invalid.");
        return ret;
    }

    if (is_pcie_card) {
        ret = is_dev_ipaddr_conflict(logic_id, DSMI_VNIC_PORT, 0, ipaddr, mask);
        if (ret == 0 || ret == UDA_DSMI_IPCONF_NOT_PRESET_ERR) {
            goto CHECK_IP;
        }
        return ret;
    }

    if (phy_id >= TOOL_DEVICE_CHIP_ID_MAX) {
        start = TOOL_DEVICE_CHIP_ID_MAX;
    } else if (end > TOOL_DEVICE_CHIP_ID_MAX) {
        end = TOOL_DEVICE_CHIP_ID_MAX;
    }

    if (is_total_dev_ipaddr_conflict(logic_id, start, end, ipaddr, mask)) {
        return UDA_PARAM_CONFLICT_IP_ADDR_ERR;
    }

CHECK_IP:
    /* check if there has confliction that ip with device vnic's host_ip */
    if ((ipaddr & vnic_h_mask) == (vnic_h_ipaddr & vnic_h_mask)) { // vnic_h_ipaddr/vnic_h_mask网段下的所有子网都不支持
        return UDA_PARAM_CONFLICT_IP_ADDR_ERR;
    }

    return tool_ipaddr_conflict_extend(logic_id, phy_id, ipaddr, mask);
}

STATIC int tool_write_ip_conf(struct tool_param *param, const char *address, const char *netmask)
{
    int ret;

    if (param->option_mode == UDA_OPT_EMPTY_CMD) {
        ret = cfg_write_conf(param->phy_id, "address", address);
        if (ret != 0) {
            roce_err("write address cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
        ret = cfg_write_conf(param->phy_id, "netmask", netmask);
        if (ret != 0) {
            roce_err("Write netmask cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else if (param->option_mode == UDA_OPT_BOND_CMD) {
        ret = cfg_write_conf(param->phy_id, "bond_address", address);
        if (ret != 0) {
            roce_err("Write bond address cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
        ret = cfg_write_conf(param->phy_id, "bond_netmask", netmask);
        if (ret != 0) {
            roce_err("Write bond netmask cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    return 0;
}

int tool_check_route_net_segment(struct tool_param *param, const char *address, const char *netmask)
{
    int ret;
    struct ds_route_table_value ip_param = {0};
    ip_param.address = inet_addr(address);
    ip_param.netmask = inet_addr(netmask);

    ret = tool_read_hccn_conf_handle_action(param, READ_TO_DEL_NOT_SAME_SEGMENT, ip_param);
    if (ret) {
        roce_err("tool_check_route_net_segment: tool_read_hccn_conf_handle_action failed! ret is [%d]", ret);
        return ret;
    }
    return 0;
}

STATIC int tool_cfg_gateway_recovery(struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = "";
    char gateway[MAX_IP_LEN] = "";
    char netmask[MAX_IP_LEN] = "";
    unsigned int gateway_ip = 0;
    struct ds_gateway_addr gw_addr = {0};

    ret = cfg_read_conf(param->phy_id, "udhcpc_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("Udhcpc enable, do not need recover gateway cfg.");
        return 0;
    }

    ret = cfg_read_conf(param->phy_id, "gateway", gateway, sizeof(gateway));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The gateway conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("gateway need recover cfg");
        ret = tool_inet_pton_ipv4_address(gateway, &gateway_ip);
        if (ret) {
            roce_err("Tool inet pton ipv4 address fail. (ret=%d; gateway_ip=0x%x)", ret, gateway_ip);
            return ret;
        }
        gw_addr.address = gateway_ip;
        gw_addr.is_gateway_on_eth = is_ATLAS_900_A3_SUPERPOD(param->mainboard_id);
        ret = dsmi_set_default_gateway_address(param->logic_id, 0, gw_addr);
        if (ret) {
            roce_err("dsmi set default gw fail! ret[%d] logic_id[%d] gateway_ip[0x%x]",
                ret, param->logic_id, gateway_ip);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    }

    return ret;
}

STATIC int tool_cfg_route_recovery(struct tool_param *param)
{
    int ret;
    struct ds_route_table_value ip_param = {0};
    char address[MAX_IP_LEN] = "";
    char netmask[MAX_IP_LEN] = "";

    ret = cfg_read_conf(param->phy_id, "udhcpc_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("Udhcpc enable, do not need recover route cfg.");
        return 0;
    }
    ret = cfg_read_conf(param->phy_id, "udhcpc_ipv6_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("[Ipv6]Udhcpc enable, do not need recover route cfg.");
        return 0;
    }

    ret = tool_read_hccn_conf_handle_action(param, READ_TO_RECOVERY, ip_param);
    if (ret) {
        roce_err("tool_cfg_route_recovery: tool_read_hccn_conf_handle_action failed! ret is [%d]", ret);
        return ret;
    }
    return 0;
}

int tool_set_ipaddr_recovery(struct tool_param *param, const char *address, const char *netmask,
    char *gateway, unsigned int gateway_len)
{
    int ret;

    ret = cfg_read_conf(param->phy_id, "gateway", gateway, gateway_len);
    if (ret == 0) {
        ret = tool_check_ip_net_segment(address, gateway, netmask);
        if (ret) {
            roce_err("Not same net segment. (ret=%d)", ret);

            ret = cfg_del_conf(param->phy_id, "gateway");
            if (ret) {
                roce_err("del cfg error! ret[%d] logic_id[%d]", ret, param->logic_id);
                return ret;
            }
        }
    }
    ret = tool_cfg_gateway_recovery(param);
    if (ret) {
        roce_err("recover gateway cfg fail! ret[%d] phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    ret = tool_cfg_route_recovery(param);
    if (ret) {
        roce_err("recover route cfg fail[%d], phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    ret = tool_cfg_ip_route_recovery(param);
    if (ret) {
        roce_err("recover ip route cfg fail[%d], phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    ret = tool_cfg_gratuitous_arp_recovery(param);
    if (ret) {
        roce_err("recover send arp cfg fail[%d], phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    ret = tool_write_ip_conf(param, address, netmask);
    if (ret) {
        roce_err("Write cfg error. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    return 0;
}

STATIC int tool_set_device_ipaddr(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = {0};
    char netmask[MAX_IP_LEN] = {0};
    char gateway[MAX_IP_LEN] = {0};
    LOG_CONFIG("Start to set ip address and netmask_ip of logic_id[%d]", param->logic_id);
    ret = tool_ip_get_ipaddr(argc, argv, address, netmask, MAX_IP_LEN);
    if (ret) {
        roce_err("Tool ip get ipaddr fail. (ret=%d)", ret);
        return ret;
    }

    ret = tool_ip_set_address(param, address, netmask);
    if (ret) {
        roce_err("Ip set address fail! (ret=%x; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    ret = tool_set_ipaddr_recovery(param, address, netmask, gateway, MAX_IP_LEN);
    if (ret) {
        roce_err("tool recover after set ipaddr err! ret is [%d]", ret);
        return ret;
    }

    roce_info("Set logic_id[%d] ip success!", param->logic_id);
    return 0;
}

int tool_ip_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (is_ipv6_cmd(&argc, &argv)) {
        if (is_atlas_9000_a3(param)) {
            roce_err("Ipv6 atlas_9000_a3 command is not supported.");
            return UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR;
        }
        ret = tool_ip_cmd_execute_ipv6(argc, argv, param);
        if (ret != 0) {
            roce_err("tool_ip_cmd_execute_ipv6 fail, ret = %d", ret);
            return ret;
        }
        return 0;
    }
    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        if (argc != ARGC_ID_5) {
            roce_err("err ip set cmd argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ret = tool_set_device_ipaddr(argc, argv, param);
        if (ret) {
            roce_err("set device [%d] ip fail", param->logic_id);
            return ret;
        }
        return UDA_EXE_SUCCESS;
    } else if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        if (argc != ARGC_ID_1) {
            roce_err("err ip get cmd argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ret = tool_get_device_ipaddr(param);
        if (ret) {
            roce_err("get logic_id [%d] ip fail", param->logic_id);
            return ret;
        }
        return UDA_EXE_SUCCESS;
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
}

int tool_inner_gateway_set_execute(int argc, char **argv, struct tool_param *param, bool is_gateway_on_eth)
{
    int ret, ipv4_len =  MAX_IP_LEN, port_type = DSMI_ROCE_PORT;
    char gateway_ip[MAX_IP_LEN] = "";
    char ip[MAX_IP_LEN] = "";
    char mask[MAX_IP_LEN] = "";
    ip_addr_t ip_address, mask_address;
    const int index = 0;

    LOG_CONFIG("Start to set default gateway address of logic_id[%d]", param->logic_id);
    const char *pstr = NULL;

    ret = tool_ip_get_gateway(argc, argv, gateway_ip);
    if (ret) {
        roce_err("Tool ip get gateway fail. (ret=%d)", ret);
        return ret;
    }
    ret = tool_get_ipaddr_from_device(param, ip, mask, ipv4_len);
    if (ret) {
        roce_err("tool_get_ipaddr_from_device fail ret=%d, logic_id[%d]", ret, param->logic_id);
        return ret;
    }

    ret = tool_check_ip_net_segment(ip, gateway_ip, mask);
    if (ret) {
        roce_err("Not the same net segment. (ret=%d)", ret);
        return ret;
    }

    ret = tool_ip_set_gateway(param->logic_id, gateway_ip, param, is_gateway_on_eth);
    if (ret) {
        roce_err("Tool ip set gateway fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    if (!check_udhcpc_write_hccn_conf(param, 0)) {
        ret = cfg_write_conf(param->phy_id, "gateway", &gateway_ip[index]);
        if (ret) {
            roce_err("Write cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }
    return 0;
}

STATIC int tool_get_mac(int argc, char **argv, const struct tool_param *param)
{
    int ret;
    unsigned char mac_addr[TOOL_MAC_ADDR_LEN] = {0};
    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_mac_address(param->logic_id, 0, mac_addr);
    if (ret) {
        roce_err("dsmi get mac addr fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    TOOL_PRINT_INFO("mac addr: %02x:%02x:%02x:%02x:%02x:%02x",
                    mac_addr[0x0], mac_addr[0x1], mac_addr[0x2],
                    mac_addr[0x3], mac_addr[0x4], mac_addr[0x5]);
    return 0;
}

STATIC int tool_mac_filter_check(const char *argv)
{
    int index;

    if (!strncmp(argv, TOOL_MAC_FILTER_PRE_UPPER, strlen(TOOL_MAC_FILTER_PRE_UPPER))) {
        roce_err("strncmp argv error, upper case check failed");
        return UDA_PARAM_MAC_ADDR_INVALID_ERR;
    }

    if (!strncmp(argv, TOOL_MAC_FILTER_PRE_LOWER, strlen(TOOL_MAC_FILTER_PRE_LOWER))) {
        roce_err("strncmp argv error, lower case check failed");
        return UDA_PARAM_MAC_ADDR_INVALID_ERR;
    }

    // mac address like x1:xx:xx:xx:xx:xx is multicast mac addr
    if (argv[1] == '1') {
        roce_err("mac address is likely a multicast mac address");
        return UDA_PARAM_MAC_ADDR_INVALID_ERR;
    }

    for (index = 0; index < TOOL_MAC_FILTER_SIZE; index++) {
        if (!strncmp(argv, g_mac_filter_list[index], TOOL_MAC_STR_LEN)) {
            roce_err("Strncmp argv error. (index=%d)", index);
            return UDA_PARAM_MAC_ADDR_INVALID_ERR;
        }
    }

    return 0;
}

int tool_mac_str2char(const char mac_str[], unsigned char mac_pieces[], int num)
{
    int index, tmp, c2i;
    char c;
    unsigned char sum_tmp = 0;
    for (index = 0; index < TOOL_MAC_STR_LEN; index++) {
        c = mac_str[index];
        if ((index % THREE_VALUE) == TWO_VALUE) {
            if (c != ':') {
                roce_err("tool_mac_str2char contain invalid char, index[%d], mac_char[%c]", index, c);
                return UDA_PARAM_MAC_ADDR_INVALID_ERR;
            }
            sum_tmp = 0;
            continue;
        }
        switch (c) {
            case '0' ... '9':
                c2i = c - '0';
                break;
            case 'a' ... 'f':
                c2i = c - 'a' + TOOL_NUM_TEN;
                break;
            case 'A' ... 'F':
                c2i = c - 'A' + TOOL_NUM_TEN;
                break;
            default:
                roce_err("tool_mac_str2char contain invalid char[%c]", c);
                return UDA_PARAM_MAC_ADDR_INVALID_ERR;
        }
        if ((index % THREE_VALUE) == 0) {
            sum_tmp += c2i * TOOL_NUM_SIXTEEN;
        }

        if ((index % THREE_VALUE) == 1) {
            sum_tmp += c2i;
            tmp = (int)(index / THREE_VALUE);
            mac_pieces[tmp] = sum_tmp;
        }
    }
    return 0;
}

STATIC int tool_set_mac(int argc, char **argv, struct tool_param *param)
{
    int ret;
    unsigned char mac_pieces[TOOL_MAC_ADDR_LEN] = {0};

    LOG_CONFIG("start to set mac address of logic_id[%d]", param->logic_id);

    if (argc != ARGC_ID_2) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "mac", strlen("mac") + 1)) {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    if (strlen(argv[1]) != TOOL_MAC_STR_LEN) {
        roce_err("Check para length err.");
        return UDA_PARAM_MAC_ADDR_INVALID_ERR;
    }

    ret = tool_mac_str2char(argv[1], mac_pieces, TOOL_MAC_ADDR_LEN);
    if (ret) {
        roce_err("Invalid mac_address.");
        return ret;
    }

    ret = tool_mac_filter_check(argv[1]);
    if (ret) {
        roce_err("Tool mac filter check error, invalid mac_address.");
        return ret;
    }

    ret = dsmi_set_mac_address(param->logic_id, 0, mac_pieces);
    if (ret) {
        roce_err("DSMI set mac addr fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return ret;
}

STATIC int tool_netdetect_set_address(int logic_id, const char *address)
{
    int ret;
    struct ipv_addr ip = {0};

    LOG_CONFIG("Start to set net detect ip of logic_id[%d]", logic_id);
    ret = tool_inet_pton_ipv4_address(address, &(ip.ipv4));
    if (ret) {
        roce_err("Tool inet pton ipv4 address fail. (ret=%d)", ret);
        return ret;
    }

    if (ip.ipv4 == IP_BROADCAST) {
        roce_err("Addr is broadcast ip");
        return UDA_TOOL_COFNIG_BROAD_ADDRESS_ERR;
    }

    ret = dsmi_set_net_detect_ip_address(logic_id, &ip);
    if (ret) {
        roce_err("dsmi set net detect fail! ret[%d] logic_id[%d] ip[0x%x]", ret, logic_id, ip.ipv4);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return ret;
}

int tool_get_netdetect(int argc, char **argv, const struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = "";
    struct ipv_addr ip = {0};

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_net_detect_ip_address(param->logic_id, 0, &ip);
    if (ret) {
        roce_err("dsmi_get_net_detect_ip_address fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = tool_ipv4_int_to_str(ip.ipv4, address, MAX_IP_LEN);
    if (ret) {
        roce_err("tool_ipv4_int_to_str fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return ret;
    }

    TOOL_PRINT_INFO("netdetect addr: %s", address);
    return 0;
}

int tool_set_netdetect(int argc, char **argv, const struct tool_param *param)
{
    char address[MAX_IP_LEN] = "";
    const int index = 0;
    int ret;

    if (argc != THREE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    if (!strncmp(argv[1], "address", strlen("address") + 1)) {
        ret = memcpy_s(address, MAX_IP_LEN, argv[ARGC_ID_2], strlen(argv[ARGC_ID_2]) + 1);
        if (ret) {
            roce_err("memcpy_s address fail[%d], dlen[%d], slen[%u]", ret, MAX_IP_LEN, strlen(argv[ARGC_ID_2]) + 1);
            return UDA_TOOL_NO_MEM_ERR;
        }
    } else {
        roce_err("Err input cmd.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    ret = tool_netdetect_set_address(param->logic_id, address);
    if (ret) {
        roce_err("Tool netdetect set address fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }
    ret = cfg_write_conf(param->phy_id, "netdetect", &address[index]);
    if (ret) {
        roce_err("Write cfg error. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    roce_info("Set logic_id[%d] netdetect address success!", param->logic_id);
    return ret;
}

int tool_lldp_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1)) {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    param->get_cmd_flag = true;
    ret = dsmi_lldp_get_neighbor_info(param->logic_id);
    if (ret) {
        roce_err("dsmi get lldptool fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

int tool_mac_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_mac(argc, argv, param);
        if (ret) {
            roce_err("tool_get_mac fail, ret:%d", ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_mac(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("set mac failed, logic_id[%d]", param->logic_id);
            return ret;
        }
        ret = cfg_write_conf(param->phy_id, "mac_addr", argv[ARGC_ID_2]);
        if (ret) {
            roce_err("Write cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

STATIC int tool_cfg_ip_recovery(struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = "";
    char netmask[MAX_IP_LEN] = "";

    ret = tool_cfg_ip_recovery_bond(param);
    if (ret != 0) {
        roce_err("tool_cfg_ip_recovery_bond fail! (ret=%d, logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    ret = cfg_read_conf(param->phy_id, "address", address, sizeof(address));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The ip address conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    ret = cfg_read_conf(param->phy_id, "netmask", netmask, sizeof(netmask));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The netmask conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("ip address need recover cfg");
        param->option_mode = UDA_OPT_EMPTY_CMD;
        ret = tool_ip_set_address(param, address, netmask);
        if (ret) {
            roce_err("ip set address fail! ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    }

    return ret;
}

STATIC int tool_cfg_netdetect_recovery(struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = "";

    ret = cfg_read_conf(param->phy_id, "netdetect", address, sizeof(address));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The netdetect conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("netdetect address need recover cfg");
        ret = tool_netdetect_set_address(param->logic_id, address);
        if (ret) {
            roce_err("netdetect set address fail ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    }

    return ret;
}

STATIC int tool_set_mtu(struct tool_param *param, int argc, char **argv)
{
    unsigned int mac_type = MAC_TYPE_ETH, mtu_size;
    int ret, logic_id = param->logic_id;

    if (argc != ARGC_ID_2) {
        roce_err("Err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    LOG_CONFIG("Start to set mtu[%s] of logic_id[%d]", argv[1], logic_id);

    if (strncmp(argv[0], "size", strlen("size") + 1)) {
        roce_err("Invalid option -- '%s'", argv[0]);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    ret = dsmi_get_mac_type(logic_id, 0, &mac_type);
    if (ret) {
        roce_err("Dsmi get mac type fail. (ret=%d; logic_id=%d; mac_type=%u)",
                 ret, logic_id, mac_type);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    if (mac_type >= INVALID_MAC_TYPE) {
        roce_err("Dsmi get mac type fail. (ret=%d; logic_id=%d; mac_type=%u)",
                 ret, logic_id, mac_type);
        return UDA_DSMI_EXE_ERR;
    }

    ret = tool_check_mtu(argv[1], &mtu_size, mac_type);
    if (ret) {
        roce_err("Invalid mtu format-- '%s'", argv[0]);
        return ret;
    }

    ret = dsmi_set_mtu(logic_id, 0, mtu_size);
    if (ret) {
        roce_err("Dsmi set mtu fail. (ret=%d; logic_id=%d; mtu=%u)", ret, logic_id, mtu_size);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = tool_del_ipv6_conf_after_set_mtu(param->phy_id, mac_type, mtu_size);
    if (ret) {
        roce_err("del ipv6 address cfg error when config mtu! ret[%d] phy_id[%d]", ret, param->phy_id);
        return ret;
    }
    return ret;
}

STATIC int tool_cfg_mtu_recovery(struct tool_param *param)
{
    int ret;
    char mtu[FIVE_VALUE] = "";
    char *argv[ARGC_ID_2];
    argv[0] = "size";

    ret = cfg_read_conf(param->phy_id, "mtu", mtu, sizeof(mtu));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The mtu conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("mtu address need recover cfg");
        argv[1] = mtu;
        ret = tool_set_mtu(param, ARGC_ID_2, argv);
        if (ret) {
            roce_err("mtu set fail ret[%d] logic_id[%d]", ret, param->logic_id);
        }
    }

    return ret;
}

STATIC int tool_cfg_mac_addr_recovery(struct tool_param *param)
{
    int ret;
    char mac_addr[TOOL_MAC_STR_LEN + 1] = "";
    char *argv[ARGC_ID_2];
    argv[0] = "mac";

    ret = cfg_read_conf(param->phy_id, "mac_addr", mac_addr, sizeof(mac_addr));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The mac_addr conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("mac_addr address need recover cfg, logic_id[%d]", param->logic_id);
        argv[1] = mac_addr;
        ret = tool_set_mac(ARGC_ID_2, argv, param);
        if (ret) {
            roce_err("mac_addr set fail ret[%d] logic_id[%d]", ret, param->logic_id);
        }
    }

    return ret;
}

int tool_cfg_shaping_recovery(struct tool_param *param)
{
    int ret;
    char bw_limit[CHAR_ARGV_MAX] = "";
    char *argv[ARGV_NUM_2];
    argv[0] = "bw_limit";

    ret = cfg_read_conf(param->phy_id, "bw_limit", bw_limit, sizeof(bw_limit));
    if (ret) {
        roce_info("port shaping bw_limit do not need recover cfg [%d]", ret);
        return 0;
    } else {
        roce_info("port shaping bw_limit need recover cfg: logic_id[%d]", param->logic_id);
        argv[1] = bw_limit;
        ret = tool_port_shaping_set(param->logic_id, ARGC_ID_2, 0, argv);
        if (ret) {
            roce_err("tool set port shaping fail ret[%d] logic_id[%d]", ret, param->logic_id);
        }
    }

    return ret;
}

STATIC int tool_str_split(char *src, const char *split_s, char dst[][DSCP_STR_LEN], int dst_len)
{
    char *str = src;
    char *token = NULL;
    int cnt = 0;
    int ret;

    for (token = strsep(&str, split_s); token != NULL; token = strsep(&str, split_s)) {
        roce_info("token = %s, len = %d", token, strlen(token));
        if (strlen(token) <= 1) {
            continue;
        }

        if (cnt >= dst_len) {
            break;
        }

        ret = strncpy_s(dst[cnt++], DSCP_STR_LEN, token, strlen(token));
        if (ret) {
            roce_err("strncpy_s fail ret[%d] token[%s].", ret, token);
            return UDA_TOOL_NO_MEM_ERR;
        }
    }

    return cnt;
}

STATIC int tool_dscp_tc_value_check(unsigned char dscp, unsigned char tc)
{
    if (dscp > DSCP_MAX) {
        roce_err("dscp[%u] > [%d](DSCP_MAX) is invalid!", dscp, DSCP_MAX);
        return UDA_TOOL_PARSE_CONF_FILE_ERR;
    }

    if (tc > TC_MAX) {
        roce_err("tc[%u] > [%d](TC_MAX) is invalid!", tc, TC_MAX);
        return UDA_TOOL_PARSE_CONF_FILE_ERR;
    }

    return 0;
}

STATIC int tool_dscp_cfg_read(struct tool_param *param, struct dscp_tc_data *tos_data, int tos_data_len, int *tos_len,
    int(*func)(int, unsigned int, unsigned char, unsigned char))
{
    char dscp_str[MAX_DSCP_LEN] = {0};
    char tos_str[DS_MAX_USER_TOS][DSCP_STR_LEN];
    unsigned char dscp = 0;
    unsigned char tc = 0;
    int j, ret;
    int tos_cnt = 0;

    ret = cfg_read_conf(param->phy_id, DSCP_TC_CONF, dscp_str, sizeof(dscp_str));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The dscp conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        tos_cnt = tool_str_split(dscp_str, ",", tos_str, DS_MAX_USER_TOS);
        if ((tos_cnt == -1) || ((tos_data != NULL) && (tos_cnt > tos_data_len))) {
            roce_err("dscp split str fail, tos:%d.", tos_cnt);
            return UDA_TOOL_PARSE_CONF_FILE_ERR;
        }

        for (j = 0; j < tos_cnt; j++) {
            ret = sscanf_s(tos_str[j], "%hhu:%hhu", &dscp, &tc);
            if (ret != DSCP_AND_TC) {
                roce_err("sscanf_s fail %d.", ret);
                return UDA_TOOL_PARSE_CONF_FILE_ERR;
            }

            ret = tool_dscp_tc_value_check(dscp, tc);
            if (ret) {
                return ret;
            }

            if (tos_data != NULL) {
                tos_data[j].dscp = dscp;
                tos_data[j].tc = tc;
                *tos_len = j + 1;
            }

            /* set dscp to tc map, func can be null */
            if (func == NULL) {
                continue;
            }

            ret = func(param->logic_id, 0, dscp, tc);
            if (ret) {
                roce_err("set dscp_to_tc fail, ret %d, logic_id %d, dscp %d, tc %d", ret, param->logic_id, dscp, tc);
                return UDA_DSMI_EXE_ERR;
            }
        }
    }

    return 0;
}

STATIC int tool_cfg_dscp_recovery(struct tool_param *param)
{
    return tool_dscp_cfg_read(param, NULL, 0, NULL, dsmi_set_dscp_map);
}

STATIC int tool_cfg_static_speed_recovery(struct tool_param *param)
{
    char speed[CHAR_ARGV_MAX] = "";
    char *argv[ARGV_NUM_2];
    int ret;

    argv[0] = "static_speed";
    ret = cfg_read_conf(param->phy_id, argv[0], speed, sizeof(speed));
    if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_info("generic info static speed do not need recover cfg [%d]", ret);
        return 0;
    }

    if (ret) {
        roce_err("generic info speed cfg_read_conf failed: logic_id[%d] speed[%s]", param->logic_id, speed);
        return ret;
    }

    roce_info("generic info speed need recover cfg: logic_id[%d] static_speed[%s]", param->logic_id, speed);
    argv[1] = speed;
    ret = tool_set_static_speed(ARGV_NUM_2, argv, param);
    if (ret) {
        roce_err("tool set generic info fail ret[%d] logic_id[%d] speed[%s]", ret, param->logic_id, speed);
    }

    return ret;
}

STATIC int tool_cfg_auto_adapt_recovery(struct tool_param *param)
{
    char auto_adapt_flag[AUTO_ADAPT_INBUFF_LEN] = {0};
    char inbuf[AUTO_ADAPT_INBUFF_LEN] = {0};
    int ret;

    ret = cfg_read_conf(param->phy_id, "auto_adapt", auto_adapt_flag, sizeof(auto_adapt_flag));
    if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_info("generic info auto adapt do not need recover cfg [%d]", ret);
        return 0;
    }

    if (ret) {
        roce_err("auto adapt cfg_read_conf failed: logic_id[%d] status[%s]", param->logic_id, "on");
        return ret;
    }

    ret = sprintf_s(inbuf, AUTO_ADAPT_INBUFF_LEN, "%s", "on");
    if (ret <= 0) {
        roce_err("Generic info cmd sprintf auto_adapt failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }

    roce_info("generic info auto adapt need recover cfg: logic_id[%d] auto_adapt", param->logic_id);
    LOG_CONFIG("start to set auto_adapt speed of logic_id [%d]", param->logic_id);
    ret = dsmi_set_optical_auto_adapt(param->logic_id, inbuf, AUTO_ADAPT_INBUFF_LEN);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("dsmi_set_optical_auto_adapt error[%d], phy_id[%d], status[%s]",
                 ret, param->phy_id, "on");
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return ret;
}

STATIC int tool_cfg_generic_recovery(struct tool_param *param)
{
    int ret;

    ret = tool_cfg_static_speed_recovery(param);
    if (ret) {
        roce_err("tool recovery static speed fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return ret;
    }

    ret = tool_cfg_auto_adapt_recovery(param);
    if (ret) {
        roce_err("tool recovery auto adapt fail ret[%d] logic_id[%d]", ret, param->logic_id);
    }

    return ret;
}

int resolve_abnormal_param(int argc, char **argv)
{
    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    if (access(CFGFILE_NAME, F_OK) != 0) {
        roce_err("The config file does not exist. Failed to recover the configuration.");
        return UDA_TOOL_ACCESS_CONF_FILE_ERR;
    }
    return 0;
}

recovery_cmd_t g_recovery_ipv4_cmd_list[] = {
    {"ipv4", tool_cfg_ip_recovery},
    {"netdetect", tool_cfg_netdetect_recovery},
    {"ipv4 gateway", tool_cfg_gateway_recovery},
    {"ip rule", tool_cfg_ip_rule_recovery},
    {"arp", tool_cfg_arp_recovery},
    {"route", tool_cfg_route_recovery},
    {"ip route", tool_cfg_ip_route_recovery},
    {"gratuitous arp", tool_cfg_gratuitous_arp_recovery},
};

recovery_cmd_t g_recovery_ipv6_cmd_list[] = {
    {"ip ipv6", tool_cfg_ip_ipv6_recovery},
    {"ipv6 netdetect", tool_cfg_netdetect_ipv6_recovery},
    {"ipv6 gateway", tool_cfg_gateway_recovery_ipv6},
    {"ipv6 route", tool_cfg_route_ipv6_recovery},
    {"neigh", tool_cfg_neigh_recovery},
};

recovery_cmd_t g_recovery_com_cmd_list[] = {
    {"ipv4 udhcpc", tool_cfg_ip_udhcpc_recovery},
    {"ipv6 udhcpc", tool_cfg_ip_ipv6_udhcpc_recovery},
    {"mac address", tool_cfg_mac_addr_recovery},
    {"mtu", tool_cfg_mtu_recovery},
    {"dscp", tool_cfg_dscp_recovery},
    {"generic", tool_cfg_generic_recovery},
    {"shaping", tool_cfg_shaping_recovery},
    {"roce_port", tool_cfg_roce_port_recovery},
    {"pfc", tool_cfg_pfc_recovery},
    {"tc", tool_tc_cfg_recovery},
    {"prio_tc", tool_cfg_prio_tc_recovery},
    {"fec", tool_cfg_fec_recovery},
    {"dcqcn_cnp_dscp", tool_cfg_dcqcn_cnp_dscp_recovery},
    {"dcqcn_alg", tool_cfg_dcqcn_alg_recovery},
    {"dcqcn_enable", tool_cfg_dcqcn_enable_recovery},
    {"xsfp_reset", tool_cfg_xsfp_reset_recovery},
    {"tls_enable", tool_cfg_tls_enable_recovery},
    {"tls ca", tool_cfg_tls_ca_recovery},
    {"lldp_portid", tool_cfg_lldp_portid_recovery},
    {"bad_thd", tool_roce_cw_bad_cnt_thd_recovery},
    {"pfc_storm_watchdog", tool_cfg_pfc_storm_watchdog_recovery},
    {"down_fault_time", tool_downdelay_recovery},
    {"scdr_reset_delay_time", tool_scdr_reset_delay_time_recovery},
    {"cdr_reset", tool_cdr_reset_recovery},
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
    {"tc_qos", tool_cfg_tc_qos_recovery},
    {"udp_port_mode", tool_cfg_udp_port_mode_recovery},
    {"mem_reserve", tool_cfg_mem_reserve_recovery},
#endif
};

recovery_cmd_t g_recovery_cooperative_cmd_list[] = {
    {"auto_downgrade", tool_cfg_downgrade_lane_recovery},
    {"optical_snr", tool_cfg_optical_snr_query_recovery},
};

recovery_cmd_t *get_recovery_ipv4_cmd_list(int *size)
{
    *size = sizeof(g_recovery_ipv4_cmd_list) / sizeof(g_recovery_ipv4_cmd_list[0]);
    return g_recovery_ipv4_cmd_list;
}

recovery_cmd_t *get_recovery_ipv6_cmd_list(int *size)
{
    *size = sizeof(g_recovery_ipv6_cmd_list) / sizeof(g_recovery_ipv6_cmd_list[0]);
    return g_recovery_ipv6_cmd_list;
}

recovery_cmd_t *get_recovery_com_cmd_list(int *size)
{
    *size = sizeof(g_recovery_com_cmd_list) / sizeof(g_recovery_com_cmd_list[0]);
    return g_recovery_com_cmd_list;
}

// 主从die互助，一些从die的配置需下发到主die保存。因此主die复位时，需要额外恢复从die配置。cooperative_cfg专门恢复该类配置
recovery_cmd_t *get_recovery_cooperative_cmd_list(int *size)
{
    *size = sizeof(g_recovery_cooperative_cmd_list) / sizeof(g_recovery_cooperative_cmd_list[0]);
    return g_recovery_cooperative_cmd_list;
}

int tool_cfg_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if ((!strncmp(argv[0], "recovery", strlen("recovery") + 1)) && (param->cmd_attr == UDA_DEV_CMD)) {
        return tool_cfg_cmd_recovery(argc, argv, param);
    } else if ((!strncmp(argv[0], "recovery", strlen("recovery") + 1)) && (param->cmd_attr == UDA_GLOBAL_CMD)) {
        return tool_cfg_cmd_recovery_all(argc, argv, param);
    } else if ((!strncmp(argv[0], "status", strlen("status") + 1)) && (param->cmd_attr == UDA_DEV_CMD)) {
        param->get_cmd_flag = true; // hccn_tool -i [%d] -cfg status: 查询打印当前recovery状态
        return tool_cfg_status_get(argc, argv, param);
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
}

STATIC int tool_link_get_linkstatus(int argc, int logic_id)
{
    int ret;
    int link = 0;

    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_netdev_link(logic_id, 0, &link);
    if (ret != 0) {
        roce_err("The dsmi gets link status fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (link) {
        TOOL_PRINT_INFO("link status: UP");
    } else {
        TOOL_PRINT_INFO("link status: DOWN");
    }

    return ret;
}

STATIC int tool_link_set_linkstatus(int argc, char **argv, int logic_id)
{
    int ret;
    int enable_flag = INT_MAX; // 表示整型变量能够存储的最大值
    LOG_CONFIG("start to set the link of logic_id[%d] status", logic_id);

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "down", strlen("down") + 1)) {
        enable_flag = DISABLE;
        ret = tool_double_check(
            "[WARNING] This link down command will result in the loss of the IPv6 address, continue?");
        if (ret != 0) {
            roce_info("hccn tool command aborts by user. (link down)");
            return ret;
        }
    } else if (!strncmp(argv[0], "up", strlen("up") + 1)) {
        enable_flag = ENABLE;
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    ret = dsmi_set_netdev_link(logic_id, 0, enable_flag);
    if (ret != 0) {
        roce_err("The dsmi set net dev status fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

int tool_link_set(int argc, char **argv, struct tool_param *param)
{
    if (argc < 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    } else if (!strcmp(argv[0], "up") || !strcmp(argv[0], "down")) {
        return tool_link_set_linkstatus(argc, argv, param->logic_id);
#ifdef HCCN_TOOL_SHOW_EXT
    } else if (!strcmp(argv[0], "down_fault_time")) {
        return tool_link_set_downdelay(argc - 1, argv + 1, param);
#endif
    }
    roce_err("invalid operation. (-link -s %s)", argv[0]);
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

int tool_link_get(int argc, char **argv, struct tool_param *param)
{
    if (argc == 0) {
        return tool_link_get_linkstatus(argc, param->logic_id);
#ifdef HCCN_TOOL_SHOW_EXT
    } else if (!strcmp(argv[0], "down_fault_time")) {
        if (argc != 1) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        return tool_config_downdelay(param->logic_id, 0, GET_MODE);
#endif
    }
    roce_err("invalid operation. (-link -g %s)", argv[0]);
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

int tool_link_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret = 0;
    int logic_id = param->logic_id;
    int argc_tmp = argc - 1;
    char **argv_tmp = argv + 1;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_link_set(argc_tmp, argv_tmp, param);
        if (ret != 0) {
            roce_err("The tool_link_set failed. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
        if (!strncmp(argv[1], "up", strlen("up") + 1)) {
            ret = recovery_process_cfg_cmd(param);
            if (ret != 0) {
                TOOL_PRINT_INFO("Link up executed, "
                    "but recovery failed, please check '/var/log/hccn_tool/hccn_config.log' for details.");
                roce_err("The recovery_process_cfg_cmd failed. (ret=%d; logic_id=%d)", ret, logic_id);
                return ret;
            }
        }
    } else if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_link_get(argc_tmp, argv_tmp, param);
        if (ret != 0) {
            roce_err("The tool_link_get failed. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
    } else {
        roce_err("tool_link_cmd_execute invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

STATIC int tool_get_mtu(int logic_id, int argc)
{
    int ret;
    unsigned int mtu = 0;

    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_mtu(logic_id, 0, &mtu);
    if (ret) {
        roce_err("dsmi get mtu fail ret[%d] logic_id[%d]", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    DSMI_PRINT_INFO("mtu:%u", mtu);
    return ret;
}

int tool_mtu_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    int logic_id = param->logic_id;
    int argc_tmp = argc - 1;
    char **argv_tmp = argv + 1;
    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_mtu(param, argc_tmp, argv_tmp);
        if (ret) {
            roce_err("set mtu failed, logic_id[%d]", param->logic_id);
            return ret;
        }
        ret = cfg_write_conf(param->phy_id, "mtu", argv[ARGC_ID_2]);
        if (ret) {
            roce_err("write cfg error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-g", strlen(argv[0]) + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_mtu(logic_id, argc_tmp);
        if (ret) {
            roce_err("tool get mtu failed ret %d'", ret);
            return ret;
        }
    } else {
        roce_err("invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    return ret;
}

int tool_net_health_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    int logic_id = param->logic_id;
    int num = sizeof(g_net_health_status) / sizeof(g_net_health_status[0]);
    DSMI_NET_HEALTH_STATUS presult;

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1)) {
        roce_err("invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    param->get_cmd_flag = true;
    ret = dsmi_get_network_health(logic_id, &presult);
    if (ret || (int)presult >= num) {
        roce_err("dsmi get net health fail ret[%d] logic_id[%d] presult[%d]", ret, logic_id, presult);
        return UDA_DSMI_EXE_ERR;
    } else {
        TOOL_PRINT_INFO("net health status: %s", g_net_health_status[(int)presult].status_str);
    }
    return ret;
}

STATIC int tool_str_to_u8(const char *argv, unsigned char *val_ptr)
{
    unsigned int i;
    int val;
    unsigned int argv_len = strlen(argv);
    if (argv_len > U8_MAX_LEN) {
        roce_err("argv len[%u] overflow the u8[%u].", strlen(argv), U8_MAX_LEN);
        return UDA_PARAM_INVALID_ERR;
    }

    for (i = 0; i < argv_len; i++) {
        if ((argv[i] < '0') || (argv[i] > '9')) {
            roce_err("vaule is not digit, expect digit[0-9].");
            return UDA_PARAM_INVALID_ERR;
        }
    }

    if ((strlen(argv) > 1) && (argv[0] == '0')) {
        roce_err("argv is not right digit.");
        return UDA_PARAM_INVALID_ERR;
    }

    val = strtol(argv, NULL, NUMBER_BASE);
    if ((val > U8_MAX) || (val < 0)) {
        roce_err("argv [%d] overflow the u8[0~255].", val);
        return UDA_PARAM_INVALID_ERR;
    }
    *val_ptr = (unsigned char)val;

    return 0;
}

STATIC void tool_dscp_update_data(struct dscp_tc_data *tos_data, int *tos_len, unsigned char dscp_val,
    unsigned char tc_val)
{
    int i;

    for (i = 0; i < (*tos_len); i++) {
        if (tos_data[i].dscp == dscp_val) {
            tos_data[i].tc = tc_val;
            return;
        }
    }

    if (i < DS_MAX_USER_TOS) {
        tos_data[i].dscp = dscp_val;
        tos_data[i].tc = tc_val;
        *tos_len += 1;
    }

    return;
}

STATIC int tool_dscp_write_conf(struct tool_param *param, unsigned char dscp_val, unsigned char tc_val)
{
    struct dscp_tc_data tos_data[DS_MAX_USER_TOS];
    int tos_len = 0;
    char conf[CONLINE_LENGTH] = {0};
    char *p = (char *)conf;
    int conf_len = 0;
    int ret;
    int i;

    ret = memset_s(tos_data, sizeof(struct dscp_tc_data) * DS_MAX_USER_TOS, 0,
                   sizeof(struct dscp_tc_data) * DS_MAX_USER_TOS);
    if (ret) {
        roce_err("memset error, ret[%d].", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = tool_dscp_cfg_read(param, tos_data, DS_MAX_USER_TOS, &tos_len, NULL);
    if (ret || (tos_len > DS_MAX_USER_TOS)) {
        roce_err("tool_dscp_cfg_read cfg fail[%d], conf[%s] logic_id[%d] dscp cfg_len[%d].",
            ret, DSCP_TC_CONF, param->logic_id, tos_len);
        return ret;
    }

    tool_dscp_update_data(tos_data, &tos_len, dscp_val, tc_val);
    roce_info("tos_len = [%d].", tos_len);

    for (i = 0; i < tos_len; i++) {
        ret = sprintf_s(p, CONLINE_LENGTH - conf_len, "%u:%u,", tos_data[i].dscp, tos_data[i].tc);
        if (ret <= 0) {
            roce_err("sprintf_s fail[%d], tos_data[%d].dscp[%u], tos_data[%d].tc[%u].",
                ret, i, tos_data[i].dscp, i, tos_data[i].tc);
            return UDA_TOOL_NO_MEM_ERR;
        }
        conf_len += ret;
        p += ret;
    }

    ret = cfg_write_conf(param->phy_id, DSCP_TC_CONF, conf);
    if (ret) {
        roce_err("write cfg fail[%d] phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    return 0;
}

STATIC int tool_dscp_check_argv(int argc, char **argv, unsigned char *dscp_ptr, unsigned char *tc_ptr)
{
    int ret;
    char **argv_tmp = argv;

    if (argc != FOUR_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv_tmp[0], "dscp", strlen("dscp") + 1)) {
        roce_err("invalid dscp option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    argv_tmp++;
    ret = tool_str_to_u8(argv_tmp[0], dscp_ptr);
    if (ret) {
        roce_err("invalid dscp_ptr option");
        return ret;
    }
    if (*dscp_ptr > DSCP_MAX) {
        roce_err("dscp[%u] > [%d](DSCP_MAX) is invalid!", *dscp_ptr, DSCP_MAX);
        return UDA_PARAM_DSCP_OUT_OF_RANGE_ERR;
    }

    argv_tmp++;
    if (strncmp(argv_tmp[0], "tc", strlen("tc") + 1)) {
        roce_err("invalid tc option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    argv_tmp++;
    ret = tool_str_to_u8(argv_tmp[0], tc_ptr);
    if (ret) {
        roce_err("invalid tc_ptr option");
        return ret;
    }

    if (*tc_ptr > TC_MAX) {
        roce_err("tc[%u] > [%d](TC_MAX) is invalid!", *tc_ptr, TC_MAX);
        return UDA_PARAM_TC_OUT_OF_RANGE_ERR;
    }

    return 0;
}

STATIC int tool_dscp_set_map(int argc, char **argv, unsigned int port_id, struct tool_param *param)
{
    int ret;
    unsigned char dscp_val;
    unsigned char tc_val;
    int logic_id = param->logic_id;

    if (argc != FOUR_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    LOG_CONFIG("start to set dscp and tc of logic_id[%d]", logic_id);

    ret = tool_dscp_check_argv(argc, argv, &dscp_val, &tc_val);
    if (ret) {
        roce_err("tool_dscp_check_argv fail, ret[%d]!", ret);
        return ret;
    }
    roce_info("logic_id[%d], dscp[%u] tc[%u].", logic_id, dscp_val, tc_val);
    ret = dsmi_set_dscp_map(logic_id, port_id, dscp_val, tc_val);
    if (ret) {
        roce_err("dsmi set dscp to tc fail ret[%d], logic_id[%d], dscp[%u], tc[%u].", ret, logic_id, dscp_val, tc_val);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = tool_dscp_write_conf(param, dscp_val, tc_val);
    if (ret) {
        roce_err("dscp to tc write conf fail,ret[%d],phy_id[%d], dscp[%u], tc[%u].",
            ret, param->phy_id, dscp_val, tc_val);
        return ret;
    }

    return 0;
}

STATIC int tool_get_dscp_value(int argc, char **argv, unsigned char *dscp_val)
{
    int ret;

    ret = tool_str_to_u8(argv[0], dscp_val);
    if (ret) {
        roce_err("invalid option");
        return ret;
    }

    if (*dscp_val > DSCP_MAX) {
        roce_err("dscp[%u] > [%d](DSCP_MAX) is invalid!", *dscp_val, DSCP_MAX);
        return UDA_PARAM_DSCP_OUT_OF_RANGE_ERR;
    }

    return 0;
}

STATIC int tool_dscp_get_map(int argc, char **argv, unsigned int port_id, int logic_id)
{
    int i, ret;
    unsigned char dscp_val = 0;
    unsigned char tos_tc[DS_MAX_USER_TOS] = {0};
    char **argv_tmp = argv;

    if ((argc != ARGC_ID_2) && (argc != 0)) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (argc == ARGC_ID_2) {
        if (strncmp(argv_tmp[0], "dscp", strlen("dscp") + 1)) {
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }

        argv_tmp++;
        ret = tool_get_dscp_value(argc, argv_tmp, &dscp_val);
        if (ret) {
            roce_err("get dscp value from string failed, ret %d", ret);
            return ret;
        }
        ret = dsmi_get_dscp_map(logic_id, port_id, dscp_val, &tos_tc[dscp_val]);
        if (ret) {
            roce_err("dsmi get dscp to tc fail ret[%d] logic_id[%d] dscp[%u].", ret, logic_id, dscp_val);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }

        if (tos_tc[dscp_val] > TC_MAX) {
            roce_err("tc[%u] > [%d](TC_MAX) is invalid!", tos_tc[dscp_val], TC_MAX);
            return UDA_PARAM_TC_OUT_OF_RANGE_ERR;
        }

        TOOL_PRINT_INFO("%4s%8s", "dscp", "tc");
        TOOL_PRINT_INFO("%4u%8u", dscp_val, tos_tc[dscp_val]);
    } else {
        TOOL_PRINT_INFO("%4s%8s", "dscp", "tc");
        for (i = 0; i < DS_MAX_USER_TOS; i++) {
            ret = dsmi_get_dscp_map(logic_id, port_id, i, &tos_tc[i]);
            if (ret) {
                roce_err("dsmi get dscp to tc fail ret[%d] logic_id[%d] dscp[%u].", ret, logic_id, i);
                return dsmi_analysis_dsmi_ret_to_uda(ret);
            }

            if (tos_tc[i] > TC_MAX) {
                roce_err("tc[%u] > [%d](TC_MAX) is invalid!", tos_tc[i], TC_MAX);
                return UDA_PARAM_TC_OUT_OF_RANGE_ERR;
            }
            TOOL_PRINT_INFO("%4d%8u", i, tos_tc[i]);
        }
    }

    return 0;
}

int tool_dscp_cmd_execute(int argc, char **argv, struct tool_param *param, unsigned int port_id)
{
    int ret, logic_id = param->logic_id, argc_tmp = argc - 1, tmp_port_id = 0;
    char **argv_tmp = argv + 1;
    if (argc == 0) {
        roce_err("tool_dscp_cmd_execute err argc[%d].", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_dscp_set_map(argc_tmp, argv_tmp, tmp_port_id, param);
    } else if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_dscp_get_map(argc_tmp, argv_tmp, tmp_port_id, logic_id);
    } else {
        roce_err("invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_get_vnic_ipaddr(struct tool_param *param, char ip_addr[], unsigned int ip_len,
                         char netmask_addr[], unsigned int netmask_len)
{
    int ret, port_id = 0;
    ip_addr_t ip_address, mask_address;
    const char *pstr = NULL;
    struct in_addr *addr = NULL;

    ip_address.ip_type = IPADDR_TYPE_V4;
    mask_address.ip_type = IPADDR_TYPE_V4;
    ret = dsmi_get_device_ip_address(param->logic_id, DSMI_VNIC_PORT, port_id, &ip_address, &mask_address);
    if (ret) {
        roce_err("dsmi_get_device_ip_address fail ret=%d, logic_id[%d]", ret, param->logic_id);
        return UDA_DSMI_EXE_ERR;
    }

    pstr = inet_ntop(AF_INET, (void *)&ip_address, ip_addr, ip_len);
    if (pstr == NULL) {
        addr = (struct in_addr *)(void *)(&ip_address);
        roce_err("ip[0x%x] transfer error", addr->s_addr);
        return UDA_TOOL_NO_MEM_ERR;
    }

    pstr = inet_ntop(AF_INET, (void *)&mask_address, netmask_addr, netmask_len);
    if (pstr == NULL) {
        addr = (struct in_addr *)(void *)(&mask_address);
        roce_err("netmask[0x%x] transfer error", addr->s_addr);
        return UDA_TOOL_NO_MEM_ERR;
    }

    return UDA_EXE_SUCCESS;
}

int tool_vnic_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret, link, logic_id = param->logic_id;
    char ip_addr[MAX_IP_LEN] = {0}, netmask_addr[MAX_IP_LEN] = {0};

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1)) {
        roce_err("invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    param->get_cmd_flag = true;
    ret = dsmi_get_vnic_status(logic_id, 0, &link);
    if (ret) {
        roce_err("get vnic status fail ret[%d] logic_id[%d] link[%d]", ret, logic_id, link);
        return UDA_DSMI_EXE_ERR;
    }

    ret = tool_get_vnic_ipaddr(param, ip_addr, MAX_IP_LEN, netmask_addr, MAX_IP_LEN);
    if (ret) {
        roce_err("tool_get_vnic_ipaddr fail ret[%d] logic_id[%d]", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (link) {
        TOOL_PRINT_INFO("vnic link status: UP");
    } else {
        TOOL_PRINT_INFO("vnic link status: DOWN");
    }
    TOOL_PRINT_INFO("vnic ipaddr: %s", ip_addr);
    TOOL_PRINT_INFO("vnic netmask: %s", netmask_addr);

    return 0;
}

bool is_network_segment(unsigned int address, unsigned int netmask)
{
    return !(address & ~netmask);
}

bool is_address_gateway_same_segment(unsigned int address, unsigned int gateway, unsigned int netmask)
{
    return ((address & netmask) == (gateway & netmask));
}

