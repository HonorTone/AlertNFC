/****************************************************************************
 *
 * @file	lcd8b.c
 * @brief	This is LCD8B driver program file for S1C17W14/W16.
 *
 * @par		Copyright:
 *			Copyright (C) SEIKO EPSON CORPORATION 2015-5015. All rights reserved.
 *
 * @warning -
 *
 * @par		History:
 *			- 09 APR, 2015	1.00
 *				- First revision.
 *
 ***************************************************************************/

#include "lcd8b.h"
#include "main.h"

/* --- function declaration --- */

static void initLcd8bSegRam(void);
static void initLcd8bMode(void);
static void initLcd8bPort(void);
void ClrLcd8bIntFlg( void );


/* --- definition of constants --- */
static const unsigned char	DOT_DATA[] = {
	0x01, 0x02, 0x04, 0x08,
	0x10, 0x20, 0x40, 0x80
};

/* --- global variable --- */

/****************************************************************************
 * initLcd8b function.
 *
 * @brief	This function initializes LCD8B driver.
 ***************************************************************************/
void initLcd8b( void )
{
	initLcd8bSegRam();		/// Initialize RAM of LCD Panel.
	initLcd8bMode();		/// initialize LCD Driver.
	//initLcd8bPort();		/// initialize port used with LCD8B.
}


/****************************************************************************
 * onLcd8bDisplay function.
 *
 * @brief	The display turn on.
 ***************************************************************************/
void onLcd8bDisplay( void )
{
	LCD8CTL_MODEN	= 1;	/// Enable LCD8B.
	LCD8DSP_DSPC	= 1;	/// The LCD8B display state set to "normal display".
}


/****************************************************************************
 * offLcd8bDisplay function.
 *
 * @brief	The display turn off.
 ***************************************************************************/
void offLcd8bDisplay( void )
{
	LCD8DSP_DSPC	= 0;	/// The LCD8B display state set to "display off".
	LCD8CTL_MODEN	= 0;	/// Disable LCD8B.
}


/****************************************************************************
 * setLcd8bDisplayState function.
 *
 * @brief	This function changes LCD8B driver's state.
 *
 * @param	state
 *	@li @c		LCD8B_STATE_ALL_OFF		Mode : All off.
 *	@li @c		LCD8B_STATE_ALL_ON		Mode : All on.
 *	@li @c		LCD8B_STATE_NORMAL		Mode : Normal display.
 *	@li @c		LCD8B_STATE_OFF			Mode : Display off.
 ***************************************************************************/
void setLcd8bDisplayState( unsigned char state )
{
	LCD8DSP_DSPC = state;	/// The LCD8B display state set.
}


/****************************************************************************
 * getLcd8bDisplayState function.
 *
 * @brief	This function gets LCD8B driver's state.
 *
 * @retval		LCD8B_STATE_ALL_OFF		Mode : All off.
 * @retval		LCD8B_STATE_ALL_ON		Mode : All on.
 * @retval		LCD8B_STATE_NORMAL		Mode : Normal display.
 * @retval		LCD8B_STATE_OFF			Mode : Display off.
 ***************************************************************************/
unsigned char getLcd8bDisplayState( void )
{
	return ( (unsigned char)LCD8DSP_DSPC );
}


/****************************************************************************
 * SetLCDDisplay1Seg function.
 *
 * @brief	This function display 1 dot of LCD.
 *
 * @param	*seg
 *	@li @c		LCD_SEG00-53	SEG00-53	/// S1C17W14
 *	@li @c		LCD_SEG00-59	SEG00-59	/// S1C17W16
 * @param	com
 *	@li @c		LCD_COM00	COM00
 *	@li @c		LCD_COM01	COM01
 *	@li @c		LCD_COM02	COM02
 *	@li @c		LCD_COM03	COM03
 *	@li @c		LCD_COM04	COM04
 *	@li @c		LCD_COM05	COM05
 *	@li @c		LCD_COM06	COM06
 *	@li @c		LCD_COM07	COM07
 * @param	data
 *	@li @c		LCD_DATA_TURNOFF	LCD Data Turn off
 *	@li @c		LCD_DATA_TURNON		LCD Data Turn on
 *
 * @retval	LCD_SET_NG		Failed.
 * @retval	LCD_SET_OK		Success.
 ***************************************************************************/
