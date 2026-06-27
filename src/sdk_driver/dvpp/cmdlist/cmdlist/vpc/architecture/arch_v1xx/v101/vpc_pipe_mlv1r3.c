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
#include "vpc_pipe_yuvscaler.h"
#include "vpc_pipe_resize.h"
#include "dvpp_cmdlist_define.h"
#include "dvpp_cmdlist_num_define.h"

static void vpc_pipe_set_dump_reg(const vpc_pipe_ctx_t *ctx, uint32_t size, uint64_t addr)
{
    PIPELINE_(ctx).kernel.dumpReg.en = 1;
    PIPELINE_(ctx).kernel.dumpReg.readSize = size;
    PIPELINE_(ctx).kernel.dumpReg.readAddr = addr;
}

static void vpc_pipe_set_mosaic(const vpc_pipe_ctx_t *ctx, const vpc_pipe_mosaic_t *mosaics,
                                const uint32_t mosaic_num, uint32_t width, uint32_t height)
{
    uint32_t index = 0;
    uint32_t blk_size;
    const vpc_pipe_mosaic_t *mosaic;

    blk_size = mosaics->blk_size;
    // region mosaic block size含义 1:8x8   2:16x16  3:32x32
    // vpc mosaic block size含义 0:8x8   1:16x16  2:32x32
    // 需要做转换
    PIPELINE_(ctx).kernel.mosaic.blockSize = (blk_size < 1) ? 0 : (blk_size - 1);
    PIPELINE_(ctx).kernel.mosaic.inWidth = width;
    PIPELINE_(ctx).kernel.mosaic.inHeight = height;

    for (index = 0; index < mosaic_num; index++) {
        mosaic = &mosaics[index];
        PIPELINE_(ctx).kernel.mosaic.mosaicRegion[index].en = 1;
        PIPELINE_(ctx).kernel.mosaic.mosaicRegion[index].hmin = (mosaic->rect.x < 0) ? 0 : (uint32_t)mosaic->rect.x;
        PIPELINE_(ctx).kernel.mosaic.mosaicRegion[index].vmin = (mosaic->rect.y < 0) ? 0 : (uint32_t)mosaic->rect.y;
        PIPELINE_(ctx).kernel.mosaic.mosaicRegion[index].hmax = mosaic->rect.x + mosaic->rect.width - 1;
        PIPELINE_(ctx).kernel.mosaic.mosaicRegion[index].vmax = mosaic->rect.y + mosaic->rect.height - 1;
    }
}

static void vpc_pipe_set_cover(const vpc_pipe_ctx_t *ctx, const cover_region_t *cover_regions,
                               const uint32_t num, uint32_t width, uint32_t height)
{
    uint32_t i = 0;

    PIPELINE_(ctx).kernel.cover.inWidth = width;
    PIPELINE_(ctx).kernel.cover.inHeight = height;

    for (i = 0; i < num; i++) {
        PIPELINE_(ctx).kernel.cover.coverRegion[i] = cover_regions[i];
    }
}

static void vpc_pipe_set_osd(const vpc_pipe_ctx_t *ctx, const osd_t *osd_info, const uint32_t osd_num)
{
    uint32_t i = 0;
    PIPELINE_(ctx).kernel.osd.inWidth = osd_info->inWidth;
    PIPELINE_(ctx).kernel.osd.inHeight = osd_info->inHeight;
    (void)memcpy_s(&PIPELINE_(ctx).kernel.osd.clut[0], sizeof(osd_info->clut),
        &osd_info->clut[0], sizeof(osd_info->clut));

    for (i = 0; i < osd_num; i++) {
        PIPELINE_(ctx).kernel.osd.osdRegion[i] = osd_info->osdRegion[i];
    }
}

