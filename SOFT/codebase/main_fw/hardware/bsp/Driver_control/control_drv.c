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
#include "stm32f10x.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/
#define MIDI_MARKER             (0xb4)
#define MIDI_SIZE_FRAME         (0x03)
#define SW7_SIZE_FSM_TABLE      (24U)
#define SW9_SIZE_FSM_TABLE      (12U)
#define SW10_SIZE_FSM_TABLE     (12U)
#define SW12_SIZE_FSM_TABLE     (24U)
#define SW1_SIZE_FSM_TABLE      (6U)
#define SIZE_BUF_USART2         (256)
#define TRIG_SCHMITT            (3U)
#define TRIG_SCHMITT_SW_BUTTONS (20U)

/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/
typedef enum
{
    TOGGLE_POS1 = 0,
    TOGGLE_POS2,
    TOGGLE_POS3
} toggle_pos_t;

typedef union
{
    struct
    {
        uint8_t toggle_2pos : 1;
        uint8_t dir_rotation : 1;
        uint8_t enc_button : 1;
        uint8_t toggle_3pos : 2;
        uint8_t : 3;
    } B;
    uint8_t R;
} sw7_input_prm_t;

typedef union
{
    struct
    {
        uint8_t toggle_2pos : 1;
        uint8_t dir_rotation : 1;
        uint8_t toggle_3pos : 2;
        uint8_t : 4;
    } B;
    uint8_t R;
} sw9_input_prm_t;

typedef union
{
    struct
    {
        uint8_t toggle_2pos : 1;
        uint8_t toggle_3pos : 2;
        uint8_t : 5;
    } B;
    uint8_t R;
} sw1_input_prm_t;

typedef union
{
    struct prm_str
    {
        uint8_t cc;
        uint8_t data;
    } prm;
    uint16_t W;
} table_t;

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/

static buttons_state_t buttons_state[BUTTONS_QTY];
static sw1_input_prm_t sw1_input_prm;
static sw1_input_prm_t sw2_input_prm;
static sw1_input_prm_t sw3_input_prm;
static sw1_input_prm_t sw4_input_prm;
static sw1_input_prm_t sw5_input_prm;
static sw1_input_prm_t sw6_input_prm;
static sw7_input_prm_t sw7_input_prm;
static sw7_input_prm_t sw12_input_prm;
static sw9_input_prm_t sw9_input_prm;
static sw9_input_prm_t sw10_input_prm;
static buttons_state_t last_buttons_state_sw7_1  = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw12_1 = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw1    = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw2    = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw3    = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw4    = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw5    = BUTTONS_NOT_ACTIVE;
static buttons_state_t last_buttons_state_sw6    = BUTTONS_NOT_ACTIVE;
static uint8_t         n_cnt_trig_schmitt_sw7_1  = 0;
static uint8_t         n_cnt_trig_schmitt_sw12_1 = 0;
static uint8_t         n_cnt_trig_schmitt_sw1    = 0;
static uint8_t         n_cnt_trig_schmitt_sw2    = 0;
static uint8_t         n_cnt_trig_schmitt_sw3    = 0;
static uint8_t         n_cnt_trig_schmitt_sw4    = 0;
static uint8_t         n_cnt_trig_schmitt_sw5    = 0;
static uint8_t         n_cnt_trig_schmitt_sw6    = 0;

