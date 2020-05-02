// Oversized Pancake Choppers
#include <bits/stdc++.h>

class fraction {
   public:
    int64_t numerator;
    int64_t denominator;

    fraction() {
        numerator = 0;
        denominator = 1;
    }

    fraction(int64_t numerator) {
        this->numerator = numerator;
        this->denominator = 1;
    }

    fraction(int64_t numerator, int64_t denominator) {
        this->numerator = numerator;
        this->denominator = denominator;

        simplify();
    }

    static int64_t gcd(int64_t a, int64_t b) {
        if (a < b) {
            return gcd(b, a);
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    void simplify() {
        int64_t multiple = gcd(numerator, denominator);

        numerator /= multiple;
        denominator /= multiple;
    }

    fraction operator/(int dividend) {
        fraction res(numerator, denominator * dividend);
        res.simplify();

        return res;
    }

    fraction operator-(fraction other) {
        fraction res(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
        res.simplify();

        return res;
    }

    bool operator==(fraction other) {
        return this->denominator == other.denominator &&
               this->numerator == other.numerator;
    }

    bool operator<(fraction other) {
        return this->numerator * other.denominator <
               this->denominator * other.numerator;
    }
};

auto input() {
    int n = 0;
    int d = 0;
    std::vector<double> slice;

    std::cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        double angle;
        std::cin >> angle;

        slice.push_back(angle);
    }
    return std::make_tuple(n, d, slice);
}

template <typename T>
auto process(const T& inputs) {
    auto n = std::get<0>(inputs);
    auto d = std::get<1>(inputs);
    auto slices = std::get<2>(inputs);
    // std::map<fraction, int> count;
    std::map<double, int> count;

    for (auto&& slice : slices) {
        // fraction angle(slice);
        double angle = slice;

        if (count.find(angle) == count.end()) {
            count[angle] = 0;
        }
        count[angle]++;
    }

    // std::vector<std::pair<int, fraction>> freq;
    std::vector<std::pair<int, double>> freq;

    for (auto&& pair : count) {
        freq.push_back(std::make_pair(pair.second, pair.first));
    }

    std::sort(freq.begin(), freq.end(), std::greater<>());

    switch (freq[0].first) {
        case 1:
            return d - 1;
        case 2:
            return std::max(0, d - 2);
        default:
            return 0;
    }
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
