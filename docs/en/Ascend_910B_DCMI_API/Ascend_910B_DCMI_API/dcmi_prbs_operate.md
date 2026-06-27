# dcmi\_prbs\_operate<a name="EN-US_TOPIC_0000002515343900"></a>

**Prototype<a name="section428918818434"></a>**

**int dcmi\_prbs\_operate\(int card\_id, int device\_id, struct dcmi\_prbs\_operate\_param operate\_para, struct dcmi\_prbs\_operate\_result \*operate\_result\)**

**Description<a name="section162912812435"></a>**

Sends traffic to the Ascend NPU chip and obtains the traffic sending result.

**Parameter Description<a name="section529358154316"></a>**

<a name="table6390285439"></a>
<table><thead align="left"><tr id="row15504689437"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p6504198204312"><a name="p6504198204312"></a><a name="p6504198204312"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="11.92%" id="mcps1.1.5.1.2"><p id="p45041818432"><a name="p45041818432"></a><a name="p45041818432"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.220000000000002%" id="mcps1.1.5.1.3"><p id="p1450419814310"><a name="p1450419814310"></a><a name="p1450419814310"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="54.690000000000005%" id="mcps1.1.5.1.4"><p id="p45046812433"><a name="p45046812433"></a><a name="p45046812433"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row185041987434"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1750511894313"><a name="p1750511894313"></a><a name="p1750511894313"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.2 "><p id="p65056816436"><a name="p65056816436"></a><a name="p65056816436"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.5.1.3 "><p id="p125055834311"><a name="p125055834311"></a><a name="p125055834311"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p14505788439"><a name="p14505788439"></a><a name="p14505788439"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1221233771102842"><a name="b1221233771102842"></a><a name="b1221233771102842"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row105051780432"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2505581438"><a name="p2505581438"></a><a name="p2505581438"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.2 "><p id="p6505198134310"><a name="p6505198134310"></a><a name="p6505198134310"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.5.1.3 "><p id="p950510814437"><a name="p950510814437"></a><a name="p950510814437"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p55058810433"><a name="p55058810433"></a><a name="p55058810433"></a>Chip ID, which can be obtained by calling <strong id="b648519541102512"><a name="b648519541102512"></a><a name="b648519541102512"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p155061289436"><a name="p155061289436"></a><a name="p155061289436"></a>NPU: [0, <strong id="b318215370528"><a name="b318215370528"></a><a name="b318215370528"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row1450638194317"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p16506188124320"><a name="p16506188124320"></a><a name="p16506188124320"></a>operate_para</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.2 "><p id="p125061184431"><a name="p125061184431"></a><a name="p125061184431"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.5.1.3 "><p id="p9506158134317"><a name="p9506158134317"></a><a name="p9506158134317"></a>DCMI_PRBS_OPERATE_PARAM</p>
</td>
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p1250688114319"><a name="p1250688114319"></a><a name="p1250688114319"></a>Input parameters of the PRBS bit stream. The parameters in the following structure are used to distinguish between traffic sending and traffic sending result to be queried.</p>
<p id="p101001532182"><a name="p101001532182"></a><a name="p101001532182"></a>typedef struct dcmi_serdes_prbs_param_base {</p>
<p id="p1910017313185"><a name="p1910017313185"></a><a name="p1910017313185"></a>unsigned int serdes_prbs_macro_id; // Only traffic sending to macro_0 is supported.</p>
<p id="p181004341818"><a name="p181004341818"></a><a name="p181004341818"></a>unsigned int serdes_prbs_start_lane_id;// Start ID of a lane. The value ranges from 0 to 3.</p>
<p id="p111006311183"><a name="p111006311183"></a><a name="p111006311183"></a>unsigned int serdes_prbs_lane_count; // Number of lanes. The value ranges from 1 to 4.</p>
<p id="p310033151818"><a name="p310033151818"></a><a name="p310033151818"></a>} DCMI_SERDES_PRBS_PARAM_BASE;</p>
<p id="p1510018391816"><a name="p1510018391816"></a><a name="p1510018391816"></a>typedef DCMI_SERDES_PRBS_PARAM_BASE DCMI_SERDES_PRBS_GET_PARAM; // Input <strong id="b1135220272588"><a name="b1135220272588"></a><a name="b1135220272588"></a>PARAM_BASE</strong> to obtain the traffic sending result, whose type is specified by <strong id="b14352182785814"><a name="b14352182785814"></a><a name="b14352182785814"></a>sub_cmd</strong>.</p>
<p id="p110016316188"><a name="p110016316188"></a><a name="p110016316188"></a>typedef struct dcmi_serdes_prbs_set_param {</p>
<p id="p9100173131817"><a name="p9100173131817"></a><a name="p9100173131817"></a>DCMI_SERDES_PRBS_PARAM_BASE param_base; // Basic parameters of the traffic sending settings.</p>
<p id="p161001335180"><a name="p161001335180"></a><a name="p161001335180"></a>unsigned int serdes_prbs_type; // Code type of the traffic sending. For details, see the PRBS code type enumeration.</p>
<p id="p15100734183"><a name="p15100734183"></a><a name="p15100734183"></a>unsigned int serdes_prbs_direction; // Direction of the traffic sending. For details, see the enumeration of PRBS traffic sending directions.</p>
<p id="p1210063131814"><a name="p1210063131814"></a><a name="p1210063131814"></a>} DCMI_SERDES_PRBS_SET_PARAM;</p>
<p id="p1610073161819"><a name="p1610073161819"></a><a name="p1610073161819"></a>typedef struct dcmi_prbs_operate_param {</p>
<p id="p1810063111816"><a name="p1810063111816"></a><a name="p1810063111816"></a>unsigned int main_cmd; // Traffic sending command. For details, see the enumeration of main command words.</p>
<p id="p1510017361810"><a name="p1510017361810"></a><a name="p1510017361810"></a>unsigned int sub_cmd; // Flag indicating whether the command is used to set traffic sending or query the traffic sending result.</p>
<p id="p1610015371810"><a name="p1610015371810"></a><a name="p1610015371810"></a>union {</p>
<p id="p5100335189"><a name="p5100335189"></a><a name="p5100335189"></a>DCMI_SERDES_PRBS_SET_PARAM set_param; // Set traffic sending parameters.</p>
<p id="p12100037189"><a name="p12100037189"></a><a name="p12100037189"></a>DCMI_SERDES_PRBS_GET_PARAM get_param; // Query the traffic sending result.</p>
<p id="p0100133171811"><a name="p0100133171811"></a><a name="p0100133171811"></a>} operate_para;</p>
<p id="p18100103121813"><a name="p18100103121813"></a><a name="p18100103121813"></a>} DCMI_PRBS_OPERATE_PARAM;</p>
<p id="p195049239555"><a name="p195049239555"></a><a name="p195049239555"></a>// Enumeration of main command words</p>
<p id="p155041623115511"><a name="p155041623115511"></a><a name="p155041623115511"></a>enum dcmi_prbs_main_cmd_list {</p>
<p id="p850402375512"><a name="p850402375512"></a><a name="p850402375512"></a>DSMI_SERDES_CMD_PRBS = 0, // Command for traffic sending</p>
<p id="p350432375520"><a name="p350432375520"></a><a name="p350432375520"></a>DSMI_SERDES_CMD_MAX</p>
<p id="p155044232552"><a name="p155044232552"></a><a name="p155044232552"></a>};</p>
<p id="p15504172316553"><a name="p15504172316553"></a><a name="p15504172316553"></a>// Subcommand word enumeration</p>
<p id="p115051623165515"><a name="p115051623165515"></a><a name="p115051623165515"></a>enum dcmi_prbs_sub_cmd_list {</p>
<p id="p1250592345518"><a name="p1250592345518"></a><a name="p1250592345518"></a>SERDES_PRBS_SET_CMD = 0, // Set the subcommand for traffic sending.</p>
<p id="p8505172365516"><a name="p8505172365516"></a><a name="p8505172365516"></a>SERDES_PRBS_GET_RESULT_CMD, // Query the result.</p>
<p id="p10505112315511"><a name="p10505112315511"></a><a name="p10505112315511"></a>SERDES_PRBS_GET_STATUS_CMD, // Query the code type.</p>
<p id="p10505523185516"><a name="p10505523185516"></a><a name="p10505523185516"></a>SERDES_PRBS_SUB_CMD_MAX</p>
<p id="p185051723165511"><a name="p185051723165511"></a><a name="p185051723165511"></a>};</p>
<p id="p950562311553"><a name="p950562311553"></a><a name="p950562311553"></a>// Enumeration of the PRBS code type</p>
<p id="p550511235552"><a name="p550511235552"></a><a name="p550511235552"></a>enum dcmi_serdes_prbs_type_list {</p>
<p id="p1450513238551"><a name="p1450513238551"></a><a name="p1450513238551"></a>SERDES_PRBS_TYPE_END = 0,</p>
<p id="p12505923195516"><a name="p12505923195516"></a><a name="p12505923195516"></a>SERDES_PRBS_TYPE_31 = 8,</p>
<p id="p750582313556"><a name="p750582313556"></a><a name="p750582313556"></a>SERDES_PRBS_TYPE_MAX</p>
<p id="p9505123105513"><a name="p9505123105513"></a><a name="p9505123105513"></a>};</p>
<p id="p0505112385510"><a name="p0505112385510"></a><a name="p0505112385510"></a>// Enumeration of PRBS traffic sending directions</p>
<p id="p1350532345511"><a name="p1350532345511"></a><a name="p1350532345511"></a>enum dcmi_serdes_prbs_direction {</p>
<p id="p135051623195512"><a name="p135051623195512"></a><a name="p135051623195512"></a>SERDES_PRBS_DIRECTION_TX = 0,</p>
<p id="p15505423115519"><a name="p15505423115519"></a><a name="p15505423115519"></a>SERDES_PRBS_DIRECTION_RX,</p>
<p id="p3505152325510"><a name="p3505152325510"></a><a name="p3505152325510"></a>SERDES_PRBS_DIRECTION_TXRX,</p>
<p id="p45051523165511"><a name="p45051523165511"></a><a name="p45051523165511"></a>SERDES_PRBS_DIRECTION_MAX</p>
<p id="p1750552316555"><a name="p1750552316555"></a><a name="p1750552316555"></a>};</p>
</td>
</tr>
<tr id="row85061087433"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p11507178174313"><a name="p11507178174313"></a><a name="p11507178174313"></a>operate_result</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.2 "><p id="p115071088431"><a name="p115071088431"></a><a name="p115071088431"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.5.1.3 "><p id="p9297132912213"><a name="p9297132912213"></a><a name="p9297132912213"></a>DCMI_PRBS_OPERATE_RESULT</p>
</td>
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p175071983435"><a name="p175071983435"></a><a name="p175071983435"></a>Queries the traffic sending result or the PRBS link status.</p>
<p id="p179734420424"><a name="p179734420424"></a><a name="p179734420424"></a>#define MAX_LANE_NUM 8</p>
<p id="p829314942119"><a name="p829314942119"></a><a name="p829314942119"></a>typedef struct dcmi_prbs_operate_result {</p>
<p id="p229339192111"><a name="p229339192111"></a><a name="p229339192111"></a>union {</p>
<p id="p32933992112"><a name="p32933992112"></a><a name="p32933992112"></a>SERDES_PRBS_STATUS_S result[MAX_LANE_NUM]; // Returned result of traffic sending</p>
<p id="p329311913218"><a name="p329311913218"></a><a name="p329311913218"></a>DCMI_SERDES_PRBS_LANE_STATUS lane_status[MAX_LANE_NUM]; // Lane status</p>
<p id="p9294159182117"><a name="p9294159182117"></a><a name="p9294159182117"></a>} prbs_result;</p>
<p id="p529416942111"><a name="p529416942111"></a><a name="p529416942111"></a>} DCMI_PRBS_OPERATE_RESULT;</p>
<p id="p6766454154411"><a name="p6766454154411"></a><a name="p6766454154411"></a>struct dcmi_serdes_prbs_lane_status {</p>
<p id="p676675414449"><a name="p676675414449"></a><a name="p676675414449"></a>unsigned int lane_prbs_tx_status; // Code type of the traffic sending in the TX direction</p>
<p id="p87661054174413"><a name="p87661054174413"></a><a name="p87661054174413"></a>unsigned int lane_prbs_rx_status; // Code type of the traffic sending in the RX direction</p>
<p id="p8766195410445"><a name="p8766195410445"></a><a name="p8766195410445"></a>};</p>
<p id="p197666547445"><a name="p197666547445"></a><a name="p197666547445"></a>typedef struct {</p>
<p id="p37669545447"><a name="p37669545447"></a><a name="p37669545447"></a>unsigned int check_en; // Query whether traffic sending is enabled.</p>
<p id="p6766155434417"><a name="p6766155434417"></a><a name="p6766155434417"></a>unsigned int check_type; // Query the traffic sending code type.</p>
<p id="p1576613547449"><a name="p1576613547449"></a><a name="p1576613547449"></a>unsigned int error_status; // Query the traffic sending status.</p>
<p id="p167667547444"><a name="p167667547444"></a><a name="p167667547444"></a>unsigned int error_cnt; // Number of error code types</p>
<p id="p12766135417441"><a name="p12766135417441"></a><a name="p12766135417441"></a>unsigned long error_rate; // Reciprocal of the traffic sending error rate (1/error_rate), which should be less than 10<sup id="sup367441691311"><a name="sup367441691311"></a><a name="sup367441691311"></a>-5</sup>.</p>
<p id="p18766454114416"><a name="p18766454114416"></a><a name="p18766454114416"></a>unsigned int alos_status; // Amplitude of the input signal. The value <strong id="b1643320236135"><a name="b1643320236135"></a><a name="b1643320236135"></a>0</strong> indicates normal, and the value <strong id="b1433112321313"><a name="b1433112321313"></a><a name="b1433112321313"></a>1</strong> indicates low.</p>
<p id="p87662054174420"><a name="p87662054174420"></a><a name="p87662054174420"></a>unsigned long time_val;// Set the interval between sending traffic and querying the traffic sending result.</p>
<p id="p167661554164418"><a name="p167661554164418"></a><a name="p167661554164418"></a>} SERDES_PRBS_STATUS_S;</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section3642631135017"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b85615885685630"><a name="b85615885685630"></a><a name="b85615885685630"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None.

**Restrictions<a name="section19396154863610"></a>**

- Stop all running services before traffic sending.
- For the Atlas 200T A2 Box16 heterogeneous subrack, Atlas 800T A2 training server, Atlas 800I A2 inference server, Atlas 900 A2 PoD cluster basic unit, and A200I A2 Box heterogeneous component, this API can be used in the PM + privileged container scenario.
- After the driver package is installed or the NPU is reset, you need to wait for 120s before performing traffic sending.
- Traffic sending will cause the NPU network port to go down, due to which a BMC alarm will be generated. The network port cannot be brought up if traffic sending is not disabled.
- The traffic sending function supports optical module loopback \(the optical module must have the loopback capability\), external loopback connector loopback of the optical module, and CDR loopback.
- The Atlas 900 A2 PoD cluster basic unit does not support PRBS traffic sending, while the Atlas 900 A2 PoDc cluster basic unit supports PRBS traffic sending.

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1514515016392"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p15286130203213"><a name="en-us_topic_0000002515503852_p15286130203213"></a><a name="en-us_topic_0000002515503852_p15286130203213"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p132861730113218"><a name="en-us_topic_0000002515503852_p132861730113218"></a><a name="en-us_topic_0000002515503852_p132861730113218"></a><strong id="en-us_topic_0000002515503852_b065416910513"><a name="en-us_topic_0000002515503852_b065416910513"></a><a name="en-us_topic_0000002515503852_b065416910513"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p22861530183212"><a name="en-us_topic_0000002515503852_p22861530183212"></a><a name="en-us_topic_0000002515503852_p22861530183212"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b4800131019511"><a name="en-us_topic_0000002515503852_b4800131019511"></a><a name="en-us_topic_0000002515503852_b4800131019511"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p1928683003217"><a name="en-us_topic_0000002515503852_p1928683003217"></a><a name="en-us_topic_0000002515503852_p1928683003217"></a><strong id="en-us_topic_0000002515503852_b79191511557"><a name="en-us_topic_0000002515503852_b79191511557"></a><a name="en-us_topic_0000002515503852_b79191511557"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row514512014397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14145100183919"><a name="en-us_topic_0000002515503852_p14145100183919"></a><a name="en-us_topic_0000002515503852_p14145100183919"></a><span id="en-us_topic_0000002515503852_ph15145206394"><a name="en-us_topic_0000002515503852_ph15145206394"></a><a name="en-us_topic_0000002515503852_ph15145206394"></a><span id="en-us_topic_0000002515503852_text141451204393"><a name="en-us_topic_0000002515503852_text141451204393"></a><a name="en-us_topic_0000002515503852_text141451204393"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p114519073913"><a name="en-us_topic_0000002515503852_p114519073913"></a><a name="en-us_topic_0000002515503852_p114519073913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p672045395"><a name="en-us_topic_0000002515503852_p672045395"></a><a name="en-us_topic_0000002515503852_p672045395"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p14102046396"><a name="en-us_topic_0000002515503852_p14102046396"></a><a name="en-us_topic_0000002515503852_p14102046396"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1314590133918"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p914590143915"><a name="en-us_topic_0000002515503852_p914590143915"></a><a name="en-us_topic_0000002515503852_p914590143915"></a><span id="en-us_topic_0000002515503852_text151456017398"><a name="en-us_topic_0000002515503852_text151456017398"></a><a name="en-us_topic_0000002515503852_text151456017398"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p114512012392"><a name="en-us_topic_0000002515503852_p114512012392"></a><a name="en-us_topic_0000002515503852_p114512012392"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p161319419393"><a name="en-us_topic_0000002515503852_p161319419393"></a><a name="en-us_topic_0000002515503852_p161319419393"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1019184143917"><a name="en-us_topic_0000002515503852_p1019184143917"></a><a name="en-us_topic_0000002515503852_p1019184143917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1814514011392"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p414590193920"><a name="en-us_topic_0000002515503852_p414590193920"></a><a name="en-us_topic_0000002515503852_p414590193920"></a><span id="en-us_topic_0000002515503852_text161451704394"><a name="en-us_topic_0000002515503852_text161451704394"></a><a name="en-us_topic_0000002515503852_text161451704394"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1514516018392"><a name="en-us_topic_0000002515503852_p1514516018392"></a><a name="en-us_topic_0000002515503852_p1514516018392"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18242403910"><a name="en-us_topic_0000002515503852_p18242403910"></a><a name="en-us_topic_0000002515503852_p18242403910"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18307415390"><a name="en-us_topic_0000002515503852_p18307415390"></a><a name="en-us_topic_0000002515503852_p18307415390"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1114514093913"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1145407399"><a name="en-us_topic_0000002515503852_p1145407399"></a><a name="en-us_topic_0000002515503852_p1145407399"></a><span id="en-us_topic_0000002515503852_text161451007395"><a name="en-us_topic_0000002515503852_text161451007395"></a><a name="en-us_topic_0000002515503852_text161451007395"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p314518015391"><a name="en-us_topic_0000002515503852_p314518015391"></a><a name="en-us_topic_0000002515503852_p314518015391"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13378413911"><a name="en-us_topic_0000002515503852_p13378413911"></a><a name="en-us_topic_0000002515503852_p13378413911"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p8431344398"><a name="en-us_topic_0000002515503852_p8431344398"></a><a name="en-us_topic_0000002515503852_p8431344398"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1114514017397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1114510163910"><a name="en-us_topic_0000002515503852_p1114510163910"></a><a name="en-us_topic_0000002515503852_p1114510163910"></a><span id="en-us_topic_0000002515503852_text01466093919"><a name="en-us_topic_0000002515503852_text01466093919"></a><a name="en-us_topic_0000002515503852_text01466093919"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p214613010391"><a name="en-us_topic_0000002515503852_p214613010391"></a><a name="en-us_topic_0000002515503852_p214613010391"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15471840391"><a name="en-us_topic_0000002515503852_p15471840391"></a><a name="en-us_topic_0000002515503852_p15471840391"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p45014483920"><a name="en-us_topic_0000002515503852_p45014483920"></a><a name="en-us_topic_0000002515503852_p45014483920"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row3146140203913"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p0146160143914"><a name="en-us_topic_0000002515503852_p0146160143914"></a><a name="en-us_topic_0000002515503852_p0146160143914"></a><span id="en-us_topic_0000002515503852_text181621218183218"><a name="en-us_topic_0000002515503852_text181621218183218"></a><a name="en-us_topic_0000002515503852_text181621218183218"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p141461506394"><a name="en-us_topic_0000002515503852_p141461506394"></a><a name="en-us_topic_0000002515503852_p141461506394"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p353114123912"><a name="en-us_topic_0000002515503852_p353114123912"></a><a name="en-us_topic_0000002515503852_p353114123912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p135715415392"><a name="en-us_topic_0000002515503852_p135715415392"></a><a name="en-us_topic_0000002515503852_p135715415392"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row31461604397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p714619015395"><a name="en-us_topic_0000002515503852_p714619015395"></a><a name="en-us_topic_0000002515503852_p714619015395"></a><span id="en-us_topic_0000002515503852_text111462014399"><a name="en-us_topic_0000002515503852_text111462014399"></a><a name="en-us_topic_0000002515503852_text111462014399"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1314610043913"><a name="en-us_topic_0000002515503852_p1314610043913"></a><a name="en-us_topic_0000002515503852_p1314610043913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p8602483913"><a name="en-us_topic_0000002515503852_p8602483913"></a><a name="en-us_topic_0000002515503852_p8602483913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11635413398"><a name="en-us_topic_0000002515503852_p11635413398"></a><a name="en-us_topic_0000002515503852_p11635413398"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row31464013910"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p5146120153917"><a name="en-us_topic_0000002515503852_p5146120153917"></a><a name="en-us_topic_0000002515503852_p5146120153917"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section537048144314"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
DCMI_PRBS_OPERATE_PARAM operate_para = {0};
operate_para.main_cmd = DSMI_SERDES_CMD_PRBS;
operate_para.sub_cmd = SERDES_PRBS_SET_CMD;
operate_para.operate_para.set_param.param_base = {0, 0, 1};
operate_para.operate_para.set_param.serdes_prbs_type = SERDES_PRBS_TYPE_7;
operate_para.operate_para.set_param.serdes_prbs_direction = SERDES_PRBS_DIRECTION_TXRX;
DCMI_PRBS_OPERATE_RESULT operate_result;
ret = dcmi_prbs_operate(card_id, device_id, operate_para, &operate_result);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```
