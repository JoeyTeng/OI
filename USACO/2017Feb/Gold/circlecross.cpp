// circlecross

#define TASK std::string("circlecross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int N = 0;
    std::vector<int> visited;
    std::list<int> stack;

    fin >> N;
    visited.assign(N + 1, 0);
    int count = 0;
    for (int i = 0; i < (N << 1); ++i) {
        int tmp;
        fin >> tmp;

        if (visited.at(tmp) == 0) {
            stack.push_back(tmp);
            ++visited.at(tmp);
        } else if (visited.at(tmp) == 1) {
            int c = 0;
            for (auto i = --stack.end(); i != --stack.begin(); --i, ++c) {
                if (*i == tmp) {
                    count += c;
                    stack.erase(i);
                    ++visited.at(tmp);
                    break;
                }
            }
        }
    }

    fout << count << std::endl;

    return 0;
}
