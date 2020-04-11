// Pascal Walk
#include <bits/stdc++.h>

const int MAX_DEPTH = 500;
const std::vector<std::pair<int, int>> INC(
    {std::make_pair(-1, -1), std::make_pair(-1, 0), std::make_pair(0, -1),
     std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(1, 1)});

// begin * (begin + 1) * ... * (end - 1) * end
int64_t factorial(int begin, int end) {
    int64_t res = 1;

    for (int64_t i = begin; i <= end; ++i) {
        res *= i;
    }

    return res;
}

// change to pre-computed triangle. int64_t may not be sufficient
int64_t binomial(int n, int k) {
    n -= 1;
    k -= 1;

    return factorial(k + 1, n) / factorial(1, n - k);
}

auto input() {
    int64_t N;
    std::cin >> N;

    return std::move(N);
}

bool valid(const std::pair<int, int>& coord) {
    return coord.first >= 1 && coord.second >= 1 && coord.first >= coord.second;
}

auto dfs(std::vector<std::pair<int, int>>& path,
         std::set<std::pair<int, int>>& visited, int64_t n) {
    // std::cerr << "(" << path.back().first << ", " << path.back().second
    //           << "): " << binomial(path.back().first, path.back().second) <<
    //           " "
    //           << n << std::endl;
    if (n == 0) {
        return true;
    }

    if (path.size() > MAX_DEPTH) {
        return false;
    }

    for (auto&& dir : INC) {
        auto next = std::make_pair(path.back().first + dir.first,
                                   path.back().second + dir.second);

        if (valid(next) && visited.find(next) == visited.end()) {
            auto value = binomial(next.first, next.second);

            if (value <= n) {
                path.push_back(next);
                visited.insert(next);

                auto res = dfs(path, visited, n - value);
                if (res) {
                    return true;
                }

                path.pop_back();
                visited.erase(next);
            }
        }
    }

    return false;
}

auto process(int64_t n) {
    std::vector<std::pair<int, int>> path;
    std::set<std::pair<int, int>> visited;

    path.push_back(std::make_pair(1, 1));
    visited.insert(path.back());

    dfs(path, visited, n - 1);

    return path;
}

void output(std::vector<std::pair<int, int>>& path) {
    for (auto&& pair : path) {
        std::cout << pair.first << ' ' << pair.second << std::endl;
    }
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto n = input();
        auto result = process(n);

        std::cout << "Case #" << i + 1 << ":" << std::endl;
        output(result);
    }

    return 0;
}
