// helpcross

#define TASK std::string("helpcross")
#include<bits/stdc++.h>

struct Cow {
    Cow (int A, int B) {
        this -> A = A;
        this -> B = B;
    }
    friend int operator<(const Cow& left, const Cow& right);
    
    int A;
    int B;
};

int operator<(const Cow& left, const Cow& right) {
    return (left.A == right.A) ? (left.B < right.B) : (left.A < right.A);
}
int cmp(const Cow& left, const Cow& right) {
    return left.B < right.B;
}
std::ifstream fin(TASK + ".in");
std::ofstream fout(TASK + ".out");

int main() {
    int C = 0;
    int N = 0;
    std::vector<int> T;
    std::vector<Cow> cow;

    fin >> C >> N;
    for (int i = 0; i < C; ++i) {
        int tmp = 0;
        fin >> tmp;
        T.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int A = 0;
        int B = 0;
        fin >> A >> B;
        cow.push_back(Cow(A, B));
    }
    T.push_back(INT_MIN);
    T.push_back(INT_MAX);
    std::sort(T.begin(), T.end());

    for (auto& i : cow) {
        int l = std::distance(T.begin(), std::lower_bound(T.begin(), T.end(), i.A));
        int r = std::distance(T.begin(), std::upper_bound(T.begin(), T.end(), i.B));
        --r;

        i.A = std::max(1, l);
        i.B = std::min(C, r);
    }
    std::sort(cow.begin(), cow.end());

    int lower = cow.at(0).A;
    int counting = 0;
    for (auto i = cow.begin(); i != cow.end(); ++i) {

        if (lower > i -> B || i -> B < i -> A) {
            continue;
        }
        auto min_it = i;
        auto min = i -> B;
        for (auto j = i + 1; j != cow.end() && j -> A <= lower; ++j) {
            if (j -> B < min && j -> B >= lower) {
                min = j -> B;
                min_it = j;
            }
        }
        std::swap(*i, *min_it);
        ++counting;
        lower = std::max(lower, i -> A) + 1;
    }

    fout << counting << std::endl;

    return 0;
}
