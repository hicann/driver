/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <sys/ioctl.h>

#include "ascend_hal.h"
#include "drv_user_common.h"
#include "pbl_uda_user.h"

#include "svm_pub.h"
#include "svm_log.h"
#include "malloc_mng.h"
#include "svm_user_adapt.h"
#include "svm_pipeline.h"
#include "svm_vmm.h"
#include "svm_alloc.h"
#include "svm_master_init.h"
#include "svm_addr_desc.h"
#include "svm_pagesize.h"
#include "va_allocator.h"
#include "svm_dbi.h"
#include "svm_share_align.h"
#include "svm_atomic.h"
#include "svmm.h"
#include "svm_share_type.h"
#include "svm_umc_client.h"
#include "svm_sub_event_type_uk_msg.h"
#include "svm_apbi.h"
#include "svm_sys_cmd.h"
#include "svm_ioctl_ex.h"
#include "svm_flag.h"
#include "soma_ioctl.h"
#include "soma_flag.h"
#include "mem_pool_uk_msg.h"
#include "mem_pool_client.h"

#define SOMA_POOL_PAGE_SHIFT 21
#define SOMA_POOL_HUGE_PAGE_SIZE (1UL << SOMA_POOL_PAGE_SHIFT) /* 2MB */
#define SOMA_MEM_ALLOC 0
#define SOMA_MEM_FREE 1

struct soma_global_va_state {
    struct svm_share_priv_head head;
    bool deleted;
    u64 va;
};

typedef struct {
    drv_mem_handle_t *handle;
    u64 pool_id;
    u64 pool_va;
    u64 pool_size;
    u32 dev_id;
    struct list_head node;
    u64 ref;
} soma_mem_handle;

static struct list_head soma_mem_handle_head = LIST_HEAD_INIT(soma_mem_handle_head);
static pthread_mutex_t soma_mem_handle_lock = PTHREAD_MUTEX_INITIALIZER;

static int soma_mem_ioctl(u32 devid, u64 *va, u64 size, u32 flag, struct svm_global_va *src_info)
{
    struct svm_soma_mem_cfg_para para;
    int ret;

    if (src_info == NULL) {
        return DRV_ERROR_INVALID_VALUE;
    }

    para.va = *va;
    para.size = size;
    para.flag = flag;
    para.src_info = *src_info;

    ret = svm_cmd_ioctl(devid, SVM_SOMA_MEM_CFG, (void *)&para);
    if (ret != DRV_ERROR_NONE) {
        ret = (ret == DRV_ERROR_OPER_NOT_PERMITTED) ? DRV_ERROR_NO_PROCESS : ret;
        svm_err_if((ret != DRV_ERROR_NO_PROCESS),
                   SOMA_LOG_TAG "Mem record ioctl failed. (ret=%d; va=0x%llx; "
                                "flag=%u; size=%llu)\n",
                   ret, *va, flag, size);
        return ret;
    }

    *va = para.va;

    return 0;
}

static int soma_global_va_config(u64 start, int flag)
{
    int ret;
    struct svm_prop src_prop;
    struct svm_global_va src_info;
    ret = svm_get_prop(start, &src_prop);
    if (ret != 0) {
        svm_soma_err("Get src prop failed. (start=%llx)\n", start);
        return ret;
    }

    svm_global_va_pack(0, src_prop.tgid, src_prop.start, src_prop.size, &src_info);
    ret = uda_get_udevid_by_devid_ex(src_prop.devid, &src_info.udevid);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("Get udevid failed. (devid=%u; ret=%d)\n", src_prop.devid, ret);
        return ret;
    }

    ret = soma_mem_ioctl(svm_get_host_devid(), &start, src_prop.size, (u32)flag, &src_info);
    if (ret != 0) {
        svm_soma_err("Config global va failed. (devid=%u; va=%llx)\n", svm_get_host_devid(), start);
    }

    return ret;
}

static int soma_global_va_release(void *priv, bool force)
{
    int ret;
    struct soma_global_va_state *va_state = (struct soma_global_va_state *)priv;
    u64 start = va_state->va;

    (void)force;
    if (!va_state->deleted) {
        ret = soma_global_va_config(start, SVM_SOMA_GLOBAL_VA_DELETE);
        if (ret != 0) {
            svm_soma_err("Config global va failed when destroy pool. (va=%llx)\n", start);
            return ret;
        }
        va_state->deleted = true;
    }

    svm_ua_free(va_state);
    return 0;
}

