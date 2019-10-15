#!/bin/bash
#/home/nikita/git/ioc/pom.xml
#/home/nikita/git/operating-system-labs/first-semester/lab2/linux/2.sh

echo Input full way of file: 
read way

if test -e $way
then
	echo File $way was found;
	ls -la $way
else
	echo File $way not found
fi

sleep 1s
