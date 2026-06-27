# Querying Device Monitoring Data

## Function

The  `npu-smi info watch` command is used to query the monitoring data of all devices.

The  `npu-smi info watch -i dev_id` command is used to query the monitoring data of a device.

The  `npu-smi info watch -i dev_id_ -d delay_seconds -s watch_type` command is used to query a device's monitoring data of a specified type.

## Syntax

```bash
npu-smi info watch
npu-smi info watch -i dev_id
npu-smi info watch -i dev_id_ -d delay_seconds -s watch_type
```

## Parameters<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_section57340323212"></a>

<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_table77351332122"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row97901932822"><th class="cellrowborder" valign="top" width="26.240000000000002%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p77902323215"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p77902323215"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p77902323215"></a><strong id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b157494233584"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b157494233584"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b157494233584"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="73.76%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p779013329217"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p779013329217"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p779013329217"></a><strong id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b1493918146584"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b1493918146584"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_b1493918146584"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row127907321923"><td class="cellrowborder" valign="top" width="26.240000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p187909323217"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p187909323217"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p187909323217"></a><span id="ph1688015185301"><a name="ph1688015185301"></a><a name="ph1688015185301"></a><em id="en-us_topic_0000002552580505_i177511300519_4"><a name="en-us_topic_0000002552580505_i177511300519_4"></a><a name="en-us_topic_0000002552580505_i177511300519_4"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="73.76%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
<tr id="row5241104963513"><td class="cellrowborder" valign="top" width="26.240000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p147901832026"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p147901832026"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p147901832026"></a><em id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i479193218211"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i479193218211"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i479193218211"></a>delay_seconds</em></p>
</td>
<td class="cellrowborder" valign="top" width="73.76%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791732925"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791732925"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791732925"></a>Delay of each query operation, in seconds. The value ranges from 1 to 100. The default value is <strong id="b111424171233"><a name="b111424171233"></a><a name="b111424171233"></a>1</strong>.</p>
</td>
</tr>
<tr id="row17264118183614"><td class="cellrowborder" valign="top" width="26.240000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791113213210"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791113213210"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p9791113213210"></a><em id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i879114329211"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i879114329211"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_i879114329211"></a>watch_type</em></p>
</td>
<td class="cellrowborder" valign="top" width="73.76%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p18911747124217"><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p18911747124217"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_p18911747124217"></a>Type of the monitored data. Multiple options can be used together.</p>
<a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_ul1733733195110"></a><a name="en-us_topic_0000001264416757_en-us_topic_0000001242834191_ul1733733195110"></a><ul id="en-us_topic_0000001264416757_en-us_topic_0000001242834191_ul1733733195110"><li><strong id="b1611815188249"><a name="b1611815188249"></a><a name="b1611815188249"></a>p</strong> indicates the power.</li><li><strong id="b1714812332412"><a name="b1714812332412"></a><a name="b1714812332412"></a>t</strong> indicates the temperature.</li><li><strong id="b97321736202420"><a name="b97321736202420"></a><a name="b97321736202420"></a>a</strong> indicates the AI Core usage.</li><li><strong id="b2052840132412"><a name="b2052840132412"></a><a name="b2052840132412"></a>i</strong> indicates the AICPU usage.</li><li><strong id="b4793947122420"><a name="b4793947122420"></a><a name="b4793947122420"></a>c</strong> indicates the Ctrl CPU usage.</li><li><strong id="b20271175162414"><a name="b20271175162414"></a><a name="b20271175162414"></a>m</strong> indicates the memory usage.</li><li><strong id="b193062549246"><a name="b193062549246"></a><a name="b193062549246"></a>b</strong> indicates the memory bandwidth usage.</li><li><strong id="b46871559152412"><a name="b46871559152412"></a><a name="b46871559152412"></a>n</strong> indicates the comprehensive NPU utilization.</li><li><strong id="b149533143257"><a name="b149533143257"></a><a name="b149533143257"></a>u</strong> indicates the AI Cube usage.</li></ul>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_section2106140121613"></a>

