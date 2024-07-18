/**
 * @file  : Driver_SIM.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file Driver_SIM.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "../Includes/Driver/Driver_SIM.h"
#include "../Includes/HAL/HAL_SIM.h"
#include <stdlib.h>

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*Functions*********************************************************************
*
* Function name: Driver_SIM_enable_clock_PORT
* Description: Enable clock source for a PORT.
*
END***************************************************************************/
void Driver_SIM_SCGC5_init_clock(SCGC5_config_info *SCGC5_clock_config)
{
    if(NULL != SCGC5_clock_config)
    {
        HAL_SIM_SCGC5_set_clock_PORTA((uint8_t)SCGC5_clock_config->PORTA_clock);
        HAL_SIM_SCGC5_set_clock_PORTB((uint8_t)SCGC5_clock_config->PORTB_clock);
        HAL_SIM_SCGC5_set_clock_PORTC((uint8_t)SCGC5_clock_config->PORTC_clock);
        HAL_SIM_SCGC5_set_clock_PORTD((uint8_t)SCGC5_clock_config->PORTD_clock);
        HAL_SIM_SCGC5_set_clock_PORTE((uint8_t)SCGC5_clock_config->PORTE_clock);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}

void Driver_SIM_SCGC6_init_clock(SCGC6_config_info *SCGC6_clock_config)
{
    if(NULL != SCGC6_clock_config)
    {
        HAL_SIM_SCGC6_set_clock_ADC0((uint8_t)SCGC6_clock_config->ADC0_clock);
        HAL_SIM_SCGC6_set_clock_PIT((uint8_t)SCGC6_clock_config->PIT_clock);
    }
    else
    {
        /*Do nothing*/
    }

    return;
}
/*EOF*/
