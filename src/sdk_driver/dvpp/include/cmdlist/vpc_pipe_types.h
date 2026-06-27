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

#ifndef PIPE_VPC_VPC_TYPES_H
#define PIPE_VPC_VPC_TYPES_H

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#endif
#include "pipeline_top.h"

typedef enum {
    VPC_PIPE_PIXEL_FORMAT_YUV_400 = 0,
    VPC_PIPE_PIXEL_FORMAT_YUV_SEMIPLANAR_420 = 1,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMIPLANAR_420 = 2,
    VPC_PIPE_PIXEL_FORMAT_YUV_SEMIPLANAR_422 = 3,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMIPLANAR_422 = 4,
    VPC_PIPE_PIXEL_FORMAT_YUV_SEMIPLANAR_444 = 5,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMIPLANAR_444 = 6,
    VPC_PIPE_PIXEL_FORMAT_YUYV_PACKED_422 = 7,
    VPC_PIPE_PIXEL_FORMAT_UYVY_PACKED_422 = 8,
    VPC_PIPE_PIXEL_FORMAT_YVYU_PACKED_422 = 9,
    VPC_PIPE_PIXEL_FORMAT_VYUY_PACKED_422 = 10,
    VPC_PIPE_PIXEL_FORMAT_YUV_PACKED_444 = 11,
    VPC_PIPE_PIXEL_FORMAT_RGB_888 = 12,
    VPC_PIPE_PIXEL_FORMAT_BGR_888 = 13,
    VPC_PIPE_PIXEL_FORMAT_ARGB_8888 = 14,
    VPC_PIPE_PIXEL_FORMAT_ABGR_8888 = 15,
    VPC_PIPE_PIXEL_FORMAT_RGBA_8888 = 16,
    VPC_PIPE_PIXEL_FORMAT_BGRA_8888 = 17,
    VPC_PIPE_PIXEL_FORMAT_YUV_SEMI_PLANNER_420_10BIT = 18,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMI_PLANNER_420_10BIT = 19,
    VPC_PIPE_PIXEL_FORMAT_YVU_PLANAR_420 = 20,
    VPC_PIPE_PIXEL_FORMAT_YVU_PLANAR_422 = 21,
    VPC_PIPE_PIXEL_FORMAT_YVU_PLANAR_444 = 22,
    VPC_PIPE_PIXEL_FORMAT_RGB_444 = 23,
    VPC_PIPE_PIXEL_FORMAT_BGR_444 = 24,
    VPC_PIPE_PIXEL_FORMAT_ARGB_4444 = 25,
    VPC_PIPE_PIXEL_FORMAT_ABGR_4444 = 26,
    VPC_PIPE_PIXEL_FORMAT_RGBA_4444 = 27,
    VPC_PIPE_PIXEL_FORMAT_BGRA_4444 = 28,
    VPC_PIPE_PIXEL_FORMAT_RGB_555 = 29,
    VPC_PIPE_PIXEL_FORMAT_BGR_555 = 30,
    VPC_PIPE_PIXEL_FORMAT_RGB_565 = 31,
    VPC_PIPE_PIXEL_FORMAT_BGR_565 = 32,
    VPC_PIPE_PIXEL_FORMAT_ARGB_1555 = 33,
    VPC_PIPE_PIXEL_FORMAT_ABGR_1555 = 34,
    VPC_PIPE_PIXEL_FORMAT_RGBA_1555 = 35,
    VPC_PIPE_PIXEL_FORMAT_BGRA_1555 = 36,
    VPC_PIPE_PIXEL_FORMAT_ARGB_8565 = 37,
    VPC_PIPE_PIXEL_FORMAT_ABGR_8565 = 38,
    VPC_PIPE_PIXEL_FORMAT_RGBA_8565 = 39,
    VPC_PIPE_PIXEL_FORMAT_BGRA_8565 = 40,
    VPC_PIPE_PIXEL_FORMAT_ARGB_CLUT2 = 41,
    VPC_PIPE_PIXEL_FORMAT_ARGB_CLUT4 = 42,

    VPC_PIPE_PIXEL_FORMAT_YVU_PACKED_420_TILE = 45,

    VPC_PIPE_PIXEL_FORMAT_RGB_BAYER_8BPP = 50,
    VPC_PIPE_PIXEL_FORMAT_RGB_BAYER_10BPP = 51,
    VPC_PIPE_PIXEL_FORMAT_RGB_BAYER_12BPP = 52,
    VPC_PIPE_PIXEL_FORMAT_RGB_BAYER_14BPP = 53,
    VPC_PIPE_PIXEL_FORMAT_RGB_BAYER_16BPP = 54,
    VPC_PIPE_PIXEL_FORMAT_YUV_PLANAR_420 = 55,
    VPC_PIPE_PIXEL_FORMAT_YUV_PLANAR_422 = 56,
    VPC_PIPE_PIXEL_FORMAT_YUV_PLANAR_444 = 57,
    VPC_PIPE_PIXEL_FORMAT_YVU_PACKED_444 = 58,
    VPC_PIPE_PIXEL_FORMAT_XYUV_PACKED_444 = 59,
    VPC_PIPE_PIXEL_FORMAT_XYVU_PACKED_444 = 60,
    VPC_PIPE_PIXEL_FORMAT_YUV_SEMIPLANAR_411 = 61,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMIPLANAR_411 = 62,
    VPC_PIPE_PIXEL_FORMAT_YUV_PLANAR_411 = 63,
    VPC_PIPE_PIXEL_FORMAT_YVU_PLANAR_411 = 64,
    VPC_PIPE_PIXEL_FORMAT_YUV_PLANAR_440 = 65,
    VPC_PIPE_PIXEL_FORMAT_YVU_PLANAR_440 = 66,

    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR = 69,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR = 70,
    VPC_PIPE_PIXEL_FORMAT_HSV_888_PACKAGE = 71,
    VPC_PIPE_PIXEL_FORMAT_HSV_888_PLANAR = 72,
    VPC_PIPE_PIXEL_FORMAT_LAB_888_PACKAGE = 73,
    VPC_PIPE_PIXEL_FORMAT_LAB_888_PLANAR = 74,
    VPC_PIPE_PIXEL_FORMAT_S8C1 = 75,
    VPC_PIPE_PIXEL_FORMAT_S8C2_PACKAGE = 76,
    VPC_PIPE_PIXEL_FORMAT_S8C2_PLANAR = 77,
    VPC_PIPE_PIXEL_FORMAT_S16C1 = 78,
    VPC_PIPE_PIXEL_FORMAT_U8C1 = 79,
    VPC_PIPE_PIXEL_FORMAT_U16C1 = 80,
    VPC_PIPE_PIXEL_FORMAT_S32C1 = 81,
    VPC_PIPE_PIXEL_FORMAT_U32C1 = 82,
    VPC_PIPE_PIXEL_FORMAT_U64C1 = 83,
    VPC_PIPE_PIXEL_FORMAT_S64C1 = 84,

    VPC_PIPE_PIXEL_FORMAT_RGB_888_INT8 = 110,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_INT8 = 111,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_INT16 = 112,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_INT16 = 113,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_INT32 = 114,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_INT32 = 115,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_UINT16 = 116,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_UINT16 = 117,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_UINT32 = 118,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_UINT32 = 119,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_INT8  = 120,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_INT8  = 121,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_INT16 = 122,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_INT16 = 123,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_INT32 = 124,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_INT32 = 125,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_UINT16 = 126,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_UINT16 = 127,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_UINT32 = 128,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_UINT32 = 129,
    VPC_PIPE_PIXEL_FORMAT_YUV400_UINT16 = 130,
    VPC_PIPE_PIXEL_FORMAT_YUV400_UINT32 = 131,
    VPC_PIPE_PIXEL_FORMAT_YUV400_UINT64 = 132,
    VPC_PIPE_PIXEL_FORMAT_YUV400_INT8   = 133,
    VPC_PIPE_PIXEL_FORMAT_YUV400_INT16  = 134,
    VPC_PIPE_PIXEL_FORMAT_YUV400_INT32  = 135,
    VPC_PIPE_PIXEL_FORMAT_YUV400_INT64  = 136,
    VPC_PIPE_PIXEL_FORMAT_YUV400_FP16 = 137,
    VPC_PIPE_PIXEL_FORMAT_YUV400_FP32 = 138,
    VPC_PIPE_PIXEL_FORMAT_YUV400_FP64 = 139,
    VPC_PIPE_PIXEL_FORMAT_YUV400_BF16 = 140,

    VPC_PIPE_FORMAT_RAW12_PLANAR = 180,
    VPC_PIPE_FORMAT_RAW12_BAYER_RGGB = 181,
    VPC_PIPE_FORMAT_RAW12_BAYER_BGGR = 182,
    VPC_PIPE_FORMAT_RAW12_BAYER_GRBG = 183,
    VPC_PIPE_FORMAT_RAW12_BAYER_GBRG = 184,

    VPC_PIPE_PIXEL_FORMAT_YUV_SEMIPLANAR_440 = 1000,
    VPC_PIPE_PIXEL_FORMAT_YVU_SEMIPLANAR_440 = 1001,
    VPC_PIPE_PIXEL_FORMAT_FLOAT32 = 1002,
    VPC_PIPE_PIXEL_FORMAT_BUTT = 1003,

    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_FP16 = 1004,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_FP16 = 1005,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_FP32 = 1006,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_FP32 = 1007,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_PLANAR_BF16 = 1008,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_PLANAR_BF16 = 1009,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_FP16 = 1010,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_FP16 = 1011,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_FP32 = 1012,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_FP32 = 1013,
    VPC_PIPE_PIXEL_FORMAT_RGB_888_BF16 = 1014,
    VPC_PIPE_PIXEL_FORMAT_BGR_888_BF16 = 1015,

    VPC_PIPE_PIXEL_FORMAT_UNKNOWN = 10000,

    VPC_PIPE_PIXEL_FORMAT_UVY_PACKED_444 = 10001,
    VPC_PIPE_PIXEL_FORMAT_VUY_PACKED_444 = 10002,
} vpc_pipe_pic_fmt_t;