int SetLcd8bDisplay1Seg( unsigned char seg, unsigned char com, unsigned char data )
{
	unsigned char *lcdram;
	unsigned char tem;
	/// Parameter Check
	if( data > 1){
		return LCD_SET_NG;
	}

	lcdram = LCD8B_SEGRAM_TOP_ADDR + seg;
	if(data == 1){

		//unsigned char num;

		//for( lcdram = (unsigned char*)LCD8B_SEGRAM_TOP_ADDR ; lcdram <= (LCD8B_SEGRAM_TOP_ADDR + seg) ; lcdram++){
		//lcdram = LCD8B_SEGRAM_TOP_ADDR + seg;
		*lcdram|=DOT_DATA[com];//一个SEG对应一个显示字节 bit0~bit8对应COM0~COM8。想让哪个COM上的点亮就让哪个BIT为1
			/*for(num = 0; num <= com; num++){
				*lcdram |= data * DOT_DATA[num];
			}*/

		//}
	} else {
		//for( lcdram = (unsigned char*)LCD8B_SEGRAM_TOP_ADDR ; lcdram <= (LCD8B_SEGRAM_TOP_ADDR + seg) ; lcdram++){
			//*lcdram = data;
		     tem= *lcdram;

		     *lcdram = tem&(~DOT_DATA[com]);//只改变相应的COM位
		//}
	}

	return LCD_SET_OK;
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
	            	SetLcd8bDisplay1Seg(LCD_1A_SEG,LCD_1A_COM,0);
	            	break;
	            case 0x1B:
	                SetLcd8bDisplay1Seg(LCD_1B_SEG,LCD_1B_COM,0);
	                break;
	            case 0x1C:
	                SetLcd8bDisplay1Seg(LCD_1C_SEG,LCD_1C_COM,0);
	                break;
	            case 0x2A:
	                SetLcd8bDisplay1Seg(LCD_2A_SEG,LCD_2A_COM,0);
	                break;
	            case 0x2B:
	                SetLcd8bDisplay1Seg(LCD_2B_SEG,LCD_2B_COM,0);
	                break;
	            case 0x2C:
	                SetLcd8bDisplay1Seg(LCD_2C_SEG,LCD_2C_COM,0);
	                break;
	            case 0x3A:
	                SetLcd8bDisplay1Seg(LCD_3A_SEG,LCD_3A_COM,0);
	                break;
	            case 0x3B:
	                SetLcd8bDisplay1Seg(LCD_3B_SEG,LCD_3B_COM,0);
	                break;
	            case 0x3C:
	                SetLcd8bDisplay1Seg(LCD_3C_SEG,LCD_3C_COM,0);
	                break;
	            case 0x4A:
	                SetLcd8bDisplay1Seg(LCD_4A_SEG,LCD_4A_COM,0);
	                break;
	            case 0x4B:
	                SetLcd8bDisplay1Seg(LCD_4B_SEG,LCD_4B_COM,0);
	                break;
	            case 0x4C:
	                SetLcd8bDisplay1Seg(LCD_4C_SEG,LCD_4C_COM,0);
	                break;
	            case 0x4D:
	                SetLcd8bDisplay1Seg(LCD_4D_SEG,LCD_4D_COM,0);
	                break;
	            case 0x5E:
	                SetLcd8bDisplay1Seg(LCD_5E_SEG,LCD_5E_COM,0);
	                break;
	            case 0x5F:
	                SetLcd8bDisplay1Seg(LCD_5F_SEG,LCD_5F_COM,0);
	                break;
	            case 0x5A:
	                SetLcd8bDisplay1Seg(LCD_5A_SEG,LCD_5A_COM,0);
	                break;
	            case 0x54://对应5H
	                SetLcd8bDisplay1Seg(LCD_5H_SEG,LCD_5H_COM,0);
	                 break;
	            case 0x5D:
	                SetLcd8bDisplay1Seg(LCD_5D_SEG,LCD_5D_COM,0);
	                break;
	            case 0x5C:
	                SetLcd8bDisplay1Seg(LCD_5C_SEG,LCD_5C_COM,0);
	                break;
	            case 0x53://对应5G
	                SetLcd8bDisplay1Seg(LCD_5G_SEG,LCD_5G_COM,0);
	                break;
	            case 0x5B:
	                SetLcd8bDisplay1Seg(LCD_5B_SEG,LCD_5B_COM,0);
	                break;
	            case 0x6F:
	                SetLcd8bDisplay1Seg(LCD_6F_SEG,LCD_6F_COM,0);
	                break;
	            case 0x6A:
	                SetLcd8bDisplay1Seg(LCD_6A_SEG,LCD_6A_COM,0);
	                break;
	            case 0x6E:
	                SetLcd8bDisplay1Seg(LCD_6E_SEG,LCD_6E_COM,0);
	                break;
	            case 0x63://对应6G
	                SetLcd8bDisplay1Seg(LCD_6G_SEG,LCD_6G_COM,0);
	                break;
	            case 0x6B:
	                SetLcd8bDisplay1Seg(LCD_6B_SEG,LCD_6B_COM,0);
	                break;
	            case 0x8A:
	                SetLcd8bDisplay1Seg(LCD_8A_SEG,LCD_8A_COM,0);
	                break;
	            case 0x6D:
	                SetLcd8bDisplay1Seg(LCD_6D_SEG,LCD_6D_COM,0);
	                break;
	            case 0x6C:
	                SetLcd8bDisplay1Seg(LCD_6C_SEG,LCD_6C_COM,0);
	                break;
	            case 0x8B:
	                SetLcd8bDisplay1Seg(LCD_8B_SEG,LCD_8B_COM,0);
	                break;
	            case 0x7F:
	                SetLcd8bDisplay1Seg(LCD_7F_SEG,LCD_7F_COM,0);
	                break;
	            case 0x7A:
	                SetLcd8bDisplay1Seg(LCD_7A_SEG,LCD_7A_COM,0);
	                break;
	            case 0x7E:
	                SetLcd8bDisplay1Seg(LCD_7E_SEG,LCD_7E_COM,0);
	                break;
	            case 0x73://对应7G
	                SetLcd8bDisplay1Seg(LCD_7G_SEG,LCD_7G_COM,0);
	                break;
	            case 0x7B:
	                SetLcd8bDisplay1Seg(LCD_7B_SEG,LCD_7B_COM,0);
	                break;
	            case 0x7D:
	                SetLcd8bDisplay1Seg(LCD_7D_SEG,LCD_7D_COM,0);
	                break;
	            case 0x7C:
	                SetLcd8bDisplay1Seg(LCD_7C_SEG,LCD_7C_COM,0);
	                break;
	            case 0x8C:
	                SetLcd8bDisplay1Seg(LCD_8C_SEG,LCD_8C_COM,0);
	                break;
	            case 0x8D:
	                SetLcd8bDisplay1Seg(LCD_8D_SEG,LCD_8D_COM,0);
	                break;
	            case 0x9C:
	                SetLcd8bDisplay1Seg(LCD_9C_SEG,LCD_9C_COM,0);
	                break;
	            case 0x9B:
	                SetLcd8bDisplay1Seg(LCD_9B_SEG,LCD_9B_COM,0);
	                break;
	            case 0x9E:
	                SetLcd8bDisplay1Seg(LCD_9E_SEG,LCD_9E_COM,0);
	                break;
	            case 0x9A:
	                SetLcd8bDisplay1Seg(LCD_9A_SEG,LCD_9A_COM,0);
	                break;
	            case 0x9D:
	                SetLcd8bDisplay1Seg(LCD_9D_SEG,LCD_9D_COM,0);
	                break;

	        }
		}
	for(i=0;i<addNum;i++)
	{
        switch(*(addDataPos+i))
        {
            case 0x1A:
            	SetLcd8bDisplay1Seg(LCD_1A_SEG,LCD_1A_COM,1);
            	break;
            case 0x1B:
                SetLcd8bDisplay1Seg(LCD_1B_SEG,LCD_1B_COM,1);
                break;
            case 0x1C:
                SetLcd8bDisplay1Seg(LCD_1C_SEG,LCD_1C_COM,1);
                break;
            case 0x2A:
                SetLcd8bDisplay1Seg(LCD_2A_SEG,LCD_2A_COM,1);
                break;
            case 0x2B:
                SetLcd8bDisplay1Seg(LCD_2B_SEG,LCD_2B_COM,1);
                break;
            case 0x2C:
                SetLcd8bDisplay1Seg(LCD_2C_SEG,LCD_2C_COM,1);
                break;
            case 0x3A:
                SetLcd8bDisplay1Seg(LCD_3A_SEG,LCD_3A_COM,1);
                break;
            case 0x3B:
                SetLcd8bDisplay1Seg(LCD_3B_SEG,LCD_3B_COM,1);
                break;
            case 0x3C:
                SetLcd8bDisplay1Seg(LCD_3C_SEG,LCD_3C_COM,1);
                break;
            case 0x4A:
                SetLcd8bDisplay1Seg(LCD_4A_SEG,LCD_4A_COM,1);
                break;
            case 0x4B:
                SetLcd8bDisplay1Seg(LCD_4B_SEG,LCD_4B_COM,1);
                break;
            case 0x4C:
                SetLcd8bDisplay1Seg(LCD_4C_SEG,LCD_4C_COM,1);
                break;
            case 0x4D:
                SetLcd8bDisplay1Seg(LCD_4D_SEG,LCD_4D_COM,1);
                break;
            case 0x5E:
                SetLcd8bDisplay1Seg(LCD_5E_SEG,LCD_5E_COM,1);
                break;
            case 0x5F:
                SetLcd8bDisplay1Seg(LCD_5F_SEG,LCD_5F_COM,1);
                break;
            case 0x5A:
                SetLcd8bDisplay1Seg(LCD_5A_SEG,LCD_5A_COM,1);
                break;
            case 0x54://对应5H
                SetLcd8bDisplay1Seg(LCD_5H_SEG,LCD_5H_COM,1);
                 break;
            case 0x5D:
                SetLcd8bDisplay1Seg(LCD_5D_SEG,LCD_5D_COM,1);
                break;
            case 0x5C:
                SetLcd8bDisplay1Seg(LCD_5C_SEG,LCD_5C_COM,1);
                break;
            case 0x53://对应5G
                SetLcd8bDisplay1Seg(LCD_5G_SEG,LCD_5G_COM,1);
                break;
            case 0x5B:
                SetLcd8bDisplay1Seg(LCD_5B_SEG,LCD_5B_COM,1);
                break;
            case 0x6F:
                SetLcd8bDisplay1Seg(LCD_6F_SEG,LCD_6F_COM,1);
                break;
            case 0x6A:
                SetLcd8bDisplay1Seg(LCD_6A_SEG,LCD_6A_COM,1);
                break;
            case 0x6E:
                SetLcd8bDisplay1Seg(LCD_6E_SEG,LCD_6E_COM,1);
                break;
            case 0x63://对应6G
                SetLcd8bDisplay1Seg(LCD_6G_SEG,LCD_6G_COM,1);
                break;
            case 0x6B:
                SetLcd8bDisplay1Seg(LCD_6B_SEG,LCD_6B_COM,1);
                break;
            case 0x8A:
                SetLcd8bDisplay1Seg(LCD_8A_SEG,LCD_8A_COM,1);
                break;
            case 0x6D:
                SetLcd8bDisplay1Seg(LCD_6D_SEG,LCD_6D_COM,1);
                break;
            case 0x6C:
                SetLcd8bDisplay1Seg(LCD_6C_SEG,LCD_6C_COM,1);
                break;
            case 0x8B:
                SetLcd8bDisplay1Seg(LCD_8B_SEG,LCD_8B_COM,1);
                break;
            case 0x7F:
                SetLcd8bDisplay1Seg(LCD_7F_SEG,LCD_7F_COM,1);
                break;
            case 0x7A:
                SetLcd8bDisplay1Seg(LCD_7A_SEG,LCD_7A_COM,1);
                break;
            case 0x7E:
                SetLcd8bDisplay1Seg(LCD_7E_SEG,LCD_7E_COM,1);
                break;
            case 0x73://对应7G
                SetLcd8bDisplay1Seg(LCD_7G_SEG,LCD_7G_COM,1);
                break;
            case 0x7B:
                SetLcd8bDisplay1Seg(LCD_7B_SEG,LCD_7B_COM,1);
                break;
            case 0x7D:
                SetLcd8bDisplay1Seg(LCD_7D_SEG,LCD_7D_COM,1);
                break;
            case 0x7C:
                SetLcd8bDisplay1Seg(LCD_7C_SEG,LCD_7C_COM,1);
                break;
            case 0x8C:
                SetLcd8bDisplay1Seg(LCD_8C_SEG,LCD_8C_COM,1);
                break;
            case 0x8D:
                SetLcd8bDisplay1Seg(LCD_8D_SEG,LCD_8D_COM,1);
                break;
            case 0x9C:
                SetLcd8bDisplay1Seg(LCD_9C_SEG,LCD_9C_COM,1);
                break;
            case 0x9B:
                SetLcd8bDisplay1Seg(LCD_9B_SEG,LCD_9B_COM,1);
                break;
            case 0x9E:
                SetLcd8bDisplay1Seg(LCD_9E_SEG,LCD_9E_COM,1);
                break;
            case 0x9A:
                SetLcd8bDisplay1Seg(LCD_9A_SEG,LCD_9A_COM,1);
                break;
            case 0x9D:
                SetLcd8bDisplay1Seg(LCD_9D_SEG,LCD_9D_COM,1);
                break;

        }
	}
}
/************************************************
 * 函数功能：打开或关闭单个显示位
 * comm==1:显示 comm==0：不显示
 ************************************************/
