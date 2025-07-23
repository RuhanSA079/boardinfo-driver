# Boardinfo driver
  
Usage:  
In your device-tree file, add the following:  
```
boardinfo {
    compatible = "custom,boardinfo";
    boardname = "YOUR-BOARD-NAME";
};  
```

Compilation:  
Ensure to add this to the Linux kernel sources (tested up to 5.10.y) and enable the CONFIG_BOARDINFO setting
