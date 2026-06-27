/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef MEM_SHOW_UK_MSG_H
#define MEM_SHOW_UK_MSG_H

#include "svm_pub.h"

#define FEARURE_NAME_LEN 32

#define USER_FEATURE_SHOW_NUM 5
#define USER_FEATURE_MALLOC_MNG "user_malloc_mng"
#define USER_FEATURE_CACHE_MALLOC "user_cache_malloc"
#define USER_FEATURE_PREFETCH "user_prefetch"
#define USER_FEATURE_REGISTER "user_register"
#define USER_FEATURE_MEM_STAT "user_mem_stat"

#define SVM_SHOW_SCOPE_DEV 0
#define SVM_SHOW_SCOPE_ALL 1

/* SVM_MEM_SHOW_EVENT */
struct svm_mem_show_msg {
    char feature_name[FEARURE_NAME_LEN];
    u32 type; /* 0: single dev, 1: all dev */
};

struct svm_mem_show_buf_head {
    int valid; /* kernel set invalid before send msg, user set valid when fill data finish */
    char data[0];
};

#define SVM_MEM_SHOW_BUF_LEN 4096U
#define SVM_MEM_SHOW_BUF_DATA_LEN (SVM_MEM_SHOW_BUF_LEN - sizeof(struct svm_mem_show_buf_head))

#endif
