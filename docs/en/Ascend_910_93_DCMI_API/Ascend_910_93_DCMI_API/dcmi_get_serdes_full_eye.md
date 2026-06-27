# dcmi\_get\_serdes\_full\_eye<a name="EN-US_TOPIC_0000002515510430"></a>

**Prototype<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412077"></a>**

**int dcmi\_get\_serdes\_full\_eye\(int card\_id, int device\_id, struct dcmi\_serdes\_full\_eye \*serdes\_full\_eye\_info\)**

**Description<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412078"></a>**

Queries the full eye diagram information for a specific lane on a designated NPU macro port. Currently, this API can retrieve only the composite eye diagram using the inner-eye vertical scan mode.

**Parameter Description<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412079"></a>**

<a name="table2736627173213"></a>
<table><thead align="left"><tr id="row37511727123212"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p3751827143219"><a name="p3751827143219"></a><a name="p3751827143219"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p10751142783216"><a name="p10751142783216"></a><a name="p10751142783216"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p1575112718322"><a name="p1575112718322"></a><a name="p1575112718322"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p13751142783210"><a name="p13751142783210"></a><a name="p13751142783210"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row875132713328"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1751927173218"><a name="p1751927173218"></a><a name="p1751927173218"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p275182733212"><a name="p275182733212"></a><a name="p275182733212"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p375112713322"><a name="p375112713322"></a><a name="p375112713322"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p12751627153211"><a name="p12751627153211"></a><a name="p12751627153211"></a>Device ID. The supported IDs can be obtained by calling <strong id="b192308032733145"><a name="b192308032733145"></a><a name="b192308032733145"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="row87511127163211"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p157511227143210"><a name="p157511227143210"></a><a name="p157511227143210"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p875111272328"><a name="p875111272328"></a><a name="p875111272328"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p6751162712320"><a name="p6751162712320"></a><a name="p6751162712320"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p075152718324"><a name="p075152718324"></a><a name="p075152718324"></a>Chip ID, which can be obtained by calling <strong id="b2439828563313"><a name="b2439828563313"></a><a name="b2439828563313"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p875116277323"><a name="p875116277323"></a><a name="p875116277323"></a>NPU: [0, <strong id="b8596185718158"><a name="b8596185718158"></a><a name="b8596185718158"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row7751112703217"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1434513331784"><a name="p1434513331784"></a><a name="p1434513331784"></a>serdes_full_eye_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p334593312811"><a name="p334593312811"></a><a name="p334593312811"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p15345143311818"><a name="p15345143311818"></a><a name="p15345143311818"></a>dcmi_serdes_full_eye *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p126724643516"><a name="p126724643516"></a><a name="p126724643516"></a>Structure for querying the full eye diagram. The full eye diagram is a composite eye diagram using the inner-eye vertical scan mode.</p>
<p id="p15151250141116"><a name="p15151250141116"></a><a name="p15151250141116"></a>The full eye diagram data for each lane comprises a maximum of 256 data points. Each data point group includes an offset and two corresponding coordinate values.</p>
<p id="p1969445582"><a name="p1969445582"></a><a name="p1969445582"></a>The structure is defined as follows:</p>
<p id="p1982514210276"><a name="p1982514210276"></a><a name="p1982514210276"></a>#define SERDES_FULL_EYE_INFO_NUM 256</p>
<p id="p882554272718"><a name="p882554272718"></a><a name="p882554272718"></a>#define SERDES_FULL_EYE_RESERVED_LEN 8</p>
<p id="p182564252713"><a name="p182564252713"></a><a name="p182564252713"></a>struct dcmi_serdes_full_eye_base {</p>
<p id="p2825742192718"><a name="p2825742192718"></a><a name="p2825742192718"></a>int offset; // Offset</p>
<p id="p18825242182719"><a name="p18825242182719"></a><a name="p18825242182719"></a>int eye_diagram_0; // Coordinate value 0 corresponding to the offset</p>
<p id="p1682524214277"><a name="p1682524214277"></a><a name="p1682524214277"></a>int eye_diagram_1; // Coordinate value 1 corresponding to the offset</p>
<p id="p15825104262715"><a name="p15825104262715"></a><a name="p15825104262715"></a>};</p>
<p id="p1825742132711"><a name="p1825742132711"></a><a name="p1825742132711"></a>typedef struct dcmi_serdes_full_eye {</p>
<p id="p1082512424277"><a name="p1082512424277"></a><a name="p1082512424277"></a>unsigned int macro_id; // ID of the macro port to be queried. This function currently only supports the h32 macro port, with valid values being <strong id="b185621340104618"><a name="b185621340104618"></a><a name="b185621340104618"></a>9</strong> or <strong id="b172781432468"><a name="b172781432468"></a><a name="b172781432468"></a>10</strong> (only for A200T A3 Box8 server).</p>
<p id="p1882514423271"><a name="p1882514423271"></a><a name="p1882514423271"></a>unsigned int lane_id; // Lane to be queried</p>
<p id="p15825342112713"><a name="p15825342112713"></a><a name="p15825342112713"></a>unsigned int reserved[SERDES_FULL_EYE_RESERVED_LEN]; // Reserved field</p>
<p id="p98251942182712"><a name="p98251942182712"></a><a name="p98251942182712"></a>unsigned int info_size; // Length of the returned full eye diagram result data</p>
<p id="p15825104219279"><a name="p15825104219279"></a><a name="p15825104219279"></a>struct dcmi_serdes_full_eye_base serdes_full_eye[SERDES_FULL_EYE_INFO_NUM]; // Full eye diagram data of each group</p>
<p id="p3825174219273"><a name="p3825174219273"></a><a name="p3825174219273"></a>} DCMI_SERDES_FULL_EYE;</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b16436534088158"><a name="b16436534088158"></a><a name="b16436534088158"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="section8765321374"></a>**

This API can be used on physical machines and in privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table20788125825517"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row6501201391416"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1050161321419"><a name="en-us_topic_0000002515350556_p1050161321419"></a><a name="en-us_topic_0000002515350556_p1050161321419"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p18501913131413"><a name="en-us_topic_0000002515350556_p18501913131413"></a><a name="en-us_topic_0000002515350556_p18501913131413"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p1501151319149"><a name="en-us_topic_0000002515350556_p1501151319149"></a><a name="en-us_topic_0000002515350556_p1501151319149"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row5501131311410"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p195011513161419"><a name="en-us_topic_0000002515350556_p195011513161419"></a><a name="en-us_topic_0000002515350556_p195011513161419"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p12501213101415"><a name="en-us_topic_0000002515350556_p12501213101415"></a><a name="en-us_topic_0000002515350556_p12501213101415"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p25011113201418"><a name="en-us_topic_0000002515350556_p25011113201418"></a><a name="en-us_topic_0000002515350556_p25011113201418"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row7501101371412"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p85021133146"><a name="en-us_topic_0000002515350556_p85021133146"></a><a name="en-us_topic_0000002515350556_p85021133146"></a><span id="en-us_topic_0000002515350556_text14502413151414"><a name="en-us_topic_0000002515350556_text14502413151414"></a><a name="en-us_topic_0000002515350556_text14502413151414"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p126134434150"><a name="en-us_topic_0000002515350556_p126134434150"></a><a name="en-us_topic_0000002515350556_p126134434150"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p20502181319141"><a name="en-us_topic_0000002515350556_p20502181319141"></a><a name="en-us_topic_0000002515350556_p20502181319141"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1250281314143"><a name="en-us_topic_0000002515350556_p1250281314143"></a><a name="en-us_topic_0000002515350556_p1250281314143"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14502111318141"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1850241391415"><a name="en-us_topic_0000002515350556_p1850241391415"></a><a name="en-us_topic_0000002515350556_p1850241391415"></a><span id="en-us_topic_0000002515350556_text1550201371412"><a name="en-us_topic_0000002515350556_text1550201371412"></a><a name="en-us_topic_0000002515350556_text1550201371412"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1563314438157"><a name="en-us_topic_0000002515350556_p1563314438157"></a><a name="en-us_topic_0000002515350556_p1563314438157"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p450261315143"><a name="en-us_topic_0000002515350556_p450261315143"></a><a name="en-us_topic_0000002515350556_p450261315143"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1750213136147"><a name="en-us_topic_0000002515350556_p1750213136147"></a><a name="en-us_topic_0000002515350556_p1750213136147"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1350261315144"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p165021213171419"><a name="en-us_topic_0000002515350556_p165021213171419"></a><a name="en-us_topic_0000002515350556_p165021213171419"></a><span id="en-us_topic_0000002515350556_text65024132144"><a name="en-us_topic_0000002515350556_text65024132144"></a><a name="en-us_topic_0000002515350556_text65024132144"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p9651124313150"><a name="en-us_topic_0000002515350556_p9651124313150"></a><a name="en-us_topic_0000002515350556_p9651124313150"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p45021313141413"><a name="en-us_topic_0000002515350556_p45021313141413"></a><a name="en-us_topic_0000002515350556_p45021313141413"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p850261315146"><a name="en-us_topic_0000002515350556_p850261315146"></a><a name="en-us_topic_0000002515350556_p850261315146"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1150210135144"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p85021713181415"><a name="en-us_topic_0000002515350556_p85021713181415"></a><a name="en-us_topic_0000002515350556_p85021713181415"></a><span id="en-us_topic_0000002515350556_text75023132148"><a name="en-us_topic_0000002515350556_text75023132148"></a><a name="en-us_topic_0000002515350556_text75023132148"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p16571443161520"><a name="en-us_topic_0000002515350556_p16571443161520"></a><a name="en-us_topic_0000002515350556_p16571443161520"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p150251391416"><a name="en-us_topic_0000002515350556_p150251391416"></a><a name="en-us_topic_0000002515350556_p150251391416"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8502111319143"><a name="en-us_topic_0000002515350556_p8502111319143"></a><a name="en-us_topic_0000002515350556_p8502111319143"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row4502913101412"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p25023136145"><a name="en-us_topic_0000002515350556_p25023136145"></a><a name="en-us_topic_0000002515350556_p25023136145"></a><span id="en-us_topic_0000002515350556_text4502191331419"><a name="en-us_topic_0000002515350556_text4502191331419"></a><a name="en-us_topic_0000002515350556_text4502191331419"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p250291313144"><a name="en-us_topic_0000002515350556_p250291313144"></a><a name="en-us_topic_0000002515350556_p250291313144"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p19502713101415"><a name="en-us_topic_0000002515350556_p19502713101415"></a><a name="en-us_topic_0000002515350556_p19502713101415"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1150261316146"><a name="en-us_topic_0000002515350556_p1150261316146"></a><a name="en-us_topic_0000002515350556_p1150261316146"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19502151319148"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10502191381420"><a name="en-us_topic_0000002515350556_p10502191381420"></a><a name="en-us_topic_0000002515350556_p10502191381420"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206147244_en-us_topic_0000001223414441_en-us_topic_0000001099619850_toc533412083"></a>**

```c
...   
int ret = 0;  
 int card_id = 0;  
 int device_id = 0;  
 struct dcmi_serdes_full_eye serdes_full_eye_info = {
          .macro_id = 9,
          .lane_id = 0,
          .serdes_full_eye = {0} 
 } 
 ret = dcmi_get_serdes_full_eye(card_id, device_id, &serdes_full_eye_info);  
...
```
