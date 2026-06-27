# 查询多NPU的拓扑结构<a name="ZH-CN_TOPIC_0000002613692321"></a>

## 功能说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section1271426121315"></a>

用于查询设备CPU和NPU的亲和性关系、多NPU之间的拓扑结构。

## 命令格式<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section663871213445"></a>

`npu-smi info -t topo`

## 参数说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section52928161114"></a>

无

## 使用指南<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section138501410151716"></a>

**表 1** 不同部署场景下的支持情况

<a name="table345515356547"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p5649445717"><a name="zh-cn_topic_0000002583332642_p5649445717"></a><a name="zh-cn_topic_0000002583332642_p5649445717"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p116412411579"><a name="zh-cn_topic_0000002583332642_p116412411579"></a><a name="zh-cn_topic_0000002583332642_p116412411579"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row185641517124016"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p144147361596"><a name="zh-cn_topic_0000002583332642_p144147361596"></a><a name="zh-cn_topic_0000002583332642_p144147361596"></a><span id="zh-cn_topic_0000002583332642_ph12140626193614"><a name="zh-cn_topic_0000002583332642_ph12140626193614"></a><a name="zh-cn_topic_0000002583332642_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_p125931265317"><a name="zh-cn_topic_0000002583332642_p125931265317"></a><a name="zh-cn_topic_0000002583332642_p125931265317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_p158021256175710"><a name="zh-cn_topic_0000002583332642_p158021256175710"></a><a name="zh-cn_topic_0000002583332642_p158021256175710"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row651184316559"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p2194113775312"><a name="zh-cn_topic_0000002583332642_p2194113775312"></a><a name="zh-cn_topic_0000002583332642_p2194113775312"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section77423984414"></a>

查询设备CPU和NPU的亲和性关系、多NPU之间的拓扑结构。

- 单卡场景多个NPU通过PCIe相连，拓扑结构如下：

    ```bash
    npu-smi info -t topo
    ```

    ```text
    NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          SYS        SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       SYS        X          SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       SYS        SYS        X          SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       SYS        SYS        SYS        X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         SYS       SYS       SYS       64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        SYS       X         SYS       SYS       64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        SYS       SYS       X         SYS       64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        SYS       SYS       SYS       X         64-127,192-255         
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

- 2卡互联场景，卡内通过UB相连，卡间通过PCIe相连，拓扑结构如下：

    ```bash
    npu-smi info -t topo
    ```

    ```text
               NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          UB         SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       UB         X          SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       SYS        SYS        X          UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       SYS        SYS        UB         X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         UB        SYS       SYS       64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        UB        X         SYS       SYS       64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        SYS       SYS       X         UB        64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        SYS       SYS       UB        X         64-127,192-255
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

- 4卡互联场景，卡内通过UB相连，卡间通过PCIe相连，拓扑结构如下：

    ```bash
    npu-smi info -t topo
    ```

    ```text
               NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          UB         UB         UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       UB         X          UB         UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       UB         UB         X          UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       UB         UB         UB         X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         UB        UB        UB        64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        UB        X         UB        UB        64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        UB        UB        X         UB        64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        UB        UB        UB        X         64-127,192-255
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

## 输出说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="42.02%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="57.98%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_row16177103510201"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"></a>NPU<em id="i14259163375019"><a name="i14259163375019"></a><a name="i14259163375019"></a>X</em></p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"></a><em id="i3500154705219"><a name="i3500154705219"></a><a name="i3500154705219"></a>X</em>表示<span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row1941545717168"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"></a>CPU Affinity</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"></a>与NPU具有亲和性关系的CPU。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p4642739141315"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p4642739141315"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p4642739141315"></a>X</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p8642123913138"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p8642123913138"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p8642123913138"></a>同一个NPU的拓扑互联关系。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p564183915134"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p564183915134"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p564183915134"></a>SYS</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1764083911312"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1764083911312"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1764083911312"></a>在不同的NUMA节点下的NPU之间的拓扑互联关系。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p16392398134"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p16392398134"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p16392398134"></a>PHB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p15620139171316"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p15620139171316"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p15620139171316"></a>在同一个NUMA节点下的NPU之间的拓扑互联关系。</p>
</td>
</tr>
<tr id="row118536113337"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p208541511193316"><a name="p208541511193316"></a><a name="p208541511193316"></a>PIX</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p48541117335"><a name="p48541117335"></a><a name="p48541117335"></a>在同一个NUMA节点下通过单个PCIe switch连接两个NPU之间<span>的</span>拓扑互联关系。</p>
</td>
</tr>
<tr id="row7107716163315"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p101070167332"><a name="p101070167332"></a><a name="p101070167332"></a>PXB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p210701614338"><a name="p210701614338"></a><a name="p210701614338"></a>在同一个NUMA节点下通过多个PCIe switches连接两个NPU之间<span>的</span>拓扑互联关系。</p>
</td>
</tr>
<tr id="row5761581713"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p677989717"><a name="p677989717"></a><a name="p677989717"></a>SIO</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p134645391257"><a name="p134645391257"></a><a name="p134645391257"></a>在同一个模组下的NPU之间的拓扑互联关系。</p>
</td>
</tr>
<tr id="row1898212263154"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p1798302620155"><a name="p1798302620155"></a><a name="p1798302620155"></a>UB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p139831326181514"><a name="p139831326181514"></a><a name="p139831326181514"></a>通过UB连接的两个NPU之间<span>的</span>拓扑互联关系。</p>
</td>
</tr>
<tr id="row122851220125215"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p2286132055212"><a name="p2286132055212"></a><a name="p2286132055212"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p1828612205522"><a name="p1828612205522"></a><a name="p1828612205522"></a>拓扑互联关系为未知关系。</p>
</td>
</tr>
</tbody>
</table>
