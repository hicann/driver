/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef TRS_URMA_ASYNC_H
#define TRS_URMA_ASYNC_H

#include "ascend_hal_define.h"

#define TRS_ASYNC_HOST_TO_DEVICE   0
#define TRS_ASYNC_DEVICE_TO_HOST   1
#define TRS_ASYNC_DEVICE_TO_DEVICE 6
#define TRS_ASYNC_MAX_DIR          7

enum trs_async_dma_type {
    TRS_ASYNC_DMA_TYPE_NORMAL = 0,
    TRS_ASYNC_DMA_TYPE_SQE_UPDATE,
    TRS_ASYNC_DMA_TYPE_2D,
    TRS_ASYNC_DMA_TYPE_BATCH,
    TRS_ASYNC_DMA_TYPE_MAX
};

struct trs_async_dma_input_para {
    enum trs_async_dma_type async_dma_type;
    drvSqCqType_t type;
    uint32_t tsId;
    uint32_t sqId;
    uint32_t dir;
    union {
        struct halAsyncDmaInputPara *async_normal_in;
        struct halAsyncDmaInput2DPara *async_2d_in;
        struct halAsyncDmaInputBatchPara *async_batch_in;
    };
};

struct trs_async_dma_destroy_para {
    enum trs_async_dma_type async_dma_type;
    drvSqCqType_t type;
    uint32_t tsId;
    uint32_t sqId;
    union {
        struct halAsyncDmaDestoryPara *normal_para;
        struct halAsyncDmaDestroy2DPara *async_2d_para;
        struct halAsyncDmaDestroyBatchPara *async_batch_para;
    };
};

static inline struct trs_async_dma_input_para trs_pack_async_dma_input_para(void *in,
    enum trs_async_dma_type async_dma_type, drvSqCqType_t type, uint32_t tsId, uint32_t sqId)
{
    struct trs_async_dma_input_para async_input = {0};
    async_input.async_dma_type = async_dma_type;
    async_input.async_normal_in = in;
    async_input.type = type;
    async_input.tsId = tsId;
    async_input.sqId = sqId;
    return async_input;
}

static inline struct trs_async_dma_destroy_para trs_pack_async_dma_destroy_para(void *in,
    enum trs_async_dma_type async_dma_type, drvSqCqType_t type, uint32_t tsId, uint32_t sqId)
{
    struct trs_async_dma_destroy_para destroy_para = {0};
    destroy_para.async_dma_type = async_dma_type;
    destroy_para.normal_para = in;
    destroy_para.type = type;
    destroy_para.tsId = tsId;
    destroy_para.sqId = sqId;
    return destroy_para;
}

#endif /* TRS_URMA_ASYNC_H */
