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

// Default configs
#define CONTROL_ENCODER_SW7_VAR0_CC   (0) // Right, SW11_pos1, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR0_DATA (0)
#define CONTROL_ENCODER_SW7_VAR1_CC   (1) // Left, SW11_pos1, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR1_DATA (1)
#define CONTROL_ENCODER_SW7_VAR2_CC   (2) // Right, SW11_pos1, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR2_DATA (2)
#define CONTROL_ENCODER_SW7_VAR3_CC   (3) // Left, SW11_pos1, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR3_DATA (3)
#define CONTROL_ENCODER_SW7_VAR4_CC   (4) // Right, SW11_pos1, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR4_DATA (4)
#define CONTROL_ENCODER_SW7_VAR5_CC   (5) // Left, SW11_pos1, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR5_DATA (5)
#define CONTROL_ENCODER_SW7_VAR6_CC   (6) // Right, SW11_pos1, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR6_DATA (6)
#define CONTROL_ENCODER_SW7_VAR7_CC   (7) // Left, SW11_pos1, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR7_DATA (7)
#define CONTROL_ENCODER_SW7_VAR8_CC   (8) // Right, SW11_pos1, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR8_DATA (8)
#define CONTROL_ENCODER_SW7_VAR9_CC   (9) // Left, SW11_pos1, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR9_DATA (9)
#define CONTROL_ENCODER_SW7_VAR10_CC   (10) // Right, SW11_pos1, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR10_DATA (10)
#define CONTROL_ENCODER_SW7_VAR11_CC   (11) // Left, SW11_pos1, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR11_DATA (11)
#define CONTROL_ENCODER_SW7_VAR12_CC   (12) // Right, SW11_pos1, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR12_DATA (12)
#define CONTROL_ENCODER_SW7_VAR13_CC   (13) // Left, SW11_pos1, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR13_DATA (13)
#define CONTROL_ENCODER_SW7_VAR14_CC   (14) // Right, SW11_pos1, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR14_DATA (14)
#define CONTROL_ENCODER_SW7_VAR15_CC   (15) // Left, SW11_pos1, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR15_DATA (15)
#define CONTROL_ENCODER_SW7_VAR16_CC   (16) // Right, SW11_pos2, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR16_DATA (16)
#define CONTROL_ENCODER_SW7_VAR17_CC   (17) // Left, SW11_pos2, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR17_DATA (17)
#define CONTROL_ENCODER_SW7_VAR18_CC   (18) // Right, SW11_pos2, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR18_DATA (18)
#define CONTROL_ENCODER_SW7_VAR19_CC   (19) // Left, SW11_pos2, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR19_DATA (19)
#define CONTROL_ENCODER_SW7_VAR20_CC   (20) // Right, SW11_pos2, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR20_DATA (20)
#define CONTROL_ENCODER_SW7_VAR21_CC   (21) // Left, SW11_pos2, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR21_DATA (21)
#define CONTROL_ENCODER_SW7_VAR22_CC   (22) // Right, SW11_pos2, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR22_DATA (22)
#define CONTROL_ENCODER_SW7_VAR23_CC   (23) // Left, SW11_pos2, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR23_DATA (23)
#define CONTROL_ENCODER_SW7_VAR24_CC   (24) // Right, SW11_pos2, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR24_DATA (24)
#define CONTROL_ENCODER_SW7_VAR25_CC   (25) // Left, SW11_pos2, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR25_DATA (25)
#define CONTROL_ENCODER_SW7_VAR26_CC   (26) // Right, SW11_pos2, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR26_DATA (26)
#define CONTROL_ENCODER_SW7_VAR27_CC   (27) // Left, SW11_pos2, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR27_DATA (27)
#define CONTROL_ENCODER_SW7_VAR28_CC   (28) // Right, SW11_pos2, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR28_DATA (28)
#define CONTROL_ENCODER_SW7_VAR29_CC   (29) // Left, SW11_pos2, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR29_DATA (29)
#define CONTROL_ENCODER_SW7_VAR30_CC   (30) // Right, SW11_pos2, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR30_DATA (30)
#define CONTROL_ENCODER_SW7_VAR31_CC   (31) // Left, SW11_pos2, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR31_DATA (31)
#define CONTROL_ENCODER_SW7_VAR32_CC   (32) // Right, SW11_pos3, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR32_DATA (32)
#define CONTROL_ENCODER_SW7_VAR33_CC   (33) // Left, SW11_pos3, SW8_pos1, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR33_DATA (33)
#define CONTROL_ENCODER_SW7_VAR34_CC   (34) // Right, SW11_pos3, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR34_DATA (34)
#define CONTROL_ENCODER_SW7_VAR35_CC   (35) // Left, SW11_pos3, SW8_pos2, button_B_OFF, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR35_DATA (35)
#define CONTROL_ENCODER_SW7_VAR36_CC   (36) // Right, SW11_pos3, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR36_DATA (36)
#define CONTROL_ENCODER_SW7_VAR37_CC   (37) // Left, SW11_pos3, SW8_pos1, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR37_DATA (37)
#define CONTROL_ENCODER_SW7_VAR38_CC   (38) // Right, SW11_pos3, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR38_DATA (38)
#define CONTROL_ENCODER_SW7_VAR39_CC   (39) // Left, SW11_pos3, SW8_pos2, button_B_OFF, button_A_ON
#define CONTROL_ENCODER_SW7_VAR39_DATA (39)
#define CONTROL_ENCODER_SW7_VAR40_CC   (40) // Right, SW11_pos3, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR40_DATA (40)
#define CONTROL_ENCODER_SW7_VAR41_CC   (41) // Left, SW11_pos3, SW8_pos1, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR41_DATA (41)
#define CONTROL_ENCODER_SW7_VAR42_CC   (42) // Right, SW11_pos3, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR42_DATA (42)
#define CONTROL_ENCODER_SW7_VAR43_CC   (43) // Left, SW11_pos3, SW8_pos2, button_B_ON, button_A_OFF
#define CONTROL_ENCODER_SW7_VAR43_DATA (43)
#define CONTROL_ENCODER_SW7_VAR44_CC   (44) // Right, SW11_pos3, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR44_DATA (44)
#define CONTROL_ENCODER_SW7_VAR45_CC   (45) // Left, SW11_pos3, SW8_pos1, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR45_DATA (45)
#define CONTROL_ENCODER_SW7_VAR46_CC   (46) // Right, SW11_pos3, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR46_DATA (46)
#define CONTROL_ENCODER_SW7_VAR47_CC   (47) // Left, SW11_pos3, SW8_pos2, button_B_ON, button_A_ON
#define CONTROL_ENCODER_SW7_VAR47_DATA (47)

