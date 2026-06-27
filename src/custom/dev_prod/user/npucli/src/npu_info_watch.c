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
#include <stddef.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <time.h>

#include "securec.h"
#include "dcmi_log.h"
#include "npu_common.h"
#include "npu_info_print.h"

struct get_usages_info_table {
    int type;
    int (*func)(int card_id, int chip_index, unsigned int *usage);
    unsigned int *usage;
};

static int init_npu_watch_card_info(struct npu_watch_info *npu_watch_info, const int *card_id_list,
    int card_id_list_len)
{
    int card_index;
    int ret;

    for (card_index = 0; (card_index < npu_watch_info->card_count) && (card_index < card_id_list_len); card_index++) {
        npu_watch_info->card_info[card_index].card_id = card_id_list[card_index];
        ret = npu_get_card_device_id(npu_watch_info->card_info[card_index].card_id,
            &npu_watch_info->card_info[card_index].chip_count,
            &npu_watch_info->card_info[card_index].mcu_id,
            &npu_watch_info->card_info[card_index].cpu_id);
        if (ret != NPU_OK) {
            printf("npu_get_card_device_id failed. err is %d\n", ret);
            return NPU_ERR_CODE_INNER_ERR;
        }
    }
    return NPU_OK;
}

static int npu_get_usages_info(struct npu_smi_operate_info *operate_info, int card_id, int chip_index,
    struct npu_chip_usages_info *usages_info)
{
    int type, ret;
    size_t table_size, i;
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool not_support_chip_type = (chip_type != NPU_CHIP_910B && chip_type != NPU_CHIP_910_93
                            && chip_type != NPU_CHIP_950);

    // 定义函数指针变量，用于动态选择MEMORY_TYPE和MEMORY_BANDWIDTH_TYPE的函数
    int (*memory_func)(int card_id, int chip_index, unsigned int *usage) = npu_get_hbm_usage;
    int (*memory_bandwidth_func)(int card_id, int chip_index, unsigned int *usage) = npu_get_hbm_bandwidth_usage;
    unsigned int *memory_usages = &usages_info->hbm_usage;
    unsigned int *memory_bandwidth_usages = &usages_info->hbm_bandwidth_usage;

    if (not_support_chip_type) {
        memory_func = npu_get_ddr_usage;
        memory_bandwidth_func = npu_get_ddr_bandwidth_usage;
        memory_usages = &usages_info->memory_usage;
        memory_bandwidth_usages = &usages_info->memory_bandwidth_usage;
        usages_info->npu_utilization_usage = NPU_DEFAULT_VALUE;
    }

    struct get_usages_info_table usages_info_table[] = {
        {AI_CORE_TYPE, npu_get_ai_core_usage, &usages_info->aicore_usage},
        {AI_CPU_TYPE, npu_get_ai_cpu_usage, &usages_info->aicpu_usage},
        {CTRL_CPU_TYPE, npu_get_ctrl_cpu_usage, &usages_info->ctrlcpu_usage},
        {MEMORY_TYPE, memory_func, memory_usages},
        {MEMORY_BANDWIDTH_TYPE, memory_bandwidth_func, memory_bandwidth_usages},
        {NPU_UTILIZATION_TYPE, npu_get_npu_utilization_usage, &usages_info->npu_utilization_usage},
        {AI_CUBE_TYPE, npu_get_ai_cube_usage, &usages_info->aicube_usage},
    };

    table_size = sizeof(usages_info_table) / sizeof(usages_info_table[0]);

    for (i = 0; i < table_size; i++) {
        type = usages_info_table[i].type;
        if (operate_info->watch_stype[type] != NPU_DEFAULT_VALUE) {
            ret = usages_info_table[i].func(card_id, chip_index, usages_info_table[i].usage);
            if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
                return ret;
            }
        }
    }

    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
        chip_type == NPU_CHIP_950) {
        ret = npu_get_util_info_simultaneously(card_id, chip_index, usages_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "npu_get_util_info_simultaneously failed. err is %d", ret);
            return ret;
        }
    }

    return NPU_OK;
}

