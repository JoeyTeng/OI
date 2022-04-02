#include <bits/stdc++.h>

void solution(int t, int r, int c) {
    std::cout << "Case #" << t << ':' << std::endl;
    for (int i = 0; i < r; ++i) {
        if (i == 0) {
            std::cout << "..";
        } else {
            std::cout << "+-";
        }
        for (int j = 1; j < c; ++j) {
            std::cout << "+-";
        }
        std::cout << "+" << std::endl
                  << ((i == 0) ? ".." : "|.");
        for (int j = 1; j < c; ++j) {
            std::cout << "|.";
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < c; ++j) {
            std::cout << "+-";
        }
    std::cout << "+" << std::endl;
}

int main() {
    int t = 0;
    int r = 0;
    int c = 0;

    std::cin >> t;

    for (int it = 1; it <= t; ++it) {
        std::cin >> r >> c;
        solution(it, r, c);
    }

    return 0;
}
