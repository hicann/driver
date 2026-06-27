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

#ifndef VPC_CMDLIST_PIPELINE_DEFINE_H
#define VPC_CMDLIST_PIPELINE_DEFINE_H

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#endif

#define ENABLE 1
#define DISABLE 0

#define COLOR_CHANNEL_NUM 4
#define PORT_STEP 3

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3
#define PORT4 4
#define PORT5 5
#define PORT6 6
#define PORT7 7
#define PORT8 8
#define PORT9 9
#define PORT10 10
#define PORT11 11
#define PORT12 12
#define PORT13 13
#define PORT14 14
#define PORT15 15
#define X_DIR 0
#define Y_DIR 1

#define PIPE_KERNEL_NUM 2
#define PIPE_OUT_NUM 3
#define SUB_CHN_NUM 2
#define MAIN_CHN 0
#define SUB_CHN_1 1
#define SUB_CHN_2 2

#define SCALER_COFF_NB_4 128
#define SCALER_COFF_NB_6 192
#define SCALER_COFF_NB_8 256

#define MAX_PARA_COUNT 2048
#define VP_RD_NUM 11
#define VP_WR_NUM 16
#define NR_RD_NUM 4
#define NR_WR_NUM 2
#define MAX_MOSAIC_NUM 4
#define MIN_MOSAIC_REGION_WIDTH 8
#define MIN_MOSAIC_REGION_HEIGHT 8
#define SCALER_RADIO_1_TIME 0x100000
#define SCALER_BIT_MOVE_TO_OLD_INC 4
#define MAX_COVER_NUM 8
#define MAX_LINE_NUM 8
#define MAX_OSD_NUM 8

#define YUV_SCALER_BYPASS 3
#define YUV_SCALER_ENABLE_HOR 1
#define YUV_SCALER_ENABLE_VER 2

#define MOSAIC_REGION_NUM 4
#define COVER_REGION_NUM 8
#define OSD_REGION_NUM 8

#define VPC_BORDER_CONSTANT 0

typedef enum ImageRankType {
    NV12 = 0, // 0
    NV21,     // 1
    YUYV,     // 2
    YVYU,     // 3
    UYVY,     // 4
    VYUY,     // 5
    YUV,      // 6
    YVU,      // 7
    RGB,      // 8
    BGR,      // 9
    RGBA,     // 10
    BGRA,     // 11
    ARGB,     // 12
    ABGR,     // 13
    UVY,      // 14 only warp use UVY and VUY
    VUY,      // 15
    BGR_PLANAR, // 16 disable swap, and software switching the address of port0, port2
    YVU_PLANAR, // 17 disable swap, and software switching the address of port1, port2
    XYUV, // 18
    RANK_BUTT = 100
} img_rank_type_e;

typedef enum VpcPixelFormat {
    D8 = 0,
    D16 = 1,
    D24 = 2,
    D32 = 3,
    D48 = 4,
    D64 = 5,
    D96 = 6,
    YUV422PKT = 15,
    IDEL = 100
} vpc_pixel_fmt_e;

typedef enum PlannarFormat {
    YUV_PLANNAR = 0,
    RGB_PLANNAR,
    BUTT_PLANNAR,
} plannar_fmt_e;

