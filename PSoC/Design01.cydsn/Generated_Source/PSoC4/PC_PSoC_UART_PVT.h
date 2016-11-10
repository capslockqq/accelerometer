/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_PC_PSoC_UART_H)
#define CY_SCB_PVT_PC_PSoC_UART_H

#include "PC_PSoC_UART.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define PC_PSoC_UART_SetI2CExtClkInterruptMode(interruptMask) PC_PSoC_UART_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define PC_PSoC_UART_ClearI2CExtClkInterruptSource(interruptMask) PC_PSoC_UART_CLEAR_INTR_I2C_EC(interruptMask)
#define PC_PSoC_UART_GetI2CExtClkInterruptSource()                (PC_PSoC_UART_INTR_I2C_EC_REG)
#define PC_PSoC_UART_GetI2CExtClkInterruptMode()                  (PC_PSoC_UART_INTR_I2C_EC_MASK_REG)
#define PC_PSoC_UART_GetI2CExtClkInterruptSourceMasked()          (PC_PSoC_UART_INTR_I2C_EC_MASKED_REG)

#if (!PC_PSoC_UART_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define PC_PSoC_UART_SetSpiExtClkInterruptMode(interruptMask) \
                                                                PC_PSoC_UART_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define PC_PSoC_UART_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                PC_PSoC_UART_CLEAR_INTR_SPI_EC(interruptMask)
    #define PC_PSoC_UART_GetExtSpiClkInterruptSource()                 (PC_PSoC_UART_INTR_SPI_EC_REG)
    #define PC_PSoC_UART_GetExtSpiClkInterruptMode()                   (PC_PSoC_UART_INTR_SPI_EC_MASK_REG)
    #define PC_PSoC_UART_GetExtSpiClkInterruptSourceMasked()           (PC_PSoC_UART_INTR_SPI_EC_MASKED_REG)
#endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */

#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void PC_PSoC_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER)
    extern cyisraddress PC_PSoC_UART_customIntrHandler;
#endif /* !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER) */
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */

extern PC_PSoC_UART_BACKUP_STRUCT PC_PSoC_UART_backup;

#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 PC_PSoC_UART_scbMode;
    extern uint8 PC_PSoC_UART_scbEnableWake;
    extern uint8 PC_PSoC_UART_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 PC_PSoC_UART_mode;
    extern uint8 PC_PSoC_UART_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * PC_PSoC_UART_rxBuffer;
    extern uint8   PC_PSoC_UART_rxDataBits;
    extern uint32  PC_PSoC_UART_rxBufferSize;

    extern volatile uint8 * PC_PSoC_UART_txBuffer;
    extern uint8   PC_PSoC_UART_txDataBits;
    extern uint32  PC_PSoC_UART_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 PC_PSoC_UART_numberOfAddr;
    extern uint8 PC_PSoC_UART_subAddrSize;
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG || \
        PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 PC_PSoC_UART_IntrTxMask;
#endif /* (! (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG || \
              PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define PC_PSoC_UART_SCB_MODE_I2C_RUNTM_CFG     (PC_PSoC_UART_SCB_MODE_I2C      == PC_PSoC_UART_scbMode)
    #define PC_PSoC_UART_SCB_MODE_SPI_RUNTM_CFG     (PC_PSoC_UART_SCB_MODE_SPI      == PC_PSoC_UART_scbMode)
    #define PC_PSoC_UART_SCB_MODE_UART_RUNTM_CFG    (PC_PSoC_UART_SCB_MODE_UART     == PC_PSoC_UART_scbMode)
    #define PC_PSoC_UART_SCB_MODE_EZI2C_RUNTM_CFG   (PC_PSoC_UART_SCB_MODE_EZI2C    == PC_PSoC_UART_scbMode)
    #define PC_PSoC_UART_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (PC_PSoC_UART_SCB_MODE_UNCONFIG == PC_PSoC_UART_scbMode)

    /* Defines wakeup enable */
    #define PC_PSoC_UART_SCB_WAKE_ENABLE_CHECK       (0u != PC_PSoC_UART_scbEnableWake)
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!PC_PSoC_UART_CY_SCBIP_V1)
    #define PC_PSoC_UART_SCB_PINS_NUMBER    (7u)
#else
    #define PC_PSoC_UART_SCB_PINS_NUMBER    (2u)
#endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_PC_PSoC_UART_H) */


/* [] END OF FILE */