void OnOffSingleDisp(uchar type,uchar comm)//
{
	if(comm==1)
	{
		dispAddData[0]=type;
		LcdDisplayChar(dispAddData,1,NULL,0);
		cleanDateBuf(dispAddData,1);
	}
	if(comm==0)
	{
		dispDelData[0]=type;
		LcdDisplayChar(NULL,0,dispDelData,1);
		cleanDateBuf(dispDelData,1);
	}
}
void FlashScreen(int gapTime)
{

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

	cleanDateBuf(dispAddData,20);
	cleanDateBuf(dispDelData,20);
	dispDelData[0]=0X4C;dispDelData[1]=0X4B;dispDelData[2]=0X5A;dispDelData[3]=0X5F;dispDelData[4]=0X5B;
	dispDelData[5]=0X53;dispDelData[6]=0X5E;dispDelData[7]=0X5D;dispDelData[8]=0X5C;dispDelData[9]=0X6A;
	dispDelData[10]=0X6F;dispDelData[11]=0X63;dispDelData[12]=0X6B;dispDelData[13]=0X6E;dispDelData[14]=0X6D;
	dispDelData[15]=0X6C;dispDelData[16]=0X8B;
	LcdDisplayChar(NULL,0,dispDelData,17);
	cleanDateBuf(dispDelData,17);
	dispDelData[0]=0X7A;dispDelData[1]=0X7F;dispDelData[2]=0X7B;dispDelData[3]=0X73;dispDelData[4]=0X7E;
	dispDelData[5]=0X7C;dispDelData[6]=0X7D;
	LcdDisplayChar(NULL,0,dispDelData,7);
	cleanDateBuf(dispDelData,7);
	if(dispType==1)//显示湿度单位
	{
		dispAddData[0]=0x1C;
		dispDelData[0]=0X8C;dispDelData[1]=0X9A;dispDelData[2]=0X9B;dispDelData[3]=0X9C;
		LcdDisplayChar(dispAddData,1,dispDelData,4);
		cleanDateBuf(dispAddData,1);
		cleanDateBuf(dispDelData,4);
	}
	if(dispType==2)//显示摄氏C湿度单位
	{
		dispAddData[0]=0x8C;dispAddData[1]=0x9A;dispAddData[2]=0x9C;
		dispDelData[0]=0X9B;dispDelData[1]=0X1C;
		LcdDisplayChar(dispAddData,3,dispDelData,2);
		cleanDateBuf(dispAddData,3);
		cleanDateBuf(dispDelData,2);
	}
	if(dispType==3)//显示华氏F湿度单位
	{
		dispAddData[0]=0x8C;dispAddData[1]=0x9A;dispAddData[2]=0x9B;
		dispDelData[0]=0X9C;dispDelData[1]=0X1C;
		LcdDisplayChar(dispAddData,3,dispDelData,2);
		cleanDateBuf(dispAddData,3);
		cleanDateBuf(dispDelData,2);
	}
	if(tem<0)//处理符号部分
	{
		dispAddData[0]=0x3C;//显示+-符号
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
		dispAddData[0]=0x3C;//显示+-符号
		LcdDisplayChar(NULL,0,dispAddData,1);

		DISPD:

		dispAddData[0]=0x8B;//显示小数点
		LcdDisplayChar(dispAddData,1,NULL,0);
		cleanDateBuf(dispAddData,1);
		f-=tem;//得到小数部分
		i=f*10;//显示小数部分
		switch(i)
		{
			case 0:
				dispAddData[0]=0x7A;dispAddData[1]=0x7F;dispAddData[2]=0x7E;dispAddData[3]=0x7D;dispAddData[4]=0x7C;dispAddData[5]=0x7B;
				dispDelData[0]=0X73;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
			    break;
			case 1:
				dispAddData[0]=0x7B;dispAddData[1]=0x7C;
				dispDelData[0]=0X73;dispDelData[1]=0X7A;dispDelData[2]=0X7F;dispDelData[3]=0X7E;dispDelData[4]=0X7D;
				LcdDisplayChar(dispAddData,2,dispDelData,5);
				//LcdDisplayChar(dispAddData,2,NULL,0);
				cleanDateBuf(dispAddData,2);
				cleanDateBuf(dispDelData,5);
				break;
			case 2:
				dispAddData[0]=0x7A;dispAddData[1]=0x7B;dispAddData[2]=0x73;dispAddData[3]=0x7E;dispAddData[4]=0x7D;
				dispDelData[0]=0X7F;dispDelData[1]=0X7C;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 3:
				dispAddData[0]=0x7A;dispAddData[1]=0x7B;dispAddData[2]=0x73;dispAddData[3]=0x7C;dispAddData[4]=0x7D;
				dispDelData[0]=0X7F;dispDelData[1]=0X7E;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 4:
				dispAddData[0]=0x7F;dispAddData[1]=0x73;dispAddData[2]=0x7B;dispAddData[3]=0x7C;
				dispDelData[0]=0X7A;dispDelData[1]=0X7E;dispDelData[2]=0X7D;
				LcdDisplayChar(dispAddData,4,dispDelData,3);
				cleanDateBuf(dispAddData,4);
				cleanDateBuf(dispDelData,3);
			    break;
			case 5:
				dispAddData[0]=0x7A;dispAddData[1]=0x7F;dispAddData[2]=0x73;dispAddData[3]=0x7D;dispAddData[4]=0x7C;
				dispDelData[0]=0X7B;dispDelData[1]=0X7E;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 6:
				dispAddData[0]=0x7A;dispAddData[1]=0x7F;dispAddData[2]=0x73;dispAddData[3]=0x7D;dispAddData[4]=0x7E;dispAddData[5]=0x7C;
				dispDelData[0]=0X7B;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
				break;
			case 7:
				dispAddData[0]=0x7A;dispAddData[1]=0x7B;dispAddData[2]=0x7C;
				dispDelData[0]=0X73;dispDelData[1]=0X7F;dispDelData[2]=0X7E;dispDelData[3]=0X7D;
				LcdDisplayChar(dispAddData,3,dispDelData,4);
				cleanDateBuf(dispAddData,3);
				cleanDateBuf(dispDelData,4);
				break;
			case 8:
				dispAddData[0]=0x7A;dispAddData[1]=0x7F;dispAddData[2]=0x7E;dispAddData[3]=0x7D;dispAddData[4]=0x7C;dispAddData[5]=0x7B;dispAddData[6]=0x73;
				//dispDelData[0]=0X63;
				LcdDisplayChar(dispAddData,7,NULL,0);
				cleanDateBuf(dispAddData,7);
				//cleanDateBuf(dispDelData,1);
				break;
			case 9:
				dispAddData[0]=0x7A;dispAddData[1]=0x7F;dispAddData[2]=0x73;dispAddData[3]=0x7D;dispAddData[4]=0x7C;dispAddData[5]=0x7B;
				dispDelData[0]=0X7E;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
				break;

		}

		i=tem%10;//取个位
		switch(i)
		{
		    case 0:
			    dispAddData[0]=0x6A;dispAddData[1]=0x6F;dispAddData[2]=0x6E;dispAddData[3]=0x6D;dispAddData[4]=0x6C;dispAddData[5]=0x6B;
			    dispDelData[0]=0X63;
			    LcdDisplayChar(dispAddData,6,dispDelData,1);
			    cleanDateBuf(dispAddData,6);
			    cleanDateBuf(dispDelData,1);
			    break;
		    case 1:
		    	dispAddData[0]=0x6B;dispAddData[1]=0x6C;
		    	dispDelData[0]=0X63;dispDelData[1]=0X6A;dispDelData[2]=0X6F;dispDelData[3]=0X6E;dispDelData[4]=0X6D;
		    	LcdDisplayChar(dispAddData,2,dispDelData,5);
		    	cleanDateBuf(dispAddData,2);
		    	cleanDateBuf(dispDelData,5);
		    	break;
		    case 2:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6B;dispAddData[2]=0x63;dispAddData[3]=0x6E;dispAddData[4]=0x6D;
		    	dispDelData[0]=0X6F;dispDelData[1]=0X6C;
		    	LcdDisplayChar(dispAddData,5,dispDelData,2);
		    	cleanDateBuf(dispAddData,5);
		    	cleanDateBuf(dispDelData,2);
		    	break;
		    case 3:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6B;dispAddData[2]=0x63;dispAddData[3]=0x6C;dispAddData[4]=0x6D;
		    	dispDelData[0]=0X6F;dispDelData[1]=0X6E;
		    	LcdDisplayChar(dispAddData,5,dispDelData,2);
		    	cleanDateBuf(dispAddData,5);
		    	cleanDateBuf(dispDelData,2);
		    	break;
		    case 4:
		    	dispAddData[0]=0x6F;dispAddData[1]=0x63;dispAddData[2]=0x6B;dispAddData[3]=0x6C;
		    	dispDelData[0]=0X6A;dispDelData[1]=0X6E;dispDelData[2]=0X6D;
		    	LcdDisplayChar(dispAddData,4,dispDelData,3);
		    	cleanDateBuf(dispAddData,4);
		    	cleanDateBuf(dispDelData,3);
		    	break;
		    case 5:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6F;dispAddData[2]=0x63;dispAddData[3]=0x6D;dispAddData[4]=0x6C;
		    	dispDelData[0]=0X6B;dispDelData[1]=0X6E;
		    	LcdDisplayChar(dispAddData,5,dispDelData,2);
		    	cleanDateBuf(dispAddData,5);
		    	cleanDateBuf(dispDelData,2);
		    	break;
		    case 6:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6F;dispAddData[2]=0x63;dispAddData[3]=0x6D;dispAddData[4]=0x6E;dispAddData[5]=0x6C;
		    	dispDelData[0]=0X6B;
		    	LcdDisplayChar(dispAddData,6,dispDelData,1);
		    	cleanDateBuf(dispAddData,6);
		    	cleanDateBuf(dispDelData,1);
		    	break;
		    case 7:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6B;dispAddData[2]=0x6C;
		    	dispDelData[0]=0X63;dispDelData[1]=0X6F;dispDelData[2]=0X6E;dispDelData[3]=0X6D;
		    	LcdDisplayChar(dispAddData,3,dispDelData,4);
		    	cleanDateBuf(dispAddData,3);
		    	cleanDateBuf(dispDelData,4);
		    	break;
		    case 8:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6F;dispAddData[2]=0x6E;dispAddData[3]=0x6D;dispAddData[4]=0x6C;dispAddData[5]=0x6B;dispAddData[6]=0x63;
		    	//dispDelData[0]=0X63;
		    	LcdDisplayChar(dispAddData,7,NULL,0);
		    	cleanDateBuf(dispAddData,7);
		    	//cleanDateBuf(dispDelData,1);
		    	break;
		    case 9:
		    	dispAddData[0]=0x6A;dispAddData[1]=0x6F;dispAddData[2]=0x63;dispAddData[3]=0x6D;dispAddData[4]=0x6C;dispAddData[5]=0x6B;
		    	dispDelData[0]=0X6E;
		    	LcdDisplayChar(dispAddData,6,dispDelData,1);
		    	cleanDateBuf(dispAddData,6);
		    	cleanDateBuf(dispDelData,1);
		    	break;

		}
		tem/=10;
		if(tem==0)return;//判断后面是否还有要显示的数
		i=tem%10;//取十位
		switch(i)
		{
			case 0:
				dispAddData[0]=0x5A;dispAddData[1]=0x5F;dispAddData[2]=0x5E;dispAddData[3]=0x5D;dispAddData[4]=0x5C;dispAddData[5]=0x5B;
				dispDelData[0]=0X53;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
				break;
			case 1:
				dispAddData[0]=0x5B;dispAddData[1]=0x5C;
				dispDelData[0]=0X53;dispDelData[1]=0X5A;dispDelData[2]=0X5F;dispDelData[3]=0X5E;dispDelData[4]=0X5D;
				LcdDisplayChar(dispAddData,2,dispDelData,5);
				cleanDateBuf(dispAddData,2);
				cleanDateBuf(dispDelData,5);
				break;
			case 2:
				dispAddData[0]=0x5A;dispAddData[1]=0x5B;dispAddData[2]=0x53;dispAddData[3]=0x5E;dispAddData[4]=0x5D;
				dispDelData[0]=0X5F;dispDelData[1]=0X5C;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 3:
				dispAddData[0]=0x5A;dispAddData[1]=0x5B;dispAddData[2]=0x53;dispAddData[3]=0x5C;dispAddData[4]=0x5D;
				dispDelData[0]=0X5F;dispDelData[1]=0X5E;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 4:
				dispAddData[0]=0x5F;dispAddData[1]=0x53;dispAddData[2]=0x5B;dispAddData[3]=0x5C;
				dispDelData[0]=0X5A;dispDelData[1]=0X5E;dispDelData[2]=0X5D;
				LcdDisplayChar(dispAddData,4,dispDelData,3);
				cleanDateBuf(dispAddData,4);
				cleanDateBuf(dispDelData,3);
				break;
			case 5:
				dispAddData[0]=0x5A;dispAddData[1]=0x5F;dispAddData[2]=0x53;dispAddData[3]=0x5D;dispAddData[4]=0x5C;
				dispDelData[0]=0X5B;dispDelData[1]=0X5E;
				LcdDisplayChar(dispAddData,5,dispDelData,2);
				//LcdDisplayChar(dispAddData,5,NULL,0);
				cleanDateBuf(dispAddData,5);
				cleanDateBuf(dispDelData,2);
				break;
			case 6:
				dispAddData[0]=0x5A;dispAddData[1]=0x5F;dispAddData[2]=0x53;dispAddData[3]=0x5D;dispAddData[4]=0x5E;dispAddData[5]=0x5C;
				dispDelData[0]=0X5B;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
				break;
			case 7:
				dispAddData[0]=0x5A;dispAddData[1]=0x5B;dispAddData[2]=0x5C;
				dispDelData[0]=0X53;dispDelData[1]=0X5F;dispDelData[2]=0X5E;dispDelData[3]=0X5D;
				LcdDisplayChar(dispAddData,3,dispDelData,4);
				cleanDateBuf(dispAddData,3);
				cleanDateBuf(dispDelData,4);
				break;
			case 8:
				dispAddData[0]=0x5A;dispAddData[1]=0x5F;dispAddData[2]=0x5E;dispAddData[3]=0x5D;dispAddData[4]=0x5C;dispAddData[5]=0x5B;dispAddData[6]=0x53;
				//dispDelData[0]=0X63;
				LcdDisplayChar(dispAddData,7,NULL,0);
				cleanDateBuf(dispAddData,7);
				//cleanDateBuf(dispDelData,1);
				break;
			case 9:
				dispAddData[0]=0x5A;dispAddData[1]=0x5F;dispAddData[2]=0x53;dispAddData[3]=0x5D;dispAddData[4]=0x5C;dispAddData[5]=0x5B;
				dispDelData[0]=0X5E;
				LcdDisplayChar(dispAddData,6,dispDelData,1);
				cleanDateBuf(dispAddData,6);
				cleanDateBuf(dispDelData,1);
				break;

		}
		tem/=10;
		if(tem==0)return;//判断后面是否还有要显示的数
		i=tem%10;//取十位
		if(i>0)
		{
			dispAddData[0]=0x4C;dispAddData[1]=0x4B;
			LcdDisplayChar(dispAddData,2,NULL,0);
			cleanDateBuf(dispAddData,2);
		}
	}
}
/****************************************************************************
 * StartLCDClock function.
 *
 * @brief	This function sets LCD8B clock enable.
 ***************************************************************************/
