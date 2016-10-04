//#include "stm32f10x.h"

#include "I2C.h"
#include <i2c_mst.h>



void EE_WriteOneByte(unsigned int ReadAddr,unsigned char *data,char len)
{
	u8 i=0;
	u8 temp=0;
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	delay_ms(5);
	IIC_Start();
	temp = ( ( 0x53 << 1 ) & 0xFE );
	IIC_Send_Byte(temp);
	IIC_Wait_Ack();
	IIC_Send_Byte(ReadAddr>>8);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
	IIC_Send_Byte(ReadAddr%256);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
	for(i=0;i<len;i++)
	{
		temp=data[i];
	    IIC_Send_Byte(temp);//���͵�ַ���ֽ�
	    IIC_Wait_Ack();
	}
	IIC_Stop();
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
}
//void EE_WriteBlock(unsigned int ReadAddr,unsigned char *data,char len)
//{

//}
void EE_ReadOneByte(uint ReadAddr,uchar *data,uchar len)
{
	u8 i=0;
	u8 temp=0;
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	delay_ms(5);
    IIC_Start();
    temp = ( ( 0x53 << 1 ) & 0xFE );
    IIC_Send_Byte(temp);
	IIC_Wait_Ack();
	IIC_Send_Byte(ReadAddr>>8);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
    IIC_Send_Byte(ReadAddr%256);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
	IIC_Start();
	temp = ( ( 0x53 << 1 ) | 0x01 );
	IIC_Send_Byte(temp);
	IIC_Wait_Ack();
	IIC_Read_Bytes(data,len);
	/*
	for(i=0;i<len;i++)
	{

        if(i<(len-1))temp=IIC_Read_Byte(1);
        else temp=IIC_Read_Byte(0);
        data[i]=temp;

	}
	*/
	IIC_Stop();
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
}
void EE_ReadOneByte1(uchar *data,uchar len)
{
	u8 i=0;
	u8 temp=0;
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_HIGH );
	delay_ms(5);
    IIC_Start();
    temp = ( ( ADDRES_SHTW2 << 1 ) & 0xFE );
    IIC_Send_Byte(temp);
	IIC_Wait_Ack();
	IIC_Send_Byte(0x5c);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
    IIC_Send_Byte(0x24);//���͵�ַ���ֽ�
	IIC_Wait_Ack();
	delay_ms(15);
	IIC_Start();
	temp = ( ( ADDRES_SHTW2 << 1 ) | 0x01 );
	IIC_Send_Byte(temp);
	IIC_Wait_Ack();
	IIC_Read_Bytes(data,len);
	/*
	for(i=0;i<len;i++)
	{

        if(i<(len-1))temp=IIC_Read_Byte(1);
        else temp=IIC_Read_Byte(0);
        data[i]=temp;

	}
	*/
	IIC_Stop();
	setPortOutputP1x( PORT_NO_PX2, PORT_DATA_LOW );
}


void IIC_Init(void)
{
	/// P12 set to the output.
	initPortOutputP0x( PORT_NO_PX3 );//I2C SDA
	/// P12 set the interrupt.
	disablePortIntP0x( PORT_NO_PX3 );
	setPortOutputP0x( PORT_NO_PX3, PORT_DATA_HIGH );

	/// P12 set to the output.
	initPortOutputP0x( PORT_NO_PX2 );//I2C SCL
	/// P12 set the interrupt.
	disablePortIntP0x( PORT_NO_PX2 );
	setPortOutputP0x( PORT_NO_PX2, PORT_DATA_HIGH );

	IIC_SCL_H();
	IIC_SDA_H();

}
//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA_H();
	//delay_us(1);
	asm("nop");
	IIC_SCL_H();
	asm("nop");
	asm("nop");
	asm("nop");
 	IIC_SDA_L();//START:when CLK is high,DATA change form high to low
	//delay_us(3);
 	asm("nop");
 	asm("nop");
	IIC_SCL_L();//ǯסI2C���ߣ�׼�����ͻ��������
}
//����IICֹͣ�ź�
void IIC_Stop(void)
{

	SDA_OUT();//sda�����
	IIC_SDA_L();//STOP:when CLK is high DATA change form low to high
	IIC_SCL_H();
 	//delay_us(3);
	asm("nop");
	asm("nop");
	asm("nop");
	IIC_SDA_H();//����I2C���߽����ź�
	//delay_us(2);
	asm("nop");
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u16 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����
	IIC_SCL_H();//delay_us(4);
	asm("nop");
	asm("nop");
	while(getPortInputP0x(3))
	{
		ucErrTime++;
		if(ucErrTime>1000)
		{
			IIC_Stop();
			return 1;
		}
	}
	//delay_us(2);
	asm("nop");
	asm("nop");
	IIC_SCL_L();//ʱ�����0
	return 0;
}

