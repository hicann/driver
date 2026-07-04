/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "network_comm.h"
#include <stdbool.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <limits.h>
#include "securec.h"
#include "user_log.h"
#include "tls.h"
#include "file_opt.h"

#define RIGHT_GONFIG_FILE_PATH_FROM_USER 1

#ifndef NETWORK_HOST
#include "ascend_kernel_hal.h"
#else
int devdrv_set_user_config(unsigned int dev_id, const char *name, unsigned char *buf, unsigned int buf_size)
{
    return 0;
}

int devdrv_get_user_config(unsigned int dev_id, const char *name, unsigned char *buf, unsigned int *buf_size)
{
    return 0;
}

int devdrv_clear_user_config(unsigned int devid, const char *name)
{
    return 0;
}
#endif

#ifndef CONFIG_LLT
#define STATIC static
#else
#define STATIC
#endif

#define HCCN_CDEV_IOC_MAGIC '%'

#define HCCN_CDEV_IOC_READ_FLASH _IOWR(HCCN_CDEV_IOC_MAGIC, 11, struct hccn_flash_cmd_para)
#define HCCN_CDEV_IOC_SET_TLS_ENABLE _IOWR(HCCN_CDEV_IOC_MAGIC, 22, struct hccn_tls_enable)
#define HCCN_CDEV_IOC_GET_TLS_ENABLE _IOWR(HCCN_CDEV_IOC_MAGIC, 23, struct hccn_tls_enable)
#define DEV_USER_CONFIG_NAME_MAX 32

struct hccn_flash_cmd_para {
    unsigned int chip_id;
    char name[DEV_USER_CONFIG_NAME_MAX];
    unsigned char *buf;
    unsigned int buf_size;
    int *thread_end_status;
};

struct hccn_tls_enable {
    unsigned int enable;
    unsigned int customer_setting;
    int chip_id;
};

int NetCommGetSelfHome(char *home_path, unsigned int path_len)
{
    int ret, ret_val;
    struct passwd *pwd = getpwuid((uid_t)getuid());
    CHK_PRT_RETURN(pwd == NULL, roce_err("pwd is NULL! getpwuid fail, errno:%d", errno), -EINVAL);

    if (pwd->pw_name == NULL) {
        roce_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out_get_self_home;
    }

    // root用户的home路径为/root
    // 其他用户的home路径为/home/${user_name}
    if (strncmp(pwd->pw_name, "root", strlen("root") + 1) == 0) {
        ret = sprintf_s((char *)home_path, path_len, "/root");
    } else {
        ret = sprintf_s((char *)home_path, path_len, "/home/%s", pwd->pw_name);
    }
    if (ret <= 0) {
        roce_err("sprintf_s for user name:%s failed, ret:%d ", pwd->pw_name, ret);
        ret = -ENOMEM;
        goto out_get_self_home;
    }

    ret = 0;
out_get_self_home:
    ret_val = memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    if (ret_val != 0) {
        roce_err("memset error, ret_val[%d]", ret_val);
        ret = ret_val;
    }

    return ret;
}

int get_tls_config_path(char *path, unsigned int path_len)
{
    int ret, ret_val;
    struct passwd *pwd = getpwuid((uid_t)getuid());
    CHK_PRT_RETURN(pwd == NULL, roce_err("pwd is NULL! getpwuid fail, errno:%d", errno), -EINVAL);

    if (pwd->pw_name == NULL) {
        roce_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out;
    }

    // root用户的tls配置文件存放在/root目录下
    // 其他用户的tls配置文件存放在/home/${user_name}/cert目录下
    if (strncmp(pwd->pw_name, "root", strlen("root") + 1) == 0) {
        ret = sprintf_s((char *)path, path_len, "/root");
    } else {
        ret = sprintf_s((char *)path, path_len, "/home/%s/cert", pwd->pw_name);
    }
    if (ret <= 0) {
        roce_err("sprintf_s for user name:%s failed, ret:%d ", pwd->pw_name, ret);
        ret = -ENOMEM;
        goto out;
    }

    ret = 0;
out:
    ret_val = memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    if (ret_val != 0) {
        roce_err("memset error, ret_val[%d]", ret_val);
        ret = ret_val;
    }

    return ret;
}

