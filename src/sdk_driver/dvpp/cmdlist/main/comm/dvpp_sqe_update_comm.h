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

#ifndef DVPP_SQE_UPDATE_COMM_H
#define DVPP_SQE_UPDATE_COMM_H

#include "ka_type.h"
#include "ka_task_pub.h"
#include "dvpp_cmdlist.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ka_pid_t pid;
    uint32_t devid;
    uint32_t pf_id;
    uint32_t vf_id;
} dvpp_comm_para;

typedef struct {
    uint64_t cmdbuf_uva;
    uint64_t cmdbuf_kva;
    uint64_t cmdbuf_size;
    uint64_t args_uva;
    uint64_t args_kva;
    uint64_t args_size;
    uint32_t chn_id;
    uint8_t is_use_mem_pool;
    uint8_t is_cmdbuf_pool;
} dvpp_save_para;

int32_t dvpp_comm_drv_ready(dvpp_sqe_args *sqe_args, uint64_t tlv_stru_addr, uint64_t* cmdbuf_size_used);
uint64_t alloc_args_mem(uint32_t pool_id, uint64_t size, dvpp_sqe_args *sqe_args);
int32_t copy_args_from_user(dvpp_save_para *save_para, dvpp_sqe_args *sqe_args);
uint64_t get_alloc_size(dvpp_sqe_args *sqe_args, uint64_t dma_info_size);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_SQE_UPDATE_COMM_H