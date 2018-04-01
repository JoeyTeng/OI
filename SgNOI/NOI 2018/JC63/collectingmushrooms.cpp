// 78: T1-5/6
#include<bits/stdc++.h>

const int RC_MAX = 500000 + 10;

int R;
int C;
int D;
int K;
char Map[RC_MAX];
std::queue<int> sp[RC_MAX];

int T1_5();
int T2_3_4();

int main() {
	std::cin >> R >> C >> D >> K;
	if ((D == std::max(R, C) && K == 1) || R == 1) {
		T1_5();
	} else {
		T2_3_4();
	}

	return 0;
}

int T1_5() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> Map[i * C + j];
			if (i <= D && Map[i * C + j] == 'S') {
				sp[j].push(i);
			}
		}
	}

	int k = 0;
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
		if (i + 1 == R) {
			break;
		}

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

int T2_3_4() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cin >> Map[i * C + j];
		}
	}
	int count = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (Map[i * C + j] == 'M') {
				int k = 0;
				// std::cout << "M " << i << ' ' << j << std::endl;
				// std::cout << std::max(i - D, 0) << ' ' << std::min (i + D, R) << ' ' << std::max(j - D, 0) << ' '  << std::min(j + D, C) << std::endl;
				for (int si = std::max(i - D, 0); si < std::min(i + D + 1, R); ++si) {
					for (int sj = std::max(j - D, 0); sj < std::min(j + D + 1, C); ++sj) {
						if (Map[si * C + sj] == 'S') {
							++k;
						}
						// std::cout << si << ' ' << sj << ' ' << Map[si * C + sj] << std::endl;
					}
				}
				if (k >= K) {
					++count;
				}
			}
		}
	}
	std::cout << count << std::endl;
	return 0;
}
