/**
 * @file      control_drv.h
 *
 * @brief     Interface for control driver
 *
 * @date      2023-02-21
 *
 */

/** \addtogroup module
 *  @{
 */

#ifndef __CONTROL_DRV_H_
#define __CONTROL_DRV_H_

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
#include "control_drv_cfg.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/

/******************************************************************************
 * PUBLIC TYPES
 ******************************************************************************/

/******************************************************************************
 * INLINE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/
void control_poll(void);

/******************************************************************************
 * END OF HEADER'S CODE
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // __CONTROL_DRV_H_

/** @}*/