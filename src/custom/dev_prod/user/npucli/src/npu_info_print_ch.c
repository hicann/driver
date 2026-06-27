/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifdef ORIENT_CH
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
#include "dcmi_npu_link_intf.h"
#include "dcmi_environment_judge.h"
#include "dcmi_product_judge.h"
#include "npu_card_info.h"
#include "npu_chip_info.h"
#include "npu_info_print.h"
#include "dcmi_inner_info_get.h"

#define     PERCENTAGE           100
#define     HCCS_LANE_SPEED      56
#define     SINGLE_PACKETS_BYTES 20
#define     G_ARR_DIM            2
#define     G_ARR1_ROW           16
#define     G_ARR2_ROW           8
#define     G_ARR_COL            8
#define     ONE_GHZ              1000000000.0
#define     CONVERSION_MS        1000

/* 此数组用以记录天成(900)npu-交换芯片的hccs链路链接信息 */
/* row记录npu编号；col记录npu的某条hccs端口编号 */
/* 第一个二维数组对应的交换芯片编号，第二个二维数组记录NPU所链接的交换芯片对应的Macro端口 */
STATIC int g_hccs_topo_900[G_ARR_DIM][G_ARR1_ROW][G_ARR_COL] = {
    {
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 6, 5, 4, 3, 2, 1},
        {0, 7, 2, 1, 4, 3, 6, 5},
        {0, 7, 2, 1, 4, 3, 6, 5}
    },
    {
        {0, 16, 4, 16, 4, 16, 4, 16},
        {0, 16, 4, 16, 4, 16, 4, 16},
        {0, 14, 2, 14, 2, 14, 2, 14},
        {0, 14, 2, 14, 2, 14, 2, 14},
        {0, 12, 0, 12, 0, 12, 0, 12},
        {0, 12, 0, 12, 0, 12, 0, 12},
        {0, 19, 7, 19, 7, 19, 7, 19},
        {0, 19, 7, 19, 7, 19, 7, 19},
        {0, 17, 5, 17, 5, 17, 5, 17},
        {0, 17, 5, 17, 5, 17, 5, 17},
        {0, 15, 3, 15, 3, 15, 3, 15},
        {0, 15, 3, 15, 3, 15, 3, 15},
        {0, 13, 1, 13, 1, 13, 1, 13},
        {0, 13, 1, 13, 1, 13, 1, 13},
        {0, 18, 6, 18, 6, 18, 6, 18},
        {0, 18, 6, 18, 6, 18, 6, 18}
    }
};
/* 此数组用以记录天工(9000)npu-1520芯片的hccs链路链接信息 */
/* 第二个二维数组 row记录npu编号；col记录npu的某条hccs端口编号 */
/* 第二个数组中npu端口所链接的是第一个二维数组对应的1520芯片编号 */
STATIC int g_hccs_topo_9000[G_ARR_DIM][G_ARR2_ROW][G_ARR_COL] = {
    {
        {0, 0, 2, 2, 3, 3, 1, 1},
        {0, 0, 1, 1, 2, 2, 3, 3},
        {0, 0, 3, 3, 2, 2, 1, 1},
        {0, 0, 1, 1, 2, 2, 3, 3},
        {0, 0, 1, 1, 2, 2, 3, 3},
        {0, 0, 3, 3, 2, 2, 1, 1},
        {0, 0, 1, 1, 2, 2, 3, 3},
        {0, 0, 3, 3, 2, 2, 1, 1}
    },
    {
        {0, 0, 10, 10, 22, 22, 21, 21},
        {0, 0, 22, 22, 9, 9, 21, 21},
        {0, 0, 15, 15, 3, 3, 15, 14},
        {0, 0, 16, 17, 4, 4, 16, 16},
        {0, 0, 17, 16, 5, 5, 17, 17},
        {0, 0, 14, 14, 2, 2, 14, 15},
        {0, 0, 20, 20, 8, 8, 20, 20},
        {0, 0, 23, 23, 11, 11, 23, 23}
    }
};
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

    printf("%-12s%-12s", "NpuID(Idx)", "ChipId(Idx)");

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
    int ret;
    enum info_watch_type type;
    struct chip_watch_info_print_hook info_print[] = {
        {POWER_TYPE, print_chip_watch_pwr_info},
        {TEMP_TYPE, print_chip_watch_temp_info},
        {AI_CORE_TYPE, print_chip_watch_ai_core_info},
        {AI_CPU_TYPE, print_chip_watch_ai_cpu_info},
        {CTRL_CPU_TYPE, print_chip_watch_ctrl_cpu_info},
        {MEMORY_TYPE, print_chip_watch_hbm_info},
        {MEMORY_BANDWIDTH_TYPE, print_chip_watch_hbm_bandwidth_info},
        {NPU_UTILIZATION_TYPE, print_chip_npu_utilization_info},
        {AI_CUBE_TYPE, print_chip_watch_ai_cube_info}
    };

    printf("%-12d%-12d", card_id, device_id);
    if (npu_get_chip_type() != NPU_CHIP_910B && npu_get_chip_type() != NPU_CHIP_910_93) {
        struct chip_watch_info_print_hook info_print_910b_before[] = {
        {POWER_TYPE, print_chip_watch_pwr_info},
        {TEMP_TYPE, print_chip_watch_temp_info},
        {AI_CORE_TYPE, print_chip_watch_ai_core_info},
        {AI_CPU_TYPE, print_chip_watch_ai_cpu_info},
        {CTRL_CPU_TYPE, print_chip_watch_ctrl_cpu_info},
        {MEMORY_TYPE, print_chip_watch_memory_info},
        {MEMORY_BANDWIDTH_TYPE, print_chip_watch_memory_bandwidth_info},
        };
        ret = memcpy_s(info_print, sizeof(info_print), info_print_910b_before, sizeof(info_print_910b_before));
        if (ret != EOK) {
            gplog(LOG_ERR, "call memcpy_s failed.%d.", ret);
            return;
        }
        chip_info->usages_info.npu_utilization_usage = NPU_DEFAULT_VALUE;
    }
    if (npu_get_chip_type() == NPU_CHIP_910_93 && device_id == 1) {
        chip_info->power = NPU_DEFAULT_VALUE;
    }

    for (type = POWER_TYPE; type < WATCH_STYPE_BOTTOM; type++) {
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

void print_card_total_info_with_HBM_first(struct npu_card_total_info *card_info, int chip_index)
{
    int ret;
    char health_info[NPU_MAX_LENTH] = {0};
    ret = npu_common_get_health_state_str(card_info->chip_health[chip_index], &health_info[0], sizeof(health_info));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get health state failed, chip_index is %d err is %d.", chip_index, ret);
        return;
    }
    if (chip_index == 1 && npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("| %-5d %-20s| %-13s | %-11s %-17d %-5lu/ %-13lu |\n",
            card_info->card_id,
            card_info->chip_info[chip_index].chip_name,
            &health_info[0],
            "-",
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
                card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
    } else {  // 910_93的die1不显示功耗
        printf("| %-5d %-20s| %-13s | %-11.1f %-17d %-5lu/ %-13lu |\n",
            card_info->card_id,
            card_info->chip_info[chip_index].chip_name,
            &health_info[0],
            card_info->chip_common_info[chip_index].power * NPU_DECIMAL_TRANS,
            card_info->chip_common_info[chip_index].temp,
            card_info->chip_memory_info[chip_index].hugepages_total -
                card_info->chip_memory_info[chip_index].hugepages_free,
            card_info->chip_memory_info[chip_index].hugepages_total);
    }
}

void print_card_total_info_with_HBM_second(struct npu_card_total_info *card_info, int chip_index, unsigned int phyid)
{
    unsigned long long memory_total = card_info->chip_memory_info[chip_index].memory_size;
    int memory_used = (int)(memory_total - card_info->chip_memory_info[chip_index].memory_available);
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        memory_total = 0;
        memory_used = 0;
    }
    unsigned long long hbm_total = card_info->chip_hbm_info[chip_index].memory_size;
    int hbm_used = (int)card_info->chip_hbm_info[chip_index].memory_usage;

    if ((card_info->chip_common_info[chip_index].npu_usage & (0x1 << DCMI_VF_FLAG_BIT)) != 0) {
        card_info->chip_common_info[chip_index].npu_usage = 0;  // 算力分组场景获取的aicore利用率为0，实际无意义。
    }
    if (npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B) {
        printf("| %-26d| ", chip_index);
    } else if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("| %-5d %-20u| ", chip_index, phyid);
    }
    printf("%04X:%02X:%02X.%-2X | %-11u %-5d/ %-10llu %-5d/ %-13llu |\n",
        card_info->device_pcie_info[chip_index].domain,
        card_info->device_pcie_info[chip_index].bdf_busid,
        card_info->device_pcie_info[chip_index].bdf_deviceid,
        card_info->device_pcie_info[chip_index].bdf_funcid,
        (card_info->chip_common_info[chip_index].npu_usage),
        memory_used,
        memory_total,
        hbm_used,
        hbm_total);
}

