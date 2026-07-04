/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <netinet/in.h>
#include <arpa/inet.h>
#include "file_opt.h"
#include "ds_data.h"
#include "tool_errcode.h"
#include "tool_lib.h"
#include "tool_product.h"
#include "tool_cfg_ops.h"
#include "tool_udp.h"

typedef struct {
    char cfg_name[TMP_CFG_STR_SIZE];
    unsigned int *data_ptr;
    unsigned int date_lower;
    unsigned int date_upper;
} cfg_data_request;

int tool_write_conf_comm_uint(struct command_context *ctx, char *cfg_name, unsigned int cfg_size,
                              unsigned int cfg_value)
{
    int ret;
    char cfg_tmp[CONFLINE_LENGTH] = {0};

    ret = snprintf_s(cfg_tmp, CONFLINE_LENGTH, CONFLINE_LENGTH - 1, "%u", cfg_value);
    if (ret <= 0) {
        hccn_err("snprintf_s %s val failed. (ret=%d)", cfg_name, ret);
        return -EIO;
    }

    ret = tool_write_conf(ctx->slot_id, cfg_name, cfg_tmp);
    if (ret != 0) {
        hccn_err("write cfg %s error. (ret=%d; slot_id=%d; logic_id=%d)", cfg_name, ret, ctx->slot_id,
                 ctx->npu_info.logic_id);
        return ret;
    }

    return 0;
}

static int tool_read_conf_comm_uint(struct command_context *ctx, char *cfg_name, unsigned int cfg_size,
                                    unsigned int *cfg_value)
{
    int ret;
    char cfg_tmp[CONFLINE_LENGTH] = {0};
    char *tmp_ptr = NULL;

    ret = tool_read_conf(ctx->slot_id, cfg_name, cfg_tmp, CONFLINE_LENGTH);
    if (ret != 0) {
        if (ret == FILE_OPT_SYS_RD_FILE_NOT_FOUND || ret == FILE_OPT_INNER_PARAM_ERR) {
            return 0;
        } else {
            hccn_err("tool_read_conf %s failed! (ret=%d)", cfg_name, ret);
            return ret;
        }
    }

    *cfg_value = (unsigned int)strtoul(cfg_tmp, &tmp_ptr, 10); // 按10进制解析
    if (tmp_ptr == cfg_tmp || *tmp_ptr != '\0') {
        hccn_err("%s must be int. (value=%u; ptr_tail=%s)", cfg_name, *cfg_value, tmp_ptr);
        return -EINVAL;
    }

    return 0;
}

int tool_cfg_send_arp_recovery(struct command_context *ctx)
{
    int ret;
    arp_param_t param = {
        .enable = PARAM_INVALID,
        .period = PARAM_INVALID,
    };

    // 非UBoE设备跳过recovery
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_info("send arp sport recovery skipped: not a UBoE device. (mainboard_id=0x%x)",
                  ctx->npu_info.mainboard_id);
        return 0;
    }

    ret = tool_read_conf_comm_uint(ctx, "arp_enable", sizeof("arp_enable"), &param.enable);
    if (ret != 0) {
        return ret;
    }

    ret = tool_read_conf_comm_uint(ctx, "arp_period", sizeof("arp_period"), &param.period);
    if (ret != 0) {
        return ret;
    }

    // arp_enable 和 arp_period 都不需要恢复
    if (param.enable == PARAM_INVALID && param.period == PARAM_INVALID) {
        hccn_warn("tool_read_conf send arp do not need recover cfg. (ret=%d; logic_id=%d; slot_id=%d)",
                  ret, ctx->npu_info.logic_id, ctx->slot_id);
        return 0;
    }

    // 判断 arp_enable 和 arp_period 的合法性
    if ((param.enable != PARAM_INVALID && param.enable > 1) ||
        (param.period != PARAM_INVALID && (param.period < 1 || param.period > 3600))) { // period [1, 3600]
        hccn_err("arp_enable or arp_period is invalid. (enable=%d; period=%d)", param.enable, param.period);
        return -EINVAL;
    }

    ctx->cmd_args = (void *)(&param);
    ret = tool_set_send_arp(ctx);
    if (ret != 0) {
        hccn_err("recovery set send arp failed. (logic_id=%d)", ctx->npu_info.logic_id);
    }
    ctx->cmd_args = NULL;

    return ret;
}

