/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "tool_table.h"
#include "tool_errcode.h"
#include "tool_lib.h"
#include "securec.h"
#include "hccn_log.h"
#include "tool_param.h"

// TOOL_PRINT_INFO会自动在打印后加换行，所以这里另起打印宏
#define PRINT(fmt, ...) do { fprintf(stdout, fmt, ##__VA_ARGS__); } while (0)

static struct table_t g_table[TABLE_MAX];
static void *g_table_data;          // malloc_table后会在这里记录data
static void *g_table_temp;          // 当前数据指针
static unsigned int g_table_index;  // 当前元素指针
static unsigned int g_table_row;    // 当前列表行数
static unsigned int g_table_size;   // 当前列表体积(一行)

/** 清理表格数据，会在init_table/malloc_table时自动调用 */
void clean_table(void)
{
    (void)memset_s(g_table, sizeof(g_table), 0, sizeof(g_table));
    if (g_table_data) {
        free(g_table_data);
        g_table_data = NULL;
        g_table_temp = NULL;
        g_table_index = 0;
        g_table_row = 0;
        g_table_size = 0;
    }
}

/** 定义表头 */
int init_table(int num, ...)
{
    enum table_type type;
    char *name;
    int i;
    va_list va;

    if (num >= TABLE_MAX) {
        return TOOL_TABLE_ERROR;
    }

    va_start(va, num);
    clean_table();
    for (i = 0; i < num; i++) {
        name = va_arg(va, char *);
        type = va_arg(va, enum table_type);
        g_table[i].name = name;
        g_table[i].type = type;
    }
    va_end(va);
    return 0;
}

int init_table_t(int num, struct table_header_t *header)
{
    int i;

    if (header == NULL) {
        return TOOL_TABLE_ERROR;
    }
    if (num >= TABLE_MAX) {
        return TOOL_TABLE_ERROR;
    }

    clean_table();
    for (i = 0; i < num; i++) {
        g_table[i].name = header[i].name;
        g_table[i].type = header[i].type;
    }
    return 0;
}

unsigned char int_len(int input)
{
    // cleancode 避免修改函数入参
    int temp = input;
    unsigned char i = 0;

    // 0也是要打印出来的占1位
    if (input == 0) {
        return 1;
    }

    while (temp != 0) {
        temp = temp / 10L;
        i++;
    }
    // 算上负号
    return i + (input < 0 ? 1 : 0);
}

unsigned char uint_len(unsigned int input)
{
    // cleancode 避免修改函数入参
    unsigned int temp = input;
    unsigned char i = 0;

    if (input == 0) {
        return 1;
    }
    while (temp != 0) {
        temp = temp / 10UL;
        i++;
    }
    return i;
}

unsigned char hex_len(unsigned int input)
{
    // cleancode 避免修改函数入参
    unsigned int temp = input;
    unsigned char i = 0;
    // 0会以0x0的形式打印出来占3位
    if (input == 0) {
        return 0x3;
    }
    while (temp != 0) {
        temp = temp / 16UL;
        i++;
    }
    // 加上2位0x前缀
    return i + 0x2;
}

/** 打印X个空格 */
void print_blank(unsigned int len)
{
    char temp[TABLE_LEN_MAX];
    if (len >= TABLE_LEN_MAX) {
        return;
    }
    (void)memset_s(temp, TABLE_LEN_MAX, ' ', TABLE_LEN_MAX);
    temp[len] = '\0';
    PRINT("%s", temp);
}

/** 打印 +---+---+ 这种间隔行 */
void print_table_sep_line(void)
{
    int i;
    char temp[TABLE_LEN_MAX + 0x1]; // 多0x1放结束符

    PRINT("+");
    for (i = 0; g_table[i].name != NULL; i++) {
        (void)memset_s(temp, TABLE_LEN_MAX, '-', TABLE_LEN_MAX);
        if (g_table[i].len + 0x2 >= TABLE_LEN_MAX) { // 2: 左右各一个空格
            return;
        }
        temp[g_table[i].len + 0x2] = '+';
        temp[g_table[i].len + 0x3] = '\0'; // 3: 结束符
        PRINT("%s", temp);
    }
    PRINT("\n");
}