static void vpc_pipe_set_postpadding(const vpc_pipe_ctx_t *ctx,
    vpc_pipe_make_border_info_t *para, uint32_t in_width, uint32_t in_height, uint32_t chn)
{
    const uint32_t PADDING_R_WEIGHT_MASK = 0x00FF0000;
    const uint32_t PADDING_G_WEIGHT_MASK = 0x0000FF00;
    const uint32_t PADDING_B_WEIGHT_MASK = 0x000000FF;

    PIPELINE_(ctx).kernel.postPadding[chn].en = 1;
    PIPELINE_(ctx).kernel.postPadding[chn].paddingSel = (uint32_t)(para->border_type);
    PIPELINE_(ctx).kernel.postPadding[chn].bottomSize = para->bottom;
    PIPELINE_(ctx).kernel.postPadding[chn].topSize = para->top;
    PIPELINE_(ctx).kernel.postPadding[chn].rightSize = para->right;
    PIPELINE_(ctx).kernel.postPadding[chn].leftSize = para->left;
    PIPELINE_(ctx).kernel.postPadding[chn].inHeight = in_height - 1;
    PIPELINE_(ctx).kernel.postPadding[chn].inWidth = in_width - 1;
    if (para->border_type == VPC_PIPE_BORDER_CONSTANT) {
        // 芯片内部地址从低到高排列时BGR, kernel格式为整型时只需使能L, 为浮点型时需要同时使能M,H
        uint32_t r_weight = (uint32_t)(para->scalar_value.val[NUM_0]);
        uint32_t g_weight = (uint32_t)(para->scalar_value.val[NUM_1]);
        uint32_t b_weight = (uint32_t)(para->scalar_value.val[NUM_2]);
        uint32_t scalar_value = ((r_weight << NUM_16) & PADDING_R_WEIGHT_MASK) |
                               ((g_weight << NUM_8) & PADDING_G_WEIGHT_MASK) |
                               (b_weight & PADDING_B_WEIGHT_MASK);

        PIPELINE_(ctx).kernel.postPadding[chn].regValueVer[NUM_2] = scalar_value;
        PIPELINE_(ctx).kernel.postPadding[chn].regValueHor[NUM_2] = scalar_value;
    }
}

static void set_rotate_src_pic_info(const vpc_pipe_ctx_t *ctx)
{
    uint64_t base_addr;
    vpc_pixel_fmt_e pixel_fmt;
    uint32_t wstride[COLOR_CHANNEL_NUM];
    wstride[PORT0] = vpc_pipe_get_stride(&SRC_FMTCFG_(ctx), SRCPIC_(ctx).picture_width_stride, PORT0);
    wstride[PORT1] = vpc_pipe_get_stride(&SRC_FMTCFG_(ctx), SRCPIC_(ctx).picture_width_stride, PORT1);
    wstride[PORT2] = vpc_pipe_get_stride(&SRC_FMTCFG_(ctx), SRCPIC_(ctx).picture_width_stride, PORT2);

    base_addr = (uint64_t)(SRCPIC_(ctx).picture_address);
    pixel_fmt = vpc_pipe_get_pixel_fmt(&SRC_FMTCFG_(ctx), PORT0);
    if (pixel_fmt != IDEL) {
        PIPELINE_(ctx).kernel.rotate.inPicAddrL[NUM_0] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicAddrH[NUM_0] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicStride[NUM_0] = wstride[0];
    }

    pixel_fmt = vpc_pipe_get_pixel_fmt(&SRC_FMTCFG_(ctx), PORT1);
    if (pixel_fmt != IDEL) {
        base_addr = get_cvdr_base_addr(&SRCPIC_(ctx), &SRC_FMTCFG_(ctx), wstride, 0, 0, PORT1);
        PIPELINE_(ctx).kernel.rotate.inPicAddrL[NUM_1] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicAddrH[NUM_1] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicStride[NUM_1] = wstride[1];
    }

    pixel_fmt = vpc_pipe_get_pixel_fmt(&SRC_FMTCFG_(ctx), PORT2);
    if (pixel_fmt != IDEL) {
        base_addr =  get_cvdr_base_addr(&SRCPIC_(ctx), &SRC_FMTCFG_(ctx), wstride, 0, 0, PORT2);
        PIPELINE_(ctx).kernel.rotate.inPicAddrL[NUM_2] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicAddrH[NUM_2] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.inPicStride[NUM_2] = wstride[NUM_2];
    }
}

