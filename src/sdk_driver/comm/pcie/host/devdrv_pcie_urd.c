/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "pbl/pbl_feature_loader.h"
#include "pbl/pbl_urd.h"
#include "pbl_urd_main_cmd_def.h"
#include "pbl_urd_sub_cmd_common.h"
#include "devdrv_pcie_link_info.h"
#include "devdrv_pcie_urd.h"

BEGIN_DMS_MODULE_DECLARATION(ASCEND_PCIE_CMD_NAME)
BEGIN_FEATURE_COMMAND()
ADD_FEATURE_COMMAND(ASCEND_PCIE_CMD_NAME, DMS_GET_GET_DEVICE_INFO_CMD, ZERO_CMD,
                    "main_cmd=0x37,sub_cmd=0x0", /* DMS_MAIN_CMD_PCIE, DMS_SUBCMD_GET_PCIE_LINK_INFO */
                    NULL, DMS_ACC_NOT_LIMIT_USER | DMS_ENV_NOT_NORMAL_DOCKER | DMS_VDEV_NOTSUPPORT,
                    devdrv_get_pcie_link_bandwidth)
END_FEATURE_COMMAND()
END_MODULE_DECLARATION()

int devdrv_init_urd(void)
{
    CALL_INIT_MODULE(ASCEND_PCIE_CMD_NAME);
    return 0;
}

void devdrv_uninit_urd(void)
{
    CALL_EXIT_MODULE(ASCEND_PCIE_CMD_NAME);
}

DECLAER_FEATURE_AUTO_INIT(devdrv_init_urd, FEATURE_LOADER_STAGE_5);
DECLAER_FEATURE_AUTO_UNINIT(devdrv_uninit_urd, FEATURE_LOADER_STAGE_5);