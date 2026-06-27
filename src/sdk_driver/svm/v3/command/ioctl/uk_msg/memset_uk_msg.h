/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef MEMSET_UK_MSG_H
#define MEMSET_UK_MSG_H

#include "svm_pub.h"

/* SVM_MEMSET_DEV_EVENT */
struct svm_memset_msg {
    u64 va;
    u64 size;
    u8 val;
};

#endif
