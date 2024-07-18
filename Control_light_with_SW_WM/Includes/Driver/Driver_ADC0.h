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

#ifndef _DRIVER_ADC0_H_
#define _DRIVER_ADC0_H_

/*******************************************************************************
 * Enum
 ******************************************************************************/

/**
 * @brief Reference of the analog input channel.
 */
typedef enum SC1_ADCH
{
    DADP0_DAD0 = 0u,       /*Singled-ended DADP0 channel, Differential DAD0 channel*/
    DADP1_DAD1 = 1u,       /*Singled-ended DADP1 channel, Differential DAD1 channel*/
    DADP2_DAD2 = 2u,       /*Singled-ended DADP2 channel, Differential DAD2 channel*/
    DADP3_DAD3 = 3u,       /*Singled-ended DADP3 channel, Differential DAD3 channel*/
    AD4 = 4u,              /*Singled-ended AD4 channel*/
    AD5 = 5u,              /*Singled-ended AD5 channel*/
    AD6 = 6u,              /*Singled-ended AD6 channel*/
    AD7 = 7u,              /*Singled-ended AD7 channel*/
    AD8 = 8u,              /*Singled-ended AD8 channel*/
    AD9 = 9u,              /*Singled-ended AD9 channel*/
    AD10 = 10u,            /*Singled-ended AD10 channel*/
    AD11 = 11u,            /*Singled-ended AD11 channel*/
    AD12 = 12u,            /*Singled-ended AD12 channel*/
    AD13 = 13u,            /*Singled-ended AD13 channel*/
    AD14 = 14u,            /*Singled-ended AD14 channel*/
    AD15 = 15u,            /*Singled-ended AD15 channel*/
    AD16 = 16u,            /*Singled-ended AD16 channel*/
    AD17 = 17u,            /*Singled-ended AD17 channel*/
    AD18 = 18u,            /*Singled-ended AD18 channel*/
    AD19 = 19u,            /*Singled-ended AD19 channel*/
    AD20 = 20u,            /*Singled-ended AD20 channel*/
    AD21 = 21u,            /*Singled-ended AD21 channel*/
    AD22 = 22u,            /*Singled-ended AD22 channel*/
    AD23 = 23u,            /*Singled-ended AD23 channel*/
    RESERVED1 = 24u,       /*This value is reserved*/
    RESERVED2 = 25u,       /*This value is reserved*/
    TEMP_SENSOR = 26u,     /*Temp sensor(single-ended/differential) channel*/
    BANDGAP = 27u,         /*Bandgap(single-ended/differential) channel*/
    RESERVED3 = 28u,       /*This value is reserved*/
    VREFSH = 29u,          /*If DIFF = 0, V_REFSH is selected. DIFF = 1, -V_REFSH is selected*/
    VREFSL = 30u,          /*If DIFF = 0, V_REFSL is selected. DIFF = 0, It is reserved*/
    MODULE_DISABLED = 31u, /*Module disabled*/
} SC1_channel_enum_t;

/**
 * @brief Reference of the differential mode enable.
 */
typedef enum SC1_DIFF_mod
{
    SINGLE_ENDED_INPUT = 0u, /*Single-ended conversion and input channels are selected*/
    DIFFERENTIAL_INPUT = 1u, /*Differential conversion and input channels are selected*/
} SC1_DIFF_enum_t;

/**
 * @brief Reference of the interrupt enable.
 */
typedef enum SC1_Interrupt_enable
{
    COCO_IRQ_DISABLED = 0u, /*Conversion complete interrupt is disabled*/
    COCO_IRQ_ENABLED = 1u,  /*Conversion complete interrupt is enabled*/
} SC1_AIEN_enum_t;

/**
 * @brief Reference of the input Clock source.
 */
typedef enum CFG1_ADICLK_type
{
    BUS_CLOCK = 0u,          /*Input clock is Bus Clock*/
    BUS_CLOCK_HALF = 1u,     /*Input clock is (Bus Clock / 2)*/
    ALTERNATE_CLOCK = 2u,    /*Input clock is Altenate Clock*/
    ASYNCHRONOUS_CLOCK = 3u, /*Input clock is Asynchronous Clock*/
} CFG1_ADICLK_enum_t;

/**
 * @brief Reference of the conversion MODE.
 */
