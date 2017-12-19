// Haybale Feast

// interval

#include <bits/stdc++.h>
#define INFILE "hayfeast.in"
#define OUTFILE "hayfeast.out"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

int main() {
    int N = 0;

    std::int64_t M = 0;

    cin >> N >> M;

    std::vector<std::pair<std::int64_t, int> > haybales;

    for (int i = 0; i < N; ++i) {
        std::int64_t f = 0;
        int s          = 0;
        cin >> f >> s;
        haybales.push_back({ f, s });
    }

    auto lhs       = haybales.begin();
    auto rhs       = haybales.begin();
    std::int64_t F = 0;
    int S          = INT_MAX;
    std::priority_queue<int> queue;
    std::priority_queue<int> deleted;

    while (rhs != haybales.end()) {
        // std::cout << lhs -> second << ' ' << rhs -> second << std::endl;
        while (lhs != rhs && F >= M) {
            S = std::min(S, queue.top());

            if ((queue.top() == lhs->second)) {
                queue.pop();
            } else {
                deleted.push(lhs->second);
            }

            while (!deleted.empty() && queue.top() == deleted.top()) {
                // std::cout << "pruning " << queue.top() << std::endl;
                queue.pop();
                deleted.pop();
            }
            F -= lhs->first;
            ++lhs;
        }
        F += rhs->first;
        queue.push(rhs->second);
        ++rhs;
    }
    while (lhs != rhs && F >= M) {
        S = std::min(S, queue.top());

        if ((queue.top() == lhs->second)) {
            queue.pop();
        } else {
            deleted.push(lhs->second);
        }

        while (!deleted.empty() && queue.top() == deleted.top()) {
            // std::cout << "pruning " << queue.top() << std::endl;
            queue.pop();
            deleted.pop();
        }
        F -= lhs->first;
        ++lhs;
    }

    cout << S << std::endl;

    return 0;
}
