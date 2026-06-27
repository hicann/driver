/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef _HNS_ROCE_HAL_H_
#define _HNS_ROCE_HAL_H_

#include <sys/ioctl.h>

#define HNS_ROCE_AI_CMD_IOCTL_TYPE  'A'
#define RESV_MEM_MMAP_PGOFF (5120 << 12)
#define PAGE_SIZE_4KB 4096

enum {
    HNS_ROCE_RESV_MEM_POPULATE      = 0xD,
    HNS_ROCE_RESV_MEM_DEPOPULATE    = 0xE,
};

#define HNS_ROCE_AI_RESV_MEM_POPULATE \
	_IOWR(HNS_ROCE_AI_CMD_IOCTL_TYPE, HNS_ROCE_RESV_MEM_POPULATE, struct resv_mem_populate_cmd_data)
#define HNS_ROCE_AI_RESV_MEM_DEPOPULATE \
	_IOWR(HNS_ROCE_AI_CMD_IOCTL_TYPE, HNS_ROCE_RESV_MEM_DEPOPULATE, struct resv_mem_depopulate_cmd_data)

struct resv_mem_populate_cmd_data {
	unsigned int pool_id;
	unsigned long long addr;
	unsigned long long len;
	unsigned long long mmap_va;
	unsigned long long mmap_len;
};

struct resv_mem_depopulate_cmd_data {
	unsigned int pool_id;
	unsigned long long addr;
	unsigned long long mmap_va;
	unsigned long long mmap_len;
};

int hns_roce_hal_alloc_buf(void **buf, unsigned int *length, unsigned int size, unsigned int page_size,
    unsigned int dev_id);
int hns_roce_hal_get_dev_id(unsigned int chip_id, unsigned int die_id, unsigned int *dev_id);
int hns_roce_hal_alloc_ai_buf(void **buf, unsigned int *length, unsigned int size, unsigned int page_size,
    unsigned int dev_id, unsigned int grp_id);
int hns_roce_hal_free_ai_buf(void *buf);
int hns_roce_hal_alloc_resv_mem(int cmd_fd, unsigned int size, unsigned int page_size, 
    unsigned int pool_id, void **buf, unsigned int *length);
int hns_roce_hal_free_resv_mem(int cmd_fd, void *buf, unsigned int pool_id);
#endif // _HNS_ROCE_HAL_H_
