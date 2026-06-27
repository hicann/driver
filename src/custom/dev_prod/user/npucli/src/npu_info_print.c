/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef ORIENT_CH
#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_log.h"
#include "npu_common.h"
#include "npu_info.h"
#include "npu_smi.h"
#include "dcmi_interface_api.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_npu_link_intf.h"
#include "dcmi_environment_judge.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_info_get.h"
#include "npu_card_info.h"
#include "npu_chip_info.h"
#include "npu_info_print.h"

#define     PERCENTAGE           100
#define     HCCS_LANE_SPEED      56
#define     SINGLE_PACKETS_BYTES 20
#define     G_ARR_DIM            2
#define     G_ARR1_ROW           16
#define     G_ARR2_ROW           8
#define     G_ARR_COL            8
#define     ONE_GHZ              1000000000.0
#define     CONVERSION_MS        1000

struct chip_watch_info_print_hook {
    int type;
    void (*func)(struct npu_chip_watch_info *chip_info);
};

void print_npu_watch_header(const int *stype, const int stype_len)
{
    int i;

    const char *type_header[] = {
        "Pwr(W)",      "Temp(C)",   "AI Core(%)",   "AI Cpu(%)",
        "Ctrl Cpu(%)", "Memory(%)", "Memory BW(%)", "NPU Util(%)", "AI Cube(%)"
    };
#ifndef NPU_SMI_V2
    printf("%-12s%-12s", "NpuID(Idx)", "ChipId(Idx)");
#else
    printf("%-12s", "NpuID(Idx)");
#endif
    for (i = 0; i <= MEMORY_BANDWIDTH_TYPE; i++) {
        if (stype[i] != NPU_DEFAULT_VALUE) {
            printf("%-12s", type_header[i]);
        }
    }
    // after Memory BW(%), use the cycle to print
    for (i = MEMORY_BANDWIDTH_TYPE + 1; i < WATCH_STYPE_BOTTOM; i++) {
        if (stype[i] != NPU_DEFAULT_VALUE) {
            printf(" %-12s", type_header[i]);
        }
    }

    printf("\n");
    (void)stype_len;
}

void print_chip_watch_pwr_info(struct npu_chip_watch_info *chip_info)
{
    if (npu_get_chip_type() == NPU_CHIP_910_93 && chip_info->power == NPU_DEFAULT_VALUE) {
        printf("%-12s", "-");
    } else if (npu_get_chip_type() == NPU_CHIP_310P || chip_info->power == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12.1f", chip_info->power * NPU_DECIMAL_TRANS);
    }
    return;
}

void print_chip_watch_temp_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->temp == NPU_DEFAULT_TEMP_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12d", chip_info->temp);
    }
    return;
}

void print_chip_watch_ai_core_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.aicore_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.aicore_usage);
    }
}

void print_chip_watch_ai_cube_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.aicube_usage == NPU_DEFAULT_VALUE) {
        printf(" %-12s", "NA");
    } else {
        printf(" %-12u", chip_info->usages_info.aicube_usage);
    }
}

void print_chip_watch_ai_cpu_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.aicpu_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.aicpu_usage);
    }
}

void print_chip_watch_ctrl_cpu_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.ctrlcpu_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.ctrlcpu_usage);
    }
}

void print_chip_watch_memory_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.memory_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.memory_usage);
    }
}

void print_chip_watch_hbm_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.hbm_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.hbm_usage);
    }
}

void print_chip_watch_memory_bandwidth_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.memory_bandwidth_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.memory_bandwidth_usage);
    }
}

void print_chip_watch_hbm_bandwidth_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.hbm_bandwidth_usage == NPU_DEFAULT_VALUE) {
        printf("%-12s", "NA");
    } else {
        printf("%-12u", chip_info->usages_info.hbm_bandwidth_usage);
    }
}

void print_chip_npu_utilization_info(struct npu_chip_watch_info *chip_info)
{
    if (chip_info->usages_info.npu_utilization_usage == NPU_DEFAULT_VALUE) {
        printf(" %-12s", "NA");
    } else {
        printf(" %-12u", chip_info->usages_info.npu_utilization_usage);
    }
}

void print_chip_watch_info(int card_id, int device_id, struct npu_chip_watch_info *chip_info, const int *stype)
{
    int type;
    size_t table_size, i;
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool not_support_chip_type = (chip_type != NPU_CHIP_910B && chip_type != NPU_CHIP_910_93
                            && chip_type != NPU_CHIP_950);

    // 定义函数指针变量，用于动态选择MEMORY_TYPE和MEMORY_BANDWIDTH_TYPE的函数
    void (*memory_func)(struct npu_chip_watch_info *) = print_chip_watch_hbm_info;
    void (*memory_bandwidth_func)(struct npu_chip_watch_info *) = print_chip_watch_hbm_bandwidth_info;

    if (not_support_chip_type) {
        memory_func = print_chip_watch_memory_info;
        memory_bandwidth_func = print_chip_watch_memory_bandwidth_info;
        chip_info->usages_info.npu_utilization_usage = NPU_DEFAULT_VALUE;
    }

    struct chip_watch_info_print_hook info_print[] = {
        {POWER_TYPE, print_chip_watch_pwr_info},
        {TEMP_TYPE, print_chip_watch_temp_info},
        {AI_CORE_TYPE, print_chip_watch_ai_core_info},
        {AI_CPU_TYPE, print_chip_watch_ai_cpu_info},
        {CTRL_CPU_TYPE, print_chip_watch_ctrl_cpu_info},
        {MEMORY_TYPE, memory_func},
        {MEMORY_BANDWIDTH_TYPE, memory_bandwidth_func},
        {NPU_UTILIZATION_TYPE, print_chip_npu_utilization_info},
        {AI_CUBE_TYPE, print_chip_watch_ai_cube_info},
    };

    if (chip_type == NPU_CHIP_910_93 && device_id == 1) {
        chip_info->power = NPU_DEFAULT_VALUE;
    }
#ifndef NPU_SMI_V2
    printf("%-12d%-12d", card_id, device_id);
#else
    printf("%-12d", card_id);
#endif
    table_size = sizeof(info_print) / sizeof(info_print[0]);

    for (i = 0; i < table_size; i++) {
        type = info_print[i].type;
        if (stype[type] == NPU_DEFAULT_VALUE) {
            continue;
        }
        info_print[type].func(chip_info);
    }

    printf("\n");
    return;
}

void print_card_total_info_first(struct npu_card_total_info *card_info, int chip_index)
{
    int ret;
    char health_info[NPU_MAX_LENTH] = {0};
    ret = npu_common_get_health_state_str(card_info->chip_health[chip_index], &health_info[0], sizeof(health_info));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "call npu_common_get_health_state_str failed. err is %d.", ret);
        return;
    }
#ifdef _WIN32
    printf("| %-7d %-22s| %-15s | %-12.1f %-17d %-6s/ %-13s |\n", card_info->card_id,
        card_info->chip_info[chip_index].chip_name, &health_info[0],
        card_info->chip_common_info[chip_index].power * NPU_DECIMAL_TRANS,
        card_info->chip_common_info[chip_index].temp, "NA", "NA");
#else
    if (npu_get_chip_type() == NPU_CHIP_310P) {
        printf("| %-7d %-22s| %-15s | %-12s %-17d %-6lu/ %-13lu |\n", card_info->card_id,
            card_info->chip_info[chip_index].chip_name, &health_info[0], "NA",
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
            card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
    } else {
        printf("| %-7d %-22s| %-15s | %-12.1f %-17d %-6lu/ %-13lu |\n", card_info->card_id,
            card_info->chip_info[chip_index].chip_name, &health_info[0],
            card_info->chip_common_info[chip_index].power * NPU_DECIMAL_TRANS,
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
            card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
    }
#endif
    return;
}

void print_card_total_info_second(struct npu_card_total_info *card_info, int chip_index)
{
    int ret, memory_used, device_logic_id;
    unsigned long long memory_total;

    memory_total = card_info->chip_memory_info[chip_index].memory_size;
    memory_used = (int)(memory_total - card_info->chip_memory_info[chip_index].memory_available);
    ret = dcmi_get_device_logic_id(&device_logic_id, card_info->card_id, chip_index);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_logic_id failed. err is %d.", ret);
        return;
    }

    if ((card_info->chip_common_info[chip_index].npu_usage & (0x1 << DCMI_VF_FLAG_BIT)) != 0) {
        card_info->chip_common_info[chip_index].npu_usage = 0; // 算力分组场景获取的aicore利用率为0，实际无意义。
    }

    if (card_info->is_has_pcie == TRUE) {
        printf("| %-7d %-22d| %04X:%02X:%02X.%-4X | %-12u %-5d/ %-32llu |\n", chip_index, device_logic_id,
            card_info->device_pcie_info[chip_index].domain,
            card_info->device_pcie_info[chip_index].bdf_busid, card_info->device_pcie_info[chip_index].bdf_deviceid,
            card_info->device_pcie_info[chip_index].bdf_funcid, card_info->chip_common_info[chip_index].npu_usage,
            memory_used, memory_total);
    } else {
        if (card_info->chip_memory_info[chip_index].utiliza == NPU_DEFAULT_VALUE) {
            printf("| %-7d %-22d| %-15s | %-12u %-3s/ %-34llu |\n", chip_index, device_logic_id, "NA",
                card_info->chip_common_info[chip_index].npu_usage, "NA", memory_total);
        } else {
            printf("| %-7d %-22d| %-15s | %-12u %-5d/ %-32llu |\n", chip_index, device_logic_id, "NA",
                card_info->chip_common_info[chip_index].npu_usage, memory_used, memory_total);
        }
    }
    return;
}

