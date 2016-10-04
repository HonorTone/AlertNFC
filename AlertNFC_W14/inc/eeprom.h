/*
 * eeprom.h
 *
 *  Created on: 2016-8-19
 *      Author: Administrator
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#define COMMB_UNCONFIG 4
#define COMMB_STARTUP_DELAY 3
#define COMMB_SLEEPING 2
#define COMMB_RUNNING 1
#define COMMB_STOPED 0

#define EE_PRODUCT_ID_NUM 0 //2 BYTE
#define EE_FIRMWARE_V_NUM  2//2 BYTE
#define EE_SOFTWARE_V_NUM  4//2 BYTE
#define EE_MANUFACT_SERI_NUM  6//12 BYTE
#define EE_CUSTOMER_SERI_NUM  18//12 BYTE
#define EE_CUSTOMER_RESET_NUM  30//1 BYTE
#define EE_USERINFOR_CHARACTER  31//1 BYTE
#define EE_EEPROM_SIZE  32//1 BYTE
#define EE_DATAPOINT_COUNT  33//2 BYTE
#define EE_COMMAND_BYTE  35//1 BYTE
#define EE_STARTUP_DELAY  36//2 BYTE
#define EE_MEASURE_INTERVAL  38//2 BYTE
#define EE_CONFIG_OPTION  40//2 BYTE
#define EE_UNIT_START_TIME  42//4 BYTE
#define EE_UNIT_STOP_TIME  46//4 BYTE
#define EE_HIGH_ALARM_TIME  50//4 BYTE
#define EE_LOW_ALARM_TIME  54//4 BYTE
#define EE_ALARM_STATUS  58//1 BYTE
#define EE_HIGHBIN_TEM_TRIP_POINT  59//2 BYTE
#define EE_HIGHBIN_F_COUNTER  61//3 BYTE
#define EE_HIGH_FUNC_LIMIT  64//3 BYTE
#define EE_LOWBIN_TEM_TRIP_POINT  67//2 BYTE
#define EE_LOWBIN_F_COUNTER  69//3 BYTE
#define EE_LOW_FUNC_LIMIT  72//3 BYTE
#define EE_NEWBATTERY_TIME  75//4 BYTE
#define EE_USER_INFO  79//192 BYTE
#define EE_USERINFO_LENTH  171//1 BYTE
#define EE_TEMP_DATA  172//N BYTE



int eepromWriteBytes(unsigned int addr,unsigned char *data,char len);
int eepromReadBytes(unsigned int addr,unsigned char *data,int len);
void eepromWriteDefaut();
void eepromWriteOneByOne(unsigned int addr,unsigned char *data,char len);

#endif /* EEPROM_H_ */
