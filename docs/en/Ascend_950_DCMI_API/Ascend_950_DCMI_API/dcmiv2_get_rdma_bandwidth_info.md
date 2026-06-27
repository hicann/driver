# dcmiv2\_get\_rdma\_bandwidth\_info<a name="EN-US_TOPIC_0000002348043769"></a>

## Prototype<a name="section196251231145019"></a>

**int dcmiv2\_get\_rdma\_bandwidth\_info\(int dev\_id, int port\_id,** **unsigned int prof\_time, struct dcmi\_network\_rdma\_bandwidth\_info \*network\_rdma\_bandwidth\_info\)**

## Description<a name="section116271631195017"></a>

Queries the RDMA bandwidth of an NPU network port in a specified profiling time.

## Parameter Description<a name="section11627103114506"></a>

<a name="table196551731155016"></a>
<table><thead align="left"><tr id="row6708031165017"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p17708123120507"><a name="p17708123120507"></a><a name="p17708123120507"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p13708143185017"><a name="p13708143185017"></a><a name="p13708143185017"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="18.81%" id="mcps1.1.5.1.3"><p id="p67081031185017"><a name="p67081031185017"></a><a name="p67081031185017"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="47.19%" id="mcps1.1.5.1.4"><p id="p3708131145014"><a name="p3708131145014"></a><a name="p3708131145014"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="47.19%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="row89976111742"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1824103514419"><a name="p1824103514419"></a><a name="p1824103514419"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p424143514417"><a name="p424143514417"></a><a name="p424143514417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.3 "><p id="p1424112357410"><a name="p1424112357410"></a><a name="p1424112357410"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="47.19%" headers="mcps1.1.5.1.4 "><p id="p1224183544119"><a name="p1224183544119"></a><a name="p1224183544119"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b1197909082486"><a name="b1197909082486"></a><a name="b1197909082486"></a>0</strong>.</p>
</td>
</tr>
<tr id="row2498185195919"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p145961171904"><a name="p145961171904"></a><a name="p145961171904"></a>prof_time</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p55965171505"><a name="p55965171505"></a><a name="p55965171505"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.3 "><p id="p145963175011"><a name="p145963175011"></a><a name="p145963175011"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="47.19%" headers="mcps1.1.5.1.4 "><p id="p11596317609"><a name="p11596317609"></a><a name="p11596317609"></a>Profiling time. Value range: 100 ms to 10000 ms.</p>
</td>
</tr>
<tr id="row15998411242"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p6597191716014"><a name="p6597191716014"></a><a name="p6597191716014"></a>network_rdma_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p10597717308"><a name="p10597717308"></a><a name="p10597717308"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="18.81%" headers="mcps1.1.5.1.3 "><p id="p4597101712011"><a name="p4597101712011"></a><a name="p4597101712011"></a>struct dcmi_network_rdma_bandwidth_info <strong id="b13436228171317"><a name="b13436228171317"></a><a name="b13436228171317"></a>*</strong></p>
</td>
<td class="cellrowborder" valign="top" width="47.19%" headers="mcps1.1.5.1.4 "><p id="p62841921710"><a name="p62841921710"></a><a name="p62841921710"></a>RDMA bandwidth information of the network port, in MB/s.</p>
<pre class="codeblock" id="codeblock19576202519714"><a name="codeblock19576202519714"></a><a name="codeblock19576202519714"></a>struct dcmi_network_rdma_bandwidth_info {
unsigned int tx_bandwidth; // TX bandwidth
unsigned int rx_bandwidth; // RX bandwidth
};</pre>
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

<a name="table095520915213"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row26461043103219"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p06463434324"><a name="en-us_topic_0000002347924121_p06463434324"></a><a name="en-us_topic_0000002347924121_p06463434324"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p15646043123214"><a name="en-us_topic_0000002347924121_p15646043123214"></a><a name="en-us_topic_0000002347924121_p15646043123214"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1464614435324"><a name="en-us_topic_0000002347924121_p1464614435324"></a><a name="en-us_topic_0000002347924121_p1464614435324"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p14646174353210"><a name="en-us_topic_0000002347924121_p14646174353210"></a><a name="en-us_topic_0000002347924121_p14646174353210"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p3647104343214"><a name="en-us_topic_0000002347924121_p3647104343214"></a><a name="en-us_topic_0000002347924121_p3647104343214"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16472433324"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p16471543143217"><a name="en-us_topic_0000002347924121_p16471543143217"></a><a name="en-us_topic_0000002347924121_p16471543143217"></a><strong id="en-us_topic_0000002347924121_b1919763744"><a name="en-us_topic_0000002347924121_b1919763744"></a><a name="en-us_topic_0000002347924121_b1919763744"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p664754323210"><a name="en-us_topic_0000002347924121_p664754323210"></a><a name="en-us_topic_0000002347924121_p664754323210"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b892351261"><a name="en-us_topic_0000002347924121_b892351261"></a><a name="en-us_topic_0000002347924121_b892351261"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p66471543173215"><a name="en-us_topic_0000002347924121_p66471543173215"></a><a name="en-us_topic_0000002347924121_p66471543173215"></a><strong id="en-us_topic_0000002347924121_b125134011"><a name="en-us_topic_0000002347924121_b125134011"></a><a name="en-us_topic_0000002347924121_b125134011"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p4647943123210"><a name="en-us_topic_0000002347924121_p4647943123210"></a><a name="en-us_topic_0000002347924121_p4647943123210"></a><strong id="en-us_topic_0000002347924121_b922706339"><a name="en-us_topic_0000002347924121_b922706339"></a><a name="en-us_topic_0000002347924121_b922706339"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p176472043163218"><a name="en-us_topic_0000002347924121_p176472043163218"></a><a name="en-us_topic_0000002347924121_p176472043163218"></a><strong id="en-us_topic_0000002347924121_b202429450"><a name="en-us_topic_0000002347924121_b202429450"></a><a name="en-us_topic_0000002347924121_b202429450"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row964714313220"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p664734316322"><a name="en-us_topic_0000002347924121_p664734316322"></a><a name="en-us_topic_0000002347924121_p664734316322"></a><span id="en-us_topic_0000002347924121_ph9647194317328"><a name="en-us_topic_0000002347924121_ph9647194317328"></a><a name="en-us_topic_0000002347924121_ph9647194317328"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13924182025119"><a name="en-us_topic_0000002347924121_p13924182025119"></a><a name="en-us_topic_0000002347924121_p13924182025119"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p109262206516"><a name="en-us_topic_0000002347924121_p109262206516"></a><a name="en-us_topic_0000002347924121_p109262206516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p8926172095110"><a name="en-us_topic_0000002347924121_p8926172095110"></a><a name="en-us_topic_0000002347924121_p8926172095110"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row176481543163219"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p26481431322"><a name="en-us_topic_0000002347924121_p26481431322"></a><a name="en-us_topic_0000002347924121_p26481431322"></a><span id="en-us_topic_0000002347924121_ph9648104363220"><a name="en-us_topic_0000002347924121_ph9648104363220"></a><a name="en-us_topic_0000002347924121_ph9648104363220"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13653173113509"></a>

```c
...
int ret = 0;
int dev_id=0;
int port_id=0;
unsigned int prof_time = 1000;
struct dcmi_network_rdma_bandwidth_info bandwidth_info = {0};
ret = dcmiv2_get_rdma_bandwidth_info (dev_id, port_id, prof_time, &bandwidth_info);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