void print_proc_total_info(struct npu_card_total_info *card_info)
{
    int proc_index, chip_index;
    int process_num = 0;

    if (card_info->card_id < 0) {
        gplog(LOG_ERR, "get card_id failed, card_id = %d", card_info->card_id);
        return;
    }

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        for (proc_index = 0; proc_index < card_info->proc_nums[chip_index]; proc_index++) {
            process_num++;
            printf("| %-7d %-22d| %-15d | %-24s | %-25lu |\n", card_info->card_id, chip_index,
                card_info->chip_proc_info[chip_index][proc_index].proc_id,
                card_info->chip_proc_name[chip_index][proc_index],
                (unsigned long)(card_info->chip_proc_info[chip_index][proc_index].proc_mem_usage /
                    BYTE_TO_KB_TRANS_VALUE / KB_TO_MB_TRANS_VALUE));
            if (proc_index == MAX_CHIP_PROCESS_NUM - 1) { // 防止进程信息刷屏
                break;
            }
        }
    }

    if (!process_num) {
        printf("| No running processes found in NPU %-7d                 "\
            "                                             |\n", card_info->card_id);
    }
    printf("+===============================+======="\
        "==========+======================================================+\n");
    return;
}

void print_card_total_info(struct npu_card_total_info *card_info)
{
    int chip_index;
    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        print_card_total_info_first(card_info, chip_index);
        print_card_total_info_second(card_info, chip_index);

        if (chip_index != card_info->chip_count - 1) {
            printf("+-------------------------------+-----------------+"\
                "------------------------------------------------------+\n");
        }
    }

    printf("+===============================+======="\
        "==========+======================================================+\n");
    return;
}

void print_total_info(struct npu_total_info *npu_total_info)
{
    int card_index;
    bool check_result = (npu_board_type_is_card() || npu_board_type_is_station() || npu_board_type_is_hilens() ||
        npu_board_type_is_server() || npu_board_type_is_model());

    printf("+------------------------------------------------------------------------"\
        "--------------------------------+\n");
#ifdef _WIN32
    printf("| %s %-40s Version: %-44s |\n", TOOL_NAME, TOOL_VERSION, TOOL_VERSION);
#else
    printf("| %s %-40s Version: %-44s |\n", TOOL_NAME, TOOL_VERSION, npu_total_info->software_version);
#endif
    printf("+-------------------------------+-----------------+-----------------------"\
        "-------------------------------+\n");
    printf("| NPU     Name                  | Health          | Power(W)     Temp(C)  "\
        "         Hugepages-Usage(page) |\n");
    printf("| Chip    Device                | Bus-Id          | AICore(%%)    Memory-Usage(MB)"\
        "                        |\n");
    printf("+===============================+=================+======================="\
        "===============================+\n");

    for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
        struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
        print_card_total_info(card_info);
    }

    if ((npu_get_chip_type() == NPU_CHIP_310 || npu_get_chip_type() == NPU_CHIP_310P) && check_result) {
        printf("+-------------------------------+-----------------+-----------------------"\
            "-------------------------------+\n");
        printf("| NPU     Chip                  | Process id      | Process name          "\
            "   | Process memory(MB)        |\n");
        printf("+===============================+=================+======================="\
            "===============================+\n");
        for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
            struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
            print_proc_total_info(card_info);
        }
    }
    return;
}

void print_chip_info(int chip_index, unsigned int phyid)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B) {
        printf("| %-26d| ", chip_index);
    } else if (chip_type == NPU_CHIP_910_93) {
        printf("| %-5d %-20u| ", chip_index, phyid);
    } else if (chip_type == NPU_CHIP_950) {
        printf("|%-8s|%-18s| ", "", "");
    }
}

void print_card_total_info_with_HBM_first(struct npu_card_total_info *card_info, int chip_index)
{
    int ret;
    char health_info[NPU_MAX_LENTH] = {0};
    enum npu_chip_type chip_type = npu_get_chip_type();

    ret = npu_common_get_health_state_str(card_info->chip_health[chip_index], &health_info[0], sizeof(health_info));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get health state failed, chip_index is %d err is %d.", chip_index, ret);
        return;
    }
    if (chip_index == 1 && chip_type == NPU_CHIP_910_93) {
        printf("| %-5d %-20s| %-13s | %-11s %-17d %-6lu/ %-13lu |\n",
            card_info->card_id,
            card_info->chip_info[chip_index].chip_name,
            &health_info[0],
            "-",
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
                card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
    } else {  // 910_93的die1不显示功耗
#ifdef NPU_SMI_V2
        printf("| %-7d| %-17s| %-13s | %-11.1f %-17d %-6lu/ %-13lu |\n",
            card_info->card_id,
            card_info->chip_info[chip_index].chip_name,
            &health_info[0],
            card_info->chip_common_info[chip_index].power * NPU_DECIMAL_TRANS,
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
                card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
#else
        printf("| %-5d %-20s| %-13s | %-11.1f %-17d %-6lu/ %-13lu |\n",
            card_info->card_id,
            card_info->chip_info[chip_index].chip_name,
            &health_info[0],
            card_info->chip_common_info[chip_index].power * NPU_DECIMAL_TRANS,
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
                card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
#endif
    }
}

void print_card_total_info_with_HBM_second(struct npu_card_total_info *card_info, int chip_index, unsigned int phyid)
{
    unsigned long long memory_total = card_info->chip_memory_info[chip_index].memory_size;
    int memory_used = (int)(memory_total - card_info->chip_memory_info[chip_index].memory_available);
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        memory_total = 0;
        memory_used = 0;
    }
    unsigned long long hbm_total = card_info->chip_hbm_info[chip_index].memory_size;
    int hbm_used = (int)card_info->chip_hbm_info[chip_index].memory_usage;

    if ((card_info->chip_common_info[chip_index].npu_usage & (0x1 << DCMI_VF_FLAG_BIT)) != 0) {
        card_info->chip_common_info[chip_index].npu_usage = 0;  // 算力分组场景获取的aicore利用率为0，实际无意义。
    }

    print_chip_info(chip_index, phyid);

    if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        printf("%-11s   | %-11u %-5d/ %-10llu %-6d/ %-13llu |\n",
            "NA", (card_info->chip_common_info[chip_index].npu_usage),
            memory_used, memory_total, hbm_used, hbm_total);
    } else {
        printf("%04X:%02X:%02X.%-2X | %-11u %-5d/ %-10llu %-6d/ %-13llu |\n",
            card_info->device_pcie_info[chip_index].domain,
            card_info->device_pcie_info[chip_index].bdf_busid,
            card_info->device_pcie_info[chip_index].bdf_deviceid,
            card_info->device_pcie_info[chip_index].bdf_funcid,
            (card_info->chip_common_info[chip_index].npu_usage),
            memory_used, memory_total, hbm_used, hbm_total);
    }
}

void print_card_total_info_with_HBM(struct npu_card_total_info *card_info)
{
#ifndef NPU_SMI_V2
    int ret;
#endif
    int chip_index;
    unsigned int phyid = -1;

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_phyid_by_cardid_and_devid(card_info->card_id, chip_index, &phyid);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Get phyid failed. card id:%d, device id:%d.", card_info->card_id, chip_index);
            return;
        }
#endif
        print_card_total_info_with_HBM_first(card_info, chip_index);
        print_card_total_info_with_HBM_second(card_info, chip_index, phyid);
        if (chip_index != card_info->chip_count - 1) {
            printf("+------------------------------------------------------"\
            "-------------------------------------------+\n");
        }
    }

    if (card_info->chip_count > 0) {
#ifdef NPU_SMI_V2
        printf("+========+==================+===============+=========================="\
        "===========================+\n");
#else
        printf("+===========================+===============+=========================="\
        "===========================+\n");
#endif
    }

    return;
}

void print_proc_total_info_with_HBM(struct npu_card_total_info *card_info)
{
    int proc_index, chip_index;
    int process_num = 0;

    if (card_info->card_id < 0) {
        gplog(LOG_ERR, "get card_id failed, card_id = %d", card_info->card_id);
        return;
    }

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        for (proc_index = 0; proc_index < card_info->proc_nums[chip_index]; proc_index++) {
            process_num++;
#ifdef NPU_SMI_V2
            printf("| %-26d | %-13d | %-24s | %-23lu |\n", card_info->card_id,
                card_info->chip_proc_info[chip_index][proc_index].proc_id,
                card_info->chip_proc_name[chip_index][proc_index],
                (unsigned long)(card_info->chip_proc_info[chip_index][proc_index].proc_mem_usage /
                    BYTE_TO_KB_TRANS_VALUE / KB_TO_MB_TRANS_VALUE));
#else
            printf("| %-7d %-18d| %-13d | %-24s | %-24lu |\n", card_info->card_id, chip_index,
                card_info->chip_proc_info[chip_index][proc_index].proc_id,
                card_info->chip_proc_name[chip_index][proc_index],
                (unsigned long)(card_info->chip_proc_info[chip_index][proc_index].proc_mem_usage /
                    BYTE_TO_KB_TRANS_VALUE / KB_TO_MB_TRANS_VALUE));
#endif
            if (proc_index == MAX_CHIP_PROCESS_NUM - 1) { // 防止进程信息刷屏
                break;
            }
        }
    }

    if (!process_num) {
        printf("| No running processes found in NPU %-7d                      "\
            "                                 |\n", card_info->card_id);
    }

    printf("+===========================+======="\
        "========+=====================================================+\n");
    return;
}