static int soma_vmm_va_release(void *priv, bool force)
{
    struct svm_global_va src_info;
    u64 va, svm_flag;
    u32 devid;
    int ret;
    void *svmm_inst;

    (void)force;
    svmm_inst = vmm_get_svmm_inst(priv);

    while (svm_svmm_get_first_seg(svmm_inst, &devid, &va, &svm_flag, &src_info) == 0) {
        vmm_restore_real_src_va(&src_info);
        ret = soma_mem_ioctl(devid, &va, src_info.size, SVM_SOMA_MEM_FREE, &src_info);
        if (ret != 0) {
            svm_soma_err("Free soma mem failed. (va=%llx)\n", va);
            break;
        }
        ret = svm_svmm_del_seg(svmm_inst, devid, va, src_info.size, true);
        if (ret != 0) {
            svm_soma_err("Svm del seg failed. (va=%llx)\n", va);
            break;
        }
    }

    svm_vmm_svmm_destroy_priv(priv);
    return 0;
}

static struct svm_priv_ops soma_global_va_priv_ops = {
    .release = soma_global_va_release,
    .get_prop = NULL,
    .show = NULL,
    .should_criu_reset = NULL,
};

static struct svm_priv_ops soma_vmm_va_priv_ops = {
    .release = soma_vmm_va_release,
    .get_prop = NULL,
    .show = NULL,
    .should_criu_reset = NULL,
};

static void mem_handle_get(soma_mem_handle *mem_handle)
{
    if (mem_handle != NULL) {
        svm_atomic64_inc((u64 *)&mem_handle->ref);
    }
}

static int _free_global_va(u64 start)
{
    int ret;

    ret = svm_free(start);
    if (ret) {
        svm_soma_err("Free global va failed. (ret=%d; start%llx)\n", ret, start);
    }

    return ret;
}

static int free_global_va(drv_mem_handle_t *handle)
{
    int ret;
    void *va_handle = NULL;
    struct soma_global_va_state *va_state;
    u64 start = vmm_get_mem_handle_va(handle);

    va_handle = svm_handle_get(start);
    if (va_handle == NULL) {
        svm_soma_err("Get va handle failed. (start=%llx)\n", start);
        return DRV_ERROR_INVALID_VALUE;
    }

    va_state = (struct soma_global_va_state *)svm_get_priv(va_handle);

    ret = soma_global_va_config(start, SVM_SOMA_GLOBAL_VA_DELETE);
    if (ret != 0) {
        svm_handle_put(va_handle);
        svm_soma_err("Config global va failed when destroy pool. (va=%llx)\n", start);
        return ret;
    }
    va_state->deleted = true;
    svm_handle_put(va_handle);

    ret = _free_global_va(start);
    if (ret != 0) {
        svm_soma_err("Free global va failed. (ret=%d; ptr=0x%llx)\n", ret, start);
        return ret;
    }

    svm_ua_free(handle);
    return ret;
}

void mem_handle_put(soma_mem_handle *mem_handle)
{
    u64 old, new;

    if (mem_handle == NULL) {
        return;
    }

    do {
        old = mem_handle->ref;
        if (old == 0) {
            return;
        }
        new = old - 1;
    } while (!svm_atomic64_compare_and_swap((u64 *)&mem_handle->ref, old, new));

    if (new == 0) {
        (void)pthread_mutex_lock(&soma_mem_handle_lock);
        drv_user_list_del(&mem_handle->node);
        (void)pthread_mutex_unlock(&soma_mem_handle_lock);

        free_global_va(mem_handle->handle);
        svm_ua_free(mem_handle);
    }
}

static void soma_mem_handle_release(soma_mem_handle *mem_handle)
{
    mem_handle_put(mem_handle);
}

static soma_mem_handle *soma_mem_get_handle(u64 pool_id)
{
    soma_mem_handle *soma_handle = NULL;
    struct list_head *node = NULL, *tmp = NULL;

    pthread_mutex_lock(&soma_mem_handle_lock);
    list_for_each_safe(node, tmp, &soma_mem_handle_head)
    {
        soma_handle = list_entry(node, soma_mem_handle, node);
        if (soma_handle->pool_id == pool_id) {
            pthread_mutex_unlock(&soma_mem_handle_lock);
            return soma_handle;
        }
    }

    svm_soma_err("Cannot find soma mem handle. (pool_id=%llx)\n", pool_id);
    pthread_mutex_unlock(&soma_mem_handle_lock);
    return NULL;
}

static soma_mem_handle *soma_mem_handle_get(u64 pool_id)
{
    soma_mem_handle *soma_handle = soma_mem_get_handle(pool_id);
    if (soma_handle != NULL) {
        mem_handle_get(soma_handle);
    }

    return soma_handle;
}

