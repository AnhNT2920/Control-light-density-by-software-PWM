/**
 * @file  : Driver_SIM.h
 * @author: Nguyen The Anh.
 * @brief : Declare enum, typdef, macro and function using in Driver_SIM.h.
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include <stdint.h>
#include "../Includes/Driver/Driver_common.h"

/*******************************************************************************
 * Header guard
 ******************************************************************************/

#ifndef _DRIVER_SIM_H_
#define _DRIVER_SIM_H_

/*******************************************************************************
 * Enum
 ******************************************************************************/

/**
 * @brief Reference the state of the clock gate.
 */
typedef enum clock_gate_state
{
    DISABLED = 0u,  /*Clock gate is disabled*/
    ENABLED = 1u,   /*Clock gate is enabled*/
} clock_gate_state_enum_t;

/*******************************************************************************
 * Struct
 ******************************************************************************/

/**
 * @brief Contain the infomation of the SCGC5 configuration.
 */
typedef struct SCGC5_config
{
    clock_gate_state_enum_t PORTA_clock;    /*PORTA clock gate status*/
    clock_gate_state_enum_t PORTB_clock;    /*PORTB clock gate status*/
    clock_gate_state_enum_t PORTC_clock;    /*PORTC clock gate status*/
    clock_gate_state_enum_t PORTD_clock;    /*PORTD clock gate status*/
    clock_gate_state_enum_t PORTE_clock;    /*PORTE clock gate status*/
} SCGC5_config_info;

/**
 * @brief Contain the infomation of the SCGC6 configuration.
 */
typedef struct SCGC6_config
{
    clock_gate_state_enum_t ADC0_clock;     /*ADC0 clock gate status*/
    clock_gate_state_enum_t PIT_clock;      /*PIT clock gate status*/
} SCGC6_config_info;

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Init the SCGC5 register to control clock gate in SCGC5.
 *
 * @param SCGC5_clock_config has the configuration information of the SCGC5.
 *
 * @return: This function return nothing.
 */
void Driver_SIM_SCGC5_init_clock(SCGC5_config_info *SCGC5_clock_config);

/**
 * @brief Init the SCGC6 register to control clock gate in SCGC6.
 *
 * @param SCGC6_clock_config has the configuration information of the SCGC6.
 *
 * @return: This function return nothing.
 */
void Driver_SIM_SCGC6_init_clock(SCGC6_config_info *SCGC6_clock_config);

/*******************************************************************************
 * End of header guard
 ******************************************************************************/
#endif
/*EOF*/