void print_card_total_info_with_HBM(struct npu_card_total_info *card_info)
{
    int ret, chip_index;
    unsigned int phyid;

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        ret = dcmi_get_phyid_by_cardid_and_devid(card_info->card_id, chip_index, &phyid);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Get phyid failed. card id:%d, device id:%d.", card_info->card_id, chip_index);
            return;
        }

        print_card_total_info_with_HBM_first(card_info, chip_index);
        print_card_total_info_with_HBM_second(card_info, chip_index, phyid);
        if (chip_index != card_info->chip_count - 1) {
            printf("+------------------------------------------------------"\
                "------------------------------------------+\n");
        }
    }

    if (card_info->chip_count > 0) {
        printf("+===========================+===============+====================================================+\n");
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
            printf("| %-7d %-18d| %-13d | %-24s | %-23lu |\n", card_info->card_id, chip_index,
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
        printf("| No running processes found in NPU %-7d                      "\
            "                                |\n", card_info->card_id);
    }
    printf("+===========================+======="\
        "========+====================================================+\n");
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

void print_total_info_with_HBM(struct npu_total_info *npu_total_info)
{
    int card_index;

    printf("+------------------------------------------------------------------------------------------------+\n");
    printf("| %s %-24s Version: %-52s |\n", TOOL_NAME, TOOL_VERSION, npu_total_info->software_version);
    printf("+---------------------------+---------------+----------------------------------------------------+\n");
    printf("| NPU   Name                | Health        | Power(W)    Temp(C)           Hugepages-Usage(page)|\n");
    if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("| Chip  Phy-ID              | Bus-Id        | AICore(%%)   Memory-Usage(MB)  HBM-Usage(MB)        |\n");
    } else {
        printf("| Chip                      | Bus-Id        | AICore(%%)   Memory-Usage(MB)  HBM-Usage(MB)        |\n");
    }
    printf("+===========================+===============+====================================================+\n");

    for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
        struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
        print_card_total_info_with_HBM(card_info);
    }
    printf("+---------------------------+---------------+----------------------------------------------------+\n");
    printf("| NPU     Chip              | Process id    | Process name             | Process memory(MB)      |\n");
    printf("+===========================+===============+====================================================+\n");
    for (card_index = 0; card_index < npu_total_info->card_count; card_index++) {
        struct npu_card_total_info *card_info = &npu_total_info->card_info[card_index];
        if (card_info ->card_id < 0) {
            continue;
        }
        print_proc_total_info_with_HBM(card_info);
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
    bool check_result = ((npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
                             npu_get_chip_type() == NPU_CHIP_910_93) &&
                         (npu_board_type_is_server()));

    if (npu_all_info->card_count < 1) {
        if (npu_board_type_is_station() || npu_board_type_is_hilens()) {
            printf("\t%-30s : %d\n", "NPU ID", npu_all_info->card_info[0].card_id);
            printf("\t%-30s : %s\n", "Product Name", npu_all_info->card_info[0].product_name);
            printf("\t%-30s : %s\n", "Serial Number", npu_all_info->card_info[0].serial_number);
            printf("\t%-30s : %d\n\n", "Chip Count", npu_all_info->card_info[0].chip_count);
        } else {
            printf("There is no NPU card on this server.\n");
        }
        return;
    }

    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
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
        printf("\t%-30s : %d\n\n", "Chip Count", npu_all_info->card_info[i].chip_count);
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
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
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
    } else if (npu_get_chip_type() == NPU_CHIP_910B || (npu_get_chip_type() == NPU_CHIP_910_93)) { // 1980B、1980C无DDR
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
    if (usages_info->hbm_size_info_M.memory_size == 0) {
        return;
    }

    if (npu_get_chip_type() == NPU_CHIP_910B) {
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
        (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93)) {
        printf("\t%-30s : %u\n", "Aicube Usage Rate(%)", usages_info->aicube_usage);
    }
    return;
}

