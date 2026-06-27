# Upgrading Firmware<a name="EN-US_TOPIC_0000002484306802"></a>

## Function<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_section18674262006"></a>

This command is used to upgrade firmware.

## Syntax<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_section386902615016"></a>

`npu-smi upgrade -t item -i dev_id -f file_path`

## Parameters<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_section1786919261014"></a>

<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p3985976"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p3985976"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p54428625"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p54428625"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p57396781"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p57396781"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p57396781"></a><span id="ph1593919581467"><a name="ph1593919581467"></a><a name="ph1593919581467"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_row201038418178"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p81048471715"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p81048471715"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p81048471715"></a><em id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i73221932164217"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i73221932164217"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i73221932164217"></a>item</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p4431350161216"><a name="p4431350161216"></a><a name="p4431350161216"></a>Firmware type: <strong id="b1930331375611"><a name="b1930331375611"></a><a name="b1930331375611"></a>vrd</strong></p>
</td>
</tr>
<tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_row11300194934817"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p13300649114810"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p13300649114810"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p13300649114810"></a><em id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i5610100104911"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i5610100104911"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_i5610100104911"></a>file_path</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4818624101716"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4818624101716"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4818624101716"></a>Path of the upgrade file.</p>
<p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p472711121346"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p472711121346"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p472711121346"></a>The file path can contain only letters, digits, underscores (_), periods (.), slashes (/), and hyphens (-).</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_section1882494910505"></a>

- This command does not support concurrent VRD firmware upgrades.
- During the VRD firmware upgrade, do not repeatedly perform the VRD upgrade operation. Otherwise, an upgrade failure message will be returned, but the current VRD firmware upgrade operation will not be affected.
- After the VRD firmware is upgraded, run the  **reboot**  command to reboot the system for the upgrade to take effect. Wait at least 60 seconds, and power off and then power on the DC. Wait until the NPU link is successfully established.

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row8234558115412"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p1423485865414"><a name="en-us_topic_0000002484466758_p1423485865414"></a><a name="en-us_topic_0000002484466758_p1423485865414"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p142341158165418"><a name="en-us_topic_0000002484466758_p142341158165418"></a><a name="en-us_topic_0000002484466758_p142341158165418"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p72341558145414"><a name="en-us_topic_0000002484466758_p72341558145414"></a><a name="en-us_topic_0000002484466758_p72341558145414"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p1823415813540"><a name="en-us_topic_0000002484466758_p1823415813540"></a><a name="en-us_topic_0000002484466758_p1823415813540"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p1123485814542"><a name="en-us_topic_0000002484466758_p1123485814542"></a><a name="en-us_topic_0000002484466758_p1123485814542"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row1723465816543"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p62341588548"><a name="en-us_topic_0000002484466758_p62341588548"></a><a name="en-us_topic_0000002484466758_p62341588548"></a><strong id="en-us_topic_0000002484466758_b1743296197"><a name="en-us_topic_0000002484466758_b1743296197"></a><a name="en-us_topic_0000002484466758_b1743296197"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p42348588545"><a name="en-us_topic_0000002484466758_p42348588545"></a><a name="en-us_topic_0000002484466758_p42348588545"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1311078514"><a name="en-us_topic_0000002484466758_b1311078514"></a><a name="en-us_topic_0000002484466758_b1311078514"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p7234135815412"><a name="en-us_topic_0000002484466758_p7234135815412"></a><a name="en-us_topic_0000002484466758_p7234135815412"></a><strong id="en-us_topic_0000002484466758_b1173464849"><a name="en-us_topic_0000002484466758_b1173464849"></a><a name="en-us_topic_0000002484466758_b1173464849"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p82341458115413"><a name="en-us_topic_0000002484466758_p82341458115413"></a><a name="en-us_topic_0000002484466758_p82341458115413"></a><strong id="en-us_topic_0000002484466758_b25901087"><a name="en-us_topic_0000002484466758_b25901087"></a><a name="en-us_topic_0000002484466758_b25901087"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p4234105820546"><a name="en-us_topic_0000002484466758_p4234105820546"></a><a name="en-us_topic_0000002484466758_p4234105820546"></a><strong id="en-us_topic_0000002484466758_b1807776706"><a name="en-us_topic_0000002484466758_b1807776706"></a><a name="en-us_topic_0000002484466758_b1807776706"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row192341458195412"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p82341958155410"><a name="en-us_topic_0000002484466758_p82341958155410"></a><a name="en-us_topic_0000002484466758_p82341958155410"></a><span id="en-us_topic_0000002484466758_ph162341358185419"><a name="en-us_topic_0000002484466758_ph162341358185419"></a><a name="en-us_topic_0000002484466758_ph162341358185419"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p76802030115811"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p76802030115811"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p76802030115811"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row15236115820544"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p42361458145419"><a name="en-us_topic_0000002484466758_p42361458145419"></a><a name="en-us_topic_0000002484466758_p42361458145419"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_section66051714132117"></a>

Upgrade the VRD firmware on device 0.

```bash
npu-smi upgrade -t vrd -i 0 -f Atlas-A5-hdk-vrd-firmware_xxx.hpm
```

```text
 [WARNING]: Do not power off or restart the system during the upgrade.     
        Transfer                      : success
        Status                        : start to upgrade
Start upgrade [100].                   
        Message                       : Upgrade device success
```

> **NOTE:** 
> 
> Replace  **Atlas-A5-hdk-vrd-firmware\_**_xxx_**.hpm**  with the actual firmware package name.

## Output Description<a name="section195811228122311"></a>

**Table  2**  Description of the displayed information \(VRD upgrade\)

<a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4642739141315"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4642739141315"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p4642739141315"></a>Transfer</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p8642123913138"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p8642123913138"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p8642123913138"></a>Transmission status of the firmware.</p>
<p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p109431713185"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p109431713185"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p109431713185"></a>The value can be <strong id="b166411555174218"><a name="b166411555174218"></a><a name="b166411555174218"></a>Fail</strong> or <strong id="b0641655114210"><a name="b0641655114210"></a><a name="b0641655114210"></a>success</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p564183915134"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p564183915134"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p564183915134"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p1764083911312"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p1764083911312"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p1764083911312"></a>Firmware upgrade status.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p16392398134"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p16392398134"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p16392398134"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p15620139171316"><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p15620139171316"></a><a name="en-us_topic_0000001264656709_en-us_topic_0000001117597252_p15620139171316"></a>Message displayed after the command is executed.</p>
</td>
</tr>
</tbody>
</table>
