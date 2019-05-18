/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: new_elements_part_2.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 19-May-2019
 */
#include <bits/stdc++.h>

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int64_t cmp(std::pair<int64_t, int64_t> a, std::pair<int64_t, int64_t> b) {
  if (a.first * b.second < a.second * b.first) {
    return true;
  }
  return false;
}

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N = 0;
    std::cin >> N;
    std::vector<std::pair<int64_t, int64_t>> molecule;
    std::vector<std::pair<int64_t, int64_t>> inequality;
    for (int i = 0; i < N; ++i) {
      int64_t c = 0;
      int64_t j = 0;
      std::cin >> c >> j;
      molecule.push_back(std::make_pair(c, j));
    }
    for (int i = 1; i < N; ++i) {
      // ax + by < 0
      inequality.push_back(
          std::make_pair(molecule[i - 1].first - molecule[i].first,
                         molecule[i].second - molecule[i - 1].second));
      int64_t _gcd =
          std::abs(gcd(inequality.back().first, inequality.back().second));
      if (_gcd != 1) {
        inequality.back().first /= _gcd;
        inequality.back().second /= _gcd;
      }
    }
    int IMPOSSIBLE = 0;
    // std::cout << std::endl;
    for (auto p : inequality) {
      //   std::cout << ' ' << p.first << ' ' << p.second << std::endl;
      if ((p.first == 0 && p.second < 0) || (p.first > 0 && p.second == 0)) {
        IMPOSSIBLE = 1;
        break;
      }
    }
    std::pair<int64_t, int64_t> checking_negative_pair = std::make_pair(0, 1);
    for (auto p : inequality) {
      if (cmp(p, checking_negative_pair)) {
        checking_negative_pair = p;
      }
    }
    for (auto p : inequality) {
      if (p != checking_negative_pair &&
          (cmp(p, checking_negative_pair) ||
           (p.first * checking_negative_pair.second ==
            p.second * checking_negative_pair.first))) {
        IMPOSSIBLE = 1;
        break;
      }
    }
    if (IMPOSSIBLE == 1) {
      std::cout << "Case #" << t << ": "
                << "IMPOSSIBLE" << std::endl;
      continue;
    }

    std::sort(inequality.begin(), inequality.end(), cmp);

    int64_t _min = INT_MAX;
    int index = -1;
    for (int i = N - 2; i > -1; --i) {
      if (inequality[i].first == 0 || inequality[i].second == 0) {
        continue;
      }
      if (_min > std::abs(inequality[i].first)) {
        _min = std::abs(inequality[i].first);
        index = i;
      }
    }
    // std::cout << index << std::endl;
    int64_t c = 0;
    int64_t j = 0;
    if (index == -1) {
      c = j = 1;
    } else {
      c = inequality[index].first;
      j = inequality[index].second;
      int64_t _gcd = gcd(c, j);
      //   std::cout << "c j " << c << ' ' << j << std::endl;
      c /= _gcd;
      j /= _gcd;
      if (_gcd > 0) {
        ++j;
      } else {
        ++c;
      }
    }

    std::cout << "Case #" << t << ": " << c << ' ' << j << std::endl;
  }

  return 0;
}