void StartLcd8bClock( void )
{
	/// LCD8B Clock Enable
	LCD8CTL |= 0x01;
}

/****************************************************************************
 * StopLCDClock function.
 *
 * @brief	This function sets LCD8B clock disable.
 ***************************************************************************/
void StopLcd8bClock( void )
{
	/// LCD8B Clock Disable
	LCD8CTL &= 0xfe;
}

/****************************************************************************
 * InitLcd8bInt function.
 *
 * @brief	This function initializes LCD interrupt.
 *
 * @param	intLevel
 *	@li @c		0		Interrupt Level 0
 *	@li @c		1		Interrupt Level 1
 *	@li @c		2		Interrupt Level 2
 *	@li @c		3		Interrupt Level 3
 *	@li @c		4		Interrupt Level 4
 *	@li @c		5		Interrupt Level 5
 *	@li @c		6		Interrupt Level 6
 *	@li @c		7		Interrupt Level 7
 *
 *  @retval		0		Failed.
 *  @retval		1		Success.
 ***************************************************************************/
short InitLcd8bInt( unsigned char intLevel )
{
	/// Parameter Check
	if( intLevel > 7 ){
			return 0;
	}

	/// LCD8B Interrupt Level Set
	ILVLCD8B = intLevel;

	return 1;
}

