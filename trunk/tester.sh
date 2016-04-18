#Testing of tamarisk-all
cd tamarisk-all
make clean
make all
dmesg -C
ps -el > ../ps-all.test
insmod tamarisk-all.ko
rmmod tamarisk-all.ko
dmesg > ../tamarisk-all.test
cd ..

#Testing of tamarisk-dfs
cd tamarisk-all
make clean
make all
dmesg -C
ps -eLf > ../ps-dfs.test
insmod tamarisk-dfs.ko
rmmod tamarisk-dfs.ko
dmesg > ../tamarisk-dfs.test
dmesg -C
