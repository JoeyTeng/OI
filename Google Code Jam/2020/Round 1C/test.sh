#!/bin/sh
name=$1;g++ -O3 -std=c++14 $name.cpp -o $name && ./$name <$name.sample.in >$name.sample.out; cat $name.sample.out; diff $name.sample.out $name.sample.std.out; /bin/rm $name