bool check_file(const char* filename, const char* str)
{
    FILE* fp = fopen(filename, "r");
    char buf[MAX_CHAR_LEN];

    if (fp == NULL) {
        gplog(LOG_ERR, "File %s does not exist.", filename);
        return FALSE;
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (strstr(buf, str) != NULL) {
            // 找到了目标字符串
            fclose(fp);
            return TRUE;
        }
    }
    (void)fclose(fp);
    gplog(LOG_ERR, "The character string %s is not found.", str);
    return FALSE;
}

void print_total_info_header_950(struct npu_total_info *npu_total_info)
{
    printf("+-------------------------------------------------------------------------------------------------+\n");
    printf("| %s %-40s Version: %-37s |\n", TOOL_NAME, TOOL_VERSION, npu_total_info->software_version);
    printf("+--------+------------------+---------------+-----------------------------------------------------+\n");
    printf("| NPU ID | Name             | Health        | Power(W)    Temp(C)           Hugepages-Usage(page) |\n");
    printf("|        |                  | Bus-Id        | NPU Util(%%) Memory-Usage(MB)  HBM-Usage(MB)         |\n");
    printf("+========+==================+===============+=====================================================+\n");
}

void print_total_info_header_v1(struct npu_total_info *npu_total_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    printf("+-------------------------------------------------------------------------------------------------+\n");
    printf("| %s %-24s Version: %-53s |\n", TOOL_NAME, TOOL_VERSION, npu_total_info->software_version);
    printf("+---------------------------+---------------+-----------------------------------------------------+\n");
    printf("| NPU   Name                | Health        | Power(W)    Temp(C)           Hugepages-Usage(page) |\n");
    if (chip_type == NPU_CHIP_910_93) {
        printf("| Chip  Phy-ID              | Bus-Id        | AICore(%%)   Memory-Usage(MB)  HBM-Usage(MB)   "
        "      |\n");
    } else {
        printf("| Chip                      | Bus-Id        | AICore(%%)   Memory-Usage(MB)  HBM-Usage(MB)  "
        "       |\n");
    }
    printf("+===========================+===============+=====================================================+\n");
}

void print_total_info_with_HBM(struct npu_total_info *npu_total_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    int card_index;

    if (chip_type == NPU_CHIP_950) {
        print_total_info_header_950(npu_total_info);
    } else {
        print_total_info_header_v1(npu_total_info);
    }

    for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
        struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
        print_card_total_info_with_HBM(card_info);
    }
#ifdef NPU_SMI_V2
    printf("+---------------------------+---------------+-----------------------------------------------------+\n");
    printf("| NPU ID                    | Process id    | Process name             | Process memory(MB)       |\n");
    printf("+===========================+===============+=====================================================+\n");
#else
    printf("+---------------------------+---------------+-----------------------------------------------------+\n");
    printf("| NPU     Chip              | Process id    | Process name             | Process memory(MB)       |\n");
    printf("+===========================+===============+=====================================================+\n");
#endif
    for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
        struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
        if (card_info->card_id >= 0) {
            print_proc_total_info_with_HBM(card_info);
        }
    }
    if (!dcmi_check_run_in_docker() && !check_file("/etc/ascend_install.info", "Driver_Install_Status=complete")) {
        printf("[WARNING]The driver package may not be completely installed, "\
            "which may cause function abnormal. Please reinstall it.\n");
    }
    return;
}

void print_mapping_info_910_93(struct npu_mapping_info *npu_mapping_info)
{
    int card_index, chip_index;

    if (npu_mapping_info->card_count < 1) {
        printf("There is no NPU card on this server.\n");
        return;
    }

    printf("\t%-30s %-30s %-30s %-30s %-30s\n", "NPU ID", "Chip ID", "Chip Logic ID", "Chip Phy-ID", "Chip Name");
    for (card_index = 0; card_index < npu_mapping_info->card_count; card_index++) {
        for (chip_index = 0; chip_index < npu_mapping_info->card_info[card_index].chip_count; chip_index++) {
            printf("\t%-30d %-30d %-30d %-30d %s\n",
                npu_mapping_info->card_info[card_index].card_id,
                chip_index,
                npu_mapping_info->card_info[card_index].chip_logic_id[chip_index],
                npu_mapping_info->card_info[card_index].chip_phy_id[chip_index],
                npu_mapping_info->card_info[card_index].chip_info[chip_index].chip_name);
        }
        if (npu_mapping_info->card_info[card_index].mcu_id != -1) {
            printf("\t%-30d %-30d %-30s %-30s %-30s\n",
                npu_mapping_info->card_info[card_index].card_id,
                npu_mapping_info->card_info[card_index].mcu_id,
                "-",
                "-",
                "Mcu");
        }
        if (npu_mapping_info->card_info[card_index].cpu_id != -1) {
            printf("\t%-30d %-30d %-30s %-30s %-30s\n",
                npu_mapping_info->card_info[card_index].card_id,
                npu_mapping_info->card_info[card_index].cpu_id,
                "-",
                "-",
                "3559");
        }
    }

    return;
}

void print_mapping_info_950(struct npu_mapping_info *npu_mapping_info)
{
    int card_index, chip_index = 0;
    int start = 0;

    if (npu_mapping_info->card_count < 1) {
        printf("There is no NPU card on this server.\n");
        return;
    }
        
    for (start = 0; start < npu_mapping_info->card_count; start++) {
        if (g_board_details.card_info[start].slot_id != -1) {
            break;
        }
    }

    if (start >= MAX_CARD_NUM_IN_BROAD) {
        start = 0;
    }

    printf("\t%-30s %-30s %-30s %-30s %-30s\n", "NPU ID", "Slot ID", "Chip ID", "Chip Phy-ID", "Chip Name");
    for (card_index = 0; card_index < npu_mapping_info->card_count; card_index++) {
        printf("\t%-30d %-30d %-30d %-30d %s\n",
            npu_mapping_info->card_info[card_index].card_id,
            g_board_details.card_info[start].slot_id,
            chip_index,
            npu_mapping_info->card_info[card_index].chip_phy_id[chip_index],
            npu_mapping_info->card_info[card_index].chip_info[chip_index].chip_name);
        start++;
    }
    return;
}

void print_all_info(struct npu_all_info *npu_all_info)
{
    int i;
    enum npu_chip_type chip_type = npu_get_chip_type();

    bool check_result = ((chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
                         chip_type == NPU_CHIP_950) && (npu_board_type_is_server()));

    if (npu_all_info->card_count < 1) {
        if (npu_board_type_is_station() || npu_board_type_is_hilens()) {
            printf("\t%-30s : %d\n", "NPU ID", npu_all_info->card_info[0].card_id);
            printf("\t%-30s : %s\n", "Product Name", npu_all_info->card_info[0].product_name);
            printf("\t%-30s : %s\n", "Serial Number", npu_all_info->card_info[0].serial_number);
#ifndef NPU_SMI_V2
            printf("\t%-30s : %d\n\n", "Chip Count", npu_all_info->card_info[0].chip_count);
#endif
        } else {
            printf("There is no NPU card on this server.\n");
        }
        return;
    }

    if ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310B)) {
        printf("\t%-30s : %d\n\n", "Card Count", npu_all_info->card_count);
    } else {
        printf("\t%-30s : %d\n\n", "Total Count", npu_all_info->card_count);
    }

    for (i = 0; i < npu_all_info->card_count; i++) {
        printf("\t%-30s : %d\n", "NPU ID", npu_all_info->card_info[i].card_id);
        if (!check_result) {
            printf("\t%-30s : %s\n", "Product Name", npu_all_info->card_info[i].product_name);
            printf("\t%-30s : %s\n", "Serial Number", npu_all_info->card_info[i].serial_number);
        }
#ifndef NPU_SMI_V2
        printf("\t%-30s : %d\n\n", "Chip Count", npu_all_info->card_info[i].chip_count);
#else
        printf("\n");
#endif
    }
    return;
}

void print_mapping_info(struct npu_mapping_info *npu_mapping_info)
{
    int card_index, chip_index;

    if (npu_mapping_info->card_count < 1) {
        printf("There is no NPU card on this server.\n");
        return;
    }

    printf("\t%-30s %-30s %-30s %-30s\n", "NPU ID", "Chip ID", "Chip Logic ID", "Chip Name");
    for (card_index = 0; card_index < npu_mapping_info->card_count; card_index++) {
        for (chip_index = 0; chip_index < npu_mapping_info->card_info[card_index].chip_count; chip_index++) {
            if (npu_get_chip_type() == NPU_CHIP_310) {
                printf("\t%-30d %-30d %-30d %-30s\n", npu_mapping_info->card_info[card_index].card_id, chip_index,
                    npu_mapping_info->card_info[card_index].chip_logic_id[chip_index], "MiniD");
            } else {
                printf("\t%-30d %-30d %-30d %s %s\n", npu_mapping_info->card_info[card_index].card_id, chip_index,
                    npu_mapping_info->card_info[card_index].chip_logic_id[chip_index],
                    npu_mapping_info->card_info[card_index].chip_info[chip_index].chip_type,
                    npu_mapping_info->card_info[card_index].chip_info[chip_index].chip_name);
            }
        }
        if (npu_mapping_info->card_info[card_index].mcu_id != -1) {
            printf("\t%-30d %-30d %-30s %-30s\n",
                npu_mapping_info->card_info[card_index].card_id,
                npu_mapping_info->card_info[card_index].mcu_id,
                "-",
                "Mcu");
        }
        if (npu_mapping_info->card_info[card_index].cpu_id != -1) {
            printf("\t%-30d %-30d %-30s %-30s\n",
                npu_mapping_info->card_info[card_index].card_id,
                npu_mapping_info->card_info[card_index].cpu_id,
                "-",
                "3559");
        }
    }

    return;
}

