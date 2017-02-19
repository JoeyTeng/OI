// Flags

#include<bits/stdc++.h>

int main() {
    int N = 0;
    std::vector<std::pair<int, int> > coordinate;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::pair<int, int> tmp;
        std::cin >> tmp.first >> tmp.second;
        if (tmp.first > tmp.second) {
            std::swap(tmp.first, tmp.second);
        }
        coordinate.push_back(tmp);
    }
    std::sort(coordinate.begin(), coordinate.end());

    auto ans = std::make_pair(INT_MAX, INT_MAX);
    auto last = coordinate.front();

    for (auto i = ++coordinate.begin(); i != coordinate.end() ; ++i) {
        int x1 = i -> first - last.first;
        int x2 = i -> first - last.second;
        int y1 = i -> second - last.first;
        int y2 = i -> second - last.second;

        ans.first = std::min(ans.first, std::max(x1, x2));
        ans.second = std::min(ans.second, std::max(y1, y2));
        last = *i;
    }
    std::cout << std::max(ans.first, ans.second) << std::endl;

    return 0;
}
