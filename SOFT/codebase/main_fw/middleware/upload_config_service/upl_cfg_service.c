/**
  * @file      upl_cfg_srvc.c
  *
  * @brief     Some module
  *
  * @date      2022-12-21
  *
  */

/** \addtogroup module
*  @{
*/

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "upl_cfg_service.h"
#include "circ_buffer.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_flash.h"
#include "stm32f10x.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "xmodem_server.h"
#include "bsp.h"
#include "control_drv.h"



/******************************************************************************
 * DEFINES
 ******************************************************************************/

#define CIRC_BUFFER_SIZE_BYTES                             (512U)
#define UPL_CFG_SERVICE_UPLOAD_CMD                         ('u')
#define UPL_CFG_SERVICE_BUF_NEW_CFG_SIZE_BYTES             (512U)

#define UPL_CFG_SERVICE_BUF_NEW_CFG_PAYLOAD_MIN_SIZE_BYTES             (7U)



/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/

typedef enum
{
	UPL_CFG_SRVC_FSM_WAIT_CMD            = 0U,
	UPL_CFG_SRVC_FSM_XMODEM_PROCESS = 1U
} upl_cfg_srvc_fsm_t;

typedef enum
{
	UPL_CFG_SRVC_FSM_PARS_START           = 0U,
	UPL_CFG_SRVC_FSM_PARS_LEN             = 1U,
	UPL_CFG_SRVC_FSM_PARS_DATA            = 2U,
	UPL_CFG_SRVC_FSM_PARS_CRC             = 3U
} upl_cfg_srvc_fsm_pars_t;

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/

static upl_cfg_srvc_fsm_t upl_cfg_srvc_fsm = UPL_CFG_SRVC_FSM_WAIT_CMD;
static stCIRCBUF p_circ_buff_hdl;
static uint8_t cicr_buffer[CIRC_BUFFER_SIZE_BYTES];
static struct xmodem_server upl_cfg_srvc_xdm;
static uint8_t upl_cfg_srvc_xmodem_resp[XMODEM_MAX_PACKET_SIZE];
static uint8_t upl_cfg_srvc_new_cfg[UPL_CFG_SERVICE_BUF_NEW_CFG_SIZE_BYTES];
static volatile uint32_t qty_store_bytes = 0;



/******************************************************************************
 * PUBLIC DATA
 ******************************************************************************/

// None.



/******************************************************************************
 * EXTERNAL DATA
 ******************************************************************************/

// None.



