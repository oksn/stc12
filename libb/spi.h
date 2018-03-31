#ifndef _SPI_H_
#define _SPI_H_

#include <stc12c5a60s2.h>

//���ͺͽ��յ�λ˳��[��λ����]
#define DORD_HTL 0x00
//���ͺͽ��յ�λ˳��[��λ����]
#define DORD_LTH 0x20

//SPICLKʱ��ѡ��[���иߵ�ƽ]
#define CPOL_HIGH 0x80
//SPICLKʱ��ѡ��[���е͵�ƽ]
#define CPOL_LOW 0x00

sbit SS = P1^4;

void SPI_init(unsigned char DORD,unsigned char CPOL);

void SPI_writeByte(unsigned char DAT);

unsigned char readByte();


#endif