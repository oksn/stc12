#ifndef _SPI4_H_
#define _SPI4_h_

#include <stc12c5a60s2.h>
#include "delay.h"

#define SPI_SEND_START 0
#define SPI_SEND_STOP 1;

//ʱ��
sbit SPI_CLK = P2^0;
//�������
sbit SPI_MISO = P2^1;
//�ӻ�����
sbit SPI_MOSI = P2^2;
//Ƭѡ
sbit SPI_CS = P2^5;



//��spi������д��һ���ֽ�
void SPI4_writeByte(unsigned char dat);

void SPI4_readByte();

#endif