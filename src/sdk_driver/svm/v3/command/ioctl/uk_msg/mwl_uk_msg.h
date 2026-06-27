/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef MWL_UK_MSG_H
#define MWL_UK_MSG_H

#include "svm_pub.h"

struct svm_mwl_op_msg {
    u64 va;
    u64 size;
    u64 flag;
    u64 rsv; /* reserve */
};

#endif
