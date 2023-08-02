#ifndef RC_STREAMS_H
#define RC_STREAMS_H

#include <LLL.h>

typedef enum{
    RC_REFRESH,   // refreshes screen - without it changes will not be visible
    RC_CLEAR,     // clears screen
    RC_SET_PX,    // sets pixel
    RC_CLR_PX,    // clears pixel
    RC_WRITE_CHAR // writes char
} RETCON_STREAMS;

void rc_stream_refresh(void);
void rc_stream_clear(void);
void rc_stream_set_px(void);
void rc_stream_clr_px(void);
void rc_stream_write_char(void);

#endif