static int _malloc_global_va(u64 *va, u64 size, u32 devid, u32 module_id)
{
    u64 align;
    u64 svm_flag = 0;
    int ret = 0;
    struct svm_malloc_location location;

    svm_flag |= SVM_FLAG_CAP_VMM_VA_FREE | SVM_FLAG_ATTR_VA_ONLY | SVM_FLAG_CAP_VMM_EXPORT | SVM_FLAG_BY_PASS_CACHE |
                SVM_FLAG_ATTR_PA_HPAGE | SVM_FLAG_CAP_VMM_MAP;
    ret = svm_query_page_size_by_svm_flag(devid, svm_flag, &align);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("Query page size failed. (ret=%d; devid=%u; flag=0x%llx)\n", ret, devid, svm_flag);
        return ret;
    }

    svm_malloc_location_pack(devid, SVM_MALLOC_NUMA_NO_NODE, &location);
    svm_flag_set_module_id(&svm_flag, module_id);
    ret = svm_malloc(va, size, align, svm_flag, &location);
    if (ret != 0) {
        svm_soma_err("Module mem malloc not success. (ret=%d; size=%llu; devid=%u)\n", ret, size, devid);
        return ret;
    }
    (void)svm_mod_va_devid(*va, devid);
    return ret;
}

static int global_va_malloc_post_proc(u64 start, u32 devid, const struct drv_mem_prop *prop,
                                      drv_mem_handle_t **out_handle)
{
    int ret = 0;
    drv_mem_handle_t *handle = NULL;
    struct soma_global_va_state *va_state = NULL;
    void *va_handle = NULL;

    ret = soma_global_va_config(start, SVM_SOMA_GLOBAL_VA_ALLOC);
    if (ret) {
        svm_soma_err("Get global va cfg failed when create soma pool. (start=%llx)\n", start);
        return ret;
    }

    va_handle = svm_handle_get(start);
    if (va_handle == NULL) {
        svm_err("Get va handle failed. (start=%llx)\n", start);
        ret = DRV_ERROR_INVALID_VALUE;
        goto delete_config;
    }

    va_state = (struct soma_global_va_state *)svm_ua_calloc(1, sizeof(struct soma_global_va_state));
    if (va_state == NULL) {
        (void)svm_set_priv(va_handle, NULL, &soma_global_va_priv_ops);
        svm_err("Malloc failed. (va=0x%llx)\n", start);
        svm_handle_put(va_handle);
        ret = DRV_ERROR_OUT_OF_MEMORY;
        goto delete_config;
    }
    va_state->deleted = false;
    va_state->va = start;
    va_state->head.type = SVM_SHARE_TYPE_SOMA;
    (void)svm_set_priv(va_handle, va_state, &soma_global_va_priv_ops);
    svm_handle_put(va_handle);

    handle = vmm_normal_handle_create(devid, start, prop);
    if (handle == NULL) {
        ret = DRV_ERROR_OUT_OF_MEMORY;
        goto delete_config;
    }
    *out_handle = handle;
    return ret;

delete_config:
    soma_global_va_config(start, SVM_SOMA_GLOBAL_VA_DELETE);
    return ret;
}

static int malloc_global_va(drv_mem_handle_t **out_handle, u64 size, const struct drv_mem_prop *prop)
{
    u32 devid = prop->devid;
    u64 start = 0;
    int ret = 0;
    u32 module_id = (prop->module_id == UNKNOWN_MODULE_ID) ? ASCENDCL_MODULE_ID : prop->module_id;

    ret = _malloc_global_va(&start, size, devid, module_id);
    if (ret) {
        svm_soma_err("Malloc va failed. (ret=%d; size=%llu; devid=%u)\n", ret, size, devid);
        return ret;
    }

    ret = global_va_malloc_post_proc(start, devid, prop, out_handle);
    if (ret) {
        svm_soma_err("Global va malloc  post process failed. (ret=%d)\n", ret);
        (void)_free_global_va(start);
        return ret;
    }

    return ret;
}

static drvError_t mem_pool_create_set_ops(u64 va)
{
    void *va_handle = NULL;
    int ret = 0;

    va_handle = svm_handle_get(va);
    if (va_handle == NULL) {
        svm_soma_err("Get va handle failed. (va=0x%llx)\n", va);
        ret = DRV_ERROR_INVALID_VALUE;
        return ret;
    }
    svm_set_priv_ops(va_handle, &soma_vmm_va_priv_ops);
    svm_set_mem_source(va_handle, SVM_POOL_MEM);
    svm_handle_put(va_handle);
    return ret;
}

