/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <pwd.h>
#include "file_opt.h"
#include "hccn_log.h"
#include "tool_cfg_ops.h"
#include "dsmi_common_interface.h"
#include "shell_cmd_data.h"

STATIC int tool_inner_write_conf_byfd(FILE *fp, const char *conf_name,
    const char *conf_value, char *sum_buf, int sum_buf_len)
{
    char line_buf[CONFLINE_LENGTH] = {0};
    char new_conf[CONFLINE_LENGTH] = {0};
    int ret, ret_val;

    if (sum_buf == NULL) {
        return -ENOENT;
    }
    while (fgets(line_buf, CONFLINE_LENGTH, fp) != NULL && feof(fp) == 0) {
        if ((strncmp(line_buf, conf_name, strlen(conf_name)) == 0) && (line_buf[strlen(conf_name)] == '=')) {
            continue;
        } else {
            ret = strcat_s(sum_buf, sum_buf_len, line_buf);
            CHK_PRT_RETURN(ret != 0, hccn_err("strcat failed, ret:%d", ret), ret);
        }
    }

    ret = sprintf_s(new_conf, CONFLINE_LENGTH, "%s=%s\n", conf_name, conf_value);
    CHK_PRT_RETURN(ret <= 0, hccn_err("sprintf str op failed, ret:%d conf_name:%s conf_value:%s",
        ret, conf_name, conf_value), -EIO);

    ret = strcat_s(sum_buf, sum_buf_len, new_conf);
    CHK_PRT_RETURN(ret < 0, hccn_err("sum_buf str op failed, ret:%d new_conf:%s", ret, new_conf), -ENOENT);

    hccn_info("---configure---->\n%s<----------", sum_buf);
    ret = ftruncate(fileno(fp), 0);
    if (ret < 0) {
        hccn_err("hccn.conf ftruncate failed! ret[%d] errno[%d]", ret, errno);
        return ret;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        hccn_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        return ret;
    }

    ret_val = fputs(sum_buf, fp);
    if (ret_val < 0) {
        hccn_warn("fputs failed, ret_val:%d, fd:%d, errno:%d", ret_val, fileno(fp), errno);
    }
    return 0;
}

STATIC int tool_inner_write_conf(const char *conf_path, const char *conf_name, const char *conf_value)
{
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813
    char *sum_buf = NULL;
    int ret, ret_val;
    FILE *fp = NULL;

    if ((strlen(conf_path) > PATH_MAX) || (realpath(conf_path, real_conf_path) == NULL)) {
        hccn_err("write path_len[%zu] > PATH_MAX or conf_path is invalid, err[%d]", strlen(conf_path), errno);
        return -EINVAL;
    }

#ifndef CONFIG_LLT
    fp = fopen(real_conf_path, "a+");
    if (fp == NULL) {
        hccn_err("Open read configure failed! errno[%d]", errno);
        return errno;
    }

    sum_buf = (char *)calloc(CONFILE_LENGTH, sizeof(char));
    if (sum_buf == NULL) {
        hccn_err("calloc failed.");
        ret = -ENOENT;
        goto close_fd;
    }

    ret = flock(fileno(fp), LOCK_EX);
    if (ret) {
        hccn_err("hccn.conf lock failed! ret:%d, fd:%d, errno:%d", ret, fileno(fp), errno);
        ret = errno;
        goto out;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        hccn_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = errno;
        goto out;
    }

    ret = tool_inner_write_conf_byfd(fp, conf_name, conf_value, sum_buf, CONFILE_LENGTH);
out:
    free(sum_buf);
    sum_buf = NULL;
close_fd:
    ret_val = fclose(fp);
    fp = NULL;
    CHK_PRT_RETURN(ret_val != 0, hccn_err("fclose failed, ret_val:%d, errno:%d", ret_val, errno), ret_val);
    return ret;
#else
    return 0;
#endif
}

int tool_write_conf(int phy_id, const char *conf_name, const char *conf_value)
{
    char conf[CONFLINE_LENGTH] = {0};
    int ret;

    if (conf_name == NULL || conf_value == NULL) {
        hccn_err("Input param is NULL.");
        return -EINVAL;
    }

    ret = sprintf_s(conf, CONFLINE_LENGTH, "%s_%d", conf_name, phy_id);
    if (ret <= 0) {
        hccn_err("conf str op failed! ret[%d] conf_name[%s] phy_id[%d]", ret, conf_name, phy_id);
        return -ENOENT;
    }

    ret = tool_inner_write_conf(CFGFILE_NAME, conf, conf_value);
    if (ret) {
        hccn_err("tool_inner_write_conf failed! ret[%d] conf[%s] conf_value[%s]", ret, conf, conf_value);
        return ret;
    }
    hccn_info("write conf[%s] realconf[%s] conf_value[%s]", conf, conf_name, conf_value);

    return 0;
}

int tool_read_conf(int phy_id, const char *conf_name, char *conf_value, unsigned int len)
{
    return FileReadCfg(CFGFILE_NAME, phy_id, conf_name, conf_value, len);
}

bool tool_check_conf_udhcpc_enable(int phy_id)
{
    char udhcpc_flag[UDHCPC_QUIT_INBUFF_LEN] = {0};
    int ret;

    ret = tool_read_conf(phy_id, "udhcpc_enable", udhcpc_flag, sizeof(udhcpc_flag));
    CHK_PRT_RETURN(ret == 0, hccn_info("[Ipv4]hccn.conf have udhcpc_enable flag"), true);

    return false;
}

static bool is_dev_ipaddr_conflict(int logic_id, int port_type, int port_id, unsigned int ipaddr, unsigned int mask)
{
    unsigned int ip_addr, mask_addr;
    ip_addr_t mask_address = {0};
    ip_addr_t ip_address = {0};
    int ret;

    ip_address.ip_type = IPADDR_TYPE_V4;
    mask_address.ip_type = IPADDR_TYPE_V4;
    ret = dsmi_get_device_ip_address(logic_id, port_type, port_id, &ip_address, &mask_address);
    if (ret) {
        hccn_err("dsmi_get_device_ip_address failed ret:%d, logic_id:%d", ret, logic_id);
        return false;
    }

    ip_addr = *(unsigned int *)&ip_address.u_addr;
    mask_addr = *(unsigned int *)&mask_address.u_addr;
    if ((ip_addr & mask_addr) == (ipaddr & mask_addr)) {
        return true;
    }

    return false;
}

bool is_ipaddr_conflict(struct command_context *ctx)
{
    struct ip_cmd_args *ip_args = (struct ip_cmd_args *)ctx->cmd_args;
    unsigned int netmask = ip_args->netmask.ip_addr;
    const char *vnic_host_addr = "192.168.1.199";
    const char *vnic_host_mask = "255.255.255.0";
    unsigned int ip_addr = ip_args->ip.ip_addr;
    int logic_id = ctx->npu_info.logic_id;
    unsigned int vnic_h_ipaddr;
    unsigned int vnic_h_mask;

    if (is_dev_ipaddr_conflict(logic_id, DSMI_VNIC_PORT, 0, ip_addr, netmask)) {
        return true;
    }

    vnic_h_ipaddr = inet_addr(vnic_host_addr);
    vnic_h_mask = inet_addr(vnic_host_mask);
    /* check if there has confliction that ip with device vnic's host_ip */
    if ((ip_addr & vnic_h_mask) == (vnic_h_ipaddr & vnic_h_mask)) {
        return true;
    }

    return false;
}