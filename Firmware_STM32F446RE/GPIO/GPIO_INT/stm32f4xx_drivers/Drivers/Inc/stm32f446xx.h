/*
 * stm32f446xx.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Nestor
 */

#ifndef DRIVERS_INC_STM32F446XX_H_
#define DRIVERS_INC_STM32F446XX_H_

#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

#define SET			1
#define RESET		0

#define AHB1PERIPH_BASEADDR			0x40020000UL
#define AHB2PERIPH_BASEADDR			0x40010000UL

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1C00)

#define RCC_BASEADOR 				(AHB1PERIPH_BASEADDR + 0X3800)

#define SYSCFG_BASEADDR				(AHB2PERIPH_BASEADDR + 0X3800)
#define EXTI_BASEADDR				(AHB2PERIPH_BASEADDR + 0X3C00)

#define NVIC_ISER0					(*((volatile uint32_t *)0xE000E100UL))
#define NVIC_ISER1					(*((volatile uint32_t *)0xE000E104UL))
#define NVIC_ISER2					(*((volatile uint32_t *)0xE000E108UL))

#define NVIC_ICER0					(*((volatile uint32_t *)0XE000E180UL))
#define NVIC_ICER1					(*((volatile uint32_t *)0xE000E184UL))
#define NVIC_ICER2					(*((volatile uint32_t *)0xE000E188UL))

#define NVIC_IPR_BASEADDR			0xE000E400UL
/*Estructura de prerifericos*/
typedef struct{
	volatile uint32_t MODDER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_RegDef_t;

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;

	uint32_t RES0;

	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;

	uint32_t RES1[2];

	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;

	uint32_t RES2;

	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;

	uint32_t RES3[2];

	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;

	uint32_t RES4;

	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;

	uint32_t RES5[2];

	volatile uint32_t BDCR;
	volatile uint32_t CSR;

	uint32_t RES6[2];

	volatile uint32_t SSCGR;
	volatile uint32_t PLLISCFGR;
}RCC_RegDef_t;

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef;

typedef struct {
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	uint32_t RES0[2];
	volatile uint32_t CMPCR;
	uint32_t RES1[2];
	volatile uint32_t CFGR;
}SYSCFG_RegDef;

/*Definicion de perifericos*/

#define GPIOA		((GPIO_RegDef_t *)GPIOA_BASEADDR)//apuntara al primer registro de la estructura que es volatile uint32_t MODDER;
#define GPIOB		((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG		((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH		((GPIO_RegDef_t *)GPIOH_BASEADDR)

#define RCC			((RCC_RegDef_t *)RCC_BASEADOR)

#define EXTI 		((EXTI_RegDef *)EXTI_BASEADDR)

#define SYSCFG 		((SYSCFG_RegDef *)SYSCFG_BASEADDR)

/* Habilitar clock de perifericos*/
#define GPIOA_EN_CLK()				(RCC->AHB1ENR |=(1<<0))//habilitar el primer bit
#define GPIOB_EN_CLK()				(RCC->AHB1ENR |=(1<<1))
#define GPIOC_EN_CLK()				(RCC->AHB1ENR |=(1<<2))
#define GPIOD_EN_CLK()				(RCC->AHB1ENR |=(1<<3))
#define GPIOE_EN_CLK()				(RCC->AHB1ENR |=(1<<4))
#define GPIOF_EN_CLK()				(RCC->AHB1ENR |=(1<<5))
#define GPIOG_EN_CLK()				(RCC->AHB1ENR |=(1<<6))
#define GPIOH_EN_CLK()				(RCC->AHB1ENR |=(1<<7))

#define SYSCFG_EN_CLK()				(RCC->APB2ENR |=(1<<14))

/* Deshabilitar clock de perifericos */

#define GPIOA_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_DIS_CLK()		(RCC->AHB1ENR &= ~(1 << 7))

#define SYSCFG_DIS_CLK()				(RCC->APB2ENR &= ~(1<<14))

/*Reset de perifericos*/
#define GPIOA_RESET() do{ RCC-> AHB1RSTR |=(1<<0); RCC-> AHB1RSTR &=~(1<<0);}while(0)
#define GPIOB_RESET() do{ RCC-> AHB1RSTR |=(1<<1); RCC-> AHB1RSTR &=~(1<<1);}while(0)
#define GPIOC_RESET() do{ RCC-> AHB1RSTR |=(1<<2); RCC-> AHB1RSTR &=~(1<<2);}while(0)
#define GPIOD_RESET() do{ RCC-> AHB1RSTR |=(1<<3); RCC-> AHB1RSTR &=~(1<<3);}while(0)
#define GPIOE_RESET() do{ RCC-> AHB1RSTR |=(1<<4); RCC-> AHB1RSTR &=~(1<<4);}while(0)
#define GPIOF_RESET() do{ RCC-> AHB1RSTR |=(1<<5); RCC-> AHB1RSTR &=~(1<<5);}while(0)
#define GPIOG_RESET() do{ RCC-> AHB1RSTR |=(1<<6); RCC-> AHB1RSTR &=~(1<<6);}while(0)
#define GPIOH_RESET() do{ RCC-> AHB1RSTR |=(1<<7); RCC-> AHB1RSTR &=~(1<<7);}while(0)

/* Macro para obtener el Numero de puerto*/

#define PORT_NUMBER(x)		( (x== GPIOA) ? 0: \
							  (x== GPIOB) ? 1: \
							  (x== GPIOC) ? 2: \
							  (x== GPIOD) ? 3: \
							  (x== GPIOE) ? 4: \
							  (x== GPIOF) ? 5: \
							  (x== GPIOG) ? 6: 7)

/* IRQS*/
#define IRQ_EXTI15_10		40


#endif /* DRIVERS_INC_STM32F446XX_H_ */
