/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: tmp.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 19-May-2019
 */
#include <bits/stdc++.h>
#include <numeric>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() { std::cout << gcd(-4, -2) << std::endl; }

/*
x + y < x + 2y
0 < y
0 < 1

x + 2y < 2x + y
-x < -y
x / y > 1

//
x + 2y < 2x + y
-x < -y
x / y > 1

-2x < y
x/y > -1/2

2x < 2y
x/y < 1

//

x + 2y < x + 3y
0 < y
0 < 1

x + 3y < 2x + 3y
-x < 0

//
2x < y
x = 1, y = 3

3x < 2y
x = 2, y = 4
*/
