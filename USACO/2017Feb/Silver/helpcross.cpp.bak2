// helpcross

#define TASK std::string("helpcross")
#include<bits/stdc++.h>

struct Cow {
    Cow (int number, int t) {
        this -> number = number;
        this -> t = t;
    }
    operator int() const {
        return this -> t;
    }

    int number;
    int t;
};

std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int C = 0;
    int N = 0;
    std::vector<int> T;
    std::vector<std::pair<int, int> > cow;
    std::vector<Cow> A;
    std::vector<Cow> B;

    fin >> C >> N;
    std::vector<int> used(N, 0);
    for (int i = 0; i < C; ++i) {
        int tmp = 0;
        fin >> tmp;
        T.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int a = 0;
        int b = 0;
        fin >> a >> b;
        A.push_back(Cow(i, a));
        B.push_back(Cow(i, b));
        cow.push_back(std::make_pair(a, b));
    }
    A.push_back(Cow(-1, INT_MIN));
    A.push_back(Cow(-1, INT_MAX));
    B.push_back(Cow(-1, INT_MIN));
    B.push_back(Cow(-1, INT_MAX));
    std::sort(T.begin(), T.end());
    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end());

//    for (auto i : A) {
//        std::cout << i.number << ' ' << i.t << std::endl;
//    }

    int counting = 0;
    for (auto t : T) {
        int pos = std::distance(B.begin(), std::lower_bound(B.begin(), B.end(), Cow(-1, t)));
//        std::cout << pos << std::endl;
        if (t < B.at(pos).t) {
            --pos;
        }
        int min_pos = -1;
        int min_A = INT_MAX;
        for (auto i = 0; i <= pos; ++i) {
            if (A.at(i).number != -1 && used.at(A.at(i).number) == 0
             && A.at(i).t < min_A && A.at(i).t >= t) {
                min_A = A.at(i).t;
                min_pos = i;
            }
        }
        if (min_pos != -1) {
            ++counting;
            used.at(min_pos) = 1;
        }
    }

    fout << counting << std::endl;

    return 0;
}