STATIC void print_aicore_usages_rate_info(struct npu_chip_usages_info *usages_info)
{
    /* 除910B产品，aicore的利用率底层返回为两个之和 */
    if ((usages_info->aicore_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) {
        printf("\t%-30s : %u\n", "Aicore Usage Rate(%)", usages_info->aicore_usage);
    }

    if (((usages_info->aivector_usage & (0x1 << DCMI_VF_FLAG_BIT)) == 0) &&
        (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93)) {
        printf("\t%-30s : %u\n", "Aivector Usage Rate(%)", usages_info->aivector_usage);
    }
    return;
}

void print_chip_usages_npu_utilization(struct npu_chip_usages_info *usages_info)
{
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : %u\n", "NPU Utilization(%)", usages_info->npu_utilization_usage);
    }
}

void print_chip_usages_info(struct npu_chip_usages_info *usages_info)
{
    bool support_chip_type = (npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
                              npu_get_chip_type() == NPU_CHIP_910_93);
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
    if (npu_get_chip_type() == NPU_CHIP_310P) {
        printf("\t%-30s : %u\n", "Vectorcore Usage Rate(%)", usages_info->vectorcore_usage);
    }
    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-30s : %u\n", "Memory Bandwidth Usage Rate(%)", usages_info->memory_bandwidth_usage);
    } else if (npu_get_chip_type() == NPU_CHIP_910B) {
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

    if (npu_get_chip_type() == NPU_CHIP_310P) {
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
    if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : %s\n", "NPU Name", chip_info->chip_info.npu_name);
    }
}

static void print_ascend_chip_info(struct npu_chip_info *chip_info, unsigned int module_id)
{
    size_t i, count;
    bool support_chip_type = (npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
                              npu_get_chip_type() == NPU_CHIP_910_93);
    printf("\t%-30s : %d\n", "NPU ID", chip_info->npu_id);
    print_ascend_910_93_npu_name(chip_info);
    printf("\t%-30s : %d\n", "Chip ID", chip_info->chip_id);
    if (npu_get_chip_type() != NPU_CHIP_910_93) {
        printf("\t%-30s : %s\n", "Chip Type", chip_info->chip_info.chip_type);
    }
    printf("\t%-30s : %s\n", "Chip Name", chip_info->chip_info.chip_name);
    printf("\t%-30s : %s\n", "Chip Version", chip_info->chip_info.chip_ver);
    printf("\t%-30s : 0x%02x\n", "Board ID", chip_info->board_info.board_id);
    print_ascend_310b_module_id(module_id);

    if (!(npu_get_chip_type() == NPU_CHIP_310P)) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
        printf("\t%-30s : %u\n", "BOM ID", chip_info->board_info.bom_id);
    }

    if (support_chip_type) {
        printf("\t%-30s :", "VDie ID");
    } else if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
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

    if ((npu_board_type_is_soc() == TRUE) && (npu_get_chip_type() == NPU_CHIP_310P)) {
        printf("\t%-30s : %s\n", "Firmware Version", chip_info->xloader_version);
    }

    /* 此处需要评估下此处在模组和SOC形态下打印是否存在异常 */
    if (npu_board_type_is_card() == TRUE || npu_board_type_is_server()) {
        printf("\t%-30s : %d\n", "Chip Position ID", chip_info->chip_pos_id);

        printf("\t%-30s : %04X:%02X:%02X.%X\n", "PCIe Bus Info", chip_info->device_pcie_info.domain,
            chip_info->device_pcie_info.bdf_busid, chip_info->device_pcie_info.bdf_deviceid,
            chip_info->device_pcie_info.bdf_funcid);
        printf("\t%-30s : %s\n", "Firmware Version", chip_info->xloader_version);
    }

    return;
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
    if (npu_get_chip_type() == NPU_CHIP_310 || npu_get_chip_type() == NPU_CHIP_310B) {
        if (npu_get_chip_type() == NPU_CHIP_310B) {
            printf("\t%-30s : %u\n", "Total Capacity(MB)", ddr_info);
        }
        printf("\t%-30s : %llu\n", "Capacity(MB)", memory_info->memory_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "Clock Speed(MHz)", memory_info->memory_frequency_mhz);
    } else if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : %u\n", "DDR Capacity(MB)", 0);
        printf("\t%-30s : %u\n", "DDR Clock Speed(MHz)", 0);
    } else {
        if (npu_get_chip_type() == NPU_CHIP_310P) {
            printf("\t%-30s : %u\n", "Total DDR Capacity(MB)", ddr_info);
        }
        printf("\t%-30s : %llu\n", "DDR Capacity(MB)", memory_info->memory_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "DDR Clock Speed(MHz)", memory_info->memory_frequency_mhz);
    }
    return;
}

