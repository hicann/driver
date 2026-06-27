# dcmiv2\_get\_device\_info<a name="EN-US_TOPIC_0000002314045082"></a>

**Prototype<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412077"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p5522164215178"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p17522114220174"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"></a><a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_p167001165556"></a>Main command word corresponding to the specified query item. CMD information, which is used to obtain the information about the corresponding module.</p>
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
<p id="p092419461017"><a name="p092419461017"></a><a name="p092419461017"></a>DCMI_MAIN_CMD_EX_COMPUTING = 0x8000,</p>
<p id="p18590722192310"><a name="p18590722192310"></a><a name="p18590722192310"></a>DCMI_MAIN_CMD_DEVICE_SHARE = 0x8001,</p>
<p id="p1032616302563"><a name="p1032616302563"></a><a name="p1032616302563"></a>DCMI_MAIN_CMD_EX_CERT = 0x8003,</p>
<p id="p692433982"><a name="p692433982"></a><a name="p692433982"></a>DCMI_MAIN_CMD_MAX</p>
<p id="p223161612813"><a name="p223161612813"></a><a name="p223161612813"></a>};</p>
<p id="p9932195894319"><a name="p9932195894319"></a><a name="p9932195894319"></a>Only the following main command words are supported:</p>
<p id="p1028842114915"><a name="p1028842114915"></a><a name="p1028842114915"></a>DCMI_MAIN_CMD_DVPP // Main command word of the DVPP operator module</p>
<p id="p889911226920"><a name="p889911226920"></a><a name="p889911226920"></a>DCMI_MAIN_CMD_LP // Main command word of the low power consumption module</p>
<p id="p630816245918"><a name="p630816245918"></a><a name="p630816245918"></a>DCMI_MAIN_CMD_TS // Main command word of the task scheduling module</p>
<p id="p77158266913"><a name="p77158266913"></a><a name="p77158266913"></a>DCMI_MAIN_CMD_QOS // Main command word of the QoS module</p>
<p id="p121340251314"><a name="p121340251314"></a><a name="p121340251314"></a>DCMI_MAIN_CMD_VDEV_MNG // Main command word of the <span id="ph584501422712"><a name="ph584501422712"></a><a name="ph584501422712"></a>Ascend  Virtual Instance (AVI)</span> module</p>
<p id="p47917422120"><a name="p47917422120"></a><a name="p47917422120"></a>DCMI_MAIN_CMD_PCIE // Obtain PCIe information.</p>
<p id="p15875609615"><a name="p15875609615"></a><a name="p15875609615"></a>DCMI_MAIN_CMD_SIO // Query the SIO status between Dies.</p>
<p id="p1334062061315"><a name="p1334062061315"></a><a name="p1334062061315"></a>DCMI_MAIN_CMD_EX_COMPUTING // Main command word of the compute expansion module</p>
<p id="p91844347321"><a name="p91844347321"></a><a name="p91844347321"></a>DCMI_MAIN_CMD_EX_CERT // Main command word of the certificate management module.</p>
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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
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

**Example<a name="en-us_topic_0000001206467202_en-us_topic_0000001178373156_en-us_topic_0000001101204718_toc533412083"></a>**

