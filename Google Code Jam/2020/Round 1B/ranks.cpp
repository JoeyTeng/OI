// Join the Ranks
#include <bits/stdc++.h>

auto input() {
    int R = 0;
    int S = 0;

    std::cin >> R >> S;

    return std::make_tuple(R, S);
}

template <typename T>
void swap_deck(T& deck, int a, int b) {
    T tmp;
    for (int i = 0; i < b; ++i) {
        tmp.push_back(deck[a + i]);
    }
    for (int i = a - 1; i >= 0; --i) {
        deck[b + i] = deck[i];
    }
    for (int i = 0; i < b; ++i) {
        deck[i] = tmp[i];
    }
}

template <typename T>
void print_deck(const T& deck) {
    for (auto&& card : deck) {
        std::cerr << card << ' ';
    }
    std::cerr << std::endl;
}

template <typename T>
auto process(T& tuple) {
    auto R = std::get<0>(tuple);
    auto S = std::get<1>(tuple);
    std::vector<int> deck;
    std::vector<std::pair<int, int>> result;

    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < R; ++j) {
            deck.push_back(j);
        }
    }

    int right_index = deck.size() - 1;

    for (; right_index >= 0;) {
        // std::cerr << right_index << std::endl;
        // print_deck(deck);
        auto right = deck[right_index];
        bool flag = false;

        for (; right_index >= 0 && deck[right_index] == right; --right_index)
            ;
        right_index++;

        for (int i = right_index - 2; i >= 0; --i) {
            if (deck[i] == right) {
                swap_deck(deck, i + 1, right_index - i - 1);
                result.push_back(std::make_pair(i + 1, right_index - i - 1));
                flag = true;
                // std::cerr << "(" << i + 1 << ", " << right_index - i - 1
                //           << ")\n";
                break;
            }
        }
        for (; right_index >= 0 && deck[right_index] == right; --right_index)
            ;
        if (flag) {
            ++right_index;
        }
    }
    return result;
}

template <typename T>
auto output(const T& result) {
    std::stringstream ss;
    ss << result.size() << std::endl;
    for (auto&& pair : result) {
        ss << pair.first << ' ' << pair.second << std::endl;
    }

    return ss.str();
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto tuple = input();
        auto result = process(tuple);

        std::cout << "Case #" << i + 1 << ": " << output(result);
    }

    return 0;
}
