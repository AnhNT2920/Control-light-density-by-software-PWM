/**
 * @file  : main.c
 * @author: Nguyen The Anh.
 * @brief : Definition of function using in file main.c
 * @version: 0.0
 *
 * @copyright Copyright (c) 2024.
 *
 */

/*******************************************************************************
 * Include
 ******************************************************************************/

#include "../Includes/Driver/Driver_SIM.h"
#include "../Includes/Driver/Driver_GPIO.h"
#include "../Includes/Driver/Driver_ADC0.h"
#include "../Includes/Driver/Driver_PIT.h"

/*******************************************************************************
 * Macro
 ******************************************************************************/

#define PWM_FREQUENCY_1kHZ (1000u)              /*PWM frequency at 1 kHz*/
#define TICKS_PER_PWM_CYCLE (100u)              /*PWM will finish 1 cycle per 100 PIT interrupt*/
#define DEFAULT_BUS_CLOCK_FREQUENCY (20971520u) /*Default bus clock frequency*/
#define PIT_TICKS_100kHz (203u)                 /*PIT count value to get frequency at 100 kHz*/

/*******************************************************************************
 * Variable
 ******************************************************************************/

static volatile uint32_t ticks = 0; /*ticks is the number of PIT interrupt has occured*/
static uint8_t signal_state = 0;    /*sinal_state is the logic level of the PWM pulse*/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Create a PWM based on the PIT ticks interrupt
 *
 * @param duty_cycle is the time which the PWM pulse is on high logic level
 *
 * @return: this function return nothing.
 */
void software_PWM(uint32_t duty_cycle);

/**
 * @brief Update ticks value after each PIT interrupt event
 *
 * @param: This function has no parameter.
 *
 * @return: this function return nothing.
 */
void Update_ticks_PIT_IRQ(void);

/**
 * @brief Convert the light intensity to digital value
 *
 * @param ADC0_config is a struct pointer that has the information about the ADC0 configuration
 *
 * @return the digital value of the light intensity
 */
uint32_t get_light_value(ADC0_config_info *ADC0_config);

/**
 * @brief Get duty cycle based on the light intensity
 *
 * @param light_value is the digital value of the light intensity
 *
 * @return the duty cycle
 */
uint8_t get_duty_cycle(uint32_t light_value);

/**
 * @brief Control the LED corresponding to the PWM pulse
 *
 * @param green_LED is a struct pointer that has information about green LED configuration
 *
 * @return: this function return nothing.
 */
