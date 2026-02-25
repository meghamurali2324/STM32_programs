/*
 * stm32_I2C_Driver.c
 *
 *  Created on: Feb 25, 2026
 *      Author: megha
 */


#include "stm32_I2C_Driver.h"

/* ================================
        Peripheral Clock Control
================================ */

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pI2Cx == I2C1)
            I2C1_PCLK_EN();
        else if(pI2Cx == I2C2)
            I2C2_PCLK_EN();
        else if(pI2Cx == I2C3)
            I2C3_PCLK_EN();
    }
    else
    {
        if(pI2Cx == I2C1)
            I2C1_PCLK_DI();
        else if(pI2Cx == I2C2)
            I2C2_PCLK_DI();
        else if(pI2Cx == I2C3)
            I2C3_PCLK_DI();
    }
}

/* ================================
            I2C Init
================================ */

void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    uint32_t tempreg = 0;

    /* Enable Peripheral Clock */
    I2C_PeriClockControl(pI2CHandle->pI2Cx, ENABLE);

    /* ACK Control */
    tempreg |= pI2CHandle->I2C_Config.I2C_ACKControl << I2C_CR1_ACK;
    pI2CHandle->pI2Cx->CR1 = tempreg;

    /* Configure FREQ field in CR2 */
    tempreg = 0;
    tempreg |= 16;   // Assuming APB1 clock = 16MHz
    pI2CHandle->pI2Cx->CR2 = tempreg;

    /* Configure Own Address */
    tempreg = 0;
    tempreg |= pI2CHandle->I2C_Config.I2C_DeviceAddress << 1;
    tempreg |= (1 << 14);
    pI2CHandle->pI2Cx->OAR1 = tempreg;

    /* CCR Calculation */
    uint16_t ccr_value = 0;

    if(pI2CHandle->I2C_Config.I2C_SCLSpeed == I2C_SCL_SPEED_SM)
    {
        ccr_value = (16000000 / (2 * pI2CHandle->I2C_Config.I2C_SCLSpeed));
        pI2CHandle->pI2Cx->CCR = ccr_value & 0xFFF;
    }

    /* TRISE Calculation */
    pI2CHandle->pI2Cx->TRISE = 17; // (16MHz/1MHz) + 1
}

/* ================================
        Peripheral Enable
================================ */

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
        pI2Cx->CR1 |= (1 << I2C_CR1_PE);
    else
        pI2Cx->CR1 &= ~(1 << I2C_CR1_PE);
}

/* ================================
        START Condition
================================ */

static void I2C_GenerateStartCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= (1 << I2C_CR1_START);
}

/* ================================
        STOP Condition
================================ */

void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= (1 << I2C_CR1_STOP);
}

/* ================================
        ACK Control
================================ */

void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t EnorDi)
{
    if(EnorDi == I2C_ACK_ENABLE)
        pI2Cx->CR1 |= (1 << I2C_CR1_ACK);
    else
        pI2Cx->CR1 &= ~(1 << I2C_CR1_ACK);
}

/* ================================
        Master Send (Blocking)
================================ */

void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,
                        uint8_t *pTxBuffer,
                        uint32_t Len,
                        uint8_t SlaveAddr,
                        uint8_t Sr)
{
    /* Generate START */
    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

    /* Wait until SB is set */
    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 0)));

    /* Send Slave Address */
    pI2CHandle->pI2Cx->DR = SlaveAddr << 1;

    /* Wait until ADDR flag */
    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 1)));

    /* Clear ADDR */
    volatile uint32_t dummy;
    dummy = pI2CHandle->pI2Cx->SR1;
    dummy = pI2CHandle->pI2Cx->SR2;
    (void)dummy;

    /* Send Data */
    while(Len > 0)
    {
        while(!(pI2CHandle->pI2Cx->SR1 & (1 << 7))); // TXE

        pI2CHandle->pI2Cx->DR = *pTxBuffer;
        pTxBuffer++;
        Len--;
    }

    /* Wait for TXE and BTF */
    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 7)));
    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 2)));

    if(Sr == I2C_DISABLE_SR)
        I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
}

/* ================================
        Master Receive (Blocking)
================================ */

void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,
                           uint8_t *pRxBuffer,
                           uint32_t Len,
                           uint8_t SlaveAddr,
                           uint8_t Sr)
{
    /* Generate START */
    I2C_GenerateStartCondition(pI2CHandle->pI2Cx);

    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 0)));

    /* Send Address with Read */
    pI2CHandle->pI2Cx->DR = (SlaveAddr << 1) | 1;

    while(!(pI2CHandle->pI2Cx->SR1 & (1 << 1)));

    volatile uint32_t dummy;
    dummy = pI2CHandle->pI2Cx->SR1;
    dummy = pI2CHandle->pI2Cx->SR2;
    (void)dummy;

    while(Len > 0)
    {
        if(Len == 1)
        {
            I2C_ManageAcking(pI2CHandle->pI2Cx, I2C_ACK_DISABLE);
            I2C_GenerateStopCondition(pI2CHandle->pI2Cx);
        }

        while(!(pI2CHandle->pI2Cx->SR1 & (1 << 6))); // RXNE

        *pRxBuffer = pI2CHandle->pI2Cx->DR;
        pRxBuffer++;
        Len--;
    }

    if(pI2CHandle->I2C_Config.I2C_ACKControl == I2C_ACK_ENABLE)
        I2C_ManageAcking(pI2CHandle->pI2Cx, I2C_ACK_ENABLE);
}
