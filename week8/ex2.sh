gcc ex2.c -o ex2

echo "before start of the program:"

vmstat

echo "start program"

./ex2 &

vmstat 1
