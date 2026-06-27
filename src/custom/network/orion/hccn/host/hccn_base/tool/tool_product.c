/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdlib.h>
#include <string.h>
#include "file_opt.h"
#include "ds_data.h"
#include "tool_cmd_parse.h"
#include "tool_comm.h"
#include "tool_serdes.h"
#include "ascend_hal.h"
#include "securec.h"
#include "tool_errcode.h"
#include "ds_net_interface.h"
#include "comm_channel.h"
#include "comm_channel_ext.h"
#include "tool_cmd_err.h"
#include "dsmi_inner_interface.h"
#include "dsmi_common_interface.h"
#include "dsmi_common_product.h"
#include "tool_lib.h"
#include "tool_table.h"
#include "tool_optical.h"
#include "comm_product.h"
#include "tcpip_cmd_data.h"
#include "tool_port_dfx.h"
#include "tool_su_ber.h"
#include "tool_cfg_ops.h"
#include "tool_product.h"
#include "dsmi_optical.h"
#include "tool_udp.h"
#include "tool_dev_info.h"


#define PRINT(fmt, ...) do { fprintf(stdout, fmt, ##__VA_ARGS__); } while (0)

#ifdef DEBUG_MODE
void get_i2c_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    // 当前i2c预期只用来访问cpld和xsfp，他们都是offlen为1的器件
    static struct sub_option_entry param_list[] = {
        {"-dev", ARG_TYPE_INT, parse_int, MODE_TEST, MODE_TEST, true, .range.int_range = {0, 0xFF}},
        {"-reg", ARG_TYPE_INT, parse_int, MODE_TEST, MODE_TEST, true, .range.int_range = {0, 0xFF}},
        {"-read", ARG_TYPE_NONE, parse_none, MODE_TEST},
        {"-write", ARG_TYPE_NONE, parse_none, MODE_TEST},
        {"-val", ARG_TYPE_INT, parse_int, MODE_TEST},
    };
    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}

void *alloc_i2c_args(void)
{
    return calloc(1, sizeof(struct i2c_test_t));
}

#define RWFLAG_INVALID 0
#define RWFLAG_READ    1
#define RWFLAG_WRITE   2
int i2c_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct i2c_test_t *data = (struct i2c_test_t *)args;

    if (strcmp(opt->name, "-dev") == 0) {
        data->dev = type_val->int_val;
    } else if (strcmp(opt->name, "-reg") == 0) {
        data->reg = type_val->int_val;
    } else if (strcmp(opt->name, "-val") == 0) {
        data->val = type_val->int_val;
    } else if (strcmp(opt->name, "-read") == 0) {
        if (data->rw != RWFLAG_INVALID) {
            return TOOL_CONFLICT_INPUT;
        }
        data->rw = RWFLAG_READ;
    } else if (strcmp(opt->name, "-write") == 0) {
        if (data->rw != RWFLAG_INVALID) {
            return TOOL_CONFLICT_INPUT;
        }
        data->rw = RWFLAG_WRITE;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

static void tool_i2c_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        // 如果一个主命令字有多个模式，不同模式的属性不一样，case MODE_ALL中会打印所有MODE
        case MODE_ALL:
            tool_i2c_print_help(ctx, MODE_TEST);
            break;
        case MODE_TEST:
            TOOL_PRINT_CMD("-t", "-i2c", "i2c test cmd, not for release");
            tool_print_npu_info(DEV_DEV_ATTR);
            TOOL_PRINT_OPT("[-read|-write]", "marks this cmd is a read or write command, omiting this means read.");
            TOOL_PRINT_OPT("-dev <slave_address>", "target device you want to access");
            TOOL_PRINT_OPT("-reg <reg_address>", "register you want to read/write");
            TOOL_PRINT_OPT("[-val <value>]", "data you want to write in. will be ignore if this is a read cmd.");
            break;
        default:
            break;
    }
}

int tool_i2c_exec(struct command_context *ctx)
{
    int ret;
    struct product_channel_msg msg = {0};
    struct i2c_test_t *data = (struct i2c_test_t *)ctx->cmd_args;

    // 不指定读写时默认为读
    if (data->rw == RWFLAG_INVALID) {
        data->rw = RWFLAG_READ;
    }

    // 指定inbuf inlen outbuf outlen
    SET_PRODUCT_MSG(msg, data, sizeof(struct i2c_test_t), data, sizeof(struct i2c_test_t));
    // 下发数据
    ret = product_host_device_channel(ctx, CMD_I2C_OPERATE, &msg);
    if (ret) {
        hccn_err("i2c %s failed. (ret:%d)", data->rw == RWFLAG_WRITE ? "write" : "read", ret);
        return ret;
    }

    if (data->rw == RWFLAG_READ) {
        TOOL_PRINT_INFO("i2c read  dev[0x%x] reg[0x%x] >> val[0x%x]", data->dev, data->reg, data->val);
    } else {
        TOOL_PRINT_INFO("i2c write val[0x%x] >> dev[0x%x] reg[0x%x]", data->val, data->dev, data->reg);
    }
    return 0;
}
#endif


void get_ip_rule_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry param_list[] = {
        {"-dir", ARG_TYPE_STR, parse_str, MODE_SET, MODE_SET},
        {"-ip", ARG_TYPE_IP, parse_ip, MODE_SET, MODE_SET},
        {"-add", ARG_TYPE_NONE, parse_none, MODE_SET},
        {"-delete", ARG_TYPE_NONE, parse_none, MODE_SET},
        {"-table", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {0, 0xFF}},
    };
    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}

void *alloc_ip_rule_args(void)
{
    struct ip_rule_t *data = calloc(1, sizeof(struct ip_rule_t));
    if (data == NULL) {
        return NULL;
    }
    data->addel = PARAM_INVALID;
    data->table = PARAM_INVALID;
    return data;
}


