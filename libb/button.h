#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <stc12c5a60s2.h>
#include "delay.h"

#define BUTTON1 P1^2
//����ʱ�䶨�峬��3s
#define LONG_TIME 3000
//˫����϶
#define INTERVAL_TIME 1000

void Button1_click();
void Button1_dbclick();
void Button1_lclick();

void Button1_enable();
	

#endif