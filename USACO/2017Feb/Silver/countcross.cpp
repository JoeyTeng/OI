// countcross

#define TASK std::string("countcross")
#include<bits/stdc++.h>

const int inc[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int COW = 1 << 5;
const int NO_L = 1;
const int NO_U = 2;
const int NO_R = 4;
const int NO_D = 8;
const int VISITED = 16;
const int N_MAX = 100 + 10;

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int total = 0;
int N = 0;
//32 Cow, 1, No left, 2 No up, 4 No right, 8 No down, 16 visited
std::vector<std::vector<int> > map;
int visited_map[N_MAX][N_MAX] = {0};
std::vector<int> color;
std::vector<int> visited;
std::vector<std::pair<int, int> > cow;

void dfs(int x, int y) {
    if (visited_map[x][y]) {
        return;
    }
    visited_map[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        if (!(map[x][y] & (1 << i))) {
            if (x + inc[i][0] > 0 && y + inc[i][1] > 0
             && x + inc[i][0] <= N && y + inc[i][1] <= N
             && !visited_map[x + inc[i][0]][y + inc[i][1]]) {
                if (map[x + inc[i][0]][y + inc[i][1]] & COW) {
                    visited[map[x + inc[i][0]][y + inc[i][1]] >> 6] = 1;
                    ++color.back();
                    ++total;
                }
                dfs(x + inc[i][0], y + inc[i][1]);
            }
        }
    }
}

int main() {
    int K = 0;
    int R = 0;

    fin >> N >> K >> R;

    color.assign(N + 1, 0);
    map.assign(N + 1, color);
    visited.assign(K, 0);
    color.clear();

    for (int i = 0; i < R; ++i) {
        int x1 = 0;
        int x2 = 0;
        int y1 = 0;
        int y2 = 0;
        fin >> x1 >> y1 >> x2 >> y2;

        if (x1 - x2 == 1) {
            map[x1][y1] |= 1 << 0;
            map[x2][y2] |= 1 << 2;
        } else if (y1 - y2 == 1) {
            map[x1][y1] |= 1 << 1;
            map[x2][y2] |= 1 << 3;
        } else if (x1 - x2 == -1) {
            map[x1][y1] |= 1 << 2;
            map[x2][y2] |= 1 << 0;
        } else if (y1 - y2 == -1) {
            map[x1][y1] |= 1 << 3;
            map[x2][y2] |= 1 << 1;
        }
    }
    for (int i = 0; i < K; ++i) {
        int x = 0;
        int y = 0;
        fin >> x >> y;

        map[x][y] |= 1 << 5;
        map[x][y] |= i << 6;
        cow.push_back(std::make_pair(x, y));
    }
    while (total < K) {
        for (int i = 0; i < K; ++i) {
            if (visited.at(i) == 0) {
                color.push_back(1);
                visited.at(i) = 1;
                ++total;
                dfs(cow.at(i).first, cow.at(i).second);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < color.size(); ++i) {
        for (int j = i + 1; j < color.size(); ++j) {
            ans += color[i] * color[j];
        }
    }
    fout << ans << std::endl;

    return 0;
}
