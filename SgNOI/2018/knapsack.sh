g++-7 -O2 -g knapsack.cpp
echo "sample 1"
./a.out < knapsack.sample.1.in
echo "sample 2"
./a.out < knapsack.sample.2.in

rm ./a.out
