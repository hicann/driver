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

#include "ka_system_pub.h"
#include "hw_vdavinci.h"
#include "dvt.h"
#include "vfio_ops.h"
#include "schedule.h"

bool hw_vdavinci_changed_cpu(ka_task_struct_t *p,
                             const ka_cpumask_t *next_mask)
{
#if (IS_VDAVINCI_KERNEL_VERSION_SUPPORT || (defined(DRV_UT)))
    if (ka_base_cpumask_empty(next_mask)) {
        return false;
    }

    if (cpumask_test_cpu(ka_system_smp_processor_id(), next_mask)) {
        return false;
    }

    if (ka_base_set_cpus_allowed_ptr(p, next_mask) != 0) {
        return false;
    }
#endif
    return true;
}

bool hw_vdavinci_scheduled(struct hw_vdavinci *vdavinci,
                           unsigned long current_pages,
                           unsigned long max_pages,
                           unsigned int timeout,
                           ka_page_t *page)
{
#if (IS_VDAVINCI_KERNEL_VERSION_SUPPORT || (defined(DRV_UT)))
    ka_cpumask_var_t next_mask;
    bool ret;

    if (page != NULL) {
        if (!ka_base_zalloc_cpumask_var(&next_mask, KA_GFP_KERNEL)) {
            return false;
        }
        ret = get_node_cpu_by_page(vdavinci, ka_system_smp_processor_id(), page, next_mask);
        if (ret && hw_vdavinci_changed_cpu(ka_task_get_current(), next_mask)) {
            ka_base_free_cpumask_var(next_mask);
            return true;
        }
        ka_base_free_cpumask_var(next_mask);
    }
    if (current_pages >= max_pages) {
        ka_task_set_current_state(KA_TASK_INTERRUPTIBLE);
        ka_task_schedule_timeout((long)ka_system_msecs_to_jiffies(timeout));
        return true;
    }
#endif
    return false;
}

#ifdef CONFIG_NUMA
#if (IS_VDAVINCI_KERNEL_VERSION_SUPPORT || (defined(DRV_UT)))
STATIC bool is_vcpu_thread(ka_task_struct_t *task)
{
    return ka_strstarts(task->comm, "CPU ");
}

STATIC int get_page_node(ka_page_t *page)
{
    if (!ka_mm_pfn_valid(ka_mm_page_to_pfn(page))) {
        return -1;
    }

    return ka_mm_page_to_nid(page);
}
#endif /* VERSION_SUPPORT */
#endif /* CONFIG_NUMA */

bool get_node_cpu_by_page(struct hw_vdavinci *vdavinci,
                          unsigned int current_cpu,
                          ka_page_t *page,
                          ka_cpumask_t *cpumask)
{
#ifdef CONFIG_NUMA
#if (IS_VDAVINCI_KERNEL_VERSION_SUPPORT || (defined(DRV_UT)))
    unsigned int cpu = 0;
    ka_task_struct_t *me = NULL;
    ka_task_struct_t *thread = NULL;
    int page_node = get_page_node(page);
    ka_task_struct_t *qemu_task = vdavinci->qemu_task;
    const ka_cpumask_t *thread_mask;

    if (page_node < 0) {
        return false;
    }
    if (page_node == ka_system_cpu_to_node(current_cpu)) {
        return false;
    }
    me = qemu_task;
    thread = me;
    do {
        if (!is_vcpu_thread(thread)) {
            continue;
        }
        cpu = ka_task_task_cpu(thread);
        if (ka_system_cpu_to_node(cpu) == page_node) {
            ka_base_cpumask_set_cpu(cpu, cpumask);
        }
        thread_mask = ka_get_cpumask(thread);
        ka_base_cpumask_or(&(vdavinci->vm_cpus_mask), &(vdavinci->vm_cpus_mask), thread_mask);
    } ka_while_each_thread(me, thread);
    ka_base_for_each_cpu(cpu, &(vdavinci->vm_cpus_mask)) {
        if (ka_system_cpu_to_node(cpu) == page_node) {
            ka_base_cpumask_set_cpu(cpu, cpumask);
        }
    }
    thread_mask = ka_get_cpumask(qemu_task);
    ka_base_for_each_cpu(cpu, thread_mask) {
        if (ka_system_cpu_to_node(cpu) == page_node) {
            ka_base_cpumask_set_cpu(cpu, cpumask);
        }
    }
#endif /* VERSION_SUPPORT */
#endif /* CONFIG_NUMA */
    return true;
}