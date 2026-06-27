# dcmiv2\_get\_device\_info<a name="ZH-CN_TOPIC_0000002314045082"></a>

**函数原型<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_toc533412077"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_toc533412078"></a>**

获取device信息的通用接口，获取各模块中的状态信息。

**参数说明<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_toc533412079"></a>**

<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p10021890"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p10021890"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p6466753"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p6466753"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.96%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p54045009"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p54045009"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15569626"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15569626"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7711145152918"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7711145152918"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p671116522914"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p671116522914"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1771116572910"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1771116572910"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p5522164215178"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p5522164215178"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p5522164215178"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8522242101715"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8522242101715"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8522242101715"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p17522114220174"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p17522114220174"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p17522114220174"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p167001165556"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p167001165556"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p167001165556"></a>指定查询项对应主命令字。模块cmd信息，用于获取对应模块的信息。</p>
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
<p id="p9932195894319"><a name="p9932195894319"></a><a name="p9932195894319"></a>仅支持如下模块主命令字：</p>
<p id="p1028842114915"><a name="p1028842114915"></a><a name="p1028842114915"></a>DCMI_MAIN_CMD_DVPP //dvpp算子模块主命令字</p>
<p id="p889911226920"><a name="p889911226920"></a><a name="p889911226920"></a>DCMI_MAIN_CMD_LP //lp低功耗模块主命令字</p>
<p id="p630816245918"><a name="p630816245918"></a><a name="p630816245918"></a>DCMI_MAIN_CMD_TS //ts任务调度模块主命令字</p>
<p id="p77158266913"><a name="p77158266913"></a><a name="p77158266913"></a>DCMI_MAIN_CMD_QOS //QoS模块主命令字</p>
<p id="p121340251314"><a name="p121340251314"></a><a name="p121340251314"></a>DCMI_MAIN_CMD_VDEV_MNG //<span id="ph947682813612"><a name="ph947682813612"></a><a name="ph947682813612"></a>昇腾虚拟化实例（AVI）</span>模块主命令字</p>
<p id="p47917422120"><a name="p47917422120"></a><a name="p47917422120"></a>DCMI_MAIN_CMD_PCIE //获取PCIe相关信息</p>
<p id="p15875609615"><a name="p15875609615"></a><a name="p15875609615"></a>DCMI_MAIN_CMD_SIO //查询die间SIO状态</p>
<p id="p1334062061315"><a name="p1334062061315"></a><a name="p1334062061315"></a>DCMI_MAIN_CMD_EX_COMPUTING //算力扩展模块主命令字</p>
<p id="p91844347321"><a name="p91844347321"></a><a name="p91844347321"></a>DCMI_MAIN_CMD_EX_CERT //证书管理模块主命令字</p>
<p id="p1854611116108"><a name="p1854611116108"></a><a name="p1854611116108"></a>DCMI_MAIN_CMD_DEVICE_SHARE //容器共享主命令字</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row118352016305"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p19161539205"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p19161539205"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p19161539205"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1816115315209"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1816115315209"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1816115315209"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1216853142018"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1216853142018"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1216853142018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p75475304476"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p75475304476"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p75475304476"></a>详细参见子章节中的功能说明。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row148973243016"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8864185062018"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8864185062018"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p8864185062018"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p886417500202"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p886417500202"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p886417500202"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1386445092020"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1386445092020"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1386445092020"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15864145012200"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15864145012200"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p15864145012200"></a>用于输入指定获取信息，并接收设备信息的返回数据。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_row20221172313016"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7749184816202"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7749184816202"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p7749184816202"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p0749104811207"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p0749104811207"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p0749104811207"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1374944862018"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1374944862018"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p1374944862018"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p074915488209"><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p074915488209"></a><a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_p074915488209"></a>buf数组的输入/输出长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_toc533412082"></a>**

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="zh-cn_topic_0000001206467202_zh-cn_topic_0000001178373156_zh-cn_topic_0000001101204718_toc533412083"></a>**

