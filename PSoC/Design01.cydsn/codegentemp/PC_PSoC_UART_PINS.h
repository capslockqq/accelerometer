/***************************************************************************//**
* \file PC_PSoC_UART_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_PC_PSoC_UART_H)
#define CY_SCB_PINS_PC_PSoC_UART_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define PC_PSoC_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define PC_PSoC_UART_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define PC_PSoC_UART_REMOVE_TX_SDA_MISO_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SCLK_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SS0_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SS1_PIN                 (1u)
#define PC_PSoC_UART_REMOVE_SS2_PIN                 (1u)
#define PC_PSoC_UART_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define PC_PSoC_UART_REMOVE_I2C_PINS                (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_PINS         (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SPI_SLAVE_PINS          (1u)
#define PC_PSoC_UART_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define PC_PSoC_UART_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define PC_PSoC_UART_REMOVE_UART_TX_PIN             (0u)
#define PC_PSoC_UART_REMOVE_UART_RX_TX_PIN          (1u)
#define PC_PSoC_UART_REMOVE_UART_RX_PIN             (0u)
#define PC_PSoC_UART_REMOVE_UART_RX_WAKE_PIN        (1u)
#define PC_PSoC_UART_REMOVE_UART_RTS_PIN            (1u)
#define PC_PSoC_UART_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN (0u == PC_PSoC_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define PC_PSoC_UART_RX_SCL_MOSI_PIN     (0u == PC_PSoC_UART_REMOVE_RX_SCL_MOSI_PIN)
#define PC_PSoC_UART_TX_SDA_MISO_PIN     (0u == PC_PSoC_UART_REMOVE_TX_SDA_MISO_PIN)
#define PC_PSoC_UART_SCLK_PIN     (0u == PC_PSoC_UART_REMOVE_SCLK_PIN)
#define PC_PSoC_UART_SS0_PIN     (0u == PC_PSoC_UART_REMOVE_SS0_PIN)
#define PC_PSoC_UART_SS1_PIN                (0u == PC_PSoC_UART_REMOVE_SS1_PIN)
#define PC_PSoC_UART_SS2_PIN                (0u == PC_PSoC_UART_REMOVE_SS2_PIN)
#define PC_PSoC_UART_SS3_PIN                (0u == PC_PSoC_UART_REMOVE_SS3_PIN)

/* Mode defined pins */
#define PC_PSoC_UART_I2C_PINS               (0u == PC_PSoC_UART_REMOVE_I2C_PINS)
#define PC_PSoC_UART_SPI_MASTER_PINS        (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_PINS)
#define PC_PSoC_UART_SPI_MASTER_SCLK_PIN    (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_SCLK_PIN)
#define PC_PSoC_UART_SPI_MASTER_MOSI_PIN    (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_MOSI_PIN)
#define PC_PSoC_UART_SPI_MASTER_MISO_PIN    (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_MISO_PIN)
#define PC_PSoC_UART_SPI_MASTER_SS0_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_SS0_PIN)
#define PC_PSoC_UART_SPI_MASTER_SS1_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_SS1_PIN)
#define PC_PSoC_UART_SPI_MASTER_SS2_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_SS2_PIN)
#define PC_PSoC_UART_SPI_MASTER_SS3_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_MASTER_SS3_PIN)
#define PC_PSoC_UART_SPI_SLAVE_PINS         (0u == PC_PSoC_UART_REMOVE_SPI_SLAVE_PINS)
#define PC_PSoC_UART_SPI_SLAVE_MOSI_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_SLAVE_MOSI_PIN)
#define PC_PSoC_UART_SPI_SLAVE_MISO_PIN     (0u == PC_PSoC_UART_REMOVE_SPI_SLAVE_MISO_PIN)
#define PC_PSoC_UART_UART_TX_PIN            (0u == PC_PSoC_UART_REMOVE_UART_TX_PIN)
#define PC_PSoC_UART_UART_RX_TX_PIN         (0u == PC_PSoC_UART_REMOVE_UART_RX_TX_PIN)
#define PC_PSoC_UART_UART_RX_PIN            (0u == PC_PSoC_UART_REMOVE_UART_RX_PIN)
#define PC_PSoC_UART_UART_RX_WAKE_PIN       (0u == PC_PSoC_UART_REMOVE_UART_RX_WAKE_PIN)
#define PC_PSoC_UART_UART_RTS_PIN           (0u == PC_PSoC_UART_REMOVE_UART_RTS_PIN)
#define PC_PSoC_UART_UART_CTS_PIN           (0u == PC_PSoC_UART_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
    #include "PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (PC_PSoC_UART_RX_SCL_MOSI) */

#if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
    #include "PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (PC_PSoC_UART_RX_SCL_MOSI) */

#if (PC_PSoC_UART_TX_SDA_MISO_PIN)
    #include "PC_PSoC_UART_uart_tx_i2c_sda_spi_miso.h"
#endif /* (PC_PSoC_UART_TX_SDA_MISO) */

#if (PC_PSoC_UART_SCLK_PIN)
    #include "PC_PSoC_UART_spi_sclk.h"
#endif /* (PC_PSoC_UART_SCLK) */

#if (PC_PSoC_UART_SS0_PIN)
    #include "PC_PSoC_UART_spi_ss0.h"
#endif /* (PC_PSoC_UART_SS0_PIN) */

#if (PC_PSoC_UART_SS1_PIN)
    #include "PC_PSoC_UART_spi_ss1.h"
