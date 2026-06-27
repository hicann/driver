/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "log.h"
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>
#include "securec.h"
#include "user_log.h"
#include "cfg.h"
#include "hccn_comm.h"

#define FILE_MASK_WC 0640
#define UNIT_THOUSAND 1000
#define BEGIN_YEAR 1900
#define SYS_OK 0
#define SYS_ERROR (-1)
#define LOGFILE_MAX_SIZE (5 * 1024 * 1024)
#define LOG_PRINT_TOTAL_SIZE 1024
#define LOG_PRINT_TIMESTR_SIZE 128
#define HCCN_LOG_SUFFIX_LEN 7
#define HCCN_LOG_MAX_RETRY  100
#define HCCN_LOG_HEAD_LEN   13

#define FILE_PATH_LEN 64
#define FILE_NAME_LEN 128
#define FILE_LOCK_LEN 128

#define IS_SET_CMD_LOG 0
#define IS_GET_CMD_LOG 1

#define UCHAR_MAX 255

static char g_cdr_reg_file_name[FILE_NAME_LEN];

#define CLOSE_AND_SET_FD_INVALID(ret, fd)    \
    do {                                \
        ret = close((fd));                \
        if (ret) {                  \
            printf("close log handle failed, errno(%d)\n", errno);             \
        }                 \
        (fd) = -1;                  \
    } while (0)

#define XFREE(ps)           \
    do {                    \
        if ((ps) != NULL) { \
            free((ps));     \
            (ps) = NULL;    \
        }                   \
    } while (0)

typedef struct {
    char *buff;
    unsigned int buffLen;
} Buffer;

STATIC int HccnOpenByMode(const char *pathName, int flags, mode_t mode)
{
    char *file_ret = NULL;
    char actualPath[PATH_MAX + 1] = {0};//lint !e813

    if ((pathName == NULL) || (flags < 0)) {
        roce_err("params invaild, pathName : %p, flags : %d.", pathName, flags);
        return SYS_ERROR;
    }

    if (strlen(pathName) > PATH_MAX) {
        roce_err("path_len[%lu] > [%d](PATH_MAX)", strlen(pathName), PATH_MAX);
        return SYS_ERROR;
    }

    file_ret = realpath(pathName, actualPath);
    if (file_ret == NULL) {
        roce_warn("log file doesn't exist, create it.");
    }

    return open(actualPath, flags, mode);
}

/**
 * @brief HccnGetTimeForLog: get local timestamp
 * @param [in]bufLen: length of timeBuffer
 * @param [in]timeBuffer: buffer to store timestamp string
 */
STATIC void HccnGetTimeForLog(unsigned int bufLen, char *timeBuffer)
{
    struct timeval timeVal = { 0 };
    struct tm nowTime = { 0 };

    if (timeBuffer == NULL) {
        roce_err("timeBuffer is NULL.");
        return;
    }

    if ((gettimeofday(&timeVal, NULL)) != SYS_OK) {
        roce_err("gettimeofday fail, errno : %d.", errno);
        return;
    }

    if (localtime_r(&(timeVal.tv_sec), &nowTime) == NULL) {
        roce_err("localtime_r fail, errno : %d.", errno);
        return;
    }

    int ret = snprintf_s(timeBuffer, bufLen, bufLen - 1, "%04d-%02d-%02d %02d:%02d:%02d.%03ld",
                         nowTime.tm_year + BEGIN_YEAR, nowTime.tm_mon + 1, nowTime.tm_mday,
                         nowTime.tm_hour, nowTime.tm_min,
                         nowTime.tm_sec, (timeVal.tv_usec / UNIT_THOUSAND));
    if (ret <= 0) {
        roce_err("snprintf_s fail, ret : %d.", ret);
        return;
    }
}

