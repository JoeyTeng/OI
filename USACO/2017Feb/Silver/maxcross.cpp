// maxcross

#define TASK std::string("maxcross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int N = 0;
    int K = 0;
    int B = 0;
    std::vector<int> broken;
    std::vector<int> road;
    fin >> N >> K >> B;
    std::istream_iterator<int> int_fin(fin);
    std::istream_iterator<int> int_end;

    broken.assign(int_fin, int_end);
    road.assign(N + 1, 0);
    for (auto i : broken) {
        road.at(i) = 1;
    }
    int counting = 0;
    int min = INT_MAX;
    for (int i = 0; i <= N; ++i) {
        counting += road.at(i);
        if (i >= K) {
            counting -= road.at(i - K);
            min = std::min(min, counting);
        }
    }

    fout << min << std::endl;

    return 0;
}
