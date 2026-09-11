# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
#
# File Name     : CMakeLists.txt
# Description   : Build configuration for adp_mlx driver library

cmake_minimum_required(VERSION 3.13)
project(adp_mlx VERSION 1.0.0 LANGUAGES C)

# 设置C标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ibv_extend源码路径(同级目录)
set(IBV_EXTEND_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ibv_extend")

# 根据系统架构自动选择库目录
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    if(EXISTS "/usr/local/lib64")
        set(SYSTEM_LIB_DIR /usr/local/lib64)
    elseif(EXISTS "/usr/lib64")
        set(SYSTEM_LIB_DIR /usr/lib64)
    elseif(EXISTS "/usr/local/lib")
        set(SYSTEM_LIB_DIR /usr/local/lib)
    else()
        set(SYSTEM_LIB_DIR /usr/lib)
    endif()
else()
    if(EXISTS "/usr/local/lib")
        set(SYSTEM_LIB_DIR /usr/local/lib)
    else()
        set(SYSTEM_LIB_DIR /usr/lib)
    endif()
endif()

message(STATUS "System architecture: ${CMAKE_SYSTEM_PROCESSOR}")

# 查找ibverbs依赖
if(DEFINED LIBIBVERBS_BUILD_DIR)
    set(IBVERBS_INCLUDE_DIRS ${LIBIBVERBS_BUILD_DIR}/include)
    set(IBVERBS_LIBRARY_DIRS ${LIBIBVERBS_BUILD_DIR}/lib)
    set(IBVERBS_LIBRARIES ibverbs)
    set(MLX5_LIBRARIES mlx5)
    message(STATUS "Using manually specified libibverbs paths:")
    message(STATUS "  Include: ${IBVERBS_INCLUDE_DIRS}")
    message(STATUS "  Library: ${IBVERBS_LIBRARY_DIRS}")
else()
    find_package(PkgConfig)
    if(PKG_CONFIG_FOUND)
        pkg_check_modules(IBVERBS libibverbs)
        pkg_check_modules(MLX5 libmlx5)
    endif()
    if(NOT IBVERBS_FOUND)
        set(IBVERBS_INCLUDE_DIRS "")
        set(IBVERBS_LIBRARY_DIRS "${SYSTEM_LIB_DIR}")
        set(IBVERBS_LIBRARIES ibverbs)
        set(MLX5_LIBRARIES mlx5)
        message(STATUS "Using system default libibverbs")
    else()
        message(STATUS "Found libibverbs via pkg-config")
        if(NOT MLX5_FOUND)
            set(MLX5_LIBRARIES mlx5)
        else()
            message(STATUS "Found libmlx5 via pkg-config")
        endif()
    endif()
endif()

# 查找ibv_extend依赖(用于编译时头文件和运行时符号解析)
if(DEFINED IBV_EXTEND_BUILD_DIR)
    set(IBV_EXTEND_INCLUDE_DIR "${IBV_EXTEND_SRC_DIR}")
    set(IBV_EXTEND_LIBRARY_DIR "${IBV_EXTEND_BUILD_DIR}")
    set(IBV_EXTEND_LIBRARIES ibv_extend)
    message(STATUS "Using manually specified ibv_extend build dir: ${IBV_EXTEND_BUILD_DIR}")
else()
    set(IBV_EXTEND_INCLUDE_DIR "${IBV_EXTEND_SRC_DIR}")
    set(IBV_EXTEND_LIBRARY_DIR "")
    set(IBV_EXTEND_LIBRARIES "")
    message(STATUS "Using ibv_extend headers from source: ${IBV_EXTEND_INCLUDE_DIR}")
endif()

# 添加库搜索路径
if(EXISTS "${IBVERBS_LIBRARY_DIRS}")
    link_directories(${IBVERBS_LIBRARY_DIRS})
endif()

if(DEFINED MLX5_LIBRARY_DIRS AND EXISTS "${MLX5_LIBRARY_DIRS}")
    link_directories(${MLX5_LIBRARY_DIRS})
endif()

if(DEFINED IBV_EXTEND_BUILD_DIR AND EXISTS "${IBV_EXTEND_LIBRARY_DIR}")
    link_directories(${IBV_EXTEND_LIBRARY_DIR})
endif()

# 定义源文件
set(ADP_MLX_SOURCES
    adp_mlx.c
)

# 创建共享库
add_library(adp_mlx SHARED
    ${ADP_MLX_SOURCES}
)

# 设置库版本号
set_target_properties(adp_mlx PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME "adp_mlx"
    PREFIX "lib"
)

# 设置包含目录
target_include_directories(adp_mlx PRIVATE
    ${IBV_EXTEND_INCLUDE_DIR}
)

if(EXISTS "${IBVERBS_INCLUDE_DIRS}")
    target_include_directories(adp_mlx SYSTEM PRIVATE ${IBVERBS_INCLUDE_DIRS})
endif()

if(DEFINED MLX5_INCLUDE_DIRS AND EXISTS "${MLX5_INCLUDE_DIRS}")
    target_include_directories(adp_mlx SYSTEM PRIVATE ${MLX5_INCLUDE_DIRS})
endif()

# 链接库
# ibv_extend: 运行时由ibv_extend通过dlopen加载本驱动, 驱动构造函数调用
#              verbs_register_driver_extend() (定义在ibv_extend中), 因此需要链接ibv_extend
#              以便动态链接器解析符号
# mlx5: 提供mlx5dv_modify_qp_udp_sport等vendor direct verbs接口
if(DEFINED IBV_EXTEND_BUILD_DIR AND EXISTS "${IBV_EXTEND_LIBRARY_DIR}")
    target_link_libraries(adp_mlx PRIVATE
        ${IBV_EXTEND_LIBRARIES}
        ${IBVERBS_LIBRARIES}
        ${MLX5_LIBRARIES}
    )
else()
    target_link_libraries(adp_mlx PRIVATE
        ${IBVERBS_LIBRARIES}
        ${MLX5_LIBRARIES}
    )
endif()

# 链接选项
if(DEFINED IBVERBS_LDFLAGS AND NOT "${IBVERBS_LDFLAGS}" STREQUAL "")
    target_link_options(adp_mlx PRIVATE ${IBVERBS_LDFLAGS})
endif()

# 添加编译选项
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(adp_mlx PRIVATE
        -Wall
        -Wextra
        -fPIC
        -fvisibility=hidden
    )

    # 根据构建类型设置不同选项
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(adp_mlx PRIVATE
            -g
            -O0
            -DDEBUG
        )
        target_compile_definitions(adp_mlx PRIVATE DEBUG)
    else()
        target_compile_options(adp_mlx PRIVATE
            -O2
            -Werror
            -DNDEBUG
        )
    endif()
endif()

# 安装规则
install(TARGETS adp_mlx
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