void control_green_LED(GPIO_config_info_t *green_LED);

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*Functions*********************************************************************
*
* Function name: software_PWM
* Description: Create a PWM based on the PIT ticks interrupt
*
END***************************************************************************/
void software_PWM(uint32_t duty_cycle)
{
    /*If the ticks is smaller than or equal to duty cycle*/
    if (ticks <= duty_cycle)
    {
        /*Set PWM pulse at high logic level*/
        signal_state = 1;
    }
    /*If the ticks is greater than duty cycle*/
    else
    {
        /*Set PWM pulse at low logic level*/
        signal_state = 0;
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: Update_ticks_PIT_IRQ
* Description: Update the ticks after each interrupt event.
*
END***************************************************************************/
void Update_ticks_PIT_IRQ(void)
{
    /*If the ticks is greater than or equal to the PWM ticks limit per cycle*/
    if (ticks >= TICKS_PER_PWM_CYCLE)
    {
        /*Reset ticks value*/
        ticks = 0;
    }
    else
    {
        /*Increase ticks by 1*/
        ticks++;
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: get_light_value
* Description: Convert light to digital value
*
END***************************************************************************/
uint32_t get_light_value(ADC0_config_info *ADC0_config)
{
    uint32_t ret_val = 0;   /*This variable stores the return value of the function*/

    /*Get analog input*/
    Driver_ADC0_input_channel(ADC0_config->SC1_config.SC1_channel, ADC0_config->SC1_config.input_channel);
    /*Wait for the conversion to complete*/
    while (!(Driver_ADC0_read_conversion_flag(ADC0_config->SC1_config.SC1_channel)))
    {
    }
    /*Get the digital value*/
    ret_val = Driver_ADC0_read_Digital_value(ADC0_config->SC1_config.SC1_channel);

    return ret_val;
}

/*Functions*********************************************************************
*
* Function name: get_duty_cycle
* Description: Get duty cycle based on the light digital value
*
END***************************************************************************/
uint8_t get_duty_cycle(uint32_t light_value)
{
    uint8_t ret_value = 0;  /*This variable stores the return value of the function*/

    /*If the light intensity is too high*/
    if (light_value <= 0xC8u)
    {
        /*Set duty cycle to 0*/
        ret_value = 0;
    }
    /*If the light intensity is in middle range*/
    else if (light_value <= 0xF0)
    {
        /*Get the duty cycle*/
        ret_value = ((light_value - 0xC0u) * 100)/(0xF0 - 0xC0u);
    }
    /*If the light intensity is too low*/
    else
    {
        /*Set duty cycle to be the total ticks per cycle*/
        ret_value = 100;
    }

    return ret_value;
}

/*Functions*********************************************************************
*
* Function name: control_green_LED
* Description: Turn on or turn off the LED based on the PWM
*
END***************************************************************************/
void control_green_LED(GPIO_config_info_t *green_LED)
{
    /*If the PWM is on duty cycle*/
    if (1 == signal_state)
    {
        /*Turn on green LED*/
        Driver_GPIO_set_pin_State(green_LED->port_type, green_LED->pin, LOW_STATE);
    }
    else
    {
        /*Turn off the green LED*/
        Driver_GPIO_set_pin_State(green_LED->port_type, green_LED->pin, HIGH_STATE);
    }

    return;
}

/*Functions*********************************************************************
*
* Function name: main
* Description: main function of the program
*
END***************************************************************************/
int main(void)
{
    uint32_t light_value = 0;   /*This variable stores the digital value of light intensity*/
    uint32_t duty_cycle = 0;    /*This variable stores the duty cycle of the PWM*/

    /*SCGC5 configuration info*/
    SCGC5_config_info SCGC5_config = {
        .PORTA_clock = DISABLED,
        .PORTB_clock = DISABLED,
        .PORTC_clock = DISABLED,
        .PORTD_clock = ENABLED,
        .PORTE_clock = DISABLED,
    };

    /*SCGC6 configuration info*/
    SCGC6_config_info SCGC6_config = {
        .ADC0_clock = ENABLED,
        .PIT_clock = ENABLED,
    };

    /*ADC0 configuration info*/
    ADC0_config_info ADC0_config = {
        /*CFG1 register configuration*/
        .CFG1_config.clock_source = BUS_CLOCK,
        .CFG1_config.clock_divide = DIV_1,
        .CFG1_config.conversion_mode = SINGLE_END_8BITS,
        .CFG1_config.sample_time = SHORT_SAMPLE_TIME,
        /*SC1n register configuration*/
        .SC1_config.DIFF_mode = SINGLE_ENDED_INPUT,
        .SC1_config.SC1_channel = 0,
        .SC1_config.IRQ_state = COCO_IRQ_DISABLED,
        .SC1_config.input_channel = DADP3_DAD3,
    };

    /*GPIO pin configuration for green LED*/
    GPIO_config_info_t green_LED = {
        .port_type = PORT_D,
        .pin = 5,
        .pull_type = PULL_DOWN,
        .direction = GPIO_OUTPUT,
        .initial_state = HIGH_STATE,
    };

    /*PIT configuration info*/
    PIT_config_info PIT_config = {
        /*MCR resigter configuration*/
        .MCR_config.freeze_mode = TIMERS_STOPPED_IN_DEBUG,
        .MCR_config.module_state = PIT_ENABLED,
        /*TCTRLn register configuration*/
        .TCTRLn_config.timer_index = 0,
        .TCTRLn_config.timer_state = TIMER_ENABLED,
        .TCTRLn_config.chain_mode = CHAIN_MODE_DISABLED,
        .TCTRLn_config.IRQ_state = IRQ_ENABLED,
        /*Load value for PIT timer*/
        .load_value = PIT_TICKS_100kHz,
    };

    /*Init clock according to SCGC5 configuration*/
    Driver_SIM_SCGC5_init_clock(&SCGC5_config);
    /*Init clock according to SCGC6 configuration*/
    Driver_SIM_SCGC6_init_clock(&SCGC6_config);
    /*Init ADC0 according to ADC0 configuration*/
    Driver_ADC0_init_ADC(&ADC0_config);
    /*Init GPIO pin according to green LED configuration*/
    Driver_GPIO_init_pin(&green_LED);
    /*Init PIT according to PIT configuration*/
    Driver_PIT_init(&PIT_config);
    /*Register update ticks callback function for PIT interrupt handler*/
    Driver_PIT_register_callabck(Update_ticks_PIT_IRQ);

    while (1)
    {
        /*Get digital value of light intensity*/
        light_value = get_light_value(&ADC0_config);
        /*Get duty cycle based on the light intensity*/
        duty_cycle = get_duty_cycle(light_value);
        /*Run the software PWM*/
        software_PWM(duty_cycle);
        /*Control the green LED by the software PWM*/
        control_green_LED(&green_LED);
    }

    return 0;
}
/*EOF*/