#define CONTROL_ENCODER_SW9_VAR0_CC   (0) // Right, SW11_pos1, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR0_DATA (0)
#define CONTROL_ENCODER_SW9_VAR1_CC   (1) // Left, SW11_pos1, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR1_DATA (1)
#define CONTROL_ENCODER_SW9_VAR2_CC   (2) // Right, SW11_pos1, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR2_DATA (2)
#define CONTROL_ENCODER_SW9_VAR3_CC   (3) // Left, SW11_pos1, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR3_DATA (3)
#define CONTROL_ENCODER_SW9_VAR4_CC   (4) // Right, SW11_pos1, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR4_DATA (4)
#define CONTROL_ENCODER_SW9_VAR5_CC   (5) // Left, SW11_pos1, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR5_DATA (5)
#define CONTROL_ENCODER_SW9_VAR6_CC   (6) // Right, SW11_pos1, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR6_DATA (6)
#define CONTROL_ENCODER_SW9_VAR7_CC   (7) // Left, SW11_pos1, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR7_DATA (7)
#define CONTROL_ENCODER_SW9_VAR8_CC   (8) // Right, SW11_pos1, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR8_DATA (8)
#define CONTROL_ENCODER_SW9_VAR9_CC   (9) // Left, SW11_pos1, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR9_DATA (9)
#define CONTROL_ENCODER_SW9_VAR10_CC   (10) // Right, SW11_pos1, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR10_DATA (10)
#define CONTROL_ENCODER_SW9_VAR11_CC   (11) // Left, SW11_pos1, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR11_DATA (11)
#define CONTROL_ENCODER_SW9_VAR12_CC   (12) // Right, SW11_pos1, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR12_DATA (12)
#define CONTROL_ENCODER_SW9_VAR13_CC   (13) // Left, SW11_pos1, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR13_DATA (13)
#define CONTROL_ENCODER_SW9_VAR14_CC   (14) // Right, SW11_pos1, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR14_DATA (14)
#define CONTROL_ENCODER_SW9_VAR15_CC   (15) // Left, SW11_pos1, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR15_DATA (15)
#define CONTROL_ENCODER_SW9_VAR16_CC   (16) // Right, SW11_pos2, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR16_DATA (16)
#define CONTROL_ENCODER_SW9_VAR17_CC   (17) // Left, SW11_pos2, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR17_DATA (17)
#define CONTROL_ENCODER_SW9_VAR18_CC   (18) // Right, SW11_pos2, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR18_DATA (18)
#define CONTROL_ENCODER_SW9_VAR19_CC   (19) // Left, SW11_pos2, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR19_DATA (19)
#define CONTROL_ENCODER_SW9_VAR20_CC   (20) // Right, SW11_pos2, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR20_DATA (20)
#define CONTROL_ENCODER_SW9_VAR21_CC   (21) // Left, SW11_pos2, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR21_DATA (21)
#define CONTROL_ENCODER_SW9_VAR22_CC   (22) // Right, SW11_pos2, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR22_DATA (22)
#define CONTROL_ENCODER_SW9_VAR23_CC   (23) // Left, SW11_pos2, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR23_DATA (23)
#define CONTROL_ENCODER_SW9_VAR24_CC   (24) // Right, SW11_pos2, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR24_DATA (24)
#define CONTROL_ENCODER_SW9_VAR25_CC   (25) // Left, SW11_pos2, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR25_DATA (25)
#define CONTROL_ENCODER_SW9_VAR26_CC   (26) // Right, SW11_pos2, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR26_DATA (26)
#define CONTROL_ENCODER_SW9_VAR27_CC   (27) // Left, SW11_pos2, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR27_DATA (27)
#define CONTROL_ENCODER_SW9_VAR28_CC   (28) // Right, SW11_pos2, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR28_DATA (28)
#define CONTROL_ENCODER_SW9_VAR29_CC   (29) // Left, SW11_pos2, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR29_DATA (29)
#define CONTROL_ENCODER_SW9_VAR30_CC   (30) // Right, SW11_pos2, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR30_DATA (30)
#define CONTROL_ENCODER_SW9_VAR31_CC   (31) // Left, SW11_pos2, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR31_DATA (31)
#define CONTROL_ENCODER_SW9_VAR32_CC   (32) // Right, SW11_pos3, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR32_DATA (32)
#define CONTROL_ENCODER_SW9_VAR33_CC   (33) // Left, SW11_pos3, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR33_DATA (33)
#define CONTROL_ENCODER_SW9_VAR34_CC   (34) // Right, SW11_pos3, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR34_DATA (34)
#define CONTROL_ENCODER_SW9_VAR35_CC   (35) // Left, SW11_pos3, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW9_VAR35_DATA (35)
#define CONTROL_ENCODER_SW9_VAR36_CC   (36) // Right, SW11_pos3, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR36_DATA (36)
#define CONTROL_ENCODER_SW9_VAR37_CC   (37) // Left, SW11_pos3, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR37_DATA (37)
#define CONTROL_ENCODER_SW9_VAR38_CC   (38) // Right, SW11_pos3, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR38_DATA (38)
#define CONTROL_ENCODER_SW9_VAR39_CC   (39) // Left, SW11_pos3, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW9_VAR39_DATA (39)
#define CONTROL_ENCODER_SW9_VAR40_CC   (40) // Right, SW11_pos3, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR40_DATA (40)
#define CONTROL_ENCODER_SW9_VAR41_CC   (41) // Left, SW11_pos3, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR41_DATA (41)
#define CONTROL_ENCODER_SW9_VAR42_CC   (42) // Right, SW11_pos3, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR42_DATA (42)
#define CONTROL_ENCODER_SW9_VAR43_CC   (43) // Left, SW11_pos3, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW9_VAR43_DATA (43)
#define CONTROL_ENCODER_SW9_VAR44_CC   (44) // Right, SW11_pos3, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR44_DATA (44)
#define CONTROL_ENCODER_SW9_VAR45_CC   (45) // Left, SW11_pos3, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR45_DATA (45)
#define CONTROL_ENCODER_SW9_VAR46_CC   (46) // Right, SW11_pos3, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR46_DATA (46)
#define CONTROL_ENCODER_SW9_VAR47_CC   (47) // Left, SW11_pos3, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW9_VAR47_DATA (47)