/** 打印表头 */
void print_table_header(void)
{
    int i;
    print_table_sep_line();
    PRINT("|");
    for (i = 0; g_table[i].name != NULL; i++) {
        PRINT(" %s ", g_table[i].name);
        print_blank(g_table[i].len - strlen(g_table[i].name));
        PRINT("|");
    }
    PRINT("\n");
    print_table_sep_line();
}

/** 若使用该接口指定表格列宽，需要一次性完成所有列宽的指定，否则请使用set_table_len_by_name/index单点赋值 */
int set_entire_table_len(int num, ...)
{
    int i;
    va_list va;

    if (num != get_table_col_len()) {
        return TOOL_TABLE_ERROR;
    }

    va_start(va, num);
    for (i = 0; i < num; i++) {
        g_table[i].len = va_arg(va, unsigned int);
    }
    va_end(va);
    return 0;
}

/** 手动定义表格指定列宽 */
int set_table_len_by_name(char *name, unsigned char len)
{
    int col;
    if (name == NULL) {
        return TOOL_TABLE_ERROR;
    }
    col = get_col(name);
    if (col < 0 || col >= TABLE_MAX) {
        return TOOL_TABLE_ERROR;
    }
    g_table[col].len = len;
    return 0;
}

int set_table_len_by_index(int col, int len)
{
    if (col < 0 || col >= TABLE_MAX) {
        return TOOL_TABLE_ERROR;
    }
    g_table[col].len = len;
    return 0;
}

static unsigned char table_get_len(int i, struct table_value_t *value)
{
    switch (g_table[i].type) {
        case TYPE_INT:
        case TYPE_CHAR:
            return int_len(value->value_int);
        case TYPE_UINT:
        case TYPE_UCHAR:
            return uint_len(value->value_uint);
        case TYPE_HEX:
        case TYPE_XCHAR:
            return hex_len(value->value_uint);
        case TYPE_STR:
            return value->value_str ? strlen(value->value_str) : 0;
        case TYPE_CHARS:
            return value->value ? strlen((char *)value->value) : 0;
        default:
            return 0;
    }
}

static void table_fill_blank(int i, struct table_value_t *value)
{
    unsigned char len = table_get_len(i, value);
    print_blank(g_table[i].len - len);
}

/** 成功加载数据时返回正数代表偏移，失败时返回负数 */
static int table_load_in_data(int i, void *data, unsigned int size, struct table_value_t *value)
{
    int ret, step = 0;
    switch (g_table[i].type) {
        case TYPE_INT:
        case TYPE_UINT:
        case TYPE_HEX:
            ret = (size >= sizeof(int)) ? memcpy_s(&value->value_int, sizeof(int), data, sizeof(int)) : -1;
            step = sizeof(int);
            break;
        case TYPE_CHAR:
        case TYPE_UCHAR:
        case TYPE_XCHAR:
            ret = (size >= sizeof(int)) ? memcpy_s(&value->value_int, sizeof(char), data, sizeof(char)) : -1;
            step = sizeof(char);
            break;
        case TYPE_STR:
            ret = (size >= sizeof(char *)) ? memcpy_s(&value->value_str, sizeof(char *), data, sizeof(char *)) : -1;
            step = sizeof(char *);
            break;
        case TYPE_CHARS:
            value->value = data;
            return (size >= g_table[i].offset) ? g_table[i].offset : -TOOL_TABLE_ERROR;
        default:
            return -TOOL_TABLE_ERROR;
    }
    if (ret) {
        return -TOOL_TABLE_ERROR;
    }
    return step;
}

