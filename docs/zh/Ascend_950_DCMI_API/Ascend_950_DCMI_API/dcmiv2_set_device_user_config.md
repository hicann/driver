# dcmiv2\_set\_device\_user\_config<a name="ZH-CN_TOPIC_0000002314204978"></a>

## 函数原型<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_toc533412077"></a>

**int dcmiv2\_set\_device\_user\_config\(int dev\_id, const char \*config\_name, unsigned int buf\_size, char \*buf\)**

## 功能说明<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_toc533412078"></a>

设置用户配置。

## 参数说明<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_toc533412079"></a>

<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p10021890"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p10021890"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p6466753"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p6466753"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="12.3%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p54045009"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p54045009"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="55.67999999999999%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p15569626"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p15569626"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p7711145152918"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p7711145152918"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p671116522914"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p671116522914"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="12.3%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1771116572910"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1771116572910"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="55.67999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1762123612289"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1762123612289"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1762123612289"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p46211236182811"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p46211236182811"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p46211236182811"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="12.3%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1662112368286"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1662112368286"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1662112368286"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="55.67999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"></a>目前支持处理的配置项名称如下，配置项名称的字符串长度最大为32。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1795311111557"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1795311111557"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1795311111557"></a>已实现功能的配置项：mac_info<span id="ph74595420195"><a name="ph74595420195"></a><a name="ph74595420195"></a>、cert_expired_threshold</span>。支持用户自定义名称配置。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189533165513"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189533165513"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189533165513"></a>配置项功能说明如下：</p>
<p id="p13747195920471"><a name="p13747195920471"></a><a name="p13747195920471"></a>"mac_info" ：用于设置MAC地址。</p>
<p id="p1445341171913"><a name="p1445341171913"></a><a name="p1445341171913"></a>"cert_expired_threshold"：用于设置证书过期时间阈值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_row677353102819"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p347295412284"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p347295412284"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p347295412284"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1847275412814"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1847275412814"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1847275412814"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="12.3%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1472195462814"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1472195462814"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1472195462814"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="55.67999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p18198579293"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p18198579293"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p18198579293"></a>buf长度，单位为byte，最大长度为1K byte。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p33509511202"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p33509511202"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p33509511202"></a>支持mac_info<span id="ph665414273197"><a name="ph665414273197"></a><a name="ph665414273197"></a>、</span><span id="ph543640181918"><a name="ph543640181918"></a><a name="ph543640181918"></a>cert_expired_threshold</span>配置。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p5350155152014"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p5350155152014"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p5350155152014"></a>目前支持处理的配置项名称如下：</p>
<p id="p2542749172219"><a name="p2542749172219"></a><a name="p2542749172219"></a>如果配置"mac_info" ：buf_size参数固定配置为16。</p>
<p id="p35475548193"><a name="p35475548193"></a><a name="p35475548193"></a>如果配置“cert_expired_threshold”：buf_size参数固定配置为1。</p>
<p id="p7865034114310"><a name="p7865034114310"></a><a name="p7865034114310"></a>除了如上固定的名称外，其他最大长度不超过1024 byte。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_row19625184713240"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p176251747192415"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p176251747192415"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p176251747192415"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1862534712243"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1862534712243"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1862534712243"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="12.3%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p462554719244"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p462554719244"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p462554719244"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="55.67999999999999%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p32012572298"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p32012572298"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p32012572298"></a>buf指针，指向配置项内容。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1398395362310"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1398395362310"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p1398395362310"></a>支持mac_info配置。</p>
<p id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189915342233"><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189915342233"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_p189915342233"></a>目前支持处理的配置项名称如下：</p>
<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_ul626216442429"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_ul626216442429"></a><ul id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_zh-cn_topic_0204328569_ul626216442429"><li>针对"mac_info"配置项，默认值为空，包含内容如下：<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_ul10163124817104"></a><a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_ul10163124817104"></a><ul id="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_ul10163124817104"><li>buf[0]~buf[1]： crc_value，对应于buf[2]~buf[10]的CRC校验值；</li><li>buf[2]：data_length，固定为9；</li><li>buf[3]： mac_id，对应于MAC_ID；</li><li>buf[4]：mac_type，对应于MAC类型；</li><li>buf[5]~buf[10]：mac_addr，对应于MAC地址，占6个字节；</li><li>buf[11]~buf[15]：预留，当前没有使用，可置为全0。</li></ul>
</li><li>针对"cert_expired_threshold"配置项，默认值为空，包含内容如下：<p id="p617823151218"><a name="p617823151218"></a><a name="p617823151218"></a>buf[0]：证书过期时间阈值。</p>
</li></ul>
<p id="p1289194120432"><a name="p1289194120432"></a><a name="p1289194120432"></a>除了如上固定的名称外，其他配置项内容请根据实际情况配置。</p>
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

