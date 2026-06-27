# dcmiv2\_revoke\_device\_sec\_key<a name="ZH-CN_TOPIC_0000002314204814"></a>

## 函数原型<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_toc533412077"></a>

**int dcmiv2\_revoke\_device\_sec\_key\(int dev\_id, enum dcmi\_revo\_type input\_type, const unsigned char \*file\_data, unsigned int file\_size\)**

## 功能说明<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_toc533412078"></a>

实现密钥吊销功能。

## 参数说明<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_toc533412079"></a>

<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p10021890"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p10021890"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p6466753"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p6466753"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p54045009"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p54045009"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="48.96%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p15569626"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p15569626"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7711145152918"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7711145152918"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p671116522914"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p671116522914"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1771116572910"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1771116572910"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p5522164215178"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p5522164215178"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p5522164215178"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p8522242101715"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p8522242101715"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p8522242101715"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p17522114220174"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p17522114220174"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p17522114220174"></a>enum dcmi_revo_type</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p0522164231718"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p0522164231718"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p0522164231718"></a>吊销类型。</p>
<pre class="codeblock" id="codeblock163931351123"><a name="codeblock163931351123"></a><a name="codeblock163931351123"></a>enum dcmi_revo_type {
DCMI_REVOCATION_TYPE_SOC = 0, //用于吊销SOC密钥
DCMI_REVOCATION_TYPE_CMS_CRL = 1,  //用于MDC CMS CRL文件升级
DCMI_REVOCATION_TYPE_CMS_CRL_EXT = 2, //用于扩展CRL文件升级
DCMI_REVOCATION_TYPE_MAX
};</pre>
<p id="p171201345786"><a name="p171201345786"></a><a name="p171201345786"></a>当前仅支持DCMI_REVOCATION_TYPE_SOC。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_row46671240105418"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p14667114012547"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p14667114012547"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p14667114012547"></a>file_data</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7668154095417"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7668154095417"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p7668154095417"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p566818401548"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p566818401548"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p566818401548"></a>const unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1366819403540"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1366819403540"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p1366819403540"></a>吊销文件的数据地址。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_row1306946165516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307146105520"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307146105520"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307146105520"></a>file_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p830764614555"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p830764614555"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p830764614555"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307746155515"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307746155515"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p16307746155515"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p630704645512"><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p630704645512"></a><a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_p630704645512"></a>吊销文件的数据长度，Soc二级密钥吊销操作的文件长度固定为544字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>

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
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_toc533412082"></a>

- 密钥吊销操作是不可逆的过程，吊销操作执行成功后，无法再进行恢复，需要谨慎使用。
- 该接口在确定需要进行对应的吊销操作时才可以调用，并且需要正确的吊销文件才可以吊销成功，否则，调用该接口返回失败。
- 执行吊销操作成功后，设备不可用。
- 该接口需调入TEEOS，耗时较长，不支持在接口调用时触发休眠唤醒，如果触发休眠，有较大可能造成休眠失败。
- SMP系统，在执行吊销操作前必须先获取设备个数，然后对所有的设备均执行吊销操作。

**表 1** 不同部署场景下的支持情况

<a name="table155158516230"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row9596171719419"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p1059661716417"><a name="zh-cn_topic_0000002347924121_p1059661716417"></a><a name="zh-cn_topic_0000002347924121_p1059661716417"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p115964174411"><a name="zh-cn_topic_0000002347924121_p115964174411"></a><a name="zh-cn_topic_0000002347924121_p115964174411"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p3663614615"><a name="zh-cn_topic_0000002347924121_p3663614615"></a><a name="zh-cn_topic_0000002347924121_p3663614615"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p1559620177411"><a name="zh-cn_topic_0000002347924121_p1559620177411"></a><a name="zh-cn_topic_0000002347924121_p1559620177411"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p10613162423514"><a name="zh-cn_topic_0000002347924121_p10613162423514"></a><a name="zh-cn_topic_0000002347924121_p10613162423514"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row959614172418"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p15596151714414"><a name="zh-cn_topic_0000002347924121_p15596151714414"></a><a name="zh-cn_topic_0000002347924121_p15596151714414"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p559611171344"><a name="zh-cn_topic_0000002347924121_p559611171344"></a><a name="zh-cn_topic_0000002347924121_p559611171344"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p866318118620"><a name="zh-cn_topic_0000002347924121_p866318118620"></a><a name="zh-cn_topic_0000002347924121_p866318118620"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p1959614171345"><a name="zh-cn_topic_0000002347924121_p1959614171345"></a><a name="zh-cn_topic_0000002347924121_p1959614171345"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p82264478360"><a name="zh-cn_topic_0000002347924121_p82264478360"></a><a name="zh-cn_topic_0000002347924121_p82264478360"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row135967178414"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p2596121712410"><a name="zh-cn_topic_0000002347924121_p2596121712410"></a><a name="zh-cn_topic_0000002347924121_p2596121712410"></a><span id="zh-cn_topic_0000002347924121_ph259617171249"><a name="zh-cn_topic_0000002347924121_ph259617171249"></a><a name="zh-cn_topic_0000002347924121_ph259617171249"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p6596111711414"><a name="zh-cn_topic_0000002347924121_p6596111711414"></a><a name="zh-cn_topic_0000002347924121_p6596111711414"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p25961017947"><a name="zh-cn_topic_0000002347924121_p25961017947"></a><a name="zh-cn_topic_0000002347924121_p25961017947"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p17398249175310"><a name="zh-cn_topic_0000002347924121_p17398249175310"></a><a name="zh-cn_topic_0000002347924121_p17398249175310"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1529918247412"><a name="zh-cn_topic_0000002347924121_p1529918247412"></a><a name="zh-cn_topic_0000002347924121_p1529918247412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p1932714266187"><a name="zh-cn_topic_0000002347924121_p1932714266187"></a><a name="zh-cn_topic_0000002347924121_p1932714266187"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row155971917944"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p18597217849"><a name="zh-cn_topic_0000002347924121_p18597217849"></a><a name="zh-cn_topic_0000002347924121_p18597217849"></a><span id="zh-cn_topic_0000002347924121_ph3597217240"><a name="zh-cn_topic_0000002347924121_ph3597217240"></a><a name="zh-cn_topic_0000002347924121_ph3597217240"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001251307177_zh-cn_topic_0000001178373148_zh-cn_topic_0000001101604520_toc533412083"></a>

```c
…
#define REVOCATION_FILE_LEN  544
int dev_id = 0;
int ret = 0;
unsigned char revocation_file_buf[REVOCATION_FILE_LEN] = {0};
unsigned int buf_size = REVOCATION_FILE_LEN;
ret = dcmiv2_revoke_device_sec_key(dev_id, DCMI_REVOCATION_TYPE_SOC, (const unsigned char *)revocation_file_buf, buf_size);
if (ret != 0){
    // todo:记录日志
    return ret;
}
…
```
