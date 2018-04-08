#include <bits/stdc++.h>

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int len = 0;
        bool end = false;
        std::cin >> len;
        std::vector<int> all;
        std::vector<int> odd;
        std::vector<int> even;
        for (int i = 0; i < len; ++i)
        {
            int tmp;
            std::cin >> tmp;
            if (i & 1)
            {
                odd.push_back(tmp);
            }
            else
            {
                even.push_back(tmp);
            }
        }
        std::sort(odd.begin(), odd.end());
        std::sort(even.begin(), even.end());
        all.push_back(even[0]);
        for (int i = 1; i < len; ++i)
        {
            if (i & 1)
            {
                all.push_back(odd[i >> 1]);
            }
            else
            {
                all.push_back(even[i >> 1]);
            }
            if (all[i] < all[i - 1])
            {
                std::cout << "Case #" << t << ": " << i - 1 << std::endl;
                end = true;
                break;
            }
        }
        if (!end)
        {
            std::cout << "Case #" << t << ": OK" << std::endl;
        }
    }
}
