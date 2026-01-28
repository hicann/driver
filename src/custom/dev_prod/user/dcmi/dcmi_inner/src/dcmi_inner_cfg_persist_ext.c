/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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
#include <errno.h>
#ifndef _WIN32
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#endif
#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_interface_api.h"
#include "dcmi_environment_judge.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_cfg_persist.h"

STATIC int dcmi_cfg_op_timeout_get_cfg_path(char *path, unsigned int path_size, char *path_bak,
    unsigned int path_bak_size)
{
#ifndef _WIN32

    if (path_size < PATH_MAX || path_bak_size < PATH_MAX) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if (realpath(DCMI_OP_TIMEOUT_CONF, path) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath check path error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (realpath(DCMI_OP_TIMEOUT_CONF_BAK, path_bak) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath check path_bak error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    return DCMI_OK;
}

STATIC void dcmi_cfg_op_timeout_fix_empty_file()
{
#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
    char path_bak[PATH_MAX + 1] = {0x00};
    struct stat buf;
    int ret;
    uid_t uid;

    ret = dcmi_cfg_op_timeout_get_cfg_path(path, sizeof(path), path_bak, sizeof(path_bak));
    if (ret != DCMI_OK) {
        return;
    }

    ret = stat(path_bak, &buf);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "stat failed. ret is %d. errno is %d.", ret, errno);
        dcmi_cfg_write_default_context(DCMI_OP_TIMEOUT_CONF, DCMI_OP_TIMEOUT_CONF_DEFAULT_COMMENT);
        return;
    }
    uid = getuid();
    if (uid != buf.st_uid) {
        gplog(LOG_ERR, "file uid invalid.uid %u st_pid %u.", uid, buf.st_uid);
        return;
    }

    ret = rename(path_bak, path);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "rename error. errno is %d", errno);
        return;
    }
    gplog(LOG_INFO, "op timeout rename cfg ok.");
    return;
#else
    return;
#endif
}

int dcmi_cfg_op_timeout_open_file(FILE **fp)
{
#ifdef _WIN32
    return DCMI_ERR_CODE_NOT_SUPPORT;
#else
    FILE *fp_tmp = NULL;
    unsigned int file_len;

    char path[PATH_MAX + 1] = {0x00};

    if (fp == NULL) {
        gplog(LOG_ERR, "fp is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (realpath(DCMI_OP_TIMEOUT_CONF, path) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    fp_tmp = fopen(path, "r");
    if ((fp_tmp == NULL) && (errno == ENOENT)) {
        dcmi_cfg_write_default_context(DCMI_OP_TIMEOUT_CONF, DCMI_OP_TIMEOUT_CONF_DEFAULT_COMMENT);
        // 如果文件不存在，则创建一个默认的配置文件
    } else if (fp_tmp == NULL) {
        gplog(LOG_ERR, "fopen %s error. errno is %d", path, errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    } else {
        (void)fseek(fp_tmp, 0, SEEK_END);
        file_len = (unsigned int)ftell(fp_tmp);
        rewind(fp_tmp);
        fclose(fp_tmp);
        if (file_len == 0) {
            dcmi_cfg_op_timeout_fix_empty_file();
        }
    }

    fp_tmp = fopen(path, "r");
    if (fp_tmp == NULL) {
        gplog(LOG_ERR, "fopen %s error. errno is %d", path, errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    *fp = fp_tmp;
    return DCMI_OK;
#endif
}

int dcmi_cfg_op_timeout_check_cfg_path(char *path, unsigned int path_size, char *path_bak, unsigned int path_bak_size)
{
    int ret;

    ret = dcmi_cfg_op_timeout_get_cfg_path(path, path_size, path_bak, path_bak_size);
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_check_run_in_docker()) {
        ret = rename(path, path_bak);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "rename error. errno is %d", errno);
            return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
        }
    }

    return DCMI_OK;
}

int dcmi_cfg_op_timeout_write_to_file(const char *buf, unsigned int buf_len)
{
#ifdef _WIN32
    return DCMI_ERR_CODE_NOT_SUPPORT;
#else
    FILE *fp = NULL;
    char path[PATH_MAX + 1] = {0x00};
    char path_bak[PATH_MAX + 1] = {0x00};
    unsigned int write_len;
    int fd_num, ret;

    if (buf == NULL) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_cfg_op_timeout_check_cfg_path(path, sizeof(path), path_bak, sizeof(path_bak));
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    fp = fopen(path, "w");
    if (fp == NULL) {
        (void)rename(path_bak, path);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }
    fd_num = fileno(fp);
    if (fd_num >= 0) {
        (void)fchmod(fd_num, (S_IRUSR | S_IWUSR));
    }

    write_len = fwrite(buf, 1, buf_len, fp);
    if (write_len != buf_len) {
        gplog(LOG_ERR, "fwrite error. write_len is %u, buf_len is %u", write_len, buf_len);
        goto write_fail;
    }
    ret = fsync(fd_num);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "fsync error. errno is %d", errno);
        goto write_fail;
    }
    (void)fclose(fp);
    (void)unlink(path_bak);
    return DCMI_OK;

write_fail:
    (void)fclose(fp);
    (void)rename(path_bak, path);
    return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
#endif
}

