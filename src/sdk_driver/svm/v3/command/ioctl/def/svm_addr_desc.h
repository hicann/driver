/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SVM_ADDR_DESC_H
#define SVM_ADDR_DESC_H

#include "svm_pub.h"

/* used in host and device */
struct svm_global_va {
    u32 server_id;
    u32 udevid; /* host global view udevid */
    int tgid;
    u64 va;
    u64 size;
};

/* used in host */
struct svm_dst_va {
    u32 devid;
    u32 task_type; /* processType_t, invalid when devid is host id */
    u64 va;
    u64 size;
};

struct svm_pa_seg {
    u64 pa;
    u64 size;
};

struct svm_dma_addr_seg {
    u64 dma_addr;
    u64 size;
};

static inline void svm_global_va_pack(u32 udevid, int tgid, u64 va, u64 size, struct svm_global_va *global_va)
{
    global_va->server_id = SVM_INVALID_SERVER_ID;
    global_va->udevid = udevid;
    global_va->tgid = tgid;
    global_va->va = va;
    global_va->size = size;
}

static inline void svm_dst_va_pack(u32 devid, u32 task_type, u64 va, u64 size, struct svm_dst_va *dst_va)
{
    dst_va->devid = devid;
    dst_va->task_type = task_type;
    dst_va->va = va;
    dst_va->size = size;
}

#endif
