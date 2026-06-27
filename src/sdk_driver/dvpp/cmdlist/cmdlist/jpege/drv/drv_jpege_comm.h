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

#ifndef JPEGE_DRV_JPEGE_COMM_H
#define JPEGE_DRV_JPEGE_COMM_H

#include "ka_type.h"

#include "dvpp_cmdlist_num_define.h"
#include "dvpp_cmdlist.h"
#include "dvpp_decoder.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CMDLIST_FIX_WRITE 0x1FFFFE

#define BITS_COUNT 16
#define DC_VALUE_COUNT 12
#define AC_VALUE_COUNT 162
#define AC_VALUE_LEN 256

typedef struct {
    uint16_t code;
    uint8_t len;
    uint8_t val;
} huffman_data;

typedef struct {
    uint32_t is_yuv420; // 0：yuv422, 1：yuv420
    uint32_t swap_yuv;
    uint32_t swap_uv;
    uint32_t width_minus1;   // send传入
    uint32_t height_minus1;  // send传入
    uint64_t y_phy_addr;      // 输入图像device地址virt_addr[0]
    uint64_t u_phy_addr;      // 输入图像device地址virt_addr[1]
    uint32_t y_stride;       // send时用户传入width_stride[0]

    uint64_t stream_addr; // 输出地址

    uint8_t y_quant_table[64];
    uint8_t cb_quant_table[64];
    uint8_t cr_quant_table[64];

    uint64_t read_user_addr; // 回读操作的device地址

    uint8_t dc0_bits_table[BITS_COUNT];
    uint8_t dc0_val_table[DC_VALUE_COUNT];
    uint8_t dc1_bits_table[BITS_COUNT];
    uint8_t dc1_val_table[DC_VALUE_COUNT];

    uint8_t ac0_bits_table[BITS_COUNT];
    uint8_t ac0_val_table[AC_VALUE_COUNT];
    uint8_t ac1_bits_table[BITS_COUNT];
    uint8_t ac1_val_table[AC_VALUE_COUNT];

    // 注意：该结构体2~3包都有，不能变更已有字段，新增字段放在最后边
    uint32_t yuv_fmt; // 0：yuv420 1：yuv422 2：yuv444
    uint32_t str_fmt; // 0: SEMI_PLANAR 1: PLANAR 2: PACKAGE
    uint32_t package_sel; // SEMI-PLANAR 0:UV,1:VU;
                          // PACKAGE422 0:YUYV;1:YVYU;2:UYVY;3：vyuy
                          // PACKAGE444 0:YUV;1:YVU;2:UYV;3:UVY;4:VYU;5:VUY
    uint32_t color_to_gray;
    uint32_t stream_len; // 输出内存长度
    uint32_t u_stride; // send时用户传入width_stride[1]
    uint32_t v_stride; // send时用户传入width_stride[2]
    uint64_t v_phy_addr; // 输入图像device地址virt_addr[2]
} jpege_config;

int32_t drv_jpege_struct_assign(dvpp_decoder *decoder, uint32_t node_idx, void *dst, const uint16_t struct_len);
void drv_jpege_config_sqe(struct CmdBuf *cmd_buf, enum dvpp_sqe_ptr_mode mode, uint32_t blkdim, struct dvpp_sqe *sqe);
void drv_jpege_config_sqelist(struct CmdBuf *cmd_buf, uint32_t sqe_idx, uint32_t blkdim);
void drv_jpege_build_cmdnode(dvpp_decoder *decoder, struct CmdNode *node, uint32_t node_idx);
void drv_jpege_cmdnode_set_next_node(struct CmdBuf *cmd_buf, struct CmdNode *node);
void drv_jpege_cmdnode_set_interrupt(struct CmdNode *node, uint32_t isLastNode);

void config_jpege_interrupt(struct CmdNode *node, uint32_t isLastNode);
void config_jepge_next_node(struct CmdBuf *cmd_buf, struct CmdNode *node);
void config_jpege_cmdnode(struct CmdNode *node, jpege_config* jpege_cfg);

void config_jpege_cmdnode_reverse_space(struct CmdNode *node);
void config_jpege_dump_addr(struct CmdNode *node, jpege_config* jpege_cfg);

#ifdef __cplusplus
}
#endif
#endif // #ifndef JPEGE_DRV_JPEGE_COMM_H