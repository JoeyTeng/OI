/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: senate_evacuation.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 01-Apr-2018
 */

#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N = 0;
    std::vector<int> P;
    std::cin >> N;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::less<std::pair<int, int>>>
        queue;

    for (int i = 0; i < N; ++i) {
      int tmp;
      std::cin >> tmp;
      queue.push(std::make_pair(tmp, i));
    }
    std::cout << "Case #" << t << ": ";
    while (queue.size() > 2) {
      int count = queue.top().first;
      int index = queue.top().second;
      queue.pop();

      std::cout << char('A' + index) << ' ';
      --count;
      if (count) {
        queue.push(std::make_pair(count, index));
      }
    }
    int count = queue.top().first;
    int a = queue.top().second;
    queue.pop();
    int b = queue.top().second;
    while (count) {
      std::cout << char(a + 'A') << char(b + 'A') << ' ';
      --count;
    }
    std::cout << std::endl;
  }

  return 0;
}
