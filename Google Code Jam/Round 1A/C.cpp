// C. Play the Dragon

#include<bits/stdc++.h>

const int MAX_ROUND = 200;

int dfs(int Hd, int Ad, int Hk, int Ak, int B, int D, int hp, int C, int depth) {
    if (depth == 0) {
        std::cout << Hd << ' ' << Ad << ' ' << Hk << ' ' << Ak << ' ' << B << ' ' << D << ' ' << hp << ' ' << C << ' ' << depth << std::endl;
        if (hp > -Ak && Hk <= 0) {
            std::cout << "WIN\n\n";
            return 0;
        } else {
            std::cout << "LOSE\n\n";
            return 1;
        }
    }
    std::cout << Hd << ' ' << Ad << ' ' << Hk << ' ' << Ak << ' ' << B << ' ' << D << ' ' << hp << ' ' << C << ' ' << depth << std::endl;
    if (hp <= Ad && depth > 1) {
        std::cout << "Cure\n";
        if (C) {
            return dfs(Hd, Ad, Hk, Ak, B, D, Hd, 0, depth - 1);
        } else {
            std::cout << "DIE\n\n";
            return 1;
        }
    }
    std::cout << "Attack\n";
    int a = dfs(Hd, Ad, Hk - Ad, Ak, B, D, hp - Ak, 1, depth - 1);
    std::cout << "Debuff\n";
    int d = dfs(Hd, Ad, Hk, Ak - D, B, D, hp - std::max(Ak - D, 0), 1, depth - 1);
    std::cout << "Buff\n";
    int b = dfs(Hd, Ad + B, Hk, Ak, B, D, hp - Ak, 1, depth - 1);
    return std::min(std::min(a, d), b);
}

int main() {
    int T = 0;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int Hd;
        int Ad;
        int Hk;
        int Ak;
        int B;
        int D;

        std::cin >> Hd >> Ad >> Hk >> Ak >> B >> D;

        int ans = 1;
        for (;dfs(Hd, Ad, Hk, Ak, B, D, Hd, 1, ans) && ans < MAX_ROUND; ++ans) {
            std::cout << "Check " << ans << "\n\n";
        }

        std::cout << "Case #" << t + 1 << ": ";
        if (ans < MAX_ROUND) {
            std::cout << ans << std::endl;
        } else {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
    }

    return 0;
}
