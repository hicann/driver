# dcmiv2\_upgrade\_vrd<a name="EN-US_TOPIC_0000002533268079"></a>

## Prototype<a name="en-us_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_upgrade\_vrd\(int dev\_id, const char \*file\)**

## Description<a name="en-us_topic_0000002227065381_section126852122411"></a>

Upgrades the VRD firmware.

## Parameter Description<a name="en-us_topic_0000002227065381_section1527155212240"></a>

<a name="en-us_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="en-us_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002227065381_p1467135212241"><a name="en-us_topic_0000002227065381_p1467135212241"></a><a name="en-us_topic_0000002227065381_p1467135212241"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002227065381_p1367152172415"><a name="en-us_topic_0000002227065381_p1367152172415"></a><a name="en-us_topic_0000002227065381_p1367152172415"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002227065381_p1967952112412"><a name="en-us_topic_0000002227065381_p1967952112412"></a><a name="en-us_topic_0000002227065381_p1967952112412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002227065381_p967135212413"><a name="en-us_topic_0000002227065381_p967135212413"></a><a name="en-us_topic_0000002227065381_p967135212413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002227065381_row146720522240"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002227065381_p8672522246"><a name="en-us_topic_0000002227065381_p8672522246"></a><a name="en-us_topic_0000002227065381_p8672522246"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002227065381_p667452182410"><a name="en-us_topic_0000002227065381_p667452182410"></a><a name="en-us_topic_0000002227065381_p667452182410"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002227065381_p116705215249"><a name="en-us_topic_0000002227065381_p116705215249"></a><a name="en-us_topic_0000002227065381_p116705215249"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000002227065381_row667452172412"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p168608275467"><a name="p168608275467"></a><a name="p168608275467"></a>file</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002227065381_p86718523246"><a name="en-us_topic_0000002227065381_p86718523246"></a><a name="en-us_topic_0000002227065381_p86718523246"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002227065381_p26718521243"><a name="en-us_topic_0000002227065381_p26718521243"></a><a name="en-us_topic_0000002227065381_p26718521243"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227159_en-us_topic_0000001223172947_en-us_topic_0000001148530297_p868945411372"><a name="en-us_topic_0000001251227159_en-us_topic_0000001223172947_en-us_topic_0000001148530297_p868945411372"></a><a name="en-us_topic_0000001251227159_en-us_topic_0000001223172947_en-us_topic_0000001148530297_p868945411372"></a>VRD upgrade package.</p>
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

## Restrictions<a name="section113625214244"></a>

**Table  1** Support in different deployment scenarios

<a name="table1495412398240"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row1219955113916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1519555163918"><a name="en-us_topic_0000002347924121_p1519555163918"></a><a name="en-us_topic_0000002347924121_p1519555163918"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p10191551393"><a name="en-us_topic_0000002347924121_p10191551393"></a><a name="en-us_topic_0000002347924121_p10191551393"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p31935573913"><a name="en-us_topic_0000002347924121_p31935573913"></a><a name="en-us_topic_0000002347924121_p31935573913"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p419125563917"><a name="en-us_topic_0000002347924121_p419125563917"></a><a name="en-us_topic_0000002347924121_p419125563917"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p019555103920"><a name="en-us_topic_0000002347924121_p019555103920"></a><a name="en-us_topic_0000002347924121_p019555103920"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row2019185519395"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p519205514399"><a name="en-us_topic_0000002347924121_p519205514399"></a><a name="en-us_topic_0000002347924121_p519205514399"></a><strong id="en-us_topic_0000002347924121_b1448581182"><a name="en-us_topic_0000002347924121_b1448581182"></a><a name="en-us_topic_0000002347924121_b1448581182"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p51918553399"><a name="en-us_topic_0000002347924121_p51918553399"></a><a name="en-us_topic_0000002347924121_p51918553399"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b1665844552"><a name="en-us_topic_0000002347924121_b1665844552"></a><a name="en-us_topic_0000002347924121_b1665844552"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p31917558393"><a name="en-us_topic_0000002347924121_p31917558393"></a><a name="en-us_topic_0000002347924121_p31917558393"></a><strong id="en-us_topic_0000002347924121_b1995752126"><a name="en-us_topic_0000002347924121_b1995752126"></a><a name="en-us_topic_0000002347924121_b1995752126"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2194555398"><a name="en-us_topic_0000002347924121_p2194555398"></a><a name="en-us_topic_0000002347924121_p2194555398"></a><strong id="en-us_topic_0000002347924121_b1159965305"><a name="en-us_topic_0000002347924121_b1159965305"></a><a name="en-us_topic_0000002347924121_b1159965305"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p21995593919"><a name="en-us_topic_0000002347924121_p21995593919"></a><a name="en-us_topic_0000002347924121_p21995593919"></a><strong id="en-us_topic_0000002347924121_b1117742169"><a name="en-us_topic_0000002347924121_b1117742169"></a><a name="en-us_topic_0000002347924121_b1117742169"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row101915558397"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p8191355143917"><a name="en-us_topic_0000002347924121_p8191355143917"></a><a name="en-us_topic_0000002347924121_p8191355143917"></a><span id="en-us_topic_0000002347924121_ph819115583917"><a name="en-us_topic_0000002347924121_ph819115583917"></a><a name="en-us_topic_0000002347924121_ph819115583917"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p12191055143917"><a name="en-us_topic_0000002347924121_p12191055143917"></a><a name="en-us_topic_0000002347924121_p12191055143917"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p2191255113910"><a name="en-us_topic_0000002347924121_p2191255113910"></a><a name="en-us_topic_0000002347924121_p2191255113910"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p51912552396"><a name="en-us_topic_0000002347924121_p51912552396"></a><a name="en-us_topic_0000002347924121_p51912552396"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1201455113912"><a name="en-us_topic_0000002347924121_p1201455113912"></a><a name="en-us_topic_0000002347924121_p1201455113912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p220955113913"><a name="en-us_topic_0000002347924121_p220955113913"></a><a name="en-us_topic_0000002347924121_p220955113913"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row4201855143918"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p112012555392"><a name="en-us_topic_0000002347924121_p112012555392"></a><a name="en-us_topic_0000002347924121_p112012555392"></a><span id="en-us_topic_0000002347924121_ph921055143919"><a name="en-us_topic_0000002347924121_ph921055143919"></a><a name="en-us_topic_0000002347924121_ph921055143919"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000002227065381_section6395526248"></a>

```c
...
int ret = 0;
int dev_id = 0;
const char *file = "Atlas-A5-hdk-vrd-firmware_xxx.hpm";
ret = dcmiv2_upgrade_vrd(dev_id, file);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
