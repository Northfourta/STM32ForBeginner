#include "stm32f10x.h"                  // Device header
#include "Timer.h"


void PWM_Init(void)
{
	/*配置GPIO*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 开启timer2的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x04); // TIM外部时钟模式2->GPIO
	TIM_InternalClockConfig(TIM2);// TIM外内部时钟模式
	
	/* 时基单元初始化:PWM频率为10000hz*/
	TIM_TimeBaseInitTypeDef TimerInitStructure;
	TimerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; // 不分频
	TimerInitStructure.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	TimerInitStructure.TIM_Period = 100 - 1;
	TimerInitStructure.TIM_Prescaler = 72 - 1;
	TimerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TimerInitStructure);
	
	/* 定时器中断控制*/
	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); 
	
	/* NVIC配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitSturcture);
	*/
	
	// 配置输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	//输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	
	/*TIM使能*/
	TIM_Cmd(TIM2, ENABLE);			//使能TIM2，定时器开始运行
}
