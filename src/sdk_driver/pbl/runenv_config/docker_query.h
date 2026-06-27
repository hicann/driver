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
#ifndef _DOCKER_QUERY_H
#define _DOCKER_QUERY_H

#include "ka_task_pub.h"

bool check_in_host_mach(void);
bool run_in_normal_docker(void);
bool run_in_admin_docker(void);
bool run_in_docker(void);
int dbl_host_pid_to_container_pid(ka_pid_t host_pid, ka_pid_t *container_pid);

#endif
