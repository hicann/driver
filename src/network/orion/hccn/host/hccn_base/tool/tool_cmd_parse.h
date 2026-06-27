/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_CMD_PARSE_H
#define TOOL_CMD_PARSE_H

#include "hccn_err.h"
#include "ds_data.h"
#include "tool_param.h"
#include "tool_comm.h"

#define ENSURE_PARAM_UNIQUE(flags, flag, param) \
    do { \
        if (flags & flag) { \
            TOOL_PRINT_ERR("Option %s duplicated.", param); \
            return TOOL_PUBLIC_ARGS_REPEAT_ERR; \
        } \
        flags |= flag; \
    } while (0)

int parse_args(int argc, char **argv, struct command_context *ctx);
void dump_prompt_log(int argc, char **argv, struct command_context *ctx);
int execute(struct command_context *ctx);
int get_other_id_from_logic_id(struct command_context *ctx);
#ifdef ENABLE_BUILD_PRODUCT
void hccn_record_log(int argc, char **argv, struct command_context *ctx);
#endif

#endif // TOOL_CMD_PARSE_H
