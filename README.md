# Boardinfo driver
Notes:  
This driver is only compatible to the devices using a OF driver (Open Firmware) or device-tree. It is incompatible with ACPI-based systems (x86/x64 based Intel and AMD systems)
  
Usage:  
In your device-tree file, add the following:  
```
boardinfo {
    compatible = "custom,boardinfo";
    boardname = "YOUR-BOARD-NAME";
};  
```

Installation:  
In your Linux kernel source, add the following "boardinfo" driver folder, under the "drivers" directory.
Example: `cd linux/ && cd drivers/ && mkdir boardinfo`  

Copy the `boardinfo.c Makefile Kconfig` files into the newly created `boardinfo` folder as seen above.  
Move one directory up from the `boardinfo` folder, so that you are in the `drivers` folder.  
Add the following line to the `Makefile`: `obj-$(CONFIG_BOARDINFO)         += boardinfo/`  
In the same directory, add the following line to the `Kconfig` file, before the `endmenu` compiler directive: `source "drivers/boardinfo/Kconfig"`  

Compile:  
Ensure you have the `CONFIG_BOARDINFO=y` setting added into your device's defconfig.
Compile the Linux kernel as normal.  
