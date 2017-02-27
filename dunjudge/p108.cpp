// 4sum

#include<bits/stdc++.h>

const int N_MAX = 10000 + 10;

inline int index(int x) {
    return x + (N_MAX << 1);
}

int main() {
    std::vector<int> len;
    std::vector<int> num[4];
    std::vector<int> hash(N_MAX << 2, INT_MAX);

    for (int i = 0; i < 4; ++i) {
        int tmp;
        std::cin >> tmp;
        len.push_back(tmp);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < len[i]; ++j) {
            int tmp;
            std::cin >> tmp;
            num[i].push_back(tmp);
        }
    }

    for (auto a : num[0]) {
        for (auto b : num[1]) {
            hash[index(a + b)] = a;
        }
    }
    for (auto c : num[2]) {
        for (auto d : num[3]) {
            if (hash[index(-(c + d))] != INT_MAX) {
                try {
                    std::cout << hash[index(-(c + d))] << ' ' << -(c + d) - hash[index(-(c + d))] << ' ' << c << ' ' << d << std::endl;
                } catch (...) {
                    std::exit(-1);
                }
            
                return 0;
            }
        }
    }

    return 0;
}
