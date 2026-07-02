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
#include "pbl_uda.h"
#include "dpa_kernel_interface.h"

#include "dbi_kern.h"
#include "pmq_client.h"
#include "svm_um_handle.h"
#include "svm_kern_log.h"
#include "mpl_uk_msg.h"
#include "mpl_flag.h"
#include "svm_smp.h"
#include "svm_slab.h"
#include "pma.h"
#include "assign_um_handle.h"
#include "mms_kern.h"

static int um_mpl_populate_pre_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mpl_populate_msg *populate_msg = (struct svm_mpl_populate_msg *)msg;
    int ret;

    if ((msg_len != sizeof(*populate_msg)) || (udevid == uda_get_host_id())) {
        svm_err("Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid,
                slave_tgid, msg_len);
        return -EINVAL;
    }

    ret = svm_smp_check_mem_exists(udevid, master_tgid, populate_msg->va, populate_msg->size);
    if (ret == 0) {
        svm_err("Smp existed, not allow to populate. (udevid=%u; master_tgid=%d; va=0x%llx; size=%llu)\n", udevid,
                master_tgid, populate_msg->va, populate_msg->size);
        return -EADDRINUSE;
    }

    if ((populate_msg->flag & SVM_MPL_FLAG_NO_REMOTE_OPS) != 0) {
        ret = svm_smp_add_mem(udevid, master_tgid, populate_msg->va, populate_msg->size, populate_msg->flag);
        if (ret != 0) {
            svm_err("Smp add mem failed. (ret=%d; udevid=%u; master_tgid=%d; va=0x%llx; size=%llu)\n", ret, udevid,
                    master_tgid, populate_msg->va, populate_msg->size);
            return ret;
        }
        return -EINPROGRESS; /* return this to abord event submit */
    }
    return 0;
}

static void um_mpl_populate_pre_cancel_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    svm_mms_dev_show(udevid);
}

static u64 mpl_flag_to_page_size(u32 udevid, u32 mpl_flag)
{
    u64 page_size = 0;
    int ret;

    if ((mpl_flag & SVM_MPL_FLAG_GPAGE) != 0) {
        ret = svm_dbi_kern_query_gpage_size(udevid, &page_size);
    } else if ((mpl_flag & SVM_MPL_FLAG_HPAGE) != 0) {
        ret = svm_dbi_kern_query_hpage_size(udevid, &page_size);
    } else {
        ret = svm_dbi_kern_query_npage_size(udevid, &page_size);
    }
    if (ret != 0) {
        svm_err("Query page size failed. (udevid=%u; mpl_flag=0x%x)\n", udevid, mpl_flag);
    }

    return page_size;
}

static int um_mpl_fill_pa_seg(u32 udevid, int master_tgid, u64 va, u64 size, u32 flag)
{
    struct svm_global_va va_info;
    struct svm_pa_seg *pa_seg = NULL;
    u64 page_size, seg_num;
    int ret, slave_tgid;

    ret = hal_kernel_apm_query_slave_tgid_by_master(master_tgid, udevid, PROCESS_CP1, &slave_tgid);
    if (ret != 0) {
        svm_err("Get slave tgid failed. (ret=%d; udevid=%u; tgid=%d)\n", ret, udevid, master_tgid);
        return ret;
    }

    page_size = mpl_flag_to_page_size(udevid, flag);
    if (page_size == 0) {
        svm_err("Get page size failed. (udevid=%u; tgid=%d; va=0x%llx; size=%llu)\n", udevid, master_tgid, va, size);
        return -EINVAL;
    }

    seg_num = svm_get_align_up_num(va, size, page_size);
    pa_seg = svm_vzalloc(seg_num * sizeof(struct svm_pa_seg));
    if (pa_seg == NULL) {
        svm_err("Alloc pa_seg failed. (udevid=%u; tgid=%d; va=0x%llx; size=%llu; seg_num=%llu)\n", udevid, master_tgid,
                va, size, seg_num);
        return -EINVAL;
    }

    svm_global_va_pack(udevid, slave_tgid, va, size, &va_info);
    ret = svm_pmq_client_pa_query(uda_get_host_id(), &va_info, pa_seg, &seg_num);
    if (ret != 0) {
        svm_vfree(pa_seg);
        svm_err("Query pa failed. (udevid=%u; tgid=%d; va=0x%llx; size=%llu)\n", udevid, master_tgid, va, size);
        return 0;
    }

    ret = svm_smp_set_mem_pa(udevid, master_tgid, va, size, pa_seg, seg_num);
    svm_vfree(pa_seg);
    svm_debug("Fill seg. (ret=%d; udevid=%u; tgid=%d; va=0x%llx; size=%llu; page_size=%llu; seg_num=%llu)\n", ret,
              udevid, master_tgid, va, size, page_size, seg_num);
    return 0;
}

