/**
  * @file      encoder_drv.h
  *
  * @brief     Interface for ENCODER_DRV module
  *
  * @date      2022-12-21
  *
  */
 
/** \addtogroup module
*  @{
*/
 
#ifndef __ENCODER_DRV_H_
#define __ENCODER_DRV_H_
 
#ifdef __cplusplus
extern "C" {
#endif
 
/******************************************************************************
 * INCLUDES
 ******************************************************************************/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "encoder_drv_cfg.h"
 
/******************************************************************************
 * DEFINES
 ******************************************************************************/
 // Encoder channels
#define ENCODER_CH_0                        (0U)
#define ENCODER_CH_1                        (1U)
#define ENCODER_CH_2                        (2U)
#define ENCODER_CH_3                        (3U)
#define ENCODER_CH_4                        (4U)
 
/******************************************************************************
 * PUBLIC TYPES
 ******************************************************************************/
 // Encoder direction rotation type
typedef enum
{
    ENCODER_DIR_ROTATION_RIGHT,             // Encoder rotation right
    ENCODER_DIR_ROTATION_LEFT,              // Encoder rotation left
    ENCODER_DIR_ROTATION_NONE               // Encoder not rotation
} encoder_dir_rotation_t;

// Encoder state type
typedef struct 
{
    uint32_t n_counter_impulses;                  // Counter of encoder impulses
    encoder_dir_rotation_t enDirection;       // Direction rotation
} encoder_state_t;
 
 
/******************************************************************************
 * INLINE FUNCTIONS
 ******************************************************************************/
 
 
 
/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/
void encoder_init(void);
void encoder_calculate_rotations(void);
void encoder_get_channel_value(const uint8_t nChannel,
                                encoder_state_t *const stStateCh);
 
 
/******************************************************************************
 * END OF HEADER'S CODE
 ******************************************************************************/
#ifdef __cplusplus
}
#endif
 
#endif // __ENCODER_DRV_H_
 
/** @}*/