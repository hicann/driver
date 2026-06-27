/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DEVDRV_MANAGER_SYSTEM_INFO_H
#define DEVDRV_MANAGER_SYSTEM_INFO_H

#include "ascend_hal.h"

drvError_t drv_get_system_info_ex(uint32_t devId, int32_t info_type, void *buf, unsigned int *size);
drvError_t drv_set_system_info_ex(uint32_t devId, int32_t info_type, void *buf, unsigned int size);
drvError_t DmsSetSWPluginUpgrade(unsigned int dev_id, unsigned int sub_cmd, const void *in_buff, unsigned int buf_len);
drvError_t DmsGetSWPluginUpgrade(unsigned int dev_id, void *in_buff);

#endif /* DEVDRV_MANAGER_SYSTEM_INFO_H */
