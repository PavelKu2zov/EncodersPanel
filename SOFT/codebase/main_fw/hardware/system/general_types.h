#ifndef GENERAL_TYPES_H
#define GENERAL_TYPES_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// True/False definition
#ifndef FALSE
#define FALSE               (0U)
#endif
#ifndef TRUE
#define TRUE                (1U)
#endif

// On/Off definition
#ifndef OFF
#define OFF                 (0U)
#endif
#ifndef ON
#define ON                  (1U)
#endif

// Logical signal state definitions
#ifndef LOGIC_0
#define LOGIC_0             (0U)
#endif
#ifndef LOGIC_1
#define LOGIC_1             (1U)
#endif

// Development error definitions
typedef enum DEV_ERROR_enum
{
    DEV_ERROR_NOT_INIT      = (uint8_t)0,   // Program module is not initialized
    DEV_ERROR_ALREADY_INIT  = (uint8_t)1,   // Program module already initialized
    DEV_ERROR_PARAM_0       = (uint8_t)2,   // Parameter number 0 is out of range
    DEV_ERROR_PARAM_1       = (uint8_t)3,   // Parameter number 1 is out of range
    DEV_ERROR_PARAM_2       = (uint8_t)4,   // Parameter number 2 is out of range
    DEV_ERROR_PARAM_3       = (uint8_t)5,   // Parameter number 3 is out of range
    DEV_ERROR_PARAM_4       = (uint8_t)6,   // Parameter number 4 is out of range
    DEV_ERROR_PARAM_5       = (uint8_t)7,   // Parameter number 5 is out of range
    DEV_ERROR_PARAM_6       = (uint8_t)8,   // Parameter number 6 is out of range
    DEV_ERROR_PARAM_7       = (uint8_t)9,   // Parameter number 7 is out of range
    DEV_ERROR_PARAM_8       = (uint8_t)10,  // Parameter number 8 is out of range
    DEV_ERROR_PARAM_9       = (uint8_t)11,  // Parameter number 9 is out of range
    DEV_ERROR_FUNC_NOT_SUPP = (uint8_t)12,  // Function is not supported

    DEV_ERROR_LAST          = (uint8_t)128 // The last standard development error definition

} DEV_ERROR;

// Runtime error definitions
typedef enum RT_ERROR_enum
{
    RT_ERROR_NULL_PTR           = (uint8_t)0,  // Null pointer
    RT_ERROR_RX_FIFO_OVERFLOW   = (uint8_t)1,  // RX FIFO overflow attempt occurred
    RT_ERROR_TX_FIFO_OVERFLOW   = (uint8_t)2,  // TX FIFO overflow attempt occurred
    RT_ERROR_RX_OVERRUN         = (uint8_t)3,  // RX buffer overrun occurred
    RT_ERROR_TX_OVERRUN         = (uint8_t)4,  // TX buffer overrun occurred
    RT_ERROR_BUSY               = (uint8_t)5,  // Resource is busy

    RT_ERROR_LAST               = (uint8_t)128 // The last standard runtime error definition

} RT_ERROR;

// Standard result type
typedef enum STD_RESULT_enum
{
    RESULT_OK     = (uint8_t)0U, // Function succeeded
    RESULT_NOT_OK = (uint8_t)1U  // Function not succeeded

} STD_RESULT;

// Board channel status definitions
typedef enum IO_STATUS_enum
{
    IO_STATUS_NOT_APPLICABLE     = (uint8_t)0,    // Channel status is not applicable
    IO_STATUS_NO_FAILURE         = (uint8_t)1,    // Channel state is OK
    IO_STATUS_FAULT_UNKNOWN      = (uint8_t)2,    // Channel state is unknown fault
    IO_STATUS_SHRT_CIRC_BAT      = (uint8_t)3,    // Short circuit to bat
    IO_STATUS_OPEN_LOAD          = (uint8_t)4,    // Open load
    IO_STATUS_SHRT_CIRC_GND      = (uint8_t)5,    // Short circuit to ground in on
    IO_STATUS_OVER_VOLTAGE       = (uint8_t)6,    // Over voltage
    IO_STATUS_UNDER_VOLTAGE      = (uint8_t)7,    // Under voltage
    IO_STATUS_OVER_CURRENT       = (uint8_t)8,    // Over current
    IO_STATUS_UNDER_CURRENT      = (uint8_t)9,    // Under current
    IO_STATUS_OVER_TEMPERATURE   = (uint8_t)10,   // Over temperature

    IO_STATUS_LAST               = (uint8_t)128   // The last status definitions

} IO_STATUS;