/** 返回值为正数代表偏移量，否则为错误 */
int print_table_data_line(void *input, unsigned int size)
{
    int i, step, offset = 0;
    struct table_value_t value = {0};

    PRINT("|");
    for (i = 0; g_table[i].name; i++) {
        step = table_load_in_data(i, input + offset, size - offset, &value);
        if (step < 0) {
            hccn_err("print table failed. (col=%d, ret=%d)\n", i, step);
            return step;
        }
        switch (g_table[i].type) {
            case TYPE_INT:
            case TYPE_CHAR:
                PRINT(" %d ", value.value_int);
                break;
            case TYPE_UINT:
            case TYPE_UCHAR:
                PRINT(" %u ", value.value_uint);
                break;
            case TYPE_HEX:
            case TYPE_XCHAR:
                PRINT(" 0x%x ", value.value_uint);
                break;
            case TYPE_STR:
                if (value.value_str == NULL) {
                    PRINT("  ");
                } else {
                    PRINT(" %s ", value.value_str);
                }
                break;
            case TYPE_CHARS:
                PRINT(" %s ", (char *)(input + offset));
                break;
            default:
                return -TOOL_TABLE_ERROR;
        }
        table_fill_blank(i, &value);
        PRINT("|");
        offset += g_table[i].offset ? g_table[i].offset : step;
    }
    PRINT("\n");
    return offset;
}

int table_flush_length(void *input, unsigned int row, unsigned int size)
{
    int i, j;
    unsigned int left = row * size;
    unsigned int step, offset = 0;
    struct table_value_t value = {0};

    // 首先识别表头长度
    for (i = 0; g_table[i].name; i++) {
        g_table[i].len = max(g_table[i].len, strlen(g_table[i].name));
    }
    // 然后遍历表格确认最大宽度
    for (i = 0; i < row; i++) {
        for (j = 0; g_table[j].name; j++) {
            step = table_load_in_data(j, input + offset, left - offset, &value);
            if (step < 0) {
                hccn_err("check table length failed. (row=%d; col=%d; offset=%d; ret=%d)", i, j, offset, step);
                return step;
            }
            g_table[j].len = max(g_table[j].len, table_get_len(j, &value));
            offset += g_table[j].offset ? g_table[j].offset : step;
        }
    }
    return 0;
}

/** 根据输入的数据打印表格。input是入参，row是有几行，size是单个元素的大小 */
int print_table_by_input(void *input, unsigned int row, unsigned int size)
{
    int i;
    unsigned int left = row * size;
    int offset = 0, step;
    if (input == NULL) {
        return TOOL_TABLE_ERROR;
    }
    if (table_flush_length(input, row, size)) {
        return TOOL_TABLE_ERROR;
    }
    // 不校验left，因为元素不一定全部打印
    offset = 0;
    print_table_header();
    for (i = 0; i < row; i++) {
        step = print_table_data_line(input + offset, left - offset);
        if (step < 0) {
            hccn_err("print table failed. (row=%d; offset=%d; ret=%d)\n", i, offset, step);
            return step;
        }
        offset += step;
    }
    print_table_sep_line();
    return 0;
}

int set_offset_by_name(char *name, unsigned int offset)
{
    int col = get_col(name);
    if (col < 0 || col >= TABLE_MAX) {
        hccn_err("cannot set offset. (col=%s)\n", name);
        return TOOL_TABLE_ERROR;
    }
    return set_offset_by_index(col, offset);
}

int set_offset_by_index(int index, unsigned int offset)
{
    if (index >= TABLE_MAX) {
        hccn_err("cannot set offset. (col=%d)\n", index);
        return TOOL_TABLE_ERROR;
    }
    g_table[index].offset = offset;
    return 0;
}

// 通过传入结构体中各属性的地址，自动计算offset，地址必须是递进的不能有回头
void prepare_table_pack(int size, ...)
{
    va_list va;
    va_start(va, size);
    int i;
    void *p1 = va_arg(va, void *);
    void *lastp = p1;
    void *p = p1;  // 若列数为1导致循环0次执行，p 退化为 p1，424行offset算出0，避免未初始化使用
    for (i = 0; g_table[i + 1].name && (i + 1 < TABLE_MAX); i++) {
        p = va_arg(va, void *);
        g_table[i].offset = (size + p - lastp) % size;
        lastp = p;
    }
    g_table[i].offset = (size + p1 - p) % size;
    va_end(va);
}

