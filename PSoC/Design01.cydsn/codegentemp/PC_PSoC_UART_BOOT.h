/***************************************************************************//**
* \file PC_PSoC_UART_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_PC_PSoC_UART_H)
#define CY_SCB_BOOT_PC_PSoC_UART_H

#include "PC_PSoC_UART_PVT.h"

#if (PC_PSoC_UART_SCB_MODE_I2C_INC)
    #include "PC_PSoC_UART_I2C.h"
#endif /* (PC_PSoC_UART_SCB_MODE_I2C_INC) */

#if (PC_PSoC_UART_SCB_MODE_EZI2C_INC)
    #include "PC_PSoC_UART_EZI2C.h"
#endif /* (PC_PSoC_UART_SCB_MODE_EZI2C_INC) */

#if (PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC)
    #include "PC_PSoC_UART_SPI_UART.h"
#endif /* (PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define PC_PSoC_UART_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PC_PSoC_UART) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (PC_PSoC_UART_SCB_MODE_I2C_INC)
    #define PC_PSoC_UART_I2C_BTLDR_COMM_ENABLED     (PC_PSoC_UART_BTLDR_COMM_ENABLED && \
                                                            (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             PC_PSoC_UART_I2C_SLAVE_CONST))
#else
     #define PC_PSoC_UART_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (PC_PSoC_UART_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (PC_PSoC_UART_SCB_MODE_EZI2C_INC)
    #define PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED   (PC_PSoC_UART_BTLDR_COMM_ENABLED && \
                                                         PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (PC_PSoC_UART_SCB_MODE_SPI_INC)
    #define PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED     (PC_PSoC_UART_BTLDR_COMM_ENABLED && \
                                                            (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             PC_PSoC_UART_SPI_SLAVE_CONST))
#else
        #define PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (PC_PSoC_UART_SCB_MODE_UART_INC)
       #define PC_PSoC_UART_UART_BTLDR_COMM_ENABLED    (PC_PSoC_UART_BTLDR_COMM_ENABLED && \
                                                            (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (PC_PSoC_UART_UART_RX_DIRECTION && \
                                                              PC_PSoC_UART_UART_TX_DIRECTION)))
#else
     #define PC_PSoC_UART_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (PC_PSoC_UART_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define PC_PSoC_UART_BTLDR_COMM_MODE_ENABLED    (PC_PSoC_UART_I2C_BTLDR_COMM_ENABLED   || \
                                                     PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED   || \
                                                     PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED || \
                                                     PC_PSoC_UART_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void PC_PSoC_UART_I2CCyBtldrCommStart(void);
    void PC_PSoC_UART_I2CCyBtldrCommStop (void);
    void PC_PSoC_UART_I2CCyBtldrCommReset(void);
    cystatus PC_PSoC_UART_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus PC_PSoC_UART_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG)
        #define PC_PSoC_UART_CyBtldrCommStart   PC_PSoC_UART_I2CCyBtldrCommStart
        #define PC_PSoC_UART_CyBtldrCommStop    PC_PSoC_UART_I2CCyBtldrCommStop
        #define PC_PSoC_UART_CyBtldrCommReset   PC_PSoC_UART_I2CCyBtldrCommReset
        #define PC_PSoC_UART_CyBtldrCommRead    PC_PSoC_UART_I2CCyBtldrCommRead
        #define PC_PSoC_UART_CyBtldrCommWrite   PC_PSoC_UART_I2CCyBtldrCommWrite
    #endif /* (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void PC_PSoC_UART_EzI2CCyBtldrCommStart(void);
    void PC_PSoC_UART_EzI2CCyBtldrCommStop (void);
    void PC_PSoC_UART_EzI2CCyBtldrCommReset(void);
    cystatus PC_PSoC_UART_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus PC_PSoC_UART_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG)
        #define PC_PSoC_UART_CyBtldrCommStart   PC_PSoC_UART_EzI2CCyBtldrCommStart
        #define PC_PSoC_UART_CyBtldrCommStop    PC_PSoC_UART_EzI2CCyBtldrCommStop
        #define PC_PSoC_UART_CyBtldrCommReset   PC_PSoC_UART_EzI2CCyBtldrCommReset
        #define PC_PSoC_UART_CyBtldrCommRead    PC_PSoC_UART_EzI2CCyBtldrCommRead
        #define PC_PSoC_UART_CyBtldrCommWrite   PC_PSoC_UART_EzI2CCyBtldrCommWrite
    #endif /* (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void PC_PSoC_UART_SpiCyBtldrCommStart(void);
    void PC_PSoC_UART_SpiCyBtldrCommStop (void);
    void PC_PSoC_UART_SpiCyBtldrCommReset(void);
    cystatus PC_PSoC_UART_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus PC_PSoC_UART_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG)
        #define PC_PSoC_UART_CyBtldrCommStart   PC_PSoC_UART_SpiCyBtldrCommStart
        #define PC_PSoC_UART_CyBtldrCommStop    PC_PSoC_UART_SpiCyBtldrCommStop
        #define PC_PSoC_UART_CyBtldrCommReset   PC_PSoC_UART_SpiCyBtldrCommReset
        #define PC_PSoC_UART_CyBtldrCommRead    PC_PSoC_UART_SpiCyBtldrCommRead
        #define PC_PSoC_UART_CyBtldrCommWrite   PC_PSoC_UART_SpiCyBtldrCommWrite
    #endif /* (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void PC_PSoC_UART_UartCyBtldrCommStart(void);
    void PC_PSoC_UART_UartCyBtldrCommStop (void);
    void PC_PSoC_UART_UartCyBtldrCommReset(void);
    cystatus PC_PSoC_UART_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus PC_PSoC_UART_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG)
        #define PC_PSoC_UART_CyBtldrCommStart   PC_PSoC_UART_UartCyBtldrCommStart
        #define PC_PSoC_UART_CyBtldrCommStop    PC_PSoC_UART_UartCyBtldrCommStop
        #define PC_PSoC_UART_CyBtldrCommReset   PC_PSoC_UART_UartCyBtldrCommReset
        #define PC_PSoC_UART_CyBtldrCommRead    PC_PSoC_UART_UartCyBtldrCommRead
        #define PC_PSoC_UART_CyBtldrCommWrite   PC_PSoC_UART_UartCyBtldrCommWrite
    #endif /* (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_BTLDR_COMM_ENABLED)
    #if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void PC_PSoC_UART_CyBtldrCommStart(void);
        void PC_PSoC_UART_CyBtldrCommStop (void);
        void PC_PSoC_UART_CyBtldrCommReset(void);
        cystatus PC_PSoC_UART_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus PC_PSoC_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PC_PSoC_UART)
        #define CyBtldrCommStart    PC_PSoC_UART_CyBtldrCommStart
        #define CyBtldrCommStop     PC_PSoC_UART_CyBtldrCommStop
        #define CyBtldrCommReset    PC_PSoC_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    PC_PSoC_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     PC_PSoC_UART_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_PC_PSoC_UART) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (PC_PSoC_UART_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define PC_PSoC_UART_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define PC_PSoC_UART_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define PC_PSoC_UART_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define PC_PSoC_UART_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef PC_PSoC_UART_SPI_BYTE_TO_BYTE
    #define PC_PSoC_UART_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef PC_PSoC_UART_UART_BYTE_TO_BYTE
    #define PC_PSoC_UART_UART_BYTE_TO_BYTE  (171u)
#endif /* PC_PSoC_UART_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_PC_PSoC_UART_H) */


/* [] END OF FILE */