STATIC int HccnCatStr(const char *str1, unsigned int len1, const char *str2, unsigned int len2, Buffer *buffer)
{
    if ((str1 == NULL) || (str2 == NULL) || (buffer->buff == NULL) || (len1 + len2 >= buffer->buffLen)) {
        roce_err("params invalid, str1 : %p, str2 : %p, buffer->buff : %p, (len1 + len2) : %u, buffer->buffLen : %u.",
                 str1, str2, buffer->buff, (len1 + len2), buffer->buffLen);
        return SYS_ERROR;
    }

    int ret = strcpy_s(buffer->buff, buffer->buffLen, str1);
    if (ret != EOK) {
        roce_err("strcpy_s err[%d], len : %u, str1 len : %lu.", ret, buffer->buffLen, strlen(str1));
        return SYS_ERROR;
    }

    // join two string
    ret = strcpy_s(buffer->buff + strlen(str1), buffer->buffLen - strlen(str1), str2);
    if (ret != EOK) {
        roce_err("strcpy_s err[%d], len : %u, str2 len : %lu.", ret, buffer->buffLen - strlen(str1), strlen(str2));
        return SYS_ERROR;
    }
    return SYS_OK;
}

STATIC void HccnCheckRingFileLen(const char *hccnFile, const char *newFileName)
{
    struct stat logStat = { 0 };

    if (stat(hccnFile, &logStat) < 0) {
        roce_warn("file : %s stat fail.", hccnFile);
        return;
    }
    // check log size to judge whether log file already rotated
    if (logStat.st_size < (LOGFILE_MAX_SIZE - LOG_PRINT_TOTAL_SIZE)) {
        return;
    }

    if (remove(newFileName) != 0) {
        roce_warn("file : %s remove fail, errno : %d.", newFileName, errno);
    }

    // readonly, 440
    if (chmod(hccnFile, S_IRUSR | S_IRGRP) != 0) {
        roce_warn("file : %s chmod fail, errno : %d.", hccnFile, errno);
    }

    if (rename(hccnFile, newFileName)) {
        roce_warn("file : %s rename fail, errno : %d.", hccnFile, errno);
    }
}

/**
* @brief HccnSetRingFile: set self dfx log file ring. lock log file during log rotation
* @param [in]hccnFile: log file path
*/
STATIC void HccnSetRingFile(const char *hccnFile, const char *logFileLock)
{
    const char logFileSuffix[HCCN_LOG_SUFFIX_LEN + 1] = ".old";

    int len = strlen(hccnFile) + 1;
    if (len <= 1) {
        roce_err("len : %d is an invalid value.", len);
        return;
    }
    char *newFileName = (char *)malloc(len + HCCN_LOG_SUFFIX_LEN);
    if (newFileName == NULL) {
        roce_err("malloc fail, len : %d.", len + HCCN_LOG_SUFFIX_LEN);
        return;
    }

    if (memset_s(newFileName, len + HCCN_LOG_SUFFIX_LEN, 0x00, len + HCCN_LOG_SUFFIX_LEN)) {
        roce_err("memset_s error.");
        goto err_handle;
    }
    Buffer buffer = { newFileName, len + HCCN_LOG_SUFFIX_LEN };
    int ret = HccnCatStr(hccnFile, strlen(hccnFile), logFileSuffix, strlen(logFileSuffix), &buffer);
    if (ret != SYS_OK) {
        goto err_handle;
    }

    int lockFd = HccnOpenByMode(logFileLock, O_CREAT | O_RDWR, FILE_MASK_WC);
    if (lockFd < 0) {
        roce_err("file %s open fail, fd : %d.", logFileLock, lockFd);
        goto err_handle;
    }
    // non-blocking lock. if failed to fetch lock, immediately exit func
    if (flock(lockFd, LOCK_EX | LOCK_NB) < 0) {
        CLOSE_AND_SET_FD_INVALID(ret, lockFd);
        goto err_handle;
    }

    HccnCheckRingFileLen(hccnFile, newFileName);

    XFREE(newFileName);
    if (flock(lockFd, LOCK_UN) != 0) {
        roce_warn("fd : %d unlock fail, errno : %d.", lockFd, errno);
    }
    CLOSE_AND_SET_FD_INVALID(ret, lockFd);
    if (remove(logFileLock) != 0) {
        roce_warn("file : %s remove fail, errno : %d.", logFileLock, errno);
    }
    return;

err_handle:
    XFREE(newFileName);
    return;
}