#define CONTROL_ENCODER_SW10_VAR0_CC   (0) // Right, SW11_pos1, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR0_DATA (0)
#define CONTROL_ENCODER_SW10_VAR1_CC   (1) // Left, SW11_pos1, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR1_DATA (1)
#define CONTROL_ENCODER_SW10_VAR2_CC   (2) // Right, SW11_pos1, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR2_DATA (2)
#define CONTROL_ENCODER_SW10_VAR3_CC   (3) // Left, SW11_pos1, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR3_DATA (3)
#define CONTROL_ENCODER_SW10_VAR4_CC   (4) // Right, SW11_pos1, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR4_DATA (4)
#define CONTROL_ENCODER_SW10_VAR5_CC   (5) // Left, SW11_pos1, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR5_DATA (5)
#define CONTROL_ENCODER_SW10_VAR6_CC   (6) // Right, SW11_pos1, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR6_DATA (6)
#define CONTROL_ENCODER_SW10_VAR7_CC   (7) // Left, SW11_pos1, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR7_DATA (7)
#define CONTROL_ENCODER_SW10_VAR8_CC   (8) // Right, SW11_pos1, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR8_DATA (8)
#define CONTROL_ENCODER_SW10_VAR9_CC   (9) // Left, SW11_pos1, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR9_DATA (9)
#define CONTROL_ENCODER_SW10_VAR10_CC   (10) // Right, SW11_pos1, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR10_DATA (10)
#define CONTROL_ENCODER_SW10_VAR11_CC   (11) // Left, SW11_pos1, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR11_DATA (11)
#define CONTROL_ENCODER_SW10_VAR12_CC   (12) // Right, SW11_pos1, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR12_DATA (12)
#define CONTROL_ENCODER_SW10_VAR13_CC   (13) // Left, SW11_pos1, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR13_DATA (13)
#define CONTROL_ENCODER_SW10_VAR14_CC   (14) // Right, SW11_pos1, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR14_DATA (14)
#define CONTROL_ENCODER_SW10_VAR15_CC   (15) // Left, SW11_pos1, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR15_DATA (15)
#define CONTROL_ENCODER_SW10_VAR16_CC   (16) // Right, SW11_pos2, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR16_DATA (16)
#define CONTROL_ENCODER_SW10_VAR17_CC   (17) // Left, SW11_pos2, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR17_DATA (17)
#define CONTROL_ENCODER_SW10_VAR18_CC   (18) // Right, SW11_pos2, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR18_DATA (18)
#define CONTROL_ENCODER_SW10_VAR19_CC   (19) // Left, SW11_pos2, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR19_DATA (19)
#define CONTROL_ENCODER_SW10_VAR20_CC   (20) // Right, SW11_pos2, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR20_DATA (20)
#define CONTROL_ENCODER_SW10_VAR21_CC   (21) // Left, SW11_pos2, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR21_DATA (21)
#define CONTROL_ENCODER_SW10_VAR22_CC   (22) // Right, SW11_pos2, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR22_DATA (22)
#define CONTROL_ENCODER_SW10_VAR23_CC   (23) // Left, SW11_pos2, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR23_DATA (23)
#define CONTROL_ENCODER_SW10_VAR24_CC   (24) // Right, SW11_pos2, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR24_DATA (24)
#define CONTROL_ENCODER_SW10_VAR25_CC   (25) // Left, SW11_pos2, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR25_DATA (25)
#define CONTROL_ENCODER_SW10_VAR26_CC   (26) // Right, SW11_pos2, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR26_DATA (26)
#define CONTROL_ENCODER_SW10_VAR27_CC   (27) // Left, SW11_pos2, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR27_DATA (27)
#define CONTROL_ENCODER_SW10_VAR28_CC   (28) // Right, SW11_pos2, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR28_DATA (28)
#define CONTROL_ENCODER_SW10_VAR29_CC   (29) // Left, SW11_pos2, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR29_DATA (29)
#define CONTROL_ENCODER_SW10_VAR30_CC   (30) // Right, SW11_pos2, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR30_DATA (30)
#define CONTROL_ENCODER_SW10_VAR31_CC   (31) // Left, SW11_pos2, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR31_DATA (31)
#define CONTROL_ENCODER_SW10_VAR32_CC   (32) // Right, SW11_pos3, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR32_DATA (32)
#define CONTROL_ENCODER_SW10_VAR33_CC   (33) // Left, SW11_pos3, SW8_pos1, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR33_DATA (33)
#define CONTROL_ENCODER_SW10_VAR34_CC   (34) // Right, SW11_pos3, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR34_DATA (34)
#define CONTROL_ENCODER_SW10_VAR35_CC   (35) // Left, SW11_pos3, SW8_pos2, button_OFF, button_OFF
#define CONTROL_ENCODER_SW10_VAR35_DATA (35)
#define CONTROL_ENCODER_SW10_VAR36_CC   (36) // Right, SW11_pos3, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR36_DATA (36)
#define CONTROL_ENCODER_SW10_VAR37_CC   (37) // Left, SW11_pos3, SW8_pos1, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR37_DATA (37)
#define CONTROL_ENCODER_SW10_VAR38_CC   (38) // Right, SW11_pos3, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR38_DATA (38)
#define CONTROL_ENCODER_SW10_VAR39_CC   (39) // Left, SW11_pos3, SW8_pos2, button_OFF, button_ON
#define CONTROL_ENCODER_SW10_VAR39_DATA (39)
#define CONTROL_ENCODER_SW10_VAR40_CC   (40) // Right, SW11_pos3, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR40_DATA (40)
#define CONTROL_ENCODER_SW10_VAR41_CC   (41) // Left, SW11_pos3, SW8_pos1, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR41_DATA (41)
#define CONTROL_ENCODER_SW10_VAR42_CC   (42) // Right, SW11_pos3, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR42_DATA (42)
#define CONTROL_ENCODER_SW10_VAR43_CC   (43) // Left, SW11_pos3, SW8_pos2, button_ON, button_OFF
#define CONTROL_ENCODER_SW10_VAR43_DATA (43)
#define CONTROL_ENCODER_SW10_VAR44_CC   (44) // Right, SW11_pos3, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR44_DATA (44)
#define CONTROL_ENCODER_SW10_VAR45_CC   (45) // Left, SW11_pos3, SW8_pos1, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR45_DATA (45)
#define CONTROL_ENCODER_SW10_VAR46_CC   (46) // Right, SW11_pos3, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR46_DATA (46)
#define CONTROL_ENCODER_SW10_VAR47_CC   (47) // Left, SW11_pos3, SW8_pos2, button_ON, button_ON
#define CONTROL_ENCODER_SW10_VAR47_DATA (47)

