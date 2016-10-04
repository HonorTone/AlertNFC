
#include "main.h"
#include <port.h>
//********************************************************************************


//IO��������
#define SDA_IN()  {P0IOEN = ( P0IOEN | ( 0x0100 << 3 ) );P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0001 << 3 ) ) );}//��������
//#define SDA_IN()  {GPIOC->CRH&=0XFFFFFF0F;GPIOC->CRL|=8<<4;}//����/ ��������
#define SDA_OUT() {P0IOEN = ( P0IOEN | ( 0x0001 << 3 ) );P0IOEN = ( P0IOEN & ( 0xFFFF ^ ( 0x0100 << 3 ) ) );}//�������

//IO��������
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

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(unsigned char txd);			//IIC����һ���ֽ�
unsigned char IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);
void EE_ReadOneByte(uint ReadAddr,uchar *data,uchar len);
void IIC_Read_Bytes(u8 *revData,u8 readLen);
void EE_WriteOneByte(unsigned int ReadAddr,unsigned char *data,char len);
void EE_ReadOneByte1(uchar *data,uchar len);