typedef enum VpcPictureFormat {
    YUV420_SEMI_PLANNAR = 0x00,
    YUV422_SEMI_PLANNAR = 0x01,
    YUV444_SEMI_PLANNAR = 0x02,
    YUV440_SEMI_PLANNAR = 0x03,
    YUV411_SEMI_PLANNAR = 0x04,
    YUV420_PLANNAR = 0x10,
    YUV422_PLANNAR = 0x11,
    YUV444_PLANNAR = 0x12,
    YUV440_PLANNAR = 0x13,
    YUV411_PLANNAR = 0x14,

    RGB888_PLANNAR = 0x20,
    RGB888_PLANNAR_FP16 = 0x21,
    RGB888_PLANNAR_FP32 = 0x22,
    RGB888_PLANNAR_BF16 = 0x23,
    RGB888_PLANNAR_INT16 = 0x24,
    RGB888_PLANNAR_INT32 = 0x25,
    RGB888_PLANNAR_INT64 = 0x26,
    RGB888_PLANNAR_UINT16 = 0x27,
    RGB888_PLANNAR_UINT32 = 0x28,
    RGB888_PLANNAR_UINT64 = 0x29,
    RGB888_PLANNAR_INT8 = 0x2A,

    YUV422_PACKED = 0x30,
    YUV444_PACKED = 0x31,
    XYUV444_PACKED = 0x32,
    YUV420_TILE_32x4 = 0x33,

    RGB888_PACKED = 0x40,
    XRGB8888_PACKED = 0x41,
    RGB888_PACKED_FP16 = 0x42,
    RGB888_PACKED_FP32 = 0x43,
    RGB888_PACKED_BF16 = 0x44,
    RGB888_PACKED_INT16 = 0x45,
    RGB888_PACKED_INT32 = 0x46,

    RGB888_PACKED_UINT16 = 0x48,
    RGB888_PACKED_UINT32 = 0x49,

    RGB888_PACKED_INT8 = 0x4B,

    YUV400 = 0x50,
    YUV400_FP16 = 0x51,
    YUV400_FP32 = 0x52,
    YUV400_FP64 = 0x53,
    YUV400_BF16 = 0x54,
    YUV400_INT16 = 0x55,
    YUV400_INT32 = 0x56,
    YUV400_INT64 = 0x57,
    YUV400_UINT16 = 0x58,
    YUV400_UINT32 = 0x59,
    YUV400_UINT64 = 0x5A,
    YUV400_INT8 = 0x5B,

    RAW12_YYUV = 0x60,
    RAW12_RGGB = 0x61,

    VPC_PICTURE_FORMAT_BUTT
} vpc_pic_fmt_e;

typedef enum UvupMethod {
    DUPLICATE,
    INTERPOLATION,
    UVUP_METHOD_BUTT,
} uvup_method_e;

typedef enum ChannelOutType {
    AI_CHANNEL_OUT,
    RAW12_CHANNEL_OUT = 1,
    PYRAMID_CHANNEL_OUT = 1,
    TRANSFORAM_CHANNEL_OUT = 2,
    POINTNET_CHANNEL_OUT = 2,
    WRAP_CHANNEL_OUT,
    NORMAL_BLEND_CHANNEL_OUT,
    MULTI_BLEND_CHANNEL_OUT,
    AFFINE_CHANNEL_OUT,
    CHANNEL_OUT_TYPE_BUTT
} channel_out_type_e;

typedef enum ReadType {
    RDMA_CHANNEL,
    CVDR_CHANNEL,
    CACHE_CHANNEL,
    ROTATE_CHANNEL
} read_type_e;

typedef enum BitWidth {
    BIT_8,
    BIT_10
} bitwidth_e;

typedef enum CacheRunMode {
    PADDING_OR_BLKTRANS,
    AFFINE_BILINEAR,
    AFFINE_NEAREST,
    AFFINE_BILINEAR_3D,
    AFFINE_NEAREST_3D
} cache_run_mode_e;

typedef enum MultiLevelZoom {
    SERIES_MODE = 1,
    ONE_TO_THREE_MODE = 2,
    DUAL_PYRAMID_MODE = 3
} multi_level_zoom_e;

typedef enum RndMode {
    RND_NEAREST_EVEN,   // 四舍六入
    RND_ZERO,           // 截断舍入
    RND_POS_INF,        // 舍入到更大的数
    RND_NEG_INF,        // 舍入到更小的数
    RND_NEAREST_UP,     // 舍入到更近的浮点刻度
    RND_AWAY_FROM_ZERO, // 舍入到距离“零点”最远的那个数
    RND_NORMAL,         // 四舍五入，加0.5后截断
    RND_BUTT
} run_mode_e;

typedef enum TransformMode {
    TRANSFORM_MODE_NONE,
    TRANSFORM_MODE_ROTATE,
    TRANSFORM_MODE_CROP,
    TRANSFORM_MODE_DMA,
} transform_mode_e;

#endif // #ifndef VPC_CMDLIST_PIPELINE_DEFINE_H
