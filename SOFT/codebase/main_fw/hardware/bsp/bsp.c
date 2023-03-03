#include "stm32f10x.h"
#include "bsp.h"
#include "control_drv.h"

extern uint8_t bufferUartTx[];

void bsp_init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); // 72 MHz clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); // 36 MHz clock
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); // 36 MHz clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    /******************************** GPIO *********************/
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_10; // Test pin
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    // Uart tx
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*****************************Timer2***************************/
    TIM_DeInit(TIM2);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    // 36 MHz clock
    TIM_TimeBaseInitStruct.TIM_Prescaler         = 36000 - 1U;
    TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period            = 0xffff;
    TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    // Timer3 for poll encoders
    TIM_DeInit(TIM3);
    TIM_TimeBaseInitStruct.TIM_Prescaler         = 35;
    TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period            = 400;
    TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM3, ENABLE);

    /********************************DMA*****************************/
    DMA_DeInit(DMA1_Channel4); // USART1_TX

    DMA_InitTypeDef DMA_InitStruct;
    DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
    DMA_InitStruct.DMA_MemoryBaseAddr     = (uint32_t)&bufferUartTx;
    DMA_InitStruct.DMA_DIR                = DMA_DIR_PeripheralDST;
    DMA_InitStruct.DMA_BufferSize         = 0;
    DMA_InitStruct.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStruct.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStruct.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;
    DMA_InitStruct.DMA_Mode               = DMA_Mode_Normal;
    DMA_InitStruct.DMA_Priority           = DMA_Priority_Low;
    DMA_InitStruct.DMA_M2M                = DMA_M2M_Disable;

    DMA_Init(DMA1_Channel4, &DMA_InitStruct);
    DMA_Cmd(DMA1_Channel4, DISABLE);
    /********************************Usart1***************************/
    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate            = 31250;
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits            = USART_StopBits_1;
    USART_InitStruct.USART_Parity              = USART_Parity_No;
    USART_InitStruct.USART_Mode                = USART_Mode_Tx;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &USART_InitStruct);

#if 0
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
#endif
    /* Enable USART2 */
    USART_Cmd(USART1, ENABLE);
    /********************************��������� NVIC******************************/

    NVIC_EnableIRQ(TIM3_IRQn);
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel                   = TIM3_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority        = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

/**
 * @brief Delay funcrion
 *
 * @param time in us
 */
void Delay(uint16_t time)
{
    TIM_Cmd(TIM2, DISABLE);
    TIM_SetCounter(TIM2, 0);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);
    TIM_SetAutoreload(TIM2, time);
    // wait
    TIM_Cmd(TIM2, ENABLE);
    while (SET != TIM_GetFlagStatus(TIM2, TIM_FLAG_Update))
        ;
    TIM_Cmd(TIM2, DISABLE);
}