typedef enum {
    VPC_PIPE_CSC_MATRIX_BT601_WIDE = 0,
    VPC_PIPE_CSC_MATRIX_BT601_NARROW,
    VPC_PIPE_CSC_MATRIX_BT709_WIDE,
    VPC_PIPE_CSC_MATRIX_BT709_NARROW,
    VPC_PIPE_CSC_MATRIX_BT2020_WIDE,
    VPC_PIPE_CSC_MATRIX_BT2020_NARROW,
    VPC_PIPE_CSC_MATRIX_USER = 100,
    VPC_PIPE_CSC_MATRIX_BUTT
} vpc_pipe_csc_matrix_e;

typedef enum {
    YUV_FIELD,
    RGB_FIELD,
    GRAY_FIELD,
    YUV_FP32_FIELD,
    RGB_FP32_FIELD,
    GRAY_FP32_FIELD,
    FP32_FIELD,
} vpc_pipe_format_field_e;

typedef enum {
    VPC_PIPE_BLEND_ALPHA_BLENDING = 0,
    VPC_PIPE_BLEND_MAX,
    VPC_PIPE_BLEND_MIN,
    VPC_PIPE_BLEND_ABS_DIFF,
    VPC_PIPE_BLEND_BITWISE_AND,
    VPC_PIPE_BLEND_BITWISE_OR,
    VPC_PIPE_BLEND_BITWISE_XOR,
    VPC_PIPE_BLEND_ADD_WEIGHT,
    VPC_PIPE_BLEND_MASK,
} vpc_pipe_blending_type_e;

