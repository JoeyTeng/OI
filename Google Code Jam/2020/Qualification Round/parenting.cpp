// Parenting Partnering Returns
#include <bits/stdc++.h>

auto input() {
    int N = 0;
    std::vector<std::pair<int, int>> tasks;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int s;
        int e;

        std::cin >> s >> e;
        tasks.push_back(std::make_pair(s, e));
    }
    return tasks;
}

auto process(std::vector<std::pair<int, int>>& _tasks) {
    std::string _res;
    std::string res;

    std::vector<std::pair<int, int>> tasks(_tasks);
    std::sort(tasks.begin(), tasks.end());

    int curr_c = 0;
    int curr_j = 0;
    for (auto&& task : tasks) {
        if (task.first >= curr_c) {
            curr_c = task.second;
            res.push_back('C');
        } else if (task.first >= curr_j) {
            curr_j = task.second;
            res.push_back('J');
        } else {
            return std::string("IMPOSSIBLE");
        }
    }

    for (int i = 0; i < _tasks.size(); ++i) {
        for (int j = 0; j < tasks.size(); ++j) {
            if (_tasks[i] == tasks[j]) {
                _res.push_back(res[j]);
                tasks[j] = std::make_pair(-1, -1);

                break;
            }
        }
    }

    return _res;
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto tasks = input();
        auto result = process(tasks);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
