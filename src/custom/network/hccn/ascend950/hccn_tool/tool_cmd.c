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
#include "tool_shell_ops.h"
#include "tool_tcpip_ops.h"
#include "tool_tls.h"
#include "tool_ubase_ops.h"
#include "tool_cfg_ops.h"
#include "tool_product.h"
#include "tool_cmd.h"

STATIC tool_get_cmds_func g_main_cmds_func[] = {
    tool_get_shell_cmds,
    tool_get_tcpip_cmds,
    tool_get_tls_cmds,
    tool_get_ubase_cmds,
    tool_get_cfg_cmds,
    tool_get_product_cmds,
};

void tool_get_main_cmds_funcs(tool_get_cmds_func **cmds_func, unsigned int *count)
{
    *cmds_func = g_main_cmds_func;
    *count = ARRAY_SIZE_COMPUTE(g_main_cmds_func);
}
