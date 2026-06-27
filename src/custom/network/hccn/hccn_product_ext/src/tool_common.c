/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "ds_net.h"
#include "tool_ext.h"
#include "tool.h"
#include "tool_ops.h"

int tool_is_optical_supported_board_type(struct tool_param *param)
{
    int ret;
    int board_type;

    ret = tool_get_board_type(param, &board_type);
    if (ret) {
        roce_err("hccn tool get board type failed. (ret=%d)", ret);
        return UDA_DSMI_EXE_ERR;
    }

    // 支持 A+K A+X 天成 podc 标卡
    if (board_type != A_K_BOARD_TYPE && board_type != A_X_BOARD_TYPE && board_type != SUPERPOD_900_BOARD_TYPE &&
        board_type != PCIe_BOARD_TYPE && board_type != PoD_BUSINESS_BOARD_TYPE) {
        roce_err("this command not supported in this product");
        return UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR;
    }

    return 0;
}

int tool_get_convert_logic_id_and_master_flag(struct tool_param *param, int *logic_id, unsigned char *master_flag)
{
    *logic_id = param->logic_id;
    if (is_ATLAS_900_A3_SUPERPOD(param->mainboard_id)) {
        *master_flag = atlas_900_a3_superpod_phy_id_convert(param->phy_id) == param->phy_id ? 1 : 0;
        *logic_id = ATLAS_900_A3_SUPERPOD_logic_id_convert(param->phy_id);
        if (*logic_id == INVALID_LOGIC_ID) {
            roce_err("Get logic_id fail. (logic_id=%d)", logic_id);
            return UDA_DSMI_CONTROL_LINK_UNREACHABLE_ERR;
        }
    } else {
        *master_flag = 1;
    }

    return 0;
}