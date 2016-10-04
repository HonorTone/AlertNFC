/*
 * lcd.c
 *
 *  Created on: 2016-9-19
 *      Author: Administrator
 */
#include "lcd.h"
#include "lcd4a.h"

void lcdInit()
{
	initLcd4a();
	/// start LCD4A clock.
	StartLcd4aClock();

}
/*
 LCD_ALL_ON       0
 LCD_ALL_OFF      1
 LCD_DISP_NORMAL  2
 LCD_DISP_OFF     4
 */
void setLcdDispMode(unsigned char mode)
{
    switch(mode)
    {
        case LCD_ALL_ON:
        	LCD4DSP_DSPC = (LCD4DSP_DSPC & 0xfc) | 2;
        	break;
        case LCD_ALL_OFF:
        	LCD4DSP_DSPC = (LCD4DSP_DSPC & 0xfc) | 3;
        	break;
        case LCD_DISP_NORMAL:
        	LCD4DSP_DSPC = (LCD4DSP_DSPC & 0xfc) | 1;
        	break;
        case LCD_DISP_OFF:
        	LCD4DSP_DSPC = (LCD4DSP_DSPC & 0xfc) | 0;
        	break;
    }
}
void dispRunTime(unsigned int secends)
{
	unsigned char j=0;
	unsigned int tem=secends%3600;
	unsigned int hour=secends/3600;
	unsigned int minute=tem/60;
	unsigned int second=tem%60;
    //cleanDateBuf(dispAddData,20);
    //cleanDateBuf(dispDelData,20);//先清除待显示数据区域
	clearDigitArea();
	OnOffSingleDisp(0x02,1);

    //显示秒
    tem=second;
    j=tem%10;//显示个位
    dispSegNum(1,j);
    tem/=10;
    if(tem==0)goto step1;//没有要显示的数，返回
    j=tem%10;//显十位
    dispSegNum(2,j);

    step1:

    //显示分
    tem=minute;
    j=tem%10;//显示个位
    dispSegNum(3,j);
    tem/=10;
    if(tem==0)goto step2;//没有要显示的数，返回
    j=tem%10;//显十位
    dispSegNum(3,j);

    step2:

    //显示时
    tem=hour;
    j=tem%10;//显示个位
    dispSegNum(5,j);
    tem/=10;
    if(tem==0)return;//没有要显示的数，返回
    j=tem%10;//显十位
    dispSegNum(6,j);
    tem/=10;
    if(tem==0)return;//没有要显示的数，返回
    j=tem%10;//显百位
    dispSegNum(7,j);
    tem/=10;
    if(tem==0)return;//没有要显示的数，返回
    j=tem%10;//显千位
    dispSegNum(8,j);
    tem/=10;
    if(tem==0)return;//没有要显示的数，返回
    j=tem%10;//显万位
    dispSegNum(9,j);

}
void disp_H_L_Char(unsigned char t)
{
	switch(t)
	{
	    case 1://显示 H
	    	dispAddData[0]=0xAB;dispAddData[1]=0xAC;dispAddData[2]=0xAE;dispAddData[3]=0XAF;dispAddData[4]=0XA3;
	    	dispDelData[0]=0XAA;dispDelData[1]=0XAD;
	    	LcdDisplayChar(dispAddData,5,dispDelData,2);
	    	cleanDateBuf(dispAddData,5);
	    	cleanDateBuf(dispDelData,2);
	    	break;
	    case 0://显示 L
	    	dispAddData[0]=0xAD;dispAddData[1]=0xAE;dispAddData[2]=0xAF;
	    	dispDelData[0]=0XAA;dispDelData[1]=0XAB;dispDelData[2]=0XAC;dispDelData[3]=0XA3;
	    	LcdDisplayChar(dispAddData,3,dispDelData,4);
	    	cleanDateBuf(dispAddData,3);
	    	cleanDateBuf(dispDelData,4);
	    	break;
	}
}
/**************************************************************************
 * G-3 H-4
 * addDataPos代表要增加的显示 delDataPos代表要删除的显示
 **************************************************************************/