void print_hbm_info(struct npu_memory_info *memory_info)
{
    if (npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
        npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : %llu\n", "HBM Capacity(MB)", memory_info->hbm_size_info_M.memory_size);
        printf("\t%-30s : %u\n", "HBM Clock Speed(MHz)", memory_info->hbm_frequency_mhz);
        printf("\t%-30s : %d\n", "HBM Temperature(C)", memory_info->hbm_size_info_M.temp);
        if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
            printf("\t%-30s : 0x%X\n", "HBM Manufacturer ID", memory_info->hbm_product_info.manufacturer_id);
        }
    }
    return;
}

void print_memory_info(int card_id, int device_id, struct npu_memory_info *memory_info)
{
    int ret;
    int device_logic_id = 0;
    unsigned int ddr_info = 0;
    unsigned int ddr_size = sizeof(ddr_info);

    ret = dcmi_get_device_logic_id(&device_logic_id, card_id, device_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_device_logic_id failed. err is %d.", ret);
        return;
    }

    if (!((npu_get_chip_type() == NPU_CHIP_910) || (npu_get_chip_type() == NPU_CHIP_910B) ||
        (npu_get_chip_type() == NPU_CHIP_910_93))) {
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
    if (npu_get_chip_type() == NPU_CHIP_910B && !(device_info->board_info.board_id)) {
        printf("\t%-30s : %s\n", "Board ID", "NA");
    } else {
        printf("\t%-30s : 0x%02x\n", "Board ID", device_info->board_info.board_id);
    }

    if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : 0x%02x\n", "Main Board ID", device_info->main_board_id);
    }

    if (device_info->board_info.pcb_id == 0) {
        printf("\t%-30s : %s\n", "PCB ID", "NA");
    } else {
        printf("\t%-30s : %c\n", "PCB ID", (char)('A' + (device_info->board_info.pcb_id - 1)));
    }
    if (npu_get_chip_type() == NPU_CHIP_910B && !(device_info->board_info.bom_id)) {
        printf("\t%-30s : %s\n", "BOM ID", "NA");
    } else {
        printf("\t%-30s : %u\n", "BOM ID", device_info->board_info.bom_id);
    }
}

void print_ascend_board_info(struct npu_device_info *device_info)
{
    printf("\t%-30s : %d\n", "NPU ID", device_info->npu_id);
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("\t%-30s : %s\n", "Product Name", device_info->product_name);
        printf("\t%-30s : %s\n", "Model", device_info->model);
        printf("\t%-30s : %s\n", "Manufacturer", "NA");
        printf("\t%-30s : %s\n", "Serial Number", device_info->serial_number);
    }
    printf("\t%-30s : %s\n", "Software Version", device_info->software_version);
    printf("\t%-30s : %s\n", "Firmware Version", device_info->firmware_version);

    print_chip_compatibility_info(device_info);
    print_card_board_info(device_info);

    printf("\t%-30s : %04X:%02X:%02X.%X\n", "PCIe Bus Info", device_info->device_pcie_info.domain,
        device_info->device_pcie_info.bdf_busid, device_info->device_pcie_info.bdf_deviceid,
        device_info->device_pcie_info.bdf_funcid);
    printf("\t%-30s : %d\n", "Slot ID", device_info->slot_id);
    printf("\t%-30s : %s\n", "Class ID", "NA");
    printf("\t%-30s : 0x%04X\n", "PCI Vendor ID", device_info->device_pcie_info.venderid);
    printf("\t%-30s : 0x%04X\n", "PCI Device ID", device_info->device_pcie_info.deviceid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Vendor ID", device_info->device_pcie_info.subvenderid);
    printf("\t%-30s : 0x%04X\n", "Subsystem Device ID", device_info->device_pcie_info.subdeviceid);
    printf("\t%-30s : %d\n", "Chip Count", device_info->chip_count);

    return;
}

