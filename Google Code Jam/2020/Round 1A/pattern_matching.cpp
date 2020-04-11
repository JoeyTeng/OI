// Pattern Matching
#include <bits/stdc++.h>

auto input() {
    std::vector<std::string> starters;
    std::vector<std::string> connectors;
    std::vector<std::string> endings;

    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        int begin = -1;

        for (int j = 0; j < str.size(); ++j) {
            if (str[j] != '*') {
                continue;
            }

            if (j != 0 && begin == -1) {
                starters.push_back(str.substr(0, j));
                begin = j;

                // std::cerr << "starter: " << starters.back() << std::endl;
            }
            if (begin < j) {
                if (begin + 1 == j) {
                    begin++;

                    continue;
                }
                connectors.push_back(str.substr(begin + 1, j - begin - 1));

                // std::cerr << "connector: " << connectors.back() << std::endl;
                begin = j;
            }
        }

        if (begin < str.size() - 1) {
            endings.push_back(str.substr(begin + 1, str.size() - begin - 1));

            // std::cerr << "ending: " << endings.back() << std::endl;
        }
    }
    return std::make_tuple(starters, connectors, endings);
}

std::string commmon_starter(std::vector<std::string>& strings) {
    std::string str;

    for (auto& string : strings) {
        // std::cerr << " str: " << str << "; string: " << string
        //           << (str[0] == string[0]) << std::endl;

        if (str.size() < string.size()) {
            std::swap(str, string);
        }
        for (int i = 0; i < string.size(); ++i) {
            if (str[i] != string[i]) {
                return "*";
            }
        }
    }

    return str;
}

template <typename T>
auto process(T& tuple) {
    std::vector<std::string>& starters = std::get<0>(tuple);
    std::vector<std::string>& connectors = std::get<1>(tuple);
    std::vector<std::string>& endings = std::get<2>(tuple);

    // std::cerr << starters.size() << " " << connectors.size() << " "
    //           << endings.size() << std::endl;

    std::string ending;

    for (auto& end : endings) {
        if (end.size() > ending.size()) {
            ending = end.substr(0, end.size());
        }
        std::reverse(end.begin(), end.end());
    }

    // std::cerr << "ending: " << ending << std::endl;

    std::string res(commmon_starter(starters));
    std::string tmp_end(commmon_starter(endings));

    // std::cerr << res.size() << ' ' << res << ' ' << tmp_end << ' '
    //           << (res == "*" || tmp_end == "*") << std::endl;

    if (res == "*" || tmp_end == "*") {
        // std::cerr << "not found: " << res << std::endl;

        return std::string("*");
    }

    res.push_back('A');  // Test set 2

    for (auto&& str : connectors) {
        res.append(str);
    }
    res.append(ending);

    return res;
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto tuple = input();
        auto result = process(tuple);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
