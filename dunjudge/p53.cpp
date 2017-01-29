// exponentiate

#include<bits/stdc++.h>

int main() {
    int T = 0;

    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int A;
        int B;
        int M;

        std::cin >> A >> B >> M;

        int64_t base = A;
        int64_t result = 1;

        A = A % M;

        while (B) {
            if (B & 1) {
                result = (result * base) % M;
            }
            B >>= 1;
            base = (base * base) % M;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
