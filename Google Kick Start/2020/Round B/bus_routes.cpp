// Bus Routes
#include <bits/stdc++.h>

auto input() {
    int n = 0;
    int64_t D = 0;
    std::vector<int64_t> schedule;

    std::cin >> n >> D;
    for (auto i = 0; i < n; ++i) {
        int64_t tmp;
        std::cin >> tmp;

        schedule.push_back(tmp);
    }

    return std::make_tuple(D, schedule);
}

template <typename T>
auto process(T& tuple) {
    auto D = std::get<0>(tuple);
    auto& schedule = std::get<1>(tuple);
    int64_t result = D;

    std::reverse(schedule.begin(), schedule.end());

    for (auto&& day : schedule) {
        result -= (result % day);
    }

    return result;
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
