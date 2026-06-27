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

#include "vpc_pipe_comm.h"
#include "securec.h"
#include "vpc_pipe_resize.h"
#include "vpc_pipe_yuvscaler.h"

static void get_yuvscaler_para(uint32_t inc, yuvscaler_para_t *para)
{
    uint32_t i;
    const struct yuv_scaler_array* coeff = search_scaler_para(inc);

    for (i = 0; i < NUM_32; i++) {
        para->taps4[i] = coeff->taps4[i];
    }

    for (i = 0; i < NUM_48; i++) {
        para->taps6[i] = coeff->taps6[i];
    }
}

static void set_yuv_scaler_para(yuvscaler_t *yuvscaler, uint32_t in_width, uint32_t in_height,
    uint32_t out_width, uint32_t out_height)
{
    const uint32_t SCALER_BIT_MOVE = 16;
    const uint32_t SCALER_RADIO_1_TIME_MILAN = 0x10000;
    if (out_width == in_width) {
        yuvscaler->ihinc = SCALER_RADIO_1_TIME_MILAN;
        yuvscaler->bypass |= 0x1;
    } else {
        yuvscaler->ihinc = ((uint64_t)(in_width) << SCALER_BIT_MOVE) / out_width;
    }

    if (out_height == in_height) {
        yuvscaler->ivinc = SCALER_RADIO_1_TIME_MILAN;
        yuvscaler->bypass |= 0x2;
    } else {
        yuvscaler->ivinc = ((uint64_t)(in_height) << SCALER_BIT_MOVE) / out_height;
    }
    if (yuvscaler->bypass == 0x3) {
        return;
    }

    yuvscaler->ihleftInt = 0;
    yuvscaler->ivtopInt = 0;
    yuvscaler->ihrightInt = (uint32_t)(yuvscaler->ihinc * (out_width - 1));
    yuvscaler->ivbotInt = (uint32_t)(yuvscaler->ivinc * (out_height - 1));

    yuvscaler->inWidth = in_width;
    yuvscaler->inHeight = in_height;
    yuvscaler->outWidth = out_width;
    yuvscaler->outHeight = out_height;
    (void)memset_s(&yuvscaler->coeff.scale, sizeof(yuvscaler->coeff.scale), 0, sizeof(yuvscaler->coeff.scale));
    get_yuvscaler_para((uint32_t)yuvscaler->ihinc, &yuvscaler->coeff.scale[0]);
    get_yuvscaler_para((uint32_t)yuvscaler->ivinc, &yuvscaler->coeff.scale[1]);
}

static void vpc_pipe_set_yuvscaler(const vpc_pipe_ctx_t *ctx, vpc_pipe_resize_para_t *para, uint32_t chn)
{
    (void)chn;
    uint32_t in_height;
    uint32_t in_width;
    uint32_t out_height;
    uint32_t out_width;
    vpc_pipe_resize_para_t pre_scale;

    in_height = para->in_height;
    in_width = para->in_width;
    out_height = para->out_height;
    out_width = para->out_width;

    PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN].bypass = 0;

    pre_scale.in_width = in_width;
    pre_scale.in_height = in_height;
    pre_scale.interpolation = VPC_PIPE_YUV_SCALE;
    if (judge_use_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN], in_width, in_height, out_width, out_height);
    } else if (judge_use_1prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        // 模拟一个pre scale，缩小2倍
        pre_scale.out_height = in_height / NUM_2;
        pre_scale.out_width = in_width / NUM_2;
        vpc_pipe_set_resize(ctx, &pre_scale, MAIN_CHN);
        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN],
            in_width / NUM_2, in_height / NUM_2, out_width, out_height);
    } else if (judge_use_2prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        // 模拟两个pre scale，缩小4倍
        pre_scale.out_height = in_height / NUM_4;
        pre_scale.out_width = in_width / NUM_4;
        vpc_pipe_set_resize(ctx, &pre_scale, MAIN_CHN);
        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN],
            in_width / NUM_4, in_height / NUM_4, out_width, out_height);
    } else if (judge_use_3prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        // 模拟三个pre scale，缩小8倍
        pre_scale.out_height = in_height / NUM_8;
        pre_scale.out_width = in_width / NUM_8;
        vpc_pipe_set_resize(ctx, &pre_scale, MAIN_CHN);
        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN],
            in_width / NUM_8, in_height / NUM_8, out_width, out_height);
    }
}

static void vpc_pipe_set_normalize(const vpc_pipe_ctx_t *ctx, normalize_t *para)
{
    PIPELINE_(ctx).kernel.pixaug.normalize = *para;
    PIPELINE_(ctx).kernel.pixaug.normalize.en = 1;
}

