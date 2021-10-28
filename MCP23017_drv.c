//**************************************************************************************************
// @Module        MCP23017
// @Filename      MCP23017_drv.c
//--------------------------------------------------------------------------------------------------
// @Platform      PLATFORM_NAME
//--------------------------------------------------------------------------------------------------
// @Compatible    COMPATIBLE_PROCESSOR_MODULE
//--------------------------------------------------------------------------------------------------
// @Description   Implementation of the MCP23017 functionality.
//                
//
//                Abbreviations:
//                  None.
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

// Native header
#include "MCP23017_drv.h"





//**************************************************************************************************
// Verification of the imported configuration parameters
//**************************************************************************************************

//None.

//**************************************************************************************************
// Definitions of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of local (private) data types
//**************************************************************************************************

// [Description...]
typedef DATA_TYPE MODULE_DATA_TYPE_THREE;

// [Description...]
typedef struct MODULE_DATA_TYPE_FOUR_struct
{
    DATA_TYPE fieldZero;
    DATA_TYPE fieldOne;
} MODULE_DATA_TYPE_FOUR;

// [Description...]
typedef union MODULE_DATA_TYPE_FIVE_union
{
    struct fieldZero_struct
    {
        DATA_TYPE fieldZero;
        DATA_TYPE fieldOne;
    } fieldZero;
    
    DATA_TYPE fieldOne;
} MODULE_DATA_TYPE_FIVE;



//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Control register summary bank == 1
// portA
#define MCP23017_IODIRA             (0x00)
#define MCP23017_IPOLA              (0x01)
#define MCP23017_GPINTENA           (0x02)
#define MCP23017_DEFVALA            (0x03)
#define MCP23017_INTCONA            (0x04)
#define MCP23017_IOCON              (0x05)
#define MCP23017_GPPUA              (0x06)
#define MCP23017_INTFA              (0x07)
#define MCP23017_INTCAPA            (0x08)
#define MCP23017_GPIOA              (0x09)
#define MCP23017_OLATA              (0x0A)   

//portB
#define MCP23017_IODIRB             (0x10)
#define MCP23017_IPOLB              (0x11)
#define MCP23017_GPINTENB           (0x12)
#define MCP23017_DEVVALB            (0x13)
#define MCP23017_INTCONB            (0x14)
#define MCP23017_IOCON              (0x15)
#define MCP23017_GPPUB              (0x16)
#define MCP23017_INTFB              (0x17)
#define MCP23017_INTCAPB            (0x18)
#define MCP23017_GPIOB              (0x19)
#define MCP23017_OLATB              (0x1A)   



//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// None.


//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

// [Description...]
static DATA_TYPE MODULE_FunctionTwo(DATA_TYPE parameterZero,
                                    DATA_TYPE parameterOne);

// [Description...]
static DATA_TYPE MODULE_FunctionThree(DATA_TYPE parameterZero,
                                      DATA_TYPE parameterOne,
                                      DATA_TYPE parameterTwo);



//**************************************************************************************************
//==================================================================================================
// Definitions of global (public) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      MCP23017_Init()
//--------------------------------------------------------------------------------------------------
// @Description   Initialization MCP23017
//--------------------------------------------------------------------------------------------------
// @Notes         None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
void MCP23017_Init(void);
{
    // Init GPIO for i2c
    GPIO_InitTypeDef GPIO_InitStruct
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_SDA | MCP23017_PIN_SCL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_Init(MCP23017_PORT, &GPIO_InitStruct);
    
    // Init i2c
    I2C_DeInit(MCP23017_I2C);
    I2C_InitTypeDef I2C_InitStruct;
    I2C_InitStruct.I2C_ClockSpeed = MCP23017_I2C_ClockSpeed;
    I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_OwnAddress1 = 0;
    I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init(MCP23017_I2C, &I2C_InitStruct);
    
    
    
} // end of MCP23017_Init()



//**************************************************************************************************
// @Function      MODULE_FunctionOne()
//--------------------------------------------------------------------------------------------------
// @Description   [description...]
//--------------------------------------------------------------------------------------------------
// @Notes
//--------------------------------------------------------------------------------------------------
// @ReturnValue   returnValue - [description...]
//--------------------------------------------------------------------------------------------------
// @Parameters    parameterZero - [description...]
//                parameterOne  - [description...]
//**************************************************************************************************
DATA_TYPE MODULE_FunctionOne(DATA_TYPE parameterZero,
                             DATA_TYPE parameterOne)
{
    DATA_TYPE returnValue;
    
    // [Description...]
    DATA_TYPE idx = 0;
    for ( ; idx < MAX; idx++)
    {
        arrayResult[idx] = arrayInitial[idx];
    }
    
    return returnValue;
    
} // end of MODULE_FunctionOne()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      MODULE_FunctionTwo()
//--------------------------------------------------------------------------------------------------
// @Description   [description...]
//--------------------------------------------------------------------------------------------------
// @Notes
//--------------------------------------------------------------------------------------------------
// @ReturnValue   returnValue - [description...]
//--------------------------------------------------------------------------------------------------
// @Parameters    parameterZero - [description...]
//                parameterOne  - [description...]
//**************************************************************************************************
static void MCP23017_WriteReg(uint8_t reg,
                              uint8_t value)
{
    DATA_TYPE returnValue;
    
    // [Description...]
    switch (expression)
    {
        case CASE_ONE:
            caseOneCnt++;
            break;

        case CASE_TWO:
            caseTwoCnt++;
            break;

        default:
            caseDefaultCnt++;
            break;
    } // end of switch (expression)
    
    return returnValue;
    
} // end of MCP23017_WriteReg()



//**************************************************************************************************
// @Function      MODULE_FunctionThree()
//--------------------------------------------------------------------------------------------------
// @Description   [description...]
//--------------------------------------------------------------------------------------------------
// @Notes
//--------------------------------------------------------------------------------------------------
// @ReturnValue   returnValue - [description...]
//--------------------------------------------------------------------------------------------------
// @Parameters    parameterZero - [description...]
//                parameterOne  - [description...]
//                parameterTwo  - [description...]
//**************************************************************************************************
static DATA_TYPE MODULE_FunctionThree(DATA_TYPE parameterZero,
                                      DATA_TYPE parameterOne,
                                      DATA_TYPE parameterTwo)
{
    DATA_TYPE returnValue;
    
    // [Place code here]
    
    return returnValue;
    
} // end of MODULE_FunctionThree()



//****************************************** end of file *******************************************