static table_t a_sw7_fsm_table[SW7_SIZE_FSM_TABLE]
    = {{CONTROL_ENCODER_SW7_VAR0_CC, CONTROL_ENCODER_SW7_VAR0_DATA},   {CONTROL_ENCODER_SW7_VAR1_CC, CONTROL_ENCODER_SW7_VAR1_DATA},   {CONTROL_ENCODER_SW7_VAR2_CC, CONTROL_ENCODER_SW7_VAR2_DATA},   {CONTROL_ENCODER_SW7_VAR3_CC, CONTROL_ENCODER_SW7_VAR3_DATA},
       {CONTROL_ENCODER_SW7_VAR4_CC, CONTROL_ENCODER_SW7_VAR4_DATA},   {CONTROL_ENCODER_SW7_VAR5_CC, CONTROL_ENCODER_SW7_VAR5_DATA},   {CONTROL_ENCODER_SW7_VAR6_CC, CONTROL_ENCODER_SW7_VAR6_DATA},   {CONTROL_ENCODER_SW7_VAR7_CC, CONTROL_ENCODER_SW7_VAR7_DATA},
       {CONTROL_ENCODER_SW7_VAR8_CC, CONTROL_ENCODER_SW7_VAR8_DATA},   {CONTROL_ENCODER_SW7_VAR9_CC, CONTROL_ENCODER_SW7_VAR9_DATA},   {CONTROL_ENCODER_SW7_VAR10_CC, CONTROL_ENCODER_SW7_VAR10_DATA}, {CONTROL_ENCODER_SW7_VAR11_CC, CONTROL_ENCODER_SW7_VAR11_DATA},
       {CONTROL_ENCODER_SW7_VAR12_CC, CONTROL_ENCODER_SW7_VAR12_DATA}, {CONTROL_ENCODER_SW7_VAR13_CC, CONTROL_ENCODER_SW7_VAR13_DATA}, {CONTROL_ENCODER_SW7_VAR14_CC, CONTROL_ENCODER_SW7_VAR14_DATA}, {CONTROL_ENCODER_SW7_VAR15_CC, CONTROL_ENCODER_SW7_VAR15_DATA},
       {CONTROL_ENCODER_SW7_VAR16_CC, CONTROL_ENCODER_SW7_VAR16_DATA}, {CONTROL_ENCODER_SW7_VAR17_CC, CONTROL_ENCODER_SW7_VAR17_DATA}, {CONTROL_ENCODER_SW7_VAR18_CC, CONTROL_ENCODER_SW7_VAR18_DATA}, {CONTROL_ENCODER_SW7_VAR19_CC, CONTROL_ENCODER_SW7_VAR19_DATA},
       {CONTROL_ENCODER_SW7_VAR20_CC, CONTROL_ENCODER_SW7_VAR20_DATA}, {CONTROL_ENCODER_SW7_VAR21_CC, CONTROL_ENCODER_SW7_VAR21_DATA}, {CONTROL_ENCODER_SW7_VAR22_CC, CONTROL_ENCODER_SW7_VAR22_DATA}, {CONTROL_ENCODER_SW7_VAR23_CC, CONTROL_ENCODER_SW7_VAR23_DATA}};

static table_t a_sw9_fsm_table[SW9_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW9_VAR0_CC, CONTROL_ENCODER_SW9_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR1_CC, CONTROL_ENCODER_SW9_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR2_CC, CONTROL_ENCODER_SW9_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR3_CC, CONTROL_ENCODER_SW9_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR4_CC, CONTROL_ENCODER_SW9_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR5_CC, CONTROL_ENCODER_SW9_VAR5_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR6_CC, CONTROL_ENCODER_SW9_VAR6_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR7_CC, CONTROL_ENCODER_SW9_VAR7_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR8_CC, CONTROL_ENCODER_SW9_VAR8_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR9_CC, CONTROL_ENCODER_SW9_VAR9_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR10_CC, CONTROL_ENCODER_SW9_VAR10_DATA},
                                                      {CONTROL_ENCODER_SW9_VAR11_CC, CONTROL_ENCODER_SW9_VAR11_DATA}};

static table_t a_sw10_fsm_table[SW10_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW10_VAR0_CC, CONTROL_ENCODER_SW10_VAR0_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR1_CC, CONTROL_ENCODER_SW10_VAR1_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR2_CC, CONTROL_ENCODER_SW10_VAR2_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR3_CC, CONTROL_ENCODER_SW10_VAR3_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR4_CC, CONTROL_ENCODER_SW10_VAR4_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR5_CC, CONTROL_ENCODER_SW10_VAR5_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR6_CC, CONTROL_ENCODER_SW10_VAR6_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR7_CC, CONTROL_ENCODER_SW10_VAR7_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR8_CC, CONTROL_ENCODER_SW10_VAR8_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR9_CC, CONTROL_ENCODER_SW10_VAR9_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR10_CC, CONTROL_ENCODER_SW10_VAR10_DATA},
                                                        {CONTROL_ENCODER_SW10_VAR11_CC, CONTROL_ENCODER_SW10_VAR11_DATA}};

