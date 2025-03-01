#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	// RCC_GPIO时钟控制
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	//GPIO初始化
	GPIO_InitTypeDef GPIOInitSturcture;
	GPIOInitSturcture.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOInitSturcture.GPIO_Pin = GPIO_Pin_0;
	GPIOInitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOInitSturcture);
	
//	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	
	while(1){
		//GPIO_ResetBits(GPIOA, GPIO_Pin_0);	
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//		Delay_ms(100);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(100);
	}
}
