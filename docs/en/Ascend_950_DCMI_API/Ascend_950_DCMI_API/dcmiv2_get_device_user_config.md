# dcmiv2\_get\_device\_user\_config<a name="EN-US_TOPIC_0000002348043833"></a>

## Prototype<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_toc533412077"></a>

**int dcmiv2\_get\_device\_user\_config\(int dev\_id, const char \*config\_name, unsigned int buf\_size, unsigned char \*buf\)**

## Description<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_toc533412078"></a>

Obtains user configuration.

## Parameter Description<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_toc533412079"></a>

<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p10021890"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p10021890"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p6466753"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p6466753"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p54045009"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p54045009"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p15569626"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p15569626"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p7711145152918"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p7711145152918"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p671116522914"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p671116522914"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1771116572910"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1771116572910"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1762123612289"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1762123612289"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1762123612289"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p46211236182811"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p46211236182811"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p46211236182811"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1662112368286"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1662112368286"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1662112368286"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a>Configuration item name, up to 32 characters.</p>
<p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1795311111557"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1795311111557"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1795311111557"></a>Supported configuration items: <strong id="b077521491218"><a name="b077521491218"></a><a name="b077521491218"></a>mac_info</strong> and <strong id="b477591421212"><a name="b477591421212"></a><a name="b477591421212"></a>cert_expired_threshold</strong>. Custom names are supported.</p>
<p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p189533165513"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p189533165513"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p189533165513"></a>The configuration items are described as follows:</p>
<a name="ul6465145641315"></a><a name="ul6465145641315"></a><ul id="ul6465145641315"><li><strong id="b5652172001210"><a name="b5652172001210"></a><a name="b5652172001210"></a>mac_info</strong>: sets the MAC address.</li><li><strong id="b127429321126"><a name="b127429321126"></a><a name="b127429321126"></a>cert_expired_threshold</strong>: obtains the certificate expiration threshold.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_row7362613153313"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p347295412284"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p347295412284"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p347295412284"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1847275412814"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1847275412814"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1847275412814"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1472195462814"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1472195462814"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1472195462814"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p18198579293"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p18198579293"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p18198579293"></a>Buffer size, up to 1 KB.</p>
<p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p08451907465"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p08451907465"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p08451907465"></a>For details, see <a href="dcmiv2_set_device_user_config.md">dcmiv2_set_device_user_config</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_row677353102819"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p176251747192415"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p176251747192415"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p176251747192415"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1862534712243"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1862534712243"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p1862534712243"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p462554719244"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p462554719244"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_p462554719244"></a>unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p32012572298"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p32012572298"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_en-us_topic_0158027667_p32012572298"></a>Buffer pointer, pointing to the configuration option.</p>
<p id="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p1837751610327"><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p1837751610327"></a><a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_en-us_topic_0293880893_en-us_topic_0204328552_p1837751610327"></a>For details, see <a href="dcmiv2_set_device_user_config.md">dcmiv2_set_device_user_config</a>.</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p65514914017"><a name="en-us_topic_0000002347924121_p65514914017"></a><a name="en-us_topic_0000002347924121_p65514914017"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p56108061"><a name="en-us_topic_0000002347924121_p56108061"></a><a name="en-us_topic_0000002347924121_p56108061"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1855189908"><a name="en-us_topic_0000002347924121_p1855189908"></a><a name="en-us_topic_0000002347924121_p1855189908"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10771327123917"><a name="en-us_topic_0000002347924121_p10771327123917"></a><a name="en-us_topic_0000002347924121_p10771327123917"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><strong id="en-us_topic_0000002347924121_b5395653155415"><a name="en-us_topic_0000002347924121_b5395653155415"></a><a name="en-us_topic_0000002347924121_b5395653155415"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b16340205411546"><a name="en-us_topic_0000002347924121_b16340205411546"></a><a name="en-us_topic_0000002347924121_b16340205411546"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p56110815619"><a name="en-us_topic_0000002347924121_p56110815619"></a><a name="en-us_topic_0000002347924121_p56110815619"></a><strong id="en-us_topic_0000002347924121_b1325919551546"><a name="en-us_topic_0000002347924121_b1325919551546"></a><a name="en-us_topic_0000002347924121_b1325919551546"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><strong id="en-us_topic_0000002347924121_b7873135516543"><a name="en-us_topic_0000002347924121_b7873135516543"></a><a name="en-us_topic_0000002347924121_b7873135516543"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p977116273398"><a name="en-us_topic_0000002347924121_p977116273398"></a><a name="en-us_topic_0000002347924121_p977116273398"></a><strong id="en-us_topic_0000002347924121_b868415562549"><a name="en-us_topic_0000002347924121_b868415562549"></a><a name="en-us_topic_0000002347924121_b868415562549"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p144147361596"><a name="en-us_topic_0000002347924121_p144147361596"></a><a name="en-us_topic_0000002347924121_p144147361596"></a><span id="en-us_topic_0000002347924121_ph12140626193614"><a name="en-us_topic_0000002347924121_ph12140626193614"></a><a name="en-us_topic_0000002347924121_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13356146465"><a name="en-us_topic_0000002347924121_p13356146465"></a><a name="en-us_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p19351314124620"><a name="en-us_topic_0000002347924121_p19351314124620"></a><a name="en-us_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p1577514751713"><a name="en-us_topic_0000002347924121_p1577514751713"></a><a name="en-us_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1435121434611"><a name="en-us_topic_0000002347924121_p1435121434611"></a><a name="en-us_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p8318151920427"><a name="en-us_topic_0000002347924121_p8318151920427"></a><a name="en-us_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p56258171305"><a name="en-us_topic_0000002347924121_p56258171305"></a><a name="en-us_topic_0000002347924121_p56258171305"></a><span id="en-us_topic_0000002347924121_ph15391145912019"><a name="en-us_topic_0000002347924121_ph15391145912019"></a><a name="en-us_topic_0000002347924121_ph15391145912019"></a>Note: <strong id="en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251227169_en-us_topic_0000001223494383_en-us_topic_0000001102290298_toc533412083"></a>

```c
...
#define BUF_SIZE 16
int ret = 0;
int dev_id = 0;
const char *config_name = "mac_info";
unsigned char buf[BUF_SIZE] = {0};
ret=dcmiv2_get_device_user_config(dev_id, config_name, BUF_SIZE, buf);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}
...
```
