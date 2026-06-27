# 命令列表

## 查询类命令

- [查询hccn\_tool帮助提示信息](./Ascend_950_HCCN_Tool/查询hccn_tool帮助提示信息.md)
- [查询NPU设备信息](./Ascend_950_HCCN_Tool/查询NPU设备信息.md)
- [查询端口的连接状态](./Ascend_950_HCCN_Tool/查询端口的连接状态.md)
- [查询端口的实时带宽信息](./Ascend_950_HCCN_Tool/查询端口的实时带宽信息.md)
- [查询端口的相关统计信息](./Ascend_950_HCCN_Tool/查询端口的相关统计信息.md)
- [查询端口的状态信息](./Ascend_950_HCCN_Tool/查询端口的状态信息.md)
- [查询端口的峰值带宽信息](./Ascend_950_HCCN_Tool/查询端口的峰值带宽信息.md)
- [查询端口的误码数信息](./Ascend_950_HCCN_Tool/查询端口的误码数信息.md)
- [查询端口的芯片可用信用证数量](./Ascend_950_HCCN_Tool/查询端口的芯片可用信用证数量.md)
- [查询端口的速率信息](./Ascend_950_HCCN_Tool/查询端口的速率信息.md)
- [查询端口的SerDes信息](./Ascend_950_HCCN_Tool/查询端口的SerDes信息.md)
- [查询端口的FEC信息](./Ascend_950_HCCN_Tool/查询端口的FEC信息.md)
- [查询端口的历史建链流程的状态信息](./Ascend_950_HCCN_Tool/查询端口的历史建链流程的状态信息.md)
- [查询端口的历史link up和down状态信息](./Ascend_950_HCCN_Tool/查询端口的历史link-up和down状态信息.md)
- [查询端口的link down时链路相关信息](./Ascend_950_HCCN_Tool/查询端口的link-down时链路相关信息.md)
- [查询端口的SU误码模式和误码统计结果](./Ascend_950_HCCN_Tool/查询端口的SU误码模式和误码统计结果.md)
- [查询NPU设备的互连或断开状态信息](./Ascend_950_HCCN_Tool/查询NPU设备的互连或断开状态信息.md)
- [查询NPU设备的vNIC IP及link状态](./Ascend_950_HCCN_Tool/查询NPU设备的vNIC-IP及link状态.md)
- [查询NPU设备的DRV驱动包和固件版本号信息](./Ascend_950_HCCN_Tool/查询NPU设备的DRV驱动包和固件版本号信息.md)
- [查询NPU设备的TLS证书信息](./Ascend_950_HCCN_Tool/查询NPU设备的TLS证书信息.md)
- [查询NPU设备的Device侧进程信息](./Ascend_950_HCCN_Tool/查询NPU设备的Device侧进程信息.md)
- [查询NPU设备的配置恢复状态信息](./Ascend_950_HCCN_Tool/查询NPU设备的配置恢复状态信息.md)
- [查询网络设备的AEQ context信息](./Ascend_950_HCCN_Tool/查询网络设备的AEQ-context信息.md)
- [查询网络设备的CEQ context信息](./Ascend_950_HCCN_Tool/查询网络设备的CEQ-context信息.md)
- [查询网络设备的队列相关资源列表信息](./Ascend_950_HCCN_Tool/查询网络设备的队列相关资源列表信息.md)
- [查询网络设备的队列相关资源属性信息](./Ascend_950_HCCN_Tool/查询网络设备的队列相关资源属性信息.md)

## 设置类命令

- [清除端口的相关统计信息](./Ascend_950_HCCN_Tool/清除端口的相关统计信息.md)
- [设置端口升lane](./Ascend_950_HCCN_Tool/设置端口升lane.md)
- [清除端口的SU误码统计](./Ascend_950_HCCN_Tool/清除端口的SU误码统计.md)
- [替换NPU设备的TLS证书](./Ascend_950_HCCN_Tool/替换NPU设备的TLS证书.md)
- [设置NPU设备的TLS开关状态](./Ascend_950_HCCN_Tool/设置NPU设备的TLS开关状态.md)
- [设置NPU设备的TLS过期告警阈值](./Ascend_950_HCCN_Tool/设置NPU设备的TLS过期告警阈值.md)
- [清除NPU设备的TLS证书信息](./Ascend_950_HCCN_Tool/清除NPU设备的TLS证书信息.md)
- [恢复NPU设备的配置](./Ascend_950_HCCN_Tool/恢复NPU设备的配置.md)
- [恢复所有NPU设备的配置](./Ascend_950_HCCN_Tool/恢复所有NPU设备的配置.md)

