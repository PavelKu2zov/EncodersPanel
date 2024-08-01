#ifndef __BSP_H_
#define __BSP_H_

#include "stm32f10x.h"
#define ARR     144

void bsp_init(void);
void Delay( uint16_t time );
uint64_t bsp_get_current_time(void);


#endif // __BSP_H_


