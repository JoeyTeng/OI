// fibo

#include<bits/stdc++.h>

int main() {
    int N = 0;
    int M = 0;
    int fibo[3] = {0, 1, 1};

    std::cin >> N >> M;

    if (N == 0) {
        std::cout << 0 << std::endl;

        return 0;
    } else if (N == 1) {
        std::cout << 1 << std::endl;

        return 0;
    }

    for (int i = 2; i < N; ++i) {
        fibo[0] = fibo[1];
        fibo[1] = fibo[2];
        fibo[2] = (fibo[0] + fibo[1]) % M;
    }

    std::cout << fibo[2] % M << std::endl;

    return 0;
}
