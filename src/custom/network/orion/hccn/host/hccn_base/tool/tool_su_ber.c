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
#include <ctype.h>
#include "ds_data.h"
#include "tool_cmd_parse.h"
#include "tool_comm.h"
#include "ascend_hal.h"
#include "securec.h"
#include "tool_errcode.h"
#include "ds_net_interface.h"
#include "comm_product.h"
#include "tool_cmd_err.h"
#include "dsmi_common_interface.h"
#include "tool_lib.h"
#include "tool_table.h"
#include "tool_su_ber.h"

void get_su_ber_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry param_list[] = {
        {"-mode", ARG_TYPE_STR, parse_str, MODE_TEST, MODE_TEST, true, .range.str_range = {MAX_STR_VAL_LEN}},
        {"-mode_status", ARG_TYPE_NONE, parse_none, MODE_GET},
        {"-result", ARG_TYPE_NONE, parse_none, MODE_GET},
        {"-clear", ARG_TYPE_NONE, parse_none, MODE_SET, MODE_SET},
    };
    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}

void *alloc_su_ber_args(void)
{
    return calloc(1, sizeof(struct su_ber_data_t));
}

int su_ber_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    const char *name = opt->name;
    struct su_ber_data_t *data = (struct su_ber_data_t *)args;

    if (strcmp(name, "-mode") == 0) {
        if (strcmp(type_val->str_val, "tx_enable") == 0) {
            data->mode = SU_BER_MODE_TX_ENABLE;
        } else if (strcmp(type_val->str_val, "rx_enable") == 0) {
            data->mode = SU_BER_MODE_RX_ENABLE;
        } else if (strcmp(type_val->str_val, "stop") == 0) {
            data->mode = SU_BER_MODE_STOP;
        } else {
            return TOOL_ASSIGN_UNKNOWN;
        }
    } else if (strcmp(name, "-mode_status") == 0) {
        data->mode = SU_BER_MODE_STATUS;
    } else if (strcmp(name, "-result") == 0) {
        data->mode = SU_BER_MODE_GET_RESULT;
    } else if (strcmp(name, "-clear") == 0) {
        data->mode = SU_BER_MODE_CLEAR;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }

    return 0;
}

static int tool_su_ber_print_basic_info(struct command_context *ctx, struct su_ber_cnt_info *info)
{
    int ret = 0;
    struct table_header_t header[] = {
        {"su_itlv_mode",    TYPE_STR},
        {"status",          TYPE_STR},
    };
    size_t header_size = ARRAY_SIZE_COMPUTE(header);
    if (malloc_table_prefix_t(DEV_PORT_TYPE, 1, header_size, header) != 0) {
        hccn_err("alloc table su_ber info failed.");
        return TOOL_TABLE_ERROR;
    }

    const char *itlv_modes[] = {
        [SU_BER_ITLV_MODE_NON_ITLV] = "non-itlv",
        [SU_BER_ITLV_MODE_ITLV] = "itlv",
    };
    const char *itlv_mode = NULL;
    if (info->su_itlv_mode < 0 || info->su_itlv_mode >= ARRAY_SIZE_COMPUTE(itlv_modes)) {
        itlv_mode = "Unknown";
    } else {
        itlv_mode = itlv_modes[info->su_itlv_mode];
    }

    const char *statuses[] = {
        [SU_BER_MODE_STOP] = "stop",
        [SU_BER_MODE_RX_ENABLE] = "rx_enable",
        [SU_BER_MODE_TX_ENABLE] = "tx_enable",
    };
    const char *status = NULL;
    if (info->su_ber_status < 0 || info->su_ber_status >= ARRAY_SIZE_COMPUTE(statuses)) {
        status = "N/a";
    } else {
        status = statuses[info->su_ber_status];
    }

    ret += SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, itlv_mode, status);
    if (ret != 0) {
        hccn_err("write table row show su_ber info failed.");
        goto TABLE_ERR;
    }

    ret = print_table();
    if (ret != 0) {
        hccn_err("print table show su_ber info failed.");
        goto TABLE_ERR;
    }

    clean_table();
    return 0;

TABLE_ERR:
    clean_table();
    return TOOL_TABLE_ERROR;
}

