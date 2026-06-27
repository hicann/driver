# 预置/更新TLS证书<a name="ZH-CN_TOPIC_0000002613572373"></a>

## 功能说明<a name="zh-cn_topic_0000001937698749_section1012914384613"></a>

用于导入TLS证书。

## 命令格式<a name="zh-cn_topic_0000001937698749_section913083810614"></a>

`npu-smi set -t tls-cert -i dev_id -f "TLS证书 CA根证书 二级CA证书"`

## 参数说明<a name="zh-cn_topic_0000001937698749_section1813112381066"></a>

<a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_table7208814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"></a><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"></a><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"></a><a name="zh-cn_topic_0000001937698749_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"></a><em id="i5270129122719"><a name="i5270129122719"></a><a name="i5270129122719"></a><span id="ph52707942715"><a name="ph52707942715"></a><a name="ph52707942715"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="zh-cn_topic_0000002613572411_ph861524220464"><a name="zh-cn_topic_0000002613572411_ph861524220464"></a><a name="zh-cn_topic_0000002613572411_ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001937698749_row098220478355"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001937698749_p2214041215"><a name="zh-cn_topic_0000001937698749_p2214041215"></a><a name="zh-cn_topic_0000001937698749_p2214041215"></a><em id="zh-cn_topic_0000001937698749_i20244091210"><a name="zh-cn_topic_0000001937698749_i20244091210"></a><a name="zh-cn_topic_0000001937698749_i20244091210"></a>TLS证书 CA根证书 二级CA证书</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001937698749_p69831847103512"><a name="zh-cn_topic_0000001937698749_p69831847103512"></a><a name="zh-cn_topic_0000001937698749_p69831847103512"></a>TLS证书路径、CA根证书路径、二级CA证书路径。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001937698749_section814218382062"></a>

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_row964854311460"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_p13648143204610"><a name="zh-cn_topic_0000002583332642_p13648143204610"></a><a name="zh-cn_topic_0000002583332642_p13648143204610"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_p1864874319464"><a name="zh-cn_topic_0000002583332642_p1864874319464"></a><a name="zh-cn_topic_0000002583332642_p1864874319464"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p8648124314461"><a name="zh-cn_topic_0000002583332642_p8648124314461"></a><a name="zh-cn_topic_0000002583332642_p8648124314461"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_p7648843164617"><a name="zh-cn_topic_0000002583332642_p7648843164617"></a><a name="zh-cn_topic_0000002583332642_p7648843164617"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_p7648174364614"><a name="zh-cn_topic_0000002583332642_p7648174364614"></a><a name="zh-cn_topic_0000002583332642_p7648174364614"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_row8648643184618"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_p1164844314620"><a name="zh-cn_topic_0000002583332642_p1164844314620"></a><a name="zh-cn_topic_0000002583332642_p1164844314620"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_p96483431466"><a name="zh-cn_topic_0000002583332642_p96483431466"></a><a name="zh-cn_topic_0000002583332642_p96483431466"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p11648174310465"><a name="zh-cn_topic_0000002583332642_p11648174310465"></a><a name="zh-cn_topic_0000002583332642_p11648174310465"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_p264864313463"><a name="zh-cn_topic_0000002583332642_p264864313463"></a><a name="zh-cn_topic_0000002583332642_p264864313463"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_p19648943114611"><a name="zh-cn_topic_0000002583332642_p19648943114611"></a><a name="zh-cn_topic_0000002583332642_p19648943114611"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_row12648144394611"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p1764844354613"><a name="zh-cn_topic_0000002583332642_p1764844354613"></a><a name="zh-cn_topic_0000002583332642_p1764844354613"></a><span id="zh-cn_topic_0000002583332642_ph46481643174611"><a name="zh-cn_topic_0000002583332642_ph46481643174611"></a><a name="zh-cn_topic_0000002583332642_ph46481643174611"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_p6648194364615"><a name="zh-cn_topic_0000002583332642_p6648194364615"></a><a name="zh-cn_topic_0000002583332642_p6648194364615"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_p136487437467"><a name="zh-cn_topic_0000002583332642_p136487437467"></a><a name="zh-cn_topic_0000002583332642_p136487437467"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_p26077503460"><a name="zh-cn_topic_0000002583332642_p26077503460"></a><a name="zh-cn_topic_0000002583332642_p26077503460"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p18611175034612"><a name="zh-cn_topic_0000002583332642_p18611175034612"></a><a name="zh-cn_topic_0000002583332642_p18611175034612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_p1161365020461"><a name="zh-cn_topic_0000002583332642_p1161365020461"></a><a name="zh-cn_topic_0000002583332642_p1161365020461"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row10649154311467"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p12649164316467"><a name="zh-cn_topic_0000002583332642_p12649164316467"></a><a name="zh-cn_topic_0000002583332642_p12649164316467"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001937698749_section81981638760"></a>

设备0导入TLS证书。

```bash
npu-smi set -t tls-cert -i 0 -f "rsa.d2.pem rsa.rca.pem rsa.oca.pem"
```

```text
        Status                         : OK
        Message                        : The tls-cert of the chip is set successfully.
```

## 输出说明<a name="zh-cn_topic_0000001937698749_section9199538460"></a>

**表 2**  打印信息说明

<a name="table5232133817619"></a>
<table><thead align="left"><tr id="row1436523813615"><th class="cellrowborder" valign="top" width="49.49%" id="mcps1.2.3.1.1"><p id="p63652380614"><a name="p63652380614"></a><a name="p63652380614"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.2.3.1.2"><p id="p153654388611"><a name="p153654388611"></a><a name="p153654388611"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row836511381611"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p136514381366"><a name="p136514381366"></a><a name="p136514381366"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p33657383620"><a name="p33657383620"></a><a name="p33657383620"></a>命令执行结果。</p>
<p id="p10365338463"><a name="p10365338463"></a><a name="p10365338463"></a>有如下两种状态：OK，Fail。</p>
</td>
</tr>
<tr id="row183658381163"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p1236615381866"><a name="p1236615381866"></a><a name="p1236615381866"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p036617381966"><a name="p036617381966"></a><a name="p036617381966"></a>命令执行后的提示信息。</p>
</td>
</tr>
</tbody>
</table>