#endif /* (PC_PSoC_UART_SS1_PIN) */

#if (PC_PSoC_UART_SS2_PIN)
    #include "PC_PSoC_UART_spi_ss2.h"
#endif /* (PC_PSoC_UART_SS2_PIN) */

#if (PC_PSoC_UART_SS3_PIN)
    #include "PC_PSoC_UART_spi_ss3.h"
#endif /* (PC_PSoC_UART_SS3_PIN) */

#if (PC_PSoC_UART_I2C_PINS)
    #include "PC_PSoC_UART_scl.h"
    #include "PC_PSoC_UART_sda.h"
#endif /* (PC_PSoC_UART_I2C_PINS) */

#if (PC_PSoC_UART_SPI_MASTER_PINS)
#if (PC_PSoC_UART_SPI_MASTER_SCLK_PIN)
    #include "PC_PSoC_UART_sclk_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_SCLK_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_MOSI_PIN)
    #include "PC_PSoC_UART_mosi_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_MOSI_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_MISO_PIN)
    #include "PC_PSoC_UART_miso_m.h"
#endif /*(PC_PSoC_UART_SPI_MASTER_MISO_PIN) */
#endif /* (PC_PSoC_UART_SPI_MASTER_PINS) */

#if (PC_PSoC_UART_SPI_SLAVE_PINS)
    #include "PC_PSoC_UART_sclk_s.h"
    #include "PC_PSoC_UART_ss_s.h"

#if (PC_PSoC_UART_SPI_SLAVE_MOSI_PIN)
    #include "PC_PSoC_UART_mosi_s.h"
#endif /* (PC_PSoC_UART_SPI_SLAVE_MOSI_PIN) */

#if (PC_PSoC_UART_SPI_SLAVE_MISO_PIN)
    #include "PC_PSoC_UART_miso_s.h"
#endif /*(PC_PSoC_UART_SPI_SLAVE_MISO_PIN) */
#endif /* (PC_PSoC_UART_SPI_SLAVE_PINS) */

#if (PC_PSoC_UART_SPI_MASTER_SS0_PIN)
    #include "PC_PSoC_UART_ss0_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_SS0_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS1_PIN)
    #include "PC_PSoC_UART_ss1_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_SS1_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS2_PIN)
    #include "PC_PSoC_UART_ss2_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_SS2_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS3_PIN)
    #include "PC_PSoC_UART_ss3_m.h"
#endif /* (PC_PSoC_UART_SPI_MASTER_SS3_PIN) */

#if (PC_PSoC_UART_UART_TX_PIN)
    #include "PC_PSoC_UART_tx.h"
#endif /* (PC_PSoC_UART_UART_TX_PIN) */

#if (PC_PSoC_UART_UART_RX_TX_PIN)
    #include "PC_PSoC_UART_rx_tx.h"
#endif /* (PC_PSoC_UART_UART_RX_TX_PIN) */

#if (PC_PSoC_UART_UART_RX_PIN)
    #include "PC_PSoC_UART_rx.h"
#endif /* (PC_PSoC_UART_UART_RX_PIN) */

#if (PC_PSoC_UART_UART_RX_WAKE_PIN)
    #include "PC_PSoC_UART_rx_wake.h"
#endif /* (PC_PSoC_UART_UART_RX_WAKE_PIN) */

#if (PC_PSoC_UART_UART_RTS_PIN)
    #include "PC_PSoC_UART_rts.h"
#endif /* (PC_PSoC_UART_UART_RTS_PIN) */

#if (PC_PSoC_UART_UART_CTS_PIN)
    #include "PC_PSoC_UART_cts.h"
#endif /* (PC_PSoC_UART_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_MASK      (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_POS       (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_GPIO  (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_I2C   (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_SPI   (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_UART  (PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_MASK      (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_POS       (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) PC_PSoC_UART_INTCFG_TYPE_MASK << \
                                                                           PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins PC_PSoC_UART_RX_SCL_MOSI_PIN or PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */

#if (PC_PSoC_UART_TX_SDA_MISO_PIN)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_MASK      (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_POS       (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_GPIO  (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_I2C   (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_SPI   (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_UART  (PC_PSoC_UART_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */

#if (PC_PSoC_UART_SCLK_PIN)
    #define PC_PSoC_UART_SCLK_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_spi_sclk__0__HSIOM)
    #define PC_PSoC_UART_SCLK_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_spi_sclk__0__HSIOM)
    
    #define PC_PSoC_UART_SCLK_HSIOM_MASK      (PC_PSoC_UART_spi_sclk__0__HSIOM_MASK)
    #define PC_PSoC_UART_SCLK_HSIOM_POS       (PC_PSoC_UART_spi_sclk__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SCLK_HSIOM_SEL_GPIO  (PC_PSoC_UART_spi_sclk__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SCLK_HSIOM_SEL_I2C   (PC_PSoC_UART_spi_sclk__0__HSIOM_I2C)
    #define PC_PSoC_UART_SCLK_HSIOM_SEL_SPI   (PC_PSoC_UART_spi_sclk__0__HSIOM_SPI)
    #define PC_PSoC_UART_SCLK_HSIOM_SEL_UART  (PC_PSoC_UART_spi_sclk__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_SCLK_PIN) */

