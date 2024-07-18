/**
 * @file  : HAL_PIT.h
 * @author: Nguyen The Anh.
 * @brief : Declare enum and function using in HAL_PIT.c.
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

#ifndef _HAL_PIT_H_
#define _HAL_PIT_H_

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- MCR register bit setting function group
   ---------------------------------------------------------------------------- */

/**
 * @brief Set the PIT module state is enabled or disabled.
 *
 * @param MDIS_value is the value of the MDIS bit field(0 = enabled/ 1 = disabled).
 *
 * @return: this function return nothing.
 */
void HAL_PIT_MCR_set_MDIS(uint8_t MDIS_value);

/**
 * @brief Set the timer continue to run or stop in debug mode.
 *
 * @param FRZ_value is the logic to set the FRZ bit field(0 = run/ 1 = stop).
 *
 * @return: this function return nothing.
 */
void HAL_PIT_MCR_set_FRZ(uint8_t FRZ_value);

/*!
 * @}
 */
/* end of group MCR register bit setting functions */

/* ----------------------------------------------------------------------------
   -- LDVALn register bit setting functions group
   ---------------------------------------------------------------------------- */

/**
 * @brief Set load value for PIT timer n.
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 * @param TSV_value is the load value to set for PIT timer n.
 *
 * @return: this function return nothing.
 */
void HAL_PIT_LDVALn_set_TSV(uint8_t timer_index, uint32_t TSV_value);

/*!
 * @}
 */
/* end of group LDVALn register bit setting functions */

/* ----------------------------------------------------------------------------
  -- TCTRLn register bit setting functions group
  ---------------------------------------------------------------------------- */

/**
 * @brief Set the timer continue to run or stop in debug mode.
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 * @param CHN_value is the logic to set the CHN bit field(0 = Not chained/ 1 = Chained).
 *
 * @return: this function return nothing.
 */
void HAL_PIT_TCTRLn_set_CHN(uint8_t timer_index, uint8_t CHN_value);

/**
 * @brief Set timer n interrupt request enabled or disabled
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 * @param TIE_value is the logic to set the TIE bit field(0 = Disabled/ 1 = Enabled).
 *
 * @return: this function return nothing.
 */
void HAL_PIT_TCTRLn_set_TIE(uint8_t timer_index, uint8_t TIE_value);

/**
 * @brief Set timer n enabled or disabled
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 * @param TEN_value is the logic to set the TEN bit field(0 = Disabled/ 1 = Enabled).
 *
 * @return: this function return nothing.
 */
void HAL_PIT_TCTRLn_set_TEN(uint8_t timer_index, uint8_t TEN_value);

/*!
 * @}
 */
/* end of group TCTRLn register bit setting functions */

/* ----------------------------------------------------------------------------
  -- TFLGn register bit setting functions group
  ---------------------------------------------------------------------------- */

/**
 * @brief Read the interrupt flag of the timer n
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 *
 * @return the state of the interrupt flag
 */
uint8_t HAL_PIT_TFLGn_read_TIF(uint8_t timer_index);

/**
 * @brief Set the interrupt flag of the timer n to generate interrupt or clear flag
 *
 * @param timer_index is the index of PIT timer (0 or 1)
 *
 * @return: This function return nothing
 */
void HAL_PIT_TFLGn_set_TIF(uint8_t timer_index);

/*!
 * @}
 */
/* end of group TFLGn register bit setting functions */

/**
 * @brief Enable the PIT interrupt handler
 *
 * @param: This function has no parameter
 *
 * @return: This function return nothing
 */
void HAL_PIT_enable_IRQ_Handler(void);

/*******************************************************************************
 * End of header guard
 ******************************************************************************/
#endif
/*EOF*/
