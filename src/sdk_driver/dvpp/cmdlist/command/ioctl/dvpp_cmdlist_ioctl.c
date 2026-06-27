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
#include "dvpp_cmdlist_ioctl.h"
#include "ka_type.h"
#include "ka_errno_pub.h"
#include "ka_base_pub.h"
#include "ka_list_pub.h"
#include "ka_task_pub.h"
#include "ka_fs_pub.h"
#include "ka_driver_pub.h"
#include "ka_memory_pub.h"
#include "ka_kernel_def_pub.h"
#include "ka_common_pub.h"

#include "securec.h"
#include "dvpp_cmdlist_log.h"

#ifdef RUN_MODE_OFFLINE
#include "cmdbuf_hlist_ctx.h"
#endif // RUN_MODE_OFFLINE

static cmdlist_case g_cmdlist_case[] = {
    {GEN_CMDLIST, NULL},
    {GET_CMDLIST_VERSION, NULL},
    {DEL_CMDLIST_CHN_HLIST, NULL},
};

static ka_dev_t g_dvpp_cmdlist_dev_num = 0;
static ka_class_t *g_dvpp_cmdlist_class;
static ka_cdev_t g_dvpp_cmdlist_cdev;
static ka_device_t *g_dvpp_cmdlist_device;

static void dvpp_cmdlist_get_pid(int *p_pid)
{
    *p_pid = ka_task_get_current_tgid();
}

static int32_t dvpp_awake_handler(unsigned int cmd, dvpp_cmdlist_ioctl_args *ioctl_args)
{
    int32_t ret;
    CMDLIST_HANDLER handler = NULL;

    if (cmd == g_cmdlist_case[IOC_NR_CMDLIST_GEN_CMDLIST].cmd) {
        handler = g_cmdlist_case[IOC_NR_CMDLIST_GEN_CMDLIST].handler;
    } else if (cmd == g_cmdlist_case[IOC_NR_CMDLIST_GET_VERSION].cmd) {
        handler = g_cmdlist_case[IOC_NR_CMDLIST_GET_VERSION].handler;
    } else if (cmd == g_cmdlist_case[IOC_NR_CMDLIST_DEL_CHN_HLIST].cmd) {
        handler = g_cmdlist_case[IOC_NR_CMDLIST_DEL_CHN_HLIST].handler;
    } else {
        DVPP_CMDLIST_LOG_ERROR("check ioctl cmd fail, cmd %x should be %x, %x or %x."
                               "pls check whether the versions of the runtime pkg and the driver pkg are same.\n",
                               cmd, g_cmdlist_case[IOC_NR_CMDLIST_GEN_CMDLIST].cmd,
                               g_cmdlist_case[IOC_NR_CMDLIST_GET_VERSION].cmd,
                               g_cmdlist_case[IOC_NR_CMDLIST_DEL_CHN_HLIST].cmd);
        return -1;
    }

    if (handler == NULL) {
        DVPP_CMDLIST_LOG_ERROR("get function handler fail.\n");
        return -1;
    }

    ret = handler(ioctl_args);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("handler fail");
        return ret;
    }
    return 0;
}

static int dvpp_cmdlist_open(ka_inode_t *node, ka_file_t *file)
{
    (void)node;
#ifdef RUN_MODE_OFFLINE
    uint32_t size;
    size = sizeof(dvpp_cmdlist_private_data);
    dvpp_cmdlist_private_data *data = NULL;
    if (file == NULL) {
        DVPP_CMDLIST_LOG_ERROR("file is NULL");
        return -1;
    }

    file->private_data = ka_mm_kzalloc(size, GFP_KERNEL);
    if (file->private_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("private_data is NULL, kzalloc size %d failed", size);
        return -1;
    }
    data = (dvpp_cmdlist_private_data *)(file->private_data);
    KA_INIT_HLIST_HEAD(&(data->head));
    ka_task_init_rwsem(&(data->rw_sem));
    data->pid = ka_task_get_current_tgid();
#endif // RUN_MODE_OFFLINE
    return 0;
}

static int dvpp_cmdlist_close(ka_inode_t *node, ka_file_t *file)
{
    (void)node;
#ifdef RUN_MODE_OFFLINE
    dvpp_cmdlist_private_data *data = NULL;

    if (file == NULL) {
        DVPP_CMDLIST_LOG_ERROR("file is NULL");
        return -1;
    }
    if (file->private_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("private_data is NULL");
        return -1;
    }
    data = (dvpp_cmdlist_private_data *)(file->private_data);
    del_cmdbuf_hlist(data->pid, data);
    ka_mm_kfree(file->private_data);
    file->private_data = NULL;
#endif // RUN_MODE_OFFLINE
    return 0;
}