#define CONTROL_ENCODER_SW1_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR0_DATA (0)
#define CONTROL_ENCODER_SW1_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR1_DATA (1)
#define CONTROL_ENCODER_SW1_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR2_DATA (2)
#define CONTROL_ENCODER_SW1_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR3_DATA (3)
#define CONTROL_ENCODER_SW1_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR4_DATA (4)
#define CONTROL_ENCODER_SW1_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR5_DATA (5)
#define CONTROL_ENCODER_SW1_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR6_DATA (6)
#define CONTROL_ENCODER_SW1_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR7_DATA (7)
#define CONTROL_ENCODER_SW1_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR8_DATA (8)
#define CONTROL_ENCODER_SW1_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR9_DATA (9)
#define CONTROL_ENCODER_SW1_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR10_DATA (10)
#define CONTROL_ENCODER_SW1_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR11_DATA (11)
#define CONTROL_ENCODER_SW1_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR12_DATA (12)
#define CONTROL_ENCODER_SW1_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR13_DATA (13)
#define CONTROL_ENCODER_SW1_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR14_DATA (14)
#define CONTROL_ENCODER_SW1_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR15_DATA (15)
#define CONTROL_ENCODER_SW1_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR16_DATA (16)
#define CONTROL_ENCODER_SW1_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR17_DATA (17)
#define CONTROL_ENCODER_SW1_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR18_DATA (18)
#define CONTROL_ENCODER_SW1_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR19_DATA (19)
#define CONTROL_ENCODER_SW1_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW1_VAR20_DATA (20)
#define CONTROL_ENCODER_SW1_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW1_VAR21_DATA (21)
#define CONTROL_ENCODER_SW1_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW1_VAR22_DATA (22)
#define CONTROL_ENCODER_SW1_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW1_VAR23_DATA (23)

