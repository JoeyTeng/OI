// paint

#include<bits/stdc++.h>

int main() {
    int N = 0;
    int sum = 0;
    std::vector<int> inc;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;

        std::cin >> tmp;
        sum += tmp;
    }

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;
    inc.assign(int_cin, int_end);

    std::sort(inc.begin(), inc.end(), std::greater<int>());

    for (int i = 0; i < N; ++i) {
        sum += i * inc.at(i);
    }

    std::cout << sum << std::endl;

    return 0;
}
