/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
 
#ifndef __DCMI_INIT_BASIC_H__
#define __DCMI_INIT_BASIC_H__

#include "dcmi_common.h"

typedef struct {
    int venderid;
    int deviceid;
    int chip_type;
    void (*init_board_type)(int);
    void (*init_product_type)(int);
} ChipInfo;

#define DCMI_SHIFT_FIVE_BITS            5
#define A5_MAINBOARD_ID_MASK            7
#define MAINBOARD_ID_HIGH_3BIT_POD      0
#define MAINBOARD_ID_HIGH_3BIT_A_K      1
#define MAINBOARD_ID_HIGH_3BIT_A_X      2
#define MAINBOARD_ID_HIGH_3BIT_CARD     3
#define MAINBOARD_ID_HIGH_3BIT_EQU      6

void dcmi_run_env_init(void);

void dcmi_init_ok(void);
 
void dcmi_init_board_details_default(void);
 
int dcmi_init_for_model(const int *device_id_list, int device_count);
 
int dcmi_init_for_soc(const int *device_id_list, int device_count);
 
int dcmi_init_for_server(int *device_id_list, int device_count);
 
void dcmi_310B_trans_baseboard_id(unsigned int *board_id);
 
int dcmi_init_chip_board_product_type(struct tag_pcie_idinfo_all *pcie_id_info);

void dcmi_init_chip_board_product_950(struct dsmi_board_info_stru *board_info);
 
int dcmi_init_board_type(const int *device_logic_id, int device_count);

int dcmi_trans_pcie_common_id(const char *bus_id_str, int common_len, int common_pos, unsigned int *common_num);

int dcmi_get_board_info_handle(int device_logic_id, struct dsmi_board_info_stru *board_info);

int dcmi_init_for_card(const int *device_id_list, int device_count);

int dcmi_flush_device_id(void);

int dcmi_pcie_slot_map_init(void);

void dcmi_card_info_sort(void);

bool dcmi_scene_is_950_uboe(int device_id);

#endif /* __DCMI_INIT_BASIC_H__ */