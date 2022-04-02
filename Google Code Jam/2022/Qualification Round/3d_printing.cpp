#include <bits/stdc++.h>

const int NUM_PRINTERS = 3;
const int TOTAL = 1000000;

template<typename T>
T min_vec(const std::vector<T>& a, const T& maximum) {
    T curr = maximum;
    for (const auto& val : a) {
        if (val < curr) {
            curr = val;
        }
    }

    return curr;
}

void solution(
    int t,
    const std::vector<int>& c,
    const std::vector<int>& m,
    const std::vector<int>& y,
    const std::vector<int>& k
) {
    std::cout << "Case #" << t << ": ";

    int max_c = min_vec(c, TOTAL);
    int max_m = min_vec(m, TOTAL);
    int max_y = min_vec(y, TOTAL);
    int max_k = min_vec(k, TOTAL);

    if (max_c + max_m + max_y + max_k < TOTAL) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        int left = TOTAL;
        int c_ = std::min(left, max_c);
        left -= c_;
        int m_ = std::min(left, max_m);
        left -= m_;
        int y_ = std::min(left, max_y);
        left -= y_;
        int k_ = std::min(left, max_k);
        left -= k_;

        std::cout << c_ << ' ' << m_ << ' ' << y_ << ' ' << k_ << std::endl;
    }
}

int main() {
    int t = 0;
    std::vector<int> c(NUM_PRINTERS);
    std::vector<int> m(NUM_PRINTERS);
    std::vector<int> y(NUM_PRINTERS);
    std::vector<int> k(NUM_PRINTERS);

    std::cin >> t;

    for (int it = 1; it <= t; ++it) {
        for (int i = 0; i < NUM_PRINTERS; ++i) {
            std::cin >> c[i] >> m[i] >> y[i] >> k[i];
        }
        solution(it, c, m, y, k);
    }

    return 0;
}