static void set_rotate_dst_pic_info(const vpc_pipe_ctx_t *ctx)
{
    uint64_t base_addr;
    vpc_pixel_fmt_e pixel_fmt;
    uint32_t wstride[COLOR_CHANNEL_NUM];
    wstride[PORT0] = vpc_pipe_get_stride(
        &DST_FMTCFG_(ctx, MAIN_CHN), DSTPIC_(ctx, MAIN_CHN).picture_width_stride, PORT0);
    wstride[PORT1] = vpc_pipe_get_stride(
        &DST_FMTCFG_(ctx, MAIN_CHN), DSTPIC_(ctx, MAIN_CHN).picture_width_stride, PORT1);
    wstride[PORT2] = vpc_pipe_get_stride(
        &DST_FMTCFG_(ctx, MAIN_CHN), DSTPIC_(ctx, MAIN_CHN).picture_width_stride, PORT2);

    base_addr = (uint64_t)(DSTPIC_(ctx, MAIN_CHN).picture_address);
    pixel_fmt = vpc_pipe_get_pixel_fmt(&DST_FMTCFG_(ctx, MAIN_CHN), PORT0);
    if (pixel_fmt != IDEL) {
        PIPELINE_(ctx).kernel.rotate.outPicAddrL[NUM_0] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicAddrH[NUM_0] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicStride[NUM_0] = wstride[NUM_0];
    }

    pixel_fmt = vpc_pipe_get_pixel_fmt(&DST_FMTCFG_(ctx, MAIN_CHN), PORT1);
    if (pixel_fmt != IDEL) {
        base_addr =  get_cvdr_base_addr(&DSTPIC_(ctx, MAIN_CHN), &DST_FMTCFG_(ctx, MAIN_CHN), wstride, 0, 0, PORT1);
        PIPELINE_(ctx).kernel.rotate.outPicAddrL[NUM_1] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicAddrH[NUM_1] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicStride[NUM_1] = wstride[NUM_1];
    }

    pixel_fmt = vpc_pipe_get_pixel_fmt(&DST_FMTCFG_(ctx, MAIN_CHN), PORT2);
    if (pixel_fmt != IDEL) {
        base_addr =  get_cvdr_base_addr(&DSTPIC_(ctx, MAIN_CHN), &DST_FMTCFG_(ctx, MAIN_CHN), wstride, 0, 0, PORT2);
        PIPELINE_(ctx).kernel.rotate.outPicAddrL[NUM_2] = GET_LOW_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicAddrH[NUM_2] = GET_HIGH_ADDR(base_addr);
        PIPELINE_(ctx).kernel.rotate.outPicStride[NUM_2] = wstride[NUM_2];
    }
}

static void vpc_pipe_set_rotate(const vpc_pipe_ctx_t *ctx, uint32_t in_width, uint32_t in_height, uint32_t rot_dir)
{
    PIPELINE_(ctx).kernel.rotate.en = 1;
    PIPELINE_(ctx).kernel.rotate.inWidth = in_width - 1; // 输入图像宽度，减1配置
    PIPELINE_(ctx).kernel.rotate.inHeight = in_height - 1; // 输入图像高度，减1配置
    PIPELINE_(ctx).kernel.rotate.rotDir = rot_dir;
    set_rotate_src_pic_info(ctx);
    set_rotate_dst_pic_info(ctx);
}

