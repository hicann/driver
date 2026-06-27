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

#ifndef DVPP_VPC_PIPE_H
#define DVPP_VPC_PIPE_H

#include "pipeline_module.h"
#include "vpc_pipe_types.h"
#include "vpc_pipe_format.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    uint64_t cmdbuf_uva;
    uint64_t cmdbuf_kva;
    uint32_t cmdbuf_size;
    void **vpu_config;
    uint16_t node_cnt;
    uint16_t *node_cnt_of_batch;
    uint16_t batch_cnt;
} dvpp_cmdlist_param_t;

// 由于当前vpc不支持y和uv分量分开配置，但是NVR AUTO模式需要单独配置，增加以下结构体
// 用于保存其他通道的信息
typedef struct {
    uint64_t addr[3];   // 记录其他3个分量的首地址
    uint32_t stride[3]; // 记录其余3个分量的stride
    uint32_t width;
    uint32_t height;
    vpc_pipe_pic_fmt_t picture_format;
} vpc_apart_pic_info_t;

typedef struct {
    uint8_t hfbc_en;
    vpc_hfbc_info_t hfbc_src;
    vpc_pipe_pic_info_t src;
    uint8_t src_use_apart_pic;
    uint8_t dst_use_apart_pic;
    vpc_pipe_pic_info_t dst[PIPE_OUT_NUM];
    vpc_apart_pic_info_t apart_src;
    vpc_apart_pic_info_t apart_dst[PIPE_OUT_NUM];
    uint32_t dst_num;
    roi_t src_roi; // 用于抠图加速
    vpc_fmt_info_t src_fmt_info;
    vpc_fmt_info_t dst_fmt_info[PIPE_OUT_NUM];
    vpc_pipe_csc_info_t csc_info;
} vpc_pipe_private_data_t;

// 外部用户只需填充vpc_pipe_ctx
typedef struct vpc_pipe_ctx {
    // public
    uint8_t vpu_id;
    vpu_vpc_config_t *vpu_config;
    // private
    vpc_pipe_private_data_t pdata[3];
} vpc_pipe_ctx_t;

#define PIPELINE_(ctx) (ctx)->vpu_config[(ctx)->vpu_id].pipe
#define TOP_(ctx) (ctx)->vpu_config[(ctx)->vpu_id].top
#define CHANNEL_(ctx) (ctx)->vpu_config[(ctx)->vpu_id].channel
#define SRC_FMTCFG_(ctx) (ctx)->pdata[(ctx)->vpu_id].src_fmt_info
#define DST_FMTCFG_(ctx, chn) (ctx)->pdata[(ctx)->vpu_id].dst_fmt_info[(chn)]
#define CSC_INFO_(ctx) (ctx)->pdata[(ctx)->vpu_id].csc_info
#define SRCHFBC_(ctx) (ctx)->pdata[(ctx)->vpu_id].hfbc_src
#define SRC_APARTPIC_(ctx) (ctx)->pdata[(ctx)->vpu_id].apart_src
#define DST_APARTPIC_(ctx, chn) (ctx)->pdata[(ctx)->vpu_id].apart_dst[(chn)]
#define SRCPIC_(ctx) (ctx)->pdata[(ctx)->vpu_id].src
#define DSTPIC_(ctx, chn) (ctx)->pdata[(ctx)->vpu_id].dst[(chn)]
#define SRCROI_(ctx) (ctx)->pdata[(ctx)->vpu_id].src_roi

/**********************comm proc**********************/
typedef void fn_vpc_pipe_set_src_pic_info(vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t *src);
typedef void fn_vpc_pipe_set_src_hfbc_info(vpc_pipe_ctx_t *ctx, vpc_hfbc_info_t *src);
typedef void fn_vpc_pipe_set_dst_pic_info(
    vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t *dst[PIPE_OUT_NUM], uint32_t num);
typedef void fn_vpc_pipe_set_apart_src_pic_info(vpc_pipe_ctx_t *ctx, vpc_apart_pic_info_t *apart_src);
typedef void fn_vpc_pipe_set_apart_dst_pic_info(
    vpc_pipe_ctx_t *ctx, vpc_apart_pic_info_t *apart_dst[PIPE_OUT_NUM], uint32_t num);
