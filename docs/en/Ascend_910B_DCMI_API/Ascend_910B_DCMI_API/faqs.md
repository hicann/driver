# FAQs<a name="EN-US_TOPIC_0000002515503758"></a>

## Preparing IPMItool<a name="EN-US_TOPIC_0000002515503830"></a>

The standard PCIe card reset function in out-of-band mode depends on IPMItool. Download the tool and load the driver in advance.

**Procedure<a name="en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_section12232175417"></a>**

1. Download IPMItool.
    - CentOS:  **yum install ipmitool**
    - Ubuntu:  **apt-get install ipmitool**

2. <a name="en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_li135416108536"></a>Run the following commands to load the drivers:

    **modprobe ipmi\_si**

    **modprobe ipmi\_devintf**

    **modprobe ipmi\_msghandler**

3. <a name="en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_li154541422181820"></a>Run the following command to check whether the drivers are successfully loaded:

    **lsmod | grep ipmi**

    If the drivers fail to be loaded, perform  [2](#en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_li135416108536)  to reload them.

    > **NOTE:** 
    >
    > If the OS is restarted, repeat  [2](#en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_li135416108536)  to  [3](#en-us_topic_0000001206147258_en-us_topic_0000001223172961_en-us_topic_0000001179877623_li154541422181820).

## Querying NPU Service Processes<a name="EN-US_TOPIC_0000002515503814"></a>

You can use fuser to query NPU service processes.

**Procedure<a name="section162691339587"></a>**

1. Install fuser. For example:
    - CentOS:  **yum install psmisc**
    - Ubuntu:  **apt-get install psmisc**

2. Run the following command to query the service processes of the NPU at the current time:

    **fuser -uv /dev/davinci\* /dev/devmm\_svm /dev/hisi\_hdc**

    If no command output is displayed, no service process is running.

## Error Code -8006 Is Returned When the dcmi\_prbs\_operate API Is Called to Perform PRBS Traffic Sending<a name="EN-US_TOPIC_0000002515343912"></a>

**Symptom<a name="section1258661685713"></a>**

When the DCMI API is called to perform PRBS traffic sending, it may return error code  **-8006**. As a result, the PRBS traffic sending function cannot be used.

**Possible Cause<a name="section1186052310578"></a>**

When the PRBS traffic sending function is enabled, the function may fail due to the I2C resource contention failure.

**Solution<a name="section197601727115714"></a>**

When this error code is displayed, re-deliver the PRBS traffic sending command.
