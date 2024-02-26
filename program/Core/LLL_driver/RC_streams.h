#ifndef RC_STREAMS_H
#define RC_STREAMS_H

#include <LLL.h>
#include <config.h>

//out
void rc_stream_error(void);
void rc_stream_refresh(void);
void rc_stream_clear(void);
void rc_stream_set_px(void);
void rc_stream_clr_px(void);
void rc_stream_write_char(void);
void rc_stream_stroke_rect(void);
void rc_stream_fill_rect(void);
void rc_stream_beep(void);
void rc_stream_delay(void);
void rc_stream_set_timer(void);


//in
uint8_t rc_stream_error_in(void);
uint8_t rc_stream_10_val(void);
uint8_t rc_analog1_val(void);
uint8_t rc_analog2_val(void);
uint8_t rc_stream_get_timer(void);

#endif