/*
 * lcd.h
 *
 *  Created on: 2016-9-19
 *      Author: Administrator
 */

#ifndef LCD_H_
#define LCD_H_

#include "main.h"



#define DISP_WHELL_LOGO 0X1A //ÂÖ×Ó
#define DISP_STOP_LOGO 0X9D //Í£Ö¹Í¼±ê
#define DISP_ARROW_UP 0X2A //ÏòÉÏµÄ¼ýÍ·
#define DISP_ALARM_CHAR 0X2C//¾¯±¨×Ö·û
#define DISP_ALARM_LOGO 0X9E//¾¯±¨Í¼±ê
#define DISP_HI_CHAR 0X2B//HI×Ö·û
#define DISP_LOW_CHAR 0X3B//LOW×Ö·û
#define DISP_AVG_CHAR 0X1B//AVG×Ö·û
#define DISP_HR_CHAR 0X8A//HR×Ö·û
#define DISP_MIN_CHAR 0X8D//MIN×Ö·û
#define DISP_C_LOGO 0X3A //C×Ö·û
#define DISP_D_LOGO 0X4A //D×Ö·û
#define DISP_R_LOGO 0X4A //R×Ö·û
#define DISP_T_LOGO 0X54 //T×Ö·û

#define UNIT_HUMIDITY 1 //Êª¶È
#define UNIT_TEMP_C   2 //ÉãÊÏÎÂ¶È
#define UNIT_TEMP_F   3 //»ªÊÏÎÂ¶È

#define LCD_1A_SEG 0
#define LCD_1B_SEG 0
#define LCD_1C_SEG 0
#define LCD_1D_SEG 0
#define LCD_1F_SEG 1
#define LCD_1G_SEG 1
#define LCD_1E_SEG 1
#define LCD_S1_SEG 1
#define LCD_2A_SEG 2
#define LCD_2B_SEG 2
#define LCD_2C_SEG 2
#define LCD_2D_SEG 2
#define LCD_2F_SEG 3
#define LCD_2G_SEG 3
#define LCD_2E_SEG 3
#define LCD_S2_SEG 3
#define LCD_3A_SEG 4
#define LCD_3B_SEG 4
#define LCD_3C_SEG 4
#define LCD_3D_SEG 4
#define LCD_3F_SEG 5
#define LCD_3G_SEG 5
#define LCD_3E_SEG 5
#define LCD_4A_SEG 6
#define LCD_4B_SEG 6
#define LCD_4C_SEG 6
#define LCD_4D_SEG 6
#define LCD_4F_SEG 7
#define LCD_4G_SEG 7
#define LCD_4E_SEG 7
#define LCD_S3_SEG 7
#define LCD_5A_SEG 8
#define LCD_5B_SEG 8
#define LCD_5C_SEG 8
#define LCD_5D_SEG 8
#define LCD_5F_SEG 9
#define LCD_5G_SEG 9
#define LCD_5E_SEG 9
#define LCD_S4_SEG 9
#define LCD_6A_SEG 10
#define LCD_6B_SEG 10
#define LCD_6C_SEG 10
#define LCD_6D_SEG 10
#define LCD_6F_SEG 11
#define LCD_6G_SEG 11
#define LCD_6E_SEG 11
#define LCD_S5_SEG 11
#define LCD_7A_SEG 12
#define LCD_7B_SEG 12
#define LCD_7C_SEG 12
#define LCD_7D_SEG 12
#define LCD_7F_SEG 13
#define LCD_7G_SEG 13
#define LCD_7E_SEG 13
#define LCD_S6_SEG 13
#define LCD_8A_SEG 14
#define LCD_8B_SEG 14
#define LCD_8C_SEG 14
#define LCD_8D_SEG 14
#define LCD_8F_SEG 15
#define LCD_8G_SEG 15
#define LCD_8E_SEG 15
#define LCD_S7_SEG 15
#define LCD_9A_SEG 16
#define LCD_9B_SEG 16
#define LCD_9C_SEG 16
#define LCD_9D_SEG 16
#define LCD_9F_SEG 17
#define LCD_9G_SEG 17
#define LCD_9E_SEG 17
#define LCD_S8_SEG 17
#define LCD_S9_SEG 18
#define LCD_S12_SEG 18
#define LCD_S13_SEG 18
#define LCD_S14_SEG 18
#define LCD_S10_SEG 19
#define LCD_S11_SEG 19
#define LCD_S16_SEG 19
#define LCD_S15_SEG 19
#define LCD_S17_SEG 20
#define LCD_10E_SEG 20
#define LCD_10G_SEG 20
#define LCD_10F_SEG 20
#define LCD_10D_SEG 21
#define LCD_10C_SEG 21
#define LCD_10B_SEG 21
#define LCD_10A_SEG 21
#define LCD_S21_SEG 22
#define LCD_S20_SEG 22
#define LCD_S19_SEG 22
#define LCD_S18_SEG 22

