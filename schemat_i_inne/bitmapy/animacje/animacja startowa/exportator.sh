#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# it's an "exportator" -> this program exports wbmp to my file format
echo -n "Write file name and press enter: ";
read prefix;
i=0;
pr2=$prefix"e";
echo -n "">"$pr2.txt";
echo -n "in progress...";
./exportator <"$prefix.txt" >>"$pr2.txt"
echo -n "done!"