static void vpc_pipe_set_hsv(const vpc_pipe_ctx_t *ctx, hsv_t *para)
{
    PIPELINE_(ctx).kernel.hsv.deltaHue = para->deltaHue;
    PIPELINE_(ctx).kernel.hsv.scaleSat = para->scaleSat;
    PIPELINE_(ctx).kernel.hsv.hueEn = para->hueEn;
    PIPELINE_(ctx).kernel.hsv.satEn = para->satEn;
    PIPELINE_(ctx).kernel.hsv.hsv2rgbEn = 1;
    PIPELINE_(ctx).kernel.hsv.rgb2hsvEn = 1;
}

static void vpc_pipe_set_clip(const vpc_pipe_ctx_t *ctx, vpc_clip_t *para)
{
    PIPELINE_(ctx).kernel.pixaug.clip = *para;
    PIPELINE_(ctx).kernel.pixaug.clip.en = 1;
}

static void vpc_pipe_set_enhance(const vpc_pipe_ctx_t *ctx, enhance_t *para)
{
    PIPELINE_(ctx).kernel.pixaug.enhance = *para;
    PIPELINE_(ctx).kernel.pixaug.enhance.en = 1;
}

static void vpc_pipe_set_convert(const vpc_pipe_ctx_t *ctx)
{
    const uint32_t one_per_255 = 0x3b808081;
    PIPELINE_(ctx).kernel.convert.en = 1;
    PIPELINE_(ctx).kernel.convert.scaleEn = 1;
    PIPELINE_(ctx).kernel.convert.rnd = RND_NEAREST_EVEN;
    PIPELINE_(ctx).kernel.convert.scale = one_per_255;
}

static void vpc_pipe_set_contrast(const vpc_pipe_ctx_t *ctx, contrast_t *para)
{
    PIPELINE_(ctx).kernel.pixaug.contrast = *para;
    PIPELINE_(ctx).kernel.pixaug.contrast.en = 1;
}

static void vpc_pipe_set_prepadding(const vpc_pipe_ctx_t *ctx,
    vpc_pipe_make_border_info_t *para, uint32_t in_width, uint32_t in_height)
{
    PIPELINE_(ctx).kernel.prePadding.en = 1;
    PIPELINE_(ctx).kernel.prePadding.paddingSel = para->border_type;
    PIPELINE_(ctx).kernel.prePadding.mirrorMode = 0;
    if (para->border_type == VPC_PIPE_BORDER_REFLECT) { // mirror 2 ba|abc*******fgh|hg;
        PIPELINE_(ctx).kernel.prePadding.mirrorMode = NUM_1;
        PIPELINE_(ctx).kernel.prePadding.paddingSel = NUM_2;
    } else if (para->border_type == VPC_PIPE_BORDER_WRAP) {
        PIPELINE_(ctx).kernel.prePadding.paddingSel = NUM_3;
    } else if (para->border_type == VPC_PIPE_BORDER_REFLECT_101) { // mirror 1 cb|abc****fgh|gf;
        PIPELINE_(ctx).kernel.prePadding.paddingSel = NUM_2;
    } 

    PIPELINE_(ctx).kernel.prePadding.bottomSize = para->bottom;
    PIPELINE_(ctx).kernel.prePadding.topSize = para->top;
    PIPELINE_(ctx).kernel.prePadding.rightSize = para->right;
    PIPELINE_(ctx).kernel.prePadding.leftSize = para->left;
    PIPELINE_(ctx).kernel.prePadding.inHeight = in_height - 1;
    PIPELINE_(ctx).kernel.prePadding.inWidth = in_width - 1;
}

