/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_TOOL_CFG_H
#define HCCN_TOOL_CFG_H

#define CFGFILE_NAME    "/etc/hccn.conf"

#ifndef CONFIG_LLT
#define STATIC static
#else
#define STATIC
#endif

#define CONLINE_LENGTH  384
#define CONFILE_LENGTH  (1024 * 1000)
#define FILE_RELEASE_RET_VALUE_NUM          4

int cfg_read_conf(int phy_id, const char *conf_name, char *conf_value, unsigned int len);
int cfg_write_conf(int phy_id, const char *conf_name, const char *conf_value);
int cfg_del_conf(int phy_id, const char *conf_name);
int cfg_inner_del_conf_byfd(FILE *fp, const char *conf_name);
#endif

