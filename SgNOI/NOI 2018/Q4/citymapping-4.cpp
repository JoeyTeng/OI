#include "citymapping.h"
#include<bits/stdc++.h>

const int N_MAX = 1000 + 10;
int _dist[N_MAX][N_MAX];
std::vector<std::pair<long long, std::pair<int, int>>> edges;

void dfs(int root, std::vector<int>& points) {
	for (int i = 1; i < points.size(); ++i) {
		if (_dist[points[0]][points[i]] != 0) {
		} else {
			_dist[points[0]][points[i]] = get_distance(points[0], points[i]);
			_dist[points[i]][points[0]] = _dist[points[0]][points[i]];
		}
	}
	std::vector<int> left;
	std::vector<int> right;
	int min_l_dist = INT_MAX;
	int min_l_root = INT_MAX;
	int min_r_dist = INT_MAX;
	int min_r_root = INT_MAX;
	for (int i = 0; i < points.size(); ++i) {
		if (_dist[root][points[i]] > _dist[points[0]][points[i]]) {
			left.push_back(points[i]);
			if (min_l_root > N_MAX || _dist[root][points[i]] < min_l_dist) {
				min_l_dist = _dist[root][points[i]];
				min_l_root = points[i];
			}
		} else {
			right.push_back(points[i]);
			if (min_r_root > N_MAX || _dist[root][points[i]] < min_r_dist) {
				min_r_dist = _dist[root][points[i]];
				min_r_root = points[i];
			}
		}
	}
	edges.push_back(std::make_pair(min_l_dist, std::make_pair(root, min_l_root)));
	edges.push_back(std::make_pair(min_r_dist, std::make_pair(root, min_r_root)));
	dfs(min_l_root, left);
	dfs(min_r_root, right);
}

void find_roads(int N, int Q, int A[], int B[], int W[]) {
	std::vector<int> points;
	for (int i = 1; i < N; ++i) {
		_dist[1][i] = get_distance(1, i);
		points.push_back(i);
	}
	dfs(0, points);
	for (int i = 0; i < edges.size(); ++i) {
		A[i] = edges[i].second.first;
		B[i] = edges[i].second.second;
		W[i] = edges[i].first;
	}

	return;
}
