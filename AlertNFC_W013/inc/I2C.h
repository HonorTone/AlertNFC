
#include "main.h"
#include <port.h>
//********************************************************************************


//IO方向设置
#define SDA_IN()  {P0IOEN = ( P0IOEN | ( 0x0100 << 3 ) );P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0001 << 3 ) ) );}//浮空输入
//#define SDA_IN()  {GPIOC->CRH&=0XFFFFFF0F;GPIOC->CRL|=8<<4;}//上拉/ 下拉输入
#define SDA_OUT() {P0IOEN = ( P0IOEN | ( 0x0001 << 3 ) );P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0100 << 3 ) ) );}//推挽输出

//IO操作函数
/*
#define IIC_SCL_H()    P0DAT = ( P0DAT | ( 0x0100 << 2 ) );
#define IIC_SCL_L()    P0DAT = ( P0DAT & ( 0xFFFF ^ ( 0x0100 << 2 ) ) );
#define IIC_SDA_H()    P0DAT = ( P0DAT | ( 0x0100 << 3 ) );
#define IIC_SDA_L()    P0DAT = ( P0DAT & ( 0xFFFF ^ ( 0x0100 << 3 ) ) );
*/
#define IIC_SCL_H()    P0DAT = ( P0DAT | 0x0400 );
#define IIC_SCL_L()    P0DAT = ( P0DAT & 0xfbff );
#define IIC_SDA_H()    P0DAT = ( P0DAT | 0x0800);
#define IIC_SDA_L()    P0DAT = ( P0DAT & 0xf7ff );

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(unsigned char txd);			//IIC发送一个字节
unsigned char IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);
void EE_ReadOneByte(uint ReadAddr,uchar *data,uchar len);
void IIC_Read_Bytes(u8 *revData,u8 readLen);
void EE_WriteOneByte(unsigned int ReadAddr,unsigned char *data,char len);
void EE_ReadOneByte1(uchar *data,uchar len);

