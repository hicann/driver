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

#include "ascend_hal_define.h"
#include "bitmap.h"

#include "svm_pub.h"
#include "svm_log.h"
#include "svm_init_pri.h"
#include "svm_sys_cmd.h"
#include "svm_alloc.h"
#include "svm_dbi.h"
#include "malloc_mng.h"
#include "svm_cpy_host_pool.h"

#define SVM_CPY_HOST_POOL_BUCKET_NUM 3
#define SVM_CPY_HOST_POOL_128_SIZE (128ULL)
#define SVM_CPY_HOST_POOL_128_NUM 10000U
#define SVM_CPY_HOST_POOL_4K_SIZE (4ULL * SVM_BYTES_PER_KB)
#define SVM_CPY_HOST_POOL_4K_NUM 1000U
#define SVM_CPY_HOST_POOL_512K_SIZE (512ULL * SVM_BYTES_PER_KB)
#define SVM_CPY_HOST_POOL_512K_NUM 8U

#define SVM_CPY_HOST_POOL_BITMAP_BIT_NUM (sizeof(bitmap_t) * 8U)
#define SVM_CPY_HOST_POOL_BITMAP_NUM(bit_num) \
    (((bit_num) + SVM_CPY_HOST_POOL_BITMAP_BIT_NUM - 1) / SVM_CPY_HOST_POOL_BITMAP_BIT_NUM)

enum svm_cpy_host_pool_state {
    SVM_CPY_HOST_POOL_UNINIT = 0,
    SVM_CPY_HOST_POOL_READY,
    SVM_CPY_HOST_POOL_FAIL
};

struct svm_cpy_host_pool_bucket {
    u64 chunk_size;
    u32 chunk_num;
    u32 free_num;
    u64 base_va;
    bitmap_t *bitmap;
};

static pthread_mutex_t g_svm_cpy_host_pool_mutex = PTHREAD_MUTEX_INITIALIZER;
static bitmap_t g_svm_cpy_host_pool_128_bitmap[SVM_CPY_HOST_POOL_BITMAP_NUM(SVM_CPY_HOST_POOL_128_NUM)];
static bitmap_t g_svm_cpy_host_pool_4k_bitmap[SVM_CPY_HOST_POOL_BITMAP_NUM(SVM_CPY_HOST_POOL_4K_NUM)];
static bitmap_t g_svm_cpy_host_pool_512k_bitmap[SVM_CPY_HOST_POOL_BITMAP_NUM(SVM_CPY_HOST_POOL_512K_NUM)];
static enum svm_cpy_host_pool_state g_svm_cpy_host_pool_state = SVM_CPY_HOST_POOL_UNINIT;
static struct svm_cpy_host_pool_bucket g_svm_cpy_host_pool[SVM_CPY_HOST_POOL_BUCKET_NUM] = {
    {.chunk_size = SVM_CPY_HOST_POOL_128_SIZE,
     .chunk_num = SVM_CPY_HOST_POOL_128_NUM,
     .bitmap = g_svm_cpy_host_pool_128_bitmap},
    {.chunk_size = SVM_CPY_HOST_POOL_4K_SIZE,
     .chunk_num = SVM_CPY_HOST_POOL_4K_NUM,
     .bitmap = g_svm_cpy_host_pool_4k_bitmap},
    {.chunk_size = SVM_CPY_HOST_POOL_512K_SIZE,
     .chunk_num = SVM_CPY_HOST_POOL_512K_NUM,
     .bitmap = g_svm_cpy_host_pool_512k_bitmap}};

static struct svm_cpy_host_pool_bucket *svm_cpy_host_pool_get_bucket(u64 size, u32 *bucket_idx)
{
    u32 i;

    for (i = 0; i < SVM_CPY_HOST_POOL_BUCKET_NUM; i++) {
        if (size <= g_svm_cpy_host_pool[i].chunk_size) {
            *bucket_idx = i;
            return &g_svm_cpy_host_pool[i];
        }
    }

    return NULL;
}

static void svm_cpy_host_pool_bucket_reset(struct svm_cpy_host_pool_bucket *bucket)
{
    bitmap_clear(bucket->bitmap, 0, (int)bucket->chunk_num);
    bucket->free_num = bucket->chunk_num;
}

static int svm_cpy_host_pool_bucket_init(struct svm_cpy_host_pool_bucket *bucket)
{
    void *host_va = NULL;
    int ret;

    if (bucket->base_va != 0) {
        return DRV_ERROR_NONE;
    }

    ret = svm_mem_malloc(&host_va, bucket->chunk_size * bucket->chunk_num,
                         MEM_HOST | ((u64)DEVMM_MODULE_ID << MEM_MODULE_ID_BIT));
    if (ret != DRV_ERROR_NONE) {
        return ret;
    }

    bucket->base_va = (u64)(uintptr_t)host_va;
    svm_cpy_host_pool_bucket_reset(bucket);
    return DRV_ERROR_NONE;
}

static void svm_cpy_host_pool_bucket_uninit(struct svm_cpy_host_pool_bucket *bucket)
{
    if (bucket->base_va != 0) {
        (void)svm_mem_free((void *)(uintptr_t)bucket->base_va);
        bucket->base_va = 0;
    }

    svm_cpy_host_pool_bucket_reset(bucket);
}

