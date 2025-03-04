#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIOInitSturcture;
	GPIOInitSturcture.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInitSturcture.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
	GPIOInitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInitSturcture);
}

uint8_t Key_GetNum(void)
{
	uint8_t Key_Num = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)==0)
		{
			Delay_ms(20);
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)==0);
			Delay_ms(20);
			Key_Num = 1;
		}
		
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)==0);
		Delay_ms(20);
		Key_Num = 2;
	}
	return Key_Num;
	
}

