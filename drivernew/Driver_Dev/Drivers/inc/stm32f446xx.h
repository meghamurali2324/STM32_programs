/*
 * stm32f446xx.h
 * Updated for compatibility and bug fixes
 */

#ifndef STM32F446XX_H_
#define STM32F446XX_H_

#include <stdint.h>

#define __vo    volatile

/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0          ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (__vo uint32_t*)0xE000E10C )


/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0          ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1          ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2          ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3          ((__vo uint32_t*)0xE000E18C)


/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR   ((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

/*
 * Memory base addresses
 */
#define FLASH_BASEADDR          0x08000000U
#define ROM_BASEADDR            0x1FFF0000U
#define SRAM1_BASEADDR          0x20000000U
#define SRAM2_BASEADDR          0x2001C000U
#define SRAM                    SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */
#define PERIPH_BASE             0x40000000U
#define APB1PERIPH_BASE         PERIPH_BASE
#define APB2PERIPH_BASE         0x40010000U
#define AHB1PERIPH_BASE         0x40020000U
#define AHB2PERIPH_BASE         0x50000000U

/*
 * Base addresses of peripherals on AHB1 bus
 */
#define GPIOA_BASEADDR          (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR          (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR          (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR          (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR          (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR          (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR          (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR          (AHB1PERIPH_BASE + 0x1C00)
#define RCC_BASEADDR            (AHB1PERIPH_BASE + 0x3800)

/*
 * Base addresses of peripherals on APB1 bus
 */
#define I2C1_BASEADDR           (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR           (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR           (APB1PERIPH_BASE + 0x5C00)
#define SPI2_BASEADDR           (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR           (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASEADDR          (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR          (APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR           (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR           (APB1PERIPH_BASE + 0x5000)

/*
 * Base addresses of peripherals on APB2 bus
 */
#define USART1_BASEADDR         (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR         (APB2PERIPH_BASE + 0x1400)
#define SPI1_BASEADDR           (APB2PERIPH_BASE + 0x3000)
#define SYSCFG_BASEADDR         (APB2PERIPH_BASE + 0x3800)
#define EXTI_BASEADDR           (APB2PERIPH_BASE + 0x3C00)

/*
 * Peripheral register definition structures for GPIO
 */
typedef struct {
    __vo uint32_t MODER;
    __vo uint32_t OTYPER;
    __vo uint32_t OSPEEDR;
    __vo uint32_t PUPDR;
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t LCKR;
    __vo uint32_t AFR[2];
} GPIO_RegDef_t;
/*
 *   Peripheral register definition structures for RCC
 *
 */
typedef struct {
    __vo uint32_t CR;
    __vo uint32_t PLLCFGR;
    __vo uint32_t CFGR;
    __vo uint32_t CIR;
    __vo uint32_t AHB1RSTR;
    __vo uint32_t AHB2RSTR;
    __vo uint32_t AHB3RSTR;
    uint32_t      RESERVED0;
    __vo uint32_t APB1RSTR;
    __vo uint32_t APB2RSTR;
    uint32_t      RESERVED1[2];
    __vo uint32_t AHB1ENR;
    __vo uint32_t AHB2ENR;
    __vo uint32_t AHB3ENR;
    uint32_t      RESERVED2;
    __vo uint32_t APB1ENR;
    __vo uint32_t APB2ENR;
} RCC_RegDef_t;

/*
 *  * Peripheral register definition structures for EXTI
*/
typedef struct {

	  __vo uint32_t IMR;                      /*!< Interrupt mask register,                       Address offset: 0x00 */
	  __vo uint32_t EMR;                      /*!< Event mask register,                           Address offset: 0x04 */
	  __vo uint32_t RTSR;                     /*!< Rising trigger selection register,             Address offset: 0x08 */
	  __vo uint32_t FTSR;                     /*!< Falling trigger selection register,            Address offset: 0x0C */
	  __vo uint32_t SWIER;                    /*!< Software interrupt event register,             Address offset: 0x10 */
	  __vo uint32_t PR;                       /*!< Pending register,                              Address offset: 0x14 */
	} EXTI_RegDef_t;
/*
* Peripheral register definition structure for SYSCFG
*/
typedef struct{
	  __vo uint32_t MEMRMP;                   /*!< SYSCFG memory remap register,                  Address offset: 0x00 */
	  __vo uint32_t PMC;                      /*!< SYSCFG peripheral mode configuration register, Address offset: 0x04 */
	  __vo uint32_t EXTICR[4];                /*!< SYSCFG external interrupt configuration,       Address offset: 0x08-0x14 */
	  uint32_t      RESERVED1[2];             /*!< Reserved,                                      Address offset: 0x18-0x1C */
	  __vo uint32_t CMPCR;                    /*!< SYSCFG compensation cell control register,     Address offset: 0x20 */
	  uint32_t      RESERVED2[2];             /*!< Reserved,                                      Address offset: 0x24-0x28 */
	  __vo uint32_t CFGR;                     /*!< SYSCFG configuration register,                 Address offset: 0x2C */
}SYSCFG_RegDef_t;


#define IRQ_NO_EXTI0                        6
#define IRQ_NO_EXTI1                        7
#define IRQ_NO_EXTI2                        8
#define IRQ_NO_EXTI3                        9
#define IRQ_NO_EXTI4                        10
#define IRQ_NO_EXTI9_5                      23
#define IRQ_NO_EXTI15_10                    40

/*
 * Peripheral Definitions (Pointers to structures)
 */
#define GPIOA    ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB    ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC    ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD    ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE    ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF    ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG    ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH    ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC      ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI     ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG   ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


/*
 * Clock Enable Macros
 */
#define GPIOA_PCLK_EN()         (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()         (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()         (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()         (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()         (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()         (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()         (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()         (RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Disable Macros
 */
#define GPIOA_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()         (RCC->AHB1ENR &= ~(1 << 7))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN()                    (RCC->APB2ENR |= (1 << 14))

/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI()                    (RCC->APB2ENR &= ~(1 << 14))

/*
 * This macro returns a code (between 0 to 7) for a given GPIO base address (x)
 * STM32F446xx has GPIO ports A-H only
 */
#define GPIO_BASEADDR_TO_CODE(x)            ( (x == GPIOA) ? 0 :\
                                              (x == GPIOB) ? 1 :\
                                              (x == GPIOC) ? 2 :\
                                              (x == GPIOD) ? 3 :\
                                              (x == GPIOE) ? 4 :\
                                              (x == GPIOF) ? 5 :\
                                              (x == GPIOG) ? 6 :\
                                              (x == GPIOH) ? 7 : 0 )

/*
 * Generic Macros
 */
#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET

#endif /* STM32F446XX_H_ */
