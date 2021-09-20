#!/bin/bash  
  
file='ex2.txt'
while true 
do

i=0
while read -r line
do
i=$(($i+1))
done<"$file"
echo "$i" >> 'ex2.txt'
file='ex2.txt'
done<"$file"
