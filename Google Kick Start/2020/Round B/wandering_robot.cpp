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

template <typename T>
auto process(T& args) {
    auto w = std::get<0>(args);
    auto h = std::get<1>(args);
    auto l = std::get<2>(args) - 1;
    auto u = std::get<3>(args) - 1;
    auto r = std::get<4>(args) - 1;
    auto d = std::get<5>(args) - 1;
    std::string result;
    // rolling rows
    std::vector<std::vector<double>> prob;

    std::vector<double> tmp(w);
    prob.push_back(tmp);
    prob.push_back(tmp);

    // std::cerr << "start: (" << l << ", " << u << "), (" << r << ", " << d <<
    // ")"
    //           << std::endl;
    prob[(0 & 1) ^ 1][0] = 2.0;  // a hack
    for (auto i = 0; i < h - 1; ++i) {
        auto& curr = prob[i & 1];
        auto& prev = prob[(i & 1) ^ 1];

        if (l <= 0 && 0 <= r && u <= i && i <= d) {
            curr[0] = .0;
        } else {
            curr[0] = prev[0] / 2.0;
        }

        // std::cerr << std::setprecision(6) << std::setw(9) << curr[0] << ' ';
        for (auto j = 1; j < curr.size() - 1; ++j) {
            if (l <= j && j <= r && u <= i && i <= d) {
                curr[j] = 0.0;
                // std::cerr << std::setprecision(6) << std::setw(9) << 0 << '
                // ';
                continue;
            }
            curr[j] = prev[j] / 2.0 + curr[j - 1] / 2.0;

            // std::cerr << std::setprecision(6) << std::setw(9) << curr[j] << '
            // ';
        }
        if (l <= w - 1 && w - 1 <= r && u <= i && i <= d) {
            curr[w - 1] = 0;
        } else {
            curr[w - 1] = prev[w - 1] + curr[w - 2] / 2.0;
        }
        // std::cerr << std::setprecision(6) << std::setw(9) << curr[w - 1] << '
        // '
        //           << std::endl;
    }

    auto& prev = prob[(h & 1)];
    auto& curr = prob[(h & 1) ^ 1];

    if (l <= 0 && 0 <= r && u <= h - 1 && h - 1 <= d) {
        curr[0] = .0;
    } else {
        curr[0] = prev[0] / (h >= 2 ? 2.0 : 1.0);
    }
    // std::cerr << std::setprecision(6) << std::setw(9) << curr[0] << ' ';
    for (auto j = 1; j < w - 1; ++j) {
        if (u <= h - 1 && h - 1 <= d && l <= j && j <= r) {
            curr[j] = 0.0;
            // std::cerr << std::setprecision(6) << std::setw(9) << 0 << ' ';
            continue;
        }

        curr[j] = prev[j] / 2.0 + curr[j - 1];
        // std::cerr << std::setprecision(6) << std::setw(9) << curr[j] << ' ';
    }
    curr[w - 1] = prev[w - 1] + (w >= 2 ? curr[w - 2] : .0);
    // std::cerr << std::setprecision(6) << std::setw(9) << curr[w - 1] << ' '
    //           << std::endl;

    return floor(curr[w - 1] * 1e8) / 1e8;
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
