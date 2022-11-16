#!/bin/bash
#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# it's an "exportator" -> this program exports wbmp to my file format
if [ -n "$1" ]; then
  prefix=$1;
else
  	echo -n "Write file name and press enter: ";
	read prefix;
fi
i=0;
echo -n "in progress...";
./exportator <"not_exported/$prefix.txt" >>"exported/$prefix.txt"
echo -n "done!"
