/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <stdbool.h>
#include <limits.h>
#include "securec.h"
#include "urma_api.h"
#include "trs_ioctl.h"
#include "drv_user_common.h"
#include "esched_user_interface.h"
#include "svm_user_interface.h"
#include "hash_table.h"
#include "trs_urma.h"
#include "trs_user_pub_def.h"
#include "trs_uk_msg.h"
#include "trs_master_event.h"
#include "trs_master_urma.h"
#include "trs_master_async.h"
#include "trs_urma_async.h"
#include "trs_res.h"

struct udma_sqe_ctl_tmp {
    uint32_t sqe_bb_idx : 16;
    uint32_t odr : 3;
    uint32_t fence : 1;
    uint32_t se : 1;
    uint32_t cqe : 1;
    uint32_t inline_en : 1;
    uint32_t udf_flag : 1;
    uint32_t rsv : 3;
    uint32_t nf : 1;
    uint32_t token_en : 1;
    uint32_t rmt_jetty_type : 2;
    uint32_t owner : 1;

    uint32_t target_hint : 8;
    uint32_t opcode : 8;
    uint32_t rsv1 : 6;
    uint32_t inline_msg_len : 10;

    uint32_t tpn : 24;
    uint32_t sge_num : 8;

    uint32_t rmt_obj_id : 20;
    uint32_t rsv2 : 12;

    uint32_t rmt_eid[4];
    uint32_t rmt_token_value;
    uint32_t udf;
    uint32_t rmt_addr_l_or_token_id;
    uint32_t rmt_addr_h_or_token_value;
};

struct udma_wqe_sge_tmp {
    uint32_t length;
    uint32_t token_id : 20;
    uint32_t rsv3 : 12;
    uint64_t va;
};

struct trs_urma_dwqe_fill_para {
    uint64_t send_addr;
    uint64_t recv_addr;
    uint64_t len;
    uint32_t cqe_report;
    uint32_t op_code;
    uint32_t sqe_bb_idx;
    urma_eid_t *rmt_eid;
    uint32_t tpn;
    urma_seg_t seg;
    urma_token_t token;
};

struct trs_async_jetty_node {
    struct trs_async_jetty_info jetty_info;
    struct halAsyncJettyHandle jettyHandle;
    bool is_free_implicitly;
};

struct trs_async_jetty_mng_ctx {
    hash_table *hash_table;
    pthread_rwlock_t rw_mutex;
    uint32_t node_num;
};

static struct trs_async_jetty_mng_ctx g_jetty_mng_ctx[TRS_DEV_NUM];

extern int halMemGetSeg(uint32_t dev_id, uint64_t va, uint64_t size, urma_seg_t *seg, urma_token_t *token);
static int trs_get_segment(struct trs_urma_ctx *urma_ctx, uint64_t va, uint64_t size,
                           struct trs_async_dma_wqe_info *wqe_info, urma_seg_t *seg, urma_token_t *token)
{
    int ret = 0;

    ret = halMemGetSeg(urma_ctx->devid, va, (uint64_t)size, seg, token);
    if (ret != 0) {
        trs_err("Get segment failed. (devid=%u; va=0x%llx; size=%llu; ret=%d)\n", urma_ctx->devid, va, size, ret);
        return ret;
    }

    wqe_info->flag = 0;
    trs_debug("Get token_id from svm. (devid=%u)\n", urma_ctx->devid);
    return 0;
}

void trs_swap_endian(uint8_t dst[], uint8_t src[], uint32_t size)
{
#ifndef EMU_ST
    uint32_t i;
    for (i = 0; i < size; i++) {
        dst[i] = src[size - 1 - i];
    }
#endif
}

static inline void trs_get_async_send_recv_addr(struct trs_async_devid *async_devid, uint64_t src, uint64_t dst,
                                                uint64_t *send_addr, uint64_t *recv_addr)
{
    if (async_devid->local_devid == async_devid->dst_devid) {
        *send_addr = dst;
        *recv_addr = src;
    } else {
        *send_addr = src;
        *recv_addr = dst;
    }
}

static struct trs_async_ctx *trs_get_async_ctx(struct trs_urma_ctx *urma_ctx, uint32_t dir,
                                               enum trs_async_dma_type async_dma_type)
{
    if (dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        if (urma_ctx->d2d_async_ctx.init_flag) {
            return &urma_ctx->d2d_async_ctx;
        }
        return NULL;
    } else {
        if ((async_dma_type == TRS_ASYNC_DMA_TYPE_2D) || (async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH)) {
            return &urma_ctx->batch_2d_async_ctx;
        } else {
            return &urma_ctx->async_ctx;
        }
    }
}

static void trs_get_async_input_src_dst_len_array(struct trs_async_dma_input_para *in, unsigned long long **src_array,
                                                  unsigned long long **dst_array, unsigned long long **src_len_array,
                                                  unsigned long long **dst_len_array)
{
    enum trs_async_dma_type async_type = in->async_dma_type;

    if (async_type == TRS_ASYNC_DMA_TYPE_2D) {
        *src_array = (unsigned long long *)&in->async_2d_in.src;
        *dst_array = (unsigned long long *)&in->async_2d_in.dst;
    } else {
        *src_array = (async_type == TRS_ASYNC_DMA_TYPE_BATCH) ? in->async_batch_in.src :
                                                                (unsigned long long *)&in->async_normal_in.src;
        *dst_array = (async_type == TRS_ASYNC_DMA_TYPE_BATCH) ? in->async_batch_in.dst :
                                                                (unsigned long long *)&in->async_normal_in.dst;
    }

    if (async_type == TRS_ASYNC_DMA_TYPE_2D) {
        *src_len_array = &in->async_2d_in.width;
        *dst_len_array = &in->async_2d_in.width;
    } else {
        *src_len_array = (async_type == TRS_ASYNC_DMA_TYPE_BATCH) ? in->async_batch_in.len :
                                                                    (unsigned long long *)&in->async_normal_in.len;
        *dst_len_array = *src_len_array;
    }
}

static inline int trs_check_batch_async_devid(unsigned long long va, uint32_t dev_id)
{
    struct DVattribute vaAttr = {0};
    int ret = 0;

    ret = drvMemGetAttribute((DVdeviceptr)va, &vaAttr);
    if (ret != DRV_ERROR_NONE) {
        trs_err("Failed to get va attribute. (ret=%d; va=0x%llx)\n", ret, va);
        return ret;
    }

    return (vaAttr.devId == dev_id) ? 0 : DRV_ERROR_PARA_ERROR;
}

static drvError_t trs_check_d2d_async_devid(uint32_t dev_id, uint32_t src_dev_id, uint32_t dst_dev_id)
{
    uint32_t host_dev_id;

    if ((dev_id != src_dev_id) && (dev_id != dst_dev_id)) {
        trs_err("Invalid dev_id. (dev_id=%u; src_dev_id=%u; dst_dev_id=%u)\n", dev_id, src_dev_id, dst_dev_id);
        return DRV_ERROR_PARA_ERROR;
    }

    (void)halGetHostID(&host_dev_id);
    if ((src_dev_id == host_dev_id) || (dst_dev_id == host_dev_id)) {
        trs_err("Invalid dev_id. (host_dev_id=%u; src_dev_id=%u; dst_dev_id=%u)\n", host_dev_id, src_dev_id,
                dst_dev_id);
        return DRV_ERROR_PARA_ERROR;
    }

    if (src_dev_id == dst_dev_id) {
        return DRV_ERROR_NOT_SUPPORT;
    }

    return DRV_ERROR_NONE;
}

