/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <unistd.h>
#include <sys/stat.h>
#include <termios.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <regex.h>
#include <errno.h>
#include "dms_devdrv_info_comm.h" // hisi_trunk_ai, drvGetHostPhyMachFlag需要
#include "tool.h"
#include "cmd.h"
#include "cfg.h"
#include "dsmi_common_interface.h"
#include "log.h"
#include "tool_ops.h"
#include "weak_passwd_dict.h"
#include "rdfx_tls.h"
#include "rdfx_tls_interface.h"
#include "encrypt.h"
#include "file_opt.h"
#include "network_comm.h"
#include "ds_net.h"
#include "hccn_comm.h"
#include "tool_tls.h"

#define CALLOC_BLOCK_NUM 1
#define TLS_CA_ALIAS_FORMAT "^[a-zA-Z0-9_-]{1,63}$"
#define CA_CERT_PATH "/driver/cert/ca/"
#define NUMBER_BASE (10)

STATIC int tool_get_cert_type(unsigned int index, char *type, unsigned int len)
{
    int ret;

    if (index == TLS_PUB_CERT) {
        ret = snprintf_s(type, len, len - 1, "pub cert");
        if (ret <= 0) {
            roce_err("snprintf_s for pub cert fail, ret:%d, index:%u", ret, index);
            return UDA_TOOL_NO_MEM_ERR;
        }
    } else if ((index >= TLS_CA1_CERT) && (index <= TLS_CA14_CERT)) {
        ret = snprintf_s(type, len, len - 1, "ca%u cert", index);
        if (ret <= 0) {
            roce_err("snprintf_s for ca cert fail, ret:%d, index:%u", ret, index);
            return UDA_TOOL_NO_MEM_ERR;
        }
    } else {
        ret = snprintf_s(type, len, len - 1, "crl");
        if (ret <= 0) {
            roce_err("snprintf_s for crl fail, ret:%d, index:%u", ret, index);
            return UDA_TOOL_NO_MEM_ERR;
        }
    }

    return 0;
}

STATIC int tool_get_cert_time(unsigned int index, struct tls_cert_show_info *show_info, time_t *cert_end_time,
                              time_t *now)
{
    char *p = NULL;
    struct tm tm = {0};
    struct tm tm_now = {0};
    struct tm *tmp = NULL;
    char time_now[TOOL_TIME_LEN] = {0};

    p = strptime(show_info[index].end_time, "%a %b%d%H:%M:%S%Y", &tm);
    if (p == NULL) {
        roce_err("string to time failed, index:%u, end_time:%s", index, show_info[index].end_time);
        return UDA_TOOL_SYS_TIME_OP_ERR;
    }
    *cert_end_time = mktime(&tm);
    (void)time(now);
    tmp = gmtime_r(now, &tm_now);
    if (tmp == NULL) {
        roce_err("gmtime_r failed, now:%ld", now);
        return UDA_TOOL_SYS_TIME_OP_ERR;
    }
    *now = mktime(&tm_now);
    p = ctime_r(now, time_now);
    if (p == NULL) {
        roce_err("ctime_r failed, now:%ld", *now);
        return UDA_TOOL_SYS_TIME_OP_ERR;
    }
    return 0;
}

STATIC int tool_check_cert_expired(struct tool_param *param, struct tls_cert_show_info *show_info, unsigned int index)
{
    int ret;
    char type[TLS_TYPE_LEN] = {0};
    time_t cert_end_time;
    time_t now;

    ret = tool_get_cert_type(index, type, TLS_TYPE_LEN);
    if (ret) {
        roce_err("Get cert type fail. (ret=%d; index=%u)", ret, index);
        return ret;
    }
#ifdef CFG_SOC_PLATFORM_CLOUD
    TOOL_PRINT_INFO("dev_id:%d, [%s] info:\n\t issuer[%s]\n\t start_time[%s GMT]\n\t end_time[%s GMT]",
        param->phy_id, type, show_info[index].issuer, show_info[index].start_time, show_info[index].end_time);
#else
    TOOL_PRINT_INFO("dev_id:%d, [%s] info:\n\t subject[%s]\n\t issuer[%s]\n\t start_time[%s GMT]\n\t end_time[%s GMT]",
        param->phy_id, type, show_info[index].subject, show_info[index].issuer, show_info[index].start_time,
        show_info[index].end_time);
#endif
    ret = tool_get_cert_time(index, show_info, &cert_end_time, &now);
    if (ret) {
        roce_err("Tool get cert time fail! ret:%d, logic_id:%d", ret, param->logic_id);
        return ret;
    }
    if (cert_end_time - now <= 0) {
        TOOL_PRINT_ERR("\t tls expiration status[2](0:normal, 1:near expiration, 2:has expired)");
        return UDA_TOOL_SYS_CERT_EXPRD_ERR;
    }
    roce_info("logic_id[%d] show_info[%d].tls_alarm:%u", param->logic_id, index, show_info[index].tls_alarm);
    if ((unsigned int)(cert_end_time - now) <= (show_info[index].tls_alarm * TLS_DAY_TO_S)) {
        TOOL_PRINT_INFO("\t tls expiration status[1](0:normal, 1:near expiration, 2:has expired)");
    } else {
        TOOL_PRINT_INFO("\t tls expiration status[0](0:normal, 1:near expiration, 2:has expired)");
    }
    return 0;
}

STATIC unsigned int tool_tls_cert_is_preconfig(struct tls_cert_show_info show_info[], unsigned int num)
{
    unsigned int preconfig = 0;
    unsigned int i;

    for (i = 0; i < num; i++) {
        if (!strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei IT Product CA",
            strlen(show_info[i].issuer) + 1) ||
            !strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei Equipment CA",
            strlen(show_info[i].issuer) + 1) ||
            !strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei Computing RSA-PSS Equipment CA 1",
            strlen(show_info[i].issuer) + 1) ||
            !strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei Computing RSA-PSS Equipment CA 2",
            strlen(show_info[i].issuer) + 1) ||
            !strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei RSA-PSS Equipment Root CA 1",
            strlen(show_info[i].issuer) + 1) ||
            !strncmp(show_info[i].issuer, "/C=CN/O=Huawei/CN=Huawei RSA Equipment Root CA 2",
            strlen(show_info[i].issuer) + 1)) {
                preconfig = 1;
                break;
        }
    }
    return preconfig;
}

STATIC int tool_show_tls_cert_info(struct tool_param *param, struct tls_cert_show_info show_info[], unsigned int num)
{
    unsigned int i;
    unsigned int preconfig;
    int ret;

    DSMI_CHECK_PTR_VALID_RETURN_VAL(show_info, UDA_TOOL_INNER_PARAM_ERR);

    preconfig = tool_tls_cert_is_preconfig(show_info, num);
    
    TOOL_PRINT_INFO("dev_id:%d, tls switch[%u](0:disable, 1:enable), tls preconfigured[%u](0:non-preset, 1:preset),"
        " tls alarm time threshold[%u]days", param->phy_id, show_info[0].tls_enable, preconfig, show_info[0].tls_alarm);

    for (i = 0; i < num; i++) {
        if ((i < num) &&  (strlen(show_info[i].issuer) > 0)) {
            ret = tool_check_cert_expired(param, show_info, i);
            if (ret && (ret != UDA_TOOL_SYS_CERT_EXPRD_ERR)) {
                roce_err("tool_check_cert_expired failed, ret:%d,i:%u, logic_id:%d", ret, i, param->logic_id);
                return ret;
            }
        }
    }
    return 0;
}

