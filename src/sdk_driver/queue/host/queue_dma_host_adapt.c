/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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
#include "queue_dma_platform.h"
#include "queue_feature_check.h"

void queue_clear_dma_blks_platform(struct queue_dma_list *dma_list, u32 dev_id)
{
    if (queue_has_feature(dev_id, QUEUE_FEATURE_SURPORT_PCIE_DMA_SVA) == 0) {
        unsigned long stamp = ka_jiffies;
        u64 i;

        for (i = 0; i < dma_list->page_num; i++) {
            ka_mm_put_page(dma_list->page[i]);
            queue_try_cond_resched(&stamp);
        }
    }
    return;
}

void queue_unmap_dma_blks_platform(ka_device_t *dev, struct queue_dma_list *dma_list, u64 idx, u32 dev_id)
{
    if (queue_has_feature(dev_id, QUEUE_FEATURE_SURPORT_PCIE_DMA_SVA) == 0) {
        hal_kernel_devdrv_dma_unmap_page(dev, dma_list->blks[idx].dma, dma_list->blks[idx].sz, KA_DMA_BIDIRECTIONAL);
    }
}

bool queue_get_dma_sva_enable_platform(u32 dev_id)
{
    return (queue_has_feature(dev_id, QUEUE_FEATURE_SURPORT_PCIE_DMA_SVA) != 0);
}

u64 get_queue_dma_max_node_cnt(u32 dev_id)
{
    if (queue_has_feature(dev_id, QUEUE_FEATURE_PLATFORM_MINI_DMA) != 0) {
        return QUEUE_DMA_MAX_NODE_CNT_MINI;
    } else {
        return QUEUE_DMA_MAX_NODE_CNT_STD;
    }
}
