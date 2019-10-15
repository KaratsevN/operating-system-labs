#!/bin/bash

echo "Input full way of directory: "
read path
#cd $path
for f in *.txt
do
echo $path/$f
cat $path/$f
done
sleep 1s

#echo "Input full way of directory: "; read directory;
#done;
#find $directory/ -name "*.txt" -print -exec more {} \;
