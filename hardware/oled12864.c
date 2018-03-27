#include "oled12864.h"

//����оƬSSD1306

//OLED��ʼ��
void OLED_SSD1306_Init(){
  IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xAE);  //ae/af   [��ʾ��/��ʾ��]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);  //2��4λ�ϳ�һ���ֽ���Ϊ��ָ�룬ҳģʽ��ָ����ʾ�ڴ����λ��
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x40);  //��RAM����һ�����ȡ��ʾ����(0x00~0x3F)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x81);  //���ȿ���
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xCF); 
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA1);  //0xa0���ҷ��� 0xa1����
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xC8);  //��ɨ�����·�ת   0xc0���·��� 0xc8����
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA6);  //a6/a7   [����/������ʾ]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA8);  //��ɨ��·
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x3f);  //����ɨ����Щ��
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xD3);  //��ɨƫ��(0x00~0x3F)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);//-not offset
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xd5);   //����ʱ�ӷ�Ƶ
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xD9);  //��ŵ���������
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xF1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xDA);  //��ɨ����
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x12);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xDB);  //Vcomh��ѹ
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x40);//Set VCOM Deselect Level
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x20);  //����ҳ��ַģʽ (0x00/0x01/0x02)
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x02);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x8D);  //������ѹ�ÿ���
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x14);  //--set(0x10) disable
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA4);  //a4/a5  [����/ȫ����ʾ]
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xA6);  
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xAF);//--turn on oled panel
	
	OLED_SSD1306_clear();
	OLED_SSD1306_setFocus(0,0);
}

void OLED_SSD1306_drawImg(unsigned char show[]){
  unsigned char x,y;
  unsigned int i=0;
  for(y=0;y<8;y++){
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+y);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x00);
    IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
    for(x=0;x<128;x++){
      IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,show[i++]);
    }
  }
}

void OLED_SSD1306_clear(){
  unsigned char i,j;
	for(i=0;i<8;i++){
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+i);
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
		IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0x10);
		for(j=0;j<128;j++){
		  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,0x00);
		}
	}
}

void OLED_SSD1306_drawChinese(unsigned char x0,unsigned char page,unsigned int ind){
  unsigned char i;
	OLED_SSD1306_setFocus(x0,page);
	for(i=0;i<16;i++){
		IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,GBKZKTAB[ind][i]);
	}
	OLED_SSD1306_setFocus(x0,page+1);
	for(;i<32;i++){
	  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,GBKZKTAB[ind][i]);
	}
}

void OLED_SSD1306_drawAscii(unsigned char x0,unsigned char page,unsigned char ind){
  unsigned char i;
	OLED_SSD1306_setFocus(x0,page);
	for(i=0;i<8;i++){
		IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,ASCIITAB[ind-0x20][i]);
	}
	OLED_SSD1306_setFocus(x0,page+1);
	for(;i<16;i++){
	  IIC_writeCd(OLED_ADDR,OLED_DATA_ADDR,ASCIITAB[ind-0x20][i]);
	}
}

void OLED_SSD1306_setFocus(unsigned char x, unsigned char y){ 
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,0xb0+y);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,((x&0xf0)>>4)|0x10);
	IIC_writeCd(OLED_ADDR,OLED_CMD_ADDR,(x&0x0f)|0x01);
}

