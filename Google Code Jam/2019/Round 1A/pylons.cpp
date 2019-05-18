/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: pylons.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 13-Apr-2019
 */
#include <bits/stdc++.h>

bool valid(const std::pair<int, int> &current,
           const std::pair<int, int> &next) {
  if (current.first != next.first && current.second != next.second &&
      current.first - current.second != next.first - next.second &&
      current.first + current.second != next.first + next.second) {
    return true;
  }
  return false;
}

bool dfs(std::vector<std::pair<int, int>> &candidates,
         const std::pair<int, int> &current,
         std::vector<std::pair<int, int>> &jump_sequence) {
  if (candidates.empty()) {
    return true;
  }
  for (int i = 0; i < candidates.size(); ++i) {
    if (valid(current, candidates[i])) {
      std::swap(candidates[i], candidates.back());
      auto tmp = candidates.back();
      candidates.pop_back();
      jump_sequence.push_back(tmp);
      if (dfs(candidates, tmp, jump_sequence)) {
        return true;
      }
      jump_sequence.pop_back();
      candidates.push_back(tmp);
      std::swap(candidates[i], candidates.back());
    }
  }
  return false;
}

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    std::string ans;
    int r = 0;
    int c = 0;
    std::vector<std::pair<int, int>> candidates;

    std::cin >> r >> c;

    auto start_point = std::make_pair(1, 1);
    std::vector<std::pair<int, int>> jump_sequence;

    int odds = 0;
    int maximum = 0;
    for (int first = 1; first <= r; ++first) {
      for (int second = 1; second <= c; ++second) {
        int count = 0;
        for (int i = 1; i <= r; ++i) {
          for (int j = 1; j <= c; ++j) {
            if (valid(std::make_pair(first, second), std::make_pair(i, j))) {
              ++count;
            }
          }
        }
        if (count > maximum) {
          maximum = count;
          start_point = std::make_pair(first, second);
        }
        if (count == 0) {
          goto _impossible;
        }
      }
    }

    // std::cout << "start point: " << start_point.first << ' '
    //           << start_point.second << std::endl;
    jump_sequence.push_back(start_point);
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (i != start_point.first || j != start_point.second) {
          candidates.push_back(std::make_pair(i, j));
        }
      }
    }

    if (dfs(candidates, start_point, jump_sequence)) {
      std::cout << "Case #" << t << ": POSSIBLE" << std::endl;
      for (auto i : jump_sequence) {
        std::cout << i.first << ' ' << i.second << std::endl;
      }
    } else {
    _impossible:
      std::cout << "Case #" << t << ": IMPOSSIBLE" << std::endl;
    }
  }

  return 0;
}