## 测试类命令

- [导出端口的寄存器信息](./Ascend_950_HCCN_Tool/导出端口的寄存器信息.md)
- [设置端口的SU误码模式](./Ascend_950_HCCN_Tool/设置端口的SU误码模式.md)
- [查询指定NPU设备到目的地址的UB ping结果](./Ascend_950_HCCN_Tool/查询指定NPU设备到目的地址的UB-ping结果.md)

# 命令说明

## 概述<a name="section1243813351818"></a>

本文档主要描述集群网络工具hccn\_tool对外接口，包括查询NPU设备信息、查询端口的连接状态等。

适用于：Atlas 350 加速卡。

## 接口部署场景说明<a name="section185124551191"></a>

- 如果部分部署场景在本文档的相关命令或接口描述中未提及，则表明该产品不涉及此场景，当前未规划。
- 本文档中“不同部署场景下的支持情况”表中的Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。

**表 1**  部署场景分类定义及说明

<a name="table45461144192020"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row63157411612"><th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531594115110"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531594115110"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531594115110"></a>部署场景分类</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231514119116"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231514119116"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231514119116"></a>子场景分类</p>
</th>
<th class="cellrowborder" valign="top" width="62.496249624962495%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83158416110"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83158416110"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83158416110"></a>子场景说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row631511411411"><td class="cellrowborder" rowspan="3" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83151741912"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83151741912"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p83151741912"></a>物理机场景<sup id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup124511238422"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup124511238422"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup124511238422"></a>a</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1931510414116"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1931510414116"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1931510414116"></a>物理机场景（裸机）</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p203156413117"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p203156413117"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p203156413117"></a>NPU设备直接在物理机（裸机）上使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row33150417118"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p731511419112"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p731511419112"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p731511419112"></a>物理机+普通容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1731574111112"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1731574111112"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1731574111112"></a>将物理机的NPU设备映射进普通容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row531512417117"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43154414114"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43154414114"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43154414114"></a>物理机+特权容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531514411418"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531514411418"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1531514411418"></a>将物理机的NPU设备映射进特权容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row531516410114"><td class="cellrowborder" rowspan="2" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1031515411519"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1031515411519"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1031515411519"></a>虚拟机场景<sup id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup198089431922"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup198089431922"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup198089431922"></a>b</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p0315154114114"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p0315154114114"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p0315154114114"></a>直通虚拟机场景</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p53151741516"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p53151741516"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p53151741516"></a>将单个物理NPU设备的资源全部分配给虚拟机使用，该虚拟机独占单个NPU资源。主要涉及整机全部NPU设备直通（整卡直通）、部分NPU设备直通（部分卡直通）、单个NPU设备直通（单卡直通）等不同使用场景。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row4315104115119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p93159411314"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p93159411314"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p93159411314"></a>直通虚拟机+普通容器场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p16315941119"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p16315941119"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p16315941119"></a>将单个物理NPU设备的资源全部分配给虚拟机，然后将NPU设备资源映射进该虚拟机创建的普通容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row7315241315"><td class="cellrowborder" rowspan="4" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p4315104113114"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p4315104113114"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p4315104113114"></a>昇腾虚拟化实例<sup id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup165410541824"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup165410541824"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_sup165410541824"></a>c</sup>（全称Ascend Virtual Instance，简称为AVI）</p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p5315741612"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p5315741612"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p5315741612"></a>物理机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p831514411011"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p831514411011"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p831514411011"></a>在物理机上通过npu-smi工具或DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，将创建的vNPU挂载到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row531512416114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p143156411415"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p143156411415"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p143156411415"></a>物理机+虚拟机AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43151141111"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43151141111"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p43151141111"></a>在物理机上通过npu-smi工具或DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，将创建的vNPU分配给虚拟机使用。单个vNPU只能给单个虚拟机使用，但是单个虚拟机可以挂载多个vNPU。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row73152418114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1567091519716"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1567091519716"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p1567091519716"></a>虚拟机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231574116113"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231574116113"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p231574116113"></a>在物理机上通过npu-smi或者DCMI API接口对NPU硬件资源根据用户指定的需求划分出vNPU，通过虚拟机挂载指定的vNPU资源，然后在虚拟机内部进一步将创建的vNPU挂载到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row93151941719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11315184110116"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11315184110116"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11315184110116"></a>直通虚拟机+容器AVI场景</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p10315124112120"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p10315124112120"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p10315124112120"></a>将单个物理NPU设备的资源全部分配给虚拟机后，先在虚拟机上通过npu-smi或者DCMI API接口对NPU资源根据用户指定的需求划分出vNPU，再映射到容器中使用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_row122217819219"><td class="cellrowborder" colspan="3" valign="top" headers="mcps1.2.4.1.1 mcps1.2.4.1.2 mcps1.2.4.1.3 "><p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p18261919824"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p18261919824"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p18261919824"></a>a：指在物理机环境中操作NPU资源的场景，包括物理机和物理机+容器。</p>
<p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p9513057319"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p9513057319"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p9513057319"></a>b：指在虚拟机环境中操作NPU资源的场景，包括直通虚拟机和直通虚拟机+容器。</p>
<p id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11102132014313"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11102132014313"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_p11102132014313"></a>c：<span id="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_ph42251523171020"><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_ph42251523171020"></a><a name="zh-cn_topic_0000002584451444_zh-cn_topic_0000002373372809_ph42251523171020"></a>指通过资源虚拟化技术将1个NPU切分成若干个vNPU（虚拟NPU）实例挂载到虚拟机或容器中使用，使得1个NPU同时支持多个计算调度任务。AVI通过算力资源切分的方式，实现了资源虚拟化复用并保证了资源的安全隔离，大大降低了用户使用NPU算力的门槛和成本，并且支持多租户按需进行资源申请或回收管理</span>。</p>
</td>
</tr>
</tbody>
</table>

