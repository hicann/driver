# dcmiv2\_get\_device\_flash\_info<a name="ZH-CN_TOPIC_0000002314204806"></a>

## 函数原型<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_toc533412077"></a>

**int dcmiv2\_get\_device\_flash\_info\(int dev\_id, unsigned int flash\_index, struct dcmi\_flash\_info \*flash\_info\)**

## 功能说明<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_toc533412078"></a>

获取设备内Flash的信息。

## 参数说明<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_toc533412079"></a>

<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p10021890"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p10021890"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6466753"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6466753"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p54045009"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p54045009"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.01%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p15569626"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p15569626"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p7711145152918"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p7711145152918"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p671116522914"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p671116522914"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1771116572910"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1771116572910"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p143031615125113"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p143031615125113"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p143031615125113"></a>flash_index</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p4303171585116"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p4303171585116"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p4303171585116"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1530316159514"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1530316159514"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1530316159514"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p130313153512"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p130313153512"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p130313153512"></a>Flash索引号，通过<a href="dcmiv2_get_device_flash_cnt.md">dcmiv2_get_device_flash_cnt</a>接口获取。取值范围：[0, flash_cnt-1]</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_row177033112516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p5303315115116"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p5303315115116"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p5303315115116"></a>flash_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p14303171511517"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p14303171511517"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p14303171511517"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6303151516512"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6303151516512"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p6303151516512"></a>struct dcmi_flash_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p430301514519"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p430301514519"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p430301514519"></a>返回Flash信息。</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1830312153510"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1830312153510"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1830312153510"></a>Flash信息结构体定义：</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p818710215312"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p818710215312"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p818710215312"></a>struct dcmi_flash_info {</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p518762538"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p518762538"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p518762538"></a>unsigned long long flash_id; //Flash ID</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p131871521832"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p131871521832"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p131871521832"></a>unsigned short device_id; //设备ID</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p191871421437"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p191871421437"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p191871421437"></a>unsigned short vendor; //厂商ID</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p16458162585015"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p16458162585015"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p16458162585015"></a>unsigned int state; //Flash health, 0表示正常，非0表示异常</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p181871821733"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p181871821733"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p181871821733"></a>unsigned long long size; //Flash大小，单位Byte</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p17187321434"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p17187321434"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p17187321434"></a>unsigned int sector_count; //擦除单元数量</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1218720217317"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1218720217317"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p1218720217317"></a>unsigned short manufacturer_id; //制造商ID</p>
<p id="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p141876214319"><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p141876214319"></a><a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_p141876214319"></a>};</p>
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

## 约束说明<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_toc533412082"></a>

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

## 调用示例<a name="zh-cn_topic_0000001251427215_zh-cn_topic_0000001223172955_zh-cn_topic_0000001101490894_toc533412083"></a>

```c
…
unsigned int i;
int ret = 0;
int dev_id = 0;
struct dcmi_flash_info flash_info = {0};
unsigned int flash_cnt = 0;
ret = dcmiv2_get_device_flash_cnt(dev_id, &flash_cnt);
if (ret != 0){
    //todo：记录日志
    return ret;
}
for (i = 0; i < flash_cnt; i++){
    ret = dcmiv2_get_device_flash_info(dev_id, i, &flash_info);
    if(ret != 0){
        //todo：记录日志
        return ret;
    }
}
…
```
