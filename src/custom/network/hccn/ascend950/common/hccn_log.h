/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_LOG_H
#define HCCN_LOG_H

#include "slog.h"
#include "slog_api.h"
#include "user_log.h"

#define SUBMODULE_HCCN "HCCN"
#define HCCN_CHECK_USER_IS_ROOT "root"
#define HCCN_USER_NAME_LEN 32
#define HCCN_USER_IP_LEN 20

#ifdef DRV_HOST
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include "securec.h"

#define BUFF_LENTH (64U)
#define DRV_LOG_LEVEL_MAX (LOG_DEBUG + 1U)
#define DRV_LOG_START_TIME (1900)

static inline const char *get_tm_default(void)
{
    static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    static char tmbuf[BUFF_LENTH] = {0};
    struct timeval usec = {0};
    struct tm *tm_now = NULL;
    time_t rawtime = {0};
    int ret;

    (void)pthread_mutex_lock(&lock);
    (void)time(&rawtime);
    tm_now = localtime(&rawtime);
    CHK_PRT_RETURN(tm_now == NULL, (void)pthread_mutex_unlock(&lock), NULL);

    (void)gettimeofday(&usec, NULL);

    ret = sprintf_s(tmbuf, BUFF_LENTH, "[%d-%02d-%02d-%02d:%02d:%02d:%06d]",
                    tm_now->tm_year + DRV_LOG_START_TIME, tm_now->tm_mon + 1,
                    tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min,
                    tm_now->tm_sec, (int32_t)usec.tv_usec);
    if (ret < 0) {
        (void)pthread_mutex_unlock(&lock);
        return NULL;
    }

    (void)pthread_mutex_unlock(&lock);
    return tmbuf;
}

#define NET_SYSLOG_BASE(LEVEL, level_str, module_str, fmt, ...) do {            \
    syslog(LEVEL, "%s%s[%s:%d][ascend][curpid:%d,%ld][drv][%s][%s]" fmt "\n",   \
           level_str,                                                           \
           get_tm_default(),                                                    \
           __FILE__, __LINE__,                                                  \
           getpid(),                                                            \
           syscall(__NR_gettid),                                                \
           module_str,                                                          \
           __func__,                                                            \
           ##__VA_ARGS__);                                                      \
} while (0)

#define NET_ERR(module, fmt, ...)   NET_SYSLOG_BASE(LOG_ERR, "[ERROR]", "net", fmt, ##__VA_ARGS__)
#define NET_WARN(module, fmt, ...)  NET_SYSLOG_BASE(LOG_WARNING, "[WARNING]", "net", fmt, ##__VA_ARGS__)
#define NET_INFO(module, fmt, ...)  NET_SYSLOG_BASE(LOG_INFO, "[INFO]", "net", fmt, ##__VA_ARGS__)
#define NET_DEBUG(module, fmt, ...) NET_SYSLOG_BASE(LOG_DEBUG, "[DEBUG]", "net", fmt, ##__VA_ARGS__)

#define hccn_err(fmt, ...)          NET_ERR(HAL_MODULE_TYPE_NET, fmt, ##__VA_ARGS__)
#define hccn_warn(fmt, ...)         NET_WARN(HAL_MODULE_TYPE_NET, fmt, ##__VA_ARGS__)
#define hccn_info(fmt, ...)         NET_INFO(HAL_MODULE_TYPE_NET, fmt, ##__VA_ARGS__)
#define hccn_dbg(fmt, ...)          NET_DEBUG(HAL_MODULE_TYPE_NET, fmt, ##__VA_ARGS__)

#define hccn_run_warn hccn_warn
#else
#define hccn_err(fmt, args...)    usr_sub_dlog(NET, SUBMODULE_HCCN, ERROR_LEVEL, "%s: " fmt, __func__, ##args)
#define hccn_warn(fmt, args...)   usr_sub_dlog(NET, SUBMODULE_HCCN, WARN_LEVEL, "%s: " fmt, __func__, ##args)
#define hccn_info(fmt, args...)   usr_sub_dlog(NET, SUBMODULE_HCCN, INFO_LEVEL, "%s: " fmt, __func__, ##args)
#define hccn_dbg(fmt, args...)    usr_sub_dlog(NET, SUBMODULE_HCCN, DEBUG_LEVEL, "%s: " fmt, __func__, ##args)

#define hccn_run_warn(fmt, args...) \
    usr_sub_dlog(NET | RUN_LOG_MASK, SUBMODULE_HCCN, WARN_LEVEL, "%s: " fmt, __func__, ##args)

#endif // DRV_HOST
#endif // HCCN_LOG_H