/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SOMA_IOCTL_H
#define SOMA_IOCTL_H

#include "svm_pub.h"
#include "svm_addr_desc.h"

struct svm_soma_mem_cfg_para {
    u64 va;                        /* input */
    u64 size;                      /* input */
    u32 flag;                      /* input */
    struct svm_global_va src_info; /* input */
};

#endif