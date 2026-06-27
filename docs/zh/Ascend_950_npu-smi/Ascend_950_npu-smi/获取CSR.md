# 获取CSR<a name="ZH-CN_TOPIC_0000002583172650"></a>

## 功能说明<a name="zh-cn_topic_0000001897339252_section1943544104812"></a>

用于获取TLS证书对应的CSR文件。

## 命令格式<a name="zh-cn_topic_0000001897339252_section164424414486"></a>

`npu-smi info -t tls-csr-get -i dev_id`

## 参数说明<a name="zh-cn_topic_0000001897339252_section645174414488"></a>

<a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_table7208814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"></a><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p3985976"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"></a><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p54428625"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"></a><a name="zh-cn_topic_0000001897339252_zh-cn_topic_0000001220416486_zh-cn_topic_0000001168070435_p57396781"></a><em id="i12830164192620"><a name="i12830164192620"></a><a name="i12830164192620"></a><span id="ph168304413268"><a name="ph168304413268"></a><a name="ph168304413268"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000002484466710_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="zh-cn_topic_0000002613572411_ph861524220464"><a name="zh-cn_topic_0000002613572411_ph861524220464"></a><a name="zh-cn_topic_0000002613572411_ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000002613572411_zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001897339252_section145711449481"></a>

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

## 使用示例<a name="zh-cn_topic_0000001897339252_section1110394413482"></a>

获取设备0的TLS证书对应的CSR文件。

```bash
npu-smi info -t tls-csr-get -i 0
```

```text
Enter country_name|province_name|city_name|organization_name|department_name.
Example: CN|ZHEJIANG|HANGZHOU|Huawei|Marketing
CN|ZHEJIANG|HANGZHOU|*|Marketing
        Message                        : The tls csr file of the chip is obtained successfully.
```

查看已生成的CSR文件。

```text
cat /run/csr/cert_type_PKI2.0_tls_*.csr
-----BEGIN CERTIFICATE REQUEST-----
MIIEzzCCArkCAQAwgYsxCzAJBgNVBAYTAkNOMQ8wDQYDVQQKDAZIdWF3ZWkxETAP
BgNVBAgMCFpIRUpJQU5HMREwDwYDVQQHDAhIQU5HWkhPVTESMBAGA1UECwwJTWFy
*********************************************************
-----END CERTIFICATE REQUEST-----
```

> **说明：** 
> 
> /run/csr/是CSR文件路径。

## 输出说明<a name="zh-cn_topic_0000001897339252_section21061544144810"></a>

**表 2**  打印信息说明

<a name="table13130194414811"></a>
<table><thead align="left"><tr id="row142291944144816"><th class="cellrowborder" valign="top" width="49.49%" id="mcps1.2.3.1.1"><p id="p8230144410489"><a name="p8230144410489"></a><a name="p8230144410489"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.2.3.1.2"><p id="p723024484811"><a name="p723024484811"></a><a name="p723024484811"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1523084484817"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p14230184484813"><a name="p14230184484813"></a><a name="p14230184484813"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p4230184464819"><a name="p4230184464819"></a><a name="p4230184464819"></a>命令执行后的提示信息。</p>
</td>
</tr>
</tbody>
</table>
