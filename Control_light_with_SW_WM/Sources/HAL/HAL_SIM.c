/**
 * @file  : HAL_SIM.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file HAL_SIM.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "../Includes/HAL/HAL_SIM.h"

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- SCGC5 register bit setting function group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC5_set_clock_PORTA
* Description: Enable clock for a PORTA.
*
END***************************************************************************/
void HAL_SIM_SCGC5_set_clock_PORTA(uint8_t portA_gate_value)
{
    /*If PORTA clock gate is enabled*/
    if (1 == portA_gate_value)
    {
        /*Write 1 to the bit field PORTA to enable clock source*/
        SIM->SCGC5 |= portA_gate_value << SIM_SCGC5_PORTA_SHIFT;
    }
    /*If PORTA clock gate is disabled*/
    else if (0 == portA_gate_value)
    {
        /*Write 0 to the bit field PORTA to disable clock source*/
        SIM->SCGC5 &= ~(1u << portA_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC5_set_clock_PORTB
* Description: Enable clock for a PORTB.
*
END***************************************************************************/
void HAL_SIM_SCGC5_set_clock_PORTB(uint8_t portB_gate_value)
{
    /*If PORTB clock gate is enabled*/
    if (1 == portB_gate_value)
    {
        /*Write 1 to the bit field PORTB to enable clock source*/
        SIM->SCGC5 |= portB_gate_value << SIM_SCGC5_PORTB_SHIFT;
    }
    /*If PORTB clock gate is disabled*/
    else if (0 == portB_gate_value)
    {
        /*Write 0 to the bit field PORTB to disable clock source*/
        SIM->SCGC5 &= ~(1u << portB_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC5_set_clock_PORTC
* Description: Enable clock for a PORTC.
*
END***************************************************************************/
void HAL_SIM_SCGC5_set_clock_PORTC(uint8_t portC_gate_value)
{
    /*If PORTC clock gate is enabled*/
    if (1 == portC_gate_value)
    {
        /*Write 1 to the bit field PORTC to enable clock source*/
        SIM->SCGC5 |= portC_gate_value << SIM_SCGC5_PORTC_SHIFT;
    }
    /*If PORTC clock gate is disabled*/
    else if (0 == portC_gate_value)
    {
        /*Write 0 to the bit field PORTC to disable clock source*/
        SIM->SCGC5 &= ~(1u << portC_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC5_set_clock_PORTD
* Description: Enable clock for a PORTD.
*
END***************************************************************************/
void HAL_SIM_SCGC5_set_clock_PORTD(uint8_t portD_gate_value)
{
    /*If PORTD clock gate is enabled*/
    if (1 == portD_gate_value)
    {
        /*Write 1 to the bit field PORTD to enable clock source*/
        SIM->SCGC5 |= portD_gate_value << SIM_SCGC5_PORTD_SHIFT;
    }
    /*If PORTD clock gate is disabled*/
    else if (0 == portD_gate_value)
    {
        /*Write 0 to the bit field PORTD to disable clock source*/
        SIM->SCGC5 &= ~(1u << portD_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC5_set_clock_PORTE
* Description: Enable clock for a PORTE.
*
END***************************************************************************/
void HAL_SIM_SCGC5_set_clock_PORTE(uint8_t portE_gate_value)
{
    /*If PORTE clock gate is enabled*/
    if (1 == portE_gate_value)
    {
        /*Write 1 to the bit field PORTE to enable clock source*/
        SIM->SCGC5 |= portE_gate_value << SIM_SCGC5_PORTE_SHIFT;
    }
    /*If PORTE clock gate is disabled*/
    else if (0 == portE_gate_value)
    {
        /*Write 0 to the bit field PORTE to disable clock source*/
        SIM->SCGC5 &= ~(1u << portE_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*!
 * @}
 */ /* end of group SCGC5 register bit setting function */

/* ----------------------------------------------------------------------------
   -- SCGC6 register bit setting function group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC6_set_clock_ADC0
* Description: Enable clock for a ADC0.
*
END***************************************************************************/
void HAL_SIM_SCGC6_set_clock_ADC0(uint8_t ADC0_gate_value)
{
    /*If ADC0 clock gate is enabled*/
    if (1 == ADC0_gate_value)
    {
        /*Write 1 to the bit field ADC0 to enable clock source*/
        SIM->SCGC6 |= ADC0_gate_value << SIM_SCGC6_ADC0_SHIFT;
    }
    /*If ADC0 clock gate is disabled*/
    else if (0 == ADC0_gate_value)
    {
        /*Write 0 to the bit field ADC0 to disable clock source*/
        SIM->SCGC6 &= ~(1u << ADC0_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_SIM_SCGC6_set_clock_PIT
* Description: Set clock for a PIT.
*
END***************************************************************************/
void HAL_SIM_SCGC6_set_clock_PIT(uint8_t PIT_gate_value)
{
    /*If PIT clock gate is enabled*/
    if (1 == PIT_gate_value)
    {
        /*Write 1 to the PIT bit field*/
        SIM->SCGC6 |= PIT_gate_value << SIM_SCGC6_PIT_SHIFT;
    }
    /*If PIT clock gate is disabled*/
    else if (0 == PIT_gate_value)
    {
        /*Write 0 to the PIT bit field*/
        SIM->SCGC6 &= ~(1u << PIT_gate_value);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*!
 * @}
 */ /* end of group SCGC6 register bit setting function */

/*EOF*/
