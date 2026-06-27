/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "comm_product.h"

unsigned int product_get_board_type(unsigned int mainboard_id)
{
    static const struct uint_to_uint_map map[] = {
        {MAINBOARD_ID_950_PCIE_CARD_1P,  PRODUCT_950_PCIE_CARD_1P},
        {MAINBOARD_ID_950_PCIE_CARD_2P,  PRODUCT_950_PCIE_CARD_2P},
        {MAINBOARD_ID_950_PCIE_CARD_4P,  PRODUCT_950_PCIE_CARD_4P},
        {MAINBOARD_ID_950_PCIE_CARD_8P,  PRODUCT_950_PCIE_CARD_8P},
        {MAINBOARD_ID_950_X86_2_2_UB,    PRODUCT_950_SERVER_X86},
        {MAINBOARD_ID_950_X86_2_2_UBOE,  PRODUCT_950_SERVER_X86},
        {MAINBOARD_ID_950_KP_2_4_UB,     PRODUCT_950_SERVER_ARM_2_4},
        {MAINBOARD_ID_950_KP_2_4_UBOE,   PRODUCT_950_SERVER_ARM_2_4},
        {MAINBOARD_ID_950_KP_0_8_UB,     PRODUCT_950_SERVER_ARM_0_8},
        {MAINBOARD_ID_950_KP_0_8_UBOE,   PRODUCT_950_SERVER_ARM_0_8},
        {MAINBOARD_ID_950_KP_0_0_UB,     PRODUCT_950_SERVER_ARM_0_0},
        {MAINBOARD_ID_950_KP_0_0_UBOE,   PRODUCT_950_SERVER_ARM_0_0},
        {MAINBOARD_ID_950_POD_NPU,       PRODUCT_950_POD},
        {MAINBOARD_ID_950_POD_BACKUP,    PRODUCT_950_POD},
        {MAINBOARD_ID_950_POD_2_6_UB,    PRODUCT_950_POD},
        {MAINBOARD_ID_950_UBX_4_0_UB,    PRODUCT_950_UBX},
    };
    int i;

    for (i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
        if (mainboard_id == map[i].key) {
            return map[i].val;
        }
    }
    return PRODUCT_950_INVALID;
}

unsigned int product_get_pod_port_type(unsigned int chip_id, unsigned int udie_id, unsigned int port_id)
{
    static const unsigned char pod_former_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_D2D, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_INVALID},
        {NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_H2D,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_H2D, NPU_PORT_INVALID, NPU_PORT_INVALID}
    };
    static const unsigned char pod_later_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET,
            NPU_PORT_OUTLET, NPU_PORT_H2D, NPU_PORT_H2D, NPU_PORT_INVALID, NPU_PORT_INVALID},
        {NPU_PORT_D2D, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_INVALID}
    };

    if (udie_id >= UDIE_NUMBER || port_id >= PORT_NUMBER) {
        return NPU_PORT_INVALID;
    }

    if ((chip_id % CHIP_NUMBER) < CHIP_HALF_NUMBER) {
        return pod_former_port_list[udie_id][port_id];
    } else {
        return pod_later_port_list[udie_id][port_id];
    }
}

unsigned int product_get_port_type(unsigned int board_type,
                                   unsigned int chip_id, unsigned int udie_id, unsigned int port_id)
{
    static const unsigned char server_arm_2_4_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_H2D, NPU_PORT_H2D, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_OUTLET,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_UBOE, NPU_PORT_UBOE},
        {NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_INVALID}
    };
    static const unsigned char server_arm_0_8_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_H2D, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_INVALID},
        {NPU_PORT_H2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_UBOE, NPU_PORT_UBOE}
    };
    static const unsigned char server_arm_0_0_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_H2D, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID,
            NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID},
        {NPU_PORT_H2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_UBOE, NPU_PORT_UBOE}
    };
    static const unsigned char server_x86_port_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_OUTLET,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_UBOE, NPU_PORT_UBOE},
        {NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_INVALID}
    };

    static const unsigned char server_ubx_port_4_0_list[UDIE_NUMBER][PORT_NUMBER] = {
        {NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID,
            NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_INVALID, NPU_PORT_D2D, NPU_PORT_INVALID},
        {NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_D2D, NPU_PORT_INVALID, NPU_PORT_OUTLET,
            NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_OUTLET, NPU_PORT_INVALID, NPU_PORT_INVALID}
    };

    if (udie_id >= UDIE_NUMBER || port_id >= PORT_NUMBER) {
        return NPU_PORT_INVALID;
    }

    if ((board_type == PRODUCT_950_PCIE_CARD_4P) && (udie_id == 0)) {
        return ((port_id >= PCIE_PORT_INDEX_START) && (port_id <= PCIE_PORT_INDEX_END)) ? \
            NPU_PORT_D2D : NPU_PORT_INVALID;
    } else if ((board_type == PRODUCT_950_PCIE_CARD_2P) && (udie_id == 0)) {
        if (port_id == PCIE_PORT_INDEX_EXTRA) {
            return NPU_PORT_D2D;
        }
        return ((port_id >= PCIE_PORT_INDEX_START) && (port_id <= PCIE_PORT_INDEX_END)) ? \
            NPU_PORT_D2D : NPU_PORT_INVALID;
    } else if (board_type == PRODUCT_950_SERVER_ARM_2_4) {
        return server_arm_2_4_port_list[udie_id][port_id];
    } else if (board_type == PRODUCT_950_SERVER_ARM_0_8) {
        return server_arm_0_8_port_list[udie_id][port_id];
    } else if (board_type == PRODUCT_950_SERVER_ARM_0_0) {
        return server_arm_0_0_port_list[udie_id][port_id];
    } else if (board_type == PRODUCT_950_SERVER_X86) {
        return server_x86_port_list[udie_id][port_id];
    } else if (board_type == PRODUCT_950_POD) {
        return product_get_pod_port_type(chip_id, udie_id, port_id);
    } else if (board_type == PRODUCT_950_UBX) {
        return server_ubx_port_4_0_list[udie_id][port_id];
    }
    return NPU_PORT_INVALID;
}
