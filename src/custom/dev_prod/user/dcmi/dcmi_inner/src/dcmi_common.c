/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
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
#include <sys/wait.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <fcntl.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_os_adapter.h"
#include "dcmi_log.h"
#include "dcmi_environment_judge.h"
#include "dcmi_common.h"

#define CRC_TABLE_SIZE    256
#define CRC_MASK          8

static unsigned short crc_tab[CRC_TABLE_SIZE] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c,
    0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318,
    0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4,
    0x5485, 0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611, 0x0630,
    0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4,
    0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969,
    0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf,
    0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13,
    0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9,
    0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046,
    0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2,
    0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 0x34e2,
    0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e,
    0xc71d, 0xd73c, 0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e,
    0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1,
    0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07,
    0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9,
    0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

unsigned short crc16(unsigned char *buffer, unsigned int length)
{
    unsigned short crc = 0;
    unsigned char *data = buffer;
    unsigned int data_len = length;

    if (buffer == NULL || length == 0) {
        return 0;
    }

    while (data_len-- != 0) {
        crc = (crc << CRC_MASK) ^ crc_tab[((crc >> CRC_MASK) ^ *data++) & 0xff];
    }

    return crc;
}

/*****************************************************************************
 函 数 名  : safe_exec
 功能描述  : 安全system函数
 输入参数  : cmd_path: 命令路径
             cmd: 命令参数
 输出参数  : 无
*****************************************************************************/
int safe_exec(const char *cmd_path, char *cmd[])
{
#ifndef _WIN32
    pid_t pid;
    int status = 0;
    int j;
    int fds;

    if ((cmd_path == NULL) || (cmd == NULL)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if ((pid = fork()) < 0) {
        return DCMI_ERR_CODE_INNER_ERR;
    }

    if (pid == 0) {  /* child */
        for (j = FD_SERVICE_MIN, fds = getdtablesize(); j < fds; j++) {
            (void)close(j);
        }

        if (execv(cmd_path, cmd) < 0) {
            exit(errno);
        }
    } else {    /* parent */
        (void)waitpid(pid, &status, 0);
        if ((WIFEXITED(status) == 0) || (WEXITSTATUS(status)) != 0) {
            return DCMI_ERR_CODE_INNER_ERR;
        }
    }
    return DCMI_OK;
#else
    return DCMI_ERR_CODE_NOT_SUPPORT;
#endif
}

int dcmi_file_realpath_disallow_nonexist(const char *file, char *path, int path_len)
{
    int check_result;
    (void)path_len;
#ifndef _WIN32
    check_result = ((file == NULL) || (strlen(file) > PATH_MAX) || (realpath(file, path) == NULL));
#else
    check_result = ((file == NULL) || (strlen(file) > MAX_PATH) || (PathCanonicalizeA(path, file) == FALSE));
#endif
    if (check_result) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    return DCMI_OK;
}

int dcmi_file_realpath_allow_nonexist(const char *file, char *path, int path_len)
{
    int check_result;
    (void)path_len;
#ifndef _WIN32
    check_result = ((file == NULL) || (strlen(file) > PATH_MAX) ||
                    ((realpath(file, path) == NULL) && (errno != ENOENT)));
#else
    check_result = ((file == NULL) || (strlen(file) > MAX_PATH) ||
                    ((PathCanonicalizeA(path, file) == FALSE) && (errno != ENOENT)));
#endif
    if (check_result) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    return DCMI_OK;
}

int dcmi_get_file_length(const char *file, unsigned int *file_len)
{
    FILE *fp = NULL;
    int ret;
#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif

    ret = dcmi_file_realpath_disallow_nonexist(file, path, sizeof(path));
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_file_realpath_disallow_nonexist failed. ret is %d.", ret);
        return ret;
    }

    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file failed errno is %d.", errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fseek(fp, 0, SEEK_END);
    *file_len = ftell(fp);

    (void)fclose(fp);
    return DCMI_OK;
}

