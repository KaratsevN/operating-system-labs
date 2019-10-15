#!/bin/bash
echo Input а
read a

echo Input b
read b

if test $a -gt $b
then
  echo a is bigger than b
fi
if test $a -lt $b
then
  echo b is bigger than a
fi
if test $a -eq $b
then
   echo a equal b
fi

sleep 1s 