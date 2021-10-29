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

// User can specify OPCODE
#define MCP23017_OPCODE                         (0x40)

// User can specify port
#define MCP23017_PORT                           (GPIOB)

// User can specify pin SDA
#define MCP23017_PIN_SDA                        (GPIO_Pin_11)

// User can specify pin SCL
#define MCP23017_PIN_SCL                        (GPIO_Pin_10)

// User can specify i2cx
#define MCP23017_I2C                            (I2C2)

// User can specify I2C clock speed
#define MCP23017_I2C_ClockSpeed                 (100000)

#endif // #ifndef MCP23017_CFG_H

//****************************************** end of file *******************************************