static void normalize_yuvscaler_coeff(yuvscaler_para_t *para)
{
    uint32_t i;
    const int16_t MAX_VALUE_MILAN = 255; // 老系数最大值255
    const int16_t MAX_VALUE_MINI = 511; // 新系数最大值511
    for (i = 0; i < SCALER_COFF_NB_4; i++) {
        if (para->taps4[i] == MAX_VALUE_MILAN) {
            para->taps4[i] = MAX_VALUE_MINI;
        } else {
            para->taps4[i] *= NUM_2;
        }
    }

    for (i = 0; i < SCALER_COFF_NB_6; i++) {
        if (para->taps6[i] == MAX_VALUE_MILAN) {
            para->taps6[i] = MAX_VALUE_MINI;
        } else {
            para->taps6[i] *= NUM_2;
        }
    }
    for (i = 0; i < SCALER_COFF_NB_8; i++) {
        if (para->taps8[i] == MAX_VALUE_MILAN) {
            para->taps8[i] = MAX_VALUE_MINI;
        } else {
            para->taps8[i] *= NUM_2;
        }
    }
}

static void get_yuvscaler_para(uint32_t inc, yuvscaler_para_t *para)
{
    uint32_t i;
    uint32_t j;
    // Ascend910B为32phase，为了兼容Ascend910_73的8phase，将系数扩展了
    const struct yuv_scaler_array* coeff = search_scaler_para(inc);
    uint32_t index = 0;
    uint32_t index2 = 0;

    for (i = 0; i < NUM_8; i++) {
        for (j = 0; j < NUM_4; j++) {
            index = i * NUM_4 + j;
            index2 = i * NUM_16 + j;
            para->taps4[index2] = coeff->taps4[index];
            para->taps4[index2 + NUM_4] = coeff->taps4[index];
            para->taps4[index2 + NUM_8] = coeff->taps4[index];
            para->taps4[index2 + NUM_12] = coeff->taps4[index];
        }
    }

    for (i = 0; i < NUM_8; i++) {
        for (j = 0; j < NUM_6; j++) {
            index = i * NUM_6 + j;
            index2 = i * NUM_24 + j;
            para->taps6[index2] = coeff->taps6[index];
            para->taps6[index2 + NUM_6] = coeff->taps6[index];
            para->taps6[index2 + NUM_12] = coeff->taps6[index];
            para->taps6[index2 + NUM_18] = coeff->taps6[index];
        }
    }

    for (i = 0; i < NUM_8; i++) {
        for (j = 0; j < NUM_6; j++) {
            index = i * NUM_6 + j;
            index2 = i * NUM_32 + j;
            para->taps8[index2 + NUM_1] = coeff->taps6[index];
            para->taps8[index2 + NUM_9] = coeff->taps6[index];
            para->taps8[index2 + NUM_17] = coeff->taps6[index];
            para->taps8[index2 + NUM_25] = coeff->taps6[index];
        }
    }
    normalize_yuvscaler_coeff(para);
}

static void get_yuvscaler_bilinear_para(yuvscaler_para_t *para)
{
    uint32_t i;
    // yuv scale 模拟 pre scale，使用特殊的系数
    for (i = 0; i < SCALER_COFF_NB_4; i++) {
        para->taps4[i] = COEFF_512NORM_32PHASE_4TAPS_BILINEAR[i];
    }
    for (i = 0; i < SCALER_COFF_NB_6; i++) {
        para->taps6[i] = COEFF_512NORM_32PHASE_6TAPS_BILINEAR[i];
    }
    for (i = 0; i < SCALER_COFF_NB_8; i++) {
        para->taps8[i] = COEFF_512NORM_32PHASE_8TAPS_BILINEAR[i];
    }
}