#if (PC_PSoC_UART_SS0_PIN)
    #define PC_PSoC_UART_SS0_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_spi_ss0__0__HSIOM)
    #define PC_PSoC_UART_SS0_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_spi_ss0__0__HSIOM)
    
    #define PC_PSoC_UART_SS0_HSIOM_MASK      (PC_PSoC_UART_spi_ss0__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS0_HSIOM_POS       (PC_PSoC_UART_spi_ss0__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS0_HSIOM_SEL_GPIO  (PC_PSoC_UART_spi_ss0__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS0_HSIOM_SEL_I2C   (PC_PSoC_UART_spi_ss0__0__HSIOM_I2C)
    #define PC_PSoC_UART_SS0_HSIOM_SEL_SPI   (PC_PSoC_UART_spi_ss0__0__HSIOM_SPI)
#if !(PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1)
    #define PC_PSoC_UART_SS0_HSIOM_SEL_UART  (PC_PSoC_UART_spi_ss0__0__HSIOM_UART)
#endif /* !(PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1) */
#endif /* (PC_PSoC_UART_SS0_PIN) */

#if (PC_PSoC_UART_SS1_PIN)
    #define PC_PSoC_UART_SS1_HSIOM_REG  (*(reg32 *) PC_PSoC_UART_spi_ss1__0__HSIOM)
    #define PC_PSoC_UART_SS1_HSIOM_PTR  ( (reg32 *) PC_PSoC_UART_spi_ss1__0__HSIOM)
    
    #define PC_PSoC_UART_SS1_HSIOM_MASK     (PC_PSoC_UART_spi_ss1__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS1_HSIOM_POS      (PC_PSoC_UART_spi_ss1__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS1_HSIOM_SEL_GPIO (PC_PSoC_UART_spi_ss1__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS1_HSIOM_SEL_I2C  (PC_PSoC_UART_spi_ss1__0__HSIOM_I2C)
    #define PC_PSoC_UART_SS1_HSIOM_SEL_SPI  (PC_PSoC_UART_spi_ss1__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SS1_PIN) */

#if (PC_PSoC_UART_SS2_PIN)
    #define PC_PSoC_UART_SS2_HSIOM_REG     (*(reg32 *) PC_PSoC_UART_spi_ss2__0__HSIOM)
    #define PC_PSoC_UART_SS2_HSIOM_PTR     ( (reg32 *) PC_PSoC_UART_spi_ss2__0__HSIOM)
    
    #define PC_PSoC_UART_SS2_HSIOM_MASK     (PC_PSoC_UART_spi_ss2__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS2_HSIOM_POS      (PC_PSoC_UART_spi_ss2__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS2_HSIOM_SEL_GPIO (PC_PSoC_UART_spi_ss2__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS2_HSIOM_SEL_I2C  (PC_PSoC_UART_spi_ss2__0__HSIOM_I2C)
    #define PC_PSoC_UART_SS2_HSIOM_SEL_SPI  (PC_PSoC_UART_spi_ss2__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SS2_PIN) */

#if (PC_PSoC_UART_SS3_PIN)
    #define PC_PSoC_UART_SS3_HSIOM_REG     (*(reg32 *) PC_PSoC_UART_spi_ss3__0__HSIOM)
    #define PC_PSoC_UART_SS3_HSIOM_PTR     ( (reg32 *) PC_PSoC_UART_spi_ss3__0__HSIOM)
    
    #define PC_PSoC_UART_SS3_HSIOM_MASK     (PC_PSoC_UART_spi_ss3__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS3_HSIOM_POS      (PC_PSoC_UART_spi_ss3__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS3_HSIOM_SEL_GPIO (PC_PSoC_UART_spi_ss3__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS3_HSIOM_SEL_I2C  (PC_PSoC_UART_spi_ss3__0__HSIOM_I2C)
    #define PC_PSoC_UART_SS3_HSIOM_SEL_SPI  (PC_PSoC_UART_spi_ss3__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SS3_PIN) */

#if (PC_PSoC_UART_I2C_PINS)
    #define PC_PSoC_UART_SCL_HSIOM_REG  (*(reg32 *) PC_PSoC_UART_scl__0__HSIOM)
    #define PC_PSoC_UART_SCL_HSIOM_PTR  ( (reg32 *) PC_PSoC_UART_scl__0__HSIOM)
    
    #define PC_PSoC_UART_SCL_HSIOM_MASK     (PC_PSoC_UART_scl__0__HSIOM_MASK)
    #define PC_PSoC_UART_SCL_HSIOM_POS      (PC_PSoC_UART_scl__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SCL_HSIOM_SEL_GPIO (PC_PSoC_UART_sda__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SCL_HSIOM_SEL_I2C  (PC_PSoC_UART_sda__0__HSIOM_I2C)
    
    #define PC_PSoC_UART_SDA_HSIOM_REG  (*(reg32 *) PC_PSoC_UART_sda__0__HSIOM)
    #define PC_PSoC_UART_SDA_HSIOM_PTR  ( (reg32 *) PC_PSoC_UART_sda__0__HSIOM)
    
    #define PC_PSoC_UART_SDA_HSIOM_MASK     (PC_PSoC_UART_sda__0__HSIOM_MASK)
    #define PC_PSoC_UART_SDA_HSIOM_POS      (PC_PSoC_UART_sda__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SDA_HSIOM_SEL_GPIO (PC_PSoC_UART_sda__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SDA_HSIOM_SEL_I2C  (PC_PSoC_UART_sda__0__HSIOM_I2C)
