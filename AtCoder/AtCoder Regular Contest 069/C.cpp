// Scc Puzzle

#include<bits/stdc++.h>

int main() {
    int64_t N = 0;
    int64_t M = 0;

    std::cin >> N >> M;
    std::cout << (std::min(N, M >> 1) + std::max(int64_t(0), (M - (N << 1)) >> 2)) << std::endl;

    return 0;
}