/**
 * @brief HccnGetRingFd: get logfile fd which to be written
 * @param [in]hccnFile: upgrade logfile path
 * @param [in]msg: log msg to be written
 * @return: success:fd, failed:SYS_ERROR(-1)
 */
STATIC int HccnGetRingFd(const char *logFilePath, const char *hccnFile, const char *msg)
{
    int fd = 0;
    int cnt = 0;
    int renameFlag = 0;
    struct stat buf = { 0 };
    char logFileLock[FILE_LOCK_LEN] = {0};
    int ret;

    ret = sprintf_s((char *)logFileLock, FILE_LOCK_LEN, "%s/hccn.lock", logFilePath);
    if (ret <= 0) {
        roce_err("sprintf_s for root failed, ret:%d logFilePath:%s", ret, logFilePath);
        return -ENOMEM;
    }

    do {
        cnt++;
        fd = HccnOpenByMode(hccnFile, O_CREAT | O_WRONLY | O_APPEND, FILE_MASK_WC);
        if (fd < 0) {
            renameFlag = 0;
            roce_warn("open %s failed, errno=%d\n", hccnFile, errno);
            continue;
        }

        ret = flock(fd, LOCK_EX);
        if (ret) {
            renameFlag = 0;
            roce_warn("flock %s failed, errno=%d\n", hccnFile, errno);
            CLOSE_AND_SET_FD_INVALID(ret, fd);
            continue;
        }

        // get logFile size
        if (fstat(fd, &buf) < 0) {
            renameFlag = 0;
            flock(fd, LOCK_UN);
            CLOSE_AND_SET_FD_INVALID(ret, fd);
            continue;
        }
        unsigned int sum = (buf.st_size + strlen(msg));
        if ((sum > buf.st_size) && (sum > strlen(msg)) && (sum >= LOGFILE_MAX_SIZE)) {
            flock(fd, LOCK_UN);
            CLOSE_AND_SET_FD_INVALID(ret, fd);
            HccnSetRingFile(hccnFile, logFileLock);
            renameFlag = 1;
        } else {
            renameFlag = 0;
        }
    } while (renameFlag && cnt <= HCCN_LOG_MAX_RETRY);

    return fd;
}

STATIC void HccnFillMsg(char *msg, unsigned int msgLen, const char *format, va_list arg)
{
    int ret;
    int len, offset;
    char timeStamp[LOG_PRINT_TIMESTR_SIZE + 1] = { 0 };
    char logStr[LOG_PRINT_TOTAL_SIZE] = { 0 };

    HccnGetTimeForLog(LOG_PRINT_TIMESTR_SIZE, timeStamp);
    ret = vsnprintf_s(logStr, LOG_PRINT_TOTAL_SIZE, LOG_PRINT_TOTAL_SIZE - 1, format, arg);
    if (ret <= 0) {
        printf("copy format to logStr failed, ret[%d]\n", ret);
        goto out;
    }

    offset = HCCN_LOG_HEAD_LEN + strlen(hccn_get_g_usr_name());
    ret = strncpy_s(msg, msgLen, logStr, offset);
    if (ret != SYS_OK) {
        printf("copy log head to msg failed, ret(%d)\n", ret);
        goto out;
    }
    len = strlen(msg);
    ret = strncpy_s(msg + len, msgLen - len, timeStamp, strlen(timeStamp));
    if (ret != SYS_OK) {
        printf("copy timeStamp to msg failed, ret(%d)\n", ret);
        goto out;
    }

    len = strlen(msg);
    ret = strncpy_s(msg + len, msgLen - len, logStr + offset,
        strlen(logStr) - offset);
    if (ret != SYS_OK) {
        printf("copy log tail to msg failed, ret(%d)\n", ret);
        goto out;
    }
out:
    va_end(arg);
    return;
}