static void set_yuv_scaler_para(yuvscaler_t *yuvscaler, uint32_t in_width, uint32_t in_height,
    uint32_t out_width, uint32_t out_height, uint8_t is_bilinear)
{
    const uint32_t SCALER_BIT_MOVE = 20;
    if (out_width == in_width) {
        yuvscaler->ihinc = SCALER_RADIO_1_TIME;
        yuvscaler->bypass |= 0x1;
    } else {
        // & 0xfffffff0 16bit精度
        yuvscaler->ihinc = (((uint64_t)(in_width) << SCALER_BIT_MOVE) / out_width) & 0xfffffff0;
    }

    if (out_height == in_height) {
        yuvscaler->ivinc = SCALER_RADIO_1_TIME;
        yuvscaler->bypass |= 0x2;
    } else {
        // & 0xfffffff0 16bit精度
        yuvscaler->ivinc = (((uint64_t)(in_height) << SCALER_BIT_MOVE) / out_height) & 0xfffffff0;
    }
    if (yuvscaler->bypass == 0x3) {
        return;
    }
    yuvscaler->ihleftInt = 0;
    yuvscaler->ihleftDec = 0;
    yuvscaler->ivtopInt = 0;
    yuvscaler->ivtopDec = 0;
    yuvscaler->ihrightInt = (uint32_t)((yuvscaler->ihinc * (out_width - 1)) >> SCALER_BIT_MOVE);
    yuvscaler->ihrightDec = (yuvscaler->ihinc * (out_width - 1)) & 0xFFFFF;
    yuvscaler->ivbotInt = (uint32_t)((yuvscaler->ivinc * (out_height - 1)) >> SCALER_BIT_MOVE);
    yuvscaler->ivbotDec = (yuvscaler->ivinc * (out_height - 1)) & 0xFFFFF;

    yuvscaler->inWidth = in_width;
    yuvscaler->inHeight = in_height;
    yuvscaler->outWidth = out_width;
    yuvscaler->outHeight = out_height;
    (void)memset_s(&yuvscaler->coeff.scale, sizeof(yuvscaler->coeff.scale), 0, sizeof(yuvscaler->coeff.scale));
    if (is_bilinear) {
        get_yuvscaler_bilinear_para(&yuvscaler->coeff.scale[0]);
        get_yuvscaler_bilinear_para(&yuvscaler->coeff.scale[1]);
    } else {
        get_yuvscaler_para((uint32_t)(yuvscaler->ihinc >> SCALER_BIT_MOVE_TO_OLD_INC), &yuvscaler->coeff.scale[0]);
        get_yuvscaler_para((uint32_t)(yuvscaler->ivinc >> SCALER_BIT_MOVE_TO_OLD_INC), &yuvscaler->coeff.scale[1]);
    }
}

static void set_resize_as_prescale(resize_t *resize, vpc_pipe_resize_mode_e mode, uint32_t in_width, uint32_t in_height)
{
    resize->en = 1;
    resize->incSrc = 0;
    resize->funcType = get_func_type(mode);
    resize->alignMode = get_align_mode(mode);
    resize->rndCtrl0 = get_rnd_ctrl(mode);
    resize->inHeight = in_height;
    resize->inWidth = in_width;
    resize->outHeight = in_height / 2; // 模拟pre scaler，只能除以2
    resize->outWidth = in_width / 2; // 模拟pre scaler，只能除以2
}

