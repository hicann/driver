# 查询设备ECC错误计数<a name="ZH-CN_TOPIC_0000002583172720"></a>

## 功能说明<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section18674262006"></a>

用于查询设备的ECC错误计数。

## 命令格式<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section386902615016"></a>

`npu-smi info -t ecc -i dev_id`

## 参数说明<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section1786919261014"></a>

<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_table7208814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p3985976"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p3985976"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p3985976"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p54428625"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p54428625"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p54428625"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p57396781"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p57396781"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p57396781"></a><span id="ph36701517144513"><a name="ph36701517144513"></a><a name="ph36701517144513"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="zh-cn_topic_0000002613572411_ph861524220464"><a name="zh-cn_topic_0000002613572411_ph861524220464"></a><a name="zh-cn_topic_0000002613572411_ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section0558429173410"></a>

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
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

## 使用示例<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section66051714132117"></a>

查询设备0的ECC错误统计。

```bash
npu-smi info -t ecc -i 0
```

```text
        NPU ID                                   : 0
        HBM Single Bit Error Count               : 0
        HBM Double Bit Error Count               : 0
        HBM Single Bit Aggregate Total Err Cnt   : 0
        HBM Double Bit Aggregate Total Err Cnt   : 0
        HBM Single Bit Isolated Pages Count      : 0
        HBM Double Bit Isolated Pages Count      : 0
        HBM Single Bit Next-Isolated Pages Count : 0
        HBM Double Bit Next-Isolated Pages Count : 0
```

## 输出说明<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p36441839191318"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p36441839191318"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1164353918134"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1164353918134"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1164353918134"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row17267164321119"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p42678437116"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p42678437116"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p42678437116"></a>HBM Single Bit Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p95915518282"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p95915518282"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p95915518282"></a>片上内存单比特当前错误计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row1118085717118"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p61804574113"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p61804574113"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p61804574113"></a>HBM Double Bit Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1559145102814"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1559145102814"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1559145102814"></a>片上内存多比特当前错误计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row8203189131213"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p8203998121"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p8203998121"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p8203998121"></a>HBM Single Bit Aggregate Total Err Cnt</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p25919582816"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p25919582816"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p25919582816"></a>片上内存生命周期内所有单比特错误数量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row1383511217128"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1383513215121"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1383513215121"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1383513215121"></a>HBM Double Bit Aggregate Total Err Cnt</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p06020582810"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p06020582810"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p06020582810"></a>片上内存生命周期内所有多比特错误数量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row1021515377127"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1321553701218"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1321553701218"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p1321553701218"></a>HBM Single Bit Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p16603582820"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p16603582820"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p16603582820"></a>片上内存单比特错误隔离内存页数量（预留字段，暂不使用，<span>固定输出0</span>）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_row13872493121"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p7387194912128"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p7387194912128"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p7387194912128"></a>HBM Double Bit Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p4605511286"><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p4605511286"></a><a name="zh-cn_topic_0000001220096542_zh-cn_topic_0000001117437366_p4605511286"></a>片上内存多比特错误隔离内存页数量。</p>
</td>
</tr>
<tr id="row1321063011448"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p3244152018370"><a name="p3244152018370"></a><a name="p3244152018370"></a>HBM Single Bit Next-Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p313252173018"><a name="p313252173018"></a><a name="p313252173018"></a>片上内存单比特错误待隔离内存页数量（预留字段，暂不使用，<span>固定输出0</span>）。</p>
<div class="note" id="note865282320918"><a name="note865282320918"></a><a name="note865282320918"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000002613572513_p1967116168326"><a name="zh-cn_topic_0000002613572513_p1967116168326"></a><a name="zh-cn_topic_0000002613572513_p1967116168326"></a>待隔离内存页数量通过复位NPU、重启系统、iBMC网管上下电或AC上下电操作刷新为隔离内存页数量。</p>
</div></div>
</td>
</tr>
<tr id="row18065326443"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p11630122213375"><a name="p11630122213375"></a><a name="p11630122213375"></a>HBM Double Bit Next-Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p137361436183014"><a name="p137361436183014"></a><a name="p137361436183014"></a>片上内存多比特错误待隔离内存页数量，取值范围0~64。</p>
<div class="note" id="note147161010452"><a name="note147161010452"></a><a name="note147161010452"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000002613572513_p1967116168326_1"><a name="zh-cn_topic_0000002613572513_p1967116168326_1"></a><a name="zh-cn_topic_0000002613572513_p1967116168326_1"></a>待隔离内存页数量通过复位NPU、重启系统、iBMC网管上下电或AC上下电操作刷新为隔离内存页数量。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

> **说明：** 
> 
> 片上内存单比特当前错误计数、片上内存多比特当前错误计数、片上内存生命周期内所有单比特错误数量和片上内存生命周期内所有多比特错误数量的最大支持统计值均为4294967295。
