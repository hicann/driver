# 设置icache bit翻转检验范围

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
- Atlas 训练系列产品：不支持
<!-- end id6 -->

## 命令功能

设置icache bit翻转检验范围，以便定位算子问题。

## 注意事项

- 该命令仅支持root用户执行。
- 容器场景下，命令执行时需要添加--docker参数，且需要配置msnpureport环境变量，示例如下：

    ```sh
    export PATH=/usr/local/Ascend/driver/tools:$PATH
    ```

- 昇腾AI应用进程运行过程中不建议执行该命令，否则可能会导致应用进程运行异常，建议应用进程退出后执行该命令。

## 命令格式

```sh
msnpureport config --set [--device <deviceId>] --icachecheck <value>
```

## 参数说明

|参数|可选/必选|说明|
|--|--|--|
|-d <deviceId>或--device <deviceId>|可选|指定Device ID（逻辑ID），默认为0。<br>部分产品可能存在SMP工作模式，即多个Device共用一个OS组成一组，此时指定一个OS内的任意Device ID时，会导出该OS下的所有Device日志。|
|--icachecheck <value>|必选|设置参数值，取值范围：[0, 131072]，单位KB。例如将该参数值设置为128，则校验从出错PC往前128K到出错PC往后128K的icache与GM（Global Memory）是否一致。<br>在设置该参数值前，可先参见查询Device维测配置信息获取当前环境上的icache翻转校验范围（即Icache check range字段值）。|

## 使用示例

1. 登录Host侧服务器。
2. 执行以下命令。

    ```sh
    msnpureport config --set --device 0 --icachecheck 128
    ```