void print_flash_info(struct npu_flash_info *flash_info)
{
    unsigned int i;
    unsigned long long mb_capacity;

    printf("\t%-30s : %u\n", "Flash Count", flash_info->flash_count);
    for (i = 0; i < flash_info->flash_count; i++) {
        printf("\n");
        printf("\t%-30s : %llu\n", "Flash ID", flash_info->flash_info[i].flash_id);
        printf("\t%-30s : 0x%X\n", "Manufacturer ID", flash_info->flash_info[i].manufacturer_id);
        (void)bytes_transform(flash_info->flash_info[i].size, BYTES_MB, &mb_capacity);
        printf("\t%-30s : %llu\n", "Capacity(MB)", mb_capacity);
    }

    return;
}

void print_chip_usages_dvpp_info(struct npu_chip_usages_info *usages_info)
{
    printf("\t%-30s : %d\n", "DVPP VDEC Usage Rate(%)", usages_info->dvpp_ratio.vdec_ratio);
    printf("\t%-30s : %d\n", "DVPP VPC Usage Rate(%)", usages_info->dvpp_ratio.vpc_ratio);
    if (((unsigned int)usages_info->dvpp_ratio.venc_ratio & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %d\n", "DVPP VENC Usage Rate(%)", usages_info->dvpp_ratio.venc_ratio);
    }
    if (((unsigned int)usages_info->dvpp_ratio.jpege_ratio & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %d\n", "DVPP JPEGE Usage Rate(%)", usages_info->dvpp_ratio.jpege_ratio);
    }
    printf("\t%-30s : %d\n", "DVPP JPEGD Usage Rate(%)", usages_info->dvpp_ratio.jpegd_ratio);
}

void print_chip_memory_usages_info(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310B)) {
        printf("\t%-30s : %llu\n", "Memory Capacity(MB)", usages_info->memory_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "Memory Usage Rate(%)", usages_info->memory_size_info_M.utiliza);
        printf("\t%-30s : %lu\n", "Hugepages Total(page)", usages_info->memory_size_info_M.hugepages_total);
        if (usages_info->memory_size_info_M.hugepages_total == 0) {
            printf("\t%-30s : %d\n", "Hugepages Usage Rate(%)", 0);
        } else {
            printf("\t%-30s : %d\n", "Hugepages Usage Rate(%)",
                (int)((usages_info->memory_size_info_M.hugepages_total -
                usages_info->memory_size_info_M.hugepages_free) *
                DIGITAL_NUM_TO_PER / usages_info->memory_size_info_M.hugepages_total));
        }
    } else if (chip_type == NPU_CHIP_910B || (chip_type == NPU_CHIP_910_93) ||
                (chip_type == NPU_CHIP_950)) { // 1980B、1980C、1980D无DDR
        printf("\t%-30s : %u\n", "DDR Capacity(MB)", 0);
        if (usages_info->memory_size_info_M.utiliza != NPU_DEFAULT_VALUE) {
            printf("\t%-30s : %u\n", "DDR Usage Rate(%)", 0);
        }
        printf("\t%-30s : %u\n", "DDR Hugepages Total(page)", 0);
        printf("\t%-30s : %d\n", "DDR Hugepages Usage Rate(%)", 0);
    } else {
        printf("\t%-30s : %llu\n", "DDR Capacity(MB)", usages_info->memory_size_info_M.memory_size);
        if (usages_info->memory_size_info_M.utiliza != NPU_DEFAULT_VALUE) {
            printf("\t%-30s : %u\n", "DDR Usage Rate(%)", usages_info->memory_size_info_M.utiliza);
        }
        printf("\t%-30s : %lu\n", "DDR Hugepages Total(page)", usages_info->memory_size_info_M.hugepages_total);
        if (usages_info->memory_size_info_M.hugepages_total == 0) {
            printf("\t%-30s : %d\n", "DDR Hugepages Usage Rate(%)", 0);
        } else {
            printf("\t%-30s : %d\n", "DDR Hugepages Usage Rate(%)",
                (int)((usages_info->memory_size_info_M.hugepages_total -
                usages_info->memory_size_info_M.hugepages_free) *
                DIGITAL_NUM_TO_PER / usages_info->memory_size_info_M.hugepages_total));
        }
    }
}

#ifdef _WIN32
void print_chip_usages_info(struct npu_chip_usages_info *usages_info)
{
    printf("\t%-30s : %llu\n", "Memory Capacity(MB)", usages_info->memory_size_info_M.memory_size);
    printf("\t%-30s : %u\n", "Memory Usage Rate(%)", usages_info->memory_size_info_M.utiliza);
    printf("\t%-30s : %s\n", "Hugepages Total(page)", "NA");
    printf("\t%-30s : %s\n", "Hugepages Usage Rate(%)", "NA");

    /* aicore的利用率底层返回为两个之和 */
    printf("\t%-30s : %u\n", "Aicore Usage Rate(%)", usages_info->aicore_usage);
    printf("\t%-30s : %u\n", "Aicpu Usage Rate(%)", usages_info->aicpu_usage);
    printf("\t%-30s : %u\n", "Ctrlcpu Usage Rate(%)", usages_info->ctrlcpu_usage);

    printf("\t%-30s : %u\n", "Memory Bandwidth Usage Rate(%)", usages_info->memory_bandwidth_usage);

    return;
}
#else
void get_hbm_usage_rate_910b(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (usages_info->hbm_size_info_M.memory_size == 0) {
        return;
    }

    if (chip_type == NPU_CHIP_910B) {
        // 虚拟化场景下 获取的hbm usage通过memory usage/ memory size计算
        usages_info->hbm_usage =
            usages_info->hbm_size_info_M.memory_usage * PERCENTAGE / usages_info->hbm_size_info_M.memory_size;
    }
    return;
}

