#include<iostream>
#include<string>
#include<vector>

const int INC[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int start[2] = {0};
int N = 0;
int M = 0;

int trial(const std::vector<std::string> &graph, const std::string &path, const std::vector<int>& mapping) {
    int pos[2] = {start[0], start[1]};

    for (auto& i:path) {
        pos[0] += INC[mapping[i - '0']][0];
        pos[1] += INC[mapping[i - '0']][1];

        if (pos [0] < 0 || pos[1] < 0 || pos[0] >= N || pos[1] >= M || graph[pos[0]][pos[1]] == '#') {
            return 0;
        } else if (graph[pos[0]][pos[1]] == 'E') {
            return 1;
        }
    }
    return 0;
}

int enumerate(const std::vector<std::string> &graph, const std::string &path) {
    int count = 0;
    std::vector<int> mapping(4);

    for (mapping[0] = 0; mapping[0] < 4; ++mapping[0]) {
        for (mapping[1] = 0; mapping[1] < 4; ++mapping[1]) {
            if (mapping[0] == mapping[1]) continue;
            for (mapping[2] = 0; mapping[2] < 4; ++mapping[2]) {
                if (mapping[0] == mapping[2] || mapping[1] == mapping[2]) continue;
                for (mapping[3] = 0; mapping[3] < 4; ++mapping[3]) {
                    if (mapping[0] == mapping[3] || mapping[1] == mapping[3] || mapping[2] == mapping[3]) continue;
                    if (trial(graph, path, mapping)) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    std::vector<std::string> graph;

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        std::string tmp;
        std::cin >> tmp;
        graph.push_back(tmp);
        for (int j = 0; j < M; ++j) {
            if (graph[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            }
        }
    }
    std::string path;
    std::cin >> path;

    int ans = enumerate(graph, path);

    std::cout << ans << std::endl;

    return 0;
}