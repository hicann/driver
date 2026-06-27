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

#ifndef VPC_CMDLIST_PIPELINE_CHANNEL_H
#define VPC_CMDLIST_PIPELINE_CHANNEL_H

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#endif

#include "pipeline_define.h"

typedef struct VP_RD {
    uint64_t addr;
    uint32_t lineSize;
    uint32_t frameSize;
    uint32_t stride;
    uint8_t  yflipEn;
    uint32_t du;
    uint32_t pixelFmt;
} vp_rd_t;

typedef struct VP_WR {
    uint64_t addr;
    uint32_t stride;
    uint32_t lineSize;
    uint8_t yflipEn;
    uint32_t pixelFmt;
} vp_wr_t;

typedef struct VideoPorts {
    struct VP_RD rd[VP_RD_NUM];
    struct VP_WR wr[VP_WR_NUM];
} video_ports_t;

typedef struct NR_RD {
    uint8_t splitEn;
    uint8_t timeoutTrld;
    uint8_t allocatedDu;
    uint8_t en;
} nr_rd_t;

typedef struct NR_WR {
    uint8_t splitEn;
    uint8_t timeoutTrld;
} nr_wr_t;

typedef struct NonRasterPorts {
    struct NR_RD rd[NR_RD_NUM];
    struct NR_WR wr[NR_WR_NUM];
} nonraster_ports_t;

typedef struct Cvdr {
    struct VideoPorts vp;
    struct NonRasterPorts nr;
} cvdr_t;

typedef struct Cache {
    uint8_t en3d;
    uint8_t sramWrapEn;
    uint32_t runMode;
    uint64_t addr[3];
    uint32_t stride[3];
} cache_t;

typedef struct Rdma {
    uint32_t srcyhAddrL;
    uint32_t srcyhAddrH;
    uint32_t srcchAddrL;
    uint32_t srcchAddrH;
    uint32_t srcyhStride;
    uint32_t srcchStride;
    uint32_t srcyAddrL;
    uint32_t srcyAddrH;
    uint32_t srccAddrL;
    uint32_t srccAddrH;
    uint32_t srcyStride;
    uint32_t srccStride;
} rdma_t;

typedef struct Swap {
    uint8_t en;
    uint32_t inPos;
    uint32_t outPos;
} swap_t;

typedef struct UvUp {
    uint8_t en;
} uvup_t;

typedef struct CscMode {
    uint8_t fpPreOffset;
    uint8_t fpOrder;
    uint8_t fpFmacEn;
    uint8_t yForward;
    uint8_t calCore;
} csc_mode_t;

typedef struct CscCvtMode {
    uint32_t rndModeOut;
    uint32_t rndModeIn;
    uint8_t clipEnOut;
    uint8_t clipEnIn;
} csc_cvt_mode_t;

typedef struct Csc {
    uint8_t en;
    uint8_t alphaPaddingEn;
    uint8_t cscOut10bEn; // out不存在这一位
    struct CscMode cscMode;
    struct CscCvtMode cvtMode;
    uint32_t coeff[24];
    uint32_t clipThresh[6];
    uint32_t normalizeIn;
    uint32_t normalizeOut;
    uint32_t alpha;
} csc_t;

typedef struct UvDown {
    uint8_t uvCross;
    uint32_t uv444to422Coeff[6];
    // 422to420只有输出有
    uint8_t uv422to420FilteEn;
    uint8_t uv422to420ClipEn;
} uvdown_t;
#endif // #ifndef VPC_CMDLIST_PIPELINE_CHANNEL_H