static void vpc_pipe_set_yuvscaler(const vpc_pipe_ctx_t *ctx, vpc_pipe_resize_para_t *para, uint32_t chn)
{
    vpc_pipe_resize_mode_e mode;
    uint32_t in_height;
    uint32_t in_width;
    uint32_t out_height;
    uint32_t out_width;

    (void)chn;

    in_height = para->in_height;
    in_width = para->in_width;
    out_height = para->out_height;
    out_width = para->out_width;
    mode = (vpc_pipe_resize_mode_e)(para->interpolation);

    if (judge_use_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        PIPELINE_(ctx).kernel.resize[MAIN_CHN].en = 0;
        PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN].bypass = 0;
        set_yuv_scaler_para(
            &PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN], in_width, in_height, out_width, out_height, 0);
    } else if (judge_use_1prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        set_resize_as_prescale(&PIPELINE_(ctx).kernel.resize[MAIN_CHN], mode, in_width, in_height);
        PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN].bypass = 0;
        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN], PIPELINE_(ctx).kernel.resize[MAIN_CHN].outWidth,
            PIPELINE_(ctx).kernel.resize[MAIN_CHN].outHeight, out_width, out_height, 0);
    } else if (judge_use_2prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        TOP_(ctx).out1To3En = 0x2; // 010
        TOP_(ctx).multiLevelZoomEn = (uint32_t)SERIES_MODE;
        // resize2
        set_resize_as_prescale(&PIPELINE_(ctx).kernel.resize[SUB_CHN_1], mode, in_width, in_height);
        // resize1
        set_resize_as_prescale(&PIPELINE_(ctx).kernel.resize[MAIN_CHN], mode,
            in_width / NUM_2, in_height / NUM_2); // 上一级缩小了2倍

        PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN].bypass = 0;
        yuvscaler_disable(&PIPELINE_(ctx).kernel.yuvScale[SUB_CHN_1]);

        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN], PIPELINE_(ctx).kernel.resize[MAIN_CHN].outWidth,
            PIPELINE_(ctx).kernel.resize[MAIN_CHN].outHeight, out_width, out_height, 0);
    } else if (judge_use_3prescale_1yuvscale(in_width, in_height, out_width, out_height) == 1) {
        TOP_(ctx).out1To3En = 0x2;
        TOP_(ctx).multiLevelZoomEn = (uint32_t)SERIES_MODE;

        PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN].bypass = 0;
        PIPELINE_(ctx).kernel.yuvScale[SUB_CHN_1].bypass = 0;
        // resize2
        set_resize_as_prescale(&PIPELINE_(ctx).kernel.resize[SUB_CHN_1], mode, in_width, in_height);

        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[SUB_CHN_1],
            PIPELINE_(ctx).kernel.resize[SUB_CHN_1].outWidth, PIPELINE_(ctx).kernel.resize[SUB_CHN_1].outHeight,
            in_width / NUM_4, in_height / NUM_4, NUM_1); // yuv scale2 模拟第二级 pre scale，输出为输入的1/4

        set_resize_as_prescale(&PIPELINE_(ctx).kernel.resize[MAIN_CHN], mode,
            in_width / NUM_4, in_height / NUM_4); // resize1模拟第三级pre scaler，输入为上一级输出，1/4

        set_yuv_scaler_para(&PIPELINE_(ctx).kernel.yuvScale[MAIN_CHN], PIPELINE_(ctx).kernel.resize[MAIN_CHN].outWidth,
            PIPELINE_(ctx).kernel.resize[MAIN_CHN].outHeight, out_width, out_height, 0);
    }
}

static void vpc_pipe_set_subchn_top(const vpc_pipe_ctx_t *ctx)
{
    uint8_t vpu_id = ctx->vpu_id;
    const vpc_pipe_private_data_t *pdata = &ctx->pdata[vpu_id];
    const vpc_fmt_info_t *outfmt_info = &pdata->dst_fmt_info[SUB_CHN_1];

    TOP_(ctx).out1To3En = 3; // bit0为3表示打开主通路和subchn1
    if (pdata->dst_use_apart_pic == 0) {
        TOP_(ctx).out1Height = pdata->dst[SUB_CHN_1].picture_height - 1;
        TOP_(ctx).out1Width = pdata->dst[SUB_CHN_1].picture_width - 1;
    } else {
        TOP_(ctx).out1Height = pdata->apart_dst[SUB_CHN_1].height - 1;
        TOP_(ctx).out1Width = pdata->apart_dst[SUB_CHN_1].width - 1;
    }
    TOP_(ctx).out1Format = vpc_pipe_get_vpc_format(outfmt_info);
}

static void vpc_pipe_set_resize_serial(const vpc_pipe_ctx_t *ctx)
{
    TOP_(ctx).out1To3En = 0x2; // 010
    TOP_(ctx).multiLevelZoomEn = (uint32_t)(SERIES_MODE);
}