```c
…
int ret = 0;
int dev_id = 0;
int buf = 0;
unsigned int size = sizeof(int);
unsigned int sub_cmd = 0;
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_DVPP, sub_cmd, (void *)&buf, &size);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

- **[DCMI\_MAIN\_CMD\_DVPP](#ZH-CN_TOPIC_0000002348043853)**  

- **[DCMI\_MAIN\_CMD\_LP](#ZH-CN_TOPIC_0000002347924029)**  

- **[DCMI\_MAIN\_CMD\_TS](#ZH-CN_TOPIC_0000002348043797)**  

- **[DCMI\_MAIN\_CMD\_QOS](#ZH-CN_TOPIC_0000002347924125)**  

- **[DCMI\_MAIN\_CMD\_PCIE](#ZH-CN_TOPIC_0000002348043793)**  

- **[DCMI\_MAIN\_CMD\_SIO](#ZH-CN_TOPIC_0000002314204826)**  

- **[DCMI\_MAIN\_CMD\_EX\_COMPUTING](#ZH-CN_TOPIC_0000002544184079)**  

- **[DCMI\_MAIN\_CMD\_EX\_CERT](#ZH-CN_TOPIC_0000002509588792)**  

## DCMI\_MAIN\_CMD\_DVPP<a id="ZH-CN_TOPIC_0000002348043853"></a>

**函数原型<a name="section1045115919305"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section184521595304"></a>**

获取dvpp相关状态，配置信息。

**参数说明<a name="section104533963015"></a>**

<a name="table104768953018"></a>
<table><thead align="left"><tr id="row19544594301"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p115440913011"><a name="p115440913011"></a><a name="p115440913011"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p754417916309"><a name="p754417916309"></a><a name="p754417916309"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="23.232323232323232%" id="mcps1.1.5.1.3"><p id="p135449903012"><a name="p135449903012"></a><a name="p135449903012"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.44444444444445%" id="mcps1.1.5.1.4"><p id="p254412913309"><a name="p254412913309"></a><a name="p254412913309"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1544592304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p195445917304"><a name="p195445917304"></a><a name="p195445917304"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185446910306"><a name="p185446910306"></a><a name="p185446910306"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p175441294306"><a name="p175441294306"></a><a name="p175441294306"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row35441953014"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1254413913016"><a name="p1254413913016"></a><a name="p1254413913016"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p154509173018"><a name="p154509173018"></a><a name="p154509173018"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p135451198309"><a name="p135451198309"></a><a name="p135451198309"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p165456953016"><a name="p165456953016"></a><a name="p165456953016"></a>DCMI_MAIN_CMD_DVPP</p>
</td>
</tr>
<tr id="row754518963011"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p85451396307"><a name="p85451396307"></a><a name="p85451396307"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1654518910302"><a name="p1654518910302"></a><a name="p1654518910302"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p354519916301"><a name="p354519916301"></a><a name="p354519916301"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p135451197302"><a name="p135451197302"></a><a name="p135451197302"></a>sub_cmd获取对应模块下子属性信息。</p>
<p id="p1154589163019"><a name="p1154589163019"></a><a name="p1154589163019"></a>/* DCMI sub command for DVPP module */</p>
<p id="p145452913308"><a name="p145452913308"></a><a name="p145452913308"></a>#define DCMI_SUB_CMD_DVPP_STATUS 0 //dvpp状态，buf为0表示状态正常，非0表示状态异常</p>
<p id="p17545699303"><a name="p17545699303"></a><a name="p17545699303"></a>#define DCMI_SUB_CMD_DVPP_VDEC_RATE 1 //vdec利用率，正常值范围0-100</p>
<p id="p0545119193019"><a name="p0545119193019"></a><a name="p0545119193019"></a>#define DCMI_SUB_CMD_DVPP_VPC_RATE 2 //vpc利用率，正常值范围0-100</p>
<p id="p13545397302"><a name="p13545397302"></a><a name="p13545397302"></a>#define DCMI_SUB_CMD_DVPP_VENC_RATE 3 //venc利用率，正常值范围0-100</p>
<p id="p154509103011"><a name="p154509103011"></a><a name="p154509103011"></a>#define DCMI_SUB_CMD_DVPP_JPEGE_RATE 4 //jpege利用率，正常值范围0-100</p>
<p id="p1054579163010"><a name="p1054579163010"></a><a name="p1054579163010"></a>#define DCMI_SUB_CMD_DVPP_JPEGD_RATE 5 //jpegd利用率，正常值范围0-100</p>
<p id="p6784427174618"><a name="p6784427174618"></a><a name="p6784427174618"></a>目前不支持DCMI_SUB_CMD_DVPP_VDEC_RATE和DCMI_SUB_CMD_DVPP_VENC_RATE命令的查询。</p>
</td>
</tr>
<tr id="row1954515903016"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p155455915303"><a name="p155455915303"></a><a name="p155455915303"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p554510903013"><a name="p554510903013"></a><a name="p554510903013"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p19545129143015"><a name="p19545129143015"></a><a name="p19545129143015"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p185454953015"><a name="p185454953015"></a><a name="p185454953015"></a>详见本节约束说明。</p>
</td>
</tr>
<tr id="row2054549113013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p25451983018"><a name="p25451983018"></a><a name="p25451983018"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p12545169113011"><a name="p12545169113011"></a><a name="p12545169113011"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="23.232323232323232%" headers="mcps1.1.5.1.3 "><p id="p1754515943013"><a name="p1754515943013"></a><a name="p1754515943013"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="44.44444444444445%" headers="mcps1.1.5.1.4 "><p id="p2054559153019"><a name="p2054559153019"></a><a name="p2054559153019"></a>buf数组的长度/返回结果实际数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section20247271550"></a>**

获取dvpp设备时sub\_cmd，buf和size之间必须要满足以下关系，如果不满足会导致接口调用失败。

**表 1**  sub\_cmd对应的buf格式

<a name="table34881973017"></a>
<table><thead align="left"><tr id="row654609173016"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p654609173010"><a name="p654609173010"></a><a name="p654609173010"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.2"><p id="p1254617983019"><a name="p1254617983019"></a><a name="p1254617983019"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.3"><p id="p2054620963017"><a name="p2054620963017"></a><a name="p2054620963017"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row1954613919308"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p45462912305"><a name="p45462912305"></a><a name="p45462912305"></a>DCMI_SUB_CMD_DVPP_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.2 "><p id="p1554659163015"><a name="p1554659163015"></a><a name="p1554659163015"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.3 "><p id="p354616913304"><a name="p354616913304"></a><a name="p354616913304"></a>长度为：sizeof(unsigned int)</p>
</td>
</tr>
<tr id="row2054611914303"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p954615953017"><a name="p954615953017"></a><a name="p954615953017"></a>DCMI_SUB_CMD_DVPP_VPC_RATE</p>
<p id="p15462094304"><a name="p15462094304"></a><a name="p15462094304"></a>DCMI_SUB_CMD_DVPP_JPEGE_RATE</p>
<p id="p85468914304"><a name="p85468914304"></a><a name="p85468914304"></a>DCMI_SUB_CMD_DVPP_JPEGD_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.2 "><p id="p135461398309"><a name="p135461398309"></a><a name="p135461398309"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.3 "><p id="p1254699103018"><a name="p1254699103018"></a><a name="p1254699103018"></a>长度为：sizeof(unsigned int)</p>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table78605316125"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section2133155511568"></a>**

```c
…
int ret = 0;
int dev_id = 0;
unsigned int ratio = 0;
unsigned int sub_cmd = 0;
unsigned int ratio_size = sizeof(unsigned int);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_DVPP, sub_cmd, (void *)&ratio, &ratio_size);
if (ret != 0) {
    // todo
    return ret;
} else {
    // todo
    return ret;
}
…
```

## DCMI\_MAIN\_CMD\_LP<a id="ZH-CN_TOPIC_0000002347924029"></a>

**函数原型<a name="section158495435301"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section7850154317304"></a>**

获取系统中AICORE、HYBIRD、CPU和DDR的电压和电流的寄存器值等LP相关信息。

**参数说明<a name="section28501043183017"></a>**

<a name="table15882143133020"></a>
<table><thead align="left"><tr id="row11974164343015"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p797519436303"><a name="p797519436303"></a><a name="p797519436303"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p697512439305"><a name="p697512439305"></a><a name="p697512439305"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p19975543163019"><a name="p19975543163019"></a><a name="p19975543163019"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p15975184353016"><a name="p15975184353016"></a><a name="p15975184353016"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row109751843163011"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p39751943113018"><a name="p39751943113018"></a><a name="p39751943113018"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p2975124363011"><a name="p2975124363011"></a><a name="p2975124363011"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p997554315307"><a name="p997554315307"></a><a name="p997554315307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row12975443183013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1097534333012"><a name="p1097534333012"></a><a name="p1097534333012"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19975124303012"><a name="p19975124303012"></a><a name="p19975124303012"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p2975184311304"><a name="p2975184311304"></a><a name="p2975184311304"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p9975194310307"><a name="p9975194310307"></a><a name="p9975194310307"></a>DCMI_MAIN_CMD_LP</p>
</td>
</tr>
<tr id="row2975194333013"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1497534343010"><a name="p1497534343010"></a><a name="p1497534343010"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p597594314306"><a name="p597594314306"></a><a name="p597594314306"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6975743153011"><a name="p6975743153011"></a><a name="p6975743153011"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18975343113017"><a name="p18975343113017"></a><a name="p18975343113017"></a>/* DCMI sub command for Low power */</p>
<pre class="codeblock" id="codeblock971395520334"><a name="codeblock971395520334"></a><a name="codeblock971395520334"></a>typedef enum {
DCMI_LP_SUB_CMD_AICORE_VOLTAGE_CURRENT = 0, //获取AICORE电压电流的寄存器值
DCMI_LP_SUB_CMD_HYBIRD_VOLTAGE_CURRENT, //获取HYBIRD电压电流的寄存器值
DCMI_LP_SUB_CMD_TAISHAN_VOLTAGE_CURRENT, //获取CPU电压电流的寄存器值
DCMI_LP_SUB_CMD_DDR_VOLTAGE_CURRENT, //获取DDR电压电流的寄存器值
DCMI_LP_SUB_CMD_ACG, //获取ACG调频计数值
DCMI_LP_SUB_CMD_STATUS, //获取低功耗总状态
DCMI_LP_SUB_CMD_TOPS_DETAILS, //获取所有工作档位
DCMI_LP_SUB_CMD_SET_WORK_TOPS, //设置工作档位
DCMI_LP_SUB_CMD_GET_WORK_TOPS, //获取当前工作档位
DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE, //获取当前降频原因
DCMI_LP_SUB_CMD_GET_POWER_INFO, //获取功耗信息
DCMI_LP_SUB_CMD_SET_IDLE_SWITCH, //设置IDLE模式开关
DCMI_LP_SUB_CMD_MAX, //枚举值上限标记
} DCMI_LP_SUB_CMD;</pre>
<p id="p0976643203017"><a name="p0976643203017"></a><a name="p0976643203017"></a>仅支持DCMI_LP_SUB_CMD_STATUS、DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE、DCMI_LP_SUB_CMD_GET_POWER_INFO命令。</p>
</td>
</tr>
<tr id="row119761843173017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p0976184343012"><a name="p0976184343012"></a><a name="p0976184343012"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p397614363010"><a name="p397614363010"></a><a name="p397614363010"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p29762043173012"><a name="p29762043173012"></a><a name="p29762043173012"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p179761943143013"><a name="p179761943143013"></a><a name="p179761943143013"></a>详见本节约束说明。</p>
</td>
</tr>
<tr id="row6976543103019"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p119765433306"><a name="p119765433306"></a><a name="p119765433306"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p79761543173017"><a name="p79761543173017"></a><a name="p79761543173017"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1976204317307"><a name="p1976204317307"></a><a name="p1976204317307"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p2976943123017"><a name="p2976943123017"></a><a name="p2976943123017"></a>buf数组的长度/返回结果实际数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section216210381817"></a>**

- 本接口获取的电压和电流信息为寄存器数值。
- AI Core降频原因每100ms更新一次，不能查询历史降频原因。

**表 1**  sub\_cmd对应的buf格式

<a name="table9893154314306"></a>
<table><thead align="left"><tr id="row1097794373014"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p597724343018"><a name="p597724343018"></a><a name="p597724343018"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p15977743113017"><a name="p15977743113017"></a><a name="p15977743113017"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1977104363011"><a name="p1977104363011"></a><a name="p1977104363011"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1097718435302"><a name="p1097718435302"></a><a name="p1097718435302"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row834951184217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12977743173013"><a name="p12977743173013"></a><a name="p12977743173013"></a>DCMI_LP_SUB_CMD_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p597754320305"><a name="p597754320305"></a><a name="p597754320305"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p097724315305"><a name="p097724315305"></a><a name="p097724315305"></a>sizeof(unsigned int)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p16977243183018"><a name="p16977243183018"></a><a name="p16977243183018"></a>非空闲：0；空闲：1。</p>
</td>
</tr>
<tr id="row497744313309"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1897794353018"><a name="p1897794353018"></a><a name="p1897794353018"></a>DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p159771243123013"><a name="p159771243123013"></a><a name="p159771243123013"></a>unsigned long long</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15977204323010"><a name="p15977204323010"></a><a name="p15977204323010"></a>sizeof(unsigned long long)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p197784315304"><a name="p197784315304"></a><a name="p197784315304"></a>buf为8字节内存空间，每个bit对应一种降频原因。</p>
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
<p id="p1197794310304"><a name="p1197794310304"></a><a name="p1197794310304"></a>其中，soc_rated_power表示soc额定功率，其余为预留扩展空间。soc额定功率正确范围[150000,600000]。</p>
</td>
</tr>
</tbody>
</table>

子命令DCMI\_LP\_SUB\_CMD\_AICORE\_FREQREDUC\_CAUSE下，AI Core降频原因由一个64位的值表示，每个bit对应一种降频原因。当值为0时，说明AI Core以额定的频率运行。当值为1时，说明是由于某种原因引起AI Core不能以额定频率运行。同时由于降频原因可能由多个因素引起，所以可能存在多个bit被同时置1的情况。

**表 2**  buf值各bit对应的含义

<a name="table188972043193011"></a>
<table><thead align="left"><tr id="row8977543133019"><th class="cellrowborder" valign="top" width="25.27%" id="mcps1.2.4.1.1"><p id="p7978843103017"><a name="p7978843103017"></a><a name="p7978843103017"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.27%" id="mcps1.2.4.1.2"><p id="p59781843103015"><a name="p59781843103015"></a><a name="p59781843103015"></a>Bit位</p>
</th>
<th class="cellrowborder" valign="top" width="49.46%" id="mcps1.2.4.1.3"><p id="p797834319309"><a name="p797834319309"></a><a name="p797834319309"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row7978143143012"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p1497834315307"><a name="p1497834315307"></a><a name="p1497834315307"></a>IDLE</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p129787433303"><a name="p129787433303"></a><a name="p129787433303"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p17978164383013"><a name="p17978164383013"></a><a name="p17978164383013"></a>AI Core处于空闲状态，通过将AI Core频率降低到空闲时的频率来降低功耗。空闲状态需要持续一段时间，频率才会切换。</p>
</td>
</tr>
<tr id="row397814314309"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p12978194317301"><a name="p12978194317301"></a><a name="p12978194317301"></a>THERMAL</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p16978194383019"><a name="p16978194383019"></a><a name="p16978194383019"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p897894393014"><a name="p897894393014"></a><a name="p897894393014"></a><span id="ph1124218211961"><a name="ph1124218211961"></a><a name="ph1124218211961"></a>昇腾AI处理器</span>温度超过了允许的范围导致底层软件将AI Core的频率限制在一定的范围，从而来降低芯片的温度。</p>
</td>
</tr>
<tr id="row297804343016"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p6978124373015"><a name="p6978124373015"></a><a name="p6978124373015"></a>SW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p1097824314304"><a name="p1097824314304"></a><a name="p1097824314304"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997864373012"><a name="p997864373012"></a><a name="p997864373012"></a>在<span id="ph178115339610"><a name="ph178115339610"></a><a name="ph178115339610"></a>昇腾AI处理器</span>上，AI Core模块的供电电流超过了允许的范围导致底层软件将AI Core的频率限制在一定的范围，保证AI Core模块供电稳定。</p>
</td>
</tr>
<tr id="row1897894313010"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p1897816431303"><a name="p1897816431303"></a><a name="p1897816431303"></a>HW_EDP</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p59781343123016"><a name="p59781343123016"></a><a name="p59781343123016"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p1497804343013"><a name="p1497804343013"></a><a name="p1497804343013"></a>在<span id="ph12624153620718"><a name="ph12624153620718"></a><a name="ph12624153620718"></a>昇腾AI处理器</span>上，AI Core模块的瞬态供电电流超过了允许的范围导致主板上的电流传感器触发AI Core模块快速降频。</p>
</td>
</tr>
<tr id="row119787436308"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p197813434307"><a name="p197813434307"></a><a name="p197813434307"></a>POWER_BREAK</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p4978144310304"><a name="p4978144310304"></a><a name="p4978144310304"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p597894323019"><a name="p597894323019"></a><a name="p597894323019"></a>主板上的功率监测模块监测到供电功率超过了允许的最大上限，通知<span id="ph5911243772"><a name="ph5911243772"></a><a name="ph5911243772"></a>昇腾AI处理器</span>将AI Core的频率快速降低，维持供电稳定。</p>
</td>
</tr>
<tr id="row4978144318302"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="p897874303013"><a name="p897874303013"></a><a name="p897874303013"></a>SVFD</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="p11978134316303"><a name="p11978134316303"></a><a name="p11978134316303"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p997804363012"><a name="p997804363012"></a><a name="p997804363012"></a><span id="ph9116482712"><a name="ph9116482712"></a><a name="ph9116482712"></a>昇腾AI处理器</span>上的AI Core供电监测模块监测到AI Core模块的供电不稳（有噪声），触发AI Core快速降频，维持供电稳定。</p>
</td>
</tr>
<tr id="row730384616819"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001312397937_p11311634212"><a name="zh-cn_topic_0000001312397937_p11311634212"></a><a name="zh-cn_topic_0000001312397937_p11311634212"></a>POWERCAPPING</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001312397937_p169341949144114"><a name="zh-cn_topic_0000001312397937_p169341949144114"></a><a name="zh-cn_topic_0000001312397937_p169341949144114"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p13043467813"><a name="p13043467813"></a><a name="p13043467813"></a><span id="ph943235018720"><a name="ph943235018720"></a><a name="ph943235018720"></a>昇腾AI处理器</span>通过iBMC带外进行的功耗控制。</p>
</td>
</tr>
<tr id="row667034813815"><td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001312397937_p1761405971619"><a name="zh-cn_topic_0000001312397937_p1761405971619"></a><a name="zh-cn_topic_0000001312397937_p1761405971619"></a>LOAD_AWARE</p>
</td>
<td class="cellrowborder" valign="top" width="25.27%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001312397937_p161435931619"><a name="zh-cn_topic_0000001312397937_p161435931619"></a><a name="zh-cn_topic_0000001312397937_p161435931619"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="49.46%" headers="mcps1.2.4.1.3 "><p id="p116708488813"><a name="p116708488813"></a><a name="p116708488813"></a><span id="ph15936165214719"><a name="ph15936165214719"></a><a name="ph15936165214719"></a>昇腾AI处理器</span>通过AI负载感知模块进行的功耗控制。</p>
</td>
</tr>
</tbody>
</table>

**表 3** 不同部署场景下的支持情况

<a name="table116394134134"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section207091751457"></a>**

```c
…
int ret = 0;
int dev_id = 0;
unsigned int sub_cmd=0;
unsigned int voltage_current_buf = 0;
unsigned int buf_size = 8;
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_LP, sub_cmd, &voltage_current_buf, &buf_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
…
```

## DCMI\_MAIN\_CMD\_TS<a id="ZH-CN_TOPIC_0000002348043797"></a>

**函数原型<a name="section782265716308"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section19822105710305"></a>**

获取系统中TS相关信息。

**参数说明<a name="section188227576305"></a>**

<a name="table584175773016"></a>
<table><thead align="left"><tr id="row158991057133012"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1189945783015"><a name="p1189945783015"></a><a name="p1189945783015"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p13899165713012"><a name="p13899165713012"></a><a name="p13899165713012"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p789919571306"><a name="p789919571306"></a><a name="p789919571306"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p38991757123015"><a name="p38991757123015"></a><a name="p38991757123015"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1990019577303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p109001457133015"><a name="p109001457133015"></a><a name="p109001457133015"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1900175783013"><a name="p1900175783013"></a><a name="p1900175783013"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13900185710307"><a name="p13900185710307"></a><a name="p13900185710307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row19900125763017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p18900657173012"><a name="p18900657173012"></a><a name="p18900657173012"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p5900155783016"><a name="p5900155783016"></a><a name="p5900155783016"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p89002574308"><a name="p89002574308"></a><a name="p89002574308"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p590010578307"><a name="p590010578307"></a><a name="p590010578307"></a>DCMI_MAIN_CMD_TS</p>
</td>
</tr>
<tr id="row0900155743018"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p139001157183018"><a name="p139001157183018"></a><a name="p139001157183018"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p18900165743017"><a name="p18900165743017"></a><a name="p18900165743017"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1690018576308"><a name="p1690018576308"></a><a name="p1690018576308"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock84586272352"><a name="codeblock84586272352"></a><a name="codeblock84586272352"></a>typedef enum {
DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE = 0, //获取AI Core的单核利用率，正常值范围0-100
DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE, //获取VECTOR CORE的单核利用率/获取AI Core单核中Vector单元利用率，正常值范围0-100
DCMI_TS_SUB_CMD_FFTS_TYPE, //获取FFTS或者FFTS+的类型，0表示FFTS，1表示FFTS+
DCMI_TS_SUB_CMD_SET_FAULT_MASK, //设置硬件屏蔽AICORE ERR的掩码
DCMI_TS_SUB_CMD_GET_FAULT_MASK, //获取硬件屏蔽AICORE ERR的掩码
DCMI_TS_SUB_CMD_COMMON_MSG = 11, //获取算子超时时间刻度值，默认32，取值范围为[20, 32]
DCMI_TS_SUB_CMD_MAX, //枚举值上限标记
} DCMI_TS_SUB_CMD;</pre>
<p id="p20900857113015"><a name="p20900857113015"></a><a name="p20900857113015"></a>仅支持DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE、DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE、DCMI_TS_SUB_CMD_FFTS_TYPE和DCMI_TS_SUB_CMD_COMMON_MSG命令。</p>
<p id="p7900115703014"><a name="p7900115703014"></a><a name="p7900115703014"></a>开启profiling时，查询单核利用率结果为0xEF。</p>
</td>
</tr>
<tr id="row1190010575303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1190018574307"><a name="p1190018574307"></a><a name="p1190018574307"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19007577307"><a name="p19007577307"></a><a name="p19007577307"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p17900175711302"><a name="p17900175711302"></a><a name="p17900175711302"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p390012575308"><a name="p390012575308"></a><a name="p390012575308"></a>详见本节约束说明。</p>
</td>
</tr>
<tr id="row16900145719304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p9900155716309"><a name="p9900155716309"></a><a name="p9900155716309"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p0900185719304"><a name="p0900185719304"></a><a name="p0900185719304"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6901257173010"><a name="p6901257173010"></a><a name="p6901257173010"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p090113577301"><a name="p090113577301"></a><a name="p090113577301"></a>buf数组的长度/返回结果数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section2889103794114"></a>**

**表 1**  sub\_cmd对应的buf格式

<a name="table08529574303"></a>
<table><thead align="left"><tr id="row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="p59011457173015"><a name="p59011457173015"></a><a name="p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="p159011357193019"><a name="p159011357193019"></a><a name="p159011357193019"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="p1990165743011"><a name="p1990165743011"></a><a name="p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row12901185711304"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p8901195718303"><a name="p8901195718303"></a><a name="p8901195718303"></a>DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE、DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p1290105717308"><a name="p1290105717308"></a><a name="p1290105717308"></a>查询Vector Core的单核利用率时，buf至少为72字节内存空间，查询AI Core的单核利用率时，buf至少为36字节空间。</p>
<p id="p79011657193018"><a name="p79011657193018"></a><a name="p79011657193018"></a>异常值：</p>
<a name="ul16453131719569"></a><a name="ul16453131719569"></a><ul id="ul16453131719569"><li>0xEE：表示对应的core损坏</li><li>0xEF：无效值</li></ul>
<p id="p290185713306"><a name="p290185713306"></a><a name="p290185713306"></a>出参时每个字节表示一个核的利用率，正常范围0-100。</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><a name="ul1265125812106"></a><a name="ul1265125812106"></a><ul id="ul1265125812106"><li>作为入参时表示buf的大小。</li><li>作为出参时表示buf内填充的有效值的个数。</li></ul>
</td>
</tr>
<tr id="row6901185719303"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p179011357143018"><a name="p179011357143018"></a><a name="p179011357143018"></a>DCMI_TS_SUB_CMD_FFTS_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p89011657113020"><a name="p89011657113020"></a><a name="p89011657113020"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p12901115712303"><a name="p12901115712303"></a><a name="p12901115712303"></a>unsigned int</p>
</td>
</tr>
<tr id="row117519810014"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p19752148407"><a name="p19752148407"></a><a name="p19752148407"></a>DCMI_TS_SUB_CMD_COMMON_MSG</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p19469111244813"><a name="p19469111244813"></a><a name="p19469111244813"></a>struct ts_dcmi_ctrl_msg_body_t {</p>
<p id="p1246961219488"><a name="p1246961219488"></a><a name="p1246961219488"></a>unsigned int msg_type;</p>
<p id="p246915123487"><a name="p246915123487"></a><a name="p246915123487"></a>union {</p>
<p id="p1746901219481"><a name="p1746901219481"></a><a name="p1746901219481"></a>ts_dcmi_task_timeout_t set_task_timeout_info;</p>
<p id="p64691512154816"><a name="p64691512154816"></a><a name="p64691512154816"></a>ts_dcmi_task_timeout_t get_task_timeout_info;</p>
<p id="p13469131244812"><a name="p13469131244812"></a><a name="p13469131244812"></a>} u;</p>
<p id="p134691512204817"><a name="p134691512204817"></a><a name="p134691512204817"></a>};</p>
<p id="p1719316326501"><a name="p1719316326501"></a><a name="p1719316326501"></a>ts_dcmi_task_timeout_t结构体如下：</p>
<p id="p522516213502"><a name="p522516213502"></a><a name="p522516213502"></a>typedef struct {</p>
<p id="p32251323501"><a name="p32251323501"></a><a name="p32251323501"></a>unsigned int timeout_limit_exp; // 取值范围为[20，32]</p>
<p id="p222512155013"><a name="p222512155013"></a><a name="p222512155013"></a>unsigned char rsev[TS_RSEV_MAX_LENTH]; //TS_RSEV_MAX_LENTH为36</p>
<p id="p10225725506"><a name="p10225725506"></a><a name="p10225725506"></a>} ts_dcmi_task_timeout_t;</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p19359252485"><a name="p19359252485"></a><a name="p19359252485"></a>作为入参时表示buf的大小，buf至少为44字节。</p>
<p id="p19218195310"><a name="p19218195310"></a><a name="p19218195310"></a>msg_type取值为0或1。</p>
<a name="ul16848433145315"></a><a name="ul16848433145315"></a><ul id="ul16848433145315"><li>0表示查询AI CPU算子超时时间刻度。</li><li>1表示设置AI CPU算子超时时间刻度。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table159431741121314"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section49611431655"></a>**

```c
…
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
…
```

## DCMI\_MAIN\_CMD\_QOS<a id="ZH-CN_TOPIC_0000002347924125"></a>

**函数原型<a name="section14467101743119"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section204687171315"></a>**

获取QOS相关配置，包含获取指定的mpamid对应的QOS配置、指定master对应的QOS配置、带宽的统计值。

**参数说明<a name="section1546861713117"></a>**

<a name="table150171718316"></a>
<table><thead align="left"><tr id="row45967179312"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1359641710311"><a name="p1359641710311"></a><a name="p1359641710311"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p1596181753116"><a name="p1596181753116"></a><a name="p1596181753116"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p13596161712315"><a name="p13596161712315"></a><a name="p13596161712315"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p1359691733113"><a name="p1359691733113"></a><a name="p1359691733113"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row19596817133118"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p185961717183110"><a name="p185961717183110"></a><a name="p185961717183110"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p195961517143118"><a name="p195961517143118"></a><a name="p195961517143118"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1359617171318"><a name="p1359617171318"></a><a name="p1359617171318"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row459661713310"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p105971917113120"><a name="p105971917113120"></a><a name="p105971917113120"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p165973173319"><a name="p165973173319"></a><a name="p165973173319"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p3597617163117"><a name="p3597617163117"></a><a name="p3597617163117"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p45971417163119"><a name="p45971417163119"></a><a name="p45971417163119"></a>DCMI_MAIN_CMD_QOS</p>
</td>
</tr>
<tr id="row25975175318"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p659741718311"><a name="p659741718311"></a><a name="p659741718311"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p185971617163113"><a name="p185971617163113"></a><a name="p185971617163113"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p175971117123115"><a name="p175971117123115"></a><a name="p175971117123115"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock13311208103610"><a name="codeblock13311208103610"></a><a name="codeblock13311208103610"></a>typedef enum {
DCMI_QOS_SUB_MATA_CONFIG, //获取指定MATA的配置信息
DCMI_QOS_SUB_MASTER_CONFIG, //获取指定master的配置信息
DCMI_QOS_SUB_BW_DATA, //获取带宽的统计信息
DCMI_QOS_SUB_GLOBAL_CONFIG, //获取通用配置信息
DCMI_QOS_SUB_CONFIG_DONE, //配置完成指令
} DCMI_QOS_SUB_INFO;</pre>
<p id="p5929173053615"><a name="p5929173053615"></a><a name="p5929173053615"></a>仅支持DCMI_QOS_SUB_MATA_CONFIG、DCMI_QOS_SUB_MASTER_CONFIG、DCMI_QOS_SUB_BW_DATA、DCMI_QOS_SUB_GLOBAL_CONFIG命令。</p>
</td>
</tr>
<tr id="row1059751753117"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p165976179310"><a name="p165976179310"></a><a name="p165976179310"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p105971717153116"><a name="p105971717153116"></a><a name="p105971717153116"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13597191753119"><a name="p13597191753119"></a><a name="p13597191753119"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p13597161723117"><a name="p13597161723117"></a><a name="p13597161723117"></a>详见本节约束说明。</p>
</td>
</tr>
<tr id="row1597151743112"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p05974176319"><a name="p05974176319"></a><a name="p05974176319"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p45972017113117"><a name="p45972017113117"></a><a name="p45972017113117"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p8597717103117"><a name="p8597717103117"></a><a name="p8597717103117"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1759791793116"><a name="p1759791793116"></a><a name="p1759791793116"></a>buf数组的长度/返回结果数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section2977135411511"></a>**

- 受soc特性约束，需要调用[dcmiv2\_get\_device\_info](#ZH-CN_TOPIC_0000002314045082)后再调用相应get接口读取配置是否生效，否则读取值不可信。
- resctrl获取带宽功能与DCMI接口获取实时带宽功能冲突，如果已经启用其中一种，请勿并行使用另外一种。

**表 1**  sub\_cmd对应的buf格式

<a name="table1450912173312"></a>
<table><thead align="left"><tr id="row1359861743110"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p16598617103119"><a name="p16598617103119"></a><a name="p16598617103119"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.2"><p id="p8598131713110"><a name="p8598131713110"></a><a name="p8598131713110"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p195981717153117"><a name="p195981717153117"></a><a name="p195981717153117"></a>buf_size</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.5.1.4"><p id="p559831773117"><a name="p559831773117"></a><a name="p559831773117"></a>参数说明</p>
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
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul72057196131"></a><a name="ul72057196131"></a><ul id="ul72057196131"><li>mpamid：取值范围为[0,127]。</li><li>bw_high：上水线（GB/s），取值范围是[0,1638]。</li><li>bw_low：下水线（GB/s），取值范围是[0, bw_high]</li><li>hardlimit：1表示开启，0表示不开启</li></ul>
<p id="p13599191773117"><a name="p13599191773117"></a><a name="p13599191773117"></a>用户通过该接口读取水线，可能与先前用户配置值存在误差。误差值计算方式为：处理器最大带宽/MAX_REG_VALUE。其中，MAX_REG_VALUE取值为1024。</p>
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
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul1553122412134"></a><a name="ul1553122412134"></a><ul id="ul1553122412134"><li>master：master ID，表示芯片加速器的枚举值，支持项：vpc=2,jpge=3,jpgd=4,pcie=7,aic_data=9,aic_ins=10,aiv_data=11,aiv_ins=12,sdma=13,stars=14,ub_mem=33,pcie_ibr=40,pcie_ibw=41</li></ul>
<a name="ul13380123561319"></a><a name="ul13380123561319"></a><ul id="ul13380123561319"><li>mpamid：识别芯片加速器数据流的标签，取值范围为[0,127]。<div class="note" id="note19682131512477"><a name="note19682131512477"></a><a name="note19682131512477"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000002314204790_p6682191518479"><a name="zh-cn_topic_0000002314204790_p6682191518479"></a><a name="zh-cn_topic_0000002314204790_p6682191518479"></a>当master取值为pcie、pcie_ibr、pcie_ibw时，对应mpamid的取值范围为[0,31]。</p>
</div></div>
</li><li>qos：带宽调度优先级，取值范围为[0,7]，0作为hardlimit专用qos，7为调度绿色通道qos。</li><li>pmg：mpamid分组，取值范围为[0,3](当前不支持)。</li><li>bitmap：指定设置目标核的bitmap，因框架限制，不支持。</li></ul>
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
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul1366017281415"></a><a name="ul1366017281415"></a><ul id="ul1366017281415"><li>mpamid：获取带宽的目标mpamid。取值范围为[0,127]。</li><li>curr：最近时间点获取的带宽值（MB/s）。</li><li>bw_max：采样时间段内最大值（MB/s）。</li><li>bw_min：采样时间段内最小值（MB/s）。</li><li>bw_mean：采样时间段内的平均值（MB/s）。</li></ul>
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
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><a name="ul15992846123713"></a><a name="ul15992846123713"></a><ul id="ul15992846123713"><li>enable：是否启用QOS功能。<a name="ul1426935273713"></a><a name="ul1426935273713"></a><ul id="ul1426935273713"><li>0表示不启用</li><li>1表示启用</li></ul>
</li><li>autoqos_fuse_en：qos的融合开关。<a name="ul161181811163814"></a><a name="ul161181811163814"></a><ul id="ul161181811163814"><li>0表示关闭qos融合</li><li>1表示开始qos融合</li></ul>
</li><li>mpamqos_fuse_mode：qos的融合模式，autoqos_fuse_en开启的条件下生效。<a name="ul879644411386"></a><a name="ul879644411386"></a><ul id="ul879644411386"><li>0表示均值融合</li><li>1表示取随路qos和mpamqos之间的最大值作为融合结果</li><li>2表示使用随路qos替换mpamqos</li></ul>
</li><li>mpam_subtype：带宽统计的模式。<a name="ul16435328393"></a><a name="ul16435328393"></a><ul id="ul16435328393"><li>0表示统计读+写带宽</li><li>1表示统计写带宽</li><li>2表示统计读带宽</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row14793950814"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002347924121_p679315517810"><a name="zh-cn_topic_0000002347924121_p679315517810"></a><a name="zh-cn_topic_0000002347924121_p679315517810"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002347924121_p179310514818"><a name="zh-cn_topic_0000002347924121_p179310514818"></a><a name="zh-cn_topic_0000002347924121_p179310514818"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002347924121_p1079395582"><a name="zh-cn_topic_0000002347924121_p1079395582"></a><a name="zh-cn_topic_0000002347924121_p1079395582"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002347924121_p197931351285"><a name="zh-cn_topic_0000002347924121_p197931351285"></a><a name="zh-cn_topic_0000002347924121_p197931351285"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002347924121_p879318516814"><a name="zh-cn_topic_0000002347924121_p879318516814"></a><a name="zh-cn_topic_0000002347924121_p879318516814"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002347924121_p0844821165718"><a name="zh-cn_topic_0000002347924121_p0844821165718"></a><a name="zh-cn_topic_0000002347924121_p0844821165718"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row11793151389"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002347924121_p147931153816"><a name="zh-cn_topic_0000002347924121_p147931153816"></a><a name="zh-cn_topic_0000002347924121_p147931153816"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002347924121_p2793451784"><a name="zh-cn_topic_0000002347924121_p2793451784"></a><a name="zh-cn_topic_0000002347924121_p2793451784"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002347924121_p4793151781"><a name="zh-cn_topic_0000002347924121_p4793151781"></a><a name="zh-cn_topic_0000002347924121_p4793151781"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002347924121_p1479319510810"><a name="zh-cn_topic_0000002347924121_p1479319510810"></a><a name="zh-cn_topic_0000002347924121_p1479319510810"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002347924121_p207938516814"><a name="zh-cn_topic_0000002347924121_p207938516814"></a><a name="zh-cn_topic_0000002347924121_p207938516814"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002347924121_p18441821105717"><a name="zh-cn_topic_0000002347924121_p18441821105717"></a><a name="zh-cn_topic_0000002347924121_p18441821105717"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row6793185686"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002347924121_p47931353814"><a name="zh-cn_topic_0000002347924121_p47931353814"></a><a name="zh-cn_topic_0000002347924121_p47931353814"></a><span id="zh-cn_topic_0000002347924121_ph4793452817"><a name="zh-cn_topic_0000002347924121_ph4793452817"></a><a name="zh-cn_topic_0000002347924121_ph4793452817"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002347924121_p197931951183"><a name="zh-cn_topic_0000002347924121_p197931951183"></a><a name="zh-cn_topic_0000002347924121_p197931951183"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002347924121_p5335612280"><a name="zh-cn_topic_0000002347924121_p5335612280"></a><a name="zh-cn_topic_0000002347924121_p5335612280"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002347924121_p10793857815"><a name="zh-cn_topic_0000002347924121_p10793857815"></a><a name="zh-cn_topic_0000002347924121_p10793857815"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002347924121_p979319512813"><a name="zh-cn_topic_0000002347924121_p979319512813"></a><a name="zh-cn_topic_0000002347924121_p979319512813"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002347924121_p8793451183"><a name="zh-cn_topic_0000002347924121_p8793451183"></a><a name="zh-cn_topic_0000002347924121_p8793451183"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002347924121_p13287103414119"><a name="zh-cn_topic_0000002347924121_p13287103414119"></a><a name="zh-cn_topic_0000002347924121_p13287103414119"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row137945514817"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002347924121_p18794451582"><a name="zh-cn_topic_0000002347924121_p18794451582"></a><a name="zh-cn_topic_0000002347924121_p18794451582"></a><span id="zh-cn_topic_0000002347924121_ph379495689"><a name="zh-cn_topic_0000002347924121_ph379495689"></a><a name="zh-cn_topic_0000002347924121_ph379495689"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section176618596619"></a>**

```c
…
int ret = 0;
int dev_id = 0;
int size = sizeof(struct dcmi_qos_mata_config);
struct dcmi_qos_mata_config mataCfg = {0};
mataCfg.mpamid = 127;
unsigned int subCmd = (unsigned int)(DCMI_QOS_SUB_CMD_MAKE(mataCfg.mpamid, DCMI_QOS_SUB_MATA_CONFIG));
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_QOS, subCmd, (void *)&mataCfg, &size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
…
```

## DCMI\_MAIN\_CMD\_PCIE<a id="ZH-CN_TOPIC_0000002348043793"></a>

**函数原型<a name="section224642513574"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section162477254573"></a>**

获取PCIe相关信息。

**参数说明<a name="section16248625165719"></a>**

<a name="table23011825165718"></a>
<table><thead align="left"><tr id="row1644220264578"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p19442192665715"><a name="p19442192665715"></a><a name="p19442192665715"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p84426269577"><a name="p84426269577"></a><a name="p84426269577"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p164426264575"><a name="p164426264575"></a><a name="p164426264575"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p14424263576"><a name="p14424263576"></a><a name="p14424263576"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8442182617573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p134421126155713"><a name="p134421126155713"></a><a name="p134421126155713"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16442142613570"><a name="p16442142613570"></a><a name="p16442142613570"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p6442142615710"><a name="p6442142615710"></a><a name="p6442142615710"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1544262610576"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2044352611575"><a name="p2044352611575"></a><a name="p2044352611575"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p7443152613571"><a name="p7443152613571"></a><a name="p7443152613571"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p104439262577"><a name="p104439262577"></a><a name="p104439262577"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p844312611573"><a name="p844312611573"></a><a name="p844312611573"></a>DCMI_MAIN_CMD_PCIE</p>
</td>
</tr>
<tr id="row6443426185717"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p14431726185711"><a name="p14431726185711"></a><a name="p14431726185711"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p84431426165711"><a name="p84431426165711"></a><a name="p84431426165711"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1844312619576"><a name="p1844312619576"></a><a name="p1844312619576"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p11443162655718"><a name="p11443162655718"></a><a name="p11443162655718"></a><span>DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO</span></p>
</td>
</tr>
<tr id="row144342617576"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p0443172665711"><a name="p0443172665711"></a><a name="p0443172665711"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p644362612579"><a name="p644362612579"></a><a name="p644362612579"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p154431526205714"><a name="p154431526205714"></a><a name="p154431526205714"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p194431626195715"><a name="p194431626195715"></a><a name="p194431626195715"></a>详细见本章<a href="#section142847254570">约束说明</a>。</p>
</td>
</tr>
<tr id="row1144315264573"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p2443526125719"><a name="p2443526125719"></a><a name="p2443526125719"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12443326145716"><a name="p12443326145716"></a><a name="p12443326145716"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p4443526135714"><a name="p4443526135714"></a><a name="p4443526135714"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p3443102675716"><a name="p3443102675716"></a><a name="p3443102675716"></a>buf数组长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section142847254570"></a>**

仅Control CPU开放形态使用该接口。

**表 1**  sub\_cmd对应的buf格式

<a name="table131652519571"></a>
<table><thead align="left"><tr id="row144441226125711"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p64441826115711"><a name="p64441826115711"></a><a name="p64441826115711"></a><strong id="b3444192610574"><a name="b3444192610574"></a><a name="b3444192610574"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p64444261570"><a name="p64444261570"></a><a name="p64444261570"></a>Buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1644432645711"><a name="p1644432645711"></a><a name="p1644432645711"></a><strong id="b13444726175712"><a name="b13444726175712"></a><a name="b13444726175712"></a>参数说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row12444826175711"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17444112611573"><a name="p17444112611573"></a><a name="p17444112611573"></a><span>DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO</span></p>
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
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7445142665715"><a name="p7445142665715"></a><a name="p7445142665715"></a>获取pcie link error相关值。</p>
<a name="ul19681694120"></a><a name="ul19681694120"></a><ul id="ul19681694120"><li>tx_err_cnt表示PCIe发送错误计数</li><li>rx_err_cnt表示PCIe接收错误计数</li><li>lcrc_err_cnt表示PCIe DLLP LCRC校验错误计数</li><li>ecrc_err_cnt表示PCIe TLP ECRC校验错误计数</li><li>retry_cnt表示PCIe链路重传计数</li><li>rsv保留字段</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section8297125115718"></a>**

```c
…
int ret = 0;
int dev_id = 0;
struct dcmi_pcie_link_error_info pcie_link_error_info = {0};
unsigned int info_leng = sizeof(struct dcmi_pcie_link_error_info);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_PCIE, DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO, &pcie_link_error_info, &info_leng);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

