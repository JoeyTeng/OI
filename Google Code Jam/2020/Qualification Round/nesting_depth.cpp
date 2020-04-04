#include <bits/stdc++.h>

auto input() {
    std::string str;
    std::cin >> str;

    return std::move(str);
}

auto process(std::string& s) {
    std::string res;
    int depth = 0;

    for (auto&& _digit : s) {
        int digit = _digit - '0';

        for (; depth < digit; ++depth) {
            res.push_back('(');
        }
        for (; depth > digit; --depth) {
            res.push_back(')');
        }

        res.push_back(_digit);
    }

    for (; depth > 0; --depth) {
        res.push_back(')');
    }

    return std::move(res);
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto str = input();
        auto result = process(str);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