STATIC void print_aicube_usages_rate_info(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (((usages_info->aicube_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) &&
        (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
         chip_type == NPU_CHIP_950)) {
        printf("\t%-30s : %u\n", "Aicube Usage Rate(%)", usages_info->aicube_usage);
    }
    return;
}

STATIC void print_aicore_usages_rate_info(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    /* 除910B产品，aicore的利用率底层返回为两个之和 */
    if ((usages_info->aicore_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %u\n", "Aicore Usage Rate(%)", usages_info->aicore_usage);
    }

    if (((usages_info->aivector_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) &&
        (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950)) {
        printf("\t%-30s : %u\n", "Aivector Usage Rate(%)", usages_info->aivector_usage);
    }
    return;
}

void print_chip_usages_npu_utilization(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        printf("\t%-30s : %u\n", "NPU Utilization(%)", usages_info->npu_utilization_usage);
    }
}

void print_chip_usages_info(struct npu_chip_usages_info *usages_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool support_chip_type = (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
                              chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
    print_chip_memory_usages_info(usages_info);

    if (support_chip_type) {
        printf("\t%-30s : %llu\n", "HBM Capacity(MB)", usages_info->hbm_size_info_M.memory_size);
        get_hbm_usage_rate_910b(usages_info);
        if ((usages_info->hbm_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
            printf("\t%-30s : %u\n", "HBM Usage Rate(%)", usages_info->hbm_usage);
        }
    }

    print_aicore_usages_rate_info(usages_info);

    if ((usages_info->aicpu_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %u\n", "Aicpu Usage Rate(%)", usages_info->aicpu_usage);
    }
    if ((usages_info->ctrlcpu_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %u\n", "Ctrlcpu Usage Rate(%)", usages_info->ctrlcpu_usage);
    }
    if (chip_type == NPU_CHIP_310P) {
        printf("\t%-30s : %u\n", "Vectorcore Usage Rate(%)", usages_info->vectorcore_usage);
    }
    if ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310B)) {
        printf("\t%-30s : %u\n", "Memory Bandwidth Usage Rate(%)", usages_info->memory_bandwidth_usage);
    } else if (chip_type == NPU_CHIP_910B) {
        if ((usages_info->memory_bandwidth_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
            printf("\t%-30s : %u\n", "DDR Bandwidth Usage Rate(%)", 0);
        }
    } else {
        if ((usages_info->memory_bandwidth_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
            printf("\t%-30s : %u\n", "DDR Bandwidth Usage Rate(%)", usages_info->memory_bandwidth_usage);
        }
    }

    if (support_chip_type) {
        printf("\t%-30s : %u\n", "HBM Bandwidth Usage Rate(%)", usages_info->hbm_size_info_M.bandwith_util_rate);
    }

    if (chip_type == NPU_CHIP_310P) {
        print_chip_usages_dvpp_info(usages_info);
    }
    print_chip_usages_npu_utilization(usages_info);
    print_aicube_usages_rate_info(usages_info);
    return;
}
#endif

static void print_ascend_310b_module_id(unsigned int module_id)
{
    if (npu_get_chip_type() == NPU_CHIP_310B) {
        if (module_id == 0) {
            printf("\t%-30s : %s\n", "Module Board ID", "NA");
        } else {
            printf("\t%-30s : 0x%02x\n", "Module Board ID", module_id);
        }
    }
}

static void print_ascend_910_93_npu_name(struct npu_chip_info *chip_info)
{
    if (npu_get_chip_type() == NPU_CHIP_910_93 || npu_get_chip_type() == NPU_CHIP_950) {
        printf("\t%-30s : %s\n", "NPU Name", chip_info->chip_info.npu_name);
    }
}

static void print_die_id_info(struct npu_chip_info *chip_info)
{
    size_t i, count;
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool support_chip_type = (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
                              chip_type == NPU_CHIP_910_93);
    
    if (chip_type == NPU_CHIP_950) {
        count = sizeof(chip_info->ddie_id.soc_die) / sizeof(chip_info->ddie_id.soc_die[0]);
        printf("\t%-30s : %d\n", "DDie Count", 1);
        printf("\t%-30s :", "DDie ID");
        for (i = 0; i < count; i++) {
            printf(" %08X", chip_info->ddie_id.soc_die[i]);
        }
        printf("\n");
        return;
    }
    if (support_chip_type) {
        printf("\t%-30s :", "VDie ID");
    } else if ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310B)) {
        printf("\t%-30s : %s,", "Die ID", chip_info->chip_info.chip_ver);
    } else {
        printf("\t%-30s :", "Die ID");
    }

    count = sizeof(chip_info->vdie_id.soc_die) / sizeof(chip_info->vdie_id.soc_die[0]);
    for (i = 0; i < count; i++) {
        printf(" %08X", chip_info->vdie_id.soc_die[i]);
    }
    printf("\n");
    if (support_chip_type) {
        printf("\t%-30s :", "NDie ID");
        count = sizeof(chip_info->ndie_id.soc_die) / sizeof(chip_info->ndie_id.soc_die[0]);
        for (i = 0; i < count; i++) {
            printf(" %08X", chip_info->ndie_id.soc_die[i]);
        }
        printf("\n");
    }
}

static void print_ascend_chip_info(struct npu_chip_info *chip_info, unsigned int module_id)
{
    enum npu_chip_type chip_type = npu_get_chip_type();

    printf("\t%-30s : %d\n", "NPU ID", chip_info->npu_id);
    print_ascend_910_93_npu_name(chip_info);
    printf("\t%-30s : %d\n", "Chip ID", chip_info->chip_id);
    if (chip_type != NPU_CHIP_910_93 && chip_type != NPU_CHIP_950) {
        printf("\t%-30s : %s\n", "Chip Type", chip_info->chip_info.chip_type);
    }
    printf("\t%-30s : %s\n", "Chip Name", chip_info->chip_info.chip_name);
    printf("\t%-30s : %s\n", "Chip Version", chip_info->chip_info.chip_ver);
    printf("\t%-30s : 0x%02x\n", "Board ID", chip_info->board_info.board_id);
    print_ascend_310b_module_id(module_id);

    if (!(chip_type == NPU_CHIP_310P)) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
        printf("\t%-30s : %u\n", "BOM ID", chip_info->board_info.bom_id);
    }

    print_die_id_info(chip_info);

    if ((npu_board_type_is_soc() == TRUE) && (chip_type == NPU_CHIP_310P)) {
        printf("\t%-30s : %s\n", "Firmware Version", chip_info->xloader_version);
    }

    /* 此处需要评估下此处在模组和SOC形态下打印是否存在异常 */
    if (npu_board_type_is_card() == TRUE || npu_board_type_is_server()) {
        printf("\t%-30s : %d\n", "Chip Position ID", chip_info->chip_pos_id);

        if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
            printf("\t%-30s : %s\n", "PCIe Bus Info", "NA");
        } else {
            printf("\t%-30s : %04X:%02X:%02X.%X\n", "PCIe Bus Info", chip_info->device_pcie_info.domain,
                chip_info->device_pcie_info.bdf_busid, chip_info->device_pcie_info.bdf_deviceid,
                chip_info->device_pcie_info.bdf_funcid);
        }
        printf("\t%-30s : %s\n", "Firmware Version", chip_info->xloader_version);
    }
}

static void print_mcu_firmware_version_info(struct npu_chip_info *chip_info)
{
    if (dcmi_check_vnpu_in_docker_or_virtual(chip_info->npu_id) == TRUE) {
        // 910B算力切分容器场景查不到固件版本信息,修改回显为NA
        printf("\t%-30s : %s\n", "Firmware Version",
            strcmp(chip_info->xloader_version, "0") == 0 ? "NA" : chip_info->xloader_version);
    } else {
        printf("\t%-30s : %s\n", "Firmware Version", chip_info->xloader_version);
    }
}

static void print_mcu_chip_info(struct npu_chip_info *chip_info)
{
    printf("\t%-30s : %d\n", "NPU ID", chip_info->npu_id);
    printf("\t%-30s : %d\n", "Chip ID", chip_info->chip_id);
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-30s : %s\n", "Chip Type", chip_info->chip_info.chip_type);
    }
    printf("\t%-30s : %s\n", "Chip Name", chip_info->chip_info.chip_name);
    if (npu_get_chip_type() == NPU_CHIP_910B && !(chip_info->board_info.board_id)) {
        printf("\t%-30s : %s\n", "Board ID", "NA");
    } else {
        printf("\t%-30s : 0x%02x\n", "Board ID", chip_info->board_info.board_id);
    }

    printf("\t%-30s : %s\n", "PCB ID", "NA");
    if (npu_get_chip_type() == NPU_CHIP_910B && !(chip_info->board_info.bom_id)) {
        printf("\t%-30s : %s\n", "BOM ID", "NA");
    } else {
        printf("\t%-30s : %u\n", "BOM ID", chip_info->board_info.bom_id);
    }
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-30s : %s\n", "Die ID", "NA");
    }
    printf("\t%-30s : %d\n", "Chip Position ID", chip_info->chip_pos_id);
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-30s : %s\n", "PCIe Bus Info", "NA");
    }

    // 圈复杂度过高,单独封装一个打印mcu firmware version的函数
    print_mcu_firmware_version_info(chip_info);
}

static void print_cpu_chip_info(struct npu_chip_info *chip_info)
{
    size_t i, count;

    printf("\t%-30s : %d\n", "NPU ID", chip_info->npu_id);
    printf("\t%-30s : %d\n", "Chip ID", chip_info->chip_id);
    printf("\t%-30s : %s\n", "Chip Type", chip_info->chip_info.chip_type);
    printf("\t%-30s : %s\n", "Chip Name", chip_info->chip_info.chip_name);
    printf("\t%-30s : 0x%02x\n", "Board ID", chip_info->board_info.board_id);
    printf("\t%-30s : %s\n", "PCB ID", "NA");
    printf("\t%-30s : %u\n", "BOM ID", chip_info->board_info.bom_id);
    printf("\t%-30s : %s,", "Die ID", chip_info->chip_info.chip_ver);
    count = sizeof(chip_info->vdie_id.soc_die) / sizeof(chip_info->vdie_id.soc_die[0]);
    for (i = 0; i < count; i++) {
        printf(" %08X", chip_info->vdie_id.soc_die[i]);
    }
    printf("\n\t%-30s : %d\n", "Chip Position ID", chip_info->chip_pos_id);
}

void print_chip_info_by_type(enum dcmi_unit_type device_type, struct npu_chip_info *chip_info, unsigned int module_id)
{
    if (chip_info == NULL) {
        return;
    }

    if (device_type == NPU_TYPE) {
        print_ascend_chip_info(chip_info, module_id);
    } else if (device_type == MCU_TYPE) {
        print_mcu_chip_info(chip_info);
    } else if (device_type == CPU_TYPE) {
        print_cpu_chip_info(chip_info);
    } else {
        gplog(LOG_INFO, "device_type is not support.%d.\n", device_type);
        return;
    }
    return;
}

void print_ddr_info(unsigned int ddr_info, struct npu_memory_info *memory_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_310 || chip_type == NPU_CHIP_310B) {
        if (chip_type == NPU_CHIP_310B) {
            printf("\t%-30s : %u\n", "Total Capacity(MB)", ddr_info);
        }
        printf("\t%-30s : %llu\n", "Capacity(MB)", memory_info->memory_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "Clock Speed(MHz)", memory_info->memory_frequency_mhz);
    } else if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        printf("\t%-30s : %u\n", "DDR Capacity(MB)", 0);
        printf("\t%-30s : %u\n", "DDR Clock Speed(MHz)", 0);
    } else {
        if (chip_type == NPU_CHIP_310P) {
            printf("\t%-30s : %u\n", "Total DDR Capacity(MB)", ddr_info);
        }
        printf("\t%-30s : %llu\n", "DDR Capacity(MB)", memory_info->memory_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "DDR Clock Speed(MHz)", memory_info->memory_frequency_mhz);
    }
    return;
}

void print_hbm_info(struct npu_memory_info *memory_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
        chip_type == NPU_CHIP_950) {
        printf("\t%-30s : %llu\n", "HBM Capacity(MB)", memory_info->hbm_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "HBM Clock Speed(MHz)", memory_info->hbm_frequency_mhz);
        printf("\t%-30s : %d\n", "HBM Temperature(C)", memory_info->hbm_size_info_M.temp);
        if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
            printf("\t%-30s : 0x%X\n", "HBM Manufacturer ID", memory_info->hbm_product_info.manufacturer_id);
        }
    }
    return;
}

