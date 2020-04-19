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
bool check(const T& deck, int R, int S) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            if (deck[i * S + j] != i) {
                return false;
            }
        }
    }
    return true;
}

template <typename T, typename P>
bool dfs(T& deck, P& result, int R, int S, int depth, int max_depth) {
    if (depth == max_depth) {
        return false;
    }
    if (check(deck, R, S)) {
        return true;
    }

    for (int i = 1; i < R * S - depth; ++i) {
        for (int j = 1; j + i < R * S - depth; ++j) {
            result.push_back(std::make_pair(i, j));
            swap_deck(deck, i, j);
            if (dfs(deck, result, R, S, depth + 1, max_depth)) {
                return true;
            }
            swap_deck(deck, j, i);
            result.pop_back();
        }
    }
    return false;
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

    for (int i = 1; i < std::max(R, S) + 2; ++i) {
        if (dfs(deck, result, R, S, 0, i)) {
            return result;
        }
    }
    exit(-1);
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
