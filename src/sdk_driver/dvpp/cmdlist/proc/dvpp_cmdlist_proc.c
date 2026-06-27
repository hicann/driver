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
#include "dvpp_cmdlist_proc.h"
#include "ka_type.h"
 
#include "ka_fs_pub.h"
#include "ka_base_pub.h"
#include "ka_define.h"
#include "ka_common_pub.h"
 
#include "securec.h"
#include "dvpp_cmdlist_log.h"
#include "dvpp_cmdlist_context.h"
#include "ka_compiler_pub.h"
 
#define PROC_NAME "dvpp_cmdlist"
#define PROC_BUF_LEN 128
 
static void disaply_time_cost(struct seq_file *m)
{
    uint16_t i = 0;
    dvpp_cmdlist_context *ctx = get_dvpp_cmdlist_ctx();
    time_cost_node* pos = NULL;
    ka_hlist_node_t* n = NULL;
    ka_hlist_head_t* head = NULL;
    ka_fs_seq_printf(m, "Time Cost Enable = %d\n", ctx->time_cost_stat.enable);
    ka_fs_seq_printf(m, "Time Cost Node Num = %d\n", ctx->time_cost_stat.node_num);
    ka_fs_seq_printf(m, "Time Cost Details(us):\n");
    ka_fs_seq_printf(m, "%10s"
        "%10s"
        "%18s"
        "%18s"
        "%18s"
        "%18s"
        "%18s"
        "\n",
        "[StreamId]", "[TaskId]", "[UsrCopyToKern]", "[Vmalloc]", "[DmaAlloc]", "[U2kMap]", "[PcieCopy]");
 
    ka_task_spin_lock(&ctx->time_cost_stat.splock);
    for (i = 0; i < ctx->time_cost_stat.node_num; i++) {
        head = &ctx->time_cost_stat.head[i];
        ka_hlist_for_each_entry_safe(pos, n, head, hlist) {
            ka_fs_seq_printf(m, "%10d"
                "%10d"
                "%18lld"
                "%18lld"
                "%18lld"
                "%18lld"
                "%18lld"
                "\n",
                pos->streamid,
                pos->taskid,
                pos->time_cost_usr_copy_to_kern,
                pos->time_cost_vmalloc,
                pos->time_cost_dma_alloc,
                pos->time_cost_u2k_map,
                pos->time_cost_pcie_copy);
        }
    }
    ka_task_spin_unlock(&ctx->time_cost_stat.splock);
}
 
static void clear_time_cost(void)
{
    uint16_t i = 0;
    time_cost_node* pos = NULL;
    ka_hlist_node_t* n = NULL;
    ka_hlist_head_t* head = NULL;
    dvpp_cmdlist_context *ctx = get_dvpp_cmdlist_ctx();
 
    ka_task_spin_lock(&ctx->time_cost_stat.splock);
    for (i = 0; i < MAX_TIME_COST_NODE_LEN; i++) {
        head = &ctx->time_cost_stat.head[i];
        ka_hlist_for_each_entry_safe(pos, n, head, hlist) {
            ka_hlist_del(&pos->hlist);
        }
    }
    ka_task_spin_unlock(&ctx->time_cost_stat.splock);
}
 
static int dvpp_cmdlist_proc_show(struct seq_file *m, void *v)
{
    ka_fs_seq_printf(m, "Welcome To Dvpp Cmldist Proc.\n");
    disaply_time_cost(m);
    ka_fs_seq_printf(m, "\n");
 
    return 0;
}
 
/* delete all blanks in a line */
static void strip_string(char * str, char *res)
{
    char *s = str;
    char *p = res;
    do {
        if (*s == '\n') {
            *s = '\0';
        }
        if (*s != ' ') {
            *p++ = *s;
        }
    } while (*s++ != '\0');
}
 
static int32_t str2num(const char* str, uint32_t *num)
{
    const uint32_t max_len = 8; // 先限制右边字符串长度为8，再转换
    uint32_t str_len = (uint32_t)ka_base_strlen(str); // right为等号右边的字符串
    char *endptr = NULL;
    if (str_len > max_len) {
        DVPP_CMDLIST_VPC_LOG_ERROR("the length of string %u cannot be larger than %u \n",
            str_len, max_len);
        return -1;
    }
 
    *num = (uint32_t)(ka_base_simple_strtoul(str, &endptr, 10)); // 转化成10进制
    if ((uint32_t)(((uintptr_t)endptr - (uintptr_t)str)) != str_len) {
        DVPP_CMDLIST_VPC_LOG_ERROR("num value is unknown. Please input num 0 - 9 \n");
        return -1;
    }
 
    return 0;
}
 
