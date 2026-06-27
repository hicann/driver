# dcmiv2\_clear\_device\_user\_config<a name="ZH-CN_TOPIC_0000002314045182"></a>

## 函数原型<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_toc533412077"></a>

**int dcmiv2\_clear\_device\_user\_config\(int dev\_id, const char \*config\_name\)**

## 功能说明<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_toc533412078"></a>

重置用户配置。

默认值请参见[dcmiv2\_set\_device\_user\_config](dcmiv2_set_device_user_config.md)。

## 参数说明<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_toc533412079"></a>

<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p10021890"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p10021890"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p6466753"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p6466753"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.990000000000002%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p54045009"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p54045009"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.01%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p15569626"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p15569626"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p7711145152918"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p7711145152918"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p671116522914"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p671116522914"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1771116572910"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1771116572910"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_row6326181581618"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p146993253912"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p146993253912"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p146993253912"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p469916256914"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p469916256914"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p469916256914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1633516491298"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1633516491298"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1633516491298"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.01%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_zh-cn_topic_0158027668_p182531815143013"></a>目前支持处理的配置项名称如下，配置项名称的字符串长度最大为32。</p>
<p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1795311111557"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1795311111557"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1795311111557"></a>已实现功能的配置项：mac_info、cert_expired_threshold。支持用户自定义名称配置。</p>
<p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p189533165513"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p189533165513"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p189533165513"></a>配置项功能说明如下：</p>
<a name="ul19317152017148"></a><a name="ul19317152017148"></a><ul id="ul19317152017148"><li>"mac_info"：用于设置MAC地址。</li><li>"cert_expired_threshold"：用于设置证书过期时间阈值。</li></ul>
<div class="note" id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_note1462701516448"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_note1462701516448"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_zh-cn_topic_0204328569_note1462701516448"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1096212366311"><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1096212366311"></a><a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_p1096212366311"></a>调用该接口配置标记后，需要复位芯片，配置才能生效。配置生效后，可通过<a href="dcmiv2_get_device_user_config.md">dcmiv2_get_device_user_config</a>接口查看配置结果。</p>
</div></div>
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

## 约束说明<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_toc533412082"></a>

该接口设置的内容会涉及Flash擦写，由于Flash擦写次数是有限制的，所以不建议频繁调用该接口。

该接口需调入TEEOS，耗时较长，不支持在接口调用时触发休眠唤醒，如果触发休眠，有较大可能造成休眠失败。

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p2935151833910"><a name="zh-cn_topic_0000002347924121_p2935151833910"></a><a name="zh-cn_topic_0000002347924121_p2935151833910"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p4935151817398"><a name="zh-cn_topic_0000002347924121_p4935151817398"></a><a name="zh-cn_topic_0000002347924121_p4935151817398"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p1293611188391"><a name="zh-cn_topic_0000002347924121_p1293611188391"></a><a name="zh-cn_topic_0000002347924121_p1293611188391"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p293616189396"><a name="zh-cn_topic_0000002347924121_p293616189396"></a><a name="zh-cn_topic_0000002347924121_p293616189396"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p8936121813397"><a name="zh-cn_topic_0000002347924121_p8936121813397"></a><a name="zh-cn_topic_0000002347924121_p8936121813397"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p6936318183917"><a name="zh-cn_topic_0000002347924121_p6936318183917"></a><a name="zh-cn_topic_0000002347924121_p6936318183917"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p79361718193918"><a name="zh-cn_topic_0000002347924121_p79361718193918"></a><a name="zh-cn_topic_0000002347924121_p79361718193918"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p593617183393"><a name="zh-cn_topic_0000002347924121_p593617183393"></a><a name="zh-cn_topic_0000002347924121_p593617183393"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p2936171814397"><a name="zh-cn_topic_0000002347924121_p2936171814397"></a><a name="zh-cn_topic_0000002347924121_p2936171814397"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1693671803910"><a name="zh-cn_topic_0000002347924121_p1693671803910"></a><a name="zh-cn_topic_0000002347924121_p1693671803910"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p1593651816390"><a name="zh-cn_topic_0000002347924121_p1593651816390"></a><a name="zh-cn_topic_0000002347924121_p1593651816390"></a><span id="zh-cn_topic_0000002347924121_ph2936121814391"><a name="zh-cn_topic_0000002347924121_ph2936121814391"></a><a name="zh-cn_topic_0000002347924121_ph2936121814391"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p189361818183914"><a name="zh-cn_topic_0000002347924121_p189361818183914"></a><a name="zh-cn_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p87162683916"><a name="zh-cn_topic_0000002347924121_p87162683916"></a><a name="zh-cn_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p57342614392"><a name="zh-cn_topic_0000002347924121_p57342614392"></a><a name="zh-cn_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1775132653914"><a name="zh-cn_topic_0000002347924121_p1775132653914"></a><a name="zh-cn_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p377112603919"><a name="zh-cn_topic_0000002347924121_p377112603919"></a><a name="zh-cn_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p9936131853915"><a name="zh-cn_topic_0000002347924121_p9936131853915"></a><a name="zh-cn_topic_0000002347924121_p9936131853915"></a><span id="zh-cn_topic_0000002347924121_ph3936171813916"><a name="zh-cn_topic_0000002347924121_ph3936171813916"></a><a name="zh-cn_topic_0000002347924121_ph3936171813916"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206627180_zh-cn_topic_0000001178054664_zh-cn_topic_0000001102358324_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
const char *config_name = "mac_info";
ret = dcmiv2_clear_device_user_config(dev_id, config_name);
if (ret != 0) {
    //todo：记录日志
    return ret;
}
…
```
