/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: foregone_solution.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 06-Apr-2019
 */
#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    std::string n;
    std::cin >> n;

    std::string a;
    std::string b;
    bool b_has_highest_digit = false;
    for (auto i : n) {
      if (i == '4') {
        a.push_back('1');
        b.push_back('3');
        b_has_highest_digit = true;
      } else if (b_has_highest_digit) {
        a.push_back(i);
        b.push_back('0');
      } else {
        a.push_back(i);
      }
    }
    std::cout << "Case #" << t << ": " << a << ' ' << b << std::endl;
  }

  return 0;
}
