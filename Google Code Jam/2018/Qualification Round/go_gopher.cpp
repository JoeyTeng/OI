#include <bits/stdc++.h>

const int N_MAX = 1000;

int map[N_MAX * N_MAX + 1] = {0};

int complete(int coordinate)
{
    for (int i = -1; i < 2; ++i)
    {
        for (int j = -1; j < 2; ++j)
        {
            if (map[(coordinate / N_MAX + i) * N_MAX + (coordinate % N_MAX + j)] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int A = 0;
        std::cin >> A;
        std::queue<int> queue;
        std::memset(map, 0, sizeof(map));

        // std::cerr << "Case #" << t << " A: " << A << std::endl;

        if (A == 20)
        {
            for (int i = 0; i < (5 - 2); ++i)
            {
                for (int j = 0; j < (4 - 2); ++j)
                {
                    queue.push((i + 2) * N_MAX + (j + 2));
                }
            }
        }
        else if (A == 200)
        {
            for (int i = 0; i < (20 - 2); ++i)
            {
                for (int j = 0; j < (10 - 2); ++j)
                {
                    queue.push((i + 2) * N_MAX + (j + 2));
                }
            }
        }

        int response = -1;
        while (response != 0 && response != (-1 * N_MAX + (-1)))
        {
            while (complete(queue.front()))
            {
                queue.pop();
            }
            std::cout << (queue.front() / N_MAX) << ' ' << (queue.front() % N_MAX) << std::endl;
            // std::cerr << queue.front() << std::endl;
            int x = 0;
            int y = 0;
            std::cin >> x >> y;
            response = x * N_MAX + y;

            map[response] = 1;
            if (!complete(queue.front()))
            {
                queue.push(queue.front());
            }
            queue.pop();
        }
    }
}
