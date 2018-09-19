#!/bin/bash

for (( i=1;i<=100;i++ ))
do
    if ln file file.lock
    then
        n=$(tail -n 1 file)
        n=$(( $n + 1 ))
        echo $n >> file
        rm file.lock
    fi
done
