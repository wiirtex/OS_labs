./ex2b.sh &
./ex2b.sh &

sleep 1 


kill $(ps | grep 'ex2' | awk '{print $1}')



echo "killed"
