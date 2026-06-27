# dcmi\_get\_capability\_group\_info<a name="EN-US_TOPIC_0000002515343902"></a>

**Prototype<a name="section14126237219"></a>**

**int dcmi\_get\_capability\_group\_info\(int card\_id, int device\_id, int ts\_id, int group\_id, struct dcmi\_capability\_group\_info \*group\_info, int group\_count\)**

**Description<a name="section1812132352116"></a>**

Obtain the configuration information of the Ascend virtual instance.

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
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p16102823142117"><a name="p16102823142117"></a><a name="p16102823142117"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1007248974102911"><a name="b1007248974102911"></a><a name="b1007248974102911"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row121026234211"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p15102132316213"><a name="p15102132316213"></a><a name="p15102132316213"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1110202310211"><a name="p1110202310211"></a><a name="p1110202310211"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p13102102313214"><a name="p13102102313214"></a><a name="p13102102313214"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p15102152315216"><a name="p15102152315216"></a><a name="p15102152315216"></a>Chip ID, which can be obtained by calling <strong id="b1830365117102555"><a name="b1830365117102555"></a><a name="b1830365117102555"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p11102112342111"><a name="p11102112342111"></a><a name="p11102112342111"></a>NPU: [0, <strong id="b1772078462105416"><a name="b1772078462105416"></a><a name="b1772078462105416"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p3103923102118"><a name="p3103923102118"></a><a name="p3103923102118"></a>Computing power group ID. Value range: 0–3 or <strong id="b16889151919207"><a name="b16889151919207"></a><a name="b16889151919207"></a>–1</strong>. When <strong id="b15351286998711"><a name="b15351286998711"></a><a name="b15351286998711"></a>group_id</strong> is set to –1, all group information is obtained.</p>
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
<a name="ul12388191374017"></a><a name="ul12388191374017"></a><ul id="ul12388191374017"><li><strong id="b12909912123155"><a name="b12909912123155"></a><a name="b12909912123155"></a>group_id</strong> indicates the computing power group ID, which is globally unique. Value range: 0–3.</li><li><strong id="b3066972448711"><a name="b3066972448711"></a><a name="b3066972448711"></a>state</strong>: creation status of a computing power group. <strong id="b6940962008711"><a name="b6940962008711"></a><a name="b6940962008711"></a>0</strong>: not created. <strong id="b7010232728711"><a name="b7010232728711"></a><a name="b7010232728711"></a>1</strong>: created.</li><li><strong id="b172542476203"><a name="b172542476203"></a><a name="b172542476203"></a>extend_attribute</strong>: flag of the Ascend virtual instance. <strong id="b62541478201"><a name="b62541478201"></a><a name="b62541478201"></a>1</strong>: enabled. Other values indicate that the Ascend virtual instance is not used as the default group. The default value is <strong id="b42541047102017"><a name="b42541047102017"></a><a name="b42541047102017"></a>0</strong>.</li><li><strong id="b5193734428711"><a name="b5193734428711"></a><a name="b5193734428711"></a>aicore_number</strong>: the number of AI Cores in the computing power group.</li><li><strong id="b16835575688711"><a name="b16835575688711"></a><a name="b16835575688711"></a>aivector_number</strong>, <strong id="b4558686918711"><a name="b4558686918711"></a><a name="b4558686918711"></a>sdma_number</strong>, <strong id="b7940484088711"><a name="b7940484088711"></a><a name="b7940484088711"></a>aicpu_number</strong> and <strong id="b5434517488711"><a name="b5434517488711"></a><a name="b5434517488711"></a>active_sq_number</strong> indicate the number of <strong id="b2175338608711"><a name="b2175338608711"></a><a name="b2175338608711"></a>aivector</strong>, <strong id="b19991720168711"><a name="b19991720168711"></a><a name="b19991720168711"></a>sdma</strong>, <strong id="b20436050508711"><a name="b20436050508711"></a><a name="b20436050508711"></a>aicpu</strong>, and <strong id="b20548531658711"><a name="b20548531658711"></a><a name="b20548531658711"></a>active</strong> resources, respectively. Currently, the return is 255, indicating that the resources are for sharing and allocation is not supported.</li><li><strong id="b12658019948711"><a name="b12658019948711"></a><a name="b12658019948711"></a>aicore_mask</strong>: the mask of the AI Core ID. Each bit indicates a core. <strong id="b15712144131114"><a name="b15712144131114"></a><a name="b15712144131114"></a>1</strong>: AI Core in the computing power group. <strong id="b271315411119"><a name="b271315411119"></a><a name="b271315411119"></a>0</strong>: AI Core not in the computing power group.</li><li><strong id="b5505830898711"><a name="b5505830898711"></a><a name="b5505830898711"></a>res</strong>: reserved parameter</li></ul>
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

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b13464750758571"><a name="b13464750758571"></a><a name="b13464750758571"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="section53132352111"></a>**

This API is used only in open Ctrl CPU form.

**Table  1** Support in different deployment scenarios

<a name="table1993685321815"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1210513304816"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p558011817325"><a name="en-us_topic_0000002515503852_p558011817325"></a><a name="en-us_topic_0000002515503852_p558011817325"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p25806812321"><a name="en-us_topic_0000002515503852_p25806812321"></a><a name="en-us_topic_0000002515503852_p25806812321"></a><strong id="en-us_topic_0000002515503852_b156561347844"><a name="en-us_topic_0000002515503852_b156561347844"></a><a name="en-us_topic_0000002515503852_b156561347844"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p558018833211"><a name="en-us_topic_0000002515503852_p558018833211"></a><a name="en-us_topic_0000002515503852_p558018833211"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b686519481414"><a name="en-us_topic_0000002515503852_b686519481414"></a><a name="en-us_topic_0000002515503852_b686519481414"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p35801189326"><a name="en-us_topic_0000002515503852_p35801189326"></a><a name="en-us_topic_0000002515503852_p35801189326"></a><strong id="en-us_topic_0000002515503852_b398912494411"><a name="en-us_topic_0000002515503852_b398912494411"></a><a name="en-us_topic_0000002515503852_b398912494411"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row14576182015105"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13661881916"><a name="en-us_topic_0000002515503852_p13661881916"></a><a name="en-us_topic_0000002515503852_p13661881916"></a><span id="en-us_topic_0000002515503852_ph116612081298"><a name="en-us_topic_0000002515503852_ph116612081298"></a><a name="en-us_topic_0000002515503852_ph116612081298"></a><span id="en-us_topic_0000002515503852_text26611487916"><a name="en-us_topic_0000002515503852_text26611487916"></a><a name="en-us_topic_0000002515503852_text26611487916"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p057642081019"><a name="en-us_topic_0000002515503852_p057642081019"></a><a name="en-us_topic_0000002515503852_p057642081019"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p65761200102"><a name="en-us_topic_0000002515503852_p65761200102"></a><a name="en-us_topic_0000002515503852_p65761200102"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1357610206101"><a name="en-us_topic_0000002515503852_p1357610206101"></a><a name="en-us_topic_0000002515503852_p1357610206101"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row318512127818"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611581596"><a name="en-us_topic_0000002515503852_p86611581596"></a><a name="en-us_topic_0000002515503852_p86611581596"></a><span id="en-us_topic_0000002515503852_text66619818911"><a name="en-us_topic_0000002515503852_text66619818911"></a><a name="en-us_topic_0000002515503852_text66619818911"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1441443298"><a name="en-us_topic_0000002515503852_p1441443298"></a><a name="en-us_topic_0000002515503852_p1441443298"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2420631892"><a name="en-us_topic_0000002515503852_p2420631892"></a><a name="en-us_topic_0000002515503852_p2420631892"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18425123899"><a name="en-us_topic_0000002515503852_p18425123899"></a><a name="en-us_topic_0000002515503852_p18425123899"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1273713241084"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p56611781094"><a name="en-us_topic_0000002515503852_p56611781094"></a><a name="en-us_topic_0000002515503852_p56611781094"></a><span id="en-us_topic_0000002515503852_text56611281693"><a name="en-us_topic_0000002515503852_text56611281693"></a><a name="en-us_topic_0000002515503852_text56611281693"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p64311736915"><a name="en-us_topic_0000002515503852_p64311736915"></a><a name="en-us_topic_0000002515503852_p64311736915"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p04391434914"><a name="en-us_topic_0000002515503852_p04391434914"></a><a name="en-us_topic_0000002515503852_p04391434914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p244917315919"><a name="en-us_topic_0000002515503852_p244917315919"></a><a name="en-us_topic_0000002515503852_p244917315919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7672192219815"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p166611689914"><a name="en-us_topic_0000002515503852_p166611689914"></a><a name="en-us_topic_0000002515503852_p166611689914"></a><span id="en-us_topic_0000002515503852_text126611581798"><a name="en-us_topic_0000002515503852_text126611581798"></a><a name="en-us_topic_0000002515503852_text126611581798"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p12459143996"><a name="en-us_topic_0000002515503852_p12459143996"></a><a name="en-us_topic_0000002515503852_p12459143996"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10470531895"><a name="en-us_topic_0000002515503852_p10470531895"></a><a name="en-us_topic_0000002515503852_p10470531895"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12476033912"><a name="en-us_topic_0000002515503852_p12476033912"></a><a name="en-us_topic_0000002515503852_p12476033912"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row153452020881"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611181098"><a name="en-us_topic_0000002515503852_p86611181098"></a><a name="en-us_topic_0000002515503852_p86611181098"></a><span id="en-us_topic_0000002515503852_text16611819911"><a name="en-us_topic_0000002515503852_text16611819911"></a><a name="en-us_topic_0000002515503852_text16611819911"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134813311917"><a name="en-us_topic_0000002515503852_p134813311917"></a><a name="en-us_topic_0000002515503852_p134813311917"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3486231596"><a name="en-us_topic_0000002515503852_p3486231596"></a><a name="en-us_topic_0000002515503852_p3486231596"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p44911135913"><a name="en-us_topic_0000002515503852_p44911135913"></a><a name="en-us_topic_0000002515503852_p44911135913"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row20496217988"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611689916"><a name="en-us_topic_0000002515503852_p86611689916"></a><a name="en-us_topic_0000002515503852_p86611689916"></a><span id="en-us_topic_0000002515503852_text105131140182910"><a name="en-us_topic_0000002515503852_text105131140182910"></a><a name="en-us_topic_0000002515503852_text105131140182910"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p649613392"><a name="en-us_topic_0000002515503852_p649613392"></a><a name="en-us_topic_0000002515503852_p649613392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2050114313914"><a name="en-us_topic_0000002515503852_p2050114313914"></a><a name="en-us_topic_0000002515503852_p2050114313914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p175075312918"><a name="en-us_topic_0000002515503852_p175075312918"></a><a name="en-us_topic_0000002515503852_p175075312918"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1775216157819"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p766118812915"><a name="en-us_topic_0000002515503852_p766118812915"></a><a name="en-us_topic_0000002515503852_p766118812915"></a><span id="en-us_topic_0000002515503852_text136611481596"><a name="en-us_topic_0000002515503852_text136611481596"></a><a name="en-us_topic_0000002515503852_text136611481596"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p205121037920"><a name="en-us_topic_0000002515503852_p205121037920"></a><a name="en-us_topic_0000002515503852_p205121037920"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5517131993"><a name="en-us_topic_0000002515503852_p5517131993"></a><a name="en-us_topic_0000002515503852_p5517131993"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p115221437916"><a name="en-us_topic_0000002515503852_p115221437916"></a><a name="en-us_topic_0000002515503852_p115221437916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1499855417336"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p48161158173310"><a name="en-us_topic_0000002515503852_p48161158173310"></a><a name="en-us_topic_0000002515503852_p48161158173310"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section1134182310216"></a>**

```C
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int ts_id  = 0;
struct dcmi_capability_group_info group_info[4] = {0};
ret = dcmi_get_capability_group_info(card_id, dev_id, ts_id, -1, group_info, 4);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```
