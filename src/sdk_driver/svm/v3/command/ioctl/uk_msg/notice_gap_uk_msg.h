/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef NOTICE_GAP_UK_MSG_H
#define NOTICE_GAP_UK_MSG_H

#include "svm_pub.h"

/* SVM_NOTICE_GAP_VA_EVENT */
struct svm_notice_gap_msg {
    u32 op; /* 1 add, 0 del */
    u64 host_gap_va;
    u64 size;
};

#endif