void printf_npu_card_pcie_info(struct npu_device_info *device_info)
{
    bool support_chip_type = (npu_get_chip_type() == NPU_CHIP_310P || npu_get_chip_type() == NPU_CHIP_910 ||
        npu_get_chip_type() == NPU_CHIP_910B);
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
    printf("\t%-30s : %s\n", "Manufacturer", "NA");
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
    return npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
        npu_get_chip_type() == NPU_CHIP_310P || npu_get_chip_type() == NPU_CHIP_910_93;
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

void print_common_info(struct npu_card_common_info *card_common_info)
{
    int i;

    if (!(npu_board_type_is_station() || npu_board_type_is_hilens())) {
        if (card_common_info->chip_count < 1) {
            printf("There is no NPU chip on this card.\n");
            return;
        }
    }

    printf("\t%-30s : %d\n", "NPU ID", card_common_info->card_id);
    printf("\t%-30s : %d\n", "Chip Count", card_common_info->chip_count);
    for (i = 0; i < card_common_info->chip_count; i++) {
        if (npu_check_is_has_d_chip() == FALSE) {
            gplog(LOG_ERR, "npu chip not present.");
            break;
        }
        printf("\n\t%-30s : %d\n", "Chip ID", i);
        if (card_common_info->chip_common_info[i].memory_usage != NPU_DEFAULT_VALUE) {
            print_memory_usage_rate_info(card_common_info, i);
        }
        bool support_chip_type = (npu_get_chip_type() == NPU_CHIP_910 || npu_get_chip_type() == NPU_CHIP_910B ||
                                  npu_get_chip_type() == NPU_CHIP_910_93);
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
    print_mcu_common_info(card_common_info);
    print_cpu_common_info(card_common_info);
    return;
}

void print_chip_temperature_for_outband(int card_id, const char *data_info, int len)
{
    int ret;
    char tmp_data[TEMPERATURE_NAME_LEN + TEMPERATURE_NUM_LEN] = {0}; /* 临时存放温度名称 */
    int temp_index, temp_num, temp_get;
    int name_offset, value_offset;
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

void print_diagnosis_info(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info)
{
    int ret, i;
    unsigned int error_code = 0;
    char error_info[NPU_ERROR_STRING_MAX_LENGTH] = {0};
    enum dcmi_unit_type device_type = INVALID_TYPE;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return;
    }
    if (dcmi_check_vnpu_in_docker_or_virtual(operate_info->id) && device_type == MCU_TYPE) {
        printf("\t%-30s : %s\n", "Health Status", "NA");
    } else {
        printf("\t%-30s : %s\n", "Health Status", health_info->health_state);
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
        ret = dcmi_get_device_errorcode_string(operate_info->id, operate_info->chip_id, error_code,
            (unsigned char *)error_info, NPU_ERROR_STRING_MAX_LENGTH);
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

void print_npu_topo_info_total(struct topo_info *topo_operate_info)
{
    int i;
    printf("\t   ");
    for (i = 0; i < topo_operate_info->device_count; i++) {
        if (npu_get_chip_type() == NPU_CHIP_910_93) {
            printf("Phy-ID%-5d", topo_operate_info->device_id_list[i]);
        } else {
            printf("NPU%-8d", topo_operate_info->device_id_list[i]);
        }
    }
    // 910_93 A+K的npu通过L1交换板链接到cpu，npu和cpu内存numa节点不存在唯一的亲和性
    if (npu_get_chip_type() == NPU_CHIP_910_93 && dcmi_is_arm()) {
        printf("\n");
    } else {
        printf("CPU Affinity\n");
    }
}

void print_npu_topo_type_legend()
{
    printf("Legend:\n");
    printf("\n");
    printf("  X    = Self\n");
    printf("  SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.\n");
    printf("  PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.\n");
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("  PIX  = Path traversing a single PCIe switch\n");
        printf("  PXB  = Path traversing multipul PCIe switches\n");
    }
    printf("  XLink = Connection traversing XLink.\n");
    if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("  SIO  = Path traversing the SIO bus\n");
        printf("  XLink_SW = Connection traversing XLink through a switch\n");
    }
    printf("  NA   = Unknown relationship.\n");
}

/* 打印npu-hccs 链接拓扑结构 */
void print_npu_hccs_topo(struct npu_smi_operate_info *operate_info)
{
    int ret, hccs_lane_index;
    int hccs_lane_id = operate_info->lane_id;
    int chip_phy_id = 2 * operate_info->id + operate_info->chip_id; // 910A3为双die场景，MCU场景前序已判断
    unsigned int main_board_id;

    ret = dcmi_get_mainboard_id(operate_info->id, 0, &main_board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Card-%d Failed to query main board id of card. err is %d.", operate_info->id, ret);
        return;
    }

    if ((main_board_id == Atlas_900_A3_SuperPoD_MAIN_BOARD_ID1 ||
        main_board_id == Atlas_900_A3_SuperPoD_MAIN_BOARD_ID2) && (chip_phy_id < HCCS_900_ARR_ROW_MAX)) {
        printf("%-20s %-20s %-20s\n", "NPU_PORT", "XLink_REMOTE_CHIP", "XLink_REMOTE_PORT");
        if (hccs_lane_id == -1) {
            for (hccs_lane_index = HCCS_900_ARR_COL_MIN; hccs_lane_index <
                HCCS_900_ARR_COL_MAX; hccs_lane_index++) {
                printf("M%-20d %-20d M%-20d\n", hccs_lane_index, g_hccs_topo_900[0][chip_phy_id][hccs_lane_index],
                    g_hccs_topo_900[1][chip_phy_id][hccs_lane_index]);
            }
        } else {
            printf("M%-20d %-20d M%-20d\n", hccs_lane_id, g_hccs_topo_900[0][chip_phy_id][hccs_lane_id],
                g_hccs_topo_900[1][chip_phy_id][hccs_lane_id]);
        }
    } else if ((main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1 ||
        main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2) && (chip_phy_id < HCCS_9000_ARR_ROW_MAX)) {
        printf("%-20s %-20s %-20s\n", "NPU_PORT", "XLink_REMOTE_CHIP", "XLink_REMOTE_PORT");
        if (hccs_lane_id == -1) {
            for (hccs_lane_index = HCCS_9000_ARR_COL_MIN; hccs_lane_index <
                HCCS_9000_ARR_COL_MAX; hccs_lane_index++) {
                printf("M%-20d %-20d M%-20d\n", hccs_lane_index, g_hccs_topo_9000[0][chip_phy_id][hccs_lane_index],
                    g_hccs_topo_9000[1][chip_phy_id][hccs_lane_index]);
            }
        } else {
            printf("M%-20d %-20d M%-20d\n", hccs_lane_id, g_hccs_topo_9000[0][chip_phy_id][hccs_lane_id],
                g_hccs_topo_9000[1][chip_phy_id][hccs_lane_id]);
        }
    } else {
        gplog(LOG_ERR, "This env is not support for hccs info query");
        printf("This device dose not support querying xlink topo.\n");
    }
}

void print_npu_topo_info(struct topo_info *topo_operate_info)
{
    int row;
    int col;
    int topo_type_index = 0;
    char topo_type_info_legend[TOPO_TYPE_MAX][TOPO_INFO_MAX_LENTH] = {
        "X", "SYS", "PHB", "XLink", "PXB", "PIX", "SIO", "XLink_SW", "NA",
    };
    print_npu_topo_info_total(topo_operate_info);
    for (row = 0; row < topo_operate_info->device_count; row++) {
        if (npu_get_chip_type() == NPU_CHIP_910_93) {
            printf("Phy-ID%-5d", topo_operate_info->device_id_list[row]);
        } else {
            printf("NPU%-8d", topo_operate_info->device_id_list[row]);
        }
        for (col = 0; col < topo_operate_info->device_count; col++) {
            topo_type_index = topo_operate_info->topo_type_matrix[row][col];
            printf("%-11s", topo_type_info_legend[topo_type_index]);
        }
        // 910_93 A+K的npu通过L1交换板链接到cpu，npu和cpu内存numa节点不存在唯一的亲和性
        if (npu_get_chip_type() == NPU_CHIP_910_93 && dcmi_is_arm()) {
            printf("\n");
        } else {
            printf("%s\n", topo_operate_info->affinity_cpu_info[row]);
        }
    }

    printf("\n");
    print_npu_topo_type_legend();
}

// 将pcs_lane_bitmap与hccs_port_pcs_bitmap从低位开始各bit位对应
void full_lane_info(struct dcmi_hccs_lane_info *lane_info_in, struct dcmi_hccs_lane_info *lane_info_out)
{
    int i, not_hccs_cnt = 0;
    lane_info_out->hccs_port_pcs_bitmap = lane_info_in->hccs_port_pcs_bitmap;
    for (i = 0; i < DCMI_HCCS_MAX_PCS_NUM; i++) {
        if (((lane_info_out->hccs_port_pcs_bitmap >> i) & 0x1) == 1) { // 做位移后取末位，表示获取第N位的二进制值
            lane_info_out->pcs_lane_bitmap[i] = lane_info_in->pcs_lane_bitmap[i - not_hccs_cnt];
        } else {
            lane_info_out->pcs_lane_bitmap[i] = 0;
            not_hccs_cnt++;
        }
    }
}

void print_npu_single_hccs_lane(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int id, int env_offset)
{
    int i;
    unsigned int lane_mode = 0;
    unsigned int link_lane = 0;
    unsigned long long tx_packets = 0;
    unsigned long long rx_packets = 0;
    unsigned int first_error_lane = 0;
    struct dcmi_hccs_lane_info lane_info_new;

    full_lane_info(lane_info, &lane_info_new);
    /* lane_info->pcs_lane_bitmap 当前用于hccs连接的lane信息数组,数组顺序与hccs_port_pcs_bitmap从低位开始写‘1’的bit位对应
       lane_info_new.pcs_lane_bitmap 数组顺序与hccs_port_pcs_bitmap从低位开始各bit位对应
    */

    if (npu_get_chip_type() != NPU_CHIP_310P) {
        if (hccs_status->pcs_status == 0 && hccs_status->hdlc_status == DCMI_HDLC_STATUS_OK) {
            printf("\t%-30s : %s\n", "xlink health status ", "OK");
        } else {
            printf("\t%-30s : %s\n", "xlink health status ", "NOK");
        }
        lane_mode = (lane_info_new.pcs_lane_bitmap[id] >> LANE_MODE_OFFSET) & 0x3;
        lane_mode = (lane_mode == 0x2) ? 4 : lane_mode; // 10为4 lane
        lane_mode = (lane_mode == 0x3) ? 2 : lane_mode; // 11为2 lane
        printf("\t%-30s : [%-20u]\n", "xlink lane mode ", lane_mode);

        printf("\t%-30s : [", "xlink link lane list ");
        link_lane = (lane_info_new.pcs_lane_bitmap[id] >> LINK_LANE_OFFSET) & 0xFF;
        for (i = 0; i < LANE_MODE_BIT_NUM; i++) {
            printf("%u", link_lane & 0x1);
            link_lane >>= 1;
        }
        printf("%16s]\n", "");

        printf("\t%-30s : [%-20u]\n", "xlink link speed ", lane_mode * HCCS_LANE_SPEED);
    }

    tx_packets = statistic_info->tx_cnt[id];
    printf("\t%-30s : [%-20llu]\n", "xlink tx packets ", tx_packets);
    printf("\t%-30s : [%-20llu]\n", "xlink tx bytes ", tx_packets * SINGLE_PACKETS_BYTES);

    rx_packets = statistic_info->rx_cnt[id];
    printf("\t%-30s : [%-20llu]\n", "xlink rx packets ", rx_packets);
    printf("\t%-30s : [%-20llu]\n", "xlink rx bytes ", rx_packets * SINGLE_PACKETS_BYTES);

    printf("\t%-30s : [%-20llu]\n", "xlink retry count ", statistic_info->retry_cnt[id]);
    printf("\t%-30s : [%-20llu]\n", "xlink error count ", statistic_info->crc_err_cnt[id]);

    if (npu_get_chip_type() != NPU_CHIP_310P) {
        if (hccs_status->pcs_status == 0) {
            printf("\t%-30s : %s\n", "xlink first error lane ", "NA");
        } else {
            first_error_lane = (hccs_status->pcs_status >> FIRST_ERROR_LANE) & 0xFF;
            printf("\t%-30s : %u\n", "xlink first error lane ", first_error_lane);
        }
    }
}

void print_npu_hccs_lane_error_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset)
{
    int index = 0;
    unsigned long long error_rate = 0;
    unsigned int first_error_lane = 0;

    printf("\t%-30s : [", "xlink error count ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        error_rate = statistic_info->crc_err_cnt[index];
        printf("%-20llu ", error_rate);
    }
    printf("]\n");
    /*  pcs_status 不同bit位定义如下:
        0bit在状态异常下固定为1；
        1-7bit当前固定为0，预留扩展。
        8-15bit表示当前存在问题的PCS序号，当前序号的范围为0-7，此值表示从0开始第1个有问题的索引号；
        16-23bit表示PCS当前发送的lane模式，0表示0lane，1表示1lane，2表示4lane，3表示8lane;
        24-31bit表示PCS当前发送的lane。
    */
    if (hccs_status->pcs_status == 0) {
        printf("\t%-30s : %s\n", "xlink first error lane ", "NA");
    } else {
        // first error lane 为8-15bit
        first_error_lane = (hccs_status->pcs_status >> FIRST_ERROR_LANE) & 0xFF;
        printf("\t%-30s : %u\n", "xlink first error lane ", first_error_lane);
    }
}

void print_npu_310P_hccs_lane_error_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int index = 0;
    unsigned long long error_rate = 0;

    printf("\t%-30s : [", "xlink error count ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        error_rate = statistic_info->crc_err_cnt[index];
        printf("%-20llu ", error_rate);
    }
    printf("]\n");
}