```c
...
int ret = 0;
int dev_id = 0;
int buf = 0;
unsigned int size = sizeof(int);
unsigned int sub_cmd = 0;
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_DVPP, sub_cmd, (void *)&buf, &size);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

- **[DCMI\_MAIN\_CMD\_DVPP](#EN-US_TOPIC_0000002348043853)**  
- **[DCMI\_MAIN\_CMD\_LP](#EN-US_TOPIC_0000002347924029)**  
- **[DCMI\_MAIN\_CMD\_TS](#EN-US_TOPIC_0000002348043797)**  
- **[DCMI\_MAIN\_CMD\_QOS](#EN-US_TOPIC_0000002347924125)**  
- **[DCMI\_MAIN\_CMD\_VDEV\_MNG](#EN-US_TOPIC_0000002348043801)**  
- **[DCMI\_MAIN\_CMD\_PCIE](#EN-US_TOPIC_0000002348043793)**  
- **[DCMI\_MAIN\_CMD\_SIO](#EN-US_TOPIC_0000002314204826)**  
- **[DCMI\_MAIN\_CMD\_EX\_COMPUTING](#EN-US_TOPIC_0000002544184079)**  
- **[DCMI\_MAIN\_CMD\_EX\_CERT](#EN-US_TOPIC_0000002509588792)**  

## DCMI\_MAIN\_CMD\_DVPP<a id="EN-US_TOPIC_0000002348043853"></a>

**Prototype<a name="section1045115919305"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row1544592304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p195445917304"><a name="p195445917304"></a><a name="p195445917304"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185446910306"><a name="p185446910306"></a><a name="p185446910306"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p175441294306"><a name="p175441294306"></a><a name="p175441294306"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
<p id="p145452913308"><a name="p145452913308"></a><a name="p145452913308"></a>#define DCMI_SUB_CMD_DVPP_STATUS 0 // DVPP status. If the value of <strong id="b6775172913529"><a name="b6775172913529"></a><a name="b6775172913529"></a>buf</strong> is <strong id="b137752295523"><a name="b137752295523"></a><a name="b137752295523"></a>0</strong>, the status is normal. Otherwise, the status is abnormal.</p>
<p id="p17545699303"><a name="p17545699303"></a><a name="p17545699303"></a>#define DCMI_SUB_CMD_DVPP_VDEC_RATE 1 // VDEC utilization. The normal value ranges from 0 to 100.</p>
<p id="p0545119193019"><a name="p0545119193019"></a><a name="p0545119193019"></a>#define DCMI_SUB_CMD_DVPP_VPC_RATE 2 // VPC utilization. The normal value ranges from 0 to 100.</p>
<p id="p13545397302"><a name="p13545397302"></a><a name="p13545397302"></a>#define DCMI_SUB_CMD_DVPP_VENC_RATE 3 // VENC utilization. The normal value ranges from 0 to 100.</p>
<p id="p154509103011"><a name="p154509103011"></a><a name="p154509103011"></a>#define DCMI_SUB_CMD_DVPP_JPEGE_RATE 4 // JPEGE utilization. The normal value ranges from 0 to 100.</p>
<p id="p1054579163010"><a name="p1054579163010"></a><a name="p1054579163010"></a>#define DCMI_SUB_CMD_DVPP_JPEGD_RATE 5 // JPEGD utilization. The normal value ranges from 0 to 100.</p>
<p id="p6784427174618"><a name="p6784427174618"></a><a name="p6784427174618"></a>Currently, the <strong id="b1320519337482"><a name="b1320519337482"></a><a name="b1320519337482"></a>DCMI_SUB_CMD_DVPP_VDEC_RATE</strong> and <strong id="b4206163384811"><a name="b4206163384811"></a><a name="b4206163384811"></a>DCMI_SUB_CMD_DVPP_VENC_RATE</strong> commands cannot be used for query.</p>
</td>
</tr>
<tr id="row1954515903016"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p155455915303"><a name="p155455915303"></a><a name="p155455915303"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p554510903013"><a name="p554510903013"></a><a name="p554510903013"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p19545129143015"><a name="p19545129143015"></a><a name="p19545129143015"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p185454953015"><a name="p185454953015"></a><a name="p185454953015"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row2054549113013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p25451983018"><a name="p25451983018"></a><a name="p25451983018"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p12545169113011"><a name="p12545169113011"></a><a name="p12545169113011"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p1754515943013"><a name="p1754515943013"></a><a name="p1754515943013"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p2054559153019"><a name="p2054559153019"></a><a name="p2054559153019"></a>Length of the <strong id="b185431194519"><a name="b185431194519"></a><a name="b185431194519"></a>buf</strong> array/Actual length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

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
<tr id="row2054611914303"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p954615953017"><a name="p954615953017"></a><a name="p954615953017"></a>DCMI_SUB_CMD_DVPP_VPC_RATE</p>
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

<a name="table78605316125"></a>
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

**Example<a name="section2133155511568"></a>**

```c
...
int ret = 0;
int dev_id = 0;
unsigned int ratio = 0;
unsigned int sub_cmd = 0;
unsigned int ratio_size = sizeof(unsigned int);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_DVPP, sub_cmd, (void *)&ratio, &ratio_size);
if (ret != 0) {
    // TODO
    return ret;
} else {
    // TODO
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_LP<a id="EN-US_TOPIC_0000002347924029"></a>

**Prototype<a name="section158495435301"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row109751843163011"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p39751943113018"><a name="p39751943113018"></a><a name="p39751943113018"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p2975124363011"><a name="p2975124363011"></a><a name="p2975124363011"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p997554315307"><a name="p997554315307"></a><a name="p997554315307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18975343113017"><a name="p18975343113017"></a><a name="p18975343113017"></a>/* DCMI sub command for Low power */</p>
<pre class="codeblock" id="codeblock971395520334"><a name="codeblock971395520334"></a><a name="codeblock971395520334"></a>typedef enum {
DCMI_LP_SUB_CMD_AICORE_VOLTAGE_CURRENT = 0, // Obtain the register values indicating the voltage and current of the AI Core.
DCMI_LP_SUB_CMD_HYBIRD_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the Hybird.
DCMI_LP_SUB_CMD_TAISHAN_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the CPU.
DCMI_LP_SUB_CMD_DDR_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the DDR.
DCMI_LP_SUB_CMD_ACG, // Obtain the count of ACG frequency modulations.
DCMI_LP_SUB_CMD_STATUS, // Obtain the overall low-power status.
DCMI_LP_SUB_CMD_TOPS_DETAILS, // Obtain all working levels.
DCMI_LP_SUB_CMD_SET_WORK_TOPS, // Set the working level.
DCMI_LP_SUB_CMD_GET_WORK_TOPS, // Obtain the current working level.
DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE, // Obtain the reason for the current frequency reduction.
DCMI_LP_SUB_CMD_GET_POWER_INFO, // Obtain the power consumption information.
DCMI_LP_SUB_CMD_SET_IDLE_SWITCH, // Set the idle mode switch.
DCMI_LP_SUB_CMD_MAX, // Upper limit flag of enumerated values.
} DCMI_LP_SUB_CMD;</pre>
<p id="p0976643203017"><a name="p0976643203017"></a><a name="p0976643203017"></a>Only <strong id="b133833491406"><a name="b133833491406"></a><a name="b133833491406"></a>DCMI_LP_SUB_CMD_STATUS</strong>, <strong id="b15597105884019"><a name="b15597105884019"></a><a name="b15597105884019"></a>DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE</strong>, and <strong id="b17512272417"><a name="b17512272417"></a><a name="b17512272417"></a>DCMI_LP_SUB_CMD_GET_POWER_INFO</strong> are supported.</p>
</td>
</tr>
<tr id="row119761843173017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p0976184343012"><a name="p0976184343012"></a><a name="p0976184343012"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p397614363010"><a name="p397614363010"></a><a name="p397614363010"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p29762043173012"><a name="p29762043173012"></a><a name="p29762043173012"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p179761943143013"><a name="p179761943143013"></a><a name="p179761943143013"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row6976543103019"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p119765433306"><a name="p119765433306"></a><a name="p119765433306"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p79761543173017"><a name="p79761543173017"></a><a name="p79761543173017"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1976204317307"><a name="p1976204317307"></a><a name="p1976204317307"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p2976943123017"><a name="p2976943123017"></a><a name="p2976943123017"></a>Length of the <strong id="b16635586519"><a name="b16635586519"></a><a name="b16635586519"></a>buf</strong> array/Actual length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section216210381817"></a>**

- The voltage and current obtained by calling this API are register values.
- The reason of AI Core frequency reduction is updated every 100 ms, and historical frequency reduction reasons cannot be queried.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table9893154314306"></a>
<table><thead align="left"><tr id="row1097794373014"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p597724343018"><a name="p597724343018"></a><a name="p597724343018"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p15977743113017"><a name="p15977743113017"></a><a name="p15977743113017"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1977104363011"><a name="p1977104363011"></a><a name="p1977104363011"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1097718435302"><a name="p1097718435302"></a><a name="p1097718435302"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row834951184217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12977743173013"><a name="p12977743173013"></a><a name="p12977743173013"></a>DCMI_LP_SUB_CMD_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p597754320305"><a name="p597754320305"></a><a name="p597754320305"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p097724315305"><a name="p097724315305"></a><a name="p097724315305"></a>sizeof(unsigned int)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p16977243183018"><a name="p16977243183018"></a><a name="p16977243183018"></a><strong id="b2818985458723"><a name="b2818985458723"></a><a name="b2818985458723"></a>0</strong>: non-idle; <strong id="b9526010988723"><a name="b9526010988723"></a><a name="b9526010988723"></a>1</strong>: idle</p>
</td>
</tr>
<tr id="row497744313309"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1897794353018"><a name="p1897794353018"></a><a name="p1897794353018"></a>DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p159771243123013"><a name="p159771243123013"></a><a name="p159771243123013"></a>unsigned long long</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15977204323010"><a name="p15977204323010"></a><a name="p15977204323010"></a>sizeof(unsigned long long)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p197784315304"><a name="p197784315304"></a><a name="p197784315304"></a><strong id="b10105201410111"><a name="b10105201410111"></a><a name="b10105201410111"></a>buf</strong> indicates an 8-byte memory space. Each bit corresponds to a frequency reduction reason.</p>
</td>
</tr>
<tr id="row697713436302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1797774310308"><a name="p1797774310308"></a><a name="p1797774310308"></a>DCMI_LP_SUB_CMD_GET_POWER_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1977043163011"><a name="p1977043163011"></a><a name="p1977043163011"></a>DCMI_LP_POWER_INFO_STRU</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p6977144314302"><a name="p6977144314302"></a><a name="p6977144314302"></a>sizeof(DCMI_LP_POWER_INFO_STRU)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p397764343016"><a name="p397764343016"></a><a name="p397764343016"></a>#define DCMI_LP_POWER_RESERVED_LEN 32</p>
<p id="p12977124373012"><a name="p12977124373012"></a><a name="p12977124373012"></a>typedef struct dcmi_lp_power_info {</p>
<p id="p1697714323019"><a name="p1697714323019"></a><a name="p1697714323019"></a>unsigned int soc_rated_power;</p>
<p id="p797713439301"><a name="p797713439301"></a><a name="p797713439301"></a>unsigned char reserved[DCMI_LP_POWER_RESERVED_LEN];</p>
<p id="p197774318301"><a name="p197774318301"></a><a name="p197774318301"></a>} DCMI_LP_POWER_INFO_STRU;</p>
<p id="p1197794310304"><a name="p1197794310304"></a><a name="p1197794310304"></a><strong id="b6851883058723"><a name="b6851883058723"></a><a name="b6851883058723"></a>soc_rated_power</strong> indicates the rated power of the SoC, and other parameters are reserved for expansion. Correct range of the SoC rated power: [150000, 600000]</p>
</td>
</tr>
</tbody>
</table>

In the subcommand  **DCMI\_LP\_SUB\_CMD\_AICORE\_FREQREDUC\_CAUSE**, the reason of AI Core frequency reduction is represented by a 64-bit value. Each bit corresponds to a frequency reduction reason. If the value is 0, the AI Core runs at a rated frequency. If the value is 1, the AI Core cannot run at a rated frequency. Frequency reduction may be caused by multiple factors. Therefore, multiple bits may be set to 1.

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
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p897894393014"><a name="p897894393014"></a><a name="p897894393014"></a>The temperature of the <span id="ph1124218211961"><a name="ph1124218211961"></a><a name="ph1124218211961"></a>Ascend AI Processor</span> exceeds the allowed range. As a result, the lower layer software imposes a range limit on the AI Core frequency to reduce the processor temperature.</p>
</td>
</tr>
<tr id="row297804343016"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p6978124373015"><a name="p6978124373015"></a><a name="p6978124373015"></a>SW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p1097824314304"><a name="p1097824314304"></a><a name="p1097824314304"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997864373012"><a name="p997864373012"></a><a name="p997864373012"></a>On the <span id="ph178115339610"><a name="ph178115339610"></a><a name="ph178115339610"></a>Ascend AI Processor</span>, the power supply current of the AI Core module exceeds the allowed range. As a result, the lower layer software imposes a range limit on the AI Core frequency to ensure stable power supply to the AI Core module.</p>
</td>
</tr>
<tr id="row1897894313010"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p1897816431303"><a name="p1897816431303"></a><a name="p1897816431303"></a>HW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p59781343123016"><a name="p59781343123016"></a><a name="p59781343123016"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p1497804343013"><a name="p1497804343013"></a><a name="p1497804343013"></a>On the <span id="ph12624153620718"><a name="ph12624153620718"></a><a name="ph12624153620718"></a>Ascend AI Processor</span>, the transient power supply current of the AI Core module exceeds the allowed range. As a result, the current sensor on the mainboard triggers a quick frequency reduction of the AI Core module.</p>
</td>
</tr>
<tr id="row119787436308"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p197813434307"><a name="p197813434307"></a><a name="p197813434307"></a>POWER_BREAK</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p4978144310304"><a name="p4978144310304"></a><a name="p4978144310304"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p597894323019"><a name="p597894323019"></a><a name="p597894323019"></a>After detecting that the power exceeds the upper limit, the power monitoring module on the mainboard instructs the <span id="ph5911243772"><a name="ph5911243772"></a><a name="ph5911243772"></a>Ascend AI Processor</span> to quickly reduce the AI Core frequency to maintain stable power supply.</p>
</td>
</tr>
<tr id="row4978144318302"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p897874303013"><a name="p897874303013"></a><a name="p897874303013"></a>SVFD</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p11978134316303"><a name="p11978134316303"></a><a name="p11978134316303"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997804363012"><a name="p997804363012"></a><a name="p997804363012"></a>When the power supply monitoring module of the AI Core on the <span id="ph9116482712"><a name="ph9116482712"></a><a name="ph9116482712"></a>Ascend AI Processor</span> detects that the power supply is unstable (with noises), the AI Core frequency is quickly reduced to maintain stable power supply.</p>
</td>
</tr>
<tr id="row730384616819"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001312397937_p11311634212"><a name="en-us_topic_0000001312397937_p11311634212"></a><a name="en-us_topic_0000001312397937_p11311634212"></a>POWERCAPPING</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001312397937_p169341949144114"><a name="en-us_topic_0000001312397937_p169341949144114"></a><a name="en-us_topic_0000001312397937_p169341949144114"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p13043467813"><a name="p13043467813"></a><a name="p13043467813"></a>The <span id="ph943235018720"><a name="ph943235018720"></a><a name="ph943235018720"></a>Ascend AI Processor</span> performs out-of-band power consumption control through the iBMC.</p>
</td>
</tr>
<tr id="row667034813815"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001312397937_p1761405971619"><a name="en-us_topic_0000001312397937_p1761405971619"></a><a name="en-us_topic_0000001312397937_p1761405971619"></a>LOAD_AWARE</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001312397937_p161435931619"><a name="en-us_topic_0000001312397937_p161435931619"></a><a name="en-us_topic_0000001312397937_p161435931619"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p116708488813"><a name="p116708488813"></a><a name="p116708488813"></a>The <span id="ph39671037191013"><a name="ph39671037191013"></a><a name="ph39671037191013"></a>Ascend AI Processor</span> performs power consumption control by using the AI load-aware module.</p>
</td>
</tr>
</tbody>
</table>

**Table  3** Support in different deployment scenarios

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

**Example<a name="section207091751457"></a>**

```c
...
int ret = 0;
int dev_id = 0;
unsigned int sub_cmd=0;
unsigned int voltage_current_buf = 0;
unsigned int buf_size = 8;
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_LP, sub_cmd, &voltage_current_buf, &buf_size);
if (ret != 0) {
// TODO
return ret;
} else {
// TODO
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_TS<a id="EN-US_TOPIC_0000002348043797"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row1990019577303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p109001457133015"><a name="p109001457133015"></a><a name="p109001457133015"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1900175783013"><a name="p1900175783013"></a><a name="p1900175783013"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13900185710307"><a name="p13900185710307"></a><a name="p13900185710307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE = 0, // Obtain the single-core utilization of the AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE, // Obtain the single-core utilization of the Vector Core/Obtain the utilization of the Vector unit in the single AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_FFTS_TYPE, // Obtain the FFTS or FFTS+ type. The value <strong id="b18757855164218"><a name="b18757855164218"></a><a name="b18757855164218"></a>0</strong> indicates FFTS, and the value <strong id="b1075820556425"><a name="b1075820556425"></a><a name="b1075820556425"></a>1</strong> indicates FFTS+.
DCMI_TS_SUB_CMD_SET_FAULT_MASK, // Set the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_GET_FAULT_MASK, // Obtain the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_MAX, // Upper limit flag of enumerated values.
} DCMI_TS_SUB_CMD;</pre>
<p id="p20900857113015"><a name="p20900857113015"></a><a name="p20900857113015"></a>Only <strong id="b1441322834412"><a name="b1441322834412"></a><a name="b1441322834412"></a>DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE</strong>, <strong id="b16587153594413"><a name="b16587153594413"></a><a name="b16587153594413"></a>DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE</strong>, and <strong id="b172812043134415"><a name="b172812043134415"></a><a name="b172812043134415"></a>DCMI_TS_SUB_CMD_FFTS_TYPE</strong> are supported.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section2889103794114"></a>**

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
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p1290105717308"><a name="p1290105717308"></a><a name="p1290105717308"></a>For the query of single-core utilization of the Vector Core, <strong id="b54092035154514"><a name="b54092035154514"></a><a name="b54092035154514"></a>buf</strong> must be at least 72 bytes. For the query of single-core utilization of the AI Core, <strong id="b840917358453"><a name="b840917358453"></a><a name="b840917358453"></a>buf</strong> must be at least 36 bytes.</p>
<p id="p79011657193018"><a name="p79011657193018"></a><a name="p79011657193018"></a>Error values:</p>
<a name="ul16453131719569"></a><a name="ul16453131719569"></a><ul id="ul16453131719569"><li><strong id="b1080421465419"><a name="b1080421465419"></a><a name="b1080421465419"></a>0xEE</strong>: The corresponding core is damaged.</li><li><strong id="b1927772245418"><a name="b1927772245418"></a><a name="b1927772245418"></a>0xEF</strong>: invalid.</li></ul>
<p id="p290185713306"><a name="p290185713306"></a><a name="p290185713306"></a>As an output, each byte indicates the utilization of a core. The value ranges from 0 to 100.</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><a name="ul1265125812106"></a><a name="ul1265125812106"></a><ul id="ul1265125812106"><li>As an input, it indicates the buffer size.</li><li>As an output, it indicates the number of valid values in the buffer.</li></ul>
</td>
</tr>
<tr id="row6901185719303"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p179011357143018"><a name="p179011357143018"></a><a name="p179011357143018"></a>DCMI_TS_SUB_CMD_FFTS_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p89011657113020"><a name="p89011657113020"></a><a name="p89011657113020"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p12901115712303"><a name="p12901115712303"></a><a name="p12901115712303"></a>unsigned int</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table159431741121314"></a>
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

**Example<a name="section49611431655"></a>**

```c
...
int ret;
int dev_id = 0;
void *buf = NULL;
int buf_size = 36;
buf = calloc(buf_size, sizeof(char));
if (buf == NULL) {
printf("calloc buf failed.\n");
return -1;
}
ret = dcmiv2_get_device_info(dev_id,DCMI_MAIN_CMD_TS, DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE, buf, &buf_size);
if (ret != 0) {
printf("dcmiv2_get_device_info failed, ret = %d.\n", ret);
return -1;
}
return 0;
...
```

## DCMI\_MAIN\_CMD\_QOS<a id="EN-US_TOPIC_0000002347924125"></a>

**Prototype<a name="section14467101743119"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row19596817133118"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p185961717183110"><a name="p185961717183110"></a><a name="p185961717183110"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p195961517143118"><a name="p195961517143118"></a><a name="p195961517143118"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1359617171318"><a name="p1359617171318"></a><a name="p1359617171318"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
DCMI_QOS_SUB_MATA_CONFIG, // MATA configuration
DCMI_QOS_SUB_MASTER_CONFIG, // Master configuration
DCMI_QOS_SUB_BW_DATA, // Bandwidth statistics
DCMI_QOS_SUB_GLOBAL_CONFIG, // Global configuration
DCMI_QOS_SUB_CONFIG_DONE, // Completion instruction
} DCMI_QOS_SUB_INFO;</pre>
<p id="p5929173053615"><a name="p5929173053615"></a><a name="p5929173053615"></a>Only <strong id="b133328153462"><a name="b133328153462"></a><a name="b133328153462"></a>DCMI_QOS_SUB_MATA_CONFIG</strong>, <strong id="b85291120184610"><a name="b85291120184610"></a><a name="b85291120184610"></a>DCMI_QOS_SUB_MASTER_CONFIG</strong>, <strong id="b31001227154612"><a name="b31001227154612"></a><a name="b31001227154612"></a>DCMI_QOS_SUB_BW_DATA</strong>, and <strong id="b6511734114619"><a name="b6511734114619"></a><a name="b6511734114619"></a>DCMI_QOS_SUB_GLOBAL_CONFIG</strong> are supported.</p>
</td>
</tr>
<tr id="row1059751753117"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p165976179310"><a name="p165976179310"></a><a name="p165976179310"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p105971717153116"><a name="p105971717153116"></a><a name="p105971717153116"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13597191753119"><a name="p13597191753119"></a><a name="p13597191753119"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p13597161723117"><a name="p13597161723117"></a><a name="p13597161723117"></a>For details, see the restrictions in this section.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section2977135411511"></a>**

- Restricted by the SoC feature, call  [dcmiv2\_get\_device\_info](#EN-US_TOPIC_0000002314045082)  before calling the corresponding  **get**  API to read whether the configuration takes effect. Otherwise, the read value is unreliable.
- The function of obtaining the bandwidth by using  **resctrl**  conflicts with the function of obtaining the real-time bandwidth by using the DCMI. Do not use both simultaneously.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1450912173312"></a>
<table><thead align="left"><tr id="row1359861743110"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p16598617103119"><a name="p16598617103119"></a><a name="p16598617103119"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.2"><p id="p8598131713110"><a name="p8598131713110"></a><a name="p8598131713110"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p195981717153117"><a name="p195981717153117"></a><a name="p195981717153117"></a>buf_size</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.5.1.4"><p id="p559831773117"><a name="p559831773117"></a><a name="p559831773117"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1459821713316"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p18326161717112"><a name="p18326161717112"></a><a name="p18326161717112"></a>((mpamid &lt;&lt; 8) | DCMI_QOS_SUB_MATA_CONFIG)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.2 "><p id="p105981117163113"><a name="p105981117163113"></a><a name="p105981117163113"></a>struct dcmi_qos_mata_config{</p>
<p id="p15598181793119"><a name="p15598181793119"></a><a name="p15598181793119"></a>int mpamid;</p>
<p id="p14598121753118"><a name="p14598121753118"></a><a name="p14598121753118"></a>u32 bw_high;</p>
<p id="p105981917153115"><a name="p105981917153115"></a><a name="p105981917153115"></a>u32 bw_low;</p>
<p id="p7598117133110"><a name="p7598117133110"></a><a name="p7598117133110"></a>int hardlimit;</p>
<p id="p359881793112"><a name="p359881793112"></a><a name="p359881793112"></a>int reserved[8];</p>
<p id="p45981317203119"><a name="p45981317203119"></a><a name="p45981317203119"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p85982017103119"><a name="p85982017103119"></a><a name="p85982017103119"></a>sizeof(qos_mata_config)</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul72057196131"></a><a name="ul72057196131"></a><ul id="ul72057196131"><li><strong id="b101109116409"><a name="b101109116409"></a><a name="b101109116409"></a>mpamid</strong>: The value range is [0, 127].</li><li><strong id="b11850155013155"><a name="b11850155013155"></a><a name="b11850155013155"></a>bw_high</strong>: high waterline (GB/s). The value range is [0, 1638].</li><li><strong id="b118921933191016"><a name="b118921933191016"></a><a name="b118921933191016"></a>bw_low</strong>: low waterline (GB/s). The value range is [0, <strong id="b1189219335109"><a name="b1189219335109"></a><a name="b1189219335109"></a>bw_high</strong>].</li><li><strong id="b13970123521013"><a name="b13970123521013"></a><a name="b13970123521013"></a>hardlimit</strong>: The value <strong id="b2097173561010"><a name="b2097173561010"></a><a name="b2097173561010"></a>1</strong> indicates enabled, whereas the value <strong id="b3971123517106"><a name="b3971123517106"></a><a name="b3971123517106"></a>0</strong> indicates disabled.</li></ul>
<p id="p13599191773117"><a name="p13599191773117"></a><a name="p13599191773117"></a>The waterlines you read by using this subcommand may be different from those you set. Difference = Maximum processor bandwidth/<strong id="b75141916192911"><a name="b75141916192911"></a><a name="b75141916192911"></a>MAX_REG_VALUE</strong>. The value of <strong id="b58411121122918"><a name="b58411121122918"></a><a name="b58411121122918"></a>MAX_REG_VALUE</strong> is 1024.</p>
</td>
</tr>
<tr id="row1599121733110"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p2494122811114"><a name="p2494122811114"></a><a name="p2494122811114"></a>((master_id &lt;&lt; 8) | DCMI_QOS_SUB_MASTER_CONFIG)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.2 "><p id="p125995179319"><a name="p125995179319"></a><a name="p125995179319"></a>struct dcmi_qos_master_config{</p>
<p id="p165991417173110"><a name="p165991417173110"></a><a name="p165991417173110"></a>int master;</p>
<p id="p205995175318"><a name="p205995175318"></a><a name="p205995175318"></a>int mpamid;</p>
<p id="p45991117143117"><a name="p45991117143117"></a><a name="p45991117143117"></a>int qos;</p>
<p id="p145992172312"><a name="p145992172312"></a><a name="p145992172312"></a>int pmg;</p>
<p id="p1859961783120"><a name="p1859961783120"></a><a name="p1859961783120"></a>u64 bitmap[4];</p>
<p id="p728964251313"><a name="p728964251313"></a><a name="p728964251313"></a>unsigned int mode;</p>
<p id="p4599217193119"><a name="p4599217193119"></a><a name="p4599217193119"></a>int reserved[8];</p>
<p id="p4599171710317"><a name="p4599171710317"></a><a name="p4599171710317"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p259917179318"><a name="p259917179318"></a><a name="p259917179318"></a>sizeof(qos_master_config)</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul1553122412134"></a><a name="ul1553122412134"></a><ul id="ul1553122412134"><li><strong id="en-us_topic_0000002314204790_b1147421016319"><a name="en-us_topic_0000002314204790_b1147421016319"></a><a name="en-us_topic_0000002314204790_b1147421016319"></a>master</strong>: master ID, indicating the enumerated value of the chip accelerator. The supported configuration items include <strong id="en-us_topic_0000002314204790_b102561145203615"><a name="en-us_topic_0000002314204790_b102561145203615"></a><a name="en-us_topic_0000002314204790_b102561145203615"></a>vpc=2</strong>, <strong id="en-us_topic_0000002314204790_b53065016367"><a name="en-us_topic_0000002314204790_b53065016367"></a><a name="en-us_topic_0000002314204790_b53065016367"></a>jpge=3</strong>, <strong id="en-us_topic_0000002314204790_b394314597368"><a name="en-us_topic_0000002314204790_b394314597368"></a><a name="en-us_topic_0000002314204790_b394314597368"></a>jpgd=4</strong>, <strong id="en-us_topic_0000002314204790_b5271370375"><a name="en-us_topic_0000002314204790_b5271370375"></a><a name="en-us_topic_0000002314204790_b5271370375"></a>pcie=7</strong>, <strong id="en-us_topic_0000002314204790_b624419132373"><a name="en-us_topic_0000002314204790_b624419132373"></a><a name="en-us_topic_0000002314204790_b624419132373"></a>aic_data=9</strong>, <strong id="en-us_topic_0000002314204790_b133601883719"><a name="en-us_topic_0000002314204790_b133601883719"></a><a name="en-us_topic_0000002314204790_b133601883719"></a>aic_ins=10</strong>, <strong id="en-us_topic_0000002314204790_b18841922123718"><a name="en-us_topic_0000002314204790_b18841922123718"></a><a name="en-us_topic_0000002314204790_b18841922123718"></a>aiv_data=11</strong>, <strong id="en-us_topic_0000002314204790_b75561226153716"><a name="en-us_topic_0000002314204790_b75561226153716"></a><a name="en-us_topic_0000002314204790_b75561226153716"></a>aiv_ins=12</strong>, <strong id="en-us_topic_0000002314204790_b377215324377"><a name="en-us_topic_0000002314204790_b377215324377"></a><a name="en-us_topic_0000002314204790_b377215324377"></a>sdma=13</strong>, <strong id="en-us_topic_0000002314204790_b81181737123713"><a name="en-us_topic_0000002314204790_b81181737123713"></a><a name="en-us_topic_0000002314204790_b81181737123713"></a>stars=14</strong>, <strong id="en-us_topic_0000002314204790_b1140613444371"><a name="en-us_topic_0000002314204790_b1140613444371"></a><a name="en-us_topic_0000002314204790_b1140613444371"></a>ub_mem=33</strong>, <strong id="en-us_topic_0000002314204790_b13214854123711"><a name="en-us_topic_0000002314204790_b13214854123711"></a><a name="en-us_topic_0000002314204790_b13214854123711"></a>pcie_ibr=40</strong>, and <strong id="en-us_topic_0000002314204790_b05521704387"><a name="en-us_topic_0000002314204790_b05521704387"></a><a name="en-us_topic_0000002314204790_b05521704387"></a>pcie_ibw=41</strong>.</li></ul>
<a name="ul13380123561319"></a><a name="ul13380123561319"></a><ul id="ul13380123561319"><li><strong id="b1984513114915"><a name="b1984513114915"></a><a name="b1984513114915"></a>mpamid</strong>: label for identifying the data flow of the chip accelerator. The value range is [0, 127].<div class="note" id="note19682131512477"><a name="note19682131512477"></a><a name="note19682131512477"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002314204790_p6682191518479"><a name="en-us_topic_0000002314204790_p6682191518479"></a><a name="en-us_topic_0000002314204790_p6682191518479"></a>When the value of <strong id="en-us_topic_0000002314204790_b734351903915"><a name="en-us_topic_0000002314204790_b734351903915"></a><a name="en-us_topic_0000002314204790_b734351903915"></a>master</strong> is <strong id="en-us_topic_0000002314204790_b295123103913"><a name="en-us_topic_0000002314204790_b295123103913"></a><a name="en-us_topic_0000002314204790_b295123103913"></a>pcie</strong>, <strong id="en-us_topic_0000002314204790_b126648250395"><a name="en-us_topic_0000002314204790_b126648250395"></a><a name="en-us_topic_0000002314204790_b126648250395"></a>pcie_ibr</strong>, or <strong id="en-us_topic_0000002314204790_b7716328173918"><a name="en-us_topic_0000002314204790_b7716328173918"></a><a name="en-us_topic_0000002314204790_b7716328173918"></a>pcie_ibw</strong>, the value range of <strong id="en-us_topic_0000002314204790_b1742173293914"><a name="en-us_topic_0000002314204790_b1742173293914"></a><a name="en-us_topic_0000002314204790_b1742173293914"></a>mpamid</strong> is [0, 31].</p>
</div></div>
</li><li><strong id="b10793166104511"><a name="b10793166104511"></a><a name="b10793166104511"></a>qos</strong>: bandwidth scheduling priority. The value range is [0, 7]. The value <strong id="b779713674518"><a name="b779713674518"></a><a name="b779713674518"></a>0</strong> indicates hardlimit QoS, and the value <strong id="b15799862454"><a name="b15799862454"></a><a name="b15799862454"></a>7</strong> indicates green channel QoS.</li><li><strong id="b1864216508735"><a name="b1864216508735"></a><a name="b1864216508735"></a>pmg</strong>: mpamid group. The value range is [0, 3] (not supported currently).</li><li><strong id="b159231553391"><a name="b159231553391"></a><a name="b159231553391"></a>bitmap</strong>: bitmap of the target core. This parameter is not supported due to framework restrictions.</li></ul>
</td>
</tr>
<tr id="row185991417153117"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p777812501311"><a name="p777812501311"></a><a name="p777812501311"></a>((mpamid &lt;&lt; 8) | DCMI_QOS_SUB_BW_DATA)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.2 "><p id="p8599817113120"><a name="p8599817113120"></a><a name="p8599817113120"></a>struct dcmi_qos_bw_result{</p>
<p id="p18600131743116"><a name="p18600131743116"></a><a name="p18600131743116"></a>int mpamid;</p>
<p id="p4600101763114"><a name="p4600101763114"></a><a name="p4600101763114"></a>u32 curr;</p>
<p id="p11600191714316"><a name="p11600191714316"></a><a name="p11600191714316"></a>u32 bw_max;</p>
<p id="p060018172318"><a name="p060018172318"></a><a name="p060018172318"></a>u32 bw_min;</p>
<p id="p960051723117"><a name="p960051723117"></a><a name="p960051723117"></a>u32 bw_mean;</p>
<p id="p86000174315"><a name="p86000174315"></a><a name="p86000174315"></a>int reserved[8];</p>
<p id="p16003175318"><a name="p16003175318"></a><a name="p16003175318"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p156001179310"><a name="p156001179310"></a><a name="p156001179310"></a>sizeof(qos_bw_result)</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul1366017281415"></a><a name="ul1366017281415"></a><ul id="ul1366017281415"><li><strong id="b75701043171011"><a name="b75701043171011"></a><a name="b75701043171011"></a>mpamid</strong>: target mpamid to obtain the bandwidth. The value range is [0, 127].</li><li><strong id="b06472039111616"><a name="b06472039111616"></a><a name="b06472039111616"></a>curr</strong>: latest bandwidth (MB/s).</li><li><strong id="b73860561163"><a name="b73860561163"></a><a name="b73860561163"></a>bw_max</strong>: maximum value (MB/s) over the sampling period.</li><li><strong id="b81405412177"><a name="b81405412177"></a><a name="b81405412177"></a>bw_min</strong>: minimum value (MB/s) over the sampling period.</li><li><strong id="b54362015101714"><a name="b54362015101714"></a><a name="b54362015101714"></a>bw_mean</strong>: mean value (MB/s) over the sampling period.</li></ul>
</td>
</tr>
<tr id="row1560041716314"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p51661741126"><a name="p51661741126"></a><a name="p51661741126"></a>((enable &lt;&lt; 8) | DCMI_QOS_SUB_GLOBAL_CONFIG)</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.2 "><p id="p3600717123114"><a name="p3600717123114"></a><a name="p3600717123114"></a>struct dcmi_qos_gbl_config{</p>
<p id="p3600131783116"><a name="p3600131783116"></a><a name="p3600131783116"></a>u32 enable;</p>
<p id="p126002177317"><a name="p126002177317"></a><a name="p126002177317"></a>u32 autoqos_fuse_en;</p>
<p id="p860021763110"><a name="p860021763110"></a><a name="p860021763110"></a>u32 mpamqos_fuse_mode;</p>
<p id="p16001617133115"><a name="p16001617133115"></a><a name="p16001617133115"></a>u32 mpam_subtype;</p>
<p id="p1600117143115"><a name="p1600117143115"></a><a name="p1600117143115"></a>int reserved[8];</p>
<p id="p126006174314"><a name="p126006174314"></a><a name="p126006174314"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p14600617163113"><a name="p14600617163113"></a><a name="p14600617163113"></a>sizeof(qos_gbl_config)</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul15992846123713"></a><a name="ul15992846123713"></a><ul id="ul15992846123713"><li><strong id="b313142611170"><a name="b313142611170"></a><a name="b313142611170"></a>enable</strong>: whether to enable the QoS function.<a name="ul1426935273713"></a><a name="ul1426935273713"></a><ul id="ul1426935273713"><li><strong id="b9076233248735"><a name="b9076233248735"></a><a name="b9076233248735"></a>0</strong>: disabled</li><li><strong id="b13081403288735"><a name="b13081403288735"></a><a name="b13081403288735"></a>1</strong>: enabled</li></ul>
</li><li><strong id="b186712385178"><a name="b186712385178"></a><a name="b186712385178"></a>autoqos_fuse_en</strong>: whether to enable QoS fusion.<a name="ul161181811163814"></a><a name="ul161181811163814"></a><ul id="ul161181811163814"><li><strong id="b162198017314"><a name="b162198017314"></a><a name="b162198017314"></a>0</strong>: QoS fusion is disabled.</li><li><strong id="b275414383116"><a name="b275414383116"></a><a name="b275414383116"></a>1</strong>: QoS fusion starts.</li></ul>
</li><li><strong id="b97251750181710"><a name="b97251750181710"></a><a name="b97251750181710"></a>mpamqos_fuse_mode</strong>: QoS fusion mode. This parameter takes effect when <strong id="b167260505174"><a name="b167260505174"></a><a name="b167260505174"></a>autoqos_fuse_en</strong> is enabled.<a name="ul879644411386"></a><a name="ul879644411386"></a><ul id="ul879644411386"><li><strong id="b16170783408735"><a name="b16170783408735"></a><a name="b16170783408735"></a>0</strong>: average fusion</li><li><strong id="b1130154717456"><a name="b1130154717456"></a><a name="b1130154717456"></a>1</strong>: maximum value between the associated QoS and MPAM QoS</li><li><strong id="b3257858608735"><a name="b3257858608735"></a><a name="b3257858608735"></a>2</strong>: associated QoS as MPAM QoS</li></ul>
</li><li><strong id="b8837144678735"><a name="b8837144678735"></a><a name="b8837144678735"></a>mpam_subtype</strong>: bandwidth statistics mode<a name="ul16435328393"></a><a name="ul16435328393"></a><ul id="ul16435328393"><li><strong id="b4378217158735"><a name="b4378217158735"></a><a name="b4378217158735"></a>0</strong>: read and write bandwidth statistics</li><li><strong id="b13358349858735"><a name="b13358349858735"></a><a name="b13358349858735"></a>1</strong>: write bandwidth statistics</li><li><strong id="b20699086758735"><a name="b20699086758735"></a><a name="b20699086758735"></a>2</strong>: read bandwidth statistics</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row14793950814"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p679315517810"><a name="en-us_topic_0000002347924121_p679315517810"></a><a name="en-us_topic_0000002347924121_p679315517810"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p179310514818"><a name="en-us_topic_0000002347924121_p179310514818"></a><a name="en-us_topic_0000002347924121_p179310514818"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1079395582"><a name="en-us_topic_0000002347924121_p1079395582"></a><a name="en-us_topic_0000002347924121_p1079395582"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p197931351285"><a name="en-us_topic_0000002347924121_p197931351285"></a><a name="en-us_topic_0000002347924121_p197931351285"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p879318516814"><a name="en-us_topic_0000002347924121_p879318516814"></a><a name="en-us_topic_0000002347924121_p879318516814"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row11793151389"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p147931153816"><a name="en-us_topic_0000002347924121_p147931153816"></a><a name="en-us_topic_0000002347924121_p147931153816"></a><strong id="en-us_topic_0000002347924121_b740342956"><a name="en-us_topic_0000002347924121_b740342956"></a><a name="en-us_topic_0000002347924121_b740342956"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p2793451784"><a name="en-us_topic_0000002347924121_p2793451784"></a><a name="en-us_topic_0000002347924121_p2793451784"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b1727384221"><a name="en-us_topic_0000002347924121_b1727384221"></a><a name="en-us_topic_0000002347924121_b1727384221"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p4793151781"><a name="en-us_topic_0000002347924121_p4793151781"></a><a name="en-us_topic_0000002347924121_p4793151781"></a><strong id="en-us_topic_0000002347924121_b313129067"><a name="en-us_topic_0000002347924121_b313129067"></a><a name="en-us_topic_0000002347924121_b313129067"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p1479319510810"><a name="en-us_topic_0000002347924121_p1479319510810"></a><a name="en-us_topic_0000002347924121_p1479319510810"></a><strong id="en-us_topic_0000002347924121_b690423339"><a name="en-us_topic_0000002347924121_b690423339"></a><a name="en-us_topic_0000002347924121_b690423339"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p207938516814"><a name="en-us_topic_0000002347924121_p207938516814"></a><a name="en-us_topic_0000002347924121_p207938516814"></a><strong id="en-us_topic_0000002347924121_b841081757"><a name="en-us_topic_0000002347924121_b841081757"></a><a name="en-us_topic_0000002347924121_b841081757"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row6793185686"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p47931353814"><a name="en-us_topic_0000002347924121_p47931353814"></a><a name="en-us_topic_0000002347924121_p47931353814"></a><span id="en-us_topic_0000002347924121_ph4793452817"><a name="en-us_topic_0000002347924121_ph4793452817"></a><a name="en-us_topic_0000002347924121_ph4793452817"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p197931951183"><a name="en-us_topic_0000002347924121_p197931951183"></a><a name="en-us_topic_0000002347924121_p197931951183"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p5335612280"><a name="en-us_topic_0000002347924121_p5335612280"></a><a name="en-us_topic_0000002347924121_p5335612280"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p10793857815"><a name="en-us_topic_0000002347924121_p10793857815"></a><a name="en-us_topic_0000002347924121_p10793857815"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p979319512813"><a name="en-us_topic_0000002347924121_p979319512813"></a><a name="en-us_topic_0000002347924121_p979319512813"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p8793451183"><a name="en-us_topic_0000002347924121_p8793451183"></a><a name="en-us_topic_0000002347924121_p8793451183"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row137945514817"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p18794451582"><a name="en-us_topic_0000002347924121_p18794451582"></a><a name="en-us_topic_0000002347924121_p18794451582"></a><span id="en-us_topic_0000002347924121_ph1678810203610"><a name="en-us_topic_0000002347924121_ph1678810203610"></a><a name="en-us_topic_0000002347924121_ph1678810203610"></a>Note: <strong id="en-us_topic_0000002347924121_b4788170103612"><a name="en-us_topic_0000002347924121_b4788170103612"></a><a name="en-us_topic_0000002347924121_b4788170103612"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b11788200153618"><a name="en-us_topic_0000002347924121_b11788200153618"></a><a name="en-us_topic_0000002347924121_b11788200153618"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b19788120123620"><a name="en-us_topic_0000002347924121_b19788120123620"></a><a name="en-us_topic_0000002347924121_b19788120123620"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section176618596619"></a>**

```c
...
int ret = 0;
int dev_id = 0;
int size = sizeof(struct dcmi_qos_mata_config);
struct dcmi_qos_mata_config mataCfg = {0};
mataCfg.mpamid = 127;
unsigned int subCmd = (unsigned int)(DCMI_QOS_SUB_CMD_MAKE(mataCfg.mpamid, DCMI_QOS_SUB_MATA_CONFIG));
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_QOS, subCmd, (void *)&mataCfg, &size);
if (ret != 0) {
// TODO
return ret;
} else {
// TODO
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_VDEV\_MNG<a id="EN-US_TOPIC_0000002348043801"></a>

**Prototype<a name="section1189012593314"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row3222180143219"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p92225043213"><a name="p92225043213"></a><a name="p92225043213"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p62221307320"><a name="p62221307320"></a><a name="p62221307320"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p72229016329"><a name="p72229016329"></a><a name="p72229016329"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
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
<p id="p1222407325"><a name="p1222407325"></a><a name="p1222407325"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE, // Obtain resource information of a single virtual device.</p>
<p id="p52221309326"><a name="p52221309326"></a><a name="p52221309326"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, // Obtain the total resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p62221905329"><a name="p62221905329"></a><a name="p62221905329"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE, // Obtain the unused resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p1422215018326"><a name="p1422215018326"></a><a name="p1422215018326"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH, // Set the SR-IOV function.</p>
<p id="p1042418509199"><a name="p1042418509199"></a><a name="p1042418509199"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY = 5, // Obtain the AI Core usage of a virtual SoC device.</p>
<p id="p722210163215"><a name="p722210163215"></a><a name="p722210163215"></a>DCMI_VMNG_SUB_CMD_MAX, // Upper limit flag of enumerated values.</p>
<p id="p522260133219"><a name="p522260133219"></a><a name="p522260133219"></a>} DCMI_VDEV_MNG_SUB_CMD;</p>
<p id="p1539418497167"><a name="p1539418497167"></a><a name="p1539418497167"></a>Only <strong id="b166611765016"><a name="b166611765016"></a><a name="b166611765016"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE</strong>, <strong id="b1025222455015"><a name="b1025222455015"></a><a name="b1025222455015"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE</strong>, <strong id="b871012915014"><a name="b871012915014"></a><a name="b871012915014"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE</strong>, and <strong id="b164771335105012"><a name="b164771335105012"></a><a name="b164771335105012"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY</strong> are supported.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section194071571789"></a>**

