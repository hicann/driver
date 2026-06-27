/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <unistd.h>
#include "que_comm_agent.h"
#include "que_comm_ctx.h"
#include "que_comm_thread.h"
#include "que_comm_chan.h"
#include "que_jetty.h"
#include "que_urma.h"
#include "que_uma.h"
#include "que_ub_msg.h"
#include "que_ini_proc.h"
#include "que_tgt_proc.h"
#include "queue_agent.h"
#include "dms_user_interface.h"
#include "que_platform_ub.h"

#ifndef EMU_ST
#include "urma_api.h"
#endif

/* ============================================================================
 * que_ini_proc.c - Host specific UBE implementations
 * ============================================================================ */
QUE_MEM_TYPE que_get_buff_memtype_platform(struct buff_iovec *vector)
{
    struct DVattribute attr;
    drvError_t ret;
    DVdeviceptr vptr = (DVdeviceptr)(uintptr_t)vector->ptr[0].iovec_base;
    ret = drvMemGetAttribute(vptr, &attr);
    if (ret != DRV_ERROR_NONE) {
        return MEM_NOT_SVM;
    } else {
        if (attr.memType == DV_MEM_LOCK_DEV) {
            return MEM_DEVICE_SVM;
        } else if (attr.memType == DV_MEM_USER_MALLOC) {
            return MEM_NOT_SVM;
        } else {
            return MEM_OTHERS_SVM;
        }
    }
}

/* ============================================================================
 * que_urma.c - Host specific UBE implementations
 * ============================================================================ */
int que_get_trans_num_platform(void)
{
    return TRANS_HOST_MAX;
}

#ifndef EMU_ST

int que_get_ub_d2d_dev_info_platform(unsigned int dev_id, struct dms_ub_dev_info *dev_info, int ret)
{
    (void)dev_id;
    (void)dev_info;
    (void)ret;
    return DRV_ERROR_NONE;
}

int que_register_share_urma_seg(struct que_urma_ctx *urma_ctx, int trans_idx)
{
    (void)urma_ctx;
    (void)trans_idx;
    return DRV_ERROR_NONE;
}

void que_unregister_share_urma_seg(urma_target_seg_t *tseg)
{
    (void)tseg;
}
#endif

/* ============================================================================
 * que_tgt_proc.c - Host specific UBE implementations
 * ============================================================================ */
/* Device only functions - stub implementations for Host */
int que_rx_pkt_bare_proc_platform(struct que_tgt_proc *tgt_proc, struct que_pkt *pkt)
{
    (void)tgt_proc;
    (void)pkt;
    return DRV_ERROR_NOT_SUPPORT;
}

/* ============================================================================
 * que_comm_ctx.c - Host specific UBE implementations
 * ============================================================================ */
/* Host has no D2D resource init/uninit */
int que_ub_ctx_res_init_d2d_platform(struct que_ctx *ctx, int res_type, que_ub_res_alloc *res_alloc,
                                     que_ub_res_free *res_free)
{
    (void)ctx;
    (void)res_type;
    (void)res_alloc;
    (void)res_free;
    return DRV_ERROR_NONE;
}

void que_ub_ctx_res_uninit_d2d_platform(struct que_ctx *ctx, int res_type, que_ub_res_free *res_free)
{
    (void)ctx;
    (void)res_type;
    (void)res_free;
}

/* ============================================================================
 * que_comm_event.c - Host specific implementations
 * ============================================================================ */
unsigned int que_comm_event_get_dst_engine_platform(uint32_t remote_devid)
{
    (void)remote_devid;
    return CCPU_DEVICE;
}

void que_get_sched_event_type_platform(uint32_t devid, int32_t *event_type)
{
    (void)devid;
    *event_type = QUEUE_EVENT;
}

unsigned int que_get_sched_engine_type_platform(uint32_t devid)
{
    (void)devid;
    return CCPU_HOST;
}

int que_inter_dev_get_remote_pid_platform(unsigned int remote_devid, pid_t *remote_pid)
{
    int ret;
    struct halQueryDevpidInfo info;
    pid_t local_pid;

    ret = drvQueryProcessHostPid(getpid(), NULL, NULL, (unsigned int *)(uintptr_t)&local_pid, NULL);
    if (ret != DRV_ERROR_NONE) {
        local_pid = getpid();
    }

    info.proc_type = DEVDRV_PROCESS_CP1;
    info.hostpid = local_pid;
    info.devid = remote_devid;
    info.vfid = 0;
    ret = halQueryDevpid(info, remote_pid);
    if (que_unlikely(ret != DRV_ERROR_NONE)) {
        QUEUE_LOG_ERR("query remote pid failed. (ret=%d; remote devid=%u; local pid=%d)\n", ret, remote_devid,
                      local_pid);
    }
    return ret;
}

/* ============================================================================
 * que_comm_agent.c - Host specific implementations
 * ============================================================================ */
bool que_is_share_mem_platform(unsigned long long addr)
{
    (void)addr;
    return false;
}

unsigned int que_get_chan_devid_platform(unsigned int devid)
{
    (void)devid;
    return halGetHostDevid();
}
