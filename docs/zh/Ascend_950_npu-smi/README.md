# 命令列表

## 信息查询（info）

- [查询帮助](./Ascend_950_npu-smi/查询帮助.md)
- [查询npu-smi工具版本](./Ascend_950_npu-smi/查询npu-smi工具版本.md)
- [信息查询帮助](./Ascend_950_npu-smi/信息查询帮助.md)
- [查询基本信息](./Ascend_950_npu-smi/查询基本信息.md)
- [查询设备映射关系信息](./Ascend_950_npu-smi/查询设备映射关系信息.md)
- [查询所有NPU设备](./Ascend_950_npu-smi/查询所有NPU设备.md)
- [查询NPU的详细信息](./Ascend_950_npu-smi/查询NPU的详细信息.md)
- [查询设备常用信息](./Ascend_950_npu-smi/查询设备常用信息.md)
- [查询设备闪存信息](./Ascend_950_npu-smi/查询设备闪存信息.md)
- [查询设备内存信息](./Ascend_950_npu-smi/查询设备内存信息.md)
- [查询设备监测数据](./Ascend_950_npu-smi/查询设备监测数据.md)
- [查询设备统计信息](./Ascend_950_npu-smi/查询设备统计信息.md)
- [查询设备温度](./Ascend_950_npu-smi/查询设备温度.md)
- [查询设备功率](./Ascend_950_npu-smi/查询设备功率.md)
- [查询设备电压](./Ascend_950_npu-smi/查询设备电压.md)
- [查询设备健康状态](./Ascend_950_npu-smi/查询设备健康状态.md)
- [查询设备告警信息](./Ascend_950_npu-smi/查询设备告警信息.md)
- [查询设备ECC错误计数](./Ascend_950_npu-smi/查询设备ECC错误计数.md)
- [查询设备ECC启用状态](./Ascend_950_npu-smi/查询设备ECC启用状态.md)
- [查询设备传感器信息](./Ascend_950_npu-smi/查询设备传感器信息.md)
- [查询设备系统时间](./Ascend_950_npu-smi/查询设备系统时间.md)
- [查询KMSAgent进程的服务状态](./Ascend_950_npu-smi/查询KMSAgent进程的服务状态.md)
- [查询设备进程占用内存](./Ascend_950_npu-smi/查询设备进程占用内存.md)
- [查询指定物理ID对应的NPU ID、Slot ID和Chip ID信息](./Ascend_950_npu-smi/查询指定物理ID对应的NPU-ID-Slot-ID和Chip-ID信息.md)
- [查询多NPU的拓扑结构](./Ascend_950_npu-smi/查询多NPU的拓扑结构.md)
- [查询设备超节点信息](./Ascend_950_npu-smi/查询设备超节点信息.md)
- [查询设备die间SIO状态](./Ascend_950_npu-smi/查询设备die间SIO状态.md)
- [查询日志落盘持久化配置信息](./Ascend_950_npu-smi/查询日志落盘持久化配置信息.md)
- [查询设备的PCIe误码计数](./Ascend_950_npu-smi/查询设备的PCIe误码计数.md)

## 设置功能（set）

- [设置功能帮助](./Ascend_950_npu-smi/设置功能帮助.md)
- [复位NPU](./Ascend_950_npu-smi/复位NPU.md)
- [清除设备ECC错误计数](./Ascend_950_npu-smi/清除设备ECC错误计数.md)
- [设置KMSAgent进程的服务状态](./Ascend_950_npu-smi/设置KMSAgent进程的服务状态.md)
- [设置日志落盘持久化功能开关模式](./Ascend_950_npu-smi/设置日志落盘持久化功能开关模式.md)
- [设置持续收集所有设备的日志](./Ascend_950_npu-smi/设置持续收集所有设备的日志.md)
- [设置结束日志进程并清除配置](./Ascend_950_npu-smi/设置结束日志进程并清除配置.md)

## 升级功能（upgrade）

- [升级功能帮助](./Ascend_950_npu-smi/升级功能帮助.md)
- [查询固件版本信息](./Ascend_950_npu-smi/查询固件版本信息.md)
- [升级固件](./Ascend_950_npu-smi/升级固件.md)
  
## 清除功能（clear）

- [清除功能帮助](./Ascend_950_npu-smi/清除功能帮助.md)
- [清除设备的ECC错误计数](./Ascend_950_npu-smi/清除设备的ECC错误计数.md)

## 证书管理

- [获取CSR](./Ascend_950_npu-smi/获取CSR.md)
- [预置/更新TLS证书](./Ascend_950_npu-smi/预置-更新TLS证书.md)
- [查询证书信息](./Ascend_950_npu-smi/查询证书信息.md)
- [查询证书过期阈值](./Ascend_950_npu-smi/查询证书过期阈值.md)
- [设置证书过期阈值](./Ascend_950_npu-smi/设置证书过期阈值.md)
- [恢复证书默认过期阈值](./Ascend_950_npu-smi/恢复证书默认过期阈值.md)

# 命令说明

## 概述<a name="section1243813351818"></a>

