/**
 * @file  : HAL_ADC0.h
 * @author: Nguyen The Anh.
 * @brief : Declare enum and function using in HAL_ADC0.c.
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include <stdint.h>

/*******************************************************************************
 * Header guard
 ******************************************************************************/

#ifndef _HAL_ADC0_H_
#define _HAL_ADC0_H_

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- SC1n register bit setting function group
   ---------------------------------------------------------------------------- */

/**
 * @brief Select if the enable interrupt or disable interrupt for the conversion.
 *
 * @param AIEN_state is the value of the AIEN bit field.
 * @param SC1_channel is which register we will use (SC1A/SC1B)
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_SC1n_set_AIEN(uint8_t AIEN_state, uint8_t SC1_channel);

/**
 * @brief Select single-ended input or differential input mode for the conversion.
 *
 * @param DIFF_state is the value of the DIFF bit field.
 * @param SC1_channel is which register we will use (SC1A/SC1B)
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_SC1n_set_DIFF(uint8_t DIFF_state, uint8_t SC1_channel);

/**
 * @brief Select input channel for the conversion.
 *
 * @param ADCH_value is the value of the ADCH bit field (5 bits width).
 * @param SC1_channel is which register we will use (SC1A/SC1B)
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_SC1n_set_ADCH(uint8_t ADCH_value, uint8_t SC1_channel);

/**
 * @brief Read the conversion complete flag bit field.
 *
 * @param SC1_channel is which register we will use (SC1A/SC1B)
 *
 * @return the state of the COCO(conversion complete) flag.
 */
uint8_t HAL_ADC0_SC1n_read_COCO_flag(uint8_t SC1_channel);

/*!
 * @}
 */ /* end of group SC1n register bit setting function */

/* ----------------------------------------------------------------------------
   -- CFG1 register bit setting functions group
   ---------------------------------------------------------------------------- */

/**
 * @brief Select clock source for the ADC0.
 *
 * @param ADICLK_value is the value of the ADICLK bit field(2 bits width).
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_CFG1_set_ADICLK(uint8_t ADICLK_value);

/**
 * @brief Select conversion mode for the ADC0.
 *
 * @param mode_value is the value of the MOD bit field(2 bits width).
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_CFG1_set_MODE(uint8_t mode_value);

/**
 * @brief Select sample time configuration for the ADC0.
 *
 * @param ADLSMP_value is the value of the ADLSMP bit field.
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_CFG1_set_ADLSMP(uint8_t ADLSMP_value);

/**
 * @brief Select clock divide ratio for the ADC0.
 *
 * @param ADIV_value is the value of the ADIV bit field(2 bits width).
 *
 * @return: this function return nothing.
 */
void HAL_ADC0_CFG1_set_ADIV(uint8_t ADIV_value);

/*!
 * @}
 */ /* end of group CFG1 register bit setting functions */

/* ----------------------------------------------------------------------------
   -- Rn register functions group
   ---------------------------------------------------------------------------- */

/**
 * @brief Get the digital data in the data register Rn.
 *
 * @param SC1_channel is which register we will use (SC1A/SC1B)
 *
 * @return the digital value of the conversion.
 */
uint16_t HAL_ADC0_Rn_read_digital_value(uint8_t SC1_channel);

/*!
 * @}
 */ /* end of group Rn register functions */

/*******************************************************************************
 * End of header guard
 ******************************************************************************/
#endif
/*EOF*/
