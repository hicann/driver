/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <string.h>
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
#include "dsmi_common_interface.h"
#include "dsmi_common_product.h"

#include "tool_port_dfx.h"

/* Forward declaration: dsmi_network_transmission_channel is defined in
 * ds_net_interface.c; its header is outside this component's include path */
struct ds_trans_data;
int dsmi_network_transmission_channel(int logic_id, struct ds_trans_data *trans_data);

STATIC int load_data_to_target(void **dst, unsigned int *dst_len, void *src, unsigned int src_len)
{
    int ret;
    if (src_len == 0) {
        return 0;
    }
    ret = memcpy_s(*dst, *dst_len, src, src_len);
    *dst = *dst + src_len;
    *dst_len = *dst_len - src_len;
    return ret;
}

// 产品专用消息通道，使用comm_channel.h里的命令字。下发的数据格式为[ctx cmd size_in size_out inbuf]，回传的数据为[outbuf]
// 传递ctx是为了与海思对齐，承载-i/-d等通用信息，虽说数据冗余较大。传递cmd是产品专属子命令机制，size_in/size_out是H2D通道上会自动放大size，需要自行传输保证准确
EXPORT_FUNCTION int product_host_device_channel(struct command_context *ctx, unsigned int cmd, struct product_channel_msg *msg)
{
    unsigned int size, temp_size;
    void *buffer, *temp_buffer;
    struct ds_trans_data trans_data = {0};
    int ret;

    // [ctx cmd size_in size_out inbuf]
    size = sizeof(struct command_context) + sizeof(unsigned int) +
               sizeof(unsigned int) + sizeof(unsigned int) + msg->inlen;
    buffer = calloc(1, size);
    if (buffer == NULL) {
        hccn_err("alloc h2d channel msg failed.\n");
        return TOOL_ENOMEM;
    }

    temp_buffer = buffer;
    temp_size = size;
    ret = load_data_to_target(&temp_buffer, &temp_size, ctx, sizeof(struct command_context));
    ret += load_data_to_target(&temp_buffer, &temp_size, &cmd, sizeof(unsigned int));
    ret += load_data_to_target(&temp_buffer, &temp_size, &msg->inlen, sizeof(unsigned int));
    ret += load_data_to_target(&temp_buffer, &temp_size, &msg->outlen, sizeof(unsigned int));
    ret += load_data_to_target(&temp_buffer, &temp_size, msg->inbuf, msg->inlen);
    if (unlikely(ret != 0 || temp_size != 0)) {
        hccn_err("load data onto h2d channel failed. (ret=%d, temp_size=%d)", ret, temp_size);
        free(buffer);
        return ret;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_PRODUCT_EXE, buffer, size, msg->outbuf, &msg->outlen);
    ret = dsmi_network_transmission_channel(ctx->npu_info.logic_id, &trans_data);
    free(buffer);
    if (ret != 0) {
        hccn_err("dsmi transmission failed. (ret=%d; logic_id=%d)", ret, ctx->npu_info.logic_id);
        return ret;
    }

    return trans_data.result;
}