/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "bbox_dump_process.h"
#include "bbox_tool_fs.h"
#include "bbox_log_common.h"
#include "bbox_dump_exception.h"
#include "bbox_print.h"
#include "adx_api.h"
#include "ascend_hal_base.h"

bbox_status bbox_create_excep_dir_adapt(u32 phy_id, int logic_id, enum EXCEPTION_EVENT_TYPE event, const char *path, char *dev_path)
{
    int sn_ret;

    if (event == EVENT_LOAD_TIMEOUT) {
        sn_ret = bbox_format_device_offline_path(dev_path, DIR_MAXLEN, path, phy_id);
    } else {
        sn_ret = bbox_format_device_path(dev_path, DIR_MAXLEN, path, logic_id);
    }
    if (sn_ret == -1) {
        return BBOX_FAILURE;
    }

    return BBOX_SUCCESS;
}

static int remove_directory(const char *path)
{
    DIR *d = opendir(path);
    if (!d) {
        return BBOX_FAILURE;
    }

    struct dirent *entry;
    char subpath[DIR_MAXLEN];
    struct stat st;

    while ((entry = readdir(d)) != NULL) {
        if ((strncmp(entry->d_name, ".", 1) == 0 && entry->d_name[1] == '\0') ||
            (strncmp(entry->d_name, "..", 2) == 0 && entry->d_name[2] == '\0')) {
            continue;
        }

        if (snprintf_s(subpath, sizeof(subpath), sizeof(subpath) - 1, "%s/%s", path, entry->d_name) == -1) {
            continue;
        }

        if (lstat(subpath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                remove_directory(subpath);
            } else {
                unlink(subpath);
            }
        }
    }
    closedir(d);
    return rmdir(path);
}

bbox_status bbox_dump_dev_files(u32 phy_id, int logic_id, const char *path)
{
    char dev_buf[DEV_BUF_MAX_LEN];
    char old_path[DIR_MAXLEN];
    char new_path[DIR_MAXLEN];
    struct stat st;
    int errno_tmp;
    s32 ret;

    BBOX_INF("[%s] bbox runtime data, dump start.", bbox_get_dev_str(phy_id, logic_id, dev_buf, sizeof(dev_buf)));
    ret = AdxGetDeviceFile((unsigned short)phy_id, path, "bbox");
    if (ret != 0) {
        BBOX_ERR("[%s] get bbox runtime data failed by hdc channel.", bbox_get_dev_str(phy_id, logic_id, dev_buf, sizeof(dev_buf)));
        return BBOX_FAILURE;
    }

    ret = snprintf_s(old_path, DIR_MAXLEN, DIR_MAXLEN - 1, "%s/device-%u", path, phy_id);
    if (ret == -1) {
        BBOX_ERR("Failed to construct path.");
        return BBOX_FAILURE;
    }

    if (stat(old_path, &st) != 0) {
        BBOX_INF("[%s] bbox runtime data, dump end.", bbox_get_dev_str(phy_id, logic_id, dev_buf, sizeof(dev_buf)));
        return BBOX_SUCCESS;
    }

    if (!S_ISDIR(st.st_mode)) {
        BBOX_ERR("Not a dir.");
        return BBOX_FAILURE;
    }

    ret = snprintf_s(new_path, DIR_MAXLEN, DIR_MAXLEN - 1, "%s/device-%d", path, logic_id);
    if (ret == -1) {
        BBOX_ERR("Failed to construct path.");
        return BBOX_FAILURE;
    }

    if (rename(old_path, new_path) != 0) {
        errno_tmp = errno;
        BBOX_INF("Skip renaming. (status=%d)", errno_tmp);
        (void)remove_directory(old_path);
    }

    BBOX_INF("[%s] bbox runtime data, dump end.", bbox_get_dev_str(phy_id, logic_id, dev_buf, sizeof(dev_buf)));
    return BBOX_SUCCESS;
}

s32 bbox_format_devices_info(char *buf, const char *status, u32 dev_status, int logic_id, u32 phy_id)
{
    s32 ret;

    if (dev_status == SOC_STATUS_BOOT_FAILED) {
        ret = sprintf_s(buf, DEV_INFO_MAXLEN,
                        "device-offline-%-2d  %-2d        %-2d          %s\n",
                        phy_id, phy_id, logic_id, status);
    } else {
        ret = sprintf_s(buf, DEV_INFO_MAXLEN,
                        "device-%-2d          %-2d        %-2d          %s\n",
                        logic_id, phy_id, logic_id, status);
    }

    return ret;
}