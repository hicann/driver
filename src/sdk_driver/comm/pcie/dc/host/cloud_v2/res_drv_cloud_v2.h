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

#ifndef _RES_DRV_CLOUD_V2_H_
#define _RES_DRV_CLOUD_V2_H_

#include "devdrv_pci.h"

/* 1024 bytes for extend, 512 bytes for hisi, and 512 bytes for virtualization */
#define DEVDRV_EXTEND_PARA_ADDR_OFFSET (0x3C9A0)
#define DEVDRV_VIRT_PARA_ADDR_OFFSET (DEVDRV_EXTEND_PARA_ADDR_OFFSET + 512)
#define DEVDRV_VIRT_NUMA_MAGIC (0xFAFAAFAF)
struct devdrv_virt_para {
    int version;
    int numa_node;
};

int devdrv_cloud_v2_res_init(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_pf_bar_addr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_vf_bar_addr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_pf_intr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_vf_intr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_peh_init_vf_intr_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_pf_dma_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_vf_dma_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_load_file_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_depend_module_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_link_speed_slow_to_normal(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v2_get_pf_msg_chan_cnt(void);
int devdrv_cloud_v2_get_vf_msg_chan_cnt(void);
int devdrv_cloud_v2_alloc_devid(struct devdrv_ctrl *ctrl_this);
u32 devdrv_cloud_v2_get_p2p_support_max_devnum(void);
int devdrv_cloud_v2_is_p2p_access_cap(struct devdrv_pci_ctrl *pci_ctrl, struct devdrv_pci_ctrl *peer_pci_ctrl);
bool devdrv_cloud_v2_is_mdev_vm_full_spec(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_hccs_flush_cache(u64 base, size_t len, u32 mode);
int devdrv_cloud_v2_get_peh_link_info(ka_pci_dev_t *pdev, u32 *link_speed, u32 *link_width, u32 *link_status);
void devdrv_cloud_v2_set_dev_shr_info(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v2_get_p2p_addr(struct devdrv_pci_ctrl *pci_ctrl, u32 remote_dev_id, enum devdrv_p2p_addr_type type, phys_addr_t *phy_addr, size_t *size);
void devdrv_cloud_v2_init_virt_info(struct devdrv_pci_ctrl *pci_ctrl);
u32 devdrv_cloud_v2_get_nvme_low_level_db_irq_num(void);
u32 devdrv_cloud_v2_get_nvme_db_irq_strde(void);
void devdrv_cloud_v2_init_pf_msg_cnt(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_vf_msg_cnt(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v2_init_pf_bar_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_vf_boot_mode_rebuild(struct devdrv_pci_ctrl *pci_ctrl);
int devdrv_cloud_v2_init_vf_bar_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_pf_setup_runtime_info(struct devdrv_pci_ctrl *pci_ctrl);
void devdrv_cloud_v2_init_vf_setup_runtime_info(struct devdrv_pci_ctrl *pci_ctrl);
enum devdrv_load_wait_mode devdrv_cloud_v2_get_load_wait_mode(struct devdrv_pci_ctrl *pci_ctrl);
unsigned devdrv_cloud_v2_get_server_id(struct devdrv_pci_ctrl *pci_ctrl);
unsigned devdrv_cloud_v2_get_max_server_num(struct devdrv_pci_ctrl *pci_ctrl);

#endif