int dcmi_safe_exec_syscmd_without_output(char *cmdstring[])
{
#ifndef _WIN32
    pid_t pid;
    int status;
    int rc = -1;

    if (cmdstring == NULL) {
        return -1;
    }

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) {
        // child process
        int fd = open("/dev/null", O_WRONLY);
        if (fd < 0) {
            exit(1);
            return rc;
        }
        dup2(fd, 0); /* 0,1,2代表子进程的标准输入输出 */
        dup2(fd, 1); /* 0,1,2代表子进程的标准输入输出 */
        dup2(fd, 2); /* 0,1,2代表子进程的标准输入输出 */
        (void)execvp(cmdstring[0], cmdstring);
        close(fd);
        exit(1);
    } else {
        // parent process
        (void)waitpid(pid, &status, 0);
        if (WIFEXITED(status) != 0) {
            rc = (int)WEXITSTATUS(status);
        }
    }

    return rc;
#else
    return 0;
#endif
}

int dcmi_is_specific_char(const char temp_char)
{
    int ret = FALSE;
    switch (temp_char) {
        case '_':
        case '.':
        case '/':
        case '-':
#ifdef _WIN32
        case '\\':
        case ':':
#endif
            ret = TRUE;
            break;
        default:
            break;
    }
    return ret;
}

int dcmi_check_file_path(const char *path)
{
    size_t i;

    if (path == NULL) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; path[i]; i++) {
        if (!isalnum(path[i])) {
            if (!dcmi_is_specific_char(path[i])) {
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
        }
    }
    return DCMI_OK;
}

