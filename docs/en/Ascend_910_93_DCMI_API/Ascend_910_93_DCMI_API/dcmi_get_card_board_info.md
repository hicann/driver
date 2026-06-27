# dcmi\_get\_card\_board\_info<a name="EN-US_TOPIC_0000002546990403"></a>

**Prototype<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_toc533412077"></a>**

**int dcmi\_get\_card\_board\_info\(int card\_id, struct dcmi\_board\_info \*board\_info\)**

**Description<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_toc533412078"></a>**

Obtains the board information of a device, including  **board\_id**,  **pcb\_id**,  **bom\_id**, and  **slot\_id**.

**Parameter Description<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_toc533412079"></a>**

<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_row7580267"><th class="cellrowborder" valign="top" width="17.080000000000002%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10021890"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10021890"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="14.940000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p6466753"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p6466753"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p54045009"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p54045009"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15569626"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15569626"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_row10560021192510"><td class="cellrowborder" valign="top" width="17.080000000000002%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p36741947142813"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p36741947142813"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.940000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p96741747122818"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p96741747122818"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p46747472287"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p46747472287"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1467413474281"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1467413474281"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b181735052210"><a name="b181735052210"></a><a name="b181735052210"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_row15462171542913"><td class="cellrowborder" valign="top" width="17.080000000000002%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p5262129152913"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p5262129152913"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p5262129152913"></a>board_info</p>
</td>
<td class="cellrowborder" valign="top" width="14.940000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1926232982914"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1926232982914"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1926232982914"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p826217292293"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p826217292293"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p826217292293"></a>struct dcmi_board_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1018413955820"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1018413955820"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p1018413955820"></a>Board information.</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4277628131212"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4277628131212"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4277628131212"></a>struct dcmi_board_info {</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15278192819129"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15278192819129"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p15278192819129"></a>unsigned int board_id; // Board ID</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10278132811210"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10278132811210"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10278132811210"></a>unsigned int pcb_id; // PCB version number</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p027892871214"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p027892871214"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p027892871214"></a>unsigned int bom_id; // BOM ID</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4278112810127"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4278112810127"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p4278112810127"></a>unsigned int slot_id; // Slot ID</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p72781328141211"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p72781328141211"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p72781328141211"></a>};</p>
<p id="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10375134534117"><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10375134534117"></a><a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_p10375134534117"></a><strong id="b255253763812"><a name="b255253763812"></a><a name="b255253763812"></a>pcb_id</strong> and <strong id="b19571143913817"><a name="b19571143913817"></a><a name="b19571143913817"></a>bom_id</strong> are invalid, but <strong id="b141171142193818"><a name="b141171142193818"></a><a name="b141171142193818"></a>slot_id</strong> is valid.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b191575945472229"><a name="b191575945472229"></a><a name="b191575945472229"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001206147262_en-us_topic_0000001177894706_en-us_topic_0000001102110956_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
struct dcmi_board_info board_info = {0};
ret = dcmi_get_card_board_info(card_id, &board_info);
...
```
