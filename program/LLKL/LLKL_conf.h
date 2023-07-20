#ifndef LLKL_TINY_CONF_INCLUDED
#define LLKL_TINY_CONF_INCLUDED


///MODE
#define LLKL_DEBUG_MODE 1  //on: 1, off: 0 - default 1
/*
if LLKL is in DEBUG mode it will return errors but may be slower
when DEBUG mode is off then LLKL should be faster but won't show errors
*/
///CPU
#define LLKL_CPU AVR

///RAM setting - set how many bytes you are giving to fastMeM ( fast Memory Matrix )
#define LLKL_FAST_MEM_SIZE 1024

///Command buffer size
#define LLKL_COMM_BUFF_SIZE 1024

///Label setting -set how many fast labels you want to use
#define LLKL_LABEL_NUMBER 5

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///DANGER ZONE - DON'T CHANGE UNTIL YOU ARE SURE WHAT EXACTLY YOU ARE DOING
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define LLKL_FLAG_NUMBER 3

extern uint8_t LLKL_FLAG_MAP[LLKL_FLAG_NUMBER];

#endif // LLKL_TINY_CONF_INCLUDED
