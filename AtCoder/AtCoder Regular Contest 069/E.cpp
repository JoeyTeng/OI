// Frequency

#include<bits/stdc++.h>

struct Data {
    Data (int a, int number) {
        this -> a = a;
        this -> number = number;
    }

    operator int() const {
        return a;
    }

    int a;
    int number;
};

int main() {
    int N = 0;
    std::cin >> N;
    std::vector<Data> Q;
    std::vector<int> a;

    for (int i = 0; i < N; ++i) {
        int tmp;
        std::cin >> tmp;
        Q.push_back(Data(tmp, i));
        a.push_back(tmp);
    }
    std::make_heap(Q.begin(), Q.end());
    std::vector<int64_t> ans(N);
    std::pop_heap(Q.begin(), Q.end());

    int bottom = 0;
    for (int i = Q.back().number; !Q.empty();
         Q.pop_back(), std::pop_heap(Q.begin(), Q.end()),
         i = Q.back().number) {
        for (int j = i; j >= 0; --j) {
            if (a.at(j) > 0) {
                int inc = std::min(std::max(a.at(j) - (a.at(i) - bottom), 0), a.at(j));
                std::cout << i << ' ' << j << ' ' << a.at(j) - bottom << std::endl;
                ans.at(i) += inc;
            }
        }
        bottom = a.at(i);
    }
    std::ostream_iterator<int> int_cout(std::cout, "\n");
    std::copy(ans.begin(), ans.end(), int_cout);

    return 0;
}
