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
#include "dcmi_basic_info_intf.h"

int dcmiv2_get_eid_list_by_urma_dev_index(int dev_id, unsigned int dev_index,
    dcmi_urma_eid_info_t *eid_list, unsigned int *eid_cnt)
{
    int ret, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if ((eid_list == NULL) || (eid_cnt == NULL) || (dev_index >= DCMI_URMA_EID_MAX_COUNT)
        || ((*eid_cnt) > DCMI_URMA_EID_MAX_COUNT)) {
        gplog(LOG_ERR, "Input param is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support get urma eid list.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", ret);
        return ret;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. ret is %d.", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_eid_list_by_urma_dev_index(card_id, device_id, dev_index, eid_list, eid_cnt);
    } else {
        gplog(LOG_ERR, "The device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_urma_device_cnt(int dev_id, unsigned int *dev_cnt)
{
    int ret, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (dev_cnt == NULL) {
        gplog(LOG_ERR, "Input param is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support get urma device cnt.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", ret);
        return ret;
    }
    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. ret is %d.", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_urma_device_cnt(card_id, device_id, dev_cnt);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}