## DCMI\_MAIN\_CMD\_SIO<a id="ZH-CN_TOPIC_0000002314204826"></a>

**函数原型<a name="section88293413398"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section166811419153914"></a>**

查询die间SIO状态。

**参数说明<a name="section9437204012398"></a>**

<a name="table1317154133812"></a>
<table><thead align="left"><tr id="row181231554203812"><th class="cellrowborder" valign="top" width="17.078292170782923%" id="mcps1.1.5.1.1"><p id="p12123105418389"><a name="p12123105418389"></a><a name="p12123105418389"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.17848215178482%" id="mcps1.1.5.1.2"><p id="p1712314549389"><a name="p1712314549389"></a><a name="p1712314549389"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.168083191680832%" id="mcps1.1.5.1.3"><p id="p141231454103812"><a name="p141231454103812"></a><a name="p141231454103812"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.57514248575143%" id="mcps1.1.5.1.4"><p id="p11123185412382"><a name="p11123185412382"></a><a name="p11123185412382"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row17124954123815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p16124165419387"><a name="p16124165419387"></a><a name="p16124165419387"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p212418549389"><a name="p212418549389"></a><a name="p212418549389"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p101241854153819"><a name="p101241854153819"></a><a name="p101241854153819"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1512419544383"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p2012485453813"><a name="p2012485453813"></a><a name="p2012485453813"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p1312405417387"><a name="p1312405417387"></a><a name="p1312405417387"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p31241754173815"><a name="p31241754173815"></a><a name="p31241754173815"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p16124105417386"><a name="p16124105417386"></a><a name="p16124105417386"></a>DCMI_MAIN_CMD_SIO</p>
</td>
</tr>
<tr id="row5124754193815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p161249543383"><a name="p161249543383"></a><a name="p161249543383"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p111248547386"><a name="p111248547386"></a><a name="p111248547386"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p1812465411385"><a name="p1812465411385"></a><a name="p1812465411385"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock117365575012"><a name="codeblock117365575012"></a><a name="codeblock117365575012"></a>typedef enum {
DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS = 0 //获取die间SIO状态
}DCMI_SIO_SUB_CMD;</pre>
</td>
</tr>
<tr id="row2012511546389"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p7125165483817"><a name="p7125165483817"></a><a name="p7125165483817"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p10125554153817"><a name="p10125554153817"></a><a name="p10125554153817"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p16125115414381"><a name="p16125115414381"></a><a name="p16125115414381"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p1612555420387"><a name="p1612555420387"></a><a name="p1612555420387"></a>详细见本节<a href="#section1374114910415">约束说明</a>。</p>
</td>
</tr>
<tr id="row7125254143815"><td class="cellrowborder" valign="top" width="17.078292170782923%" headers="mcps1.1.5.1.1 "><p id="p4125165433814"><a name="p4125165433814"></a><a name="p4125165433814"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.17848215178482%" headers="mcps1.1.5.1.2 "><p id="p18125115416386"><a name="p18125115416386"></a><a name="p18125115416386"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.168083191680832%" headers="mcps1.1.5.1.3 "><p id="p7125145419382"><a name="p7125145419382"></a><a name="p7125145419382"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.57514248575143%" headers="mcps1.1.5.1.4 "><p id="p81251954153819"><a name="p81251954153819"></a><a name="p81251954153819"></a>返回结果数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section1374114910415"></a>**

