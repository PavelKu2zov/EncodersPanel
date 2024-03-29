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
//                  MCP23017_Init
//                  MCP23017_GetPortA
//                  MCP23017_GetPortB    
//
//                Local (private) functions:
//                  MCP23017_WriteReg
//                  MCP23017_ReadReg
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

// None.


//**************************************************************************************************
// Definitions of local (private) constants
//**************************************************************************************************

// Control register summary bank == 0
#define MCP23017_IODIRA             (0x00)
#define MCP23017_IODIRB             (0x01)
#define MCP23017_IPOLA              (0x02)
#define MCP23017_IPOLB              (0x03)
#define MCP23017_GPINTENA           (0x04)
#define MCP23017_GPINTENB           (0x05)
#define MCP23017_DEFVALA            (0x06)
#define MCP23017_DEVVALB            (0x07)
#define MCP23017_INTCONA            (0x08)
#define MCP23017_INTCONB            (0x09)
#define MCP23017_IOCON              (0x0A)
//#define MCP23017_IOCON              (0x0B)
#define MCP23017_GPPUA              (0x0C)
#define MCP23017_GPPUB              (0x0D)
#define MCP23017_INTFA              (0x0E)
#define MCP23017_INTFB              (0x0F)
#define MCP23017_INTCAPA            (0x10)
#define MCP23017_INTCAPB            (0x11)
#define MCP23017_GPIOA              (0x12)
#define MCP23017_GPIOB              (0x13)
#define MCP23017_OLATA              (0x14)   
#define MCP23017_OLATB              (0x15) 


//**************************************************************************************************
// Definitions of static global (private) variables
//**************************************************************************************************

// None.


//**************************************************************************************************
// Declarations of local (private) functions
//**************************************************************************************************

static void MCP23017_WriteReg(const uint8_t reg,
                              const uint8_t data);

static uint8_t MCP23017_ReadReg(const uint8_t reg);

static void MCP23017_Reset(void);

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
void MCP23017_Init(void)
{
    // Init GPIO for nRST
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_nRST;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(MCP23017_PORT_RST, &GPIO_InitStruct);
	
    // Init GPIO for toggles POS2
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_TOGGLES_POS2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(MCP23017_PORT_TOGGLES_POS2, &GPIO_InitStruct);
    
    // Init GPIO for button encoder's NUM8
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_BUT_ENCOD_NUM8;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(MCP23017_PORT_BUT_ENCOD_NUM8, &GPIO_InitStruct);
    
    // Init GPIO for button encoder's NUM1
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_BUT_ENCOD_NUM1;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(MCP23017_PORT_BUT_ENCOD_NUM1, &GPIO_InitStruct);
    
	// Init GPIO for i2c
    GPIO_InitStruct.GPIO_Pin = MCP23017_PIN_SDA | MCP23017_PIN_SCL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_Init(MCP23017_PORT_I2C, &GPIO_InitStruct);
    
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
    
    I2C_Cmd(MCP23017_I2C, ENABLE);
	
	// RESET MCP23017
	MCP23017_Reset();
	
    // Configuration ports - input
    MCP23017_WriteReg(MCP23017_IODIRA,0xff);
    MCP23017_WriteReg(MCP23017_IODIRB,0xff);   

	// set pull-up resistor 		
    MCP23017_WriteReg(MCP23017_GPPUA,0xff);
    MCP23017_WriteReg(MCP23017_GPPUB,0xff);
	
} // end of MCP23017_Init()



//**************************************************************************************************
//==================================================================================================
// Definitions of local (private) functions
//==================================================================================================
//**************************************************************************************************



//**************************************************************************************************
// @Function      MCP23017_GetPortA()
//--------------------------------------------------------------------------------------------------
// @Description   Get value Port A
//--------------------------------------------------------------------------------------------------
// @Notes		  None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Value of Port A
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
uint8_t MCP23017_GetPortA(void)
{
    return MCP23017_ReadReg(MCP23017_GPIOA);
	//return MCP23017_ReadReg(MCP23017_IODIRA);
	
} // end of MCP23017_GetPortA()



