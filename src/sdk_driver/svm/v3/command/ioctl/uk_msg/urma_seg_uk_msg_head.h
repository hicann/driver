/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef URMA_SEG_UK_MSG_HEAD_H
#define URMA_SEG_UK_MSG_HEAD_H

#include "svm_pub.h"

struct svm_urma_seg_msg_head {
    u64 va;
    u64 size;
    u32 flag;
    u32 token_id;
};

#endif
