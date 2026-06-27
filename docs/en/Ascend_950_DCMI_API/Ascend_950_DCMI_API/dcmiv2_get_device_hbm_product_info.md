# dcmiv2\_get\_device\_hbm\_product\_info<a name="EN-US_TOPIC_0000002314045114"></a>

## Prototype<a name="section196251231145019"></a>

**int dcmiv2\_get\_device\_hbm\_product\_info\(int dev\_id, struct dcmi\_hbm\_product\_info \*hbm\_product\_info\)**

## Description<a name="section116271631195017"></a>

Queries the on-chip memory manufacturer information of a specified NPU.

## Parameter Description<a name="section11627103114506"></a>

<a name="table196551731155016"></a>
<table><thead align="left"><tr id="row6708031165017"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p17708123120507"><a name="p17708123120507"></a><a name="p17708123120507"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p13708143185017"><a name="p13708143185017"></a><a name="p13708143185017"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p67081031185017"><a name="p67081031185017"></a><a name="p67081031185017"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p3708131145014"><a name="p3708131145014"></a><a name="p3708131145014"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="row89976111742"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p20169541042"><a name="p20169541042"></a><a name="p20169541042"></a>hbm_product_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p216924749"><a name="p216924749"></a><a name="p216924749"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1016918418411"><a name="p1016918418411"></a><a name="p1016918418411"></a>struct dcmi_hbm_product_info<strong id="b1793792141419"><a name="b1793792141419"></a><a name="b1793792141419"></a> </strong>*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1916974245"><a name="p1916974245"></a><a name="p1916974245"></a>struct dcmi_hbm_product_info {</p>
<p id="p1216944241"><a name="p1216944241"></a><a name="p1216944241"></a>unsigned short manufacturer_id; // Type of the on-chip memory manufacturer</p>
<p id="p5169447418"><a name="p5169447418"></a><a name="p5169447418"></a>unsigned char reserve[62];</p>
<p id="p10169641949"><a name="p10169641949"></a><a name="p10169641949"></a>};</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="section3642631135017"></a>

<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
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

## Restrictions<a name="section364683165017"></a>

**Table  1** Support in different deployment scenarios

<a name="table116394134134"></a>
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

## Example<a name="section13653173113509"></a>

```c
...
int ret = 0;
int dev_id=0;
struct dcmi_hbm_product_info hbm_product_info = {0};
ret = dcmiv2_get_device_hbm_product_info (dev_id, &hbm_product_info);
if (ret != 0){
    // TODO: Record logs.
     return ret;
 }
...
```