//**************************************************************************************************
// @Function      MCP23017_GetPortB()
//--------------------------------------------------------------------------------------------------
// @Description   Get value Port B
//--------------------------------------------------------------------------------------------------
// @Notes		  None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   Value of Port B
//--------------------------------------------------------------------------------------------------
// @Parameters    None.
//**************************************************************************************************
uint8_t MCP23017_GetPortB(void)
{
    return MCP23017_ReadReg(MCP23017_GPIOB);
} // end of MCP23017_GetPortB()



//**************************************************************************************************
// @Function      MCP23017_WriteReg()
//--------------------------------------------------------------------------------------------------
// @Description   Write one byte in reg
//--------------------------------------------------------------------------------------------------
// @Notes		  None.
//--------------------------------------------------------------------------------------------------
// @ReturnValue   None.
//--------------------------------------------------------------------------------------------------
// @Parameters    reg - device register
//                data  - data to write in reg
//**************************************************************************************************
static void MCP23017_WriteReg(const uint8_t reg,
                              const uint8_t data)
{
    I2C_GenerateSTART(MCP23017_I2C, ENABLE);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_MODE_SELECT));//EV5
		
	// Send OPCODE
	I2C_Send7bitAddress(MCP23017_I2C, MCP23017_OPCODE, I2C_Direction_Transmitter);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); // EV6
	
	// Send ADDR Reg
	I2C_SendData(MCP23017_I2C, reg);
	
    while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8_2
	
	// Send data
	I2C_SendData(MCP23017_I2C, data);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8_2
	
	I2C_GenerateSTOP(MCP23017_I2C, ENABLE);
    
} // end of MCP23017_WriteReg()



//**************************************************************************************************
// @Function      MCP23017_ReadReg()
//--------------------------------------------------------------------------------------------------
// @Description   Read one byte from reg
//--------------------------------------------------------------------------------------------------
// @Notes		  None.	
//--------------------------------------------------------------------------------------------------
// @ReturnValue   value from reg
//--------------------------------------------------------------------------------------------------
// @Parameters    reg - device register
//**************************************************************************************************
static uint8_t MCP23017_ReadReg(const uint8_t reg)
{
	uint8_t data;
	
	I2C_AcknowledgeConfig(MCP23017_I2C, DISABLE);
	
	I2C_GenerateSTART(MCP23017_I2C, ENABLE);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_MODE_SELECT));//EV5
		
	// Send OPCODE
	I2C_Send7bitAddress(MCP23017_I2C, MCP23017_OPCODE, I2C_Direction_Transmitter);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)); // EV6
	
	// Send ADDR Reg
	I2C_SendData(MCP23017_I2C, reg);
	
    while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED));//EV8_2
	
	// Repeated start
	I2C_GenerateSTART(MCP23017_I2C, ENABLE);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_MODE_SELECT));//EV5
	
	// Send OPCODE
	I2C_Send7bitAddress(MCP23017_I2C, MCP23017_OPCODE, I2C_Direction_Receiver);
	
	while(!I2C_CheckEvent(MCP23017_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED));//EV7
    data = I2C_ReceiveData(MCP23017_I2C);
	I2C_GenerateSTOP(MCP23017_I2C, ENABLE);
    
	return data;
	
} // end of MCP23017_ReadReg()



//**************************************************************************************************
// @Function      MCP23017_Reset()
//--------------------------------------------------------------------------------------------------
// @Description   Read one byte from reg
//--------------------------------------------------------------------------------------------------
// @Notes		  None.	
//--------------------------------------------------------------------------------------------------
// @ReturnValue   value from reg
//--------------------------------------------------------------------------------------------------
// @Parameters    reg - device register
//**************************************************************************************************
static void MCP23017_Reset(void)
{
	GPIO_SetBits(MCP23017_PORT_RST, MCP23017_PIN_nRST);
	
	for (int i=0;i<0xfff;i++);
	
	GPIO_ResetBits(MCP23017_PORT_RST, MCP23017_PIN_nRST);
	
	for (int i=0;i<0xfff;i++);
	
	GPIO_SetBits(MCP23017_PORT_RST, MCP23017_PIN_nRST);
	
} // end of MCP23017_Reset()

//****************************************** end of file *******************************************
