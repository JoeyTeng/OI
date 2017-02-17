// boring

#include<bits/stdc++.h>

const int N_ALPHABETS = 26;

int main() {
    std::vector<int> like;
    std::string peanut;
    std::vector<std::map<int, int64_t> > freq(26);

    for (int i = 0; i < N_ALPHABETS; ++i) {
        int tmp;
        std::cin >> tmp;
        
        like.push_back(tmp);
    }
    std::cin >> peanut;

    int64_t ans = 0;
    int64_t prefix_sum = 0;

    for (auto i : peanut) {

        i = std::tolower(i);
        int index = i - 'a';

        ++freq.at(index)[prefix_sum];
        prefix_sum += like.at(index);

        auto pt = freq.at(index).find(prefix_sum);
        if (pt != freq.at(index).end()) {
            ans += pt -> second;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
