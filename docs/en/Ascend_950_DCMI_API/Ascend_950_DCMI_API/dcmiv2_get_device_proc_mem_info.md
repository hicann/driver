# dcmiv2\_get\_device\_proc\_mem\_info<a name="EN-US_TOPIC_0000002347923949"></a>

## Prototype<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412077"></a>

**int dcmiv2\_get\_device\_proc\_mem\_info \(int dev\_id, struct dcmi\_proc\_mem\_info \*proc\_info, int \*proc\_num\)**

## Description<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412078"></a>

Obtains the service processes of the SVM module on a device and the memory occupied by the processes.

## Parameter Description<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412079"></a>

<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_row7580267"><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p10021890"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p10021890"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p6466753"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p6466753"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.06%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p54045009"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p54045009"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="54.37%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p15569626"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p15569626"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_row15462171542913"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.06%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_row029010598584"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1845492116012"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1845492116012"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1845492116012"></a>proc_info</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p54545211409"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p54545211409"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p54545211409"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.06%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p17454182115010"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p17454182115010"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p17454182115010"></a>struct dcmi_proc_mem_info *</p>
</td>
<td class="cellrowborder" valign="top" width="54.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p818854110484"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p818854110484"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p818854110484"></a>The structure contains the process ID and the memory (in bytes) occupied by the process, representing the process ID on the host and the combined total of memory consumed by the device OS and the memory allocated to services, respectively.</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p341624411567"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p341624411567"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p341624411567"></a>The structure is defined as follows:</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p097725484813"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p097725484813"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p097725484813"></a>struct dcmi_proc_mem_info {</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1797718546489"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1797718546489"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1797718546489"></a>int proc_id; // Process ID</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1297717548486"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1297717548486"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1297717548486"></a>unsigned long proc_mem_usage; // Memory usage</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p6977105434812"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p6977105434812"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p6977105434812"></a>};</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_row2856427486"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p485612104817"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p485612104817"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p485612104817"></a>proc_num</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p138569274811"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p138569274811"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p138569274811"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.06%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1685652144810"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1685652144810"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p1685652144810"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="54.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p18856102164811"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p18856102164811"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p18856102164811"></a>Number of processes, up to 32. The value <strong id="b148821025145015"><a name="b148821025145015"></a><a name="b148821025145015"></a>0</strong> indicates that no service is running.</p>
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

## Restrictions<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412082"></a>

For host machines and privileged containers, this command queries all processes running in a host machine, in an unprivileged container, and in a privileged container. For unprivileged containers, this command queries only all processes running in an unprivileged container.

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

## Example<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412083"></a>

```c
…
#define MAX_PROC_NUM_IN_DEVICE 32
int ret;
int dev_id = 0;
struct dcmi_proc_mem_info proc_info[MAX_PROC_NUM_IN_DEVICE] = {0};
int proc_num = 0;
ret = dcmiv2_get_device_proc_mem_info(dev_id, proc_info, &proc_num);
if (ret != DCMI_OK) {
    printf("dcmiv2_get_device_proc_mem_info failed. err is %d\n", ret);
}
return ret;
...
```
