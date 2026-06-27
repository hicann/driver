/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "comm_channel.h"
#include "comm_channel_ext.h"
#include "hccn_err.h"
#include "hccn_log.h"
#include "tool_table.h"
#include "tool_errcode.h"
#include "tool_param.h"
#include "tool_cmd_err.h"
#include "tool_cmd_parse.h"
#include "tool_product.h"
#include "dsmi_common_product.h"
#include "ds_data.h"
#include "tool_lib.h"
#include "ascend_hal.h"
#include "utils/bitmap.h"
#include "tool_optical.h"
#include "dsmi_optical.h"

static int tool_optical_get_table_row_num_by_mainboard_id(unsigned int mainborad_id, int* row_num);

static int xsfp_get_peer_dev_id_by_slot_id(int dev_id, int peer_slot_id)
{
    int server_id = dev_id / SERVER_NPU_NUM;
    int new_dev_id = server_id * SERVER_NPU_NUM + peer_slot_id;
    return new_dev_id;
}

// 光模块固件升级子选项函数
static int xsfp_set_absent_table_info(int row_id, char **table_formats, int table_size)
{
    int ret = 0, j = 0;
    for (j = 0; j < table_size; j++) {
        ret += SET_TABLE(row_id, table_formats[j], "%s", TABLE_INFO_INVALID);
    }
    return ret;
}

static int is_xsfp_present(const xsfp_module_info *xsfp_info)
{
    return (xsfp_info != NULL && xsfp_info->config_data.master_xsfp_present == 1);
}

static int init_optical_table_row(struct command_context *ctx, int row)
{
    const int data_columns = 8;
    int col = 0;
    int ret = 0;
    int i;

    if (ctx->dev_mask == DEV_OPTICAL_ATTR) {
        ret += set_table_by_index(1, row, col++, ctx->npu_info.logic_id);
        ret += set_table_by_index(1, row, col++, ctx->optical_id);
    } else {
        ret += set_table_by_index(1, row, col++, ctx->npu_info.logic_id);
        ret += set_table_by_index(1, row, col++, ctx->udie_id);
        ret += set_table_by_index(1, row, col++, ctx->port_id);
    }
    if (ret != 0) {
        return TOOL_TABLE_ERROR;
    }

    for (i = 0; i < data_columns; ++i) {
        ret = set_table_by_index(1, row, col++, TABLE_INFO_INVALID);
        if (ret != 0) {
            return ret;
        }
    }
    return 0;
}

static const char* tool_xsfp_identifier_type_to_string(int identifier, int type)
{
#define LPO_DESC "LPO"
#define ACC_DESC "ACC"
    int i;

    static struct xsfp_id_map names[] = {
        { 0x00, "UNKNOWN" },
        { 0x01, "GBIC" },
        { 0x03, "SFP_SFPPLUS" },
        { 0x04, "PIN_XBI" },
        { 0x05, "XENPAK" },
        { 0x06, "XFP" },
        { 0x07, "XFF" },
        { 0x08, "XFP_E" },
        { 0x09, "XPAK" },
        { 0x0A, "X2" },
        { 0x0B, "DWDM_SFP_SFPPLUS" },
        { 0x0C, "QSFP" },
        { 0x0D, "QSFPPLUS" },
        { 0x0E, "CXP" },
        { 0x11, "QSFP28 or later" },
        { 0x12, "CXP2" },
        { 0x18, "QSFP_DD" },
        { 0x19, "OSFP" },
        { 0x1E, "QSFP+ or later" },
        { -127, "RESERVED" },
        { 0xFFFF, "NA" },
    };

    for (i = 0; i < (sizeof(names) / sizeof(names[0])); i++) {
        if (names[i].id == identifier) {
            if (names[i].id == 0x19 && type == XSFP_PRODUCT_LPO) {
                return LPO_DESC;
            } else if (names[i].id == 0x19 && type == XSFP_PRODUCT_OSFP_ACC) {
                return ACC_DESC;
            }
            return names[i].id_str;
        }
    }

    return "UNKNOWN";
}

static int tool_optical_info_print_optical_id_mode_base_info(struct command_context *ctx, xsfp_module_info xsfp_info)
{
#define WAVE_LEN_SCALE    20
    unsigned int wave_length;
    int ret = 0;
    malloc_table_advance("IO", TOOL_TABLE_ROW_1, TOOL_TABLE_COL_6,
        "Present",      TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "High_power",   TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Identifier",   TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Wave_len",     TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Phy_code",     TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Revision",     TYPE_CHARS, TOOL_TABLE_CHARS_10);
    unsigned int wave_len_msb = xsfp_info.base_data.wavelength[0];
    unsigned int wave_len_lsb = xsfp_info.base_data.wavelength[1];
    char *table_formats[] = {
        "High_power", "Identifier", "Wave_len", "Phy_code", "Revision"
    };
    ret += SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->optical_id, NULL, NULL, NULL, NULL, NULL, NULL);
    ret += SET_TABLE(0, "Present", "%s", xsfp_info.config_data.master_xsfp_present ? "present" : "absent");
    if (xsfp_info.config_data.master_xsfp_present == 1) {
        wave_length = ((wave_len_msb << 0x8) | wave_len_lsb) / WAVE_LEN_SCALE;
        if (xsfp_info.base_data.optical_type == XSFP_PRODUCT_OSFP_ACC) {
            ret += SET_TABLE(0, "High_power", "%s", TABLE_INFO_INVALID);
        } else {
            ret += SET_TABLE(0, "High_power", "%s",
                             (xsfp_info.config_data.msm_stat == XSFP_MODULE_READY) ? "enable" : "disable");
        }
        ret += SET_TABLE(0, "Identifier", "%s",
                         tool_xsfp_identifier_type_to_string(xsfp_info.base_data.xsfp_identifier,
                                                             xsfp_info.base_data.optical_type));
        if (xsfp_info.base_data.optical_type == XSFP_PRODUCT_OSFP_ACC) {
            ret += SET_TABLE(0, "Wave_len", "-");
        } else {
            ret += SET_TABLE(0, "Wave_len", "%u nm", wave_length);
        }
        ret += SET_TABLE(0, "Phy_code", "%.*s", XSFP_PHYSICAL_CODE_LEN + FOUR_VALUE,
                         xsfp_info.manufacture_data.physical_code);
        ret += SET_TABLE(0, "Revision", "%.*s", XSFP_VENDOR_REV_LEN, xsfp_info.manufacture_data.vendor_rev);
    } else {
        ret += xsfp_set_absent_table_info(0, table_formats, sizeof(table_formats) / sizeof(char *));
    }
    if (ret) {
        hccn_err("failed to make optical base info table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    print_table();
    clean_table();

    return 0;
}

static int tool_optical_info_print_optical_id_mode_vendor_info(struct command_context *ctx, xsfp_module_info xsfp_info)
{
    int ret, sret;
    char vendor_name[VENDOR_NAME_LEN + 1] = {0};
    char vendor_pn[VENDOR_PN_LEN + 1] = {0};
    char vendor_sn[VENDOR_SN_LEN + 1] = {0};
    char vendor_oui[XSFP_OUI_PRINT_LEN + 1] = {0};
    char date_code[DATA_CODE_LEN + 1] = {0};
    malloc_table_advance("IO", TOOL_TABLE_ROW_1, TOOL_TABLE_COL_5,
        "Name",             TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Part_number",      TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Serial_number",    TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Org_unique_id",    TYPE_CHARS, TOOL_TABLE_CHARS_12,
        "Manufact_date",    TYPE_CHARS, TOOL_TABLE_CHARS_10);
    ret = SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->optical_id, NULL, NULL, NULL,
                         NULL, NULL);
    (void)memcpy_s(vendor_name, VENDOR_NAME_LEN + 1, xsfp_info.manufacture_data.vendor_name, VENDOR_NAME_LEN);
    vendor_name[VENDOR_NAME_LEN] = '\0';
    ret += SET_TABLE(0, "Name", "%s", vendor_name);
    (void)memcpy_s(vendor_pn, VENDOR_PN_LEN + 1, xsfp_info.manufacture_data.vendor_pn, VENDOR_PN_LEN);
    vendor_pn[VENDOR_PN_LEN] = '\0';
    ret += SET_TABLE(0, "Part_number", "%s", vendor_pn);
    (void)memcpy_s(vendor_sn, VENDOR_SN_LEN + 1, xsfp_info.manufacture_data.vendor_sn, VENDOR_SN_LEN);
    vendor_sn[VENDOR_SN_LEN] = '\0';
    ret += SET_TABLE(0, "Serial_number", "%s", vendor_sn);
    vendor_oui[XSFP_OUI_PRINT_LEN] = '\0';
    sret = sprintf_s(vendor_oui, XSFP_OUI_PRINT_LEN, "%02X-%02X-%02X", xsfp_info.manufacture_data.vendor_oui[0x0],
        xsfp_info.manufacture_data.vendor_oui[0x1], xsfp_info.manufacture_data.vendor_oui[0x2]);
    if (sret < 0) {
        hccn_err("sprintf_s failed. (sret=%d)", sret);
        ret += TOOL_TABLE_ERROR;
    }
    ret += SET_TABLE(0, "Org_unique_id", "%s", vendor_oui);
    (void)memcpy_s(date_code, DATA_CODE_LEN + 1, xsfp_info.manufacture_data.date_code, DATA_CODE_LEN);
    date_code[DATA_CODE_LEN] = '\0';
    ret += SET_TABLE(0, "Manufact_date", "%s", date_code);
    if (ret) {
        hccn_err("failed to make optical vendor info table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    print_table();
    clean_table();

    return 0;
}

static void tool_status_malloc_table(int lane_num, int xsfp_type)
{
    int table_row_num = (xsfp_type == XSFP_PRODUCT_LPO) ? TOOL_TABLE_ROW_3 : TOOL_TABLE_ROW_5;
    if (lane_num == OSFP_LANE_NUM) {
        malloc_table_advance("IO", table_row_num, TOOL_TABLE_COL_9,
            "Items",      TYPE_STR,
            "Lane0",      TYPE_STR,
            "Lane1",      TYPE_STR,
            "Lane2",      TYPE_STR,
            "Lane3",      TYPE_STR,
            "Lane4",      TYPE_STR,
            "Lane5",      TYPE_STR,
            "Lane6",      TYPE_STR,
            "Lane7",      TYPE_STR);
    } else if (lane_num == QSFP_LANE_NUM) {
        malloc_table_advance("IO", TOOL_TABLE_ROW_5, TOOL_TABLE_COL_5,
            "Items",      TYPE_STR,
            "Lane0",      TYPE_STR,
            "Lane1",      TYPE_STR,
            "Lane2",      TYPE_STR,
            "Lane3",      TYPE_STR);
    }

    return;
}

static int tool_status_set_entire_row(int lane_num, int index, struct command_context *ctx, xsfp_module_info xsfp_info)
{
    int ret = 0;
    char* flag_map[TOOL_FLAG_MAP_NUM] = {"TxFault Flag", "TxLos Flag", "RxLos Flag", "TxLol Flag", "RxLol Flag"};
    int status_map[] = {
        xsfp_info.dynamic_data.tx_fault,
        xsfp_info.dynamic_data.adapt_info.txlos,
        xsfp_info.dynamic_data.adapt_info.rxlos,
        xsfp_info.dynamic_data.adapt_info.txlol,
        xsfp_info.dynamic_data.adapt_info.rxlol
    };

    if (lane_num == OSFP_LANE_NUM) {
        ret += SET_ENTIRE_ROW(index, ctx->npu_info.logic_id, ctx->optical_id, flag_map[index],
            (status_map[index] & TOOL_BIT0) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT1) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT2) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT3) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT4) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT5) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT6) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT7) ? "Abnormal" : "Normal");
    } else if (lane_num == QSFP_LANE_NUM) {
        ret += SET_ENTIRE_ROW(index, ctx->npu_info.logic_id, ctx->optical_id, flag_map[index],
            (status_map[index] & TOOL_BIT0) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT1) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT2) ? "Abnormal" : "Normal",
            (status_map[index] & TOOL_BIT3) ? "Abnormal" : "Normal");
    }
    return ret;
}

