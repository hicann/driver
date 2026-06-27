/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/prctl.h>
#include <stdbool.h>
#include "cmd.h"
#include "log.h"
#include "hccn_comm.h"

#ifdef CONFIG_LLT
int llt_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    int ret;
    unsigned int err_family;
    struct tool_param param = {0};
    ret = hccn_get_usr_name();
    if (ret) {
        roce_err("HCCN get user name fail. (ret=%d)", ret);
        return ret;
    }

    ret = hccn_get_usr_ip();
    if (ret) {
        roce_err("hccn_get_usr_ip fail! ret[%d]", ret);
        return ret;
    }
    ret = parse_cmd(argc, argv, &param);
    err_family = (unsigned int)ret & 0xF000;
    if (ret != UDA_EXE_SUCCESS) {
        switch (err_family) {
            case UDA_MAJOR_CMD_ERR:
                uda_handle_major_err(ret);
                break;
            case UDA_PARAM_ERR:
                uda_handle_param_err(ret, &param);
                break;
            case UDA_TOOL_ERR:
                uda_handle_tool_sys_err(ret, &param);
                break;
            case UDA_DSMI_ERR:
                uda_handle_dsmi_err(ret);
                break;
            case UDA_EXE_FAILED:
                uda_handle_exe_err(ret);
                break;
            default:
                TOOL_PRINT_ERR("Cmd execute failed!");
        }
        record_result_fail_to_log(argc, argv, ret);
    } else {
        record_result_success_to_log(param.get_cmd_flag, argc, argv);
    }
    return ret;
}


