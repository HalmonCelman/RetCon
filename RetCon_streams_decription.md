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
> > Write Char on screen
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
> ### 10. setTimer
> > sets timer which decerase every milisecond
> >
> >  2 values
> >  - 16 bits value