static table_t a_sw12_fsm_table[SW12_SIZE_FSM_TABLE]
    = {{CONTROL_ENCODER_SW12_VAR0_CC, CONTROL_ENCODER_SW12_VAR0_DATA},   {CONTROL_ENCODER_SW12_VAR1_CC, CONTROL_ENCODER_SW12_VAR1_DATA},   {CONTROL_ENCODER_SW12_VAR2_CC, CONTROL_ENCODER_SW12_VAR2_DATA},   {CONTROL_ENCODER_SW12_VAR3_CC, CONTROL_ENCODER_SW12_VAR3_DATA},
       {CONTROL_ENCODER_SW12_VAR4_CC, CONTROL_ENCODER_SW12_VAR4_DATA},   {CONTROL_ENCODER_SW12_VAR5_CC, CONTROL_ENCODER_SW12_VAR5_DATA},   {CONTROL_ENCODER_SW12_VAR6_CC, CONTROL_ENCODER_SW12_VAR6_DATA},   {CONTROL_ENCODER_SW12_VAR7_CC, CONTROL_ENCODER_SW12_VAR7_DATA},
       {CONTROL_ENCODER_SW12_VAR8_CC, CONTROL_ENCODER_SW12_VAR8_DATA},   {CONTROL_ENCODER_SW12_VAR9_CC, CONTROL_ENCODER_SW12_VAR9_DATA},   {CONTROL_ENCODER_SW12_VAR10_CC, CONTROL_ENCODER_SW12_VAR10_DATA}, {CONTROL_ENCODER_SW12_VAR11_CC, CONTROL_ENCODER_SW12_VAR11_DATA},
       {CONTROL_ENCODER_SW12_VAR12_CC, CONTROL_ENCODER_SW12_VAR12_DATA}, {CONTROL_ENCODER_SW12_VAR13_CC, CONTROL_ENCODER_SW12_VAR13_DATA}, {CONTROL_ENCODER_SW12_VAR14_CC, CONTROL_ENCODER_SW12_VAR14_DATA}, {CONTROL_ENCODER_SW12_VAR15_CC, CONTROL_ENCODER_SW12_VAR15_DATA},
       {CONTROL_ENCODER_SW12_VAR16_CC, CONTROL_ENCODER_SW12_VAR16_DATA}, {CONTROL_ENCODER_SW12_VAR17_CC, CONTROL_ENCODER_SW12_VAR17_DATA}, {CONTROL_ENCODER_SW12_VAR18_CC, CONTROL_ENCODER_SW12_VAR18_DATA}, {CONTROL_ENCODER_SW12_VAR19_CC, CONTROL_ENCODER_SW12_VAR19_DATA},
       {CONTROL_ENCODER_SW12_VAR20_CC, CONTROL_ENCODER_SW12_VAR20_DATA}, {CONTROL_ENCODER_SW12_VAR21_CC, CONTROL_ENCODER_SW12_VAR21_DATA}, {CONTROL_ENCODER_SW12_VAR22_CC, CONTROL_ENCODER_SW12_VAR22_DATA}, {CONTROL_ENCODER_SW12_VAR23_CC, CONTROL_ENCODER_SW12_VAR23_DATA}};

static table_t a_sw1_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW1_VAR0_CC, CONTROL_ENCODER_SW1_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW1_VAR1_CC, CONTROL_ENCODER_SW1_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW1_VAR2_CC, CONTROL_ENCODER_SW1_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW1_VAR3_CC, CONTROL_ENCODER_SW1_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW1_VAR4_CC, CONTROL_ENCODER_SW1_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW1_VAR5_CC, CONTROL_ENCODER_SW1_VAR5_DATA}};

