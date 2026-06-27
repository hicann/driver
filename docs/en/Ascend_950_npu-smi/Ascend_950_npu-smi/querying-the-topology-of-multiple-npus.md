# Querying the Topology of Multiple NPUs<a name="EN-US_TOPIC_0000002484306776"></a>

## Function<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section1271426121315"></a>

This command is used to query the affinity relationship between CPUs and NPUs and the topology among NPUs.

## Syntax<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section663871213445"></a>

`npu-smi info -t topo`

## Parameters<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section138501410151716"></a>

**Table  1** Support in different deployment scenarios

<a name="table345515356547"></a>
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

## Example<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section77423984414"></a>

Query the affinity relationship between CPUs and NPUs and the topology among NPUs. 

- In the single-card scenario, NPUs are connected through PCIe. The topology is as follows:

    ```bash
    npu-smi info -t topo
    ```

    ```text
    NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          SYS        SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       SYS        X          SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       SYS        SYS        X          SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       SYS        SYS        SYS        X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         SYS       SYS       SYS       64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        SYS       X         SYS       SYS       64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        SYS       SYS       X         SYS       64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        SYS       SYS       SYS       X         64-127,192-255         
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

- In the dual-card interconnect scenario, the two NPUs are connected through UB, and they are connected with other NPUs through PCIe. The topology is as follows:

    ```bash
    npu-smi info -t topo
    ```

    ```text
               NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          UB         SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       UB         X          SYS        SYS        SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       SYS        SYS        X          UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       SYS        SYS        UB         X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         UB        SYS       SYS       64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        UB        X         SYS       SYS       64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        SYS       SYS       X         UB        64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        SYS       SYS       UB        X         64-127,192-255
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

- In the four-card interconnect scenario, the four NPUs are connected through UB, and they are connected with other NPUs through PCIe. The topology is as follows:

    ```bash
    npu-smi info -t topo
    ```

    ```text
               NPU0       NPU1       NPU2       NPU3       NPU4      NPU5      NPU6      NPU7      CPU Affinity
    NPU0       X          UB         UB         UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU1       UB         X          UB         UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU2       UB         UB         X          UB         SYS       SYS       SYS       SYS       0-63,128-191
    NPU3       UB         UB         UB         X          SYS       SYS       SYS       SYS       0-63,128-191
    NPU4       SYS        SYS        SYS        SYS        X         UB        UB        UB        64-127,192-255
    NPU5       SYS        SYS        SYS        SYS        UB        X         UB        UB        64-127,192-255
    NPU6       SYS        SYS        SYS        SYS        UB        UB        X         UB        64-127,192-255
    NPU7       SYS        SYS        SYS        SYS        UB        UB        UB        X         64-127,192-255
    Legend:
      X    = Self
      SYS  = Path traversing PCIe and NUMA nodes. Nodes are connected through SMP, such as QPI, UPI.
      PHB  = Path traversing PCIe and the PCIe host bridge of a CPU.
      PIX  = Path traversing a single PCIe switch.
      PXB  = Path traversing multiple PCIe switches.
      SIO  = Path traversing the SIO bus.
      UB   = Connection traversing UB.
      NA   = Unknown relationship.
    ```

## Output Description<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="42.02%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="57.98%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_row16177103510201"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"></a>NPU<em id="i14259163375019"><a name="i14259163375019"></a><a name="i14259163375019"></a>X</em></p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"></a><em id="i3500154705219"><a name="i3500154705219"></a><a name="i3500154705219"></a>X</em> indicates the logical ID of the software.</p>
</td>
</tr>
<tr id="row1941545717168"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"></a>CPU Affinity</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"></a>CPUs that have affinity relationships with NPUs.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p4642739141315"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p4642739141315"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p4642739141315"></a>X</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p8642123913138"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p8642123913138"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p8642123913138"></a>Topology interconnection of the same NPU.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p564183915134"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p564183915134"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p564183915134"></a>SYS</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1764083911312"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1764083911312"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1764083911312"></a>Topology interconnection between NPUs on different NUMA nodes.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p16392398134"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p16392398134"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p16392398134"></a>PHB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p15620139171316"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p15620139171316"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p15620139171316"></a>Topology interconnection between NPUs on the same NUMA node.</p>
</td>
</tr>
<tr id="row118536113337"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p208541511193316"><a name="p208541511193316"></a><a name="p208541511193316"></a>PIX</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p48541117335"><a name="p48541117335"></a><a name="p48541117335"></a>Topology interconnection between two NPUs connected to the same NUMA node through a PCIe switch.</p>
</td>
</tr>
<tr id="row7107716163315"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p101070167332"><a name="p101070167332"></a><a name="p101070167332"></a>PXB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p210701614338"><a name="p210701614338"></a><a name="p210701614338"></a>Topology interconnection between two NPUs connected to the same NUMA node through multiple PCIe switches.</p>
</td>
</tr>
<tr id="row5761581713"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p677989717"><a name="p677989717"></a><a name="p677989717"></a>SIO</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p134645391257"><a name="p134645391257"></a><a name="p134645391257"></a>Topology interconnection between NPUs in the same module.</p>
</td>
</tr>
<tr id="row1898212263154"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p1798302620155"><a name="p1798302620155"></a><a name="p1798302620155"></a>UB</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p139831326181514"><a name="p139831326181514"></a><a name="p139831326181514"></a>Topology interconnection between two NPUs connected through the UB.</p>
</td>
</tr>
<tr id="row122851220125215"><td class="cellrowborder" valign="top" width="42.02%" headers="mcps1.2.3.1.1 "><p id="p2286132055212"><a name="p2286132055212"></a><a name="p2286132055212"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" width="57.98%" headers="mcps1.2.3.1.2 "><p id="p1828612205522"><a name="p1828612205522"></a><a name="p1828612205522"></a>Unknown topology interconnection.</p>
</td>
</tr>
</tbody>
</table>
