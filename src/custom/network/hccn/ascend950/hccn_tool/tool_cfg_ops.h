/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_CFG_OPS_H
#define TOOL_CFG_OPS_H

#include <stdbool.h>
#include "ds_data.h"

#define CFGFILE_NAME    "/etc/hccn.conf"

#ifndef CONFIG_LLT
#define STATIC static
#else
#define STATIC
#endif

#define UDHCPC_QUIT_INBUFF_LEN 4

#define INFO_PAYLOAD_LEN 1000
#define CONFLINE_LENGTH  384
#define CONFILE_LENGTH  (1024 * 1000)
#define FILE_RELEASE_RET_VALUE_NUM          4
#define CFG_INFO_PAYLOAD_LEN             1000
#define FILE_OPT_TYPE_APPEND_WRITE          0
#define FILE_OPT_TYPE_MATCH_DEL             1
#define FILE_OPT_TYPE_MATCH_REPLACES        2

#define RECOVER_RETRY_TIMES   3
#define DEV_LIST_MAX          16
#define MAX_HEALTH_CHECK_CNT  (5 * 60)
#define DEV_NO_EXIST          0xFFFFFFFF

#define TC_BUFF_INDEX 1
#define TC_WATERLINE_INDEX 3
#define MAX_BOOT_STATUS_RETRY 120

typedef struct recovery_cmd {
    const char *recovery_cmd_name;
    int (*recovery_cmd_execute)(struct command_context *ctx);
} recovery_cmd_t;

int tool_read_conf(int slot_id, const char *conf_name, char *conf_value, unsigned int len);
int tool_write_conf(int slot_id, const char *conf_name, const char *conf_value);
int tool_del_conf(int slot_id, const char *conf_name);
void tool_get_cfg_cmds(struct cmd_entry **cmds, unsigned int *count);
int tool_cfg_arp_recovery(struct command_context *ctx);
int tool_cfg_gateway_recovery(struct command_context *ctx);

bool tool_check_conf_udhcpc_enable(int slot_id);
int tool_update_conf(const char *cfg, int op_type, char match_list[][CONFLINE_LENGTH], int list_cnt);

#ifdef ENABLE_BUILD_PRODUCT
int tool_cfg_cmdline_recovery(struct command_context *ctx, const char *cmd_prefix,
    int (*cmdline_recovery)(struct command_context *, const char *));
#endif
#endif // TOOL_CFG_OPS_H
