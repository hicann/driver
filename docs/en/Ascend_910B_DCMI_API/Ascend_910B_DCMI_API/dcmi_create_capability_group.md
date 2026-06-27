# dcmi\_create\_capability\_group<a name="EN-US_TOPIC_0000002546983743"></a>

**Prototype<a name="section5631123462011"></a>**

**int dcmi\_create\_capability\_group\(int card\_id, int device\_id, int ts\_id, struct dcmi\_capability\_group\_info \*group\_info\)**

**Description<a name="section19632193492013"></a>**

Creates the configuration information of Ascend virtual instances.

**Parameter Description<a name="section9633113472012"></a>**

<a name="table766115345203"></a>
<table><thead align="left"><tr id="row197331434162017"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p20733143416202"><a name="p20733143416202"></a><a name="p20733143416202"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p2733734202019"><a name="p2733734202019"></a><a name="p2733734202019"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.150000000000002%" id="mcps1.1.5.1.3"><p id="p14733034152020"><a name="p14733034152020"></a><a name="p14733034152020"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.529999999999994%" id="mcps1.1.5.1.4"><p id="p1173393411206"><a name="p1173393411206"></a><a name="p1173393411206"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4733163412208"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p13733163432013"><a name="p13733163432013"></a><a name="p13733163432013"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p573323413208"><a name="p573323413208"></a><a name="p573323413208"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p77331534152011"><a name="p77331534152011"></a><a name="p77331534152011"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.529999999999994%" headers="mcps1.1.5.1.4 "><p id="p073313492011"><a name="p073313492011"></a><a name="p073313492011"></a>Device ID. The supported IDs can be obtained by calling <strong id="b52079548610298"><a name="b52079548610298"></a><a name="b52079548610298"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row0733113462010"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1073383411207"><a name="p1073383411207"></a><a name="p1073383411207"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p167344341203"><a name="p167344341203"></a><a name="p167344341203"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p1173423420208"><a name="p1173423420208"></a><a name="p1173423420208"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.529999999999994%" headers="mcps1.1.5.1.4 "><p id="p9734103492015"><a name="p9734103492015"></a><a name="p9734103492015"></a>Chip ID, which can be obtained by calling <strong id="b1057479684102552"><a name="b1057479684102552"></a><a name="b1057479684102552"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p0734183415202"><a name="p0734183415202"></a><a name="p0734183415202"></a>NPU: [0, <strong id="b1524438209105415"><a name="b1524438209105415"></a><a name="b1524438209105415"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row1873493415205"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p18734173402017"><a name="p18734173402017"></a><a name="p18734173402017"></a>ts_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1734143452017"><a name="p1734143452017"></a><a name="p1734143452017"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p187341434172015"><a name="p187341434172015"></a><a name="p187341434172015"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.529999999999994%" headers="mcps1.1.5.1.4 "><p id="p9734113472015"><a name="p9734113472015"></a><a name="p9734113472015"></a>Computing power type ID:</p>
<p id="p1573453410204"><a name="p1573453410204"></a><a name="p1573453410204"></a>typedef enum {</p>
<p id="p273423442020"><a name="p273423442020"></a><a name="p273423442020"></a>DCMI_TS_AICORE = 0,</p>
<p id="p1873453415201"><a name="p1873453415201"></a><a name="p1873453415201"></a>DCMI_TS_AIVECTOR,</p>
<p id="p6734834192015"><a name="p6734834192015"></a><a name="p6734834192015"></a>} DCMI_TS_ID;</p>
<p id="p13734103432012"><a name="p13734103432012"></a><a name="p13734103432012"></a>Currently, <strong id="b1736616330554"><a name="b1736616330554"></a><a name="b1736616330554"></a>DCMI_TS_AIVECTOR</strong> is not supported.</p>
</td>
</tr>
<tr id="row973413418206"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1873443410208"><a name="p1873443410208"></a><a name="p1873443410208"></a>group_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p073411342202"><a name="p073411342202"></a><a name="p073411342202"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p473412343208"><a name="p473412343208"></a><a name="p473412343208"></a>struct dcmi_capability_group_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.529999999999994%" headers="mcps1.1.5.1.4 "><p id="p1873415347208"><a name="p1873415347208"></a><a name="p1873415347208"></a>Information about the compute group.</p>
<p id="p67342346202"><a name="p67342346202"></a><a name="p67342346202"></a>The compute capability struct is as follows:</p>
<p id="p97347342201"><a name="p97347342201"></a><a name="p97347342201"></a>#define DCMI_COMPUTE_GROUP_INFO_RES_NUM - AICORE_MASK_NUM 8</p>
<p id="p373473415203"><a name="p373473415203"></a><a name="p373473415203"></a>#define DCMI_AICORE_MASK_NUM 2</p>
<p id="p20734143412020"><a name="p20734143412020"></a><a name="p20734143412020"></a>struct dcmi_capability_group_info {</p>
<p id="p173416342208"><a name="p173416342208"></a><a name="p173416342208"></a>unsigned int  group_id;</p>
<p id="p127345347206"><a name="p127345347206"></a><a name="p127345347206"></a>unsigned int  state;</p>
<p id="p167344343200"><a name="p167344343200"></a><a name="p167344343200"></a>unsigned int  extend_attribute;</p>
<p id="p473413402014"><a name="p473413402014"></a><a name="p473413402014"></a>unsigned int  aicore_number;</p>
<p id="p16734834152014"><a name="p16734834152014"></a><a name="p16734834152014"></a>unsigned int  aivector_number;</p>
<p id="p13734183418205"><a name="p13734183418205"></a><a name="p13734183418205"></a>unsigned int  sdma_number;</p>
<p id="p18734634152016"><a name="p18734634152016"></a><a name="p18734634152016"></a>unsigned int  aicpu_number;</p>
<p id="p167341134162016"><a name="p167341134162016"></a><a name="p167341134162016"></a>unsigned int  active_sq_number;</p>
<p id="p973413492019"><a name="p973413492019"></a><a name="p973413492019"></a>unsigned int  aicore_mask [DCMI_AICORE_MASK_NUM];</p>
<p id="p1673403411209"><a name="p1673403411209"></a><a name="p1673403411209"></a>unsigned int  res[DCMI_COMPUTE_GROUP_INFO_RES_NUM - DCMI_AICORE_MASK_NUM];</p>
<p id="p37345343205"><a name="p37345343205"></a><a name="p37345343205"></a>};</p>
<a name="ul87874572324"></a><a name="ul87874572324"></a><ul id="ul87874572324"><li><strong id="b121251588147"><a name="b121251588147"></a><a name="b121251588147"></a>group_id</strong> indicates the computing power group ID, which is globally unique. The value ranges from 0 to 3. If the value is duplicate, the creation fails.</li></ul>
<a name="ul11464113418334"></a><a name="ul11464113418334"></a><ul id="ul11464113418334"><li><strong id="b248014510569"><a name="b248014510569"></a><a name="b248014510569"></a>state</strong>: creation status of a computing power group. <strong id="b20267135648837"><a name="b20267135648837"></a><a name="b20267135648837"></a>0</strong>: not created. <strong id="b3649097248837"><a name="b3649097248837"></a><a name="b3649097248837"></a>1</strong>: created. When this field is used as an input, it is meaningless.</li><li><strong id="b6847137158"><a name="b6847137158"></a><a name="b6847137158"></a>extend_attribute</strong>: flag of the Ascend virtual instance. <strong id="b128481134158"><a name="b128481134158"></a><a name="b128481134158"></a>1</strong>: enabled. Other values indicate that the Ascend virtual instance is not used as the default group. The default value is <strong id="b1084819381518"><a name="b1084819381518"></a><a name="b1084819381518"></a>0</strong>.</li><li>The value of <strong id="b264915160589"><a name="b264915160589"></a><a name="b264915160589"></a>aicore_number</strong> ranges from 0 to 8, or can be 255. For details, see the following description.</li><li><strong id="b154903240587"><a name="b154903240587"></a><a name="b154903240587"></a>aivector_number</strong>, <strong id="b18491162475817"><a name="b18491162475817"></a><a name="b18491162475817"></a>sdma_number</strong>, <strong id="b1749162445811"><a name="b1749162445811"></a><a name="b1749162445811"></a>aicpu_number</strong> and <strong id="b149262485816"><a name="b149262485816"></a><a name="b149262485816"></a>active_sq_number</strong> can only be set to 255, indicating that the remaining available values are configured and allocation is not supported.</li><li><strong id="b20566794648837"><a name="b20566794648837"></a><a name="b20566794648837"></a>aicore_mask</strong>: the mask of the AI Core ID. Each bit indicates a core. <strong id="b15501448068837"><a name="b15501448068837"></a><a name="b15501448068837"></a>1</strong>: AI Core in the computing power group. <strong id="b19214733728837"><a name="b19214733728837"></a><a name="b19214733728837"></a>0</strong>: AI Core not in the computing power group. When this field is used as an input, it is meaningless.</li><li><strong id="b2010794618581"><a name="b2010794618581"></a><a name="b2010794618581"></a>res</strong>: reserved parameter<div class="note" id="note188303923512"><a name="note188303923512"></a><a name="note188303923512"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p653145383518"><a name="p653145383518"></a><a name="p653145383518"></a>Restrictions on <strong id="b14750920158837"><a name="b14750920158837"></a><a name="b14750920158837"></a>group_info</strong>:</p>
<a name="ul34731046183513"></a><a name="ul34731046183513"></a><ul id="ul34731046183513"><li>The value of <strong id="b14701753141715"><a name="b14701753141715"></a><a name="b14701753141715"></a>group_id</strong> ranges from 0 to 3. A newly set <strong id="b1170115341719"><a name="b1170115341719"></a><a name="b1170115341719"></a>group_id</strong> should be unused before; otherwise, a failure message is returned.</li><li>When creating different groups, ensure that the following conditions are met:<ul id="ul97411537203318"><li><img class="mathml" id="image15114194043912" src="../../../en/figures/gongshi.png" width="226.10000000000002" height="31.348100000000002">&nbsp;</li><li><strong id="b3751335068837"><a name="b3751335068837"></a><a name="b3751335068837"></a>total_aicore_number</strong> is 8.</li><li>When <strong id="b16725885278837"><a name="b16725885278837"></a><a name="b16725885278837"></a>aicore_number</strong> is set to 255, all available cores are occupied by the group. If 255 is configured for multiple groups, these groups share the available cores.</li></ul>
</li></ul>
</div></div>
</li></ul>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b1041614218570"><a name="b1041614218570"></a><a name="b1041614218570"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="section3125938142713"></a>**

- This API is used only in open Ctrl CPU form.
- Before making this API call, call the  [dcmi\_get\_capability\_group\_info](dcmi_get_capability_group_info.md)  API to obtain the configured resource information and set inputs in accordance with restrictions on  **ts\_id**  and  **group\_info**. To delete the existing configuration, call the  [dcmi\_delete\_capability\_group](dcmi_delete_capability_group.md)  API.

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

**Example<a name="section206582034172018"></a>**

```C
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int ts_id = 0;
struct dcmi_capability_group_info group_info = {0};
group_info.group_id = 0;
group_info.aivector_number = 255;
group_info.sdma_number = 255;
group_info.aicpu_number = 255;
group_info.active_sq_number = 255;
group_info.aicore_number = 8;
 
ret = dcmi_create_capability_group(card_id, dev_id, ts_id, &group_info);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```
