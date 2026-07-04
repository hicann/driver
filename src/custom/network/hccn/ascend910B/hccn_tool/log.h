/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef LOG_H
#define LOG_H
#include "user_log.h"
#include "hccn_comm.h"

#define MAX_LOG_NAME_LEN 128

void HccnPrintLog(const char *format, ...);
void HccnCdrRegPrintLog(const char *format, ...);
void HccnPrintSetConfigLog(const char *format, ...);

#define LOG_PROMPT(format, ...) do { \
            HccnPrintLog("PROMPT MINOR %s %s %s:%d >>> " format "\n", \
                hccn_get_g_usr_name(), hccn_get_g_usr_ip(), __FILE__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define LOG_SET_CONFIG(format, ...) do { \
            HccnPrintSetConfigLog("PROMPT MINOR %s %s %s:%d >>> " format "\n", \
                hccn_get_g_usr_name(), hccn_get_g_usr_ip(), __FILE__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define LOG_DEMAND(format, ...) do { \
            HccnPrintLog("DEMAND MINOR %s %s %s:%d >>> " format "\n", \
                hccn_get_g_usr_name(), hccn_get_g_usr_ip(), __FILE__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define LOG_CONFIG(format, ...) do { \
            HccnPrintSetConfigLog("CONFIG MAJOR %s %s %s:%d >>> " format "\n", \
                hccn_get_g_usr_name(), hccn_get_g_usr_ip(), __FILE__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define CdrRegLog(format, ...) do { \
            HccnCdrRegPrintLog(format "\n", ##__VA_ARGS__); \
    } while (0)
    
int generate_file_name(int prefix);
#endif