static void vpc_pipe_set_postpadding(const vpc_pipe_ctx_t *ctx,
    vpc_pipe_make_border_info_t *para, uint32_t in_width, uint32_t in_height, uint32_t chn)
{
    (void)chn;
    const uint32_t MASKR = 0x00FF0000;
    const uint32_t MASKG = 0x0000FF00;
    const uint32_t MASKB = 0x000000FF;

    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].en = 1;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].paddingSel = para->border_type;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].bottomSize = para->bottom;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].topSize = para->top;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].rightSize = para->right;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].leftSize = para->left;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].inHeight = in_height - 1;
    PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].inWidth = in_width - 1;

    if (para->border_type == VPC_PIPE_BORDER_CONSTANT) {
        if ((PIPELINE_(ctx).top.kernelFmt == YUV400_FP32) || (PIPELINE_(ctx).top.kernelFmt == RGB888_PACKED_FP32)) {
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueHor[0] = para->scalar_value.val[0];
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueHor[1] = para->scalar_value.val[1];
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueHor[NUM_2] = para->scalar_value.val[NUM_2];
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueVer[0] = para->scalar_value.val[0];
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueVer[1] = para->scalar_value.val[1];
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueVer[NUM_2] = para->scalar_value.val[NUM_2];
        } else {
            // 芯片内部地址从低到高排列时BGR, kernel格式为整型时只需使能L, 为浮点型时需要同时使能M,H
            uint32_t r_weight = para->scalar_value.val[0];
            uint32_t g_weight = para->scalar_value.val[1];
            uint32_t b_weight = para->scalar_value.val[NUM_2];
            uint32_t scalar_value = ((r_weight << NUM_16) & MASKR) | ((g_weight << NUM_8) & MASKG) |
                                    (b_weight & MASKB);
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueHor[NUM_2] = scalar_value;
            PIPELINE_(ctx).kernel.postPadding[MAIN_CHN].regValueVer[NUM_2] = scalar_value;
        }
    }
}

static void vpc_pipe_comm_proc(const vpc_pipe_ctx_t *ctx)
{
    vpc_pipe_reset(ctx);
    vpc_pipe_set_top(ctx);
    vpc_pipe_set_in0_cvdr_channel(ctx);
    vpc_pipe_set_in0swap(ctx, ENABLE);
    vpc_pipe_set_in0uvup(ctx, ENABLE);
    vpc_pipe_set_in0_csc(ctx);
    vpc_pipe_set_in0uvdown(ctx, NULL);
    vpc_pipe_set_outuvup(ctx, MAIN_CHN, UVUP_METHOD_BUTT);
    vpc_pipe_set_out_csc(ctx, MAIN_CHN);
    vpc_pipe_set_outuvdown(ctx, MAIN_CHN, ENABLE);
    vpc_pipe_set_outswap(ctx, MAIN_CHN, ENABLE);
    vpc_pipe_set_out_cvdr_channel(ctx, MAIN_CHN);
}

static void vpc_pipe_set_in0_csc_convert(const vpc_pipe_ctx_t *ctx, uint32_t toDtype, uint32_t normalize)
{
    PIPELINE_(ctx).input.in0Csc.cvtMode.rndModeOut = RND_NEAREST_EVEN;
    PIPELINE_(ctx).input.in0Csc.cvtMode.clipEnOut = 1;
    PIPELINE_(ctx).input.in0Csc.normalizeIn = 0x437F0000; // 0x437F0000 255乘的系数
    PIPELINE_(ctx).input.in0Csc.normalizeOut = 0x3F800000; // 0x3F800000 系数1

    // toDtype == 0: 走原先流程
    if (toDtype != 0) {
        if (toDtype == 1) { // 1: u8-fp32
            PIPELINE_(ctx).input.in0Csc.normalizeIn = (normalize == 1) ?
                0x3B808081 : 0x3F800000; // 0x3B808081, 系数1/255; 0x3F800000, 系数1
            PIPELINE_(ctx).input.in0Csc.normalizeOut = 0x3F800000; // 0x3F800000, 系数1
        } else { // 2: fp32-u8
            PIPELINE_(ctx).input.in0Csc.normalizeIn = (normalize == 1) ?
                0x437FFFBE: 0x3F800000; // 0x437FFFBE, 系数255.999; 0x3F800000, 系数1
            PIPELINE_(ctx).input.in0Csc.normalizeOut = 0x3F800000; // 0x3F800000, 系数1
            PIPELINE_(ctx).input.in0Csc.cvtMode.rndModeOut = RND_ZERO;
            PIPELINE_(ctx).input.in0Csc.cvtMode.clipEnOut = 0;
        }
        PIPELINE_(ctx).input.in0Csc.cscMode.calCore = 1;
    }
}

static void vpc_pipe_set_out_csc_convert(const vpc_pipe_ctx_t *ctx)
{
    const uint32_t one_per_255 = 0x3B808081;
    PIPELINE_(ctx).output[MAIN_CHN].csc.normalizeOut = one_per_255;
    PIPELINE_(ctx).output[MAIN_CHN].csc.cvtMode.rndModeOut = RND_ZERO;
}

static void vpc_pipe_set_posterize(const vpc_pipe_ctx_t *ctx, uint32_t posterizeValue,
    uint32_t in_width, uint32_t in_height)
{
    PIPELINE_(ctx).kernel.lut.en = 0; // Lut根据此寄存器配置lut ctrl，不能和posterize同时使能
    PIPELINE_(ctx).kernel.lut.cutoutEn = 0;
    PIPELINE_(ctx).kernel.lut.width = in_width;
    PIPELINE_(ctx).kernel.lut.height =  in_height;
    PIPELINE_(ctx).kernel.lut.posterizeEn = 1;
    PIPELINE_(ctx).kernel.lut.posterizeValue = posterizeValue;
}

