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
#include <errno.h>
#include "securec.h"
#include "cfg.h"
#include "ossl_user_linux.h"

STATIC int cfg_inner_read_conf_byfd(FILE *fp, const char *conf_name,
    char *conf_value, unsigned int len)
{
    int ret;
    char line_buf[CONLINE_LENGTH] = {0};
    unsigned int len_buf;
    unsigned int len_tmp;
    char *c = NULL;
    int found = 0;
    while (!feof(fp) && fgets(line_buf, CONLINE_LENGTH, fp) != NULL) {
        if ((line_buf[0] == '#') || (strlen(line_buf) < strlen("*=*"))) {
            continue;
        }
        c = (char *)strchr(line_buf, '=');
        if (c == NULL) {
            continue;
        }

        len_buf = strlen(line_buf) - 1;
        if ((len_buf < CONLINE_LENGTH) && (line_buf[len_buf] == '\n')) {
                line_buf[len_buf] = '\0';
        }
        len_tmp = (unsigned int)(c - line_buf);
        if (strncmp(line_buf, conf_name, strlen(conf_name)) == 0 && len_tmp == strlen(conf_name)) {
            ++c;
            ret = strcpy_s(conf_value, len, c);
            if (ret) {
                roce_err("strcpy_s err[%d], len:%u", ret, len);
                return UDA_TOOL_NO_MEM_ERR;
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        ret = UDA_TOOL_SYS_RD_FILE_NOT_FOUND;
    } else {
        ret = 0;
    }
    return ret;
}

int cfg_inner_read_conf(const char *conf_path, const char *conf_name,
    char *conf_value, unsigned int len)
{
    FILE *fp = NULL;
    int ret, ret_val;
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813

    if ((strlen(conf_path) > PATH_MAX) || (realpath(conf_path, real_conf_path) == NULL)) {
        roce_err("read path_len[%u] > PATH_MAX or conf_path is invalid, err[%d]", strlen(conf_path), errno);
        return UDA_TOOL_ACCESS_CONF_FILE_ERR;
    }

    fp = fopen(real_conf_path, "r");
    if (fp == NULL) {
        roce_err("Open configure file fail errno[%d] real_conf_path[%s]", errno, real_conf_path);
        return UDA_TOOL_SYS_READ_FILE_ERR;
    }

    ret = flock(fileno(fp), LOCK_EX);
    if (ret) {
        roce_err("hccn.conf lock fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }

    ret = cfg_inner_read_conf_byfd(fp, conf_name, conf_value, len);
out:
    ret_val = fclose(fp);
    if (ret_val) {
        roce_warn("Fclose fail. (ret_val=%d; errno=%d)", ret_val, errno);
    }
    fp = NULL;
    return ret;
}

STATIC int cfg_inner_write_conf_byfd(FILE *fp, const char *conf_name,
    const char *conf_value, char *sum_buf, int sum_buf_len)
{
    int ret, ret_val;
    char line_buf[CONLINE_LENGTH] = {0};
    char new_conf[CONLINE_LENGTH] = {0};

    if (sum_buf == NULL) {
        return UDA_TOOL_INNER_PARAM_ERR;
    }
    while (!feof(fp) && fgets(line_buf, CONLINE_LENGTH, fp) != NULL) {
        if ((strncmp(line_buf, conf_name, strlen(conf_name)) == 0) && (line_buf[strlen(conf_name)] == '=')) {
            continue;
        } else {
            ret = strcat_s(sum_buf, sum_buf_len, line_buf);
            if (ret) {
                roce_err("strcat fail ret[%d]!", ret);
                return UDA_TOOL_INSUFFICIENT_FILE_SIZE_ERR;
            }
        }
    }

    ret = sprintf_s(new_conf, CONLINE_LENGTH, "%s=%s\n", conf_name, conf_value);
    if (ret <= 0) {
        roce_err("sprintf str op fail[%d] conf_name[%s] conf_value[%s]!", ret, conf_name, conf_value);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = strcat_s(sum_buf, sum_buf_len, new_conf);
    if (ret) {
        roce_err("sum_buf str op fail[%d] new_conf[%s]!", ret, new_conf);
        return UDA_TOOL_INSUFFICIENT_FILE_SIZE_ERR;
    }

    roce_info("---configure---->\n%s<----------", sum_buf);
    ret = ftruncate(fileno(fp), 0);
    if (ret < 0) {
        roce_err("hccn.conf ftruncate fail! ret[%d] errno[%d]", ret, errno);
        return UDA_TOOL_SYS_WRITE_FILE_ERR;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        return UDA_TOOL_SYS_WRITE_FILE_ERR;
    }

    ret_val = fputs(sum_buf, fp);
    if (ret_val < 0) {
        roce_warn("fputs fail, ret_val:%d, fd:%d, errno:%d", ret_val, fileno(fp), errno);
    }
    return 0;
}

STATIC int cfg_inner_write_conf(const char *conf_path, const char *conf_name, const char *conf_value)
{
    FILE *fp = NULL;
    int ret, ret_val[FILE_RELEASE_RET_VALUE_NUM] = {0};
    char *sum_buf = NULL;
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813

    if ((strlen(conf_path) > PATH_MAX) || (realpath(conf_path, real_conf_path) == NULL)) {
        roce_err("write path_len[%u] > PATH_MAX or conf_path is invalid, err[%d]", strlen(conf_path), errno);
        return UDA_TOOL_ACCESS_CONF_FILE_ERR;
    }

    fp = fopen(real_conf_path, "r+");
    if (fp == NULL) {
        roce_err("Open read configure fail! errno[%d]", errno);
        return UDA_TOOL_SYS_WRITE_FILE_ERR;
    }

    sum_buf = (char *)calloc(CONFILE_LENGTH, sizeof(char));
    if (sum_buf == NULL) {
        roce_err("calloc fail.");
        ret = UDA_TOOL_NO_MEM_ERR;
        goto close_fd;
    }

    ret = flock(fileno(fp), LOCK_EX);
    if (ret) {
        roce_err("hccn.conf lock failed! ret:%d, fd:%d, errno:%d", ret, fileno(fp), errno);
        ret = UDA_TOOL_SYS_WRITE_FILE_ERR;
        goto out;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_WRITE_FILE_ERR;
        goto unlock;
    }

    ret = cfg_inner_write_conf_byfd(fp, conf_name, conf_value, sum_buf, CONFILE_LENGTH);

unlock:
    ret_val[0x0] = fflush(fp);
    ret_val[0x1] = fsync(fileno(fp));
    ret_val[0x2] = flock(fileno(fp), LOCK_UN);
out:
    free(sum_buf);
    sum_buf = NULL;
close_fd:
    ret_val[0x3] = fclose(fp);
    fp = NULL;

    if (ret_val[0x0] || ret_val[0x1] || ret_val[0x2] || ret_val[0x3]) {
        roce_err("hccn.conf release failed! (ret_val=[fflush:%d, fsync:%d, flock:%d, fclose:%d]; ret=%d; errno=%d)",
            ret_val[0x0], ret_val[0x1], ret_val[0x2], ret_val[0x3], ret, errno);
    }
    return ret;
}

int cfg_inner_del_conf_byfd(FILE *fp, const char *conf_name)
{
    char line_buf[CONLINE_LENGTH] = {0};
    int buff_len = 0;
    long offset_read = 0;
    long offset_write = 0;
    int ret = 0;
    int ret_val;
    while (!feof(fp) && fgets(line_buf, CONLINE_LENGTH, fp) != NULL) {
        buff_len = strlen(line_buf);

        if (offset_read != offset_write) {
            ret = fseek(fp, offset_write, SEEK_SET);
            if (ret) {
                roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
                return UDA_TOOL_SYS_DELETE_FILE_ERR;
            }
            ret_val = fputs(line_buf, fp);
            if (ret_val < 0) {
                roce_warn("fputs fail, ret_val:%d, fd:%d, errno:%d", ret_val, fileno(fp), errno);
            }
        }

        if (strstr(line_buf, conf_name)) {
            offset_read += buff_len;
        } else {
            offset_read += buff_len;
            offset_write += buff_len;
        }

        ret = fseek(fp, offset_read, SEEK_SET);
        if (ret) {
            roce_err("fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
            ret = UDA_TOOL_SYS_DELETE_FILE_ERR;
            break;
        }
    }

    ret_val = ftruncate(fileno(fp), offset_write);
    if (ret_val < 0) {
        roce_warn("ftruncate fail, ret_val:%d, fd:%d, errno:%d", ret_val, fileno(fp), errno);
    }
    return ret;
}

STATIC int cfg_inner_del_conf(const char *conf_path, const char *conf_name)
{
    FILE *fp = NULL;
    int ret, ret_val;
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813

    if ((strlen(conf_path) > PATH_MAX) || (realpath(conf_path, real_conf_path) == NULL)) {
        roce_err("delete path_len[%u] > PATH_MAX or conf_path is invalid, err[%d]", strlen(conf_path), errno);
        return UDA_TOOL_ACCESS_CONF_FILE_ERR;
    }

    fp = fopen(real_conf_path, "r+");
    if (fp == NULL) {
        roce_err("Open configure file fail! errno[%d], real_conf_path[%s]", errno, real_conf_path);
        return UDA_TOOL_SYS_DELETE_FILE_ERR;
    }

    ret = flock(fileno(fp), LOCK_EX);
    if (ret) {
        roce_err("hccn.conf lock fail! ret[%d] errno[%d]", ret, errno);
        ret = UDA_TOOL_SYS_DELETE_FILE_ERR;
        goto out;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_DELETE_FILE_ERR;
        goto unlock;
    }

    ret = cfg_inner_del_conf_byfd(fp, conf_name);

unlock:
    if (flock(fileno(fp), LOCK_UN)) {
        roce_err("hccn.conf unlock failed! (ret=%d; errno=%d)", ret, errno);
    }
out:
    ret_val = fclose(fp);
    if (ret_val) {
        roce_warn("Fclose fail. (ret_val=%d; errno=%d)", ret_val, errno);
    }
    fp = NULL;
    return ret;
}

int cfg_read_conf(int phy_id, const char *conf_name, char *conf_value, unsigned int len)
{
    int ret;
    char conf[CONLINE_LENGTH] = {0};
    if (conf_name == NULL || conf_value == NULL) {
        roce_err("Input param is NULL.");
        return -EINVAL;
    }

    ret = sprintf_s(conf, CONLINE_LENGTH, "%s_%d", conf_name, phy_id);
    if (ret <= 0) {
        roce_err("conf str op fail! ret[%d] conf_name[%s] phy_id[%d]", ret, conf_name, phy_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = cfg_inner_read_conf(CFGFILE_NAME, conf, conf_value, len);
    if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_info("the conf[%s] not found", conf);
        return ret;
    } else if (ret) {
        roce_err("cfg_inner_read_conf fail! ret[%d] conf[%s] conf_value[%s]", ret, conf, conf_value);
        return ret;
    }

    roce_info("read conf[%s] realconf[%s] val[%s]", conf, conf_name, conf_value);

    return 0;
}

int cfg_write_conf(int phy_id, const char *conf_name, const char *conf_value)
{
    int ret;
    char conf[CONLINE_LENGTH] = {0};

    if (conf_name == NULL || conf_value == NULL) {
        roce_err("Input param is NULL.");
        return -EINVAL;
    }

    ret = sprintf_s(conf, CONLINE_LENGTH, "%s_%d", conf_name, phy_id);
    if (ret <= 0) {
        roce_err("conf[%s] str op fail! ret[%d] conf_name[%s] phy_id[%d]",
                 conf, ret, conf_name, phy_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = cfg_inner_write_conf(CFGFILE_NAME, conf, conf_value);
    if (ret) {
        roce_err("cfg_inner_write_conf fail! ret[%d] conf[%s] conf_value[%s]", ret, conf, conf_value);
        return ret;
    }
    roce_info("write conf[%s] realconf[%s] conf_value[%s]", conf, conf_name, conf_value);

    return 0;
}

int cfg_del_conf(int phy_id, const char *conf_name)
{
    int ret;
    char conf[CONLINE_LENGTH] = {0};

    if (conf_name == NULL) {
        roce_err("Input param is NULL.");
        return -EINVAL;
    }
    ret = sprintf_s(conf, CONLINE_LENGTH, "%s_%d=", conf_name, phy_id);
    if (ret <= 0) {
        roce_err("conf[%s] str op fail! ret[%d] conf_name[%s] phy_id[%d]", conf, ret, conf_name, phy_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = cfg_inner_del_conf(CFGFILE_NAME, conf);
    if (ret) {
        roce_err("cfg_inner_del_conf fail! ret[%d] conf[%s]", ret, conf);
        return ret;
    }

    roce_info("del conf[%s]", conf);

    return ret;
}


