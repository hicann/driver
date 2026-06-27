/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "securec.h"
#include "ds_net_interface.h"
#include "hccn_err.h"
#include "tool_param.h"
#include "dev_info_data.h"
#include "tool_comm.h"
#include "tool_cmd_err.h"
#include "tool_dev_info.h"

void tool_info_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_info_print_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-dev_info", "get device info");
            tool_print_npu_info(DEV_NPU_ATTR);
            break;
        default:
            break;
    }
}

STATIC void tool_print_port_info(struct port_info_data *result)
{
#define PORT_INFO_LINE_FMT   "+%-7s+%-7s+%-19s+%-9s+%-11s+%-10s+"
#define PORT_INFO_HEADER_FMT "| %-7s | %-7s | %-19s | %-9s | %-11s | %-10s |"
#define PORT_INFO_DATA_FMT   "| %-7u | %-7u | %-19u | %-9s | %-11s | %-10s |"
    struct port_info *info = NULL;
    unsigned int i;

    // no need to print header
    if (result->num == 0) {
        return;
    }

    TOOL_PRINT_INFO(PORT_INFO_LINE_FMT, LINE_BAR_7, LINE_BAR_7, LINE_BAR_19, LINE_BAR_9, LINE_BAR_11, LINE_BAR_10);
    TOOL_PRINT_INFO(PORT_INFO_HEADER_FMT, "UDie ID", "Port ID", "Speed Ability(Gbps)",
        "Port Type", "Link Status", "Media Type");
    TOOL_PRINT_INFO(PORT_INFO_LINE_FMT, LINE_BAR_7, LINE_BAR_7, LINE_BAR_19, LINE_BAR_9, LINE_BAR_11, LINE_BAR_10);
    for (i = 0; i < MIN(result->num, DEV_INFO_MAX_PORT_NUM); i++) {
        info = &result->data[i];
        TOOL_PRINT_INFO(PORT_INFO_DATA_FMT, info->udie_id, info->port_id, info->speed_ability,
            GET_PORT_TYPE_STR(info->port_type), GET_LINK_STATUS_STR(info->link_status),
            GET_MEDIA_TYPE_STR(info->media_type));
    }
    TOOL_PRINT_INFO(PORT_INFO_LINE_FMT, LINE_BAR_7, LINE_BAR_7, LINE_BAR_19, LINE_BAR_9, LINE_BAR_11, LINE_BAR_10);
    return;
}

STATIC int tool_get_all_port_info(struct command_context *ctx)
{
    struct port_info_data result_data = {0};
    struct dsmi_info info = {0};
    unsigned int size = 0;
    int ret;

    size = sizeof(result_data);
    ctx->result = (char *)&result_data;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_UBCTL_LS_INFO, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get ubctl ls info failed, ret:%d", ret), ret);

    tool_print_port_info(&result_data);
    return 0;
}

STATIC void tool_convert_sock_addr_to_str(union sockaddr_t *addr, char *buf, unsigned int buf_len)
{
    const char *str = NULL;

    (void)memset_s(buf, buf_len, 0, buf_len);
    if (addr->sa.sa_family == AF_INET) {
        str = inet_ntop(AF_INET, &addr->sa_in.sin_addr, buf, buf_len);
    } else { // addr->sa.sa_family == AF_INET6
        str = inet_ntop(AF_INET6, &addr->sa_in6.sin6_addr, buf, buf_len);
    }

    if (str == NULL) {
        hccn_err("getnameinfo failed, ret:%d", errno);
        (void)memcpy_s(buf, buf_len, NA_STR, strlen(NA_STR));
    }
    return;
}

STATIC const char *tool_convert_ifa_addr_to_str(union sockaddr_t *addr)
{
    static char buf[INET6_ADDRSTRLEN + 1] = {0};

    tool_convert_sock_addr_to_str(addr, buf, INET6_ADDRSTRLEN);
    return buf;
}

STATIC const char *tool_convert_ifa_mask_to_str(union sockaddr_t *mask)
{
    static char buf[INET6_ADDRSTRLEN + 1] = {0};

    tool_convert_sock_addr_to_str(mask, buf, INET6_ADDRSTRLEN);
    return buf;
}

STATIC void tool_print_netdev_info(struct netdev_info_data *result)
{
#define NDEV_INFO_LINE_FMT   "+%-15s+%-42s+%-42s+%-9s+%-15s+"
#define NDEV_INFO_HEADER_FMT "| %-15s | %-42s | %-42s | %-9s | %-15s |"
#define NDEV_INFO_DATA_FMT   NDEV_INFO_HEADER_FMT
    struct netdev_info *info = NULL;
    unsigned int i, j, k;

    TOOL_PRINT_INFO(NDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_42, LINE_BAR_42, LINE_BAR_9, LINE_BAR_15);
    TOOL_PRINT_INFO(NDEV_INFO_HEADER_FMT, "Interface Name", "IP Address", "Netmask", "Bond Mode", "Slaves");
    TOOL_PRINT_INFO(NDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_42, LINE_BAR_42, LINE_BAR_9, LINE_BAR_15);
    for (i = 0; i < MIN(result->num, DEV_INFO_MAX_DEV_NUM); i++) {
        info = &result->data[i];
        for (j = 0; j < info->list_size; j++) {
            for (k = 0; k < DEV_INFO_DEFAULT_BOND_SLAVE_NUM; k++) {
                TOOL_PRINT_INFO(NDEV_INFO_DATA_FMT,
                    (j == 0 && k == 0) ? info->ifname : "",
                    (k == 0) ? tool_convert_ifa_addr_to_str(&info->addr_list[j]) : "",
                    (k == 0) ? tool_convert_ifa_mask_to_str(&info->mask_list[j]) : "",
                    (j == 0 && k == 0) ? GET_IS_BOND_STR(info->is_bond, info->bond_info.bond_mode) : "",
                    (j == 0 && k == 0) ? GET_BOND_SLAVE0_STR(info->is_bond, info->bond_info.slaves_ifname[k]) :
                        ((j == 0 && k == 1) ? info->bond_info.slaves_ifname[k] : ""));
                // only bond need to print with slaves
                if (!info->is_bond) {
                    break;
                }
            }
        }
        TOOL_PRINT_INFO(NDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_42, LINE_BAR_42, LINE_BAR_9, LINE_BAR_15);
    }
}