STATIC int GetLogFilePath(char *logPath, unsigned int pathLen)
{
    int ret, ret_val;
    struct passwd *pwd = getpwuid(getuid());

    if (pwd == NULL) {
        roce_err("pwd is NULL");
        return -EINVAL;
    }
    
    if (pwd->pw_name == NULL) {
        roce_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out;
    }

    if (strncmp(pwd->pw_name, "root", strlen("root") + 1) == 0) {
        ret = sprintf_s((char *)logPath, FILE_PATH_LEN, "/var/log/hccn_tool");
        if (ret <= 0) {
            roce_err("sprintf_s for root failed, ret:%d ", ret);
            ret = -ENOMEM;
            goto out;
        }
    } else {
        ret = sprintf_s((char *)logPath, FILE_PATH_LEN, "/home/%s", pwd->pw_name);
        if (ret <= 0) {
            roce_err("sprintf_s for user name:%s failed, ret:%d ", pwd->pw_name, ret);
            ret = -ENOMEM;
            goto out;
        }
    }

    ret = 0;
out:
    ret_val = memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    if (ret_val) {
        roce_err("memset error, ret_val[%d]", ret_val);
        ret = ret_val;
    }

    return ret;
}

STATIC int CheckFilePath(const char *path, mode_t mode)
{
    int ret;
    char realConfPath[PATH_MAX + 1] = {0};//lint !e813
    struct stat file_stat = { 0 };
    static unsigned char not_dir_flag = 0; // 0 means first time

    if (path == NULL) {
        roce_err("path is NULL");
        return -EINVAL;
    }

    if (strlen(path) > PATH_MAX) {
        roce_err("path_len[%lu] > [%d](PATH_MAX)", strlen(path), PATH_MAX);
        return -EINVAL;
    }

    if (realpath(path, realConfPath) == NULL) {
        ret = -errno;
        if (ret != -ENOENT) {
            roce_err("path[%s] is invalid, err[%d]", path, ret);
            return ret;
        }

        roce_info("path[%s] is not exist, real_path[%s]", path, realConfPath);
        ret = mkdir(realConfPath, mode);
        if (ret) {
            if (errno == EEXIST) {
                roce_info("realConfPath[%s] already exists, ret[%d], err[%d]", realConfPath, ret, errno);
                return 0;
            }
            roce_err("mkdir realConfPath[%s] failed, ret[%d], err[%d]", realConfPath, ret, errno);
            return ret;
        }
    }

    // check if realConfPath is a directory
    ret = stat(realConfPath, &file_stat);
    if (ret == 0) {
        if ((file_stat.st_mode & S_IFMT) == S_IFREG) {
            // warning only first time
            if (not_dir_flag == 0) {
                printf("[WARNING] \"%s\" is not a directory, hccn_tool logs may be lost.\n", realConfPath);
            }
            // prevent flag is out-of-bounds
            if (not_dir_flag == UCHAR_MAX) {
                not_dir_flag = 0;
            }
            not_dir_flag++;
            return ENOTDIR;
        }
    } else {
        roce_err("get realConfPath[%s] stat failed, ret[%d], err[%d]", realConfPath, ret, errno);
        return ret;
    }

    return 0;
}

void PrintLog(int cmd_type, const char *format, va_list args)
{
    int ret;
    char msg[LOG_PRINT_TOTAL_SIZE + 1] = { 0 };
    char logFilePath[FILE_PATH_LEN] = {0};
    char logFileName[FILE_NAME_LEN] = {0};

    if (format == NULL) {
        return;
    }

    ret = GetLogFilePath(logFilePath, FILE_PATH_LEN);
    if (ret) {
        roce_err("GetLogFilePath failed, ret:%d", ret);
        return;
    }

    ret = CheckFilePath(logFilePath, S_IRUSR | S_IWUSR | S_IRGRP);
    if (ret) {
        if (ret != ENOTDIR) {
            roce_err("CheckFilePath failed, ret:%d", ret);
        }
        return;
    }

    if (cmd_type == IS_GET_CMD_LOG) {
        ret = sprintf_s((char *)logFileName, FILE_NAME_LEN, "%s/hccn.log", logFilePath);
    } else {
        ret = sprintf_s((char *)logFileName, FILE_NAME_LEN, "%s/hccn_config.log", logFilePath);
    }
    
    if (ret <= 0) {
        roce_err("sprintf_s for root failed, ret:%d logFilePath:%s", ret, logFilePath);
        return;
    }

    // Check if it's a symbolic link
    struct stat buf = { 0 };
    if (lstat(logFileName, &buf) == 0 && (S_IFMT & buf.st_mode) == S_IFLNK) {
        roce_err("Lstat failed: %s is a symbolic link", logFileName);
        return;
    }

    // Fill message
    HccnFillMsg(msg, LOG_PRINT_TOTAL_SIZE + 1, format, args);

    // Get file descriptor
    int fd = HccnGetRingFd(logFilePath, logFileName, msg);
    if (fd < 0) {
        roce_err("HccnGetRingFd failed(fd=%d)", fd);
        return;
    }

    // Write message to file
    ret = write(fd, msg, strlen(msg));
    if (ret < 0) {
        roce_err("Write fail(ret=%d)", ret);
    }

    // Unlock and close file descriptor
    flock(fd, LOCK_UN);
    CLOSE_AND_SET_FD_INVALID(ret, fd);
    return;
}


