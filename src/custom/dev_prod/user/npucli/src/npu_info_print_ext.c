/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

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
#include "dcmi_mcu_intf.h"
#include "npu_card_info.h"
#include "npu_chip_info.h"
#include "npu_info_print.h"

#ifndef ORIENT_CH

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

// 用于判断A5标卡的P数，非A5标卡时返回0
int card_950_type_judge(unsigned int mainboard_id)
{
    switch (mainboard_id) {
        case DCMI_950_1P_MAINBOARD_ID:
            return DCMI_950_1P_CARD_DEVICE_COUNT;
        case DCMI_950_2P_MAINBOARD_ID:
            return DCMI_950_2P_CARD_DEVICE_COUNT;
        case DCMI_950_4P_MAINBOARD_ID:
            return DCMI_950_4P_CARD_DEVICE_COUNT;
        default:
            return 0x0;
    }
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
        printf("%-20s %-20s %-20s\n", "NPU_PORT", "HCCS_REMOTE_CHIP", "HCCS_REMOTE_PORT");
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
        printf("%-20s %-20s %-20s\n", "NPU_PORT", "HCCS_REMOTE_CHIP", "HCCS_REMOTE_PORT");
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
        printf("This device dose not support querying hccs topo.\n");
    }
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
    
    // 添加 NIC 列标题
    for (i = 0; i < NIC_PORT_NUM; i++) {
        printf("NIC%-9d", i);
    }

    // 910_93 A+K的npu通过L1交换板链接到cpu，npu和cpu内存numa节点不存在唯一的亲和性; A5 SuperPod 也不存在亲和性
    if ((dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id) || npu_get_chip_type() == NPU_CHIP_910_93) &&
        dcmi_is_arm()) {
        printf("\n");
    } else {
        printf("CPU Affinity\n");
    }
}

void print_npu_topo_type_legend()
{
    printf("Legend:\n\n");
    printf("  X    = Self\n");
    printf("  SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.\n");
    printf("  PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.\n");
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93 ||
        npu_get_chip_type() == NPU_CHIP_950) {
        printf("  PIX  = Path traversing a single PCIe switch.\n");
        printf("  PXB  = Path traversing multiple PCIe switches.\n");
    }
    if (!(npu_get_chip_type() == NPU_CHIP_950)) {
        printf("  HCCS = Connection traversing HCCS.\n");
    }
    if (npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("  SIO  = Path traversing the SIO bus.\n");
        printf("  HCCS_SW = Connection traversing HCCS through a switch.\n");
    }
    if (npu_get_chip_type() == NPU_CHIP_950) {
        printf("  SIO  = Path traversing the SIO bus.\n");
        printf("  UB   = Connection traversing UB.\n");
    }
    printf("  NA   = Unknown relationship.\n");
}

void print_npu_nic_topo_info(struct topo_info *topo_operate_info,
                             char topo_type_info_legend[TOPO_TYPE_MAX][TOPO_INFO_MAX_LENTH])
{
    int col, topo_type_index = 0;
    // 打印 NIC 行
    for (int nic_idx = 0; nic_idx < NIC_PORT_NUM; nic_idx++) {
        printf("NIC%-8d", nic_idx);
        // 打印 NIC 与所有 NPU 的拓扑关系
        for (col = 0; col < topo_operate_info->device_count; col++) {
            topo_type_index = topo_operate_info->nic_topo_matrix[nic_idx][col];
            printf("%-11s", topo_type_info_legend[topo_type_index]);
        }
        // 打印 NIC 列（自身为 X）
        for (int i = 0; i < NIC_PORT_NUM; i++) {
            if (i == nic_idx) {
                printf("%-11s", "X");
            } else {
                printf("%-11s", topo_type_info_legend[TOPO_TYPE_BUTT]);
            }
        }
        printf("\n");
    }

    // 打印网卡名称信息
    printf("\n");
    for (int nic_idx = 0; nic_idx < NIC_PORT_NUM; nic_idx++) {
        printf("NIC%d: %s\n", nic_idx, topo_operate_info->nic_name_list[nic_idx]);
    }
}

