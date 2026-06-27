# dcmi\_set\_spod\_node\_status<a name="EN-US_TOPIC_0000002546990395"></a>

**Prototype<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412077"></a>**

**int dcmi\_set\_spod\_node\_status\(int card\_id, int device\_id, unsigned int sdid, unsigned int status\)**

**Description<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412078"></a>**

Configures the status of an NPU identified by SDID. The NPU status determines how the shared resources are released.

**Parameter Description<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412079"></a>**

<a name="table67596436345"></a>
<table><thead align="left"><tr id="row1877312435347"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p777384363416"><a name="p777384363416"></a><a name="p777384363416"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p14773184373410"><a name="p14773184373410"></a><a name="p14773184373410"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p167731443173413"><a name="p167731443173413"></a><a name="p167731443173413"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p1777316436348"><a name="p1777316436348"></a><a name="p1777316436348"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row37734437347"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1777324310342"><a name="p1777324310342"></a><a name="p1777324310342"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p27737433344"><a name="p27737433344"></a><a name="p27737433344"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p877312437349"><a name="p877312437349"></a><a name="p877312437349"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1377334311340"><a name="p1377334311340"></a><a name="p1377334311340"></a>Device ID. The supported IDs can be obtained by calling <strong id="b141802146833117"><a name="b141802146833117"></a><a name="b141802146833117"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row2773184363417"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p157731243203415"><a name="p157731243203415"></a><a name="p157731243203415"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1777314316344"><a name="p1777314316344"></a><a name="p1777314316344"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p377324312344"><a name="p377324312344"></a><a name="p377324312344"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p37731543123417"><a name="p37731543123417"></a><a name="p37731543123417"></a>Chip ID, which can be obtained by calling <strong id="b14688094333135"><a name="b14688094333135"></a><a name="b14688094333135"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p57734436348"><a name="p57734436348"></a><a name="p57734436348"></a>NPU: [0, <strong id="b16324800881635"><a name="b16324800881635"></a><a name="b16324800881635"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row77733439346"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1877314431344"><a name="p1877314431344"></a><a name="p1877314431344"></a>sdid</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1777311432341"><a name="p1777311432341"></a><a name="p1777311432341"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1477354313348"><a name="p1477354313348"></a><a name="p1477354313348"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p167734438349"><a name="p167734438349"></a><a name="p167734438349"></a>Indicates the unique ID of each NPU in the SuperPoD system. The SDID of a target NPU should be provided.</p>
</td>
</tr>
<tr id="row1777317434347"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p57732434344"><a name="p57732434344"></a><a name="p57732434344"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p17773943163411"><a name="p17773943163411"></a><a name="p17773943163411"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p7773243113411"><a name="p7773243113411"></a><a name="p7773243113411"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p275162733218"><a name="p275162733218"></a><a name="p275162733218"></a>Indicates the status information about the NPU identified by SDID. The default value is <strong id="b9320132616579"><a name="b9320132616579"></a><a name="b9320132616579"></a>0</strong>.</p>
<a name="ul1518995073513"></a><a name="ul1518995073513"></a><ul id="ul1518995073513"><li>The value <strong id="b104343255717"><a name="b104343255717"></a><a name="b104343255717"></a>1</strong> indicates that the target NPU is abnormal. In this case, the local NPU forcibly releases the resources shared with the target NPU.</li><li>The value <strong id="b535714575714"><a name="b535714575714"></a><a name="b535714575714"></a>0</strong> indicates that the target NPU is normal. In this case, the local NPU negotiates the release of resources shared with the target NPU.</li></ul>
<div class="note" id="note109341427362"><a name="note109341427362"></a><a name="note109341427362"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p14934824362"><a name="p14934824362"></a><a name="p14934824362"></a>When the target NPU recovers from an abnormal state, call this API to change the status of this NPU to <strong id="b126091940151410"><a name="b126091940151410"></a><a name="b126091940151410"></a>0</strong> (normal).</p>
</div></div>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b203960747481635"><a name="b203960747481635"></a><a name="b203960747481635"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="section18439219511"></a>**

- SDID validity description: SDID is a 32-bit value divided into four ID fields, where bits 22 to 31 represent the  **server\_index**  \(range 0 to 47\), bits 18 to 21 represent the chip ID \(range 0 to 7\), bits 16 to 17 represent the die ID \(range 0 to 2\), and bits 0 to 15 represent the device ID, calculated as chip ID × 2 + die ID.
- This API can be used on physical machines and in privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412083"></a>**

```c
...
int card_id = 0;
int device_id = 0;
unsigned int sdid = 0;
unsigned int status = 0;  
int ret = dcmi_set_spod_node_status(card_id, device_id, sdid, status); 
if (ret != 0) {
    // todo: Record logs.
     return ret; 
} 
...
```
