#Testing of tamarisk-all
cd tamarisk-all
make clean
make all
dmesg -C
ps -el > ../ps-all.test
insmod tamarisk-all.ko
rmmod tamarisk-all.ko
cd ..
dmesg > tamarisk-all.test

#Testing of tamarisk-dfs
cd tamarisk-dfs
make clean
make all
dmesg -C
ps -eLf > ../ps-dfs.test
insmod tamarisk-dfs.ko
rmmod tamarisk-dfs.ko
cd ..
dmesg > tamarisk-dfs.test
dmesg -C
