# dcmiv2\_get\_pcie\_link\_bandwidth\_info<a name="EN-US_TOPIC_0000002314204926"></a>

## Prototype<a name="section196251231145019"></a>

**int dcmiv2\_get\_pcie\_link\_bandwidth\_info \(int dev\_id, struct dcmi\_pcie\_link\_bandwidth\_info \*pcie\_link\_bandwidth\_info\)**

## Description<a name="section116271631195017"></a>

Queries the PCIe bandwidth between the NPU and host OS in a specified profiling time.

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
<tr id="row1170919312507"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p2709331125015"><a name="p2709331125015"></a><a name="p2709331125015"></a>pcie_link_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p5709153165015"><a name="p5709153165015"></a><a name="p5709153165015"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p270923119508"><a name="p270923119508"></a><a name="p270923119508"></a>struct dcmi_pcie_link_bandwidth_info<strong id="b119504553355"><a name="b119504553355"></a><a name="b119504553355"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p147094314502"><a name="p147094314502"></a><a name="p147094314502"></a>struct dcmi_pcie_link_bandwidth_info {</p>
<p id="p15709103111504"><a name="p15709103111504"></a><a name="p15709103111504"></a>int profiling_time; // Control the profiling time, which is input.</p>
<p id="p8709731105013"><a name="p8709731105013"></a><a name="p8709731105013"></a>unsigned int tx_p_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to write data to the remote end, which is output</p>
<p id="p5709431135014"><a name="p5709431135014"></a><a name="p5709431135014"></a>unsigned int tx_np_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to read data from the remote end, which is output</p>
<p id="p770913120509"><a name="p770913120509"></a><a name="p770913120509"></a>unsigned int tx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; // CPL bandwidth for the device to respond to the remote read operation, which is output</p>
<p id="p67096319500"><a name="p67096319500"></a><a name="p67096319500"></a>unsigned int tx_np_lantency[AGENTDRV_PROF_DATA_NUM];</p>
<p id="p18709631165013"><a name="p18709631165013"></a><a name="p18709631165013"></a>// Latency (ns) for the device to read data from the remote end, which is output</p>
<p id="p19709173185010"><a name="p19709173185010"></a><a name="p19709173185010"></a>unsigned int rx_p_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to receive remote write requests, which is output</p>
<p id="p15709631135012"><a name="p15709631135012"></a><a name="p15709631135012"></a>unsigned int rx_np_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to receive remote read requests, which is output</p>
<p id="p27091312507"><a name="p27091312507"></a><a name="p27091312507"></a>unsigned int rx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to read the CPL response from the remote end, which is output</p>
<p id="p5709173115012"><a name="p5709173115012"></a><a name="p5709173115012"></a>};</p>
<p id="p157098315509"><a name="p157098315509"></a><a name="p157098315509"></a>Value range of <strong id="b137218401452"><a name="b137218401452"></a><a name="b137218401452"></a>profiling_time</strong>: 0 ms to 2000 ms</p>
<p id="p207091631185018"><a name="p207091631185018"></a><a name="p207091631185018"></a>Bandwidth unit: MB/ms</p>
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

## Restrictions<a name="section364683165017"></a>

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row56475259915"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1664718251196"><a name="en-us_topic_0000002347924121_p1664718251196"></a><a name="en-us_topic_0000002347924121_p1664718251196"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p106471725998"><a name="en-us_topic_0000002347924121_p106471725998"></a><a name="en-us_topic_0000002347924121_p106471725998"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p564712252099"><a name="en-us_topic_0000002347924121_p564712252099"></a><a name="en-us_topic_0000002347924121_p564712252099"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p46471925390"><a name="en-us_topic_0000002347924121_p46471925390"></a><a name="en-us_topic_0000002347924121_p46471925390"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p1664711251390"><a name="en-us_topic_0000002347924121_p1664711251390"></a><a name="en-us_topic_0000002347924121_p1664711251390"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row26471525697"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p964712258911"><a name="en-us_topic_0000002347924121_p964712258911"></a><a name="en-us_topic_0000002347924121_p964712258911"></a><strong id="en-us_topic_0000002347924121_b1885142358"><a name="en-us_topic_0000002347924121_b1885142358"></a><a name="en-us_topic_0000002347924121_b1885142358"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p11647825895"><a name="en-us_topic_0000002347924121_p11647825895"></a><a name="en-us_topic_0000002347924121_p11647825895"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b829026371"><a name="en-us_topic_0000002347924121_b829026371"></a><a name="en-us_topic_0000002347924121_b829026371"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p18647132512913"><a name="en-us_topic_0000002347924121_p18647132512913"></a><a name="en-us_topic_0000002347924121_p18647132512913"></a><strong id="en-us_topic_0000002347924121_b1159902888"><a name="en-us_topic_0000002347924121_b1159902888"></a><a name="en-us_topic_0000002347924121_b1159902888"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p106471825295"><a name="en-us_topic_0000002347924121_p106471825295"></a><a name="en-us_topic_0000002347924121_p106471825295"></a><strong id="en-us_topic_0000002347924121_b1329568613"><a name="en-us_topic_0000002347924121_b1329568613"></a><a name="en-us_topic_0000002347924121_b1329568613"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p9647132512918"><a name="en-us_topic_0000002347924121_p9647132512918"></a><a name="en-us_topic_0000002347924121_p9647132512918"></a><strong id="en-us_topic_0000002347924121_b1988308924"><a name="en-us_topic_0000002347924121_b1988308924"></a><a name="en-us_topic_0000002347924121_b1988308924"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row1464717256910"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p56479251293"><a name="en-us_topic_0000002347924121_p56479251293"></a><a name="en-us_topic_0000002347924121_p56479251293"></a><span id="en-us_topic_0000002347924121_ph564717251191"><a name="en-us_topic_0000002347924121_ph564717251191"></a><a name="en-us_topic_0000002347924121_ph564717251191"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p819818203526"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p819818203526"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p819818203526"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p399810267455"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p399810267455"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p399810267455"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p199994269451"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p199994269451"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p199994269451"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p50172714514"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p50172714514"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p50172714514"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p10284101114351"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p10284101114351"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000002347924121_p10284101114351"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row136484256917"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p2064815251198"><a name="en-us_topic_0000002347924121_p2064815251198"></a><a name="en-us_topic_0000002347924121_p2064815251198"></a><span id="en-us_topic_0000002347924121_ph1764842517912"><a name="en-us_topic_0000002347924121_ph1764842517912"></a><a name="en-us_topic_0000002347924121_ph1764842517912"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13653173113509"></a>

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_pcie_link_bandwidth_info bandwidth_info = {0};
bandwidth_info.profiling_time = 1000;
ret = dcmiv2_get_pcie_link_bandwidth_info(dev_id, &bandwidth_info);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
