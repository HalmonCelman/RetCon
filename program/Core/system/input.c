#include "input.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <RetCon_config.h>

#define ADMUX_SETTINGS ((1<<REFS0) | (1<<ADLAR)) // AREF connected to AVCC, left adjust(8 bit)

const uint8_t adcSrc[4] = {  // look up table for adc sources
    AN1_X_PIN,
    AN1_Y_PIN,
    AN2_X_PIN,
    AN2_Y_PIN
};

uint8_t adcSrcCnt=0;
uint8_t joysticks[4]; // keeps 8bit value of joysticks 
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
    PIN(ANALOG_PORT) &=~ ((1<<AN1_X_PIN) | (1<<AN1_Y_PIN) | (1<<AN2_X_PIN) | (1<<AN2_Y_PIN));

    adcSrcCnt = 0;
    ADMUX = ADMUX_SETTINGS; 
    ADCSRA = (1<<ADEN) | (1<<ADIE) | (ADPS2)| (ADPS1) | (ADPS0); // ADC ON, Interrupt ON, prescaler 128

    DIDR0 = (1<<NC1) | (1<<NC2);
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


void triggerADC(void){
    ADMUX = (1<<REFS0) | (1<<ADLAR) | adcSrc[adcSrcCnt];
    ADCSRA |= (1<<ADSC);
}

ISR(ADC_vect){
    joysticks[adcSrcCnt] = ADCH;
    adcSrcCnt = (adcSrcCnt == 3)? 0 : adcSrcCnt+1;
}