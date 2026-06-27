# dcmiv2\_get\_device\_ub\_slot\_id<a name="EN-US_TOPIC_0000002585785033"></a>

## Prototype<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_toc533412077"></a>

**int dcmiv2\_get\_device\_ub\_slot\_id\(int dev\_id, int \*ub\_slot\)**

## Description<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_toc533412078"></a>

Queries the UB port slot ID of a device.

## Parameter Description<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_toc533412079"></a>

<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10021890"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10021890"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p6466753"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p6466753"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p54045009"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p54045009"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p15569626"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p15569626"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p7711145152918"><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p7711145152918"></a><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p671116522914"><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p671116522914"></a><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p1771116572910"><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p1771116572910"></a><a name="en-us_topic_0000001206147228_en-us_topic_0000001178213206_en-us_topic_0000001101611602_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10696122145715"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10696122145715"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10696122145715"></a>ub_slot</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p17696121165710"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p17696121165710"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p17696121165710"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10697122115710"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10697122115710"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p10697122115710"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p1669792195720"><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p1669792195720"></a><a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_p1669792195720"></a>Slot ID of the UB port.</p>
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

## Restrictions<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table116394134134"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row313212815215"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p9132382529"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p9132382529"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p9132382529"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p165659620015"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p165659620015"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p165659620015"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p177681147617"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p177681147617"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p177681147617"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p15654617010"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p15654617010"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p15654617010"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p4891412143910"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p4891412143910"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p4891412143910"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row61328855215"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p17132168105212"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p17132168105212"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p17132168105212"></a><strong id="b4717535148"><a name="b4717535148"></a><a name="b4717535148"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p171329855216"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p171329855216"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p171329855216"></a>Running User Group (Non-<strong id="b11461154101412"><a name="b11461154101412"></a><a name="b11461154101412"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p07691949613"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p07691949613"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p07691949613"></a><strong id="b1164118555145"><a name="b1164118555145"></a><a name="b1164118555145"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1513228195214"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1513228195214"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1513228195214"></a><strong id="b19811115671418"><a name="b19811115671418"></a><a name="b19811115671418"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p48911512183914"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p48911512183914"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p48911512183914"></a><strong id="b19954145751412"><a name="b19954145751412"></a><a name="b19954145751412"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row7132208165219"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="p144147361596"><a name="p144147361596"></a><a name="p144147361596"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="p772194981912"><a name="p772194981912"></a><a name="p772194981912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="p1372916492196"><a name="p1372916492196"></a><a name="p1372916492196"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="p17361249171913"><a name="p17361249171913"></a><a name="p17361249171913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="p1737154910194"><a name="p1737154910194"></a><a name="p1737154910194"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="p1473815496194"><a name="p1473815496194"></a><a name="p1473815496194"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row6356211905"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1231162514015"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1231162514015"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1231162514015"></a><span id="ph10734183131515"><a name="ph10734183131515"></a><a name="ph10734183131515"></a>Note: <strong id="b97338341516"><a name="b97338341516"></a><a name="b97338341516"></a>Y</strong> indicates that the function is supported, <strong id="b1773320312157"><a name="b1773320312157"></a><a name="b1773320312157"></a>N</strong> indicates that the function is not supported, and <strong id="b177346318158"><a name="b177346318158"></a><a name="b177346318158"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001206307230_en-us_topic_0000001178373128_en-us_topic_0000001169397257_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
int ub_slot = 0;
ret = dcmiv2_get_device_ub_slot_id(dev_id, &ub_slot);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
