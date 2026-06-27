# Resetting an NPU<a name="EN-US_TOPIC_0000002516426751"></a>

## Function<a name="section1403145042312"></a>

This command is used to reset a device.

## Syntax<a name="section19404195020232"></a>

`npu-smi set -t reset -i dev_id [-m 1]`

## Parameters<a name="section9404185032319"></a>

<a name="table1340414506234"></a>
<table><thead align="left"><tr id="row740515505237"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p140505018236"><a name="p140505018236"></a><a name="p140505018236"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p1840520500237"><a name="p1840520500237"></a><a name="p1840520500237"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1040565012239"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p54051506233"><a name="p54051506233"></a><a name="p54051506233"></a><span id="ph1312861310307"><a name="ph1312861310307"></a><a name="ph1312861310307"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
<tr id="row114064506236"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p12406145012237"><a name="p12406145012237"></a><a name="p12406145012237"></a><strong id="b14406135012234"><a name="b14406135012234"></a><a name="b14406135012234"></a>-m</strong> <strong id="b18406450172315"><a name="b18406450172315"></a><a name="b18406450172315"></a>1</strong></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11406150102320"><a name="p11406150102320"></a><a name="p11406150102320"></a>Optional.</p>
<a name="ul11535133417485"></a><a name="ul11535133417485"></a><ul id="ul11535133417485"><li>If <strong id="b25623303159"><a name="b25623303159"></a><a name="b25623303159"></a>-m</strong> <strong id="b6562230171516"><a name="b6562230171516"></a><a name="b6562230171516"></a>1</strong> is not specified, out-of-band hot reset is performed.</li><li>If <strong id="b1482881021616"><a name="b1482881021616"></a><a name="b1482881021616"></a>-m</strong> <strong id="b88291310161614"><a name="b88291310161614"></a><a name="b88291310161614"></a>1</strong> is specified, in-band hot reset is performed.</li></ul>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="section440685072312"></a>

- Before performing a reset, stop all services on the NPUs.
- When the NPU resets, the network port status changes from UP to DOWN, and the iBMC reports an alarm related to intermittent disconnection of a network port. Once the NPU reset finishes, the port status returns to UP, and the alarm clears.

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row575535820220"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p2075513581623"><a name="en-us_topic_0000002484466758_p2075513581623"></a><a name="en-us_topic_0000002484466758_p2075513581623"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p187555581526"><a name="en-us_topic_0000002484466758_p187555581526"></a><a name="en-us_topic_0000002484466758_p187555581526"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p575595818217"><a name="en-us_topic_0000002484466758_p575595818217"></a><a name="en-us_topic_0000002484466758_p575595818217"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p20755958827"><a name="en-us_topic_0000002484466758_p20755958827"></a><a name="en-us_topic_0000002484466758_p20755958827"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p137556581823"><a name="en-us_topic_0000002484466758_p137556581823"></a><a name="en-us_topic_0000002484466758_p137556581823"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row16755175817215"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p14755105819211"><a name="en-us_topic_0000002484466758_p14755105819211"></a><a name="en-us_topic_0000002484466758_p14755105819211"></a><strong id="en-us_topic_0000002484466758_b468908105"><a name="en-us_topic_0000002484466758_b468908105"></a><a name="en-us_topic_0000002484466758_b468908105"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p37552581224"><a name="en-us_topic_0000002484466758_p37552581224"></a><a name="en-us_topic_0000002484466758_p37552581224"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b2129974698"><a name="en-us_topic_0000002484466758_b2129974698"></a><a name="en-us_topic_0000002484466758_b2129974698"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p1175514581218"><a name="en-us_topic_0000002484466758_p1175514581218"></a><a name="en-us_topic_0000002484466758_p1175514581218"></a><strong id="en-us_topic_0000002484466758_b125546095"><a name="en-us_topic_0000002484466758_b125546095"></a><a name="en-us_topic_0000002484466758_b125546095"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p87554581927"><a name="en-us_topic_0000002484466758_p87554581927"></a><a name="en-us_topic_0000002484466758_p87554581927"></a><strong id="en-us_topic_0000002484466758_b801497737"><a name="en-us_topic_0000002484466758_b801497737"></a><a name="en-us_topic_0000002484466758_b801497737"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p12755175814214"><a name="en-us_topic_0000002484466758_p12755175814214"></a><a name="en-us_topic_0000002484466758_p12755175814214"></a><strong id="en-us_topic_0000002484466758_b98501111112616"><a name="en-us_topic_0000002484466758_b98501111112616"></a><a name="en-us_topic_0000002484466758_b98501111112616"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row175555814213"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p175514581220"><a name="en-us_topic_0000002484466758_p175514581220"></a><a name="en-us_topic_0000002484466758_p175514581220"></a><span id="en-us_topic_0000002484466758_ph07556581225"><a name="en-us_topic_0000002484466758_ph07556581225"></a><a name="en-us_topic_0000002484466758_ph07556581225"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p256471710404"></a>Y (in-band only)</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p45656172402"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p8195141318594"></a>Y (in-band only)</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_en-us_topic_0000002484466758_p7566161714013"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p12943338315"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p12943338315"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_p12943338315"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row17562581328"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p177568581927"><a name="en-us_topic_0000002484466758_p177568581927"></a><a name="en-us_topic_0000002484466758_p177568581927"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section174092507232"></a>

Reset device 0.

```bash
npu-smi set -t reset -i 0 -m 1
```

```text
Resetting the standard PCIe card or NPU chip may cause a system hang or abnormal reset during service running.
Are you sure you want to continue resetting?(Y/N)
y
        Message                        : resetting ...
        Status                         : OK
        Message                        : Reset card successfully.
```

## Output Description<a name="section64091350102318"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p36441839191318"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p36441839191318"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p36441839191318"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p14359124716209"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p14359124716209"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p14359124716209"></a>Reset status.</p>
<p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p1520231621017"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p1520231621017"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p1520231621017"></a>The value can be <strong id="b1840271222918"><a name="b1840271222918"></a><a name="b1840271222918"></a>OK</strong> or <strong id="b164021212152912"><a name="b164021212152912"></a><a name="b164021212152912"></a>Fail</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p4642739141315"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p4642739141315"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p4642739141315"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p8642123913138"><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p8642123913138"></a><a name="en-us_topic_0000001220576462_en-us_topic_0000001117597268_p8642123913138"></a>Reset message.</p>
</td>
</tr>
</tbody>
</table>
