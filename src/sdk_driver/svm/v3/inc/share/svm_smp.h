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

#ifndef SVM_SMP_H
#define SVM_SMP_H

#include "ka_type.h"

#include "svm_addr_desc.h"

/*
   SMP: share memory pin
   add/del: When the memory is applied(with pa) for or released, the memory information is maintained in the SMP.
   pin/unpin: When the applied memory needs to be shared with others, you needs to be pin the memory.
              After the pin is pinned, a failure message is returned when the memory is released.
              After the sharing is complete, you need to unpin the memory.
              If the memory is released, an event(struct svm_smp_del_msg) is triggered to the memory applicant
              so that the memory applicant can release the memory.
*/

#define SVM_SMP_FLAG_DEV_CP_ONLY (1U << 0U)

int svm_smp_add_mem(u32 udevid, int tgid, u64 start, u64 size, u32 flag);
/* if mem ref if bigger than 1(pin by others), del method will return -EBUSY,
   and set mem invalid, then pin mem will return failed */
int svm_smp_del_mem(u32 udevid, int tgid, u64 start); /* start must same with the start in added */
int svm_smp_pin_mem(u32 udevid, int tgid, u64 va, u64 size, bool is_cross_app);   /* va and size is in range of added */
int svm_smp_unpin_mem(u32 udevid, int tgid, u64 va, u64 size, bool is_cross_app); /* must same with pin */

/*
 * Check if the memory exists and is not occupied.
 * return -EOWNERDEAD: memory is released.
 * return -EBUSY: memory is occupied.
 */
int svm_smp_check_mem(u32 udevid, int tgid, u64 va, u64 size);

static inline int svm_smp_check_mem_exists(u32 udevid, int tgid, u64 va, u64 size)
{
    int ret = svm_smp_check_mem(udevid, tgid, va, size);
    return (ret == -EBUSY) ? 0 : ret;
}

/* pin device cp only mem */
int svm_smp_pin_dev_cp_only_mem(u32 udevid, int tgid, u64 va, u64 size);
int svm_smp_unpin_dev_cp_only_mem(u32 udevid, int tgid, u64 va, u64 size);
int svm_smp_check_dev_cp_only_mem(u32 udevid, int tgid, u64 va, u64 size);

/*
 * seg_num: input&output, return the minimum value
 *          between the input seg_num and the actual seg_num in [va, size)
 */
int svm_smp_query_mem_pa(u32 udevid, int tgid, u64 va, u64 size, struct svm_pa_seg *pa_seg, u64 *seg_num);
int svm_smp_set_mem_pa(u32 udevid, int tgid, u64 va, u64 size, struct svm_pa_seg *pa_seg, u64 seg_num);
#endif
