#ifndef _UART_H_
#define _UART_H_

#include <stc12c5a60s2.h>

//9600bps@11.0592MHz  ���������ʷ�����

//���ڳ�ʼ��
void UART_Init(void);
void UART_sendChar(unsigned char dat);
void UART_sendStr(unsigned char *str);

#endif