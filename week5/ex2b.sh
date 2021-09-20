#!/bin/bash  
  
file='ex2b.txt'
while true 
do

i=0
exec 4<"$file"
flock -e 4
while  read -r line
do
flock -u 4
exec 4<"$file"
i=$(($i+1))
flock -u 4
done<"$file"
flock -e 4
echo "$i" >> 'ex2b.txt'

flock -u 4
exec 4<&-
file='ex2b.txt'
done<"$file"

