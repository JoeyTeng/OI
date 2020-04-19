// Wandering Robot
#include <bits/stdc++.h>

auto input() {
    int w = 0;
    int h = 0;
    int l = 0;
    int u = 0;
    int r = 0;
    int d = 0;

    std::cin >> w >> h >> l >> u >> r >> d;

    return std::make_tuple(w, h, l, u, r, d);
}

double choose(int n, int k) {
    double result = 1.0;
    for (int i = k + 1; i <= n; ++i) {
        result *= i;
        result /= i - k;
    }

    return result;
}

template <typename T>
auto process(T& args) {
    auto w = std::get<0>(args);
    auto h = std::get<1>(args);
    auto l = std::get<2>(args) - 1;
    auto u = std::get<3>(args) - 1;
    auto r = std::get<4>(args) - 1;
    auto d = std::get<5>(args) - 1;
    double drop = 0.0;

    // std::cerr << "\nfall by row" << std::endl;
    if (u > 0) {
        for (int i = l; i <= r; ++i) {  // fall in by row
            int options = std::min(std::min(i + u - 1, w), h);
            // std::cerr << choose(options, u - 1) / std::pow(2.0, options) /
            //                  (i == w || u == h ? 1.0 : 2.0)
            //           << std::endl;
            drop += choose(options, u - 1) / std::pow(2.0, options) /
                    (i == w || u == h ? 1.0 : 2.0);
        }
    }
    // std::cerr << "fall by col" << std::endl;
    if (l > 0) {
        for (int i = u; i <= d; ++i) {  // fall in by col
            int options = std::min(std::min(i + l - 1, w), h);
            // std::cerr << choose(options, l - 1) / std::pow(2.0, options) /
            //                  (i == h || l == w ? 1.0 : 2.0)
            //           << std::endl;
            drop += choose(options, l) / std::pow(2.0, options) /
                    (i == h || l == w ? 1.0 : 2.0);
        }
    }

    // no safe route
    if ((l == 0 && r == w - 1) || (u == 0 && d == h - 1)) {
        return 0.0;
    }

    return floor((1.0 - drop) * 1e8) / 1e8;
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto args = input();
        auto result = process(args);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
