#!/bin/bash
gcc ex2_3.c -o ex2_3.o
./ex2_3.o &
pstree
gcc ex2_5.c -o ex2_5.o
./ex2_5.o &
pstree
rm ex2_5.o
rm ex2_3.o