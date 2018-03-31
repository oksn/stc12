#ifndef _HCSR04_H_
#define _HCSR04_H_

#include <stc12c5a60s2.h>
#include "delay.h"
#include "uart.h"

//�����Ҫ�޸Ķ˿� ��Ҫע���޸ĺ����еĶ˿����������뷽ʽ�������ģ��
sbit TRIG = P1^0;
sbit ECHO = P3^2;

void HCSR04_init();

unsigned int testdistance();

#endif