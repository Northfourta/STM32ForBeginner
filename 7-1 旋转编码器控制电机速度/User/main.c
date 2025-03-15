#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "RotaryEncoder.h"
#include "Motor.h"

int main(void)
{

	OLED_Init();
	RotaryEncoder_Init();
	Motor_Init();
	OLED_ShowString(1, 1, "Count:");
	
	while(1){
		
		//OLED_ShowString(1, 3, "HelloWorld!");
//		OLED_ShowNum(2, 1, 12345, 5);
//		OLED_ShowSignedNum(2, 7, -66, 2);
//		OLED_ShowHexNum(3, 1, 0xAA55, 4);
//		OLED_ShowBinNum(4, 1, 0xAA55, 16);
		
		//OLED_ShowNum(1, 7, count, 5);
		//OLED_ShowNum(2, 1, TIM_GetCounter(TIM2), 5);
		OLED_ShowSignedNum(1, 7, EncoderNum_Get(), 5); // 
		MotorSpeed_Set(EncoderNum_Get()); // 设置电机速度
	}
}
