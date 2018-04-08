#include <string>
#include <iostream>

int64_t damage(const std::string &P)
{
    int64_t base = 1;
    int64_t d = 0;

    for (auto &p : P)
    {
        if (p == 'C')
        {
            base <<= 1;
        }
        else if (p == 'S')
        {
            d += base;
        }
    }
    return d;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        // std::cerr << "t: " << t << std::endl;
        int64_t D = 0;
        std::string P;
        std::cin >> D >> P;

        int64_t d = damage(P);
        int64_t count = 0;
        bool change = true;
        while (d > D && change)
        {
            change = false;
            // std::cerr << P << std::endl;
            for (int i = P.size() - 1; i > 0; --i)
            {
                // std::cerr << i << ' ' << P << std::endl;
                if (P[i] == 'S' && P[i - 1] == 'C')
                {
                    std::swap(P[i], P[i - 1]);
                    count++;
                    change = true;
                    break;
                }
            }
            d = damage(P);
            // std::cerr << "Program: " << P << " damage: " << d << std::endl;
        }
        if (d > D)
        {
            std::cout << "Case #" << t << ": IMPOSSIBLE" << std::endl;
        }
        else
        {
            std::cout << "Case #" << t << ": " << count << std::endl;
        }
    }
    return 0;
}
