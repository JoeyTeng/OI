// gitfts_usaco

#include<bits/stdc++.h>

struct Data {
    int P;
    int S;
};

int main() {
    int N = 0;
    int B = 0;
    std::vector<Data> cow;
    std::vector<int> cost;

    std::cin >> N >> B;

    for (int i = 0; i < N; ++i) {
        Data tmp;

        std::cin >> tmp.P >> tmp.S;
        cow.push_back(tmp);
    }

    for (auto i : cow) {
        cost.push_back(i.P + i.S);
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
        std::vector<int> tmp_cost(cost);
        tmp_cost.at(i) = (cow.at(i).P >> 1) + cow.at(i).S;

        std::sort(tmp_cost.begin(), tmp_cost.end());
        int total = 0;
        int tmpB = B;
        for (auto it = tmp_cost.begin(); it != tmp_cost.end() && *it <= tmpB; ++total, ++it) {
            tmpB -= *it;
        }
        result = std::max(result, total);
    }

    std::cout << result << std::endl;

    return 0;
}