STATIC int npu_get_watch_chip_info(struct npu_smi_operate_info *operate_info, int card_id,
    int chip_index, struct npu_chip_watch_info *chip_watch_info)
{
    int ret;
    if (operate_info->watch_stype[POWER_TYPE] != NPU_DEFAULT_VALUE) {
        ret = npu_get_device_power_info(card_id, chip_index, &chip_watch_info->power);
        if (ret != NPU_OK && ret != NPU_ERR_CODE_NOT_SUPPORT) {
            return ret;
        }
    }

    if (operate_info->watch_stype[TEMP_TYPE] != NPU_DEFAULT_VALUE) {
        ret = npu_get_device_temperature(card_id, chip_index, &chip_watch_info->temp);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = npu_get_usages_info(operate_info, card_id, chip_index, &chip_watch_info->usages_info);
    if (ret != NPU_OK) {
        return ret;
    }

    return ret;
}

static int check_input_card_id_and_chip_id_is_support(
    struct npu_smi_operate_info *operate_info, struct npu_watch_info *npu_watch_info)
{
    int ret;
    int device_count;
    int mcu_id;
    int cpu_id;

    if (operate_info->id != NPU_DEFAULT_VALUE) {
        ret = npu_check_card_id(operate_info->id);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    if (operate_info->chip_id != NPU_DEFAULT_VALUE) {
        ret = npu_check_chip_id(operate_info->id, operate_info->chip_id);
        if (ret != NPU_OK) {
            return ret;
        }

        ret = npu_get_card_device_id(operate_info->id, &device_count, &mcu_id, &cpu_id);
        if (ret != NPU_OK) {
            return ret;
        }

        if ((operate_info->chip_id == mcu_id) || (operate_info->chip_id == cpu_id)) {
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
    }
    return NPU_OK;
}

static int show_watch_card_info(struct npu_smi_operate_info *operate_info, struct npu_watch_card_info *card_info)
{
    int ret;
    int chip_index;
    struct npu_chip_watch_info chip_watch_info = {0};

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        if (operate_info->chip_id != -1 && operate_info->chip_id != chip_index) {
            continue;
        }
        ret = npu_get_watch_chip_info(operate_info, card_info->card_id, chip_index, &chip_watch_info);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            return ret;
        }

        print_chip_watch_info(card_info->card_id, chip_index, &chip_watch_info, operate_info->watch_stype);
    }

    return NPU_OK;
}

static int show_watch_info(struct npu_smi_operate_info *operate_info, struct npu_watch_info *npu_watch_info)
{
    int ret;
    int card_index;

    while (1) {
        for (card_index = 0; card_index < npu_watch_info->card_count; card_index++) {
            if (operate_info->id != -1 && operate_info->id != npu_watch_info->card_info[card_index].card_id) {
                continue;
            }
            ret = show_watch_card_info(operate_info, &npu_watch_info->card_info[card_index]);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "show_watch_card_info failed. err is %d", ret);
                return ret;
            }
            (void)fflush(stdout); // 重定向输出到文本文件时，数据缓存在缓冲区，缓冲区满才会刷新到文件中，kill后数据无法同步
        }
        if (operate_info->watch_delay <= 0) {
            sleep(1);
        } else {
            sleep(operate_info->watch_delay);
        }
    }
    return NPU_OK;
}