void print_npu_topo_info(struct topo_info *topo_operate_info)
{
    int row, col, topo_type_index = 0;
    char topo_type_info_legend[TOPO_TYPE_MAX][TOPO_INFO_MAX_LENTH] = {
        "X", "SYS", "PHB", "HCCS", "PXB", "PIX", "SIO", "HCCS_SW", "UB", "NA",
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

        // 打印 NIC 列数据
        for (int nic_idx = 0; nic_idx < NIC_PORT_NUM; nic_idx++) {
            topo_type_index = topo_operate_info->nic_topo_matrix[nic_idx][row];
            printf("%-11s", topo_type_info_legend[topo_type_index]);
        }

        // 910_93 A+K的npu通过L1交换板链接到cpu，npu和cpu内存numa节点不存在唯一的亲和性; A5 SuperPod也不存在亲和性
        if (((dcmi_get_board_chip_type() == DCMI_CHIP_TYPE_D950 &&
            dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) || npu_get_chip_type() == NPU_CHIP_910_93) &&
            dcmi_is_arm()) {
            printf("\n");
        } else {
            printf("%s\n", topo_operate_info->affinity_cpu_info[row]);
        }
    }

    print_npu_nic_topo_info(topo_operate_info, topo_type_info_legend);

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
    unsigned int lane_mode = 0, link_lane = 0;
    unsigned long long tx_packets = 0, rx_packets = 0;
    unsigned int first_error_lane = 0;
    struct dcmi_hccs_lane_info lane_info_new;

    full_lane_info(lane_info, &lane_info_new);
    /* lane_info->pcs_lane_bitmap 当前用于hccs连接的lane信息数组,数组顺序与hccs_port_pcs_bitmap从低位开始写‘1’的bit位对应
       lane_info_new.pcs_lane_bitmap 数组顺序与hccs_port_pcs_bitmap从低位开始各bit位对应
    */

    if (npu_get_chip_type() != NPU_CHIP_310P) {
        if (hccs_status->pcs_status == 0 && hccs_status->hdlc_status == DCMI_HDLC_STATUS_OK) {
            printf("\t%-30s : %s\n", "hccs health status ", "OK");
        } else {
            printf("\t%-30s : %s\n", "hccs health status ", "NOK");
        }
        lane_mode = (lane_info_new.pcs_lane_bitmap[id] >> LANE_MODE_OFFSET) & 0x3;
        lane_mode = (lane_mode == 0x2) ? 4 : lane_mode; // 10为4 lane
        lane_mode = (lane_mode == 0x3) ? 2 : lane_mode; // 11为2 lane
        printf("\t%-30s : [%-20u]\n", "hccs lane mode ", lane_mode);

        printf("\t%-30s : [", "hccs link lane list ");
        link_lane = (lane_info_new.pcs_lane_bitmap[id] >> LINK_LANE_OFFSET) & 0xFF;
        for (i = 0; i < LANE_MODE_BIT_NUM; i++) {
            printf("%u", link_lane & 0x1);
            link_lane >>= 1;
        }
        printf("%16s]\n", "");

        printf("\t%-30s : [%-20u]\n", "hccs link speed ", lane_mode * HCCS_LANE_SPEED);
    }

    tx_packets = statistic_info->tx_cnt[id];
    printf("\t%-30s : [%-20llu]\n", "hccs tx packets ", tx_packets);
    printf("\t%-30s : [%-20llu]\n", "hccs tx bytes ", tx_packets * SINGLE_PACKETS_BYTES);

    rx_packets = statistic_info->rx_cnt[id];
    printf("\t%-30s : [%-20llu]\n", "hccs rx packets ", rx_packets);
    printf("\t%-30s : [%-20llu]\n", "hccs rx bytes ", rx_packets * SINGLE_PACKETS_BYTES);

    printf("\t%-30s : [%-20llu]\n", "hccs retry count ", statistic_info->retry_cnt[id]);
    printf("\t%-30s : [%-20llu]\n", "hccs error count ", statistic_info->crc_err_cnt[id]);

    if (npu_get_chip_type() != NPU_CHIP_310P) {
        if (hccs_status->pcs_status == 0) {
            printf("\t%-30s : %s\n", "hccs first error lane ", "NA");
        } else {
            first_error_lane = (hccs_status->pcs_status >> FIRST_ERROR_LANE) & 0xFF;
            printf("\t%-30s : %u\n", "hccs first error lane ", first_error_lane);
        }
    }
}

