/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stddef.h>
#include "dcmi_interface_api.h"
#include "npu_smi.h"
#include "npu_error_code.h"

static struct err_code_map g_npu_err_code_map[] = {
    {DCMI_OK, NPU_OK},
    {DCMI_ERROR_CODE_BASE, NPU_ERR_CODE_BASE},
    {DCMI_ERR_CODE_INVALID_PARAMETER, NPU_ERR_CODE_INVALID_PARAMETER},
    {DCMI_ERR_CODE_OPER_NOT_PERMITTED, NPU_ERR_CODE_OPER_NOT_PERMITTED},
    {DCMI_ERR_CODE_MEM_OPERATE_FAIL, NPU_ERR_CODE_MEM_OPERATE_FAIL},
    {DCMI_ERR_CODE_SECURE_FUN_FAIL, NPU_ERR_CODE_SECURE_FUN_FAIL},
    {DCMI_ERR_CODE_INNER_ERR, NPU_ERR_CODE_INNER_ERR},
    {DCMI_ERR_CODE_TIME_OUT, NPU_ERR_CODE_TIME_OUT},
    {DCMI_ERR_CODE_INVALID_DEVICE_ID, NPU_ERR_CODE_INVALID_DEVICE_ID},
    {DCMI_ERR_CODE_DEVICE_NOT_EXIST, NPU_ERR_CODE_DEVICE_NOT_EXIST},
    {DCMI_ERR_CODE_IOCTL_FAIL, NPU_ERR_CODE_IOCTL_FAIL},
    {DCMI_ERR_CODE_SEND_MSG_FAIL, NPU_ERR_CODE_SEND_MSG_FAIL},
    {DCMI_ERR_CODE_RECV_MSG_FAIL, NPU_ERR_CODE_RECV_MSG_FAIL},
    {DCMI_ERR_CODE_NOT_REDAY, NPU_ERR_CODE_NOT_REDAY},
    {DCMI_ERR_CODE_NOT_SUPPORT_IN_CONTAINER, NPU_ERR_CODE_NOT_SUPPORT_IN_CONTAINER},
    {DCMI_ERR_CODE_FILE_OPERATE_FAIL, NPU_ERR_CODE_FILE_OPERATE_FAIL},
    {DCMI_ERR_CODE_RESET_FAIL, NPU_ERR_CODE_RESET_FAIL},
    {DCMI_ERR_CODE_ABORT_OPERATE, NPU_ERR_CODE_ABORT_OPERATE},
    {DCMI_ERR_CODE_IS_UPGRADING, NPU_ERR_CODE_IS_UPGRADING},
    {DCMI_ERR_CODE_RESOURCE_OCCUPIED, NPU_ERR_CODE_RESOURCE_OCCUPIED},
    {DCMI_ERR_CODE_PARTITION_NOT_RIGHT, NPU_ERR_CODE_PARTITION_NOT_RIGHT},
    {DCMI_ERR_CODE_NOT_SUPPORT, NPU_ERR_CODE_NOT_SUPPORT},
};

int dcmi_to_npu_error_code(int dcmi_err_code)
{
    size_t err_code_map_size = sizeof(g_npu_err_code_map) / sizeof(struct err_code_map);
    size_t index;

    for (index = 0; index < err_code_map_size; index++) {
        if (dcmi_err_code == g_npu_err_code_map[index].dcmi_err_code) {
            return g_npu_err_code_map[index].npu_err_code;
        }
    }
    return NPU_ERR_CODE_INNER_ERR;
}