static int ip_rule_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct ip_rule_t *data = (struct ip_rule_t *)args;

    if (strcmp(opt->name, "-dir") == 0) {
        if (strcmp(type_val->str_val, "from") != 0 && strcmp(type_val->str_val, "to") != 0) {
            hccn_err("ip rule dir wrong");
            return TOOL_ASSIGN_UNKNOWN;
        }
        if (memcpy_s(data->dir, IP_DIR_SIZE, type_val->str_val, strlen(type_val->str_val) + 1) != 0) {
            hccn_err("memcpy_s failed for dir");
            return TOOL_ASSIGN_UNKNOWN;
        }
    } else if (strcmp(opt->name, "-ip") == 0) {
        if (memcpy_s(data->ip, sizeof(data->ip), type_val->ip.str_ip, sizeof(type_val->ip.str_ip)) != 0) {
            hccn_err("memcpy_s failed for ip");
            return TOOL_ASSIGN_UNKNOWN;
        }
    } else if (strcmp(opt->name, "-table") == 0) {
        data->table = type_val->int_val;
    } else if (strcmp(opt->name, "-add") == 0) {
        if (data->addel != (unsigned char)PARAM_INVALID) {
            TOOL_PRINT_ERR("Option -add and -delete conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        data->addel = ADD_MODE_FLAG;
    } else if (strcmp(opt->name, "-delete") == 0) {
        if (data->addel != (unsigned char)PARAM_INVALID) {
            TOOL_PRINT_ERR("Option -add and -delete conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        data->addel = DEL_MODE_FLAG;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

static int ip_rule_cmd_ret(struct command_context *ctx, struct ip_rule_ret_t *result, int rule_count)
{
    int ret = 0, i;
    struct ip_rule_ret_t *rule = {0};

    ret = malloc_table_advance("I", rule_count, TOOL_TABLE_COL_5,
                               "net_dev",  TYPE_STR,
                               "priority", TYPE_UINT,
                               "selector", TYPE_STR,
                               "action",   TYPE_STR,
                               "table",    TYPE_STR);
    if (ret != 0) {
        hccn_err("get ip rule table failed. (ret=%d)", ret);
        return TOOL_TABLE_ERROR;
    }

    for (i = 0; i < rule_count; i++) {
        rule = &result[i];
        ret += SET_ENTIRE_ROW(i, ctx->dev_id, ctx->dev_name, rule->priority, rule->selector, rule->action, rule->table);
    }
    if (ret != 0) {
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

static int parse_ip_rule_string_part(char **ptr, const char *line_end, char *dest, size_t dest_size)
{
    size_t skip_len = strspn(*ptr, " \t");
    *ptr += skip_len;
    if (*ptr >= line_end || **ptr == '\n' || **ptr == '\0') {
        return EINVAL;
    }
    char *token = strsep(ptr, " \t\n");
    if (token == NULL) {
        return EINVAL;
    }
    size_t len = strlen(token);
    if (strncpy_s(dest, dest_size, token, len) != 0) {
        return EINVAL;
    }
    if (len < dest_size) {
        dest[len] = '\0';
    } else {
        dest[dest_size - 1] = '\0';
    }
    return 0;
}

static int parse_ip_rule_line(const char *line, struct ip_rule_ret_t *rule)
{
    // 复制输入行到临时缓冲区
    char *line_copy = strdup(line);
    if (line_copy == NULL) {
        return EINVAL;
    }
    // 数据格式  0： 		  from all lookup local
    char *ptr = line_copy;
    const char *line_end = line_copy + strlen(line_copy);

    // 解析优先级字段
    if (sscanf_s(ptr, "%u:", &rule->priority) != 1) {
        free(line_copy);
        return EINVAL;
    }
    // 跳过冒号分隔符
    ptr = strchr(ptr, ':');
    if (ptr == NULL) {
        free(line_copy);
        return EINVAL;
    }
    ptr++;
    // 解析选择器部分
    char selector_part1[IP_RET_DATA_SIZE] = {0};
    char selector_part2[IP_RET_DATA_SIZE] = {0};
    
    if (parse_ip_rule_string_part(&ptr, line_end, selector_part1, sizeof(selector_part1)) != 0 ||
        parse_ip_rule_string_part(&ptr, line_end, selector_part2, sizeof(selector_part2)) != 0) {
        free(line_copy);
        return EINVAL;
    }
    // 组合选择器部分
    int ret = sprintf_s(rule->selector, sizeof(rule->selector), "%s %s", selector_part1, selector_part2);
    if (ret < 0 || (size_t)ret >= sizeof(rule->selector)) {
        rule->selector[0] = '\0';
        free(line_copy);
        return EINVAL;
    }
    // 解析动作和表名
    if (parse_ip_rule_string_part(&ptr, line_end, rule->action, sizeof(rule->action)) != 0 ||
        parse_ip_rule_string_part(&ptr, line_end, rule->table, sizeof(rule->table)) != 0) {
        free(line_copy);
        return EINVAL;
    }
    free(line_copy);
    return 0;
}

int parse_ip_rules(const char *ret_data, struct ip_rule_ret_t *rules, int rule_size, int *rule_count)
{
    const char *ptr = ret_data;
    *rule_count = 0;
    int ret = 0;
    // 按行处理输入数据
    while (ptr && *ptr) {
        if (*rule_count >= rule_size) {
            hccn_err("parse_ip_rule_line rule_count exceed max size. (rule_count=%d)", *rule_count);
            return TOOL_INVALID_INNER_LOGIC;
        }
        // 找到行结束位置
        const char *line_end = strchr(ptr, '\n');
        if (!line_end) {
            line_end = ptr + strlen(ptr);
        }
        // 复制当前行到临时缓冲区
        char line[IP_RULE_SIZE];
        size_t line_len = line_end - ptr;
        if (line_len >= sizeof(line)) {
            hccn_err("Parse_ip_rules failed to copy line.");
            return EINVAL;
        }
        // 安全复制字符串
        ret = strncpy_s(line, sizeof(line), ptr, line_len);
        if (ret != 0) {
            hccn_err("Parse_ip_rules failed to copy string.");
            return EINVAL;
        }
        line[line_len] = '\0';
        // 解析当前行
        struct ip_rule_ret_t rule = {0};
        if (parse_ip_rule_line(line, &rule) != 0) {
            hccn_err("parse_ip_rule_line failed.");
            return EINVAL;
        }
        // 存储解析结果
        rules[*rule_count] = rule;
        (*rule_count)++;
        // 移动到下一行
        ptr = line_end + 1;
    }
    
    return 0;
}

static int tool_update_ip_rule_cfg(struct command_context *ctx)
{
    int ret = 0;
    struct ip_rule_t *data = (struct ip_rule_t *)ctx->cmd_args;
    char match_list[MATCH_LIST_CNT][CONFLINE_LENGTH] = {0};

    ret = snprintf_s(match_list[0], CONFLINE_LENGTH, CONFLINE_LENGTH - 1, "ip_rule_%d=%s %s table %d\n",
                     ctx->slot_id, data->dir, data->ip, (int)data->table); // 输出负数
    if (ret <= 0) {
        hccn_err("handle ip rule conf snprintf failed. (ret=%d)", ret);
        return -EIO;
    }

    // tool_update_conf 会按行匹配 MATCH_LIST_CNT 个 match_list 关键词，若符合则执行对应操作
    // 对于可重复添加的持久化命令，使用FILE_OPT_TYPE_APPEND_WRITE强制添加新配置
    if (data->addel == ADD_MODE_FLAG) {
        ret = tool_update_conf(match_list[0], FILE_OPT_TYPE_APPEND_WRITE, match_list, MATCH_LIST_CNT);
        if (ret != 0) {
            hccn_err("write cfg ip rule error. (ret=%d; slot_id=%d; logic_id=%d)", ret, ctx->slot_id,
                     ctx->npu_info.logic_id);
            return ret;
        }
    } else {
        // tool_del_conf会删除所有配置，包括重复配置，使用tool_update_conf的FILE_OPT_TYPE_MATCH_DEL全匹配删除
        ret = tool_update_conf(NULL, FILE_OPT_TYPE_MATCH_DEL, match_list, MATCH_LIST_CNT);
        if (ret) {
            hccn_err("del cfg ip rule error. (ret=%d; slot_id=%d; logic_id=%d)", ret, ctx->slot_id,
                     ctx->npu_info.logic_id);
            return ret;
        }
    }

    return 0;
}

int tool_set_ip_rule(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct ip_rule_t *data = (struct ip_rule_t *)ctx->cmd_args;

    if (data->addel == (unsigned char)PARAM_INVALID) {
        TOOL_PRINT_ERR("Option -add or -delete is required but missing.");
        return TOOL_PRIVATE_ARGS_VALUE_ERR;
    }

    SET_PRODUCT_MSG(msg, data, sizeof(struct ip_rule_t), NULL, 0);
    ret = product_host_device_channel(ctx, CMD_IP_RULE_SET, &msg);
    if (ret != 0) {
        hccn_err("set ip rule failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_get_ip_rule(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    int rule_count = 0;
    char ret_data[IP_MAX_SIZE] = {0};
    struct ip_rule_ret_t rules[IP_MAX_RULE_NUM] = {0};

    SET_PRODUCT_MSG(msg, NULL, 0, ret_data, IP_MAX_SIZE);
    ret = product_host_device_channel(ctx, CMD_IP_RULE_GET, &msg);
    if (ret != 0) {
        hccn_err("get ip rule failed. (ret=%d)", ret);
        return ret;
    }

    ret = parse_ip_rules(ret_data, rules, IP_MAX_RULE_NUM, &rule_count);
    if (ret != 0) {
        hccn_err("ip rule cmd parse failed. (ret=%d)", ret);
        return ret;
    }

    ret = ip_rule_cmd_ret(ctx, rules, rule_count);
    if (ret) {
        hccn_err("ip rule cmd ret failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

int tool_ip_rule_exec(struct command_context *ctx)
{
    int ret = 0;

    if (tool_is_uboe_mainboard(ctx->npu_info.mainboard_id) != true) {
        hccn_info("only server UBoE board support ip rule cmd. (mainboard_id=0x%x)", ctx->npu_info.mainboard_id);
        return TOOL_UNSUPPORT_BOARD;
    }

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    if (ctx->mode == MODE_SET) {
        ret = tool_set_ip_rule(ctx);
        if (ret != 0) {
            return ret;
        }

        ret = tool_update_ip_rule_cfg(ctx);
        if (ret != 0) {
            return ret;
        }
    } else { // MODE_GET
        ret = tool_get_ip_rule(ctx);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

static void tool_ip_rule_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_ip_rule_print_help(ctx, MODE_GET);
            tool_ip_rule_print_help(ctx, MODE_SET);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-ip_rule", "set ip rule command");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-add|-delete]", "add/delete rule");
            TOOL_PRINT_OPT("-dir <dir_addr>", "from or to");
            TOOL_PRINT_OPT("-ip <ip_addr>", "destination ip, such as x.x.x.x");
            TOOL_PRINT_OPT("[-table <value>]", "table index, such as xx, [0 ~ 255]");
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-ip_rule", "get ip rule command");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            break;
        default:
            break;
    }
}

void get_ip_route_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry param_list[] = {
        {"-ip_mask", ARG_TYPE_INT, parse_int, MODE_SET, MODE_SET, true, .range.int_range = {0, 32}},
        {"-ip", ARG_TYPE_IP, parse_ip, MODE_SET, MODE_SET},
        {"-add", ARG_TYPE_NONE, parse_none, MODE_SET},
        {"-delete", ARG_TYPE_NONE, parse_none, MODE_SET},
        {"-via", ARG_TYPE_IP, parse_ip, MODE_SET, MODE_SET},
        {"-table", ARG_TYPE_INT, parse_int, MODE_BOTH, 0, true, .range.int_range = {0, 255}},
    };
    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}

void *alloc_ip_route_args(void)
{
    struct ip_route_t *data = calloc(1, sizeof(struct ip_route_t));
    if (data == NULL) {
        return NULL;
    }
    data->addel = PARAM_INVALID;
    data->table_id = PARAM_INVALID;
    return data;
}

int ip_route_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct ip_route_t *data = (struct ip_route_t *)args;
    int ret;

    if (strcmp(opt->name, "-ip") == 0) {
        ret = memcpy_s(data->ip_address, sizeof(data->ip_address), type_val->ip.str_ip, sizeof(type_val->ip.str_ip));
        if (ret != 0) {
            hccn_err("memcpy_s failed for ip");
            return ret;
        }
    } else if (strcmp(opt->name, "-via") == 0) {
        ret = memcpy_s(data->via_address, sizeof(data->via_address), type_val->ip.str_ip, sizeof(type_val->ip.str_ip));
        if (ret != 0) {
            hccn_err("memcpy_s failed for ip");
            return ret;
        }
    } else if (strcmp(opt->name, "-table") == 0) {
        data->table_id = type_val->int_val;
    } else if (strcmp(opt->name, "-ip_mask") == 0) {
        data->ip_mask = type_val->int_val;
    } else if (strcmp(opt->name, "-add") == 0) {
        if (data->addel != PARAM_INVALID) {
            TOOL_PRINT_ERR("Option -add and -delete conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        data->addel = ADD_MODE_FLAG;
    } else if (strcmp(opt->name, "-delete") == 0) {
        if (data->addel != PARAM_INVALID) {
            TOOL_PRINT_ERR("Option -add and -delete conflict with each other.");
            return TOOL_PRIVATE_ARGS_CONFLICT_ERR;
        }
        data->addel = DEL_MODE_FLAG;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

// 处理GET功能的函数
static int tool_get_ip_route(struct command_context *ctx)
{
    struct product_channel_msg msg = {0};
    struct ip_route_t *data = (struct ip_route_t *)ctx->cmd_args;
    bool need_free_data = false;
    if (data == NULL) {
        data = alloc_ip_route_args();
        if (data == NULL) {
            hccn_err("Failed to allocate memory for GET data.");
            return EINVAL;
        }
        need_free_data = true;
    }
    char *ret_data = (char *)malloc(IP_ROUTE_DATA_SIZE * sizeof(char));
    if (ret_data == NULL) {
        hccn_err("Memory allocation failed for return data.");
        if (need_free_data && data) {
            free(data);
        }
        return EINVAL;
    }

    SET_PRODUCT_MSG(msg, data, sizeof(struct ip_route_t), ret_data, IP_ROUTE_DATA_SIZE);
    int ret = product_host_device_channel(ctx, CMD_IP_ROUTE_GET, &msg);
    if (ret != 0) {
        if (ret != ENOENT) {
            hccn_err("IP route GET failed. (ret=%d)", ret);
        }
        free(ret_data);
        if (need_free_data && data) {
            free(data);
        }
        return ret;
    }

    TOOL_PRINT_INFO("%s", ret_data);
    free(ret_data);
    if (need_free_data && data) {
        free(data);
    }

    return 0;
}

static int tool_update_ip_route_cfg(struct command_context *ctx)
{
    int ret = 0;
    struct ip_route_t *data = (struct ip_route_t *)ctx->cmd_args;
    char match_list[MATCH_LIST_CNT][CONFLINE_LENGTH] = {0};

    ret = snprintf_s(match_list[0], CONFLINE_LENGTH, CONFLINE_LENGTH - 1, "ip_route_%d=%s %u via %s table %d\n",
        ctx->slot_id, data->ip_address, data->ip_mask, data->via_address, (int)data->table_id);
    if (ret <= 0) {
        hccn_err("handle ip route conf snprintf failed. (ret=%d)", ret);
        return -EIO;
    }

    // tool_update_conf 会按行匹配 MATCH_LIST_CNT 个 match_list 关键词，若符合则执行对应操作
    // 对于可重复添加的持久化命令，使用FILE_OPT_TYPE_APPEND_WRITE强制添加新配置
    if (data->addel == ADD_MODE_FLAG) {
        ret = tool_update_conf(match_list[0], FILE_OPT_TYPE_APPEND_WRITE, match_list, MATCH_LIST_CNT);
        if (ret != 0) {
            hccn_err("write cfg ip route error. (ret=%d; slot_id=%d; logic_id=%d)", ret, ctx->slot_id,
                     ctx->npu_info.logic_id);
            return ret;
        }
    } else {
        // tool_del_conf会删除所有配置，包括重复配置，使用tool_update_conf的FILE_OPT_TYPE_MATCH_DEL全匹配删除
        ret = tool_update_conf(NULL, FILE_OPT_TYPE_MATCH_DEL, match_list, MATCH_LIST_CNT);
        if (ret) {
            hccn_err("del cfg ip route error. (ret=%d; slot_id=%d; logic_id=%d)", ret, ctx->slot_id,
                     ctx->npu_info.logic_id);
            return ret;
        }
    }

    return 0;
}

// 处理SET功能的函数
int tool_set_ip_route(struct command_context *ctx)
{
    struct product_channel_msg msg = {0};
    struct ip_route_t *data = (struct ip_route_t *)ctx->cmd_args;

    if (data->addel == PARAM_INVALID) {
        TOOL_PRINT_ERR("Option -add or -delete is required but missing.");
        return TOOL_PRIVATE_ARGS_VALUE_ERR;
    }

    SET_PRODUCT_MSG(msg, data, sizeof(struct ip_route_t), NULL, 0);
    int ret = product_host_device_channel(ctx, CMD_IP_ROUTE_SET, &msg);
    if (ret != 0) {
        if (ret != EEXIST) {
            hccn_err("IP route set failed. (ret=%d)", ret);
        }
        return ret;
    }

    return 0;
}

int tool_ip_route_exec(struct command_context *ctx)
{
    int ret;

    if (tool_is_uboe_mainboard(ctx->npu_info.mainboard_id) != true) {
        hccn_info("only server UBoE board support ip route cmd. (mainboard_id=0x%x)",
            ctx->npu_info.mainboard_id);
        return TOOL_UNSUPPORT_BOARD;
    }

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    if (ctx->mode == MODE_SET) {
        ret = tool_set_ip_route(ctx);
        if (ret != 0) {
            if (ret == EEXIST) {
                TOOL_PRINT_ERR("IP route table already exists.");
                return DSMI_EXE_ERR;
            } else if (ret == EADDRNOTAVAIL) {
                TOOL_PRINT_ERR("Nexthop has invalid gateway.");
                return DSMI_EXE_ERR;
            }
            return ret;
        }

        ret = tool_update_ip_route_cfg(ctx);
        if (ret != 0) {
            return ret;
        }
    } else {
        ret = tool_get_ip_route(ctx);
        if (ret != 0) {
            if (ret == ENOENT) {
                TOOL_PRINT_ERR("FIB table does not exist!");
                return DSMI_EXE_ERR;
            }
            return ret;
        }
    }

    return 0;
}

static void tool_ip_route_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        // 如果一个主命令字有多个模式，不同模式的属性不一样，case MODE_ALL中会打印所有MODE
        case MODE_ALL:
            tool_ip_route_print_help(ctx, MODE_GET);
            tool_ip_route_print_help(ctx, MODE_SET);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-ip_route", "set ip route");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-add|-delete]", "add/delete route");
            TOOL_PRINT_OPT("-ip <ip_addr>", "ip address, such as x.x.x.x");
            TOOL_PRINT_OPT("-ip_mask <mask>", "ip mask bit, such as x, [0 ~ 32]");
            TOOL_PRINT_OPT("-via <via_addr>", "forward ip, such as x.x.x.x");
            TOOL_PRINT_OPT("[-table <value>]", "table index, such as xx, [0 ~ 255]");
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-ip_route", "get route table");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-table <value>]", "table index, such as xx, [0 ~ 255]");
            break;
        default:
            break;
    }
}

int tool_ub_connect_exec(struct command_context *ctx)
{
    char *top_status[] = {"DOWN", "UP", "PARTIAL LINK", "NA"};
    char *sub_status[] = {"DOWN", "UP", "PARTIAL LINK", "INITIAL"};
    struct dsmi_ub_status data;
    unsigned int size = sizeof(data);
    int ret, port_id, *port_list;

    if (tool_is_pcie_board(ctx) != true) {
        hccn_err("only pcie card support ub connect.");
        return TOOL_UNSUPPORT_BOARD;
    }

    ret = dsmi_get_device_info(ctx->dev_id, DSMI_MAIN_CMD_UB, DSMI_UB_INFO_SUB_CMD_PORT_STATUS, &data, &size);
    if (ret) {
        hccn_err("dsmi get ub connect failed. (dev=%d; ret=%d)", ctx->dev_id, ret);
        return ret;
    }
    if (data.ub_link_status >= ARRAY_SIZE_COMPUTE(top_status)) {
        hccn_err("dsmi get ub connect invalid result. (dev=%d; status=%d)", ctx->dev_id, data.ub_link_status);
        return TOOL_INVALID_RESULT;
    }
    TOOL_PRINT_INFO("link status : %s", top_status[data.ub_link_status]);

    port_list = tool_get_pcie_card_port_list(ctx);
    if (port_list == NULL) {
        hccn_err("get valid port failed. (dev=%d)", ctx->dev_id);
        return TOOL_DSMI_ERROR;
    }

    for (port_id = *port_list; port_id >= 0 && port_id < DSMI_UB_PORT_NUM; port_list++, port_id = *port_list) {
        if (data.ub_port_status[port_id] >= ARRAY_SIZE_COMPUTE(sub_status)) {
            hccn_err("dsmi get ub connect invalid result. (dev=%d; port=%d; status=%d)",
                     ctx->dev_id, port_id, data.ub_port_status[port_id]);
            ret = TOOL_INVALID_RESULT; // 当前Port数据异常时不显示，但会继续完成其他Port打印，最终才报错退出
            continue;
        }
        TOOL_PRINT_INFO("port %d : %s", port_id, sub_status[data.ub_port_status[port_id]]);
    }

    return ret;
}

static void tool_ub_connect_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_ub_connect_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-ub_connect", "check ub connect status");
            tool_print_npu_info(DEV_NPU_ATTR);
            break;
        default:
            break;
    }
}

static int tool_speed_exec(struct command_context *ctx)
{
    int ret;
    struct hccn_speed_t data = {0};
    struct product_channel_msg msg = {0};
    struct table_header_t header[] = {
        {"Speed",   TYPE_CHARS, 8},   // speed可能为100G/200G/400G/unknown，需要8位存储
        {"Cap",     TYPE_CHARS, 3},   // cap可能为x1/x2/x4/x8，需要3位存储
        {"Width",   TYPE_CHARS, 3},   // 同上，3位存储
        {"Status",  TYPE_STR},
    };
    char *status[] = {"normal", "downgraded", "abnormal"};

    SET_PRODUCT_MSG(msg, NULL, 0, &data, sizeof(struct hccn_speed_t));
    ret = product_host_device_channel(ctx, CMD_GET_SPEED, &msg);
    if (ret) {
        hccn_err("get speed failed. (ret=%d)", ret);
        return ret;
    }

    if (malloc_table_prefix_t(DEV_PORT_TYPE, 1, ARRAY_SIZE_COMPUTE(header), header) != 0) {
        hccn_err("alloc table show speed failed.");
        return TOOL_TABLE_ERROR;
    }

    ret += SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, NULL, NULL, NULL, NULL);
    ret += SET_TABLE(0, "Cap",   "X%u",  data.cap);
    if (data.speed) {
        ret += SET_TABLE(0, "Speed", "%u G", data.speed);
    } else {
        ret += SET_TABLE(0, "Speed", "unknown");
    }
    if (data.width) {
        ret += SET_TABLE(0, "Width", "X%u",  data.width);
    } else {
        ret += SET_TABLE(0, "Width", "NA");
    }
    if (data.status >= ARRAY_SIZE_COMPUTE(status)) {
        hccn_err("invalid status value. (status=%d)", data.status);
        return TOOL_INVALID_RESULT;
    }
    ret += SET_TABLE(0, "Status", status[data.status]);
    if (ret) {
        hccn_err("write table show speed failed.");
        clean_table();
        return TOOL_TABLE_ERROR;
    }
    print_table();
    clean_table();

    return 0;
}

static void tool_speed_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_speed_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-speed", "check speed info");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}

static int tool_dump_exec(struct command_context *ctx)
{
    int ret;
    struct product_channel_msg msg = {0};

    ret = hccn_check_usr_identify();
    CHK_PRT_RETURN(ret != 0, hccn_err("permission denied: only root user is allowed, ret:%d dev_id:%d",
        ret, ctx->dev_id), TOOL_PUBLIC_ROOT_UNSUPPORT);

    SET_PRODUCT_MSG(msg, &ctx->port_id, sizeof(int), NULL, 0);
    ret = product_host_device_channel(ctx, CMD_DUMP_REGS, &msg);
    if (ret) {
        hccn_err("dump regsiters failed. (ret=%d)", ret);
        return ret;
    }
    return 0;
}

static void tool_dump_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_dump_help(ctx, MODE_TEST);
            break;
        case MODE_TEST:
            TOOL_PRINT_CMD("-t", "-dump", "dump core registers");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}

static int tool_down_data_print_row(struct command_context *ctx, int row_idx,
    down_data_log_port_item_t item[DOWN_DATA_LOG_MAX])
{
    down_data_table_row_t table_data[LANE_NUMBER] = {0};
    int lane_idx, ret;
    TOOL_PRINT_INFO("down data of udie %d port %d - log row %d:\n",
                    ctx->udie_id, ctx->port_id, row_idx);

    if (row_idx >= DOWN_DATA_LOG_MAX) {
        return EINVAL;
    }
    for (lane_idx = 0; lane_idx < LANE_NUMBER; lane_idx++) {
        table_data[lane_idx].lane = lane_idx;
        table_data[lane_idx].snr_metric = item[row_idx].data[lane_idx].snr.snr_metric;
        table_data[lane_idx].metric_his_min = item[row_idx].data[lane_idx].snr.metric_his_min;
        table_data[lane_idx].err_avg = item[row_idx].data[lane_idx].snr.err_avg;
        table_data[lane_idx].cycles_avg = item[row_idx].data[lane_idx].snr.cycles_avg;
        table_data[lane_idx].heh_avg = item[row_idx].data[lane_idx].snr.heh_avg;
        table_data[lane_idx].c3_ud_2csr = item[row_idx].data[lane_idx].rx_ffe_cfg.c3_ud_2csr;
        table_data[lane_idx].c5_ud_2csr = item[row_idx].data[lane_idx].rx_ffe_cfg.c5_ud_2csr;
    }

    ret = print_table_by_input(table_data, LANE_NUMBER, sizeof(down_data_table_row_t));
    if (ret) {
        hccn_err("print row %d failed.(ret=%d)\n", row_idx, ret);
        return ret;
    }
    return 0;
}

static int tool_down_data_exec(struct command_context *ctx)
{
    if (ctx == NULL) {
        hccn_err("tool_down_data_exec: ctx pointer is NULL");
        return EINVAL;
    }
    int row_idx, log_idx = 0, ret, max_valid_rows = 0;
    down_data_log_port_item_t data[DOWN_DATA_LOG_MAX] = {0};
    struct product_channel_msg msg = {0};
    bool has_valid_data = false;
    struct table_header_t down_data_header[] = {
        {"lane", TYPE_INT},
        {"snr_metric", TYPE_INT},
        {"metric_his_min", TYPE_INT},
        {"err_avg", TYPE_INT},
        {"cycles_avg", TYPE_INT},
        {"heh_avg", TYPE_INT},
        {"c3_ud_2csr", TYPE_UINT},
        {"c5_ud_2csr", TYPE_UINT}
    };

    SET_PRODUCT_MSG(msg, NULL, 0, &data, sizeof(data));
    ret = product_host_device_channel(ctx, CMD_GET_DOWN_DATA, &msg);
    if (ret) {
        hccn_err("get down data failed.(ret=%d)", ret);
        return ret;
    }

    ret = init_table_t(ARRAY_SIZE_COMPUTE(down_data_header), down_data_header);
    if (ret) {
        hccn_err("init table failed.(ret=%d)", ret);
        return ret;
    }

    if (data[log_idx].times > 0) {
        has_valid_data = true;
        max_valid_rows = data[log_idx].times;
    }

    if (!has_valid_data) {
        TOOL_PRINT_INFO("udie %d port %d: no down data\n", ctx->udie_id, ctx->port_id);
        return 0;
    }

    for (row_idx = 0; row_idx < max_valid_rows; row_idx++) {
        ret = tool_down_data_print_row(ctx, row_idx, data);
        if (ret) {
            hccn_err("tool_down_data_print_row failed.(ret=%d)", ret);
            return ret;
        }
    }
    return 0;
}

static void tool_down_data_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_down_data_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-down_data", "get information about link down event");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}

static int cmp_timestamp_desc(const void *a, const void *b)
{
    const time_stamp_entry *ta = (const time_stamp_entry *)a;
    const time_stamp_entry *tb = (const time_stamp_entry *)b;
    if (ta->time_stamp > tb->time_stamp) {
        return -1;
    }

    if (ta->time_stamp < tb->time_stamp) {
        return 1;
    }

    return 0;
}

int timestamp_to_str(unsigned int timestamp, char *time_str, size_t buf_size)
{
    if (time_str == NULL || buf_size == 0) {
        return -EINVAL;
    }

    time_t t = (time_t)timestamp;
    struct tm *tm_info = gmtime(&t);
    if (tm_info == NULL) {
        time_str[0] = '\0';
        return -EINVAL;
    }

    size_t ret = strftime(time_str, buf_size, "%a %b %d %H:%M:%S %Y", tm_info);
    if (ret == 0) {
        time_str[0] = '\0';
        return -EINVAL;
    }

    return 0;
}

int parse_link_records(link_info_data *trans_data, struct link_stat_data *records, struct command_context *ctx)
{
    /* 1. 收集所有有效时间戳 */
    time_stamp_entry entries[LINK_STAT_MAX_IDX * 2];
    int count = 0, ret = 0;

    for (int i = 0; i < LINK_STAT_MAX_IDX; i++) {
        if (trans_data->up_timestamp[i] != 0) {
            entries[count].time_stamp = trans_data->up_timestamp[i];
            ret = strcpy_s(entries[count].link_status, sizeof(entries[count].link_status), LINK_UP_STR);
            if (ret != 0) {
                hccn_err("Copy link up str failed.(ret=%d)", ret);
                return -EINVAL;
            }
            count++;
        }
        if (trans_data->down_timestamp[i] != 0) {
            entries[count].time_stamp = trans_data->down_timestamp[i];
            ret = strcpy_s(entries[count].link_status, sizeof(entries[count].link_status), LINK_DOWN_STR);
            if (ret != 0) {
                hccn_err("Copy link down str failed.(ret=%d)", ret);
                return -EINVAL;
            }
            count++;
        }
    }

    if (count == 0) {
        return 0;   /* 没有记录 */
    }

    /* 2. 按时间戳降序排序 */
    qsort(entries, count, sizeof(time_stamp_entry), cmp_timestamp_desc);

    /* 3. 填充输出数组 */
    int out_count = (count < LINK_STAT_MAX_IDX) ? count : LINK_STAT_MAX_IDX;
    for (int i = 0; i < out_count; i++) {
        ret = strcpy_s(records[i].link_status, sizeof(records[i].link_status), entries[i].link_status);
        if (ret != 0) {
            hccn_err("Copy link status failed.(ret=%d)", ret);
            return -EINVAL;
        }

        records[i].logic_id = (unsigned int)ctx->npu_info.logic_id;
        records[i].udie_id = (unsigned int)ctx->udie_id;
        records[i].port_id = (unsigned int)ctx->port_id;

        ret = timestamp_to_str(entries[i].time_stamp, records[i].time, TIME_MAX_LEN);
        if (ret != 0) {
            hccn_err("timestamp_to_str failed.(ret=%d)", ret);
            return -EINVAL;
        }
    }

    return out_count;
}

int tool_link_stat_exec(struct command_context *ctx)
{
    int ret, cnt;
    struct product_channel_msg msg = {0};
    struct link_stat_data data[LINK_STAT_MAX_ROW_NUM] = {0};
    link_info_data trans_data = {0};

    // 下发数据
    SET_PRODUCT_MSG(msg, NULL, 0, &trans_data, sizeof(link_info_data));
    ret = product_host_device_channel(ctx, CMD_LINK_STAT_OPERATE, &msg);
    if (ret) {
        hccn_err("link_stat failed. (ret:%d)", ret);
        return ret;
    }

    // print link cnt info
    PRINT("link up count : %d\nlink down count : %d\n", (int)trans_data.link_up_cnt, (int)trans_data.link_down_cnt);

    // 解析数据
    cnt = parse_link_records(&trans_data, data, ctx);
    if (cnt < 0 || cnt > LINK_STAT_MAX_ROW_NUM) {
        hccn_err("parse link records failed. (cnt:%d)", cnt);
        return cnt;
    }

    // print table info
    init_table(LINK_PRINT_COL, "NPU", TYPE_UINT, "UDie", TYPE_UINT, "Port", TYPE_UINT,
               "Link_Status", TYPE_CHARS, "Time_Stamp", TYPE_CHARS);
    prepare_table_pack(sizeof(struct link_stat_data), &data[0].logic_id, &data[0].udie_id, &data[0].port_id,
                       &data[0].link_status, &data[0].time);
    print_table_by_input(data, cnt, sizeof(struct link_stat_data));
    return 0;
}

static void tool_link_stat_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_link_stat_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-link_stat", "query history link status");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}

static const char *get_fec_rs_mode_str(int rs_mode)
{
    switch (rs_mode) {
        case FEC_MODE_BYPASS:
            return "Bypass";
        case FEC_MODE_128_T2:
            return "128 T2";
        case FEC_MODE_128_T4:
            return "128 T4";
        default:
            return "NA";  // 兼容未定义的数值
    }
}

static const char *get_fec_auto_mode_str(int auto_mode)
{
    switch (auto_mode) {
        case FEC_MODE_STATIC:
            return "Static";
        case FEC_MODE_TRENDS:
            return "Trends";
        default:
            return "NA";
    }
}

static const char *get_fec_itlv_mode_str(int itlv_mode)
{
    switch (itlv_mode) {
        case FEC_MODE_INTERWEAVE:
            return "Interweave";
        case FEC_MODE_UNINTERWEAVE:
            return "Uninterweave";
        default:
            return "NA";
    }
}

static const char *get_eth_fec_rs_mode_str(int rs_mode)
{
    switch (rs_mode) {
        case FEC_MODE_NO_FEC:
            return "no-fec";
        case FEC_MODE_RSFEC_2:
            return "RSFEC_MODE2";
        case FEC_MODE_RSFEC_3:
            return "RSFEC_MODE3";
        case FEC_MODE_RSFEC_5:
            return "RSFEC_MODE5";
        default:
            return "NA";
    }
}

// 填充表格数据
static int fill_fec_table_data(struct fec_query_cmdq_req_t *fec_req)
{
    int table_ret = 0;
    if (fec_req->mode == NPU_PORT_UBOE) {
        table_ret += SET_TABLE(0, "rs_mode", "%s", get_eth_fec_rs_mode_str(fec_req->fec_cfg.eth_fec_mode_cfg.rs_mode));
        table_ret += SET_TABLE(0, "auto_change_mode", "%s", "NA");
        table_ret += SET_TABLE(0, "itlv_mode", "%s", "NA");
    } else {
        table_ret += SET_TABLE(0, "rs_mode", "%s", get_fec_rs_mode_str(fec_req->fec_cfg.ub_fec_mode_cfg.rs_mode));
        table_ret += SET_TABLE(0, "auto_change_mode", "%s",
                               get_fec_auto_mode_str(fec_req->fec_cfg.ub_fec_mode_cfg.auto_change_mode));
        table_ret += SET_TABLE(0, "itlv_mode", "%s", get_fec_itlv_mode_str(fec_req->fec_cfg.ub_fec_mode_cfg.itlv_mode));
    }
    return table_ret;
}

// FEC查询命令的执行函数
static int tool_fec_exec(struct command_context *ctx)
{
    int ret = 0;
    int table_ret = 0;
    struct product_channel_msg msg = {0};
    struct fec_query_cmdq_req_t fec_req = {0};
    fec_req.port_id = ctx->port_id;
    struct table_header_t header[] = {
        {"rs_mode", TYPE_CHARS, 16},
        {"auto_change_mode", TYPE_CHARS, 16},
        {"itlv_mode", TYPE_CHARS, 16},
    };

    SET_PRODUCT_MSG(msg, &fec_req, sizeof(fec_req), &fec_req, sizeof(fec_req));
    ret = product_host_device_channel(ctx, CMDQ_FEC_QUERY_CMD, &msg);
    if (ret != 0) {
        hccn_err("FEC query failed. (ret=%d)", ret);
        return ret;
    }

    ret = malloc_table_prefix_t(DEV_PORT_TYPE, 1, ARRAY_SIZE_COMPUTE(header), header);
    if (ret != 0) {
        hccn_err("alloc table show fec failed. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    table_ret = SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->udie_id, ctx->port_id, NULL, NULL, NULL);
    if (table_ret != 0) {
        hccn_err("set entire row failed. (ret=%d)", table_ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    table_ret = fill_fec_table_data(&fec_req);
    if (table_ret != 0) {
        hccn_err("write table show fec failed. ret=%d", table_ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

// FEC命令的帮助打印函数
void tool_fec_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_fec_help(ctx, MODE_GET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-fec", "check fec info");
            tool_print_npu_info(DEV_PORT_TYPE);
            break;
        default:
            break;
    }
}


STATIC struct sub_option_entry ub_ping_opts_param[] = {
    {"-pkt", ARG_TYPE_INT, parse_int, MODE_TEST, 0, true, .range.int_range = {0, 4046}},
    {"-cnt", ARG_TYPE_INT, parse_int, MODE_TEST, 0, true, .range.int_range = {1, 1000}},
    {"-interval", ARG_TYPE_INT, parse_int, MODE_TEST, 0, true, .range.int_range = {0, 10000}},
    {"-src_eid", ARG_TYPE_STR, parse_str, MODE_TEST, MODE_TEST},
    {"-dst_eid", ARG_TYPE_STR, parse_str, MODE_TEST, MODE_TEST},
};

STATIC void get_ub_ping_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    *sub_opts = ub_ping_opts_param;
    *count = ARRAY_SIZE_COMPUTE(ub_ping_opts_param);
}

STATIC void *alloc_ub_ping_args_init(void)
{
    // Use IPv4 address by default
    struct ub_ping_operate *ub_ping_args = (struct ub_ping_operate *)calloc(1, sizeof(struct ub_ping_operate));
    if (ub_ping_args == NULL) {
        hccn_err("Failed to alloc ub_ping_args.");
        return NULL;
    }
    ub_ping_args->pkt_size = DEFAULT_PKT_SIZE;
    ub_ping_args->timeout = DEFAULT_TIMEOUT_TIME;
    ub_ping_args->pkt_send_num = DEFAULT_PKT_SEND_NUM;
    ub_ping_args->pkt_interval = DEFAULT_PKT_INTERVAL;
    return (void *)ub_ping_args;
}

STATIC int ub_ping_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct ub_ping_operate *ub_ping_args = (struct ub_ping_operate *)args;
    int ret = 0;

    if (strcmp(opt->name, "-src_eid") == 0) {
        ret = memcpy_s(ub_ping_args->ub_pair_info.src_addr, MAX_IP_VAL_LEN, type_val->str_val, MAX_IP_VAL_LEN);
    } else if (strcmp(opt->name, "-dst_eid") == 0) {
        ret = memcpy_s(ub_ping_args->ub_pair_info.dst_addr, MAX_IP_VAL_LEN, type_val->str_val, MAX_IP_VAL_LEN);
    } else if (strcmp(opt->name, "-pkt") == 0) {
        ub_ping_args->pkt_size = type_val->int_val;
    } else if (strcmp(opt->name, "-cnt") == 0) {
        ub_ping_args->pkt_send_num = type_val->int_val;
    } else if (strcmp(opt->name, "-interval") == 0) {
        ub_ping_args->pkt_interval = type_val->int_val;
    } else {
        return -EINVAL;
    }

    return ret;
}

STATIC void tool_ub_ping_print_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_ub_ping_print_help(ctx, MODE_TEST);
            break;
        case MODE_TEST:
            TOOL_PRINT_CMD("-t", "-ub_ping", "ICMP ping test");
            tool_print_npu_info(DEV_NPU_ATTR);
            TOOL_PRINT_OPT("-src_eid <src_eid>", "net detect source EID, such as x:x:x:x:x:x:x:x");
            TOOL_PRINT_OPT("-dst_eid <dst_eid>", "net detect destination EID");
            TOOL_PRINT_OPT("[-pkt <size>]", "the packet data length, default 4046 Byte, range [0, 4046] Byte");
            TOOL_PRINT_OPT("[-cnt <size>]", "the packet count, default 3, range [1, 1000]");
            TOOL_PRINT_OPT("[-interval <size>]", "the packet interval, default 1000 ms, range [0, 10000] ms");
            break;
        default:
            break;
    }
}

STATIC int tool_ub_ping_exec(struct command_context *ctx)
{
    struct ub_ping_operate *ping_args = NULL;
    struct ub_ping_result ping_result = {0};
    ping_args = (struct ub_ping_operate *)ctx->cmd_args;
    int ret;
    ping_args->ub_pair_num = 1;
    // 指定inbuf inlen outbuf outlen

    TOOL_PRINT_INFO("device %d EID %s to %s", ctx->npu_info.logic_id, ping_args->ub_pair_info.src_addr,
        ping_args->ub_pair_info.dst_addr);
    ret = dsmi_get_ub_ping_info(ctx, ping_args, &ping_result, true);
    if (ret != 0) {
        return DRV_ERROR_SEND_MESG;
    }
    TOOL_PRINT_INFO("%d packets transmitted, %u received, %.2f%% packet loss", ping_args->pkt_send_num,
        ping_result.suc_pkt_num, (float)ping_result.fail_pkt_num / ping_args->pkt_send_num * CHANGE_TO_PERCENT);
    if (ping_result.suc_pkt_num != 0) {
        TOOL_PRINT_INFO("max time %ld.%06ldms", ping_result.max_time / NS_CHANGE_TO_US,
            (ping_result.max_time % NS_CHANGE_TO_US) * NS_CHANGE_TO_US);
        TOOL_PRINT_INFO("min time %ld.%06ldms", ping_result.min_time / NS_CHANGE_TO_US,
            (ping_result.min_time % NS_CHANGE_TO_US) * NS_CHANGE_TO_US);
        TOOL_PRINT_INFO("average time %ld.%06ldms", ping_result.avg_time / NS_CHANGE_TO_US,
            (ping_result.avg_time % NS_CHANGE_TO_US) * NS_CHANGE_TO_US);
        TOOL_PRINT_INFO("TP95 time %ld.%06ldms", ping_result.tp95_time / NS_CHANGE_TO_US,
            (ping_result.tp95_time % NS_CHANGE_TO_US) * NS_CHANGE_TO_US);
    }
    return 0;
}

STATIC int tool_write_send_arp_cfg(struct command_context *ctx)
{
    int ret = 0;
    arp_param_t *param = (arp_param_t *)ctx->cmd_args;

    if (param->enable != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "arp_enable", sizeof("arp_enable"), param->enable);
        if (ret != 0) {
            return ret;
        }
    }

    if (param->period != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "arp_period", sizeof("arp_period"), param->period);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

static int tool_get_send_arp(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    arp_param_t result = {0};

    SET_PRODUCT_MSG(msg, NULL, 0, &result, sizeof(arp_param_t));
    ret = product_host_device_channel(ctx, CMD_GET_SEND_ARP, &msg);
    if (ret != 0) {
        hccn_err("get send arp failed. (ret=%d)", ret);
        return ret;
    }

    struct table_header_t header[] = {
        {"Status", TYPE_STR,  8},
        {"Period", TYPE_UINT, 6}
    };

    if (malloc_table_prefix_t(DEV_DEV_ATTR, 1, ARRAY_SIZE_COMPUTE(header), header) != 0) {
        hccn_err("alloc table show send arp failed.");
        return TOOL_TABLE_ERROR;
    }

    ret = SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->dev_name,
        (result.enable == 0 ? "disable" : "enable"), result.period);
    if (ret != 0) {
        hccn_err("write table show send arp failed. (ret=%d)", ret);
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

int tool_set_send_arp(struct command_context *ctx)
{
    struct product_channel_msg msg = {0};
    struct ip_netmask_val ip_netmask;
    struct dsmi_info info = {0};
    unsigned int size;
    int ret = 0;

    if (ctx->cmd_args == NULL) {
        hccn_err("ctx->cmd_args is NULL");
        return TOOL_PRIVATE_ARGS_NUM_ERR;
    }
    arp_param_t *param = (arp_param_t *)ctx->cmd_args;

    // 获取ip
    size = sizeof(struct ip_netmask_val);
    DSMI_FILL_INFO(info, (char *)ctx, sizeof(struct command_context), NULL, 0, (char *)&ip_netmask, &size);

    ret = dsmi_exe_get_info(ctx->npu_info.logic_id, DS_GET_IP, &info);
    if (ret != 0) {
        hccn_err("get ip info failed. (ret=%d)", ret);
        return ret; // 未查询到ip，内部会返回 DEV_EXE_IP_ADDRESS_NOT_PRESET_ERR
    }

    ret = tool_ipv4_int_to_str(ip_netmask.ip, param->ip_addr, MAX_IP_VAL_LEN);
    if (ret != 0) {
        hccn_err("ipv4_int_to_str failed. (ret=%d; ip=0x%x)", ret, ip_netmask.ip);
        return ret;
    }

    SET_PRODUCT_MSG(msg, param, sizeof(arp_param_t), NULL, 0);

    ret = product_host_device_channel(ctx, CMD_SET_SEND_ARP, &msg);
    if (ret != 0) {
        hccn_err("set send arp failed. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

static int tool_send_arp_exec(struct command_context *ctx)
{
    int ret = 0;

    // 检查是否为UBoE mainboard，此命令仅支持UBoE设备
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_err("send arp command only supports UBoE devices. (mainboard_id=0x%x)", ctx->npu_info.mainboard_id);
        TOOL_PRINT_ERR("The command is not supported on this product.");
        return TOOL_UNSUPPORT_BOARD;
    }

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    if (ctx->mode == MODE_GET) {
        return tool_get_send_arp(ctx);
    } else { // MODE_SET
        ret = tool_set_send_arp(ctx);
        if (ret != 0) {
            return ret;
        }

        ret = tool_write_send_arp_cfg(ctx);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

void get_send_arp_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry arp_param_list[] = {
        {"-enable", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {0, 1}},
        {"-period", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {1, 3600}}, // max period 3600s
    };
    *sub_opts = arp_param_list;
    *count = ARRAY_SIZE_COMPUTE(arp_param_list);
}

void *alloc_send_arp_args_init(void)
{
    arp_param_t *param = calloc(1, sizeof(arp_param_t));
    if (!param) {
        return NULL;
    }
    param->enable = PARAM_INVALID;
    param->period = PARAM_INVALID;
    return param;
}

int send_arp_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    arp_param_t *param = (arp_param_t *)args;
    if (strcmp(opt->name, "-enable") == 0) {
        param->enable = (unsigned int)type_val->int_val;
    } else if (strcmp(opt->name, "-period") == 0) {
        param->period = (unsigned int)type_val->int_val;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

static void tool_send_arp_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_send_arp_help(ctx, MODE_GET);
            tool_send_arp_help(ctx, MODE_SET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-send_arp", "get the setting of gratuitous arp");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-send_arp", "set the setting of gratuitous arp");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-enable <0/1>]", "set the ability of the gratuitous arp, 0: disable, 1: enable.");
            TOOL_PRINT_OPT("[-period <period>]", "set the period of the gratuitous arp, default 60 s,"
                           " range [1, 3600] (s).");
            break;
        default:
            break;
    }
}

void get_pfc_stat_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry pfc_param_list[] = {
        {"-clear", ARG_TYPE_NONE, parse_none, MODE_SET, MODE_SET},
    };
    *sub_opts = pfc_param_list;
    *count = ARRAY_SIZE_COMPUTE(pfc_param_list);
}
 
void *alloc_pfc_stat_args(void)
{
    struct pfc_time_t *data = calloc(1, sizeof(struct pfc_time_t));
    if (!data) {
        hccn_err("pfc_time_t failed to allocate memory.");
        return NULL;
    }
    return data;
}
 
int pfc_stat_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    if (strcmp(opt->name, "-clear") != 0) {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}
 
static void tool_pfc_stat_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_pfc_stat_help(ctx, MODE_GET);
            tool_pfc_stat_help(ctx, MODE_SET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-pfc_stat", "get the pfc all priorities pause duration");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-pfc_stat", "set the pfc all priorities pause duration");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("-clear", "clear the pfc all priorities pause duration");
            break;
        default:
            break;
    }
}

static int fill_pfc_stat_table(struct command_context *ctx, struct pfc_stat_info_t *pfc_info, int type)
{
    int i, ret = 0, table_row = 0;
    unsigned int *warn_cnt0 = NULL;
    unsigned int *warn_cnt1 = NULL;
    unsigned int *err_cnt0 = NULL;
    unsigned int *err_cnt1 = NULL;
    unsigned long long *times0 = NULL;
    unsigned long long *times1 = NULL;
    
    if (type == PFC_RX) {
        times0 = pfc_info[SLAVE_NAME_IDX0].pfc_time.pfc_rx;
        times1 = pfc_info[SLAVE_NAME_IDX1].pfc_time.pfc_rx;
        warn_cnt0 = pfc_info[SLAVE_NAME_IDX0].pfc_count.pfc_rx_warn_cnt;
        warn_cnt1 = pfc_info[SLAVE_NAME_IDX1].pfc_count.pfc_rx_warn_cnt;
        err_cnt0 = pfc_info[SLAVE_NAME_IDX0].pfc_count.pfc_rx_err_cnt;
        err_cnt1 = pfc_info[SLAVE_NAME_IDX1].pfc_count.pfc_rx_err_cnt;
    } else {
        times0 = pfc_info[SLAVE_NAME_IDX0].pfc_time.pfc_tx;
        times1 = pfc_info[SLAVE_NAME_IDX1].pfc_time.pfc_tx;
        warn_cnt0 = pfc_info[SLAVE_NAME_IDX0].pfc_count.pfc_tx_warn_cnt;
        warn_cnt1 = pfc_info[SLAVE_NAME_IDX1].pfc_count.pfc_tx_warn_cnt;
        err_cnt0 = pfc_info[SLAVE_NAME_IDX0].pfc_count.pfc_tx_err_cnt;
        err_cnt1 = pfc_info[SLAVE_NAME_IDX1].pfc_count.pfc_tx_err_cnt;
    }

    for (i = 0; i < MAX_PRI_NUM; i++) {
        ret += SET_ENTIRE_ROW(table_row, ctx->dev_id, pfc_info[SLAVE_NAME_IDX0].slave_name,
                              i, times0[i], warn_cnt0[i], err_cnt0[i]);
        table_row++;
    }
    for (i = 0; i < MAX_PRI_NUM; i++) {
        ret += SET_ENTIRE_ROW(table_row, ctx->dev_id, pfc_info[SLAVE_NAME_IDX1].slave_name,
                              i, times1[i], warn_cnt1[i], err_cnt1[i]);
        table_row++;
    }
    return ret;
}

static int print_pfc_stat_table(struct command_context *ctx, struct pfc_stat_info_t *pfc_info, int type)
{
    int ret = 0, col_num = MAX_PRI_NUM * BOND_SLAVE_NUM;

    struct table_header_t rx_header[] = {
        {"Pfc_index",               TYPE_INT},
        {"Rx_duration_time(ms)",    TYPE_INT},
        {"Rx_duration_warn_cnt",    TYPE_INT},
        {"Rx_duration_err_cnt",     TYPE_INT},
    };
    struct table_header_t tx_header[] = {
        {"Pfc_index",               TYPE_INT},
        {"Tx_duration_time(ms)",    TYPE_INT},
        {"Tx_duration_warn_cnt",    TYPE_INT},
        {"Tx_duration_err_cnt",     TYPE_INT},
    };

    if (type == PFC_RX) {
        ret = malloc_table_prefix_t(DEV_DEV_ATTR, col_num, ARRAY_SIZE_COMPUTE(rx_header), rx_header);
    } else {
        ret = malloc_table_prefix_t(DEV_DEV_ATTR, col_num, ARRAY_SIZE_COMPUTE(tx_header), tx_header);
    }
    if (ret != 0) {
        hccn_err("alloc table show pfc_stat(%s) failed.", (type == PFC_RX) ? "Rx" : "Tx");
        return TOOL_TABLE_ERROR;
    }
    ret = fill_pfc_stat_table(ctx, pfc_info, type);
    if (ret != 0) {
        hccn_err("Failed to write to the pfc_stat(%s) table.", (type == PFC_RX) ? "Rx" : "Tx");
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return ret;
}

static int tool_pfc_stat_exec(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct pfc_stat_info_t pfc_info[BOND_SLAVE_NUM] = {0};

    // 检查是否为UBoE mainboard，此命令仅支持UBoE设备
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_err("pfc stat command only supports UBoE devices. (mainboard_id=0x%x)", ctx->npu_info.mainboard_id);
        TOOL_PRINT_ERR("The command is not supported on this product.");
        return TOOL_UNSUPPORT_BOARD;
    }

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    if (ctx->mode == MODE_GET) {
        SET_PRODUCT_MSG(msg, NULL, 0, pfc_info, sizeof(pfc_info));
        ret = product_host_device_channel(ctx, CMD_GET_PFC_STAT, &msg);
        if (ret != 0) {
            hccn_err("Failed to obtain the pfc_stat backpressure time. (ret=%d)", ret);
            return ret;
        }
        ret = print_pfc_stat_table(ctx, pfc_info, PFC_TX);
        if (ret != 0) {
            return ret;
        }
        ret = print_pfc_stat_table(ctx, pfc_info, PFC_RX);
        if (ret != 0) {
            return ret;
        }
    } else {
        SET_PRODUCT_MSG(msg, NULL, 0, NULL, 0);
        ret = product_host_device_channel(ctx, CMD_SET_PFC_STAT, &msg);
        if (ret != 0) {
            hccn_err("Failed to clear the pfc_stat backpressure statistics. (ret=%d)", ret);
            return ret;
        }
    }

    return 0;
}

void get_pfc_storm_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count)
{
    static struct sub_option_entry param_list[] = {
        {"-mode", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {0, 1}},
        {"-close_time", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {0, 100}},
        {"-detect_period", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {10, 100}},
        {"-warn_thrd", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {40, 80}},
        {"-err_thrd", ARG_TYPE_INT, parse_int, MODE_SET, 0, true, .range.int_range = {60, 100}},
    };
    *sub_opts = param_list;
    *count = ARRAY_SIZE_COMPUTE(param_list);
}
 
void *alloc_pfc_storm_args(void)
{
    struct pfc_storm_t *data = calloc(1, sizeof(struct pfc_storm_t));
    if (data == NULL) {
        hccn_err("pfc_storm_t failed to allocate memory.");
        return NULL;
    }
    data->detect_period = PARAM_INVALID;
    data->close_time = PARAM_INVALID;
    data->warn_thrd = PARAM_INVALID;
    data->err_thrd = PARAM_INVALID;
    data->mode = PARAM_INVALID;
    return data;
}

int pfc_storm_assign(void *args, struct sub_option_entry *opt, value_union *type_val)
{
    struct pfc_storm_t *data = (struct pfc_storm_t *)args;
    if (strcmp(opt->name, "-mode") == 0) {
        data->mode = (unsigned char)(type_val->int_val & 0xFF);
    } else if (strcmp(opt->name, "-close_time") == 0) {
        data->close_time = type_val->int_val;
    } else if (strcmp(opt->name, "-detect_period") == 0) {
        data->detect_period = type_val->int_val;
    } else if (strcmp(opt->name, "-warn_thrd") == 0) {
        data->warn_thrd = type_val->int_val;
    } else if (strcmp(opt->name, "-err_thrd") == 0) {
        data->err_thrd = type_val->int_val;
    } else {
        return TOOL_ASSIGN_UNKNOWN;
    }
    return 0;
}

STATIC int tool_write_pfc_storm_cfg(struct command_context *ctx)
{
    int ret = 0;
    struct pfc_storm_t *info = (struct pfc_storm_t *)ctx->cmd_args;

    if (info->close_time != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "pfc_close_time", sizeof("pfc_close_time"), info->close_time);
        if (ret != 0) {
            return ret;
        }
    }

    if (info->detect_period != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "pfc_detect_period", sizeof("pfc_detect_period"), info->detect_period);
        if (ret != 0) {
            return ret;
        }
    }

    if (info->warn_thrd != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "pfc_warn_thrd", sizeof("pfc_warn_thrd"), info->warn_thrd);
        if (ret != 0) {
            return ret;
        }
    }

    if (info->err_thrd != PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "pfc_err_thrd", sizeof("pfc_err_thrd"), info->err_thrd);
        if (ret != 0) {
            return ret;
        }
    }

    if (info->mode != (unsigned char)PARAM_INVALID) {
        ret = tool_write_conf_comm_uint(ctx, "pfc_mode", sizeof("pfc_mode"), (unsigned int)info->mode);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

static int print_pfc_storm_table(struct command_context *ctx, struct pfc_storm_t *result, int type)
{
    int ret = 0;
    struct table_header_t rx_header[] = {
        {"Rx_mode",                 TYPE_STR,  8}, // 8位存储
        {"Rx_close_time(ms)",       TYPE_INT},
        {"Rx_detect_period(ms)",    TYPE_INT},
        {"Rx_warn_threshold(%)",    TYPE_INT},
        {"Rx_err_threshold(%)",     TYPE_INT},
    };
    struct table_header_t tx_header[] = {
        {"Tx_mode",                 TYPE_STR,  8}, // 8位存储
        {"Tx_close_time(ms)",       TYPE_INT},
        {"Tx_detect_period(ms)",    TYPE_INT},
        {"Tx_warn_threshold(%)",    TYPE_INT},
        {"Tx_err_threshold(%)",     TYPE_INT},
    };

    if (type == PFC_RX) {
        ret = malloc_table_prefix_t(DEV_DEV_ATTR, 1, ARRAY_SIZE_COMPUTE(rx_header), rx_header);
    } else {
        ret = malloc_table_prefix_t(DEV_DEV_ATTR, 1, ARRAY_SIZE_COMPUTE(tx_header), tx_header);
    }
    if (ret != 0) {
        hccn_err("alloc table show pfc_storm(%s) failed.", (type == PFC_RX) ? "rx" : "tx");
        return TOOL_TABLE_ERROR;
    }

    // 填充数据，门限数据从IMP读的是实际的时间，此处输出需要转化为百分比
    ret = SET_ENTIRE_ROW(0, ctx->npu_info.logic_id, ctx->dev_name, (result->mode == 0 ? "disable" : "enable"),
        result->close_time, result->detect_period, result->warn_thrd * ONE_HUNDRED_PERCENT / result->detect_period,
        result->err_thrd * ONE_HUNDRED_PERCENT / result->detect_period);
    if (ret != 0) {
        hccn_err("Failed to write to the pfc_storm(%s) table.",  (type == PFC_RX) ? "rx" : "tx");
        clean_table();
        return TOOL_TABLE_ERROR;
    }

    print_table();
    clean_table();
    return 0;
}

static int tool_verify_pfc_storm_param(struct pfc_storm_t *preinfo, struct pfc_storm_t *info)
{
    if (preinfo->close_time == PARAM_INVALID) {
        preinfo->close_time = info->close_time;
    } else {
        preinfo->close_time = preinfo->close_time * PFC_TIME_UNITS;
    }
    if (preinfo->detect_period == PARAM_INVALID) {
        preinfo->detect_period = info->detect_period;
    } else {
        preinfo->detect_period = preinfo->detect_period * PFC_TIME_UNITS;
    }
    // 门限数据IMP需要的是实际的时间，此处把百分比转化为实际的时间
    if (preinfo->warn_thrd == PARAM_INVALID) {
        preinfo->warn_thrd = info->warn_thrd * ONE_HUNDRED_PERCENT / info->detect_period;
    }
    preinfo->warn_thrd = preinfo->warn_thrd * preinfo->detect_period / ONE_HUNDRED_PERCENT;
    if (preinfo->err_thrd == PARAM_INVALID) {
        preinfo->err_thrd = info->err_thrd * ONE_HUNDRED_PERCENT / info->detect_period;
    }
    preinfo->err_thrd = preinfo->err_thrd * preinfo->detect_period / ONE_HUNDRED_PERCENT;
    if (preinfo->mode == (unsigned char)PARAM_INVALID) {
        preinfo->mode = info->mode;
    }

    if (preinfo->warn_thrd >= preinfo->err_thrd) {
        return PFC_THRD_ERR;
    }

    if (preinfo->close_time > preinfo->detect_period) {
        return PFC_TIME_ERR;
    }

    return 0;
}

int tool_set_pfc_storm(struct command_context *ctx, struct pfc_storm_info_t *info)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct pfc_storm_t param;

    if (ctx->cmd_args == NULL) {
        hccn_err("Setting the pfc_storm parameter to null.");
        return TOOL_PRIVATE_ARGS_NUM_ERR;
    }

    ret = memcpy_s(&param, sizeof(struct pfc_storm_t), ctx->cmd_args, sizeof(struct pfc_storm_t));
    if (ret != 0) {
        hccn_err("memcpy_s failed.");
        return -EINVAL;
    }

    ret = tool_verify_pfc_storm_param(&param, &info->pfc_storm_rx); // rx与tx配置相同，只需检查一侧
    if (ret != 0) {
        return ret;
    }

    info->pfc_storm_rx = param;
    info->pfc_storm_tx = param;
    info->pfc_storm_rx.dir = PFC_RX;
    info->pfc_storm_tx.dir = PFC_TX;

    SET_PRODUCT_MSG(msg, info, sizeof(struct pfc_storm_info_t), NULL, 0);
    ret = product_host_device_channel(ctx, CMD_SET_PFC_STORM, &msg);
    if (ret != 0) {
        hccn_err("Set pfc_storm failed. (ret=%d)", ret);
    }

    return ret;
}

static int tool_get_pfc_storm(struct command_context *ctx, struct pfc_storm_info_t *info)
{
    int ret = 0;

    ret = print_pfc_storm_table(ctx, &info->pfc_storm_tx, PFC_TX);
    if (ret != 0) {
        hccn_err("Print pfc_storm TX table failed. (ret=%d)", ret);
        return ret;
    }

    ret = print_pfc_storm_table(ctx, &info->pfc_storm_rx, PFC_RX);
    if (ret != 0) {
        hccn_err("Print pfc_storm RX table failed. (ret=%d)", ret);
        return ret;
    }

    return ret;
}

int tool_pfc_storm_exec(struct command_context *ctx)
{
    int ret = 0;
    struct product_channel_msg msg = {0};
    struct pfc_storm_info_t info = {0};

    // 检查是否为UBoE mainboard，此命令仅支持UBoE设备
    if (!tool_is_uboe_mainboard(ctx->npu_info.mainboard_id)) {
        hccn_err("pfc storm command only supports UBoE devices. (mainboard_id=0x%x)", ctx->npu_info.mainboard_id);
        TOOL_PRINT_ERR("The command is not supported on this product.");
        return TOOL_UNSUPPORT_BOARD;
    }

    CHECK_BOND_DEV_RETURN(ctx->dev_name, ctx->slot_id);

    info.pfc_storm_tx.dir = PFC_TX;
    info.pfc_storm_rx.dir = PFC_RX;

    // 配置和查询都需要先获取一遍pfc信息
    SET_PRODUCT_MSG(msg, NULL, 0, &info, sizeof(struct pfc_storm_info_t));
    ret = product_host_device_channel(ctx, CMD_GET_PFC_STORM, &msg);
    if (ret != 0) {
        hccn_err("Get pfc_storm failed. (ret=%d)", ret);
        return ret;
    }

    if (ctx->mode == MODE_SET) {
        ret = tool_set_pfc_storm(ctx, &info);
        if (ret != 0) {
            if (ret == PFC_THRD_ERR) {
                TOOL_PRINT_ERR("Option -warn_thrd value must be less than -err_thrd value.");
                return TOOL_PRIVATE_ARGS_VALUE_ERR;
            } else if (ret == PFC_TIME_ERR) {
                TOOL_PRINT_ERR("Option -close_time value must be less than or equal to -detect_period value.");
                return TOOL_PRIVATE_ARGS_VALUE_ERR;
            }
            return ret;
        }

        ret = tool_write_pfc_storm_cfg(ctx);
        if (ret != 0) {
            return ret;
        }
    } else {
        return tool_get_pfc_storm(ctx, &info);
    }

    return 0;
}

static void tool_pfc_storm_help(struct command_context *ctx, unsigned int mode)
{
    switch (mode) {
        case MODE_ALL:
            tool_pfc_storm_help(ctx, MODE_GET);
            tool_pfc_storm_help(ctx, MODE_SET);
            break;
        case MODE_GET:
            TOOL_PRINT_CMD("-g", "-pfc_storm", "get the configuration parameters of the pfc storm watchdog");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            break;
        case MODE_SET:
            TOOL_PRINT_CMD("-s", "-pfc_storm", "set the configuration parameters of the pfc storm watchdog");
            tool_print_npu_info(DEV_DEV_ATTR);
            tool_print_dev_info(DEV_BOND_DEV);
            TOOL_PRINT_OPT("[-mode <mode>]", "the mode of the pfc storm watchdog, "
                           "default disable, 0: disable, 1: enable.");
            TOOL_PRINT_OPT("[-close_time <time>]", "duration of pfc storm watchdog automatic shutdown PFC, "
                           "default 5 * 100ms, range [0, 100] (100ms).");
            TOOL_PRINT_OPT("[-detect_period <time>]", "pfc storm watchdog detection period, "
                           "default 20 * 100ms, range [10, 100] (100ms).");
            TOOL_PRINT_OPT("[-warn_thrd <warn_thrd>]", "threshold value for PFC storm watchdog alarm, "
                           "default 25 %, range [40, 80] (%).");
            TOOL_PRINT_OPT("[-err_thrd <err_thrd>]", "threshold value of PFC storm watchdog reporting error, "
                           "default 50 %, range [60, 100] (%).");
            TOOL_PRINT_OPT(" ", "close_time <= detect_period, warn_thrd < err_thrd.");
            break;
        default:
            break;
    }
}

// cleancode: 只在一处函数中使用的全局变量应该放进函数内部。但这么做会导致函数超大
struct cmd_entry product_main_cmds[] = {
#ifdef DEBUG_MODE // 当前i2c功能仅内部使用，在release版本中不编译
    {
        "-i2c", get_i2c_sub_opts, MODE_TEST,
        alloc_i2c_args, i2c_assign, tool_i2c_exec,
        {DEV_DEV_ATTR}, tool_i2c_print_help,
    },
#endif
    {
        "-fec", NULL, MODE_GET,
        NULL, NULL, tool_fec_exec,
        {DEV_PORT_TYPE}, tool_fec_help,
    },
    {
        "-ub_connect", NULL, MODE_GET,
        NULL, NULL, tool_ub_connect_exec,
        {DEV_NPU_ATTR}, tool_ub_connect_help,
    },
    {
        "-ip_rule", get_ip_rule_sub_opts, MODE_BOTH,
        alloc_ip_rule_args, ip_rule_assign, tool_ip_rule_exec,
        {DEV_DEV_ATTR}, tool_ip_rule_print_help,
    },
    {
        "-ip_route", get_ip_route_sub_opts, MODE_BOTH,
        alloc_ip_route_args, ip_route_assign, tool_ip_route_exec,
        {DEV_DEV_ATTR}, tool_ip_route_print_help,
    },
    {
        "-adapt_status", NULL, MODE_GET,
        NULL, NULL, tool_adapt_status_exec,
        {DEV_PORT_TYPE}, tool_adapt_status_help,
    },
    {
        "-speed", NULL, MODE_GET,
        NULL, NULL, tool_speed_exec,
        {DEV_PORT_TYPE}, tool_speed_help,
    },
    {
        "-optical", get_optical_sub_opts, MODE_ALL,
        alloc_optical_args_init, optical_assign, tool_optical_exec,
        {DEV_NPU_ATTR, DEV_OPTICAL_ATTR, DEV_PORT_TYPE}, tool_optical_help,
    },
    {
        "-down_data", NULL, MODE_GET,
        NULL, NULL, tool_down_data_exec,
        {DEV_PORT_TYPE}, tool_down_data_help,
    },
    {
        "-serdes", NULL, MODE_GET,
        NULL, NULL, tool_serdes_exec,
        {DEV_PORT_TYPE}, tool_serdes_help,
    },
    {
        "-dump", NULL, MODE_TEST,
        NULL, NULL, tool_dump_exec,
        {DEV_PORT_TYPE}, tool_dump_help,
    },
    {
        "-link_stat", NULL, MODE_GET,
        NULL, NULL, tool_link_stat_exec,
        {DEV_PORT_TYPE}, tool_link_stat_help,
    },
    {
        "-su_ber", get_su_ber_sub_opts, MODE_ALL,
        alloc_su_ber_args, su_ber_assign, tool_su_ber_exec,
        {DEV_PORT_TYPE}, tool_su_ber_help,
    },
    {
        "-ub_ping", get_ub_ping_sub_opts, MODE_TEST,
        alloc_ub_ping_args_init, ub_ping_assign, tool_ub_ping_exec,
        {DEV_NPU_ATTR}, tool_ub_ping_print_help,
    },
    {
        "-udp", get_udp_sport_sub_opts, MODE_BOTH,
        alloc_udp_sport_args, udp_sport_assign, tool_udp_sport_exec,
        {DEV_DEV_ATTR}, tool_udp_sport_help,
    },
    {
        "-send_arp", get_send_arp_sub_opts, MODE_BOTH,
        alloc_send_arp_args_init, send_arp_assign, tool_send_arp_exec,
        {DEV_DEV_ATTR}, tool_send_arp_help,
    },
    {
        "-pfc_stat", get_pfc_stat_sub_opts, MODE_BOTH,
        alloc_pfc_stat_args, pfc_stat_assign, tool_pfc_stat_exec,
        {DEV_DEV_ATTR}, tool_pfc_stat_help,
    },
    {
        "-pfc_storm", get_pfc_storm_sub_opts, MODE_BOTH,
        alloc_pfc_storm_args, pfc_storm_assign, tool_pfc_storm_exec,
        {DEV_DEV_ATTR}, tool_pfc_storm_help,
    },
};

void tool_get_product_cmds(struct cmd_entry **cmds, unsigned int *count)
{
    *cmds = product_main_cmds;
    *count = sizeof(product_main_cmds) / sizeof(product_main_cmds[0]);
}

int tool_get_product_other_info(struct command_context *ctx)
{
    int ret;

    ret = dsmi_get_mainboard_id(ctx->dev_id, &ctx->npu_info.mainboard_id);
    if (ret != 0) {
        hccn_err("get mainboard id failed. (ret=%d)\n", ret);
        return ret;
    }

    return 0;
}