static int trs_check_async_devid_dir(struct trs_async_dma_input_para *in, uint32_t local_devid, uint32_t src_devid,
                                     uint32_t dst_devid, uint32_t dir)
{
    enum trs_async_dma_type async_type = in->async_dma_type;
    int ret = 0;

    if (async_type == TRS_ASYNC_DMA_TYPE_BATCH) {
        unsigned long long i;
        for (i = 1; i < in->async_batch_in.count; i++) {
            if ((trs_check_batch_async_devid(in->async_batch_in.src[i], src_devid) != DRV_ERROR_NONE) ||
                (trs_check_batch_async_devid(in->async_batch_in.dst[i], dst_devid) != DRV_ERROR_NONE)) {
                trs_err("Addr invalid. (src_addr=0x%llx; dst_addr=0x%llx; src_devid=%u; dst_devid=%u; index=%u)\n",
                        in->async_batch_in.src[i], in->async_batch_in.dst[i], src_devid, dst_devid, i);
                return DRV_ERROR_PARA_ERROR;
            }
        }
    }

    if ((async_type == TRS_ASYNC_DMA_TYPE_SQE_UPDATE) && (dir != TRS_ASYNC_HOST_TO_DEVICE)) {
        trs_err("Invalid async_type or dir. (async_type=%d; dir=%u)\n", async_type, dir);
        return DRV_ERROR_PARA_ERROR;
    }

    if (dir == TRS_ASYNC_HOST_TO_DEVICE) {
        if (dst_devid != local_devid) {
            trs_err("Invalid devid. (dst_devid=%u; local_devid=%u)\n", dst_devid, local_devid);
            return DRV_ERROR_PARA_ERROR;
        }
    } else if (dir == TRS_ASYNC_DEVICE_TO_HOST) {
        if (src_devid != local_devid) {
            trs_err("Invalid devid. (src_devid=%u; local_devid=%u)\n", src_devid, local_devid);
            return DRV_ERROR_PARA_ERROR;
        }
    } else if (dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        ret = trs_check_d2d_async_devid(local_devid, src_devid, dst_devid);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

static int trs_get_check_async_devid_dir(uint32_t dev_id, struct trs_async_dma_input_para *in,
                                         struct trs_async_devid *async_devid, uint32_t *dir)
{
    enum trs_async_dma_type async_type = in->async_dma_type;
    struct DVattribute srcAttr, dstAttr;
    unsigned long long *src_array, *dst_array;
    unsigned long long *src_len_array, *dst_len_array;
    uint32_t host_id;
    int ret;

    trs_get_async_input_src_dst_len_array(in, &src_array, &dst_array, &src_len_array, &dst_len_array);

    ret = drvMemGetAttribute((DVdeviceptr)src_array[0], &srcAttr);
    if (ret != DRV_ERROR_NONE) {
        trs_err("Failed to get src attribute. (ret=%d; src=0x%llx)\n", ret, src_array[0]);
        return ret;
    }

    if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_SQE_UPDATE) {
        dstAttr.devId = dev_id;
    } else {
        ret = drvMemGetAttribute((DVdeviceptr)dst_array[0], &dstAttr);
        if (ret != DRV_ERROR_NONE) {
            trs_err("Failed to get dst attribute. (ret=%d; dst=0x%llx)\n", ret, dst_array[0]);
            return ret;
        }
    }

    (void)halGetHostID(&host_id);
    if ((srcAttr.devId == host_id) && (dstAttr.devId != host_id)) {
        *dir = TRS_ASYNC_HOST_TO_DEVICE;
    } else if ((dstAttr.devId == host_id) && (srcAttr.devId != host_id)) {
        *dir = TRS_ASYNC_DEVICE_TO_HOST;
    } else if ((dstAttr.devId != host_id) && (srcAttr.devId != host_id)) {
        *dir = TRS_ASYNC_DEVICE_TO_DEVICE;
    } else {
        trs_err("Invalid va. (src=0x%llx; srcMemType=%u; dst=0x%llx; dstMemType=%u; asyncType=%d)\n", src_array[0],
                srcAttr.memType, dst_array[0], dstAttr.memType, async_type);
        return DRV_ERROR_PARA_ERROR;
    }

    ret = trs_check_async_devid_dir(in, dev_id, srcAttr.devId, dstAttr.devId, *dir);
    if (ret != 0) {
        return ret;
    }

    trs_pack_async_devid(dev_id, srcAttr.devId, dstAttr.devId, async_devid);
    trs_debug("(src=0x%llx; src_devid=%u; srcType=%u; dst=0x%llx; dst_devid=%u; dstType=%u; asyncType=%d; devid=%u)\n",
              src_array[0], async_devid->src_devid, srcAttr.memType, dst_array[0], async_devid->dst_devid,
              dstAttr.memType, async_type, dev_id);
    return 0;
}

static urma_opcode_t trs_get_async_urma_opcode(uint32_t dev_id, uint32_t dst_devid, uint32_t dir)
{
    if (dir == TRS_ASYNC_HOST_TO_DEVICE) {
        return URMA_OPC_READ;
    } else if (dir == TRS_ASYNC_DEVICE_TO_HOST) {
        return URMA_OPC_WRITE;
    } else if (dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        return (dev_id == dst_devid) ? URMA_OPC_READ : URMA_OPC_WRITE;
    } else {
        return URMA_OPC_LAST;
    }
}

static int trs_fill_remote_wr_batch_info(struct trs_urma_ctx *urma_ctx, struct trs_async_dma_input_para *in,
                                         uint64_t fixedVal, struct trs_remote_fill_wqe_info *wqe_fill_info)
{
    urma_opcode_t urma_opcode = wqe_fill_info->urma_opcode;
    unsigned long long *src_array, *dst_array;
    unsigned long long *src_len_array, *dst_len_array;
    enum trs_async_dma_type async_type = in->async_dma_type;
    uint32_t start_index = 0;
    int ret = 0;
    unsigned int i;

    trs_get_async_input_src_dst_len_array(in, &src_array, &dst_array, &src_len_array, &dst_len_array);

    start_index = (uint32_t)((async_type == TRS_ASYNC_DMA_TYPE_2D) ?
                                 (in->async_2d_in.fixedSize / in->async_2d_in.width) :
                                 0);

    for (i = 0; i < wqe_fill_info->batch_num; i++) {
        uint64_t src, dst, len;
        urma_token_t src_token, dst_token;
        urma_seg_t src_seg = {0};
        urma_seg_t dst_seg = {0};
        uint32_t absolute_index = i + start_index;

        if (async_type == TRS_ASYNC_DMA_TYPE_2D) {
            uint64_t row_start = (i == 0) ? (in->async_2d_in.fixedSize % in->async_2d_in.width) : 0;
            uint64_t row_end = ((i == (wqe_fill_info->batch_num - 1)) && (fixedVal % in->async_2d_in.width != 0)) ?
                                   (fixedVal % in->async_2d_in.width) :
                                   in->async_2d_in.width;
            src = src_array[0] + absolute_index * in->async_2d_in.spitch + row_start;
            dst = dst_array[0] + absolute_index * in->async_2d_in.dpitch + row_start;
            len = row_end - row_start;
        } else {
            src = src_array[absolute_index];
            dst = dst_array[absolute_index];
            len = src_len_array[absolute_index];
        }

        ret = halMemGetSeg(urma_ctx->devid, src, len, &src_seg, &src_token);
        if (ret != 0) {
            trs_err("Failed to get src segment. (vaddr=0x%p; dir=%u; ret=%d)\n", src, in->dir, ret);
            return ret;
        }

        ret = halMemGetSeg(urma_ctx->devid, dst, len, &dst_seg, &dst_token);
        if (ret != 0) {
            trs_err("Failed to get dst segment. (vaddr=0x%p; dir=%u; ret=%d)\n", dst, in->dir, ret);
            return ret;
        }

        /* svm return the base seg va, need set to real va */
        src_seg.ubva.va = src;
        dst_seg.ubva.va = dst;

        wqe_fill_info->wr_addr[i].len = len;
        wqe_fill_info->wr_addr[i].src_ubva = src;
        wqe_fill_info->wr_addr[i].dst_ubva = dst;
        wqe_fill_info->wr_addr[i].recv_seg = (urma_opcode == URMA_OPC_READ) ? src_seg : dst_seg;
        wqe_fill_info->wr_addr[i].send_seg = (urma_opcode == URMA_OPC_READ) ? dst_seg : src_seg;
        wqe_fill_info->wr_addr[i].recv_token = (urma_opcode == URMA_OPC_READ) ? src_token : dst_token;
    }

    return ret;
}

static inline void trs_get_async_batch_num(struct trs_async_dma_input_para *in, uint64_t fixedVal,
                                           uint64_t partial_fixed_size, uint32_t *batch_num)
{
    if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH) {
        *batch_num = (uint32_t)(fixedVal + ((partial_fixed_size == 0) ? 0 : 1));
    } else if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) {
        uint64_t align_fixed_size = align_up(in->async_2d_in.fixedSize, in->async_2d_in.width);
        *batch_num = (uint32_t)((fixedVal > align_fixed_size) ?
                                    ((align_up(fixedVal - align_fixed_size, in->async_2d_in.width) /
                                      in->async_2d_in.width)) :
                                    0);
        (*batch_num) += (uint32_t)((in->async_2d_in.fixedSize % in->async_2d_in.width == 0) ? 0 : 1);
    } else {
        *batch_num = 1;
    }
}

static int trs_remote_fill_async_dma_wqe(struct trs_async_devid *async_devid, struct trs_urma_ctx *urma_ctx,
                                         struct trs_async_dma_input_para *in, uint64_t fixedVal)
{
    struct trs_remote_fill_wqe_info *wqe_fill_info = NULL;
    unsigned long long wqe_fill_info_size = 0;
    uint32_t batch_num = 0;
    urma_opcode_t urma_opcode;
    struct event_reply reply;
    uint32_t dev_id = async_devid->local_devid;
    int result, ret;

    trs_get_async_batch_num(in, fixedVal, 0, &batch_num);

    wqe_fill_info_size = (sizeof(struct trs_remote_fill_wqe_info) + sizeof(struct trs_dma_wr_addr) * batch_num);
    wqe_fill_info = (struct trs_remote_fill_wqe_info *)malloc(wqe_fill_info_size);
    if (wqe_fill_info == NULL) {
        trs_err("Malloc wqe fill info failed. (size=%llu)\n", wqe_fill_info_size);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    urma_opcode = trs_get_async_urma_opcode(dev_id, async_devid->dst_devid, in->dir);
    wqe_fill_info->sq_id = in->sqId;
    wqe_fill_info->recv_dev_id = async_devid->remote_devid;
    wqe_fill_info->urma_opcode = urma_opcode;
    wqe_fill_info->dir = in->dir;
    wqe_fill_info->async_dma_type = in->async_dma_type;
    wqe_fill_info->batch_num = batch_num;
    ret = trs_fill_remote_wr_batch_info(urma_ctx, in, fixedVal, wqe_fill_info);
    if (ret != 0) {
        free(wqe_fill_info);
        return ret;
    }

    reply.buf_len = sizeof(result);
    reply.buf = (char *)&result;
    ret = trs_svm_mem_event_sync(dev_id, wqe_fill_info, wqe_fill_info_size, DRV_SUBEVENT_TRS_FILL_WQE_MSG, &reply);
    if (ret != DRV_ERROR_NONE) {
        free(wqe_fill_info);
        trs_err("Remote fill wqe failed. (dev_id=%u; sq_id=%u)\n", dev_id, in->sqId);
        return ret;
    }

    free(wqe_fill_info);
    return (drvError_t)result;
}

static uint32_t trs_get_async_dwqe_opcode(uint32_t dev_id, struct trs_async_devid *async_devid, uint32_t dir)
{
    if (dir == TRS_ASYNC_HOST_TO_DEVICE) {
        return TRS_URMA_OPCODE_READ;
    } else if (dir == TRS_ASYNC_DEVICE_TO_HOST) {
        return TRS_URMA_OPCODE_WRITE;
    } else if (dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        return (dev_id == async_devid->dst_devid) ? TRS_URMA_OPCODE_READ : TRS_URMA_OPCODE_WRITE;
    } else {
        return 0xFFFF; // 0xFFFF: invalid opcode
    }
}

static void _trs_fill_async_dma_direct_wqe(struct trs_urma_dwqe_fill_para *fill_para, uint8_t *wqe)
{
    struct udma_sqe_ctl_tmp *sqe = (struct udma_sqe_ctl_tmp *)wqe;
    struct udma_wqe_sge_tmp *sge = (struct udma_wqe_sge_tmp *)(wqe + sizeof(struct udma_sqe_ctl_tmp));

    sqe->sqe_bb_idx = (fill_para->sqe_bb_idx & 0xFFFFu);
    sqe->odr = 0x6; // send:0x4; write:0x6
    sqe->fence = 1;
    sqe->se = 1;
    sqe->cqe = (fill_para->cqe_report & 0x1);
    sqe->inline_en = 0;
    sqe->udf_flag = 0;
    sqe->nf = 0;
    sqe->token_en = 1;
    sqe->rmt_jetty_type = 0;
    sqe->owner = 0;
    sqe->target_hint = 0;
    sqe->inline_msg_len = 0;
    sqe->sge_num = 1;

    sqe->tpn = (fill_para->tpn & 0xFFFFFF);
    if (fill_para->rmt_eid != NULL) {
        trs_swap_endian((uint8_t *)sqe->rmt_eid, fill_para->rmt_eid->raw, URMA_EID_SIZE);
    }

    sqe->opcode = (fill_para->op_code & 0xFF);

    sqe->rmt_token_value = fill_para->token.token;
    sqe->rmt_obj_id = (fill_para->seg.token_id >> 8) & 0xFFFFFu; // 8: token_id offset

    /* read/write: JFR segment */
    sqe->rmt_addr_l_or_token_id = ((uint32_t)fill_para->recv_addr) & (0xFFFFFFFF);
    sqe->rmt_addr_h_or_token_value = (uint32_t)(fill_para->recv_addr >> 32) & (0xFFFFFFFF); // 32: right bits

    /* read/write: JFS segment */
    sge->length = (uint32_t)fill_para->len;
    sge->token_id = 0;
    sge->va = fill_para->send_addr;
}

static int trs_fill_async_dma_direct_wqe(struct trs_async_devid *async_devid, struct trs_urma_ctx *urma_ctx,
                                         struct trs_async_ctx *async_ctx, struct trs_async_dma_wqe_info *wqe_info,
                                         struct trs_async_dma_input_para *in)
{
    struct trs_urma_dwqe_fill_para fill_para = {0};
    int ret = 0;