**表 1**  sub\_cmd对应的buf格式

<a name="table1148155443816"></a>
<table><thead align="left"><tr id="row7126155473815"><th class="cellrowborder" valign="top" width="24.45%" id="mcps1.2.5.1.1"><p id="p1312695412383"><a name="p1312695412383"></a><a name="p1312695412383"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="32.99%" id="mcps1.2.5.1.2"><p id="p121262547386"><a name="p121262547386"></a><a name="p121262547386"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="20.01%" id="mcps1.2.5.1.3"><p id="p0126254113814"><a name="p0126254113814"></a><a name="p0126254113814"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="22.55%" id="mcps1.2.5.1.4"><p id="p106461111681"><a name="p106461111681"></a><a name="p106461111681"></a>参数说明</p>
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
<td class="cellrowborder" valign="top" width="22.55%" headers="mcps1.2.5.1.4 "><a name="ul89281736384"></a><a name="ul89281736384"></a><ul id="ul89281736384"><li>tx_error_count表示SIO发送错误的个数。</li><li>rx_error_count表示SIO接收错误的个数。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table159431741121314"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section083811564420"></a>**

```c
…
int ret = 0;
int dev_id = 0;
struct dcmi_sio_crc_err_statistics_info sio_info = {0};
unsigned int sio_info_size = sizeof(struct dcmi_sio_crc_err_statistics_info);
ret = dcmiv2_get_device_info(dev_id, DCMI_MAIN_CMD_SIO, DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS, &sio_info, &sio_info_size);
if (ret != 0) {
//todo
return ret;
} else {
// todo
return ret;
}
…
```

