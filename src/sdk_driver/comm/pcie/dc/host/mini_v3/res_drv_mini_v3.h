/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _RES_DRV_MINI_V3_H_
#define _RES_DRV_MINI_V3_H_

#include "devdrv_pci.h"

int devdrv_mini_v3_res_init(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_mini_v3_init_bar_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_bar_addr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_intr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_dma_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_load_file_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_depend_module_info(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_mini_v3_alloc_devid(struct devdrv_ctrl *ctrl_this);
int devdrv_mini_v3_is_p2p_access_cap(struct devdrv_pci_ctrl *pci_ctrl, struct devdrv_pci_ctrl *peer_pci_ctrl);
int devdrv_mini_v3_get_pf_msg_chan_cnt(void);
int devdrv_mini_v3_get_vf_msg_chan_cnt(void);
u32 devdrv_mini_v3_get_p2p_support_max_devnum(void);
void devdrv_mini_v3_set_dev_shr_info(struct devdrv_pci_ctrl *pci_ctrl);
u32 devdrv_mini_v3_get_nvme_low_level_db_irq_num(void);
u32 devdrv_mini_v3_get_nvme_db_irq_strde(void);
void devdrv_mini_v3_init_msg_cnt(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_mini_v3_init_setup_runtime_info(struct devdrv_pci_ctrl *pci_ctrl);
enum devdrv_load_wait_mode devdrv_mini_v3_get_load_wait_mode(struct devdrv_pci_ctrl *pci_ctrl);

#endif