STATIC int get_saved_tls_config_file_path_from_user(const char *name, const char *user_name, char *dir_path,
                                                    const int dir_path_size)
{
    int ret;
    char tls_config_path[TLS_HOST_SAVE_PATH_LEN] = {0};
    char real_conf_path[PATH_MAX + 1] = {0};
    const char *pw_name = user_name;
    char *user_dir_path = dir_path;
    const int user_dir_path_size = dir_path_size;

    ret = sprintf_s((char *)user_dir_path, user_dir_path_size, "/home/%s/cert", pw_name);
    if (ret <= 0) {
        ret = -ENOMEM;
        roce_err("sprintf_s for user name:%s failed, ret:%d ", pw_name, ret);
        return ret;
    }

    ret = sprintf_s(tls_config_path, sizeof(tls_config_path), "%s/%s", user_dir_path, name);
    if (ret <= 0) {
        ret = -ENOMEM;
        roce_err("sprintf_s for user tls_config_path failed, ret:%d ", ret);
        return ret;
    }

    // 如果/home/${user_namse}/cert目录不存在，则使用/home/HwDmUser/cert目录
    if (realpath(tls_config_path, real_conf_path) == NULL) {
        roce_warn("conf_path[%s] is invalid, reason[%d].", tls_config_path, -errno);
        ret = sprintf_s((char *)user_dir_path, user_dir_path_size, "/home/HwDmUser/cert");
        if (ret <= 0) {
            ret = -ENOMEM;
            roce_err("sprintf_s for HwDmUser name:%s failed, ret:%d ", "/home/HwDmUser/cert", ret);
            return ret;
        }
        ret = sprintf_s(tls_config_path, sizeof(tls_config_path), "%s/%s", user_dir_path, name);
        if (ret <= 0) {
            ret = -ENOMEM;
            roce_err("sprintf_s for HwDmUser tls_config_path failed, ret:%d ", ret);
            return ret;
        }
        if (realpath(tls_config_path, real_conf_path) == NULL) {
            ret = -errno;
            roce_warn("conf_path[%s] is invalid, reason[%d].", tls_config_path, -errno);
            return ret;
        }
    }
    return RIGHT_GONFIG_FILE_PATH_FROM_USER;
}

STATIC int get_saved_tls_config_file_path(char *path, unsigned int path_len, const char *name)
{
    char dir_path[USER_NAME_PATH_LEN] = {0};
    int ret, ret_val;
    struct passwd *pwd = getpwuid(getuid());
    CHK_PRT_RETURN(pwd == NULL, roce_err("pwd is NULL! getpwuid fail, errno:%d", errno), -EINVAL);
    
    if (pwd->pw_name == NULL) {
        roce_err("pwd->pw_name is NULL, errno:%d", errno);
        ret = -EINVAL;
        goto out_get_saved_tls_config_path;
    }

    // root用户的tls配置文件存放在/root目录下
    // 其他用户的tls配置文件存放在/home/${user_namse}/cert目录(优先)或者/home/HwDmUser/cert目录下
    if (strncmp(pwd->pw_name, "root", strlen("root") + 1) == 0) {
        ret = sprintf_s((char *)dir_path, sizeof(dir_path), "/root");
        if (ret <= 0) {
            roce_err("sprintf_s for root name:%s failed, ret:%d ", "/root", ret);
            ret = -ENOMEM;
            goto out_get_saved_tls_config_path;
        }
    } else {
        ret = get_saved_tls_config_file_path_from_user(name, pwd->pw_name, dir_path, USER_NAME_PATH_LEN);
        if (ret == RIGHT_GONFIG_FILE_PATH_FROM_USER) {
            goto right_get_saved_tls_config_path;
        } else {
            goto out_get_saved_tls_config_path;
        }
    }

right_get_saved_tls_config_path:
    ret = sprintf_s(path, path_len, "%s/%s", dir_path, name);
    if (ret <= 0) {
        roce_err("sprintf_s for path:%s/%s failed, ret:%d ", dir_path, name, ret);
        ret = -ENOMEM;
        goto out_get_saved_tls_config_path;
    }
    ret = 0;

out_get_saved_tls_config_path:
    ret_val = memset_s(pwd, sizeof(struct passwd), 0, sizeof(struct passwd));
    if (ret_val) {
        roce_err("memset error, ret_val[%d]", ret_val);
        ret = ret_val;
    }

    return ret;
}