void print_npu_hccs_lane_error_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset)
{
    int index = 0;
    unsigned long long error_rate = 0;
    unsigned int first_error_lane = 0;

    printf("\t%-30s : [", "hccs error count ");
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
        printf("\t%-30s : %s\n", "hccs first error lane ", "NA");
    } else {
        // first error lane 为8-15bit
        first_error_lane = (hccs_status->pcs_status >> FIRST_ERROR_LANE) & 0xFF;
        printf("\t%-30s : %u\n", "hccs first error lane ", first_error_lane);
    }
}

void print_npu_310P_hccs_lane_error_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int index = 0;
    unsigned long long error_rate = 0;

    printf("\t%-30s : [", "hccs error count ");
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

    printf("\t%-30s : [", "hccs retry count ");
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

    printf("\t%-30s : [", "hccs retry count ");
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

    printf("\t%-30s : [", "hccs tx packets ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs tx bytes ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs rx packets ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs rx bytes ");
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

    printf("\t%-30s : [", "hccs tx packets ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs tx bytes ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        tx_packets = statistic_info->tx_cnt[index];
        printf("%-20llu ", tx_packets * SINGLE_PACKETS_BYTES);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs rx packets ");
    for (index = 0; index <= DCMI_HCCS_310P_PCS_NUM; index++) {
        rx_packets = statistic_info->rx_cnt[index];
        printf("%-20llu ", rx_packets);
    }
    printf("]\n");
    printf("\t%-30s : [", "hccs rx bytes ");
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
        printf("\t%-30s : %s\n", "hccs health status ", "OK");
    } else {
        printf("\t%-30s : %s\n", "hccs health status ", "NOK");
    }
    /*  pcs_lane_bitmap 不同bit位定义如下:
        0bit:是否切换到hccs完成,1完成,0则其余bit位的值均无效；
        1-8bit:当前hccs连接用的lane序号,从低位开始计数范围0-3,值为1表示该lane为当前发送使用,值为0表示未被使用;
        9-10bit:当前hccs连接用的lane模式,00为0 lane,01为1 lane,10为4 lane,11为2 lane.
    */

    printf("\t%-30s : [", "hccs lane mode ");
    for (index = env_offset; index <= DCMI_HCCS_910B_PCS_NUM; index++) {
        // lane mode为9-10bit
        lane_mode = (lane_info_new.pcs_lane_bitmap[index] >> LANE_MODE_OFFSET) & 0x3;
        lane_mode = (lane_mode == 0x2) ? 4 : lane_mode; // 10为4 lane
        lane_mode = (lane_mode == 0x3) ? 2 : lane_mode; // 11为2 lane
        printf("%-20u ", lane_mode);
    }
    printf("]\n");

    printf("\t%-30s : [", "hccs link lane list ");
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
    printf("\t%-30s : [", "hccs link speed ");
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
    printf("%-30s %-30s %-30s\n", "hccs link", "tx_bandwidth(GB/S)", "rx_bandwidth(GB/S)");
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
        printf("\t%-s%d%-5s: %u\n", "HCCS Avail Credit Count M", index, "", hccs_credit_info->credit_num[index]);
        }
    } else {
        for (index = DCMI_HCCS_910_93_MACRO_OFFSET1;
             index < DCMI_HCCS_910_93_MACRO_NUM1 + DCMI_HCCS_910_93_MACRO_OFFSET1; index++) {
            printf("\t%-s%d%-5s: %u\n", "HCCS Avail Credit Count M", index, "", hccs_credit_info->credit_num[index]);
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

static void print_error_codes(const struct npu_device_health_info *health_info)
{
    int i;
    printf("\t%-30s :", "Error Code");
    for (i = 0; i < health_info->error_code_count; i++) {
        printf(" %04X", health_info->error_code[i]);
    }
    printf("\n");
}

void print_health_status(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info,
    enum dcmi_unit_type device_type)
{
    if (dcmi_check_vnpu_in_docker_or_virtual(operate_info->id) && device_type == MCU_TYPE) {
        printf("\t%-30s : %s\n", "Health Status", "NA");
    } else {
        printf("\t%-30s : %s\n", "Health Status", health_info->health_state);
    }
}

typedef int (*get_err_str_fn)(int devid, unsigned int errcode,
                              unsigned char *buf, int len);

static int get_err_str_v2_adapter(int dev_id, unsigned int error_code,
                                  unsigned char *err_info, int buf_size)
{
    return dcmiv2_get_device_error_info(dev_id, error_code, err_info, buf_size);
}

static int get_err_str_ao_adapter(int dev_id, unsigned int error_code,
                                  unsigned char *err_info, int buf_size)
{
    return dcmi_mcu_get_device_errorcode_string(dev_id, (int)error_code, err_info, buf_size);
}

static void print_error_info(unsigned int dev_id,
                             unsigned int error_code,
                             get_err_str_fn get_fn,
                             int *is_first)
{
    int ret;
    char error_info[NPU_ERROR_STRING_MAX_LENGTH];

    ret = memset_s(error_info, sizeof(error_info), 0, sizeof(error_info));
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "memset_s failed. ret is %d.", ret);
    }

    ret = get_fn(dev_id, error_code, (unsigned char *)error_info, NPU_ERROR_STRING_MAX_LENGTH);
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        if (*is_first) {
            printf(" %04X\n", error_code);
            *is_first = 0;
        } else {
            printf("\n\t%-30s : %04X\n", " ", error_code);
        }
        return;
    }

    if (ret != DCMI_OK) {
        printf("Failed to get error information for error code : 0x%04x\n", error_code);
        return;
    }

    if (*is_first) {
        printf(" %s\n", error_info);
        *is_first = 0;
    } else {
        printf("\n\t%-30s : %s\n", " ", error_info);
    }
}

