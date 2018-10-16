#include<iostream>

int main() {
    std::int64_t factor = 2;
    std::int64_t dividend = 600851475143;

    while (dividend > 1) {
        while (!(dividend % factor)) {
            dividend /= factor;
        }
        ++factor;
    }

    std::cout << factor - 1 << std::endl;

    return 0;
}
