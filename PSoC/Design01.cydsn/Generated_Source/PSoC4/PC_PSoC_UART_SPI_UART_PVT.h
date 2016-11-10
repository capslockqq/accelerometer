/***************************************************************************//**
* \file PC_PSoC_UART_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_PC_PSoC_UART_H)
#define CY_SCB_SPI_UART_PVT_PC_PSoC_UART_H

#include "PC_PSoC_UART_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (PC_PSoC_UART_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  PC_PSoC_UART_rxBufferHead;
    extern volatile uint32  PC_PSoC_UART_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   PC_PSoC_UART_rxBufferOverflow;
    /** @} globals */
#endif /* (PC_PSoC_UART_INTERNAL_RX_SW_BUFFER_CONST) */

#if (PC_PSoC_UART_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  PC_PSoC_UART_txBufferHead;
    extern volatile uint32  PC_PSoC_UART_txBufferTail;
#endif /* (PC_PSoC_UART_INTERNAL_TX_SW_BUFFER_CONST) */

#if (PC_PSoC_UART_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 PC_PSoC_UART_rxBufferInternal[PC_PSoC_UART_INTERNAL_RX_BUFFER_SIZE];
#endif /* (PC_PSoC_UART_INTERNAL_RX_SW_BUFFER) */

#if (PC_PSoC_UART_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 PC_PSoC_UART_txBufferInternal[PC_PSoC_UART_TX_BUFFER_SIZE];
#endif /* (PC_PSoC_UART_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void PC_PSoC_UART_SpiPostEnable(void);
void PC_PSoC_UART_SpiStop(void);

#if (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG)
    void PC_PSoC_UART_SpiInit(void);
#endif /* (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG) */

#if (PC_PSoC_UART_SPI_WAKE_ENABLE_CONST)
    void PC_PSoC_UART_SpiSaveConfig(void);
    void PC_PSoC_UART_SpiRestoreConfig(void);
#endif /* (PC_PSoC_UART_SPI_WAKE_ENABLE_CONST) */

void PC_PSoC_UART_UartPostEnable(void);
void PC_PSoC_UART_UartStop(void);

#if (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG)
    void PC_PSoC_UART_UartInit(void);
#endif /* (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG) */

#if (PC_PSoC_UART_UART_WAKE_ENABLE_CONST)
    void PC_PSoC_UART_UartSaveConfig(void);
    void PC_PSoC_UART_UartRestoreConfig(void);
#endif /* (PC_PSoC_UART_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in PC_PSoC_UART_SetPins() */
#define PC_PSoC_UART_UART_RX_PIN_ENABLE    (PC_PSoC_UART_UART_RX)
#define PC_PSoC_UART_UART_TX_PIN_ENABLE    (PC_PSoC_UART_UART_TX)

/* UART RTS and CTS position to be used in  PC_PSoC_UART_SetPins() */
#define PC_PSoC_UART_UART_RTS_PIN_ENABLE    (0x10u)
#define PC_PSoC_UART_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define PC_PSoC_UART_SpiUartEnableIntRx(intSourceMask)  PC_PSoC_UART_SetRxInterruptMode(intSourceMask)
#define PC_PSoC_UART_SpiUartEnableIntTx(intSourceMask)  PC_PSoC_UART_SetTxInterruptMode(intSourceMask)
uint32  PC_PSoC_UART_SpiUartDisableIntRx(void);
uint32  PC_PSoC_UART_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_PC_PSoC_UART_H) */


/* [] END OF FILE */
