# dcmi\_set\_power\_state<a name="EN-US_TOPIC_0000002546983801"></a>

**Prototype<a name="en-us_topic_0000001532160665_en-us_topic_0251903700_section204121018181415"></a>**

**int dcmi\_set\_power\_state\(int card\_id, int device\_id, struct dcmi\_power\_state\_info\_stru power\_info\)**

**Description<a name="en-us_topic_0000001532160665_en-us_topic_0251903700_section10486629111410"></a>**

Sets the system mode.

**Parameter Description<a name="en-us_topic_0000001532160665_en-us_topic_0251903700_section1126553991413"></a>**

<a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row67890141240"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1555923777102829"><a name="b1555923777102829"></a><a name="b1555923777102829"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b195091455110250"><a name="b195091455110250"></a><a name="b195091455110250"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b19300731105347"><a name="b19300731105347"></a><a name="b19300731105347"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001532160665_p9315182755815"><a name="en-us_topic_0000001532160665_p9315182755815"></a><a name="en-us_topic_0000001532160665_p9315182755815"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a><a name="en-us_topic_0000001532160665_en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a>struct dcmi_power_state_info_stru</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p2680123615336"><a name="p2680123615336"></a><a name="p2680123615336"></a>System status.</p>
<p id="p7279113417175"><a name="p7279113417175"></a><a name="p7279113417175"></a>typedef enum {</p>
<p id="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p49221225161714"><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p49221225161714"></a><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p49221225161714"></a>DCMI_POWER_STATE_SUSPEND, // Suspend</p>
<p id="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p7922192510177"><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p7922192510177"></a><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p7922192510177"></a>DCMI_POWER_STATE_POWEROFF, // Power off</p>
<p id="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1392216255179"><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1392216255179"></a><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1392216255179"></a>DCMI_POWER_STATE_RESET, // Reset</p>
<p id="p1892262581711"><a name="p1892262581711"></a><a name="p1892262581711"></a>DCMI_POWER_STATE_MAX,</p>
<p id="p49221125171711"><a name="p49221125171711"></a><a name="p49221125171711"></a>} DCMI_POWER_STATE;</p>
<p id="p69221425171710"><a name="p69221425171710"></a><a name="p69221425171710"></a></p>
<p id="p19336184841719"><a name="p19336184841719"></a><a name="p19336184841719"></a>typedef enum {</p>
<p id="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1192222517179"><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1192222517179"></a><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p1192222517179"></a>DCMI_POWER_RESUME_MODE_BUTTON, // Power resume by button</p>
<p id="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p9922112571710"><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p9922112571710"></a><a name="en-us_topic_0000001548668158_en-us_topic_0000001548828062_p9922112571710"></a>DCMI_POWER_RESUME_MODE_TIME, // Power resume by time</p>
<p id="p6922925191713"><a name="p6922925191713"></a><a name="p6922925191713"></a>DCMI_POWER_RESUME_MODE_MAX,</p>
<p id="p1492219258178"><a name="p1492219258178"></a><a name="p1492219258178"></a>} DCMI_LP_RESUME_MODE;</p>
<p id="p179222259171"><a name="p179222259171"></a><a name="p179222259171"></a></p>
<p id="p292216258173"><a name="p292216258173"></a><a name="p292216258173"></a>#define DCMI_POWER_INFO_RESERVE_LEN 8</p>
<p id="p59221125181714"><a name="p59221125181714"></a><a name="p59221125181714"></a>struct dcmi_power_state_info_stru {</p>
<p id="p59221325111718"><a name="p59221325111718"></a><a name="p59221325111718"></a>DCMI_POWER_STATE type; // Hibernation and wakeup state</p>
<p id="p10922142519172"><a name="p10922142519172"></a><a name="p10922142519172"></a>DCMI_LP_RESUME_MODE mode; // Hibernation and wakeup mode</p>
<p id="p119229251172"><a name="p119229251172"></a><a name="p119229251172"></a>unsigned int value;</p>
<p id="p592216259177"><a name="p592216259177"></a><a name="p592216259177"></a>unsigned int reserve[DCMI_POWER_INFO_RESERVE_LEN]; // Reserved</p>
<p id="p1092262511718"><a name="p1092262511718"></a><a name="p1092262511718"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b13593184385618"><a name="b13593184385618"></a><a name="b13593184385618"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001532160665_en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412082"></a>**

After the command is executed, the device enters the sleep state immediately. After the sleep period ends, the device automatically wakes up.

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

**Example<a name="en-us_topic_0000001532160665_en-us_topic_0251903700_section1130783912517"></a>**

```c
...
    int ret;
    int card_id = 0;
    int device_id = 0;
    struct dcmi_power_state_info_stru power_info = {0};

    power_info.type = DCMI_POWER_STATE_SUSPEND;
    power_info.mode = DCMI_POWER_RESUME_MODE_TIME;
    power_info.value = 300;// 300ms

    ret = dcmi_set_power_state(card_id, device_id, power_info);
    if (ret) {
        // todo
    }
    // todo
...
```