int str2ull(unsigned long long *ptmp_num, const char *str)
{
    unsigned long long num = 0;
    char *end_ptr = NULL;
 
    if (!ptmp_num || !str) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (*str == '\0') {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    errno = 0;
    num = strtoull(str, &end_ptr, 0);
 
    if (end_ptr == str || *end_ptr != '\0' || errno == ERANGE) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    *ptmp_num = num;
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_convert_str_to_int
  功能描述		:  将字符串str转换为int类型index
  输入参数		:  str : 待转换的字符串
  输出参数		:  index : 转换后的int类型值
  返 回 值		:  转换成功，返回DCMI_OK，否则返回对应错误码
*******************************************************************************/
int dcmi_convert_str_to_int(const char* str, int *index)
{
    int ret = sscanf_s(str, "%d", index);
    if (ret <= 0) {
        gplog(LOG_ERR, "Call sscanf_s failed.(ret=%d).", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_determine_file_type
  功能描述		:  确定给定文件的类型是否与指定的文件类型匹配
  输入参数		:  file : 待检测的文件路径指针
                  fileType : 指定的文件类型 字符串指针
                  typeLen  : 文件类型的长度
  输出参数		:  None
  返 回 值		:  匹配成功，返回DCMI_OK，否则返回对应错误码
*******************************************************************************/
int dcmi_determine_file_type(const char *file, const char *fileType, int typeLen)
{
    int ret, i;

    if ((file == NULL) || (fileType == NULL)) {
        gplog(LOG_ERR, "file or fileType pointer is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    // 文件路径校验
    ret = dcmi_check_filename(file, path, sizeof(path));
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    // 文件格式校验 从后往前遍历文件路径，找到第一个'.'，并比较其后的字符串是否与fileType一致
    for (i = (int)strlen(path) - 1; i >= 0; i--) {
        if (path[i] == '.') {
            ret = strncmp((const char *)&path[i + 1], fileType, typeLen);
            if (ret != 0) {
                gplog(LOG_ERR, "file is not %s file.", fileType);
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
            return DCMI_OK;
        }
    }

    gplog(LOG_ERR, "can not find the file.");
    return DCMI_ERR_CODE_INNER_ERR;
}

/*******************************************************************************
  函 数 名		:  dcmi_check_filename
  功能描述		:  验证文件路径的有效性并转换为规范路径
  输入参数		:  file : 输入文件路径字符串，可能包含相对路径或绝对路径，如：
                         "/home/user/../user/dcmi/./file.txt"
                  path : 存储规范后的文件路径
                  len  : 输出缓冲区path的长度
  输出参数		:  path : 存储规范后的文件路径，如：
                          "/home/user/Documents/file.txt"
  返 回 值		:  成功提取返回DCMI_OK，失败则返回相应错误码
*******************************************************************************/
int dcmi_check_filename(const char *file, char *path, int len)
{
#ifndef _WIN32
    if (len < PATH_MAX) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > PATH_MAX) || (realpath(file, path) == NULL)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#else
    if (len < MAX_PATH) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > MAX_PATH) || (PathCanonicalizeA(path, file) == FALSE)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_file_directory
  功能描述		:  从完整文件路径中提取文件所在的目录路径
  输入参数		:  file : 输入文件路径字符串，可能包含相对路径或绝对路径
                  fileDir : 输出缓冲区，存放提取的目录路径
                  dirLen  : 输出缓冲区fileDir的长度
  输出参数		:  fileDir : 输出缓冲区，存放提取的目录路径
  返 回 值		:  执行状态码，成功：0，失败：非0
*******************************************************************************/
int dcmi_get_file_directory(const char *file, char *fileDir, int dirLen)
{
    int ret, i;

    if ((file == NULL) || (fileDir == NULL)) {
        gplog(LOG_ERR, "file or fileDir pointer is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (dcmi_check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    for (i = (int)strlen(path) - 1; i >= 0; i--) {
        if (path[i] == '/') {
            ret = strncpy_s(fileDir, dirLen, (const char *)path, (i + 1));
            if (ret != 0) {
                gplog(LOG_ERR, "call strncpy_s failed.%d.", ret);
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
            return DCMI_OK;
        }
    }

    gplog(LOG_ERR, "can not find '/' from file '%s'.", path);
    return DCMI_ERR_CODE_INNER_ERR;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_file_data
  功能描述		:  从指定路径的文件file中，从offset偏移位置开始，读取readLen长度的数据，
                  存入fileBuf缓冲区中
  输入参数		:  file : 输入文件路径字符串，可能包含相对路径或绝对路径
                  bufLen : 缓冲区的大小
                  offset : 从文件中读取数据的起始偏移位置
                  readLen : 要读取的数据长度
  输出参数		:  fileBuf : 存储读取数据的缓冲区
  返 回 值		:  读取成功，返回DCMI_OK，否则返回相应错误码
*******************************************************************************/
int dcmi_get_file_data(const char *file, unsigned char *fileBuf, unsigned int bufLen, unsigned int offset,
    unsigned int readLen)
{
    unsigned int fileLen;
    FILE *fp = NULL;

    if ((file == NULL) || (fileBuf == NULL)) {
        gplog(LOG_ERR, "file or fileBuf pointer is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (dcmi_check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file failed errno is %d.", errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        gplog(LOG_ERR, "call fseek failed.\n");
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    fileLen = (unsigned int)ftell(fp);
    if ((readLen > bufLen) || (readLen > (fileLen - offset))) {
        gplog(LOG_ERR, "readLen(%u) is bigger than bufLen(%u) or fileLen(%u).\n", readLen, bufLen, (fileLen - offset));
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(fp, offset, SEEK_SET) != 0) {
        gplog(LOG_ERR, "call fseek failed.\n");
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fread(fileBuf, 1, readLen, fp) <= 0) {
        gplog(LOG_ERR, "call fread failed.\n");
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_remove_file
  功能描述		:  删除指定路径的文件
  输入参数		:  filename : 待删除的文件路径
  输出参数		:  None
  返 回 值		:  删除成功或函数未执行(非Windows)，返回DCMI_OK；否则返回相应失败码
*******************************************************************************/
int dcmi_remove_file(const char *filename)
{
#ifndef _WIN32
    if (remove(filename) != DCMI_OK) {
        gplog(LOG_ERR, "call remove file %s failed.", filename);
    }
#endif
    return DCMI_OK;
}

int dcmi_remove_file_nftw(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    (void)sb;
    (void)typeflag;
    (void)ftwbuf;
    return dcmi_remove_file(fpath);
}

/*******************************************************************************
  函 数 名		:  dcmi_remove_dir
  功能描述		:  递归删除指定目录及其所有子目录和文件(适用非Windows)，调用回调函数
                  dcmi_remove_file_nftw删除每个文件，目录的最大层级深度为2
  输入参数		:  dirname : 待删除的目录路径
  输出参数		:  None
  返 回 值		:  删除成功或函数未执行(Windows)，返回DCMI_OK；否则返回相应失败码
*******************************************************************************/
int dcmi_remove_dir(const char *dirname)
{
#ifndef _WIN32
    return nftw(dirname, dcmi_remove_file_nftw, 2, FTW_DEPTH | FTW_PHYS);    // 最大目录层级深度为2
#endif
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_extract_targz_package
  功能描述		:  解压指定的文件sourceFile到目标路径targetPath
  输入参数		:  sourceFile : 源文件路径
                  targetPath : 目标路径
  输出参数		:  None
  返 回 值		:  解压成功，返回DCMI_OK，否则返回相应错误码
*******************************************************************************/
int dcmi_extract_targz_package(const char *sourceFile, const char *targetPath)
{
    int ret;
    char cmdBuf[DCMI_BUFF_MAX_LEN] = {0x00};

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (dcmi_check_filename(sourceFile, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = snprintf_s(cmdBuf, DCMI_BUFF_MAX_LEN, DCMI_BUFF_MAX_LEN - 1, "tar -mzxf %s -C %s", path, targetPath);
    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d.\n", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    /* 存放的是指向每一个参数的指针 */
    char *exec_argv[6] = {"tar", "-mzxf", path, "-C", (char*)targetPath, NULL};
    ret = safe_exec("/bin/tar", exec_argv);
    if (ret != 0) {
        gplog(LOG_ERR, "%s failed.%d.", cmdBuf, ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_convert_file_path
  功能描述		:  将输入的相对文件路径转换为规范化的绝对路径
  输入参数		:  file : 原始文件路径（可以是相对路径或绝对路径）
                  len : path缓冲区的最大长度
  输出参数		:  path : 存储转换后规范路径的缓冲区
  返 回 值		:  转换成功返回DCMI_OK，否则返回相应错误码
*******************************************************************************/
int dcmi_convert_file_path(const char *file, char *path, int len)
{
#ifndef _WIN32
    if (len < PATH_MAX) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > PATH_MAX)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((realpath(file, path) == NULL) && (errno != ENOENT)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#else
    if (len < MAX_PATH) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > MAX_PATH)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((PathCanonicalizeA(path, file) == FALSE) && (errno != ENOENT)) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#endif
    return DCMI_OK;
}

int dcmi_write_data_to_file(const char *file, const char *writeBuf, unsigned int bufLen, unsigned int writeLen)
{
    FILE *fp = NULL;

    if ((file == NULL) || (writeBuf == NULL)) {
        gplog(LOG_ERR, "file or writeBuf pointer is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (dcmi_convert_file_path(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal errno(%d).", errno);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    if (writeLen > bufLen) {
        gplog(LOG_ERR, "writeLen(%u) is bigger than bufLen(%u).", writeLen, bufLen);
        return -1;
    }

    if ((fp = fopen((const char *)path, "w+b")) == NULL) {
        gplog(LOG_ERR, "open file failed, errno is %d.", errno);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)chmod((const char *)path, S_IRUSR | S_IWUSR);

    if (fseek(fp, 0, SEEK_SET) != 0) {
        gplog(LOG_ERR, "call fseek failed.");
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fwrite(writeBuf, 1, writeLen, fp) <= 0) {
        gplog(LOG_ERR, "call fwrite failed.");
        (void)fclose(fp);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);

    return DCMI_OK;
}