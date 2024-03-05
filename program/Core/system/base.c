#include <avr/io.h>
#include <avr/interrupt.h>
#include "base.h"
#include <multi_buff.h>
#include <KS0108.h>
#include <mmc_spi.h>
#include <LLL_RetCon.h>
#include <config.h>
#include <RetCon_config.h>

uint8_t pointMenu;
uint8_t counter;
volatile uint8_t beepCounter;
volatile uint16_t timerDelay;
volatile uint16_t timerValue;
uint8_t res;
UINT s1;
FATFS fs1;

/*
turns on buzzer with generator,
set until beep counter reaches 0, or if it is already zero until beepOff()
*/
void beepOn(void){
	PORT(BUZZ_PORT) |= (1<<BUZZ_PIN);
}

/*
turns off buzzer
*/
static void beepOff(void){
	PORT(BUZZ_PORT) &=~ (1<<BUZZ_PIN);
}

void init_buffering(void){
	timerDelay=0;
	counter=0;
	///->multiplexing    ( includes also mmc_disktimerproc )                          ///<-przy zmianie mikrokontrolera lub czestotliwosci zwrócic uwage
    TCCR0A = (1<<WGM01); //CTC mode, 64 prescaler 1000Hz
    TCCR0B  = (1<<CS01)  | (1<<CS00);
    OCR0A =249;// div by 25
    TIMSK0 |=(1<<1);//enable compare match
    sei();//enable interrupts
}

void init_fs(void){
	/// 1.init disk
	res=1;
	while(res){
		res=err(disk_initialize(0),"Disk 404 ");
	}
	///end 1
	///2.mount
	errc(f_mount(&fs1, "", 0),"MountERR");
}

void close_fs(void){
	f_unmount("");
	///end 2
}

ISR(TIMER0_COMPA_vect){
counter++;
if(beepCounter){
	beepCounter--;
	if(!beepCounter){
		beepOff();
	}
} 
if(timerValue) timerValue--; //timer for set and getTimer streams
if(timerDelay) timerDelay--; //accurate delay
if(counter>=10){ //for 16MHz -> 100Hz
    FatFs_clock(); //for FatFS
    counter=0;
    if(bufferSwitch){
        bufferSwitch=0;

        int i,j;
        for(j = 0; j < 8; j++){
            GLCD_GoTo(0,j);
            for(i = 0; i < 128; i++)
                GLCD_WriteData(GLCD_Buffer[j*128+i]);
        }
    }
}
}


uint8_t err(uint8_t result,char * com){
	#if SHOW_ON_SCREEN
		if(result){
		write_message(com,result);
		}
	#endif
return result;
}

uint8_t errc(uint8_t result,char * com){
if(result){
	#if SHOW_ON_SCREEN
		write_message(com,result);
	#endif
while(1);
}
return result;
}

void write_message(char * message,uint8_t number){
	GLCD_B_ClearScreen();
	GLCD_B_WriteString(message,0,0);
	GLCD_B_WriteChar((char)(number+48),0,1);
	GLCD_r;
	delay(100);
}