static int query_watch_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int card_id_list[MAX_CARD_NUM] = {0};
    struct npu_watch_info *npu_watch_info = NULL;

    // 200SOC 容器中计算组件不支持查询内存占用率，后续计算组件功能OK后，需要放开
    if (npu_board_type_is_soc() && npu_is_in_docker()) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    npu_watch_info = (struct npu_watch_info *)malloc(sizeof(struct npu_watch_info));
    if (npu_watch_info == NULL) {
        printf("Failed to malloc memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(npu_watch_info, sizeof(struct npu_watch_info), 0, sizeof(struct npu_watch_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_num_list(&npu_watch_info->card_count, card_id_list, MAX_CARD_NUM);
#else
    ret = dcmiv2_get_device_list(card_id_list, &npu_watch_info->card_count, MAX_CARD_NUM);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get device list. err is %d", ret);
        free(npu_watch_info);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    ret = init_npu_watch_card_info(npu_watch_info, (const int *)&card_id_list[0], MAX_CARD_NUM);
    if (ret != NPU_OK) {
        free(npu_watch_info);
        return ret;
    }

    ret = check_input_card_id_and_chip_id_is_support(operate_info, npu_watch_info);
    if (ret != NPU_OK) {
        free(npu_watch_info);
        return ret;
    }

    print_npu_watch_header(operate_info->watch_stype,
        sizeof(operate_info->watch_stype) / sizeof(operate_info->watch_stype[0]));

    ret = show_watch_info(operate_info, npu_watch_info);
    if (ret != NPU_OK) {
        free(npu_watch_info);
        return ret;
    }

    free(npu_watch_info);
    return NPU_OK;
}

static int query_watch_proc_info(struct npu_smi_operate_info *operate_info)
{
    return NPU_ERR_CODE_NOT_SUPPORT;
}

static struct npu_info_cmd npu_watch_cmd[] = {
    {check_watch_chip_parm, query_watch_info, WATCH_CHIP_INFO},
    {check_watch_proc_parm, query_watch_proc_info, WATCH_CHIP_PROC},
    {NULL},
};


int npu_info_proc_watch_cmd(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    struct npu_info_cmd *cmd = NULL;
    char *watch_type_str[WATCH_MAX] = {"null", "watch", "proc"};

    /* 处理小站无AI模块场景 */
    if (npu_check_is_has_d_chip() == FALSE) {
        printf("This device does not support querying %s info.\n", watch_type_str[operate_info->is_watch]);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    for (cmd = npu_watch_cmd; cmd->check_parm != NULL; cmd++) {
        if (cmd->type == operate_info->is_watch) {
            ret = cmd->check_parm(operate_info);
            if (ret != NPU_OK) {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            ret = cmd->cmd_proc(operate_info);
            if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
                printf("This device does not support querying %s info.\n", watch_type_str[cmd->type]);
                return ret;
            }

            if (ret == NPU_ERR_CODE_NO_MATRIX_PROC) {
                printf("No matrix process exists, please check.\n");
                return ret;
            }

            if (ret != NPU_OK) {
                printf("Failed to query \"%s\" info.\n", watch_type_str[cmd->type]);
                return ret;
            }
        }
    }
    return ret;
}


static void npu_info_watch_proc_help(void)
{
    printf("Usage: %s info proc [Options...]\n", TOOL_NAME);
    printf("\nOptions:\n");
#ifndef NPU_SMI_V2
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
#else
    printf("       -i %%d          NPU ID\n");
#endif
    printf("       -d %%d          Collection delay in seconds [1~100, default is 1 second]\n");
}

static void npu_info_watch_chip_help(void)
{
    printf("Usage: %s info watch [Options...]\n", TOOL_NAME);
    printf("\nOptions:\n");
#ifndef NPU_SMI_V2
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
#else
    printf("       -i %%d          NPU ID\n");
#endif
    printf("       -d %%d          Collection delay in seconds [1~100, default is 1 second]\n");
    printf("       -s             One or more metrics [eg. info watch -s ptaicmb]\n");
    printf("                      Can be any of the following:\n");
    printf("                          p - Power Usage\n");
    printf("                          t - Temperature\n");
    printf("                          a - AI Core Usage\n");
    printf("                          i - AI Cpu Usage\n");
    printf("                          c - Control Cpu Usage\n");
    printf("                          m - Memory Usage\n");
    printf("                          b - Memory Bandwidth Usage\n");
    printf("                          n - NPU Utilization\n");
    printf("                          u - AI Cube Usage\n");
}

void npu_info_watch_help(struct npu_smi_operate_info *operate_info)
{
    void (*watch_help[WATCH_MAX - 1])(void) = {npu_info_watch_chip_help, npu_info_watch_proc_help};
    watch_help[operate_info->is_watch - 1]();
}

