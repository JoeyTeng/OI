// visitfj

#define TASK std::string("visitfj")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

const int DIRECTION = 20;
const int INC[DIRECTION][2] = {{0, 3}, {1, 2}, {2, 1},
                               {3, 0}, {2, -1}, {1, -2},
                               {0, -3}, {-1, -2}, {-2, -1},
                               {-3, 0}, {-2, 1}, {-1, 2},
                               {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int N = 0;
int T = 0;
std::vector<int> grass;
std::vector<int64_t> dist;

int mov(int pos, int dir) {
    if (INC[dir][0] + pos % N < 0 || INC[dir][0] + pos % N >= N
     || INC[dir][1] + pos / N < 0 || INC[dir][1] + pos / N >= N) {
        return -1;
    }
    pos += INC[dir][0] + INC[dir][1] * N;
    if (pos >= 0 && pos < N * N) {
        return pos;
    } else {
        return -1;
    }
}

void spfa(int pos) {
    if (pos < 0 || pos >= N * N) {
        return;
    }
    std::queue<int> Q;
    Q.push(pos);

    // std::ostream_iterator<int64_t> int_cout(std::cout, " ");
    for (; !Q.empty();) {
        int pos = Q.front();
        Q.pop();

        for (int i = 0; i < DIRECTION; ++i) {
            int p = mov(pos, i);
            if (p < 0) {
                continue;
            } else {
                if (dist[p] > dist[pos] + 3 * T + grass[p]) {
                    dist[p] = dist[pos] + 3 * T + grass[p];
                    Q.push(p);
                }
            }
        }
        /*
        std::cout << pos << " " << dist.at(pos) << std::endl;
        for (int i = 0; i < N; ++i) {
            std::copy(dist.begin() + i * N, dist.begin() + (i + 1) * N, int_cout);
            std::cout << std::endl;
        }
        */
    }
}

int main() {
    fin >> N >> T;
    std::istream_iterator<int> int_fin(fin);
    std::istream_iterator<int> int_end;
    grass.assign(int_fin, int_end);
    dist.assign(grass.size(), INT64_MAX);
    dist.at(0) = 0;

    spfa(0);

    int64_t ans = INT64_MAX;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans = std::min(ans, dist.at(N * N - 1 - j - (i - j) * N) + i * T);
        }
    }

    fout << ans << std::endl;

    return 0;
}
