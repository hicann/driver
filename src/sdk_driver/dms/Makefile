# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
MODULE_NAME = asdrv_dms

DRIVER_SOURCE_DIR := $(DRIVER_KERNEL_DIR)

DRIVER_MODULE_DEVMNG_DIR := $(DRIVER_SOURCE_DIR)/dms/devmng

include $(FEATURE_MK_PATH)
EXTRA_CFLAGS += $(CONFIG_DEFINES)

# configuring module feature
include $(DRIVER_SOURCE_DIR)/dms/feature/host/module.mk

# configuring product feature
include $(DRIVER_SOURCE_DIR)/dms/feature/host/$(PRODUCT).mk

EXTRA_CFLAGS += -Wno-type-limits

obj-m += asdrv_dms.o
asdrv_dms-y += dms_module.o

include $(DRIVER_SOURCE_DIR)/dms/devmng/devmng.mk