void print_npu_hccs_lane_retry_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset)
{
    int index;
    unsigned long long retry_cnt;

    printf("\t%-30s : [", "xlink retry count ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        retry_cnt = statistic_info->retry_cnt[index];
        printf("%-20llu ", retry_cnt);
    }
    printf("]\n");
}

void print_npu_310P_hccs_lane_retry_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int index;
    unsigned long long retry_cnt;

    printf("\t%-30s : [", "xlink retry count ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        retry_cnt = statistic_info->retry_cnt[index];
        printf("%-20llu ", retry_cnt);
    }
    printf("]\n");
}

void print_npu_hccs_lane_packet_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset)
{
    int index = 0;
    unsigned long long tx_packets = 0;
    unsigned long long rx_packets = 0;

    printf("\t%-30s : [", "xlink tx packets ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink tx bytes ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink rx packets ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink rx bytes ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    print_npu_hccs_lane_retry_info(hccs_status, lane_info, statistic_info, env_offset);
    print_npu_hccs_lane_error_info(hccs_status, lane_info, statistic_info, env_offset);
}

void print_npu_310P_hccs_lane_packet_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int index = 0;
    unsigned long long tx_packets = 0;
    unsigned long long rx_packets = 0;

    printf("\t%-30s : [", "xlink tx packets ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink tx bytes ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink rx packets ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "xlink rx bytes ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    print_npu_310P_hccs_lane_retry_info(hccs_status, lane_info, statistic_info);
    print_npu_310P_hccs_lane_error_info(hccs_status, lane_info, statistic_info);
}

int print_ascend_chip_hccs_lane_info(struct npu_smi_operate_info *operate_info, struct dcmi_hccs_statues *hccs_status,
    struct dcmi_hccs_lane_info *lane_info, struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int env_offset = TEMP_VALUE_INVALID;
    if (npu_get_chip_type() != NPU_CHIP_310P) {
        env_offset = get_env_offset_info(operate_info);
        if (env_offset < 0) {
            return env_offset;
        }
    }
    if (operate_info->is_hccs_topo) {
        print_npu_hccs_topo(operate_info);
        return NPU_OK;
    }
    if (operate_info->lane_id == -1) {
        if (npu_get_chip_type() == NPU_CHIP_310P) {
            print_npu_310P_hccs_lane_packet_info(hccs_status, lane_info, statistic_info);
            return NPU_OK;
        } else {
            print_npu_hccs_lane(hccs_status, lane_info, statistic_info, env_offset);
            return NPU_OK;
        }
    }
    print_npu_single_hccs_lane(hccs_status, lane_info, statistic_info, operate_info->lane_id, env_offset);
    return NPU_OK;
}

void print_npu_hccs_lane(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset)
{
    int i = 0;
    int index = 0;
    unsigned int lane_mode = 0, link_lane = 0;
    struct dcmi_hccs_lane_info lane_info_new = {0};

    full_lane_info(lane_info, &lane_info_new);
    /* lane_info->pcs_lane_bitmap 当前用于hccs连接的lane信息数组,数组顺序与hccs_port_pcs_bitmap从低位开始写‘1’的bit位对应
       lane_info_new->pcs_lane_bitmap 数组顺序与hccs_port_pcs_bitmap从低位开始各bit位对应
    */

    if (hccs_status->pcs_status == 0 && hccs_status->hdlc_status == DCMI_HDLC_STATUS_OK) {
        printf("\t%-30s : %s\n", "xlink health status ", "OK");
    } else {
        printf("\t%-30s : %s\n", "xlink health status ", "NOK");
    }
    /*  pcs_lane_bitmap 不同bit位定义如下:
        0bit:是否切换到hccs完成,1完成,0则其余bit位的值均无效；
        1-8bit:当前hccs连接用的lane序号,从低位开始计数范围0-3,值为1表示该lane为当前发送使用,值为0表示未被使用;
        9-10bit:当前hccs连接用的lane模式,00为0 lane,01为1 lane,10为4 lane,11为2 lane.
    */

    printf("\t%-30s : [", "xlink lane mode ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        // lane mode为9-10bit
        lane_mode = (lane_info_new.pcs_lane_bitmap[index] >> LANE_MODE_OFFSET) & 0x3;
        lane_mode = (lane_mode == 0x2) ? 4 : lane_mode; // 10为4 lane
        lane_mode = (lane_mode == 0x3) ? 2 : lane_mode; // 11为2 lane
        printf("%-20u ", lane_mode);
    }
    printf("]\n");

    printf("\t%-30s : [", "xlink link lane list ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        // lane list 为1-8bit
        link_lane = (lane_info_new.pcs_lane_bitmap[index] >> LINK_LANE_OFFSET) & 0xFF;
        for (i = 0; i < LANE_MODE_BIT_NUM; i++) {
            printf("%u", link_lane & 0x1);
            link_lane >>= 1;
        }
        printf("%16s ", "");
    }
    printf("]\n");

    /* hccs link speed 其大小为：56Gpbs * lane mode */
    printf("\t%-30s : [", "xlink link speed ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        lane_mode = (lane_info_new.pcs_lane_bitmap[index] >> LANE_MODE_OFFSET) & 0x3;
        lane_mode = (lane_mode == 0x2) ? 4 : lane_mode; // 10为4 lane
        lane_mode = (lane_mode == 0x3) ? 2 : lane_mode; // 11为2 lane
        printf("%-20u ", (lane_mode * HCCS_LANE_SPEED));
    }
    printf("]\n");
    print_npu_hccs_lane_packet_info(hccs_status, lane_info, statistic_info, env_offset);
}

void print_npu_sio_info(struct dcmi_sio_crc_err_statistics_info *sio_info)
{
    printf("\t%-s : %u\n", "TX Error Count", sio_info->tx_error_count);
    printf("\t%-s : %u\n", "RX Error Count", sio_info->rx_error_count);
}

void printf_hccs_bandwidth_info(struct dcmi_hccs_bandwidth_info *hccs_bandwidth_info, int env_offset)
{
    int index;
    printf("%-30s %-30s %-30s\n", "xlink link", "tx_bandwidth(GB/S)", "rx_bandwidth(GB/S)");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM && index >= 0; index++) {
        printf("%-35d %-30.6f %-30.6f\n", index, hccs_bandwidth_info->tx_bandwidth[index],
            hccs_bandwidth_info->rx_bandwidth[index]);
    }
    printf("%-35s %-30.6f %-30.6f\n", "total", hccs_bandwidth_info->total_txbw,
        hccs_bandwidth_info->total_rxbw);
}

