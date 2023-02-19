/**
 * @file      app.c
 *
 * @brief     Application
 *
 * @date      2023-01-20
 *
 *
 */

/** \addtogroup app
 *  @{
 */

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "app.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "bsp.h"
#include "encoder_drv.h"
#include "buttons_drv.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/
static encoder_state_t encoder_states[ENCODER_QTY_CH];
static buttons_state_t buttons_state[BUTTONS_QTY];
/******************************************************************************
 * PUBLIC DATA
 ******************************************************************************/
uint8_t bufferUartTx[DEVICE_SIZE_BUF_USART2];
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
 * @brief Application entry point
 *
 * @warning no exit from this function!
 *
 */
void app_entry_point(void)
{
    bsp_init();
    encoder_init();
    buttons_init();
    for (;;)
    {
        encoder_get_channel_value(ENCODER_CH_0, &encoder_states[ENCODER_CH_0]);
        encoder_get_channel_value(ENCODER_CH_1, &encoder_states[ENCODER_CH_1]);
        encoder_get_channel_value(ENCODER_CH_2, &encoder_states[ENCODER_CH_2]);
        encoder_get_channel_value(ENCODER_CH_3, &encoder_states[ENCODER_CH_3]);

        for (uint8_t i = 0; i < BUTTONS_QTY; i++)
        {
            buttons_state[i] = buttons_get_value(i);
        }
        Delay(250);
    }
}

/**
 * @brief IRQ of TIM3
 *
 */
void TIM3_IRQHandler(void)
{
    GPIO_SetBits(GPIOB, GPIO_Pin_10);
    encoder_calculate_rotations();
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
    GPIO_ResetBits(GPIOB, GPIO_Pin_10);
}

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/