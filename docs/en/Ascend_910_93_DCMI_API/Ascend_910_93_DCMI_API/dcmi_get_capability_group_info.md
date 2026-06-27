# dcmi\_get\_capability\_group\_info<a name="EN-US_TOPIC_0000002546910395"></a>

**Prototype<a name="section14126237219"></a>**

**int dcmi\_get\_capability\_group\_info\(int card\_id, int device\_id, int ts\_id, int group\_id, struct dcmi\_capability\_group\_info \*group\_info, int group\_count\)**

**Description<a name="section1812132352116"></a>**

Obtains the configuration information of Ascend virtual instances.

**Parameter Description<a name="section5121523152116"></a>**

<a name="table936323172112"></a>
<table><thead align="left"><tr id="row9101923162117"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p81014235218"><a name="p81014235218"></a><a name="p81014235218"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.14%" id="mcps1.1.5.1.2"><p id="p16101192311218"><a name="p16101192311218"></a><a name="p16101192311218"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.18%" id="mcps1.1.5.1.3"><p id="p810192315214"><a name="p810192315214"></a><a name="p810192315214"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p11011423182111"><a name="p11011423182111"></a><a name="p11011423182111"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row181021230215"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p710211238213"><a name="p710211238213"></a><a name="p710211238213"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p181021523202116"><a name="p181021523202116"></a><a name="p181021523202116"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p10102182312211"><a name="p10102182312211"></a><a name="p10102182312211"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p16102823142117"><a name="p16102823142117"></a><a name="p16102823142117"></a>Device ID. The supported IDs can be obtained by calling <strong id="b69892155533114"><a name="b69892155533114"></a><a name="b69892155533114"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row121026234211"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p15102132316213"><a name="p15102132316213"></a><a name="p15102132316213"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1110202310211"><a name="p1110202310211"></a><a name="p1110202310211"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p13102102313214"><a name="p13102102313214"></a><a name="p13102102313214"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p15102152315216"><a name="p15102152315216"></a><a name="p15102152315216"></a>Chip ID, which can be obtained by calling <strong id="b57060650881513"><a name="b57060650881513"></a><a name="b57060650881513"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p11102112342111"><a name="p11102112342111"></a><a name="p11102112342111"></a>NPU: [0, <strong id="b6631499568711"><a name="b6631499568711"></a><a name="b6631499568711"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row410272319218"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p18102202317214"><a name="p18102202317214"></a><a name="p18102202317214"></a>ts_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p121021423192117"><a name="p121021423192117"></a><a name="p121021423192117"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p1710222319213"><a name="p1710222319213"></a><a name="p1710222319213"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1610210232215"><a name="p1610210232215"></a><a name="p1610210232215"></a>Computing power type ID:</p>
<p id="p1102162302112"><a name="p1102162302112"></a><a name="p1102162302112"></a>typedef enum {</p>
<p id="p1210242310210"><a name="p1210242310210"></a><a name="p1210242310210"></a>DCMI_TS_AICORE = 0,</p>
<p id="p121026236213"><a name="p121026236213"></a><a name="p121026236213"></a>DCMI_TS_AIVECTOR,</p>
<p id="p01026238215"><a name="p01026238215"></a><a name="p01026238215"></a>} DCMI_TS_ID;</p>
<p id="p1210332311216"><a name="p1210332311216"></a><a name="p1210332311216"></a>Currently, <strong id="b186397298617"><a name="b186397298617"></a><a name="b186397298617"></a>DCMI_TS_AIVECTOR</strong> is not supported.</p>
</td>
</tr>
<tr id="row610319235213"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p11103102392114"><a name="p11103102392114"></a><a name="p11103102392114"></a>group_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1103132310216"><a name="p1103132310216"></a><a name="p1103132310216"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p5103182318215"><a name="p5103182318215"></a><a name="p5103182318215"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p3103923102118"><a name="p3103923102118"></a><a name="p3103923102118"></a>Computing power group ID. Value range: 0–3 or <strong id="b1683217346232"><a name="b1683217346232"></a><a name="b1683217346232"></a>–1</strong>. When <strong id="b15351286998711"><a name="b15351286998711"></a><a name="b15351286998711"></a>group_id</strong> is set to –1, all group information is obtained.</p>
</td>
</tr>
<tr id="row151037235211"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p14103162382116"><a name="p14103162382116"></a><a name="p14103162382116"></a>group_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p5103123132114"><a name="p5103123132114"></a><a name="p5103123132114"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p41036232211"><a name="p41036232211"></a><a name="p41036232211"></a>struct dcmi_capability_group_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p121033235212"><a name="p121033235212"></a><a name="p121033235212"></a>Information about the compute group.</p>
<p id="p110312239214"><a name="p110312239214"></a><a name="p110312239214"></a>The compute capability struct is as follows:</p>
<p id="p15103182311215"><a name="p15103182311215"></a><a name="p15103182311215"></a>#define DCMI_COMPUTE_GROUP_INFO_RES_NUM</p>
<p id="p7103923112114"><a name="p7103923112114"></a><a name="p7103923112114"></a>#define DCMI_AICORE_MASK_NUM 2</p>
<p id="p5103123102120"><a name="p5103123102120"></a><a name="p5103123102120"></a>struct dcmi_capability_group_info {</p>
<p id="p610313237219"><a name="p610313237219"></a><a name="p610313237219"></a>unsigned int  group_id;</p>
<p id="p12103182316212"><a name="p12103182316212"></a><a name="p12103182316212"></a>unsigned int  state;</p>
<p id="p17103202342116"><a name="p17103202342116"></a><a name="p17103202342116"></a>unsigned int  extend_attribute;</p>
<p id="p810382320219"><a name="p810382320219"></a><a name="p810382320219"></a>unsigned int  aicore_number;</p>
<p id="p9103102382114"><a name="p9103102382114"></a><a name="p9103102382114"></a>unsigned int  aivector_number;</p>
<p id="p14103122332117"><a name="p14103122332117"></a><a name="p14103122332117"></a>unsigned int  sdma_number;</p>
<p id="p16103823122115"><a name="p16103823122115"></a><a name="p16103823122115"></a>unsigned int  aicpu_number;</p>
<p id="p1310362332118"><a name="p1310362332118"></a><a name="p1310362332118"></a>unsigned int  active_sq_number;</p>
<p id="p181033233214"><a name="p181033233214"></a><a name="p181033233214"></a>unsigned int  aicore_mask [DCMI_AICORE_MASK_NUM];</p>
<p id="p141034234211"><a name="p141034234211"></a><a name="p141034234211"></a>unsigned int  res[DCMI_COMPUTE_GROUP_INFO_RES_NUM - DCMI_AICORE_MASK_NUM];</p>
<p id="p20103182342117"><a name="p20103182342117"></a><a name="p20103182342117"></a>};</p>
<a name="ul12388191374017"></a><a name="ul12388191374017"></a><ul id="ul12388191374017"><li><strong id="b144961239132317"><a name="b144961239132317"></a><a name="b144961239132317"></a>group_id</strong>: computing power group ID, which is globally unique. Value range: 0–3.</li><li><strong id="b3066972448711"><a name="b3066972448711"></a><a name="b3066972448711"></a>state</strong>: creation status of a computing power group. <strong id="b6940962008711"><a name="b6940962008711"></a><a name="b6940962008711"></a>0</strong>: not created. <strong id="b7010232728711"><a name="b7010232728711"></a><a name="b7010232728711"></a>1</strong>: created.</li><li><strong id="b10817107810"><a name="b10817107810"></a><a name="b10817107810"></a>extend_attribute</strong>: flag of Ascend virtual instances. <strong id="b11901019815"><a name="b11901019815"></a><a name="b11901019815"></a>1</strong>: enabled. Other values indicate that the Ascend virtualization instance is not used as the default group. The default value is <strong id="b19917103814"><a name="b19917103814"></a><a name="b19917103814"></a>0</strong>.</li><li><strong id="b5193734428711"><a name="b5193734428711"></a><a name="b5193734428711"></a>aicore_number</strong>: the number of AI Cores in the computing power group.</li><li><strong id="b16835575688711"><a name="b16835575688711"></a><a name="b16835575688711"></a>aivector_number</strong>, <strong id="b4558686918711"><a name="b4558686918711"></a><a name="b4558686918711"></a>sdma_number</strong>, <strong id="b7940484088711"><a name="b7940484088711"></a><a name="b7940484088711"></a>aicpu_number</strong> and <strong id="b5434517488711"><a name="b5434517488711"></a><a name="b5434517488711"></a>active_sq_number</strong> indicate the number of <strong id="b2175338608711"><a name="b2175338608711"></a><a name="b2175338608711"></a>aivector</strong>, <strong id="b19991720168711"><a name="b19991720168711"></a><a name="b19991720168711"></a>sdma</strong>, <strong id="b20436050508711"><a name="b20436050508711"></a><a name="b20436050508711"></a>aicpu</strong>, and <strong id="b20548531658711"><a name="b20548531658711"></a><a name="b20548531658711"></a>active</strong> resources, respectively. Currently, the return is <strong id="b206100691613"><a name="b206100691613"></a><a name="b206100691613"></a>255</strong>, indicating that the resources are shared and cannot be partitioned.</li><li><strong id="b12658019948711"><a name="b12658019948711"></a><a name="b12658019948711"></a>aicore_mask</strong>: the mask of the AI Core ID. Each bit indicates a core. <strong id="b15712144131114"><a name="b15712144131114"></a><a name="b15712144131114"></a>1</strong>: AI Core in the computing power group. <strong id="b271315411119"><a name="b271315411119"></a><a name="b271315411119"></a>0</strong>: AI Core not in the computing power group.</li><li><strong id="b5505830898711"><a name="b5505830898711"></a><a name="b5505830898711"></a>res</strong>: reserved parameter</li></ul>
</td>
</tr>
<tr id="row1410352362114"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p161031723122118"><a name="p161031723122118"></a><a name="p161031723122118"></a>group_count</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1010372316219"><a name="p1010372316219"></a><a name="p1010372316219"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p1210332314218"><a name="p1210332314218"></a><a name="p1210332314218"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p91032023202119"><a name="p91032023202119"></a><a name="p91032023202119"></a>Length of the <strong id="b7114920808711"><a name="b7114920808711"></a><a name="b7114920808711"></a>group_info</strong> array.</p>
<p id="p410310237215"><a name="p410310237215"></a><a name="p410310237215"></a>When <strong id="b16468097718711"><a name="b16468097718711"></a><a name="b16468097718711"></a>group_id</strong> is set to –1, <strong id="b7403207448711"><a name="b7403207448711"></a><a name="b7403207448711"></a>group_count</strong> must be greater than or equal to 4.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b6616288197946"><a name="b6616288197946"></a><a name="b6616288197946"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="section53132352111"></a>**

