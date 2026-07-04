/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <pthread.h>
#include "errno.h"
#include "ascend_hal_dl.h"
#include "dl_hal_function_internal.h"

#define DL_API_IS_NULL_CHECK(handle, ptr, str) do { \
    if ((handle) == NULL) { \
        roce_err("g_hal_api_handle is NULL!"); \
        return (-EINVAL); \
    } \
    if ((ptr) == NULL) { \
        roce_err("[%s] is NULL!", (str)); \
        return (-EINVAL); \
    } \
} while (0)

static pthread_mutex_t gHalInternalApiLock = PTHREAD_MUTEX_INITIALIZER;
static void *gHalInternalApiHandle = NULL;
static struct DlHalInternalOps gHalInternalOps;
static int gHalInternalApiRefcnt = 0;

static void DlHalInternalApiInit(void)
{
    gHalInternalOps.halSetUserConfig = (int (*)(uint32_t devid, const char *name, uint8_t *buf, uint32_t bufSize))
        AscendHalDlsym(gHalInternalApiHandle, "halSetUserConfig");

    gHalInternalOps.halClearUserConfig = (int (*)(uint32_t devid, const char *name))
        AscendHalDlsym(gHalInternalApiHandle, "halClearUserConfig");

    return;
}

void DlHalInternalDeinit(void)
{
    pthread_mutex_lock(&gHalInternalApiLock);
    if (gHalInternalApiHandle != NULL) {
        gHalInternalApiRefcnt--;
        if (gHalInternalApiRefcnt > 0) {
            pthread_mutex_unlock(&gHalInternalApiLock);
            roce_info("dl_hal_deinit success, no need to dlclose libascend_hal.so!");
            return;
        }

        (void)AscendHalDlclose(gHalInternalApiHandle);
        gHalInternalApiHandle = NULL;
    }

    pthread_mutex_unlock(&gHalInternalApiLock);
    roce_info("dl_hal_deinit success!");
    return;
}

int DlHalInternalInit(void)
{
    pthread_mutex_lock(&gHalInternalApiLock);
    if (gHalInternalApiHandle != NULL) {
        gHalInternalApiRefcnt++;
        pthread_mutex_unlock(&gHalInternalApiLock);
        roce_info("dl_hal_init success, no need to dlopen libascend_hal.so!");
        return 0;
    }

    gHalInternalApiHandle = AscendHalDlopen("libascend_hal.so", RTLD_NOW);
    if (gHalInternalApiHandle == NULL) {
        pthread_mutex_unlock(&gHalInternalApiLock);
        roce_err("dlopen libascend_hal.so failed! error_no=[%d]", errno);
        return -EINVAL;
    }

    DlHalInternalApiInit();
    gHalInternalApiRefcnt++;

    pthread_mutex_unlock(&gHalInternalApiLock);
    roce_info("dl_hal_init success!");
    return 0;
}

int DlHalSetUserConfig(uint32_t devid, const char *name, uint8_t *buf, uint32_t bufSize)
{
    int ret;

    ret = DlHalInternalInit();
    if (ret) {
        net_err("dl_hal_init failed, ret:%d", ret);
        return ret;
    }
    DL_API_IS_NULL_CHECK(gHalInternalApiHandle, gHalInternalOps.halSetUserConfig, "halSetUserConfig");

    ret = gHalInternalOps.halSetUserConfig(devid, name, buf, bufSize);
    DlHalInternalDeinit();

    return ret;
}

int DlHalClearUserConfig(uint32_t devid, const char *name)
{
    int ret;

    ret = DlHalInternalInit();
    if (ret) {
        net_err("dl_hal_init failed, ret:%d", ret);
        return ret;
    }
    DL_API_IS_NULL_CHECK(gHalInternalApiHandle, gHalInternalOps.halClearUserConfig, "halClearUserConfig");

    ret = gHalInternalOps.halClearUserConfig(devid, name);
    DlHalInternalDeinit();

    return ret;
}