# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
ifneq ($(NOT_SUPPORT_SP), y)
    EXTRA_CFLAGS += -fstack-protector-all
endif

DRIVER_SRC_BASE_DIR := $(DRIVER_KERNEL_DIR)/src
EXTRA_CFLAGS += -I$(DRIVER_SOURCE_DIR)/libc_sec
EXTRA_CFLAGS += -I$(DRIVER_SOURCE_DIR)/inc
EXTRA_CFLAGS += -I$(DRIVER_SOURCE_DIR)/inc/pbl
EXTRA_CFLAGS += -I$(DRIVER_SOURCE_DIR)/kernel_adapt/include
EXTRA_CFLAGS += -I$(DRIVER_HAL_INC_DIR)
EXTRA_CFLAGS += -I$(DRIVER_SOURCE_DIR)/pbl/ubmm

ifeq ($(ENABLE_UBE),true)
    $(MODULE_NAME)-objs += ubmm/ubmm_map.o
    $(MODULE_NAME)-objs += ubmm/ubmm_uba.o
    $(MODULE_NAME)-objs += ubmm/ubmm_init.o
    $(MODULE_NAME)-objs += ubmm/ubmm_hpa.o
endif
$(MODULE_NAME)-objs += ubmm/ubmm_dev.o
