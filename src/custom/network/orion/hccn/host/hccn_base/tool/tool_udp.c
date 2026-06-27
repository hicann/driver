/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdlib.h>
#include <string.h>
#include "securec.h"
#include "ds_data.h"
#include "tool_cmd_parse.h"
#include "tool_comm.h"
#include "comm_channel.h"
#include "comm_dfx_channel.h"
#include "tool_cmd_err.h"
#include "comm_product.h"
#include "tool_cfg_ops.h"
#include "file_opt.h"
#include "tool_lib.h"
#include "tool_errcode.h"
#include "tool_log.h"
#include "tool_udp.h"

// ==================== UDP源端口配置功能实现 ====================

// UDP源端口范围定义
#define UDP_SPORT_MIN_VALUE 4097
#define UDP_SPORT_MAX_VALUE 65535
#define UDP_SPORT_DECIMAL_BASE 10

STATIC struct sub_option_entry udp_sport_opts_param[] = {
    {"-mode", ARG_TYPE_STR, parse_str, MODE_SET, 0},
    {"-sport", ARG_TYPE_INT, parse_int, MODE_SET, 0, true,
     .range.int_range = {UDP_SPORT_MIN_VALUE, UDP_SPORT_MAX_VALUE}},
    {"-reset", ARG_TYPE_NONE, parse_none, MODE_SET, 0},
};

void get_udp_sport_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    *sub_opts = udp_sport_opts_param;
    *count = ARRAY_SIZE_COMPUTE(udp_sport_opts_param);
}

void *alloc_udp_sport_args(void)
{
    struct udp_sport_data *args = (struct udp_sport_data *)calloc(1, sizeof(struct udp_sport_data));
    if (args == NULL) {
        hccn_err("Failed to alloc udp_sport_args.");
        return NULL;
    }
    // mode初始化为NONE表示未指定操作
    args->mode = UDP_SPORT_MODE_INVALID;
    args->sport = 0;
    return (void *)args;
}

