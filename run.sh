#!bin/bash

# Create Obj files
# cd ./src
# ccache clang tree.c  -c -Wall -W -O3 -o ../obj/tree.o
# ccache clang print.c -c -Wall -W -O3 -o ../obj/print.o

# Create static library
# cd ../obj
# ar -rcs librbtree.a tree.o #print.o

# Compile and link dictionary
# cd ../src -L../obj -lrbtree
cd ./src
clang main.c -lncurses -Wall -W -O3 -o ../bin/dictionary

# Run dictionary
cd ../bin
./dictionary #< ./lib/recovery/backup.txt