typedef enum {
    VPC_PIPE_BORDER_CONSTANT = 0,
    VPC_PIPE_BORDER_REPLICATE,
    VPC_PIPE_BORDER_REFLECT,
    VPC_PIPE_BORDER_REFLECT_101,
    VPC_PIPE_BORDER_WRAP
} vpc_pipe_bord_type_e;

typedef enum {
    VPC_PIPE_MINI_V2 = 0,
    VPC_PIPE_CLOUD_V2,
    VPC_PIPE_CLOUD_V4,
    VPC_PIPE_MDC_V52,
    VPC_PIPE_SUP_CHIP_END,
} vpc_pipe_chip_type_e;

typedef enum {
    VPC_PIPE_BLK_SIZE_4 = 0,    /* block size 4*4 */
    VPC_PIPE_SIZE_8,        /* block size 8*8 */
    VPC_PIPE_SIZE_16,       /* block size 16*16 */
    VPC_PIPE_SIZE_32,       /* block size 32*32 */
    VPC_PIPE_SIZE_64,       /* block size 64*64 */
    VPC_PIPE_SIZE_128,      /* block size 128*128 */
} vpc_pipe_blk_size_e;

typedef enum {
    VPC_PIPE_BILINEAR = 0,
    VPC_PIPE_NEAREST,
    VPC_PIPE_BICUBIC,
    VPC_PIPE_AREA,
    VPC_PIPE_YUV_SCALE,
    VPC_PIPE_BILINEAR_ABANDONED, // PG1
    VPC_PIPE_NEAREST_ABANDONED,        // PG1
} vpc_pipe_resize_mode_e;