int udp_sport_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct udp_sport_data *data = (struct udp_sport_data *)args;

    if (strcmp(opt->name, "-mode") == 0) {
        // -mode 与 -reset 互斥（reset时mode为 UDP_SPORT_MODE_RESET）
        if (data->mode == UDP_SPORT_MODE_DEFAULT) {
            hccn_err("Option -mode and -reset conflict with each other.");
            TOOL_PRINT_ERR("Option -mode and -reset conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        // -mode 参数处理，目前只支持 "global"
        if (strcmp(type_val->str_val, "global") != 0) {
            hccn_err("Invalid mode value: %s, only 'global' is supported.", type_val->str_val);
            TOOL_PRINT_ERR("Invalid mode value: %s, only 'global' is supported.", type_val->str_val);
            return TOOL_PRIVATE_ARGS_VALUE_ERR;
        }
        data->mode = UDP_SPORT_MODE_GLOBAL;
        return 0;
    }

    if (strcmp(opt->name, "-sport") == 0) {
        // -sport 与 -reset 互斥（reset时mode为 UDP_SPORT_MODE_DEFAULT 且 sport=0）
        if (data->mode == UDP_SPORT_MODE_DEFAULT) {
            hccn_err("Option -sport and -reset conflict with each other.");
            TOOL_PRINT_ERR("Option -sport and -reset conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        data->sport = type_val->int_val;
        return 0;
    }

    if (strcmp(opt->name, "-reset") == 0) {
        // -reset 与 -mode/-sport 互斥
        // mode != NONE 表示已指定-mode，sport != 0 表示已指定-sport
        if (data->mode != UDP_SPORT_MODE_INVALID || data->sport != 0) {
            hccn_err("Option -reset conflicts with -mode or -sport.");
            TOOL_PRINT_ERR("Option -reset conflicts with -mode or -sport.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        // reset时直接设置为default模式
        data->mode = UDP_SPORT_MODE_DEFAULT;
        data->sport = 0;
        return 0;
    }

    return 0;
}

void tool_udp_sport_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_udp_sport_help(ctx, MODE_SET);
            tool_udp_sport_help(ctx, MODE_GET);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-udp", "set UDP source port mode for UBoE device");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_UDMA_DEV);
            TOOL_PRINT_OPT("-mode %s", "set mode, currently only supports 'global'");
            TOOL_PRINT_OPT("-sport <port>", "UDP source port number, range [4097, 65535]");
            TOOL_PRINT_OPT("-reset", "reset UDP source port mode");
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-udp", "query UDP source port mode for UBoE device");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_UDMA_DEV);
            break;
        default:
            break;
    }
}

// 将mode枚举转换为配置文件中的字符串
STATIC const char *hccn_tool_udp_mode_to_str(unsigned int mode)
{
    if (mode == UDP_SPORT_MODE_GLOBAL) {
        return "global";
    }
    return NULL;
}


// 去除字符串首尾空格，返回去除后的起始指针和长度
static void hccn_tool_trim_field(const char **start, size_t *len)
{
    const char *p_start = *start;
    const char *p_end;

    // 长度为0时直接返回
    if (*len == 0) {
        return;
    }

    p_end = p_start + *len - 1;

    // 去除前导空格
    while (p_start <= p_end && *p_start == ' ') {
        p_start++;
    }

    // 去除尾部空格
    while (p_end >= p_start && *p_end == ' ') {
        p_end--;
    }

    *start = p_start;
    *len = (p_end >= p_start) ? (size_t)(p_end - p_start + 1) : 0;
}

// 提取两个字段之间的内容（从start到end，不包含end），自动去除首尾空格
// 返回: 0-成功, 非0-失败
STATIC int hccn_tool_extract_field(char *dest, size_t dest_size, const char *start, const char *end)
{
    size_t len = (end != NULL) ? (size_t)(end - start) : strlen(start);

    // 去除首尾空格
    hccn_tool_trim_field(&start, &len);

    if (len > dest_size - 1) {
        hccn_err("extract field failed: field too long. (len=%zu, max=%zu)\n", len, dest_size - 1);
        return -EINVAL;
    }
    return strncpy_s(dest, dest_size, start, len);
}

// 解析配置项中的设备条目，格式: {dev_name}:{mode}:{mode_data}
// 返回: 0-成功解析, 非0-错误
STATIC int hccn_tool_parse_udp_cfg_entry(const char *entry, udp_cfg_entry_t *result)
{
    const char *colon1 = strchr(entry, ':');
    const char *colon2 = (colon1 != NULL) ? strchr(colon1 + 1, ':') : NULL;

    if (colon1 == NULL || colon2 == NULL) {
        hccn_err("parse udp cfg entry failed: invalid format. (entry=%s)\n", entry);
        return -EINVAL;
    }

    // 提取dev_name
    if (hccn_tool_extract_field(result->dev_name, sizeof(result->dev_name), entry, colon1) != 0) {
        hccn_err("parse udp cfg entry failed: dev_name too long or copy failed.\n");
        return -EINVAL;
    }

    // 提取mode_str
    if (hccn_tool_extract_field(result->mode_str, sizeof(result->mode_str), colon1 + 1, colon2) != 0) {
        hccn_err("parse udp cfg entry failed: mode_str too long or copy failed.\n");
        return -EINVAL;
    }

    // 提取mode_data
    if (hccn_tool_extract_field(result->mode_data, sizeof(result->mode_data), colon2 + 1, NULL) != 0) {
        hccn_err("parse udp cfg entry failed: mode_data too long or copy failed.\n");
        return -EINVAL;
    }

    return 0;
}

// 追加配置项到配置行（处理逗号）
STATIC int hccn_tool_append_config_entry(char *new_config_line, int line_size, char *entry)
{
    int ret;

    if (new_config_line[0] != '\0') {
        ret = strcat_s(new_config_line, line_size, ",");
        if (ret != 0) {
            hccn_err("strcat_s comma failed. (ret=%d)\n", ret);
            return ret;
        }
    }
    ret = strcat_s(new_config_line, line_size, entry);
    if (ret != 0) {
        hccn_err("strcat_s entry failed. (ret=%d)\n", ret);
        return ret;
    }
    return 0;
}

// 构建单个配置项字符串
STATIC int hccn_tool_build_udp_entry(char *buf, int buf_size, char *dev_name, unsigned int mode, unsigned int sport)
{
    int ret;
    const char *mode_str = hccn_tool_udp_mode_to_str(mode);
    if (mode_str == NULL) {
        hccn_err("get udp sport mode str failed. (mode=%u)\n", mode);
        return -EINVAL;
    }

    ret = snprintf_s(buf, buf_size, buf_size - 1, "%s:%s:%u", dev_name, mode_str, sport);
    if (ret < 0) {
        hccn_err("build udp entry failed. (ret=%d)\n", ret);
        return ret;
    }
    return 0;
}

// 读取UDP配置，返回: 0-成功(包括文件不存在), 其他-错误
STATIC int hccn_tool_read_udp_config(int dev_id, char *buf, unsigned int len)
{
    int ret = tool_read_conf(dev_id, UDP_SPORT_CFG_NAME, buf, len);
    if (ret == FILE_OPT_SYS_RD_FILE_NOT_FOUND) {
        buf[0] = '\0';
        return 0;
    }
    if (ret != 0) {
        hccn_err("read udp config failed. (ret=%d)\n", ret);
    }
    return ret;
}

// 处理单个配置条目：更新当前设备或保留其他设备配置
// 返回: 0-继续处理, 非0-错误
STATIC int hccn_tool_process_config_token(const char *token, struct udp_sport_data *data,
    char *new_config_line, int line_size, int *found)
{
    udp_cfg_entry_t entry = {0};
    char entry_buf[UDP_CFG_ENTRY_BUF_LEN];
    int ret;

    ret = hccn_tool_parse_udp_cfg_entry(token, &entry);
    if (ret != 0) {
        hccn_err("parse udp cfg entry failed. (token=%s)\n", token);
        return ret;
    }

    if (strcmp(entry.dev_name, data->dev_name) == 0) {
        // 找到当前设备，更新配置
        ret = hccn_tool_build_udp_entry(entry_buf, sizeof(entry_buf),
            data->dev_name, data->mode, data->sport);
        if (ret != 0) {
            hccn_err("build udp entry failed when update. (dev=%s, ret=%d)\n", data->dev_name, ret);
            return ret;
        }
        ret = hccn_tool_append_config_entry(new_config_line, line_size, entry_buf);
        if (ret != 0) {
            hccn_err("append config entry failed when update. (dev=%s, ret=%d)\n", data->dev_name, ret);
            return ret;
        }
        *found = 1;
        return 0;
    }

    // 保留其他设备配置
    return hccn_tool_append_config_entry(new_config_line, line_size, (char *)token);
}

// 添加新设备配置到配置行
STATIC int hccn_tool_add_new_device_config(struct udp_sport_data *data,
    char *new_config_line, int line_size)
{
    char entry_buf[UDP_CFG_ENTRY_BUF_LEN];
    int ret = hccn_tool_build_udp_entry(entry_buf, sizeof(entry_buf),
        data->dev_name, data->mode, data->sport);
    if (ret != 0) {
        hccn_err("build udp entry failed when add new. (dev=%s, ret=%d)\n", data->dev_name, ret);
        return ret;
    }
    ret = hccn_tool_append_config_entry(new_config_line, line_size, entry_buf);
    if (ret != 0) {
        hccn_err("append config entry failed when add new. (dev=%s, ret=%d)\n", data->dev_name, ret);
        return ret;
    }
    return 0;
}

// 保存UDP配置到配置文件
STATIC int hccn_tool_save_udp_config(struct command_context *ctx, struct udp_sport_data *data)
{
    char config_line[UDP_SPORT_CFG_MAX_LEN] = {0};
    char new_config_line[UDP_SPORT_CFG_MAX_LEN] = {0};
    char *token = NULL;
    char *save_ptr = NULL;
    int found = 0;
    int ret;

    ret = hccn_tool_read_udp_config(ctx->slot_id, config_line, sizeof(config_line));
    if (ret != 0) {
        return ret;
    }

    // 解析现有配置，更新或保留条目
    token = strtok_s(config_line, ",", &save_ptr);
    while (token != NULL) {
        ret = hccn_tool_process_config_token(token, data, new_config_line, sizeof(new_config_line), &found);
        if (ret != 0) {
            return ret;
        }
        token = strtok_s(NULL, ",", &save_ptr);
    }

    // 未找到当前设备则添加新配置
    if (!found) {
        ret = hccn_tool_add_new_device_config(data, new_config_line, sizeof(new_config_line));
        if (ret != 0) {
            return ret;
        }
    }

    return tool_write_conf(ctx->slot_id, UDP_SPORT_CFG_NAME, new_config_line);
}

// 处理删除场景的单个配置条目：保留非当前设备的配置
// 返回: 0-成功继续, 非0-错误
STATIC int hccn_tool_process_remove_token(const char *token, struct command_context *ctx,
    char *new_config_line, int line_size)
{
    udp_cfg_entry_t entry = {0};
    int ret = hccn_tool_parse_udp_cfg_entry(token, &entry);
    if (ret != 0) {
        hccn_err("parse udp cfg entry failed. (token=%s)\n", token);
        return ret;
    }

    // 保留其他设备配置
    if (strcmp(entry.dev_name, ctx->dev_name) != 0) {
        ret = hccn_tool_append_config_entry(new_config_line, line_size, (char *)token);
        if (ret != 0) {
            hccn_err("append config entry failed when remove. (dev=%s, ret=%d)\n", entry.dev_name, ret);
            return ret;
        }
    }
    return 0;
}

STATIC int hccn_tool_remove_udp_config(struct command_context *ctx)
{
    char config_line[UDP_SPORT_CFG_MAX_LEN] = {0};
    char new_config_line[UDP_SPORT_CFG_MAX_LEN] = {0};
    char *token = NULL;
    char *save_ptr = NULL;
    int ret;

    ret = tool_read_conf(ctx->slot_id, UDP_SPORT_CFG_NAME, config_line, sizeof(config_line));
    if (ret == FILE_OPT_SYS_RD_FILE_NOT_FOUND) {
        return 0;
    }
    if (ret != 0) {
        hccn_err("read udp config failed. (ret=%d)\n", ret);
        return ret;
    }

    // 解析配置，保留非当前设备的配置
    token = strtok_s(config_line, ",", &save_ptr);
    while (token != NULL) {
        ret = hccn_tool_process_remove_token(token, ctx, new_config_line, sizeof(new_config_line));
        if (ret != 0) {
            return ret;
        }
        token = strtok_s(NULL, ",", &save_ptr);
    }

    // 配置为空则删除整行，否则写入新配置
    if (new_config_line[0] == '\0') {
        return tool_del_conf(ctx->slot_id, UDP_SPORT_CFG_NAME);
    }
    return tool_write_conf(ctx->slot_id, UDP_SPORT_CFG_NAME, new_config_line);
}

STATIC int tool_udp_sport_prepare_set(struct command_context *ctx, struct udp_sport_data *data)
{
    int ret;

    // 设置设备名称
    ret = strncpy_s(data->dev_name, sizeof(data->dev_name), ctx->dev_name, strlen(ctx->dev_name));
    if (ret != 0) {
        hccn_err("copy device name failed. (ret=%d)", ret);
        return ret;
    }

    if (data->mode == UDP_SPORT_MODE_GLOBAL) {
        // SET模式：必须指定-mode global和-sport
        // 校验sport范围
        if (data->sport < UDP_SPORT_MIN_VALUE || data->sport > UDP_SPORT_MAX_VALUE) {
            hccn_err("sport %u is out of range [%u, %u]", data->sport, UDP_SPORT_MIN_VALUE, UDP_SPORT_MAX_VALUE);
            return TOOL_PUBLIC_ARGS_RANGE_ERR;
        }
    } else if (data->mode == UDP_SPORT_MODE_DEFAULT) {
        // default模式
        data->sport = 0;
    } else {
        // 未指定操作
        hccn_err("no operation specified, use -mode or -reset");
        TOOL_PRINT_ERR("no operation specified, use -mode or -reset");
        return TOOL_USER_INPUT_PARAM_ERR;
    }
    return 0;
}

STATIC int tool_udp_sport_persist(struct command_context *ctx, struct udp_sport_data *data)
{
    int ret;

    if (data->mode == UDP_SPORT_MODE_GLOBAL) {
        // SET模式：保存配置
        ret = hccn_tool_save_udp_config(ctx, data);
        if (ret != 0) {
            hccn_err("save config failed, ret: %d", ret);
            return ret;
        }
    } else if (data->mode == UDP_SPORT_MODE_DEFAULT) {
        // 删除配置
        ret = hccn_tool_remove_udp_config(ctx);
        if (ret != 0) {
            hccn_err("remove config failed, ret: %d", ret);
            return ret;
        }
    } else {
        hccn_err("invalid udp sport mode when persist, mode: %d", data->mode);
        return -EINVAL;
    }

    return 0;
}

STATIC void tool_udp_sport_print_result(struct udp_sport_data *data)
{
    if (data->mode == UDP_SPORT_MODE_GLOBAL) {
        TOOL_PRINT_INFO("mode  : global");
        TOOL_PRINT_INFO("sport : %u", data->sport);
    } else {
        // 未配置或reset后，显示not configured
        TOOL_PRINT_INFO("mode  : not configured");
        TOOL_PRINT_INFO("sport : not configured");
    }
}

STATIC void tool_udp_print_err_info(int err_code)
{
    switch (err_code) {
        case DEV_NOT_FOUND:
            TOOL_PRINT_ERR("Device not found.");
            break;
        case NOT_UBOE_DEV:
            TOOL_PRINT_ERR("Not uboe device.");
            break;
        default:
            return;
    }
    return;
}

// UDP sport SET模式执行函数
STATIC int tool_udp_sport_set_exec(struct command_context *ctx)
{
    struct udp_sport_data *data = (struct udp_sport_data *)ctx->cmd_args;
    struct product_channel_msg msg = {0};
    int ret;

    if (ctx->dev_name[0] == '\0') {
        hccn_err("device name is required (-d option)");
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR;
    }

    if (data == NULL) {
        hccn_err("ctx->cmd_args is NULL");
        return TOOL_PRIVATE_ARGS_NUM_ERR;
    }

    // 准备SET参数（包含设置设备名称）
    ret = tool_udp_sport_prepare_set(ctx, data);
    if (ret != 0) {
        return ret;
    }

    LOG_PROMPT(ctx, "set udp sport cfg[dev:%s, mode:%s, sport:%u] for device[%d]",
               data->dev_name, data->mode == UDP_SPORT_MODE_GLOBAL ? "global" : "reset",
               data->sport, ctx->npu_info.logic_id);

    // 下发命令
    SET_PRODUCT_MSG(msg, data, sizeof(struct udp_sport_data), data, sizeof(struct udp_sport_data));
    ret = product_host_device_channel(ctx, CMD_SET_UDP_SPORT_MODE, &msg);
    if (ret != 0) {
        hccn_err("UDP sport set operation failed. (ret=%d)", ret);
        return ret;
    }

    // 检查内核返回的错误码
    if (data->ret != 0) {
        hccn_err("UDP sport set operation failed. (data->ret=%d)", data->ret);
        tool_udp_print_err_info(data->ret);
        return data->ret;
    }

    // 持久化配置
    return tool_udp_sport_persist(ctx, data);
}

// UDP sport GET模式执行函数
STATIC int tool_udp_sport_get_exec(struct command_context *ctx)
{
    struct udp_sport_data *data = NULL;
    struct product_channel_msg msg = {0};
    int ret;

    if (ctx->dev_name[0] == '\0') {
        hccn_err("device name is required (-d option)");
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR;
    }

    // GET模式直接分配内存
    data = (struct udp_sport_data *)calloc(1, sizeof(struct udp_sport_data));
    if (data == NULL) {
        hccn_err("alloc udp_sport_data failed.");
        return TOOL_ENOMEM;
    }

    // 设置设备名称
    ret = strncpy_s(data->dev_name, sizeof(data->dev_name), ctx->dev_name, strlen(ctx->dev_name));
    if (ret != 0) {
        hccn_err("copy device name failed. (ret=%d)", ret);
        goto err_free;
    }

    // 下发查询命令
    SET_PRODUCT_MSG(msg, data, sizeof(struct udp_sport_data), data, sizeof(struct udp_sport_data));
    ret = product_host_device_channel(ctx, CMD_GET_UDP_SPORT_MODE, &msg);
    if (ret != 0) {
        hccn_err("UDP sport get operation failed. (ret=%d)", ret);
        goto err_free;
    }

    // 检查内核返回的错误码
    if (data->ret != 0) {
        hccn_err("UDP sport get operation failed. (data->ret=%d)", data->ret);
        tool_udp_print_err_info(data->ret);
        ret = data->ret;
        goto err_free;
    }

    // 打印结果
    tool_udp_sport_print_result(data);

err_free:
    free(data);
    return ret;
}

// UDP sport命令执行入口
int tool_udp_sport_exec(struct command_context *ctx)
{
    // 检查是否为UBoE mainboard，此命令仅支持UBoE设备
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_err("UDP sport command only supports UBoE devices. (mainboard_id=0x%x)", ctx->npu_info.mainboard_id);
        TOOL_PRINT_ERR("The command is not supported on this product.");
        return TOOL_UNSUPPORT_BOARD;
    }

    switch (ctx->mode) {
        case MODE_SET:
            return tool_udp_sport_set_exec(ctx);
        case MODE_GET:
            return tool_udp_sport_get_exec(ctx);
        default:
            hccn_err("udp sport unknown mode. (mode=%d)", ctx->mode);
            return TOOL_INVALID_PARAM;
    }
}

/* ============== Recovery函数实现 ============== */
STATIC int tool_cfg_udp_sport_do_recover(struct command_context *ctx,
    char *dev_name, unsigned int mode, unsigned int sport)
{
    struct udp_sport_data udp_args = {0};
    int ret;

    ret = memset_s(ctx->dev_name, sizeof(ctx->dev_name), 0, sizeof(ctx->dev_name));
    if (ret != EOK) {
        hccn_err("memset_s dev_name failed. (ret=%d)\n", ret);
        return ret;
    }

    ret = strncpy_s(ctx->dev_name, sizeof(ctx->dev_name), dev_name, strlen(dev_name));
    if (ret != EOK) {
        hccn_err("strncpy_s dev_name failed. (ret=%d)\n", ret);
        return ret;
    }

    // recovery时直接设置mode和sport，无需op_mode
    udp_args.mode = mode;
    udp_args.sport = sport;
    ctx->cmd_args = &udp_args;

    ret = tool_udp_sport_exec(ctx);
    if (ret != 0) {
        hccn_err("recovery udp sport failed, dev:%s mode:%u sport:%u ret:%d\n", dev_name, mode, sport, ret);
    } else {
        hccn_info("recovery udp sport success, dev:%s mode:%u sport:%u\n", dev_name, mode, sport);
    }
    return ret;
}

// 解析并恢复单个设备配置，返回: 0-成功, 非0-错误
STATIC int tool_cfg_udp_sport_recover_one(struct command_context *ctx, char *device_token)
{
    udp_cfg_entry_t entry = {0};
    unsigned int sport;
    unsigned int mode;
    char *p_tmp = NULL;
    int ret;

    // 使用hccn_tool_parse_udp_cfg_entry解析配置
    ret = hccn_tool_parse_udp_cfg_entry(device_token, &entry);
    if (ret != 0) {
        hccn_err("parse udp config failed. (token=%s)\n", device_token);
        return ret;
    }

    // 目前只支持global模式
    if (strcmp(entry.mode_str, "global") == 0) {
        mode = UDP_SPORT_MODE_GLOBAL;
        sport = (unsigned int)strtoul(entry.mode_data, &p_tmp, UDP_SPORT_DECIMAL_BASE);
        if (*p_tmp != '\0' || sport < UDP_SPORT_MIN_VALUE || sport > UDP_SPORT_MAX_VALUE) {
            hccn_err("invalid sport in config, out of range [%u, %u]. (dev=%s, sport=%u)\n",
                UDP_SPORT_MIN_VALUE, UDP_SPORT_MAX_VALUE, entry.dev_name, sport);
            return -EINVAL;
        }
    } else {
        hccn_err("unsupported mode in config, only global mode is supported. (dev=%s, mode=%s)\n",
                 entry.dev_name, entry.mode_str);
        return -EINVAL;
    }

    return tool_cfg_udp_sport_do_recover(ctx, entry.dev_name, mode, sport);
}

int tool_cfg_udp_sport_recovery(struct command_context *ctx)
{
    char udp_sport_val[CONFLINE_LENGTH] = {0};
    char *device_token = NULL;
    char *next_token = NULL;
    struct command_context recovery_ctx = {0};
    int ret;
    bool has_error = false;

    // 非UBoE设备跳过recovery
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_info("UDP sport recovery skipped: not a UBoE device. (mainboard_id=0x%x)",
                  ctx->npu_info.mainboard_id);
        return 0;
    }

    ret = hccn_tool_read_udp_config(ctx->slot_id, udp_sport_val, sizeof(udp_sport_val));
    if (ret != 0) {
        hccn_err("read udp config failed during recovery. (ret=%d)\n", ret);
        return ret;
    }
    if (udp_sport_val[0] == '\0') {
        hccn_info("udp sport config is empty, skip recovery.\n");
        return 0;
    }

    ret = memcpy_s(&recovery_ctx, sizeof(recovery_ctx), ctx, sizeof(struct command_context));
    if (ret != EOK) {
        hccn_err("memcpy_s recovery_ctx failed. (ret=%d)\n", ret);
        return ret;
    }
    recovery_ctx.mode = MODE_SET;

    // 解析配置格式: dev1:mode_str:sport,dev2:mode_str:sport
    device_token = strtok_s(udp_sport_val, ",", &next_token);
    while (device_token != NULL) {
        ret = tool_cfg_udp_sport_recover_one(&recovery_ctx, device_token);
        if (ret != 0) {
            has_error = true;
        }
        device_token = strtok_s(NULL, ",", &next_token);
    }
    return has_error ? -EINVAL : 0;
}
