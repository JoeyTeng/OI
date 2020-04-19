// Robot Path Decoding
#include <bits/stdc++.h>

const int64_t BOARDER = 1e9;

auto input() {
    std::string program;
    std::cin >> program;

    return std::move(program);
}

template <typename T, typename S>
S recurse(T& coord, const S& begin, const S& end, int64_t counter) {
    // std::cerr << "entering with counter " << counter << std::endl;
    int64_t curr_multiple = 1;

    for (auto it = begin; it != end; ++it) {
        switch (*it) {
            case '(':
                counter *= curr_multiple;
                it = recurse(coord, it + 1, end, counter % BOARDER);
                counter /= curr_multiple;
                curr_multiple = 1;
                break;
            case ')':
                // std::cerr << "exiting" << std::endl;
                return it;
            case 'N':
                coord.second -= counter;
                break;
            case 'S':
                coord.second += counter;
                break;
            case 'E':
                coord.first += counter;
                break;
            case 'W':
                coord.first -= counter;
                break;
            default:
                curr_multiple = *it - '0';
                break;
        }
        coord.first = (coord.first + BOARDER) % BOARDER;
        coord.second = (coord.second + BOARDER) % BOARDER;

        // std::cerr << "(" << coord.first << ", " << coord.second << ")"
        //           << " multiple: " << curr_multiple << std::endl;
    }

    return end;
}

template <typename T>
auto process(const T& program) {
    std::pair<int64_t, int64_t> coord(1 - 1, 1 - 1);  // col, row

    recurse(coord, program.begin(), program.end(), 1);

    std::stringstream result;
    result << (coord.first + 1) << ' ' << (coord.second + 1);

    return result.str();
}

int main() {
    int T = 0;

    std::cin >> T;

    for (auto i = 0; i < T; ++i) {
        auto vector = input();
        auto result = process(vector);

        std::cout << "Case #" << i + 1 << ": " << result << std::endl;
    }

    return 0;
}
