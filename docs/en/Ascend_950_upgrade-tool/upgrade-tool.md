# upgrade-tool

1. Log in to the  server on the host.
2. Switch to the installation path of the software package and run the commands in the following table to call the tool. The following uses the default installation path of the driver as an example.

    **Table  1**  Tools

    <a name="table181910149231"></a>
    <table><thead align="left"><tr id="row1191614112316"><th class="cellrowborder" valign="top" width="24.2%" id="mcps1.2.4.1.1"><p id="p8191814122318"><a name="p8191814122318"></a><a name="p8191814122318"></a>Function</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.67%" id="mcps1.2.4.1.2"><p id="p1919171410234"><a name="p1919171410234"></a><a name="p1919171410234"></a>Command</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.13%" id="mcps1.2.4.1.3"><p id="p819014132311"><a name="p819014132311"></a><a name="p819014132311"></a>Parameter</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17484921194219"><td class="cellrowborder" rowspan="14" valign="top" width="24.2%" headers="mcps1.2.4.1.1 "><p id="p1771385644211"><a name="p1771385644211"></a><a name="p1771385644211"></a>upgrade-tool is used to view firmware versions and upgrade one or more pieces of firmware. Only the <strong id="b847991714817"><a name="b847991714817"></a><a name="b847991714817"></a>root</strong> user is allowed to run this tool.</p>
    <p id="p51931482320"><a name="p51931482320"></a><a name="p51931482320"></a>Switch to the <strong id="b1039461493114335"><a name="b1039461493114335"></a><a name="b1039461493114335"></a>/usr/local/Ascend/driver/tools</strong> directory before running commands.</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.67%" headers="mcps1.2.4.1.2 "><p id="p163371534163613"><a name="p163371534163613"></a><a name="p163371534163613"></a>Views the help information:</p>
    <p id="p1633743483614"><a name="p1633743483614"></a><a name="p1633743483614"></a><strong id="b18337103483619"><a name="b18337103483619"></a><a name="b18337103483619"></a>./upgrade-tool --help</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="35.13%" headers="mcps1.2.4.1.3 "><p id="p9337734193616"><a name="p9337734193616"></a><a name="p9337734193616"></a><strong id="b2132193354114335"><a name="b2132193354114335"></a><a name="b2132193354114335"></a>--help</strong>: help information.</p>
    </td>
    </tr>
    <tr id="row1919171402310"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1376019386426"><a name="p1376019386426"></a><a name="p1376019386426"></a>Lists all devices:</p>
    <p id="p81951416235"><a name="p81951416235"></a><a name="p81951416235"></a><strong id="b121917149237"><a name="b121917149237"></a><a name="b121917149237"></a>./upgrade-tool --mini_devices</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1094121204911"><a name="p1094121204911"></a><a name="p1094121204911"></a><strong id="b1231209987114335"><a name="b1231209987114335"></a><a name="b1231209987114335"></a>--mini_devices</strong>: list of all devices.</p>
    </td>
    </tr>
    <tr id="row451482242919"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1861818359292"><a name="p1861818359292"></a><a name="p1861818359292"></a>Obtains the version of a specified device.</p>
    <p id="p8415133112918"><a name="p8415133112918"></a><a name="p8415133112918"></a><strong id="b8195148234"><a name="b8195148234"></a><a name="b8195148234"></a>./upgrade-tool --device_index &lt;dev_id&gt; --system_version</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><a name="ul12665685308"></a><a name="ul12665685308"></a><ul id="ul12665685308"><li><strong id="b46684277196"><a name="b46684277196"></a><a name="b46684277196"></a>--device_index</strong>:<a name="ul10237946112910"></a><a name="ul10237946112910"></a><ul id="ul10237946112910"><li>Device ID. The value can be <strong id="b14341171702019"><a name="b14341171702019"></a><a name="b14341171702019"></a>-1</strong> or a number within [0–7]. A value ranging from <strong id="b19631112722010"><a name="b19631112722010"></a><a name="b19631112722010"></a>0</strong> to <strong id="b1215122952017"><a name="b1215122952017"></a><a name="b1215122952017"></a>7</strong> indicates the device with the corresponding ID. The value <strong id="b1460323819114335"><a name="b1460323819114335"></a><a name="b1460323819114335"></a>–1</strong> indicates all devices.</li></ul>
    </li><li><strong id="b53281555114335"><a name="b53281555114335"></a><a name="b53281555114335"></a>--system_version</strong>: system version.</li></ul>
    </td>
    </tr>
    <tr id="row8839322123010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p33761935153016"><a name="p33761935153016"></a><a name="p33761935153016"></a>Obtains the component information about a specified device:</p>
    <p id="p3741123323017"><a name="p3741123323017"></a><a name="p3741123323017"></a><strong id="b520191418233"><a name="b520191418233"></a><a name="b520191418233"></a>./upgrade-tool --device_index &lt;dev_id&gt; --components</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p194254810412"><a name="p194254810412"></a><a name="p194254810412"></a><strong id="b922136099114335"><a name="b922136099114335"></a><a name="b922136099114335"></a>--components</strong>: lists of all valid components.</p>
    </td>
    </tr>
    <tr id="row12127271372"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p175431011143620"><a name="p175431011143620"></a><a name="p175431011143620"></a>Queries the device status:</p>
    <p id="p1320121416232"><a name="p1320121416232"></a><a name="p1320121416232"></a><strong id="b1120161414233"><a name="b1120161414233"></a><a name="b1120161414233"></a>./upgrade-tool --device_index &lt;dev_id&gt; --status</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1591182464310"><a name="p1591182464310"></a><a name="p1591182464310"></a><strong id="b906715264114335"><a name="b906715264114335"></a><a name="b906715264114335"></a>--status</strong>: device status. The following device status is supported:</p>
    <a name="ul12211814122312"></a><a name="ul12211814122312"></a><ul id="ul12211814122312"><li><strong id="en-us_topic_0000001208601789_b10137171618512"><a name="en-us_topic_0000001208601789_b10137171618512"></a><a name="en-us_topic_0000001208601789_b10137171618512"></a>idle</strong></li><li><strong id="en-us_topic_0000001208601789_b075142611519"><a name="en-us_topic_0000001208601789_b075142611519"></a><a name="en-us_topic_0000001208601789_b075142611519"></a>upgrading</strong></li><li><strong id="en-us_topic_0000001208601789_b12865281259"><a name="en-us_topic_0000001208601789_b12865281259"></a><a name="en-us_topic_0000001208601789_b12865281259"></a>not support</strong></li><li><strong id="en-us_topic_0000001208601789_b17352154012519"><a name="en-us_topic_0000001208601789_b17352154012519"></a><a name="en-us_topic_0000001208601789_b17352154012519"></a>failed</strong></li><li><strong id="en-us_topic_0000001208601789_b172631120614"><a name="en-us_topic_0000001208601789_b172631120614"></a><a name="en-us_topic_0000001208601789_b172631120614"></a>waitting_restart</strong>: The device is waiting to be restarted.</li><li><strong id="b16301657205911"><a name="b16301657205911"></a><a name="b16301657205911"></a>waiting_sync</strong>: The device is waiting for firmware synchronization.</li><li><strong id="en-us_topic_0000001208601789_b144726531165"><a name="en-us_topic_0000001208601789_b144726531165"></a><a name="en-us_topic_0000001208601789_b144726531165"></a>synchronizing</strong></li><li><strong id="b1280703739114335"><a name="b1280703739114335"></a><a name="b1280703739114335"></a>wrong status</strong></li></ul>
    </td>
    </tr>
    <tr id="row7604354153010"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1019414379318"><a name="p1019414379318"></a><a name="p1019414379318"></a>Queries the version of a device component:</p>
    <p id="p17201314152317"><a name="p17201314152317"></a><a name="p17201314152317"></a><strong id="b132051412236"><a name="b132051412236"></a><a name="b132051412236"></a>./upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --version</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><a name="ul1270954214412"></a><a name="ul1270954214412"></a><ul id="ul1270954214412"><li><strong id="b872502730114335"><a name="b872502730114335"></a><a name="b872502730114335"></a>--component</strong>: component name. When querying and upgrading a single component, specify the component name. The value <strong id="b683785591114335"><a name="b683785591114335"></a><a name="b683785591114335"></a>–1</strong> indicates query and update of all components.</li><li><strong id="b2124501527114335"><a name="b2124501527114335"></a><a name="b2124501527114335"></a>--version</strong>: component version.</li></ul>
    </td>
    </tr>
    <tr id="row805260361"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2800202810436"><a name="p2800202810436"></a><a name="p2800202810436"></a>Performs hot reset on the device:</p>
    <p id="p1920714182314"><a name="p1920714182314"></a><a name="p1920714182314"></a><strong id="b1220101462312"><a name="b1220101462312"></a><a name="b1220101462312"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hot_reset</strong></p>
    <p id="p1920141422315"><a name="p1920141422315"></a><a name="p1920141422315"></a><strong id="b216650506114335"><a name="b216650506114335"></a><a name="b216650506114335"></a>dev_id = –1</strong> indicates that all devices are hot reset. Hot reset of a single device is not allowed.</p>
    <div class="note" id="note122011414238"><a name="note122011414238"></a><a name="note122011414238"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p420131414237"><a name="p420131414237"></a><a name="p420131414237"></a>Before performing a hot reset, stop the services.</p>
    <p id="p14709105742617"><a name="p14709105742617"></a><a name="p14709105742617"></a>This command is supported only on PMs.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10111030144313"><a name="p10111030144313"></a><a name="p10111030144313"></a><strong id="b2848125452310"><a name="b2848125452310"></a><a name="b2848125452310"></a>--hot_reset</strong>: hot reset of a device.</p>
    </td>
    </tr>
    <tr id="row145241452143612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1639113418438"><a name="p1639113418438"></a><a name="p1639113418438"></a>Checks if a device is a physical device:</p>
    <p id="p11201214192317"><a name="p11201214192317"></a><a name="p11201214192317"></a><strong id="b17201214142311"><a name="b17201214142311"></a><a name="b17201214142311"></a>./upgrade-tool --device_index &lt;dev_id&gt; --phymachflag</strong></p>
    <div class="note" id="note1420141415239"><a name="note1420141415239"></a><a name="note1420141415239"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p120111416238"><a name="p120111416238"></a><a name="p120111416238"></a>The firmware package can be upgraded only on a PM.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1047120358432"><a name="p1047120358432"></a><a name="p1047120358432"></a><strong id="b102923934114335"><a name="b102923934114335"></a><a name="b102923934114335"></a>--phymachflag</strong>: queries if a device is a physical device. If the device is not a physical device, the firmware of the device cannot be upgraded.</p>
    </td>
    </tr>
    <tr id="row265921843718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p122481315144416"><a name="p122481315144416"></a><a name="p122481315144416"></a>Obtains the startup status of the current device:</p>
    <p id="p17201014122315"><a name="p17201014122315"></a><a name="p17201014122315"></a><strong id="b14201014192312"><a name="b14201014192312"></a><a name="b14201014192312"></a>./upgrade-tool --device_index &lt;dev_id&gt; --boot_status</strong></p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><div class="p" id="p7681191313441"><a name="p7681191313441"></a><a name="p7681191313441"></a><strong id="b1100683858114335"><a name="b1100683858114335"></a><a name="b1100683858114335"></a>--boot_status</strong>: startup status of the current device.<a name="ul17225141234"></a><a name="ul17225141234"></a><ul id="ul17225141234"><li><strong id="en-us_topic_0000001208601789_b260411392234"><a name="en-us_topic_0000001208601789_b260411392234"></a><a name="en-us_topic_0000001208601789_b260411392234"></a>0</strong>: The device has not been initialized.</li><li><strong id="en-us_topic_0000001208601789_b6460549132317"><a name="en-us_topic_0000001208601789_b6460549132317"></a><a name="en-us_topic_0000001208601789_b6460549132317"></a>1</strong>: The BIOS is starting.</li><li><strong id="en-us_topic_0000001208601789_b111055332313"><a name="en-us_topic_0000001208601789_b111055332313"></a><a name="en-us_topic_0000001208601789_b111055332313"></a>2</strong>: The OS is starting.</li><li><strong id="en-us_topic_0000001208601789_b3109197122414"><a name="en-us_topic_0000001208601789_b3109197122414"></a><a name="en-us_topic_0000001208601789_b3109197122414"></a>3</strong>: The startup is complete.</li><li><strong id="b419753801114335"><a name="b419753801114335"></a><a name="b419753801114335"></a>16</strong>: The DSMI service process has been started.</li></ul>
    </div>
    </td>
    </tr>
    <tr id="row134812015385"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1544742214442"><a name="p1544742214442"></a><a name="p1544742214442"></a>Sets the hot reset flag for the current device:</p>
    <p id="p3211414152314"><a name="p3211414152314"></a><a name="p3211414152314"></a><strong id="b22131417232"><a name="b22131417232"></a><a name="b22131417232"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hot_reset_flag</strong></p>
    <div class="note" id="note386123111267"><a name="note386123111267"></a><a name="note386123111267"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1586231132613"><a name="p1586231132613"></a><a name="p1586231132613"></a>This command is supported only on PMs.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8918172374414"><a name="p8918172374414"></a><a name="p8918172374414"></a><strong id="b473913845114335"><a name="b473913845114335"></a><a name="b473913845114335"></a>--hot_reset_flag</strong>: hot reset flag of the current device. <strong id="b182438187114335"><a name="b182438187114335"></a><a name="b182438187114335"></a>dev_id</strong> can only be set to <strong id="b432373288114335"><a name="b432373288114335"></a><a name="b432373288114335"></a>-1</strong>. If <strong id="b1884199247114335"><a name="b1884199247114335"></a><a name="b1884199247114335"></a>dev_id</strong> is set to <strong id="b895793275114335"><a name="b895793275114335"></a><a name="b895793275114335"></a>-1</strong>, basic functions will be abnormal. You can restart the device to rectify the fault.</p>
    </td>
    </tr>
    <tr id="row9954194553812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p115681326114414"><a name="p115681326114414"></a><a name="p115681326114414"></a>Sets the list of drivers compatible with the current firmware.</p>
    <p id="p1821191417238"><a name="p1821191417238"></a><a name="p1821191417238"></a><strong id="b172131442317"><a name="b172131442317"></a><a name="b172131442317"></a>./upgrade-tool --device_index &lt;dev_id&gt; --set_compat_list</strong></p>
    <div class="note" id="note43982892814"><a name="note43982892814"></a><a name="note43982892814"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p239818122810"><a name="p239818122810"></a><a name="p239818122810"></a>This command is supported only on PMs.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p65281328194411"><a name="p65281328194411"></a><a name="p65281328194411"></a><strong id="b8679122313299"><a name="b8679122313299"></a><a name="b8679122313299"></a>--set_compat_list</strong>: list of drivers compatible with the current firmware for the flash memory of each chip. Using this parameter may affect compatibility check. Therefore, exercise caution when using this parameter.</p>
    </td>
    </tr>
    <tr id="row17550151773615"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1526244803618"><a name="p1526244803618"></a><a name="p1526244803618"></a>Loads the patch package to the device.</p>
    <p id="p420402274612"><a name="p420402274612"></a><a name="p420402274612"></a><strong id="b17642835134419"><a name="b17642835134419"></a><a name="b17642835134419"></a>./upgrade-tool</strong> <strong id="b12232156144413"><a name="b12232156144413"></a><a name="b12232156144413"></a>--device_index &lt;dev_id&gt; --patch &lt;patch_path&gt;</strong></p>
    <div class="note" id="note1162718471456"><a name="note1162718471456"></a><a name="note1162718471456"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p16840133614469"><a name="p16840133614469"></a><a name="p16840133614469"></a><strong id="b47027917274322"><a name="b47027917274322"></a><a name="b47027917274322"></a>dev_id</strong> can only be set to <strong id="b160407039874322"><a name="b160407039874322"></a><a name="b160407039874322"></a>-1</strong>.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p63051745143819"><a name="p63051745143819"></a><a name="p63051745143819"></a><strong id="b44284488974322"><a name="b44284488974322"></a><a name="b44284488974322"></a>--patch</strong>: loads the patch package to the device.</p>
    </td>
    </tr>
    <tr id="row148941015183718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p58941515123714"><a name="p58941515123714"></a><a name="p58941515123714"></a>Uninstalls the patch package on the device.</p>
    <p id="p1457915341378"><a name="p1457915341378"></a><a name="p1457915341378"></a><strong id="b52077812458"><a name="b52077812458"></a><a name="b52077812458"></a>./upgrade-tool --device_index &lt;dev_id&gt; --unload_patch</strong></p>
    <div class="note" id="note56701091384"><a name="note56701091384"></a><a name="note56701091384"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p36714983814"><a name="p36714983814"></a><a name="p36714983814"></a><strong id="b34978153074322"><a name="b34978153074322"></a><a name="b34978153074322"></a>dev_id</strong> can only be set to <strong id="b32805863874322"><a name="b32805863874322"></a><a name="b32805863874322"></a>-1</strong>.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15439115317384"><a name="p15439115317384"></a><a name="p15439115317384"></a><strong id="b56414012274322"><a name="b56414012274322"></a><a name="b56414012274322"></a>--unload_patch</strong>: uninstalls the patch package on the device.</p>
    </td>
    </tr>
    <tr id="row497661573513"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1364874415226"><a name="p1364874415226"></a><a name="p1364874415226"></a>Obtains the earliest versions of the NPU driver and firmware compatible with the current device:</p>
    <p id="p17709132552118"><a name="p17709132552118"></a><a name="p17709132552118"></a><strong id="b5116181162218"><a name="b5116181162218"></a><a name="b5116181162218"></a>./upgrade-tool --device_index &lt;dev_id&gt; --hw_base_version</strong></p>
    <div class="note" id="note95919578282"><a name="note95919578282"></a><a name="note95919578282"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p85913574281"><a name="p85913574281"></a><a name="p85913574281"></a>Obtaining the earliest NPU firmware version of a VM is not supported.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p173771052142315"><a name="p173771052142315"></a><a name="p173771052142315"></a><strong id="b206158451774322"><a name="b206158451774322"></a><a name="b206158451774322"></a>--hw_base_version</strong>: Obtains the earliest versions of the NPU driver and firmware compatible with the current device.</p>
    <a name="ul10276104610292"></a><a name="ul10276104610292"></a><ul id="ul10276104610292"><li><strong id="b199232317374322"><a name="b199232317374322"></a><a name="b199232317374322"></a>0</strong>: There is no version compatibility requirement on the NPU driver and firmware versions.</li><li><strong id="b206821044974322"><a name="b206821044974322"></a><a name="b206821044974322"></a>crc_error</strong>: The device is faulty.</li><li><em id="i35361040474322"><a name="i35361040474322"></a><a name="i35361040474322"></a>xxx</em> (for example, <strong id="b22622625074322"><a name="b22622625074322"></a><a name="b22622625074322"></a>235</strong>): It is the earliest version required for the driver and firmware.<p id="p124971215152312"><a name="p124971215152312"></a><a name="p124971215152312"></a>Run the following commands to check the earliest driver and firmware versions required:</p>
    <a name="ul8411622202312"></a><a name="ul8411622202312"></a><ul id="ul8411622202312"><li>Driver: Run the <strong id="b105568375074322"><a name="b105568375074322"></a><a name="b105568375074322"></a>cat </strong><em id="i197231050274322"><a name="i197231050274322"></a><a name="i197231050274322"></a>/usr/local/Ascend</em><strong id="b63292690074322"><a name="b63292690074322"></a><a name="b63292690074322"></a>/driver/script/version_cap.map</strong> command to view the <strong id="b71841008674322"><a name="b71841008674322"></a><a name="b71841008674322"></a>version_cap.map</strong> file.</li><li>Firmware: Run the <strong id="b25553827974322"><a name="b25553827974322"></a><a name="b25553827974322"></a>cat </strong><em id="i176555323174322"><a name="i176555323174322"></a><a name="i176555323174322"></a>/usr/local/Ascend</em><strong id="b134587087774322"><a name="b134587087774322"></a><a name="b134587087774322"></a>/firmware/script/version_cap.map</strong> command to view the <strong id="b47632596074322"><a name="b47632596074322"></a><a name="b47632596074322"></a>version_cap.map</strong> file.<div class="note" id="note152221826152320"><a name="note152221826152320"></a><a name="note152221826152320"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p82221726162315"><a name="p82221726162315"></a><a name="p82221726162315"></a>In the preceding commands, <em id="i49287428374322"><a name="i49287428374322"></a><a name="i49287428374322"></a>/usr/local/Ascend</em> is the installation path of the software package. Replace it with the actual path.</p>
    </div></div>
    </li></ul>
    </li></ul>
    </td>
    </tr>
    <tr id="row112219143230"><td class="cellrowborder" rowspan="2" valign="top" width="24.2%" headers="mcps1.2.4.1.1 "><p id="p4973912321"><a name="p4973912321"></a><a name="p4973912321"></a>Switch to the <strong id="b857125510324"><a name="b857125510324"></a><a name="b857125510324"></a>/usr/local/Ascend/firmware/tools</strong> directory before running commands.</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.67%" headers="mcps1.2.4.1.2 "><p id="p1224141234"><a name="p1224141234"></a><a name="p1224141234"></a>Updates the firmware of a specified device:</p>
    <p id="p1622151410230"><a name="p1622151410230"></a><a name="p1622151410230"></a><strong id="b22291420235"><a name="b22291420235"></a><a name="b22291420235"></a>/usr/local/Ascend/driver/tools/upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --path &lt;firmware_path&gt;</strong></p>
    <div class="note" id="note10548711132112"><a name="note10548711132112"></a><a name="note10548711132112"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p262644510316"><a name="p262644510316"></a><a name="p262644510316"></a>This command is supported only on PMs.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" width="35.13%" headers="mcps1.2.4.1.3 "><p id="p1123171414239"><a name="p1123171414239"></a><a name="p1123171414239"></a><strong id="b107341818183312"><a name="b107341818183312"></a><a name="b107341818183312"></a>--path</strong>:</p>
    <p id="p182314141239"><a name="p182314141239"></a><a name="p182314141239"></a>Relative path of the firmware package. To upgrade all components, set this parameter to <strong id="en-us_topic_0000001208601789_b395916233254"><a name="en-us_topic_0000001208601789_b395916233254"></a><a name="en-us_topic_0000001208601789_b395916233254"></a>--path ./conf/upgrade.cfg</strong>. The <strong id="en-us_topic_0000001208601789_b10195346256"><a name="en-us_topic_0000001208601789_b10195346256"></a><a name="en-us_topic_0000001208601789_b10195346256"></a>upgrade.cfg</strong> file contains the relative path of each component.</p>
    <p id="p1231614172315"><a name="p1231614172315"></a><a name="p1231614172315"></a>To upgrade a single component, for example, hilink25, set this parameter to <strong id="b5231514152314"><a name="b5231514152314"></a><a name="b5231514152314"></a>--path ../image/nve.bin</strong>.</p>
    </td>
    </tr>
    <tr id="row2278113414711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1238218114810"><a name="p1238218114810"></a><a name="p1238218114810"></a>Upgrades the firmware package of a specified device in asynchronous mode:</p>
    <p id="p32331412313"><a name="p32331412313"></a><a name="p32331412313"></a><strong id="b142321462312"><a name="b142321462312"></a><a name="b142321462312"></a>/usr/local/Ascend/driver/tools/upgrade-tool --device_index &lt;dev_id&gt; --component &lt;type&gt; --async --path &lt;firmware_path&gt;</strong></p>
    <p id="p323111462319"><a name="p323111462319"></a><a name="p323111462319"></a><strong id="b990056727114335"><a name="b990056727114335"></a><a name="b990056727114335"></a>--async</strong> must follow <strong id="b354030383114335"><a name="b354030383114335"></a><a name="b354030383114335"></a>component &lt;type&gt;</strong>.</p>
    <div class="note" id="note17852194372112"><a name="note17852194372112"></a><a name="note17852194372112"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p38520432216"><a name="p38520432216"></a><a name="p38520432216"></a>This command is supported only on PMs.</p>
    </div></div>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p115801361544"><a name="p115801361544"></a><a name="p115801361544"></a><strong id="b606340725114335"><a name="b606340725114335"></a><a name="b606340725114335"></a>--async</strong>: asynchronous upgrade. That is, after an upgrade request from the host is received, the device returns a success response to the host. To query the upgrade result, use the <strong id="b90208575114335"><a name="b90208575114335"></a><a name="b90208575114335"></a>--status</strong> parameter.</p>
    </td>
    </tr>
    </tbody>
    </table>
