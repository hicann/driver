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
#ifndef SVM_MASTER_SOMA_POOL_MNG_H
#define SVM_MASTER_SOMA_POOL_MNG_H

#include "svm_ioctl.h"
#include "devmm_proc_info.h"

int devmm_ioctl_soma_create_pool(struct devmm_svm_process *svm_proc, struct devmm_ioctl_arg *args);
int devmm_ioctl_soma_destroy_pool(struct devmm_svm_process *svm_proc, struct devmm_ioctl_arg *args);
int devmm_ioctl_soma_trim_pool(struct devmm_svm_process *svm_proc, struct devmm_ioctl_arg *args);

#endif /* SVM_MASTER_SOMA_POOL_MNG_H */