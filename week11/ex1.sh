sudo kdir week11
sudo cd week11
sudo touch lofs.img
sudo mkdir lofsdisk
sudo losetup -f lofs.img
sudo mkfs -t ext2 /dev/loop3

