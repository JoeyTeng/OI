/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: number_guessing.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 01-Apr-2018
 */
#include <bits/stdc++.h>

const std::string CORRECT("CORRECT");
const std::string TOO_SMALL("TOO_SMALL");
const std::string TOO_BIG("TOO_BIG");

int main() {
  int T = 0;
  std::cin >> T;
  while (T) {
    --T;

    int64_t a = 0;
    int64_t b = 0;
    int64_t n = 0;
    std::cin >> a >> b >> n;
    a += 1;
    int64_t guess = (a + b) >> 1;
    std::cout << guess << std::endl;
    --n;
    std::string response;
    std::cin >> response;
    while (response != CORRECT && n) {
      --n;

      if (response == TOO_SMALL) {
        a = guess + 1;
      } else if (response == TOO_BIG) {
        b = guess - 1;
      } else {
        break;
      }
      guess = (a + b) >> 1;
      std::cout << guess << std::endl;
      std::cin >> response;
    }
  }

  return 0;
}
