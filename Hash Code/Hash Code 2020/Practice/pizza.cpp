#include <bits/stdc++.h>

int cmp(const std::pair<int, std::pair<int, int>> &left,
        const std::pair<int, std::pair<int, int>> &right) {
    return (left.first < right.first) ||
           (left.first == right.first &&
            left.second.second < right.second.second);
}

int main() {
    int M = 0;
    int N = 0;
    std::vector<int> s;
    std::vector<std::pair<int, std::pair<int, int>>> f;
    std::set<int> appeared;

    std::cin >> M >> N;
    for (auto i = 0; i < N; ++i) {
        int tmp;
        std::cin >> tmp;
        s.push_back(tmp);
    }

    std::cerr << "input" << std::endl;

    for (auto i = 0; i < N; ++i) {
        auto type = s[i];
        auto size = f.size();

        if (i % 50 == 0) {
            std::cerr << i << "-th iteration" << std::endl;
        }

        for (auto j = 0; j < size; ++j) {
            auto prev = f[j];
            auto new_sum = prev.first + type;
            if (new_sum <= M && appeared.find(new_sum) == appeared.end()) {
                f.push_back(std::make_pair(
                    new_sum, std::make_pair(prev.second.second, i)));
                appeared.insert(new_sum);
            }
        }

        f.push_back(std::make_pair(type, std::make_pair(-1, i)));
        appeared.insert(type);

        sort(f.begin(), f.end(), cmp);
    }

    // TODO: DEBUG:
    for (auto i : appeared) {
        std::cerr << " " << i;
    }
    std::cerr << std::endl;

    std::cerr << "output" << std::endl;

    std::vector<int> combination;
    auto it = f.back();
    do {
        auto i = it.second.second;
        auto prev = it.second.first;
        // std::cout << "prev: " << prev << " i: " << i << std::endl;

        combination.push_back(i);

        it = *std::lower_bound(
            f.begin(), f.end(),
            std::make_pair(it.first - s[i], std::make_pair(prev, prev)), cmp);
    } while (it.second.first != -1);
    combination.push_back(it.second.second);
    std::sort(combination.begin(), combination.end());

    std::cout << combination.size() << std::endl;
    for (auto index : combination) {
        std::cout << index << ' ';
    }
    std::cout << std::endl;

    // TODO: DEBUG
    // for (auto i : f) {
    //     std::cout << i.first << ' ' << i.second.first << " -> "
    //               << i.second.second << std::endl;
    // }

    return 0;
}