#define CONTROL_ENCODER_SW2_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR0_DATA (0)
#define CONTROL_ENCODER_SW2_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR1_DATA (1)
#define CONTROL_ENCODER_SW2_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR2_DATA (2)
#define CONTROL_ENCODER_SW2_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR3_DATA (3)
#define CONTROL_ENCODER_SW2_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR4_DATA (4)
#define CONTROL_ENCODER_SW2_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR5_DATA (5)
#define CONTROL_ENCODER_SW2_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR6_DATA (6)
#define CONTROL_ENCODER_SW2_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR7_DATA (7)
#define CONTROL_ENCODER_SW2_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR8_DATA (8)
#define CONTROL_ENCODER_SW2_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR9_DATA (9)
#define CONTROL_ENCODER_SW2_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR10_DATA (10)
#define CONTROL_ENCODER_SW2_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR11_DATA (11)
#define CONTROL_ENCODER_SW2_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR12_DATA (12)
#define CONTROL_ENCODER_SW2_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR13_DATA (13)
#define CONTROL_ENCODER_SW2_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR14_DATA (14)
#define CONTROL_ENCODER_SW2_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR15_DATA (15)
#define CONTROL_ENCODER_SW2_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR16_DATA (16)
#define CONTROL_ENCODER_SW2_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR17_DATA (17)
#define CONTROL_ENCODER_SW2_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR18_DATA (18)
#define CONTROL_ENCODER_SW2_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR19_DATA (19)
#define CONTROL_ENCODER_SW2_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW2_VAR20_DATA (20)
#define CONTROL_ENCODER_SW2_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW2_VAR21_DATA (21)
#define CONTROL_ENCODER_SW2_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW2_VAR22_DATA (22)
#define CONTROL_ENCODER_SW2_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW2_VAR23_DATA (23)

