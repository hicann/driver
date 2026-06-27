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
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_smbus_operate.h"
#include "dcmi_os_adapter.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_i2c_operate.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_elabel_operate.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_common.h"

static int g_dcmi_vrd_lock_flag = FALSE;

int dcmi_get_vrd_version(int card_id, char *version,  int len)
{
    gplog(LOG_OP, "This device does not support.");
    return DCMI_ERR_CODE_NOT_SUPPORT;
}

void dcmi_set_vrd_lock_flag(bool flag)
{
    // VRD锁标志置位，TRUE表示已经获取到锁
    g_dcmi_vrd_lock_flag = flag;
}
 
bool dcmi_get_vrd_lock_flag(void)
{
    return g_dcmi_vrd_lock_flag;
}
 
int dcmi_vrd_get_file_lock(int fd, unsigned int timeout)
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
        for (index = 0; index < DCMI_MCU_MUTEX_FIRST_TRY_TIMES; index++) {
            ret = fcntl(fd, F_SETLK, &f_lock);
            if (ret == DCMI_OK) {
                return DCMI_OK;
            }
        }
 
        /* 未获取到锁，等待1ms，再次尝试获取 */
        (void)usleep(DCMI_MCU_MUTEX_SLEEP_TIMES_1MS);
        time_curr++;
    }
    return DCMI_ERR_CODE_INNER_ERR;
#else
    return DCMI_OK;
#endif
}

/* 进程间文件锁，当做进程间锁 */
STATIC int dcmi_vrd_set_lock(int *fd, unsigned int timeout)
{
#ifndef _WIN32
    int fd_curr = -1;
 
    if (dcmi_get_vrd_lock_flag() == TRUE) {
        return DCMI_OK;
    }
 
    fd_curr = open(DCMI_VRD_LOCK_FILE_NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd_curr < 0) {
        gplog(LOG_ERR, "mcu_get_lock:open file %s failed! ", DCMI_VRD_LOCK_FILE_NAME);
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }
 
    *fd = fd_curr;
 
    if (dcmi_vrd_get_file_lock(fd_curr, timeout) != DCMI_OK) {
        /* 失败需要关闭文件，成功需要调用vrd_set_unlock来关闭 */
        close(fd_curr);
        *fd = -1;
        return DCMI_ERR_CODE_INNER_ERR;
    }
#endif
    return DCMI_OK;
}
 
int dcmi_vrd_set_lock_up(int *fd, unsigned int timeout)
{
#ifndef _WIN32
    int ret;
    dcmi_set_vrd_lock_flag(FALSE);
    ret = dcmi_vrd_set_lock(fd, timeout);
    if (ret == DCMI_OK) {
        dcmi_set_vrd_lock_flag(TRUE);
    }
    return ret;
#else
    return DCMI_OK;
#endif
}
 
/* 进程间文件锁，当做进程间锁 */
STATIC void dcmi_vrd_set_unlock(int fd)
{
#ifndef _WIN32
    struct flock f_lock = {0};
 
    // 被锁住的状态，预防意料之外的解锁
    if (dcmi_get_vrd_lock_flag() == TRUE) {
        return;
    }
 
    if (fd < 0) {
        gplog(LOG_ERR, "mcu_set_unlock:fd invalid. fd = %d", fd);
        return;
    }
 
    f_lock.l_type = F_UNLCK;
    f_lock.l_whence = 0;
    f_lock.l_len = 0;
 
    fcntl(fd, F_SETLK, &f_lock);
    close(fd);
 
    return;
#else
    return;
#endif
}
 
void dcmi_vrd_set_unlock_up(int fd)
{
#ifndef _WIN32
    dcmi_set_vrd_lock_flag(FALSE);
    dcmi_vrd_set_unlock(fd);
    return;
#else
    return;
#endif
}

