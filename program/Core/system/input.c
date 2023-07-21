#include "input.h"
#include <avr/io.h>

void key_init(void){
DDRB|=(1<<4);
}