static void vpc_pipe_subchn_comm_proc(const vpc_pipe_ctx_t *ctx)
{
    uint8_t vpu_id = ctx->vpu_id;
    const vpc_pipe_private_data_t *pdata = &ctx->pdata[vpu_id];
    vpc_pipe_set_subchn_top(ctx);
    vpc_pipe_set_outuvup(ctx, SUB_CHN_1, UVUP_METHOD_BUTT);
    vpc_pipe_set_outuvdown(ctx, SUB_CHN_1, ENABLE);
    vpc_pipe_set_outswap(ctx, SUB_CHN_1, ENABLE);
    if (pdata->dst_use_apart_pic == 0) {
        vpc_pipe_set_out_cvdr_channel(ctx, SUB_CHN_1);
    } else {
        vpc_pipe_set_out_cvdr_channel_by_apart_info(ctx, SUB_CHN_1);
    }
}

static void vpc_pipe_comm_proc(const vpc_pipe_ctx_t *ctx)
{
    uint8_t vpu_id = ctx->vpu_id;
    const vpc_pipe_private_data_t *pdata = &ctx->pdata[vpu_id];
    vpc_pipe_reset(ctx);
    vpc_pipe_set_top(ctx);

    if (pdata->hfbc_en == 0) {
        if (pdata->src_use_apart_pic == 0) {
            vpc_pipe_set_in0_cvdr_channel(ctx);
        } else {
            vpc_pipe_set_in0_cvdr_channel_by_apart_info(ctx);
        }
    } else {
        vpc_pipe_set_rdma_channel(ctx);
    }

    vpc_pipe_set_in0swap(ctx, ENABLE);
    vpc_pipe_set_in0uvup(ctx, ENABLE);
    vpc_pipe_set_in0_csc(ctx);
    vpc_pipe_set_in0uvdown(ctx, NULL);

    // comm process only config main channel
    vpc_pipe_set_outuvup(ctx, MAIN_CHN, UVUP_METHOD_BUTT);
    vpc_pipe_set_out_csc(ctx, MAIN_CHN);
    vpc_pipe_set_outuvdown(ctx, MAIN_CHN, ENABLE);
    vpc_pipe_set_outswap(ctx, MAIN_CHN, ENABLE);

    if (pdata->dst_use_apart_pic == 0) {
        vpc_pipe_set_out_cvdr_channel(ctx, MAIN_CHN);
    } else {
        vpc_pipe_set_out_cvdr_channel_by_apart_info(ctx, MAIN_CHN);
    }
}

