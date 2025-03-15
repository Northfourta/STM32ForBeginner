#include "stm32f10x.h"                  // Device header



void Timer_Init(void)
{
	
	/*配置GPIO*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 开启timer2的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x04); // TIM外部时钟模式2->GPIO
	
	/* 时基单元初始化*/
	TIM_TimeBaseInitTypeDef TimerInitStructure;
	TimerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
	TimerInitStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	TimerInitStructure.TIM_Period = 10 - 1;
	TimerInitStructure.TIM_Prescaler = 1 - 1;
	TimerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TimerInitStructure);
	
	/* 定时器中断控制*/
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); 
	
	/* NVIC配置*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitSturcture);
	
	/*TIM使能*/
	TIM_Cmd(TIM2, ENABLE);			//使能TIM2，定时器开始运行
	
}






