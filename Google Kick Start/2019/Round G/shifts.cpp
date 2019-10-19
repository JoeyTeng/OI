/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: shifts.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 19-Oct-2019
 */

#include <bits/stdc++.h>

std::vector<int> A;
std::vector<int> B;

int64_t dfs(int N, int H, int HA, int HB) {
  if (HA < H || HB < H) {
    return 0;
  }
  if (N == -1) {
    return 1;
  }

  return dfs(N - 1, H, HA, HB) + dfs(N - 1, H, HA - A[N], HB) +
         dfs(N - 1, H, HA, HB - B[N]);
}

int main() {
  int T;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    int N = 0;
    int64_t H = 0;
    int64_t count = 0;
    int64_t HA = 0;
    int64_t HB = 0;
    A.clear();
    B.clear();

    std::cin >> N >> H;
    for (int i = 0; i < N; ++i) {
      int tmp;
      std::cin >> tmp;
      A.push_back(tmp);
      HA += tmp;
    }
    for (int i = 0; i < N; ++i) {
      int tmp;
      std::cin >> tmp;
      B.push_back(tmp);
      HB += tmp;
    }

    std::cout << "Case #" << t << ": ";
    if (HA < H || HB < H) {
      std::cout << 0 << std::endl;
      continue;
    }

    std::cout << dfs(N - 1, H, HA, HB) << std::endl;
  }
  return 0;
}
