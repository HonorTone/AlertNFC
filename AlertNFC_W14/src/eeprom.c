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

//д�����ò���
void eepromWriteDefaut()
{
	unsigned int i=0;
	unsigned char data[4]={0};
	setPortOutputP4x( PORT_NO_PX3, PORT_DATA_HIGH );
	i=0;
	data[0]=i%256;data[1]=i/256;//���ֽ���ǰ���ֽ��ں�
	eepromWriteOneByOne(EE_PRODUCT_ID_NUM,data,2);//Product ID Number
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_FIRMWARE_V_NUM,data,2);//Firmware Version Number
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_SOFTWARE_V_NUM,data,2);//Software Version Number
	///////////////////////////////////
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_COMMAND_BYTE,data,1);//Command Byte
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_STARTUP_DELAY,data,2);//Start-up Delay
	i=5;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_MEASURE_INTERVAL,data,2);//Measurement Interval
	//i=5;
	data[0]=0x04;data[1]=0x08;//ֹͣ��ʹ�ܣ���ʾ����ͼ��
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
	i=10;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOWBIN_TEM_TRIP_POINT,data,2);//Low Bin Temperature Trip Point
	i=0;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOWBIN_F_COUNTER,data,2);//Low Bin Function Counter
	i=2;
	data[0]=i%256;data[1]=i/256;
	eepromWriteOneByOne(EE_LOW_FUNC_LIMIT,data,2);//Low Function Limit


	setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );

}
//һ��һ����дEEPROM
void eepromWriteOneByOne(unsigned int addr,unsigned char *data,char len)
{
    int i=0;
    unsigned char da=0;
    setPortOutputP4x( PORT_NO_PX3, PORT_DATA_HIGH );
    for(i=0;i<len;i++)
    {
    	da=data[i];
    	eepromWriteBytes(addr+i,&da,1);
    	delay_ms(5);
    }
    setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
}

//���ֻ��һ��д��4���ֽ�,PAGEд,������ȴ���4���ֽڸ��ǵ�ǰ��д��
//���Ϊҳд��ʽ ����ʼ��ַ�����ܱ�4����
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
		comm[i+2]=data[i];//��Ҫ���͵����ݸ��ƹ���

	}
	status = sendI2cMstData( 0x53, comm, len+2 );//����EEPROM���ݵ�ַ
	//setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
	return status;
}
int eepromReadBytes(unsigned int addr,unsigned char *data,int len)
{
	int status=0,i;
	unsigned char comm[2]={0,0};
	comm[0]=addr/256;
	comm[1]=addr%256;
	setPortOutputP4x( PORT_NO_PX3, PORT_DATA_HIGH );
    //�ӵ�ַ��7λ�㣬Ҳ����bit0~bit7
	status = sendI2cMstData( 0x53, comm, 2 );//����EEPROM���ݵ�ַ
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		//setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
		return status;
	}
	status = receiveI2cMstData( 0x53, data, len );//��������

	/// Check on receive result.
	if ( status != I2C_MST_STS_OK )
	{
		/// Stop I2C.
		stopI2cMst();
		//setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
		return status;
	}
	setPortOutputP4x( PORT_NO_PX3, PORT_DATA_LOW );
	return status;
}