#endif /* (PC_PSoC_UART_I2C_PINS) */

#if (PC_PSoC_UART_SPI_SLAVE_PINS)
    #define PC_PSoC_UART_SCLK_S_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_sclk_s__0__HSIOM)
    #define PC_PSoC_UART_SCLK_S_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_sclk_s__0__HSIOM)
    
    #define PC_PSoC_UART_SCLK_S_HSIOM_MASK      (PC_PSoC_UART_sclk_s__0__HSIOM_MASK)
    #define PC_PSoC_UART_SCLK_S_HSIOM_POS       (PC_PSoC_UART_sclk_s__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SCLK_S_HSIOM_SEL_GPIO  (PC_PSoC_UART_sclk_s__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SCLK_S_HSIOM_SEL_SPI   (PC_PSoC_UART_sclk_s__0__HSIOM_SPI)
    
    #define PC_PSoC_UART_SS0_S_HSIOM_REG    (*(reg32 *) PC_PSoC_UART_ss0_s__0__HSIOM)
    #define PC_PSoC_UART_SS0_S_HSIOM_PTR    ( (reg32 *) PC_PSoC_UART_ss0_s__0__HSIOM)
    
    #define PC_PSoC_UART_SS0_S_HSIOM_MASK       (PC_PSoC_UART_ss0_s__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS0_S_HSIOM_POS        (PC_PSoC_UART_ss0_s__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS0_S_HSIOM_SEL_GPIO   (PC_PSoC_UART_ss0_s__0__HSIOM_GPIO)  
    #define PC_PSoC_UART_SS0_S_HSIOM_SEL_SPI    (PC_PSoC_UART_ss0_s__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_SLAVE_PINS) */

#if (PC_PSoC_UART_SPI_SLAVE_MOSI_PIN)
    #define PC_PSoC_UART_MOSI_S_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_mosi_s__0__HSIOM)
    #define PC_PSoC_UART_MOSI_S_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_mosi_s__0__HSIOM)
    
    #define PC_PSoC_UART_MOSI_S_HSIOM_MASK      (PC_PSoC_UART_mosi_s__0__HSIOM_MASK)
    #define PC_PSoC_UART_MOSI_S_HSIOM_POS       (PC_PSoC_UART_mosi_s__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_MOSI_S_HSIOM_SEL_GPIO  (PC_PSoC_UART_mosi_s__0__HSIOM_GPIO)
    #define PC_PSoC_UART_MOSI_S_HSIOM_SEL_SPI   (PC_PSoC_UART_mosi_s__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_SLAVE_MOSI_PIN) */

#if (PC_PSoC_UART_SPI_SLAVE_MISO_PIN)
    #define PC_PSoC_UART_MISO_S_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_miso_s__0__HSIOM)
    #define PC_PSoC_UART_MISO_S_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_miso_s__0__HSIOM)
    
    #define PC_PSoC_UART_MISO_S_HSIOM_MASK      (PC_PSoC_UART_miso_s__0__HSIOM_MASK)
    #define PC_PSoC_UART_MISO_S_HSIOM_POS       (PC_PSoC_UART_miso_s__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_MISO_S_HSIOM_SEL_GPIO  (PC_PSoC_UART_miso_s__0__HSIOM_GPIO)
    #define PC_PSoC_UART_MISO_S_HSIOM_SEL_SPI   (PC_PSoC_UART_miso_s__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_SLAVE_MISO_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_MISO_PIN)
    #define PC_PSoC_UART_MISO_M_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_miso_m__0__HSIOM)
    #define PC_PSoC_UART_MISO_M_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_miso_m__0__HSIOM)
    
    #define PC_PSoC_UART_MISO_M_HSIOM_MASK      (PC_PSoC_UART_miso_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_MISO_M_HSIOM_POS       (PC_PSoC_UART_miso_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_MISO_M_HSIOM_SEL_GPIO  (PC_PSoC_UART_miso_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_MISO_M_HSIOM_SEL_SPI   (PC_PSoC_UART_miso_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_MISO_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_MOSI_PIN)
    #define PC_PSoC_UART_MOSI_M_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_mosi_m__0__HSIOM)
    #define PC_PSoC_UART_MOSI_M_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_mosi_m__0__HSIOM)
    
    #define PC_PSoC_UART_MOSI_M_HSIOM_MASK      (PC_PSoC_UART_mosi_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_MOSI_M_HSIOM_POS       (PC_PSoC_UART_mosi_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_MOSI_M_HSIOM_SEL_GPIO  (PC_PSoC_UART_mosi_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_MOSI_M_HSIOM_SEL_SPI   (PC_PSoC_UART_mosi_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_MOSI_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SCLK_PIN)
    #define PC_PSoC_UART_SCLK_M_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_sclk_m__0__HSIOM)
    #define PC_PSoC_UART_SCLK_M_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_sclk_m__0__HSIOM)
    
    #define PC_PSoC_UART_SCLK_M_HSIOM_MASK      (PC_PSoC_UART_sclk_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_SCLK_M_HSIOM_POS       (PC_PSoC_UART_sclk_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SCLK_M_HSIOM_SEL_GPIO  (PC_PSoC_UART_sclk_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SCLK_M_HSIOM_SEL_SPI   (PC_PSoC_UART_sclk_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_SCLK_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS0_PIN)
    #define PC_PSoC_UART_SS0_M_HSIOM_REG    (*(reg32 *) PC_PSoC_UART_ss0_m__0__HSIOM)
    #define PC_PSoC_UART_SS0_M_HSIOM_PTR    ( (reg32 *) PC_PSoC_UART_ss0_m__0__HSIOM)
    
    #define PC_PSoC_UART_SS0_M_HSIOM_MASK       (PC_PSoC_UART_ss0_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS0_M_HSIOM_POS        (PC_PSoC_UART_ss0_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS0_M_HSIOM_SEL_GPIO   (PC_PSoC_UART_ss0_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS0_M_HSIOM_SEL_SPI    (PC_PSoC_UART_ss0_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_SS0_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS1_PIN)
    #define PC_PSoC_UART_SS1_M_HSIOM_REG    (*(reg32 *) PC_PSoC_UART_ss1_m__0__HSIOM)
    #define PC_PSoC_UART_SS1_M_HSIOM_PTR    ( (reg32 *) PC_PSoC_UART_ss1_m__0__HSIOM)
    
    #define PC_PSoC_UART_SS1_M_HSIOM_MASK       (PC_PSoC_UART_ss1_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS1_M_HSIOM_POS        (PC_PSoC_UART_ss1_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS1_M_HSIOM_SEL_GPIO   (PC_PSoC_UART_ss1_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS1_M_HSIOM_SEL_SPI    (PC_PSoC_UART_ss1_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_SS1_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS2_PIN)
    #define PC_PSoC_UART_SS2_M_HSIOM_REG    (*(reg32 *) PC_PSoC_UART_ss2_m__0__HSIOM)
    #define PC_PSoC_UART_SS2_M_HSIOM_PTR    ( (reg32 *) PC_PSoC_UART_ss2_m__0__HSIOM)
    
    #define PC_PSoC_UART_SS2_M_HSIOM_MASK       (PC_PSoC_UART_ss2_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS2_M_HSIOM_POS        (PC_PSoC_UART_ss2_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS2_M_HSIOM_SEL_GPIO   (PC_PSoC_UART_ss2_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS2_M_HSIOM_SEL_SPI    (PC_PSoC_UART_ss2_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_SS2_PIN) */

