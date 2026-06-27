/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef COMM_PRODUCT_H
#define COMM_PRODUCT_H

struct uint_to_uint_map {
    unsigned int key;
    unsigned int val;
};

enum product_board_type {
    PRODUCT_950_INVALID,
    PRODUCT_950_PCIE_CARD_1P,
    PRODUCT_950_PCIE_CARD_2P,
    PRODUCT_950_PCIE_CARD_4P,
    PRODUCT_950_PCIE_CARD_8P,
    PRODUCT_950_SERVER_X86,
    PRODUCT_950_SERVER_ARM_2_4,
    PRODUCT_950_SERVER_ARM_0_8,
    PRODUCT_950_SERVER_ARM_0_0,
    PRODUCT_950_POD,
    PRODUCT_950_UBX,
};

enum product_mainboard_id {
    MAINBOARD_ID_950_PCIE_CARD_1P   = 0x68,
    MAINBOARD_ID_950_PCIE_CARD_2P   = 0x6A,
    MAINBOARD_ID_950_PCIE_CARD_4P   = 0x6C,
    MAINBOARD_ID_950_PCIE_CARD_8P   = 0x6E,
    MAINBOARD_ID_950_X86_2_2_UB     = 0x40,
    MAINBOARD_ID_950_X86_2_2_UBOE   = 0x42,
    MAINBOARD_ID_950_KP_2_4_UB      = 0x21,
    MAINBOARD_ID_950_KP_2_4_UBOE    = 0x23,
    MAINBOARD_ID_950_KP_0_8_UB      = 0x25,
    MAINBOARD_ID_950_KP_0_8_UBOE    = 0x27,
    MAINBOARD_ID_950_KP_0_0_UB      = 0x29,
    MAINBOARD_ID_950_KP_0_0_UBOE    = 0x2B,
    MAINBOARD_ID_950_POD_NPU        = 0x03,
    MAINBOARD_ID_950_POD_BACKUP     = 0x05,
    MAINBOARD_ID_950_POD_2_6_UB     = 0x07,
    MAINBOARD_ID_950_UBX_4_0_UB     = 0x44,
};

enum product_port_type {
    NPU_PORT_INVALID,
    NPU_PORT_D2D,
    NPU_PORT_H2D,
    NPU_PORT_OUTLET,
    NPU_PORT_UBOE,
};

#define UDIE_NUMBER 2
#define PORT_NUMBER 10 // UBoE port is logically split to x2 mode, so port number can be 9 + 1
#define CHIP_NUMBER 8
#define CHIP_HALF_NUMBER 4

#define PCIE_PORT_INDEX_START   4
#define PCIE_PORT_INDEX_END   6
#define PCIE_PORT_INDEX_EXTRA  8

unsigned int product_get_board_type(unsigned int mainboard_id);
unsigned int product_get_port_type(unsigned int board_type,
                                   unsigned int chip_id, unsigned int udie_id, unsigned int port_id);

#endif