static int get_su_ber_rate(int lane_id, struct su_ber_frm_cnt_err_info *info, char *su_ber_rate, int rate_len)
{
    int ret;
    double bit_err_rate = 0.0;

    if (info->frm_cnt[lane_id] != 0 && info->frm_bit != 0) {
        bit_err_rate = (double)info->bit_err_cnt[lane_id] / ((double)info->frm_cnt[lane_id] * info->frm_bit);
    }

    ret = snprintf_s(su_ber_rate, rate_len, rate_len - 1, "%e", bit_err_rate);
    if (ret <= 0) {
        hccn_err("format su_ber_rate error. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int get_su_err_frame_rate(int lane_id, struct su_ber_frm_cnt_err_info *info,
                                 char *su_err_frame_rate, int rate_len)
{
    int ret;
    double frame_err_rate = 0.0;

    if (info->frm_cnt[lane_id] != 0) {
        frame_err_rate = (double)info->err_symb_t4[lane_id] / (double)info->frm_cnt[lane_id];
    }

    ret = snprintf_s(su_err_frame_rate, rate_len, rate_len - 1, "%e", frame_err_rate);
    if (ret <= 0) {
        hccn_err("format su_err_frame_rate error. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_su_ber_print_result(struct command_context *ctx, struct su_ber_frm_cnt_err_info *info)
{
    int ret, lane_id;
    static char su_ber_rate[MAX_LANE_NUMBER_PER_PORT][SU_BER_RATE_LEN] = {0};
    static char su_err_frame_rate[MAX_LANE_NUMBER_PER_PORT][ERR_FRAME_RATE_LEN] = {0};
    struct table_header_t header[] = {
        {"Lane", TYPE_HEX},
        {"Done", TYPE_HEX},
        {"Bit_err_cnt", TYPE_HEX},
        {"Err_symb_t4", TYPE_HEX},
        {"Frm_cnt", TYPE_HEX},
        {"Frm_bit", TYPE_HEX},
        {"Su_ber_rate", TYPE_STR},
        {"Su_err_frame_rate", TYPE_STR}
    };
    size_t header_size = ARRAY_SIZE_COMPUTE(header);
    if (malloc_table_prefix_t(DEV_PORT_TYPE, MAX_LANE_NUMBER_PER_PORT, header_size, header) != 0) {
        hccn_err("alloc table show speed failed.");
        return TOOL_TABLE_ERROR;
    }

    for (lane_id = 0; lane_id < MAX_LANE_NUMBER_PER_PORT; lane_id++) {
        ret = get_su_ber_rate(lane_id, info, su_ber_rate[lane_id], SU_BER_RATE_LEN);
        if (ret != 0) {
            goto TABLE_ERR;
        }

        ret = get_su_err_frame_rate(lane_id, info, su_err_frame_rate[lane_id], ERR_FRAME_RATE_LEN);
        if (ret != 0) {
            goto TABLE_ERR;
        }

        ret = SET_ENTIRE_ROW(lane_id, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, lane_id,
            info->done_status[lane_id], info->bit_err_cnt[lane_id], info->err_symb_t4[lane_id], info->frm_cnt[lane_id],
            info->frm_bit, su_ber_rate[lane_id], su_err_frame_rate[lane_id]);
        if (ret != 0) {
            hccn_err("set table data failed. (lane=%d)", lane_id);
            goto TABLE_ERR;
        }
    }

    ret = print_table();
    if (ret != 0) {
        hccn_err("print table show su_ber statistics info failed.");
        goto TABLE_ERR;
    }

    clean_table();
    return 0;

TABLE_ERR:
    clean_table();
    return TOOL_TABLE_ERROR;
}

static int tool_su_ber_set_clear(struct command_context *ctx)
{
    int ret = 0;
    struct su_ber_data_t *data = NULL;
    struct product_channel_msg msg = {0};

    data = (struct su_ber_data_t *)ctx->cmd_args;
    SET_PRODUCT_MSG(msg, data, sizeof(struct su_ber_data_t), NULL, 0);

    ret = product_host_device_channel((struct command_context *)ctx, CMD_SU_BER_SET_CLEAR, &msg);
    if (ret != 0) {
        hccn_err("su_ber send channel message failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_su_ber_test_mode(struct command_context *ctx)
{
    int ret = 0;
    struct su_ber_data_t *data = NULL;
    struct product_channel_msg msg = {0};

    data = (struct su_ber_data_t *)ctx->cmd_args;
    SET_PRODUCT_MSG(msg, data, sizeof(struct su_ber_data_t), NULL, 0);

    ret = product_host_device_channel((struct command_context *)ctx, CMD_SU_BER_TEST_MODE, &msg);
    if (ret != 0) {
        hccn_err("su_ber send channel message failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_su_ber_get_mode_status(struct command_context *ctx)
{
    int ret = 0;
    struct su_ber_cnt_info info = {0};
    struct su_ber_data_t *data = NULL;
    struct product_channel_msg msg = {0};

    info.su_itlv_mode = SU_BER_ITLV_MODE_NON_ITLV;
    data = (struct su_ber_data_t *)ctx->cmd_args;
    SET_PRODUCT_MSG(msg, data, sizeof(struct su_ber_data_t), &info, sizeof(struct su_ber_cnt_info));
    ret = product_host_device_channel((struct command_context *)ctx, CMD_SU_BER_GET_MODE_STATUS, &msg);
    if (ret != 0) {
        hccn_err("get su_ber cnt info failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_su_ber_print_basic_info(ctx, &info);
    if (ret != 0) {
        hccn_err("su_ber print basic info failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_su_ber_get_result(struct command_context *ctx)
{
    int ret = 0;
    struct su_ber_frm_cnt_err_info info = {0};
    struct su_ber_data_t *data = NULL;
    struct product_channel_msg msg = {0};

    data = (struct su_ber_data_t *)ctx->cmd_args;
    SET_PRODUCT_MSG(msg, data, sizeof(struct su_ber_data_t), &info, sizeof(struct su_ber_frm_cnt_err_info));

    ret = product_host_device_channel((struct command_context *)ctx, CMD_SU_BER_GET_RESULT, &msg);
    if (ret != 0) {
        hccn_err("get su_ber frm cnt err info failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_su_ber_print_result(ctx, &info);
    if (ret != 0) {
        hccn_err("su_ber print extra info failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

int tool_su_ber_exec(struct command_context *ctx)
{
    int ret = 0;
    struct su_ber_data_t *data = NULL;

    if (!tool_is_pcie_board(ctx)) {
        hccn_err("su_ber only support on pcie card.");
        return TOOL_UNSUPPORT_BOARD;
    }

    if (ctx->cmd_args == NULL) {
        hccn_err("ctx->cmd_args is NULL");
        return TOOL_PRIVATE_ARGS_NUM_ERR;
    }

    data = (struct su_ber_data_t *)ctx->cmd_args;
    data->macro_id = (unsigned int)ctx->port_id;

    switch (ctx->mode) {
        case MODE_GET:
            if (data->mode == SU_BER_MODE_STATUS) {
                ret = tool_su_ber_get_mode_status(ctx);
            } else {
                ret = tool_su_ber_get_result(ctx);
            }
            break;
        case MODE_SET:
            ret = tool_su_ber_set_clear(ctx);
            break;
        case MODE_TEST:
            ret = tool_su_ber_test_mode(ctx);
            break;
        default:
            hccn_err("su_ber unknown mode. (mode=%d)", ctx->mode);
            return TOOL_INVALID_PARAM;
    }
    if (ret != 0) {
        hccn_err("su_ber process failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

void tool_su_ber_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_su_ber_help(ctx, MODE_GET);
            tool_su_ber_help(ctx, MODE_SET);
            tool_su_ber_help(ctx, MODE_TEST);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-su_ber", "Get su_ber statistics result or statistics mode.");
            tool_print_npu_info(DEV_PORT_TYPE);
            TOOL_PRINT_OPT("[-mode_status]", "Get su_ber statistics mode.");
            TOOL_PRINT_OPT("[-result]", "Get su_ber statistics result.");
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-su_ber", "Set su_ber statistics mode.");
            tool_print_npu_info(DEV_PORT_TYPE);
            TOOL_PRINT_OPT("-clear", "Clear su_ber statistics data and recycle resources.");
            break;
        case MODE_TEST:
            TOOL_PRINT_CMD("-t", "-su_ber", "Change su_ber status");
            tool_print_npu_info(DEV_PORT_TYPE);
            TOOL_PRINT_OPT("-mode <rx_enable|tx_enable|stop>", "Set su_ber statistics mode to given mode.");
            break;
        default:
            break;
    }
}