#define CONTROL_ENCODER_SW3_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR0_DATA (0)
#define CONTROL_ENCODER_SW3_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR1_DATA (1)
#define CONTROL_ENCODER_SW3_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR2_DATA (2)
#define CONTROL_ENCODER_SW3_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR3_DATA (3)
#define CONTROL_ENCODER_SW3_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR4_DATA (4)
#define CONTROL_ENCODER_SW3_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR5_DATA (5)
#define CONTROL_ENCODER_SW3_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR6_DATA (6)
#define CONTROL_ENCODER_SW3_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR7_DATA (7)
#define CONTROL_ENCODER_SW3_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR8_DATA (8)
#define CONTROL_ENCODER_SW3_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR9_DATA (9)
#define CONTROL_ENCODER_SW3_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR10_DATA (10)
#define CONTROL_ENCODER_SW3_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR11_DATA (11)
#define CONTROL_ENCODER_SW3_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR12_DATA (12)
#define CONTROL_ENCODER_SW3_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR13_DATA (13)
#define CONTROL_ENCODER_SW3_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR14_DATA (14)
#define CONTROL_ENCODER_SW3_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR15_DATA (15)
#define CONTROL_ENCODER_SW3_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR16_DATA (16)
#define CONTROL_ENCODER_SW3_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR17_DATA (17)
#define CONTROL_ENCODER_SW3_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR18_DATA (18)
#define CONTROL_ENCODER_SW3_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR19_DATA (19)
#define CONTROL_ENCODER_SW3_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW3_VAR20_DATA (20)
#define CONTROL_ENCODER_SW3_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW3_VAR21_DATA (21)
#define CONTROL_ENCODER_SW3_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW3_VAR22_DATA (22)
#define CONTROL_ENCODER_SW3_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW3_VAR23_DATA (23)

#define CONTROL_ENCODER_SW4_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR0_DATA (0)
#define CONTROL_ENCODER_SW4_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR1_DATA (1)
#define CONTROL_ENCODER_SW4_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR2_DATA (2)
#define CONTROL_ENCODER_SW4_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR3_DATA (3)
#define CONTROL_ENCODER_SW4_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR4_DATA (4)
#define CONTROL_ENCODER_SW4_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR5_DATA (5)
#define CONTROL_ENCODER_SW4_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR6_DATA (6)
#define CONTROL_ENCODER_SW4_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR7_DATA (7)
#define CONTROL_ENCODER_SW4_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR8_DATA (8)
#define CONTROL_ENCODER_SW4_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR9_DATA (9)
#define CONTROL_ENCODER_SW4_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR10_DATA (10)
#define CONTROL_ENCODER_SW4_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR11_DATA (11)
#define CONTROL_ENCODER_SW4_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR12_DATA (12)
#define CONTROL_ENCODER_SW4_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR13_DATA (13)
#define CONTROL_ENCODER_SW4_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR14_DATA (14)
#define CONTROL_ENCODER_SW4_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR15_DATA (15)
#define CONTROL_ENCODER_SW4_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR16_DATA (16)
#define CONTROL_ENCODER_SW4_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR17_DATA (17)
#define CONTROL_ENCODER_SW4_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR18_DATA (18)
#define CONTROL_ENCODER_SW4_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR19_DATA (19)
#define CONTROL_ENCODER_SW4_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW4_VAR20_DATA (20)
#define CONTROL_ENCODER_SW4_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW4_VAR21_DATA (21)
#define CONTROL_ENCODER_SW4_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW4_VAR22_DATA (22)
#define CONTROL_ENCODER_SW4_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW4_VAR23_DATA (23)

