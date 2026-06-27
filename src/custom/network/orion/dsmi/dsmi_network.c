/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <arpa/inet.h>
#include <netinet/in.h>
#include "ds_data.h"
#include "ds_net_interface.h"
#include "securec.h"
#include "hccn_log.h"
#include "ascend_hal_error.h"
#include "dsmi_network.h"
#include "dsmi_common_product.h"
#include "comm_channel.h"
#include "tool_product.h"
#include "tool_comm.h"
#include "tool_cfg_ops.h"
#include "dsmi_common_interface.h"

/* Forward declaration: defined in dsmi_cfg_ops.c, no dedicated header */
struct command_context;
bool is_ipaddr_conflict(struct command_context *ctx);

#define DSMI_MAX_IP_VAL_LEN 48
#define BANDWIDTH_STR_MAXLEN 100
EXPORT_FUNCTION int dsmi_get_ub_bandwidth(int device_id, int udie_id, int port_id,
                                          unsigned int time_interval, struct ub_bandwidth_t *bw)
{
    unsigned int size_out = sizeof(struct ub_bottom_bandwidth_t);
    struct ub_bottom_bandwidth_t data = {0};
    struct command_context ctx = {0};
    struct dsmi_info info = {0};
    int ret;

    if (bw == NULL) {
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.udie_id = udie_id;
    ctx.port_id = port_id;
    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context),
                   (char *)&time_interval, sizeof(unsigned int), (char *)&data, &size_out);
    ret = dsmi_exe_get_info(device_id, DS_GET_UB_BANDWIDTH, &info);
    if (ret != 0) {
        hccn_err("dsmi get bandwidth failed. (ret=%d)", ret);
        return ret;
    }

    bw->tx_bandwidth = (unsigned int)data.tx_bandwidth;
    bw->rx_bandwidth = (unsigned int)data.rx_bandwidth;
    return 0;
}

EXPORT_FUNCTION int dsmi_get_device_ub_ping_info(int device_id, struct dcmi_ub_ping_operate *ping_args,
    struct ub_ping_result* ping_result)
{
    int ret;
    struct command_context ctx = { 0 };
    struct ub_ping_operate ping_info = { 0 };

    ping_info.ub_pair_num = 1;
    if (ping_args == NULL || ping_result == NULL) {
        hccn_err("ping_args or ping_result is NULL.");
        return DRV_ERROR_INVALID_VALUE;
    }

    if (ping_args->pkt_interval < 0 || ping_args->pkt_interval > MAX_PING_PKT_INTERVAL) {
        hccn_err("pkt_interval is invalid. (pkt_interval=%d)", ping_args->pkt_interval);
        return DRV_ERROR_INVALID_VALUE;
    }
    ping_info.pkt_interval = ping_args->pkt_interval;

    if (ping_args->pkt_size < 0 || ping_args->pkt_size > MAX_PING_PKT_SIZE) {
        hccn_err("pkt_size is invalid. (pkt_size=%d)", ping_args->pkt_size);
        return DRV_ERROR_INVALID_VALUE;
    }
    ping_info.pkt_size = ping_args->pkt_size == 0? DEFAULT_PKT_SIZE : ping_args->pkt_size;

    if (ping_args->pkt_send_num < 0 || ping_args->pkt_send_num > MAX_PING_PKT_NUM) {
        hccn_err("pkt_send_num is invalid. (pkt_send_num=%d)", ping_args->pkt_send_num);
        return DRV_ERROR_INVALID_VALUE;
    }
    ping_info.pkt_send_num = ping_args->pkt_send_num == 0 ? DEFAULT_PKT_SEND_NUM : ping_args->pkt_send_num;

    if (ping_args->timeout < 0 || ping_args->timeout > MAX_PING_TIMEOUT) {
        hccn_err("timeout is invalid. (timeout=%d)", ping_args->timeout);
        return DRV_ERROR_INVALID_VALUE;
    }
    ping_info.timeout = ping_args->timeout == 0 ? DEFAULT_TIMEOUT_TIME  : ping_args->timeout;

