/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _WIN32
#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include "securec.h"
#include "dcmi_log.h"
#include "npu_common.h"
#include "npu_file_operate.h"

int get_file_length(const char *file, unsigned int *file_len)
{
    FILE *fp = NULL;

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
    if (check_filename(file, path, sizeof(path)) != DCMI_OK &&
        npu_get_chip_type() == NPU_CHIP_910B) {
        printf("\t%-30s : file path is illegal.\n", "Message");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (check_filename(file, path, sizeof(path)) != DCMI_OK) {
        printf("\t%-30s : Upgrade file path is illegal.\n", "Message");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#else
    char path[MAX_PATH + 1] = {0x00};
    if (check_filename(file, path, sizeof(path)) != DCMI_OK) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    if ((fp = fopen((const char *)path, "r")) == NULL) {
        printf("open file failed errno is %d.", errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fseek(fp, 0, SEEK_END);
    *file_len = ftell(fp);

    (void)fclose(fp);
    return NPU_OK;
}

int get_file_data(const char *file, unsigned char *fileBuf, unsigned int bufLen, unsigned int offset,
    unsigned int readLen)
{
    unsigned int fileLen;
    FILE *fp = NULL;

    if ((file == NULL) || (fileBuf == NULL)) {
        gplog(LOG_ERR, "file or fileBuf pointer is NULL.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (check_filename(file, path, sizeof(path)) != DCMI_OK) {
        printf("\t%-30s : file path is illegal.\n", "Message");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file failed errno is %d.", errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        gplog(LOG_ERR, "call fseek failed.\n");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    fileLen = (unsigned int)ftell(fp);
    if ((readLen > bufLen) || (readLen > (fileLen - offset))) {
        gplog(LOG_ERR, "readLen(%u) is bigger than bufLen(%u) or fileLen(%u).\n", readLen, bufLen, (fileLen - offset));
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(fp, offset, SEEK_SET) != 0) {
        gplog(LOG_ERR, "call fseek failed.\n");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fread(fileBuf, 1, readLen, fp) <= 0) {
        gplog(LOG_ERR, "call fread failed.\n");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);

    return NPU_OK;
}

int write_data_to_file(const char *file, const char *writeBuf, unsigned int bufLen, unsigned int writeLen)
{
    FILE *fp = NULL;

    if ((file == NULL) || (writeBuf == NULL)) {
        gplog(LOG_ERR, "file or writeBuf pointer is NULL.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (covert_file_path(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal errno(%d).\n", errno);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (writeLen > bufLen) {
        gplog(LOG_ERR, "writeLen(%u) is bigger than bufLen(%u).\n", writeLen, bufLen);
        return -1;
    }

    if ((fp = fopen((const char *)path, "w+b")) == NULL) {
        gplog(LOG_ERR, "open file failed，errno is %d.\n", errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)chmod((const char *)path, S_IRUSR | S_IWUSR);

    if (fseek(fp, 0, SEEK_SET) != 0) {
        gplog(LOG_ERR, "call fseek failed.\n");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fwrite(writeBuf, 1, writeLen, fp) <= 0) {
        gplog(LOG_ERR, "call fwrite failed.\n");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);

    return NPU_OK;
}

int get_file_directory(const char *file, char *fileDir, int dirLen)
{
    int ret, i;

    if ((file == NULL) || (fileDir == NULL)) {
        gplog(LOG_ERR, "file or fileDir pointer is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    for (i = (int)strlen(path) - 1; i >= 0; i--) {
        if (path[i] == '/') {
            ret = strncpy_s(fileDir, dirLen, (const char *)path, (i + 1));
            if (ret != 0) {
                gplog(LOG_ERR, "call strncpy_s failed.%d.", ret);
                return NPU_ERR_CODE_SECURE_FUN_FAIL;
            }
            return NPU_OK;
        }
    }

    gplog(LOG_ERR, "can not find '/' from file '%s'.", path);
    return NPU_ERR_CODE_INNER_ERR;
}

int remove_file(const char *filename)
{
#ifndef _WIN32
    if (remove(filename) != NPU_OK) {
        gplog(LOG_ERR, "call remove file %s failed.\n", filename);
    }
#endif
    return NPU_OK;
}

int remove_file_nftw(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    (void)sb;
    (void)typeflag;
    (void)ftwbuf;
    return remove_file(fpath);
}

int remove_dir(const char *dirname)
{
#ifndef _WIN32
    return nftw(dirname, remove_file_nftw, 2, FTW_DEPTH | FTW_PHYS);    // 最大目录层级深度为2
#endif
    return NPU_OK;
}

int read_file_to_buf(const char *path, unsigned char *data, long int data_size, unsigned int *data_len)
{
#ifndef _WIN32
    long int len;
    unsigned int read_count;
    FILE *file = NULL;
    char real_conf_path[PATH_MAX] = {0};

    if ((path == NULL) || (data == NULL)) {
        gplog(LOG_ERR, "file path or file buf pointer is NULL.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (check_filename(path, real_conf_path, sizeof(real_conf_path)) != DCMI_OK) {
        printf("\t%-30s : File path is illegal.\n", "Message");
        gplog(LOG_ERR, "File path is illegal.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((file = fopen(real_conf_path, "r")) == NULL) {
        gplog(LOG_ERR, "Open file %s failed.", real_conf_path);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        gplog(LOG_ERR, "Call fseek failed.");
        (void)fclose(file);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    len = ftell(file);
    if ((len > data_size) || (len <= 0)) {
        gplog(LOG_ERR, "ReadLen(%ld) is bigger than bufLen(%ld).", len, data_size);
        (void)fclose(file);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    rewind(file);
    read_count = fread(data, sizeof(char), len, file);
    if (read_count <= 0) {
        gplog(LOG_ERR, "Call fread failed.read_count=%u.", read_count);
        (void)fclose(file);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    *data_len = read_count;
    (void)fclose(file);
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int npu_create_lock_file(char *DIR, char *file, int *fd)
{
#ifndef _WIN32
    char dir_path[PATH_MAX + 1] = {0x00};
    int fd_curr = -1;
    char file_path[PATH_MAX + 1] = {0x00};
    char file_realpath[PATH_MAX + 1] = {0x00};
    int ret;

    if ((DIR == NULL) || (file == NULL) || (fd == NULL)) {
        gplog(LOG_ERR, "npu_create_lock_file invaild para");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (realpath(DIR, dir_path) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "npu_create_lock_file realpath error. errno is %d", errno);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (access(dir_path, F_OK) != NPU_OK) {
        if (mkdir(dir_path, S_IRWXU) != 0) {
            gplog(LOG_ERR, "npu_create_lock_file mkdir %s error. errno is %d", dir_path, errno);
            return NPU_ERR_CODE_INNER_ERR;
        }
    }

    ret = snprintf_s(file_path, PATH_MAX + 1, PATH_MAX, "%s/%s", dir_path, file);
    if (ret <= 0) {
        gplog(LOG_ERR, "npu_create_lock_file call snprintf_s failed.%d.\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (realpath(file_path, file_realpath) == NULL && errno != ENOENT) {
        gplog(LOG_ERR, "npu_create_lock_file file realpath error. errno is %d", errno);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    fd_curr = open(file_realpath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd_curr < 0) {
        gplog(LOG_ERR, "npu_create_lock_file:open file %s failed! errno is %d", file, errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    (void)fchmod(fd_curr, S_IRUSR);
    *fd = fd_curr;
    return NPU_OK;
#endif
    return NPU_OK;
}

int npu_set_file_lock(int fd, unsigned int timeout)
{
#ifndef _WIN32
    int ret;
    unsigned int index;
    unsigned int time_curr = 0;
    struct flock f_lock = {0};

    f_lock.l_type = F_WRLCK;
    f_lock.l_whence = 0;
    f_lock.l_len = 0;

    while (time_curr < timeout) {
        /* 首先循环一定次数尝试不阻塞方式获取锁 */
        for (index = 0; index < NPU_MUTEX_FIRST_TRY_TIMES; index++) {
            ret = fcntl(fd, F_SETLK, &f_lock);
            if (ret == NPU_OK) {
                return NPU_OK;
            }
        }

        /* 未获取到锁，等待1ms，再次尝试获取 */
        (void)usleep(NPU_MUTEX_SLEEP_TIME_1MS);
        time_curr++;
    }
    return NPU_ERR_CODE_INNER_ERR;
#else
    return NPU_OK;
#endif
}

void npu_set_file_unlock(int fd)
{
#ifndef _WIN32
    struct flock f_lock = {0};
    if (fd < 0) {
        gplog(LOG_ERR, "npu_set_file_unlock:fd invalid. fd = %d", fd);
        return;
    }

    f_lock.l_type = F_UNLCK;
    f_lock.l_whence = 0;
    f_lock.l_len = 0;

    fcntl(fd, F_SETLK, &f_lock);
    close(fd);
#endif
    return;
}
