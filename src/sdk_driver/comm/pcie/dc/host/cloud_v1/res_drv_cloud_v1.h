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

#ifndef _RES_DRV_CLOUD_V1_H_
#define _RES_DRV_CLOUD_V1_H_

#include "devdrv_pci.h"

int devdrv_cloud_v1_res_init(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v1_init_bar_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_bar_addr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_intr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_dma_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_load_file_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_depend_module_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_link_info(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v1_alloc_devid(struct devdrv_ctrl *ctrl_this);
int devdrv_cloud_v1_is_p2p_access_cap(struct devdrv_pci_ctrl *pci_ctrl, struct devdrv_pci_ctrl *peer_pci_ctrl);
int devdrv_cloud_v1_get_pf_msg_chan_cnt(void);
int devdrv_cloud_v1_get_vf_msg_chan_cnt(void);
u32 devdrv_cloud_v1_get_p2p_support_max_devnum(void);
void devdrv_cloud_v1_set_dev_shr_info(struct devdrv_pci_ctrl *pci_ctrl);
u32 devdrv_cloud_v1_get_nvme_low_level_db_irq_num(void);
u32 devdrv_cloud_v1_get_nvme_db_irq_strde(void);
void devdrv_cloud_v1_init_msg_cnt(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v1_init_setup_runtime_info(struct devdrv_pci_ctrl *pci_ctrl);
enum devdrv_load_wait_mode devdrv_cloud_v1_get_load_wait_mode(struct devdrv_pci_ctrl *pci_ctrl);

#endif
