// circlecross

#define TASK std::string("circlecross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    std::string record;
    std::vector<int> label(26, 0);
    std::vector<int> processed(26, 0);

    fin >> record;

    int counting = 0;
    for (int i = 0; i < record.size(); ++i) {
        char current = record.at(i);
        if (processed.at(current - 'A') == 1) {
            continue;
        }

        label.assign(26, 0);

        for (int j = i + 1; j < record.size() && record.at(j) != current; ++j) {
            if (processed.at(record.at(j) - 'A') == 1) {
                continue;
            }
            ++label.at(record.at(j) - 'A');
            if (label.at(record.at(j) - 'A') == 1) {
                ++counting;
            } else if (label.at(record.at(j) - 'A') == 2) {
                --counting;
            }
        }
        processed.at(current - 'A') = 1;
    }

    fout << counting << std::endl;

    return 0;
}
