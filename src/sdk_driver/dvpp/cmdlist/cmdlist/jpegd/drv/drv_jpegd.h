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

#ifndef JPEGD_DRV_JPEGD_H
#define JPEGD_DRV_JPEGD_H

#include "dvpp_cmdlist.h"
#include "dvpp_decoder.h"

#ifdef __cplusplus
extern "C" {
#endif

void drv_jpegd_build_cmdnode(dvpp_decoder *decoder, struct CmdNode *node, uint32_t node_idx);
void drv_jpegd_cmdnode_set_next_node(struct CmdBuf *cmd_buf, struct CmdNode *node);
void drv_jpegd_cmdnode_set_interrupt(struct CmdNode *node, uint32_t isLastNode);

#ifdef __cplusplus
}
#endif
#endif // #ifndef JPEGD_DRV_JPEGD_H
