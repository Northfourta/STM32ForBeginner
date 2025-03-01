#include "stm32f10x.h"                  // Device header

void LightSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIOInitSturcture;
	GPIOInitSturcture.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInitSturcture.GPIO_Pin = GPIO_Pin_13;
	GPIOInitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInitSturcture);
}

uint8_t LightSensorGetNum(void)
{
	uint8_t LightNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0)
	{
		LightNum = 1;
	}
	else
	{
		LightNum = 0;
	}
	return LightNum;
}
