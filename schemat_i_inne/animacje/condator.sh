#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# it's an "consolidator" of .txt files it's getting them together to one file
if [ -n "$1" ]; then
  dir=$1;
else
  	echo -n "Write dir name and press enter: ";
	read dir;
fi
if [ -n "$2" ]; then
  prefix=$2;
else
  	echo -n "Paste prefix and press enter: ";
	read prefix;
fi
i=0;
echo -n "">not_exported/$prefix.txt;
echo -n "in progress";


for file in $dir/*
do
cat frames/$dir/$prefix$i.txt >> not_exported/$prefix.txt;
echo -n ".";
((i+=1))
done
echo "done!";
