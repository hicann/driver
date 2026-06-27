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

#ifndef JPEGD_DRV_JPEGD_COMM_H
#define JPEGD_DRV_JPEGD_COMM_H

#include "dvpp_cmdlist.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CMDLIST_FIX_WRITE 0x1FFFFE
#define QUANT_TABLE_SIZE 64          // 64:quant table长度
#define HDC_TABLE_SIZE 12            // 12:hufmman table长度
#define HAC_MIN_TABLE_SIZE 8         // 8:hufmman min table长度
#define HAC_BASE_TABLE_SIZE 8        // 8:hufmman base table长度
#define HAC_SYMBOL_TABLE_SIZE 176    // 176:hufmman symbol table长度

typedef struct {
    uint32_t picFormat;
    uint32_t outputPixelFormat;
    uint8_t outIsYuv; // 1为YUV输出，0为RGB输出
    uint32_t yFac;
    uint32_t uFac;
    uint32_t vFac;
    uint32_t dri;
    uint32_t width;
    uint32_t height;
    uint32_t yStride;
    uint32_t cStride;
    uint64_t phyStrStart;
    uint64_t phyStrEnd;
    uint64_t yPhyAddr;
    uint64_t cPhyAddr;
    uint32_t uvSwap;
    uint32_t outputType;
    uint32_t quantTable[QUANT_TABLE_SIZE];
    uint32_t huffmanTable[HDC_TABLE_SIZE];
    uint32_t huffmanMinTable[HAC_MIN_TABLE_SIZE];
    uint32_t huffmanBaseTable[HAC_BASE_TABLE_SIZE];
    uint32_t huffmanSymbolTable[HAC_SYMBOL_TABLE_SIZE];
    uint32_t horizontalStartPixel; // 区域解码水平方向起始像素点
    uint32_t horizontalEndPixel;   // 区域解码水平方向结束像素点
    uint32_t verticalStartPixel;   // 区域解码竖直方向起始像素点
    uint32_t verticalEndPixel;     // 区域解码竖直方向起始像素点
} JpegdConfig;

void set_reg_val(struct CmdNode *node, uint32_t val);
void config_jpegd_cmdnode_reverse_space(struct CmdNode *node);
void config_jpegd_interrupt(struct CmdNode *node, uint32_t isLastNode);
void config_jpegd_accuracy(struct CmdNode *node);
void config_jpegd_pixel_size(struct CmdNode *node, JpegdConfig* jpegdConfig);
void config_jpegd_addr(struct CmdNode *node, JpegdConfig* jpegdConfig);
void config_jpegd_out_type(struct CmdNode *node, const JpegdConfig* jpegdConfig);
void config_jpegd_freq_scale(struct CmdNode *node);
void config_jpegd_cvdr_du_nr_rd(struct CmdNode *node);
void config_jpegd_sample_factor(struct CmdNode *node, const JpegdConfig* jpegdConfig);
void config_jpegd_dri(struct CmdNode *node, const JpegdConfig* jpegdConfig);
void config_jpegd_table(struct CmdNode *node, JpegdConfig* jpegdConfig);
void config_jpegd_dec_start(struct CmdNode *node);
void config_jpegd_reg(struct CmdNode *node, JpegdConfig* jpegdConfig);
void config_jepgd_next_node(struct CmdBuf *cmd_buf, struct CmdNode *node);
void config_jpegd_cmdnode(struct CmdNode *node, JpegdConfig* jpegdConfig);
void config_jpegd_sqe(struct CmdBuf *cmd_buf, enum dvpp_sqe_ptr_mode mode, uint32_t blkdim, struct dvpp_sqe *sqe);
void config_jpegd_sqelist(struct CmdBuf *cmd_buf, uint32_t sqe_idx, uint32_t blkdim);
#ifdef __cplusplus
}
#endif
#endif // #ifndef JPEGD_DRV_JPEGD_COMM_H