void HccnPrintLog(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    PrintLog(IS_GET_CMD_LOG, format, args);
    va_end(args);
}

void HccnPrintSetConfigLog(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    PrintLog(IS_SET_CMD_LOG, format, args);
    va_end(args);
}

void HccnCdrRegPrintLog(const char *format, ...)
{
    char msg[LOG_PRINT_TOTAL_SIZE + 1] = {0};
    char logStr[LOG_PRINT_TOTAL_SIZE] = {0};
    FILE *fp = NULL;
    size_t write_cnt;
    va_list arg;
    int ret;
    
    if (format == NULL) {
        roce_err("Format null.");
        return;
    }

    va_start(arg, format);
    ret = vsnprintf_s(logStr, LOG_PRINT_TOTAL_SIZE, LOG_PRINT_TOTAL_SIZE - 1, format, arg);
    if (ret <= 0) {
        roce_err("Copy format to logStr failed, (ret=%d)", ret);
        goto out;
    }

    ret = strncpy_s(msg, (LOG_PRINT_TOTAL_SIZE + 1), logStr, strlen(logStr));
    if (ret != SYS_OK) {
        roce_err("Copy log msg failed, (ret=%d)", ret);
        goto out;
    }

    fp = fopen(g_cdr_reg_file_name, "a+");
    if (fp == NULL) {
        roce_err("Open log file failed. (file=\"%s\")", g_cdr_reg_file_name);
        goto out;
    }

    write_cnt = fwrite(msg, 0x1, strlen(logStr), fp);
    if (write_cnt < strlen(logStr)) {
        roce_err("Write log file failed. (write_cnt=%d; file=\"%s\")", write_cnt, g_cdr_reg_file_name);
    }

    (void)fclose(fp);
out:
    va_end(arg);
}

int generate_file_name(int prefix)
{
#define TIME_BEGIN_YEAR 1900
#define MS_TO_US_CNT 1000
    struct timeval timeVal = {0};
    struct tm nowTime = {0};
    int ret;

    if ((gettimeofday(&timeVal, NULL)) != 0) {
        roce_err("Gettimeofday failed. (errno=%d)", errno);
        return SYS_ERROR;
    }

    if (localtime_r(&(timeVal.tv_sec), &nowTime) == NULL) {
        roce_err("Localtime_r failed. (errno=%d)", errno);
        return SYS_ERROR;
    }

    ret = sprintf_s(g_cdr_reg_file_name, MAX_LOG_NAME_LEN, "device-%d-CdrReg_%d%d%d%d%d%d%d.log",
        prefix, nowTime.tm_year + TIME_BEGIN_YEAR, nowTime.tm_mon + 0x1, nowTime.tm_mday, nowTime.tm_hour,
        nowTime.tm_min, nowTime.tm_sec, (timeVal.tv_usec / MS_TO_US_CNT));
    if (ret <= 0) {
        roce_err("Sprintf_s log name failed. (ret=%d)", ret);
        return SYS_ERROR;
    }
 
    return 0;
}

