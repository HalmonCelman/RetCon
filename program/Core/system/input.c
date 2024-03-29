#include "input.h"
#include <avr/io.h>
#include <RetCon_config.h>

/*
    initializes all interactives in RetCon
*/
void key_init(void){
    // set as input triggers, bumpers and buttons
    DDR(T_L_PORT) &=~ (1<<T_L_PIN);
    DDR(T_R_PORT) &=~ (1<<T_R_PIN);
    DDR(B_L_PORT) &=~ (1<<B_L_PIN);
    DDR(B_R_PORT) &=~ (1<<B_R_PIN);
    DDR(HOME_PORT) &=~ (1<<HOME_PIN);
    DDR(SELECT_PORT) &=~ (1<<SELECT_PIN);

    // without pullup
    PORT(T_L_PORT) &=~ (1<<T_L_PIN);
    PORT(T_R_PORT) &=~ (1<<T_R_PIN);
    PORT(B_L_PORT) &=~ (1<<B_L_PIN);
    PORT(B_R_PORT) &=~ (1<<B_R_PIN);
    PORT(HOME_PORT) &=~ (1<<HOME_PIN);
    PORT(SELECT_PORT) &=~ (1<<SELECT_PIN);

    // buzzer as output
    DDR(BUZZ_PORT) |= (1<<BUZZ_PIN);
    // default off
    PORT(BUZZ_PORT) &=~ (1<<BUZZ_PIN);

    // analog joysticks as input
    DDR(ANALOG_PORT) &=~ ((1<<AN1_X_PIN) | (1<<AN1_Y_PIN) | (1<<AN2_X_PIN) | (1<<AN2_Y_PIN));
    //without pullup
    PORT(ANALOG_PORT) &=~ ((1<<AN1_X_PIN) | (1<<AN1_Y_PIN) | (1<<AN2_X_PIN) | (1<<AN2_Y_PIN));
}

/*
    return buttons data according to buttons.png
*/
uint8_t getButtonsData(void){
    uint8_t tmpVal=0;
    if((PIN(T_L_PORT) & (1<<T_L_PIN))) tmpVal |= (1<<0);
    if((PIN(T_R_PORT) & (1<<T_R_PIN))) tmpVal |= (1<<1);
    if((PIN(B_L_PORT) & (1<<B_L_PIN))) tmpVal |= (1<<2);
    if((PIN(B_R_PORT) & (1<<B_R_PIN))) tmpVal |= (1<<3);
    if((PIN(HOME_PORT) & (1<<HOME_PIN))) tmpVal |= (1<<4);
    if((PIN(SELECT_PORT) & (1<<SELECT_PIN))) tmpVal |= (1<<5);
    return tmpVal;
}