#!/bin/bash
#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# this program is "make_animation" - it's making formated animation with renamerator consolidator and exportator
#

echo -n "write dir and press enter: ";
read dir;
echo -n "Paste prefix and press enter: ";
read prefix;
echo -n "write prefix you want to be -> without numbers!( and press enter ): ";
read prefix2;
chmod +x rrator.sh
chmod +x condator.sh
chmod +x exportator.sh
chmod +x exportator
./rrator.sh $dir $prefix $prefix2;
./condator.sh $dir $prefix2;
./exportator.sh $prefix2;
