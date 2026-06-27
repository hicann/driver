/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
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
#include "dcmi_product_judge.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_common.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_hpm_parse.h"

int dcmiv2_upgrade_vrd(int dev_id, const char *file)
{
    // 1.场景判断，非法则返回-8002
    int ret, card_id, device_id, fd = -1;
    bool is_in_root_env = dcmi_is_in_phy_machine_root() || dcmi_is_in_privileged_docker_root();
    if (!is_in_root_env) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }

    // 2.参数校验，非法则返回-8001
    ret = dcmi_vrd_params_check(card_id, file);
    if (ret != DCMI_OK) {
        return ret;
    }

    // 3. 因该接口暴露给用户，需要再次进行产品检查
    if (!dcmi_board_chip_type_is_ascend_950_card()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    // 4.开始执行算法流程：解析bin、过滤排序、上传
    ret = dcmi_vrd_set_lock_up(&fd, DCMI_VRD_GET_LOCK_TIME_OUT_MS); // vrd升级核心步骤前加锁
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_vrd_set_lock failed. ret is %d.", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }
 
    ret = dcmi_parse_single_vrd_hpm(card_id, file);
    dcmi_vrd_set_unlock_up(fd);
 
    return ret;
}