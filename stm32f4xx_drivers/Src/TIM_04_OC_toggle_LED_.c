#include <stm32f446xx.h>
#include "stm32f446xx_gpio.h"
#include "stm32f446xx_tim.h"


TIM_handle_t htim2;

void GPIO_setup(void)
{
	GPIO_handle_t TIM2_PIN = {0};// al ser variable local el contenido no esta definido, es buena practica inicializarlo

	TIM2_PIN.pGPIOx = GPIOA;
	TIM2_PIN.GPIO_config.GPIO_Pin = GPIO_PIN_5;
	TIM2_PIN.GPIO_config.GPIO_Mode = GPIO_Mode_AF;
	TIM2_PIN.GPIO_config.GPIO_AltFun = GPIO_ALTFUN_1;
	TIM2_PIN.GPIO_config.GPIO_Speed = GPIO_Speed_LOW;

	GPIO_Init(&TIM2_PIN);
}

void TIM_setup(void)
{
	htim2.pTIMx = TIM2;
	htim2.TIM_TimeBase.TIM_Prescaler = 16000 - 1;//se tiene por default 16mhz se emplea 16000 para tener 1khz por lo que el contador estara incremenandose cada milisegundo
	htim2.TIM_TimeBase.TIM_Period = 1000 - 1;//se hara un update cada segundo,[un reseteo]
	htim2.TIM_TimeBase.TIM_CounterMode = TIM_CouterMode_UP;

	TIM_TimeBaseInit(&htim2);

	htim2.TIM_OutputCompare.TIM_Channel = TIM_CH1;
	htim2.TIM_OutputCompare.TIM_OCMode = TIM_OCMode_Toggle;
	htim2.TIM_OutputCompare.TIM_OCPolarity = TIM_OCPolarity_Active_HIGH;
	htim2.TIM_OutputCompare.TIM_Pulse = 1000 - 1;
	TIM_OCInit(&htim2);

}

int main(void)
{
	GPIO_setup();
	TIM_setup();

	TIM_Cmd(htim2.pTIMx, ENABLE);
	while(1){

	}
}

void assert_failed(uint8_t *file, uint32_t line){
	while(1);
}
