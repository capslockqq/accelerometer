/***************************************************************************//**
* \file PC_PSoC_UART.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PC_PSoC_UART_PVT.h"

#if (PC_PSoC_UART_SCB_MODE_I2C_INC)
    #include "PC_PSoC_UART_I2C_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_I2C_INC) */

#if (PC_PSoC_UART_SCB_MODE_EZI2C_INC)
    #include "PC_PSoC_UART_EZI2C_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_EZI2C_INC) */

#if (PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC)
    #include "PC_PSoC_UART_SPI_UART_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 PC_PSoC_UART_scbMode = PC_PSoC_UART_SCB_MODE_UNCONFIG;
    uint8 PC_PSoC_UART_scbEnableWake;
    uint8 PC_PSoC_UART_scbEnableIntr;

    /* I2C configuration variables */
    uint8 PC_PSoC_UART_mode;
    uint8 PC_PSoC_UART_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * PC_PSoC_UART_rxBuffer;
    uint8  PC_PSoC_UART_rxDataBits;
    uint32 PC_PSoC_UART_rxBufferSize;

    volatile uint8 * PC_PSoC_UART_txBuffer;
    uint8  PC_PSoC_UART_txDataBits;
    uint32 PC_PSoC_UART_txBufferSize;

    /* EZI2C configuration variables */
    uint8 PC_PSoC_UART_numberOfAddr;
    uint8 PC_PSoC_UART_subAddrSize;
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** PC_PSoC_UART_initVar indicates whether the PC_PSoC_UART 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the PC_PSoC_UART_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  PC_PSoC_UART_Init() function can be called before the 
*  PC_PSoC_UART_Start() or PC_PSoC_UART_Enable() function.
*/
uint8 PC_PSoC_UART_initVar = 0u;


#if (! (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG || \
        PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * PC_PSoC_UART_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent PC_PSoC_UART_Enable() call.
    */
    uint16 PC_PSoC_UART_IntrTxMask = 0u;