#if (PC_PSoC_UART_SPI_MASTER_SS3_PIN)
    #define PC_PSoC_UART_SS3_M_HSIOM_REG    (*(reg32 *) PC_PSoC_UART_ss3_m__0__HSIOM)
    #define PC_PSoC_UART_SS3_M_HSIOM_PTR    ( (reg32 *) PC_PSoC_UART_ss3_m__0__HSIOM)
    
    #define PC_PSoC_UART_SS3_M_HSIOM_MASK      (PC_PSoC_UART_ss3_m__0__HSIOM_MASK)
    #define PC_PSoC_UART_SS3_M_HSIOM_POS       (PC_PSoC_UART_ss3_m__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_SS3_M_HSIOM_SEL_GPIO  (PC_PSoC_UART_ss3_m__0__HSIOM_GPIO)
    #define PC_PSoC_UART_SS3_M_HSIOM_SEL_SPI   (PC_PSoC_UART_ss3_m__0__HSIOM_SPI)
#endif /* (PC_PSoC_UART_SPI_MASTER_SS3_PIN) */

#if (PC_PSoC_UART_UART_RX_PIN)
    #define PC_PSoC_UART_RX_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_rx__0__HSIOM)
    #define PC_PSoC_UART_RX_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_rx__0__HSIOM)
    
    #define PC_PSoC_UART_RX_HSIOM_MASK      (PC_PSoC_UART_rx__0__HSIOM_MASK)
    #define PC_PSoC_UART_RX_HSIOM_POS       (PC_PSoC_UART_rx__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_RX_HSIOM_SEL_GPIO  (PC_PSoC_UART_rx__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RX_HSIOM_SEL_UART  (PC_PSoC_UART_rx__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_UART_RX_PIN) */

#if (PC_PSoC_UART_UART_RX_WAKE_PIN)
    #define PC_PSoC_UART_RX_WAKE_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_rx_wake__0__HSIOM)
    #define PC_PSoC_UART_RX_WAKE_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_rx_wake__0__HSIOM)
    
    #define PC_PSoC_UART_RX_WAKE_HSIOM_MASK      (PC_PSoC_UART_rx_wake__0__HSIOM_MASK)
    #define PC_PSoC_UART_RX_WAKE_HSIOM_POS       (PC_PSoC_UART_rx_wake__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_RX_WAKE_HSIOM_SEL_GPIO  (PC_PSoC_UART_rx_wake__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RX_WAKE_HSIOM_SEL_UART  (PC_PSoC_UART_rx_wake__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_UART_WAKE_RX_PIN) */

#if (PC_PSoC_UART_UART_CTS_PIN)
    #define PC_PSoC_UART_CTS_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_cts__0__HSIOM)
    #define PC_PSoC_UART_CTS_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_cts__0__HSIOM)
    
    #define PC_PSoC_UART_CTS_HSIOM_MASK      (PC_PSoC_UART_cts__0__HSIOM_MASK)
    #define PC_PSoC_UART_CTS_HSIOM_POS       (PC_PSoC_UART_cts__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_CTS_HSIOM_SEL_GPIO  (PC_PSoC_UART_cts__0__HSIOM_GPIO)
    #define PC_PSoC_UART_CTS_HSIOM_SEL_UART  (PC_PSoC_UART_cts__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_UART_CTS_PIN) */

