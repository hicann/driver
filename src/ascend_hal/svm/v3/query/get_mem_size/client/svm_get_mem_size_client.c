/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "ascend_hal.h"

#include "pbl_user_interface.h"
#include "pbl_urd_main_cmd_def.h"
#include "pbl_urd_sub_cmd_common.h"

#include "svm_pub.h"
#include "svm_log.h"

int svm_get_mem_size_info(u32 devid, u32 type, struct MemPhyInfo *phy_info)
{
    struct urd_dev_mem_type mem_type = {
        .dev_id = devid,
        .type = type};
    struct urd_cmd_para cmd_para = {
        .input = (void *)&mem_type,
        .input_len = sizeof(mem_type),
        .output = (void *)phy_info,
        .output_len = sizeof(*phy_info)};
    struct urd_cmd cmd = {
        .main_cmd = DMS_MAIN_CMD_MEMORY,
        .sub_cmd = DMS_SUBCMD_DEV_MEM_INFO,
        .filter = NULL,
        .filter_len = 0};
    int ret;

    ret = urd_dev_usr_cmd(devid, &cmd, &cmd_para);
    if (ret != DRV_ERROR_NONE) {
        svm_err("Get mem size info failed. (devid=%u; type=%u; ret=%d)\n", devid, type, ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}
