cd tamarisk-digraph
make clean
make all
dmesg -C
insmod tamarisk-digraph.ko
rmmod tamarisk-digraph.ko
cd ..
dmesg > process-digraph.dot
sed -i 's/^\[.*\]/ /g' process-digraph.dot
dot -Tpng process-digraph.dot -o process-tree.png
eog process-tree.png &
