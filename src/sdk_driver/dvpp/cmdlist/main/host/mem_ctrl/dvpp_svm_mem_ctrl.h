
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

#ifndef DVPP_SVM_MEM_CTRL_H
#define DVPP_SVM_MEM_CTRL_H

#include "ka_type.h"
#include "ka_task_pub.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint64_t *pa_list;
    uint64_t *size_list;
    uint64_t num;
    uint64_t page_size;
} dvpp_svm_pa_info; // 如果结构体变大，需修改DVPP_DEFAULT_MEM_BLK_SIZE

uint64_t dvpp_get_page_size(ka_pid_t pid, uint64_t addr, uint64_t size);
uint64_t dvpp_get_pa_num(uint64_t addr, uint64_t size, uint64_t page_size);
int32_t dvpp_get_pa_list_from_svm_addr(ka_pid_t pid, uint64_t addr, uint64_t size, dvpp_svm_pa_info *pa_info);
void dvpp_put_pa_list(ka_pid_t pid, uint64_t addr, uint64_t size, dvpp_svm_pa_info *pa_info);

#ifdef __cplusplus
}
#endif
#endif  // #ifndef DVPP_SVM_MEM_CTRL_H