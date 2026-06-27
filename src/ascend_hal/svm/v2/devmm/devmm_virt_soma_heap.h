/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef SVM_SOMA_HEAP_H
#define SVM_SOMA_HEAP_H
#include <sys/types.h>
#include <unistd.h>
#include "devmm_virt_interface.h"

DVresult devmm_virt_init_soma_heap(struct devmm_virt_heap_mgmt *mgmt);

#endif /* _SVM_BASE_HEAP_H_ */