/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef QUE_PLATFORM_UB_H
#define QUE_PLATFORM_UB_H

#include "que_platform_common.h"

#ifndef EMU_ST
#include "urma_api.h"
#endif

/* Forward declarations for UBE related structures */
struct que_urma_ctx;
struct que_urma_token;
struct dms_ub_dev_info;

/* ============================================================================
 * Platform-specific queue interfaces - from que_host_ub_adapt.c / que_device_ub_adapt.c
 * UBE related functions
 * ============================================================================ */

/* From que_ini_proc.c - UBE related */
QUE_MEM_TYPE que_get_buff_memtype_platform(struct buff_iovec *vector);

/* From que_urma.c - UBE related */
int que_get_trans_num_platform(void);

#ifndef EMU_ST
int que_get_ub_d2d_dev_info_platform(unsigned int dev_id, struct dms_ub_dev_info *dev_info, int ret);
int que_register_share_urma_seg(struct que_urma_ctx *urma_ctx, int trans_idx);
void que_unregister_share_urma_seg(urma_target_seg_t *tseg);
#endif

/* From que_comm_ctx.c - UBE related */
int que_ub_ctx_res_init_d2d_platform(struct que_ctx *ctx, int res_type, que_ub_res_alloc *res_alloc,
                                     que_ub_res_free *res_free);
void que_ub_ctx_res_uninit_d2d_platform(struct que_ctx *ctx, int res_type, que_ub_res_free *res_free);

/* From que_comm_event.c */
unsigned int que_comm_event_get_dst_engine_platform(uint32_t remote_devid);
void que_get_sched_event_type_platform(uint32_t devid, int32_t *event_type);
unsigned int que_get_sched_engine_type_platform(uint32_t devid);
int que_inter_dev_get_remote_pid_platform(unsigned int remote_devid, pid_t *remote_pid);

/* From que_comm_agent.c */
bool que_is_share_mem_platform(unsigned long long addr);
unsigned int que_get_chan_devid_platform(unsigned int devid);

/* From queue_tgt_proc.c */
int que_rx_pkt_bare_proc_platform(struct que_tgt_proc *tgt_proc, struct que_pkt *pkt);

#endif /* QUE_PLATFORM_UB_H */
