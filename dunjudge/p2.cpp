// ballot
// Binary Serach Tree

#include<bits/stdc++.h>

struct Ballot {
    explicit Ballot(int digit) {
        this -> number = -1;
        this -> digit = digit;
    }

    Ballot(int number, int digit) {
        this -> number = number;
        this -> digit = digit;
    }

    operator int() const {
        return digit;
    }

    int number;  // serial number
    int digit;  // ballot number
};

int main() {
    int N = 0;
    int C = 0;
    std::set<Ballot> ballot = {Ballot(INT_MIN), Ballot(INT_MAX)};  // boundary values

    std::cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        int tmp;

        std::cin >> tmp;
        ballot.insert(Ballot(i + 1, tmp));
    }

    for (int i = 0; i < C; ++i) {
        int query;

        std::cin >> query;

        auto upper_pos = ballot.lower_bound(Ballot(query));
        auto lower_pos = --upper_pos;
        ++upper_pos;

        if (std::abs(query - *lower_pos) <= std::abs(*upper_pos - query)) {
            std::cout << lower_pos -> number << std::endl;
            ballot.erase(lower_pos);
        } else {
            std::cout << upper_pos -> number << std::endl;
            ballot.erase(upper_pos);
        }
    }
}