static long dvpp_cmdlist_ioctl(ka_file_t *file, unsigned int cmd, unsigned long arg)
{
    void *user_data = (void *)(uintptr_t)arg;
    long ret = -1;
    dvpp_cmdlist_ioctl_args ioctl_args;

    if ((file == NULL) || (user_data == NULL)) {
        DVPP_CMDLIST_LOG_ERROR("check ioctl input fail");
        return -1;
    }
    dvpp_cmdlist_get_pid(&ioctl_args.info.pid);
    ioctl_args.user_data = user_data;
    ioctl_args.info.data = NULL;
#ifdef RUN_MODE_OFFLINE
    if (file->private_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("ioctl private_data is NULL");
        return -1;
    }
    ioctl_args.info.data = (dvpp_cmdlist_private_data *)(file->private_data);
#endif // RUN_MODE_OFFLINE

    ret = dvpp_awake_handler(cmd, &ioctl_args);
    return ret;
}

static const ka_file_operations_t dvpp_cmdlist_fops = {
    .open = dvpp_cmdlist_open,
    .release = dvpp_cmdlist_close,
    .unlocked_ioctl = dvpp_cmdlist_ioctl
};

int32_t dvpp_cmdlist_dev_init(void)
{
    int32_t ret = 0;

    // 内核自动分配设备号
    ret = ka_fs_alloc_chrdev_region(&g_dvpp_cmdlist_dev_num, 0, DVPP_CMDLIST_DEVICE_CNT, DVPP_CMDLIST_DEVICE_NAME);
    if (ret < 0) {
        DVPP_CMDLIST_LOG_ERROR("alloc_chrdev_region fail, ret = %d", ret);
        goto err_region;
    }

    // 创建一个设备类
    g_dvpp_cmdlist_class = ka_driver_class_create(KA_THIS_MODULE, DVPP_CMDLIST_DEVICE_NAME);
    if (KA_IS_ERR(g_dvpp_cmdlist_class)) {
        ret = -1;
        DVPP_CMDLIST_LOG_ERROR("class_create fail");
        goto err_class;
    }

    // 将file_operations填充进去
    ka_fs_cdev_init(&g_dvpp_cmdlist_cdev, &dvpp_cmdlist_fops);
    g_dvpp_cmdlist_cdev.owner = KA_THIS_MODULE;

    // 将设备体与设备号绑定并向内核注册一个字符设备
    ret = ka_fs_cdev_add(&g_dvpp_cmdlist_cdev, g_dvpp_cmdlist_dev_num, DVPP_CMDLIST_DEVICE_CNT);
    if (ret) {
        DVPP_CMDLIST_LOG_ERROR("cdev_add fail, ret = %d", ret);
        goto err_cdev;
    }

    // 创建设备文件
    g_dvpp_cmdlist_device = ka_driver_device_create(g_dvpp_cmdlist_class, NULL, g_dvpp_cmdlist_dev_num,
        NULL, DVPP_CMDLIST_DEVICE_NAME);
    if (KA_IS_ERR(g_dvpp_cmdlist_device)) {
        ret = -1;
        DVPP_CMDLIST_LOG_ERROR("device_create fail");
        goto err_device;
    }

    return 0;

err_device:
    ka_fs_cdev_del(&g_dvpp_cmdlist_cdev);
err_cdev:
    ka_driver_class_destroy(g_dvpp_cmdlist_class);
err_class:
    ka_fs_unregister_chrdev_region(g_dvpp_cmdlist_dev_num, DVPP_CMDLIST_DEVICE_CNT);
err_region:
    return ret;
}

int32_t dvpp_get_gen_cmdlist_info_from_ioctl(dvpp_cmdlist_ioctl_args *arg,
    dvpp_gen_cmdlist_user_data *user_data, int32_t *pid, uint32_t *devid, uint32_t *phyid, struct dvpp_sqe *sqe)
{
    unsigned long ret;
    if (arg->user_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("arg->user_data is NULL");
        return -1;
    }
    *pid = arg->info.pid;
    ret = ka_base_copy_from_user(user_data, arg->user_data, sizeof(dvpp_gen_cmdlist_user_data));
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("copy from user user_data fail");
        return -1;
    }
    if ((user_data->sqe == NULL) || (user_data->sqe_len != sizeof(struct dvpp_sqe))) {
        DVPP_CMDLIST_LOG_ERROR("user_data check fail");
        return -1;
    }
    *devid = user_data->devid;
    *phyid = user_data->phyid;
    ret = ka_base_copy_from_user(sqe, user_data->sqe, sizeof(struct dvpp_sqe));
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("copy from user sqe fail");
        return -1;
    }
    return 0;
}

