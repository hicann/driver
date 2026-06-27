# dcmi\_prbs\_operate<a name="EN-US_TOPIC_0000002546910391"></a>

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
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p14505788439"><a name="p14505788439"></a><a name="p14505788439"></a>Device ID. The supported IDs can be obtained by calling <strong id="b90589455481843"><a name="b90589455481843"></a><a name="b90589455481843"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row105051780432"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2505581438"><a name="p2505581438"></a><a name="p2505581438"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.2 "><p id="p6505198134310"><a name="p6505198134310"></a><a name="p6505198134310"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.220000000000002%" headers="mcps1.1.5.1.3 "><p id="p950510814437"><a name="p950510814437"></a><a name="p950510814437"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.690000000000005%" headers="mcps1.1.5.1.4 "><p id="p55058810433"><a name="p55058810433"></a><a name="p55058810433"></a>Chip ID, which can be obtained by calling <strong id="b43955168133039"><a name="b43955168133039"></a><a name="b43955168133039"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p155061289436"><a name="p155061289436"></a><a name="p155061289436"></a>NPU: [0, <strong id="b1658884411541"><a name="b1658884411541"></a><a name="b1658884411541"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
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
<p id="p1910017313185"><a name="p1910017313185"></a><a name="p1910017313185"></a>unsigned int serdes_prbs_macro_id; //  supports only macro_0 traffic sending.</p>
<p id="p181004341818"><a name="p181004341818"></a><a name="p181004341818"></a>unsigned int serdes_prbs_start_lane_id;// Start ID of a lane. The value ranges from 0 to 3.</p>
<p id="p111006311183"><a name="p111006311183"></a><a name="p111006311183"></a>unsigned int serdes_prbs_lane_count;// Number of lanes. The value ranges from 1 to 4.</p>
<p id="p310033151818"><a name="p310033151818"></a><a name="p310033151818"></a>} DCMI_SERDES_PRBS_PARAM_BASE;</p>
<p id="p1510018391816"><a name="p1510018391816"></a><a name="p1510018391816"></a>typedef DCMI_SERDES_PRBS_PARAM_BASE DCMI_SERDES_PRBS_GET_PARAM;  // Input <strong id="b8625725175617"><a name="b8625725175617"></a><a name="b8625725175617"></a>PARAM_BASE</strong> to obtain the traffic sending result, whose type is specified by sub_cmd.</p>
<p id="p110016316188"><a name="p110016316188"></a><a name="p110016316188"></a>typedef struct dcmi_serdes_prbs_set_param {</p>
<p id="p9100173131817"><a name="p9100173131817"></a><a name="p9100173131817"></a>DCMI_SERDES_PRBS_PARAM_BASE param_base;// Basic parameters of the traffic sending settings.</p>
<p id="p161001335180"><a name="p161001335180"></a><a name="p161001335180"></a>unsigned int serdes_prbs_type;// Code type of the traffic sending. For details, see the PRBS code type enumeration.</p>
<p id="p15100734183"><a name="p15100734183"></a><a name="p15100734183"></a>unsigned int serdes_prbs_direction;// Direction of the traffic sending. For details, see the enumeration of PRBS traffic sending directions.</p>
<p id="p1210063131814"><a name="p1210063131814"></a><a name="p1210063131814"></a>} DCMI_SERDES_PRBS_SET_PARAM;</p>
<p id="p1610073161819"><a name="p1610073161819"></a><a name="p1610073161819"></a>typedef struct dcmi_prbs_operate_param {</p>
<p id="p1810063111816"><a name="p1810063111816"></a><a name="p1810063111816"></a>unsigned int main_cmd;// Traffic sending command. For details, see the enumeration of main command words.</p>
<p id="p1510017361810"><a name="p1510017361810"></a><a name="p1510017361810"></a>unsigned int sub_cmd; // Flag indicating whether the command is used to set traffic sending or query the traffic sending result.</p>
<p id="p1610015371810"><a name="p1610015371810"></a><a name="p1610015371810"></a>union {</p>
<p id="p5100335189"><a name="p5100335189"></a><a name="p5100335189"></a>DCMI_SERDES_PRBS_SET_PARAM set_param;// Set traffic sending parameters.</p>
<p id="p12100037189"><a name="p12100037189"></a><a name="p12100037189"></a>DCMI_SERDES_PRBS_GET_PARAM get_param;// Query the traffic sending result.</p>
<p id="p0100133171811"><a name="p0100133171811"></a><a name="p0100133171811"></a>} operate_para;</p>
<p id="p18100103121813"><a name="p18100103121813"></a><a name="p18100103121813"></a>} DCMI_PRBS_OPERATE_PARAM;</p>
<p id="p195049239555"><a name="p195049239555"></a><a name="p195049239555"></a>// Enumeration of main command words</p>
<p id="p155041623115511"><a name="p155041623115511"></a><a name="p155041623115511"></a>enum dcmi_prbs_main_cmd_list {</p>
<p id="p850402375512"><a name="p850402375512"></a><a name="p850402375512"></a>DSMI_SERDES_CMD_PRBS = 0,// Command for traffic sending</p>
<p id="p350432375520"><a name="p350432375520"></a><a name="p350432375520"></a>DSMI_SERDES_CMD_MAX</p>
<p id="p155044232552"><a name="p155044232552"></a><a name="p155044232552"></a>};</p>
<p id="p15504172316553"><a name="p15504172316553"></a><a name="p15504172316553"></a>// Subcommand word enumeration</p>
<p id="p115051623165515"><a name="p115051623165515"></a><a name="p115051623165515"></a>enum dcmi_prbs_sub_cmd_list {</p>
<p id="p1250592345518"><a name="p1250592345518"></a><a name="p1250592345518"></a>SERDES_PRBS_SET_CMD = 0,// Set the subcommand for traffic sending.</p>
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
<p id="p32933992112"><a name="p32933992112"></a><a name="p32933992112"></a>SERDES_PRBS_STATUS_S result[MAX_LANE_NUM];// Returned result of traffic sending</p>
<p id="p329311913218"><a name="p329311913218"></a><a name="p329311913218"></a>DCMI_SERDES_PRBS_LANE_STATUS lane_status[MAX_LANE_NUM];// Lane status</p>
<p id="p9294159182117"><a name="p9294159182117"></a><a name="p9294159182117"></a>} prbs_result;</p>
<p id="p529416942111"><a name="p529416942111"></a><a name="p529416942111"></a>} DCMI_PRBS_OPERATE_RESULT;</p>
<p id="p6766454154411"><a name="p6766454154411"></a><a name="p6766454154411"></a>struct dcmi_serdes_prbs_lane_status {</p>
<p id="p676675414449"><a name="p676675414449"></a><a name="p676675414449"></a>unsigned int lane_prbs_tx_status;// Code type of the traffic sending in the TX direction</p>
<p id="p87661054174413"><a name="p87661054174413"></a><a name="p87661054174413"></a>unsigned int lane_prbs_rx_status;// Code type of the traffic sending in the RX direction</p>
<p id="p8766195410445"><a name="p8766195410445"></a><a name="p8766195410445"></a>};</p>
<p id="p197666547445"><a name="p197666547445"></a><a name="p197666547445"></a>typedef struct {</p>
<p id="p37669545447"><a name="p37669545447"></a><a name="p37669545447"></a>unsigned int check_en;// Query whether traffic sending is enabled.</p>
<p id="p6766155434417"><a name="p6766155434417"></a><a name="p6766155434417"></a>unsigned int check_type;// Query the traffic sending code type.</p>
<p id="p1576613547449"><a name="p1576613547449"></a><a name="p1576613547449"></a>unsigned int error_status;// Query the traffic sending status.</p>
<p id="p167667547444"><a name="p167667547444"></a><a name="p167667547444"></a>unsigned int error_cnt;// Number of error code types</p>
<p id="p12766135417441"><a name="p12766135417441"></a><a name="p12766135417441"></a>unsigned long error_rate; // Reciprocal of the traffic sending error rate (1/error_rate), which should be less than 10<sup id="sup83461731968"><a name="sup83461731968"></a><a name="sup83461731968"></a>-5</sup>.</p>
<p id="p18766454114416"><a name="p18766454114416"></a><a name="p18766454114416"></a>unsigned int alos_status; // Amplitude of the input signal. The value <strong id="b1978184016620"><a name="b1978184016620"></a><a name="b1978184016620"></a>0</strong> indicates normal, and the value <strong id="b11978840161"><a name="b11978840161"></a><a name="b11978840161"></a>1</strong> indicates low.</p>
<p id="p87662054174420"><a name="p87662054174420"></a><a name="p87662054174420"></a>unsigned long time_val;// Set the interval between sending traffic and querying the traffic sending result.</p>
<p id="p167661554164418"><a name="p167661554164418"></a><a name="p167661554164418"></a>} SERDES_PRBS_STATUS_S;</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section3642631135017"></a>**

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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b84159644272259"><a name="b84159644272259"></a><a name="b84159644272259"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None

