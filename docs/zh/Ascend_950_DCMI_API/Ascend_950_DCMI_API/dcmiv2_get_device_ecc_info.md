# dcmiv2\_get\_device\_ecc\_info<a name="ZH-CN_TOPIC_0000002314204866"></a>

## 函数原型<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_toc533412077"></a>

**int dcmiv2\_get\_device\_ecc\_info\(int dev\_id, enum dcmi\_device\_type input\_type, struct dcmi\_ecc\_info \*device\_ecc\_info\)**

## 功能说明<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_toc533412078"></a>

获取ECC信息。

## 参数说明<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_toc533412079"></a>

<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p10021890"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p10021890"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6466753"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6466753"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p54045009"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p54045009"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p15569626"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p15569626"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p7711145152918"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p7711145152918"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p671116522914"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p671116522914"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1771116572910"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1771116572910"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p237363715296"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p237363715296"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p237363715296"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837312378299"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837312378299"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837312378299"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p637373712920"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p637373712920"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p637373712920"></a>enum dcmi_device_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837317370296"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837317370296"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1837317370296"></a>组件类型。</p>
<p id="p36503314442"><a name="p36503314442"></a><a name="p36503314442"></a>enum dcmi_device_type {</p>
<p id="p14651233204415"><a name="p14651233204415"></a><a name="p14651233204415"></a>DCMI_DEVICE_TYPE_DDR,</p>
<p id="p176511336449"><a name="p176511336449"></a><a name="p176511336449"></a>DCMI_DEVICE_TYPE_SRAM,</p>
<p id="p36583324415"><a name="p36583324415"></a><a name="p36583324415"></a>DCMI_DEVICE_TYPE_HBM,</p>
<p id="p186573334416"><a name="p186573334416"></a><a name="p186573334416"></a>DCMI_DEVICE_TYPE_NPU,</p>
<p id="p065113334417"><a name="p065113334417"></a><a name="p065113334417"></a>DCMI_HBM_RECORDED_SINGLE_ADDR,</p>
<p id="p86513338448"><a name="p86513338448"></a><a name="p86513338448"></a>DCMI_HBM_RECORDED_MULTI_ADDR,</p>
<p id="p1065173364414"><a name="p1065173364414"></a><a name="p1065173364414"></a>DCMI_DEVICE_TYPE_NONE = 0xff</p>
<p id="p1165133174413"><a name="p1165133174413"></a><a name="p1165133174413"></a>};</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p795817279399"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p795817279399"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p795817279399"></a>仅支持DCMI_DEVICE_TYPE_HBM //片上内存类型内存。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_row1019163316298"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p53731537152910"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p53731537152910"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p53731537152910"></a>device_ecc_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p163731137102919"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p163731137102919"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p163731137102919"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p037353718298"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p037353718298"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p037353718298"></a>struct dcmi_ecc_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p193731837202917"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p193731837202917"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p193731837202917"></a>返回ECC结构体信息：</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917537103018"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917537103018"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917537103018"></a>struct dcmi_ecc_info {</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1691723712309"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1691723712309"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1691723712309"></a>int enable_flag;</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p991753720308"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p991753720308"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p991753720308"></a>unsigned int single_bit_error_cnt; //单比特错误数量</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1591710377309"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1591710377309"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1591710377309"></a>unsigned int double_bit_error_cnt; //多比特错误数量</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p791718375301"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p791718375301"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p791718375301"></a>unsigned int total_single_bit_error_cnt; //生命周期内所有单比特ECC错误统计</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917337123010"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917337123010"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p5917337123010"></a>unsigned int total_double_bit_error_cnt; //生命周期内所有多比特ECC错误统计</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p491713733013"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p491713733013"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p491713733013"></a>unsigned int single_bit_isolated_pages_cnt; //单比特错误隔离内存页数量</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1291712371309"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1291712371309"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p1291712371309"></a>unsigned int double_bit_isolated_pages_cnt; //多比特错误隔离内存页数量</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p691743733013"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p691743733013"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p691743733013"></a>};</p>
<p id="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6300629155519"><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6300629155519"></a><a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_p6300629155519"></a>其中，enable_flag输出0，表示ECC检测未启用；enable_flag输出1，表示ECC检测启用。</p>
<div class="note" id="note82336295217"><a name="note82336295217"></a><a name="note82336295217"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul145976102198"></a><a name="ul145976102198"></a><ul id="ul145976102198"><li>当前支持单比特和多比特错误查询，如果查询到多比特错误，需要进行相关问题定位和处理。</li><li>该接口获取的是实时的数据，系统重启之后单比特错误数量和多比特错误数量清零。</li><li>single_bit_isolated_pages_cnt为预留参数，暂不使用，固定输出0。</li></ul>
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

## 约束说明<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001251427189_zh-cn_topic_0000001223414429_zh-cn_topic_0000001147924553_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
struct dcmi_ecc_info device_ecc_info = {0};
ret = dcmiv2_get_device_ecc_info(dev_id, DCMI_DEVICE_TYPE_HBM, &device_ecc_info);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```
