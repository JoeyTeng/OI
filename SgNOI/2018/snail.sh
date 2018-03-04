g++-7 -O2 -g snail.cpp
echo "sample 1"
./a.out < snail.sample.1.in
echo "sample 2"
./a.out < snail.sample.2.in
echo "sample 3"
./a.out < snail.sample.3.in
echo "self 1"
./a.out < snail.self.1.in
echo "self 2"
./a.out < snail.self.2.in
echo "self 3"
./a.out < snail.self.3.in

rm ./a.out
