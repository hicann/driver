/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_COMMON_BASE_H__
#define __NPU_COMMON_BASE_H__

#include "npu_smi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

int parse_npu_info_param(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int parse_npu_set_param(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int parse_npu_upgrade_param(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int parse_npu_clear_param(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int set_type(struct npu_smi_operate_info *operate_info, const char *tmp_type);
int set_watch_type(struct npu_smi_operate_info *operate_info, const char *tmp_type);
int set_qos_cfg_para_parse(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);
int type_support_in_vm_or_docker(int argc, char **argv);
int type_unsupport_set_in_common_docker(int argc, char **argv);
int type_unsupport_info_in_common_docker(int argc, char **argv);
int type_is_info_vnpu(int argc, char **argv);
int type_need_check_root(int argc, char **argv);
int check_support_set_h_cmd_in_vm_or_docker(int argc, char **argv);
int check_support_set_t_cmd_in_vm_or_docker(int argc, char **argv);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif          /* __NPU_COMMON_BASE_H__ */