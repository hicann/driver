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
#include <stdbool.h>
#include <stddef.h>
#ifndef _WIN32
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_log.h"
#include "dcmi_environment_judge.h"
#include "npu_common.h"
#include "npu_error_code.h"

#define NPU_DOCKERENV_FILE    "/.dockerenv"

int npu_is_in_docker_by_cgroup_file()
{
    FILE *fp = NULL;
    char msg_info[NPU_CFG_LINE_MAX_LEN] = {0};
    char *find_flag = NULL;
    int is_in_docker = FALSE;

    fp = fopen("/proc/self/cgroup", "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "npu_is_in_docker call open failed.");
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    while (!feof(fp)) {
        if (fgets(&msg_info[0], sizeof(msg_info), fp) == NULL) {
            break;
        }
        dcmi_strlwr(msg_info, strlen(msg_info));

        find_flag = strstr(&msg_info[0], "docker");
        if (find_flag != NULL) {
            is_in_docker = TRUE;
            break;
        }
    }

    (void)fclose(fp);
    return is_in_docker;
}

int npu_is_in_docker_by_dockerenv_file()
{
    int is_in_docker = FALSE;
    if (access(NPU_DOCKERENV_FILE, F_OK) == 0) {
        is_in_docker = TRUE;
    }
    return is_in_docker;
}

int npu_is_in_docker_by_file()
{
    return (npu_is_in_docker_by_cgroup_file() || npu_is_in_docker_by_dockerenv_file());
}

int npu_is_in_docker_by_cmd()
{
    int ret;
    char *cmd_str[] = {"/usr/bin/systemd-detect-virt", "-c", NULL};

    ret = npu_safe_exec_syscmd_without_output(cmd_str);
    if (ret == 0) {
        return TRUE;
    }

    ret = system("/bin/mount 2>&1 | grep -Ei '\\s+/\\s+' | \
        grep -E \"isulad|docker|containers|containerd\" > /dev/null");
    if (ret == 0) {
        return TRUE;
    }

    ret = system("/usr/bin/mount 2>&1 | grep -Ei '\\s+/\\s+' | \
        grep -E \"isulad|docker|containers|containerd\" > /dev/null");
    if (ret == 0) {
        return TRUE;
    }

    return FALSE;
}

int check_valid_set_operation_env(struct npu_smi_operate_info *operate_info)
{
    if (npu_get_chip_type() != NPU_CHIP_310P && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    int ret = check_vnpu_chip_name(operate_info->id, operate_info->chip_id);
    if (ret != NPU_OK) {
        printf("This device does not support setting %s.\n", operate_info->stype);
    }
    return ret;
}

int check_valid_info_operation_env(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int env_flag;

    ret = dcmi_get_environment_flag(&env_flag);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    if (npu_get_chip_type() != NPU_CHIP_310P && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (npu_get_chip_type() == NPU_CHIP_910B && (npu_is_in_virtual_machine() ||
        env_flag == ENV_PHYSICAL_PLAIN_CONTAINER || env_flag == ENV_VIRTUAL_PLAIN_CONTAINER)) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = check_vnpu_chip_name(operate_info->id, operate_info->chip_id);
    if (ret != NPU_OK) {
        printf("This device does not support querying %s.\n", operate_info->stype);
    }
    return ret;
}