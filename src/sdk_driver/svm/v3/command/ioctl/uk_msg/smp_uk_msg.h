/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SMP_UK_MSG_H
#define SMP_UK_MSG_H

#include "svm_pub.h"

/* SVM_SMP_DEL_MEM_EVENT */
struct svm_smp_del_msg {
    u64 va;
    u64 size;
};

#endif
