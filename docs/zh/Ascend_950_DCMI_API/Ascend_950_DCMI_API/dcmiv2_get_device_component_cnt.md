# dcmiv2\_get\_device\_component\_cnt<a name="ZH-CN_TOPIC_0000002347924145"></a>

## 函数原型<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_toc533412077"></a>

**int dcmiv2\_get\_device\_component\_cnt\(int dev\_id, unsigned int \*component\_count\)**

## 功能说明<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_toc533412078"></a>

获取可升级组件的个数。

## 参数说明<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_toc533412079"></a>

<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_row7580267"><th class="cellrowborder" valign="top" width="19.62%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p10021890"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p10021890"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.48%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p6466753"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p6466753"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="15.9%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p54045009"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p54045009"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p15569626"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p15569626"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_row1155711494235"><td class="cellrowborder" valign="top" width="19.62%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p7711145152918"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p7711145152918"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p671116522914"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p671116522914"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1771116572910"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1771116572910"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_row15462171542913"><td class="cellrowborder" valign="top" width="19.62%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p5522164215178"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p5522164215178"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p5522164215178"></a>component_count</p>
</td>
<td class="cellrowborder" valign="top" width="14.48%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p8522242101715"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p8522242101715"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p8522242101715"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p17522114220174"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p17522114220174"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p17522114220174"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1682695217315"><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1682695217315"></a><a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_p1682695217315"></a>返回组件的个数。</p>
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

## 约束说明<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table18698834121214"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row448192315595"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p16487237599"><a name="zh-cn_topic_0000002347924121_p16487237599"></a><a name="zh-cn_topic_0000002347924121_p16487237599"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p13109938611"><a name="zh-cn_topic_0000002347924121_p13109938611"></a><a name="zh-cn_topic_0000002347924121_p13109938611"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p415458133719"><a name="zh-cn_topic_0000002347924121_p415458133719"></a><a name="zh-cn_topic_0000002347924121_p415458133719"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1048823175917"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p1248192317591"><a name="zh-cn_topic_0000002347924121_p1248192317591"></a><a name="zh-cn_topic_0000002347924121_p1248192317591"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p1248323175919"><a name="zh-cn_topic_0000002347924121_p1248323175919"></a><a name="zh-cn_topic_0000002347924121_p1248323175919"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p310918317614"><a name="zh-cn_topic_0000002347924121_p310918317614"></a><a name="zh-cn_topic_0000002347924121_p310918317614"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p11481223195912"><a name="zh-cn_topic_0000002347924121_p11481223195912"></a><a name="zh-cn_topic_0000002347924121_p11481223195912"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1154788375"><a name="zh-cn_topic_0000002347924121_p1154788375"></a><a name="zh-cn_topic_0000002347924121_p1154788375"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row9482231597"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p1848423155919"><a name="zh-cn_topic_0000002347924121_p1848423155919"></a><a name="zh-cn_topic_0000002347924121_p1848423155919"></a><span id="zh-cn_topic_0000002347924121_ph134862385916"><a name="zh-cn_topic_0000002347924121_ph134862385916"></a><a name="zh-cn_topic_0000002347924121_ph134862385916"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13805429105911"><a name="zh-cn_topic_0000002347924121_p13805429105911"></a><a name="zh-cn_topic_0000002347924121_p13805429105911"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p648122375913"><a name="zh-cn_topic_0000002347924121_p648122375913"></a><a name="zh-cn_topic_0000002347924121_p648122375913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p196292595205"><a name="zh-cn_topic_0000002347924121_p196292595205"></a><a name="zh-cn_topic_0000002347924121_p196292595205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p68652310590"><a name="zh-cn_topic_0000002347924121_p68652310590"></a><a name="zh-cn_topic_0000002347924121_p68652310590"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p199521530104817"><a name="zh-cn_topic_0000002347924121_p199521530104817"></a><a name="zh-cn_topic_0000002347924121_p199521530104817"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row26831629307"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p12838193417015"><a name="zh-cn_topic_0000002347924121_p12838193417015"></a><a name="zh-cn_topic_0000002347924121_p12838193417015"></a><span id="zh-cn_topic_0000002347924121_ph1574975517015"><a name="zh-cn_topic_0000002347924121_ph1574975517015"></a><a name="zh-cn_topic_0000002347924121_ph1574975517015"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206467216_zh-cn_topic_0000001178373140_zh-cn_topic_0000001101617122_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
unsigned int component_count = 0;
ret = dcmiv2_get_device_component_cnt(dev_id, &component_count);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```