This API is used only in open Ctrl CPU form.

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p114288580415"><a name="en-us_topic_0000002515350556_p114288580415"></a><a name="en-us_topic_0000002515350556_p114288580415"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_row19216056194814"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><span id="en-us_topic_0000002515350556_text1564782665814"><a name="en-us_topic_0000002515350556_text1564782665814"></a><a name="en-us_topic_0000002515350556_text1564782665814"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><span id="en-us_topic_0000002515350556_text1123515513517"><a name="en-us_topic_0000002515350556_text1123515513517"></a><a name="en-us_topic_0000002515350556_text1123515513517"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row12693311552"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p17872181618166"><a name="en-us_topic_0000002515350556_p17872181618166"></a><a name="en-us_topic_0000002515350556_p17872181618166"></a><span id="en-us_topic_0000002515350556_text17872121641614"><a name="en-us_topic_0000002515350556_text17872121641614"></a><a name="en-us_topic_0000002515350556_text17872121641614"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p177521042115520"><a name="en-us_topic_0000002515350556_p177521042115520"></a><a name="en-us_topic_0000002515350556_p177521042115520"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12752114215559"><a name="en-us_topic_0000002515350556_p12752114215559"></a><a name="en-us_topic_0000002515350556_p12752114215559"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p18752104275512"><a name="en-us_topic_0000002515350556_p18752104275512"></a><a name="en-us_topic_0000002515350556_p18752104275512"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row179407221298"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p696322918294"><a name="en-us_topic_0000002515350556_p696322918294"></a><a name="en-us_topic_0000002515350556_p696322918294"></a><span id="en-us_topic_0000002515350556_text15963162972914"><a name="en-us_topic_0000002515350556_text15963162972914"></a><a name="en-us_topic_0000002515350556_text15963162972914"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1560813335296"><a name="en-us_topic_0000002515350556_p1560813335296"></a><a name="en-us_topic_0000002515350556_p1560813335296"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p260873392918"><a name="en-us_topic_0000002515350556_p260873392918"></a><a name="en-us_topic_0000002515350556_p260873392918"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p5608333162914"><a name="en-us_topic_0000002515350556_p5608333162914"></a><a name="en-us_topic_0000002515350556_p5608333162914"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19346183355516"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p0905133713551"><a name="en-us_topic_0000002515350556_p0905133713551"></a><a name="en-us_topic_0000002515350556_p0905133713551"></a><span id="en-us_topic_0000002515350556_text1190563775520"><a name="en-us_topic_0000002515350556_text1190563775520"></a><a name="en-us_topic_0000002515350556_text1190563775520"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p7204194395516"><a name="en-us_topic_0000002515350556_p7204194395516"></a><a name="en-us_topic_0000002515350556_p7204194395516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p13205104310553"><a name="en-us_topic_0000002515350556_p13205104310553"></a><a name="en-us_topic_0000002515350556_p13205104310553"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32051943125519"><a name="en-us_topic_0000002515350556_p32051943125519"></a><a name="en-us_topic_0000002515350556_p32051943125519"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1158213431480"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p65418471681"><a name="en-us_topic_0000002515350556_p65418471681"></a><a name="en-us_topic_0000002515350556_p65418471681"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section1134182310216"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int ts_id  = 0;
struct dcmi_capability_group_info group_info[4] = {0};
ret = dcmi_get_capability_group_info(card_id, dev_id, ts_id, -1, group_info, 4);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```
