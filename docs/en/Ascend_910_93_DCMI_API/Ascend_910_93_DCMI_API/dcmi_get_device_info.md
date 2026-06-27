# dcmi\_get\_device\_info<a name="EN-US_TOPIC_0000002515510536"></a>

**Prototype<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412077"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412078"></a>**

Obtains device information and the status of each module.

**Parameter Description<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412079"></a>**

<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p10021890"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p10021890"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p6466753"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p6466753"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.96%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p54045009"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p54045009"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15569626"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15569626"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p36741947142813"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p36741947142813"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p96741747122818"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p96741747122818"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p46747472287"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p46747472287"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1467413474281"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1467413474281"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b8724575883301"><a name="b8724575883301"></a><a name="b8724575883301"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b54986775832940"><a name="b54986775832940"></a><a name="b54986775832940"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b6110874955953"><a name="b6110874955953"></a><a name="b6110874955953"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"></a>Main command word corresponding to the specified query item.</p>
<p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p37001865558"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p37001865558"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p37001865558"></a>CMD information, which is used to obtain the information about the corresponding module.</p>
<p id="p15764525481"><a name="p15764525481"></a><a name="p15764525481"></a>enum dcmi_main_cmd {</p>
<p id="p61731150986"><a name="p61731150986"></a><a name="p61731150986"></a>DCMI_MAIN_CMD_DVPP = 0,</p>
<p id="p14418615117"><a name="p14418615117"></a><a name="p14418615117"></a>DCMI_MAIN_CMD_ISP,</p>
<p id="p1312911171213"><a name="p1312911171213"></a><a name="p1312911171213"></a>DCMI_MAIN_CMD_TS_GROUP_NUM,</p>
<p id="p1591117521484"><a name="p1591117521484"></a><a name="p1591117521484"></a>DCMI_MAIN_CMD_CAN,</p>
<p id="p76221333125"><a name="p76221333125"></a><a name="p76221333125"></a>DCMI_MAIN_CMD_UART,</p>
<p id="p1492915181210"><a name="p1492915181210"></a><a name="p1492915181210"></a>DCMI_MAIN_CMD_UPGRADE = 5,</p>
<p id="p157832073125"><a name="p157832073125"></a><a name="p157832073125"></a>DCMI_MAIN_CMD_UFS,</p>
<p id="p132481911217"><a name="p132481911217"></a><a name="p132481911217"></a>DCMI_MAIN_CMD_OS_POWER,</p>
<p id="p11495571288"><a name="p11495571288"></a><a name="p11495571288"></a>DCMI_MAIN_CMD_LP,</p>
<p id="p1610001115121"><a name="p1610001115121"></a><a name="p1610001115121"></a>DCMI_MAIN_CMD_MEMORY,</p>
<p id="p186982123123"><a name="p186982123123"></a><a name="p186982123123"></a>DCMI_MAIN_CMD_RECOVERY,</p>
<p id="p3457195910816"><a name="p3457195910816"></a><a name="p3457195910816"></a>DCMI_MAIN_CMD_TS,</p>
<p id="p9823111501212"><a name="p9823111501212"></a><a name="p9823111501212"></a>DCMI_MAIN_CMD_CHIP_INF,</p>
<p id="p667381711214"><a name="p667381711214"></a><a name="p667381711214"></a>DCMI_MAIN_CMD_QOS,</p>
<p id="p1219517209126"><a name="p1219517209126"></a><a name="p1219517209126"></a>DCMI_MAIN_CMD_SOC_INFO,</p>
<p id="p532617119912"><a name="p532617119912"></a><a name="p532617119912"></a>DCMI_MAIN_CMD_SILS,</p>
<p id="p41674228121"><a name="p41674228121"></a><a name="p41674228121"></a>DCMI_MAIN_CMD_HCCS,</p>
<p id="p0713162516122"><a name="p0713162516122"></a><a name="p0713162516122"></a>DCMI_MAIN_CMD_HOST_AICPU,</p>
<p id="p8688112731212"><a name="p8688112731212"></a><a name="p8688112731212"></a>DCMI_MAIN_CMD_TEMP = 50,</p>
<p id="p05801129181214"><a name="p05801129181214"></a><a name="p05801129181214"></a>DCMI_MAIN_CMD_SVM,</p>
<p id="p1453863211214"><a name="p1453863211214"></a><a name="p1453863211214"></a>DCMI_MAIN_CMD_VDEV_MNG,</p>
<p id="p7623193451211"><a name="p7623193451211"></a><a name="p7623193451211"></a>DCMI_MAIN_CMD_SEC,</p>
<p id="p194422345516"><a name="p194422345516"></a><a name="p194422345516"></a>DCMI_MAIN_CMD_PCIE = 55,</p>
<p id="p1896837121219"><a name="p1896837121219"></a><a name="p1896837121219"></a>DCMI_MAIN_CMD_SIO = 56,</p>
<p id="p18590722192310"><a name="p18590722192310"></a><a name="p18590722192310"></a>DCMI_MAIN_CMD_EX_COMPUTING = 0x8000,    DCMI_MAIN_CMD_DEVICE_SHARE = 0x8001,</p>
<p id="p1032616302563"><a name="p1032616302563"></a><a name="p1032616302563"></a>DCMI_MAIN_CMD_EX_CERT = 0x8003,</p>
<p id="p692433982"><a name="p692433982"></a><a name="p692433982"></a>DCMI_MAIN_CMD_MAX</p>
<p id="p223161612813"><a name="p223161612813"></a><a name="p223161612813"></a>};</p>
<p id="p9932195894319"><a name="p9932195894319"></a><a name="p9932195894319"></a>Only the main command words of the following modules are supported:</p>
<p id="p1028842114915"><a name="p1028842114915"></a><a name="p1028842114915"></a>DCMI_MAIN_CMD_DVPP // Main command word of the DVPP operator module</p>
<p id="p889911226920"><a name="p889911226920"></a><a name="p889911226920"></a>DCMI_MAIN_CMD_LP // Main command word of the low power module</p>
<p id="p630816245918"><a name="p630816245918"></a><a name="p630816245918"></a>DCMI_MAIN_CMD_TS // Main command word of the task scheduling module</p>
<p id="p77158266913"><a name="p77158266913"></a><a name="p77158266913"></a>DCMI_MAIN_CMD_QOS // Main command word of the QoS module</p>
<p id="p1072315596121"><a name="p1072315596121"></a><a name="p1072315596121"></a>DCMI_MAIN_CMD_HCCS // Main command word of the HCCS module</p>
<p id="p1334062061315"><a name="p1334062061315"></a><a name="p1334062061315"></a>DCMI_MAIN_CMD_EX_COMPUTING // Main command word of the compute expansion module</p>
<p id="p121340251314"><a name="p121340251314"></a><a name="p121340251314"></a>DCMI_MAIN_CMD_VDEV_MNG // Main command word of the <span id="ph11173195663615"><a name="ph11173195663615"></a><a name="ph11173195663615"></a>Ascend Virtual Instance (AVI) module</span></p>
<p id="p193245812437"><a name="p193245812437"></a><a name="p193245812437"></a>DCMI_MAIN_CMD_CHIP_INF // Query the SuperPoD information.</p>
<p id="p15875609615"><a name="p15875609615"></a><a name="p15875609615"></a>DCMI_MAIN_CMD_SIO // Query the SIO status between Dies.</p>
<p id="p123541463434"><a name="p123541463434"></a><a name="p123541463434"></a>DCMI_MAIN_CMD_PCIE // Obtain PCIe information.</p>
<p id="p12452171290"><a name="p12452171290"></a><a name="p12452171290"></a>DCMI_MAIN_CMD_SOC_INFO // Obtain SoC information.</p>
<p id="p2029414595275"><a name="p2029414595275"></a><a name="p2029414595275"></a>DCMI_MAIN_CMD_DEVICE_SHARE // Main command word for container sharing</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row118352016305"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p19161539205"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p19161539205"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p19161539205"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1816115315209"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1816115315209"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1816115315209"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1216853142018"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1216853142018"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1216853142018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p75475304476"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p75475304476"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p75475304476"></a>For details, see the function description in the subsections.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row148973243016"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8864185062018"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8864185062018"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8864185062018"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p886417500202"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p886417500202"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p886417500202"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1386445092020"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1386445092020"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1386445092020"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15864145012200"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15864145012200"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p15864145012200"></a>Input/Output buffer.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row20221172313016"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7749184816202"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7749184816202"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7749184816202"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p0749104811207"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p0749104811207"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p0749104811207"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1374944862018"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1374944862018"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1374944862018"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p074915488209"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p074915488209"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p074915488209"></a>Input/Output length of the <strong id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_b1610715481949"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_b1610715481949"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_b1610715481949"></a>buf</strong> array.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b4328010137222"><a name="b4328010137222"></a><a name="b4328010137222"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int buf = 0;
unsigned int size = sizeof(int);
unsigned int sub_cmd = 0;
ret = dcmi_get_device_info(card_id, device_id, DCMI_MAIN_CMD_DVPP, sub_cmd, &buf, &size);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_DVPP Command<a name="EN-US_TOPIC_0000002515510422"></a>

**Prototype<a name="section1045115919305"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section184521595304"></a>**

Obtains DVPP status and configuration.

**Parameter Description<a name="section104533963015"></a>**

