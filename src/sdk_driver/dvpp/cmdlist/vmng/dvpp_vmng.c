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
#include "dvpp_vmng.h"
#include "ka_type.h"
#include "comm_kernel_interface.h"
#include "vmng_kernel_interface.h"
#include "dvpp_vcm_host.h"
#include "dvpp_cmdlist_log.h"
#include "dvpp_mem_allocater_comm.h"

#include "pbl_kernel_interface.h"

#define DVPP_CONTAINER_NOTIFIER "dvpp_container_notifier"
#define DVPP_VIRTUAL_NOTIFIER   "dvpp_virtual_notifier"

static int32_t dvpp_vmng_init_instance(uint32_t udevid)
{
    uint32_t dev_id = udevid;
    uint32_t fid = 0;
    int32_t ret;

    DVPP_CMDLIST_LOG_INFO("dvpp vmnh vm online dev_id=%u, fid=%u", dev_id, fid);
    // 虚拟机上线时，注册vpc通讯客户端，用于接收来自虚拟机的vpc通讯消息
    ret = dvpp_vcm_vpc_register_client(dev_id, fid);
    return ret;
}

static int32_t dvpp_vmng_uninit_instance(uint32_t udevid)
{
    uint32_t dev_id = udevid;
    uint32_t fid = 0;

    DVPP_CMDLIST_LOG_INFO("dvpp vmnh vm offline dev_id=%u, fid=%u", dev_id, fid);
    (void)dvpp_vcm_vpc_unregister_client(dev_id, fid);
    return 0;
}

static int dvpp_virtual_notifier_func(uint32_t udevid, enum uda_notified_action action)
{
    int ret = 0;

    if (udevid >= DVPP_VMNG_DEVICE_NUM_MAX) {
        DVPP_CMDLIST_LOG_ERROR("dvpp vmng check dev_id=%u is invalid\n", udevid);
        return -EINVAL;
    }

    if (action == UDA_INIT) {
        ret = dvpp_vmng_init_instance(udevid);
    } else if (action == UDA_UNINIT) {
        dvpp_vmng_uninit_instance(udevid);
    }

    DVPP_CMDLIST_LOG_INFO("notifier action. (udevid=%u; action=%d; ret=%d)\n", udevid, action, ret);

    return ret;
}

static int32_t dvpp_vmng_init_container_instance(uint32_t dev_id, struct device *dev)
{
    UNUSED(dev);
    // 使用device id为pool id管理不同的内存池
    dvpp_create_mem_pools_by_id(dev_id);
    return 0;
}

static int32_t  dvpp_vmng_uninit_container_instance(uint32_t dev_id)
{
    // 使用device id为pool id管理不同的内存池
    dvpp_destroy_mem_pools_by_id(dev_id);
    return 0;
}

static int dvpp_container_notifier_func(uint32_t udevid, enum uda_notified_action action)
{
    int ret = 0;

    if (udevid >= DVPP_VMNG_DEVICE_NUM_MAX) {
        DVPP_CMDLIST_LOG_ERROR("dvpp vmng check dev_id=%u is invalid\n", udevid);
        return -EINVAL;
    }

    // 上线有物理设备的通知, 我们不关注物理设备就返回成功不要处理
    if (uda_is_phy_dev(udevid)) {
        return 0;
    }

    if (action == UDA_INIT) {
        ret = dvpp_vmng_init_container_instance(udevid, uda_get_device(udevid));
    } else if (action == UDA_UNINIT) {
        ret = dvpp_vmng_uninit_container_instance(udevid);
    }

    DVPP_CMDLIST_LOG_INFO("notifier action. (udevid=%u; action=%d; ret=%d)\n", udevid, action, ret);

    return ret;
}

// 放在cmdlist其他模块初始化完成后，再调用
int32_t dvpp_vmng_init(void)
{
    int32_t ret;
    struct uda_dev_type type;
    // 容器上线
    uda_davinci_near_real_entity_type_pack(&type);
    ret = uda_notifier_register(DVPP_CONTAINER_NOTIFIER, &type, UDA_PRI1, dvpp_container_notifier_func);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp register %s failed, ret=%d\n", DVPP_CONTAINER_NOTIFIER, ret);
        return ret;
    }

    // 虚拟机上线
    uda_dev_type_pack(&type, UDA_DAVINCI, UDA_ENTITY, UDA_NEAR, UDA_REAL_SEC_EH);
    ret = uda_notifier_register(DVPP_VIRTUAL_NOTIFIER, &type, UDA_PRI1, dvpp_virtual_notifier_func);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp register %s failed, ret=%d\n", DVPP_VIRTUAL_NOTIFIER, ret);
        uda_davinci_near_real_entity_type_pack(&type);
        (void)uda_notifier_unregister(DVPP_CONTAINER_NOTIFIER, &type);
        return ret;
    }

    return 0;
}

int32_t dvpp_vmng_uninit(void)
{
    // 容器下线
    struct uda_dev_type type;
    uda_davinci_near_real_entity_type_pack(&type);
    (void)uda_notifier_unregister(DVPP_CONTAINER_NOTIFIER, &type);

    // 虚拟机下线
    uda_dev_type_pack(&type, UDA_DAVINCI, UDA_ENTITY, UDA_NEAR, UDA_REAL_SEC_EH);
    (void)uda_notifier_unregister(DVPP_VIRTUAL_NOTIFIER, &type);

    return 0;
}