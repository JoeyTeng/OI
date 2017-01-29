// swapping cats

#include<bits/stdc++.h>

int main() {
    int n = 0;
    int s = 0;
    std::vector<int> seat;

    std::cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        seat.push_back(i);
    }

    for (int i = 0; i < s; ++i) {
        int x;
        int y;

        std::cin >> x >> y;
        std::swap(seat.at(x), seat.at(y));
    }

    std::ostream_iterator<int> cout_int(std::cout, "\n");

    std::copy(seat.begin(), seat.end(), cout_int);

    return 0;
}
