/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef ORION_RDFX_TLS_H
#define ORION_RDFX_TLS_H

// #include "rdfx_comm.h"
#include "tls.h"
#include "tls_common.h"

#define RDFX_CHIP_ID_MAX   4

#define MAX_RESULT_CYCLE    3

#define MAX_PKT_NUM 128

struct rdfx_pkt {
    unsigned int    chip_id;
    unsigned int    use;
    unsigned int    result;
    unsigned short    seq;
    unsigned int    finish;
    struct timeval  start;
    struct timeval  end;
};

enum rdfx_thread_status {
    RDFX_THREAD_INIT  = 0,
    RDFX_THREAD_RUNNING   = 1,
    RDFX_THREAD_DEINIT    = 2,
    RDFX_THREAD_INIT_ERR = 3,
    RDFX_THREAD_REINIT_ERR   = 4,
};

struct rdfx_op_sec {
    struct timeval t_last;
    unsigned long long token_num;
};

struct rdxf_buf_info {
    char *buff;
    unsigned int offset;
    pid_t host_tid;
    unsigned int buff_len;
    pid_t pid;
};

struct rdfx_cb {
    unsigned int chip_id;
    int sockfd;
    int thread_status;
    unsigned int dip;
    unsigned short seq;

    struct rdfx_op_sec op_sec;

    struct timeval last_time;
    struct timeval last_heart_time;
    struct timeval last_cert_check_time;

    uint64_t last_heart_cycles;

    pthread_mutex_t detect_lock;
    pthread_mutex_t heart_lock;
    pthread_mutex_t cfg_lock;

    struct rdfx_pkt pkt[MAX_PKT_NUM];
    struct rdxf_buf_info recv_cfg;
    struct rdxf_buf_info send_cfg;

    int tmp_res[MAX_RESULT_CYCLE];
    int tmp_seq[MAX_RESULT_CYCLE];
    /*
    0:reach
    1:unreach
    */
    int result;
    pthread_t tid;
};

#define MAX_SEED_BYTES_LEN 48
#define MAX_CMD_LEN        128
#define MAX_BUF_LEN        128

#ifndef CONFIG_LLT
#define MAX_READ_CNT       1000
#else
#define MAX_READ_CNT       1
#endif

#define RDFX_TIME_LEN 32

#define RDFX_TLS_ALARM_MAX_DAYS  180
#define RDFX_TLS_ALARM_MIN_DAYS  7

#define TLS_CHECK_MAGIC_WORD (2 << 0)
#define TLS_CHECK_ENABLE (2 << 1)
#define TLS_CHECK_ALARM (2 << 2)

#define MS_PER_SECOND   1000.0
#define MS_PER_SECOND_I 1000

extern TLS_ATTRI_VISI_DEF struct rdfx_cb g_rdfx_cb[RDFX_CHIP_ID_MAX];

TLS_ATTRI_VISI_DEF X509 *tls_load_cert(const uint8_t *inbuf, uint32_t buf_len, int type);
TLS_ATTRI_VISI_DEF EVP_PKEY *tls_load_ky(const uint8_t *inbuf, uint32_t buf_len, int ky_type,char *pwd);
TLS_ATTRI_VISI_DEF int rdfx_set_tls_enable(int chip_id, const char *inbuf, unsigned int size_in,
    char *outbuf, unsigned int *size_out);
TLS_ATTRI_VISI_DEF int rdfx_set_tls_alarm(int chip_id, const char *inbuf, unsigned int size_in,
    char *outbuf, unsigned int *size_out);
TLS_ATTRI_VISI_DEF int rdfx_get_tls_cfg(int chip_id, const char *inbuf, unsigned int size_in,
    char *outbuf, unsigned int *size_out);
TLS_ATTRI_VISI_DEF int rdfx_set_tls_cfg(int chip_id, const char *inbuf, unsigned int size_in,
    char *outbuf, unsigned int *size_out);
TLS_ATTRI_VISI_DEF int rdfx_clear_tls_cfg(int chip_id, const char *inbuf, unsigned int size_in,
    char *outbuf, unsigned int *size_out);
TLS_ATTRI_VISI_DEF int rdfx_get_cert_show_info(unsigned int chip_id, X509 *cert,
    struct tls_cert_show_info *show_info);

TLS_ATTRI_VISI_DEF void rdfx_detect_cert_time(int chip_id);
TLS_ATTRI_VISI_DEF void rdfx_auto_detect_cert(int chip_id);
TLS_ATTRI_VISI_DEF int rdfx_get_digital_envelope_pub(int chip_id, const char *inbuf,
    unsigned int size_in, char *outbuf, unsigned int *size_out);

#endif // ORION_RDFX_TLS_H
