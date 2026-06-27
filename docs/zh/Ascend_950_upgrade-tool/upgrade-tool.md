# upgrade-tool

1. 登录Host侧的服务器。
2. 切换到软件包所在安装路径，根据以下表格中的命令调用工具，如下以Driver采用默认安装路径为例进行说明。

    **表 1**  相关工具

    <a name="table181910149231"></a>
    <table><thead align="left"><tr id="row1191614112316"><th class="cellrowborder" valign="top" width="24.2%" id="mcps1.2.4.1.1"><p id="p8191814122318"><a name="p8191814122318"></a><a name="p8191814122318"></a>功能描述</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.67%" id="mcps1.2.4.1.2"><p id="p1919171410234"><a name="p1919171410234"></a><a name="p1919171410234"></a>执行命令</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.13%" id="mcps1.2.4.1.3"><p id="p819014132311"><a name="p819014132311"></a><a name="p819014132311"></a>参数</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17484921194219"><td class="cellrowborder" rowspan="14" valign="top" width="24.2%" headers="mcps1.2.4.1.1 "><p id="p1771385644211"><a name="p1771385644211"></a><a name="p1771385644211"></a>upgrade-tool工具用于查看固件版本、升级单个或多个固件等，只允许root用户执行。</p>
    <p id="p51931482320"><a name="p51931482320"></a><a name="p51931482320"></a>请切换到“/usr/local/Ascend/driver/tools”路径执行命令。</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.67%" headers="mcps1.2.4.1.2 "><p id="p163371534163613"><a name="p163371534163613"></a><a name="p163371534163613"></a>查看帮助信息：</p>
    <p id="p1633743483614"><a name="p1633743483614"></a><a name="p1633743483614"></a><strong id="b18337103483619"><a name="b18337103483619"></a><a name="b18337103483619"></a>./upgrade-tool --help</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="35.13%" headers="mcps1.2.4.1.3 "><p id="p9337734193616"><a name="p9337734193616"></a><a name="p9337734193616"></a>--help：查看帮助信息。</p>
    </td>
    </tr>
    <tr id="row1919171402310"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1376019386426"><a name="p1376019386426"></a><a name="p1376019386426"></a>列举所有Device：</p>
    <p id="p81951416235"><a name="p81951416235"></a><a name="p81951416235"></a><strong id="b121917149237"><a name="b121917149237"></a><a name="b121917149237"></a>./upgrade-tool --mini_devices</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1094121204911"><a name="p1094121204911"></a><a name="p1094121204911"></a>--mini_devices：所有设备列表。</p>
    </td>
    </tr>
    <tr id="row451482242919"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1861818359292"><a name="p1861818359292"></a><a name="p1861818359292"></a>获取指定设备的版本：</p>
    <p id="p8415133112918"><a name="p8415133112918"></a><a name="p8415133112918"></a><strong id="b8195148234"><a name="b8195148234"></a><a name="b8195148234"></a>./upgrade-tool --device_index &lt;dev_id&gt; --system_version</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><a name="ul12665685308"></a><a name="ul12665685308"></a><ul id="ul12665685308"><li>--device_index：<a name="ul10237946112910"></a><a name="ul10237946112910"></a><ul id="ul10237946112910"><li><span id="ph13439122394214"><a name="ph13439122394214"></a><a name="ph13439122394214"></a>软件的逻辑ID</span>。取值可以是[0~7]和-1，[0~7]表示对应编号的设备。-1表示所有设备。</li></ul>
    </li><li>--system_version：系统版本。</li></ul>
    </td>
    </tr>
    <tr id="row8839322123010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p33761935153016"><a name="p33761935153016"></a><a name="p33761935153016"></a>获取指定设备的组件信息：</p>
    <p id="p3741123323017"><a name="p3741123323017"></a><a name="p3741123323017"></a><strong id="b520191418233"><a name="b520191418233"></a><a name="b520191418233"></a>./upgrade-tool --device_index &lt;dev_id&gt; --components</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p194254810412"><a name="p194254810412"></a><a name="p194254810412"></a>--components：列举所有有效的组件。</p>
    </td>
    </tr>
    <tr id="row12127271372"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p175431011143620"><a name="p175431011143620"></a><a name="p175431011143620"></a>查询设备状态：</p>
    <p id="p1320121416232"><a name="p1320121416232"></a><a name="p1320121416232"></a><strong id="b1120161414233"><a name="b1120161414233"></a><a name="b1120161414233"></a>./upgrade-tool --device_index &lt;dev_id&gt; --status</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1591182464310"><a name="p1591182464310"></a><a name="p1591182464310"></a>--status：设备状态。支持的设备状态具体包含：</p>
    <a name="ul12211814122312"></a><a name="ul12211814122312"></a><ul id="ul12211814122312"><li>idle：空闲。</li><li>upgrading：正在升级。</li><li>not support：不支持。</li><li>failed：失败。</li><li>waitting_restart：等待重启。</li><li>waitting_sync：等待固件同步。</li><li>synchronizing：正在同步。</li><li>wrong status：错误状态。</li></ul>
    </td>
    </tr>
    <tr id="row7604354153010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1019414379318"><a name="p1019414379318"></a><a name="p1019414379318"></a>查询某个设备中某一个组件对应的版本：</p>
    <p id="p17201314152317"><a name="p17201314152317"></a><a name="p17201314152317"></a><strong id="b132051412236"><a name="b132051412236"></a><a name="b132051412236"></a>./upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --version</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><a name="ul1270954214412"></a><a name="ul1270954214412"></a><ul id="ul1270954214412"><li>--component：指定具体的组件。查询和升级单个组件时，需要指定组件名称。查询和升级所有组件时，需要输入-1。</li><li>--version：组件的版本。</li></ul>
    </td>
    </tr>
    <tr id="row805260361"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2800202810436"><a name="p2800202810436"></a><a name="p2800202810436"></a>热复位device：</p>
    <p id="p1920714182314"><a name="p1920714182314"></a><a name="p1920714182314"></a><strong id="b1220101462312"><a name="b1220101462312"></a><a name="b1220101462312"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hot_reset</strong></p>
    <p id="p1920141422315"><a name="p1920141422315"></a><a name="p1920141422315"></a>dev_id仅支持-1，表示热复位所有Device，不支持热复位单个Device。</p>
    <div class="note" id="note122011414238"><a name="note122011414238"></a><a name="note122011414238"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul4308225124917"></a><a name="ul4308225124917"></a><ul id="ul4308225124917"><li>执行热复位前，需要先关闭业务。</li><li>仅物理机和特权容器支持该命令。</li></ul>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10111030144313"><a name="p10111030144313"></a><a name="p10111030144313"></a>--hot_reset：热复位Device。</p>
    </td>
    </tr>
    <tr id="row145241452143612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1639113418438"><a name="p1639113418438"></a><a name="p1639113418438"></a>查询设备是否是物理机：</p>
    <p id="p11201214192317"><a name="p11201214192317"></a><a name="p11201214192317"></a><strong id="b17201214142311"><a name="b17201214142311"></a><a name="b17201214142311"></a>./upgrade-tool --device_index &lt;dev_id&gt; --phymachflag</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1047120358432"><a name="p1047120358432"></a><a name="p1047120358432"></a>--phymachflag：查询设备是否是物理机。</p>
    </td>
    </tr>
    <tr id="row265921843718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p122481315144416"><a name="p122481315144416"></a><a name="p122481315144416"></a>获取当前设备的启动状态：</p>
    <p id="p17201014122315"><a name="p17201014122315"></a><a name="p17201014122315"></a><strong id="b14201014192312"><a name="b14201014192312"></a><a name="b14201014192312"></a>./upgrade-tool --device_index &lt;dev_id&gt; --boot_status</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><div class="p" id="p7681191313441"><a name="p7681191313441"></a><a name="p7681191313441"></a>--boot_status：当前设备的启动状态。<a name="ul17225141234"></a><a name="ul17225141234"></a><ul id="ul17225141234"><li>0：未初始化。</li><li>1：BIOS启动中。</li><li>2：OS启动中。</li><li>3：启动完成。</li><li>16：DSMI服务进程启动完成。</li></ul>
    </div>
    </td>
    </tr>
    <tr id="row134812015385"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1544742214442"><a name="p1544742214442"></a><a name="p1544742214442"></a>设置当前设备热复位标志：</p>
    <p id="p3211414152314"><a name="p3211414152314"></a><a name="p3211414152314"></a><strong id="b22131417232"><a name="b22131417232"></a><a name="b22131417232"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hot_reset_flag</strong></p>
    <div class="note" id="note386123111267"><a name="note386123111267"></a><a name="note386123111267"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1586231132613"><a name="p1586231132613"></a><a name="p1586231132613"></a>仅物理机和特权容器支持该命令。</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8918172374414"><a name="p8918172374414"></a><a name="p8918172374414"></a>--hot_reset_flag：当前设备的热复位标志。dev_id仅支持设置-1，设置后会导致基础功能异常，可通过重启恢复。</p>
    </td>
    </tr>
    <tr id="row9954194553812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p115681326114414"><a name="p115681326114414"></a><a name="p115681326114414"></a>设置当前固件兼容的驱动列表。</p>
    <p id="p1821191417238"><a name="p1821191417238"></a><a name="p1821191417238"></a><strong id="b172131442317"><a name="b172131442317"></a><a name="b172131442317"></a>./upgrade-tool --device_index &lt;dev_id&gt; --set_compat_list</strong></p>
    <div class="note" id="note43982892814"><a name="note43982892814"></a><a name="note43982892814"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p239818122810"><a name="p239818122810"></a><a name="p239818122810"></a>仅物理机和特权容器支持该命令。</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p65281328194411"><a name="p65281328194411"></a><a name="p65281328194411"></a>--set_compat_list：给每个芯片的flash设置当前固件兼容的驱动列表。使用该参数可能会影响兼容性检测，请谨慎使用。</p>
    </td>
    </tr>
    <tr id="row17550151773615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1526244803618"><a name="p1526244803618"></a><a name="p1526244803618"></a><span>对Device进行补丁包加载。</span></p>
    <p id="p420402274612"><a name="p420402274612"></a><a name="p420402274612"></a><strong id="b17642835134419"><a name="b17642835134419"></a><a name="b17642835134419"></a>./upgrade-tool</strong> <strong id="b12232156144413"><a name="b12232156144413"></a><a name="b12232156144413"></a>--device_index &lt;dev_id&gt; --patch &lt;patch_path&gt;</strong></p>
    <div class="note" id="note1162718471456"><a name="note1162718471456"></a><a name="note1162718471456"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul10199101453617"></a><a name="ul10199101453617"></a><ul id="ul10199101453617"><li>dev_id仅支持设置-1。</li><li>仅物理机和特权容器支持该命令。</li></ul>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p63051745143819"><a name="p63051745143819"></a><a name="p63051745143819"></a>--patch：对Device进行补丁包加载。</p>
    </td>
    </tr>
    <tr id="row148941015183718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p58941515123714"><a name="p58941515123714"></a><a name="p58941515123714"></a><span>对Device进行补丁包卸载。</span></p>
    <p id="p1457915341378"><a name="p1457915341378"></a><a name="p1457915341378"></a><strong id="b52077812458"><a name="b52077812458"></a><a name="b52077812458"></a>./upgrade-tool --device_index &lt;dev_id&gt; --unload_patch</strong></p>
    <div class="note" id="note56701091384"><a name="note56701091384"></a><a name="note56701091384"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul19470141715363"></a><a name="ul19470141715363"></a><ul id="ul19470141715363"><li>dev_id仅支持设置-1。</li><li>仅物理机和特权容器支持该命令。</li></ul>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15439115317384"><a name="p15439115317384"></a><a name="p15439115317384"></a>--unload_patch：对Device进行补丁包卸载。</p>
    </td>
    </tr>
    <tr id="row497661573513"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1364874415226"><a name="p1364874415226"></a><a name="p1364874415226"></a>获取当前设备兼容的NPU驱动和固件最低要求版本号信息：</p>
    <p id="p17709132552118"><a name="p17709132552118"></a><a name="p17709132552118"></a><strong id="b5116181162218"><a name="b5116181162218"></a><a name="b5116181162218"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hw_base_version</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p173771052142315"><a name="p173771052142315"></a><a name="p173771052142315"></a>--hw_base_version：当前设备兼容的NPU驱动和固件最低要求版本号信息。</p>
    <a name="ul10276104610292"></a><a name="ul10276104610292"></a><ul id="ul10276104610292"><li>0：表示无NPU驱动和固件兼容版本要求。</li><li>crc_error：表示设备故障。</li><li><em id="i14782104363315"><a name="i14782104363315"></a><a name="i14782104363315"></a>xxx</em>（例如235）：表示对驱动和固件最低能力要求值。<p id="p124971215152312"><a name="p124971215152312"></a><a name="p124971215152312"></a>执行以下命令查看对应驱动和固件最低要求的版本号：</p>
    <a name="ul8411622202312"></a><a name="ul8411622202312"></a><ul id="ul8411622202312"><li>驱动：执行<strong id="b17415231112414"><a name="b17415231112414"></a><a name="b17415231112414"></a>cat </strong><em id="i18871183162414"><a name="i18871183162414"></a><a name="i18871183162414"></a>/usr/local/Ascend</em><strong id="b941653113249"><a name="b941653113249"></a><a name="b941653113249"></a>/driver/script/version_cap.map</strong>命令查看“version_cap.map”文件。</li><li>固件：执行<strong id="b698112792415"><a name="b698112792415"></a><a name="b698112792415"></a>cat </strong><em id="i6522122810243"><a name="i6522122810243"></a><a name="i6522122810243"></a>/usr/local/Ascend</em><strong id="b1098112714248"><a name="b1098112714248"></a><a name="b1098112714248"></a>/firmware/script/version_cap.map</strong>命令查看“version_cap.map”文件。<div class="note" id="note152221826152320"><a name="note152221826152320"></a><a name="note152221826152320"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p82221726162315"><a name="p82221726162315"></a><a name="p82221726162315"></a>以上命令中的“/usr/local/Ascend”为软件包安装路径，具体请根据实际情况替换。</p>
    </div></div>
    </li></ul>
    </li></ul>
    </td>
    </tr>
    <tr id="row112219143230"><td class="cellrowborder" rowspan="2" valign="top" width="24.2%" headers="mcps1.2.4.1.1 "><p id="p4973912321"><a name="p4973912321"></a><a name="p4973912321"></a>请切换到“/usr/local/Ascend/firmware/tools”路径执行命令。</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.67%" headers="mcps1.2.4.1.2 "><p id="p1224141234"><a name="p1224141234"></a><a name="p1224141234"></a>升级指定设备的固件包：</p>
    <p id="p1622151410230"><a name="p1622151410230"></a><a name="p1622151410230"></a><strong id="b22291420235"><a name="b22291420235"></a><a name="b22291420235"></a>/usr/local/Ascend/driver/tools/upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --path &lt;firmware_path&gt;</strong></p>
    <div class="note" id="note10548711132112"><a name="note10548711132112"></a><a name="note10548711132112"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p262644510316"><a name="p262644510316"></a><a name="p262644510316"></a>仅物理机和特权容器支持该命令。</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" width="35.13%" headers="mcps1.2.4.1.3 "><p id="p1123171414239"><a name="p1123171414239"></a><a name="p1123171414239"></a>--path：固件包相对路径</p>
    <a name="ul16129415114018"></a><a name="ul16129415114018"></a><ul id="ul16129415114018"><li>若升级全部组件，则为<strong id="b023171462320"><a name="b023171462320"></a><a name="b023171462320"></a>--path conf/upgrade.cfg</strong>；“upgrade.cfg”文件中包含各个组件的相对路径。</li><li>若升级单个组件，例如hilink，则为<strong id="b5231514152314"><a name="b5231514152314"></a><a name="b5231514152314"></a>--path ../image/hilink.bin</strong>。</li></ul>
    </td>
    </tr>
    <tr id="row2278113414711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1238218114810"><a name="p1238218114810"></a><a name="p1238218114810"></a>异步升级指定设备的固件包：</p>
    <p id="p32331412313"><a name="p32331412313"></a><a name="p32331412313"></a><strong id="b142321462312"><a name="b142321462312"></a><a name="b142321462312"></a>/usr/local/Ascend/driver/tools/upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --async --path &lt;firmware_path&gt;</strong></p>
    <p id="p323111462319"><a name="p323111462319"></a><a name="p323111462319"></a><strong id="b202361432310"><a name="b202361432310"></a><a name="b202361432310"></a>--async</strong>必须紧跟在<strong id="b523121420234"><a name="b523121420234"></a><a name="b523121420234"></a>component &lt;type&gt;</strong>后面。</p>
    <div class="note" id="note17852194372112"><a name="note17852194372112"></a><a name="note17852194372112"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p38520432216"><a name="p38520432216"></a><a name="p38520432216"></a>仅物理机和特权容器支持该命令。</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p115801361544"><a name="p115801361544"></a><a name="p115801361544"></a>--async：支持异步升级，即device侧收到Host侧发送的升级请求后，返回请求成功响应到Host侧（具体固件是否升级成功，需要通过“--status”参数去查询）。</p>
    </td>
    </tr>
    </tbody>
    </table>
