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
#define BUTTONS_ACTIVE_STATE_LOW (0U) 
#define BUTTONS_ACTIVE_STATE_HIGH (1U) 

#define BUTTONS_CH0 (0U)
#define BUTTONS_CH1 (1U)
#define BUTTONS_CH2 (2U)
#define BUTTONS_CH3 (3U)
#define BUTTONS_CH4 (4U)
#define BUTTONS_CH5 (5U)
#define BUTTONS_CH6 (6U)
#define BUTTONS_CH7 (7U)
#define BUTTONS_CH8 (8U)
#define BUTTONS_CH9 (9U)
#define BUTTONS_CH10 (10U)

/******************************************************************************
 * PUBLIC TYPES
 ******************************************************************************/

typedef enum
{
    BUTTONS_ACTIVE=0,
    BUTTONS_NOT_ACTIVE,
    BUTTONS_ER
} buttons_state_t;

/******************************************************************************
 * INLINE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/
void buttons_init(void);
buttons_state_t buttons_get_value(const uint8_t n_ch);
/******************************************************************************
 * END OF HEADER'S CODE
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // __BUTTONS_DRV_H_

/** @}*/