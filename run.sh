#!bin/bash

# Create Obj files
cd ./src
clang tree.c        -c -Wall -Wextra -Wabi -Wpedantic -O3 -o ../obj/tree.o
clang print.c       -c -Wall -Wextra -Wabi -Wpedantic -O3 -o ../obj/print.o
clang linked_list.c -c -Wall -Wextra -Wabi -Wpedantic -O3 -o ../obj/list.o

# Create static library
cd ../obj
ar -rcs librbtree.a tree.o print.o
ar -rcs liblist.a list.o

# Compile and link dictionary
cd ../src
clang main.c -lrbtree -llist -L../obj -lncurses -Wall -Wextra -Wabi -Wpedantic -O3 -o ../bin/Dictionary

# Run dictionary
cd ../bin
./Dictionary #< ./lib/recovery/backup.txt
