/**
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: knapsack.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 03-Mar-2018
 */

#include <bits/stdc++.h>

const int S_MAX = (2000 << 1) + 10;

int main() {
  int S = 0;
  int N = 0;
  std::vector<int> V;
  std::vector<int> W;
  std::vector<int> K;

  std::cin >> S >> N;
  for (int i = 0; i < N; ++i) {
    int v = 0;
    int w = 0;
    int k = 0;
    std::cin >> v >> w >> k;
    k = std::min(k, S / w);
    V.push_back(v);
    W.push_back(w);
    K.push_back(k);
  }

  long long dp[S_MAX] = {0};
  for (int i = 0; i < N; ++i) {
    for (int x = S; x >= W[i]; --x) {
      for (int k = 1; k <= std::min(x / W[i], K[i]); ++k) {
        dp[x] = std::max(dp[x], dp[x - W[i] * k] + V[i] * k);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= S; ++i) {
    ans = std::max(ans, dp[i]);
  }
  std::cout << ans << std::endl;
  return 0;
}
