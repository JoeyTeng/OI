// WA
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

const int X_MAX = 1000;

int main() {
    int n = 0;
    int r = 0;
    double y[X_MAX] = {0};

    std::cin >> n >> r;
    double r_sqr = 4 * r * r;
    for (int i = 0; i < X_MAX; ++i) {
        y[i] -= double(r);
    }
    for (int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        y[x] = y[x] + 2 * r;
        for (int j = std::max(0, x - 2 * r); j < X_MAX && j <= x + 2 * r; ++j) {
            if (j == x) {
                continue;
            }
            y[x] = std::max(y[x], y[j] + std::sqrt(r_sqr - (x - j) * (x - j)));
        }
        std::cout << std::setprecision(8) << y[x] << std::endl;
    }

    return 0;
}