/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_LOG_H
#define TOOL_LOG_H

#include <unistd.h>
#include <sys/syscall.h>
#include "tool_param.h"

#define FILE_MASK_WC 0640
#define UNIT_THOUSAND 1000
#define BEGIN_YEAR 1900
#define LOGFILE_MAX_SIZE (5 * 1024 * 1024)
#define LOG_PRINT_TOTAL_SIZE 1024
#define LOG_PRINT_TIMESTR_SIZE 128
#define HCCN_LOG_SUFFIX_LEN 7
#define HCCN_LOG_MAX_RETRY 100
#define HCCN_LOG_HEAD_LEN 0
#define FILE_PATH_LEN 64
#define FILE_NAME_LEN 128
#define FILE_LOCK_LEN 128

typedef struct {
    char *buff;
    unsigned int buffLen;
} Buffer;

void ToolPrintLog(unsigned int modeType, const char *format, ...);

#define LOG_PROMPT(ctx, format, ...) do {                                                      \
    ToolPrintLog((ctx)->mode, "PROMPT %s %s [curpid:%d,%ld]%s:%d >>> " format "\n",            \
        (ctx)->env_info.usr_name, (ctx)->env_info.usr_ip,                                      \
        getpid(), syscall(__NR_gettid), __FILE__, __LINE__, ##__VA_ARGS__);                    \
} while (0)
#endif // TOOL_LOG_H
