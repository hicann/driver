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

#ifndef DVPP_DMA_CTRL_H
#define DVPP_DMA_CTRL_H

#include "ka_type.h"

#include "ka_base_pub.h"
#include "dvpp_svm_mem_ctrl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint64_t vir_addr;
    uint64_t phy_addr;
} dvpp_dma_mem; // 如果结构体变大，需修改DVPP_DEFAULT_MEM_BLK_SIZE

void* dvpp_dma_alloc(uint32_t dev_id, size_t size, dma_addr_t *dma_addr, ka_gfp_t gfp);
void dvpp_dma_free(uint32_t dev_id, size_t size, void *addr, dma_addr_t dma_addr);
int32_t dvpp_dma_sync_link_copy(uint32_t dev_id, dvpp_dma_mem *dma_mem, dvpp_svm_pa_info *pa_info);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_DMA_CTRL_H