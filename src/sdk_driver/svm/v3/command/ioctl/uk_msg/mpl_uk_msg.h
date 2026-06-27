/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef MPL_UK_MSG_H
#define MPL_UK_MSG_H

#include "svm_pub.h"

struct svm_mpl_populate_msg {
    u64 va;
    u64 size;
    u32 flag;
    u64 rsv; /* reserve */
};

struct svm_mpl_depopulate_msg {
    u64 va;
    u64 size;
    int is_busy;
    u32 flag;
    u64 rsv; /* reserve */
};

#endif
