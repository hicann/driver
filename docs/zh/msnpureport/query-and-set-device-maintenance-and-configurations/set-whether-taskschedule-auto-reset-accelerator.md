# 设置TaskSchedule是否自动复位加速器

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

设置TaskSchedule是否自动复位加速器，以便导出更详细、更精准的寄存器信息定位问题，但配置后会影响执行性能。

## 注意事项

- 该命令仅支持root用户执行。
- 容器场景下，命令执行时需要添加--docker参数，且需要配置msnpureport环境变量，示例如下：

  ```sh
  export PATH=/usr/local/Ascend/driver/tools:$PATH
  ```

- 昇腾AI应用进程运行过程中不建议执行该命令，否则可能会导致应用进程运行异常，建议应用进程退出后执行该命令。
<!-- npu="A3,910b" id7 -->

- 针对以下产品，AI Core问题定位场景下，执行本命令设置不自动复位加速器后，需再次复现问题，然后再参见[单次导出Device侧系统类日志和其他维测信息](../export-device-logs-and-files/export-device-logs-and-files-at-one-time.md)中的内容使用`--type 2`参数，可导出更详细、更精准的寄存器信息，辅助定位问题。
  <!-- npu="910b" id8 -->
  - Atlas A2 训练系列产品/Atlas A2 推理系列产品
  <!-- end id8 -->
  <!-- npu="A3" id9 -->
  - Atlas A3 训练系列产品/Atlas A3 推理系列产品
  <!-- end id9 -->
  <!-- end id7 -->
  
## 命令格式

```sh
msnpureport config --set [--device <deviceId>] --accelerator_recover <recoverflag>
```

## 参数说明

|参数|可选/必选|说明|
|--|--|--|
|-d <deviceId>或--device <deviceId>|可选|指定Device ID（逻辑ID），默认为0。<br>部分产品可能存在SMP工作模式，即多个Device共用一个OS组成一组，此时指定一个OS内的任意Device ID时，会导出该OS下的所有Device日志。|
|--accelerator_recover <recoverflag>|必选|设置加速器是否复位，取值说明如下：<br>- 0：TaskSchedule不自动复位加速器<br>设置为该值、完成问题定位后，必须重启运行环境恢复AI Core业务，重启环境后，默认自动复位加速器。<br>- 1：TaskSchedule自动复位加速器，默认该选项|

## 使用示例

1. 登录Host侧服务器。
2. 执行以下命令。

    ```sh
    msnpureport config --set --device 1 --accelerator_recover 0
    ```
