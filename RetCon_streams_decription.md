# RetCon Streams Description

> This file decribes IN and OUT recieved from LLL, and it's functions

**! *0 values mean that parameter isn't processed but still 1 parameter is necessary in program, I recommend to write in his place @0* !**

**! *more than 1 value should be given by range, or by separating out command into multiple out commands with same stream* !**

## for OUT:
> ### 0. Error 
> 
> > Display error information
> > 
> > 1 value
> > - error number
>
> ### 1. Refreshes the screen
> 
> > 0 values
>
> ### 2. Clear screen buffer
> > Clears all the screen buffer
> > (if double buffering isn't used - clears screen)
> >
> > 0 values
> 
> ### 3. SetPixel
> > Sets pixel in screen buffer
> > 
> > 2 values
> > - X axis [0:127]
> > - Y axis [0:63]
>
> ### 4. ClearPixel
> > Clears pixel in screen buffer
> > 
> >  2 values
> > - X axis [0:127]
> > - Y axis [0:63]
>
> ### 5. WriteChar
> > Write Char on screen, x and y indicates position of top left pixel of letter, letters size are 5x7 
> > 
> >  3 values
> > - X axis [0:121]
> > - Y axis [0:63]
> > - char
> 
> ### 6. Stroke Rect
> > Draws a rectangle which isn't filled inside
> > 
> >  4 values
> >  - X start axis [0:127]
> >  - Y start axis [0:63]
> >  - X length
> >  - Y length
> 
> ### 7. Fill Rect
> > Draws a rectangle which is filled inside
> > 
> >  4 values
> >  - X start axis [0:127]
> >  - Y start axis [0:63]
> >  - X length
> >  - Y length
> 
> ### 8. Beep
> > Beep with buzzer for up to 255 ms (this don't stop program from execuitng)
> >
> > *believe me you don't want to turn this buzzer for longer time,
> >  but chill, in the RetCon v1.1 you should be able to play some music with it*
> >
> > 1 value
> > - time of beeping
> ### 9. Delay - in miliseconds
> > Stop executing anything for up to 65535 ms
> >
> > 2 values
> > - 16 bits value
> >
> ### 10. setTimer
> > sets timer which decerase every milisecond and stops at 0
> >
> >  2 values
> >  - 16 bits value

## for IN:

> ### 0. Error Stream
> > Check if any error exist, if yes get his number
> > 
> > 1 value
> > - error number
> >
> ### 1. get 1-0 buttons value
> > if button is pressed, at its position 1 is set, for positions see buttons.pdf
> >
> > 1 value
> > - bits for all buttons
> >
> ### 2. get analog 1 value
> > 
> > gets value from left analog
> > 
> > - 1 value
> >
> ### 3. get analog 2 value
> > 
> > gets value from right analog
> > 
> > - 1 value
>
> ### 10. getTimer
> > gets timer value
> >
> >  2 values
> >  - 16 bits value