int dcmi_get_upgradable_vrd_version(int card_id, char *version,  int len)
{
    if ((version == NULL) || (len <= 0)) {
        gplog(LOG_ERR, "dcmi_get_vrd_version input para error.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    MCU_SMBUS_REQ_MSG mcu_req = {0};
    mcu_req.arg = 0;
    mcu_req.opcode = DCMI_MCU_GET_UPGRADE_APP_OPCODE;
    char req_data = 0x2;
    mcu_req.req_data = &req_data;
    mcu_req.req_data_len = 1;

    MCU_SMBUS_RSP_MSG mcu_rsp = {0};
    mcu_rsp.len = 0;
    mcu_rsp.total_len = len;
    mcu_rsp.data_info = version;

    int ret = dcmi_check_card_id(card_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Check card failed.(card_id=%d, ret=%d).", card_id, ret);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    ret = dcmi_mcu_get_info_dynamic(card_id, &mcu_req, &mcu_rsp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_mcu_get_info_dynamic failed.(ret=%d).", ret);
        return ret;
    }
    return DCMI_OK;
}

int dcmi_get_vdm_info(int card_id, char *version, int len)
{
    int ret, dev_id;
    int tmp_card_id = card_id;
    int req_data = 0;
    MCU_SMBUS_REQ_MSG mcu_req = {0};
    MCU_SMBUS_RSP_MSG mcu_rsp = {0};
    mcu_req.arg = 1;    // 1: 代表获取vdm信息
    mcu_req.opcode = DCMI_MCU_VRD_INFO_OPCODE;  // 与vrd共用opcode查询版本信息
    mcu_req.req_data = (char *)&req_data;
    mcu_req.req_data_len = 0;
    mcu_rsp.len = 0;
    mcu_rsp.total_len = len;
    mcu_rsp.data_info = version;

    if ((version == NULL) || (len <= 0)) {
        gplog(LOG_ERR, "dcmi_get_vdm_info input para error.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_board_chip_type_is_ascend_950()) {
        ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&tmp_card_id, &dev_id, card_id);
        if (ret != DCMI_OK) {
            return ret;
        }
    }

    ret = dcmi_check_card_id(tmp_card_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "check card id %d failed %d.", tmp_card_id, ret);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_mcu_get_info_dynamic(tmp_card_id, &mcu_req, &mcu_rsp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_mcu_get_info_dynamic failed. ret is %d.", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    return DCMI_OK;
}

int dcmi_mcu_get_device_errorcode(
    int card_id, int *error_count, unsigned int *error_code_list, unsigned int list_len)
{
    int ret, i;
    int req_data = 0;
    const int err_code_size_950 = 2;
    unsigned short mcu_err_code_list[DCMI_MCU_ERR_CODE_MAX] = {0};
    unsigned short *src = &mcu_err_code_list[1];
    MCU_SMBUS_REQ_MSG mcu_req = {0};
    MCU_SMBUS_RSP_MSG mcu_rsp = {0};
    mcu_req.arg = 0;
    mcu_req.opcode = DCMI_MCU_ERRCODE_OPCODE;
    mcu_req.req_data = (char *)&req_data;
    mcu_req.req_data_len = 0;
    mcu_rsp.data_info = (char *)&mcu_err_code_list[0];
    mcu_rsp.total_len = (int)sizeof(mcu_err_code_list);
    mcu_rsp.len = 0;

    ret = dcmi_mcu_get_info_dynamic(card_id, &mcu_req, &mcu_rsp);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_mcu_get_info_dynamic fail %d.", ret);
        return ret;
    }

    /* PCIE带外管理规范，若无故障，则填0x0000，小字节序 */
    if ((mcu_rsp.len == (int)sizeof(unsigned short)) && (mcu_err_code_list[0] == 0)) {
        *error_count = 0;
    } else {
        if (mcu_rsp.len % sizeof(unsigned short) != 0) {
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }
        *error_count = mcu_rsp.len / (int)sizeof(unsigned short);  // MCU返回的错误码为unsigned short类型，位宽为2
        if (dcmi_get_board_chip_type() == DCMI_CHIP_TYPE_D950) {
            *error_count = (*error_count - 1) / err_code_size_950;
            if (*error_count > list_len) {
                gplog(LOG_ERR, "*error_count %d is bigger than list_len %u", *error_count, list_len);
                return DCMI_ERR_CODE_INVALID_PARAMETER;
            }
            for (i = 0; i < *error_count; i++) {
                error_code_list[i] = ((unsigned int)src[err_code_size_950 * i + 1] << SHIFT_SIXTEEN_BITS) |
                                     ((unsigned int)src[err_code_size_950 * i]);
            }
        } else {
            if (*error_count > list_len) {
                gplog(LOG_ERR, "*error_count %d is bigger than list_len %u", *error_count, list_len);
                return DCMI_ERR_CODE_INVALID_PARAMETER;
            }
            for (i = 0; i < *error_count; i++) {
                error_code_list[i] = (unsigned int)mcu_err_code_list[i];
            }
        }
    }
    return DCMI_OK;
}