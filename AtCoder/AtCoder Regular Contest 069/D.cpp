// Menagerie

#include<bits/stdc++.h>

// Sheep == 0, Wolf == 1, o == 0, x == 1

int deduce(int f_2, int f_1, int s_1) {
    if ((!s_1 && !f_1) || (s_1 && f_1)) {
        return f_2;
    } else if ((!s_1 && f_1) || (s_1 && !f_1)) {
        return !f_2;
    }
}

void dfs(std::string& s, std::vector<int>& species, int index) {
    for (int i = index; i < species.size(); ++i) {
        species.at(i) = deduce(species.at(i - 2), species.at(i - 1), (s.at(i - 1) == 'o') ? 0 : 1);
    }
}

void output(std::vector<int>& species) {
    species.pop_back();
    species.pop_back();
    for (auto i : species) {
        if (i) {
            std::cout << 'W';
        } else {
            std::cout << 'S';
        }
    }
    std::cout << std::endl;
}

int check(std::vector<int>& species, int N) {
    if (species.at(0) == species.at(N) && species.at(1) == species.at(N + 1)) {
        output(species);
        return 1;
    }
    return 0;
}

int main() {
    int N = 0;
    std::string s;

    std::cin >> N >> s;
    s.push_back(s.front());
    std::vector<int> species(N + 2, 0);

    dfs(s, species, 2);
    if (check(species, N)) {
        return 0;
    }
    species.at(1) = 1;
    dfs(s, species, 2);
    if (check(species, N)) {
        return 0;
    }
    species.at(0) = 1;
    dfs(s, species, 2);
    if (check(species, N)) {
        return 0;
    }
    species.at(1) = 0;
    dfs(s, species, 2);
    if (check(species, N)) {
        return 0;
    }
    std::cout << -1 << std::endl;

    return 0;
}
