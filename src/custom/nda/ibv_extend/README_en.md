# ibv_extend - NDA(NPUDirect Async) function extension library based on ibverbs

## Overview

The `ibv_extend` component is an extension of standard RDMA verbs interfaces, specifically designed to support direct-drive RDMA communication in NDA (NPUDirect Async) scenarios. This library extends standard RDMA verbs interfaces, allowing rdma device-related resources to be managed on the NPU side, supporting direct data transfer between NPU memory and network cards.

## Directory Structure

```
docs/zh/nda/ibv_extend/
├── NDA IBV_EXTEND Extension Library Development Guide   # Development guide
src/custom/nda/ibv_extend/
├── ibv_extend.h          # Public header file, defines extension interfaces and data structures
├── ibv_extend.c          # Core implementation file
├── config.h.in           # Configuration file template
├── CMakeLists.txt        # CMake build configuration
├── build.sh              # Build script
└── README.md             # This document
```

## Development Guide

> For detailed installation, usage, and API instructions, refer to the [NDA IBV_EXTEND Extension Library Development Guide](../../../../docs/en/nda/ibv_extend/NDA_IBV_EXTEND_Extension_Library_Development_Guide.md).