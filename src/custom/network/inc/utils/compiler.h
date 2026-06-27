/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _COMPILER_UTILS_H_
#define _COMPILER_UTILS_H_

#define CONCAT_NAME_(a, b) a##_##b
#define CONCAT_NAME(a, b)  CONCAT_NAME_(a, b)

#define STATIC_ASSERT(cond, msg) \
    typedef char CONCAT_NAME(CONCAT_NAME(_static_assertion, __LINE__), msg)[(cond) ? 1 : -1]

#define ARRAY_SIZE(array)  (sizeof(array) / sizeof((array)[0]))

#ifndef offsetof
# if defined(__GNUC__) || defined(__clang__)
#  define offsetof(type, member) __builtin_offsetof(type, member)
# else
#  define offsetof(type, member) ((size_t)&(((type*)0)->member))  /* 不能用于位域成员 */
# endif
#endif

#define __maybe_unused __attribute__((unused))

#endif /* _COMPILER_UTILS_H_ */
