/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef SMM_FLAG_H
#define SMM_FLAG_H

#define SVM_SMM_FLAG_PG_NC                      (1U << 0U)
#define SVM_SMM_FLAG_PG_RDONLY                  (1U << 1U)
#define SVM_SMM_FLAG_MAP_UB_ONE_PORT_PATH       (1U << 2U)
#define SVM_SMM_FLAG_MAP_UB_MULTI_PORT_PATH     (1U << 3U)

#define SVM_SMM_FLAG_SRC_INVALID                (1U << 8U)
#define SVM_SMM_FLAG_SRC_NON_SVM_VA             (1U << 9U)

static inline int svm_smm_get_src_valid_flag(u32 flag) { return ((flag & SVM_SMM_FLAG_SRC_INVALID) != 0) ? 0 : 1; }

static inline int svm_smm_get_src_svm_va_flag(u32 flag) { return ((flag & SVM_SMM_FLAG_SRC_NON_SVM_VA) != 0) ? 0 : 1; }

#endif
