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
#define BUTTONS_QTY (8U)

#define BUTTONS_CH0_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH0     GPIOB
#define BUTTONS_GPIO_PIN_CH0      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH0 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH0           (BUTTONS_FUN_NC)

#define BUTTONS_CH1_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH1     GPIOB
#define BUTTONS_GPIO_PIN_CH1      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH1 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH1           (BUTTONS_FUN_NC)

#define BUTTONS_CH2_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH2     GPIOB
#define BUTTONS_GPIO_PIN_CH2      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH2 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH2           (BUTTONS_FUN_NC)

#define BUTTONS_CH3_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH3     GPIOB
#define BUTTONS_GPIO_PIN_CH3      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH3 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH3           (BUTTONS_FUN_NC)

#define BUTTONS_CH4_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH4     GPIOB
#define BUTTONS_GPIO_PIN_CH4      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH4 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH4           (BUTTONS_FUN_NC)

#define BUTTONS_CH5_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH5     GPIOB
#define BUTTONS_GPIO_PIN_CH5      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH5 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH5           (BUTTONS_FUN_NC)

#define BUTTONS_CH6_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH6     GPIOB
#define BUTTONS_GPIO_PIN_CH6      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH6 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH6           (BUTTONS_FUN_NC)

#define BUTTONS_CH7_EN            (OFF)
#define BUTTONS_GPIO_PORT_CH7     GPIOB
#define BUTTONS_GPIO_PIN_CH7      (GPIO_Pin_0)
#define BUTTONS_GPIO_PIN_MODE_CH7 (GPIO_Mode_IPU)
#define BUTTONS_FUN_CH7           (BUTTONS_FUN_NC)

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