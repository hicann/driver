# dcmiv2\_clear\_device\_ecc\_stats\_info<a name="ZH-CN_TOPIC_0000002347924101"></a>

## 函数原型<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_toc533412077"></a>

**int dcmiv2\_clear\_device\_ecc\_stats\_info\(int dev\_id\)**

## 功能说明<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_toc533412078"></a>

清除ECC统计信息。

## 参数说明<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_toc533412079"></a>

<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p10021890"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p10021890"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p6466753"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p6466753"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p54045009"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p54045009"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p15569626"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p15569626"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p7711145152918"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p7711145152918"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p671116522914"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p671116522914"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p1771116572910"><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p1771116572910"></a><a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
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

## 约束说明<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_toc533412082"></a>

>**须知：** 
>该接口会导致需要隔离的片上内存多bit ECC故障地址被清除，故障地址冷隔离失效，具有较高风险，请谨慎使用。

**表 1** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
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

## 调用示例<a name="zh-cn_topic_0000001251427219_zh-cn_topic_0000001223292893_zh-cn_topic_0000001147926213_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
ret = dcmiv2_clear_device_ecc_stats_info(dev_id);
if (ret != 0) {
    //todo：记录日志
    return ret;
}
…
```
