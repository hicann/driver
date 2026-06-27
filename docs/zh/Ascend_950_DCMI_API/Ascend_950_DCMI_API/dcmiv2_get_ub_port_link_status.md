# dcmiv2\_get\_ub\_port\_link\_status<a name="ZH-CN_TOPIC_0000002524828419"></a>

## 函数原型<a name="zh-cn_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_get\_ub\_port\_link\_status \(int dev\_id, struct dcmi\_ub\_port\_link\_status \*ub\_status\)**

## 功能说明<a name="zh-cn_topic_0000002227065381_section126852122411"></a>

查询指定芯片的UB建链状态信息。

## 参数说明<a name="zh-cn_topic_0000002227065381_section1527155212240"></a>

<a name="zh-cn_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000002227065381_p1467135212241"><a name="zh-cn_topic_0000002227065381_p1467135212241"></a><a name="zh-cn_topic_0000002227065381_p1467135212241"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000002227065381_p1367152172415"><a name="zh-cn_topic_0000002227065381_p1367152172415"></a><a name="zh-cn_topic_0000002227065381_p1367152172415"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000002227065381_p1967952112412"><a name="zh-cn_topic_0000002227065381_p1967952112412"></a><a name="zh-cn_topic_0000002227065381_p1967952112412"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000002227065381_p967135212413"><a name="zh-cn_topic_0000002227065381_p967135212413"></a><a name="zh-cn_topic_0000002227065381_p967135212413"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002227065381_row667452172412"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000002227065381_p1767185202414"><a name="zh-cn_topic_0000002227065381_p1767185202414"></a><a name="zh-cn_topic_0000002227065381_p1767185202414"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000002227065381_p86718523246"><a name="zh-cn_topic_0000002227065381_p86718523246"></a><a name="zh-cn_topic_0000002227065381_p86718523246"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000002227065381_p26718521243"><a name="zh-cn_topic_0000002227065381_p26718521243"></a><a name="zh-cn_topic_0000002227065381_p26718521243"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row3473517121611"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p4473151731615"><a name="p4473151731615"></a><a name="p4473151731615"></a>ub_status</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p94731217191618"><a name="p94731217191618"></a><a name="p94731217191618"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p14473191712164"><a name="p14473191712164"></a><a name="p14473191712164"></a>struct dcmi_ub_port_link_status<strong id="b1336335012171"><a name="b1336335012171"></a><a name="b1336335012171"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1247315177160"><a name="p1247315177160"></a><a name="p1247315177160"></a>UB建链状态信息。</p>
<pre class="codeblock" id="codeblock99772715811"><a name="codeblock99772715811"></a><a name="codeblock99772715811"></a>#define DCMI_UB_PORT_NUM 36        //NPU芯片端口数量
typedef enum {
DCMI_UB_ALL_PORT_NO_LINK = 0, //所有端口未建链
DCMI_UB_ALL_PORT_LINK, //所有端口建链
DCMI_UB_PARTIAL_PORT_LINK, //部分端口建链
DCMI_UB_NO_NEED_LINK, //断链标记无需建链
} dcmi_entire_ub_status; /* 芯片维度：0-2: actual link status, 3: link requirement */
typedef enum {
DCMI_UB_PORT_STATUS_NONE_LANE = 0, //芯片端口不存在
DCMI_UB_PORT_STATUS_FULL_LANE, //端口建链全带宽
DCMI_UB_PORT_STATUS_PARTIAL_LANE, //端口建链部分带宽
DCMI_UB_PORT_STATUS_INITIAL, //初始化状态未建链
} dcmi_ub_port_status; /* 芯片端口维度 */
struct dcmi_ub_port_link_status {
dcmi_entire_ub_status ub_link_status;
dcmi_ub_port_status ub_port_status[DCMI_UB_PORT_NUM];
};</pre>
<div class="note" id="note2025933092110"><a name="note2025933092110"></a><a name="note2025933092110"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1625915304213"><a name="p1625915304213"></a><a name="p1625915304213"></a>DCMI_UB_PORT_NUM定义36个NPU芯片端口数量，实际加速卡环境只有前9个NPU芯片端口返回实际的端口建链状态（4卡互联场景的UB端口ID为4、5、6，2卡互联场景的UB端口ID为4、5、6、8），其他返回DCMI_UB_PORT_STATUS_NONE_LANE。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="section3331752122419"></a>

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="section113625214244"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1495412398240"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row313212815215"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row61328855215"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row7132208165219"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p15420103714516"><a name="zh-cn_topic_0000002347924121_p15420103714516"></a><a name="zh-cn_topic_0000002347924121_p15420103714516"></a><span id="zh-cn_topic_0000002347924121_ph6420193745115"><a name="zh-cn_topic_0000002347924121_ph6420193745115"></a><a name="zh-cn_topic_0000002347924121_ph6420193745115"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p399810267455"><a name="zh-cn_topic_0000002347924121_p399810267455"></a><a name="zh-cn_topic_0000002347924121_p399810267455"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p199994269451"><a name="zh-cn_topic_0000002347924121_p199994269451"></a><a name="zh-cn_topic_0000002347924121_p199994269451"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p50172714514"><a name="zh-cn_topic_0000002347924121_p50172714514"></a><a name="zh-cn_topic_0000002347924121_p50172714514"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p8957193025710"><a name="zh-cn_topic_0000002347924121_p8957193025710"></a><a name="zh-cn_topic_0000002347924121_p8957193025710"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row6356211905"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><span id="zh-cn_topic_0000002347924121_ph39818321514"><a name="zh-cn_topic_0000002347924121_ph39818321514"></a><a name="zh-cn_topic_0000002347924121_ph39818321514"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000002227065381_section6395526248"></a>

```c
…
int ret = 0;
int dev_id = 0;
struct dcmi_ub_port_link_status ub_status = {0};
ret = dcmiv2_get_ub_port_link_status(dev_id,&ub_status);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```
