/**
 * @file      control_drv_cfg.h
 *
 * @brief     Configuration for control driver
 *
 * @date      2023-02-21
 *
 */

/** \addtogroup module
 *  @{
 */

#ifndef __CONTROL_CFG_H_
#define __CONTROL_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

    /******************************************************************************
     * INCLUDES
     ******************************************************************************/

    /******************************************************************************
     * DEFINES
     ******************************************************************************/
#define CONTROL_ENCODER_SW7_VAR4_CC    (2) // Right, SW11_pos1, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR4_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR6_CC    (3) // Left, SW11_pos1, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR6_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR12_CC   (125) // Right, SW11_pos2, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR12_DATA (126)
#define CONTROL_ENCODER_SW7_VAR14_CC   (129) // Left, SW11_pos2, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR14_DATA (130)
#define CONTROL_ENCODER_SW7_VAR20_CC   (141) // Right, SW11_pos3, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR20_DATA (142)
#define CONTROL_ENCODER_SW7_VAR22_CC   (145) // Left, SW11_pos3, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW7_VAR22_DATA (146)
#define CONTROL_ENCODER_SW7_VAR5_CC    (6) // Right, SW11_pos1, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR5_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR7_CC    (7) // Left, SW11_pos1, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR7_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR13_CC   (100) // Right, SW11_pos2, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR13_DATA (65)
#define CONTROL_ENCODER_SW7_VAR15_CC   (101) // Left, SW11_pos2, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR15_DATA (65)
#define CONTROL_ENCODER_SW7_VAR21_CC   (143) // Right, SW11_pos3, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR21_DATA (144)
#define CONTROL_ENCODER_SW7_VAR23_CC   (147) // Left, SW11_pos3, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW7_VAR23_DATA (148)
#define CONTROL_ENCODER_SW7_VAR0_CC    (2) // Right, SW11_pos1, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR0_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR2_CC    (3) // Left, SW11_pos1, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR2_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR8_CC    (6) // Right, SW11_pos2, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR8_DATA  (127)
#define CONTROL_ENCODER_SW7_VAR10_CC   (6) // Left, SW11_pos2, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR10_DATA (1)
#define CONTROL_ENCODER_SW7_VAR16_CC   (120) // Right, SW11_pos3, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR16_DATA (65)
#define CONTROL_ENCODER_SW7_VAR18_CC   (120) // Left, SW11_pos3, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW7_VAR18_DATA (12)
#define CONTROL_ENCODER_SW7_VAR1_CC    (6) // Right, SW11_pos1, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR1_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR3_CC    (7) // Left, SW11_pos1, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR3_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR9_CC    (100) // Right, SW11_pos2, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR9_DATA  (65)
#define CONTROL_ENCODER_SW7_VAR11_CC   (101) // Left, SW11_pos2, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR11_DATA (65)
#define CONTROL_ENCODER_SW7_VAR17_CC   (121) // Right, SW11_pos3, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR17_DATA (65)
#define CONTROL_ENCODER_SW7_VAR19_CC   (122) // Left, SW11_pos3, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW7_VAR19_DATA (65)

#define CONTROL_ENCODER_SW12_VAR4_CC    (40) // Right, SW11_pos1, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR4_DATA  (65)
#define CONTROL_ENCODER_SW12_VAR6_CC    (41) // Left, SW11_pos1, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR6_DATA  (65)
#define CONTROL_ENCODER_SW12_VAR12_CC   (125) // Right, SW11_pos2, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR12_DATA (126)
#define CONTROL_ENCODER_SW12_VAR14_CC   (129) // Left, SW11_pos2, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR14_DATA (130)
#define CONTROL_ENCODER_SW12_VAR20_CC   (141) // Right, SW11_pos3, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR20_DATA (142)
#define CONTROL_ENCODER_SW12_VAR22_CC   (145) // Left, SW11_pos3, SW8_pos1, button_ON
#define CONTROL_ENCODER_SW12_VAR22_DATA (146)
#define CONTROL_ENCODER_SW12_VAR5_CC    (111) // Right, SW11_pos1, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR5_DATA  (112)
#define CONTROL_ENCODER_SW12_VAR7_CC    (115) // Left, SW11_pos1, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR7_DATA  (116)
#define CONTROL_ENCODER_SW12_VAR13_CC   (127) // Right, SW11_pos2, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR13_DATA (128)
#define CONTROL_ENCODER_SW12_VAR15_CC   (114) // Left, SW11_pos2, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR15_DATA (12)
#define CONTROL_ENCODER_SW12_VAR21_CC   (13) // Right, SW11_pos3, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR21_DATA (14)
#define CONTROL_ENCODER_SW12_VAR23_CC   (117) // Left, SW11_pos3, SW8_pos2, button_ON
#define CONTROL_ENCODER_SW12_VAR23_DATA (18)
#define CONTROL_ENCODER_SW12_VAR0_CC    (40) // Right, SW11_pos1, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR0_DATA  (65)
#define CONTROL_ENCODER_SW12_VAR2_CC    (41) // Left, SW11_pos1, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR2_DATA  (65)
#define CONTROL_ENCODER_SW12_VAR8_CC    (117) // Right, SW11_pos2, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR8_DATA  (118)
#define CONTROL_ENCODER_SW12_VAR10_CC   (121) // Left, SW11_pos2, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR10_DATA (122)
#define CONTROL_ENCODER_SW12_VAR16_CC   (91) // Right, SW11_pos3, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR16_DATA (65)
#define CONTROL_ENCODER_SW12_VAR18_CC   (92) // Left, SW11_pos3, SW8_pos1, button_OFF
#define CONTROL_ENCODER_SW12_VAR18_DATA (65)
#define CONTROL_ENCODER_SW12_VAR1_CC    (103) // Right, SW11_pos1, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR1_DATA  (104)
#define CONTROL_ENCODER_SW12_VAR3_CC    (107) // Left, SW11_pos1, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR3_DATA  (108)
#define CONTROL_ENCODER_SW12_VAR9_CC    (119) // Right, SW11_pos2, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR9_DATA  (120)
#define CONTROL_ENCODER_SW12_VAR11_CC   (123) // Left, SW11_pos2, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR11_DATA (124)
#define CONTROL_ENCODER_SW12_VAR17_CC   (135) // Right, SW11_pos3, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR17_DATA (136)
#define CONTROL_ENCODER_SW12_VAR19_CC   (139) // Left, SW11_pos3, SW8_pos2, button_OFF
#define CONTROL_ENCODER_SW12_VAR19_DATA (140)