STATIC int tool_get_all_netdev_info(struct command_context *ctx)
{
    struct netdev_info_data result_data = {0};
    struct dsmi_info info = {0};
    unsigned int size = 0;
    int ret;

    size = sizeof(result_data);
    ctx->result = (char *)&result_data;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_ALL_NETDEV_INFO, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get all netdev info failed, ret:%d", ret), ret);

    CHK_PRT_RETURN(result_data.num == 0, hccn_err("result_data.num:%u is 0", result_data.num), -EIO);
    tool_print_netdev_info(&result_data);
    return 0;
}

STATIC int tool_compare_udev_info(const void *a, const void *b)
{
    const struct udev_info *udev1 = (const struct udev_info *)a;
    const struct udev_info *udev2 = (const struct udev_info *)b;

    return strcmp(udev1->name, udev2->name);
}

STATIC void tool_print_udev_info(struct udev_info_data *result)
{
#define UDEV_INFO_LINE_FMT   "+%-15s+%-9s+%-39s+"
#define UDEV_INFO_HEADER_FMT "| %-15s | %-9s | %-39s |"
#define UDEV_INFO_DATA_FMT   "| %-15s | %-9u | %-39s |"
    char eid_str[URMA_EID_STR_LEN + 1] = {0};
    struct udev_info *info = NULL;
    unsigned int i, j;
    int ret;

    // no need to print header
    if (result->num == 0) {
        return;
    }

    qsort(result->data, MIN(result->num, DEV_INFO_MAX_DEV_NUM), sizeof(struct udev_info), tool_compare_udev_info);

    TOOL_PRINT_INFO(UDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_9, LINE_BAR_39);
    TOOL_PRINT_INFO(UDEV_INFO_HEADER_FMT, "Name", "EID Index", "EID");
    TOOL_PRINT_INFO(UDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_9, LINE_BAR_39);
    for (i = 0; i < MIN(result->num, DEV_INFO_MAX_DEV_NUM); i++) {
        info = &result->data[i];
        if (info->eid_num == 0) {
            TOOL_PRINT_INFO(UDEV_INFO_HEADER_FMT, info->name, NA_STR, NA_STR);
            TOOL_PRINT_INFO(UDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_9, LINE_BAR_39);
            continue;
        }

        for (j = 0; j < info->eid_num; j++) {
            ret = snprintf_s(eid_str, URMA_EID_STR_LEN + 1, URMA_EID_STR_LEN, EID_FMT, EID_ARGS(info->eid_list[j].eid));
            if (ret <= 0) {
                hccn_warn("snprintf_s failed, ret:%d i:%u j:%u", ret, i, j);
                continue;
            }
            TOOL_PRINT_INFO(UDEV_INFO_DATA_FMT, (j == 0) ? info->name : "", info->eid_list[j].eid_index, eid_str);
        }
        TOOL_PRINT_INFO(UDEV_INFO_LINE_FMT, LINE_BAR_15, LINE_BAR_9, LINE_BAR_39);
    }
}

STATIC int tool_get_all_udev_info(struct command_context *ctx)
{
    struct udev_info_data result_data = {0};
    struct dsmi_info info = {0};
    unsigned int size = 0;
    int ret;

    size = sizeof(result_data);
    ctx->result = (char *)&result_data;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_ALL_UDEV_INFO, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get all udev info failed, ret:%d", ret), ret);

    tool_print_udev_info(&result_data);
    return 0;
}

int tool_info_exec(struct command_context *ctx)
{
    int ret_result = 0;
    int ret;

    ret = tool_get_all_port_info(ctx);
    if (ret != 0) {
        hccn_err("tool_get_all_port_info failed, ret:%d", ret);
        ret_result = ret;
    }

    ret = tool_get_all_netdev_info(ctx);
    if (ret != 0) {
        hccn_err("tool_get_all_netdev_info failed, ret:%d", ret);
        ret_result = ret;
    }

    ret = tool_get_all_udev_info(ctx);
    if (ret != 0) {
        hccn_err("tool_get_all_udev_info failed, ret:%d", ret);
        ret_result = ret;
    }
    return (ret_result == 0) ? 0 : TOOL_EXE_DEV_INFO_ERR;
}

int tool_get_bond_slaves(struct command_context *ctx, struct netdev_info *ndev_info)
{
    unsigned int size = sizeof(struct netdev_info);
    struct dsmi_info info = {0};
    int ret;

    ctx->result = (char *)ndev_info;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_BOND_SLAVES, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get bond slaves failed, ret:%d", ret), ret);

    return 0;
}

