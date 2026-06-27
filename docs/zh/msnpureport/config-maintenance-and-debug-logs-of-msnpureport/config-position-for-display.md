# 配置msnpureport工具维测日志展示位置

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

通过该命令可配置msnpureport工具维测日志展示位置。

## 注意事项

- 该命令仅支持root用户执行。
- 容器场景下，命令执行时需要添加--docker参数，且需要配置msnpureport环境变量，示例如下：

    ```sh
    export PATH=/usr/local/Ascend/driver/tools:$PATH
    ```

- 该命令仅控制`msnpureport report [options]`命令执行过程中的日志展示位置。
- 由于docker中无法查看syslog日志，建议docker中设置--print 1。

## 命令格式

```sh
msnpureport report --print <value>
```

## 参数说明

|参数|可选/必选|说明|
|--|--|--|
|--print <value>|必选|设置msnpureport工具维测日志展示位置，取值如下：<br>-0：打印在Host侧日志文件中，默认是0。 <br>aarch64架构：/var/log/messages <br>x86_64架构：/var/log/syslog <br>-1：打屏展示。|

## 使用示例

1. 登录Host侧服务器。
2. 执行以下命令。

    ```sh
    msnpureport report --print 1
    ```

## 输出说明

无。