static int tool_read_conf_pfc_storm(struct command_context *ctx, struct pfc_storm_t *info)
{
    int ret, i;
    unsigned int mode = PARAM_INVALID;
    cfg_data_request cfg_data[] = {
        {"pfc_close_time", &info->close_time, 0, 100}, // [0, 100]
        {"pfc_detect_period", &info->detect_period, 10, 100}, // [10, 100]
        {"pfc_warn_thrd", &info->warn_thrd, 40, 80}, // [40, 80]
        {"pfc_err_thrd", &info->err_thrd, 60, 100}, // [60, 100]
        {"pfc_mode", &mode, 0, 1},
    };

    for (i = 0; i < sizeof(cfg_data) / sizeof(cfg_data[0]); i++) {
        ret = tool_read_conf_comm_uint(ctx, cfg_data[i].cfg_name, TMP_CFG_STR_SIZE, cfg_data[i].data_ptr);
        if (ret != 0) {
            return ret;
        }

        if (*cfg_data[i].data_ptr != PARAM_INVALID &&
            (*cfg_data[i].data_ptr < cfg_data[i].date_lower || *cfg_data[i].data_ptr > cfg_data[i].date_upper)) {
            hccn_err("recovery pfc storm failed, param is invalid. (%s=%u)", cfg_data[i].cfg_name, info->close_time);
            return -EINVAL;
        }
    }
    info->mode = (unsigned char)(mode & 0xFF);

    return 0;
}

int tool_cfg_pfc_storm_recovery(struct command_context *ctx)
{
    int ret;
    struct product_channel_msg msg = {0};
    struct pfc_storm_info_t info = {0};
    struct pfc_storm_t param = {
        .close_time = PARAM_INVALID,
        .detect_period = PARAM_INVALID,
        .warn_thrd = PARAM_INVALID,
        .err_thrd = PARAM_INVALID,
        .mode = PARAM_INVALID,
    };

    // 非UBoE设备跳过recovery
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_info("pfc storm sport recovery skipped: not a UBoE device. (mainboard_id=0x%x)",
                  ctx->npu_info.mainboard_id);
        return 0;
    }

    ret = tool_read_conf_pfc_storm(ctx, &param);
    if (ret != 0) {
        return ret;
    }

    // 没有需要恢复的配置项
    if (param.close_time == PARAM_INVALID && param.detect_period == PARAM_INVALID && param.warn_thrd == PARAM_INVALID &&
        param.err_thrd == PARAM_INVALID && param.mode == (unsigned char)PARAM_INVALID) {
        hccn_warn("tool_read_conf pfc storm do not need recover cfg. (ret=%d; logic_id=%d; slot_id=%d)",
                  ret, ctx->npu_info.logic_id, ctx->slot_id);
        return 0;
    }

    info.pfc_storm_tx.dir = PFC_TX;
    info.pfc_storm_rx.dir = PFC_RX;

    // 先获取一遍pfc信息
    SET_PRODUCT_MSG(msg, NULL, 0, &info, sizeof(struct pfc_storm_info_t));
    ret = product_host_device_channel(ctx, CMD_GET_PFC_STORM, &msg);
    if (ret != 0) {
        hccn_err("Get pfc storm failed. (ret=%d)", ret);
        return ret;
    }

    ctx->cmd_args = (void *)(&param);
    ret = tool_set_pfc_storm(ctx, &info);
    if (ret != 0) {
        hccn_err("recovery set pfc storm failed. (logic_id=%d)", ctx->npu_info.logic_id);
    }
    ctx->cmd_args = NULL;

    return ret;
}