/****************************************************************************
 * EnableLcd8bInt function.
 *
 * @brief	LCD8B interrupt enable.
 ***************************************************************************/
void EnableLcd8bInt( void )
{
	/// Clear LCD8B interrupt
	ClrLcd8bIntFlg();

	/// LCD8B interrupt enable
	LCD8INTE |= 0x01;
}

/****************************************************************************
 * DisableLcd8bInt function.
 *
 * @brief	LCD8B interrupt disable.
 ***************************************************************************/
void DisableLcd8bInt( void )
{
	/// LCD8B interrupt disable
	LCD8INTE &= 0xfe;

	/// Clear LCD8B interrupt
	ClrLcd8bIntFlg();
}

/****************************************************************************
 * isLcd8bInt function.
 *
 * @brief	This function check interrupt flag.
 *
 * @retval	0	Not occurred
 * @retval	1		Occurred.
 ***************************************************************************/
int isLcd8bInt(void)
{
	/// Interrupt Check
	if( LCD8INTF != 1 ){
		return 0;
	}

	/// Interrupt Flag Reset
	LCD8INTF = 0x01;

	return 1;
}

/****************************************************************************
 * ClrLcd8bIntFlg function.
 *
 * @brief	Clear LCD interrupt flag
 ***************************************************************************/
