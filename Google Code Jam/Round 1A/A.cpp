// A. Alphabet Cake

#include<bits/stdc++.h>

int check(std::vector<std::vector<int>>& used, std::vector<std::string>& grid, int a, int b, int k, int l) {
    char initial = '?';
    for (int i = a; i <= k; ++i) {
        for (int j = b; j <= l; ++j) {
            if (grid.at(i).at(j) != '?') {
                if (used.at(i).at(j)) {
                    // std::cout << "used " << a << ' ' << b << ' ' << k << ' ' << l << ' ' << initial << std::endl;
                    return 1;
                }
                else if (initial != '?' && grid.at(i).at(j) != initial) {
                    // std::cout << "breaking " << a << ' ' << b << ' ' << k << ' ' << l << ' ' << initial << std::endl;
                    return 1;
                }
                else {
                    initial = grid.at(i).at(j);
                }
            }
        }
    }

    if (initial == '?') {
        return 0;
    }

    // std::cout << "coloring " << a << ' ' << b << ' ' << k << ' ' << l << ' ' << initial << std::endl;
    for (int i = a; i <= k; ++i) {
        for (int j = b; j <= l; ++j) {
            grid.at(i).at(j) = initial;
            used.at(i).at(j) = 1;
        }
    }
/*
    std::ostream_iterator<int> str_out(std::cout, "");
    for (int i = 0; i < grid.size(); ++i) {
        std::copy(used.at(i).begin(), used.at(i).end(), str_out);
        std::cout << std::endl;
    }
    std::cout << std::endl;
*/
    return 0;
}


int main() {
    int T = 0;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int R = 0;
        int C = 0;
        std::cin >> R >> C;

        std::vector<std::string> grid;
        for (int i = 0; i < R; ++i) {
            std::string row;
            std::cin >> row;
            grid.push_back(row);
        }

        std::vector<int> tmp(grid.at(0).size(), 0);
        std::vector<std::vector<int>> used(grid.size(), tmp);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.at(i).size(); ++j) {
                for (int k = grid.size() - 1; k >= 0; --k) {
                    for (int l = grid.at(k).size() - 1; l >= 0; --l) {
                        check(used, grid, i, j, k, l);
                    }
                }
            }
        }

        std::cout << "Case #" << t + 1 << ":" << std::endl;
        std::ostream_iterator<std::string> str_out(std::cout, "\n");
        std::copy(grid.begin(), grid.end(), str_out);
    }

    return 0;
}
