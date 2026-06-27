/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef JPEGE_REG_UNION_DEFINE_H
#define JPEGE_REG_UNION_DEFINE_H

#include "ka_type.h"

union Prefetch {
    // Define the struct bits
    struct {
        uint32_t prefetchEn : 1;     // [0]
        uint32_t prefetchDelay : 11; // [1..11]
        uint32_t reserved : 20;      // [12..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union IDY0 {
    // Define the struct bits
    struct {
        uint32_t ID0Y : 7;      // [0..6]
        uint32_t reserved0 : 1; // [7]
        uint32_t ID1Y : 7;      // [8..14]
        uint32_t reserved1 : 1; // [15]
        uint32_t ID2Y : 7;      // [16..22]
        uint32_t reserved2 : 1; // [23]
        uint32_t ID3Y : 7;      // [24..30]
        uint32_t reserved3 : 1; // [31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union IDY1 {
    // Define the struct bits
    struct {
        uint32_t ID4Y : 7;      // [0..6]
        uint32_t reserved0 : 1; // [7]
        uint32_t ID5Y : 7;      // [8..14]
        uint32_t reserved1 : 1; // [15]
        uint32_t ID6Y : 7;      // [16..22]
        uint32_t reserved2 : 1; // [23]
        uint32_t ID7Y : 7;      // [24..30]
        uint32_t reserved3 : 1; // [31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union IDUV0 {
    // Define the struct bits
    struct {
        uint32_t ID0UV : 7;     // [0..6]
        uint32_t reserved0 : 1; // [7]
        uint32_t ID1UV : 7;     // [8..14]
        uint32_t reserved1 : 1; // [15]
        uint32_t ID2UV : 7;     // [16..22]
        uint32_t reserved2 : 1; // [23]
        uint32_t ID3UV : 7;     // [24..30]
        uint32_t reserved3 : 1; // [31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union IDUVY {
    // Define the struct bits
    struct {
        uint32_t ID4UV : 7;      // [0..6]
        uint32_t reserved0 : 1;  // [7]
        uint32_t ID8Y : 7;       // [8..14]
        uint32_t reserved1 : 17; // [15..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union SYNCCFG {
    // Define the struct bits
    struct {
        uint32_t source : 1;     // [0]
        uint32_t reserved0 : 1;  // [1]
        uint32_t sramNoopt : 1;  // [2]
        uint32_t reserved1 : 29; // [13..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union statusICR {
    // Define the struct bits
    struct {
        uint32_t reserved0 : 4;        // [0..3]
        uint32_t encodeDoneIsr : 1;    // [4]
        uint32_t genHeaderDoneIsr : 1; // [5]
        uint32_t reserved1 : 16;       // [6..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union inputSwap {
    // Define the struct bits
    struct {
        uint32_t swapinYUV : 1;  // [0]
        uint32_t swapinUV : 1;   // [1]
        uint32_t reserved0 : 30; // [2..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union tableData {
    // Define the struct bits
    struct {
        uint32_t tableWdataL : 8; // [0..7]
        uint32_t tableWdataH : 8; // [8..15]
        uint32_t reserved0 : 16;  // [16..31]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

union frameStride {
    // Define the struct bits
    struct {
        uint32_t reserved0 : 4;  // [3..0]
        // CLOUD_V2时stride的有效位为4~14位,MINI_V2时stride的有效位为4~19位,由于reserved1未使用,此处可以按照位数多的定义
        uint32_t stride : 16;    // [19..4]
        uint32_t reserved1 : 12; // [31..20]
    } bits;

    // Define an unsigned member
    uint32_t u32;
};

#endif // JPEGE_REG_UNION_DEFINE_H