## 使用注意事项<a name="section7656918142110"></a>

- 使用本工具前需要完成驱动安装，驱动安装过程中会默认安装hccn\_tool工具。待安装完成后，hccn\_tool工具通过软链接放置在“/usr/bin/”目录下，实际路径为“/usr/local/Ascend/driver/tools”。
- 若需在容器中使用hccn\_tool工具，需将宿主机hccn\_tool工具“/usr/bin/hccn\_tool”挂载到容器中，具体操作可参考对应版本的《Atlas 350 加速卡 25.7.RC1 NPU驱动和固件安装指南》的“容器内安装与卸载 \> 安装场景 \>  [宿主机目录挂载到容器](https://support.huawei.com/enterprise/zh/doc/EDOC1100569817/25832de7)”章节内容。
- hccn\_tool工具不支持多线程并发操作。
- hccn\_tool工具无昇腾虚拟化实例场景。
- 由于Ascend 950 系列产品的NPU端口数量显著增加，老系列的hccn\_tool仅支持“一个NPU对应一个端口”的管理模式，该模式已无法满足需求。因此，新系列的hccn\_tool按网络管理对象进行了重构优化，以满足新系列多端口、多网络设备的管理诉求。网络管理对象按分类进行索引，具体如[表2](#zh-cn_topic_0000002584451446_table14479522135510)所示。

    **表 2**  网络管理对象分类

    <a name="zh-cn_topic_0000002584451446_table14479522135510"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000002584451446_row3480122215512"><th class="cellrowborder" valign="top" width="5.71%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002584451446_p1459495113556"><a name="zh-cn_topic_0000002584451446_p1459495113556"></a><a name="zh-cn_topic_0000002584451446_p1459495113556"></a>分类</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.21%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002584451446_p164806220558"><a name="zh-cn_topic_0000002584451446_p164806220558"></a><a name="zh-cn_topic_0000002584451446_p164806220558"></a>适用场景</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.82%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002584451446_p164451307013"><a name="zh-cn_topic_0000002584451446_p164451307013"></a><a name="zh-cn_topic_0000002584451446_p164451307013"></a>命令格式</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.26%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002584451446_p9936246419"><a name="zh-cn_topic_0000002584451446_p9936246419"></a><a name="zh-cn_topic_0000002584451446_p9936246419"></a>使用示例</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000002584451446_row1655195291816"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002584451446_p148032210554"><a name="zh-cn_topic_0000002584451446_p148032210554"></a><a name="zh-cn_topic_0000002584451446_p148032210554"></a>NPU设备</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002584451446_p1748072245519"><a name="zh-cn_topic_0000002584451446_p1748072245519"></a><a name="zh-cn_topic_0000002584451446_p1748072245519"></a>针对单个NPU设备（忽略其内部端口或UDie等细节）的操作。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002584451446_p68096111620"><a name="zh-cn_topic_0000002584451446_p68096111620"></a><a name="zh-cn_topic_0000002584451446_p68096111620"></a><span id="zh-cn_topic_0000002584451446_ph9793175810161"><a name="zh-cn_topic_0000002584451446_ph9793175810161"></a><a name="zh-cn_topic_0000002584451446_ph9793175810161"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; [-options]</span></p>
    <a name="zh-cn_topic_0000002584451446_ul2057415561126"></a><a name="zh-cn_topic_0000002584451446_ul2057415561126"></a><ul id="zh-cn_topic_0000002584451446_ul2057415561126"><li>-mode为命令模式，取值包括：-g（查询类命令）、-s（设置类命令）、-t（测试类命令）。</li><li>-cmd为可用命令的主命令字，具体命令见对应模式下帮助信息输出。</li></ul>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="zh-cn_topic_0000002584451446_ol5191359175113"></a><a name="zh-cn_topic_0000002584451446_ol5191359175113"></a><ol id="zh-cn_topic_0000002584451446_ol5191359175113"><li>执行npu-smi info命令获取“NPU ID”（即下面命令要用的dev_id）。</li><li>执行<span id="zh-cn_topic_0000002584451446_ph1176216540169"><a name="zh-cn_topic_0000002584451446_ph1176216540169"></a><a name="zh-cn_topic_0000002584451446_ph1176216540169"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; [-options]</span>。<p id="zh-cn_topic_0000002584451446_p9521646121615"><a name="zh-cn_topic_0000002584451446_p9521646121615"></a><a name="zh-cn_topic_0000002584451446_p9521646121615"></a>比如查询NPU设备信息，执行<span id="zh-cn_topic_0000002584451446_ph1363312397193"><a name="zh-cn_topic_0000002584451446_ph1363312397193"></a><a name="zh-cn_topic_0000002584451446_ph1363312397193"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span>。</p>
    </li></ol>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000002584451446_row64802022135517"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002584451446_p54807223551"><a name="zh-cn_topic_0000002584451446_p54807223551"></a><a name="zh-cn_topic_0000002584451446_p54807223551"></a>NPU的端口</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002584451446_p18480422135514"><a name="zh-cn_topic_0000002584451446_p18480422135514"></a><a name="zh-cn_topic_0000002584451446_p18480422135514"></a>针对单个端口（Port）的操作。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002584451446_p6350123201019"><a name="zh-cn_topic_0000002584451446_p6350123201019"></a><a name="zh-cn_topic_0000002584451446_p6350123201019"></a><span id="zh-cn_topic_0000002584451446_ph148913931811"><a name="zh-cn_topic_0000002584451446_ph148913931811"></a><a name="zh-cn_topic_0000002584451446_ph148913931811"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -u &lt;udie_id&gt; -p &lt;port_id&gt; [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="zh-cn_topic_0000002584451446_ol1067116134516"></a><a name="zh-cn_topic_0000002584451446_ol1067116134516"></a><ol id="zh-cn_topic_0000002584451446_ol1067116134516"><li>执行npu-smi info命令获取“NPU ID”（即下面命令要用的dev_id）。</li><li>执行<span id="zh-cn_topic_0000002584451446_ph963317495199"><a name="zh-cn_topic_0000002584451446_ph963317495199"></a><a name="zh-cn_topic_0000002584451446_ph963317495199"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span>命令获取UDie ID（udie_id）和Port ID（port_id）。</li><li>执行<span id="zh-cn_topic_0000002584451446_ph1848361692115"><a name="zh-cn_topic_0000002584451446_ph1848361692115"></a><a name="zh-cn_topic_0000002584451446_ph1848361692115"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -u &lt;udie_id&gt; -p &lt;port_id&gt; [-options]</span>。<p id="zh-cn_topic_0000002584451446_p1584461355612"><a name="zh-cn_topic_0000002584451446_p1584461355612"></a><a name="zh-cn_topic_0000002584451446_p1584461355612"></a>比如获取端口连接状态，执行hccn_tool -g -link -i 0 -u 0 -p 4。</p>
    </li></ol>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000002584451446_row1048062210552"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002584451446_p1648020224552"><a name="zh-cn_topic_0000002584451446_p1648020224552"></a><a name="zh-cn_topic_0000002584451446_p1648020224552"></a>网络设备</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002584451446_p1248020220559"><a name="zh-cn_topic_0000002584451446_p1248020220559"></a><a name="zh-cn_topic_0000002584451446_p1248020220559"></a>针对以太、UB等网络设备的操作。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002584451446_p201981929184316"><a name="zh-cn_topic_0000002584451446_p201981929184316"></a><a name="zh-cn_topic_0000002584451446_p201981929184316"></a><span id="zh-cn_topic_0000002584451446_ph13807846191811"><a name="zh-cn_topic_0000002584451446_ph13807846191811"></a><a name="zh-cn_topic_0000002584451446_ph13807846191811"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -d &lt;dev_name&gt; [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="zh-cn_topic_0000002584451446_ol174671024487"></a><a name="zh-cn_topic_0000002584451446_ol174671024487"></a><ol id="zh-cn_topic_0000002584451446_ol174671024487"><li>执行npu-smi info命令获取“NPU ID”（即下面命令要用的dev_id）。</li><li>执行<span id="zh-cn_topic_0000002584451446_ph1110697204"><a name="zh-cn_topic_0000002584451446_ph1110697204"></a><a name="zh-cn_topic_0000002584451446_ph1110697204"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span>命令获取Interface Name/Name（dev_name），dev_name的取值要求详见各命令。</li><li>执行<span id="zh-cn_topic_0000002584451446_ph11886239122111"><a name="zh-cn_topic_0000002584451446_ph11886239122111"></a><a name="zh-cn_topic_0000002584451446_ph11886239122111"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -d &lt;dev_name&gt; [-options]</span>。<p id="zh-cn_topic_0000002584451446_p1972712873217"><a name="zh-cn_topic_0000002584451446_p1972712873217"></a><a name="zh-cn_topic_0000002584451446_p1972712873217"></a>比如查询某个网络设备的资源数量统计列表，执行hccn_tool -g -show_list -i &lt;dev_id&gt; -d &lt;dev_name&gt;。</p>
    </li></ol>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000002584451446_row148192215512"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002584451446_p14874112518417"><a name="zh-cn_topic_0000002584451446_p14874112518417"></a><a name="zh-cn_topic_0000002584451446_p14874112518417"></a>所有NPU设备</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002584451446_p223218411050"><a name="zh-cn_topic_0000002584451446_p223218411050"></a><a name="zh-cn_topic_0000002584451446_p223218411050"></a>针对所有NPU设备的操作。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002584451446_p424153618441"><a name="zh-cn_topic_0000002584451446_p424153618441"></a><a name="zh-cn_topic_0000002584451446_p424153618441"></a><span id="zh-cn_topic_0000002584451446_ph1725774171918"><a name="zh-cn_topic_0000002584451446_ph1725774171918"></a><a name="zh-cn_topic_0000002584451446_ph1725774171918"></a>hccn_tool -mode -cmd -all [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="zh-cn_topic_0000002584451446_ol128145552538"></a><a name="zh-cn_topic_0000002584451446_ol128145552538"></a><ol id="zh-cn_topic_0000002584451446_ol128145552538"><li>执行<span id="zh-cn_topic_0000002584451446_ph161126182215"><a name="zh-cn_topic_0000002584451446_ph161126182215"></a><a name="zh-cn_topic_0000002584451446_ph161126182215"></a>hccn_tool -mode -cmd -all [-options]</span>。<p id="zh-cn_topic_0000002584451446_p196581649164818"><a name="zh-cn_topic_0000002584451446_p196581649164818"></a><a name="zh-cn_topic_0000002584451446_p196581649164818"></a>比如恢复所有NPU设备的配置，执行hccn_tool -s -cfg_recovery -all。</p>
    </li></ol>
    </td>
    </tr>
    </tbody>
    </table>
