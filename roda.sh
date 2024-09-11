#!/bin/bash

#receive a string as argument
# compile the string and output the executable as string removing the .cpp
#using g++ string.cpp -O3 -o string
#run the executable 

if [ $# -ne 2 ]; then
    echo "Usage: $0 <string>"
    exit 1
fi




file=$2

string=$1
executable=${string%.cpp}

g++ $string -O3 -o $executable
./$executable < $file