本文档详细地描述了npu-smi工具的信息查询、设置功能、工具版本查询以及帮助等命令，并提供了具体的命令操作指导。

本文档适用于：Atlas 350 加速卡。

## 接口部署场景说明<a name="section185124551191"></a>

- 如果部分部署场景在本文档的相关命令或接口描述中未提及，则表明该产品不涉及此场景，当前未规划。
- 本文档中“不同部署场景下的支持情况”表中的Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。

**表 1**  部署场景分类定义及说明

<a name="table6103615017"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002373372809_row63157411612"><th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000002373372809_p1531594115110"><a name="zh-cn_topic_0000002373372809_p1531594115110"></a><a name="zh-cn_topic_0000002373372809_p1531594115110"></a>部署场景分类</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000002373372809_p231514119116"><a name="zh-cn_topic_0000002373372809_p231514119116"></a><a name="zh-cn_topic_0000002373372809_p231514119116"></a>子场景分类</p>
</th>
<th class="cellrowborder" valign="top" width="62.496249624962495%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000002373372809_p83158416110"><a name="zh-cn_topic_0000002373372809_p83158416110"></a><a name="zh-cn_topic_0000002373372809_p83158416110"></a>子场景说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002373372809_row631511411411"><td class="cellrowborder" rowspan="3" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p83151741912"><a name="zh-cn_topic_0000002373372809_p83151741912"></a><a name="zh-cn_topic_0000002373372809_p83151741912"></a>物理机场景<sup id="zh-cn_topic_0000002373372809_sup124511238422"><a name="zh-cn_topic_0000002373372809_sup124511238422"></a><a name="zh-cn_topic_0000002373372809_sup124511238422"></a>a</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p1931510414116"><a name="zh-cn_topic_0000002373372809_p1931510414116"></a><a name="zh-cn_topic_0000002373372809_p1931510414116"></a>物理机场景（裸机）</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002373372809_p203156413117"><a name="zh-cn_topic_0000002373372809_p203156413117"></a><a name="zh-cn_topic_0000002373372809_p203156413117"></a>NPU设备直接在物理机（裸机）上使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row33150417118"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p731511419112"><a name="zh-cn_topic_0000002373372809_p731511419112"></a><a name="zh-cn_topic_0000002373372809_p731511419112"></a>物理机+普通容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p1731574111112"><a name="zh-cn_topic_0000002373372809_p1731574111112"></a><a name="zh-cn_topic_0000002373372809_p1731574111112"></a>将物理机的NPU设备映射进普通容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row531512417117"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p43154414114"><a name="zh-cn_topic_0000002373372809_p43154414114"></a><a name="zh-cn_topic_0000002373372809_p43154414114"></a>物理机+特权容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p1531514411418"><a name="zh-cn_topic_0000002373372809_p1531514411418"></a><a name="zh-cn_topic_0000002373372809_p1531514411418"></a>将物理机的NPU设备映射进特权容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row531516410114"><td class="cellrowborder" rowspan="3" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p1031515411519"><a name="zh-cn_topic_0000002373372809_p1031515411519"></a><a name="zh-cn_topic_0000002373372809_p1031515411519"></a>虚拟机场景<sup id="zh-cn_topic_0000002373372809_sup198089431922"><a name="zh-cn_topic_0000002373372809_sup198089431922"></a><a name="zh-cn_topic_0000002373372809_sup198089431922"></a>b</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p0315154114114"><a name="zh-cn_topic_0000002373372809_p0315154114114"></a><a name="zh-cn_topic_0000002373372809_p0315154114114"></a>直通虚拟机场景</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002373372809_p53151741516"><a name="zh-cn_topic_0000002373372809_p53151741516"></a><a name="zh-cn_topic_0000002373372809_p53151741516"></a>将单个物理NPU设备的资源全部分配给虚拟机使用，该虚拟机独占单个NPU资源。主要涉及整机全部NPU设备直通（整卡直通）、部分NPU设备直通（部分卡直通）、单个NPU设备直通（单卡直通）等不同使用场景。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row4315104115119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p93159411314"><a name="zh-cn_topic_0000002373372809_p93159411314"></a><a name="zh-cn_topic_0000002373372809_p93159411314"></a>直通虚拟机+普通容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p16315941119"><a name="zh-cn_topic_0000002373372809_p16315941119"></a><a name="zh-cn_topic_0000002373372809_p16315941119"></a>将单个物理NPU设备的资源全部分配给虚拟机，然后将NPU设备资源映射进该虚拟机创建的普通容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row1131519411511"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p7315164119114"><a name="zh-cn_topic_0000002373372809_p7315164119114"></a><a name="zh-cn_topic_0000002373372809_p7315164119114"></a>直通虚拟机+特权容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p203151841411"><a name="zh-cn_topic_0000002373372809_p203151841411"></a><a name="zh-cn_topic_0000002373372809_p203151841411"></a>将单个物理NPU设备的资源全部分配给虚拟机，然后将NPU设备资源映射进该虚拟机创建的特权容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row7315241315"><td class="cellrowborder" rowspan="4" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p4315104113114"><a name="zh-cn_topic_0000002373372809_p4315104113114"></a><a name="zh-cn_topic_0000002373372809_p4315104113114"></a>昇腾虚拟化实例<sup id="zh-cn_topic_0000002373372809_sup165410541824"><a name="zh-cn_topic_0000002373372809_sup165410541824"></a><a name="zh-cn_topic_0000002373372809_sup165410541824"></a>c</sup>（全称Ascend Virtual Instance，简称为AVI）</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p5315741612"><a name="zh-cn_topic_0000002373372809_p5315741612"></a><a name="zh-cn_topic_0000002373372809_p5315741612"></a>物理机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002373372809_p831514411011"><a name="zh-cn_topic_0000002373372809_p831514411011"></a><a name="zh-cn_topic_0000002373372809_p831514411011"></a>在物理机上通过npu-smi工具或DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，将创建的vNPU挂载到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row531512416114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p143156411415"><a name="zh-cn_topic_0000002373372809_p143156411415"></a><a name="zh-cn_topic_0000002373372809_p143156411415"></a>物理机+虚拟机AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p43151141111"><a name="zh-cn_topic_0000002373372809_p43151141111"></a><a name="zh-cn_topic_0000002373372809_p43151141111"></a>在物理机上通过npu-smi工具或DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，将创建的vNPU分配给虚拟机使用。单个vNPU只能给单个虚拟机使用，但是单个虚拟机可以挂载多个vNPU。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row73152418114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p1567091519716"><a name="zh-cn_topic_0000002373372809_p1567091519716"></a><a name="zh-cn_topic_0000002373372809_p1567091519716"></a>虚拟机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p231574116113"><a name="zh-cn_topic_0000002373372809_p231574116113"></a><a name="zh-cn_topic_0000002373372809_p231574116113"></a>在物理机上通过npu-smi或者DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，通过虚拟机挂载指定的vNPU资源，然后在虚拟机内部进一步将创建的vNPU挂载到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row93151941719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002373372809_p11315184110116"><a name="zh-cn_topic_0000002373372809_p11315184110116"></a><a name="zh-cn_topic_0000002373372809_p11315184110116"></a>直通虚拟机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002373372809_p10315124112120"><a name="zh-cn_topic_0000002373372809_p10315124112120"></a><a name="zh-cn_topic_0000002373372809_p10315124112120"></a>将单个物理NPU设备的资源全部分配给虚拟机后，先在虚拟机上通过npu-smi或者DCMI API接口对NPU资源根据用户指定的需求划分出vNPU，再映射到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002373372809_row122217819219"><td class="cellrowborder" colspan="3" valign="top" headers="mcps1.2.4.1.1 mcps1.2.4.1.2 mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002373372809_p18261919824"><a name="zh-cn_topic_0000002373372809_p18261919824"></a><a name="zh-cn_topic_0000002373372809_p18261919824"></a>a：指在物理机环境中操作NPU资源的场景，包括物理机和物理机+容器。</p>
<p id="zh-cn_topic_0000002373372809_p9513057319"><a name="zh-cn_topic_0000002373372809_p9513057319"></a><a name="zh-cn_topic_0000002373372809_p9513057319"></a>b：指在虚拟机环境中操作NPU资源的场景，包括直通虚拟机和直通虚拟机+容器。</p>
<p id="zh-cn_topic_0000002373372809_p11102132014313"><a name="zh-cn_topic_0000002373372809_p11102132014313"></a><a name="zh-cn_topic_0000002373372809_p11102132014313"></a>c：<span id="zh-cn_topic_0000002373372809_ph42251523171020"><a name="zh-cn_topic_0000002373372809_ph42251523171020"></a><a name="zh-cn_topic_0000002373372809_ph42251523171020"></a>指通过资源虚拟化技术将1个NPU切分成若干个vNPU（虚拟NPU）实例挂载到虚拟机或容器中使用，使得1个NPU同时支持多个计算调度任务。AVI通过算力资源切分的方式，实现了资源虚拟化复用并保证了资源的安全隔离，大大降低了用户使用NPU算力的门槛和成本，并且支持多租户按需进行资源申请或回收管理</span>。</p>
</td>
</tr>
</tbody>
</table>

## 使用注意事项<a name="section7656918142110"></a>

- 不支持多线程并发使用npu-smi命令。
- 本文的命令回显信息仅供用户参考，请以实际查询的回显信息为准。
- 本文涉及的容器场景除特殊说明外，均指普通容器。
- 从Ascend950系列开始，npu-smi工具完成重构。本次重构的核心优化是将id/chip\_id统一归并为dev\_id（软件的逻辑ID），简化命令参数结构，提升使用效率。具体变化如下：
    1. Ascend950系列：需使用"-i  _dev\_id_"参数格式，不再兼容原有的"-i  _id_  -c  _chip\_id_"参数格式。
    2. Ascend950之前的产品：继续使用"-i  _id_  -c  _chip\_id_"参数格式，不受本次重构影响。
