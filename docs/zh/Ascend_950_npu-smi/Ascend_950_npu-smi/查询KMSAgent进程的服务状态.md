# 查询KMSAgent进程的服务状态<a name="ZH-CN_TOPIC_0000002583332460"></a>

## 功能说明<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section18674262006"></a>

用于查询KMSAgent进程（密钥管理进程）的服务状态。

## 命令格式<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section386902615016"></a>

`npu-smi info -t key-manage`

## 参数说明<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section1786919261014"></a>

无

## 使用指南<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section6636145619341"></a>

OpenSSL版本需在3.0.0及以上，若版本不满足要求，请升级OpenSSL版本，建议安装最新且无漏洞版本。

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_row2056819579256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_p10568457202515"><a name="zh-cn_topic_0000002583332642_p10568457202515"></a><a name="zh-cn_topic_0000002583332642_p10568457202515"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_p3568155712520"><a name="zh-cn_topic_0000002583332642_p3568155712520"></a><a name="zh-cn_topic_0000002583332642_p3568155712520"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p7568757122511"><a name="zh-cn_topic_0000002583332642_p7568757122511"></a><a name="zh-cn_topic_0000002583332642_p7568757122511"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_p1556812578254"><a name="zh-cn_topic_0000002583332642_p1556812578254"></a><a name="zh-cn_topic_0000002583332642_p1556812578254"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_p105681557162517"><a name="zh-cn_topic_0000002583332642_p105681557162517"></a><a name="zh-cn_topic_0000002583332642_p105681557162517"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_row185688570253"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_p175691857172519"><a name="zh-cn_topic_0000002583332642_p175691857172519"></a><a name="zh-cn_topic_0000002583332642_p175691857172519"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_p1056925762517"><a name="zh-cn_topic_0000002583332642_p1056925762517"></a><a name="zh-cn_topic_0000002583332642_p1056925762517"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p1256975772514"><a name="zh-cn_topic_0000002583332642_p1256975772514"></a><a name="zh-cn_topic_0000002583332642_p1256975772514"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_p2569157132518"><a name="zh-cn_topic_0000002583332642_p2569157132518"></a><a name="zh-cn_topic_0000002583332642_p2569157132518"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_p656975711257"><a name="zh-cn_topic_0000002583332642_p656975711257"></a><a name="zh-cn_topic_0000002583332642_p656975711257"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_row65691257162516"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p1356905716259"><a name="zh-cn_topic_0000002583332642_p1356905716259"></a><a name="zh-cn_topic_0000002583332642_p1356905716259"></a><span id="zh-cn_topic_0000002583332642_ph1569135714257"><a name="zh-cn_topic_0000002583332642_ph1569135714257"></a><a name="zh-cn_topic_0000002583332642_ph1569135714257"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_p15569657112515"><a name="zh-cn_topic_0000002583332642_p15569657112515"></a><a name="zh-cn_topic_0000002583332642_p15569657112515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_p16569257142516"><a name="zh-cn_topic_0000002583332642_p16569257142516"></a><a name="zh-cn_topic_0000002583332642_p16569257142516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_p127191613267"><a name="zh-cn_topic_0000002583332642_p127191613267"></a><a name="zh-cn_topic_0000002583332642_p127191613267"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p1356945762511"><a name="zh-cn_topic_0000002583332642_p1356945762511"></a><a name="zh-cn_topic_0000002583332642_p1356945762511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_p7569135772519"><a name="zh-cn_topic_0000002583332642_p7569135772519"></a><a name="zh-cn_topic_0000002583332642_p7569135772519"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row55691557132514"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p195699573251"><a name="zh-cn_topic_0000002583332642_p195699573251"></a><a name="zh-cn_topic_0000002583332642_p195699573251"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section66051714132117"></a>

查询KMSAgent进程的服务状态。

```bash
npu-smi info -t key-manage
```

```text
        service auto startup           : Disable
        service running status         : Stop
```

## 输出说明<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p36441839191318"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p36441839191318"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p36441839191318"></a>service auto startup</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p166905557715"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p166905557715"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p166905557715"></a>服务自启动状态，默认状态为：Disable。</p>
<p id="zh-cn_topic_0000001220416510_p1653011774216"><a name="zh-cn_topic_0000001220416510_p1653011774216"></a><a name="zh-cn_topic_0000001220416510_p1653011774216"></a>有如下两种状态：Enable、Disable。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_zh-cn_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p4642739141315"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p4642739141315"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p4642739141315"></a>service running status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p202841353182817"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p202841353182817"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p202841353182817"></a>服务的运行状态，默认状态为：Stop。</p>
<p id="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p428415313286"><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p428415313286"></a><a name="zh-cn_topic_0000001220416510_zh-cn_topic_0000001200340465_p428415313286"></a>有如下两种状态：Running、Stop。</p>
</td>
</tr>
</tbody>
</table>