STATIC int dev_read_flash(unsigned int chip_id, const char *name, unsigned char *buf, unsigned int *buf_size)
{
    struct hccn_flash_cmd_para cmd_para = {0};
    int fd = -1;
    int ret, ret_val;
    int err_buf;

    cmd_para.chip_id = chip_id;
    cmd_para.buf = buf;
    cmd_para.buf_size = *buf_size;

    unsigned int name_len = (unsigned int)strlen(name) + 1;
    if (name_len > (DEV_USER_CONFIG_NAME_MAX)) {
        roce_err("dev_id[%u], name len is too long, name_len: %u.\n", chip_id, name_len);
        return -EINVAL;
    }

    ret = memcpy_s(cmd_para.name, sizeof(cmd_para.name), name, name_len);
    if (ret) {
        roce_err("memcpy flash name err ret %d, expect 0", ret);
        return -EINVAL;
    }

    fd = open("/dev/hccn_dev", O_RDONLY, S_IRUSR);
    if (fd < 0) {
        roce_warn("open hccn_dev device fail, chip_id[%u] err_code[%d].", chip_id, errno);
        return -ENOENT;
    }

    ret = ioctl(fd, HCCN_CDEV_IOC_READ_FLASH, &cmd_para);
    if (ret) {
        err_buf = errno;
        if (err_buf == ENOENT) {
            roce_warn("flash[%s] is not set before, dev[%u] ret[%d] err_code[%d].", name, chip_id, ret, err_buf);
        } else {
            roce_err("read flash[%s] fail, dev[%u] ret[%d] err_code[%d].", name, chip_id, ret, err_buf);
        }
        ret = err_buf ? -err_buf : -EINVAL;
    } else {
        *buf_size = cmd_para.buf_size;
    }
    do {
        ret_val = close(fd);
    } while ((ret_val < 0) && (errno == EINTR));

    fd = -1;
    return ret;
}

int set_tls_enable_to_hcdev(unsigned int chip_id, unsigned int tls_enable)
{
    struct hccn_tls_enable hccn_enable = {0};
    int ret, ret_val;
    int err_buf;
    int fd = -1;

    hccn_enable.enable = (tls_enable != 0) ? 1 : 0;
    hccn_enable.customer_setting = 1;
    hccn_enable.chip_id = (int)chip_id;

    fd = open("/dev/hccn_dev", O_RDONLY, S_IRUSR);
    if (fd == -1) {
        roce_err("Open hccn_dev device fail. (chip_id=%u; err_code=%d)", chip_id, errno);
        return -ENOENT;
    }

    ret = ioctl(fd, HCCN_CDEV_IOC_SET_TLS_ENABLE, &hccn_enable);
    if (ret != 0) {
        err_buf = errno;
        roce_err("Set tls enable failed. (dev=%u; ret=%d; err_code=%d)", chip_id, ret, err_buf);
        ret = (err_buf != 0) ? -err_buf : -EINVAL;
    }

    do {
        ret_val = close(fd);
    } while ((ret_val < 0) && (errno == EINTR));
    fd = -1;
    return ret;
}

STATIC int get_tls_enable_from_hcdev(unsigned int chip_id, const char *name, unsigned char *buf, bool flash_buf)
{
    struct hccn_tls_enable enable_info = { 0 };
    struct tls_cert_mng_info_v2 *mng_info = NULL;
    int ret, ret_val;
    int err_buf;
    int fd = -1;

    if (strncmp(HCCP_CERTS_MNG_NAME, name, strlen(name)) != 0) {
        return 0;
    }

    fd = open("/dev/hccn_dev", O_RDONLY, S_IRUSR);
    if (fd == -1) {
        roce_err("Open hccn_dev device fail. (chip_id=%u; err_code=%d)", chip_id, errno);
        return -ENOENT;
    }

    enable_info.chip_id = (int)chip_id;
    ret = ioctl(fd, HCCN_CDEV_IOC_GET_TLS_ENABLE, &enable_info);
    if (ret != 0) {
        err_buf = errno;
        roce_err("Get tls enable failed. (dev=%u; ret=%d; err_code=%d)", chip_id, ret, err_buf);
        ret = (err_buf != 0) ? -err_buf : -EINVAL;
    }
    do {
        ret_val = close(fd);
    } while ((ret_val < 0) && (errno == EINTR));
    fd = -1;

    if (ret != 0) {
        return ret;
    }

    mng_info = (struct tls_cert_mng_info_v2 *)buf;
    if (enable_info.customer_setting == 1) { // 如果客户修改过enable状态，就从ko中读取，否则从flash中读取
        mng_info->tls_enable = enable_info.enable;
        roce_info("Read enable status from hccn_cdev.ko success.");
    } else if (flash_buf && enable_info.customer_setting == 0) {
        // 用户没有修改过enable状态，将flash中查询出来的结果回写到ko中，下次读tls开关将直接从ko中读取
        ret = set_tls_enable_to_hcdev(chip_id, mng_info->tls_enable);
        if (ret != 0) {
            roce_err("Set_tls_enable_to_hcdev failed. (dev=%u; ret=%d)", chip_id, ret);
            return ret;
        }

        roce_info("Write enable status:%u from flash to hccn_cdev.ko success.", mng_info->tls_enable);
    }

    return ret;
}

