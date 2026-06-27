/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef PROF_ADAPT_USER_H
#define PROF_ADAPT_USER_H
#include <semaphore.h>
#include "ascend_inpackage_hal.h"
#include "prof_adapt.h"
#include "pbl_prof_interface_cmd.h"
#include "prof_common.h"

enum prof_sample_status {
    PROF_SAMPLE_NORMAL,
    PROF_SAMPLE_FLUSH_START,
    PROF_SAMPLE_FLUSH_STARTING,
    PROF_SAMPLE_FLUSH_FINISH
};

enum prof_host_samole_phease {
    PROF_HOST_SAMPLE_PHEASE_DEFAULT,
    PROF_HOST_SAMPLE_PHEASE1,
    PROF_HOST_SAMPLE_PHEASE2,
    PROF_HOST_SAMPLE_PHEASE_MAX
};

struct prof_user_chan_priv {
    uint32_t dev_id;
    uint32_t chan_id;

    uint32_t sample_mode;
    uint32_t sample_thread_flag;
    pthread_t sample_thread;
    timer_t timer_fd;
    sem_t *sem;
    struct prof_sample_ops ops;

    uint8_t *buff;
    uint32_t sample_buff_size;
    bool support_host_sample;
    enum prof_sample_status sample_status;
};

enum prof_user_sample_type {
    PROF_SAMPLE_LOCAL_MODE,
    PROF_SAMPLE_REMOTER_MODE
};

drvError_t prof_user_register_channel(uint32_t dev_id, uint32_t chan_id, struct prof_sample_register_para *para, bool support_host_sample);
drvError_t prof_user_get_chan_ops(struct prof_chan_ops **ops);
drvError_t prof_user_get_host_sample_chan_ops(struct prof_chan_ops **ops);
drvError_t prof_user_sample_start_check(struct prof_user_chan_priv *chan_priv,
    struct prof_user_start_para *para);
drvError_t prof_user_sample_timer_init(struct prof_user_chan_priv *chan_priv, uint32_t sample_period);
drvError_t prof_user_sample_thread_enable(struct prof_user_chan_priv *chan_priv);
void prof_user_sample_thread_disable(struct prof_user_chan_priv *chan_priv);
drvError_t prof_user_chan_get(uint32_t dev_id, uint32_t chan_id, struct prof_user_chan_priv *chan_priv, sem_t **sem, bool support_host_sample);
void prof_user_chan_uninit(char **priv);
drvError_t prof_user_sample_pre_start(struct prof_user_chan_priv *chan_priv, struct prof_user_start_para *para);
drvError_t prof_user_sample_start(struct prof_user_chan_priv *chan_priv, struct prof_user_start_para *para,
    struct prof_start_event_out_msg *outdata, bool support_host_sample);
void prof_user_sample_stop(struct prof_user_chan_priv *chan_priv, uint32_t release_flag);
void prof_user_sample_timer_uninit(struct prof_user_chan_priv *chan_priv);
drvError_t prof_user_chan_stop(uint32_t dev_id, uint32_t chan_id, struct prof_user_stop_para *para,
    char *priv);
int prof_user_chan_read(uint32_t dev_id, uint32_t chan_id, prof_user_read_para_t *read_para, char *priv);
drvError_t prof_user_chan_report(uint32_t dev_id, uint32_t chan_id, void *data, uint32_t data_len, char *priv);

struct prof_user_kernel_ops {
    drvError_t (*chan_register)(uint32_t dev_id, uint32_t chan_id);
    drvError_t (*chan_query)(uint32_t dev_id, uint32_t chan_id, uint32_t *avail_len);
    drvError_t (*chan_writer)(uint32_t dev_id, uint32_t chan_id, void *data, uint32_t data_len);
};

void prof_user_regiser_kernel_ops(struct prof_user_kernel_ops *ops);

#endif