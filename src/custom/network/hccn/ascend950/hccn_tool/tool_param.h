/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_PARAM_H
#define TOOL_PARAM_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <linux/limits.h>
#include "ds_data.h"
#include "tool_comm.h"
#include "tcpip_cmd_data.h"
#include "shell_cmd_data.h"

#define ARGS_TOOL_INDEX 0
#define ARGS_MODE_INDEX 1
#define ARGS_MAIN_CMD_INDEX 2

#define MAX_STR_VAL_LEN PATH_MAX

typedef struct {
    union {
        int int_val;
        int flag_val;
        struct ip_val ip;
        char str_val[MAX_STR_VAL_LEN];
        struct mac_val mac;
    };
    bool is_set;
} value_union;

// ------------------ 类型 ------------------
enum arg_type {
    ARG_TYPE_INT,
    ARG_TYPE_IP,
    ARG_TYPE_FLAG,
    ARG_TYPE_STR,
    ARG_TYPE_OPTSTR,  // Optional String, for parsing -crl [<filename>]
    ARG_TYPE_MAC,
    ARG_TYPE_NONE
};

// ------------------ 模式 ------------------
enum {
    MODE_GET_OFFSET = 0,
    MODE_SET_OFFSET,
    MODE_TEST_OFFSET,
    MODE_HELP_OFFSET,
    MODE_NUM
};

#define MODE_GET        HCCN_BIT(MODE_GET_OFFSET)
#define MODE_SET        HCCN_BIT(MODE_SET_OFFSET)
#define MODE_TEST       HCCN_BIT(MODE_TEST_OFFSET)
#define MODE_HELP       HCCN_BIT(MODE_HELP_OFFSET)

#define MODE_NONE  0
#define MODE_BOTH  (MODE_GET | MODE_SET)
#define MODE_ALL   (MODE_GET | MODE_SET | MODE_TEST)

#define MAC_MOD_3 3
#define MAC_REMAINDER_0 0
#define MAC_REMAINDER_1 1
#define MAC_REMAINDER_2 2
#define MAC_TEN_OFFSET_10 10
#define MAC_HEX_BASE_16 16
#define SUB_OPT_MAC_MASK HCCN_BIT(3)
#define SUB_OPT_TRACEROUTE_DIP_MASK HCCN_BIT(7)
#define SUB_OPT_TRACEROUTE_RESET_MASK HCCN_BIT(0)

struct mode_opt_entry {
    const char *name;
    unsigned int mode_type;
};

struct dev_opt_entry {
    const char *name;
    unsigned int dev_type;
    enum arg_type val_type;
    union {
        int *value_int;
        char *value_str;
        bool *value_flag;
    };
    size_t value_size;
    bool has_range;                                             // 是否启用范围检查
    union {
        struct { int min; int max; } int_range;
    } range;
};

struct arg_value {
    union {
        const char *as_str;
        int as_int;
        bool as_bool;
    };
    void *mem;    // 若 union 字段引用常量类型，此字段赋值为 NULL
    bool is_set;
};

// ------------------ 子命令选项结构体 ------------------
#define SUB_OPTION_FLAG_RANEG_ARRAY_LEN 16
struct sub_option_entry {
    const char *name;                                           // 子命令或参数名
    enum arg_type type;                                         // 参数类型
    int (*parse)(struct sub_option_entry *self, const char *, value_union *);  // 选项参数值解析函数
    unsigned int param_mode_mask;                               // 参数支持的模式掩码
    unsigned int param_required_mask;                           // 参数在指定模式下必选
    bool has_range;                                             // 是否启用范围检查
    union {
        struct { int min; int max; } int_range;
        struct { int max_len; } str_range;
        struct { uint32_t min_ip; uint32_t max_ip; } ip_range;
        struct { int valid_flags[SUB_OPTION_FLAG_RANEG_ARRAY_LEN]; } flag_range;
    } range;
    struct arg_value val;   // 选项的参数值
    bool is_set;            // 选项是否被指定
    uint64_t ext_data;
};

// ------------------ 主命令表 ------------------
struct cmd_entry {
    const char *name;                                   // 主命令名
    void (*get_sub_opts)(struct sub_option_entry **sub_opts, unsigned int *count); // 获取子选项表及数量的函数
    unsigned int mode_mask;                             // 支持的模式掩码
    void* (*alloc_args)();                              // 构造参数结构体的函数
    int (*assign)(void *, struct sub_option_entry *, value_union *); // 参数赋值函数
    int (*exec)(struct command_context *ctx);           // 执行函数
    unsigned int supported_dev_mask[DEV_COMBINATION_NUM]; // 该命令允许的设备组合
    void (*print_help)(struct command_context *ctx, unsigned int mode);            // 打印帮助命令函数

    struct cmd_entry *child;                            // 子命令表
    int child_count;                                    // 子命令数量
    unsigned int unsupported_prod_mask;                 // 不支持的产品
    struct mode_env_mask_cfg {
        unsigned int mode_mask;                         // MODE_GET / MODE_SET / MODE_TEST
        unsigned int unsupported_env_mask;              // 该模式不支持的环境
    } mode_env_mask_array[MODE_NUM];
    void (*free_args)(struct cmd_entry *self, void *args); // 析构参数结构体的函数
};

int parse_int(struct sub_option_entry *self, const char *val, value_union *type_val);
int parse_ip(struct sub_option_entry *self, const char *val, value_union *type_val);
int parse_mac(struct sub_option_entry *self, const char *val, value_union *type_val);
int parse_str(struct sub_option_entry *self, const char *val, value_union *type_val);
int parse_optstr(struct sub_option_entry *self, const char *val, value_union *type_val);
int parse_none(struct sub_option_entry *self, const char *val, value_union *type_val);

bool is_valid_ip(const char *str_ip, int expected_family);
bool is_valid_integer(const char *str);
bool is_value_in_range(struct sub_option_entry *opt, value_union *val);
int tool_ipv4_int_to_str(const unsigned int ip, char *str, int len);

#endif // TOOL_PARAM_H
