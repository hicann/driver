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

#ifndef DVPP_SHARE_MEM_CTRL_H
#define DVPP_SHARE_MEM_CTRL_H

#include "ka_type.h"

#include "ka_task_pub.h"
#include "dvpp_cmdlist.h"
#include "dvpp_vmng.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
消息通道个数限制了最大并发数，当前是8个
1、normalo block理论上最多只需要8个缓存块就够了。考虑后续扩展，这个地方默认按照16个缓冲块处理
2、super block考虑到VPC有batch接口，考虑到多256 batch的情况，需要预留内存块。这个当前按照VPC消息通道的个数8来申请
*/

#define MAX_SUPER_BLKS_NUM  (8U)
#define MAX_BLKS_NUM        (16U)
#define BLK_SIZE            (12288U) // 12K，8K是argssize，4K用于存放svm pa信息
#define SUPER_BLK_SIZE      (2097152U) // 2M
#define MOD_NUM             (3U)
#define DVPP_PCI_BAR_0      (0U)
#define DVPP_SHARE_MEM_SIZE (25165824U) // 24M

typedef enum {
    DVPP_SHARE_BLK_IDLE,
    DVPP_SHARE_BLK_BUSY,
} dvpp_share_blk_status;

typedef enum {
    DVPP_SHARE_BLK_TYPE_NORMAL, // 适用于一图一框
    DVPP_SHARE_BLK_TYPE_SUPER,  // 适用于一图多框，多图多框
} dvpp_share_blk_type;

typedef enum {
    DVPP_SHARE_BLK_MOD_VPC = 0,
    DVPP_SHARE_BLK_MOD_JPEGD,
    DVPP_SHARE_BLK_MOD_JPEGE,
    DVPP_SHARE_BLK_MOD_BUTT,
} dvpp_share_blk_mod;

typedef struct {
    uint64_t addr;
    uint64_t size;
    dvpp_share_blk_mod mod_id;
    dvpp_share_blk_type type;
    dvpp_share_blk_status status;
} dvpp_share_blk;

typedef struct {
    uint64_t addr; // 原始地址
    uint64_t size; // 原始长度
    dvpp_share_blk normal_blks[MOD_NUM][MAX_BLKS_NUM];   // 有三个模块，同时考虑后续扩展，这个地方默认按照32个缓冲块处理
    dvpp_share_blk super_blks[MAX_SUPER_BLKS_NUM];       // 当前按照消息通道的个数8来申请
    uint8_t init_flag;
} dvpp_share_mem_pool; // 结构体大约4K大小

extern ka_spinlock_t g_share_mem_pool_lock[DVPP_VMNG_DEVICE_NUM_MAX];
extern dvpp_share_mem_pool *g_share_mem_pool[DVPP_VMNG_DEVICE_NUM_MAX];

dvpp_share_mem_pool* dvpp_init_share_mem_pool(uint32_t devid, dvpp_sqe_args *sqe_args);
void dvpp_uninit_share_mem_pool(void);
dvpp_share_blk* dvpp_get_share_mem_blk_from_pool(
    dvpp_share_blk_type type, dvpp_share_blk_mod mod_id, dvpp_share_mem_pool *pool);
void dvpp_put_share_mem_blk_to_pool(dvpp_share_blk *blk);

static inline dvpp_share_blk_mod trans_sqe_type_to_mod_id(uint32_t sqe_type)
{
    if ((sqe_type < (uint32_t)DVPP_SQE_VPC) || (sqe_type > (uint32_t)DVPP_SQE_JPEGD)) {
        return DVPP_SHARE_BLK_MOD_BUTT;
    }
    return (dvpp_share_blk_mod)(sqe_type - DVPP_SQE_VPC);
}

static inline dvpp_share_blk_type trans_ptr_mode_to_blk_type(uint32_t ptr_mode)
{
    return ptr_mode == 1 ? DVPP_SHARE_BLK_TYPE_SUPER : DVPP_SHARE_BLK_TYPE_NORMAL;
}

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_SHARE_MEM_CTRL_H
