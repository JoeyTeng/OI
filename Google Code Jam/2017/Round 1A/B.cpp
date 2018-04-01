// B. Ratatouille

#include<bits/stdc++.h>

int main() {
    int T = 0;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        int P;
        std::vector<int> R;
        std::vector<std::vector<int>> Q;

        std::cin >> N >> P;
        for (int i = 0; i < N; ++i) {
            int tmp;
            std::cin >> tmp;
            R.push_back(tmp);
        }
        for (int i = 0; i < N; ++i) {
            std::vector<int> q;
            for (int j = 0; j < P; ++j) {
                int tmp;
                std::cin >> tmp;
                q.push_back(tmp);
            }
            std::sort(q.begin(), q.end(), std::greater<int>());
            Q.push_back(q);
        }

        int ans = 0;
        int len = Q.at(0).size();
        while (len) {
            int Max = Q.at(0).at(0) / 0.9 / R.at(0);
            int Min = (Q.at(0).at(0) / 1.1 + R.at(0) - 0.001) / R.at(0);
            // std::cout << "MM " << Max << ' ' << Min << std::endl;

            for (int i = 1; i < Q.size(); ++i) {
                while (!Q.at(i).empty()) {
                    int Q_max = Q.at(i).at(0) / 0.9 / R.at(i);
                    int Q_min = (Q.at(i).at(0) / 1.1 + R.at(i) - 0.001) / R.at(i);
                    if (Q_min > Max) {
                        Q.at(i).erase(Q.at(i).begin());
                    } else {
                        Max = std::min(Max, Q_max);
                        Min = std::max(Min, Q_min);
                        break;
                    }
                }
                len = std::min(len, int(Q.at(i).size()));
                // std::cout << len << ' ' << i << ' ' << Max << ' ' << Min << std::endl;
            }
            // std::cout << "Loop " << std::endl;
            if (Max >= Min && len > 0) {
                for (auto& i : Q) {
                    i.erase(i.begin());
                }
                ++ans;
                --len;
            } else if (len > 0) {
                Q.at(0).erase(Q.at(0).begin());
                len = std::min(len, int(Q.at(0).size()));
            }
        }

                

        std::cout << "Case #" << t + 1 << ": " << ans << std::endl;
    }

    return 0;
}
