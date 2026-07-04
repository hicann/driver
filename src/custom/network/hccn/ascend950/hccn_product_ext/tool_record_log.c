/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "comm_channel.h"
#include "tool_log.h"

static struct check_element check_list[] = {
    { "-ub_ping", "-src_eid"},
    { "-ub_ping", "-dst_eid"},
};
 
static bool check_cmd_is_in_black_list(int idx, char **argv)
{
    int i;
    struct check_element *ele = NULL;

    for (i = 0; i < sizeof(check_list) / sizeof(struct check_element); ++i) {
        ele = &check_list[i];
        if (strncmp(argv[CMD_OPS_IDX], ele->cmd, strlen(ele->cmd) + 1)) {
            continue;
        }

        if (!strncmp(argv[idx - 1], ele->config_para, strlen(ele->config_para) + 1)) {
            return true;
        }
    }
    return false;
}

void hccn_record_log(int argc, char **argv, struct command_context *ctx)
{
    int i;

    LOG_PROMPT(ctx, "input parameters: argc[%d]", argc);
    for (i = 0; i < argc; i++) {
        if (i > CMD_OPS_IDX && check_cmd_is_in_black_list(i, argv)) {
            LOG_PROMPT(ctx, "parse [%d]th argv[%s]", i, DEFAULT_FILL_CONTENT);
        } else {
            LOG_PROMPT(ctx, "parse [%d]th argv[%s]", i, argv[i]);
        }
    }
}
