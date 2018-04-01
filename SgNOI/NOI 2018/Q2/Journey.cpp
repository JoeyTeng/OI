#include<bits/stdc++.h>

const int N_MAX = 10000 + 10;
const int M_MAX = 400 + 10;
const int H_MAX = 100 + 10;
const long long COUNT_MAX = 500000001;

std::vector<std::pair<int, int>> Graph[N_MAX];
long long count[M_MAX][N_MAX];
int n;
int m;
int h;

int main() {
	std::cin >> n >> m >> h;
	for (int i = 0; i < n - 1; ++i) {
		for (int H = 0; H < h; ++H) {
			int j = 0;
			int night = 0;
			std::cin >> j >> night;
			if (j <= i) {
				continue;
			}
			Graph[i].push_back(std::make_pair(j, night));
		}
	}

	count[0][0] = 1;
	for (int night = 0; night < m; ++night) {
		for (int i = 0; i < n - 1; ++i) {
			if (night > 0) {
				count[night][i] += count[night - 1][i];
				if (count[night][i] > COUNT_MAX) {
					count[night][i] = COUNT_MAX;
				}
			}
			int size = Graph[i].size();
			for (int j = 0; j < size; ++j) {
				count[night + Graph[i][j].second][Graph[i][j].first] += count[night][i];
				if (count[night + Graph[i][j].second][Graph[i][j].first] > COUNT_MAX) {
					count[night + Graph[i][j].second][Graph[i][j].first] = COUNT_MAX;
				}
			}
		}
		if (count[night][n - 1] >= COUNT_MAX) {
			for (; night < m; ++night) {
				std::cout << COUNT_MAX << ' ';
			}
			break;
		}
		std::cout << count[night][n - 1] << ' ';
	}

	return 0;
}
