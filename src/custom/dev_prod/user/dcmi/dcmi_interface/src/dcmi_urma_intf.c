/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdbool.h>
#include <errno.h>
#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_log.h"

int dcmi_get_eid_list_by_urma_dev_index(int card_id, int device_id, unsigned int dev_index,
    dcmi_urma_eid_info_t *eid_list, unsigned int *eid_cnt)
{
    gplog(LOG_OP, "This device does not support get urma eid list.");
    return DCMI_ERR_CODE_NOT_SUPPORT;
}

int dcmi_get_urma_device_cnt(int card_id, int device_id, unsigned int *dev_cnt)
{
    gplog(LOG_OP, "This device does not support get urma device cnt.");
    return DCMI_ERR_CODE_NOT_SUPPORT;
}