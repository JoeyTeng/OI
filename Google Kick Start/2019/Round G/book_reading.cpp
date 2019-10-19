/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: book_reading.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 19-Oct-2019
 */

#include <bits/stdc++.h>

const int N_MAX = 100000 + 10;

int main() {
  int T;
  std ::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N = 0;
    int M = 0;
    int Q = 0;
    int book[N_MAX] = {0};
    int count = 0;

    std::cin >> N >> M >> Q;
    for (int i = 0; i < M; ++i) {
      int tmp;
      std::cin >> tmp;

      for (int divisor = 1; divisor <= sqrt(tmp); ++divisor) {
        if (tmp % divisor == 0) {
          book[divisor]++;
          book[tmp / divisor]++;
        }
      }
      if (int(sqrt(tmp)) * int(sqrt(tmp)) == tmp) {
        book[int(sqrt(tmp))]--;
      }
    }

    for (int i = 0; i < Q; ++i) {
      int tmp;
      std::cin >> tmp;

      count += N / tmp;
      count -= book[tmp];
      // std::cout << " Q: " << tmp << " : " << (N / tmp) << ' ' << (book[tmp])
      //           << std::endl;
    }
    // std::cout << std::endl << std::endl;
    // for (int i = 1; i <= N; ++i) {
    //   std::cout << book[i] << ' ';
    // }
    // std::cout << std::endl;
    std::cout << "Case #" << t << ": " << count << std::endl;
  }

  return 0;
}