STATIC int get_flash_tls_config(unsigned int chip_id, const char *name, unsigned char *buf, unsigned int *buf_size)
{
    struct tls_cert_mng_info_v2 mng_info = { 0 };
    int ret;

    ret = dev_read_flash(chip_id, name, buf, buf_size);
    if (ret == (-ENOENT)) {
        // set tls_enable(0) for the first time to avoid read tls_enable from flash next time
        (void)get_tls_enable_from_hcdev(chip_id, name, (unsigned char *)&mng_info, true);
        return ret;
    }
    if (ret) {
        roce_err("Dev read flash failed. (name=%s; chip_id=%u; ret=%d)", name, chip_id, ret);
        return ret;
    }

    roce_info("Read %s from flash success.", name);
    ret = get_tls_enable_from_hcdev(chip_id, name, buf, true);
    if (ret) {
        roce_err("Get tls enable from_hcdev fail. (ret=%d)", ret);
        return ret;
    }

    return 0;
}

int tls_get_user_config(unsigned int save_mode, unsigned int chip_id, const char *name,
    unsigned char *buf, unsigned int *buf_size)
{
    char file_path[TLS_HOST_SAVE_PATH_LEN] = {0};
    int ret;

    // 新增去device查数据的接口
    if (save_mode == TLS_SAVE_TO_FlASH) {
        ret = get_flash_tls_config(chip_id, name, buf, buf_size);
        if (ret == (-ENOENT)) {
            return ret;
        }
        if (ret) {
            roce_err("Get flash tls config failed. (file_path=%s; ret=%d)", file_path, ret);
            return ret;
        }
    } else if (save_mode == TLS_SAVE_TO_FILE) {
        ret = get_saved_tls_config_file_path(file_path, sizeof(file_path), name);
        if (ret) {
            if ((ret != -ENOENT) && (ret != -EACCES)) {
                roce_err("Get saved tls config file path failed. (ret=%d)", ret);
            }
            return ret;
        }

        ret = ReadFileToBuf(file_path, (char *)buf, buf_size);
        if (ret == (-ENOENT)) {
            return ret;
        }
        if (ret) {
            roce_err("Read file to buf fail, (file_path=%s; ret=%d)", file_path, ret);
            return ret;
        }
        roce_info("Read %s from path[%s] success.", name, file_path);
    } else {
        roce_err("Unknown save_mode.(save_mode=%u)", save_mode);
        return -EINVAL;
    }

    return 0;
}

void tls_get_enable_info(unsigned int save_mode, unsigned int chip_id, unsigned char *buf, unsigned int buf_size)
{
    struct tls_cert_mng_info_v2 *mng_info = NULL;
    int ret;

    if (buf == NULL) {
        roce_err("Buf is NULL. (chip_id=%u)", chip_id);
        return;
    }
    if (buf_size != sizeof(struct tls_cert_mng_info_v2)) {
        roce_err("The parameter is error. (buf_size:%u != %lu; chip_id=%u)",
            buf_size, sizeof(struct tls_cert_mng_info_v2), chip_id);
        return;
    }

    // not TLS_SAVE_TO_FlASH, disallow to get tls_enable from hccn_cdev
    if (save_mode != TLS_SAVE_TO_FlASH) {
        return;
    }

    // TLS_SAVE_TO_FlASH try to get tls_enable from hccn_cdev
    ret = get_tls_enable_from_hcdev(chip_id, HCCP_CERTS_MNG_NAME, buf, false);
    if (ret != 0) {
        roce_err("Get tls enable from hcdev failed. (ret=%d; chip_id=%u)", ret, chip_id);
        return;
    }

    // set magic_words to make sure mng_info is valid
    mng_info = (struct tls_cert_mng_info_v2 *)buf;
    ret = memcpy_s(mng_info->magic_words, TLS_MAGIC_WORDS_LEN, MAGIC_WORD_FOR_TLS, strlen(MAGIC_WORD_FOR_TLS));
    if (ret != 0) {
        roce_err("Memcpy_s failed. (ret=%d; chip_id=%u)", ret, chip_id);
        return;
    }

    return;
}

