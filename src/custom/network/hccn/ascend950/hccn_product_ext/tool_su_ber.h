/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_SU_BER_H
#define TOOL_SU_BER_H

#include "tool_param.h"
#include "tool_product.h"
#include "st_su_ber.h"

#define ERR_FRAME_RATE_LEN          32
#define SU_BER_RATE_LEN             32

void get_su_ber_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count);
void *alloc_su_ber_args(void);
int su_ber_assign(void *args, struct sub_option_entry *opt, value_union *type_val);
int tool_su_ber_exec(struct command_context *ctx);
void tool_su_ber_help(struct command_context *ctx, unsigned int mode);

#endif /* TOOL_SU_BER_H */