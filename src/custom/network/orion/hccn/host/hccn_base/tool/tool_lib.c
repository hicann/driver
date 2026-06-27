/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ds_data.h"
#include "tool_errcode.h"
#include "dsmi_inner_interface.h"
#include "dsmi_common_interface.h"
#include "tool_comm.h"
#include "comm_channel.h"
#include "tool_lib.h"

unsigned int tool_get_board_type(struct command_context *ctx)
{
    int ret;
    if (ctx->npu_info.mainboard_id == 0) {
        ret = dsmi_get_mainboard_id(ctx->dev_id, &ctx->npu_info.mainboard_id);
        if (ret) {
            hccn_err("get board type failed on get mainboard id. (ret=%d; dev=%d)", ret, ctx->dev_id);
            return PRODUCT_950_INVALID;
        }
    }
    return product_get_board_type(ctx->npu_info.mainboard_id);
}

unsigned int tool_get_port_type(struct command_context *ctx)
{
    unsigned int board_type;

    board_type = tool_get_board_type(ctx);
    return product_get_port_type(board_type, (unsigned int)ctx->dev_id,
                                 (unsigned int)ctx->udie_id, (unsigned int)ctx->port_id);
}

bool tool_is_pcie_board(struct command_context *ctx)
{
    unsigned int board_type = tool_get_board_type(ctx);
    switch (board_type) {
        case PRODUCT_950_PCIE_CARD_1P:
        case PRODUCT_950_PCIE_CARD_2P:
        case PRODUCT_950_PCIE_CARD_4P:
        case PRODUCT_950_PCIE_CARD_8P:
            return true;
        default:
            return false;
    }
}

bool tool_is_ascend950_A_K_0_8(struct command_context *ctx)
{
    unsigned int board_type;

    if (ctx == NULL) {
        hccn_err("ctx is invalid.");
        return false;
    }

    board_type = tool_get_board_type(ctx);
    return (board_type == PRODUCT_950_SERVER_ARM_0_8);
}

bool tool_is_ascend950_A_K_2_4(struct command_context *ctx)
{
    unsigned int board_type;

    board_type = tool_get_board_type(ctx);
    return (board_type == PRODUCT_950_SERVER_ARM_2_4);
}

int *tool_get_pcie_card_port_list(struct command_context *ctx)
{
    unsigned int phy_id;
    int ret;

    // 各形态的有效Port列表，需要以-1作为结束符，就像字符串的\0一样
    // 这里的数据会被取出使用，又因为cleancode要求不能定义成全局变量，所以定义为static静态变量
    static int pcie_card_4P_port_list[] = {4, 5, 6, -1};
    static int pcie_card_2P_port_list[] = {4, 5, 6, 8, -1};
    static int invalid_port_list[] = {-1};

    if (ctx->npu_info.mainboard_id == 0) {
        ret = dsmi_get_phyid_from_logicid((unsigned int)ctx->dev_id, &phy_id);
        if (ret) {
            hccn_err("get port list failed on get phyid. (ret=%d)", ret);
            return NULL;
        }
        ret = dsmi_get_mainboard_id(phy_id, &ctx->npu_info.mainboard_id);
        if (ret) {
            hccn_err("get port list failed on get mainboardid. (ret=%d; phy_id=%u)", ret, phy_id);
            return NULL;
        }
    }

    if (ctx->npu_info.mainboard_id == MAINBOARD_ID_950_PCIE_CARD_4P) {
        return pcie_card_4P_port_list;
    } else if (ctx->npu_info.mainboard_id == MAINBOARD_ID_950_PCIE_CARD_2P) {
        return pcie_card_2P_port_list;
    } else {
        return invalid_port_list;
    }
}

char* trim(char *str)
{
    if (!str) return str;
    
    char *start = str;
    char *end = str + strlen(str);
    
    // 跳过前导空白
    while (isspace((unsigned char)*start) && start < end) {
        start++;
    }
    
    // 跳过尾部空白
    while (end > start && isspace((unsigned char)*(end - 1))) {
        end--;
    }
    
    *end = '\0';
    
    if (start != str) {
        int ret = memmove_s(str, end - start + 1, start, end - start + 1);
        if (ret != EOK) {
            hccn_err("memmove_s failed.");
            return NULL;
        }
    }
    
    return str;
}

int validate_firmware_path(const char *path)
{
    struct stat file_stat;

    if (path == NULL || strlen(path) == 0) {
        hccn_err("Firmware path is empty");
        return TOOL_FILE_PATH_ERROR;
    }

    if (strlen(path) >= PATH_MAX) {
        hccn_err("Firmware path too long (max %d)", PATH_MAX - 1);
        return TOOL_FILE_PATH_ERROR;
    }

    if (access(path, F_OK) != 0) {
        hccn_err("Firmware file not found: %s", path);
        return TOOL_FILE_PATH_ERROR;
    }

    if (access(path, R_OK) != 0) {
        hccn_err("Firmware file not readable: %s", path);
        return TOOL_FILE_PATH_ERROR;
    }

    if (stat(path, &file_stat) != 0) {
        hccn_err("Failed to get file info: %s", path);
        return TOOL_FILE_PATH_ERROR;
    }
    if (!S_ISREG(file_stat.st_mode)) {
        hccn_err("Path is not a regular file: %s", path);
        return TOOL_FILE_PATH_ERROR;
    }

    if (file_stat.st_size == 0) {
        hccn_err("Firmware file is empty: %s", path);
        return TOOL_FILE_PATH_ERROR;
    }

    return 0;
}

// 检查mainboard_id是否为UBoE类型
bool tool_is_uboe_mainboard(unsigned int mainboard_id)
{
    switch (mainboard_id) {
        case MAINBOARD_ID_950_KP_2_4_UBOE:
        case MAINBOARD_ID_950_KP_0_8_UBOE:
        case MAINBOARD_ID_950_KP_0_0_UBOE:
            return true;
        default:
            return false;
    }
}