static int svm_cpy_host_pool_init(void)
{
    u32 ready_bucket_num = 0;
    u32 i;

    if (g_svm_cpy_host_pool_state == SVM_CPY_HOST_POOL_READY) {
        return DRV_ERROR_NONE;
    }

    if (g_svm_cpy_host_pool_state == SVM_CPY_HOST_POOL_FAIL) {
        return DRV_ERROR_NOT_SUPPORT;
    }

    for (i = 0; i < SVM_CPY_HOST_POOL_BUCKET_NUM; i++) {
        int ret = svm_cpy_host_pool_bucket_init(&g_svm_cpy_host_pool[i]);

        if (ret != DRV_ERROR_NONE) {
            svm_warn("Alloc memcpy host svm pool failed. (ret=%d; chunk_size=%llu; chunk_num=%u)\n", ret,
                     g_svm_cpy_host_pool[i].chunk_size, g_svm_cpy_host_pool[i].chunk_num);
            continue;
        }

        ready_bucket_num++;
    }

    if (ready_bucket_num == 0) {
        g_svm_cpy_host_pool_state = SVM_CPY_HOST_POOL_FAIL;
        return DRV_ERROR_NOT_SUPPORT;
    }

    g_svm_cpy_host_pool_state = SVM_CPY_HOST_POOL_READY;
    return DRV_ERROR_NONE;
}

void svm_cpy_host_pool_uninit(void)
{
    u32 i;

    for (i = 0; i < SVM_CPY_HOST_POOL_BUCKET_NUM; i++) {
        svm_cpy_host_pool_bucket_uninit(&g_svm_cpy_host_pool[i]);
    }

    g_svm_cpy_host_pool_state = SVM_CPY_HOST_POOL_UNINIT;
}

static int _svm_cpy_host_pool_slot_get(struct svm_cpy_host_pool_bucket *bucket, u32 bucket_idx,
                                       struct svm_cpy_host_pool_slot *slot)
{
    u32 slot_idx;

    if ((bucket->base_va == 0) || (bucket->free_num == 0)) {
        return DRV_ERROR_BUSY;
    }

    slot_idx = (u32)bitmap_find_next_zero_area(bucket->bitmap, bucket->chunk_num, 0, 1, 0);
    if (slot_idx >= bucket->chunk_num) {
        return DRV_ERROR_BUSY;
    }

    bitmap_set(bucket->bitmap, (int)slot_idx, 1);
    bucket->free_num--;

    slot->bucket_idx = bucket_idx;
    slot->slot_idx = slot_idx;
    slot->va = bucket->base_va + (u64)slot_idx * bucket->chunk_size;
    return DRV_ERROR_NONE;
}

static void _svm_cpy_host_pool_slot_put(struct svm_cpy_host_pool_slot *slot)
{
    struct svm_cpy_host_pool_bucket *bucket = &g_svm_cpy_host_pool[slot->bucket_idx];

    bitmap_clear(bucket->bitmap, (int)slot->slot_idx, 1);
    bucket->free_num++;

    slot->va = 0;
    slot->bucket_idx = 0;
    slot->slot_idx = 0;
}

int svm_cpy_host_pool_slot_get(u64 size, struct svm_cpy_host_pool_slot *slot)
{
    struct svm_cpy_host_pool_bucket *bucket;
    u32 bucket_idx;
    int ret;

    bucket = svm_cpy_host_pool_get_bucket(size, &bucket_idx);
    if (bucket == NULL) {
        return DRV_ERROR_NOT_SUPPORT;
    }

    (void)pthread_mutex_lock(&g_svm_cpy_host_pool_mutex);
    if (g_svm_cpy_host_pool_state != SVM_CPY_HOST_POOL_READY) {
        (void)pthread_mutex_unlock(&g_svm_cpy_host_pool_mutex);
        return DRV_ERROR_NOT_SUPPORT;
    }

    ret = _svm_cpy_host_pool_slot_get(bucket, bucket_idx, slot);
    (void)pthread_mutex_unlock(&g_svm_cpy_host_pool_mutex);
    return ret;
}

void svm_cpy_host_pool_slot_put(struct svm_cpy_host_pool_slot *slot)
{
    (void)pthread_mutex_lock(&g_svm_cpy_host_pool_mutex);
    _svm_cpy_host_pool_slot_put(slot);
    (void)pthread_mutex_unlock(&g_svm_cpy_host_pool_mutex);
}

static int svm_cpy_host_pool_dev_init(u32 devid)
{
    int ret;

    if (devid != svm_get_host_devid()) {
        return DRV_ERROR_NONE;
    }

    (void)pthread_mutex_lock(&g_svm_cpy_host_pool_mutex);
    ret = svm_cpy_host_pool_init();
    (void)pthread_mutex_unlock(&g_svm_cpy_host_pool_mutex);
    if (ret != DRV_ERROR_NONE) {
        svm_warn("Init memcpy host pool failed. (ret=%d; devid=%u)\n", ret, devid);
    }

    return DRV_ERROR_NONE;
}

static int svm_cpy_host_pool_dev_uninit(u32 devid)
{
    if (devid != svm_get_host_devid()) {
        return DRV_ERROR_NONE;
    }

    (void)pthread_mutex_lock(&g_svm_cpy_host_pool_mutex);
    svm_cpy_host_pool_uninit();
    (void)pthread_mutex_unlock(&g_svm_cpy_host_pool_mutex);
    return DRV_ERROR_NONE;
}

static void __attribute__((constructor(SVM_INIT_PRI_FINAL))) svm_cpy_host_pool_module_init(void)
{
    int ret;

    ret = svm_register_ioctl_dev_init_post_handle(svm_cpy_host_pool_dev_init);
    if (ret != DRV_ERROR_NONE) {
        svm_err("Register ioctl dev init post handle failed.\n");
    }

    ret = svm_register_ioctl_dev_uninit_pre_handle(svm_cpy_host_pool_dev_uninit);
    if (ret != DRV_ERROR_NONE) {
        svm_err("Register ioctl dev uninit pre handle failed.\n");
    }
}