    ret = strcpy_s(ping_info.ub_pair_info.src_addr, MAX_EID_NUM, ping_args->ub_pair_info.src_addr);
    if (ret != 0) {
        hccn_err("src_addr strcpy_s failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    ret = strcpy_s(ping_info.ub_pair_info.dst_addr, MAX_EID_NUM, ping_args->ub_pair_info.dst_addr);
    if (ret != 0) {
        hccn_err("dst_addr strcpy_s failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    ctx.npu_info.logic_id = device_id;
    ret = dsmi_get_ub_ping_info(&ctx, &ping_info, ping_result, false);
    if (ret != 0) {
        hccn_err("dsmi get ub ping info failed. (ret=%d)", ret);
        return ret;
    }

    if (ping_result->suc_pkt_num == 0) {
        ret = DRV_ERROR_WAIT_TIMEOUT;
    }
    return ret;
}

EXPORT_FUNCTION int dsmi_get_port_pkt_stats_info(int logic_id, int udie_id, int port_id,
                                                 struct ds_port_pkt_stats_info *port_pkt_stats_info)
{
    struct command_context ctx = {0};
    struct dsmi_info info = {0};
    int ret;

    if (port_pkt_stats_info == NULL) {
        return DRV_ERROR_INVALID_VALUE;
    }

    unsigned int size = sizeof(struct ds_port_pkt_stats_info);

    ctx.udie_id = udie_id;
    ctx.port_id = port_id;

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), NULL, 0, (char *)port_pkt_stats_info, &size);

    ret = dsmi_exe_get_info(logic_id, DS_GET_PACKET_STATISTICS, &info);
    if (ret != 0) {
        hccn_err("dsmi get stats info failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_get_port_avail_credit_info(int device_id, int udie_id, int port_id,
                                                    struct dsmi_credit_info *port_avail_credit_info)
{
    struct command_context ctx = {0};
    struct dsmi_info info = {0};
    int ret;
    unsigned int size = sizeof(struct dsmi_credit_info);

    if (port_avail_credit_info == NULL) {
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.udie_id = udie_id;
    ctx.port_id = port_id;

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), NULL, 0, (char *)port_avail_credit_info, &size);

    ret = dsmi_exe_get_info(device_id, DS_GET_CREDIT_INFO, &info);
    if (ret != 0) {
        hccn_err("dsmi get credit info failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_get_device_netdev_list_info(int dev_id, struct dsmi_netdev_list_info *netdev_list_info)
{
    struct command_context ctx = {0};
    struct dsmi_info info = {0};
    struct dsmi_netdev_info_data result_data = {0};
    unsigned int size = 0;
    int i;
    int ret;
    int err;

    size = sizeof(struct dsmi_netdev_info_data);
    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), NULL, 0, (char *)&result_data, &size);

    ret = dsmi_exe_get_info(dev_id, DS_GET_ALL_NETDEV_INFO, &info);
    if (ret != 0) {
        hccn_err("dsmi get device netdev list info failed. (ret=%d)", ret);
        return ret;
    }
    if (result_data.num == 0) {
        hccn_err("dsmi get device netdev list info failed. (num=0)");
        return DRV_ERROR_INNER_ERR;
    }

    netdev_list_info->netdev_nums = 0;
    for (i = 0; i < result_data.num; i++) {
        if (netdev_list_info->netdev_nums >= NETDEV_MAX_NUM) {
            hccn_err("Maximum netdevs reached (%d)", NETDEV_MAX_NUM);
            return DRV_ERROR_PARA_ERROR;
        }

        if (result_data.data[i].is_bond == 1) {
            err = strncpy_s(netdev_list_info->netdev_name[netdev_list_info->netdev_nums],
                            IFNAMSIZ,
                            result_data.data[i].ifname,
                            IFNAMSIZ - 1);
            if (err != 0) {
                hccn_err("device_netdev_list_info strncpy fail,err:(%d)", err);
                return err;
            }
            netdev_list_info->netdev_nums++;
        }
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_get_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway_addr)
{
    int ret = 0;
    struct command_context ctx = {0};
    struct dsmi_info info = {0};
    unsigned int gw_addr;
    unsigned int size_out = sizeof(unsigned int);

    if (netdev_name == NULL || gateway_addr == NULL) {
        hccn_err("Input param is invalid, netdev_name or gateway_addr is NULL.");
        return DRV_ERROR_INVALID_VALUE;
    }

    if (netdev_name_len == 0 || netdev_name_len > MAX_DEV_NAME_LEN - 1) {
        hccn_err("Invalid netdev_name_len: %u", netdev_name_len);
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = logic_id;
    ctx.result = (char *)&gw_addr;
    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != 0) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), NULL, 0, ctx.result, &size_out);

    ret = dsmi_exe_get_info(logic_id, DS_GET_DEFAULT_GATEWAY, &info);
    if (ret != 0) {
        hccn_err("dsmi get bond gateway address failed. (ret=%d)", ret);
        return ret;
    }

    ret = memcpy_s(gateway_addr->u_addr.ip4, sizeof(gateway_addr->u_addr.ip4), &gw_addr, sizeof(gw_addr));
    if (ret != 0) {
        hccn_err("memcpy_s for gateway_addr failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_set_netdev_gateway(int logic_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_ip_addr *gateway_addr)
{
    int ret = 0;
    struct dsmi_board_info_stru pboard_info = {0};
    struct command_context ctx = {0};
    struct dsmi_gateway_cmd_args gw_args = {0};
    struct dsmi_info info = {0};
    char ip_str[INET_ADDRSTRLEN] = {0};
    unsigned int size = 0;

    if (netdev_name == NULL || gateway_addr == NULL) {
        hccn_err("Input param is invalid, netdev_name or gateway_addr is NULL.");
        return DRV_ERROR_INVALID_VALUE;
    }

    ret = memcpy_s(&gw_args.gw_addr.ip_addr, sizeof(gw_args.gw_addr.ip_addr),
        gateway_addr->u_addr.ip4, sizeof(gateway_addr->u_addr.ip4));
    CHK_PRT_RETURN(ret != 0, hccn_err("memcpy_s for gateway_addr failed. (ret=%d)", ret), ret);

    ret = dsmi_get_board_info(logic_id, &pboard_info);
    if (ret != 0) {
        hccn_err("dsmi get board info failed. (ret=%d)", ret);
        return ret;
    }
    ctx.slot_id = (int)pboard_info.slot_id;
    ctx.cmd_args = (void *)&gw_args;
    ctx.npu_info.logic_id = logic_id;
    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != 0) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return ret;
    }

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context),
        (char *)ctx.cmd_args, sizeof(struct dsmi_gateway_cmd_args), NULL, &size);

    ret = dsmi_exe_get_info(logic_id, DS_SET_DEFAULT_GATEWAY, &info);
    if (ret != 0) {
        hccn_err("dsmi set bond gateway address failed. (ret=%d)", ret);
        return ret;
    }

    if (!tool_check_conf_udhcpc_enable(logic_id)) {
        if (inet_ntop(AF_INET, gateway_addr->u_addr.ip4, ip_str, sizeof(ip_str)) == NULL) {
            hccn_err("convert IPv4 to string failed.");
            return DRV_ERROR_INNER_ERR;
        }
        ret = tool_write_conf(ctx.slot_id, "gateway", ip_str);
        if (ret != 0) {
            hccn_err("write cfg error, ret:%d logic_id:%d", ret, logic_id);
            return DRV_ERROR_INNER_ERR;
        }
    }

    return DRV_ERROR_NONE;
}

EXPORT_FUNCTION int dsmi_get_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
                                             char *mac_addr, unsigned int mac_addr_len)
{
    struct command_context ctx = {0};
    unsigned int size = sizeof(struct dsmi_mac_val);
    struct dsmi_mac_val mac_address = {0};
    struct dsmi_info info = {0};
    int ret;

    if (mac_addr_len < DSMI_MAC_ADDR_LEN) {
        hccn_err("Buffer length too small: %u, need at least %d", mac_addr_len, DSMI_MAC_ADDR_LEN);
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = dev_id;
    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != EOK) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d, netdev_name_len=%u)", ret, netdev_name_len);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context),
                   NULL, 0, (char *)&mac_address, &size);

    ret = dsmi_exe_get_info(ctx.npu_info.logic_id, DS_GET_MAC_ADDR, &info);
    if (ret != 0) {
        hccn_err("dsmi get bond mac_addr address failed. (ret=%d)", ret);
        return ret;
    }

    ret = memcpy_s(mac_addr, mac_addr_len, mac_address.mac_pieces, DSMI_MAC_ADDR_LEN);
    if (ret != EOK) {
        hccn_err("memcpy_s for mac_addr failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    return DRV_ERROR_NONE;
}

EXPORT_FUNCTION int dsmi_set_netdev_mac_addr(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
                                             const char *mac_addr, unsigned int mac_addr_len)
{
    struct command_context ctx = {0};
    struct dsmi_mac_val mac_args = {0};
    struct dsmi_info info = {0};
    struct dsmi_board_info_stru pboard_info = {0};
    char mac_addr_string[DSMI_MAC_STR_LEN + 1] = {0};
    int ret;
    unsigned int size = 0;

    if (mac_addr_len < DSMI_MAC_ADDR_LEN) {
        hccn_err("Invalid mac_addr_len: %u, need at least %d", mac_addr_len, DSMI_MAC_ADDR_LEN);
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = dev_id;
    ret = dsmi_get_board_info(ctx.npu_info.logic_id, &pboard_info);
    if (ret != EOK) {
        hccn_err("dsmi get board info failed. (ret=%d)", ret);
        return ret;
    }
    ctx.slot_id = (int)pboard_info.slot_id;

    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != EOK) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    ret = memcpy_s(mac_args.mac_pieces, DSMI_MAC_ADDR_LEN, mac_addr, mac_addr_len);
    if (ret != EOK) {
        hccn_err("memcpy_s for mac_addr failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    ret = snprintf_s(mac_addr_string, DSMI_MAC_STR_LEN + 1, DSMI_MAC_STR_LEN,
                     "%02x:%02x:%02x:%02x:%02x:%02x",
                     DSMI_MAC_ADDR_ARGS(mac_args.mac_pieces));
    if (ret < 0) {
        hccn_err("snprintf_s for mac_addr_string failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context),
                   (char *)&mac_args, sizeof(struct dsmi_mac_val), NULL, &size);

    ret = dsmi_exe_get_info(ctx.npu_info.logic_id, DS_SET_MAC_ADDR, &info);
    if (ret != 0) {
        hccn_err("dsmi set bond mac_addr address failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_write_conf(ctx.slot_id, "mac_addr", mac_addr_string);
    if (ret != 0) {
        hccn_err("write cfg error, ret:%d", ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}

EXPORT_FUNCTION int dsmi_get_device_bond_ip_address(int device_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address)
{
    int ret;

    struct command_context ctx = {0};
    struct ip_netmask_val ip_netmask;
    struct dsmi_info info = {0};
    unsigned int size;

    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != 0) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    size = sizeof(struct ip_netmask_val);
    ctx.result = (char *)&ip_netmask;
    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), NULL, 0, ctx.result, &size);

    ret = dsmi_exe_get_info(device_id, DS_GET_IP, &info);
    if (ret != 0) {
        hccn_err("get ip info failed. (ret=%d)", ret);
        return ret;
    }

    ip_address->ip_type = DCMI_IPADDR_TYPE_V4;
    mask_address->ip_type = DCMI_IPADDR_TYPE_V4;

    ip_address->u_addr.ip4[IP_BYTE_INDEX_1] = SPLIT_UIP(ip_netmask.ip, IP_SPLIT_BIT_0);
    ip_address->u_addr.ip4[IP_BYTE_INDEX_2] = SPLIT_UIP(ip_netmask.ip, IP_SPLIT_BIT_8);
    ip_address->u_addr.ip4[IP_BYTE_INDEX_3] = SPLIT_UIP(ip_netmask.ip, IP_SPLIT_BIT_16);
    ip_address->u_addr.ip4[IP_BYTE_INDEX_4] = SPLIT_UIP(ip_netmask.ip, IP_SPLIT_BIT_24);

    mask_address->u_addr.ip4[IP_BYTE_INDEX_1] = SPLIT_UIP(ip_netmask.netmask, IP_SPLIT_BIT_0);
    mask_address->u_addr.ip4[IP_BYTE_INDEX_2] = SPLIT_UIP(ip_netmask.netmask, IP_SPLIT_BIT_8);
    mask_address->u_addr.ip4[IP_BYTE_INDEX_3] = SPLIT_UIP(ip_netmask.netmask, IP_SPLIT_BIT_16);
    mask_address->u_addr.ip4[IP_BYTE_INDEX_4] = SPLIT_UIP(ip_netmask.netmask, IP_SPLIT_BIT_24);

    return ret;
}

STATIC int dsmi_write_ip_conf(struct command_context *ctx, const char *address, const char *netmask)
{
    int ret;

    ret = tool_write_conf(ctx->slot_id, "address", address);
    if (ret != 0) {
        hccn_err("write address cfg error. (ret=%d; phy_id=%d; logic_id=%d)", ret, ctx->dev_id, ctx->npu_info.logic_id);
        return ret;
    }

    ret = tool_write_conf(ctx->slot_id, "netmask", netmask);
    if (ret != 0) {
        hccn_err("write netmask cfg error. (ret=%d; phy_id=%d; logic_id=%d)", ret, ctx->dev_id, ctx->npu_info.logic_id);
        return ret;
    }

    return 0;
}

STATIC int convert_ip_addr_to_ip_args(struct ip_val *ip_addr, struct dsmi_ip_addr *ip_address)
{
    int ret;

    if (ip_addr == NULL) {
        hccn_err("ip_addr is null.");
        return DRV_ERROR_INVALID_VALUE;
    }

    ip_addr->ip_addr = ((unsigned int)ip_address->u_addr.ip4[IP_BYTE_INDEX_4] << IP_SPLIT_BIT_24) |
                         ((unsigned int)ip_address->u_addr.ip4[IP_BYTE_INDEX_3] << IP_SPLIT_BIT_16) |
                         ((unsigned int)ip_address->u_addr.ip4[IP_BYTE_INDEX_2] << IP_SPLIT_BIT_8) |
                         ((unsigned int)ip_address->u_addr.ip4[IP_BYTE_INDEX_1]);
    ret = snprintf_s(ip_addr->str_ip, MAX_IP_VAL_LEN, MAX_IP_VAL_LEN - 1, "%d.%d.%d.%d",
                     ip_address->u_addr.ip4[IP_BYTE_INDEX_1], ip_address->u_addr.ip4[IP_BYTE_INDEX_2],
                     ip_address->u_addr.ip4[IP_BYTE_INDEX_3], ip_address->u_addr.ip4[IP_BYTE_INDEX_4]);
    if (ret < 0) {
        hccn_err("snprintf_s fail. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_set_device_bond_ip_address(int device_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dsmi_ip_addr *ip_address, struct dsmi_ip_addr *mask_address)
{
    int ret;
    struct command_context ctx = {0};
    strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    ctx.npu_info.logic_id = device_id;
    struct dsmi_board_info_stru pboard_info;
    struct ip_cmd_args ip_args;
    struct dsmi_info info = {0};
    unsigned int size = 0;

    ret = convert_ip_addr_to_ip_args(&ip_args.ip, ip_address);
    if (ret != 0) {
        hccn_err("convert_ip_addr_to_ip_args failed. (ret=%d)", ret);
        return ret;
    }

    ret = convert_ip_addr_to_ip_args(&ip_args.netmask, mask_address);
    if (ret != 0) {
        hccn_err("convert_ip_addr_to_ip_args failed. (ret=%d)", ret);
        return ret;
    }

    ctx.cmd_args = &ip_args;

    DSMI_FILL_INFO(info, (char *)&ctx, sizeof(struct command_context), (char *)&ip_args, sizeof(struct ip_cmd_args),
                   NULL, &size);

    ret = is_ipaddr_conflict(&ctx);
    if (ret != 0) {
        hccn_err("ipaddr conflict. (address=%s; netmask=%s)", ip_args.ip.str_ip, ip_args.netmask.str_ip);
        return ret;
    }

    ret = dsmi_exe_get_info(ctx.npu_info.logic_id, DS_SET_IP, &info);
    if (ret != 0) {
        hccn_err("set ip failed. (logic_id=%d; dev_name=%s; ret=%d)", ctx.npu_info.logic_id, ctx.dev_name, ret);
        return ret;
    }

    ret = dsmi_get_board_info(ctx.npu_info.logic_id, &pboard_info);
    if (ret != 0) {
        hccn_err("dsmi_get_board_info failed. (logic_id=%d; ret=%d)", ctx.npu_info.logic_id, ret);
        return ret;
    }
    ctx.slot_id = (int)pboard_info.slot_id;

    if (!tool_check_conf_udhcpc_enable(ctx.slot_id)) {
        ret = dsmi_write_ip_conf(&ctx, ip_args.ip.str_ip, ip_args.netmask.str_ip);
        if (ret != 0) {
            hccn_err("write ip cfg error! (ret=%d; logic_id=%d; address=%s; netmask=%s)", ret,
                     ctx.npu_info.logic_id, ip_args.ip.str_ip, ip_args.netmask.str_ip);
            return ret;
        }
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_start_ubping_mesh_proc(int device_id, struct ubping_mesh_operate *operate)
{
    struct product_channel_msg msg = {0};
    struct command_context ctx = {0};
    int ret = 0, result = 0;
    if (operate == NULL) {
        hccn_err("get operate is NULL");
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = device_id;
    SET_PRODUCT_MSG(msg, (char *)operate, sizeof(struct ubping_mesh_operate), &result, sizeof(int));
    ret = product_host_device_channel(&ctx, CMD_START_PINGMESH_TASK, &msg);
    if (ret) {
        hccn_err("Start ubping mesh task failed. (ret=%d, device_id=%d)", ret, device_id);
    }
    return ret;
}

EXPORT_FUNCTION int dsmi_stop_ubping_mesh_proc(int device_id)
{
    struct product_channel_msg msg = {0};
    int ret, result = 0, stop_info = 0;
    struct command_context ctx = {0};

    ctx.npu_info.logic_id = device_id;
    SET_PRODUCT_MSG(msg, (char *)&stop_info, sizeof(int), &result, sizeof(int));
    ret = product_host_device_channel(&ctx, CMD_STOP_PINGMESH_TASK, &msg);
    if (ret) {
        hccn_err("get ub_ping info failed. (ret=%d, device_id=%d)", ret, device_id);
    }
    return ret;
}

EXPORT_FUNCTION int dsmi_get_ubping_mesh_info_proc(int device_id, struct ubping_mesh_info *result_info)
{
    struct ubping_mesh_info ubping_mesh_result = {0};
    struct product_channel_msg msg = {0};
    struct command_context ctx = {0};
    int ret = 0;
    if (result_info == NULL) {
        hccn_err("dsmi get ubping mesh result info is NULL.");
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = device_id;
    SET_PRODUCT_MSG(msg, NULL, 0, &ubping_mesh_result, sizeof(struct ubping_mesh_info));
    ret = product_host_device_channel(&ctx, CMD_GET_PINGMESH_RESULT, &msg);
    if (ret) {
        hccn_err("Get ubping mesh task stat failed. (ret=%d, device_id=%d)", ret, device_id);
        return ret;
    }
    result_info->result_num = ubping_mesh_result.result_num;
    for (int i = 0; i < result_info->result_num; i++) {
        ret = memcpy_s(&(result_info->ub_ping_result[i]), sizeof(struct ubping_mesh_result),
                       &(ubping_mesh_result.ub_ping_result[i]), sizeof(struct ubping_mesh_result));
        if (ret != 0) {
            hccn_err("memcpy failed. (ret=%d, device_id=%d, result_id=%d)", ret, device_id, i);
            return ret;
        }
        if ((result_info->ub_ping_result[i].suc_pkt_num == 0) && (result_info->ub_ping_result[i].fail_pkt_num != 0)) {
            result_info->ub_ping_result[i].avg_time_us = INVALID_TIME_RESULT;
            result_info->ub_ping_result[i].max_time_us = INVALID_TIME_RESULT;
            result_info->ub_ping_result[i].min_time_us = INVALID_TIME_RESULT;
            result_info->ub_ping_result[i].tp95_time_us = INVALID_TIME_RESULT;
        }
    }
    return ret;
}

EXPORT_FUNCTION int dsmi_get_ubping_mesh_state_proc(int device_id, unsigned int *state)
{
    struct product_channel_msg msg = {0};
    struct command_context ctx = {0};
    unsigned int result = 0;
    int ret = 0;

    if (state == NULL) {
        return DRV_ERROR_INVALID_VALUE;
    }

    ctx.npu_info.logic_id = device_id;

    SET_PRODUCT_MSG(msg, NULL, 0, &result, sizeof(unsigned int));
    ret = product_host_device_channel(&ctx, CMD_GET_PINGMESH_STAT, &msg);
    if (ret) {
        hccn_err("Get ubping mesh state failed. (ret=%d, device_id=%d)", ret, device_id);
        return ret;
    }
    *state = result;
    return ret;
}

STATIC int copy_pfc_duration_info(struct dcmi_bond_pfc_duration_info *pfc_duration_info,
    struct pfc_stat_info_t *pfc_info)
{
    int ret;
    unsigned int i;

    for (i = 0; i < MAX_PRI_NUM; i++) {
        pfc_duration_info->slave0_tx[i] = pfc_info[0].pfc_time.pfc_tx[i];
        pfc_duration_info->slave0_rx[i] = pfc_info[0].pfc_time.pfc_rx[i];
        pfc_duration_info->slave1_tx[i] = pfc_info[1].pfc_time.pfc_tx[i];
        pfc_duration_info->slave1_rx[i] = pfc_info[1].pfc_time.pfc_rx[i];
    }

    ret = strncpy_s((char *)pfc_duration_info->slave0_name, NETDEV_NAME_MAX_LEN, pfc_info[0].slave_name, SLAVE_NAME_LEN - 1);
    if (ret != 0) {
        hccn_err("strncpy_s for bond slave0 name failed. (ret=%d)", ret);
        return ret;
    }

    ret = strncpy_s((char *)pfc_duration_info->slave1_name, NETDEV_NAME_MAX_LEN, pfc_info[1].slave_name, SLAVE_NAME_LEN - 1);
    if (ret != 0) {
        hccn_err("strncpy_s for bond slave1 name failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_get_netdev_pfc_duration_info(int logic_id, const char *netdev_name,
    unsigned int netdev_name_len, struct dcmi_bond_pfc_duration_info *pfc_duration_info)
{
    int ret = 0;
    struct command_context ctx = {0};
    struct product_channel_msg msg = {0};
    struct pfc_stat_info_t pfc_info[BOND_SLAVE_NUM] = {0};

    ctx.npu_info.logic_id = logic_id;
    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != 0) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return ret;
    }

    SET_PRODUCT_MSG(msg, NULL, 0, &pfc_info, sizeof(pfc_info));

    ret = product_host_device_channel(&ctx, CMD_GET_PFC_STAT, &msg);
    if (ret != 0) {
        hccn_err("Failed to obtain the pfc_stat backpressure time. (ret=%d)", ret);
        return ret;
    }

    ret = copy_pfc_duration_info(pfc_duration_info, pfc_info);
    if (ret != 0) {
        hccn_err("copy_pfc_duration_info faild. (ret=%d)", ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}

EXPORT_FUNCTION int dsmi_clear_netdev_pfc_duration_info(int logic_id, const char *netdev_name,
    unsigned int netdev_name_len)
{
    int ret = 0;
    struct command_context ctx = {0};
    struct product_channel_msg msg = {0};

    ctx.npu_info.logic_id = logic_id;
    ret = strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);
    if (ret != 0) {
        hccn_err("strncpy_s for netdev_name failed. (ret=%d)", ret);
        return ret;
    }

    SET_PRODUCT_MSG(msg, NULL, 0, NULL, 0);

    ret = product_host_device_channel(&ctx, CMD_SET_PFC_STAT, &msg);
    if (ret != 0) {
        hccn_err("Failed to clear the pfc_stat backpressure time. (ret=%d)", ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}

static int traceroute_reset(struct command_context *ctx)
{
    struct dsmi_info info = {0};
    unsigned int size = 0;
    int ret = 0;

    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, NULL, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_RESET_TRACEROUTE, &info);
    if (ret != 0) {
        hccn_err("tool traceroute reset status failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    return 0;
}

static int traceroute_start(struct command_context *ctx, struct traceroute_info *traceroute_args)
{
    enum traceroute_status troute_status = TRACEROUTE_STATUS_HALT;
    unsigned int size = sizeof(enum traceroute_status);
    struct dsmi_info info = {0};
    int ret = 0;

    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), (char *)traceroute_args,
                   sizeof(struct traceroute_info), (char *)&troute_status, &size);
    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_START_TRACEROUTE, &info);

    if (troute_status == TRACEROUTE_STATUS_RUNNING) {
        return DRV_ERROR_BUSY;
    }
    if (troute_status == TRACEROUTE_STATUS_ERROR) {
        ret = traceroute_reset(ctx);
        if (ret != 0) {
            hccn_err("get status_error, try to reset traceroute failed. (ret=%d; logic_id=%d)", ret,
                     ctx->npu_info.logic_id);
            return ret;
        }
    }

    return 0;
}

static int traceroute_get_status(struct command_context *ctx, enum traceroute_status *troute_status)
{
    unsigned int size = sizeof(enum traceroute_status);
    struct dsmi_info info = {0};
    int ret = 0;

    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, (char *)troute_status, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_TRACEROUTE_STATUS, &info);
    if (ret != 0) {
        hccn_err("dsmi get traceroute status failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    return 0;
}

static int traceroute_waiting_finish(struct command_context *ctx)
{
    enum traceroute_status status = TRACEROUTE_STATUS_HALT;
    int wait_num = MAX_TRACEROUTE_WAITING_TIMES;
    int ret = 0;

    while (wait_num > 0) {
        ret = traceroute_get_status(ctx, &status);
        if (ret != 0) {
            hccn_err("tool traceroute get status failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
            return ret;
        }

        if (status == TRACEROUTE_STATUS_HALT) {
            break;
        } else if (status == TRACEROUTE_STATUS_ERROR) {
            return DRV_ERROR_INNER_ERR;
        }

        wait_num--;
        if (wait_num <= 0) {
            hccn_err("tool wait traceroute finish timeout. (logic_id=%d)", ctx->npu_info.logic_id);
            return DRV_ERROR_WAIT_TIMEOUT;
        }

        sleep(1);
    }

    return 0;
}

static int traceroute_get_output(struct command_context *ctx, char *traceroute_output, unsigned int output_size)
{
    unsigned int size = output_size - 1;
    struct dsmi_info info = {0};
    int ret = 0;

    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, traceroute_output, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_TRACEROUTE_INFO, &info);
    if (ret != 0) {
        hccn_err("dsmi get traceroute info failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    size = (unsigned int)strlen(traceroute_output);
    while (size != 0 && (traceroute_output[size - 1] == '\n')) {
        traceroute_output[size - 1] = '\0';
        size = (unsigned int)strlen(traceroute_output);
    }

    return 0;
}

static void traceroute_fill_response_data(struct traceroute_result *result_data, char **context,
                                          int loss_pkt, char **tmp_token)
{
    char *token = NULL;
    int i = 0;
    double last_time = 0, avg_time;
    double best_time = TRACEROUTE_OUTPUT_MAX_TIME, wrst_time = 0, all_time = 0,
           response_time[TRACEROUTE_PACKETS_SENT_NUM] = {0}, square_sum = 0, loss_num = loss_pkt;

    for (i = loss_pkt; i < TRACEROUTE_PACKETS_SENT_NUM; i++) {
        token = strtok_s(NULL, " ", context);
        *tmp_token = token;
        if (*token == '\0') {
            return;
        }

        if (strcmp(token, "!H") == 0) { // 检测到该字符串表示目的不可达: 1  ... 0.173 ms !H 0.131 ms !H ...
            result_data->func_mask = TRACEROUTE_DSET_UNREACHABLE;
            result_data->loss = PERCENT_NUM;
            return;
        }

        if (*token == '*') {
            loss_num++;
        } else {
            last_time = strtod(token, NULL);
            response_time[i] = last_time;
            all_time += last_time;
            best_time = best_time < last_time ? best_time : last_time;
            wrst_time = wrst_time > last_time ? wrst_time : last_time;
            token = strtok_s(NULL, " ", context); // 响应时间值与单位ms间有空格，需跳过单位: 1  ... 0.173 ms  0.131 ms ...
            *tmp_token = token;
        }
    }

    result_data->loss = loss_num / TRACEROUTE_PACKETS_SENT_NUM * PERCENT_NUM;
    if (loss_num == TRACEROUTE_PACKETS_SENT_NUM) {
        result_data->func_mask = TRACEROUTE_OUTPUT_ALL_LOSS;
        return;
    }
    avg_time = all_time / (TRACEROUTE_PACKETS_SENT_NUM - loss_num);

    result_data->last = last_time;
    result_data->avg = avg_time;
    result_data->best = best_time;
    result_data->wrst = wrst_time;

    for (i = 0; i < TRACEROUTE_PACKETS_SENT_NUM; i++) {
        if (response_time[i] != 0) {
            square_sum += (response_time[i] - avg_time) * (response_time[i] - avg_time);
        }
    }
    // 此处是方差而不是标准差，由于device侧编译问题，开方在dcmi处理
    result_data->stdev = square_sum / (TRACEROUTE_PACKETS_SENT_NUM - loss_num);
}

static int traceroute_skip_loss_tokens(char **context, int *loss_pkt, char **tmp_token,
                                       struct traceroute_result *result_data)
{
    char *token = NULL;

    // traceroute回显可能有*号在ip前面的情况: 1  * 10.20.0.31 (10.20.0.31) 0.173 ms  0.131 ms xxx
    while (*loss_pkt < TRACEROUTE_PACKETS_SENT_NUM) {
        token = strtok_s(NULL, " ", context);
        if (token == NULL) {
            hccn_err("Strtok context causes token null during loss skip.");
            return -EINVAL;
        }
        *tmp_token = token;

        if (*token == '*') {
            (*loss_pkt)++;  // 注意加括号，避免歧义
        } else {
            break;
        }
    }

    // 节点带3个*号的情况（即全部丢包）
    if (*loss_pkt == TRACEROUTE_PACKETS_SENT_NUM && *token == '*') {
        result_data->loss = PERCENT_NUM;
        result_data->func_mask = TRACEROUTE_OUTPUT_ALL_LOSS;
        return 0;
    }

    return 0;
}

static int traceroute_get_string_to_struct(struct traceroute_result *result_data,
                                           char **context, char **tmp_token, const char *src_ip)
{
    int ret, len, loss_pkt = 0;
    char *token = NULL;

    ret = traceroute_skip_loss_tokens(context, &loss_pkt, tmp_token, result_data);
    if (ret != 0) {
        return ret; // 解析失败直接返回
    }
    if (result_data->func_mask == TRACEROUTE_OUTPUT_ALL_LOSS) {
        return 0;   // 全部丢包已处理，直接退出
    }

    // 根据traceroute的回显结果，路由节点信息包含节点名称，需丢弃名称，只填充括号内IP地址: 1  10.20.0.31 (10.20.0.31)  ...
    token = strtok_s(NULL, " ", context);
    if (token == NULL) {
        result_data->func_mask = 0;
        hccn_err("Strtok context causes token null.");
        return -EINVAL;
    }
    *tmp_token = token;

    len = strlen(token);
    if (token[0] != '(' || token[len - 1] != ')') {
        result_data->func_mask = 0;
        hccn_err("IP string is invalid. (len=%d; token=%s)", len, token);
        return -EINVAL;
    }

    token[len - 1] = '\0';
    ret = memmove_s(token, len - 1, token + 1, len - 1);
    if (ret != 0) {
        hccn_err("traceroute get string memmove_s failed. (ret=%d)", ret);
        return ret;
    }

    if (src_ip != NULL) {
        ret = strcpy_s(result_data->src_ip, IP_MAX_LEN, src_ip);
        if (ret != 0) {
            hccn_err("Dsmi get string src_ip strcpy failed. (ret=%d)", ret);
            return ret;
        }
    }

    ret = strcpy_s(result_data->dst_ip, IP_MAX_LEN, (const char *)token);
    if (ret != 0) {
        hccn_err("Dsmi get string dest_ip strcpy failed. (ret=%d)", ret);
        return ret;
    }

    traceroute_fill_response_data(result_data, context, loss_pkt, tmp_token);
    return 0;
}

static int traceroute_trans_node_info(char *troute_output, unsigned int *result_nums,
                                      struct traceroute_result *result_data, const char *src_ip)
{
    int ret, len;
    int str_index = 0, tmp_index = 0;
    size_t node_info_size = sizeof(struct traceroute_result);
    size_t out_index = *result_nums;
    struct traceroute_result tmp_node_info = {0};
    char *tmp_token = NULL, *context = NULL;

    // traceroute正常应答回显: 1  10.20.0.31 (10.20.0.31)  0.173 ms  0.131 ms  0.120 ms\n
    while (troute_output[str_index] != '\0') {
        if (troute_output[str_index + TRACEROUTE_OUTPUT_INDEX_TWO] == '\0') {
            return -EINVAL;
        }

        if (troute_output[str_index] == 's' && troute_output[str_index + 1] == '\n' &&
            troute_output[str_index + TRACEROUTE_OUTPUT_INDEX_TWO] == ' ') {
            str_index += TRACEROUTE_OUTPUT_INDEX_TWO;
            break;
        } else {
            str_index++;
        }
    }

    tmp_token = strtok_s(troute_output + str_index, " ", &context);
    while (tmp_token != NULL && (out_index > 0 && out_index <= TRACEROUTE_TTL_MAX)) {
        if (*tmp_token == '\0') {
            break;
        }
        tmp_index++;
        tmp_node_info.func_mask = TRACEROUTE_OUTPUT_ALL_EFFECTIVE;
        tmp_node_info.snt = TRACEROUTE_PACKETS_SENT_NUM;

        ret = traceroute_get_string_to_struct(&tmp_node_info, &context, &tmp_token, src_ip);
        if (ret != 0) {
            hccn_err("traceroute_get_string_to_struct failed. (ret=%d)", ret);
            return ret;
        }

        ret = memcpy_s(&(((struct traceroute_result *)(void *)result_data)[tmp_index - 1]), node_info_size,
                       &tmp_node_info, node_info_size);
        if (ret != 0) {
            hccn_err("memcpy_s in traceroute get info failed. (ret=%d)", ret);
            return ret;
        }
        // 读取到的三种结尾情况
        // 1). ms\n                 ---- 需要strtok
        // 2). ms\0                 ---- 需要strtok
        // 3). ms\n12               ---- 不能strtok
        out_index--;
        len = strlen(tmp_token) - 1;
        if (tmp_token[len] >= '0' && tmp_token[len] <= '9') {
            continue;
        }
        tmp_token = strtok_s(NULL, " ", &context);
    }

    *result_nums = (unsigned int)tmp_index;
    return 0;
}

static int convert_traceroute_info(struct traceroute_info *traceroute_args,
                                   struct dsmi_traceroute_param *traceroute_info)
{
    int ret;

    traceroute_args->max_ttl = traceroute_info->max_ttl;
    traceroute_args->tos = traceroute_info->tos;
    traceroute_args->waittime = traceroute_info->waittime;
    traceroute_args->sport = traceroute_info->src_port;
    traceroute_args->dport = traceroute_info->dst_port;
    traceroute_args->reset_flag = traceroute_info->reset_flag;

    ret = strncpy_s(traceroute_args->src_ip.str_ip, IP_MAX_LEN, traceroute_info->src_ip,
                    strlen(traceroute_info->src_ip));
    if (ret != 0) {
        hccn_err("src_ip addr strncpy failed! (ret=%d; str_ip_len=%zu)", ret, strlen(traceroute_info->src_ip));
        return ret;
    }

    ret = strncpy_s(traceroute_args->dst_ip.str_ip, IP_MAX_LEN, traceroute_info->dst_ip,
                    strlen(traceroute_info->dst_ip));
    if (ret != 0) {
        hccn_err("dest_ip addr strncpy failed! (ret=%d; str_ip_len=%zu)", ret, strlen(traceroute_info->dst_ip));
        return ret;
    }

    return 0;
}

static int dsmi_exec_bond_traceroute_main(struct command_context *ctx, struct traceroute_info *traceroute_args,
                                          char *traceroute_output)
{
    int ret;

    ret = traceroute_start(ctx, traceroute_args);
    if (ret != 0) {
        hccn_err("tool traceroute start failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    ret = traceroute_waiting_finish(ctx);
    if (ret != 0) {
        hccn_err("waiting traceroute finish failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    ret = traceroute_get_output(ctx, traceroute_output, OUTBUF_LEN_32K);
    if (ret != 0) {
        hccn_err("tool traceroute get output failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    return 0;
}

EXPORT_FUNCTION int dsmi_exec_bond_traceroute(int device_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dsmi_traceroute_param *traceroute_info, struct dsmi_traceroute_result *result)
{
    int ret;
    char *traceroute_output = NULL;
    struct command_context ctx = {0};
    struct dsmi_board_info_stru pboard_info = {0};
    struct traceroute_info traceroute_args;

    strncpy_s(ctx.dev_name, sizeof(ctx.dev_name), netdev_name, netdev_name_len);

    if (traceroute_info == NULL) {
        hccn_err("traceroute_info is NULL");
        return DRV_ERROR_INVALID_VALUE;
    }

    if (traceroute_info->reset_flag) {
        return traceroute_reset(&ctx);
    }

    ret = dsmi_get_board_info(device_id, &pboard_info);
    if (ret != 0) {
        hccn_err("dsmi get board info failed. (ret=%d)", ret);
        return ret;
    }

    ctx.slot_id = (int)pboard_info.slot_id;
    ctx.npu_info.logic_id = device_id;

    ret = convert_traceroute_info(&traceroute_args, traceroute_info);
    if (ret != 0) {
        hccn_err("convert param_in to traceroute_info failed. (ret=%d)", ret);
        return ret;
    }

    ctx.cmd_args = &traceroute_args;

    traceroute_output = (char *)calloc(OUTBUF_LEN_32K, sizeof(char));
    if (traceroute_output == NULL) {
        hccn_err("calloc traceroute_output failed.");
        return -ENOMEM;
    }

    ret = dsmi_exec_bond_traceroute_main(&ctx, &traceroute_args, traceroute_output);
    if (ret != 0) {
        hccn_err("dsmi_exec_bond_traceroute_main failed. (ret=%d; logic_id=%d)", ret, ctx.npu_info.logic_id);
        goto out;
    }

    ret = traceroute_trans_node_info(traceroute_output, &result->result_nums, result->result_data,
                                     traceroute_args.src_ip.str_ip);
    if (ret != 0) {
        hccn_err("traceroute info trans failed. (ret=%d; logic_id=%d)", ret, ctx.npu_info.logic_id);
    }

out:
    FREE_BUF(traceroute_output);
    return ret;
}
