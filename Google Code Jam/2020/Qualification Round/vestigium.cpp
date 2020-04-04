// C++ 14
#include <bits/stdc++.h>

auto input() {
    int n = 0;
    std::vector<std::vector<int>> matrix;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::vector<int> row;

        for (int j = 0; j < n; ++j) {
            int cell = 0;

            std::cin >> cell;
            row.push_back(cell);
        }
        matrix.push_back(std::move(row));
    }

    return std::make_tuple(n, matrix);
}

auto process(int N, std::vector<std::vector<int>>& matrix) {
    int trace = 0;
    int rows = 0;
    int columns = 0;

    for (int i = 0; i < N; ++i) {
        int row_repeat = 0;
        int col_repeat = 0;
        std::vector<int> row(N + 1, 0);
        std::vector<int> col(N + 1, 0);

        trace += matrix[i][i];

        for (int j = 0; j < N; ++j) {
            if (row[matrix[i][j]]) {
                row_repeat = 1;
            }
            if (col[matrix[j][i]]) {
                col_repeat = 1;
            }

            row[matrix[i][j]] = 1;
            col[matrix[j][i]] = 1;
        }
        rows += row_repeat;
        columns += col_repeat;
    }

    return std::make_tuple(trace, rows, columns);
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto input_tuple = input();
        auto N = std::get<0>(input_tuple);
        auto matrix = std::get<1>(input_tuple);

        auto result = process(N, matrix);
        auto k = std::get<0>(result);
        auto r = std::get<1>(result);
        auto c = std::get<2>(result);

        std::cout << "Case #" << i + 1 << ": " << k << ' ' << r << ' ' << c
                  << std::endl;
    }

    return 0;
}
