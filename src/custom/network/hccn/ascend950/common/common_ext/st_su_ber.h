/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef ST_SU_BER_H
#define ST_SU_BER_H

#define ARRAY_SIZE_COMPUTE(_array) (sizeof((_array)) / sizeof((_array)[0]))
#define MAX_LANE_NUMBER_PER_PORT    4 // 一个nl_id 8条lane，偶数macro_id前4条，奇数macro_id后4条

enum cfg_su_itlv_mode_e {
    SU_BER_ITLV_MODE_NON_ITLV = 0,  /* 0:按非交织 统计SU误码 */
    SU_BER_ITLV_MODE_ITLV,          /* 1:按2CW交织统计SU误码 */
};

struct su_ber_frm_cnt_err_info {
    unsigned int frm_bit;
    unsigned int reserved;
    unsigned int done_status[MAX_LANE_NUMBER_PER_PORT];         /* SU统计结束标记及异常 */
    unsigned int bit_err_cnt[MAX_LANE_NUMBER_PER_PORT];         /* SU统计错误bit数 */
    unsigned int frm_cnt[MAX_LANE_NUMBER_PER_PORT];             /* SU统计FRAME数 */
    unsigned int err_symb_t4[MAX_LANE_NUMBER_PER_PORT];         /* SU统计错误超过4个symbol的帧数 */
};
 
struct su_ber_cnt_info {
    unsigned int su_itlv_mode;
    unsigned int su_ber_status;
};

enum su_ber_mode_e {
    SU_BER_MODE_STOP,
    SU_BER_MODE_RX_ENABLE,
    SU_BER_MODE_TX_ENABLE,
    SU_BER_MODE_GET_RESULT,
    SU_BER_MODE_STATUS,
    SU_BER_MODE_CLEAR,
};

struct su_ber_data_t {
    enum su_ber_mode_e mode;
    unsigned int macro_id;
    unsigned int cmd;
};

#endif /* ST_SU_BER_H */