static int32_t hanle_left_str_and_right_num(char *buf, char *target, uint64_t len, uint32_t *num)
{
    uint8_t left[PROC_BUF_LEN] = {0};
    uint8_t right[PROC_BUF_LEN] = {0};
    int32_t ret = sscanf_s(buf, "%[^=]=%s", left, len, right, len);
    if (ret != 2) { // 如果没有按格式输入2个字符串
        DVPP_CMDLIST_VPC_LOG_ERROR("cmd format is error, please check.\n");
        return -1;
    }
    if (ka_base_strcmp(target, left) == 0) {
        // 长度检查，过滤数字，并转成10进制u64
        ret = str2num(right, num);
        if (ret != 0) {
            return -1;
        }
 
        return 0;
    }
 
    DVPP_CMDLIST_VPC_LOG_ERROR("cmd is error, pls input 'echo enable_time_cost > /proc/dvpp_cmdlist' or "
                               "'echo disable_time_cost > /proc/dvpp_cmdlist' or 'echo clear_time_cost > /proc/dvpp_cmdlist'"
                               "or 'echo time_cost_node=0 >/proc/dvpp_cmdlist '\n");
    return -1;
}
 
static ssize_t dvpp_cmdlist_proc_write(ka_file_t *file, const char __ka_user *buffer, size_t count, loff_t *pos)
{
    dvpp_cmdlist_context *ctx = get_dvpp_cmdlist_ctx();
    uint8_t buf[PROC_BUF_LEN] = {0};
    uint8_t strip_buf[PROC_BUF_LEN] = {0};
    ssize_t length;
 
    if (count < 1) {
        return -EINVAL;
    }
 
    if (buffer == NULL) {
        return -EINVAL;
    }
 
    length = (ssize_t)(count > PROC_BUF_LEN ? PROC_BUF_LEN : count);
    if (ka_base_copy_from_user(&buf[0], buffer, (uint32_t)(length))) {
        return -EFAULT;
    }
    buf[length - 1] = '\0';
    strip_string(buf, strip_buf);
 
    if (ka_base_strcmp("enable_time_cost", strip_buf) == 0) {
        ctx->time_cost_stat.enable = 1;
        return length;
    }
 
    if (ka_base_strcmp("disable_time_cost", strip_buf) == 0) {
        ctx->time_cost_stat.enable = 0;
        return length;
    }
 
    if (ka_base_strcmp("clear_time_cost", strip_buf) == 0) {
        clear_time_cost();
        return length;
    }
 
    (void)hanle_left_str_and_right_num(strip_buf, "time_cost_node", (uint64_t)(length),
                                       (uint32_t*)(&ctx->time_cost_stat.node_num));
 
    if (ctx->time_cost_stat.node_num > MAX_TIME_COST_NODE_LEN) {
        ctx->time_cost_stat.node_num = MAX_TIME_COST_NODE_LEN;
        DVPP_CMDLIST_VPC_LOG_WARN("max time cost node num is %d.\n", MAX_TIME_COST_NODE_LEN);
    }
 
    return length;
}
 
 
static int dvpp_cmdlist_proc_open(ka_inode_t *inode, struct file *file)
{
    return ka_fs_single_open(file, dvpp_cmdlist_proc_show, NULL);
}
 
static const ka_procfs_ops_t dvpp_cmdlist_proc_ops = {
    ka_fs_init_pf_open(dvpp_cmdlist_proc_open)
    ka_fs_init_pf_read(ka_fs_seq_read)
    ka_fs_init_pf_write(dvpp_cmdlist_proc_write)
    ka_fs_init_pf_lseek(ka_fs_seq_lseek)
    ka_fs_init_pf_release(ka_fs_single_release)
};
 
void dvpp_cmdlist_init_proc(void)
{
    ka_fs_proc_create(PROC_NAME, 0, NULL, &dvpp_cmdlist_proc_ops);
}
 
void dvpp_cmdlist_remove_proc(void)
{
    ka_fs_remove_proc_entry(PROC_NAME, NULL);
}