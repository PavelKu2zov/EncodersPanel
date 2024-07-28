/**
 * @file      app.c
 *
 * @brief     Application
 *
 * @date      2023-01-20
 *
 *
 */

/** \addtogroup app
 *  @{
 */

/******************************************************************************
 * INCLUDES
 ******************************************************************************/

#include "app.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "bsp.h"
#include "encoder_drv.h"
#include "buttons_drv.h"
#include "control_drv.h"
#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "string.h"
#include "circ_buffer.h"



/******************************************************************************
 * DEFINES
 ******************************************************************************/
#define API_CIRC_BUFFER_SIZE_BYTES             (258U)


/******************************************************************************
 * PRIVATE TYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE DATA
 ******************************************************************************/
static stCIRCBUF* const p_circ_buff_hdl;
static uint8_t cicr_buffer[API_CIRC_BUFFER_SIZE_BYTES];



/******************************************************************************
 * PUBLIC DATA
 ******************************************************************************/

/******************************************************************************
 * EXTERNAL DATA
 ******************************************************************************/

/******************************************************************************
 * EXTERNAL FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 ******************************************************************************/

/******************************************************************************
 * PRIVATE FUNCTIONS
 ******************************************************************************/

/******************************************************************************
 * PUBLIC FUNCTIONS
 ******************************************************************************/

/**
 * @brief Application entry point
 *
 * @warning no exit from this function!
 *
 */
void app_entry_point(void)
{
    bsp_init();
    encoder_init();
    buttons_init();
	CIRCBUF_Init(p_circ_buff_hdl, cicr_buffer, API_CIRC_BUFFER_SIZE_BYTES);

    for (;;)
    {
        control_poll();
        // Delay(250);
    }
}

/**
 * @brief IRQ of TIM3
 *
 */
void TIM3_IRQHandler(void)
{
    encoder_calculate_rotations();
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);
}

void HardFault_Handler(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, DISABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate            = 31250;
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits            = USART_StopBits_1;
    USART_InitStruct.USART_Parity              = USART_Parity_No;
    USART_InitStruct.USART_Mode                = USART_Mode_Tx;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &USART_InitStruct);
    USART_Cmd(USART1, ENABLE);

    int8_t msg[] = {"Hard Fault\n\r"};

    while (true)
    {
        USART_SendData(USART1, 0xf0);
        while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TXE))
            ;
        for (uint16_t i = 0; i < strlen(msg); i++)
        {
            USART_SendData(USART1, msg[i]);
            while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TXE))
                ;
        }
        USART_SendData(USART1, 0xf7);

        for (uint32_t i = 0; i < 0xfffff; i++)
            ;
    }
}

void USART3_IRQHandler(void)
{
	uint8_t rx_data = 0U;

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_RXNE))
	{
		rx_data = (uint8_t)USART_ReceiveData(USART3);
		CIRCBUF_PutData(&rx_data, p_circ_buff_hdl);
	}
}



/******************************************************************************
 * END OF SOURCE'S CODE
 ******************************************************************************/
/** @}*/