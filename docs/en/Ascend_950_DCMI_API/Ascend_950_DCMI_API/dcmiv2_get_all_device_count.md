# dcmiv2\_get\_all\_device\_count<a name="EN-US_TOPIC_0000002347923945"></a>

## Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>

**int dcmiv2\_get\_all\_device\_count\(int \*all\_device\_count\)**

## Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>

- PCIe scenarios: Queries the number of NPU devices that are successfully connected to the PCIe of the host after the host is started.
- UB interconnect scenarios: Queries the number of NPU devices in the resource ratio information on the host after the host is started.

## Parameter Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412079"></a>

<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.97%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p14881939993"><a name="p14881939993"></a><a name="p14881939993"></a>all_device_count</p>
</td>
<td class="cellrowborder" valign="top" width="16.97%" headers="mcps1.1.5.1.2 "><p id="p1488203916913"><a name="p1488203916913"></a><a name="p1488203916913"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.3 "><p id="p18833919917"><a name="p18833919917"></a><a name="p18833919917"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p118820391193"><a name="p118820391193"></a><a name="p118820391193"></a>Number of queried devices.</p>
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

## Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>

The installation and upgrade of the NPU firmware and NPU driver must take effect before this API is called.

**Table  1** Support in different deployment scenarios

<a name="table18921924124018"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row85055222256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1850512212252"><a name="en-us_topic_0000002347924121_p1850512212252"></a><a name="en-us_topic_0000002347924121_p1850512212252"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p1850522212250"><a name="en-us_topic_0000002347924121_p1850522212250"></a><a name="en-us_topic_0000002347924121_p1850522212250"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p195055221252"><a name="en-us_topic_0000002347924121_p195055221252"></a><a name="en-us_topic_0000002347924121_p195055221252"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1505222162517"><a name="en-us_topic_0000002347924121_p1505222162517"></a><a name="en-us_topic_0000002347924121_p1505222162517"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p2050552211251"><a name="en-us_topic_0000002347924121_p2050552211251"></a><a name="en-us_topic_0000002347924121_p2050552211251"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row6505162292517"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p3505202214258"><a name="en-us_topic_0000002347924121_p3505202214258"></a><a name="en-us_topic_0000002347924121_p3505202214258"></a><strong id="en-us_topic_0000002347924121_b1713206182"><a name="en-us_topic_0000002347924121_b1713206182"></a><a name="en-us_topic_0000002347924121_b1713206182"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p2505152282515"><a name="en-us_topic_0000002347924121_p2505152282515"></a><a name="en-us_topic_0000002347924121_p2505152282515"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b199721174"><a name="en-us_topic_0000002347924121_b199721174"></a><a name="en-us_topic_0000002347924121_b199721174"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p75057226257"><a name="en-us_topic_0000002347924121_p75057226257"></a><a name="en-us_topic_0000002347924121_p75057226257"></a><strong id="en-us_topic_0000002347924121_b1796997753"><a name="en-us_topic_0000002347924121_b1796997753"></a><a name="en-us_topic_0000002347924121_b1796997753"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p165051822132516"><a name="en-us_topic_0000002347924121_p165051822132516"></a><a name="en-us_topic_0000002347924121_p165051822132516"></a><strong id="en-us_topic_0000002347924121_b780240272"><a name="en-us_topic_0000002347924121_b780240272"></a><a name="en-us_topic_0000002347924121_b780240272"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p850511222259"><a name="en-us_topic_0000002347924121_p850511222259"></a><a name="en-us_topic_0000002347924121_p850511222259"></a><strong id="en-us_topic_0000002347924121_b618459806"><a name="en-us_topic_0000002347924121_b618459806"></a><a name="en-us_topic_0000002347924121_b618459806"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row1950542211255"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p15505202212513"><a name="en-us_topic_0000002347924121_p15505202212513"></a><a name="en-us_topic_0000002347924121_p15505202212513"></a><span id="en-us_topic_0000002347924121_ph6505132214255"><a name="en-us_topic_0000002347924121_ph6505132214255"></a><a name="en-us_topic_0000002347924121_ph6505132214255"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p1850552216254"><a name="en-us_topic_0000002347924121_p1850552216254"></a><a name="en-us_topic_0000002347924121_p1850552216254"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p1350512262513"><a name="en-us_topic_0000002347924121_p1350512262513"></a><a name="en-us_topic_0000002347924121_p1350512262513"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p4963142615255"><a name="en-us_topic_0000002347924121_p4963142615255"></a><a name="en-us_topic_0000002347924121_p4963142615255"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p350522232515"><a name="en-us_topic_0000002347924121_p350522232515"></a><a name="en-us_topic_0000002347924121_p350522232515"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p65051922102516"><a name="en-us_topic_0000002347924121_p65051922102516"></a><a name="en-us_topic_0000002347924121_p65051922102516"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row155061022192517"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1750616221258"><a name="en-us_topic_0000002347924121_p1750616221258"></a><a name="en-us_topic_0000002347924121_p1750616221258"></a><span id="en-us_topic_0000002347924121_ph1444731735"><a name="en-us_topic_0000002347924121_ph1444731735"></a><a name="en-us_topic_0000002347924121_ph1444731735"></a>Note: <strong id="en-us_topic_0000002347924121_b1930294408"><a name="en-us_topic_0000002347924121_b1930294408"></a><a name="en-us_topic_0000002347924121_b1930294408"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b871279599"><a name="en-us_topic_0000002347924121_b871279599"></a><a name="en-us_topic_0000002347924121_b871279599"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b716394356"><a name="en-us_topic_0000002347924121_b716394356"></a><a name="en-us_topic_0000002347924121_b716394356"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>

```c
...
int ret = 0;
int all_device_count;
ret = dcmiv2_get_all_device_count(&all_device_count);
if(ret != 0) {
    // TODO
    return ret;
}
...
```
