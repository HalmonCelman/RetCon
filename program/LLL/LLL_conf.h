#ifndef LLL_TINY_CONF_INCLUDED
#define LLL_TINY_CONF_INCLUDED


///options
#define LLL_DEBUG_MODE 1 //on: 1, off: 0 - default 1
#define LLL_USE_EXTERNAL_MEMORY 1 //if true, external memory will be used - much more memory but this memory will be slower
/*
if LLL is in DEBUG mode it will return errors but may be slower
when DEBUG mode is off then LLL should be faster but won't show errors
*/
///CPU
#define LLL_CPU AVR

///RAM setting - set how many bytes you are giving to fastMeM ( fast Memory Matrix )
#define LLL_FAST_MEM_SIZE 1024

///Command buffer size
#define LLL_COMM_BUFF_SIZE 1024

///Label setting -set how many fast labels you want to use
#define LLL_LABEL_NUMBER 5

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///DANGER ZONE - DON'T CHANGE UNTIL YOU ARE SURE WHAT EXACTLY YOU ARE DOING
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define LLL_FLAG_NUMBER 3

extern const uint8_t LLL_FLAG_MAP[LLL_FLAG_NUMBER];

#endif // LLL_TINY_CONF_INCLUDED
