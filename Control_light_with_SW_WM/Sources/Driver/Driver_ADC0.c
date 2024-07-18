/**
 * @file  : Driver_ADC0.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file Driver_ADC0.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "../Includes/HAL/HAL_ADC0.h"
#include "../Includes/Driver/Driver_ADC0.h"
#include <stdlib.h>

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*Functions*********************************************************************
*
* Function name: Driver_ADC0_init_ADC
* Description: Initiate the ADC0.
*
END***************************************************************************/
void Driver_ADC0_init_ADC(ADC0_config_info *ADC0_config)
{
    /*Check input*/
    if (NULL != ADC0_config)
    {
        /*Configure the CFG1 as the configuration information in ADC0_config*/
        Driver_ADC0_config_CFG1(&(ADC0_config->CFG1_config));
        /*Configure the SC1n as the configuration information in ADC0_config*/
        Driver_ADC0_config_SC1n(&(ADC0_config->SC1_config));
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_ADC0_config_SC1n
* Description: Configure the SC1n register
*
END***************************************************************************/
void Driver_ADC0_config_SC1n(SC1_config_info *SC1_config)
{
    /*Check input*/
    if (NULL != SC1_config)
    {
        /*Select conversion complete interrupt for the ADC0*/
        HAL_ADC0_SC1n_set_AIEN((uint8_t)SC1_config->IRQ_state, SC1_config->SC1_channel);
        /*Select the differential mode or single-ended mode for the ADC0*/
        HAL_ADC0_SC1n_set_DIFF((uint8_t)SC1_config->DIFF_mode, SC1_config->SC1_channel);

        /*If the Differential mode is selected*/
        if (DIFFERENTIAL_INPUT == SC1_config->DIFF_mode)
        {
            /*If the input channel is a reserverd value*/
            if (SC1_config->input_channel > DADP3_DAD3)
            {
                /*Disable the input channel module*/
                HAL_ADC0_SC1n_set_ADCH((uint8_t)MODULE_DISABLED, SC1_config->SC1_channel);
            }
            /*If the input channel is a valid channel for differential channel*/
            else if (SC1_config->input_channel <= DADP3_DAD3 || SC1_config->input_channel == TEMP_SENSOR || SC1_config->input_channel == BANDGAP || SC1_config->input_channel == VREFSH)
            {
                /*Select input channel for the ADC0*/
                HAL_ADC0_SC1n_set_ADCH(SC1_config->input_channel, SC1_config->SC1_channel);
            }
        }
        /*If the Single-ended mode is selected*/
        else if (SINGLE_ENDED_INPUT == SC1_config->DIFF_mode)
        {
            /*If the input channel is a reserved value*/
            if ((RESERVED1 == SC1_config->input_channel) || (RESERVED2 == SC1_config->input_channel) || (RESERVED3 == SC1_config->input_channel))
            {
                /*Disable the input module*/
                HAL_ADC0_SC1n_set_ADCH((uint8_t)MODULE_DISABLED, SC1_config->SC1_channel);
            }
            /*If the input channel is a valid channel for single-ended channel*/
            else if (SC1_config->input_channel <= MODULE_DISABLED)
            {
                /*Select input channel for the ADC0*/
                HAL_ADC0_SC1n_set_ADCH((uint8_t)SC1_config->input_channel, SC1_config->SC1_channel);
            }
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
* Function name: Driver_ADC0_config_CFG1
* Description: Configure the CFG1 register
*
END***************************************************************************/
void Driver_ADC0_config_CFG1(CFG1_config_info *CFG1_config)
{
    /*Check input*/
    if (NULL != CFG1_config)
    {
        /*Select input Clock source for ADC0*/
        HAL_ADC0_CFG1_set_ADICLK((uint8_t)CFG1_config->clock_source);
        /*Select Clock Divide ratio*/
        HAL_ADC0_CFG1_set_ADIV((uint8_t)CFG1_config->clock_divide);
        /*Select conversion mode*/
        HAL_ADC0_CFG1_set_MODE((uint8_t)CFG1_config->conversion_mode);
        /*Select sample time mode*/
        HAL_ADC0_CFG1_set_ADLSMP((uint8_t)CFG1_config->sample_time);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_ADC0_input_channel
* Description: Enable the input channel for ADC0.
*
END***************************************************************************/
void Driver_ADC0_input_channel(uint8_t SC1_channel, SC1_channel_enum_t ADCH_channel)
{
    /*Check input*/
    if (SC1_channel < 2 && ((DADP0_DAD0 <= ADCH_channel) && (ADCH_channel <= MODULE_DISABLED)))
    {
        /*Set input channel for ADC0*/
        HAL_ADC0_SC1n_set_ADCH((uint8_t)ADCH_channel, SC1_channel);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Driver_ADC0_read_Digital_value
* Description: Get digital value of the conversion
*
END***************************************************************************/
uint16_t Driver_ADC0_read_Digital_value(uint8_t SC1_channel)
{
    /*Any invalid value of SC1_channel will result this function to return a value 0*/
    return HAL_ADC0_Rn_read_digital_value(SC1_channel);
}

/*Functions*********************************************************************
*
* Function name: Driver_ADC0_read_conversion_flag
* Description: Get the conversion complete flag state
*
END***************************************************************************/
uint8_t Driver_ADC0_read_conversion_flag(uint8_t SC1_channel)
{
    /*Any invalid value of SC1_channel will result this function to return a value 0*/
    return HAL_ADC0_SC1n_read_COCO_flag(SC1_channel);
}

/*EOF*/
