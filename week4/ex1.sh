#!/bin/bash
gcc ex1.c -o ex1.o
for (( i=1; i<=10; i=i+1))
do
	./ex1.o
done
