/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CARD_INFO_H_
#define _NPU_CARD_INFO_H_

#include "npu_smi.h"
#include "npu_common.h"

int query_card_info(struct npu_smi_operate_info *operate_info);
int show_ascend_board_info(struct npu_smi_operate_info *operate_info);
int show_ascend_card_health(struct npu_smi_operate_info *operate_info);
int show_ascend_card_default_proc(struct npu_smi_operate_info *operate_info);
int show_ascend_card_template_info(struct npu_smi_operate_info *operate_info);
int npu_get_card_board_info(int card_id, struct npu_device_info *device_info);

#endif /* _NPU_CARD_INFO_H_ */