// B. Tidy Numbers

#include<bits/stdc++.h>

int check(std::string N, int count) {
    for (int i = 0; i < count; ++i) {
        if (N.at(i) > N.at(i + 1)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::string N;
        std::cin >> N;

        int count = N.size();
        for (int i = N.size() - 1; i >= 0; --i) {
            if (!check(N, i)) {
                count = i;
                --N.at(i - 1);
            }
        }

        int pos = count - 1;
        while (N.at(pos) < '0') {
            N.at(pos) = '9';
            --N.at(pos - 1);
            --pos;
        }

        std::cout << "Case #" << t + 1 << ": ";
        for (int i = (N.at(0) == '0') ? 1 : 0; i < N.size(); ++i) {
            if (i < count) {
                std::cout << N.at(i);
            } else {
                std::cout << '9';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
