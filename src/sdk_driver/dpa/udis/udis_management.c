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

#include "ka_task_pub.h"
#include "udis_log.h"
#include "udis_management.h"
#include "ka_common_pub.h"

STATIC struct udis_ctrl_block *g_udis_cb[UDIS_DEVICE_UDEVID_MAX];
STATIC ka_rw_semaphore_t g_udis_cb_lock[UDIS_DEVICE_UDEVID_MAX];

struct udis_ctrl_block *udis_get_ctrl_block(unsigned int udevid)
{
    if (udevid >= UDIS_DEVICE_UDEVID_MAX) {
        udis_err("Invalid udevid. (udevid=%u)\n", udevid);
        return NULL;
    }
    return g_udis_cb[udevid];
}

int udis_set_ctrl_block(unsigned int udevid, struct udis_ctrl_block *ctrl_block)
{
    if (udevid >= UDIS_DEVICE_UDEVID_MAX) {
        udis_err("Invalid udevid. (udevid=%u)\n", udevid);
        return -EINVAL;
    }
    g_udis_cb[udevid] = ctrl_block;
    return 0;
}

void udis_cb_rwlock_init(unsigned int udevid)
{
    ka_task_init_rwsem(&g_udis_cb_lock[udevid]);
}

void udis_cb_write_lock(unsigned int udevid)
{
    ka_task_down_write(&g_udis_cb_lock[udevid]);
}

void udis_cb_write_unlock(unsigned int udevid)
{
    ka_task_up_write(&g_udis_cb_lock[udevid]);
}

void udis_cb_read_lock(unsigned int udevid)
{
    ka_task_down_read(&g_udis_cb_lock[udevid]);
}

void udis_cb_read_unlock(unsigned int udevid)
{
    ka_task_up_read(&g_udis_cb_lock[udevid]);
}

struct udis_node *udis_addr_list_find_node(const struct udis_ctrl_block *udis_cb, UDIS_MODULE_TYPE module_type,
                                           const char *name)
{
    int i;
    struct udis_node *addr_node, *next = NULL;

    for (i = UPDATE_ONLY_ONCE; i < UPDATE_TYPE_MAX; ++i) {
        ka_list_for_each_entry_safe(addr_node, next, &udis_cb->addr_list[i], list)
        {
            if ((addr_node->module_type == module_type) && (ka_base_strcmp(addr_node->name, name) == 0)) {
                return addr_node;
            }
        }
    }
    return NULL;
}