<a name="table104768953018"></a>
<table><thead align="left"><tr id="row19544594301"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p115440913011"><a name="p115440913011"></a><a name="p115440913011"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p754417916309"><a name="p754417916309"></a><a name="p754417916309"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="23.232323232323232%" id="mcps1.1.5.1.3"><p id="p135449903012"><a name="p135449903012"></a><a name="p135449903012"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="44.44444444444445%" id="mcps1.1.5.1.4"><p id="p254412913309"><a name="p254412913309"></a><a name="p254412913309"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row55442993013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p12544109113015"><a name="p12544109113015"></a><a name="p12544109113015"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185448903012"><a name="p185448903012"></a><a name="p185448903012"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p195441497307"><a name="p195441497307"></a><a name="p195441497307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p105445933016"><a name="p105445933016"></a><a name="p105445933016"></a>Device ID. The supported IDs can be obtained by calling <strong id="b12341571493303"><a name="b12341571493303"></a><a name="b12341571493303"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1544592304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p195445917304"><a name="p195445917304"></a><a name="p195445917304"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185446910306"><a name="p185446910306"></a><a name="p185446910306"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p175441294306"><a name="p175441294306"></a><a name="p175441294306"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p1854417933011"><a name="p1854417933011"></a><a name="p1854417933011"></a>Chip ID, which can be obtained by calling <strong id="b120184079832941"><a name="b120184079832941"></a><a name="b120184079832941"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p1054449203011"><a name="p1054449203011"></a><a name="p1054449203011"></a>NPU: [0, <strong id="b14831142238629"><a name="b14831142238629"></a><a name="b14831142238629"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row35441953014"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1254413913016"><a name="p1254413913016"></a><a name="p1254413913016"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p154509173018"><a name="p154509173018"></a><a name="p154509173018"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p135451198309"><a name="p135451198309"></a><a name="p135451198309"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p165456953016"><a name="p165456953016"></a><a name="p165456953016"></a>DCMI_MAIN_CMD_DVPP</p>
</td>
</tr>
<tr id="row754518963011"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p85451396307"><a name="p85451396307"></a><a name="p85451396307"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1654518910302"><a name="p1654518910302"></a><a name="p1654518910302"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p354519916301"><a name="p354519916301"></a><a name="p354519916301"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p135451197302"><a name="p135451197302"></a><a name="p135451197302"></a>Sub-command information, which is used to obtain the sub-attribute information of each module.</p>
<p id="p1154589163019"><a name="p1154589163019"></a><a name="p1154589163019"></a>/* DCMI sub command for DVPP module */</p>
<p id="p145452913308"><a name="p145452913308"></a><a name="p145452913308"></a>#define DCMI_SUB_CMD_DVPP_STATUS 0  // DVPP status. If the value of <strong id="b6775172913529"><a name="b6775172913529"></a><a name="b6775172913529"></a>buf</strong> is <strong id="b137752295523"><a name="b137752295523"></a><a name="b137752295523"></a>0</strong>, the status is normal. Otherwise, the status is abnormal.</p>
<p id="p17545699303"><a name="p17545699303"></a><a name="p17545699303"></a>#define DCMI_SUB_CMD_DVPP_VDEC_RATE 1  // VDEC utilization. The normal value ranges from 0 to 100.</p>
<p id="p0545119193019"><a name="p0545119193019"></a><a name="p0545119193019"></a>#define DCMI_SUB_CMD_DVPP_VPC_RATE 2 // VPC utilization. The normal value ranges from 0 to 100.</p>
<p id="p13545397302"><a name="p13545397302"></a><a name="p13545397302"></a>#define DCMI_SUB_CMD_DVPP_VENC_RATE 3 // VENC utilization. The normal value ranges from 0 to 100.</p>
<p id="p154509103011"><a name="p154509103011"></a><a name="p154509103011"></a>#define DCMI_SUB_CMD_DVPP_JPEGE_RATE 4 // JPEGE utilization. The normal value ranges from 0 to 100.</p>
<p id="p1054579163010"><a name="p1054579163010"></a><a name="p1054579163010"></a>#define DCMI_SUB_CMD_DVPP_JPEGD_RATE 5 // JPEGD utilization. The normal value ranges from 0 to 100.</p>
<p id="p1754517943015"><a name="p1754517943015"></a><a name="p1754517943015"></a>Currently, the <strong id="b9757728448629"><a name="b9757728448629"></a><a name="b9757728448629"></a>DCMI_SUB_CMD_DVPP_VENC_RATE</strong> command cannot be used for query.</p>
</td>
</tr>
<tr id="row1954515903016"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p155455915303"><a name="p155455915303"></a><a name="p155455915303"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p554510903013"><a name="p554510903013"></a><a name="p554510903013"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p19545129143015"><a name="p19545129143015"></a><a name="p19545129143015"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p185454953015"><a name="p185454953015"></a><a name="p185454953015"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row2054549113013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p25451983018"><a name="p25451983018"></a><a name="p25451983018"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p12545169113011"><a name="p12545169113011"></a><a name="p12545169113011"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p1754515943013"><a name="p1754515943013"></a><a name="p1754515943013"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p2054559153019"><a name="p2054559153019"></a><a name="p2054559153019"></a>Length of the <strong id="b18651916498629"><a name="b18651916498629"></a><a name="b18651916498629"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section104687916306"></a>**

<a name="table34861192309"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b1491372167223"><a name="b1491372167223"></a><a name="b1491372167223"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section8924415552"></a>**

None

**Restrictions<a name="section20247271550"></a>**

To obtain the DVPP device settings,  **sub\_cmd**,  **buf**, and  **size**  must meet the following requirements. Failure to do so may impact API calls.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table34881973017"></a>
<table><thead align="left"><tr id="row654609173016"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p654609173010"><a name="p654609173010"></a><a name="p654609173010"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.2"><p id="p1254617983019"><a name="p1254617983019"></a><a name="p1254617983019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.3"><p id="p2054620963017"><a name="p2054620963017"></a><a name="p2054620963017"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row1954613919308"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p45462912305"><a name="p45462912305"></a><a name="p45462912305"></a>DCMI_SUB_CMD_DVPP_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.2 "><p id="p1554659163015"><a name="p1554659163015"></a><a name="p1554659163015"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.3 "><p id="p354616913304"><a name="p354616913304"></a><a name="p354616913304"></a>Length: sizeof(unsigned int)</p>
</td>
</tr>
<tr id="row2054611914303"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1754613917303"><a name="p1754613917303"></a><a name="p1754613917303"></a>DCMI_SUB_CMD_DVPP_VDEC_RATE</p>
<p id="p954615953017"><a name="p954615953017"></a><a name="p954615953017"></a>DCMI_SUB_CMD_DVPP_VPC_RATE</p>
<p id="p754649173014"><a name="p754649173014"></a><a name="p754649173014"></a>DCMI_SUB_CMD_DVPP_VENC_RATE</p>
<p id="p15462094304"><a name="p15462094304"></a><a name="p15462094304"></a>DCMI_SUB_CMD_DVPP_JPEGE_RATE</p>
<p id="p85468914304"><a name="p85468914304"></a><a name="p85468914304"></a>DCMI_SUB_CMD_DVPP_JPEGD_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.2 "><p id="p135461398309"><a name="p135461398309"></a><a name="p135461398309"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.3 "><p id="p1254699103018"><a name="p1254699103018"></a><a name="p1254699103018"></a>Length: sizeof(unsigned int)</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section2133155511568"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int ratio = 0;
int sub_cmd = 0;
unsigned int ratio_size = sizeof(int);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_DVPP, sub_cmd, (void *)&ratio, &ratio_size);
if (ret != 0) {
    // todo
    return ret;
} else {
    // todo
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_LP Command<a name="EN-US_TOPIC_0000002546910425"></a>

**Prototype<a name="section158495435301"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section7850154317304"></a>**

Obtains LP information in the system, such as the voltage and current register values of the AI Core, Hybrid, CPU, and DDR.

**Parameter Description<a name="section28501043183017"></a>**

<a name="table15882143133020"></a>
<table><thead align="left"><tr id="row11974164343015"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p797519436303"><a name="p797519436303"></a><a name="p797519436303"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p697512439305"><a name="p697512439305"></a><a name="p697512439305"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p19975543163019"><a name="p19975543163019"></a><a name="p19975543163019"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p15975184353016"><a name="p15975184353016"></a><a name="p15975184353016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row159751431302"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p497524313301"><a name="p497524313301"></a><a name="p497524313301"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1397564318309"><a name="p1397564318309"></a><a name="p1397564318309"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1697510439301"><a name="p1697510439301"></a><a name="p1697510439301"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p15975114317309"><a name="p15975114317309"></a><a name="p15975114317309"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1366482420224"><a name="b1366482420224"></a><a name="b1366482420224"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row109751843163011"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p39751943113018"><a name="p39751943113018"></a><a name="p39751943113018"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p2975124363011"><a name="p2975124363011"></a><a name="p2975124363011"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p997554315307"><a name="p997554315307"></a><a name="p997554315307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p49753435303"><a name="p49753435303"></a><a name="p49753435303"></a>Chip ID, which can be obtained by calling <strong id="b130153769932942"><a name="b130153769932942"></a><a name="b130153769932942"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p69753439303"><a name="p69753439303"></a><a name="p69753439303"></a>NPU: [0, <strong id="b12414203238723"><a name="b12414203238723"></a><a name="b12414203238723"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row12975443183013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1097534333012"><a name="p1097534333012"></a><a name="p1097534333012"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19975124303012"><a name="p19975124303012"></a><a name="p19975124303012"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p2975184311304"><a name="p2975184311304"></a><a name="p2975184311304"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p9975194310307"><a name="p9975194310307"></a><a name="p9975194310307"></a>DCMI_MAIN_CMD_LP</p>
</td>
</tr>
<tr id="row2975194333013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1497534343010"><a name="p1497534343010"></a><a name="p1497534343010"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p597594314306"><a name="p597594314306"></a><a name="p597594314306"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6975743153011"><a name="p6975743153011"></a><a name="p6975743153011"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18975343113017"><a name="p18975343113017"></a><a name="p18975343113017"></a>/* DCMI sub commond for Low power */</p>
<pre class="codeblock" id="codeblock971395520334"><a name="codeblock971395520334"></a><a name="codeblock971395520334"></a>typedef enum {
// Obtain the register values indicating the voltage and current of the AI Core.
DCMI_LP_SUB_CMD_AICORE_VOLTAGE_CURRENT = 0,
// Obtain the register values indicating the voltage and current of the Hybird.
DCMI_LP_SUB_CMD_HYBIRD_VOLTAGE_CURRENT,
// Obtain the register values indicating the voltage and current of the CPU.
DCMI_LP_SUB_CMD_TAISHAN_VOLTAGE_CURRENT,
// Obtain the register values indicating the voltage and current of the DDR.
DCMI_LP_SUB_CMD_DDR_VOLTAGE_CURRENT,
// Obtain the count of ACG frequency modulations.
DCMI_LP_SUB_CMD_ACG,
// Obtain the overall low-power status.
DCMI_LP_SUB_CMD_STATUS,
// Obtain all working levels.
DCMI_LP_SUB_CMD_TOPS_DETAILS,
// Set the working level.
DCMI_LP_SUB_CMD_SET_WORK_TOPS,
// Obtain the current working level.
DCMI_LP_SUB_CMD_GET_WORK_TOPS,
// Retrieve the cause of the current frequency reduction.
DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE,
// Obtain the power consumption information.
DCMI_LP_SUB_CMD_GET_POWER_INFO,
// Set the idle mode switch.
DCMI_LP_SUB_CMD_SET_IDLE_SWITCH,
DCMI_LP_SUB_CMD_MAX,
} DCMI_LP_SUB_CMD;</pre>
<p id="p0976643203017"><a name="p0976643203017"></a><a name="p0976643203017"></a><strong id="b731682217014"><a name="b731682217014"></a><a name="b731682217014"></a>DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE</strong>, <strong id="b153171622207"><a name="b153171622207"></a><a name="b153171622207"></a>DCMI_LP_SUB_CMD_GET_POWER_INFO</strong>, and <strong id="b1131719221904"><a name="b1131719221904"></a><a name="b1131719221904"></a>DCMI_LP_SUB_CMD_STATUS</strong> commands are supported.</p>
</td>
</tr>
<tr id="row119761843173017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p0976184343012"><a name="p0976184343012"></a><a name="p0976184343012"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p397614363010"><a name="p397614363010"></a><a name="p397614363010"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p29762043173012"><a name="p29762043173012"></a><a name="p29762043173012"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p179761943143013"><a name="p179761943143013"></a><a name="p179761943143013"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row6976543103019"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p119765433306"><a name="p119765433306"></a><a name="p119765433306"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p79761543173017"><a name="p79761543173017"></a><a name="p79761543173017"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1976204317307"><a name="p1976204317307"></a><a name="p1976204317307"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p2976943123017"><a name="p2976943123017"></a><a name="p2976943123017"></a>Length of the <strong id="b198641439905"><a name="b198641439905"></a><a name="b198641439905"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section386564317309"></a>**

<a name="table1689294312308"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b5722147057225"><a name="b5722147057225"></a><a name="b5722147057225"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section581311341081"></a>**

None

**Restrictions<a name="section216210381817"></a>**

- Length of the  **buf**  array/Length of the returned result.
- The reason of AI Core frequency reduction is updated every 100 ms, and historical frequency reduction reasons cannot be queried.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table9893154314306"></a>
<table><thead align="left"><tr id="row1097794373014"><th class="cellrowborder" valign="top" width="32.629999999999995%" id="mcps1.2.5.1.1"><p id="p597724343018"><a name="p597724343018"></a><a name="p597724343018"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="23.200000000000003%" id="mcps1.2.5.1.2"><p id="p15977743113017"><a name="p15977743113017"></a><a name="p15977743113017"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.6%" id="mcps1.2.5.1.3"><p id="p1977104363011"><a name="p1977104363011"></a><a name="p1977104363011"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25.569999999999997%" id="mcps1.2.5.1.4"><p id="p1097718435302"><a name="p1097718435302"></a><a name="p1097718435302"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row497744313309"><td class="cellrowborder" valign="top" width="32.629999999999995%" headers="mcps1.2.5.1.1 "><p id="p1897794353018"><a name="p1897794353018"></a><a name="p1897794353018"></a>DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE</p>
</td>
<td class="cellrowborder" valign="top" width="23.200000000000003%" headers="mcps1.2.5.1.2 "><p id="p159771243123013"><a name="p159771243123013"></a><a name="p159771243123013"></a>Unsigned long long</p>
</td>
<td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.2.5.1.3 "><p id="p15977204323010"><a name="p15977204323010"></a><a name="p15977204323010"></a>sizeof(unsigned long long)</p>
</td>
<td class="cellrowborder" valign="top" width="25.569999999999997%" headers="mcps1.2.5.1.4 "><p id="p197784315304"><a name="p197784315304"></a><a name="p197784315304"></a><strong id="b146209472251"><a name="b146209472251"></a><a name="b146209472251"></a>buf</strong> is an 8-byte memory space. Each bit corresponds to a frequency reduction cause.</p>
</td>
</tr>
<tr id="row697713436302"><td class="cellrowborder" valign="top" width="32.629999999999995%" headers="mcps1.2.5.1.1 "><p id="p1797774310308"><a name="p1797774310308"></a><a name="p1797774310308"></a>DCMI_LP_SUB_CMD_GET_POWER_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="23.200000000000003%" headers="mcps1.2.5.1.2 "><p id="p1977043163011"><a name="p1977043163011"></a><a name="p1977043163011"></a>DCMI_LP_POWER_INFO_STRU</p>
</td>
<td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.2.5.1.3 "><p id="p6977144314302"><a name="p6977144314302"></a><a name="p6977144314302"></a>sizeof(DCMI_LP_POWER_INFO_STRU)</p>
</td>
<td class="cellrowborder" valign="top" width="25.569999999999997%" headers="mcps1.2.5.1.4 "><p id="p397764343016"><a name="p397764343016"></a><a name="p397764343016"></a>#define DCMI_LP_POWER_RESERVED_LEN 32</p>
<p id="p12977124373012"><a name="p12977124373012"></a><a name="p12977124373012"></a>typedef struct DCMI_lp_power_info {</p>
<p id="p1697714323019"><a name="p1697714323019"></a><a name="p1697714323019"></a>unsigned int soc_rated_power;</p>
<p id="p797713439301"><a name="p797713439301"></a><a name="p797713439301"></a>unsigned char reserved[DCMI_LP_POWER_RESERVED_LEN];</p>
<p id="p197774318301"><a name="p197774318301"></a><a name="p197774318301"></a>} DCMI_LP_POWER_INFO_STRU;</p>
<p id="p1197794310304"><a name="p1197794310304"></a><a name="p1197794310304"></a><strong id="b6851883058723"><a name="b6851883058723"></a><a name="b6851883058723"></a>soc_rated_power</strong> indicates the rated power of the SoC, and other values are reserved for expansion.</p>
<p id="p7977184393012"><a name="p7977184393012"></a><a name="p7977184393012"></a>Correct range of the SoC rated power: [150000, 600000]</p>
</td>
</tr>
<tr id="row4977124333016"><td class="cellrowborder" valign="top" width="32.629999999999995%" headers="mcps1.2.5.1.1 "><p id="p12977743173013"><a name="p12977743173013"></a><a name="p12977743173013"></a>DCMI_LP_SUB_CMD_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="23.200000000000003%" headers="mcps1.2.5.1.2 "><p id="p597754320305"><a name="p597754320305"></a><a name="p597754320305"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.2.5.1.3 "><p id="p097724315305"><a name="p097724315305"></a><a name="p097724315305"></a>sizeof(unsigned int)</p>
</td>
<td class="cellrowborder" valign="top" width="25.569999999999997%" headers="mcps1.2.5.1.4 "><p id="p16977243183018"><a name="p16977243183018"></a><a name="p16977243183018"></a><strong id="b2818985458723"><a name="b2818985458723"></a><a name="b2818985458723"></a>0</strong>: non-idle; <strong id="b9526010988723"><a name="b9526010988723"></a><a name="b9526010988723"></a>1</strong>: idle</p>
</td>
</tr>
</tbody>
</table>

In the subcommand  **DCMI\_LP\_SUB\_CMD\_AICORE\_FREQREDUC\_CAUSE**, the reason of AI Core frequency reduction is represented by a 64-bit value. Each bit corresponds to a frequency reduction cause. If the value is 0, the AI Core runs at a rated frequency. If the value is 1, the AI Core cannot run at a rated frequency. Frequency reduction may be caused by multiple factors. Therefore, multiple bits may be set to 1.

**Table  2**  Meaning of each bit in the buffer value

<a name="table188972043193011"></a>
<table><thead align="left"><tr id="row8977543133019"><th class="cellrowborder" valign="top" width="25.27%" id="mcps1.2.4.1.1"><p id="p7978843103017"><a name="p7978843103017"></a><a name="p7978843103017"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.27%" id="mcps1.2.4.1.2"><p id="p59781843103015"><a name="p59781843103015"></a><a name="p59781843103015"></a>Bit</p>
</th>
<th class="cellrowborder" valign="top" width="49.46%" id="mcps1.2.4.1.3"><p id="p797834319309"><a name="p797834319309"></a><a name="p797834319309"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7978143143012"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p1497834315307"><a name="p1497834315307"></a><a name="p1497834315307"></a>IDLE</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p129787433303"><a name="p129787433303"></a><a name="p129787433303"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p17978164383013"><a name="p17978164383013"></a><a name="p17978164383013"></a>The AI Core is in the idle state. The power consumption is reduced by reducing the AI Core frequency to the idle state frequency. The frequency will be switched only after the idle state lasts for a period of time.</p>
</td>
</tr>
<tr id="row397814314309"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p12978194317301"><a name="p12978194317301"></a><a name="p12978194317301"></a>THERMAL</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p16978194383019"><a name="p16978194383019"></a><a name="p16978194383019"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p897894393014"><a name="p897894393014"></a><a name="p897894393014"></a>The temperature of the Ascend AI Processor exceeds the allowed range. As a result, the lower layer software imposes a range limit on the AI Core frequency to reduce the processor temperature.</p>
</td>
</tr>
<tr id="row297804343016"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p6978124373015"><a name="p6978124373015"></a><a name="p6978124373015"></a>SW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p1097824314304"><a name="p1097824314304"></a><a name="p1097824314304"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997864373012"><a name="p997864373012"></a><a name="p997864373012"></a>On the Ascend AI Processor, the power supply current of the AI Core module exceeds the allowed range. As a result, the lower layer software imposes a range limit on the AI Core frequency to ensure stable power supply to the AI Core module.</p>
</td>
</tr>
<tr id="row1897894313010"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p1897816431303"><a name="p1897816431303"></a><a name="p1897816431303"></a>HW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p59781343123016"><a name="p59781343123016"></a><a name="p59781343123016"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p1497804343013"><a name="p1497804343013"></a><a name="p1497804343013"></a>On the Ascend AI Processor, the transient power supply current of the AI Core module exceeds the allowed range. As a result, the current sensor on the mainboard triggers a quick frequency reduction of the AI Core module.</p>
</td>
</tr>
<tr id="row119787436308"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p197813434307"><a name="p197813434307"></a><a name="p197813434307"></a>POWER_BREAK</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p4978144310304"><a name="p4978144310304"></a><a name="p4978144310304"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p597894323019"><a name="p597894323019"></a><a name="p597894323019"></a>After detecting that the power exceeds the upper limit, the power monitoring module on the mainboard instructs the Ascend AI Processor to quickly reduce the AI Core frequency to maintain stable power supply.</p>
</td>
</tr>
<tr id="row4978144318302"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p897874303013"><a name="p897874303013"></a><a name="p897874303013"></a>SVFD</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p11978134316303"><a name="p11978134316303"></a><a name="p11978134316303"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997804363012"><a name="p997804363012"></a><a name="p997804363012"></a>When the power supply monitoring module of the AI Core on the Ascend AI Processor detects that the power supply is unstable (with noises), the AI Core frequency is quickly reduced to maintain stable power supply.</p>
</td>
</tr>
<tr id="row730384616819"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001312397937_p11311634212"><a name="en-us_topic_0000001312397937_p11311634212"></a><a name="en-us_topic_0000001312397937_p11311634212"></a>POWERCAPPING</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001312397937_p169341949144114"><a name="en-us_topic_0000001312397937_p169341949144114"></a><a name="en-us_topic_0000001312397937_p169341949144114"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p13043467813"><a name="p13043467813"></a><a name="p13043467813"></a>The Ascend AI Processor performs out-of-band power consumption control through the iBMC.</p>
</td>
</tr>
<tr id="row667034813815"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001312397937_p1761405971619"><a name="en-us_topic_0000001312397937_p1761405971619"></a><a name="en-us_topic_0000001312397937_p1761405971619"></a>LOAD_AWARE</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001312397937_p161435931619"><a name="en-us_topic_0000001312397937_p161435931619"></a><a name="en-us_topic_0000001312397937_p161435931619"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p116708488813"><a name="p116708488813"></a><a name="p116708488813"></a>The Ascend AI Processor performs power consumption control by using the AI load-aware module.</p>
</td>
</tr>
</tbody>
</table>

**Table  3** Support in different deployment scenarios

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

**Example<a name="section207091751457"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int sub_cmd=0;
unsigned int voltage_cruuent_buf = 0;
unsigned int buf_size = 8;
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_LP, sub_cmd, &voltage_cruuent_buf, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_TS Command<a name="EN-US_TOPIC_0000002515350586"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section19822105710305"></a>**

Obtains TS information in the system.

**Parameter Description<a name="section188227576305"></a>**

<a name="table584175773016"></a>
<table><thead align="left"><tr id="row158991057133012"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1189945783015"><a name="p1189945783015"></a><a name="p1189945783015"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p13899165713012"><a name="p13899165713012"></a><a name="p13899165713012"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p789919571306"><a name="p789919571306"></a><a name="p789919571306"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p38991757123015"><a name="p38991757123015"></a><a name="p38991757123015"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14899115710307"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p289935717300"><a name="p289935717300"></a><a name="p289935717300"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p158990579308"><a name="p158990579308"></a><a name="p158990579308"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p890025715306"><a name="p890025715306"></a><a name="p890025715306"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1290095773011"><a name="p1290095773011"></a><a name="p1290095773011"></a>Device ID. The supported IDs can be obtained by calling <strong id="b198417431395"><a name="b198417431395"></a><a name="b198417431395"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1990019577303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p109001457133015"><a name="p109001457133015"></a><a name="p109001457133015"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1900175783013"><a name="p1900175783013"></a><a name="p1900175783013"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13900185710307"><a name="p13900185710307"></a><a name="p13900185710307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18900957193015"><a name="p18900957193015"></a><a name="p18900957193015"></a>Chip ID, which can be obtained by calling <strong id="b1079613493916"><a name="b1079613493916"></a><a name="b1079613493916"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p390015577304"><a name="p390015577304"></a><a name="p390015577304"></a>NPU: [0, <strong id="b9701421558530"><a name="b9701421558530"></a><a name="b9701421558530"></a>device_id_max</strong> – 1]</p>
<p id="p106451722987"><a name="p106451722987"></a><a name="p106451722987"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row19900125763017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p18900657173012"><a name="p18900657173012"></a><a name="p18900657173012"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p5900155783016"><a name="p5900155783016"></a><a name="p5900155783016"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p89002574308"><a name="p89002574308"></a><a name="p89002574308"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p590010578307"><a name="p590010578307"></a><a name="p590010578307"></a>DCMI_MAIN_CMD_TS</p>
</td>
</tr>
<tr id="row0900155743018"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p139001157183018"><a name="p139001157183018"></a><a name="p139001157183018"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p18900165743017"><a name="p18900165743017"></a><a name="p18900165743017"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1690018576308"><a name="p1690018576308"></a><a name="p1690018576308"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock84586272352"><a name="codeblock84586272352"></a><a name="codeblock84586272352"></a>typedef enum {
// Obtain the single-core utilization of the AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE = 0,
// Obtain the single-core utilization of the Vector Core/Obtain the utilization of the Vector unit in the single AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE,
// Obtain the FFTS or FFTS+ type. The value 0 indicates FFTS, and the value 1 indicates FFTS+.
DCMI_TS_SUB_CMD_FFTS_TYPE,
// Set the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_SET_FAULT_MASK,
// Obtain the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_GET_FAULT_MASK,
// Obtain the operator timeout scale. It defaults to <strong id="b176552631011"><a name="b176552631011"></a><a name="b176552631011"></a>32</strong>, and the value range is [20, 32].
DCMI_TS_SUB_CMD_COMMON_MSG = 11,
DCMI_TS_SUB_CMD_MAX,
} DCMI_TS_SUB_CMD;</pre>
<p id="p20900857113015"><a name="p20900857113015"></a><a name="p20900857113015"></a><strong id="b8730615748530"><a name="b8730615748530"></a><a name="b8730615748530"></a>DCMI_TS_SUB_CMD_SET_FAULT_MASK</strong> and <strong id="b12414376578530"><a name="b12414376578530"></a><a name="b12414376578530"></a>DCMI_TS_SUB_CMD_GET_FAULT_MASK</strong> are not supported.</p>
<p id="p7900115703014"><a name="p7900115703014"></a><a name="p7900115703014"></a>If Profiling is enabled, the queried single-core utilization will be <strong id="b187470161920"><a name="b187470161920"></a><a name="b187470161920"></a>0xEF</strong>.</p>
</td>
</tr>
<tr id="row1190010575303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1190018574307"><a name="p1190018574307"></a><a name="p1190018574307"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19007577307"><a name="p19007577307"></a><a name="p19007577307"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p17900175711302"><a name="p17900175711302"></a><a name="p17900175711302"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p390012575308"><a name="p390012575308"></a><a name="p390012575308"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row16900145719304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p9900155716309"><a name="p9900155716309"></a><a name="p9900155716309"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p0900185719304"><a name="p0900185719304"></a><a name="p0900185719304"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6901257173010"><a name="p6901257173010"></a><a name="p6901257173010"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p090113577301"><a name="p090113577301"></a><a name="p090113577301"></a>Length of the <strong id="b39621213111915"><a name="b39621213111915"></a><a name="b39621213111915"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section283355715302"></a>**

<a name="table1985018574309"></a>
<table><thead align="left"><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002546910411_b16147213413"><a name="en-us_topic_0000002546910411_b16147213413"></a><a name="en-us_topic_0000002546910411_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None.

**Restrictions<a name="section2889103794114"></a>**

- For the query of single-core utilization of the Vector Core,  **buf**  must be at least 50 bytes. For the query of single-core utilization of the AI Core,  **buf**  must be at least 25 bytes.
- This API can be used in the PM + privileged container scenario.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table08529574303"></a>
<table><thead align="left"><tr id="row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="p59011457173015"><a name="p59011457173015"></a><a name="p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="p159011357193019"><a name="p159011357193019"></a><a name="p159011357193019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="p1990165743011"><a name="p1990165743011"></a><a name="p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row12901185711304"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p8901195718303"><a name="p8901195718303"></a><a name="p8901195718303"></a>DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE, DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p1290105717308"><a name="p1290105717308"></a><a name="p1290105717308"></a>For the query of single-core utilization of the Vector Core, <strong id="b11460530151212"><a name="b11460530151212"></a><a name="b11460530151212"></a>buf</strong> must be at least 50 bytes. For the query of single-core utilization of the AI Core, <strong id="b16460183010120"><a name="b16460183010120"></a><a name="b16460183010120"></a>buf</strong> must be at least 25 bytes.</p>
<p id="p79011657193018"><a name="p79011657193018"></a><a name="p79011657193018"></a>Error values:</p>
<p id="p29014575305"><a name="p29014575305"></a><a name="p29014575305"></a><strong id="b17706454308530"><a name="b17706454308530"></a><a name="b17706454308530"></a>0xEE</strong>: The corresponding core is damaged.</p>
<p id="p4901115718309"><a name="p4901115718309"></a><a name="p4901115718309"></a><strong id="b1123339738530"><a name="b1123339738530"></a><a name="b1123339738530"></a>0xEF</strong>: invalid.</p>
<p id="p290185713306"><a name="p290185713306"></a><a name="p290185713306"></a>As an output, each byte indicates the utilization of a core. The value ranges from 0 to 100.</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p490115713018"><a name="p490115713018"></a><a name="p490115713018"></a>As an input, it indicates the buffer size.</p>
<p id="p2090125710307"><a name="p2090125710307"></a><a name="p2090125710307"></a>As an output, it indicates the number of valid values in the buffer.</p>
</td>
</tr>
<tr id="row6901185719303"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p179011357143018"><a name="p179011357143018"></a><a name="p179011357143018"></a>DCMI_TS_SUB_CMD_FFTS_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p89011657113020"><a name="p89011657113020"></a><a name="p89011657113020"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p12901115712303"><a name="p12901115712303"></a><a name="p12901115712303"></a>unsigned int</p>
</td>
</tr>
<tr id="row19471316207"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p1047117132015"><a name="p1047117132015"></a><a name="p1047117132015"></a>DCMI_TS_SUB_CMD_COMMON_MSG</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p19469111244813"><a name="p19469111244813"></a><a name="p19469111244813"></a>struct ts_dcmi_ctrl_msg_body_t {</p>
<p id="p1246961219488"><a name="p1246961219488"></a><a name="p1246961219488"></a>unsigned int msg_type;</p>
<p id="p246915123487"><a name="p246915123487"></a><a name="p246915123487"></a>union {</p>
<p id="p1746901219481"><a name="p1746901219481"></a><a name="p1746901219481"></a>ts_dcmi_task_timeout_t set_task_timeout_info;</p>
<p id="p64691512154816"><a name="p64691512154816"></a><a name="p64691512154816"></a>ts_dcmi_task_timeout_t get_task_timeout_info;</p>
<p id="p13469131244812"><a name="p13469131244812"></a><a name="p13469131244812"></a>} u;</p>
<p id="p134691512204817"><a name="p134691512204817"></a><a name="p134691512204817"></a>};</p>
<p id="p1719316326501"><a name="p1719316326501"></a><a name="p1719316326501"></a>The ts_dcmi_task_timeout_t structure is as follows:</p>
<p id="p522516213502"><a name="p522516213502"></a><a name="p522516213502"></a>typedef struct {</p>
<p id="p32251323501"><a name="p32251323501"></a><a name="p32251323501"></a>unsigned int timeout_limit_exp; // Value range: [20, 32]</p>
<p id="p222512155013"><a name="p222512155013"></a><a name="p222512155013"></a>unsigned char rsev[TS_RSEV_MAX_LENTH]; // <strong id="b1872093414113"><a name="b1872093414113"></a><a name="b1872093414113"></a>TS_RSEV_MAX_LENTH</strong> is <strong id="b1072093431114"><a name="b1072093431114"></a><a name="b1072093431114"></a>36</strong>.</p>
<p id="p10225725506"><a name="p10225725506"></a><a name="p10225725506"></a>} ts_dcmi_task_timeout_t;</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p19359252485"><a name="p19359252485"></a><a name="p19359252485"></a>As an input, it indicates the <strong id="b17861204312118"><a name="b17861204312118"></a><a name="b17861204312118"></a>buf</strong> size. The <strong id="b18861343111119"><a name="b18861343111119"></a><a name="b18861343111119"></a>buf</strong> must be at least 44 bytes.</p>
<p id="p19218195310"><a name="p19218195310"></a><a name="p19218195310"></a><strong id="b126011646161113"><a name="b126011646161113"></a><a name="b126011646161113"></a>msg_type</strong> is <strong id="b19601144615112"><a name="b19601144615112"></a><a name="b19601144615112"></a>0</strong> or <strong id="b0601144617119"><a name="b0601144617119"></a><a name="b0601144617119"></a>1</strong>.</p>
<a name="ul16848433145315"></a><a name="ul16848433145315"></a><ul id="ul16848433145315"><li>The value <strong id="b65066501117"><a name="b65066501117"></a><a name="b65066501117"></a>1</strong> indicates setting the AICPU operator timeout value.</li><li>The value <strong id="b5742205391119"><a name="b5742205391119"></a><a name="b5742205391119"></a>0</strong> indicates querying the AICPU operator timeout value.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section49611431655"></a>**

```c
...
int ret;
int card_id = 0;
int dev_id = 0;
void *buf = NULL;
int buf_size = 10;
buf = calloc(buf_size, sizeof(char));
if (buf == NULL) {
printf("calloc buf failed.\n");
return -1;
}
ret = dcmi_get_device_info(card_id,dev_id,DCMI_MAIN_CMD_TS, DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE, buf, &buf_size);
if (ret != 0) {
printf("dcmi_get_device_info failed, ret = %d.\n", ret);
return -1;
}
return 0;
...
```

## DCMI\_MAIN\_CMD\_QOS Command<a name="EN-US_TOPIC_0000002546990371"></a>

**Prototype<a name="section14467101743119"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section204687171315"></a>**

Obtains QoS configuration, including mpamid and master QoS configuration and bandwidth statistics.

**Parameter Description<a name="section1546861713117"></a>**

<a name="table150171718316"></a>
<table><thead align="left"><tr id="row45967179312"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1359641710311"><a name="p1359641710311"></a><a name="p1359641710311"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p1596181753116"><a name="p1596181753116"></a><a name="p1596181753116"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p13596161712315"><a name="p13596161712315"></a><a name="p13596161712315"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p1359691733113"><a name="p1359691733113"></a><a name="p1359691733113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1159661713116"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p259611174316"><a name="p259611174316"></a><a name="p259611174316"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p3596151773118"><a name="p3596151773118"></a><a name="p3596151773118"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p059611170317"><a name="p059611170317"></a><a name="p059611170317"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p959612177316"><a name="p959612177316"></a><a name="p959612177316"></a>Device ID. The supported IDs can be obtained by calling <strong id="b96781876224"><a name="b96781876224"></a><a name="b96781876224"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row19596817133118"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p185961717183110"><a name="p185961717183110"></a><a name="p185961717183110"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p195961517143118"><a name="p195961517143118"></a><a name="p195961517143118"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1359617171318"><a name="p1359617171318"></a><a name="p1359617171318"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p059671763113"><a name="p059671763113"></a><a name="p059671763113"></a>Chip ID, which can be obtained by calling <strong id="b110166716932946"><a name="b110166716932946"></a><a name="b110166716932946"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p20596131743115"><a name="p20596131743115"></a><a name="p20596131743115"></a>NPU: [0, <strong id="b9079639408735"><a name="b9079639408735"></a><a name="b9079639408735"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row459661713310"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p105971917113120"><a name="p105971917113120"></a><a name="p105971917113120"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p165973173319"><a name="p165973173319"></a><a name="p165973173319"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p3597617163117"><a name="p3597617163117"></a><a name="p3597617163117"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p45971417163119"><a name="p45971417163119"></a><a name="p45971417163119"></a>DCMI_MAIN_CMD_QOS</p>
</td>
</tr>
<tr id="row25975175318"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p659741718311"><a name="p659741718311"></a><a name="p659741718311"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185971617163113"><a name="p185971617163113"></a><a name="p185971617163113"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p175971117123115"><a name="p175971117123115"></a><a name="p175971117123115"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock13311208103610"><a name="codeblock13311208103610"></a><a name="codeblock13311208103610"></a>typedef enum {
// MATA configuration
DCMI_QOS_SUB_MATA_CONFIG,
// Master configuration
DCMI_QOS_SUB_MASTER_CONFIG,
// Bandwidth statistics
DCMI_QOS_SUB_BW_DATA,
// Global configuration
DCMI_QOS_SUB_GLOBAL_CONFIG,
// Configure the completion instruction.
DCMI_QOS_SUB_CONFIG_DONE,
} DCMI_QOS_SUB_INFO;</pre>
<p id="p5929173053615"><a name="p5929173053615"></a><a name="p5929173053615"></a>Currently, only <strong id="b19153729102718"><a name="b19153729102718"></a><a name="b19153729102718"></a>DCMI_QOS_SUB_MATA_CONFIG</strong>, <strong id="b915362902715"><a name="b915362902715"></a><a name="b915362902715"></a>DCMI_QOS_SUB_MASTER_CONFIG</strong>, <strong id="b10154729172711"><a name="b10154729172711"></a><a name="b10154729172711"></a>DCMI_QOS_SUB_BW_DATA</strong>, and <strong id="b15154132902714"><a name="b15154132902714"></a><a name="b15154132902714"></a>DCMI_QOS_SUB_GLOBAL_CONFIG</strong> are supported.</p>
</td>
</tr>
<tr id="row1059751753117"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p165976179310"><a name="p165976179310"></a><a name="p165976179310"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p105971717153116"><a name="p105971717153116"></a><a name="p105971717153116"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13597191753119"><a name="p13597191753119"></a><a name="p13597191753119"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p13597161723117"><a name="p13597161723117"></a><a name="p13597161723117"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row1597151743112"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p05974176319"><a name="p05974176319"></a><a name="p05974176319"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p45972017113117"><a name="p45972017113117"></a><a name="p45972017113117"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p8597717103117"><a name="p8597717103117"></a><a name="p8597717103117"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1759791793116"><a name="p1759791793116"></a><a name="p1759791793116"></a>Length of the <strong id="b61221334284"><a name="b61221334284"></a><a name="b61221334284"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section34771217163116"></a>**

<a name="table165071517183118"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b16661104657227"><a name="b16661104657227"></a><a name="b16661104657227"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section9677135115517"></a>**

None

**Restrictions<a name="section2977135411511"></a>**

- Restricted by the SoC feature, call  **DCMI\_set\_device\_info**  before calling the corresponding  **get**  API to read whether the configuration takes effect. Otherwise, the read value is unreliable.
- The function of obtaining the bandwidth by using  **resctrl**  conflicts with the function of obtaining the real-time bandwidth by using the DCMI API. Do not use both simultaneously.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1450912173312"></a>
<table><thead align="left"><tr id="row1359861743110"><th class="cellrowborder" valign="top" width="31.403140314031404%" id="mcps1.2.5.1.1"><p id="p16598617103119"><a name="p16598617103119"></a><a name="p16598617103119"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="20.122012201220123%" id="mcps1.2.5.1.2"><p id="p8598131713110"><a name="p8598131713110"></a><a name="p8598131713110"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="15.701570157015702%" id="mcps1.2.5.1.3"><p id="p195981717153117"><a name="p195981717153117"></a><a name="p195981717153117"></a>buf_size</p>
</th>
<th class="cellrowborder" valign="top" width="32.77327732773277%" id="mcps1.2.5.1.4"><p id="p559831773117"><a name="p559831773117"></a><a name="p559831773117"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1459821713316"><td class="cellrowborder" valign="top" width="31.403140314031404%" headers="mcps1.2.5.1.1 "><p id="p659871712318"><a name="p659871712318"></a><a name="p659871712318"></a>DCMI_QOS_SUB_MATA_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="20.122012201220123%" headers="mcps1.2.5.1.2 "><p id="p105981117163113"><a name="p105981117163113"></a><a name="p105981117163113"></a>struct qos_mata_config</p>
<p id="p3598917133118"><a name="p3598917133118"></a><a name="p3598917133118"></a>{</p>
<p id="p15598181793119"><a name="p15598181793119"></a><a name="p15598181793119"></a>int mpamid;</p>
<p id="p14598121753118"><a name="p14598121753118"></a><a name="p14598121753118"></a>u32 bw_high;</p>
<p id="p105981917153115"><a name="p105981917153115"></a><a name="p105981917153115"></a>u32 bw_low;</p>
<p id="p7598117133110"><a name="p7598117133110"></a><a name="p7598117133110"></a>int hardlimit;</p>
<p id="p359881793112"><a name="p359881793112"></a><a name="p359881793112"></a>int reserved[8];</p>
<p id="p45981317203119"><a name="p45981317203119"></a><a name="p45981317203119"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="15.701570157015702%" headers="mcps1.2.5.1.3 "><p id="p85982017103119"><a name="p85982017103119"></a><a name="p85982017103119"></a>sizeof(qos_mata_</p>
<p id="p65987174315"><a name="p65987174315"></a><a name="p65987174315"></a>config)</p>
</td>
<td class="cellrowborder" valign="top" width="32.77327732773277%" headers="mcps1.2.5.1.4 "><p id="p55981017153116"><a name="p55981017153116"></a><a name="p55981017153116"></a><strong id="b92471322101016"><a name="b92471322101016"></a><a name="b92471322101016"></a>mpamid</strong>: The value range is [0, 127].</p>
<p id="p959881723117"><a name="p959881723117"></a><a name="p959881723117"></a><strong id="b15114728768735"><a name="b15114728768735"></a><a name="b15114728768735"></a>bw_high</strong>: high waterline (GB/s).</p>
<p id="p15598141713319"><a name="p15598141713319"></a><a name="p15598141713319"></a>The value range is [0, 1638].</p>
<p id="p1959917172315"><a name="p1959917172315"></a><a name="p1959917172315"></a><strong id="b118921933191016"><a name="b118921933191016"></a><a name="b118921933191016"></a>bw_low</strong>: low waterline (GB/s). The value range is [0, <strong id="b1189219335109"><a name="b1189219335109"></a><a name="b1189219335109"></a>bw_high</strong>].</p>
<p id="p20599121793112"><a name="p20599121793112"></a><a name="p20599121793112"></a><strong id="b13970123521013"><a name="b13970123521013"></a><a name="b13970123521013"></a>hardlimit</strong>: The value <strong id="b2097173561010"><a name="b2097173561010"></a><a name="b2097173561010"></a>1</strong> indicates enabled, whereas the value <strong id="b3971123517106"><a name="b3971123517106"></a><a name="b3971123517106"></a>0</strong> indicates disabled.</p>
<p id="p13599191773117"><a name="p13599191773117"></a><a name="p13599191773117"></a>The waterlines you read by using this subcommand may be different from those you set. Difference = Maximum processor bandwidth/<strong id="b75141916192911"><a name="b75141916192911"></a><a name="b75141916192911"></a>MAX_REG_VALUE</strong>. The value of <strong id="b58411121122918"><a name="b58411121122918"></a><a name="b58411121122918"></a>MAX_REG_VALUE</strong> is 1024.</p>
</td>
</tr>
<tr id="row1599121733110"><td class="cellrowborder" valign="top" width="31.403140314031404%" headers="mcps1.2.5.1.1 "><p id="p359910173318"><a name="p359910173318"></a><a name="p359910173318"></a>DCMI_QOS_SUB_MASTER_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="20.122012201220123%" headers="mcps1.2.5.1.2 "><p id="p125995179319"><a name="p125995179319"></a><a name="p125995179319"></a>struct qos_master_config</p>
<p id="p1659941753115"><a name="p1659941753115"></a><a name="p1659941753115"></a>{</p>
<p id="p165991417173110"><a name="p165991417173110"></a><a name="p165991417173110"></a>int master;</p>
<p id="p205995175318"><a name="p205995175318"></a><a name="p205995175318"></a>int mpamid;</p>
<p id="p45991117143117"><a name="p45991117143117"></a><a name="p45991117143117"></a>int qos;</p>
<p id="p145992172312"><a name="p145992172312"></a><a name="p145992172312"></a>int pmg;</p>
<p id="p1859961783120"><a name="p1859961783120"></a><a name="p1859961783120"></a>u64 bitmap[4];</p>
<p id="p4599217193119"><a name="p4599217193119"></a><a name="p4599217193119"></a>int reserved[8];</p>
<p id="p4599171710317"><a name="p4599171710317"></a><a name="p4599171710317"></a>};</p>
<p id="p1599101711319"><a name="p1599101711319"></a><a name="p1599101711319"></a></p>
</td>
<td class="cellrowborder" valign="top" width="15.701570157015702%" headers="mcps1.2.5.1.3 "><p id="p259917179318"><a name="p259917179318"></a><a name="p259917179318"></a>sizeof(qos_master</p>
<p id="p18599121713116"><a name="p18599121713116"></a><a name="p18599121713116"></a>_config)</p>
</td>
<td class="cellrowborder" valign="top" width="32.77327732773277%" headers="mcps1.2.5.1.4 "><p id="p1659911753116"><a name="p1659911753116"></a><a name="p1659911753116"></a><strong id="b41131819152213"><a name="b41131819152213"></a><a name="b41131819152213"></a>master</strong>: master ID. The options are as follows:</p>
<p id="p13599317193112"><a name="p13599317193112"></a><a name="p13599317193112"></a>vdec=1,vpc=2,jpge=3,</p>
<p id="p1759951773118"><a name="p1759951773118"></a><a name="p1759951773118"></a>jpgd=4,pcie=7,sdma=13</p>
<p id="p959901703114"><a name="p959901703114"></a><a name="p959901703114"></a><strong id="b0400326141116"><a name="b0400326141116"></a><a name="b0400326141116"></a>mpamid</strong>: The value range is [0, 127].</p>
<p id="p9599517133119"><a name="p9599517133119"></a><a name="p9599517133119"></a><strong id="b182111338111020"><a name="b182111338111020"></a><a name="b182111338111020"></a>qos</strong>: bandwidth scheduling priority. The value range is [0, 7]. The value 0 indicates hardlimit QoS, and the value 7 indicates green channel QoS.</p>
<p id="p1459901712318"><a name="p1459901712318"></a><a name="p1459901712318"></a><strong id="b1864216508735"><a name="b1864216508735"></a><a name="b1864216508735"></a>pmg</strong>: mpamid group. The value range is [0, 3] (not supported currently).</p>
<p id="p11599171718314"><a name="p11599171718314"></a><a name="p11599171718314"></a><strong id="b104871440121015"><a name="b104871440121015"></a><a name="b104871440121015"></a>bitmap</strong>: not supported due to framework restrictions.</p>
</td>
</tr>
<tr id="row185991417153117"><td class="cellrowborder" valign="top" width="31.403140314031404%" headers="mcps1.2.5.1.1 "><p id="p259931753110"><a name="p259931753110"></a><a name="p259931753110"></a>DCMI_QOS_SUB_BW_DATA</p>
</td>
<td class="cellrowborder" valign="top" width="20.122012201220123%" headers="mcps1.2.5.1.2 "><p id="p8599817113120"><a name="p8599817113120"></a><a name="p8599817113120"></a>struct qos_bw_result</p>
<p id="p12600917113118"><a name="p12600917113118"></a><a name="p12600917113118"></a>{</p>
<p id="p18600131743116"><a name="p18600131743116"></a><a name="p18600131743116"></a>int mpamid;</p>
<p id="p4600101763114"><a name="p4600101763114"></a><a name="p4600101763114"></a>u32 curr;</p>
<p id="p11600191714316"><a name="p11600191714316"></a><a name="p11600191714316"></a>u32 bw_max;</p>
<p id="p060018172318"><a name="p060018172318"></a><a name="p060018172318"></a>u32 bw_min;</p>
<p id="p960051723117"><a name="p960051723117"></a><a name="p960051723117"></a>u32 bw_mean;</p>
<p id="p86000174315"><a name="p86000174315"></a><a name="p86000174315"></a>int reserved[8];</p>
<p id="p16003175318"><a name="p16003175318"></a><a name="p16003175318"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="15.701570157015702%" headers="mcps1.2.5.1.3 "><p id="p156001179310"><a name="p156001179310"></a><a name="p156001179310"></a>sizeof(qos_bw_result)</p>
</td>
<td class="cellrowborder" valign="top" width="32.77327732773277%" headers="mcps1.2.5.1.4 "><p id="p136002017103117"><a name="p136002017103117"></a><a name="p136002017103117"></a><strong id="b75701043171011"><a name="b75701043171011"></a><a name="b75701043171011"></a>mpamid</strong>: target mpamid to obtain the bandwidth.</p>
<p id="p1860021719315"><a name="p1860021719315"></a><a name="p1860021719315"></a>The value range is [0, 127].</p>
<p id="p1460019179315"><a name="p1460019179315"></a><a name="p1460019179315"></a><strong id="b1331024751020"><a name="b1331024751020"></a><a name="b1331024751020"></a>curr</strong>: latest bandwidth (MB/s).</p>
<p id="p5600101793110"><a name="p5600101793110"></a><a name="p5600101793110"></a><strong id="b15151295398735"><a name="b15151295398735"></a><a name="b15151295398735"></a>bw_max</strong>: maximum value (MB/s) over the sampling period.</p>
<p id="p1060010171314"><a name="p1060010171314"></a><a name="p1060010171314"></a><strong id="b168212037173020"><a name="b168212037173020"></a><a name="b168212037173020"></a>bw_min</strong>: minimum value (MB/s) over the sampling period.</p>
<p id="p10600617153119"><a name="p10600617153119"></a><a name="p10600617153119"></a><strong id="b5535401306"><a name="b5535401306"></a><a name="b5535401306"></a>bw_mean</strong>: mean value (MB/s) over the sampling period.</p>
</td>
</tr>
<tr id="row1560041716314"><td class="cellrowborder" valign="top" width="31.403140314031404%" headers="mcps1.2.5.1.1 "><p id="p12600917143112"><a name="p12600917143112"></a><a name="p12600917143112"></a>DCMI_QOS_SUB_GLOBAL_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="20.122012201220123%" headers="mcps1.2.5.1.2 "><p id="p3600717123114"><a name="p3600717123114"></a><a name="p3600717123114"></a>struct qos_gbl_config</p>
<p id="p76008172312"><a name="p76008172312"></a><a name="p76008172312"></a>{</p>
<p id="p3600131783116"><a name="p3600131783116"></a><a name="p3600131783116"></a>u32 enable;</p>
<p id="p126002177317"><a name="p126002177317"></a><a name="p126002177317"></a>u32 autoqos_fuse_en;</p>
<p id="p860021763110"><a name="p860021763110"></a><a name="p860021763110"></a>u32 mpamqos_fuse_mode;</p>
<p id="p16001617133115"><a name="p16001617133115"></a><a name="p16001617133115"></a>u32 mpam_subtype;</p>
<p id="p1600117143115"><a name="p1600117143115"></a><a name="p1600117143115"></a>int reserved[8];</p>
<p id="p126006174314"><a name="p126006174314"></a><a name="p126006174314"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="15.701570157015702%" headers="mcps1.2.5.1.3 "><p id="p14600617163113"><a name="p14600617163113"></a><a name="p14600617163113"></a>sizeof(qos_gbl_config)</p>
</td>
<td class="cellrowborder" valign="top" width="32.77327732773277%" headers="mcps1.2.5.1.4 "><a name="ul15992846123713"></a><a name="ul15992846123713"></a><ul id="ul15992846123713"><li><strong id="b1591483282219"><a name="b1591483282219"></a><a name="b1591483282219"></a>enable</strong>: indicates whether to enable the QoS function.<a name="ul1426935273713"></a><a name="ul1426935273713"></a><ul id="ul1426935273713"><li><strong id="b9076233248735"><a name="b9076233248735"></a><a name="b9076233248735"></a>0</strong>: disabled</li><li><strong id="b13081403288735"><a name="b13081403288735"></a><a name="b13081403288735"></a>1</strong>: enabled</li></ul>
</li><li><strong id="b193103713226"><a name="b193103713226"></a><a name="b193103713226"></a>autoqos_fuse_en</strong>: indicates whether to enable QoS fusion.<a name="ul161181811163814"></a><a name="ul161181811163814"></a><ul id="ul161181811163814"><li><strong id="b162198017314"><a name="b162198017314"></a><a name="b162198017314"></a>0</strong>: QoS fusion is disabled.</li><li><strong id="b275414383116"><a name="b275414383116"></a><a name="b275414383116"></a>1</strong>: QoS fusion starts.</li></ul>
</li><li><strong id="b182112913311"><a name="b182112913311"></a><a name="b182112913311"></a>mpamqos_fuse_mode</strong>: QoS fusion mode. This parameter takes effect when <strong id="b9211149173111"><a name="b9211149173111"></a><a name="b9211149173111"></a>autoqos_fuse_en</strong> is enabled.<a name="ul879644411386"></a><a name="ul879644411386"></a><ul id="ul879644411386"><li><strong id="b16170783408735"><a name="b16170783408735"></a><a name="b16170783408735"></a>0</strong>: average fusion</li><li><strong id="b1130154717456"><a name="b1130154717456"></a><a name="b1130154717456"></a>1</strong>: maximum value between the associated QoS and MPAM QoS</li><li><strong id="b3257858608735"><a name="b3257858608735"></a><a name="b3257858608735"></a>2</strong>: associated QoS as mpamqos</li></ul>
</li><li><strong id="b8837144678735"><a name="b8837144678735"></a><a name="b8837144678735"></a>mpam_subtype</strong>: bandwidth statistics mode<a name="ul16435328393"></a><a name="ul16435328393"></a><ul id="ul16435328393"><li><strong id="b4378217158735"><a name="b4378217158735"></a><a name="b4378217158735"></a>0</strong>: read and write bandwidth statistics</li><li><strong id="b13358349858735"><a name="b13358349858735"></a><a name="b13358349858735"></a>1</strong>: write bandwidth statistics</li><li><strong id="b20699086758735"><a name="b20699086758735"></a><a name="b20699086758735"></a>2</strong>: read bandwidth statistics</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row913516862011"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1913568182013"><a name="en-us_topic_0000002515350556_p1913568182013"></a><a name="en-us_topic_0000002515350556_p1913568182013"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p1713588142014"><a name="en-us_topic_0000002515350556_p1713588142014"></a><a name="en-us_topic_0000002515350556_p1713588142014"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p161354852013"><a name="en-us_topic_0000002515350556_p161354852013"></a><a name="en-us_topic_0000002515350556_p161354852013"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row17135168192014"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p16135128182017"><a name="en-us_topic_0000002515350556_p16135128182017"></a><a name="en-us_topic_0000002515350556_p16135128182017"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1713528202015"><a name="en-us_topic_0000002515350556_p1713528202015"></a><a name="en-us_topic_0000002515350556_p1713528202015"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p181351087205"><a name="en-us_topic_0000002515350556_p181351087205"></a><a name="en-us_topic_0000002515350556_p181351087205"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row31351488206"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p6135185208"><a name="en-us_topic_0000002515350556_p6135185208"></a><a name="en-us_topic_0000002515350556_p6135185208"></a><span id="en-us_topic_0000002515350556_text1213528172016"><a name="en-us_topic_0000002515350556_text1213528172016"></a><a name="en-us_topic_0000002515350556_text1213528172016"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1213511813205"><a name="en-us_topic_0000002515350556_p1213511813205"></a><a name="en-us_topic_0000002515350556_p1213511813205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p613528102020"><a name="en-us_topic_0000002515350556_p613528102020"></a><a name="en-us_topic_0000002515350556_p613528102020"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p713512862013"><a name="en-us_topic_0000002515350556_p713512862013"></a><a name="en-us_topic_0000002515350556_p713512862013"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1813515811208"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p71354810207"><a name="en-us_topic_0000002515350556_p71354810207"></a><a name="en-us_topic_0000002515350556_p71354810207"></a><span id="en-us_topic_0000002515350556_text51358812207"><a name="en-us_topic_0000002515350556_text51358812207"></a><a name="en-us_topic_0000002515350556_text51358812207"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p213568152019"><a name="en-us_topic_0000002515350556_p213568152019"></a><a name="en-us_topic_0000002515350556_p213568152019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1613548142019"><a name="en-us_topic_0000002515350556_p1613548142019"></a><a name="en-us_topic_0000002515350556_p1613548142019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11351087209"><a name="en-us_topic_0000002515350556_p11351087209"></a><a name="en-us_topic_0000002515350556_p11351087209"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row87611016195410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p8296259161515"><a name="en-us_topic_0000002515350556_p8296259161515"></a><a name="en-us_topic_0000002515350556_p8296259161515"></a><span id="en-us_topic_0000002515350556_text14296259131514"><a name="en-us_topic_0000002515350556_text14296259131514"></a><a name="en-us_topic_0000002515350556_text14296259131514"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1451920314542"><a name="en-us_topic_0000002515350556_p1451920314542"></a><a name="en-us_topic_0000002515350556_p1451920314542"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p2519133155413"><a name="en-us_topic_0000002515350556_p2519133155413"></a><a name="en-us_topic_0000002515350556_p2519133155413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11519153110545"><a name="en-us_topic_0000002515350556_p11519153110545"></a><a name="en-us_topic_0000002515350556_p11519153110545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row0323633152810"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p064011372281"><a name="en-us_topic_0000002515350556_p064011372281"></a><a name="en-us_topic_0000002515350556_p064011372281"></a><span id="en-us_topic_0000002515350556_text18640537162811"><a name="en-us_topic_0000002515350556_text18640537162811"></a><a name="en-us_topic_0000002515350556_text18640537162811"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p279104012287"><a name="en-us_topic_0000002515350556_p279104012287"></a><a name="en-us_topic_0000002515350556_p279104012287"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p779112409289"><a name="en-us_topic_0000002515350556_p779112409289"></a><a name="en-us_topic_0000002515350556_p779112409289"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1791140112816"><a name="en-us_topic_0000002515350556_p1791140112816"></a><a name="en-us_topic_0000002515350556_p1791140112816"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row49081418125411"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p512952510545"><a name="en-us_topic_0000002515350556_p512952510545"></a><a name="en-us_topic_0000002515350556_p512952510545"></a><span id="en-us_topic_0000002515350556_text012942512545"><a name="en-us_topic_0000002515350556_text012942512545"></a><a name="en-us_topic_0000002515350556_text012942512545"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1260932135413"><a name="en-us_topic_0000002515350556_p1260932135413"></a><a name="en-us_topic_0000002515350556_p1260932135413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1660133285419"><a name="en-us_topic_0000002515350556_p1660133285419"></a><a name="en-us_topic_0000002515350556_p1660133285419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p46017321545"><a name="en-us_topic_0000002515350556_p46017321545"></a><a name="en-us_topic_0000002515350556_p46017321545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1625111184"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1386118141085"><a name="en-us_topic_0000002515350556_p1386118141085"></a><a name="en-us_topic_0000002515350556_p1386118141085"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section176618596619"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
int sub_cmd=0;
int size = sizeof(struct dcmi_qos_mata_config);
struct dcmi_qos_mata_config mataCfg = {0};
mataCfg.mpamid = 127;
unsigned int subCmd = (unsigned int)(DCMI_QOS_SUB_CMD_MAKE(mataCfg.mpamid, DCMI_QOS_SUB_MATA_CONFIG));
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_QOS, subCmd, (void *)&mataCfg, &size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_HCCS Command<a name="EN-US_TOPIC_0000002546910405"></a>

**Prototype<a name="section208203016314"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section15811309317"></a>**

Obtains HCCS information.

**Parameter Description<a name="section198123020315"></a>**

<a name="table72213073115"></a>
<table><thead align="left"><tr id="row1672203023119"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p187273012319"><a name="p187273012319"></a><a name="p187273012319"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p173143013316"><a name="p173143013316"></a><a name="p173143013316"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p873163083118"><a name="p873163083118"></a><a name="p873163083118"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p2073630143115"><a name="p2073630143115"></a><a name="p2073630143115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12731304319"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p4730301317"><a name="p4730301317"></a><a name="p4730301317"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p12731730103114"><a name="p12731730103114"></a><a name="p12731730103114"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p20731830153112"><a name="p20731830153112"></a><a name="p20731830153112"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1873930173118"><a name="p1873930173118"></a><a name="p1873930173118"></a>Device ID. The supported IDs can be obtained by calling <strong id="b10150186533308"><a name="b10150186533308"></a><a name="b10150186533308"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1073230183110"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p17731830153111"><a name="p17731830153111"></a><a name="p17731830153111"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p12731330203114"><a name="p12731330203114"></a><a name="p12731330203114"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p77314303319"><a name="p77314303319"></a><a name="p77314303319"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p117320301313"><a name="p117320301313"></a><a name="p117320301313"></a>Chip ID, which can be obtained by calling <strong id="b133484753932948"><a name="b133484753932948"></a><a name="b133484753932948"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p1073163019313"><a name="p1073163019313"></a><a name="p1073163019313"></a>NPU: [0, <strong id="b20994812358633"><a name="b20994812358633"></a><a name="b20994812358633"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1973830183110"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p373130163117"><a name="p373130163117"></a><a name="p373130163117"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p127317307311"><a name="p127317307311"></a><a name="p127317307311"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p117310304314"><a name="p117310304314"></a><a name="p117310304314"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1273193015315"><a name="p1273193015315"></a><a name="p1273193015315"></a>DCMI_MAIN_CMD_HCCS</p>
</td>
</tr>
<tr id="row373830113118"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p187333003113"><a name="p187333003113"></a><a name="p187333003113"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p873130123111"><a name="p873130123111"></a><a name="p873130123111"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1773153003117"><a name="p1773153003117"></a><a name="p1773153003117"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p2591111610485"><a name="p2591111610485"></a><a name="p2591111610485"></a>typedef enum {</p>
<p id="p1659181664812"><a name="p1659181664812"></a><a name="p1659181664812"></a>DCMI_HCCS_CMD_GET_STATUS = 0,</p>
<p id="p18591416144813"><a name="p18591416144813"></a><a name="p18591416144813"></a>DCMI_HCCS_CMD_GET_LANE_INFO = 1,</p>
<p id="p10784121072814"><a name="p10784121072814"></a><a name="p10784121072814"></a>DCMI_HCCS_CMD_GET_STATISTIC_INFO = 3,</p>
<p id="p1828621611238"><a name="p1828621611238"></a><a name="p1828621611238"></a>DCMI_HCCS_CMD_GET_STATISTIC_INFO_U64 = 5,</p>
<p id="p125911116174815"><a name="p125911116174815"></a><a name="p125911116174815"></a>DCMI_HCCS_CMD_MAX,</p>
<p id="p359181694813"><a name="p359181694813"></a><a name="p359181694813"></a>} DCMI_HCCS_SUB_CMD;</p>
</td>
</tr>
<tr id="row10735307313"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p127343014311"><a name="p127343014311"></a><a name="p127343014311"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p37353017317"><a name="p37353017317"></a><a name="p37353017317"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p373193010317"><a name="p373193010317"></a><a name="p373193010317"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p107415309318"><a name="p107415309318"></a><a name="p107415309318"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row1074230113112"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p97423015311"><a name="p97423015311"></a><a name="p97423015311"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p674183073114"><a name="p674183073114"></a><a name="p674183073114"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p874183073116"><a name="p874183073116"></a><a name="p874183073116"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p11741830133113"><a name="p11741830133113"></a><a name="p11741830133113"></a>Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section111593003115"></a>**

<a name="table92723063116"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b20816764177229"><a name="b20816764177229"></a><a name="b20816764177229"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section77912615717"></a>**

None

**Restrictions<a name="section09411081372"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table12297302311"></a>
<table><thead align="left"><tr id="row37413013317"><th class="cellrowborder" valign="top" width="31.4%" id="mcps1.2.5.1.1"><p id="p10741330113120"><a name="p10741330113120"></a><a name="p10741330113120"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="31.4%" id="mcps1.2.5.1.2"><p id="p1874030103112"><a name="p1874030103112"></a><a name="p1874030103112"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.11%" id="mcps1.2.5.1.3"><p id="p1374530193111"><a name="p1374530193111"></a><a name="p1374530193111"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="24.09%" id="mcps1.2.5.1.4"><p id="p1674030173116"><a name="p1674030173116"></a><a name="p1674030173116"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1274193013316"><td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.1 "><p id="p1274203019311"><a name="p1274203019311"></a><a name="p1274203019311"></a>DCMI_HCCS_CMD_GET_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.2 "><p id="p156861185517"><a name="p156861185517"></a><a name="p156861185517"></a>struct dcmi_hccs_statues {</p>
<p id="p9681811135520"><a name="p9681811135520"></a><a name="p9681811135520"></a>unsigned int pcs_status;</p>
<p id="p11548325101116"><a name="p11548325101116"></a><a name="p11548325101116"></a>unsigned int hdlc_status;</p>
<p id="p1668151135514"><a name="p1668151135514"></a><a name="p1668151135514"></a>unsigned char reserve[DCMI_HCCS_STATUS_RESERVED_LEN];</p>
<p id="p1868151113554"><a name="p1868151113554"></a><a name="p1868151113554"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.2.5.1.3 "><p id="p1474123013119"><a name="p1474123013119"></a><a name="p1474123013119"></a>sizeof(struct dcmi_hccs_statues)</p>
</td>
<td class="cellrowborder" valign="top" width="24.09%" headers="mcps1.2.5.1.4 "><p id="p275203013113"><a name="p275203013113"></a><a name="p275203013113"></a>Queries the HCCS status. Currently, the PCS and HDLC status can be queried.</p>
<a name="ul5663163334913"></a><a name="ul5663163334913"></a><ul id="ul5663163334913"><li><strong id="b9222126182311"><a name="b9222126182311"></a><a name="b9222126182311"></a>pcs_status</strong> indicates the HCCS PCS status. The meanings of the values are as follows:<a name="ul13766848161417"></a><a name="ul13766848161417"></a><ul id="ul13766848161417"><li><strong id="b1233773751111"><a name="b1233773751111"></a><a name="b1233773751111"></a>0</strong> indicates that the status is normal.</li><li>A non-zero value indicates that the status is abnormal.</li></ul>
<p id="p2469153944918"><a name="p2469153944918"></a><a name="p2469153944918"></a>Specifically:</p>
<a name="ul1693262125011"></a><a name="ul1693262125011"></a><ul id="ul1693262125011"><li>Bit 0 is set to <strong id="b25434160468"><a name="b25434160468"></a><a name="b25434160468"></a>1</strong> when the status is abnormal.</li><li>Bits 1–7 are set to 0 and are reserved for extension.</li><li>Bits 8 to 15 indicate the sequence number of the faulty PCS. The sequence number ranges from 0 to 7 and indicates the index number of the first faulty PCS starting from 0.</li><li>Bits 16 to 23 indicate the current lane mode of the PCS.<p id="p86611229115012"><a name="p86611229115012"></a><a name="p86611229115012"></a><strong id="b4693113014472"><a name="b4693113014472"></a><a name="b4693113014472"></a>0</strong>: 0lane</p>
<p id="p176877310505"><a name="p176877310505"></a><a name="p176877310505"></a><strong id="b15530193134711"><a name="b15530193134711"></a><a name="b15530193134711"></a>1</strong>: 1lane</p>
<p id="p0883143345017"><a name="p0883143345017"></a><a name="p0883143345017"></a><strong id="b1439983216476"><a name="b1439983216476"></a><a name="b1439983216476"></a>2</strong>: 4lane</p>
<p id="p199651627105011"><a name="p199651627105011"></a><a name="p199651627105011"></a><strong id="b43461333164718"><a name="b43461333164718"></a><a name="b43461333164718"></a>3</strong>: 8lane</p>
</li><li>Bits 24–31 indicate the current lane of the PCS.</li></ul>
</li><li><strong id="b16997931162318"><a name="b16997931162318"></a><a name="b16997931162318"></a>pcs_status</strong> indicates the HCCS PCS status. The meanings of the values are as follows:<a name="ul15277145372620"></a><a name="ul15277145372620"></a><ul id="ul15277145372620"><li>Bits 2 to 31 are set to <strong id="b12995814473"><a name="b12995814473"></a><a name="b12995814473"></a>0</strong> and are reserved for extension.</li><li>Bits 0 to 1 indicate the HCCS HDLC initialization status.<a name="ul11478295276"></a><a name="ul11478295276"></a><ul id="ul11478295276"><li><strong id="b18971105617236"><a name="b18971105617236"></a><a name="b18971105617236"></a>00</strong>: waiting for initialization</li><li><strong id="b131932057244"><a name="b131932057244"></a><a name="b131932057244"></a>01</strong>: initialization packets exchanged successfully</li><li><strong id="b1885891352410"><a name="b1885891352410"></a><a name="b1885891352410"></a>10</strong>: waiting for initialization to complete</li><li><strong id="b13201219102419"><a name="b13201219102419"></a><a name="b13201219102419"></a>11</strong>: initialization completed successfully (the HCCS HDLC status is normal).</li></ul>
</li></ul>
</li></ul>
</td>
</tr>
<tr id="row3561143218479"><td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.1 "><p id="p2266153518472"><a name="p2266153518472"></a><a name="p2266153518472"></a>DCMI_HCCS_CMD_GET_LANE_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.2 "><p id="p1126619351474"><a name="p1126619351474"></a><a name="p1126619351474"></a>struct dcmi_hccs_lane_info {</p>
<p id="p926603514474"><a name="p926603514474"></a><a name="p926603514474"></a>unsigned int hccs_port_pcs_bitmap;</p>
<p id="p11266133513473"><a name="p11266133513473"></a><a name="p11266133513473"></a>unsigned int pcs_lane_bitmap[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p626673519479"><a name="p626673519479"></a><a name="p626673519479"></a>unsigned int reserve[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p10266135194714"><a name="p10266135194714"></a><a name="p10266135194714"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.2.5.1.3 "><p id="p14266435114716"><a name="p14266435114716"></a><a name="p14266435114716"></a>sizeof(struct dcmi_hccs_lane_info)</p>
</td>
<td class="cellrowborder" valign="top" width="24.09%" headers="mcps1.2.5.1.4 "><a name="ul8832161775120"></a><a name="ul8832161775120"></a><ul id="ul8832161775120"><li><strong id="b20584193620476"><a name="b20584193620476"></a><a name="b20584193620476"></a>hccs_port_pcs_bitmap</strong> indicates whether a port is used for connecting the HCCS to the PCS. The less significant a bit in the bitmap, the smaller the port number. For each bit, the value <strong id="b7584193644715"><a name="b7584193644715"></a><a name="b7584193644715"></a>0</strong> indicates that the port corresponding to the bit is not used for the HCCS, and the value <strong id="b85841136174716"><a name="b85841136174716"></a><a name="b85841136174716"></a>1</strong> indicates that the port corresponding to the bit is used for the HCCS.</li><li><strong id="b192031514819"><a name="b192031514819"></a><a name="b192031514819"></a>pcs_lane_bitmap</strong> indicates the lane information array used for HCCS connection. The sequence of the values in this array is the same as that of the bits set to <strong id="b15920151574811"><a name="b15920151574811"></a><a name="b15920151574811"></a>1</strong> in <strong id="b192071518489"><a name="b192071518489"></a><a name="b192071518489"></a>hccs_port_pcs_bitmap</strong> (starting from the least significant bit that is set to <strong id="b49201215184810"><a name="b49201215184810"></a><a name="b49201215184810"></a>1</strong>). The meanings of the values are as follows:<a name="ul132662358472"></a><a name="ul132662358472"></a><ul id="ul132662358472"><li>Bit 0 indicates whether the switching to the HCCS is complete.<p id="p88104120528"><a name="p88104120528"></a><a name="p88104120528"></a>The value <strong id="b1394218246484"><a name="b1394218246484"></a><a name="b1394218246484"></a>1</strong> indicates that it is complete.</p>
<p id="p920790135211"><a name="p920790135211"></a><a name="p920790135211"></a>The value <strong id="b18334162774812"><a name="b18334162774812"></a><a name="b18334162774812"></a>0</strong> indicates that the values of other bits are invalid.</p>
</li><li>Bits 1 to 8 indicate the lane number of the current HCCS connection. The value ranges from 0 to 3, starting from the least significant bit.<p id="p152591425165312"><a name="p152591425165312"></a><a name="p152591425165312"></a>The value <strong id="b65241334104818"><a name="b65241334104818"></a><a name="b65241334104818"></a>1</strong> indicates that a lane is being used for data transmission.</p>
<p id="p257122111530"><a name="p257122111530"></a><a name="p257122111530"></a>The value <strong id="b131212368483"><a name="b131212368483"></a><a name="b131212368483"></a>0</strong> indicates that it is not being used.</p>
</li><li>Bits 9 to 10 indicate the lane mode of the current HCCS connection.<p id="p131154611532"><a name="p131154611532"></a><a name="p131154611532"></a><strong id="b18765040164817"><a name="b18765040164817"></a><a name="b18765040164817"></a>00</strong>: 0lane</p>
<p id="p5608347145319"><a name="p5608347145319"></a><a name="p5608347145319"></a><strong id="b9853841104815"><a name="b9853841104815"></a><a name="b9853841104815"></a>01</strong>: 1lane</p>
<p id="p0579103145413"><a name="p0579103145413"></a><a name="p0579103145413"></a><strong id="b169182425486"><a name="b169182425486"></a><a name="b169182425486"></a>10</strong>: 4lane</p>
<p id="p184709442533"><a name="p184709442533"></a><a name="p184709442533"></a><strong id="b2822154374812"><a name="b2822154374812"></a><a name="b2822154374812"></a>11</strong>: 2lane</p>
</li></ul>
</li></ul>
</td>
</tr>
<tr id="row515051473110"><td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.1 "><p id="p7151111413315"><a name="p7151111413315"></a><a name="p7151111413315"></a>DCMI_HCCS_CMD_GET_STATISTIC_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.2 "><p id="p290151111549"><a name="p290151111549"></a><a name="p290151111549"></a>struct dcmi_hccs_statistic_info {</p>
<p id="p190118116546"><a name="p190118116546"></a><a name="p190118116546"></a>unsigned int tx_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p18901161120541"><a name="p18901161120541"></a><a name="p18901161120541"></a>unsigned int rx_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p119013111542"><a name="p119013111542"></a><a name="p119013111542"></a>unsigned int crc_err_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p119015111545"><a name="p119015111545"></a><a name="p119015111545"></a>unsigned int retry_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p2090141185415"><a name="p2090141185415"></a><a name="p2090141185415"></a>unsigned int reserved_field_cnt[DCMI_HCCS_RES_FIELD_NUM];</p>
<p id="p8901191145412"><a name="p8901191145412"></a><a name="p8901191145412"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.2.5.1.3 "><p id="p20151121412314"><a name="p20151121412314"></a><a name="p20151121412314"></a>sizeof(struct dcmi_hccs_statistic_info)</p>
</td>
<td class="cellrowborder" valign="top" width="24.09%" headers="mcps1.2.5.1.4 "><p id="p1311994219353"><a name="p1311994219353"></a><a name="p1311994219353"></a>Obtains the statistics of packets received and sent by the HCCS and bit errors.</p>
<a name="ul18736115213512"></a><a name="ul18736115213512"></a><ul id="ul18736115213512"><li>Currently, the chip uses only the x4 mode and obtains the statistics of eight HDLC links (per device).</li><li>The statistics of each link contain three u32 integers, which are the number of transmitted packets, number of received packets, and number of received packets with CRC errors. The unit is flit.</li><li><strong id="b5919165074812"><a name="b5919165074812"></a><a name="b5919165074812"></a>tx_cnt</strong>: total number of sent packets. The value ranges from 0 to 4,294,967,295.</li><li><strong id="b9726155304815"><a name="b9726155304815"></a><a name="b9726155304815"></a>rx_cnt</strong>: total number of received packets. The value ranges from 0 to 4,294,967,295.</li><li><strong id="b472715594816"><a name="b472715594816"></a><a name="b472715594816"></a>crc_err_cnt</strong>: number of bit errors. The value ranges from 0 to 4,294,967,295.</li><li><strong id="b1080455804815"><a name="b1080455804815"></a><a name="b1080455804815"></a>retry_cnt</strong>: number of packet transmission retries. The value ranges from 0 to 4,294,967,295.<a name="ul1352101671119"></a><a name="ul1352101671119"></a><ul id="ul1352101671119"><li><strong id="b494973164910"><a name="b494973164910"></a><a name="b494973164910"></a>0</strong>: no retransmission</li><li>Other values: number of retransmission times</li></ul>
</li></ul>
</td>
</tr>
<tr id="row1172342663911"><td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.1 "><p id="p18308185552312"><a name="p18308185552312"></a><a name="p18308185552312"></a>DCMI_HCCS_CMD_GET_STATISTIC_INFO_U64</p>
</td>
<td class="cellrowborder" valign="top" width="31.4%" headers="mcps1.2.5.1.2 "><p id="p88016523368"><a name="p88016523368"></a><a name="p88016523368"></a>struct dcmi_hccs_statistic_info_u64 {</p>
<p id="p08015525362"><a name="p08015525362"></a><a name="p08015525362"></a>unsigned long long tx_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p18016526363"><a name="p18016526363"></a><a name="p18016526363"></a>unsigned long long rx_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p580145218362"><a name="p580145218362"></a><a name="p580145218362"></a>unsigned long long crc_err_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p1780155243612"><a name="p1780155243612"></a><a name="p1780155243612"></a>unsigned long long retry_cnt[DCMI_HCCS_MAX_PCS_NUM];</p>
<p id="p3801052183611"><a name="p3801052183611"></a><a name="p3801052183611"></a>unsigned long long reserved[DCMI_HCCS_RES_FIELD_NUM];  // 64 fields are reserved for use.</p>
<p id="p980125217364"><a name="p980125217364"></a><a name="p980125217364"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="13.11%" headers="mcps1.2.5.1.3 "><p id="p10308155132311"><a name="p10308155132311"></a><a name="p10308155132311"></a>sizeof(struct dcmi_hccs_statistic_info_u64)</p>
</td>
<td class="cellrowborder" valign="top" width="24.09%" headers="mcps1.2.5.1.4 "><p id="p72181373246"><a name="p72181373246"></a><a name="p72181373246"></a>Obtains the statistics of HCCS packet transmission/reception and bit errors.</p>
<a name="ul15381435182416"></a><a name="ul15381435182416"></a><ul id="ul15381435182416"><li>Currently, the chip uses only the x4 mode and obtains the statistics of eight HDLC links (per device).</li><li>The statistics of each link contain three u64 integers, which are the number of transmitted packets, number of received packets, and number of received packets with CRC errors. The unit is flit.</li><li><strong id="b19600159131717"><a name="b19600159131717"></a><a name="b19600159131717"></a>tx_cnt</strong>: accumulated number of transmitted packets. The value range is 0 to 18,446,744,073,709,551,615.</li><li><strong id="b164946151178"><a name="b164946151178"></a><a name="b164946151178"></a>rx_cnt</strong>: accumulated number of received packets. The value range is 0 to 18,446,744,073,709,551,615.</li><li><strong id="b10722418191715"><a name="b10722418191715"></a><a name="b10722418191715"></a>crc_err_cnt</strong>: number of CRC errors. The value range is 0 to 18,446,744,073,709,551,615.</li><li><strong id="b14570122441714"><a name="b14570122441714"></a><a name="b14570122441714"></a>retry_cnt</strong>: number of packet transmission retries. The value range is 0 to 18,446,744,073,709,551,615.<a name="ul18352890486"></a><a name="ul18352890486"></a><ul id="ul18352890486"><li><strong id="b5873194611175"><a name="b5873194611175"></a><a name="b5873194611175"></a>0</strong>: no transmission retries</li><li>Another value: number of retries</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section1782016178717"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_hccs_statues status = {0};
unsigned int buf_size = sizeof(struct dcmi_hccs_statues);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_HCCS,
DCMI_HCCS_CMD_GET_STATUS, &status, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_EX\_COMPUTING Command<a name="EN-US_TOPIC_0000002515510498"></a>

**Prototype<a name="section251144503117"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section4511154520314"></a>**

Obtains the token value of the computing power.

**Parameter Description<a name="section195111645193117"></a>**

<a name="table145283455316"></a>
<table><thead align="left"><tr id="row963614518316"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p96361345163111"><a name="p96361345163111"></a><a name="p96361345163111"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p1963644563115"><a name="p1963644563115"></a><a name="p1963644563115"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p46361745193112"><a name="p46361745193112"></a><a name="p46361745193112"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p15636144519316"><a name="p15636144519316"></a><a name="p15636144519316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1663613450314"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p16367453317"><a name="p16367453317"></a><a name="p16367453317"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1863654517314"><a name="p1863654517314"></a><a name="p1863654517314"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p17636345203114"><a name="p17636345203114"></a><a name="p17636345203114"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p14636945193116"><a name="p14636945193116"></a><a name="p14636945193116"></a>Device ID. The supported IDs can be obtained by calling <strong id="b4086273123309"><a name="b4086273123309"></a><a name="b4086273123309"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row163617450316"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p126362454318"><a name="p126362454318"></a><a name="p126362454318"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p6636174518315"><a name="p6636174518315"></a><a name="p6636174518315"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p4636194553115"><a name="p4636194553115"></a><a name="p4636194553115"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1563674543113"><a name="p1563674543113"></a><a name="p1563674543113"></a>Chip ID, which can be obtained by calling <strong id="b156908955432949"><a name="b156908955432949"></a><a name="b156908955432949"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p36365456315"><a name="p36365456315"></a><a name="p36365456315"></a>NPU: [0, <strong id="b15343267618811"><a name="b15343267618811"></a><a name="b15343267618811"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row166363454319"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p16636145193116"><a name="p16636145193116"></a><a name="p16636145193116"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p6637545163119"><a name="p6637545163119"></a><a name="p6637545163119"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p20637104516316"><a name="p20637104516316"></a><a name="p20637104516316"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p16371245203115"><a name="p16371245203115"></a><a name="p16371245203115"></a>DCMI_MAIN_CMD_EX_COMPUTING</p>
</td>
</tr>
<tr id="row663754533112"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p106371145153114"><a name="p106371145153114"></a><a name="p106371145153114"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p5637144510311"><a name="p5637144510311"></a><a name="p5637144510311"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p106374457316"><a name="p106374457316"></a><a name="p106374457316"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p11637204512315"><a name="p11637204512315"></a><a name="p11637204512315"></a>DCMI_EX_COMPUTING_SUB_CMD_TOKEN</p>
</td>
</tr>
<tr id="row20637114553111"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1163734513119"><a name="p1163734513119"></a><a name="p1163734513119"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p17637545203112"><a name="p17637545203112"></a><a name="p17637545203112"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1163719452314"><a name="p1163719452314"></a><a name="p1163719452314"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p106372452314"><a name="p106372452314"></a><a name="p106372452314"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row146374453314"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p10637184563116"><a name="p10637184563116"></a><a name="p10637184563116"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p126373451313"><a name="p126373451313"></a><a name="p126373451313"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13637445163120"><a name="p13637445163120"></a><a name="p13637445163120"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p3637184518311"><a name="p3637184518311"></a><a name="p3637184518311"></a>Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section1551994503119"></a>**

<a name="table6533174517314"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b140406964272210"><a name="b140406964272210"></a><a name="b140406964272210"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section15209424870"></a>**

None

**Restrictions<a name="section1535162716712"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table353514454317"></a>
<table><thead align="left"><tr id="row263834543117"><th class="cellrowborder" valign="top" width="25.380000000000003%" id="mcps1.2.5.1.1"><p id="p166382458312"><a name="p166382458312"></a><a name="p166382458312"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="28.88%" id="mcps1.2.5.1.2"><p id="p16638645113120"><a name="p16638645113120"></a><a name="p16638645113120"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.69%" id="mcps1.2.5.1.3"><p id="p263819453310"><a name="p263819453310"></a><a name="p263819453310"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="27.05%" id="mcps1.2.5.1.4"><p id="p1638145183117"><a name="p1638145183117"></a><a name="p1638145183117"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1263884503118"><td class="cellrowborder" valign="top" width="25.380000000000003%" headers="mcps1.2.5.1.1 "><p id="p763884573120"><a name="p763884573120"></a><a name="p763884573120"></a>DCMI_EX_COMPUTING</p>
<p id="p3638184563117"><a name="p3638184563117"></a><a name="p3638184563117"></a>_SUB_CMD_TOKEN</p>
</td>
<td class="cellrowborder" valign="top" width="28.88%" headers="mcps1.2.5.1.2 "><p id="p1963817451315"><a name="p1963817451315"></a><a name="p1963817451315"></a>struct dcmi_computing_token_stru {</p>
<p id="p1863844515316"><a name="p1863844515316"></a><a name="p1863844515316"></a>float value;</p>
<p id="p126384453317"><a name="p126384453317"></a><a name="p126384453317"></a>u8 type;</p>
<p id="p1563804518310"><a name="p1563804518310"></a><a name="p1563804518310"></a>u8 reserve_c;</p>
<p id="p763874510313"><a name="p763874510313"></a><a name="p763874510313"></a>u16 reserve_s;</p>
<p id="p56381459316"><a name="p56381459316"></a><a name="p56381459316"></a>}</p>
<p id="p6638164513117"><a name="p6638164513117"></a><a name="p6638164513117"></a>a. <strong id="b11183290138811"><a name="b11183290138811"></a><a name="b11183290138811"></a>value</strong>: computing power</p>
<p id="p863819458316"><a name="p863819458316"></a><a name="p863819458316"></a>b. <strong id="b812485213452"><a name="b812485213452"></a><a name="b812485213452"></a>type</strong>: type value after the license BOM code is converted</p>
<p id="p20638345123117"><a name="p20638345123117"></a><a name="p20638345123117"></a>c. <strong id="b12900064418811"><a name="b12900064418811"></a><a name="b12900064418811"></a>reserve_c</strong>: reserved currently</p>
<p id="p1663810451310"><a name="p1663810451310"></a><a name="p1663810451310"></a>d. <strong id="b143329114612"><a name="b143329114612"></a><a name="b143329114612"></a>reserve_s</strong>: reserved currently</p>
</td>
<td class="cellrowborder" valign="top" width="18.69%" headers="mcps1.2.5.1.3 "><p id="p663854523113"><a name="p663854523113"></a><a name="p663854523113"></a>sizeof(dcmi_</p>
<p id="p46381445153118"><a name="p46381445153118"></a><a name="p46381445153118"></a>computing_token_stru)</p>
</td>
<td class="cellrowborder" valign="top" width="27.05%" headers="mcps1.2.5.1.4 "><p id="p1638144514312"><a name="p1638144514312"></a><a name="p1638144514312"></a>Obtains the token value of the computing power.</p>
<p id="p163864515312"><a name="p163864515312"></a><a name="p163864515312"></a>Value range: [0, 65535]</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section172981043978"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_computing_token_stru dcmi_computing_token = {0};
unsigned int buf_size = sizeof(struct dcmi_computing_token_stru);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_EX_COMPUTING,
DCMI_EX_COMPUTING_SUB_CMD_TOKEN, &dcmi_computing_token, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_VDEV\_MNG Command<a name="EN-US_TOPIC_0000002546910419"></a>

**Prototype<a name="section1189012593314"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section689185915314"></a>**

Manages virtual devices, including obtaining virtual device resource information, total SoC device resource information, and unused SoC device resource information.

**Parameter Description<a name="section4891659133117"></a>**

<a name="table69831559113114"></a>
<table><thead align="left"><tr id="row5221130183210"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1122220113216"><a name="p1122220113216"></a><a name="p1122220113216"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p142220033219"><a name="p142220033219"></a><a name="p142220033219"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p122222083218"><a name="p122222083218"></a><a name="p122222083218"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p1122217019327"><a name="p1122217019327"></a><a name="p1122217019327"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row5222507323"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p15222203328"><a name="p15222203328"></a><a name="p15222203328"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p112226020327"><a name="p112226020327"></a><a name="p112226020327"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p822218012323"><a name="p822218012323"></a><a name="p822218012323"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p15222107328"><a name="p15222107328"></a><a name="p15222107328"></a>Device ID. The supported IDs can be obtained by calling <strong id="b169138461233010"><a name="b169138461233010"></a><a name="b169138461233010"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row3222180143219"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p92225043213"><a name="p92225043213"></a><a name="p92225043213"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p62221307320"><a name="p62221307320"></a><a name="p62221307320"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p72229016329"><a name="p72229016329"></a><a name="p72229016329"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p162221608326"><a name="p162221608326"></a><a name="p162221608326"></a>Chip ID, which can be obtained by calling <strong id="b9238151812181"><a name="b9238151812181"></a><a name="b9238151812181"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p112221406324"><a name="p112221406324"></a><a name="p112221406324"></a>NPU: [0, <strong id="b6498110098652"><a name="b6498110098652"></a><a name="b6498110098652"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row12223019320"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p42221019320"><a name="p42221019320"></a><a name="p42221019320"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p52224019323"><a name="p52224019323"></a><a name="p52224019323"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p122228015326"><a name="p122228015326"></a><a name="p122228015326"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1622210113220"><a name="p1622210113220"></a><a name="p1622210113220"></a>DCMI_MAIN_CMD_VDEV_MNG</p>
</td>
</tr>
<tr id="row8222300322"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1222160143216"><a name="p1222160143216"></a><a name="p1222160143216"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p122222014322"><a name="p122222014322"></a><a name="p122222014322"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p14222140103211"><a name="p14222140103211"></a><a name="p14222140103211"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p72227073218"><a name="p72227073218"></a><a name="p72227073218"></a>typedef enum {</p>
<p id="p1222407325"><a name="p1222407325"></a><a name="p1222407325"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE,</p>
<p id="p52221309326"><a name="p52221309326"></a><a name="p52221309326"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE,</p>
<p id="p62221905329"><a name="p62221905329"></a><a name="p62221905329"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE,</p>
<p id="p1422215018326"><a name="p1422215018326"></a><a name="p1422215018326"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH,</p>
<p id="p722210163215"><a name="p722210163215"></a><a name="p722210163215"></a>DCMI_VMNG_SUB_CMD_MAX,</p>
<p id="p522260133219"><a name="p522260133219"></a><a name="p522260133219"></a>} DCMI_VDEV_MNG_SUB_CMD;</p>
<p id="p192221307329"><a name="p192221307329"></a><a name="p192221307329"></a><strong id="b1080353519497"><a name="b1080353519497"></a><a name="b1080353519497"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE</strong>: obtains resource information of a single virtual device.</p>
<p id="p172224010327"><a name="p172224010327"></a><a name="p172224010327"></a><strong id="b10507101611234"><a name="b10507101611234"></a><a name="b10507101611234"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE</strong>: obtains the total resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p2022214023217"><a name="p2022214023217"></a><a name="p2022214023217"></a><strong id="b518932922312"><a name="b518932922312"></a><a name="b518932922312"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE</strong>: obtains the unused resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p10223110173213"><a name="p10223110173213"></a><a name="p10223110173213"></a>Note:</p>
<p id="p122315003214"><a name="p122315003214"></a><a name="p122315003214"></a>The current API does not support the <strong id="b6411072668652"><a name="b6411072668652"></a><a name="b6411072668652"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH</strong> command.</p>
</td>
</tr>
<tr id="row182233017321"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p192231204324"><a name="p192231204324"></a><a name="p192231204324"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p152237093214"><a name="p152237093214"></a><a name="p152237093214"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p52231093215"><a name="p52231093215"></a><a name="p52231093215"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1722380113216"><a name="p1722380113216"></a><a name="p1722380113216"></a>See <a href="#table1499155916318">Table 1</a> for the <strong id="b15260839165617"><a name="b15260839165617"></a><a name="b15260839165617"></a>buf</strong> format that corresponds to <strong id="b6260339155611"><a name="b6260339155611"></a><a name="b6260339155611"></a>sub_cmd</strong>.</p>
</td>
</tr>
<tr id="row1822390123215"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p322311015323"><a name="p322311015323"></a><a name="p322311015323"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p02233013326"><a name="p02233013326"></a><a name="p02233013326"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p2223809324"><a name="p2223809324"></a><a name="p2223809324"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p4223100103216"><a name="p4223100103216"></a><a name="p4223100103216"></a>The returned result corresponds to the <strong id="b1918185812236"><a name="b1918185812236"></a><a name="b1918185812236"></a>buf</strong> structure size in <a href="#table1499155916318">Table 1</a>.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section189807595317"></a>**

<a name="table154712012328"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b102980203572212"><a name="b102980203572212"></a><a name="b102980203572212"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section88531421389"></a>**

When you query basic and resource information, if the corresponding product form is not supported, see the option description in  [Table 2](#table1567919386575)  for the returned value.

**Restrictions<a name="section194071571789"></a>**

- When this API is called,  **sub\_cmd**  must correspond to  [Table 1](#table1499155916318), and  **buf\_size**  indicates the size of the corresponding buffer data structure.
- To use this API to obtain resources, set the environment to the SR-IOV mode.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1499155916318"></a>
<table><thead align="left"><tr id="row922320103219"><th class="cellrowborder" valign="top" width="30.080000000000002%" id="mcps1.2.4.1.1"><p id="p1722319017323"><a name="p1722319017323"></a><a name="p1722319017323"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="43.46%" id="mcps1.2.4.1.2"><p id="p02235018328"><a name="p02235018328"></a><a name="p02235018328"></a>buf Format</p>
</th>
<th class="cellrowborder" valign="top" width="26.46%" id="mcps1.2.4.1.3"><p id="p1883611521712"><a name="p1883611521712"></a><a name="p1883611521712"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13223806324"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p112234015324"><a name="p112234015324"></a><a name="p112234015324"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p14223100143214"><a name="p14223100143214"></a><a name="p14223100143214"></a>struct DCMI_vdev_query_stru {</p>
<p id="p172234013218"><a name="p172234013218"></a><a name="p172234013218"></a>unsigned int vdev_id;</p>
<p id="p22234043220"><a name="p22234043220"></a><a name="p22234043220"></a>struct DCMI_vdev_query_info query_info;</p>
<p id="p1822313043218"><a name="p1822313043218"></a><a name="p1822313043218"></a>}</p>
<p id="p52239019325"><a name="p52239019325"></a><a name="p52239019325"></a><strong id="b1238515568581"><a name="b1238515568581"></a><a name="b1238515568581"></a>vdev_id</strong> indicates the virtual device ID, which is used as the input information.</p>
<p id="p1622316033219"><a name="p1622316033219"></a><a name="p1622316033219"></a><strong id="b868613597583"><a name="b868613597583"></a><a name="b868613597583"></a>query_info</strong> indicates the queried virtual device information. Its structure is as follows:</p>
<p id="p1722340183213"><a name="p1722340183213"></a><a name="p1722340183213"></a>#define DCMI_VDEV_RES_NAME_LEN 16</p>
<p id="p322380103210"><a name="p322380103210"></a><a name="p322380103210"></a>struct DCMI_vdev_query_info {</p>
<p id="p172237014328"><a name="p172237014328"></a><a name="p172237014328"></a>char name[DCMI_VDEV_RES_NAME_LEN];</p>
<p id="p6223110183211"><a name="p6223110183211"></a><a name="p6223110183211"></a>unsigned int status;</p>
<p id="p62231809326"><a name="p62231809326"></a><a name="p62231809326"></a>unsigned int is_container_used;</p>
<p id="p32236018325"><a name="p32236018325"></a><a name="p32236018325"></a>unsigned int vfid;</p>
<p id="p92238053213"><a name="p92238053213"></a><a name="p92238053213"></a>unsigned int reserved;</p>
<p id="p1322370113218"><a name="p1322370113218"></a><a name="p1322370113218"></a>unsigned long long container_id;</p>
<p id="p172231004322"><a name="p172231004322"></a><a name="p172231004322"></a>struct DCMI_base_resource base;</p>
<p id="p1922316011328"><a name="p1922316011328"></a><a name="p1922316011328"></a>struct DCMI_computing_resource computing;</p>
<p id="p172231502321"><a name="p172231502321"></a><a name="p172231502321"></a>struct DCMI_media_resource media;</p>
<p id="p322313010325"><a name="p322313010325"></a><a name="p322313010325"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul1512412249211"></a><a name="ul1512412249211"></a><ul id="ul1512412249211"><li><strong id="b167672017122517"><a name="b167672017122517"></a><a name="b167672017122517"></a>name</strong>: name specified during virtual device creation.</li><li><strong id="b82491220132510"><a name="b82491220132510"></a><a name="b82491220132510"></a>status</strong>: (reserved) virtual device status.</li><li><strong id="b1334113312913"><a name="b1334113312913"></a><a name="b1334113312913"></a>is_container_used</strong>: indicates whether the current container is used.</li><li><strong id="b598417452913"><a name="b598417452913"></a><a name="b598417452913"></a>vfid</strong>: sequence number of the VF used by the virtual device.</li><li><strong id="b136710802910"><a name="b136710802910"></a><a name="b136710802910"></a>reserved</strong>: reserved field, which is not used currently.</li><li><strong id="b848516913295"><a name="b848516913295"></a><a name="b848516913295"></a>container_id</strong>: container ID.</li><li><strong id="b52601411122916"><a name="b52601411122916"></a><a name="b52601411122916"></a>base</strong>: basic information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b05821272299"><a name="b05821272299"></a><a name="b05821272299"></a>computing</strong>: computing resource information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1677183812306"><a name="b1677183812306"></a><a name="b1677183812306"></a>media</strong>: media resource information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
<tr id="row52243093216"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p1422412015326"><a name="p1422412015326"></a><a name="p1422412015326"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p12241005325"><a name="p12241005325"></a><a name="p12241005325"></a>#define DCMI_SOC_SPLIT_MAX 32</p>
<p id="p18224120193213"><a name="p18224120193213"></a><a name="p18224120193213"></a>struct DCMI_soc_total_resource {</p>
<p id="p1622420163211"><a name="p1622420163211"></a><a name="p1622420163211"></a>unsigned int vdev_num;</p>
<p id="p022415023211"><a name="p022415023211"></a><a name="p022415023211"></a>unsigned int vdev_id[DCMI_SOC_SPLIT_MAX];</p>
<p id="p62241015329"><a name="p62241015329"></a><a name="p62241015329"></a>unsigned int vfg_num;</p>
<p id="p162241007321"><a name="p162241007321"></a><a name="p162241007321"></a>unsigned int vfg_bitmap;</p>
<p id="p13224170163215"><a name="p13224170163215"></a><a name="p13224170163215"></a>struct DCMI_base_resource base;</p>
<p id="p192246033213"><a name="p192246033213"></a><a name="p192246033213"></a>struct DCMI_computing_resource computing;</p>
<p id="p182246093217"><a name="p182246093217"></a><a name="p182246093217"></a>struct DCMI_media_resource media;</p>
<p id="p1522415023214"><a name="p1522415023214"></a><a name="p1522415023214"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul20252101215414"></a><a name="ul20252101215414"></a><ul id="ul20252101215414"><li><strong id="b2828104443012"><a name="b2828104443012"></a><a name="b2828104443012"></a>vdev_num</strong>: number of virtual devices in the specified SoC device.</li><li><strong id="b4243152723117"><a name="b4243152723117"></a><a name="b4243152723117"></a>vdev_id</strong>: virtual device ID.</li><li><strong id="b147132029183119"><a name="b147132029183119"></a><a name="b147132029183119"></a>vfg_num</strong>: total number of VFGs in a SoC device. Not supported currently.</li><li><strong id="b2168028123219"><a name="b2168028123219"></a><a name="b2168028123219"></a>vfg_bitmap</strong>: VFG bitmap of the device. Each bit corresponds to a VFG. The value <strong id="b616820282321"><a name="b616820282321"></a><a name="b616820282321"></a>1</strong> indicates valid. Not supported currently.</li><li><strong id="b416119319337"><a name="b416119319337"></a><a name="b416119319337"></a>base</strong>: general basic information of the specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b497011168335"><a name="b497011168335"></a><a name="b497011168335"></a>computing</strong>: total computing resource information of the specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1964013375337"><a name="b1964013375337"></a><a name="b1964013375337"></a>media</strong>: total media resource information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
<tr id="row62242063213"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p02241202328"><a name="p02241202328"></a><a name="p02241202328"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p3224200143215"><a name="p3224200143215"></a><a name="p3224200143215"></a>struct DCMI_soc_free_resource {</p>
<p id="p5224130133213"><a name="p5224130133213"></a><a name="p5224130133213"></a>unsigned int vfg_num;</p>
<p id="p62249010329"><a name="p62249010329"></a><a name="p62249010329"></a>unsigned int vfg_bitmap;</p>
<p id="p1922417023219"><a name="p1922417023219"></a><a name="p1922417023219"></a>struct DCMI_base_resource base;</p>
<p id="p7224106328"><a name="p7224106328"></a><a name="p7224106328"></a>struct DCMI_computing_resource computing;</p>
<p id="p922413012328"><a name="p922413012328"></a><a name="p922413012328"></a>struct DCMI_media_resource media;</p>
<p id="p122411063216"><a name="p122411063216"></a><a name="p122411063216"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul14775720049"></a><a name="ul14775720049"></a><ul id="ul14775720049"><li><strong id="b11541443153316"><a name="b11541443153316"></a><a name="b11541443153316"></a>vfg_num</strong>: number of unused VFGs in a SoC device. Not supported currently.</li><li><strong id="b14961310142313"><a name="b14961310142313"></a><a name="b14961310142313"></a>vfg_bitmap</strong>: VFG bitmap of the device. Each bit corresponds to a VFG. The value <strong id="b1597141014235"><a name="b1597141014235"></a><a name="b1597141014235"></a>1</strong> indicates an unused VFG. Not supported currently.</li><li><strong id="b1572419920357"><a name="b1572419920357"></a><a name="b1572419920357"></a>base</strong>: unused basic information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b213291913358"><a name="b213291913358"></a><a name="b213291913358"></a>computing</strong>: The specified SoC device does not use computing resources. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1129119561364"><a name="b1129119561364"></a><a name="b1129119561364"></a>media</strong>: remaining media resource information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
<tr id="row1622520123217"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p122590133210"><a name="p122590133210"></a><a name="p122590133210"></a>DCMI_VMNG_SUB_CMD_GET_TOPS_PERCENTAGE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p112254063216"><a name="p112254063216"></a><a name="p112254063216"></a>/* for compute group ratio */</p>
<p id="p142251602327"><a name="p142251602327"></a><a name="p142251602327"></a>struct DCMI_soc_vdev_ratio {</p>
<p id="p82256012324"><a name="p82256012324"></a><a name="p82256012324"></a>unsigned int vdev_id;</p>
<p id="p922510123214"><a name="p922510123214"></a><a name="p922510123214"></a>unsigned int ratio;</p>
<p id="p142253033219"><a name="p142253033219"></a><a name="p142253033219"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul17751192613416"></a><a name="ul17751192613416"></a><ul id="ul17751192613416"><li><strong id="b75309322518"><a name="b75309322518"></a><a name="b75309322518"></a>vdev_id</strong>: virtual device ID.</li><li><strong id="b1183681912372"><a name="b1183681912372"></a><a name="b1183681912372"></a>ratio</strong>: the proportion of computing resources</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2**  Basic and resource information structure

<a name="table1567919386575"></a>
<table><thead align="left"><tr id="row12671173813574"><th class="cellrowborder" valign="top" width="6.823942288945214%" id="mcps1.2.6.1.1"><p id="p186708382574"><a name="p186708382574"></a><a name="p186708382574"></a>Information Type</p>
</th>
<th class="cellrowborder" valign="top" width="37.74614934685124%" id="mcps1.2.6.1.2"><p id="p5670138195718"><a name="p5670138195718"></a><a name="p5670138195718"></a>Structure</p>
</th>
<th class="cellrowborder" valign="top" width="12.331838565022421%" id="mcps1.2.6.1.3"><p id="p19670153855717"><a name="p19670153855717"></a><a name="p19670153855717"></a>Option</p>
</th>
<th class="cellrowborder" valign="top" width="22.44102164164554%" id="mcps1.2.6.1.4"><p id="p136702038145711"><a name="p136702038145711"></a><a name="p136702038145711"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="20.65704815753558%" id="mcps1.2.6.1.5"><p id="p18670113885713"><a name="p18670113885713"></a><a name="p18670113885713"></a>Supported Form</p>
</th>
</tr>
</thead>
<tbody><tr id="row967163815572"><td class="cellrowborder" rowspan="5" valign="top" width="6.823942288945214%" headers="mcps1.2.6.1.1 "><p id="p9671163818579"><a name="p9671163818579"></a><a name="p9671163818579"></a>Basic information</p>
</td>
<td class="cellrowborder" rowspan="5" valign="top" width="37.74614934685124%" headers="mcps1.2.6.1.2 "><p id="p5671238185711"><a name="p5671238185711"></a><a name="p5671238185711"></a>#define DCMI_VDEV_FOR_RESERVE 32</p>
<p id="p4671153805719"><a name="p4671153805719"></a><a name="p4671153805719"></a>struct DCMI_base_resource {</p>
<p id="p1167116387573"><a name="p1167116387573"></a><a name="p1167116387573"></a>unsigned long long token;</p>
<p id="p76711238175711"><a name="p76711238175711"></a><a name="p76711238175711"></a>unsigned long long token_max;</p>
<p id="p2671183814573"><a name="p2671183814573"></a><a name="p2671183814573"></a>unsigned long long task_timeout;</p>
<p id="p166711538165713"><a name="p166711538165713"></a><a name="p166711538165713"></a>unsigned int vfg_id;</p>
<p id="p156711238165715"><a name="p156711238165715"></a><a name="p156711238165715"></a>unsigned char vip_mode;</p>
<p id="p1967133810574"><a name="p1967133810574"></a><a name="p1967133810574"></a>unsigned char reserved[DCMI_VDEV_FOR_RESERVE - 1];</p>
<p id="p66719389572"><a name="p66719389572"></a><a name="p66719389572"></a>/* bytes aligned */</p>
<p id="p18671143811570"><a name="p18671143811570"></a><a name="p18671143811570"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="12.331838565022421%" headers="mcps1.2.6.1.3 "><p id="p106714389577"><a name="p106714389577"></a><a name="p106714389577"></a>token</p>
</td>
<td class="cellrowborder" valign="top" width="22.44102164164554%" headers="mcps1.2.6.1.4 "><p id="p7671143895715"><a name="p7671143895715"></a><a name="p7671143895715"></a>Number of cycles taken by virtual devices when time-division multiplexing (TDM) is applied to the VFG.</p>
<p id="p1567163817574"><a name="p1567163817574"></a><a name="p1567163817574"></a>If this option is not supported, <strong id="b9293115610112"><a name="b9293115610112"></a><a name="b9293115610112"></a>0xFFFFFFFFFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" width="20.65704815753558%" headers="mcps1.2.6.1.5 "><p id="p187612025916"><a name="p187612025916"></a><a name="p187612025916"></a>None</p>
</td>
</tr>
<tr id="row1267112386572"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p12671143814574"><a name="p12671143814574"></a><a name="p12671143814574"></a>token_max</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p18671113895711"><a name="p18671113895711"></a><a name="p18671113895711"></a>Maximum number of cycles taken by virtual devices when TDM is applied to the VFG.</p>
<p id="p0671838185714"><a name="p0671838185714"></a><a name="p0671838185714"></a>If this option is not supported, <strong id="b1887717971217"><a name="b1887717971217"></a><a name="b1887717971217"></a>0xFFFFFFFFFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p15611358105812"><a name="p15611358105812"></a><a name="p15611358105812"></a>None</p>
</td>
</tr>
<tr id="row667193855713"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p17671133825711"><a name="p17671133825711"></a><a name="p17671133825711"></a>task_timeout</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p86715388572"><a name="p86715388572"></a><a name="p86715388572"></a>Number of VFG task timeout cycles.</p>
<p id="p13671638135716"><a name="p13671638135716"></a><a name="p13671638135716"></a>If this option is not supported, <strong id="b141031224181218"><a name="b141031224181218"></a><a name="b141031224181218"></a>0xFFFFFFFFFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p173119569582"><a name="p173119569582"></a><a name="p173119569582"></a>None</p>
</td>
</tr>
<tr id="row4672133819576"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1467223815718"><a name="p1467223815718"></a><a name="p1467223815718"></a>vfg_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p2672143875710"><a name="p2672143875710"></a><a name="p2672143875710"></a>VFG ID of a virtual device.</p>
<p id="p18672143814572"><a name="p18672143814572"></a><a name="p18672143814572"></a>Normal values: –1, 0–5</p>
<p id="p967233812572"><a name="p967233812572"></a><a name="p967233812572"></a>If this option is not supported, <strong id="b17637835172218"><a name="b17637835172218"></a><a name="b17637835172218"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1067210383579"><a name="p1067210383579"></a><a name="p1067210383579"></a>All products</p>
</td>
</tr>
<tr id="row6672153825717"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p967216381576"><a name="p967216381576"></a><a name="p967216381576"></a>vip_mode</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p46721738155718"><a name="p46721738155718"></a><a name="p46721738155718"></a>VFG mode of the virtual device. The values are as follows:</p>
<a name="ul067253810573"></a><a name="ul067253810573"></a><ul id="ul067253810573"><li><strong id="b3183423748652"><a name="b3183423748652"></a><a name="b3183423748652"></a>0</strong>: Virtual devices share a VFG, which may cause contention for shared resources and affect the scheduling delay during virtual device switchover.</li><li><strong id="b18046224888652"><a name="b18046224888652"></a><a name="b18046224888652"></a>1</strong>: A virtual device exclusively occupies a VFG and uses all resources of the VFG. Other virtual devices cannot share the VFG.</li></ul>
<p id="p19672153817577"><a name="p19672153817577"></a><a name="p19672153817577"></a>If this option is not supported, <strong id="b18850226668652"><a name="b18850226668652"></a><a name="b18850226668652"></a>0xFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1567203815572"><a name="p1567203815572"></a><a name="p1567203815572"></a>All products</p>
</td>
</tr>
<tr id="row267333811572"><td class="cellrowborder" rowspan="20" valign="top" width="6.823942288945214%" headers="mcps1.2.6.1.1 "><p id="p767293818576"><a name="p767293818576"></a><a name="p767293818576"></a>Computing power resource information</p>
</td>
<td class="cellrowborder" rowspan="20" valign="top" width="37.74614934685124%" headers="mcps1.2.6.1.2 "><p id="p196721038195711"><a name="p196721038195711"></a><a name="p196721038195711"></a>struct DCMI_computing_resource {</p>
<p id="p19672183865720"><a name="p19672183865720"></a><a name="p19672183865720"></a>/* accelator resource */</p>
<p id="p15672163895719"><a name="p15672163895719"></a><a name="p15672163895719"></a>float aic;</p>
<p id="p26726380573"><a name="p26726380573"></a><a name="p26726380573"></a>float aiv;</p>
<p id="p26721338195715"><a name="p26721338195715"></a><a name="p26721338195715"></a>unsigned short dsa;</p>
<p id="p1367253875712"><a name="p1367253875712"></a><a name="p1367253875712"></a>unsigned short rtsq;</p>
<p id="p1967215383571"><a name="p1967215383571"></a><a name="p1967215383571"></a>unsigned short acsq;</p>
<p id="p567263818578"><a name="p567263818578"></a><a name="p567263818578"></a>unsigned short cdqm;</p>
<p id="p166721384576"><a name="p166721384576"></a><a name="p166721384576"></a>unsigned short c_core;</p>
<p id="p116721938195711"><a name="p116721938195711"></a><a name="p116721938195711"></a>unsigned short ffts;</p>
<p id="p1967253835717"><a name="p1967253835717"></a><a name="p1967253835717"></a>unsigned short sdma;</p>
<p id="p126721438105713"><a name="p126721438105713"></a><a name="p126721438105713"></a>unsigned short pcie_dma;</p>
<p id="p19672133815573"><a name="p19672133815573"></a><a name="p19672133815573"></a>/* memory resource, MB as unit */</p>
<p id="p176724385574"><a name="p176724385574"></a><a name="p176724385574"></a>unsigned long long memory_size;</p>
<p id="p46738380575"><a name="p46738380575"></a><a name="p46738380575"></a>/* id resource */</p>
<p id="p1267383815711"><a name="p1267383815711"></a><a name="p1267383815711"></a>unsigned int event_id;</p>
<p id="p767363810576"><a name="p767363810576"></a><a name="p767363810576"></a>unsigned int notify_id;</p>
<p id="p36731838205712"><a name="p36731838205712"></a><a name="p36731838205712"></a>unsigned int stream_id;</p>
<p id="p1667314386574"><a name="p1667314386574"></a><a name="p1667314386574"></a>unsigned int model_id;</p>
<p id="p06731938125713"><a name="p06731938125713"></a><a name="p06731938125713"></a>/* cpu resource */</p>
<p id="p1867323817573"><a name="p1867323817573"></a><a name="p1867323817573"></a>unsigned short topic_schedule_aicpu;</p>
<p id="p8673438145717"><a name="p8673438145717"></a><a name="p8673438145717"></a>unsigned short host_ctrl_cpu;</p>
<p id="p66731338145710"><a name="p66731338145710"></a><a name="p66731338145710"></a>unsigned short host_aicpu;</p>
<p id="p7673738165718"><a name="p7673738165718"></a><a name="p7673738165718"></a>unsigned short device_aicpu;</p>
<p id="p1673438175711"><a name="p1673438175711"></a><a name="p1673438175711"></a>unsigned short topic_ctrl_cpu_slot;</p>
<p id="p12673193885714"><a name="p12673193885714"></a><a name="p12673193885714"></a>unsigned char reserved[DCMI_VDEV_FOR_RESERVE];</p>
<p id="p106731638205718"><a name="p106731638205718"></a><a name="p106731638205718"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="12.331838565022421%" headers="mcps1.2.6.1.3 "><p id="p136738381571"><a name="p136738381571"></a><a name="p136738381571"></a>aic</p>
</td>
<td class="cellrowborder" valign="top" width="22.44102164164554%" headers="mcps1.2.6.1.4 "><p id="p1067333820577"><a name="p1067333820577"></a><a name="p1067333820577"></a>Number of AI Cores</p>
<p id="p136736384570"><a name="p136736384570"></a><a name="p136736384570"></a>If this option is not supported, <strong id="b10675346448652"><a name="b10675346448652"></a><a name="b10675346448652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" width="20.65704815753558%" headers="mcps1.2.6.1.5 "><p id="p11673838135712"><a name="p11673838135712"></a><a name="p11673838135712"></a>None</p>
</td>
</tr>
<tr id="row467333810579"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p36739385576"><a name="p36739385576"></a><a name="p36739385576"></a>aiv</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p867312386575"><a name="p867312386575"></a><a name="p867312386575"></a>ai_vector number.</p>
<p id="p06733389573"><a name="p06733389573"></a><a name="p06733389573"></a>If this option is not supported, <strong id="b8703070938652"><a name="b8703070938652"></a><a name="b8703070938652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p86731338105714"><a name="p86731338105714"></a><a name="p86731338105714"></a>None</p>
</td>
</tr>
<tr id="row176732383574"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p166731438125716"><a name="p166731438125716"></a><a name="p166731438125716"></a>dsa</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1673123816571"><a name="p1673123816571"></a><a name="p1673123816571"></a>dsa number.</p>
<p id="p1867383820578"><a name="p1867383820578"></a><a name="p1867383820578"></a>If this option is not supported, <strong id="b10347266708652"><a name="b10347266708652"></a><a name="b10347266708652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p12673193820576"><a name="p12673193820576"></a><a name="p12673193820576"></a>None</p>
</td>
</tr>
<tr id="row1267413845715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p116741380572"><a name="p116741380572"></a><a name="p116741380572"></a>rtsq</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p16674193816577"><a name="p16674193816577"></a><a name="p16674193816577"></a>rtsq number.</p>
<p id="p6674123817576"><a name="p6674123817576"></a><a name="p6674123817576"></a>If this option is not supported, <strong id="b18735239578652"><a name="b18735239578652"></a><a name="b18735239578652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p76741838175711"><a name="p76741838175711"></a><a name="p76741838175711"></a>None</p>
</td>
</tr>
<tr id="row1767473805718"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p166741038115716"><a name="p166741038115716"></a><a name="p166741038115716"></a>acsq</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p06741238195712"><a name="p06741238195712"></a><a name="p06741238195712"></a>acsq number.</p>
<p id="p15674153825710"><a name="p15674153825710"></a><a name="p15674153825710"></a>If this option is not supported, <strong id="b12999687618652"><a name="b12999687618652"></a><a name="b12999687618652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p867413819572"><a name="p867413819572"></a><a name="p867413819572"></a>None</p>
</td>
</tr>
<tr id="row156741238175715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1674193819578"><a name="p1674193819578"></a><a name="p1674193819578"></a>cdqm</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1167473825713"><a name="p1167473825713"></a><a name="p1167473825713"></a>cdqm number.</p>
<p id="p10674163805713"><a name="p10674163805713"></a><a name="p10674163805713"></a>If this option is not supported, <strong id="b8607998558652"><a name="b8607998558652"></a><a name="b8607998558652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p20674138125712"><a name="p20674138125712"></a><a name="p20674138125712"></a>None</p>
</td>
</tr>
<tr id="row467433816573"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1767433816575"><a name="p1767433816575"></a><a name="p1767433816575"></a>c_core</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p16674173819570"><a name="p16674173819570"></a><a name="p16674173819570"></a>cdqm number.</p>
<p id="p1267413382577"><a name="p1267413382577"></a><a name="p1267413382577"></a>If this option is not supported, <strong id="b4842521988652"><a name="b4842521988652"></a><a name="b4842521988652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p15674123816576"><a name="p15674123816576"></a><a name="p15674123816576"></a>None</p>
</td>
</tr>
<tr id="row26759386571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p7674123845714"><a name="p7674123845714"></a><a name="p7674123845714"></a>ffts</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p146747385578"><a name="p146747385578"></a><a name="p146747385578"></a>ffts number.</p>
<p id="p1267418384579"><a name="p1267418384579"></a><a name="p1267418384579"></a>If this option is not supported, <strong id="b1958743112344"><a name="b1958743112344"></a><a name="b1958743112344"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p967414386579"><a name="p967414386579"></a><a name="p967414386579"></a>None</p>
</td>
</tr>
<tr id="row367563875720"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p46751438135714"><a name="p46751438135714"></a><a name="p46751438135714"></a>sdma</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p13675103855718"><a name="p13675103855718"></a><a name="p13675103855718"></a>Number of SDMA channels.</p>
<p id="p1667583815710"><a name="p1667583815710"></a><a name="p1667583815710"></a>If this option is not supported, <strong id="b51119418364"><a name="b51119418364"></a><a name="b51119418364"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1567523814577"><a name="p1567523814577"></a><a name="p1567523814577"></a>None</p>
</td>
</tr>
<tr id="row11675133816571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p20675123815719"><a name="p20675123815719"></a><a name="p20675123815719"></a>pcie_dma</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p156755383576"><a name="p156755383576"></a><a name="p156755383576"></a>Number of PCIe DMA channels.</p>
<p id="p16759388577"><a name="p16759388577"></a><a name="p16759388577"></a>If this option is not supported, <strong id="b187237488369"><a name="b187237488369"></a><a name="b187237488369"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p16756383578"><a name="p16756383578"></a><a name="p16756383578"></a>None</p>
</td>
</tr>
<tr id="row196751338105719"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p467523895720"><a name="p467523895720"></a><a name="p467523895720"></a>memory_size</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p5675738195717"><a name="p5675738195717"></a><a name="p5675738195717"></a>Memory size, in MB.</p>
<p id="p1267583813577"><a name="p1267583813577"></a><a name="p1267583813577"></a>If this option is not supported, <strong id="b8831127408652"><a name="b8831127408652"></a><a name="b8831127408652"></a>0xFFFFFFFFFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p7675538155718"><a name="p7675538155718"></a><a name="p7675538155718"></a>All products</p>
</td>
</tr>
<tr id="row66751338105710"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p067553811578"><a name="p067553811578"></a><a name="p067553811578"></a>event_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p8675173805712"><a name="p8675173805712"></a><a name="p8675173805712"></a>Number of event IDs.</p>
<p id="p167514389579"><a name="p167514389579"></a><a name="p167514389579"></a>If this option is not supported, <strong id="b2681938408652"><a name="b2681938408652"></a><a name="b2681938408652"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p12675838185714"><a name="p12675838185714"></a><a name="p12675838185714"></a>None</p>
</td>
</tr>
<tr id="row18676163815574"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p16675163816579"><a name="p16675163816579"></a><a name="p16675163816579"></a>notify_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p6675438145713"><a name="p6675438145713"></a><a name="p6675438145713"></a>Number of notify IDs.</p>
<p id="p14675173855720"><a name="p14675173855720"></a><a name="p14675173855720"></a>If this option is not supported, <strong id="b8416560778652"><a name="b8416560778652"></a><a name="b8416560778652"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p967583813571"><a name="p967583813571"></a><a name="p967583813571"></a>None</p>
</td>
</tr>
<tr id="row3676738195712"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1067613865715"><a name="p1067613865715"></a><a name="p1067613865715"></a>stream_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p967603825710"><a name="p967603825710"></a><a name="p967603825710"></a>Number of stream IDs.</p>
<p id="p5676183835711"><a name="p5676183835711"></a><a name="p5676183835711"></a>If this option is not supported, <strong id="b10076075788652"><a name="b10076075788652"></a><a name="b10076075788652"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p36769387575"><a name="p36769387575"></a><a name="p36769387575"></a>None</p>
</td>
</tr>
<tr id="row13676538155714"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1367613381570"><a name="p1367613381570"></a><a name="p1367613381570"></a>model_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p467617388576"><a name="p467617388576"></a><a name="p467617388576"></a>Number of model IDs.</p>
<p id="p367643811573"><a name="p367643811573"></a><a name="p367643811573"></a>If this option is not supported, <strong id="b6749930248652"><a name="b6749930248652"></a><a name="b6749930248652"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p367673875710"><a name="p367673875710"></a><a name="p367673875710"></a>None</p>
</td>
</tr>
<tr id="row86761838195713"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p15676138115719"><a name="p15676138115719"></a><a name="p15676138115719"></a>topic_schedule_aicpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p116761938125713"><a name="p116761938125713"></a><a name="p116761938125713"></a>Number of topic schedule AI CPUs.</p>
<p id="p196761738195714"><a name="p196761738195714"></a><a name="p196761738195714"></a>If this option is not supported, <strong id="b20859224688652"><a name="b20859224688652"></a><a name="b20859224688652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1967683885717"><a name="p1967683885717"></a><a name="p1967683885717"></a>None</p>
</td>
</tr>
<tr id="row16761038115716"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1067693895712"><a name="p1067693895712"></a><a name="p1067693895712"></a>host_ctrl_cpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p206761338125711"><a name="p206761338125711"></a><a name="p206761338125711"></a>Number of host-side Ctrl CPUs.</p>
<p id="p8676113819574"><a name="p8676113819574"></a><a name="p8676113819574"></a>If this option is not supported, <strong id="b16813957988652"><a name="b16813957988652"></a><a name="b16813957988652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p116761638175712"><a name="p116761638175712"></a><a name="p116761638175712"></a>None</p>
</td>
</tr>
<tr id="row767623812571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1467612383573"><a name="p1467612383573"></a><a name="p1467612383573"></a>host_ai_cpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1567643895711"><a name="p1567643895711"></a><a name="p1567643895711"></a>Number of host-side AI CPUs.</p>
<p id="p767616383579"><a name="p767616383579"></a><a name="p767616383579"></a>If this option is not supported, <strong id="b14893185494012"><a name="b14893185494012"></a><a name="b14893185494012"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p13676203835716"><a name="p13676203835716"></a><a name="p13676203835716"></a>None</p>
</td>
</tr>
<tr id="row186770380575"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p116768385577"><a name="p116768385577"></a><a name="p116768385577"></a>device_aicpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p36771383578"><a name="p36771383578"></a><a name="p36771383578"></a>Number of device-side AI CPUs.</p>
<p id="p13677838155714"><a name="p13677838155714"></a><a name="p13677838155714"></a>If this option is not supported, <strong id="b15958220178652"><a name="b15958220178652"></a><a name="b15958220178652"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1365011248219"><a name="p1365011248219"></a><a name="p1365011248219"></a>All products</p>
</td>
</tr>
<tr id="row267711388572"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p116771038155716"><a name="p116771038155716"></a><a name="p116771038155716"></a>topic_ctrl_cpu_slot</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1467783885710"><a name="p1467783885710"></a><a name="p1467783885710"></a>Number of topic Ctrl CPU slots.</p>
<p id="p106771138145716"><a name="p106771138145716"></a><a name="p106771138145716"></a>If this option is not supported, <strong id="b4166207134111"><a name="b4166207134111"></a><a name="b4166207134111"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p867713818571"><a name="p867713818571"></a><a name="p867713818571"></a>None</p>
</td>
</tr>
<tr id="row156771238105720"><td class="cellrowborder" rowspan="6" valign="top" width="6.823942288945214%" headers="mcps1.2.6.1.1 "><p id="p567733875712"><a name="p567733875712"></a><a name="p567733875712"></a>Media resource information</p>
</td>
<td class="cellrowborder" rowspan="6" valign="top" width="37.74614934685124%" headers="mcps1.2.6.1.2 "><p id="p1667733875711"><a name="p1667733875711"></a><a name="p1667733875711"></a>struct DCMI_media_resource {</p>
<p id="p14677153810570"><a name="p14677153810570"></a><a name="p14677153810570"></a>/* dvpp resource */</p>
<p id="p20677538135717"><a name="p20677538135717"></a><a name="p20677538135717"></a>float jpegd;</p>
<p id="p9677638175718"><a name="p9677638175718"></a><a name="p9677638175718"></a>float jpege;</p>
<p id="p16677183810572"><a name="p16677183810572"></a><a name="p16677183810572"></a>float vpc;</p>
<p id="p156771387571"><a name="p156771387571"></a><a name="p156771387571"></a>float vdec;</p>
<p id="p10677123819571"><a name="p10677123819571"></a><a name="p10677123819571"></a>float pngd;</p>
<p id="p136775385571"><a name="p136775385571"></a><a name="p136775385571"></a>float venc;</p>
<p id="p18677153835718"><a name="p18677153835718"></a><a name="p18677153835718"></a>unsigned char reserved[DCMI_VDEV_FOR_RESERVE];</p>
<p id="p17677133805710"><a name="p17677133805710"></a><a name="p17677133805710"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="12.331838565022421%" headers="mcps1.2.6.1.3 "><p id="p176771038135719"><a name="p176771038135719"></a><a name="p176771038135719"></a>jpegd</p>
</td>
<td class="cellrowborder" valign="top" width="22.44102164164554%" headers="mcps1.2.6.1.4 "><p id="p156773389574"><a name="p156773389574"></a><a name="p156773389574"></a>Number of DVPP JPEGDs.</p>
<p id="p66771738125710"><a name="p66771738125710"></a><a name="p66771738125710"></a>If this option is not supported, <strong id="b9263764778652"><a name="b9263764778652"></a><a name="b9263764778652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" rowspan="4" valign="top" width="20.65704815753558%" headers="mcps1.2.6.1.5 "><p id="p1124182732116"><a name="p1124182732116"></a><a name="p1124182732116"></a>All products</p>
</td>
</tr>
<tr id="row46781738105717"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p4677203855713"><a name="p4677203855713"></a><a name="p4677203855713"></a>jpege</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1667883814577"><a name="p1667883814577"></a><a name="p1667883814577"></a>Number of DVPP JPEGEs.</p>
<p id="p18678438105719"><a name="p18678438105719"></a><a name="p18678438105719"></a>If this option is not supported, <strong id="b17668205828652"><a name="b17668205828652"></a><a name="b17668205828652"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row1867803865715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p16678113885710"><a name="p16678113885710"></a><a name="p16678113885710"></a>vpc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p10678103815712"><a name="p10678103815712"></a><a name="p10678103815712"></a>Number of DVPP VPCs.</p>
<p id="p3678138145714"><a name="p3678138145714"></a><a name="p3678138145714"></a>If this option is not supported, <strong id="b1111843228652"><a name="b1111843228652"></a><a name="b1111843228652"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row867813895715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1967863818575"><a name="p1967863818575"></a><a name="p1967863818575"></a>vdev</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1167803818577"><a name="p1167803818577"></a><a name="p1167803818577"></a>Number of DVPP VDECs.</p>
<p id="p1267893810577"><a name="p1267893810577"></a><a name="p1267893810577"></a>If this option is not supported, <strong id="b18600068908652"><a name="b18600068908652"></a><a name="b18600068908652"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row767833815573"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p17678123855719"><a name="p17678123855719"></a><a name="p17678123855719"></a>pngd</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p146785381571"><a name="p146785381571"></a><a name="p146785381571"></a>Number of DVPP PNGDs.</p>
<p id="p5678038165711"><a name="p5678038165711"></a><a name="p5678038165711"></a>If this option is not supported, <strong id="b19682008038652"><a name="b19682008038652"></a><a name="b19682008038652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p11678143812572"><a name="p11678143812572"></a><a name="p11678143812572"></a>None</p>
</td>
</tr>
<tr id="row16679103812577"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p166787387572"><a name="p166787387572"></a><a name="p166787387572"></a>venc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p76781738195714"><a name="p76781738195714"></a><a name="p76781738195714"></a>Number of DVPP VENCs.</p>
<p id="p14678103855713"><a name="p14678103855713"></a><a name="p14678103855713"></a>If this option is not supported, <strong id="b10766722978652"><a name="b10766722978652"></a><a name="b10766722978652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p11231730142116"><a name="p11231730142116"></a><a name="p11231730142116"></a>All products</p>
</td>
</tr>
</tbody>
</table>

**Table  3** Support in different deployment scenarios

<a name="table155158516230"></a>
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

**Example<a name="section15381171918820"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_domain_info domain_info = {0};
unsigned int size = sizeof(struct dcmi_domain_info);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_SOC_INFO, DCMI_SOC_INFO_SUB_CMD_DOMAIN_INFO, &domain_info, &size);
if (ret != 0) {
printf("[failed] ret = %d\n", ret);
return -1;
}
...
```

## DCMI\_MAIN\_CMD\_CHIP\_INF Command<a name="EN-US_TOPIC_0000002515510428"></a>

**Prototype<a name="section88293413398"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section166811419153914"></a>**

Obtains SuperPoD information.

**Parameter Description<a name="section9437204012398"></a>**

<a name="table1317154133812"></a>
<table><thead align="left"><tr id="row181231554203812"><th class="cellrowborder" valign="top" width="17.078292170782923%" id="mcps1.1.5.1.1"><p id="p12123105418389"><a name="p12123105418389"></a><a name="p12123105418389"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.17848215178482%" id="mcps1.1.5.1.2"><p id="p1712314549389"><a name="p1712314549389"></a><a name="p1712314549389"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.168083191680832%" id="mcps1.1.5.1.3"><p id="p141231454103812"><a name="p141231454103812"></a><a name="p141231454103812"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.57514248575143%" id="mcps1.1.5.1.4"><p id="p11123185412382"><a name="p11123185412382"></a><a name="p11123185412382"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2123854183820"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p712365423813"><a name="p712365423813"></a><a name="p712365423813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p112313543386"><a name="p112313543386"></a><a name="p112313543386"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p15123125416386"><a name="p15123125416386"></a><a name="p15123125416386"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p1212455433818"><a name="p1212455433818"></a><a name="p1212455433818"></a>Device ID. The supported IDs can be obtained by calling <strong id="b94431366433013"><a name="b94431366433013"></a><a name="b94431366433013"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row17124954123815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p16124165419387"><a name="p16124165419387"></a><a name="p16124165419387"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p212418549389"><a name="p212418549389"></a><a name="p212418549389"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p101241854153819"><a name="p101241854153819"></a><a name="p101241854153819"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p012485416387"><a name="p012485416387"></a><a name="p012485416387"></a>Chip ID, which can be obtained by calling <strong id="b8887535152612"><a name="b8887535152612"></a><a name="b8887535152612"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p31242054153818"><a name="p31242054153818"></a><a name="p31242054153818"></a>NPU: [0, <strong id="b1388710514419"><a name="b1388710514419"></a><a name="b1388710514419"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1512419544383"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p2012485453813"><a name="p2012485453813"></a><a name="p2012485453813"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p1312405417387"><a name="p1312405417387"></a><a name="p1312405417387"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p31241754173815"><a name="p31241754173815"></a><a name="p31241754173815"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p16124105417386"><a name="p16124105417386"></a><a name="p16124105417386"></a>DCMI_MAIN_CMD_CHIP_INF</p>
</td>
</tr>
<tr id="row5124754193815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p161249543383"><a name="p161249543383"></a><a name="p161249543383"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p111248547386"><a name="p111248547386"></a><a name="p111248547386"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p1812465411385"><a name="p1812465411385"></a><a name="p1812465411385"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock117365575012"><a name="codeblock117365575012"></a><a name="codeblock117365575012"></a>typedef enum {
DCMI_CHIP_INF_SUB_CMD_CHIP_ID,
DCMI_CHIP_INF_SUB_CMD_SPOD_INFO,
DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS
DCMI_CHIP_INF_SUB_CMD_MAX = 0xFF,
} DCMI_CHIP_INFO_SUB_CMD;</pre>
</td>
</tr>
<tr id="row2012511546389"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p7125165483817"><a name="p7125165483817"></a><a name="p7125165483817"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p10125554153817"><a name="p10125554153817"></a><a name="p10125554153817"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p16125115414381"><a name="p16125115414381"></a><a name="p16125115414381"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p1612555420387"><a name="p1612555420387"></a><a name="p1612555420387"></a>For details, see <a href="#section1374114910415">Restrictions</a>.</p>
</td>
</tr>
<tr id="row7125254143815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p4125165433814"><a name="p4125165433814"></a><a name="p4125165433814"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p18125115416386"><a name="p18125115416386"></a><a name="p18125115416386"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p7125145419382"><a name="p7125145419382"></a><a name="p7125145419382"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p81251954153819"><a name="p81251954153819"></a><a name="p81251954153819"></a>Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section189807595317"></a>**

<a name="table154712012328"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b46651277272214"><a name="b46651277272214"></a><a name="b46651277272214"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section9677135115517"></a>**

None

**Restrictions<a name="section1374114910415"></a>**

SDID validity description: SDID is a 32-bit value divided into four ID fields, where bits 22 to 31 represent the  **server\_index**  \(range 0 to 47\), bits 18 to 21 represent the chip ID \(range 0 to 7\), bits 16 to 17 represent the die ID \(range 0 to 2\), and bits 0 to 15 represent the device ID, calculated as chip ID × 2 + die ID.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1148155443816"></a>
<table><thead align="left"><tr id="row7126155473815"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p1312695412383"><a name="p1312695412383"></a><a name="p1312695412383"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p121262547386"><a name="p121262547386"></a><a name="p121262547386"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p0126254113814"><a name="p0126254113814"></a><a name="p0126254113814"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p36346131358"><a name="p36346131358"></a><a name="p36346131358"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row712655418385"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1912610545385"><a name="p1912610545385"></a><a name="p1912610545385"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1412635410384"><a name="p1412635410384"></a><a name="p1412635410384"></a>struct dcmi_spod_info {</p>
<p id="p10126175423819"><a name="p10126175423819"></a><a name="p10126175423819"></a>unsigned int sdid;</p>
<p id="p21267542389"><a name="p21267542389"></a><a name="p21267542389"></a>unsigned int super_pod_size;</p>
<p id="p612695417388"><a name="p612695417388"></a><a name="p612695417388"></a>unsigned int super_pod_id;</p>
<p id="p14126185483815"><a name="p14126185483815"></a><a name="p14126185483815"></a>unsigned int server_index;</p>
<p id="p14126154173816"><a name="p14126154173816"></a><a name="p14126154173816"></a>unsigned int reserve[8];</p>
<p id="p8126195418380"><a name="p8126195418380"></a><a name="p8126195418380"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1712718547382"><a name="p1712718547382"></a><a name="p1712718547382"></a>sizeof(struct dcmi_spod_info)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1084711499719"></a><a name="ul1084711499719"></a><ul id="ul1084711499719"><li><strong id="b12695193416362"><a name="b12695193416362"></a><a name="b12695193416362"></a>sdid</strong> indicates the unique ID of each NPU in the SuperPoD system. The SDID of a target NPU should be provided.</li><li><strong id="b148751026124211"><a name="b148751026124211"></a><a name="b148751026124211"></a>super_pod_size</strong> indicates the scale of a SuperPoD cluster.</li><li><strong id="b191761036144212"><a name="b191761036144212"></a><a name="b191761036144212"></a>super_pod_id</strong> indicates the ID of the SuperPoD cluster, that is, SuperPoD ID.</li><li><strong id="b618303224716"><a name="b618303224716"></a><a name="b618303224716"></a>server_index</strong> indicates the index of a compute server in the SuperPoD cluster.</li></ul>
</td>
</tr>
<tr id="row1279662818243"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p0501134011248"><a name="p0501134011248"></a><a name="p0501134011248"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1250164092412"><a name="p1250164092412"></a><a name="p1250164092412"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1850154018240"><a name="p1850154018240"></a><a name="p1850154018240"></a>sizeof(unsigned int)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p11501940192410"><a name="p11501940192410"></a><a name="p11501940192410"></a><strong id="b116441414113916"><a name="b116441414113916"></a><a name="b116441414113916"></a>buf</strong> serves as both input and output of the API.</p>
<a name="ul1501154022414"></a><a name="ul1501154022414"></a><ul id="ul1501154022414"><li>As input, <strong id="b16516941133918"><a name="b16516941133918"></a><a name="b16516941133918"></a>buf</strong> indicates the SDID of an NPU to be queried.</li><li>As output, <strong id="b992115515430"><a name="b992115515430"></a><a name="b992115515430"></a>buf</strong> indicates the status of the NPU specified by the SDID.<a name="ul1518995073513"></a><a name="ul1518995073513"></a><ul id="ul1518995073513"><li>The value <strong id="en-us_topic_0000002546990395_b104343255717"><a name="en-us_topic_0000002546990395_b104343255717"></a><a name="en-us_topic_0000002546990395_b104343255717"></a>1</strong> indicates that the target NPU is abnormal. In this case, the local NPU forcibly releases the resources shared with the target NPU.</li><li>The value <strong id="en-us_topic_0000002546990395_b535714575714"><a name="en-us_topic_0000002546990395_b535714575714"></a><a name="en-us_topic_0000002546990395_b535714575714"></a>0</strong> indicates that the target NPU is normal. In this case, the local NPU negotiates the release of resources shared with the target NPU.</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section083811564420"></a>**

Obtains SuperPoD information of an NPU identified by  **card\_id**  and  **device\_id**.

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_spod_info spod_info = {0};
unsigned int buf_size = sizeof(struct dcmi_spod_info);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_CHIP_INF,
DCMI_CHIP_INF_SUB_CMD_SPOD_INFO, & spod_info, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

Retrieves the state record of an NPU identified by  **SDID**, using the NPU identified by  **card\_id**  and  **device\_id**.

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
union {
unsigned int sdid;
unsigned int status;
} para; 
unsigned int buf_size = sizeof(para); 
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_CHIP_INF, DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS, &para.sdid, &buf_size); 
if (ret != 0) { 
//todo return ret;
} 
else { 
printf("status=%u\n", para.status);
return ret; 
} 
...
```

## DCMI\_MAIN\_CMD\_SIO Command<a name="EN-US_TOPIC_0000002546910399"></a>

**Prototype<a name="section88293413398"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section166811419153914"></a>**

Obtains the SIO status between Dies.

**Parameter Description<a name="section9437204012398"></a>**

<a name="table1317154133812"></a>
<table><thead align="left"><tr id="row181231554203812"><th class="cellrowborder" valign="top" width="17.078292170782923%" id="mcps1.1.5.1.1"><p id="p12123105418389"><a name="p12123105418389"></a><a name="p12123105418389"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.17848215178482%" id="mcps1.1.5.1.2"><p id="p1712314549389"><a name="p1712314549389"></a><a name="p1712314549389"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.168083191680832%" id="mcps1.1.5.1.3"><p id="p141231454103812"><a name="p141231454103812"></a><a name="p141231454103812"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.57514248575143%" id="mcps1.1.5.1.4"><p id="p11123185412382"><a name="p11123185412382"></a><a name="p11123185412382"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2123854183820"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p712365423813"><a name="p712365423813"></a><a name="p712365423813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p112313543386"><a name="p112313543386"></a><a name="p112313543386"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p15123125416386"><a name="p15123125416386"></a><a name="p15123125416386"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p1212455433818"><a name="p1212455433818"></a><a name="p1212455433818"></a>Device ID. The supported IDs can be obtained by calling <strong id="b193951478933014"><a name="b193951478933014"></a><a name="b193951478933014"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row17124954123815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p16124165419387"><a name="p16124165419387"></a><a name="p16124165419387"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p212418549389"><a name="p212418549389"></a><a name="p212418549389"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p101241854153819"><a name="p101241854153819"></a><a name="p101241854153819"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p012485416387"><a name="p012485416387"></a><a name="p012485416387"></a>Chip ID, which can be obtained by calling <strong id="b129342266593"><a name="b129342266593"></a><a name="b129342266593"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p31242054153818"><a name="p31242054153818"></a><a name="p31242054153818"></a>NPU: [0, <strong id="b166986402194111"><a name="b166986402194111"></a><a name="b166986402194111"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1512419544383"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p2012485453813"><a name="p2012485453813"></a><a name="p2012485453813"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p1312405417387"><a name="p1312405417387"></a><a name="p1312405417387"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p31241754173815"><a name="p31241754173815"></a><a name="p31241754173815"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p16124105417386"><a name="p16124105417386"></a><a name="p16124105417386"></a>DCMI_MAIN_CMD_SIO</p>
</td>
</tr>
<tr id="row5124754193815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p161249543383"><a name="p161249543383"></a><a name="p161249543383"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p111248547386"><a name="p111248547386"></a><a name="p111248547386"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p1812465411385"><a name="p1812465411385"></a><a name="p1812465411385"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock117365575012"><a name="codeblock117365575012"></a><a name="codeblock117365575012"></a>typedef enum {
DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS = 0
}DCMI_SIO_SUB_CMD;</pre>
</td>
</tr>
<tr id="row2012511546389"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p7125165483817"><a name="p7125165483817"></a><a name="p7125165483817"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p10125554153817"><a name="p10125554153817"></a><a name="p10125554153817"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p16125115414381"><a name="p16125115414381"></a><a name="p16125115414381"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p1612555420387"><a name="p1612555420387"></a><a name="p1612555420387"></a>For details, see Restrictions.</p>
</td>
</tr>
<tr id="row7125254143815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p4125165433814"><a name="p4125165433814"></a><a name="p4125165433814"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p18125115416386"><a name="p18125115416386"></a><a name="p18125115416386"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p7125145419382"><a name="p7125145419382"></a><a name="p7125145419382"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p81251954153819"><a name="p81251954153819"></a><a name="p81251954153819"></a>Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section189807595317"></a>**

<a name="table154712012328"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b164422819972215"><a name="b164422819972215"></a><a name="b164422819972215"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section9677135115517"></a>**

None

**Restrictions<a name="section1374114910415"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1148155443816"></a>
<table><thead align="left"><tr id="row7126155473815"><th class="cellrowborder" valign="top" width="24.45%" id="mcps1.2.5.1.1"><p id="p1312695412383"><a name="p1312695412383"></a><a name="p1312695412383"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="32.99%" id="mcps1.2.5.1.2"><p id="p121262547386"><a name="p121262547386"></a><a name="p121262547386"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="20.01%" id="mcps1.2.5.1.3"><p id="p0126254113814"><a name="p0126254113814"></a><a name="p0126254113814"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="22.55%" id="mcps1.2.5.1.4"><p id="p106461111681"><a name="p106461111681"></a><a name="p106461111681"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row712655418385"><td class="cellrowborder" valign="top" width="24.45%" headers="mcps1.2.5.1.1 "><p id="p1912610545385"><a name="p1912610545385"></a><a name="p1912610545385"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="32.99%" headers="mcps1.2.5.1.2 "><p id="p1664914023114"><a name="p1664914023114"></a><a name="p1664914023114"></a>struct dcmi_sio_crc_err_statistics_info {</p>
<p id="p195228943118"><a name="p195228943118"></a><a name="p195228943118"></a>unsigned short tx_error_count;</p>
<p id="p1959618125316"><a name="p1959618125316"></a><a name="p1959618125316"></a>unsigned short rx_error_count;</p>
<p id="p966122118317"><a name="p966122118317"></a><a name="p966122118317"></a>unsigned char reserved[8];</p>
<p id="p128675414305"><a name="p128675414305"></a><a name="p128675414305"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20.01%" headers="mcps1.2.5.1.3 "><p id="p1712718547382"><a name="p1712718547382"></a><a name="p1712718547382"></a>sizeof(struct dcmi_sio_crc_err_statistics_info)</p>
</td>
<td class="cellrowborder" valign="top" width="22.55%" headers="mcps1.2.5.1.4 "><a name="ul89281736384"></a><a name="ul89281736384"></a><ul id="ul89281736384"><li><strong id="b19285441165012"><a name="b19285441165012"></a><a name="b19285441165012"></a>tx_error_count</strong>: number of transmitted SIO errors</li><li><strong id="b1948310434504"><a name="b1948310434504"></a><a name="b1948310434504"></a>rx_error_count</strong>: number of received SIO errors</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

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

**Example<a name="section083811564420"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_sio_crc_err_statistics_info sio_info = {0};
unsigned int sio_info_size = sizeof(struct dcmi_sio_crc_err_statistics_info);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_SIO, DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS, &sio_info, &sio_info_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_PCIE Command<a name="EN-US_TOPIC_0000002546990365"></a>

**Prototype<a name="section224642513574"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf,unsigned int \*size\)**

**Description<a name="section162477254573"></a>**

Obtains PCIe information.

**Parameter Description<a name="section16248625165719"></a>**

<a name="table23011825165718"></a>
<table><thead align="left"><tr id="row1644220264578"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p19442192665715"><a name="p19442192665715"></a><a name="p19442192665715"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p84426269577"><a name="p84426269577"></a><a name="p84426269577"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p164426264575"><a name="p164426264575"></a><a name="p164426264575"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p14424263576"><a name="p14424263576"></a><a name="p14424263576"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row144428269571"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p11442192614578"><a name="p11442192614578"></a><a name="p11442192614578"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p544232625716"><a name="p544232625716"></a><a name="p544232625716"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p17442526165714"><a name="p17442526165714"></a><a name="p17442526165714"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p16442182635713"><a name="p16442182635713"></a><a name="p16442182635713"></a>Device ID. The supported IDs can be obtained by calling <strong id="b125773584933015"><a name="b125773584933015"></a><a name="b125773584933015"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row8442182617573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p134421126155713"><a name="p134421126155713"></a><a name="p134421126155713"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16442142613570"><a name="p16442142613570"></a><a name="p16442142613570"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p6442142615710"><a name="p6442142615710"></a><a name="p6442142615710"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p11442226105712"><a name="p11442226105712"></a><a name="p11442226105712"></a>Chip ID, which can be obtained by calling <strong id="b346285318713"><a name="b346285318713"></a><a name="b346285318713"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p17442112616571"><a name="p17442112616571"></a><a name="p17442112616571"></a>NPU: [0, <strong id="b64764970994112"><a name="b64764970994112"></a><a name="b64764970994112"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1544262610576"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2044352611575"><a name="p2044352611575"></a><a name="p2044352611575"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p7443152613571"><a name="p7443152613571"></a><a name="p7443152613571"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p104439262577"><a name="p104439262577"></a><a name="p104439262577"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p844312611573"><a name="p844312611573"></a><a name="p844312611573"></a>DCMI_MAIN_CMD_PCIE</p>
</td>
</tr>
<tr id="row6443426185717"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p14431726185711"><a name="p14431726185711"></a><a name="p14431726185711"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p84431426165711"><a name="p84431426165711"></a><a name="p84431426165711"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1844312619576"><a name="p1844312619576"></a><a name="p1844312619576"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p11443162655718"><a name="p11443162655718"></a><a name="p11443162655718"></a>DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO</p>
</td>
</tr>
<tr id="row144342617576"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p0443172665711"><a name="p0443172665711"></a><a name="p0443172665711"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p644362612579"><a name="p644362612579"></a><a name="p644362612579"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p154431526205714"><a name="p154431526205714"></a><a name="p154431526205714"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p194431626195715"><a name="p194431626195715"></a><a name="p194431626195715"></a>For details, see Restrictions.</p>
</td>
</tr>
<tr id="row1144315264573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2443526125719"><a name="p2443526125719"></a><a name="p2443526125719"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12443326145716"><a name="p12443326145716"></a><a name="p12443326145716"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p4443526135714"><a name="p4443526135714"></a><a name="p4443526135714"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p3443102675716"><a name="p3443102675716"></a><a name="p3443102675716"></a>Length of the <strong id="b95951017115213"><a name="b95951017115213"></a><a name="b95951017115213"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section1276192518575"></a>**

<a name="table154712012328"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b32973925072216"><a name="b32973925072216"></a><a name="b32973925072216"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section10284025165720"></a>**

None

**Restrictions<a name="section142847254570"></a>**

This API is used only in open Ctrl CPU form.

For the A200T A3 Box8 SuperPoD server, this API can be used in the PM + privileged container scenario.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table131652519571"></a>
<table><thead align="left"><tr id="row144441226125711"><th class="cellrowborder" valign="top" width="30.303030303030305%" id="mcps1.2.4.1.1"><p id="p64441826115711"><a name="p64441826115711"></a><a name="p64441826115711"></a><strong id="b3444192610574"><a name="b3444192610574"></a><a name="b3444192610574"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="47.474747474747474%" id="mcps1.2.4.1.2"><p id="p64444261570"><a name="p64444261570"></a><a name="p64444261570"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="22.222222222222225%" id="mcps1.2.4.1.3"><p id="p1644432645711"><a name="p1644432645711"></a><a name="p1644432645711"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12444826175711"><td class="cellrowborder" valign="top" width="30.303030303030305%" headers="mcps1.2.4.1.1 "><p id="p17444112611573"><a name="p17444112611573"></a><a name="p17444112611573"></a>DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="47.474747474747474%" headers="mcps1.2.4.1.2 "><p id="p124454268570"><a name="p124454268570"></a><a name="p124454268570"></a>struct dcmi_pcie_link_error_info {</p>
<p id="p94452262574"><a name="p94452262574"></a><a name="p94452262574"></a>unsigned int tx_err_cnt;</p>
<p id="p2044522615576"><a name="p2044522615576"></a><a name="p2044522615576"></a>unsigned int rx_err_cnt;</p>
<p id="p34456263573"><a name="p34456263573"></a><a name="p34456263573"></a>unsigned int lcrc_err_cnt;</p>
<p id="p34450264576"><a name="p34450264576"></a><a name="p34450264576"></a>unsigned int ecrc_err_cnt;</p>
<p id="p24455263576"><a name="p24455263576"></a><a name="p24455263576"></a>unsigned int retry_cnt;</p>
<p id="p15445152619575"><a name="p15445152619575"></a><a name="p15445152619575"></a>unsigned int rsv[32];</p>
<p id="p1445182613571"><a name="p1445182613571"></a><a name="p1445182613571"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="22.222222222222225%" headers="mcps1.2.4.1.3 "><p id="p7445142665715"><a name="p7445142665715"></a><a name="p7445142665715"></a>Obtains the values related to <strong id="b723113227810"><a name="b723113227810"></a><a name="b723113227810"></a>pcie_link_error</strong>.</p>
<a name="ul19681694120"></a><a name="ul19681694120"></a><ul id="ul19681694120"><li><strong id="b2966049173216"><a name="b2966049173216"></a><a name="b2966049173216"></a>tx_err_cnt</strong>: number of PCIe transmission errors</li><li><strong id="b1852913524321"><a name="b1852913524321"></a><a name="b1852913524321"></a>rx_err_cnt</strong>: number of PCIe receiving errors</li><li><strong id="b132091540324"><a name="b132091540324"></a><a name="b132091540324"></a>lcrc_err_cnt</strong>: number of PCIe DLLP LCRC errors</li><li><strong id="b6934105614322"><a name="b6934105614322"></a><a name="b6934105614322"></a>ecrc_err_cnt</strong>: number of PCIe TLP ECRC errors</li><li><strong id="b354917586321"><a name="b354917586321"></a><a name="b354917586321"></a>retry_cnt</strong>: number of PCIe link retransmissions</li><li><strong id="b32668113335"><a name="b32668113335"></a><a name="b32668113335"></a>rsv</strong>: reserved field</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row20271184815710"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p327144895713"><a name="en-us_topic_0000002515350556_p327144895713"></a><a name="en-us_topic_0000002515350556_p327144895713"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p527116484571"><a name="en-us_topic_0000002515350556_p527116484571"></a><a name="en-us_topic_0000002515350556_p527116484571"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p122714488577"><a name="en-us_topic_0000002515350556_p122714488577"></a><a name="en-us_topic_0000002515350556_p122714488577"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row927164816576"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p14271148145715"><a name="en-us_topic_0000002515350556_p14271148145715"></a><a name="en-us_topic_0000002515350556_p14271148145715"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p427154812577"><a name="en-us_topic_0000002515350556_p427154812577"></a><a name="en-us_topic_0000002515350556_p427154812577"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p142713489570"><a name="en-us_topic_0000002515350556_p142713489570"></a><a name="en-us_topic_0000002515350556_p142713489570"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1527104875720"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p13271248185720"><a name="en-us_topic_0000002515350556_p13271248185720"></a><a name="en-us_topic_0000002515350556_p13271248185720"></a><span id="en-us_topic_0000002515350556_text1527154812578"><a name="en-us_topic_0000002515350556_text1527154812578"></a><a name="en-us_topic_0000002515350556_text1527154812578"></a><span id="en-us_topic_0000002515350556_text2271148205710"><a name="en-us_topic_0000002515350556_text2271148205710"></a><a name="en-us_topic_0000002515350556_text2271148205710"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p10271248165717"><a name="en-us_topic_0000002515350556_p10271248165717"></a><a name="en-us_topic_0000002515350556_p10271248165717"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p11271348175719"><a name="en-us_topic_0000002515350556_p11271348175719"></a><a name="en-us_topic_0000002515350556_p11271348175719"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p6271144865712"><a name="en-us_topic_0000002515350556_p6271144865712"></a><a name="en-us_topic_0000002515350556_p6271144865712"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row527124819571"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p42711448205716"><a name="en-us_topic_0000002515350556_p42711448205716"></a><a name="en-us_topic_0000002515350556_p42711448205716"></a><span id="en-us_topic_0000002515350556_text8271134845715"><a name="en-us_topic_0000002515350556_text8271134845715"></a><a name="en-us_topic_0000002515350556_text8271134845715"></a><span id="en-us_topic_0000002515350556_text527164811575"><a name="en-us_topic_0000002515350556_text527164811575"></a><a name="en-us_topic_0000002515350556_text527164811575"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p12271164818576"><a name="en-us_topic_0000002515350556_p12271164818576"></a><a name="en-us_topic_0000002515350556_p12271164818576"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p427134816570"><a name="en-us_topic_0000002515350556_p427134816570"></a><a name="en-us_topic_0000002515350556_p427134816570"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p627114835717"><a name="en-us_topic_0000002515350556_p627114835717"></a><a name="en-us_topic_0000002515350556_p627114835717"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row18271184811578"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p79671124131618"><a name="en-us_topic_0000002515350556_p79671124131618"></a><a name="en-us_topic_0000002515350556_p79671124131618"></a><span id="en-us_topic_0000002515350556_text49671624141613"><a name="en-us_topic_0000002515350556_text49671624141613"></a><a name="en-us_topic_0000002515350556_text49671624141613"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p9271134885710"><a name="en-us_topic_0000002515350556_p9271134885710"></a><a name="en-us_topic_0000002515350556_p9271134885710"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p7271104814571"><a name="en-us_topic_0000002515350556_p7271104814571"></a><a name="en-us_topic_0000002515350556_p7271104814571"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8271048185714"><a name="en-us_topic_0000002515350556_p8271048185714"></a><a name="en-us_topic_0000002515350556_p8271048185714"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row285204910295"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p15986185513296"><a name="en-us_topic_0000002515350556_p15986185513296"></a><a name="en-us_topic_0000002515350556_p15986185513296"></a><span id="en-us_topic_0000002515350556_text098685572912"><a name="en-us_topic_0000002515350556_text098685572912"></a><a name="en-us_topic_0000002515350556_text098685572912"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p105251859192911"><a name="en-us_topic_0000002515350556_p105251859192911"></a><a name="en-us_topic_0000002515350556_p105251859192911"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p7525145902913"><a name="en-us_topic_0000002515350556_p7525145902913"></a><a name="en-us_topic_0000002515350556_p7525145902913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p0525165962917"><a name="en-us_topic_0000002515350556_p0525165962917"></a><a name="en-us_topic_0000002515350556_p0525165962917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14271848145719"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p527118483579"><a name="en-us_topic_0000002515350556_p527118483579"></a><a name="en-us_topic_0000002515350556_p527118483579"></a><span id="en-us_topic_0000002515350556_text15271174815713"><a name="en-us_topic_0000002515350556_text15271174815713"></a><a name="en-us_topic_0000002515350556_text15271174815713"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p16271194813571"><a name="en-us_topic_0000002515350556_p16271194813571"></a><a name="en-us_topic_0000002515350556_p16271194813571"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1827154818570"><a name="en-us_topic_0000002515350556_p1827154818570"></a><a name="en-us_topic_0000002515350556_p1827154818570"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p72711448185716"><a name="en-us_topic_0000002515350556_p72711448185716"></a><a name="en-us_topic_0000002515350556_p72711448185716"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row886601693"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p17525251914"><a name="en-us_topic_0000002515350556_p17525251914"></a><a name="en-us_topic_0000002515350556_p17525251914"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section8297125115718"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
struct dcmi_pcie_link_error_info pcie_link_error_info = {0};
unsigned int info_leng = sizeof(struct dcmi_pcie_link_error_info);
ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_PCIE, DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO, &pcie_link_error_info, &info_leng);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_DEVICE\_SHARE Command<a name="EN-US_TOPIC_0000002546990405"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_get\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf,unsigned int \*size\)**

**Description<a name="section19822105710305"></a>**

Queries the container sharing enable flag for a chip.

**Parameter Description<a name="section5671124612912"></a>**

<a name="en-us_topic_0257495783_table45028263"></a>
<table><thead align="left"><tr id="en-us_topic_0257495783_row60695621"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0257495783_p17398306"><a name="en-us_topic_0257495783_p17398306"></a><a name="en-us_topic_0257495783_p17398306"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.41%" id="mcps1.1.5.1.2"><p id="en-us_topic_0257495783_p67085535"><a name="en-us_topic_0257495783_p67085535"></a><a name="en-us_topic_0257495783_p67085535"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.3"><p id="p153645385214"><a name="p153645385214"></a><a name="p153645385214"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0257495783_p48266778"><a name="en-us_topic_0257495783_p48266778"></a><a name="en-us_topic_0257495783_p48266778"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row884163595218"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p121951513267"><a name="p121951513267"></a><a name="p121951513267"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p11956515261"><a name="p11956515261"></a><a name="p11956515261"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1919510562619"><a name="p1919510562619"></a><a name="p1919510562619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b37503087533017"><a name="b37503087533017"></a><a name="b37503087533017"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row31747823"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b93628361681528"><a name="b93628361681528"></a><a name="b93628361681528"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU: [0, <strong id="b103060011181528"><a name="b103060011181528"></a><a name="b103060011181528"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row7743426585"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p15756282814"><a name="en-us_topic_0257495783_p15756282814"></a><a name="en-us_topic_0257495783_p15756282814"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p1574417263816"><a name="en-us_topic_0257495783_p1574417263816"></a><a name="en-us_topic_0257495783_p1574417263816"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1519518513263"><a name="p1519518513263"></a><a name="p1519518513263"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p466445534710"><a name="p466445534710"></a><a name="p466445534710"></a>DCMI_MAIN_CMD_DEVICE_SHARE</p>
<div class="note" id="note1218455521019"><a name="note1218455521019"></a><a name="note1218455521019"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p14728105710819"><a name="p14728105710819"></a><a name="p14728105710819"></a>To query the container sharing function, see <a href="dcmi_get_device_share_enable.md">dcmi_get_device_share_enable Prototype</a>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row42644663"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p851813475811"><a name="en-us_topic_0257495783_p851813475811"></a><a name="en-us_topic_0257495783_p851813475811"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p133891038900"><a name="en-us_topic_0257495783_p133891038900"></a><a name="en-us_topic_0257495783_p133891038900"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p17196155202616"><a name="p17196155202616"></a><a name="p17196155202616"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1528419185118"><a name="p1528419185118"></a><a name="p1528419185118"></a>typedef enum {</p>
<p id="p1228415916510"><a name="p1228415916510"></a><a name="p1228415916510"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON = 0,</p>
<p id="p1028409165114"><a name="p1028409165114"></a><a name="p1028409165114"></a>DCMI_DEVICE_SHARE_SUB_CMD_MAX,</p>
<p id="p328411917514"><a name="p328411917514"></a><a name="p328411917514"></a>} DCMI_DEVICE_SHARE_SUB_CMD;</p>
<div class="note" id="note690717511525"><a name="note690717511525"></a><a name="note690717511525"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p12648821111120"><a name="p12648821111120"></a><a name="p12648821111120"></a>Currently, this API supports only the <strong id="b67492547281528"><a name="b67492547281528"></a><a name="b67492547281528"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON</strong> command.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row17526454687"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row19825197914"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p1231019570213"><a name="p1231019570213"></a><a name="p1231019570213"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p12310115715213"><a name="p12310115715213"></a><a name="p12310115715213"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1531045710217"><a name="p1531045710217"></a><a name="p1531045710217"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p13107576214"><a name="p13107576214"></a><a name="p13107576214"></a>Length of the <strong id="b1733039381528"><a name="b1733039381528"></a><a name="b1733039381528"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section283355715302"></a>**

<a name="table1985018574309"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b196538211081528"><a name="b196538211081528"></a><a name="b196538211081528"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None

**Restrictions<a name="section13645113118442"></a>**

- In the container sharing mode, the container is disabled by default after the system is restarted.
- This API can be used in the PM + privileged container scenario.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table08529574303"></a>
<table><thead align="left"><tr id="row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="p59011457173015"><a name="p59011457173015"></a><a name="p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="p159011357193019"><a name="p159011357193019"></a><a name="p159011357193019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="p1990165743011"><a name="p1990165743011"></a><a name="p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row15743174685218"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p17744144675215"><a name="p17744144675215"></a><a name="p17744144675215"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p6898117165315"><a name="p6898117165315"></a><a name="p6898117165315"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p789841705311"><a name="p789841705311"></a><a name="p789841705311"></a>unsigned int</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table6183194116432"></a>
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

**Example<a name="section49611431655"></a>**

```c
...
    int ret = 0;
    int card_id = 0;
    int dev_id = 0;
    unsigned int enable_flag = 1;
    unsigned int size = (unsigned int)sizeof(int);
    ret = dcmi_get_device_info(card_id, dev_id, DCMI_MAIN_CMD_DEVICE_SHARE, 
        DCMI_DEVICE_SHARE_SUB_CMD_COMMON, &enable_flag, &size);
    if (ret != DCMI_OK){
        // todo: Record logs.
        return ret;
    }
...
```
