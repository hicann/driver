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
#ifndef VPC_CMDLIST_PIPELINE_TOP_H
#define VPC_CMDLIST_PIPELINE_TOP_H

#include "pipeline_module.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PipleLineTop {
    enum VpcPictureFormat kernelFmt;
    enum ChannelOutType channelOut;
};

struct PipeLineInput {
    struct Swap in0Swap;
    struct UvUp in0Uvup;
    struct Csc in0Csc;
    struct UvDown in0UvDown;
    struct Swap in1Swap;
    struct UvUp in1Uvup;
    struct Csc in1Csc;
    struct UvDown in1UvDown;
    struct IrCsc in0IrCsc;
};

struct PipeLineKernel {
    struct Crop preCrop;
    struct Padding prePadding;
    struct Resize resize[PIPE_KERNEL_NUM];
    struct YuvScale yuvScale[PIPE_KERNEL_NUM];
    struct Crop postCrop[PIPE_KERNEL_NUM];
    struct Padding postPadding[PIPE_KERNEL_NUM];

    struct Flip flip;
    struct Mosaic mosaic;
    struct Rotate rotate;
    struct Cover cover;
    struct Osd osd;
    struct Histogram histogram;
    struct Lut lut;
    struct Blend blend;
    struct Hsv hsv;
    struct Filter filter;
    struct PixAug pixaug;
    struct Affine affine;
    struct Convert convert;
    struct DumpReg dumpReg;
    struct DataTransform dataTransform;
    struct Pyramid pyramid;
    struct Level2Pointer level2Pointer;
};

struct PipeLineOutput {
    struct Swap swap;
    struct UvUp uvUp;
    struct Csc csc;
    struct UvDown uvDown;
};

struct Channel {
    struct Cvdr cvdr;
    struct Cache cache;
    struct Rdma rdma;
    uint8_t earlyRunEn;
};

struct PipeLine {
    struct PipleLineTop top;
    struct PipeLineInput input;
    struct PipeLineKernel kernel;
    struct PipeLineOutput output[PIPE_OUT_NUM];
};

typedef struct Roi {
    uint32_t hmin;
    uint32_t hmax;
    uint32_t vmin;
    uint32_t vmax;
    uint32_t width;
    uint32_t height;
} roi_t;

typedef struct {
    struct Top top;
    struct Channel channel;
    struct PipeLine pipe;
} vpu_vpc_config_t;

void reset_pipeline(struct Top *top, struct Channel *channel, struct PipeLine *pipeline);

#ifdef __cplusplus
}
#endif
#endif // #ifndef VPC_CMDLIST_PIPELINE_TOP_H