/**********************comm proc**********************/

/**********************channel**********************/
typedef void fn_vpc_pipe_set_paste(
    const vpc_pipe_ctx_t *ctx, uint32_t top_off, uint32_t left_off, uint32_t width, uint32_t chn);
typedef void fn_vpc_pipe_in0_cvdr_copy_1chn_to_3chn(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_cvdr_rd_nr(const vpc_pipe_ctx_t *ctx, uint8_t port, uint8_t du);
typedef void fn_vpc_pipe_set_output_cvdr_idle(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic(
    const vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t *pic, uint32_t port);
/**********************channel**********************/

/**********************kernel**********************/
// comm
typedef void fn_vpc_pipe_set_default(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_ker_fmt(const vpc_pipe_ctx_t *ctx, const vpc_pic_fmt_e kernelFmt);
typedef void fn_vpc_pipe_set_channel_cache(const vpc_pipe_ctx_t *ctx, uint32_t run_mode);
typedef void fn_vpc_pipe_set_channel_out_type(const vpc_pipe_ctx_t *ctx, channel_out_type_e type);
typedef void fn_vpc_pipe_set_bitwidth(const vpc_pipe_ctx_t *ctx, bitwidth_e bitwidth);
typedef void fn_vpc_pipe_set_readtype(const vpc_pipe_ctx_t *ctx, read_type_e read_type);
typedef void fn_vpc_pipe_set_outpic_size(const vpc_pipe_ctx_t *ctx, uint32_t width, uint16_t height, uint32_t chn);
typedef void fn_vpc_pipe_set_int_merge(const vpc_pipe_ctx_t *ctx, uint32_t int_merge);
typedef void fn_vpc_pipe_set_errmask(const vpc_pipe_ctx_t *ctx, uint32_t errMask);
typedef void fn_vpc_pipe_set_top_in1(const vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t *layer1);
typedef void fn_vpc_pipe_set_in0swap(const vpc_pipe_ctx_t *ctx, uint8_t en);
typedef void fn_vpc_pipe_set_in0uvup(const vpc_pipe_ctx_t *ctx, uvup_method_e method);
typedef void fn_vpc_pipe_set_in0uvdown(const vpc_pipe_ctx_t *ctx, const uint32_t coeff[6]);
typedef void fn_vpc_pipe_set_outswap(const vpc_pipe_ctx_t *ctx, uint32_t chn, uint8_t en);
typedef void fn_vpc_pipe_direct_set_outswap(const vpc_pipe_ctx_t *ctx, uint32_t chn, uint32_t pos);
typedef void fn_vpc_pipe_set_outuvup(const vpc_pipe_ctx_t *ctx, uint32_t chn, uvup_method_e method);
typedef void fn_vpc_pipe_set_outuvdown(const vpc_pipe_ctx_t *ctx, uint32_t chn, uint8_t en);
typedef void fn_vpc_pipe_set_user_csc(vpc_pipe_ctx_t *ctx, const vpc_pipe_csc_info_t *info);
typedef void fn_vpc_pipe_set_in0_csc(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_out_csc(const vpc_pipe_ctx_t *ctx, uint32_t chn);
typedef void fn_vpc_pipe_set_csc_alpha(const vpc_pipe_ctx_t *ctx, uint32_t alpha);
typedef void fn_vpc_pipe_set_in0_csc_clip(const vpc_pipe_ctx_t *ctx, const uint16_t clip[2][6]);
typedef void fn_vpc_pipe_set_out_csc_clip(const vpc_pipe_ctx_t *ctx, const uint16_t clip[2][6], uint32_t chn);
typedef void fn_vpc_pipe_set_crop_accelerate(
    vpc_pipe_ctx_t *ctx, const vpc_pipe_crop_para_t *para, uint8_t expend_edge);
typedef void fn_vpc_pipe_set_precrop(const vpc_pipe_ctx_t *ctx, const vpc_pipe_crop_para_t *para);
typedef void fn_vpc_pipe_set_postcrop(const vpc_pipe_ctx_t *ctx, const vpc_pipe_crop_para_t *para, uint32_t chn);
typedef void fn_vpc_pipe_set_resize(const vpc_pipe_ctx_t *ctx, const vpc_pipe_resize_para_t *para, uint32_t chn);
typedef void fn_vpc_pipe_set_resize_split(const vpc_pipe_ctx_t *ctx, const vpc_pipe_split_para_t *para, uint32_t nhn);
typedef void fn_vpc_pipe_set_postpadding(const vpc_pipe_ctx_t *ctx,
    vpc_pipe_make_border_info_t *para, uint32_t in_width, uint32_t in_height, uint32_t chn);
typedef void fn_vpc_pipe_set_blend(const vpc_pipe_ctx_t *ctx, vpc_pipe_blending_type_e type, uint32_t offset,
    const vpc_pipe_pic_info_t *layer1, const vpc_pipe_blend_add_weight_config_t *add_weight_config);
typedef void fn_vpc_pipe_set_xflip(const vpc_pipe_ctx_t *ctx, uint8_t isPre, uint32_t inWidth, uint32_t inHeight);
typedef void fn_vpc_pipe_set_yflip(const vpc_pipe_ctx_t *ctx, uint8_t isPre);
typedef void fn_vpc_pipe_set_histogram(const vpc_pipe_ctx_t *ctx, uint32_t size, uint64_t addr, uint8_t is_yuvsum);
typedef void fn_vpc_pipe_set_affine(const vpc_pipe_ctx_t *ctx, affine_t *para, uint8_t en3d);
typedef void fn_vpc_pipe_set_filter(const vpc_pipe_ctx_t *ctx, filter_t *para);
typedef void fn_vpc_pipe_set_lut(const vpc_pipe_ctx_t *ctx, vpc_pipe_lut_remap_t *para, 
    uint32_t in_width, uint32_t in_height, uint8_t lutSecondaryPointerEn, vpc_pipe_lut_table_addr_t* addr_para);
typedef void fn_vpc_pipe_set_yuvscaler(const vpc_pipe_ctx_t *ctx, vpc_pipe_resize_para_t *para, uint32_t chn);

typedef void fn_vpc_pipe_comm_proc(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_subchn_comm_proc(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_level2_pointer(const vpc_pipe_ctx_t *ctx, level2_pointer_t *para);

// mlv1r1
typedef void fn_vpc_pipe_set_normalize(const vpc_pipe_ctx_t *ctx, normalize_t *para);
typedef void fn_vpc_pipe_set_hsv(const vpc_pipe_ctx_t *ctx, hsv_t *para);
typedef void fn_vpc_pipe_set_enhance(const vpc_pipe_ctx_t *ctx, enhance_t *para);
typedef void fn_vpc_pipe_set_contrast(const vpc_pipe_ctx_t *ctx, contrast_t *para);
typedef void fn_vpc_pipe_set_contrast_v2(const vpc_pipe_ctx_t *ctx, contrast_v2_t *para);
typedef void fn_vpc_pipe_set_convert(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_clip(const vpc_pipe_ctx_t *ctx, vpc_clip_t *para);
typedef void fn_vpc_pipe_set_prepadding(const vpc_pipe_ctx_t *ctx,
    vpc_pipe_make_border_info_t *para, uint32_t in_width, uint32_t in_height);

// mlv1r3
typedef void fn_vpc_pipe_set_mosaic(const vpc_pipe_ctx_t *ctx, const vpc_pipe_mosaic_t *mosaics,
    const uint32_t mosaic_num, uint32_t width, uint32_t height);
typedef void fn_vpc_pipe_set_cover(const vpc_pipe_ctx_t *ctx, const cover_region_t *cover_regions,
    const uint32_t num, uint32_t width, uint32_t height);
typedef void fn_vpc_pipe_set_osd(const vpc_pipe_ctx_t *ctx, const osd_t *osd_info, const uint32_t osd_num);
typedef void fn_vpc_pipe_set_rotate(
    const vpc_pipe_ctx_t *ctx, uint32_t in_width, uint32_t in_height, uint32_t rot_dir);
typedef void fn_vpc_pipe_set_resize_serial(const vpc_pipe_ctx_t *ctx);

typedef void fn_vpc_pipe_set_in0_csc_convert(const vpc_pipe_ctx_t *ctx, uint32_t toDtype, uint32_t normalize);
typedef void fn_vpc_pipe_set_out_csc_convert(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_posterize(const vpc_pipe_ctx_t *ctx, uint32_t posterizeValue,
    uint32_t in_width, uint32_t in_height);
typedef void fn_vpc_pipe_set_solarize(const vpc_pipe_ctx_t *ctx, uint32_t thld_min, uint32_t thld_max,
    uint32_t in_width, uint32_t in_height);
typedef void fn_vpc_pipe_set_invert(const vpc_pipe_ctx_t *ctx, uint32_t in_width, uint32_t in_height);
typedef void fn_vpc_pipe_set_erase(const vpc_pipe_ctx_t *ctx, uint32_t erase_value[3], uint32_t erase_win[4],
    uint32_t in_width, uint32_t in_height);
typedef void fn_vpc_pipe_set_cutout(const vpc_pipe_ctx_t *ctx, uint32_t cutout_en,
    uint32_t in_width, uint32_t in_height, uint32_t cutout_value[12], uint32_t cutout_win[16]);
/**********************kernel**********************/
// gen cmdlist
typedef int32_t fn_dvpp_gen_vpc_sqe(dvpp_cmdlist_param_t *param, void *sqe);
typedef void fn_vpc_pipe_set_histogram_min_max(const vpc_pipe_ctx_t *ctx, uint32_t size, uint64_t addr);

typedef void fn_vpc_pipe_set_dump_reg(const vpc_pipe_ctx_t *ctx, uint32_t size, uint64_t addr);
// pegv2r1
typedef void fn_nsc_pipe_set_cvdr_wr_chn(const vpc_pipe_ctx_t *ctx, uint32_t top_off, uint32_t left_off,
    const vpc_pipe_pic_info_t *dst, uint32_t chn);
typedef void fn_nsc_pipe_set_cvdr_rd_chn(const vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t *src, uint32_t chn);
typedef void fn_nsc_pipe_set_pyramid(const vpc_pipe_ctx_t *ctx, const pyramid_t *pyramid);
typedef void fn_nsc_pipe_set_pyramid_input(const vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t src[], uint32_t num,
    uint32_t port, uint32_t uv_sel);
typedef void fn_nsc_pipe_set_pyramid_output(const vpc_pipe_ctx_t *ctx, const vpc_pipe_pic_info_t dst[], uint32_t num,
    uint32_t port, uint32_t uv_sel);

typedef void fn_nsc_pipe_set_blend(const vpc_pipe_ctx_t *ctx, const blend_t *blend);
typedef void fn_vpc_pipe_set_dma_copy(const vpc_pipe_ctx_t *ctx, uint32_t in_width, uint32_t in_height);
typedef void fn_vpc_pipe_set_ircsc(const vpc_pipe_ctx_t *ctx, ircsc_t *conf);
typedef void fn_vpc_pipe_set_raw_yyuv_rd(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_set_raw_yyuv_wr(
    const vpc_pipe_ctx_t *ctx, uint32_t valid_width, uint32_t top_offset, uint32_t left_offset);
typedef void fn_vpc_pipe_set_raw_bayer_wr(const vpc_pipe_ctx_t *ctx);
typedef void fn_vpc_pipe_in0_out_cvdr(const vpc_pipe_ctx_t *ctx);

typedef struct {
    // common
    fn_vpc_pipe_set_src_pic_info *pfn_vpc_pipe_set_src_pic_info;
    fn_vpc_pipe_set_src_hfbc_info *pfn_vpc_pipe_set_src_hfbc_info;
    fn_vpc_pipe_set_dst_pic_info *pfn_vpc_pipe_set_dst_pic_info;
    fn_vpc_pipe_set_apart_src_pic_info *pfn_vpc_pipe_set_apart_src_pic_info;
    fn_vpc_pipe_set_apart_dst_pic_info *pfn_vpc_pipe_set_apart_dst_pic_info;
    // channel
    fn_vpc_pipe_set_paste *pfn_vpc_pipe_set_paste;
    fn_vpc_pipe_in0_cvdr_copy_1chn_to_3chn *pfn_vpc_pipe_in0_cvdr_copy_1chn_to_3chn;
    fn_vpc_pipe_set_cvdr_rd_nr *pfn_vpc_pipe_set_cvdr_rd_nr;
    fn_vpc_pipe_set_output_cvdr_idle *pfn_vpc_pipe_set_output_cvdr_idle;
    fn_vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic *pfn_vpc_pipe_set_input_cvdr_port_for_single_chn_by_pic;
    // kernel
    fn_vpc_pipe_set_default *pfn_vpc_pipe_set_default;
    fn_vpc_pipe_set_ker_fmt *pfn_vpc_pipe_set_ker_fmt;
    fn_vpc_pipe_set_channel_cache *pfn_vpc_pipe_set_channel_cache;
    fn_vpc_pipe_set_channel_out_type *pfn_vpc_pipe_set_channel_out_type;
    fn_vpc_pipe_set_bitwidth *pfn_vpc_pipe_set_bitwidth;
    fn_vpc_pipe_set_readtype *pfn_vpc_pipe_set_readtype;
    fn_vpc_pipe_set_outpic_size *pfn_vpc_pipe_set_outpic_size;
    fn_vpc_pipe_set_int_merge *pfn_vpc_pipe_set_int_merge;
    fn_vpc_pipe_set_errmask *pfn_vpc_pipe_set_errmask;
    fn_vpc_pipe_set_top_in1 *pfn_vpc_pipe_set_top_in1;
    fn_vpc_pipe_set_in0swap *pfn_vpc_pipe_set_in0swap;
    fn_vpc_pipe_set_in0uvup *pfn_vpc_pipe_set_in0uvup;
    fn_vpc_pipe_set_in0uvdown *pfn_vpc_pipe_set_in0uvdown;
    fn_vpc_pipe_set_outswap *pfn_vpc_pipe_set_outswap;
    fn_vpc_pipe_direct_set_outswap *pfn_vpc_pipe_direct_set_outswap;
    fn_vpc_pipe_set_outuvup *pfn_vpc_pipe_set_outuvup;
    fn_vpc_pipe_set_outuvdown *pfn_vpc_pipe_set_outuvdown;
    fn_vpc_pipe_set_user_csc *pfn_vpc_pipe_set_user_csc;
    fn_vpc_pipe_set_in0_csc *pfn_vpc_pipe_set_in0_csc;
    fn_vpc_pipe_set_out_csc *pfn_vpc_pipe_set_out_csc;
    fn_vpc_pipe_set_csc_alpha *pfn_vpc_pipe_set_csc_alpha;
    fn_vpc_pipe_set_in0_csc_clip *pfn_vpc_pipe_set_in0_csc_clip;
    fn_vpc_pipe_set_out_csc_clip *pfn_vpc_pipe_set_out_csc_clip;
    fn_vpc_pipe_set_crop_accelerate *pfn_vpc_pipe_set_crop_accelerate;
    fn_vpc_pipe_set_precrop *pfn_vpc_pipe_set_precrop;
    fn_vpc_pipe_set_postcrop *pfn_vpc_pipe_set_postcrop;
    fn_vpc_pipe_set_resize *pfn_vpc_pipe_set_resize;
    fn_vpc_pipe_set_resize_split *pfn_vpc_pipe_set_resize_split;
    fn_vpc_pipe_set_postpadding *pfn_vpc_pipe_set_postpadding;
    fn_vpc_pipe_set_blend *pfn_vpc_pipe_set_blend;
    fn_vpc_pipe_set_xflip *pfn_vpc_pipe_set_xflip;
    fn_vpc_pipe_set_yflip *pfn_vpc_pipe_set_yflip;
    fn_vpc_pipe_set_histogram *pfn_vpc_pipe_set_histogram;
    fn_vpc_pipe_set_histogram_min_max *pfn_vpc_pipe_set_histogram_min_max;
    fn_vpc_pipe_set_affine *pfn_vpc_pipe_set_affine;
    fn_vpc_pipe_set_filter *pfn_vpc_pipe_set_filter;
    fn_vpc_pipe_set_lut *pfn_vpc_pipe_set_lut;
    fn_vpc_pipe_set_yuvscaler *pfn_vpc_pipe_set_yuvscaler;
    fn_vpc_pipe_comm_proc *pfn_vpc_pipe_comm_proc;
    fn_vpc_pipe_subchn_comm_proc *pfn_vpc_pipe_subchn_comm_proc;
    fn_vpc_pipe_set_level2_pointer *pfn_vpc_pipe_set_level2_pointer;

    // mlv1r1
    fn_vpc_pipe_set_normalize *pfn_vpc_pipe_set_normalize;
    fn_vpc_pipe_set_hsv *pfn_vpc_pipe_set_hsv;
    fn_vpc_pipe_set_enhance *pfn_vpc_pipe_set_enhance;
    fn_vpc_pipe_set_contrast *pfn_vpc_pipe_set_contrast;
    fn_vpc_pipe_set_convert *pfn_vpc_pipe_set_convert;
    fn_vpc_pipe_set_clip *pfn_vpc_pipe_set_clip;
    fn_vpc_pipe_set_prepadding *pfn_vpc_pipe_set_prepadding;
    fn_vpc_pipe_set_in0_csc_convert *pfn_vpc_pipe_set_in0_csc_convert;
    fn_vpc_pipe_set_out_csc_convert *pfn_vpc_pipe_set_out_csc_convert;
    fn_vpc_pipe_set_posterize *pfn_vpc_pipe_set_posterize;
    fn_vpc_pipe_set_invert *pfn_vpc_pipe_set_invert;
    fn_vpc_pipe_set_solarize *pfn_vpc_pipe_set_solarize;
    fn_vpc_pipe_set_erase *pfn_vpc_pipe_set_erase;
    fn_vpc_pipe_set_cutout *pfn_vpc_pipe_set_cutout;
    // dvd
    fn_vpc_pipe_set_contrast_v2 *pfn_vpc_pipe_set_contrast_v2;
    // mlv1r3
    fn_vpc_pipe_set_mosaic *pfn_vpc_pipe_set_mosaic;
    fn_vpc_pipe_set_cover *pfn_vpc_pipe_set_cover;
    fn_vpc_pipe_set_osd *pfn_vpc_pipe_set_osd;
    fn_vpc_pipe_set_rotate *pfn_vpc_pipe_set_rotate;
    fn_vpc_pipe_set_resize_serial *pfn_vpc_pipe_set_resize_serial;
    // gen cmdlist
    fn_dvpp_gen_vpc_sqe *pfn_dvpp_gen_vpc_sqe;
    fn_vpc_pipe_set_dump_reg *pfn_vpc_pipe_set_dump_reg;
    // pegv2r1 nsc
    fn_nsc_pipe_set_cvdr_wr_chn *pfn_nsc_pipe_set_cvdr_wr_chn;
    fn_nsc_pipe_set_cvdr_rd_chn *pfn_nsc_pipe_set_cvdr_rd_chn;
    fn_nsc_pipe_set_pyramid *pfn_nsc_pipe_set_pyramid;
    fn_nsc_pipe_set_pyramid_input *pfn_nsc_pipe_set_pyramid_input;
    fn_nsc_pipe_set_pyramid_output *pfn_nsc_pipe_set_pyramid_output;
    fn_nsc_pipe_set_blend *pfn_nsc_pipe_set_blend;
    fn_vpc_pipe_set_dma_copy *pfn_vpc_pipe_set_dma_copy;
    // pegv2r1 vpc
    fn_vpc_pipe_set_ircsc *pfn_vpc_pipe_set_ircsc;
    fn_vpc_pipe_set_raw_yyuv_rd *pfn_vpc_pipe_set_raw_yyuv_rd;
    fn_vpc_pipe_set_raw_yyuv_wr *pfn_vpc_pipe_set_raw_yyuv_wr;
    fn_vpc_pipe_set_raw_bayer_wr *pfn_vpc_pipe_set_raw_bayer_wr;
    fn_vpc_pipe_in0_out_cvdr *pfn_vpc_pipe_in0_out_cvdr;

} dvpp_vpc_pipe_export_func_t;

void dvpp_vpc_pipe_register_export_func(dvpp_vpc_pipe_export_func_t *export_func);
void dvpp_vpc_pipe_unregister_export_func(void);
dvpp_vpc_pipe_export_func_t* dvpp_vpc_pipe_get_export_func(void);

#ifdef __KERNEL__
void dvpp_vpc_pipe_init_export_func(void);
void dvpp_vpc_pipe_uninit_export_func(void);
#endif // __KERNEL__

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif // #ifndef DVPP_VPC_PIPE_H
