/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef DMA_MAP_FLAG_H
#define DMA_MAP_FLAG_H

#include "svm_pub.h"

#define SVM_DMA_MAP_ACCESS_WRITE (1u << 0u)
#define SVM_DMA_MAP_VA_IO_MAP (1u << 1u)

static inline bool svm_dma_map_flag_is_access_write(u32 flag)
{
    return ((flag & SVM_DMA_MAP_ACCESS_WRITE) != 0);
}

static inline bool svm_dma_map_flag_is_va_io_map(u32 flag)
{
    return ((flag & SVM_DMA_MAP_VA_IO_MAP) != 0);
}

#endif
