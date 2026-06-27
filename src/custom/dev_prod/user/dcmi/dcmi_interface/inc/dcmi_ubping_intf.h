/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __DCMI_UBPING_INTF_H__
#define __DCMI_UBPING_INTF_H__

#include "dcmi_interface_api.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/* 参数范围定义 */
#define UBPING_MESH_MAX_PKT_NUM     1000   /* 最大ping报文发送轮数 */
#define UBPING_MESH_MIN_PKT_NUM     1      /* 最小ping报文发送轮数 */
#define UBPING_MESH_MAX_PKT_SIZE    4046  /* 最大ping报文大小 */
#define UBPING_MESH_MAX_INTERVAL    1000   /* 最大报文间隔ms */
#define UBPING_MESH_MAX_TASK_INTERVAL 60   /* 最大任务轮询间隔s */
#define UBPING_MESH_MIN_TASK_INTERVAL 1    /* 最小任务轮询间隔s */

/* ubping mesh 常量定义 */
#define DCMI_UBPING_MESH_MAX_NUM     48   /* 最大EID对数量 */

struct ubping_mesh_operate {
    struct ubping_pair_info ub_pair_info[DCMI_UBPING_MESH_MAX_NUM];
    int pair_num;
    int pkt_size;
    int pkt_send_num;
    int pkt_interval;
    int task_interval;
    unsigned int reserved[UB_PING_RESERVE_NUM];
};

struct ubping_mesh_result {
    struct ubping_pair_info ub_pair_info;
    long max_time;     // ping最大时延
    long min_time;     // ping最小时延
    long avg_time;     // ping平均时延
    long tp95_time;     // ping时延TP95分位数
    unsigned int suc_pkt_num;  // ping成功次数
    unsigned int fail_pkt_num;  // ping失败次数
    int reply_stat_num;    // 统计结果所用样本轮数
};

struct ubping_mesh_info {
    int result_num;
    struct ubping_mesh_result ub_ping_result[DCMI_UBPING_MESH_MAX_NUM];
};

int dsmi_get_device_ub_ping_info(int device_id, struct dcmi_ub_ping_operate *ping_args,
    struct ub_ping_result* ping_result);
int dsmi_start_ubping_mesh_proc(int device_id, struct ubping_mesh_operate *operate);
int dsmi_stop_ubping_mesh_proc(int device_id);
int dsmi_get_ubping_mesh_info_proc(int device_id, struct ubping_mesh_info *result_info);
int dsmi_get_ubping_mesh_state_proc(int device_id, unsigned int *stat);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
 
#endif /* __DCMI_UBPING_INTF_H__ */