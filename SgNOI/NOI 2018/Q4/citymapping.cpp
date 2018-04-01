#include "citymapping.h"
#include<bits/stdc++.h>

const int N_MAX = 1000 + 10;
int dist[3][N_MAX] = {0};
std::vector<std::pair<int, int>> graph[3];

void find_roads(int N, int Q, int A[], int B[], int W[]) {
	int edges = 0;
	for (int n = 1; n < 3; ++n) {
		for (int i = 1; i <= N; ++i) {
			dist[n][i] = get_distance(n, i);
		}
		// std::cout << std::endl;
	}
	for (int i = 3; i <= N; ++i) {
		if (dist[2][i] == dist[1][i] + dist[1][2]) { // Left
			graph[1].push_back(std::make_pair(dist[1][i], i));
		} else if (dist[1][i] == dist[2][i] + dist[1][2]) { // Right
			graph[2].push_back(std::make_pair(dist[2][i], i));
		} else if (dist[1][i] + dist[2][i] == dist[1][2]) { // Middle
			graph[0].push_back(std::make_pair(dist[1][i], i));
		} else {
			// std::cout << "WTF" << std::endl;
		}
	}
	graph[0].push_back(std::make_pair(dist[1][2], 2));
	graph[0].push_back(std::make_pair(0, 1));
	graph[1].push_back(std::make_pair(0, 1));
	graph[2].push_back(std::make_pair(0, 2));
	for (int i = 0; i < 3; ++i) {
		std::sort(graph[i].begin(), graph[i].end());
		// for (auto j : graph[i]) {
			// std::cout << j.first << ' ' << j.second << std::endl;
		// }
		// std::cout << std::endl;
	}

	for (int n = 0; n < 3; ++n) {
		// std::cout << std::endl << ' ' << n << ": ";
		for (int i = 0; i < graph[n].size() - 1; ++i) {
			A[edges] = graph[n][i].second;
			B[edges] = graph[n][i + 1].second;
			W[edges] = graph[n][i + 1].first - graph[n][i].first;
			++edges;
			// std::cout << graph[n][i].second << ' ' << graph[n][i].first << ' ';
		}
		// std::cout << graph[n].back().second << ' '<< graph[n].back().first << std::endl;
	}
	// std::cout << edges << std::endl;

	return;
}