void print_memory_info(int card_id, int device_id, struct npu_memory_info *memory_info)
{
    int ret = 0;
    int device_logic_id = 0;
    unsigned int ddr_info = 0;
    unsigned int ddr_size = sizeof(ddr_info);
    enum npu_chip_type chip_type = npu_get_chip_type();

    if (!dcmi_board_chip_type_is_ascend_950()) {
        ret = dcmi_get_device_logic_id(&device_logic_id, card_id, device_id);
    } else {
        device_logic_id = card_id;
    }

    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_device_logic_id failed. err is %d.", ret);
        return;
    }

    if (!((chip_type == NPU_CHIP_910) || (chip_type == NPU_CHIP_910B) ||
        (chip_type == NPU_CHIP_910_93) ||(chip_type == NPU_CHIP_950))) {
            ret = dsmi_get_device_info(device_logic_id, DSMI_MAIN_CMD_MEMORY, DSMI_SUB_CMD_MEMORY_CAPACITY,
                (void*)&ddr_info, &ddr_size);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "call dsmi_get_device_info failed, type=%d. err is %d.", npu_get_chip_type(), ret);
            }
    }

    print_ddr_info(ddr_info, memory_info);
    print_hbm_info(memory_info);

    return;
}

STATIC void print_chip_compatibility_info(struct npu_device_info *device_info)
{
    int ret;
    char* compt_list[] = {"", "OK", "NOK", "UNKNOWN", NULL};

    /* 仅支持EP设备，RC设备、310不支持(直接不打印) */
    if ((npu_board_type_is_soc() == TRUE) || (dcmi_board_chip_type_is_ascend_310() == TRUE)) {
        return;
    }
#ifndef _WIN32
    ret = (int)geteuid();
#else
    ret = root_user_check();
#endif
    /* 仅支持root用户 */
    if ((ret != NPU_OK) ||
        (device_info->compat_info.err == DCMI_ERR_CODE_NOT_SUPPORT) ||
        (device_info->compat_info.err == DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
        printf("\t%-30s : %s\n", "Compatibility", "NOT SUPPORT");
    } else if (device_info->compat_info.compatibility == 0) {
        printf("\t%-30s : %s\n", "Compatibility", "UNKNOWN");
    } else {
        printf("\t%-30s : %s\n", "Compatibility", compt_list[(int)device_info->compat_info.compatibility]);
    }
}

STATIC void print_card_board_info(struct npu_device_info *device_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B && !(device_info->board_info.board_id)) {
        printf("\t%-30s : %s\n", "Board ID", "NA");
    } else {
        printf("\t%-30s : 0x%02x\n", "Board ID", device_info->board_info.board_id);
    }

    if (chip_type == NPU_CHIP_950 && card_950_type_judge(device_info->main_board_id)) {
        printf("\t%-30s : 0x%02x(%dP)\n", "Main Board ID", device_info->main_board_id,
            card_950_type_judge(device_info->main_board_id));
    } else if (chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        printf("\t%-30s : 0x%02x\n", "Main Board ID", device_info->main_board_id);
    }

    if (device_info->board_info.pcb_id == 0) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
    } else {
        printf("\t%-30s : %c\n", "PCB ID", (char)('A' + (device_info->board_info.pcb_id - 1)));
    }
    if (chip_type == NPU_CHIP_910B && !(device_info->board_info.bom_id)) {
        printf("\t%-30s : %s\n", "BOM ID", "NA");
    } else {
        printf("\t%-30s : %u\n", "BOM ID", device_info->board_info.bom_id);
    }
}

STATIC void print_card_ub_info(struct npu_device_info *device_info)
{
    printf("\t%-30s : %s\n", "PCIe Bus Info", "NA");
    printf("\t%-30s : %d\n", "Slot ID", device_info->slot_id);
    printf("\t%-30s : %s\n", "Class ID", "NA");
    printf("\t%-30s : 0x%04X\n", "Vendor ID", device_info->device_ub_id_info.vendor_id);
    printf("\t%-30s : 0x%04X\n", "Device ID", device_info->device_ub_id_info.device_id);
    printf("\t%-30s : 0x%04X\n", "Module Vendor ID", device_info->device_ub_id_info.module_vendor_id);
    printf("\t%-30s : 0x%04X\n", "Module ID", device_info->device_ub_id_info.module_id);
}

STATIC void print_card_pcie_info(struct npu_device_info *device_info)
{
    printf("\t%-30s : %04X:%02X:%02X.%X\n", "PCIe Bus Info", device_info->device_pcie_info.domain,
        device_info->device_pcie_info.bdf_busid, device_info->device_pcie_info.bdf_deviceid,
        device_info->device_pcie_info.bdf_funcid);
    printf("\t%-30s : %d\n", "Slot ID", device_info->slot_id);
    printf("\t%-30s : %s\n", "Class ID", "NA");
    printf("\t%-30s : 0x%04X\n", "PCI Vendor ID", device_info->device_pcie_info.venderid);
    printf("\t%-30s : 0x%04X\n", "PCI Device ID", device_info->device_pcie_info.deviceid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Vendor ID", device_info->device_pcie_info.subvenderid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Device ID", device_info->device_pcie_info.subdeviceid);
}

void print_ascend_board_info(struct npu_device_info *device_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();

    printf("\t%-30s : %d\n", "NPU ID", device_info->npu_id);
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
        chip_type == NPU_CHIP_950) {
        printf("\t%-30s : %s\n", "Product Name", device_info->product_name);
        printf("\t%-30s : %s\n", "Model", device_info->model);
        printf("\t%-30s : %s\n", "Manufacturer", device_info->manufacturer);
        printf("\t%-30s : %s\n", "Serial Number", device_info->serial_number);
    }
    printf("\t%-30s : %s\n", "Software Version", device_info->software_version);
    printf("\t%-30s : %s\n", "Firmware Version", device_info->firmware_version);

    print_chip_compatibility_info(device_info);
    print_card_board_info(device_info);

    if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        print_card_ub_info(device_info);
    } else {
        print_card_pcie_info(device_info);
    }
    printf("\t%-30s : %d\n", "Chip Count", device_info->chip_count);

    return;
}

void printf_npu_card_pcie_info(struct npu_device_info *device_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool support_chip_type = (chip_type == NPU_CHIP_310P || chip_type == NPU_CHIP_910 ||
        chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_950);
    if (support_chip_type) {
        printf("\t%-30s : %04X:%02X:%02X.%X\n", "PCIe Bus Info", device_info->device_pcie_info.domain,
            device_info->device_pcie_info.bdf_busid, device_info->device_pcie_info.bdf_deviceid,
            device_info->device_pcie_info.bdf_funcid);
    } else {
        printf("\t%-30s : %s\n", "PCIe Bus Info", device_info->pcie_info);
    }
    if (device_info->slot_id == -1) {
        printf("\t%-30s : %s\n", "Slot ID", "NA");
    } else {
        printf("\t%-30s : %d\n", "Slot ID", device_info->slot_id);
    }

    printf("\t%-30s : %s\n", "Class ID", "NA");
    printf("\t%-30s : 0x%04X\n", "PCI Vendor ID", device_info->device_pcie_info.venderid);
    printf("\t%-30s : 0x%04X\n", "PCI Device ID", device_info->device_pcie_info.deviceid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Vendor ID", device_info->device_pcie_info.subvenderid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Device ID", device_info->device_pcie_info.subdeviceid);
    return;
}

void print_npu_card_info(struct npu_device_info *device_info)
{
    printf("\t%-30s : %d\n", "NPU ID", device_info->npu_id);

    printf("\t%-30s : %s\n", "Product Name", device_info->product_name);
    printf("\t%-30s : %s\n", "Model", device_info->model);
    printf("\t%-30s : %s\n", "Manufacturer", device_info->manufacturer);
    printf("\t%-30s : %s\n", "Serial Number", device_info->serial_number);
#ifdef _WIN32
    printf("\t%-30s : %s\n", "Software Version", TOOL_VERSION);
#else
    printf("\t%-30s : %s\n", "Software Version", device_info->software_version);
#endif
    printf("\t%-30s : %s\n", "Firmware Version", device_info->firmware_version);

    print_chip_compatibility_info(device_info);

    if (device_info->board_info.board_id == 0) {
        printf("\t%-30s : %s\n", "Board ID", "NA");
    } else {
        printf("\t%-30s : 0x%02x\n", "Board ID", device_info->board_info.board_id);
    }

    if (npu_get_chip_type() == NPU_CHIP_950 && card_950_type_judge(device_info->main_board_id)) {
        printf("\t%-30s : 0x%02x(%dP)\n", "Main Board ID", device_info->main_board_id,
            card_950_type_judge(device_info->main_board_id));
    }

    if (npu_board_type_is_model()) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
    } else {
        if (device_info->board_info.pcb_id == 0) {
            printf("\t%-30s : %s\n", "PCB ID", "NA");
        } else {
            printf("\t%-30s : %c\n", "PCB ID", (char)('A' + (device_info->board_info.pcb_id - 1)));
        }
    }

    printf("\t%-30s : %u\n", "BOM ID", device_info->board_info.bom_id);

    if (npu_board_type_is_card() == TRUE) {
        printf_npu_card_pcie_info(device_info);
    }
    printf("\t%-30s : %d\n", "Chip Count", device_info->chip_count);
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        if (npu_is_in_docker()) {
            printf("\t%-30s : %s\n", "Faulty Chip Count", "NA");
        } else {
            printf("\t%-30s : %d\n", "Faulty Chip Count", device_info->chip_fault);
        }
    } else {
        printf("\t%-30s : %d\n", "Chip Fault", device_info->chip_fault);
    }

    return;
}
#ifdef NPU_SMI_V2
STATIC void print_version_info(struct npu_device_info *device_info)
{
#ifdef _WIN32
    printf("\t%-30s : %s\n", "Software Version", TOOL_VERSION);
#else
    printf("\t%-30s : %s\n", "Software Version", device_info->software_version);
#endif
    printf("\t%-30s : %s\n", "Firmware Version", device_info->firmware_version);
    return;
}

