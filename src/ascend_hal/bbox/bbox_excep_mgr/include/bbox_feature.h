/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef BBOX_FEATURE_H
#define BBOX_FEATURE_H

#include <stdbool.h>
#include "bbox_dump_feature_def.h"
#include "ascend_hal.h"

drvError_t bbox_feature_init(void);
bool bbox_has_feature(unsigned int dev_id, enum bbox_feature_id feature);

#endif /* BBOX_FEATURE_H */
