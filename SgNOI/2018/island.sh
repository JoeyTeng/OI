g++-7 -O2 -g island.cpp
echo "sample 1"
./a.out < island.sample.1.in
echo "sample 2"
./a.out < island.sample.2.in
echo "sample 3"
./a.out < island.sample.3.in
echo "self 1"
./a.out < island.self.1.in
echo "self 2"
./a.out < island.self.2.in


rm ./a.out
