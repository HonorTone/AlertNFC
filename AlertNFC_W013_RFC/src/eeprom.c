/*
 * eeprom.c
 *
 *  Created on: 2016-8-19
 *      Author: Administrator
 */

#include <i2c_mst.h>
#include "eeprom.h"
#include <port.h>
#include "main.h"
#include "I2C.h"

//写入配置参数
void eepromWriteDefaut()
{
	unsigned int i=0;
	unsigned char data[4]={0};
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	delay_ms(5);
	i=0;
	data[0]=i%256;data[1]=i/256;//低字节在前高字节在后
	eepromWriteOneByOne(EE_PRODUCT_ID_NUM,data,2);//Product ID Number
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_FIRMWARE_V_NUM,data,2);//Firmware Version Number
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_SOFTWARE_V_NUM,data,2);//Software Version Number
	///////////////////////////////////
	i=0x10;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_COMMAND_BYTE,data,1);//Command Byte
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_STARTUP_DELAY,data,2);//Start-up Delay
	i=5;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_MEASURE_INTERVAL,data,2);//Measurement Interval
	//i=5;
	data[0]=0x04;data[1]=0x08;//停止键使能，显示警报图标
	eepromWriteOneByOne(EE_CONFIG_OPTION,data,2);//Configuration Option Bytes
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_ALARM_STATUS,data,1);//Alarm Status Byte
	i=30;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_HIGHBIN_TEM_TRIP_POINT,data,2);//High Bin Temperature Trip Point
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_HIGHBIN_F_COUNTER,data,2);//High Bin Function Counter
	i=1;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_HIGH_FUNC_LIMIT,data,2);//High Function Limit
	i=20;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOWBIN_TEM_TRIP_POINT,data,2);//Low Bin Temperature Trip Point
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOWBIN_F_COUNTER,data,2);//Low Bin Function Counter
	i=2;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOW_FUNC_LIMIT,data,2);//Low Function Limit


	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );

}
void eepromWriteInit(unsigned int ReadAddr,unsigned char data,char len)
{
	int i=0;
	unsigned char da[4]={0};
	da[0]=data;da[1]=data;da[2]=data;da[3]=data;
	for(i=0;i<len;i++)
	{
	    EE_WriteOneByte(ReadAddr,da,4);
	    ReadAddr+=4;
	}
}
//一个一个的写EEPROM
void eepromWriteOneByOne(unsigned int addr,unsigned char *data,char len)
{
	EE_WriteOneByte(addr,data,len);
	/*
    int i=0;
    unsigned char da=0;
    setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
    delay_ms(5);
    for(i=0;i<len;i++)
    {
    	da=data[i];
    	eepromWriteBytes(addr+i,&da,1);
    	delay_ms(5);
    }
    //setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
     */
}

//最多只能一次写入4个字节,PAGE写,如果长度大于4个字节覆盖掉前面写的
//如果为页写方式 ：起始地址必须能被4整除
int eepromWriteBytes(unsigned int addr,unsigned char *data,char len)
{
	int status=0,i;
	unsigned char comm[6]={0,0,0,0,0,0};
	comm[0]=addr/256;
	comm[1]=addr%256;
	if(len>4)len=4;
	//setPortOutputP4x( PORT_NO_PX3, PORT_DATA_HIGH );
	for(i=0;i<len;i++)
	{
		comm[i+2]=data[i];//把要发送的数据复制过来

	}
	status = sendI2cMstData( 0x53, comm, len+2,1 );//发送EEPROM数据地址
	//setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
	return status;
}
int eepromReadBytes(unsigned int addr,unsigned char *data,int len)
{
	EE_ReadOneByte(addr,data,len);
	/*
	int status=0,i;
	unsigned char comm[2]={0,0};
	comm[0]=addr/256;
	comm[1]=addr%256;
	startI2cMst();
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	delay_ms(5);
    //从地址按7位算，也就是bit0~bit7
	status = sendI2cMstData( 0x53, comm, 2 ,0);//发送EEPROM数据地址
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
		return status;
	}
	delay_ms(5);
	status = receiveI2cMstData( 0x53, data, len );//接收数据
	//delay_ms(1);
	/// Check on receive result.
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
		return status;
	}
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
	//stopI2cMst();
	return status;
	*/
}
