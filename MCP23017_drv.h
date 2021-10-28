//**************************************************************************************************
// @Module        MCP23017
// @Filename      MCP23017_drv.h
//--------------------------------------------------------------------------------------------------
// @Description   Interface of the MCP23017 module.
//                
//--------------------------------------------------------------------------------------------------
// @Version       1.0.0
//--------------------------------------------------------------------------------------------------
// @Date          XX.XX.XXXX
//--------------------------------------------------------------------------------------------------
// @History       Version  Author      Comment
// XX.XX.XXXX     1.0.0    XXX         First release.
//**************************************************************************************************

#ifndef MCP23017_H
#define MCP23017_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// Get data types
#include "compiler.h"

// Get generic definitions
#include "general.h"

// Get configuration of the program module
#include "module_cfg.h"



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// [Description...]
typedef DATA_TYPE MODULE_DATA_TYPE_ZERO;

// [Description...]
typedef enum
{
    MODULE_DATA_TYPE_ONE_CONST_ZERO,  // [Description...]
    MODULE_DATA_TYPE_ONE_CONST_ONE,   // [Description...]
    MODULE_DATA_TYPE_ONE_CONST_TWO,   // [Description...]
    MODULE_DATA_TYPE_ONE_CONST_THREE, // [Description...]
} MODULE_DATA_TYPE_ONE;

// [Description...]
typedef struct MODULE_DATA_TYPE_TWO_struct
{
    DATA_TYPE fieldZero; // [Description...]
    DATA_TYPE fieldOne;  // [Description...]
} MODULE_DATA_TYPE_TWO;



//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// None.


//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// [Description...]
extern DATA_TYPE MODULE_variableZero;

// [Description...]
extern DATA_TYPE MODULE_variableOne;



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// Init MCP23017
extern void MCP23017_Init(void);

// Get value portA
extern uint8_t MCP23017_GetPortA(void);
            
// Get value portB
extern uint8_t MCP23017_GetPortB(void);


#endif // #ifndef MCP23017_H

//****************************************** end of file *******************************************