void LcdDisplayChar(unsigned char *addDataPos,unsigned char addNum,unsigned char *delDataPos,unsigned char delNum)
{
	int i=0;
	for(i=0;i<delNum;i++)
	{
	    switch(*(delDataPos+i))
	    {
	        case 0x1A:
	            SetLcd4aDisplay1Seg(LCD_1A_SEG,LCD_1A_COM,0);
	            break;
	        case 0x1B:
	            SetLcd4aDisplay1Seg(LCD_1B_SEG,LCD_1B_COM,0);
	            break;
	        case 0x1C:
	            SetLcd4aDisplay1Seg(LCD_1C_SEG,LCD_1C_COM,0);
	            break;
	        case 0x1D:
	            SetLcd4aDisplay1Seg(LCD_1D_SEG,LCD_1D_COM,0);
	            break;
	        case 0x1F:
	            SetLcd4aDisplay1Seg(LCD_1F_SEG,LCD_1F_COM,0);
	            break;
	        case 0x13://对应 1G
	            SetLcd4aDisplay1Seg(LCD_1G_SEG,LCD_1G_COM,0);
	            break;
	        case 0x1E:
	            SetLcd4aDisplay1Seg(LCD_1E_SEG,LCD_1E_COM,0);
	            break;
	        case 0x01://对应S1
	            SetLcd4aDisplay1Seg(LCD_S1_SEG,LCD_S1_COM,0);
	            break;
	        case 0x2A:
	            SetLcd4aDisplay1Seg(LCD_2A_SEG,LCD_2A_COM,0);
	            break;
	        case 0x2B:
	            SetLcd4aDisplay1Seg(LCD_2B_SEG,LCD_2B_COM,0);
	            break;
	        case 0x2C:
	            SetLcd4aDisplay1Seg(LCD_2C_SEG,LCD_2C_COM,0);
	            break;
	        case 0x2D:
	            SetLcd4aDisplay1Seg(LCD_2D_SEG,LCD_2D_COM,0);
	            break;
	        case 0x2F:
	            SetLcd4aDisplay1Seg(LCD_2F_SEG,LCD_2F_COM,0);
	            break;
	        case 0x23://对应 2G
	            SetLcd4aDisplay1Seg(LCD_2G_SEG,LCD_2G_COM,0);
	            break;
	        case 0x2E:
	            SetLcd4aDisplay1Seg(LCD_2E_SEG,LCD_2E_COM,0);
	            break;
	        case 0x02://对应S2
	            SetLcd4aDisplay1Seg(LCD_S2_SEG,LCD_S2_COM,0);
	            break;
	        case 0x3A:
	            SetLcd4aDisplay1Seg(LCD_3A_SEG,LCD_3A_COM,0);
	            break;
	        case 0x3B:
	            SetLcd4aDisplay1Seg(LCD_3B_SEG,LCD_3B_COM,0);
	            break;
	        case 0x3C:
	            SetLcd4aDisplay1Seg(LCD_3C_SEG,LCD_3C_COM,0);
	            break;
	        case 0x3D:
	            SetLcd4aDisplay1Seg(LCD_3D_SEG,LCD_3D_COM,0);
	            break;
	        case 0x3F:
	            SetLcd4aDisplay1Seg(LCD_3F_SEG,LCD_3F_COM,0);
	            break;
	        case 0x33://对应 3G
	            SetLcd4aDisplay1Seg(LCD_3G_SEG,LCD_3G_COM,0);
	            break;
	        case 0x3E:
	            SetLcd4aDisplay1Seg(LCD_3E_SEG,LCD_3E_COM,0);
	            break;
	        case 0x4A:
	            SetLcd4aDisplay1Seg(LCD_4A_SEG,LCD_4A_COM,0);
	            break;
	        case 0x4B:
	            SetLcd4aDisplay1Seg(LCD_4B_SEG,LCD_4B_COM,0);
	            break;
	        case 0x4C:
	            SetLcd4aDisplay1Seg(LCD_4C_SEG,LCD_4C_COM,0);
	            break;
	        case 0x4D:
	            SetLcd4aDisplay1Seg(LCD_4D_SEG,LCD_4D_COM,0);
	            break;
	        case 0x4F:
	            SetLcd4aDisplay1Seg(LCD_4F_SEG,LCD_4F_COM,0);
	            break;
	        case 0x43://对应 4G
	            SetLcd4aDisplay1Seg(LCD_4G_SEG,LCD_4G_COM,0);
	            break;
	        case 0x4E:
	            SetLcd4aDisplay1Seg(LCD_4E_SEG,LCD_4E_COM,0);
	            break;
	        case 0x03://对应S3
	            SetLcd4aDisplay1Seg(LCD_S3_SEG,LCD_S3_COM,0);
	            break;
	        case 0x5A:
	            SetLcd4aDisplay1Seg(LCD_5A_SEG,LCD_5A_COM,0);
	            break;
	        case 0x5B:
	            SetLcd4aDisplay1Seg(LCD_5B_SEG,LCD_5B_COM,0);
	            break;
	        case 0x5C:
	            SetLcd4aDisplay1Seg(LCD_5C_SEG,LCD_5C_COM,0);
	            break;
	        case 0x5D:
	            SetLcd4aDisplay1Seg(LCD_5D_SEG,LCD_5D_COM,0);
	            break;
	        case 0x5F:
	            SetLcd4aDisplay1Seg(LCD_5F_SEG,LCD_5F_COM,0);
	            break;
	        case 0x53://对应 5G
	            SetLcd4aDisplay1Seg(LCD_5G_SEG,LCD_5G_COM,0);
	            break;
	        case 0x5E:
	            SetLcd4aDisplay1Seg(LCD_5E_SEG,LCD_5E_COM,0);
	            break;
	        case 0x04://对应S4
	            SetLcd4aDisplay1Seg(LCD_S4_SEG,LCD_S4_COM,0);
	            break;
	        case 0x6A:
	            SetLcd4aDisplay1Seg(LCD_6A_SEG,LCD_6A_COM,0);
	            break;
	        case 0x6B:
	            SetLcd4aDisplay1Seg(LCD_6B_SEG,LCD_6B_COM,0);
	            break;
	        case 0x6C:
	            SetLcd4aDisplay1Seg(LCD_6C_SEG,LCD_6C_COM,0);
	            break;
	        case 0x6D:
	            SetLcd4aDisplay1Seg(LCD_6D_SEG,LCD_6D_COM,0);
	            break;
	        case 0x6F:
	            SetLcd4aDisplay1Seg(LCD_6F_SEG,LCD_6F_COM,0);
	            break;
	        case 0x63://对应 6G
	            SetLcd4aDisplay1Seg(LCD_6G_SEG,LCD_6G_COM,0);
	            break;
	        case 0x6E:
	            SetLcd4aDisplay1Seg(LCD_6E_SEG,LCD_6E_COM,0);
	            break;
	        case 0x05://对应S5
	            SetLcd4aDisplay1Seg(LCD_S5_SEG,LCD_S5_COM,0);
	            break;
	        case 0x7A:
	            SetLcd4aDisplay1Seg(LCD_7A_SEG,LCD_7A_COM,0);
	            break;
	        case 0x7B:
	            SetLcd4aDisplay1Seg(LCD_7B_SEG,LCD_7B_COM,0);
	            break;
	        case 0x7C:
	            SetLcd4aDisplay1Seg(LCD_7C_SEG,LCD_7C_COM,0);
	            break;
	        case 0x7D:
	            SetLcd4aDisplay1Seg(LCD_7D_SEG,LCD_7D_COM,0);
	            break;
	        case 0x7F:
	            SetLcd4aDisplay1Seg(LCD_7F_SEG,LCD_7F_COM,0);
	            break;
	        case 0x73://对应 7G
	            SetLcd4aDisplay1Seg(LCD_7G_SEG,LCD_7G_COM,0);
	            break;
	        case 0x7E:
	            SetLcd4aDisplay1Seg(LCD_7E_SEG,LCD_7E_COM,0);
	            break;
	        case 0x06://对应S6
	            SetLcd4aDisplay1Seg(LCD_S6_SEG,LCD_S6_COM,0);
	            break;
	        case 0x8A:
	            SetLcd4aDisplay1Seg(LCD_8A_SEG,LCD_8A_COM,0);
	            break;
	        case 0x8B:
	            SetLcd4aDisplay1Seg(LCD_8B_SEG,LCD_8B_COM,0);
	            break;
	        case 0x8C:
	            SetLcd4aDisplay1Seg(LCD_8C_SEG,LCD_8C_COM,0);
	            break;
	        case 0x8D:
	            SetLcd4aDisplay1Seg(LCD_8D_SEG,LCD_8D_COM,0);
	            break;
	        case 0x8F:
	            SetLcd4aDisplay1Seg(LCD_8F_SEG,LCD_8F_COM,0);
	            break;
	        case 0x83://对应 8G
	            SetLcd4aDisplay1Seg(LCD_8G_SEG,LCD_8G_COM,0);
	            break;
	        case 0x8E:
	            SetLcd4aDisplay1Seg(LCD_8E_SEG,LCD_8E_COM,0);
	            break;
	        case 0x07://对应S7
	            SetLcd4aDisplay1Seg(LCD_S7_SEG,LCD_S7_COM,0);
	            break;
	        case 0x9A:
	            SetLcd4aDisplay1Seg(LCD_9A_SEG,LCD_9A_COM,0);
	            break;
	        case 0x9B:
	            SetLcd4aDisplay1Seg(LCD_9B_SEG,LCD_9B_COM,0);
	            break;
	        case 0x9C:
	            SetLcd4aDisplay1Seg(LCD_9C_SEG,LCD_9C_COM,0);
	            break;
	        case 0x9D:
	            SetLcd4aDisplay1Seg(LCD_9D_SEG,LCD_9D_COM,0);
	            break;
	        case 0x9F:
	            SetLcd4aDisplay1Seg(LCD_9F_SEG,LCD_9F_COM,0);
	            break;
	        case 0x93://对应 9G
	            SetLcd4aDisplay1Seg(LCD_9G_SEG,LCD_9G_COM,0);
	            break;
	        case 0x9E:
	            SetLcd4aDisplay1Seg(LCD_9E_SEG,LCD_9E_COM,0);
	            break;
	        case 0x08://对应S8
	            SetLcd4aDisplay1Seg(LCD_S8_SEG,LCD_S8_COM,0);
	            break;
	        case 0x09://对应S9
	            SetLcd4aDisplay1Seg(LCD_S9_SEG,LCD_S9_COM,0);
	            break;
	        case 0x12://对应 S12
	            SetLcd4aDisplay1Seg(LCD_S12_SEG,LCD_S12_COM,0);
	            break;
	        case 0xC3://对应 S13
	            SetLcd4aDisplay1Seg(LCD_S13_SEG,LCD_S13_COM,0);
	            break;
	        case 0x14://对应S14
	            SetLcd4aDisplay1Seg(LCD_S14_SEG,LCD_S14_COM,0);
	            break;
	        case 0x10://对应S10
	            SetLcd4aDisplay1Seg(LCD_S10_SEG,LCD_S10_COM,0);
	            break;
	        case 0x11://对应 S11
	            SetLcd4aDisplay1Seg(LCD_S11_SEG,LCD_S11_COM,0);
	            break;
	        case 0x16://对应 S16
	            SetLcd4aDisplay1Seg(LCD_S16_SEG,LCD_S16_COM,0);
	            break;
	        case 0x15://对应S15
	            SetLcd4aDisplay1Seg(LCD_S15_SEG,LCD_S15_COM,0);
	            break;
	        case 0x17://对应S17
	            SetLcd4aDisplay1Seg(LCD_S17_SEG,LCD_S17_COM,0);
	            break;
	        case 0xAE://对应 10E
	            SetLcd4aDisplay1Seg(LCD_10E_SEG,LCD_10E_COM,0);
	            break;
	        case 0xA3://对应 10G
	            SetLcd4aDisplay1Seg(LCD_10G_SEG,LCD_10G_COM,0);
	            break;
	        case 0xAF://对应10F
	            SetLcd4aDisplay1Seg(LCD_10F_SEG,LCD_10F_COM,0);
	            break;
	        case 0xAD://对应10D
	            SetLcd4aDisplay1Seg(LCD_10D_SEG,LCD_10D_COM,0);
	            break;
	        case 0xAC://对应 10C
	            SetLcd4aDisplay1Seg(LCD_10C_SEG,LCD_10C_COM,0);
	            break;
	        case 0xAB://对应10B
	            SetLcd4aDisplay1Seg(LCD_10B_SEG,LCD_10B_COM,0);
	            break;
	        case 0xAA://对应10A
	            SetLcd4aDisplay1Seg(LCD_10A_SEG,LCD_10A_COM,0);
	            break;
	        case 0x21://对应S21
	            SetLcd4aDisplay1Seg(LCD_S21_SEG,LCD_S21_COM,0);
	            break;
	        case 0x20://对应 S20
	            SetLcd4aDisplay1Seg(LCD_S20_SEG,LCD_S20_COM,0);
	            break;
	        case 0x19://对应S19
	            SetLcd4aDisplay1Seg(LCD_S19_SEG,LCD_S19_COM,0);
	            break;
	        case 0x18://对应S18
	            SetLcd4aDisplay1Seg(LCD_S18_SEG,LCD_S18_COM,0);
	            break;


	        }
		}
	for(i=0;i<addNum;i++)
	{
        switch(*(addDataPos+i))
        {
            case 0x1A:
        	   SetLcd4aDisplay1Seg(LCD_1A_SEG,LCD_1A_COM,1);
        	   break;
        	case 0x1B:
        	    SetLcd4aDisplay1Seg(LCD_1B_SEG,LCD_1B_COM,1);
        	    break;
        	case 0x1C:
        	    SetLcd4aDisplay1Seg(LCD_1C_SEG,LCD_1C_COM,1);
        	    break;
        	case 0x1D:
        	    SetLcd4aDisplay1Seg(LCD_1D_SEG,LCD_1D_COM,1);
        	    break;
        	case 0x1F:
        	    SetLcd4aDisplay1Seg(LCD_1F_SEG,LCD_1F_COM,1);
        	    break;
        	case 0x13://对应 1G
        	    SetLcd4aDisplay1Seg(LCD_1G_SEG,LCD_1G_COM,1);
        	    break;
        	case 0x1E:
        	    SetLcd4aDisplay1Seg(LCD_1E_SEG,LCD_1E_COM,1);
        	    break;
        	case 0x01://对应S1
        	    SetLcd4aDisplay1Seg(LCD_S1_SEG,LCD_S1_COM,1);
        	    break;
        	case 0x2A:
        	    SetLcd4aDisplay1Seg(LCD_2A_SEG,LCD_2A_COM,1);
        	    break;
        	case 0x2B:
        	    SetLcd4aDisplay1Seg(LCD_2B_SEG,LCD_2B_COM,1);
        	    break;
        	case 0x2C:
        	    SetLcd4aDisplay1Seg(LCD_2C_SEG,LCD_2C_COM,1);
        	    break;
        	case 0x2D:
        	    SetLcd4aDisplay1Seg(LCD_2D_SEG,LCD_2D_COM,1);
        	    break;
        	case 0x2F:
        	    SetLcd4aDisplay1Seg(LCD_2F_SEG,LCD_2F_COM,1);
        	    break;
        	case 0x23://对应 2G
        	    SetLcd4aDisplay1Seg(LCD_2G_SEG,LCD_2G_COM,1);
        	    break;
        	case 0x2E:
        	    SetLcd4aDisplay1Seg(LCD_2E_SEG,LCD_2E_COM,1);
        	    break;
        	case 0x02://对应S2
        	    SetLcd4aDisplay1Seg(LCD_S2_SEG,LCD_S2_COM,1);
        	    break;
        	case 0x3A:
        	    SetLcd4aDisplay1Seg(LCD_3A_SEG,LCD_3A_COM,1);
        	    break;
        	case 0x3B:
        	    SetLcd4aDisplay1Seg(LCD_3B_SEG,LCD_3B_COM,1);
        	    break;
        	case 0x3C:
        	    SetLcd4aDisplay1Seg(LCD_3C_SEG,LCD_3C_COM,1);
        	    break;
        	case 0x3D:
        	    SetLcd4aDisplay1Seg(LCD_3D_SEG,LCD_3D_COM,1);
        	    break;
        	case 0x3F:
        	    SetLcd4aDisplay1Seg(LCD_3F_SEG,LCD_3F_COM,1);
        	    break;
        	case 0x33://对应 3G
        	    SetLcd4aDisplay1Seg(LCD_3G_SEG,LCD_3G_COM,1);
        	    break;
        	case 0x3E:
        	    SetLcd4aDisplay1Seg(LCD_3E_SEG,LCD_3E_COM,1);
        	    break;
        	case 0x4A:
        	    SetLcd4aDisplay1Seg(LCD_4A_SEG,LCD_4A_COM,1);
        	    break;
        	case 0x4B:
        	    SetLcd4aDisplay1Seg(LCD_4B_SEG,LCD_4B_COM,1);
        	    break;
        	case 0x4C:
        	    SetLcd4aDisplay1Seg(LCD_4C_SEG,LCD_4C_COM,1);
        	    break;
        	case 0x4D:
        	    SetLcd4aDisplay1Seg(LCD_4D_SEG,LCD_4D_COM,1);
        	    break;
        	case 0x4F:
        	    SetLcd4aDisplay1Seg(LCD_4F_SEG,LCD_4F_COM,1);
        	    break;
        	case 0x43://对应 4G
        	    SetLcd4aDisplay1Seg(LCD_4G_SEG,LCD_4G_COM,1);
        	    break;
        	case 0x4E:
        	    SetLcd4aDisplay1Seg(LCD_4E_SEG,LCD_4E_COM,1);
        	    break;
        	case 0x03://对应S3
        	    SetLcd4aDisplay1Seg(LCD_S3_SEG,LCD_S3_COM,1);
        	    break;
        	case 0x5A:
        	    SetLcd4aDisplay1Seg(LCD_5A_SEG,LCD_5A_COM,1);
        	    break;
        	case 0x5B:
        	    SetLcd4aDisplay1Seg(LCD_5B_SEG,LCD_5B_COM,1);
        	    break;
        	case 0x5C:
        	    SetLcd4aDisplay1Seg(LCD_5C_SEG,LCD_5C_COM,1);
        	    break;
        	case 0x5D:
        	    SetLcd4aDisplay1Seg(LCD_5D_SEG,LCD_5D_COM,1);
        	    break;
        	case 0x5F:
        	    SetLcd4aDisplay1Seg(LCD_5F_SEG,LCD_5F_COM,1);
        	    break;
        	case 0x53://对应 5G
        	    SetLcd4aDisplay1Seg(LCD_5G_SEG,LCD_5G_COM,1);
        	    break;
        	case 0x5E:
        	    SetLcd4aDisplay1Seg(LCD_5E_SEG,LCD_5E_COM,1);
        	    break;
        	case 0x04://对应S4
        	    SetLcd4aDisplay1Seg(LCD_S4_SEG,LCD_S4_COM,1);
        	    break;
        	case 0x6A:
        	    SetLcd4aDisplay1Seg(LCD_6A_SEG,LCD_6A_COM,1);
        	    break;
        	case 0x6B:
        	    SetLcd4aDisplay1Seg(LCD_6B_SEG,LCD_6B_COM,1);
        	    break;
        	case 0x6C:
        	    SetLcd4aDisplay1Seg(LCD_6C_SEG,LCD_6C_COM,1);
        	    break;
        	case 0x6D:
        	    SetLcd4aDisplay1Seg(LCD_6D_SEG,LCD_6D_COM,1);
        	    break;
        	case 0x6F:
        	    SetLcd4aDisplay1Seg(LCD_6F_SEG,LCD_6F_COM,1);
        	    break;
        	case 0x63://对应 6G
        	    SetLcd4aDisplay1Seg(LCD_6G_SEG,LCD_6G_COM,1);
        	    break;
        	case 0x6E:
        	    SetLcd4aDisplay1Seg(LCD_6E_SEG,LCD_6E_COM,1);
        	    break;
        	case 0x05://对应S5
        	    SetLcd4aDisplay1Seg(LCD_S5_SEG,LCD_S5_COM,1);
        	    break;
        	case 0x7A:
        	    SetLcd4aDisplay1Seg(LCD_7A_SEG,LCD_7A_COM,1);
        	    break;
        	case 0x7B:
        	    SetLcd4aDisplay1Seg(LCD_7B_SEG,LCD_7B_COM,1);
        	    break;
        	case 0x7C:
        	    SetLcd4aDisplay1Seg(LCD_7C_SEG,LCD_7C_COM,1);
        	    break;
        	case 0x7D:
        	    SetLcd4aDisplay1Seg(LCD_7D_SEG,LCD_7D_COM,1);
        	    break;
        	case 0x7F:
        	    SetLcd4aDisplay1Seg(LCD_7F_SEG,LCD_7F_COM,1);
        	    break;
        	case 0x73://对应 7G
        	    SetLcd4aDisplay1Seg(LCD_7G_SEG,LCD_7G_COM,1);
        	    break;
        	case 0x7E:
        	    SetLcd4aDisplay1Seg(LCD_7E_SEG,LCD_7E_COM,1);
        	    break;
        	case 0x06://对应S6
        	    SetLcd4aDisplay1Seg(LCD_S6_SEG,LCD_S6_COM,1);
        	    break;
        	case 0x8A:
        	    SetLcd4aDisplay1Seg(LCD_8A_SEG,LCD_8A_COM,1);
        	    break;
        	case 0x8B:
        	    SetLcd4aDisplay1Seg(LCD_8B_SEG,LCD_8B_COM,1);
        	    break;
        	case 0x8C:
        	    SetLcd4aDisplay1Seg(LCD_8C_SEG,LCD_8C_COM,1);
        	    break;
        	case 0x8D:
        	    SetLcd4aDisplay1Seg(LCD_8D_SEG,LCD_8D_COM,1);
        	    break;
        	case 0x8F:
        	    SetLcd4aDisplay1Seg(LCD_8F_SEG,LCD_8F_COM,1);
        	    break;
        	case 0x83://对应 8G
        	    SetLcd4aDisplay1Seg(LCD_8G_SEG,LCD_8G_COM,1);
        	    break;
        	case 0x8E:
        	    SetLcd4aDisplay1Seg(LCD_8E_SEG,LCD_8E_COM,1);
        	    break;
        	case 0x07://对应S7
        	    SetLcd4aDisplay1Seg(LCD_S7_SEG,LCD_S7_COM,1);
        	    break;
        	case 0x9A:
        	    SetLcd4aDisplay1Seg(LCD_9A_SEG,LCD_9A_COM,1);
        	    break;
        	case 0x9B:
        	    SetLcd4aDisplay1Seg(LCD_9B_SEG,LCD_9B_COM,1);
        	    break;
        	case 0x9C:
        	    SetLcd4aDisplay1Seg(LCD_9C_SEG,LCD_9C_COM,1);
        	    break;
        	case 0x9D:
        	    SetLcd4aDisplay1Seg(LCD_9D_SEG,LCD_9D_COM,1);
        	    break;
        	case 0x9F:
        	    SetLcd4aDisplay1Seg(LCD_9F_SEG,LCD_9F_COM,1);
        	    break;
        	case 0x93://对应 9G
        	    SetLcd4aDisplay1Seg(LCD_9G_SEG,LCD_9G_COM,1);
        	    break;
        	case 0x9E:
        	    SetLcd4aDisplay1Seg(LCD_9E_SEG,LCD_9E_COM,1);
        	    break;
        	case 0x08://对应S8
        	    SetLcd4aDisplay1Seg(LCD_S8_SEG,LCD_S8_COM,1);
        	    break;
        	case 0x09://对应S9
        	    SetLcd4aDisplay1Seg(LCD_S9_SEG,LCD_S9_COM,1);
        	    break;
        	case 0x12://对应 S12
        	    SetLcd4aDisplay1Seg(LCD_S12_SEG,LCD_S12_COM,1);
        	    break;
        	case 0xC3://对应 S13
        	    SetLcd4aDisplay1Seg(LCD_S13_SEG,LCD_S13_COM,1);
        	    break;
        	case 0x14://对应S14
        	    SetLcd4aDisplay1Seg(LCD_S14_SEG,LCD_S14_COM,1);
        	    break;
        	case 0x10://对应S10
        	    SetLcd4aDisplay1Seg(LCD_S10_SEG,LCD_S10_COM,1);
        	    break;
        	case 0x11://对应 S11
        	    SetLcd4aDisplay1Seg(LCD_S11_SEG,LCD_S11_COM,1);
        	    break;
        	case 0x16://对应 S16
        	    SetLcd4aDisplay1Seg(LCD_S16_SEG,LCD_S16_COM,1);
        	    break;
        	case 0x15://对应S15
        	    SetLcd4aDisplay1Seg(LCD_S15_SEG,LCD_S15_COM,1);
        	    break;
        	case 0x17://对应S17
        	    SetLcd4aDisplay1Seg(LCD_S17_SEG,LCD_S17_COM,1);
        	    break;
        	case 0xAE://对应 10E
        	    SetLcd4aDisplay1Seg(LCD_10E_SEG,LCD_10E_COM,1);
        	    break;
        	case 0xA3://对应 10G
        	    SetLcd4aDisplay1Seg(LCD_10G_SEG,LCD_10G_COM,1);
        	    break;
        	case 0xAF://对应10F
        	    SetLcd4aDisplay1Seg(LCD_10F_SEG,LCD_10F_COM,1);
        	    break;
        	case 0xAD://对应10D
        	    SetLcd4aDisplay1Seg(LCD_10D_SEG,LCD_10D_COM,1);
        	    break;
        	case 0xAC://对应 10C
        	    SetLcd4aDisplay1Seg(LCD_10C_SEG,LCD_10C_COM,1);
        	    break;
        	case 0xAB://对应10B
        	    SetLcd4aDisplay1Seg(LCD_10B_SEG,LCD_10B_COM,1);
        	    break;
        	case 0xAA://对应10A
        	    SetLcd4aDisplay1Seg(LCD_10A_SEG,LCD_10A_COM,1);
        	    break;
        	case 0x21://对应S21
        	    SetLcd4aDisplay1Seg(LCD_S21_SEG,LCD_S21_COM,1);
        	    break;
        	case 0x20://对应 S20
        	    SetLcd4aDisplay1Seg(LCD_S20_SEG,LCD_S20_COM,1);
        	    break;
        	case 0x19://对应S19
        	    SetLcd4aDisplay1Seg(LCD_S19_SEG,LCD_S19_COM,1);
        	    break;
        	case 0x18://对应S18
        	    SetLcd4aDisplay1Seg(LCD_S18_SEG,LCD_S18_COM,1);
        	    break;

        }
	}
}
/************************************************
 * 函数功能：打开或关闭单个显示位
 * comm==1:显示 comm==0：不显示
 ************************************************/
