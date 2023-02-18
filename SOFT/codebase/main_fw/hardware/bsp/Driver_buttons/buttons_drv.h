/**
 * @file      buttons_drv.h
 *
 * @brief     Interface for buttons driver
 *
 * @date      2023-02-18
 *
 * @par
 */

/** \addtogroup module
 *  @{
 */

#ifndef __BUTTONS_DRV_H_
#define __BUTTONS_DRV_H_

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
#include "buttons_drv_cfg.h"

/******************************************************************************
 * DEFINES
 ******************************************************************************/
#define BUTTONS_FUN_NO      (0U)    // Normally open
#define BUTTONS_FUN_NC      (1U)    // Normally closed

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

#endif // __BUTTONS_DRV_H_

/** @}*/