int tool_get_cfg_cmd_line(struct command_context *ctx, const char *cfg_cmd, char *cmd)
{
    char line_buf[CONFLINE_LENGTH] = {0};
    char *next_token = NULL;
    char *cmd_tmp = NULL;
    int ret = 0;

    ret = strncpy_s(line_buf, CONFLINE_LENGTH, cfg_cmd, strlen(cfg_cmd));
    if (ret != 0) {
        hccn_err("recovery strncpy_s cfg failed, ret:%d", ret);
        return -EIO;
    }

    // 等号前的部分
    cmd_tmp = strtok_s(line_buf, "=", &next_token);
    if (cmd_tmp == NULL) {
        hccn_err("strtok_s failed. (cfg_cmd=%s)", line_buf);
        return -EIO;
    }

    // 等号后的部分
    cmd_tmp = strtok_s(NULL, "=", &next_token);
    if (cmd_tmp == NULL) {
        hccn_err("strtok_s failed. (cfg_cmd=%s)", line_buf);
        return -EIO;
    }

    /* del the end \n symbol */
    cmd_tmp[strlen(cmd_tmp) - 1] = '\0';

    ret = strncpy_s(cmd, CONFLINE_LENGTH, cmd_tmp, strlen(cmd_tmp));
    if (ret != 0) {
        hccn_err("recovery strncpy_s cfg failed. (ret=%d)", ret);
        return -EIO;
    }

    return 0;
}

int tool_read_conf_ip_rule(struct command_context *ctx, const char *cfg_cmd, struct ip_rule_t *param)
{
    int ret, table;
    char cfg_tmp[CONFLINE_LENGTH] = {0};

    ret = tool_get_cfg_cmd_line(ctx, cfg_cmd, cfg_tmp);
    if (ret != 0) {
        hccn_err("get ip rule cfg cmd line failed! (ret=%d)", ret);
        return ret;
    }

    ret = sscanf_s(cfg_tmp, "%s %s table %d", param->dir, IP_DIR_SIZE, param->ip, MAX_IP_VAL_LEN, &table);
    if (ret <= 0) {
        roce_err("ip rule recover get param failed. (ret=%d; cfg_tmp=%s)", ret, cfg_tmp);
        return -EIO;
    }
    param->table = (unsigned int)table;

    return 0;
}

int tool_cfg_ip_rule_cmd_recovery(struct command_context *ctx, const char *cfg_cmd)
{
    int ret;
    union addr_t in = {0};
    struct ip_rule_t param = {
        .table = PARAM_INVALID,
        .addel = ADD_MODE_FLAG,
    };

    ret = tool_read_conf_ip_rule(ctx, cfg_cmd, &param);
    if (ret != 0) {
        if (ret == FILE_OPT_SYS_RD_FILE_NOT_FOUND || ret == FILE_OPT_INNER_PARAM_ERR) {
            return 0;
        }
        return ret;
    }

    // 判断参数的合法性
    if ((param.table != PARAM_INVALID && param.table > 255)) { // table [0, 255]
        hccn_err("ip rule recover table is invalid. (table=%u)", param.table);
        return -EINVAL;
    }
    if (strcmp(param.dir, "from") != 0 && strcmp(param.dir, "to") != 0) {
        hccn_err("ip rule recover dir is invalid. (dir=%s)", param.dir);
        return -EINVAL;
    }
    
    if (inet_pton(AF_INET, param.ip, &in.addr) != 1) {
        hccn_err("ip rule recover ip is invalid. (ip=%s)", param.ip);
        return -EINVAL;
    }

    ctx->cmd_args = (void *)(&param);
    ret = tool_set_ip_rule(ctx);
    if (ret != 0) {
        hccn_err("ip rule recovery set failed. (logic_id=%d)", ctx->npu_info.logic_id);
    }
    ctx->cmd_args = NULL;

    return ret;
}

int tool_cfg_ip_rule_recovery(struct command_context *ctx)
{
    char prefix[CONFLINE_LENGTH] = {0};
    int ret = 0;

    // 非UBoE设备跳过recovery
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_info("ip rule sport recovery skipped: not a UBoE device. (mainboard_id=0x%x)",
                  ctx->npu_info.mainboard_id);
        return 0;
    }

    ret = snprintf_s(prefix, CONFLINE_LENGTH, CONFLINE_LENGTH - 1, "ip_rule_%d", ctx->slot_id);
    if (ret <= 0) {
        hccn_err("snprintf_s ip rule prefix failed. (ret=%d; logic_id=%d; slot_id=%d)",
            ret, ctx->npu_info.logic_id, ctx->slot_id);
        return -EIO;
    }

    // 按行搜索，匹配到上面关键词的配置行就调用 tool_cfg_ip_rule_cmd_recovery
    return tool_cfg_cmdline_recovery(ctx, prefix, tool_cfg_ip_rule_cmd_recovery);
}