#define CONTROL_ENCODER_SW5_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR0_DATA (0)
#define CONTROL_ENCODER_SW5_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR1_DATA (1)
#define CONTROL_ENCODER_SW5_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR2_DATA (2)
#define CONTROL_ENCODER_SW5_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR3_DATA (3)
#define CONTROL_ENCODER_SW5_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR4_DATA (4)
#define CONTROL_ENCODER_SW5_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR5_DATA (5)
#define CONTROL_ENCODER_SW5_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR6_DATA (6)
#define CONTROL_ENCODER_SW5_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR7_DATA (7)
#define CONTROL_ENCODER_SW5_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR8_DATA (8)
#define CONTROL_ENCODER_SW5_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR9_DATA (9)
#define CONTROL_ENCODER_SW5_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR10_DATA (10)
#define CONTROL_ENCODER_SW5_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR11_DATA (11)
#define CONTROL_ENCODER_SW5_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR12_DATA (12)
#define CONTROL_ENCODER_SW5_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR13_DATA (13)
#define CONTROL_ENCODER_SW5_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR14_DATA (14)
#define CONTROL_ENCODER_SW5_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR15_DATA (15)
#define CONTROL_ENCODER_SW5_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR16_DATA (16)
#define CONTROL_ENCODER_SW5_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR17_DATA (17)
#define CONTROL_ENCODER_SW5_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR18_DATA (18)
#define CONTROL_ENCODER_SW5_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR19_DATA (19)
#define CONTROL_ENCODER_SW5_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW5_VAR20_DATA (20)
#define CONTROL_ENCODER_SW5_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW5_VAR21_DATA (21)
#define CONTROL_ENCODER_SW5_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW5_VAR22_DATA (22)
#define CONTROL_ENCODER_SW5_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW5_VAR23_DATA (23)

#define CONTROL_ENCODER_SW6_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR0_DATA (0)
#define CONTROL_ENCODER_SW6_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR1_DATA (1)
#define CONTROL_ENCODER_SW6_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR2_DATA (2)
#define CONTROL_ENCODER_SW6_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR3_DATA (3)
#define CONTROL_ENCODER_SW6_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR4_DATA (4)
#define CONTROL_ENCODER_SW6_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR5_DATA (5)
#define CONTROL_ENCODER_SW6_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR6_DATA (6)
#define CONTROL_ENCODER_SW6_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR7_DATA (7)
#define CONTROL_ENCODER_SW6_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR8_DATA (8)
#define CONTROL_ENCODER_SW6_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR9_DATA (9)
#define CONTROL_ENCODER_SW6_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR10_DATA (10)
#define CONTROL_ENCODER_SW6_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR11_DATA (11)
#define CONTROL_ENCODER_SW6_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR12_DATA (12)
#define CONTROL_ENCODER_SW6_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR13_DATA (13)
#define CONTROL_ENCODER_SW6_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR14_DATA (14)
#define CONTROL_ENCODER_SW6_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR15_DATA (15)
#define CONTROL_ENCODER_SW6_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR16_DATA (16)
#define CONTROL_ENCODER_SW6_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR17_DATA (17)
#define CONTROL_ENCODER_SW6_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR18_DATA (18)
#define CONTROL_ENCODER_SW6_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR19_DATA (19)
#define CONTROL_ENCODER_SW6_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW6_VAR20_DATA (20)
#define CONTROL_ENCODER_SW6_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW6_VAR21_DATA (21)
#define CONTROL_ENCODER_SW6_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW6_VAR22_DATA (22)
#define CONTROL_ENCODER_SW6_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW6_VAR23_DATA (23)

