/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <sys/file.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include "securec.h"
#include "hccn_log.h"
#include "hccn_comm.h"
#include "tool_param.h"
#include "tool_log.h"

STATIC int HccnOpenByMode(const char *pathName, int flags, mode_t mode)
{
    char actualPath[PATH_MAX + 1] = {0};
    char *file_ret = NULL;

    CHK_PRT_RETURN((pathName == NULL) || (flags < 0),
        hccn_err("params invalid, pathName is NULL or flags:%d < 0", flags), -EINVAL);
    CHK_PRT_RETURN(strlen(pathName) > PATH_MAX,
        hccn_err("path_len:%zu > PATH_MAX:%d", strlen(pathName), PATH_MAX), -EINVAL);

    file_ret = realpath(pathName, actualPath);
    if (file_ret == NULL) {
        hccn_warn("log file doesn't exist, create it");
    }

    return open(actualPath, flags, mode);
}

STATIC void HccnGetTimeForLog(char *timeBuffer, unsigned int bufLen)
{
    struct timeval timeVal = {0};
    struct tm nowTime = {0};

    if (timeBuffer == NULL) {
        hccn_err("timeBuffer is NULL");
        return;
    }

    if ((gettimeofday(&timeVal, NULL)) != 0) {
        hccn_err("gettimeofday failed, errno:%d", errno);
        return;
    }

    if (localtime_r(&(timeVal.tv_sec), &nowTime) == NULL) {
        hccn_err("localtime_r failed, errno:%d", errno);
        return;
    }

    int ret = snprintf_s(timeBuffer, bufLen, bufLen - 1, "%04d-%02d-%02d %02d:%02d:%02d.%03ld ",
                         nowTime.tm_year + BEGIN_YEAR, nowTime.tm_mon + 1, nowTime.tm_mday,
                         nowTime.tm_hour, nowTime.tm_min,
                         nowTime.tm_sec, (timeVal.tv_usec / UNIT_THOUSAND));
    if (ret <= 0) {
        hccn_err("snprintf_s failed, ret:%d", ret);
        return;
    }
}

STATIC int HccnCatStr(const char *str1, unsigned int len1, const char *str2, unsigned int len2, Buffer *buffer)
{
    int ret;

    if ((str1 == NULL) || (str2 == NULL) || (buffer->buff == NULL) || (len1 + len2 >= buffer->buffLen)) {
        hccn_err("params invalid, str1 or str2 or buffer->buff is NULL, or (len1 + len2):%u >= buffer->buffLen:%u",
            (len1 + len2), buffer->buffLen);
        return -EINVAL;
    }

    ret = strcpy_s(buffer->buff, buffer->buffLen, str1);
    if (ret != 0) {
        hccn_err("strcpy_s failed, ret:%d, len:%u, str1 len:%lu", ret, buffer->buffLen, strlen(str1));
        return ret;
    }

    // join two string
    ret = strcpy_s(buffer->buff + strlen(str1), buffer->buffLen - strlen(str1), str2);
    if (ret != 0) {
        hccn_err("strcpy_s failed, ret:%d, len:%zu, str2 len:%zu", ret, buffer->buffLen - strlen(str1), strlen(str2));
        return ret;
    }
    return 0;
}

STATIC void HccnCheckRingFileLen(const char *hccnFile, const char *newFileName)
{
    struct stat logStat = {0};

    if (stat(hccnFile, &logStat) < 0) {
        hccn_warn("stat file:%s failed, errno:%d", hccnFile, errno);
        return;
    }
    // check log size to judge whether log file already rotated
    if (logStat.st_size < (LOGFILE_MAX_SIZE - LOG_PRINT_TOTAL_SIZE)) {
        return;
    }

    if (remove(newFileName) != 0) {
        hccn_warn("remove file:%s failed, errno:%d", newFileName, errno);
    }

    // readonly, 440
    if (chmod(hccnFile, S_IRUSR | S_IRGRP) != 0) {
        hccn_warn("chmod file:%s failed, errno:%d", hccnFile, errno);
    }

    if (rename(hccnFile, newFileName)) {
        hccn_warn("rename file:%s failed, errno:%d", hccnFile, errno);
    }
}

