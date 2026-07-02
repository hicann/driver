/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SVM_URMA_SEG_FLAG_H
#define SVM_URMA_SEG_FLAG_H

#include "svm_pub.h"

#define SVM_URMA_SEG_FLAG_ACCESS_WRITE (1U << 0U)
#define SVM_URMA_SEG_FLAG_PIN (1U << 1U)
#define SVM_URMA_SEG_FLAG_SELF_USER (1U << 2U)

static inline bool svm_urma_seg_flag_is_access_write(u32 seg_flag)
{
    return ((seg_flag & SVM_URMA_SEG_FLAG_ACCESS_WRITE) != 0);
}

static inline bool svm_urma_seg_flag_is_pin(u32 seg_flag)
{
    return ((seg_flag & SVM_URMA_SEG_FLAG_PIN) != 0);
}

static inline bool svm_urma_seg_flag_is_self_user(u32 seg_flag)
{
    return ((seg_flag & SVM_URMA_SEG_FLAG_SELF_USER) != 0);
}

#endif
