#include<bits/stdc++.h>

const int RC_MAX = 500000 + 10;

int R;
int C;
int D;
int K;
std::vector<int> sprinkler[RC_MAX];
char Map[RC_MAX];
std::queue<int> sp[RC_MAX];

int main() {
	std::cin >> R >> C >> D >> K;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> Map[i * C + j];
			if (Map[i * C + j] == 'S') {
				sprinkler[j].push_back(i);
			}
		}
	}

	int k = 0;
	for (int i = 0; i < C; ++i) {
		auto it = sprinkler[i].begin();
		while (it != sprinkler[i].end() && *it <= D) {
			sp[i].push(*it);
			++it;
		}
		// std::cout << sp[i].size() << ' ';
	}
	// std::cout << std::endl;
	// for (int i = 0; i < C; ++i) {
		// std::cout << sprinkler[i].size() << ' ';
	// }
	// std::cout << std::endl;

	int count = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j <= D; ++j) {
			k += sp[j].size();
		}
		// std::cout << " Row " << i << " k " << std::endl;
		for (int j = 0; j < C; ++j) {
			// std::cout << k << ' ';
			if (k >= K && Map[i * C + j] == 'M') {
				count += 1;
			}
			if (j >= D) {
				k -= sp[j - D].size();
			}
			if (j <= C - D) {
				k += sp[j + D + 1].size();
			}
		}
		// std::cout << std::endl;
		// std::cout << " Row " << i + 1 << std::endl;
		for (int j = 0; j < C; ++j) {
			if (!sp[j].empty() && sp[j].front() < i - D + 1) {
				sp[j].pop();
			}
			if (Map[(i + D + 1) * C + j] == 'S') {
				sp[j].push(i + D + 1);
			}
			// std::cout << sp[j].size() << ' ';
		}
		// std::cout << std::endl;
	}
	std::cout << count << std::endl;

	return 0;
}