void ClrLcd8bIntFlg( void )
{
	/// Clear LCD interrupt
	LCD8INTF = 0x01;
}

/****************************************************************************
 * onLcd8bReg function.
 *
 * @brief	LCD voltage regulator on
 ***************************************************************************/
void onLcd8bReg( void )
{
#ifdef	LCDX_DISCHARGE_VC
	LCD8PWR_VCEN = 1;
#endif
	LCD8PWR_HVLD = 0;
}

/****************************************************************************
 * offLcd8bReg function.
 *
 * @brief	LCD voltage regulator off
 ***************************************************************************/
void offLcd8bReg( void )
{
#ifdef	LCDX_DISCHARGE_VC
	LCD8PWR_VCEN = 0;
#endif
	LCD8PWR_HVLD = 1;
}


/* ----- static ----- */

/****************************************************************************
 * initLcd8bSegRam function.
 *
 * @brief	This function initializes RAM of LCD8B Panel.
 ***************************************************************************/

static void initLcd8bSegRam(void)
{
	unsigned char	*segram = (unsigned char *)LCD8B_SEGRAM_TOP_ADDR;
	unsigned short	i;
	unsigned char size;

	size = LCD8B_SEGRAM_END_ADDR - LCD8B_SEGRAM_TOP_ADDR;

	for(i = 0 ; i < size ; i++){
		*segram++ = 0x00;
	}
}



