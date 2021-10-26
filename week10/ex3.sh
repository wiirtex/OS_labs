touch _ex3.txt
echo Timur > _ex3.txt
chmod uog-x _ex3.txt
chmod uo+rwx _ex3.txt
chmod g+rwx _ex3.txt
echo "chmod 660 grants rw to u and g"
echo "chmod 775 gives all permissions to everyone, except write permission to others"
echo "chmod 777 gives all permission to everyone"
