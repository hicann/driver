/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "ascend_hal.h"
#include "devmm_virt_com_heap.h"
#include "devmm_virt_comm.h"
#include "devmm_virt_interface.h"
#include "devmm_svm_init.h"
#include "devmm_virt_host_pin_heap.h"

static void devmm_fill_host_pin_heap_info(struct devmm_virt_heap_mgmt *mgmt,
    struct devmm_virt_heap_type *heap_type, uint32_t device, struct devmm_virt_heap_para *heap_info)
{
    (void)mgmt;
    (void)heap_type;
    (void)device;
    heap_info->start = DEVMM_HOST_PIN_START;
    heap_info->heap_size = DEVMM_HOST_PIN_SIZE;
    heap_info->kernel_page_size = DEVMM_2M_PAGE_SIZE;
    heap_info->map_size = DEVMM_2M_PAGE_SIZE;
    heap_info->is_limited = true;
    heap_info->is_base_heap = false;
}

void devmm_fill_host_pin_heap_type(uint32_t heap_sub_type, struct devmm_virt_heap_type *heap_type)
{
    /* host pin just has one heap, arrangement attribute hbm mem_type/huge heap type */
    heap_type->heap_type = DEVMM_HEAP_PINNED_HOST;
    heap_type->heap_list_type = HOST_LIST;
    heap_type->heap_sub_type = heap_sub_type;
    heap_type->heap_mem_type = DEVMM_DDR_MEM;
}

DVresult devmm_init_host_pin_heap_by_devid(uint32_t device, uint32_t heap_sub_type)
{
    struct devmm_virt_heap_type heap_type = {0};
    struct devmm_virt_heap_para heap_info = {0};
    struct devmm_virt_heap_mgmt *mgmt = NULL;

    (void)heap_sub_type;
    mgmt = (struct devmm_virt_heap_mgmt *)devmm_virt_get_heap_mgmt();
    if (mgmt == NULL) {
        DEVMM_DRV_ERR("Get heap management error.\n");
        return DRV_ERROR_INVALID_HANDLE;
    }

    devmm_fill_host_pin_heap_type(SUB_HOST_TYPE, &heap_type);
    devmm_fill_host_pin_heap_info(mgmt, &heap_type, device, &heap_info);
    return DRV_ERROR_NONE;
}

