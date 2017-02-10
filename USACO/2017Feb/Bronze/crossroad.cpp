// crossroad

#define TASK std::string("crossroad")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int N = 0;
    fin >> N;

    std::vector<int> label(N + 1, -1);

    int counting = 0;
    for (int i = 0; i < N; ++i) {
        int number = 0;
        int side = 0;

        fin >> number >> side;

        if (label.at(number) == -1) {
            label.at(number) = side;
        } else if (label.at(number) != side) {
            ++counting;
            label.at(number) = side;
        }
    }

    fout << counting << std::endl;

    return 0;
}
