/**
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: dirtraverse.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 25-Feb-2018
 */

// Directory Traversal
#include <bits/stdc++.h>
#define INPUT "dirtraverse.in"
#define OUTPUT "dirtraverse.out"

std::ifstream cin(INPUT);
std::ofstream cout(OUTPUT);

int main() {
  int N = 0;
  cin >> N;
  std::vector<std::vector<int>> tree(N); // Son of a[i]
  std::vector<int> father(N);
  std::vector<int> length(N);
  std::vector<int> number_of_files(N, 0);
  std::vector<long long> sum_of_path_length(N, 0);
  std::vector<int> son_processed(N, 0);
  std::vector<int> files;
  std::queue<int> queue;

  father[0] = -1;
  for (int i = 0; i < N; ++i) {
    int m;
    std::string tmp;
    cin >> tmp >> m;
    length[i] = tmp.size();
    for (int j = 0; j < m; ++j) {
      int tmp;
      cin >> tmp;
      tree[i].push_back(tmp - 1);
      father[tmp - 1] = i;
    }
    if (!m) {
      queue.push(i);
      files.push_back(i);
      number_of_files[i] = 1;
      length[i] -= 1;
    }
  }

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();
    if (father[current] != -1) {
      sum_of_path_length[father[current]] +=
          sum_of_path_length[current] +
          number_of_files[current] * (length[current] + 1);
      number_of_files[father[current]] += number_of_files[current];

      ++son_processed[father[current]];
      if (son_processed[father[current]] == tree[father[current]].size()) {
        queue.push(father[current]);
        son_processed[father[current]] = 0;
      }
    }
    // std::cout << current << ' ' << father[current] << ' '
    //           << sum_of_path_length[current] << ' '
    //           << number_of_files[current]
    //           << std::endl;
  }

  // std::cout << "2nd" << std::endl;

  long long ans = LLONG_MAX;
  for (int i = 0; i < files.size(); ++i) {
    queue.push(files[i]);
  }

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();

    long long tot_length = sum_of_path_length[0];
    long long reduction = 0;
    long long file_count = 0;
    int pos = current;
    int depth = 0;

    // std::cout << current << ' ' << tot_length << ' ' << reduction
    //           << std::endl;
    while (pos != 0) {
      if (tree[pos].size() != 0) {
        reduction += (length[pos] + 1) * (number_of_files[pos] - file_count);
      }
      // std::cout << "  " << length[pos] + 1 << ' ' << number_of_files[pos]
      //           << ' ' << file_count << ' ' << reduction << std::endl;
      file_count += number_of_files[pos];
      depth += 1;

      pos = father[pos];
    }

    pos = current;
    file_count = 0;
    while (pos != 0) {
      if (tree[pos].size() != 0) {
        reduction -= 3 * depth * (number_of_files[pos] - file_count);
      }
      file_count += number_of_files[pos];
      depth -= 1;

      pos = father[pos];
    }
    tot_length -= reduction;
    ans = std::min(ans, tot_length);

    ++son_processed[father[current]];
    if (son_processed[father[current]] == tree[father[current]].size()) {
      queue.push(father[current]);
      son_processed[father[current]] = 0;
    }
    // std::cout << "  final: " << reduction << std::endl;
  }

  cout << ans << std::endl;

  return 0;
}
