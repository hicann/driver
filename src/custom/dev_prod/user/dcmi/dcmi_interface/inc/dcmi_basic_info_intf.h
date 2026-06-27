/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
 
#ifndef __DCMI_BASIC_INFO_INTF_H__
#define __DCMI_BASIC_INFO_INTF_H__
#include "dcmi_interface_api.h"

#define DCMI_VERSION_MIN_LEN         16            /* 存放dcmi版本号的内存空间，大小不能小于16 */
#define OS_VERSION_FILE              "/etc/os-release"
#define COMPONENT_VERSION_MIN_LEN    64       /* 存放固件版本号信息的内存空间, 大小不能小于64Byte。 */
#define DCMI_PRODUCT_TYPE_MIN_LEN    32       /* 存放product type 的内存空间，大小不能小于32 */

#define DEVICE_HEARTBEAT_LOSS        0x40F84E00      /* 设备心跳丢失健康状态错误码 */
#define DCMI_ERROR_CODE_MAX_NUM      128             /* 设备健康错误码最大数量 */
 
#if defined DCMI_VERSION_1
#define DRIVER_VERSION_MIN_LEN       64        /* 存放版本号信息的内存空间, 大小不能小于64Byte。 */
#endif

int dcmi_get_device_logic_id(int *device_logic_id, int card_id, int device_id);
int dcmiv2_get_device_logic_id(int *device_logic_id, int card_id, int device_id);
int check_get_device_type_para_valid(int card_id, int device_id, enum dcmi_unit_type *device_type);
int dcmiv2_inner_get_card_id_device_id_from_logicid(int *card_id, int *device_id, int device_logic_id);
int dcmiv2_check_device_heartbeat_state(int device_id);
int dcmi_get_device_logic_id_and_type(int card_id, int device_id, enum dcmi_unit_type *device_type,
    int *device_logic_id);
#endif /* __DCMI_BASIC_INFO_INTF_H__ */