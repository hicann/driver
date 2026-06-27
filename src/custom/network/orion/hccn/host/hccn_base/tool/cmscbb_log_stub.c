/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

/*
 * cmscbb_log_stub.c - CMS-C 日志回调 stub 实现
 * upgrade_cmscbb_callback.c 中的 CmscbbLogPrint 调用 dcmi_log_fun，
 * 该函数原本由 iNPUManager 的 dcmi_inner 库提供。
 * hccn_tool 不链接 dcmi_inner，因此提供 stub 实现。
 */

#include <stdio.h>
#include <stdarg.h>

void dcmi_log_fun(int level, const char *fmt, ...)
{
    va_list args;
    (void)level;
    va_start(args, fmt);
    (void)vfprintf(stderr, fmt, args);
    va_end(args);
}
