// Expogo
#include <bits/stdc++.h>

const int64_t INC_X[] = {0, 1, 0, -1};
const int64_t INC_Y[] = {1, 0, -1, 0};
const char DIRECTION[] = {'S', 'W', 'N', 'E'};

auto input() {
    int64_t X = 0;
    int64_t Y = 0;

    std::cin >> X >> Y;

    return std::make_tuple(X, Y);
}

template <typename T>
bool dfs(T x, T y, int depth, std::string& res) {
    // std::cerr << "(" << x << ", " << y << ")" << std::endl;
    if (x == 0 && y == 0) {
        return true;
    }
    if (depth == 0) {
        return false;
    }
    if (((x % 2) && (y % 2)) || (!(x % 2) && !(y % 2))) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        auto nextX = x + INC_X[i];
        auto nextY = y + INC_Y[i];

        if (((nextX % 2) || (nextY % 2)) ||
            (nextX / 2 == x && nextY / 2 == y)) {
            continue;
        }

        res.push_back(DIRECTION[i]);
        auto ret = dfs(nextX / 2, nextY / 2, depth + 1, res);
        if (ret) {
            return true;
        }
        res.pop_back();
    }

    return false;
}

template <typename T>
auto process(const T& inputs) {
    auto X = std::get<0>(inputs);
    auto Y = std::get<1>(inputs);
    std::string result;

    // std::cerr << std::endl << X << ", " << Y << std::endl;
    for (int i = 1; i <= std::log2(std::abs(X) + std::abs(Y)) + 2; ++i) {
        result.clear();
        if (dfs(X, Y, i, result)) {
            return result;
        }
    }
    return std::string("IMPOSSIBLE");
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
