# ibv_extend - NDA(NPUDirect Async) function extension library based on ibverbs

## 概述

`ibv_extend` 组件是标准RDMA verbs接口的扩展，专门用于支持NDA（NPUDirect Async）场景下的直驱RDMA通信。该库扩展了标准 RDMA verbs 接口，允许在 NPU 侧管理 rdma 设备相关资源，支撑 NPU 内存与网卡之间的直接数据传输。

## 目录结构

```
docs/zh/nda/ibv_extend/
├── NDA IBV_EXTEND 扩展库开发指南   # 开发指南
src/custom/nda/ibv_extend/
├── ibv_extend.h          # 公共头文件，定义扩展接口和数据结构
├── ibv_extend.c          # 核心实现文件
├── config.h.in           # 配置文件模板
├── CMakeLists.txt        # CMake 构建配置
├── build.sh              # 编译脚本
└── README.md             # 本文档
```

## 开发指南

> 详细的安装、使用和API说明请参考 [NDA IBV_EXTEND 扩展库开发指南](../../../../docs/zh/nda/ibv_extend/NDA_IBV_EXTEND_Extension_Library_Development_Guide.md)
