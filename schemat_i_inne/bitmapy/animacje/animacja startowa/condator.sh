#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# it's an "consolidator" of .txt files it's getting them together to one file
echo -n "Write dir and press enter: ";
read dir;
echo -n "Write prefix and press enter: ";
read prefix;
i=0;
echo -n "">$prefix.txt;
echo -n "in progress";


for file in $dir/*
do
cat $dir/$prefix$i.txt >> $prefix.txt;
echo -n ".";
((i+=1))
done
echo "done!";
