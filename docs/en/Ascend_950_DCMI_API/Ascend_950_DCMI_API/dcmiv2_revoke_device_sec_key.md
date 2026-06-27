# dcmiv2\_revoke\_device\_sec\_key<a name="EN-US_TOPIC_0000002314204814"></a>

## Prototype<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412077"></a>

**int dcmiv2\_revoke\_device\_sec\_key\(int dev\_id, enum dcmi\_revo\_type input\_type, const unsigned char \*file\_data, unsigned int file\_size\)**

## Description<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412078"></a>

Revokes the key.

## Parameter Description<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412079"></a>

<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.96%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"></a>enum dcmi_revo_type</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"></a>Revocation type.</p>
<pre class="codeblock" id="codeblock163931351123"><a name="codeblock163931351123"></a><a name="codeblock163931351123"></a>enum dcmi_revo_type {
DCMI_REVOCATION_TYPE_SOC = 0, // Revoke the SoC key.
DCMI_REVOCATION_TYPE_CMS_CRL = 1,  // Upgrade the MDC CMS CRL file.
DCMI_REVOCATION_TYPE_CMS_CRL_EXT = 2, // Upgrade the extended CRL file.
DCMI_REVOCATION_TYPE_MAX
};</pre>
<p id="p171201345786"><a name="p171201345786"></a><a name="p171201345786"></a>Currently, only <strong id="b979561194713"><a name="b979561194713"></a><a name="b979561194713"></a>DCMI_REVOCATION_TYPE_SOC</strong> is supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row46671240105418"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"></a>file_data</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"></a>const unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"></a>Data address of the revocation file.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row1306946165516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"></a>file_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a>Data length of the revocation file. The file length for SoC level-2 key revocation is fixed at 544 bytes.</p>
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

## Restrictions<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412082"></a>

- Key revocation is irreversible. Exercise caution when performing this operation.
- Call this API if you want to perform revocation. Correct revocation files are required. Otherwise, the API call may fail.
- The device is no longer available after key revocation.
- This API needs to call TEEOS, which takes a long time. It does not support triggering hibernation/wake-up during the call. If hibernation is triggered, there is a high likelihood of hibernation failure.
- For a Symmetric Multi-Processing \(SMP\) system, the device count must be obtained before key revocation of all devices.

**Table  1** Support in different deployment scenarios

<a name="table155158516230"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row9596171719419"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1059661716417"><a name="en-us_topic_0000002347924121_p1059661716417"></a><a name="en-us_topic_0000002347924121_p1059661716417"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p115964174411"><a name="en-us_topic_0000002347924121_p115964174411"></a><a name="en-us_topic_0000002347924121_p115964174411"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p3663614615"><a name="en-us_topic_0000002347924121_p3663614615"></a><a name="en-us_topic_0000002347924121_p3663614615"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1559620177411"><a name="en-us_topic_0000002347924121_p1559620177411"></a><a name="en-us_topic_0000002347924121_p1559620177411"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10613162423514"><a name="en-us_topic_0000002347924121_p10613162423514"></a><a name="en-us_topic_0000002347924121_p10613162423514"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row959614172418"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p15596151714414"><a name="en-us_topic_0000002347924121_p15596151714414"></a><a name="en-us_topic_0000002347924121_p15596151714414"></a><strong id="en-us_topic_0000002347924121_b95001068569"><a name="en-us_topic_0000002347924121_b95001068569"></a><a name="en-us_topic_0000002347924121_b95001068569"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p559611171344"><a name="en-us_topic_0000002347924121_p559611171344"></a><a name="en-us_topic_0000002347924121_p559611171344"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b12657127135611"><a name="en-us_topic_0000002347924121_b12657127135611"></a><a name="en-us_topic_0000002347924121_b12657127135611"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p866318118620"><a name="en-us_topic_0000002347924121_p866318118620"></a><a name="en-us_topic_0000002347924121_p866318118620"></a><strong id="en-us_topic_0000002347924121_b5599208195615"><a name="en-us_topic_0000002347924121_b5599208195615"></a><a name="en-us_topic_0000002347924121_b5599208195615"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p1959614171345"><a name="en-us_topic_0000002347924121_p1959614171345"></a><a name="en-us_topic_0000002347924121_p1959614171345"></a><strong id="en-us_topic_0000002347924121_b540214925617"><a name="en-us_topic_0000002347924121_b540214925617"></a><a name="en-us_topic_0000002347924121_b540214925617"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p82264478360"><a name="en-us_topic_0000002347924121_p82264478360"></a><a name="en-us_topic_0000002347924121_p82264478360"></a><strong id="en-us_topic_0000002347924121_b142941110185613"><a name="en-us_topic_0000002347924121_b142941110185613"></a><a name="en-us_topic_0000002347924121_b142941110185613"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row135967178414"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p2596121712410"><a name="en-us_topic_0000002347924121_p2596121712410"></a><a name="en-us_topic_0000002347924121_p2596121712410"></a><span id="en-us_topic_0000002347924121_ph259617171249"><a name="en-us_topic_0000002347924121_ph259617171249"></a><a name="en-us_topic_0000002347924121_ph259617171249"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p6596111711414"><a name="en-us_topic_0000002347924121_p6596111711414"></a><a name="en-us_topic_0000002347924121_p6596111711414"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p25961017947"><a name="en-us_topic_0000002347924121_p25961017947"></a><a name="en-us_topic_0000002347924121_p25961017947"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p17398249175310"><a name="en-us_topic_0000002347924121_p17398249175310"></a><a name="en-us_topic_0000002347924121_p17398249175310"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1529918247412"><a name="en-us_topic_0000002347924121_p1529918247412"></a><a name="en-us_topic_0000002347924121_p1529918247412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p1932714266187"><a name="en-us_topic_0000002347924121_p1932714266187"></a><a name="en-us_topic_0000002347924121_p1932714266187"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row155971917944"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p18597217849"><a name="en-us_topic_0000002347924121_p18597217849"></a><a name="en-us_topic_0000002347924121_p18597217849"></a><span id="en-us_topic_0000002347924121_ph3597217240"><a name="en-us_topic_0000002347924121_ph3597217240"></a><a name="en-us_topic_0000002347924121_ph3597217240"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412083"></a>

```c
...
#define REVOCATION_FILE_LEN  544
int dev_id = 0;
int ret = 0;
unsigned char revocation_file_buf[REVOCATION_FILE_LEN] = {0};
unsigned int buf_size = REVOCATION_FILE_LEN;
ret = dcmiv2_revoke_device_sec_key(dev_id, DCMI_REVOCATION_TYPE_SOC, (const unsigned char *)revocation_file_buf, buf_size);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