void print_npu_info(struct npu_device_info *device_info, struct npu_chip_info *chip_info)
{
    int i, count, p_val;
    printf("\t%-30s : %d\n", "NPU ID", device_info->npu_id);

    printf("\t%-30s : %s\n", "Product Name", device_info->product_name);
    printf("\t%-30s : %s\n", "NPU Name", chip_info->chip_info.npu_name);
    printf("\t%-30s : %s\n", "Chip Name", chip_info->chip_info.chip_name);
    printf("\t%-30s : %s\n", "Chip Version", chip_info->chip_info.chip_ver);
    printf("\t%-30s : %s\n", "Model", device_info->model);
    printf("\t%-30s : %s\n", "Manufacturer", device_info->manufacturer);
    printf("\t%-30s : %s\n", "Serial Number", device_info->serial_number);

    print_version_info(device_info);

    print_chip_compatibility_info(device_info);

    if (device_info->board_info.board_id == 0) {
        printf("\t%-30s : %s\n", "Board ID", "NA");
    } else {
        printf("\t%-30s : 0x%02x\n", "Board ID", device_info->board_info.board_id);
    }

    if (npu_get_chip_type() == NPU_CHIP_950) {
        p_val = card_950_type_judge(device_info->main_board_id);
        if (p_val) {
            printf("\t%-30s : 0x%02x(%dP)\n", "Main Board ID", device_info->main_board_id, p_val);
        } else {
            printf("\t%-30s : 0x%02x\n", "Main Board ID", device_info->main_board_id);
        }
    }

    if (device_info->board_info.pcb_id == 0) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
    } else {
        printf("\t%-30s : %c\n", "PCB ID", (char)('A' + (device_info->board_info.pcb_id - 1)));
    }
    printf("\t%-30s : %u\n", "BOM ID", device_info->board_info.bom_id);

    if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        print_card_ub_info(device_info);
    } else {
        print_card_pcie_info(device_info);
    }

    printf("\t%-30s : %d\n", "Chip Count", device_info->chip_count);
    printf("\t%-30s :", "DDie ID");
    count = sizeof(chip_info->ddie_id.soc_die) / sizeof(chip_info->ddie_id.soc_die[0]);
    for (i = 0; i < count; i++) {
        printf(" %08X", chip_info->ddie_id.soc_die[i]);
    }
    printf("\n");
    printf("\t%-30s : %d\n", "Chip Position ID", chip_info->chip_pos_id);

    return;
}
#endif
static void print_mcu_common_info(struct npu_card_common_info *card_common_info)
{
    if (card_common_info->mcu_id != NPU_DEFAULT_VALUE) {
        printf("\n");
        printf("\t%-30s : %s\n", "Chip Name",
            ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) ? "MCU" : "mcu");
        if (dcmi_check_vnpu_in_docker_or_virtual(card_common_info->card_id) == TRUE &&
            card_common_info->chip_common_info[card_common_info->mcu_id].temp == 0) {
            // 910B算力切分下的容器和虚拟机场景，获取不到mcu信息，回显NA
            printf("\t%-30s : %s\n", "Temperature(C)", "NA");
        } else {
            printf("\t%-30s : %d\n", "Temperature(C)",
                card_common_info->chip_common_info[card_common_info->mcu_id].temp);
        }

        if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
            printf("\t%-30s : %.1f\n",
                "Power Dissipation(W)",
                card_common_info->chip_common_info[card_common_info->mcu_id].power * NPU_DECIMAL_TRANS);
        } else if (npu_get_chip_type() == NPU_CHIP_310P) {
            printf("\t%-30s : %.1f\n",
                "NPU Real-time Power(W)",
                card_common_info->chip_common_info[card_common_info->mcu_id].power * NPU_DECIMAL_TRANS);
        }
    }
}

static void print_cpu_common_info(struct npu_card_common_info *card_common_info)
{
    if (card_common_info->cpu_id != NPU_DEFAULT_VALUE) {
        printf("\n");
        printf("\t%-30s : %s\n", "Chip Name", "3559");
        printf("\t%-30s : %d\n", "Temperature(C)", card_common_info->chip_common_info[card_common_info->cpu_id].temp);
        printf("\t%-30s : %.1f\n",
            "Power Dissipation(W)",
            card_common_info->chip_common_info[card_common_info->cpu_id].power * NPU_DECIMAL_TRANS);
    }
}

int get_aicore_freq_support_type()
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    return chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_310P || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950;
}

int get_rated_power_dissipation_supppry_type()
{
    return npu_get_chip_type() == NPU_CHIP_310 || npu_get_chip_type() == NPU_CHIP_310B;
}

void print_memory_usage_rate_info(struct npu_card_common_info *card_common_info, int i)
{
    if (npu_get_chip_type() == NPU_CHIP_910B) {
        printf("\t%-30s : %u\n", "Memory Usage Rate(%)", 0);
    } else {
        printf("\t%-30s : %u\n", "Memory Usage Rate(%)", card_common_info->chip_common_info[i].memory_usage);
    }
    return;
}