static dvpp_vpc_pipe_export_func_t g_export_mlv1r3_func = {
    // common
    .pfn_vpc_pipe_set_src_pic_info = vpc_pipe_set_src_pic_info,
    .pfn_vpc_pipe_set_src_hfbc_info = vpc_pipe_set_src_hfbc_info,
    .pfn_vpc_pipe_set_dst_pic_info = vpc_pipe_set_dst_pic_info,
    .pfn_vpc_pipe_set_apart_src_pic_info = vpc_pipe_set_apart_src_pic_info,
    .pfn_vpc_pipe_set_apart_dst_pic_info = vpc_pipe_set_apart_dst_pic_info,
    // channel
    .pfn_vpc_pipe_set_paste = vpc_pipe_set_paste,
    .pfn_vpc_pipe_in0_cvdr_copy_1chn_to_3chn = vpc_pipe_in0_cvdr_copy_1chn_to_3chn,
    .pfn_vpc_pipe_set_cvdr_rd_nr = vpc_pipe_set_cvdr_rd_nr,
    .pfn_vpc_pipe_set_output_cvdr_idle = vpc_pipe_set_output_cvdr_idle,
    .pfn_vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic = vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic,
    // kernel
    .pfn_vpc_pipe_set_default = vpc_pipe_set_default,
    .pfn_vpc_pipe_set_ker_fmt = vpc_pipe_set_ker_fmt,
    .pfn_vpc_pipe_set_channel_cache = vpc_pipe_set_channel_cache,
    .pfn_vpc_pipe_set_channel_out_type = vpc_pipe_set_channel_out_type,
    .pfn_vpc_pipe_set_bitwidth = vpc_pipe_set_bitwidth,
    .pfn_vpc_pipe_set_readtype = vpc_pipe_set_readtype,
    .pfn_vpc_pipe_set_outpic_size = vpc_pipe_set_outpic_size,
    .pfn_vpc_pipe_set_int_merge = vpc_pipe_set_int_merge,
    .pfn_vpc_pipe_set_errmask = vpc_pipe_set_errmask,
    .pfn_vpc_pipe_set_top_in1 = vpc_pipe_set_top_in1,
    .pfn_vpc_pipe_set_in0swap = vpc_pipe_set_in0swap,
    .pfn_vpc_pipe_set_in0uvup = vpc_pipe_set_in0uvup,
    .pfn_vpc_pipe_set_in0uvdown = vpc_pipe_set_in0uvdown,
    .pfn_vpc_pipe_set_outswap = vpc_pipe_set_outswap,
    .pfn_vpc_pipe_direct_set_outswap = vpc_pipe_direct_set_outswap,
    .pfn_vpc_pipe_set_outuvup = vpc_pipe_set_outuvup,
    .pfn_vpc_pipe_set_outuvdown = vpc_pipe_set_outuvdown,
    .pfn_vpc_pipe_set_user_csc = vpc_pipe_set_user_csc,
    .pfn_vpc_pipe_set_in0_csc_clip = vpc_pipe_set_in0_csc_clip,
    .pfn_vpc_pipe_set_out_csc_clip = vpc_pipe_set_out_csc_clip,   
    .pfn_vpc_pipe_set_csc_alpha = vpc_pipe_set_csc_alpha,
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
    .pfn_vpc_pipe_subchn_comm_proc = vpc_pipe_subchn_comm_proc,
    // mlv1r3
    .pfn_vpc_pipe_set_mosaic = vpc_pipe_set_mosaic,
    .pfn_vpc_pipe_set_cover = vpc_pipe_set_cover,
    .pfn_vpc_pipe_set_osd = vpc_pipe_set_osd,
    .pfn_vpc_pipe_set_rotate = vpc_pipe_set_rotate,
    .pfn_vpc_pipe_set_resize_serial = vpc_pipe_set_resize_serial,
    .pfn_vpc_pipe_set_dump_reg = vpc_pipe_set_dump_reg,
    // mlv1r1
    .pfn_vpc_pipe_set_normalize = NULL,
    .pfn_vpc_pipe_set_hsv = NULL,
    .pfn_vpc_pipe_set_enhance = NULL,
    .pfn_vpc_pipe_set_contrast = NULL,
    .pfn_vpc_pipe_set_convert = NULL,
    .pfn_vpc_pipe_set_clip = NULL,
    .pfn_vpc_pipe_set_prepadding = NULL,
    .pfn_vpc_pipe_set_in0_csc_convert = NULL,
    .pfn_vpc_pipe_set_out_csc_convert = NULL,
    .pfn_vpc_pipe_set_posterize = NULL,
    .pfn_vpc_pipe_set_cutout = NULL,
    // dvd
    .pfn_vpc_pipe_set_invert = NULL,
    .pfn_vpc_pipe_set_solarize = NULL,
    .pfn_vpc_pipe_set_erase = NULL,
    .pfn_vpc_pipe_set_contrast_v2 = NULL,
    .pfn_vpc_pipe_set_histogram_min_max = NULL,
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
    dvpp_vpc_pipe_register_export_func(&g_export_mlv1r3_func);
}

void vpc_pipe_unregister_export_func(void)
{
    dvpp_vpc_pipe_unregister_export_func();
}