#define CONTROL_ENCODER_SW9_VAR0_CC    (126) // Right, SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR0_DATA  (65)
#define CONTROL_ENCODER_SW9_VAR2_CC    (126) // Left, SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR2_DATA  (65)
#define CONTROL_ENCODER_SW9_VAR4_CC    (38) // Right, SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR4_DATA  (39)
#define CONTROL_ENCODER_SW9_VAR6_CC    (42) // Left, SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR6_DATA  (43)
#define CONTROL_ENCODER_SW9_VAR8_CC    (46) // Right, SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR8_DATA  (47)
#define CONTROL_ENCODER_SW9_VAR10_CC   (50) // Left, SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW9_VAR10_DATA (51)
#define CONTROL_ENCODER_SW9_VAR1_CC    (32) // Right, SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR1_DATA  (33)
#define CONTROL_ENCODER_SW9_VAR3_CC    (36) // Left, SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR3_DATA  (37)
#define CONTROL_ENCODER_SW9_VAR5_CC    (40) // Right, SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR5_DATA  (41)
#define CONTROL_ENCODER_SW9_VAR7_CC    (44) // Left, SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR7_DATA  (45)
#define CONTROL_ENCODER_SW9_VAR9_CC    (48) // Right, SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR9_DATA  (49)
#define CONTROL_ENCODER_SW9_VAR11_CC   (53) // Left, SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW9_VAR11_DATA (53)

#define CONTROL_ENCODER_SW10_VAR0_CC    (32) // Right, SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR0_DATA  (65)
#define CONTROL_ENCODER_SW10_VAR2_CC    (33) // Left, SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR2_DATA  (65)
#define CONTROL_ENCODER_SW10_VAR4_CC    (38) // Right, SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR4_DATA  (39)
#define CONTROL_ENCODER_SW10_VAR6_CC    (42) // Left, SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR6_DATA  (43)
#define CONTROL_ENCODER_SW10_VAR8_CC    (46) // Right, SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR8_DATA  (47)
#define CONTROL_ENCODER_SW10_VAR10_CC   (50) // Left, SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW10_VAR10_DATA (51)
#define CONTROL_ENCODER_SW10_VAR1_CC    (32) // Right, SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR1_DATA  (33)
#define CONTROL_ENCODER_SW10_VAR3_CC    (36) // Left, SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR3_DATA  (37)
#define CONTROL_ENCODER_SW10_VAR5_CC    (40) // Right, SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR5_DATA  (41)
#define CONTROL_ENCODER_SW10_VAR7_CC    (44) // Left, SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR7_DATA  (45)
#define CONTROL_ENCODER_SW10_VAR9_CC    (48) // Right, SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR9_DATA  (49)
#define CONTROL_ENCODER_SW10_VAR11_CC   (50) // Left, SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW10_VAR11_DATA (53)

#define CONTROL_ENCODER_SW1_VAR0_CC   (10) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW1_VAR0_DATA (20)
#define CONTROL_ENCODER_SW1_VAR1_CC   (10) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW1_VAR1_DATA (20)
#define CONTROL_ENCODER_SW1_VAR2_CC   (10) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW1_VAR2_DATA (20)
#define CONTROL_ENCODER_SW1_VAR3_CC   (10) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW1_VAR3_DATA (20)
#define CONTROL_ENCODER_SW1_VAR4_CC   (10) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW1_VAR4_DATA (20)
#define CONTROL_ENCODER_SW1_VAR5_CC   (10) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW1_VAR5_DATA (20)