void print_npu_common_info(struct npu_card_common_info *card_common_info)
{
    int i;
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool support_chip_type = (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
                             chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);

    for (i = 0; i < card_common_info->chip_count; i++) {
        if (npu_check_is_has_d_chip() == FALSE) {
            gplog(LOG_ERR, "npu chip not present.");
            break;
        }
#ifndef NPU_SMI_V2
        printf("\n\t%-30s : %d\n", "Chip ID", i);
#endif
        if (card_common_info->chip_common_info[i].memory_usage != NPU_DEFAULT_VALUE) {
            print_memory_usage_rate_info(card_common_info, i);
        }
        if (support_chip_type) {
            if ((card_common_info->chip_common_info[i].hbm_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
                printf("\t%-30s : %u\n", "HBM Usage Rate(%)", card_common_info->chip_common_info[i].hbm_usage);
            }
        }
        if ((card_common_info->chip_common_info[i].npu_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
            printf("\t%-30s : %u\n", "Aicore Usage Rate(%)", (card_common_info->chip_common_info[i].npu_usage));
        }
        if (get_aicore_freq_support_type()) {
            printf("\t%-30s : %u\n", "Aicore Freq(MHZ)", (card_common_info->chip_common_info[i].aicore_info.freq));
            printf("\t%-30s : %u\n", "Aicore curFreq(MHZ)",
                (card_common_info->chip_common_info[i].aicore_info.cur_freq));
        }

        if (support_chip_type) {
            printf("\t%-30s : %u\n", "Aicore Count", (card_common_info->chip_common_info[i].aicore_count));
        }

        printf("\t%-30s : %d\n", "Temperature(C)", card_common_info->chip_common_info[i].temp);
        if (get_rated_power_dissipation_supppry_type()) {
            printf("\t%-30s : %.1f\n", "Rated Power Dissipation(W)",
                card_common_info->chip_common_info[i].power * NPU_DECIMAL_TRANS);
        } else if (support_chip_type) {
            printf("\t%-30s : %.1f\n", "NPU Real-time Power(W)",
                card_common_info->chip_common_info[i].power * NPU_DECIMAL_TRANS);
        }
    }
}

void print_common_info(struct npu_card_common_info *card_common_info)
{
    if (!(npu_board_type_is_station() || npu_board_type_is_hilens())) {
        if (card_common_info->chip_count < 1) {
            printf("There is no NPU chip on this card.\n");
            return;
        }
    }

    printf("\t%-30s : %d\n", "NPU ID", card_common_info->card_id);
#ifndef NPU_SMI_V2
    printf("\t%-30s : %d\n", "Chip Count", card_common_info->chip_count);
#endif

    print_npu_common_info(card_common_info);
    print_mcu_common_info(card_common_info);
    print_cpu_common_info(card_common_info);
    return;
}

void print_chip_temperature_for_outband(int card_id, const char *data_info, int len)
{
    int ret;
    char tmp_data[TEMPERATURE_NAME_LEN + TEMPERATURE_NUM_LEN] = {0}; /* 临时存放温度名称 */
    int temp_index, temp_num, temp_get, name_offset, value_offset;
    bool chip_is_910b_93 = (npu_get_chip_type() == NPU_CHIP_910B) || (npu_get_chip_type() == NPU_CHIP_910_93);
    bool chip_is_910_series = (npu_get_chip_type() == NPU_CHIP_910) || chip_is_910b_93;
    const int chip_910_temp_sensor_num = 2;

    if (chip_is_910_series) {
        // A300T-9000 LM75温度传感器只有2个，其它D芯片，光模块等温度不显示；
        temp_num = chip_910_temp_sensor_num;
    } else {
        temp_num = (int)data_info[0];
    }
    for (temp_index = 0; temp_index < temp_num; temp_index++) {
        name_offset = temp_index * TEMPERATURE_INFO_LEN + TEMPERATURE_NUM_LEN;
        value_offset = temp_index * TEMPERATURE_INFO_LEN + TEMPERATURE_NAME_LEN + TEMPERATURE_NUM_LEN;
        temp_get = *(short *)(data_info + value_offset);
        /* PCIE带外管理规范，温度名称长度为8(不含结束字符) */
        ret = strncpy_s(tmp_data, sizeof(tmp_data), data_info + name_offset, TEMPERATURE_NAME_LEN);
        if (ret != EOK) {
            gplog(LOG_ERR, "strncpy_s failed. err is %d", ret);
            return;
        }
        if (strlen(tmp_data) == 0 && chip_is_910b_93) {
            printf("\t%-8s%-22s :", "NA", " (C)");
        } else {
            printf("\t%-8s%-22s :", tmp_data, " (C)");
        }

        if (temp_get == TEMP_VALUE_INVALID) {
            printf(" %s\n", "Failed");
        } else if (temp_get == TEMP_VALUE_ERROR) {
            printf(" %s\n", "NA");
        } else if (temp_get == 0 && chip_is_910b_93 &&
            dcmi_check_vnpu_in_docker_or_virtual(card_id)) {
            printf(" %s\n", "NA");
        } else {
            printf(" %d\n", temp_get);
        }
    }
}

void printf_ddr_ecc_info(struct dcmi_ecc_info *ddr_ecc_info, unsigned int next_isolated_pages_cnt)
{
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-40s : %u\n", "Single-bit Error Count", ddr_ecc_info->single_bit_error_cnt);
        printf("\t%-40s : %u\n", "Double-bit Error Count", ddr_ecc_info->double_bit_error_cnt);
    } else {
        printf("\t%-40s : %u\n", "DDR Single Bit Error Count", ddr_ecc_info->single_bit_error_cnt);
        printf("\t%-40s : %u\n", "DDR Double Bit Error Count", ddr_ecc_info->double_bit_error_cnt);
    }

    if (npu_get_chip_type() == NPU_CHIP_910 ||
        ((npu_get_chip_type() == NPU_CHIP_310P) && (!dcmi_board_type_is_soc()))) {
        printf("\t%-40s : %u\n", "DDR Single Bit Aggregate Total Err Cnt", ddr_ecc_info->total_single_bit_error_cnt);
        printf("\t%-40s : %u\n", "DDR Double Bit Aggregate Total Err Cnt", ddr_ecc_info->total_double_bit_error_cnt);
        printf("\t%-40s : %u\n", "DDR Single Bit Isolated Pages Count", ddr_ecc_info->single_bit_isolated_pages_cnt);
        printf("\t%-40s : %u\n", "DDR Double Bit Isolated Pages Count", ddr_ecc_info->double_bit_isolated_pages_cnt);
    }
    if ((npu_get_chip_type() == NPU_CHIP_310P) && (!dcmi_board_type_is_soc())) {
        printf("\t%-40s : 0\n", "DDR Single Bit Next-Isolated Pages Count");
        printf("\t%-40s : %u\n", "DDR Double Bit Next-Isolated Pages Count", next_isolated_pages_cnt);
    }
}

void printf_hbm_ecc_info(struct dcmi_ecc_info *hbm_ecc_info)
{
    printf("\t%-40s : %u\n", "HBM Single Bit Error Count", hbm_ecc_info->single_bit_error_cnt);
    printf("\t%-40s : %u\n", "HBM Double Bit Error Count", hbm_ecc_info->double_bit_error_cnt);
    printf("\t%-40s : %u\n", "HBM Single Bit Aggregate Total Err Cnt", hbm_ecc_info->total_single_bit_error_cnt);
    printf("\t%-40s : %u\n", "HBM Double Bit Aggregate Total Err Cnt", hbm_ecc_info->total_double_bit_error_cnt);
    printf("\t%-40s : %u\n", "HBM Single Bit Isolated Pages Count", hbm_ecc_info->single_bit_isolated_pages_cnt);
    printf("\t%-40s : %u\n", "HBM Double Bit Isolated Pages Count", hbm_ecc_info->double_bit_isolated_pages_cnt);
}

static int dcmi_get_single_error_info(struct npu_smi_operate_info *operate_info,
                                      unsigned int error_code, char *error_info)
{
    int ret;
    ret = memset_s(error_info, NPU_ERROR_STRING_MAX_LENGTH, 0, NPU_ERROR_STRING_MAX_LENGTH);
    if (ret != 0) {
        gplog(LOG_ERR, "call memset_s failed.%d.\n", ret);
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_errorcode_string(operate_info->id, operate_info->chip_id, error_code,
                                           (unsigned char *)error_info, NPU_ERROR_STRING_MAX_LENGTH);
#else
    ret = dcmiv2_get_device_error_info(operate_info->id, error_code,
                                       (unsigned char *)error_info, NPU_ERROR_STRING_MAX_LENGTH);
#endif
    return ret;
}

static bool print_health_status(struct npu_smi_operate_info *operate_info,
                                struct npu_device_health_info *health_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d", ret);
        return false;
    }

    if (dcmi_check_vnpu_in_docker_or_virtual(operate_info->id) && device_type == MCU_TYPE) {
        printf("\t%-30s : %s\n", "Health Status", "NA");
    } else {
        printf("\t%-30s : %s\n", "Health Status", health_info->health_state);
    }

    return true;
}

void print_diagnosis_info(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info)
{
    int ret, i;
    unsigned int error_code = 0;
    char error_info[NPU_ERROR_STRING_MAX_LENGTH] = {0};

    if (!print_health_status(operate_info, health_info)) {
        return;
    }

    /* 当无错误码时，直接返回 */
    if (health_info->error_code_count <= 0) {
        printf("\t%-30s : %s\n", "Error Code", "NA");
        printf("\t%-30s : %s\n", "Error Information", "NA");
        return;
    }

    printf("\t%-30s :", "Error Code");
    for (i = 0; i < health_info->error_code_count; i++) {
        printf(" %04X", health_info->error_code[i]);
    }
    printf("\n");
    printf("\t%-30s :", "Error Information");
    for (i = 0; i < health_info->error_code_count; i++) {
        error_code = (unsigned int)health_info->error_code[i];
        ret = dcmi_get_single_error_info(operate_info, error_code, error_info);
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            if (i == 0) {
                printf(" %u\n", error_code);
            } else {
                printf("\n\t%-30s : %u\n", " ", error_code);
            }
            continue;
        }
        if (ret != DCMI_OK) {
            printf("Failed to get error information for error code : 0x%04x\n", error_code);
            continue;
        }
 
        if (i == 0) {
            printf(" %s\n", error_info);
        } else {
            printf("\n\t%-30s : %s\n", " ", error_info);
        }
    }
 
    return;
}

void print_pcie_err_code(struct dcmi_chip_pcie_err_rate *pcie_err_code_info)
{
        printf("\t%-30s : %u\n", "Pcs Rx Error Count", pcie_err_code_info->pcs_rx_err_cnt);
        printf("\t%-30s : %u\n", "Phy Lane Error Count", pcie_err_code_info->phy_lane_err_counter);
        printf("\t%-30s : %u\n", "Dl Lcrc Error Count", pcie_err_code_info->dl_lcrc_err_num);
        printf("\t%-30s : %u\n", "Dl Dcrc Error Count", pcie_err_code_info->dl_dcrc_err_num);
}

void print_pcie_err_count(struct dcmi_pcie_link_error_info *pcie_err_count)
{
    printf("\t%-30s : %u\n", "TX Error Count", pcie_err_count->tx_err_cnt);
    printf("\t%-30s : %u\n", "RX Error Count", pcie_err_count->rx_err_cnt);
    printf("\t%-30s : %u\n", "Lcrc Error Count", pcie_err_count->lcrc_err_cnt);
    printf("\t%-30s : %u\n", "Ecrc Error Count", pcie_err_count->ecrc_err_cnt);
    printf("\t%-30s : %u\n", "Retry Count", pcie_err_count->retry_cnt);
}

void print_chip_temp_info(int ret, enum dcmi_unit_type device_type, int temp)
{
    if (ret != DCMI_OK) {
        return;
    }

    if (npu_board_type_is_server()) {
        printf("\t%-30s : %d\n", "NPU Temperature (C)", temp);
    } else {
        printf("\t%-30s : %d\n", "Temperature (C)", temp);
    }
}

void printf_template_info(struct dcmi_computing_template *template_in, unsigned int template_num)
{
    unsigned int index;
    const unsigned int mb_to_gb_shift_num = 10;
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|NPU instance template info is:                                                            |\n");
    printf("|Name                AICORE    Memory    AICPU     VPC            VENC           JPEGD     |\n");
    printf("|                               GB                 PNGD           VDEC           JPEGE     |\n");
    printf("|==========================================================================================|\n");
    for (index = 0; index < template_num; index++) {
        printf("|%-19s %-9u %-9u %-9g %-14d %-14d %-10d|\n",
            template_in[index].name, template_in[index].aicore_num, (template_in[index].mem_size >> mb_to_gb_shift_num),
            template_in[index].aicpu_num, (int)template_in[index].vpc, (int)template_in[index].venc,
            (int)template_in[index].jpegd);
        printf("|%-49s %-14g %-14d %-10d|\n", " ", template_in[index].pngd, (int)template_in[index].vdec,
            (int)template_in[index].jpege);
        printf("+------------------------------------------------------------------------------------------+\n");
    }
}

void print_npu_work_mode_info(const int card_id, const unsigned char work_mode)
{
    printf("\t%-30s : %d\n", "NPU ID", card_id);
    printf("\t%-30s : %s\n", "work-mode", (work_mode == 0 ? "AMP" : "SMP"));
}
#endif
