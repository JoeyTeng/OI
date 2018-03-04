/**
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: snail.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 03-Mar-2018
 */

#include <bits/stdc++.h>

int main() {
  long long H = 0;
  long long N = 0;
  long long total = 0;
  long long maximum = 0;
  std::vector<long long> P;

  std::cin >> H >> N;
  for (int i = 0; i < N; ++i) {
    long long tmp = 0;
    std::cin >> tmp;
    P.push_back(tmp);
    total += tmp;
    maximum = std::max(tmp, maximum);
  }
  for (int i = 0; i < N; ++i) {
    P.push_back(P[i]);
  }
  for (int i = 0; i < N; ++i) {
    P.push_back(P[i]);
  }

  if (total <= 0) {
    long long phase = 0;
    long long H_MAX = H;
    P.push_back(0);
    while (H > 0 && phase <= N) {
      H = std::min(H_MAX, H - P[phase]);
      ++phase;
    }
    if (phase == N + 1) {
      std::cout << "-1 -1" << std::endl;
    } else {
      std::cout << "0 " << phase - 1 << std::endl;
    }
    return 0;
  }

  if (H * N <= 10000) {
    long long day = 0;
    long long phase = 0;
    long long H_MAX = H;
    while (H > 0) {
      H = std::min(H_MAX, H - P[phase]);
      ++phase;
      day += phase / N;
      phase %= N;
    }

    --day;
    --phase;
    phase += N;
    day += phase / N;
    phase %= N;

    std::cout << day << ' ' << phase << std::endl;

    return 0;
  }

  long long days = std::max((H - maximum) / total, 0ll);
  long long remaining = H - days * total;
  long long phase = 0;
  long long H_MAX = H;

  // std::cout << "day " << days << std::endl;
  while (remaining > 0) {
    remaining = std::min(H_MAX, remaining - P[phase]);
    // std::cout << phase << std::endl;
    ++phase;
    days += phase / N;
    phase %= N;
  }
  phase -= 1;
  days -= 1;
  phase += N;
  days += phase / N;
  phase %= N;

  std::cout << days << ' ' << phase << std::endl;

  return 0;
}
