/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_UBASE_OPS_H
#define TOOL_UBASE_OPS_H

#include "ubase_cmd_data.h"
#include "tool_param.h"

void tool_get_ubase_cmds(struct cmd_entry **cmds, unsigned int *count);
int tool_tc_cfg_get_size(char *str_tc_buf, struct tc_cfg_info *tc_cfg);
int tool_tc_cfg_get_waterline(char *str_waterline, struct tc_cfg_info *tc_cfg);
int parse_qos_cfg(struct qos_map_info *qos_cfg, int qos_cnt, char *string);
int tool_set_qos_dscp_exec(struct command_context *ctx);

#endif // TOOL_UBASE_OPS_H