## 约束说明<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p2935151833910"><a name="zh-cn_topic_0000002347924121_p2935151833910"></a><a name="zh-cn_topic_0000002347924121_p2935151833910"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p4935151817398"><a name="zh-cn_topic_0000002347924121_p4935151817398"></a><a name="zh-cn_topic_0000002347924121_p4935151817398"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p1293611188391"><a name="zh-cn_topic_0000002347924121_p1293611188391"></a><a name="zh-cn_topic_0000002347924121_p1293611188391"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p293616189396"><a name="zh-cn_topic_0000002347924121_p293616189396"></a><a name="zh-cn_topic_0000002347924121_p293616189396"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p8936121813397"><a name="zh-cn_topic_0000002347924121_p8936121813397"></a><a name="zh-cn_topic_0000002347924121_p8936121813397"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p6936318183917"><a name="zh-cn_topic_0000002347924121_p6936318183917"></a><a name="zh-cn_topic_0000002347924121_p6936318183917"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p79361718193918"><a name="zh-cn_topic_0000002347924121_p79361718193918"></a><a name="zh-cn_topic_0000002347924121_p79361718193918"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p593617183393"><a name="zh-cn_topic_0000002347924121_p593617183393"></a><a name="zh-cn_topic_0000002347924121_p593617183393"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p2936171814397"><a name="zh-cn_topic_0000002347924121_p2936171814397"></a><a name="zh-cn_topic_0000002347924121_p2936171814397"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1693671803910"><a name="zh-cn_topic_0000002347924121_p1693671803910"></a><a name="zh-cn_topic_0000002347924121_p1693671803910"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p1593651816390"><a name="zh-cn_topic_0000002347924121_p1593651816390"></a><a name="zh-cn_topic_0000002347924121_p1593651816390"></a><span id="zh-cn_topic_0000002347924121_ph2936121814391"><a name="zh-cn_topic_0000002347924121_ph2936121814391"></a><a name="zh-cn_topic_0000002347924121_ph2936121814391"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p189361818183914"><a name="zh-cn_topic_0000002347924121_p189361818183914"></a><a name="zh-cn_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p87162683916"><a name="zh-cn_topic_0000002347924121_p87162683916"></a><a name="zh-cn_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p57342614392"><a name="zh-cn_topic_0000002347924121_p57342614392"></a><a name="zh-cn_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1775132653914"><a name="zh-cn_topic_0000002347924121_p1775132653914"></a><a name="zh-cn_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p377112603919"><a name="zh-cn_topic_0000002347924121_p377112603919"></a><a name="zh-cn_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p9936131853915"><a name="zh-cn_topic_0000002347924121_p9936131853915"></a><a name="zh-cn_topic_0000002347924121_p9936131853915"></a><span id="zh-cn_topic_0000002347924121_ph3936171813916"><a name="zh-cn_topic_0000002347924121_ph3936171813916"></a><a name="zh-cn_topic_0000002347924121_ph3936171813916"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206467198_zh-cn_topic_0000001223494375_zh-cn_topic_0000001148770187_toc533412083"></a>

```c
…
#define BUF_SIZE 16
int ret = 0;
int dev_id = 0;
const char *config_name = "mac_info";
char buf[BUF_SIZE] = {0};
ret=dcmiv2_set_device_user_config(dev_id,config_name, BUF_SIZE, buf);
if (ret != 0) {
    //todo:记录日志
    return ret;
}
…
```
