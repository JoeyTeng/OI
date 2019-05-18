/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: alien_rhyme.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 13-Apr-2019
 */
#include <bits/stdc++.h>

int dfs(std::vector<std::string> &words) {
  //   std::cout << words.size() << std::endl;
  if (words.size() < 2) {
    return 0;
  }
  if (words.size() == 2) {
    // std::cout << "2: " << std::endl;
    // for (auto word : words) {
    //   std::cout << word << std::endl;
    // }
    // std::cout << std::endl;

    return 2;
  }
  //   for (auto word : words) {
  //     std::cout << word << std::endl;
  //   }
  //   std::cout << std::endl;
  std::vector<std::string> candidates[26];
  int count = 0;
  for (auto word : words) {
    if (!word.empty()) {
      std::string tmp(word.begin(), word.end() - 1);
      candidates[word.back() - 'A'].push_back(tmp);
    } else {
      ++count;
    }
  }
  int ans = 0;
  if (count >= 2) {
    ans += 2;
  }
  for (int i = 0; i < 26; ++i) {
    ans += dfs(candidates[i]);
  }
  if (words.size() - ans >= 2) {
    ans += 2;
  }
  return ans;
}

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    std::vector<std::string> words;
    int n = 0;
    int ans = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
      std::string tmp;
      std::cin >> tmp;
      words.push_back(tmp);
    }

    std::vector<std::string> candidates[26];
    for (auto word : words) {
      std::string tmp(word.begin(), word.end() - 1);
      candidates[word.back() - 'A'].push_back(tmp);
    }
    for (int i = 0; i < 26; ++i) {
      ans += dfs(candidates[i]);
    }

    std::cout << "Case #" << t << ": " << ans << std::endl;
  }

  return 0;
}