typedef enum CFG1_MODE_type
{
    SINGLE_END_8BITS = 0u,    /*Single-ended 8 bits conversion*/
    DIFFERENTIAL_9BITS = 0u,  /*Differential 9 bits conversion with 2's complement output*/
    SINGLE_END_12BITS = 1u,   /*Single-ended 12 bits conversion*/
    DIFFERENTIAL_13BITS = 1u, /*Differential 13 bits conversion with 2's complement output*/
    SINGLE_END_10BITS = 2u,   /*Single-ended 10 bits conversion*/
    DIFFERENTIAL_11BITS = 2u, /*Differential 11 bits conversion with 2's complement output*/
    SINGLE_END_16BITS = 3u,   /*Single-ended 16 bits conversion*/
    DIFFERENTIAL_16BITS = 3u, /*Differential 16 bits conversion with 2's complement output*/
} CFG1_MODE_enum_t;

/**
 * @brief Reference of the Sample time configuration.
 */
typedef enum CFG1_ADLSMP_type
{
    SHORT_SAMPLE_TIME = 0u, /*Short sample time*/
    LONG_SAMPLE_TIME = 1u,  /*Long sample time*/
} CFG1_ADLSMP_enum_t;

/**
 * @brief Reference of the Clock Divide Ratio.
 */
typedef enum CFG1_ADIV_type
{
    DIV_1 = 0u, /*Divide ratio is 1*/
    DIV_2 = 1u, /*Divide ratio is 2*/
    DIV_4 = 2u, /*Divide ratio is 4*/
    DIV_8 = 3u, /*Divide ratio is 8*/
} CFG1_ADIV_enum_T;

/*******************************************************************************
 * Struct
 ******************************************************************************/

/**
 * @brief Contain the infomation of the SC1n configuration.
 */
typedef struct SC1n_config
{
    uint8_t SC1_channel;              /*Select SC1A or SC1B*/
    SC1_AIEN_enum_t IRQ_state;        /*Select the conversion complete interrupt state*/
    SC1_DIFF_enum_t DIFF_mode;        /*Select the diferrential or single-end mode*/
    SC1_channel_enum_t input_channel; /*Select input channel*/
} SC1_config_info;

/**
 * @brief Contain the infomation of the CFG1 configuration.
 */
typedef struct CFG1_config
{
    CFG1_ADICLK_enum_t clock_source;  /*Select input clock source*/
    CFG1_MODE_enum_t conversion_mode; /*Select conversion mode*/
    CFG1_ADLSMP_enum_t sample_time;   /*Select sample time mode*/
    CFG1_ADIV_enum_T clock_divide;    /*Select Clock Divide Ratio*/
} CFG1_config_info;

/**
 * @brief Contain the infomation of the ADC0 configuration.
 */
typedef struct ADC0_config
{
    SC1_config_info SC1_config;   /*SC1n configuration information*/
    CFG1_config_info CFG1_config; /*CFG1 configuration information*/
} ADC0_config_info;

/*******************************************************************************
 * Variable
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Init the ADC0
 *
 * @param ADC0_config is a struct pointer that has information of the ADC0 configuration
 *
 * @return: This function return nothing.
 */
void Driver_ADC0_init_ADC(ADC0_config_info *ADC0_config);

/**
 * @brief Configure the SC1n register
 *
 * @param SC1_config is a struct pointer that has information of the SC1n configuration
 *
 * @return: This function return nothing.
 */
void Driver_ADC0_config_SC1n(SC1_config_info *SC1_config);

/**
 * @brief Configure the CFG1 register
 *
 * @param CFG1_config is a struct pointer that has information of the CFG1 configuration
 *
 * @return: This function return nothing.
 */
void Driver_ADC0_config_CFG1(CFG1_config_info *CFG1_config);

/**
 * @brief Select input channel for ADC0
 *
 * @param SC1_channel is which SC1 register we will use to configure the ADC0 (SC1A/SC1B)
 * @param ADCH_channel is which input channel we will selected for ADC0
 *
 * @return: This function return nothing.
 */
void Driver_ADC0_input_channel(uint8_t SC1_channel, SC1_channel_enum_t ADCH_channel);

/**
 * @brief Read the digital data of the conversion in the corresponding Rn register.
 *
 * @param SC1_channel is which SC1 register we use to configure the ADC0 (SC1A -> RA / SC1B -> RB)
 *
 * @return the digital value of the conversion.
 */
uint16_t Driver_ADC0_read_Digital_value(uint8_t SC1_channel);

/**
 * @brief Read the conversion complete flag.
 *
 * @param SC1_channel is which SC1 register we use to configure the ADC0
 *
 * @return the state of the COCO flag
 */
uint8_t Driver_ADC0_read_conversion_flag(uint8_t SC1_channel);

/*******************************************************************************
 * End of header guard
 ******************************************************************************/
#endif
/*EOF*/
