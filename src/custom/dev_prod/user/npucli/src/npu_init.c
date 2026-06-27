/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "npu_smi.h"
#include "dcmi_interface_api.h"
#include "dcmi_os_adapter.h"
#include "dcmi_log.h"
#include "npu_error_code.h"

int g_ascend_chip_count = 0;
#ifdef NPU_SMI_V2
int npu_init_total_ascend_chip_count(void)
{
    int card_count = 0;
    int card_id_list[MAX_CARD_NUM] = {0};
    int ret;

    /* Atlas 500 存在不带Asccend 310发货场景 */
    if (access("/run/minid_not_present", F_OK) == 0) {
        g_ascend_chip_count = 0;
        return NPU_OK;
    }

    ret = dcmiv2_get_device_list(card_id_list, &card_count, MAX_CARD_NUM);
        if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_list failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    g_ascend_chip_count = card_count;

    return NPU_OK;
}
#else
int npu_init_total_ascend_chip_count(void)
{
    int card_count = 0;
    int card_id_list[MAX_CARD_NUM] = {0};
    int ret;
    int card_index;
    int device_count;
    int mcu_id = NPU_DEFAULT_VALUE;
    int cpu_id = NPU_DEFAULT_VALUE;

    /* Atlas 500 存在不带Asccend 310发货场景 */
    if (access("/run/minid_not_present", F_OK) == 0) {
        g_ascend_chip_count = 0;
        return NPU_OK;
    }

    ret = dcmi_get_card_list(&card_count, card_id_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_list failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    for (card_index = 0; card_index < card_count; card_index++) {
        ret = dcmi_get_device_id_in_card(card_id_list[card_index], &device_count, &mcu_id, &cpu_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_id_in_card card %d failed. err is %d", card_id_list[card_index], ret);
            continue;
        }
        g_ascend_chip_count += device_count;
    }
    (void)mcu_id;
    (void)cpu_id;

    return NPU_OK;
}
#endif
int npu_get_total_ascend_chip_count(void)
{
    return g_ascend_chip_count;
}