/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_CMD_ERR_H
#define TOOL_CMD_ERR_H

#include "ds_data.h"

enum {
    HELP_LEVEL_NONE = 0,
    HELP_LEVEL_GLOBAL,
    HELP_LEVEL_MODE,
    HELP_LEVEL_CMD,
};

enum {
    PRINT_LEVEL_INFO = 0,
    PRINT_LEVEL_ERR,
};

struct tool_err_info {
    int err_code;
    int err_level;
    int help_level;
    const char *err_str;
};

void tool_print_npu_info(unsigned int npu_info);
void tool_print_dev_info(unsigned int dev_info);
void tool_handle_cmd_err(int argc, char **argv, struct command_context *ctx, int ret);
void tool_get_help_cmds(struct cmd_entry **cmds, unsigned int *count);
void tool_exe_help(struct command_context *ctx);
int tool_double_check(const char *info);
#endif // TOOL_CMD_ERR_H
