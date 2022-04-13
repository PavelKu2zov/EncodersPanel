//**************************************************************************************************
// @Module        MCP23017
// @Filename      MCP23017_cfg.h
//--------------------------------------------------------------------------------------------------
// @Description   Configuration of the required functionality of the MCP23017 module.
//                
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          XX.XX.XXXX
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// XX.XX.XXXX     1.0.0    XXX         First release.
//**************************************************************************************************

#ifndef MCP23017_CFG_H
#define MCP23017_CFG_H



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// User can specify port nRST
#define MCP23017_PORT_RST   					(GPIOB)

// User can specify port toggles pos2
#define MCP23017_PORT_TOGGLES_POS2   		    (GPIOB)

// User can specify pin toggles pos2
#define MCP23017_PIN_TOGGLES_POS2   		    (GPIO_Pin_8)

// User can specify pin nRST
#define MCP23017_PIN_nRST                       (GPIO_Pin_5)

// User can specify port for encoder's button NUM8
#define MCP23017_PORT_BUT_ENCOD_NUM8            (GPIOB)

// User can specify port for encoder's button NUM1
#define MCP23017_PORT_BUT_ENCOD_NUM1            (GPIOB)

// User can specify pin for encoder's button NUM8
#define MCP23017_PIN_BUT_ENCOD_NUM8             (GPIO_Pin_9)

// User can specify pin for encoder's button NUM1
#define MCP23017_PIN_BUT_ENCOD_NUM1             (GPIO_Pin_7)

// User can specify OPCODE
#define MCP23017_OPCODE                         (0x40)

// User can specify port
#define MCP23017_PORT_I2C                       (GPIOB)

// User can specify pin SDA
#define MCP23017_PIN_SDA                        (GPIO_Pin_11)

// User can specify pin SCL
#define MCP23017_PIN_SCL                        (GPIO_Pin_10)

// User can specify i2cx
#define MCP23017_I2C                            (I2C2)

// User can specify I2C clock speed
#define MCP23017_I2C_ClockSpeed                 (600000)

#endif // #ifndef MCP23017_CFG_H

//****************************************** end of file *******************************************
