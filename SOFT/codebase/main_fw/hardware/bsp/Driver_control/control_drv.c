/**
 * @file      control_drv.c
 *
 * @brief     Control driver
 *
 * @date      2023-02-21
 *
 */

/** \addtogroup module
 *  @{
 */

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "control_drv.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <general_types.h>
#include <general_macros.h>
#include "encoder_drv.h"
#include "buttons_drv.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/
#define MIDI_MARKER     (0xb4)
#define MIDI_SIZE_FRAME (0x03)

/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/
typedef enum
{
    TOGGLE_POS1 = 0,
    TOGGLE_POS2,
    TOGGLE_POS3
} toggle_pos_t;

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/
static uint8_t         bufferUartTx[DEVICE_SIZE_BUF_USART2];
static encoder_state_t encoder_states[ENCODER_QTY_CH];
static buttons_state_t buttons_state[BUTTONS_QTY];
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
static void         create_midi_frame(const uint8_t cc, const uint8_t data);
static toggle_pos_t get_state_toggle_two_pos(void);
static toggle_pos_t get_state_toggle_three_pos(void);
static void         process_encoder_sw1(void);
static void         process_encoder_sw2(void);
static void         process_encoder_sw3(void);
static void         process_encoder_sw4(void);

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

/**
 * @brief Create a midi frame object
 *
 * @param cc
 * @param data
 */
static void create_midi_frame(const uint8_t cc, const uint8_t data)
{
    bufferUartTx[0]  = MIDI_MARKER;
    bufferUartTx[1U] = cc;
    bufferUartTx[2U] = data;
}

/**
 * @brief Get the state toggle three pos object
 *
 * @return toggle_pos_t
 */
static toggle_pos_t get_state_toggle_three_pos(void)
{
    toggle_pos_t toggle_pos;

    if (BUTTONS_ACTIVE == buttons_get_value(BUTTONS_CHx))
    {
        toggle_pos = TOGGLE_POS1;
    }
    else if (BUTTONS_ACTIVE == buttons_get_value(BUTTONS_CHxx))
    {
        toggle_pos = TOGGLE_POS2;
    }
    else
    {
        toggle_pos = TOGGLE_POS3;
    }

    return toggle_pos;
}

/**
 * @brief Get the state toggle two pos object
 *
 * @return toggle_pos_t
 */
static toggle_pos_t get_state_toggle_two_pos(void)
{
    toggle_pos_t toggle_pos;

    if (BUTTONS_ACTIVE == buttons_get_value(BUTTONS_CHx))
    {
        toggle_pos = TOGGLE_POS1;
    }
    else
    {
        toggle_pos = TOGGLE_POS2;
    }

    return toggle_pos;
}

/**
 * @brief Process encoder sw
 *
 */
static void process_encoder_sw1(void)
{
    encoder_state_t * encoder_state = &encoder_states[ENCODER_CH_0];
    toggle_pos_t      toggle_pos;
    uint8_t           n_data = 0;

    encoder_get_channel_value(ENCODER_CH_0, encoder_state);
    
    if (ENCODER_DIR_ROTATION_NONE != encoder_state->enDirection)
    {
        toggle_pos = get_state_toggle_three_pos();

        if (ENCODER_DIR_ROTATION_RIGHT == encoder_state->enDirection)
        {
            n_data = 18;
        }
        else
        {
            n_data = 109;
        }

        switch (toggle_pos)
        {
            case TOGGLE_POS1:
                create_midi_frame(30, n_data);
                break;
            case TOGGLE_POS2:
                create_midi_frame(40, n_data);
                break;
            case TOGGLE_POS3:
                create_midi_frame(50, n_data);
                break;
            default:
                break;
        }

        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }
    else
    {
        DoNothing();
    }
}

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/

/**
 * @brief Polling encoders and buttons of control panel
 *
 */
void control_poll(void)
{
    process_encoder_sw1();
}

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/