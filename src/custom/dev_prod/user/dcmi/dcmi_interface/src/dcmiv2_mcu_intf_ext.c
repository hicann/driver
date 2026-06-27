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
#include "dcmi_virtual_intf.h"
#include "dcmi_i2c_operate.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_elabel_operate.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_basic_info_intf.h"


int dcmiv2_get_vrd_version(int dev_id, char *version,  int len)
{
    int err;
    int card_id, device_id;
    
    if ((version == NULL) || (len <= 0)) {
        gplog(LOG_ERR, "input param version[%d] or len(%d) is invalid.", version == NULL, len);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 1.针对暴露给用户的接口dcmiv2_get_vrd_version，需要再次进行产品检查
    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. err is %d.", err);
        return err;
    }

    // 2.针对card_id的判断已在dcmi_get_vrd_info中实现，不再重复实现
    return dcmi_get_vrd_info(card_id, version, len);
}