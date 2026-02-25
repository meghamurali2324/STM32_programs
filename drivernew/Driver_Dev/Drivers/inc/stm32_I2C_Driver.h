/*
 * stm32_I2C_Driver.h
 *
 *  Created on: Feb 25, 2026
 *      Author: megha
 */
#ifndef INC_STM32F446XX_I2C_DRIVER_H_
#define INC_STM32F446XX_I2C_DRIVER_H_

#include "stm32f446xx.h"

/*
 *        I2C Configuration
 */

typedef struct
{
    uint32_t I2C_SCLSpeed;        /* Standard Mode(100kHz), Fast Mode(400kHz) */
    uint8_t  I2C_DeviceAddress;   /* Own device address */
    uint8_t  I2C_ACKControl;      /* Enable/Disable ACK */
    uint16_t I2C_FMDutyCycle;     /* Duty cycle in fast mode */

} I2C_Config_t;


/*
 *        I2C Handle Structure
 */

typedef struct
{
    I2C_RegDef_t *pI2Cx;      /* Base address of I2C peripheral */

    I2C_Config_t I2C_Config;

    uint8_t  *pTxBuffer;
    uint8_t  *pRxBuffer;
    uint32_t TxLen;
    uint32_t RxLen;

    uint8_t  TxRxState;
    uint8_t  DevAddr;
    uint32_t RxSize;
    uint8_t  Sr;   /* Repeated start */

} I2C_Handle_t;


/*
 *        I2C SCL Speed
 */

#define I2C_SCL_SPEED_SM        100000
#define I2C_SCL_SPEED_FM4K      400000

/*
 *        I2C ACK Control
 */

#define I2C_ACK_ENABLE          1
#define I2C_ACK_DISABLE         0

/*
 *        I2C Fast Mode Duty
 */

#define I2C_FM_DUTY_2           0
#define I2C_FM_DUTY_16_9         1


/*
 *        I2C States
 */

#define I2C_READY               0
#define I2C_BUSY_IN_RX          1
#define I2C_BUSY_IN_TX          2


/*
 *        I2C Application Events
 */

#define I2C_EV_TX_CMPLT         0
#define I2C_EV_RX_CMPLT         1
#define I2C_EV_STOP             2
#define I2C_ERROR_BERR          3
#define I2C_ERROR_ARLO          4
#define I2C_ERROR_AF            5
#define I2C_ERROR_OVR           6
#define I2C_ERROR_TIMEOUT       7


/*
 *        Peripheral Clock Control
 */

void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 *        Init and De-init
 */

void I2C_Init(I2C_Handle_t *pI2CHandle);
void I2C_DeInit(I2C_RegDef_t *pI2Cx);

/*
 *        Data Send & Receive
 */

/* Blocking APIs */
void I2C_MasterSendData(I2C_Handle_t *pI2CHandle,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);

void I2C_MasterReceiveData(I2C_Handle_t *pI2CHandle,uint8_t *pRxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);

/* Interrupt based APIs */
uint8_t I2C_MasterSendDataIT(I2C_Handle_t *pI2CHandle,uint8_t *pTxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);

uint8_t I2C_MasterReceiveDataIT(I2C_Handle_t *pI2CHandle,uint8_t *pRxBuffer,uint32_t Len,uint8_t SlaveAddr,uint8_t Sr);

/*
 *        IRQ Handling
 */

void I2C_EV_IRQHandling(I2C_Handle_t *pI2CHandle);
void I2C_ER_IRQHandling(I2C_Handle_t *pI2CHandle);

/*
 *        Other Peripheral Control APIs
 */

void I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
void I2C_SSIConfig(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
void I2C_GenerateStopCondition(I2C_RegDef_t *pI2Cx);
void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 *        Application Callback
 */

void I2C_ApplicationEventCallback(I2C_Handle_t *pI2CHandle, uint8_t AppEv);

#endif /* INC_STM32F446XX_I2C_DRIVER_H_ */
