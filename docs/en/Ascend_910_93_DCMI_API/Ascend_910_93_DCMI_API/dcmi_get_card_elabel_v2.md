# dcmi\_get\_card\_elabel\_v2<a name="EN-US_TOPIC_0000002546990463"></a>

**Prototype<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_toc533412077"></a>**

**int dcmi\_get\_card\_elabel\_v2\(int card\_id, struct dcmi\_elabel\_info \*elabel\_info\)**

**Description<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_toc533412078"></a>**

Obtains the electronic label information of an NPU device.

**Parameter Description<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_toc533412079"></a>**

<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p10021890"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p10021890"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p6466753"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p6466753"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p54045009"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p54045009"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p15569626"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p15569626"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36741947142813"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36741947142813"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p96741747122818"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p96741747122818"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p46747472287"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p46747472287"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1467413474281"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1467413474281"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b141092068033121"><a name="b141092068033121"></a><a name="b141092068033121"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36921291519"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36921291519"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p36921291519"></a>elabel_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p2692329056"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p2692329056"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p2692329056"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p116921929858"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p116921929858"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p116921929858"></a>struct dcmi_elabel_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p156920291951"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p156920291951"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p156920291951"></a>#define MAX_LENTH 256</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p175344116380"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p175344116380"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p175344116380"></a>struct dcmi_elabel_info {</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p853420133810"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p853420133810"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p853420133810"></a>char product_name[MAX_LENTH]; // Product name</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p95341216380"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p95341216380"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p95341216380"></a>char model[MAX_LENTH]; // Product model</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p85343143813"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p85343143813"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p85343143813"></a>char manufacturer[MAX_LENTH]; // Manufacturer</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953412123810"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953412123810"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953412123810"></a>char manufacturer_date[MAX_LENTH]; // Production date</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p135341414381"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p135341414381"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p135341414381"></a>char serial_number[MAX_LENTH]; // Product serial number</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953417114381"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953417114381"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1953417114381"></a>};</p>
<p id="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1129264019172"><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1129264019172"></a><a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_p1129264019172"></a><strong id="b18376456881647"><a name="b18376456881647"></a><a name="b18376456881647"></a>manufacturer_date</strong> is a reserved field and is invalid currently.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b34656885872225"><a name="b34656885872225"></a><a name="b34656885872225"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251107217_en-us_topic_0000001178373154_en-us_topic_0000001160801035_toc533412083"></a>**

```c
... 
struct dcmi_elabel_info elabelInfo;
int ret = 0;
int card_id = 0;
memset(&elabelInfo, 0, sizeof(elabelInfo));
ret = dcmi_get_card_elabel_v2(card_id, &elabelInfo);
if (ret != 0) {
    // todo: Record logs.
    return ERROR;
}
...
```