#endif /* (! (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG || \
              PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER)
    void (*PC_PSoC_UART_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER) */
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void PC_PSoC_UART_ScbEnableIntr(void);
static void PC_PSoC_UART_ScbModeStop(void);
static void PC_PSoC_UART_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: PC_PSoC_UART_Init
****************************************************************************//**
*
*  Initializes the PC_PSoC_UART component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  PC_PSoC_UART_I2CInit, PC_PSoC_UART_SpiInit, 
*  PC_PSoC_UART_UartInit or PC_PSoC_UART_EzI2CInit.
*
*******************************************************************************/
void PC_PSoC_UART_Init(void)
{
#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    if (PC_PSoC_UART_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        PC_PSoC_UART_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG)
    PC_PSoC_UART_I2CInit();

#elif (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG)
    PC_PSoC_UART_SpiInit();

#elif (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG)
    PC_PSoC_UART_UartInit();

#elif (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG)
    PC_PSoC_UART_EzI2CInit();

#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_Enable
****************************************************************************//**
*
*  Enables PC_PSoC_UART component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  PC_PSoC_UART_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The PC_PSoC_UART configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured PC_PSoC_UART”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void PC_PSoC_UART_Enable(void)
{
#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!PC_PSoC_UART_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        PC_PSoC_UART_CTRL_REG |= PC_PSoC_UART_CTRL_ENABLED;

        PC_PSoC_UART_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        PC_PSoC_UART_ScbModePostEnable();
    }
#else
    PC_PSoC_UART_CTRL_REG |= PC_PSoC_UART_CTRL_ENABLED;

    PC_PSoC_UART_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    PC_PSoC_UART_ScbModePostEnable();
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_Start
****************************************************************************//**
*
*  Invokes PC_PSoC_UART_Init() and PC_PSoC_UART_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  PC_PSoC_UART_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void PC_PSoC_UART_Start(void)
{
    if (0u == PC_PSoC_UART_initVar)
    {
        PC_PSoC_UART_Init();
        PC_PSoC_UART_initVar = 1u; /* Component was initialized */
    }

    PC_PSoC_UART_Enable();
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_Stop
****************************************************************************//**
*
*  Disables the PC_PSoC_UART component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function PC_PSoC_UART_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void PC_PSoC_UART_Stop(void)
{
#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
    PC_PSoC_UART_DisableInt();
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    PC_PSoC_UART_ScbModeStop();

    /* Disable SCB IP */
    PC_PSoC_UART_CTRL_REG &= (uint32) ~PC_PSoC_UART_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    PC_PSoC_UART_SetTxInterruptMode(PC_PSoC_UART_NO_INTR_SOURCES);

#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
    PC_PSoC_UART_ClearPendingInt();
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void PC_PSoC_UART_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = PC_PSoC_UART_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~PC_PSoC_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (PC_PSoC_UART_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    PC_PSoC_UART_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void PC_PSoC_UART_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = PC_PSoC_UART_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~PC_PSoC_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (PC_PSoC_UART_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    PC_PSoC_UART_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: PC_PSoC_UART_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void PC_PSoC_UART_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER)
        PC_PSoC_UART_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_PC_PSoC_UART_CUSTOM_INTR_HANDLER) */
    }
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: PC_PSoC_UART_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void PC_PSoC_UART_ScbEnableIntr(void)
{
#if (PC_PSoC_UART_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != PC_PSoC_UART_scbEnableIntr)
        {
            PC_PSoC_UART_EnableInt();
        }

    #else
        PC_PSoC_UART_EnableInt();

    #endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (PC_PSoC_UART_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void PC_PSoC_UART_ScbModePostEnable(void)
{
#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!PC_PSoC_UART_CY_SCBIP_V1)
    if (PC_PSoC_UART_SCB_MODE_SPI_RUNTM_CFG)
    {
        PC_PSoC_UART_SpiPostEnable();
    }
    else if (PC_PSoC_UART_SCB_MODE_UART_RUNTM_CFG)
    {
        PC_PSoC_UART_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */

#elif (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG)
    PC_PSoC_UART_SpiPostEnable();

#elif (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG)
    PC_PSoC_UART_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void PC_PSoC_UART_ScbModeStop(void)
{
#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    if (PC_PSoC_UART_SCB_MODE_I2C_RUNTM_CFG)
    {
        PC_PSoC_UART_I2CStop();
    }
    else if (PC_PSoC_UART_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        PC_PSoC_UART_EzI2CStop();
    }
#if (!PC_PSoC_UART_CY_SCBIP_V1)
    else if (PC_PSoC_UART_SCB_MODE_SPI_RUNTM_CFG)
    {
        PC_PSoC_UART_SpiStop();
    }
    else if (PC_PSoC_UART_SCB_MODE_UART_RUNTM_CFG)
    {
        PC_PSoC_UART_UartStop();
    }
#endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG)
    PC_PSoC_UART_I2CStop();

#elif (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG)
    PC_PSoC_UART_EzI2CStop();

#elif (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG)
    PC_PSoC_UART_SpiStop();

#elif (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG)
    PC_PSoC_UART_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: PC_PSoC_UART_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void PC_PSoC_UART_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[PC_PSoC_UART_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!PC_PSoC_UART_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
        
        uint32 hsiomSel[PC_PSoC_UART_SCB_PINS_NUMBER] = 
        {
            PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (PC_PSoC_UART_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (PC_PSoC_UART_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < PC_PSoC_UART_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = PC_PSoC_UART_PIN_DM_ALG_HIZ;
        }

        if ((PC_PSoC_UART_SCB_MODE_I2C   == mode) ||
            (PC_PSoC_UART_SCB_MODE_EZI2C == mode))
        {
        #if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
            hsiomSel[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_OD_LO;
        #elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_OD_LO;
        #else
        #endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */
        
        #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
            hsiomSel[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_PIN_DM_OD_LO;
        #endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */
        }
    #if (!PC_PSoC_UART_CY_SCBIP_V1)
        else if (PC_PSoC_UART_SCB_MODE_SPI == mode)
        {
        #if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
            hsiomSel[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */
        
        #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
            hsiomSel[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */
        
        #if (PC_PSoC_UART_SCLK_PIN)
            hsiomSel[PC_PSoC_UART_SCLK_PIN_INDEX] = PC_PSoC_UART_SCLK_HSIOM_SEL_SPI;
        #endif /* (PC_PSoC_UART_SCLK_PIN) */

            if (PC_PSoC_UART_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
                pinsDm[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsDm[PC_PSoC_UART_SCLK_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;

            #if (PC_PSoC_UART_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_SS0_HSIOM_SEL_SPI;
                pinsDm  [PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
            #endif /* (PC_PSoC_UART_SS0_PIN) */

            #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= PC_PSoC_UART_TX_SDA_MISO_PIN_MASK;
            #endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsDm[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
                pinsDm[PC_PSoC_UART_SCLK_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;

            #if (PC_PSoC_UART_SS0_PIN)
                hsiomSel [PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_SS0_HSIOM_SEL_SPI;
                pinsDm   [PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsInBuf |= PC_PSoC_UART_SS0_PIN_MASK;
            #endif /* (PC_PSoC_UART_SS0_PIN) */

            #if (PC_PSoC_UART_SS1_PIN)
                hsiomSel [PC_PSoC_UART_SS1_PIN_INDEX] = PC_PSoC_UART_SS1_HSIOM_SEL_SPI;
                pinsDm   [PC_PSoC_UART_SS1_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsInBuf |= PC_PSoC_UART_SS1_PIN_MASK;
            #endif /* (PC_PSoC_UART_SS1_PIN) */

            #if (PC_PSoC_UART_SS2_PIN)
                hsiomSel [PC_PSoC_UART_SS2_PIN_INDEX] = PC_PSoC_UART_SS2_HSIOM_SEL_SPI;
                pinsDm   [PC_PSoC_UART_SS2_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsInBuf |= PC_PSoC_UART_SS2_PIN_MASK;
            #endif /* (PC_PSoC_UART_SS2_PIN) */

            #if (PC_PSoC_UART_SS3_PIN)
                hsiomSel [PC_PSoC_UART_SS3_PIN_INDEX] = PC_PSoC_UART_SS3_HSIOM_SEL_SPI;
                pinsDm   [PC_PSoC_UART_SS3_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                pinsInBuf |= PC_PSoC_UART_SS3_PIN_MASK;
            #endif /* (PC_PSoC_UART_SS3_PIN) */

                /* Disable input buffers */
            #if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
                pinsInBuf |= PC_PSoC_UART_RX_SCL_MOSI_PIN_MASK;
            #elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */

            #if (PC_PSoC_UART_SCLK_PIN)
                pinsInBuf |= PC_PSoC_UART_SCLK_PIN_MASK;
            #endif /* (PC_PSoC_UART_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (PC_PSoC_UART_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
                hsiomSel[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_PIN_DM_OD_LO;
            #endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (PC_PSoC_UART_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
                    hsiomSel[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
                #elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
                #else
                #endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */
                }

                if (0u != (PC_PSoC_UART_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
                    hsiomSel[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= PC_PSoC_UART_TX_SDA_MISO_PIN_MASK;
                #endif /* (PC_PSoC_UART_TX_SDA_MISO_PIN) */
                }

            #if !(PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1)
                if (PC_PSoC_UART_UART_MODE_STD == subMode)
                {
                    if (0u != (PC_PSoC_UART_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (PC_PSoC_UART_SCLK_PIN)
                        hsiomSel[PC_PSoC_UART_SCLK_PIN_INDEX] = PC_PSoC_UART_SCLK_HSIOM_SEL_UART;
                        pinsDm  [PC_PSoC_UART_SCLK_PIN_INDEX] = PC_PSoC_UART_PIN_DM_DIG_HIZ;
                    #endif /* (PC_PSoC_UART_SCLK_PIN) */
                    }

                    if (0u != (PC_PSoC_UART_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (PC_PSoC_UART_SS0_PIN)
                        hsiomSel[PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_SS0_HSIOM_SEL_UART;
                        pinsDm  [PC_PSoC_UART_SS0_PIN_INDEX] = PC_PSoC_UART_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= PC_PSoC_UART_SS0_PIN_MASK;
                    #endif /* (PC_PSoC_UART_SS0_PIN) */
                    }
                }
            #endif /* !(PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1) */
            }
        }
    #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (PC_PSoC_UART_RX_SCL_MOSI_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_RX_SCL_MOSI_HSIOM_REG,
                                       PC_PSoC_UART_RX_SCL_MOSI_HSIOM_MASK,
                                       PC_PSoC_UART_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX]);

        PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_RX_SCL_MOSI_PIN_INDEX]);

        #if (!PC_PSoC_UART_CY_SCBIP_V1)
            PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         PC_PSoC_UART_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & PC_PSoC_UART_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
    
    #elif (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       PC_PSoC_UART_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     PC_PSoC_UART_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        PC_PSoC_UART_SET_INCFG_TYPE(PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        PC_PSoC_UART_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        PC_PSoC_UART_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (PC_PSoC_UART_RX_WAKE_SCL_MOSI_PIN) */

    #if (PC_PSoC_UART_TX_SDA_MISO_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_TX_SDA_MISO_HSIOM_REG,
                                       PC_PSoC_UART_TX_SDA_MISO_HSIOM_MASK,
                                       PC_PSoC_UART_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX]);

        PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_TX_SDA_MISO_PIN_INDEX]);

    #if (!PC_PSoC_UART_CY_SCBIP_V1)
        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     PC_PSoC_UART_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & PC_PSoC_UART_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
    #endif /* (PC_PSoC_UART_RX_SCL_MOSI_PIN) */

    #if (PC_PSoC_UART_SCLK_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SCLK_HSIOM_REG,
                                       PC_PSoC_UART_SCLK_HSIOM_MASK,
                                       PC_PSoC_UART_SCLK_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_SCLK_PIN_INDEX]);

        PC_PSoC_UART_spi_sclk_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_SCLK_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_spi_sclk_INP_DIS,
                                     PC_PSoC_UART_spi_sclk_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_SCLK_PIN_MASK)));
    #endif /* (PC_PSoC_UART_SCLK_PIN) */

    #if (PC_PSoC_UART_SS0_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SS0_HSIOM_REG,
                                       PC_PSoC_UART_SS0_HSIOM_MASK,
                                       PC_PSoC_UART_SS0_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_SS0_PIN_INDEX]);

        PC_PSoC_UART_spi_ss0_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_SS0_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_spi_ss0_INP_DIS,
                                     PC_PSoC_UART_spi_ss0_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_SS0_PIN_MASK)));
    #endif /* (PC_PSoC_UART_SS0_PIN) */

    #if (PC_PSoC_UART_SS1_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SS1_HSIOM_REG,
                                       PC_PSoC_UART_SS1_HSIOM_MASK,
                                       PC_PSoC_UART_SS1_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_SS1_PIN_INDEX]);

        PC_PSoC_UART_spi_ss1_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_SS1_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_spi_ss1_INP_DIS,
                                     PC_PSoC_UART_spi_ss1_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_SS1_PIN_MASK)));
    #endif /* (PC_PSoC_UART_SS1_PIN) */

    #if (PC_PSoC_UART_SS2_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SS2_HSIOM_REG,
                                       PC_PSoC_UART_SS2_HSIOM_MASK,
                                       PC_PSoC_UART_SS2_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_SS2_PIN_INDEX]);

        PC_PSoC_UART_spi_ss2_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_SS2_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_spi_ss2_INP_DIS,
                                     PC_PSoC_UART_spi_ss2_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_SS2_PIN_MASK)));
    #endif /* (PC_PSoC_UART_SS2_PIN) */

    #if (PC_PSoC_UART_SS3_PIN)
        PC_PSoC_UART_SET_HSIOM_SEL(PC_PSoC_UART_SS3_HSIOM_REG,
                                       PC_PSoC_UART_SS3_HSIOM_MASK,
                                       PC_PSoC_UART_SS3_HSIOM_POS,
                                       hsiomSel[PC_PSoC_UART_SS3_PIN_INDEX]);

        PC_PSoC_UART_spi_ss3_SetDriveMode((uint8) pinsDm[PC_PSoC_UART_SS3_PIN_INDEX]);

        PC_PSoC_UART_SET_INP_DIS(PC_PSoC_UART_spi_ss3_INP_DIS,
                                     PC_PSoC_UART_spi_ss3_MASK,
                                     (0u != (pinsInBuf & PC_PSoC_UART_SS3_PIN_MASK)));
    #endif /* (PC_PSoC_UART_SS3_PIN) */
    }

#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: PC_PSoC_UART_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void PC_PSoC_UART_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (PC_PSoC_UART_CTRL_REG & PC_PSoC_UART_CTRL_EC_AM_MODE)) &&
            (0u == (PC_PSoC_UART_I2C_CTRL_REG & PC_PSoC_UART_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            PC_PSoC_UART_CTRL_REG &= ~PC_PSoC_UART_CTRL_EC_AM_MODE;
            PC_PSoC_UART_CTRL_REG |=  PC_PSoC_UART_CTRL_EC_AM_MODE;
        }

        PC_PSoC_UART_I2C_SLAVE_CMD_REG = PC_PSoC_UART_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (PC_PSoC_UART_CY_SCBIP_V0 || PC_PSoC_UART_CY_SCBIP_V1) */


/* [] END OF FILE */
