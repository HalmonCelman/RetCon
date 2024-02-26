#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <ff.h>

#define R 13*pointMenu //ratio
#define delay(x) timerDelay=x;while(timerDelay);


extern uint8_t pointMenu;
extern unsigned char counter;
extern volatile uint16_t timerDelay;
extern volatile uint16_t timerValue;
extern volatile uint16_t beepCounter;
extern uint8_t res;
extern UINT s1;
extern FATFS fs1;

uint8_t err(uint8_t,char *); // normal error if error occure than it displays it on screen for 1000 ms and returns error code
uint8_t errc(uint8_t,char *); //critic error, if error occure then program will no longer work( function causes infinite loop ),if no error returns 0
void write_message(char *,uint8_t); //writes message on the screen

void init_buffering(void);
void init_fs(void);
void close_fs(void);

// output
void beepOn(void);

#endif