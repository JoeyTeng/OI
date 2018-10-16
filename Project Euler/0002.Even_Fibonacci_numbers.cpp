#include<iostream>

int main() {
    int sum = 0;
    int last = 1;
    int prev = 1;
    int current = 0;

    while (current < 4000000) {
        current = last + prev;
        if (!(current % 2)) {
            sum += current;
        }
        last = prev;
        prev = current;
    }

    std::cout << sum << std::endl;

    return 0;
}
