/**
 * @file  : Driver_GPIO.h
 * @author: Nguyen The Anh.
 * @brief : Declare enum, typdef, macro and function using in Driver_GPIO.c.
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

#ifndef _DRIVER_PIT_H_
#define _DRIVER_PIT_H_

/*******************************************************************************
 * Typedef
 ******************************************************************************/

/**
 * @brief function callback pointer.
 */
typedef void (*callback)(void);

/*******************************************************************************
 * Enum
 ******************************************************************************/

/**
 * @brief Reference of freeze mode.
 */
typedef enum MCR_FRZ_type
{
    TIMERS_CONTINUE_IN_DEBUG = 0u,  /*Timer continue to run in debug mode*/
    TIMERS_STOPPED_IN_DEBUG = 1u,   /*Timer stop in debug mode*/
} MCR_FRZ_type_enum_t;

/**
 * @brief Reference of module state.
 */
typedef enum MCR_MDIS_type
{
    PIT_ENABLED = 0u,   /*PIT module enabled*/
    PIT_DISABLED = 1u,  /*PIT module disabled*/
} MCR_MDIS_type_enum_t;

/**
 * @brief Reference of chain mode state.
 */
typedef enum TCTRL_CHN_type
{
    CHAIN_MODE_DISABLED = 0u,   /*Chain mode disabled*/
    CHAIN_MODE_ENABLED = 1u,    /*Chain mode enabled*/
} TCTRL_CHN_type_enum_t;

/**
 * @brief Reference of interrupt request state.
 */
typedef enum TCTRL_TIE_type
{
    IRQ_DISABLED = 0u,  /*PIT timer interrupt request disabled*/
    IRQ_ENABLED = 1u,   /*PIT timer interrupt request enabled*/
} TCTRL_TIE_type_enum_t;

/**
 * @brief Reference of PIT timer state.
 */
typedef enum TCTRL_TEN_type
{
    TIMER_DISABLED = 0u,    /*Timer disabled*/
    TIMER_ENABLED = 1u,     /*Timer enabled*/
} TCTRL_TEN_type_enum_t;

/*******************************************************************************
 * Struct
 ******************************************************************************/

/**
 * @brief Information about the MCR register configuration
 */
typedef struct MCR_config
{
    MCR_FRZ_type_enum_t freeze_mode;    /*Freeze mode configuration*/
    MCR_MDIS_type_enum_t module_state;  /*Module state configuration*/
} MCR_config_info;

/**
 * @brief Information about the TCTRLn register configuration
 */
typedef struct TCTRL_config
{
    uint8_t timer_index;                /*Index of the timer(0 / 1)*/
    TCTRL_TEN_type_enum_t timer_state;  /*Timer state configuration*/
    TCTRL_TIE_type_enum_t IRQ_state;    /*Timer interrupt request state*/
    TCTRL_CHN_type_enum_t chain_mode;   /*Timer chain mode state*/
} TCTRL_config_info;

/**
 * @brief Information about the PIT configuration
 */
typedef struct PIT_config
{
    MCR_config_info MCR_config;         /*MCR register configuration information*/
    TCTRL_config_info TCTRLn_config;    /*TCTRLn register configuration information*/
    uint32_t load_value;                /*Load value for PIT timer n*/
} PIT_config_info;

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Register a callback function
 *
 * @param callback_func is the address of the function to callback
 *
 * @return: This function return nothing.
 */
void Driver_PIT_register_callabck(callback callback_func);

/**
 * @brief Init the PIT
 *
 * @param PIT_config is a struct pointer has the information about the PIT configuration
 *
 * @return: This function return nothing.
 */
void Driver_PIT_init(PIT_config_info *PIT_config);

/**
 * @brief Configure the MCR register
 *
 * @param MCR_config is a struct pointer has the information about the MCR configuration
 *
 * @return: This function return nothing.
 */
void Driver_PIT_config_MCR(MCR_config_info *MCR_config);

/**
 * @brief Select freeze mode for PIT timers
 *
 * @param freeze_mode is the freeze mode option for PIT timers (run or stop in debug mode)
 *
 * @return: This function return nothing.
 */
void Driver_PIT_select_freeze_mode(MCR_FRZ_type_enum_t freeze_mode);

/**
 * @brief Select PIT module state.
 *
 * @param module_state is the state of the PIT (Enabled/Disabled)
 *
 * @return: This function return nothing.
 */
void Driver_PIT_select_module_state(MCR_MDIS_type_enum_t module_state);

/**
 * @brief Set load value for timer n
 *
 * @param timer_index is the index of the timer (0/1)
 * @param load_value is the value to load to the timer n.
 *
 * @return: This function return nothing.
 */
void Driver_PIT_set_load_value(uint8_t timer_index, uint32_t load_value);

/**
 * @brief Configure the TCTRLn register
 *
 * @param TCTRLn_config is a struct pointer has the information about the TCTRLn configuration
 *
 * @return: This function return nothing.
 */
void Driver_PIT_config_TCTRLn(TCTRL_config_info *TCTRLn_config);

/**
 * @brief Set timer n state to disabled or enabled
 *
 * @param timer_index is the index of the timer (0/1)
 * @param timer_state is the state of timer n (enabled/disabled).
 *
 * @return: This function return nothing.
 */
void Driver_PIT_select_Timer_state(uint8_t timer_index, TCTRL_TEN_type_enum_t timer_state);

/**
 * @brief Set timer n interrupt request state to disabled or enabled
 *
 * @param timer_index is the index of the timer (0/1)
 * @param IRQ_state is the interrupt request state of timer n (enabled/disabled).
 *
 * @return: This function return nothing.
 */
void Driver_PIT_select_IRQ_state(uint8_t timer_index, TCTRL_TIE_type_enum_t IRQ_state);

/**
 * @brief Set timer n to be chained or not chained
 *
 * @param timer_index is the index of the timer (0/1)
 * @param chain_mode is the chain mode of timer n (chained /not chained).
 *
 * @return: This function return nothing.
 */
void Driver_PIT_select_Chain_Mode(uint8_t timer_index, TCTRL_CHN_type_enum_t chain_mode);

/**
 * @brief Set timer n interrupt flag to generate interrupt or clear interrupt flag
 *
 * @param timer_index is the index of the timer (0/1)
 *
 * @return: This function return nothing.
 */
void Driver_PIT_set_IRQ_flag(uint8_t timer_index);

/*******************************************************************************
 * End of header guard
 ******************************************************************************/
#endif
/*EOF*/