    trs_get_async_send_recv_addr(async_devid, (uint64_t)(uintptr_t)in->async_normal_in.src,
                                 (uint64_t)(uintptr_t)in->async_normal_in.dst, &fill_para.send_addr,
                                 &fill_para.recv_addr);
    fill_para.len = in->async_normal_in.len;
    fill_para.op_code = trs_get_async_dwqe_opcode(async_devid->local_devid, async_devid, in->dir);
    fill_para.sqe_bb_idx = async_ctx->pi;
    fill_para.cqe_report = 1;

    if (in->dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        struct trs_d2d_dev_ctx *d2d_dev_ctx = NULL;
        trs_dev_ctx_mutex_lock(wqe_info->remote_dev_id);
        d2d_dev_ctx = trs_get_d2d_dev_ctx(wqe_info->remote_dev_id);
        if (d2d_dev_ctx == NULL) {
            trs_dev_ctx_mutex_un_lock(wqe_info->remote_dev_id);
            return DRV_ERROR_UNINIT;
        }

        fill_para.tpn = d2d_dev_ctx->tpn[async_devid->local_devid] & 0xFFFFFF;
        fill_para.rmt_eid = &(d2d_dev_ctx->dst_jfr_id.eid);
        trs_dev_ctx_mutex_un_lock(wqe_info->remote_dev_id);
    } else {
        fill_para.tpn = async_ctx->tpn & 0xFFFFFF;
        fill_para.rmt_eid = &(urma_ctx->trs_jfr.jfr->urma_ctx->eid);
    }

    ret = trs_get_segment(urma_ctx, fill_para.recv_addr, fill_para.len, wqe_info, &fill_para.seg, &fill_para.token);
    if (ret != 0) {
        trs_err("Failed to get segment. (vaddr=0x%llx; dir=%u; ret=%d)\n", fill_para.recv_addr, in->dir, ret);
        return ret;
    }

    _trs_fill_async_dma_direct_wqe(&fill_para, wqe_info->wqe);
    return 0;
}

static inline uint32_t trs_get_async_jetty_credit(struct trs_async_ctx *async_ctx, bool is_direct_wqe)
{
    if (is_direct_wqe == true) { /* dwqe not post wr, just pack */
        return trs_jetty_get_credit(async_ctx->pi, async_ctx->ci, TRS_UB_PI_CI_DEPTH);
    } else {
        return trs_jetty_get_credit(async_ctx->pi % TRS_STARS_NORMAL_JETTY_DEPTH,
                                    async_ctx->ci % TRS_STARS_NORMAL_JETTY_DEPTH, TRS_STARS_NORMAL_JETTY_DEPTH);
    }
}

/* fixedVal: means fixedCnt for batch/nop; fixedSIze for others */
static void trs_get_async_post_wr_num(struct trs_async_dma_input_para *in, uint32_t credit, bool is_normal_use_fixedVal,
                                      uint32_t *wr_num, uint64_t *fixedVal, uint64_t *partial_fixed_size)
{
    *wr_num = 0;

    if ((in->async_dma_type == TRS_ASYNC_DMA_TYPE_NORMAL) || (in->async_dma_type == TRS_ASYNC_DMA_TYPE_SQE_UPDATE)) {
        *wr_num = (uint32_t)(align_up(in->async_normal_in.len, TRS_URMA_WR_CPY_MAX_SIZE) / TRS_URMA_WR_CPY_MAX_SIZE);
        if (is_normal_use_fixedVal == true) {
            *fixedVal = (*wr_num <= credit) ? in->async_normal_in.len : (credit * TRS_URMA_WR_CPY_MAX_SIZE);
            *wr_num = (uint32_t)((*wr_num <= credit) ? *wr_num : credit);
        }
    } else if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH) { /* batch : one element is atomic async cpy */
        uint64_t i;

        *fixedVal = 0;
        for (i = 0; i < in->async_batch_in.count; i++) {
            uint32_t tmp = (uint32_t)(align_up(in->async_batch_in.len[i], TRS_URMA_WR_CPY_MAX_SIZE) /
                                      TRS_URMA_WR_CPY_MAX_SIZE);
            if ((*wr_num + tmp) <= credit) {
                (*wr_num) += tmp;
                (*fixedVal)++;
                continue;
            }

            if (partial_fixed_size != NULL) {
                *partial_fixed_size = (credit - *wr_num) * TRS_URMA_WR_CPY_MAX_SIZE;
                *wr_num = credit;
            }
            return;
        }
    } else if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) { /* batch : one byte is atomic async cpy */
        u64 remain_height = in->async_2d_in.height - (in->async_2d_in.fixedSize / in->async_2d_in.width);
        u64 width_offset = (in->async_2d_in.fixedSize % in->async_2d_in.width);
        u64 align_fixed_width = align_up(in->async_2d_in.width - width_offset, TRS_URMA_WR_CPY_MAX_SIZE);
        u32 align_fixed_width_wr_num = (uint32_t)(align_fixed_width / TRS_URMA_WR_CPY_MAX_SIZE);
        u32 align_width_wr_num = (uint32_t)(align_up(in->async_2d_in.width, TRS_URMA_WR_CPY_MAX_SIZE) /
                                            TRS_URMA_WR_CPY_MAX_SIZE);

        *fixedVal = in->async_2d_in.fixedSize;
        if (align_fixed_width_wr_num > credit) { /* credit not meet the the-fixedSize-row */
            *wr_num = credit;
            (*fixedVal) += (credit * TRS_URMA_WR_CPY_MAX_SIZE);
        } else {
            if ((remain_height - 1) * align_width_wr_num >
                (credit - align_fixed_width_wr_num)) { /* credit not meet the whole 2d size */
                *wr_num = credit;
                (*fixedVal) += ((in->async_2d_in.width - width_offset) +
                                (((credit - align_fixed_width_wr_num) / align_width_wr_num) * in->async_2d_in.width) +
                                (((credit - align_fixed_width_wr_num) % align_width_wr_num) *
                                 TRS_URMA_WR_CPY_MAX_SIZE));
            } else { /* credit meet the whole 2d size */
                (*wr_num) = (uint32_t)(align_fixed_width_wr_num + (remain_height - 1) * align_width_wr_num);
                *fixedVal = in->async_2d_in.height * in->async_2d_in.width;
            }
        }
    } else if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_NOP) {
        *wr_num = (credit >= in->async_nop_in.nopCnt) ? (uint32_t)in->async_nop_in.nopCnt : credit;
        *fixedVal = *wr_num;
    }
}

static int trs_fill_async_dma_wqe(struct trs_async_devid *async_devid, struct sqcq_usr_info *sq_info,
                                  struct trs_async_dma_wqe_info *wqe_info, struct trs_async_dma_input_para *in,
                                  struct halAsyncDmaOutputPara *out)
{
    struct trs_urma_ctx *urma_ctx = sq_info->urma_ctx;
    bool is_direct_wqe = trs_is_async_direct_wqe(sq_info->flag, in->async_dma_type);
    bool is_wqe_sink = trs_is_async_jetty_wqe_sink(sq_info->flag);
    struct trs_async_ctx *async_ctx = trs_get_async_ctx(urma_ctx, in->dir, in->async_dma_type);
    uint32_t credit = trs_get_async_jetty_credit(async_ctx, is_direct_wqe);
    uint64_t fixedVal = 0;
    uint32_t wr_num = 0;
    uint32_t last_pi = async_ctx->pi;
    int ret = 0;

    trs_get_async_post_wr_num(in, credit, false, &wr_num, &fixedVal, NULL);
    if (credit < wr_num) {
        trs_err("Jetty Credit not enough. (pi=%u; ci=%u; credit=%u; wr_num=%u)\n", async_ctx->pi, async_ctx->ci, credit,
                wr_num);
        return DRV_ERROR_NO_RESOURCES;
    }

    if (wr_num == 0) { /* 2d/batch support fixSize/fixCnt, which wr_num maybe zero when none credit exist */
        goto exit;
    }

    async_ctx->pi = ((async_ctx->pi + wr_num) % TRS_UB_PI_CI_DEPTH);
    if (is_direct_wqe == true) {
        ret = trs_fill_async_dma_direct_wqe(async_devid, urma_ctx, async_ctx, wqe_info, in);
    } else {
        ret = trs_remote_fill_async_dma_wqe(async_devid, urma_ctx, in, fixedVal);
    }

    if (ret != 0) {
        async_ctx->pi = last_pi;
        return ret;
    }

exit:
    out->jettyId = async_ctx->src_jetty_id.id;
    out->pi = (is_wqe_sink == false) ? async_ctx->pi : wr_num; /* absolute in single task, relative in task sinking */
    out->functionId = async_ctx->func_id;
    out->dieId = async_ctx->die_id;
    out->fixedSize = fixedVal;
    return 0;
}