static table_t a_sw2_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW2_VAR0_CC, CONTROL_ENCODER_SW2_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW2_VAR1_CC, CONTROL_ENCODER_SW2_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW2_VAR2_CC, CONTROL_ENCODER_SW2_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW2_VAR3_CC, CONTROL_ENCODER_SW2_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW2_VAR4_CC, CONTROL_ENCODER_SW2_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW2_VAR5_CC, CONTROL_ENCODER_SW2_VAR5_DATA}};

static table_t a_sw3_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW3_VAR0_CC, CONTROL_ENCODER_SW3_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW3_VAR1_CC, CONTROL_ENCODER_SW3_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW3_VAR2_CC, CONTROL_ENCODER_SW3_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW3_VAR3_CC, CONTROL_ENCODER_SW3_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW3_VAR4_CC, CONTROL_ENCODER_SW3_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW3_VAR5_CC, CONTROL_ENCODER_SW3_VAR5_DATA}};

static table_t a_sw4_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW4_VAR0_CC, CONTROL_ENCODER_SW4_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW4_VAR1_CC, CONTROL_ENCODER_SW4_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW4_VAR2_CC, CONTROL_ENCODER_SW4_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW4_VAR3_CC, CONTROL_ENCODER_SW4_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW4_VAR4_CC, CONTROL_ENCODER_SW4_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW4_VAR5_CC, CONTROL_ENCODER_SW4_VAR5_DATA}};

static table_t a_sw5_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW5_VAR0_CC, CONTROL_ENCODER_SW5_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW5_VAR1_CC, CONTROL_ENCODER_SW5_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW5_VAR2_CC, CONTROL_ENCODER_SW5_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW5_VAR3_CC, CONTROL_ENCODER_SW5_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW5_VAR4_CC, CONTROL_ENCODER_SW5_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW5_VAR5_CC, CONTROL_ENCODER_SW5_VAR5_DATA}};

static table_t a_sw6_fsm_table[SW1_SIZE_FSM_TABLE] = {{CONTROL_ENCODER_SW6_VAR0_CC, CONTROL_ENCODER_SW6_VAR0_DATA},
                                                      {CONTROL_ENCODER_SW6_VAR1_CC, CONTROL_ENCODER_SW6_VAR1_DATA},
                                                      {CONTROL_ENCODER_SW6_VAR2_CC, CONTROL_ENCODER_SW6_VAR2_DATA},
                                                      {CONTROL_ENCODER_SW6_VAR3_CC, CONTROL_ENCODER_SW6_VAR3_DATA},
                                                      {CONTROL_ENCODER_SW6_VAR4_CC, CONTROL_ENCODER_SW6_VAR4_DATA},
                                                      {CONTROL_ENCODER_SW6_VAR5_CC, CONTROL_ENCODER_SW6_VAR5_DATA}};

/******************************************************************************
 * PUBLIC DATA
 ******************************************************************************/
uint8_t bufferUartTx[SIZE_BUF_USART2];
/******************************************************************************
 * EXTERNAL DATA
 ******************************************************************************/

/******************************************************************************
 * EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/
static void       create_midi_frame(const uint8_t cc, const uint8_t data);
static STD_RESULT update_sw_buttons_input_prm(uint8_t sw_but_ch, sw1_input_prm_t * sw_input_prm, buttons_state_t * last_buttons_state_sw, uint8_t * n_cnt_trig_schmitt_sw);
static STD_RESULT update_sw7_input_prm(void);
static STD_RESULT update_sw9_input_prm(void);
static STD_RESULT update_sw10_input_prm(void);
static STD_RESULT update_sw12_input_prm(void);

static STD_RESULT get_toggle_sw11_pos(toggle_pos_t * toggle_pos);
static STD_RESULT get_toggle_sw8_pos(toggle_pos_t * toggle_pos);

static toggle_pos_t get_toggle_two_pos(void);
static void USARTSend(const unsigned char * pucbufferUartTx, uint16_t size);

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
 * @brief Get the toggle three pos object
 *
 * @return toggle_pos_t
 */
