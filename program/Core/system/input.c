#include "input.h"
#include <avr/io.h>
#include <RetCon_config.h>

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
}