/** 判断两个字符是否一致，无视大小写 */
static bool char_match(char a, char b)
{
    char A = a;
    if (a >= 'a' && a <= 'z') {
        A = a - 'a' + 'A';
    }
    if (a >= 'A' && a <= 'Z') {
        A = a - 'A' + 'a';
    }
    return (a == b) || (A == b);
}

/** malloc_table的内部函数，为了将有无prefix的情况归一才有该层封装，外界不应调用 */
static int malloc_table_inner(int row, int col, unsigned int prefix_size, va_list va)
{
    int index = get_table_col_len();
    unsigned int size = prefix_size;
    int i;

    if (index + col >= TABLE_LEN_MAX) {
        hccn_err("calloc table failed. (col=%d)", index + col);
        return TOOL_TABLE_ERROR;
    }

    for (i = 0; i < col; i++) {
        g_table[index + i].name = va_arg(va, char *);
        g_table[index + i].type = va_arg(va, enum table_type);
        if (g_table[index + i].type == TYPE_CHARS) {
            g_table[index + i].offset = va_arg(va, unsigned int);
            size += g_table[index + i].offset;
        } else if (g_table[index + i].type == TYPE_STR) {
            size += sizeof(char *);
        } else if (g_table[index + i].type <= TYPE_HEX) {
            size += sizeof(int);
        } else {
            size += sizeof(char);
        }
    }
    g_table_data = calloc(row, size);
    if (g_table_data == NULL) {
        hccn_err("calloc table failed. (row=%d; size=%u)", row, size);
        return TOOL_TABLE_ERROR;
    }
    g_table_temp = g_table_data;
    g_table_row = row;
    g_table_size = size;
    return 0;
}

static int malloc_table_inner_t(int row, int col, unsigned int prefix_size, struct table_header_t *header)
{
    int index = get_table_col_len();
    unsigned int size = prefix_size;
    int i;

    if (header == NULL) {
        return TOOL_TABLE_ERROR;
    }

    if (index + col >= TABLE_LEN_MAX) {
        hccn_err("calloc table failed. (col=%d)", index + col);
        return TOOL_TABLE_ERROR;
    }

    for (i = 0; i < col; i++) {
        g_table[index + i].name = header[i].name;
        g_table[index + i].type = header[i].type;
        if (g_table[index + i].type == TYPE_CHARS) {
            g_table[index + i].offset = header[i].len;
            size += header[i].len;
        } else if (g_table[index + i].type == TYPE_STR) {
            size += sizeof(char *);
        } else if (g_table[index + i].type <= TYPE_HEX) {
            size += sizeof(int);
        } else {
            size += sizeof(char);
        }
    }
    g_table_data = calloc(row, size);
    if (g_table_data == NULL) {
        hccn_err("calloc table failed. (row=%d; size=%u)", row, size);
        return TOOL_TABLE_ERROR;
    }
    g_table_temp = g_table_data;
    g_table_row = row;
    g_table_size = size;
    return 0;
}

static unsigned int malloc_table_prefix_inner(char *prefix)
{
    int i, j, index = 0;
    char head_code[] = {'i', 'u', 'p', 'd', 'o'};
    char *head_name[] = {"NPU", "UDie", "Port", "Dev", "Optical"};
    unsigned int size = 0;

    for (i = 0; prefix[i]; i++) {
        for (j = 0; j < sizeof(head_code); j++) {
            if (!char_match(prefix[i], head_code[j])) {
                continue;
            }
            g_table[index].name = head_name[j];
            g_table[index].type = char_match(prefix[i], 'd') ? TYPE_STR : TYPE_UINT;
            size += g_table[index].type == TYPE_STR ? sizeof(char *) : sizeof(int);
            index++;
            break;
        }
        if (j == sizeof(head_code)) {
            hccn_err("unknown prefix [%s]\n", prefix);
            return 0;
        }
    }
    return size;
}