static inline uint64_t trs_get_sq_bind_remote_que_addr(uint32_t dev_id, uint32_t ts_id, struct sqcq_usr_info *sq_info)
{
    if (((struct trs_urma_ctx *)sq_info->urma_ctx)->remote_sq_que_addr != 0) {
        return ((struct trs_urma_ctx *)sq_info->urma_ctx)->remote_sq_que_addr;
    }

    if (sq_info->switch_stream_flag) {
        struct res_id_usr_info *stream_usr_info = trs_get_res_id_info(dev_id, ts_id, DRV_STREAM_ID, sq_info->stream_id);
        if ((stream_usr_info != NULL) && (stream_usr_info->valid != 0)) {
            return stream_usr_info->res_addr;
        }
    }

    return (uintptr_t)NULL;
}

static int trs_fill_h2d_async_dma_wqe(struct trs_async_devid *async_devid, struct sqcq_usr_info *sq_info,
                                      struct trs_async_dma_wqe_info *wqe_info, struct trs_async_dma_input_para *in,
                                      struct halAsyncDmaOutputPara *out)
{
    uint32_t sqid = in->async_normal_in.info.sq_id;
    uint32_t sqe_pos = 0;
    int ret;

    if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_SQE_UPDATE) {
        struct sqcq_usr_info *update_sq_info = NULL;
        uint64_t remote_sq_que_addr = 0;

        update_sq_info = trs_get_sq_info(async_devid->local_devid, in->tsId, in->type, sqid);
        if ((update_sq_info == NULL) || (update_sq_info->urma_ctx == NULL)) {
            trs_err("Invalid para. (devid=%u; tsId=%u; type=%d; sqid=%u)\n", async_devid->local_devid, in->tsId,
                    in->type, sqid);
            return DRV_ERROR_INVALID_VALUE;
        }

        sqe_pos = in->async_normal_in.info.sqe_pos;
        if ((sqe_pos >= update_sq_info->depth) ||
            (in->async_normal_in.len > (update_sq_info->depth - sqe_pos) * update_sq_info->e_size)) {
            trs_err("Invalid para. (sqid=%u; sqe_pos=%u; len=%u; depth=%u, sqe_size=%u)\n", sqid, sqe_pos,
                    in->async_normal_in.len, update_sq_info->depth, update_sq_info->e_size);
            return DRV_ERROR_PARA_ERROR;
        }

        remote_sq_que_addr = trs_get_sq_bind_remote_que_addr(async_devid->local_devid, 0, update_sq_info);
        if (remote_sq_que_addr == 0) {
            trs_err("Sq queue not inited. (devid=%u; type=%d; sqid=%u)\n", async_devid->local_devid, in->type, sqid);
            return DRV_ERROR_PARA_ERROR;
        }

        in->async_normal_in.dst = (u8 *)(uintptr_t)remote_sq_que_addr + sqe_pos * update_sq_info->e_size;
        trs_debug("(devid=%u; sqid=%u; sqe_pos=%u; sqe_size=%u; len=%u; remote_sq_que_addr=0x%llx; dst=0x%llx)\n",
                  async_devid->local_devid, sqid, sqe_pos, update_sq_info->e_size, in->async_normal_in.len,
                  remote_sq_que_addr, (u64)(uintptr_t)in->async_normal_in.dst);
    }

    ret = trs_fill_async_dma_wqe(async_devid, sq_info, wqe_info, in, out);
    if (in->async_dma_type == TRS_ASYNC_DMA_TYPE_SQE_UPDATE) {
        in->async_normal_in.info.sq_id = sqid;
        in->async_normal_in.info.sqe_pos = sqe_pos;
    }

    return ret;
}

static int trs_fill_d2h_async_dma_wqe(struct trs_async_devid *async_devid, struct sqcq_usr_info *sq_info,
                                      struct trs_async_dma_wqe_info *wqe_info, struct trs_async_dma_input_para *in,
                                      struct halAsyncDmaOutputPara *out)
{
    return trs_fill_async_dma_wqe(async_devid, sq_info, wqe_info, in, out);
}

static int trs_alloc_device_jetty(uint32_t dev_id, struct trs_d2d_send_info *alloc_info,
                                  struct trs_d2d_sync_info *sync_msg)
{
    struct event_reply reply;
    int ret, result;

