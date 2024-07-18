/**
 * @file  : HAL_PIT.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file HAL_PIT.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "MKL46Z4.h"

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- MCR register bit setting functions group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_PIT_MCR_set_MDIS.
* Description: Select the PIT module's state (Timers disabled/enabled)
*
END***************************************************************************/
void HAL_PIT_MCR_set_MDIS(uint8_t MDIS_value)
{
    /*If the PIT Timers is enabled*/
    if (0 == MDIS_value)
    {
        /*Write 0 to the MDIS bit field*/
        PIT->MCR &= ~(1u << PIT_MCR_MDIS_SHIFT);
    }
    /*If the PIT timers is disabled*/
    else if (1 == MDIS_value)
    {
        /*Write 1 to the MDIS bit field*/
        PIT->MCR |= PIT_MCR_MDIS_MASK;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_PIT_MCR_set_FRZ.
* Description: Set timers continue to run or stop in debug mode
*
END***************************************************************************/
void HAL_PIT_MCR_set_FRZ(uint8_t FRZ_value)
{
    /*If timers continue to run in debug mode*/
    if (0 == FRZ_value)
    {
        /*Write 0 to the FRZ bit field*/
        PIT->MCR &= ~(1u << PIT_MCR_FRZ_SHIFT);
    }
    /*If timers stop in debug mode*/
    else if (1 == FRZ_value)
    {
        /*Write 1 to the FRZ bit field*/
        PIT->MCR |= PIT_MCR_FRZ_MASK;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*!
 * @}
 */ /* end of group MCR register bit setting functions */

/* ----------------------------------------------------------------------------
   -- LDVALn register functions group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_PIT_LDVALn_set_TSV.
* Description: Set load value for timer n
*
END***************************************************************************/
void HAL_PIT_LDVALn_set_TSV(uint8_t timer_index, uint32_t TSV_value)
{
    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*Set load value*/
        PIT_LDVAL0 = TSV_value;
        break;
    }
    case 1:
    {
        /*Set load value*/
        PIT_LDVAL1 = TSV_value;
        break;
    }
    default:
        break;
    }

    return;
}

/*!
 * @}
 */ /* end of group LDVALn register functions */

 /* ----------------------------------------------------------------------------
   -- TCTRLn register bit setting functions group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_PIT_TCTRLn_set_CHN.
* Description: Set chain mode state for PIT timer
*
END***************************************************************************/
void HAL_PIT_TCTRLn_set_CHN(uint8_t timer_index, uint8_t CHN_value)
{
    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*If timer is chained to previous timer*/
        if (1 == CHN_value)
        {
            /*Write 1 to the CHN bit field*/
            PIT_TCTRL0 |= PIT_TCTRL_CHN_MASK;
        }
        /*If timer is not chained*/
        else
        {
            /*Write 0 to the CHN bit field*/
            PIT_TCTRL0 &= ~(1u << PIT_TCTRL_CHN_SHIFT);
        }

        break;
    }
    case 1:
    {
        /*If timer is chained to previous timer*/
        if (1 == CHN_value)
        {
            /*Write 1 to the CHN bit field*/
            PIT_TCTRL1 |= PIT_TCTRL_CHN_MASK;
        }
        /*If timer is not chained*/
        else
        {
            /*Write 0 to the CHN bit field*/
            PIT_TCTRL1 &= ~(1u << PIT_TCTRL_CHN_SHIFT);
        }

        break;
    }
    default:
        break;
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_PIT_TCTRLn_set_TIE.
* Description: Set Timer n interrupt enabled or disabled
*
END***************************************************************************/
void HAL_PIT_TCTRLn_set_TIE(uint8_t timer_index, uint8_t TIE_value)
{
    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*If interrupt request from timer 0 is enabled*/
        if (1 == TIE_value)
        {
            /*Write 1 to the TIE bit field*/
            PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;
        }
        /*If interrupt request from timer 0 is disabled*/
        else
        {
            /*Write 0 to the TIE bit field*/
            PIT_TCTRL0 &= ~(1u << PIT_TCTRL_TIE_SHIFT);
        }

        break;
    }
    case 1:
    {
        /*If interrupt request from timer 1 is enabled*/
        if (1 == TIE_value)
        {
            /*Write 1 to the TIE bit field*/
            PIT_TCTRL1 |= PIT_TCTRL_TIE_MASK;
        }
        /*If interrupt request from timer 0 is disabled*/
        else
        {
            /*Write 0 to the TIE bit field*/
            PIT_TCTRL1 &= ~(1u << PIT_TCTRL_TIE_SHIFT);
        }

        break;
    }
    default:
        break;
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_PIT_TCTRLn_set_TEN.
* Description: Set Timer n enabled or disabled
*
END***************************************************************************/
void HAL_PIT_TCTRLn_set_TEN(uint8_t timer_index, uint8_t TEN_value)
{
    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*If timer 0 is enabled*/
        if (1 == TEN_value)
        {
            /*Write 1 to the TEN bit field*/
            PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;
        }
        /*If timer 0 is disabled*/
        else
        {
            /*Write 0 to the TEN bit field*/
            PIT_TCTRL0 &= ~(1u << PIT_TCTRL_TEN_SHIFT);
        }

        break;
    }
    case 1:
    {
        /*If timer 1 is enabled*/
        if (1 == TEN_value)
        {
            /*Write 1 to the TEN bit field*/
            PIT_TCTRL1 |= PIT_TCTRL_TEN_MASK;
        }
        /*If timer 1 is disabled*/
        else
        {
            /*Write 0 to the TEN bit field*/
            PIT_TCTRL1 &= ~(1u << PIT_TCTRL_TEN_SHIFT);
        }

        break;
    }
    default:
        break;
    }

    return;
}

