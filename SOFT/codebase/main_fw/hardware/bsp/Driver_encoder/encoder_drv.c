/**
 * @file      encoder_drv.c
 *
 * @brief     Encoder driver. It is rigidly tied to the applied scheme, does not configure
 *
 * @date      2023-02-14
 *
 *
 */

/** \addtogroup module
 *  @{
 */

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "encoder_drv.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <general_types.h>
#include <general_macros.h>
#include "stm32f10x_gpio.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/

// Define direction rotation constants
#define ENCODER_DIR_ROTATION_NONE_CONST  (0U)
#define ENCODER_DIR_ROTATION_LEFT_CONST  (1U)
#define ENCODER_DIR_ROTATION_RIGHT_CONST (2U)

/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/

// Encoder real time parameters
typedef struct
{
    uint32_t       nCounterImpulsesLeft;
    uint32_t       nCounterImpulsesRight;
    uint8_t        n_bit_pos_result;
    GPIO_TypeDef * nGPIOPortPin0;
    GPIO_TypeDef * nGPIOPortPin1;
    uint16_t       nGPIOPin0;
    uint16_t       nGPIOPin1;
    uint8_t        nGPIOPin0Mode;
    uint8_t        nGPIOPin1Mode;
    uint8_t        nChannelEn;
} encoder_parmeters_t;

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/

// Array of encoder states
static encoder_parmeters_t encoder_aParameters[ENCODER_QTY_CH] = {{0, 0, ENCODER_BIT_RESULT_POS_CH0, ENCODER_GPIO_PORT_PIN0_CH0, ENCODER_GPIO_PORT_PIN1_CH0, ENCODER_GPIO_PIN_0_CH0, ENCODER_GPIO_PIN_1_CH0, ENCODER_GPIO_PIN_0_MODE_CH0, ENCODER_GPIO_PIN_1_MODE_CH0, ENCODER_CH0_EN},
                                                                  {0, 0, ENCODER_BIT_RESULT_POS_CH1, ENCODER_GPIO_PORT_PIN0_CH1, ENCODER_GPIO_PORT_PIN1_CH1, ENCODER_GPIO_PIN_0_CH1, ENCODER_GPIO_PIN_1_CH1, ENCODER_GPIO_PIN_0_MODE_CH1, ENCODER_GPIO_PIN_1_MODE_CH1, ENCODER_CH1_EN},
                                                                  {0, 0, ENCODER_BIT_RESULT_POS_CH2, ENCODER_GPIO_PORT_PIN0_CH2, ENCODER_GPIO_PORT_PIN1_CH2, ENCODER_GPIO_PIN_0_CH2, ENCODER_GPIO_PIN_1_CH2, ENCODER_GPIO_PIN_0_MODE_CH2, ENCODER_GPIO_PIN_1_MODE_CH2, ENCODER_CH2_EN},
                                                                  {0, 0, ENCODER_BIT_RESULT_POS_CH3, ENCODER_GPIO_PORT_PIN0_CH3, ENCODER_GPIO_PORT_PIN1_CH3, ENCODER_GPIO_PIN_0_CH3, ENCODER_GPIO_PIN_1_CH3, ENCODER_GPIO_PIN_0_MODE_CH3, ENCODER_GPIO_PIN_1_MODE_CH3, ENCODER_CH3_EN},
                                                                  {0, 0, ENCODER_BIT_RESULT_POS_CH4, ENCODER_GPIO_PORT_PIN0_CH4, ENCODER_GPIO_PORT_PIN1_CH4, ENCODER_GPIO_PIN_0_CH4, ENCODER_GPIO_PIN_1_CH4, ENCODER_GPIO_PIN_0_MODE_CH4, ENCODER_GPIO_PIN_1_MODE_CH4, ENCODER_CH4_EN}};

static uint16_t n_last_state_line_A;
static uint16_t n_last_state_line_B;

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

static uint16_t get_state_line_A(void);
static uint16_t get_state_line_B(void);

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

/**
 * @brief Read line A of encoders
 *
 * @return currents status line A
 */
static uint16_t get_state_line_A(void)
{
    return (GPIO_ReadInputData(GPIOB) >> 1U);
}

/**
 * @brief Read line B of encoders
 *
 * @return currents status line B
 */
static uint16_t get_state_line_B(void)
{
    return (GPIO_ReadInputData(GPIOB));
}

/**
 * @brief Determine rotation foward/back
 * @param x1: last state line A
 * @param x2: last state line B
 * @param y1: next state line A
 * @param y2: next state line B
 * @return 1 - rotation foward/back exist, 0- no rotation
 */
static inline uint16_t detect(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
    return (x2 ^ y1) & ~(x1 ^ y2);
}
/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/
/**
 * @brief Encoder init
 *
 */
