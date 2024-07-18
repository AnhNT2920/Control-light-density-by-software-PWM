/**
 * @file  : Driver_PIT.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file Driver_PIT.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "../Includes/HAL/HAL_PIT.h"
#include "../Includes/Driver/Driver_PIT.h"
#include <stdlib.h>

/*******************************************************************************
 * Variable
 ******************************************************************************/

static callback func_callback_ptr = NULL;

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*Functions*********************************************************************
*
* Function name: Driver_PIT_register_callabck.
* Description: Register a callback function for PIT interrupt handler
*
END***************************************************************************/
void Driver_PIT_register_callabck(callback callback_func)
{
    /*Register callback function*/
    func_callback_ptr = callback_func;

    return;
}

/*Functions*********************************************************************
*
* Function name: PIT_IRQHandler.
* Description: Interrupt handler of the PIT module
*
END***************************************************************************/
void PIT_IRQHandler(void)
{
    /*If timer 0 send interrupt request*/
    if (0 == HAL_PIT_TFLGn_read_TIF(0))
    {
        /*Clear interrupt flag*/
        HAL_PIT_TFLGn_set_TIF(0);
    }
    /*If timer 1 send interrupt request*/
    else if (1 == HAL_PIT_TFLGn_read_TIF(1))
    {
        /*Clear interrupt flag*/
        HAL_PIT_TFLGn_set_TIF(1);
    }
    else
    {
        /*Clear interrupt flag of timer 0*/
        HAL_PIT_TFLGn_set_TIF(0);
        /*Clear interrupt flag of timer 1*/
        HAL_PIT_TFLGn_set_TIF(1);
    }

    /*If callback pointer is not NULL*/
    if (NULL != func_callback_ptr)
    {
        /*Call the callback function*/
        func_callback_ptr();
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_init.
* Description: Init the PIT module
*
END***************************************************************************/
void Driver_PIT_init(PIT_config_info *PIT_config)
{
    /*Check input*/
    if (NULL != PIT_config)
    {
        /*Configure the MCR register*/
        Driver_PIT_config_MCR(&(PIT_config->MCR_config));
        /*Configure the TCTRLn register*/
        Driver_PIT_config_TCTRLn(&(PIT_config->TCTRLn_config));
        /*Set load value for PIT timer n*/
        Driver_PIT_set_load_value(PIT_config->TCTRLn_config.timer_index, PIT_config->load_value);

        /*Check if interrupt request is enabled*/
        if ((IRQ_ENABLED == PIT_config->TCTRLn_config.IRQ_state))
        {
            /*Enable interrupt handler*/
            HAL_PIT_enable_IRQ_Handler();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_config_MCR
* Description: Configure the MCR register
*
END***************************************************************************/
void Driver_PIT_config_MCR(MCR_config_info *MCR_config)
{
    /*Check input*/
    if (NULL != MCR_config)
    {
        /*Select freeze mode*/
        Driver_PIT_select_freeze_mode(MCR_config->freeze_mode);
        /*Select module state*/
        Driver_PIT_select_module_state(MCR_config->module_state);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_freeze_mode
* Description: Select the freeze mode for PIT timer
*
END***************************************************************************/
void Driver_PIT_select_freeze_mode(MCR_FRZ_type_enum_t freeze_mode)
{
    /*Check input*/
    if ((TIMERS_CONTINUE_IN_DEBUG <= freeze_mode) && (freeze_mode <= TIMERS_STOPPED_IN_DEBUG))
    {
        /*Set freeze mode*/
        HAL_PIT_MCR_set_FRZ((uint8_t)freeze_mode);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_module_state
* Description: Select the module state for PIT
*
END***************************************************************************/
void Driver_PIT_select_module_state(MCR_MDIS_type_enum_t module_state)
{
    /*Check input*/
    if ((PIT_ENABLED <= module_state) && (module_state <= PIT_DISABLED))
    {
        /*Set module state*/
        HAL_PIT_MCR_set_MDIS((uint8_t)module_state);
    }
    else
    {
        /*Do nothing*/
    }
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_set_load_value
* Description: Set load value for PIT timer n
*
END***************************************************************************/
void Driver_PIT_set_load_value(uint8_t timer_index, uint32_t load_value)
{
    /*Check timer index*/
    if (timer_index <= 1)
    {
        /*Set load value for timer n*/
        HAL_PIT_LDVALn_set_TSV(timer_index, load_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_config_TCTRLn
* Description: Configure the TCTRLn register
*
END***************************************************************************/
void Driver_PIT_config_TCTRLn(TCTRL_config_info *TCTRLn_config)
{
    /*Check input*/
    if (NULL != TCTRLn_config)
    {
        /*Select timer n state*/
        Driver_PIT_select_Timer_state(TCTRLn_config->timer_index, TCTRLn_config->timer_state);
        /*Select timer n interrupt request state*/
        Driver_PIT_select_IRQ_state(TCTRLn_config->timer_index, TCTRLn_config->IRQ_state);
        /*Select timer n chain mode*/
        Driver_PIT_select_Chain_Mode(TCTRLn_config->timer_index, TCTRLn_config->chain_mode);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_Timer_state
* Description: Select the timer n state is disabled or enabled
*
END***************************************************************************/
void Driver_PIT_select_Timer_state(uint8_t timer_index, TCTRL_TEN_type_enum_t timer_state)
{
    /*Check timer index input*/
    if (timer_index <= 1)
    {
        /*Check timer state input*/
        if ((TIMER_DISABLED <= timer_state) && (timer_state <= TIMER_ENABLED))
        {
            /*Set timer n state*/
            HAL_PIT_TCTRLn_set_TEN(timer_index, (uint8_t)timer_state);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_IRQ_state
* Description: Select the timer n interrupt request state is enabled or disabled
*
END***************************************************************************/
void Driver_PIT_select_IRQ_state(uint8_t timer_index, TCTRL_TIE_type_enum_t IRQ_state)
{
    /*Check timer index input*/
    if (timer_index <= 1)
    {
        /*Check timer n interrupt request state*/
        if ((IRQ_DISABLED <= IRQ_state) && (IRQ_state <= IRQ_ENABLED))
        {
            /*Set timer n interrupt request state*/
            HAL_PIT_TCTRLn_set_TIE(timer_index, (uint8_t)IRQ_state);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_Chain_Mode
* Description: Select the chain mode of PIT timer n
*
END***************************************************************************/
void Driver_PIT_select_Chain_Mode(uint8_t timer_index, TCTRL_CHN_type_enum_t chain_mode)
{
    /*Check timer n index*/
    if (timer_index <= 1)
    {
        /*Check timer n chain mode state*/
        if ((CHAIN_MODE_DISABLED <= chain_mode) && (chain_mode <= CHAIN_MODE_ENABLED))
        {
            /*Set timer n chain mode state*/
            HAL_PIT_TCTRLn_set_CHN(timer_index, (uint8_t)chain_mode);
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_PIT_select_Chain_Mode
* Description: Select the chain mode of PIT timer n
*
END***************************************************************************/
void Driver_PIT_set_IRQ_flag(uint8_t timer_index)
{
    /*Check timer index input*/
    if (timer_index <= 1)
    {
        /*Set interrupt flag of timer n to 1*/
        HAL_PIT_TFLGn_set_TIF(timer_index);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}
/*EOF*/
