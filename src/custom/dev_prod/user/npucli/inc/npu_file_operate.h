/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_FILE_OPERATE_H__
#define __NPU_FILE_OPERATE_H__

#define NPU_MUTEX_FIRST_TRY_TIMES 100 /* 获取超时锁，首先尝试调用trylock的次数 */

#define NPU_MUTEX_SLEEP_TIME_1MS 1000
#define NPU_GET_LOCK_TIMOUT       5000

int get_file_length(const char *file, unsigned int *file_len);

int get_file_data(const char *file, unsigned char *fileBuf, unsigned int bufLen, unsigned int offset,
    unsigned int readLen);

int write_data_to_file(const char *file, const char *writeBuf, unsigned int bufLen, unsigned int writeLen);

int get_file_directory(const char *file, char *fileDir, int dirLen);

int remove_file(const char *filename);

int remove_dir(const char *dirname);

int read_file_to_buf(const char *path, unsigned char *data, long int data_size, unsigned int *data_len);

int npu_create_lock_file(char *DIR, char *file, int *fd);

int npu_set_file_lock(int fd, unsigned int timeout);

void npu_set_file_unlock(int fd);

#endif /* __NPU_FILE_OPERATE_H__ */
