#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	PWM_Init();
	/*ÅäÖÃGPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // ÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);*/
}

void MotorSpeed_Set(int16_t speed)
{
	if (speed>=0)
	{
		TIM_SetCompare2(TIM2, speed);
		TIM_SetCompare3(TIM2, 0);
	}
	else
	{
		TIM_SetCompare2(TIM2, 0);
		TIM_SetCompare3(TIM2, -speed);
	}
}