#define CONTROL_ENCODER_SW7_1_VAR0_CC   (0) // SW11_pos1, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR0_DATA (0)
#define CONTROL_ENCODER_SW7_1_VAR1_CC   (1) // SW11_pos1, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR1_DATA (1)
#define CONTROL_ENCODER_SW7_1_VAR2_CC   (2) // SW11_pos1, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR2_DATA (2)
#define CONTROL_ENCODER_SW7_1_VAR3_CC   (3) // SW11_pos1, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR3_DATA (3)
#define CONTROL_ENCODER_SW7_1_VAR4_CC   (4) // SW11_pos1, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR4_DATA (4)
#define CONTROL_ENCODER_SW7_1_VAR5_CC   (5) // SW11_pos1, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR5_DATA (5)
#define CONTROL_ENCODER_SW7_1_VAR6_CC   (6) // SW11_pos1, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR6_DATA (6)
#define CONTROL_ENCODER_SW7_1_VAR7_CC   (7) // SW11_pos1, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR7_DATA (7)
#define CONTROL_ENCODER_SW7_1_VAR8_CC   (8) // SW11_pos2, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR8_DATA (8)
#define CONTROL_ENCODER_SW7_1_VAR9_CC   (9) // SW11_pos2, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR9_DATA (9)
#define CONTROL_ENCODER_SW7_1_VAR10_CC   (10) // SW11_pos2, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR10_DATA (10)
#define CONTROL_ENCODER_SW7_1_VAR11_CC   (11) // SW11_pos2, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR11_DATA (11)
#define CONTROL_ENCODER_SW7_1_VAR12_CC   (12) // SW11_pos2, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR12_DATA (12)
#define CONTROL_ENCODER_SW7_1_VAR13_CC   (13) // SW11_pos2, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR13_DATA (13)
#define CONTROL_ENCODER_SW7_1_VAR14_CC   (14) // SW11_pos2, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR14_DATA (14)
#define CONTROL_ENCODER_SW7_1_VAR15_CC   (15) // SW11_pos2, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR15_DATA (15)
#define CONTROL_ENCODER_SW7_1_VAR16_CC   (16) // SW11_pos3, SW8_pos1,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR16_DATA (16)
#define CONTROL_ENCODER_SW7_1_VAR17_CC   (17) // SW11_pos3, SW8_pos1,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR17_DATA (17)
#define CONTROL_ENCODER_SW7_1_VAR18_CC   (18) // SW11_pos3, SW8_pos1,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR18_DATA (18)
#define CONTROL_ENCODER_SW7_1_VAR19_CC   (19) // SW11_pos3, SW8_pos1,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR19_DATA (19)
#define CONTROL_ENCODER_SW7_1_VAR20_CC   (20) // SW11_pos3, SW8_pos2,  button_OFF, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR20_DATA (20)
#define CONTROL_ENCODER_SW7_1_VAR21_CC   (21) // SW11_pos3, SW8_pos2,  button_OFF, button_ON
#define CONTROL_ENCODER_SW7_1_VAR21_DATA (21)
#define CONTROL_ENCODER_SW7_1_VAR22_CC   (22) // SW11_pos3, SW8_pos2,  button_ON, button_OFF
#define CONTROL_ENCODER_SW7_1_VAR22_DATA (22)
#define CONTROL_ENCODER_SW7_1_VAR23_CC   (23) // SW11_pos3, SW8_pos2,  button_ON, button_ON
#define CONTROL_ENCODER_SW7_1_VAR23_DATA (23)

#define CONTROL_ENCODER_SW7_CH   (ENCODER_CH_0)
#define CONTROL_ENCODER_SW9_CH   (ENCODER_CH_1)
#define CONTROL_ENCODER_SW10_CH  (ENCODER_CH_2)
#define CONTROL_BUTTON_SW7_1_CH  (BUTTONS_CH6)
#define CONTROL_BUTTON_SW1_CH    (BUTTONS_CH0)
#define CONTROL_BUTTON_SW2_CH    (BUTTONS_CH1)
#define CONTROL_BUTTON_SW3_CH    (BUTTONS_CH2)
#define CONTROL_BUTTON_SW4_CH    (BUTTONS_CH3)
#define CONTROL_BUTTON_SW5_CH    (BUTTONS_CH4)
#define CONTROL_BUTTON_SW6_CH    (BUTTONS_CH5)
#define CONTROL_TOGGLE_SW11_1    (BUTTONS_CH9)
#define CONTROL_TOGGLE_SW11_2    (BUTTONS_CH10)
#define CONTROL_TOGGLE_SW8       (BUTTONS_CH8)
#define CONTROL_BUTTON_SW12_CH   (BUTTONS_CH11)
#define CONTROL_BUTTON_SW13_CH   (BUTTONS_CH12)

// Specify MIDI channel for SW
#define CONTROL_MIDI_CH_SW1	 	 (0U)
#define CONTROL_MIDI_CH_SW2	 	 (1U)
#define CONTROL_MIDI_CH_SW3	 	 (2U)
#define CONTROL_MIDI_CH_SW4	 	 (3U)
#define CONTROL_MIDI_CH_SW5	 	 (4U)
#define CONTROL_MIDI_CH_SW6	 	 (5U)
#define CONTROL_MIDI_CH_SW7	 	 (6U)
#define CONTROL_MIDI_CH_SW7_1    (7U)
#define CONTROL_MIDI_CH_SW9	 	 (8U)
#define CONTROL_MIDI_CH_SW10	 (9U)




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