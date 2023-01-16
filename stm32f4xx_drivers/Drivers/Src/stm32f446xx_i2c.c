#include "stm32f446xx_i2c.h"
//enable clock acces to gpiob
//enable clock acces to i2c1
/*
 * i2c1_scl = pb8
 * i2c1_sda = pb9
 * */
//set pb8 as alternate function pin
//set pb9 as alternate function pin
//set pb9,pb9 to i2c alternate function

void I2C_Init(I2C_RegDef_t *pI2C1)
{
	//Enable clock access to GPIOB
		RCC->AHB1ENR |= (1 << 1);

		//Configure pin PB8 in alternate function mode
		//to be I2C1_SCL (AF4)
		GPIOB->MODER |= (0b10 << 16);

		GPIOB->AFR[1] |= (0b0100 << 0);



		//Configure pin PB9 in alternate function mode
		//to be I2C1_SDA (AF4)
		GPIOB->MODER |= (0b10 << 18);

		GPIOB->AFR[1] |= (0b0100 << 4);

		//Set PB8 and PB9 output type to open drain
		GPIOB->OTYPER |= (1 << 8);

		GPIOB->OTYPER |= (1 << 9);


		//Enable pull-up resistors for PB8 and PB9
		GPIOB->PUPDR |= (0b01 << 16);

		GPIOB->PUPDR |= (0b01 << 18);


		//Enable clock access to I2C1
		RCC->APB1ENR |= (1 << 21);

		//Set I2C1 to be under reset state
		I2C1->CR1 |= (1 << 15);

		//Come out of reset state
		I2C1->CR1 &= ~(1 << 15);

		//Set clock frequency of I2C1 to be 16MHz
		//pI2C1->CR2 = (0b010000 << 0);
		I2C1->CR2 = (1U << 4);


		//Set I2C clock to standard mode- 100KHz
		//pI2C1->CCR = (0b01010000 << 0);
		I2C1->CCR = 80;

		//Sets rise time
		I2C1->TRISE = 17;

		//Enable I2C1
		I2C1->CR1 |= (1 << 0);
}
