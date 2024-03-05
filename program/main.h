#ifndef MAIN_H
#define MAIN_H

/*
main.h
contains all needed includes and macros
*/

#define F_CPU 16000000UL
#ifndef __AVR_ATmega1284P__
#define __AVR_ATmega1284P__
#endif

///__biblioteki standardowe
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>

/// __ekran WinCom WG12864D ze sterownikiem KS0108
#include <KS0108.h>
#include <graphic.h>
#include <font5x8.h>
#include <multi_buff.h>

/// FAT FS
#include <diskio.h>
#include <ff.h>
#include <ffconf.h>
#include <rtc.h>

/// LLL
#include <LLL.h>

// Driver
#include <LLL_RetCon.h>

// additional graphics
#include <additional_graphics.h>

//system
#include <base.h>
#include <input.h>

///__makra
#define PREP_TRICK_DDR(x,y) x##y
#define DDR(x) PREP_TRICK_DDR(DDR,x)

#define PREP_TRICK_PORT(x,y) x##y
#define PORT(x) PREP_TRICK_PORT(PORT,x)

#define PREP_TRICK_PIN(x,y) x##y
#define PIN(x) PREP_TRICK_PIN(PIN,x)
#define J(x,y) x##y
#define QUOTE(x) "x"


#endif