int tls_set_user_config(unsigned int save_mode, unsigned int chip_id, const char *name,
    unsigned char *buf, unsigned int buf_size)
{
    int ret;
    char file_path[TLS_HOST_SAVE_PATH_LEN] = {0};
    char tls_config_path[USER_NAME_PATH_LEN] = {0};

    if (save_mode == TLS_SAVE_TO_FlASH) {
        ret = devdrv_set_user_config(chip_id, name, buf, buf_size);
        if (ret) {
            roce_err("devdrv_set_user_config for [%s]] fail, ret:%d", name, ret);
            return ret;
        }
        roce_run_info("write %s to flash success.", name);
    } else if (save_mode == TLS_SAVE_TO_FILE) {
        ret = get_tls_config_path(tls_config_path, sizeof(tls_config_path));
        if (ret) {
            roce_err("get_tls_config_path failed, ret:%d", ret);
            return ret;
        }
        ret = sprintf_s(file_path, TLS_HOST_SAVE_PATH_LEN, "%s/%s", tls_config_path, name);
        if (ret <= 0) {
            roce_err("sprintf_s fail, ret:%d", ret);
            return -ENOMEM;
        }

        ret = WriteBufToFile(buf, buf_size, file_path, S_IRUSR | S_IWUSR | S_IRGRP);
        if (ret) {
            roce_err("WriteBufToFile for [%s] fail, ret:%d", file_path, ret);
            return ret;
        }
        roce_run_info("write %s to path[%s] success.", name, file_path);
    } else {
        roce_err("unknown save_mode[%u]", save_mode);
        return -EINVAL;
    }

    return 0;
}

int tls_clear_user_config(unsigned int save_mode, unsigned int chip_id, const char *name)
{
    int ret;
    char file_path[TLS_HOST_SAVE_PATH_LEN] = {0};
    char tls_config_path[USER_NAME_PATH_LEN] = {0};

    if (name == NULL) {
        roce_err("name is NULL");
        return -EINVAL;
    }

    if (save_mode == TLS_SAVE_TO_FlASH) {
        ret = devdrv_clear_user_config(chip_id, name);
        if (ret && (ret != -ENOENT)) {
            roce_err("devdrv_clear_user_config for [%s]] fail, ret:%d", name, ret);
            return ret;
        }
        roce_run_info("clear %s from flash success.", name);
    } else if (save_mode == TLS_SAVE_TO_FILE) {
        ret = get_tls_config_path(tls_config_path, sizeof(tls_config_path));
        if (ret) {
            roce_err("get_tls_config_path failed, ret:%d", ret);
            return ret;
        }
        ret = sprintf_s(file_path, TLS_HOST_SAVE_PATH_LEN, "%s/%s", tls_config_path, name);
        if (ret <= 0) {
            roce_err("sprintf_s fail, ret:%d", ret);
            return -ENOMEM;
        }
        RemoveFile(file_path);
        roce_run_info("clear %s from path[%s] success.", name, file_path);
    } else {
        roce_err("unknown save_mode[%u]", save_mode);
        return -EINVAL;
    }

    return 0;
}

int tls_get_lock_file_path(char *lock_file_path, unsigned int file_path_len)
{
    int ret;
    char tls_config_path[USER_NAME_PATH_LEN] = {0};

    if (lock_file_path == NULL) {
        roce_err("lock_file_path is NULL");
        return -EINVAL;
    }

    ret = get_tls_config_path(tls_config_path, sizeof(tls_config_path));
    if (ret) {
        roce_err("get_tls_config_path failed, ret:%d", ret);
        return ret;
    }

    ret = check_file_path(tls_config_path, S_IRWXU | S_IRGRP | S_IXGRP);
    if (ret) {
        roce_err("check and create file_path[%s] failed, ret:%d", tls_config_path, ret);
        return ret;
    }

    ret = sprintf_s(lock_file_path, file_path_len, TLS_LOCK_FILE_NAME, tls_config_path);
    if (ret <= 0) {
        roce_err("sprintf_s for lock_file_path fail, ret:%d", ret);
        return -ENOMEM;
    }

    return 0;
}
