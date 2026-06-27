/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
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

#include "ka_kernel_def_pub.h"
#include "ka_pci_pub.h"
#include "ka_task_pub.h"
#include "dvpp_trs_ops.h"
#include "dvpp_share_mem_ctrl.h"
#include "dvpp_cmdlist_ioctl.h"
#include "ka_compiler_pub.h"

#define PCI_VENDOR_ID_HUAWEI 0x19e5
static const ka_pci_device_id_t g_pci_dvpp_tbl[] = {
    {KA_PCI_VDEVICE(HUAWEI, 0xd802), 0},
    {KA_PCI_VDEVICE(HUAWEI, 0xd803), 0},
    {0x20C6, 0xd802, KA_PCI_ANY_ID, KA_PCI_ANY_ID, 0, 0, 0},
    {0x203F, 0xd802, KA_PCI_ANY_ID, KA_PCI_ANY_ID, 0, 0, 0},
    {0x20e9, 0xd802, KA_PCI_ANY_ID, KA_PCI_ANY_ID, 0, 0, 0},
    {}};
KA_MODULE_DEVICE_TABLE(pci, g_pci_dvpp_tbl);

static int32_t __ka_init dvpp_vdrv_init(void)
{
    uint32_t devid;
    dvpp_get_version_init();
    dvpp_trs_sqe_update_init();
    if (dvpp_cmdlist_dev_init() != 0) {
        dvpp_trs_sqe_update_uninit();
        return -1;
    }

    for (devid = 0;devid < DVPP_VMNG_DEVICE_NUM_MAX;devid++) {
        ka_task_spin_lock_init(&g_share_mem_pool_lock[devid]);
    }

    return 0;
}

static void __ka_exit dvpp_vdrv_exit(void)
{
    dvpp_cmdlist_dev_exit();
    dvpp_trs_sqe_update_uninit();
}

ka_module_init(dvpp_vdrv_init);
ka_module_exit(dvpp_vdrv_exit);

KA_MODULE_LICENSE("GPL");