int malloc_table_advance(char *prefix, int row, int col, ...)
{
    unsigned int size = 0;
    va_list va;
    int ret;

    clean_table();

    if (prefix == NULL) {
        return TOOL_TABLE_ERROR;
    }

    size = malloc_table_prefix_inner(prefix);
    if (strlen(prefix) && (size == 0)) {
        return TOOL_TABLE_ERROR;
    }

    va_start(va, col);
    ret = malloc_table_inner(row, col, size, va);
    va_end(va);
    return ret;
}

int malloc_table(int row, int col, ...)
{
    int ret;
    va_list va;

    clean_table();

    va_start(va, col);
    ret = malloc_table_inner(row, col, 0, va);
    va_end(va);
    return ret;
}

int malloc_table_advance_t(char *prefix, int row, int col, struct table_header_t *header)
{
    unsigned int size = 0;

    clean_table();

    size = malloc_table_prefix_inner(prefix);
    if (strlen(prefix) && (size == 0)) {
        return TOOL_TABLE_ERROR;
    }

    return malloc_table_inner_t(row, col, size, header);
}

int malloc_table_prefix_t(unsigned int flag, int row, int col, struct table_header_t *header)
{
    char prefix[DEV_COMBINATION_NUM + 1] = {0};
    char head[] = {'I', 'U', 'P', 'D', 'O'};
    int i = 0, j = 0;
    for (; i < DEV_COMBINATION_NUM; i++) {
        if (flag & HCCN_BIT(i)) {
            prefix[j++] = head[i];
        }
    }
    return malloc_table_advance_t(prefix, row, col, header);
}

int malloc_table_t(int row, int col, struct table_header_t *header)
{
    clean_table();
    return malloc_table_inner_t(row, col, 0, header);
}

static unsigned int table_space_left(void *current)
{
    return g_table_data + g_table_row * g_table_size - current;
}

static int prepare_chars_value(va_list va, char *value_str)
{
    int ret = 0;
    ret = vsprintf_s(g_table_temp, g_table[g_table_index].offset, value_str, va);
    if (ret < 0) {
        return TOOL_TABLE_ERROR;
    } else if (ret == 0) {
        ret = sprintf_s(g_table_temp, g_table[g_table_index].offset, TABLE_INFO_INVALID);
        if (ret <= 0) {
            return TOOL_TABLE_ERROR;
        }
    }
    return 0;
}

int addto_table_va(int num, va_list va)
{
    int i, ret = 0;
    struct table_value_t value = {0};
    if (g_table_temp == NULL) {
        return TOOL_TABLE_ERROR;
    }
    for (i = 0; i < num; i++) {
        switch (g_table[g_table_index].type) {
            case TYPE_CHARS:
                value.value_str = va_arg(va, char *);
                if (value.value_str == NULL) {
                    g_table_temp += g_table[g_table_index].offset;
                    break;
                }
                // 支持自动拼装CHARS型，但是拼装完会直接结束函数，无法再接收输入
                ret = prepare_chars_value(va, value.value_str);
                if (ret != 0) {
                    return TOOL_TABLE_ERROR;
                }
                g_table_temp += g_table[g_table_index].offset;
                g_table_index = g_table[++g_table_index].name ? g_table_index : 0;
                return 0;
            case TYPE_STR:
                value.value_str = va_arg(va, char *);
                ret = memcpy_s(g_table_temp, table_space_left(g_table_temp), &value.value_str, sizeof(char *));
                g_table_temp += sizeof(char *);
                break;
            case TYPE_INT:
            case TYPE_UINT:
            case TYPE_HEX:
                value.value_int = va_arg(va, int);
                ret = memcpy_s(g_table_temp, table_space_left(g_table_temp), &value.value_int, sizeof(int));
                g_table_temp += sizeof(int);
                break;
            case TYPE_CHAR:
            case TYPE_UCHAR:
            case TYPE_XCHAR:
                value.value_int = va_arg(va, int); // 数据成为可变参数时会自动提升至至少int型
                ret = memcpy_s(g_table_temp, table_space_left(g_table_temp), &value.value_int, sizeof(char));
                g_table_temp += sizeof(char);
                break;
            default:
                return TOOL_TABLE_ERROR;
        }
        if (ret) {
            return TOOL_TABLE_ERROR;
        }
        g_table_index = g_table[++g_table_index].name ? g_table_index : 0;
    }
    return 0;
}

