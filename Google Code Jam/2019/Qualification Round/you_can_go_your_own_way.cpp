/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: you_can_go_your_own_way.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 06-Apr-2019
 */
#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n = 0;
    std::cin >> n;

    std::string p;
    std::cin >> p;

    for (int i = 0; i < p.size(); ++i) {
      if (p[i] == 'S') {
        p[i] = 'E';
      } else {
        p[i] = 'S';
      }
    }
    std::cout << "Case #" << t << ": " << p << std::endl;
  }
  return 0;
}
