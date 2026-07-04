/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "comm_channel.h"
#include "comm_channel_ext.h"
#include "hccn_err.h"
#include "tool_table.h"
#include "tool_errcode.h"
#include "tool_param.h"
#include "tool_cmd_err.h"
#include "tool_cmd_parse.h"
#include "tool_product.h"
#include "ds_data.h"
#include "tool_lib.h"
#include "ascend_hal.h"
#include "utils/bitmap.h"
#include "dsmi_common_product.h"

#include "tool_optical.h"

int tool_optical_show_page_info(struct optical_test_t *info, unsigned char *reg_buf)
{
    int ret;
    int byte_no;
    int page_len;
    int i, j;
    char row_buf[XSFP_REG_BUF_LEN];

    byte_no = (info->dump_page_id == 0) ? 0 : XSFP_PAGE_REG_LENGTH;
    page_len = (info->dump_page_id == 0) ? XSFP_PAGE_REG_MAX_LENGTH : XSFP_PAGE_REG_LENGTH;

    TOOL_PRINT_INFO("Dump Optical Register: Page %02xh", info->dump_page_id);

    for (i = 0; i < page_len; i += XSFP_REG_NUM_ONE_ROW) {
        if (info->dump_page_id == 0 && i == 0) {
            TOOL_PRINT_INFO("Page 00h Low Memory : 0 - 127");
        } else if (info->dump_page_id == 0 && i == XSFP_PAGE_REG_LENGTH) {
            TOOL_PRINT_INFO("Page 00h High Memory : 128 - 255");
        } else if (info->dump_page_id != 0 && i == 0) {
            TOOL_PRINT_INFO("Page %02xh : 128 - 255", info->dump_page_id);
        }

        ret = sprintf_s(row_buf, XSFP_REG_BUF_LEN, "[%03d]:", byte_no);
        if (ret < 0) {
            hccn_err("sprintf_s cmd fail. ret[%d]", ret);
            return ret;
        }

        for (j = 0; j < XSFP_REG_NUM_ONE_ROW; j++) {
            ret += sprintf_s(row_buf + ret, XSFP_REG_BUF_LEN - ret, " %02x", reg_buf[i + j]);
            if (ret < 0) {
                hccn_err("sprintf_s cmd fail. ret[%d]", ret);
                return ret;
            }
        }
        row_buf[ret] = '\0'; // 确保截断
        TOOL_PRINT_INFO("%s", row_buf);
        byte_no += XSFP_REG_NUM_ONE_ROW;
    }

    return 0;
}

int optical_confirm_required(const struct optical_test_t *info)
{
    if (info->test_mode == CMD_OPTICAL_OPERATE_LOOPBACK || info->cmd == OPTICAL_HIGH_POWER_DISABLE ||
        info->test_mode == CMD_OPTICAL_RESET || info->cmd == OPTICAL_TX_SIGNAL_DISABLE) {
        /* 回环测试：影响 co-groups + 其他程序 */
        return tool_double_check(
            "[WARNING]This optical module set mode will influence co-groups.\n"
            "[WARNING]Running this command may cause errors to other programs "
            "that are using the network port. Please ensure that all other programs "
            "are stopped before proceeding with this command.\n"
            "Are you sure you want to continue?");
    }

    /* 默认情况：仅影响 co-groups */
    return tool_double_check(
        "[WARNING]This optical module set mode will influence co-groups.\n"
        "Are you sure you want to continue?");
}

