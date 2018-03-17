#ifndef _IIC_H_
#define _IIC_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define IIC_DEL 0

sbit IIC_SCL = P1^1;
sbit IIC_SDA = P1^2;

#include "iic.h"

//IIC I/O�˿ڳ�ʼ��
void IIC_Init();

//д�뿪ʼ�ź�
void IIC_start();

//д�����ź�
void IIC_end();

//��IIC�����Ϸ���Ӧ����
void IIC_writeack(bit ack);

//��IIC�����϶�ȡӦ����
bit IIC_readack();

//��IIC������д��һ���ֽ�
void IIC_writeByte(unsigned char dat);

//��IIC�����϶�ȡһ���ֽ�
unsigned char IIC_readByte();

//����һ����������ݵ�IIC����
void IIC_writeCd(unsigned char addr1,unsigned char addr2,unsigned char cd);


#endif