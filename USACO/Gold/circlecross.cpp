// circlecross

#define TASK std::string("circlecross")
#include<bits/stdc++.h>

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int64_t ans = 0;
std::vector<int> order;

void merge_sort(std::vector<int>& data, int begin, int end) {
    //std::cout << "Merge Sort" << std::endl;
    if (begin >= end) {
        return;
    }

    int l = begin;
    int r = end;
    int m = (begin + end) >> 1;

    //std::cout << l << ' ' << m << ' ' << r << std::endl;
    if (l < m) {
        merge_sort(data, l, m);
    }
    if (m <= r) {
        merge_sort(data, m + 1, r);
    }
    std::vector<int> upper(data.begin() + l, data.begin() + m + 1);
    std::vector<int> lower(data.begin() + m + 1, data.begin() + r + 1);

    int i = upper.size() - 1;
    int j = lower.size() - 1;
/*
    std::cout << "upper ";
    for (auto i : upper) {
        std::cout << order.at(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << "lower ";
    for (auto i : lower) {
        std::cout << order.at(i) << ' ';
    }
    std::cout << std::endl;
*/
    int k = r;
    while (i >= 0 && j >= 0) {
        //std::cout << "main i " << i << " j " << j << " k " << k << std::endl;
        if (order.at(upper.at(i)) < order.at(lower.at(j))) {
            data.at(k) = upper.at(i);
            --i;
            ans += j + 1;
        } else {
            data.at(k) = lower.at(j);
            --j;
        }
        --k;
    }
    while (i >= 0) {
    //std::cout << "nex1 i " << i << " j " << j << " k " << k << std::endl;
        data.at(k) = upper.at(i);
        --i;
        --k;
    }
    while (j >= 0) {
    //std::cout << "nex2 i " << i << " j " << j << " k " << k << std::endl;
        data.at(k) = lower.at(j);
        --j;
        --k;
    }
}

int main() {
    int N = 0;
    std::vector<int> visited;
    std::vector<int> input;

    fin >> N;
    visited.assign(N + 1, 0);
    order.assign(N + 1, 0);
    int count = 0;
    for (int i = 0; i < (N << 1); ++i) {
        int tmp;
        fin >> tmp;
        //std::cout << "input " << tmp << std::endl;

        if (visited.at(tmp) == 1) {
            input.push_back(tmp);
        } else {
            /*
            for (auto i : input) {
                std::cout << order.at(i) << ' ';
            }
            std::cout << std::endl;
            */
            merge_sort(input, 0, input.size() - 1);
            /*
            for (auto i : input) {
                std::cout << order.at(i) << ' ';
            }
            std::cout << std::endl;
            */
            input.clear();
            ++count;
            order.at(tmp) = count;
        }
        ++visited.at(tmp);
    }
    merge_sort(input, 0, input.size() - 1);

    fout << ans << std::endl;

    return 0;
}
