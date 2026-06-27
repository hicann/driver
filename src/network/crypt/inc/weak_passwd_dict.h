/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _WEAK_PASSWD_DICT_H_
#define _WEAK_PASSWD_DICT_H_

#define ROOT_CONFIG_WEAK_DICT "/etc/hccn_weak_dict.conf"
#define WEAK_PWD_MAX_LEN 1024
#define WEAK_PWD_MAX_NUMS 10000
#define WEAK_PWD_PATH_LEN 64
#define WEAK_PWD_FILE_MAX_LEN (WEAK_PWD_MAX_LEN * WEAK_PWD_MAX_NUMS)
#define CRYPT_ATTRI_VISI_DEF __attribute__ ((visibility ("default")))

CRYPT_ATTRI_VISI_DEF int crypto_check_weak_pwd(const char *pwd, int pwd_len);
#endif