int tool_read_conf_ip_route(struct command_context *ctx, const char *cfg_cmd, struct ip_route_t *param)
{
    int ret, table;
    char cfg_tmp[CONFLINE_LENGTH] = {0};

    ret = tool_get_cfg_cmd_line(ctx, cfg_cmd, cfg_tmp);
    if (ret != 0) {
        hccn_err("get ip route cfg cmd line failed! (ret=%d)", ret);
        return ret;
    }

    ret = sscanf_s(cfg_tmp, "%s %u via %s table %d",
        param->ip_address, MAX_IP_VAL_LEN, &param->ip_mask, param->via_address, MAX_IP_VAL_LEN, &table);
    if (ret <= 0) {
        hccn_err("ip route recover get param failed. (ret=%d; cfg_tmp=%s)", ret, cfg_tmp);
        return -EIO;
    }
    param->table_id = (unsigned int)table;

    return 0;
}

int tool_cfg_ip_route_cmd_recovery(struct command_context *ctx, const char *cfg_cmd)
{
    int ret;
    union addr_t in = {0};
    struct ip_route_t param = {
        .table_id = PARAM_INVALID,
        .addel = ADD_MODE_FLAG,
    };

    ret = tool_read_conf_ip_route(ctx, cfg_cmd, &param);
    if (ret != 0) {
        if (ret == FILE_OPT_SYS_RD_FILE_NOT_FOUND || ret == FILE_OPT_INNER_PARAM_ERR) {
            return 0;
        }
        return ret;
    }

    // 判断参数的合法性
    if ((param.table_id != PARAM_INVALID && param.table_id > 255)) { // table [0, 255]
        hccn_err("ip route recover table is invalid. (table=%u)", param.table_id);
        return -EINVAL;
    }
    if (param.ip_mask > 32) { // table [0, 32]
        hccn_err("ip route recover ip_mask is invalid. (ip_mask=%u)", param.ip_mask);
        return -EINVAL;
    }
    if (inet_pton(AF_INET, param.ip_address, &in.addr) != 1) {
        hccn_err("ip route recover ip is invalid. (ip=%s)", param.ip_address);
        return -EINVAL;
    }
    if (inet_pton(AF_INET, param.via_address, &in.addr) != 1) {
        hccn_err("ip route recover via is invalid. (via=%s)", param.via_address);
        return -EINVAL;
    }

    ctx->cmd_args = (void *)(&param);
    ret = tool_set_ip_route(ctx);
    if (ret == EEXIST) { // 如果ip_route已经存在就不再重复配置
        hccn_info("IP route table already exists.");
        ret = 0;
    } else if (ret != 0) {
        hccn_err("ip route recovery set failed. (logic_id=%d)", ctx->npu_info.logic_id);
    }
    ctx->cmd_args = NULL;

    return ret;
}

int tool_cfg_ip_route_recovery(struct command_context *ctx)
{
    char prefix[CONFLINE_LENGTH] = {0};
    int ret = 0;

    // 非UBoE设备跳过recovery
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_info("ip route sport recovery skipped: not a UBoE device. (mainboard_id=0x%x)",
                  ctx->npu_info.mainboard_id);
        return 0;
    }

    ret = snprintf_s(prefix, CONFLINE_LENGTH, CONFLINE_LENGTH - 1, "ip_route_%d", ctx->slot_id);
    if (ret <= 0) {
        hccn_err("snprintf_s ip route prefix failed. (ret=%d; logic_id=%d; slot_id=%d)",
            ret, ctx->npu_info.logic_id, ctx->slot_id);
        return -EIO;
    }

    // 按行搜索，匹配到上面关键词的配置行就调用 tool_cfg_ip_route_cmd_recovery
    return tool_cfg_cmdline_recovery(ctx, prefix, tool_cfg_ip_route_cmd_recovery);
}