#if (PC_PSoC_UART_UART_TX_PIN)
    #define PC_PSoC_UART_TX_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_tx__0__HSIOM)
    #define PC_PSoC_UART_TX_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_tx__0__HSIOM)
    
    #define PC_PSoC_UART_TX_HSIOM_MASK      (PC_PSoC_UART_tx__0__HSIOM_MASK)
    #define PC_PSoC_UART_TX_HSIOM_POS       (PC_PSoC_UART_tx__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_TX_HSIOM_SEL_GPIO  (PC_PSoC_UART_tx__0__HSIOM_GPIO)
    #define PC_PSoC_UART_TX_HSIOM_SEL_UART  (PC_PSoC_UART_tx__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_UART_TX_PIN) */

#if (PC_PSoC_UART_UART_RX_TX_PIN)
    #define PC_PSoC_UART_RX_TX_HSIOM_REG   (*(reg32 *) PC_PSoC_UART_rx_tx__0__HSIOM)
    #define PC_PSoC_UART_RX_TX_HSIOM_PTR   ( (reg32 *) PC_PSoC_UART_rx_tx__0__HSIOM)
    
    #define PC_PSoC_UART_RX_TX_HSIOM_MASK      (PC_PSoC_UART_rx_tx__0__HSIOM_MASK)
    #define PC_PSoC_UART_RX_TX_HSIOM_POS       (PC_PSoC_UART_rx_tx__0__HSIOM_SHIFT)
    #define PC_PSoC_UART_RX_TX_HSIOM_SEL_GPIO  (PC_PSoC_UART_rx_tx__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RX_TX_HSIOM_SEL_UART  (PC_PSoC_UART_rx_tx__0__HSIOM_UART)
#endif /* (PC_PSoC_UART_UART_RX_TX_PIN) */

#if (PC_PSoC_UART_UART_RTS_PIN)
    #define PC_PSoC_UART_RTS_HSIOM_REG      (*(reg32 *) PC_PSoC_UART_rts__0__HSIOM)
    #define PC_PSoC_UART_RTS_HSIOM_PTR      ( (reg32 *) PC_PSoC_UART_rts__0__HSIOM)
    
    #define PC_PSoC_UART_RTS_HSIOM_MASK     (PC_PSoC_UART_rts__0__HSIOM_MASK)
    #define PC_PSoC_UART_RTS_HSIOM_POS      (PC_PSoC_UART_rts__0__HSIOM_SHIFT)    
    #define PC_PSoC_UART_RTS_HSIOM_SEL_GPIO (PC_PSoC_UART_rts__0__HSIOM_GPIO)
    #define PC_PSoC_UART_RTS_HSIOM_SEL_UART (PC_PSoC_UART_rts__0__HSIOM_UART)    
#endif /* (PC_PSoC_UART_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define PC_PSoC_UART_HSIOM_DEF_SEL      (0x00u)
#define PC_PSoC_UART_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for PC_PSoC_UART_CY_SCBIP_V0 
* and PC_PSoC_UART_CY_SCBIP_V1. It is not recommended to use them for 
* PC_PSoC_UART_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define PC_PSoC_UART_HSIOM_UART_SEL     (0x09u)
#define PC_PSoC_UART_HSIOM_I2C_SEL      (0x0Eu)
#define PC_PSoC_UART_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX       (0u)
#define PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX       (1u)
#define PC_PSoC_UART_SCLK_PIN_INDEX       (2u)
#define PC_PSoC_UART_SS0_PIN_INDEX       (3u)
#define PC_PSoC_UART_SS1_PIN_INDEX                  (4u)
#define PC_PSoC_UART_SS2_PIN_INDEX                  (5u)
#define PC_PSoC_UART_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define PC_PSoC_UART_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX)
#define PC_PSoC_UART_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX)
#define PC_PSoC_UART_SCLK_PIN_MASK     ((uint32) 0x01u << PC_PSoC_UART_SCLK_PIN_INDEX)
#define PC_PSoC_UART_SS0_PIN_MASK     ((uint32) 0x01u << PC_PSoC_UART_SS0_PIN_INDEX)
#define PC_PSoC_UART_SS1_PIN_MASK                ((uint32) 0x01u << PC_PSoC_UART_SS1_PIN_INDEX)
#define PC_PSoC_UART_SS2_PIN_MASK                ((uint32) 0x01u << PC_PSoC_UART_SS2_PIN_INDEX)
#define PC_PSoC_UART_SS3_PIN_MASK                ((uint32) 0x01u << PC_PSoC_UART_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define PC_PSoC_UART_INTCFG_TYPE_MASK           (0x03u)
#define PC_PSoC_UART_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define PC_PSoC_UART_PIN_DM_ALG_HIZ  (0u)
#define PC_PSoC_UART_PIN_DM_DIG_HIZ  (1u)
#define PC_PSoC_UART_PIN_DM_OD_LO    (4u)
#define PC_PSoC_UART_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define PC_PSoC_UART_DM_MASK    (0x7u)
#define PC_PSoC_UART_DM_SIZE    (3u)
#define PC_PSoC_UART_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) PC_PSoC_UART_DM_MASK << (PC_PSoC_UART_DM_SIZE * (pos)))) >> \
                                                              (PC_PSoC_UART_DM_SIZE * (pos)) )

