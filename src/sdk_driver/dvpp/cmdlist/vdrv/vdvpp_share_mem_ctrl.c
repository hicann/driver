/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "dvpp_share_mem_ctrl.h"

#include "ka_task_pub.h"
#include "ka_memory_pub.h"
#include "comm_kernel_interface.h"
#include "dvpp_cmdlist_log.h"

ka_spinlock_t g_share_mem_pool_lock[DVPP_VMNG_DEVICE_NUM_MAX];
dvpp_share_mem_pool *g_share_mem_pool[DVPP_VMNG_DEVICE_NUM_MAX] = {[0 ... DVPP_VMNG_DEVICE_NUM_MAX - 1U] = NULL} ;
static ka_mutex_t g_normal_blks_mutex[MOD_NUM];
static ka_mutex_t g_super_blks_mutex;

static int32_t dvpp_get_share_addr_info(uint32_t devid, uint64_t *addr, size_t *size)
{
    int32_t ret = devdrv_get_addr_info(devid, DEVDRV_ADDR_DVPP_BASE, 0, addr, size);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("get dvpp share memory info fail. ret = %d\n", ret);
        return -1;
    }

    if (*addr == 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp share memory addr is null\n");
        return -1;
    }

    if (*size < DVPP_SHARE_MEM_SIZE) {
        DVPP_CMDLIST_LOG_ERROR("dvpp share memory size cannot be less %u\n", DVPP_SHARE_MEM_SIZE);
        return -1;
    }

    return 0;
}

dvpp_share_mem_pool* dvpp_init_share_mem_pool(uint32_t devid, dvpp_sqe_args *sqe_args)
{
    uint32_t m = 0;
    uint32_t n = 0;
    dvpp_share_mem_pool *pool = NULL;
    uint64_t addr = 0;
    size_t size = 0;
    void *share_mem = NULL;

    // get share memory info
    if (dvpp_get_share_addr_info(devid, &addr, &size) != 0) {
        DVPP_CMDLIST_LOG_ERROR("get share memory information fail.\n");
        return NULL;
    }

    // 常驻内存不做释放，进程退出后自动释放
    share_mem = ka_mm_ioremap_wc(addr, size);
    if (share_mem == NULL) {
        DVPP_CMDLIST_LOG_ERROR("map share mem memory fail.\n");
        return NULL;
    }

    pool = (dvpp_share_mem_pool*)share_mem;
    pool->addr = (uintptr_t)share_mem + sizeof(dvpp_share_mem_pool);
    pool->size = size - sizeof(dvpp_share_mem_pool);

    // normal blks split
    for (m = 0; m < MOD_NUM; m++) {
        for (n = 0; n < MAX_BLKS_NUM; n++) {
            pool->normal_blks[m][n].addr = pool->addr + (m * MAX_BLKS_NUM + n) * BLK_SIZE;
            pool->normal_blks[m][n].size = BLK_SIZE;
            pool->normal_blks[m][n].type = DVPP_SHARE_BLK_TYPE_NORMAL;
            pool->normal_blks[m][n].status = DVPP_SHARE_BLK_IDLE;
        }
    }
    for (m = 0; m < MOD_NUM; m++) {
        ka_task_mutex_init(&g_normal_blks_mutex[m]);
    }

    // super blks split
    for (n = 0; n < MAX_SUPER_BLKS_NUM; n++) {
        pool->super_blks[n].addr = pool->addr + (MOD_NUM * MAX_BLKS_NUM * BLK_SIZE) + (n * SUPER_BLK_SIZE);
        pool->super_blks[n].size = SUPER_BLK_SIZE;
        pool->super_blks[n].type = DVPP_SHARE_BLK_TYPE_SUPER;
        pool->super_blks[n].status = DVPP_SHARE_BLK_IDLE;
    }
    ka_task_mutex_init(&g_super_blks_mutex);

    return pool;
}

void dvpp_uninit_share_mem_pool(void)
{
    uint32_t devid;
    for (devid = 0;devid < DVPP_VMNG_DEVICE_NUM_MAX;devid++) {
        if (g_share_mem_pool[devid] != NULL) {
            ka_mm_iounmap(g_share_mem_pool[devid]);
            g_share_mem_pool[devid] = NULL;
        }
    }
}

static dvpp_share_blk* dvpp_get_normal_blk_from_pool(dvpp_share_mem_pool *pool, dvpp_share_blk_mod mod_id)
{
    uint32_t n = 0;
    ka_task_mutex_lock(&g_normal_blks_mutex[mod_id]);
    for (n = 0; n < MAX_BLKS_NUM; n++) {
        if (pool->normal_blks[mod_id][n].status == DVPP_SHARE_BLK_IDLE) {
            pool->normal_blks[mod_id][n].status = DVPP_SHARE_BLK_BUSY;
            pool->normal_blks[mod_id][n].mod_id = mod_id;
            ka_task_mutex_unlock(&g_normal_blks_mutex[mod_id]);
            return &pool->normal_blks[mod_id][n];
        }
    }
    ka_task_mutex_unlock(&g_normal_blks_mutex[mod_id]);

    return NULL;
}

static dvpp_share_blk* dvpp_get_super_blk_from_pool(dvpp_share_mem_pool *pool)
{
    uint32_t n = 0;
    ka_task_mutex_lock(&g_super_blks_mutex);
    for (n = 0; n < MAX_SUPER_BLKS_NUM; n++) {
        if (pool->super_blks[n].status == DVPP_SHARE_BLK_IDLE) {
            pool->super_blks[n].status = DVPP_SHARE_BLK_BUSY;
            ka_task_mutex_unlock(&g_super_blks_mutex);
            return &pool->super_blks[n];
        }
    }
    ka_task_mutex_unlock(&g_super_blks_mutex);

    return NULL;
}

dvpp_share_blk* dvpp_get_share_mem_blk_from_pool(
    dvpp_share_blk_type type, dvpp_share_blk_mod mod_id, dvpp_share_mem_pool *pool)
{
    dvpp_share_blk *blk = NULL;
    if (type == DVPP_SHARE_BLK_TYPE_NORMAL) {
        blk = dvpp_get_normal_blk_from_pool(pool, mod_id);
        if (blk == NULL) {
            DVPP_CMDLIST_LOG_ERROR("get normal memory block from pool fail.\n");
            return NULL;
        }
    } else if (type == DVPP_SHARE_BLK_TYPE_SUPER) {
        blk = dvpp_get_super_blk_from_pool(pool);
        if (blk == NULL) {
            DVPP_CMDLIST_LOG_ERROR("get super memory block from pool fail.\n");
            return NULL;
        }
    }

    return blk;
}

void dvpp_put_share_mem_blk_to_pool(dvpp_share_blk *blk)
{
    blk->status = DVPP_SHARE_BLK_IDLE;
}