// nocross

#define TASK std::string("nocross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int N = 0;
int ans = 0;
std::vector<int> breed;  // upp [0, N) low [N, 2N)

int valid(int a, int b) {
    return (std::abs(a - b) <= 4);
}

void dfs(int upp, int low, int depth) {
    // std::cout << upp << ' ' << low << ' ' << depth << std::endl;
    ans = std::max(ans, depth);
    if (upp >= N - 1 || low >= N - 1) {
        return;
    }

    if (depth % 2 == 0) {
        ++upp;
        for (int i = low + 1; i < N; ++i) {
            if (valid(breed.at(upp), breed.at(i + N))) {
                dfs(upp, i, depth + 1);  // cross
            }
        }
    } else {
        ++low;
        for (int i = upp + 1; i < N; ++i) {
            if (valid(breed.at(low + N), breed.at(i))) {
                dfs(i, low, depth + 1);
            }
        }
    }

    dfs(upp, low, depth);
}

int main() {
    fin >> N;
    std::istream_iterator<int> int_fin(fin);
    std::istream_iterator<int> int_end;
    breed.assign(int_fin, int_end);

    dfs(-1, -1, 0);
    fout << ans << std::endl;

    return 0;
}
