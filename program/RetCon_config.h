#ifndef RETCON_CONFIG_H
#define RETCON_CONFIG_H

#define PREP_TRICK_DDR(x,y) x##y
#define DDR(x) PREP_TRICK_DDR(DDR,x)

#define PREP_TRICK_PORT(x,y) x##y
#define PORT(x) PREP_TRICK_PORT(PORT,x)

#define PREP_TRICK_PIN(x,y) x##y
#define PIN(x) PREP_TRICK_PIN(PIN,x)
///__bindings
// all triggers, bumpers and buttons active high
#define T_L_PIN 1  //trigger left
#define T_L_PORT D

#define T_R_PIN 4  //trigger right
#define T_R_PORT A

#define B_L_PIN 2  //bumper left
#define B_L_PORT D

#define B_R_PIN 5  //left
#define B_R_PORT A

#define HOME_PIN 0  //Home
#define HOME_PORT D

#define SELECT_PIN 2  //Select
#define SELECT_PORT B

#define BUZZ_PIN 3  //buzzer - active high
#define BUZZ_PORT B

// analog joysticks
#define ANALOG_PORT A

#define AN1_X_PIN 0
#define AN1_Y_PIN 1

#define AN2_X_PIN 2
#define AN2_Y_PIN 3

// not connected analog inputs, disabled to minimize power consumption
#define NC1 6
#define NC2 7

#endif