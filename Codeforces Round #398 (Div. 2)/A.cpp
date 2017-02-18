// Snacktower

#include<bits/stdc++.h>

int main() {
    int n = 0;
    std::cin >> n;

    int top = n;
    std::vector<int> falled(n + 1);
    for (int i = 0; i < n; ++i) {
        int tmp;

        std::cin >> tmp;
        falled.at(tmp) = 1;
        for (int j = top; j > 0 && falled.at(j); --j) {
            std::cout << j << ' ';
            --top;
        }
        std::cout << std::endl;
    }

    return 0;
}
