cd ../week1
touch file.txt
echo TIm > file.txt
cd ../week10
link ../week1/file.txt _ex2.txt
a=`ls -i _ex2.txt | awk '{print $1}'`
echo Now I will find all links to that i-node > ex2.txt
find ../ -inum `echo $a` >> ex2.txt
echo "Now let's delete it all" >> ex2.txt
find ../ -inum `echo $a` -exec rm {} \; >> ex2.txt
find ../ -inum `echo $a` >> ex2.txt

