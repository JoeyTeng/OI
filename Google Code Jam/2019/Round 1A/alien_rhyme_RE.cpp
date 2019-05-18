/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: alien_rhyme.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 13-Apr-2019
 */
#include <bits/stdc++.h>

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
      for (int j = 0; j < (tmp.size() >> 1); ++j) {
        // reverse
        std::swap(tmp[j], tmp[tmp.size() - j - 1]);
      }
      words.push_back(tmp);
    }
    // std::sort(words.begin(), words.end());

    // std::set<std::string> prefix_set;
    // for (int i = words.size() - 1; i > 0; --i) {
    //   std::string prefix; // common prefix, i.e. accent-suffix in the Q
    //   int max_len = std::min(words[i].size(), words[i - 1].size());

    //   for (int j = 0; j < max_len; ++j) {
    //     if (words[i][j] == words[i - 1][j]) {
    //       prefix.push_back(words[i][j]);
    //     } else {
    //       break;
    //     }
    //   }
    //   std::cout << "i: " << i << " prefix len " << prefix.size() << std::endl
    //             << words[i] << std::endl
    //             << words[i - 1] << std::endl;
    //   while (!prefix.empty()) {
    //     if (prefix_set.find(prefix) == prefix_set.end()) {
    //       ans += 2;
    //       --i;
    //       prefix_set.insert(prefix);
    //       break;
    //     } else {
    //       prefix.pop_back();
    //     }
    //   }
    //   std::cout << prefix << ' ' << prefix_set.size() << std::endl;
    // }

    std::map<std::string, int> prefix_count;
    std::vector<std::string> keys;
    for (auto word : words) {
      std::string prefix;
      for (auto letter : word) {
        prefix.push_back(letter);
        if (prefix_count.find(prefix) == prefix_count.end()) {
          prefix_count[prefix] = 1;
          keys.push_back(prefix);
        } else {
          ++prefix_count[prefix];
        }
      }
    }
    std::sort(keys.begin(), keys.end(),
              [](auto a, auto b) { return a.size() > b.size(); });

    while (!keys.empty()) {
      bool skip = true;
      for (int i = 0; i < keys.size(); ++i) {
        // std::cout << keys[i] << ' ' << prefix_count[keys[i]] << " ans " <<
        // ans
        //           << std::endl;
        if (prefix_count[keys[i]] == 2) {
          ans += 2;

          std::string prefix = keys[i];
          while (!prefix.empty()) {
            prefix_count[prefix] -= 2;
            prefix.pop_back();
          }
          keys.erase(std::next(keys.begin(), i));
          --i;
          skip = false;
        } else if (prefix_count[keys[i]] <= 1) {
          keys.erase(std::next(keys.begin(), i));
          --i;
        }
      }
      if (skip) {
        break;
      }
    }
    // std::cout << "remainder: " << keys.size() << std::endl;
    // for (auto key : keys) {
    //   std::cout << key << ' ' << prefix_count[key] << std::endl;
    // }
    while (!keys.empty()) {
      int minimum_count = INT_MAX;
      int index = -1;
      for (int i = 0; i < keys.size(); ++i) {
        if (prefix_count[keys[i]] <= 1) {
          keys.erase(std::next(keys.begin(), i));
          --i;
        } else if (prefix_count[keys[i]] < minimum_count) {
          minimum_count = prefix_count[keys[i]];
          index = i;
        }
      }
      //   std::cout << index << ' ' << minimum_count << std::endl;
      if (index != -1) {
        ans += 2;

        std::string prefix = keys[index];
        while (!prefix.empty()) {
          prefix_count[prefix] -= minimum_count;
          prefix.pop_back();
        }
        keys.erase(std::next(keys.begin(), index));
      } else if (prefix_count[keys[index]] <= 0) {
        keys.erase(std::next(keys.begin(), index));
      }
    }

    std::cout << "Case #" << t << ": " << ans << std::endl;
  }

  return 0;
}
