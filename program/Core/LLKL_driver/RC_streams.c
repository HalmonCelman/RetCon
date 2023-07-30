#include "RC_streams.h"
#include "LLKL_RetCon.h"
#include <multi_buff.h>


void rc_stream_refresh(void){
    GLCD_r;
}

void rc_stream_clear(void){
    GLCD_B_ClearScreen();
}

void rc_stream_set_px(void){
    uint8_t px_x=llkl_get();
    uint8_t px_y=llkl_get();
    GLCD_B_SetPixel(px_x,px_y);
}

void rc_stream_clr_px(void){
    uint8_t px_x=llkl_get();
    uint8_t px_y=llkl_get();
    GLCD_B_ClrPixel(px_x,px_y);
}

void rc_stream_write_char(void){
    char charToWrite=llkl_get();
    uint8_t p_x=llkl_get();
    uint8_t p_y=llkl_get();
    GLCD_B_WriteChar(charToWrite,p_x,p_y);
}