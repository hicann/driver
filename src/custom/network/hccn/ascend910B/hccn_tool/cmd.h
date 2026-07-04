/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef CMD_H
#define CMD_H

#include <stdbool.h>
#include "ossl_user_linux.h"

#define NO_PARAM 1
#define MAX_PARAM 64
#define CMD_PHY_ID_POS  2
#define MAX_ARGV_LEN 900

#define MAX_CMD_LIST 128
#define MAX_OPTION_LEN 50
#define MAX_PHY_ID_LEN 2
#define HCCN_TOOL_MAIN_CMD_POS 3
#define CMD_TYPE_MAX_CHECK_PARAMS 5

typedef struct {
    int length;                                     // 待校验参数个数
    const char *params[CMD_TYPE_MAX_CHECK_PARAMS];  // 待校验参数字符串数组
} cmd_type_config;

struct cmd_info {
    char attr[MAX_OPTION_LEN];
    char attr_value[MAX_OPTION_LEN];
    char option[MAX_OPTION_LEN];
    int (*cmd_execute)(int argc, char **argv, struct tool_param *param);
    const char  *help;
    const char  *option_help;
    char *option_mode;
};

struct option_mode_info {
    char attr[MAX_OPTION_LEN];
    hccn_cmd_mode mode;
    int cmd_major_offset;
};

extern void uda_formate_err_print(void);
extern void uda_compile_time_show();
extern int parse_cmd(int argc, char **argv, struct tool_param *param);
extern void uda_handle_major_err(int exe_ret);
extern void uda_handle_param_err(int exe_ret, struct tool_param *param);
extern void uda_handle_dsmi_err(int exe_ret);
extern void uda_handle_tool_sys_err(int exe_ret, struct tool_param *param);
extern void uda_handle_exe_err(int exe_ret);
int insert_ext_cmd(void);
int insert_cmd_list(struct cmd_info *cmd, int cmd_num);
void record_result_fail_to_log(int argc, char *argv[], int ret);
void record_result_success_to_log(bool get_cmd_flag, int argc, char *argv[]);
#endif

