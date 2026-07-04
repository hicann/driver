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
#include "tool_cmd_parse.h"
#include "tool_comm.h"
#include "tool_serdes.h"
#include "ascend_hal.h"
#include "securec.h"
#include "tool_errcode.h"
#include "ds_net_interface.h"
#include "comm_channel.h"
#include "tool_cmd_err.h"
#include "dsmi_common_product.h"
#include "dsmi_common_interface.h"
#include "tool_product.h"

static int cmpfunc(const void *a, const void *b)
{
    return *(long*)a - *(long*)b;
}

void get_ub_ping_result(struct ub_ping_operate *ping_args, struct ub_ping_result *ping_result,
    long *cost_time, int time_size)
{
    int seq = 0;
    long sum_time = 0, recv_num = 0;

    if (ping_result->suc_pkt_num == 0) {
        return;
    }
    for (seq = 0; seq < time_size; seq++) {
        if (cost_time[seq] > 0) {
                sum_time += cost_time[seq];
                cost_time[recv_num++] = cost_time[seq];
        }
    }
    ping_result->avg_time = recv_num == 0 ? 0 : sum_time / recv_num;
    qsort(cost_time, recv_num, sizeof(long), cmpfunc);
    ping_result->tp95_time = cost_time[(int)((PERCENT_NINETY_FIVE * recv_num) / CHANGE_TO_PERCENT)];
}

EXPORT_FUNCTION int dsmi_get_ub_ping_info(struct command_context *ctx, struct ub_ping_operate *ping_args,
    struct ub_ping_result* ping_result, bool flag)
{
    struct product_channel_msg msg = {0};
    int ret, pkt_idx;
    char tmp_str[PING_RESULT_BUF_SIZE] = {0};
    long *cost_time = calloc(ping_args->pkt_send_num, sizeof(long));
 
    if (cost_time == NULL) {
        hccn_err("calloc cost time array failed. (num=%d)", ping_args->pkt_send_num);
        return DRV_ERROR_MEMORY_OPT_FAIL;
    }

    for (pkt_idx = 0; pkt_idx < ping_args->pkt_send_num; pkt_idx++) {
        SET_PRODUCT_MSG(msg, (char *)ping_args, sizeof(struct ub_ping_operate), &cost_time[pkt_idx], sizeof(long));
        ret = product_host_device_channel(ctx, CMD_GET_UB_PING_INFO, &msg);
        if (ret) {
            hccn_err("get ub_ping info failed. (ret=%d, pkt_idx=%d)", ret, pkt_idx);
            free(cost_time);
            return ret;
        }
        switch (cost_time[pkt_idx]) {
            case 0:
                ping_result->fail_pkt_num++;
                ret = sprintf_s(tmp_str, PING_RESULT_BUF_SIZE, "recv time out seq:%u", pkt_idx);
                break;
            case PKT_SEND_FAIL:
                ping_result->fail_pkt_num++;
                ret = sprintf_s(tmp_str, PING_RESULT_BUF_SIZE, "pkt send fail seq:%u", pkt_idx);
                break;
            default:
                ping_result->max_time = ping_result->max_time < cost_time[pkt_idx] ?
                    cost_time[pkt_idx] : ping_result->max_time;
                ping_result->min_time = (ping_result->min_time > cost_time[pkt_idx] ||
                    ping_result->min_time == 0) ? cost_time[pkt_idx] : ping_result->min_time;
                ping_result->suc_pkt_num++;
                ret = sprintf_s(tmp_str, PING_RESULT_BUF_SIZE, "recv seq:%u,time:%ld.%06ldms", pkt_idx,
                    cost_time[pkt_idx] / NS_CHANGE_TO_US, (cost_time[pkt_idx] % NS_CHANGE_TO_US) * NS_CHANGE_TO_US);

                break;
        }
        if (ret <= 0) {
            hccn_err("sprintf_s failed. (ret=%d, pkt_idx=%d)", ret, pkt_idx);
            free(cost_time);
            return DRV_ERROR_MEMORY_OPT_FAIL;
        }
        if (flag) {
            TOOL_PRINT_INFO("%s", tmp_str);
        }
    }
    get_ub_ping_result(ping_args, ping_result, cost_time, ping_args->pkt_send_num);
    free(cost_time);
    return 0;
}