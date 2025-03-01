#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

int main(void)
{
	uint8_t KeyNum;
	LED_Init();
	Key_Init();
	
//	LED1_ON();
//	LED3_ON(); 
	while(1){
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
//			LED1_ON();
//			LED2_OFF();
//			Delay_ms(500);
			LED2_TURNING();
		}
		if (KeyNum == 2)
		{
//			LED2_ON();
//			LED1_OFF();
//			Delay_ms(500);
			LED1_TURNING();
		}
	}
}