static int tool_optical_reset_print_result(optical_reset_result_e result)
{
    static struct {
        optical_reset_result_e result;
        char *result_msg;
    } optical_reset_result_msg_map[] = {
        {OPTICAL_RESET_OK, "optical reset success"},
        {OPTICAL_RESET_ERR, "optical reset failed"},
        {OPTICAL_RDFX_ERR_IDX, "optical id not support"},
        {OPTICAL_RDFX_ERR_START, "device start reset optical failed"},
        {OPTICAL_RDFX_ERR_STATUS, "device read reset status failed"},
        {OPTICAL_RDFX_TIMEOUT, "device read reset status timeout"},
        {OPTICAL_NOT_PRESENT, "optical not present"},
    };

    for (int i = 0; i < (int)ARRAY_SIZE(optical_reset_result_msg_map); i++) {
        if (result == optical_reset_result_msg_map[i].result) {
            const char* result_msg = optical_reset_result_msg_map[i].result_msg;
            if (result == OPTICAL_RESET_OK) {
                TOOL_PRINT_INFO("%s", result_msg);
                return 0;
            } else {
                TOOL_PRINT_ERR("%s", result_msg);
                return TOOL_INVALID_RESULT;
            }
        }
    }
    TOOL_PRINT_ERR("optical reset get unknown result. (result=%d)", result);
    return TOOL_INVALID_RESULT;
}

static int tool_optical_reset(struct command_context *ctx)
{
    int ret = 0;
    struct optical_test_t *info = (struct optical_test_t *)ctx->cmd_args;
    optical_reset_result_e reset_result = OPTICAL_RESET_ERR;
    struct product_channel_msg msg = {0};
    const char* reset_type_msg = info->cmd == OPTICAL_RESET_SOFT? "soft" : "hard";

    // root权限确认
    ret = hccn_check_usr_identify();
    CHK_PRT_RETURN(ret != 0, hccn_err("permission denied: only root user is allowed, ret:%d logic_id:%d",
        ret, ctx->npu_info.logic_id), TOOL_PUBLIC_ROOT_UNSUPPORT);

    CHK_PRT_RETURN(ret != 0, hccn_info("User aborts command"), ret);

    info->optical_index = ctx->optical_id;
    SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), &reset_result, sizeof(reset_result));
    ret = product_host_device_channel(ctx, info->test_mode, &msg);
    if (ret != 0) {
        hccn_err("failed to reset optical. (type=%s, ret=%d)", reset_type_msg, ret);
    } else {
        hccn_info("reset optical result returned. (type=%s)", reset_type_msg);
        ret = tool_optical_reset_print_result(reset_result);
    }
    return ret;
}

static int tool_print_optical_info(struct command_context *ctx, optical_power_result_t* power_result)
{
    enum optical_test_result_e task_status = power_result->task_status;
    char* cur_power_status = "unknown";
    if (power_result->power_status == OPTICAL_HIGH_POWER) {
        cur_power_status = "high power";
    } else if (power_result->power_status == OPTICAL_LOW_POWER) {
        cur_power_status = "low power";
    }

    if (task_status == OPTICAL_TEST_SUCC) {
        TOOL_PRINT_INFO("optical set power mode success, current power mod is %s.\n", cur_power_status);
        return TOOL_EXE_SUCCESS;
    } else if (task_status == OPTICAL_TEST_FAIL) {
        TOOL_PRINT_INFO("optical set power mode failed.\n");
        return TOOL_DSMI_ERROR;
    } else if (task_status == OPTICAL_TEST_TIMEOUT) {
        TOOL_PRINT_INFO("optical set power mode task timeout.\n");
        return TOOL_DSMI_ERROR;
    } else {
        TOOL_PRINT_INFO("unknown error.\n");
        return TOOL_INVALID_PARAM;
    }
}

static int tool_optical_power_mode(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct optical_test_t *info = (struct optical_test_t *)ctx->cmd_args;
    info->optical_index = ctx->optical_id;

    optical_power_result_t power_result = {0};
    SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), &power_result,
        sizeof(optical_power_result_t));
    ret = product_host_device_channel(ctx, CMD_OPTICAL_SET_POWER_MODE, &msg);
    if (ret != 0) {
        hccn_err("product_host_device_channel failed. (ret=%d)", ret);
        return ret;
    }
    ret = tool_print_optical_info(ctx, &power_result);
    if (ret != 0) {
        hccn_err("tool_print_optical_info failed. (ret=%d)", ret);
        return ret;
    }
    return ret;
}

