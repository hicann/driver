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

#ifndef CMDLIST_DVPP_CMDLIST_H
#define CMDLIST_DVPP_CMDLIST_H

#include "ka_type.h"

#include "dvpp_cmdlist_sqe.h"
#include "dvpp_cmdlist_define.h"
#include "dvpp_decoder.h"
#ifdef __cplusplus
extern "C" {
#endif

// 计算公式 kernel_credit * (2^ runtime_limit(0x1f))
// STARTS时钟频率500M
#define KERNEL_CREDIT (0x2) // 约8s
#define SQE_LEN (64U)
#define SQE_LIST_LEN (SQE_LEN * DVPP_MAX_BATCH_NUM)
#define SQE_PTR_MODE_OFFSET (12U)
#define SQE_RTT_MODE_OFFSET (13U)
#define SQE_WRCQE_OFFSET_DVD (11U)
#define SQE_WRCQE_OFFSET (14U)
#define SQE_BLKDIM_OFFSET (16U)
#define SQE_TIMEOUT_OFFSET (16U)
#define SQE_PTRMODE_OFFSET (24U)
#define SQE_ADDRTYPE_OFFSET (31U)

#define CMDLST_PADDING_DATA (0xFF1FFFFDU)
#define ADDR_ALIGN_SIZE (128U)
#define MEM_SIZE_4M (4 * 1024 * 1024)
#define ALIGN_LEN 4                  // 每4byte做一次对齐操作

enum dvpp_sqe_type {
    DVPP_SQE_VPC = 12,
    DVPP_SQE_JPEGE = 13,
    DVPP_SQE_JPEGD = 14,
    DVPP_SQE_NSC = 18,
};

enum dvpp_sqe_ptr_mode {
    DVPP_SQE_FIRST_PTR_MODE = 0,
    DVPP_SQE_SECOND_PTR_MODE = 1
};

enum dvpp_cmdlist_engine_type {
    DVPP_CMDLIST_ENGINE_TYPE_VPC   = 0,
    DVPP_CMDLIST_ENGINE_TYPE_JPEGD = 1,
    DVPP_CMDLIST_ENGINE_TYPE_JPEGE = 2,
    DVPP_CMDLIST_ENGINE_TYPE_NSC   = 3,
    DVPP_CMDLIST_ENGINE_TYPE_BUTT
};

struct CmdNodeHeadInfo {
    uint32_t errMask;
    uint32_t cvdrIntMerge;
    uint32_t pipeIntMerge;
};

struct CmdNode {
    uint32_t *startAddr;
    uint32_t *posAddr;
    uint32_t *endAddr;
    uint32_t dataSize;
    uint32_t *extAddr;     // 用于填充VPC预留cmdnode空间的内容
    uint32_t extDataSize; // 用于填充VPC预留cmdnode空间的内容
    struct CmdNode *next;
    struct CmdNode *prev;
    struct CmdNodeHeadInfo headInfo;
    uint32_t len0; // 记录cmdlist buffer0寄存器偏移地址和值的配置长度
    uint32_t len1; // 记录cmdlist buffer1芯片回读操作的寄存器偏移地址的配置长度
    uint8_t isNeedWrBack;
    uint32_t wrBackRegAddr;
    uint32_t wrBackSize;
    uint64_t wrBackValAddr;
};

struct CmdBuf {
    uint64_t bufAddr;
    uint32_t bufSize;
    uint64_t ioAddr;
    uint64_t ioStartAddr;
    uint32_t *startAddr;
    uint32_t *posAddr;
    uint32_t *endAddr; // 用于校验cmdbuf是否写越界
    struct CmdNode *cmdHeadNode;
    struct CmdNode *cmdTailNode;
};

typedef int32_t (*pfn_dvpp_fill_one_cmdnode)(dvpp_decoder *decoder, struct CmdNode *node, uint32_t node_idx);
typedef int32_t (*pfn_dvpp_connect_all_cmdnode)(struct CmdBuf *cmd_buf);
typedef int32_t (*pfn_dvpp_fill_sqelist)(struct CmdBuf *cmd_buf, uint32_t sqe_idx, uint32_t blkdim);
typedef int32_t (*pfn_dvpp_gen_sqe)(
    struct CmdBuf *cmd_buf, enum dvpp_sqe_ptr_mode mode, uint32_t blkdim, struct dvpp_sqe *sqe);
typedef int32_t (*pfn_dvpp_check_param)(dvpp_decoder *decoder, uint32_t node_idx);

typedef struct dvpp_cmdlist_engine_ops {
    pfn_dvpp_fill_one_cmdnode    dvpp_fill_one_cmdnode;
    pfn_dvpp_connect_all_cmdnode dvpp_connect_all_cmdnode;
    pfn_dvpp_fill_sqelist        dvpp_fill_sqelist;
    pfn_dvpp_gen_sqe             dvpp_gen_sqe;
    pfn_dvpp_check_param         dvpp_check_param;
} dvpp_cmdlist_engine_ops;

dvpp_cmdlist_engine_ops *dvpp_get_cmdlist_engine_ops(void);
void dvpp_init_cmdbuf(uint64_t host_addr, uint64_t dev_addr, uint32_t len, struct CmdBuf *cmd_buf);
int32_t dvpp_gen_cmdlist(dvpp_decoder *decoder, struct CmdBuf *cmd_buf);
uint64_t dvpp_get_cmdbuf_real_size(struct CmdBuf *cmd_buf);
void dvpp_gen_sqe(dvpp_decoder *decoder, struct CmdBuf *cmd_buf, struct dvpp_sqe *sqe);
void dvpp_seq_set_cmdnode_val(struct CmdNode *node, uint32_t val);
void dvpp_ext_set_cmdnode_val(struct CmdNode *node, uint32_t val);
struct CmdNode *dvpp_alloc_one_cmdnode(struct CmdBuf *cmd_buf);

void add_padding_data(struct CmdNode *node);

#ifdef BUILD_DEBUG
void dvpp_dump_cmdbuf(struct CmdBuf *cmd_buf);
void dvpp_dump_sqe(struct dvpp_sqe *sqe);
void dvpp_dump_sqe_list(struct CmdBuf *cmd_buf);
#endif

#ifdef __cplusplus
}
#endif
#endif // #ifndef CMDLIST_DVPP_CMDLIST_H
