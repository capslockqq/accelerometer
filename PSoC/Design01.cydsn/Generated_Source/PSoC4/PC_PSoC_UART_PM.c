/***************************************************************************//**
* \file PC_PSoC_UART_PM.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
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

#include "PC_PSoC_UART.h"
#include "PC_PSoC_UART_PVT.h"

#if(PC_PSoC_UART_SCB_MODE_I2C_INC)
    #include "PC_PSoC_UART_I2C_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_I2C_INC) */

#if(PC_PSoC_UART_SCB_MODE_EZI2C_INC)
    #include "PC_PSoC_UART_EZI2C_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_EZI2C_INC) */

#if(PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC)
    #include "PC_PSoC_UART_SPI_UART_PVT.h"
#endif /* (PC_PSoC_UART_SCB_MODE_SPI_INC || PC_PSoC_UART_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG || \
   (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG   && (!PC_PSoC_UART_I2C_WAKE_ENABLE_CONST))   || \
   (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG && (!PC_PSoC_UART_EZI2C_WAKE_ENABLE_CONST)) || \
   (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG   && (!PC_PSoC_UART_SPI_WAKE_ENABLE_CONST))   || \
   (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG  && (!PC_PSoC_UART_UART_WAKE_ENABLE_CONST)))

    PC_PSoC_UART_BACKUP_STRUCT PC_PSoC_UART_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: PC_PSoC_UART_Sleep
****************************************************************************//**
*
*  Prepares the PC_PSoC_UART component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the PC_PSoC_UART_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void PC_PSoC_UART_Sleep(void)
{
#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(PC_PSoC_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(PC_PSoC_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            PC_PSoC_UART_I2CSaveConfig();
        }
        else if(PC_PSoC_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            PC_PSoC_UART_EzI2CSaveConfig();
        }
    #if(!PC_PSoC_UART_CY_SCBIP_V1)
        else if(PC_PSoC_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            PC_PSoC_UART_SpiSaveConfig();
        }
        else if(PC_PSoC_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            PC_PSoC_UART_UartSaveConfig();
        }
    #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        PC_PSoC_UART_backup.enableState = (uint8) PC_PSoC_UART_GET_CTRL_ENABLED;

        if(0u != PC_PSoC_UART_backup.enableState)
        {
            PC_PSoC_UART_Stop();
        }
    }

#else

    #if (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG && PC_PSoC_UART_I2C_WAKE_ENABLE_CONST)
        PC_PSoC_UART_I2CSaveConfig();

    #elif (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG && PC_PSoC_UART_EZI2C_WAKE_ENABLE_CONST)
        PC_PSoC_UART_EzI2CSaveConfig();

    #elif (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG && PC_PSoC_UART_SPI_WAKE_ENABLE_CONST)
        PC_PSoC_UART_SpiSaveConfig();

    #elif (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG && PC_PSoC_UART_UART_WAKE_ENABLE_CONST)
        PC_PSoC_UART_UartSaveConfig();

    #else

        PC_PSoC_UART_backup.enableState = (uint8) PC_PSoC_UART_GET_CTRL_ENABLED;

        if(0u != PC_PSoC_UART_backup.enableState)
        {
            PC_PSoC_UART_Stop();
        }

    #endif /* defined (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG) && (PC_PSoC_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: PC_PSoC_UART_Wakeup
****************************************************************************//**
*
*  Prepares the PC_PSoC_UART component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the PC_PSoC_UART_Wakeup() function without first calling the 
*   PC_PSoC_UART_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void PC_PSoC_UART_Wakeup(void)
{
#if(PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG)

    if(PC_PSoC_UART_SCB_WAKE_ENABLE_CHECK)
    {
        if(PC_PSoC_UART_SCB_MODE_I2C_RUNTM_CFG)
        {
            PC_PSoC_UART_I2CRestoreConfig();
        }
        else if(PC_PSoC_UART_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            PC_PSoC_UART_EzI2CRestoreConfig();
        }
    #if(!PC_PSoC_UART_CY_SCBIP_V1)
        else if(PC_PSoC_UART_SCB_MODE_SPI_RUNTM_CFG)
        {
            PC_PSoC_UART_SpiRestoreConfig();
        }
        else if(PC_PSoC_UART_SCB_MODE_UART_RUNTM_CFG)
        {
            PC_PSoC_UART_UartRestoreConfig();
        }
    #endif /* (!PC_PSoC_UART_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != PC_PSoC_UART_backup.enableState)
        {
            PC_PSoC_UART_Enable();
        }
    }

#else

    #if (PC_PSoC_UART_SCB_MODE_I2C_CONST_CFG  && PC_PSoC_UART_I2C_WAKE_ENABLE_CONST)
        PC_PSoC_UART_I2CRestoreConfig();

    #elif (PC_PSoC_UART_SCB_MODE_EZI2C_CONST_CFG && PC_PSoC_UART_EZI2C_WAKE_ENABLE_CONST)
        PC_PSoC_UART_EzI2CRestoreConfig();

    #elif (PC_PSoC_UART_SCB_MODE_SPI_CONST_CFG && PC_PSoC_UART_SPI_WAKE_ENABLE_CONST)
        PC_PSoC_UART_SpiRestoreConfig();

    #elif (PC_PSoC_UART_SCB_MODE_UART_CONST_CFG && PC_PSoC_UART_UART_WAKE_ENABLE_CONST)
        PC_PSoC_UART_UartRestoreConfig();

    #else

        if(0u != PC_PSoC_UART_backup.enableState)
        {
            PC_PSoC_UART_Enable();
        }

    #endif /* (PC_PSoC_UART_I2C_WAKE_ENABLE_CONST) */

#endif /* (PC_PSoC_UART_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
