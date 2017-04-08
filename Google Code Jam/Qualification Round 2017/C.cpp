// C. Bathroom Stalls

#include<bits/stdc++.h>

struct Pair {
    int L;
    int R;
    int N;

    Pair() {
    }
    Pair(int _L, int _R, int _N) {
        L = std::min(_L, _R);
        R = std::max(_L, _R);
        N = _N;
    }
};

struct HigherRank {
    bool operator()(Pair& lhs, Pair& rhs) {
        if (lhs.L < rhs.L) {
            return 1;
        } else if (lhs.L > rhs.L) {
            return 0;
        } else if (lhs.R < rhs.R) {
            return 1;
        } else if (lhs.R == rhs.R) {
//            std::cout << "Merge " << lhs.L << ' ' << lhs.R << ' ' << lhs.N << ' ' << rhs.N << std::endl;
            lhs.N += rhs.N;
            rhs.N = 0;
        }

        return 0;
    }
};

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int N;
        int K;
        std::cin >> N >> K;

        std::priority_queue<Pair, std::vector<Pair>, HigherRank> Q;
        Q.push(Pair(N >> 1, N - (N >> 1) - 1, 1));
        for (int i = 1; i < K;) {
            auto P = Q.top();
            Q.pop();
//            std::cout << "Loop " << i << ' ' << P.L << ' ' << P.R << ' ' << P.N << std::endl;
            if (P.N == 0) {
                continue;
            }
            auto A = (Pair(P.L >> 1, P.L - (P.L >> 1) - 1, P.N));
            auto B = (Pair(P.R >> 1, P.R - (P.R >> 1) - 1, P.N));
            Q.push(A);
            Q.push(B);
//            std::cout << "Push " << A.L << ' ' << A.R << ' ' << A.N << std::endl;
//            std::cout << "Push " << B.L << ' ' << B.R << std::endl;
            i += P.N << 1;
        }
        auto P = Q.top();
        std::cout << "Case #" << t + 1 << ": " << P.R << ' '  << P.L << std::endl;
    }

    return 0;
}