static void print_npu_err_info(struct npu_smi_operate_info *operate_info,
                               struct npu_device_health_info *health_info,
                               int start, int end)
{
    int first = 1;
    int i;

    if (start >= end) {
        return;
    }

    for (i = start; i < end; ++i) {
        unsigned int error_code = (unsigned int)health_info->error_code[i];
        print_error_info(operate_info->id, error_code,
                         get_err_str_v2_adapter,
                         &first);
    }
}

static void print_ao_error_info(struct npu_smi_operate_info *operate_info,
                                struct npu_device_health_info *health_info,
                                unsigned int *ao_err_code_list, int ao_err_code_count)
{
    int i;
    int first;

    if (!ao_err_code_list) {
        gplog(LOG_ERR, "ao_err_code_list is NULL.");
        return;
    }

    first = (health_info->error_code_count == ao_err_code_count) ? 1 : 0;

    for (i = 0; i < ao_err_code_count; i++) {
        unsigned int error_code = ao_err_code_list[i];
        print_error_info(operate_info->id, error_code,
                         get_err_str_ao_adapter,
                         &first);
    }
}

void print_diagnosis_info_ao(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info,
    unsigned int *ao_err_code_list, unsigned int ao_err_code_count)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    if (ao_err_code_count > health_info->error_code_count) {
        return;
    }
    int npu_err_end = health_info->error_code_count - ao_err_code_count;

    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return;
    }
    print_health_status(operate_info, health_info, device_type);

    /* 当无错误码时，直接返回 */
    if (health_info->error_code_count <= 0) {
        printf("\t%-30s : %s\n", "Error Code", "NA");
        printf("\t%-30s : %s\n", "Error Information", "NA");
        return;
    }

    print_error_codes(health_info);

    printf("\t%-30s :", "Error Information");

    npu_err_end = (npu_err_end < 0) ? 0 : npu_err_end;

    print_npu_err_info(operate_info, health_info, 0, npu_err_end);
    print_ao_error_info(operate_info, health_info, ao_err_code_list, ao_err_code_count);

    return;
}