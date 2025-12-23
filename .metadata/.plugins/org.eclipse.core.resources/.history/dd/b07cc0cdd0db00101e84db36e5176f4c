/*
 * stm32f4xx.h
 *
 *  Created on: Dec 18, 2025
 *      Author: megha
 */

#ifndef STM32F4XX_H_
#define STM32F4XX_H_

#include <stdint.h>
/*
 * GPIO BASE ADDRESSES (AHB1 BUS)
 */
#define GPIOA_BASEADDR		0x40020000U
#define GPIOB_BASEADDR		0x40020400U
#define GPIOC_BASEADDR		0x40020800U
#define GPIOD_BASEADDR		0x40020C00U
#define GPIOE_BASEADDR		0x40021000U
#define GPIOF_BASEADDR		0x40021400U
#define GPIOG_BASEADDR		0x40021800U
#define GPIOH_BASEADDR		0x40021C00U



/*GPIO Register structure
 */
typedef struct{
    volatile uint32_t MODER;    // GPIO port mode register                (0x00)
    volatile uint32_t OTYPER;   // GPIO port output type register         (0x04)
    volatile uint32_t OSPEEDR;  // GPIO port output speed register        (0x08)
    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register   (0x0C)
    volatile uint32_t IDR;      // GPIO port input data register          (0x10)
    volatile uint32_t ODR;      // GPIO port output data register         (0x14)
    volatile uint32_t BSRR;     // GPIO port bit set/reset register       (0x18)
    volatile uint32_t LCKR;     // GPIO port configuration lock register  (0x1C)
    volatile uint32_t AFRL;     // GPIO alternate function low register   (0x20)
    volatile uint32_t AFRH;     // GPIO alternate function high register  (0x24)
} GPIO_RegDef_t;

/*
 * GPIO POINTERS
 */
#define GPIOA		((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG		((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH		((GPIO_RegDef_t *)GPIOH_BASEADDR)

/*
 * SPI BASE ADDRESSES (APB2)
 */

#define SPI1_BASEADDR			0X40013000U
#define SPI4_BASEADDR			0X40013400U


/*
 * SPI REGISTER STRUCTURE
 */
typedef struct{
	volatile uint32_t CR1;							//SPI REGISTER 1 				(0X00)
	volatile uint32_t CR2;							//SPI REGISTER 2				(0X04)
	volatile uint32_t SR;							//SPI STATUS REGISTER			(0X08)
	volatile uint32_t DR;							//SPI DATA REGISTER				(0X0C)
	volatile uint32_t CRCPR;						//SPI CRC POLYNOMIAL REGISTER	(0X10)
	volatile uint32_t RXCRCR;						//SPI RX CRC REGISTER			(0X14)
	volatile uint32_t TXCRCR;						//SPI TX CRC REGISTER   		(0X18)
	volatile uint32_t SCFGR;						//SPI I2S CONFIGURATION REGISTER(0X1C)
	volatile uint32_t SPR;							//SPI I2S PRESCALER REGISTER	(0X20)


}SPI_RegDef_t;

/*
 * SPI POINTERS
 */

#define SPI1			((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI4			((SPI_RegDef_t*)SPI4_BASEADDR)



/*
 * I2C BASE ADDRESSES	(APB1)
 */

#define I2C1_BASEADDR			0X40005400U
#define I2C2_BASEADDR			0X40005800U
#define I2C3_BASEADDR			0X40005C00U


/*
 * SPI REGISTER STRUCTURE
 */

typedef struct{
	volatile uint32_t CR1;							//I2C CONTROL REGISTER 1	(0X00)
	volatile uint32_t CR2;							//I2C CONTROL REGISTER 2	(0X04)
	volatile uint32_t OAR1;							//I2C OWN ADDRESS REGISTER 1(0X08)
	volatile uint32_t OAR2;							//I2C OWN ADDRESS REGISTER 2(0X0C)
	volatile uint32_t DR;							//I2C DATA REGISTER 		(0X10)
	volatile uint32_t SR1;							//I2C STATUS REGISTER 1		(0X14)
	volatile uint32_t SR2;							//I2C STATUS REGISTER 2		(0X18)
	volatile uint32_t CCR;							//I2C CLOCK CONTROL REGISTER(0X1C)
	volatile uint32_t TRISE;						//I2C TRISE REGISTER 		(0X20)
	volatile uint32_t FLTR;							//I2C FLTR REGISTER 		(0X24)


}I2C_RegDef_t;


/*
 * I2C POINTER
 */

#define I2C1			((I2C_RegDef_t*) I2C1_BASEADDR)
#define I2C2			((I2C_RegDef_t*) I2C2_BASEADDR)
#define I2C3			((I2C_RegDef_t*) I2C3_BASEADDR)


/*
 * RCC BASE ADDRESS		(AHB1)
 */

#define RCC_BASEADDR			0X40023800U
/*
 * RCC REGISTER STRUCTURE
 */

typedef struct{
    volatile uint32_t CR;           // 0x00
    volatile uint32_t PLLCFGR;      // 0x04
    volatile uint32_t CFGR;         // 0x08
    volatile uint32_t CIR;          // 0x0C
    volatile uint32_t AHB1RSTR;     // 0x10
    volatile uint32_t AHB2RSTR;     // 0x14
    volatile uint32_t AHB3RSTR;     // 0x18
    volatile uint32_t RESERVED0;    // 0x1C
    volatile uint32_t APB1RSTR;     // 0x20
    volatile uint32_t APB2RSTR;     // 0x24
    volatile uint32_t RESERVED1;    // 0x28
    volatile uint32_t RESERVED2;    // 0x2C
    volatile uint32_t AHB1ENR;      // 0x30
    volatile uint32_t AHB2ENR;      // 0x34
    volatile uint32_t AHB3ENR;      // 0x38
    volatile uint32_t APB1ENR;      // 0x40
    volatile uint32_t APB2ENR;      // 0x44
    volatile uint32_t AHB1LPENR;    // 0x50
    volatile uint32_t AHB2LPENR;    // 0x54
    volatile uint32_t AHB3LPENR;    // 0x58
    volatile uint32_t APB1LPENR;    // 0x60
    volatile uint32_t APB2LPENR;    // 0x64
    volatile uint32_t RESERVED3;    // 0x68
    volatile uint32_t BDCR;         // 0x70
    volatile uint32_t CSR;          // 0x74
    volatile uint32_t SSCGR;        // 0x80
    volatile uint32_t PLLI2SCFGR;   // 0x84
    volatile uint32_t PLLSAICFGR;   // 0x88
    volatile uint32_t DCKCFGR;      // 0x8C
    volatile uint32_t CKGATENR;     // 0x90
    volatile uint32_t DCKCFGR2;     // 0x94
} RCC_RegDef_t;



/*
 * RCC POINTER
 */
#define RCC			((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * CLOCK ENABLE MACROS AHB1 BUS FOR GPIO
 */

#define GPIOA_CLK_EN()	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()	(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()	(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()	(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()	(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN()	(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN()	(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN()	(RCC->AHB1ENR |= (1 << 7))


#endif /* STM32_F446XX_H_ */


