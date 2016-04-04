#!/bin/bash

if [ -z "$1" ];then
echo -e "\nUsage:"
echo -e "$0 MAX\n"
else
for i in $(seq 3 $1);do
l=($(./primetri $i t | sed 's/,/ /g'))
s="${l[$((${#l[@]} - 1))]}"
printf "($i,${#s}),"
done
printf "\n"
fi
