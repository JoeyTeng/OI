/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: steed2.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 01-Apr-2018
 */
#include <bits/stdc++.h>

int main() {
  std::cout << std::fixed << std::setprecision(6);
  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    int D = 0;
    int N = 0;
    std::cin >> D >> N;

    double _max = DBL_MIN;
    for (int i = 0; i < N; ++i) {
      int position;
      int speed;
      std::cin >> position >> speed;
      double _time = double(D - position) / speed;
      _max = std::max(_max, _time);
    }
    std::cout << "Case #" << t << ": " << D / _max << std::endl;
  }

  return 0;
}
