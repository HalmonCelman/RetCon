# RetCon

Mini konsola Retro

OK, so when microcontroller doesn't aswer try avrdude with -B300 flag ,
 it sets SCK to 2KHz so it can communicate even if microcontroller is going really slow
f.e. avrdude -c usbasp -p m1284p -B300