// Physical values types

// Voltage
// Resolution: 1  millivolts / bit,   Offset: 0 volts,   Range: 0 - 65.535 volts
typedef uint16_t U16_PHYS_VOLT_1MV;
// Resolution: 10 millivolts / bit,   Offset: 0 volts,   Range: 0 - 655.35 volts
typedef uint16_t U16_PHYS_VOLT_10MV;
// Resolution: 1  millivolts / bit,   Offset: 0 volts,   Range: -32.767 - 32.768 volts
typedef int16_t S16_PHYS_VOLT_1MV;

// Amperage
// Resolution: 1  milliamps / bit,    Offset: 0 amps,   Range: 0 - 65.535 amps
typedef uint16_t U16_PHYS_AMP_1MA;
// Resolution: 10 milliamps / bit,    Offset: 0 amps,   Range: 0 - 655.35 amps
typedef uint16_t U16_PHYS_AMP_10MA;
// Resolution: 1  milliamps / bit,    Offset: 0 amps,   Range: -32.767 - 32.768 amps
typedef int16_t S16_PHYS_AMP_1MA;

// Temperature
// Resolution: 1 degrees / bit,    Offset: 0 deg,   Range: 0 - 255 deg
typedef uint8_t  U8_PHYS_TEMP_1DEG;
// Resolution: 1 degrees / bit,    Offset: 0 deg,   Range: -127 - 128 deg
typedef int8_t  S8_PHYS_TEMP_1DEG;
// Resolution: 1 degrees / bit,    Offset: 0 deg,   Range: -32767 - 32768 deg
typedef int16_t S16_PHYS_TEMP_1DEG;
// Resolution: 0.1 degrees / bit,  Offset: 0 deg,   Range: -3276.7 - 3276.8 deg
typedef int16_t S16_PHYS_TEMP_01DEG;
// Resolution: 1 degrees / bit,    Offset: 0 deg,   Range: 0 - 65535 deg
typedef uint16_t U16_PHYS_TEMP_1DEG;
// Resolution: 0.1 degrees / bit,  Offset: 0 deg,   Range: 0 - 6553.5 deg
typedef uint16_t U16_PHYS_TEMP_01DEG;

// Pressure
// Resolution: 10 kpa / bit,       Offset: 0 kpa,   Range: 0 - 2550 kpa
typedef uint8_t U8_PHYS_PRESS_10KPA;
// Resolution: 1 kpa / bit,        Offset: 0 kpa,   Range: 0 - 65535 kpa
typedef uint16_t U16_PHYS_PRESS_1KPA;
// Resolution: 0.1 kpa / bit,      Offset: 0 kpa,   Range: 0 - 6553.5 kpa
typedef uint16_t U16_PHYS_PRESS_01KPA;

// Signal strength
// Resolution: 1 dBm / bit,        Offset: 0 dBm,   Range: -127 - 128 dBm
typedef int8_t S8_PHYS_SS_1DBM;
// Resolution: 0.1 dBm / bit,      Offset: 0 dBm,   Range: -3276.7 - 3276.8 dBm
typedef int16_t S16_PHYS_SS_01DBM;




//**************************************************************************************************
// Definitions of global (public) constants
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) variables
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) functions
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of interrupt service routines
//**************************************************************************************************

// None.



#endif // #ifndef GENERAL_TYPES_H

//****************************************** end of file *******************************************
