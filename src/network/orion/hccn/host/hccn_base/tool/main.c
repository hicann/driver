/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "securec.h"
#include "pwd.h"
#include "hccn_err.h"
#include "hccn_log.h"
#include "tool_comm.h"
#include "tool_cmd_err.h"
#include "tool_cmd_parse.h"

#ifdef CONFIG_LLT
int llt_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    struct command_context ctx = {0};
    int ret = 0;

    ret = hccn_get_usr_name(&ctx);
    if (ret != 0) {
        hccn_err("hccn_get_usr_name failed! ret[%d]", ret);
        return ret;
    }

    ret = hccn_get_usr_ip(&ctx);
    if (ret != 0) {
        hccn_err("hccn_get_usr_ip failed! ret[%d]", ret);
        return ret;
    }

    ret = parse_args(argc, argv, &ctx);
#ifdef ENABLE_BUILD_PRODUCT
    hccn_record_log(argc, argv, &ctx);
#else
    dump_prompt_log(argc, argv, &ctx);
#endif
    if (ret == TOOL_EXE_HELP) {
        ret = TOOL_EXE_SUCCESS;
        goto cleanup;
    }
    if (ret != 0) {
        hccn_err("parse_args failed! ret[%d]", ret);
        goto cleanup;
    }

    ret = execute(&ctx);
    if (ret != 0) {
        hccn_err("execute failed! ret[%d]", ret);
        goto cleanup;
    }

cleanup:
    tool_handle_cmd_err(argc, argv, &ctx, ret);
    if(ctx.cmd_args != NULL) {
        if (ctx.match_cmd->free_args != NULL) {
            ctx.match_cmd->free_args(ctx.match_cmd, ctx.cmd_args);
        } else {
            free(ctx.cmd_args);
        }
        ctx.cmd_args = NULL;
    }
    return ret;
}
