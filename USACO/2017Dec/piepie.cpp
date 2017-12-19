// A pie for a pie

// Graph, BFS

#include <bits/stdc++.h>
#define INFILE "piepie.in"
#define OUTFILE "piepie.out"

std::ifstream cin(INFILE);
std::ofstream cout(OUTFILE);

int main() {
    int N = 0;
    int D = 0;

    cin >> N >> D;

    std::vector<std::pair<std::pair<int, int>, int> > B;
    std::vector<std::pair<std::pair<int, int>, int> > E;
    std::vector<int> ans((N << 1), -1);
    std::queue<int>  zero_queue;

    for (int i = 0; i < N; ++i) {
        int b = 0;
        int e = 0;
        cin >> b >> e;
        B.push_back({{ e, b }, i });

        if (e == 0) {
            zero_queue.push(i);
            ans[i] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        int b = 0;
        int e = 0;
        cin >> b >> e;
        E.push_back({{ b, e }, i + N }); // Note! position of b&e has been

        // swapped
        if (b == 0) {
            zero_queue.push(i);
            ans[i] = 2;
        }
    }
    auto Bessie = B;
    auto Elsie  = E;

    std::sort(B.begin(), B.end());
    std::sort(E.begin(), E.end());

    while (!zero_queue.empty()) {
        std::queue<int> queue;
        queue.push(zero_queue.front());
        zero_queue.pop();

        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            int step = ans[current] + 1;

            if (current < N) { // in B
                auto b   = Bessie[current].first.second;
                auto pos =
                    std::upper_bound(E.begin(),
                                     E.end(),
                                     b,
                                     [](const int& lhs,
                                        const std::pair<std::pair<int, int>,
                                                        int>& rhs) -> bool {
                    return lhs < rhs.first.first;
                });
                --pos;

                while (pos >= E.begin() && (pos->first).first >= b - D) {
                    if ((ans[pos->second] > step) || (ans[pos->second] == -1)) {
                        ans[pos->second] = step;
                        queue.push(pos->second);
                    }
                    --pos;
                }
            } else { // in E
                current -= N;
                auto e   = Elsie[current].first.second;
                auto pos =
                    std::upper_bound(B.begin(),
                                     B.end(),
                                     e - D,
                                     [](const int& lhs,
                                        const std::pair<std::pair<int, int>,
                                                        int>& rhs) -> bool {
                    return lhs < rhs.first.first;
                });
                --pos;

                while (pos >= B.begin() && (pos->first).first >= e - D) {
                    if ((ans[pos->second] > step) || (ans[pos->second] == -1)) {
                        ans[pos->second] = step;
                        queue.push(pos->second);
                    }
                    --pos;
                }
                current += N;
            }

            std::cout << std::endl << "step: " << step << " current: " <<
                current << std::endl;

            for (auto& i:ans) {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            ++step;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << std::endl;
    }

    return 0;
}