/******************************************************************************
 * EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

// None.



/******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

static bool upl_cfg_srvc_get_cmd(void);
static void upl_cfg_srvc_tx_byte(struct xmodem_server *xdm, uint8_t byte, void *cb_data);



/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

static bool upl_cfg_srvc_get_cmd(void)
{
	bool retval = false;
	uint8_t data = 0U;

	if (CIRCBUF_NO_ERR == CIRCBUF_GetData(&data, &p_circ_buff_hdl))
	{
		if (UPL_CFG_SERVICE_UPLOAD_CMD == data)
		{
			retval = true;
		}
	}

	return retval;
}

static void upl_cfg_srvc_tx_byte(struct xmodem_server *xdm, uint8_t byte, void *cb_data)
{
	while (RESET == USART_GetFlagStatus(USART3, USART_FLAG_TXE));
    USART_SendData(USART3, byte);
}



/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/

STD_RESULT upl_cfg_srvc_init(void)
{
	STD_RESULT retval = RESULT_OK;

	CIRCBUF_Init(&p_circ_buff_hdl, cicr_buffer, CIRC_BUFFER_SIZE_BYTES);
	xmodem_server_init(&upl_cfg_srvc_xdm, upl_cfg_srvc_tx_byte, NULL);


	return retval;
}

STD_RESULT upl_cfg_srvc_process(void)
{
	STD_RESULT retval = RESULT_OK;

	switch (upl_cfg_srvc_fsm)
	{
		case UPL_CFG_SRVC_FSM_WAIT_CMD:
			if (true == upl_cfg_srvc_get_cmd())
			{
				upl_cfg_srvc_fsm = UPL_CFG_SRVC_FSM_XMODEM_PROCESS;
			}
			break;

		case UPL_CFG_SRVC_FSM_XMODEM_PROCESS:
			while (!xmodem_server_is_done(&upl_cfg_srvc_xdm))
			{
				uint32_t block_nr = 0U;
				int rx_data_len   = 0;
				uint8_t rx_byte   = 0U;

				if (0 != CIRCBUF_GetNumberOfItems(&p_circ_buff_hdl))
				{
					CIRCBUF_GetData(&rx_byte, &p_circ_buff_hdl);
					xmodem_server_rx_byte(&upl_cfg_srvc_xdm, rx_byte);
				}

				rx_data_len = xmodem_server_process(&upl_cfg_srvc_xdm, upl_cfg_srvc_xmodem_resp, &block_nr, bsp_get_current_time());

				if (rx_data_len > 0)
				{
					if ((qty_store_bytes + rx_data_len) < sizeof(upl_cfg_srvc_new_cfg))
					{
						memcpy(&upl_cfg_srvc_new_cfg[qty_store_bytes], upl_cfg_srvc_xdm.packet_data, rx_data_len);
						qty_store_bytes += rx_data_len;
					}

					// TODO
					//handle_incoming_packet(upl_cfg_srvc_xmodem_resp, rx_data_len, block_nr);
				}
			}

			if (xmodem_server_get_state(&upl_cfg_srvc_xdm) == XMODEM_STATE_FAILURE)
			{
				// TODO
				//handle_transfer_failure();
				xmodem_server_init(&upl_cfg_srvc_xdm, upl_cfg_srvc_tx_byte, NULL);
			}
			else if (xmodem_server_get_state(&upl_cfg_srvc_xdm) == XMODEM_STATE_SUCCESSFUL)
			{
				uint16_t len_payload = 0U;

				if (qty_store_bytes >= UPL_CFG_SERVICE_BUF_NEW_CFG_PAYLOAD_MIN_SIZE_BYTES)
				{
					len_payload = upl_cfg_srvc_new_cfg[0U] << 8U;
					len_payload |= upl_cfg_srvc_new_cfg[1U];
				}

				if (len_payload == (sizeof(control_cfg_t) - 4U))
				{
					uint32_t adr  = CONTROL_ADR_STORE_CONFIG;
					uint32_t data = 0U;
					volatile uint8_t t = 0;
					uint8_t rem = 0U;

					// Check CRC
					// TODO

					// Write to flash
					FLASH_Unlock();

					if (FLASH_COMPLETE == FLASH_ErasePage(adr))
					{
						for (uint32_t i = 0U; i < ((len_payload + 4U) / 4U); i++)
						{
							memcpy((uint8_t*)&data, &upl_cfg_srvc_new_cfg[2U + (i * 4U)], 4U);

							if (FLASH_COMPLETE == FLASH_ProgramWord(adr, data))
							{
								adr +=4U;
							}
							else
							{
								// TODO
								t = 0;
							}

						}

						rem = ((len_payload + 4U) % 4U);

						if (rem != 0)
						{
							data = 0xffffffff;

							memcpy((uint8_t*)&data, &upl_cfg_srvc_new_cfg[2U + ((len_payload + 4U) / 4U)], rem);
						}
					}

					control_init();
				}

				memset(upl_cfg_srvc_new_cfg, 0, sizeof(upl_cfg_srvc_new_cfg));
				xmodem_server_init(&upl_cfg_srvc_xdm, upl_cfg_srvc_tx_byte, NULL);
			}
			else
			{
				// Do nothing
			}

			qty_store_bytes = 0U;
			upl_cfg_srvc_fsm = UPL_CFG_SRVC_FSM_WAIT_CMD;
			break;

		default:
			upl_cfg_srvc_fsm = UPL_CFG_SRVC_FSM_WAIT_CMD;
			break;
	}
	return retval;
}


void USART3_IRQHandler(void)
{
	uint8_t rx_data = 0U;

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_RXNE))
	{
		rx_data = (uint8_t)USART_ReceiveData(USART3);
		CIRCBUF_PutData(&rx_data, &p_circ_buff_hdl);
	}
}

/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/