# dcmi\_get\_npu\_work\_mode<a name="EN-US_TOPIC_0000002546910371"></a>

**Prototype<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_toc533412077"></a>**

**int dcmi\_get\_npu\_work\_mode\(int card\_id, unsigned char \*work\_mode\)**

**Description<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_toc533412078"></a>**

Queries the NPU working mode.

**Parameter Description<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_toc533412079"></a>**

<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p10021890"><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p10021890"></a><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p6466753"><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p6466753"></a><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p54045009"><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p54045009"></a><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p15569626"><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p15569626"></a><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001533089933_p1036956104919"><a name="en-us_topic_0000001533089933_p1036956104919"></a><a name="en-us_topic_0000001533089933_p1036956104919"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001533089933_p13301734154916"><a name="en-us_topic_0000001533089933_p13301734154916"></a><a name="en-us_topic_0000001533089933_p13301734154916"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p46747472287"><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p46747472287"></a><a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001533089933_p148501928125417"><a name="en-us_topic_0000001533089933_p148501928125417"></a><a name="en-us_topic_0000001533089933_p148501928125417"></a>Device ID. The supported IDs can be obtained by calling <strong id="b125930615233016"><a name="b125930615233016"></a><a name="b125930615233016"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001533089933_row228185634814"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001533089933_p928145616483"><a name="en-us_topic_0000001533089933_p928145616483"></a><a name="en-us_topic_0000001533089933_p928145616483"></a>work_mode</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001533089933_p132810566489"><a name="en-us_topic_0000001533089933_p132810566489"></a><a name="en-us_topic_0000001533089933_p132810566489"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001533089933_p16329935165317"><a name="en-us_topic_0000001533089933_p16329935165317"></a><a name="en-us_topic_0000001533089933_p16329935165317"></a>unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001533089933_p176001917161010"><a name="en-us_topic_0000001533089933_p176001917161010"></a><a name="en-us_topic_0000001533089933_p176001917161010"></a>NPU working mode. The output is <strong id="b7598919688731"><a name="b7598919688731"></a><a name="b7598919688731"></a>0</strong> or <strong id="b15935776258731"><a name="b15935776258731"></a><a name="b15935776258731"></a>1</strong>.</p>
<a name="en-us_topic_0000001533089933_ul5532104444715"></a><a name="en-us_topic_0000001533089933_ul5532104444715"></a><ul id="en-us_topic_0000001533089933_ul5532104444715"><li><strong id="b9515118928731"><a name="b9515118928731"></a><a name="b9515118928731"></a>0</strong>: AMP</li><li><strong id="b4037755908731"><a name="b4037755908731"></a><a name="b4037755908731"></a>1</strong>: SMP</li></ul>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b97003309772250"><a name="b97003309772250"></a><a name="b97003309772250"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p114288580415"><a name="en-us_topic_0000002515350556_p114288580415"></a><a name="en-us_topic_0000002515350556_p114288580415"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_row19216056194814"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><span id="en-us_topic_0000002515350556_text1564782665814"><a name="en-us_topic_0000002515350556_text1564782665814"></a><a name="en-us_topic_0000002515350556_text1564782665814"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><span id="en-us_topic_0000002515350556_text1123515513517"><a name="en-us_topic_0000002515350556_text1123515513517"></a><a name="en-us_topic_0000002515350556_text1123515513517"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row12693311552"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p17872181618166"><a name="en-us_topic_0000002515350556_p17872181618166"></a><a name="en-us_topic_0000002515350556_p17872181618166"></a><span id="en-us_topic_0000002515350556_text17872121641614"><a name="en-us_topic_0000002515350556_text17872121641614"></a><a name="en-us_topic_0000002515350556_text17872121641614"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p177521042115520"><a name="en-us_topic_0000002515350556_p177521042115520"></a><a name="en-us_topic_0000002515350556_p177521042115520"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12752114215559"><a name="en-us_topic_0000002515350556_p12752114215559"></a><a name="en-us_topic_0000002515350556_p12752114215559"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p18752104275512"><a name="en-us_topic_0000002515350556_p18752104275512"></a><a name="en-us_topic_0000002515350556_p18752104275512"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row179407221298"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p696322918294"><a name="en-us_topic_0000002515350556_p696322918294"></a><a name="en-us_topic_0000002515350556_p696322918294"></a><span id="en-us_topic_0000002515350556_text15963162972914"><a name="en-us_topic_0000002515350556_text15963162972914"></a><a name="en-us_topic_0000002515350556_text15963162972914"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1560813335296"><a name="en-us_topic_0000002515350556_p1560813335296"></a><a name="en-us_topic_0000002515350556_p1560813335296"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p260873392918"><a name="en-us_topic_0000002515350556_p260873392918"></a><a name="en-us_topic_0000002515350556_p260873392918"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p5608333162914"><a name="en-us_topic_0000002515350556_p5608333162914"></a><a name="en-us_topic_0000002515350556_p5608333162914"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19346183355516"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p0905133713551"><a name="en-us_topic_0000002515350556_p0905133713551"></a><a name="en-us_topic_0000002515350556_p0905133713551"></a><span id="en-us_topic_0000002515350556_text1190563775520"><a name="en-us_topic_0000002515350556_text1190563775520"></a><a name="en-us_topic_0000002515350556_text1190563775520"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p7204194395516"><a name="en-us_topic_0000002515350556_p7204194395516"></a><a name="en-us_topic_0000002515350556_p7204194395516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p13205104310553"><a name="en-us_topic_0000002515350556_p13205104310553"></a><a name="en-us_topic_0000002515350556_p13205104310553"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32051943125519"><a name="en-us_topic_0000002515350556_p32051943125519"></a><a name="en-us_topic_0000002515350556_p32051943125519"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1158213431480"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p65418471681"><a name="en-us_topic_0000002515350556_p65418471681"></a><a name="en-us_topic_0000002515350556_p65418471681"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001533089933_en-us_topic_0000001277289337_en-us_topic_0000001178213212_en-us_topic_0000001167998163_toc533412083"></a>**

```c
...
int card_id;
unsigned char *work_mode; 
ret= dcmi_get_npu_work_mode(&work_mode); 
if (ret != 0){ 
    // todo: Record logs.
    return ret; 
} 
...
```
