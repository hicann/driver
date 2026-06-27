/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _MATH_UTILS_H_
#define _MATH_UTILS_H_

#define DECIMAL_SCALE  10

typedef struct {
    unsigned int integer;      // 整数部分
    unsigned int fraction;     // 缩放后的分数部分（即小数部分 * 10^precision 四舍五入取整）
} decimal_t;

/**
 * @brief 计算 base 的 exp 次幂
 *
 * 该函数使用快速幂算法（二分幂），时间复杂度 O(log exp)。
 *
 * @param base  底数（无符号整数，0～UINT_MAX）
 * @param exp   指数（非负整数）
 * @return unsigned int 计算结果：base^exp
 *
 * @warning 注意溢出风险！
 * - 该函数返回 unsigned int 类型，最大值为 UINT_MAX（通常 4294967295）。
 *
 * @note 当 base == 0 且 exp == 0 时，数学上未定义，本函数返回 1（常见约定）。
 */
static inline unsigned int pow_u32(unsigned int base, unsigned int exp)
{
    unsigned int res = 1;

    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
    }
    return res;
}

/**
 * @brief 将浮点数拆分为整数部分和缩放后的小数部分（四舍五入）
 *
 * 将输入的浮点数按指定精度拆分，结果保存在 decimal_t 结构体中。
 * 小数部分会被乘以 10^precision 并四舍五入取整，便于后续格式化输出。
 *
 * @param value     待拆分的浮点数（非负数，若为负数需外部处理符号）
 * @param precision 保留的小数位数（0~7，建议最多5位，避免乘数溢出）
 * @return decimal_t 包含以下字段：
 *         - integer:   整数部分 (unsigned int)
 *         - fraction:  小数部分 * 10^precision 并四舍五入后的整数值
 */
static inline decimal_t split_decimal(float value, unsigned int precision)
{
    decimal_t dec = { .integer = (unsigned int)value };
    unsigned int frac_part_scale = pow_u32(DECIMAL_SCALE, precision & 0x7);

    dec.fraction = (unsigned int)(frac_part_scale * (value - dec.integer) + 0.5f);
    if (dec.fraction >= frac_part_scale) {
        dec.fraction -= frac_part_scale;
        dec.integer += 1;
    }

    return dec;
}

#undef DECIMAL_SCALE

#endif /* _MATH_UTILS_H_ */
