#ifndef _EEPROM_H_
#define _EEPROM_H_

#include <stc12c5a60s2.h>
#include <intrins.h>

#define WD1 0x5a;
#define WD2 0xa5;

//EEPROM��д�ٶȶ�
//#define ENABLE_IAP 0X80    //SYSCLK < 30MHz
//#define ENABLE_IAP 0X81    //SYSCLK < 24MHz
#define ENABLE_IAP 0X82    //SYSCLK < 20MHz
//#define ENABLE_IAP 0X83    //SYSCLK < 12MHz
//#define ENABLE_IAP 0X84    //SYSCLK < 6MHz
//#define ENABLE_IAP 0X85    //SYSCLK < 3MHz
//#define ENABLE_IAP 0X86    //SYSCLK < 2MHz
//#define ENABLE_IAP 0X87    //SYSCLK < 1MHz

//��������
void iap_EraseSector(unsigned int addr);
//ISP����
void iap_Disable();
//д�����ݵ�ָ��λ��
void iap_ByteProgram(unsigned int addr,unsigned char dat);
//д������[�Ȳ����ٰ�����д�뵽ָ��λ��]
void eeprom_write(unsigned int addr,unsigned char dat);
//��ȡָ��λ������
unsigned char eeprom_read(unsigned int addr);


#endif