static drvError_t halMemPoolCreateInner(soma_mem_pool_t pool, soma_mem_pool_prop prop)
{
    soma_mem_handle *mem_handle = NULL;
    u64 global_va;
    int ret = 0;

    ret = svm_master_init();
    if (ret) {
        svm_soma_err("Svm master init failed. (ret=%d)\n", ret);
        return ret;
    }

    mem_handle = (soma_mem_handle *)svm_ua_calloc(1, sizeof(soma_mem_handle));
    if (mem_handle == NULL) {
        svm_soma_err("Malloc failed. (pool_id=%d)\n", pool.poolId);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    svm_use_pipeline();
    ret = malloc_global_va(&mem_handle->handle, (u64)prop.maxSize, &prop.mem_prop);
    svm_unuse_pipeline();
    if (ret) {
        svm_soma_err("Global va malloc failed. (devid=%u; poolid=%d; ret=%d)\n", pool.devId, pool.poolId, ret);
        goto free_handle;
    }

    global_va = vmm_get_mem_handle_va(mem_handle->handle);
    ret = mem_pool_client_create(pool.devId, pool.poolId, prop.va, prop.maxSize, global_va);
    if (ret) {
        free_global_va(mem_handle->handle);
        svm_soma_err("Pool create remote failed. (devid=%u; poolid=%d; ret=%d, va=0x%llx)\n", pool.devId, pool.poolId,
                     ret, global_va);
        goto free_handle;
    }

    mem_handle->pool_id = pool.poolId;
    mem_handle->pool_va = prop.va;
    mem_handle->pool_size = (u64)prop.maxSize;
    mem_handle->dev_id = pool.devId;
    mem_handle->ref = 1ULL;
    pthread_mutex_lock(&soma_mem_handle_lock);
    drv_user_list_add_tail(&mem_handle->node, &soma_mem_handle_head);
    pthread_mutex_unlock(&soma_mem_handle_lock);
    return ret;

free_handle:
    svm_ua_free(mem_handle);
    return ret;
}

static drvError_t soma_pool_set_mem_source(uint64_t va, memSource mem_source)
{
    void *va_handle = NULL;

    va_handle = svm_handle_get(va);
    if (va_handle == NULL) {
        svm_soma_err("Get va handle failed. (va=0x%llx)\n", va);
        return DRV_ERROR_INVALID_VALUE;
    }
    svm_set_mem_source(va_handle, mem_source);
    svm_handle_put(va_handle);
    return DRV_ERROR_NONE;
}

static int soma_pool_create_para_check(soma_mem_pool_t pool, soma_mem_pool_prop prop)
{
    u64 align;
    struct svm_prop va_prop;
    int ret;

    ret = svm_share_dst_align_use_hpage_size(prop.va, prop.maxSize, pool.devId, &align);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("va is not aligned when create soma pool. (va=0x%llx)\n", prop.va);
        return ret;
    }

    ret = svm_get_prop(prop.va, &va_prop);
    if (ret != 0) {
        svm_soma_err("Get prop failed when create pool. (va=%llx)\n", prop.va);
        return ret;
    }

    if (!svm_flag_cap_is_support_vmm_map(va_prop.flag)) {
        svm_soma_err("Addr cap is not support vmm map. (va=0x%llx)\n", prop.va);
        return DRV_ERROR_INVALID_VALUE;
    }

    if ((prop.handle_type != MEM_HANDLE_TYPE_NONE && prop.handle_type != MEM_HANDLE_TYPE_POSIX) ||
        prop.mem_prop.side != MEM_DEV_SIDE) {
        svm_soma_err("Handle type or side is not supported.\n");
        return DRV_ERROR_INVALID_VALUE;
    }

    if (prop.mem_prop.module_id != ASCENDCL_MODULE_ID) {
        svm_soma_err("module id is not supported. (module_id=%u)\n", prop.mem_prop.module_id);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (prop.mem_prop.pg_type != MEM_HUGE_PAGE_TYPE || prop.mem_prop.mem_type != MEM_HBM_TYPE) {
        svm_soma_err("page type or mem type is not supported. (pg_type=%u; mem_type=%u)\n", prop.mem_prop.pg_type,
                     prop.mem_prop.mem_type);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (prop.maxSize == 0) {
        svm_soma_err("Zero va or maxSize. (va=0x%llx; maxSize=0x%llx)\n", prop.va, prop.maxSize);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (pool.devId != prop.mem_prop.devid) {
        svm_soma_err("Pool devid is not equal Prop devid. (pool.devId=0x%u; prop.devIde=0x%u)\n", pool.devId,
                     prop.mem_prop.devid);
        return DRV_ERROR_INVALID_VALUE;
    }

    return ret;
}

drvError_t halMemPoolCreate(soma_mem_pool_t pool, soma_mem_pool_prop prop)
{
    int ret;

    ret = soma_pool_create_para_check(pool, prop);
    if (ret) {
        return ret;
    }

    ret = mem_pool_create_set_ops(prop.va);
    if (ret) {
        svm_soma_err("Pool create pre proc failed. (devid=%u; poolid=%d; ret=%d)\n", pool.devId, pool.poolId, ret);
        return ret;
    }

    ret = halMemPoolCreateInner(pool, prop);
    if (ret) {
        svm_soma_err("Pool create pre proc failed. (devid=%u; poolid=%d; ret=%d)\n", pool.devId, pool.poolId, ret);
        soma_pool_set_mem_source(prop.va, SVM_NORMAL_MEM);
    }

    return ret;
}

static int somaPoolDestroyInner(soma_mem_pool_t pool)
{
    int ret;
    soma_mem_handle *mem_handle = NULL;
    uint64_t va;

    mem_handle = soma_mem_handle_get(pool.poolId);
    if (mem_handle == NULL || mem_handle->dev_id != pool.devId) {
        svm_soma_err("Invalid pool. (pool_id=%llx)\n", pool.poolId);
        if (mem_handle != NULL) {
            mem_handle_put(mem_handle);
        }
        return DRV_ERROR_NOT_EXIST;
    }

    ret = mem_pool_client_destory(pool.devId, pool.poolId, (u64 *)&va);
    if (ret != DRV_ERROR_NONE) {
        mem_handle_put(mem_handle);
        return ret;
    }

    ret = soma_pool_set_mem_source(va, SVM_NORMAL_MEM);
    if (ret) {
        svm_soma_err("Pool destroy pre proc failed. (devid=%u; poolid=%d; ret=%d)\n", pool.devId, pool.poolId, ret);
        mem_handle_put(mem_handle);
        return ret;
    }
    ret = halMemAddressFree((void *)(uintptr_t)va);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("Free reserved va failed. (va=0x%llx; ret=%d)\n", va, ret);
        mem_handle_put(mem_handle);
        return ret;
    }

    mem_handle_put(mem_handle);
    soma_mem_handle_release(mem_handle);

    return DRV_ERROR_NONE;
}

drvError_t halMemPoolDestroy(soma_mem_pool_t pool)
{
    return somaPoolDestroyInner(pool);
}

static int soma_pool_check_attr_val(enum soma_mem_pool_attr attr, int64_t val)
{
    switch (attr) {
        case SOMA_MEM_POOL_ATTR_RELEASE_THRESHOLD:
            if (val < 0) {
                svm_soma_err("Negative value for release threshold is not allowed. (attr=0x%x; value=%lld)\n", attr,
                             val);
                return DRV_ERROR_INVALID_VALUE;
            }
            if (!SVM_IS_ALIGNED((uint64_t)val, SOMA_POOL_HUGE_PAGE_SIZE)) {
                svm_soma_err("Release threshold not aligned to 2MB. (attr=0x%x; value=%lld)\n", attr, val);
                return DRV_ERROR_INVALID_VALUE;
            }
            return DRV_ERROR_NONE;

        case SOMA_MEM_POOL_ATTR_RESERVED_MEM_CURRENT:
            svm_soma_err(
                "Write to read-only attribute SOMA_MEM_POOL_ATTR_RESERVED_MEM_CURRENT is not allowed. (attr=0x%x)\n",
                attr);
            return DRV_ERROR_INVALID_VALUE;

        case SOMA_MEM_POOL_ATTR_RESERVED_MEM_HIGH:
            if (val == 0) {
                return DRV_ERROR_NONE;
            }
            svm_soma_err("Write non-zero value to SOMA_MEM_POOL_ATTR_RESERVED_MEM_HIGH is not allowed. (attr=0x%x; "
                         "value=%llu)\n",
                         attr, val);
            return DRV_ERROR_INVALID_VALUE;

        case SOMA_MEM_POOL_ATTR_USED_MEM_CURRENT:
            svm_soma_err(
                "Write to read-only attribute SOMA_MEM_POOL_ATTR_USED_MEM_CURRENT is not allowed. (attr=0x%x)\n", attr);
            return DRV_ERROR_INVALID_VALUE;

        case SOMA_MEM_POOL_ATTR_USED_MEM_HIGH:
            if (val == 0) {
                return DRV_ERROR_NONE;
            }
            svm_err(
                "Write non-zero value to SOMA_MEM_POOL_ATTR_USED_MEM_HIGH is not allowed. (attr=0x%x; value=%llu)\n",
                attr, val);
            return DRV_ERROR_INVALID_VALUE;

        default:
            svm_soma_err("Unsupported attribute for set attr. (attr=0x%x)\n", attr);
            return DRV_ERROR_NOT_SUPPORT;
    }
}

drvError_t halMemPoolSetAttr(soma_mem_pool_t pool, enum soma_mem_pool_attr attr, void *value)
{
    int64_t val;
    int ret;
    soma_mem_handle *soma_handle = NULL;

    if (value == NULL) {
        svm_soma_err("Null pointer value for set attr is not allowed. (attr=0x%x)\n", attr);
        return DRV_ERROR_INVALID_VALUE;
    }

    soma_handle = soma_mem_get_handle(pool.poolId);
    if (soma_handle == NULL) {
        svm_soma_err("Invalid pool id. (poolId=%d)\n", pool.poolId);
        return DRV_ERROR_INVALID_VALUE;
    }

    val = *(int64_t *)value;
    ret = soma_pool_check_attr_val(attr, val);
    if (ret != 0) {
        svm_soma_err("SOMA pool check attr val failed. (poolId=%d, attr=%d, val=%d)\n", pool.poolId, (int)attr, val);
        return ret;
    }

    ret = mem_pool_client_set_attr(pool.devId, pool.poolId, (u64)attr, (u64)val);
    if (ret != 0) {
        svm_soma_err("SOMA pool client set attr failed. (poolId=%d, attr=%d, val=%d, ret=%d)\n", pool.poolId, (int)attr,
                     val, ret);
    }

    return ret;
}

drvError_t halMemPoolGetAttr(soma_mem_pool_t pool, enum soma_mem_pool_attr attr, void *value)
{
    uint64_t val;
    int ret;
    soma_mem_handle *soma_handle = NULL;

    if (value == NULL) {
        svm_soma_err("Null pointer value for get attr is not allowed. (attr=0x%x)\n", attr);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (attr < SOMA_MEM_POOL_ATTR_RELEASE_THRESHOLD || attr > SOMA_MEM_POOL_ATTR_USED_MEM_HIGH) {
        svm_soma_err("Invalid attr for get attr. (attr=0x%x)\n", attr);
        return DRV_ERROR_INVALID_VALUE;
    }

    soma_handle = soma_mem_get_handle(pool.poolId);
    if (soma_handle == NULL) {
        svm_soma_err("Invalid pool id. (poolId=%d)\n", pool.poolId);
        return DRV_ERROR_INVALID_VALUE;
    }

    ret = mem_pool_client_get_attr(pool.devId, pool.poolId, attr, (u64 *)&val);
    if (ret == DRV_ERROR_NONE) {
        *(uint64_t *)value = val;
    }

    return ret;
}

static u64 soma_build_malloc_flag(u64 src_svm_flag)
{
    u64 svm_flag = 0;

#ifdef EMU_ST /* Simulation ST support test. */
    svm_flag |= SVM_FLAG_CAP_PREFETCH;
    svm_flag |= SVM_FLAG_CAP_REGISTER | SVM_FLAG_CAP_UNREGISTER;
#endif
    svm_flag |= SVM_FLAG_CAP_VMM_MAP;
    svm_flag |= SVM_FLAG_CAP_VMM_UNMAP;
    svm_flag |= SVM_FLAG_CAP_VMM_VA_FREE;
    svm_flag |= SVM_FLAG_ATTR_VA_ONLY;
    svm_flag |= SVM_FLAG_CAP_GET_D2D_TRANS_WAY;
    svm_flag |= SVM_FLAG_CAP_REGISTER_ACCESS;
    svm_flag |= SVM_FLAG_CAP_SYNC_COPY_EX;
    svm_flag |= SVM_FLAG_CAP_MEMSET;
    svm_flag |= SVM_FLAG_CAP_ASYNC_COPY_SUBMIT | SVM_FLAG_CAP_ASYNC_COPY_WAIT;
    svm_flag |= SVM_FLAG_CAP_SYNC_COPY_2D | SVM_FLAG_CAP_DMA_DESC_CONVERT_2D;
    svm_flag |= SVM_FLAG_CAP_SYNC_COPY | SVM_FLAG_CAP_SYNC_COPY_BATCH;
    svm_flag |= SVM_FLAG_CAP_GET_ATTR | SVM_FLAG_CAP_GET_ADDR_CHECK_INFO | SVM_FLAG_CAP_GET_MEM_TOKEN_INFO;
    svm_flag |= SVM_FLAG_CAP_DMA_DESC_CONVERT | SVM_FLAG_CAP_DMA_DESC_DESTROY | SVM_FLAG_CAP_DMA_DESC_SUBMIT |
                SVM_FLAG_CAP_DMA_DESC_WAIT;
    svm_flag |= src_svm_flag & SVM_FLAG_ATTR_PA_GPAGE;
    svm_flag |= src_svm_flag & SVM_FLAG_ATTR_PA_HPAGE;
    svm_flag |= src_svm_flag & SVM_FLAG_ATTR_PA_CONTIGUOUS;
    svm_flag |= src_svm_flag & SVM_FLAG_ATTR_PA_P2P;
    svm_flag_set_module_id(&svm_flag, svm_flag_get_module_id(src_svm_flag));

    return svm_flag;
}

static int _soma_mem_malloc_cfg(void *va_handle, u64 va, u64 size, struct svm_prop *src_prop, drv_mem_handle_t *handle)
{
    struct svm_dst_va dst_info;
    struct svm_global_va src_info;
    void *svmm_inst = NULL;
    u64 svm_flag = 0;
    u32 smm_flag = SVM_SOMA_MEM_ALLOC;
    int ret;

    svmm_inst = vmm_get_svmm(va_handle);
    if (svmm_inst == NULL) { /* vmm map addr first prefetch */
        svm_soma_err("Get svmm inst failed. (va=%llx)\n", va);
        return DRV_ERROR_INVALID_VALUE;
    }

    svm_global_va_pack(0, src_prop->tgid, src_prop->start, size, &src_info);
    ret = uda_get_udevid_by_devid_ex(src_prop->devid, &src_info.udevid);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("Get udevid failed. (devid=%u; ret=%d)\n", src_prop->devid, ret);
        return ret;
    }

    svm_flag = soma_build_malloc_flag(src_prop->flag);
    src_info.va = (u64)(uintptr_t)handle; /* use va to store handle, get real va from handle */
    ret = svm_svmm_add_seg(svmm_inst, src_prop->devid, va, svm_flag, &src_info);
    if (ret != 0) {
        svm_soma_err("Add seg failed. (devid=%u; va=%llx; size=%llx)\n", src_prop->devid, va, size);
        return ret;
    }

    src_info.va = src_prop->start; /* map use real va */

    svm_dst_va_pack(svm_get_host_devid(), PROCESS_CP1, va, size, &dst_info);
    ret = soma_mem_ioctl(dst_info.devid, &dst_info.va, dst_info.size, smm_flag, &src_info);
    if (ret != 0) {
        svm_soma_err("SOMA mem malloc cfg failed. (devid=%u; va=%llx; size=%llx)\n", src_prop->devid, va, size);
        (void)svm_svmm_del_seg(svmm_inst, src_prop->devid, va, size, true);
        return ret;
    }

    return 0;
}

static int soma_mem_malloc_cfg(u64 va, u64 size, drv_mem_handle_t *handle)
{
    u64 handle_start = vmm_get_mem_handle_va(handle);
    struct svm_prop src_prop;
    void *va_handle = NULL;
    int ret;

    ret = svm_get_prop(handle_start, &src_prop);
    if (ret != 0) {
        svm_soma_err("Get src prop failed. (handle_start=%llx)\n", handle_start);
        return ret;
    }

    if (!svm_flag_cap_is_support_vmm_map(src_prop.flag)) {
        svm_soma_err("Addr cap is not support vmm map. (handle_start=0x%llx)\n", handle_start);
        return DRV_ERROR_INVALID_VALUE;
    }

    if ((!svm_is_va_page_align(src_prop.devid, src_prop.flag, va)) ||
        (!svm_is_page_align(src_prop.devid, src_prop.flag, size))) {
        svm_soma_err("Not align. (devid=%u; flag=0x%llx; va=0x%llx; size=0x%llx)\n", src_prop.devid, src_prop.flag, va,
                     size);
        return DRV_ERROR_INVALID_VALUE;
    }

    va_handle = svm_handle_get(va);
    if (va_handle == NULL) { /* maybe va has been free after get prop */
        svm_soma_err("Get va handle failed. (va=%llx)\n", va);
        return DRV_ERROR_INVALID_VALUE;
    }

    ret = _soma_mem_malloc_cfg(va_handle, va, size, &src_prop, handle);
    svm_handle_put(va_handle);

    return ret;
}

static int soma_validate_cfg_params(u64 va, u64 size, const soma_mem_handle *soma_handle)
{
    u64 end;
    u64 pool_end;

    if ((va == 0) || (soma_handle == NULL) || (soma_handle->handle == NULL) || (size == 0) ||
        !SVM_IS_ALIGNED(va, SOMA_POOL_HUGE_PAGE_SIZE) || !SVM_IS_ALIGNED(size, SOMA_POOL_HUGE_PAGE_SIZE) ||
        (va + size < va) || (soma_handle->pool_va + soma_handle->pool_size < soma_handle->pool_va)) {
        svm_soma_err("Pool cfg invalid para. (pool_id=%llu)\n", soma_handle == NULL ? 0ULL : soma_handle->pool_id);
        return DRV_ERROR_INVALID_VALUE;
    }

    end = va + size;
    pool_end = soma_handle->pool_va + soma_handle->pool_size;
    if ((va < soma_handle->pool_va) || (end > pool_end)) {
        svm_soma_err("Pool cfg addr out of range. (pool_id=%llu)\n", soma_handle->pool_id);
        return DRV_ERROR_INVALID_VALUE;
    }

    return DRV_ERROR_NONE;
}

static int soma_pool_malloc_cfg(u64 va, u64 size, soma_mem_handle *soma_handle)
{
    int ret;

    ret = soma_validate_cfg_params(va, size, soma_handle);
    if (ret != 0) {
        return ret;
    }

    svm_use_pipeline();
    ret = soma_mem_malloc_cfg(va, size, soma_handle->handle);
    svm_unuse_pipeline();

    return ret;
}

static int _soma_mem_free_cfg(u32 devid, void *va_handle, u64 va, u64 size)
{
    struct svm_dst_va dst_info;
    struct svm_global_va src_info;
    void *svmm_inst = NULL;
    u64 start = va;
    u64 svm_flag;
    u32 smm_flag = SVM_SOMA_MEM_FREE;
    int ret;

    svmm_inst = vmm_get_svmm(va_handle);
    if (svmm_inst == NULL) { /* vmm map addr first prefetch */
        svm_soma_err("Get svmm inst failed. (va=0x%llx)\n", va);
        return DRV_ERROR_INVALID_VALUE;
    }

    src_info.udevid = SVM_INVALID_UDEVID;
    ret = svm_svmm_get_seg(svmm_inst, &devid, &start, &svm_flag, &src_info);
    if (ret != 0) {
        svm_soma_err("Get seg failed. (devid=%u; va=0x%llx; size=0x%llx)\n", devid, va, size);
        return ret;
    }

    vmm_restore_real_src_va(&src_info);

    ret = svm_svmm_del_seg(svmm_inst, devid, va, size, false);
    if (ret != DRV_ERROR_NONE) {
        svm_soma_err("Del seg failed. (ret=%d; devid=%u; va=0x%llx; size=0x%llx)\n", ret, devid, va, size);
        return ret;
    }

    svm_dst_va_pack(svm_get_host_devid(), PROCESS_CP1, start, size, &dst_info);
    ret = soma_mem_ioctl(dst_info.devid, &dst_info.va, dst_info.size, smm_flag, &src_info);
    if (ret != 0) {
        /* not rollback */
        svm_soma_err("SOMA mem free cfg failed. (devid=%u; va=0x%llx; size=0x%llx)\n", devid, start, size);
        return ret;
    }

    return 0;
}

static int soma_mem_free_cfg(u64 va, u64 size)
{
    struct svm_prop prop;
    void *va_handle = NULL;
    int ret;

    ret = svm_get_prop(va, &prop);
    if (ret != 0) {
        svm_soma_err("Free cfg find addr failed. (va=0x%llx)\n", va);
        return ret;
    }

    va_handle = svm_handle_get(va);
    if (va_handle == NULL) { /* maybe va has been free after get prop */
        svm_soma_err("Get va handle failed. (va=%llx)\n", va);
        return DRV_ERROR_INVALID_VALUE;
    }

    ret = _soma_mem_free_cfg(prop.devid, va_handle, va, size);
    svm_handle_put(va_handle);

    return ret;
}

static int soma_pool_free_cfg(u64 va, u64 size, soma_mem_handle *soma_handle)
{
    int ret;

    ret = soma_validate_cfg_params(va, size, soma_handle);
    if (ret != 0) {
        return ret;
    }

    svm_use_pipeline();
    ret = soma_mem_free_cfg((u64)va, (u64)size);
    svm_unuse_pipeline();

    return ret;
}

static bool soma_mem_flag_is_malloc(uint32_t flag)
{
    return flag == SOMA_MEM_ALLOC;
}

static bool soma_mem_flag_is_free(uint32_t flag)
{
    return flag == SOMA_MEM_FREE;
}

drvError_t halMemPoolAsyncConfig(soma_mem_pool_t pool, uint64_t va, uint64_t size, uint32_t flag)
{
    int ret = 0;
    soma_mem_handle *soma_handle = soma_mem_handle_get(pool.poolId);
    if (soma_handle == NULL || soma_handle->dev_id != pool.devId) {
        svm_soma_err("Invalid pool id. (poolId=%d)\n", pool.poolId);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (soma_handle->handle == NULL) {
        svm_soma_err("Invalid pool id. (poolId=%d)\n", pool.poolId);
        ret = DRV_ERROR_INVALID_VALUE;
        goto out;
    }

    if (soma_mem_flag_is_malloc((u32)flag)) {
        ret = soma_pool_malloc_cfg((u64)va, (u64)size, soma_handle);
    } else if (soma_mem_flag_is_free((u32)flag)) {
        ret = soma_pool_free_cfg((u64)va, (u64)size, soma_handle);
    } else {
        svm_soma_err("SOMA mem pool config param flag is invalid. (poolId=%d)\n", flag);
        ret = DRV_ERROR_NOT_SUPPORT;
    }
out:
    mem_handle_put(soma_handle);
    return ret;
}