/*!
 * @}
 */ /* end of group TCTRLn register bit setting functions */

  /* ----------------------------------------------------------------------------
   -- TFLGn register bit setting functions group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_PIT_TFLGn_read_TIF.
* Description: Read timer interrupt flag
*
END***************************************************************************/
uint8_t HAL_PIT_TFLGn_read_TIF(uint8_t timer_index)
{
    uint8_t ret_val = 0;    /*This variable stores the return value of the function*/

    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*Read the TIF value*/
        ret_val = PIT_TFLG0 & PIT_TFLG_TIF_MASK;
        break;
    }
    case 1:
    {
        /*Read the TIF value*/
        ret_val = PIT_TFLG1 & PIT_TFLG_TIF_MASK;
    }
    default:
        break;
    }

    return ret_val;
}

/*Functions*********************************************************************
*
* Function name: HAL_PIT_TFLGn_set_TIF.
* Description: Set value TIF to 1 to generate an interrupt or clear the interrupt
               flag.
*
END***************************************************************************/
void HAL_PIT_TFLGn_set_TIF(uint8_t timer_index)
{
    /*Check timer index*/
    switch (timer_index)
    {
    case 0:
    {
        /*Set 1 to TIF bit field*/
        PIT_TFLG0 = PIT_TFLG_TIF_MASK;
        break;
    }
    case 1:
    {
        /*Set 1 to TIF bit field*/
        PIT_TFLG1 = PIT_TFLG_TIF_MASK;
        break;
    }
    default:
        break;
    }

    return;
}

/*!
 * @}
 */ /* end of group TFLGn register bit setting functions */

/*Function*********************************************************************
*
* Function name: HAL_PIT_enable_IRQ_Handler.
* Description: Enable the PIT interrupt handler.
*
END***************************************************************************/
void HAL_PIT_enable_IRQ_Handler(void)
{
    /*Enable the PIT interrupt handler*/
    NVIC_EnableIRQ(PIT_IRQn);

    return;
}
/*EOF*/