## DCMI\_MAIN\_CMD\_EX\_COMPUTING<a id="ZH-CN_TOPIC_0000002544184079"></a>

**函数原型<a name="section251144503117"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section4511154520314"></a>**

获取算力token值。

**参数说明<a name="section195111645193117"></a>**

<a name="table145283455316"></a>
<table><thead align="left"><tr id="row963614518316"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p96361345163111"><a name="p96361345163111"></a><a name="p96361345163111"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p1963644563115"><a name="p1963644563115"></a><a name="p1963644563115"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p46361745193112"><a name="p46361745193112"></a><a name="p46361745193112"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p15636144519316"><a name="p15636144519316"></a><a name="p15636144519316"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row163617450316"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p126362454318"><a name="p126362454318"></a><a name="p126362454318"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p6636174518315"><a name="p6636174518315"></a><a name="p6636174518315"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p4636194553115"><a name="p4636194553115"></a><a name="p4636194553115"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row166363454319"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p16636145193116"><a name="p16636145193116"></a><a name="p16636145193116"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p6637545163119"><a name="p6637545163119"></a><a name="p6637545163119"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p20637104516316"><a name="p20637104516316"></a><a name="p20637104516316"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p16371245203115"><a name="p16371245203115"></a><a name="p16371245203115"></a>DCMI_MAIN_CMD_EX_COMPUTING</p>
</td>
</tr>
<tr id="row663754533112"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p106371145153114"><a name="p106371145153114"></a><a name="p106371145153114"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p5637144510311"><a name="p5637144510311"></a><a name="p5637144510311"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p106374457316"><a name="p106374457316"></a><a name="p106374457316"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p11637204512315"><a name="p11637204512315"></a><a name="p11637204512315"></a>DCMI_EX_COMPUTING_SUB_CMD_TOKEN</p>
</td>
</tr>
<tr id="row20637114553111"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1163734513119"><a name="p1163734513119"></a><a name="p1163734513119"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p17637545203112"><a name="p17637545203112"></a><a name="p17637545203112"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1163719452314"><a name="p1163719452314"></a><a name="p1163719452314"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p106372452314"><a name="p106372452314"></a><a name="p106372452314"></a>详见本节<a href="#section168551249144914">约束说明</a>。</p>
</td>
</tr>
<tr id="row146374453314"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p10637184563116"><a name="p10637184563116"></a><a name="p10637184563116"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p126373451313"><a name="p126373451313"></a><a name="p126373451313"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13637445163120"><a name="p13637445163120"></a><a name="p13637445163120"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p3637184518311"><a name="p3637184518311"></a><a name="p3637184518311"></a>返回结果数据长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section168551249144914"></a>**

