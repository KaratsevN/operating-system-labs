#!/bin/bash
echo "Input full way of directory: "
read x
while test -z $x
do
echo "Input full way of directory: "
read x
done
echo "Input full way of backup directory: "
read y
if test -z $y
then
  mkdir $x-copy
  y=$x-copy
fi
if test ! -e $y 
then
mkdir $y
fi
echo "1. Substitution of files (if it's backup directory)"
echo "2. Addendum a file"
echo "3. Deleting"
echo "4. Synchonisation of files"
echo "5. Help"
echo "6. Exit"
echo "Input a number of operation: "
read a
case $a in 
1) echo "Substitution"
   cd $x
   for f in *
   do
     cp -R  $x/$f $y
   done 
   echo "Done!" ;;
2) echo "Addendum"
   cd $x
   for f in *
   do
     cp -R -n $x/$f $y
   done 
   echo "Done!" ;;
3) echo "Deleting";
cd $x;
for d in `find * -type d`; do
	if test -e "$y/$d"; then
	cd $y/$d;
	for f in *;
	do
		if test ! -e "$x/$d/$f"; then
			rm "$f"
		fi;
	done;
	fi;
done;
cd $y;
for f in *.*; do
	if test ! -e "$x/$f"; then
	rm "$f"
	fi;
done;
   echo "Done!" ;;
4) echo "Synchonisation";
cd $x
for d in `find * -type d`; do
	cd $x/$d;
	for f in *.*; do
		if test -e $y/$d; then
			if test "$x/$d/$f" -nt "$y/$d/$f"; then
			cp --remove-destination "$f" $y/$d/
			fi;
		fi;
	done;
done;
cd $x;
for f in *.*; do
	if test "$x/$f" -nt "$y/$f"; then
	cp --remove-destination "$f" $y/
	fi;
done;
   echo "Done!" ;;
5) echo "4.sh - creates a backup copy of directory."
echo "1. You have to input a way of directory correctly;"
echo "2. You have to input a way of backup directory, if you don't input name"
echo "	 of directory. It will be created at the same section;"
echo "3. There are 3 operation for working with files."
echo "4. From the files the user chooses who was changed later copies to backup directory"
esac
sleep 1s