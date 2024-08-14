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
#include "stm32f10x.h"



/******************************************************************************
 * DEFINES
 ******************************************************************************/
#define SW7_SIZE_FSM_TABLE      (48U)
#define SW9_SIZE_FSM_TABLE      (48U)
#define SW10_SIZE_FSM_TABLE     (48U)
#define SW1_SIZE_FSM_TABLE      (24U)
#define CONTROL_ADR_STORE_CONFIG 			(0x08007C00UL)



/******************************************************************************
 * PUBLIC TYPES
 ******************************************************************************/

typedef union
{
    struct prm_str
    {
        uint8_t cc;
        uint8_t data;
    } prm;
    uint16_t W;
} table_t;

typedef __PACKED_STRUCT
{
	table_t sw7_fsm_table[SW7_SIZE_FSM_TABLE];
	table_t sw9_fsm_table[SW9_SIZE_FSM_TABLE];
	table_t sw10_fsm_table[SW10_SIZE_FSM_TABLE];
	table_t sw1_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw2_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw3_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw4_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw5_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw6_fsm_table[SW1_SIZE_FSM_TABLE];
	table_t sw7_1_fsm_table[SW1_SIZE_FSM_TABLE];
	uint32_t crc32;
} control_cfg_t;



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