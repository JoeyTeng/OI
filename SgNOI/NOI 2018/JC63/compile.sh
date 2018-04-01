#!/bin/bash
/usr/bin/g++ -DEVAL -static -O2 -std=c++11 -Wall -o "$1" "$1.cpp"
