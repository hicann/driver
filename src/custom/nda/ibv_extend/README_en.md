# ibv_extend - NDA (NPUDirect Async) function extension library based on ibverbs

## Overview

`ibv_extend` component is an extension of standard RDMA verbs interface, specifically used to support direct-drive RDMA communication in NDA (NPUDirect Async) scenarios. This library extends standard RDMA verbs interface, allowing management of rdma device related resources on NPU side, supporting direct data transmission between NPU memory and network card.

## Directory Structure

```
docs/zh/nda/ibv_extend/
├── NDA IBV_EXTEND Extension Library Development Guide   # Development guide
src/custom/nda/ibv_extend/
├── ibv_extend.h          # Public header file, defines extension interfaces and data structures
├── ibv_extend.c          # Core implementation file
├── config.h.in           # Configuration file template
├── CMakeLists.txt        # CMake build configuration
├── build.sh              # Compilation script
└── README.md             # This document
```

## Development Guide

> For detailed installation, usage, and API documentation, refer to [NDA IBV_EXTEND Extension Library Development Guide](../../../../docs/en/nda/ibv_extend/NDA_IBV_EXTEND_Extension_Library_Development_Guide.md)