void OnOffSingleDisp(uchar posVal,uchar comm)//
{
	if(comm==1)
	{
		dispAddData[0]=posVal;
		LcdDisplayChar(dispAddData,1,NULL,0);
		cleanDateBuf(dispAddData,1);
	}
	if(comm==0)
	{
		dispDelData[0]=posVal;
		LcdDisplayChar(NULL,0,dispDelData,1);
		cleanDateBuf(dispDelData,1);
	}
}
void FlashScreen(int gapTime)
{

}
void dispSegNum(unsigned char pos,unsigned char dispNum)
{
	unsigned segA,segB,segC,segD,segE,segF,segG;
	switch(pos)
	{
	    case 1:
	    	segA=0x1A;segB=0x1B;segC=0x1C;segD=0x1D;segE=0x1E;segF=0x1F;segG=0x13;
	    	break;
	    case 2:
	    	segA=0x2A;segB=0x2B;segC=0x2C;segD=0x2D;segE=0x2E;segF=0x2F;segG=0x23;
	    	break;
	    case 3:
	    	segA=0x3A;segB=0x3B;segC=0x3C;segD=0x3D;segE=0x3E;segF=0x3F;segG=0x33;
	    	break;
	    case 4:
	    	segA=0x4A;segB=0x4B;segC=0x4C;segD=0x4D;segE=0x4E;segF=0x4F;segG=0x43;
	    	break;
	    case 5:
	    	segA=0x5A;segB=0x5B;segC=0x5C;segD=0x5D;segE=0x5E;segF=0x5F;segG=0x53;
	    	break;
	    case 6:
	    	segA=0x6A;segB=0x6B;segC=0x6C;segD=0x6D;segE=0x6E;segF=0x6F;segG=0x63;
	    	break;
	    case 7:
	    	segA=0x7A;segB=0x7B;segC=0x7C;segD=0x7D;segE=0x7E;segF=0x7F;segG=0x73;
	    	break;
	    case 8:
	    	segA=0x8A;segB=0x8B;segC=0x8C;segD=0x8D;segE=0x8E;segF=0x8F;segG=0x83;
	    	break;
	    case 9:
	    	segA=0x9A;segB=0x9B;segC=0x9C;segD=0x9D;segE=0x9E;segF=0x9F;segG=0x93;
	    	break;
	    case 10:
	    	segA=0xAA;segB=0xAB;segC=0xAC;segD=0xAD;segE=0xAE;segF=0xAF;segG=0xA3;
	    	break;
	}
	switch(dispNum)
	{
				case 0:
					dispAddData[0]=segA;dispAddData[1]=segB;dispAddData[2]=segC;dispAddData[3]=segD;dispAddData[4]=segE;dispAddData[5]=segF;
					dispDelData[0]=segG;
					LcdDisplayChar(dispAddData,6,dispDelData,1);
					cleanDateBuf(dispAddData,6);
					cleanDateBuf(dispDelData,1);
				    break;
				case 1:
					dispAddData[0]=segB;dispAddData[1]=segC;
					dispDelData[0]=segG;dispDelData[1]=segA;dispDelData[2]=segF;dispDelData[3]=segE;dispDelData[4]=segD;
					LcdDisplayChar(dispAddData,2,dispDelData,5);
					//LcdDisplayChar(dispAddData,2,NULL,0);
					cleanDateBuf(dispAddData,2);
					cleanDateBuf(dispDelData,5);
					break;
				case 2:
					dispAddData[0]=segA;dispAddData[1]=segB;dispAddData[2]=segG;dispAddData[3]=segE;dispAddData[4]=segD;
					dispDelData[0]=segF;dispDelData[1]=segC;
					LcdDisplayChar(dispAddData,5,dispDelData,2);
					cleanDateBuf(dispAddData,5);
					cleanDateBuf(dispDelData,2);
					break;
				case 3:
					dispAddData[0]=segA;dispAddData[1]=segB;dispAddData[2]=segG;dispAddData[3]=segC;dispAddData[4]=segD;
					dispDelData[0]=segF;dispDelData[1]=segE;
					LcdDisplayChar(dispAddData,5,dispDelData,2);
					cleanDateBuf(dispAddData,5);
					cleanDateBuf(dispDelData,2);
					break;
				case 4:
					dispAddData[0]=segF;dispAddData[1]=segG;dispAddData[2]=segB;dispAddData[3]=segC;
					dispDelData[0]=segA;dispDelData[1]=segE;dispDelData[2]=segD;
					LcdDisplayChar(dispAddData,4,dispDelData,3);
					cleanDateBuf(dispAddData,4);
					cleanDateBuf(dispDelData,3);
				    break;
				case 5:
					dispAddData[0]=segA;dispAddData[1]=segF;dispAddData[2]=segG;dispAddData[3]=segD;dispAddData[4]=segC;
					dispDelData[0]=segB;dispDelData[1]=segE;
					LcdDisplayChar(dispAddData,5,dispDelData,2);
					cleanDateBuf(dispAddData,5);
					cleanDateBuf(dispDelData,2);
					break;
				case 6:
					dispAddData[0]=segA;dispAddData[1]=segF;dispAddData[2]=segG;dispAddData[3]=segD;dispAddData[4]=segE;dispAddData[5]=segC;
					dispDelData[0]=segB;
					LcdDisplayChar(dispAddData,6,dispDelData,1);
					cleanDateBuf(dispAddData,6);
					cleanDateBuf(dispDelData,1);
					break;
				case 7:
					dispAddData[0]=segA;dispAddData[1]=segB;dispAddData[2]=segC;
					dispDelData[0]=segG;dispDelData[1]=segF;dispDelData[2]=segE;dispDelData[3]=segD;
					LcdDisplayChar(dispAddData,3,dispDelData,4);
					cleanDateBuf(dispAddData,3);
					cleanDateBuf(dispDelData,4);
					break;
				case 8:
					dispAddData[0]=segA;dispAddData[1]=segF;dispAddData[2]=segE;dispAddData[3]=segD;dispAddData[4]=segC;dispAddData[5]=segB;dispAddData[6]=segG;
					//dispDelData[0]=0X63;
					LcdDisplayChar(dispAddData,7,NULL,0);
					cleanDateBuf(dispAddData,7);
					//cleanDateBuf(dispDelData,1);
					break;
				case 9:
					dispAddData[0]=segA;dispAddData[1]=segF;dispAddData[2]=segG;dispAddData[3]=segD;dispAddData[4]=segC;dispAddData[5]=segB;
					dispDelData[0]=segE;
					LcdDisplayChar(dispAddData,6,dispDelData,1);
					cleanDateBuf(dispAddData,6);
					cleanDateBuf(dispDelData,1);
					break;

    }
}
/**********************************************
 * dispType=1 显示湿度单位
 * dispType=2 显示摄氏C湿度单位
 * dispType=3 显示华氏F湿度单位
 *********************************************/
