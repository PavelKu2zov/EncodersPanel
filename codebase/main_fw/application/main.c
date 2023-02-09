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
#include "MCP23017_drv.h"

//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// Have to specify number encoders
#define DEVICE_NUM_ENCODERS         (4)

// Have to specify number buttons
#define DEVICE_NUM_BUTTONS         (8)

#define DEVICE_NUM_TOGGLES_POS2         (1)

#define DEVICE_NUM_TOGGLES_POS3         (1)

#define DEVICE_NUMBER_CNT               (254)

uint8_t bufferUartTx[DEVICE_SIZE_BUF_USART2];


//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// toggles status  
typedef enum DEVICE_STATUS_TOGGLE_POS_enum
{
    POS1=0,
    POS2,
    POS3
}DEVICE_STATUS_TOGGLE_POS;

// buttons's status  
typedef enum DEVICE_STATUS_BUTTON_enum
{
    NOT_PUSHED=0,
    PUSHED
}DEVICE_STATUS_BUTTON;


// encoder's status  
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
    DEVICE_STATUS_BUTTON buttons[DEVICE_NUM_BUTTONS];
    DEVICE_STATUS_TOGGLE_POS togglesPos2[DEVICE_NUM_TOGGLES_POS2];
    DEVICE_STATUS_TOGGLE_POS togglesPos3[DEVICE_NUM_TOGGLES_POS3];
}DEVICE_CONTROLS;

//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Get code each encoders
// numEn  [0,1 .. DEVICE_NUM_ENCODERS-1]
#define DEVICE_GET_CODE_EN(numEn,dataIn)       ((dataIn >> (numEn*2)) & 0x03)

#define DEVICE_DELAY_MS                        (10)

#define CC(x)           (x)
//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// structure of device
static DEVICE_CONTROLS DEVICE_control;

static uint8_t DEVICE_oldCodeEncoders = 0;

static uint8_t index=0;
static uint8_t testBuf[256];

static uint8_t flagAllowSwitchButEncoderOptic = 0;

static uint8_t flagsAllowSwitchBut[6];
//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// Get direction of rotation
static void DEVICE_GetStatusEncoders(void);

static void DEVICE_GetStatusButtons(void);

static void USARTSend(const unsigned char *pucbufferUartTx, uint16_t size);

void Delay( uint16_t time );


//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************

// None.

//**************************************************************************************************
// @Function      main()
//--------------------------------------------------------------------------------------------------
// @Description   None.
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
    DEVICE_GetStatusButtons();
    
//    for (int i=0;i < DEVICE_NUM_ENCODERS;i++)
//    {
//        if (NOT_ROTATION != DEVICE_control.encoder[i])
//        {
//            uint8_t nSize=0;
//            if (FORWARD == DEVICE_control.encoder[i])
//            {
//                //nSize = sprintf(bufferUartTx,"%s %d\r\n","FORWARD",DEVICE_GET_CODE_EN(i,DEVICE_oldCodeEncoders));
//                //nSize = sprintf(bufferUartTx,"%s %d\r\n","FORWARD",i);
//                bufferUartTx[0] = 0xb4;
//                bufferUartTx[1] = 0x01;
//                bufferUartTx[2] = 0x01;
//                nSize = 3;
//            }
//            else
//            {
//              //nSize = sprintf(bufferUartTx,"%s %d\r\n","BACKWARD",DEVICE_GET_CODE_EN(i,DEVICE_oldCodeEncoders));
//              //nSize = sprintf(bufferUartTx,"%s %d\r\n","BACKWARD",i);
//                bufferUartTx[0] = 0xb4;
//                bufferUartTx[1] = 0x01;
//                bufferUartTx[2] = 0x7f;
//                nSize = 3;
//            }
//            USARTSend(bufferUartTx,nSize);
//            DEVICE_control.encoder[i] = NOT_ROTATION;
//        }
//    }

/**************************** Encoder 0 *************************************/
    if (NOT_ROTATION != DEVICE_control.encoder[0])
    {          
        uint8_t nSize=0;
        if (FORWARD == DEVICE_control.encoder[0])
        {            
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(30);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(40);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(50);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
        }
        else
        {
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(30);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(40);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(50);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
        }
        USARTSend(bufferUartTx,nSize);
        DEVICE_control.encoder[0] = NOT_ROTATION;
    }
   
