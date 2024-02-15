#include "RC_streams.h"
#include "LLL_RetCon.h"
#include <multi_buff.h>

//out
void rc_stream_refresh(void){
    GLCD_r;
};

void rc_stream_clear(void){
    GLCD_B_ClearScreen();
};

void rc_stream_set_px(void){
    GLCD_B_SetPixel(stream_params[0],stream_params[1]);
};

void rc_stream_clr_px(void){
    GLCD_B_ClrPixel(stream_params[0],stream_params[1]);
};

void rc_stream_write_char(void){ // TBD - not working GLCD_B_WriteChar?
    GLCD_B_WriteChar('A',64,32);
};

void rc_stream_stroke_rect(void){
    GLCD_B_Rect(stream_params[0],stream_params[1],stream_params[2],stream_params[3]);
};

void rc_stream_fill_rect(void){
    GLCD_B_FillRect(stream_params[0],stream_params[1],stream_params[2],stream_params[3]);
};

void rc_stream_set_timer(void){
    // TBD
};


//in
void rc_stream_get_timer(void){
    // TBD
};
