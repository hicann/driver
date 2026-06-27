/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_TABLE_H
#define TOOL_TABLE_H

#include "stdbool.h"

/**
 * tool_table用于打印如下格式的表格
 * +-----+------+------+---------+-------------+------------+-------------+----------------+-----------+--------+
 * | NPU | UDie | Port | present | temperature | high power | vendor_name | vendor id      | vcc       | tx los |
 * +-----+------+------+---------+-------------+------------+-------------+----------------+-----------+--------+
 * | 1   | 2    | 0    | present | 70 C        | enable     | XSFP STUB   | 0x3c 0xff 0x5a | 1.2345 mV | 0x3    |
 * | 1   | 2    | 1    | present | 37 C        | enable     | STUB XSFP   | 0x12 0x34 0x56 | 9.9999 mV | 0xa    |
 * | 1   | 2    | 2    | absent  | 0 C         | disable    | 123         | 0x0 0x0 0x0    | 0.0000 mV | 0xf    |
 * +-----+------+------+---------+-------------+------------+-------------+----------------+-----------+--------+
 * 主要有两种调用方式：
 * 一：若你的数据支持直接打印
 * 1. INIT_TABLE 初始化表头
 * 2. PREPARE_TABLE 自动计算属性偏移 或 set_offset_by_name 手动计算属性偏移
 * 3. print_table_by_input 打印表格
 * 二：若你的数据需要组装/翻译后才能打印
 * 1. malloc_table 初始化表头
 * 2. ADDTO_TABLE / SET_TABLE 组装数据
 * 3. print_table 打印表格
*/

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define TOOL_TABLE_ROW_1        1
#define TOOL_TABLE_ROW_3        3
#define TOOL_TABLE_ROW_4        4
#define TOOL_TABLE_ROW_5        5
#define TOOL_TABLE_ROW_8        8
#define TOOL_TABLE_ROW_12       12
#define TOOL_TABLE_ROW_26       26
#define TOOL_TABLE_COL_2        2
#define TOOL_TABLE_COL_3        3
#define TOOL_TABLE_COL_4        4
#define TOOL_TABLE_COL_5        5
#define TOOL_TABLE_COL_6        6
#define TOOL_TABLE_COL_7        7
#define TOOL_TABLE_COL_8        8
#define TOOL_TABLE_COL_9        9
#define TOOL_TABLE_CHARS_10     10
#define TOOL_TABLE_CHARS_12     12
#define TOOL_TABLE_CHARS_18     18
#define TOOL_TABLE_CHARS_20     20
#define TOOL_TABLE_CHARS_22     22
#define TOOL_TABLE_CHARS_24     24

#define TABLE_LEN_MAX 100           // TABLE中单列不能超过50字符
#define TABLE_MAX 20                // TABLE最大支持显示20列，如要扩展，记得同步扩展下面的参数计数宏
#define __COUNT_ARGS(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
                     _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N
#define COUNT_ARGS(...) __COUNT_ARGS(, ##__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
                                                      9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define INIT_TABLE(...) init_table(COUNT_ARGS(__VA_ARGS__) / 2, ##__VA_ARGS__)

#define ADDTO_TABLE(...) addto_table(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)
#define SET_TABLE(row, name, ...) set_table_by_name(COUNT_ARGS(__VA_ARGS__), row, name, ##__VA_ARGS__)
#define SET_TABLE_BY_NAME(row, name, ...) set_table_by_name(COUNT_ARGS(__VA_ARGS__), row, name, ##__VA_ARGS__)
#define SET_TABLE_BY_INDEX(row, col, ...) set_table_by_index(COUNT_ARGS(__VA_ARGS__), row, col, ##__VA_ARGS__)
#define SET_ROW(row, ...) set_table_by_index(COUNT_ARGS(__VA_ARGS__), row, 0, ##__VA_ARGS__)
/** 要求一次性填写整行，不支持在这里sprintf CHARS型数据，只能用NULL占位符 */

#define SET_ENTIRE_ROW(row, ...) set_entire_row(COUNT_ARGS(__VA_ARGS__), row, ##__VA_ARGS__)

#define DEFINE_TABLE_LEN(...) set_entire_table_len(COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__)

/* 同样是自动参数计数，允许你用 addto_table(DATA_PACK(1, 2, 3)) 替代 ADDTO_TABLE(1, 2, 3)，但是不太美观 */

#define DATA_PACK(...) COUNT_ARGS(__VA_ARGS__), ##__VA_ARGS__

enum table_type {
    // 32位数据
    TYPE_INT,
    TYPE_UINT,
    TYPE_HEX,
    // 8位数据
    TYPE_CHAR,
    TYPE_UCHAR,
    TYPE_XCHAR,
    // 字符串(char *)
    TYPE_STR,
    // 字符串(char [])
    TYPE_CHARS,
};

struct table_t {
    const char *name;
    enum table_type type;
    unsigned char len;
    unsigned char offset; // 偏移
};

struct table_value_t {
    union {
        int value_int;
        unsigned int value_uint;
        char value_char;
        unsigned int value_uchar;
        char *value_str;
        void *value;
    };
};

struct table_header_t {
    const char *name;
    enum  table_type type;
    unsigned char len;
};

int init_table(int num, ...);   /** 定义表头 */
int init_table_t(int num, struct table_header_t *header); /** 定义表头，但是使用数据结构而非可变参数 */
int print_table_by_input(void *input, unsigned int row, unsigned int size); /** 根据输入的数据打印表格 */

void print_table_sep_line(void); /** 打印 +---+---+ 这种间隔行 */
void print_table_header(void);   /** 打印表头 */

int set_table_len_by_name(char *name, unsigned char len); /** 手动指定表格列宽 */
int set_table_len_by_index(int col, int len);
int set_entire_table_len(int num, ...); /** 一次性指定表格的所有列宽 */
int set_offset_by_name(char *name, unsigned int offset);
int set_offset_by_index(int index, unsigned int offset);
void prepare_table_pack(int size, ...);
int malloc_table_advance(char *prefix, int row, int col, ...);
int malloc_table(int row, int col, ...);
int malloc_table_advance_t(char *prefix, int row, int col, struct table_header_t *header);
int malloc_table_t(int row, int col, struct table_header_t *header);
int addto_table(int num, ...);
int print_table(void);
int goto_table_offset(int row, int col);
int goto_table_offset_by_name(int row, char *name);
int goto_table_row(int row);
int get_col(char *name);
int set_table_by_index(int num, int row, int col, ...);
int set_table_by_name(int num, int row, char *name, ...);
int get_table_col_len(void);
int set_entire_row(int num, int row, ...);
bool table_reach_end(void);
int malloc_table_prefix_t(unsigned int flag, int row, int col, struct table_header_t *header);
void clean_table(void);

#endif
