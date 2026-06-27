# dcmiv2\_clear\_device\_user\_config<a name="EN-US_TOPIC_0000002314045182"></a>

## Prototype<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_toc533412077"></a>

**int dcmiv2\_clear\_device\_user\_config\(int dev\_id, const char \*config\_name\)**

## Description<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_toc533412078"></a>

Clears user configuration.

For details about the default values, see  [dcmiv2\_set\_device\_user\_config](dcmiv2_set_device_user_config.md).

## Parameter Description<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_toc533412079"></a>

<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p10021890"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p10021890"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p6466753"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p6466753"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.990000000000002%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p54045009"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p54045009"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.01%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p15569626"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p15569626"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p7711145152918"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p7711145152918"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p671116522914"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p671116522914"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1771116572910"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1771116572910"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_row6326181581618"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p146993253912"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p146993253912"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p146993253912"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p469916256914"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p469916256914"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p469916256914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1633516491298"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1633516491298"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1633516491298"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a>Configuration item name, up to 32 characters.</p>
<p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1795311111557"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1795311111557"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1795311111557"></a>Supported configuration items: <strong id="b151211444191319"><a name="b151211444191319"></a><a name="b151211444191319"></a>mac_info</strong> and <strong id="b1512184431312"><a name="b1512184431312"></a><a name="b1512184431312"></a>cert_expired_threshold</strong>. Custom names are supported.</p>
<p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p189533165513"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p189533165513"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p189533165513"></a>The configuration items are described as follows:</p>
<a name="ul19317152017148"></a><a name="ul19317152017148"></a><ul id="ul19317152017148"><li><strong id="b1595017575208"><a name="b1595017575208"></a><a name="b1595017575208"></a>mac_info</strong>: sets the MAC address.</li><li><strong id="b42983484139"><a name="b42983484139"></a><a name="b42983484139"></a>cert_expired_threshold</strong>: sets the certificate expiration threshold.</li></ul>
<div class="note" id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_note1462701516448"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_note1462701516448"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_en-us_topic_0204328569_note1462701516448"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1096212366311"><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1096212366311"></a><a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_p1096212366311"></a>After calling this API, you need to reset the chip for the configuration to take effect. Then, you can call <a href="dcmiv2_get_device_user_config.md">dcmiv2_get_device_user_config</a> to inspect the configuration result.</p>
</div></div>
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

## Restrictions<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_toc533412082"></a>

Since the flash memory has a limited number of program-erase \(PE\) cycles, avoid unnecessary calls to this API.

This API needs to call TEEOS, which takes a long time. It does not support triggering hibernation/wake-up during the call. If hibernation is triggered, there is a high likelihood of hibernation failure.

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001206627180_en-us_topic_0000001178054664_en-us_topic_0000001102358324_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
const char *config_name = "mac_info";
ret = dcmiv2_clear_device_user_config(dev_id, config_name);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}
...
```