static void vpc_pipe_set_cutout(const vpc_pipe_ctx_t *ctx, uint32_t cutout_en,uint32_t in_width, uint32_t in_height, 
    uint32_t cutout_value[12], uint32_t cutout_win[16])
{
    PIPELINE_(ctx).kernel.lut.en = 0;
    PIPELINE_(ctx).kernel.lut.posterizeEn = 0;
    PIPELINE_(ctx).kernel.lut.width = in_width;
    PIPELINE_(ctx).kernel.lut.height =  in_height;
    PIPELINE_(ctx).kernel.lut.cutoutEn = cutout_en;
    uint32_t index;
    if (cutout_value != NULL) {
        for (index = 0; index < 12; index++) { // 12：4个窗口 * 3个通道。win0:R,G,B; ... win3:R,G,B
            PIPELINE_(ctx).kernel.lut.cutoutValue[index] = cutout_value[index];
        }
    }
    if (cutout_win != NULL) {
        for (index = 0; index < 16; index++) { // 16: 4个窗口 * 4个坐标。win0:H,V; ... win3:H,V
            PIPELINE_(ctx).kernel.lut.cutoutWin[index] = cutout_win[index];
        }
    }
}

static dvpp_vpc_pipe_export_func_t g_export_mlv1r1_func = {
    // common
    .pfn_vpc_pipe_set_apart_src_pic_info = vpc_pipe_set_apart_src_pic_info,
    .pfn_vpc_pipe_set_apart_dst_pic_info = vpc_pipe_set_apart_dst_pic_info,
    .pfn_vpc_pipe_set_src_pic_info = vpc_pipe_set_src_pic_info,
    .pfn_vpc_pipe_set_src_hfbc_info = vpc_pipe_set_src_hfbc_info,
    .pfn_vpc_pipe_set_dst_pic_info = vpc_pipe_set_dst_pic_info,

    // channel
    .pfn_vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic = vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic,
    .pfn_vpc_pipe_set_paste = vpc_pipe_set_paste,
    .pfn_vpc_pipe_in0_cvdr_copy_1chn_to_3chn = vpc_pipe_in0_cvdr_copy_1chn_to_3chn,
    .pfn_vpc_pipe_set_cvdr_rd_nr = vpc_pipe_set_cvdr_rd_nr,
    .pfn_vpc_pipe_set_output_cvdr_idle = vpc_pipe_set_output_cvdr_idle,
    // kernel
    .pfn_vpc_pipe_set_default = vpc_pipe_set_default,
    .pfn_vpc_pipe_set_ker_fmt = vpc_pipe_set_ker_fmt,
    .pfn_vpc_pipe_set_bitwidth = vpc_pipe_set_bitwidth,
    .pfn_vpc_pipe_set_readtype = vpc_pipe_set_readtype,
    .pfn_vpc_pipe_set_channel_cache = vpc_pipe_set_channel_cache,
    .pfn_vpc_pipe_set_channel_out_type = vpc_pipe_set_channel_out_type,
    .pfn_vpc_pipe_set_outpic_size = vpc_pipe_set_outpic_size,
    .pfn_vpc_pipe_set_int_merge = vpc_pipe_set_int_merge,
    .pfn_vpc_pipe_set_errmask = vpc_pipe_set_errmask,
    .pfn_vpc_pipe_set_top_in1 = vpc_pipe_set_top_in1,
    .pfn_vpc_pipe_set_in0swap = vpc_pipe_set_in0swap,
    .pfn_vpc_pipe_set_in0uvup = vpc_pipe_set_in0uvup,
    .pfn_vpc_pipe_set_in0uvdown = vpc_pipe_set_in0uvdown,
    .pfn_vpc_pipe_set_outuvup = vpc_pipe_set_outuvup,
    .pfn_vpc_pipe_set_outuvdown = vpc_pipe_set_outuvdown,
    .pfn_vpc_pipe_set_outswap = vpc_pipe_set_outswap,
    .pfn_vpc_pipe_direct_set_outswap = vpc_pipe_direct_set_outswap,
    .pfn_vpc_pipe_set_user_csc = vpc_pipe_set_user_csc,
    .pfn_vpc_pipe_set_csc_alpha = vpc_pipe_set_csc_alpha,
    .pfn_vpc_pipe_set_in0_csc_clip = vpc_pipe_set_in0_csc_clip,
    .pfn_vpc_pipe_set_out_csc_clip = vpc_pipe_set_out_csc_clip,  
    .pfn_vpc_pipe_set_crop_accelerate = vpc_pipe_set_crop_accelerate,
    .pfn_vpc_pipe_set_precrop = vpc_pipe_set_precrop,
    .pfn_vpc_pipe_set_postcrop = NULL,
    .pfn_vpc_pipe_set_resize = vpc_pipe_set_resize,
    .pfn_vpc_pipe_set_resize_split = vpc_pipe_set_resize_split,
    .pfn_vpc_pipe_set_postpadding = vpc_pipe_set_postpadding,
    .pfn_vpc_pipe_set_blend = vpc_pipe_set_blend,
    .pfn_vpc_pipe_set_xflip = vpc_pipe_set_xflip,
    .pfn_vpc_pipe_set_yflip = vpc_pipe_set_yflip,
    .pfn_vpc_pipe_set_histogram = vpc_pipe_set_histogram,
    .pfn_vpc_pipe_set_affine = vpc_pipe_set_affine,
    .pfn_vpc_pipe_set_filter = vpc_pipe_set_filter,
    .pfn_vpc_pipe_set_lut = vpc_pipe_set_lut,
    .pfn_vpc_pipe_set_yuvscaler = vpc_pipe_set_yuvscaler,
    .pfn_vpc_pipe_comm_proc = vpc_pipe_comm_proc,
    .pfn_vpc_pipe_subchn_comm_proc = NULL,
    .pfn_vpc_pipe_set_histogram_min_max = NULL,
    // mlv1r1
    .pfn_vpc_pipe_set_normalize = vpc_pipe_set_normalize,
    .pfn_vpc_pipe_set_hsv = vpc_pipe_set_hsv,
    .pfn_vpc_pipe_set_enhance = vpc_pipe_set_enhance,
    .pfn_vpc_pipe_set_contrast = vpc_pipe_set_contrast,
    .pfn_vpc_pipe_set_convert = vpc_pipe_set_convert,
    .pfn_vpc_pipe_set_clip = vpc_pipe_set_clip,
    .pfn_vpc_pipe_set_prepadding = vpc_pipe_set_prepadding,
    .pfn_vpc_pipe_set_in0_csc_convert = vpc_pipe_set_in0_csc_convert,
    .pfn_vpc_pipe_set_out_csc_convert = vpc_pipe_set_out_csc_convert,
    .pfn_vpc_pipe_set_posterize = vpc_pipe_set_posterize,
    .pfn_vpc_pipe_set_cutout = vpc_pipe_set_cutout,
    // mlv1r3
    .pfn_vpc_pipe_set_mosaic = NULL,
    .pfn_vpc_pipe_set_cover = NULL,
    .pfn_vpc_pipe_set_osd = NULL,
    .pfn_vpc_pipe_set_rotate = NULL,
    .pfn_vpc_pipe_set_resize_serial = NULL,
    .pfn_vpc_pipe_set_dump_reg = NULL,
    // dvd
    .pfn_vpc_pipe_set_invert = NULL,
    .pfn_vpc_pipe_set_solarize = NULL,
    .pfn_vpc_pipe_set_erase = NULL,
    .pfn_vpc_pipe_set_contrast_v2 = NULL,
    .pfn_vpc_pipe_set_dma_copy = NULL,
    // pegv2r1 nsc
    .pfn_nsc_pipe_set_cvdr_wr_chn = NULL,
    .pfn_nsc_pipe_set_cvdr_rd_chn = NULL,
    .pfn_nsc_pipe_set_pyramid = NULL,
    .pfn_nsc_pipe_set_pyramid_input = NULL,
    .pfn_nsc_pipe_set_pyramid_output = NULL,
    .pfn_nsc_pipe_set_blend = NULL,
    // pegv2r1 vpc
    .pfn_vpc_pipe_set_level2_pointer = NULL,
    .pfn_vpc_pipe_set_ircsc = NULL,
    .pfn_vpc_pipe_set_raw_yyuv_rd = NULL,
    .pfn_vpc_pipe_set_raw_yyuv_wr = NULL,
    .pfn_vpc_pipe_set_raw_bayer_wr = NULL,
    .pfn_vpc_pipe_in0_out_cvdr = NULL,
};

void vpc_pipe_register_export_func(void)
{
    dvpp_vpc_pipe_register_export_func(&g_export_mlv1r1_func);
}

void vpc_pipe_unregister_export_func(void)
{
    dvpp_vpc_pipe_unregister_export_func();
}

