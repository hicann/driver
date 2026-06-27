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

#include "dcmi_interface_api.h"
#include "npu_init.h"
#include "npu_common.h"
#include "npu_info.h"
#include "npu_set.h"
#include "npu_clear.h"
#include "npu_upgrade.h"
#include "npu_parameter_parse.h"
#include "npu_smi.h"

struct npu_cmd npu_cmd_list[] = {
    { npu_help_main,     "-h",      "This command's help information" },
    { npu_help_main,     "--help",  "This command's help information" },
    { npu_version_main,  "-v",      "Show npu-smi version information" },
    { npu_info_main,     "info",    "Show hardware details" },
    { npu_set_main,      "set",     "Modify device configuration properties" },
    { npu_clear_main,    "clear",   "Clear device information" },
#ifdef NPU_SMI_V2
    { npu_upgrade_main,  "upgrade", "Upgrade firmware" },
#else
    { npu_upgrade_main,  "upgrade", "Upgrade MCU firmware" },
#endif
    { NULL },
};

int npu_help_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    struct npu_cmd *cmd = NULL;

    (void)operate_info;
    (void)argc;
    (void)argv;

    printf("Usage: %s <Command|-h|-v> [Options...]\n\n", TOOL_NAME);
    printf("%s Command:\n", TOOL_NAME);

    for (cmd = npu_cmd_list; cmd->func != NULL; cmd++) {
        if (cmd->desc == NULL) {
            continue;
        }

        printf("\t%-12s  %s\n", cmd->name, cmd->desc);
    }

    return NPU_OK;
}

int npu_version_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    (void)operate_info;
    (void)argc;
    (void)argv;

    printf("%s version: %s\n", TOOL_NAME, TOOL_VERSION);
    return 0;
}

static void init_npu_operate_info_default(struct npu_smi_operate_info *operate_info)
{
    operate_info->id = NPU_INVALID_VALUE;
    operate_info->chip_id = NPU_INVALID_VALUE;
    operate_info->type = NPU_INVALID_VALUE;
    operate_info->enable_value = NPU_INVALID_VALUE;
    operate_info->name = NULL;
    operate_info->desc = NULL;
    operate_info->file_path = NULL;
    operate_info->phy_id = NPU_INVALID_VALUE;
    operate_info->vnpu_id = NPU_INVALID_VALUE;
    operate_info->vfg_id = NPU_INVALID_VALUE;
    operate_info->lane_id = NPU_LANE_ID;
    operate_info->profiling_time = NPU_INVALID_VALUE;
    operate_info->is_total = FALSE;
    operate_info->is_watch = WATCH_INIT;
    operate_info->is_all = FALSE;
    operate_info->is_erase = FALSE;
    operate_info->is_reset = FALSE;
    operate_info->is_upgrade = FALSE;
    operate_info->is_query = FALSE;
    operate_info->is_active = FALSE;
    operate_info->is_common = FALSE;
    operate_info->is_version = FALSE;
    operate_info->is_mapping = FALSE;
    operate_info->is_hccs_topo = FALSE;
}

static bool validate_arguments(int argc)
{
    if (argc < LEAST_PARAMETER_NUM) {
        npu_help_main(NULL, argc, NULL);
        return false;
    }
    return true;
}

static void initialize_environment(struct npu_smi_operate_info *info)
{
    init_npu_operate_info_default(info);
    init_para_support_map();
}

static const struct npu_cmd *find_command(const char *input_cmd, const struct npu_cmd *cmd_list)
{
    for (const struct npu_cmd *cmd = cmd_list; cmd->func != NULL; cmd++) {
        if (cmd->name == NULL) {
            continue;
        }
        // 直接比较整个字符串（无需计算长度）
        if (strcmp(input_cmd, cmd->name) == 0) {  // 使用 strcmp 替代 strncmp
            return cmd;
        }
    }
    return NULL;
}

static void handle_command_not_found(void)
{
    printf("Command or option is not found.\n");
    npu_help_main(NULL, 0, NULL);
}

static int handle_dcmi_initialization(void)
{
    int ret;
#ifndef NPU_SMI_V2
    ret = dcmi_init();
#else
    ret = dcmiv2_init();
#endif
    if (ret == DCMI_OK) {
        return ret;
    }
    if (ret != DCMI_ERR_CODE_RESOURCE_OCCUPIED) {
        printf("dcmi module initialize failed. ret is %d\n", ret);
    } else {
        printf("dcmi model initialized failed, because the device is used. ret is %d\n", ret);
    }
    return ret;
}

static int handle_board_type_initialization(void)
{
    int ret = npu_get_board_type_by_config();
    if (ret == NPU_OK) {
        return ret;
    }
    if ((ret = npu_get_board_type_by_board_id()) != NPU_OK) {
        printf("npu get board type failed. ret is %d\n", ret);
    }
    return ret;
}

static int execute_command(const struct npu_cmd *cmd, struct npu_smi_operate_info *info, int argc, char **argv)
{
    info->name = cmd->name;
    info->desc = cmd->desc;
    const int ret = cmd->func(info, argc - 1, &argv[1]);
    if (ret >= DCMI_ERR_CODE_NOT_SUPPORT && ret < DCMI_ERROR_CODE_BASE) {
        printf("Failed to execute npu-smi %s. ret is %d.\n", info->name, ret);
    }
    return ret;
}

int npu_main(int argc, char **argv)
{
    struct npu_smi_operate_info npu_operate_info = { 0 };
    const struct npu_cmd *found_cmd = NULL;
    int ret;
    if (!validate_arguments(argc)) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    initialize_environment(&npu_operate_info);
    found_cmd = find_command(argv[1], npu_cmd_list);
    if (found_cmd == NULL || found_cmd->func == NULL) {
        handle_command_not_found();
        return NPU_ERR_CODE_INNER_ERR;
    }
    ret = handle_dcmi_initialization();
    if (ret != NPU_OK) {
        return ret;
    }
    ret = handle_board_type_initialization();
    if (ret != NPU_OK) {
        return ret;
    }
    (void)npu_init_total_ascend_chip_count();
    return execute_command(found_cmd, &npu_operate_info, argc, argv);
}

int main(int argc, char **argv)
{
    int rc;
    rc = npu_main(argc, argv);
    exit(rc);
}