static STD_RESULT get_toggle_sw11_pos(toggle_pos_t * toggle_pos)
{
    STD_RESULT result;

    buttons_state_t buttons_state_1 = buttons_get_value(CONTROL_TOGGLE_SW11_1);
    buttons_state_t buttons_state_2 = buttons_get_value(CONTROL_TOGGLE_SW11_2);

    if ((BUTTONS_ER != buttons_state_1) && (BUTTONS_ER != buttons_state_2))
    {
        if (BUTTONS_ACTIVE == buttons_state_1)
        {
            *toggle_pos = TOGGLE_POS1;
        }
        else if (BUTTONS_ACTIVE == buttons_state_2)
        {
            *toggle_pos = TOGGLE_POS3;
        }
        else
        {
            *toggle_pos = TOGGLE_POS2;
        }
        result = RESULT_OK;
    }
    else
    {
        result = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Get the toggle two pos object
 *
 * @return toggle_pos_t
 */
static STD_RESULT get_toggle_sw8_pos(toggle_pos_t * toggle_pos)
{
    STD_RESULT result;

    buttons_state_t buttons_state = buttons_get_value(CONTROL_TOGGLE_SW8);

    if (BUTTONS_ER != buttons_state)
    {
        if (BUTTONS_ACTIVE == buttons_state)
        {
            *toggle_pos = TOGGLE_POS2;
        }
        else
        {
            *toggle_pos = TOGGLE_POS1;
        }
        result = RESULT_OK;
    }
    else
    {
        result = RESULT_NOT_OK;
    }
    return result;
}

/**
 * @brief Update input parameters of buttons
 *
 */
static STD_RESULT update_sw_buttons_input_prm(uint8_t sw_but_ch, sw1_input_prm_t * sw_input_prm, buttons_state_t * last_buttons_state_sw, uint8_t * n_cnt_trig_schmitt_sw)
{
    STD_RESULT      result = RESULT_NOT_OK;
    toggle_pos_t    toggle_pos;
    buttons_state_t buttons_state;

    sw_input_prm->R = 0;
    buttons_state   = buttons_get_value(sw_but_ch);

    if ((BUTTONS_ER != buttons_state) && (*last_buttons_state_sw != buttons_state))
    {
        if (TRIG_SCHMITT_SW_BUTTONS < *n_cnt_trig_schmitt_sw)
        {
            if ((RESULT_OK == get_toggle_sw11_pos(&toggle_pos)) && (BUTTONS_ACTIVE == buttons_state))
            {
                sw_input_prm->B.toggle_3pos = toggle_pos;

                if (RESULT_OK == get_toggle_sw8_pos(&toggle_pos))
                {
                    sw_input_prm->B.toggle_2pos = toggle_pos;

                    result = RESULT_OK;
                }
                else
                {
                    result = RESULT_NOT_OK;
                }
            }
            else
            {
                result = RESULT_NOT_OK;
            }
            *last_buttons_state_sw = buttons_state;
            *n_cnt_trig_schmitt_sw = 0;
        }
        else
        {
            (*n_cnt_trig_schmitt_sw)++;
        }
    }
    else
    {
        *n_cnt_trig_schmitt_sw = 0;
        result                 = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Update input parameters of encoder SW7
 *
 */
static STD_RESULT update_sw7_input_prm(void)
{
    STD_RESULT      result = RESULT_NOT_OK;
    int32_t         encoder_impulses;
    buttons_state_t buttons_state;
    toggle_pos_t    toggle_pos;

    encoder_impulses = encoder_get_channel_value(CONTROL_ENCODER_SW7_CH);

    buttons_state = buttons_get_value(CONTROL_BUTTON_SW7_1_CH);

    if (BUTTONS_ER != buttons_state)
    {
        if ((last_buttons_state_sw7_1 != buttons_state) && (TRIG_SCHMITT < n_cnt_trig_schmitt_sw7_1))
        {
            if (BUTTONS_ACTIVE == buttons_state)
            {
                sw7_input_prm.B.enc_button = (~sw7_input_prm.B.enc_button) & 0x1;
            }
            n_cnt_trig_schmitt_sw7_1 = 0;
            last_buttons_state_sw7_1 = buttons_state;
        }
        else
        {
            n_cnt_trig_schmitt_sw7_1++;
        }
    }

    if (ENCODER_DIR_ROTATION_NONE != ENCODER_GET_DIR_ROTATION(encoder_impulses))
    {
        sw7_input_prm.B.dir_rotation = ENCODER_GET_DIR_ROTATION(encoder_impulses);

        if (BUTTONS_ER != buttons_state)
        {
            if (RESULT_OK == get_toggle_sw11_pos(&toggle_pos))
            {
                sw7_input_prm.B.toggle_3pos = toggle_pos;

                if (RESULT_OK == get_toggle_sw8_pos(&toggle_pos))
                {
                    sw7_input_prm.B.toggle_2pos = toggle_pos;
                    result                      = RESULT_OK;
                }
                else
                {
                    result = RESULT_NOT_OK;
                }
            }
            else
            {
                result = RESULT_NOT_OK;
            }
        }
        else
        {
            result = RESULT_NOT_OK;
        }
    }
    else
    {
        result = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Update input parameters of encoder SW9
 *
 */
static STD_RESULT update_sw9_input_prm(void)
{
    STD_RESULT   result = RESULT_NOT_OK;
    int32_t      encoder_impulses;
    toggle_pos_t toggle_pos;

    sw9_input_prm.R = 0;

    encoder_impulses = encoder_get_channel_value(CONTROL_ENCODER_SW9_CH);

        table_t value;
        value = a_sw10_fsm_table[sw10_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);

    if (ENCODER_DIR_ROTATION_NONE != ENCODER_GET_DIR_ROTATION(encoder_impulses))
    {
        sw9_input_prm.B.dir_rotation = ENCODER_GET_DIR_ROTATION(encoder_impulses);

        if (RESULT_OK == get_toggle_sw11_pos(&toggle_pos))
        {
            sw9_input_prm.B.toggle_3pos = toggle_pos;

            if (RESULT_OK == get_toggle_sw8_pos(&toggle_pos))
            {
                sw9_input_prm.B.toggle_2pos = toggle_pos;

                result = RESULT_OK;
            }
            else
            {
                result = RESULT_NOT_OK;
            }
        }
        else
        {
            result = RESULT_NOT_OK;
        }
    }
    else
    {
        result = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Update input parameters of encoder SW10
 *
 */
static STD_RESULT update_sw10_input_prm(void)
{
    STD_RESULT   result = RESULT_NOT_OK;
    int32_t      encoder_impulses;
    toggle_pos_t toggle_pos;

    sw10_input_prm.R = 0;

    encoder_impulses = encoder_get_channel_value(CONTROL_ENCODER_SW10_CH);

    if (ENCODER_DIR_ROTATION_NONE != ENCODER_GET_DIR_ROTATION(encoder_impulses))
    {
        sw10_input_prm.B.dir_rotation = ENCODER_GET_DIR_ROTATION(encoder_impulses);

        if (RESULT_OK == get_toggle_sw11_pos(&toggle_pos))
        {
            sw10_input_prm.B.toggle_3pos = toggle_pos;

            if (RESULT_OK == get_toggle_sw8_pos(&toggle_pos))
            {
                sw10_input_prm.B.toggle_2pos = toggle_pos;

                result = RESULT_OK;
            }
            else
            {
                result = RESULT_NOT_OK;
            }
        }
        else
        {
            result = RESULT_NOT_OK;
        }
    }
    else
    {
        result = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Update input parameters of encoder SW12
 *
 */
static STD_RESULT update_sw12_input_prm(void)
{
    STD_RESULT      result = RESULT_NOT_OK;
    int32_t         encoder_impulses;
    buttons_state_t buttons_state;
    toggle_pos_t    toggle_pos;

    encoder_impulses = encoder_get_channel_value(CONTROL_ENCODER_SW12_CH);
    buttons_state    = buttons_get_value(CONTROL_BUTTON_SW12_1_CH);

    if ((last_buttons_state_sw12_1 != buttons_state) && (TRIG_SCHMITT < n_cnt_trig_schmitt_sw12_1))
    {
        if (BUTTONS_ACTIVE == buttons_state)
        {
            sw12_input_prm.B.enc_button = (~sw12_input_prm.B.enc_button) & 0x01;
        }
        last_buttons_state_sw12_1 = buttons_state;
        n_cnt_trig_schmitt_sw12_1 = 0;
    }
    else
    {
        n_cnt_trig_schmitt_sw12_1++;
    }

    if (ENCODER_DIR_ROTATION_NONE != ENCODER_GET_DIR_ROTATION(encoder_impulses))
    {
        sw12_input_prm.B.dir_rotation = ENCODER_GET_DIR_ROTATION(encoder_impulses);

        if (BUTTONS_ER != buttons_state)
        {

            if (RESULT_OK == get_toggle_sw11_pos(&toggle_pos))
            {
                sw12_input_prm.B.toggle_3pos = toggle_pos;

                if (RESULT_OK == get_toggle_sw8_pos(&toggle_pos))
                {
                    sw12_input_prm.B.toggle_2pos = toggle_pos;
                    result                       = RESULT_OK;
                }
                else
                {
                    result = RESULT_NOT_OK;
                }
            }
            else
            {
                result = RESULT_NOT_OK;
            }
        }
        else
        {
            result = RESULT_NOT_OK;
        }
    }
    else
    {
        result = RESULT_NOT_OK;
    }

    return result;
}

/**
 * @brief Send midi fram to USART
 *
 * @param pucbufferUartTx
 * @param size
 */
static void USARTSend(const unsigned char * pucbufferUartTx, uint16_t size)
{
#if 0
    DMA_Cmd(DMA1_Channel4, DISABLE);
    DMA_ClearFlag(DMA1_FLAG_TC4);
    DMA_SetCurrDataCounter(DMA1_Channel4, size);
    DMA_Cmd(DMA1_Channel4, ENABLE);
#endif
    for (uint16_t i = 0; i < size; i++)
    {
        USART_SendData(USART1, pucbufferUartTx[i]);
        while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TXE))
            ;
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
    table_t value;

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW1_CH, &sw1_input_prm, &last_buttons_state_sw1, &n_cnt_trig_schmitt_sw1))
    {
        value = a_sw1_fsm_table[sw1_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW2_CH, &sw2_input_prm, &last_buttons_state_sw2, &n_cnt_trig_schmitt_sw2))
    {
        value = a_sw2_fsm_table[sw2_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW3_CH, &sw3_input_prm, &last_buttons_state_sw3, &n_cnt_trig_schmitt_sw3))
    {
        value = a_sw3_fsm_table[sw3_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW4_CH, &sw4_input_prm, &last_buttons_state_sw4, &n_cnt_trig_schmitt_sw4))
    {
        value = a_sw4_fsm_table[sw4_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW5_CH, &sw5_input_prm, &last_buttons_state_sw5, &n_cnt_trig_schmitt_sw5))
    {
        value = a_sw5_fsm_table[sw5_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw_buttons_input_prm(CONTROL_BUTTON_SW6_CH, &sw6_input_prm, &last_buttons_state_sw6, &n_cnt_trig_schmitt_sw6))
    {
        value = a_sw6_fsm_table[sw6_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw7_input_prm())
    {
        value = a_sw7_fsm_table[sw7_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw9_input_prm())
    {
        value = a_sw9_fsm_table[sw9_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }

    if (RESULT_OK == update_sw10_input_prm())
    {
        value = a_sw10_fsm_table[sw10_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }
    else
    {
        DoNothing();
    }

    if (RESULT_OK == update_sw12_input_prm())
    {
        value = a_sw12_fsm_table[sw12_input_prm.R];
        create_midi_frame(value.prm.cc, value.prm.data);
        USARTSend(bufferUartTx, MIDI_SIZE_FRAME);
    }
    else
    {
        DoNothing();
    }
}

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/