/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: waffle_choppers.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 14-Apr-2018
 */
#include <bits/stdc++.h>

int main() {
  int T = 0;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    if (false) {
IMPOSSIBLE:
      std::cout << "IMPOSSIBLE" << std::endl;
      continue;
    }

    int R = 0;
    int C = 0;
    int H = 0;
    int V = 0;
    std::cin >> R >> C >> H >> V;
    std::vector<std::vector<int>> waffle;
    for (int i = 0; i < R; ++i) {
      std::string tmp;
      std::vector<int> row;
      std::cin >> tmp;
      for (int j = 0; j < C; ++j) {
        if (tmp[j] == '@') {
          row.push_back(1);
        } else {
          row.push_back(0);
        }
      }
      waffle.push_back(row);
    }

    std::vector<std::vector<int>> prefix_sum;
    for (int i = 0; i < 1; ++i) {
      std::vector<int> row;
      row.push_back(waffle[0][0]);
      for (int j = 1; j < C; ++j) {
        row.push_back(row[j - 1] + waffle[0][j]);
      }
      prefix_sum.push_back(row);
    }
    for (int i = 1; i < R; ++i) {
      std::vector<int> row;
      row.push_back(waffle[i][0] + prefix_sum[i - 1][0]);
      for (int j = 1; j < C; ++j) {
        row.push_back(prefix_sum[i - 1][j] + row[j - 1] + waffle[i][j] - prefix_sum[i - 1][j - 1]);
      }
      prefix_sum.push_back(row);
    }

    // std::cout << std::endl;
    // for (int i = 0; i < R; ++i) {
    //   for (int j = 0; j < C; ++j) {
    //     std::cout << prefix_sum[i][j] << ' ';
    //   }
    //   std::cout << std::endl;
    // }

    std::cout << "Case #" << t << ": ";
    if (prefix_sum[R - 1][C - 1] % ((H + 1) * (V + 1))) {
      goto IMPOSSIBLE;
    }

    int row_unit = prefix_sum[R - 1][C - 1] / (H + 1);
    // std::cout << std::endl << row_unit << std::endl;
    std::vector<int> h_cut;
    for (int i = 0; i < R; ++i) {
      if (h_cut.size() == 0) {
        if (prefix_sum[i][C - 1] == row_unit) {
          h_cut.push_back(i);
        } else if (prefix_sum[i][C - 1] > row_unit) {
          goto IMPOSSIBLE;
        }
      } else {
        int prefix =
            prefix_sum[i][C - 1] - prefix_sum[h_cut[h_cut.size() - 1]][C - 1];
        if (prefix == row_unit) {
          h_cut.push_back(i);
        } else if (prefix > row_unit) {
          goto IMPOSSIBLE;
        }
      }
    }
    // for (auto &i: h_cut) {
    //   std::cout << i << ' ';
    // }

    int unit = row_unit / (V + 1);
    // std::cout << unit << std::endl;
    std::vector<int> v_cut;
    for (int i = 0; i < C; ++i) {
      if (v_cut.size() == 0) {
        if (prefix_sum[h_cut[0]][i] == unit) {
          v_cut.push_back(i);
        } else if (prefix_sum[h_cut[0]][i] > unit) {
          goto IMPOSSIBLE;
        }
      } else {
        int prefix = prefix_sum[h_cut[0]][i] -
                 prefix_sum[h_cut[0]][v_cut[v_cut.size() - 1]];
        if (prefix == unit) {
          v_cut.push_back(i);
        } else if (prefix > unit) {
          goto IMPOSSIBLE;
        }
      }
    }
    // for (auto &i: v_cut) {
    //   std::cout << i << ' ';
    // }
    // std::cout << std::endl;


    for (int i = 1; i < h_cut.size(); ++i) {
      int choco =
          prefix_sum[h_cut[i]][v_cut[0]] - prefix_sum[h_cut[i - 1]][v_cut[0]];
      if (choco != unit) {
        goto IMPOSSIBLE;
      }
      for (int j = 1; j < v_cut.size(); ++j) {
        int choco = prefix_sum[h_cut[i]][v_cut[j]] -
                    prefix_sum[h_cut[i - 1]][v_cut[j]] -
                    prefix_sum[h_cut[i]][v_cut[j - 1]] +
                    prefix_sum[h_cut[i - 1]][v_cut[j - 1]];
        if (choco != unit) {
          // std::cout << choco << ' ' << i << ' ' << j << std::endl;
          // std::cout << prefix_sum[h_cut[i]][v_cut[j]] << ' ' <<
          //           prefix_sum[h_cut[i - 1]][v_cut[j]] << ' ' <<
          //           prefix_sum[h_cut[i]][v_cut[j]] << ' ' <<
          //           prefix_sum[h_cut[i - 1]][v_cut[j - 1]] << ' ' << std::endl;
          goto IMPOSSIBLE;
        }
      }
    }
    std::cout << "POSSIBLE" << std::endl;
  }

  return 0;
}
