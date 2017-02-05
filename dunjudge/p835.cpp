// vanish

#include<bits/stdc++.h>

struct Counter {
    Counter (int digit, int count) {
        this -> digit = digit;
        this -> count = count;
    }

    int digit;
    int count;
};

int main() {
    int N = 0;

    std::cin >> N;

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;
    std::vector<int> numbers(int_cin, int_end);

    std::sort(numbers.begin(), numbers.end());

    std::vector<Counter> squeezed;
    squeezed.push_back(Counter(numbers.front(), 0));

    for (auto it : numbers) {
        if (it == squeezed.back().digit) {
            ++squeezed.back().count;
        } else {
            squeezed.push_back(Counter(it, 1));
        }
    }

    int64_t last[2] = {0};
    int64_t current[2] = {0};
    int last_digit = INT_MIN;
    int current_digit = INT_MIN;

    for (auto it : squeezed) {
        last_digit = current_digit;
        current_digit = it.digit;
        last[0] = current[0];
        last[1] = current[1];

        if (last_digit + 1 == current_digit) {
            current[0] = std::max(last[0], last[1]);
            current[1] = last[0] + it.digit * it.count;
        } else {
            current[0] = std::max(last[0], last[1]);
            current[1] = std::max(last[0], last[1]) + it.digit * it.count;
        }
    }

    std::cout << std::max(current[0], current[1]) << std::endl;

    return 0;
}
