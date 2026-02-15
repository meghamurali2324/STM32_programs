/*
 * stm32_GPIO_Driver.c
 *
 *  Created on: Feb 14, 2026
 *      Author: megha
 */

#include "stm32_GPIO_Driver.h"

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi) {
    if (EnorDi == ENABLE) {
        if (pGPIOx == GPIOA)      { GPIOA_PCLK_EN(); }
        else if (pGPIOx == GPIOB) { GPIOB_PCLK_EN(); }
        else if (pGPIOx == GPIOC) { GPIOC_PCLK_EN(); }
        else if (pGPIOx == GPIOD) { GPIOD_PCLK_EN(); }
        else if (pGPIOx == GPIOE) { GPIOE_PCLK_EN(); }
        else if (pGPIOx == GPIOF) { GPIOF_PCLK_EN(); }
        else if (pGPIOx == GPIOG) { GPIOG_PCLK_EN(); }
        else if (pGPIOx == GPIOH) { GPIOH_PCLK_EN(); }
    } else {
        if (pGPIOx == GPIOA)      { GPIOA_PCLK_DI(); }
        else if (pGPIOx == GPIOB) { GPIOB_PCLK_DI(); }
        else if (pGPIOx == GPIOC) { GPIOC_PCLK_DI(); }
        else if (pGPIOx == GPIOD) { GPIOD_PCLK_DI(); }
        else if (pGPIOx == GPIOE) { GPIOE_PCLK_DI(); }
        else if (pGPIOx == GPIOF) { GPIOF_PCLK_DI(); }
        else if (pGPIOx == GPIOG) { GPIOG_PCLK_DI(); }
        else if (pGPIOx == GPIOH) { GPIOH_PCLK_DI(); }
    }
}

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {
    uint32_t temp = 0;

    // 0. Enable the peripheral clock
    GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

    // 1. Configure the mode
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER |= temp;
    } else {
        // Interrupt mode logic to be added here
    }

    // 2. Configure the speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // 3. Configure the pupd settings
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // 4. Configure the optype
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;

    // 5. Configure the alternate functionality
    if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {
        uint8_t temp1, temp2;
        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
        pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
    }
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {
    if (pGPIOx == GPIOA)      { RCC->AHB1RSTR |= (1 << 0);  RCC->AHB1RSTR &= ~(1 << 0); }
    else if (pGPIOx == GPIOB) { RCC->AHB1RSTR |= (1 << 1);  RCC->AHB1RSTR &= ~(1 << 1); }
    else if (pGPIOx == GPIOC) { RCC->AHB1RSTR |= (1 << 2);  RCC->AHB1RSTR &= ~(1 << 2); }
    else if (pGPIOx == GPIOD) { RCC->AHB1RSTR |= (1 << 3);  RCC->AHB1RSTR &= ~(1 << 3); }
    else if (pGPIOx == GPIOE) { RCC->AHB1RSTR |= (1 << 4);  RCC->AHB1RSTR &= ~(1 << 4); }
    else if (pGPIOx == GPIOF) { RCC->AHB1RSTR |= (1 << 5);  RCC->AHB1RSTR &= ~(1 << 5); }
    else if (pGPIOx == GPIOG) { RCC->AHB1RSTR |= (1 << 6);  RCC->AHB1RSTR &= ~(1 << 6); }
    else if (pGPIOx == GPIOH) { RCC->AHB1RSTR |= (1 << 7);  RCC->AHB1RSTR &= ~(1 << 7); }
}

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {
    return (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) {
    return (uint16_t)pGPIOx->IDR;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value) {
    if (Value == GPIO_PIN_SET) {
        pGPIOx->ODR |= (1 << PinNumber);
    } else {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value) {
    pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {
    pGPIOx->ODR ^= (1 << PinNumber);
}
