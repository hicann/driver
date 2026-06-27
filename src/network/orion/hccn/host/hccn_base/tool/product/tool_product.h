/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_PRODUCT_H
#define TOOL_PRODUCT_H

#include "tool_comm.h"
#include "tool_cfg_ops.h"
#ifdef ENABLE_BUILD_PRODUCT
void tool_get_product_cmds(struct cmd_entry **cmds, unsigned int *count);
int tool_get_product_other_info(struct command_context *ctx);
recovery_cmd_t *tool_get_full_independent_cmd_list(recovery_cmd_t *list, unsigned int *size);
recovery_cmd_t *tool_get_full_dependent_cmd_list(recovery_cmd_t *list, unsigned int *size);
#else
static inline void tool_get_product_cmds(struct cmd_entry **cmds, unsigned int *count)
{
    *count = 0;
    return;
}
static inline int tool_get_product_other_info(struct command_context *ctx)
{
    return 0;
}
static inline recovery_cmd_t *tool_get_full_independent_cmd_list(recovery_cmd_t *list, unsigned int *size)
{
    return list;
}
static inline recovery_cmd_t *tool_get_full_dependent_cmd_list(recovery_cmd_t *list, unsigned int *size)
{
    return list;
}
#endif

#endif