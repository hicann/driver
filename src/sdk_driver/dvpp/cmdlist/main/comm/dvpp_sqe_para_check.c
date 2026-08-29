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

#include "dvpp_sqe_para_check.h"
#include "dvpp_cmdlist.h"
#include "dvpp_cmdlist_log.h"

int32_t check_dvpp_sqe_args(dvpp_sqe_args *sqe_args)
{
    if ((sqe_args->cmdbuf_uva == 0) || (sqe_args->cmdbuf_size == 0) || (sqe_args->args_size == 0) ||
        (sqe_args->args_addr == 0)) {
        DVPP_CMDLIST_LOG_ERROR("para in sqe is illegal, address of cmdbuf or args may be null. cmdbuf_size:%u,"
                               " args_size:%u\n",
                               sqe_args->cmdbuf_size, sqe_args->args_size);
        return -1;
    }

    if (sqe_args->cmdbuf_size <= SQE_LIST_LEN) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf size %u must be greater than %d.\n", sqe_args->cmdbuf_size, SQE_LIST_LEN);
        return -1;
    }

    if ((sqe_args->cmdbuf_size > MEM_SIZE_4M) || (sqe_args->args_size > MEM_SIZE_4M)) {
        DVPP_CMDLIST_LOG_ERROR("memory size can not exceed %u."
                               "cmdbuf_size:%u, args_size:%u\n",
                               MEM_SIZE_4M, sqe_args->cmdbuf_size, sqe_args->args_size);
        return -1;
    }

    if (sqe_args->tlv_node_num > DVPP_MAX_NODE_NUM) {
        DVPP_CMDLIST_LOG_ERROR("tlv_node_num %u should not be bigger than %u.\n", sqe_args->tlv_node_num,
                               DVPP_MAX_NODE_NUM);
        return -1;
    }

#ifdef BUILD_DEBUG
    DVPP_CMDLIST_LOG_DEBUG("cmdbuf_uva:%pK, cmdbuf_size:%u, args_uva:%pK, args_size:%u", (void *)(sqe_args->cmdbuf_uva),
                           sqe_args->cmdbuf_size, (void *)(sqe_args->args_addr), sqe_args->args_size);
#endif

    return 0;
}