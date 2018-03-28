#ifndef _OLED12864SPI_H_
#define _OLED12864SPI_H_

//#include "spi4.h"
#include "bmp.h"
#include "spi.h"
#include "delay.h"

sbit OLED_RST = P2^3;
sbit OLED_DC = P2^4;

void OLED_Init();

void OLED_writeCmd(unsigned char cmd);

void OLED_writeData(unsigned char dat);

//����
void OLED_clear();

void OLED_display_ON();

void OLED_display_OFF();

//���役��λ�ã�x [0-128]��  y[0-7]��
void OLED_resetFocus(unsigned char x, unsigned char y);

//����ͼƬ
void OLED_drawImg(unsigned char bmp[]);

//����
//x0����һ������Ҫ��ʾ��λ��*16
void OLED_drawChinese(unsigned char x0,unsigned char page,unsigned int ind);

//��ʾascii   [16*8]
//x0����һ������Ҫ��ʾ��λ��*8
void OLED_drawAscii(unsigned char x0,unsigned char page,unsigned char ind);


#endif