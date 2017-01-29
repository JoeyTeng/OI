// fizzbuzz

#include<iostream>

int main() {
    int64_t S = 0;
    int64_t E = 0;
    int A = 0;
    int B = 0;

    std::cin >> S >> E >> A >> B;

    for (int64_t i = S; i <= E; ++i) {
        int flag = 0;
        if (!(i % A)) {
            flag = 1;
            std::cout << "Fizz";
        }
        if (!(i % B)) {
            flag = 1;
            std::cout << "Buzz";
        }
        if (!flag) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    return 0;
}
