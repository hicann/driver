/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef MEMCPY_UK_MSG_H
#define MEMCPY_UK_MSG_H

#include "svm_pub.h"

/* SVM_MEMCPY_LOCAL_EVENT */
struct svm_memcpy_local_msg {
    u64 src;
    u64 dst;
    u64 size;
};

#endif
