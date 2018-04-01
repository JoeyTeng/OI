/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: bathroom_stalls.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 01-Apr-2018
 */

#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int64_t N = 0;
    int64_t K = 0;
    std::cin >> N >> K;

    int64_t power = std::log2(K);
    int64_t divisor = std::pow(2, power);
    std::cout << "Case #" << t << ": " << (((N - K + divisor) / divisor) >> 1)
              << ' ' << (((N - K) / divisor) >> 1) << std::endl;
    // std::cout << "N: " << N << " K: " << K << " Divisor: " << divisor
    //           << std::endl;
  }

  return 0;
}
