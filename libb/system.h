#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stc12c5a60s2.h>

//0x101000
#define WDT_2DP 0x00;    //����Ƶ       12Mhz   65.5ms
#define WDT_4DP 0x01;    //�ķ�Ƶ       12Mhz   131.0ms
#define WDT_8DP 0x02;    //�˷�Ƶ       12Mhz   262.1ms
#define WDT_16DP 0x03;   //ʮ����Ƶ     12Mhz   524.2ms
#define WDT_32DP 0x04;   //������Ƶ     12Mhz   1.0485s
#define WDT_64DP 0x05;   //���ķ�Ƶ     12Mhz   2.0971s
#define WDT_128DP 0x06;  //һ���˷�Ƶ   12Mhz   4.1943s
#define WDT_256DP 0x07;  //��������Ƶ   12Mhz   8.3886s

//������ʼ�����Ź�
//���flag=1���ڿ���ģʽ������Ĭ�Ͽ���ģʽ������
//wdt_xdp���÷�Ƶ
void sys_en_wdt(bit flag,unsigned char wdt_xdp);
//ι��
void sys_feed_wdt();
//����ģʽ
void sys_pd();
//����ģʽ
void sys_idle();

#endif