// nocross

#define TASK std::string("nocross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

const int N_MAX = 1000 + 10;

int N = 0;
int ans = 0;
std::vector<int> breed;  // upp [0, N) low [N, 2N)
std::vector<std::pair<int, int> > edges;
std::vector<int> dp;

int valid(int a, int b) {
    return (std::abs(a - b) <= 4);
}

int main() {
    fin >> N;
    std::istream_iterator<int> int_fin(fin);
    std::istream_iterator<int> int_end;
    breed.assign(int_fin, int_end);
    dp.assign(N, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            if (valid(breed.at(i), breed.at(N + j))) {
                edges.push_back(std::make_pair(i, j));
            }
        }
    }

    // std::ostream_iterator<int> int_cout(std::cout, " ");
    for (auto i : edges) {
        // std::cout << i.first << ' ' << i.second << std::endl;
        for (int j = i.second - 1; j >= 0; --j) {
            dp[i.second] = std::max(dp[i.second], dp[j] + 1);
        }
        // std::copy(dp.begin(), dp.end(), int_cout);
        // std::cout << std::endl;
    }
    int ans = 0;
    for (auto i : dp) {
        ans = std::max(ans, i);
    }

    fout << ans << std::endl;

    return 0;
}
