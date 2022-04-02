#include <bits/stdc++.h>

void solution(
    int t,
    std::vector<int>& s
) {
    std::cout << "Case #" << t << ": ";

    int count = 0;
    std::sort(s.begin(), s.end());
    for (const auto& si : s) {
        if (si > count) {
            count++;
        }
    }

    std::cout << count << std::endl;
}

int main() {
    int t = 0;
    int n = 0;
    std::cin >> t;

    for (int it = 1; it <= t; ++it) {
        std::vector<int> s;

        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            int si;
            std::cin >> si;
            s.push_back(si);
        }
        solution(it, s);
    }

    return 0;
}
