//**************************************************************************************************
// @Module        DEVICE
// @Filename      main.c
//--------------------------------------------------------------------------------------------------
// @Platform      PLATFORM_NAME
//--------------------------------------------------------------------------------------------------
// @Compatible    COMPATIBLE_PROCESSOR_MODULE
//--------------------------------------------------------------------------------------------------
// @Description   Implementation of the MODULE functionality.
//                
//
//                Abbreviations:
//                  None.
//                  
//
//                Global (public) functions:
//                  MODULE_functionZero()
//                  MODULE_functionOne()
//
//                Local (private) functions:
//                  MODULE_functionTwo()
//                  MODULE_functionThree()
//
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          XX.XX.XXXX
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// XX.XX.XXXX     1.0.0    XXX         First release.
//**************************************************************************************************



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

#include "stm32f10x.h"
#include "Init.h"
#include <stdio.h>


//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// Have to specify number encoders
#define DEVICE_NUM_ENCODERS         (4)



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// type of encoder
typedef enum DEVICE_STATUS_ENCODER_enum
{
    NOT_ROTATION=0,
    FORWARD,
    BACKWARD
}DEVICE_STATUS_ENCODER;


// type structure of device
typedef struct DEVICE_CONTROLS_struct
{
    DEVICE_STATUS_ENCODER encoder[DEVICE_NUM_ENCODERS];
}DEVICE_CONTROLS;

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Get code each encoders
// numEn  [0,1 .. DEVICE_NUM_ENCODERS-1]
#define DEVICE_GET_CODE_EN(numEn,dataIn)       ((dataIn >> (numEn*2)) & 0x03)


//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// structure of device
static DEVICE_CONTROLS DEVICE_control;

static uint8_t DEVICE_oldCodeEncoders = 0;

static uint8_t bufferUartTx[64];

//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// Get direction of rotation
static void DEVICE_GetStatusEncoders(void);

//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************

// None.

//**************************************************************************************************
// @Function      main()
//--------------------------------------------------------------------------------------------------
// @Description   [description...]
//--------------------------------------------------------------------------------------------------
// @Notes
//--------------------------------------------------------------------------------------------------
// @ReturnValue   returnValue - [description...]
//--------------------------------------------------------------------------------------------------
// @Parameters    parameterZero - [description...]
//**************************************************************************************************
int main(void)
{
Init();
MCP23017_Init();

while(1)
{
    DEVICE_GetStatusEncoders();
    
    for (int i=0;i < DEVICE_NUM_ENCODERS;i++)
    {
        if (NOT_ROTATION != DEVICE_control.encoder[i])
        {
            uint8_t nSize=0;
            if (FORWARD == DEVICE_control.encoder[i])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = 0x01;
                bufferUartTx[2] = 0x01;
                nSize = 3;
            }
            else
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = 0x01;
                bufferUartTx[2] = 0x7f;
                nSize = 3;
            }
            USARTSend(bufferUartTx,nSize);
        }
    }
  
  
}

}
// end of main()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      DEVICE_GetStatusEncoders()
//--------------------------------------------------------------------------------------------------
// @Description   Get status encoders
//--------------------------------------------------------------------------------------------------
// @Notes         Number encoders is specified in DEVICE_NUM_ENCODERS  
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.  
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//                
//**************************************************************************************************
static void DEVICE_GetStatusEncoders(void)
{
    uint8_t nNewCodeEncoders = 0;
    
    nNewCodeEncoders = MCP23017_GetPortA();
    
    for (int i=0;i < DEVICE_NUM_ENCODERS;i++)
    {
        if (DEVICE_GET_CODE_EN(i,nNewCodeEncoders) != DEVICE_GET_CODE_EN(i,DEVICE_oldCodeEncoders))
        {
            switch(DEVICE_GET_CODE_EN(i,DEVICE_oldCodeEncoders))
            {
                case 0:
                        {
                            if (2 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = FORWARD;
                            }
                            else if (1 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = BACKWARD;
                            }
                        }
                case 2:
                        {
                            if (3 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = FORWARD;
                            }
                            else if (0 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = BACKWARD;
                            }
                        }
                case 3:
                        {
                            if (1 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = FORWARD;
                            }
                            else if (2 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = BACKWARD;
                            }
                        }
                case 1:
                        {
                            if (0 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = FORWARD;
                            }
                            else if (3 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = BACKWARD;
                            }
                        }
            }
        }
        else
        {
            DEVICE_control.encoder[i] = NOT_ROTATION;
        }
    }
    
}
// end of DEVICE_GetStatusEncoders()



//**************************************************************************************************
// @Function      USARTSend()
//--------------------------------------------------------------------------------------------------
// @Description   Send data to usart
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.  
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//                
//**************************************************************************************************
void USARTSend(const unsigned char *pucbufferUartTx, uint8_t size)
{
    while (0 != size)
    {
        USART_SendData(USART2, *pucbufferUartTx++);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
        {
        }
        size--;
    }
}// end of USARTSend()


