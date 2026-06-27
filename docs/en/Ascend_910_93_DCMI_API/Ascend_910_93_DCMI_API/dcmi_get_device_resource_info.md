# dcmi\_get\_device\_resource\_info<a name="EN-US_TOPIC_0000002546990467"></a>

**Prototype<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412077"></a>**

**int dcmi\_get\_device\_resource\_info \(int card\_id, int device\_id, struct dcmi\_proc\_mem\_info \*proc\_info, int \*proc\_num\)**

**Description<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412078"></a>**

Obtains the service processes of the SVM module on a device and the memory occupied by the processes.

**Parameter Description<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412079"></a>**

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
<tbody><tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_row10560021192510"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p36741947142813"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p36741947142813"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p96741747122818"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p96741747122818"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.06%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p46747472287"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p46747472287"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1467413474281"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1467413474281"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b877821110217"><a name="b877821110217"></a><a name="b877821110217"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_row15462171542913"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_p445315176517"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p1926232982914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.06%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_p826217292293"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.37%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b93676108733021"><a name="b93676108733021"></a><a name="b93676108733021"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="en-us_topic_0000001206307222_en-us_topic_0000001189111912_b1789674145012"><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_b1789674145012"></a><a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_b1789674145012"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b80481915872239"><a name="b80481915872239"></a><a name="b80481915872239"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412082"></a>**

For host machines and privileged containers, this command queries all processes running in host machines, common containers, and privileged containers. For common containers, this command queries all processes only running in common containers.

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p67828402447"><a name="en-us_topic_0000002515350556_p67828402447"></a><a name="en-us_topic_0000002515350556_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p16315103817414"><a name="en-us_topic_0000002515350556_p16315103817414"></a><a name="en-us_topic_0000002515350556_p16315103817414"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row125012052104311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1378374019445"><a name="en-us_topic_0000002515350556_p1378374019445"></a><a name="en-us_topic_0000002515350556_p1378374019445"></a><span id="en-us_topic_0000002515350556_text262011415447"><a name="en-us_topic_0000002515350556_text262011415447"></a><a name="en-us_topic_0000002515350556_text262011415447"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p3696134919457"><a name="en-us_topic_0000002515350556_p3696134919457"></a><a name="en-us_topic_0000002515350556_p3696134919457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1069610491457"><a name="en-us_topic_0000002515350556_p1069610491457"></a><a name="en-us_topic_0000002515350556_p1069610491457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14744104011463"><a name="en-us_topic_0000002515350556_p14744104011463"></a><a name="en-us_topic_0000002515350556_p14744104011463"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p137832403444"><a name="en-us_topic_0000002515350556_p137832403444"></a><a name="en-us_topic_0000002515350556_p137832403444"></a><span id="en-us_topic_0000002515350556_text1480012462513"><a name="en-us_topic_0000002515350556_text1480012462513"></a><a name="en-us_topic_0000002515350556_text1480012462513"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17744194024612"><a name="en-us_topic_0000002515350556_p17744194024612"></a><a name="en-us_topic_0000002515350556_p17744194024612"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row195142220363"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p19150201815714"><a name="en-us_topic_0000002515350556_p19150201815714"></a><a name="en-us_topic_0000002515350556_p19150201815714"></a><span id="en-us_topic_0000002515350556_text1615010187716"><a name="en-us_topic_0000002515350556_text1615010187716"></a><a name="en-us_topic_0000002515350556_text1615010187716"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1831093744715"><a name="en-us_topic_0000002515350556_p1831093744715"></a><a name="en-us_topic_0000002515350556_p1831093744715"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9310337164720"><a name="en-us_topic_0000002515350556_p9310337164720"></a><a name="en-us_topic_0000002515350556_p9310337164720"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p10310113714473"><a name="en-us_topic_0000002515350556_p10310113714473"></a><a name="en-us_topic_0000002515350556_p10310113714473"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1024616413271"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1824612411277"><a name="en-us_topic_0000002515350556_p1824612411277"></a><a name="en-us_topic_0000002515350556_p1824612411277"></a><span id="en-us_topic_0000002515350556_text712252182813"><a name="en-us_topic_0000002515350556_text712252182813"></a><a name="en-us_topic_0000002515350556_text712252182813"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p436771642813"><a name="en-us_topic_0000002515350556_p436771642813"></a><a name="en-us_topic_0000002515350556_p436771642813"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p436710164281"><a name="en-us_topic_0000002515350556_p436710164281"></a><a name="en-us_topic_0000002515350556_p436710164281"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p193671116172816"><a name="en-us_topic_0000002515350556_p193671116172816"></a><a name="en-us_topic_0000002515350556_p193671116172816"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row11011140184711"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1010254064715"><a name="en-us_topic_0000002515350556_p1010254064715"></a><a name="en-us_topic_0000002515350556_p1010254064715"></a><span id="en-us_topic_0000002515350556_text15548246175319"><a name="en-us_topic_0000002515350556_text15548246175319"></a><a name="en-us_topic_0000002515350556_text15548246175319"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p0636155115534"><a name="en-us_topic_0000002515350556_p0636155115534"></a><a name="en-us_topic_0000002515350556_p0636155115534"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p16636951125317"><a name="en-us_topic_0000002515350556_p16636951125317"></a><a name="en-us_topic_0000002515350556_p16636951125317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p163685125315"><a name="en-us_topic_0000002515350556_p163685125315"></a><a name="en-us_topic_0000002515350556_p163685125315"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row7398193211715"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12881158154715"><a name="en-us_topic_0000002515350556_p12881158154715"></a><a name="en-us_topic_0000002515350556_p12881158154715"></a>Note: <strong id="en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206307222_en-us_topic_0000001189111912_en-us_topic_0000001167913765_toc533412083"></a>**

```c
... 
#define MAX_PROC_NUM_IN_DEVICE 32
int ret;
int card_id = 0;
int chip_id = 0;
struct dcmi_proc_mem_info proc_info[MAX_PROC_NUM_IN_DEVICE] = {0};
int proc_num = 0;
char proc_name[16] = {0};
int name_len = 0;
ret = dcmi_get_device_resource_info(card_id, chip_id, proc_info, &proc_num);
if (ret != DCMI_OK) {
    printf("dcmi_get_device_resource_info failed. err is %d\n", ret);
}
return ret; 
...
```
