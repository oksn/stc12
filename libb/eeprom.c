#include "eeprom.h"

//��������
//��һ������0000h - 01ffh
//�ڶ�������0200h - 03ffh
void iap_EraseSector(unsigned int addr){
  IAP_CONTR = ENABLE_IAP;
	//0x03  ����;
	IAP_CMD = 0x03;
	IAP_ADDRH = addr;
	IAP_ADDRL = addr >> 8;
	IAP_TRIG = WD1;
	IAP_TRIG = WD2;
	_nop_();
	iap_Disable();
}

void iap_Disable(){
  IAP_CONTR = 0;
	//0x02����ģʽ ��ISP����;
	IAP_CMD = 0;
	IAP_ADDRH = 0;
	IAP_ADDRL = 0;
	IAP_TRIG = 0;
}

void iap_ByteProgram(unsigned int addr,unsigned char dat){
	IAP_CONTR = ENABLE_IAP;
	//0x02  д/���;
  IAP_CMD = 0X02;
	IAP_ADDRH = addr >> 8;
	IAP_ADDRL = addr;
	IAP_DATA = dat;
	IAP_TRIG = WD1;
	IAP_TRIG = WD2;
	_nop_();
	iap_Disable();
}

void eeprom_write(unsigned int addr,unsigned char dat){
  iap_EraseSector(addr);
	iap_ByteProgram(addr,dat);	
}

unsigned char eeprom_read(unsigned int addr){
	unsigned char dat;
  IAP_CONTR = ENABLE_IAP;
	//0x01  ��;
	IAP_CMD = 0X01;
	IAP_ADDRH = addr >> 8;
	IAP_ADDRL = addr;
	IAP_TRIG = WD1;
	IAP_TRIG = WD2;
	_nop_();
	dat = IAP_DATA;
	iap_Disable();
	return dat;
}