static int um_mpl_populate_post_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mpl_populate_msg *populate_msg = (struct svm_mpl_populate_msg *)msg;
    u32 flag = 0;
    int ret;

    if ((msg_len != sizeof(*populate_msg)) || (udevid == uda_get_host_id())) {
        svm_err("Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid,
                slave_tgid, msg_len);
        return -EINVAL;
    }
    if (populate_msg->size == 0) {
        svm_err("Invalid size. (udevid=%u; master_tgid=%d; va=0x%llx; size=%llu)\n", udevid, master_tgid,
                populate_msg->va, populate_msg->size);
        return -EINVAL;
    }

    flag |= ((populate_msg->flag & SVM_MPL_FLAG_DEV_CP_ONLY) != 0) ? SVM_SMP_FLAG_DEV_CP_ONLY : 0;
    ret = svm_smp_add_mem(udevid, master_tgid, populate_msg->va, populate_msg->size, flag);
    if (ret != 0) {
        svm_err("Smp add mem failed in mpl um post handle. (udevid=%u; master_tgid=%d; va=0x%llx; size=%llu)\n", udevid,
                master_tgid, populate_msg->va, populate_msg->size);
        return ret;
    }

    ret = um_mpl_fill_pa_seg(udevid, master_tgid, populate_msg->va, populate_msg->size, populate_msg->flag);
    if (ret != 0) {
        svm_err("Fill pa list failed. (udevid=%u; tgid=%d; va=0x%llx; size=%llu)\n", udevid, master_tgid,
                populate_msg->va, populate_msg->size);
        svm_smp_del_mem(udevid, master_tgid, populate_msg->va);
    }
    return ret;
}

static int um_mpl_depopulate_pre_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mpl_depopulate_msg *depopulate_msg = (struct svm_mpl_depopulate_msg *)msg;
    int ret;

    if ((msg_len != sizeof(*depopulate_msg)) || (udevid == uda_get_host_id())) {
        svm_err("Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid,
                slave_tgid, msg_len);
        return -EINVAL;
    }

    ret = svm_smp_del_mem(udevid, master_tgid, depopulate_msg->va);
    if (ret == -EBUSY) {
        depopulate_msg->is_busy = 1;
    }

    pma_mem_recycle_notify(udevid, master_tgid, depopulate_msg->va, depopulate_msg->size);

    if ((depopulate_msg->flag & SVM_MPL_FLAG_NO_REMOTE_OPS) != 0) {
        return -EINPROGRESS; /* return this to abord event submit */
    }

    return ((ret == -EBUSY) ? 0 : ret);
}

static int um_mpl_populate_no_pin_pre_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mpl_populate_msg *populate_msg = (struct svm_mpl_populate_msg *)msg;
    int ret;

    if ((msg_len != sizeof(*populate_msg)) || (udevid == uda_get_host_id())) {
        svm_err("Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid,
                slave_tgid, msg_len);
        return -EINVAL;
    }

    ret = svm_smp_check_mem(udevid, master_tgid, populate_msg->va, populate_msg->size);
    if (ret != 0) {
        ret = svm_smp_check_dev_cp_only_mem(udevid, master_tgid, populate_msg->va, populate_msg->size);
    }

    return ret;
}

static int um_mpl_depopulate_no_unpin_pre_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mpl_depopulate_msg *depopulate_msg = (struct svm_mpl_depopulate_msg *)msg;
    int ret;

    if ((msg_len != sizeof(*depopulate_msg)) || (udevid == uda_get_host_id())) {
        svm_err("Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid,
                slave_tgid, msg_len);
        return -EINVAL;
    }

    ret = svm_smp_check_mem(udevid, master_tgid, depopulate_msg->va, depopulate_msg->size);
    if (ret != 0) {
        ret = svm_smp_check_dev_cp_only_mem(udevid, master_tgid, depopulate_msg->va, depopulate_msg->size);
    }
    if (ret == 0) {
        pma_mem_recycle_notify(udevid, master_tgid, depopulate_msg->va, depopulate_msg->size);
    }

    return ret;
}

void assign_um_handle_init(void)
{
    svm_um_register_handle(SVM_MPL_POPULATE_EVENT, um_mpl_populate_pre_handle, um_mpl_populate_pre_cancel_handle,
                           um_mpl_populate_post_handle);
    svm_um_register_handle(SVM_MPL_DEPOPULATE_EVENT, um_mpl_depopulate_pre_handle, NULL, NULL);
    svm_um_register_handle(SVM_MPL_POPULATE_NO_PIN_EVENT, um_mpl_populate_no_pin_pre_handle, NULL, NULL);
    svm_um_register_handle(SVM_MPL_DEPOPULATE_NO_UNPIN_EVENT, um_mpl_depopulate_no_unpin_pre_handle, NULL, NULL);
}