int32_t dvpp_set_gen_cmdlist_sqe_to_user_data(struct dvpp_sqe *sqe, dvpp_gen_cmdlist_user_data *user_data)
{
    unsigned long ret;
    ret = ka_base_copy_to_user(user_data->sqe, sqe, sizeof(struct dvpp_sqe));
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("copy to user fail");
        return -1;
    }
    return 0;
}

void dvpp_cmdlist_dev_exit(void)
{
    ka_driver_device_destroy(g_dvpp_cmdlist_class, g_dvpp_cmdlist_dev_num);
    ka_fs_cdev_del(&g_dvpp_cmdlist_cdev);
    ka_driver_class_destroy(g_dvpp_cmdlist_class);
    ka_fs_unregister_chrdev_region(g_dvpp_cmdlist_dev_num, DVPP_CMDLIST_DEVICE_CNT);
}

int32_t dvpp_set_gen_cmdlist_func(cmdlist_case *cmd_case)
{
    if (cmd_case->cmd != GEN_CMDLIST) {
        DVPP_CMDLIST_LOG_ERROR("set cmdlist func fail cmd=%d", (int32_t)cmd_case->cmd);
        return -1;
    }

    g_cmdlist_case[IOC_NR_CMDLIST_GEN_CMDLIST].handler = cmd_case->handler;
    return 0;
}

static int32_t dvpp_get_cmdlist_version_func(cmdlist_case *cmd_case)
{
    if (cmd_case->cmd != GET_CMDLIST_VERSION) {
        DVPP_CMDLIST_LOG_ERROR("set get cmdlist version func failed, cmd=%d.", (int32_t)cmd_case->cmd);
        return -1;
    }

    g_cmdlist_case[IOC_NR_CMDLIST_GET_VERSION].handler = cmd_case->handler;
    return 0;
}

static int32_t dvpp_get_cmdlist_version_handler(dvpp_cmdlist_ioctl_args *arg)
{
    unsigned long ret;
    const uint32_t major_version = 0;
    // 1. 增加LUT模块中Posterize功能的配置
    // 2. 增加LUT模块中cutout功能的配置
    const uint32_t minor_version = 2;
    const uint32_t patch_version = 0;
    dvpp_cmdlist_version_user_data user_data = {0};
    user_data.major = major_version;
    user_data.minor = minor_version;
    user_data.patch = patch_version;

    if (arg->user_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("arg->user_data is NULL.");
        return -1;
    }

    ret = ka_base_copy_to_user(arg->user_data, &user_data, sizeof(dvpp_cmdlist_version_user_data));
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("copy version info to user failed.");
        return -1;
    }

    return 0;
}

void dvpp_get_version_init(void)
{
    int32_t ret = 0;
    // 挂接响应iotcl的get version请求钩子函数，纯物理机场景
    cmdlist_case cmd_case;
    cmd_case.cmd = GET_CMDLIST_VERSION;
    cmd_case.handler = dvpp_get_cmdlist_version_handler;
    ret = dvpp_get_cmdlist_version_func(&cmd_case);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp_get_cmdlist_version_func failed， cmd=%d\n", (int32_t)GET_CMDLIST_VERSION);
        return;
    }
}

static int32_t dvpp_del_chn_hlist_handler(dvpp_cmdlist_ioctl_args *arg)
{
#ifdef RUN_MODE_OFFLINE
    unsigned long ret;
    dvpp_cmdlist_hlist_user_data user_data = {0};

    if (arg->user_data == NULL) {
        DVPP_CMDLIST_LOG_ERROR("arg->user_data is NULL.");
        return -1;
    }

    ret = ka_base_copy_from_user(&user_data, arg->user_data, sizeof(dvpp_cmdlist_hlist_user_data));
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("copy hlist info from user failed.");
        return -1;
    }
    del_chn_cmdbuf_hlist(ka_task_get_current_tgid(), user_data.chn_id, arg->info.data);
#endif // RUN_MODE_OFFLINE
    return 0;
}

void dvpp_del_chn_hlist_init(void)
{
    g_cmdlist_case[IOC_NR_CMDLIST_DEL_CHN_HLIST].handler = dvpp_del_chn_hlist_handler;
}