    reply.buf_len = sizeof(struct trs_d2d_sync_info) + sizeof(int);
    reply.buf = (char *)malloc(reply.buf_len);
    if (reply.buf == NULL) {
        trs_err("Malloc reply buffer failed. (size=%u)\n", reply.buf_len);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    ret = trs_local_mem_event_sync(dev_id, alloc_info, sizeof(struct trs_d2d_send_info),
                                   DRV_SUBEVENT_TRS_CREATE_ASYNC_JETTY_MSG, &reply);
    result = DRV_EVENT_REPLY_BUFFER_RET(reply.buf);
    if ((ret != DRV_ERROR_NONE) || (result != 0)) {
#ifndef EMU_ST
        trs_err("Failed to sync event. (dev_id=%u; ret=%d; result=%d)\n", dev_id, ret, result);
        free(reply.buf);
        return (ret != DRV_ERROR_NONE) ? ret : result;
#endif
    }
    (void)memcpy_s(sync_msg, sizeof(struct trs_d2d_sync_info), DRV_EVENT_REPLY_BUFFER_DATA_PTR(reply.buf),
                   sizeof(struct trs_d2d_sync_info));

    free(reply.buf);
    return 0;
}

static int trs_free_device_jetty(uint32_t dev_id, struct trs_d2d_send_info *free_info)
{
    struct event_reply reply;
    int result, ret;

    reply.buf_len = sizeof(result);
    reply.buf = (char *)&result;
    ret = trs_local_mem_event_sync(dev_id, free_info, sizeof(struct trs_d2d_send_info),
                                   DRV_SUBEVENT_TRS_DESTROY_ASYNC_JETTY_MSG, &reply);
    if ((ret != 0) || (result != 0)) {
        trs_err("Failed to sync destroy async jetty. (ret=%d; result=%d; dev_id=%u)\n", ret, result, dev_id);
        return (ret != 0) ? ret : result;
    }

    return 0;
}

static int trs_import_remote_d2d_jetty(uint32_t dev_id, uint32_t remote_dev_id, struct trs_d2d_dev_ctx *d2d_dev_ctx)
{
    struct trs_d2d_sync_info sync_msg = {0};
    struct trs_import_jetty_info info = {0};
    struct event_reply reply;
    int result, ret;

    (void)memcpy_s(info.jfr_raw, URMA_EID_SIZE, d2d_dev_ctx->dst_jfr_id.eid.raw, URMA_EID_SIZE);
    info.jfr_uasid = d2d_dev_ctx->dst_jfr_id.uasid;
    info.jfr_id = d2d_dev_ctx->dst_jfr_id.id;
    info.token_val = d2d_dev_ctx->token_value;
    info.recv_dev_id = remote_dev_id;
    reply.buf_len = sizeof(struct trs_d2d_sync_info) + sizeof(int);
    reply.buf = (char *)malloc(reply.buf_len);
    if (reply.buf == NULL) {
        trs_err("Malloc reply buffer failed.\n");
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    ret = trs_local_mem_event_sync(dev_id, &info, sizeof(struct trs_import_jetty_info),
                                   DRV_SUBEVENT_TRS_IMPORT_ASYNC_JETTY_MSG, &reply);
    result = DRV_EVENT_REPLY_BUFFER_RET(reply.buf);
    if ((ret != 0) || (result != 0)) {
        free(reply.buf);
        trs_err("Failed to sync import remote jetty. (ret=%d; result=%d; dev_id=%u)\n", ret, result, dev_id);
        return (ret != 0) ? ret : result;
    }

    (void)memcpy_s(&sync_msg, sizeof(struct trs_d2d_sync_info), DRV_EVENT_REPLY_BUFFER_DATA_PTR(reply.buf),
                   sizeof(struct trs_d2d_sync_info));
    d2d_dev_ctx->tpn[dev_id] = sync_msg.tpn;
    d2d_dev_ctx->tpn_valid[dev_id] = true;

    free(reply.buf);
    return 0;
}

static int trs_create_local_d2d_jetty(struct trs_async_devid *d2d_async_devid, uint32_t sq_id, uint32_t flag,
                                      struct trs_async_ctx *async_ctx)
{
    struct trs_d2d_sync_info sync_msg;
    struct trs_d2d_send_info alloc_info = {0};
    int ret;
    alloc_info.flag = flag;
    alloc_info.pos = TRS_ASYNC_SEND_SIDE;
    alloc_info.sq_id = sq_id;
    ret = trs_alloc_device_jetty(d2d_async_devid->local_devid, &alloc_info, &sync_msg);
    if (ret != 0) {
        trs_err("Failed to alloc device jetty. (local_devid=%u; sq_id=%u)\n", d2d_async_devid->local_devid, sq_id);
        return ret;
    }
    async_ctx->src_jetty_id = sync_msg.jetty_id;
    async_ctx->func_id = sync_msg.func_id;
    async_ctx->die_id = sync_msg.die_id;
    return 0;
}

static int trs_destroy_local_d2d_jetty(uint32_t local_devid, uint32_t sq_id)
{
    struct trs_d2d_send_info free_info = {0};
    free_info.pos = TRS_ASYNC_SEND_SIDE;
    free_info.sq_id = sq_id;
    return trs_free_device_jetty(local_devid, &free_info);
}

static int trs_create_remote_d2d_jetty(uint32_t remote_devid, uint32_t flag, struct trs_d2d_dev_ctx *d2d_dev_ctx)
{
    struct trs_d2d_sync_info sync_msg;
    struct trs_d2d_send_info alloc_info = {0};
    int ret;

    alloc_info.flag = flag;
    alloc_info.pos = TRS_ASYNC_RECV_SIDE;
    ret = trs_alloc_device_jetty(remote_devid, &alloc_info, &sync_msg);
    if (ret != 0) {
        trs_err("Failed to alloc remote jetty. (ret=%d; remote_devid=%u; flag=0x%x)\n", ret, remote_devid, flag);
        return ret;
    }

    d2d_dev_ctx->dst_jfr_id = sync_msg.jfr_id;
    d2d_dev_ctx->token_value = sync_msg.token_value;

    trs_debug("Create jetty success. (remote_devid=%u; jfr_id=%u; flag=0x%x)\n", remote_devid,
              d2d_dev_ctx->dst_jfr_id.id, flag);
    return 0;
}

int trs_destroy_remote_d2d_jetty(uint32_t dev_id)
{
    /* remote use d2d proc_ctx->jfr, would destroy by device close */
    (void)dev_id;
    return 0;
}

static int trs_d2d_dev_ctx_check_init(struct trs_async_devid *d2d_async_devid, uint32_t flag)
{
    struct trs_d2d_dev_ctx *d2d_dev_ctx = NULL;
    uint32_t remote_devid = d2d_async_devid->remote_devid;
    uint32_t local_devid = d2d_async_devid->local_devid;
    int ret = 0;

    trs_dev_ctx_mutex_lock(remote_devid);

    d2d_dev_ctx = trs_get_d2d_dev_ctx(remote_devid);
    if (d2d_dev_ctx == NULL) {
        d2d_dev_ctx = (struct trs_d2d_dev_ctx *)calloc(1, sizeof(struct trs_d2d_dev_ctx));
        if (d2d_dev_ctx == NULL) {
            trs_err("Alloc d2d_dev_ctx failed. (remote_devid=%u)\n", remote_devid);
            ret = DRV_ERROR_OUT_OF_MEMORY;
            goto exit;
        }

        ret = trs_create_remote_d2d_jetty(remote_devid, flag, d2d_dev_ctx);
        if (ret != 0) {
            trs_err("Failed to create remote jetty. (local_devid=%u; remote_devid=%u; ret=%d; flag=0x%x)\n",
                    local_devid, remote_devid, ret, flag);
            free(d2d_dev_ctx);
            goto exit;
        }

        trs_set_d2d_dev_ctx(remote_devid, (void *)d2d_dev_ctx);
        trs_debug("Create remote jetty success. (remote_devid=%u; flag=0x%x; jetty_id=%u)\n", remote_devid, flag,
                  d2d_dev_ctx->dst_jfr_id.id);
    }

    if (d2d_dev_ctx->tpn_valid[local_devid] == false) {
        ret = trs_import_remote_d2d_jetty(local_devid, remote_devid, d2d_dev_ctx);
        if (ret != 0) {
            goto exit; /* destroy remote jetty when close device */
        }
    }

exit:
    (void)trs_dev_ctx_mutex_un_lock(remote_devid);
    return ret;
}

static int trs_d2d_async_ctx_create(struct trs_urma_ctx *urma_ctx, struct trs_async_devid *d2d_async_devid,
                                    uint32_t sq_id, uint32_t flag)
{
    uint32_t local_devid = d2d_async_devid->local_devid;
    struct trs_async_ctx *async_ctx = &urma_ctx->d2d_async_ctx;
    int ret, create_local_flag = 0;

    (void)pthread_mutex_lock(&urma_ctx->ctx_mutex);
    if (!async_ctx->init_flag) {
        ret = trs_create_local_d2d_jetty(d2d_async_devid, sq_id, flag, async_ctx);
        if (ret != 0) {
            (void)pthread_mutex_unlock(&urma_ctx->ctx_mutex);
            trs_err("Failed to create local jetty. (local_devid=%u; ret=%d; flag=0x%x)\n", local_devid, ret, flag);
            return ret;
        }
        async_ctx->init_flag = true;
        create_local_flag = 1;
        trs_debug("Create local jetty success. (devid=%u; flag=0x%x; sq_id=%u; jetty_id=%u; fun_id=%u; die_id=%u)\n",
                  local_devid, flag, sq_id, async_ctx->src_jetty_id.id, async_ctx->func_id, async_ctx->die_id);
    }
    (void)pthread_mutex_unlock(&urma_ctx->ctx_mutex);

    ret = trs_d2d_dev_ctx_check_init(d2d_async_devid, flag);
    if (ret != 0) {
        if (create_local_flag == 1) {
            (void)pthread_mutex_lock(&urma_ctx->ctx_mutex);
            (void)trs_destroy_local_d2d_jetty(local_devid, sq_id);
            async_ctx->init_flag = false;
            (void)pthread_mutex_unlock(&urma_ctx->ctx_mutex);
        }
        return ret;
    }

    return 0;
}

static int trs_d2d_async_ctx_destroy(uint32_t dev_id, uint32_t sq_id, struct trs_urma_ctx *urma_ctx)
{
    int ret;

    (void)pthread_mutex_lock(&urma_ctx->ctx_mutex);
    if (urma_ctx->d2d_async_ctx.init_flag) {
        ret = trs_destroy_local_d2d_jetty(dev_id, sq_id);
        if (ret != 0) {
            (void)pthread_mutex_unlock(&urma_ctx->ctx_mutex);
            trs_err("Failed to destroy local jetty. (dev_id=%u; sq_id=%u; ret=%d)\n", dev_id, sq_id, ret);
            return ret;
        }
        trs_debug("Destroy d2d jetty success. (dev_id=%u; sq_id=%u)\n", dev_id, sq_id);
        urma_ctx->d2d_async_ctx.init_flag = false;
    }
    (void)pthread_mutex_unlock(&urma_ctx->ctx_mutex);

    return 0;
}

static int trs_fill_d2d_async_dma_wqe(struct trs_async_devid *async_devid, struct sqcq_usr_info *sq_info,
                                      struct trs_async_dma_wqe_info *wqe_info, struct trs_async_dma_input_para *in,
                                      struct halAsyncDmaOutputPara *out)
{
    wqe_info->remote_dev_id = async_devid->remote_devid;
    return trs_fill_async_dma_wqe(async_devid, sq_info, wqe_info, in, out);
}

static int (*const trs_async_dma_wqe_fill_handles[TRS_ASYNC_MAX_DIR])(struct trs_async_devid *async_devid,
                                                                      struct sqcq_usr_info *sq_info,
                                                                      struct trs_async_dma_wqe_info *wqe_info,
                                                                      struct trs_async_dma_input_para *in,
                                                                      struct halAsyncDmaOutputPara *out) = {
    [TRS_ASYNC_HOST_TO_DEVICE] = trs_fill_h2d_async_dma_wqe,
    [TRS_ASYNC_DEVICE_TO_HOST] = trs_fill_d2h_async_dma_wqe,
    [TRS_ASYNC_DEVICE_TO_DEVICE] = trs_fill_d2d_async_dma_wqe,
};

static int trs_h2d2h_async_ctx_init(uint32_t dev_id, struct trs_urma_ctx *urma_ctx, uint32_t sqId, uint32_t subevent_id,
                                    struct trs_async_ctx *async_ctx)
{
    struct trs_async_jetty_init_para jetty_para = {0};
    uint32_t sq_id = sqId;
    struct event_reply reply;
    int ret, result;

    reply.buf_len = sizeof(struct trs_async_jetty_init_para) + sizeof(int);
    reply.buf = (char *)malloc(reply.buf_len);
    if (reply.buf == NULL) {
        trs_err("Malloc reply buffer failed. (size=%u)\n", reply.buf_len);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    ret = trs_local_mem_event_sync(dev_id, &sq_id, sizeof(uint32_t), subevent_id, &reply);
    result = DRV_EVENT_REPLY_BUFFER_RET(reply.buf);

    if ((ret != DRV_ERROR_NONE) || (result != 0)) {
        trs_err("Failed to sync event. (dev_id=%u; subevent_id=%u; ret=%d; result=%d)\n", dev_id, subevent_id, ret,
                result);
        free(reply.buf);
        return (ret != DRV_ERROR_NONE) ? ret : result;
    }

    (void)memcpy_s(&jetty_para, sizeof(struct trs_async_jetty_init_para), DRV_EVENT_REPLY_BUFFER_DATA_PTR(reply.buf),
                   sizeof(struct trs_async_jetty_init_para));
    free(reply.buf);

    async_ctx->src_jetty_id = jetty_para.jetty_id;
    async_ctx->tpn = jetty_para.tpn;
    async_ctx->die_id = urma_ctx->die_id;
    async_ctx->func_id = urma_ctx->func_id;
    async_ctx->init_flag = true;
    return 0;
}

static int trs_async_init_async_ctx(struct trs_async_devid *async_devid, struct sqcq_usr_info *sq_info,
                                    struct trs_async_dma_input_para *in)
{
    struct trs_urma_ctx *urma_ctx = sq_info->urma_ctx;
    int ret = 0;

    if (in->dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        ret = trs_d2d_async_ctx_create(urma_ctx, async_devid, in->sqId, sq_info->flag);
        if (ret != 0) {
            return ret;
        }
    }

    if ((in->dir == TRS_ASYNC_HOST_TO_DEVICE) || (in->dir == TRS_ASYNC_DEVICE_TO_HOST)) {
        struct trs_async_ctx *async_ctx = NULL;
        uint32_t subevent_id;

        if ((in->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) || (in->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH)) {
            async_ctx = &urma_ctx->batch_2d_async_ctx;
            subevent_id = DRV_SUBEVENT_TRS_INIT_BATCH_2D_JETTY_MSG;
        } else {
            async_ctx = &urma_ctx->async_ctx;
            subevent_id = DRV_SUBEVENT_TRS_INIT_H2D2H_JETTY_MSG;
        }

        if (async_ctx->init_flag == false) {
            ret = trs_h2d2h_async_ctx_init(async_devid->local_devid, urma_ctx, in->sqId, subevent_id, async_ctx);
            if (ret != 0) {
                return ret;
            }
        }
    }

    return 0;
}

/* all async ctx would be destroyed in sq free */
int trs_async_uninit_async_ctx(uint32_t dev_id, uint32_t sq_id, void *master_ctx)
{
    struct trs_urma_ctx *urma_ctx = (struct trs_urma_ctx *)master_ctx;

    if (urma_ctx->batch_2d_async_ctx.init_flag == true) {
        /* batch_2d jetty destroyed in sqcq remote free */
        urma_ctx->batch_2d_async_ctx.init_flag = false;
    }

    return trs_d2d_async_ctx_destroy(dev_id, sq_id, urma_ctx);
}

drvError_t trs_async_dma_wqe_create(uint32_t dev_id, struct trs_async_dma_input_para *in,
                                    struct halAsyncDmaOutputPara *out)
{
    struct sqcq_usr_info *sq_info = NULL;
    struct trs_async_dma_wqe_info *wqe_info = NULL;
    struct trs_async_devid async_devid = {0};
    int ret;

    ret = trs_get_check_async_devid_dir(dev_id, in, &async_devid, &in->dir);
    if (ret != 0) {
        return ret;
    }

    if (((in->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH) || (in->async_dma_type == TRS_ASYNC_DMA_TYPE_2D)) &&
        (in->dir == TRS_ASYNC_DEVICE_TO_DEVICE)) {
        return DRV_ERROR_NOT_SUPPORT;
    }

    sq_info = trs_get_sq_info(dev_id, in->tsId, in->type, in->sqId);
    if ((sq_info == NULL) || (sq_info->urma_ctx == NULL)) {
        trs_err("Invalid para. (dev_id=%u; ts_id=%u; type=%d; sq_id=%u)\n", dev_id, in->tsId, in->type, in->sqId);
        return DRV_ERROR_INVALID_VALUE;
    }

    /* d2d and 2d/batch async cpy need init when first submit */
    ret = trs_async_init_async_ctx(&async_devid, sq_info, in);
    if (ret != 0) {
        return ret;
    }

    wqe_info = (struct trs_async_dma_wqe_info *)calloc(1, sizeof(struct trs_async_dma_wqe_info));
    if (wqe_info == NULL) {
        trs_err("WqeInfo malloc failed. (dev_id=%u)\n", dev_id);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    ret = trs_async_dma_wqe_fill_handles[in->dir](&async_devid, sq_info, wqe_info, in, out);
    if (ret != 0) {
        trs_err("Failed to fill async dma wqe. (ret=%d; dev_id=%u; sq_id=%u)\n", ret, dev_id, in->sqId);
        free(wqe_info);
        return ret;
    }

    /* normal dma dwqe cpy need to store tseg when destroy */
    if (trs_is_async_direct_wqe(sq_info->flag, in->async_dma_type) == true) {
        wqe_info->dir = (uint8_t)in->dir;
        out->size = STARS_ASYNC_DMA_WQE_SIZE;
        out->wqe = wqe_info->wqe;
    } else {
        out->size = 0;
        out->wqe = NULL;
        free(wqe_info);
    }

    trs_debug("Create async dma wqe. (dev_id=%u; dir=%u; sq_id=%u; dieid=%u; func_id=%u; jetty_id=%u)\n", dev_id,
              in->dir, in->sqId, out->dieId, out->functionId, out->jettyId);
    return DRV_ERROR_NONE;
}

static drvError_t trs_async_dma_wqe_normal_destory(uint32_t dev_id, struct trs_urma_ctx *urma_ctx,
                                                   struct halAsyncDmaDestoryPara *para)
{
    struct trs_async_dma_wqe_info *wqe_info = NULL;
    struct trs_async_ctx *async_ctx = NULL;

    if ((para->wqe == NULL) && (para->size == 0)) {
        return DRV_ERROR_NONE;
    }

    if ((para->wqe == NULL) || (para->size != STARS_ASYNC_DMA_WQE_SIZE)) {
        trs_err("Invalid para. (dev_id=%u; wqe=0x%llx; size=%u)\n", dev_id, (uint64_t)(uintptr_t)para->wqe, para->size);
        return DRV_ERROR_INVALID_VALUE;
    }

    wqe_info = (struct trs_async_dma_wqe_info *)(void *)para->wqe;
    if ((wqe_info->flag == 1) && (wqe_info->async_tseg != NULL)) {
        (void)urma_unregister_seg(wqe_info->async_tseg);
        trs_debug("Unregister seg. (dev_id=%u)\n", dev_id);
    }
    async_ctx = trs_get_async_ctx(urma_ctx, wqe_info->dir, TRS_ASYNC_DMA_TYPE_NORMAL);
    if (async_ctx == NULL) {
        trs_err("Not create. (dev_id=%u; sq_id=%u)\n", dev_id, para->sqId);
        return DRV_ERROR_UNINIT;
    }

    async_ctx->ci = (async_ctx->ci + 1) % trs_get_async_pi_ci_max(false);
    trs_debug("Async dma wqe destroy. (dev_id=%u; sq_id=%u; ci=%u; dir=%u)\n", dev_id, para->sqId, async_ctx->ci,
              wqe_info->dir);
    free(wqe_info);
    return 0;
}

static drvError_t trs_async_dma_wqe_batch_2d_destory(uint32_t dev_id, struct trs_urma_ctx *urma_ctx,
                                                     struct trs_async_dma_destroy_para *para)
{
    struct trs_async_ctx *async_ctx = NULL;

    if (para->async_batch_para->ci >= TRS_UB_PI_CI_DEPTH) {
        trs_err("The ci exceed. (dev_id=%u; sq_id=%u; ci=%u; max=%d)\n", dev_id, para->sqId, para->async_batch_para->ci,
                TRS_UB_PI_CI_DEPTH);
        return DRV_ERROR_PARA_ERROR;
    }

    async_ctx = &urma_ctx->batch_2d_async_ctx;
    if (async_ctx->init_flag == false) {
        trs_err("Not create. (dev_id=%u; sq_id=%u)\n", dev_id, para->sqId);
        return DRV_ERROR_UNINIT;
    }

    async_ctx->ci = para->async_batch_para->ci;
    trs_debug("Async dma wqe destroy. (dev_id=%u; sq_id=%u; ci=%u;)\n", dev_id, para->sqId, async_ctx->ci);

    return 0;
}

drvError_t trs_async_dma_wqe_destory(uint32_t dev_id, struct trs_async_dma_destroy_para *para)
{
    struct sqcq_usr_info *sq_info = NULL;
    struct trs_urma_ctx *urma_ctx = NULL;
    int ret = 0;

    sq_info = trs_get_sq_info(dev_id, para->tsId, DRV_NORMAL_TYPE, para->sqId);
    if (sq_info == NULL) {
        trs_err("Invalid para. (dev_id=%u; ts_id=%u; sq_id=%u)\n", dev_id, para->tsId, para->sqId);
        return DRV_ERROR_INVALID_VALUE;
    }

    urma_ctx = (struct trs_urma_ctx *)sq_info->urma_ctx;
    if (para->async_dma_type == TRS_ASYNC_DMA_TYPE_NORMAL) {
        ret = trs_async_dma_wqe_normal_destory(dev_id, urma_ctx, para->normal_para);
    } else if ((para->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) || (para->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH)) {
        ret = trs_async_dma_wqe_batch_2d_destory(dev_id, urma_ctx, para);
    } else {
        ret = DRV_ERROR_NOT_SUPPORT;
    }

    return ret;
}

drvError_t trs_sq_jetty_info_query(uint32_t dev_id, struct halSqCqQueryInfo *info)
{
    struct sqcq_usr_info *sq_info = NULL;
    struct trs_async_ctx *async_ctx = NULL;
    struct trs_urma_ctx *urma_ctx = NULL;
    uint32_t dir;

    sq_info = trs_get_sq_info(dev_id, info->tsId, info->type, info->sqId);
    if ((sq_info == NULL) || (sq_info->urma_ctx == NULL)) {
        trs_err("Invalid para. (dev_id=%u; ts_id=%u; type=%d; sq_id=%u)\n", dev_id, info->tsId, info->type, info->sqId);
        return DRV_ERROR_INVALID_VALUE;
    }

    if ((sq_info->flag & TSDRV_FLAG_TASK_SINK_SQ) == 0) {
        return DRV_ERROR_NOT_SUPPORT;
    }

    urma_ctx = (struct trs_urma_ctx *)sq_info->urma_ctx;
    dir = (info->prop == DRV_SQCQ_PROP_D2D_ASYNC_JETTY_INFO) ? TRS_ASYNC_DEVICE_TO_DEVICE : TRS_ASYNC_HOST_TO_DEVICE;

    async_ctx = trs_get_async_ctx(urma_ctx, dir, TRS_ASYNC_DMA_TYPE_NORMAL);
    if (async_ctx == NULL) {
        trs_err("Failed to get async ctx. (dev_id=%u; sq_id=%u; prop=%d)\n", dev_id, info->sqId, info->prop);
        return DRV_ERROR_UNINIT;
    }

    info->value[0] = trs_get_async_pi_ci_max(true) - async_ctx->pi; /* 0: NOP number */
    info->value[1] = async_ctx->src_jetty_id.id;                    /* 1: jetty id */
    info->value[2] = async_ctx->func_id;                            /* 2: func id */
    info->value[3] = async_ctx->die_id;                             /* 3: die id*/
    trs_debug("Query jetty info. (devid=%u; sqid=%u; prop=%d; nop_num=%u; jetty_id=%u; func_id=%u; die_id=%u)\n",
              dev_id, info->sqId, info->prop, info->value[0], info->value[1], info->value[2], info->value[3]);

    return DRV_ERROR_NONE;
}

static int trs_async_dma_jetty_remote_alloc(uint32_t dev_id, struct halAsyncDmaJettyCreateIn *in,
                                            struct trs_async_jetty_info *jetty_info)
{
    struct trs_urma_proc_ctx *urma_proc_ctx = NULL;
    struct trs_remote_alloc_jetty_para jetty_para = {0};
    struct event_reply reply;
    drvError_t ret = 0;
    int result;

    reply.buf_len = sizeof(struct trs_async_jetty_info) + sizeof(int);
    reply.buf = (char *)malloc(reply.buf_len);
    if (reply.buf == NULL) {
        trs_err("Malloc reply buffer failed. (size=%u)\n", reply.buf_len);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    urma_proc_ctx = trs_get_urma_proc_ctx(dev_id);
    jetty_para.in = *in;
    jetty_para.jfr_id = urma_proc_ctx->trs_jfr.jfr->jfr_id;
    jetty_para.token = urma_proc_ctx->token;
    ret = trs_svm_mem_event_sync(dev_id, &jetty_para, sizeof(struct trs_remote_alloc_jetty_para),
                                 DRV_SUBEVENT_TRS_ALLOC_JETTY_MSG, &reply);
    result = DRV_EVENT_REPLY_BUFFER_RET(reply.buf);

    if ((ret != DRV_ERROR_NONE) || (result != 0)) {
        trs_err("Failed to sync event. (dev_id=%u; ret=%d; result=%d)\n", dev_id, ret, result);
        free(reply.buf);
        return (ret != DRV_ERROR_NONE) ? (int)ret : result;
    }

    (void)memcpy_s(jetty_info, sizeof(struct trs_async_jetty_info), DRV_EVENT_REPLY_BUFFER_DATA_PTR(reply.buf),
                   sizeof(struct trs_async_jetty_info));
    free(reply.buf);

    return 0;
}

static int trs_async_dma_jetty_remote_free(uint32_t dev_id, struct trs_urma_stars_jetty *slave_jetty_addr)
{
    struct event_reply reply;
    drvError_t ret = 0;
    int result;

    reply.buf_len = sizeof(result);
    reply.buf = (char *)&result;

    ret = trs_local_mem_event_sync(dev_id, &slave_jetty_addr, sizeof(struct trs_urma_stars_jetty *),
                                   DRV_SUBEVENT_TRS_FREE_JETTY_MSG, &reply);
    if ((ret != DRV_ERROR_NONE) || (result != 0)) {
        trs_err("Failed to sync event. (dev_id=%u; ret=%d; result=%d)\n", dev_id, ret, result);
        return (ret != DRV_ERROR_NONE) ? (int)ret : result;
    }

    return 0;
}

static inline void trs_async_update_h2d2h_tpn(uint32_t dev_id, drvAsyncDmaJettyDir_t dir, uint32_t tpn)
{
    if (dir == TRS_ASYNC_JETTY_HOST_DEVICE) { /* get h2d d2h tjetty tpn */
        struct trs_urma_proc_ctx *urma_proc_ctx = trs_get_urma_proc_ctx(dev_id);
        if (urma_proc_ctx->tpn_valid == false) {
            urma_proc_ctx->tpn = tpn;
            urma_proc_ctx->tpn_valid = true;
        }
    }
}

static inline void trs_async_jetty_node_free(void *jetty_node)
{
    if (((struct trs_async_jetty_node *)jetty_node)->is_free_implicitly == true) {
        free(jetty_node);
    }
}

drvError_t trs_async_dma_jetty_create(uint32_t dev_id, struct halAsyncDmaJettyCreateIn *in,
                                      struct halAsyncDmaJettyCreateOut *out)
{
    struct trs_async_jetty_node *jetty_node = NULL;
    struct trs_async_jetty_info *jetty_info = NULL;
    int ret = 0;

    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        return DRV_ERROR_UNINIT;
    }

    jetty_node = (struct trs_async_jetty_node *)calloc(1, sizeof(struct trs_async_jetty_node));
    if (jetty_node == NULL) {
        trs_err("Failed to alloc jetty node. (dev_id=%u; size=%ld)\n", dev_id, sizeof(struct trs_async_jetty_node));
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    jetty_info = &jetty_node->jetty_info;
    ret = trs_async_dma_jetty_remote_alloc(dev_id, in, jetty_info);
    if (ret != 0) {
        free(jetty_node);
        return ret;
    }

    ret = snprintf_s(jetty_node->jettyHandle.handle, TRS_ASYNC_DMA_JETTY_HANDLE_LEN, TRS_ASYNC_DMA_JETTY_HANDLE_LEN - 1,
                     "%08x%08x%08x", jetty_info->die_id, jetty_info->func_id, jetty_info->jetty_id);
    if (ret < 0) {
        trs_err("Failed to format jetty handle. (dev_id=%u; ret=%d)\n", dev_id, ret);
        ret = DRV_ERROR_INNER_ERR;
        goto remote_free;
    }

    ret = trs_register_reg(dev_id, jetty_info->jetty_queue_base, jetty_info->jetty_queue_len);
    if (ret != 0) {
        goto remote_free;
    }

    (void)pthread_rwlock_wrlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
    ret = hash_table_put2(g_jetty_mng_ctx[dev_id].hash_table, jetty_node->jettyHandle.handle, jetty_node,
                          trs_async_jetty_node_free);
    if (ret != 0) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to instert jetty node. (dev_id=%u; ret=%d)\n", dev_id, ret);
        ret = DRV_ERROR_INNER_ERR;
        goto unregister_seg;
    }

    g_jetty_mng_ctx[dev_id].node_num++;
    out->jettyHandle = &jetty_node->jettyHandle;
    trs_async_update_h2d2h_tpn(dev_id, in->dir, jetty_info->tpn);
    (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
    return 0;

unregister_seg:
    trs_unregister_reg(dev_id, jetty_info->jetty_queue_base, jetty_info->jetty_queue_len);
remote_free:
    (void)trs_async_dma_jetty_remote_free(dev_id, jetty_info->slave_jetty_addr);
    free(jetty_node);
    return ret;
}

drvError_t trs_async_dma_jetty_destroy(uint32_t dev_id, struct halAsyncJettyDestroyPara *para)
{
    struct trs_async_jetty_node *jetty_node = NULL;
    drvError_t ret = 0;

    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        return DRV_ERROR_UNINIT;
    }

    (void)pthread_rwlock_wrlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

    jetty_node = hash_table_get(g_jetty_mng_ctx[dev_id].hash_table, para->jettyHandle->handle);
    if (jetty_node == NULL) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to find jetty node. (dev_id=%u; handle=%s)\n", dev_id, para->jettyHandle->handle);
        return DRV_ERROR_UNINIT;
    }

    g_jetty_mng_ctx[dev_id].node_num--;
    hash_table_rm(g_jetty_mng_ctx[dev_id].hash_table, para->jettyHandle->handle);

    (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

    trs_unregister_reg(dev_id, jetty_node->jetty_info.jetty_queue_base, jetty_node->jetty_info.jetty_queue_len);
    ret = trs_async_dma_jetty_remote_free(dev_id, jetty_node->jetty_info.slave_jetty_addr);
    if (ret != 0) {
        trs_register_reg(dev_id, jetty_node->jetty_info.jetty_queue_base, jetty_node->jetty_info.jetty_queue_len);
        (void)pthread_rwlock_wrlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        (void)hash_table_put2(g_jetty_mng_ctx[dev_id].hash_table, jetty_node->jettyHandle.handle, jetty_node,
                              trs_async_jetty_node_free);
        g_jetty_mng_ctx[dev_id].node_num++;
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        return ret;
    }

    free(jetty_node);
    return 0;
}

drvError_t trs_async_dma_jetty_query(uint32_t dev_id, struct halAsyncDmaJettyQueryIn *in,
                                     struct halAsyncDmaJettyQueryOut *out)
{
    struct trs_async_jetty_node *jetty_node = NULL;

    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        return DRV_ERROR_UNINIT;
    }

    (void)pthread_rwlock_rdlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

    jetty_node = hash_table_get(g_jetty_mng_ctx[dev_id].hash_table, in->jettyHandle->handle);
    if (jetty_node == NULL) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to find jetty node. (dev_id=%u; handle=%s)\n", dev_id, in->jettyHandle->handle);
        return DRV_ERROR_UNINIT;
    }

    out->dieId = jetty_node->jetty_info.die_id;
    out->funcId = jetty_node->jetty_info.func_id;
    out->jettyId = jetty_node->jetty_info.jetty_id;
    (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

    return 0;
}

static int trs_async_dma_nop_wqe_convert(struct trs_async_dma_input_para *input, uint8_t *wqe_buffer,
                                         uint64_t wqe_bufferLen, struct halAsyncDmaWqeOutputPara *out)
{
    struct trs_urma_dwqe_fill_para fill_para = {0};
    uint32_t credit = (uint32_t)(wqe_bufferLen / TRS_URMA_DWQE_LEN);
    uint32_t i = 0;

    if (input->async_nop_in.nopCnt <= credit) {
        out->wqeCnt = (unsigned int)(input->async_nop_in.nopCnt);
    } else {
        out->wqeCnt = credit;
    }

    out->fixedSize = 0;
    out->fixedCnt = out->wqeCnt;

    fill_para.sqe_bb_idx = 1;
    fill_para.op_code = TRS_URMA_OPCODE_NOP;
    fill_para.rmt_eid = NULL;
    for (i = 0; i < out->wqeCnt; i++) {
        fill_para.cqe_report = (i == (out->wqeCnt - 1)) ? 1 : 0;
        _trs_fill_async_dma_direct_wqe(&fill_para, wqe_buffer + i * STARS_ASYNC_DMA_WQE_SIZE);
    }

    return 0;
}

static int _trs_async_dma_copy_wqe_convert(struct trs_async_devid *async_devid, uint32_t dir,
                                           struct trs_async_addr_pack *addr_pack, uint8_t *wqe_buffer,
                                           bool is_last_batch)
{
    struct trs_urma_dwqe_fill_para fill_para = {0};
    uint32_t devid = async_devid->local_devid;
    uint64_t send_addr, recv_addr;
    uint32_t wqe_num;
    uint32_t i = 0;
    int ret = 0;

    trs_get_async_send_recv_addr(async_devid, addr_pack->src, addr_pack->dst, &send_addr, &recv_addr);

    fill_para.op_code = trs_get_async_dwqe_opcode(devid, async_devid, dir);
    fill_para.sqe_bb_idx = 1; /* in acl graph mode, sqe_bb_idx not used */

    if (dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        struct trs_d2d_dev_ctx *d2d_dev_ctx = NULL;
        trs_dev_ctx_mutex_lock(async_devid->remote_devid);
        d2d_dev_ctx = trs_get_d2d_dev_ctx(async_devid->remote_devid);
        if (d2d_dev_ctx == NULL) {
            trs_dev_ctx_mutex_un_lock(async_devid->remote_devid);
            return DRV_ERROR_UNINIT;
        }

        fill_para.tpn = d2d_dev_ctx->tpn[devid];
        fill_para.rmt_eid = &(d2d_dev_ctx->dst_jfr_id.eid);
        trs_dev_ctx_mutex_un_lock(async_devid->remote_devid);
    } else {
        struct trs_urma_proc_ctx *urma_proc_ctx = trs_get_urma_proc_ctx(devid);
        fill_para.tpn = urma_proc_ctx->tpn;
        fill_para.rmt_eid = &(urma_proc_ctx->urma_ctx->eid);
    }

    ret = halMemGetSeg(devid, recv_addr, addr_pack->len, &fill_para.seg, &fill_para.token);
    if (ret != 0) {
        trs_err("Get token_id from svm failed. (devid=%u; va=0x%llx; len=0x%llx; ret=%d)\n", devid, recv_addr,
                addr_pack->len, ret);
        return ret;
    }

    wqe_num = (uint32_t)(align_up(addr_pack->len, TRS_URMA_WR_CPY_MAX_SIZE) / TRS_URMA_WR_CPY_MAX_SIZE);
    for (i = 0; i < wqe_num; i++) {
        fill_para.send_addr = send_addr + i * TRS_URMA_WR_CPY_MAX_SIZE;
        fill_para.recv_addr = recv_addr + i * TRS_URMA_WR_CPY_MAX_SIZE;
        fill_para.len = (i == (wqe_num - 1)) ? (addr_pack->len - i * TRS_URMA_WR_CPY_MAX_SIZE) :
                                               TRS_URMA_WR_CPY_MAX_SIZE;
        fill_para.cqe_report = ((i == (wqe_num - 1)) && is_last_batch) ? 1 : 0;
        _trs_fill_async_dma_direct_wqe(&fill_para, wqe_buffer + i * STARS_ASYNC_DMA_WQE_SIZE);
    }

    return 0;
}

static inline bool trs_is_async_wqe_convert_complete(struct trs_async_dma_input_para *input, uint64_t fixedVal)
{
    switch (input->async_dma_type) {
        case TRS_ASYNC_DMA_TYPE_NORMAL:
            return (fixedVal == input->async_normal_in.len);
        case TRS_ASYNC_DMA_TYPE_2D:
            return (fixedVal == (input->async_2d_in.width * input->async_2d_in.height));
        case TRS_ASYNC_DMA_TYPE_NOP:
            return (fixedVal == input->async_nop_in.nopCnt);
        default:
            return false;
    }
}

static int trs_async_dma_copy_wqe_convert(struct trs_async_devid *async_devid, struct trs_async_dma_input_para *input,
                                          uint8_t *wqe_buffer, uint64_t wqe_bufferLen,
                                          struct halAsyncDmaWqeOutputPara *out)
{
    unsigned long long *src_array, *dst_array, *src_len_array, *dst_len_array;
    uint8_t *dst_wqe_addr = wqe_buffer;
    uint32_t wr_num = 0, credit = 0, batch_num = 0, start_index = 0;
    uint64_t fixedVal = 0, partial_fixed_size = 0;
    uint32_t i;
    int ret = 0;

    credit = (uint32_t)(wqe_bufferLen / TRS_URMA_DWQE_LEN);
    trs_get_async_post_wr_num(input, credit, true, &wr_num, &fixedVal, &partial_fixed_size);
    if (credit < wr_num) {
        trs_err("Credit not enough. (credit=%u; wr_num=%u; wqe_bufferLen=0x%llx)\n", credit, wr_num, wqe_bufferLen);
        return DRV_ERROR_NO_RESOURCES;
    }

    trs_get_async_input_src_dst_len_array(input, &src_array, &dst_array, &src_len_array, &dst_len_array);
    start_index = (uint32_t)((input->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) ?
                                 (input->async_2d_in.fixedSize / input->async_2d_in.width) :
                                 0);

    trs_get_async_batch_num(input, fixedVal, partial_fixed_size, &batch_num);
    for (i = 0; i < batch_num; i++) {
        struct trs_async_addr_pack addr_pack = {0};
        uint32_t absolute_index = i + start_index;

        if (input->async_dma_type == TRS_ASYNC_DMA_TYPE_2D) {
            uint64_t row_start = (i == 0) ? (input->async_2d_in.fixedSize % input->async_2d_in.width) : 0;
            uint64_t row_end = ((i == (batch_num - 1)) && (fixedVal % input->async_2d_in.width != 0)) ?
                                   (fixedVal % input->async_2d_in.width) :
                                   input->async_2d_in.width;
            addr_pack.src = src_array[0] + absolute_index * input->async_2d_in.spitch + row_start;
            addr_pack.dst = dst_array[0] + absolute_index * input->async_2d_in.dpitch + row_start;
            addr_pack.len = row_end - row_start;
        } else {
            addr_pack.src = src_array[absolute_index];
            addr_pack.dst = dst_array[absolute_index];
            addr_pack.len = (input->async_dma_type == TRS_ASYNC_DMA_TYPE_NORMAL) ? fixedVal :           /* normal */
                                ((i == fixedVal) ? partial_fixed_size : src_len_array[absolute_index]); /* batch */
        }

        ret = _trs_async_dma_copy_wqe_convert(async_devid, input->dir, &addr_pack, dst_wqe_addr,
                                              (i == (batch_num - 1)));
        if (ret != 0) {
            return ret;
        }

        dst_wqe_addr += (align_up(addr_pack.len, TRS_URMA_WR_CPY_MAX_SIZE) / TRS_URMA_WR_CPY_MAX_SIZE) *
                        STARS_ASYNC_DMA_WQE_SIZE;
    }

    out->wqeCnt = wr_num;
    if (input->async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH) {
        out->fixedCnt = fixedVal;
        out->fixedSize = partial_fixed_size;
    } else {
        out->fixedCnt = trs_is_async_wqe_convert_complete(input, fixedVal) ? 1 : 0;
        out->fixedSize = (out->fixedCnt == 1) ? 0 : fixedVal;
    }

    return 0;
}

drvError_t trs_async_dma_wqe_convert(uint32_t dev_id, struct halAsyncDmaWqeInputPara *in,
                                     struct halAsyncDmaWqeOutputPara *out)
{
    struct trs_async_dma_input_para input = {0};
    struct trs_async_devid async_devid = {0};
    int ret = 0;

    input.async_dma_type = (enum trs_async_dma_type)in->wqeType;
    if (input.async_dma_type == TRS_ASYNC_DMA_TYPE_NORMAL) {
        input.async_normal_in = in->normal;
    } else if (input.async_dma_type == TRS_ASYNC_DMA_TYPE_2D) {
        input.async_2d_in = in->matrix2d;
    } else if (input.async_dma_type == TRS_ASYNC_DMA_TYPE_BATCH) {
        input.async_batch_in = in->batch;
    } else if (input.async_dma_type == TRS_ASYNC_DMA_TYPE_NOP) {
        input.async_nop_in = in->nop;
    }

    if (input.async_dma_type == TRS_ASYNC_DMA_TYPE_NOP) {
        return trs_async_dma_nop_wqe_convert(&input, in->wqeBuffer, in->wqeBufferLen, out);
    }

    ret = trs_get_check_async_devid_dir(dev_id, &input, &async_devid, &input.dir);
    if (ret != 0) {
        return ret;
    }

    if (input.dir == TRS_ASYNC_DEVICE_TO_DEVICE) {
        ret = trs_d2d_dev_ctx_check_init(&async_devid, 0);
        if (ret != 0) {
            return ret;
        }
    }

    return trs_async_dma_copy_wqe_convert(&async_devid, &input, in->wqeBuffer, in->wqeBufferLen, out);
}

drvError_t trs_async_dma_jetty_fill(uint32_t dev_id, struct halAsyncDmaJettyFillInfo *para)
{
    struct trs_async_jetty_node *jetty_node = NULL;
    drvError_t ret = 0;

    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        return DRV_ERROR_UNINIT;
    }

    (void)pthread_rwlock_rdlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

    jetty_node = hash_table_get(g_jetty_mng_ctx[dev_id].hash_table, para->jettyHandle->handle);
    if (jetty_node == NULL) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to find jetty node. (dev_id=%u; handle=%s)\n", dev_id, para->jettyHandle->handle);
        return DRV_ERROR_UNINIT;
    }

    if ((para->offset + para->size) > jetty_node->jetty_info.jetty_queue_len) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to fill jetty queue. (dev_id=%u; offset=0x%llx; size=0x%llx; len=0x%x; ret=%d)\n", dev_id,
                para->offset, para->size, jetty_node->jetty_info.jetty_queue_len, ret);
        return DRV_ERROR_PARA_ERROR;
    }

    ret = halSvmAccess(dev_id, jetty_node->jetty_info.jetty_queue_base + para->offset,
                       (uint64_t)(uintptr_t)para->srcWqe, para->size, SVM_MEM_ACCESS_WRITE);
    if (ret != DRV_ERROR_NONE) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to fill jetty queue. (dev_id=%u; addr=0x%llx; offset=0x%llx; src=%px; len=0x%llx; ret=%d)\n",
                dev_id, jetty_node->jetty_info.jetty_queue_base, para->offset, para->srcWqe, para->size, ret);
        return ret;
    }

    (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
    return 0;
}

