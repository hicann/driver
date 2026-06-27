# dcmiv2\_get\_device\_die\_id<a name="ZH-CN_TOPIC_0000002347924117"></a>

## 函数原型<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_toc533412077"></a>

**int dcmiv2\_get\_device\_die\_id\(int dev\_id, enum dcmi\_die\_type input\_type, struct dcmi\_die\_id \*die\_id\)**

## 功能说明<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_toc533412078"></a>

获取指定设备的DIE ID。

## 参数说明<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_toc533412079"></a>

<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p10021890"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p10021890"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p6466753"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p6466753"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p54045009"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p54045009"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p15569626"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p15569626"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7711145152918"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7711145152918"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p671116522914"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p671116522914"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1771116572910"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1771116572910"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_row1019612371857"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p13196937559"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p13196937559"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p13196937559"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p21961837556"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p21961837556"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p21961837556"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1019618371851"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1019618371851"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1019618371851"></a>enum dcmi_die_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7178671263"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7178671263"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p7178671263"></a>die类型。</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p527611516618"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p527611516618"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p527611516618"></a>enum dcmi_die_type {</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p82762513619"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p82762513619"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p82762513619"></a>NDIE,</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p152761959615"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p152761959615"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p152761959615"></a>VDIE,</p>
<p id="p20785201410403"><a name="p20785201410403"></a><a name="p20785201410403"></a>DDIE,</p>
<p id="p16267183204310"><a name="p16267183204310"></a><a name="p16267183204310"></a>INVALID_DIE</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p192761656615"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p192761656615"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p192761656615"></a>};</p>
<div class="note" id="note78344145127"><a name="note78344145127"></a><a name="note78344145127"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p169371152155116"><a name="p169371152155116"></a><a name="p169371152155116"></a>仅支持查询DDIE相关信息。</p>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p18463355636"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p18463355636"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p18463355636"></a>die_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p0463145518316"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p0463145518316"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p0463145518316"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p746320551936"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p746320551936"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p746320551936"></a>struct dcmi_die_id *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p174632559317"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p174632559317"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p174632559317"></a>die_id信息。</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1336612416415"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1336612416415"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1336612416415"></a>struct dcmi_die_id {</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p23662412045"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p23662412045"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p23662412045"></a>unsigned int soc_die[DIE_ID_COUNT]; //芯片Die编号</p>
<p id="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1366341449"><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1366341449"></a><a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_p1366341449"></a>};</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>

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

## 约束说明<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206627176_zh-cn_topic_0000001178213218_zh-cn_topic_0000001101123898_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
enum dcmi_die_type input_type = DDIE;
struct dcmi_die_id die_id = {0};
ret = dcmiv2_get_device_die_id(dev_id, input_type, &die_id);
…
```
