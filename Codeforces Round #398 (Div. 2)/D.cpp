// Cartons of milk

#include<bits/stdc++.h>

const int DAY_MAX = 10000000 + 1;
int main() {
    int n = 0;
    int m = 0;
    int k = 0;
    std::vector<int> fridge(DAY_MAX);
    std::vector<std::vector<int> > shop(DAY_MAX);

    std::cin >> n >> m >> k;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        ++fridge.at(tmp);
        last = std::max(last, tmp);
    }
    for (int i = 1; i <= m; ++i) {
        int tmp;
        std::cin >> tmp;
        shop.at(tmp).push_back(i);
        last = std::max(last, tmp);
    }
    std::vector<int> ans;

    for (int i = last; i > 0; --i) {
        if (fridge.at(i) < k) {
            int count = k - fridge.at(i);
            for (int j = last; j >= i && count; --j) {
                while (!shop.at(j).empty() && count) {
                    ans.push_back(shop.at(j).back());
                    shop.at(j).pop_back();
                    --count;
                }
            }
        } else if (fridge.at(i) > k) {
            fridge.at(i - 1) += fridge.at(i) - k;
            fridge.at(i) = k;
        }
    }
    if (fridge.at(0) > k) {
        std::cout << -1 << std::endl;
    } else {
        int count = k - fridge.at(0);
        for (int i = last; i >= 0 && count; --i) {
            while (!shop.at(i).empty() && count) {
                ans.push_back(shop.at(i).back());
                shop.at(i).pop_back();
                --count;
            }
        }
        std::cout << ans.size() << std::endl;
        for (auto i : ans) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
