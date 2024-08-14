/**
 * @file      buttons_drv_cfg.h
 *
 * @brief     Configuration for buttons driver
 *
 * @date      2023-02-18
 *
 */

/** \addtogroup module
 *  @{
 */

#ifndef __BUTTONS_DRV_CFG_H_
#define __BUTTONS_DRV_CFG_H_

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

// Specify number of buttons to use
#define BUTTONS_QTY (13U)

#define BUTTONS_CH0_EN            (ON)// SW1
#define BUTTONS_GPIO_PORT_CH0     GPIOA
#define BUTTONS_GPIO_PIN_CH0      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH0 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH0        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH1_EN            (ON)// SW2
#define BUTTONS_GPIO_PORT_CH1     GPIOA
#define BUTTONS_GPIO_PIN_CH1      (GPIO_Pin_1)
#define BUTTONS_GPIO_PIN_MODE_CH1 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH1        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH2_EN            (ON)// SW3
#define BUTTONS_GPIO_PORT_CH2     GPIOA
#define BUTTONS_GPIO_PIN_CH2      (GPIO_Pin_2)
#define BUTTONS_GPIO_PIN_MODE_CH2 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH2        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH3_EN            (ON)// SW4
#define BUTTONS_GPIO_PORT_CH3     GPIOA
#define BUTTONS_GPIO_PIN_CH3      (GPIO_Pin_3)
#define BUTTONS_GPIO_PIN_MODE_CH3 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH3        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH4_EN            (ON)// SW5
#define BUTTONS_GPIO_PORT_CH4     GPIOA
#define BUTTONS_GPIO_PIN_CH4      (GPIO_Pin_4)
#define BUTTONS_GPIO_PIN_MODE_CH4 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH4        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH5_EN            (ON)// SW6
#define BUTTONS_GPIO_PORT_CH5     GPIOA
#define BUTTONS_GPIO_PIN_CH5      (GPIO_Pin_5)
#define BUTTONS_GPIO_PIN_MODE_CH5 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH5        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH6_EN            (ON)// button of encoder SW7
#define BUTTONS_GPIO_PORT_CH6     GPIOB
#define BUTTONS_GPIO_PIN_CH6      (GPIO_Pin_13)
#define BUTTONS_GPIO_PIN_MODE_CH6 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH6        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH7_EN            (OFF)// button of encoder SW12
#define BUTTONS_GPIO_PORT_CH7     GPIOB
#define BUTTONS_GPIO_PIN_CH7      (GPIO_Pin_12)
#define BUTTONS_GPIO_PIN_MODE_CH7 (GPIO_Mode_IN_FLOATING)
#define BUTTONS_ACTIVE_CH7        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH8_EN            (ON)// toggle SW8
#define BUTTONS_GPIO_PORT_CH8     GPIOA
#define BUTTONS_GPIO_PIN_CH8      (GPIO_Pin_6)
#define BUTTONS_GPIO_PIN_MODE_CH8 (GPIO_Mode_IPD)
#define BUTTONS_ACTIVE_CH8        (BUTTONS_ACTIVE_STATE_HIGH)

#define BUTTONS_CH9_EN            (ON)// toggle SW11_1
#define BUTTONS_GPIO_PORT_CH9     GPIOA
#define BUTTONS_GPIO_PIN_CH9      (GPIO_Pin_7)
#define BUTTONS_GPIO_PIN_MODE_CH9 (GPIO_Mode_IPD)
#define BUTTONS_ACTIVE_CH9        (BUTTONS_ACTIVE_STATE_HIGH)

#define BUTTONS_CH10_EN            (ON)// toggle SW11_2
#define BUTTONS_GPIO_PORT_CH10     GPIOA
#define BUTTONS_GPIO_PIN_CH10      (GPIO_Pin_8)
#define BUTTONS_GPIO_PIN_MODE_CH10 (GPIO_Mode_IPD)
#define BUTTONS_ACTIVE_CH10        (BUTTONS_ACTIVE_STATE_HIGH)

#define BUTTONS_CH11_EN            (ON)// SW12
#define BUTTONS_GPIO_PORT_CH11     GPIOB
#define BUTTONS_GPIO_PIN_CH11      (GPIO_Pin_8)
#define BUTTONS_GPIO_PIN_MODE_CH11 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH11        (BUTTONS_ACTIVE_STATE_LOW)

#define BUTTONS_CH12_EN            (ON)// SW13
#define BUTTONS_GPIO_PORT_CH12     GPIOB
#define BUTTONS_GPIO_PIN_CH12      (GPIO_Pin_9)
#define BUTTONS_GPIO_PIN_MODE_CH12 (GPIO_Mode_IPU)
#define BUTTONS_ACTIVE_CH12        (BUTTONS_ACTIVE_STATE_LOW)

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

#endif // __BUTTONS_DRV_CFG_H_

/** @}*/