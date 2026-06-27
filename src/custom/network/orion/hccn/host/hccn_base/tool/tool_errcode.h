/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_ERRCODE_H
#define TOOL_ERRCODE_H

// 我们在海思的tool_cmd_err.h里加错误码会导致频繁冲突，先另起一个文件放产品错误码，待框架稳定后合并
enum {
    TOOL_CMD_LIST_OVERBOUND  = 0x1F00, // CMD表单已满
    TOOL_INVALID_INNER_LOGIC = 0x1F01, // 内部逻辑问题，正常不触发
    TOOL_CONFLICT_INPUT      = 0x1F02, // 输入了冲突的参数
    TOOL_ASSIGN_UNKNOWN      = 0x1F03, // assign的时候发现未知参数
    TOOL_ENOMEM              = 0x1F04,
    TOOL_PRODUCT_H2D_ONLY    = 0x1F05, // 产品H2D通道传的消息格式特殊，不能由其他接口处理
    TOOL_INVALID_RESULT      = 0x1F06, // 底层返回了异常数据
    TOOL_DSMI_ERROR          = 0x1F07, // 海思dsmi接口出错时一律返回此错误码
    TOOL_TABLE_ERROR         = 0x1F08, // 表格回显异常时都用此错误码，一般是构建表格不当所致
    TOOL_INVALID_PARAM       = 0x1F09,
    TOOL_UNSUPPORT_BOARD     = 0x1F0A, // 表示当前产品形态不支持该命令
    TOOL_FILE_PATH_ERROR     = 0x1F0B, // 固件文件路径错误（不存在、不可读、路径过长等）
    TOOL_CMD_ERROR_UNKNOWN_END,        // 结束值标记，请勿改动其定义的相对位置
};

enum tool_exception_err_t {
    /* 异常状态记录 */
    TOOL_EXCEPT_UNIVERSAL = ((TOOL_CMD_ERROR_UNKNOWN_END + 0xFF) & (~0xFF)),  // 通用异常
    TOOL_EXCEPT_BAD_ALLOC,              // 内存分配失败
    TOOL_EXCEPT_INVALID_ARGUMENT,       // 参数异常
    TOOL_EXCEPT_INVALID_RESULT_DATA,    // 数据异常
    TOOL_EXCEPT_UNKOWN_END,             // 结束值标记，请勿改动其定义的相对位置
};

#endif