#define CONTROL_ENCODER_SW2_VAR0_CC   (10) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW2_VAR0_DATA (20)
#define CONTROL_ENCODER_SW2_VAR1_CC   (10) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW2_VAR1_DATA (20)
#define CONTROL_ENCODER_SW2_VAR2_CC   (10) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW2_VAR2_DATA (20)
#define CONTROL_ENCODER_SW2_VAR3_CC   (10) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW2_VAR3_DATA (20)
#define CONTROL_ENCODER_SW2_VAR4_CC   (10) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW2_VAR4_DATA (20)
#define CONTROL_ENCODER_SW2_VAR5_CC   (10) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW2_VAR5_DATA (20)

#define CONTROL_ENCODER_SW3_VAR0_CC   (10) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW3_VAR0_DATA (20)
#define CONTROL_ENCODER_SW3_VAR1_CC   (10) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW3_VAR1_DATA (20)
#define CONTROL_ENCODER_SW3_VAR2_CC   (10) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW3_VAR2_DATA (20)
#define CONTROL_ENCODER_SW3_VAR3_CC   (10) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW3_VAR3_DATA (20)
#define CONTROL_ENCODER_SW3_VAR4_CC   (10) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW3_VAR4_DATA (20)
#define CONTROL_ENCODER_SW3_VAR5_CC   (10) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW3_VAR5_DATA (20)

#define CONTROL_ENCODER_SW4_VAR0_CC   (80) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW4_VAR0_DATA (65)
#define CONTROL_ENCODER_SW4_VAR1_CC   (80) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW4_VAR1_DATA (65)
#define CONTROL_ENCODER_SW4_VAR2_CC   (10) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW4_VAR2_DATA (20)
#define CONTROL_ENCODER_SW4_VAR3_CC   (10) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW4_VAR3_DATA (20)
#define CONTROL_ENCODER_SW4_VAR4_CC   (10) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW4_VAR4_DATA (20)
#define CONTROL_ENCODER_SW4_VAR5_CC   (10) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW4_VAR5_DATA (20)

#define CONTROL_ENCODER_SW5_VAR0_CC   (81) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW5_VAR0_DATA (65)
#define CONTROL_ENCODER_SW5_VAR1_CC   (81) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW5_VAR1_DATA (65)
#define CONTROL_ENCODER_SW5_VAR2_CC   (10) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW5_VAR2_DATA (20)
#define CONTROL_ENCODER_SW5_VAR3_CC   (10) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW5_VAR3_DATA (20)
#define CONTROL_ENCODER_SW5_VAR4_CC   (10) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW5_VAR4_DATA (20)
#define CONTROL_ENCODER_SW5_VAR5_CC   (10) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW5_VAR5_DATA (20)

#define CONTROL_ENCODER_SW6_VAR0_CC   (82) // SW11_pos1, SW8_pos1
#define CONTROL_ENCODER_SW6_VAR0_DATA (65)
#define CONTROL_ENCODER_SW6_VAR1_CC   (82) // SW11_pos1, SW8_pos2
#define CONTROL_ENCODER_SW6_VAR1_DATA (65)
#define CONTROL_ENCODER_SW6_VAR2_CC   (15) // SW11_pos2, SW8_pos1
#define CONTROL_ENCODER_SW6_VAR2_DATA (16)
#define CONTROL_ENCODER_SW6_VAR3_CC   (17) // SW11_pos2, SW8_pos2
#define CONTROL_ENCODER_SW6_VAR3_DATA (18)
#define CONTROL_ENCODER_SW6_VAR4_CC   (19) // SW11_pos3, SW8_pos1
#define CONTROL_ENCODER_SW6_VAR4_DATA (20)
#define CONTROL_ENCODER_SW6_VAR5_CC   (21) // SW11_pos3, SW8_pos2
#define CONTROL_ENCODER_SW6_VAR5_DATA (22)

#define CONTROL_ENCODER_SW7_CH   (ENCODER_CH_0)
#define CONTROL_ENCODER_SW9_CH   (ENCODER_CH_1)
#define CONTROL_ENCODER_SW10_CH  (ENCODER_CH_2)
#define CONTROL_ENCODER_SW12_CH  (ENCODER_CH_3)
#define CONTROL_BUTTON_SW7_1_CH  (BUTTONS_CH6)
#define CONTROL_BUTTON_SW1_CH    (BUTTONS_CH0)
#define CONTROL_BUTTON_SW2_CH    (BUTTONS_CH1)
#define CONTROL_BUTTON_SW3_CH    (BUTTONS_CH2)
#define CONTROL_BUTTON_SW4_CH    (BUTTONS_CH3)
#define CONTROL_BUTTON_SW5_CH    (BUTTONS_CH4)
#define CONTROL_BUTTON_SW6_CH    (BUTTONS_CH5)
#define CONTROL_BUTTON_SW12_1_CH (BUTTONS_CH7)
#define CONTROL_TOGGLE_SW11_1    (BUTTONS_CH9)
#define CONTROL_TOGGLE_SW11_2    (BUTTONS_CH10)
#define CONTROL_TOGGLE_SW8       (BUTTONS_CH8)

/******************************************************************************
 * PUBLIC TYPES
 ******************************************************************************/

/******************************************************************************
 * INLINE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * END OF HEADER'S CODE
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // __CONTROL_CFG_H_

/** @}*/