int trs_async_urma_init(uint32_t dev_id)
{
    int ret;

    if (g_jetty_mng_ctx[dev_id].hash_table != NULL) {
        return DRV_ERROR_REPEATED_INIT;
    }

    ret = pthread_rwlock_init(&g_jetty_mng_ctx[dev_id].rw_mutex, NULL);
    if (ret != 0) {
        trs_err("Failed to init jetty mng rwlock. (dev_id=%u; ret=%d)\n", dev_id, ret);
        return DRV_ERROR_INNER_ERR;
    }

    g_jetty_mng_ctx[dev_id].hash_table = hash_table_new();
    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        (void)pthread_rwlock_destroy(&g_jetty_mng_ctx[dev_id].rw_mutex);
        return DRV_ERROR_INNER_ERR;
    }

    g_jetty_mng_ctx[dev_id].node_num = 0;
    return 0;
}

void trs_async_urma_uninit(uint32_t dev_id)
{
    struct trs_async_jetty_node **node_buff = NULL;
    uint32_t node_num;
    uint32_t i;

    if (g_jetty_mng_ctx[dev_id].hash_table == NULL) {
        return;
    }

    (void)pthread_rwlock_wrlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
    node_num = g_jetty_mng_ctx[dev_id].node_num;
    if (node_num == 0) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        goto out;
    }

    node_buff = (struct trs_async_jetty_node **)malloc(sizeof(void *) * node_num);
    if (node_buff == NULL) {
        (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);
        trs_err("Failed to alloc node buffer. (dev_id=%u; node_num=%u)\n", dev_id, node_num);
        goto out;
    }

    node_num = get_hash_table_value(g_jetty_mng_ctx[dev_id].hash_table, (void **)node_buff, (unsigned short)node_num);
    for (i = 0; i < node_num; i++) {
        struct trs_async_jetty_node *jetty_node = node_buff[i];
        trs_unregister_reg(dev_id, jetty_node->jetty_info.jetty_queue_base, jetty_node->jetty_info.jetty_queue_len);
        (void)trs_async_dma_jetty_remote_free(dev_id, jetty_node->jetty_info.slave_jetty_addr);
        jetty_node->is_free_implicitly = true;
        hash_table_rm(g_jetty_mng_ctx[dev_id].hash_table, jetty_node->jettyHandle.handle);
    }

    g_jetty_mng_ctx[dev_id].node_num = 0;
    free(node_buff);
    (void)pthread_rwlock_unlock(&g_jetty_mng_ctx[dev_id].rw_mutex);

out:
    hash_table_delete(g_jetty_mng_ctx[dev_id].hash_table);
    g_jetty_mng_ctx[dev_id].hash_table = NULL;
    (void)pthread_rwlock_destroy(&g_jetty_mng_ctx[dev_id].rw_mutex);
}
