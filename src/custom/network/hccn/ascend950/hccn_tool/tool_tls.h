/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_TLS_H
#define TOOL_TLS_H

#include "tool_param.h"
#include "tls.h"

#define TOOL_TIME_LEN 32

void tool_get_tls_cmds(struct cmd_entry **cmds, unsigned int *count);
int set_tls_flash_enable(struct command_context *ctx, struct tls_enable_info *enable_info);
#endif // TOOL_TLS_H
