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
#include "ds_net_interface.h"
#include "hccn_err.h"
#include "ds_data.h"
#include "tool_param.h"
#include "tool_cmd_err.h"
#include "dev_info_data.h"
#include "tool_dev_info.h"
#include "ubase_cmd_data.h"

struct sub_option_entry bandwidth_opts_param[] = {
    {
        "-time", ARG_TYPE_INT, parse_int, MODE_GET, MODE_NONE,
        false, .range.int_range = {0, MAX(BW_MAX_TIME_VAL, PK_BW_MAX_TIME_VAL)}
    },
};

void get_bandwidth_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    *sub_opts = bandwidth_opts_param;
    *count = ARRAY_SIZE_COMPUTE(bandwidth_opts_param);
}

void *alloc_bandwidth_args_init(void)
{
    return calloc(1, sizeof(struct bandwidth_cmd_args));
}

int bandwidth_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct bandwidth_cmd_args *bw_args = (struct bandwidth_cmd_args *)args;

    if (strcmp(opt->name, "-time") == 0) {
        bw_args->time_interval = (unsigned int)type_val->int_val;
    }

    return 0;
}

int tool_peak_bw_exec(struct command_context *ctx)
{
    struct bandwidth_cmd_args bw_args = {.time_interval = PK_BW_DEFAULT_TIME};
    unsigned int size = sizeof(struct bandwidth_t);
    struct bandwidth_t peak_bw = {0};
    struct dsmi_info info = {0};
    int ret = 0;

    if (ctx->cmd_args != NULL) {
        bw_args = *((struct bandwidth_cmd_args *)ctx->cmd_args);
        CHK_PRT_RETURN(bw_args.time_interval < PK_BW_MIN_TIME_VAL || bw_args.time_interval > PK_BW_MAX_TIME_VAL,
            TOOL_PRINT_ERR("Option [-time %d] is out of range [%d, %d].",
            (int)bw_args.time_interval, PK_BW_MIN_TIME_VAL, PK_BW_MAX_TIME_VAL), TOOL_PRIVATE_ARGS_VALUE_ERR);
    }

    ctx->result = (char *)&peak_bw;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), (char *)&bw_args,
        sizeof(struct bandwidth_cmd_args), ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_PEAK_BANDWIDTH, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get peak bandwidth failed, ret:%d", ret), ret);

    TOOL_PRINT_INFO("Peak Bandwidth TX: %10.02f MB/sec\nPeak Bandwidth RX: %10.02f MB/sec",
        peak_bw.tx_bandwidth, peak_bw.rx_bandwidth);

    return 0;
}

void tool_peak_bw_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_peak_bw_print_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-peak_bw", "get tx/rx peak bandwidth");
            tool_print_npu_info(DEV_PORT_TYPE);
            TOOL_PRINT_OPT("[-time <time_val>]", "specify time period to measure bandwidth, "
                "default 200ms, range [1, 226] ms");
            break;
        default:
            break;
    }
}

int tool_ub_bandwidth_exec(struct command_context *ctx, struct bandwidth_cmd_args *bw_args)
{
    unsigned int size = sizeof(struct bandwidth_t);
    struct bandwidth_t bw_t = {0};
    struct dsmi_info info = {0};
    int ret;

    ctx->result = (char *)&bw_t;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), (char *)bw_args,
        sizeof(struct bandwidth_cmd_args), ctx->result, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_UB_BANDWIDTH, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get ub bandwidth failed, ret:%d", ret), ret);

    TOOL_PRINT_INFO("Bandwidth TX: %10.02f MB/sec\nBandwidth RX: %10.02f MB/sec",
        bw_t.tx_bandwidth, bw_t.rx_bandwidth);

    return 0;
}