**表 1**  sub\_cmd对应的buf格式

<a name="table353514454317"></a>
<table><thead align="left"><tr id="row263834543117"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p166382458312"><a name="p166382458312"></a><a name="p166382458312"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.2"><p id="p16638645113120"><a name="p16638645113120"></a><a name="p16638645113120"></a>buf对应的数据类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p263819453310"><a name="p263819453310"></a><a name="p263819453310"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="40%" id="mcps1.2.5.1.4"><p id="p1638145183117"><a name="p1638145183117"></a><a name="p1638145183117"></a>参数说明</p>
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
<td class="cellrowborder" valign="top" width="40%" headers="mcps1.2.5.1.4 "><p id="p1638144514312"><a name="p1638144514312"></a><a name="p1638144514312"></a>获取算力token值，value值的正确范围：[0,65535]。</p>
<p id="p6638164513117"><a name="p6638164513117"></a><a name="p6638164513117"></a>a. value表示算力值。</p>
<p id="p863819458316"><a name="p863819458316"></a><a name="p863819458316"></a>b. type表示license BOM编码转换后的类型值。</p>
<p id="p20638345123117"><a name="p20638345123117"></a><a name="p20638345123117"></a>c. reserve_c表示保留字，当前预留，不使用。</p>
<p id="p1663810451310"><a name="p1663810451310"></a><a name="p1663810451310"></a>d. reserve_s表示保留字，当前预留，不使用。</p>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table159431741121314"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section172981043978"></a>**

