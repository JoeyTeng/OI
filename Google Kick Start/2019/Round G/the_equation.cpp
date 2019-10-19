/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: the_equation.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 19-Oct-2019
 */

#include <bits/stdc++.h>

int N;
int64_t M;
int bits[64] = {0};

int64_t dfs(int i, int64_t current) {
  int64_t ans = 0;
  // std::cout << "dfs: " << i << " " << current << std::endl;
  if (current > M) {
    return -1;
  }
  if (i == 0) {
    return 0;
  }
  // std::cout << "dfs via 1" << std::endl;
  if ((ans = dfs(i - 1, current + ((N - bits[i]) << i))) != -1) {
    return ans | (1 << i);
  }
  // std::cout << "dfs via 0" << std::endl;
  return dfs(i - 1, current + (bits[i] << i));
}

int main() {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int64_t maximum = 0;
    N = 0;
    M = 0;
    std::memset(bits, 0, sizeof(bits));

    std::cin >> N >> M;
    maximum = std::max(maximum, M);
    for (int i = 0; i < N; ++i) {
      int64_t tmp;
      std::cin >> tmp;
      maximum = std::max(maximum, tmp);
      for (int j = 0; tmp > 0; tmp /= 2, ++j) {
        bits[j] += tmp & 1;
      }
    }

    int bits_maximum = 0;
    for (int i = maximum; i > 0; i /= 2, bits_maximum++) {
    }

    // std::cout << "bits: ";
    // for (int i = bits_maximum; i >= 0; --i) {
    //   std::cout << bits[i] << ' ';
    // }
    // std::cout << std::endl;

    int64_t ans = 0;
    if ((ans = dfs(bits_maximum, 0)) != -1) {
      std::cout << "Case #" << t << ": " << ans << std::endl;
    } else {
      std::cout << "Case #" << t << ": -1" << std::endl;
    }
  }

  return 0;
}
