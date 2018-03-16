#include "oled12864spi.h"

void OLED_Init(){
  OLED_RST = 1;
	Delay1ms(100);
	OLED_RST = 0;
	Delay1ms(100);
	OLED_RST = 1;
	
	OLED_writeCmd(0xAE);  //ae/af   [��ʾ��/��ʾ��]
	OLED_writeCmd(0x00);
	OLED_writeCmd(0x10);  //2��4λ�ϳ�һ���ֽ���Ϊ��ָ�룬ҳģʽ��ָ����ʾ�ڴ����λ��
	OLED_writeCmd(0x40);  //��RAM����һ�����ȡ��ʾ����(0x00~0x3F)
	OLED_writeCmd(0x81);  //���ȿ���
	OLED_writeCmd(0xCF); 
	OLED_writeCmd(0xA1);  //0xa0���ҷ��� 0xa1����
	OLED_writeCmd(0xC8);  //��ɨ�����·�ת   0xc0���·��� 0xc8����
	OLED_writeCmd(0xA6);  //a6/a7   [����/������ʾ]
	OLED_writeCmd(0xA8);  //��ɨ��·
	OLED_writeCmd(0x3f);  //����ɨ����Щ��
	OLED_writeCmd(0xD3);  //��ɨƫ��(0x00~0x3F)
	OLED_writeCmd(0x00);//-not offset
	OLED_writeCmd(0xd5);   //����ʱ�ӷ�Ƶ
	OLED_writeCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_writeCmd(0xD9);  //��ŵ���������
	OLED_writeCmd(0xF1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_writeCmd(0xDA);  //��ɨ����
	OLED_writeCmd(0x12);
	OLED_writeCmd(0xDB);  //Vcomh��ѹ
	OLED_writeCmd(0x40);//Set VCOM Deselect Level
	OLED_writeCmd(0x20);  //����ҳ��ַģʽ (0x00/0x01/0x02)
	OLED_writeCmd(0x02);
	OLED_writeCmd(0x8D);  //������ѹ�ÿ���
	OLED_writeCmd(0x14);  //--set(0x10) disable
	OLED_writeCmd(0xA4);  //a4/a5  [����/ȫ����ʾ]
	OLED_writeCmd(0xA6);  
	OLED_writeCmd(0xAF);//--turn on oled panel

  OLED_clear();
	
  OLED_writeCmd(0xb0);  //����ҳ��ַ(0-7)
  OLED_writeCmd(0x00);    //�����е͵�ַ
  OLED_writeCmd(0x10);    //�����иߵ�ַ
}

void OLED_writeCmd(unsigned char cmd){
  OLED_DC = 0;
	SPI4_writeByte(cmd);
	OLED_DC = 1;
}

void OLED_writeData(unsigned char dat){
  OLED_DC = 1;
	SPI4_writeByte(dat);
	OLED_DC = 1;
}

void OLED_clear(){
  unsigned char i,j;
	for(i=0;i<8;i++){
	  OLED_writeCmd(0xb0);  //����ҳ��ַ(0-7)
		OLED_writeCmd(0x00);    //�����е͵�ַ
		OLED_writeCmd(0x10);    //�����иߵ�ַ
		for(j=0;j<128;j++){
		  OLED_writeData(0x00);
		}
	}
}

void OLED_display_ON(){
  OLED_writeCmd(0x8d);
	OLED_writeCmd(0x14);
	OLED_writeCmd(0xaf);
}

void OLED_display_OFF(){
  OLED_writeCmd(0x8d);
	OLED_writeCmd(0x10);
	OLED_writeCmd(0xae);
}

void OLED_setFocus(unsigned char x, unsigned char y){ 
	OLED_writeCmd(0xb0+y);
	OLED_writeCmd(((x&0xf0)>>4)|0x10);
	OLED_writeCmd((x&0x0f)|0x01);
}

//ȫ����ʾͼƬ
void OLED_drawImg(unsigned char bmp[]){
  unsigned char i,j;
	unsigned int ind;
	for(i=0;i<8;i++){
	  OLED_setFocus(0,i);
		for(j=0;j<128;j++){
		  OLED_writeData(bmp[ind]);
		}
	}
}

//����
void OLED_drawChinese(unsigned char x0,unsigned char page,unsigned int ind){
  unsigned char i;
	OLED_setFocus(x0,page);
	for(i=0;i<16;i++){
	  OLED_writeData(GBKZKTAB[ind][i]);
	}
	OLED_setFocus(x0,page+1);
	for(;i<32;i++){
	  OLED_writeData(GBKZKTAB[ind][i]);
	}
}

//��ʾascii   [16*8]
void OLED_drawAscii(unsigned char x0,unsigned char page,unsigned char ind){
  unsigned char i;
	OLED_setFocus(x0,page);
	for(i=0;i<8;i++){
	  OLED_writeData(ASCIITAB[ind-0x20][i]);
	}
	OLED_setFocus(x0,page+1);
	for(;i<16;i++){
	  OLED_writeData(ASCIITAB[ind-0x20][i]);
	}
}


