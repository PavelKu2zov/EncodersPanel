/**
  * @file      encoder_drv_cfg.h
  *
  * @brief     Configuration for ENCODER_DRV module
  *
  * @date      2023-02-14
  *
  */
 
/** \addtogroup module
*  @{
*/
 
#ifndef __ENCODER_DRV_CFG_H_
#define __ENCODER_DRV_CFG_H_
 
#ifdef __cplusplus
extern "C" {
#endif
 
/******************************************************************************
 * INCLUDES
 ******************************************************************************/
 
 
 
/******************************************************************************
 * DEFINES
 ******************************************************************************/
 // Specify number of channels
#define ENCODER_QTY_CH (5U)
 
 // Specify GPIO pin channel 0
#define ENCODER_CH0_EN                             (ON)// Encoder #SW7
#define ENCODER_GPIO_PORT_PIN0_CH0                 GPIOB
#define ENCODER_GPIO_PORT_PIN1_CH0                 GPIOB
#define ENCODER_GPIO_PIN_0_CH0                     (GPIO_Pin_7)
#define ENCODER_GPIO_PIN_1_CH0                     (GPIO_Pin_6)
#define ENCODER_GPIO_PIN_0_MODE_CH0                (GPIO_Mode_IN_FLOATING)
#define ENCODER_GPIO_PIN_1_MODE_CH0                (GPIO_Mode_IN_FLOATING)
#define ENCODER_BIT_RESULT_POS_CH0                 (6U) 

// Specify GPIO pin channel 1
#define ENCODER_CH1_EN                             (ON)// Encoder #SW9
#define ENCODER_GPIO_PORT_PIN0_CH1                 GPIOB
#define ENCODER_GPIO_PORT_PIN1_CH1                 GPIOB
#define ENCODER_GPIO_PIN_0_CH1                     (GPIO_Pin_0)
#define ENCODER_GPIO_PIN_1_CH1                     (GPIO_Pin_1)
#define ENCODER_GPIO_PIN_0_MODE_CH1                (GPIO_Mode_IPU)
#define ENCODER_GPIO_PIN_1_MODE_CH1                (GPIO_Mode_IPU)
#define ENCODER_BIT_RESULT_POS_CH1                 (0U) 

// Specify GPIO pin channel 2
#define ENCODER_CH2_EN                             (ON)// Encoder #SW10
#define ENCODER_GPIO_PORT_PIN0_CH2                 GPIOB
#define ENCODER_GPIO_PORT_PIN1_CH2                 GPIOB
#define ENCODER_GPIO_PIN_0_CH2                     (GPIO_Pin_5)
#define ENCODER_GPIO_PIN_1_CH2                     (GPIO_Pin_4)
#define ENCODER_GPIO_PIN_0_MODE_CH2                (GPIO_Mode_IPU)
#define ENCODER_GPIO_PIN_1_MODE_CH2                (GPIO_Mode_IPU)
#define ENCODER_BIT_RESULT_POS_CH2                 (4U) 

// Specify GPIO pin channel 3
#define ENCODER_CH3_EN                             (ON)// Encoder #SW12
#define ENCODER_GPIO_PORT_PIN0_CH3                 GPIOB
#define ENCODER_GPIO_PORT_PIN1_CH3                 GPIOB
#define ENCODER_GPIO_PIN_0_CH3                     (GPIO_Pin_8)
#define ENCODER_GPIO_PIN_1_CH3                     (GPIO_Pin_9)
#define ENCODER_GPIO_PIN_0_MODE_CH3                (GPIO_Mode_IPU)
#define ENCODER_GPIO_PIN_1_MODE_CH3                (GPIO_Mode_IPU)
#define ENCODER_BIT_RESULT_POS_CH3                 (8U) 

// Specify GPIO pin channel 4
#define ENCODER_CH4_EN                             (OFF)// None
#define ENCODER_GPIO_PORT_PIN0_CH4                 GPIOB
#define ENCODER_GPIO_PORT_PIN1_CH4                 GPIOB
#define ENCODER_GPIO_PIN_0_CH4                     (GPIO_Pin_8)
#define ENCODER_GPIO_PIN_1_CH4                     (GPIO_Pin_9)
#define ENCODER_GPIO_PIN_0_MODE_CH4                (GPIO_Mode_IPU)
#define ENCODER_GPIO_PIN_1_MODE_CH4                (GPIO_Mode_IPU)
#define ENCODER_BIT_RESULT_POS_CH4                 (8U) 


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
 
#endif // __ENCODER_DRV_CFG_H_
 
/** @}*/