// general https://dunjudge.me/contest/481/problems/165/

// Union-find set AC

#include <bits/stdc++.h>

auto find(int pos, std::vector<std::pair<int, int> >& set) {
    if (pos == set.at(pos).first) {
        return set.at(pos);
    } else {
        auto p = find(set.at(pos).first, set);
        set.at(pos).first = p.first;
        return p;
    }
}

void union_(int pos_a, int pos_b, std::vector<std::pair<int, int> >& set) {
    set.at(pos_b).first = pos_a;
}

int main() {
    int N = 0;
    int M = 0;

    std::vector<std::pair<int, int> > power; // pair<number, power>

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int p = 0;
        std::cin >> p;
        power.push_back(std::make_pair(i, p));
    }

    for (int i = 0; i < M; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        auto p_a = find(a - 1, power);
        auto p_b = find(b - 1, power);

        if (p_a.second == p_b.second) {
            std::cout << -1 << std::endl;
        } else if (p_a.second > p_b.second) {
            std::cout << p_a.first + 1 << std::endl;
            union_(p_a.first, p_b.first, power);
        } else {
            std::cout << p_b.first + 1 << std::endl;
            union_(p_b.first, p_a.first, power);
        }
    }

    return 0;
}
