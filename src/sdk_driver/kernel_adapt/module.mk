# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ascend_kernel_open_adapt

LOCAL_KO_SRC_FOLDER := $(LOCAL_PATH)

LOCAL_INSTALLED_KO_FILES := ascend_kernel_open_adapt.ko

ifeq ($(build_device), true)
PRODUCT_SIDE := device
include $(BUILD_DEVICE_KO)
else
PRODUCT_SIDE := host
include $(BUILD_HOST_KO)
endif

