#ifndef ADDITIONAL_GRAPHICS_H
#define ADDITIONAL_GRAPHICS_H

#include <stdint.h>

typedef struct{
char *name; //nazwa
int frame; //nr aktualnej klatki
uint8_t x; //x
uint8_t y; //y
uint8_t w; //szerokosc
uint8_t h; //wysokosc
uint8_t active; //czy aktywna aktualnie
}  animation;


void GLCD_B_Bitmap_SD_exp(char*); //shows exported bitmap from path
void GLCD_Animate_exp(char*); //shows exported animation from file
void GLCD_B_Bitmap_SD(char*); //shows unexported bitmap(from .wbmp file)

void animate(char*); //animate file

#endif