/**************************** Encoder 1 *************************************/
    if (NOT_ROTATION != DEVICE_control.encoder[1])
    {          
        uint8_t nSize=0;
        if (FORWARD == DEVICE_control.encoder[1])
        {            
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(31);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(41);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(51);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
        }
        else
        {
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(31);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(41);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(51);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
        }
        USARTSend(bufferUartTx,nSize);
        DEVICE_control.encoder[1] = NOT_ROTATION;
    }

/**************************** Encoder 2 *************************************/
    if (NOT_ROTATION != DEVICE_control.encoder[2])
    {          
        uint8_t nSize=0;
        if (FORWARD == DEVICE_control.encoder[2])
        {            
            if (( POS1 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == NOT_PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(11);
                bufferUartTx[2] = 127;
                nSize = 3;
            }
            else if (( POS1 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(21);
                bufferUartTx[2] = 127;
                nSize = 3;
            }
            else if (( POS2 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == NOT_PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(20);
                bufferUartTx[2] = 124;
                nSize = 3;
            }
            else if (( POS2 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(10);
                bufferUartTx[2] = 124;
                nSize = 3;
            }
        }
        else
        {
            if (( POS1 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == NOT_PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(12);
                bufferUartTx[2] = 127;
                nSize = 3;
            }
            else if (( POS1 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(22);
                bufferUartTx[2] = 127;
                nSize = 3;
            }
            else if (( POS2 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == NOT_PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(20);
                bufferUartTx[2] = 4;
                nSize = 3;
            }
            else if (( POS2 == DEVICE_control.togglesPos2[0]) && (DEVICE_control.buttons[7] == PUSHED))
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(10);
                bufferUartTx[2] = 4;
                nSize = 3;
            }
        }
        USARTSend(bufferUartTx,nSize);
        DEVICE_control.encoder[2] = NOT_ROTATION;
    }    
    
/**************************** Encoder 3 *************************************/
    if (NOT_ROTATION != DEVICE_control.encoder[3])
    {          
        uint8_t nSize=0;
        if (FORWARD == DEVICE_control.encoder[3])
        {            
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(32);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(42);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(52);
                bufferUartTx[2] = 109;
                nSize = 3;
            }
        }
        else
        {
            if ( POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(32);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(42);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(52);
                bufferUartTx[2] = 18;
                nSize = 3;
            }
        }
        USARTSend(bufferUartTx,nSize);
        DEVICE_control.encoder[3] = NOT_ROTATION;
    }    
    
/**************************** Buttons_0 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[0])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(13);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(23);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[0] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }
/**************************** Buttons_1 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[1])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(14);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(24);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[1] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }
/**************************** Buttons_2 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[2])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(15);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos2[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(25);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[2] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }
/**************************** Buttons_3 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[3])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(33);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(43);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(53);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[3] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }

/**************************** Buttons_4 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[4])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(34);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(44);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(54);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[4] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }    

/**************************** Buttons_5 *************************************/    
    if ( PUSHED == DEVICE_control.buttons[5])
    {
        static uint8_t cnt = 0;
        if ( DEVICE_NUMBER_CNT == cnt )
        {
            uint8_t nSize;
            if (POS1 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(35);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS2 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(45);
                bufferUartTx[2] = 0x7f;
            }
            else if (POS3 == DEVICE_control.togglesPos3[0])
            {
                bufferUartTx[0] = 0xb4;
                bufferUartTx[1] = CC(55);
                bufferUartTx[2] = 0x7f;
            }
            nSize = 3;  
            DEVICE_control.buttons[5] = NOT_PUSHED;
            USARTSend(bufferUartTx,nSize);
            cnt=0;
        }
        else
        {
            cnt++;
        }
    }
    
    Delay(DEVICE_DELAY_MS);
  
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
            if (i==0)
            {
              if (index<256)
                {
                   testBuf[index] = DEVICE_GET_CODE_EN(i,nNewCodeEncoders);
                   index++;
                }
                else
                {
                    index=0;
                }
            }
          switch(DEVICE_GET_CODE_EN(i,DEVICE_oldCodeEncoders))
            {
                case 0:
                        {
                            if (2 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = FORWARD;
                                }
                            }
                            else if (1 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = BACKWARD;
                                }
                                
                            }
                        }break;
                case 2:
                        {
                            if (3 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = FORWARD;
                            }
                            else if (0 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = BACKWARD;
                                }                                    
                            
                            }
                        }break;
                case 3:
                        {
                            if (1 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = FORWARD;   
                                }
                                
                            }
                            else if (2 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = BACKWARD;
                                }
                                
                            }
                        }break;
                case 1:
                        {
                            if (0 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                if (2 == i)
                                {
                                    DEVICE_control.encoder[i] = FORWARD;
                                }
                                
                            }
                            else if (3 == DEVICE_GET_CODE_EN(i,nNewCodeEncoders))
                            {
                                DEVICE_control.encoder[i] = BACKWARD;
                            }
                        }break;
            }
        }
        else
        {
            DEVICE_control.encoder[i] = NOT_ROTATION;
        }
    }
    DEVICE_oldCodeEncoders = nNewCodeEncoders;
    
}
// end of DEVICE_GetStatusEncoders()