This command cannot be used to query AI Core usage \(%\) when profiling is enabled. The return value is  **0**, which has no specific sense.

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

## Example<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_section1674463219214"></a>

- Query the monitoring data of all devices.

    ```bash
    npu-smi info watch
    ```

    ```text
    NpuID(Idx)  Pwr(W)      Temp(C)     AI Core(%)  AI Cpu(%)   Ctrl Cpu(%) Memory(%)   Memory BW(%)   NPU Util(%)    AI Cube(%)
    0           290.4       51          0           0           16          3           0              0              0           
    1           292.1       49          0           0           4           3           0              0              0           
    2           291.2       49          0           0           7           3           0              0              0           
    3           292.1       49          0           0           3           3           0              0              0           
    4           291.5       49          0           0           4           3           0              0              0           
    5           289.5       50          0           0           6           3           0              0              0           
    6           288.5       48          0           0           8           3           0              0              0           
    7           289.3       51          0           0           14          3           0              0              0
    ```

- Query the monitoring data of device 0.

    ```bash
    npu-smi info watch -i 0
    ```

    ```text
    NpuID(Idx)  Pwr(W)      Temp(C)     AI Core(%)  AI Cpu(%)   Ctrl Cpu(%) Memory(%)   Memory BW(%)   NPU Util(%)   AI Cube(%)
    0           280.8       84          0           0           0           3           0              0             0
    0           280.9       84          0           0           0           3           0              0             0
    0           280.8       83          0           0           0           3           0              0             0
    ```

- Query device 0's monitoring data whose type includes  **p**  and  **t**.

    ```bash
    npu-smi info watch -i 0 -d 2 -s pt
    ```

    ```text
    NpuID(Idx)  Pwr(W)      Temp(C) 
    0           280.8       84
    0           280.9       84
    0           280.8       83
    ```

## Output Description<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p36441839191318"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p36441839191318"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p36441839191318"></a>NpuID(Idx)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1164353918134"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1164353918134"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1164353918134"></a><span id="ph3350735193910"><a name="ph3350735193910"></a><a name="ph3350735193910"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p564183915134"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p564183915134"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p564183915134"></a>Pwr(W)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1764083911312"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1764083911312"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1764083911312"></a>Power (unit: W).</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p16392398134"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p16392398134"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p16392398134"></a>Temp(C)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15620139171316"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15620139171316"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15620139171316"></a>Temperature (unit: &deg;C).</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row1974905414175"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p474955418172"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p474955418172"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p474955418172"></a>AI Core(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p274995491710"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p274995491710"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p274995491710"></a>AI Core usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row2255151121710"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p325517512179"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p325517512179"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p325517512179"></a>AI Cpu(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19256205111712"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19256205111712"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19256205111712"></a>AICPU usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row188407465177"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15841546141715"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15841546141715"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p15841546141715"></a>Ctrl Cpu(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p148411146171715"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p148411146171715"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p148411146171715"></a>Ctrl CPU usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row16181524111816"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p018124191815"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p018124191815"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p018124191815"></a>Memory(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19181524121819"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19181524121819"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p19181524121819"></a>On-chip memory usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_row12389428181810"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p10389142820186"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p10389142820186"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p10389142820186"></a>Memory BW(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1838922817180"><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1838922817180"></a><a name="en-us_topic_0000001264656685_en-us_topic_0000001163797121_p1838922817180"></a>On-chip memory bandwidth usage.</p>
</td>
</tr>
<tr id="row16101865119"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p4590122016374"><a name="p4590122016374"></a><a name="p4590122016374"></a>NPU Util(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1759018201377"><a name="p1759018201377"></a><a name="p1759018201377"></a>Comprehensive NPU utilization.</p>
</td>
</tr>
<tr id="row197392052713"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p420924514182"><a name="p420924514182"></a><a name="p420924514182"></a>AI Cube(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p102091045201818"><a name="p102091045201818"></a><a name="p102091045201818"></a>AI Cube usage.</p>
</td>
</tr>
</tbody>
</table>
