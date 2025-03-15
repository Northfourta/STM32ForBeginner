#include "stm32f10x.h"                  // Device header


void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIOInitSturcture;
	GPIOInitSturcture.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOInitSturcture.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIOInitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOInitSturcture);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIOInitSturcture1;
	GPIOInitSturcture1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOInitSturcture1.GPIO_Pin = GPIO_Pin_5;
	GPIOInitSturcture1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInitSturcture1);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void LED3_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}

void LED1_TURNING(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_TURNING(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}

