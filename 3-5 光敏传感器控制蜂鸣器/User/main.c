#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

int main(void)
{

	Buzzer_Init();
	LightSensor_Init();
	
	uint8_t Num;
//	Buzzer_ON();

	while(1){
		Num = LightSensorGetNum();
		if (Num == 0)
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}

	}
}