void encoder_init(void)
{

    // Init GPIO
    for (uint8_t i = 0; i < ENCODER_QTY_CH; i++)
    {
        if (ON == encoder_aParameters[i].nChannelEn)
        {
            GPIO_InitTypeDef GPIO_InitStruct;
            GPIO_InitStruct.GPIO_Pin   = encoder_aParameters[i].nGPIOPin0;
            GPIO_InitStruct.GPIO_Mode  = encoder_aParameters[i].nGPIOPin0Mode;
            GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(encoder_aParameters[i].nGPIOPortPin0, &GPIO_InitStruct);

            GPIO_InitStruct.GPIO_Pin   = encoder_aParameters[i].nGPIOPin1;
            GPIO_InitStruct.GPIO_Mode  = encoder_aParameters[i].nGPIOPin1Mode;
            GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_Init(encoder_aParameters[i].nGPIOPortPin1, &GPIO_InitStruct);

            encoder_aParameters[i].nCounterImpulsesLeft  = 0U;
            encoder_aParameters[i].nCounterImpulsesRight = 0U;
        }
        else
        {
            DoNothing();
        }
    }
} // end of ENCODER_Init()

/**
 * @brief Calculate rotations of all encoders
 *
 */
void encoder_calculate_rotations(void)
{
    uint16_t n_current_state_line_A = get_state_line_A();
    uint16_t n_current_state_line_B = get_state_line_B();

    uint16_t fwd  = detect(n_last_state_line_A, n_last_state_line_B, n_current_state_line_A, n_current_state_line_B);
    uint16_t back = detect(n_last_state_line_B, n_last_state_line_A, n_current_state_line_B, n_current_state_line_A);

    n_last_state_line_A = n_current_state_line_A;
    n_last_state_line_B = n_current_state_line_B;

    for (uint8_t nChNumber = 0; nChNumber < ENCODER_QTY_CH; nChNumber++)
    {
        if (ON == encoder_aParameters[nChNumber].nChannelEn)
        {
            if (fwd & (1U << encoder_aParameters[nChNumber].n_bit_pos_result))
            {
                encoder_aParameters[nChNumber].nCounterImpulsesRight++;
            }
            else if (back & (1U << encoder_aParameters[nChNumber].n_bit_pos_result))
            {
                encoder_aParameters[nChNumber].nCounterImpulsesLeft++;
            }
            else
            {
                DoNothing();
            }
        }
    }
}

/**
 * @brief Get channel value
 * @param[in] nChannel: channel number
 * @param[out] stStateCh: encoder status
 */
void encoder_get_channel_value(const uint8_t nChannel, encoder_state_t * const stStateCh)
{
    if (ON == encoder_aParameters[nChannel].nChannelEn)
    {
        if (encoder_aParameters[nChannel].nCounterImpulsesRight > encoder_aParameters[nChannel].nCounterImpulsesLeft)
        {
            stStateCh->n_counter_impulses = (encoder_aParameters[nChannel].nCounterImpulsesRight - encoder_aParameters[nChannel].nCounterImpulsesLeft);

            if (ENCODER_CH_1 == nChannel)
            {
                if (((stStateCh->n_counter_impulses % 4U) == 0) && (stStateCh->n_counter_impulses != 0))
                {
                    stStateCh->enDirection = ENCODER_DIR_ROTATION_RIGHT;

                    encoder_aParameters[nChannel].nCounterImpulsesRight = 0U;
                    encoder_aParameters[nChannel].nCounterImpulsesLeft  = 0U;
                }
                else
                {
                    stStateCh->enDirection = ENCODER_DIR_ROTATION_NONE;
                }
            }
            else
            {
                stStateCh->enDirection = ENCODER_DIR_ROTATION_RIGHT;

                encoder_aParameters[nChannel].nCounterImpulsesRight = 0U;
                encoder_aParameters[nChannel].nCounterImpulsesLeft  = 0U;
            }
        }
        else if (encoder_aParameters[nChannel].nCounterImpulsesRight < encoder_aParameters[nChannel].nCounterImpulsesLeft)
        {
            stStateCh->n_counter_impulses = (encoder_aParameters[nChannel].nCounterImpulsesLeft - encoder_aParameters[nChannel].nCounterImpulsesRight);

            stStateCh->enDirection = ENCODER_DIR_ROTATION_LEFT;

            encoder_aParameters[nChannel].nCounterImpulsesRight = 0U;
            encoder_aParameters[nChannel].nCounterImpulsesLeft  = 0U;
        }
        else
        {
            stStateCh->enDirection = ENCODER_DIR_ROTATION_NONE;
        }
    }
    else
    {
        DoNothing();
    }
} // end of ENCODER_GetChannelValue()

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/