// nocross

#define TASK std::string("nocross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

const int N_MAX = 1000 + 10;

int N = 0;
int ans = 0;
std::vector<int> breed;  // upp [0, N) low [N, 2N)
int dp[N_MAX][2][2] = {0};  // i, upp/low, open/close

int valid(int a, int b) {
    return (std::abs(a - b) <= 4);
}

int main() {
    fin >> N;
    std::istream_iterator<int> int_fin(fin);
    std::istream_iterator<int> int_end;
    breed.assign(int_fin, int_end);

    if (valid(breed.at(0), breed.at(N))) {
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        dp[0][1][1] = 1;
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0][0] = std::max(dp[i - 1][0][0], dp[i - 1][0][1]);
        dp[i][1][0] = std::max(dp[i - 1][1][0], dp[i - 1][1][1]);
        for (int j = 0; j < i; ++j) {
            if (valid(breed.at(i), breed.at(j + N))) {
                dp[i][0][1] = std::max(dp[i][0][1], dp[j][1][0] + 1);
            }
            if (valid(breed.at(i + N), breed.at(j))) {
                dp[i][1][1] = std::max(dp[i][1][1], dp[j][0][0] + 1);
            }
        }
        std::cout << dp[i][0][0] << ' ' << dp[i][0][1] << ' ' << dp[i][1][0] << ' ' << dp[i][1][1] << std::endl;
    }
    int ans = std::max(std::max(dp[N - 1][0][0], dp[N - 1][0][1]), std::max(dp[N - 1][1][0], dp[N - 1][1][1]));

    fout << ans << std::endl;

    return 0;
}