static int dcmi_cfg_op_timeout_check_is_cover(const char *cmdline, char *buf_tmp)
{
    int ret = DCMI_CFG_DIFF_LINE;
    if (strstr(cmdline, buf_tmp) != NULL) {
        return DCMI_CFG_HAS_SAME_LINE;
    }

    // 判断该npu命令是否已持久化
    if (strncmp(cmdline, buf_tmp, strlen(buf_tmp) - DCMI_CFG_OP_TIMEOUT_DLINE_LEN) == 0) {
        ret = DCMI_CFG_COVER_LINE;
    }

    if (strlen(cmdline) < DCMI_CFG_OP_TIMEOUT_CMD_LINE_LEN) {
        return DCMI_CFG_DIFF_LINE;
    }
    if (strlen(buf_tmp) < DCMI_CFG_OP_TIMEOUT_CMD_LINE_LEN) {
        return DCMI_CFG_DIFF_LINE;
    }
    if (strncmp(cmdline, buf_tmp, DCMI_CFG_OP_TIMEOUT_CMD_LINE_LEN) == 0) {
        ret = DCMI_CFG_COVER_LINE;
    }
    return ret;
}

static int dcmi_cfg_op_timeout_get_action(unsigned int start, unsigned int end, const char *cmdline, char *buf_tmp)
{
    unsigned int card_id_tmp, chip_id_tmp, enable_type_tmp;
    unsigned int card_id_cmd, chip_id_cmd, enable_type_cmd;
    int ret;

    ret = sscanf_s(cmdline, "npu-smi set -t op-timeout-cfg -i %u -c %u -d %u ", &card_id_cmd, &chip_id_cmd,
                   &enable_type_cmd);
    if (ret < 1) {
        gplog(LOG_ERR, "sscanf_s failed. ret is %d", ret);
        return DCMI_CFG_NOT_NEED_INSERT;
    }

    // 找到起始位置，检查是否需要插入
    if (start != DCMI_OP_TIMEOUT_FLAG_NOT_FIND) {
        if (end == DCMI_OP_TIMEOUT_FLAG_NOT_FIND) {
            ret = dcmi_cfg_op_timeout_check_is_cover(cmdline, buf_tmp);
            if (ret != DCMI_CFG_DIFF_LINE) {
                return ret;
            }

            ret = sscanf_s((const char *)buf_tmp, "npu-smi set -t op-timeout-cfg -i %u -c %u -d %u ",
                           &card_id_tmp, &chip_id_tmp, &enable_type_tmp);
            if (ret < 1) {
                gplog(LOG_ERR, "sscanf_s failed. ret is %d", ret);
                return DCMI_ERR_CODE_OP_TIMEOUT_CONFIG_ILLEGAL;
            }

            if (card_id_tmp > card_id_cmd) {
                return DCMI_CFG_NEED_INSERT;
            } else if ((card_id_tmp == card_id_cmd) && (chip_id_tmp > chip_id_cmd)) {
                return DCMI_CFG_NEED_INSERT;
            } else {
                return DCMI_CFG_NOT_NEED_INSERT;
            }
        } else {
            if (end - start >= 1) {
                return DCMI_CFG_NEED_INSERT;
            }
        }
    }
    return DCMI_CFG_NOT_NEED_INSERT;
}