#define LCD_1A_COM 0
#define LCD_1B_COM 1
#define LCD_1C_COM 2
#define LCD_1D_COM 3
#define LCD_1F_COM 0
#define LCD_1G_COM 1
#define LCD_1E_COM 2
#define LCD_S1_COM 3
#define LCD_2A_COM 0
#define LCD_2B_COM 1
#define LCD_2C_COM 2
#define LCD_2D_COM 3
#define LCD_2F_COM 0
#define LCD_2G_COM 1
#define LCD_2E_COM 2
#define LCD_S2_COM 3
#define LCD_3A_COM 0
#define LCD_3B_COM 1
#define LCD_3C_COM 2
#define LCD_3D_COM 3
#define LCD_3F_COM 0
#define LCD_3G_COM 1
#define LCD_3E_COM 2
#define LCD_4A_COM 0
#define LCD_4B_COM 1
#define LCD_4C_COM 2
#define LCD_4D_COM 3
#define LCD_4F_COM 0
#define LCD_4G_COM 1
#define LCD_4E_COM 2
#define LCD_S3_COM 3
#define LCD_5A_COM 0
#define LCD_5B_COM 1
#define LCD_5C_COM 2
#define LCD_5D_COM 3
#define LCD_5F_COM 0
#define LCD_5G_COM 1
#define LCD_5E_COM 2
#define LCD_S4_COM 3
#define LCD_6A_COM 0
#define LCD_6B_COM 1
#define LCD_6C_COM 2
#define LCD_6D_COM 3
#define LCD_6F_COM 0
#define LCD_6G_COM 1
#define LCD_6E_COM 2
#define LCD_S5_COM 3
#define LCD_7A_COM 0
#define LCD_7B_COM 1
#define LCD_7C_COM 2
#define LCD_7D_COM 3
#define LCD_7F_COM 0
#define LCD_7G_COM 1
#define LCD_7E_COM 2
#define LCD_S6_COM 3
#define LCD_8A_COM 0
#define LCD_8B_COM 1
#define LCD_8C_COM 2
#define LCD_8D_COM 3
#define LCD_8F_COM 0
#define LCD_8G_COM 1
#define LCD_8E_COM 2
#define LCD_S7_COM 3
#define LCD_9A_COM 0
#define LCD_9B_COM 1
#define LCD_9C_COM 2
#define LCD_9D_COM 3
#define LCD_9F_COM 0
#define LCD_9G_COM 1
#define LCD_9E_COM 2
#define LCD_S8_COM 3
#define LCD_S9_COM 0
#define LCD_S12_COM 1
#define LCD_S13_COM 2
#define LCD_S14_COM 3
#define LCD_S10_COM 0
#define LCD_S11_COM 1
#define LCD_S16_COM 2
#define LCD_S15_COM 3
#define LCD_S17_COM 0
#define LCD_10E_COM 1
#define LCD_10G_COM 2
#define LCD_10F_COM 3
#define LCD_10D_COM 0
#define LCD_10C_COM 1
#define LCD_10B_COM 2
#define LCD_10A_COM 3
#define LCD_S21_COM 0
#define LCD_S20_COM 1
#define LCD_S19_COM 2
#define LCD_S18_COM 3

#define LCD_ALL_ON       0
#define LCD_ALL_OFF      1
#define LCD_DISP_NORMAL  2
#define LCD_DISP_OFF     4


void dispDigital(float val,uchar dispType);
void OnOffSingleDisp(uchar posVal,uchar comm);
void LcdDisplayChar(unsigned char *addDataPos,unsigned char addNum,unsigned char *delDataPos,unsigned char delNum);
void lcdInit();
void setLcdDispMode(unsigned char mode);
void disp_H_L_Char(unsigned char t);
void dispSegNum(unsigned char pos,unsigned char dispNum);
void dispRunTime(unsigned int secends);
void clearDigitArea();

#endif /* LCD_H_ */
