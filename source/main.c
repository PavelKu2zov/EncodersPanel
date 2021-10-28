#include "stm32f10x.h"
#include "Init.h"
#include <stdio.h>

#define FORWARD		0
#define BACKWARD	1

#define NOREADY		0
#define READY		1
#define INIT		3


volatile uint8_t encoder_status = INIT;
volatile uint8_t encoder_direction = FORWARD;
char buffer[80];

uint8_t DataPortA = 0;
uint8_t DataPortB = 0;

void USARTSend(const unsigned char *pucBuffer, uint8_t size);
int main(void)
{
Init();
MCP23017_Init();

while(1)
{
    DataPortA = MCP23017_GetPortA();
    DataPortB = MCP23017_GetPortB();
  
    
  
  
  
  
  
  
  
  
  if (encoder_status)
    {
       encoder_status = NOREADY;
       uint8_t nSize=0;
       if (encoder_direction == FORWARD)
       {
          //nSize = sprintf(buffer, "FORWARD\r\n");  
          buffer[0] = 0xb4;
          buffer[1] = 0x01;
          buffer[2] = 0x01; 

          nSize = 3;
       }
        else
        {
          //nSize = sprintf(buffer, "BACKWARD\r\n");
          buffer[0] = 0xb4;
          buffer[1] = 0x01;
          buffer[2] = 0x7f;
          nSize = 3;
               
        }
        USARTSend(buffer,nSize);
       
       
     
    }
}

}



void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

		if (encoder_status == INIT)
			encoder_status = NOREADY;
		else
			encoder_status = READY;

		
		encoder_direction = (TIM2->CR1 & TIM_CR1_DIR ? BACKWARD : FORWARD);
	}
}


void USARTSend(const unsigned char *pucBuffer, uint8_t size)
{
    while (0 != size)
    {
        USART_SendData(USART2, *pucBuffer++);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
        {
        }
        size--;
    }
}
