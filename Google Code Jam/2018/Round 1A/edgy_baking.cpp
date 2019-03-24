/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: edgy_baking.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 14-Apr-2018
 */

#include<bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N = 0;
        int P = 0;
        std::cin >> N >> P;

        double min_perimeter = 0;
        double max_perimeter = 0;
        for (int i = 0; i < N; ++i) {
            int W;
            int H;
            std::cin >> W >> H;
            min_perimeter += (W + H) * 2;
            max_perimeter += (W + H) * 2 + std::sqrt(W * W + H * H) * 2;
        }
        std::cout << "Case #" << t << ": ";
        std::cout << std::fixed << std::setprecision(15) << std::min((P * 1.0), max_perimeter) << std::endl;
        // std::cout << min_perimeter << ' ' << max_perimeter << std::endl;
    }

    return 0;
}