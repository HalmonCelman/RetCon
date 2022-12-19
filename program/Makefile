# Custom universal makefile for AVR
# ************ by KK **************
# ****** All rights reserved ******
# *********************************

#Configurable part
DEVICE = atmega1284p
PROGRAMMER = usbasp
COMPILE = avr-gcc -Wall -Os -mmcu=$(DEVICE) -std=c99
DUDEFLAGS = 


#DANGER ZONE - DON'T TOUCH UNTIL YOU ARE SURE WHAT YOU DO
OBJ := $(patsubst %.c,%.o,$(wildcard *.c */*.c))
OF = main

default: compile upload clean

compile: $(OBJ) $(OF).elf
%.o : %.c
	$(COMPILE) -c $< -o $@
$(OF).elf: $(OBJ)
	$(COMPILE) -o $@ $^
	avr-objcopy -j .text -j .data -O ihex $@ $(OF).hex
	avr-size --format avr --mcu=$(DEVICE) $@

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) $(DUDEFALGS) -U flash:w:$(OF).hex:i

clean: 
	rm $(OBJ)
	rm $(OF).elf
	rm $(OF).hex