**Restrictions<a name="section163575864318"></a>**

- Stop all running services before traffic sending.
- This API can be used in the PM + privileged container scenario.
- After the driver package is installed or the NPU is reset, you need to wait for 120s before performing traffic sending.
- In the case of two-end traffic sending, traffic sending in the TX and RX directions cannot be enabled at the same end \(for example, if traffic sending in the TX direction is enabled on one end, traffic sending in the RX direction must be enabled on the other end\).
- Traffic sending will cause the NPU network port to go down, due to which a BMC alarm will be generated. The network port cannot be brought up if traffic sending is not disabled.
- Traffic sending supports only optical module loopback \(which requires that optical modules have the loopback capability\), CDR loopback, and direct connection of NPUs using optical fibers.

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row2051415544912"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p20514155144920"><a name="en-us_topic_0000002515350556_p20514155144920"></a><a name="en-us_topic_0000002515350556_p20514155144920"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p10514165204915"><a name="en-us_topic_0000002515350556_p10514165204915"></a><a name="en-us_topic_0000002515350556_p10514165204915"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p4514956491"><a name="en-us_topic_0000002515350556_p4514956491"></a><a name="en-us_topic_0000002515350556_p4514956491"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row145145524918"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p85141551498"><a name="en-us_topic_0000002515350556_p85141551498"></a><a name="en-us_topic_0000002515350556_p85141551498"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p10514185134916"><a name="en-us_topic_0000002515350556_p10514185134916"></a><a name="en-us_topic_0000002515350556_p10514185134916"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p7514656494"><a name="en-us_topic_0000002515350556_p7514656494"></a><a name="en-us_topic_0000002515350556_p7514656494"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row135148510490"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p11514155490"><a name="en-us_topic_0000002515350556_p11514155490"></a><a name="en-us_topic_0000002515350556_p11514155490"></a><span id="en-us_topic_0000002515350556_text551465114917"><a name="en-us_topic_0000002515350556_text551465114917"></a><a name="en-us_topic_0000002515350556_text551465114917"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p185143564913"><a name="en-us_topic_0000002515350556_p185143564913"></a><a name="en-us_topic_0000002515350556_p185143564913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p185145519497"><a name="en-us_topic_0000002515350556_p185145519497"></a><a name="en-us_topic_0000002515350556_p185145519497"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1751413513498"><a name="en-us_topic_0000002515350556_p1751413513498"></a><a name="en-us_topic_0000002515350556_p1751413513498"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row135141553491"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1351411524913"><a name="en-us_topic_0000002515350556_p1351411524913"></a><a name="en-us_topic_0000002515350556_p1351411524913"></a><span id="en-us_topic_0000002515350556_text175141751499"><a name="en-us_topic_0000002515350556_text175141751499"></a><a name="en-us_topic_0000002515350556_text175141751499"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1034521615495"><a name="en-us_topic_0000002515350556_p1034521615495"></a><a name="en-us_topic_0000002515350556_p1034521615495"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6514145154913"><a name="en-us_topic_0000002515350556_p6514145154913"></a><a name="en-us_topic_0000002515350556_p6514145154913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17514145184914"><a name="en-us_topic_0000002515350556_p17514145184914"></a><a name="en-us_topic_0000002515350556_p17514145184914"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row183721515155518"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p923812139165"><a name="en-us_topic_0000002515350556_p923812139165"></a><a name="en-us_topic_0000002515350556_p923812139165"></a><span id="en-us_topic_0000002515350556_text8238111381610"><a name="en-us_topic_0000002515350556_text8238111381610"></a><a name="en-us_topic_0000002515350556_text8238111381610"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1858019263555"><a name="en-us_topic_0000002515350556_p1858019263555"></a><a name="en-us_topic_0000002515350556_p1858019263555"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p125801926195517"><a name="en-us_topic_0000002515350556_p125801926195517"></a><a name="en-us_topic_0000002515350556_p125801926195517"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p125808265554"><a name="en-us_topic_0000002515350556_p125808265554"></a><a name="en-us_topic_0000002515350556_p125808265554"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1828812107299"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p4288010192914"><a name="en-us_topic_0000002515350556_p4288010192914"></a><a name="en-us_topic_0000002515350556_p4288010192914"></a><span id="en-us_topic_0000002515350556_text17252201592911"><a name="en-us_topic_0000002515350556_text17252201592911"></a><a name="en-us_topic_0000002515350556_text17252201592911"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p14729171810297"><a name="en-us_topic_0000002515350556_p14729171810297"></a><a name="en-us_topic_0000002515350556_p14729171810297"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p187294185296"><a name="en-us_topic_0000002515350556_p187294185296"></a><a name="en-us_topic_0000002515350556_p187294185296"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p12729918182916"><a name="en-us_topic_0000002515350556_p12729918182916"></a><a name="en-us_topic_0000002515350556_p12729918182916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row8768181557"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1563212213554"><a name="en-us_topic_0000002515350556_p1563212213554"></a><a name="en-us_topic_0000002515350556_p1563212213554"></a><span id="en-us_topic_0000002515350556_text1963217219554"><a name="en-us_topic_0000002515350556_text1963217219554"></a><a name="en-us_topic_0000002515350556_text1963217219554"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p18671727165520"><a name="en-us_topic_0000002515350556_p18671727165520"></a><a name="en-us_topic_0000002515350556_p18671727165520"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p967152775514"><a name="en-us_topic_0000002515350556_p967152775514"></a><a name="en-us_topic_0000002515350556_p967152775514"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p667192712555"><a name="en-us_topic_0000002515350556_p667192712555"></a><a name="en-us_topic_0000002515350556_p667192712555"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row207580351817"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1339643920818"><a name="en-us_topic_0000002515350556_p1339643920818"></a><a name="en-us_topic_0000002515350556_p1339643920818"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
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
    // todo: Record logs.
    return ret;
}
...
```
