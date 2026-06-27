# 查询帮助信息

## 产品支持情况

<!-- npu="950" id1 -->

- Ascend 950PR/Ascend 950DT：支持
<!-- end id1 -->
<!-- npu="A3" id2 -->
- Atlas A3 训练系列产品/Atlas A3 推理系列产品：支持
<!-- end id2 -->
<!-- npu="910b" id3 -->
- Atlas A2 训练系列产品/Atlas A2 推理系列产品：支持
<!-- end id3 -->
<!-- npu="310b" id4 -->
- Atlas 200I/500 A2 推理产品：支持
<!-- end id4 -->
<!-- npu="310p" id5 -->
- Atlas 推理系列产品：支持
<!-- end id5 -->
<!-- npu="910" id6 -->
- Atlas 训练系列产品：支持
<!-- end id6 -->

## 命令功能

查询msnpureport工具帮助信息。

## 注意事项

无。

## 命令格式

查询msnpureport工具帮助信息：

```sh
msnpureport help
```

查询msnpureport工具config子命令的帮助信息：

```sh
msnpureport config --help
```

查询msnpureport工具report子命令的帮助信息：

```sh
msnpureport report --help
```

## 参数说明

无

## 使用示例

1. 登录Host侧服务器。
2. 执行以下命令。

    ```sh
    msnpureport help
    ```

## 输出说明

以下输出仅为举例，因版本不同略有差异，请以实际输出为准。

```sh
Usage:  msnpureport <subcommand> [OPTIONS]
subcommand:
  config               configure settings and queries
  report               get device log
  help                 get help information
  version              get version information

get options information by msnpureport <subcommand> --help
Example:
        msnpureport config --help
```
