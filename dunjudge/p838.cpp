// egypt

#include<bits/stdc++.h>

int main() {
    int N = 0;

    std::cin >> N;

    for (int i = 0; i < (N << 1) - 1; ++i) {
        for (int j = 0; j < (N << 1) - 2; ++j) {
            std::cout << std::min(std::min(j + 1, (i + 1)),
                         std::min((N << 1) - j - 1, (N << 1) - i - 1)) << ' ';
        }
        std::cout << '1' << std::endl;
    }

    return 0;
}
