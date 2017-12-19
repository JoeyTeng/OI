// barn painting; Accepted

// DP on tree

#include <bits/stdc++.h>
#define INFILE "barnpainting.in"
#define OUTFILE "barnpainting.out"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

const std::int64_t MOD = 1000000007;
const int N_MAX        = 100000 + 1;
const int C_MAX        = 3;

int main() {
    int N = 0;
    int K = 0;

    cin >> N >> K;
    std::vector<std::vector<int> > barn(N + 1);
    std::vector<int> count(N + 1);
    std::int64_t     f[N_MAX][C_MAX] = { 0 };

    for (int i = 1; i < N; ++i) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        barn[x].push_back(y);
        barn[y].push_back(x);
        count[x] += 1;
        count[y] += 1;
    }

    std::queue<int> queue;

    for (int i = 1; i < N + 1; ++i) {
        if (count[i] == 1) {
            queue.push(i);
        }

        for (int c = 0; c < C_MAX; ++c) {
            f[i][c] = 1;
        }
    }

    for (int i = 0; i < K; ++i) {
        int b = 0;
        int c = 0;
        cin >> b >> c;

        for (int j = 0; j < C_MAX; ++j) {
            if ((c - 1) == j) {
                f[b][j] = 1;
            } else {
                f[b][j] = 0;
            }
        }
    }

    int last = -1;

    while (!queue.empty()) {
        int i = queue.front();
        queue.pop();

        for (const auto& j : barn[i]) {
            f[j][0]  *= f[i][1] + f[i][2];
            f[j][1]  *= f[i][0] + f[i][2];
            f[j][2]  *= f[i][0] + f[i][1];
            for (int c = 0; c < C_MAX; ++c) {
                f[j][c] %= MOD;
            }
            count[j] -= 1;

            if (count[j] == 1) {
                queue.push(j);
            }
        }
        last = i;
    }

    cout << (f[last][0] + f[last][1] + f[last][2]) % MOD << std::endl;
}
