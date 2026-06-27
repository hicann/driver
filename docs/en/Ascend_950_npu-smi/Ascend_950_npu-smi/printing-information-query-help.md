# Printing Information Query Help<a name="EN-US_TOPIC_0000002484466798"></a>

## Function<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section18674262006"></a>

This command is used to display the help information about information query commands.

## Syntax<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section386902615016"></a>

```bash
npu-smi info -h
npu-smi info --help
```

## Parameters<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section2106140121613"></a>

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p5649445717"><a name="en-us_topic_0000002484466758_p5649445717"></a><a name="en-us_topic_0000002484466758_p5649445717"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"></a><strong id="en-us_topic_0000002484466758_b16723134216619"><a name="en-us_topic_0000002484466758_b16723134216619"></a><a name="en-us_topic_0000002484466758_b16723134216619"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1944445364"><a name="en-us_topic_0000002484466758_b1944445364"></a><a name="en-us_topic_0000002484466758_b1944445364"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p116412411579"><a name="en-us_topic_0000002484466758_p116412411579"></a><a name="en-us_topic_0000002484466758_p116412411579"></a><strong id="en-us_topic_0000002484466758_b19691194714618"><a name="en-us_topic_0000002484466758_b19691194714618"></a><a name="en-us_topic_0000002484466758_b19691194714618"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"></a><strong id="en-us_topic_0000002484466758_b5170174915615"><a name="en-us_topic_0000002484466758_b5170174915615"></a><a name="en-us_topic_0000002484466758_b5170174915615"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"></a><strong id="en-us_topic_0000002484466758_b76581504619"><a name="en-us_topic_0000002484466758_b76581504619"></a><a name="en-us_topic_0000002484466758_b76581504619"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row185641517124016"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p144147361596"><a name="en-us_topic_0000002484466758_p144147361596"></a><a name="en-us_topic_0000002484466758_p144147361596"></a><span id="en-us_topic_0000002484466758_ph12140626193614"><a name="en-us_topic_0000002484466758_ph12140626193614"></a><a name="en-us_topic_0000002484466758_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p125931265317"><a name="en-us_topic_0000002484466758_p125931265317"></a><a name="en-us_topic_0000002484466758_p125931265317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p158021256175710"><a name="en-us_topic_0000002484466758_p158021256175710"></a><a name="en-us_topic_0000002484466758_p158021256175710"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row651184316559"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p2194113775312"><a name="en-us_topic_0000002484466758_p2194113775312"></a><a name="en-us_topic_0000002484466758_p2194113775312"></a>Note: <strong id="en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section66051714132117"></a>

Display the help information about information query commands.

```bash
npu-smi info -h
```

```text
Usage: npu-smi info <watch|proc|-h|-m|-l|-t type> [Options...]

Commands:
       watch          Show all device's status in scrolling format
       proc           Show device's matrix process status in scrolling format
       -h, --help     Show this help text and exit
       -m             Show all device's mapping information
       -l             Show all device's topology information
       -t type        Show information for type
                      type: board, common, flash, memory, usages, temp, power, volt, health,
                            current-fault-event, ecc, ecc-enable, sensors, sys-time, key-manage,
                            proc-mem, phyid-remap, topo, spod-info, sio-info, sys-log-info,
                            tls-csr-get, tls-cert, tls-cert-period.

Options:
       -i %d          NPU ID
       -p %d          Chip Physical ID
```

## Output Description<a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="tc10e463d89ce429cbf0a946046ea43fe"></a>
<table><thead align="left"><tr id="rc83a5f731fd64bedae47e4def86f3022"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_row1027145102912"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p827645142916"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p827645142916"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p827645142916"></a>watch</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p72716456297"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p72716456297"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p72716456297"></a>Displays device monitoring information.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_row189361242172917"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p3936194222914"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p3936194222914"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p3936194222914"></a>proc</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_p155420954015"><a name="en-us_topic_0000001459363253_p155420954015"></a><a name="en-us_topic_0000001459363253_p155420954015"></a>Displays the monitoring data of the Matrix process of a chip.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a>-h</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"><a name="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a>Displays the help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"><a name="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a>Displays the help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_p77950499337"><a name="en-us_topic_0000001459363253_p77950499337"></a><a name="en-us_topic_0000001459363253_p77950499337"></a>Displays the mapping information of all chips.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p16392398134"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p16392398134"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p16392398134"></a>-l</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_p1315015510338"><a name="en-us_topic_0000001459363253_p1315015510338"></a><a name="en-us_topic_0000001459363253_p1315015510338"></a>Displays all NPUs.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row8932111419508"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p1389113410304"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p1389113410304"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p1389113410304"></a>-t type</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p611995314338"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p611995314338"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_p611995314338"></a>Displays the type of the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row115212416509"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p13153441155011"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p13153441155011"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p13153441155011"></a>-i %d</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"></a><a name="en-us_topic_0000001459363253_en-us_topic_0000001458106929_en-us_topic_0000001457539217_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>Logical ID of the software</span>, that is, the value of <em id="i19219113124110"><a name="i19219113124110"></a><a name="i19219113124110"></a>X</em> in <strong id="b1279682912374"><a name="b1279682912374"></a><a name="b1279682912374"></a>/dev/davinci</strong><em id="i1292613717552"><a name="i1292613717552"></a><a name="i1292613717552"></a>X</em> on the OS.</p>
</td>
</tr>
<tr id="row2057592915019"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p2575229502"><a name="p2575229502"></a><a name="p2575229502"></a>-p %d</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p45756299013"><a name="p45756299013"></a><a name="p45756299013"></a>Physical chip ID.</p>
</td>
</tr>
</tbody>
</table>
