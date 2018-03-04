/**
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: snow_boots.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 25-Feb-2018
 */

// Snow Boots
#include <bits/stdc++.h>
#define INPUT "snowboots.in"
#define OUTPUT "snowboots.out"

std::ifstream cin(INPUT);
std::ofstream cout(OUTPUT);

int main() {
  std::vector<int> path;
  int N = 0;
  int B = 0;
  cin >> N >> B;
  for (int i = 0; i < N; ++i) {
    int tmp;
    cin >> tmp;
    path.push_back(tmp);
  }
  for (int i = 0; i < B; ++i) {
    int depth;
    int length;
    cin >> depth >> length;

    int interval = 0;
    for (int j = 0; j < N; ++j) {
      int count = 0;
      for (; j < N && path[j] > depth; ++j) {
        ++count;
      }
      interval = std::max(interval, count);
    }
    // std::cout << interval << ' ' << depth << std::endl;
    cout << (interval < length) << std::endl;
  }

  return 0;
}
