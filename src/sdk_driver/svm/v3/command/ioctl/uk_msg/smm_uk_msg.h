/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SMM_UK_MSG_H
#define SMM_UK_MSG_H

#include "svm_pub.h"
#include "svm_addr_desc.h"

struct svm_smm_map_msg {
    u64 dst_va;
    u64 dst_size;
    u32 dst_task_type;
    u32 flag;
    struct svm_global_va src_info;
    u64 rsv; /* reserve */
};

struct svm_smm_unmap_msg {
    u64 dst_va;
    u64 dst_size;
    u32 dst_task_type;
    u32 flag;
    struct svm_global_va src_info;
    u64 rsv; /* reserve */
};

#endif
