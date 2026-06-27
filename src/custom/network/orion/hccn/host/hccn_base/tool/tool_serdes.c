/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "ds_data.h"
#include "hccn_log.h"
#include "tool_cmd_parse.h"
#include "tool_lib.h"
#include "tool_comm.h"
#include "tool_cmd_err.h"
#include "tool_errcode.h"
#include "tool_table.h"
#include "serdes_com.h"
#include "tool_serdes.h"

static int tool_serdes_info_common(struct command_context *ctx, unsigned int sds_type,
                                   void *info, size_t size)
{
    int ret;
    struct product_channel_msg msg = {0};
    
    (void)memset_s(info, size, 0, size);
    SET_PRODUCT_MSG(msg, &sds_type, sizeof(unsigned int), info, size);

    ret = product_host_device_channel(ctx, CMD_GET_SERDES, &msg);
    if (ret) {
        hccn_err("tool get serdes info failed. (sds_type=%u, ret=%d)", sds_type, ret);
    }
    return ret;
}

static int tool_get_serdes_snr(struct command_context *ctx, struct serdes_info_t *data, size_t size)
{
    return tool_serdes_info_common(ctx, SERDES_SNR_INFO, (void *)data, size);
}

static int tool_get_serdes_tx_fir(struct command_context *ctx, struct serdes_info_t *data, size_t size)
{
    return tool_serdes_info_common(ctx, SERDES_TX_FIR_INFO, (void *)data, size);
}

static int tool_print_serdes_info(struct command_context *ctx, struct serdes_info_print_t info)
{
    int ret;
    unsigned int i;
    unsigned int start = info.lane_start;
    unsigned int count = info.lane_cnt;

    ret = malloc_table_advance("IUP", count, TOOL_TABLE_COL_7,
                               "Lane",      TYPE_CHAR,
                               "snr",       TYPE_UINT,
                               "fir pre2",  TYPE_INT,
                               "fir pre1",  TYPE_INT,
                               "fir main",  TYPE_UINT,
                               "fir post1", TYPE_INT,
                               "fir post2", TYPE_INT);
    if (ret) {
        hccn_err("alloc table show serdes failed.");
        return TOOL_TABLE_ERROR;
    }

    for (i = 0; (i < count) && (start + i) < PORT_LANE_CNT; i++) {
        ret += SET_ENTIRE_ROW(i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
                              start + i,
                              info.snr_info[i].snr,
                              info.tx_fir_info[i].tx_fir.fir_pre2,
                              info.tx_fir_info[i].tx_fir.fir_pre1,
                              info.tx_fir_info[i].tx_fir.fir_main,
                              info.tx_fir_info[i].tx_fir.fir_post1,
                              info.tx_fir_info[i].tx_fir.fir_post2);
    }
    if (ret) {
        hccn_err("write table show serdes failed.");
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

int tool_serdes_exec(struct command_context *ctx)
{
    int ret;
    struct serdes_info_t data = {0};
    struct serdes_info_print_t all = {0};

    ret = tool_get_serdes_snr(ctx, &data, sizeof(struct serdes_info_t));
    if (ret) {
        return ret;
    }
    memcpy_s(all.snr_info, sizeof(all.snr_info), data.info.snr_info, sizeof(all.snr_info));
    
    ret = tool_get_serdes_tx_fir(ctx, &data, sizeof(struct serdes_info_t));
    if (ret) {
        return ret;
    }
    memcpy_s(all.tx_fir_info, sizeof(all.tx_fir_info), data.info.tx_fir_info, sizeof(all.tx_fir_info));

    all.lane_start = data.lane_start;
    all.lane_cnt = data.lane_cnt;

    return tool_print_serdes_info(ctx, all);
}

void tool_serdes_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_serdes_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-serdes", "get serdes info");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}