STATIC void HccnSetRingFile(const char *hccnFile, const char *logFileLock)
{
    const char logFileSuffix[HCCN_LOG_SUFFIX_LEN + 1] = ".old";
    int len = strlen(hccnFile) + 1;
    char *newFileName = NULL;
    Buffer buffer = {0};
    int lockFd;
    int ret;

    if (len <= 1) {
        hccn_err("hccnFile len:%d is invalid", len);
        return;
    }
    newFileName = (char *)calloc(len + HCCN_LOG_SUFFIX_LEN, sizeof(char));
    if (newFileName == NULL) {
        hccn_err("calloc newFileName failed, len:%d", len + HCCN_LOG_SUFFIX_LEN);
        return;
    }

    buffer.buff = newFileName;
    buffer.buffLen = len + HCCN_LOG_SUFFIX_LEN;
    ret = HccnCatStr(hccnFile, strlen(hccnFile), logFileSuffix, strlen(logFileSuffix), &buffer);
    if (ret != 0) {
        goto err_handle;
    }

    lockFd = HccnOpenByMode(logFileLock, O_CREAT | O_RDWR, FILE_MASK_WC);
    if (lockFd < 0) {
        hccn_err("open file:%s failed, fd:%d", logFileLock, lockFd);
        goto err_handle;
    }
    // non-blocking lock. if failed to fetch lock, immediately exit func
    if (flock(lockFd, LOCK_EX | LOCK_NB) < 0) {
        CLOSE_RETRY_FOR_EINTR(lockFd);
        goto err_handle;
    }

    HccnCheckRingFileLen(hccnFile, newFileName);

    FREE_BUF(newFileName);
    if (flock(lockFd, LOCK_UN) != 0) {
        hccn_warn("unlock fd:%d failed, errno:%d", lockFd, errno);
    }
    CLOSE_RETRY_FOR_EINTR(lockFd);
    if (remove(logFileLock) != 0) {
        hccn_warn("remove file:%s failed, errno:%d", logFileLock, errno);
    }
    return;

err_handle:
    FREE_BUF(newFileName);
    return;
}

STATIC int HccnGetRingFd(const char *logFilePath, const char *hccnFile, const char *msg)
{
    char logFileLock[FILE_LOCK_LEN] = {0};
    bool renameFlag = false;
    struct stat buf = {0};
    unsigned int sum;
    int cnt = 0;
    int fd = 0;
    int ret;

    ret = sprintf_s((char *)logFileLock, FILE_LOCK_LEN, "%s/hccn.lock", logFilePath);
    if (ret <= 0) {
        hccn_err("sprintf_s for root failed, ret:%d logFilePath:%s", ret, logFilePath);
        return -ENOMEM;
    }

    do {
        cnt++;
        fd = HccnOpenByMode(hccnFile, O_CREAT | O_WRONLY | O_APPEND, FILE_MASK_WC);
        if (fd < 0) {
            renameFlag = false;
            hccn_warn("open file:%s failed, errno:%d", hccnFile, errno);
            continue;
        }

        ret = flock(fd, LOCK_EX);
        if (ret != 0) {
            renameFlag = false;
            hccn_warn("flock file:%s failed, errno:%d", hccnFile, errno);
            CLOSE_RETRY_FOR_EINTR(fd);
            continue;
        }

        // get logFile size
        if (fstat(fd, &buf) < 0) {
            renameFlag = false;
            flock(fd, LOCK_UN);
            CLOSE_RETRY_FOR_EINTR(fd);
            continue;
        }
        sum = (buf.st_size + strlen(msg));
        if ((sum > buf.st_size) && (sum > strlen(msg)) && (sum >= LOGFILE_MAX_SIZE)) {
            flock(fd, LOCK_UN);
            CLOSE_RETRY_FOR_EINTR(fd);
            HccnSetRingFile(hccnFile, logFileLock);
            renameFlag = true;
        } else {
            renameFlag = false;
        }
    } while (renameFlag && cnt <= HCCN_LOG_MAX_RETRY);

    return fd;
}

STATIC void HccnFillMsg(char *msg, unsigned int msgLen, const char *format, va_list arg)
{
    char timeStamp[LOG_PRINT_TIMESTR_SIZE + 1] = {0};
    char logStr[LOG_PRINT_TOTAL_SIZE] = {0};
    int len, offset;
    int ret;

    HccnGetTimeForLog(timeStamp, LOG_PRINT_TIMESTR_SIZE);
    ret = vsnprintf_s(logStr, LOG_PRINT_TOTAL_SIZE, LOG_PRINT_TOTAL_SIZE - 1, format, arg);
    if (ret <= 0) {
        hccn_err("copy format to logStr failed, ret:%d", ret);
        goto out;
    }

    offset = HCCN_LOG_HEAD_LEN;
    ret = strncpy_s(msg, msgLen, logStr, offset);
    if (ret != 0) {
        hccn_err("copy log head to msg failed, ret:%d", ret);
        goto out;
    }
    len = strlen(msg);
    ret = strncpy_s(msg + len, msgLen - len, timeStamp, strlen(timeStamp));
    if (ret != 0) {
        hccn_err("copy timeStamp to msg failed, ret:%d", ret);
        goto out;
    }

    len = strlen(msg);
    ret = strncpy_s(msg + len, msgLen - len, logStr + offset, strlen(logStr) - offset);
    if (ret != 0) {
        hccn_err("copy log tail to msg failed, ret:%d", ret);
        goto out;
    }

out:
    va_end(arg);
    return;
}

