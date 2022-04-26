echo -n "write dir and press enter: ";
read dir;
echo -n "Paste prefix and press enter: ";
read prefix;
echo -n "write prefix you want to be -> without numbers!( and press enter ): ";
read prefix2;
i=0;

for file in $dir/*
do
rename -n s/$prefix$i\.wbmp/$prefix2$i\.wbmp/ $dir/*
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
rename s/$prefix$i\.wbmp/$prefix2$i\.wbmp/ $dir/*.wbmp
((i+=1))
done
echo "done!"
fi