```c
…
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
…
```

## DCMI\_MAIN\_CMD\_EX\_CERT<a id="ZH-CN_TOPIC_0000002509588792"></a>

**函数原型<a name="section5922172553416"></a>**

**int dcmiv2\_get\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, void \*buf, unsigned int \*size\)**

**功能说明<a name="section367034213346"></a>**

用于获取TLS证书相关信息。

**参数说明<a name="section19821164963414"></a>**

<a name="table6879815113410"></a>
<table><thead align="left"><tr id="row911191616342"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="p81111693412"><a name="p81111693412"></a><a name="p81111693412"></a><strong id="b19112165345"><a name="b19112165345"></a><a name="b19112165345"></a>参数名</strong></p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.2"><p id="p811111619348"><a name="p811111619348"></a><a name="p811111619348"></a><strong id="b01113166342"><a name="b01113166342"></a><a name="b01113166342"></a>输入/输出</strong></p>
</th>
<th class="cellrowborder" valign="top" width="19.189999999999998%" id="mcps1.1.5.1.3"><p id="p1911516173411"><a name="p1911516173411"></a><a name="p1911516173411"></a><strong id="b121151693418"><a name="b121151693418"></a><a name="b121151693418"></a>类型</strong></p>
</th>
<th class="cellrowborder" valign="top" width="62.629999999999995%" id="mcps1.1.5.1.4"><p id="p15113163349"><a name="p15113163349"></a><a name="p15113163349"></a><strong id="b121161614348"><a name="b121161614348"></a><a name="b121161614348"></a>描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row9111316183415"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p13111716133419"><a name="p13111716133419"></a><a name="p13111716133419"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p81117168341"><a name="p81117168341"></a><a name="p81117168341"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p151171615344"><a name="p151171615344"></a><a name="p151171615344"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="./dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row15128165343"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p81241613416"><a name="p81241613416"></a><a name="p81241613416"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p19121016153415"><a name="p19121016153415"></a><a name="p19121016153415"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p212616113417"><a name="p212616113417"></a><a name="p212616113417"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1012101643419"><a name="p1012101643419"></a><a name="p1012101643419"></a>DCMI_MAIN_CMD_EX_CERT</p>
</td>
</tr>
<tr id="row1121016153416"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p912111603417"><a name="p912111603417"></a><a name="p912111603417"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p1812151618349"><a name="p1812151618349"></a><a name="p1812151618349"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p10121016133413"><a name="p10121016133413"></a><a name="p10121016133413"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1909144281914"><a name="p1909144281914"></a><a name="p1909144281914"></a>typedef enum {</p>
<p id="p16909134251918"><a name="p16909134251918"></a><a name="p16909134251918"></a>DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY = 0, //初始化TLS证书（用于获取CSR）</p>
<p id="p189091942131912"><a name="p189091942131912"></a><a name="p189091942131912"></a>DCMI_CERT_SUB_CMD_INIT_RESERVE, //初始化预留字段</p>
<p id="p99091942161915"><a name="p99091942161915"></a><a name="p99091942161915"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO, //获取TLS证书信息</p>
<p id="p89094428194"><a name="p89094428194"></a><a name="p89094428194"></a>DCMI_CERT_SUB_CMD_MAX, //枚举值上限标记</p>
<p id="p790919427194"><a name="p790919427194"></a><a name="p790919427194"></a>} DCMI_EX_CERT_SUB_CMD;</p>
<p id="p2797182871618"><a name="p2797182871618"></a><a name="p2797182871618"></a>仅支持DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY和DCMI_CERT_SUB_CMD_TLS_CERT_INFO命令。</p>
</td>
</tr>
<tr id="row612121619349"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p5129164343"><a name="p5129164343"></a><a name="p5129164343"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p312616163411"><a name="p312616163411"></a><a name="p312616163411"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p151219163343"><a name="p151219163343"></a><a name="p151219163343"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1512516103412"><a name="p1512516103412"></a><a name="p1512516103412"></a>详见本节<a href="#section1422146133417">约束说明</a>。</p>
</td>
</tr>
<tr id="row1912101611341"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p112151617346"><a name="p112151617346"></a><a name="p112151617346"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p11121616193413"><a name="p11121616193413"></a><a name="p11121616193413"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p512151616341"><a name="p512151616341"></a><a name="p512151616341"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p191317165344"><a name="p191317165344"></a><a name="p191317165344"></a>buf数组的长度。</p>
</td>
</tr>
</tbody>
</table>

