/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef BUFF_PLATFORM_H
#define BUFF_PLATFORM_H

#include <stdbool.h>
#include "ascend_hal_define.h"

/*
 * ============================================================================
 * Platform-specific buffer event interfaces
 * ============================================================================
 */

/*
 * Return destination engine type for event routing.
 * Called by buff_event module to determine event target (CCPU_HOST or CCPU_DEVICE).
 *
 * @return: Destination engine type (unsigned int to match event_summary.dst_engine field)
 *
 * Usage:
 *   - Called when submitting events to determine target execution engine
 *   - Platform-specific implementation returns appropriate engine type
 */
unsigned int buff_event_get_dst_engine(void);

/*
 * ============================================================================
 * Platform-specific buffer recycle interfaces
 * ============================================================================
 */

/*
 * Set CPU affinity for buff recycle thread.
 * Called during buff recycle thread initialization to bind thread to specific CPU.
 *
 * Usage:
 *   - Called by buff_proc_cache_free thread during startup
 *   - Platform-specific implementation sets appropriate CPU affinity
 *   - On Device platform: binds to CPU 0 for dedicated recycle processing
 *   - On Host platform: empty implementation (no affinity setting needed)
 *
 * Note: This function does not return error status. Failures are logged but do not
 *       affect thread execution.
 */
void buff_recycle_set_thread_affinity(void);

/*
 * ============================================================================
 * Platform-specific buffer allocation interfaces
 * ============================================================================
 */

/*
 * Get the hugepage allocation policy for mbuf.
 * On Host platform: uses runtime feature check to determine policy.
 * On Device platform: uses compile-time configuration to determine policy.
 *
 * @return: BUFF_SP_HUGEPAGE_PRIOR if hugepage is supported, BUFF_SP_NORMAL otherwise
 */
unsigned long buff_get_mbuf_hugepage_policy(void);

/*
 * Check if hugepage feature is supported for memzone configuration.
 * On Host platform: queries runtime feature bitmap.
 * On Device platform: returns compile-time configuration result.
 *
 * @return: true if hugepage is supported, false otherwise
 */
bool buff_mz_has_hugepage(void);

/*
 * Check if dvpp memzone is NOT supported.
 * On Host platform: queries runtime feature bitmap.
 * On Device platform: returns compile-time configuration result.
 *
 * @return: true if dvpp memzone is not supported, false otherwise
 */
bool buff_mz_has_no_dvpp(void);

/*
 * Initialize platform-specific features.
 * On Host platform: queries runtime feature bitmap via buff_dev_feature_init_all().
 * On Device platform: no-op, features are determined at compile time.
 *
 * @return: DRV_ERROR_NONE on success, error code otherwise
 */
int buff_platform_feature_init(void);

#endif /* BUFF_PLATFORM_H */
