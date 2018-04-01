// Oversized Pancake Flipper

#include<bits/stdc++.h>

void flip(std::string& S, int pos, int K) {
    for (int i = 0; i < K; ++i) {
        if (S.at(i + pos) == '-') {
            S.at(i + pos) = '+';
        } else {
            S.at(i + pos) = '-';
        }
    }
}

int check(const std::string& S, int K) {
    for (int i = S.size() - 1; i >= int(S.size()) - K; --i) {
        if (S.at(i) == '-') {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::string S;
        int K;
        std::cin >> S >> K;

        int count = 0;
        for (int i = 0; i < S.size() - K + 1; ++i) {
            if (S.at(i) == '-') {
                flip(S, i, K);
                ++count;
            }
        }
        std::cout << "Case #" << t + 1 << ": ";
        if (check(S, K)) {
            std::cout << count << std::endl;
        } else {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
    }

    return 0;
}
