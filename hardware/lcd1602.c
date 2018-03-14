#include "lcd1602.h"

void LCD1602_write_cmd(unsigned char cmd){
	RS = 0;
  DATA = cmd;
	EN = 1;
	Delay10us(50);
	EN = 0;
	Delay10us(50);
}

void LCD1602_write_data(unsigned char dat){
  RS = 1;
  DATA = dat;
	EN = 1;
	Delay10us(50);
	EN = 0;
	Delay10us(50);
}

void LCD1602_init(){
	RS = 0;
	RW = 0;
	EN = 0;
	//��λ
  LCD1602_write_cmd(0x02);
	//�������뷽ʽ��AC�Զ���һ�����治��
	LCD1602_write_cmd(0x06);
	//��ʾ���ƿ���
	LCD1602_write_cmd(0x0c);
	//�������ã�8λ���� ������ʾ��5*7����
	LCD1602_write_cmd(0x38);
	//����
	LCD1602_write_cmd(0x01);
	//��λ���0X80
	//�ڶ��� 0XC0
	LCD1602_write_cmd(0x80);
}