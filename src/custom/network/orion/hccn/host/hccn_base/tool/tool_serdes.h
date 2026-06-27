/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_SERDES_H
#define TOOL_SERDES_H
 
#include "tool_comm.h"
#include "serdes_com.h"

struct serdes_info_print_t {
    struct snr_info_t snr_info[PORT_LANE_CNT];
    struct tx_fir_info_t tx_fir_info[PORT_LANE_CNT];
    unsigned int lane_start;
    unsigned int lane_cnt;
};

int tool_serdes_exec(struct command_context *ctx);
void tool_serdes_help(struct command_context *ctx, unsigned int mode);

#endif