STATIC int tool_save_tls_enable_cfg(const struct tool_param *param, unsigned int tls_enable, bool save_first_time)
{
    char enable_cfg[MAX_TLS_LEN] = {'\0'};
    int ret;

    ret = cfg_read_conf(param->phy_id, "tls_enable", enable_cfg, sizeof(enable_cfg));
    // only save tls_enable for the first time
    if (save_first_time && ret != UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        return 0;
    }

    ret = sprintf_s(enable_cfg, MAX_TLS_LEN, "%u", tls_enable);
    if (ret <= 0) {
        roce_warn("Sprintf_s tls_enable info unsuccessful. (ret=%d; phy_id=%d)", ret, param->phy_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = cfg_write_conf(param->phy_id, "tls_enable", enable_cfg);
    if (ret) {
        roce_warn("Cfg_write_conf tls_enable unsuccessful. (ret=%d; phy_id=%d)", ret, param->phy_id);
        return ret;
    }
    return 0;
}

STATIC int tool_get_tls_cfg(int argc, char **argv, const struct tool_param *param)
{
    struct tls_cert_show_info show_info[MAX_SHOW_INFO_COUNT];
    unsigned int save_mode = TLS_SAVE_TO_FlASH;
    unsigned int size_out;
    int ret;

    if (argc == 0 || argc > TLS_HOST_ARGC_NUM) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (argc == TLS_HOST_ARGC_NUM) {
        if (strncmp(argv[argc - 1], "host", strlen("host") + 1) != 0) {
            roce_err("invalid option");
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
        save_mode = TLS_SAVE_TO_FILE;
        size_out = sizeof(struct tls_cert_show_info) * MAX_SHOW_INFO_COUNT;
        ret = rdfx_get_tls_cfg(param->logic_id, (const char *)&save_mode, sizeof(save_mode),
            (char *)show_info, &size_out);
    } else {
        ret = dsmi_get_tls_cfg(param->logic_id, 0, show_info, MAX_SHOW_INFO_COUNT);
    }

    if (ret == (-ENOENT)) {
        roce_warn("logic_id[%d] has no certs, please set certs firstly", param->logic_id);
        return UDA_PARAM_TLS_NO_CERT_ERR;
    }

    if (ret) {
        roce_err("get tls cfg fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    // save tls_enable to conf for the first time, ignore failure
    if (save_mode == TLS_SAVE_TO_FlASH) {
        ret = tool_save_tls_enable_cfg(param, show_info[0].tls_enable, true);
        if (ret != 0) {
            roce_warn("Tool save tls_enable cfg unsuccessful. (logic_id=%d; ret=%d)", param->logic_id, ret);
        }
    }

    ret = tool_show_tls_cert_info(param, show_info, MAX_SHOW_INFO_COUNT);
    if (ret) {
        roce_err("Dsmi show tls cert info fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    return 0;
}

int tool_check_tls_param(const char *input, const char *expect)
{
    char crl[] = "crl";
    char ca[] = "ca";
    char host[] = "host";

    if (strncmp(input, expect, strlen(expect) + 1) == 0) {
        roce_info("check [%s] ok", expect);
        return 0;
    }

    roce_info("input[%s], strlen(input):%d", expect, strlen(input));

    if (strncmp(input, crl, strlen(crl) + 1) == 0) {
        roce_info("input is crl");
        return TLS_CRL_FLAG;
    }

    if ((strncmp(input, ca, strlen(ca)) == 0)) {
        roce_info("input is ca");
        return TLS_CA_FLAG;
    }

    if ((strncmp(input, host, strlen(host) + 1) == 0)) {
        roce_info("input is host");
        return TLS_HOST_FLAG;
    }

    return UDA_PARAM_INVALID_ERR;
}

STATIC int tool_read_file_check_size(int type, const int len, bool host_flag)
{
    int ret = 0;
    int cert_len = (host_flag == true) ? OLD_CERT_MAX_SIZE : CERT_MAX_SIZE;

    if ((type == TLS_CRL) && (len > CRL_MAX_SIZE)) {
        roce_err("crl size[%d] is bigger than [%d], invalid", len, CRL_MAX_SIZE);
        ret = -EFBIG;
        return UDA_PARAM_TLS_CERT_LEN_INVALID_ERR;
    }

    if ((type == TLS_PRI_KY) && (len > KY_MAX_SIZE)) {
        roce_err("ky size[%d] is bigger than [%d], invalid", len, KY_MAX_SIZE);
        ret = -EFBIG;
        return UDA_PARAM_TLS_CERT_LEN_INVALID_ERR;
    }

    if ((type >= TLS_PUB_CERT) && (type <= TLS_CA14_CERT) && (len > cert_len)) {
        roce_err("cert type[%d] size[%d] is bigger than [%d], invalid", type, len, cert_len);
        ret = -EFBIG;
        return UDA_PARAM_TLS_CERT_LEN_INVALID_ERR;
    }

    return ret;
}

STATIC int tool_read_file(const char *path, char *content, int *len, int type, bool host_flag)
{
    int ret, ret_val;
    FILE *file = NULL;
    size_t btyes_read;
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813

    if ((strlen(path) > PATH_MAX) || (realpath(path, real_conf_path) == NULL)) {
        roce_err("path_len[%u] > [%d](PATH_MAX) or conf_path is invalid, err[%d]", strlen(path), PATH_MAX, errno);
        return UDA_PARAM_PATH_INVALID_ERR;
    }

    file = fopen(real_conf_path, "r");
    if (file == NULL) {
        roce_err("file is NULL, invalid");
        return UDA_TOOL_SYS_READ_FILE_ERR;
    }
    ret = fseek(file, 0, SEEK_END);
    if (ret < 0) {
        roce_err("fseek failed with error:%d", errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }

    *len = ftell(file);
    if (*len <= 0) {
        roce_err("ftell failed with error:%d", errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }

    ret = tool_read_file_check_size(type, *len, host_flag);
    if (ret) {
        roce_err("check size err, %d", ret);
        goto out;
    }

    rewind(file);
    btyes_read = fread((void *)content, *len, 1, file); /* read a buf which size is *len */
    if (btyes_read != 1) {
        roce_err("fread failed ret:%zu, error:%d, ferror(fp):%d", btyes_read, errno, ferror(file));
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }
    ret = 0;
    content[*len] = '\0';
out:
    ret_val = fclose(file);
    if (ret_val) {
        roce_warn("Fclose fail. (ret_val=%d; errno=%d)", ret_val, errno);
    }
    file = NULL;
    return ret;
}

STATIC void tool_filter_str(char *str, unsigned int *len, char filter)
{
    int idx;

    for (idx = *len - 1; idx >= 0; idx--) {
        if (str[idx] == filter) {
            str[idx] = '\0';
            break;
        }
    }

    *len = strlen(str);
}

void weak_pwd_check_ret_print(int ret)
{
    switch (ret) {
        case UDA_PARAM_TLS_NO_WEAK_PWD_DICT:
            TOOL_PRINT_INFO("You have not configed a weak password dictionary, please config to ensure safer");
            break;
        case UDA_PARAM_TLS_WEAK_PWD_DICT_TOO_MANY:
            TOOL_PRINT_ERR("You config the weak passwords exceed 10000 entries, invalid!");
            break;
        case UDA_PARAM_TLS_WEAK_PWD_DICT_NULL:
            TOOL_PRINT_INFO("There is nothing in weak password dictionary, please config to ensure safer");
            break;
        case UDA_PARAM_TLS_PWD_TOO_WEAK_ERR:
            TOOL_PRINT_ERR("The password you input is too weak, please choose another one!");
            break;
        default:
            break;
    }
}

STATIC bool is_special_char(char c)
{
    unsigned int i;
    char special_chars[] = "`~!@#$%^&*()-_=+\\|[{}];:'"",<.>/? ";

    for (i = 0; i < strlen(special_chars); i++) {
        if (c == special_chars[i]) {
            return true;
        }
    }

    return false;
}

STATIC int tool_check_pwd_complexity(const char *pwd, unsigned int len)
{
    unsigned int i;
    int type[PWD_TPYE_CNT] = {0};
    int type_cnt = 0;

    for (i = 0; i < len; i++) {
        if (pwd[i] >= '0' && pwd[i] <= '9') {
            type[PWD_NUM_INDEX] = 1;
        } else if (pwd[i] >= 'a' && pwd[i] <= 'z') {
            type[PWD_LOW_LET_INDEX] = 1;
        } else if (pwd[i] >= 'A' && pwd[i] <= 'Z') {
            type[PWD_UP_LET_INDEX] = 1;
        } else if (is_special_char(pwd[i])) {
            type[PWD_SYMBOL_INDEX] = 1;
        } else {
            roce_err("invalid char[%c]", pwd[i]);
            return -EINVAL;
        }
    }

    for (i = 0; i < PWD_TPYE_CNT; i++) {
        type_cnt += type[i];
    }

    if (type_cnt < PWD_COMPLEXITY_THR) {
        roce_err("type_cnt[%u] < [%u], the complexity of pwd is too low", type_cnt, PWD_COMPLEXITY_THR);
        return UDA_PARAM_TLS_PWD_COMPLEXITY_ERR;
    }

    return 0;
}

STATIC int tool_check_pwd(char *pwd, unsigned int *len)
{
    int ret;

    tool_filter_str(pwd, len, '\n');
    if (*len < PWD_MIN_LEN || *len > PWD_MAX_LEN) {
        roce_err("len[%u] is invalid, must between [%d] and [%d]", *len, PWD_MIN_LEN, PWD_MAX_LEN);
        return UDA_PARAM_TLS_PWD_LEN_INVALID_ERR;
    }

    ret = tool_check_pwd_complexity(pwd, *len);
    if (ret) {
        roce_err("tool_check_pwd_complexity failed, ret:0x%x", ret);
        return ret;
    }

    ret = crypto_check_weak_pwd(pwd, *len);
    weak_pwd_check_ret_print(ret);
    if (ret && ret != UDA_PARAM_TLS_NO_WEAK_PWD_DICT && ret != UDA_PARAM_TLS_WEAK_PWD_DICT_NULL) {
        roce_err("crypto_check_weak_pwd failed, ret:0x%x", ret);
        return UDA_PARAM_TLS_WEAK_PWD_DICT_CHECK_FAIL;
    }

    return 0;
}

STATIC int tool_get_passwd(char *pwd, unsigned int pwd_len)
{
    int ret;
    struct termios ts = {0};
    struct termios old_ts = {0};
    char *str = NULL;
    int ret_val;

    ret = tcgetattr(STDIN_FILENO, &ts);
    if (ret) {
        roce_err("tcgetattr failed, ret:%d, err_no:%d", ret, errno);
        return UDA_TOOL_SYS_TERMIOS_ERR;
    }

    ret = memcpy_s(&old_ts, sizeof(struct termios), &ts, sizeof(struct termios));
    if (ret) {
        roce_err("memcpy_s for old_ts failed, ret:%d", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ts.c_lflag &= ~ECHO;
    ts.c_lflag |= ECHONL;
    ret = tcsetattr(STDIN_FILENO, TCSAFLUSH, &ts);
    if (ret) {
        roce_err("tcsetattr failed, ret:%d, err_no:%d", ret, errno);
        return UDA_TOOL_SYS_TERMIOS_ERR;
    }

    (void)fprintf(stdout, "Please enter pass phrase for pri key:");
    str = fgets(pwd, pwd_len, stdin);
    if (str == NULL) {
        roce_err("fgets for pwd failed, pwd_len:%u", pwd_len);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = tcsetattr(STDIN_FILENO, TCSANOW, &old_ts);
    if (ret) {
        roce_err("tcsetattr failed, ret:%d, err_no:%d", ret, errno);
        ret_val = memset_s(pwd, pwd_len, 0, pwd_len);
        if (ret_val) {
            roce_err("memset_s for pwd fail,ret:%d", ret_val);
        }
        return UDA_TOOL_SYS_TERMIOS_ERR;
    }

    return 0;
}

STATIC int tool_digital_envelope_enc_data_with_symm_ky(unsigned char *in_buf, unsigned int in_len,
    const unsigned char *symm_ky, struct symmetric_enc_info *enc_info)
{
    int ret;
    crypt_info info = {0};

    ret = RAND_priv_bytes(enc_info->iv, IV_LEN);
    if (ret != 1) {
        roce_err("gen iv err, ret:%d", ret);
        return -EINVAL;
    }

    info.key = symm_ky;
    info.iv = enc_info->iv;
    info.in = in_buf;
    info.in_len = (int)in_len;
    info.tag = enc_info->tag;
    info.tag_len = TAG_LEN;
    info.en_dec = TLS_ENC_MODE;

    ret = crypto_encrypt_with_aes_gcm(&info, enc_info->out_buf, enc_info->out_len);
    if (ret) {
        roce_err("crypto_encrypt_with_aes_gcm failed:%d", ret);
        return ret;
    }

    return 0;
}

STATIC int tool_get_tls_digital_envelope_pub_ky(int logic_id, struct envelope_pub_info *pub_info)
{
    int ret;

    ret = dsmi_get_tls_digital_envelope_pub_ky(logic_id, pub_info);
    if (ret) {
        roce_err("dsmi_get_tls_digital_envelope_pub_ky fail, ret:%d", ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

STATIC int tool_digital_envelope_enc_symm_ky(struct envelope_pub_info *pub_info,
    unsigned char *symm_ky, unsigned int symm_ky_len, unsigned char *symm_enc_ky, unsigned int *symm_enc_ky_len)
{
    int ret;
    EVP_PKEY *pub_ky = NULL;
    RSA *pub_rsa = NULL;
    int enc_len;

    pub_ky = tls_load_ky(pub_info->pub_ky_info, pub_info->pub_ky_len, TLS_PUB_PLAINTEXT, NULL);
    if (pub_ky == NULL) {
        roce_err("tls_load_ky for pub_ky failed");
        return -EINVAL;
    }

    pub_rsa = EVP_PKEY_get1_RSA(pub_ky);
    EVP_PKEY_free(pub_ky);
    pub_ky = NULL;
    if (pub_rsa == NULL) {
        roce_err("pub_rsa is NULL, EVP_PKEY_get1_RSA failed");
        return -EINVAL;
    }

    enc_len = RSA_public_encrypt(symm_ky_len, symm_ky, symm_enc_ky, pub_rsa, RSA_PKCS1_OAEP_PADDING);
    if (enc_len <= 0 || enc_len > (int)*symm_enc_ky_len) {
        roce_err("RSA_public_encrypt failed, enc_len:%d, symm_enc_ky_len:%u", enc_len, *symm_enc_ky_len);
        ret = -EINVAL;
        goto free_rsa;
    }

    *symm_enc_ky_len = enc_len;
    ret = 0;
free_rsa:
    RSA_free(pub_rsa);
    pub_rsa = NULL;
    return ret;
}

STATIC int tool_enc_tls_pwd(unsigned char *pwd, unsigned int pwd_len, struct envelope_pub_info *pub_info,
    struct tls_cert_ky_crl_info *tls_cfg)
{
    int ret, ret_val;
    struct symmetric_enc_info enc_info = {0};
    unsigned char symm_ky[ENVELOPE_SYMM_KY_LEN] = {0};
    unsigned char enc_pwd[PWD_MAX_ENC_LEN + 1] = {0};
    unsigned int enc_pwd_len = sizeof(enc_pwd);

    ret = RAND_priv_bytes(symm_ky, ENVELOPE_SYMM_KY_LEN);
    if (ret != 1) {
        roce_err("gen symm_ky err, ret:%d", ret);
        return -EINVAL;
    }

    enc_info.iv = tls_cfg->mng.envelope_iv;
    enc_info.tag = tls_cfg->mng.envelope_tag;
    enc_info.out_buf = enc_pwd;
    enc_info.out_len = &enc_pwd_len;
    ret = tool_digital_envelope_enc_data_with_symm_ky(pwd, pwd_len, symm_ky, &enc_info);
    if (ret) {
        roce_err("tool_envelope_enc_data_with_symm_ky failed, ret[%d]", ret);
        goto clear_symm_ky;
    }

    ret = memcpy_s(tls_cfg->pwd.pwd_info, sizeof(tls_cfg->pwd.pwd_info), enc_pwd, enc_pwd_len);
    if (ret) {
        roce_err("memcpy_s for pwd fail, ret_val:%d", ret);
        (void)memset_s(enc_pwd, sizeof(enc_pwd), 0, sizeof(enc_pwd));
        goto clear_symm_ky;
    }
    tls_cfg->mng.pwd_enc_len = enc_pwd_len;

    ret = memset_s(enc_pwd, sizeof(enc_pwd), 0, sizeof(enc_pwd));
    if (ret) {
        roce_err("memset_s for enc_pwd fail, ret_val:%d", ret);
        goto clear_symm_ky;
    }

    tls_cfg->symm_enc_ky_info.symm_enc_ky_len = sizeof(tls_cfg->symm_enc_ky_info.symm_enc_ky);
    ret = tool_digital_envelope_enc_symm_ky(pub_info, symm_ky, ENVELOPE_SYMM_KY_LEN,
        tls_cfg->symm_enc_ky_info.symm_enc_ky, &(tls_cfg->symm_enc_ky_info.symm_enc_ky_len));
    if (ret) {
        roce_err("tool_digital_envelope_enc_symm_ky failed, ret[%d]", ret);
    }

clear_symm_ky:
    ret_val = memset_s(symm_ky, ENVELOPE_SYMM_KY_LEN, 0, ENVELOPE_SYMM_KY_LEN);
    if (ret_val) {
        roce_err("memset_s for symm_ky fail, ret_val:%d", ret_val);
        ret = ret_val;
    }
    return ret;
}

STATIC int tool_handle_tls_pwd(unsigned int logic_id, unsigned char *pwd, unsigned int pwd_len,
    struct tls_cert_ky_crl_info *tls_cfg)
{
    int ret;
    struct envelope_pub_info *pub_info = NULL;

    pub_info = calloc(1, sizeof(struct envelope_pub_info));
    if (pub_info == NULL) {
        roce_err("no memory for pub_info");
        return -ENOMEM;
    }
    pub_info->pub_ky_len = sizeof(pub_info->pub_ky_info);

    ret = tool_get_tls_digital_envelope_pub_ky(logic_id, pub_info);
    if (ret) {
        roce_err("tool_get_tls_digital_envelope_pub_ky fail, ret:%d", ret);
        goto out;
    }

    tls_cfg->mng.pwd_len = pwd_len;
    ret = tool_enc_tls_pwd(pwd, pwd_len, pub_info, tls_cfg);
    if (ret) {
        roce_err("tool_enc_tls_pwd fail, ret:%d, logic_id:%u", ret, logic_id);
    }

out:
    free(pub_info);
    return ret;
}

STATIC int tool_get_and_check_tls_pwd(unsigned int logic_id, bool host_flag, struct tls_cert_ky_crl_info *tls_cfg)
{
    int ret, ret_val;
    unsigned int len;
    char pwd[FGETS_MAX_LEN] = {0};

    ret = tool_get_passwd(pwd, sizeof(pwd));
    if (ret) {
        roce_err("memcpy_s for pwd fail, ret:%d", ret);
        return ret;
    }

    len = strlen(pwd);
    ret = tool_check_pwd(pwd, &len);
    if (ret || len > PWD_MAX_LEN) {
        roce_err("tool_check_pwd failed ret:%d or len[%u] > PWD_MAX_LEN[%d]", ret, len, PWD_MAX_LEN);
        goto clear_pwd;
    }
    if (host_flag == false) {
        ret = tool_handle_tls_pwd(logic_id, (unsigned char *)pwd, len, tls_cfg);
        if (ret) {
            roce_err("tool_handle_tls_pwd fail, ret:%d", ret);
            goto clear_pwd;
        }
    } else {
        ret = memcpy_s(tls_cfg->pwd.pwd_info, sizeof(tls_cfg->pwd.pwd_info), pwd, len);
        if (ret) {
            roce_err("memcpy_s for pwd fail, ret:%d", ret);
            ret = UDA_TOOL_NO_MEM_ERR;
            goto clear_pwd;
        }
    }

    tls_cfg->mng.pwd_len = len;

clear_pwd:
    ret_val = memset_s(pwd, sizeof(pwd), 0, sizeof(pwd));
    if (ret_val) {
        roce_err("memset_s for pwd fail, ret:%d", ret_val);
        ret = UDA_TOOL_NO_MEM_ERR;
    }
    return ret;
}

STATIC int tool_get_tls_cfg_from_file(unsigned int logic_id, bool host_flag,
    char cfg_file[][PATH_MAX + 1], unsigned int cfg_file_len, struct tls_cert_ky_crl_info *tls_cfg)
{
    char *temp_cert = NULL;
    unsigned int i;
    int len = 0;
    int ret;

    if ((cfg_file_len >= TLS_PRI_KY) && (strlen(cfg_file[TLS_PRI_KY]) > 0)) {
        ret = tool_read_file((const char*)cfg_file[TLS_PRI_KY], (char*)&(tls_cfg->ky.ky_info), &len,
            TLS_PRI_KY, host_flag);
        if (ret) {
            roce_err("tool_read_file for cfg_file[%d]:[pri key] fail, ret:%d", TLS_PRI_KY, ret);
            return ret;
        }
        tls_cfg->mng.ky_len = (unsigned int)len;
        ret = tool_get_and_check_tls_pwd(logic_id, host_flag, tls_cfg);
        if (ret) {
            roce_err("tool_get_and_check_tls_pwd failed, ret:%d", ret);
            return ret;
        }
    }

    // host侧证书不支持新证书格式
    for (i = TLS_PUB_CERT; i <= TLS_CA14_CERT; i++) {
        if ((i <= cfg_file_len) && (strlen(cfg_file[i]) > 0)) {
            temp_cert = host_flag ? tls_cfg->certs[i].cert_info :
                        tls_cfg->ncerts[i / TLS_CA8_CERT].certs[i % TLS_CA8_CERT].ncert_info;
            ret = tool_read_file((const char*)cfg_file[i], temp_cert, &len, i, host_flag);
            if (ret) {
                roce_err("tool_read_file for cfg_file[%u]:[ca] fail, ret:%d, host_flag:%d.", i, ret, host_flag);
                return ret;
            }
            tls_cfg->mng.cert_len[i] = (unsigned int)len;
            tls_cfg->mng.total_cert_len += (unsigned int)len;
            if (host_flag == false) {
                tls_cfg->ncerts[i / TLS_CA8_CERT].ncert_count++;
            }
        }
    }

    if ((cfg_file_len >= TLS_CRL) && (strlen(cfg_file[TLS_CRL]) > 0)) {
        ret = tool_read_file((const char*)cfg_file[TLS_CRL], (char*)tls_cfg->crl.crl_info, &len, TLS_CRL, host_flag);
        if (ret) {
            roce_err("tool_read_file for cfg_file[%d]:[crl] fail, ret:%d", TLS_CRL, ret);
            return ret;
        }
        tls_cfg->mng.crl_len = (unsigned int)len;
    }

    return 0;
}

STATIC int tool_check_tls_cfg(const unsigned int bit_map[], unsigned int bit_map_len)
{
    int i, j;
    int cnt = 0;
    int required_flags[] = {TLS_PRI_KY, TLS_PUB_CERT, TLS_CA1_CERT, TLS_CA2_CERT};
    unsigned int any_set = 0, all_set = 1;

    for (i = 0; i < ARRAY_SIZE(required_flags); i++) {
        any_set |= bit_map[required_flags[i]];
        all_set &= bit_map[required_flags[i]];
    }

    // A CRL certificate only supports the device-side and does not support the host-side.
    if (bit_map[TLS_CRL] && bit_map[TLS_HOST] && any_set == 0) {
        roce_err("A CRL certificate only supports the device-side and does not support the host-side!");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    if (any_set && !all_set) {
        roce_err("PUB_CERT, PRI_KY, CA1_CERT, CA2_CERT must be set together or not set at all!");
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!bit_map[TLS_PUB_CERT]) {
        for (i = TLS_CA1_CERT; i <= TLS_CA14_CERT; i++) {
            if (bit_map[i]) {
                roce_err("Update CA certificate must after Updating pub certificate!");
                return UDA_PARAM_TLS_CA_WTHOT_PRI_ERR;
            }
        }
        if (i == TLS_CA14_CERT + 1) {
            roce_info("no pub cert and no ca cert.");
            return 0;
        }
    }

    for (i = TLS_CA14_CERT; i >= TLS_CA1_CERT; i--) {
        if (bit_map[i]) {
            for (j = i; j > TLS_CA1_CERT; j--) {
                cnt += bit_map[j] ^ bit_map[j - 1];
            }
            break;
        }
    }
    if (cnt > 1) {
        roce_err("cnt[%d] > 1, certificate chain is not consequent!", cnt);
        return UDA_PARAM_TLS_CERT_DISCONSEQ_ERR;
    }

    return 0;
}

STATIC int tool_pars_tls_cfg_para_once(struct tool_pars_tls_para *para, int *i, const char *expect)
{
    int ret, ret_val;

    (*i)++;
    if (*i >= para->argc) {
        roce_info("all para have parsed");
        return 0;
    }
    if (para->tls_index > para->cfg_file_len) {
        roce_err("tls_index[%u] > cfg_file_len[%u]", para->tls_index, para->cfg_file_len);
        return UDA_PARAM_INVALID_ERR;
    }

    ret = tool_check_tls_param(para->argv[*i], expect);
    if (ret == UDA_PARAM_INVALID_ERR) {
        roce_err("tool_check_tls_param for [%d]_th para err, ret:%d", *i, ret);
        return ret;
    }

    if (ret) {
        roce_info("tool_check_tls_param for [%d]_th para may be a ca or crl, ret:%d", *i, ret);
        return ret;
    }

    (*i)++;
    if (*i >= para->argc || strncmp(para->argv[*i], "host", strlen("host") + 1) == 0) {
        roce_err("has no matched configuration item");
        return UDA_PARAM_INVALID_ERR;
    }

    if (strlen(para->argv[*i]) > NAME_MAX || strlen(para->argv[*i]) == 0) {
        roce_err("file name len[%u] > [%d](NAME_MAX) or is 0", strlen(para->argv[*i]), NAME_MAX);
        return UDA_PARAM_INVALID_ERR;
    }
    ret_val = snprintf_s(para->cfg_file[para->tls_index], PATH_MAX + 1, PATH_MAX, "%s/%s",
        para->real_conf_path, para->argv[*i]);
    if (ret_val <= 0) {
        roce_err("Snprintf fail. (ret=%d)", ret_val);
        return UDA_TOOL_NO_MEM_ERR;
    }
    para->bit_map[para->tls_index] = 1;

    return 0;
}

STATIC int tool_pars_tls_ca_certs(int *i, struct tool_pars_tls_para *para)
{
    unsigned int j;
    int ret = 0;
    int ret_val;
    char ca_cert_flag[CA_CERT_FLAG_LEN] = {0};
    int index;

    for (j = TLS_CA1_CERT; j <= TLS_CA14_CERT; j++) {
        ret_val = snprintf_s(ca_cert_flag, CA_CERT_FLAG_LEN, CA_CERT_FLAG_LEN - 1, "ca%u", j);
        if (ret_val <= 0) {
            roce_err("Snprintf fail. (ret=%d)", ret_val);
            return UDA_TOOL_NO_MEM_ERR;
        }
        para->tls_index = (unsigned int)j;
        ret = tool_pars_tls_cfg_para_once(para, i, ca_cert_flag);
        if (ret == TLS_CA_FLAG) {
            index = (*i) + 1;
            roce_info("para->argv[%d] is a ca", index);
            (*i)--;
            continue;
        }
        if ((*i >= para->argc) || (ret == TLS_CRL_FLAG) || ret == TLS_HOST_FLAG) {
            roce_info("all para have parsed or maybe a crl or host, ret:%d", ret);
            break;
        }
        if (ret) {
            roce_err("tool check for [%d]_th para fail, ret:%d", *i, ret);
            return ret;
        }
        para->cert_cnt++;
        roce_info("find ca_cert_flag:%s, cert_cnt:%d, j:%u, i:%d", ca_cert_flag, para->cert_cnt, j, *i);
    }

    if ((*i < para->argc - 1) && (ret == 0)) {
        (*i)++;
        return TLS_CRL_FLAG;
    }
    return ret;
}

STATIC int tool_pars_tls_crl_handle(struct tool_pars_tls_para *para, int *index, int *next_flag)
{
    int ret;
    int index_tmp;

    para->tls_index = TLS_CRL;
    ret = tool_pars_tls_cfg_para_once(para, index, "crl");
    if (ret == TLS_HOST_FLAG) {
        *next_flag = TLS_HOST_FLAG;
        return 0;
    }

    if (ret) {
        roce_err("tool check for [%d]_th para fail, ret:%d", *index, ret);
        return ret;
    }

    index_tmp = *index + 1;
    if ((*index < para->argc - 1) && (strncmp(para->argv[index_tmp], "host", strlen("host") + 1) != 0)) {
        roce_err("crl index[%d] < [%d](argc - 1), crl is not the last configuration item, illegal",
            *index, para->argc - 1);
        return UDA_PARAM_TLS_CRL_NOT_LAST_ITEM_ERR;
    }

    if (*index == para->argc - 1) {
        roce_info("crls index[%d] == [%d](argc - 1), crl is the last configuration item", *index, para->argc - 1);
    } else {
        (*index)++;
        *next_flag = TLS_HOST_FLAG;
    }

    return 0;
}

STATIC int tool_pars_tls_host_handle(struct tool_pars_tls_para *para, int index)
{
    int ret;

    if (index >= para->argc) { // all para have parsed
        return 0;
    }

    para->tls_index = TLS_HOST;
    ret = tool_check_tls_param(para->argv[index], "host");
    if (ret == UDA_PARAM_INVALID_ERR) {
        roce_err("tool_check_tls_param for [%d]_th para err, ret:%d", index, ret);
        return ret;
    }

    if (index < para->argc - 1) {
        roce_err("host index[%d] < [%d](argc - 1), host is not the last configuration item, illegal", index,
                 para->argc - 1);
        return UDA_PARAM_TLS_HOST_NOT_LAST_ITEM_ERR;
    }

    para->host_flag = true;
    para->bit_map[para->tls_index] = 1;
    return 0;
}

STATIC int tool_pars_tls_path(struct tool_pars_tls_para *para, int *index)
{
    if (strncmp(para->argv[*index], "path", strlen("path") + 1)) {
        roce_err("tool_check_tls_param for [%d]_th para fail, expect [path]", *index);
        return UDA_PARAM_INVALID_ERR;
    }
    *index = *index + 1;
    if ((strlen(para->argv[*index]) > PATH_MAX) || (realpath(para->argv[*index], para->real_conf_path) == NULL)) {
        roce_err("path_len[%u] > [%d](PATH_MAX) or conf_path is invalid, err[%d]",
            strlen(para->argv[*index]), PATH_MAX, errno);
        return UDA_PARAM_PATH_INVALID_ERR;
    }

    return 0;
}

STATIC int tool_pars_tls_cfg_para(struct tls_cert_ky_crl_info *tls_cfg, struct tool_pars_tls_para *para)
{
    int ret;
    int i = 0;
    int next_flag = 0;

    ret = tool_pars_tls_path(para, &i);
    if (ret) {
        return ret;
    }

    para->tls_index = TLS_PRI_KY;
    ret = tool_pars_tls_cfg_para_once(para, &i, "pri");
    if (ret == TLS_CRL_FLAG) {
        goto crl_handle;
    } else if (ret) {
        roce_err("tool check for [%d]_th para fail, ret:%d", i, ret);
        return UDA_PARAM_TLS_CA_WTHOT_PRI_ERR;
    }

    para->tls_index = TLS_PUB_CERT;
    ret = tool_pars_tls_cfg_para_once(para, &i, "pub");
    if (ret) {
        roce_err("tool_pars_tls_cfg_para_once fail, ret:%d", ret);
        return  (ret == TLS_CA_FLAG || ret == TLS_CRL_FLAG || ret == TLS_HOST_FLAG) ?
            UDA_PARAM_TLS_PRI_WITHOUT_PUB_ERR : ret;
    }

    para->cert_cnt++;
    ret = tool_pars_tls_ca_certs(&i, para);
    tls_cfg->mng.cert_count = para->cert_cnt;
    if (ret == TLS_CRL_FLAG) {
        goto crl_handle;
    }
    if (ret == TLS_HOST_FLAG) {
        goto host_handle;
    }
    if (ret) {
        roce_err("tool check for [%d]_th para fail, ret:%d", i, ret);
        return ret;
    }

    return ret;
crl_handle:
    i--;
    ret = tool_pars_tls_crl_handle(para, &i, &next_flag);
    if (ret) {
        roce_err("tool_pars_tls_crl_handle failed, ret:%d", ret);
    }
    return (ret == 0 && next_flag == TLS_HOST_FLAG) ? tool_pars_tls_host_handle(para, i) : ret;
host_handle:
    return tool_pars_tls_host_handle(para, i);
}

STATIC void tool_tls_cfg_print(const unsigned int cfg[], unsigned int cfg_len, int logic_id)
{
    int i;
    char ca_bit_map[MAX_TLS_CFG_COUNT] = {0};

    if (cfg_len > MAX_TLS_CFG_COUNT) {
        roce_err("cfg_len[%u] > [%d], invalid", cfg_len, MAX_TLS_CFG_COUNT);
        return;
    }

    for (i = TLS_CA1_CERT; i <= TLS_CA14_CERT; i++) {
        ca_bit_map[i - 1] = cfg[i] + '0';
    }

    ca_bit_map[i] = '\0';
    LOG_CONFIG("set tls cfg[pub:%d, ca1-ca14:%s, pri:%u, crl:%u, host:%u] for logic_id[%d]", cfg[TLS_PUB_CERT],
        ca_bit_map, cfg[TLS_PRI_KY], cfg[TLS_CRL], cfg[TLS_HOST], logic_id);
    return;
}

// 用于判断当前是否在虚拟机中，与Manage仓的npu_is_in_virtual_machine类似
bool tool_is_virtual_machine(void)
{
    unsigned int ret, host_flag = 0;
    ret = (unsigned int)system("/usr/sbin/dmidecode 2>&1 | grep -E \"xen|Xen|VMware|OpenStack|KVM Virtual Machine\"" \
                               " > /dev/null");
    if ((ret != (unsigned int)-1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0))) {
        return TRUE;
    }

    ret = (unsigned int)system("/usr/sbin/dmidecode 2>&1 | grep -E \"Manufacturer: QEMU|Manufacturer: qemu\"" \
                               " > /dev/null");
    if ((ret != (unsigned int)-1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0))) {
        return TRUE;
    }

    ret = (unsigned int)system("/usr/bin/systemd-detect-virt -v > /dev/null  2>&1");
    if ((ret != (unsigned int)-1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0))) {
        return TRUE;
    }

    ret = (unsigned int)drvGetHostPhyMachFlag(0, &host_flag);
    if (ret != 0) {
        roce_err("Get host physical machine flag failed. (ret=%u)\n", ret);
        return FALSE;
    }

    if (host_flag != DEVDRV_HOST_PHY_MACH_FLAG) {
        return TRUE;
    }

    return FALSE;
}

STATIC int tool_tls_handle_cfg(struct tool_pars_tls_para *para, struct tls_cert_ky_crl_info *tls_cfg,
    struct tool_param *param)
{
    int ret;

    ret = tool_check_tls_cfg(para->bit_map, MAX_TLS_CFG_COUNT);
    if (ret) {
        roce_err("tls_cfg is invalid. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    ret = tool_get_tls_cfg_from_file(param->logic_id, para->host_flag, para->cfg_file, MAX_TLS_CFG_COUNT, tls_cfg);
    if (ret) {
        roce_err("tool_get_tls_cfg_from_file failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    if (para->host_flag == true) {
        tls_cfg->mng.save_mode = TLS_SAVE_TO_FILE;
        ret = rdfx_set_tls_cfg(param->logic_id, (char *)tls_cfg, sizeof(struct tls_cert_ky_crl_info), NULL, 0);
        if (ret == -EBUSY) {
            return UDA_TOOL_SYS_BUSY_ERR;
        } else if (ret) {
            roce_err("rdfx_set_tls_cfg failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
            return ret;
        }
    } else {
        tls_cfg->mng.save_mode = TLS_SAVE_TO_FlASH;
        if (tool_is_virtual_machine()) {
            roce_err("The VM has no permission to write flash.");
            return UDA_DSMI_NOT_SUPPORT_VM_ERR;
        }
        ret = dsmi_set_tls_cfg(param->logic_id, tls_cfg);
        roce_err("Dsmi set tls_cfg failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return (ret == -ENOENT && tls_cfg->mng.cert_count == 0) ?
            UDA_PARAM_TLS_NO_CERT_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

STATIC int tool_set_tls_cfg(int argc, char **argv, struct tool_param *param)
{
    int ret, ret_val;
    struct tls_cert_ky_crl_info *tls_cfg = NULL;
    struct tool_pars_tls_para *para = NULL;

    if ((param == NULL) || (argc > TOOL_TLS_CMD_MAX_LEN) || (argc < TOOL_TLS_CMD_MIN_LEN)) {
        roce_err("Input param is invalid. (param=%p; argc=%d)", param, argc);
        return (param == NULL) ? UDA_TOOL_INNER_PARAM_ERR : UDA_PARAM_CMD_COUNT_ERR;
    }

    tls_cfg = calloc(CALLOC_BLOCK_NUM, sizeof(struct tls_cert_ky_crl_info));
    if (tls_cfg == NULL) {
        roce_err("Ptr is NULL.");
        return UDA_TOOL_NO_MEM_ERR;
    }
    para = calloc(CALLOC_BLOCK_NUM, sizeof(struct tool_pars_tls_para));
    if (para == NULL) {
        roce_err("no memory for para");
        ret = UDA_TOOL_NO_MEM_ERR;
        goto cfg_mem_err;
    }

    para->argc = argc;
    para->argv = argv;
    para->cfg_file_len = MAX_TLS_CFG_COUNT;

    ret = tool_pars_tls_cfg_para(tls_cfg, para);
    if (ret) {
        roce_err("tool_pars_tls_cfg_para fail, ret:%d", ret);
        goto para_mem_err;
    }

    tool_tls_cfg_print(para->bit_map, MAX_TLS_CFG_COUNT, param->logic_id);
    ret = tool_tls_handle_cfg(para, tls_cfg, param);
    if (ret) {
        if (ret != UDA_TOOL_SYS_BUSY_ERR) {
            roce_err("handle tls cfg err, ret:%d", ret);
        }
        goto para_mem_err;
    }

para_mem_err:
    free(para);
    para = NULL;
cfg_mem_err:
    ret_val = memset_s(tls_cfg, CALLOC_BLOCK_NUM * sizeof(struct tls_cert_ky_crl_info),
        0, CALLOC_BLOCK_NUM * sizeof(struct tls_cert_ky_crl_info));
    if (ret_val) {
        roce_err("Memset_s fail. (ret_val=%d)", ret_val);
    }
    free(tls_cfg);
    tls_cfg = NULL;
    return ret;
}

STATIC int tool_set_tls_alarm_get_alarm(char *argv, size_t len, unsigned int *alarm)
{
    if (len < 1 || len > TOOL_TLS_ALARM_MAX_LEN || check_str_is_num(argv, len)) {
        roce_err("argv err. (len=%u)", len);
        return UDA_PARAM_TLS_INVALID_ALARM_ERR;
    }

    *alarm = (unsigned int)strtol(argv, NULL, NUMBER_BASE);
    if ((*alarm != TOOL_TLS_ALARM_DISABLE) && (*alarm < TOOL_TLS_ALARM_MIN_DAYS || *alarm > TOOL_TLS_ALARM_MAX_DAYS)) {
        roce_err("alarm days is not valid");
        return UDA_PARAM_TLS_INVALID_ALARM_ERR;
    }
    return 0;
}

STATIC int tool_set_tls_alarm(int argc, char **argv, struct tool_param *param)
{
    int ret;
    unsigned int alarm;
    unsigned int size_out = 0;
    struct tls_alarm_info alarm_info = {0};

    if (argc != 1 && argc != TLS_HOST_ARGC_NUM) {
        roce_err("argc err %d", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (argc == TLS_HOST_ARGC_NUM && strncmp(argv[argc - 1], "host", strlen("host") + 1) != 0) {
        roce_err("host is not the last config item, invalid");
        return UDA_PARAM_TLS_HOST_NOT_LAST_ITEM_ERR;
    }

    if (argv[0] == NULL) {
        roce_err("argv[0] is NULL!");
        return UDA_PARAM_TLS_INVALID_ALARM_ERR;
    }

    LOG_CONFIG("start to set tls alarm of device[%d]", param->logic_id);

    ret = tool_set_tls_alarm_get_alarm(argv[0], strlen(argv[0]), &alarm);
    if (ret) {
        return ret;
    }

    alarm_info.alarm = alarm;
    if (strncmp(argv[argc - 1], "host", strlen("host") + 1) == 0) {
        if (alarm_info.alarm == 0) {
            roce_err("Set alarm to 0 only support on device.");
            return UDA_PARAM_TLS_INVALID_ALARM_ERR;
        }
        alarm_info.save_mode = TLS_SAVE_TO_FILE;
        ret = rdfx_set_tls_alarm(param->logic_id, (const char *)&alarm_info, sizeof(struct tls_alarm_info),
            NULL, &size_out);
        if (ret) {
            roce_err("rdfx_set_tls_alarm fail for logic_id[%d] ret[%d] alarm[%u]", param->logic_id, ret, alarm);
            return (ret == -ENOENT) ? UDA_PARAM_TLS_NO_CERT_ERR : ret;
        }
        return 0;
    }

    if (tool_is_virtual_machine()) {
        roce_err("The VM has no permission to write flash.");
        return UDA_DSMI_NOT_SUPPORT_VM_ERR;
    }

    alarm_info.save_mode = TLS_SAVE_TO_FlASH;
    ret = dsmi_set_tls_alarm(param->logic_id, &alarm_info);
    if (ret) {
        roce_err("dsmi_set_tls_alarm fail logic_id[%d] ret[%d] alarm[%u]", param->logic_id, ret, alarm);
        return (ret == -ENOENT) ? UDA_PARAM_TLS_NO_CERT_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    return 0;
}

STATIC int tool_tls_enable_warning(int chip_id, const char *inbuf, unsigned int size_in,
    unsigned int *size_out, unsigned int enable)
{
    int ret = 0;
    unsigned int preconfig;
    struct tls_cert_show_info show_info[MAX_SHOW_INFO_COUNT];

    if (enable == 1) {
        if (*(unsigned int *)inbuf == TLS_SAVE_TO_FILE) {
            *size_out = sizeof(struct tls_cert_show_info) * MAX_SHOW_INFO_COUNT;
            ret = rdfx_get_tls_cfg(chip_id, inbuf, size_in, (char *)show_info, size_out);
        } else if (*(unsigned int *)inbuf == TLS_SAVE_TO_FlASH) {
            ret = dsmi_get_tls_cfg(chip_id, 0, show_info, MAX_SHOW_INFO_COUNT);
        }
    }

    if (ret) {
        roce_err("get tls cfg fail ret[%d] logic_id[%d]", ret, chip_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    DSMI_CHECK_PTR_VALID_RETURN_VAL(show_info, UDA_TOOL_INNER_PARAM_ERR);

    preconfig = tool_tls_cert_is_preconfig(show_info, MAX_SHOW_INFO_COUNT);
    if (preconfig == 1) {
        TOOL_PRINT_INFO("[Warning] The currently loaded is a preset certificate, which has security risks."
            "It is recommended to configure a security certificate.");
    }
    return 0;
}

int tool_cfg_tls_enable_recovery(struct tool_param *param)
{
    struct tls_enable_info enable_info = { 0 };
    char tls_enable[MAX_TLS_LEN] = "";
    char *tmp_ptr = NULL;
    int ret;

    ret = cfg_read_conf(param->phy_id, "tls_enable", tls_enable, sizeof(tls_enable));
    if (ret) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
            roce_info("Tls enable do not need recover cfg [%d], phy_id:[%d]", ret, param->phy_id);
            return 0;
        } else {
            roce_err("Cfg_read_conf tls enable failed! ret[%d]", ret);
            return UDA_PARAM_INVALID_ERR;
        }
    }
    enable_info.enable = (unsigned int)strtoul(tls_enable, &tmp_ptr, STR_NUM_BASE);
    if (tmp_ptr == tls_enable || *tmp_ptr != '\0') {
        roce_err("Enable status must be unsigned int, (enable=%u; tail=%s)", enable_info.enable, tmp_ptr);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    enable_info.save_mode = TLS_SAVE_TO_FlASH;
    ret = dsmi_set_tls_enable(param->logic_id, &enable_info);
    if (ret) {
        roce_err("Dsmi set tls enable failed. (logic_id=%d; ret=%d; enable=%u)", param->logic_id, ret,
            enable_info.enable);
        return (ret == -ENOENT) ? UDA_PARAM_TLS_NO_CERT_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    return 0;
}

STATIC int set_tls_flash_enable(struct tool_param *param, struct tls_enable_info enable_info, unsigned int size_out)
{
    char enable_cfg[MAX_TLS_LEN] = {'\0'};
    int ret;

    enable_info.save_mode = TLS_SAVE_TO_FlASH;
    (void)tool_tls_enable_warning(param->logic_id, (const char *)&(enable_info.save_mode),
        sizeof(enable_info.save_mode), &size_out, enable_info.enable);
    ret = dsmi_set_tls_enable(param->logic_id, &enable_info);
    if (ret) {
        roce_err("Dsmi_set_tls_enable fail. (logic_id=%d; ret=%d; enable=%u)", param->logic_id, ret,
            enable_info.enable);
        return (ret == -ENOENT) ? UDA_PARAM_TLS_NO_CERT_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    ret = sprintf_s(enable_cfg, MAX_TLS_LEN, "%u", enable_info.enable);
    if (ret <= 0) {
        roce_err("Sprintf tls enable info failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = cfg_write_conf(param->phy_id, "tls_enable", enable_cfg);
    if (ret) {
        roce_err("Write cfg error. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }
    return 0;
}

STATIC int set_tls_host_enable(struct tool_param *param, struct tls_enable_info enable_info, unsigned int size_out)
{
    int ret;

    enable_info.save_mode = TLS_SAVE_TO_FILE;
    (void)tool_tls_enable_warning(param->logic_id, (const char *)&(enable_info.save_mode),
        sizeof(enable_info.save_mode), &size_out, enable_info.enable);
    ret = rdfx_set_tls_enable(param->logic_id, (const char *)&enable_info, sizeof(struct tls_enable_info),
        NULL, &size_out);
    if (ret) {
        roce_err("Rdfx_set_tls_enable fail for logic_id[%d] ret[%d] alarm[%u]", param->logic_id, ret,
            enable_info.enable);
        return (ret == -ENOENT) ? UDA_PARAM_TLS_NO_CERT_ERR : ret;
    }
    return 0;
}
STATIC int tool_set_tls_enable(int argc, char **argv, struct tool_param *param)
{
    unsigned int enable;
    int ret;
    unsigned int size_out = 0;
    struct tls_enable_info enable_info = {0};

    if (argc != 1 && argc != TLS_HOST_ARGC_NUM) {
        roce_err("Argc err %d", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (argc == TLS_HOST_ARGC_NUM && strncmp(argv[argc - 1], "host", strlen("host") + 1) != 0) {
        roce_err("Host is not the last config item, invalid");
        return UDA_PARAM_TLS_HOST_NOT_LAST_ITEM_ERR;
    }

    if (argv[0] == NULL) {
        roce_err("Argv[0] is NULL!");
        return UDA_PARAM_TLS_INVALID_ENABLE_ERR;
    }

    LOG_CONFIG("Start to set tls enable of logic_id[%d]", param->logic_id);

    if (strncmp(argv[0], "0", strlen("0") + 1) && strncmp(argv[0], "1", strlen("1") + 1)) {
        roce_err("Argv err len[%d]", strlen(argv[0]));
        return UDA_PARAM_TLS_INVALID_ENABLE_ERR;
    }

    enable = (unsigned int)strtol(argv[0], NULL, NUMBER_BASE);
    if (enable != 0 && enable != 1) {
        roce_err("Enable is not valid");
        return UDA_PARAM_TLS_INVALID_ENABLE_ERR;
    }

    enable_info.enable = enable;
    if (strncmp(argv[argc - 1], "host", strlen("host") + 1) == 0) {
        ret = set_tls_host_enable(param, enable_info, size_out);
    } else {
        ret = set_tls_flash_enable(param, enable_info, size_out);
    }

    if (ret != 0) {
        roce_err("Set tls [%s] enable failed, (logic_id=%d)", argv[argc - 1], param->logic_id);
    }

    return ret;
}

STATIC int tool_set_tls(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc < TOOL_TLS_SET_CMD_MIN_LEN) {
        roce_err("argc err %d", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "enable", strlen("enable") + 1)) {
        ret = tool_set_tls_enable(argc - 1, argv + 1, param);
        if (ret == UDA_PARAM_TLS_NO_CERT_ERR) {
            roce_err("can't set tls enable or disable for logic_id[%d], because it has no certs, please set certs",
                param->logic_id);
            return ret;
        }
        if (ret) {
            roce_err("set tls enable failed, logic_id[%d]", param->logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "alarm", strlen("alarm") + 1)) {
        ret = tool_set_tls_alarm(argc - 1, argv + 1, param);
        if (ret == UDA_PARAM_TLS_NO_CERT_ERR) {
            roce_err("can't set tls alarm for logic_id[%d], because it has no certs, please set certs",
                param->logic_id);
            return ret;
        }
        if (ret) {
            roce_err("set tls alarm failed, logic_id[%d]", param->logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "path", strlen("path") + 1)) {
        ret = tool_set_tls_cfg(argc, argv, param);
        TOOL_PRINT_INFO("[WARNING] Please delete the private key file after updating for security considerations.");
        if (ret) {
            if (ret != UDA_TOOL_SYS_BUSY_ERR) {
                roce_err("set tls cfg failed, ret[%d], logic_id[%d]", ret, param->logic_id);
            }
            return ret;
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_tls_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_tls_cfg(argc, argv, param);
        if (ret) {
            if (ret != UDA_PARAM_TLS_NO_CERT_ERR) {
                roce_err("tool_get_tls_cfg fail, ret:%d", ret);
            }
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_tls(argc - 1, argv + 1, param);
        if (ret) {
            if (ret != UDA_TOOL_SYS_BUSY_ERR) {
                roce_err("set tls cfg failed, ret[%d], logic_id[%d]", ret, param->logic_id);
            }
            return ret;
        }
    } else if (!strncmp(argv[0], "-c", strlen("-c") + 1)) {
        ret = tool_clear_tls_cfg(argc, argv, param);
        if (ret) {
            if (ret != UDA_TOOL_SYS_BUSY_ERR) {
                roce_err("clear tls cfg failed, ret[%d], logic_id[%d]", ret, param->logic_id);
            }
            return ret;
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

STATIC bool tool_find_ca_insert_pos(struct tls_ca_new_certs *tls_ca_cfg, int cb_num,
                                    struct tool_pars_tls_ca_para *para)
{
    for (int i = 0; i < cb_num; ++i) {
        for (int j = 0; j < TLS_CA_SSL_MAX_NEW_CERT_NUM; ++j) {
            if (strlen(tls_ca_cfg[i].alias[j].name) == 0) {
                para->insert_cb = i;
                para->insert_pos = j;
                return true;
            }
        }
    }
    
    return false;
}

STATIC bool tool_exist_same_alias_ca(struct tls_ca_new_certs *tls_ca_cfg, int cb_num,
                                     struct tool_pars_tls_ca_para *para)
{
    for (int i = 0; i < cb_num; ++i) {
        for (int j = 0; j < TLS_CA_SSL_MAX_NEW_CERT_NUM; ++j) {
            if (strcmp(tls_ca_cfg[i].alias[j].name, para->alias) == 0) {
                para->exist_cb = i;
                para->exist_pos = j;
                return true;
            }
        }
    }

    return false;
}

STATIC int tool_calc_cert_fingerprint(char *real_ca_conf_path, unsigned char *fingerprint, int len)
{
    int ret = 0;
    X509 *cert = NULL;
    unsigned int fingerprint_len = 0;
    struct stat file_stat = { 0 };
    char real_conf_path[PATH_MAX + 1] = {0};

    if (realpath(real_ca_conf_path, real_conf_path) == NULL) {
        roce_err("set tls ca realpath %s is err.", real_ca_conf_path);
        ret = -EINVAL;
        goto err;
    }
    ret = stat(real_ca_conf_path, &file_stat);
    if (ret != 0 || (file_stat.st_mode & S_IFMT) != S_IFREG) {
        roce_err("set tls ca path %s is invalid.", real_ca_conf_path);
        ret = -EINVAL;
        goto err;
    }

    FILE *fp = fopen(real_conf_path, "rb");
    if (!fp) {
        roce_err("tls ca open conf path %s failed.", real_ca_conf_path);
        ret = -EINVAL;
        goto err;
    }
    cert = PEM_read_X509(fp, NULL, NULL, NULL);
    ret = fclose(fp);
    if (ret) {
        roce_warn("tls ca fclose fail. (ret=%d; errno=%d)", ret, errno);
        goto err;
    }

    if (!X509_digest(cert, EVP_sha256(), fingerprint, &fingerprint_len)) {
        roce_err("tls ca failed to calc digest.");
        ret = -EINVAL;
        goto err;
    }

err:
    if (cert) {
        X509_free(cert);
    }

    return ret;
}

STATIC int tool_insert_tls_ca_cfg(struct tls_ca_new_certs *tls_ca_cfg, struct tool_pars_tls_ca_para *para)
{
    int ret;
    unsigned char fingerprint[EVP_MAX_MD_SIZE];
    int len = 0;

    if (tool_calc_cert_fingerprint(para->real_ca_conf_path, fingerprint, EVP_MAX_MD_SIZE) != 0) {
        return -EINVAL;
    }
    ret = memcpy_s(tls_ca_cfg[para->insert_cb].alias[para->insert_pos].thumbprint, TLS_CA_SSL_NEW_CERT_ALIAS_LEN,
                   fingerprint, TLS_CA_SSL_NEW_CERT_ALIAS_LEN);
    if (ret) {
        roce_err("tool_insert_tls_ca_cfg memcpy failed. (ret=%d)", ret);
        return -EINVAL;
    }
    ret = memcpy_s(tls_ca_cfg[para->insert_cb].alias[para->insert_pos].name, TLS_CA_SSL_NEW_CERT_ALIAS_LEN,
                   para->alias, TLS_CA_SSL_NEW_CERT_ALIAS_LEN);
    if (ret) {
        roce_err("tool_insert_tls_ca_cfg memcpy failed. (ret=%d)", ret);
        return -EINVAL;
    }

    ret = tool_read_file(para->real_ca_conf_path, tls_ca_cfg[para->insert_cb].certs[para->insert_pos].ncert_info,
                         &len, TLS_CA_CERT, false);
    if (ret != 0) {
        roce_err("tool_insert_tls_ca_cfg read file %s failed. (ret=%d)", para->real_ca_conf_path, ret);
        return ret;
    }

    tls_ca_cfg[para->insert_cb].ncert_count++;
    return ret;
}

STATIC int tool_check_set_tls_ca_cfg(struct tls_ca_new_certs *tls_ca_cfg, int cb_num,
                                     struct tool_pars_tls_ca_para *para)
{
    int ret = 0;
    if (tls_ca_cfg[0].ncert_count == TLS_CA_SSL_MAX_NEW_CERT_NUM
        && tls_ca_cfg[1].ncert_count == TLS_CA_SSL_MAX_NEW_CERT_NUM) {
        roce_err("set tls ca fail, flash is full.");
        return UDA_PARAM_TLS_CA_MEM_FULL;
    }

    if (tool_exist_same_alias_ca(tls_ca_cfg, cb_num, para) || !tool_find_ca_insert_pos(tls_ca_cfg, cb_num, para)) {
        roce_err("set tls ca fail, this alias %s is exist or not find insert pos, exist_cb %d exist_pos %d.",
                 para->alias, para->exist_cb, para->exist_pos);
        return UDA_PARAM_TLS_CA_SAME_ALIAS;
    }

    ret = tool_insert_tls_ca_cfg(tls_ca_cfg, para);
    if (ret) {
        return UDA_PARAM_TLS_HOST_INSERT_CA_ERR;
    }

    return ret;
}

STATIC int tool_handle_tls_ca_cfg(struct tool_param *param, struct tool_pars_tls_ca_para *para)
{
    int ret;
    uint32_t certs_len = sizeof(struct tls_ca_new_certs);
    struct tls_ca_new_certs *tls_ca_cfg = (struct tls_ca_new_certs *)calloc(TLS_CA_SSL_MAX_FLASH_NUM, certs_len);

    if (tls_ca_cfg == NULL) {
        roce_err("malloc memory failed");
        return -EINVAL;
    }

    ret = dsmi_get_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0 && ret != (-ENOENT)) { // flash为空时，可以写入证书，不能返回错误
        roce_err("when set, get tls ca cfg [%s] fail. (ret=%d; logic_id=%d)", para->alias, ret, param->logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    // 设置别名与原flash中证书不存在重名且flash中有空位，直接插入
    ret = tool_check_set_tls_ca_cfg(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM, para);
    if (ret != 0) {
        roce_err("when set, insert tls ca cfg [%s] fail. (ret=%d; logic_id=%d)", para->alias, ret, param->logic_id);
        goto out;
    }

    // 覆盖写flash
    ret = dsmi_set_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret) {
        roce_err("set tls ca cfg [%s] failed. (logic_id=%d; ret=%d)", para->alias, param->logic_id, ret);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }
out:
    free(tls_ca_cfg);  // 释放动态分配的内存
    return ret;
}

int tool_check_name_match_format(char *name, char *format)
{
    int ret;
    int cflags = REG_EXTENDED;
    regex_t regex;

    ret = regcomp(&regex, format, cflags);
    if (ret != 0) {
        roce_err("check name compile regex failed. (ret=%d)", ret);
        ret = UDA_PARAM_INVALID_ERR;
        goto err;
    }

    ret = regexec(&regex, name, 0, NULL, 0);
    if (ret != 0) {
        roce_err("match name [%s] failed. (ret=%d)", name, ret);
        ret = UDA_PARAM_INVALID_ERR;
        goto err;
    }

    roce_info("match name %s success: pattern %s", name, format);
err:
    regfree(&regex);
    return ret;
}

STATIC int tool_parse_tls_ca_cfg(int argc, char **argv, struct tool_pars_tls_ca_para *para)
{
    int ret = 0;
    int index = 0;
    struct stat file_stat = { 0 };

    if (strncmp(argv[index], "alias", strlen("alias") + 1) != 0) {
        roce_err("set tls ca param for %d_para err.", index);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    index++;
    ret = tool_check_name_match_format(argv[index], TLS_CA_ALIAS_FORMAT);
    if (ret != 0) {
        return ret;
    }
    ret = memcpy_s(para->alias, sizeof(para->alias), argv[index], strlen(argv[index]));
    if (ret != 0) {
        roce_err("set tls ca alias [%s], memcpy failed. (ret=%d)", argv[index], ret);
        return UDA_PARAM_INVALID_ERR;
    }

    index++;
    if (strncmp(argv[index], "path", strlen("path") + 1) != 0) {
        roce_err("set tls ca param for %d_para err.", index);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    index++;
    if (strlen(argv[index]) > PATH_MAX || realpath(argv[index], para->real_ca_conf_path) == NULL) {
        roce_err("set tls ca path err. (len=%u; errno=%d)", strlen(argv[index]), errno);
        return UDA_PARAM_PATH_INVALID_ERR;
    }

    ret = stat(para->real_ca_conf_path, &file_stat);
    if (ret != 0 || (file_stat.st_mode & S_IFMT) != S_IFREG) {
        roce_err("set tls ca path is not file. (ret=%d)", ret);
        return UDA_PARAM_PATH_INVALID_ERR;
    }

    return ret;
}

STATIC int tool_set_tls_ca_cfg(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct tool_pars_tls_ca_para para = {0};
    LOG_CONFIG("start to set tls ca cfg of logic_id[%d]", param->logic_id);
    if (argc != TOOL_TLS_CA_IMPORT_CMD_LEN) {
        roce_err("set tls ca argc err. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_parse_tls_ca_cfg(argc, argv, &para);
    if (ret != 0) {
        return ret;
    }

    return tool_handle_tls_ca_cfg(param, &para);
}

STATIC int tool_delete_single_tls_ca_cfg_rewrite_flash(char *alias_name, struct tls_ca_new_certs *tls_ca_cfg,
                                                       struct tool_param *param)
{
    int ret;
    struct tool_pars_tls_ca_para para = {0};
    ret = memcpy_s(para.alias, TLS_CA_SSL_NEW_CERT_ALIAS_LEN, alias_name, strlen(alias_name) + 1);
    if (ret) {
        roce_err("when delete, memcpy alias %s fail. (ret=%d)", alias_name, ret);
        return UDA_PARAM_INVALID_ERR;
    }
    if (!tool_exist_same_alias_ca(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM, &para)) {
        roce_err("delete tls ca cfg [%s] fail, it is not exist.", alias_name);
        return UDA_PARAM_TLS_CA_ALIAS_NOT_EXIST;
    }

    ret = memset_s(tls_ca_cfg[para.exist_cb].certs[para.exist_pos].ncert_info, TLS_CA_SSL_NEW_CERT_LEN,
                   0, TLS_CA_SSL_NEW_CERT_LEN);
    if (ret) {
        roce_err("when delete, memset ncert_info fail. (ret=%d)", ret);
        return UDA_PARAM_INVALID_ERR;
    }
    ret = memset_s(tls_ca_cfg[para.exist_cb].alias[para.exist_pos].name, TLS_CA_SSL_NEW_CERT_ALIAS_LEN,
                   0, TLS_CA_SSL_NEW_CERT_ALIAS_LEN);
    if (ret) {
        roce_err("when delete, memset name fail. (ret=%d)", ret);
        return UDA_PARAM_INVALID_ERR;
    }
    ret = memset_s(tls_ca_cfg[para.exist_cb].alias[para.exist_pos].thumbprint, TLS_CA_SSL_NEW_CERT_ALIAS_LEN,
                   0, TLS_CA_SSL_NEW_CERT_ALIAS_LEN);
    if (ret) {
        roce_err("when delete, memset thumbprint fail. (ret=%d)", ret);
        return UDA_PARAM_INVALID_ERR;
    }
    tls_ca_cfg[para.exist_cb].ncert_count--;

    ret = dsmi_set_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0) {
        roce_err("dsmi_set_tls_ca_cfg fail. (ret=%d)", ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    return ret;
}

STATIC int tool_delete_single_tls_ca_cfg(char *alias_name, struct tool_param *param)
{
    int ret;

    if (tool_check_name_match_format(alias_name, TLS_CA_ALIAS_FORMAT) != 0) {
        roce_err("delete tls ca alias [%s] err, the format is not match.", alias_name);
        return UDA_PARAM_INVALID_ERR;
    }

    struct tls_ca_new_certs *tls_ca_cfg = calloc(TLS_CA_SSL_MAX_FLASH_NUM, sizeof(struct tls_ca_new_certs));
    if (tls_ca_cfg == NULL) {
        roce_err("delete tls ca cfg, alloc tls_ca_cfg fail. (ret=%d)", -ENOMEM);
        return -ENOMEM;
    }

    ret = dsmi_get_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0) {
        roce_err("when delete, get tls ca cfg fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    // 将重名证书删除后，覆盖写flash
    ret = tool_delete_single_tls_ca_cfg_rewrite_flash(alias_name, tls_ca_cfg, param);
    if (ret) {
        roce_err("when delete, delete and rewirte flash fail. (ret=%d)", ret);
    }

out:
    (void)memset_s(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs),
                   0, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs));
    free(tls_ca_cfg);
    return ret;
}

STATIC int tool_delete_tls_ca_cfg(int argc, char **argv, struct tool_param *param)
{
    int ret;
    unsigned int save_mode = TLS_SAVE_TO_FlASH;
    LOG_CONFIG("start to delete tls ca cfg of logic_id[%d]", param->logic_id);
    if (argc < TOOL_TLS_CA_CMD_LEN_ONE) {
        roce_err("delete tls ca argc err. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    // 删除单个证书需要覆盖写flash，删除所有证书则直接清空flash
    if (strncmp(argv[0], "alias", strlen("alias") + 1) == 0 && (argc == TOOL_TLS_CA_CMD_LEN_ONE + 1)) {
        ret = tool_delete_single_tls_ca_cfg(argv[1], param);
        if (ret != 0) {
            roce_err("delete tls ca cfg [%s] fail. (ret=%d; logic_id=%d)", argv[1], ret, param->logic_id);
            return ret;
        }
    } else if (strncmp(argv[0], "all", strlen("all") + 1) == 0 && (argc == TOOL_TLS_CA_CMD_LEN_ONE)) {
        ret = dsmi_clear_tls_ca_cfg(param->logic_id, save_mode);
        if (ret != 0) {
            if (ret == -ENOENT) {
                roce_err("no need to clear flash, because no certs is in flash!");
                return UDA_PARAM_TLS_CA_MEM_EMPTY;
            } else if (ret == -ENODEV) {
                roce_err("vm machine has no power to clear flash.");
                return UDA_DSMI_NOT_SUPPORT_VM_ERR;
            } else if (ret == -EACCES) {
                roce_err("Permission denied.");
                return UDA_TOOL_SYS_NOT_ACCESS;
            }
            roce_err("delete all tls ca cfg fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
            return UDA_DSMI_EXE_ERR;
        }
    } else {
        roce_err("delete tls ca param for %d_para err.", argc);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

STATIC int tool_show_tls_ca_cfg_handle(unsigned char *ncert_info, struct tool_param *param, const char *name)
{
    int ret = 0;
    X509 *cert = NULL;
    struct tls_cert_show_info show_info = {0};

    cert = tls_load_cert(ncert_info, strlen(ncert_info), SSL_FILETYPE_PEM);
    if (cert == NULL) {
        roce_err("show tls ca cfg, load cert fail.");
        return UDA_PARAM_INVALID_ERR;
    }

    ret = rdfx_get_cert_show_info(param->logic_id, cert, &show_info);
    if (ret != 0) {
        roce_err("show tls ca cfg, rdfx get showinfo fail. (ret=%d)", ret);
        ret = UDA_PARAM_INVALID_ERR;
        goto err;
    }

    TOOL_PRINT_INFO("dev_id:%d, alias:%s, info:\n\t "
                    "subject[%s]\n\t issuer[%s]\n\t start_time[%s GMT]\n\t end_time[%s GMT]",
                    param->phy_id, name,
                    show_info.subject, show_info.issuer, show_info.start_time, show_info.end_time);
err:
    X509_free(cert);
    cert = NULL;
    return ret;
}

STATIC int tool_show_single_tls_ca_cfg(char *alias_name, struct tool_param *param)
{
    int ret;
    unsigned char *ncert_info = NULL;
    struct tool_pars_tls_ca_para para = {0};

    if (tool_check_name_match_format(alias_name, TLS_CA_ALIAS_FORMAT) != 0) {
        roce_err("show tls ca alias [%s] err, the format is not match.", alias_name);
        return UDA_PARAM_INVALID_ERR;
    }

    struct tls_ca_new_certs *tls_ca_cfg = calloc(TLS_CA_SSL_MAX_FLASH_NUM, sizeof(struct tls_ca_new_certs));
    if (tls_ca_cfg == NULL) {
        roce_err("show tls ca cfg, alloc tls_ca_cfg fail. (ret=%d)", -ENOMEM);
        return -ENOMEM;
    }

    ret = dsmi_get_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0) {
        roce_err("when show, get tls ca cfg fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    ret = memcpy_s(para.alias, TLS_CA_SSL_NEW_CERT_ALIAS_LEN, alias_name, strlen(alias_name) + 1);
    if (ret) {
        roce_err("when show, memcpy alias %s fail. (ret=%d)", alias_name, ret);
        ret = UDA_PARAM_INVALID_ERR;
        goto out;
    }
    if (!tool_exist_same_alias_ca(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM, &para)) {
        roce_err("show tls ca cfg [%s] fail, it is not exist.", alias_name);
        ret = UDA_PARAM_TLS_CA_ALIAS_NOT_EXIST;
        goto out;
    }

    ncert_info = tls_ca_cfg[para.exist_cb].certs[para.exist_pos].ncert_info;
    ret = tool_show_tls_ca_cfg_handle(ncert_info, param, tls_ca_cfg[para.exist_cb].alias[para.exist_pos].name);

out:
    (void)memset_s(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs),
                   0, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs));
    free(tls_ca_cfg);
    return ret;
}

STATIC int tool_show_all_tls_ca_cfg(struct tool_param *param)
{
    int ret = 0;
    int cert_count = 0;
    unsigned char *ncert_info = NULL;
    struct tls_ca_new_certs *tls_ca_cfg = calloc(TLS_CA_SSL_MAX_FLASH_NUM, sizeof(struct tls_ca_new_certs));
    if (tls_ca_cfg == NULL) {
        roce_err("show all tls ca cfg, alloc tls_ca_cfg fail. (ret=%d)", -ENOMEM);
        return -ENOMEM;
    }

    ret = dsmi_get_tls_ca_cfg(param->logic_id, 0, tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0) {
        roce_err("when show all, get tls ca cfg fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    for (int i = 0; i < TLS_CA_SSL_MAX_FLASH_NUM; ++i) {
        for (int j = 0; j < TLS_CA_SSL_MAX_NEW_CERT_NUM; ++j) {
            ncert_info = tls_ca_cfg[i].certs[j].ncert_info;
            if (strlen(ncert_info) == 0) {
                cert_count++;
                continue;
            }
            ret = tool_show_tls_ca_cfg_handle(ncert_info, param, tls_ca_cfg[i].alias[j].name);
            if (ret != 0) {
                roce_err("when show all, handle fail. (ret=%d; logic_id=%d; alias name=%s)",
                         ret, param->logic_id, tls_ca_cfg[i].alias[j].name);
            }
        }
    }

    if (cert_count == TLS_CA_SSL_MAX_FLASH_NUM * TLS_CA_SSL_MAX_NEW_CERT_NUM) {
        ret = UDA_PARAM_TLS_CA_MEM_EMPTY;
    }

out:
    (void)memset_s(tls_ca_cfg, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs),
                   0, TLS_CA_SSL_MAX_FLASH_NUM * sizeof(struct tls_ca_new_certs));
    free(tls_ca_cfg);
    return ret;
}

STATIC int tool_show_tls_ca_cfg(int argc, char **argv, struct tool_param *param)
{
    int ret;

    LOG_CONFIG("start to show tls ca cfg of logic_id[%d]", param->logic_id);
    if (argc < TOOL_TLS_CA_CMD_LEN_ONE) {
        roce_err("GET tls ca argc err. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "alias", strlen("alias") + 1) == 0 && (argc == TOOL_TLS_CA_CMD_LEN_ONE + 1)) {
        ret = tool_show_single_tls_ca_cfg(argv[1], param);
    } else if (strncmp(argv[0], "all", strlen("all") + 1) == 0 && (argc == TOOL_TLS_CA_CMD_LEN_ONE)) {
        ret = tool_show_all_tls_ca_cfg(param);
    } else {
        roce_err("show tls ca param for %d_para err.", argc);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_tls_ca_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("tls ca command recv err. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-importcert", strlen("-importcert") + 1)) {
        ret = tool_set_tls_ca_cfg(argc - 1, argv + 1, param);
        if (ret) {
            if (ret != UDA_TOOL_SYS_BUSY_ERR) {
                roce_err("set tls ca cfg failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
            }
            return ret;
        }
    } else if (!strncmp(argv[0], "-deletecert", strlen("-deletecert") + 1)) {
        ret = tool_delete_tls_ca_cfg(argc - 1, argv + 1, param);
        if (ret) {
            if (ret != UDA_TOOL_SYS_BUSY_ERR) {
                roce_err("delete tls ca cfg failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
            }
            return ret;
        }
    } else if (!strncmp(argv[0], "-showcert", strlen("-showcert") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_show_tls_ca_cfg(argc - 1, argv + 1, param);
        if (ret) {
            if (ret != UDA_PARAM_TLS_NO_CERT_ERR) {
                roce_err("show tls ca cfg failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
            }
            return ret;
        }
    } else {
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

static char *g_ca_argv[][TOOL_TLS_CA_IMPORT_CMD_LEN] = {
    {"alias", "2041_CA1", "path", CA_CERT_PATH"Equipment_Root_CA_2041.pem\0"},
    {"alias", "2041_CA2", "path", CA_CERT_PATH"IT_Product_CA_2041.pem\0"},
    {"alias", "2071_CA1", "path", CA_CERT_PATH"RSA_Equipment_Root_CA_2071.pem\0"},
    {"alias", "2071_CA2", "path", CA_CERT_PATH"Computing_RSA-PSS_Equipment_CA_2071.pem\0"},
    {"alias", "2099_CA1", "path", CA_CERT_PATH"RSA-PSS_Equipment_Root_CA_2099.pem\0"},
    {"alias", "2099_CA2", "path", CA_CERT_PATH"Computing_RSA-PSS_Equipment_CA_2099.pem\0"}
};

// 此函数的功能为校验CA证书是否已经被写入flash中。
// 返回值为-EINVAL代表计算本地证书的hash值失败；返回值为-EBADF代表本地证书的hash值与flash中同别名证书的hash值不一致；
// 返回值为-EEXIST代表flash中已有同别名证书；返回值为0代表证书未被写入flash中。
static int tool_tls_ca_check_certs_exist_in_flash(struct tls_ca_new_certs *tls_ca_rec_cfg, int cb_num,
    char* ca_cert_alias, char* ca_cert_path)
{
    unsigned char fingerprint[EVP_MAX_MD_SIZE] = {0};
    for (int i = 0; i < cb_num; ++i) {
        for (int j = 0; j < TLS_CA_SSL_MAX_NEW_CERT_NUM; ++j) {
            if (strcmp(tls_ca_rec_cfg[i].alias[j].name, ca_cert_alias) != 0) {
                continue;
            }
            if (tool_calc_cert_fingerprint(ca_cert_path, fingerprint, EVP_MAX_MD_SIZE) != 0) {
                roce_err("Calc local cert's fingerprint failed.");
                return -EINVAL;
            }
            if (strncmp(tls_ca_rec_cfg[i].alias[j].thumbprint, fingerprint, strlen(fingerprint)) != 0) {
                return -EBADF;
            }
            return -EEXIST;
        }
    }
    return 0;
}

static int tool_cat_tls_ca_cert_path(char Driver_Install_Path_Param[TOOL_TLS_CA_LOCAL_PATH_LEN],
    char ca_cert_path[][TOOL_TLS_CA_LOCAL_PATH_LEN], size_t certs_len)
{
    int ret = 0;
    char real_conf_path[PATH_MAX + 1] = {0};
    for (size_t index = 0; index < certs_len; index++) {
        if (strlen(g_ca_argv[index][TOOL_INDEX_THREE]) + strlen(Driver_Install_Path_Param) + 1 >
            TOOL_TLS_CA_LOCAL_PATH_LEN) {
            roce_err("Path is too long. current path len=%lu",
                strlen(g_ca_argv[index][TOOL_INDEX_THREE]) + strlen(Driver_Install_Path_Param) + 1);
            return UDA_TOOL_INNER_PARAM_ERR;
        }
        ret = sprintf_s(ca_cert_path[index],
                        strlen(g_ca_argv[index][TOOL_INDEX_THREE]) + strlen(Driver_Install_Path_Param) + 1,
                        "%s%s\0", Driver_Install_Path_Param, g_ca_argv[index][TOOL_INDEX_THREE]);
        if (ret < 0) {
            roce_err("Parse tls ca cert path failed. ret=[%d]", ret);
            return ret;
        }

        if (realpath(ca_cert_path[index], real_conf_path) == NULL) {
            roce_err("read path_len[%u] > TOOL_TLS_CA_LOCAL_PATH_LEN or conf_path is invalid, err[%d]",
                     strlen(ca_cert_path[index]), errno);
            return UDA_TOOL_INNER_PARAM_ERR;
        }
    }
    return 0;
}

static int tool_check_tlsca_flash_state(unsigned int logic_id, char ca_cert_path[][TOOL_TLS_CA_LOCAL_PATH_LEN],
    size_t certs_len)
{
    int ret = 0;
    struct tls_ca_new_certs *tls_ca_rec_cfgs = (struct tls_ca_new_certs *)calloc(TLS_CA_SSL_MAX_FLASH_NUM,
        sizeof(struct tls_ca_new_certs));

    if (tls_ca_rec_cfgs == NULL) {
        roce_err("Malloc memory failed");
        return -EINVAL;
    }
    ret = dsmi_get_tls_ca_cfg(logic_id, 0, tls_ca_rec_cfgs, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0) { // 此时已完成写入，flash为空也应当报错
        roce_err("When check again, get tls ca cfg fail. (ret=%d; logic_id=%d)", ret, logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }
    for (size_t index = 0; index < certs_len; index++) {
        ret = tool_tls_ca_check_certs_exist_in_flash(tls_ca_rec_cfgs, TLS_CA_SSL_MAX_FLASH_NUM,
                                                     g_ca_argv[index][1], ca_cert_path[index]);
        // ret=0代表证书未被写入flash，非0则代表写入成功。
        if (ret == 0) {
            LOG_CONFIG("Failed to write tls ca certs alias[%d] of logic_id[%d].", index, logic_id);
            ret = UDA_DSMI_EXE_ERR;
            goto out;
        }
    }
    LOG_CONFIG("Tls ca certs write to flash success. (logic_id=%d)", logic_id);
    ret = 0; // 证书写入成功 但此时ret仍为非0值。
out:
    free(tls_ca_rec_cfgs);
    return ret;
}

static int tool_tls_ca_try_set_flash(struct tool_param *param, struct tls_ca_new_certs *tls_ca_rec_cfg,
    char ca_cert_path[][TOOL_TLS_CA_LOCAL_PATH_LEN], size_t certs_len)
{
    int ret = 0;
    for (size_t index = 0; index < certs_len; index++) {
        char *ca_argv[TOOL_INDEX_FOUR] = {g_ca_argv[index][0], g_ca_argv[index][1],
            g_ca_argv[index][TOOL_INDEX_TWO], ca_cert_path[index]};
        int tmp_ret = tool_tls_ca_check_certs_exist_in_flash(tls_ca_rec_cfg, TLS_CA_SSL_MAX_FLASH_NUM,
                                                             g_ca_argv[index][1], ca_cert_path[index]);
        if (tmp_ret != 0) {
            roce_info("Certs [%s] already in no need to insert... ret=[%d]", g_ca_argv[index][1], ret);
            if (tmp_ret == -EBADF) {
                // 同别名而不同hash则记录日志
                LOG_CONFIG("Cert [%s] not initial ca. (logic_id=%d)", g_ca_argv[index][1], param->logic_id);
            }
            continue;
        }
 
        ret = tool_set_tls_ca_cfg(TOOL_TLS_CA_IMPORT_CMD_LEN, (char**)ca_argv, param);
        if (ret) {
            roce_err("Tls ca recover, import tls ca cfg %d failed. (ret=%d)", index, ret);
            return ret;
        }
    }
    return ret;
}

static int tool_tls_ca_rec_handle(struct tool_param *param)
{
    int ret = 0;
    size_t certs_len = sizeof(g_ca_argv) / (TOOL_TLS_CA_IMPORT_CMD_LEN * sizeof(char*));
    // 在指定路径安装驱动场景下，驱动安装过程中，海思会读取指定的安装路径的绝对路径，并校验长度（最大128）；
    // 校验通过后会进行一次拼接操作，并再次校验长度（最大128） 所以这里不再给用户长路径输入许可，沿用海思规则。
    char Driver_Install_Path_Param[TOOL_TLS_CA_LOCAL_PATH_LEN] = "";
    char ca_cert_path[TOOL_INDEX_SIX][TOOL_TLS_CA_LOCAL_PATH_LEN] = {{0}, {0}, {0}, {0}, {0}, {0}};
    struct tls_ca_new_certs *tls_ca_rec_cfg = (struct tls_ca_new_certs *)calloc(TLS_CA_SSL_MAX_FLASH_NUM,
        sizeof(struct tls_ca_new_certs));

    if (tls_ca_rec_cfg == NULL) {
        roce_err("Malloc memory failed");
        return -EINVAL;
    }

    ret = cfg_inner_read_conf("/etc/ascend_install.info", "Driver_Install_Path_Param",
                              Driver_Install_Path_Param, TOOL_TLS_CA_LOCAL_PATH_LEN);
    if (ret) {
        roce_err("Read tls ca cert local path failed. ret=[%d]", ret);
        goto out;
    }

    ret = tool_cat_tls_ca_cert_path(Driver_Install_Path_Param, ca_cert_path, certs_len);
    if (ret) {
        goto out;
    }
    // 查出所有的证书 为空则直接进行导入
    ret = dsmi_get_tls_ca_cfg(param->logic_id, 0, tls_ca_rec_cfg, TLS_CA_SSL_MAX_FLASH_NUM);
    if (ret != 0 && ret != (-ENOENT)) { // flash为空时，可以写入证书，不能返回错误
        roce_err("When set, get tls ca cfg fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    ret = tool_tls_ca_try_set_flash(param, tls_ca_rec_cfg, ca_cert_path, certs_len);
    if (ret) {
        roce_err("Tls ca try to set certs to flash failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        goto out;
    }
    // 导入完证书后，再次读取flash中的证书进行校验
    ret = tool_check_tlsca_flash_state(param->logic_id, ca_cert_path, certs_len);
    if (ret) {
        roce_err("Re check tls ca certs in flash failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        goto out;
    }

out:
    free(tls_ca_rec_cfg);  // 释放动态分配的内存
    return ret;
}

int tool_cfg_tls_ca_recovery(struct tool_param *param)
{
#ifdef HCCN_TOOL_ADAPT_IPV6
    int ret = 0;
    long int recovered = 0;
    char *tmp_ptr = NULL;
    char tls_ca_recovered[MAX_TLS_LEN] = "";

    ret = drv_get_phy_mach_flag(param->logic_id);
    if (ret != 0 || hccn_check_usr_identify() != 0) {
        roce_info("tls ca does not need to be recovered");
        return 0;
    }
    ret = cfg_read_conf(param->phy_id, "tls_ca_recovered", tls_ca_recovered, sizeof(tls_ca_recovered));
    if (ret != 0 && ret != UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_err("read conf tls ca recovered failed. (ret=%d)", ret);
        return UDA_PARAM_INVALID_ERR;
    }

    if (strlen(tls_ca_recovered) != 0) {
        recovered = strtol(tls_ca_recovered, &tmp_ptr, STR_NUM_BASE);
        if (*tmp_ptr != '\0' || (recovered != 1 && recovered != 0)) {
            roce_err("tls ca recovered must be 0 or 1 with int. (tls_ca_recovered=%s; tail=%s)",
                     tls_ca_recovered, tmp_ptr);
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    }

    // CA证书已经恢复过，无需再恢复
    if (recovered == 1) {
        roce_info("Tls ca do not need recover. (phy_id=%d)", param->phy_id);
        return ret;
    }

    ret = tool_tls_ca_rec_handle(param);
    if (ret != 0) {
        return ret;
    }

    // 恢复成功，则将标志位设置为1
    return cfg_write_conf(param->phy_id, "tls_ca_recovered", "1");
#else
    return 0;
#endif
}
