# Boardinfo driver
Notes:  
This driver is only compatible to the devices using a OF driver (Open Firmware) or device-tree. <br>
It is incompatible with ACPI-based systems (x86/x64 based Intel and AMD systems)
  
Usage:<br>
In your device-tree file, add the following:<br>
```
boardinfo {
    compatible = "custom,boardinfo";
    boardname = "YOUR-BOARD-NAME";
};  
```

Installation:<br>
In your Linux kernel source, add the following "boardinfo" driver folder, under the "drivers" directory.<br>
Example: `cd linux/ && cd drivers/ && mkdir boardinfo`<br>
<br>
Copy the `boardinfo.c Makefile Kconfig` files into the newly created `boardinfo` folder as seen above.<br>
Move one directory up from the `boardinfo` folder, so that you are in the `drivers` folder.<br>
Add the following line to the `Makefile`: `obj-$(CONFIG_BOARDINFO)         += boardinfo/`<br>
In the same directory, add the following line to the `Kconfig` file, before the `endmenu` compiler directive: `source "drivers/boardinfo/Kconfig"`<br>
<br>

Compile:<br>
Ensure you have the `CONFIG_BOARDINFO=y` setting added into your device's defconfig.<br>
Compile the Linux kernel as normal.<br>