int dcmi_cfg_insert_op_timeout_cmdline_to_buffer(const char *cmdline, FILE *fp, char **buf_out, unsigned int *len)
{
    int ret, action;
    char buf_tmp[DCMI_OP_TIMEOUT_CONF_ONE_LINE_MAX_LEN] = {0};
    unsigned int insert_flag = 0, line = 0, start_flag = 0, end_flag = 0;
    struct cfg_buf_info buf_info;

    (void)fseek(fp, 0, SEEK_END);
    buf_info.buf_size = (unsigned int)ftell(fp) + DCMI_OP_TIMEOUT_CONF_ONE_LINE_MAX_LEN + 1;
    rewind(fp);
    if (dcmi_cfg_malloc_buffer_and_init(buf_out, buf_info.buf_size) != DCMI_OK) {
        return DCMI_ERR_CODE_INNER_ERR;
    }
    buf_info.buf = *buf_out;

    while (!feof(fp)) {
        (void)memset_s(buf_tmp, sizeof(buf_tmp), 0, sizeof(buf_tmp));
        char *str = fgets(buf_tmp, sizeof(buf_tmp), fp);
        if (str == NULL) {
            break;
        }
        line++;

        if (insert_flag != DCMI_CFG_INSERT_COMPLETE) {
            if (end_flag == DCMI_OP_TIMEOUT_FLAG_NOT_FIND) {
                end_flag = (strcmp(buf_tmp, "[op-timeout-config end]\n") == 0) ? (line - 1) : end_flag;
            }

            action = dcmi_cfg_op_timeout_get_action(start_flag, end_flag, cmdline, buf_tmp);
            if (action == DCMI_ERR_CODE_OP_TIMEOUT_CONFIG_ILLEGAL) {
                return DCMI_ERR_CODE_OP_TIMEOUT_CONFIG_ILLEGAL;
            }
            ret = dcmi_cfg_process_action(action, &buf_info, len, cmdline, buf_tmp);
            insert_flag = ((ret == DCMI_CFG_INSERT_OK) ? DCMI_CFG_INSERT_COMPLETE : insert_flag);
            if (ret == DCMI_ERR_CODE_SECURE_FUN_FAIL) {
                goto SECURE_FUN_FAIL;
            }
            if (start_flag == DCMI_OP_TIMEOUT_FLAG_NOT_FIND) {
                start_flag = (strcmp(buf_tmp, "[op-timeout-config start]\n") == 0) ? (line - 1) : start_flag;
            }
        } else {
            ret = strncat_s(*buf_out, buf_info.buf_size, buf_tmp, strlen(buf_tmp));
            if (ret != 0) {
                goto SECURE_FUN_FAIL;
            }
            *len += strlen(buf_tmp);
        }
    }

    ret = (start_flag == 0) ? DCMI_ERR_CODE_OP_TIMEOUT_CONFIG_ILLEGAL : DCMI_OK;
    return ret;
SECURE_FUN_FAIL:
    gplog(LOG_ERR, "strncat_s failed. ret is %d", ret);
    return DCMI_ERR_CODE_SECURE_FUN_FAIL;
}

