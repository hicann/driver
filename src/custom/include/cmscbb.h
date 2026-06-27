/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef CMSCBB_H
#define CMSCBB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========== Platform type definitions ========== */

#if defined(__LP64__) || defined(__64BIT__)
typedef unsigned int        CVB_UINT32;
typedef int                 CVB_INT32;
typedef unsigned long long  CVB_ULONG;
typedef long long           CVB_LONG;
#else
typedef unsigned long       CVB_UINT32;
typedef long                CVB_INT32;
typedef unsigned long       CVB_ULONG;
typedef long                CVB_LONG;
#endif

typedef unsigned char       CVB_BYTE;
typedef char                CVB_CHAR;
typedef CVB_UINT32          CVB_BOOL;
typedef int                 CVB_INT;
typedef unsigned int        CVB_UINT;
typedef size_t              CVB_SIZE_T;

#if defined(_MSC_VER)
typedef unsigned __int64    CVB_UINT64;
typedef __int64             CVB_INT64;
typedef uintptr_t           CVB_PTR;
#else
#   if defined(__linux__)
#       if !defined(__KERNEL__)
#           include <stdint.h>
#       endif
typedef uintptr_t           CVB_PTR;
#   else
typedef CVB_ULONG           CVB_PTR;
#       if defined(__vxworks__)
#           if !defined(VXWORKS_VERSION) && !defined(__INCvxTypesh)
#               error "not able to identify vxworks platform"
#           endif
#       endif
#       if defined(VXWORKS_VERSION) || defined(__INCvxTypesh)
#           include <vxWorks.h>
#       else
#           include <inttypes.h>
#       endif
#   endif
#   if (defined(__GNUC__) && (__GNUC__ < 3))
typedef unsigned long long  CVB_UINT64;
typedef long long           CVB_INT64;
#   else
typedef uint64_t            CVB_UINT64;
typedef int64_t             CVB_INT64;
#   endif
#endif

/* ========== Constants ========== */

#ifndef CVB_SUCCESS
#define CVB_SUCCESS     0
#endif
#ifndef CVB_NULL
#define CVB_NULL        0
#endif
#ifndef CVB_TRUE
#define CVB_TRUE        ((CVB_BOOL)1)
#endif
#ifndef CVB_FALSE
#define CVB_FALSE       ((CVB_BOOL)0)
#endif
#ifndef CVB_VOID
#define CVB_VOID        void
#endif

#define CMSCBB_HASH_SHA256  43
#define CMSCBB_HASH_SHA384  44
#define CMSCBB_HASH_SHA512  45

#define MAX_ISSUER_NAME_LENGTH  256
#define CMSCBB_MAX_SN_LEN      32
#define MAX_CRL_SUPPORT         16
#define MAX_CERT_SUPPORT        16
#define MAX_REVOKE_LIST_NUM     5

/* ========== Opaque handles ========== */

typedef CVB_VOID *CMSCBB_VRF_CTX;
typedef void *CMSCBB_CRYPTO_MD_CTX;
typedef CVB_UINT32 CMSCBB_ERROR_CODE;

/* ========== Structures ========== */

typedef struct CmscbbCtxCreateParamsSt {
    CVB_SIZE_T st_size;
#if CMSCBB_NEED_RELOCATE
    CVB_ULONG relocBase;
#endif
    CVB_CHAR resv[64];
} CmscbbCtxCreateParams;

typedef enum CmscbbCrlPeriodStat {
    SCPS_SAME = 0,
    SCPS_NEW  = 1,
    SCPS_OLD  = 2,
    SCPS_MIX  = 3,
} CmscbbCrlPeriodStat;

typedef struct CmscbbSerialNumSt {
    CVB_BYTE sn[CMSCBB_MAX_SN_LEN];
    CVB_UINT32 snLenth;
} CmscbbSerialNum;

typedef struct CmscbbRevokeListSt {
    CmscbbSerialNum *snList;
    CVB_UINT32 revokeCount;
} CmscbbRevokeList;

typedef struct CmscbbCrlInfoSt {
#if CMSCBB_STRICT_CHECK
    CVB_SIZE_T st_size;
#endif
    int valid;
#if CMSCBB_BYTE_ALIGN
    CVB_BYTE resv0[4];
#endif
    CVB_INT64 updateTime;
    CVB_INT64 validUntil;
    CVB_CHAR issuer[MAX_ISSUER_NAME_LENGTH];
    CmscbbSerialNum issuerSn;
    CmscbbRevokeList revokeList;
    CVB_CHAR resv[60];
} CmscbbCrlInfo;

typedef struct CmscbbCrlBundleInfoSt {
    CVB_SIZE_T st_size;
    CmscbbCrlInfo *crlInfoList[MAX_CRL_SUPPORT];
    CVB_INT crlCount;
    CVB_CHAR resv[64];
} CmscbbCrlBundleInfo;

/* ========== API ========== */

CMSCBB_ERROR_CODE CmscbbVerifyCreateCtx(CMSCBB_VRF_CTX *ctx,
    const CmscbbCtxCreateParams *params);

CMSCBB_ERROR_CODE CmscbbVrfCtxFree(CMSCBB_VRF_CTX ctx);

CMSCBB_ERROR_CODE CmscbbVerifyDetachSignatureBegin(CMSCBB_VRF_CTX ctx, const CVB_BYTE *signature, CVB_UINT32 sigLen);

CMSCBB_ERROR_CODE CmscbbVerifyDetachSignatureUpdate(CMSCBB_VRF_CTX ctx,
    const CVB_BYTE *content, CVB_INT32 contentLength);

CMSCBB_ERROR_CODE CmscbbVerifyDetachSignatureFinal(CMSCBB_VRF_CTX ctx, CVB_INT32 *res);

CMSCBB_ERROR_CODE CmscbbVerifyAddCert(CMSCBB_VRF_CTX ctx, const CVB_BYTE *cert, CVB_UINT32 certLength);

CMSCBB_ERROR_CODE CmscbbVerifyAddCrlFile(CMSCBB_VRF_CTX ctx, const CVB_CHAR *crlFile);

CMSCBB_ERROR_CODE CmscbbVerifyAddCrl(CMSCBB_VRF_CTX ctx,
    const CVB_BYTE *crl, CVB_UINT32 crlLength);

CMSCBB_ERROR_CODE CmscbbDecodeCrlFile(CMSCBB_VRF_CTX ctx, const CVB_CHAR *crlFile, CmscbbCrlBundleInfo **result);

CMSCBB_ERROR_CODE CmscbbDecodeCrl(CMSCBB_VRF_CTX ctx,
    const CVB_BYTE *crl, CVB_UINT32 crlLength, CmscbbCrlBundleInfo **result);

CMSCBB_ERROR_CODE CmscbbCrlFree(CMSCBB_VRF_CTX ctx, CmscbbCrlBundleInfo *crlBundle);

CMSCBB_ERROR_CODE CmscbbCrlCompare(CMSCBB_VRF_CTX ctx, const CmscbbCrlBundleInfo *crlToUpdate,
    const CmscbbCrlBundleInfo *crlOnDevice, CmscbbCrlPeriodStat *stat);

#ifdef __cplusplus
}
#endif

#endif /* CMSCBB_H */
