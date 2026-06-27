/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_UPGRADE_H__
#define __NPU_UPGRADE_H__
#include "npu_smi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define MCU_RETRY_TOTAL_TIMES 2

#define VOL_MOD_NUM_LEN 1
#define VOL_MOD_NAME_LEN 10
#define VOL_MOD_VALUE_LEN 2
#define VOL_MOD_VALUE_NUM 3
#define VOL_MOD_INFO_LEN (VOL_MOD_NAME_LEN + VOL_MOD_VALUE_LEN * VOL_MOD_VALUE_NUM)
#define VOL_MOD_VALUE_INVALID 0x7fff
#define VOL_MOD_VALUE_ERROR 0x7ffd

int npu_upgrade_main(struct npu_smi_operate_info* operate_info, int argc, char** argv);
void print_upgrade_result(int ret, struct npu_smi_operate_info* operate_info);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPU_UPGRADE_H__ */