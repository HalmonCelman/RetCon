cd build; cmake --build .;avr-objcopy -j .text -j .data -O ihex RetCon RetCon.hex;avr-size -C RetCon