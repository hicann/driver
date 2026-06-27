/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef PAGEFAULT_UK_MSG_H
#define PAGEFAULT_UK_MSG_H

#include "svm_pub.h"

/* SVM_PAGEFAULT_EVENT */
struct svm_pagefault_msg {
    u64 va;
    u32 sn;
    u32 magic;
    int result;
};

#endif