/**
 * @file      buttons_drv.c
 *
 * @brief     Some module
 *
 * @date      2023-02-18
 *
 * @par
 */

/** \addtogroup module
 *  @{
 */

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "buttons_drv.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <general_types.h>
#include <general_macros.h>
#include "stm32f10x_gpio.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/

typedef struct
{
    uint8_t        n_ChannelEn;
    GPIO_TypeDef * gpio;
    uint16_t       n_pin;
    uint8_t        n_mode;
    uint8_t        n_active;
} button_t;

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/
static button_t buttons_cfg[BUTTONS_QTY] = {{BUTTONS_CH0_EN, BUTTONS_GPIO_PORT_CH0, BUTTONS_GPIO_PIN_CH0, BUTTONS_GPIO_PIN_MODE_CH0, BUTTONS_ACTIVE_CH0},
                                            {BUTTONS_CH1_EN, BUTTONS_GPIO_PORT_CH1, BUTTONS_GPIO_PIN_CH1, BUTTONS_GPIO_PIN_MODE_CH1, BUTTONS_ACTIVE_CH1},
                                            {BUTTONS_CH2_EN, BUTTONS_GPIO_PORT_CH2, BUTTONS_GPIO_PIN_CH2, BUTTONS_GPIO_PIN_MODE_CH2, BUTTONS_ACTIVE_CH2},
                                            {BUTTONS_CH3_EN, BUTTONS_GPIO_PORT_CH3, BUTTONS_GPIO_PIN_CH3, BUTTONS_GPIO_PIN_MODE_CH3, BUTTONS_ACTIVE_CH3},
                                            {BUTTONS_CH4_EN, BUTTONS_GPIO_PORT_CH4, BUTTONS_GPIO_PIN_CH4, BUTTONS_GPIO_PIN_MODE_CH4, BUTTONS_ACTIVE_CH4},
                                            {BUTTONS_CH5_EN, BUTTONS_GPIO_PORT_CH5, BUTTONS_GPIO_PIN_CH5, BUTTONS_GPIO_PIN_MODE_CH5, BUTTONS_ACTIVE_CH5},
                                            {BUTTONS_CH6_EN, BUTTONS_GPIO_PORT_CH6, BUTTONS_GPIO_PIN_CH6, BUTTONS_GPIO_PIN_MODE_CH6, BUTTONS_ACTIVE_CH6},
                                            {BUTTONS_CH7_EN, BUTTONS_GPIO_PORT_CH7, BUTTONS_GPIO_PIN_CH7, BUTTONS_GPIO_PIN_MODE_CH7, BUTTONS_ACTIVE_CH7},
                                            {BUTTONS_CH8_EN, BUTTONS_GPIO_PORT_CH8, BUTTONS_GPIO_PIN_CH8, BUTTONS_GPIO_PIN_MODE_CH8, BUTTONS_ACTIVE_CH8},
                                            {BUTTONS_CH9_EN, BUTTONS_GPIO_PORT_CH9, BUTTONS_GPIO_PIN_CH9, BUTTONS_GPIO_PIN_MODE_CH9, BUTTONS_ACTIVE_CH9},
                                            {BUTTONS_CH10_EN, BUTTONS_GPIO_PORT_CH10, BUTTONS_GPIO_PIN_CH10, BUTTONS_GPIO_PIN_MODE_CH10, BUTTONS_ACTIVE_CH10},
                                            };

/******************************************************************************
 * PUBLIC DATA
 ******************************************************************************/

/******************************************************************************
 * EXTERNAL DATA
 ******************************************************************************/

/******************************************************************************
 * EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/

/**
 * @brief Init buttons driver
 *
 */
void buttons_init(void)
{
    for (uint8_t n_button_num = 0; n_button_num < BUTTONS_QTY; n_button_num++)
    {
        if (ON == buttons_cfg[n_button_num].n_ChannelEn)
        {
            GPIO_InitTypeDef GPIO_InitStruct;
            GPIO_InitStruct.GPIO_Pin   = buttons_cfg[n_button_num].n_pin;
            GPIO_InitStruct.GPIO_Mode  = buttons_cfg[n_button_num].n_mode;
            GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(buttons_cfg[n_button_num].gpio, &GPIO_InitStruct);
        }
        else
        {
            DoNothing();
        }
    }
}

/**
 * @brief Get buuton state
 *
 * @param n_ch : number of channel
 * @return BUTTONS_ACTIVE, BUTTONS_NOT_ACTIVE
 */
buttons_state_t buttons_get_value(const uint8_t n_ch)
{
    buttons_state_t state = BUTTONS_NOT_ACTIVE;

    if (n_ch <= BUTTONS_QTY)
    {
        if (ON == buttons_cfg[n_ch].n_ChannelEn)
        {
            uint8_t data = GPIO_ReadInputDataBit(buttons_cfg[n_ch].gpio, buttons_cfg[n_ch].n_pin);

            if ((BUTTONS_ACTIVE_STATE_HIGH == buttons_cfg[n_ch].n_active) && (Bit_SET == data))
            {
                state = BUTTONS_ACTIVE;
            }
            else if ((BUTTONS_ACTIVE_STATE_LOW == buttons_cfg[n_ch].n_active) && (Bit_RESET == data))
            {
                state = BUTTONS_ACTIVE;
            }
            else
            {
                state = BUTTONS_NOT_ACTIVE;
            }
        }
        else
        {
            state = BUTTONS_ER;
        }
    }
    else
    {
        state = BUTTONS_ER;
    }
    return state;
}

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/