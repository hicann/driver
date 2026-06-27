# FAQ

## Preparing IPMItool

The standard PCIe card reset function in out-of-band mode depends on IPMItool. Download the tool and load the driver in advance.

**Procedure**

1. Download IPMItool.
    - CentOS:  **yum install ipmitool**
    - Ubuntu:  **apt-get install ipmitool**

2. Run the following commands to load the drivers:

    **modprobe ipmi\_si**

    **modprobe ipmi\_devintf**

    **modprobe ipmi\_msghandler**

3. Run the following command to check whether the drivers are successfully loaded:

    **lsmod | grep ipmi**

    If the drivers fail to be loaded, perform step2 to reload them.

    > **NOTE:** 
    > 
    > If the OS is restarted, repeat step2 to step3.

## Querying NPU Service Processes

You can use fuser to query NPU service processes.

**Procedure**

1. Install fuser. For example:
    - CentOS:  **yum install psmisc**
    - Ubuntu:  **apt-get install psmisc**

2. Run the following command to query the service processes of the NPU at the current time:

    **fuser -uv /dev/davinci\* /dev/hisi\_hdc**

    If no command output is displayed, no service process is running.
