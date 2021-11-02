sudo touch ex2.txt
sudo chmod 777 ex2.txt

sudo touch file1
sudo touch file2

sudo chmod 777 file1
sudo chmod 777 file2
sudo echo timur > file1
sudo echo iakhshigulov > file2

sudo cp -a /bin lofsdisk/
sudo cp -a /usr lofsdisk/
sudo cp -a /lib lofsdisk/

sudo ./ex2 > ex2.txt
sudo ./ex2 >> ex2.txt
