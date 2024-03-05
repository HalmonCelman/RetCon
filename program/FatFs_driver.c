#include <stdint.h>
#include <avr/io.h>

#define SCK 7
#define MISO 6
#define MOSI 5
#define CS 0 //PORTA

/*
 set CS pin to HIGH state - 3,3V 
*/
void FatFs_CS_HIGH(void){
    PORTA|=(1<<CS);
}

/*
 set CS pin to LOW state - 3,3V 
*/
void FatFs_CS_LOW(void){
    PORTA &=~ (1<<CS);
}

/*
Initialize all pins and SPI here
*/
void FatFs_power_on()(void)
{
    DDRB |= (1<<MOSI)|(1<<SCK)|(1<<PB4); //SS output to working SPI
    DDRA |= (1<<CS);
	DDRB &=~ (1<<MISO);
    PORTB |= (1<<MOSI);
    PORTA &=~ (1<<CS);
	/* Enable SPI module with SPI2X */
    SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPI2X);
}

/*
Turn off spi and pins here
*/
void FatFs_power_off (void)
{
	/* Disable SPI function */
	SPCR &=~ (1<<SPE) | (1<<MSTR)|(1<<SPI2X);

	PORTA|=(1<<CS);
}

uint8_t FatFs_SPI_SendRcv(uint8_t data){
    SPDR = data;
    while(!(SPSR & (1<<7)));
    return SPDR;
}