STATIC int GetLogFilePath(char *logPath, unsigned int pathLen)
{
    struct passwd *pwd = getpwuid(getuid());
    int ret;

    CHK_PRT_RETURN(pwd == NULL, hccn_err("pwd is NULL, errno:%d", errno), -EINVAL);

    if (pwd->pw_name == NULL) {
        hccn_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out;
    }

    if (strcmp(pwd->pw_name, "root") == 0) {
        ret = sprintf_s((char *)logPath, FILE_PATH_LEN, "/var/log/hccn_tool");
        if (ret <= 0) {
            hccn_err("sprintf_s for root failed, ret:%d ", ret);
            ret = -ENOMEM;
            goto out;
        }
    } else {
        ret = sprintf_s((char *)logPath, FILE_PATH_LEN, "/home/%s", pwd->pw_name);
        if (ret <= 0) {
            hccn_err("sprintf_s for user name:%s failed, ret:%d ", pwd->pw_name, ret);
            ret = -ENOMEM;
            goto out;
        }
    }
    ret = 0;

out:
    (void)memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    return ret;
}

STATIC int ToolCheckFilePath(const char *path, mode_t mode)
{
    char realConfPath[PATH_MAX + 1] = {0};
    struct stat file_stat = {0};
    int ret;

    CHK_PRT_RETURN(path == NULL, hccn_err("path is NULL"), -EINVAL);
    CHK_PRT_RETURN(strlen(path) > PATH_MAX, hccn_err("path_len:%zu > PATH_MAX:%d", strlen(path), PATH_MAX), -EINVAL);

    if (realpath(path, realConfPath) == NULL) {
        ret = -errno;
        if (ret != -ENOENT) {
            hccn_err("path:%s is invalid, ret:%d", path, ret);
            return ret;
        }

        hccn_info("path:%s does not exist, real_path:%s", path, realConfPath);
        ret = mkdir(realConfPath, mode);
        if (ret != 0) {
            if (errno == EEXIST) {
                hccn_info("realConfPath:%s already exists, ret:%d errno:%d", realConfPath, ret, errno);
                return 0;
            }
            hccn_err("mkdir realConfPath:%s failed, ret:%d errno:%d", realConfPath, ret, errno);
            return ret;
        }
    }

    // check if realConfPath is a directory
    ret = stat(realConfPath, &file_stat);
    if (ret == 0) {
        if ((file_stat.st_mode & S_IFMT) == S_IFREG) {
            return -ENOTDIR;
        }
    } else {
        hccn_err("stat realConfPath:%s failed, ret:%d errno:%d", realConfPath, ret, errno);
        return ret;
    }

    return 0;
}

STATIC int GetLogFileName(unsigned int modeType, char *logFileName, unsigned int fileNameLen, char *logFilePath)
{
    int ret;

    switch (modeType) {
        case MODE_GET:
            ret = sprintf_s(logFileName, fileNameLen, "%s/hccn.log", logFilePath);
            break;
        case MODE_SET:
            ret = sprintf_s(logFileName, fileNameLen, "%s/hccn_set.log", logFilePath);
            break;
        case MODE_TEST:
            ret = sprintf_s(logFileName, fileNameLen, "%s/hccn_test.log", logFilePath);
            break;
        default:
            ret = sprintf_s(logFileName, fileNameLen, "%s/hccn.log", logFilePath);
            break;
    }
    return ret;
}

STATIC void PrintLog(unsigned int modeType, const char *format, va_list args)
{
    char msg[LOG_PRINT_TOTAL_SIZE + 1] = {0};
    char logFilePath[FILE_PATH_LEN] = {0};
    char logFileName[FILE_NAME_LEN] = {0};
    struct stat buf = {0};
    int ret;
    int fd;

    if (format == NULL) {
        return;
    }

    ret = GetLogFilePath(logFilePath, FILE_PATH_LEN);
    if (ret != 0) {
        hccn_err("GetLogFilePath failed, ret:%d", ret);
        return;
    }

    ret = ToolCheckFilePath(logFilePath, S_IRUSR | S_IWUSR | S_IRGRP);
    if (ret != 0) {
        if (ret != -ENOTDIR) {
            hccn_err("ToolCheckFilePath failed, ret:%d", ret);
        }
        return;
    }

    ret = GetLogFileName(modeType, logFileName, FILE_NAME_LEN, logFilePath);
    if (ret <= 0) {
        hccn_err("GetLogFileName for root failed, ret:%d logFilePath:%s", ret, logFilePath);
        return;
    }
    // Check if it's a symbolic link
    if (lstat(logFileName, &buf) == 0 && (S_IFMT & buf.st_mode) == S_IFLNK) {
        hccn_err("lstat failed, file:%s is a symbolic link", logFileName);
        return;
    }

    // Fill message
    HccnFillMsg(msg, LOG_PRINT_TOTAL_SIZE + 1, format, args);

    // Get file descriptor
    fd = HccnGetRingFd(logFilePath, logFileName, msg);
    if (fd < 0) {
        hccn_err("HccnGetRingFd failed, fd:%d", fd);
        return;
    }

    // Write message to file
    ret = write(fd, msg, strlen(msg));
    if (ret < 0) {
        hccn_err("write failed, ret:%d errno:%d", ret, errno);
    }

    // Unlock and close file descriptor
    flock(fd, LOCK_UN);
    CLOSE_RETRY_FOR_EINTR(fd);
    return;
}

void ToolPrintLog(unsigned int modeType, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    PrintLog(modeType, format, args);
    va_end(args);
}