int dcmi_cfg_insert_set_op_timeout_cmdline(int card_id, int chip_id, unsigned int timeout_value)
{
    char *buf = NULL;
    unsigned int buf_len = 0;
    int ret, lock_fd;
    char cmdline_buf[DCMI_OP_TIMEOUT_CONF_ONE_LINE_MAX_LEN] = {0};
    FILE *fp = NULL;

    ret = snprintf_s(cmdline_buf, sizeof(cmdline_buf), sizeof(cmdline_buf) - 1,
        "npu-smi set -t op-timeout-cfg -i %d -c %d -d %u\n",
         card_id, chip_id, timeout_value);
    if (ret <= 0) {
        gplog(LOG_ERR, "snprintf_s failed, ret is %d", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmi_cfg_set_lock(&lock_fd, DCMI_CFG_GET_LOCK_TIMEOUT, DCMI_CFG_OP_TIMEOUT_LOCK_FILE_NAME);
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    ret = dcmi_cfg_op_timeout_open_file(&fp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_op_timeout_open_file failed. ret is %d", ret);
        dcmi_cfg_set_unlock(lock_fd);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = dcmi_cfg_insert_op_timeout_cmdline_to_buffer(cmdline_buf, fp, &buf, &buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_insert_op_timeout_cmdline_to_buffer cmdline_buf %s failed. ret is %d",
              cmdline_buf, ret);
        if (ret == DCMI_ERR_CODE_OP_TIMEOUT_CONFIG_ILLEGAL) {
            gplog(LOG_OP, "The configuraion file has been modified unexpectedly.");
        }
        fclose(fp);
        dcmi_cfg_set_unlock(lock_fd);
        return ret;
    }

    (void)fclose(fp);
    ret = dcmi_cfg_op_timeout_write_to_file(buf, buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_op_timeout_write_to_file failed, ret is %d", ret);
    }

    free(buf);
    dcmi_cfg_set_unlock(lock_fd);
    return ret;
}

STATIC int dcmi_cfg_device_share_get_cfg_path(char *path, unsigned int path_size, char *path_bak,
    unsigned int path_bak_size)
{
    if (path_size < PATH_MAX  || path_bak_size < PATH_MAX) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if (realpath(DCMI_DEVICE_SHARE_CONF, path) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath check path error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (realpath(DCMI_DEVICE_SHARE_CONF_BAK, path_bak) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath check path_bak error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    return DCMI_OK;
}

STATIC void dcmi_cfg_device_share_fix_empty_file()
{
#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
    char path_bak[PATH_MAX + 1] = {0x00};
    struct stat buf;
    int ret;
    uid_t uid;

    ret = dcmi_cfg_device_share_get_cfg_path(path, sizeof(path), path_bak, sizeof(path_bak));
    if (ret != DCMI_OK) {
        return;
    }

    ret = stat(path_bak, &buf);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "stat failed. ret is %d. errno is %d.", ret, errno);
        dcmi_cfg_write_default_context(DCMI_DEVICE_SHARE_CONF, DCMI_DEVICE_SHARE_CONF_DEFAULT_COMMENT);
        return;
    }
    uid = getuid();
    if (uid != buf.st_uid) {
        gplog(LOG_ERR, "file uid invalid.uid %u st_pid %u.", uid, buf.st_uid);
        return;
    }

    ret = rename(path_bak, path);
   if (ret != DCMI_OK) {
        gplog(LOG_ERR, "rename error. errno is %d", errno);
        return;
    }
    gplog(LOG_INFO, "device share rename cfg ok.");
    return;
#endif
}

int dcmi_cfg_device_share_open_file(FILE **fp)
{
#ifdef _WIN32
    return DCMI_ERR_CODE_NOT_SUPPORT;
#else
    FILE *fp_tmp = NULL;
    unsigned int file_len;

    char path[PATH_MAX + 1] = {0x00};

    if (fp == NULL) {
        gplog(LOG_ERR, "fp is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (realpath(DCMI_DEVICE_SHARE_CONF, path) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "realpath error. errno is %d", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    fp_tmp = fopen(path, "r");
    if ((fp_tmp == NULL) && (errno == ENOENT)) {
        dcmi_cfg_write_default_context(DCMI_DEVICE_SHARE_CONF, DCMI_DEVICE_SHARE_CONF_DEFAULT_COMMENT);
        // 如果文件不存在，则创建一个默认的配置文件
    } else if (fp_tmp == NULL) {
        gplog(LOG_ERR, "fopen %s error. errno is %d", path, errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    } else {
        (void)fseek(fp_tmp, 0, SEEK_END);
        file_len = (unsigned int)ftell(fp_tmp);
        rewind(fp_tmp);
        fclose(fp_tmp);
        if (file_len == 0) {
            dcmi_cfg_device_share_fix_empty_file();
        }
    }

    fp_tmp = fopen(path, "r");
    if (fp_tmp == NULL) {
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    *fp = fp_tmp;
    return DCMI_OK;
#endif
}

int dcmi_cfg_check_device_share_config_context_is_delete(unsigned int start, unsigned int end, unsigned int mode,
    unsigned set_flag, const char *buf)
{
    int cmp_flag = FALSE;
    if (strncmp(buf, "device-share-recover:", strlen("device-share-recover:")) == 0) {
        cmp_flag = TRUE;
    }

    if ((!set_flag) && cmp_flag) {
        return DCMI_CFG_NEED_INSERT;
    }
    if (mode == DCMI_CFG_RECOVER_ENABLE) {
        return DCMI_CFG_NOT_NEED_DELETE;
    } else {
        if (end == DCMI_VNPU_FLAG_NOT_FIND && start != DCMI_VNPU_FLAG_NOT_FIND) {
            return DCMI_CFG_NEED_DELETE;
        } else {
            return DCMI_CFG_NOT_NEED_DELETE;
        }
    }
}

int dcmi_cfg_set_device_share_recover_to_buffer(const char *cmdline, unsigned int mode, FILE *fp,
    char **buf_out, unsigned int *buf_len)
{
    unsigned int start_flag = DCMI_DEVICE_SHARE_FLAG_NOT_FIND, end_flag = DCMI_DEVICE_SHARE_FLAG_NOT_FIND;
    char buf_tmp[DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN] = {0};
    unsigned int out_file_len = 0, line = 0;
    unsigned int set_complete = FALSE;
    int ret, action;

    // 获取文件大小，分配缓冲区
    (void)fseek(fp, 0, SEEK_END);
    unsigned int buf_size = (unsigned int)ftell(fp) + DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN + 1;
    rewind(fp);

    if (dcmi_cfg_malloc_buffer_and_init(buf_out, buf_size) != DCMI_OK) {
        return DCMI_ERR_CODE_INNER_ERR;
    }

    while (!feof(fp)) {
        (void)memset_s(buf_tmp, sizeof(buf_tmp), 0, sizeof(buf_tmp));
        char *str = fgets(buf_tmp, sizeof(buf_tmp), fp);
        if (str == NULL) {
            break;
        }

        line++;
        if (end_flag == DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
            end_flag = (strcmp(buf_tmp, "[device-share-config end]\n") == 0) ? (line - 1) : end_flag;
        }

        action =
            dcmi_cfg_check_device_share_config_context_is_delete(start_flag, end_flag, mode, set_complete, buf_tmp);
        if (action == DCMI_CFG_NEED_DELETE) {
            continue;
        } else if (action == DCMI_CFG_NEED_INSERT) {
            ret = strncat_s(*buf_out, buf_size, cmdline, strlen(cmdline));
            out_file_len += strlen(cmdline);
            set_complete = TRUE;
        } else {
            ret = strncat_s(*buf_out, buf_size, buf_tmp, strlen(buf_tmp));
            out_file_len += strlen(buf_tmp);
        }

        if (start_flag == DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
            start_flag = (strcmp(buf_tmp, "[device-share-config start]\n") == 0) ? (line - 1) : start_flag;
        }

        if (ret != 0) {
            free(*buf_out);
            return DCMI_ERR_CODE_SECURE_FUN_FAIL;
        }
    }

    if (set_complete == FALSE) {
        free(*buf_out);
        gplog(LOG_ERR, "The configuration file was modified unexpectedly.");
        return DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL;
    }
    *buf_len = out_file_len;
    return DCMI_OK;
}

int dcmi_cfg_device_share_check_cfg_path(char *path, unsigned int path_size, char *path_bak, unsigned int path_bak_size)
{
    int ret;

#ifndef _WIN32
    ret = dcmi_cfg_device_share_get_cfg_path(path, path_size, path_bak, path_bak_size);
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#endif

    if (!dcmi_check_run_in_docker()) {
        ret = rename(path, path_bak);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "rename error. errno is %d", errno);
            return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
        }
    }

    return DCMI_OK;
}

int dcmi_cfg_device_share_write_to_file(const char *buf, unsigned int buf_len)
{
#ifdef _WIN32
    return DCMI_ERR_CODE_NOT_SUPPORT;
#else
    FILE *fp = NULL;
    char path[PATH_MAX + 1] = {0x00};
    char path_bak[PATH_MAX + 1] = {0x00};
    unsigned int write_len;
    int fd_num, ret;

    if (buf == NULL) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_cfg_device_share_check_cfg_path(path, sizeof(path), path_bak, sizeof(path_bak));
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    fp = fopen(path, "w");
    if (fp == NULL) {
        (void)rename(path_bak, path);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }
    fd_num = fileno(fp);
    if (fd_num >= 0) {
        (void)fchmod(fd_num, (S_IRUSR | S_IWUSR));
    }

    write_len = fwrite(buf, 1, buf_len, fp);
    if (write_len != buf_len) {
        gplog(LOG_ERR, "fwrite error. write_len is %u, buf_len is %u", write_len, buf_len);
        goto write_fail;
    }
    ret = fsync(fd_num);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "fsync error. errno is %d", errno);
        goto write_fail;
    }
    (void)fclose(fp);
    (void)unlink(path_bak);
    return DCMI_OK;

write_fail:
    (void)fclose(fp);
    (void)rename(path_bak, path);
    return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
#endif
}

int dcmi_cfg_insert_set_device_share_cmdline(int card_id, int chip_id, int enable_value)
{
    char *buf = NULL;
    unsigned int buf_len = 0;
    int ret, lock_fd;
    char cmdline_buf[DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN] = {0};
    FILE *fp = NULL;

    if (dcmi_board_chip_type_is_ascend_910_93() == TRUE) {
        ret = snprintf_s(cmdline_buf, sizeof(cmdline_buf), sizeof(cmdline_buf) - 1,
            "npu-smi set -t device-share -i %d -d %d\n", card_id, enable_value);
    } else {
        ret = snprintf_s(cmdline_buf, sizeof(cmdline_buf), sizeof(cmdline_buf) - 1,
            "npu-smi set -t device-share -i %d -c %d -d %d\n", card_id, chip_id, enable_value);
    }

    if (ret <= 0) {
        gplog(LOG_ERR, "snprintf_s failed, ret is %d", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmi_cfg_set_lock(&lock_fd, DCMI_CFG_GET_LOCK_TIMEOUT, DCMI_CFG_DEVICE_SHARE_LOCK_FILE_NAME);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "The config file resource is occupied.");
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    ret = dcmi_cfg_device_share_open_file(&fp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_device_share_open_file failed. ret is %d", ret);
        dcmi_cfg_set_unlock(lock_fd);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = dcmi_cfg_insert_device_share_cmdline_to_buffer(cmdline_buf, fp, &buf, &buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_insert_device_share_cmdline_to_buffer cmdline_buf %s failed. ret is %d",
              cmdline_buf, ret);
        if (ret == DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL) {
            gplog(LOG_ERR, "The configuration file was modified unexpectedly.");
        }
        fclose(fp);
        dcmi_cfg_set_unlock(lock_fd);
        return ret;
    }

    (void)fclose(fp);
    ret = dcmi_cfg_device_share_write_to_file(buf, buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_write_to_file failed, ret is %d", ret);
    }

    free(buf);
    dcmi_cfg_set_unlock(lock_fd);
    return ret;
}

static int dcmi_cfg_device_share_check_is_cover(const char *cmdline, char *buf_tmp)
{
    int ret = DCMI_CFG_DIFF_LINE;
    if (strstr(cmdline, buf_tmp) != NULL) {
        return DCMI_CFG_HAS_SAME_LINE;
    }

    // Compatible with earlier versions. must be overwritten.
    if (strncmp(cmdline, buf_tmp, strlen(buf_tmp) - DCMI_CFG_DEVICE_SHARE_DLINE_LEN) == 0) {
        ret = DCMI_CFG_COVER_LINE;
    }

    /* Adapting Persistence Configuration of Privilege Containers */
    if (strlen(cmdline) < DCMI_CFG_DEVICE_SHARE_CMD_LINE_LEN) {
        return DCMI_CFG_DIFF_LINE;
    }
    if (strlen(buf_tmp) < DCMI_CFG_DEVICE_SHARE_CMD_LINE_LEN) {
        return DCMI_CFG_DIFF_LINE;
    }
    if (strncmp(cmdline, buf_tmp, DCMI_CFG_DEVICE_SHARE_CMD_LINE_LEN) == 0) {
        ret = DCMI_CFG_COVER_LINE;
    }
    return ret;
}

static int dcmi_cfg_check_device_share_cmdline_is_correct(const char *cmdline, unsigned int *card_id_cmd,
    unsigned int  *chip_id_cmd, unsigned int *enable_type_cmd)
{
    int ret = 0;
    if (dcmi_board_chip_type_is_ascend_910_93() == TRUE) {
        ret = sscanf_s(cmdline, "npu-smi set -t device-share -i %u -d %u ", card_id_cmd, enable_type_cmd);
    } else {
        ret = sscanf_s(cmdline, "npu-smi set -t device-share -i %u -c %u -d %u ", card_id_cmd, chip_id_cmd,
            enable_type_cmd);
    }

    if (ret < 1) {
        gplog(LOG_ERR, "sscanf_s failed. ret is %d", ret);
    }
    return ret;
}

static int dcmi_cfg_device_share_get_action(unsigned int start, unsigned int end, const char *cmdline, char *buf_tmp)
{
    unsigned int card_id_tmp, chip_id_tmp, enable_type_tmp;
    unsigned int card_id_cmd, chip_id_cmd, enable_type_cmd;
    int ret;

    ret = dcmi_cfg_check_device_share_cmdline_is_correct(cmdline, &card_id_cmd, &chip_id_cmd, &enable_type_cmd);
    if (ret < 1) {
        gplog(LOG_ERR, "dcmi_cfg_check_device_share_cmdline_is_correct failed. ret is %d", ret);
        return DCMI_CFG_NOT_NEED_INSERT;
    }

    if (start != DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
        if (end == DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
            ret = dcmi_cfg_device_share_check_is_cover(cmdline, buf_tmp);
            if (ret != DCMI_CFG_DIFF_LINE) {
                return ret;
            }

            // 再次校验，防止文件被修改
            ret = dcmi_cfg_check_device_share_cmdline_is_correct(buf_tmp, &card_id_tmp, &chip_id_tmp, &enable_type_tmp);
            if (ret < 1) {
                gplog(LOG_ERR, "dcmi_cfg_check_device_share_cmdline_is_correct failed. ret is %d", ret);
                return DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL;
            }
            // 依据 卡ID 和 设备ID 判断是否插入在当前行后面
            if (card_id_tmp > card_id_cmd) {
                return DCMI_CFG_NEED_INSERT;
            } else if (!dcmi_board_chip_type_is_ascend_910_93() && (card_id_tmp == card_id_cmd) &&
                (chip_id_tmp > chip_id_cmd)) {
                return DCMI_CFG_NEED_INSERT;
            } else {
                return DCMI_CFG_NOT_NEED_INSERT;
            }
        } else {
            if ((end - start) >= 1) {
                return DCMI_CFG_NEED_INSERT;
            }
        }
    }
    return DCMI_CFG_NOT_NEED_INSERT;
}

int dcmi_cfg_insert_device_share_cmdline_to_buffer(const char *cmdline, FILE *fp, char **buf_out, unsigned int *len)
{
    int ret, action;
    char buf_tmp[DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN] = {0};
    unsigned int insert_flag = 0, line = 0, start_flag = 0, end_flag = 0;
    struct cfg_buf_info buf_info;

    (void)fseek(fp, 0, SEEK_END);
    buf_info.buf_size = (unsigned int)ftell(fp) + DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN + 1;
    rewind(fp);
    if (dcmi_cfg_malloc_buffer_and_init(buf_out, buf_info.buf_size) != DCMI_OK) {
        return DCMI_ERR_CODE_INNER_ERR;
    }
    buf_info.buf = *buf_out;

    while (!feof(fp)) {
        (void)memset_s(buf_tmp, sizeof(buf_tmp), 0, sizeof(buf_tmp));
        char *str = fgets(buf_tmp, sizeof(buf_tmp), fp);
        if (str == NULL) {
            break;
        }
        line++;

        if (insert_flag != DCMI_CFG_INSERT_COMPLETE) {
            if (end_flag == DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
                end_flag = (strcmp(buf_tmp, "[device-share-config end]\n") == 0) ? (line - 1) : end_flag;
            }

            action = dcmi_cfg_device_share_get_action(start_flag, end_flag, cmdline, buf_tmp);
            if (action == DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL) {
                return DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL;
            }
            ret = dcmi_cfg_process_action(action, &buf_info, len, cmdline, buf_tmp);
            insert_flag = ((ret == DCMI_CFG_INSERT_OK) ? DCMI_CFG_INSERT_COMPLETE : insert_flag);
            if (ret == DCMI_ERR_CODE_SECURE_FUN_FAIL) {
                goto SECURE_FUN_FAIL;
            }
            if (start_flag == DCMI_DEVICE_SHARE_FLAG_NOT_FIND) {
                start_flag = (strcmp(buf_tmp, "[device-share-config start]\n") == 0) ? (line - 1) : start_flag;
            }
        } else {
            ret = strncat_s(*buf_out, buf_info.buf_size, buf_tmp, strlen(buf_tmp));
            if (ret != 0) {
                goto SECURE_FUN_FAIL;
            }
            *len += strlen(buf_tmp);
        }
    }

    ret = (start_flag == 0) ? DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL : DCMI_OK;
    return ret;
SECURE_FUN_FAIL:
    gplog(LOG_ERR, "strncat_s failed. ret is %d", ret);
    return DCMI_ERR_CODE_SECURE_FUN_FAIL;
}

int dcmi_cfg_get_device_share_config_recover_mode(unsigned int *enable_flag)
{
    int ret;
    char buf_tmp[DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN] = {0};
    FILE *fp = NULL;
    char *str = NULL;
    int lock_fd;

    ret = dcmi_cfg_set_lock(&lock_fd, DCMI_CFG_GET_LOCK_TIMEOUT, DCMI_CFG_DEVICE_SHARE_LOCK_FILE_NAME);
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    ret = dcmi_cfg_device_share_open_file(&fp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_device_share_open_file failed. ret is %d", ret);
        dcmi_cfg_set_unlock(lock_fd);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = DCMI_ERR_CODE_DEVICE_SHARE_CONFIG_ILLEGAL;

    while (!feof(fp)) {
        (void)memset_s(buf_tmp, sizeof(buf_tmp), 0, sizeof(buf_tmp));
        str = fgets(buf_tmp, sizeof(buf_tmp), fp);
        if (str == NULL) {
            break;
        }

        if (strncmp(buf_tmp, "device-share-recover:enable", strlen("device-share-recover:enable")) == 0) {
            *enable_flag = DCMI_CFG_RECOVER_ENABLE;
            ret = DCMI_OK;
        } else if (strncmp(buf_tmp, "device-share-recover:disable", strlen("device-share-recover:disable")) == 0) {
            *enable_flag = DCMI_CFG_RECOVER_DISABLE;
            ret = DCMI_OK;
        }
        if (ret == DCMI_OK) {
            (void)fclose(fp);
            dcmi_cfg_set_unlock(lock_fd);
            return DCMI_OK;
        }
    }
    (void)fclose(fp);
    dcmi_cfg_set_unlock(lock_fd);
    gplog(LOG_OP, "The configuration file was modified unexpectedly.");
    return ret;
}

int dcmi_cfg_set_device_share_config_recover_mode(unsigned int enable_flag)
{
    int ret;
    char cmdline_buf[DCMI_DEVICE_SHARE_CONF_ONE_LINE_MAX_LEN] = {0};
    FILE *fp = NULL;
    char *buf = NULL;
    int lock_fd;
    unsigned int buf_len = 0;
    ret = snprintf_s(cmdline_buf, sizeof(cmdline_buf), sizeof(cmdline_buf) - 1,
        "device-share-recover:%s\n", (enable_flag == DCMI_CFG_RECOVER_ENABLE) ? "enable" : "disable");
    if (ret <= 0) {
        gplog(LOG_ERR, "snprintf_s failed, ret is %d, enable_flag is %u", ret, enable_flag);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmi_cfg_set_lock(&lock_fd, DCMI_CFG_GET_LOCK_TIMEOUT, DCMI_CFG_DEVICE_SHARE_LOCK_FILE_NAME);
    if (ret != DCMI_OK) {
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    ret = dcmi_cfg_device_share_open_file(&fp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_device_share_open_file failed. ret is %d", ret);
        dcmi_cfg_set_unlock(lock_fd);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = dcmi_cfg_set_device_share_recover_to_buffer(cmdline_buf, enable_flag, fp, &buf, &buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_set_recover_to_buffer cmdline_buf %s failed, ret is %d", cmdline_buf, ret);
        fclose(fp);
        dcmi_cfg_set_unlock(lock_fd);
        return ret;
    }

    (void)fclose(fp);
    ret = dcmi_cfg_device_share_write_to_file(buf, buf_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_cfg_device_share_write_to_file failed, ret is %d", ret);
    }

    free(buf);
    dcmi_cfg_set_unlock(lock_fd);
    return ret;
}