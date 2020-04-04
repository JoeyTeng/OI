// ESAb ATAd
#include <bits/stdc++.h>

// #define DEBUG 1

const int MAX_QUERIES = 150;
const int MAX_BITS = 100;

using BitStream = std::bitset<MAX_BITS>;

#ifdef DEBUG
static int count = 0;
#endif

bool read_at(int pos) {
    int bit = 0;

    std::cout << pos + 1 << std::endl;
    std::cin >> bit;
#ifdef DEBUG
    count++;
    std::cerr << count << "-th read:" << std::endl
              << "  " << pos << "-th bit: " << bit << std::endl;
#endif

    return bit == 1;
}

auto fluctuation(BitStream& bits, int complement, int reverse, int B) {
    int count = (complement != -1 ? 1 : 0) + (reverse != -1 ? 1 : 0);

    if (complement != -1) {
#ifdef DEBUG
        std::cerr << "read test-bit for flipping" << std::endl;
#endif
        if (read_at(complement) != bits[complement]) {
            bits.flip();
#ifdef DEBUG
            std::cerr << "  flipped" << std::endl;
#endif
        }
    }
    if (reverse != -1) {
#ifdef DEBUG
        std::cerr << "read test-bit for reverse" << std::endl;
#endif
        bool test_bit = read_at(reverse);
        if (test_bit != bits[reverse]) {
            auto tmp = bits.to_string().substr(MAX_BITS - B, B);
            std::reverse(tmp.begin(), tmp.end());
            auto _bits = BitStream(tmp);
#ifdef DEBUG
            auto _tmp = bits.to_string().substr(MAX_BITS - B, B);
            std::reverse(_tmp.begin(), _tmp.end());

            std::cerr << "  reversed" << std::endl
                      << "  - " << tmp << std::endl
                      << "  - ";
            for (int i = 0; i < B; ++i) {
                std::cerr << bits.test(i) ? 1 : 0;
            }
            std::cerr << std::endl << "  - ";
            bits = _bits;
            for (int i = 0; i < B; ++i) {
                std::cerr << bits.test(i) ? 1 : 0;
            }
            std::cerr << std::endl;
#endif
            bits = _bits;
        }
    }

    // ensure reads always occurs in pairs.
    if (count & 1) {
        read_at(0);
        ++count;
    }

    return std::make_tuple(count, bits);
}

auto process(int B) {
    BitStream bits;
    BitStream queried;
    int complement_indicator = -1;  // symmatric bits pair
    int reverse_indicator = -1;     // asymmatric bits pair
    int queried_count = 0;

    {
        bits = bits.set(0, read_at(0));
        queried = queried.set(0, true);
        ++queried_count;
    }

    for (int i = 1; i < MAX_QUERIES; ++i) {
#ifdef DEBUG
        auto res = bits.to_string().substr(MAX_BITS - B, B);
        std::reverse(res.begin(), res.end());
        std::cerr << i << "-th iteration:" << std::endl << "  ";
        for (int j = 0; j < B; ++j) {
            if (queried.test(j)) {
                std::cerr << res[j];
            } else {
                std::cerr << ' ';
            }
        }
        std::cerr << std::endl;
#endif

        if (queried_count == B) {
            break;
        }

        if (i % 10 == 0) {
            auto tmp =
                fluctuation(bits, complement_indicator, reverse_indicator, B);
            bits = std::get<1>(tmp);
            i += std::get<0>(tmp);
            --i;

            continue;
        }

        int bit = 0;
        int index = (queried_count >> 1);

        if (queried_count & 1) {
            index = B - index - 1;
        }

        bits[index] = read_at(index);
        queried[index] = true;
        if (queried_count & 1) {
            if (complement_indicator == -1 &&
                bits[index] == bits[B - index - 1]) {
                complement_indicator = index;
#ifdef DEBUG
                std::cerr << "!complement_indicator: " << index << std::endl;
#endif
            }
            if (reverse_indicator == -1 && bits[index] != bits[B - index - 1]) {
                reverse_indicator = index;
#ifdef DEBUG
                std::cerr << "!reverse_indicator: " << index << std::endl;
#endif
            }
        }
        ++queried_count;
    }

    auto res = bits.to_string().substr(MAX_BITS - B, B);
    std::reverse(res.begin(), res.end());

    return res;
}

int main() {
    int T = 0;
    int B = 0;

    std::cin >> T >> B;

    for (auto i = 0; i < T; ++i) {
        char correctness = 0;
        auto result = process(B);
#ifdef DEBUG
        count = 0;
#endif

        std::cout << result << std::endl;
        std::cin >> correctness;

        if (correctness == 'N') {
            return 0;
        }
    }

    return 0;
}