**返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>**

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="./return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

**约束说明<a name="section1422146133417"></a>**

**表 1**  sub\_cmd对应的buf格式

<a name="table1892515103416"></a>
<table><thead align="left"><tr id="row1713716153413"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.1"><p id="p81313161345"><a name="p81313161345"></a><a name="p81313161345"></a><strong id="b913916193413"><a name="b913916193413"></a><a name="b913916193413"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.2.5.1.2"><p id="p813201610342"><a name="p813201610342"></a><a name="p813201610342"></a><strong id="b2132165342"><a name="b2132165342"></a><a name="b2132165342"></a>buf对应的数据类型</strong></p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.5.1.3"><p id="p151351673417"><a name="p151351673417"></a><a name="p151351673417"></a><strong id="b11133165345"><a name="b11133165345"></a><a name="b11133165345"></a>size</strong></p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.2.5.1.4"><p id="p7131516203415"><a name="p7131516203415"></a><a name="p7131516203415"></a><strong id="b201361683411"><a name="b201361683411"></a><a name="b201361683411"></a>参数说明</strong></p>
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
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p2141116103414"><a name="p2141116103414"></a><a name="p2141116103414"></a>返回公钥或者证书信息长度</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.4 "><a name="ul57333280138"></a><a name="ul57333280138"></a><ul id="ul57333280138"><li>country_name：国家名称</li><li>province_name：州或省名称</li><li>city_name：地区名称</li><li>organization_name：组织名称</li><li>department_name：组织内的部门名称</li><li>reserve_name：保留名称</li><li>reserve：保留</li><li>csr_len：csr请求内容的长度</li><li>csr_data：csr请求内容</li></ul>
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
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.5.1.3 "><p id="p614141693419"><a name="p614141693419"></a><a name="p614141693419"></a>返回公钥或者证书信息长度</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.5.1.4 "><a name="ul11930122181818"></a><a name="ul11930122181818"></a><ul id="ul11930122181818"><li>alarm_stat：证书告警状态，0-正常，1-证书即将过期，2-证书已过期/失效（只有在读取时呈现证书即将过期，不主动呈现）</li><li>reserve：保留</li><li>start_time：证书生效的起始时间</li><li>end_time：证书生效的结束时间</li><li>country_name：国家名称</li><li>province_name：州或省名称</li><li>city_name：地区名称</li><li>organization_name：组织名称</li><li>department_name：组织内的部门名称</li><li>reserve_name：保留名称</li><li>common_name：证书的通用名，这里填充的是device的DIE-ID</li></ul>
</td>
</tr>
</tbody>
</table>

**表 2** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="zh-cn_topic_0000002347924121_p134011119145110"><a name="zh-cn_topic_0000002347924121_p134011119145110"></a><a name="zh-cn_topic_0000002347924121_p134011119145110"></a>直通虚拟机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="zh-cn_topic_0000002347924121_p792517432563"><a name="zh-cn_topic_0000002347924121_p792517432563"></a><a name="zh-cn_topic_0000002347924121_p792517432563"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="zh-cn_topic_0000002347924121_p144015195510"><a name="zh-cn_topic_0000002347924121_p144015195510"></a><a name="zh-cn_topic_0000002347924121_p144015195510"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="zh-cn_topic_0000002347924121_p4925144311565"><a name="zh-cn_topic_0000002347924121_p4925144311565"></a><a name="zh-cn_topic_0000002347924121_p4925144311565"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p12401219145119"><a name="zh-cn_topic_0000002347924121_p12401219145119"></a><a name="zh-cn_topic_0000002347924121_p12401219145119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="zh-cn_topic_0000002347924121_p13512541619"><a name="zh-cn_topic_0000002347924121_p13512541619"></a><a name="zh-cn_topic_0000002347924121_p13512541619"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

**调用示例<a name="section5271151515373"></a>**

```c
…
int ret;
int dev_id = 0;
struct dcmi_cert_info cert_info = { 0 };
enum dcmi_main_cmd main_cmd = DCMI_MAIN_CMD_EX_CERT;
unsigned int sub_cmd = DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY;
unsigned int size = sizeof(struct dcmi_csr_info);
ret = dcmiv2_get_device_info(dev_id, main_cmd, sub_cmd, (const void *)&cert_info, size);
if (ret) {
   // todo
}
// todo
…
```
