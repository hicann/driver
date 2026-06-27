/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "bbox_feature.h"
#include "bbox_print.h"
#include "pbl_user_interface.h"
#include "pbl_urd_main_cmd_def.h"
#include "pbl_urd_sub_cmd_common.h"

#ifndef ASCEND_DEV_MAX_NUM
#define ASCEND_DEV_MAX_NUM 1140
#endif
static unsigned long long g_bbox_feature_bitmap[ASCEND_DEV_MAX_NUM] = {0};

drvError_t bbox_feature_init(void)
{
    struct urd_cmd_para cmd_para = {0};
    struct urd_cmd cmd = {0};
    int ret;

    /* Batch query: no input, output is the full bitmap array for all devices */
    urd_usr_cmd_fill(&cmd, DMS_MAIN_CMD_BBOX, DMS_SUBCMD_GET_BBOX_FEATURE, NULL, 0);
    urd_usr_cmd_para_fill(&cmd_para, NULL, 0,
                          (void *)g_bbox_feature_bitmap,
                          sizeof(unsigned long long) * ASCEND_DEV_MAX_NUM);

    ret = urd_dev_usr_cmd(0, &cmd, &cmd_para);
    if (ret != 0) {
        BBOX_ERR("Failed to init bbox feature bitmap (ret=%d)", ret);
        return (drvError_t)ret;
    }
    return DRV_ERROR_NONE;
}

bool bbox_has_feature(unsigned int dev_id, enum bbox_feature_id feature)
{
    if (dev_id >= ASCEND_DEV_MAX_NUM) {
        return false;
    }

    if ((unsigned int)feature >= BBOX_FEATURE_MAX) {
        return false;
    }
    return (g_bbox_feature_bitmap[dev_id] & (1ULL << (unsigned int)feature)) != 0;
}
