# Command file generated by Gnu17 Plug-in for Eclipse
cd /cygdrive/E/WorkFolder/EPSON_PRJ/AlertNFC

c17 log E:/WorkFolder/EPSON_PRJ/AlertNFC\c17_flash_load.log

# flash program load
file /cygdrive/C/EPSON/GNU17/mcu_model/17W14/fls/fls17W14.elf

# connect to the debugger with specified mode and port
target icd usb

# flash program load
load /cygdrive/C/EPSON/GNU17/mcu_model/17W14/fls/fls17W14.elf

# flash set
c17 fls 0x8000 0x13fff FLASH_ERASE FLASH_LOAD 128

# set the voltage to erase flash
c17 flv 7.5

# flash sector erase
c17 fle 0x8000 0 0

# the end of flash setting
c17 flvs

# load debugging information in program
# file /cygdrive/E/WorkFolder/EPSON_PRJ/AlertNFC/AlertNFC.elf

# set the memory configuration map file to the debugger
c17 rpf /cygdrive/E/WorkFolder/EPSON_PRJ/AlertNFC/AlertNFC_gnu17IDE.par

# connect to the debugger with specified mode and port
target icd usb

# set the voltage to write flash
c17 flv 7.5

# load program to memory
load /cygdrive/E/WorkFolder/EPSON_PRJ/AlertNFC/AlertNFC.psa

# the end of flash setting
c17 flvs

# reset
c17 rst

c17 log