# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

asdrv_dpa-objs += dp_proc_mng/master/pmaster/dp_proc_mng_msg_client.o
asdrv_dpa-objs += dp_proc_mng/common/dp_proc_mng_module_ops.o
asdrv_dpa-objs += dp_proc_mng/master/comm/dp_proc_mng_proc_info.o
asdrv_dpa-objs += dp_proc_mng/master/comm/dp_proc_mng_master_register_ops.o
asdrv_dpa-objs += dp_proc_mng/master/comm/dp_proc_mng_channel.o
asdrv_dpa-objs += dp_proc_mng/common/dp_proc_mng_pci_dev_tbl.o
asdrv_dpa-objs += dp_proc_mng/common/dp_proc_mng_pid_maps.o

EXTRA_CFLAGS += -I$(DRIVER_HAL_INC_DIR)
EXTRA_CFLAGS += -I$(C_SEC_INCLUDE)
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/inc
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/inc/pbl
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/command/ioctl
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/command/msg
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/master
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/common
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/master/comm
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/master/pmaster
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/common
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dpa/dp_proc_mng/master/comm
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/pbl/uda/command/ioctl
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/kernel_adapt/include
EXTRA_CFLAGS += -I$(DRIVER_KERNEL_DIR)/dms/command/ioctl
