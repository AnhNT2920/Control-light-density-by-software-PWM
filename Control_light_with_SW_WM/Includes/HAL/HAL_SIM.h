/**
 * @file  : HAL_SIM.h
 * @author: Nguyen The Anh.
 * @brief : Declare enum and function using in HAL_SIM.c.
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
 * Header guard
 ******************************************************************************/

#ifndef _HAL_SIM_H_
#define _HAL_SIM_H_

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- SCGC5 register bit setting function group
   ---------------------------------------------------------------------------- */

/**
 * @brief Enable clock source for PORTA
 *
 * @param portA_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC5_set_clock_PORTA(uint8_t portA_gate_value);

/**
 * @brief Enable clock source for PORTB
 *
 * @param portB_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC5_set_clock_PORTB(uint8_t portB_gate_value);

/**
 * @brief Enable clock source for PORTC
 *
 * @param portC_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC5_set_clock_PORTC(uint8_t portC_gate_value);

/**
 * @brief Enable clock source for PORTD
 *
 * @param portD_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC5_set_clock_PORTD(uint8_t portD_gate_value);

/**
 * @brief Enable clock source for PORTE
 *
 * @param portE_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC5_set_clock_PORTE(uint8_t portE_gate_value);

/*!
 * @}
 */ /* end of group SCGC5 register bit setting function */

/* ----------------------------------------------------------------------------
   -- SCGC6 register bit setting function group
   ---------------------------------------------------------------------------- */

/**
 * @brief Enable clock source for ADC0
 *
 * @param ADC0_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC6_set_clock_ADC0(uint8_t ADC0_gate_value);

/**
 * @brief Enable clock source for PIT
 *
 * @param PIT_gate_value is the value we will write to bit PORTA in SCGC5 register.
 *
 * @return: this function return nothing.
 */
void HAL_SIM_SCGC6_set_clock_PIT(uint8_t PIT_gate_value);

/*!
 * @}
 */ /* end of group SCGC6 register bit setting function */

/*Header guard*/
#endif
/*EOF*/