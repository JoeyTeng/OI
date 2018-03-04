/**
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: island.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 03-Mar-2018
 */

#include <bits/stdc++.h>

const int N_MAX = 200000 + 20;

int main() {
  int N = 0;
  int M = 0;
  int tree[N_MAX] = {0};
  std::vector<int> graph[N_MAX];
  int degree[N_MAX] = {0};
  std::deque<int> factors;
  int count[N_MAX] = {0};

  std::cin >> N >> M;
  if (M <= 1) {
    for (int i = 2; i < N; ++i) {
      std::cout << i << ' ' << 1 << std::endl;
    }
    return 0;
  }
  for (int i = 0; i < N + M; ++i) {
    int s = 0;
    int d = 0;
    std::cin >> s >> d;
    if (s <= N) { // s is a town
      ++count[d];
    } else if (d <= N) {
      ++count[s];
    } else {
      graph[s].push_back(d);
      graph[d].push_back(s);
      degree[s]++;
      degree[d]++;
    }
  }

  std::queue<int> queue;
  int queued[N_MAX] = {0};
  for (int i = N + 1; i <= N + M; ++i) {
    if (degree[i] <= 1) {
      queue.push(i);
      queued[i] = 1;
    }
  }

  while (!queue.empty()) {
    int current = queue.front();
    // std::cout << "current " << current << std::endl;
    queue.pop();
    factors.push_back(count[current]);
    for (auto node : graph[current]) {
      degree[node]--;
      count[node] += 1;
      if (degree[node] <= 1 && !queued[node] && node > N) {
        queue.push(node);
        queued[node] = 1;
        // std::cout << " push " << node << std::endl;
      }
    }
  }

  std::sort(factors.begin(), factors.end(), std::greater<int>());
  // factors.pop_front();

  int index = 0;
  factors.push_back(0);
  factors.push_back(0);
  int factor = factors[0];
  while (factors[index + 1] >= factor) {
    index++;
  }
  if (index > 0) {
    std::cout << factor << ' ' << index << std::endl;
  }
  --factor;
  for (; factor > 1; --factor) {
    while (factors[index + 1] >= factor) {
      index++;
    }
    std::cout << factor << ' ' << index + 1 << std::endl;
  }

  return 0;
}
