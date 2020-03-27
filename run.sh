#!bin/bash

# Create Obj files
cd ./src
ccache clang tree.c  -c -Wall -W -O3 -o ../obj/tree.o
# ccache clang print.c -c -Wall -W -O3 -o ../obj/print.o

# Create static library
cd ../obj
ar -rcs librbtree.a tree.o #print.o

# Compile and link dictionary
cd ../src
ccache clang main.c -lrbtree -L../obj -lncurses -Wall -Wextra -Wabi -Wpedantic -O3 -o ../bin/Dictionary

# Run dictionary
cd ../bin
./Dictionary #< ./lib/recovery/backup.txt
