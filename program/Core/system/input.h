#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

extern uint8_t joysticks[4];

void key_init(void); //initialize keys
uint8_t getButtonsData(void);

void triggerADC(void);

#endif