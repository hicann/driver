# Return Codes

**Table  1**  Return codes

<a name="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_table087793593717"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row587773523711"><th class="cellrowborder" valign="top" width="10%" id="mcps1.2.7.1.1"><p id="p284813217591"><a name="p284813217591"></a><a name="p284813217591"></a>Return Code Category</p>
</th>
<th class="cellrowborder" valign="top" width="26.13%" id="mcps1.2.7.1.2"><p id="p14848024592"><a name="p14848024592"></a><a name="p14848024592"></a>DCMI Return Code</p>
</th>
<th class="cellrowborder" valign="top" width="13.059999999999999%" id="mcps1.2.7.1.3"><p id="p12848102205917"><a name="p12848102205917"></a><a name="p12848102205917"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="14.52%" id="mcps1.2.7.1.4"><p id="p1484817219598"><a name="p1484817219598"></a><a name="p1484817219598"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="21.77%" id="mcps1.2.7.1.5"><p id="p178482026594"><a name="p178482026594"></a><a name="p178482026594"></a>Solution</p>
</th>
<th class="cellrowborder" valign="top" width="14.52%" id="mcps1.2.7.1.6"><p id="p484810210597"><a name="p484810210597"></a><a name="p484810210597"></a>Remarks</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1387763573713"><td class="cellrowborder" valign="top" width="10%" headers="mcps1.2.7.1.1 "><p id="p026211810585"><a name="p026211810585"></a><a name="p026211810585"></a>Successful execution</p>
</td>
<td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.2.7.1.2 "><p id="p184931298013"><a name="p184931298013"></a><a name="p184931298013"></a>DCMI_OK</p>
</td>
<td class="cellrowborder" valign="top" width="13.059999999999999%" headers="mcps1.2.7.1.3 "><p id="p16493229608"><a name="p16493229608"></a><a name="p16493229608"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="14.52%" headers="mcps1.2.7.1.4 "><p id="p249319291506"><a name="p249319291506"></a><a name="p249319291506"></a>Execution succeeded.</p>
</td>
<td class="cellrowborder" valign="top" width="21.77%" headers="mcps1.2.7.1.5 "><p id="p271816446589"><a name="p271816446589"></a><a name="p271816446589"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="14.52%" headers="mcps1.2.7.1.6 "><p id="p1921441211583"><a name="p1921441211583"></a><a name="p1921441211583"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row4877113503714"><td class="cellrowborder" rowspan="6" valign="top" width="10%" headers="mcps1.2.7.1.1 "><p id="p844120491808"><a name="p844120491808"></a><a name="p844120491808"></a>Invalid input parameter, abnormal device status, or abnormal environment</p>
</td>
<td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.2.7.1.2 "><p id="p649342912014"><a name="p649342912014"></a><a name="p649342912014"></a>DCMI_ERR_CODE_INVALID_PARAMETER</p>
</td>
<td class="cellrowborder" valign="top" width="13.059999999999999%" headers="mcps1.2.7.1.3 "><p id="p1493729505"><a name="p1493729505"></a><a name="p1493729505"></a>-8001</p>
</td>
<td class="cellrowborder" valign="top" width="14.52%" headers="mcps1.2.7.1.4 "><p id="p64931829304"><a name="p64931829304"></a><a name="p64931829304"></a>Incorrect input parameter.</p>
</td>
<td class="cellrowborder" valign="top" width="21.77%" headers="mcps1.2.7.1.5 "><p id="p14613115915115"><a name="p14613115915115"></a><a name="p14613115915115"></a>Check the validity of input parameters.</p>
</td>
<td class="cellrowborder" rowspan="13" valign="top" width="14.52%" headers="mcps1.2.7.1.6 "><p id="p186986196317"><a name="p186986196317"></a><a name="p186986196317"></a>If the fault persists, contact Huawei engineers.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row15877153543714"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p6494162913015"><a name="p6494162913015"></a><a name="p6494162913015"></a>DCMI_ERR_CODE_MEM_OPERATE_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p5494182910013"><a name="p5494182910013"></a><a name="p5494182910013"></a>-8003</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p44941029809"><a name="p44941029809"></a><a name="p44941029809"></a>Memory API operation failed.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p7613185912112"><a name="p7613185912112"></a><a name="p7613185912112"></a>Verify that user space memory is sufficient.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row48778351379"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p6494102911016"><a name="p6494102911016"></a><a name="p6494102911016"></a>DCMI_ERR_CODE_INVALID_DEVICE_ID</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p949410298010"><a name="p949410298010"></a><a name="p949410298010"></a>-8007</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p174941629907"><a name="p174941629907"></a><a name="p174941629907"></a>Invalid device ID.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p3613159913"><a name="p3613159913"></a><a name="p3613159913"></a>Verify that the input device ID is valid.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1187719353374"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p104944291602"><a name="p104944291602"></a><a name="p104944291602"></a>DCMI_ERR_CODE_DEVICE_NOT_EXIST</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p349462916014"><a name="p349462916014"></a><a name="p349462916014"></a>-8008</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p049417291203"><a name="p049417291203"></a><a name="p049417291203"></a>The device does not exist.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p16613859911"><a name="p16613859911"></a><a name="p16613859911"></a>Verify that the device is running properly or that the device exists.</p>
</td>
</tr>
<tr id="row920918413169"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p154940291004"><a name="p154940291004"></a><a name="p154940291004"></a>DCMI_ERR_CODE_CONFIG_INFO_NOT_EXIST</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p74941629802"><a name="p74941629802"></a><a name="p74941629802"></a>-8023</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p10494142915019"><a name="p10494142915019"></a><a name="p10494142915019"></a>The queried configuration does not exist.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p206138591811"><a name="p206138591811"></a><a name="p206138591811"></a>Verify that the configuration is completed before performing the query.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row48771635173717"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p59643193177"><a name="p59643193177"></a><a name="p59643193177"></a>DCMI_ERR_CODE_FILE_OPERATE_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p9344712161613"><a name="p9344712161613"></a><a name="p9344712161613"></a>-8014</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p13437126168"><a name="p13437126168"></a><a name="p13437126168"></a>File operation failed.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p10343101251616"><a name="p10343101251616"></a><a name="p10343101251616"></a>Verify that the file exists, the file permission meets the requirements, and the file is not damaged.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1287815355374"><td class="cellrowborder" rowspan="3" valign="top" headers="mcps1.2.7.1.1 "><p id="p19681681313"><a name="p19681681313"></a><a name="p19681681313"></a>Permission or function not supported</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p1249416298013"><a name="p1249416298013"></a><a name="p1249416298013"></a>DCMI_ERR_CODE_OPER_NOT_PERMITTED</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p18494329100"><a name="p18494329100"></a><a name="p18494329100"></a>-8002</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p94948295010"><a name="p94948295010"></a><a name="p94948295010"></a>Permission error.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.5 "><p id="p18614659513"><a name="p18614659513"></a><a name="p18614659513"></a>Check the user permission and verify that the current scenario meets the API permission requirements.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row118788352370"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p124944292010"><a name="p124944292010"></a><a name="p124944292010"></a>DCMI_ERR_CODE_NOT_SUPPORT_IN_CONTAINER</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p5494829503"><a name="p5494829503"></a><a name="p5494829503"></a>-8013</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p1649462911019"><a name="p1649462911019"></a><a name="p1649462911019"></a>This API is not supported in a container environment.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p14614459711"><a name="p14614459711"></a><a name="p14614459711"></a>This API is not supported in a container environment.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1878163503717"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p44941129606"><a name="p44941129606"></a><a name="p44941129606"></a>DCMI_ERR_CODE_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p04946299017"><a name="p04946299017"></a><a name="p04946299017"></a>-8255</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p0494152915010"><a name="p0494152915010"></a><a name="p0494152915010"></a>The device ID or function is not supported.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p26141259813"><a name="p26141259813"></a><a name="p26141259813"></a>The device does not support this function.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1287833511372"><td class="cellrowborder" rowspan="4" valign="top" headers="mcps1.2.7.1.1 "><p id="p1555922914118"><a name="p1555922914118"></a><a name="p1555922914118"></a>Retry upon timeout</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p54947293015"><a name="p54947293015"></a><a name="p54947293015"></a>DCMI_ERR_CODE_TIME_OUT</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p44946297013"><a name="p44946297013"></a><a name="p44946297013"></a>-8006</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p449414291606"><a name="p449414291606"></a><a name="p449414291606"></a>Response timeout.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.5 "><p id="p116141595114"><a name="p116141595114"></a><a name="p116141595114"></a>Response timed out. Please try again later.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1887853553714"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p1649452914012"><a name="p1649452914012"></a><a name="p1649452914012"></a>DCMI_ERR_CODE_NOT_REDAY</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p2049416298013"><a name="p2049416298013"></a><a name="p2049416298013"></a>-8012</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p54942291505"><a name="p54942291505"></a><a name="p54942291505"></a>Not ready. Please try again.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p16614159118"><a name="p16614159118"></a><a name="p16614159118"></a>The device is not ready. Please retry later.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row188781835113710"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p449412297018"><a name="p449412297018"></a><a name="p449412297018"></a>DCMI_ERR_CODE_IS_UPGRADING</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p34949293012"><a name="p34949293012"></a><a name="p34949293012"></a>-8017</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p649414296017"><a name="p649414296017"></a><a name="p649414296017"></a>The upgrade is in progress.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p161412593120"><a name="p161412593120"></a><a name="p161412593120"></a>The device is being upgraded. Please try again later.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row10878193513716"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p17494132910019"><a name="p17494132910019"></a><a name="p17494132910019"></a>DCMI_ERR_CODE_RESOURCE_OCCUPIED</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p44941929109"><a name="p44941929109"></a><a name="p44941929109"></a>-8020</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p1749432913019"><a name="p1749432913019"></a><a name="p1749432913019"></a>Device resources are occupied.</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p161415916117"><a name="p161415916117"></a><a name="p161415916117"></a>Check that the device is not occupied by other containers or processes and try again.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row188782035153718"><td class="cellrowborder" rowspan="7" valign="top" width="10%" headers="mcps1.2.7.1.1 "><p id="p33290398113"><a name="p33290398113"></a><a name="p33290398113"></a>Internal execution exception</p>
</td>
<td class="cellrowborder" valign="top" width="26.13%" headers="mcps1.2.7.1.2 "><p id="p174948295013"><a name="p174948295013"></a><a name="p174948295013"></a>DCMI_ERR_CODE_SECURE_FUN_FAIL</p>
</td>
<td class="cellrowborder" valign="top" width="13.059999999999999%" headers="mcps1.2.7.1.3 "><p id="p14494182918015"><a name="p14494182918015"></a><a name="p14494182918015"></a>-8004</p>
</td>
<td class="cellrowborder" valign="top" width="14.52%" headers="mcps1.2.7.1.4 "><p id="p74945291606"><a name="p74945291606"></a><a name="p74945291606"></a>Secure function execution failed.</p>
</td>
<td class="cellrowborder" rowspan="7" valign="top" width="21.77%" headers="mcps1.2.7.1.5 "><p id="p1871315404218"><a name="p1871315404218"></a><a name="p1871315404218"></a>Provide logs and contact Huawei engineers.</p>
</td>
<td class="cellrowborder" rowspan="7" valign="top" width="14.52%" headers="mcps1.2.7.1.6 "><p id="p164914496211"><a name="p164914496211"></a><a name="p164914496211"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row1887918356377"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p1049417291302"><a name="p1049417291302"></a><a name="p1049417291302"></a>DCMI_ERR_CODE_INNER_ERR</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p949412911015"><a name="p949412911015"></a><a name="p949412911015"></a>-8005</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p104942292003"><a name="p104942292003"></a><a name="p104942292003"></a>Internal error.</p>
</td>
</tr>
<tr id="row196312131303"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p349492910014"><a name="p349492910014"></a><a name="p349492910014"></a>DCMI_ERR_CODE_IOCTL_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p9494132914017"><a name="p9494132914017"></a><a name="p9494132914017"></a>-8009</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p849418295012"><a name="p849418295012"></a><a name="p849418295012"></a>ioctl return failure.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row2879435163716"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p134944291806"><a name="p134944291806"></a><a name="p134944291806"></a>DCMI_ERR_CODE_SEND_MSG_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p1549412291409"><a name="p1549412291409"></a><a name="p1549412291409"></a>-8010</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p749420291001"><a name="p749420291001"></a><a name="p749420291001"></a>Message sending failed.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row887913352378"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p7494182913019"><a name="p7494182913019"></a><a name="p7494182913019"></a>DCMI_ERR_CODE_RECV_MSG_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p1249402920012"><a name="p1249402920012"></a><a name="p1249402920012"></a>-8011</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p184948291703"><a name="p184948291703"></a><a name="p184948291703"></a>Message receiving failed.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427209_en-us_topic_0000001223292879_en-us_topic_0000001174989205_row3879535133712"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p1349412918018"><a name="p1349412918018"></a><a name="p1349412918018"></a>DCMI_ERR_CODE_RESET_FAIL</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p14941291202"><a name="p14941291202"></a><a name="p14941291202"></a>-8015</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p6494729205"><a name="p6494729205"></a><a name="p6494729205"></a>Reset failed.</p>
</td>
</tr>
<tr id="row881013109012"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p144941295017"><a name="p144941295017"></a><a name="p144941295017"></a>DCMI_ERR_CODE_ABORT_OPERATE</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p149419291503"><a name="p149419291503"></a><a name="p149419291503"></a>-8016</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p1449416291004"><a name="p1449416291004"></a><a name="p1449416291004"></a>Reset canceled.</p>
</td>
</tr>
</tbody>
</table>