/****************************************************************************
 * initLcd8bMode function.
 *
 * @brief	This function initializes LCD8B Driver.
 ***************************************************************************/
static void initLcd8bMode( void )
{
	LCD8INTF			= 0x0001;	/// Clear frame interrupt flag.
	LCD8INTE			= 0x0000;	/// Disable frame interrupt.

	LCD8CLK_CLKSRC		= 1;		/// the clock source = OSC1.    =32.768MHZ
	LCD8CLK_CLKDIV		= 5;		/// the division ratio = 1/128. =31.25KHZ
	LCD8CLK_DBRUN		= 1;		/// Clock supplied in DEBUG mode.

	LCD8CTL_MODEN		= 1;		/// LCD disable.
	LCD8CTL_LCDDIS		= 1;		/// Enable the discharge operations

	LCD8TIM1_LDUTY		= 2;		/// the drive duty = 1/3.
	LCD8TIM1_FRMCNT		= 9;		/// the frame frequency = 65Hz.
	LCD8TIM2_NLINE		= 0;		/// the n-line inverse AC drive function = Normal drive.
	LCD8TIM2_BSTC		= 1;		/// the booster clock frequency = fCLK_LCD8B/16 Hz.

	LCD8PWR_VCEN		= 1;		/// the LCD8B voltage regulator = on.
	LCD8PWR_VCSEL		= 1;		/// the LCD8B voltage regulator output = VC2.
	LCD8PWR_HVLD		= 0;		/// the LCD8B voltage regulator into heavy load protection mode = Normal mode.
	LCD8PWR_BSTEN		= 1;		/// the LCD8B voltage booster = on.
	LCD8PWR_LC			= 0;		/// the LCD8B panel contrast = 0x0:light - 0xf:dark.

	LCD8DSP_DSPC		= 0;		/// the LCD8B display = display off.
	LCD8DSP_DSPAR		= 0;		/// the display area in the display data RAM = Display area 0.
	LCD8DSP_DSPREV		= 1;		/// black/white inversion = Normal display.
	LCD8DSP_COMREV		= 1;		/// the common pin assignment direction = Normal assignment.
	LCD8DSP_SEGREV		= 1;		/// the segment pin assignment direction = Normal assignment.
	LCD8COMC0_COM0DEN	= 1;		/// the partial drive of COM0 pin = Normal output;
	LCD8COMC0_COM1DEN	= 1;		/// the partial drive of COM1 pin = Normal output;
	LCD8COMC0_COM2DEN	= 1;		/// the partial drive of COM2 pin = Normal output;
	LCD8COMC0_COM3DEN	= 1;		/// the partial drive of COM3 pin = Normal output;
	LCD8COMC0_COM4DEN	= 1;		/// the partial drive of COM4 pin = Normal output;
	LCD8COMC0_COM5DEN	= 1;		/// the partial drive of COM5 pin = Normal output;
	LCD8COMC0_COM6DEN	= 1;		/// the partial drive of COM6 pin = Normal output;
	LCD8COMC0_COM7DEN	= 1;		/// the partial drive of COM7 pin = Normal output;

}


/****************************************************************************
 * initLcd8bPort function.
 *
 * @brief	The port with LCD8B initialize.
 ***************************************************************************/
static void initLcd8bPort( void )
{

	P3FNCSEL		|= 0xFFFF;		/// W14: P30 to P37 = Function 3(LCD8B / SEG46 to SEG53).
									/// W16: P30 to P37 = Function 3(LCD8B / SEG52 to SEG59).

	P3MODSEL		|= 0x00FF;		/// P30 to P37 = Use peripheral I/O function (LCD8B).

	P4FNCSEL		|= 0xFFFF;		/// W14: P40 to P43 = Function 3(LCD8B / SEG42 to SEG45).
									/// W16: P40 to P44 = Function 3(LCD8B / SEG47 to SEG51).

	P4MODSEL		|= 0x00FF;		/// W14: P40 to P43 = Use peripheral I/O function (LCD8B).
									/// W16: P40 to P44 = Use peripheral I/O function (LCD8B).

}

