# adp_mlx - mlx5 driver adapter loaded by ibv_extend at runtime

## Overview

`adp_mlx` is a driver adapter component for mlx5 series network cards, serving as a runtime dependency of the `ibv_extend` extension library.

```
┌─────────────────────────────────┐
│         Application              │
└───────────────┬─────────────────┘
                │
┌───────────────▼─────────────────┐
│     ibv_extend library (.so)    │
└───────────────┬─────────────────┘
                │
┌───────────────▼─────────────────┐
│     adp_mlx adapter (.so)       │
└───────────────┬─────────────────┘
                │
┌───────────────▼─────────────────┐
│       mlx5 standard driver       │
└─────────────────────────────────┘
```

## Directory Structure

```
src/custom/nda/
├── ibv_extend/              # ibv_extend extension library (provides ibv_extend.h header)
└── adp_mlx/                 # This component
    ├── adp_mlx.c            # Driver implementation source file
    ├── CMakeLists.txt       # CMake build configuration
    ├── build.sh             # Compilation script
    ├── README.md            # Chinese documentation
    └── README_en.md         # This document
```

## Dependencies

| Dependency | Purpose |
|------------|---------|
| libibverbs (rdma-core) | Standard verbs header and interfaces |
| libmlx5 | mlx5 vendor direct verbs interfaces |
| ibv_extend.h | Extension interface definitions (sibling directory `ibv_extend/`) |

## Build

### Prerequisites

- cmake, gcc, make
- rdma-core (includes libibverbs and libmlx5)

### Using build.sh

```bash
# Use system-installed libibverbs / libmlx5
bash build.sh

# Specify rdma-core build directory (containing include/ and lib/ subdirectories)
bash build.sh -b=/path/to/rdma-core/build

# Specify ibv_extend build directory (links against libibv_extend.so)
bash build.sh -b=/path/to/rdma-core/build -e=/path/to/ibv_extend/build
```

### Build Output

```
output/lib/libadp_mlx.so
```

## Usage

### 1. Install the driver library

Copy the build output to the `ibv_extend` driver search path (typically `/usr/local/lib64` or `/usr/lib64`):

```bash
cp output/lib/libadp_mlx.so /usr/local/lib64/
ldconfig
```

### 2. Configure ibv_extend driver loading list

**Option A: Environment variable**

```bash
export IBV_EXTEND_DRIVERS=adp_mlx
```

**Option B: Configuration file**

```bash
# Create /etc/libibverbs_extend.d/adp_mlx.conf with content:
driver adp_mlx
```