STATIC int tool_get_uboe_bandwidth(struct command_context *ctx, struct bandwidth_cmd_args *bw_args)
{
    unsigned int size_out = sizeof(struct bandwidth_t);
    struct bandwidth_t bw_t = {0};
    struct dsmi_info info = {0};
    int ret;

    ctx->result = (char *)&bw_t;
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), (char *)bw_args,
        sizeof(struct bandwidth_cmd_args), ctx->result, &size_out);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_UBOE_BANDWIDTH, &info);
    CHK_PRT_RETURN(ret != 0, hccn_err("dsmi get uboe bandwidth failed, ret:%d name:%s", ret, ctx->dev_name), ret);

    TOOL_PRINT_INFO("[dev_name: %s] get bandwidth result:", ctx->dev_name);
    TOOL_PRINT_INFO("Bandwidth TX: %10.02f MB/sec\nBandwidth RX: %10.02f MB/sec",
        bw_t.tx_bandwidth, bw_t.rx_bandwidth);

    return 0;
}

STATIC int tool_uboe_bandwidth_exec(struct command_context *ctx, struct bandwidth_cmd_args *bw_args)
{
    struct netdev_info ndev_info = {0};
    unsigned int err_count = 0;
    int ret;
    int i;

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    ret = tool_get_bond_slaves(ctx, &ndev_info);
    CHK_PRT_RETURN(ret != 0, hccn_err("get bond slaves failed, ret:%d", ret), ret);

    for (i = 0; i < DEV_INFO_DEFAULT_BOND_SLAVE_NUM; i++) {
        (void)memset_s(ctx->dev_name, MAX_DEV_NAME_LEN, 0, MAX_DEV_NAME_LEN);
        ret = strncpy_s(ctx->dev_name, MAX_DEV_NAME_LEN,
            ndev_info.bond_info.slaves_ifname[i], strlen(ndev_info.bond_info.slaves_ifname[i]));
        CHK_PRT_RETURN(ret != 0, hccn_err("copy slave_name to ctx->dev_name failed, ret:%d", ret), ret);

        ret = tool_get_uboe_bandwidth(ctx, bw_args);
        if (ret != 0) {
            err_count++;
            hccn_err("tool get uboe bandwidth failed, ret:%d name:%s err_count:%u", ret, ctx->dev_name, err_count);
            TOOL_PRINT_ERR("[dev_name:%s] get bandwidth result failed!", ctx->dev_name);
        }
    }

    return (err_count == DEV_INFO_DEFAULT_BOND_SLAVE_NUM) ? ret : 0;
}

int tool_bandwidth_exec(struct command_context *ctx)
{
    struct bandwidth_cmd_args bw_args = {.time_interval = BW_DEFAULT_TIME};
    int ret;

    if (ctx->cmd_args != NULL) {
        bw_args = *((struct bandwidth_cmd_args *)ctx->cmd_args);
        CHK_PRT_RETURN(bw_args.time_interval < BW_MIN_TIME_VAL || bw_args.time_interval > BW_MAX_TIME_VAL,
            TOOL_PRINT_ERR("Option [-time %d] is out of range [%d, %d].",
            (int)bw_args.time_interval, BW_MIN_TIME_VAL, BW_MAX_TIME_VAL), TOOL_PRIVATE_ARGS_VALUE_ERR);
    }

    if (ctx->dev_mask == DEV_PORT_TYPE) {
        ret = tool_ub_bandwidth_exec(ctx, &bw_args);
        CHK_PRT_RETURN(ret != 0, hccn_err("tool_ub_bandwidth_exec failed, ret:%d", ret), ret);
    } else { // ctx->dev_mask == DEV_DEV_ATTR
        ret = tool_uboe_bandwidth_exec(ctx, &bw_args);
        CHK_PRT_RETURN(ret != 0, hccn_err("tool_uboe_bandwidth_exec failed, ret:%d", ret), ret);
    }

    return 0;
}

void tool_bandwidth_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_bandwidth_print_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-bandwidth", "get ub tx/rx bandwidth");
            tool_print_npu_info(DEV_PORT_TYPE);
            TOOL_PRINT_OPT("[-time <time_val>]", "specify time period to measure ub bandwidth, "
                "default 1000ms, range [100, 10000] ms");

            TOOL_PRINT_CMD("-g", "-bandwidth", "get uboe tx/rx bandwidth");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-time <time_val>]", "specify time period to measure uboe bandwidth, "
                "default 1000ms, range [100, 10000] ms");
            break;
        default:
            break;
    }
}
