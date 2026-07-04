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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "errno.h"
#include "securec.h"
#include "pwd.h"
#include "tool_comm.h"

STATIC char g_hccn_usr_name[HCCN_USER_NAME_LEN] = {0};

char *hccn_get_g_usr_name(void)
{
    return g_hccn_usr_name;
}

int hccn_check_usr_identify(void)
{
    struct passwd *pwd = getpwuid(getuid());
    int ret, ret_val;

    if (pwd == NULL) {
        hccn_err("pwd is NULL! getpwuid failed, errno:%d", errno);
        return -EINVAL;
    }
#ifndef CONFIG_LLT
    if (pwd->pw_name == NULL) {
        hccn_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out;
    }

    if (strcmp(pwd->pw_name, HCCN_CHECK_USER_IS_ROOT)) {
        hccn_err("only root user is legal, current user is:%s ", pwd->pw_name);
        ret = -EACCES;
        goto out;
    }
#endif
    ret = 0;
out:
    ret_val = memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    if (ret_val) {
        hccn_err("memset error, ret_val[%d]", ret_val);
        ret = -ENOMEM;
    }

    return ret;
}

int hccn_get_usr_name(struct command_context *ctx)
{
    struct passwd *pwd = getpwuid(getuid());
    int ret;

    if (pwd == NULL) {
        hccn_err("pwd is NULL! getpwuid failed, errno:%d", errno);
        return -EINVAL;
    }

    if (pwd->pw_name == NULL) {
        hccn_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out;
    }

    ret = strncpy_s(ctx->env_info.usr_name, HCCN_USER_NAME_LEN, pwd->pw_name, strlen(pwd->pw_name));
    if (ret != 0) {
        hccn_err("strncpy_s user name failed, ret[%d]", ret);
        goto out;
    }

    ret = strncpy_s(g_hccn_usr_name, HCCN_USER_NAME_LEN, pwd->pw_name, strlen(pwd->pw_name));
    if (ret) {
        hccn_err("strncpy_s user name failed, ret[%d]", ret);
        goto out;
    }

out:
    (void)memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));

    return ret;
}

int hccn_get_usr_ip(struct command_context *ctx)
{
    unsigned int ip_len = HCCN_USER_IP_LEN + 1;
    char *usr_ssh_ip = NULL;
    char *spac_pos = NULL;
    struct in_addr addr;

    usr_ssh_ip = getenv("SSH_CLIENT");
    if (usr_ssh_ip == NULL) {
        return strncpy_s(ctx->env_info.usr_ip, HCCN_USER_IP_LEN, "127.0.0.1", sizeof("127.0.0.1"));
    }

    spac_pos = strchr(usr_ssh_ip, ' ');
    if (spac_pos != NULL) {
        ip_len = (unsigned int)(spac_pos - usr_ssh_ip);
    }

    if (ip_len > HCCN_USER_IP_LEN) {
        return strncpy_s(ctx->env_info.usr_ip, HCCN_USER_IP_LEN, "Error IP", sizeof("Error IP"));
    }

    if (strncpy_s(ctx->env_info.usr_ip, HCCN_USER_IP_LEN, usr_ssh_ip, ip_len) != 0 ||
        inet_pton(AF_INET, ctx->env_info.usr_ip, &addr) != 1) {
        memset_s(ctx->env_info.usr_ip, HCCN_USER_IP_LEN, 0, HCCN_USER_IP_LEN);
        return strncpy_s(ctx->env_info.usr_ip, HCCN_USER_IP_LEN, "Invalid IP", sizeof("Invalid IP"));
    }

    return 0;
}