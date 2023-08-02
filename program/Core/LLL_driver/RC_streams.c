#include "RC_streams.h"
#include "LLL_RetCon.h"
#include <multi_buff.h>


void rc_stream_refresh(void){
    GLCD_r;
}

void rc_stream_clear(void){
    GLCD_B_ClearScreen();
}

void rc_stream_set_px(void){
    uint8_t px_x=lll_get();
    uint8_t px_y=lll_get();
    GLCD_B_SetPixel(px_x,px_y);
}

void rc_stream_clr_px(void){
    uint8_t px_x=lll_get();
    uint8_t px_y=lll_get();
    GLCD_B_ClrPixel(px_x,px_y);
}

void rc_stream_write_char(void){
    char charToWrite=lll_get();
    uint8_t p_x=lll_get();
    uint8_t p_y=lll_get();
    GLCD_B_WriteChar(charToWrite,p_x,p_y);
}