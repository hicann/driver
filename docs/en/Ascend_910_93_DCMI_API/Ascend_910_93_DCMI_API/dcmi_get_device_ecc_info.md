# dcmi\_get\_device\_ecc\_info<a name="EN-US_TOPIC_0000002546990381"></a>

**Prototype<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412077"></a>**

**int dcmi\_get\_device\_ecc\_info\(int card\_id, int device\_id, enum dcmi\_device\_type input\_type, struct dcmi\_ecc\_info \*device\_ecc\_info\)**

**Description<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412078"></a>**

Obtains the ECC information.

**Parameter Description<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412079"></a>**

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
<tbody><tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p36741947142813"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p36741947142813"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p96741747122818"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p96741747122818"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p46747472287"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p46747472287"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1467413474281"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1467413474281"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1928614232319"><a name="b1928614232319"></a><a name="b1928614232319"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b9442144342313"><a name="b9442144342313"></a><a name="b9442144342313"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b21222083496147"><a name="b21222083496147"></a><a name="b21222083496147"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p237363715296"></a>device_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837312378299"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p637373712920"></a>enum dcmi_device_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p1837317370296"></a>Components:</p>
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
<p id="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"></a><a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_p6300629155519"></a>If the value of <strong id="b37314472410"><a name="b37314472410"></a><a name="b37314472410"></a>enable_flag</strong> is <strong id="b7741044122420"><a name="b7741044122420"></a><a name="b7741044122420"></a>0</strong>, ECC detection is disabled. If the value of <strong id="b1874124417245"><a name="b1874124417245"></a><a name="b1874124417245"></a>enable_flag</strong> is <strong id="b157415449247"><a name="b157415449247"></a><a name="b157415449247"></a>1</strong>, ECC detection is enabled.</p>
<div class="note" id="note82336295217"><a name="note82336295217"></a><a name="note82336295217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul145976102198"></a><a name="ul145976102198"></a><ul id="ul145976102198"><li>Currently, single-bit and multi-bit errors can be queried. If a multi-bit error is found, locate and rectify the fault.</li><li>This API obtains real-time data. After the system is restarted, the number of single-bit errors and the number of double-bit errors are cleared.</li><li><strong id="b1822213182617"><a name="b1822213182617"></a><a name="b1822213182617"></a>single_bit_isolated_pages_cnt</strong> is a reserved parameter and is currently not used. Its value is set to <strong id="b277391132612"><a name="b277391132612"></a><a name="b277391132612"></a>0</strong>.</li></ul>
</div></div>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b27737756672131"><a name="b27737756672131"></a><a name="b27737756672131"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251427189_en-us_topic_0000001223414429_en-us_topic_0000001147924553_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 1;
int device_id = 0;
struct dcmi_ecc_info device_ecc_info = {0};
ret = dcmi_get_device_ecc_info(card_id, device_id, DCMI_DEVICE_TYPE_DDR, &device_ecc_info);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```