int addto_table(int num, ...)
{
    int ret;
    va_list va;
    va_start(va, num);
    ret = addto_table_va(num, va);
    va_end(va);
    return ret;
}

/** 用于malloc_table的打印，malloc_table的数据放在全局变量里，所以这里无需输入 */
int print_table(void)
{
    return print_table_by_input(g_table_data, g_table_row, g_table_size);
}

/** 跳转到当前表格的X行Y列，通常与addto_table等配合使用 */
int goto_table_offset(int row, int col)
{
    unsigned int offset = 0;
    int columns;
    int i;

    columns = get_table_col_len();
    if (col >= columns || g_table[col].name == NULL || row >= g_table_row || g_table_data == NULL) {
        hccn_err("error on get_table_offset. (row=%d/%u, col=%d/%d)\n", row, g_table_row, col, columns);
        return TOOL_TABLE_ERROR;
    }
    offset += (row * g_table_size);
    for (i = 0; i < col; i++) {
        if (g_table[i].type == TYPE_CHARS) {
            offset += g_table[i].offset;
        } else if (g_table[i].type == TYPE_STR) {
            offset += sizeof(char *);
        } else if (g_table[i].type <= TYPE_HEX) {
            offset += sizeof(int);
        } else {
            offset += sizeof(char);
        }
    }
    g_table_temp = g_table_data + offset;
    g_table_index = col;
    return 0;
}

int goto_table_offset_by_name(int row, char *name)
{
    int col = get_col(name);
    if (col < 0 || col >= TABLE_MAX) {
        return TOOL_TABLE_ERROR;
    }
    return goto_table_offset(row, col);
}

int goto_table_row(int row)
{
    return goto_table_offset(row, 0);
}

/** 查找当前name位于表格的第几列，当有多列同名时，取出最先匹配的列 */
int get_col(char *name)
{
    int i;
    if (name == NULL) {
        return TOOL_TABLE_ERROR;
    }
    for (i = 0; g_table[i].name && i < TABLE_MAX; i++) {
        if (strcmp(name, g_table[i].name) == 0) {
            return i;
        }
    }
    return -TOOL_TABLE_ERROR;
}

int set_table_va(int num, int row, int col, va_list va)
{
    int ret;

    if (col < 0) {
        return col;
    }
    ret = goto_table_offset(row, col);
    if (ret) {
        return ret;
    }
    return addto_table_va(num, va);
}

int set_table_by_index(int num, int row, int col, ...)
{
    int ret;
    va_list va;
    va_start(va, col);
    ret = set_table_va(num, row, col, va);
    va_end(va);
    return ret;
}

int set_table_by_name(int num, int row, char *name, ...)
{
    int ret, col;
    va_list va;

    col = get_col(name);
    if (col < 0 || col >= TABLE_MAX) {
        return -TOOL_TABLE_ERROR;
    }
    va_start(va, name);
    ret = set_table_va(num, row, col, va);
    va_end(va);
    return ret;
}

/** 获取当前表格有几列 */
int get_table_col_len(void)
{
    int i = 0;
    for (i = 0; g_table[i].name && i < TABLE_MAX; i++) {
        // 不执行操作，仅是用for循环搜索g_table[i].name == NULL的终点
    }
    return i;
}

int set_entire_row(int num, int row, ...)
{
    int col = get_table_col_len();
    int ret;
    va_list va;
    va_start(va, row);
    if (num != col) {
        hccn_err("set entire row failed. (expect=%d; input=%d)\n", col, num);
        return -TOOL_TABLE_ERROR;
    }
    ret = set_table_va(num, row, 0, va);
    va_end(va);
    return ret;
}

/** 抵达末尾时index也正好为0，常用于添加完元素后检查是否刚好一行结束 */
bool table_reach_end(void)
{
    return g_table_index == 0;
}
