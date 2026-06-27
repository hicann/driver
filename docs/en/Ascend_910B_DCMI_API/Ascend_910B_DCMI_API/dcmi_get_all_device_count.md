# dcmi\_get\_all\_device\_count<a name="EN-US_TOPIC_0000002515503874"></a>

**Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>**

**int dcmi\_get\_all\_device\_count\(int \*all\_device\_count\)**

**Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>**

Queries the number of Ascend AI processors that are successfully connected to PCIe of a host after the host is started.

**Parameter Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412079"></a>**

<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p14881939993"><a name="p14881939993"></a><a name="p14881939993"></a>all_device_count</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p1488203916913"><a name="p1488203916913"></a><a name="p1488203916913"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p18833919917"><a name="p18833919917"></a><a name="p18833919917"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p118820391193"><a name="p118820391193"></a><a name="p118820391193"></a>Number of queried devices.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b106855732685621"><a name="b106855732685621"></a><a name="b106855732685621"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

The installation and upgrade of the NPU firmware and driver must take effect before this API is called.

**Table  1** Support in different deployment scenarios

<a name="table1831828113412"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row19901425175211"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p1555917570362"><a name="en-us_topic_0000002515503852_p1555917570362"></a><a name="en-us_topic_0000002515503852_p1555917570362"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p201384912311"><a name="en-us_topic_0000002515503852_p201384912311"></a><a name="en-us_topic_0000002515503852_p201384912311"></a><strong id="en-us_topic_0000002515503852_b446915610411"><a name="en-us_topic_0000002515503852_b446915610411"></a><a name="en-us_topic_0000002515503852_b446915610411"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p513124915316"><a name="en-us_topic_0000002515503852_p513124915316"></a><a name="en-us_topic_0000002515503852_p513124915316"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b18560720419"><a name="en-us_topic_0000002515503852_b18560720419"></a><a name="en-us_topic_0000002515503852_b18560720419"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p1131549173112"><a name="en-us_topic_0000002515503852_p1131549173112"></a><a name="en-us_topic_0000002515503852_p1131549173112"></a><strong id="en-us_topic_0000002515503852_b14967981844"><a name="en-us_topic_0000002515503852_b14967981844"></a><a name="en-us_topic_0000002515503852_b14967981844"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p232525365317"><a name="en-us_topic_0000002515503852_p232525365317"></a><a name="en-us_topic_0000002515503852_p232525365317"></a><span id="en-us_topic_0000002515503852_ph3325165314533"><a name="en-us_topic_0000002515503852_ph3325165314533"></a><a name="en-us_topic_0000002515503852_ph3325165314533"></a><span id="en-us_topic_0000002515503852_text2032565316533"><a name="en-us_topic_0000002515503852_text2032565316533"></a><a name="en-us_topic_0000002515503852_text2032565316533"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p33251753135313"><a name="en-us_topic_0000002515503852_p33251753135313"></a><a name="en-us_topic_0000002515503852_p33251753135313"></a><span id="en-us_topic_0000002515503852_text232555315538"><a name="en-us_topic_0000002515503852_text232555315538"></a><a name="en-us_topic_0000002515503852_text232555315538"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p862174514211"><a name="en-us_topic_0000002515503852_p862174514211"></a><a name="en-us_topic_0000002515503852_p862174514211"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p12621104519215"><a name="en-us_topic_0000002515503852_p12621104519215"></a><a name="en-us_topic_0000002515503852_p12621104519215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p6621204519220"><a name="en-us_topic_0000002515503852_p6621204519220"></a><a name="en-us_topic_0000002515503852_p6621204519220"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row293019912529"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p532515315535"><a name="en-us_topic_0000002515503852_p532515315535"></a><a name="en-us_topic_0000002515503852_p532515315535"></a><span id="en-us_topic_0000002515503852_text732545315315"><a name="en-us_topic_0000002515503852_text732545315315"></a><a name="en-us_topic_0000002515503852_text732545315315"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p386884075314"><a name="en-us_topic_0000002515503852_p386884075314"></a><a name="en-us_topic_0000002515503852_p386884075314"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p12868184075310"><a name="en-us_topic_0000002515503852_p12868184075310"></a><a name="en-us_topic_0000002515503852_p12868184075310"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p986814025319"><a name="en-us_topic_0000002515503852_p986814025319"></a><a name="en-us_topic_0000002515503852_p986814025319"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row29531122175210"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1832516539533"><a name="en-us_topic_0000002515503852_p1832516539533"></a><a name="en-us_topic_0000002515503852_p1832516539533"></a><span id="en-us_topic_0000002515503852_text143251353185313"><a name="en-us_topic_0000002515503852_text143251353185313"></a><a name="en-us_topic_0000002515503852_text143251353185313"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16576467538"><a name="en-us_topic_0000002515503852_p16576467538"></a><a name="en-us_topic_0000002515503852_p16576467538"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13657346135315"><a name="en-us_topic_0000002515503852_p13657346135315"></a><a name="en-us_topic_0000002515503852_p13657346135315"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p10657164695315"><a name="en-us_topic_0000002515503852_p10657164695315"></a><a name="en-us_topic_0000002515503852_p10657164695315"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row2737141919528"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1632695317538"><a name="en-us_topic_0000002515503852_p1632695317538"></a><a name="en-us_topic_0000002515503852_p1632695317538"></a><span id="en-us_topic_0000002515503852_text532612537537"><a name="en-us_topic_0000002515503852_text532612537537"></a><a name="en-us_topic_0000002515503852_text532612537537"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1844654714531"><a name="en-us_topic_0000002515503852_p1844654714531"></a><a name="en-us_topic_0000002515503852_p1844654714531"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p64461747205318"><a name="en-us_topic_0000002515503852_p64461747205318"></a><a name="en-us_topic_0000002515503852_p64461747205318"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1446184725320"><a name="en-us_topic_0000002515503852_p1446184725320"></a><a name="en-us_topic_0000002515503852_p1446184725320"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row78171617135218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p3326853195318"><a name="en-us_topic_0000002515503852_p3326853195318"></a><a name="en-us_topic_0000002515503852_p3326853195318"></a><span id="en-us_topic_0000002515503852_text912513032714"><a name="en-us_topic_0000002515503852_text912513032714"></a><a name="en-us_topic_0000002515503852_text912513032714"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p2967114725312"><a name="en-us_topic_0000002515503852_p2967114725312"></a><a name="en-us_topic_0000002515503852_p2967114725312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1396754795312"><a name="en-us_topic_0000002515503852_p1396754795312"></a><a name="en-us_topic_0000002515503852_p1396754795312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p596734725316"><a name="en-us_topic_0000002515503852_p596734725316"></a><a name="en-us_topic_0000002515503852_p596734725316"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1913121595213"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p532613533533"><a name="en-us_topic_0000002515503852_p532613533533"></a><a name="en-us_topic_0000002515503852_p532613533533"></a><span id="en-us_topic_0000002515503852_text332611538530"><a name="en-us_topic_0000002515503852_text332611538530"></a><a name="en-us_topic_0000002515503852_text332611538530"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1452484814533"><a name="en-us_topic_0000002515503852_p1452484814533"></a><a name="en-us_topic_0000002515503852_p1452484814533"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p19524174835320"><a name="en-us_topic_0000002515503852_p19524174835320"></a><a name="en-us_topic_0000002515503852_p19524174835320"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652419482532"><a name="en-us_topic_0000002515503852_p652419482532"></a><a name="en-us_topic_0000002515503852_p652419482532"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row71831758163218"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p28486114331"><a name="en-us_topic_0000002515503852_p28486114331"></a><a name="en-us_topic_0000002515503852_p28486114331"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>**

```C
int ret = 0;
int all_device_count;
ret = dcmi_get_all_device_count(&all_device_count);
if(ret != 0) {
    //todo
    return ret;
}
...
```