#if (PC_PSoC_UART_TX_SDA_MISO_PIN)
    #define PC_PSoC_UART_CHECK_TX_SDA_MISO_PIN_USED \
                (PC_PSoC_UART_PIN_DM_ALG_HIZ != \
                    PC_PSoC_UART_GET_P4_PIN_DM(PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_PC, \
                                                   PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */

#if (PC_PSoC_UART_SS0_PIN)
    #define PC_PSoC_UART_CHECK_SS0_PIN_USED \
                (PC_PSoC_UART_PIN_DM_ALG_HIZ != \
                    PC_PSoC_UART_GET_P4_PIN_DM(PC_PSoC_UART_spi_ss0_PC, \
                                                   PC_PSoC_UART_spi_ss0_SHIFT))
#endif /* (PC_PSoC_UART_SS0_PIN) */

/* Set bits-mask in register */
#define PC_PSoC_UART_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define PC_PSoC_UART_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define PC_PSoC_UART_SET_HSIOM_SEL(reg, mask, pos, sel) PC_PSoC_UART_SET_REGISTER_BITS(reg, mask, pos, sel)
#define PC_PSoC_UART_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        PC_PSoC_UART_SET_REGISTER_BITS(reg, mask, pos, intType)
#define PC_PSoC_UART_SET_INP_DIS(reg, mask, val) PC_PSoC_UART_SET_REGISTER_BIT(reg, mask, val)

/* PC_PSoC_UART_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  PC_PSoC_UART_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (PC_PSoC_UART_CY_SCBIP_V0)
#if (PC_PSoC_UART_I2C_PINS)
    #define PC_PSoC_UART_SET_I2C_SCL_DR(val) PC_PSoC_UART_scl_Write(val)

    #define PC_PSoC_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                          PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SCL_HSIOM_REG,  \
                                                         PC_PSoC_UART_SCL_HSIOM_MASK, \
                                                         PC_PSoC_UART_SCL_HSIOM_POS,  \
                                                         (sel))
    #define PC_PSoC_UART_WAIT_SCL_SET_HIGH  (0u == PC_PSoC_UART_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
    #define PC_PSoC_UART_SET_I2C_SCL_DR(val) \
                            PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define PC_PSoC_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                    PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define PC_PSoC_UART_WAIT_SCL_SET_HIGH  (0u == PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (PC_PSoC_UART_RX_SCL_MOSI_PIN)
    #define PC_PSoC_UART_SET_I2C_SCL_DR(val) \
                            PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define PC_PSoC_UART_SET_I2C_SCL_HSIOM_SEL(sel) \
                            PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_RX_SCL_MOSI_HSIOM_REG,  \
                                                           PC_PSoC_UART_RX_SCL_MOSI_HSIOM_MASK, \
                                                           PC_PSoC_UART_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define PC_PSoC_UART_WAIT_SCL_SET_HIGH  (0u == PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define PC_PSoC_UART_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define PC_PSoC_UART_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define PC_PSoC_UART_WAIT_SCL_SET_HIGH  (0u)
#endif /* (PC_PSoC_UART_I2C_PINS) */

/* SCB I2C: sda signal */
#if (PC_PSoC_UART_I2C_PINS)
    #define PC_PSoC_UART_WAIT_SDA_SET_HIGH  (0u == PC_PSoC_UART_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (PC_PSoC_UART_TX_SDA_MISO_PIN)
    #define PC_PSoC_UART_WAIT_SDA_SET_HIGH  (0u == PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define PC_PSoC_UART_WAIT_SDA_SET_HIGH  (0u)
#endif /* (PC_PSoC_UART_MOSI_SCL_RX_PIN) */
#endif /* (PC_PSoC_UART_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
    #define PC_PSoC_UART_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
    #define PC_PSoC_UART_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(PC_PSoC_UART_UART_RX_WAKE_PIN)
    #define PC_PSoC_UART_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) PC_PSoC_UART_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define PC_PSoC_UART_REMOVE_MOSI_SCL_RX_WAKE_PIN    PC_PSoC_UART_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define PC_PSoC_UART_REMOVE_MOSI_SCL_RX_PIN         PC_PSoC_UART_REMOVE_RX_SCL_MOSI_PIN
#define PC_PSoC_UART_REMOVE_MISO_SDA_TX_PIN         PC_PSoC_UART_REMOVE_TX_SDA_MISO_PIN
#ifndef PC_PSoC_UART_REMOVE_SCLK_PIN
#define PC_PSoC_UART_REMOVE_SCLK_PIN                PC_PSoC_UART_REMOVE_SCLK_PIN
#endif /* PC_PSoC_UART_REMOVE_SCLK_PIN */
#ifndef PC_PSoC_UART_REMOVE_SS0_PIN
#define PC_PSoC_UART_REMOVE_SS0_PIN                 PC_PSoC_UART_REMOVE_SS0_PIN
#endif /* PC_PSoC_UART_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define PC_PSoC_UART_MOSI_SCL_RX_WAKE_PIN   PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN
#define PC_PSoC_UART_MOSI_SCL_RX_PIN        PC_PSoC_UART_RX_SCL_MOSI_PIN
#define PC_PSoC_UART_MISO_SDA_TX_PIN        PC_PSoC_UART_TX_SDA_MISO_PIN
#ifndef PC_PSoC_UART_SCLK_PIN
#define PC_PSoC_UART_SCLK_PIN               PC_PSoC_UART_SCLK_PIN
#endif /* PC_PSoC_UART_SCLK_PIN */
#ifndef PC_PSoC_UART_SS0_PIN
#define PC_PSoC_UART_SS0_PIN                PC_PSoC_UART_SS0_PIN
#endif /* PC_PSoC_UART_SS0_PIN */

#if (PC_PSoC_UART_MOSI_SCL_RX_WAKE_PIN)
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_HSIOM_REG     PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_HSIOM_PTR     PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_HSIOM_MASK    PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_HSIOM_POS     PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_INTCFG_REG    PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_INTCFG_PTR    PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN) */

#if (PC_PSoC_UART_MOSI_SCL_RX_PIN)
    #define PC_PSoC_UART_MOSI_SCL_RX_HSIOM_REG      PC_PSoC_UART_RX_SCL_MOSI_HSIOM_REG
    #define PC_PSoC_UART_MOSI_SCL_RX_HSIOM_PTR      PC_PSoC_UART_RX_SCL_MOSI_HSIOM_PTR
    #define PC_PSoC_UART_MOSI_SCL_RX_HSIOM_MASK     PC_PSoC_UART_RX_SCL_MOSI_HSIOM_MASK
    #define PC_PSoC_UART_MOSI_SCL_RX_HSIOM_POS      PC_PSoC_UART_RX_SCL_MOSI_HSIOM_POS
#endif /* (PC_PSoC_UART_MOSI_SCL_RX_PIN) */

#if (PC_PSoC_UART_MISO_SDA_TX_PIN)
    #define PC_PSoC_UART_MISO_SDA_TX_HSIOM_REG      PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG
    #define PC_PSoC_UART_MISO_SDA_TX_HSIOM_PTR      PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG
    #define PC_PSoC_UART_MISO_SDA_TX_HSIOM_MASK     PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG
    #define PC_PSoC_UART_MISO_SDA_TX_HSIOM_POS      PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG
#endif /* (PC_PSoC_UART_MISO_SDA_TX_PIN_PIN) */

#if (PC_PSoC_UART_SCLK_PIN)
    #ifndef PC_PSoC_UART_SCLK_HSIOM_REG
    #define PC_PSoC_UART_SCLK_HSIOM_REG     PC_PSoC_UART_SCLK_HSIOM_REG
    #define PC_PSoC_UART_SCLK_HSIOM_PTR     PC_PSoC_UART_SCLK_HSIOM_PTR
    #define PC_PSoC_UART_SCLK_HSIOM_MASK    PC_PSoC_UART_SCLK_HSIOM_MASK
    #define PC_PSoC_UART_SCLK_HSIOM_POS     PC_PSoC_UART_SCLK_HSIOM_POS
    #endif /* PC_PSoC_UART_SCLK_HSIOM_REG */
#endif /* (PC_PSoC_UART_SCLK_PIN) */

#if (PC_PSoC_UART_SS0_PIN)
    #ifndef PC_PSoC_UART_SS0_HSIOM_REG
    #define PC_PSoC_UART_SS0_HSIOM_REG      PC_PSoC_UART_SS0_HSIOM_REG
    #define PC_PSoC_UART_SS0_HSIOM_PTR      PC_PSoC_UART_SS0_HSIOM_PTR
    #define PC_PSoC_UART_SS0_HSIOM_MASK     PC_PSoC_UART_SS0_HSIOM_MASK
    #define PC_PSoC_UART_SS0_HSIOM_POS      PC_PSoC_UART_SS0_HSIOM_POS
    #endif /* PC_PSoC_UART_SS0_HSIOM_REG */
#endif /* (PC_PSoC_UART_SS0_PIN) */

#define PC_PSoC_UART_MOSI_SCL_RX_WAKE_PIN_INDEX PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX
#define PC_PSoC_UART_MOSI_SCL_RX_PIN_INDEX      PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX
#define PC_PSoC_UART_MISO_SDA_TX_PIN_INDEX      PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX
#ifndef PC_PSoC_UART_SCLK_PIN_INDEX
#define PC_PSoC_UART_SCLK_PIN_INDEX             PC_PSoC_UART_SCLK_PIN_INDEX
#endif /* PC_PSoC_UART_SCLK_PIN_INDEX */
#ifndef PC_PSoC_UART_SS0_PIN_INDEX
#define PC_PSoC_UART_SS0_PIN_INDEX              PC_PSoC_UART_SS0_PIN_INDEX
#endif /* PC_PSoC_UART_SS0_PIN_INDEX */

#define PC_PSoC_UART_MOSI_SCL_RX_WAKE_PIN_MASK PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_MASK
#define PC_PSoC_UART_MOSI_SCL_RX_PIN_MASK      PC_PSoC_UART_RX_SCL_MOSI_PIN_MASK
#define PC_PSoC_UART_MISO_SDA_TX_PIN_MASK      PC_PSoC_UART_TX_SDA_MISO_PIN_MASK
#ifndef PC_PSoC_UART_SCLK_PIN_MASK
#define PC_PSoC_UART_SCLK_PIN_MASK             PC_PSoC_UART_SCLK_PIN_MASK
#endif /* PC_PSoC_UART_SCLK_PIN_MASK */
#ifndef PC_PSoC_UART_SS0_PIN_MASK
#define PC_PSoC_UART_SS0_PIN_MASK              PC_PSoC_UART_SS0_PIN_MASK
#endif /* PC_PSoC_UART_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_PC_PSoC_UART_H) */


/* [] END OF FILE */