//����ACKӦ��
void IIC_Ack(void)
{
	IIC_SCL_L();
	SDA_OUT();
	IIC_SDA_L();
	//delay_us(1);
	asm("nop");
	IIC_SCL_H();
	//delay_us(4);
	asm("nop");
	asm("nop");
	asm("nop");
	IIC_SCL_L();
	//delay_us(6);
}
//������ACKӦ��
void IIC_NAck(void)
{
	IIC_SCL_L();
	SDA_OUT();
	IIC_SDA_H();
	//delay_us(1);
	asm("nop");
	IIC_SCL_H();
	//delay_us(4);
	asm("nop");
	asm("nop");
	asm("nop");
	IIC_SCL_L();
	//delay_us(6);
}
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void IIC_Send_Byte(unsigned char txd)
{
  u8 t;
  SDA_OUT();
  IIC_SCL_L();//����ʱ�ӿ�ʼ���ݴ���
  //delay_us(2);
  asm("nop");
  asm("nop");
  for(t=0;t<8;t++)
  {
    if((txd&0x80)>>7)
    {
    	IIC_SDA_H();
    }
    else
    {
        IIC_SDA_L();
    }
    txd<<=1;
	IIC_SCL_H();
	//delay_us(2); 	 //4
	asm("nop");
	asm("nop");
	IIC_SCL_L();
	//delay_us(1);	//4
	asm("nop");
  }
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL_L();
        //delay_us(8);
		//delay_us(2);	//3
        asm("nop");
        asm("nop");
		IIC_SCL_H();
		//delay_us(5);
		asm("nop");
		asm("nop");
		//delay_us(3);	 //5
        receive<<=1;
        if(( P0DAT & ( 0x0001 << 3 ) ))receive++;
		//delay_us(2);
    }
	IIC_SCL_L();
    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK
    return receive;
}
void IIC_Read_Bytes(u8 *revData,u8 readLen)
{
	unsigned char i,j,receive=0;

	for(j=0;j<readLen;j++)
	{
		SDA_IN();//SDA����Ϊ����
        for(i=0;i<8;i++ )
	    {
            IIC_SCL_L();
            //delay_us(8);
		    //delay_us(2);	//3
            asm("nop");
            asm("nop");
		    IIC_SCL_H();
		    //delay_us(5);
		    asm("nop");
		    asm("nop");
		    //delay_us(3);	 //5
            receive<<=1;
            //if(( P0DAT & ( 0x0001 << 3 ) ))receive++;
            if(( P0DAT & 0x0008 ))receive++;
		    //delay_us(2);
        }
        revData[j]=receive;
	    IIC_SCL_L();
	    if(readLen>1)
	    {
	        if(j<(readLen-1))IIC_Ack(); //����ACK
	    	else IIC_NAck();//����nACK
	    }
	    else
	    {
	    	IIC_NAck();//����nACK
	    }
	}


}
/*
//����IIC��ʼ�ź�
void IIC_Start(void)
{
	SDA_OUT();     //sda�����
	IIC_SDA_H();
	delay_us(1);
	IIC_SCL_H();
	delay_us(4);
 	IIC_SDA_L();//START:when CLK is high,DATA change form high to low
	delay_us(3);
	IIC_SCL_L();//ǯסI2C���ߣ�׼�����ͻ��������
}
//����IICֹͣ�ź�
void IIC_Stop(void)
{

	SDA_OUT();//sda�����
	IIC_SDA_L();//STOP:when CLK is high DATA change form low to high
	IIC_SCL_H();
 	delay_us(3);
	IIC_SDA_H();//����I2C���߽����ź�
	delay_us(2);
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(void)
{
	u16 ucErrTime=0;
	SDA_IN();      //SDA����Ϊ����
	IIC_SCL_H();delay_us(4);
	while(getPortInputP0x(3))
	{
		ucErrTime++;
		if(ucErrTime>1000)
		{
			IIC_Stop();
			return 1;
		}
	}
	delay_us(2);
	IIC_SCL_L();//ʱ�����0
	return 0;
}

//����ACKӦ��
void IIC_Ack(void)
{
	IIC_SCL_L();
	SDA_OUT();
	IIC_SDA_L();
	delay_us(1);
	IIC_SCL_H();
	delay_us(4);
	IIC_SCL_L();
	//delay_us(6);
}
//������ACKӦ��
void IIC_NAck(void)
{
	IIC_SCL_L();
	SDA_OUT();
	IIC_SDA_H();
	delay_us(1);
	IIC_SCL_H();
	delay_us(4);
	IIC_SCL_L();
	//delay_us(6);
}
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��
void IIC_Send_Byte(unsigned char txd)
{
  u8 t;
  SDA_OUT();
  IIC_SCL_L();//����ʱ�ӿ�ʼ���ݴ���
  delay_us(2);
  for(t=0;t<8;t++)
  {
    if((txd&0x80)>>7)
    {
    	IIC_SDA_H();
    }
    else
    {
        IIC_SDA_L();
    }
    txd<<=1;
	IIC_SCL_H();
	delay_us(2); 	 //4
	IIC_SCL_L();
	delay_us(1);	//4
  }
}
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
unsigned char IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        IIC_SCL_L();
        //delay_us(8);
		delay_us(2);	//3
		IIC_SCL_H();
		//delay_us(5);
		delay_us(3);	 //5
        receive<<=1;
        if(( P0DAT & ( 0x0001 << 3 ) ))receive++;
		//delay_us(2);
    }
	IIC_SCL_L();
    if (!ack)
        IIC_NAck();//����nACK
    else
        IIC_Ack(); //����ACK
    return receive;
}
*/