static recovery_cmd_t g_full_independent_cmd_list[MAX_CFG_LIST] = {0};

static recovery_cmd_t g_full_dependent_cmd_list[MAX_CFG_LIST] = {0};

// 产品侧独立恢复命令表
static recovery_cmd_t g_recovery_independent_cmd_list_product[] = {
    {"udp", tool_cfg_udp_sport_recovery},
    {"pfc_storm", tool_cfg_pfc_storm_recovery},
};

// 产品侧依赖ip恢复命令表
static recovery_cmd_t g_recovery_dependent_cmd_list_product[] = {
    {"send_arp", tool_cfg_send_arp_recovery},
    {"ip_rule", tool_cfg_ip_rule_recovery},
    {"ip_route", tool_cfg_ip_route_recovery},
};

int tool_copy_cmd_to_full_list(recovery_cmd_t *full_list, recovery_cmd_t *product_list, int product_cfg_num,
                               recovery_cmd_t *cfg_list, unsigned int *cfg_num)
{
    int ret, cfg_size = sizeof(recovery_cmd_t);

    if (full_list == NULL || product_list == NULL || cfg_list == NULL || cfg_num == NULL) {
        roce_err("copy full cfg list failed. (full_list_is_NULL=%d; product_list_is_NULL=%d; cfg_list_is_NULL=%d; "
                 "cfg_num_is_NULL=%d)", full_list == NULL, product_list == NULL, cfg_list == NULL, cfg_num == NULL);
        return -EINVAL;
    }

    if (product_cfg_num + *cfg_num >= MAX_CFG_LIST) {
        roce_err("Full list num out of max list num. (product_cfg_num=%d; cfg_num=%d", product_cfg_num, *cfg_num);
        return -EINVAL;
    }

    ret = memcpy_s(full_list, MAX_CFG_LIST * cfg_size, cfg_list, *cfg_num * cfg_size);
    if (ret) {
        roce_err("Memcpy_s cfg list to full list fail. (ret=%d)", ret);
        return ret;
    }

    ret = memcpy_s(&full_list[*cfg_num], (MAX_CFG_LIST - *cfg_num) * cfg_size,
                   product_list, product_cfg_num * cfg_size);
    if (ret) {
        roce_err("Memcpy_s product list to full list fail. (ret=%d)", ret);
        return ret;
    }

    *cfg_num = product_cfg_num + *cfg_num;
    return 0;
}

recovery_cmd_t *tool_get_full_independent_cmd_list(recovery_cmd_t *cfg_list, unsigned int *cfg_num)
{
    int ret, product_cfg_num;

    product_cfg_num = ARRAY_SIZE_COMPUTE(g_recovery_independent_cmd_list_product);
    if (product_cfg_num == 0) {
        return cfg_list;
    }

    ret = tool_copy_cmd_to_full_list(g_full_independent_cmd_list, g_recovery_independent_cmd_list_product,
                                     product_cfg_num, cfg_list, cfg_num);
    if (ret != 0) {
        roce_err("get full recovery independent cmd list failed. (ret=%d)", ret);
        return NULL;
    }

    return g_full_independent_cmd_list;
}

recovery_cmd_t *tool_get_full_dependent_cmd_list(recovery_cmd_t *cfg_list, unsigned int *cfg_num)
{
    int ret, product_cfg_num;

    product_cfg_num = ARRAY_SIZE_COMPUTE(g_recovery_dependent_cmd_list_product);
    if (product_cfg_num == 0) {
        return cfg_list;
    }

    ret = tool_copy_cmd_to_full_list(g_full_dependent_cmd_list, g_recovery_dependent_cmd_list_product,
                                     product_cfg_num, cfg_list, cfg_num);
    if (ret != 0) {
        roce_err("get full recovery dependent cmd list failed. (ret=%d)", ret);
        return NULL;
    }

    return g_full_dependent_cmd_list;
}
