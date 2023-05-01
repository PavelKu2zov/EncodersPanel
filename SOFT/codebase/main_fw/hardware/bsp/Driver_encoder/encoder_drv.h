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
extern "C"
{
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
#define ENCODER_CH_0 (0U)
#define ENCODER_CH_1 (1U)
#define ENCODER_CH_2 (2U)
#define ENCODER_CH_3 (3U)
#define ENCODER_CH_4 (4U)

#define ENCODER_DIR_ROTATION_RIGHT (0U)
#define ENCODER_DIR_ROTATION_LEFT  (1U)
#define ENCODER_DIR_ROTATION_NONE  (2U)

#define ENCODER_GET_DIR_ROTATION(x) (((x) == 0) ? ENCODER_DIR_ROTATION_NONE : (((x) < 0) ? ENCODER_DIR_ROTATION_LEFT : ENCODER_DIR_ROTATION_RIGHT))

    /******************************************************************************
     * PUBLIC TYPES
     ******************************************************************************/

    /******************************************************************************
     * INLINE FUNCTIONS
     ******************************************************************************/

    /******************************************************************************
     * PUBLIC FUNCTION PROTOTYPES
     ******************************************************************************/
    void    encoder_init(void);
    void    encoder_calculate_rotations(void);
    int32_t encoder_get_channel_value(const uint8_t nChannel);

/******************************************************************************
 * END OF HEADER'S CODE
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // __ENCODER_DRV_H_

/** @}*/