//**************************************************************************************************
// @Function      DEVICE_GetStatusButtons()
//--------------------------------------------------------------------------------------------------
// @Description   Get status buttons
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.  
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//                
//**************************************************************************************************
static void DEVICE_GetStatusButtons(void)
{
    uint8_t nNewCodeButtons = 0;
    
    nNewCodeButtons = MCP23017_GetPortB();
    for (int i = 0;i<6;i++)
    {
        if (((nNewCodeButtons << i) & 0x80) == 0x80)
        {
            if (flagsAllowSwitchBut[i] == 1)
            {
                flagsAllowSwitchBut[i] = 0;  
                DEVICE_control.buttons[i] = PUSHED;    
            }
        }
        else
        {
            //DEVICE_control.buttons[i] = NOT_PUSHED;
            flagsAllowSwitchBut[i] = 1;
        }
    }
    
    // get status toggle POS3
    switch (nNewCodeButtons & 3)
    {
        case 3 : DEVICE_control.togglesPos3[0] = POS2;break;
        
        case 1 : DEVICE_control.togglesPos3[0] = POS1;break;
        
        case 2 : DEVICE_control.togglesPos3[0] = POS3;break;
    }
    
    // get status toggle POS2
    if ( Bit_SET == GPIO_ReadInputDataBit(MCP23017_PORT_TOGGLES_POS2, MCP23017_PIN_TOGGLES_POS2))
    {
        DEVICE_control.togglesPos2[0] = POS1;
    }
    else
    {
        DEVICE_control.togglesPos2[0] = POS2;
    }
    
    // get status encoder's button NUM8
    if ( Bit_SET == GPIO_ReadInputDataBit(MCP23017_PORT_BUT_ENCOD_NUM8, MCP23017_PIN_BUT_ENCOD_NUM8))
    {
        DEVICE_control.buttons[6] = NOT_PUSHED;
    }
    else
    {
        DEVICE_control.buttons[6] = PUSHED;
    }
    
    // get status encoder's button NUM1
    if ( Bit_SET == GPIO_ReadInputDataBit(MCP23017_PORT_BUT_ENCOD_NUM1, MCP23017_PIN_BUT_ENCOD_NUM1))
    {
        //DEVICE_control.buttons[7] = NOT_PUSHED;
        flagAllowSwitchButEncoderOptic = 1;
    }
    else if (flagAllowSwitchButEncoderOptic)
    {
        flagAllowSwitchButEncoderOptic = 0;
        if (PUSHED == DEVICE_control.buttons[7])
        {
            DEVICE_control.buttons[7] = NOT_PUSHED;
        }
        else
        {
            DEVICE_control.buttons[7] = PUSHED;
        }
      
    }
    
    
}
// end of DEVICE_GetStatusButtons()



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
static void USARTSend(const unsigned char *pucbufferUartTx, uint16_t size)
{
//    while (0 != size)
//    {
//        USART_SendData(USART2, *pucbufferUartTx++);
//        while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
//        {
//        }
//        size--;
//    }
    DMA_Cmd(DMA1_Channel7, DISABLE);
    DMA_ClearFlag( DMA1_FLAG_TC7 );
    DMA_SetCurrDataCounter(DMA1_Channel7, size);
    DMA_Cmd(DMA1_Channel7, ENABLE);
  
}// end of USARTSend()



//**************************************************************************************************
// @Function      Delay
//--------------------------------------------------------------------------------------------------
// @Description   None.
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    time in us
//**************************************************************************************************
void Delay( uint16_t time )
{
	TIM_Cmd(TIM2, DISABLE);
    TIM_SetCounter(TIM2, 0);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_SetAutoreload(TIM2, time);
	//wait
	TIM_Cmd(TIM2, ENABLE);
	while(SET != TIM_GetFlagStatus(TIM2, TIM_FLAG_Update));
	TIM_Cmd(TIM2, DISABLE);
}
// end of Delay()