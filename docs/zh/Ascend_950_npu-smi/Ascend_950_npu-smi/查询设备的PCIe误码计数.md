# 查询设备的PCIe误码计数<a name="ZH-CN_TOPIC_0000002583172590"></a>

## 功能说明<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_section5771700"></a>

用于查询设备的PCIe误码计数。

## 命令格式<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_section51945304"></a>

`npu-smi info -t pcie-err -i dev_id`

## 参数说明<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_section64854559"></a>

<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_table52358009"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_row49853000"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p11561214"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p11561214"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p11561214"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p64043148"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p64043148"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p64043148"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_row20112539"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p18502995"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p18502995"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_p18502995"></a><span id="ph541015741818"><a name="ph541015741818"></a><a name="ph541015741818"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="zh-cn_topic_0000002613572411_ph861524220464"><a name="zh-cn_topic_0000002613572411_ph861524220464"></a><a name="zh-cn_topic_0000002613572411_ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_section618113216182"></a>

**表 1** 不同部署场景下的支持情况

<a name="table441213131391"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_row10978131113711"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_p1297816153719"><a name="zh-cn_topic_0000002583332642_p1297816153719"></a><a name="zh-cn_topic_0000002583332642_p1297816153719"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_p13978141143710"><a name="zh-cn_topic_0000002583332642_p13978141143710"></a><a name="zh-cn_topic_0000002583332642_p13978141143710"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p209781123712"><a name="zh-cn_topic_0000002583332642_p209781123712"></a><a name="zh-cn_topic_0000002583332642_p209781123712"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_p149784173718"><a name="zh-cn_topic_0000002583332642_p149784173718"></a><a name="zh-cn_topic_0000002583332642_p149784173718"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_p897811123713"><a name="zh-cn_topic_0000002583332642_p897811123713"></a><a name="zh-cn_topic_0000002583332642_p897811123713"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_row997891203715"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_p1397813116379"><a name="zh-cn_topic_0000002583332642_p1397813116379"></a><a name="zh-cn_topic_0000002583332642_p1397813116379"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_p18978016374"><a name="zh-cn_topic_0000002583332642_p18978016374"></a><a name="zh-cn_topic_0000002583332642_p18978016374"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p19789173720"><a name="zh-cn_topic_0000002583332642_p19789173720"></a><a name="zh-cn_topic_0000002583332642_p19789173720"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_p1897812118374"><a name="zh-cn_topic_0000002583332642_p1897812118374"></a><a name="zh-cn_topic_0000002583332642_p1897812118374"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_p1897811133710"><a name="zh-cn_topic_0000002583332642_p1897811133710"></a><a name="zh-cn_topic_0000002583332642_p1897811133710"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_row9978191103715"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p29785111379"><a name="zh-cn_topic_0000002583332642_p29785111379"></a><a name="zh-cn_topic_0000002583332642_p29785111379"></a><span id="zh-cn_topic_0000002583332642_ph2097851133717"><a name="zh-cn_topic_0000002583332642_ph2097851133717"></a><a name="zh-cn_topic_0000002583332642_ph2097851133717"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p256471710404"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p256471710404"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p256471710404"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p45656172402"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p45656172402"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p45656172402"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p13391755125816"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p13391755125816"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p13391755125816"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p7566161714013"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p7566161714013"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_zh-cn_topic_0000002027533757_p7566161714013"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p4158102317586"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p4158102317586"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p4158102317586"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row1697951113714"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p897913111374"><a name="zh-cn_topic_0000002583332642_p897913111374"></a><a name="zh-cn_topic_0000002583332642_p897913111374"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0238524716_section46820120"></a>

查询设备0的PCIe误码统计。

```bash
npu-smi info -t pcie-err -i 0
```

```text
NPU ID                         : 0
TX Error Count                 : 0
RX Error Count                 : 991
Lcrc Error Count               : 0
Ecrc Error Count               : 0
Retry Count                    : 415
```

## 输出说明<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p36441839191318"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p36441839191318"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1164353918134"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1164353918134"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1164353918134"></a>设备ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p564183915134"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p564183915134"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p564183915134"></a>TX Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p111181536195"><a name="p111181536195"></a><a name="p111181536195"></a>PCIe发送错误计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_zh-cn_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p114775578183"><a name="p114775578183"></a><a name="p114775578183"></a>RX Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p19118853111915"><a name="p19118853111915"></a><a name="p19118853111915"></a>PCIe接收错误计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_row1714819359322"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p19148113533210"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p19148113533210"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p19148113533210"></a>Lcrc Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p18118115361913"><a name="p18118115361913"></a><a name="p18118115361913"></a>PCIe DDLP LCRC校验错误计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_row1660618522328"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1460610525322"><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1460610525322"></a><a name="zh-cn_topic_0000001220096510_zh-cn_topic_0000001163757103_p1460610525322"></a>Ecrc Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p4116135341919"><a name="p4116135341919"></a><a name="p4116135341919"></a>PCIe TLP ECRC校验错误计数。</p>
</td>
</tr>
<tr id="row6328133961912"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p14328103910195"><a name="p14328103910195"></a><a name="p14328103910195"></a>Retry Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1480411118522"><a name="p1480411118522"></a><a name="p1480411118522"></a>PCIe链路重传计数。</p>
</td>
</tr>
</tbody>
</table>
