./ex2.sh &
./ex2.sh 

sleep 1 


kill $(ps | grep 'ex2' | awk '{print $1}')



echo "killed"
