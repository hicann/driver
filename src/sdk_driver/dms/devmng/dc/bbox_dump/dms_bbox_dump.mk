# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
# Common bbox feature - compiled for ALL products
asdrv_dms-y += devmng/dc/bbox_dump/dms_bbox_dump_feature_check.o
EXTRA_CFLAGS += -I$(DRIVER_MODULE_DEVMNG_DIR)/dc/bbox_dump
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/pbl/dev_urd/command/ioctl
EXTRA_CFLAGS += -DDRV_HOST
ifneq ($(filter $(PRODUCT), ascend950),)
	EXTRA_CFLAGS += -DCFG_SOC_PLATFORM_CLOUD_V4
	asdrv_dms-y += devmng/dc/bbox_dump/dms_bbox_dump.o
	asdrv_dms-y += devmng/dc/bbox_dump/dms_bbox_dump_host.o
	EXTRA_CFLAGS += -I$(DRIVER_MODULE_DEVMNG_DIR)/drv_devmng/drv_devmng_host/ascend910
	EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/inc/comm
	EXTRA_CFLAGS += -DCFG_FEATURE_PCIE_BBOX_DUMP
	ifeq ($(ENABLE_UBE), true)
		asdrv_dms-y += devmng/dc/bbox_dump/dms_bbox_type_mng.o
		EXTRA_CFLAGS += -DCFG_FEATURE_UB
		EXTRA_CFLAGS += -Iinclude/ub/urma
	endif
endif
