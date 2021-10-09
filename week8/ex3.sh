gcc ex2.c -o ex2


echo "before start of the program:"


vmstat


echo "start program"


./ex2 &
top -i  1

#here we can see, how my program ex2.c use the sources of the CPU. It is one of the most intensive CPU-users.
#And we see, how much virtual memory is using at the moment.
