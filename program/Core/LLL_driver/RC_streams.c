#include "RC_streams.h"
#include "LLL_RetCon.h"
#include <base.h>
#include <multi_buff.h>

// output stream


void rc_stream_refresh(void){
    #if DEBUG_MODE
        lll_send_info("Refreshing ",0);
    #endif
    GLCD_r;
}

void rc_stream_clear(void){
    #if DEBUG_MODE
        lll_send_info("Clearing Screen ",0);
    #endif
    GLCD_B_ClearScreen();
}

void rc_stream_set_px(uint32_t first_reg){
    uint8_t px_x=LLL_load_mem(first_reg++);
    uint8_t px_y=LLL_load_mem(first_reg);
    #if DEBUG_MODE
        lll_send_info("Px set x:",px_x);
        lll_send_info("Px set y:",px_y);
    #endif
    GLCD_B_SetPixel(px_x,px_y);
}

void rc_stream_clr_px(uint32_t first_reg){
    uint8_t px_x=LLL_load_mem(first_reg++);
    uint8_t px_y=LLL_load_mem(first_reg);
    #if DEBUG_MODE
        lll_send_info("Px clr x:",px_x);
        lll_send_info("Px clr y:",px_y);
    #endif
    GLCD_B_ClrPixel(px_x,px_y);
}

void rc_stream_write_char(uint32_t first_reg){
    char charToWrite=LLL_load_mem(first_reg++);
    uint8_t p_x=LLL_load_mem(first_reg++);
    uint8_t p_y=LLL_load_mem(first_reg);
    #if DEBUG_MODE
        lll_send_info("Write char x:",p_x);
        lll_send_info("Write char y:",p_y);
        lll_send_info("Write char:",charToWrite);
    #endif
    GLCD_B_WriteChar(charToWrite,p_x,p_y);
}

void rc_stream_set_timer(uint32_t first_reg){
    uint16_t timVal=(LLL_load_mem(first_reg)<<8)+LLL_load_mem(first_reg+1);
    #if DEBUG_MODE
        lll_send_info("Set timer val: ",timVal);
    #endif
    timerDelay=timVal;
}


void rc_stream_stroke_rect(uint32_t first_reg){
    uint8_t x,y,xw,yw;
    x=LLL_load_mem(first_reg++);
    y=LLL_load_mem(first_reg++);
    xw=LLL_load_mem(first_reg++);
    yw=LLL_load_mem(first_reg);

    #if DEBUG_MODE
        lll_send_info("Stroke Rect x:",x);
        lll_send_info("Stroke Rect y:",y);
        lll_send_info("Stroke Rect x width:",xw);
        lll_send_info("Stroke Rect y width:",yw);
    #endif

    GLCD_B_Rect(x,y,xw,yw);
}

void rc_stream_fill_rect(uint32_t first_reg){
    uint8_t x,y,xw,yw;
    x=LLL_load_mem(first_reg++);
    y=LLL_load_mem(first_reg++);
    xw=LLL_load_mem(first_reg++);
    yw=LLL_load_mem(first_reg);

    #if DEBUG_MODE
        lll_send_info("Fill Rect x:",x);
        lll_send_info("Fill Rect y:",y);
        lll_send_info("Fill Rect x width:",xw);
        lll_send_info("Fill Rect y width:",yw);
    #endif

    GLCD_B_FillRect(x,y,xw,yw);
}

// input stream

void rc_stream_get_timer(uint32_t first_reg){
    uint8_t timVal1=(uint8_t)(timerDelay>>8);
    uint8_t timVal2=(uint8_t)(timerDelay & 0xFF);
    #if DEBUG_MODE
        lll_send_info("Get timer val1: ",timVal1);
        lll_send_info("Get timer val2: ",timVal2);
    #endif
    
    LLL_save_mem(first_reg++,timVal1);
    LLL_save_mem(first_reg,timVal2);
}