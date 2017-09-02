// Lollipops, Sweets and Chocolates
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define INFILE "lscin.txt"
#define OUTFILE "lscout.txt"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

std::vector<int64_t> position;
std::vector<int64_t> pamphlet;
std::vector<int64_t> order; // sub distance into pamphlet

int check(int pos) {
    int64_t dist = std::abs(pos - order.at(0));
    for (auto i : order) {
        if (std::abs(i - pos) < dist) {
            if (pos > i) {
                return 1;
            } else {
                return -1;
            }
        }
        dist = std::abs(i - pos);
    }

    return 0;
}

int main() {
    int N = 0;
    int L = 0;
    
    cin >> N >> L;
    if (N == 1) {
        cout << "1";
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        int64_t tmp = 0;
        cin >> tmp;
        position.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int64_t tmp = 0;
        cin >> tmp;
        pamphlet.push_back(tmp);
        order.push_back(position.at(tmp - 1));
    }
    
    int64_t upper = std::max(order.at(0), order.at(1));
    int64_t lower = std::min(order.at(0), order.at(1));
/*
    int dist = 0;
    
    for (int i = 2; i < N; ++i) {
        if (order.at(i) >= upper) {
            if (order.at(i) - dist > upper) {
                dist = order.at(i) - upper;
            } else {
                upper = order.at(i) - dist;
            }
        } else if (order.at(i) <= lower) {
            if (order.at(i) + dist < lower) {
                dist = lower - order.at(i);
            } else {
                lower = order.at(i) + dist;
            }
        } else {
            cout << "-1" << std::endl;
        }
        std::cout << order.at(i) << ' ' << upper << ' ' << lower << ' ' << dist << std::endl;
    }
    
    cout << upper << std::endl;
*/

    int64_t current = -1;
/*
    if (upper - lower > 1000) {
        current = (upper + lower) >> 1;
        int direction = 0;
        while (direction = check(current)) {
            if (upper <= lower) {
                cout << "-1" << std::endl;
                return 0;
            }
            // std::cout << upper << ' ' << lower << std::endl;
            if (direction > 0) {
                lower = current + 1;
            } else {
                upper = current - 1;
            }
            current = (upper + lower) >> 1;
        }
    } else {
*/
        for (int64_t i = lower; i <= upper; ++i) {
            if (!check(i)) {
                current = i;
                break;
            }
        }
//    }
    cout << current << std::endl;

    return 0;
}