static int tool_optical_info_print_optical_id_mode_status(struct command_context *ctx, xsfp_module_info xsfp_info)
{
    int ret = 0, i, lane_num = xsfp_info.config_data.lane_num;
    int tx_stat_check_num = 0;
    int xsfp_type = xsfp_info.base_data.optical_type;

    if ((lane_num != QSFP_LANE_NUM) && (lane_num != OSFP_LANE_NUM)) {
        hccn_err("invalid lane num. (lane_num=%d)", lane_num);
        return TOOL_INVALID_PARAM;
    }

    tool_status_malloc_table(lane_num, xsfp_type);
    tx_stat_check_num = (xsfp_info.base_data.optical_type == XSFP_PRODUCT_LPO) ? THREE_NUM : TOOL_FLAG_MAP_NUM;
    for (i = 0; i < tx_stat_check_num; i++) {
        ret += tool_status_set_entire_row(lane_num, i, ctx, xsfp_info);
    }
    if (ret) {
        hccn_err("failed to make optical status info table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    print_table();
    clean_table();

    return 0;
}

#define VPP_TO_MV(vpp)              ((double)(vpp) / 10)

// 0~3为下层抽屉，4~7位上层抽屉，对应关系一致
static struct portid_optical_lane_id_map g_portid_lane_id_map_table[DEV_NUM_PER_LEVEL][PER_DEV_USE_OPTICAL_2_4] = {
    //     dev_id  udie_id  port_id                        optical_id / optical_lane_id(index为lane_id)
    {   {     0x0,     0x0,     0x4,     {{0x6, 0x5}, {0x6, 0x7}, {0x5, 0x5}, {0x5, 0x7}}  },
        {     0x0,     0x0,     0x7,     {{0x6, 0x4}, {0x6, 0x6}, {0x5, 0x4}, {0x5, 0x6}}  },
        {     0x0,     0x0,     0x5,     {{0xa, 0x5}, {0xa, 0x7}, {0x9, 0x5}, {0x9, 0x7}}  },
        {     0x0,     0x0,     0x6,     {{0xa, 0x4}, {0xa, 0x6}, {0x9, 0x4}, {0x9, 0x6}}  },
        {     0x0,     0x1,     0x5,     {{0x4, 0x5}, {0x4, 0x7}, {0x3, 0x5}, {0x3, 0x7}}  },
        {     0x0,     0x1,     0x6,     {{0x4, 0x4}, {0x4, 0x6}, {0x3, 0x4}, {0x3, 0x6}}  }, },
    {   {     0x1,     0x0,     0x4,     {{0x6, 0x1}, {0x6, 0x3}, {0x5, 0x1}, {0x5, 0x3}}  },
        {     0x1,     0x0,     0x7,     {{0x6, 0x0}, {0x6, 0x2}, {0x5, 0x0}, {0x5, 0x2}}  },
        {     0x1,     0x0,     0x5,     {{0xa, 0x1}, {0xa, 0x3}, {0x9, 0x1}, {0x9, 0x3}}  },
        {     0x1,     0x0,     0x6,     {{0xa, 0x0}, {0xa, 0x2}, {0x9, 0x0}, {0x9, 0x2}}  },
        {     0x1,     0x1,     0x5,     {{0x4, 0x1}, {0x4, 0x3}, {0x3, 0x1}, {0x3, 0x3}}  },
        {     0x1,     0x1,     0x6,     {{0x4, 0x0}, {0x4, 0x2}, {0x3, 0x0}, {0x3, 0x2}}  }, },
    {   {     0x2,     0x0,     0x4,     {{0x8, 0x1}, {0x8, 0x3}, {0x7, 0x1}, {0x7, 0x3}}  },
        {     0x2,     0x0,     0x7,     {{0x8, 0x0}, {0x8, 0x2}, {0x7, 0x0}, {0x7, 0x2}}  },
        {     0x2,     0x0,     0x5,     {{0x2, 0x1}, {0x2, 0x3}, {0x1, 0x1}, {0x1, 0x3}}  },
        {     0x2,     0x0,     0x6,     {{0x2, 0x0}, {0x2, 0x2}, {0x1, 0x0}, {0x1, 0x2}}  },
        {     0x2,     0x1,     0x5,     {{0xc, 0x1}, {0xc, 0x3}, {0xb, 0x1}, {0xb, 0x3}}  },
        {     0x2,     0x1,     0x6,     {{0xc, 0x0}, {0xc, 0x2}, {0xb, 0x0}, {0xb, 0x2}}  }, },
    {   {     0x3,     0x0,     0x4,     {{0x8, 0x5}, {0x8, 0x7}, {0x7, 0x5}, {0x7, 0x7}}  },
        {     0x3,     0x0,     0x7,     {{0x8, 0x4}, {0x8, 0x6}, {0x7, 0x4}, {0x7, 0x6}}  },
        {     0x3,     0x0,     0x5,     {{0x2, 0x5}, {0x2, 0x7}, {0x1, 0x5}, {0x1, 0x7}}  },
        {     0x3,     0x0,     0x6,     {{0x2, 0x4}, {0x2, 0x6}, {0x1, 0x4}, {0x1, 0x6}}  },
        {     0x3,     0x1,     0x5,     {{0xc, 0x5}, {0xc, 0x7}, {0xb, 0x5}, {0xb, 0x7}}  },
        {     0x3,     0x1,     0x6,     {{0xc, 0x4}, {0xc, 0x6}, {0xb, 0x4}, {0xb, 0x6}}  }, },
};

struct optical_id_map g_optical_id_map[] = {
    // optical_phy_id  phy_dev_id optical_logic_id
    {             0x1,       0x2,             0x2},
    {             0x2,       0x3,             0x2},
    {             0x3,       0x0,             0x0},
    {             0x4,       0x1,             0x0},
    {             0x5,       0x0,             0x1},
    {             0x6,       0x1,             0x1},
    {             0x7,       0x2,             0x1},
    {             0x8,       0x3,             0x1},
    {             0x9,       0x0,             0x2},
    {             0xa,       0x1,             0x2},
    {             0xb,       0x2,             0x0},
    {             0xc,       0x3,             0x0},
};

// 光模块视角展开
struct port_id_optical_lane_id_map g_macro_id_from_xsfp_id_map[DEV_NUM_PER_LEVEL][PER_DEV_CTL_OSFP_NUM_0_8] = {
    // chip_id 0
    {
        // {dev_id, macro_id, macro_lane_id}
        {{{0x1, 0x6, 0x0}, {0x0, 0x5, 0x0}, {0x1, 0x6, 0x1}, {0x0, 0x5, 0x1},
          {0x0, 0x6, 0x0}, {0x1, 0x5, 0x0}, {0x0, 0x6, 0x1}, {0x1, 0x5, 0x1}}}, // osfp 0
        {{{0x1, 0x8, 0x0}, {0x0, 0x7, 0x0}, {0x1, 0x8, 0x1}, {0x0, 0x7, 0x1},
          {0x0, 0x8, 0x0}, {0x1, 0x7, 0x0}, {0x0, 0x8, 0x1}, {0x1, 0x7, 0x1}}}, // osfp 1
        {{{0x1, 0x2, 0x3}, {0x0, 0x1, 0x3}, {0x1, 0x2, 0x2}, {0x0, 0x1, 0x2},
          {0x0, 0x2, 0x3}, {0x1, 0x1, 0x3}, {0x0, 0x2, 0x2}, {0x1, 0x1, 0x2}}}, // osfp 2
        {{{0x1, 0x4, 0x0}, {0x0, 0x3, 0x3}, {0x1, 0x4, 0x1}, {0x0, 0x3, 0x2},
          {0x0, 0x4, 0x0}, {0x1, 0x3, 0x3}, {0x0, 0x4, 0x1}, {0x1, 0x3, 0x2}}}  // osfp 3
    },
    // chip_id 1
    {
        {{{0x1, 0x6, 0x2}, {0x0, 0x5, 0x2}, {0x1, 0x6, 0x3}, {0x0, 0x5, 0x3},
          {0x0, 0x6, 0x2}, {0x1, 0x5, 0x2}, {0x0, 0x6, 0x3}, {0x1, 0x5, 0x3}}}, // osfp 0
        {{{0x1, 0x8, 0x2}, {0x0, 0x7, 0x2}, {0x1, 0x8, 0x3}, {0x0, 0x7, 0x3},
          {0x0, 0x8, 0x2}, {0x1, 0x7, 0x2}, {0x0, 0x8, 0x3}, {0x1, 0x7, 0x3}}}, // osfp 1
        {{{0x1, 0x2, 0x1}, {0x0, 0x1, 0x1}, {0x1, 0x2, 0x0}, {0x0, 0x1, 0x0},
          {0x0, 0x2, 0x1}, {0x1, 0x1, 0x1}, {0x0, 0x2, 0x0}, {0x1, 0x1, 0x0}}}, // osfp 2
        {{{0x1, 0x4, 0x2}, {0x0, 0x3, 0x1}, {0x1, 0x4, 0x3}, {0x0, 0x3, 0x0},
          {0x0, 0x4, 0x2}, {0x1, 0x3, 0x1}, {0x0, 0x4, 0x3}, {0x1, 0x3, 0x0}}}  // osfp 3
    },
    // chip_id 2
    {
        {{{0x2, 0x2, 0x3}, {0x3, 0x1, 0x3}, {0x2, 0x2, 0x2}, {0x3, 0x1, 0x2},
          {0x3, 0x2, 0x3}, {0x2, 0x1, 0x3}, {0x3, 0x2, 0x2}, {0x2, 0x1, 0x2}}}, // osfp 0
        {{{0x2, 0x4, 0x0}, {0x3, 0x3, 0x3}, {0x2, 0x4, 0x1}, {0x3, 0x3, 0x2},
          {0x3, 0x4, 0x0}, {0x2, 0x3, 0x3}, {0x3, 0x4, 0x1}, {0x2, 0x3, 0x2}}}, // osfp 1
        {{{0x2, 0x6, 0x0}, {0x3, 0x5, 0x0}, {0x2, 0x6, 0x1}, {0x3, 0x5, 0x1},
          {0x3, 0x6, 0x0}, {0x2, 0x5, 0x0}, {0x3, 0x6, 0x1}, {0x2, 0x5, 0x1}}}, // osfp 2
        {{{0x2, 0x8, 0x0}, {0x3, 0x7, 0x0}, {0x2, 0x8, 0x1}, {0x3, 0x7, 0x1},
          {0x3, 0x8, 0x0}, {0x2, 0x7, 0x0}, {0x3, 0x8, 0x1}, {0x2, 0x7, 0x1}}}  // osfp 3
    },
    // chip_id 3
    {
        {{{0x2, 0x2, 0x1}, {0x3, 0x1, 0x1}, {0x2, 0x2, 0x0}, {0x3, 0x1, 0x0},
          {0x3, 0x2, 0x1}, {0x2, 0x1, 0x1}, {0x3, 0x2, 0x0}, {0x2, 0x1, 0x0}}}, // osfp 0
        {{{0x2, 0x4, 0x2}, {0x3, 0x3, 0x1}, {0x2, 0x4, 0x3}, {0x3, 0x3, 0x0},
          {0x3, 0x4, 0x2}, {0x2, 0x3, 0x1}, {0x3, 0x4, 0x3}, {0x2, 0x3, 0x0}}}, // osfp 1
        {{{0x2, 0x6, 0x2}, {0x3, 0x5, 0x2}, {0x2, 0x6, 0x3}, {0x3, 0x5, 0x3},
          {0x3, 0x6, 0x2}, {0x2, 0x5, 0x2}, {0x3, 0x6, 0x3}, {0x2, 0x5, 0x3}}}, // osfp 2
        {{{0x2, 0x8, 0x2}, {0x3, 0x7, 0x2}, {0x2, 0x8, 0x3}, {0x3, 0x7, 0x3},
          {0x3, 0x8, 0x2}, {0x2, 0x7, 0x2}, {0x3, 0x8, 0x3}, {0x2, 0x7, 0x3}}}  // osfp 3
    }
};

// port口视角展开
static struct optical_id_macro_laneid_map g_opticalid_macro_lane_id_map_table[DEV_NUM_PER_LEVEL][UDIE_PORT_NUM] = {
    // chip_id 0
    {
        // {光模块丝印编码，光模块逻辑id，主控该光模块的模组槽位号，port口的lane对应光模块的lane}
        {{{-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}}},
        {{{ 0xe,  0x2,  0x1,  0x3}, { 0xe,  0x2,  0x1,  0x1}, { 0xd,  0x2,  0x0,  0x3}, { 0xd,  0x2,  0x0,  0x1}}},
        {{{ 0xe,  0x2,  0x1,  0x6}, { 0xe,  0x2,  0x1,  0x4}, { 0xd,  0x2,  0x0,  0x6}, { 0xd,  0x2,  0x0,  0x4}}},
        {{{0x10,  0x3,  0x1,  0x3}, {0x10,  0x3,  0x1,  0x1}, { 0xf,  0x3,  0x0,  0x3}, { 0xf,  0x3,  0x0,  0x1}}},
        {{{ 0xf,  0x3,  0x0,  0x4}, { 0xf,  0x3,  0x0,  0x6}, {0x10,  0x3,  0x1,  0x4}, {0x10,  0x3,  0x1,  0x6}}},
        {{{ 0x9,  0x0,  0x0,  0x1}, { 0x9,  0x0,  0x0,  0x3}, { 0xa,  0x0,  0x1,  0x1}, { 0xa,  0x0,  0x1,  0x3}}},
        {{{ 0x9,  0x0,  0x0,  0x4}, { 0x9,  0x0,  0x0,  0x6}, { 0xa,  0x0,  0x1,  0x4}, { 0xa,  0x0,  0x1,  0x6}}},
        {{{ 0xb,  0x1,  0x0,  0x1}, { 0xb,  0x1,  0x0,  0x3}, { 0xc,  0x1,  0x1,  0x1}, { 0xc,  0x1,  0x1,  0x3}}},
        {{{ 0xb,  0x1,  0x0,  0x4}, { 0xb,  0x1,  0x0,  0x6}, { 0xc,  0x1,  0x1,  0x4}, { 0xc,  0x1,  0x1,  0x6}}}
    },
    // chip_id 1
    {
        {{{-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}}},
        {{{ 0xe,  0x2,  0x1,  0x7}, { 0xe,  0x2,  0x1,  0x5}, { 0xd,  0x2,  0x0,  0x7}, { 0xd,  0x2,  0x0,  0x5}}},
        {{{ 0xe,  0x2,  0x1,  0x2}, { 0xe,  0x2,  0x1,  0x0}, { 0xd,  0x2,  0x0,  0x2}, { 0xd,  0x2,  0x0,  0x0}}},
        {{{0x10,  0x3,  0x1,  0x7}, {0x10,  0x3,  0x1,  0x5}, { 0xf,  0x3,  0x0,  0x7}, { 0xf,  0x3,  0x0,  0x5}}},
        {{{ 0xf,  0x3,  0x0,  0x0}, { 0xf,  0x3,  0x0,  0x2}, {0x10,  0x3,  0x1,  0x0}, {0x10,  0x3,  0x1,  0x2}}},
        {{{ 0x9,  0x0,  0x0,  0x5}, { 0x9,  0x0,  0x0,  0x7}, { 0xa,  0x0,  0x1,  0x5}, { 0xa,  0x0,  0x1,  0x7}}},
        {{{ 0x9,  0x0,  0x0,  0x0}, { 0x9,  0x0,  0x0,  0x2}, { 0xa,  0x0,  0x1,  0x0}, { 0xa,  0x0,  0x1,  0x2}}},
        {{{ 0xb,  0x1,  0x0,  0x5}, { 0xb,  0x1,  0x0,  0x7}, { 0xc,  0x1,  0x1,  0x5}, { 0xc,  0x1,  0x1,  0x7}}},
        {{{ 0xb,  0x1,  0x0,  0x0}, { 0xb,  0x1,  0x0,  0x2}, { 0xc,  0x1,  0x1,  0x0}, { 0xc,  0x1,  0x1,  0x2}}}
    },
    // chip_id 2
    {
        {{{-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}}},
        {{{ 0x2,  0x0,  0x3,  0x7}, { 0x2,  0x0,  0x3,  0x5}, { 0x1,  0x0,  0x2,  0x7}, { 0x1,  0x0,  0x2,  0x5}}},
        {{{ 0x2,  0x0,  0x3,  0x2}, { 0x2,  0x0,  0x3,  0x0}, { 0x1,  0x0,  0x2,  0x2}, { 0x1,  0x0,  0x2,  0x0}}},
        {{{ 0x4,  0x1,  0x3,  0x7}, { 0x4,  0x1,  0x3,  0x5}, { 0x3,  0x1,  0x2,  0x7}, { 0x3,  0x1,  0x2,  0x5}}},
        {{{ 0x3,  0x1,  0x2,  0x0}, { 0x3,  0x1,  0x2,  0x2}, { 0x4,  0x1,  0x3,  0x0}, { 0x4,  0x1,  0x3,  0x2}}},
        {{{ 0x5,  0x2,  0x2,  0x5}, { 0x5,  0x2,  0x2,  0x7}, { 0x6,  0x2,  0x3,  0x5}, { 0x6,  0x2,  0x3,  0x7}}},
        {{{ 0x5,  0x2,  0x2,  0x0}, { 0x5,  0x2,  0x2,  0x2}, { 0x6,  0x2,  0x3,  0x0}, { 0x6,  0x2,  0x3,  0x2}}},
        {{{ 0x7,  0x3,  0x2,  0x5}, { 0x7,  0x3,  0x2,  0x7}, { 0x8,  0x3,  0x3,  0x5}, { 0x8,  0x3,  0x3,  0x7}}},
        {{{ 0x7,  0x3,  0x2,  0x0}, { 0x7,  0x3,  0x2,  0x2}, { 0x8,  0x3,  0x3,  0x0}, { 0x8,  0x3,  0x3,  0x2}}}
    },
    // chip_id 3
    {
        {{{-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}, {-0x1, -0x1, -0x1, -0x1}}},
        {{{ 0x2,  0x0,  0x3,  0x3}, { 0x2,  0x0,  0x3,  0x1}, { 0x1,  0x0,  0x2,  0x3}, { 0x1,  0x0,  0x2,  0x1}}},
        {{{ 0x2,  0x0,  0x3,  0x6}, { 0x2,  0x0,  0x3,  0x4}, { 0x1,  0x0,  0x2,  0x6}, { 0x1,  0x0,  0x2,  0x4}}},
        {{{ 0x4,  0x1,  0x3,  0x3}, { 0x4,  0x1,  0x3,  0x1}, { 0x3,  0x1,  0x2,  0x3}, { 0x3,  0x1,  0x2,  0x1}}},
        {{{ 0x3,  0x1,  0x2,  0x4}, { 0x3,  0x1,  0x2,  0x6}, { 0x4,  0x1,  0x3,  0x4}, { 0x4,  0x1,  0x3,  0x6}}},
        {{{ 0x5,  0x2,  0x2,  0x1}, { 0x5,  0x2,  0x2,  0x3}, { 0x6,  0x2,  0x3,  0x1}, { 0x6,  0x2,  0x3,  0x3}}},
        {{{ 0x5,  0x2,  0x2,  0x4}, { 0x5,  0x2,  0x2,  0x6}, { 0x6,  0x2,  0x3,  0x4}, { 0x6,  0x2,  0x3,  0x6}}},
        {{{ 0x7,  0x3,  0x2,  0x1}, { 0x7,  0x3,  0x2,  0x3}, { 0x8,  0x3,  0x3,  0x1}, { 0x8,  0x3,  0x3,  0x3}}},
        {{{ 0x7,  0x3,  0x2,  0x4}, { 0x7,  0x3,  0x2,  0x6}, { 0x8,  0x3,  0x3,  0x4}, { 0x8,  0x3,  0x3,  0x6}}}
    }
};

// 光模块视角展开 uboe
struct port_id_optical_lane_id_map_uboe g_macro_id_from_xsfp_id_map_uboe[DEV_NUM_PER_LEVEL] = {
    // {dev_id, macro_id, macro_lane_id}
    {{{0x0, 0x8, 0x0}, {0x0, 0x8, 0x1}, {0x1, 0x8, 0x0}, {0x1, 0x8, 0x1}}}, // chip_id 0
    {{{0x0, 0x9, 0x0}, {0x0, 0x9, 0x1}, {0x1, 0x9, 0x0}, {0x1, 0x9, 0x1}}}, // chip_id 1
    {{{0x2, 0x8, 0x0}, {0x2, 0x8, 0x1}, {0x3, 0x8, 0x0}, {0x3, 0x8, 0x1}}}, // chip_id 2
    {{{0x2, 0x9, 0x0}, {0x2, 0x9, 0x1}, {0x3, 0x9, 0x0}, {0x3, 0x9, 0x1}}}  // chip_id 3
};

// port口视角展开 uboe
struct optical_id_macro_laneid_map_uboe
    g_opticalid_macro_lane_id_map_table_uboe[DEV_NUM_PER_LEVEL][PER_NPU_PORT_UBOE] = {
    // chip_id 0
    {
        // {光模块丝印编码，光模块逻辑id，主控该光模块的模组槽位号，port口的lane对应光模块的lane}
        {{{0x1,  0x4,  0x0,  0x0}, {0x1,  0x4,  0x0,  0x1}}}, // macro 8
        {{{0x2,  0x4,  0x1,  0x0}, {0x2,  0x4,  0x1,  0x1}}}  // macro 9
    },
    // chip_id 1
    {
        {{{0x1,  0x4,  0x0,  0x2}, {0x1,  0x4,  0x0,  0x3}}},
        {{{0x2,  0x4,  0x1,  0x2}, {0x2,  0x4,  0x1,  0x3}}}
    },
    // chip_id 2
    {
        {{{0x1,  0x4,  0x2,  0x0}, {0x1,  0x4,  0x2,  0x1}}},
        {{{0x2,  0x4,  0x3,  0x0}, {0x2,  0x4,  0x3,  0x1}}}
    },
    // chip_id 3
    {
        {{{0x1,  0x4,  0x2,  0x2}, {0x1,  0x4,  0x2,  0x3}}},
        {{{0x2,  0x4,  0x3,  0x2}, {0x2,  0x4,  0x3,  0x3}}}
    }
};

struct optical_id_silk_screen_num_map g_slot0_optical_id_silk_screen_num_map[FIVE_NUM] = {
    {"Optical_9",       0, "800G", "UB"},
    {"Optical_11",      1, "800G", "UB"},
    {"Optical_13",      2, "800G", "UB"},
    {"Optical_15",      3, "800G", "UB"},
    {"FLEX1_Optical_1", 4, "400G", "UBOE"},
};

struct optical_id_silk_screen_num_map g_slot1_optical_id_silk_screen_num_map[FIVE_NUM] = {
    {"Optical_10",      0, "800G", "UB"},
    {"Optical_12",      1, "800G", "UB"},
    {"Optical_14",      2, "800G", "UB"},
    {"Optical_16",      3, "800G", "UB"},
    {"FLEX1_Optical_2", 4, "400G", "UBOE"},
};

struct optical_id_silk_screen_num_map g_slot2_optical_id_silk_screen_num_map[FIVE_NUM] = {
    {"Optical_1",       0, "800G", "UB"},
    {"Optical_3",       1, "800G", "UB"},
    {"Optical_5",       2, "800G", "UB"},
    {"Optical_7",       3, "800G", "UB"},
    {"FLEX2_Optical_1", 4, "400G", "UBOE"},
};

struct optical_id_silk_screen_num_map g_slot3_optical_id_silk_screen_num_map[FIVE_NUM] = {
    {"Optical_2",       0, "800G", "UB"},
    {"Optical_4",       1, "800G", "UB"},
    {"Optical_6",       2, "800G", "UB"},
    {"Optical_8",       3, "800G", "UB"},
    {"FLEX2_Optical_2", 4, "400G", "UBOE"},
};

static int tool_get_dev_lane_id_by_optical_lane_id(int dev_id, int port_index, int optical_id, int optical_lane_id,
    int *lane_id)
{
    int i;

    for (i = 0; i < LANE_PER_NPU_PORT; i++) {
        if (g_portid_lane_id_map_table[dev_id][port_index].optical_lane_id[i].optical_id == optical_id &&
            g_portid_lane_id_map_table[dev_id][port_index].optical_lane_id[i].optical_lane_id == optical_lane_id) {
            *lane_id = i;
            return 0;
        }
    }

    return TOOL_INVALID_PARAM;
}

static int tool_get_used_info_uboe(struct command_context *ctx, int lane_id, char *buff, int buff_len)
{
    int ret = 0, slot_id_print = 0, macro_id = 0, macro_lane_id = 0;
    int die_id = (tool_is_ascend950_A_K_2_4(ctx) ? 0 : 1);
    int slot_id = ctx->slot_id;

    if (buff == NULL) {
        hccn_err("get invalid buff.\n");
        return TOOL_INVALID_PARAM;
    }

    int tmp_slot_id = (slot_id >= MAX_CHIP_NUM) ? (slot_id - MAX_CHIP_NUM) : slot_id;
    slot_id_print = (slot_id >= MAX_CHIP_NUM) ?
                   (g_macro_id_from_xsfp_id_map_uboe[tmp_slot_id].optical_lane[lane_id].chip_id + MAX_CHIP_NUM) :
                    g_macro_id_from_xsfp_id_map_uboe[tmp_slot_id].optical_lane[lane_id].chip_id;
    macro_id = g_macro_id_from_xsfp_id_map_uboe[tmp_slot_id].optical_lane[lane_id].macro_id;
    macro_lane_id = g_macro_id_from_xsfp_id_map_uboe[tmp_slot_id].optical_lane[lane_id].macro_lane_id;

    ret = sprintf_s(buff, buff_len, "npu%d_die%d_port%d_lane%d", slot_id_print, die_id, macro_id, macro_lane_id);
    if (ret < 0) {
        hccn_err("sprintf_s failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_get_used_info_0_8(int slot_id, int optical_id, int lane_id, char *buff, int buff_len)
{
    int ret = 0;
    int slot_id_print = 0, macro_id = 0, macro_lane_id = 0;
    int die_id = 0;
    if (buff == NULL) {
        hccn_err("get invalid buff.\n");
        return TOOL_INVALID_PARAM;
    }
    int tmp_slot_id = (slot_id >= MAX_CHIP_NUM) ? (slot_id - MAX_CHIP_NUM) : slot_id;
    slot_id_print = (slot_id >= MAX_CHIP_NUM) ?
                   (g_macro_id_from_xsfp_id_map[tmp_slot_id][optical_id].optical_lane[lane_id].chip_id + MAX_CHIP_NUM) :
                    g_macro_id_from_xsfp_id_map[tmp_slot_id][optical_id].optical_lane[lane_id].chip_id;
    macro_id = g_macro_id_from_xsfp_id_map[tmp_slot_id][optical_id].optical_lane[lane_id].macro_id;
    macro_lane_id = g_macro_id_from_xsfp_id_map[tmp_slot_id][optical_id].optical_lane[lane_id].macro_lane_id;
    ret = sprintf_s(buff, buff_len, "npu%d_die%d_port%d_lane%d", slot_id_print, die_id, macro_id, macro_lane_id);
    if (ret < 0) {
        hccn_err("sprintf_s failed. (ret=%d)", ret);
        return ret;
    }
    return 0;
}

static int tool_get_used_by(struct command_context *ctx, int lane_id, int lane_num, char *buff, int buff_len)
{
    int i, j, ret = -1; // 初始化为负数，接口最后判断为非负则为成功
    int optical_phy_id = 0;
    int dev_lane_id;
    int slot_id_print;
    int slot_id = ctx->slot_id, optical_id = ctx->optical_id;
    int slot_id_temp = slot_id % DEV_NUM_PER_LEVEL;

    if (lane_num == QSFP_LANE_NUM) {
        ret = tool_get_used_info_uboe(ctx, lane_id, buff, buff_len);
        return ret;
    }

    if (tool_is_ascend950_A_K_0_8(ctx) == true) {
        ret = tool_get_used_info_0_8(slot_id, optical_id, lane_id, buff, buff_len);
        return ret;
    }

    for (i = 0; i < (sizeof(g_optical_id_map) / sizeof(g_optical_id_map[0])); i++) {
        if ((g_optical_id_map[i].phy_dev_id == slot_id_temp) && (g_optical_id_map[i].optical_logic_id == optical_id)) {
            // 模块内使用，调用处保证入参合法性
            optical_phy_id = g_optical_id_map[i].optical_phy_id;
            break;
        }
    }

    for (i = 0; i < DEV_NUM_PER_LEVEL; i++) {
        for (j = 0; j < PER_DEV_USE_OPTICAL_2_4; j++) {
            if (!tool_get_dev_lane_id_by_optical_lane_id(i, j, optical_phy_id, lane_id, &dev_lane_id)) {
                // 判断是哪层抽屉，上层抽屉则+4
                slot_id_print = (slot_id >= MAX_CHIP_NUM) ? (i + MAX_CHIP_NUM) : i;
                ret = sprintf_s(buff, buff_len, "npu%d_die%d_port%d_lane%d", slot_id_print,
                    g_portid_lane_id_map_table[i][j].udie_id,
                    g_portid_lane_id_map_table[i][j].port_id, dev_lane_id);
            }
        }
    }

    if (ret < 0) {
        hccn_err("sprintf_s failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_set_optical_table_temperature(struct command_context *ctx, xsfp_module_info xsfp_info, int row)
{
    int ret = 0;
    int temp_neo, temp_h = 0, temp_l = 0; // imp层将负数转成正数，此处需要转回负数

    ret += SET_ENTIRE_ROW(row, ctx->npu_info.logic_id, ctx->optical_id, "Temperature(C)",
        NULL, NULL, NULL, NULL, NULL, NULL, "-");
    temp_neo = xsfp_info.dynamic_data.temperature / TEMP_BYTE_OFFSET;
    ret += SET_TABLE(row, "Value", "%d", temp_neo);
    temp_h = xsfp_info.threshold_data.temp_high_alarm_threshold / TEMP_BYTE_OFFSET;
    ret += SET_TABLE(row, "HighAlarm", "%d", temp_h);
    temp_l = xsfp_info.threshold_data.temp_high_threshold / TEMP_BYTE_OFFSET;
    ret += SET_TABLE(row, "HighWarn", "%d", temp_l);
    temp_l = xsfp_info.threshold_data.temp_low_threshold / TEMP_BYTE_OFFSET;
    ret += SET_TABLE(row, "LowWarn", "%d", temp_l);
    temp_l = xsfp_info.threshold_data.temp_low_alarm_threshold / TEMP_BYTE_OFFSET;
    ret += SET_TABLE(row, "LowAlarm", "%d", temp_l);
    ret += SET_TABLE(row, "Used_by", "-");
    ret += SET_TABLE(row, "Status", (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(temp_neo, temp_h, temp_l)) ?
                     "Normal" : "Abnormal");
    if (ret) {
        hccn_err("failed to set optical temperature table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_voltage(struct command_context *ctx, xsfp_module_info xsfp_info, int row)
{
    int ret = 0;

    ret += SET_ENTIRE_ROW(row, ctx->npu_info.logic_id, ctx->optical_id, "Voltage(V)",
        NULL, NULL, NULL, NULL, NULL, NULL, "-");
    ret += SET_TABLE(row, "Value", "%.4f",
        (float)xsfp_info.dynamic_data.voltage / OPTICAL_VCC_DEVISOR);
    ret += SET_TABLE(row, "HighAlarm", "%.4f",
        (float)xsfp_info.threshold_data.vcc_high_alarm_threshold / OPTICAL_VCC_DEVISOR);
    ret += SET_TABLE(row, "HighWarn", "%.4f",
        (float)xsfp_info.threshold_data.vcc_high_threshold / OPTICAL_VCC_DEVISOR);
    ret += SET_TABLE(row, "LowWarn", "%.4f",
        (float)xsfp_info.threshold_data.vcc_low_threshold / OPTICAL_VCC_DEVISOR);
    ret += SET_TABLE(row, "LowAlarm", "%.4f",
        (float)xsfp_info.threshold_data.vcc_low_alarm_threshold / OPTICAL_VCC_DEVISOR);
    ret += SET_TABLE(row, "Used_by", "-");
    ret += SET_TABLE(row, "Status", (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(xsfp_info.dynamic_data.voltage,
        xsfp_info.threshold_data.vcc_high_alarm_threshold, xsfp_info.threshold_data.vcc_low_alarm_threshold)) ?
        "Normal" : "Abnormal");
    if (ret) {
        hccn_err("failed to set optical voltage table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_bias(struct command_context *ctx, xsfp_module_info xsfp_info, int start_row,
    int lane_num)
{
    int ret = 0, i;
    char buff[TOOL_USER_BY_STR_LEN] = {0};
    int buff_len = TOOL_USER_BY_STR_LEN;
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->optical_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ret += SET_TABLE(start_row + i, "Items", "Bias Lane%d(mA)", i);
        if (xsfp_info.base_data.optical_type == XSFP_PRODUCT_OSFP_ACC) {
            ret += xsfp_set_absent_table_info(start_row + i, table_formats, sizeof(table_formats) / sizeof(char *));
        } else {
            ret += SET_TABLE(start_row + i, "Value", "%.4f",
                (float)xsfp_info.dynamic_data.dp_info[i].tx_bias / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(start_row + i, "HighAlarm", "%.4f",
                (float)xsfp_info.threshold_data.tx_bias_high_alarm_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(start_row + i, "HighWarn", "%.4f",
                (float)xsfp_info.threshold_data.tx_bias_high_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(start_row + i, "LowWarn", "%.4f",
                (float)xsfp_info.threshold_data.tx_bias_low_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(start_row + i, "LowAlarm", "%.4f",
                (float)xsfp_info.threshold_data.tx_bias_low_alarm_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(start_row + i, "Status",
                (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(xsfp_info.dynamic_data.dp_info[i].tx_bias,
                xsfp_info.threshold_data.tx_bias_high_alarm_threshold,
                xsfp_info.threshold_data.tx_bias_low_alarm_threshold)) ? "Normal" : "Abnormal");
        }
        ret += tool_get_used_by(ctx, i, lane_num, buff, buff_len);
        ret += SET_TABLE(start_row + i, "Used_by", buff);
    }
    if (ret) {
        hccn_err("failed to set optical bias table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_tx_power(struct command_context *ctx, xsfp_module_info xsfp_info, int start_row,
    int lane_num)
{
    int ret = 0, i;
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->optical_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, "-");
        ret += SET_TABLE(start_row + i, "Items", "TxPower Lane%d(dBm)", i);
        ret += SET_TABLE(start_row + i, "Value", "%.4f",
            MW_TO_DBM((float)xsfp_info.dynamic_data.dp_info[i].tx_power / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "HighAlarm", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.tx_power_high_alarm_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "HighWarn", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.tx_power_high_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "LowWarn", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.tx_power_low_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "LowAlarm", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.tx_power_low_alarm_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "Status",
            (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(xsfp_info.dynamic_data.dp_info[i].tx_power,
            xsfp_info.threshold_data.tx_power_high_alarm_threshold,
            xsfp_info.threshold_data.tx_power_low_alarm_threshold)) ? "Normal" : "Abnormal");
    }
    if (ret) {
        hccn_err("failed to set optical tx power table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_rx_power(struct command_context *ctx, xsfp_module_info xsfp_info, int start_row,
    int lane_num)
{
    int ret = 0, i;
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->optical_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, "-");
        ret += SET_TABLE(start_row + i, "Items", "RxPower Lane%d(dBm)", i);
        ret += SET_TABLE(start_row + i, "Value", "%.4f",
            MW_TO_DBM((float)xsfp_info.dynamic_data.dp_info[i].rx_power / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "HighAlarm", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.rx_power_high_alarm_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "HighWarn", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.rx_power_high_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "LowWarn", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.rx_power_low_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "LowAlarm", "%.4f",
            MW_TO_DBM((float)xsfp_info.threshold_data.rx_power_low_alarm_threshold / OPTICAL_POWER_DEVISOR));
        ret += SET_TABLE(start_row + i, "Status",
            (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(xsfp_info.dynamic_data.dp_info[i].rx_power,
            xsfp_info.threshold_data.rx_power_high_alarm_threshold,
            xsfp_info.threshold_data.rx_power_low_alarm_threshold)) ? "Normal" : "Abnormal");
    }
    if (ret) {
        hccn_err("failed to set optical rx power table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_host_snr_vpp(struct command_context *ctx, xsfp_module_info xsfp_info, int start_row,
    int lane_num)
{
    int ret = 0, i;
    double snr_vpp_value = 0;
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->optical_id,
            NULL, NULL, "-", "-", "-", "-", "-", "-");
        if (xsfp_info.base_data.optical_type == XSFP_PRODUCT_LPO)  {
            ret += SET_TABLE(start_row + i, "Items", "TxVPP Lane%d(mV)", i);
            snr_vpp_value = VPP_TO_MV(xsfp_info.dynamic_data.vdm_info.lanes[i].tx_vpp);
        } else {
            ret += SET_TABLE(start_row + i, "Items", "HostSNR Lane%d(dB)", i);
            snr_vpp_value = (double)xsfp_info.dynamic_data.dp_info[i].host_snr / OPTICAL_SNR_OFFSET;
        }
        ret += SET_TABLE(start_row + i, "Value", "%.4f", snr_vpp_value);
        ret += SET_TABLE(start_row + i, "HighAlarm", "-");
        ret += SET_TABLE(start_row + i, "HighWarn", "-");
        ret += SET_TABLE(start_row + i, "LowWarn", "-");
        ret += SET_TABLE(start_row + i, "LowAlarm", "-");
        ret += SET_TABLE(start_row + i, "Status", "-");
        ret += SET_TABLE(start_row + i, "Used_by", "-");
    }
    if (ret) {
        hccn_err("failed to set optical host snr table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_media_snr_vpp(struct command_context *ctx, xsfp_module_info xsfp_info, int start_row,
    int lane_num)
{
    int ret = 0, i;
    double snr_vpp_value = 0;
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->optical_id,
            NULL, NULL, "-", "-", "-", "-", "-", "-");
        if (xsfp_info.base_data.optical_type == XSFP_PRODUCT_LPO)  {
            ret += SET_TABLE(start_row + i, "Items", "RxVPP Lane%d(mV)", i);
            snr_vpp_value = VPP_TO_MV(xsfp_info.dynamic_data.vdm_info.lanes[i].rx_vpp);
        } else {
            ret += SET_TABLE(start_row + i, "Items", "MediaSNR Lane%d(dB)", i);
            snr_vpp_value = (double)xsfp_info.dynamic_data.dp_info[i].media_snr / OPTICAL_SNR_OFFSET;
        }
        ret += SET_TABLE(start_row + i, "Value", "%.4f", snr_vpp_value);
        ret += SET_TABLE(start_row + i, "HighAlarm", "-");
        ret += SET_TABLE(start_row + i, "HighWarn", "-");
        ret += SET_TABLE(start_row + i, "LowWarn", "-");
        ret += SET_TABLE(start_row + i, "LowAlarm", "-");
        ret += SET_TABLE(start_row + i, "Status", "-");
        ret += SET_TABLE(start_row + i, "Used_by", "-");
    }
    if (ret) {
        hccn_err("failed to set optical media snr table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

typedef struct {
    const char *name;
    const char *unit;
    double scale;
    uint64_t index;  /* 在 xsfp_dp_vdm_info_t 具名数组中的位置 */
} vdm_field_desc_t;

static const struct {
    vdm_field_desc_t host_ltp;
    vdm_field_desc_t media_ltp;
} g_dp_filed_descs = {
    .host_ltp = {"HostLTP", "dB", XSFP_LTP_SCALE, GET_VDM_INFO_FIELD_INDEX(host_ltp)},
    .media_ltp = {"MediaLTP", "dB", XSFP_LTP_SCALE, GET_VDM_INFO_FIELD_INDEX(media_ltp)},
};

static int tool_set_optcial_table_dynamic_item(
    struct command_context *ctx, int row,
    const xsfp_dp_vdm_info_t *dp_vdm_info, const vdm_field_desc_t *field, int lane)
{
    double val;
    int ret = 0;

    ret += init_optical_table_row(ctx, row);
    ret += SET_TABLE(row, "Items", "%s Lane%d(%s)", field->name, lane, field->unit);
    if (dp_vdm_info != NULL) {
        val = dp_vdm_info->begin[field->index] * field->scale;
        ret += SET_TABLE(row, "Value", "%.4f", val);
    }
    if (ret) {
        hccn_err("failed to set optical table item[%s Lane%d]. (ret=%d)", field->name, lane, ret);
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_vdm_field_by_optical(
    struct command_context *ctx, const xsfp_module_info *xsfp_info,
    const vdm_field_desc_t *field, int start_row, int lane_num)
{
    const xsfp_vdm_info_t *vdm_info = &xsfp_info->dynamic_data.vdm_info;
    const xsfp_dp_vdm_info_t *dp_vdm_info;
    int valid;
    int ret;
    int i;

    valid = b8_bitmap_get_bit(vdm_info->valid_bitmap, sizeof(vdm_info->valid_bitmap), field->index);
    for (i = 0; i < lane_num; ++i) {
        dp_vdm_info = valid ? &vdm_info->lanes[i] : NULL;
        ret = tool_set_optcial_table_dynamic_item(ctx, start_row + i,
            dp_vdm_info, field, i);
        if (ret) {
            clean_table();
            return TOOL_TABLE_ERROR;
        }
    }

    return 0;
}

static int tool_set_optcial_table_vdm_field_by_port(
    struct command_context *ctx, xsfp_module_info xsfp_info_pair[2], int *optical_lane_id,
    const vdm_field_desc_t *field, int start_row, int lane_num)
{
    const xsfp_dp_vdm_info_t *dp_vdm_info;
    const xsfp_vdm_info_t *vdm_info;
    const xsfp_module_info *xsfp_info;
    const int udie_num = 2;
    int ret;
    int i;

    for (i = 0; i < lane_num; i++) {
        xsfp_info = &xsfp_info_pair[i / udie_num];
        vdm_info = &xsfp_info->dynamic_data.vdm_info;
        if (is_xsfp_present(xsfp_info) &&
            b8_bitmap_get_bit(vdm_info->valid_bitmap, sizeof(vdm_info->valid_bitmap), field->index)) {
            dp_vdm_info = &vdm_info->lanes[optical_lane_id[i % udie_num]];
        } else {
            dp_vdm_info = NULL;
        }
        ret = tool_set_optcial_table_dynamic_item(ctx, start_row + i, dp_vdm_info, field, i);
        if (ret) {
            clean_table();
            return TOOL_TABLE_ERROR;
        }
    }

    return 0;
}

static int tool_set_optcial_table_ltp_by_optical(
    struct command_context *ctx, const xsfp_module_info *xsfp_info,
    int start_row, int lane_num)
{
    const vdm_field_desc_t *host_ltp = &g_dp_filed_descs.host_ltp;
    const vdm_field_desc_t *media_ltp = &g_dp_filed_descs.media_ltp;
    int ret;

    ret = tool_set_optcial_table_vdm_field_by_optical(ctx, xsfp_info, host_ltp, start_row, lane_num);
    if (ret != 0) {
        return TOOL_TABLE_ERROR;
    }

    start_row += lane_num;
    ret = tool_set_optcial_table_vdm_field_by_optical(ctx, xsfp_info, media_ltp, start_row, lane_num);
    if (ret != 0) {
        return TOOL_TABLE_ERROR;
    }

    return 0;
}

static int tool_set_optcial_table_ltp_by_port(
    struct command_context *ctx, xsfp_module_info xsfp_info[2],
    int *optical_lane_id, int start_row, int lane_num)
{
    const vdm_field_desc_t *host_ltp = &g_dp_filed_descs.host_ltp;
    const vdm_field_desc_t *media_ltp = &g_dp_filed_descs.media_ltp;
    int ret;

    ret = tool_set_optcial_table_vdm_field_by_port(ctx, xsfp_info, optical_lane_id, host_ltp, start_row, lane_num);
    if (ret != 0) {
        return TOOL_TABLE_ERROR;
    }

    start_row += lane_num;
    ret = tool_set_optcial_table_vdm_field_by_port(ctx, xsfp_info, optical_lane_id, media_ltp, start_row, lane_num);
    if (ret != 0) {
        return TOOL_TABLE_ERROR;
    }

    return 0;
}

static void tool_digital_info_malloc_table(int lane_num, int xsfp_type)
{
    /* Temperature, Voltage, and 7 fields per lane. */
    const int table_rows_nonacc = 1 + 1 + 7 * lane_num;
    const int table_rows_acc = 8;

    const int table_row_num = xsfp_type == XSFP_PRODUCT_OSFP_ACC
                            ? table_rows_acc
                            : table_rows_nonacc;

    malloc_table_advance("IO", table_row_num, TOOL_TABLE_COL_8,
        "Items",      TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Value",      TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "HighAlarm",  TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "HighWarn",   TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "LowWarn",    TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "LowAlarm",   TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Status",     TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Used_by",    TYPE_CHARS, TOOL_TABLE_CHARS_22);

    return;
}

static int tool_set_optcial_table_nonacc_items_by_optical(
    struct command_context *ctx, xsfp_module_info xsfp_info, int row, int lane_num)
{
    int ret;

    row = row + lane_num;
    ret = tool_set_optcial_table_tx_power(ctx, xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }
    row = row + lane_num;
    ret = tool_set_optcial_table_rx_power(ctx, xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }
    row = row + lane_num;
    ret = tool_set_optcial_table_host_snr_vpp(ctx, xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }
    row = row + lane_num;
    ret = tool_set_optcial_table_media_snr_vpp(ctx, xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }
    row = row + lane_num;
    ret = tool_set_optcial_table_ltp_by_optical(ctx, &xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }

    return 0;
}

static int tool_optical_info_print_optical_id_mode_digital_info(struct command_context *ctx, xsfp_module_info xsfp_info)
{
    int ret = 0, row, lane_num = xsfp_info.config_data.lane_num, xsfp_type = xsfp_info.base_data.optical_type;
    if ((lane_num != QSFP_LANE_NUM) && (lane_num != OSFP_LANE_NUM)) {
        hccn_err("invalid lane num. (lane_num=%d)", lane_num);
        return TOOL_INVALID_PARAM;
    }

    tool_digital_info_malloc_table(lane_num, xsfp_type);

    // 函数内clean table
    row = TOOL_START_ROW_NUM0;
    if (xsfp_type != XSFP_PRODUCT_OSFP_ACC) {
        ret = tool_set_optical_table_temperature(ctx, xsfp_info, row);
        if (ret) {
            return ret;
        }
        row = row + TOOL_START_ROW_NUM1;
        ret = tool_set_optcial_table_voltage(ctx, xsfp_info, row);
        if (ret) {
            return ret;
        }
        row = row + TOOL_START_ROW_NUM1;
    }
    ret = tool_set_optcial_table_bias(ctx, xsfp_info, row, lane_num);
    if (ret) {
        return ret;
    }
    if (xsfp_type != XSFP_PRODUCT_OSFP_ACC) {
        ret = tool_set_optcial_table_nonacc_items_by_optical(ctx, xsfp_info, row, lane_num);
        if (ret) {
            return ret;
        }
    }

    print_table();
    clean_table();
    return 0;
}

static int tool_optical_info_print_optical_id_mode(struct command_context *ctx, xsfp_module_info xsfp_info)
{
    int ret = 0;

    ret += tool_optical_info_print_optical_id_mode_base_info(ctx, xsfp_info);
    if (xsfp_info.config_data.master_xsfp_present != 1) { // 光模块不在位后续信息不再打印
        return 0;
    }
    ret += tool_optical_info_print_optical_id_mode_vendor_info(ctx, xsfp_info);
    if (xsfp_info.base_data.optical_type != XSFP_PRODUCT_OSFP_ACC) {
        ret += tool_optical_info_print_optical_id_mode_status(ctx, xsfp_info);
    }
    ret += tool_optical_info_print_optical_id_mode_digital_info(ctx, xsfp_info);
    return ret;
}

static int tool_get_optical_info_by_logic_id(struct command_context *ctx, int optical_id, xsfp_module_info *xsfp_info)
{
    struct product_channel_msg msg = {0};
    int ret = 0;
    optical_data_request *req = NULL;
    int i;

    optical_data_request optical_data_requests[] = {
        { &xsfp_info->base_data,          sizeof(xsfp_info->base_data),         CMD_OPTICAL_OPERATE_BASE_DATA },
        { &xsfp_info->xsfp_capabilities,  sizeof(xsfp_info->xsfp_capabilities), CMD_OPTICAL_OPERATE_XSFP_CAPABILITIES },
        { &xsfp_info->config_data,        sizeof(xsfp_info->config_data),       CMD_OPTICAL_OPERATE_CONFIG_DATA },
        { &xsfp_info->manufacture_data,   sizeof(xsfp_info->manufacture_data),  CMD_OPTICAL_OPERATE_MANUFACTURE_DATA },
        { &xsfp_info->threshold_data,     sizeof(xsfp_info->threshold_data),    CMD_OPTICAL_OPERATE_THRESHOLD_DATA },
        { &xsfp_info->dynamic_data,       sizeof(xsfp_info->dynamic_data),      CMD_OPTICAL_OPERATE_DYNAMIC_DATA }
    };

    // 遍历所有要获取的数据项
    for (i = 0; i < sizeof(optical_data_requests) / sizeof(optical_data_requests[0]); i++) {
        req = &optical_data_requests[i];

        // 设置 H2D 消息：optical_id + 数据区域
        SET_PRODUCT_MSG(msg, &optical_id, sizeof(int), req->data_ptr, req->data_size);

        // 下发命令获取数据
        ret = product_host_device_channel(ctx, req->cmd_id, &msg);
        if (ret) {
            hccn_err("failed to get optical data. (cmd=%u, ret=%d)", req->cmd_id, ret);
            return ret;
        }
    }

    return 0;
}

static int tool_optical_upgrade_exec(struct command_context *ctx)
{
    int ret;
    int max_optical_id;
    int row_num;
    struct optical_param_t *args = NULL;
    struct optical_upgrade_result result = {0};
    bool has_path = false;
    bool has_upgrade = false;

    args = (struct optical_param_t *)ctx->cmd_args;

    // 检查 -path 和 -upgrade 是否成对出现
    has_path = (args->firmware_path[0] != '\0');
    has_upgrade = (args->info.test_mode == CMD_OPTICAL_UPGRADE_FIRMWARE);

    // 如果两个选项只有一个被指定，报错
    if (has_path != has_upgrade) {
        TOOL_PRINT_ERR("Option -path and -upgrade must be used together.");
        return TOOL_INVALID_PARAM;
    }

    // 根据mainboard_id获取有效的optical_id范围
    ret = tool_optical_get_table_row_num_by_mainboard_id(ctx->npu_info.mainboard_id, &row_num);
    if (ret) {
        hccn_err("get table row num failed by mainboard_id failed (ret=%d)", ret);
        TOOL_PRINT_INFO("optical upgrade is not supported on this board type.");
        return ret;
    }
    // row_num表示光模块数量，有效optical_id范围为0到row_num-1
    max_optical_id = row_num - 1;

    if (ctx->optical_id < 0 || ctx->optical_id > max_optical_id) {
        hccn_err("Invalid optical_id: %d, valid range is 0-%d", ctx->optical_id, max_optical_id);
        TOOL_PRINT_INFO("Invalid optical_id: %d, valid range is 0-%d.", ctx->optical_id, max_optical_id);
        return TOOL_INVALID_PARAM;
    }

    ret = dsmi_optical_upgrade_firmware(ctx, args->firmware_path, PATH_MAX, &result);
    if (ret) {
        hccn_err("Optical upgrade failed. (ret=%d)", ret);
        return ret;
    }

    TOOL_PRINT_INFO("Optical upgrade success!");
    return 0;
}

static int tool_optical_exec_optical_id_mode(struct command_context *ctx)
{
    xsfp_module_info xsfp_info = {0};
    int ret = 0;
    
    if (ctx->mode == MODE_GET) {
        ret = tool_get_optical_info_by_logic_id(ctx, ctx->optical_id, &xsfp_info);
        if (ret) {
            hccn_err("failed to get optical info by logic id. (ret=%d)", ret);
            return ret;
        }
 
        // 所有数据获取成功后，打印信息
        ret = tool_optical_info_print_optical_id_mode(ctx, xsfp_info);
        if (ret) {
            hccn_err("failed to print optical info. (ret=%d)", ret);
        }
    } else if (ctx->mode == MODE_SET) {
        ret = hccn_check_usr_identify();
        if (ret != 0) {
            hccn_err("permission denied: only root user is allowed, ret:%d dev_id:%d", ret, ctx->dev_id);
            return TOOL_PUBLIC_ROOT_UNSUPPORT;
        }
        ret = tool_optical_upgrade_exec(ctx);
        if (ret) {
            hccn_err("tool_optical_upgrade_exec failed. (ret=%d)", ret);
        }
    } else {
        ret = tool_test_optical_exec(ctx);
        if (ret) {
            hccn_err("tool_test_optical_exec failed. (ret=%d)", ret);
        }
    }

    return ret;
}

static int tool_optical_get_table_row_num_by_mainboard_id(unsigned int mainborad_id, int* row_num)
{
    int ret = 0;

    switch (mainborad_id) {
        case MAINBOARD_ID_950_KP_0_8_UB:
            *row_num = TOOL_TABLE_ROW_4;
            break;
        case MAINBOARD_ID_950_KP_0_8_UBOE:
            *row_num = TOOL_TABLE_ROW_5;
            break;
        case MAINBOARD_ID_950_KP_0_0_UBOE:
            *row_num = TOOL_TABLE_ROW_1;
            break;
        default:
            hccn_info("mainborad_id is invalid, mainborad_id = 0x%x", mainborad_id);
            ret = TOOL_TABLE_ERROR;
            break;
    }
    return ret;
}

static int tool_optical_set_table_by_dev_id_and_row_num(int dev_id, int row_num)
{
#define UBOE_INDEX_IN_MAP 4

    int ret = 0;
    int npu_slot_id;
    struct optical_id_silk_screen_num_map* map;

    npu_slot_id = dev_id % DEV_NUM_PER_LEVEL;
    switch (npu_slot_id) {
        case CHIP_ID_0:
            map = g_slot0_optical_id_silk_screen_num_map;
            break;
        case CHIP_ID_1:
            map = g_slot1_optical_id_silk_screen_num_map;
            break;
        case CHIP_ID_2:
            map = g_slot2_optical_id_silk_screen_num_map;
            break;
        case CHIP_ID_3:
            map = g_slot3_optical_id_silk_screen_num_map;
            break;
        default:
            ret = TOOL_TABLE_ERROR;
            hccn_info("npu_id %d is invalid, ret=%d", dev_id, ret);
            return ret;
    }

    if (row_num == TOOL_TABLE_ROW_4 || row_num == TOOL_TABLE_ROW_5) {
        for (int i = 0; i < row_num; i++) {
            ret += SET_ENTIRE_ROW(i, dev_id + 1, NULL, map[i].optical_id, NULL, NULL);
            ret += SET_TABLE(i, "Optical silk screen num", "%s", map[i].screen_num);
            ret += SET_TABLE(i, "Speed", "%s", map[i].speed);
            ret += SET_TABLE(i, "Used for", "%s", map[i].used_mode);
        }
    } else if (row_num == TOOL_TABLE_ROW_1) {
        ret += SET_ENTIRE_ROW(0, dev_id + 1, NULL, map[UBOE_INDEX_IN_MAP].optical_id, NULL, NULL);
        ret += SET_TABLE(0, "Optical silk screen num", "%s", map[UBOE_INDEX_IN_MAP].screen_num);
        ret += SET_TABLE(0, "Speed", "%s", map[UBOE_INDEX_IN_MAP].speed);
        ret += SET_TABLE(0, "Used for", "%s", map[UBOE_INDEX_IN_MAP].used_mode);
    } else {
        ret = TOOL_TABLE_ERROR;
        hccn_err("row_num %d is invalid, ret=%d", row_num, ret);
    }

    return ret;
}

static int tool_optical_exec_device_id_mode(struct command_context *ctx)
{
    int ret = 0;
    int row_num;
    int slot_id = ctx->slot_id;
    unsigned int mainborad_id;

    mainborad_id = ctx->npu_info.mainboard_id;

    ret = tool_optical_get_table_row_num_by_mainboard_id(mainborad_id, &row_num);
    if (ret) {
        hccn_err("get table row num failed by mainborad_id failed (ret=%d)", ret);
        return ret;
    }

    malloc_table_advance("I", row_num, TOOL_TABLE_COL_4,
        "Optical silk screen num",     TYPE_CHARS, TOOL_TABLE_CHARS_18,
        "Optical id",                  TYPE_UINT,
        "Speed",                       TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Used for",                    TYPE_CHARS, TOOL_TABLE_CHARS_10);

    ret = tool_optical_set_table_by_dev_id_and_row_num(slot_id, row_num);
    if (ret) {
        hccn_err("set table by dev_id and row num failed (ret=%d)", ret);
        clean_table();
        return ret;
    }

    print_table();
    clean_table();

    return ret;
}

static int tool_get_optical_lane_info_by_port_id(int phy_slot_id, int udie_id, int port_id, int *optical_id,
    int *optical_lane_id)
{
    int i;
    int slot_id_temp = phy_slot_id % DEV_NUM_PER_LEVEL; // 0~3为下层抽屉，4~7位上层抽屉，对应关系一致

    if ((phy_slot_id < 0) || (phy_slot_id >= (DEV_NUM_PER_LEVEL * 0x2))) {
        hccn_err("phy_dev_id is invalid. (phy_dev_id=%d)", phy_slot_id);
        return TOOL_INVALID_PARAM;
    }

    for (i = 0; i < PER_DEV_USE_OPTICAL_2_4; i++) {
        if ((udie_id == g_portid_lane_id_map_table[slot_id_temp][i].udie_id) &&
            (port_id == g_portid_lane_id_map_table[slot_id_temp][i].port_id)) {
                optical_id[0] = g_portid_lane_id_map_table[slot_id_temp][i].optical_lane_id[0].optical_id;
                optical_id[1] = g_portid_lane_id_map_table[slot_id_temp][i].optical_lane_id[0x2].optical_id;
                optical_lane_id[0] =
                    g_portid_lane_id_map_table[slot_id_temp][i].optical_lane_id[0].optical_lane_id;
                optical_lane_id[1] =
                    g_portid_lane_id_map_table[slot_id_temp][i].optical_lane_id[1].optical_lane_id;
                return 0;
            }
    }

    hccn_err("get optical id by port id failed.");
    return TOOL_INVALID_PARAM;
}

static int tool_get_master_dev_id_by_phy_optical_id(int optical_id, int *phy_dev_id, int *optical_logic_id,
    int ori_slot_id)
{
    int i;
    for (i = 0; i < (sizeof(g_optical_id_map) / sizeof(g_optical_id_map[0])); i++) {
        if (g_optical_id_map[i].optical_phy_id == optical_id) {
            *phy_dev_id = (ori_slot_id >= MAX_CHIP_NUM) ?
                (g_optical_id_map[i].phy_dev_id + MAX_CHIP_NUM) : g_optical_id_map[i].phy_dev_id;
            *optical_logic_id = g_optical_id_map[i].optical_logic_id;
            return 0;
        }
    }
    return TOOL_INVALID_PARAM;
}

static int tool_get_optical_info_by_phy_optical_id(struct command_context *ctx, int optical_id,
    xsfp_module_info *xsfp_info)
{
    int ret;
    int master_phy_dev_id;
    int optical_logic_id;

    ret = tool_get_master_dev_id_by_phy_optical_id(optical_id, &master_phy_dev_id, &optical_logic_id, ctx->slot_id);
    if (ret) {
        hccn_err("get master dev id by phy optical id failed. (ret=%d)", ret);
        return ret;
    }

    master_phy_dev_id = xsfp_get_peer_dev_id_by_slot_id(ctx->dev_id, master_phy_dev_id);
    // imp侧由dev_id和optical_id确定哪个imp
    ret = drvDeviceGetIndexByPhyId(master_phy_dev_id, (unsigned int*)&ctx->npu_info.logic_id);
    if (ret) {
        hccn_err("failed to get dev logic id. (ret=%d; master_phy_dev_id=%d)", ret, master_phy_dev_id);
        return ret;
    }
    ret = tool_get_optical_info_by_logic_id(ctx, optical_logic_id, xsfp_info);
    if (ret) {
        hccn_err("failed to get optical info by logic id. (ret=%d)", ret);
    }

    return ret;
}

static char* get_status_string(int status, int lane_id)
{
    return (status & (1 << lane_id)) ? "Abnormal" : "Normal";
}

static void tool_optical_absent_info_proc(struct optical_status *status_map, xsfp_module_info *xsfp_info, int map_size)
{
    int i = 0;
    for (i = 0; i < map_size; i++) {
        if (xsfp_info[i].config_data.master_xsfp_present != 1) {
            status_map[i].rxlol = -1;
            status_map[i].txfault = -1;
            status_map[i].txlol = -1;
            status_map[i].txlos = -1;
            status_map[i].rxlos = -1;
        } else {
            status_map[i].rxlol = xsfp_info[i].dynamic_data.adapt_info.rxlol;
            status_map[i].txlol = xsfp_info[i].dynamic_data.adapt_info.txlol;
            status_map[i].rxlos = xsfp_info[i].dynamic_data.adapt_info.rxlos;
            status_map[i].txlos = xsfp_info[i].dynamic_data.adapt_info.txlos;
            status_map[i].txfault = xsfp_info[i].dynamic_data.tx_fault;
        }
    }
    return;
}

static void get_optical_status_value(int cmd_id, struct optical_status *status_map, int map_size,
                                     int *value0, int *value1)
{
    switch (cmd_id) {
        case TX_FAULT_CMD:
            *value0 = status_map[0].txfault;
            *value1 = status_map[1].txfault;
            break;
        case TX_LOS_CMD:
            *value0 = status_map[0].txlos;
            *value1 = status_map[1].txlos;
            break;
        case RX_LOS_CMD:
            *value0 = status_map[0].rxlos;
            *value1 = status_map[1].rxlos;
            break;
        case TX_LOL_CMD:
            *value0 = status_map[0].txlol;
            *value1 = status_map[1].txlol;
            break;
        case RX_LOL_CMD:
            *value0 = status_map[0].rxlol;
            *value1 = status_map[1].rxlol;
            break;
        default:
            hccn_err("get invalid cmd %d.\n", cmd_id);
            break;
    }
    return;
}

static int tool_optical_info_print_port_id_mode_status(struct command_context *ctx, xsfp_module_info *xsfp_info,
    int xsfp_info_num, int *optical_lane_id)
{
    int ret = 0, cmd_num = 0, i = 0, value0 = 0, value1 = 0, row_num = 0;

    // 约束互助的两个光模块必须插同一类型的，不允许混插
    row_num = (xsfp_info[0].base_data.optical_type == XSFP_PRODUCT_LPO ||
               xsfp_info[1].base_data.optical_type == XSFP_PRODUCT_LPO) ? TOOL_TABLE_ROW_3 : TOOL_TABLE_ROW_5;

    if (xsfp_info_num == TOOL_USED_BY_OPTICAL_SUM) {
        malloc_table_advance("IUP", row_num, TOOL_TABLE_COL_5,
            "Items",      TYPE_STR,
            "Lane0",      TYPE_STR,
            "Lane1",      TYPE_STR,
            "Lane2",      TYPE_STR,
            "Lane3",      TYPE_STR);
    } else {
        malloc_table_advance("IUP", row_num, TOOL_TABLE_COL_3,
            "Items",      TYPE_STR,
            "Lane0",      TYPE_STR,
            "Lane1",      TYPE_STR);
    }

    char* flag_map[TOOL_FLAG_MAP_NUM] = {
        "TxFault Flag", "TxLos Flag", "RxLos Flag",
        "TxLol Flag", "RxLol Flag"
    };

    struct optical_status status_map[TOOL_USED_BY_OPTICAL_SUM] = {0};
    tool_optical_absent_info_proc(status_map, xsfp_info, TOOL_USED_BY_OPTICAL_SUM);

    cmd_num = (xsfp_info[0].base_data.optical_type == XSFP_PRODUCT_LPO ||
               xsfp_info[1].base_data.optical_type == XSFP_PRODUCT_LPO) ? THREE_NUM : TOOL_FLAG_MAP_NUM;
    for (i = 0; i < cmd_num; i++) {
        get_optical_status_value(i, status_map, TOOL_USED_BY_OPTICAL_SUM, &value0, &value1);
        if (xsfp_info_num == TOOL_USED_BY_OPTICAL_SUM) {
            ret += SET_ENTIRE_ROW(i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, flag_map[i],
                (value0 == -1) ? "-" : get_status_string(value0, optical_lane_id[0]),
                (value0 == -1) ? "-" : get_status_string(value0, optical_lane_id[1]),
                (value1 == -1) ? "-" : get_status_string(value1, optical_lane_id[0]),
                (value1 == -1) ? "-" : get_status_string(value1, optical_lane_id[1]));
        } else {
            ret += SET_ENTIRE_ROW(i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, flag_map[i],
                (value0 == -1) ? "-" : get_status_string(value0, optical_lane_id[0]),
                (value0 == -1) ? "-" : get_status_string(value0, optical_lane_id[1]));
        }
    }
    if (ret) {
        hccn_err("failed to make optical status info table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

static int tool_set_optcial_table_bias_diff_lane(struct command_context *ctx, xsfp_module_info xsfp_info[0x2],
    int optical_id[0x2], int *optical_lane_id, int lane_num)
{
#define OPTICAL_LANE_INFO_NUM  18
    int ret = 0, retval = 0, i = 0;
    char buff[OPTICAL_LANE_INFO_NUM] = {0};
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ret += SET_TABLE(i, "Items", "Bias Lane%d(mA)", i);
        if (!is_xsfp_present(&(xsfp_info[i / 0x2])) ||
            xsfp_info[i / 0x2].base_data.optical_type == XSFP_PRODUCT_OSFP_ACC) {
            ret += xsfp_set_absent_table_info(i, table_formats, sizeof(table_formats) / sizeof(char *));
        } else {
            ret += SET_TABLE(i, "Value", "%.4f",
                (float)xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].tx_bias /
                OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(i, "HighAlarm", "%.4f",
                (float)xsfp_info[i / 0x2].threshold_data.tx_bias_high_alarm_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(i, "HighWarn", "%.4f",
                (float)xsfp_info[i / 0x2].threshold_data.tx_bias_high_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(i, "LowWarn", "%.4f",
                (float)xsfp_info[i / 0x2].threshold_data.tx_bias_low_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(i, "LowAlarm", "%.4f",
                (float)xsfp_info[i / 0x2].threshold_data.tx_bias_low_alarm_threshold / OPTICAL_BIAS_DEVISOR);
            ret += SET_TABLE(i, "Status",
                (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(
                    xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].tx_bias,
                    xsfp_info[i / 0x2].threshold_data.tx_bias_high_alarm_threshold,
                    xsfp_info[i / 0x2].threshold_data.tx_bias_low_alarm_threshold)) ? "Normal" : "Abnormal");
        }
        retval += sprintf_s(buff, OPTICAL_LANE_INFO_NUM,
                            "optical_%d_lane_%d", optical_id[i / 0x2], optical_lane_id[i % 0x2]);
        if (retval < 0) {
            hccn_err("failed to set optical_lane info. (ret=%d)", retval);
        }
        ret += SET_TABLE(i, "Optical_use", "%s", buff);
        memset_s(buff, OPTICAL_LANE_INFO_NUM, 0, OPTICAL_LANE_INFO_NUM);
    }
    if (ret) {
        hccn_err("failed to set optical bias table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_tx_power_diff_lane(struct command_context *ctx, xsfp_module_info xsfp_info[0x2],
    int *optical_lane_id, int start_row, int lane_num)
{
    int ret = 0, i;
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ret += SET_TABLE(start_row + i, "Items", "TxPower Lane%d(dBm)", i);
        if (!is_xsfp_present(&(xsfp_info[i / 0x2]))) {
            ret += xsfp_set_absent_table_info(start_row + i, table_formats, sizeof(table_formats) / sizeof(char *));
        } else {
            ret += SET_TABLE(start_row + i, "Value", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].tx_power /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "HighAlarm", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.tx_power_high_alarm_threshold /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "HighWarn", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.tx_power_high_threshold / OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "LowWarn", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.tx_power_low_threshold / OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "LowAlarm", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.tx_power_low_alarm_threshold /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "Status",
                (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(
                    xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].tx_power,
                    xsfp_info[i / 0x2].threshold_data.tx_power_high_alarm_threshold,
                    xsfp_info[i / 0x2].threshold_data.tx_power_low_alarm_threshold)) ? "Normal" : "Abnormal");
        }
        ret += SET_TABLE(start_row + i, "Optical_use", "-");
    }
    if (ret) {
        hccn_err("failed to set optical tx power table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_rx_power_diff_lane(struct command_context *ctx, xsfp_module_info xsfp_info[0x2],
    int *optical_lane_id, int start_row, int lane_num)
{
    int ret = 0;
    int i;
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
            NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        ret += SET_TABLE(start_row + i, "Items", "RxPower Lane%d(dBm)", i);
        if (!is_xsfp_present(&(xsfp_info[i / 0x2]))) {
            ret += xsfp_set_absent_table_info(start_row + i, table_formats, sizeof(table_formats)/ sizeof(char *));
        } else {
            ret += SET_TABLE(start_row + i, "Value", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].rx_power /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "HighAlarm", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.rx_power_high_alarm_threshold /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "HighWarn", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.rx_power_high_threshold / OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "LowWarn", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.rx_power_low_threshold / OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "LowAlarm", "%.4f",
                MW_TO_DBM((float)xsfp_info[i / 0x2].threshold_data.rx_power_low_alarm_threshold /
                          OPTICAL_POWER_DEVISOR));
            ret += SET_TABLE(start_row + i, "Status",
                (TOOL_GET_OPTICAL_DIGITAL_INFO_IS_NORMAL(
                    xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].rx_power,
                    xsfp_info[i / 0x2].threshold_data.rx_power_high_alarm_threshold,
                    xsfp_info[i / 0x2].threshold_data.rx_power_low_alarm_threshold)) ? "Normal" : "Abnormal");
        }
        ret += SET_TABLE(start_row + i, "Optical_use", "-");
    }
    if (ret) {
        hccn_err("failed to set optical rx power table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_host_snr_vpp_diff_lane(struct command_context *ctx, xsfp_module_info xsfp_info[0x2],
    int *optical_lane_id, int start_row, int lane_num)
{
    int ret = 0, i;
    double snr_vpp_value = 0;
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
            NULL, NULL, "-", "-", "-", "-", "-", NULL);
        if (xsfp_info[0].base_data.optical_type == XSFP_PRODUCT_LPO ||
            xsfp_info[1].base_data.optical_type == XSFP_PRODUCT_LPO) {
            snr_vpp_value = VPP_TO_MV(xsfp_info[i / 0x2].dynamic_data.vdm_info.lanes[optical_lane_id[i % 0x2]].tx_vpp);
            ret += SET_TABLE(start_row + i, "Items", "TxVPP Lane%d(mV)", i);
        } else {
            ret += SET_TABLE(start_row + i, "Items", "HostSNR Lane%d(dB)", i);
            snr_vpp_value = (double)(xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].host_snr)
                / OPTICAL_SNR_OFFSET;
        }
        if (!is_xsfp_present(&(xsfp_info[i / 0x2]))) {
            ret += xsfp_set_absent_table_info(start_row + i, table_formats, sizeof(table_formats)/ sizeof(char *));
        } else {
            ret += SET_TABLE(start_row + i, "Value", "%.4f", snr_vpp_value);
            ret += SET_TABLE(start_row + i, "HighAlarm", "-");
            ret += SET_TABLE(start_row + i, "HighWarn", "-");
            ret += SET_TABLE(start_row + i, "LowWarn", "-");
            ret += SET_TABLE(start_row + i, "LowAlarm", "-");
            ret += SET_TABLE(start_row + i, "Status", "-");
        }
        ret += SET_TABLE(start_row + i, "Optical_use", "-");
    }
    if (ret) {
        hccn_err("failed to set optical host snr table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_media_snr_vpp_diff_lane(struct command_context *ctx, xsfp_module_info xsfp_info[0x2],
    int *optical_lane_id, int start_row, int lane_num)
{
    int ret = 0, i;
    double snr_vpp_value = 0;
    char *table_formats[] = {
        "Value", "HighAlarm", "HighWarn", "LowWarn", "LowAlarm", "Status"
    };
    for (i = 0; i < lane_num; i++) {
        ret += SET_ENTIRE_ROW(start_row + i, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id,
            NULL, NULL, "-", "-", "-", "-", "-", NULL);
        if (xsfp_info[0].base_data.optical_type == XSFP_PRODUCT_LPO ||
            xsfp_info[1].base_data.optical_type == XSFP_PRODUCT_LPO) {
            snr_vpp_value = VPP_TO_MV(xsfp_info[i / 0x2].dynamic_data.vdm_info.lanes[optical_lane_id[i % 0x2]].rx_vpp);
            ret += SET_TABLE(start_row + i, "Items", "RxVPP Lane%d(mV)", i);
        } else {
            ret += SET_TABLE(start_row + i, "Items", "MediaSNR Lane%d(dB)", i);
            snr_vpp_value = (double)(xsfp_info[i / 0x2].dynamic_data.dp_info[optical_lane_id[i % 0x2]].media_snr)
                / OPTICAL_SNR_OFFSET;
        }
        if (!is_xsfp_present(&(xsfp_info[i / 0x2]))) {
            ret += xsfp_set_absent_table_info(start_row + i, table_formats, sizeof(table_formats) / sizeof(char *));
        } else {
            ret += SET_TABLE(start_row + i, "Value", "%.4f", snr_vpp_value);
            ret += SET_TABLE(start_row + i, "HighAlarm", "-");
            ret += SET_TABLE(start_row + i, "HighWarn", "-");
            ret += SET_TABLE(start_row + i, "LowWarn", "-");
            ret += SET_TABLE(start_row + i, "LowAlarm", "-");
            ret += SET_TABLE(start_row + i, "Status", "-");
        }
        ret += SET_TABLE(start_row + i, "Optical_use", "-");
    }
    if (ret) {
        hccn_err("failed to set optical media snr table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    return 0;
}

static int tool_set_optcial_table_nonacc_items_by_port(
    struct command_context *ctx, xsfp_module_info *xsfp_info, int *optical_lane_id, int row, int lane_num)
{
    int ret;

    row += lane_num;
    ret = tool_set_optcial_table_tx_power_diff_lane(ctx, xsfp_info, optical_lane_id, row, lane_num);
    if (ret) {
        return ret;
    }

    row += lane_num;
    ret = tool_set_optcial_table_rx_power_diff_lane(ctx, xsfp_info, optical_lane_id, row, lane_num);
    if (ret) {
        return ret;
    }

    row += lane_num;
    ret = tool_set_optcial_table_host_snr_vpp_diff_lane(ctx, xsfp_info, optical_lane_id, row, lane_num);
    if (ret) {
        return ret;
    }

    row += lane_num;
    ret = tool_set_optcial_table_media_snr_vpp_diff_lane(ctx, xsfp_info, optical_lane_id, row, lane_num);
    if (ret) {
        return ret;
    }

    row += lane_num;
    ret = tool_set_optcial_table_ltp_by_port(ctx, xsfp_info, optical_lane_id, row, lane_num);
    if (ret) {
        return ret;
    }

    return 0;
}

static int tool_optical_info_print_port_id_mode_digital_info(struct command_context *ctx, xsfp_module_info *xsfp_info,
    int xsfp_info_num, int *optical_lane_id, int *optical_id)
{
    const int lane_field_cnt = 7;
    int ret, row_num, lane_num, row;

    if (xsfp_info_num == TOOL_USED_BY_OPTICAL_SUM) {
        lane_num = LANE_PER_NPU_PORT;
        row_num = xsfp_info[0].base_data.optical_type == XSFP_PRODUCT_OSFP_ACC
                ? TOOL_TABLE_ROW_4
                : lane_field_cnt * lane_num;
    } else {
        lane_num = LANE_PER_NPU_PORT_UBOE;
        row_num = lane_field_cnt * lane_num;
    }

    malloc_table_advance("IUP", row_num, TOOL_TABLE_COL_8,
        "Items",            TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "Value",            TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "HighAlarm",        TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "HighWarn",         TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "LowWarn",          TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "LowAlarm",         TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Status",           TYPE_CHARS, TOOL_TABLE_CHARS_10,
        "Optical_use",      TYPE_CHARS, TOOL_TABLE_CHARS_20);

    row = TOOL_START_ROW_NUM0;
    ret = tool_set_optcial_table_bias_diff_lane(ctx, xsfp_info, optical_id, optical_lane_id, lane_num);
    if (ret) {
        return ret;
    }
    if (xsfp_info[0].base_data.optical_type != XSFP_PRODUCT_OSFP_ACC) {
        ret = tool_set_optcial_table_nonacc_items_by_port(ctx, xsfp_info, optical_lane_id, row, lane_num);
        if (ret) {
            return ret;
        }
    }

    print_table();
    clean_table();
    return 0;
}

static int tool_optical_info_print_port_id_mode(struct command_context *ctx,
                                                xsfp_module_info *xsfp_info, int xsfp_info_size,
                                                int *optical_lane_id, int *optical_id)
{
    int ret = 0;

    ret += tool_optical_info_print_port_id_mode_status(ctx, xsfp_info, xsfp_info_size, optical_lane_id);
    ret += tool_optical_info_print_port_id_mode_digital_info(ctx, xsfp_info, xsfp_info_size,
                                                             optical_lane_id, optical_id);
    return ret;
}

static int tool_optical_info_print_port_id_mode_0_8(struct command_context *ctx,
                                                    xsfp_module_info *xsfp_info, int xsfp_info_size,
                                                    struct optical_info *macro_data, int macro_data_size)
{
    int ret = 0;
    int optical_lane_id[TOOL_USED_BY_OPTICAL_SUM] = {0};
    int optical_id[TOOL_USED_BY_OPTICAL_SUM] = {0};

    optical_lane_id[0] = macro_data[0].optical_lane_id;
    optical_lane_id[1] = macro_data[1].optical_lane_id;
    optical_id[0] = macro_data[0].optical_phy_id;
    optical_id[1] = macro_data[0x2].optical_phy_id;
    if (xsfp_info[0].base_data.optical_type != XSFP_PRODUCT_OSFP_ACC) {
        ret += tool_optical_info_print_port_id_mode_status(ctx, xsfp_info, xsfp_info_size, optical_lane_id);
    }
    ret += tool_optical_info_print_port_id_mode_digital_info(ctx, xsfp_info, xsfp_info_size,
                                                             optical_lane_id, optical_id);
    return ret;
}

static int tool_optical_info_print_port_id_mode_uboe(struct command_context *ctx,
                                                     xsfp_module_info *xsfp_info, int xsfp_info_size,
                                                     struct optical_info *macro_data, int macro_data_size)
{
    int ret = 0;
    int optical_lane_id[TOOL_USED_BY_OPTICAL_SUM] = {0};
    int optical_id[TOOL_USED_BY_OPTICAL_SUM] = {0};

    // 框架需要光模块信息数组大小为2，但uboe只输出一个光模块，这里只传一条信息，通过xsfp_info_size控制输出
    optical_id[0] = macro_data[0].optical_phy_id;
    optical_lane_id[0] = macro_data[0].optical_lane_id;
    optical_lane_id[1] = macro_data[1].optical_lane_id;

    ret += tool_optical_info_print_port_id_mode_status(ctx, xsfp_info, xsfp_info_size, optical_lane_id);
    ret += tool_optical_info_print_port_id_mode_digital_info(ctx, xsfp_info, xsfp_info_size,
                                                             optical_lane_id, optical_id);
    return ret;
}

static void tool_get_optical_info_by_port_id_0_8(int slot_id, int udie_id, int port_id,
                                                 struct optical_info *macro_data, int data_size)
{
    int i, chip_id = (slot_id >= MAX_CHIP_NUM) ? (slot_id - MAX_CHIP_NUM) : slot_id;

    for (i = 0; i < data_size; i++) {
        macro_data[i].optical_phy_id =
            g_opticalid_macro_lane_id_map_table[chip_id][port_id].macro_lane[i].optical_phy_id;
        macro_data[i].optical_logic_id =
            g_opticalid_macro_lane_id_map_table[chip_id][port_id].macro_lane[i].optical_logic_id;
        macro_data[i].optical_lane_id =
            g_opticalid_macro_lane_id_map_table[chip_id][port_id].macro_lane[i].optical_lane_id;
        macro_data[i].optical_master_dev_id =
            (slot_id >= MAX_CHIP_NUM) ?
            (g_opticalid_macro_lane_id_map_table[chip_id][port_id].macro_lane[i].optical_master_chip_id +
             MAX_CHIP_NUM) :
             g_opticalid_macro_lane_id_map_table[chip_id][port_id].macro_lane[i].optical_master_chip_id;
    }

    return;
}

static void tool_get_optical_info_by_port_id_uboe(int slot_id, int port_id,
                                                  struct optical_info *macro_data, int data_size)
{
    int i, chip_id = (slot_id >= MAX_CHIP_NUM) ? (slot_id - MAX_CHIP_NUM) : slot_id;
    int tmp_port_id = port_id - 0x8;

    for (i = 0; i < data_size; i++) {
        macro_data[i].optical_phy_id =
            g_opticalid_macro_lane_id_map_table_uboe[chip_id][tmp_port_id].macro_lane[i].optical_phy_id;
        macro_data[i].optical_logic_id =
            g_opticalid_macro_lane_id_map_table_uboe[chip_id][tmp_port_id].macro_lane[i].optical_logic_id;
        macro_data[i].optical_lane_id =
            g_opticalid_macro_lane_id_map_table_uboe[chip_id][tmp_port_id].macro_lane[i].optical_lane_id;
        macro_data[i].optical_master_dev_id =
            (slot_id >= MAX_CHIP_NUM) ?
            (g_opticalid_macro_lane_id_map_table_uboe[chip_id][tmp_port_id].macro_lane[i].optical_master_chip_id +
             MAX_CHIP_NUM) :
             g_opticalid_macro_lane_id_map_table_uboe[chip_id][tmp_port_id].macro_lane[i].optical_master_chip_id;
    }

    return;
}

static int tool_optical_exec_port_id_mode_A_K_0_8(struct command_context *ctx)
{
    xsfp_module_info xsfp_info[TOOL_USED_BY_OPTICAL_SUM] = {0};
    struct optical_info macro_data[MACRO_LANE_NUM] = {0};
    int ret = 0, org_dev_id = ctx->npu_info.logic_id;
    int tmp_solt_id = 0, tmp_phy_id = 0;

    tool_get_optical_info_by_port_id_0_8(ctx->slot_id, ctx->udie_id, ctx->port_id, macro_data, MACRO_LANE_NUM);

    tmp_solt_id = macro_data[0].optical_master_dev_id;
    tmp_phy_id = xsfp_get_peer_dev_id_by_slot_id(ctx->dev_id, tmp_solt_id);
    ret = drvDeviceGetIndexByPhyId(tmp_phy_id, (unsigned int*)&ctx->npu_info.logic_id);
    if (ret) {
        hccn_err("failed to get dev logic id. (ret=%d; master_phy_dev_id=%d)",
                 ret, macro_data[0].optical_master_dev_id);
        return ret;
    }
    ret = tool_get_optical_info_by_logic_id(ctx, macro_data[0].optical_logic_id, &(xsfp_info[0]));
    if (ret) {
        hccn_err("failed to get optical info by logic id. (ret=%d)", ret);
        return ret;
    }

    tmp_solt_id = macro_data[MACRO_LANE_NUM / 0x2].optical_master_dev_id;
    tmp_phy_id = xsfp_get_peer_dev_id_by_slot_id(ctx->dev_id, tmp_solt_id);
    ret = drvDeviceGetIndexByPhyId(tmp_phy_id, (unsigned int*)&ctx->npu_info.logic_id);
    if (ret) {
        hccn_err("failed to get dev logic id. (ret=%d; master_phy_dev_id=%d)",
                 ret, macro_data[0x2].optical_master_dev_id);
        return ret;
    }
    ret = tool_get_optical_info_by_logic_id(ctx, macro_data[0x2].optical_logic_id, &(xsfp_info[1]));
    if (ret) {
        hccn_err("failed to get optical info by logic id. (ret=%d)", ret);
        return ret;
    }

    ctx->npu_info.logic_id = org_dev_id;
    ret = tool_optical_info_print_port_id_mode_0_8(ctx, xsfp_info, TOOL_USED_BY_OPTICAL_SUM,
                                                   macro_data, MACRO_LANE_NUM);
    return ret;
}

static int tool_optical_exec_port_id_mode(struct command_context *ctx)
{
    int ret;
    int optical_id[TOOL_USED_BY_OPTICAL_SUM];
    int optical_lane_id[TOOL_USED_BY_OPTICAL_SUM];
    xsfp_module_info xsfp_info[TOOL_USED_BY_OPTICAL_SUM] = {0};

    ret = tool_get_optical_lane_info_by_port_id(ctx->slot_id, ctx->udie_id, ctx->port_id, optical_id, optical_lane_id);
    if (ret) {
        return ret;
    }

    ret = tool_get_optical_info_by_phy_optical_id(ctx, optical_id[0], &xsfp_info[0]);
    if (ret) {
        hccn_err("get optical info by phy optical id failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_get_optical_info_by_phy_optical_id(ctx, optical_id[1], &xsfp_info[1]);
    if (ret) {
        hccn_err("get optical info by phy optical id failed. (ret=%d)", ret);
        return ret;
    }

    ret = tool_optical_info_print_port_id_mode(ctx, xsfp_info, TOOL_USED_BY_OPTICAL_SUM, optical_lane_id, optical_id);
    if (ret) {
        hccn_err("failed to print optical info. (ret=%d)", ret);
    }

    return ret;
}

// UBOE一个port只使用1个光模块，框架需要数组为2，故定义数组大小为2但实际只有1个光模块的信息，传递数组大小也为1
static int tool_optical_exec_port_id_mode_uboe(struct command_context *ctx)
{
    int ret = 0, org_dev_id = ctx->npu_info.logic_id, tmp_solt_id = 0, tmp_phy_id = 0;
    xsfp_module_info xsfp_info[TOOL_USED_BY_OPTICAL_SUM] = {0};
    struct optical_info macro_data[MACRO_LANE_NUM] = {0};

    tool_get_optical_info_by_port_id_uboe(ctx->slot_id, ctx->port_id, macro_data, MACRO_LANE_NUM);

    tmp_solt_id = macro_data[0].optical_master_dev_id;
    tmp_phy_id = xsfp_get_peer_dev_id_by_slot_id(ctx->dev_id, tmp_solt_id);
    ret = drvDeviceGetIndexByPhyId(tmp_phy_id, (unsigned int*)&ctx->npu_info.logic_id);
    if (ret) {
        hccn_err("failed to get dev logic id. (ret=%d; master_phy_dev_id=%d)",
                 ret, macro_data[0].optical_master_dev_id);
        return ret;
    }
    ret = tool_get_optical_info_by_logic_id(ctx, macro_data[0].optical_logic_id, &(xsfp_info[0]));
    if (ret) {
        hccn_err("failed to get optical info by logic id. (ret=%d)", ret);
        return ret;
    }

    ctx->npu_info.logic_id = org_dev_id;
    ret = tool_optical_info_print_port_id_mode_uboe(ctx, xsfp_info, 0x1, macro_data, MACRO_LANE_NUM);
    if (ret) {
        hccn_err("failed to print optical info. (ret=%d)", ret);
    }

    return ret;
}

static int tool_get_optical_cfg_status_by_logic_id(
    struct command_context *ctx, int optical_id, xsfp_cfg_status_info *cfg_status_info)
{
    struct product_channel_msg msg = {0};
    int ret = 0;

    SET_PRODUCT_MSG(msg, &optical_id, sizeof(int),
                    cfg_status_info, sizeof(xsfp_cfg_status_info));
    ret = product_host_device_channel(ctx, CMD_OPTICAL_OPERATE_CFG_STATUS, &msg);
    if (ret) {
        hccn_err("failed to get optical cfg status. (cmd=%u, ret=%d)",
                 CMD_OPTICAL_OPERATE_CFG_STATUS, ret);
        return ret;
    }

    return 0;
}

/* loopback 状态名称定义 */
static const char* g_loopback_names[] = {
    "no loopback mode",                // 0
    "host side input loopback mode",   // 1: 电侧内环
    "media side output loopback mode", // 2: 光侧内环
    "host side output loopback mode",  // 3: 电侧外环
    "media side input loopback mode"   // 4: 光侧外环
};

static const char* tool_optical_get_loopback_name(unsigned char loopback_val)
{
    if (loopback_val < (sizeof(g_loopback_names) / sizeof(g_loopback_names[0]))) {
        return g_loopback_names[loopback_val];
    }
    return "abnormal";
}

static int tool_optical_format_tx_signal(
    unsigned char optical_type, unsigned char tx_signal, char *tx_signal_str, int len)
{
    int ret;
    const char *status = "abnormal";
    unsigned char disable_value = (optical_type == XSFP_PRODUCT_QSFP_DD) ? TX_SIGNAL_DD_DISABLE : TX_SIGNAL_DISABLE;

    if (tx_signal == TX_SIGNAL_ENABLE) {
        status = "enable";
    } else if (tx_signal == disable_value) {
        status = "disable";
    }

    ret = snprintf_s(tx_signal_str, len, len - 1, "%s", status);
    if (ret < 0) {
        hccn_err("snprintf_s tx signal failed. (ret=%d)", ret);
        return ret;
    }
    return 0;
}

static int tool_optical_info_print_optical_id_cfg_status_mode(
    struct command_context *ctx, xsfp_cfg_status_info cfg_status_info)
{
    int ret = 0;
    char tx_status_str[TOOL_USER_BY_STR_LEN] = {0};

    malloc_table_advance("IO", TOOL_TABLE_ROW_1, TOOL_TABLE_COL_2,
        "loopback status",  TYPE_CHARS, TOOL_TABLE_CHARS_20,
        "tx signal status", TYPE_CHARS, TOOL_TABLE_CHARS_20);

    const char *loopback_str = tool_optical_get_loopback_name(cfg_status_info.dynamic_data.loopback_mode & 0x7);
    ret = tool_optical_format_tx_signal(cfg_status_info.optical_type, cfg_status_info.dynamic_data.tx_signal,
                                        tx_status_str, sizeof(tx_status_str));
    if (ret != 0) {
        hccn_err("format tx signal failed. (ret=%d)", ret);
        clean_table();
        return ret;
    }

    ret += SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->optical_id, NULL, NULL);
    ret += SET_TABLE(0, "loopback status", "%s", loopback_str);
    ret += SET_TABLE(0, "tx signal status", "%s", tx_status_str);
    if (ret) {
        hccn_err("failed to make cfg_status table. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();

    return 0;
}

static int tool_optical_exec_optical_id_cfg_status_mode(struct command_context *ctx)
{
    int ret;
    xsfp_cfg_status_info cfg_status_info = {0};

    ret = tool_get_optical_cfg_status_by_logic_id(ctx, ctx->optical_id, &cfg_status_info);
    if (ret) {
        hccn_err("failed to get optical cfg status by logic id. (ret=%d)", ret);
        return ret;
    }

    if (cfg_status_info.config_data.master_xsfp_present != 1) {
        TOOL_PRINT_INFO("optical_id %d: module absent, query not supported.", ctx->optical_id);
        return 0;
    }

    ret = tool_optical_info_print_optical_id_cfg_status_mode(ctx, cfg_status_info);
    if (ret) {
        hccn_err("failed to print optical cfg status info. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

int tool_optical_exec(struct command_context *ctx)
{
    int ret;
    unsigned int port_type;

    // 处理 -cfg_status 子选项 (MODE_GET)
    if (ctx->cmd_args != NULL) {
        struct optical_param_t *param = (struct optical_param_t *)ctx->cmd_args;
        if (param->cfg_status_flag == 1) {
            return tool_optical_exec_optical_id_cfg_status_mode(ctx);
        }
    }

    // 此处需要根据unsupported_prod_mask判断是否为支持的产品判断，待海思代码上库后添加校验
    if (ctx->dev_mask == DEV_OPTICAL_ATTR) { // 传入参数为dev_id + optical_id模式
        ret = tool_optical_exec_optical_id_mode(ctx);
    } else if (ctx->dev_mask == DEV_PORT_TYPE) { // 传入参数为dev_id + udie_id + port_id模式
        port_type = tool_get_port_type(ctx);
        if (port_type == NPU_PORT_OUTLET) {
            if (tool_is_ascend950_A_K_0_8(ctx) == true) {
                ret = tool_optical_exec_port_id_mode_A_K_0_8(ctx);
            } else {
                ret = tool_optical_exec_port_id_mode(ctx);
            }
        } else if (port_type == NPU_PORT_UBOE) {
            ret = tool_optical_exec_port_id_mode_uboe(ctx);
        } else {
            hccn_err("port id not support. (udie_id=%d; port_id=%d)", ctx->udie_id, ctx->port_id);
            return TOOL_PUBLIC_ARGS_PORT_ERR;
        }
    } else if (ctx->dev_mask == DEV_NPU_ATTR) {
        ret = tool_optical_exec_device_id_mode(ctx);
    } else {
        ret = TOOL_INVALID_PARAM;
    }

    return ret;
}

void get_optical_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry param_list[] = {
        {"-tx_signal", ARG_TYPE_STR, parse_str, MODE_TEST, 0, true, .range.str_range = {MAX_STR_VAL_LEN}},
        {"-cfg_status", ARG_TYPE_NONE, parse_none, MODE_GET, 0, true, .range.str_range = {MAX_STR_VAL_LEN}},
        {"-path", ARG_TYPE_STR, parse_str, MODE_SET, 0, true, .range.str_range = {PATH_MAX}},
        {"-upgrade", ARG_TYPE_NONE, parse_none, MODE_SET, 0, true},
        {"-dump_page", ARG_TYPE_STR, parse_str, MODE_TEST, 0, true, .range.str_range = {MAX_STR_VAL_LEN}},
        {"-loopback_mode", ARG_TYPE_INT, parse_int, MODE_TEST, 0, true, .range.int_range = {0, 4}},
        {"-reset_mode", ARG_TYPE_STR, parse_str, MODE_TEST, 0, true, .range.str_range = {MAX_STR_VAL_LEN}},
        {"-high_power", ARG_TYPE_STR, parse_str, MODE_TEST, 0, true, .range.str_range = {MAX_STR_VAL_LEN}},
    };

    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}

void *alloc_optical_args_init(void)
{
    return calloc(1, sizeof(struct optical_param_t));
}

int optical_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct optical_param_t *param = (struct optical_param_t *)args;

    if (strcmp(opt->name, "-cfg_status") == 0) {
        param->cfg_status_flag = 1;
        return 0;
    }

    if (strcmp(opt->name, "-upgrade") == 0) {
        param->info.test_mode = CMD_OPTICAL_UPGRADE_FIRMWARE;
        return 0;
    }

    if (strcmp(opt->name, "-path") == 0) {
        if (validate_firmware_path(type_val->str_val) != 0) {
            TOOL_PRINT_INFO("target fw_path is invalid, please check.");
            return TOOL_FILE_PATH_ERROR;
        }
        if (strncpy_s(param->firmware_path, PATH_MAX,
                      type_val->str_val, strlen(type_val->str_val)) != 0) {
            hccn_err("Failed to copy firmware path.");
            return TOOL_ASSIGN_UNKNOWN;
        }
        return 0;
    }

    return optical_assign_test(&param->info, opt, type_val);
}

void tool_optical_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_optical_help(ctx, MODE_GET);
            tool_optical_help(ctx, MODE_TEST);
            tool_optical_help(ctx, MODE_SET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-optical", "get optical info");
            tool_print_npu_info(DEV_PORT_TYPE);

            TOOL_PRINT_CMD("-g", "-optical", "get optical info");
            tool_print_npu_info(DEV_OPTICAL_ATTR);
            TOOL_PRINT_OPT("[-cfg_status]", "get optical config status");
            break;
        case MODE_TEST:
            TOOL_PRINT_CMD("-t", "-optical", "optical module test operations");
            tool_print_npu_info(DEV_OPTICAL_ATTR);
            TOOL_PRINT_OPT("-tx_signal <enable|disable>", "Enable or disable optical module tx signal");
            TOOL_PRINT_OPT("-dump_page <all|%x>", "Dump optical module EEPROM registers. "
                "all: dump all pages. %x: dump specified page (0x00-0xFF)");
            TOOL_PRINT_OPT("-loopback_mode <0-4>", "Set optical module loopback mode. "
                "0: cancel loopback, 1: host side input loopback, 2: media side output loopback, "
                "3: host side output loopback, 4: media side input loopback");
            TOOL_PRINT_OPT("-reset_mode <soft_reset|hard_reset>", "reset optical module");
            TOOL_PRINT_OPT("-high_power <enable|disable>", "Enable or disable optical module high power mode");
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-optical", "upgrade optical firmware");
            tool_print_npu_info(DEV_OPTICAL_ATTR);
            TOOL_PRINT_OPT("-path <firmware_path>", "firmware file path");
            TOOL_PRINT_OPT("-upgrade", "execute firmware upgrade");
            break;
        default:
            break;
    }
}