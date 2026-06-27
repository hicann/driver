# dcmi\_sm\_encrypt<a name="EN-US_TOPIC_0000002515343842"></a>

**Prototype<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412077"></a>**

**int dcmi\_sm\_encrypt\(int card\_id, int device\_id, struct dcmi\_sm\_parm\* parm, struct dcmi\_sm\_data \*data\)**

**Description<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412078"></a>**

Obtains the encrypted ciphertext by calling this API and entering the plaintext to be encrypted, the encryption key, and the Chinese encryption algorithm type.

**Parameter Description<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412079"></a>**

<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.97%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.97%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1879235000102827"><a name="b1879235000102827"></a><a name="b1879235000102827"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.97%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1329592036102459"><a name="b1329592036102459"></a><a name="b1329592036102459"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b248423554105345"><a name="b248423554105345"></a><a name="b248423554105345"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p9315182755815"><a name="p9315182755815"></a><a name="p9315182755815"></a>parm</p>
</td>
<td class="cellrowborder" valign="top" width="16.97%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a>struct dcmi_sm_parm*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p12792271415"><a name="p12792271415"></a><a name="p12792271415"></a>struct sm_parm {</p>
<p id="p158072713117"><a name="p158072713117"></a><a name="p158072713117"></a>unsigned int key_type;</p>
<p id="p3809271110"><a name="p3809271110"></a><a name="p3809271110"></a>unsigned int key_len;// The length of the SM4 key is 16 bytes. SM3 is not involved.</p>
<p id="p98011278111"><a name="p98011278111"></a><a name="p98011278111"></a>unsigned int iv_len;// The initial length of SM4 is 16 bytes. SM3 is not involved.</p>
<p id="p880132711119"><a name="p880132711119"></a><a name="p880132711119"></a>unsigned int reserves;// Reserved</p>
<p id="p188042716114"><a name="p188042716114"></a><a name="p188042716114"></a>unsigned char iv[64]; // Initialization vector of the CBC algorithm</p>
<p id="p4806275111"><a name="p4806275111"></a><a name="p4806275111"></a>unsigned char key[512]; // Key</p>
<p id="p18801727611"><a name="p18801727611"></a><a name="p18801727611"></a>unsigned char reserved[512];// Reserved</p>
<p id="p168017271816"><a name="p168017271816"></a><a name="p168017271816"></a>};</p>
<p id="p168013271617"><a name="p168013271617"></a><a name="p168013271617"></a>The arguments of <strong id="b2070712341783"><a name="b2070712341783"></a><a name="b2070712341783"></a>key_type</strong> are as follows:</p>
<p id="p1804276118"><a name="p1804276118"></a><a name="p1804276118"></a>enum sm_key_type{</p>
<p id="p9673123415610"><a name="p9673123415610"></a><a name="p9673123415610"></a>SM3_NORMAL_SUMMARY = 0, // SM3 hash algorithm</p>
<p id="p11673153485616"><a name="p11673153485616"></a><a name="p11673153485616"></a>SM4_CBC_ENCRYPT = 1, // SM4 CBC encryption algorithm</p>
<p id="p1667393414568"><a name="p1667393414568"></a><a name="p1667393414568"></a>SM4_CBC_DECRYPT = 2,[x(1] // SM4 CBC decryption algorithm</p>
<p id="p1580182710111"><a name="p1580182710111"></a><a name="p1580182710111"></a>};</p>
</td>
</tr>
<tr id="row15244163135814"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p32445315586"><a name="p32445315586"></a><a name="p32445315586"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.97%" headers="mcps1.1.5.1.2 "><p id="p15244731115812"><a name="p15244731115812"></a><a name="p15244731115812"></a>Input; output</p>
</td>
<td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.3 "><p id="p17244731155814"><a name="p17244731155814"></a><a name="p17244731155814"></a>struct dcmi_sm_data *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1801527219"><a name="p1801527219"></a><a name="p1801527219"></a>struct sm_data {</p>
<p id="p78010271212"><a name="p78010271212"></a><a name="p78010271212"></a>const unsigned char *in_buf;</p>
<p id="p19803271713"><a name="p19803271713"></a><a name="p19803271713"></a>unsigned in_len;// The SM3/SM4 length cannot exceed 3072 bytes, and the SM4 length must be an integer multiple of 16 bytes.</p>
<p id="p48221628153511"><a name="p48221628153511"></a><a name="p48221628153511"></a>unsigned char *out_buf; // Output buffer</p>
<p id="p16869334123513"><a name="p16869334123513"></a><a name="p16869334123513"></a>unsigned int *out_len; // Output buffer length</p>
<p id="p88012277115"><a name="p88012277115"></a><a name="p88012277115"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b93003262485617"><a name="b93003262485617"></a><a name="b93003262485617"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1993685321815"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1210513304816"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p558011817325"><a name="en-us_topic_0000002515503852_p558011817325"></a><a name="en-us_topic_0000002515503852_p558011817325"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p25806812321"><a name="en-us_topic_0000002515503852_p25806812321"></a><a name="en-us_topic_0000002515503852_p25806812321"></a><strong id="en-us_topic_0000002515503852_b156561347844"><a name="en-us_topic_0000002515503852_b156561347844"></a><a name="en-us_topic_0000002515503852_b156561347844"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p558018833211"><a name="en-us_topic_0000002515503852_p558018833211"></a><a name="en-us_topic_0000002515503852_p558018833211"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b686519481414"><a name="en-us_topic_0000002515503852_b686519481414"></a><a name="en-us_topic_0000002515503852_b686519481414"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p35801189326"><a name="en-us_topic_0000002515503852_p35801189326"></a><a name="en-us_topic_0000002515503852_p35801189326"></a><strong id="en-us_topic_0000002515503852_b398912494411"><a name="en-us_topic_0000002515503852_b398912494411"></a><a name="en-us_topic_0000002515503852_b398912494411"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row14576182015105"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13661881916"><a name="en-us_topic_0000002515503852_p13661881916"></a><a name="en-us_topic_0000002515503852_p13661881916"></a><span id="en-us_topic_0000002515503852_ph116612081298"><a name="en-us_topic_0000002515503852_ph116612081298"></a><a name="en-us_topic_0000002515503852_ph116612081298"></a><span id="en-us_topic_0000002515503852_text26611487916"><a name="en-us_topic_0000002515503852_text26611487916"></a><a name="en-us_topic_0000002515503852_text26611487916"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p057642081019"><a name="en-us_topic_0000002515503852_p057642081019"></a><a name="en-us_topic_0000002515503852_p057642081019"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p65761200102"><a name="en-us_topic_0000002515503852_p65761200102"></a><a name="en-us_topic_0000002515503852_p65761200102"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1357610206101"><a name="en-us_topic_0000002515503852_p1357610206101"></a><a name="en-us_topic_0000002515503852_p1357610206101"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row318512127818"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611581596"><a name="en-us_topic_0000002515503852_p86611581596"></a><a name="en-us_topic_0000002515503852_p86611581596"></a><span id="en-us_topic_0000002515503852_text66619818911"><a name="en-us_topic_0000002515503852_text66619818911"></a><a name="en-us_topic_0000002515503852_text66619818911"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1441443298"><a name="en-us_topic_0000002515503852_p1441443298"></a><a name="en-us_topic_0000002515503852_p1441443298"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2420631892"><a name="en-us_topic_0000002515503852_p2420631892"></a><a name="en-us_topic_0000002515503852_p2420631892"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18425123899"><a name="en-us_topic_0000002515503852_p18425123899"></a><a name="en-us_topic_0000002515503852_p18425123899"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1273713241084"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p56611781094"><a name="en-us_topic_0000002515503852_p56611781094"></a><a name="en-us_topic_0000002515503852_p56611781094"></a><span id="en-us_topic_0000002515503852_text56611281693"><a name="en-us_topic_0000002515503852_text56611281693"></a><a name="en-us_topic_0000002515503852_text56611281693"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p64311736915"><a name="en-us_topic_0000002515503852_p64311736915"></a><a name="en-us_topic_0000002515503852_p64311736915"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p04391434914"><a name="en-us_topic_0000002515503852_p04391434914"></a><a name="en-us_topic_0000002515503852_p04391434914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p244917315919"><a name="en-us_topic_0000002515503852_p244917315919"></a><a name="en-us_topic_0000002515503852_p244917315919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7672192219815"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p166611689914"><a name="en-us_topic_0000002515503852_p166611689914"></a><a name="en-us_topic_0000002515503852_p166611689914"></a><span id="en-us_topic_0000002515503852_text126611581798"><a name="en-us_topic_0000002515503852_text126611581798"></a><a name="en-us_topic_0000002515503852_text126611581798"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p12459143996"><a name="en-us_topic_0000002515503852_p12459143996"></a><a name="en-us_topic_0000002515503852_p12459143996"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10470531895"><a name="en-us_topic_0000002515503852_p10470531895"></a><a name="en-us_topic_0000002515503852_p10470531895"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12476033912"><a name="en-us_topic_0000002515503852_p12476033912"></a><a name="en-us_topic_0000002515503852_p12476033912"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row153452020881"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611181098"><a name="en-us_topic_0000002515503852_p86611181098"></a><a name="en-us_topic_0000002515503852_p86611181098"></a><span id="en-us_topic_0000002515503852_text16611819911"><a name="en-us_topic_0000002515503852_text16611819911"></a><a name="en-us_topic_0000002515503852_text16611819911"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134813311917"><a name="en-us_topic_0000002515503852_p134813311917"></a><a name="en-us_topic_0000002515503852_p134813311917"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3486231596"><a name="en-us_topic_0000002515503852_p3486231596"></a><a name="en-us_topic_0000002515503852_p3486231596"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p44911135913"><a name="en-us_topic_0000002515503852_p44911135913"></a><a name="en-us_topic_0000002515503852_p44911135913"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row20496217988"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611689916"><a name="en-us_topic_0000002515503852_p86611689916"></a><a name="en-us_topic_0000002515503852_p86611689916"></a><span id="en-us_topic_0000002515503852_text105131140182910"><a name="en-us_topic_0000002515503852_text105131140182910"></a><a name="en-us_topic_0000002515503852_text105131140182910"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p649613392"><a name="en-us_topic_0000002515503852_p649613392"></a><a name="en-us_topic_0000002515503852_p649613392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2050114313914"><a name="en-us_topic_0000002515503852_p2050114313914"></a><a name="en-us_topic_0000002515503852_p2050114313914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p175075312918"><a name="en-us_topic_0000002515503852_p175075312918"></a><a name="en-us_topic_0000002515503852_p175075312918"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1775216157819"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p766118812915"><a name="en-us_topic_0000002515503852_p766118812915"></a><a name="en-us_topic_0000002515503852_p766118812915"></a><span id="en-us_topic_0000002515503852_text136611481596"><a name="en-us_topic_0000002515503852_text136611481596"></a><a name="en-us_topic_0000002515503852_text136611481596"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p205121037920"><a name="en-us_topic_0000002515503852_p205121037920"></a><a name="en-us_topic_0000002515503852_p205121037920"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5517131993"><a name="en-us_topic_0000002515503852_p5517131993"></a><a name="en-us_topic_0000002515503852_p5517131993"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p115221437916"><a name="en-us_topic_0000002515503852_p115221437916"></a><a name="en-us_topic_0000002515503852_p115221437916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1499855417336"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p48161158173310"><a name="en-us_topic_0000002515503852_p48161158173310"></a><a name="en-us_topic_0000002515503852_p48161158173310"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412083"></a>**

```c
 int ret;
    int card_id = 0;
    int device_id = 0;
    struct dcmi_sm_parm parm = {0};
    parm.key_type = 0;
    unsigned char hash1[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    unsigned char *out_buf =  (unsigned char *)malloc(100);
    unsigned int *out_len =(unsigned int *)malloc(sizeof(unsigned int));
    *out_len = 100;
    struct dcmi_sm_data data = {(const unsigned char *)hash1, sizeof(hash1), out_buf, out_len};
    dcmi_init();
    ret = dcmi_sm_encrypt(0, 0, &parm, &data);
    if (ret != 0) {
        //todo: Record logs.
        free(out_buf);
        free(out_len);
        return ret;
    }
    // data.out_buf records the encrypted data, and data.out_len records the length of the encrypted data.
    free(out_buf);
    free(out_len);
```