void printf_hccs_avail_credit_info(int card_id, struct dcmi_hccs_credit_info *hccs_credit_info)
{
    int index, ret;
    unsigned int main_board_id;

    ret = dcmi_get_mainboard_id(card_id, 0, &main_board_id);
    if (ret != DCMI_OK) {
        printf("Failed to query main board id of card.\n");
        gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
        return;
    }

    if (main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1 ||
        main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2) {
        for (index = DCMI_HCCS_910_93_MACRO_OFFSET2;
             index < DCMI_HCCS_910_93_MACRO_NUM2 + DCMI_HCCS_910_93_MACRO_OFFSET2; index++) {
        printf("\t%-s%d%-5s: %u\n", "XLink Avail Credit Count M", index, "", hccs_credit_info->credit_num[index]);
        }
    } else {
        for (index = DCMI_HCCS_910_93_MACRO_OFFSET1;
             index < DCMI_HCCS_910_93_MACRO_NUM1 + DCMI_HCCS_910_93_MACRO_OFFSET1; index++) {
            printf("\t%-s%d%-5s: %u\n", "XLink Avail Credit Count M", index, "", hccs_credit_info->credit_num[index]);
        }
    }
}
void printf_syslog_dump_info(int type, int persistence_enable, int gear, char *syslog_path,
                             int *card_msn_existed, int path_len, int card_num)
{
    int index;

    if (type == DCMI_ERR_CODE_CONFIG_INFO_NOT_EXIST) {
        printf("\t%-40s: %s\n", "Current syslog dump config recover mode", "disable");

        printf("\t%-40s: %s\n", "Current syslog dump config gear", "NA");
        printf("\t%-40s: %s\n", "Current syslog dump config path", "NA");
    } else {
        printf("\t%-40s: %s\n", "Current syslog dump config recover mode",
            (persistence_enable == 0) ? "disable" : "enable");
        if (syslog_path[0] == '\0') {
            printf("\t%-40s: %s\n", "Current syslog dump config gear", "NA");
            printf("\t%-40s: %s\n", "Current syslog dump config path", "NA");
        } else {
            printf("\t%-40s: %d\n", "Current syslog dump config gear", gear);
            printf("\t%-40s: %s\n", "Current syslog dump config path", syslog_path);
        }
    }
    for (index = 0; index < MAX_CARD_NUM; index++) {
        if (card_msn_existed[index] != -1) {
            printf("\t%-s %d %s\n", "NPU", card_msn_existed[index], "syslog collecting process is existed");
        }
    }
}

void print_op_timeout_info(struct ts_dcmi_ctrl_msg_body_t *op_timeout_info)
{
    if (op_timeout_info == NULL) {
        gplog(LOG_ERR, "print_op_timeout_info failed.");
        return;
    }
    const unsigned int timeout_limit_exp = op_timeout_info->u.get_task_timeout_info.timeout_limit_exp;
    const unsigned int timeout_time = (unsigned int)round(pow(2, timeout_limit_exp) / ONE_GHZ * CONVERSION_MS);

    // 超时时间(单位：毫秒) = 2^timeout_limit_exp / stars频率 * 1000，stars频率默认1GHZ（1000,000,000）
    printf("\t%-18s : %u\n", "Timeout Exponent", timeout_limit_exp);
    printf("\t%-18s : %ums\n", "Timeout Duration", timeout_time);
}
#endif