- When this API is called,  **sub\_cmd**  must correspond to  [Table 1](#table1499155916318), and  **buf\_size**  indicates the size of the corresponding buffer data structure.
- To use this API to obtain resources, set the environment to the SR-IOV mode.
- When you query basic and resource information, if the corresponding product form is not supported, see the option description in  [Table 2](#table1567919386575)  for the returned value.

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
<p id="p1523701910588"><a name="p1523701910588"></a><a name="p1523701910588"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p14223100143214"><a name="p14223100143214"></a><a name="p14223100143214"></a>struct dcmi_vdev_query_stru {</p>
<p id="p172234013218"><a name="p172234013218"></a><a name="p172234013218"></a>unsigned int vdev_id;</p>
<p id="p22234043220"><a name="p22234043220"></a><a name="p22234043220"></a>struct dcmi_vdev_query_info query_info;</p>
<p id="p1822313043218"><a name="p1822313043218"></a><a name="p1822313043218"></a>}</p>
<p id="p1622316033219"><a name="p1622316033219"></a><a name="p1622316033219"></a><strong id="b868613597583"><a name="b868613597583"></a><a name="b868613597583"></a>query_info</strong> indicates the queried virtual device information. Its structure is as follows:</p>
<p id="p1722340183213"><a name="p1722340183213"></a><a name="p1722340183213"></a>#define DCMI_VDEV_RES_NAME_LEN 16</p>
<p id="p322380103210"><a name="p322380103210"></a><a name="p322380103210"></a>struct dcmi_vdev_query_info {</p>
<p id="p172237014328"><a name="p172237014328"></a><a name="p172237014328"></a>char name[DCMI_VDEV_RES_NAME_LEN];</p>
<p id="p6223110183211"><a name="p6223110183211"></a><a name="p6223110183211"></a>unsigned int status;</p>
<p id="p62231809326"><a name="p62231809326"></a><a name="p62231809326"></a>unsigned int is_container_used;</p>
<p id="p32236018325"><a name="p32236018325"></a><a name="p32236018325"></a>unsigned int vfid;</p>
<p id="p92238053213"><a name="p92238053213"></a><a name="p92238053213"></a>unsigned int vfg_id;</p>
<p id="p1322370113218"><a name="p1322370113218"></a><a name="p1322370113218"></a>unsigned long long container_id;</p>
<p id="p172231004322"><a name="p172231004322"></a><a name="p172231004322"></a>struct dcmi_base_resource base;</p>
<p id="p1922316011328"><a name="p1922316011328"></a><a name="p1922316011328"></a>struct dcmi_computing_resource computing;</p>
<p id="p172231502321"><a name="p172231502321"></a><a name="p172231502321"></a>struct dcmi_media_resource media;</p>
<p id="p322313010325"><a name="p322313010325"></a><a name="p322313010325"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul1512412249211"></a><a name="ul1512412249211"></a><ul id="ul1512412249211"><li><strong id="b7630154443115"><a name="b7630154443115"></a><a name="b7630154443115"></a>vdev_id</strong> indicates the virtual device ID, which is used as the input information.</li><li><strong id="b161911225191912"><a name="b161911225191912"></a><a name="b161911225191912"></a>name</strong>: name specified during virtual device creation.</li><li><strong id="b82491220132510"><a name="b82491220132510"></a><a name="b82491220132510"></a>status</strong>: (reserved) virtual device status.</li><li><strong id="b155720722014"><a name="b155720722014"></a><a name="b155720722014"></a>is_container_used</strong>: whether the current container is used.</li><li><strong id="b12128934132014"><a name="b12128934132014"></a><a name="b12128934132014"></a>vfid</strong>: sequence number of the VF used by the virtual device.</li><li><strong id="b598268173119"><a name="b598268173119"></a><a name="b598268173119"></a>vfg_id</strong>: ID of the VFG used by the virtual device.</li><li><strong id="b17993101214"><a name="b17993101214"></a><a name="b17993101214"></a>container_id</strong>: container ID.</li><li><strong id="b157851462111"><a name="b157851462111"></a><a name="b157851462111"></a>base</strong>: basic information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b103801027102115"><a name="b103801027102115"></a><a name="b103801027102115"></a>computing</strong>: computing resource information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1677183812306"><a name="b1677183812306"></a><a name="b1677183812306"></a>media</strong>: media resource information of the virtual device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
<tr id="row52243093216"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p1422412015326"><a name="p1422412015326"></a><a name="p1422412015326"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p12241005325"><a name="p12241005325"></a><a name="p12241005325"></a>#define DCMI_SOC_SPLIT_MAX 32</p>
<p id="p18224120193213"><a name="p18224120193213"></a><a name="p18224120193213"></a>struct dcmi_soc_total_resource {</p>
<p id="p1622420163211"><a name="p1622420163211"></a><a name="p1622420163211"></a>unsigned int vdev_num;</p>
<p id="p022415023211"><a name="p022415023211"></a><a name="p022415023211"></a>unsigned int vdev_id[DCMI_SOC_SPLIT_MAX];</p>
<p id="p62241015329"><a name="p62241015329"></a><a name="p62241015329"></a>unsigned int vfg_num;</p>
<p id="p162241007321"><a name="p162241007321"></a><a name="p162241007321"></a>unsigned int vfg_bitmap;</p>
<p id="p13224170163215"><a name="p13224170163215"></a><a name="p13224170163215"></a>struct dcmi_base_resource base;</p>
<p id="p192246033213"><a name="p192246033213"></a><a name="p192246033213"></a>struct dcmi_computing_resource computing;</p>
<p id="p182246093217"><a name="p182246093217"></a><a name="p182246093217"></a>struct dcmi_media_resource media;</p>
<p id="p1522415023214"><a name="p1522415023214"></a><a name="p1522415023214"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul20252101215414"></a><a name="ul20252101215414"></a><ul id="ul20252101215414"><li><strong id="b109677575214"><a name="b109677575214"></a><a name="b109677575214"></a>vdev_num</strong>: number of virtual devices in a specified SoC device.</li><li><strong id="b525811218227"><a name="b525811218227"></a><a name="b525811218227"></a>vdev_id</strong>: virtual device ID.</li><li><strong id="b0668144013222"><a name="b0668144013222"></a><a name="b0668144013222"></a>vfg_num</strong>: total number of VFGs in a specified SoC device. Not supported currently.</li><li><strong id="b852981818231"><a name="b852981818231"></a><a name="b852981818231"></a>vfg_bitmap</strong>: VFG bitmap of the device. Each bit corresponds to a VFG. The value <strong id="b125301218182312"><a name="b125301218182312"></a><a name="b125301218182312"></a>1</strong> indicates valid. Not supported currently.</li><li><strong id="b7394636132311"><a name="b7394636132311"></a><a name="b7394636132311"></a>base</strong>: general basic information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1745147152310"><a name="b1745147152310"></a><a name="b1745147152310"></a>computing</strong>: total computing resource information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1964013375337"><a name="b1964013375337"></a><a name="b1964013375337"></a>media</strong>: total media resource information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
<tr id="row62242063213"><td class="cellrowborder" valign="top" width="30.080000000000002%" headers="mcps1.2.4.1.1 "><p id="p02241202328"><a name="p02241202328"></a><a name="p02241202328"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="43.46%" headers="mcps1.2.4.1.2 "><p id="p3224200143215"><a name="p3224200143215"></a><a name="p3224200143215"></a>struct dcmi_soc_free_resource {</p>
<p id="p5224130133213"><a name="p5224130133213"></a><a name="p5224130133213"></a>unsigned int vfg_num;</p>
<p id="p62249010329"><a name="p62249010329"></a><a name="p62249010329"></a>unsigned int vfg_bitmap;</p>
<p id="p1922417023219"><a name="p1922417023219"></a><a name="p1922417023219"></a>struct dcmi_base_resource base;</p>
<p id="p7224106328"><a name="p7224106328"></a><a name="p7224106328"></a>struct dcmi_computing_resource computing;</p>
<p id="p922413012328"><a name="p922413012328"></a><a name="p922413012328"></a>struct dcmi_media_resource media;</p>
<p id="p122411063216"><a name="p122411063216"></a><a name="p122411063216"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="26.46%" headers="mcps1.2.4.1.3 "><a name="ul14775720049"></a><a name="ul14775720049"></a><ul id="ul14775720049"><li><strong id="b537922132413"><a name="b537922132413"></a><a name="b537922132413"></a>vfg_num</strong>: number of unused VFGs in a specified SoC device. Not supported currently.</li><li><strong id="b83540415241"><a name="b83540415241"></a><a name="b83540415241"></a>vfg_bitmap</strong>: VFG bitmap of the device. Each bit corresponds to a VFG. The value <strong id="b1835534142414"><a name="b1835534142414"></a><a name="b1835534142414"></a>1</strong> indicates unused. Not supported currently.</li><li><strong id="b144239115611"><a name="b144239115611"></a><a name="b144239115611"></a>base</strong>: unused basic information of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b114782527555"><a name="b114782527555"></a><a name="b114782527555"></a>computing</strong>: information about unused computing resources of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li><li><strong id="b1129119561364"><a name="b1129119561364"></a><a name="b1129119561364"></a>media</strong>: information about remaining media resources of a specified SoC device. For details, see <a href="#table1567919386575">Table 2</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2**  Basic and resource information structures

<a name="table1567919386575"></a>
<table><thead align="left"><tr id="row12671173813574"><th class="cellrowborder" valign="top" width="15%" id="mcps1.2.6.1.1"><p id="p186708382574"><a name="p186708382574"></a><a name="p186708382574"></a>Information Type</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.2.6.1.2"><p id="p5670138195718"><a name="p5670138195718"></a><a name="p5670138195718"></a>Structure</p>
</th>
<th class="cellrowborder" valign="top" width="15%" id="mcps1.2.6.1.3"><p id="p19670153855717"><a name="p19670153855717"></a><a name="p19670153855717"></a>Option</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.6.1.4"><p id="p136702038145711"><a name="p136702038145711"></a><a name="p136702038145711"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="15%" id="mcps1.2.6.1.5"><p id="p18670113885713"><a name="p18670113885713"></a><a name="p18670113885713"></a>Supported Form</p>
</th>
</tr>
</thead>
<tbody><tr id="row967163815572"><td class="cellrowborder" rowspan="5" valign="top" width="15%" headers="mcps1.2.6.1.1 "><p id="p9671163818579"><a name="p9671163818579"></a><a name="p9671163818579"></a>Basic information</p>
</td>
<td class="cellrowborder" rowspan="5" valign="top" width="30%" headers="mcps1.2.6.1.2 "><p id="p5671238185711"><a name="p5671238185711"></a><a name="p5671238185711"></a>#define DCMI_VDEV_FOR_RESERVE 32</p>
<p id="p4671153805719"><a name="p4671153805719"></a><a name="p4671153805719"></a>struct dcmi_base_resource {</p>
<p id="p1167116387573"><a name="p1167116387573"></a><a name="p1167116387573"></a>unsigned long long token;</p>
<p id="p76711238175711"><a name="p76711238175711"></a><a name="p76711238175711"></a>unsigned long long token_max;</p>
<p id="p2671183814573"><a name="p2671183814573"></a><a name="p2671183814573"></a>unsigned long long task_timeout;</p>
<p id="p166711538165713"><a name="p166711538165713"></a><a name="p166711538165713"></a>unsigned int vfg_id;</p>
<p id="p156711238165715"><a name="p156711238165715"></a><a name="p156711238165715"></a>unsigned char vip_mode;</p>
<p id="p1967133810574"><a name="p1967133810574"></a><a name="p1967133810574"></a>unsigned char reserved[DCMI_VDEV_FOR_RESERVE - 1];</p>
<p id="p66719389572"><a name="p66719389572"></a><a name="p66719389572"></a>/* bytes aligned */</p>
<p id="p18671143811570"><a name="p18671143811570"></a><a name="p18671143811570"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.2.6.1.3 "><p id="p106714389577"><a name="p106714389577"></a><a name="p106714389577"></a>token</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.6.1.4 "><p id="p7671143895715"><a name="p7671143895715"></a><a name="p7671143895715"></a>Number of cycles taken by virtual devices when time-division multiplexing (TDM) is applied to the VFG.</p>
<p id="p1567163817574"><a name="p1567163817574"></a><a name="p1567163817574"></a>If this option is not supported, <strong id="b9293115610112"><a name="b9293115610112"></a><a name="b9293115610112"></a>0xFFFFFFFFFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.2.6.1.5 "><p id="p187612025916"><a name="p187612025916"></a><a name="p187612025916"></a>None</p>
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
<tr id="row267333811572"><td class="cellrowborder" rowspan="23" valign="top" width="15%" headers="mcps1.2.6.1.1 "><p id="p767293818576"><a name="p767293818576"></a><a name="p767293818576"></a>Computing power resource information</p>
</td>
<td class="cellrowborder" rowspan="23" valign="top" width="30%" headers="mcps1.2.6.1.2 "><p id="p1477115963515"><a name="p1477115963515"></a><a name="p1477115963515"></a>#define DCMI_ULONG_LONG_SIZE        sizeof(unsigned long long)</p>
<p id="p1747745973511"><a name="p1747745973511"></a><a name="p1747745973511"></a>#define DCMI_UINT_SIZE              sizeof(unsigned int)</p>
<p id="p8477159193512"><a name="p8477159193512"></a><a name="p8477159193512"></a>#define DCMI_VDEV_SIZE              ((2 * DCMI_ULONG_LONG_SIZE) + DCMI_UINT_SIZE)</p>
<p id="p196721038195711"><a name="p196721038195711"></a><a name="p196721038195711"></a>struct dcmi_computing_resource {</p>
<p id="p19672183865720"><a name="p19672183865720"></a><a name="p19672183865720"></a>/* accelerator resource */</p>
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
<p id="p1185710710244"><a name="p1185710710244"></a><a name="p1185710710244"></a>/* vnpu resource */</p>
<p id="p188570722416"><a name="p188570722416"></a><a name="p188570722416"></a>unsigned int vdev_aicore_utilization;</p>
<p id="p985707172411"><a name="p985707172411"></a><a name="p985707172411"></a>unsigned long long vdev_memory_total;</p>
<p id="p13857207152416"><a name="p13857207152416"></a><a name="p13857207152416"></a>unsigned long long vdev_memory_free;</p>
<p id="p12673193885714"><a name="p12673193885714"></a><a name="p12673193885714"></a>unsigned char reserved[DCMI_VDEV_FOR_RESERVE - DCMI_VDEV_SIZE];</p>
<p id="p106731638205718"><a name="p106731638205718"></a><a name="p106731638205718"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.2.6.1.3 "><p id="p136738381571"><a name="p136738381571"></a><a name="p136738381571"></a>aic</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.6.1.4 "><p id="p1067333820577"><a name="p1067333820577"></a><a name="p1067333820577"></a>Number of AI Cores.</p>
<p id="p136736384570"><a name="p136736384570"></a><a name="p136736384570"></a>If this option is not supported, <strong id="b10675346448652"><a name="b10675346448652"></a><a name="b10675346448652"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.2.6.1.5 "><p id="p11673838135712"><a name="p11673838135712"></a><a name="p11673838135712"></a>None</p>
</td>
</tr>
<tr id="row467333810579"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p36739385576"><a name="p36739385576"></a><a name="p36739385576"></a>aiv</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p867312386575"><a name="p867312386575"></a><a name="p867312386575"></a>ai_vector number.</p>
<p id="p06733389573"><a name="p06733389573"></a><a name="p06733389573"></a>If this option is not supported, <strong id="b172131120195517"><a name="b172131120195517"></a><a name="b172131120195517"></a>-1.0</strong> is returned.</p>
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
<p id="p6674123817576"><a name="p6674123817576"></a><a name="p6674123817576"></a>If this option is not supported, <strong id="b098643515556"><a name="b098643515556"></a><a name="b098643515556"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p76741838175711"><a name="p76741838175711"></a><a name="p76741838175711"></a>None</p>
</td>
</tr>
<tr id="row1767473805718"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p166741038115716"><a name="p166741038115716"></a><a name="p166741038115716"></a>acsq</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p06741238195712"><a name="p06741238195712"></a><a name="p06741238195712"></a>acsq number.</p>
<p id="p15674153825710"><a name="p15674153825710"></a><a name="p15674153825710"></a>If this option is not supported, <strong id="b11151944185513"><a name="b11151944185513"></a><a name="b11151944185513"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p867413819572"><a name="p867413819572"></a><a name="p867413819572"></a>None</p>
</td>
</tr>
<tr id="row156741238175715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1674193819578"><a name="p1674193819578"></a><a name="p1674193819578"></a>cdqm</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1167473825713"><a name="p1167473825713"></a><a name="p1167473825713"></a>cdqm number.</p>
<p id="p10674163805713"><a name="p10674163805713"></a><a name="p10674163805713"></a>If this option is not supported, <strong id="b5605164911558"><a name="b5605164911558"></a><a name="b5605164911558"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p20674138125712"><a name="p20674138125712"></a><a name="p20674138125712"></a>None</p>
</td>
</tr>
<tr id="row467433816573"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1767433816575"><a name="p1767433816575"></a><a name="p1767433816575"></a>c_core</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p16674173819570"><a name="p16674173819570"></a><a name="p16674173819570"></a>c_core number.</p>
<p id="p1267413382577"><a name="p1267413382577"></a><a name="p1267413382577"></a>If this option is not supported, <strong id="b6876655165518"><a name="b6876655165518"></a><a name="b6876655165518"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p15674123816576"><a name="p15674123816576"></a><a name="p15674123816576"></a>None</p>
</td>
</tr>
<tr id="row26759386571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p7674123845714"><a name="p7674123845714"></a><a name="p7674123845714"></a>ffts</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p146747385578"><a name="p146747385578"></a><a name="p146747385578"></a>ffts number.</p>
<p id="p1267418384579"><a name="p1267418384579"></a><a name="p1267418384579"></a>If this option is not supported, <strong id="b17244145925512"><a name="b17244145925512"></a><a name="b17244145925512"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p967414386579"><a name="p967414386579"></a><a name="p967414386579"></a>None</p>
</td>
</tr>
<tr id="row367563875720"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p46751438135714"><a name="p46751438135714"></a><a name="p46751438135714"></a>sdma</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p13675103855718"><a name="p13675103855718"></a><a name="p13675103855718"></a>Number of SDMA channels.</p>
<p id="p1667583815710"><a name="p1667583815710"></a><a name="p1667583815710"></a>If this option is not supported, <strong id="b3692113145618"><a name="b3692113145618"></a><a name="b3692113145618"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1567523814577"><a name="p1567523814577"></a><a name="p1567523814577"></a>None</p>
</td>
</tr>
<tr id="row11675133816571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p20675123815719"><a name="p20675123815719"></a><a name="p20675123815719"></a>pcie_dma</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p156755383576"><a name="p156755383576"></a><a name="p156755383576"></a>Number of PCIe DMA channels.</p>
<p id="p16759388577"><a name="p16759388577"></a><a name="p16759388577"></a>If this option is not supported, <strong id="b1685615655610"><a name="b1685615655610"></a><a name="b1685615655610"></a>0xFFFF</strong> is returned.</p>
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
<p id="p14675173855720"><a name="p14675173855720"></a><a name="p14675173855720"></a>If this option is not supported, <strong id="b594425805612"><a name="b594425805612"></a><a name="b594425805612"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p967583813571"><a name="p967583813571"></a><a name="p967583813571"></a>None</p>
</td>
</tr>
<tr id="row3676738195712"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1067613865715"><a name="p1067613865715"></a><a name="p1067613865715"></a>stream_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p967603825710"><a name="p967603825710"></a><a name="p967603825710"></a>Number of stream IDs.</p>
<p id="p5676183835711"><a name="p5676183835711"></a><a name="p5676183835711"></a>If this option is not supported, <strong id="b131218616578"><a name="b131218616578"></a><a name="b131218616578"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p36769387575"><a name="p36769387575"></a><a name="p36769387575"></a>None</p>
</td>
</tr>
<tr id="row13676538155714"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1367613381570"><a name="p1367613381570"></a><a name="p1367613381570"></a>model_id</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p467617388576"><a name="p467617388576"></a><a name="p467617388576"></a>Number of model IDs.</p>
<p id="p367643811573"><a name="p367643811573"></a><a name="p367643811573"></a>If this option is not supported, <strong id="b446116124573"><a name="b446116124573"></a><a name="b446116124573"></a>0xFFFFFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p367673875710"><a name="p367673875710"></a><a name="p367673875710"></a>None</p>
</td>
</tr>
<tr id="row86761838195713"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p15676138115719"><a name="p15676138115719"></a><a name="p15676138115719"></a>topic_schedule_aicpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p116761938125713"><a name="p116761938125713"></a><a name="p116761938125713"></a>Number of topic schedule AICPUs.</p>
<p id="p196761738195714"><a name="p196761738195714"></a><a name="p196761738195714"></a>If this option is not supported, <strong id="b196211815145715"><a name="b196211815145715"></a><a name="b196211815145715"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1967683885717"><a name="p1967683885717"></a><a name="p1967683885717"></a>None</p>
</td>
</tr>
<tr id="row16761038115716"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1067693895712"><a name="p1067693895712"></a><a name="p1067693895712"></a>host_ctrl_cpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p206761338125711"><a name="p206761338125711"></a><a name="p206761338125711"></a>Number of host-side Ctrl CPUs.</p>
<p id="p8676113819574"><a name="p8676113819574"></a><a name="p8676113819574"></a>If this option is not supported, <strong id="b10205152818576"><a name="b10205152818576"></a><a name="b10205152818576"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p116761638175712"><a name="p116761638175712"></a><a name="p116761638175712"></a>None</p>
</td>
</tr>
<tr id="row767623812571"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1467612383573"><a name="p1467612383573"></a><a name="p1467612383573"></a>host_aicpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1567643895711"><a name="p1567643895711"></a><a name="p1567643895711"></a>Number of host-side AICPUs.</p>
<p id="p767616383579"><a name="p767616383579"></a><a name="p767616383579"></a>If this option is not supported, <strong id="b8123154411572"><a name="b8123154411572"></a><a name="b8123154411572"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p13676203835716"><a name="p13676203835716"></a><a name="p13676203835716"></a>None</p>
</td>
</tr>
<tr id="row186770380575"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p116768385577"><a name="p116768385577"></a><a name="p116768385577"></a>device_aicpu</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p36771383578"><a name="p36771383578"></a><a name="p36771383578"></a>Number of device-side AICPUs.</p>
<p id="p13677838155714"><a name="p13677838155714"></a><a name="p13677838155714"></a>If this option is not supported, <strong id="b1933685118573"><a name="b1933685118573"></a><a name="b1933685118573"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1365011248219"><a name="p1365011248219"></a><a name="p1365011248219"></a>All products</p>
</td>
</tr>
<tr id="row267711388572"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p116771038155716"><a name="p116771038155716"></a><a name="p116771038155716"></a>topic_ctrl_cpu_slot</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1467783885710"><a name="p1467783885710"></a><a name="p1467783885710"></a>Number of topic Ctrl CPU slots.</p>
<p id="p106771138145716"><a name="p106771138145716"></a><a name="p106771138145716"></a>If this option is not supported, <strong id="b14867194165819"><a name="b14867194165819"></a><a name="b14867194165819"></a>0xFFFF</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p867713818571"><a name="p867713818571"></a><a name="p867713818571"></a>None</p>
</td>
</tr>
<tr id="row1410212297020"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p13734133865411"><a name="p13734133865411"></a><a name="p13734133865411"></a>vdev_aicore_utilization</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p57341038105415"><a name="p57341038105415"></a><a name="p57341038105415"></a>AI Core usage of a vNPU.</p>
<p id="p19503122214413"><a name="p19503122214413"></a><a name="p19503122214413"></a>It is supported only when the subcommand word is <strong id="b733915419562"><a name="b733915419562"></a><a name="b733915419562"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY</strong>.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p10102152917016"><a name="p10102152917016"></a><a name="p10102152917016"></a>None</p>
</td>
</tr>
<tr id="row38211634504"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p165214413541"><a name="p165214413541"></a><a name="p165214413541"></a>vdev_memory_total</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p15526442547"><a name="p15526442547"></a><a name="p15526442547"></a>Total video memory of the vNPU.</p>
<p id="p3103382050"><a name="p3103382050"></a><a name="p3103382050"></a>It is supported only when the subcommand word is <strong id="b133332020105716"><a name="b133332020105716"></a><a name="b133332020105716"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY</strong>.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p1182114341907"><a name="p1182114341907"></a><a name="p1182114341907"></a>None</p>
</td>
</tr>
<tr id="row57178311019"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p429205195517"><a name="p429205195517"></a><a name="p429205195517"></a>vdev_memory_free</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p030185105513"><a name="p030185105513"></a><a name="p030185105513"></a>Remaining video memory of the vNPU.</p>
<p id="p1869314401517"><a name="p1869314401517"></a><a name="p1869314401517"></a>It is supported only when the subcommand word is <strong id="b8656143413576"><a name="b8656143413576"></a><a name="b8656143413576"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY</strong>.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p12718183111014"><a name="p12718183111014"></a><a name="p12718183111014"></a>None</p>
</td>
</tr>
<tr id="row156771238105720"><td class="cellrowborder" rowspan="6" valign="top" width="15%" headers="mcps1.2.6.1.1 "><p id="p567733875712"><a name="p567733875712"></a><a name="p567733875712"></a>Media resource information</p>
</td>
<td class="cellrowborder" rowspan="6" valign="top" width="30%" headers="mcps1.2.6.1.2 "><p id="p1667733875711"><a name="p1667733875711"></a><a name="p1667733875711"></a>struct dcmi_media_resource {</p>
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
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.2.6.1.3 "><p id="p176771038135719"><a name="p176771038135719"></a><a name="p176771038135719"></a>jpegd</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.6.1.4 "><p id="p156773389574"><a name="p156773389574"></a><a name="p156773389574"></a>Number of DVPP JPEGDs.</p>
<p id="p66771738125710"><a name="p66771738125710"></a><a name="p66771738125710"></a>If this option is not supported, <strong id="b16594146580"><a name="b16594146580"></a><a name="b16594146580"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" rowspan="4" valign="top" width="15%" headers="mcps1.2.6.1.5 "><p id="p1124182732116"><a name="p1124182732116"></a><a name="p1124182732116"></a>All products</p>
</td>
</tr>
<tr id="row46781738105717"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p4677203855713"><a name="p4677203855713"></a><a name="p4677203855713"></a>jpege</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1667883814577"><a name="p1667883814577"></a><a name="p1667883814577"></a>Number of DVPP JPEGEs.</p>
<p id="p18678438105719"><a name="p18678438105719"></a><a name="p18678438105719"></a>If this option is not supported, <strong id="b16198191717587"><a name="b16198191717587"></a><a name="b16198191717587"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row1867803865715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p16678113885710"><a name="p16678113885710"></a><a name="p16678113885710"></a>vpc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p10678103815712"><a name="p10678103815712"></a><a name="p10678103815712"></a>Number of DVPP VPCs.</p>
<p id="p3678138145714"><a name="p3678138145714"></a><a name="p3678138145714"></a>If this option is not supported, <strong id="b117642319588"><a name="b117642319588"></a><a name="b117642319588"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row867813895715"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p1967863818575"><a name="p1967863818575"></a><a name="p1967863818575"></a>vdec</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p1167803818577"><a name="p1167803818577"></a><a name="p1167803818577"></a>Number of DVPP VDECs.</p>
<p id="p1267893810577"><a name="p1267893810577"></a><a name="p1267893810577"></a>If this option is not supported, <strong id="b19122192945818"><a name="b19122192945818"></a><a name="b19122192945818"></a>-1.0</strong> is returned.</p>
</td>
</tr>
<tr id="row767833815573"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p17678123855719"><a name="p17678123855719"></a><a name="p17678123855719"></a>pngd</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p146785381571"><a name="p146785381571"></a><a name="p146785381571"></a>Number of DVPP PNGDs.</p>
<p id="p5678038165711"><a name="p5678038165711"></a><a name="p5678038165711"></a>If this option is not supported, <strong id="b32918312583"><a name="b32918312583"></a><a name="b32918312583"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p11678143812572"><a name="p11678143812572"></a><a name="p11678143812572"></a>None</p>
</td>
</tr>
<tr id="row16679103812577"><td class="cellrowborder" valign="top" headers="mcps1.2.6.1.1 "><p id="p166787387572"><a name="p166787387572"></a><a name="p166787387572"></a>venc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.2 "><p id="p76781738195714"><a name="p76781738195714"></a><a name="p76781738195714"></a>Number of DVPP VENCs.</p>
<p id="p14678103855713"><a name="p14678103855713"></a><a name="p14678103855713"></a>If this option is not supported, <strong id="b1195653515818"><a name="b1195653515818"></a><a name="b1195653515818"></a>-1.0</strong> is returned.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.6.1.3 "><p id="p11231730142116"><a name="p11231730142116"></a><a name="p11231730142116"></a>All products</p>
</td>
</tr>
</tbody>
</table>

**Table  3** Support in different deployment scenarios

<a name="table155158516230"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row9596171719419"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1059661716417"><a name="en-us_topic_0000002347924121_p1059661716417"></a><a name="en-us_topic_0000002347924121_p1059661716417"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p115964174411"><a name="en-us_topic_0000002347924121_p115964174411"></a><a name="en-us_topic_0000002347924121_p115964174411"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p3663614615"><a name="en-us_topic_0000002347924121_p3663614615"></a><a name="en-us_topic_0000002347924121_p3663614615"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1559620177411"><a name="en-us_topic_0000002347924121_p1559620177411"></a><a name="en-us_topic_0000002347924121_p1559620177411"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10613162423514"><a name="en-us_topic_0000002347924121_p10613162423514"></a><a name="en-us_topic_0000002347924121_p10613162423514"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row959614172418"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p15596151714414"><a name="en-us_topic_0000002347924121_p15596151714414"></a><a name="en-us_topic_0000002347924121_p15596151714414"></a><strong id="en-us_topic_0000002347924121_b95001068569"><a name="en-us_topic_0000002347924121_b95001068569"></a><a name="en-us_topic_0000002347924121_b95001068569"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p559611171344"><a name="en-us_topic_0000002347924121_p559611171344"></a><a name="en-us_topic_0000002347924121_p559611171344"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b12657127135611"><a name="en-us_topic_0000002347924121_b12657127135611"></a><a name="en-us_topic_0000002347924121_b12657127135611"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p866318118620"><a name="en-us_topic_0000002347924121_p866318118620"></a><a name="en-us_topic_0000002347924121_p866318118620"></a><strong id="en-us_topic_0000002347924121_b5599208195615"><a name="en-us_topic_0000002347924121_b5599208195615"></a><a name="en-us_topic_0000002347924121_b5599208195615"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p1959614171345"><a name="en-us_topic_0000002347924121_p1959614171345"></a><a name="en-us_topic_0000002347924121_p1959614171345"></a><strong id="en-us_topic_0000002347924121_b540214925617"><a name="en-us_topic_0000002347924121_b540214925617"></a><a name="en-us_topic_0000002347924121_b540214925617"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p82264478360"><a name="en-us_topic_0000002347924121_p82264478360"></a><a name="en-us_topic_0000002347924121_p82264478360"></a><strong id="en-us_topic_0000002347924121_b142941110185613"><a name="en-us_topic_0000002347924121_b142941110185613"></a><a name="en-us_topic_0000002347924121_b142941110185613"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row135967178414"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p2596121712410"><a name="en-us_topic_0000002347924121_p2596121712410"></a><a name="en-us_topic_0000002347924121_p2596121712410"></a><span id="en-us_topic_0000002347924121_ph259617171249"><a name="en-us_topic_0000002347924121_ph259617171249"></a><a name="en-us_topic_0000002347924121_ph259617171249"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p6596111711414"><a name="en-us_topic_0000002347924121_p6596111711414"></a><a name="en-us_topic_0000002347924121_p6596111711414"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p25961017947"><a name="en-us_topic_0000002347924121_p25961017947"></a><a name="en-us_topic_0000002347924121_p25961017947"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p17398249175310"><a name="en-us_topic_0000002347924121_p17398249175310"></a><a name="en-us_topic_0000002347924121_p17398249175310"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1529918247412"><a name="en-us_topic_0000002347924121_p1529918247412"></a><a name="en-us_topic_0000002347924121_p1529918247412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p1932714266187"><a name="en-us_topic_0000002347924121_p1932714266187"></a><a name="en-us_topic_0000002347924121_p1932714266187"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row155971917944"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p18597217849"><a name="en-us_topic_0000002347924121_p18597217849"></a><a name="en-us_topic_0000002347924121_p18597217849"></a><span id="en-us_topic_0000002347924121_ph3597217240"><a name="en-us_topic_0000002347924121_ph3597217240"></a><a name="en-us_topic_0000002347924121_ph3597217240"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section15381171918820"></a>**

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_domain_info domain_info = {0};
unsigned int size = sizeof(struct dcmi_domain_info);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_VDEV_MNG, DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE, &domain_info, &size);
if (ret != 0) {
printf("[failed] ret = %d\n", ret);
return -1;
}
...
```

## DCMI\_MAIN\_CMD\_PCIE<a id="EN-US_TOPIC_0000002348043793"></a>

**Prototype<a name="section224642513574"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row8442182617573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p134421126155713"><a name="p134421126155713"></a><a name="p134421126155713"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16442142613570"><a name="p16442142613570"></a><a name="p16442142613570"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p6442142615710"><a name="p6442142615710"></a><a name="p6442142615710"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
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
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p194431626195715"><a name="p194431626195715"></a><a name="p194431626195715"></a>For details, see <a href="#section142847254570">Restrictions</a>.</p>
</td>
</tr>
<tr id="row1144315264573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2443526125719"><a name="p2443526125719"></a><a name="p2443526125719"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12443326145716"><a name="p12443326145716"></a><a name="p12443326145716"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p4443526135714"><a name="p4443526135714"></a><a name="p4443526135714"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p3443102675716"><a name="p3443102675716"></a><a name="p3443102675716"></a>Length of the <strong id="b713982918418"><a name="b713982918418"></a><a name="b713982918418"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section142847254570"></a>**

This API is used only in the open Ctrl CPU form.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table131652519571"></a>
<table><thead align="left"><tr id="row144441226125711"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p64441826115711"><a name="p64441826115711"></a><a name="p64441826115711"></a><strong id="b3444192610574"><a name="b3444192610574"></a><a name="b3444192610574"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p64444261570"><a name="p64444261570"></a><a name="p64444261570"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1644432645711"><a name="p1644432645711"></a><a name="p1644432645711"></a><strong id="b341813184220"><a name="b341813184220"></a><a name="b341813184220"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row12444826175711"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17444112611573"><a name="p17444112611573"></a><a name="p17444112611573"></a>DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p124454268570"><a name="p124454268570"></a><a name="p124454268570"></a>struct dcmi_pcie_link_error_info {</p>
<p id="p94452262574"><a name="p94452262574"></a><a name="p94452262574"></a>unsigned int tx_err_cnt;</p>
<p id="p2044522615576"><a name="p2044522615576"></a><a name="p2044522615576"></a>unsigned int rx_err_cnt;</p>
<p id="p34456263573"><a name="p34456263573"></a><a name="p34456263573"></a>unsigned int lcrc_err_cnt;</p>
<p id="p34450264576"><a name="p34450264576"></a><a name="p34450264576"></a>unsigned int ecrc_err_cnt;</p>
<p id="p24455263576"><a name="p24455263576"></a><a name="p24455263576"></a>unsigned int retry_cnt;</p>
<p id="p15445152619575"><a name="p15445152619575"></a><a name="p15445152619575"></a>unsigned int rsv[32];</p>
<p id="p1445182613571"><a name="p1445182613571"></a><a name="p1445182613571"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7445142665715"><a name="p7445142665715"></a><a name="p7445142665715"></a>Obtains the information about PCIe link errors.</p>
<a name="ul19681694120"></a><a name="ul19681694120"></a><ul id="ul19681694120"><li><strong id="b1391012291903"><a name="b1391012291903"></a><a name="b1391012291903"></a>tx_err_cnt</strong>: number of PCIe transmission errors</li><li><strong id="b1084294314217"><a name="b1084294314217"></a><a name="b1084294314217"></a>rx_err_cnt</strong>: number of PCIe receiving errors</li><li><strong id="b105418024414"><a name="b105418024414"></a><a name="b105418024414"></a>lcrc_err_cnt</strong>: number of PCIe DLLP LCRC errors</li><li><strong id="b12617111913441"><a name="b12617111913441"></a><a name="b12617111913441"></a>ecrc_err_cnt</strong>: number of PCIe TLP ECRC errors</li><li><strong id="b46951729184413"><a name="b46951729184413"></a><a name="b46951729184413"></a>retry_cnt</strong>: number of PCIe link retransmissions</li><li><strong id="b19304124264417"><a name="b19304124264417"></a><a name="b19304124264417"></a>rsv</strong>: reserved field</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table6183194116432"></a>
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

**Example<a name="section8297125115718"></a>**

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_pcie_link_error_info pcie_link_error_info = {0};
unsigned int info_leng = sizeof(struct dcmi_pcie_link_error_info);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_PCIE, DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO, &pcie_link_error_info, &info_leng);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_SIO<a id="EN-US_TOPIC_0000002314204826"></a>

**Prototype<a name="section88293413398"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section166811419153914"></a>**

Queries the SIO status between dies.

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
<tbody><tr id="row17124954123815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p16124165419387"><a name="p16124165419387"></a><a name="p16124165419387"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p212418549389"><a name="p212418549389"></a><a name="p212418549389"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p101241854153819"><a name="p101241854153819"></a><a name="p101241854153819"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS = 0 // Obtain the inter-die SIO status.
}DCMI_SIO_SUB_CMD;</pre>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

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
<tbody><tr id="row712655418385"><td class="cellrowborder" valign="top" width="24.45%" headers="mcps1.2.5.1.1 "><p id="p7441102231412"><a name="p7441102231412"></a><a name="p7441102231412"></a>DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS</p>
</td>
<td class="cellrowborder" valign="top" width="32.99%" headers="mcps1.2.5.1.2 "><p id="p1664914023114"><a name="p1664914023114"></a><a name="p1664914023114"></a>struct dcmi_sio_crc_err_statistics_info {</p>
<p id="p195228943118"><a name="p195228943118"></a><a name="p195228943118"></a>unsigned short tx_error_count;</p>
<p id="p1959618125316"><a name="p1959618125316"></a><a name="p1959618125316"></a>unsigned short rx_error_count;</p>
<p id="p966122118317"><a name="p966122118317"></a><a name="p966122118317"></a>unsigned char reserved[8];</p>
<p id="p128675414305"><a name="p128675414305"></a><a name="p128675414305"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20.01%" headers="mcps1.2.5.1.3 "><p id="p1712718547382"><a name="p1712718547382"></a><a name="p1712718547382"></a>sizeof(struct dcmi_sio_crc_err_statistics_info)</p>
</td>
<td class="cellrowborder" valign="top" width="22.55%" headers="mcps1.2.5.1.4 "><a name="ul89281736384"></a><a name="ul89281736384"></a><ul id="ul89281736384"><li><strong id="b168085424016"><a name="b168085424016"></a><a name="b168085424016"></a>tx_error_count</strong>: number of transmitted SIO errors</li><li><strong id="b1948310434504"><a name="b1948310434504"></a><a name="b1948310434504"></a>rx_error_count</strong>: number of received SIO errors</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table159431741121314"></a>
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

**Example<a name="section083811564420"></a>**

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_sio_crc_err_statistics_info sio_info = {0};
unsigned int sio_info_size = sizeof(struct dcmi_sio_crc_err_statistics_info);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_SIO, DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS, &sio_info, &sio_info_size);
if (ret != 0) {
// TODO
return ret;
} else {
// TODO
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_EX\_COMPUTING<a id="EN-US_TOPIC_0000002544184079"></a>

**Prototype<a name="section251144503117"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

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
<tbody><tr id="row163617450316"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p126362454318"><a name="p126362454318"></a><a name="p126362454318"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p6636174518315"><a name="p6636174518315"></a><a name="p6636174518315"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p4636194553115"><a name="p4636194553115"></a><a name="p4636194553115"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p106372452314"><a name="p106372452314"></a><a name="p106372452314"></a>For details, see <a href="#section168551249144914">Restrictions</a>.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section168551249144914"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table353514454317"></a>
<table><thead align="left"><tr id="row263834543117"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p166382458312"><a name="p166382458312"></a><a name="p166382458312"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.2"><p id="p16638645113120"><a name="p16638645113120"></a><a name="p16638645113120"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p263819453310"><a name="p263819453310"></a><a name="p263819453310"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.5.1.4"><p id="p1638145183117"><a name="p1638145183117"></a><a name="p1638145183117"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1263884503118"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p763884573120"><a name="p763884573120"></a><a name="p763884573120"></a>DCMI_EX_COMPUTING</p>
<p id="p3638184563117"><a name="p3638184563117"></a><a name="p3638184563117"></a>_SUB_CMD_TOKEN</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.2 "><p id="p1963817451315"><a name="p1963817451315"></a><a name="p1963817451315"></a>struct dsmi_computing_token_stru {</p>
<p id="p1863844515316"><a name="p1863844515316"></a><a name="p1863844515316"></a>float value;</p>
<p id="p126384453317"><a name="p126384453317"></a><a name="p126384453317"></a>u8 type;</p>
<p id="p1563804518310"><a name="p1563804518310"></a><a name="p1563804518310"></a>u8 reserve_c;</p>
<p id="p763874510313"><a name="p763874510313"></a><a name="p763874510313"></a>u16 reserve_s;</p>
<p id="p56381459316"><a name="p56381459316"></a><a name="p56381459316"></a>}COMPUTING_TOKEN_STRU;</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p663854523113"><a name="p663854523113"></a><a name="p663854523113"></a>sizeof(dsmi_computing_token_stru)</p>
</td>
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><p id="p1638144514312"><a name="p1638144514312"></a><a name="p1638144514312"></a>Obtains the computing power token value. The value range is [0, 65535].</p>
<p id="p6638164513117"><a name="p6638164513117"></a><a name="p6638164513117"></a>a. <strong id="b17265125861619"><a name="b17265125861619"></a><a name="b17265125861619"></a>value</strong>: computing power</p>
<p id="p863819458316"><a name="p863819458316"></a><a name="p863819458316"></a>b. <strong id="b178935616179"><a name="b178935616179"></a><a name="b178935616179"></a>type</strong>: type value after the license BOM number is converted</p>
<p id="p20638345123117"><a name="p20638345123117"></a><a name="p20638345123117"></a>c. <strong id="b74931329111716"><a name="b74931329111716"></a><a name="b74931329111716"></a>reserve_c</strong>: reserved currently</p>
<p id="p1663810451310"><a name="p1663810451310"></a><a name="p1663810451310"></a>d. <strong id="b5341436111711"><a name="b5341436111711"></a><a name="b5341436111711"></a>reserve_s</strong>: reserved currently</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table159431741121314"></a>
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

**Example<a name="section172981043978"></a>**

```c
...
int ret = 0;
int dev_id = 0;
struct dsmi_computing_token_stru computing_token = {0};
unsigned int buf_size = sizeof(struct dsmi_computing_token_stru);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_EX_COMPUTING, DCMI_EX_COMPUTING_SUB_CMD_TOKEN, &computing_token, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_EX\_CERT<a id="EN-US_TOPIC_0000002509588792"></a>

**Prototype<a name="section5922172553416"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**Description<a name="section367034213346"></a>**

Obtains TLS certificate information.

**Parameter Description<a name="section19821164963414"></a>**

<a name="table6879815113410"></a>
<table><thead align="left"><tr id="row911191616342"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="p81111693412"><a name="p81111693412"></a><a name="p81111693412"></a><strong id="b17950154710135"><a name="b17950154710135"></a><a name="b17950154710135"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.2"><p id="p811111619348"><a name="p811111619348"></a><a name="p811111619348"></a><strong id="b15365114911314"><a name="b15365114911314"></a><a name="b15365114911314"></a>Input/Output</strong></p>
</th>
<th class="cellrowborder" valign="top" width="19.189999999999998%" id="mcps1.1.5.1.3"><p id="p1911516173411"><a name="p1911516173411"></a><a name="p1911516173411"></a><strong id="b1130114509136"><a name="b1130114509136"></a><a name="b1130114509136"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="62.629999999999995%" id="mcps1.1.5.1.4"><p id="p15113163349"><a name="p15113163349"></a><a name="p15113163349"></a><strong id="b3306751131316"><a name="b3306751131316"></a><a name="b3306751131316"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row9111316183415"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p13111716133419"><a name="p13111716133419"></a><a name="p13111716133419"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p81117168341"><a name="p81117168341"></a><a name="p81117168341"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p151171615344"><a name="p151171615344"></a><a name="p151171615344"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="row15128165343"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p81241613416"><a name="p81241613416"></a><a name="p81241613416"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p19121016153415"><a name="p19121016153415"></a><a name="p19121016153415"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p212616113417"><a name="p212616113417"></a><a name="p212616113417"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1012101643419"><a name="p1012101643419"></a><a name="p1012101643419"></a>DCMI_MAIN_CMD_EX_CERT</p>
</td>
</tr>
<tr id="row1121016153416"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p912111603417"><a name="p912111603417"></a><a name="p912111603417"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p1812151618349"><a name="p1812151618349"></a><a name="p1812151618349"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p10121016133413"><a name="p10121016133413"></a><a name="p10121016133413"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1909144281914"><a name="p1909144281914"></a><a name="p1909144281914"></a>typedef enum {</p>
<p id="p16909134251918"><a name="p16909134251918"></a><a name="p16909134251918"></a>DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY = 0, // Initialization of the TLS certificate (used to obtain the CSR)</p>
<p id="p189091942131912"><a name="p189091942131912"></a><a name="p189091942131912"></a>DCMI_CERT_SUB_CMD_INIT_RESERVE, // Reserved field for initialization</p>
<p id="p99091942161915"><a name="p99091942161915"></a><a name="p99091942161915"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO, // Acquisition of the TLS certificate information</p>
<p id="p89094428194"><a name="p89094428194"></a><a name="p89094428194"></a>DCMI_CERT_SUB_CMD_MAX, // Upper limit flag of enumerated values</p>
<p id="p790919427194"><a name="p790919427194"></a><a name="p790919427194"></a>} DCMI_EX_CERT_SUB_CMD;</p>
<p id="p2797182871618"><a name="p2797182871618"></a><a name="p2797182871618"></a>Currently, only <strong id="b20782114655020"><a name="b20782114655020"></a><a name="b20782114655020"></a>DCMI_CERT_SUB_CMD_INIT_RESERVE</strong> and <strong id="b18782146125017"><a name="b18782146125017"></a><a name="b18782146125017"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO</strong> are supported.</p>
</td>
</tr>
<tr id="row612121619349"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p5129164343"><a name="p5129164343"></a><a name="p5129164343"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p312616163411"><a name="p312616163411"></a><a name="p312616163411"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p151219163343"><a name="p151219163343"></a><a name="p151219163343"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1512516103412"><a name="p1512516103412"></a><a name="p1512516103412"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row1912101611341"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p112151617346"><a name="p112151617346"></a><a name="p112151617346"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p11121616193413"><a name="p11121616193413"></a><a name="p11121616193413"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p512151616341"><a name="p512151616341"></a><a name="p512151616341"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p191317165344"><a name="p191317165344"></a><a name="p191317165344"></a>Length of the <strong id="b125031745101518"><a name="b125031745101518"></a><a name="b125031745101518"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section1422146133417"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table1892515103416"></a>
<table><thead align="left"><tr id="row1713716153413"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p81313161345"><a name="p81313161345"></a><a name="p81313161345"></a><strong id="b913916193413"><a name="b913916193413"></a><a name="b913916193413"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.2.5.1.2"><p id="p813201610342"><a name="p813201610342"></a><a name="p813201610342"></a><strong id="b10529195011150"><a name="b10529195011150"></a><a name="b10529195011150"></a>buf Data Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p151351673417"><a name="p151351673417"></a><a name="p151351673417"></a><strong id="b1986795281515"><a name="b1986795281515"></a><a name="b1986795281515"></a>Size</strong></p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.2.5.1.4"><p id="p7131516203415"><a name="p7131516203415"></a><a name="p7131516203415"></a><strong id="b1391565313156"><a name="b1391565313156"></a><a name="b1391565313156"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1013191663416"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p913121617349"><a name="p913121617349"></a><a name="p913121617349"></a>DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.2 "><p id="p121331617349"><a name="p121331617349"></a><a name="p121331617349"></a>#define CERT_NAME_MAX_LEN    16</p>
<p id="p1413816103411"><a name="p1413816103411"></a><a name="p1413816103411"></a>#define CERT_COMMON_NAME_LEN 64</p>
<p id="p131311165341"><a name="p131311165341"></a><a name="p131311165341"></a>struct dcmi_csr_info {</p>
<p id="p1713161613417"><a name="p1713161613417"></a><a name="p1713161613417"></a>char country_name[CERT_NAME_MAX_LEN];</p>
<p id="p614216183418"><a name="p614216183418"></a><a name="p614216183418"></a>char province_name[CERT_NAME_MAX_LEN];</p>
<p id="p14147168341"><a name="p14147168341"></a><a name="p14147168341"></a>char city_name[CERT_NAME_MAX_LEN];</p>
<p id="p11141516183413"><a name="p11141516183413"></a><a name="p11141516183413"></a>char organization_name[CERT_NAME_MAX_LEN];</p>
<p id="p21481613344"><a name="p21481613344"></a><a name="p21481613344"></a>char department_name[CERT_NAME_MAX_LEN];</p>
<p id="p18141116113418"><a name="p18141116113418"></a><a name="p18141116113418"></a>char reserve_name[CERT_COMMON_NAME_LEN];</p>
<p id="p13142161345"><a name="p13142161345"></a><a name="p13142161345"></a>int reserve;</p>
<p id="p81414169347"><a name="p81414169347"></a><a name="p81414169347"></a>int csr_len;</p>
<p id="p161411616349"><a name="p161411616349"></a><a name="p161411616349"></a>char csr_data[NPU_CERT_MAX_SIZE];</p>
<p id="p151415161342"><a name="p151415161342"></a><a name="p151415161342"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p2141116103414"><a name="p2141116103414"></a><a name="p2141116103414"></a>Returns the length of the public key or certificate information.</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.4 "><a name="ul57333280138"></a><a name="ul57333280138"></a><ul id="ul57333280138"><li><strong id="b1563526151610"><a name="b1563526151610"></a><a name="b1563526151610"></a>country_name</strong>: country name</li><li><strong id="b13581163121617"><a name="b13581163121617"></a><a name="b13581163121617"></a>province_name</strong>: state or province name</li><li><strong id="b425424131619"><a name="b425424131619"></a><a name="b425424131619"></a>city_name</strong>: city name</li><li><strong id="b141687439163"><a name="b141687439163"></a><a name="b141687439163"></a>organization_name</strong>: organization name</li><li><strong id="b12918467161"><a name="b12918467161"></a><a name="b12918467161"></a>department_name</strong>: name of a department in an organization</li><li><strong id="b1818314547168"><a name="b1818314547168"></a><a name="b1818314547168"></a>reserve_name</strong>: reserved name</li><li><strong id="b1428435615161"><a name="b1428435615161"></a><a name="b1428435615161"></a>reserve</strong>: reserved</li><li><strong id="b8305185917169"><a name="b8305185917169"></a><a name="b8305185917169"></a>csr_len</strong>: length of the CSR content</li><li><strong id="b619311710175"><a name="b619311710175"></a><a name="b619311710175"></a>csr_data</strong>: CSR content</li></ul>
</td>
</tr>
<tr id="row19141016183410"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.1 "><p id="p514131615349"><a name="p514131615349"></a><a name="p514131615349"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.2 "><p id="p141418165347"><a name="p141418165347"></a><a name="p141418165347"></a>#define CERT_COMMON_NAME_LEN 64</p>
<p id="p91420169348"><a name="p91420169348"></a><a name="p91420169348"></a>#define CERT_NAME_MAX_LEN    16</p>
<p id="p714216103412"><a name="p714216103412"></a><a name="p714216103412"></a>#define TIME_LEN 32</p>
<p id="p21415163341"><a name="p21415163341"></a><a name="p21415163341"></a>struct dcmi_cert_info  {</p>
<p id="p171431623415"><a name="p171431623415"></a><a name="p171431623415"></a>unsigned int alarm_stat;</p>
<p id="p1146167340"><a name="p1146167340"></a><a name="p1146167340"></a>unsigned int reserve;</p>
<p id="p51421663412"><a name="p51421663412"></a><a name="p51421663412"></a>char start_time[TIME_LEN];</p>
<p id="p114101613414"><a name="p114101613414"></a><a name="p114101613414"></a>char end_time[TIME_LEN];</p>
<p id="p10149162343"><a name="p10149162343"></a><a name="p10149162343"></a>char country_name[CERT_NAME_MAX_LEN];</p>
<p id="p8142169344"><a name="p8142169344"></a><a name="p8142169344"></a>char province_name[CERT_NAME_MAX_LEN];</p>
<p id="p3144167347"><a name="p3144167347"></a><a name="p3144167347"></a>char city_name[CERT_NAME_MAX_LEN];</p>
<p id="p201451653418"><a name="p201451653418"></a><a name="p201451653418"></a>char organization_name[CERT_NAME_MAX_LEN];</p>
<p id="p1014191615345"><a name="p1014191615345"></a><a name="p1014191615345"></a>char department_name[CERT_NAME_MAX_LEN];</p>
<p id="p91471643415"><a name="p91471643415"></a><a name="p91471643415"></a>char reserve_name[CERT_COMMON_NAME_LEN];</p>
<p id="p4141161342"><a name="p4141161342"></a><a name="p4141161342"></a>char common_name[CERT_COMMON_NAME_LEN];</p>
<p id="p1814916143411"><a name="p1814916143411"></a><a name="p1814916143411"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p614141693419"><a name="p614141693419"></a><a name="p614141693419"></a>Returns the length of the public key or certificate information.</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.4 "><a name="ul11930122181818"></a><a name="ul11930122181818"></a><ul id="ul11930122181818"><li><strong id="b14528112181714"><a name="b14528112181714"></a><a name="b14528112181714"></a>alarm_stat</strong>: certificate alarm status. <strong id="b152982101718"><a name="b152982101718"></a><a name="b152982101718"></a>0</strong>: normal; <strong id="b55292021101715"><a name="b55292021101715"></a><a name="b55292021101715"></a>1</strong>: about to expire; <strong id="b55301321131719"><a name="b55301321131719"></a><a name="b55301321131719"></a>2</strong>: expired/invalid ("about to expire" is displayed only when the certificate is read.)</li><li><strong id="b13253955121716"><a name="b13253955121716"></a><a name="b13253955121716"></a>reserve</strong>: reserved</li><li><strong id="b20866156141712"><a name="b20866156141712"></a><a name="b20866156141712"></a>start_time</strong>: time when the certificate takes effect</li><li><strong id="b155511181819"><a name="b155511181819"></a><a name="b155511181819"></a>end_time</strong>: time when the certificate expires</li><li><strong id="b4409519183"><a name="b4409519183"></a><a name="b4409519183"></a>country_name</strong>: country name</li><li><strong id="b36238615182"><a name="b36238615182"></a><a name="b36238615182"></a>province_name</strong>: state or province name</li><li><strong id="b17718971186"><a name="b17718971186"></a><a name="b17718971186"></a>city_name</strong>: city name</li><li><strong id="b629099111816"><a name="b629099111816"></a><a name="b629099111816"></a>organization_name</strong>: organization name</li><li><strong id="b155052112184"><a name="b155052112184"></a><a name="b155052112184"></a>department_name</strong>: name of a department in an organization</li><li><strong id="b2096901317188"><a name="b2096901317188"></a><a name="b2096901317188"></a>reserve_name</strong>: reserved name</li><li><strong id="b1559181810186"><a name="b1559181810186"></a><a name="b1559181810186"></a>common_name</strong>: common name of the certificate. The DIE-ID of the device is used here.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table1891871242416"></a>
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

**Example<a name="section5271151515373"></a>**

```c
...
int ret;
int dev_id = 0;
struct dcmi_cert_info cert_info = { 0 };
enum dcmi_main_cmd main_cmd = DCMI_MAIN_CMD_EX_CERT;
unsigned int sub_cmd = DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY;
unsigned int size = sizeof(struct dcmi_csr_info);
ret = dcmiv2_get_device_info(dev_id, main_cmd, sub_cmd, (const void *)&cert_info, size);
if (ret) {
   // TODO
}
// TODO
...
```