void dispDigital(float val,uchar dispType)
{
	uchar i;
	float f=val;
    int tem=val;

	//cleanDateBuf(dispAddData,20);
	//cleanDateBuf(dispDelData,20);//先清除待显示数据区域
    clearDigitArea();
	if(dispType==1)//显示湿度单位
	{
		dispAddData[0]=0x07;
		//dispDelData[0]=0X08;dispDelData[1]=0X09;dispDelData[2]=0X10;dispDelData[3]=0X11;
		LcdDisplayChar(dispAddData,1,NULL,0);
		//cleanDateBuf(dispAddData,1);
		//cleanDateBuf(dispDelData,4);
	}
	if(dispType==2)//显示摄氏C湿度单位
	{
		dispAddData[0]=0x08;dispAddData[1]=0x09;dispAddData[2]=0x10;
		//dispDelData[0]=0X11;dispDelData[1]=0X07;
		LcdDisplayChar(dispAddData,3,NULL,0);
		//cleanDateBuf(dispAddData,3);
		//cleanDateBuf(dispDelData,2);
	}
	if(dispType==3)//显示华氏F湿度单位
	{
		dispAddData[0]=0x08;dispAddData[1]=0x09;dispAddData[2]=0x11;
		//dispDelData[0]=0X07;dispDelData[1]=0X10;
		LcdDisplayChar(dispAddData,3,NULL,0);
		//cleanDateBuf(dispAddData,3);
		//cleanDateBuf(dispDelData,2);
	}
	if(tem<0)//处理符号部分
	{
		dispAddData[0]=0x93;//显示+-符号
		LcdDisplayChar(dispAddData,1,NULL,0);

		f=-val;
		tem=f;
        //tem=~tem+1;
        goto DISPD;
	}
	else
	{
		f=val;
		tem=val;
		dispAddData[0]=0x93;//显示+-符号
		LcdDisplayChar(NULL,0,dispAddData,1);

		DISPD:

		dispAddData[0]=0x04;//显示小数点
		LcdDisplayChar(dispAddData,1,NULL,0);
		cleanDateBuf(dispAddData,1);
		f-=tem;//得到小数部分
		i=f*10;//显示小数部分
		dispSegNum(5,i);

		i=tem%10;//取个位
		dispSegNum(6,i);

		tem/=10;
		if(tem==0)return;//判断后面是否还有要显示的数
		i=tem%10;//取十位
		dispSegNum(7,i);

		tem/=10;
		if(tem==0)return;//判断后面是否还有要显示的数
		i=tem%10;//取十位
		if(i>0)
		{
			dispAddData[0]=0x8C;dispAddData[1]=0x8B;
			LcdDisplayChar(dispAddData,2,NULL,0);
			cleanDateBuf(dispAddData,2);
		}
	}
}
void clearDigitArea()
{
	dispDelData[0]=0X9A;dispDelData[1]=0X9B;dispDelData[2]=0X9C;dispDelData[3]=0X9D;dispDelData[4]=0X9E;
	dispDelData[5]=0X9F;dispDelData[6]=0X93;dispDelData[7]=0X8A;dispDelData[8]=0X8B;dispDelData[9]=0X8C;
	dispDelData[10]=0X8D;dispDelData[11]=0X8E;dispDelData[12]=0X8F;dispDelData[13]=0X83;dispDelData[14]=0X7A;
	dispDelData[15]=0X7B;dispDelData[16]=0X7C;dispDelData[17]=0X7D;
	LcdDisplayChar(NULL,0,dispDelData,18);
	//cleanDateBuf(dispDelData,18);
	dispDelData[0]=0X7E;dispDelData[1]=0X7F;dispDelData[2]=0X73;dispDelData[3]=0X05;dispDelData[4]=0X6A;
	dispDelData[5]=0X6B;dispDelData[6]=0X6C;dispDelData[7]=0X6D;dispDelData[8]=0X6E;dispDelData[9]=0X6F;
	dispDelData[10]=0X63;dispDelData[11]=0X04;dispDelData[12]=0X5A;dispDelData[13]=0X5B;dispDelData[14]=0X5C;
	dispDelData[15]=0X5D;dispDelData[16]=0X5E;dispDelData[17]=0X5F;dispDelData[18]=0X53;
	LcdDisplayChar(NULL,0,dispDelData,19);
	//cleanDateBuf(dispDelData,19);
	dispDelData[0]=0X4A;dispDelData[1]=0X4B;dispDelData[2]=0X4C;dispDelData[3]=0X4D;dispDelData[4]=0X4E;
	dispDelData[5]=0X4F;dispDelData[6]=0X43;dispDelData[7]=0X3A;dispDelData[8]=0X3B;dispDelData[9]=0X3C;
	dispDelData[10]=0X3D;dispDelData[11]=0X3E;dispDelData[12]=0X3F;dispDelData[13]=0X33;dispDelData[14]=0X2A;
	dispDelData[15]=0X2B;dispDelData[16]=0X2C;dispDelData[17]=0X2D;dispDelData[18]=0X2E;
	LcdDisplayChar(NULL,0,dispDelData,19);
	dispDelData[0]=0X2F;dispDelData[1]=0X23;dispDelData[2]=0X1A;dispDelData[3]=0X1B;dispDelData[4]=0X1C;
	dispDelData[5]=0X1D;dispDelData[6]=0X1F;dispDelData[7]=0X13;dispDelData[8]=0X02;dispDelData[9]=0X07;
	dispDelData[10]=0X08;dispDelData[11]=0X09;dispDelData[12]=0X10;dispDelData[13]=0X11;dispDelData[14]=0X1E;
	LcdDisplayChar(NULL,0,dispDelData,15);
	//cleanDateBuf(dispDelData,15);
}


