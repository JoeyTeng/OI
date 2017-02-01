// lol

#include<bits/stdc++.h>

int main() {
    int N = 0;
    int64_t total = 0;
    int64_t L_left = 0;
    int64_t L_right = 0;

    std::string str;

    std::cin >> N >> str;

    for (auto i : str) {
        if (i == 'L') {
            ++L_right;
        }
    }

    for (auto i : str) {
        if (i == 'L') {
            ++L_left;
            --L_right;
        }
        if (i == 'O') {
            total += L_left * L_right;
        }
    }

    std::cout << total << std::endl;

    return 0;
}
