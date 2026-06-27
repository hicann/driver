# dcmiv2\_get\_device\_ecc\_info<a name="EN-US_TOPIC_0000002314204866"></a>

## Prototype<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412077"></a>

**int dcmiv2\_get\_device\_ecc\_info\(int dev\_id, enum dcmi\_device\_type input\_type, struct dcmi\_ecc\_info \*device\_ecc\_info\)**

## Description<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412078"></a>

Obtains the ECC information.

## Parameter Description<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412079"></a>

<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p10021890"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p10021890"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6466753"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6466753"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p54045009"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p54045009"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p15569626"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p15569626"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"></a>enum dcmi_device_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"></a>Component type.</p>
<p id="p36503314442"><a name="p36503314442"></a><a name="p36503314442"></a>enum dcmi_device_type {</p>
<p id="p14651233204415"><a name="p14651233204415"></a><a name="p14651233204415"></a>DCMI_DEVICE_TYPE_DDR,</p>
<p id="p176511336449"><a name="p176511336449"></a><a name="p176511336449"></a>DCMI_DEVICE_TYPE_SRAM,</p>
<p id="p36583324415"><a name="p36583324415"></a><a name="p36583324415"></a>DCMI_DEVICE_TYPE_HBM,</p>
<p id="p186573334416"><a name="p186573334416"></a><a name="p186573334416"></a>DCMI_DEVICE_TYPE_NPU,</p>
<p id="p065113334417"><a name="p065113334417"></a><a name="p065113334417"></a>DCMI_HBM_RECORDED_SINGLE_ADDR,</p>
<p id="p86513338448"><a name="p86513338448"></a><a name="p86513338448"></a>DCMI_HBM_RECORDED_MULTI_ADDR,</p>
<p id="p1065173364414"><a name="p1065173364414"></a><a name="p1065173364414"></a>DCMI_DEVICE_TYPE_NONE = 0xff</p>
<p id="p1165133174413"><a name="p1165133174413"></a><a name="p1165133174413"></a>};</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p795817279399"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p795817279399"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p795817279399"></a>Only <strong id="b1544412014245"><a name="b1544412014245"></a><a name="b1544412014245"></a>DCMI_DEVICE_TYPE_HBM</strong> (on-chip memory) is supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row1019163316298"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p53731537152910"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p53731537152910"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p53731537152910"></a>device_ecc_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p163731137102919"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p163731137102919"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p163731137102919"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p037353718298"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p037353718298"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p037353718298"></a>struct dcmi_ecc_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p193731837202917"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p193731837202917"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p193731837202917"></a>ECC information structure.</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917537103018"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917537103018"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917537103018"></a>struct dcmi_ecc_info {</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1691723712309"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1691723712309"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1691723712309"></a>int enable_flag;</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p991753720308"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p991753720308"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p991753720308"></a>unsigned int single_bit_error_cnt; // Number of single-bit errors</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1591710377309"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1591710377309"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1591710377309"></a>unsigned int double_bit_error_cnt; // Number of double-bit errors</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p791718375301"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p791718375301"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p791718375301"></a>unsigned int total_single_bit_error_cnt; // Count of all single-bit ECC errors in the lifecycle</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917337123010"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917337123010"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p5917337123010"></a>unsigned int total_double_bit_error_cnt; // Count of all double-bit ECC errors in the lifecycle</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p491713733013"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p491713733013"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p491713733013"></a>unsigned int single_bit_isolated_pages_cnt; // Number of isolated memory pages with single-bit errors</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1291712371309"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1291712371309"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1291712371309"></a>unsigned int double_bit_isolated_pages_cnt; // Number of isolated memory pages with double-bit errors</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p691743733013"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p691743733013"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p691743733013"></a>};</p>
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"></a>If the value of <strong id="b67581546127"><a name="b67581546127"></a><a name="b67581546127"></a>enable_flag</strong> is <strong id="b87591442123"><a name="b87591442123"></a><a name="b87591442123"></a>0</strong>, ECC detection is disabled. If the value of <strong id="b14759349122"><a name="b14759349122"></a><a name="b14759349122"></a>enable_flag</strong> is <strong id="b13759144141210"><a name="b13759144141210"></a><a name="b13759144141210"></a>1</strong>, ECC detection is enabled.</p>
<div class="note" id="note82336295217"><a name="note82336295217"></a><a name="note82336295217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul145976102198"></a><a name="ul145976102198"></a><ul id="ul145976102198"><li>Currently, single-bit and multi-bit errors can be queried. If a multi-bit error is found, locate and rectify the fault.</li><li>This API obtains real-time data. After the system is restarted, the number of single-bit errors and the number of double-bit errors are cleared.</li><li><strong id="b578841819109"><a name="b578841819109"></a><a name="b578841819109"></a>single_bit_isolated_pages_cnt</strong> is a reserved parameter and is currently not used. Its value is set to <strong id="b67897183108"><a name="b67897183108"></a><a name="b67897183108"></a>0</strong>.</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412082"></a>

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

## Example<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_ecc_info device_ecc_info = {0};
ret = dcmiv2_get_device_ecc_info(dev_id, DCMI_DEVICE_TYPE_HBM, &device_ecc_info);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```