static int tool_optical_dump_reg(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct optical_test_t *info = (struct optical_test_t *)ctx->cmd_args;
    info->optical_index = ctx->optical_id;

    unsigned char reg_buf[XSFP_PAGE_REG_MAX_LENGTH] = {0};
    if (info->dump_page_id != 0xFFFFFFFF) {
        SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), reg_buf, sizeof(reg_buf));
    } else {
        SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), NULL, 0);
    }
    ret = product_host_device_channel(ctx, CMD_OPTICAL_OPERATE_DUMP_REG, &msg);
    if (ret == 0 && info->dump_page_id != 0xFFFFFFFF) {
        ret = tool_optical_show_page_info(info, reg_buf);
    }
    return ret;
}

static int optical_assign_tx_signal(struct optical_test_t *info, value_union *type_val)
{
    info->test_mode = CMD_OPTICAL_TX_SIGNAL;
    if (strcmp(type_val->str_val, "enable") == 0) {
        info->cmd = OPTICAL_TX_SIGNAL_ENABLE;
    } else if (strcmp(type_val->str_val, "disable") == 0) {
        info->cmd = OPTICAL_TX_SIGNAL_DISABLE;
    } else {
        hccn_err("Invalid operation.");
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

static int optical_assign_dump_page(struct optical_test_t *info, value_union *type_val)
{
    const char *page_str = type_val->str_val;
    if (!info || !page_str) {
        hccn_err("Invalid input: info or page_str is null.");
        return TOOL_ASSIGN_UNKNOWN;
    }

    // 1. 设置测试模式
    info->test_mode = CMD_OPTICAL_OPERATE_DUMP_REG;

    // 2. 处理 "all" 情况
    if (strcmp(page_str, "all") == 0) {
        info->cmd = OPTICAL_DUMP_REG_ALL;
        info->dump_page_id = 0xFFFFFFFF;
        return 0;
    }

    // 3. 处理十六进制页号 (0x00 - 0xFF)
    char *p_end_str = NULL;
    unsigned long page_id = strtoul(page_str, &p_end_str, NUMBER_HEX);
    // 校验：
    // - p_end_str 必须指向字符串结束符，说明整个字符串都被解析了
    // - 值必须在 0x00 到 0xFF 之间
    if (*p_end_str != '\0' || page_id > 0xFF) {
        hccn_err("Invalid page id: '%s'. Must be 0x00-0xFF or 'all'.", page_str);
        return TOOL_ASSIGN_UNKNOWN;
    }

    // 4. 正常设置
    info->cmd = OPTICAL_DUMP_REG_SPECIFIED;
    info->dump_page_id = (unsigned int)page_id;

    return 0;
}

static int optical_assign_loopback(struct optical_test_t *info, value_union *type_val)
{
    info->test_mode = CMD_OPTICAL_OPERATE_LOOPBACK;
    info->loopback_mode = type_val->int_val;
    return 0;
}

static int optical_assign_reset(struct optical_test_t *info, value_union *type_val)
{
    info->test_mode = CMD_OPTICAL_RESET;
    if (strcmp(type_val->str_val, "soft_reset") == 0) {
        info->cmd = OPTICAL_RESET_SOFT;
    } else if (strcmp(type_val->str_val, "hard_reset") == 0) {
        info->cmd = OPTICAL_RESET_HARD;
    } else {
        hccn_err("Invalid operation.");
        return TOOL_INVALID_PARAM;
    }
    return 0;
}

static int optical_assign_power(struct optical_test_t *info, value_union *type_val)
{
    info->test_mode = CMD_OPTICAL_SET_POWER_MODE;
    if (strcmp(type_val->str_val, "enable") == 0) {
        info->cmd = OPTICAL_HIGH_POWER_ENABLE;
    } else if (strcmp(type_val->str_val, "disable") == 0) {
        info->cmd = OPTICAL_HIGH_POWER_DISABLE;
    } else {
        hccn_err("Invalid operation.");
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

static struct {
    char* arg_opt;
    int (*func)(struct optical_test_t *info, value_union *type_val);
} g_optical_test_parser[] = {
    {"-tx_signal", optical_assign_tx_signal},
    {"-dump_page", optical_assign_dump_page},
    {"-loopback_mode", optical_assign_loopback},
    {"-reset_mode", optical_assign_reset},
    {"-high_power", optical_assign_power},
};

int optical_assign_test(struct optical_test_t *info, struct sub_option_entry *opt, value_union *type_val)
{
    // 后面用于处理Test命令行，只支持同时执行一个命令
    // 如果已经指定了其他命令，则返回错误
    if (info->test_mode != 0) {
        hccn_err("Already have specified other command.");
        return TOOL_CONFLICT_INPUT;
    }

    for (int i = 0; i < (int)ARRAY_SIZE(g_optical_test_parser); i++) {
        if (strcmp(opt->name, g_optical_test_parser[i].arg_opt) == 0) {
            return g_optical_test_parser[i].func(info, type_val);
        }
    }

    hccn_err("Invalid operation.");
    return TOOL_ASSIGN_UNKNOWN;
}

int parse_dump_page(struct optical_test_t *info, const char *page_str)
{
    if (!info || !page_str) {
        hccn_err("Invalid input: info or page_str is null.");
        return TOOL_ASSIGN_UNKNOWN;
    }

    // 1. 设置测试模式
    info->test_mode = CMD_OPTICAL_OPERATE_DUMP_REG;

    // 2. 处理 "all" 情况
    if (strcmp(page_str, "all") == 0) {
        info->cmd = OPTICAL_DUMP_REG_ALL;
        info->dump_page_id = 0xFFFFFFFF;
        return 0;
    }

    // 3. 处理十六进制页号 (0x00 - 0xFF)
    char *p_end_str = NULL;
    unsigned long page_id = strtoul(page_str, &p_end_str, NUMBER_HEX);
    // 校验：
    // - p_end_str 必须指向字符串结束符，说明整个字符串都被解析了
    // - 值必须在 0x00 到 0xFF 之间
    if (*p_end_str != '\0' || page_id > 0xFF) {
        hccn_err("Invalid page id: '%s'. Must be 0x00-0xFF or 'all'.", page_str);
        return TOOL_ASSIGN_UNKNOWN;
    }

    // 4. 正常设置
    info->cmd = OPTICAL_DUMP_REG_SPECIFIED;
    info->dump_page_id = (unsigned int)page_id;

    return 0;
}

int tool_test_optical_exec(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct optical_param_t *param = (struct optical_param_t *)ctx->cmd_args;
    struct optical_test_t *info = NULL;

    if (param == NULL) {
        hccn_err("get invalid param.\n");
        return TOOL_PRIVATE_ARGS_NUM_ERR;
    }
    info = &param->info;

    if (info->test_mode != CMD_OPTICAL_OPERATE_DUMP_REG) {
        ret = optical_confirm_required(info);
    }
    if (ret) {
        hccn_err("hccn tool command aborts by user. (set optical mode)");
        return ret;
    }

    info->optical_index = ctx->optical_id;
    switch (info->test_mode) {
        case CMD_OPTICAL_TX_SIGNAL:
            SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), NULL, 0);
            ret = product_host_device_channel(ctx, CMD_OPTICAL_TX_SIGNAL, &msg);
            break;
        case CMD_OPTICAL_OPERATE_DUMP_REG:
            ret = tool_optical_dump_reg(ctx);
            break;
        case CMD_OPTICAL_OPERATE_LOOPBACK:
            SET_PRODUCT_MSG(msg, info, sizeof(struct optical_test_t), NULL, 0);
            ret = product_host_device_channel(ctx, CMD_OPTICAL_OPERATE_LOOPBACK, &msg);
            break;
        case CMD_OPTICAL_RESET:
            ret = tool_optical_reset(ctx);
            break;
        case CMD_OPTICAL_SET_POWER_MODE:
            ret = tool_optical_power_mode(ctx);
            break;
        default:
            return TOOL_INVALID_PARAM;
    }

    if (ret != 0) {
        hccn_err("optical send channel message failed. (ret=%d)", ret);
    }

    return ret;
}