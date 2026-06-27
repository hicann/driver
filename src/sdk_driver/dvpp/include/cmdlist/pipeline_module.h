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

#ifndef VPC_CMDLIST_PIPELINE_MODULE_H
#define VPC_CMDLIST_PIPELINE_MODULE_H

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#endif

#include "pipeline_define.h"
#include "pipeline_kernel.h"
#include "pipeline_channel.h"

typedef struct Top {
    uint8_t vpcStart;
    uint32_t in0Height;
    uint32_t in0Width;
    uint32_t in1Height;
    uint32_t in1Width;
    uint32_t outHeight;
    uint32_t outWidth;
    uint32_t out1Height;
    uint32_t out1Width;
    uint32_t out2Height;
    uint32_t out2Width;
    uint32_t in0Format;
    uint32_t in1Format;
    uint32_t outFormat;
    uint32_t out1Format;
    uint32_t out2Format;
    uint32_t bitWidth;
    uint32_t rdChannelSel;
    // add for milanV1R3
    uint32_t out1To3En;
    uint32_t multiLevelZoomEn;

    uint32_t errMask;
    uint32_t pipeIntMerge;
} top_t;

typedef struct IrCsc {
    uint8_t en;
    uint8_t bayerMode;
    uint8_t startetrixEn;
    uint8_t interlaceEn;
    uint8_t renormEn;
    uint8_t degammaEn;
    uint8_t outRgbFlg;
    uint16_t gammaCoef[257]; // ��Ҫ257��ϵ�� 
    uint64_t readAddr;
    uint8_t readEn;
} ircsc_t;

typedef struct Level2Pointer {
    uint8_t srcEn;
    uint8_t dstEn;
} level2_pointer_t;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif // #ifdef __cplusplus

void vp_disable(struct VideoPorts *vp);

uint8_t crop_en(struct Crop *crop);
void crop_disable(struct Crop *crop);

uint8_t padding_en(struct Padding *padding);
void padding_disable(struct Padding *padding);

uint8_t flip_en(struct Flip *flip);
void flip_disable(struct Flip *flip);

uint8_t resize_en(struct Resize *resize);
void resize_disable(struct Resize *resize);

uint8_t yuvscaler_en(struct YuvScale *scaler);
void yuvscaler_disable(struct YuvScale *scaler);
void yuvscaler_bypass(struct YuvScale *scaler);

void hsv_disable(struct Hsv *hsv);
uint8_t hsv_en(struct Hsv *hsv);
void affine_disable(struct Affine *affine);
void pixaug_disable(struct PixAug *pixaug);

uint8_t mosaic_en(struct Mosaic *mosaic);
void mosaic_disable(struct Mosaic *mosaic);
uint8_t cover_en(struct Cover *cover);
void cover_disable(struct Cover *cover);
uint8_t osd_en(struct Osd *osd);
void osd_disable(struct Osd *osd);

void csc_disable(struct Csc *csc);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif // #ifdef __cplusplus


#endif // #ifndef VPC_CMDLIST_PIPELINE_MODULE_H
