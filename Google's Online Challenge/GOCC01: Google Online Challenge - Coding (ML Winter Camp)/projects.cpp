#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int C = 0;
  std::cin >> C;
  for (int t = 1; t <= C; ++t) {
    int K = 0;
    int J = 0;
    int dependencies[27][27] = {0};
    int delay[27] = {0};

    std::cin >> K >> J;
    for (int i = 0; i < K; ++i) {
      std::string X;
      std::string Y;
      std::cin >> X >> Y;
      dependencies[X[0] - 'A'][Y[0] - 'A'] = 1;
    }
    for (int i = 0; i < J; ++i) {
      std::string D;
      std::cin >> D;
      delay[D[0] - 'A'] = 1;
    }

    while (true) {
      bool change = false;
      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
          if (!delay[i] && delay[j] && dependencies[i][j]) {
            delay[i] = 1;
            change = true;
          }
        }
      }
      if (!change) {
        break;
      }
    }

    std::string answer;
    for (int i = 0; i < 26; ++i) {
      if (delay[i]) {
        answer.push_back(i + 'A');
        answer.push_back(' ');
      }
    }
    answer.pop_back();
    std::cout << "Case #" << t << ": " << answer << std::endl;
  }

  return 0;
}
