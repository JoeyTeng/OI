// Overexcited Fan
#include <bits/stdc++.h>

const int64_t INC_X[] = {0, 1, 0, -1};
const int64_t INC_Y[] = {1, 0, -1, 0};
const char DIRECTION[] = {'S', 'W', 'N', 'E'};

auto input() {
    int64_t X = 0;
    int64_t Y = 0;
    std::string path;

    std::cin >> X >> Y >> path;

    return std::make_tuple(X, Y, path);
}

template <typename T>
auto simulate(int X, int Y, const T& path) {
    for (auto&& move : path) {
        switch (move) {
            case 'N':
                Y += 1;
                break;
            case 'S':
                Y -= 1;
                break;
            case 'E':
                X += 1;
                break;
            case 'W':
                X -= 1;
                break;
        }
    }

    return std::abs(X) + std::abs(Y);
}

template <typename T>
auto process(const T& inputs) {
    auto X = std::get<0>(inputs);
    auto Y = std::get<1>(inputs);
    auto path = std::get<2>(inputs);

    // std::cerr << '(' << X << ", " << Y << ") " << path << std::endl;

    auto lower_bound = 0;
    auto higher_bound = path.size();
    // std::cerr << lower_bound << ' ' << higher_bound << std::endl;
    while (lower_bound != higher_bound) {
        auto mid = (lower_bound + higher_bound) >> 1;
        auto dist = simulate(X, Y, path.substr(0, mid));
        // std::cerr << lower_bound << ' ' << mid << ' ' << higher_bound << ' '
        //           << dist << ' ' << path.substr(0, mid) << std::endl;
        if (dist <= mid) {
            higher_bound = mid;
        } else {
            lower_bound = mid + 1;
        }
    }

    if (higher_bound == path.size() && (simulate(X, Y, path) > higher_bound)) {
        return std::string("IMPOSSIBLE");
    }
    std::stringstream str;
    str << higher_bound;
    return str.str();
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto tuple = input();
        auto result = process(tuple);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
