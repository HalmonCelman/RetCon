#include "RC_streams.h"
#include "LLL_RetCon.h"
#include <base.h>
#include <multi_buff.h>

//out
void rc_stream_error(void){
    lll_send_info("STREAM ERROR: ",stream_params[0]);
};

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

void rc_stream_write_char(void){
    GLCD_B_WriteCharAcc(stream_params[2],stream_params[0],stream_params[1]);
};

void rc_stream_stroke_rect(void){
    GLCD_B_Rect(stream_params[0],stream_params[1],stream_params[2],stream_params[3]);
};

void rc_stream_fill_rect(void){
    GLCD_B_FillRect(stream_params[0],stream_params[1],stream_params[2],stream_params[3]);
};

void rc_stream_set_timer(void){
    timerValue = (uint16_t)stream_params[0] + (uint16_t)(stream_params[1]<<8);
};


//in
uint8_t rc_stream_get_timer(void){
    static uint8_t cnt=0;   // internal counter
    if(cnt){
        cnt = 0;
        return (uint8_t)(timerValue>>8);
    }else{
        cnt++;
        return (uint8_t)(timerValue & 0xFF);
    }
    return 0;
};

uint8_t rc_stream_error_in(void){
    lll_send_info("STREAM ERROR IN: ",stream_params[0]);
    return 0;
};