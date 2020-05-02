// Overrandomized
#include <bits/stdc++.h>

const int64_t QUERIES = 10000;

auto input() {
    int64_t U = 0;
    std::vector<std::pair<int64_t, std::string>> query;

    std::cin >> U;
    for (int i = 0; i < QUERIES; ++i) {
        int64_t q;
        std::string r;
        std::cin >> q >> r;

        query.push_back(std::make_pair(q, r));
    }
    return std::make_tuple(U, query);
}

template <typename T>
auto processA(const T& inputs) {
    auto U = std::get<0>(inputs);
    auto records = std::get<1>(inputs);
    std::map<int, char> d2c;
    std::map<char, int> c2d;
    std::set<char> chars;

    std::sort(records.begin(), records.end());

    std::queue<std::pair<int64_t, std::string>> qr;
    for (auto&& record : records) {
        qr.push(record);
    }
    // auto a = qr.front();
    // std::cerr << a.first << ' ' << a.second << std::endl;

    // int64_t LOOP_COUNT = 0;

    while (!qr.empty()) {
        // LOOP_COUNT++;
        // if (LOOP_COUNT % 100 == 0) {
        //     std::cerr << LOOP_COUNT
        //               << "-th iteration: queue size: " << qr.size()
        //               << std::endl;
        // }
        auto pair = qr.front();
        qr.pop();
        auto query = pair.first;
        auto response = pair.second;
        auto base = std::pow(10, response.size() - 1);

        for (auto&& c : response) {
            chars.insert(c);
        }

        if (query < std::pow(10, response.size() - 1)) {
            continue;
        }

        auto d = query / base;
        auto c = response[0];
        if (c2d.find(c) != c2d.end()) {
            continue;
        }
        int counter = 0;
        int pos = -1;
        for (int i = 1; i <= d; ++i) {
            if (d2c.find(i) == d2c.end()) {
                counter++;
                pos = i;
            }
        }
        if (counter > 1) {
            qr.push(pair);
        } else {  // counter == 1;
            d2c[pos] = c;
            c2d[c] = pos;
        }
    }

    for (auto&& c : chars) {
        if (c2d.find(c) == c2d.end()) {
            d2c[0] = c;
            c2d[c] = 0;
            break;
        }
    }

    std::string result;
    for (int i = 0; i < 10; ++i) {
        result.push_back(d2c[i]);
    }

    return result;
}

template <typename T>
auto processB(const T& inputs) {
    auto U = std::get<0>(inputs);
    auto records = std::get<1>(inputs);
    std::map<char, int64_t> chars;
    std::set<char> non_zero;

    for (auto&& pair : records) {
        // LOOP_COUNT++;
        // if (LOOP_COUNT % 100 == 0) {
        //     std::cerr << LOOP_COUNT
        //               << "-th iteration: queue size: " << qr.size()
        //               << std::endl;
        // }
        auto query = pair.first;
        auto response = pair.second;
        auto base = std::pow(10, response.size() - 1);

        for (auto&& c : response) {
            if (chars.find(c) == chars.end()) {
                chars[c] = 0;
            }
            chars[c]++;
        }

        if (query >= std::pow(10, response.size() - 1)) {
            non_zero.insert(response[0]);
        }
    }

    for (auto&& c : chars) {
        if (non_zero.find(c.first) == non_zero.end()) {
            chars[c.first] = INT_MAX;
            break;
        }
    }
    std::vector<std::pair<int64_t, char>> freq;
    for (auto&& pair : chars) {
        freq.push_back(std::make_pair(pair.second, pair.first));
    }
    std::sort(freq.begin(), freq.end(), std::greater<>());

    std::string result;
    for (auto&& pair : freq) {
        result.push_back(pair.second);
    }

    return result;
}

template <typename T>
auto process(const T& inputs) {
    auto qr = std::get<1>(inputs);
    if (qr[0].first != -1) {
        return processA(inputs);
    }
    return processB(inputs);
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
