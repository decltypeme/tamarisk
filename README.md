# tamarisk
Linux kernel module for listing processes
## Repository Structure
```
.
├── LICENSE
├── README.md
└── trunk
    ├── includes
    │   └── printer.h
    ├── tamarisk-all
    │   ├── Makefile
    │   └── tamarisk-all.c
    ├── tamarisk-dfs
    │   ├── Makefile
    │   └── tamarisk-dfs.c
    ├── tamarisk-digraph
    │   ├── Makefile
    │   └── tamarisk-digraph.c
    ├── tamarisk-visualize.sh
    └── tester.sh
    └── cleaner.sh
```
### Configurations

***Still in progress***

For the modules tamarisk-all and tamarisk-dfs, we give the option to translate the state to a readable string. You can change it by setting the following configuration in the header in ``includes/printer.h``

As you know, "(programmers) provide enough to satisfy [every] (user)'s needs, but not [every] (user)'s greed." - Mahatma Gandhi after shifting careers.

Preprocessor | Effect
------------ | -------------
STATE_STRING | Print the state as a readable string

### tamarisk-all
A module to list all tasks linearly. To use the module, you can either run the **tester.sh$$ or run this code when in tamarisk-all. Please run these commands with administrator privileges.
```
make clean
make all
# This will clear the dmesg, please think before using it.
# dmesg -C
insmod tamarisk-all.ko
rmmod tamarisk-all.ko
dmesg > tamarisk-all.test
```
Whenever you want to clean the directory from the built files, please run this command.
```
sudo make clean
```
### tamarisk-dfs
A module to list all tasks in a DFS manner. To use the module, you can either run the **tester.sh$$ or run this code when in tamarisk-dfs. Please run these commands with administrator privileges.
```
make clean
make all
# This will clear the dmesg, please think before using it.
# dmesg -C
insmod tamarisk-dfs.ko
rmmod tamarisk-dfs.ko
dmesg > tamarisk-dfs.test
```
Whenever you want to clean the directory from the built files, please run this command.
```
sudo make clean
```
### tamarisk-digraph
A module to generate a digraph for processes'parent-child relation in the DOT graph description language. To use the module, you can run the **tamarisk-visualize.sh$$ with sudo privileges after making sure graphviz is installed or follow these instructions.
#### Generating the DOT file
Please build, insmod and then rmmod as follows.
```
make clean
make all
dmesg -C
insmod tamarisk-digraph.ko
rmmod tamarisk-digraph.ko
dmesg > process-digraph.dot
```
Now, let's clean the mess in the generated dot file and get our DOT file. The dmesg prints some numbers at the beginning, we can get rid of them using this sed and regex trick.
```
sed -i 's/^\[.*\]/ /g' process-digraph.dot
```
#### Visualizing the graph
We give here an option to visualize the generated graph using graphviz.

Please make sure graphviz is installed on your machine. To install graphviz, use this command.
```
sudo apt-get install graphviz
```
Now, we create a cool png file.
```
dot -Tpng process-digraph.dot -o process-tree.png
```
And of course view it, I have eog, so I used it. You can preview the PNG with any application capable of or view the 0s and 1s if you have some sorts of superpowers.
```
eog process-tree.png &
```
**Please note that the PNG file may have lots of processes, however the quality of the generated file will allow you to zoom in as you wish.**
