# 复位NPU<a name="ZH-CN_TOPIC_0000002613572559"></a>

## 功能说明<a name="section1403145042312"></a>

用于复位设备。

## 命令格式<a name="section19404195020232"></a>

`npu-smi set -t reset -i dev_id [-m 1]`

## 参数说明<a name="section9404185032319"></a>

<a name="table1340414506234"></a>
<table><thead align="left"><tr id="row740515505237"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p140505018236"><a name="p140505018236"></a><a name="p140505018236"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p1840520500237"><a name="p1840520500237"></a><a name="p1840520500237"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1040565012239"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p54051506233"><a name="p54051506233"></a><a name="p54051506233"></a><span id="ph1312861310307"><a name="ph1312861310307"></a><a name="ph1312861310307"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="zh-cn_topic_0000002613572411_ph861524220464"><a name="zh-cn_topic_0000002613572411_ph861524220464"></a><a name="zh-cn_topic_0000002613572411_ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
<tr id="row114064506236"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p12406145012237"><a name="p12406145012237"></a><a name="p12406145012237"></a><strong id="b14406135012234"><a name="b14406135012234"></a><a name="b14406135012234"></a>-m</strong> <strong id="b18406450172315"><a name="b18406450172315"></a><a name="b18406450172315"></a>1</strong></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11406150102320"><a name="p11406150102320"></a><a name="p11406150102320"></a>可选。</p>
<a name="ul11535133417485"></a><a name="ul11535133417485"></a><ul id="ul11535133417485"><li>若不带<strong id="b14852181842216"><a name="b14852181842216"></a><a name="b14852181842216"></a>-m</strong> <strong id="b12852918122210"><a name="b12852918122210"></a><a name="b12852918122210"></a>1</strong>参数，表示带外热复位。</li><li>若带<strong id="b57531592232"><a name="b57531592232"></a><a name="b57531592232"></a>-m</strong> <strong id="b117539952317"><a name="b117539952317"></a><a name="b117539952317"></a>1</strong>参数，表示带内热复位。</li></ul>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section440685072312"></a>

- 执行复位操作前，请停掉NPU上的所有业务。
- 复位NPU时网口状态由UP变为DOWN，iBMC网管上报网口闪断相关告警，复位NPU完成后网口状态恢复为UP，告警消除，属于正常现象。

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_row575535820220"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_p2075513581623"><a name="zh-cn_topic_0000002583332642_p2075513581623"></a><a name="zh-cn_topic_0000002583332642_p2075513581623"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_p187555581526"><a name="zh-cn_topic_0000002583332642_p187555581526"></a><a name="zh-cn_topic_0000002583332642_p187555581526"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p575595818217"><a name="zh-cn_topic_0000002583332642_p575595818217"></a><a name="zh-cn_topic_0000002583332642_p575595818217"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_p20755958827"><a name="zh-cn_topic_0000002583332642_p20755958827"></a><a name="zh-cn_topic_0000002583332642_p20755958827"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_p137556581823"><a name="zh-cn_topic_0000002583332642_p137556581823"></a><a name="zh-cn_topic_0000002583332642_p137556581823"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_row16755175817215"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_p14755105819211"><a name="zh-cn_topic_0000002583332642_p14755105819211"></a><a name="zh-cn_topic_0000002583332642_p14755105819211"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_p37552581224"><a name="zh-cn_topic_0000002583332642_p37552581224"></a><a name="zh-cn_topic_0000002583332642_p37552581224"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p1175514581218"><a name="zh-cn_topic_0000002583332642_p1175514581218"></a><a name="zh-cn_topic_0000002583332642_p1175514581218"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_p87554581927"><a name="zh-cn_topic_0000002583332642_p87554581927"></a><a name="zh-cn_topic_0000002583332642_p87554581927"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_p12755175814214"><a name="zh-cn_topic_0000002583332642_p12755175814214"></a><a name="zh-cn_topic_0000002583332642_p12755175814214"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_row175555814213"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p175514581220"><a name="zh-cn_topic_0000002583332642_p175514581220"></a><a name="zh-cn_topic_0000002583332642_p175514581220"></a><span id="zh-cn_topic_0000002583332642_ph07556581225"><a name="zh-cn_topic_0000002583332642_ph07556581225"></a><a name="zh-cn_topic_0000002583332642_ph07556581225"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p256471710404"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p256471710404"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p256471710404"></a>Y（仅支持带内）</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p45656172402"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p45656172402"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p45656172402"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p8195141318594"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p8195141318594"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p8195141318594"></a>Y（仅支持带内）</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p7566161714013"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p7566161714013"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_zh-cn_topic_0000002484466758_p7566161714013"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_p12943338315"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_p12943338315"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002484466758_p12943338315"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row17562581328"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p177568581927"><a name="zh-cn_topic_0000002583332642_p177568581927"></a><a name="zh-cn_topic_0000002583332642_p177568581927"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section174092507232"></a>

复位设备0。

```bash
npu-smi set -t reset -i 0 -m 1
```

```text
Resetting the standard PCIe card or NPU chip may cause a system hang or abnormal reset during service running.
Are you sure you want to continue resetting?(Y/N)
y
        Message                        : resetting ...
        Status                         : OK
        Message                        : Reset card successfully.
```

## 输出说明<a name="section64091350102318"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p36441839191318"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p36441839191318"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p36441839191318"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p14359124716209"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p14359124716209"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p14359124716209"></a>复位状态。</p>
<p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p1520231621017"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p1520231621017"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p1520231621017"></a>有如下两种状态：OK，Fail。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_zh-cn_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p4642739141315"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p4642739141315"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p4642739141315"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p8642123913138"><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p8642123913138"></a><a name="zh-cn_topic_0000001220576462_zh-cn_topic_0000001117597268_p8642123913138"></a>复位提示信息。</p>
</td>
</tr>
</tbody>
</table>
