/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _BITMAP_UTILS_H_
#define _BITMAP_UTILS_H_

/* imp 中有非内联的 bitmap 实现，但是采用 u32 数组实现，有内存对齐风险。 */

#define BIT_PER_BYTE  8
#define u32 unsigned int   /* imp 不能使用 C 标准库头文件 */
#define u8 unsigned char

/**
 * @brief 获取位图中指定比特位的值（字节数组实现，无对齐问题）
 *
 * @param bitmap  位图数据（u8数组）。每个字节的低位到高位依次对应位图的低索引到高索引（小端字节序）。
 * @param size    位图的字节数
 * @param bit     位索引 [0, size*8 - 1]
 *
 * @return  0 或 1，若 bit 越界则返回 0
 *
 * @note 每个字节的低位（bit0）到高位（bit7）依次对应位图的低索引到高索引。
 * @see b8_bitmap_set_bit
 */
static inline u32 b8_bitmap_get_bit(const u8 *bitmap, u32 size, u32 bit)
{
    u32 byte_index = bit / BIT_PER_BYTE;
    u32 bit_offset = bit % BIT_PER_BYTE;

    if (byte_index >= size) {
        return 0;
    }

    return (bitmap[byte_index] >> bit_offset) & 0x1;
}

/**
 * @brief 设置位图中指定比特位的值（0 或 1）
 *
 * 本函数基于 uint8_t 数组实现位图写入，底层无地址对齐要求，
 * 与基于 uint32_t 数组的实现（可能存在对齐问题）相区分。
 *
 * @param bitmap  位图数据（u8数组）。写入操作采用小端字节序（字节低位对应较小位索引）。
 * @param size    位图的字节数
 * @param bit     位索引 [0, size*8 - 1]
 * @param val     要设置的值（非0视为1，0视为0）
 *
 * @note 每个字节的低位（bit0）到高位（bit7）依次对应位图的低索引到高索引。
 * @see b8_bitmap_get_bit
 */
static inline void b8_bitmap_set_bit(u8 *bitmap, u32 size, u32 bit, u32 val)
{
    u32 byte_index = bit / BIT_PER_BYTE;
    u32 bit_offset = bit % BIT_PER_BYTE;

    if (byte_index >= size) {
        return;
    }

    if (val) {
        bitmap[byte_index] |= (0x1 << bit_offset);
    } else {
        bitmap[byte_index] &= ~(0x1 << bit_offset);
    }
}

#undef u8
#undef u32
#undef BIT_PER_BYTE

#endif /* _BITMAP_UTILS_H_ */
