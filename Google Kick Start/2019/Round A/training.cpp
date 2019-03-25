/*
 * @Author: Joey Teng
 * @Email:  joey.teng.dev@gmail.com
 * @Filename: Training.cpp
 * @Last modified by:   Joey Teng
 * @Last modified time: 25-Mar-2019
 */
/*
* Problem
* As the football coach at your local school, you have been tasked with picking
a team of exactly P students to represent your school. There are N students for
you to pick from. The i-th student has a skill rating Si, which is a positive
integer indicating how skilled they are.
* You have decided that a team is fair if it has exactly P students on it and
they all have the same skill rating. That way, everyone plays as a team.
Initially, it might not be possible to pick a fair team, so you will give some
of the students one-on-one coaching. It takes one hour of coaching to increase
the skill rating of any student by 1.
* The competition season is starting very soon (in fact, the first match has
already started!), so you'd like to find the minimum number of hours of coaching
you need to give before you are able to pick a fair team.
* Input
* The first line of the input gives the number of test cases, T. T test cases
follow. Each test case starts with a line containing the two integers N and P,
the number of students and the number of students you need to pick,
respectively. Then, another line follows containing N integers Si; the i-th of
these is the skill of the i-th student.
* Output
* For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1) and y is the minimum number of hours of coaching
needed, before you can pick a fair team of P students.
* Limits
Time limit: 15 seconds per test set.
Memory limit: 1 GB.
1 ≤ T ≤ 100.
1 ≤ Si ≤ 10000, for all i.
2 ≤ P ≤ N.
* Test set 1 (Visible)
2 ≤ N ≤ 1000.
* Test set 2 (Hidden)
2 ≤ N ≤ 105.
* Sample

Input

3
4 3
3 1 9 100
6 2
5 5 1 2 3 4
5 5
7 7 1 7 7

Output

Case #1: 14
Case #2: 0
Case #3: 6


* In Sample Case #1, you can spend a total of 6 hours training the first student
and 8 hours training the second one. This gives the first, second and third
students a skill level of 9. This is the minimum time you can spend, so the
answer is 14.
* In Sample Case #2, you can already pick a fair team (the first and
second student) without having to do any coaching, so the answer is 0.
* In Sample Case #3, P = N, so every student will be on your team. You have to
spend 6 hours training the third student, so that they have a skill of 7, like
everyone else. This is the minimum time you can spend, so the answer is 6.
*/
#include <bits/stdc++.h>

int main() {
  int T = 0;

  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    int p = 0;
    std::vector<int> S;

    std::cin >> n >> p;
    for (int i = 0; i < n; ++i) {
      int tmp;
      std::cin >> tmp;
      S.push_back(tmp);
    }
    std::sort(S.begin(), S.end());

    // int l = 0;
    int r = 0;
    int64_t last_dec = 0;
    int64_t ans = 0;
    int64_t total = 0;

    for (int i = 1; i < p; ++i) {
      total += i * (S[i] - S[i - 1]);
    }
    ans = total;
    // for (auto i : S) {
    //   std::cout << i << ' ';
    // }
    // std::cout << std::endl;
    for (int i = p; i < n; ++i) {

      int inc = (p - 1) * (S[i] - S[i - 1]);
      int dec = (S[i - 1] - S[i - p]); // + last_dec;
      total += inc - dec;

      //   std::cout << "inc : " << inc << " dec: " << dec << " last: " <<
      //   last_dec
      //             << "\ncurrent: " << total << " ans: " << ans << "\nSi: " <<
      //             S[i]
      //             << " Si-1: " << S[i - 1] << "\nSi-p-r+1: " << S[i - p - r +
      //             1]
      //             << " Si-p-r: " << S[i - p - r] << "\np:" << p << " r: " <<
      //             r
      //             << "\n " << i - p + 1 << " " << i - p << std::endl
      //             << std::endl;

      //   if (S[i - p + 1] == S[i - p]) {
      //     std::cout << " Y " << std::endl;
      //     last_dec = dec;
      //   } else {
      //     last_dec = 0;
      //   }
      //   if (S[i] == S[i - 1]) {
      //     ++r;
      //   } else {
      //     r = 0;
      //   }
      ans = std::min(ans, total);
    }

    std::cout << "Case #" << t + 1 << ": " << ans << std::endl;
  }

  return 0;
}
