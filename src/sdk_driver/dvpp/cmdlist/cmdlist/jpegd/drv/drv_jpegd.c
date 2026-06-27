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

#include "drv_jpegd.h"
#include "dvpp_tlv_types.h"
#include "drv_jpegd_comm.h"

void drv_jpegd_build_cmdnode(dvpp_decoder *decoder, struct CmdNode *node, uint32_t node_idx)
{
    JpegdConfig *jpegdConfig =
        (JpegdConfig*)(dvpp_get_vpu_mod_val(decoder, node_idx, JPEGD_TLV_TYPE_DEC));

    if (jpegdConfig == NULL) {
        return;
    }
    // 配置cmdnode寄存器
    config_jpegd_cmdnode(node, jpegdConfig);
}

void drv_jpegd_cmdnode_set_next_node(struct CmdBuf *cmd_buf, struct CmdNode *node)
{
    config_jepgd_next_node(cmd_buf, node);
}

void drv_jpegd_cmdnode_set_interrupt(struct CmdNode *node, uint32_t isLastNode)
{
    config_jpegd_interrupt(node, isLastNode);
}