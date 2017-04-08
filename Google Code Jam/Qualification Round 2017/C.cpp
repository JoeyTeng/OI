// C. Bathroom Stalls

#include<bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int N;
        int K;
        std::cin >> N >> K;

        int64_t level = std::log2(K);
        int64_t pre = std::pow(2, level) - 1;
        int64_t rem = K - pre;
        // a = n(x + 1) - m
        int64_t n = std::pow(2, level);
        int64_t m = N - pre;
        int64_t x = m / n;
        int64_t a = n * (x + 1) - m;

        int64_t ans = 0;
        if (n - a >= rem) {
            ans = x + 1;
        } else {
            ans = x;
        }
        --ans;

//        std::cout << level << ' ' << pre << ' ' << rem << std::endl
//                  << n << ' ' << x << ' ' << m << ' ' << a << ' ' << ans << std::endl;

        std::cout << "Case #" << t + 1 << ": " << (ans - (ans >> 1)) << ' '  << (ans >> 1) << std::endl;
    }

    return 0;
}
