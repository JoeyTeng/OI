// ballot
// Binary serach

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
    std::vector<Ballot> ballot;

    std::cin >> N >> C;

    ballot.push_back(Ballot(INT_MIN));
    ballot.push_back(Ballot(INT_MAX));
    for (int i = 0; i < N; ++i) {
        int tmp;

        std::cin >> tmp;
        ballot.push_back(Ballot(i + 1, tmp));
    }
    std::sort(ballot.begin(), ballot.end());

    for (int i = 0; i < C; ++i) {
        int query;

        std::cin >> query;
        // lower_bound: first element that _not less_ than the value
        int pos = std::distance(ballot.begin(),
                  std::lower_bound(ballot.begin(), ballot.end(), query));

        if (std::abs(query - ballot.at(pos - 1).digit)
         <= std::abs(ballot.at(pos).digit - query)) {
            std::cout << ballot.at(pos - 1).number << std::endl;
            ballot.erase(ballot.begin() + pos - 1);
        } else {
            std::cout << ballot.at(pos).number << std::endl;
            ballot.erase(ballot.begin() + pos);
        }
    }
}