typedef struct {
    void* picture_address;
    uint32_t picture_buffer_size;
    uint32_t picture_width;
    uint32_t picture_height;
    uint32_t picture_width_stride;
    uint32_t picture_height_stride;
    vpc_pipe_pic_fmt_t picture_format;
} vpc_pipe_pic_info_t;

typedef  struct {
    uint64_t luma_head_addr;
    uint64_t chroma_head_addr;
    uint64_t luma_payload_addr;
    uint64_t chroma_payload_addr;
    uint32_t luma_head_stride;
    uint32_t chroma_head_stride;
    uint32_t luma_payload_stride;
    uint32_t chroma_payload_stride;
    uint32_t width;
    uint32_t height;
    vpc_pipe_pic_fmt_t picture_format;
} vpc_hfbc_info_t;

typedef struct {
    uint32_t top_offset;
    uint32_t left_offset;
    uint32_t crop_width;
    uint32_t crop_height;
} vpc_pipe_crop_para_t;

typedef struct {
    uint32_t in_width;
    uint32_t in_height;
    uint32_t out_width;
    uint32_t out_height;
    uint32_t interpolation;
} vpc_pipe_resize_para_t;

typedef struct csc_coeff {
    int64_t yuv_to_rgb_coeff[12];
    int64_t rgb_to_yuv_coeff[12];
} vpc_pipe_csc_coeff_t;

typedef struct user_coeff {
    double yuv_to_rgb_coeff[12];
    double rgb_to_yuv_coeff[12];
} vpc_pipe_user_coeff_t;

typedef struct csc_info {
    uint32_t csc_matrix;
    vpc_pipe_csc_coeff_t csc_coeff;
    vpc_pipe_user_coeff_t user_coeff;
    uint32_t is_universal_coeff;
    int64_t universal_convert_coeff[12];
} vpc_pipe_csc_info_t;

typedef struct {
    uint32_t left;
    uint32_t right;
    uint32_t top;
    uint32_t bottom;
} vpc_pipe_split_coord_t;

typedef struct {
    vpc_pipe_split_coord_t in;
    vpc_pipe_split_coord_t out;
} vpc_pipe_split_para_t;

typedef struct  {
    uint32_t alpha;
    uint32_t beta;
    uint32_t gamma;
} vpc_pipe_blend_add_weight_config_t;

typedef struct {
    uint8_t map_value_y_or_r[256]; // remap value of Y or R component
    uint8_t map_value_u_or_g[256]; // remap value of U or G component
    uint8_t map_value_v_or_b[256]; // remap value of V or B component
    uint8_t  lutSecondaryPointerEn;
    uint32_t mapYorRAddrHigh;
    uint32_t mapYorRAddrLow;
    uint32_t mapUorGAddrHigh;
    uint32_t mapUorGAddrLow;
    uint32_t mapVorBAddrHigh;
    uint32_t mapVorBAddrLow;
} vpc_pipe_lut_remap_t;

typedef struct {
    uint32_t mapYorRAddrHigh;
    uint32_t mapYorRAddrLow;
    uint32_t mapUorGAddrHigh;
    uint32_t mapUorGAddrLow;
    uint32_t mapVorBAddrHigh;
    uint32_t mapVorBAddrLow;
} vpc_pipe_lut_table_addr_t;

typedef struct {
    uint32_t val[4];
} vpc_pipe_scalar_t;

typedef struct {
    uint32_t top;
    uint32_t bottom;
    uint32_t left;
    uint32_t right;
    vpc_pipe_bord_type_e border_type;
    vpc_pipe_scalar_t scalar_value;
} vpc_pipe_make_border_info_t;

typedef struct {
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
} vpc_pipe_rect_t;

typedef struct {
    vpc_pipe_blk_size_e blk_size;
    vpc_pipe_rect_t rect;
} vpc_pipe_mosaic_t;

#endif // #ifndef PIPE_VPC_VPC_TYPES_H
