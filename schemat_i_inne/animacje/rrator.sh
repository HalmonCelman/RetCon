#by KK
# license as always - you can freely use but you must give information that this program
# was written by KK
# 
# ABOUT PROGRAM
# this program is "renamerator" - it's renaming many files .wbmp to .txt or .txt to .txt
#
if [ -n "$1" ]; then
  dir=$1;
else
  	echo -n "write dir and press enter: ";
	read dir;
fi
if [ -n "$2" ]; then
  prefix=$2;
else
  	echo -n "Paste prefix and press enter: ";
	read prefix;
fi
if [ -n "$3" ]; then
  prefix2=$3;
else
  	echo -n "write prefix you want to be -> without numbers!( and press enter ): ";
	read prefix2;
fi

i=0;

for file in frames/$dir/*
do
rename -n s/$prefix$i\.wbmp/$prefix2$i\.txt/ frames/$dir/*
rename -n s/$prefix$i\.txt/$prefix2$i\.txt/ frames/$dir/*
((i+=1))
done



echo -n "This files would change their names, are you sure?(y/n)";
read sure;
if [ "$sure" = "y" ];
then 
echo "in progress";
i=0;
for file in $dir/*.wbmp
do
echo -n "."
rename s/$prefix$i\.wbmp/$prefix2$i\.txt/ frames/$dir/*
rename s/$prefix$i\.txt/$prefix2$i\.txt/ frames/$dir/*
((i+=1))
done
echo "done!"
fi
