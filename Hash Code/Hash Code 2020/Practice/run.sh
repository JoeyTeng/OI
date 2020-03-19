#!/bin/bash

g++ -O3 pizza.cpp -o _pizza.out
./_pizza.out <a_example.in >a_example.out &
./_pizza.out <b_small.in >b_small.out &
./_pizza.out <c_medium.in >c_medium.out &
./_pizza.out <d_quite_big.in >d_quite_big.out 2>_d_quite_big.log &
./_pizza.out <e_also_big.in >e_also_big.out 2>_e_also_big.log &
