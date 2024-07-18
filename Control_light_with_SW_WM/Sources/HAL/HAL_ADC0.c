/**
 * @file  : HAL_ADC0.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file HAL_ADC0.c
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
   -- SC1n register bit setting function group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_SC1n_set_AIEN.
* Description: Select ADC0 interrupt enabled or disabled when conversion completes
*
END***************************************************************************/
void HAL_ADC0_SC1n_set_AIEN(uint8_t AIEN_state, uint8_t SC1_channel)
{
    /*Check the SC1 channel*/
    if (0 == SC1_channel || 1 == SC1_channel)
    {
        /*If enable the interrupt when conversion completes*/
        if (1 == AIEN_state)
        {
            /*Write 1 to the AIEN bit field in the SC1n register*/
            ADC0->SC1[SC1_channel] |= AIEN_state << ADC_SC1_AIEN_SHIFT;
        }
        /*If interrupt is disabled*/
        else if (0 == AIEN_state)
        {
            /*Write 0 to the AIEN bit field in the SC1n register*/
            ADC0->SC1[SC1_channel] &= ~(1u << ADC_SC1_AIEN_SHIFT);
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
* Function name: HAL_ADC0_SC1n_set_DIFF.
* Description: Select single-ended input or differential input mode.
*
END***************************************************************************/
void HAL_ADC0_SC1n_set_DIFF(uint8_t DIFF_state, uint8_t SC1_channel)
{
    /*Check the SC1 channel*/
    if (0 == SC1_channel || 1 == SC1_channel)
    {
        /*If Differential input is selected*/
        if (1 == DIFF_state)
        {
            /*Write 1 to the DIFF bit field in SC1n register*/
            ADC0->SC1[SC1_channel] |= DIFF_state << ADC_SC1_AIEN_SHIFT;
        }
        /*If single-ended input is selected*/
        else if (0 == DIFF_state)
        {
            /*Write 0 to the DIFF bit field in SC1n register*/
            ADC0->SC1[SC1_channel] &= ~(1u << ADC_SC1_AIEN_SHIFT);
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
* Function name: HAL_ADC0_SC1n_set_ADCH.
* Description: Select input channel.
*
END***************************************************************************/
void HAL_ADC0_SC1n_set_ADCH(uint8_t ADCH_value, uint8_t SC1_channel)
{
    /*Check SC1 channel*/
    if (0 == SC1_channel || 1 == SC1_channel)
    {
        /*If ADCH channel is 0*/
        if (0 == ADCH_value)
        {
            /*Write 0 to the ADCH bit field in SC1n register*/
            ADC0->SC1[SC1_channel] &= ~(1u << ADC_SC1_ADCH_SHIFT);
        }
        /*If the ADCH channel is in range from 0 to 0x1F*/
        else if (ADCH_value < 0x1F)
        {
            /*Clear the ADCH first*/
            ADC0->SC1[SC1_channel] &= ~(0x1F);
            /*Write the input channel to the ADCH bit field in SC1n register*/
            ADC0->SC1[SC1_channel] |= ADCH_value << ADC_SC1_ADCH_SHIFT;
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
* Function name: HAL_ADC0_SC1n_read_COCO_flag.
* Description: Get the state of conversion complete flag
*
END***************************************************************************/
uint8_t HAL_ADC0_SC1n_read_COCO_flag(uint8_t SC1_channel)
{
    uint8_t ret_val = 0;    /*This variable stores the return value of the function*/

    /*Check SC1 channel*/
    if ((0 == SC1_channel) || (1 == SC1_channel))
    {
        /*Get the conversion complete flag by reading the COCO bit*/
        ret_val = ADC0->SC1[SC1_channel] & ADC_SC1_COCO_MASK;
    }
    else
    {
        /*Do nothing*/
    }

    return ret_val;
}

/*!
 * @}
 */ /* end of group SC1n register bit setting function */

/* ----------------------------------------------------------------------------
   -- CFG1 register bit setting function group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_CFG1_set_ADICLK.
* Description: Select input clock source
*
END***************************************************************************/
void HAL_ADC0_CFG1_set_ADICLK(uint8_t ADICLK_value)
{
    /*If clock source is Bus Clock*/
    if (0 == ADICLK_value)
    {
        /*Write 0 to the ADICLK bit field in CFG1 register*/
        ADC0->CFG1 &= ~(1u << ADC_CFG1_ADICLK_SHIFT);
    }
    /*If clock source is (Bus Clock/2), Alternate Clock, Asynchronous clock*/
    else if (ADICLK_value < 4)
    {
        /*Write the ADICLK value to the CFG1 register*/
        ADC0->CFG1 |= ADICLK_value << ADC_CFG1_ADICLK_SHIFT;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_CFG1_set_MODE.
* Description: Select the conversion mode
*
END***************************************************************************/
void HAL_ADC0_CFG1_set_MODE(uint8_t mode_value)
{
    /*If conversion mode value is 0*/
    if (0 == mode_value)
    {
        /*Write 0 to MODE bit field in CFG1 register*/
        ADC0->CFG1 &= ~(1u << ADC_CFG1_MODE_SHIFT);
    }
    /*If conversion mode is 1, 2, or 3*/
    else if (mode_value < 4)
    {
        /*Write MODE value to MODE bit field in CFG1 register*/
        ADC0->CFG1 |= mode_value << ADC_CFG1_MODE_SHIFT;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_CFG1_set_ADLSMP.
* Description: Select sample time configuration
*
END***************************************************************************/
void HAL_ADC0_CFG1_set_ADLSMP(uint8_t ADLSMP_value)
{
    /*If the sample time configuration is short sample time*/
    if (0 == ADLSMP_value)
    {
        /*Write 0 to the ADLSMP bit field in CFG1 register*/
        ADC0->CFG1 &= ~(1u << ADC_CFG1_ADLSMP_SHIFT);
    }
    /*If the sample time configuration is long sample time*/
    else if (1 == ADLSMP_value)
    {
        /*Write 1 to the ADLSMP bit field in CFG1 register*/
        ADC0->CFG1 |= ADLSMP_value << ADC_CFG1_ADLSMP_SHIFT;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_CFG1_set_ADIV.
* Description: Select clock divide
*
END***************************************************************************/
void HAL_ADC0_CFG1_set_ADIV(uint8_t ADIV_value)
{
    /*If divide ratio 1 is selected*/
    if (0 == ADIV_value)
    {
        /*Write 0 to the ADIV bit field in CFG1 register*/
        ADC0->CFG1 &= ~(1u << ADC_CFG1_ADIV_SHIFT);
    }
    /*If divide ratio is 2, 4 or 8 is selected*/
    else if (ADIV_value < 4)
    {
        /*Write ADIV value to ADIV bit field in CFG1 register*/
        ADC0->CFG1 |= ADIV_value << ADC_CFG1_ADIV_SHIFT;
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*!
 * @}
 */ /* end of group CFG1 register bit setting functions */

/* ----------------------------------------------------------------------------
   -- Rn register functions group
   ---------------------------------------------------------------------------- */

/*Functions*********************************************************************
*
* Function name: HAL_ADC0_Rn_read_digital_value.
* Description: Get the digital value of the conversion
*
END***************************************************************************/
uint16_t HAL_ADC0_Rn_read_digital_value(uint8_t SC1_channel)
{
    uint16_t ret_val = 0;   /*This variable stores the return value of function*/

    /*If SC1 channel is SC1A*/
    if (0 == SC1_channel)
    {
        /*Get data in the data register RA*/
        ret_val = ADC0->R[SC1_channel];
    }
    /*If SC1 channel is SC1B*/
    else if (1 == SC1_channel)
    {
        /*Get data in the data register RB*/
        ret_val = ADC0->R[SC1_channel];
    }
    else
    {
        /*Do nothing*/
    }

    return ret_val;
}

/*!
 * @}
 */ /* end of group Rn register function */

/*EOF*/
