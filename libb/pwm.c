#include "pwm.h"

//PWM��ʼ��
void PWM0_init(){
	//�����ڲ�ʱ��Fosc/2
  CMOD = 0x02;
	CL = 0x00;
	CCAP0H = 0xC0;
	CCAP0L = 0xC0;
	//8λPWM�����ж�
	CCAPM0 = 0x42;
	CR = 1;
}

//PWMռ�ձ�����
void PWM0_set(unsigned char val){
	CCAP0H = val;
}