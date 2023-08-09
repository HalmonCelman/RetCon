#ifndef RC_STREAMS_H
#define RC_STREAMS_H

#include <LLL.h>
#include <config.h>

typedef enum{
    RC_ERROR_OUT,       // throws error
    RC_REFRESH,     // refreshes screen - without it changes will not be visible
    RC_CLEAR,       // clears screen
    RC_SET_PX,      // sets pixel
    RC_CLR_PX,      // clears pixel
    RC_WRITE_CHAR,  // writes char
    RC_SET_TIMER=10 
} RETCON_STREAMS_OUT;

typedef enum{
    RC_ERROR_IN,       // throws error
    RC_GET_TIMER=10 
} RETCON_STREAMS_IN;

//out
void rc_stream_refresh(void);
void rc_stream_clear(void);
void rc_stream_set_px(uint32_t);
void rc_stream_clr_px(uint32_t);
void rc_stream_write_char(uint32_t);
void rc_stream_set_timer(uint32_t);


//in
void rc_stream_get_timer(uint32_t);

#endif