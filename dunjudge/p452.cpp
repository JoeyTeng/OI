// haybales

#include<bits/stdc++.h>

int main() {
    int N = 0;
    std::vector<int> piles;

    std::cin >> N;

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;

    piles.assign(int_cin, int_end);

    int sum = std::accumulate(piles.begin(), piles.end(), 0);
    int average = sum / piles.size();

    int moving = 0;

    for (auto i : piles) {
        if (i < average) {
            moving += average - i;
        }
    }

    std::cout << moving << std::endl;

    return 0;
}
