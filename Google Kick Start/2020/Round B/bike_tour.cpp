// Bike Tour
#include <bits/stdc++.h>

auto input() {
    int n = 0;
    std::vector<int> checkpoints;

    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;

        checkpoints.push_back(tmp);
    }

    return std::move(checkpoints);
}

auto process(std::vector<int>& checkpoints) {
    int result = 0;

    for (auto i = 1; i < checkpoints.size() - 1; ++i) {
        if (checkpoints[i - 1] < checkpoints[i] &&
            checkpoints[i] > checkpoints[i + 1]) {
            ++result;
        }
    }

    return result;
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto vector = input();
        auto result = process(vector);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
