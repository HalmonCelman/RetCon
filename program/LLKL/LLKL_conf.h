#ifndef LLKL_TINY_CONF_INCLUDED
#define LLKL_TINY_CONF_INCLUDED

///CPU
#define LLKL_CPU AVR
/// include section
#include "../LLKL_drv/llkl_atmega1284p.h"

///RAM setting - set how many bytes you are giving to RAM memory ( fastMeM )
#define LLKL_RAM_SIZE 1024
///Maximum number of 8bit parameters in function
#define LLKL_MAX_PARAM_NUMBER 256


#endif // LLKL_TINY_CONF_INCLUDED
