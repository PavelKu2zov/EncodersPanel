#ifndef GENERAL_MACROS_H
#define GENERAL_MACROS_H



//**************************************************************************************************
// Project Includes
//**************************************************************************************************

// None.



//**************************************************************************************************
// Declarations of global (public) data types
//**************************************************************************************************

// Null pointer
#define NULL_PTR                (0U)

// Returns size of the specified array in elements
#define SIZE_OF_ARRAY(array)    (sizeof(array) / sizeof((array)[0U]))

// Concatenation of two macros
#define PASTER(x, y)            x ## y
#define CONCATENATE(x, y)       PASTER(x, y)

// Byte order definition
#define FIRST_HIGH_BYTE         (0U) // Big-endian
#define FIRST_LOW_BYTE          (1U) // Little-endian

// The function doing nothing definition
#define DoNothing()

// Convert input param "addr", that contains address, to arithmetic pointer
#define ConvertToPtr_8bit(addr)                 ((uint8_t*)(addr))
#define ConvertToPtr_S8bit(addr)                ((int8_t*)(addr))
#define ConvertToPtr_16bit(addr)                ((uint16_t*)(addr))
#define ConvertToPtr_S16bit(addr)               ((int16_t*)(addr))
#define ConvertToPtr_32bit(addr)                ((uint32_t*)(addr))
#define ConvertToPtr_S32bit(addr)               ((S32*)(addr))

// These macros returns value from the specified address
#define GetDataFromAddress_8bit(Address,  Offset)   ((uint8_t)*((uint8_t* FAR)  ((uint32_t)(Address) + (Offset))))
#define GetDataFromAddress_16bit(Address, Offset)   ((uint16_t)*((uint16_t* FAR)((uint32_t)(Address) + (Offset))))
#define GetDataFromAddress_32bit(Address, Offset)   ((uint32_t)*((uint32_t* FAR)((uint32_t)(Address) + (Offset))))

// NIBBLE <-> BYTE <-> WORD <-> DWORD <-> BYTE <-> NIBBLE macro conversion support
#define MAKEBYTE(lowNibble, highNibble) (((uint8_t)(lowNibble) & 0x0FU) | (((uint8_t)(highNibble) & 0x0FU) << 4U))
#define MAKEWORD(lowByte, highByte)     ((uint16_t)(((uint8_t)(lowByte)) | ((uint16_t)((uint8_t)(highByte))) << U8_BIT_QTY))
#define MAKELONG(lowWord, highWord)     ((uint32_t)(((uint16_t)((uint16_t)(lowWord) & 0xFFFFU)) | ((uint32_t)((uint16_t)((uint16_t)(highWord) & 0xFFFFU))) << U16_BIT_QTY))
#define LONIBBLE(b) (((uint8_t)(b)) & 0x0FU)
#define HINIBBLE(b) ((((uint8_t)(b)) & 0xF0U) >> 4U)
#define LOBYTE(w)   ((uint8_t)((uint16_t)(w) & 0x00FFU))
#define HIBYTE(w)   ((uint8_t)((((uint16_t)(w)) >> U8_BIT_QTY) & (uint16_t)0x00FFU))
#define LOWORD(l)   ((uint16_t)((uint32_t)(l) & 0xFFFFU))
#define HIWORD(l)   ((uint16_t)(((uint32_t)(l) >> U16_BIT_QTY) & 0xFFFFU))

// Check, whether value is in the specified range.
// This inequality is UNstrict,
// i.e. LOW and HIGH values are possible (in the specified range).
#define IsValueInRange(LOW, Value, HIGH)     ((((LOW)  <   (Value))    \
                                            || ((LOW)  ==  (Value)))   \
                                            && ((HIGH) >=  (Value)))

// Converts (MHz - frequency) into (Hz - frequency)
#define MHZ_TO_HZ(MHz)        ((MHz) * (1000000UL))
#define HZ_TO_MHZ(Hz)         ((Hz)  / (1000000UL))

// Integer rounding support macro
#define ROUND_TO(nValue, nRoundTo)          (((nValue) / (nRoundTo)) * (nRoundTo))

// ASCII conversion support
// Convert HEX value to ASCII symbol: HEX = {0x0..0xF} -> {'0'..'F'}
#define BIN_TO_ASCII(digit)     (((digit) > 9U) ? ((digit) + 0x37U) : ((digit) + 0x30U))
// Convert ASCII symbol to its HEX value: CHAR = {'0'..'F'} -> {0x0..0xF}
#define ASCII_TO_BIN(symbol)    (((symbol) >= 0x41U) ? ((symbol) - 0x37U) : ((symbol) - 0x30U))

// Find maximum value macro
#define MAX(valueA, valueB)     (((valueA) > (valueB)) ? (valueA) : (valueB))
// Find minimum value macro
#define MIN(valueA, valueB)     (((valueA) < (valueB)) ? (valueA) : (valueB))



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



#endif // #ifndef GENERAL_MACROS_H

//****************************************** end of file *******************************************
